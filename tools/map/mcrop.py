#!/usr/bin/env python3
"""mcrop.py - crop the raster to a bbox region and save
it as an image (numeral-first rebuild, v0.1).

Takes the same --bbox X1,X2,Y1,Y2 lattice lines as
mroom (his coordinates, AS-IS, no transform) and
crops the raster to exactly that region - so the
region can be adjudicated by eyes on real pixels,
with nothing outside the box in frame.

Optional --grid overlays the lattice lines with
labels, so every feature in the crop can be located
in his frame at a glance.

Usage:
    python3 tools/map/mcrop.py <image> --bbox 9,22,35,42
    python3 tools/map/mcrop.py <image> --bbox 9,22,35,42 \\
        --grid --scale 2 --out room1.png

Constants copied from hallscan (his fit_lattice
fit); override with --x0/--xpitch/--y0/--ypitch."""
import argparse

X0, XPITCH = 181.95, 64.2742   # X(k) = X0 + XPITCH*k
Y0, YPITCH = 482.00, 64.5875   # Y(k) = Y0 + YPITCH*k


def px(x0, xp, k):
    return x0 + xp * k


def main():
    ap = argparse.ArgumentParser(description=(
        "crop the raster to a bbox region "
        "(same --bbox as mroom) and save it"))
    ap.add_argument("image")
    ap.add_argument("--bbox", required=True,
                    help="X1,X2,Y1,Y2 lattice lines, "
                         "his coordinates AS-IS")
    ap.add_argument("--out", default=None,
                    help="output path (default: "
                         "crop_<bbox>.png)")
    ap.add_argument("--margin", type=int, default=8,
                    help="extra pixels around the "
                         "crop (default 8)")
    ap.add_argument("--scale", type=int, default=1,
                    help="upscale factor "
                         "(default 1)")
    ap.add_argument("--grid", action="store_true",
                    help="overlay lattice lines "
                         "with line labels")
    ap.add_argument("--x0", type=float, default=X0)
    ap.add_argument("--xpitch", type=float,
                    default=XPITCH)
    ap.add_argument("--y0", type=float, default=Y0)
    ap.add_argument("--ypitch", type=float,
                    default=YPITCH)
    a = ap.parse_args()

    x1, x2, y1, y2 = (int(v) for v in
                      a.bbox.split(","))
    if not (x1 < x2 and y1 < y2):
        ap.error("bbox needs X1<X2 and Y1<Y2")

    left = int(round(px(a.x0, a.xpitch, x1))) \
        - a.margin
    right = int(round(px(a.x0, a.xpitch, x2))) \
        + a.margin
    top = int(round(px(a.y0, a.ypitch, y1))) \
        - a.margin
    bottom = int(round(px(a.y0, a.ypitch, y2))) \
        + a.margin

    from PIL import Image, ImageDraw
    img = Image.open(a.image).convert("RGB")
    if right <= left or bottom <= top or \
            left < 0 or top < 0 or \
            right > img.size[0] or \
            bottom > img.size[1]:
        print("image %dx%d; crop rect (%d,%d)-"
              "(%d,%d) out of range"
              % (img.size[0], img.size[1],
                 left, top, right, bottom))
        raise SystemExit(1)
    crop = img.crop((left, top, right, bottom))

    if a.grid:
        d = ImageDraw.Draw(crop)
        for k in range(x1, x2 + 1):
            gx = int(round(
                px(a.x0, a.xpitch, k))) - left
            d.line([(gx, 0),
                    (gx, crop.size[1] - 1)],
                   fill=(255, 0, 0), width=1)
            d.text((gx + 2, 2), "X%d" % k,
                   fill=(255, 0, 0))
        for k in range(y1, y2 + 1):
            gy = int(round(
                px(a.y0, a.ypitch, k))) - top
            d.line([(0, gy),
                    (crop.size[0] - 1, gy)],
                   fill=(255, 0, 0), width=1)
            d.text((2, gy + 2), "Y%d" % k,
                   fill=(255, 0, 0))

    if a.scale > 1:
        crop = crop.resize(
            (crop.size[0] * a.scale,
             crop.size[1] * a.scale),
            Image.NEAREST)

    out = a.out or ("crop_%s.png"
                    % a.bbox.replace(",", "-"))
    crop.save(out)
    print("saved %s  %dx%d px  bbox X%d..X%d "
          "x Y%d..Y%d  margin %d  scale %d"
          % (out, crop.size[0], crop.size[1],
             x1, x2, y1, y2, a.margin, a.scale))


if __name__ == "__main__":
    main()
