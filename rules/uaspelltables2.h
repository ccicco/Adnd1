// ===========================================================================
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
//   - R785: the "Whip" doubt STRIKES - the
//     uam2WhipName pin ("Whip (Evocation)", p. 52)
//     proves the cell reads a real UA 2nd-level
//     spell, not a garble.
//   - verbatim-with-doubt pins: "Stone Shape" prints in the 5th
//     column (the PHB reads MU 4th) and "Secret Page" in the 3rd (the
//     PHB reads 2nd) - pinned as printed, doubts noted; the 3rd- and
//     7th-column "Monster Summoning" cells print without numerals -
//     pinned verbatim, the numeral loss noted.
//
// R785 RESOLUTIONS (the PDF ledger closes; the ledger
// census pins in rules/spelltableledger.h): the
// archive.org full-text OCR reads the continued table;
// the 6th-level column REPAIRS (17 names, uas2Mu6thName)
// and the drifted cells re-seat - Tenser's
// Transformation and Transmute Water To Dust belong
// to the 6th column, and the four other drifted 6th
// cells read in their own column; Clone and Otiluke's
// Telekinetic Sphere newly read; the fragment holes
// resolve against the UA-new description rosters and
// the R80 registry (Flaming = Flaming Sphere,
// Protection From = the cantrips tail, Detect = Detect
// Illusion, Item and Material resolve, Dispel = Dispel
// Illusion, Dolor resolves, Truename resolves, Gravity =
// the Reverse Gravity tail, Project Im = Project
// Image); Glassteel and Power Word Kill stay OPEN
// holes (absent from the print, the descriptions, and
// the registry); the "th Level" print stands (the 9
// stays lost); the row numbers stay unreliable (the
// alphabetical order contradicts them); the registry
// rows absent from the print stay noted, not pinned;
// the illusionist 3rd-6th columns resolve on the
// UA-new side (the R364-R368 description rosters,
// rules/uailspells3-7.h, carry 4/4/4/4 new names plus
// the 7th-level pair Shadow Walk and Weird); the
// PHB-side rows of those columns stay lost; the
// "Phantom Wind" fragment resolves (the UA-new 3rd
// roster carries it); the "Mirror" tail seam-decode
// stands (Mirror Image).

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

// ---- the MU continued table (6th-9th; the R785
// ledger repair rides rules/spelltableledger.h) ----
// The repaired 7th-level roster (16 names: the nine
// readable print cells - including the numeral
// restorations Monster Summoning V and Drawmij's
// Instant Summons and the Reverse Gravity tail - the
// six UA-new description-roster names, and the
// registry row Limited Wish).
inline int uas2Mu7thCount()
    { return 16; }

inline const char* uas2Mu7thName(int i) {
    static const char* const k[16] = {
        "Banishment", "Charm Plants",
        "Delayed Blast Fireball",
        "Drawmij's Instant Summons", "Forcecage",
        "Legend Lore", "Limited Wish",
        "Monster Summoning V",
        "Mordenkainen's Magnificent Mansion",
        "Reverse Gravity", "Sequester",
        "Teleport Without Error", "Torment",
        "Truename", "Vanish", "Volley",
    };
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    return k[i];
}

// The repaired 8th-level roster (10 names: the nine
// readable print cells - including the newly-read
// Clone and Otiluke's Telekinetic Sphere - and the
// UA-new Binding; Glassteel and Power Word Kill stay
// OPEN holes; Tenser's Transformation and Transmute
// Water To Dust re-seat to the 6th column).
inline int uas2Mu8thCount()
    { return 10; }

inline const char* uas2Mu8thName(int i) {
    static const char* const k[10] = {
        "Binding", "Clone", "Demand",
        "Mass Invisibility", "Mind Blank",
        "Monster Summoning VI",
        "Otiluke's Telekinetic Sphere",
        "Power Word Blind", "Serten's Spell Immunity",
        "Sink",
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

// The repaired 9th-level roster (8 names: the five
// readable print cells - Energy Drain, Gate, Prismatic
// Sphere, Shape Change, Wish - and the UA-new
// Crystalbrittle, Mordenkainen's Disjunction, and
// Succor, its level seam-proven by the section
// heading; the "th Level" print stands).
inline int uas2Mu9thCount()
    { return 8; }

inline const char* uas2Mu9thName(int i) {
    static const char* const k[8] = {
        "Crystalbrittle", "Energy Drain", "Gate",
        "Mordenkainen's Disjunction",
        "Prismatic Sphere", "Shape Change",
        "Succor", "Wish",
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

// R785: the 6th-level column - the archive.org
// full-text OCR reads the continued table, and the
// cells the R342 read had drifted into the 7th and
// 8th blocks re-seat here. The repaired roster (17
// names: the twelve readable cells, the three UA-new
// description-roster names - Chain Lightning,
// Ensnarement, Mordenkainen's Lucubration - and the
// two registry rows Death Spell and Disintegrate).
inline int uas2Mu6thCount()
    { return 17; }

inline const char* uas2Mu6thName(int i) {
    static const char* const k[17] = {
        "Chain Lightning", "Contingency",
        "Control Weather", "Death Spell",
        "Disintegrate", "Ensnarement", "Eyebite",
        "Geas", "Invisible Stalker", "Lower Water",
        "Mordenkainen's Lucubration",
        "Otiluke's Freezing Sphere", "Part Water",
        "Project Image", "Stone To Flesh",
        "Tenser's Transformation",
        "Transmute Water To Dust",
    };
    if (i < 0) i = 0;
    if (i > 16) i = 16;
    return k[i];
}

// R785: the sixth column reads (the loss flag flips).
inline bool uas2MuSixthLevelColumnLost()
    { return false; }
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

// The illusionist minor-illusion cantrip
// column: the PDF read resolves the
// loss (R421) - the clean p. 31
// print gives the whole column, the
// eight names in roster order,
// matching the description roster
// (rules/uailcantrips.h) row for row.
inline int uas2IlCantripCount()
    { return 8; }

inline const char* uas2IlCantripName(int i) {
    static const char* const k[8] = {
        "Colored Lights", "Dim", "Haze", "Mask",
        "Mirage", "Noise", "Rainbow",
        "Two-D'lusion",
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

}   // namespace rules
