-- wsg: promoted from rules/wsgprof.h (the The WSG WILDERNESS PROFICIENCIES, R425:);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 425,
  "prefix" = "wsg",
  "banner" = {
      "title" = "The WSG WILDERNESS PROFICIENCIES, R425:",
      "provenance" = "the wilderness arc opener. The printed p. 12 grids pin whole (Table 1: the 14 class rows; Table 2: the 25 proficiency rows) with the Proficiency Check system, the improving rule and the slot rules; census 350 -> 351. Pin-era pattern (R322); the WSG arc mirrors the R322 UA opener.  Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), pdf page 13 = printed p. 12 - the Table 1/2 grids read from the IIIF page image (the text layer drops the grid columns); the rule prose verified whole.",
    },
  "consts" = { {
      "name" = "wsgCheckDieSides",
      "value" = 20,
      "comment" = "The check uses a twenty-sided die.",
    }, {
      "name" = "wsgCheckAutoFail",
      "value" = 19,
      "comment" = "An unmodified die roll of 19 or 20 always fails.",
    }, {
      "name" = "wsgAbilityCap",
      "value" = 18,
      "comment" = "An Appropriate Ability score greater than 18 is treated as 18.",
    }, {
      "name" = "wsgCheckFloorIn20",
      "value" = 2,
      "comment" = "Even a character with an Appropriate Ability of 18 or better keeps at least a 10 percent (2 in 20) chance of failing any check.",
    }, {
      "name" = "wsgImprovingStep",
      "value" = -2,
      "comment" = "Improving an existing proficiency (a nonweapon slot gained at 3rd level or higher): each extra slot gives a cumulative -2 die-roll modifier.",
    }, {
      "name" = "wsgImprovingMinLevel",
      "value" = 3,
      "comment" = "Improving uses slots gained at 3rd level or higher.",
    }, {
      "name" = "wsgExpandingBonusSlots",
      "value" = 1,
      "comment" = "The Dungeon Master may allow one additional nonweapon proficiency slot at 1st level - only if all of the character nonweapon slots are filled right away.",
    }, {
      "name" = "wsgHorsemanZeroLevelSlots",
      "value" = 1,
      "comment" = "0-level horsemen and lancers begin with one nonweapon proficiency.",
    }, {
      "name" = "wsgHorsemanSecondSlotLevel",
      "value" = 1,
      "comment" = "The horseman second nonweapon proficiency arrives at 1st level.",
    }, {
      "name" = "wsgClassCount",
      "value" = 14,
      "comment" = "The census: 14 rows.",
    }, {
      "name" = "wsgProfCount",
      "value" = 25,
      "comment" = "The census: 25 rows.",
    }, {
      "name" = "wsgSingleSlotProfs",
      "value" = 20,
      "comment" = "The Table 2 slot census: one-slot rows.",
    }, {
      "name" = "wsgDoubleSlotProfs",
      "value" = 5,
      "comment" = "The Table 2 slot census: two-slot rows.",
    }, {
      "name" = "wsgWisdomProfs",
      "value" = 11,
      "comment" = "The Table 2 ability census: wisdom rows.",
    }, {
      "name" = "wsgNeverCheckProfs",
      "value" = 7,
      "comment" = "The census of the rows that never make a check.",
    }, {
      "name" = "wsgHardestModifier",
      "value" = -3,
      "comment" = "The harshest Table 2 modifier: riding, land-based.",
    } },
  "bools" = { {
      "name" = "wsgCheckRolls1d20",
      "value" = true,
      "comment" = "A Proficiency Check is a roll of 1d20 against the Appropriate Ability.",
    }, {
      "name" = "wsgImproved19Succeeds",
      "value" = true,
      "comment" = "An improved proficiency succeeds on an unmodified 19.",
    }, {
      "name" = "wsgNatural20Fails",
      "value" = true,
      "comment" = "No matter how much a proficiency is improved, an unmodified 20 still fails.",
    }, {
      "name" = "wsgWeaponSlotHoldsNonweapon",
      "value" = true,
      "comment" = "A weapon proficiency slot can be filled with a nonweapon proficiency.",
    }, {
      "name" = "wsgNonweaponSlotHoldsWeapon",
      "value" = false,
      "comment" = "The reverse is not allowed: a nonweapon slot never holds a weapon proficiency.",
    }, {
      "name" = "wsgExpandingFirstLevelOnly",
      "value" = true,
      "comment" = "The extra slot comes at 1st level only.",
    }, {
      "name" = "wsgExpandingDelayedIsLost",
      "value" = true,
      "comment" = "A delayed extra slot is lost and cannot be filled later.",
    }, {
      "name" = "wsgBardAsOtherClasses",
      "value" = true,
      "comment" = "The bard Table 1 row reads \"as other classes\" - the -1 sentinel below.",
    } },
  "switches" = { {
      "name" = "wsgProfNeverChecks",
      "values" = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
      "default" = 0,
      "comment" = "True when the proficiency never makes a Proficiency Check (the NA-ability and the 99-modifier rows agree row for row).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = " m['wsgCheckRolls1d20']() != 1  or m['wsgCheckDieSides']() != 20  or m['wsgCheckAutoFail']() != 19  or m['wsgAbilityCap']() != 18  or m['wsgCheckFloorIn20']() != 2  or  m['wsgImproved19Succeeds']() != 1  or  m['wsgNatural20Fails']() != 1  or m['wsgImprovingStep']() != -2  or m['wsgImprovingMinLevel']() != 3",
      "note" = "",
    }, {
      "expr" = " m['wsgWeaponSlotHoldsNonweapon']() != 1  or m['wsgNonweaponSlotHoldsWeapon']()  or  m['wsgExpandingBonusSlots']() != 1  or  m['wsgExpandingFirstLevelOnly']() != 1  or  m['wsgExpandingDelayedIsLost']() != 1  or m['wsgHorsemanZeroLevelSlots']() != 1  or m['wsgHorsemanSecondSlotLevel']() != 1  or  m['wsgBardAsOtherClasses']() != 1  or m['wsgClassCount']() != 14  or m['wsgProfCount']() != 25",
      "note" = "",
    }, {
      "expr" = "m['wsgSingleSlotProfs']() != 20 or m['wsgDoubleSlotProfs']() != 5 or m['wsgWisdomProfs']() != 11 or m['wsgNeverCheckProfs']() != 7 or m['wsgHardestModifier']() != -3 or m['wsgProfNeverChecks'](0) != 0 or m['wsgProfNeverChecks'](1) != 0 or m['wsgProfNeverChecks'](2) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsgProfNeverChecks'](3) != 1 or m['wsgProfNeverChecks'](4) != 0 or m['wsgProfNeverChecks'](5) != 0 or m['wsgProfNeverChecks'](6) != 0 or m['wsgProfNeverChecks'](7) != 1 or m['wsgProfNeverChecks'](8) != 0 or m['wsgProfNeverChecks'](9) != 0 or m['wsgProfNeverChecks'](10) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsgProfNeverChecks'](11) != 0 or m['wsgProfNeverChecks'](12) != 0 or m['wsgProfNeverChecks'](13) != 1 or m['wsgProfNeverChecks'](14) != 0 or m['wsgProfNeverChecks'](15) != 0 or m['wsgProfNeverChecks'](16) != 0 or m['wsgProfNeverChecks'](17) != 0 or m['wsgProfNeverChecks'](18) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsgProfNeverChecks'](19) != 1 or m['wsgProfNeverChecks'](20) != 1 or m['wsgProfNeverChecks'](21) != 1 or m['wsgProfNeverChecks'](22) != 0 or m['wsgProfNeverChecks'](23) != 1 or m['wsgProfNeverChecks'](24) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R425: the WSG proficiencies pin audit",
      "comment" = "The wilderness arc opener pins the WSG proficiency system (rules/wsgprof.h, prefix wsg): the Proficiency Check system (1d20 vs the Appropriate Ability, the unmodified 19/20 auto-fail, the 18 cap, the 2-in-20 floor), the improving rule (a cumulative -2 per extra slot, from 3rd level; an improved 19 succeeds, a natural 20 always fails), the slot rules (a weapon slot may hold a nonweapon proficiency, never the reverse) and the expanding optional rule (one extra nonweapon slot at 1st level, all slots filled right away - a delayed slot is lost); Table 1 (the 14 class rows, the bard \"as other classes\" sentinel, the horseman footnote) and Table 2 (the 25 rows) pin with the censuses verified and the denominator arithmetic - the book own cleric and illusionist examples; census 350 -> 351.",
    },
}
