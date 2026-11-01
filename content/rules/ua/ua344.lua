-- ua344: promoted from rules/uaclericspells2.h (the The UA NEW CLERIC SPELLS (pp. 35-36) pins, R344: the 2nd-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 344,
  "prefix" = "ua344",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (pp. 35-36) pins, R344: the 2nd-level",
      "provenance" = "spell descriptions - aid, detect life, dust devil, enthrall, holy symbol, messenger, withdraw, wyvern watch.  Pin-era pattern (R322): pinned data only - no engine site exists. The R341 cleric table pin (rules/uaspelltables.h) is the name seam.  JUDGMENTs (the decode method): - the digit-garble family (established R343): the OCR prints 7 where 1 belongs in the stat cells. This round's five 7s all decode as 1: aid duration \"7 round + 1/level\" = 1 round + 1/level; detect life casting time \"7 round\" = 1 round; holy symbol casting time \"7 turn\" = 1 turn; messenger duration \"7 hour/level\" = 1 hour/level and casting time \"7 round\" = 1 round. Every \"Level: 2\" cell prints clean - the family is corroborated five times over. - enthrall's area prints \"90\u00b0 radius\" - the degree sign is the OCR's foot mark; decoded as a 90-foot radius. - the wyvern watch header prints \"'Wyvern Watch\" - a stray curly apostrophe before the name; decoded as Wyvern Watch. - holy symbol's \"holy bol\" garble = the tail of \"holy symbol\" lost mid-word; decoded. - messenger's \"may be it nored\" scramble = \"may be ignored\"; decoded. - withdraw's interleaved example: the fragments \"Thus; 5th level experience, ... while but 6 segments of time for all others\" decode as the worked example - a 5th-level caster passes 6 segments for all others (the cleric experiences 6 rounds). The formula: base 2 segments at 1st level, plus one per level beyond (segments = level + 1; 2 + 4 = 6 at 5th). The \"(The DM must allow the caster 1 minute of real time per segment to ponder some problem or question with which the spell caster is confronted)\" fragments decode likewise. - the R341 table 2nd-column hole decodes: the \"draw\" fragment at row 18 (R341 pinned it as a hole; it sorts between Spiritual Hammer and Wyvern Watch) decodes as Withdraw - position-forced by alphabetical continuity and corroborated by this round's prose section. The three leading empty cells include Aid's lost cell (aid sorts before Detect Charm and this round's prose confirms aid as a UA 2nd-level cleric spell) - noted, not row-resolved, pending the PDF. - aid's stat components cell prints empty - a hole; the material component survives in the prose (a tiny strip of white cloth with a sticky substance such as tree sap on the ends, plus the cleric's holy symbol) - pinned from the prose, the stat cell flagged lost. - messenger's range cell prints empty - a hole.  OCR holes (the item stays open - the 3rd-7th levels pin in later rounds; these stay pending the PDF): the aid casting-time cell and stat components cell; the messenger range cell; the aid leading-empty row resolution; the withdraw scrambled column beyond the readable fragments.",
    },
  "consts" = { {
      "name" = "uac2AidName",
      "value" = "Aid (Necromantic - Conjuration)",
      "comment" = "---- aid (Necromantic - Conjuration), p. 35 ----",
    }, {
      "name" = "uac2AidBonusHpMin",
      "value" = 1,
      "comment" = "The recipient gains the benefit of a bless spell plus 1-8 additional hit points.",
    }, {
      "name" = "uac2AidBonusHpMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac2AidExampleStartHp",
      "value" = 8,
      "comment" = "The worked example: a 1st-level fighter with 8 hit points takes 2 damage, then receives aid for 6 additional hit points (12 total, 6 temporary); hit for 7, one regular point and all six temporary points are lost.",
    }, {
      "name" = "uac2AidExampleFirstDamage",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac2AidExampleBonusHp",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac2AidExampleTotalHp",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac2AidExampleSecondDamage",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac2AidExampleRegularLost",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2AidDurationBaseRounds",
      "value" = 1,
      "comment" = "The duration prints \"7 round + 1/level\" - the digit-garble family decodes 1 round + 1/level.",
    }, {
      "name" = "uac2AidDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2AidRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeName",
      "value" = "Detect Life (Divination)",
      "comment" = "---- detect life (Divination), p. 35 ----",
    }, {
      "name" = "uac2DetectLifeRangeFeet",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeDurationRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uac2DetectLifeInchBarrierFeet",
      "value" = 10,
      "comment" = "Each inch of wood or stone barrier counts as 10 feet of open space; a metal barrier of any thickness ruins the spell.",
    }, {
      "name" = "uac2DustDevilName",
      "value" = "Dust Devil (Conjuration/Summoning)",
      "comment" = "---- dust devil (Conjuration/Summoning), p. 35-36 ----",
    }, {
      "name" = "uac2DustDevilAc",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilHitDice",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilMvInches",
      "value" = 18,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilDamageMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilDamageMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilBaseDiameterFeet",
      "value" = 5,
      "comment" = "A small whirlwind: 5 feet diameter at the base, 15 feet tall, 10 feet across at the top.",
    }, {
      "name" = "uac2DustDevilHeightFeet",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilTopDiameterFeet",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilCastingTimeRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilCloudDiameterFeet",
      "value" = 30,
      "comment" = "Skimming loose dust, sand or ash: disperses a cloud 30 feet in diameter; normal vision impossible; creatures blinded until one round after leaving.",
    }, {
      "name" = "uac2DustDevilBlindLingersRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallName",
      "value" = "Enthrall (Enchantment/Charm)",
      "comment" = "---- enthrall (Enchantment/Charm), p. 36 ----",
    }, {
      "name" = "uac2EnthrallCastingTimeRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallRadiusFeet",
      "value" = 90,
      "comment" = "The area prints \"90\u00b0 radius\" - the degree sign is the foot mark; decoded as a 90-foot radius.",
    }, {
      "name" = "uac2EnthrallUnfriendlyRaceSaveMod",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallMaxLevelsOrHd",
      "value" = 4,
      "comment" = "Impossible to enthrall more than 4 levels or hit dice, or a wisdom score greater than 15.",
    }, {
      "name" = "uac2EnthrallMaxWisdom",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallMaxDurationTurns",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallFailedSaveCharisma",
      "value" = 21,
      "comment" = "Failed save: the listeners view the cleric as charisma 21 (loyalty base +70%, reaction adjustment +50%); they stand and listen but do not act on the words as if a suggestion had been cast.",
    }, {
      "name" = "uac2EnthrallLoyaltyBasePct",
      "value" = 70,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallReactionAdjPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallMadeSaveCharisma",
      "value" = 3,
      "comment" = "Successful save: the listener views the cleric as charisma 3, and may (50% chance) hoot and jeer, allowing a new saving throw for the others.",
    }, {
      "name" = "uac2EnthrallJeerChancePct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallOffendedSaveMod",
      "value" = 5,
      "comment" = "Preaching a religion or alignment opposed to the audience's: each offended listener gets a new save at +5.",
    }, {
      "name" = "uac2HolySymbolName",
      "value" = "Holy Symbol (Conjuration/Summoning)",
      "comment" = "---- holy symbol (Conjuration/Summoning), p. 36 ----",
    }, {
      "name" = "uac2HolySymbolCastingTimeTurns",
      "value" = 1,
      "comment" = "The casting time prints \"7 turn\" - the family decodes 1 turn.",
    }, {
      "name" = "uac2HolySymbolMaxPossessed",
      "value" = 2,
      "comment" = "A cleric may possess two holy symbols at one time; the spell can create the spare.",
    }, {
      "name" = "uac2MessengerName",
      "value" = "Messenger (Enchantment/Charm)",
      "comment" = "---- messenger (Enchantment/Charm), p. 36 ----",
    }, {
      "name" = "uac2MessengerMaxIntelligence",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2MessengerDurationHoursPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 hour/level\" and the casting time \"7 round\" - the family decodes 1 hour/level and 1 round.",
    }, {
      "name" = "uac2MessengerCastingTimeRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawName",
      "value" = "Withdraw (Alteration)",
      "comment" = "---- withdraw (Alteration), p. 36 ----",
    }, {
      "name" = "uac2WithdrawCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawRangeZero",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawBaseSegments",
      "value" = 2,
      "comment" = "Base duration 2 segments (2 rounds from the cleric's point of view), plus 1 increment per level of experience - the 5th-level example passes 6 segments for all others.",
    }, {
      "name" = "uac2WithdrawSegmentsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawRealMinutesPerSegment",
      "value" = 1,
      "comment" = "The DM must allow 1 minute of real time per segment to ponder some problem or question.",
    }, {
      "name" = "uac2WyvernWatchName",
      "value" = "Wyvern Watch (Evocation)",
      "comment" = "---- wyvern watch (Evocation), p. 36 ----",
    }, {
      "name" = "uac2WyvernWatchRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchDurationHours",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchSphereDiameterInches",
      "value" = 1,
      "comment" = "The area prints a 1\" diameter sphere.",
    }, {
      "name" = "uac2WyvernWatchTriggerRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchParalysisRoundsPerLevel",
      "value" = 1,
      "comment" = "Save versus spell or stand paralyzed 1 round per level of the caster, until freed by the caster, a dispel magic or a remove paralysis.",
    }, {
      "name" = "uac2WyvernWatchDetectBrightPct",
      "value" = 90,
      "comment" = "Detection before entering: 90% in bright light, 30% in twilight, 0% in darkness.",
    }, {
      "name" = "uac2WyvernWatchDetectTwilightPct",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchDetectDarknessPct",
      "value" = 0,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uac2AidGrantsBless",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2AidMayExceedNormalTotal",
      "value" = true,
      "comment" = "The bless lasts as long as the aid spell, as do the hit points; the recipient may exceed the full normal total.",
    }, {
      "name" = "uac2AidTempHpLostFirst",
      "value" = true,
      "comment" = "Damage comes off the temporary points before regular ones.",
    }, {
      "name" = "uac2AidLostTempHpNotCurable",
      "value" = true,
      "comment" = "Hit points bestowed by aid and then lost cannot be regained by curative magic.",
    }, {
      "name" = "uac2AidMaterialClothAndSap",
      "value" = true,
      "comment" = "The material survives in the prose; the stat cell is lost.",
    }, {
      "name" = "uac2AidComponentsStatCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2AidCastingTimeLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeSeesFeignDeath",
      "value" = true,
      "comment" = "Detects life in a feign death recipient, a coma, a deathlike trance or suspended animation; reveals an astral-traveling creature as alive; works on plants and plant creatures as well as animals.",
    }, {
      "name" = "uac2DetectLifeSeesAstralTraveler",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeWorksOnPlants",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeMetalBarrierRuins",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DetectLifeMentalProtectionRuins",
      "value" = true,
      "comment" = "Any mental protection (psionic or magical) likewise ruins the spell without anything being detected.",
    }, {
      "name" = "uac2DetectLifeFirstAlongLineOfSight",
      "value" = true,
      "comment" = "Detects the first living creature along the line of sight within range, or the first creature crossing it before the duration expires.",
    }, {
      "name" = "uac2DustDevilHitByNormalWeapons",
      "value" = true,
      "comment" = "Hit by normal weapons; magic weapons of any type cause double damage.",
    }, {
      "name" = "uac2DustDevilMagicWeaponDoubleDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilComponentsVS",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilDispelBeyondRange",
      "value" = true,
      "comment" = "Dismissed if ordered beyond 3\" from the caster.",
    }, {
      "name" = "uac2DustDevilWindsHoldGas",
      "value" = true,
      "comment" = "Its winds hold a gas cloud or gaseous creature at bay or push it away (but cannot damage or dispel such a cloud); they put out torches, small campfires, exposed lanterns and other small open flames of non-magical origin.",
    }, {
      "name" = "uac2DustDevilWindsExtinguishSmallFlames",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilCloudBlinds",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2DustDevilCastingRequiresSave",
      "value" = true,
      "comment" = "Spellcasting inside the cloud or the devil is virtually impossible: a save versus spell keeps concentration even if the winds score no damage.",
    }, {
      "name" = "uac2DustDevilAirNativeCanDismiss",
      "value" = true,
      "comment" = "Creatures native to the Elemental Plane of Air (even another of the same sort) can dismiss it at will from 3\" or less.",
    }, {
      "name" = "uac2DustDevilNonNativeUnaffected",
      "value" = true,
      "comment" = "Creatures not native to the plane occupied by the caster are unaffected.",
    }, {
      "name" = "uac2DustDevilResistContactDispels",
      "value" = true,
      "comment" = "Automatically dispelled on contact with innate magic resistance - but only after it gets its chance to hit and do damage.",
    }, {
      "name" = "uac2DustDevilResistDispelsAfterItsAttack",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallComponentsVS",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallRequiresUnderstanding",
      "value" = true,
      "comment" = "The audience must fully understand the caster's language.",
    }, {
      "name" = "uac2EnthrallSameRaceSaves",
      "value" = true,
      "comment" = "Listeners of the same race save versus spell; those of a generally unfriendly different race save at +4.",
    }, {
      "name" = "uac2EnthrallRequiresFullRoundSpeech",
      "value" = true,
      "comment" = "The caster must speak without interruption for a full round; the enchantment lasts while speaking, to a maximum of 6 turns.",
    }, {
      "name" = "uac2EnthrallNotASuggestion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallEndsIfCasterStopsOrActs",
      "value" = true,
      "comment" = "Stopping the speech, any attack against the cleric (a successful hit or a spell cast), or the cleric casting a different spell or performing another action breaks it.",
    }, {
      "name" = "uac2EnthrallAttackOnClericCancels",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2EnthrallJeerAllowsNewSaves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2HolySymbolComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2HolySymbolCreatesOrReplaces",
      "value" = true,
      "comment" = "Prepares a holy symbol or creates a replacement for a lost or damaged one.",
    }, {
      "name" = "uac2HolySymbolMaterialIsTheSymbol",
      "value" = true,
      "comment" = "The symbol-to-be IS the material component (obviously not consumed); it must be crafted of appropriate material per the religion and of proper shape and design - not just any item.",
    }, {
      "name" = "uac2HolySymbolMustBeCrafted",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2HolySymbolOnlyOwnReligion",
      "value" = true,
      "comment" = "No cleric can create a holy symbol of a religion or deity other than the one worshipped.",
    }, {
      "name" = "uac2HolySymbolRadiatesAlignmentAura",
      "value" = true,
      "comment" = "A good or evil cleric's symbol radiates a faint aura of good or evil but is not magical per se; a neutral cleric's symbol has no such aura.",
    }, {
      "name" = "uac2HolySymbolNeutralNoAura",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerRequiresSizeS",
      "value" = true,
      "comment" = "Calls a small (size S) creature of at least animal intelligence; no \"giant\" types; nothing of intelligence 4 or higher, or low intelligence or better.",
    }, {
      "name" = "uac2MessengerExcludesGiantTypes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerLureIsFood",
      "value" = true,
      "comment" = "If the creature is within range, the cleric calls it with food as a lure; a successful save means the spell fails.",
    }, {
      "name" = "uac2MessengerSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerSimpleDirectionsOnly",
      "value" = true,
      "comment" = "The cleric communicates crudely - go to a place, with simple directions; a small item or note can be attached; the animal waits at the location until the duration ends.",
    }, {
      "name" = "uac2MessengerCanCarryNote",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerWaitsUntilDurationEnds",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerRecipientMayIgnore",
      "value" = true,
      "comment" = "A recipient not in small animal or bird form may be ignored; when the duration expires the animal returns to normal activities; the receiver gains no communication ability.",
    }, {
      "name" = "uac2MessengerReceiverGainsNothing",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2MessengerRangeLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole.",
    }, {
      "name" = "uac2WithdrawComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawTimeRatioSegmentToRound",
      "value" = true,
      "comment" = "While but 1 segment passes for those unaffected, the cleric spends 1 round in contemplation.",
    }, {
      "name" = "uac2WithdrawPermitsAuguryCuringInfo",
      "value" = true,
      "comment" = "Permitted acts only: an augury spell, any curing or healing spells, or any informational spells - and only on the cleric himself; casting any of them otherwise ends the withdraw.",
    }, {
      "name" = "uac2WithdrawSpellsOnlyOnSelf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawOtherCastingEndsIt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawNoPhysicalActions",
      "value" = true,
      "comment" = "No walking, running, invisibility or other actions beyond thinking, reading and the like; the cleric can be affected by others' actions; any attack on the cleric that succeeds breaks the spell.",
    }, {
      "name" = "uac2WithdrawAttackBreaksIt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WithdrawDrawHoleDecoded",
      "value" = true,
      "comment" = "The R341 table's \"draw\" fragment (row 18) decodes as this spell - position-forced between Spiritual Hammer and Wyvern Watch, corroborated by the prose (see the JUDGMENTs).",
    }, {
      "name" = "uac2AidLeadingEmptyNoted",
      "value" = true,
      "comment" = "The R341 2nd-column leading empties include aid's lost cell - noted, not row-resolved, pending the PDF.",
    }, {
      "name" = "uac2WyvernWatchComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchGuardsArea",
      "value" = true,
      "comment" = "The insubstantial haze vaguely resembles a wyvern; typically guards an area against intrusion; any creature within 1\" is subject to attack from the spell force.",
    }, {
      "name" = "uac2WyvernWatchFreeDispelOrRemoveParalysis",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchSaveMeansMissed",
      "value" = true,
      "comment" = "A successful save means the target was missed and the spell remains; once a target is struck the paralysis takes effect and the force dissipates; it also dissipates after 8 hours with no intruder struck.",
    }, {
      "name" = "uac2WyvernWatchStrikeDissipates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchDissipatesAfterDuration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac2WyvernWatchMaterialHolySymbol",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uac2WithdrawSegmentsForLevel",
      "comment" = "",
      "kind" = "header pin",
      "body" = "if (level < 1) level = 1; return 1 + level;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac2AidName'](), \"Aid (Necromantic - Conjuration)\") != 0  or m['uac2AidBonusHpMin']() != 1  or m['uac2AidBonusHpMax']() != 8  or  m['uac2AidGrantsBless']() != 1  or  m['uac2AidMayExceedNormalTotal']() != 1  or  m['uac2AidTempHpLostFirst']() != 1  or  m['uac2AidLostTempHpNotCurable']() != 1  or m['uac2AidExampleStartHp']() != 8  or m['uac2AidExampleFirstDamage']() != 2  or m['uac2AidExampleBonusHp']() != 6  or m['uac2AidExampleTotalHp']() != 12  or m['uac2AidExampleSecondDamage']() != 7  or m['uac2AidExampleRegularLost']() != 1  or m['uac2AidDurationBaseRounds']() != 1  or m['uac2AidDurationRoundsPerLevel']() != 1  or m['uac2AidRangeTouch']() != 0  or  m['uac2AidMaterialClothAndSap']() != 1  or  m['uac2AidComponentsStatCellLost']() != 1  or  m['uac2AidCastingTimeLost']() != 1  or  m['uac2AidLeadingEmptyNoted']() != 1",
      "note" = "U1: aid",
    }, {
      "expr" = "strcmp(m['uac2DetectLifeName'](), \"Detect Life (Divination)\") != 0  or m['uac2DetectLifeRangeFeet']() != 10  or m['uac2DetectLifeDurationRounds']() != 5  or m['uac2DetectLifeCastingTimeRounds']() != 1  or  m['uac2DetectLifeComponentsVSM']() != 1  or  m['uac2DetectLifeSeesFeignDeath']() != 1  or  m['uac2DetectLifeSeesAstralTraveler']() != 1  or  m['uac2DetectLifeWorksOnPlants']() != 1  or m['uac2DetectLifeInchBarrierFeet']() != 10  or  m['uac2DetectLifeMetalBarrierRuins']() != 1  or  m['uac2DetectLifeMentalProtectionRuins']() != 1  or  m['uac2DetectLifeFirstAlongLineOfSight']() != 1",
      "note" = "U2: detect life",
    }, {
      "expr" = "strcmp(m['uac2DustDevilName'](), \"Dust Devil (Conjuration/Summoning)\") != 0  or m['uac2DustDevilAc']() != 4  or m['uac2DustDevilHitDice']() != 2  or m['uac2DustDevilMvInches']() != 18  or m['uac2DustDevilDamageMin']() != 1  or m['uac2DustDevilDamageMax']() != 4  or  m['uac2DustDevilHitByNormalWeapons']() != 1  or  m['uac2DustDevilMagicWeaponDoubleDamage']() != 1  or m['uac2DustDevilBaseDiameterFeet']() != 5  or m['uac2DustDevilHeightFeet']() != 15  or m['uac2DustDevilTopDiameterFeet']() != 10  or m['uac2DustDevilRangeInches']() != 3  or m['uac2DustDevilCastingTimeRounds']() != 3  or m['uac2DustDevilDurationRoundsPerLevel']() != 1  or  m['uac2DustDevilComponentsVS']() != 1  or  m['uac2DustDevilDispelBeyondRange']() != 1  or  m['uac2DustDevilWindsHoldGas']() != 1  or  m['uac2DustDevilWindsExtinguishSmallFlames']() != 1  or m['uac2DustDevilCloudDiameterFeet']() != 30  or  m['uac2DustDevilCloudBlinds']() != 1  or m['uac2DustDevilBlindLingersRounds']() != 1  or  m['uac2DustDevilCastingRequiresSave']() != 1  or  m['uac2DustDevilAirNativeCanDismiss']() != 1  or  m['uac2DustDevilNonNativeUnaffected']() != 1  or  m['uac2DustDevilResistContactDispels']() != 1  or  m['uac2DustDevilResistDispelsAfterItsAttack']() != 1",
      "note" = "U3: dust devil",
    }, {
      "expr" = "strcmp(m['uac2EnthrallName'](), \"Enthrall (Enchantment/Charm)\") != 0  or  m['uac2EnthrallComponentsVS']() != 1  or m['uac2EnthrallCastingTimeRounds']() != 1  or m['uac2EnthrallRangeInches']() != 3  or m['uac2EnthrallRadiusFeet']() != 90  or  m['uac2EnthrallRequiresUnderstanding']() != 1  or  m['uac2EnthrallSameRaceSaves']() != 1  or m['uac2EnthrallUnfriendlyRaceSaveMod']() != 4  or m['uac2EnthrallMaxLevelsOrHd']() != 4  or m['uac2EnthrallMaxWisdom']() != 15  or  m['uac2EnthrallRequiresFullRoundSpeech']() != 1  or m['uac2EnthrallMaxDurationTurns']() != 6  or m['uac2EnthrallFailedSaveCharisma']() != 21  or m['uac2EnthrallLoyaltyBasePct']() != 70  or m['uac2EnthrallReactionAdjPct']() != 50  or  m['uac2EnthrallNotASuggestion']() != 1  or  m['uac2EnthrallEndsIfCasterStopsOrActs']() != 1  or  m['uac2EnthrallAttackOnClericCancels']() != 1  or m['uac2EnthrallMadeSaveCharisma']() != 3  or m['uac2EnthrallJeerChancePct']() != 50  or  m['uac2EnthrallJeerAllowsNewSaves']() != 1  or m['uac2EnthrallOffendedSaveMod']() != 5",
      "note" = "U4: enthrall",
    }, {
      "expr" = "strcmp(m['uac2HolySymbolName'](), \"Holy Symbol (Conjuration/Summoning)\") != 0  or  m['uac2HolySymbolComponentsVSM']() != 1  or m['uac2HolySymbolCastingTimeTurns']() != 1  or  m['uac2HolySymbolCreatesOrReplaces']() != 1  or  m['uac2HolySymbolMaterialIsTheSymbol']() != 1  or  m['uac2HolySymbolMustBeCrafted']() != 1  or m['uac2HolySymbolMaxPossessed']() != 2  or  m['uac2HolySymbolOnlyOwnReligion']() != 1  or  m['uac2HolySymbolRadiatesAlignmentAura']() != 1  or  m['uac2HolySymbolNeutralNoAura']() != 1",
      "note" = "U5: holy symbol",
    }, {
      "expr" = "strcmp(m['uac2MessengerName'](), \"Messenger (Enchantment/Charm)\") != 0  or  m['uac2MessengerComponentsVSM']() != 1  or  m['uac2MessengerRequiresSizeS']() != 1  or  m['uac2MessengerExcludesGiantTypes']() != 1  or m['uac2MessengerMaxIntelligence']() != 3  or  m['uac2MessengerLureIsFood']() != 1  or  m['uac2MessengerSaveNegates']() != 1  or  m['uac2MessengerSimpleDirectionsOnly']() != 1  or  m['uac2MessengerCanCarryNote']() != 1  or  m['uac2MessengerWaitsUntilDurationEnds']() != 1  or  m['uac2MessengerRecipientMayIgnore']() != 1  or  m['uac2MessengerReceiverGainsNothing']() != 1  or m['uac2MessengerDurationHoursPerLevel']() != 1  or m['uac2MessengerCastingTimeRounds']() != 1  or  m['uac2MessengerRangeLost']() != 1",
      "note" = "U6: messenger",
    }, {
      "expr" = "strcmp(m['uac2WithdrawName'](), \"Withdraw (Alteration)\") != 0  or  m['uac2WithdrawComponentsVSM']() != 1  or m['uac2WithdrawCastingTimeSegments']() != 3  or m['uac2WithdrawRangeZero']() != 0  or  m['uac2WithdrawTimeRatioSegmentToRound']() != 1  or m['uac2WithdrawBaseSegments']() != 2  or m['uac2WithdrawSegmentsPerLevel']() != 1  or m['uac2WithdrawSegmentsForLevel'](1) != 2  or m['uac2WithdrawSegmentsForLevel'](5) != 6  or m['uac2WithdrawSegmentsForLevel'](9) != 10  or m['uac2WithdrawRealMinutesPerSegment']() != 1  or  m['uac2WithdrawPermitsAuguryCuringInfo']() != 1  or  m['uac2WithdrawSpellsOnlyOnSelf']() != 1  or  m['uac2WithdrawOtherCastingEndsIt']() != 1  or  m['uac2WithdrawNoPhysicalActions']() != 1  or  m['uac2WithdrawAttackBreaksIt']() != 1",
      "note" = "U7: withdraw",
    }, {
      "expr" = "strcmp(m['uac2WyvernWatchName'](), \"Wyvern Watch (Evocation)\") != 0  or  m['uac2WyvernWatchComponentsVSM']() != 1  or m['uac2WyvernWatchRangeInches']() != 3  or m['uac2WyvernWatchCastingTimeSegments']() != 5  or m['uac2WyvernWatchDurationHours']() != 8  or m['uac2WyvernWatchSphereDiameterInches']() != 1  or  m['uac2WyvernWatchGuardsArea']() != 1  or m['uac2WyvernWatchTriggerRangeInches']() != 1  or m['uac2WyvernWatchParalysisRoundsPerLevel']() != 1  or  m['uac2WyvernWatchFreeDispelOrRemoveParalysis']() != 1  or  m['uac2WyvernWatchSaveMeansMissed']() != 1  or  m['uac2WyvernWatchStrikeDissipates']() != 1  or  m['uac2WyvernWatchDissipatesAfterDuration']() != 1  or m['uac2WyvernWatchDetectBrightPct']() != 90  or m['uac2WyvernWatchDetectTwilightPct']() != 30  or m['uac2WyvernWatchDetectDarknessPct']() != 0  or  m['uac2WyvernWatchMaterialHolySymbol']() != 1",
      "note" = "U8: wyvern watch",
    }, {
      "expr" = "strcmp(m['uastClericName'](2, 4), \"Detect Life\") != 0  or strcmp(m['uastClericName'](2, 5), \"Dust Devil\") != 0  or strcmp(m['uastClericName'](2, 6), \"Enthrall\") != 0  or strcmp(m['uastClericName'](2, 9), \"Holy Symbol\") != 0  or strcmp(m['uastClericName'](2, 11), \"Messenger\") != 0  or strcmp(m['uastClericName'](2, 19), \"Wyvern Watch\") != 0  or m['uastClericName'](2, 18)[0] != 0  or  m['uac2WithdrawDrawHoleDecoded']() != 1  or m['uastClericName'](2, r)[0]) ++n; if (n != 16",
      "note" = "U9: the R341 table seam",
    } },
  "audit" = {
      "label" = "R344: the UA new cleric 2nd level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (pp. 35-36), the 2nd level - aid (the bless-plus-1-8 hit points mechanics and the worked example), detect life, dust devil (the AC 4 / 2 HD whirlwind ladder), enthrall (the 90-foot radius, the charisma 21/3 split), holy symbol, messenger, withdraw (the segments = level + 1 formula) and wyvern watch (the detection percentages). The digit-garble family (established R343) decodes this round's five 7s as 1; the R341 table hole at row 18 (the \"draw\" fragment) decodes as withdraw. The item stays open (the 3rd-7th levels).",
    },
}
