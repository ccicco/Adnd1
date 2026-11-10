#!/usr/bin/env python3
"""mkstamp.py - compose a construct stamp from its spec manifest + gated tiles.

Renders construct stamps (e.g. the stairwell_upper reverse-J stair run) from the
spec JSON and the baked 64x64 tiles. Deterministic: same inputs, same pixels.

Geometry rules (construct doctrine, all constants measured/composed on the
64px tile grid):
  - Each spec square renders at exactly 64x64 px; squares outside the path
    stay TRANSPARENT (RGBA) so the stamp overlays the region build.
  - Base layer of every path square: its floor material (coverage-driven).
  - Treads: bands perpendicular to travel direction, one 11px band per pitch
    step along the direction of travel (pitch 11px, no gaps - full-pitch
    plank bands), spanning the full 64px flight width.
  - E-W flights use the horizontal-grain tread tile; N-S flights the vertical.
  - Landing squares: a 40px flight band of tread material crosses the turn
    (perpendicular to the outgoing direction), floor elsewhere.
  - Tread pitch continues across square boundaries within a segment
    (global pitch per segment, from the segment's first square).

usage: mkstamp.py SPEC.json TILES_DIR OUT.png [--preview PATH]
"""
import sys, json, zlib, struct, os

# ---------------- stdlib PNG I/O ----------------

def read_png(path):
    d = open(path, "rb").read()
    if d[:8] != b"\x89PNG\r\n\x1a\n":
        sys.exit("not a PNG: " + path)
    pos, idat, w, h, ct = 8, b"", 0, 0, 0
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
    bpp, stride = 3, w * 3
    out = bytearray(h * stride)
    prev = bytearray(stride)
    p = 0
    for y in range(h):
        f = raw[p]; p += 1
        line = bytearray(raw[p:p+stride]); p += stride
        if f == 1:
            for i in range(bpp, stride): line[i] = (line[i] + line[i-bpp]) & 255
        elif f == 2:
            for i in range(stride): line[i] = (line[i] + prev[i]) & 255
        elif f == 3:
            for i in range(stride):
                a = line[i-bpp] if i >= bpp else 0
                line[i] = (line[i] + ((a + prev[i]) >> 1)) & 255
        elif f == 4:
            for i in range(stride):
                a = line[i-bpp] if i >= bpp else 0
                b = prev[i]; c = prev[i-bpp] if i >= bpp else 0
                pp = a + b - c
                pa, pb, pc = abs(pp-a), abs(pp-b), abs(pp-c)
                line[i] = (line[i] + (a if (pa <= pb and pa <= pc) else (b if pb <= pc else c))) & 255
        out[y*stride:(y+1)*stride] = line
        prev = line
    return w, h, bytes(out)

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

# ---------------- composition ----------------

def clip_band(tile, w, h, x0, y0, bw, bh):
    """Exact pixel clip of a bw x bh rect from the tile at (x0,y0). Tiles are
    seam-proven, so any clip window is valid material; offsets wrap."""
    out = bytearray()
    for y in range(bh):
        ty = (y0 + y) % h
        base = ty * w * 3
        for x in range(bw):
            tx = (x0 + x) % w
            o = base + tx * 3
            out += tile[o:o+3]
    return bytes(out)

def main():
    argv = sys.argv[1:]
    args, preview = [], None
    i = 0
    while i < len(argv):
        if argv[i] == "--preview":
            preview = argv[i + 1]; i += 2
        else:
            args.append(argv[i]); i += 1
    if len(args) != 3:
        sys.exit("usage: mkstamp.py SPEC.json TILES_DIR OUT.png [--preview PATH]")
    spec_path, tiles_dir, out_path = args
    spec = json.load(open(spec_path))
    path = spec["path"]
    comp = spec["compose"]
    T = comp["tile_px"]
    PITCH = comp["tread_pitch_px"]
    BAND = comp["flight_band_px"]
    floor_name = comp["floor"].split(",")[0].strip()
    fw, fh, floor = read_png(os.path.join(tiles_dir, floor_name + ".png"))
    hw, hh, tread_h = read_png(os.path.join(tiles_dir, comp["tread_material"]["E-W segments"] + ".png"))
    vw, vh, tread_v = read_png(os.path.join(tiles_dir, comp["tread_material"]["N-S segments"] + ".png"))

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
    # RGBA canvas, transparent outside path squares
    canvas = bytearray(W * H * 4)

    def set_px(x, y, r, g, b, a=255):
        o = (y * W + x) * 4
        canvas[o] = r; canvas[o+1] = g; canvas[o+2] = b; canvas[o+3] = a

    # floor base + per-square layers
    for (sx, sy) in squares:
        px = (sx - x0sq) * T
        py = (sy - y0sq) * T
        for yy in range(T):
            for xx in range(T):
                o = (yy * fw + xx) * 3
                set_px(px + xx, py + yy, floor[o], floor[o+1], floor[o+2])
    # treads per segment (global pitch per segment, travel-ordered)
    for seg in segments:
        segs = [tuple(q) for q in seg["squares"]]
        # order squares along travel from 'from'
        fx, fy = seg["from"]; tx, ty = seg["to"]
        if seg["dir"] in ("E", "W"):
            segs.sort(key=lambda s: s[0])
            if seg["dir"] == "W": segs = list(reversed(segs))
        else:
            segs.sort(key=lambda s: s[1])
            if seg["dir"] == "N": segs = list(reversed(segs))
        # travel distance origin at first square edge
        travel = 0
        for k, (sx, sy) in enumerate(segs):
            px = (sx - x0sq) * T
            py = (sy - y0sq) * T
            is_landing = (sx, sy) in landings
            if is_landing:
                # flight band: BAND-wide strip of tread material crossing the
                # square, perpendicular to the OUTGOING direction, centered
                tile = tread_h if seg["dir"] in ("E", "W") else tread_v
                if seg["dir"] in ("E", "W"):
                    bx = px + (T - BAND) // 2
                    band = clip_band(tile, fw, fh, bx % fw, 0, BAND, T)
                    for yy in range(T):
                        for xx in range(BAND):
                            o = (yy * BAND + xx) * 3
                            set_px(bx + xx, py + yy, band[o], band[o+1], band[o+2])
                else:
                    by = py + (T - BAND) // 2
                    band = clip_band(tile, fw, fh, 0, by % fh, T, BAND)
                    for yy in range(BAND):
                        for xx in range(T):
                            o = (yy * T + xx) * 3
                            set_px(px + xx, by + yy, band[o], band[o+1], band[o+2])
            else:
                # treads: bands perpendicular to travel, pitch along travel
                if seg["dir"] in ("E", "W"):
                    tile = tread_h
                    start = travel - k * 0  # global: travel accumulates
                    while True:
                        b0 = travel + (0)
                        # bands at absolute pitch positions within this square
                        break
                    # pitch continues across squares: absolute position a = travel + offset
                    for off in range(0, T, 1):
                        a = travel + off
                        if a % PITCH == 0:
                            bw = min(PITCH, T - off)
                            if seg["dir"] == "E":
                                bx0 = px + off
                                band = clip_band(tile, fw, fh, (bx0) % fw, 0, bw, T)
                            else:
                                bx0 = px + T - off - bw
                                band = clip_band(tile, fw, fh, (bx0) % fw, 0, bw, T)
                            for yy in range(T):
                                for xx in range(bw):
                                    o = (yy * bw + xx) * 3
                                    set_px(bx0 + xx, py + yy, band[o], band[o+1], band[o+2])
                else:
                    tile = tread_v
                    for off in range(0, T, 1):
                        a = travel + off
                        if a % PITCH == 0:
                            bh = min(PITCH, T - off)
                            if seg["dir"] == "S":
                                by0 = py + off
                                band = clip_band(tile, fw, fh, 0, (py + off) % fh, T, bh)
                            else:
                                by0 = py + T - off - bh
                                band = clip_band(tile, fw, fh, 0, (by0) % fh, T, bh)
                            for yy in range(bh):
                                for xx in range(T):
                                    o = (yy * T + xx) * 3
                                    set_px(px + xx, by0 + yy, band[o], band[o+1], band[o+2])
            travel += T
    # write RGBA rows
    rows = []
    for y in range(H):
        rows.append(bytes(canvas[y*W*4:(y+1)*W*4]))
    write_png_rgba(out_path, rows, W, H)
    print("stamp: %s -> %s (%dx%d px, %d path squares, pitch %dpx, band %dpx)"
          % (spec["id"], out_path, W, H, len(squares), PITCH, BAND))
    if preview:
        # 3x nearest upscale preview
        prows = []
        for r in rows:
            r3 = bytearray()
            for x in range(W):
                px = r[x*4:x*4+4]
                r3 += px * 3
            prows.append(bytes(r3))
            prows.append(bytes(r3))
            prows.append(bytes(r3))
        write_png_rgba(preview, prows, W*3, H*3)
        print("preview: %s (%dx%d)" % (preview, W*3, H*3))

if __name__ == "__main__":
    main()
