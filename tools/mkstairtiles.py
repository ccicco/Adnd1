#!/usr/bin/env python3
"""mkstairtiles.py - bake the stair system's two composing tiles.

The two-tile ruling (2026-11-11): the whole stair system composes from a
STAIR TILE (the step pattern) and a LANDING TILE (the platform) placed per
square - no monolithic stairwell stamp. The step pitch ruling: 5 steps per
10-foot square at 2 feet each (1.5ft tread + 0.5ft riser = 128 subpixels
exactly at the 640 construct supersample, 1ft = 64 subpx), the only layout
that wraps the 64px tile seamlessly so pitch continues across squares by
construction. Supersedes the measured 11px pitch (which cannot tile).

Pipeline (all deterministic, no generative step):
  1. The gated tread master (any square size, e.g. 1024x1024 generator
     output) is area-averaged down to the 640 construct supersample
     (rational 8:5 arithmetic when the master is 1024; exact for any
     master size, integer math in 64ths of a subpixel).
  2. The pattern is applied at 640 where every constant is an integer:
     stair tile: 5 steps x 128 subpx, tread 96 (lit) + riser 32 (x riser_
     shade), bands across the travel axis, grain along the tread tile's
     horizontal axis;
     landing tile: full-square platform (x1.0) framed by a trim ring
     (trim_ft wide, x trim_shade) on all four sides.
  3. The single x10 exact area-average bakes each 640 master to the
     64x64 tile (integer arithmetic, one rounding point per channel).
  4. The vertical stair variant is an exact rot90 of the baked tile.

usage: mkstairtiles.py MASTER.png TILES_DIR [--riser F] [--trim-shade F]
       [--trim-ft F]

Writes TILES_DIR/stair_step.png, stair_step_v.png, stair_landing.png.
"""
import sys, zlib, struct, os

def read_png_rgb(path):
    d = open(path, "rb").read()
    if d[:8] != b"\x89PNG\r\n\x1a\n":
        sys.exit("not a PNG: " + path)
    pos, idat, w, h, bd, ct = 8, b"", 0, 0, 0, 0
    while pos < len(d):
        ln, typ = struct.unpack(">I4s", d[pos:pos+8]); pos += 8
        data = d[pos:pos+ln]; pos += ln + 4
        if typ == b"IHDR":
            w, h, bd, ct = struct.unpack(">IIBB", data[:10])
            if bd != 8 or ct != 2:
                sys.exit("expected 8-bit RGB PNG: " + path)
        elif typ == b"IDAT":
            idat += data
    raw = zlib.decompress(idat)
    stride = w * 3
    prev = bytearray(stride)
    out = []
    p = 0
    for y in range(h):
        f = raw[p]; p += 1
        line = bytearray(raw[p:p+stride]); p += stride
        for i in range(stride):
            a = line[i-3] if i >= 3 else 0
            b = prev[i]
            c = prev[i-3] if i >= 3 else 0
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
    return w, h, out

def write_png_rgb(path, rows, w, h):
    def chunk(t, data):
        c = t + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c))
    raw = b"".join(b"\x00" + r for r in rows)
    png = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
           + chunk(b"IDAT", zlib.compress(raw, 9))
           + chunk(b"IEND", b""))
    open(path, "wb").write(png)

def resample_exact(rows, w, h, W2):
    """Exact area-average h x w -> h x W2 along x (rational, integer math in
    64ths of a source pixel). Returns new rows."""
    out = []
    # source span of target pixel p: [p*w/W2, (p+1)*w/W2) in 64ths
    starts = [p * w * 64 // W2 for p in range(W2 + 1)]
    for row in rows:
        nrow = bytearray(W2 * 3)
        for p in range(W2):
            s0, s1 = starts[p], starts[p + 1]
            r = g = b = 0
            total = 0
            i = s0
            while i < s1:
                sx = i // 64
                take = 64 - (i % 64)
                if i + take > s1:
                    take = s1 - i
                o = sx * 3
                r += row[o] * take; g += row[o+1] * take; b += row[o+2] * take
                total += take
                i += take
            o = p * 3
            nrow[o] = (r * 2 + total) // (2 * total)
            nrow[o+1] = (g * 2 + total) // (2 * total)
            nrow[o+2] = (b * 2 + total) // (2 * total)
        out.append(bytes(nrow))
    return out

def rot90(rows, w, h):
    """Exact 90-degree rotation: out[x][h-1-y] = rows[y][x]."""
    out = []
    for x in range(w):
        nrow = bytearray()
        for y in range(h - 1, -1, -1):
            nrow += rows[y][x*3:x*3+3]
        out.append(bytes(nrow))
    return out

def main():
    argv = sys.argv[1:]
    riser_shade, trim_shade, trim_ft = 0.42, 0.55, 0.5
    args = []
    i = 0
    while i < len(argv):
        if argv[i] == "--riser":
            riser_shade = float(argv[i+1]); i += 2
        elif argv[i] == "--trim-shade":
            trim_shade = float(argv[i+1]); i += 2
        elif argv[i] == "--trim-ft":
            trim_ft = float(argv[i+1]); i += 2
        else:
            args.append(argv[i]); i += 1
    if len(args) != 2:
        sys.exit("usage: mkstairtiles.py MASTER.png TILES_DIR [--riser F] [--trim-shade F] [--trim-ft F]")
    master_path, tiles_dir = args

    SS = 640                      # construct supersample (1 ft = 64 subpx)
    STEP = 128                    # 2 ft per step, 5 steps per square
    TREAD_SUB = 96                # 1.5 ft lit tread
    TRIM_SUB = int(round(trim_ft * 64))

    mw, mh, mrows = read_png_rgb(master_path)
    if mw != mh:
        sys.exit("master must be square: %dx%d" % (mw, mh))
    # 1. master -> 640 supersample (x and y), exact area-average
    r640 = resample_exact(mrows, mw, mh, SS)
    # transpose trick for y: resample columns by rotating
    r640 = rot90(resample_exact(rot90(r640, SS, SS), SS, SS, SS), SS, SS)

    # 2. pattern at 640
    stair = []
    for y in range(SS):
        row = bytearray()
        src = r640[y]
        for x in range(SS):
            frac = x % STEP
            f = riser_shade if frac >= TREAD_SUB else 1.0
            o = x * 3
            row += bytes((int(src[o]*f), int(src[o+1]*f), int(src[o+2]*f)))
        stair.append(bytes(row))
    landing = []
    for y in range(SS):
        row = bytearray()
        src = r640[y]
        ey = min(y, SS - 1 - y)
        for x in range(SS):
            f = trim_shade if min(ey, x, SS - 1 - x) < TRIM_SUB else 1.0
            o = x * 3
            row += bytes((int(src[o]*f), int(src[o+1]*f), int(src[o+2]*f)))
        landing.append(bytes(row))

    # 3. single x10 exact area-average -> 64x64
    T = SS // 10
    def bake(rows640):
        out = []
        for y in range(T):
            nrow = bytearray(T * 3)
            for x in range(T):
                r = g = b = 0
                for yy in range(y*10, (y+1)*10):
                    row = rows640[yy]
                    for xx in range(x*10, (x+1)*10):
                        o = xx * 3
                        r += row[o]; g += row[o+1]; b += row[o+2]
                o = x * 3
                nrow[o] = (r + 50) // 100     # (r*2+100)//200 == half-up
                nrow[o+1] = (g + 50) // 100
                nrow[o+2] = (b + 50) // 100
            out.append(bytes(nrow))
        return out
    stair_t = bake(stair)
    landing_t = bake(landing)

    os.makedirs(tiles_dir, exist_ok=True)
    write_png_rgb(os.path.join(tiles_dir, "stair_step.png"), stair_t, T, T)
    write_png_rgb(os.path.join(tiles_dir, "stair_step_v.png"), rot90(stair_t, T, T), T, T)
    write_png_rgb(os.path.join(tiles_dir, "stair_landing.png"), landing_t, T, T)
    print("baked %s: stair_step.png + stair_step_v.png + stair_landing.png "
          "(64x64, 5 steps/sq = 2ft pitch, tread 1.5ft + riser 0.5ft, trim %.2fft, riser x%.2f, trim x%.2f)"
          % (tiles_dir, trim_ft, riser_shade, trim_shade))

if __name__ == "__main__":
    main()
