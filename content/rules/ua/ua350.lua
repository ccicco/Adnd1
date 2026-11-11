-- ua350: promoted from rules/ua/uadruidspells1.h (the The UA NEW DRUID SPELLS (pp. 42-43) pins, R350: the 1st-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 350,
  "prefix" = "ua350",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (pp. 42-43) pins, R350: the 1st-level",
      "provenance" = "spell descriptions - ceremony, detect balance, detect poison, precipitation.  Pin-era pattern (R322): pinned data only - no engine site exists. The R341 druid table pin (rules/ua/uaspelltables.h) is the name seam.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): three \"Level: 7\" cells print where the level is position-certain 1 (ceremony, detect poison, precipitation) - the section header reads First Level Spells and detect balance prints a clean \"Level: 1\" cell. The same family decodes the detect balance casting time \"7 segment\" and the two \"7 round/level\" durations (detect balance, detect poison) as 1. - the ceremony opener prints \"The druidic ... spell is similar to the clerical spell of the same name\" with a stray \"y\" fragment - the lost word decodes as ceremony (the section subject); the fragment noted. - the ceremony stat block prints empty Components and Casting Time cells - holes; the prose pins mistletoe (always) and the dawn-or-dusk rite setting. - the ceremony variety ladder: the \"1st-level druid\" and \"12th-level druid\" prefixes print clean; the three middle group prefixes are lost cells (\"id:\" is a tail of a lost \"...level druid:\" prefix) - the group membership and order pin (dedication, investiture; initiation, special vows; hallowed ground), the middle prefix numbers stay holes pending the PDF. The \"Th as follows:\" line is the scrambled \"The effects of the various types of druidic ceremony spells are as follows:\" head. - hallowed ground: \"his or her willy grove\" decodes as the druid's own grove (the \"willy\" garble noted); the displaced \"never\" reads \"the trees of the grove will never be affected by disease or other natural disasters\". - cast out: the permission interleave decodes as the ladder druid <- Archdruid <- Great Druid <- Grand Druid (\"Archdruid\" prints displaced before \"performed\"; the \"us\" fragment is a stray tail); the Grand Druid needs no permission but a Hierophant Druid may reverse the Grand Druid at any time. The adverb after \"causing any natural crea- tures to react\" is lost - a hole. - the detect poison opener scrambles two columns: \"By means of this spell the druid is able to determine if some object, creature, or area contains or has been poisoned.\" - precipitation: the name header never prints (the stat block follows detect poison's scrambled opener directly); identified by the gap item list plus \"identical to the 1st-level clerical spell of the same name\" - the R343 clerical precipitation pin. The duration prints \"1 segment/ievel\" = level; the range cell prints empty - a hole (the R343 clerical range was lost too).  OCR holes (the item stays open - the 2nd-7th levels pin in later rounds; these stay pending the PDF): the ceremony components cell beyond the prose mistletoe and the empty casting time cell; the three middle ceremony variety prefix numbers; the cast out react-adverb; the detect balance range cell; the precipitation name header, school line and range cell.",
    },
  "consts" = { {
      "name" = "uad1CeremonyName",
      "value" = "Ceremony (Invocation)",
      "comment" = "---- ceremony (Invocation), p. 42-43 ----",
    }, {
      "name" = "uad1CeremonyLevel",
      "value" = 1,
      "comment" = "The stat block prints \"Level: 7\" - the digit-garble family decodes 1 (the section header and the R343 family precedent).",
    }, {
      "name" = "uad1CeremonyVarietyCount",
      "value" = 9,
      "comment" = "The nine ceremony varieties, in list order. The caster level pins clean for the 1st (the first three) and the 12th (cast out); the three middle group prefixes are lost cells.",
    }, {
      "name" = "uad1ComingOfAgeUsualAge",
      "value" = 14,
      "comment" = "Coming of age: usually at age 14, symbolic of entrance into adulthood; the +1 bonus to a single saving throw matches the clerical version.",
    }, {
      "name" = "uad1ComingOfAgeSaveBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad1CastOutUnwillingSaveMod",
      "value" = -4,
      "comment" = "An unwilling recipient receives a saving throw versus spell, at -4, to negate.",
    }, {
      "name" = "uad1DetectBalanceName",
      "value" = "Detect Balance (Divination)",
      "comment" = "---- detect balance (Divination), p. 43 ----",
    }, {
      "name" = "uad1DetectBalanceLevel",
      "value" = 1,
      "comment" = "This one prints a clean \"Level: 1\" cell.",
    }, {
      "name" = "uad1DetectBalanceCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segment\" - the digit-garble family decodes 1 segment.",
    }, {
      "name" = "uad1DetectBalanceDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round/level.",
    }, {
      "name" = "uad1DetectPoisonName",
      "value" = "Detect Poison (Divination)",
      "comment" = "---- detect poison (Divination), p. 43 ----",
    }, {
      "name" = "uad1DetectPoisonLevel",
      "value" = 1,
      "comment" = "The stat block prints \"Level: 7\" - the family decodes 1.",
    }, {
      "name" = "uad1DetectPoisonCastingTimeRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round/level.",
    }, {
      "name" = "uad1DetectPoisonScanVolumeCubicYards",
      "value" = 1,
      "comment" = "About 1 cubic yard of space can be perused per round - the druid cannot tell if an entire pond is poisoned, but can tell of a portion (or something within it) scanned during a round.",
    }, {
      "name" = "uad1DetectPoisonTypeChancePctPerLevel",
      "value" = 5,
      "comment" = "A 5% chance per level of experience also discovers the type of poison used or contained: contact (insinuative), ingestive, or respirative (gas).",
    }, {
      "name" = "uad1DetectPoisonTypeCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad1PrecipName",
      "value" = "Precipitation",
      "comment" = "---- precipitation, p. 43 ---- The name header never prints - the stat block follows the detect poison scrambled opener directly; identified by the gap item list plus \"identical to the 1st-level clerical spell of the same name\" (the R343 clerical pin).",
    }, {
      "name" = "uad1PrecipLevel",
      "value" = 1,
      "comment" = "The stat block prints \"Level: 7\" - the family decodes 1.",
    }, {
      "name" = "uad1PrecipCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad1PrecipDurationSegmentsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"1 segment/ievel\" - the OCR \"ievel\" reads level.",
    }, {
      "name" = "uad1PrecipCylinderDiameterInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad1PrecipCylinderHeightInches",
      "value" = 12,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uad1CeremonyRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonySaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyAoeOneCreatureItemOrArea",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyComponentsIncludeMistletoe",
      "value" = true,
      "comment" = "The components and casting time cells print empty - holes; the prose pins that the components always include mistletoe.",
    }, {
      "name" = "uad1CeremonyComponentsCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyCastingTimeCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonySimilarToClerical",
      "value" = true,
      "comment" = "The opener decodes: the druidic ceremony spell is similar to the clerical spell of the same name.",
    }, {
      "name" = "uad1CeremonyNoAuraOfMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyKnowAlignmentRevealsNeutrality",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyIndicatedOrLowerLevel",
      "value" = true,
      "comment" = "A druid of the indicated or lower level can cast each rite.",
    }, {
      "name" = "uad1RestEternalBlocksRaiseDeadAndResurrection",
      "value" = true,
      "comment" = "Rest eternal: the soul is hastened to its final resting place; raise dead and resurrection will not restore life afterwards - a wish would serve.",
    }, {
      "name" = "uad1RestEternalWishWorks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1MarriageIdenticalToClerical",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DedicationRequiresTrueNeutral",
      "value" = true,
      "comment" = "Dedication: taken into the ranks of followers/worshipers, provided the character is true neutral; charged, as druids, with preserving and protecting nature and the balance.",
    }, {
      "name" = "uad1DedicationChargesBalanceKeeping",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1InvestitureBeforeAspirant",
      "value" = true,
      "comment" = "Investiture: must be performed before a character can become an Aspirant (1st-level druid); conveys no other benefit.",
    }, {
      "name" = "uad1InvestitureNoOtherBenefit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1InitiationGrantsShapechangeAndWoodlandImmunity",
      "value" = true,
      "comment" = "Initiation: imbues the shape-changing and woodland-charm immunity powers available upon attaining 7th level; must be performed immediately after the druid begins advancing through the 7th level or it will not work.",
    }, {
      "name" = "uad1InitiationMustFollowSeventhLevelStart",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1InitiationUsuallyBySeventhPlusDruid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1InitiationSelfCastUnusual",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1SpecialVowsNotOnPaladins",
      "value" = true,
      "comment" = "Special vows: same fashion as the clerical rite; does not work upon paladins, but functions upon cavaliers of any alignment.",
    }, {
      "name" = "uad1SpecialVowsWorksOnCavaliersAnyAlignment",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1HallowedGroundOwnGrove",
      "value" = true,
      "comment" = "Hallowed ground: cast on the druid's own grove; the trees will never be affected by disease or other natural disasters; the ground stays hallowed while the druid keeps the grove as his or her permanent base.",
    }, {
      "name" = "uad1HallowedGroundTreesNeverDiseased",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1HallowedGroundLastsWhilePermanentBase",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutExcommunicationForSacrilege",
      "value" = true,
      "comment" = "Cast out: excommunication or punishment for sacrilege upon the natural environment or violations of druidic principles; the effects may be lessened later by a reversed version cast by the same druid or another of at least as high a level; never completely neutralized except by a Hierophant Druid of any level.",
    }, {
      "name" = "uad1CastOutLessenedByReversedVersion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutReverserAtLeastEqualLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutOnlyHierophantNeutralizes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutAuraAffectsNaturalCreatures",
      "value" = true,
      "comment" = "The cast-out druid exudes an aura causing any natural creatures to react [adverb lost - a hole]; this includes all animals native to the woodlands, domesticated beasts such as horses and dogs, and all druids and their followers.",
    }, {
      "name" = "uad1CastOutReactAdverbLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutAuraIncludesDomesticAndDruids",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutNeedsArchdruidPermission",
      "value" = true,
      "comment" = "The permission ladder: a druid needs permission from his or her Archdruid; an Archdruid similarly from the Great Druid; the Great Druid from the Grand Druid; the Grand Druid needs no permission, but a Hierophant Druid may reverse the Grand Druid at any time. A denied or offset druid may be punished by higher-ranking hierarchy members.",
    }, {
      "name" = "uad1ArchdruidNeedsGreatDruidPermission",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1GreatDruidNeedsGrandDruidPermission",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1GrandDruidNeedsNoPermission",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1GrandDruidReversibleByHierophant",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CastOutDeniedOrOffsetPunishable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1CeremonyRiteInGroveOrHealthyForest",
      "value" = true,
      "comment" = "The components always include mistletoe; the rite must be performed in a druid grove or another natural, healthy patch of forest, normally at dawn or dusk (night and day in balance).",
    }, {
      "name" = "uad1CeremonyAtDawnOrDusk",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceRangeLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole.",
    }, {
      "name" = "uad1DetectBalanceSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceAoeOnePerRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceDetectsNonNeutralForces",
      "value" = true,
      "comment" = "The spell determines if non-neutral alignments are at work in the area of effect or upon the object or creature; a partly neutral alignment (neutral good) radiates a mild aura; one with no neutral part (chaotic good) gives off a strong aura.",
    }, {
      "name" = "uad1DetectBalancePartlyNeutralMildAura",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceNoNeutralPartStrongAura",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceNotExactAlignment",
      "value" = true,
      "comment" = "It does not determine exact alignment - only whether neutral; a paladin and a chaotic evil thief radiate the same strength.",
    }, {
      "name" = "uad1DetectBalanceSameStrengthForSameNeutrality",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceNoAuraOnPlainItems",
      "value" = true,
      "comment" = "It will not function upon non-living items without a natural aura (a vial of poison) but works upon an aligned magical sword; unknowable alignment or similar magic blocks the read; a true neutral subject (another druid) produces a smooth, well-balanced aura of neutrality.",
    }, {
      "name" = "uad1DetectBalanceWorksOnAlignedMagicItem",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceUnknowableAlignmentBlocks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectBalanceTrueNeutralSmoothAura",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonRangeZero",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonOpenerScrambleDecoded",
      "value" = true,
      "comment" = "The scrambled opener decodes: by means of this spell the druid is able to determine if some object, creature, or area contains or has been poisoned.",
    }, {
      "name" = "uad1DetectPoisonPortionNotWholePond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonOneFailureEndsTypeDetection",
      "value" = true,
      "comment" = "More than one area can be scanned during the duration, but any single failure on the 5% type roll makes the spell useless for type detection for the remainder of that casting.",
    }, {
      "name" = "uad1DetectPoisonMaterialMistletoe",
      "value" = true,
      "comment" = "The components are mistletoe plus a yew leaf; the yew leaf turns brown if poison is present, so several may be needed to utilize the entire duration.",
    }, {
      "name" = "uad1DetectPoisonMaterialYewLeaf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonYewLeafTurnsBrown",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1DetectPoisonSeveralLeavesNeeded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1PrecipNameHeaderLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1PrecipSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1PrecipIdenticalToClerical",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1PrecipComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad1PrecipRangeLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole (the R343 clerical range was lost too).",
    }, {
      "name" = "uad1PrecipSaveNoneAndSpecial",
      "value" = true,
      "comment" = "The saving throw prints \"None (& special)\".",
    }, {
      "name" = "uad1PrecipAddsMistletoeToClerical",
      "value" = true,
      "comment" = "The druidic version is identical to the 1st-level clerical spell of the same name except that the druid needs mistletoe as an additional material component.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uad1CeremonyVarietyName",
      "comment" = "",
      "kind" = "string array",
      "count" = 9,
      "values" = { "Coming of Age", "Rest Eternal", "Marriage", "Dedication", "Investiture", "Initiation", "Special Vows", "Hallowed Ground", "Cast Out" },
    }, {
      "name" = "uad1CeremonyVarietyCasterLevel",
      "comment" = "",
      "kind" = "header pin",
      "body" = "// 1 for the first three; 12 for cast out; 0 marks the // lost middle prefixes (pending the PDF). static const int k[9] = { 1, 1, 1, 0, 0, 0, 0, 0, 12, }; if (i < 0) i = 0; if (i > 8) i = 8; return k[i];",
    }, {
      "name" = "uad1DetectPoisonTypeName",
      "comment" = "",
      "kind" = "string array",
      "count" = 3,
      "values" = { "Contact (Insinuative)", "Ingestive", "Respirative (Gas)" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad1CeremonyName'](), \"Ceremony (Invocation)\") != 0  or m['uad1CeremonyLevel']() != 1  or  m['uad1CeremonyRangeTouch']() != 1  or  m['uad1CeremonySaveSpecial']() != 1  or  m['uad1CeremonyDurationPermanent']() != 1  or  m['uad1CeremonyAoeOneCreatureItemOrArea']() != 1  or  m['uad1CeremonyComponentsIncludeMistletoe']() != 1  or  m['uad1CeremonyComponentsCellLost']() != 1  or  m['uad1CeremonyCastingTimeCellLost']() != 1  or  m['uad1CeremonySimilarToClerical']() != 1  or  m['uad1CeremonyNoAuraOfMagic']() != 1  or  m['uad1CeremonyKnowAlignmentRevealsNeutrality']() != 1  or m['uad1CeremonyVarietyCount']() != 9  or strcmp(m['uad1CeremonyVarietyName'](0), \"Coming of Age\") != 0  or strcmp(m['uad1CeremonyVarietyName'](2), \"Marriage\") != 0  or strcmp(m['uad1CeremonyVarietyName'](3), \"Dedication\") != 0  or strcmp(m['uad1CeremonyVarietyName'](6), \"Special Vows\") != 0  or strcmp(m['uad1CeremonyVarietyName'](8), \"Cast Out\") != 0  or m['uad1CeremonyVarietyCasterLevel'](0) != 1  or m['uad1CeremonyVarietyCasterLevel'](2) != 1  or m['uad1CeremonyVarietyCasterLevel'](4) != 0  or m['uad1CeremonyVarietyCasterLevel'](8) != 12  or  m['uad1CeremonyIndicatedOrLowerLevel']() != 1  or m['uad1ComingOfAgeUsualAge']() != 14  or m['uad1ComingOfAgeSaveBonus']() != 1  or  m['uad1RestEternalBlocksRaiseDeadAndResurrection']() != 1  or  m['uad1RestEternalWishWorks']() != 1  or  m['uad1MarriageIdenticalToClerical']() != 1  or  m['uad1DedicationRequiresTrueNeutral']() != 1  or  m['uad1DedicationChargesBalanceKeeping']() != 1  or  m['uad1InvestitureBeforeAspirant']() != 1  or  m['uad1InvestitureNoOtherBenefit']() != 1  or  m['uad1InitiationGrantsShapechangeAndWoodlandImmunity']() != 1  or  m['uad1InitiationMustFollowSeventhLevelStart']() != 1  or  m['uad1InitiationUsuallyBySeventhPlusDruid']() != 1  or  m['uad1InitiationSelfCastUnusual']() != 1  or  m['uad1SpecialVowsNotOnPaladins']() != 1  or  m['uad1SpecialVowsWorksOnCavaliersAnyAlignment']() != 1  or  m['uad1HallowedGroundOwnGrove']() != 1  or  m['uad1HallowedGroundTreesNeverDiseased']() != 1  or  m['uad1HallowedGroundLastsWhilePermanentBase']() != 1  or  m['uad1CastOutExcommunicationForSacrilege']() != 1  or  m['uad1CastOutLessenedByReversedVersion']() != 1  or  m['uad1CastOutReverserAtLeastEqualLevel']() != 1  or  m['uad1CastOutOnlyHierophantNeutralizes']() != 1  or  m['uad1CastOutAuraAffectsNaturalCreatures']() != 1  or  m['uad1CastOutReactAdverbLost']() != 1  or  m['uad1CastOutAuraIncludesDomesticAndDruids']() != 1  or  m['uad1CastOutNeedsArchdruidPermission']() != 1  or  m['uad1ArchdruidNeedsGreatDruidPermission']() != 1  or  m['uad1GreatDruidNeedsGrandDruidPermission']() != 1  or  m['uad1GrandDruidNeedsNoPermission']() != 1  or  m['uad1GrandDruidReversibleByHierophant']() != 1  or  m['uad1CastOutDeniedOrOffsetPunishable']() != 1  or m['uad1CastOutUnwillingSaveMod']() != -4  or  m['uad1CeremonyRiteInGroveOrHealthyForest']() != 1  or  m['uad1CeremonyAtDawnOrDusk']() != 1",
      "note" = "U1: ceremony",
    }, {
      "expr" = "strcmp(m['uad1DetectBalanceName'](), \"Detect Balance (Divination)\") != 0  or  m['uad1DetectBalanceComponentsVSM']() != 1  or m['uad1DetectBalanceLevel']() != 1  or m['uad1DetectBalanceCastingTimeSegments']() != 1  or  m['uad1DetectBalanceRangeLost']() != 1  or  m['uad1DetectBalanceSaveNone']() != 1  or m['uad1DetectBalanceDurationRoundsPerLevel']() != 1  or  m['uad1DetectBalanceAoeOnePerRound']() != 1  or  m['uad1DetectBalanceDetectsNonNeutralForces']() != 1  or  m['uad1DetectBalancePartlyNeutralMildAura']() != 1  or  m['uad1DetectBalanceNoNeutralPartStrongAura']() != 1  or  m['uad1DetectBalanceNotExactAlignment']() != 1  or  m['uad1DetectBalanceSameStrengthForSameNeutrality']() != 1  or  m['uad1DetectBalanceNoAuraOnPlainItems']() != 1  or  m['uad1DetectBalanceWorksOnAlignedMagicItem']() != 1  or  m['uad1DetectBalanceUnknowableAlignmentBlocks']() != 1  or  m['uad1DetectBalanceTrueNeutralSmoothAura']() != 1",
      "note" = "U2: detect balance",
    }, {
      "expr" = "strcmp(m['uad1DetectPoisonName'](), \"Detect Poison (Divination)\") != 0  or  m['uad1DetectPoisonComponentsVSM']() != 1  or m['uad1DetectPoisonLevel']() != 1  or  m['uad1DetectPoisonRangeZero']() != 1  or m['uad1DetectPoisonCastingTimeRounds']() != 1  or  m['uad1DetectPoisonSaveNone']() != 1  or m['uad1DetectPoisonDurationRoundsPerLevel']() != 1  or  m['uad1DetectPoisonAoeSpecial']() != 1  or  m['uad1DetectPoisonOpenerScrambleDecoded']() != 1  or m['uad1DetectPoisonScanVolumeCubicYards']() != 1  or  m['uad1DetectPoisonPortionNotWholePond']() != 1  or m['uad1DetectPoisonTypeChancePctPerLevel']() != 5  or m['uad1DetectPoisonTypeCount']() != 3  or strcmp(m['uad1DetectPoisonTypeName'](0), \"Contact (Insinuative)\") != 0  or strcmp(m['uad1DetectPoisonTypeName'](1), \"Ingestive\") != 0  or strcmp(m['uad1DetectPoisonTypeName'](2), \"Respirative (Gas)\") != 0  or  m['uad1DetectPoisonOneFailureEndsTypeDetection']() != 1  or  m['uad1DetectPoisonMaterialMistletoe']() != 1  or  m['uad1DetectPoisonMaterialYewLeaf']() != 1  or  m['uad1DetectPoisonYewLeafTurnsBrown']() != 1  or  m['uad1DetectPoisonSeveralLeavesNeeded']() != 1",
      "note" = "U3: detect poison",
    }, {
      "expr" = "strcmp(m['uad1PrecipName'](), \"Precipitation\") != 0  or  m['uad1PrecipNameHeaderLost']() != 1  or  m['uad1PrecipSchoolLost']() != 1  or  m['uad1PrecipIdenticalToClerical']() != 1  or  m['uad1PrecipComponentsVSM']() != 1  or m['uad1PrecipLevel']() != 1  or m['uad1PrecipCastingTimeSegments']() != 3  or  m['uad1PrecipRangeLost']() != 1  or  m['uad1PrecipSaveNoneAndSpecial']() != 1  or m['uad1PrecipDurationSegmentsPerLevel']() != 1  or m['uad1PrecipCylinderDiameterInches']() != 3  or m['uad1PrecipCylinderHeightInches']() != 12  or  m['uad1PrecipAddsMistletoeToClerical']() != 1  or m['uad1PrecipCylinderDiameterInches']() !=m['uac1PrecipCylinderDiameterInches']()  or m['uad1PrecipCylinderHeightInches']() !=m['uac1PrecipCylinderHeightInches']()",
      "note" = "U4: precipitation",
    }, {
      "expr" = "m['uastDruid1stCount']() != 4  or strcmp(m['uastDruid1stName'](0), \"Locate Animals\") != 0  or strcmp(m['uastDruid1stName'](1), \"Invisibility to Animals\") != 0  or strcmp(m['uastDruid1stName'](2), \"Shillelagh\") != 0  or strcmp(m['uastDruid1stName'](3), \"Speak With Animals\") != 0",
      "note" = "U5: the R341 table seam",
    } },
  "audit" = {
      "label" = "R350: the UA new druid 1st level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (pp. 42-43), the 1st level - ceremony (the nine varieties with the cast-out permission ladder), detect balance, detect poison (the yew leaf) and precipitation (the name header lost - identified via the R343 clerical pin). The digit-garble family decodes the three \"Level: 7\" cells, the \"7 segment\" and the two \"7 round/level\" cells as 1 (detect balance prints the clean 1). The item stays open (the 2nd-7th levels).",
    },
}
