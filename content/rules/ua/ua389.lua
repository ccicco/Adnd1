-- ua: promoted from rules/ua/uaappendq.h (the The UA APPENDIX Q: WEAPONLESS);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 389,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA APPENDIX Q: WEAPONLESS",
      "provenance" = "COMBAT pins, R389: the pp. 106-108 stretch - six items, one fully clean (the throwing rules) plus five mechanics-clean with flagged holes (the System I height example cell, the pummeling table row bodies, the kicking tail, the grappling size bands, the overbearing AC prose). Nothing fully garbles. The R160 overlap RECONCILED: the DMG pp. 72-73 system stays the engine default; this header pins the UA System I / System II layer as its own data - the R374 dial precedent. Pin-era pattern (R322).",
    },
  "consts" = { {
      "name" = "uaqSysOneUserTypeCount",
      "value" = 3,
      "comment" = "Used by humans, demi-humans and humanoids only, against the same.",
    }, {
      "name" = "uaqSysOneActionCount",
      "value" = 3,
      "comment" = "The three steps: choose the action (pummeling, grappling or overbearing), roll to hit, the DM administers the result.",
    }, {
      "name" = "uaqSysOneHeightPctLimit",
      "value" = 125,
      "comment" = "The target cannot exceed 125 percent of the attacker's height.",
    }, {
      "name" = "uaqSysOneExampleShortFt",
      "value" = 4,
      "comment" = "The four-foot example:",
    }, {
      "name" = "uaqSysOneExampleTallFt",
      "value" = 5,
      "comment" = "no use against creatures of more than five feet.",
    }, {
      "name" = "uaqSysOnePummelDelaySegments",
      "value" = 1,
      "comment" = "A pummeling hit delays the action 1 segment and negates spell casting.",
    }, {
      "name" = "uaqSysOnePummelDamageLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqSysOnePummelDamageHi",
      "value" = 2,
      "comment" = "Damage 1-2 points; the strength bonus only with a weapon such as a mailed glove.",
    }, {
      "name" = "uaqSysOneGrappleHoldRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqSysOneGrappledToHitPenalty",
      "value" = 2,
      "comment" = "While held: +2 to be hit, -2 to hit.",
    }, {
      "name" = "uaqSysOneGrappledHitByBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqSysOneProneHitByBonus",
      "value" = 4,
      "comment" = "Prone opponents are +4 to be hit until regaining their feet.",
    }, {
      "name" = "uaqSysOneInitPenalty",
      "value" = 2,
      "comment" = "Weaponless initiative at a -2 penalty.",
    }, {
      "name" = "uaqPumMayRosterCount",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumMayNotRosterCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uaqPumCannotRosterCount",
      "value" = 5,
      "comment" = "Cannot be pummeled: shambling mounds, elementals, all demons, slimes and fungus creatures.",
    }, {
      "name" = "uaqPumInitPenalty",
      "value" = 4,
      "comment" = "Initiative at -4 plus the dexterity modifiers.",
    }, {
      "name" = "uaqPumSurpriseOrBehindToHitBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumResolutionSteps",
      "value" = 4,
      "comment" = "Resolve: the item type, the vulnerability, the to-hit versus the effective AC, then the stunning table.",
    }, {
      "name" = "uaqPumObjTypeCount",
      "value" = 4,
      "comment" = "The four object types: small soft (bare fist or foot), small hard (mailed fist or pommel), large soft (an unconscious figure), large hard (a table or chair).",
    }, {
      "name" = "uaqPumObjSmallSoft",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uaqPumObjSmallHard",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqPumObjLargeSoft",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumObjLargeHard",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uaqPumExposedNaturalAcWorst",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiNaturalLo",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiNaturalHi",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumUnexposedNaturalAcBest",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumTableRows",
      "value" = 3,
      "comment" = "The Pummeling Table: 3 vulnerability rows by 3 data columns (the R394 clean read: the print merges small hard with large soft in the middle column), the chance per point of strength of stunning;",
    }, {
      "name" = "uaqPumTableCols",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uaqPumExposedSmallSoftPerPt",
      "value" = 2,
      "comment" = "the exposed row decoded from the clean worked example: 2 percent per",
    }, {
      "name" = "uaqPumExposedSmallSoftCap",
      "value" = 40,
      "comment" = "point, 40 percent at 18/01;",
    }, {
      "name" = "uaqPumExposedSmallHardPerPt",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumExposedSmallHardCap",
      "value" = 75,
      "comment" = "4 percent per point, 75 percent at 18/01;",
    }, {
      "name" = "uaqPumExposedLargeHardPerPt",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uaqPumExposedLargeHardCap",
      "value" = 95,
      "comment" = "5 percent per point, 95 percent at 18/01.",
    }, {
      "name" = "uaqPumFragPair1PerPt",
      "value" = 1,
      "comment" = "The printed fragment pairs (the row bodies OCR-scramble): 1 percent",
    }, {
      "name" = "uaqPumFragPair1Cap",
      "value" = 20,
      "comment" = "per point with 20 at 18/01,",
    }, {
      "name" = "uaqPumFragPair2PerPt",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumFragPair2Cap",
      "value" = 40,
      "comment" = "2 percent per point with 40 at 18/01,",
    }, {
      "name" = "uaqPumFragPair3PerPt",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumFragPair3Cap",
      "value" = 75,
      "comment" = "4 percent per point with 75 at 18/01 - the attribution flagged,",
    }, {
      "name" = "uaqPumExStrength",
      "value" = 15,
      "comment" = "The example: a strength-15 fighter versus padded armor (exposed) - 30 percent bare-fist, 60 percent with a dagger pommel, 75 percent with a chair.",
    }, {
      "name" = "uaqPumExSmallSoftPct",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uaqPumExSmallHardPct",
      "value" = 60,
      "comment" = "",
    }, {
      "name" = "uaqPumExLargeHardPct",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uaqPumStunSegmentsLo",
      "value" = 1,
      "comment" = "A stunned opponent stays so 1-10 segments, unable to act, spells lost,",
    }, {
      "name" = "uaqPumStunSegmentsHi",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaqPumRestunUnconsciousLo",
      "value" = 1,
      "comment" = "concentration broken; a second stun brings 1-4 rounds unconscious.",
    }, {
      "name" = "uaqPumRestunUnconsciousHi",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumStunnedHitByBonus",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumSmallSoftDamageLo",
      "value" = 1,
      "comment" = "Damage: small soft objects inflict 1-2 points, small hard 1-3 (the printed fragments), whether or",
    }, {
      "name" = "uaqPumSmallSoftDamageHi",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumSmallHardDamageLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqPumSmallHardDamageHi",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uaqPumThievesBehindToHitBonus",
      "value" = 4,
      "comment" = "thieves (with thief-acrobats and assassins) gain +4 to hit from behind;",
    }, {
      "name" = "uaqPumCavaliersBareHandToHitPenalty",
      "value" = 2,
      "comment" = "cavaliers (with paladins) pummel bare-handed at -2 to hit.",
    }, {
      "name" = "uaqKickJumperClassCount",
      "value" = 3,
      "comment" = "jumpers (monks, thief-acrobats, barbarians) kick any portion of a",
    }, {
      "name" = "uaqThrowSmallRangeFeet",
      "value" = 30,
      "comment" = "Throwing: a small object hurled 30 feet, a large one no more than 10;",
    }, {
      "name" = "uaqThrowLargeRangeFeet",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaqThrowToHitLongRangeMod",
      "value" = -5,
      "comment" = "the throw reads a missile at long range (-5) plus strength if applicable;",
    }, {
      "name" = "uaqGrapInitPenalty",
      "value" = 1,
      "comment" = "Initiative at -1; damage earlier in the round ruins the attempt.",
    }, {
      "name" = "uaqGrapResolutionSteps",
      "value" = 2,
      "comment" = "Resolve: the effective AC (ignoring shield and magic armor, counting rings, protection devices, bracers and magical plate), then the to-hit roll.",
    }, {
      "name" = "uaqGrapVictimToHitPenalty",
      "value" = 2,
      "comment" = "the held target is -2 to hit and +2 to be hit, dexterity negated.",
    }, {
      "name" = "uaqGrapVictimHitByBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqGrapBreakWayCount",
      "value" = 5,
      "comment" = "The hold breaks five ways: the release;",
    }, {
      "name" = "uaqGrapCounterAttacksAtPenalty",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqGrapPerExtraMemberBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqGrapDefSMaxSizeS",
      "value" = 3,
      "comment" = "The grapple counts: a size-S defender takes 3 size-S attackers, 1-2",
    }, {
      "name" = "uaqGrapDefSBySizeMHi",
      "value" = 2,
      "comment" = "size-M, or 1 size-L;",
    }, {
      "name" = "uaqGrapDefSBySizeL",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqGrapDefMMaxSizeM",
      "value" = 3,
      "comment" = "a size-M defender takes 3 size-M (the rest of the",
    }, {
      "name" = "uaqGrapDefLMaxSizeL",
      "value" = 3,
      "comment" = "a size-L defender takes 3 size-L; a prone figure 8 size-S, 6 size-M or 4",
    }, {
      "name" = "uaqGrapProneMaxSizeS",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uaqGrapProneMaxSizeM",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaqGrapProneMaxSizeL",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqOvbResolutionSteps",
      "value" = 2,
      "comment" = "Resolve: the effective AC, then the to-hit roll;",
    }, {
      "name" = "uaqOvbProneHitByBonus",
      "value" = 4,
      "comment" = "the prone are +4 to be hit and strike at -2",
    }, {
      "name" = "uaqOvbProneStrikePenalty",
      "value" = 2,
      "comment" = "until regaining their feet, and may be grappled and pummeled regardless",
    }, {
      "name" = "uaqOvbAcRows",
      "value" = 3,
      "comment" = "The Armor Class Adjustment for Size table reads clean: 3 defender rows by",
    }, {
      "name" = "uaqOvbAcCols",
      "value" = 3,
      "comment" = "3 attacker columns; the diagonal is zero;",
    }, {
      "name" = "uaqOvbAcDefSVsS",
      "value" = 0,
      "comment" = "a size-S defender: 0 versus S, +2 versus M, +4 versus L;",
    }, {
      "name" = "uaqOvbAcDefSVsM",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcDefSVsL",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcDefMVsS",
      "value" = -4,
      "comment" = "a size-M defender: -4 versus S, 0 versus M, +2 versus L;",
    }, {
      "name" = "uaqOvbAcDefMVsM",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcDefMVsL",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcDefLVsS",
      "value" = -8,
      "comment" = "a size-L defender: -8 versus S, -4 versus M, 0 versus L.",
    }, {
      "name" = "uaqOvbAcDefLVsM",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcDefLVsL",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uaqOvbFootFourLegsAcAdj",
      "value" = -6,
      "comment" = "The footing list: 4 legs -6, 6 legs -8, more than 6 legs -10;",
    }, {
      "name" = "uaqOvbFootSixLegsAcAdj",
      "value" = -8,
      "comment" = "",
    }, {
      "name" = "uaqOvbFootMoreLegsAcAdj",
      "value" = -10,
      "comment" = "",
    }, {
      "name" = "uaqOvbPerExtraFigureBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqOvbTargetSMaxSizeS",
      "value" = 6,
      "comment" = "The overbear counts read clean: a size-S target takes 6 size-S, 4 size-M",
    }, {
      "name" = "uaqOvbTargetSBySizeM",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqOvbTargetSBySizeL",
      "value" = 2,
      "comment" = "or 2 size-L;",
    }, {
      "name" = "uaqOvbTargetMMaxSizeS",
      "value" = 8,
      "comment" = "a size-M target 8 size-S, 6 size-M, 4 size-L;",
    }, {
      "name" = "uaqOvbTargetMBySizeM",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaqOvbTargetMBySizeL",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqOvbTargetLMaxSizeS",
      "value" = 12,
      "comment" = "a size-L target 12 size-S, 8 size-M, 6 size-L.",
    }, {
      "name" = "uaqOvbTargetLBySizeM",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uaqOvbTargetLBySizeL",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaqPartItemTotal",
      "value" = 6,
      "comment" = "The part ledger: six items - the R394 clean read fills every flagged hole; all six fully clean, none garbled.",
    }, {
      "name" = "uaqPartCleanCount",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaqPartFlaggedCount",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uaqPartGarbledCount",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uaqSysOneSixFtExampleFt",
      "value" = 6,
      "comment" = "System I: the six-foot example - a six-foot being affects creatures 7 1/2 feet or shorter.",
    }, {
      "name" = "uaqSysOneSixFtLimitTenths",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uaqPumUnexMergedPerPt",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uaqPumUnexMergedCap",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uaqPumUnexLargeHardPerPt",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumUnexLargeHardCap",
      "value" = 40,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiSmallSoftPerPt",
      "value" = 1,
      "comment" = "Semi-exposed: 1 and 20 small soft; 2 and 40 merged; 4 and 75 large hard.",
    }, {
      "name" = "uaqPumSemiSmallSoftCap",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiMergedPerPt",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiMergedCap",
      "value" = 40,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiLargeHardPerPt",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiLargeHardCap",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uaqPumLargeDamageLo",
      "value" = 1,
      "comment" = "The large-object damage: all large objects inflict 1-4.",
    }, {
      "name" = "uaqPumLargeDamageHi",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uaqPumAcrobatStunCap",
      "value" = 95,
      "comment" = "",
    }, {
      "name" = "uaqGrapDefMBySizeLHi",
      "value" = 2,
      "comment" = "The size-M band: three size-M attackers, or one or two size-L.",
    } },
  "bools" = { {
      "name" = "uaqSysOneSimpleQuickSystem",
      "value" = true,
      "comment" = "The first system: very simple, used quickly in need.",
    }, {
      "name" = "uaqSysTwoOutgrowthMorePowerful",
      "value" = true,
      "comment" = "The second system: an outgrowth of the first, greater detail, the more powerful of the two.",
    }, {
      "name" = "uaqSysOneSixFtExampleGarbles",
      "value" = false,
      "comment" = "The six-foot example height cell OCR-lost - flagged, PDF-gated.",
    }, {
      "name" = "uaqSysOneToHitStrengthOnlyMod",
      "value" = true,
      "comment" = "The to-hit roll: the standard class chance modified only for strength.",
    }, {
      "name" = "uaqSysOneDefenderArmorDexMagic",
      "value" = true,
      "comment" = "The defender gains armor, dexterity and magic benefits.",
    }, {
      "name" = "uaqSysOnePummelStrBonusNeedsWeapon",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqSysOnePummelMultiNoExtraDelay",
      "value" = true,
      "comment" = "No further delay for multiple pummels in the same round.",
    }, {
      "name" = "uaqSysOneGrappleNoDamage",
      "value" = true,
      "comment" = "A grappling attack inflicts no damage, holds the opponent 1 round.",
    }, {
      "name" = "uaqSysOneGrappleAutoBreaksNextRound",
      "value" = true,
      "comment" = "The grapple breaks automatically at the start of the next round.",
    }, {
      "name" = "uaqSysOneOverbearKnocksProne",
      "value" = true,
      "comment" = "A successful overbearing attack inflicts no damage but knocks the opponent prone.",
    }, {
      "name" = "uaqSysOneSpoiledByPriorDamage",
      "value" = true,
      "comment" = "Damage suffered before the attack spoils it.",
    }, {
      "name" = "uaqPumAvailWithStrengthScore",
      "value" = true,
      "comment" = "Available to any creature with a strength score (or the equivalent); players, most humans, giants and vampires may, most other undead, dragons and non-humanoids may not.",
    }, {
      "name" = "uaqPumTargetNonUndeadNonVegetable",
      "value" = true,
      "comment" = "The target must be a non-undead, non-vegetable organic native of the Prime Material Plane.",
    }, {
      "name" = "uaqPumTargetPrimeNative",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumDemonExceptionGarbles",
      "value" = false,
      "comment" = "The demon exception cell OCR-lost - flagged, PDF-gated.",
    }, {
      "name" = "uaqPumSameOrSmallerSizeClass",
      "value" = true,
      "comment" = "Same or smaller size class only; any size if the target is prone.",
    }, {
      "name" = "uaqPumAnySizeIfTargetProne",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumDexModsStillApply",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumSurpriseNoInitPenalty",
      "value" = true,
      "comment" = "Surprise or from-behind attacks take no penalty and strike at +2.",
    }, {
      "name" = "uaqPumBehindNoInitPenalty",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumSpoiledByPriorDamage",
      "value" = true,
      "comment" = "Damage from the attacked creature first spoils the pummel.",
    }, {
      "name" = "uaqPumLargeObjPickupRound",
      "value" = true,
      "comment" = "Large objects take a round to pick up.",
    }, {
      "name" = "uaqPumMoreVulnerableCategoryWins",
      "value" = true,
      "comment" = "A target qualifying for two categories counts as the more vulnerable.",
    }, {
      "name" = "uaqPumExposedBareHeadOrFace",
      "value" = true,
      "comment" = "Exposed: bare head or face, ordinary cap or clothing, leather or padded armor, or natural AC 7 or worse.",
    }, {
      "name" = "uaqPumExposedOrdinaryCapClothing",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumExposedLeatherOrPadded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiRingToPlateMail",
      "value" = true,
      "comment" = "Semi-exposed: standard armor between ring and plate mail, or natural AC between 7 and 2.",
    }, {
      "name" = "uaqPumUnexposedFullOrFieldPlate",
      "value" = true,
      "comment" = "Unexposed: full or field plate, or natural AC 2 or better.",
    }, {
      "name" = "uaqPumVulnIgnoresShieldsAndMagicArmor",
      "value" = true,
      "comment" = "Vulnerability ignores shields and magic armor bonuses.",
    }, {
      "name" = "uaqPumEffAcShieldIgnoredUnlessBuckler",
      "value" = true,
      "comment" = "Effective AC ignores the shield unless a buckler; magic and dexterity count.",
    }, {
      "name" = "uaqPumEffAcMagicAndDexCount",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumAcaReadsFistOrOpenHand",
      "value" = true,
      "comment" = "Weapon-to-AC adjustments read the pummel as fist or open hand.",
    }, {
      "name" = "uaqPumTableRowBodiesGarble",
      "value" = false,
      "comment" = "the unattributed cells OCR-lost - flagged, PDF-gated.",
    }, {
      "name" = "uaqPumStr1801PlusCountsAs1801",
      "value" = true,
      "comment" = "Strength 18/01 or higher reads as 18/01 for stunning.",
    }, {
      "name" = "uaqPumExPaddedArmorExposed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumStunNoActions",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumStunSpellsLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumStunConcentrationBroken",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumStunnedLosesDexAndShield",
      "value" = true,
      "comment" = "The stunned defend without dexterity or shield, +4 to be hit.",
    }, {
      "name" = "uaqPumDamageWhetherOrNotStun",
      "value" = true,
      "comment" = "not a stun occurs; the conventional-manner rule excludes normal weapon damage.",
    }, {
      "name" = "uaqPumLargeDamageCellsGarble",
      "value" = false,
      "comment" = "The large-object damage cells OCR-lost - flagged, PDF-gated.",
    }, {
      "name" = "uaqPumMonksNoInitPenalty",
      "value" = true,
      "comment" = "Class notes: monks take no pummeling initiative penalty and may pummel or strike open-hand;",
    }, {
      "name" = "uaqPumMonksPummelOrOpenHand",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumThiefTumblingNoteGarbles",
      "value" = false,
      "comment" = "the thief-acrobat tumbling note OCR-lost - flagged, PDF-gated;",
    }, {
      "name" = "uaqKickBareFeetSmallSoft",
      "value" = true,
      "comment" = "Kicking: bare feet read small soft, metal-shod boots small hard;",
    }, {
      "name" = "uaqKickMetalShodSmallHard",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqKickSameSizeWaistDownArmorOnly",
      "value" = true,
      "comment" = "a same-size defender counts only armor from the waist down;",
    }, {
      "name" = "uaqKickSmallerTailGarbles",
      "value" = false,
      "comment" = "the smaller-target tail OCR-lost - flagged, PDF-gated;",
    }, {
      "name" = "uaqKickJumperAnyPortionSameSize",
      "value" = true,
      "comment" = "same-size target; a higher elevation kicks any portion.",
    }, {
      "name" = "uaqKickHigherElevationAnyPortion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqThrowStrengthModApplies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqThrowMissScattersGrenadeLike",
      "value" = true,
      "comment" = "misses scatter as grenade-like missiles.",
    }, {
      "name" = "uaqGrapAvailIntelligentRestraint",
      "value" = true,
      "comment" = "Grappling: any intelligent creature that can conceivably restrain an opponent.",
    }, {
      "name" = "uaqGrapNoNonCorporeal",
      "value" = true,
      "comment" = "Cannot grapple: the non-corporeal, the astral and ethereal natives,",
    }, {
      "name" = "uaqGrapNoAstralEthereal",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapNoUnintelligentSlimes",
      "value" = true,
      "comment" = "the non-intelligent slimes and jellies (a beholder or a bound orc, for instance).",
    }, {
      "name" = "uaqGrapBeholderExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapBoundOrcExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapPurposeDelaysOrRestrains",
      "value" = true,
      "comment" = "The grapple delays an upcoming action or restrains the opponent",
    }, {
      "name" = "uaqGrapPurposeSentenceGarbles",
      "value" = false,
      "comment" = "(the purpose sentence OCR-lost - flagged, PDF-gated).",
    }, {
      "name" = "uaqGrapLargerUnlessProne",
      "value" = true,
      "comment" = "Larger creatures cannot be grappled unless prone",
    }, {
      "name" = "uaqGrapLargerWordGarbles",
      "value" = false,
      "comment" = "(the size word lost - position-decoded, flagged).",
    }, {
      "name" = "uaqGrapSpoiledByPriorDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapEffAcIgnoresShieldMagicArmor",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapRingsProtectionBracersCount",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapMagicalPlateCounts",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapNoDamage",
      "value" = true,
      "comment" = "A hold inflicts no damage and prevents further action that round;",
    }, {
      "name" = "uaqGrapPreventsFurtherAction",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapDexNegatedWhileHeld",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapBreakByRelease",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapBreakByInflictingDamage",
      "value" = true,
      "comment" = "damage on the attacker (at -2);",
    }, {
      "name" = "uaqGrapCounterAttackerKeepsMagicDex",
      "value" = true,
      "comment" = "a counter-grapple (the original attacker keeps magic and dexterity,",
    }, {
      "name" = "uaqGrapCounterStrToHitAsAcBonus",
      "value" = true,
      "comment" = "plus the strength to-hit bonus as AC bonus;",
    }, {
      "name" = "uaqGrapStr17ExampleTailGarbles",
      "value" = false,
      "comment" = "the Str-17 example tail OCR-lost - flagged);",
    }, {
      "name" = "uaqGrapBreakByCounterGrapple",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapBreakByBendBars",
      "value" = true,
      "comment" = "a bend-bars roll;",
    }, {
      "name" = "uaqGrapBreakByAcrobatEvasion",
      "value" = true,
      "comment" = "a thief-acrobat tumbles out on the evasion percentage.",
    }, {
      "name" = "uaqGrapHeldAsLargeSoftObject",
      "value" = true,
      "comment" = "A held figure serves as a large soft pummeling object if liftable.",
    }, {
      "name" = "uaqGrapNeutralizesOneOfMany",
      "value" = true,
      "comment" = "Versus multiple separate attacks the grapple neutralizes only one",
    }, {
      "name" = "uaqGrapScorpionExample",
      "value" = true,
      "comment" = "(the scorpion claw-or-sting example); same-weapon multiples all go.",
    }, {
      "name" = "uaqGrapSameWeaponAllNeutralized",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqGrapGroupSingleRoll",
      "value" = true,
      "comment" = "A similar group grapples on a single roll, +2 per member beyond the first.",
    }, {
      "name" = "uaqGrapDefMBandsGarble",
      "value" = false,
      "comment" = "band OCR-lost - flagged, PDF-gated);",
    }, {
      "name" = "uaqOvbAnyVsAny",
      "value" = true,
      "comment" = "Overbearing: any creature against any other with a discernible upright",
    }, {
      "name" = "uaqOvbNeedsDiscernibleUpright",
      "value" = true,
      "comment" = "position (not a purple worm or gelatinous cube).",
    }, {
      "name" = "uaqOvbPurpleWormCubeException",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqOvbNoInitModification",
      "value" = true,
      "comment" = "A normal attack, no initiative modification;",
    }, {
      "name" = "uaqOvbSpoiledByPriorDamage",
      "value" = true,
      "comment" = "prior damage in the round negates it.",
    }, {
      "name" = "uaqOvbNoInherentDamage",
      "value" = true,
      "comment" = "no inherent damage (the situation may inflict it - flaming oil, a pit);",
    }, {
      "name" = "uaqOvbSituationMayDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqOvbProneGrapplePummelAnySize",
      "value" = true,
      "comment" = "of size class;",
    }, {
      "name" = "uaqOvbAcProseGarbles",
      "value" = false,
      "comment" = "the effective-AC prose OCR-lost - flagged, PDF-gated.",
    }, {
      "name" = "uaqOvbNoLegsCannotBeOverborne",
      "value" = true,
      "comment" = "no legs, never overborne;",
    }, {
      "name" = "uaqOvbLargeMultiLegRiseAuto",
      "value" = true,
      "comment" = "size-L multi-leg creatures rise automatically the next round.",
    }, {
      "name" = "uaqOvbGroupSingleRoll",
      "value" = true,
      "comment" = "A similar group overbears on a single roll, +1 per figure after the first;",
    }, {
      "name" = "uaqOvbWeakestToHitUsed",
      "value" = true,
      "comment" = "a dissimilar group rolls the weakest to-hit",
    }, {
      "name" = "uaqOvbWeakestSentenceGarbles",
      "value" = false,
      "comment" = "(the sentence tail OCR-lost - flagged, PDF-gated).",
    }, {
      "name" = "uaqR160DmgSystemStaysDefault",
      "value" = true,
      "comment" = "The R160 reconciliation: the DMG pp. 72-73 system (rules/dmg/weaponless.h) stays the engine default;",
    }, {
      "name" = "uaqR160DivergentSystemsRunBoth",
      "value" = true,
      "comment" = "the UA Appendix Q system pins here as its own data layer - the R374 dial precedent, run both.",
    }, {
      "name" = "uaqR160OverlapReconciled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqPumSemiDemonException",
      "value" = true,
      "comment" = "Pummeling: all demons, though not semi-demons.",
    }, {
      "name" = "uaqPumMergedMiddleColumn",
      "value" = true,
      "comment" = "The Pummeling Table row bodies: the print merges small hard with large soft in the middle column.",
    }, {
      "name" = "uaqPumUnexSmallSoftNoEffect",
      "value" = true,
      "comment" = "Unexposed: no effect small soft; 1 percent per point and 20 at 18/01 merged; 2 percent and 40 large hard.",
    }, {
      "name" = "uaqPumAcrobatAttackAdds",
      "value" = true,
      "comment" = "The thief-acrobat tumbling note: the Tumbling Attack percentage adds to the own stun chance, capped at 95; the Tumbling Defense percentage subtracts from the attacker chance while tumbling.",
    }, {
      "name" = "uaqPumAcrobatDefenseSubtracts",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqKickSmallerOverallArmor",
      "value" = true,
      "comment" = "Kicking: a smaller target counts the overall armor, the most vulnerable read.",
    }, {
      "name" = "uaqGrapStr17OneStepBetterAc",
      "value" = true,
      "comment" = "Grappling: the Str-17 example - an effective armor class one step better than usual.",
    }, {
      "name" = "uaqOvbAllBonusesConsidered",
      "value" = true,
      "comment" = "Overbearing: all defensive bonuses count; the effective AC modifies for relative size and for four or more legs.",
    }, {
      "name" = "uaqOvbAcModifiedForRelativeSize",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaqOvbAcAffectedFourPlusLegs",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uaqSysOneSimpleQuickSystem']() != 1  or  m['uaqSysTwoOutgrowthMorePowerful']() != 1  or m['uaqSysOneUserTypeCount']() != 3  or m['uaqSysOneActionCount']() != 3  or m['uaqSysOneHeightPctLimit']() != 125  or m['uaqSysOneExampleShortFt']() != 4  or m['uaqSysOneExampleTallFt']() != 5  or m['uaqSysOneSixFtExampleGarbles']()  or  m['uaqSysOneToHitStrengthOnlyMod']() != 1  or  m['uaqSysOneDefenderArmorDexMagic']() != 1  or m['uaqSysOnePummelDelaySegments']() != 1  or m['uaqSysOnePummelDamageLo']() != 1  or m['uaqSysOnePummelDamageHi']() != 2  or  m['uaqSysOnePummelStrBonusNeedsWeapon']() != 1  or  m['uaqSysOnePummelMultiNoExtraDelay']() != 1  or  m['uaqSysOneGrappleNoDamage']() != 1  or m['uaqSysOneGrappleHoldRounds']() != 1  or m['uaqSysOneGrappledToHitPenalty']() != 2  or m['uaqSysOneGrappledHitByBonus']() != 2  or  m['uaqSysOneGrappleAutoBreaksNextRound']() != 1  or  m['uaqSysOneOverbearKnocksProne']() != 1  or m['uaqSysOneProneHitByBonus']() != 4  or m['uaqSysOneInitPenalty']() != 2  or  m['uaqSysOneSpoiledByPriorDamage']() != 1  or  m['uaqPumAvailWithStrengthScore']() != 1  or m['uaqPumMayRosterCount']() != 4  or m['uaqPumMayNotRosterCount']() != 3  or  m['uaqPumTargetNonUndeadNonVegetable']() != 1  or  m['uaqPumTargetPrimeNative']() != 1  or m['uaqPumCannotRosterCount']() != 5  or m['uaqPumDemonExceptionGarbles']()  or  m['uaqPumSameOrSmallerSizeClass']() != 1  or  m['uaqPumAnySizeIfTargetProne']() != 1  or m['uaqPumInitPenalty']() != 4  or  m['uaqPumDexModsStillApply']() != 1  or  m['uaqPumSurpriseNoInitPenalty']() != 1  or  m['uaqPumBehindNoInitPenalty']() != 1  or m['uaqPumSurpriseOrBehindToHitBonus']() != 2  or  m['uaqPumSpoiledByPriorDamage']() != 1  or m['uaqPumResolutionSteps']() != 4  or m['uaqPumObjTypeCount']() != 4  or m['uaqPumObjSmallSoft']() != 0  or m['uaqPumObjSmallHard']() != 1  or m['uaqPumObjLargeSoft']() != 2  or m['uaqPumObjLargeHard']() != 3  or  m['uaqPumLargeObjPickupRound']() != 1  or  m['uaqPumMoreVulnerableCategoryWins']() != 1  or  m['uaqPumExposedBareHeadOrFace']() != 1  or  m['uaqPumExposedOrdinaryCapClothing']() != 1  or  m['uaqPumExposedLeatherOrPadded']() != 1  or m['uaqPumExposedNaturalAcWorst']() != 7  or  m['uaqPumSemiRingToPlateMail']() != 1  or m['uaqPumSemiNaturalLo']() != 7  or m['uaqPumSemiNaturalHi']() != 2  or  m['uaqPumUnexposedFullOrFieldPlate']() != 1  or m['uaqPumUnexposedNaturalAcBest']() != 2  or  m['uaqPumVulnIgnoresShieldsAndMagicArmor']() != 1  or  m['uaqPumEffAcShieldIgnoredUnlessBuckler']() != 1  or  m['uaqPumEffAcMagicAndDexCount']() != 1  or  m['uaqPumAcaReadsFistOrOpenHand']() != 1  or m['uaqPumTableRows']() != 3  or m['uaqPumTableCols']() != 3  or m['uaqPumExposedSmallSoftPerPt']() != 2  or m['uaqPumExposedSmallSoftCap']() != 40  or m['uaqPumExposedSmallHardPerPt']() != 4  or m['uaqPumExposedSmallHardCap']() != 75  or m['uaqPumExposedLargeHardPerPt']() != 5  or m['uaqPumExposedLargeHardCap']() != 95  or m['uaqPumFragPair1PerPt']() != 1  or m['uaqPumFragPair1Cap']() != 20  or m['uaqPumFragPair2PerPt']() != 2  or m['uaqPumFragPair2Cap']() != 40  or m['uaqPumFragPair3PerPt']() != 4  or m['uaqPumFragPair3Cap']() != 75  or m['uaqPumTableRowBodiesGarble']()  or  m['uaqPumStr1801PlusCountsAs1801']() != 1  or m['uaqPumExStrength']() != 15  or  m['uaqPumExPaddedArmorExposed']() != 1  or m['uaqPumExSmallSoftPct']() != 30  or m['uaqPumExSmallHardPct']() != 60  or m['uaqPumExLargeHardPct']() != 75  or m['uaqPumStunSegmentsLo']() != 1  or m['uaqPumStunSegmentsHi']() != 10  or  m['uaqPumStunNoActions']() != 1  or  m['uaqPumStunSpellsLost']() != 1  or  m['uaqPumStunConcentrationBroken']() != 1  or m['uaqPumRestunUnconsciousLo']() != 1  or m['uaqPumRestunUnconsciousHi']() != 4  or  m['uaqPumStunnedLosesDexAndShield']() != 1  or m['uaqPumStunnedHitByBonus']() != 4  or m['uaqPumSmallSoftDamageLo']() != 1  or m['uaqPumSmallSoftDamageHi']() != 2  or m['uaqPumSmallHardDamageLo']() != 1  or m['uaqPumSmallHardDamageHi']() != 3  or  m['uaqPumDamageWhetherOrNotStun']() != 1  or m['uaqPumLargeDamageCellsGarble']()  or  m['uaqPumMonksNoInitPenalty']() != 1  or  m['uaqPumMonksPummelOrOpenHand']() != 1  or m['uaqPumThievesBehindToHitBonus']() != 4  or m['uaqPumThiefTumblingNoteGarbles']()  or m['uaqPumCavaliersBareHandToHitPenalty']() != 2  or  m['uaqKickBareFeetSmallSoft']() != 1  or  m['uaqKickMetalShodSmallHard']() != 1  or  m['uaqKickSameSizeWaistDownArmorOnly']() != 1  or m['uaqKickSmallerTailGarbles']()  or m['uaqKickJumperClassCount']() != 3  or  m['uaqKickJumperAnyPortionSameSize']() != 1  or  m['uaqKickHigherElevationAnyPortion']() != 1  or m['uaqThrowSmallRangeFeet']() != 30  or m['uaqThrowLargeRangeFeet']() != 10  or m['uaqThrowToHitLongRangeMod']() != -5  or  m['uaqThrowStrengthModApplies']() != 1  or  m['uaqThrowMissScattersGrenadeLike']() != 1  or  m['uaqGrapAvailIntelligentRestraint']() != 1  or  m['uaqGrapNoNonCorporeal']() != 1  or  m['uaqGrapNoAstralEthereal']() != 1  or  m['uaqGrapNoUnintelligentSlimes']() != 1  or  m['uaqGrapBeholderExample']() != 1  or  m['uaqGrapBoundOrcExample']() != 1  or  m['uaqGrapPurposeDelaysOrRestrains']() != 1  or m['uaqGrapPurposeSentenceGarbles']()  or  m['uaqGrapLargerUnlessProne']() != 1  or m['uaqGrapLargerWordGarbles']()  or m['uaqGrapInitPenalty']() != 1  or  m['uaqGrapSpoiledByPriorDamage']() != 1  or m['uaqGrapResolutionSteps']() != 2  or  m['uaqGrapEffAcIgnoresShieldMagicArmor']() != 1  or  m['uaqGrapRingsProtectionBracersCount']() != 1  or  m['uaqGrapMagicalPlateCounts']() != 1  or  m['uaqGrapNoDamage']() != 1  or  m['uaqGrapPreventsFurtherAction']() != 1  or m['uaqGrapVictimToHitPenalty']() != 2  or m['uaqGrapVictimHitByBonus']() != 2  or  m['uaqGrapDexNegatedWhileHeld']() != 1  or m['uaqGrapBreakWayCount']() != 5  or  m['uaqGrapBreakByRelease']() != 1  or  m['uaqGrapBreakByInflictingDamage']() != 1  or m['uaqGrapCounterAttacksAtPenalty']() != 2  or  m['uaqGrapCounterAttackerKeepsMagicDex']() != 1  or  m['uaqGrapCounterStrToHitAsAcBonus']() != 1  or m['uaqGrapStr17ExampleTailGarbles']()  or  m['uaqGrapBreakByCounterGrapple']() != 1  or  m['uaqGrapBreakByBendBars']() != 1  or  m['uaqGrapBreakByAcrobatEvasion']() != 1  or  m['uaqGrapHeldAsLargeSoftObject']() != 1  or  m['uaqGrapNeutralizesOneOfMany']() != 1  or  m['uaqGrapScorpionExample']() != 1  or  m['uaqGrapSameWeaponAllNeutralized']() != 1  or  m['uaqGrapGroupSingleRoll']() != 1  or m['uaqGrapPerExtraMemberBonus']() != 2  or m['uaqGrapDefSMaxSizeS']() != 3  or m['uaqGrapDefSBySizeMHi']() != 2  or m['uaqGrapDefSBySizeL']() != 1  or m['uaqGrapDefMMaxSizeM']() != 3  or m['uaqGrapDefMBandsGarble']()  or m['uaqGrapDefLMaxSizeL']() != 3  or m['uaqGrapProneMaxSizeS']() != 8  or m['uaqGrapProneMaxSizeM']() != 6  or m['uaqGrapProneMaxSizeL']() != 4  or  m['uaqOvbAnyVsAny']() != 1  or  m['uaqOvbNeedsDiscernibleUpright']() != 1  or  m['uaqOvbPurpleWormCubeException']() != 1  or  m['uaqOvbNoInitModification']() != 1  or  m['uaqOvbSpoiledByPriorDamage']() != 1  or m['uaqOvbResolutionSteps']() != 2  or  m['uaqOvbNoInherentDamage']() != 1  or  m['uaqOvbSituationMayDamage']() != 1  or m['uaqOvbProneHitByBonus']() != 4  or m['uaqOvbProneStrikePenalty']() != 2  or  m['uaqOvbProneGrapplePummelAnySize']() != 1  or m['uaqOvbAcProseGarbles']()  or m['uaqOvbAcRows']() != 3  or m['uaqOvbAcCols']() != 3  or m['uaqOvbAcDefSVsS']() != 0  or m['uaqOvbAcDefSVsM']() != 2  or m['uaqOvbAcDefSVsL']() != 4  or m['uaqOvbAcDefMVsS']() != -4  or m['uaqOvbAcDefMVsM']() != 0  or m['uaqOvbAcDefMVsL']() != 2  or m['uaqOvbAcDefLVsS']() != -8  or m['uaqOvbAcDefLVsM']() != -4  or m['uaqOvbAcDefLVsL']() != 0  or m['uaqOvbFootFourLegsAcAdj']() != -6  or m['uaqOvbFootSixLegsAcAdj']() != -8  or m['uaqOvbFootMoreLegsAcAdj']() != -10  or  m['uaqOvbNoLegsCannotBeOverborne']() != 1  or  m['uaqOvbLargeMultiLegRiseAuto']() != 1  or  m['uaqOvbGroupSingleRoll']() != 1  or m['uaqOvbPerExtraFigureBonus']() != 1  or  m['uaqOvbWeakestToHitUsed']() != 1  or m['uaqOvbWeakestSentenceGarbles']()  or m['uaqOvbTargetSMaxSizeS']() != 6  or m['uaqOvbTargetSBySizeM']() != 4  or m['uaqOvbTargetSBySizeL']() != 2  or m['uaqOvbTargetMMaxSizeS']() != 8  or m['uaqOvbTargetMBySizeM']() != 6  or m['uaqOvbTargetMBySizeL']() != 4  or m['uaqOvbTargetLMaxSizeS']() != 12  or m['uaqOvbTargetLBySizeM']() != 8  or m['uaqOvbTargetLBySizeL']() != 6  or  m['uaqR160DmgSystemStaysDefault']() != 1  or  m['uaqR160DivergentSystemsRunBoth']() != 1  or  m['uaqR160OverlapReconciled']() != 1  or m['uaqPartItemTotal']() != 6  or m['uaqPartCleanCount']() != 6  or m['uaqPartFlaggedCount']() != 0  or m['uaqPartGarbledCount']() != 0",
      "note" = "",
    }, {
      "expr" = "m['uaqSysOneExampleShortFt']() *m['uaqSysOneHeightPctLimit']() / 100 !=m['uaqSysOneExampleTallFt']()",
      "note" = "---- the cross-checks ---- the height example: 4 feet at 125 percent reads 5 feet",
    }, {
      "expr" = "m['uaqPumExStrength']() *m['uaqPumExposedSmallSoftPerPt']() !=m['uaqPumExSmallSoftPct']()  or m['uaqPumExStrength']() *m['uaqPumExposedSmallHardPerPt']() !=m['uaqPumExSmallHardPct']()  or m['uaqPumExStrength']() *m['uaqPumExposedLargeHardPerPt']() !=m['uaqPumExLargeHardPct']()",
      "note" = "the Str-15 example multiplies the decoded per-point cells exactly",
    }, {
      "expr" = "m['uaqPumExposedSmallSoftCap']() >=m['uaqPumExposedSmallHardCap']()  or m['uaqPumExposedSmallHardCap']() >=m['uaqPumExposedLargeHardCap']()",
      "note" = "the caps climb 40 < 75 < 95",
    }, {
      "expr" = "m['uaqPumFragPair1PerPt']() * 20 !=m['uaqPumFragPair1Cap']()  or m['uaqPumFragPair2PerPt']() * 20 !=m['uaqPumFragPair2Cap']()",
      "note" = "the fragment pairs tile the 18/01 caps: 20 = 1 x 20, 40 = 2 x 20",
    }, {
      "expr" = "m['uaqPumObjSmallSoft']() + 1 !=m['uaqPumObjSmallHard']()  or m['uaqPumObjSmallHard']() + 1 !=m['uaqPumObjLargeSoft']()  or m['uaqPumObjLargeSoft']() + 1 !=m['uaqPumObjLargeHard']()",
      "note" = "the four object ids are 0-3 contiguous",
    }, {
      "expr" = "m['uaqPartCleanCount']() +m['uaqPartFlaggedCount']() +m['uaqPartGarbledCount']() !=m['uaqPartItemTotal']()",
      "note" = "the ledger sums",
    }, {
      "expr" = "m['uaqOvbAcDefSVsS']() != 0  or m['uaqOvbAcDefMVsM']() != 0  or m['uaqOvbAcDefLVsL']() != 0  or m['uaqOvbAcDefSVsM']() -m['uaqOvbAcDefSVsS']() != 2  or m['uaqOvbAcDefMVsM']() -m['uaqOvbAcDefMVsS']() != 4  or m['uaqOvbAcDefLVsM']() -m['uaqOvbAcDefLVsS']() != 4",
      "note" = "the overbear size-AC diagonal is zero and the rows shift by 4, 2 and 2",
    }, {
      "expr" = "m['uaqOvbFootFourLegsAcAdj']() <=m['uaqOvbFootSixLegsAcAdj']()  or m['uaqOvbFootSixLegsAcAdj']() <=m['uaqOvbFootMoreLegsAcAdj']()",
      "note" = "the footing ladder descends -6 -8 -10",
    }, {
      "expr" = "m['uaqOvbTargetSMaxSizeS']() <=m['uaqOvbTargetSBySizeM']()  or m['uaqOvbTargetSBySizeM']() <=m['uaqOvbTargetSBySizeL']()  or m['uaqOvbTargetMMaxSizeS']() <=m['uaqOvbTargetMBySizeM']()  or m['uaqOvbTargetMBySizeM']() <=m['uaqOvbTargetMBySizeL']()  or m['uaqOvbTargetLMaxSizeS']() <=m['uaqOvbTargetLBySizeM']()  or m['uaqOvbTargetLBySizeM']() <=m['uaqOvbTargetLBySizeL']()  or m['uaqOvbTargetMMaxSizeS']() -m['uaqOvbTargetSMaxSizeS']() != 2  or m['uaqOvbTargetLMaxSizeS']() -m['uaqOvbTargetMMaxSizeS']() != 4",
      "note" = "the overbear count bands descend within each row and climb by row",
    }, {
      "expr" = "m['uaqGrapProneMaxSizeS']() -m['uaqGrapProneMaxSizeM']() != 2  or m['uaqGrapProneMaxSizeM']() -m['uaqGrapProneMaxSizeL']() != 2",
      "note" = "the grapple prone bands descend 8 6 4",
    }, {
      "expr" = "m['uaqPumStunSegmentsLo']() != 1  or m['uaqPumStunSegmentsHi']() != 10  or m['uaqPumRestunUnconsciousLo']() != 1  or m['uaqPumRestunUnconsciousHi']() != 4",
      "note" = "the stun bands",
    }, {
      "expr" = "m['pummelBaseChance'](10) != 100  or m['pummelBaseChance'](9) != 90  or m['pummelBaseChance'](0) != 0",
      "note" = "---- the R160 seam ---- the DMG pp. 72-73 system stays the engine default: its pummel base ladder reads AC x 10",
    } },
  "audit" = {
      "label" = "R389: the UA weaponless combat appendix Q pin audit",
      "comment" = "The pp. 106-108 stretch: six items pin - one fully clean (the throwing rules) plus five mechanics-clean with flagged holes (the System I height example cell, the pummeling table row bodies, the kicking tail, the grappling size bands, the overbearing AC prose); the R160 seam the DMG default, the R388 seam the misc weapons ledger.",
    },
}
