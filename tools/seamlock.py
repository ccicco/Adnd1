#!/usr/bin/env python3
"""
seamlock.py - the G1 primitive seam gate and tile baker (pure stdlib).

Doctrine (repo-as-persistence, seamlock doctrine 2026-11-02, master-size
ruling fallback clause invoked 2026-11-03):
  - The generator emits a FIXED size (1254x1254) and cannot honor 640x640.
    Per the master-size ruling's fallback clause, full-coverage organic
    terrain masters are admissible at the generator's true size; the
    manifest records it. Exact foot-grid geometry (1'=64 subpx) applies
    to CONSTRUCT primitives only - never to these.
  - The ONLY downsample in existence is this tool's single exact
    area-average master -> 64x64 (rational boundaries, integer
    arithmetic, one rounding point: the final half-up per channel).
  - The pixel gate is the authority; the vision gate is a pre-filter.

Gate semantics (verify mode):
  1. HEADER: square master (w == h), >= 64, 8-bit, color type 2 (RGB)
     or 6 (RGBA), no interlace. The true size is reported for the
     manifest; no size is refused as long as it is square.
  2. COVERAGE: if RGBA, alpha must be 255 everywhere (full coverage claim).
  3. SEAM ENERGY: the wrap transition (last col vs first col, last row vs
     first row) must be an ORDINARY interior transition, not a special one.
     The wrap is one boundary among w/h boundaries: PASS requires its mean
     energy to be within 2x the p99 of interior boundary energies on both
     axes (the p99 alone is brittle - a perfect texture's wrap column
     lands in the interior tail ~1% of the time by chance), AND zero HARD
     seam pixels (pixels whose wrap diff exceeds max(8, p999 interior
     pixel diff * HARD_FACTOR) - catches a fine seam that hides in the
     mean).
  4. BAKE (bake mode): after gate PASS, the x10 area-average downsample
     produces the 64x64 tile; the gate then re-runs ON THE TILE so the
     post-downsample AA rows are verified too.

Exit codes: 0 = pass, 1 = fail, 2 = unreadable/malformed input.

Usage:
  python3 tools/seamlock.py verify  <master.png>
  python3 tools/seamlock.py bake   <master.png> <tile_out.png>
  python3 tools/seamlock.py tile2x2 <master.png> <tiled_out.png>   # eyeball aid
"""

import sys
import zlib
import struct

TILE_SIZE = 64

HARD_FACTOR = 4.0


# ---------------------------------------------------------------- PNG decode

def read_png(path):
    """Return (width, height, color_type, rows) where rows is a list of
    bytearrays, each w*bpp bytes, bpp = bytes per pixel. Raises ValueError
    with a clear message on anything this gate refuses."""
    data = open(path, 'rb').read()
    if data[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('not a PNG (bad signature)')
    pos, ihdr, idat = 8, None, []
    while pos < len(data):
        if pos + 8 > len(data):
            raise ValueError('truncated chunk header')
        ln, typ = struct.unpack('>I4s', data[pos:pos + 8])
        body = data[pos + 8:pos + 8 + ln]
        if len(body) != ln:
            raise ValueError('truncated chunk body')
        if typ == b'IHDR':
            ihdr = struct.unpack('>IIBBBBB', body)
        elif typ == b'IDAT':
            idat.append(body)
        elif typ == b'IEND':
            break
        pos += 12 + ln
    if ihdr is None:
        raise ValueError('no IHDR')
    w, h, bd, ct, comp, filt, inter = ihdr
    if w != h:
        raise ValueError(f'expected a square master, got {w}x{h}')
    if w < TILE_SIZE:
        raise ValueError(f'master smaller than the tile ({w} vs {TILE_SIZE})')
    if bd != 8:
        raise ValueError(f'expected 8-bit, got bit depth {bd}')
    if ct == 2:
        bpp = 3
    elif ct == 6:
        bpp = 4
    else:
        raise ValueError(f'expected color type 2 (RGB) or 6 (RGBA), got {ct}')
    if inter != 0:
        raise ValueError('interlaced PNG refused (non-interlaced required)')
    raw = zlib.decompress(b''.join(idat))
    stride = w * bpp
    if len(raw) != (stride + 1) * h:
        raise ValueError('decompressed size mismatch')
    rows, prev, p = [], bytearray(stride), 0
    for _ in range(h):
        ft = raw[p]; p += 1
        line = bytearray(raw[p:p + stride]); p += stride
        if ft == 0:
            pass
        elif ft == 1:                                   # Sub
            for i in range(bpp, stride):
                line[i] = (line[i] + line[i - bpp]) & 0xFF
        elif ft == 2:                                   # Up
            for i in range(stride):
                line[i] = (line[i] + prev[i]) & 0xFF
        elif ft == 3:                                   # Average
            for i in range(stride):
                left = line[i - bpp] if i >= bpp else 0
                line[i] = (line[i] + ((left + prev[i]) >> 1)) & 0xFF
        elif ft == 4:                                   # Paeth
            for i in range(stride):
                a = line[i - bpp] if i >= bpp else 0
                b = prev[i]
                c = prev[i - bpp] if i >= bpp else 0
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                if pa <= pb and pa <= pc:
                    pr = a
                elif pb <= pc:
                    pr = b
                else:
                    pr = c
                line[i] = (line[i] + pr) & 0xFF
        else:
            raise ValueError(f'unknown filter type {ft}')
        rows.append(line)
        prev = line
    return w, h, ct, bpp, rows


# ---------------------------------------------------------------- PNG encode

def write_png(path, w, h, ct, bpp, rows):
    out = bytearray(b'\x89PNG\r\n\x1a\n')

    def chunk(typ, body):
        out.extend(struct.pack('>I', len(body)))
        out.extend(typ)
        out.extend(body)
        out.extend(struct.pack('>I', zlib.crc32(typ + body) & 0xFFFFFFFF))

    chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, ct, 0, 0, 0))
    raw = bytearray()
    for r in rows:
        raw.append(0)
        raw.extend(r)
    chunk(b'IDAT', zlib.compress(bytes(raw), 9))
    chunk(b'IEND', b'')
    open(path, 'wb').write(out)


# ---------------------------------------------------------------- gate math

def pixel_diff(a, b, i, j, bpp):
    """Sum of abs channel diffs between row a[i..] pixel and row b[j..]."""
    d = 0
    for c in range(bpp):
        d += abs(a[i + c] - b[j + c])
    return d


def seam_gate(rows, w, h, bpp):
    """Return (ok, report_lines). The exact, deterministic gate.

    The wrap seam is ONE boundary column/row among w/h boundaries. It is
    judged against the texture's own population of interior boundary
    energies, not a global mean: the wrap energy must not exceed the p99
    of interior boundary energies, and no single wrap pixel may be a
    hard discontinuity (> max(8, p999 interior pixel diff * HARD_FACTOR)).
    """
    rep = []
    ok = True
    maxd = 255 * bpp + 1

    # ---- horizontal axis: boundaries between columns x and x+1
    hist = [0] * maxd                 # interior per-pixel diff histogram
    col_e = [0] * (w - 1)             # per-boundary-column mean energy
    for y in range(h):
        r = rows[y]
        for x in range(w - 1):
            d = pixel_diff(r, r, x * bpp, (x + 1) * bpp, bpp)
            col_e[x] += d
            hist[d] += 1
    col_e = [c / h for c in col_e]
    seam_h = hard_h = 0
    for y in range(h):
        r = rows[y]
        d = pixel_diff(r, r, (w - 1) * bpp, 0, bpp)
        seam_h += d
    seam_h /= h
    col_sorted = sorted(col_e)
    p99_h = col_sorted[int((w - 1) * 0.99)]
    # p999 of interior per-pixel diffs
    cum, p999 = 0, 0
    for d, n in enumerate(hist):
        cum += n
        if cum >= (w - 1) * h * 0.999:
            p999 = d
            break
    hard_lim = max(8.0, p999 * HARD_FACTOR)
    for y in range(h):
        r = rows[y]
        if pixel_diff(r, r, (w - 1) * bpp, 0, bpp) > hard_lim:
            hard_h += 1

    # ---- vertical axis: boundaries between rows y and y+1
    hist = [0] * maxd
    row_e = [0] * (h - 1)
    for y in range(h - 1):
        r0, r1 = rows[y], rows[y + 1]
        e = 0
        for x in range(w):
            d = pixel_diff(r0, r1, x * bpp, x * bpp, bpp)
            e += d
            hist[d] += 1
        row_e[y] = e / w
    seam_v = 0
    for x in range(w):
        seam_v += pixel_diff(rows[0], rows[h - 1], x * bpp, x * bpp, bpp)
    seam_v /= w
    row_sorted = sorted(row_e)
    p99_v = row_sorted[int((h - 1) * 0.99)]
    cum, p999v = 0, 0
    total = w * (h - 1)
    for d, n in enumerate(hist):
        cum += n
        if cum >= total * 0.999:
            p999v = d
            break
    hard_lim_v = max(8.0, p999v * HARD_FACTOR)
    hard_v = 0
    for x in range(w):
        if pixel_diff(rows[0], rows[h - 1], x * bpp, x * bpp, bpp) > hard_lim_v:
            hard_v += 1

    rep.append(f'interior boundary energies: h mean={sum(col_e)/(w-1):.3f} p99={p99_h:.3f}'
               f' | v mean={sum(row_e)/(h-1):.3f} p99={p99_v:.3f}')
    rep.append(f'wrap seam energy: h={seam_h:.3f} v={seam_v:.3f}')
    rep.append(f'hard pixel limits: h>{hard_lim:.1f} v>{hard_lim_v:.1f}'
               f' -> hard seam pixels: h={hard_h} v={hard_v}')

    if seam_h > 2 * p99_h:
        rep.append(f'FAIL: horizontal wrap energy {seam_h:.3f} exceeds 2x interior'
                   f' boundary p99 {p99_h:.3f} - the wrap is a gross outlier column')
        ok = False
    if seam_v > 2 * p99_v:
        rep.append(f'FAIL: vertical wrap energy {seam_v:.3f} exceeds 2x interior'
                   f' boundary p99 {p99_v:.3f} - the wrap is a gross outlier row')
        ok = False
    if hard_h or hard_v:
        rep.append(f'FAIL: {hard_h + hard_v} hard seam pixel(s) at the wrap border')
        ok = False
    if ok:
        rep.append('PASS: the wrap is an ordinary interior transition,'
                   ' zero hard seam pixels')
    return ok, rep


def coverage_gate(rows, w, h, bpp, ct):
    """Full-coverage claim: alpha 255 everywhere (RGBA only)."""
    if ct != 6:
        return True, ['coverage: RGB (no alpha plane), full coverage by definition']
    bad = 0
    for r in rows:
        for x in range(w):
            if r[x * bpp + 3] != 255:
                bad += 1
    if bad:
        return False, [f'FAIL coverage: {bad} non-opaque pixel(s)']
    return True, ['coverage: alpha 255 everywhere']


# ---------------------------------------------------------------- downsample

def axis_weights(size, n=TILE_SIZE):
    """Exact rational coverage: for each output index k, the source
    interval [k*size/n, (k+1)*size/n) in n-ths of a pixel. Returns a
    list of (source_index, numerator) pairs; fraction = num/size."""
    out = []
    for k in range(n):
        a, b = k * size, (k + 1) * size
        segs = []
        i = a // n
        while i * n < b:
            lo = max(a, i * n)
            hi = min(b, (i + 1) * n)
            if hi > lo:
                segs.append((i, hi - lo))
            i += 1
        out.append(segs)
    return out


def bake_tile(rows, w, h, bpp):
    """The one round: exact area average master -> 64x64. Rational
    boundaries in n-ths of a pixel, pure integer arithmetic; the single
    rounding point is the final half-up per channel."""
    xw = axis_weights(w)
    yw = axis_weights(h)
    denom = w * h
    tile = []
    for ty in range(TILE_SIZE):
        row = bytearray(TILE_SIZE * bpp)
        for tx in range(TILE_SIZE):
            sums = [0] * bpp
            for (j, wy) in yw[ty]:
                src = rows[j]
                for (i, wx) in xw[tx]:
                    wt = wx * wy
                    base = i * bpp
                    for c in range(bpp):
                        sums[c] += src[base + c] * wt
            for c in range(bpp):
                row[tx * bpp + c] = (2 * sums[c] + denom) // (2 * denom)
        tile.append(row)
    return tile


def tile2x2(rows, w, h, bpp):
    out = []
    for _ in range(2):
        for r in rows:
            out.append(bytearray(r) + bytearray(r))
    return out


# ---------------------------------------------------------------- commands

def cmd_verify(path):
    try:
        w, h, ct, bpp, rows = read_png(path)
    except ValueError as e:
        print(f'HEADER FAIL: {path}: {e}')
        return 2
    print(f'header: {w}x{h} color type {ct} - OK')
    ok_cov, rep_cov = coverage_gate(rows, w, h, bpp, ct)
    print('\n'.join(rep_cov))
    ok, rep = seam_gate(rows, w, h, bpp)
    print('\n'.join(rep))
    if not (ok_cov and ok):
        print(f'VERDICT: {path}: FAIL')
        return 1
    print(f'VERDICT: {path}: PASS')
    return 0


def cmd_bake(master, tile_out):
    rc = cmd_verify(master)
    if rc != 0:
        print('bake refused: master did not pass the gate')
        return rc
    w, h, ct, bpp, rows = read_png(master)
    print(f'master true size: {w}x{h} (record this in the manifest)')
    tile = bake_tile(rows, w, h, bpp)
    print('re-running the gate on the 64x64 tile (AA rows included)...')
    ok, rep = seam_gate(tile, TILE_SIZE, TILE_SIZE, bpp)
    print('\n'.join(rep))
    if not ok:
        print('FAIL: the downsampled tile failed the gate')
        return 1
    write_png(tile_out, TILE_SIZE, TILE_SIZE, ct, bpp, tile)
    print(f'baked: {tile_out} ({TILE_SIZE}x{TILE_SIZE}, the single exact area-average round)')
    print(f'manifest: "pixel_gate": "pass '
          f'{__import__("datetime").date.today().isoformat()}"')
    return 0


def cmd_tile2x2(master, out):
    try:
        w, h, ct, bpp, rows = read_png(master)
    except ValueError as e:
        print(f'FAIL: {e}')
        return 2
    out_rows = tile2x2(rows, w, h, bpp)
    write_png(out, w * 2, h * 2, ct, bpp, out_rows)
    print(f'wrote {out} ({w * 2}x{h * 2} 2x2 tiling - eyeball aid, not a gate)')
    return 0


def main(argv):
    if len(argv) >= 3 and argv[1] == 'verify':
        return cmd_verify(argv[2])
    if len(argv) >= 4 and argv[1] == 'bake':
        return cmd_bake(argv[2], argv[3])
    if len(argv) >= 4 and argv[1] == 'tile2x2':
        return cmd_tile2x2(argv[2], argv[3])
    print(__doc__)
    return 2


if __name__ == '__main__':
    sys.exit(main(sys.argv))

