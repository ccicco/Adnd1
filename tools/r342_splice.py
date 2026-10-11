#!/usr/bin/env python3
# R342: the UA SPELL TABLES pin
# round, part 2 - the magic-user
# spells tables (1st-5th columns,
# 35/30/28/28/28 readable names,
# every garble position-decoded by
# alphabetical continuity) and the
# illusionist spell table (5/4/1);
# the 6th-level column, the fragment
# cells and the illusionist cantrip
# and 3rd-6th columns are OCR-lost -
# the item closes, the holes stay
# pending the PDF. Pin-era pattern
# (R322). Idempotent; run twice.
import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R341 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R341 landed 2026-10-11: commit',
    '  d619290, census 268, the UA spell',
    '  tables pin round, part 1',
    '  (rules/uaspelltables.h): the',
    '  cleric 1st-3rd table (20 rows,',
    '  seam-verified against the R80',
    '  registry), the cleric 4th-7th',
    '  fragments, the druid tables (the',
    '  readable rows seam-decoded as the',
    '  1st-level roster) and the MU',
    '  cantrip table (64 names); the MU',
    '  spells tables and the illusionist',
    '  table stayed OCR-scrambled -',
    '  part 2 next. GREEN on the first',
    '  paste. No new lessons.',
])
s = rd(SD)
if 'R341 landed 2026-10-11' in s:
    already.append('seed: the R341 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R341 record')
s = rd(SD)
assert s.count('R341 landed 2026-10-11') == 1,     'a entry'
assert s.count('R340 landed 2026-10-11') == 1,     'a r340 kept'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('R338 landed 2026-10-11') == 1,     'a r338 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaspelltables2.h ----
US = 'rules/uaspelltables2.h'
if os.path.exists(US) and 'R342' in rd(US):
    already.append('uaspelltables2.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaspelltables2.h
// The UA SPELL TABLES (pp. 30-31) pins, part 2 (R342): the magic-user
// spells tables and the illusionist spell table.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R80 spell registry (spells/spells.h) is the class/level seam.
//
// JUDGMENTs (the decode method): each column of the printed table is
// alphabetical, so a fragment's position forces its identity; the
// straight apostrophe normalizes the extract's typographic one.
//   - split names: Spider/[Climb]; Tenser's/[Floating]/[Disc]; Secure/
//     Shelter = Leomund's Secure Shelter (the attribution restored by
//     the L-sort position between Ice Storm and Magic Mirror); Minor
//     Globe of/[Invulnerability]; Otiluke's Resilient/[ere = Sphere];
//     Mordenkainen's Faithful/[Hound]; Rary's Mnemonic/[Enhancer];
//     Protection From Normal/[Missiles]; [L]/[Bolt] = Lightning Bolt
//     (registry seam-proven: the engine row reads MU 3); Wizard/
//     [Lock]; Prismatic/[Sphere].
//   - garble decodes: "Reso Magic" = Read Magic (position-forced: it
//     sorts between Protection From Evil and Shocking Grasp);
//     "588985888 Grasp" = Shocking Grasp; "From Evil" = the tail of
//     Protection From Evil (head lost); "Dis oor" = Dimension Door
//     (sorts between Dig and Enchanted Weapon); "Fics 2 LA Terrain" =
//     Hallucinatory Terrain (sorts between Fire Shield and Ice Storm);
//     "Ice" = Ice Storm (registry seam-proven: the engine row reads
//     MU 4); "Tiny Hut" = Leomund's Tiny Hut; "Runes" = Explosive
//     Runes; "Extension Il" = Extension II (the pair convention with
//     the 4th column's Extension I); "Monster Summoning Ili" =
//     Monster Summoning III; "Wall Iron of" and "Stone Wall of" =
//     word-order scrambles of Wall of Iron and Wall of Stone.
//   - merged-cell decodes: "Comprehend Languages Detect Evil" = two
//     names (col1 + col2); "Conjure Elemental Tentacles" = Conjure
//     Elemental (col5) + the leaked tail of Evard's Black Tentacles
//     (col4); "Leomund's Lamentable rosie Belabourment Jar Secret
//     Chest" = Leomund's Lamentable Belabourment + Magic Jar +
//     Leomund's Secret Chest (three 5th-level names, position-
//     verified); "Tasha's Uncontrollable ~~ Water Breathing" = the
//     2nd-level name plus the 3rd column's Water Breathing drifted
//     into the cell ("Laughter Hideous" below is its inverted tail);
//     "Protection From Normal Rary's Mnemonic" = the 3rd-level name
//     plus the 4th column's Rary's Mnemonic Enhancer; "Spider Taunt
//     Tenser's" = three 1st-level names; "Whip Wizard" = the 2nd-level
//     "Whip" plus Wizard Lock's head; "Disc ~~ Zephyr" = the 1st-level
//     Disc tail plus the 2nd-level Zephyr.
//   - the "Whip" cell: pinned as printed (verbatim). It sorts where
//     the PHB's Whispering Wind would sit; likely its garble - the
//     identity stays pending the PDF.
//   - verbatim-with-doubt pins: "Stone Shape" prints in the 5th
//     column (the PHB reads MU 4th) and "Secret Page" in the 3rd (the
//     PHB reads 2nd) - pinned as printed, doubts noted; the 3rd- and
//     7th-column "Monster Summoning" cells print without numerals -
//     pinned verbatim, the numeral loss noted.
//
// OCR holes (the item closes; these stay on the PDF ledger): the 6th-
// level column is wholly lost (the printed table runs 1st-5th, the
// continued table 7th-9th; the registry rows Death Spell and
// Disintegrate prove it existed); the fragment cells read as holes -
// "pid" (1st), "A >", "Flaming" and "Protection From" (2nd), "Detect",
// "Item" and "Material" (3rd), "Dispel" (4th), "Dolor" (5th), "i
// last", "Truename", "ish" and "888" (7th-9th), "To Flesh" and the
// tail of "Otiluke's" (8th); the continued header prints "th Level"
// (the 9 lost); the registry rows absent from the print (Shield,
// Sleep, Web, Whispering Wind, Monster Summoning II, Limited Wish,
// Alter Reality, Wish, Gate) read as lost rows - noted, not pinned;
// the illusionist cantrip column and the illusionist 3rd-6th columns
// are wholly lost; the illusionist 2nd-level brace-garbage cell and
// the "Phantom Wind" fragment read as holes (the "Mirror" tail
// seam-decodes as Mirror Image).
// ===========================================================================

#pragma once

namespace rules {

// ---- the MU 1st-5th table (pp. 30-31) ----
// The readable roster of the 1st-level column (35 names).
inline int uas2Mu1stCount()
    { return 35; }

inline const char* uas2Mu1stName(int i) {
    static const char* const k[35] = {
        "Affect Normal Fires", "Alarm", "Armor",
        "Burning Hands", "Charm Person",
        "Comprehend Languages", "Dancing Lights",
        "Detect Magic", "Enlarge", "Erase",
        "Feather Fall", "Find Familiar", "Firewater",
        "Friends", "Grease", "Hold Portal", "Identify",
        "Jump", "Light", "Magic Missile", "Melt",
        "Mending", "Message", "Mount",
        "Nystul's Magic Aura", "Precipitation",
        "Protection From Evil", "Read Magic",
        "Shocking Grasp", "Spider Climb", "Taunt",
        "Tenser's Floating Disc", "Unseen Servant",
        "Ventriloquism", "Wizard Mark",
    };
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    return k[i];
}

// The 2nd-level column (30 names; "Whip" pinned as printed; the
// extract prints Suggestion in the 3rd column only).
inline int uas2Mu2ndCount()
    { return 30; }

inline const char* uas2Mu2ndName(int i) {
    static const char* const k[30] = {
        "Audible Glamer", "Bind", "Continual Light",
        "Darkness 15' Radius", "Detect Evil",
        "Detect Invisibility", "Fool's Gold", "Forget",
        "Invisibility", "Irritation", "Knock",
        "Know Alignment", "Leomund's Trap", "Levitate",
        "Locate Object", "Magic Mouth",
        "Melf's Acid Arrow", "Mirror Image",
        "Preserve", "Pyrotechnics",
        "Ray of Enfeeblement", "Rope Trick", "Scare",
        "Shatter", "Stinking Cloud", "Strength",
        "Tasha's Uncontrollable Hideous Laughter",
        "Whip", "Wizard Lock", "Zephyr",
    };
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    return k[i];
}

// The 3rd-level column (28 names; Secret Page pinned as printed).
inline int uas2Mu3rdCount()
    { return 28; }

inline const char* uas2Mu3rdName(int i) {
    static const char* const k[28] = {
        "Blink", "Clairaudience", "Clairvoyance",
        "Dispel Magic", "Explosive Runes", "Feign Death",
        "Fireball", "Flame Arrow", "Fly",
        "Gust of Wind", "Haste", "Hold Person",
        "Infravision", "Invisibility 10'' Radius",
        "Leomund's Tiny Hut", "Lightning Bolt",
        "Melf's Minute Meteor", "Monster Summoning",
        "Phantasmal Force",
        "Protection From Evil 10' Radius",
        "Protection From Normal Missiles",
        "Secret Page", "Sepia Snake Sigil", "Slow",
        "Suggestion", "Tongues", "Water Breathing",
        "Wind Wall",
    };
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    return k[i];
}

// The 4th-level column (28 names).
inline int uas2Mu4thCount()
    { return 28; }

inline const char* uas2Mu4thName(int i) {
    static const char* const k[28] = {
        "Charm Monster", "Confusion", "Dig",
        "Dimension Door", "Enchanted Weapon",
        "Evard's Black Tentacles", "Extension I",
        "Fear", "Fire Charm", "Fire Shield",
        "Hallucinatory Terrain", "Ice Storm",
        "Leomund's Secure Shelter", "Magic Mirror",
        "Massmorph", "Minor Globe of Invulnerability",
        "Otiluke's Resilient Sphere", "Plant Growth",
        "Polymorph Other", "Polymorph Self",
        "Rary's Mnemonic Enhancer", "Remove Curse",
        "Shout", "Stoneskin", "Ultravision",
        "Wall of Fire", "Wall of Ice", "Wizard Eye",
    };
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    return k[i];
}

// The 5th-level column (28 names; Stone Shape pinned as printed).
inline int uas2Mu5thCount()
    { return 28; }

inline const char* uas2Mu5thName(int i) {
    static const char* const k[28] = {
        "Airy Water", "Animal Growth", "Animate Dead",
        "Bigby's Interposing Hand", "Cloudkill",
        "Conjure Elemental", "Cone of Cold",
        "Contact Other Plane", "Dismissal",
        "Distance Distortion", "Extension II",
        "Fabricate", "Feeblemind", "Hold Monster",
        "Leomund's Lamentable Belabourment",
        "Leomund's Secret Chest", "Magic Jar",
        "Monster Summoning III",
        "Mordenkainen's Faithful Hound", "Passwall",
        "Sending", "Stone Shape", "Telekinesis",
        "Teleport", "Transmute Rock To Mud",
        "Wall of Force", "Wall of Iron",
        "Wall of Stone",
    };
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    return k[i];
}

// ---- the MU continued table (7th-9th; the 6th column is lost) ----
// The readable 7th-level fragments (7 names; the numerals of
// Monster Summoning and Drawmij's Instant [Summons] are lost).
inline int uas2Mu7thCount()
    { return 7; }

inline const char* uas2Mu7thName(int i) {
    static const char* const k[7] = {
        "Drawmij's Instant", "Invisible Stalker",
        "Legend Lore", "Lower Water",
        "Monster Summoning",
        "Otiluke's Freezing Sphere", "Part Water",
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

// The readable 8th-level names (11).
inline int uas2Mu8thCount()
    { return 11; }

inline const char* uas2Mu8thName(int i) {
    static const char* const k[11] = {
        "Demand", "Glassteel", "Mass Invisibility",
        "Mind Blank", "Monster Summoning VI",
        "Power Word Blind", "Power Word Kill",
        "Serten's Spell Immunity", "Sink",
        "Tenser's Transformation",
        "Transmute Water To Dust",
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return k[i];
}

// The readable 9th-level names (2; the header's "th Level" cell
// prints the 9 lost).
inline int uas2Mu9thCount()
    { return 2; }

inline const char* uas2Mu9thName(int i) {
    static const char* const k[2] = {
        "Prismatic Sphere", "Shape Change",
    };
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    return k[i];
}

// The 6th-level column is wholly lost (the registry rows Death
// Spell and Disintegrate prove it existed).
inline bool uas2MuSixthLevelColumnLost()
    { return true; }

// The continued header's "th Level" prints the 9 lost.
inline bool uas2MuHighTableNineLost()
    { return true; }

// ---- the illusionist table (p. 31) ----
// The readable 1st-level column (5 names).
inline int uas2Il1stCount()
    { return 5; }

inline const char* uas2Il1stName(int i) {
    static const char* const k[5] = {
        "Color Spray", "Dancing Lights", "Darkness",
        "Hypnotism", "Phantasmal Force",
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// The readable 2nd-level names (4; the "Hallucin: Terrain" and
// "Mirror" fragments seam-decode against the R229 registry).
inline int uas2Il2ndCount()
    { return 4; }

inline const char* uas2Il2ndName(int i) {
    static const char* const k[4] = {
        "Dispel Illusion", "Hallucinatory Terrain",
        "Magic Mouth", "Mirror Image",
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The readable 7th-level name (1; the 3rd-6th columns are lost).
inline int uas2Il7thCount()
    { return 1; }

inline const char* uas2Il7thName(int i) {
    static const char* const k[1] = {
        "Shadow Walk",
    };
    if (i < 0) i = 0;
    return k[i];
}

// The illusionist minor-illusion cantrip column is wholly lost
// (the cells print garbage; the acquisition prose survives).
inline bool uas2IlCantripListLost()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uaspelltables2.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 25, 'b inline count'
assert s.count('R342') == 1, 'b round tag'
assert s.count('uas2Mu2ndName(int i)') == 1,     'b mu2nd fn'
assert s.count('uas2Il2ndName(int i)') == 1,     'b il2nd fn'
assert s.count('uas2MuSixthLevelColumnLost') == 1,     'b loss flag'
assert 'uastClericName' not in s,     'b no r341 ref'
assert 'uanwAklys' not in s,     'b no r340 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the item
# CLOSES - the flip plus the note ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R342' in s:
    already.append('gap report: the closed note')
else:
    FIRST_OLD = ('- [ ] **The spell tables**'
                ' (pp. 28-31)')
    assert s.count(FIRST_OLD) == 1, 'c first'
    TAIL_OLD = NL.join([
        '        are OCR-scrambled - stays open',
        '        pending the PDF read.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - CLOSED R342: part 2 pinned',
        '        (rules/uaspelltables2.h) - the',
        '        MU 1st-5th columns',
        '        (35/30/28/28/28 readable names,',
        '        every garble position-decoded),',
        '        the MU 7th-9th continued table',
        '        (7/11/2) and the illusionist',
        '        table (5/4/1). The 6th column,',
        '        the fragment cells, the',
        '        illusionist cantrip and',
        '        3rd-6th columns are OCR-lost -',
        '        noted pending the PDF read.',
    ])
    clean(NOTE, 57)
    s = s.replace(FIRST_OLD,
        '- [x] **The spell tables** (pp. 28-31)')
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the closed note')
s = rd(GP)
FIRST = '- [x] **The spell tables**'     ' (pp. 28-31)'
OPEN = '- [ ] **The spell tables**'     ' (pp. 28-31)'
assert s.count('CLOSED R342') == 1, 'c closed note'
assert s.count(FIRST) == 1, 'c flipped'
assert s.count(OPEN) == 0, 'c no open item'
assert s.count(
    'R341: the readable tables') == 1, 'c r341 note kept'
assert s.count(
    'R340: the fragment-verified') == 1, 'c r340 kept'
assert s.count('CLOSED R339') == 1, 'c r339 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R342 UA MU and IL tables pin audit' in s:
    already.append('regtest.cpp: the R342 audit')
else:
    INC_ANCH = (
        '#include "rules/uaspelltables.h"'
        '  // R341: the UA spell tables part 1')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaspelltables2.h"'
        '  // R342: the UA MU and illusionist'
        ' tables',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R342: the UA MU and illusionist tables pin audit ----
    // The UA SPELL TABLES (pp. 30-31), part 2 - the MU
    // 1st-5th columns (35/30/28/28/28 readable names,
    // every garble position-decoded, the alphabetical
    // continuity documented), the MU 7th-9th continued
    // table (7/11/2, the 6th column and the header's 9
    // lost) and the illusionist table (5/4/1, the
    // cantrip and 3rd-6th columns lost). The item
    // closes; the holes stay pending the PDF.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the loss flags
        {
            if (uas2Mu1stCount() != 35) ++bad;
            if (uas2Mu2ndCount() != 30) ++bad;
            if (uas2Mu3rdCount() != 28) ++bad;
            if (uas2Mu4thCount() != 28) ++bad;
            if (uas2Mu5thCount() != 28) ++bad;
            if (uas2Mu7thCount() != 7) ++bad;
            if (uas2Mu8thCount() != 11) ++bad;
            if (uas2Mu9thCount() != 2) ++bad;
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (!uas2MuSixthLevelColumnLost()) ++bad;
            if (!uas2MuHighTableNineLost()) ++bad;
            if (!uas2IlCantripListLost()) ++bad;
        }
        // U2: the MU 1st column (the garble decodes)
        {
            if (strcmp(uas2Mu1stName(0),
                "Affect Normal Fires") != 0) ++bad;
            if (strcmp(uas2Mu1stName(5),
                "Comprehend Languages") != 0) ++bad;
            if (strcmp(uas2Mu1stName(19),
                "Magic Missile") != 0) ++bad;
            // the "Reso Magic" cell = Read Magic
            if (strcmp(uas2Mu1stName(27),
                "Read Magic") != 0) ++bad;
            // the "588985888 Grasp" cell = Shocking Grasp
            if (strcmp(uas2Mu1stName(28),
                "Shocking Grasp") != 0) ++bad;
            // the "From Evil" head-lost tail decode
            if (strcmp(uas2Mu1stName(26),
                "Protection From Evil") != 0) ++bad;
            // the merged Spider/Taunt/Tenser's cell
            if (strcmp(uas2Mu1stName(29),
                "Spider Climb") != 0) ++bad;
            if (strcmp(uas2Mu1stName(30), "Taunt")
                != 0) ++bad;
            if (strcmp(uas2Mu1stName(31),
                "Tenser's Floating Disc") != 0) ++bad;
            // the "Unseen Servan" tail loss
            if (strcmp(uas2Mu1stName(32),
                "Unseen Servant") != 0) ++bad;
            if (strcmp(uas2Mu1stName(34),
                "Wizard Mark") != 0) ++bad;
        }
        // U3: the MU 2nd-5th columns
        {
            // the "Continual Li" tail decode
            if (strcmp(uas2Mu2ndName(2),
                "Continual Light") != 0) ++bad;
            // the merged Detect Evil cell
            if (strcmp(uas2Mu2ndName(4),
                "Detect Evil") != 0) ++bad;
            // the "Meif's" garble
            if (strcmp(uas2Mu2ndName(16),
                "Melf's Acid Arrow") != 0) ++bad;
            // the "Whip" cell - verbatim, identity
            // pending the PDF
            if (strcmp(uas2Mu2ndName(27), "Whip")
                != 0) ++bad;
            if (strcmp(uas2Mu2ndName(29), "Zephyr")
                != 0) ++bad;
            // the "Runes" cell = Explosive Runes
            if (strcmp(uas2Mu3rdName(4),
                "Explosive Runes") != 0) ++bad;
            // the "Tiny Hut" decode
            if (strcmp(uas2Mu3rdName(14),
                "Leomund's Tiny Hut") != 0) ++bad;
            // the "Bolt" cell = Lightning Bolt
            if (strcmp(uas2Mu3rdName(15),
                "Lightning Bolt") != 0) ++bad;
            // the numeral-less print, verbatim
            if (strcmp(uas2Mu3rdName(17),
                "Monster Summoning") != 0) ++bad;
            // the Secret Page print sits in the 3rd
            // column (the PHB reads 2nd) - as printed
            if (strcmp(uas2Mu3rdName(21),
                "Secret Page") != 0) ++bad;
            // the "Dis oor" cell = Dimension Door
            if (strcmp(uas2Mu4thName(3),
                "Dimension Door") != 0) ++bad;
            // the "Ice" cell = Ice Storm (seam-proven)
            if (strcmp(uas2Mu4thName(11),
                "Ice Storm") != 0) ++bad;
            // the Secure/Shelter split decode
            if (strcmp(uas2Mu4thName(12),
                "Leomund's Secure Shelter") != 0) ++bad;
            // the "Fics 2 LA Terrain" cell
            if (strcmp(uas2Mu4thName(10),
                "Hallucinatory Terrain") != 0) ++bad;
            // the "Otiluke's Resilient"/"ere" split
            if (strcmp(uas2Mu4thName(16),
                "Otiluke's Resilient Sphere") != 0) ++bad;
            // the "Extension Il" pair decode
            if (strcmp(uas2Mu5thName(10),
                "Extension II") != 0) ++bad;
            // the three-name merged cell
            if (strcmp(uas2Mu5thName(14),
                "Leomund's Lamentable Belabourment")
                != 0) ++bad;
            if (strcmp(uas2Mu5thName(15),
                "Leomund's Secret Chest") != 0) ++bad;
            if (strcmp(uas2Mu5thName(16),
                "Magic Jar") != 0) ++bad;
            // the "Monster Summoning Ili" decode
            if (strcmp(uas2Mu5thName(17),
                "Monster Summoning III") != 0) ++bad;
            // the word-order scrambles
            if (strcmp(uas2Mu5thName(26),
                "Wall of Iron") != 0) ++bad;
            if (strcmp(uas2Mu5thName(27),
                "Wall of Stone") != 0) ++bad;
            // the Stone Shape print sits in the 5th
            // column (the PHB reads 4th) - as printed
            if (strcmp(uas2Mu5thName(21),
                "Stone Shape") != 0) ++bad;
        }
        // U4: the MU continued table (7th-9th)
        {
            // the merged Drawmij's cell head
            if (strcmp(uas2Mu7thName(0),
                "Drawmij's Instant") != 0) ++bad;
            // the numeral-less print, verbatim
            if (strcmp(uas2Mu7thName(4),
                "Monster Summoning") != 0) ++bad;
            if (strcmp(uas2Mu7thName(5),
                "Otiluke's Freezing Sphere") != 0) ++bad;
            // the "Il Demand" cell = Demand
            if (strcmp(uas2Mu8thName(0), "Demand")
                != 0) ++bad;
            // the "Power Word, Kill" comma print
            if (strcmp(uas2Mu8thName(6),
                "Power Word Kill") != 0) ++bad;
            if (strcmp(uas2Mu8thName(5),
                "Power Word Blind") != 0) ++bad;
            // the merged Shape Change/Sphere cell
            if (strcmp(uas2Mu9thName(0),
                "Prismatic Sphere") != 0) ++bad;
            if (strcmp(uas2Mu9thName(1),
                "Shape Change") != 0) ++bad;
        }
        // U5: the illusionist table
        {
            if (strcmp(uas2Il1stName(0),
                "Color Spray") != 0) ++bad;
            if (strcmp(uas2Il1stName(4),
                "Phantasmal Force") != 0) ++bad;
            // the "Hallucin: Terrain" fragment decode
            if (strcmp(uas2Il2ndName(1),
                "Hallucinatory Terrain") != 0) ++bad;
            // the "Phantom Wind Mirror" tail decode
            if (strcmp(uas2Il2ndName(3),
                "Mirror Image") != 0) ++bad;
            if (strcmp(uas2Il7thName(0),
                "Shadow Walk") != 0) ++bad;
        }
        // U6: the R80/R229 registry seam (live)
        {
            auto reglvl = [](const char* n,
                spells::SpellClass c) -> int {
                for (int id = 0;
                     id < spells::SPELL_COUNT; ++id) {
                    const spells::SpellDef& d =
                        spells::spell(
                            (spells::SpellId)id);
                    if (d.sclass == c
                        && strcmp(d.name, n) == 0)
                        return d.level;
                }
                return -1;
            };
            using spells::SPELL_MU;
            using spells::SPELL_ILLUSIONIST;
            // the 1st-5th columns verify
            if (reglvl("Magic Missile",
                SPELL_MU) != 1) ++bad;
            if (reglvl("Charm Person",
                SPELL_MU) != 1) ++bad;
            if (reglvl("Invisibility",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Mirror Image",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Strength",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Fireball",
                SPELL_MU) != 3) ++bad;
            if (reglvl("Lightning Bolt",
                SPELL_MU) != 3) ++bad;
            if (reglvl("Dispel Magic",
                SPELL_MU) != 3) ++bad;
            // the "Ice" decode seam-proven
            if (reglvl("Ice Storm",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Charm Monster",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Polymorph Other",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Fire Shield",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Cone of Cold",
                SPELL_MU) != 5) ++bad;
            if (reglvl("Teleport",
                SPELL_MU) != 5) ++bad;
            if (reglvl("Hold Monster",
                SPELL_MU) != 5) ++bad;
            // the 6th-column proof rows
            if (reglvl("Death Spell",
                SPELL_MU) != 6) ++bad;
            if (reglvl("Disintegrate",
                SPELL_MU) != 6) ++bad;
            // the lost 7th/9th registry rows
            if (reglvl("Limited Wish",
                SPELL_MU) != 7) ++bad;
            if (reglvl("Wish",
                SPELL_MU) != 9) ++bad;
            // the illusionist 2nd column verifies
            if (reglvl("Dispel Illusion",
                SPELL_ILLUSIONIST) != 2) ++bad;
            if (reglvl("Magic Mouth",
                SPELL_ILLUSIONIST) != 2) ++bad;
            // the "Hallucin: Terrain" decode seam
            if (reglvl("Hallucinatory Terrain",
                SPELL_ILLUSIONIST) != 2) ++bad;
            // the "Mirror" fragment decode seam
            if (reglvl("Mirror Image",
                SPELL_ILLUSIONIST) != 2) ++bad;
        }
        printf("R342 UA MU and IL tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R342 audit')
s = rd(RT)
assert s.count(
    'R342 UA MU and IL tables'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 269, 'd census 269'
assert s.count(
    'R341 UA spell tables pin audit: bad ')     == 1, 'd r341 kept'
assert s.count(
    'R340 UA new weapons prose pin audit: bad ')     == 1, 'd r340 kept'
assert s.count(
    'R339 UA proficiency pin audit: bad ')     == 1, 'd r339 kept'
assert s.count('R227: the wis mental save') == 1,     'd r227 kept'
assert s.count(
    '#include "rules/uaspelltables2.h"') == 1,     'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R342 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R342 note: the UA spell tables pin')
print('round, part 2 - the MU 1st-5th')
print('columns (35/30/28/28/28 readable')
print('names, every garble position-decoded')
print('by alphabetical continuity, the')
print('registry seam live in the audit),')
print('the MU 7th-9th continued table and')
print('the illusionist table; the 6th')
print('column, the fragment cells and the')
print('illusionist cantrip and 3rd-6th')
print('columns are OCR holes - noted')
print('pending the PDF; the item closes;')
print('the census 268 -> 269')
print('commit: R342: the UA MU and')
print('illusionist tables pin round')
print('(census 269)')

