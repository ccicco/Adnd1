-- ua341: promoted from rules/ua/uaspelltables.h (the The UA SPELL TABLES (pp. 28-31) pins, part 1 (R341): the cleric);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 341,
  "prefix" = "ua341",
  "banner" = {
      "title" = "The UA SPELL TABLES (pp. 28-31) pins, part 1 (R341): the cleric",
      "provenance" = "tables, the druid tables and the magic-user cantrip table.  Pin-era pattern (R322): pinned data only - no engine site exists. The R80 spell registry (spells/spells.h) is the class/level seam.  JUDGMENTs: - the scope: part 1 pins the READABLE tables. The magic-user spells tables (1st-5th and 7th-9th) and the illusionist spell table are OCR-scrambled beyond row-aligned decode - their head rows read clean but the column alignment breaks mid-table (the interleaved tail rows) - they stay open pending the PDF, the item stays open. - the druid \"2nd Level\" fragment: the four readable rows (the merged \"Locate Invisibility To Animals Animals\" cell plus Shillelagh and Speak With Animals) all seam-verify against the R228 druid roster as FIRST-level spells (Locate Animals, Invisibility To Animals, Shillelagh, Speak With Animals - all druid 1). The merged cell decodes as two interleaved names (Locate/Invisibility + Animals/Animals). The \"2nd Level\" header reads as a stray fragment: the visible rows are the 1st-level roster; the actual 2nd-level list is OCR-lost. - the druid 5th column \"Insect P|\" fragment decodes to Insect Plague - the R228 seam (druid 5) confirms both the name and the column. The druid Sticks To Snakes prints in the 5th column where the R228 seam reads druid 6 - pinned as printed, the doubt noted pending the PDF. - the cleric Spike Growth prints in the 5th column (the PHB reads cleric 3rd) - pinned as printed, the doubt noted pending the PDF. - the cleric Cure Critical Wounds prints in the 5th column (the PHB-consistent read); the R80 registry carries it at cleric 4 - a registry quirk, not a print doubt: pinned as printed, no seam assert against the registry for that cell. - the cantrip \"Gather Polish\" cell is two names merged by the OCR (Gather, Polish); both pin. The \"Unlock\" cantrip prints in the Personal column - pinned as printed, the likely column-slip noted pending the PDF. - the cleric 2nd column \"Silence 15 Radius\" prints without the apostrophe (the PHB print \"Silence 15' Radius\"); pinned as printed. - the MU useful-cantrip count: the acquisition prose prints scrambled, but the fragments (\"has one\", \"of each point\", \"For of intelligence\") assemble to one useful cantrip per point of intelligence - the illusionist text (\"one per point of intelligence, up to intelligence minus 3\") parallels it. Pinned as the fragment decode, flagged. - the Number columns prove the loss: the cleric Continued table prints row numbers 15 and 16 (a 16+ row table) but only 7 readable rows; the druid 4th-6th table prints 4, 6, 10, 11 (garbled \"1\"\"), 12 - a 12-row table with 6 readable rows.  OCR holes (the item stays open pending the PDF): the ENTIRE magic-user spells tables (1st-9th), the illusionist spell table and the illusionist minor-illusion cantrip list; the cleric 1st \"ct Evil\" cell (a garble matching no unique name), the cleric 2nd \"draw\" cell, the empty table cells (hole sentinels: the empty string), the cleric 7th column (no readable cell), the druid 1st/2nd/3rd lists beyond the four readable rows, and the two tables' Number columns.",
    },
  "consts" = { {
      "name" = "uastClericTableRowCount",
      "value" = 20,
      "comment" = "---- the cleric table (pp. 28-29) ---- The 1st-3rd level table: 20 printed rows. The empty string is the hole sentinel (an OCR-lost cell).",
    }, {
      "name" = "uastDruid1stCount",
      "value" = 4,
      "comment" = "---- the druid tables (p. 29) ---- The four readable rows - the 1st-level roster per the R228 seam (the \"2nd Level\" header is a stray fragment).",
    }, {
      "name" = "uastDruid4thCount",
      "value" = 6,
      "comment" = "The 4th-6th table: 6 readable rows of a 12-row print.",
    }, {
      "name" = "uastDruid5thCount",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uastDruid6thCount",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastCantripCategoryCount",
      "value" = 6,
      "comment" = "---- the magic-user cantrip table (p. 30) ---- Six categories, 66 names (the Gather/Polish merge decodes to two; the Number column is OCR-lost). R401 clean-read fix: the table prints Tangle (reversed row 9) and Tweak (personal row 9) - the R341 decode read 64, missing both.",
    }, {
      "name" = "uastMuCantripMaxNewCount",
      "value" = 3,
      "comment" = "---- the cantrip acquisition prose (pp. 28, 31) ---- The magic-user ranges (the useful count is the fragment decode - one per point of intelligence).",
    }, {
      "name" = "uastMuReversedMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastMuReversedMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uastMuLegerdemainMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastMuLegerdemainMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastMuPersonAffectingMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastMuPersonAffectingMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uastMuPersonalMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastMuPersonalMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uastMuHauntingMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastMuHauntingMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastIlMinorIllusionMin",
      "value" = 5,
      "comment" = "The illusionist ranges (clean print): the useful count is one per point of intelligence up to intelligence minus 3 (an 18 intelligence chooses 15); 5-8 minor illusion cantrips.",
    }, {
      "name" = "uastIlMinorIllusionMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uastIlUsefulIntMinus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uastIlUsefulAtInt18",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uastIlReversedMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastIlReversedMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastIlLegerdemainMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uastIlLegerdemainMax",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uastIlPersonAffectingMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastIlPersonAffectingMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastIlPersonalMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uastIlPersonalMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastIlHauntingMin",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uastIlHauntingMax",
      "value" = 8,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uastMuUsefulOnePerIntPoint",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uastNoteAllCantripsDescribedHere",
      "value" = true,
      "comment" = "The caption note: all cantrips (plus the italic spells) are described in this volume.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uastClericName",
      "comment" = "",
      "kind" = "string grid",
      "rows" = { { "Bless", "Ceremony", "Combine", "Command", "Create Water", "Cure Light Wounds", "", "Detect Magic", "Endure Cold/Heat", "Invisibility to Undead", "Light", "Magic Stone", "Penetrate Disguise", "", "Precipitation", "Protection From Evil", "Purify Food & Drink", "Remove Fear", "Resist Cold", "Sanctuary" }, { "", "", "", "Detect Charm", "Detect Life", "Dust Devil", "Enthrall", "Find Traps", "Hold Person", "Holy Symbol", "Know Alignment", "Messenger", "Resist Fire", "Silence 15 Radius", "Slow Poison", "Snake Charm", "Speak With Animals", "Spiritual Hammer", "", "Wyvern Watch" }, { "Animate Dead", "Cloudburst", "Continual Light", "Create Food & Water", "Cure Blindness", "Cure Disease", "Death's Door", "Dispel Magic", "Feign Death", "Flame Walk", "Glyph of Warding", "Locate Object", "Magical Vestment", "Meld Into Stone", "Negative Plane Protection", "Prayer", "Remove Curse", "Remove Paralysis", "Speak With Dead", "Water Walk" } },
    }, {
      "name" = "uastClericReadableCount",
      "comment" = "The readable cells per level column (18, 16, 20).",
      "kind" = "header pin",
      "body" = "static const int k[3] = { 18, 16, 20 }; if (lvl < 1) lvl = 1; if (lvl > 3) lvl = 3; return k[lvl - 1];",
    }, {
      "name" = "uastClericFragCount",
      "comment" = "The Continued table (4th-7th): only fragments readable (the row numbers 15 and 16 prove a 16-row print).",
      "kind" = "header pin",
      "body" = "// 4th, 5th, 6th, 7th static const int k[4] = { 2, 7, 4, 0 }; if (lvl < 4) lvl = 4; if (lvl > 7) lvl = 7; return k[lvl - 4];",
    }, {
      "name" = "uastClericFragName",
      "comment" = "",
      "kind" = "string grid",
      "rows" = { { "Sticks to Snakes", "Tongues", "", "", "", "", "", "" }, { "Commune", "Cure Critical Wounds", "Dispel Evil", "Magic Font", "Plane Shift", "Spike Growth", "True Seeing", "" }, { "Conjure Animals", "Find The Path", "Speak With Monsters", "Stone Tell", "", "", "", "" }, { "", "", "", "", "", "", "", "" } },
    }, {
      "name" = "uastDruid1stName",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "Locate Animals", "Invisibility to Animals", "Shillelagh", "Speak With Animals" },
    }, {
      "name" = "uastDruid4thName",
      "comment" = "",
      "kind" = "string array",
      "count" = 6,
      "values" = { "Cure Serious Wounds", "Dispel Magic", "Hallucinatory Forest", "Protection From Lightning", "Repel Insects", "Speak With Plants" },
    }, {
      "name" = "uastDruid5thName",
      "comment" = "",
      "kind" = "string array",
      "count" = 6,
      "values" = { "Commune With Nature", "Control Winds", "Insect Plague", "Sticks To Snakes", "Transmute Rock To Mud", "Wall Of Fire" },
    }, {
      "name" = "uastDruid6thName",
      "comment" = "",
      "kind" = "string array",
      "count" = 5,
      "values" = { "Cure Critical Wounds", "Fire Seeds", "Turn Wood", "Wall Of Thorns", "Weather Summoning" },
    }, {
      "name" = "uastCantripCategoryName",
      "comment" = "",
      "kind" = "string array",
      "count" = 6,
      "values" = { "Useful", "Reversed", "Legerdemain", "Person-Affecting", "Personal", "Haunting" },
    }, {
      "name" = "uastCantripCount",
      "comment" = "The name count per category (20, 12, 6, 10, 10, 8 - the R401 clean-read fix adds Tangle and Tweak).",
      "kind" = "header pin",
      "body" = "static const int k[6] = { 20, 12, 6, 10, 10, 8 }; if (cat < 0) cat = 0; if (cat > 5) cat = 5; return k[cat];",
    }, {
      "name" = "uastCantripName",
      "comment" = "",
      "kind" = "string grid",
      "rows" = { { "Chill", "Clean", "Color", "Dampen", "Dry", "Dust", "Exterminate", "Flavor", "Freshen", "Gather", "Polish", "Salt", "Shine", "Spice", "Sprout", "Stitch", "Sweeten", "Tie", "Warm", "Wrap" }, { "Curdle", "Dirty", "Dusty", "Hairy", "Knot", "Ravel", "Sour", "Spill", "Tangle", "Tarnish", "Untie", "Wilt", "", "", "", "", "", "", "", "" }, { "Change", "Distract", "Hide", "Mute", "Palm", "Present", "", "", "", "", "", "", "", "", "", "", "", "", "", "" }, { "Belch", "Blink", "Cough", "Giggle", "Nod", "Scratch", "Sneeze", "Twitch", "Wink", "Yawn", "", "", "", "", "", "", "", "", "", "" }, { "Bee", "Bluelight", "Bug", "Firefinger", "Gnats", "Mouse", "Smokepuff", "Spider", "Tweak", "Unlock", "", "", "", "", "", "", "", "", "", "" }, { "Creak", "Footfall", "Groan", "Moan", "Rattle", "Tap", "Thump", "Whistle", "", "", "", "", "", "", "", "", "", "", "", "" } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uastClericTableRowCount']() != 20  or m['uastClericReadableCount'](1) != 18  or m['uastClericReadableCount'](2) != 16  or m['uastClericReadableCount'](3) != 20  or m['uastClericFragCount'](4) != 2  or m['uastClericFragCount'](5) != 7  or m['uastClericFragCount'](6) != 4  or m['uastClericFragCount'](7) != 0  or m['uastDruid1stCount']() != 4  or m['uastDruid4thCount']() != 6  or m['uastDruid5thCount']() != 6  or m['uastDruid6thCount']() != 5  or m['uastCantripCategoryCount']() != 6  or total != 66  or  m['uastNoteAllCantripsDescribedHere']() != 1",
      "note" = "U1: the counts",
    }, {
      "expr" = "strcmp(m['uastClericName'](1, 0), \"Bless\") != 0  or strcmp(m['uastClericName'](1, 5), \"Cure Light Wounds\") != 0  or strcmp(m['uastClericName'](1, 14), \"Precipitation\") != 0  or strcmp(m['uastClericName'](1, 19), \"Sanctuary\") != 0  or m['uastClericName'](1, 6)[0] != 0  or m['uastClericName'](1, 13)[0] != 0  or m['uastClericName'](1, r)[0]) ++n; if (n != 18",
      "note" = "U2: the cleric 1st column (the two holes)",
    }, {
      "expr" = "strcmp(m['uastClericName'](2, 5), \"Dust Devil\") != 0  or strcmp(m['uastClericName'](2, 13), \"Silence 15 Radius\") != 0  or strcmp(m['uastClericName'](2, 19), \"Wyvern Watch\") != 0  or m['uastClericName'](2, 0)[0] != 0  or m['uastClericName'](2, 18)[0] != 0  or m['uastClericName'](2, r)[0]) ++n; if (n != 16  or strcmp(m['uastClericName'](3, 0), \"Animate Dead\") != 0  or strcmp(m['uastClericName'](3, 14), \"Negative Plane Protection\") != 0  or strcmp(m['uastClericName'](3, 19), \"Water Walk\") != 0",
      "note" = "U3: the cleric 2nd and 3rd columns",
    }, {
      "expr" = "strcmp(m['uastClericFragName'](4, 0), \"Sticks to Snakes\") != 0  or strcmp(m['uastClericFragName'](4, 1), \"Tongues\") != 0  or strcmp(m['uastClericFragName'](5, 0), \"Commune\") != 0  or strcmp(m['uastClericFragName'](5, 5), \"Spike Growth\") != 0  or strcmp(m['uastClericFragName'](5, 6), \"True Seeing\") != 0  or strcmp(m['uastClericFragName'](6, 3), \"Stone Tell\") != 0  or m['uastClericFragCount'](7) != 0",
      "note" = "U4: the cleric 4th-7th fragments",
    }, {
      "expr" = "strcmp(m['uastDruid1stName'](0), \"Locate Animals\") != 0  or strcmp(m['uastDruid1stName'](1), \"Invisibility to Animals\") != 0  or strcmp(m['uastDruid1stName'](2), \"Shillelagh\") != 0  or strcmp(m['uastDruid1stName'](3), \"Speak With Animals\") != 0  or strcmp(m['uastDruid4thName'](0), \"Cure Serious Wounds\") != 0  or strcmp(m['uastDruid4thName'](5), \"Speak With Plants\") != 0  or strcmp(m['uastDruid5thName'](2), \"Insect Plague\") != 0  or strcmp(m['uastDruid5thName'](3), \"Sticks To Snakes\") != 0  or strcmp(m['uastDruid6thName'](0), \"Cure Critical Wounds\") != 0  or strcmp(m['uastDruid6thName'](4), \"Weather Summoning\") != 0",
      "note" = "U5: the druid tables",
    }, {
      "expr" = "strcmp(m['uastCantripCategoryName'](0), \"Useful\") != 0  or strcmp(m['uastCantripCategoryName'](5), \"Haunting\") != 0  or strcmp(m['uastCantripName'](0, 0), \"Chill\") != 0  or strcmp(m['uastCantripName'](0, 9), \"Gather\") != 0  or strcmp(m['uastCantripName'](0, 10), \"Polish\") != 0  or strcmp(m['uastCantripName'](0, 19), \"Wrap\") != 0  or strcmp(m['uastCantripName'](1, 8), \"Tangle\") != 0  or strcmp(m['uastCantripName'](1, 11), \"Wilt\") != 0  or strcmp(m['uastCantripName'](2, 5), \"Present\") != 0  or strcmp(m['uastCantripName'](3, 9), \"Yawn\") != 0  or strcmp(m['uastCantripName'](4, 8), \"Tweak\") != 0  or strcmp(m['uastCantripName'](4, 9), \"Unlock\") != 0  or strcmp(m['uastCantripName'](5, 7), \"Whistle\") != 0",
      "note" = "U6: the cantrip table",
    }, {
      "expr" = "m['uastMuCantripMaxNewCount']() != 3  or  m['uastMuUsefulOnePerIntPoint']() != 1  or m['uastMuReversedMin']() != 2  or m['uastMuReversedMax']() != 8  or m['uastMuLegerdemainMin']() != 2  or m['uastMuLegerdemainMax']() != 5  or m['uastMuPersonAffectingMin']() != 2  or m['uastMuPersonAffectingMax']() != 8  or m['uastMuPersonalMax']() != 8  or m['uastMuHauntingMin']() != 2  or m['uastMuHauntingMax']() != 5  or m['uastIlMinorIllusionMin']() != 5  or m['uastIlMinorIllusionMax']() != 8  or m['uastIlUsefulIntMinus']() != 3  or m['uastIlUsefulAtInt18']() != 15  or m['uastIlLegerdemainMin']() != 3  or m['uastIlLegerdemainMax']() != 6  or m['uastIlPersonalMax']() != 5  or m['uastIlHauntingMin']() != 5  or m['uastIlHauntingMax']() != 8",
      "note" = "U7: the acquisition prose",
    }, {
      "expr" = "m['reglvl'](\"Cure Light Wounds\", SPELL_CLERIC) != 1  or m['reglvl'](\"Hold Person\", SPELL_CLERIC) != 2  or m['reglvl'](\"Slow Poison\", SPELL_CLERIC) != 2  or m['reglvl'](\"Dispel Magic\", SPELL_CLERIC) != 3  or m['reglvl'](\"Prayer\", SPELL_CLERIC) != 3  or m['reglvl'](\"Cure Critical Wounds\", SPELL_CLERIC) != 4  or m['reglvl'](\"Locate Animals\", SPELL_DRUID) != 1  or m['reglvl'](\"Invisibility To Animals\", SPELL_DRUID) != 1  or m['reglvl'](\"Shillelagh\", SPELL_DRUID) != 1  or m['reglvl'](\"Speak With Animals\", SPELL_DRUID) != 1  or m['reglvl'](\"Cure Serious Wounds\", SPELL_DRUID) != 4  or m['reglvl'](\"Dispel Magic\", SPELL_DRUID) != 4  or m['reglvl'](\"Hallucinatory Forest\", SPELL_DRUID) != 4  or m['reglvl'](\"Repel Insects\", SPELL_DRUID) != 4  or m['reglvl'](\"Commune With Nature\", SPELL_DRUID) != 5  or m['reglvl'](\"Control Winds\", SPELL_DRUID) != 5  or m['reglvl'](\"Insect Plague\", SPELL_DRUID) != 5  or m['reglvl'](\"Sticks to Snakes\", SPELL_DRUID) != 6  or m['reglvl'](\"Cure Critical Wounds\", SPELL_DRUID) != 6  or m['reglvl'](\"Turn Wood\", SPELL_DRUID) != 6  or m['reglvl'](\"Weather Summoning\", SPELL_DRUID) != 6",
      "note" = "U8: the R80/R228 registry seam (live)",
    } },
  "audit" = {
      "label" = "R341: the UA spell tables pin audit",
      "comment" = "The UA SPELL TABLES (pp. 28-31), part 1 - the cleric 1st-3rd table (20 rows, seam-verified against the R80 registry), the cleric 4th-7th fragments, the druid tables (the four readable rows seam-decoded as the 1st-level roster, the \"Insect P|\" fragment seam-decoded as Insect Plague) and the MU cantrip table (64 names, the Gather/Polish merge decoded). The MU spells tables and the illusionist spell table are OCR-scrambled - the item stays open pending the PDF.",
    },
}
