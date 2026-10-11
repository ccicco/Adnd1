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

}   // namespace rules
