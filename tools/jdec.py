#!/usr/bin/env python3
"""jdec.py - pure-stdlib baseline JPEG decoder (grayscale Y
output as flat bytes + dims). Baseline sequential DCT, Huffman,
YCbCr 4:4:4 / 4:2:2 / 4:2:0, keep only the Y plane. The seamlock
pattern: no image libraries in the sandbox, decode by hand."""
import struct

ZIGZAG = [
 [0, 1, 8, 16, 9, 2, 3, 10],
 [17, 24, 32, 25, 18, 11, 4, 5],
 [12, 19, 26, 33, 40, 48, 41, 34],
 [27, 20, 13, 6, 7, 14, 21, 28],
 [35, 42, 49, 56, 57, 50, 43, 36],
 [29, 22, 15, 23, 30, 37, 44, 51],
 [58, 59, 52, 45, 38, 31, 39, 46],
 [53, 60, 61, 54, 47, 55, 62, 63]]

FLAT_Z = sum(ZIGZAG, [])
ZINV = [0] * 64
for _k in range(64):
    ZINV[FLAT_Z[_k]] = _k

class BitReader:
    def __init__(self, data):
        self.d = data
        self.p = 0
        self.b = 0
        self.n = 0

    def bit(self):
        if self.n == 0:
            if self.p >= len(self.d):
                return 0        # pad (spec: 1s)
            c = self.d[self.p]
            self.p += 1
            if c == 0xFF:
                nxt = self.d[self.p] if self.p < len(self.d) else 0
                if nxt == 0x00:
                    self.p += 1
                else:
                    return 0    # EOI pad
            self.b = c
            self.n = 8
        self.n -= 1
        return (self.b >> self.n) & 1

    def bits(self, k):
        v = 0
        for _ in range(k):
            v = (v << 1) | self.bit()
        return v

def build_huff(counts, symbols):
    # canonical code assignment per JPEG spec C.2
    code = 0
    k = 0
    lut = {}
    for leng in range(1, 17):
        for _ in range(counts[leng - 1]):
            lut[(leng, code)] = symbols[k]
            k += 1
            code += 1
        code <<= 1
    return lut

def decode_huff(br, lut):
    code = 0
    for leng in range(1, 17):
        code = (code << 1) | br.bit()
        if (leng, code) in lut:
            return lut[(leng, code)]
    raise ValueError("bad huffman code")

def extend(v, t):
    return v - (1 << t) + 1 if v < (1 << (t - 1)) \
        else v

def idct(blk):
    """8x8 IDCT (separable, straightforward)."""
    out = [[0.0] * 8 for _ in range(8)]
    for y in range(8):
        for x in range(8):
            s = 0.0
            for u in range(8):
                for v in range(8):
                    cu = (2 ** 0.5) if u else 1.0
                    cv = (2 ** 0.5) if v else 1.0
                    s += (cu * cv * blk[v][u]
                          * _C[u][x] * _C[v][y])
            out[y][x] = s / 4.0
    return out

import math
_C = [[math.cos((2 * x + 1) * u * math.pi / 16.0)
       for x in range(8)] for u in range(8)]

def decode(path):
    d = open(path, "rb").read()
    p = 0
    qt = {}
    hts = {}
    comps = None
    restart = 0
    while p < len(d):
        if d[p] != 0xFF:
            p += 1
            continue
        m = d[p + 1]
        p += 2
        if m in (0xD8, 0xD9, 0x01) or 0xD0 <= m <= 0xD7:
            continue
        ln = struct.unpack(">H", d[p:p + 2])[0]
        seg = d[p + 2:p + ln]
        if m == 0xDB:                      # DQT
            q = 0
            while q < len(seg):
                pq = seg[q]
                t = pq & 15
                need = 129 if pq >> 4 else 65
                if q + need > len(seg):
                    break        # not a full table
                if pq >> 4:                     # 16-bit rare
                    qt[t] = [struct.unpack(
                        ">H", seg[q + 1 + 2 * i:
                        q + 3 + 2 * i])[0]
                        for i in range(64)]
                    q += 129
                else:
                    qt[t] = list(seg[q + 1:q + 65])
                    q += 65
        elif m in (0xC0, 0xC1):            # SOF0/1 baseline
            prec = seg[0]
            h = struct.unpack(">H", seg[1:3])[0]
            w = struct.unpack(">H", seg[3:5])[0]
            nc = seg[5]
            comps = []
            for i in range(nc):
                cid, hv, tq = seg[6 + 3 * i], \
                    seg[7 + 3 * i], seg[8 + 3 * i]
                comps.append(dict(id=cid, h=hv >> 4,
                    v=hv & 15, tq=tq))
        elif m == 0xC4:                    # DHT
            q = 0
            while q < len(seg):
                tc_th = seg[q]
                counts = list(seg[q + 1:q + 17])
                ns = sum(counts)
                syms = list(seg[q + 17:q + 17 + ns])
                lut = build_huff(counts, syms)
                hts[(tc_th >> 4, tc_th & 15)] = lut
                q += 17 + ns
        elif m == 0xDD:                    # DRI
            restart = struct.unpack(">H", seg[0:2])[0]
        elif m == 0xDA:                    # SOS
            ns = seg[0]
            order = []
            for i in range(ns):
                cid = seg[1 + 2 * i]
                td_ta = seg[2 + 2 * i]
                order.append((cid, td_ta >> 4, td_ta & 15))
            scan = d[p + ln:]
            yid = 0
            hmax = max(c["h"] for c in comps)
            vmax = max(c["v"] for c in comps)
            for i, c in enumerate(comps):
                if c["h"] == hmax and c["v"] == vmax:
                    yid = i
                    break
            return _scan(scan, order, comps, hts, qt,
                         restart, w, h, yid)
        p += ln
    raise ValueError("no SOS")

def _scan(sd, order, comps, hts, qt, restart, w, h,
          yid):
    cs = []
    for cid, td, ta in order:
        for c in comps:
            if c["id"] == cid:
                cs.append((c, td, ta))
    hmax = max(c["h"] for c, _, _ in cs)
    vmax = max(c["v"] for c, _, _ in cs)
    mcux = (w + 8 * hmax - 1) // (8 * hmax)
    mcuy = (h + 8 * vmax - 1) // (8 * vmax)
    planes = []
    for c, _, _ in cs:
        cw = mcux * c["h"] * 8
        ch = mcuy * c["v"] * 8
        planes.append([[0] * cw for _ in range(ch)])
    br = BitReader(sd)
    pred = [0] * len(cs)
    mcu_count = 0
    for my in range(mcuy):
        for mx in range(mcux):
            if restart and mcu_count == restart:
                br = BitReader(br.d[br.p:])
                pred = [0] * len(cs)
                mcu_count = 0
            mcu_count += 1
            for ci, (c, td, ta) in enumerate(cs):
                for by in range(c["v"]):
                    for bx in range(c["h"]):
                        blk = [[0] * 8 for _ in range(8)]
                        t = decode_huff(br, hts[(0, td)])
                        if t:
                            v = br.bits(t)
                            blk[0][0] = extend(v, t) \
                                + pred[ci]
                        else:
                            blk[0][0] = pred[ci]
                        pred[ci] = blk[0][0]
                        k = 1
                        while k < 64:
                            rs = decode_huff(
                                br, hts[(1, ta)])
                            r, s = rs >> 4, rs & 15
                            if s == 0:
                                if r == 15:
                                    k += 16
                                    continue
                                break
                            k += r
                            if k > 63:
                                break
                            v = br.bits(s)
                            zz = ZIGZAG[k // 8][k % 8]
                            blk[zz // 8][zz % 8] = \
                                extend(v, s)
                            k += 1
                        q = qt[c["tq"]]
                        for yy in range(8):
                            for xx in range(8):
                                blk[yy][xx] *= q[
                                    ZINV[yy * 8 + xx]]
                        if ci != yid:
                            continue      # chroma: parse only
                        px = idct(blk)
                        ox = (mx * c["h"] + bx) * 8
                        oy = (my * c["v"] + by) * 8
                        pl = planes[ci]
                        for yy in range(8):
                            row = pl[oy + yy]
                            for xx in range(8):
                                row[ox + xx] = max(
                                    0, min(255,
                                    int(px[yy][xx] + 128)))
    # Y plane is the component with the largest subsampling
    yi = 0
    for i, (c, _, _) in enumerate(cs):
        if c["h"] == hmax and c["v"] == vmax:
            yi = i
            break
    ypl = planes[yi]
    out = bytearray(w * h)
    for y in range(h):
        row = ypl[y]
        out[y * w:(y + 1) * w] = bytes(row[:w])
    return w, h, bytes(out)

if __name__ == "__main__":
    import sys
    w, h, y = decode(sys.argv[1])
    print("decoded %dx%d, %d bytes Y" % (w, h, len(y)))
    if len(sys.argv) > 2:
        open(sys.argv[2], "wb").write(y)

