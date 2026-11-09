#!/usr/bin/env python3
"""jpg2png.py - pure-stdlib baseline JPEG to RGB PNG converter.

Converts a generator's true-JPEG master (e.g. Gemini output) into the PNG the
seamlock header gate requires. No resampling, no size change: pixels are
decoded at native resolution and written as 8-bit RGB PNG. Handles baseline
sequential JPEG (SOF0/SOF1), arbitrary component sampling (4:2:0, 4:2:2,
4:4:4), restart intervals, and chroma upsampling by replication. Progressive
JPEG (SOF2) and lossless (SOF3) are refused with a clear error.

usage: jpg2png.py IN.jpg OUT.png
"""
import sys, zlib, struct, math

# ---------------- PNG writer (same pattern as rot90.py) ----------------

def write_png(path, rows, w, h):
    def chunk(t, data):
        c = t + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c))
    raw = b"".join(b"\x00" + r for r in rows)
    png = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
           + chunk(b"IDAT", zlib.compress(raw, 9))
           + chunk(b"IEND", b""))
    open(path, "wb").write(png)

# ---------------- JPEG decoding ----------------

ZIGZAG = [
    0, 1, 8,16, 9, 2, 3,10,17,24,32,25,18,11, 4, 5,
    12,19,26,33,40,48,41,34,27,20,13, 6, 7,14,21,28,
    35,42,49,56,57,50,43,36,29,22,15,23,30,37,44,51,
    58,59,52,45,38,31,39,46,53,60,61,54,47,55,62,63]

COS = [[math.cos((2 * x + 1) * u * math.pi / 16) for x in range(8)] for u in range(8)]
CU = [1.0 / math.sqrt(2.0)] + [1.0] * 7

def idct2(block):
    tmp = [0.0] * 64
    out = [0.0] * 64
    for y in range(8):
        base = y * 8
        for x in range(8):
            s = 0.0
            for u in range(8):
                s += CU[u] * COS[u][x] * block[base + u]
            tmp[base + x] = s
    for x in range(8):
        for y in range(8):
            s = 0.0
            for v in range(8):
                s += CU[v] * COS[v][y] * tmp[v * 8 + x]
            out[y * 8 + x] = s
    return out

class Huff:
    def __init__(self, counts, symbols):
        self.lookup = {}
        code = 0
        k = 0
        for l in range(1, 17):
            for _ in range(counts[l - 1]):
                self.lookup[(l, code)] = symbols[k]
                k += 1
                code += 1
            code <<= 1
    def decode(self, br):
        l = 0
        code = 0
        while l < 17:
            b = br.bit()
            if b is None:
                return None
            code = (code << 1) | b
            l += 1
            v = self.lookup.get((l, code))
            if v is not None:
                return v
        raise ValueError("bad huffman code")

class BitReader:
    def __init__(self, data):
        self.data = data
        self.pos = 0
        self.buf = 0
        self.nbits = 0
    def bit(self):
        if self.nbits == 0:
            if self.pos >= len(self.data):
                return None
            b = self.data[self.pos]
            self.pos += 1
            if b == 0xFF:
                nxt = self.data[self.pos] if self.pos < len(self.data) else 0x00
                if nxt == 0x00:
                    self.pos += 1  # FF 00 stuffs a literal FF data byte
                else:
                    return None  # marker reached
            self.buf = b
            self.nbits = 8
        self.nbits -= 1
        return (self.buf >> self.nbits) & 1
    def receive(self, n):
        v = 0
        for _ in range(n):
            b = self.bit()
            if b is None:
                return None
            v = (v << 1) | b
        return v

def extend(v, t):
    if v is None:
        return None
    if t == 0:
        return 0
    return v if v >= (1 << (t - 1)) else v - (1 << t) + 1

def decode_jpeg(path):
    d = open(path, "rb").read()
    if d[:2] != b"\xff\xd8":
        sys.exit("not a JPEG (bad SOI)")
    qt = {}
    huf_dc = {}
    huf_ac = {}
    comps = None
    W = H = None
    restart = 0
    data_start = None
    i = 2
    while i < len(d) - 1:
        if d[i] != 0xFF:
            i += 1
            continue
        m = d[i + 1]
        if m in (0xD8, 0x01) or 0xD0 <= m <= 0xD7 or m == 0xD9:
            i += 2
            continue
        if i + 4 > len(d):
            break
        ln = (d[i + 2] << 8) | d[i + 3]
        seg = d[i + 4:i + 2 + ln]
        if m == 0xDB:  # DQT
            p = 0
            while p < len(seg):
                pq, tq = seg[p] >> 4, seg[p] & 15
                if pq == 0:
                    qt[tq] = list(seg[p + 1:p + 65])
                    p += 65
                else:
                    qt[tq] = [(seg[p + 1 + 2 * k] << 8) | seg[p + 2 + 2 * k] for k in range(64)]
                    p += 129
        elif m in (0xC0, 0xC1):  # baseline sequential
            H, W = (seg[1] << 8) | seg[2], (seg[3] << 8) | seg[4]
            nc = seg[5]
            comps = []
            for c in range(nc):
                comps.append({"id": seg[6 + c * 3], "h": seg[7 + c * 3] >> 4,
                              "v": seg[7 + c * 3] & 15, "tq": seg[8 + c * 3]})
        elif m in (0xC2, 0xC3):
            sys.exit("refusing: progressive/lossless JPEG not supported by this tool")
        elif m == 0xC4:  # DHT
            p = 0
            while p < len(seg):
                tc, th = seg[p] >> 4, seg[p] & 15
                counts = list(seg[p + 1:p + 17])
                total = sum(counts)
                symbols = list(seg[p + 17:p + 17 + total])
                table = Huff(counts, symbols)
                if tc == 0:
                    huf_dc[th] = table
                else:
                    huf_ac[th] = table
                p += 17 + total
        elif m == 0xDD:  # DRI
            restart = (seg[0] << 8) | seg[1]
        elif m == 0xDA:  # SOS
            ns = seg[0]
            assign = {}
            for s in range(ns):
                cs, t = seg[1 + s * 2], seg[2 + s * 2]
                assign[cs] = (t >> 4, t & 15)
            for c in comps:
                c["td"], c["ta"] = assign[c["id"]]
            data_start = i + 2 + ln
            break
        i += 2 + ln
    if comps is None or data_start is None:
        sys.exit("no SOF/SOS found")

    hmax = max(c["h"] for c in comps)
    vmax = max(c["v"] for c in comps)
    mcux = (W + 8 * hmax - 1) // (8 * hmax)
    mcuy = (H + 8 * vmax - 1) // (8 * vmax)
    for c in comps:
        c["bw"] = mcux * c["h"] * 8
        c["bh"] = mcuy * c["v"] * 8
        c["px"] = [0.0] * (c["bw"] * c["bh"])

    br = BitReader(d[data_start:])
    pred = {c["id"]: 0 for c in comps}
    nm = 0
    for my in range(mcuy):
        for mx in range(mcux):
            if restart and nm > 0 and nm % restart == 0:
                br.nbits = 0
                while br.pos < len(d) - 1 and not (d[br.pos] == 0xFF and 0xD0 <= d[br.pos + 1] <= 0xD7):
                    br.pos += 1
                if br.pos < len(d) - 1:
                    br.pos += 2
                for cid in pred:
                    pred[cid] = 0
            for c in comps:
                q = qt[c["tq"]]
                for by in range(c["v"]):
                    for bx in range(c["h"]):
                        blk = [0.0] * 64
                        t = huf_dc[c["td"]].decode(br)
                        if t is None:
                            raise ValueError("stream ended mid-block")
                        diff = extend(br.receive(t), t) if t else 0
                        pred[c["id"]] += diff
                        blk[0] = pred[c["id"]] * q[0]
                        k = 1
                        while k < 64:
                            rs = huf_ac[c["ta"]].decode(br)
                            if rs is None:
                                raise ValueError("stream ended mid-block")
                            r, s = rs >> 4, rs & 15
                            if s == 0:
                                if r == 15:
                                    k += 16
                                    continue
                                break  # EOB
                            k += r
                            if k > 63:
                                break
                            val = extend(br.receive(s), s)
                            blk[ZIGZAG[k]] = val * q[k]
                            k += 1
                        px = idct2(blk)
                        x0 = (mx * c["h"] + bx) * 8
                        y0 = (my * c["v"] + by) * 8
                        plane = c["px"]
                        bw = c["bw"]
                        for yy in range(8):
                            rb = (y0 + yy) * bw + x0
                            plane[rb:rb + 8] = px[yy * 8:yy * 8 + 8]
            nm += 1
    return W, H, comps

def clamp(v):
    return 0 if v < 0 else (255 if v > 255 else int(v + 0.5))

def to_rgb(W, H, comps):
    yc = max(comps, key=lambda c: c["h"] * c["v"])  # luma = highest-sampled plane
    chroma = [c for c in comps if c is not yc]
    rows = []
    for y in range(H):
        row = bytearray(W * 3)
        yrow = yc["px"][y * yc["bw"]:y * yc["bw"] + W]
        if chroma:
            cb, cr = chroma[0], chroma[1] if len(chroma) > 1 else chroma[0]
            sy = (y * cb["v"]) // yc["v"]
            sxr = [(x * cr["h"]) // yc["h"] for x in range(W)]
            sxb = [(x * cb["h"]) // yc["h"] for x in range(W)]
            cbrow = cb["px"][sy * cb["bw"]:sy * cb["bw"] + cb["bw"]]
            crrow = cr["px"][sy * cr["bw"]:sy * cr["bw"] + cr["bw"]]
            for x in range(W):
                Y = yrow[x]
                Cb = cbrow[sxb[x]] - 128.0
                Cr = crrow[sxr[x]] - 128.0
                row[x * 3] = clamp(Y + 1.402 * Cr)
                row[x * 3 + 1] = clamp(Y - 0.344136 * Cb - 0.714136 * Cr)
                row[x * 3 + 2] = clamp(Y + 1.772 * Cb)
        else:
            for x in range(W):
                Y = yrow[x]
                row[x * 3] = row[x * 3 + 1] = row[x * 3 + 2] = clamp(Y)
        rows.append(bytes(row))
    return rows

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit("usage: jpg2png.py IN.jpg OUT.png")
    W, H, comps = decode_jpeg(sys.argv[1])
    rows = to_rgb(W, H, comps)
    write_png(sys.argv[2], rows, W, H)
    print("decoded %dx%d, wrote %s" % (W, H, sys.argv[2]))
