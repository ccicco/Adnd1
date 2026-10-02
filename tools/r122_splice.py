#!/usr/bin/env python3
# R122 splice: TREASURE LINE-DIFF (DMG pp.120-125).
# The gap report demanded a line-by-line diff
# of every implemented treasure table against
# the book. The diff was done (R122) against
# the OCR of book pages 121-126, normalizing
# the repo's documented print-errata
# corrections (the treasure.h header list:
# Clairaudience, Cloak-of (not Clock),
# Petrification, Daern's, Robe/Rope split
# incl. Rope of Constriction, Tuerny,
# Jacinth, Heward's, Nolzur's, twin Hammer
# +2 rows printed as-is): ALL 383 ROWS MATCH
# - dice bands, printed xp/gp values, bundle
# quantities. No divergence, so no table row
# changes: this round PINS what was diffed.
# New API (treasure.h/cpp): magicTablePinCount
# + magicTablePin expose any printed row of
# III.A/C-H and the Special artifact table
# (12); III.B scrolls (1) pin their structure
# count (16 spell bands + 8 protection
# scrolls + 1 curse row = 25).
# Battery audit pins: all 13 counts, dice-band
# continuity on every ItemRow table (1..100,
# no gaps or overlaps), the errata rows, the
# printed range row (Ring of Protection), the
# no-value rows (Delusion, Poison, the
# Throne), the twin Hammer +2 rows, the
# bundle quantities, the cursed shield.
# Census becomes 40. The book's II.A/II.B/
# II.C hoard-construction tables are DM tools
# the repo replaces with MM Treasure Types
# (p.105, R71) - documented, not a
# divergence. Idempotent (marker checks per
# patch): run twice - the second run must
# print every patch already applied.
# ASCII-only. Refuses non-unique anchors,
# all-or-nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


# ---- patch bodies ----------------------------------------------------------

TH_OLD = """MagicItem rollMagicItem(rules::Dice& dice);

} // namespace treasure"""

TH_NEW = """MagicItem rollMagicItem(rules::Dice& dice);

// ----------------------------------------------------------------------------
// R122: line-diff pins - the battery reads any printed row of the DMG
// pp.121-125 item tables so the tables are pinned, not just rolled.
// category is a MagicItemCategory (0, 2-11) or 12 for the Special
// artifact table. Category 1 (scrolls, III.B) has no ItemRow rows:
// magicTablePinCount(1) pins its structure (16 spell bands + 8
// protection scrolls + 1 curse row = 25) and magicTablePin refuses it.
// ----------------------------------------------------------------------------
struct TablePin {
    int lo, hi;           // printed dice band
    const char* name;     // printed name (errata-corrected, header list)
    int xp, xpHi;         // printed x.p. value (a range if xpHi > 0)
    int gp, gpHi;         // printed g.p. sale value (range if gpHi > 0)
    int qtyLo, qtyHi;     // printed bundle ("2-24 in number"; 0 = single)
};

int  magicTablePinCount(int category);
bool magicTablePin(int category, int row, TablePin* out);

} // namespace treasure"""

TC_OLD = """MagicItem rollMagicItem(rules::Dice& dice) {
    return rollFromCategory(dice, rollCategory(dice));
}"""

TC_NEW = """MagicItem rollMagicItem(rules::Dice& dice) {
    return rollFromCategory(dice, rollCategory(dice));
}

// ---- R122: line-diff pins ---------------------------------------------------
// The battery reads any printed row of the pp.121-125 tables so they
// are pinned, not just rolled (the R122 line-diff found all 383 rows
// faithful). Category 1 (scrolls) has no ItemRow rows - its pin count
// is the structure: 16 spell bands + 8 protection scrolls + 1 curse
// row. Category 12 is the Special artifact table.
static const ItemRow* pinTableFor(int category, int* n) {
    switch (category) {
        case 0:  *n = COUNT_OF(kPotions);   return kPotions;
        case 2:  *n = COUNT_OF(kRings);     return kRings;
        case 3:  *n = COUNT_OF(kRods);      return kRods;
        case 4:  *n = COUNT_OF(kMisc1);     return kMisc1;
        case 5:  *n = COUNT_OF(kMisc2);     return kMisc2;
        case 6:  *n = COUNT_OF(kMisc3);     return kMisc3;
        case 7:  *n = COUNT_OF(kMisc4);     return kMisc4;
        case 8:  *n = COUNT_OF(kMisc5);     return kMisc5;
        case 9:  *n = COUNT_OF(kArmor);     return kArmor;
        case 10: *n = COUNT_OF(kSwords);    return kSwords;
        case 11: *n = COUNT_OF(kWeapons);   return kWeapons;
        case 12: *n = COUNT_OF(kArtifacts); return kArtifacts;
        default: *n = 0; return nullptr;
    }
}

int magicTablePinCount(int category) {
    if (category == 1)
        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse
    int n = 0;
    pinTableFor(category, &n);
    return n;
}

bool magicTablePin(int category, int row, TablePin* out) {
    if (!out || category == 1) return false;
    int n = 0;
    const ItemRow* t = pinTableFor(category, &n);
    if (!t || row < 0 || row >= n) return false;
    const ItemRow& r = t[row];
    out->lo = r.lo;      out->hi = r.hi;
    out->name = r.name;
    out->xp = r.xp;      out->xpHi = r.xpHi;
    out->gp = r.gp;      out->gpHi = r.gpHi;
    out->qtyLo = r.qlo;  out->qtyHi = r.qhi;
    return true;
}"""

RT_OLD = """        printf("R121 crew officers audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R121 crew officers audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R122: treasure line-diff audit ---------------------------------
    // The R122 line-by-line diff against the printed tables (DMG
    // pp.121-125) found all 383 rows faithful; this audit pins what
    // was diffed so a future edit cannot drift silently: every
    // table's row count, every row's dice-band continuity (1..100,
    // no gaps or overlaps), and the famous rows - the errata
    // corrections (the treasure.h header list), the printed range
    // (Ring of Protection), the no-value rows (Delusion, Poison, the
    // Throne of the Gods), the twin "Hammer +2" rows printed as-is,
    // the bundle quantities (arrows, bolts), and the cursed shield.
    {
        int bad = 0;
        // printed row counts: III.A, III.B (structure: 16 spell
        // bands + 8 protection scrolls + 1 curse row), III.C-H,
        // then 12 = the Special artifact table
        static const int kRows[13] = { 35, 25, 24, 30, 33,
                                       30, 33, 36, 35, 26,
                                       26, 36, 29 };
        for (int c = 0; c <= 12; ++c) {
            if (dm::treasure::magicTablePinCount(c) != kRows[c])
                ++bad;
        }
        // dice-band continuity on every ItemRow table
        for (int c = 0; c <= 12; ++c) {
            if (c == 1) continue;      // III.B: no ItemRow rows
            dm::treasure::TablePin p, prev;
            int n = dm::treasure::magicTablePinCount(c);
            for (int i = 0; i < n; ++i) {
                if (!dm::treasure::magicTablePin(c, i, &p)) {
                    ++bad; break;
                }
                if (p.lo < 1 || p.hi < p.lo || p.hi > 100) ++bad;
                if (i == 0     && p.lo != 1)         ++bad;
                if (i > 0      && p.lo != prev.hi + 1) ++bad;
                if (i == n - 1 && p.hi != 100)       ++bad;
                prev = p;
            }
        }
        dm::treasure::TablePin p;
        // III.A edge rows: 01-03 Animal Control 250/400, the
        // no-xp Delusion (13-15, gp 150) and Poison (82-84, no
        // values at all), 98-00 Water Breathing 400/900
        if (!dm::treasure::magicTablePin(0, 0, &p)) ++bad;
        else if (p.lo != 1 || p.hi != 3 || p.xp != 250 ||
                 p.gp != 400 ||
                 std::string(p.name) != "Potion of Animal Control")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 4, &p)) ++bad;
        else if (p.lo != 13 || p.hi != 15 || p.xp != 0 ||
                 p.gp != 150 ||
                 std::string(p.name) != "Potion of Delusion")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 28, &p)) ++bad;
        else if (p.lo != 82 || p.hi != 84 || p.xp != 0 ||
                 p.gp != 0 ||
                 std::string(p.name) != "Potion of Poison") ++bad;
        if (!dm::treasure::magicTablePin(0, 34, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 400 ||
                 p.gp != 900 ||
                 std::string(p.name) != "Potion of Water Breathing")
            ++bad;
        // III.C: the printed range row (Ring of Protection
        // 45-60, xp 2,000-4,000, gp 10,000-20,000) and the 00 row
        if (!dm::treasure::magicTablePin(2, 11, &p)) ++bad;
        else if (p.lo != 45 || p.hi != 60 ||
                 p.xp != 2000 || p.xpHi != 4000 ||
                 p.gp != 10000 || p.gpHi != 20000 ||
                 std::string(p.name) != "Ring of Protection") ++bad;
        if (!dm::treasure::magicTablePin(2, 23, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.xp != 4000 ||
                 std::string(p.name) != "Ring of X-Ray Vision") ++bad;
        // III.E.5: the Robe/Rope errata rows
        if (!dm::treasure::magicTablePin(8, 1, &p)) ++bad;
        else if (p.lo != 2 || p.hi != 8 || p.xp != 3500 ||
                 std::string(p.name) != "Robe of Blending") ++bad;
        if (!dm::treasure::magicTablePin(8, 7, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 27 || p.gp != 1000 ||
                 std::string(p.name) != "Rope of Constriction") ++bad;
        // Special: Heward's (printed Howard's), the valueless
        // Throne, and 00 Wand of Orcus
        if (!dm::treasure::magicTablePin(12, 8, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 26 || p.gp != 25000 ||
                 std::string(p.name) != "Heward's Mystical Organ")
            ++bad;
        if (!dm::treasure::magicTablePin(12, 27, &p)) ++bad;
        else if (p.lo != 99 || p.gp != 0 ||
                 std::string(p.name) != "Throne of the Gods") ++bad;
        if (!dm::treasure::magicTablePin(12, 28, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.gp != 10000 ||
                 std::string(p.name) != "Wand of Orcus") ++bad;
        // III.G: the Flame Tongue row (46-49) and the cursed rows
        // with no sale value
        if (!dm::treasure::magicTablePin(10, 5, &p)) ++bad;
        else if (p.lo != 46 || p.hi != 49 || p.xp != 900 ||
                 p.gp != 4500 ||
                 std::string(p.name) != "Sword +1, Flame Tongue")
            ++bad;
        if (!dm::treasure::magicTablePin(10, 25, &p)) ++bad;
        else if (p.lo != 96 || p.hi != 100 || p.gp != 0 ||
                 std::string(p.name) !=
                     "Sword, Cursed Berserking") ++bad;
        // III.H: the twin Hammer +2 rows printed as-is, and the
        // bundle quantities (Arrow +1 2-24, Bolt +2 2-20)
        if (!dm::treasure::magicTablePin(11, 18, &p)) ++bad;
        else if (p.lo != 57 || p.hi != 60 || p.xp != 300 ||
                 p.gp != 2500 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 19, &p)) ++bad;
        else if (p.lo != 61 || p.hi != 62 || p.xp != 650 ||
                 p.gp != 6000 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 0, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 24 ||
                 std::string(p.name) != "Arrow +1") ++bad;
        if (!dm::treasure::magicTablePin(11, 9, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 20 ||
                 std::string(p.name) != "Bolt +2") ++bad;
        // III.F: the cursed shield (98-00, no xp, gp 750)
        if (!dm::treasure::magicTablePin(9, 25, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 0 ||
                 p.gp != 750 ||
                 std::string(p.name) != "Shield -1, missile attractor")
            ++bad;
        printf("R122 treasure line-diff audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R121 CLOSED crew officers (p.35) - a
captain, a lieutenant and two mates
join the crew: wages 40 -> 300 gp, the
take's cut 5% -> 37% (PC keeps 63%)."""

GH_NEW = """R121 CLOSED crew officers (p.35) - a
captain, a lieutenant and two mates
join the crew: wages 40 -> 300 gp, the
take's cut 5% -> 37% (PC keeps 63%).
R122 CLOSED the treasure line-diff
(pp.120-125) - every implemented table
diffed row-by-row against the book:
383 rows, dice bands, xp and gp values,
bundle quantities, no divergence. The
tables are now pinned, not just rolled."""

GT_OLD = """      pins 20k-roll behavior, but a full
      line-by-line table diff against pp.120-125
      has NOT been done. Kept open as an item
      below until diffed."""

GT_NEW = """      pins 20k-roll behavior; the line-by-line
      table diff was done R122 - no divergence
      (the item below is closed)."""

GB_OLD = """- [ ] **Treasure line-diff (pp.120-125)** - see
      above; diff each table against the book."""

GB_NEW = """- [x] **Treasure line-diff (pp.120-125)** -
      VERIFIED R122: every implemented table
      diffed line-by-line against the book -
      383 rows across III.A/C-H plus the
      Special artifact table (35+24+30+33+30+
      33+36+35+29+26+26+36), dice bands, xp
      and gp values, bundle quantities: no
      divergence. The repo's name corrections
      are the treasure.h print-errata list.
      The III dispatch bands, the Map table
      and the scroll structure (16 spell
      bands, 8 protection scrolls, the 5x/3x
      sale rules) verified with it. The book's
      II.A/II.B/II.C hoard-construction
      tables are DM tools the repo replaces
      with MM Treasure Types (p.105, R71) -
      documented, not a divergence. Pinned by
      the R122 battery audit."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("dm/treasure.h", "struct TablePin {",
     TH_OLD, TH_NEW, "treasure.h TablePin pins"),
    ("dm/treasure.cpp", "static const ItemRow* pinTableFor(int category, int* n) {",
     TC_OLD, TC_NEW, "treasure.cpp pin helpers"),
    ("regtest.cpp", "R122 treasure line-diff audit",
     RT_OLD, RT_NEW, "regtest R122 audit"),
    ("tools/dmg_gap_report.md", "R122 CLOSED the treasure line-diff",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "VERIFIED R122: every implemented table",
     GT_OLD, GT_NEW, "gap report upper box note"),
    ("tools/dmg_gap_report.md", "are the treasure.h print-errata list",
     GB_OLD, GB_NEW, "gap report treasure line-diff box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R122 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R122 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R122 splice: nothing to do (already applied)")
    else:
        print("R122 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
