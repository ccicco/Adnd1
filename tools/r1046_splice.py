#!/usr/bin/env python3
# r1046_splice.py - the R1046 splice: the Appendix A
# dungeon dressing band tables de-wire (dm/appendixa.h,
# DMG pp.169-172).
#
# WHAT: every band cascade accessor in dm/appendixa.h
# (32 accessors, 224 printed bands, d20 with one d%)
# reads its rows from items::MiscItemRegistry under NEW
# DIRECTORY content/tables/appendixa/ (one lua per
# accessor; def keys appendixa_*). The enums and
# structs stay in-file; every accessor signature is
# unchanged (the r124 audit and dm.cpp pin them); the
# fall-through semantics (roll under the first band ->
# row 0; roll past the last band -> the last row) are
# reproduced verbatim by the band scan.
#
# Row encodings (MiscItemRow; band = the printed band,
# name/set/qty/gp/gpHi/xp/xpHi per shape):
#   enum      name = the enum tag, qty = { ordinal, 0 }
#   int       name = <base>_<value>, gp = the value,
#             qty = { row index, 0 }
#   pass      name = the SPEC_ tag, gp = widthFt,
#             qty = { ordinal, 0 }
#   treasure  name = the TR_ tag, gp = basePerLevel,
#             qty = { ordinal, 0 }
#   exits     name = EXITS_<n>, gp = the under-
#             threshold value, gpHi = the over-
#             threshold value, qty = { row index, 0 }
#   shape     name = <base>_<w>x<h> (the blank row
#             RMS_BLANK), gp/gpHi = w/h, qty = {
#             unusual, row index }
#   cave      name = CAVE_<n>, gp/gpHi = w/h,
#             xp/xpHi = w2/h2, qty = { pool, lake }
# The ordinals ride qtyLo because cascade order is NOT
# enum order (RoomContents: ROOM_TREASURE is ordinal 3
# but prints at band 98-100) - never EnumType(i).
#
# The one-threshold helpers stay in-file constants (the
# R1044 subclass-scalar ruling): streamBridged,
# containerGuarded, goldBecomesPlatinum,
# stairEgressDoorIn20, kExitsRollD4.
#
# DO NOT hand-edit anything this tool writes.
import os
import re
import sys

MAXCH = 78          # the splice-file line discipline
FRAG = "rules/audits/r1046_appendixa_dressing_registry.h"
LUA_DIR = "content/tables/appendixa"
KEY = "appendixa_"


def die(m):
    sys.stderr.write("R1046 SPLICE-RED: %s\n" % m)
    sys.exit(1)


def read(p):
    return open(p).read()


def replace_once(src, old, new):
    if src.count(old) != 1:
        die("anchor not unique (%d): %r"
            % (src.count(old), old[:60]))
    return src.replace(old, new, 1)


def cq(s):
    if '"' in s or "\\" in s:
        die("tag needs escape support: %r" % s)
    return '"%s"' % s


# ---- the table spec ---------------------------------------------------
# (key, fn, shape, enum prefix or None, tag base for
#  synthetic names, max roll)
TABLES = [
    ("appendixa_periodic_check", "passageCheckFor",
     "enum", "PC_", None, 20),
    ("appendixa_door_location", "doorLocationFor",
     "enum", "DL_", None, 20),
    ("appendixa_space_beyond", "spaceBeyondFor",
     "enum", "SB_", None, 20),
    ("appendixa_side_passage", "sidePassageFor",
     "enum", "SP_", None, 20),
    ("appendixa_passage_width",
     "passageWidthFeetFor", "int", None, "PW", 20),
    ("appendixa_special_passage", "specialPassageFor",
     "pass", "SPEC_", None, 20),
    ("appendixa_river_feature", "riverFeature",
     "enum", "WF_", None, 20),
    ("appendixa_chasm_feature", "chasmFeature",
     "enum", "CF_", None, 20),
    ("appendixa_turn", "turnFor",
     "enum", "T_", None, 20),
    ("appendixa_chamber_shape", "chamberShapeFor",
     "shape", None, "CHS", 20),
    ("appendixa_room_shape", "roomShapeFor",
     "shape", None, "RMS", 20),
    ("appendixa_unusual_shape", "unusualShapeFor",
     "enum", "US_", None, 20),
    ("appendixa_circular_feature",
     "circularFeatureFor", "enum", "CIRC_", None, 20),
    ("appendixa_unusual_size", "unusualSizeBaseFor",
     "int", None, "SIZE", 20),
    ("appendixa_exits", "exitsFor",
     "exits", None, "EXITS", 20),
    ("appendixa_exit_location", "exitLocationFor",
     "enum", "EL_", None, 20),
    ("appendixa_exit_direction", "exitDirectionFor",
     "enum", "ED_", None, 20),
    ("appendixa_room_contents", "roomContentsFor",
     "enum", "ROOM_", None, 20),
    ("appendixa_stairway_variant",
     "stairwayVariantFor", "enum", "SV_", None, 20),
    ("appendixa_treasure", "treasureFor",
     "treasure", "TR_", None, 100),
    ("appendixa_container", "containerFor",
     "enum", "C_", None, 20),
    ("appendixa_guard", "guardedByFor",
     "enum", "G_", None, 20),
    ("appendixa_hidden", "hiddenByFor",
     "enum", "H_", None, 20),
    ("appendixa_stairs", "stairsFor",
     "enum", "ST_", None, 20),
    ("appendixa_trick_trap", "trickTrapFor",
     "enum", "TT_", None, 20),
    ("appendixa_gas", "gasFor",
     "enum", "GAS_", None, 20),
    ("appendixa_cave", "caveFor",
     "cave", None, "CAVE", 20),
    ("appendixa_pool", "poolFor",
     "enum", "POOL_", None, 20),
    ("appendixa_lake", "lakeFor",
     "enum", "LAKE_", None, 20),
    ("appendixa_magic_pool", "magicPoolFor",
     "enum", "MP_", None, 20),
    ("appendixa_talking_pool_alignment",
     "talkingPoolAlignmentFor", "enum", "PA_", None, 20),
    ("appendixa_transport_dest", "transportDestFor",
     "enum", "TD_", None, 20),
]
NKEYS = len(TABLES)

ENUM_TYPE = {  # fn -> enum/struct C++ type (for casts)
    "passageCheckFor": "PassageCheck",
    "doorLocationFor": "DoorLocation",
    "spaceBeyondFor": "SpaceBeyond",
    "sidePassageFor": "SidePassage",
    "specialPassageFor": "SpecialPassage",
    "riverFeature": "WaterFeature",
    "chasmFeature": "ChasmFeature",
    "turnFor": "TurnKind",
    "unusualShapeFor": "UnusualShape",
    "circularFeatureFor": "CircularFeature",
    "exitLocationFor": "ExitLocation",
    "exitDirectionFor": "ExitDirection",
    "roomContentsFor": "RoomContents",
    "stairwayVariantFor": "StairVariant",
    "treasureFor": "TreasureKind",
    "containerFor": "Container",
    "guardedByFor": "Guard",
    "hiddenByFor": "Hidden",
    "stairsFor": "StairKind",
    "trickTrapFor": "TrickTrap",
    "gasFor": "GasKind",
    "poolFor": "PoolKind",
    "lakeFor": "LakeKind",
    "magicPoolFor": "MagicPool",
    "talkingPoolAlignmentFor": "PoolAlignment",
    "transportDestFor": "TransportDest",
}

DEF_NAME = {
    "appendixa_periodic_check":
        "Appendix A Table I. periodic check (9 bands)",
    "appendixa_door_location":
        "Appendix A Table II. door location (3 bands)",
    "appendixa_space_beyond":
        "Appendix A Table II. space beyond (6 bands)",
    "appendixa_side_passage":
        "Appendix A Table III. side passages (12 bands)",
    "appendixa_passage_width":
        "Appendix A Table III.A passage width (5 bands)",
    "appendixa_special_passage":
        "Appendix A Table III.B special passage (9 bands)",
    "appendixa_river_feature":
        "Appendix A Table III.B river feature (3 bands)",
    "appendixa_chasm_feature":
        "Appendix A Table III.B chasm feature (3 bands)",
    "appendixa_turn":
        "Appendix A Table IV. turns (6 bands)",
    "appendixa_chamber_shape":
        "Appendix A Table V chamber shape (7 bands)",
    "appendixa_room_shape":
        "Appendix A Table V room shape (9 bands)",
    "appendixa_unusual_shape":
        "Appendix A Table V.A unusual shape (8 bands)",
    "appendixa_circular_feature":
        "Appendix A Table V.A circular feature (4 bands)",
    "appendixa_unusual_size":
        "Appendix A Table V.B unusual size (7 bands)",
    "appendixa_exits":
        "Appendix A Table V.C number of exits (7 bands)",
    "appendixa_exit_location":
        "Appendix A Table V.D exit location (4 bands)",
    "appendixa_exit_direction":
        "Appendix A Table V.E exit direction (3 bands)",
    "appendixa_room_contents":
        "Appendix A Table V.F room contents (6 bands)",
    "appendixa_stairway_variant":
        "Appendix A Table V.F stairway variant (5 bands)",
    "appendixa_treasure":
        "Appendix A Table V.G treasure (8 bands)",
    "appendixa_container":
        "Appendix A Table V.H container (10 bands)",
    "appendixa_guard":
        "Appendix A Table V.I guard (16 bands)",
    "appendixa_hidden":
        "Appendix A Table V.J hidden (10 bands)",
    "appendixa_stairs":
        "Appendix A Table VI. stairs (12 bands)",
    "appendixa_trick_trap":
        "Appendix A Table VII. trick/trap (15 bands)",
    "appendixa_gas":
        "Appendix A Table VII.A gas (7 bands)",
    "appendixa_cave":
        "Appendix A Table VIII. caves (8 bands)",
    "appendixa_pool":
        "Appendix A Table VIII.A pools (5 bands)",
    "appendixa_lake":
        "Appendix A Table VIII.B lakes (4 bands)",
    "appendixa_magic_pool":
        "Appendix A Table VIII.C magic pools (4 bands)",
    "appendixa_talking_pool_alignment":
        "Appendix A Table VIII.C pool alignment (5 bands)",
    "appendixa_transport_dest":
        "Appendix A Table VIII.C transport dest (4 bands)",
}

EXPECTED_BANDS = {  # parsed-band count cross-checks
    "appendixa_periodic_check": 9,
    "appendixa_door_location": 3,
    "appendixa_space_beyond": 6,
    "appendixa_side_passage": 12,
    "appendixa_passage_width": 5,
    "appendixa_special_passage": 9,
    "appendixa_river_feature": 3,
    "appendixa_chasm_feature": 3,
    "appendixa_turn": 6,
    "appendixa_chamber_shape": 7,
    "appendixa_room_shape": 9,
    "appendixa_unusual_shape": 8,
    "appendixa_circular_feature": 4,
    "appendixa_unusual_size": 7,
    "appendixa_exits": 7,
    "appendixa_exit_location": 4,
    "appendixa_exit_direction": 3,
    "appendixa_room_contents": 6,
    "appendixa_stairway_variant": 5,
    "appendixa_treasure": 8,
    "appendixa_container": 10,
    "appendixa_guard": 16,
    "appendixa_hidden": 10,
    "appendixa_stairs": 12,
    "appendixa_trick_trap": 15,
    "appendixa_gas": 7,
    "appendixa_cave": 8,
    "appendixa_pool": 5,
    "appendixa_lake": 4,
    "appendixa_magic_pool": 4,
    "appendixa_talking_pool_alignment": 5,
    "appendixa_transport_dest": 4,
}


# ---- parse ------------------------------------------------------------
def find_fn(src, fn):
    # locate "inline <ret> <fn>(...)" through the body's
    # matching close brace (the R1045 lesson: never slice
    # a signature by spaces; anchor on the fn name)
    m = re.search(r"\b%s\(" % re.escape(fn), src)
    if not m:
        die("accessor %s not found" % fn)
    start = src.rindex("\n", 0, m.start()) + 1
    i = src.index("{", m.end())
    depth = 0
    j = i
    while j < len(src):
        if src[j] == "{":
            depth += 1
        elif src[j] == "}":
            depth -= 1
            if depth == 0:
                break
        j += 1
    if depth != 0:
        die("unbalanced braces in %s" % fn)
    return start, j + 1


def enum_tags(src, prefix):
    # parse the enum block holding prefix (appendixa.h,
    # or dm.h for RoomContents)
    for text in (src, read("dm/dm.h")):
        for m in re.finditer(
                r"enum (\w+)( : int)? \{(.*?)\};",
                text, re.S):
            tags = re.findall(r"\b(%s[A-Z0-9_]*)\b" % prefix,
                              m.group(3))
            if tags:
                if tags[-1].endswith("_COUNT"):
                    tags = tags[:-1]
                return tags
    die("enum with prefix %s not found" % prefix)


def parse_cascade(fn, body):
    # branch heads: "if (r <= K)", "if (r == K)",
    # "else if (...)", "else"; the code between heads is
    # the branch payload; after the last head is the tail
    heads = list(re.finditer(
        r"(?:else if|if) \(r (<=|==) (\d+)\)|"
        r"(?<![\w])else(?![\w(])", body))
    if not heads:
        die("no cascade branches in %s" % fn)
    rows = []
    prev = 0
    for k, h in enumerate(heads):
        seg_start = h.end()
        seg_end = (heads[k + 1].start()
                   if k + 1 < len(heads) else len(body))
        seg = body[seg_start:seg_end]
        if h.group(1):          # an if/else-if condition
            hi = int(h.group(2))
            if h.group(1) == "==":
                lo = hi
            else:
                lo = prev + 1
            prev = hi
        else:                   # bare else: the tail band
            lo = prev + 1
            hi = None            # filled by the caller
        rows.append([lo, hi, seg])
    # a fall-through tail (bare-if cascade, no else)
    # is its own final band: split it off the last
    # condition head's segment (its own return comes
    # first; the trailing return is the tail row)
    if heads[-1].group(1):
        last_seg = rows[-1][2]
        m1 = re.search(r"return [^;]*;", last_seg)
        if not m1:
            die("no branch return in %s tail" % fn)
        rest = last_seg[m1.end():]
        if "return" in rest:
            rows[-1][2] = last_seg[:m1.end()]
            rows.append([prev + 1, None, rest])
    return rows


def interp(fn, shape, prefix, base, rows, tags, ordinals):
    out = []
    n = len(rows)
    for i, (lo, hi, seg) in enumerate(rows):
        if shape == "enum":
            m = re.search(r"return (%s[A-Z0-9_]*);" % prefix,
                          seg)
            if not m:
                die("%s band %d: no return tag" % (fn, i))
            tag = m.group(1)
            if tag not in ordinals:
                die("%s: tag %s not in enum" % (fn, tag))
            r = dict(name=tag, gp=0, gp_hi=0, xp=0, xp_hi=0,
                     qty0=ordinals[tag], qty1=0)
        elif shape == "int":
            m = re.search(r"return (-?\d+);", seg)
            if not m:
                die("%s band %d: no int return" % (fn, i))
            v = int(m.group(1))
            r = dict(name="%s_%d" % (base, v), gp=v,
                     gp_hi=0, xp=0, xp_hi=0,
                     qty0=i, qty1=0)
        elif shape == "pass":
            mk = re.search(r"s\.kind = (\w+);", seg)
            mw = re.search(r"s\.widthFt = (\d+);", seg)
            if not mk or not mw:
                die("%s band %d: no kind/width" % (fn, i))
            tag = mk.group(1)
            if tag not in ordinals:
                die("%s: tag %s not in enum" % (fn, tag))
            r = dict(name=tag, gp=int(mw.group(1)),
                     gp_hi=0, xp=0, xp_hi=0,
                     qty0=ordinals[tag], qty1=0)
        elif shape == "treasure":
            mk = re.search(r"t\.kind = (\w+);", seg)
            if not mk:
                die("%s band %d: no kind" % (fn, i))
            mb = re.search(r"basePerLevel = (\d+);", seg)
            tag = mk.group(1)
            if tag not in ordinals:
                die("%s: tag %s not in enum" % (fn, tag))
            r = dict(name=tag,
                     gp=int(mb.group(1)) if mb else 0,
                     gp_hi=0, xp=0, xp_hi=0,
                     qty0=ordinals[tag], qty1=0)
        elif shape == "exits":
            m = re.search(
                r"return overThreshold \? (\w+) : (\w+);",
                seg)
            if m:
                # the ternary is overThreshold ? OVER : UNDER
                over = m.group(1)
                under = m.group(2)
            else:
                mm = re.search(r"return (\w+);", seg)
                if not mm:
                    die("%s band %d: no exits return"
                        % (fn, i))
                under = over = mm.group(1)
            u = -1 if under == "kExitsRollD4" else int(
                under)
            o = -1 if over == "kExitsRollD4" else int(over)
            r = dict(name="%s_%d" % (base, i + 1), gp=u,
                     gp_hi=o, xp=0, xp_hi=0,
                     qty0=i, qty1=0)
        elif shape == "shape":
            if "return false" in seg:
                r = dict(name="%s_BLANK" % base, gp=0,
                         gp_hi=0, xp=0, xp_hi=0,
                         qty0=0, qty1=i)
            else:
                mw = re.search(r"s\.wFt = (\d+);", seg)
                mh = re.search(r"s\.hFt = (\d+);", seg)
                un = 1 if "unusual = true" in seg else 0
                if (mw is None) != (mh is None):
                    die("%s band %d: w/h mismatch"
                        % (fn, i))
                w = int(mw.group(1)) if mw else 0
                h = int(mh.group(1)) if mh else 0
                r = dict(
                    name=("%s_UNUSUAL" % base if un
                          else "%s_%dx%d" % (base, w, h)),
                    gp=w, gp_hi=h, xp=0, xp_hi=0,
                    qty0=un, qty1=i)
        elif shape == "cave":
            def g(p):
                mm = re.search(p, seg)
                return int(mm.group(1)) if mm else 0
            w = g(r"c\.wFt = (\d+);")
            h = g(r"c\.hFt = (\d+);")
            w2 = g(r"c\.w2Ft = (\d+);")
            h2 = g(r"c\.h2Ft = (\d+);")
            pool = 1 if "c.pool = true" in seg else 0
            lake = 1 if "c.lake = true" in seg else 0
            if w == 0 and h == 0 and w2 == 0 and h2 == 0:
                die("%s band %d: empty cave row" % (fn, i))
            r = dict(name="%s_%d" % (base, i + 1), gp=w,
                     gp_hi=h, xp=w2, xp_hi=h2,
                     qty0=pool, qty1=lake)
        else:
            die("unknown shape %s" % shape)
        if hi is None:      # the else-tail band
            hi = lo - 1     # marker; caller sets the max
        r["lo"] = lo
        r["hi"] = hi
        out.append(r)
    # the last band (else-tail or fall-through) runs to
    # the die max
    out[-1]["hi"] = MAXROLL[fn]
    return out, n


MAXROLL = {}


def parse_all():
    src = read("dm/appendixa.h")
    tables = {}
    for key, fn, shape, prefix, base, mx in TABLES:
        MAXROLL[fn] = mx
        start, end = find_fn(src, fn)
        body = src[start:end]
        tags, ordinals = [], {}
        if prefix:
            tags = enum_tags(src, prefix)
            ordinals = {t: k for k, t in enumerate(tags)}
        rows, n = interp(fn, shape, prefix, base,
                         parse_cascade(fn, body), tags,
                         ordinals)
        if n != EXPECTED_BANDS[key]:
            die("%s: parsed %d bands, want %d"
                % (key, n, EXPECTED_BANDS[key]))
        # the chain must be contiguous and end at max
        prev = 0
        for r in rows:
            if r["lo"] != prev + 1 or r["hi"] < r["lo"]:
                die("%s: band chain break at %d-%d"
                    % (key, r["lo"], r["hi"]))
            prev = r["hi"]
        if prev != mx:
            die("%s: last band %d != %d" % (key, prev, mx))
        tables[key] = dict(fn=fn, shape=shape, rows=rows,
                          tags=tags)
        print("parsed: %s %d bands" % (key, n))
    return src, tables


# ---- lua emission ------------------------------------------------------
RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", '
    r"band = \{ (-?\d+), (-?\d+) \}, "
    r"xp = (-?\d+), xp_hi = (-?\d+), "
    r"gp = (-?\d+), gp_hi = (-?\d+), "
    r"qty = \{ (-?\d+), (-?\d+) \} \}")


def lua_row(key, r):
    return ("{ name = %s, set = %s, band = { %d, %d }, "
            "xp = %d, xp_hi = %d, gp = %d, gp_hi = %d, "
            "qty = { %d, %d } },"
            % (cq(r["name"]), cq(key), r["lo"], r["hi"],
               r["xp"], r["xp_hi"], r["gp"], r["gp_hi"],
               r["qty0"], r["qty1"]))


def emit_lua(tables):
    os.makedirs(LUA_DIR, exist_ok=True)
    for key, ent in tables.items():
        rows = ent["rows"]
        n = len(rows)
        L = []
        L.append("-- dressing table def: %s" % key)
        L.append("-- The DMG Appendix A dungeon dressing"
                 " bands, the R1046 de-wire.")
        L.append("-- %s." % DEF_NAME[key])
        L.append("-- Row encoding: the R1046 shape"
                 " convention (name the")
        L.append("-- enum tag or the synthetic tag, band"
                 " the printed")
        L.append("-- roll band, and the shape payload in"
                 " gp/gpHi/xp/xpHi/qty;")
        if ent["shape"] in ("enum", "pass", "treasure"):
            L.append("-- qty[1] the enum ordinal, never"
                     " the row index")
            L.append("-- (cascade order is not enum"
                     " order). The accessor")
        else:
            L.append("-- see the seam comment in"
                     " dm/appendixa.h for this")
            L.append("-- shape's field map. The accessor")
        L.append("-- and the fall-through semantics live"
                 " in dm/appendixa.h")
        L.append("-- and are unchanged.")
        L.append("-- DO NOT hand-edit:"
                 " tools/r1046_splice.py is the only"
                 " writer.")
        L.append("")
        L.append("return {")
        L.append('  key = "%s",' % key)
        L.append('  name = "%s",' % DEF_NAME[key])
        L.append("  rows = {")
        for r in rows:
            L.append("    " + lua_row(key, r))
        L.append("  },")
        L.append("  sources = {")
        L.append("    { part = 0, round = 1046 },")
        L.append("  },")
        L.append('  pins = { { name = "%sRowCount",'
                 ' value = %d },' % (key, n))
        L.append("  },")
        L.append("  tables = {},")
        L.append("}")
        open(os.path.join(LUA_DIR, key + ".lua"),
             "w").write("\n".join(L) + "\n")
        # round-trip: parse it back byte-exact
        back = read(os.path.join(LUA_DIR, key + ".lua"))
        got = RT_ROW.findall(back)
        if len(got) != n:
            die("%s: round-trip row count %d != %d"
                % (key, len(got), n))
        for i, g in enumerate(got):
            r = rows[i]
            want = (r["name"], key, str(r["lo"]),
                    str(r["hi"]), str(r["xp"]),
                    str(r["xp_hi"]), str(r["gp"]),
                    str(r["gp_hi"]), str(r["qty0"]),
                    str(r["qty1"]))
            if g != want:
                die("%s row %d round-trip: %r != %r"
                    % (key, i, g, want))
    print("round-trip: %d lua files parse back"
          " byte-exact" % NKEYS)


# ---- the header seam ---------------------------------------------------
SEAM = (
    "// ---- the R1046 registry seam ----------------------------------------\n"
    "// The 32 Appendix A dressing band tables\n"
    "// ride items::MiscItemRegistry from\n"
    "// content/tables/appendixa/ (def keys\n"
    "// appendixa_*). Row encoding: name the\n"
    "// enum tag or the synthetic tag, band the\n"
    "// printed roll band, and the shape payload\n"
    "// in gp/gpHi/xp/xpHi/qty (qty[1] the enum\n"
    "// ordinal - cascade order is not enum\n"
    "// order; the RoomContents lesson). This\n"
    "// seam is header-only (the R1040-R1045\n"
    "// idiom); every accessor signature below\n"
    "// is unchanged (the r124 audit and dm.cpp\n"
    "// pin them); the enums and structs stay\n"
    "// in-file as constants and the fall-through\n"
    "// semantics (under the first band -> row\n"
    "// 0, past the last -> the last row) are\n"
    "// reproduced verbatim by the band scan.\n"
    "// The one-threshold helpers stay in-file\n"
    "// constants (the R1044 subclass-scalar\n"
    "// ruling): streamBridged,\n"
    "// containerGuarded, goldBecomesPlatinum,\n"
    "// stairEgressDoorIn20, kExitsRollD4.\n"
    "\n"
    "inline items::MiscItemRegistry& aaReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    '        reg.loadDirectory("content/tables/appendixa");\n'
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view cache (the\n"
    "// R1032-R1045 idiom; function-local statics in\n"
    "// inline functions are shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>&\n"
    "aaView(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d =\n"
    "            aaReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<"
    "items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


def new_body(key, ent):
    fn = ent["fn"]
    shape = ent["shape"]
    rows = ent["rows"]
    first = rows[0]
    last = rows[-1]
    v = key
    L = []
    a = L.append
    if shape == "enum":
        et = ENUM_TYPE[fn]
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (rows.empty())\n")
        a("        return %s;   // defensive\n" % first["name"])
        a("    for (int i = 0; i < (int)rows.size(); ++i)\n")
        a("        if (r <= rows[i].bandHi)\n")
        a("            return %s(rows[i].qtyLo);\n" % et)
        a("    return %s(rows[(int)rows.size() - 1]\n"
          ".qtyLo);\n" % et)
    elif shape == "int":
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (rows.empty())\n")
        a("        return %d;   // defensive\n" % first["gp"])
        a("    for (int i = 0; i < (int)rows.size(); ++i)\n")
        a("        if (r <= rows[i].bandHi)\n")
        a("            return rows[i].gp;\n")
        a("    return rows[(int)rows.size() - 1].gp;\n")
    elif shape == "pass":
        a("    SpecialPass s;\n")
        a("    s.widthFt = 0;\n")
        a("    s.kind = %s;   // defensive\n" % first["name"])
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (!rows.empty()) {\n")
        a("        int i = 0;\n")
        a("        for (; i < (int)rows.size(); ++i)\n")
        a("            if (r <= rows[i].bandHi) break;\n")
        a("        if (i >= (int)rows.size())\n")
        a("            i = (int)rows.size() - 1;\n")
        a("        s.kind = SpecialPassage(rows[i].qtyLo);\n")
        a("        s.widthFt = rows[i].gp;\n")
        a("    }\n")
        a("    return s;\n")
    elif shape == "treasure":
        a("    TreasureRow t;\n")
        a("    t.kind = %s;\n" % first["name"])
        a("    t.basePerLevel = 0;\n")
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (!rows.empty()) {\n")
        a("        int i = 0;\n")
        a("        for (; i < (int)rows.size(); ++i)\n")
        a("            if (r <= rows[i].bandHi) break;\n")
        a("        if (i >= (int)rows.size())\n")
        a("            i = (int)rows.size() - 1;\n")
        a("        t.kind = TreasureKind(rows[i].qtyLo);\n")
        a("        t.basePerLevel = rows[i].gp;\n")
        a("    }\n")
        a("    return t;\n")
    elif shape == "exits":
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (rows.empty())\n")
        a("        return overThreshold ? %d : %d;   "
          "// defensive\n"
          % (first["gp_hi"], first["gp"]))
        a("    for (int i = 0; i < (int)rows.size(); ++i)\n")
        a("        if (r <= rows[i].bandHi)\n")
        a("            return overThreshold ? rows[i].gpHi\n")
        a("                              : rows[i].gp;\n")
        a("    return overThreshold\n")
        a("        ? rows[(int)rows.size() - 1].gpHi\n")
        a("        : rows[(int)rows.size() - 1].gp;\n")
    elif shape == "shape":
        a("    s.wFt = 0; s.hFt = 0; s.unusual = false;\n")
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (rows.empty()) {\n")
        if fn == "roomShapeFor":
            a("        s.wFt = 10; s.hFt = 10;\n")
            a("        return true;   // defensive: a load\n")
            a("        // failure must never hang the dm.cpp\n")
            a("        // re-roll while-loop (10'x10' room)\n")
            a("    }\n")
        else:
            a("        return;   // defensive\n")
            a("    }\n")
        a("    int i = 0;\n")
        a("    for (; i < (int)rows.size(); ++i)\n")
        a("        if (r <= rows[i].bandHi) break;\n")
        a("    if (i >= (int)rows.size())\n")
        a("        i = (int)rows.size() - 1;\n")
        if fn == "roomShapeFor":
            a('    if (rows[i].name == "RMS_BLANK")'
              '   // 18-20: blank\n')
            a("        return false;   "
              "// in the book - re-roll\n")
        a("    s.wFt = rows[i].gp;\n")
        a("    s.hFt = rows[i].gpHi;\n")
        a("    s.unusual = rows[i].qtyLo != 0;\n")
        if fn == "roomShapeFor":
            a("    return true;\n")
    elif shape == "cave":
        a("    CaveSize c;\n")
        a("    const auto& rows = aaView(\"%s\");\n" % v)
        a("    if (rows.empty())\n")
        a("        return c;   // defensive\n")
        a("    int i = 0;\n")
        a("    for (; i < (int)rows.size(); ++i)\n")
        a("        if (r <= rows[i].bandHi) break;\n")
        a("    if (i >= (int)rows.size())\n")
        a("        i = (int)rows.size() - 1;\n")
        a("    c.wFt = rows[i].gp;\n")
        a("    c.hFt = rows[i].gpHi;\n")
        a("    c.w2Ft = rows[i].xp;\n")
        a("    c.h2Ft = rows[i].xpHi;\n")
        a("    c.pool = rows[i].qtyLo != 0;\n")
        a("    c.lake = rows[i].qtyHi != 0;\n")
        a("    return c;\n")
    else:
        die("shape %s" % shape)
    return "".join(L)


def rewrite_header(src, tables):
    # the include
    src = replace_once(
        src,
        '#include "dm.h"   // dm::RoomContents\n',
        '#include "dm.h"   // dm::RoomContents\n'
        '#include "items/MiscItemRegistry.h"   '
        "// R1046: the dressing bands ride\n"
        "                                     "
        "// the registry\n")
    # the banner note
    src = replace_once(
        src,
        "// R124: DMG pp.169-172 - APPENDIX A, RANDOM"
        " DUNGEON\n",
        "// R124: DMG pp.169-172 - APPENDIX A, RANDOM\n"
        "// R1046: the 32 band tables are registry-native\n"
        "// (content/tables/appendixa/, the seam below);\n"
        "// the printed cascades are gone from this header\n"
        "// and the accessors read registry views. The\n"
        "// enums and structs stay in-file as constants\n"
        "// (the band identity API); the fall-through\n"
        "// semantics stay verbatim.\n")
    # the seam, right inside the namespace
    src = replace_once(
        src,
        "namespace dm {\nnamespace appendixa {\n\n",
        "namespace dm {\nnamespace appendixa {\n\n"
        + SEAM)
    # each accessor body
    for key, ent in tables.items():
        start, end = find_fn(src, ent["fn"])
        head = src[start:end]
        sig = head[:head.index("{") + 1]
        body = new_body(key, ent)
        if "return;" not in body and shape_returns_void(
                ent):
            die("%s: void shape lost the return" % key)
        new = sig + "\n" + body + "}\n"
        src = src[:start] + new + src[end:]
    return src


def shape_returns_void(ent):
    return ent["fn"] == "chamberShapeFor"


# ---- the fragment -----------------------------------------------------
def build_fragment(tables):
    L = []
    a = L.append
    a("    // ==== R1046: appendix A dressing registry ================================\n")
    a("    // The R1046 de-wire: the 32 DMG Appendix A\n")
    a("    // dungeon dressing band tables (224 printed\n")
    a("    // bands, d20 with one d%) ride\n")
    a("    // items::MiscItemRegistry from\n")
    a("    // content/tables/appendixa/ (def keys\n")
    a("    // appendixa_*). This audit loads its own\n")
    a("    // registry instance and cross-reads every\n")
    a("    // band through the inline accessor surface\n")
    a("    // and the aaView seam, so the r124 audit and\n")
    a("    // this registry audit read the same data\n")
    a("    // through the same signatures.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    # 1. load
    a("        // -- 1. load --------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory("content/tables/appendixa")\n')
    a("                != %d) ++bad;\n" % NKEYS)
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != %d) ++bad;\n" % NKEYS)
    for key, _f, _s, _p, _b, _m in TABLES[:6]:
        a('            if (t.all().count("%s") != 1) ++bad;\n'
          % key)
    a('            if (t.all().count("appendixa_width")) ++bad;\n')
    a('            if (t.all().count("treasure_swords")) ++bad;\n')
    a('            if (t.all().count("")) ++bad;\n')
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry load audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 2. counts
    a("        // -- 2. counts ------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixa");\n')
    for key, _fn, _sh, _p, _b, _m in TABLES:
        v = "v_%s" % key[len(KEY):]
        a('            const auto* %s = t.find("%s");\n'
          % (v, key))
        a("            if (!%s || (int)%s->rows.size() != %d)\n"
          % (v, v, EXPECTED_BANDS[key]))
        a("                ++bad;\n")
        a("            if (%s && ((int)%s->pins.size() != 1\n"
          % (v, v))
        a("                       || %s->pins[0].name\n" % v)
        a('                              != std::string("%sRowCount")\n'
          % key)
        a("                       || %s->pins[0].value != %d))\n"
          % (v, EXPECTED_BANDS[key]))
        a("                ++bad;\n")
        a("            if (%s && (int)%s->sources.size() != 1)\n"
          % (v, v))
        a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry counts audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 3. bands
    a("        // -- 3. bands (the roll axis) ---------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixa");\n')
    a("            for (const auto& kv : t.all()) {\n")
    a("                const auto& d = kv.second;\n")
    a("                int prevHi = 0;\n")
    a("                for (const auto& r : d.rows) {\n")
    a("                    if (r.bandLo != prevHi + 1\n")
    a("                        || r.bandHi < r.bandLo\n")
    a("                        || r.bandHi > 100\n")
    a("                        || r.set != d.key\n")
    a("                        || r.name.empty()) ++bad;\n")
    a("                    prevHi = r.bandHi;\n")
    a("                }\n")
    a("            }\n")
    for key, _fn, _sh, _p, _b, mx in TABLES:
        v = "v_%s" % key[len(KEY):]
        a('            const auto* %s = t.find("%s");\n'
          % (v, key))
        a("            if (!%s || %s->rows.empty()\n" % (v, v))
        a("                || %s->rows.back().bandHi != %d)\n"
          % (v, mx))
        a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry bands audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 4. data (famous pins, all computed from parsed source)
    a("        // -- 4. data (famous pins, all computed) ----------\n")
    a("        {\n")
    a("            namespace AA = dm::appendixa;\n")
    for key, fn, shape, _p, _b, _m in TABLES:
        ent = tables[key]
        rows = ent["rows"]
        mid = len(rows) // 2
        for idx in (0, mid, len(rows) - 1):
            r = rows[idx]
            roll = r["hi"] if idx == len(rows) - 1 else r["lo"]
            if shape == "enum":
                # the enum must be reachable from the
                # fragment scope: every band enum lives
                # in dm::appendixa EXCEPT RoomContents,
                # which lives in dm (dm.h) - qualify it
                # with its home namespace (the R1046
                # preflight catch)
                q = ("dm::" if _p == "ROOM_"
                      else "AA::")
                a("            if (AA::%s(%d)\n"
                  "                != %s%s) ++bad;\n"
                  % (fn, roll, q, r["name"]))
            elif shape == "int":
                a("            if (AA::%s(%d) != %d) ++bad;\n"
                  % (fn, roll, r["gp"]))
            elif shape == "pass":
                a("            if (AA::%s(%d).kind\n"
                  "                    != AA::%s\n"
                  "                || AA::%s(%d).widthFt\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, r["name"], fn, roll,
                     r["gp"]))
            elif shape == "treasure":
                a("            if (AA::%s(%d).kind\n"
                  "                    != AA::%s\n"
                  "                || AA::%s(%d).basePerLevel\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, r["name"], fn, roll,
                     r["gp"]))
            elif shape == "exits":
                a("            if (AA::%s(%d, false) != %d\n"
                  "                || AA::%s(%d, true)\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, r["gp"], fn, roll,
                     r["gp_hi"]))
            elif shape == "shape":
                blank = (r["name"] == "RMS_BLANK")
                if blank:
                    a("            { AA::SpaceShape s;\n")
                    a("              if (AA::%s(%d, s)\n"
                      "                  || s.wFt != 0\n"
                      "                  || s.hFt != 0)\n"
                      "                  ++bad; }\n"
                      % (fn, roll))
                else:
                    a("            { AA::SpaceShape s;\n")
                    a("              AA::%s(%d, s);\n"
                      % (fn, roll))
                    a("              if (s.wFt != %d\n"
                      "                  || s.hFt != %d\n"
                      "                  || s.unusual\n"
                      "                     != %s) ++bad; }\n"
                      % (r["gp"], r["gp_hi"],
                         "true" if r["qty0"] else "false"))
            elif shape == "cave":
                a("            { AA::CaveSize c ="
                  " AA::%s(%d);\n" % (fn, roll))
                a("              if (c.wFt != %d\n"
                  "                  || c.hFt != %d\n"
                  "                  || c.w2Ft != %d\n"
                  "                  || c.h2Ft != %d\n"
                  "                  || c.pool != %s\n"
                  "                  || c.lake != %s)\n"
                  "                  ++bad; }\n"
                  % (r["gp"], r["gp_hi"], r["xp"], r["xp_hi"],
                     "true" if r["qty0"] else "false",
                     "true" if r["qty1"] else "false"))
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry data audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 5. rows (the full cross-read)
    a("        // -- 5. rows (the full band cross-read) -----------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixa");\n')
    for key, fn, shape, _p, _b, mx in TABLES:
        v = "v_%s" % key[len(KEY):]
        ent = tables[key]
        names = [r["name"] for r in ent["rows"]]
        a('            const auto* %s = t.find("%s");\n'
          % (v, key))
        a("            if (!%s) { ++bad; } else {\n" % v)
        a("                static const char* const"
          " k1046_%s[] = {\n" % key[len(KEY):])
        for i in range(0, len(names), 3):
            a("                    " + " ".join(
                "%s," % cq(nm) for nm in names[i:i + 3])
              + "\n")
        a("                };\n")
        a("                if ((int)(sizeof(k1046_%s)\n"
          % key[len(KEY):])
        a("                        / sizeof(k1046_%s[0]))\n"
          % key[len(KEY):])
        a("                        != (int)%s->rows.size())\n"
          % v)
        a("                    ++bad;\n")
        a("                for (int i = 0;\n")
        a("                     i < (int)%s->rows.size(); ++i) {\n" % v)
        a("                    const auto& rr = %s->rows[i];\n" % v)
        a("                    if (rr.name\n")
        a("                            != std::string("
          "k1046_%s[i]))\n" % key[len(KEY):])
        a("                        ++bad;\n")
        a("                    for (int r = rr.bandLo;\n")
        a("                         r <= rr.bandHi; ++r) {\n")
        if shape == "enum":
            a("                        if ((int)dm::appendixa::%s(r)\n" % fn)
            a("                                != rr.qtyLo)\n")
            a("                            ++bad;\n")
        elif shape == "int":
            a("                        if (dm::appendixa::%s(r)\n" % fn)
            a("                                != rr.gp)\n")
            a("                            ++bad;\n")
        elif shape == "pass":
            a("                        dm::appendixa::SpecialPass sp\n")
            a("                            = dm::appendixa::%s(r);\n" % fn)
            a("                        if ((int)sp.kind != rr.qtyLo\n")
            a("                            || sp.widthFt != rr.gp)\n")
            a("                            ++bad;\n")
        elif shape == "treasure":
            a("                        dm::appendixa::TreasureRow tr\n")
            a("                            = dm::appendixa::%s(r);\n" % fn)
            a("                        if ((int)tr.kind != rr.qtyLo\n")
            a("                            || tr.basePerLevel\n")
            a("                               != rr.gp)\n")
            a("                            ++bad;\n")
        elif shape == "exits":
            a("                        if (dm::appendixa::%s(r, false)\n" % fn)
            a("                                != rr.gp\n")
            a("                            || dm::appendixa::%s(r, true)\n" % fn)
            a("                                   != rr.gpHi)\n")
            a("                            ++bad;\n")
        elif shape == "shape":
            blankn = '"RMS_BLANK"' if fn == "roomShapeFor" \
                else '"CHS_UNUSUAL"'
            a("                        dm::appendixa::SpaceShape s;\n")
            if fn == "roomShapeFor":
                a("                        bool ok =\n")
                a("                            dm::appendixa::"
                  "%s(r, s);\n" % fn)
                a("                        if (ok\n")
                a("                            == (rr.name\n")
                a("                                == std::string("
                  "%s)))\n" % blankn)
                a("                            ++bad;\n")
            else:
                a("                        dm::appendixa::"
                  "%s(r, s);\n" % fn)
                a("                        (void)0;\n")
            if fn == "roomShapeFor":
                # the blank band reports ok=false BY DESIGN - the
                # dims payload is only asserted when a real shape
                # was reported (the R1046 rows-audit lesson)
                a("                        if (ok\n")
                a("                            && (s.wFt != rr.gp\n")
                a("                                || s.hFt != rr.gpHi\n")
                a("                                || s.unusual\n")
                a("                                   != (rr.qtyLo != 0)))\n")
                a("                            ++bad;\n")
            else:
                a("                        if (false\n")
                a("                            || s.wFt != rr.gp\n")
                a("                            || s.hFt != rr.gpHi\n")
                a("                            || s.unusual\n")
                a("                               != (rr.qtyLo != 0))\n")
                a("                            ++bad;\n")
        elif shape == "cave":
            a("                        dm::appendixa::CaveSize c =\n")
            a("                            dm::appendixa::%s(r);\n" % fn)
            a("                        if (c.wFt != rr.gp\n")
            a("                            || c.hFt != rr.gpHi\n")
            a("                            || c.w2Ft != rr.xp\n")
            a("                            || c.h2Ft != rr.xpHi\n")
            a("                            || c.pool\n")
            a("                               != (rr.qtyLo != 0)\n")
            a("                            || c.lake\n")
            a("                               != (rr.qtyHi != 0))\n")
            a("                            ++bad;\n")
        a("                    }\n")
        a("                }\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry rows audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 6. edges
    a("        // -- 6. edges (fall-through, negatives) -----------\n")
    a("        {\n")
    a("            namespace AA = dm::appendixa;\n")
    for key, fn, shape, _p, _b, mx in TABLES:
        ent = tables[key]
        first = ent["rows"][0]
        last = ent["rows"][-1]
        # under the first band -> row 0; past the last
        # -> the last row (the verbatim fall-through)
        for roll in (0, -5):
            if shape == "enum":
                a("            if ((int)AA::%s(%d) != %d)\n"
                  "                ++bad;\n"
                  % (fn, roll, first["qty0"]))
            elif shape == "int":
                a("            if (AA::%s(%d) != %d)\n"
                  "                ++bad;\n"
                  % (fn, roll, first["gp"]))
            elif shape == "pass":
                a("            if ((int)AA::%s(%d).kind != %d\n"
                  "                || AA::%s(%d).widthFt\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, first["qty0"], fn, roll,
                     first["gp"]))
            elif shape == "treasure":
                a("            if ((int)AA::%s(%d).kind != %d\n"
                  "                || AA::%s(%d).basePerLevel\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, first["qty0"], fn, roll,
                     first["gp"]))
            elif shape == "exits":
                a("            if (AA::%s(%d, false) != %d\n"
                  "                || AA::%s(%d, true)\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, first["gp"], fn, roll,
                     first["gp_hi"]))
            elif shape == "shape":
                un = "true" if first["qty0"] else "false"
                if fn == "roomShapeFor" and first["name"] == \
                        "RMS_BLANK":
                    a("            { AA::SpaceShape s;\n")
                    a("              if (AA::%s(%d, s)) ++bad; }\n"
                      % (fn, roll))
                else:
                    a("            { AA::SpaceShape s;\n")
                    a("              AA::%s(%d, s);\n" % (fn, roll))
                    a("              if (s.wFt != %d\n"
                      "                  || s.hFt != %d\n"
                      "                  || s.unusual != %s)\n"
                      "                  ++bad; }\n"
                      % (first["gp"], first["gp_hi"], un))
            elif shape == "cave":
                a("            { AA::CaveSize c ="
                  " AA::%s(%d);\n" % (fn, roll))
                a("              if (c.wFt != %d\n"
                  "                  || c.hFt != %d\n"
                  "                  || c.w2Ft != %d\n"
                  "                  || c.h2Ft != %d\n"
                  "                  || c.pool != %s\n"
                  "                  || c.lake != %s)\n"
                  "                  ++bad; }\n"
                  % (first["gp"], first["gp_hi"], first["xp"],
                     first["xp_hi"],
                     "true" if first["qty0"] else "false",
                     "true" if first["qty1"] else "false"))
        for roll in (mx + 1, 999):
            if shape == "enum":
                a("            if ((int)AA::%s(%d) != %d)\n"
                  "                ++bad;\n"
                  % (fn, roll, last["qty0"]))
            elif shape == "int":
                a("            if (AA::%s(%d) != %d)\n"
                  "                ++bad;\n"
                  % (fn, roll, last["gp"]))
            elif shape == "pass":
                a("            if ((int)AA::%s(%d).kind != %d\n"
                  "                || AA::%s(%d).widthFt\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, last["qty0"], fn, roll,
                     last["gp"]))
            elif shape == "treasure":
                a("            if ((int)AA::%s(%d).kind != %d\n"
                  "                || AA::%s(%d).basePerLevel\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, last["qty0"], fn, roll,
                     last["gp"]))
            elif shape == "exits":
                a("            if (AA::%s(%d, false) != %d\n"
                  "                || AA::%s(%d, true)\n"
                  "                    != %d) ++bad;\n"
                  % (fn, roll, last["gp"], fn, roll,
                     last["gp_hi"]))
            elif shape == "shape":
                un = "true" if last["qty0"] else "false"
                if fn == "roomShapeFor" and last["name"] == \
                        "RMS_BLANK":
                    a("            { AA::SpaceShape s;\n")
                    a("              if (AA::%s(%d, s)) ++bad; }\n"
                      % (fn, roll))
                else:
                    a("            { AA::SpaceShape s;\n")
                    a("              AA::%s(%d, s);\n" % (fn, roll))
                    a("              if (s.wFt != %d\n"
                      "                  || s.hFt != %d\n"
                      "                  || s.unusual != %s)\n"
                      "                  ++bad; }\n"
                      % (last["gp"], last["gp_hi"], un))
            elif shape == "cave":
                a("            { AA::CaveSize c ="
                  " AA::%s(%d);\n" % (fn, roll))
                a("              if (c.wFt != %d\n"
                  "                  || c.hFt != %d\n"
                  "                  || c.w2Ft != %d\n"
                  "                  || c.h2Ft != %d\n"
                  "                  || c.pool != %s\n"
                  "                  || c.lake != %s)\n"
                  "                  ++bad; }\n"
                  % (last["gp"], last["gp_hi"], last["xp"],
                     last["xp_hi"],
                     "true" if last["qty0"] else "false",
                     "true" if last["qty1"] else "false"))
    a('            if (!dm::appendixa::aaView("appendixa").empty())\n')
    a("                ++bad;\n")
    a('            if (!dm::appendixa::aaView("no_such").empty())\n')
    a("                ++bad;\n")
    a('            if (dm::appendixa::aaReg().find("treasure_swords")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (dm::appendixa::aaReg().find("") != nullptr)\n')
    a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1046 appendix A dressing registry edges audit: bad %d\\n", bad);\n')
    a("    }\n")
    return "".join(L)


# ---- static header checks (the R392 lesson, generalized; the
# R1045 fix-1 lesson adds the ::( guard) --------------------------
def static_checks(name, text):
    for ln in text.split("\n"):
        # strip comment tails first: printed prose may
        # quote the book (the appendixa banner does)
        code_ln = re.sub(r"//[^\n]*", "", ln)
        stripped = re.sub(r"\\.", "", code_ln)
        if stripped.count('"') % 2 != 0:
            die("%s: unbalanced quotes: %r" % (name, ln))
    depth = 0
    for ch in text:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
    if depth != 0:
        die("%s: brace balance %d" % (name, depth))
    code = re.sub(r'"[^"\n]*"', '""', text)
    code = re.sub(r"//[^\n]*", "", code)
    for m in re.finditer(r"\b[A-Za-z0-9_]+(-[A-Za-z0-9_]+)+\b",
                         code):
        die("%s: hyphen token in code: %r"
            % (name, m.group(0)))
    for m in re.finditer(r"::\s*\(", code):
        die("%s: qualified call with no name at %r"
            % (name, m.group(0)))


def census():
    total = 0
    for root, _dirs, files in os.walk("rules"):
        if "audits" not in root:
            continue
        for f in files:
            if f.endswith(".h"):
                total += read(os.path.join(root, f)).count(
                    "audit: bad %d")
    total += read("regtest.cpp").count("audit: bad %d")
    return total


# ---- main --------------------------------------------------------------
def main():
    before = census()
    if os.path.exists(os.path.join(LUA_DIR,
                                   "appendixa_turn.lua")):
        print("applied 0, already 1")
        print("SPLICE OK")
        return
    src, tables = parse_all()
    emit_lua(tables)
    new_src = rewrite_header(src, tables)
    # regtest: the include, after the R1045 line
    new_src_reg = read("regtest.cpp")
    new_src_reg = replace_once(
        new_src_reg,
        '    #include "rules/audits/'
        'r1045_appendixi_dressing_registry.h"  // R1045\n',
        '    #include "rules/audits/'
        'r1045_appendixi_dressing_registry.h"  // R1045\n'
        '    #include "rules/audits/'
        'r1046_appendixa_dressing_registry.h"  // R1046\n')
    frag = build_fragment(tables)
    static_checks("dm/appendixa.h", new_src)
    static_checks("regtest.cpp", new_src_reg)
    static_checks("the fragment", frag)
    open("dm/appendixa.h", "w").write(new_src)
    open("regtest.cpp", "w").write(new_src_reg)
    open(FRAG, "w").write(frag)
    after = census()
    print("census: %d -> %d audit printf patterns"
          % (before, after))
    if after != before + 6:
        die("census must move by exactly 6 (got %d)"
            % (after - before))
    print("applied 1, rewrote 2 tracked files,"
          " wrote %d new files" % (NKEYS + 1))
    print("SPLICE OK")


main()
