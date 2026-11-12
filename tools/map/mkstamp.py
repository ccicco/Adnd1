#!/usr/bin/env python3
"""mkstamp.py - compose a construct stamp from its spec manifest + gated tiles.

Renders construct stamps (e.g. the stairwell_upper reverse-J stair run) from
the spec JSON and the baked 64x64 tiles. Deterministic: same inputs, same pixels.

Geometry rules (construct doctrine, all constants measured/composed on the
64px tile grid):
  - Each spec square renders at exactly 64x64 px; squares outside the path
    stay TRANSPARENT (RGBA) so the stamp overlays the region build.
  - Base layer of every path square: its floor material (coverage-driven).
  - E-W flights use the horizontal-grain tread tile; N-S flights the vertical.
  - Tread pitch continues across square boundaries within a segment
    (global pitch per segment, from the segment's first square).

STAIR READABILITY (v2 - what makes a flight read as stairs, not stripes):
  - Each pitch step splits into TREAD + RISER along the travel direction:
    tread_px of lit plank, then (pitch - tread_px) of riser shadow (the
    vertical face), so every step has the light/dark tread-riser alternation
    the eye expects. The riser sits at the ASCENDING edge of its tread.
  - DEPTH GRADIENT: a gentle global brightness ramp along the whole run -
    the top of the staircase is lighter than the bottom (depth_shade
    spread, default 0.26).
  - LANDINGS ARE FULL-SQUARE PLATFORMS (v2.2, per his Gemini-reference
    ruling): a landing occupies its ENTIRE square of the same tread wood
    (horizontal grain), framed by a dark trim ring (lip_px wide, trim_shade
    brightness) around all four sides - not a flight band crossing the
    square. No step edge where a flight meets the platform. Legacy band
    mode available via compose "landing_mode": "band".

GEOMETRY GUIDE MODE (--guide PATH, v2.1): for image-to-image generation -
generators paint texture well but cannot follow lattice geometry in prose,
so we hand them the geometry instead. Renders the SAME geometry at 10x scale
(tile_px*10 per square - a 256x256 stamp becomes 2560x2560, 1 square = 640px
= 10 feet, 1 foot = 64px exactly) as a FLAT GRAYSCALE guide: one neutral
gray per surface class, geometry only, by construction. Classes: background
black (0), floor (90), tread (215), riser (55), landing band (190),
landing lip (130). Retexture it with a generator edit pass and keep every
edge pixel-identical.

Compose keys consumed (all optional beyond the originals; defaults in
parentheses): tile_px, tread_pitch_px (11), flight_band_px (40),
tread_tread_px (8 - lit portion of the pitch), riser_shade (0.42),
depth_shade (0.26), lip_px (3), lip_shade (0.72).

usage: mkstamp.py SPEC.json TILES_DIR OUT.png [--preview PATH] [--guide PATH]
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

# surface classes (single geometry source for stamp + guide)
C_BG, C_FLOOR, C_TREAD, C_RISER, C_LBAND, C_LLIP = 0, 1, 2, 3, 4, 5
GUIDE_GRAY = {C_BG: 0, C_FLOOR: 90, C_TREAD: 215, C_RISER: 55, C_LBAND: 190, C_LLIP: 130}

# ---------------- composition ----------------

def main():
    argv = sys.argv[1:]
    args, preview, guide = [], None, None
    i = 0
    while i < len(argv):
        if argv[i] == "--preview":
            preview = argv[i + 1]; i += 2
        elif argv[i] == "--guide":
            guide = argv[i + 1]; i += 2
        else:
            args.append(argv[i]); i += 1
    if len(args) != 3:
        sys.exit("usage: mkstamp.py SPEC.json TILES_DIR OUT.png [--preview PATH] [--guide PATH]")
    spec_path, tiles_dir, out_path = args
    spec = json.load(open(spec_path))
    path = spec["path"]
    comp = spec["compose"]
    T = comp["tile_px"]
    PITCH = comp["tread_pitch_px"]
    BAND = comp["flight_band_px"]
    TREADP = comp.get("tread_tread_px", 8)         # lit portion of the pitch
    RISER = comp.get("riser_shade", 0.42)          # riser face brightness
    DEPTH = comp.get("depth_shade", 0.26)          # top-light/bottom-dark spread
    LIP_PX = comp.get("lip_px", 3)
    LIP = comp.get("lip_shade", 0.72)          # legacy band-mode edge shade
    TRIM = comp.get("trim_shade", 0.55)        # landing platform trim ring
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
    TOTAL = len(squares) * T    # total run travel for the depth gradient

    # ---- geometry pass: class map + grain map + absolute-travel map ----
    cls = [[C_BG] * W for _ in range(H)]
    grain = [[0] * W for _ in range(H)]      # 0 = h tile (E-W), 1 = v tile (N-S)
    atr = [[0] * W for _ in range(H)]        # absolute travel along the run
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
                            # full-square platform: trim ring on all four sides
                            edge = min(xx, yy, T - 1 - xx, T - 1 - yy)
                            cls[cy][cx] = C_LLIP if edge < LIP_PX else C_LBAND
                    else:
                        cls[cy][cx] = C_RISER if a % PITCH >= TREADP else C_TREAD
                    # landings use horizontal-grain planks (his reference);
                    # flights use the grain that matches their travel axis
                    if is_landing:
                        grain[cy][cx] = 0
                    else:
                        grain[cy][cx] = 0 if ew else 1
                    atr[cy][cx] = a
            travel += T

    # ---- render pass ----
    if guide:
        S = 10
        GW, GH = W * S, H * S
        canvas = bytearray(GW * GH * 4)
        for y in range(H):
            for x in range(W):
                g = GUIDE_GRAY[cls[y][x]]
                for dy in range(S):
                    base = ((y * S + dy) * GW + x * S) * 4
                    for dx in range(S):
                        canvas[base + dx*4] = g
                        canvas[base + dx*4 + 1] = g
                        canvas[base + dx*4 + 2] = g
                        canvas[base + dx*4 + 3] = 255
        rows = [bytes(canvas[y*GW*4:(y+1)*GW*4]) for y in range(GH)]
        write_png_rgba(guide, rows, GW, GH)
        print("guide: %s -> %s (%dx%d px, 1 square = %dpx = 10 feet, 1 foot = %dpx)"
              % (spec["id"], guide, GW, GH, T * S, T * S // 10))
        return

    floor_name = comp["floor"].split(",")[0].strip()
    fw, fh, floor = read_png(os.path.join(tiles_dir, floor_name + ".png"))
    hw, hh, tread_h = read_png(os.path.join(tiles_dir, comp["tread_material"]["E-W segments"] + ".png"))
    vw, vh, tread_v = read_png(os.path.join(tiles_dir, comp["tread_material"]["N-S segments"] + ".png"))

    def grad(a):
        # depth gradient: brightness 1-DEPTH at the bottom (a=0),
        # 1.0 at the top (a=TOTAL)
        return 1.0 - DEPTH * (1.0 - a / float(TOTAL))

    # RGBA canvas, transparent outside path squares
    canvas = bytearray(W * H * 4)
    for y in range(H):
        for x in range(W):
            c = cls[y][x]
            if c == C_BG:
                continue
            xx, yy = x % T, y % T
            a = atr[y][x]
            f = grad(a)
            if c == C_FLOOR:
                o = (yy * fw + xx) * 3
                r, g, b = floor[o], floor[o+1], floor[o+2]
            else:
                tile = tread_h if grain[y][x] == 0 else tread_v
                o = (yy * 64 + xx) * 3
                if c == C_RISER:
                    f *= RISER
                elif c == C_LLIP:
                    f *= TRIM
                r, g, b = int(tile[o]*f), int(tile[o+1]*f), int(tile[o+2]*f)
            off = (y * W + x) * 4
            canvas[off] = r; canvas[off+1] = g; canvas[off+2] = b; canvas[off+3] = 255

    rows = [bytes(canvas[y*W*4:(y+1)*W*4]) for y in range(H)]
    write_png_rgba(out_path, rows, W, H)
    print("stamp: %s -> %s (%dx%d px, %d path squares, pitch %dpx = tread %d + riser %d, band %dpx)"
          % (spec["id"], out_path, W, H, len(squares), PITCH, TREADP, PITCH - TREADP, BAND))
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
