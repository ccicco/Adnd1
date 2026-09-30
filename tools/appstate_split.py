#!/usr/bin/env python3
"""appstate_split.py -- R78: move AppState inline method bodies out-of-line.

Run from the repo root:  python3 tools/appstate_split.py [--dry]
Rewrites game/appstate.h (keeps declarations only) and writes
game/state_core.cpp, state_town.cpp, state_dungeon.cpp, state_combat.cpp,
game/state_overland.cpp, state_sea.cpp (plus state_misc.cpp if anything
is unmapped -- a safety net so no code is ever lost).
"""
import re
import sys
import os

SRC = "game/appstate.h"
DRY = "--dry" in sys.argv[1:]

GROUPS = {
    "state_core.cpp": ["newDungeon", "beginDelve", "resetToCreation", "saveGame",
                       "loadGame", "placeStairs", "descend", "restoreSlots",
                       "restockAmmo"],
    "state_town.cpp": ["enterTown", "billTownVisit", "leaveTown", "townBuyPotion",
                       "townBuyArrows", "townInnRest", "townTempleHeal",
                       "townBuySword", "townTrain", "townBuyChain", "townBuyScroll",
                       "townBuildStronghold", "townBuyIdentify", "useIdentifyScroll",
                       "townHireHenchman", "townSage", "townSpy", "townPeddler",
                       "describeRoom", "townTalk", "townUpgradeHire",
                       "townHireCrew", "arriveTown"],
    "state_dungeon.cpp": ["restExplore", "populateRooms", "springTrap",
                          "placeSecretDoors", "searchExplore", "rollTreasure",
                          "awardVictory", "spawnRoomEncounter",
                          "countOccupied", "roomCountCap", "roomAt",
                          "occupiedRoomNear", "trapRoomNear"],
    "state_combat.cpp": ["partyActors", "beginCombat", "quaffExplore", "combatQuaff",
                         "combatShoot", "combatThrow", "rollSpawnContext",
                         "hpPerDieFor", "rollDmEncounter", "buildFoesFromDm",
                         "encFromRoom", "kitNpc", "npcName", "buildFoesFromParty",
                         "spawnWanderingEncounter", "playerFlee", "endCombat"],
    "state_overland.cpp": ["enterOverland", "overlandSetTerrain", "overlandInhabited",
                           "overlandClime", "overlandStep", "overlandWildEncounter",
                           "overlandPatrol", "overlandMeeting", "overlandSafeCamp",
                           "overlandDiscoverCastle", "overlandApproach",
                           "overlandPass", "overlandTravel", "overlandHomeward",
                           "overlandCamp", "checkArrivedHome"],
    "state_sea.cpp": ["enterSea", "seaDepth", "seaStep", "seaTravel", "seaHomeward",
                      "seaCamp", "checkArrivedSea", "enterCity", "leaveCity",
                      "cityExcursion"],
}
M2G = {m: g for g, ms in GROUPS.items() for m in ms}
KEEP_INLINE = {"SAVE_FILE", "rangeLo", "rangeHi"}

SIG_RE = re.compile(
    r'^(\s*)((?:static\s+)?([A-Za-z_][\w:<>,\s*&]*?))\s+([A-Za-z_]\w*)\s*\(')
KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "case", "else"}


def skip_string(text, i):
    """i at a quote char; return index just past the closing quote."""
    q = text[i]
    i += 1
    n = len(text)
    while i < n:
        if text[i] == "\\":
            i += 2
            continue
        if text[i] == q:
            return i + 1
        i += 1
    return n


def scan(text, start, open_ch, close_ch):
    """Return index of the matching close_ch for open_ch at start.
    String, char-literal and comment aware."""
    depth = 0
    i = start
    n = len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            if j < 0:
                return -1
            i = j
            continue
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            if j < 0:
                return -1
            i = j + 2
            continue
        if c == '"' or c == "'":
            i = skip_string(text, i)
            continue
        if c == open_ch:
            depth += 1
        elif c == close_ch:
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def find_sig_brace(text, start):
    """Index of the first '{' at paren-depth 0 scanning from start, or -1.
    Stops at a ';' at paren-depth 0 (plain declaration). String/comment aware.
    Paren depth carries across newlines, so multi-line signatures work."""
    d = 0
    k = start
    n = len(text)
    while k < n:
        c = text[k]
        if text.startswith("//", k):
            j = text.find("\n", k)
            if j < 0:
                return -1
            k = j
            continue
        if text.startswith("/*", k):
            j = text.find("*/", k + 2)
            if j < 0:
                return -1
            k = j + 2
            continue
        if c == '"' or c == "'":
            k = skip_string(text, k)
            continue
        if c == "(":
            d += 1
        elif c == ")":
            d -= 1
        elif c == ";" and d == 0:
            return -1
        elif c == "{" and d == 0:
            return k
        k += 1
    return -1


def parse_params(sig_text):
    """Split the parameter list (without outer parens) on top-level commas."""
    params = []
    cur = []
    depth = 0
    i = 0
    n = len(sig_text)
    while i < n:
        c = sig_text[i]
        if c == '"':
            j = skip_string(sig_text, i)
            cur.append(sig_text[i:j])
            i = j
            continue
        if c in "(<":
            depth += 1
        elif c in ")>":
            depth -= 1
        elif c == "," and depth == 0:
            params.append("".join(cur).strip())
            cur = []
            i += 1
            continue
        cur.append(c)
        i += 1
    tail = "".join(cur).strip()
    if tail:
        params.append(tail)
    return params


def strip_default(p):
    """Remove a '= default-arg' suffix from one parameter, string-aware."""
    depth = 0
    i = 0
    n = len(p)
    while i < n:
        c = p[i]
        if c == '"':
            i = skip_string(p, i)
            continue
        if c in "(<":
            depth += 1
        elif c in ")>":
            depth -= 1
        elif c == "=" and depth == 0:
            return p[:i].rstrip()
        i += 1
    return p


def strip_code(s):
    """Remove comments and neutralize strings, for brace-balance checks."""
    s = re.sub(r"//[^\n]*", "", s)
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    s = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
    s = re.sub(r"'(?:\\.|[^'\\])*'", "''", s)
    return s


def main():
    with open(SRC, "r", encoding="utf-8", errors="replace") as f:
        src = f.read()

    m = re.search(r"^struct AppState \{", src, re.M)
    if not m:
        sys.exit("cannot find 'struct AppState {'")
    struct_start = m.end()
    struct_text = src[struct_start:]
    lines = struct_text.split("\n")
    N = len(lines)

    # cumulative offset of each line start in struct_text
    offs = [0]
    for l in lines[:-1]:
        offs.append(offs[-1] + len(l) + 1)

    kept = {}       # orig line idx -> replacement text (kept lines)
    taken = []      # (name, cpp_text)

    i = 0
    while i < N:
        line = lines[i]
        sm = SIG_RE.match(line)
        if not sm:
            kept[i] = line
            i += 1
            continue
        indent = sm.group(1)
        ret = sm.group(3).strip()
        name = sm.group(4)
        if name in KEEP_INLINE or name in KEYWORDS:
            kept[i] = line
            i += 1
            continue
        static = re.match(r"\s*static\b", ret) is not None
        if static:
            ret = ret[len("static"):].strip()

        # locate the opening '{' of the body (multi-line signatures OK)
        lo = offs[i]
        bo = find_sig_brace(struct_text, lo)
        if bo < 0:
            # plain declaration, keep as-is
            kept[i] = line
            i += 1
            continue
        # line index containing the '{'
        j = i
        while offs[j] + len(lines[j]) < bo:
            j += 1
        close = scan(struct_text, bo, "{", "}")
        if close < 0:
            sys.exit("unbalanced braces in method %s" % name)

        # parameter list
        sig_region = struct_text[lo:bo]
        nm = sig_region.find(name)
        popen = sig_region.find("(", nm)
        if popen < 0:
            popen = sig_region.find("(")
        pclose = scan(struct_text, lo + popen, "(", ")")
        params_text = struct_text[lo + popen + 1:pclose]
        params = [strip_default(p) for p in parse_params(params_text.replace("\n", " "))]
        params_flat = ", ".join(p for p in params if p)

        # trailer between ')' and '{' (const, etc.)
        trailer = re.sub(r"//[^\n]*", "", struct_text[pclose + 1:bo]).strip()

        # body: '{' ... matching '}'
        body = struct_text[bo:close + 1]
        cppsig = "%sAppState::%s(%s)%s" % (
            (ret + " ") if ret else "", name, params_flat,
            (" " + trailer) if trailer else "")
        cpp_text = cppsig + body
        taken.append((name, cpp_text))

        # header declaration: original signature, '{' dropped, ';' appended
        decl = struct_text[lo:bo].rstrip() + ";"
        kept[i] = decl

        # skip past the closing '}' line
        cl = i
        while offs[cl] <= close:
            cl += 1
        cl -= 1
        i = cl + 1

    new_header = src[:struct_start] + "\n".join(kept[k] for k in sorted(kept))

    cpp_files = {g: [] for g in GROUPS}
    cpp_files["state_misc.cpp"] = []
    for name, cpp_text in taken:
        cpp_files[M2G.get(name, "state_misc.cpp")].append((name, cpp_text))

    report = []
    report.append("methods extracted: %d" % len(taken))
    for g in sorted(cpp_files):
        ms = cpp_files[g]
        report.append("%s: %d methods (%s)" % (g, len(ms), ", ".join(n for n, _ in ms)))

    bal = lambda s: strip_code(s).count("{") - strip_code(s).count("}")
    bad = 0
    for g, ms in cpp_files.items():
        for n, t in ms:
            b = bal(t)
            if b != 0:
                report.append("UNBALANCED %s in %s: %+d" % (n, g, b))
                bad += 1
    report.append("brace balance new header: %+d" % bal(new_header))
    hdr_bal = bal(new_header)
    if hdr_bal != 0 or bad:
        report.append("ABORT: balance check failed, nothing written")
        print("\n".join(report))
        sys.exit(1)

    # exact line accounting
    total = (src.count("\n") + 1)
    newl = new_header.count("\n") + 1
    cpp_total = len(cpp_files)  # one include line each
    for ms in cpp_files.values():
        for n, t in ms:
            cpp_total += t.count("\n") + 1
    report.append("orig %d lines -> header %d + cpp %d (+%d include lines)" %
                  (total, newl, cpp_total - len(cpp_files) - sum(len(ms) for ms in cpp_files.values()),
                   len(cpp_files) + sum(len(ms) for ms in cpp_files.values())))
    report.append("total lines out: %d (orig %d; small diff = decl ';' + blank lines + includes)"
                  % (newl + cpp_total, total))

    if not DRY:
        for g, ms in cpp_files.items():
            if not ms:
                continue
            body = '#include "appstate.h"\n\n' + "\n".join(
                "// ---- %s ----\n%s\n" % (n, t) for n, t in ms)
            with open(os.path.join("game", g), "w", encoding="utf-8") as f:
                f.write(body)
        with open(SRC, "w", encoding="utf-8") as f:
            f.write(new_header)
    report.append("DRY RUN - nothing written" if DRY else "WROTE game/appstate.h + %d cpp files"
                  % sum(1 for ms in cpp_files.values() if ms))
    print("\n".join(report))


main()
