#!/usr/bin/env python3
"""mkmap.py - create the new-map ORA file with initial layers.

Canvas: --cols x --rows squares at --tile px each (default 51x60 @ 64px).
Initial layers (bottom to top):
  base : all black (no floor/ground placed yet)
  grid : 1px red lines at every square boundary
Also writes a merged preview PNG (--preview) for quick viewing.

Pure stdlib. OpenRaster (.ora) opens in Krita/GIMP with real layers.
"""
import argparse, os, struct, zipfile, zlib


def png_write(path, w, h, rows, color_type):
    # rows: list of bytes, each w*ch long (filter byte 0 prepended per row)
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


def make_base(w, h):
    return 2, [bytes([0, 0, 0]) * w for _ in range(h)]


def make_grid(w, h, tile):
    trans = bytes([0, 0, 0, 0])
    red = bytes([255, 0, 0, 255])
    xs = set(range(0, w + 1, tile)) | {w - 1}
    ys = set(range(0, h + 1, tile)) | {h - 1}
    rows = []
    for y in range(h):
        if y in ys:
            rows.append(red * w)
        else:
            rows.append(b"".join(red if x in xs else trans for x in range(w)))
    return 6, rows


def make_merged(w, h, tile):
    xs = set(range(0, w + 1, tile)) | {w - 1}
    ys = set(range(0, h + 1, tile)) | {h - 1}
    black, red = b"\x00\x00\x00", b"\xff\x00\x00"
    rows = []
    for y in range(h):
        if y in ys:
            rows.append(red * w)
        else:
            rows.append(b"".join(red if x in xs else black for x in range(w)))
    return 2, rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--cols", type=int, default=51)
    ap.add_argument("--rows", type=int, default=60)
    ap.add_argument("--tile", type=int, default=64)
    ap.add_argument("--out", default="maps/upper_level.ora")
    ap.add_argument("--preview", default="")
    ap.add_argument("--small", type=int, default=8,
                    help="px per square for the small moire-proof preview (0=off)")
    args = ap.parse_args()

    w, h = args.cols * args.tile, args.rows * args.tile
    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    tmp = args.out + ".tmpdir"
    os.makedirs(tmp + "/data", exist_ok=True)
    os.makedirs(tmp + "/Thumbnails", exist_ok=True)

    ct, rows = make_base(w, h)
    png_write(tmp + "/data/000.png", w, h, rows, ct)
    ct, rows = make_grid(w, h, args.tile)
    png_write(tmp + "/data/001.png", w, h, rows, ct)
    ct, rows = make_merged(w, h, args.tile)
    png_write(tmp + "/mergedimage.png", w, h, rows, ct)
    if args.preview:
        os.makedirs(os.path.dirname(args.preview) or ".", exist_ok=True)
        png_write(args.preview, w, h, rows, ct)
    if args.preview and args.small > 0:
        sp = os.path.splitext(args.preview)[0] + "_small.png"
        ct2, rows2 = make_merged(args.cols * args.small, args.rows * args.small, args.small)
        png_write(sp, args.cols * args.small, args.rows * args.small, rows2, ct2)
        print("wrote %s (%dx%d px, %dpx squares - moire-proof)" %
              (sp, args.cols * args.small, args.rows * args.small, args.small))

    stack = (
        "<?xml version='1.0' encoding='UTF-8'?>\n"
        '<image version="0.0.3" w="%d" h="%d" xres="72" yres="72">\n'
        " <stack>\n"
        '  <layer name="base" src="data/000.png" x="0" y="0" opacity="1.0"'
        ' visibility="visible" composite-op="svg:src-over"/>\n'
        '  <layer name="grid" src="data/001.png" x="0" y="0" opacity="1.0"'
        ' visibility="visible" composite-op="svg:src-over"/>\n'
        " </stack>\n"
        "</image>\n" % (w, h)
    )
    with open(tmp + "/stack.xml", "w") as f:
        f.write(stack)

    # thumbnail: merged shrunk to 256 wide, boundaries preserved
    tw = 256
    th = round(h * tw / w)
    xsp = set(min(round(k * tw / w), tw - 1) for k in range(0, w + 1, args.tile))
    ysp = set(min(round(k * th / h), th - 1) for k in range(0, h + 1, args.tile))
    rows = []
    for y in range(th):
        if y in ysp:
            rows.append(b"\xff\x00\x00" * tw)
        else:
            rows.append(b"".join(b"\xff\x00\x00" if x in xsp else b"\x00\x00\x00" for x in range(tw)))
    png_write(tmp + "/Thumbnails/thumbnail.png", tw, th, rows, 2)

    with open(args.out, "wb") as f:
        with zipfile.ZipFile(f, "w") as z:
            z.writestr(zipfile.ZipInfo("mimetype"), "image/openraster",
                       compress_type=zipfile.ZIP_STORED)
            for name in ("stack.xml", "data/000.png", "data/001.png",
                         "mergedimage.png", "Thumbnails/thumbnail.png"):
                z.write(tmp + "/" + name, name)

    for root, _, files in os.walk(tmp, topdown=False):
        for fn in files:
            os.remove(os.path.join(root, fn))
        os.rmdir(root)

    print("wrote %s (%dx%d px, %dx%d squares @ %dpx)" %
          (args.out, w, h, args.cols, args.rows, args.tile))
    if args.preview:
        print("wrote %s" % args.preview)


if __name__ == "__main__":
    main()
