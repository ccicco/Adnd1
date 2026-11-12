#!/usr/bin/env python3
"""mktexstamp.py - bake a construct stamp from a generated texture master.

The image-to-image pipeline's back half. The front half (mkstamp --guide)
handed a generator an exact-geometry grayscale guide; the generator painted
it; this tool turns the painted master back into the stamped RGBA overlay.

Doctrine:
  - GEOMETRY IS THE MASK, NEVER THE IMAGE: the stamp's alpha and class
    layout come from the SPEC's class map (the same geometry source mkstamp
    renders from), so generator wobble inside a region is harmless and any
    drift AT a region boundary only softens that edge - the stamp's
    geometry cannot drift, by construction.
  - THE ONLY DOWNSAMPLE IS THE SINGLE EXACT AREA-AVERAGE (seamlock
    doctrine): 2560x2560 master -> 256x256 stamp, integer arithmetic in
    64ths of a pixel (x10 blocks), one rounding point per channel per px.
  - VALIDATION BEFORE BAKING: the master's per-pixel luminance must agree
    with the guide gray of its class (tolerance tol_gray, default 45) for at
    least min_match (default 0.85) of each major class's pixels. A master
    whose geometry drifted reads as mismatches and the tool fails loudly
    instead of baking a wrong-geometry stamp.

usage: mktexstamp.py SPEC.json MASTER.png OUT.png [--preview PATH]
       [--tol N] [--min-match F]

MASTER.png is the generator's painted guide at 10x (tile_px*10 per square).
If your master is a JPG, convert first: jpg2png.py MASTER.jpg MASTER.png
(the generator's JPEG artifacts should not ride through a second lossy
round-trip in the bake).
"""
import sys, json, zlib, struct, os

# ---------------- stdlib PNG I/O (mkstamp pattern) ----------------

def read_png_rgba(path):
    d = open(path, "rb").read()
    if d[:8] != b"\x89PNG\r\n\x1a\n":
        sys.exit("not a PNG: " + path)
    pos, idat, w, h, bd, ct = 8, b"", 0, 0, 0, 0
    while pos < len(d):
        ln, typ = struct.unpack(">I4s", d[pos:pos+8]); pos += 8
        data = d[pos:pos+ln]; pos += ln + 4
        if typ == b"IHDR":
            w, h, bd, ct = struct.unpack(">IIBB", data[:10])
            if bd != 8 or ct not in (2, 6):
                sys.exit("expected 8-bit RGB/RGBA PNG: " + path)
        elif typ == b"IDAT":
            idat += data
    raw = zlib.decompress(idat)
    ch = 4 if ct == 6 else 3
    stride = w * ch
    prev = bytearray(stride)
    out = []
    p = 0
    for y in range(h):
        f = raw[p]; p += 1
        line = bytearray(raw[p:p+stride]); p += stride
        for i in range(stride):
            a = line[i-ch] if i >= ch else 0
            b = prev[i]
            c = prev[i-ch] if i >= ch else 0
            if f == 1:
                line[i] = (line[i] + a) & 255
            elif f == 2:
                line[i] = (line[i] + b) & 255
            elif f == 3:
                line[i] = (line[i] + ((a + b) >> 1)) & 255
            elif f == 4:
                pp = a + b - c
                pa, pb, pc = abs(pp-a), abs(pp-b), abs(pp-c)
                pr = a if (pa <= pb and pa <= pc) else (b if pb <= pc else c)
                line[i] = (line[i] + pr) & 255
        out.append(bytes(line))
        prev = line
    return w, h, ch, out

def write_png_rgba(path, rows, w, h):
    def chunk(t, data):
        c = t + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c))
    raw = b"".join(b"\x00" + r for r in rows)
    png = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0))
           + chunk(b"IDAT", zlib.compress(raw, 9))
           + chunk(b"IEND", b""))
    open(path, "wb").write(png)

# surface classes (mkstamp's geometry source, replicated exactly)
C_BG, C_FLOOR, C_TREAD, C_RISER, C_LBAND, C_LLIP = 0, 1, 2, 3, 4, 5
GUIDE_GRAY = {C_BG: 0, C_FLOOR: 90, C_TREAD: 215, C_RISER: 55,
              C_LBAND: 190, C_LLIP: 130}

def build_class_map(spec):
    """The exact geometry pass mkstamp runs, at STAMP resolution (tile_px)."""
    path = spec["path"]
    comp = spec["compose"]
    T = comp["tile_px"]
    PITCH = comp["tread_pitch_px"]
    BAND = comp["flight_band_px"]
    TREADP = comp.get("tread_tread_px", 8)
    LIP_PX = comp.get("lip_px", 3)
    LANDING = comp.get("landing_mode", "full_square")

    squares = []
    segments = []
    for seg in path["segments"]:
        segments.append(seg)
        squares.extend([tuple(q) for q in seg["squares"]])
    squares = sorted(set(squares))
    landings = set(tuple(q) for q in path["landings"])
    x0sq = min(s[0] for s in squares); y0sq = min(s[1] for s in squares)
    x1sq = max(s[0] for s in squares); y1sq = max(s[1] for s in squares)
    W = (x1sq - x0sq + 1) * T
    H = (y1sq - y0sq + 1) * T

    cls = [[C_BG] * W for _ in range(H)]
    for seg in segments:
        segs = [tuple(q) for q in seg["squares"]]
        if seg["dir"] in ("E", "W"):
            segs.sort(key=lambda s: s[0])
            if seg["dir"] == "W": segs = list(reversed(segs))
        else:
            segs.sort(key=lambda s: s[1])
            if seg["dir"] == "N": segs = list(reversed(segs))
        ew = seg["dir"] in ("E", "W")
        travel = 0
        for (sx, sy) in segs:
            px = (sx - x0sq) * T
            py = (sy - y0sq) * T
            is_landing = (sx, sy) in landings
            for yy in range(T):
                for xx in range(T):
                    if seg["dir"] == "E":
                        o = xx
                    elif seg["dir"] == "W":
                        o = T - 1 - xx
                    elif seg["dir"] == "S":
                        o = yy
                    else:
                        o = T - 1 - yy
                    a = travel + o
                    cx, cy = px + xx, py + yy
                    if is_landing:
                        if LANDING == "band":
                            pos = xx if ew else yy
                            b0 = (T - BAND) // 2
                            if b0 <= pos < b0 + BAND:
                                edge = min(pos - b0, b0 + BAND - 1 - pos)
                                cls[cy][cx] = C_LLIP if edge < LIP_PX else C_LBAND
                            else:
                                cls[cy][cx] = C_FLOOR
                        else:
                            edge = min(xx, yy, T - 1 - xx, T - 1 - yy)
                            cls[cy][cx] = C_LLIP if edge < LIP_PX else C_LBAND
                    else:
                        cls[cy][cx] = C_RISER if a % PITCH >= TREADP else C_TREAD
            travel += T
    return W, H, T, cls

def main():
    argv = sys.argv[1:]
    args, preview = [], None
    tol, min_match = 45, 0.85
    i = 0
    while i < len(argv):
        if argv[i] == "--preview":
            preview = argv[i + 1]; i += 2
        elif argv[i] == "--tol":
            tol = int(argv[i + 1]); i += 2
        elif argv[i] == "--min-match":
            min_match = float(argv[i + 1]); i += 2
        else:
            args.append(argv[i]); i += 1
    if len(args) != 3:
        sys.exit("usage: mktexstamp.py SPEC.json MASTER.png OUT.png [--preview PATH] [--tol N] [--min-match F]")
    spec_path, master_path, out_path = args
    spec = json.load(open(spec_path))
    W, H, T, cls = build_class_map(spec)
    S = 10   # master is the 10x guide: tile_px*10 per square
    mw, mh, ch, mrows = read_png_rgba(master_path)
    if (mw, mh) != (W * S, H * S):
        sys.exit("master is %dx%d but the spec wants %dx%d (10x of the "
                 "%dx%d stamp). Re-render the guide: mkstamp.py ... --guide"
                 % (mw, mh, W * S, H * S, W, H))

    # ---- validation: master luminance must agree with guide gray per class ----
    stats = {}
    for c in GUIDE_GRAY:
        stats[c] = [0, 0]   # [matched, total]
    for y in range(H * S):
        row = mrows[y]
        crow = cls[y // S]
        for x in range(W * S):
            c = crow[x // S]
            o = x * ch
            lum = (row[o] + row[o + 1] + row[o + 2]) / 3.0
            if abs(lum - GUIDE_GRAY[c]) <= tol:
                stats[c][0] += 1
            stats[c][1] += 1
    print("validation (luminance vs guide gray, tol %d):" % tol)
    ok = True
    for c in sorted(stats):
        m, t = stats[c]
        frac = m / float(t) if t else 1.0
        name = {0: "background", 1: "floor", 2: "tread", 3: "riser",
                4: "landing", 5: "trim"}[c]
        flag = ""
        if t and frac < min_match:
            ok = False
            flag = "  <-- BELOW %.0f%%" % (min_match * 100)
        if t:
            print("  %-10s %6.2f%% match (%d px)%s" % (name, frac * 100, t, flag))
    if not ok:
        sys.exit("FAIL: the master's geometry drifted from the guide - "
                 "do not bake. Re-run the generator on the guide image.")

    # ---- bake: single exact x10 area-average, masked by class ----
    stamp = bytearray(W * H * 4)
    for y in range(H):
        crow = cls[y]
        for x in range(W):
            if crow[x] == C_BG:
                continue
            r = g = b = 0
            for sy in range(y * S, (y + 1) * S):
                row = mrows[sy]
                for sx in range(x * S, (x + 1) * S):
                    o = sx * ch
                    r += row[o]; g += row[o + 1]; b += row[o + 2]
            n = S * S
            o = (y * W + x) * 4
            stamp[o] = (r * 2 + n) // (2 * n)   # half-up per channel
            stamp[o + 1] = (g * 2 + n) // (2 * n)
            stamp[o + 2] = (b * 2 + n) // (2 * n)
            stamp[o + 3] = 255
    rows = [bytes(stamp[y * W * 4:(y + 1) * W * 4]) for y in range(H)]
    write_png_rgba(out_path, rows, W, H)
    print("baked: %s (%dx%d, single exact x%d area-average, class-masked alpha)"
          % (out_path, W, H, S))
    if preview:
        prows = []
        for r in rows:
            r3 = bytearray()
            for x in range(W):
                px = r[x * 4:x * 4 + 4]
                r3 += px * 3
            prows.append(bytes(r3)); prows.append(bytes(r3)); prows.append(bytes(r3))
        write_png_rgba(preview, prows, W * 3, H * 3)
        print("preview: %s (%dx%d)" % (preview, W * 3, H * 3))

if __name__ == "__main__":
    main()
