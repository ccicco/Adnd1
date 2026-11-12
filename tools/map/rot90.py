#!/usr/bin/env python3
"""rot90.py - exact 90-degree CCW rotation of a seamlock-baked 64x64 RGB PNG.
Pure stdlib. No resampling: pixels transpose+flip exactly. Gate-safe: a tile
that passed both axes passes with the numbers swapped after rotation."""
import sys, zlib, struct

def read_png(path):
    d = open(path, "rb").read()
    assert d[:8] == b"\x89PNG\r\n\x1a\n", "not a PNG"
    pos, idat, w, h = 8, b"", None, None
    while pos < len(d):
        ln, typ = struct.unpack(">I4s", d[pos:pos+8]); pos += 8
        data = d[pos:pos+ln]; pos += ln + 4
        if typ == b"IHDR":
            w, h, bd, ct = struct.unpack(">IIBB", data[:10]); assert bd == 8 and ct == 2
        elif typ == b"IDAT":
            idat += data
    raw = zlib.decompress(idat)
    rows = [raw[i*(w*3+1):(i+1)*(w*3+1)] for i in range(h)]
    assert all(r[0] == 0 for r in rows), "unexpected filters"
    return w, h, [bytes(r[1:]) for r in rows]

def write_png(path, rows, w, h):
    def chunk(t, data):
        c = t + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c))
    raw = b"".join(b"\x00" + r for r in rows)
    png = (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
           + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))
    open(path, "wb").write(png)

def rot90(rows, w, h):
    out = []
    for y in range(w):
        row = bytearray()
        for x in range(h):
            sx, sy = y, h - 1 - x
            row += rows[sy][sx*3:sx*3+3]
        out.append(bytes(row))
    return out, h, w

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit("usage: rot90.py IN.png OUT.png")
    w, h, rows = read_png(sys.argv[1])
    out, nw, nh = rot90(rows, w, h)
    write_png(sys.argv[2], out, nw, nh)
    print("rotated %dx%d -> %dx%d" % (w, h, nw, nh))
