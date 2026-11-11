#!/usr/bin/env python3
"""mkplace.py - place floor/ground tiles as a new layer in the new-map ORA.

Adds a 'floor' layer on top of the base (black) layer - the grid layer
is dropped from the map:
  - yard tile across every square outside the building footprint
  - stone_floor tile across region 1 (room 1 interior)
Building squares not yet built stay black (base shows through).
The preview is written at normal full size only.

Usage:
  python3 mkplace.py --map maps/upper_level.ora \
      --tiles content/sites/g1/tiles --preview maps/upper_level_preview.png

Rects are the seated rulings; override via --building / --room1 if ever needed.
Pure stdlib.
"""
import argparse, os, struct, zipfile, zlib


def png_write(path, w, h, rows, color_type):
    def chunk(typ, data):
        c = struct.pack(">I", len(data)) + typ + data
        return c + struct.pack(">I", zlib.crc32(typ + data) & 0xFFFFFFFF)
    out = bytearray(b"\x89PNG\r\n\x1a\n")
    out += chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, color_type, 0, 0, 0))
    raw = b"".join(b"\x00" + r for r in rows)
    out += chunk(b"IDAT", zlib.compress(raw, 9))
    out += chunk(b"IEND", b"")
    with open(path, "wb") as f:
        f.write(out)


def png_decode(data):
    pos, idat, ihdr = 8, b"", None
    while pos < len(data):
        ln, typ = struct.unpack(">I4s", data[pos:pos+8])
        body = data[pos+8:pos+8+ln]
        if typ == b"IHDR": ihdr = struct.unpack(">IIBBBBB", body)
        elif typ == b"IDAT": idat += body
        pos += 12 + ln
    w, h, bd, ct = ihdr[:4]
    ch = 3 if ct == 2 else 4
    raw = zlib.decompress(idat); stride = w*ch
    rows = [raw[i+1:i+1+stride] for i in range(0, len(raw), stride+1)]
    return w, h, ch, rows


def parse_rect(s):
    xs, ys = s.split("x")
    x0, x1 = (int(v) for v in xs.split("-"))
    y0, y1 = (int(v) for v in ys.split("-"))
    return x0, x1, y0, y1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--map", default="maps/upper_level.ora")
    ap.add_argument("--tiles", default="content/sites/g1/tiles")
    ap.add_argument("--preview", default="")
    ap.add_argument("--building", default="10-40x10-49")
    ap.add_argument("--room1", default="20-31x45-49")
    args = ap.parse_args()

    z = zipfile.ZipFile(args.map)
    names = {n: z.read(n) for n in z.namelist()}
    bw, bh, bch, base = png_decode(names["data/000.png"])
    W, H = bw, bh
    # canvas squares from stack.xml? safer: derive from W with tile=64 fixed per doctrine
    TILE = 64
    COLS, ROWS = W // TILE, H // TILE

    stone = png_decode(open(os.path.join(args.tiles, "stone_floor.png"), "rb").read())
    yard = png_decode(open(os.path.join(args.tiles, "yard.png"), "rb").read())
    assert stone[0] == yard[0] == TILE, "tiles must be 64x64"

    bx0, bx1, by0, by1 = parse_rect(args.building)
    rx0, rx1, ry0, ry1 = parse_rect(args.room1)

    # floor layer: transparent RGBA, tiles blitted at square origins
    floor = [bytearray(W*4) for _ in range(H)]
    placed_yard = placed_stone = 0
    for c in range(COLS):
        for r in range(ROWS):
            in_building = bx0 <= c <= bx1 and by0 <= r <= by1
            in_room1 = rx0 <= c <= rx1 and ry0 <= r <= ry1
            if in_room1:
                tw, th, tch, trows = stone
                kind = "stone"
            elif not in_building:
                tw, th, tch, trows = yard
                kind = "yard"
            else:
                continue
            ox, oy = c*TILE, r*TILE
            for y in range(TILE):
                row = floor[oy+y]
                srow = trows[y]
                if tch == 3:
                    row[ox*4:(ox+TILE)*4] = b"".join(
                        bytes(srow[x*3:x*3+3]) + b"\xff" for x in range(TILE))
                else:
                    row[ox*4:(ox+TILE)*4] = b"".join(
                        bytes(srow[x*4:x*4+4]) for x in range(TILE))
            if kind == "yard": placed_yard += 1
            else: placed_stone += 1

    # merged: base, then floor (alpha over) - no grid layer
    merged = []
    for y in range(H):
        brow, frow = base[y], floor[y]
        line = bytearray(W*3)
        for x in range(W):
            r0, g0, b0 = brow[x*3], brow[x*3+1], brow[x*3+2]
            fa = frow[x*4+3]
            if fa:
                r0, g0, b0 = frow[x*4], frow[x*4+1], frow[x*4+2]
            line[x*3], line[x*3+1], line[x*3+2] = r0, g0, b0
        merged.append(bytes(line))

    out_tmp = args.map + ".tmpdir"
    os.makedirs(out_tmp + "/data", exist_ok=True)
    os.makedirs(out_tmp + "/Thumbnails", exist_ok=True)
    png_write(out_tmp + "/data/000.png", W, H, base, 2)          # base (unchanged)
    png_write(out_tmp + "/data/001.png", W, H, [bytes(r) for r in floor], 6)  # floor
    png_write(out_tmp + "/mergedimage.png", W, H, merged, 2)

    stack = (
        "<?xml version='1.0' encoding='UTF-8'?>\n"
        '<image version="0.0.3" w="%d" h="%d" xres="72" yres="72">\n'
        " <stack>\n"
        '  <layer name="base" src="data/000.png" x="0" y="0" opacity="1.0"'
        ' visibility="visible" composite-op="svg:src-over"/>\n'
        '  <layer name="floor" src="data/001.png" x="0" y="0" opacity="1.0"'
        ' visibility="visible" composite-op="svg:src-over"/>\n'
        " </stack>\n"
        "</image>\n" % (W, H)
    )
    with open(out_tmp + "/stack.xml", "w") as f:
        f.write(stack)

    # thumbnail: merged shrunk to 256 wide, nearest on boundaries
    tw = 256; th = round(H * tw / W)
    rows = []
    for y in range(th):
        sy = min(y*H//th, H-1)
        line = bytearray(tw*3)
        for x in range(tw):
            sx = min(x*W//tw, W-1)
            line[x*3:x*3+3] = merged[sy][sx*3:sx*3+3]
        rows.append(bytes(line))
    png_write(out_tmp + "/Thumbnails/thumbnail.png", tw, th, rows, 2)

    with open(args.map, "wb") as f:
        with zipfile.ZipFile(f, "w") as zo:
            zo.writestr(zipfile.ZipInfo("mimetype"), "image/openraster",
                        compress_type=zipfile.ZIP_STORED)
            for name in ("stack.xml", "data/000.png", "data/001.png",
                         "mergedimage.png", "Thumbnails/thumbnail.png"):
                zo.write(out_tmp + "/" + name, name)
    for root, _, files in os.walk(out_tmp, topdown=False):
        for fn in files:
            os.remove(os.path.join(root, fn))
        os.rmdir(root)

    if args.preview:
        os.makedirs(os.path.dirname(args.preview) or ".", exist_ok=True)
        png_write(args.preview, W, H, merged, 2)

    print("placed: %d yard squares, %d stone_floor squares (room 1)" %
          (placed_yard, placed_stone))
    print("wrote %s" % args.map)


if __name__ == "__main__":
    main()
