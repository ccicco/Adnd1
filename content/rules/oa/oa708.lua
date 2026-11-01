-- oa708: promoted from rules/oa79buso.h (the OA MONSTERS - THE BUSO, printed capture pp. 256-257 - the two-type ghoul);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 708,
  "prefix" = "oa708",
  "banner" = {
      "title" = "OA MONSTERS - THE BUSO, printed capture pp. 256-257 - the two-type ghoul",
      "provenance" = "round census 630 -> 631.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 161 closed, 74 open - the Buso box flips (census 630 -> 631); NEXT - R709: the Carp, Giant (capture p. 257), prefix djw (verify free at the landing), audit \"R709 OA monsters Giant Carp audit\", include after rules/oa79buso.h",
    },
  "consts" = { {
      "name" = "djvBusoTypesCount",
      "value" = 2,
      "comment" = "the Buso type count - the tigbanua and the tagamaling of the two-column stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoNoAppearingMin",
      "value" = 1,
      "comment" = "the Buso appearance minimum - the 1 of the 1-6 of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoNoAppearingMax",
      "value" = 6,
      "comment" = "the Buso appearance maximum - the 6 of the 1-6 of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaAC",
      "value" = 4,
      "comment" = "the tigbanua armor class - the AC 4 of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoMove",
      "value" = 12,
      "comment" = "the Buso movement rate - the move 12 of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaHDNum",
      "value" = 8,
      "comment" = "the tigbanua hit dice - the 8 of the 8 + 2 of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaHDMod",
      "value" = 2,
      "comment" = "the tigbanua hit-dice modifier - the + 2 of the 8 + 2 (print capture p. 256)",
    }, {
      "name" = "djvBusoAttacks",
      "value" = 3,
      "comment" = "the Buso attacks per round - the 3 of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaDmgMin",
      "value" = 1,
      "comment" = "the tigbanua damage minimum - the 1 of the 1-6/1-6/1-10 (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaDmgMid",
      "value" = 6,
      "comment" = "the tigbanua mid damage - the first 6 of the 1-6/1-6/1-10 (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaDmgMax",
      "value" = 10,
      "comment" = "the tigbanua damage maximum - the 10 of the 1-6/1-6/1-10 (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaXPBase",
      "value" = 1400,
      "comment" = "the tigbanua base experience - the 1,400 of the VII/1,400 (print capture p. 256)",
    }, {
      "name" = "djvBusoTigbanuaXPPerHP",
      "value" = 12,
      "comment" = "the tigbanua experience per hit point - the 12/hp of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoTagamalingAC",
      "value" = 5,
      "comment" = "the tagamaling armor class - the AC 5 of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoTagamalingDmgMin",
      "value" = 1,
      "comment" = "the tagamaling damage minimum - the 1 of the 1-4/1-4/1-8 (print capture p. 256)",
    }, {
      "name" = "djvBusoTagamalingDmgMid",
      "value" = 4,
      "comment" = "the tagamaling mid damage - the first 4 of the 1-4/1-4/1-8 (print capture p. 256)",
    }, {
      "name" = "djvBusoTagamalingDmgMax",
      "value" = 8,
      "comment" = "the tagamaling damage maximum - the 8 of the 1-4/1-4/1-8 (print capture p. 256)",
    }, {
      "name" = "djvBusoUncommon",
      "value" = 1,
      "comment" = "the Buso frequency - the uncommon of both columns of the stat block (print capture p. 256)",
    }, {
      "name" = "djvBusoLairNil",
      "value" = 1,
      "comment" = "the Buso in-lair percentage - the Nil of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoTreasureNil",
      "value" = 1,
      "comment" = "the Buso treasure - the Nil of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoMRStandard",
      "value" = 1,
      "comment" = "the Buso magic resistance - the standard of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoIntAnimal",
      "value" = 1,
      "comment" = "the Buso intelligence - the animal of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoChaoticEvil",
      "value" = 1,
      "comment" = "the Buso alignment - the chaotic evil of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoSizeM",
      "value" = 1,
      "comment" = "the Buso size - the M of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoPsionicNil",
      "value" = 1,
      "comment" = "the Buso psionics - the Nil ability and the Nil attack/defense modes of both columns (print capture p. 256)",
    }, {
      "name" = "djvBusoGhoulLike",
      "value" = 1,
      "comment" = "the Buso nature - fearsome ghoul-like creatures (print capture p. 257)",
    }, {
      "name" = "djvBusoCemeteryHabitat",
      "value" = 1,
      "comment" = "the Buso habitat - normally found near cemeteries or in forests or rocky mountains (print capture p. 257)",
    }, {
      "name" = "djvBusoOnceFriendlyNowEnemies",
      "value" = 1,
      "comment" = "the Buso history - once friendly and helpful to men, now one of mankind deadly enemies (print capture p. 257)",
    }, {
      "name" = "djvBusoNightPredators",
      "value" = 1,
      "comment" = "the Buso predation - under the cloak of night they prey on lone travelers and helpless villages (print capture p. 257)",
    }, {
      "name" = "djvBusoTallLean",
      "value" = 1,
      "comment" = "the Buso build - exceptionally tall and lean, long bodies and necks, bony oversized feet, curly dirty hair, flat noses (print capture p. 257)",
    }, {
      "name" = "djvBusoSingleEye",
      "value" = 1,
      "comment" = "the Buso eye - a single eye in the head, either red or yellow (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaFearRadiusFt",
      "value" = 10,
      "comment" = "the tigbanua fear aura - the 10-foot radius (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaFerocious",
      "value" = 1,
      "comment" = "the tigbanua temperament - extremely ferocious, attacks whenever it has the opportunity (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaFearAura",
      "value" = 1,
      "comment" = "the tigbanua aura - radiates a fear aura out to the 10-foot radius (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaLessThanOneHDAutoParalyzed",
      "value" = 1,
      "comment" = "the tigbanua aura rule - creatures with less than 1 HD are automatically paralyzed (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaSaveVsParalyzation",
      "value" = 1,
      "comment" = "the tigbanua aura rule - creatures with 1 HD or more receive a saving throw vs. paralyzation to avoid the effect (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaParalyzedUntilOutOfRadius",
      "value" = 1,
      "comment" = "the tigbanua aura rule - creatures remain paralyzed until they are no longer in the radius (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaSaveGrantsEncounterImmunity",
      "value" = 1,
      "comment" = "the tigbanua aura rule - a successful save grants immunity to the fear aura for the remainder of the encounter (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaClawsAndFangs",
      "value" = 1,
      "comment" = "the tigbanua attack form - the sharp claws and fangs (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaClawDisease",
      "value" = 1,
      "comment" = "the tigbanua claw - transmits a horrible disease (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaSaveVsDeathOrInfected",
      "value" = 1,
      "comment" = "the tigbanua disease rule - all wounded by the creature must make a successful saving throw vs. death or become infected (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaInfectedBecomeTagamaling",
      "value" = 1,
      "comment" = "the tigbanua disease outcome - those infected eventually become tagamaling (print capture p. 257)",
    }, {
      "name" = "djvTigbanuaLowIntelligence",
      "value" = 1,
      "comment" = "the tigbanua mind - not noted for its intelligence (print capture p. 257)",
    }, {
      "name" = "djvTagamalingTransformChancePct",
      "value" = 1,
      "comment" = "the tagamaling transformation - the 1% cumulative nightly chance that the diseased person transforms (print capture p. 257)",
    }, {
      "name" = "djvTagamalingIncurablePct",
      "value" = 100,
      "comment" = "the tagamaling disease limit - once the disease reaches 100% the victim can no longer be cured (print capture p. 257)",
    }, {
      "name" = "djvTagamalingInfectedPerson",
      "value" = 1,
      "comment" = "the tagamaling origin - a person infected by a tigbanua (print capture p. 257)",
    }, {
      "name" = "djvTagamalingNightlyTransformation",
      "value" = 1,
      "comment" = "the tagamaling change - the disease periodically transforms the person, the body changing into that of a buso (print capture p. 257)",
    }, {
      "name" = "djvTagamalingSavageMindless",
      "value" = 1,
      "comment" = "the tagamaling temperament - savage and mindless, attacking and devouring any and all (print capture p. 257)",
    }, {
      "name" = "djvTagamalingSameHDHPAsPerson",
      "value" = 1,
      "comment" = "the tagamaling vitality - the same hit dice and hit points as the person possesses in normal life (print capture p. 257)",
    }, {
      "name" = "djvTagamalingHDVariable",
      "value" = 1,
      "comment" = "the tagamaling hit dice - the special entry of the stat block, variable with the host (print capture p. 256)",
    }, {
      "name" = "djvTagamalingPowersUnusable",
      "value" = 1,
      "comment" = "the tagamaling limitation - characters with special abilities cannot use their powers while transformed (print capture p. 257)",
    }, {
      "name" = "djvTagamalingNoMemory",
      "value" = 1,
      "comment" = "the tagamaling amnesia - the diseased person has no memory of any actions done as a tagamaling (print capture p. 257)",
    }, {
      "name" = "djvTagamalingNightlyAtLimit",
      "value" = 1,
      "comment" = "the tagamaling end state - at 100% the victim changes into a tagamaling every night (print capture p. 257)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djvBusoTypesCount']() != 2  or m['djvBusoNoAppearingMin']() != 1  or m['djvBusoNoAppearingMax']() != 6  or m['djvBusoTigbanuaAC']() != 4  or m['djvBusoMove']() != 12  or m['djvBusoTigbanuaHDNum']() != 8  or m['djvBusoTigbanuaHDMod']() != 2  or m['djvBusoAttacks']() != 3  or m['djvBusoTigbanuaDmgMin']() != 1  or m['djvBusoTigbanuaDmgMid']() != 6  or m['djvBusoTigbanuaDmgMax']() != 10  or m['djvBusoTigbanuaXPBase']() != 1400  or m['djvBusoTigbanuaXPPerHP']() != 12  or m['djvBusoTagamalingAC']() != 5  or m['djvBusoTagamalingDmgMin']() != 1  or m['djvBusoTagamalingDmgMid']() != 4  or m['djvBusoTagamalingDmgMax']() != 8  or m['djvTigbanuaFearRadiusFt']() != 10  or m['djvTagamalingTransformChancePct']() != 1  or m['djvTagamalingIncurablePct']() != 100  or  m['djvBusoUncommon']() != 1  or  m['djvBusoLairNil']() != 1  or  m['djvBusoTreasureNil']() != 1  or  m['djvBusoMRStandard']() != 1  or  m['djvBusoIntAnimal']() != 1  or  m['djvBusoChaoticEvil']() != 1  or  m['djvBusoSizeM']() != 1  or  m['djvBusoPsionicNil']() != 1  or  m['djvBusoGhoulLike']() != 1  or  m['djvBusoCemeteryHabitat']() != 1  or  m['djvBusoOnceFriendlyNowEnemies']() != 1  or  m['djvBusoNightPredators']() != 1  or  m['djvBusoTallLean']() != 1  or  m['djvBusoSingleEye']() != 1  or  m['djvTigbanuaFerocious']() != 1  or  m['djvTigbanuaFearAura']() != 1  or  m['djvTigbanuaLessThanOneHDAutoParalyzed']() != 1  or  m['djvTigbanuaSaveVsParalyzation']() != 1  or  m['djvTigbanuaParalyzedUntilOutOfRadius']() != 1  or  m['djvTigbanuaSaveGrantsEncounterImmunity']() != 1  or  m['djvTigbanuaClawsAndFangs']() != 1  or  m['djvTigbanuaClawDisease']() != 1  or  m['djvTigbanuaSaveVsDeathOrInfected']() != 1  or  m['djvTigbanuaInfectedBecomeTagamaling']() != 1  or  m['djvTigbanuaLowIntelligence']() != 1  or  m['djvTagamalingInfectedPerson']() != 1  or  m['djvTagamalingNightlyTransformation']() != 1  or  m['djvTagamalingSavageMindless']() != 1  or  m['djvTagamalingSameHDHPAsPerson']() != 1  or  m['djvTagamalingHDVariable']() != 1  or  m['djvTagamalingPowersUnusable']() != 1  or  m['djvTagamalingNoMemory']() != 1  or  m['djvTagamalingNightlyAtLimit']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djvBusoTypesCount']() != 2  or m['djvBusoNoAppearingMin']() != 1  or m['djvBusoNoAppearingMax']() != 6  or m['djvBusoTigbanuaAC']() != 4  or m['djvBusoMove']() != 12  or m['djvBusoTigbanuaHDNum']() != 8  or m['djvBusoTigbanuaHDMod']() != 2  or m['djvBusoAttacks']() != 3  or m['djvBusoTigbanuaDmgMin']() != 1  or m['djvBusoTigbanuaDmgMid']() != 6  or m['djvBusoTigbanuaDmgMax']() != 10  or m['djvBusoTigbanuaXPBase']() != 1400  or m['djvBusoTigbanuaXPPerHP']() != 12  or m['djvBusoTagamalingAC']() != 5  or m['djvBusoTagamalingDmgMin']() != 1  or m['djvBusoTagamalingDmgMid']() != 4  or m['djvBusoTagamalingDmgMax']() != 8  or m['djvBusoUncommon']() != 1  or m['djvBusoLairNil']() != 1  or m['djvBusoTreasureNil']() != 1  or m['djvBusoMRStandard']() != 1  or m['djvBusoIntAnimal']() != 1  or m['djvBusoChaoticEvil']() != 1  or m['djvBusoSizeM']() != 1  or m['djvBusoPsionicNil']() != 1",
      "note" = "the stat block - the two types, the uncommon, the 1-6, the tigbanua AC 4 the move 12 the 8 + 2 the 3 attacks of 1-6/1-6/1-10 the VII/1,400 + 12/hp, the tagamaling AC 5 the 3 attacks of 1-4/1-4/1-8, the Nil lair, the Nil treasure, the animal, the chaotic evil, the M, the Nil psionics",
    }, {
      "expr" = "m['djvBusoGhoulLike']() != 1  or m['djvBusoCemeteryHabitat']() != 1  or m['djvBusoOnceFriendlyNowEnemies']() != 1  or m['djvBusoNightPredators']() != 1  or m['djvBusoTallLean']() != 1  or m['djvBusoSingleEye']() != 1",
      "note" = "the buso nature - the ghoul-like, the cemetery and forest and rocky-mountain habitat, the once-friendly now-enemies history, the night predation, the tall lean build, the single red or yellow eye",
    }, {
      "expr" = "m['djvTigbanuaFearRadiusFt']() != 10  or m['djvTigbanuaFerocious']() != 1  or m['djvTigbanuaFearAura']() != 1  or m['djvTigbanuaLessThanOneHDAutoParalyzed']() != 1  or m['djvTigbanuaSaveVsParalyzation']() != 1  or m['djvTigbanuaParalyzedUntilOutOfRadius']() != 1  or m['djvTigbanuaSaveGrantsEncounterImmunity']() != 1  or m['djvTigbanuaClawsAndFangs']() != 1  or m['djvTigbanuaClawDisease']() != 1  or m['djvTigbanuaSaveVsDeathOrInfected']() != 1  or m['djvTigbanuaInfectedBecomeTagamaling']() != 1  or m['djvTigbanuaLowIntelligence']() != 1",
      "note" = "the tigbanua - the ferocious, the 10-foot fear aura, the under-1-HD auto-paralysis, the save vs. paralyzation, the paralyzed until out of radius, the save-granted encounter immunity, the claws and fangs, the claw disease, the save vs. death or infected, the infected become tagamaling, the low intelligence",
    }, {
      "expr" = "m['djvTagamalingTransformChancePct']() != 1  or m['djvTagamalingIncurablePct']() != 100  or m['djvTagamalingInfectedPerson']() != 1  or m['djvTagamalingNightlyTransformation']() != 1  or m['djvTagamalingSavageMindless']() != 1  or m['djvTagamalingSameHDHPAsPerson']() != 1  or m['djvTagamalingHDVariable']() != 1  or m['djvTagamalingPowersUnusable']() != 1  or m['djvTagamalingNoMemory']() != 1  or m['djvTagamalingNightlyAtLimit']() != 1",
      "note" = "the tagamaling - the infected person, the 1% cumulative nightly chance, the savage mindless devouring, the same HD and HP as the person, the variable stat-block hit dice, the powers unusable, the no memory, the 100% incurable limit with the every-night transformation",
    } },
  "audit" = {
      "label" = "R708 OA monsters Buso audit",
      "comment" = "OA round ninety-five (capture pp. 256-257): the Chapter 12 monster roster - the Buso, the first two-column monster of the roster, the stat block and the description riding together, single-pass pins per the Chapter 9 provenance shift",
    },
}
