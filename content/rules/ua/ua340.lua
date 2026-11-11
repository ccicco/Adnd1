-- ua340: promoted from rules/ua/uanewweapons.h (the The UA DESCRIPTIONS OF NEW WEAPON TYPES (pp. 26-28) pins (R340).);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 340,
  "prefix" = "ua340",
  "banner" = {
      "title" = "The UA DESCRIPTIONS OF NEW WEAPON TYPES (pp. 26-28) pins (R340).",
      "provenance" = "Pin-era pattern (R322): pinned data only - no engine site exists. The R337 data rows (rules/ua/uaweapontable.h) and the R338 missile rows (rules/ua/uamissile.h) are the data seam; this header pins the PROSE.  JUDGMENTs: - the roster: 16 prose entries in the printed order. The gap item names 14 types; the section also describes the hand-held crossbow and the falchion - both pinned (the item-list flag uanwInGapItemList marks the 14 the item names). - the khopesh \"1'/z feet\" reads as 1 1/2 feet (the slash-loss fraction, the same artifact as the R339 \"112 levels\" cadence); pinned as 15 tenths of a foot. - the whip's \"3d6e minus 2\" reads as 3d6 minus 2 - the accent is an OCR artifact on the plain 3d6 roll (the printed \"dexterity or less\" pins the roll's meaning). - the caltrop \"hits on two\" fragment: the subject cell is OCR-garbled but the \"virtually no movement for eight days\" is readable - the eight days pin, the trigger reads as hits on two feet (noted pending the PDF). - the khopesh trailing leverage sentence (\"disallow (80%) ... leverage ... (10%)\") is scrambled beyond decode - a hole; the readable 10% tear chance pins.  OCR holes (the item stays open - the DM pp. 77-79 half of the item is DMG material absent from the UA extract, and these cells await the PDF read): the harpoon failure damage (prints \"point damage\" - the die lost), the hand-crossbow poison sentence (the \"isons and sleep-inducing\" scramble), the lasso severing mechanics paragraph (the bending-bars chance and the 2 cutting points print scrambled), the caltrop \"hits on two\" trigger, and the khopesh leverage sentence.",
    },
  "consts" = { {
      "name" = "uanwCount",
      "value" = 16,
      "comment" = "The prose entry count (16 printed entries; the 10 PHB-style descriptions plus the hand-held crossbow and falchion prose).",
    }, {
      "name" = "uanwAklysEntangleHitPct",
      "value" = 5,
      "comment" = "---- the aklys ---- 5% of the hits entangle; a subsequent roll of 20 on a hit indicates the entanglement; the thong runs about 10 feet; severing the thong takes 2 cutting points; a round spent disentangling frees the wielder.",
    }, {
      "name" = "uanwAklysThongFeet",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwAklysThongSeverCuttingDmg",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwAklysDisentangleRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwCaltropProngCountLow",
      "value" = 4,
      "comment" = "---- the caltrop ---- Four or six prongs; about one-half foot across; three-inch points at 70 or 90 degrees; aware movement slows by one-half for a round; each square yard crossed checks as a 1+1 HD monster attacking foot armor; a hit has a 25% chance to slow movement 25% for four days; hits on two (feet - the garbled trigger) mean virtually no movement for eight days; prongs under two inches are ignored; no proficiency needed.",
    }, {
      "name" = "uanwCaltropProngCountHigh",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uanwCaltropDiameterInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uanwCaltropPointInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uanwCaltropPointAngleLow",
      "value" = 70,
      "comment" = "",
    }, {
      "name" = "uanwCaltropPointAngleHigh",
      "value" = 90,
      "comment" = "",
    }, {
      "name" = "uanwCaltropAwareMoveFactorPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwCaltropCheckHdDice",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwCaltropCheckHdPlus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwCaltropHitSlowPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwCaltropHitSlowMovePct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwCaltropHitSlowDays",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uanwCaltropTwoHitNoMoveDays",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uanwCaltropMinProngInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwHandXbowPoisonSaveMod",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uanwHandXbowSurfaceCostGp",
      "value" = 300,
      "comment" = "",
    }, {
      "name" = "uanwHandXbowDrowCostGp",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uanwHandXbowDrowQuarrelGp",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwGarrotNeckMaxFeetAboveShoulder",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwGarrotDeflectDmg",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwGarrotVictimAttackMod",
      "value" = -2,
      "comment" = "",
    }, {
      "name" = "uanwGarrotSlayAtEndOfRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwHarpoonSaveMinInt",
      "value" = 2,
      "comment" = "---- the harpoon ---- A target of intelligence 2+ with means of dislodgement saves versus poison to free itself; failure drags the victim 1 inch closer if the harpooner desires (the failure damage prints \"point damage\" - the die lost, a hole).",
    }, {
      "name" = "uanwHarpoonDragInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwHookFauchardDismountPct",
      "value" = 20,
      "comment" = "---- the hook fauchard ---- A hit has a 20% probability of dismounting or toppling the target - the wielder larger, or over 50% of the target's height and weight.",
    }, {
      "name" = "uanwHookFauchardSizeReqPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwLassoDismountPct",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uanwLassoPullOffFeetPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwLassoTargetMaxPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherSizeBandPct",
      "value" = 50,
      "comment" = "---- the man catcher ---- Creatures larger or smaller than human size by 50% or more are unaffected; the caught loses all shield and dexterity bonuses; pushing and pulling inflicts 1-2 per round; 25% pulled off its feet; breakout by bend bars, each attempt 1-4 damage unless gloved; hacking the pole takes 6 cutting points.",
    }, {
      "name" = "uanwManCatcherPushPullDmgMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherPushPullDmgMax",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherPullOffFeetPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherAttemptDmgMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherAttemptDmgMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherPoleCuttingDmg",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uanwSapUnconsciousPctPerStr",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uanwSapNonHeadDamageFactorPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwSpikedBucklerExtraAttacksPerRound",
      "value" = 1,
      "comment" = "---- the spiked buckler ---- The only effective armed shield; one extra attack per round, always after the initial weapon attack; as a second attack mode it strikes at -2.",
    }, {
      "name" = "uanwSpikedBucklerSecondModeMod",
      "value" = -2,
      "comment" = "",
    }, {
      "name" = "uanwStaffSlingPoleMinFeet",
      "value" = 4,
      "comment" = "---- the staff sling ---- A pole of four or more feet; slower and less accurate than a sling, high trajectory - it always operates at medium or long range only; combustibles use the grenade-like missile table.",
    }, {
      "name" = "uanwFalchionMagicBroadswordPct",
      "value" = 25,
      "comment" = "---- the falchion ---- The Dungeon Master should assume 25% of magic broadswords are falchions.",
    }, {
      "name" = "uanwKhopeshHandleInches",
      "value" = 6,
      "comment" = "---- the khopesh ---- About 6 inches of handle and quillons, then about 2 feet straight, then about 2 feet sickle-shaped - extending the overall length by only 1 1/2 feet (the \"1'/z\" print). A snagged opponent not 50% smaller and lighter gets no effective attack for 10 segments; if smaller and lighter: pulled to the ground 25%, impeded 75%. Any hit 5% chance to snag the opponent; any miss 5% to snag the weapon; a snagged weapon is torn from grasp 10%. 10% of magical scimitars are khopeshes - a druidical instrument.",
    }, {
      "name" = "uanwKhopeshStraightBladeFeet",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshSickleBladeFeet",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshEffectiveExtendsTenthsFeet",
      "value" = 15,
      "comment" = "The 1 1/2 feet effective extension (15 tenths).",
    }, {
      "name" = "uanwKhopeshSnagNoAttackSegments",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshSnagSizePct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshSnaggedGroundPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshSnaggedImpededPct",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshOpponentSnagOnHitPct",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshWeaponSnagOnMissPct",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshWeaponTornPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshMagicScimitarPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleNonProfPct",
      "value" = 5,
      "comment" = "---- the whip ---- Any hit entangles at the wielder's option: 5% in non-proficient hands, 5% per level when proficient. The entanglement: one limb 50%, two limbs 10%, weapon arm and weapon 20%, the head 20% (40% against an opponent not using a weapon). One limb: no effective attack 10 segments; two limbs: the same, 25% kneeling or prone; weapon arm: no attack 10 segments, 10% weapon lost (an edged weapon severs the whip 50% instead); the neck: garrot-type damage without throat protection. A proficient wielder disentangles on dexterity or less on 3d6 minus 2; the victim pulls it loose at 5% plus 1% per point of its strength.",
    }, {
      "name" = "uanwWhipEntangleProfPctPerLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleOneLimbPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleTwoLimbsPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleWeaponArmPct",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleHeadPct",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uanwWhipEntangleHeadNoWeaponPct",
      "value" = 40,
      "comment" = "",
    }, {
      "name" = "uanwWhipNoAttackSegments",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwWhipTwoLimbPronePct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uanwWhipWeaponLostPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uanwWhipEdgedSeveredPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uanwWhipDisentangle3d6Minus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uanwWhipVictimPullPct",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uanwWhipVictimPullPctPerStr",
      "value" = 1,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uanwAklysEntangleRollOf20",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwAtlatlJavelinDamageSame",
      "value" = true,
      "comment" = "---- the atlatl ---- The shorter, lighter javelins inflict the same damage because of their velocity.",
    }, {
      "name" = "uanwBlowgunBattlefieldImpossible",
      "value" = true,
      "comment" = "---- the blowgun ---- Fragile and long - impossible on the normal battlefield; the needles carry an insinuative poison.",
    }, {
      "name" = "uanwBlowgunPoisonNeedles",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwCaltropNoProficiencyNeeded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwHandXbowOneHandFire",
      "value" = true,
      "comment" = "---- the hand-held crossbow ---- One hand to fire, two to load; a dart tipped with the substance forces a save versus poison at -4 or fall unconscious; 300 gp on the surface, 30 gp from the dark elves, their quarrels about a factor of 10 down - 10 gp.",
    }, {
      "name" = "uanwGarrotStrikeFromBehind",
      "value" = true,
      "comment" = "---- the garrot ---- Strike from behind; the victim's neck no more than 1 foot above the wielder's shoulder height; a raised limb foils encirclement - damage reduces to 1 point; a successful hit slays at the end of the next round; the victim attacks at -2; a successful bend bars roll spoils the attack.",
    }, {
      "name" = "uanwGarrotBendBarsBreaks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwHarpoonSaveVsPoison",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwLassoDamageless",
      "value" = true,
      "comment" = "---- the lasso ---- No damage in game terms; the hit mirrors the harpoon's; 75% dismount, 25% pulled off its feet if bipedal and no more than +50% of the wielder's height and mass (the severing mechanics print scrambled - a hole).",
    }, {
      "name" = "uanwManCatcherLosesShieldAndDex",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwManCatcherBreakoutBendBars",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwSapHeadUncoveredRequired",
      "value" = true,
      "comment" = "---- the sap ---- Unconsciousness only if the head is uncovered (light cloth counts); 5% per point of strength - 18/01 strength suffices; a non-head hit inflicts half damage only.",
    }, {
      "name" = "uanwStaffSlingMediumOrLongOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwStaffSlingUsesGrenadeTable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uanwKhopeshDruidicalIdeal",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uanwName",
      "comment" = "The entry name (printed).",
      "kind" = "string array",
      "count" = 16,
      "values" = { "Aklys", "Atlatl", "Blowgun", "Caltrop", "Crossbow, Hand-held", "Garrot", "Harpoon", "Hook Fauchard", "Lasso", "Man Catcher", "Sap", "Spiked Buckler", "Staff Sling", "Sword, Falchion", "Sword, Khopesh", "Whip" },
    }, {
      "name" = "uanwInGapItemList",
      "comment" = "True when the entry is among the 14 types the gap item names (the hand-held crossbow and the falchion are extra prose).",
      "kind" = "header pin",
      "body" = "static const bool k[16] = { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }; if (i < 0) i = 0; if (i > 15) i = 15; return k[i];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uanwCount']() != 16  or strcmp(m['uanwName'](0), \"Aklys\") != 0  or strcmp(m['uanwName'](4), \"Crossbow, Hand-held\") != 0  or strcmp(m['uanwName'](9), \"Man Catcher\") != 0  or strcmp(m['uanwName'](13), \"Sword, Falchion\") != 0  or strcmp(m['uanwName'](15), \"Whip\") != 0  or m['uanwInGapItemList'](4)  or m['uanwInGapItemList'](13)  or m['uanwInGapItemList'](i)) ++listed; if (listed != 14",
      "note" = "U1: the counts and the roster",
    }, {
      "expr" = "m['uanwAklysEntangleHitPct']() != 5  or  m['uanwAklysEntangleRollOf20']() != 1  or m['uanwAklysThongFeet']() != 10  or m['uanwAklysThongSeverCuttingDmg']() != 2  or m['uanwAklysDisentangleRounds']() != 1  or  m['uanwAtlatlJavelinDamageSame']() != 1  or  m['uanwBlowgunBattlefieldImpossible']() != 1  or  m['uanwBlowgunPoisonNeedles']() != 1",
      "note" = "U2: the aklys, the atlatl, the blowgun",
    }, {
      "expr" = "m['uanwCaltropProngCountLow']() != 4  or m['uanwCaltropProngCountHigh']() != 6  or m['uanwCaltropDiameterInches']() != 6  or m['uanwCaltropPointInches']() != 3  or m['uanwCaltropPointAngleLow']() != 70  or m['uanwCaltropPointAngleHigh']() != 90  or m['uanwCaltropAwareMoveFactorPct']() != 50  or m['uanwCaltropCheckHdDice']() != 1  or m['uanwCaltropCheckHdPlus']() != 1  or m['uanwCaltropHitSlowPct']() != 25  or m['uanwCaltropHitSlowMovePct']() != 25  or m['uanwCaltropHitSlowDays']() != 4  or m['uanwCaltropTwoHitNoMoveDays']() != 8  or m['uanwCaltropMinProngInches']() != 2  or  m['uanwCaltropNoProficiencyNeeded']() != 1",
      "note" = "U3: the caltrop",
    }, {
      "expr" = "m['uanwHandXbowOneHandFire']() != 1  or m['uanwHandXbowPoisonSaveMod']() != -4  or m['uanwHandXbowSurfaceCostGp']() != 300  or m['uanwHandXbowDrowCostGp']() != 30  or m['uanwHandXbowDrowQuarrelGp']() != 10  or  m['uanwGarrotStrikeFromBehind']() != 1  or m['uanwGarrotNeckMaxFeetAboveShoulder']() != 1  or m['uanwGarrotDeflectDmg']() != 1  or m['uanwGarrotVictimAttackMod']() != -2  or m['uanwGarrotSlayAtEndOfRounds']() != 1  or  m['uanwGarrotBendBarsBreaks']() != 1",
      "note" = "U4: the hand-held crossbow, the garrot",
    }, {
      "expr" = "m['uanwHarpoonSaveMinInt']() != 2  or  m['uanwHarpoonSaveVsPoison']() != 1  or m['uanwHarpoonDragInches']() != 1  or m['uanwHookFauchardDismountPct']() != 20  or m['uanwHookFauchardSizeReqPct']() != 50  or  m['uanwLassoDamageless']() != 1  or m['uanwLassoDismountPct']() != 75  or m['uanwLassoPullOffFeetPct']() != 25  or m['uanwLassoTargetMaxPct']() != 50",
      "note" = "U5: the harpoon, the hook fauchard, the lasso",
    }, {
      "expr" = "m['uanwManCatcherSizeBandPct']() != 50  or  m['uanwManCatcherLosesShieldAndDex']() != 1  or m['uanwManCatcherPushPullDmgMin']() != 1  or m['uanwManCatcherPushPullDmgMax']() != 2  or m['uanwManCatcherPullOffFeetPct']() != 25  or  m['uanwManCatcherBreakoutBendBars']() != 1  or m['uanwManCatcherAttemptDmgMin']() != 1  or m['uanwManCatcherAttemptDmgMax']() != 4  or m['uanwManCatcherPoleCuttingDmg']() != 6  or  m['uanwSapHeadUncoveredRequired']() != 1  or m['uanwSapUnconsciousPctPerStr']() != 5  or m['uanwSapNonHeadDamageFactorPct']() != 50  or m['uanwSpikedBucklerExtraAttacksPerRound']() != 1  or m['uanwSpikedBucklerSecondModeMod']() != -2  or m['uanwStaffSlingPoleMinFeet']() != 4  or  m['uanwStaffSlingMediumOrLongOnly']() != 1  or  m['uanwStaffSlingUsesGrenadeTable']() != 1",
      "note" = "U6: the man catcher, the sap, the spiked buckler, the staff sling",
    }, {
      "expr" = "m['uanwFalchionMagicBroadswordPct']() != 25  or m['uanwKhopeshHandleInches']() != 6  or m['uanwKhopeshStraightBladeFeet']() != 2  or m['uanwKhopeshSickleBladeFeet']() != 2  or m['uanwKhopeshEffectiveExtendsTenthsFeet']() != 15  or m['uanwKhopeshSnagNoAttackSegments']() != 10  or m['uanwKhopeshSnagSizePct']() != 50  or m['uanwKhopeshSnaggedGroundPct']() +m['uanwKhopeshSnaggedImpededPct']() != 100  or m['uanwKhopeshSnaggedGroundPct']() != 25  or m['uanwKhopeshOpponentSnagOnHitPct']() != 5  or m['uanwKhopeshWeaponSnagOnMissPct']() != 5  or m['uanwKhopeshWeaponTornPct']() != 10  or m['uanwKhopeshMagicScimitarPct']() != 10  or  m['uanwKhopeshDruidicalIdeal']() != 1",
      "note" = "U7: the falchion, the khopesh",
    }, {
      "expr" = "m['uanwWhipEntangleNonProfPct']() != 5  or m['uanwWhipEntangleProfPctPerLevel']() != 5  or m['uanwWhipEntangleOneLimbPct']() +m['uanwWhipEntangleTwoLimbsPct']() +m['uanwWhipEntangleWeaponArmPct']() +m['uanwWhipEntangleHeadPct']() != 100  or m['uanwWhipEntangleOneLimbPct']() != 50  or m['uanwWhipEntangleTwoLimbsPct']() != 10  or m['uanwWhipEntangleWeaponArmPct']() != 20  or m['uanwWhipEntangleHeadPct']() != 20  or m['uanwWhipEntangleHeadNoWeaponPct']() != 40  or m['uanwWhipNoAttackSegments']() != 10  or m['uanwWhipTwoLimbPronePct']() != 25  or m['uanwWhipWeaponLostPct']() != 10  or m['uanwWhipEdgedSeveredPct']() != 50  or m['uanwWhipDisentangle3d6Minus']() != 2  or m['uanwWhipVictimPullPct']() != 5  or m['uanwWhipVictimPullPctPerStr']() != 1",
      "note" = "U8: the whip",
    } },
  "audit" = {
      "label" = "R340: the UA new weapons prose pin audit",
      "comment" = "The UA DESCRIPTIONS OF NEW WEAPON TYPES (pp. 26-28) - the 16 printed entries (the 14 types the gap item names plus the hand-held crossbow and falchion prose), every readable number pinned; the garbled cells (the harpoon failure die, the hand-crossbow poison sentence, the lasso severing mechanics, the caltrop trigger, the khopesh leverage sentence) are documented holes; the DM pp. 77-79 half is DMG material absent from the UA extract - the item stays open.",
    },
}
