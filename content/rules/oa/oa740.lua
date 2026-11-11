-- oa740: promoted from rules/oa/oa111scrolls.h (the OA TREASURE - SCROLLS, printed capture p. 288 - the scroll notes round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 740,
  "prefix" = "oa740",
  "banner" = {
      "title" = "OA TREASURE - SCROLLS, printed capture p. 288 - the scroll notes round",
      "provenance" = "census 662 -> 663.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 193 closed, 42 open - the scrolls box flips (census 662 -> 663); NEXT - R741: Rods, Staves, and Wands (capture p. 288), prefix dlc (verify free at the landing), audit \"R741 OA rods staves wands audit\", include after rules/oa/oa111scrolls.h",
    },
  "consts" = { {
      "name" = "dlbUseStandardDMGRules",
      "value" = 1,
      "comment" = "the type determination - use the standard rules given in the DMG for the type of scroll found (print capture p. 288)",
    }, {
      "name" = "dlbMagicUsersAsWuJen",
      "value" = 1,
      "comment" = "the first mapping - treating magic-users as wu jen (print capture p. 288)",
    }, {
      "name" = "dlbClericsAsShukenja",
      "value" = 1,
      "comment" = "the second mapping - treating clerics as shukenja (print capture p. 288)",
    }, {
      "name" = "dlbGajinScrollPct",
      "value" = 5,
      "comment" = "the gajin scroll percent - the 5% of all scrolls found containing gajin spells (print capture p. 288)",
    }, {
      "name" = "dlbGajinSpellsFivePct",
      "value" = 1,
      "comment" = "the gajin spells - the 5% of all scrolls found containing gajin spells, either magic-user or clerical (print capture p. 288)",
    }, {
      "name" = "dlbGajinUsedByWuJenShukenja",
      "value" = 1,
      "comment" = "the usability - such spells usable by wu jen and shukenja respectively (print capture p. 288)",
    }, {
      "name" = "dlbGajinAddedToSpellBooks",
      "value" = 1,
      "comment" = "the spell books - the gajin spells even addable to the spell books in the case of the wu jen (print capture p. 288)",
    }, {
      "name" = "dlbProtectionFromDevilsRerolled",
      "value" = 1,
      "comment" = "the protection from devils scroll - not commonly found in Oriental lands, the result rerolled (print capture p. 288)",
    }, {
      "name" = "dlbProtectionFromShapechangersScope",
      "value" = 1,
      "comment" = "the protection from shapechangers scroll - including all hengeyokai and the spirit creatures able to change their form (print capture p. 288)",
    }, {
      "name" = "dlbProtectionFromUndeadRerolled",
      "value" = 1,
      "comment" = "the protection from undead scroll - not commonly found in Oriental lands, the result rerolled (print capture p. 288)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlbGajinScrollPct']() != 5  or  m['dlbUseStandardDMGRules']() != 1  or  m['dlbMagicUsersAsWuJen']() != 1  or  m['dlbClericsAsShukenja']() != 1  or  m['dlbGajinSpellsFivePct']() != 1  or  m['dlbGajinUsedByWuJenShukenja']() != 1  or  m['dlbGajinAddedToSpellBooks']() != 1  or  m['dlbProtectionFromDevilsRerolled']() != 1  or  m['dlbProtectionFromShapechangersScope']() != 1  or  m['dlbProtectionFromUndeadRerolled']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlbUseStandardDMGRules']() != 1  or m['dlbMagicUsersAsWuJen']() != 1  or m['dlbClericsAsShukenja']() != 1  or m['dlbGajinSpellsFivePct']() != 1  or m['dlbGajinUsedByWuJenShukenja']() != 1  or m['dlbGajinAddedToSpellBooks']() != 1  or m['dlbGajinScrollPct']() != 5",
      "note" = "the scroll determination and the gajin spells, healthy values, each condition false",
    }, {
      "expr" = "m['dlbProtectionFromDevilsRerolled']() != 1  or m['dlbProtectionFromShapechangersScope']() != 1  or m['dlbProtectionFromUndeadRerolled']() != 1",
      "note" = "the three protection scroll notes, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R740 OA scrolls audit",
      "comment" = "OA round one hundred twenty-seven (capture p. 288): the Scrolls section - the DMG standard type rules with the wu jen and shukenja mappings, the 5% gajin-spell scrolls and their usability, the three protection scroll notes, single-pass pins per the Chapter 9 provenance shift",
    },
}
