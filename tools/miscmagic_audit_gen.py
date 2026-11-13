#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/miscmagic_audit_gen.py
# R1027 (the A2 de-wire): generate rules/audits/r1027_misc_magic_registry.h
# from the 166 misc magic item defs at content/magic_items/<letter>/.
#
# The generated fragment is the WALKING AUDIT replacement for the 23
# retired prose pin audits (boneyard/dmg/): it loads every def live
# through items::MiscItemRegistry (the MonsterRegistry Lua C API
# pattern) and asserts the full population - keys and names, the
# letter census, sources, every kMisc row (cross-checked against the
# live dm::treasure row-count pins), all 1329 scalar pins, all 123
# table walkers, and the 16 nested subs.
#
# The expected values are read from the defs themselves, so the audit
# proves the LOADER round-trips the defs byte-faithfully; the defs are
# in turn byte-gated against the boneyard part headers by
# tools/miscmagic2lua.py in the same session. Two independent layers,
# same discipline as the retired pin audits.
#
# Pure stdlib. STRICT: any schema drift, count drift, or parse surprise
# dies loudly with a RED message. Run from the repo root:
#   python3 tools/miscmagic_audit_gen.py
# ============================================================================

import os
import sys

OFF = "\033[0m"
RED = "\033[31m"
GREEN = "\033[32m"


def FAIL(msg):
    print(RED + "AUDIT-GEN RED: " + msg + OFF)
    sys.exit(1)


# ---- the lua subset lexer ------------------------------------------------
# The defs are one tool's uniform output; the grammar is fixed:
# strings ("..." with \" and \\ escapes, joined by ..), integers,
# identifiers, { } = , and -- comments.

def lex(src, where):
    toks = []
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if c in " \t\r\n":
            i += 1
            continue
        if c == "-" and i + 1 < n and src[i + 1] == "-":
            j = src.find("\n", i)
            i = n if j < 0 else j + 1
            continue
        if c == '"':
            i += 1
            buf = []
            while i < n:
                if src[i] == "\\":
                    if i + 1 >= n:
                        FAIL("%s: truncated escape" % where)
                    e = src[i + 1]
                    buf.append({'"': '"', "\\": "\\"}.get(e, e))
                    i += 2
                    continue
                if src[i] == '"':
                    break
                buf.append(src[i])
                i += 1
            else:
                FAIL("%s: unterminated string" % where)
            i += 1
            toks.append(("str", "".join(buf)))
            continue
        if c == "-" and i + 1 < n and src[i + 1].isdigit():
            j = i + 1
            while j < n and src[j].isdigit():
                j += 1
            toks.append(("num", int(src[i:j])))
            i = j
            continue
        if c.isdigit():
            j = i
            while j < n and src[j].isdigit():
                j += 1
            toks.append(("num", int(src[i:j])))
            i = j
            continue
        if c == "." and src[i:i + 2] == "..":
            toks.append(("cat", ".."))
            i += 2
            continue
        if c.isalpha() or c == "_":
            j = i
            while j < n and (src[j].isalnum() or src[j] == "_"):
                j += 1
            toks.append(("id", src[i:j]))
            i = j
            continue
        if c in "{}=,":
            toks.append((c, c))
            i += 1
            continue
        FAIL("%s: unexpected character %r at offset %d" % (where, c, i))
    toks.append(("eof", None))
    return toks


# ---- the lua subset parser ----------------------------------------------
# A parsed table: (fields dict of string keys, items list for the
# positional/array part). Values: str / int / table.

class Table:
    def __init__(self):
        self.fields = {}
        self.items = []


class Parser:
    def __init__(self, toks, where):
        self.toks = toks
        self.i = 0
        self.where = where

    def peek(self):
        return self.toks[self.i]

    def next(self):
        t = self.toks[self.i]
        self.i += 1
        return t

    def expect(self, kind):
        t = self.next()
        if t[0] != kind:
            FAIL("%s: expected %s, got %r" % (self.where, kind, t[1]))
        return t

    def value(self):
        t = self.peek()
        if t[0] == "str":
            s = self.next()[1]
            while self.peek()[0] == "cat":
                self.next()
                s += self.expect("str")[1]
            return s
        if t[0] == "num":
            return self.next()[1]
        if t[0] == "{":
            return self.table()
        FAIL("%s: bad value token %r" % (self.where, t[1]))

    def table(self):
        self.expect("{")
        t = Table()
        while True:
            k = self.peek()
            if k[0] == "}":
                self.next()
                return t
            if k[0] == "id" and self.toks[self.i + 1][0] == "=":
                name = self.next()[1]
                self.next()                     # =
                t.fields[name] = self.value()
            else:
                t.items.append(self.value())
            if self.peek()[0] == ",":
                self.next()
            elif self.peek()[0] == "}":
                self.next()
                return t
            else:
                FAIL("%s: expected , or } , got %r"
                     % (self.where, self.peek()[1]))


DEF_KEYS = {"key", "name", "rows", "sources", "pins", "tables", "subs"}
ROW_KEYS = {"name", "set", "band", "xp", "xp_hi", "gp", "gp_hi", "qty"}
SRC_KEYS = {"part", "round"}
PIN_KEYS = {"name", "value", "comment"}
TAB_KEYS = {"name", "comment", "clamp_hi", "values"}
SUB_KEYS = {"key", "name", "sources", "pins", "tables"}


def field(t, k, where, required=True):
    if k not in t.fields:
        if required:
            FAIL("%s: missing field %r" % (where, k))
        return None
    return t.fields[k]


def check_keys(t, allowed, where):
    for k in t.fields:
        if k not in allowed:
            FAIL("%s: unknown key %r" % (where, k))


def parse_def_table(t, where, allow_rows):
    check_keys(t, DEF_KEYS if allow_rows else SUB_KEYS, where)
    d = {}
    d["key"] = field(t, "key", where)
    d["name"] = field(t, "name", where)
    rows = field(t, "rows", where, required=False)
    d["rows"] = []
    if rows is not None:
        if not allow_rows:
            FAIL("%s: a sub must not carry rows" % where)
        for i, r in enumerate(rows.items):
            w = "%s rows[%d]" % (where, i)
            if not isinstance(r, Table):
                FAIL("%s: not a table" % w)
            check_keys(r, ROW_KEYS, w)
            band = field(r, "band", w).items
            qty = field(r, "qty", w).items
            if len(band) != 2 or len(qty) != 2:
                FAIL("%s: band/qty not 2-element" % w)
            d["rows"].append({
                "name": field(r, "name", w), "set": field(r, "set", w),
                "band": (band[0], band[1]), "qty": (qty[0], qty[1]),
                "xp": field(r, "xp", w), "xp_hi": field(r, "xp_hi", w),
                "gp": field(r, "gp", w), "gp_hi": field(r, "gp_hi", w)})
    d["sources"] = []
    for i, s in enumerate(field(t, "sources", where).items):
        w = "%s sources[%d]" % (where, i)
        if not isinstance(s, Table):
            FAIL("%s: not a table" % w)
        check_keys(s, SRC_KEYS, w)
        d["sources"].append((field(s, "part", w), field(s, "round", w)))
    d["pins"] = []
    for i, p in enumerate(field(t, "pins", where).items):
        w = "%s pins[%d]" % (where, i)
        if not isinstance(p, Table):
            FAIL("%s: not a table" % w)
        check_keys(p, PIN_KEYS, w)
        d["pins"].append((field(p, "name", w), field(p, "value", w)))
    d["tables"] = []
    for i, tb in enumerate(field(t, "tables", where).items):
        w = "%s tables[%d]" % (where, i)
        if not isinstance(tb, Table):
            FAIL("%s: not a table" % w)
        check_keys(tb, TAB_KEYS, w)
        vals = field(tb, "values", w).items
        for v in vals:
            if not isinstance(v, int):
                FAIL("%s: a value is not an integer" % w)
        clamp = field(tb, "clamp_hi", w, required=False)
        d["tables"].append({"name": field(tb, "name", w),
                            "values": vals, "clamp": clamp})
    d["subs"] = []
    subs = field(t, "subs", where, required=False)
    if subs is not None:
        for i, s in enumerate(subs.items):
            w = "%s subs[%d]" % (where, i)
            if not isinstance(s, Table):
                FAIL("%s: not a table" % w)
            d["subs"].append(parse_def_table(s, w, False))
    return d


def load_defs():
    root = os.path.join("content", "magic_items")
    if not os.path.isdir(root):
        FAIL("missing %s (run from the repo root)" % root)
    defs = {}
    letters = {}
    for letter in sorted(os.listdir(root)):
        d = os.path.join(root, letter)
        if not os.path.isdir(d):
            FAIL("%s is not a letter dir" % d)
        for fn in sorted(os.listdir(d)):
            if not fn.endswith(".lua"):
                FAIL("stray non-lua file %s/%s" % (d, fn))
            stem = fn[:-4]
            if stem[0] != letter:
                FAIL("%s is in the wrong letter dir" % fn)
            if stem in defs:
                FAIL("duplicate def key %s" % stem)
            where = "%s/%s" % (letter, fn)
            src = open(os.path.join(d, fn)).read()
            toks = lex(src, where)
            p = Parser(toks, where)
            p.expect("id")           # return
            t = p.table()
            if p.peek()[0] != "eof":
                FAIL("%s: trailing tokens" % where)
            dd = parse_def_table(t, where, True)
            if dd["key"] != stem:
                FAIL("%s: key %r != file stem" % (where, dd["key"]))
            defs[stem] = dd
            letters.setdefault(letter, []).append(stem)
    return defs, letters


# ---- the emission --------------------------------------------------------

def cstr(s):
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def emit_fragment(defs, letters):
    order = sorted(defs)
    L = []
    L.append("    // ---- R1027: the misc magic item registry audit ----")
    L.append("    // GENERATED by tools/miscmagic_audit_gen.py - DO NOT")
    L.append("    // hand-edit. The 166 defs at content/magic_items/<letter>/")
    L.append("    // loaded live by items::MiscItemRegistry (the R71")
    L.append("    // MonsterRegistry pattern), asserted in full. This block")
    L.append("    // replaces the 23 retired prose pin audits (boneyard/dmg)")
    L.append("    // as the walking audit of the misc magic record.")
    L.append("    {")
    L.append("        items::MiscItemRegistry mreg;")
    L.append("        int perLetter[26] = {0};")
    L.append("        int loaded = 0;")
    L.append("        for (char c = 'a'; c <= 'z'; ++c) {")
    L.append('            std::string dir = "content/magic_items/";')
    L.append("            dir.push_back(c);")
    L.append("            int m = mreg.loadDirectory(dir);")
    L.append("            if (m > 0) { loaded += m; perLetter[c - 'a'] = m; }")
    L.append("        }")

    L.append("        // the total pin count helper (a lambda: this")
    L.append("        // fragment is included inside a function body)")
    L.append("        auto pinCount = [](const items::MiscItemRegistry&"
             " mreg) {")
    L.append("            int n = 0;")
    L.append("            for (const auto& kv : mreg.all()) {")
    L.append("                n += (int)kv.second.pins.size();")
    L.append("                for (const auto& s : kv.second.subs)")
    L.append("                    n += (int)s.pins.size();")
    L.append("            }")
    L.append("            return n;")
    L.append("        };")

    # [1] load
    L.append("        int bad = 0;")
    L.append("        if (loaded != 166) ++bad;")
    L.append("        if (mreg.errors().size() != 0) ++bad;")
    L.append("        for (const auto& e : mreg.errors())")
    L.append('            printf("ERR: %s\\n", e.c_str());')
    L.append('        printf("R1027 misc magic registry load audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [2] letters
    L.append("        bad = 0;")
    for letter in sorted(letters):
        want = len(letters[letter])
        L.append('        if (perLetter[%d] != %d) ++bad;   // %s'
                 % (ord(letter) - ord("a"), want, letter))
    L.append("        if (loaded != 166) ++bad;")
    L.append('        printf("R1027 misc magic registry letters audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [3] the full key/name roster (all() size catches extras)
    L.append("        bad = 0;")
    L.append("        if ((int)mreg.all().size() != 166) ++bad;")
    for k in order:
        d = defs[k]
        L.append("        {")
        L.append("            const auto* d = mreg.find(%s);" % cstr(k))
        L.append("            if (!d || d->name != %s) ++bad;"
                 % cstr(d["name"]))
        L.append("        }")
    L.append('        printf("R1027 misc magic registry roster audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [4] sources
    L.append("        bad = 0;")
    for k in order:
        d = defs[k]
        L.append("        {")
        L.append("            const auto* d = mreg.find(%s);" % cstr(k))
        L.append("            if (!d) { ++bad; }")
        L.append("            else {")
        if d["sources"]:
            L.append("                static const int kSrc[%d] = { %s };"
                     % (2 * len(d["sources"]),
                        ", ".join("%d, %d" % s for s in d["sources"])))
            L.append("                if ((int)d->sources.size() != %d) ++bad;"
                     % len(d["sources"]))
            L.append("                else for (int i = 0; i < %d; ++i) {"
                     % len(d["sources"]))
            L.append("                    if (d->sources[i].first != kSrc[2*i]"
                     " || d->sources[i].second != kSrc[2*i+1]) ++bad;")
            L.append("                }")
        else:
            L.append("                if (!d->sources.empty()) ++bad;")
        L.append("            }")
        L.append("        }")
    L.append('        printf("R1027 misc magic registry sources audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [5] rows + the live treasure cross-check
    L.append("        bad = 0;")
    L.append("        int rowsMisc[6] = { 0, 0, 0, 0, 0, 0 };")
    for k in order:
        d = defs[k]
        L.append("        {")
        L.append("            const auto* d = mreg.find(%s);" % cstr(k))
        L.append("            if (!d) { ++bad; }")
        L.append("            else {")
        if d["rows"]:
            L.append("                static const int kRow[%d][8] = {"
                     % len(d["rows"]))
            for r in d["rows"]:
                L.append("                    { %d, %d, %d, %d, %d, %d, %d,"
                         " %d },"
                         % (r["band"][0], r["band"][1], r["xp"], r["xp_hi"],
                            r["gp"], r["gp_hi"], r["qty"][0], r["qty"][1]))
            L.append("                };")
            L.append("                static const char* const kRowName[%d] = {"
                     % len(d["rows"]))
            for r in d["rows"]:
                L.append("                    %s," % cstr(r["name"]))
            L.append("                };")
            L.append("                static const int kRowSet[%d] = { %s };"
                     % (len(d["rows"]),
                        ", ".join(str(int(r["set"][-1]))
                                  for r in d["rows"])))
            L.append("                if ((int)d->rows.size() != %d) ++bad;"
                     % len(d["rows"]))
            L.append("                else for (int i = 0; i < %d; ++i) {"
                     % len(d["rows"]))
            L.append("                    const auto& r = d->rows[i];")
            L.append("                    if (r.name != kRowName[i]) ++bad;")
            L.append("                    if (r.set[5] - '0' != kRowSet[i])"
                     " ++bad;")
            L.append("                    if (r.bandLo != kRow[i][0]"
                     " || r.bandHi != kRow[i][1]"
                     " || r.xp != kRow[i][2] || r.xpHi != kRow[i][3]"
                     " || r.gp != kRow[i][4] || r.gpHi != kRow[i][5]"
                     " || r.qtyLo != kRow[i][6]"
                     " || r.qtyHi != kRow[i][7]) ++bad;")
            L.append("                    ++rowsMisc[r.set[5] - '0'];")
            L.append("                }")
        else:
            L.append("                if (!d->rows.empty()) ++bad;")
        L.append("            }")
        L.append("        }")
    L.append("        // the live dm::treasure kMisc row counts: the defs")
    L.append("        // mirror the printed tables (kMisc1 minus the")
    L.append("        // Artifact-or-Relic row, the others exact).")
    L.append("        if (rowsMisc[1] != rules::m1RowCount() - 1) ++bad;")
    for n in range(2, 6):
        L.append("        if (rowsMisc[%d] != rules::m%dRowCount()) ++bad;"
                 % (n, n))
    L.append('        printf("R1027 misc magic registry rows audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [6] pins (defs + subs)
    L.append("        bad = 0;")
    npins = 0
    L.append("        static const struct { const char* key; int sub;"
             " const char* name; long long value; } kPin[] = {")
    for k in order:
        d = defs[k]
        for name, val in d["pins"]:
            L.append("            { %s, -1, %s, %d }," %
                     (cstr(k), cstr(name), val))
            npins += 1
        for si, sub in enumerate(d["subs"]):
            for name, val in sub["pins"]:
                L.append("            { %s, %d, %s, %d }," %
                         (cstr(k), si, cstr(name), val))
                npins += 1
    L.append("        };")
    L.append("        for (const auto& e : kPin) {")
    L.append("            const auto* d = mreg.find(e.key);")
    L.append("            if (!d) { ++bad; continue; }")
    L.append("            if (e.sub < 0) {")
    L.append("                bool hit = false;")
    L.append("                for (const auto& p : d->pins)")
    L.append("                    if (p.name == e.name && p.value == e.value)")
    L.append("                        hit = true;")
    L.append("                if (!hit) ++bad;")
    L.append("            } else {")
    L.append("                if (e.sub >= (int)d->subs.size()) { ++bad;"
             " continue; }")
    L.append("                bool hit = false;")
    L.append("                for (const auto& p : d->subs[e.sub].pins)")
    L.append("                    if (p.name == e.name && p.value == e.value)")
    L.append("                        hit = true;")
    L.append("                if (!hit) ++bad;")
    L.append("            }")
    L.append("        }")
    L.append("        if (pinCount(mreg) != %d) ++bad;" % npins)
    L.append('        printf("R1027 misc magic registry pins audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [7] tables (defs + subs)
    L.append("        bad = 0;")
    ntabs = 0
    for k in order:
        d = defs[k]
        for ti, tb in enumerate(d["tables"]):
            emit_table_assert(L, k, -1, ti, tb, "d")
            ntabs += 1
        for si, sub in enumerate(d["subs"]):
            for ti, tb in enumerate(sub["tables"]):
                emit_table_assert(L, k, si, ti, tb, "&d->subs[%d]" % si)
                ntabs += 1
    L.append('        printf("R1027 misc magic registry tables audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")

    # [8] subs
    L.append("        bad = 0;")
    nsubs = 0
    for k in order:
        d = defs[k]
        if not d["subs"]:
            continue
        L.append("        {")
        L.append("            const auto* d = mreg.find(%s);" % cstr(k))
        L.append("            if (!d) { ++bad; }")
        L.append("            else {")
        L.append("                if ((int)d->subs.size() != %d) ++bad;"
                 % len(d["subs"]))
        L.append("                else {")
        for si, sub in enumerate(d["subs"]):
            L.append("                    if (d->subs[%d].key != %s"
                     " || d->subs[%d].name != %s) ++bad;"
                     % (si, cstr(sub["key"]), si, cstr(sub["name"])))
            nsubs += 1
        L.append("                }")
        L.append("            }")
        L.append("        }")
    L.append('        printf("R1027 misc magic registry subs audit: bad %d\\n",')
    L.append("               bad);")
    L.append("        if (bad) return 1;")
    L.append("    }")
    return "\n".join(L) + "\n", npins, ntabs, nsubs


def emit_table_assert(L, key, sub, ti, tb, owner):
    tag = "kT%s_%d" % (key[:24], ti) + ("_s%d" % sub if sub >= 0 else "")
    L.append("        {")
    L.append("            const auto* d = mreg.find(%s);" % cstr(key))
    L.append("            if (!d) { ++bad; }")
    L.append("            else {")
    L.append("                const auto* owner = %s;" % owner)
    L.append("                const items::MiscItemTable* t = nullptr;")
    L.append("                for (const auto& x : owner->tables)")
    L.append("                    if (x.name == %s) t = &x;" % cstr(tb["name"]))
    L.append("                if (!t) ++bad;")
    L.append("                else {")
    L.append("                    static const long long %s[%d] = { %s };"
             % (tag, len(tb["values"]), ", ".join(str(v)
                                                  for v in tb["values"])))
    L.append("                    if ((int)t->values.size() != %d) ++bad;"
             % len(tb["values"]))
    L.append("                    else for (int j = 0; j < %d; ++j)" %
             len(tb["values"]))
    L.append("                        if (t->values[j] != %s[j]) ++bad;" % tag)
    if tb["clamp"] is not None:
        L.append("                    if (!t->hasClamp"
                 " || t->clampHi != %d) ++bad;" % tb["clamp"])
    else:
        L.append("                    if (t->hasClamp) ++bad;")
    L.append("                }")
    L.append("            }")
    L.append("        }")


# A generated helper: the total pin count across all defs+subs, so a
# def that gained or lost a pin shifts the total and dies. Emitted as
# a lambda INSIDE the audit block (the fragment is included in a
# function body - no file-scope helpers allowed).
def main():
    if not os.path.isfile("regtest.cpp"):
        FAIL("run from the repo root (regtest.cpp not found in cwd)")
    defs, letters = load_defs()
    if len(defs) != 166:
        FAIL("expected 166 defs, found %d" % len(defs))

    nsub = sum(len(defs[k]["subs"]) for k in defs)
    npins_total = sum(len(defs[k]["pins"])
                      + sum(len(s["pins"]) for s in defs[k]["subs"])
                      for k in defs)
    ntab_total = sum(len(defs[k]["tables"])
                     + sum(len(s["tables"]) for s in defs[k]["subs"])
                     for k in defs)
    nrow_total = sum(len(defs[k]["rows"]) for k in defs)
    if nsub != 16:
        FAIL("expected 16 subs, found %d" % nsub)
    if npins_total != 1329:
        FAIL("expected 1329 pins, found %d" % npins_total)
    if ntab_total != 123:
        FAIL("expected 123 tables, found %d" % ntab_total)
    if nrow_total != 166:
        FAIL("expected 166 kMisc rows, found %d" % nrow_total)

    body, npins, ntabs, nsubs = emit_fragment(defs, letters)
    if npins != npins_total or ntabs != ntab_total or nsubs != nsub:
        FAIL("emission count drift")

    frag = ("// ====================================================================\n"
            "// Adnd1 - rules/audits/r1027_misc_magic_registry.h\n"
            "// GENERATED by tools/miscmagic_audit_gen.py (R1027) - DO NOT\n"
            "// hand-edit; the generator is the only writer.\n"
            "// ====================================================================\n"
            + body)
    out = os.path.join("rules", "audits", "r1027_misc_magic_registry.h")
    with open(out, "w") as f:
        f.write(frag)

    print(GREEN + "misc magic registry audit: GENERATED" + OFF)
    print("  defs: %d (+%d subs nested)" % (len(defs), nsub))
    print("  letters: %d" % len(letters))
    print("  sources asserted, rows: %d, pins: %d, tables: %d"
          % (nrow_total, npins, ntabs))
    print("  wrote: %s (%d lines)" % (out, frag.count("\n")))


if __name__ == "__main__":
    main()
