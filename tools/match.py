#!/usr/bin/env python3
"""match.py - exemplar-based object proposals for mapbatch
extracts. Reads blob Hu moments / area / aspect / lattice
position from .extract.json files, matches each blob
against a hand-tagged exemplar file, writes proposals.
Deps: none (pure stdlib). Doctrine: PROPOSALS, never
decisions - identity stays with the eyes.
Usage: match.py EXEMPLARS.json EXTRACT.json [EXTRACT.json
  ...]; exemplars: {"label": ["map-stem:latx,laty",
  ...], ...}; out: <stem>.match.json per extract +
  stdout summary."""
import sys, os, json, math

EPS = 1e-30
# distance weights: shape vs size vs aspect
W_HU, W_A, W_S = 1.0, 0.5, 0.3
UNKNOWN = 0.45      # best distance above this = UNKNOWN
MARGIN = 0.25       # best-vs-second margin for confident
CONF_MAX = 0.30     # confident also needs absolute closeness:
                    # margin alone rewards far blobs that are
                    # merely more one-label-than-another


def loghu(hu):
    return [math.log(abs(v) + EPS) for v in hu]


def blob_dist(a, b):
    """Log-Hu shape distance + area/aspect agreement."""
    la, lb = loghu(a["hu"]), loghu(b["hu"])
    d = math.sqrt(sum((x - y) ** 2 for x, y in
                      zip(la, lb)) / len(la))
    da = abs(math.log(max(a["area"], 1) /
                      max(b["area"], 1)))
    ds = abs(math.log(max(a["aspect"], 0.05) /
                      max(b["aspect"], 0.05)))
    return W_HU * d + W_A * da + W_S * ds


def find_blob(blobs, lat, tol=0.4):
    """Blob whose lattice position is nearest lat."""
    best, bd = None, None
    for b in blobs:
        bx, by = b["lat"]
        d = math.hypot(bx - lat[0], by - lat[1])
        if bd is None or d < bd:
            best, bd = b, d
    if best is None or bd > tol:
        return None, bd
    return best, bd


def load_exemplars(path, blobmaps):
    """exemplars -> [(label, blob)] with lookup errors."""
    ex = json.load(open(path))
    out, errs = [], []
    for label, refs in sorted(ex.items()):
        for ref in refs:
            stem, lat = ref.split(":")
            lat = [float(v) for v in lat.split(",")]
            blobs = blobmaps.get(stem)
            if blobs is None:
                errs.append("%s: no extract loaded for "
                            "exemplar %s" % (label, ref))
                continue
            b, d = find_blob(blobs, lat)
            if b is None:
                errs.append("%s: no blob within %.2f of "
                            "%s (nearest %.2f)"
                            % (label, 0.4, ref,
                               d if d is not None else -1))
                continue
            out.append((label, b))
    return out, errs


def main():
    if len(sys.argv) < 3:
        sys.exit("match.py EXEMPLARS.json EXTRACT.json "
                 "[EXTRACT.json ...]")
    expath, stems = sys.argv[1], sys.argv[2:]
    blobmaps = {}
    for s in stems:
        d = json.load(open(s))
        stem = os.path.splitext(
            os.path.basename(s))[0]
        if stem.endswith(".extract"):
            stem = stem[:-8]
        blobmaps[stem] = d["blobs"]
    exemplars, errs = load_exemplars(expath, blobmaps)
    for e in errs:
        print("WARNING: " + e)
    if not exemplars:
        sys.exit("match: no usable exemplars")
    print("exemplars: %s" % ", ".join(
        "%s x%d" % (l, sum(1 for x, _ in exemplars
                           if x == l))
        for l in sorted(set(x for x, _ in exemplars))))
    for s in stems:
        d = json.load(open(s))
        blobs = d["blobs"]
        out = []
        for i, b in enumerate(blobs):
            scores = {}
            for label, ex in exemplars:
                dist = blob_dist(b, ex)
                if label not in scores or \
                        dist < scores[label]:
                    scores[label] = dist
            ranked = sorted(scores.items(),
                            key=lambda t: t[1])
            best, bd = ranked[0]
            md = (ranked[1][1] - bd) if len(ranked) > 1 \
                else 99.0
            prop = dict(i=i, px=b["px"], lat=b["lat"],
                        cls=b["cls"])
            if bd <= UNKNOWN:
                prop["proposal"] = best
                prop["dist"] = round(bd, 3)
                prop["margin"] = round(min(md, 99.0), 3)
                prop["confident"] = bool(
                    md >= MARGIN and bd <= CONF_MAX)
            else:
                prop["proposal"] = "UNKNOWN"
                prop["dist"] = round(bd, 3)
            out.append(prop)
        tally = {}
        for p in out:
            tally[p["proposal"]] = tally.get(
                p["proposal"], 0) + 1
        conf = sum(1 for p in out
                   if p.get("confident"))
        op = os.path.splitext(s)[0]
        if op.endswith(".extract"):
            op = op[:-8]
        op += ".match.json"
        json.dump(out, open(op, "w"), indent=1)
        print("%s: %d blobs -> %s (%d confident)"
              % (os.path.basename(s), len(out),
                 ", ".join("%s=%d" % kv
                            for kv in sorted(
                                tally.items())), conf))


if __name__ == "__main__":
    main()

