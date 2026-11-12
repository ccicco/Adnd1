#!/usr/bin/env python3
"""mapp.py - mapp's trainable shape-family recognizer
(match2-spec v0.1). Reads blobs from .extract.json files,
clusters them into per-map shape families, matches families
against a persistent library (library.json), labels only
what passes the certainty bar, surfaces UNKNOWN families
as an ask-list, and learns from answered questions.
Doctrine (app-doctrine): proposals, never decisions; margin
never grants confidence alone; every answer is a training
event with provenance.
Usage:
  mapp.py LIB.json A.extract.json [B...] [--ask]
  mapp.py --learn ANSWERS.json [--lib LIB.json]
  mapp.py --teach "x,y:label[;x,y:label...]"
           A.extract.json [--lib LIB.json]
  mapp.py --around "x,y" A.extract.json
  mapp.py --rename "OLD:NEW" [--lib LIB.json]
  mapp.py --import extract/g1/exemplars.json A.extract.json [B...]
           [--lib LIB.json]
Exemplars (legacy): {"label": ["stem:latx,laty", ...]}.
Answers file = the .ask.json rows with "label" added."""
import sys, os, json, math, argparse, datetime

EPS = 1e-30
# distance weights: shape vs size vs aspect (v1 lineage)
W_HU, W_A, W_S = 1.0, 0.5, 0.3
# family cut = Q1 of nearest-neighbor distances * FAM_FACTOR,
# clamped to [FAM_MIN, FAM_MAX] (safety rails, per spec)
FAM_FACTOR, FAM_MIN, FAM_MAX = 4.0, 0.05, 1.2
# certainty bar per label = BAR_Q quantile of within-label
# nearest-neighbor distances among entries, clamped
BAR_Q, BAR_FLOOR, BAR_CAP = 0.9, 0.30, 0.90
# proposal bar = certainty bar * PROP_MULT
PROP_MULT = 2.0
# member agreement floor (v1.2 law: never label on one odd
# blob's say-so)
AGREE_MIN = 2.0 / 3.0
# legacy exemplar position tolerance, lattice units
EX_TOL = 0.4


def loghu(hu):
    return [math.log(abs(v) + EPS) for v in hu]


def sig_dist(a, b):
    """Distance between two blob signatures (hu/area/
    aspect dicts), log-space, v1 metric."""
    la, lb = loghu(a["hu"]), loghu(b["hu"])
    d = math.sqrt(sum((x - y) ** 2 for x, y in
                      zip(la, lb)) / len(la))
    da = abs(math.log(max(a["area"], 1) /
                      max(b["area"], 1)))
    ds = abs(math.log(max(a["aspect"], 0.05) /
                      max(b["aspect"], 0.05)))
    return W_HU * d + W_A * da + W_S * ds


def quantile(vals, q):
    """Linear-interpolated quantile of a plain list."""
    if not vals:
        return None
    s = sorted(vals)
    if len(s) == 1:
        return s[0]
    t = q * (len(s) - 1)
    lo = int(math.floor(t))
    hi = min(lo + 1, len(s) - 1)
    return s[lo] + (s[hi] - s[lo]) * (t - lo)


def clamp(v, lo, hi):
    return max(lo, min(hi, v))


def load_extract(path):
    d = json.load(open(path))
    stem = os.path.splitext(os.path.basename(path))[0]
    if stem.endswith(".extract"):
        stem = stem[:-8]
    return stem, d["blobs"]


def fam_cut(blobs):
    """Single-linkage cut from the blob population."""
    n = len(blobs)
    if n < 2:
        return FAM_MIN
    nn = []
    for i, a in enumerate(blobs):
        best = None
        for j, b in enumerate(blobs):
            if i == j:
                continue
            d = sig_dist(a, b)
            if best is None or d < best:
                best = d
        nn.append(best)
    return clamp(quantile(nn, 0.25) * FAM_FACTOR,
                 FAM_MIN, FAM_MAX)


def cluster(blobs, cut):
    """Average-linkage clustering at cut. Sorted-edge
    agglomeration: a merge is accepted only if the MEAN
    pairwise distance across the two clusters stays within
    cut - single-linkage chaining (one lucky edge) cannot
    hang junk onto a clean family (v2.2 fix). Returns
    index lists, biggest first, then by first index."""
    n = len(blobs)
    members = {i: [i] for i in range(n)}
    root = list(range(n))
    cache = {}

    def pd(x, y):
        k = (x, y) if x < y else (y, x)
        if k not in cache:
            cache[k] = sig_dist(blobs[k[0]],
                                blobs[k[1]])
        return cache[k]

    edges = []
    for i in range(n):
        for j in range(i + 1, n):
            d = pd(i, j)
            if d <= cut:
                edges.append((d, i, j))
    edges.sort()
    for d, i, j in edges:
        ri, rj = root[i], root[j]
        if ri == rj:
            continue
        a, b = members[ri], members[rj]
        cross = [pd(x, y) for x in a for y in b]
        if sum(cross) / len(cross) > cut:
            continue
        if len(b) > len(a):
            ri, rj = rj, ri
            a, b = b, a
        a.extend(b)
        for x in b:
            root[x] = ri
        del members[rj]
    fams = sorted(members.values(),
                  key=lambda g: (-len(g), g[0]))
    return fams
    fams = sorted(groups.values(),
                  key=lambda g: (-len(g), g[0]))
    return fams


def label_bars(lib):
    """Certainty bar per label from within-label nearest-
    neighbor spread; floor governs while small."""
    bars = {}
    for label, ent in sorted(lib.items()):
        nn = []
        for i, a in enumerate(ent["entries"]):
            ds = [sig_dist(a, b)
                  for j, b in enumerate(ent["entries"])
                  if j != i]
            if ds:
                nn.append(min(ds))
        if nn:
            bars[label] = clamp(quantile(nn, BAR_Q),
                                BAR_FLOOR, BAR_CAP)
        else:
            bars[label] = BAR_FLOOR
    return bars


def fam_scores(members, blobs, lib):
    """Family-vs-label distances + member agreement."""
    per = {}
    for label in lib:
        dists = []
        for m in members:
            d = min(sig_dist(blobs[m], e)
                    for e in lib[label]["entries"])
            dists.append(d)
        dists.sort()
        per[label] = dists[len(dists) // 2]
    ranked = sorted(per.items(), key=lambda t: t[1])
    best, bd = ranked[0] if ranked else (None, None)
    md = (ranked[1][1] - bd) if len(ranked) > 1 else 99.0
    if best is None:
        return None, None, md, 0.0
    agree = 0.0
    for m in members:
        own = min(((sig_dist(blobs[m], e), lab)
                   for lab in lib
                   for e in lib[lab]["entries"]))
        if own[1] == best:
            agree += 1.0
    return best, bd, md, agree / len(members)


def ask_rows(stem, fams, blobs, judged):
    """UNKNOWN-family and non-confident ask-list rows."""
    rows = []
    for fid, (members, kind, best, bd, why) \
            in enumerate(judged):
        if kind in ("confident", "anchored"):
            continue
        r = max(members, key=lambda m: blobs[m]["area"])
        rows.append({
            "q": fid, "map": stem, "family": fid,
            "kind": kind, "best": best,
            "dist": round(bd, 3) if bd is not None
            else None, "why": why,
            "rep": {
                "px": blobs[r]["px"],
                "lat": blobs[r]["lat"],
                "cls": blobs[r]["cls"],
                "hu": blobs[r]["hu"],
                "area": blobs[r]["area"],
                "aspect": blobs[r]["aspect"],
            }})
    return rows


def member_own(m, blobs, lib):
    """Member's own nearest label, its distance, and the
    margin to the runner-up label (v2.4 anchoring)."""
    ranked = sorted(
        (min(sig_dist(blobs[m], e)
             for e in lib[lab]["entries"]), lab)
        for lab in lib)
    d, lab = ranked[0]
    md = (ranked[1][0] - d) if len(ranked) > 1 \
        else 99.0
    return d, lab, md


def match_extract(stem, blobs, lib, ask,
                 outdir=''):
    bars = label_bars(lib)
    cut = fam_cut(blobs)
    fams = cluster(blobs, cut)
    out, judged = [], []
    tally = {}
    out, judged = [], []
    tally = {}
    for fid, members in enumerate(fams):
        own = {}
        for m in members:
            if lib:
                d, lab, md = member_own(m, blobs,
                                       lib)
                own[m] = (d, lab, md,
                          d <= bars[lab])
        unanch = [m for m in members
                  if not own.get(
                      m, (0, None, 0, False))[3]]
        best, bd, fmd, agree = fam_scores(
            members, blobs, lib)
        if not unanch:
            kind, why = "anchored", "all-seated"
        elif best is None:
            kind, why = "unknown", "empty-library"
        elif bd <= bars[best] and \
                agree >= AGREE_MIN:
            kind, why = "confident", "bar+agreement"
        elif bd <= bars[best] * PROP_MULT:
            kind, why = "proposal", "propose-bar"
        else:
            kind, why = "unknown", "beyond-bars"
        judged.append((members, kind, best, bd, why))
        for m in members:
            if m in own and own[m][3]:
                row = dict(i=m, px=blobs[m]["px"],
                           lat=blobs[m]["lat"],
                           cls=blobs[m]["cls"],
                           family=fid,
                           proposal=own[m][1],
                           dist=round(own[m][0], 3),
                           margin=round(own[m][2],
                                        3),
                           confident=True,
                           kind="anchored")
            else:
                d = None
                if best is not None:
                    d = min(sig_dist(blobs[m], e)
                            for e in
                            lib[best]["entries"])
                row = dict(i=m,
                           px=blobs[m]["px"],
                           lat=blobs[m]["lat"],
                           cls=blobs[m]["cls"],
                           family=fid,
                           proposal=best if kind !=
                           "unknown" else "UNKNOWN",
                           dist=round(d, 3)
                           if d is not None
                           else None,
                           margin=round(fmd, 3),
                           confident=(kind ==
                                      "confident"),
                           kind=kind)
            tally.setdefault(
                (row["kind"], row["proposal"]), 0)
            tally[(row["kind"],
                   row["proposal"])] += 1
            out.append(row)
    op = os.path.join(outdir,
                     stem + ".match.json")
    json.dump(out, open(op, "w"), indent=1)
    rows = ask_rows(stem, fams, blobs, judged)
    nconf = sum(1 for p in out if p["confident"])
    print("%s: %d blobs, %d families (cut %.3f) -> "
          "%d confident, %d in families, %d to ask"
          % (stem, len(blobs), len(fams), cut, nconf,
             len(out), len(rows)))
    for (kind, lab), cnt in sorted(
            tally.items(), key=str):
        print("  %-9s %-10s %d" % (kind, lab, cnt))
    if ask:
        ap = os.path.join(outdir,
                         stem + ".ask.json")
        json.dump(rows, open(ap, "w"), indent=1)
        print("ask-list: %d questions -> %s"
              % (len(rows), ap))
        for r in rows:
            print("  q%d family %d %s best=%s d=%s "
                  "rep lat=(%.1f,%.1f) area=%d"
                  % (r["q"], r["family"], r["kind"],
                     r["best"], r["dist"],
                     r["rep"]["lat"][0],
                     r["rep"]["lat"][1],
                     r["rep"]["area"]))
    return rows


def entry_of(stem, blob, source):
    return {"map": stem,
            "lat": blob["lat"], "px": blob["px"],
            "hu": blob["hu"], "area": blob["area"],
            "aspect": blob["aspect"],
            "learned": datetime.date.today().isoformat(),
            "source": source}


def add_entry(lib, label, ent):
    lib.setdefault(label, {
        "description": label,
        "entries": []})
    seen = {(e["map"], tuple(round(v, 2)
            for v in e["lat"]))
            for e in lib[label]["entries"]}
    key = (ent["map"], tuple(round(v, 2)
            for v in ent["lat"]))
    if key not in seen:
        lib[label]["entries"].append(ent)
        return True
    return False


def cmd_import(expath, extracts, libpath):
    ex = json.load(open(expath))
    blobmaps = {}
    for s in extracts:
        stem, blobs = load_extract(s)
        blobmaps[stem] = blobs
    lib = json.load(open(libpath)) if (
        os.path.exists(libpath)) else {}
    n, miss = 0, 0
    for label, refs in sorted(ex.items()):
        for ref in refs:
            stem, lat = ref.split(":")
            lat = [float(v) for v in lat.split(",")]
            blobs = blobmaps.get(stem)
            if blobs is None:
                print("WARNING: no extract for %s" % ref)
                miss += 1
                continue
            best, bd = None, None
            for b in blobs:
                d = math.hypot(b["lat"][0] - lat[0],
                               b["lat"][1] - lat[1])
                if bd is None or d < bd:
                    best, bd = b, d
            if best is None or bd > EX_TOL:
                print("WARNING: no blob within %.2f of "
                      "%s (nearest %.2f)"
                      % (EX_TOL, ref,
                         bd if bd is not None else -1))
                miss += 1
                continue
            n += add_entry(lib, label,
                           entry_of(stem, best,
                                    "legacy-"
                                    "import"))
    save_lib(lib, libpath)
    print("import: %d entries added, %d missed -> %s"
          % (n, miss, libpath))


def save_lib(lib, libpath):
    lib = {k: {"description": v["description"],
               "entries": sorted(
                   v["entries"],
                   key=lambda e: (e["map"],
                                  e["lat"][0],
                                  e["lat"][1]))}
           for k, v in sorted(lib.items())}
    json.dump(lib, open(libpath, "w"), indent=1)


def cmd_learn(anspath, libpath):
    rows = json.load(open(anspath))
    lib = json.load(open(libpath)) if (
        os.path.exists(libpath)) else {}
    n = 0
    for r in rows:
        if not r.get("label"):
            continue
        rep = r["rep"]
        n += add_entry(lib, r["label"], {
            "map": r["map"], "lat": rep["lat"],
            "px": rep["px"], "hu": rep["hu"],
            "area": rep["area"],
            "aspect": rep["aspect"],
            "learned": datetime.date.today().isoformat(),
            "source": "human-confirm"})
    save_lib(lib, libpath)
    print("learn: %d entries added -> %s" % (n, libpath))


def cmd_teach(spec, extracts, libpath):
    """Teach blobs by lattice position: "x,y:label;..."
    pairs resolved against the first extract. For
    correcting confident rows straight from review."""
    if not extracts:
        sys.exit("teach: need an extract to resolve lat")
    stem, blobs = load_extract(extracts[0])
    lib = json.load(open(libpath)) if (
        os.path.exists(libpath)) else {}
    n = 0
    for pair in spec.split(";"):
        pair = pair.strip()
        if not pair:
            continue
        lat_s, label = pair.split(":")
        lat = [float(v) for v in lat_s.split(",")]
        best, bd = None, None
        for b in blobs:
            d = math.hypot(b["lat"][0] - lat[0],
                           b["lat"][1] - lat[1])
            if bd is None or d < bd:
                best, bd = b, d
        if best is None or bd > EX_TOL:
            print("WARNING: no blob within %.2f of "
                  "(%.2f,%.2f) (nearest %.2f)"
                  % (EX_TOL, lat[0], lat[1],
                     bd if bd is not None else -1))
            continue
        if add_entry(lib, label,
                     entry_of(stem, best,
                              "human-teach")):
            print("taught %s: blob at (%.1f,%.1f),"
                  " area %d, d=%.3f"
                  % (label, best["lat"][0],
                     best["lat"][1], best["area"],
                     bd))
            n += 1
        else:
            print("skipped %s: (%.1f,%.1f) already"
                  " in library"
                  % (label, best["lat"][0],
                     best["lat"][1]))
    save_lib(lib, libpath)
    print("teach: %d entries added -> %s" % (n, libpath))


def cmd_around(spec, extracts):
    """ASCII neighborhood map around a lattice point:
    anchored labels uppercase, proposals lowercase,
    unknown dots. Context for eyeballing a blob before
    naming it."""
    cx, cy = [float(v) for v in spec.split(",")]
    stem, blobs = load_extract(extracts[0])
    mdir = os.path.dirname(extracts[0])
    rows = {}
    mp = os.path.join(mdir, stem + ".match.json")
    if os.path.exists(mp):
        for r in json.load(open(mp)):
            rows[r["i"]] = r
    else:
        print("note: no %s.match.json - labels "
              "unavailable, run a match first"
              % stem)

    def ch_of(i):
        r = rows.get(i)
        if not r or r["proposal"] == "UNKNOWN":
            return "."
        c = r["proposal"][0]
        if r.get("kind") == "anchored":
            return c.upper()
        return c.lower()

    W, STEP = 5.0, 0.5
    best = {}
    for i, b in enumerate(blobs):
        gx = int(round((b["lat"][0] - cx) / STEP))
        gy = int(round((b["lat"][1] - cy) / STEP))
        if abs(gx) * STEP > W or abs(gy) * STEP > W:
            continue
        k = (gx, gy)
        if k not in best or b["area"] > \
                blobs[best[k]]["area"]:
            best[k] = i
    print("around (%.1f,%.1f) %s, +/-%.0f squares"
          " (col = x, row = y, top = high y)"
          % (cx, cy, stem, W))
    for gy in range(int(W / STEP), -int(W / STEP) - 1,
                    -1):
        line = ""
        for gx in range(-int(W / STEP),
                       int(W / STEP) + 1):
            if gx == 0 and gy == 0 and \
                    (0, 0) not in best:
                line += "+"
            else:
                line += ch_of(best.get((gx, gy),
                                      -1)) \
                    if (gx, gy) in best else " "
        print("  %s" % line)
    near = sorted(best.values(),
                  key=lambda i: -blobs[i]["area"])
    for i in near[:8]:
        b, r = blobs[i], rows.get(i, {})
        print("  (%5.1f,%5.1f) area %6d %s %s"
              % (b["lat"][0], b["lat"][1],
                 b["area"], r.get("proposal",
                                   "?"),
                 r.get("kind", "")))


def cmd_rename(spec, libpath):
    """Rename a label: OLD:NEW."""
    old, new = spec.split(":")
    lib = json.load(open(libpath)) if (
        os.path.exists(libpath)) else {}
    if old not in lib:
        print("rename: no label %r in %s"
              % (old, libpath))
        return
    if new != old and new in lib:
        lib[new]["entries"].extend(
            lib[old]["entries"])
        del lib[old]
        print("rename: merged %s into %s"
              % (old, new))
    else:
        lib[new] = lib.pop(old)
        lib[new]["description"] = new
        print("rename: %s -> %s (%d entries)"
              % (old, new, len(lib[new]["entries"])))
    save_lib(lib, libpath)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lib", default="library.json")
    ap.add_argument("--ask", action="store_true")
    ap.add_argument("--learn", metavar="ANSWERS")
    ap.add_argument("--teach", metavar="SPEC")
    ap.add_argument("--around", metavar="X,Y")
    ap.add_argument("--rename", metavar="OLD:NEW")
    ap.add_argument("--import", dest="imp",
                    metavar="EXEMPLARS")
    ap.add_argument("extracts", nargs="*")
    a = ap.parse_args()
    if a.learn:
        cmd_learn(a.learn, a.lib)
        return
    if a.teach:
        cmd_teach(a.teach, a.extracts, a.lib)
        return
    if a.around:
        cmd_around(a.around, a.extracts)
        return
    if a.rename:
        cmd_rename(a.rename, a.lib)
        return
    if a.imp:
        cmd_import(a.imp, a.extracts, a.lib)
        return
    if not a.extracts:
        ap.error("need extracts (or --learn/--import)")
    libpath = a.lib
    if not a.imp and len(a.extracts) >= 1 \
            and not a.extracts[0].endswith(
                ".extract.json"):
        libpath = a.extracts[0]
        a.extracts = a.extracts[1:]
    if not a.extracts:
        ap.error("no extracts given")
    lib = json.load(open(libpath)) if (
        os.path.exists(libpath)) else {}
    for s in a.extracts:
        stem, blobs = load_extract(s)
        match_extract(stem, blobs, lib,
                     a.ask, os.path.dirname(s))


if __name__ == "__main__":
    main()

