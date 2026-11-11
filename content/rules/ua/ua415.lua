-- ua: promoted from rules/ua/uacantrips4.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 415,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 4 (R415): the PERSON-AFFECTING category (p. 49), 10 cantrips. The R363/R412/ R413/R414 precedents ride: the descriptions pin; the casting-time fraction cells garble in the scan (the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean except two reads: the scan prints \"TVvitch\" for the roster's Twitch (the name resolves via the LIVE R341/R401 roster cross-check - the roster is the independent confirmation), and Giggle prints \"(Charm)\" while Wink prints \"(Enchantment)\" in the SAME section - the print distinguishes the two, so Charm pins AS PRINTED (a NEW school code; the never-guess doctrine). The census: Evocation 8, Enchantment 1 (Wink), Charm 1 (Giggle).  The area lines print clean for ALL 10 blocks - ZERO area holes: the one-person six (Belch, Blink, Cough, Giggle, Nod, Wink - a NEW area kind code) and the one-creature four (Scratch, Sneeze, Twitch, Yawn - a NEW area kind code).  The mechanics pin clean: the Blink half-second momentary read, the Cough 1-3 second spasms, the Giggle 2-3 second chuckle, the Scratch one-second itch relief, and the YAWN SLEEP SUSCEPTIBILITY - the window (the balance of the cast round + the whole following round), the 1 additional vulnerable creature, the 4 or fewer HD band, the 4+1 to 4+4 re-roll band, the up-to 5+2 HD reach, and the 50% unaffected chance.",
    },
  "consts" = { {
      "name" = "ucpPersonAffectingCount",
      "value" = 10,
      "comment" = "The count.",
    }, {
      "name" = "ucpBlinkDurationHalfSecs",
      "value" = 1,
      "comment" = "---- the mechanics pins ---- The Blink read: momentary, lasting no more than half a second (in halves).",
    }, {
      "name" = "ucpCoughMinSeconds",
      "value" = 1,
      "comment" = "The Cough spasms: from 1 to 3 seconds on a failed save.",
    }, {
      "name" = "ucpCoughMaxSeconds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "ucpGiggleMinSeconds",
      "value" = 2,
      "comment" = "The Giggle chuckle: about 2 or 3 seconds on a failed save.",
    }, {
      "name" = "ucpGiggleMaxSeconds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "ucpScratchSeconds",
      "value" = 1,
      "comment" = "The Scratch relief: the scratching takes but a second and the itch ceases.",
    }, {
      "name" = "ucpYawnWindowRounds",
      "value" = 2,
      "comment" = "---- the yawn sleep susceptibility ---- The window: the balance of the round in which the yawn was cast, plus the whole of the following round (the span covers 2 rounds).",
    }, {
      "name" = "ucpYawnExtraVulnerable",
      "value" = 1,
      "comment" = "The extra vulnerable: 1 additional creature of 4 or fewer hit dice may be affected by the sleep spell.",
    }, {
      "name" = "ucpYawnSleepHdLow",
      "value" = 4,
      "comment" = "The low band: creatures of 4 or fewer hit dice (the sleep spell norm).",
    }, {
      "name" = "ucpYawnSleepBandLo",
      "value" = 41,
      "comment" = "The re-roll band: creatures of 4+1 to 4+4 hit dice gain a chance to be affected (encoded lo*10+plus: 41..44).",
    }, {
      "name" = "ucpYawnSleepBandHi",
      "value" = 44,
      "comment" = "",
    }, {
      "name" = "ucpYawnSleepHdMax",
      "value" = 52,
      "comment" = "The reach: even a creature of up to 5+2 hit dice can be affected (encoded 52), rolled as if in the band.",
    }, {
      "name" = "ucpYawnUnaffectedPct",
      "value" = 50,
      "comment" = "The unaffected chance: the over-band creature has a 50% chance of NOT being affected.",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "ucpPersonAffecting",
      "comment" = "The 10 person-affecting cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UcpCantrip T[10] = { { \"Belch\", 0, 8, 0 }, { \"Blink\", 0, 8, 0 }, { \"Cough\", 0, 8, 0 }, { \"Giggle\", 5, 8, 0 }, { \"Nod\", 0, 8, 0 }, { \"Scratch\", 0, 9, 0 }, { \"Sneeze\", 0, 9, 0 }, { \"Twitch\", 0, 9, 0 }, { \"Wink\", 3, 8, 0 }, { \"Yawn\", 0, 9, 0 }, }; if (i < 0) i = 0; if (i > 9) i = 9; return T[i];",
    }, {
      "name" = "ucpSchoolCount",
      "comment" = "The school census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucpPersonAffecting(i).school == s) ++n; return n;",
    }, {
      "name" = "ucpAreaKindCount",
      "comment" = "The area kind census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucpPersonAffecting(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "ucpCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R419) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: order: Sneeze at 1/2, Cough, Giggle and Twitch at 1/3, Scratch and Yawn at 1/8, Belch, Blink, Nod and Wink at 1/10.",
      "kind" = "header pin",
      "body" = "static const int D[10] = { 10, 10, 3, 3, 10, 8, 2, 3, 10, 8 }; if (i < 0) i = 0; if (i > 9) i = 9; return D[i];",
    }, {
      "name" = "ucpCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 10; ++i) if (ucpCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ucpPersonAffectingCount']() != 10  or m['uastCantripCount'](3) != 10",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['ucpSchoolCount'](UCP_EVO) != 8  or m['ucpSchoolCount'](UCP_ABJ) != 0  or m['ucpSchoolCount'](UCP_ALT) != 0  or m['ucpSchoolCount'](UCP_ENCH) != 1  or m['ucpSchoolCount'](UCP_ILL) != 0  or m['ucpSchoolCount'](UCP_CHARM) != 1",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['ucpAreaKindCount'](UCP_AREA_PERSON) != 6  or m['ucpAreaKindCount'](UCP_AREA_CREATURE) != 4  or m['ucpAreaKindCount'](UCP_AREA_HOLE) != 0  or strcmp(m['ucpPersonAffecting'](0).name,m['uastCantripName'](3, 0)) != 0  or m['ucpPersonAffecting'](0) .school != 0  or m['ucpPersonAffecting'](0) .areaKind != 8  or m['ucpPersonAffecting'](0) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](1).name,m['uastCantripName'](3, 1)) != 0  or m['ucpPersonAffecting'](1) .school != 0  or m['ucpPersonAffecting'](1) .areaKind != 8  or m['ucpPersonAffecting'](1) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](2).name,m['uastCantripName'](3, 2)) != 0  or m['ucpPersonAffecting'](2) .school != 0  or m['ucpPersonAffecting'](2) .areaKind != 8  or m['ucpPersonAffecting'](2) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](3).name,m['uastCantripName'](3, 3)) != 0  or m['ucpPersonAffecting'](3) .school != 5  or m['ucpPersonAffecting'](3) .areaKind != 8  or m['ucpPersonAffecting'](3) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](4).name,m['uastCantripName'](3, 4)) != 0  or m['ucpPersonAffecting'](4) .school != 0  or m['ucpPersonAffecting'](4) .areaKind != 8  or m['ucpPersonAffecting'](4) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](5).name,m['uastCantripName'](3, 5)) != 0  or m['ucpPersonAffecting'](5) .school != 0  or m['ucpPersonAffecting'](5) .areaKind != 9  or m['ucpPersonAffecting'](5) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](6).name,m['uastCantripName'](3, 6)) != 0  or m['ucpPersonAffecting'](6) .school != 0  or m['ucpPersonAffecting'](6) .areaKind != 9  or m['ucpPersonAffecting'](6) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](7).name,m['uastCantripName'](3, 7)) != 0  or m['ucpPersonAffecting'](7) .school != 0  or m['ucpPersonAffecting'](7) .areaKind != 9  or m['ucpPersonAffecting'](7) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](8).name,m['uastCantripName'](3, 8)) != 0  or m['ucpPersonAffecting'](8) .school != 3  or m['ucpPersonAffecting'](8) .areaKind != 8  or m['ucpPersonAffecting'](8) .areaVal != 0  or strcmp(m['ucpPersonAffecting'](9).name,m['uastCantripName'](3, 9)) != 0  or m['ucpPersonAffecting'](9) .school != 0  or m['ucpPersonAffecting'](9) .areaKind != 9  or m['ucpPersonAffecting'](9) .areaVal != 0",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['ucpCastTimeDen'](0) != 10  or m['ucpCastTimeDen'](1) != 10  or m['ucpCastTimeDen'](2) != 3  or m['ucpCastTimeDen'](3) != 3  or m['ucpCastTimeDen'](4) != 10  or m['ucpCastTimeDen'](5) != 8  or m['ucpCastTimeDen'](6) != 2  or m['ucpCastTimeDen'](7) != 3  or m['ucpCastTimeDen'](8) != 10  or m['ucpCastTimeDen'](9) != 8",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R419)",
    }, {
      "expr" = "m['ucpBlinkDurationHalfSecs']() != 1  or m['ucpScratchSeconds']() != 1  or m['ucpCoughMinSeconds']() != 1  or m['ucpCoughMaxSeconds']() != 3  or m['ucpGiggleMinSeconds']() != 2  or m['ucpGiggleMaxSeconds']() != 3",
      "note" = "---- the mechanics ----",
    }, {
      "expr" = "m['ucpGiggleMaxSeconds']() >m['ucpCoughMaxSeconds']()  or m['ucpGiggleMinSeconds']() >=m['ucpGiggleMaxSeconds']()",
      "note" = "The cough/giggle bands are distinct and giggle never exceeds cough max.",
    }, {
      "expr" = "m['ucpYawnWindowRounds']() != 2  or m['ucpYawnExtraVulnerable']() != 1  or m['ucpYawnSleepHdLow']() != 4  or m['ucpYawnSleepBandLo']() != 41  or m['ucpYawnSleepBandHi']() != 44  or m['ucpYawnSleepHdMax']() != 52  or m['ucpYawnUnaffectedPct']() != 50",
      "note" = "---- the yawn sleep susceptibility ----",
    }, {
      "expr" = "m['ucpYawnSleepBandLo']() / 10 !=m['ucpYawnSleepBandHi']() / 10  or m['ucpYawnSleepBandLo']() % 10 != 1  or m['ucpYawnSleepBandHi']() % 10 != 4  or m['ucpYawnSleepBandHi']() / 10 !=m['ucpYawnSleepHdLow']()  or m['ucpYawnSleepHdMax']() / 10 !=m['ucpYawnSleepHdLow']() + 1  or m['ucpYawnSleepHdMax']() % 10 != 2",
      "note" = "The band derivation: the re-roll band 41..44 sits in the 4 HD tens, opens at +1, closes at +4, and the 52 reach rides the 5 HD tens with +2.",
    } },
  "audit" = {
      "label" = "R415: the UA person-affecting cantrips pin audit",
      "comment" = "The 10 person-affecting descriptions pin: the names cross-check the R341/R401 roster live (the scan's \"TVvitch\" resolves as Twitch via the roster - the independent confirmation), the schools pin per row (Charm AS PRINTED, a NEW code - Giggle prints Charm while Wink prints Enchantment in the same section), the areas pin per row (ZERO area holes; one person and one creature NEW area kinds), the censuses count, the mechanics pin with the yawn band derivation cross-checking itself; census 341 -> 342.",
    },
}
