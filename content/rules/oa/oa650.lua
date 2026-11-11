-- oa650: promoted from rules/oa/oaweaponspec.h (the WEAPON PROFICIENCIES AND SPECIALIZATION, printed capture pp. 99-101 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 650,
  "prefix" = "oa650",
  "banner" = {
      "title" = "WEAPON PROFICIENCIES AND SPECIALIZATION, printed capture pp. 99-101 - the",
      "provenance" = "OA proficiencies arc opener census 572 -> 573.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the section - the chapter opener intro on capture p. 99 and the weapon proficiencies and specialization prose on pp. 100-101 of the print pass, cross-checked paragraph-by-paragraph between the two passes (compressed pp. 52-53); every printed number agrees. One OCR artifact class: the compressed pass systematically renders the specialization bonuses with minus signs - the +1/+2 melee, the +3 double, the +2/+2 and +1 bow reads all print as negatives - and each such read contradicts its own sentence (an increase to a bonus, a doubled base damage), so the print + signs stand per the R643 pattern; likewise the print pocked read of the arrow-ready doctrine is a letter slip, settled as nocked. The Chapter 6 parent box opens this round with the proficiency slot system pinned: all characters receive slots at 1st level, some or all fillable with weapon training and the rest with other skills, unfilled slots saveable, and a selected proficiency never changed for any reason. The specialization doctrine pins as consts and bools: a weapon proficiency costs one slot; only samurai and bushi specialize; the bushi any-one-weapon at-creation rule and the samurai katana-and-bow two-weapon rule (the katana at creation, the bow delayable); melee or crossbow specialization costs two slots, other missile weapons three; unarmed combat cannot be a weapon proficiency except under a master; the specific-type-not-general-class rule; the melee specialist +1 to hit and +2 damage, the iaijutsu fast-draw benefit, the next-higher-rank multiple-attack rule with the 3/2 first-level and 2/1 fifth-level samurai examples, and double specialization at one more slot for +3 to hit and damage. The bow specialist gains the point blank band (5 to 30 feet, +2 to hit and damage, the base damage doubled with strength and magic added to the final total), +1 at short range, no special bonus at medium and longer, no damage bonuses beyond point blank, and the ready-arrow auto-fire before initiative; the crossbow specialist the same point blank benefits within 5 to 60 feet, +1 to hit and damage at short range, +1 to hit at medium, and the same ready benefit; other missile specialists +1 to hit and +2 damage, with the higher-level extra attacks listed on Table 57 (its own box) and the per-class numbers on Table 56 (likewise). The p. 101 restrictions pin: class-disallowed weapons usable at the non-proficiency penalty (worst for split class) but never kept and carried; the under-5-feet 12-foot weapon-length bound; the under-4-feet daikyu ban; and the under-100-pounds heavy crossbow, over-200-gp and two-handed-sword bans - prohibitions that override the penalty since the weapons cannot be wielded at all  the gap census after this round: 102 closed, 133 open - the Chapter 6 parent box opens and the weapon proficiencies and specialization prose box flips (census 572 -> 573); NEXT - R651: Table 57 (Missile Weapon Specializations), capture p. 100, the specialist attacks-per-round grid, prefix dhl (verify free), audit \"R651 OA missile specializations audit\", include after rules/oa/oaweaponspec.h",
    },
  "consts" = { {
      "name" = "dhkSlotsAtFirstLevel",
      "value" = 1,
      "comment" = "all characters receive their number of proficiency slots at 1st level (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkWeaponProfSlotCost",
      "value" = 1,
      "comment" = "each weapon proficiency costs one proficiency slot from those the character has available (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecMeleeSlots",
      "value" = 2,
      "comment" = "weapon specialization in any melee weapon or crossbow counts as two proficiency slots (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecMissileSlots",
      "value" = 3,
      "comment" = "specialization in any other missile weapon counts as three proficiency slots (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkMeleeSpecHit",
      "value" = 1,
      "comment" = "the melee specialist is +1 on to hit rolls with the specialized weapon (capture p. 100 of the print pass; compressed p. 52, where the minus read is the plus-as-minus OCR artifact)",
    }, {
      "name" = "dhkMeleeSpecDmg",
      "value" = 2,
      "comment" = "the melee specialist is +2 on damage rolls with the specialized weapon (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecFirstAttNum",
      "value" = 3,
      "comment" = "a first-level samurai makes 3/2 attacks per round with his specialized weapon - the numerator of the printed example (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecFirstAttDen",
      "value" = 2,
      "comment" = "the 3/2 denominator of the first-level attack example (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecFifthAttNum",
      "value" = 2,
      "comment" = "at fifth level the same character makes 2 attacks per round with his specialized weapon - the numerator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecFifthAttDen",
      "value" = 1,
      "comment" = "the 2/1 denominator of the fifth-level attack example (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkDoubleSpecSlotCost",
      "value" = 1,
      "comment" = "an additional proficiency slot spent to double specialize once the character advances beyond 1st level (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkDoubleSpecHit",
      "value" = 3,
      "comment" = "double specialization increases the bonus to +3 on to hit (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkDoubleSpecDmg",
      "value" = 3,
      "comment" = "double specialization increases the bonus to +3 on damage (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowPointBlankMin",
      "value" = 5,
      "comment" = "the bow specialist's point blank range begins at 5 feet (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowPointBlankMax",
      "value" = 30,
      "comment" = "the point blank range extends to 30 feet (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowPointBlankHit",
      "value" = 2,
      "comment" = "the bow specialist is +2 to hit at any target within point blank (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowPointBlankDmg",
      "value" = 2,
      "comment" = "the bow specialist is +2 damage at any target within point blank (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowShortHit",
      "value" = 1,
      "comment" = "at short range the bow specialist is +1 on his to hit rolls (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkXbowPointBlankMin",
      "value" = 5,
      "comment" = "the crossbow specialist's point blank range begins at 5 feet (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkXbowPointBlankMax",
      "value" = 60,
      "comment" = "the crossbow point blank range extends to 60 feet (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkXbowShortHit",
      "value" = 1,
      "comment" = "at short range the crossbow specialist is +1 on to hit rolls (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkXbowShortDmg",
      "value" = 1,
      "comment" = "at short range the crossbow specialist is +1 on damage rolls (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkXbowMediumHit",
      "value" = 1,
      "comment" = "at medium range the crossbow specialist is +1 on his chances to hit (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkOtherMissileHit",
      "value" = 1,
      "comment" = "specializing in other missile weapons gains +1 on to hit rolls (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkOtherMissileDmg",
      "value" = 2,
      "comment" = "specializing in other missile weapons gains +2 on damage (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkHeightLimitFeet",
      "value" = 5,
      "comment" = "characters under 5 feet in height cannot effectively use any weapon over 12 feet in length - the height bound (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhkWeaponLenLimitFeet",
      "value" = 12,
      "comment" = "the weapon-length bound of the under-5-feet rule (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhkDaikyuHeightFeet",
      "value" = 4,
      "comment" = "characters under 4 feet in height cannot use the daikyu, the great bow (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhkBodyWeightPounds",
      "value" = 100,
      "comment" = "characters of less than 100 pounds body weight cannot use a heavy crossbow, any weapon weighing more than 200 gp, or a two-handed sword - the weight bound (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhkHeavyWeaponGp",
      "value" = 200,
      "comment" = "the weapon-weight bound of the under-100-pounds rule, in gold-piece weight (capture p. 101 of the print pass; compressed p. 53)",
    } },
  "bools" = { {
      "name" = "dhkPeacefulAsImportant",
      "value" = true,
      "comment" = "the artistic and peaceful skills are as important to a character as his ability to fight - the society emphasizes creative talents almost as much as combat prowess (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSlotsWeaponOrPeaceful",
      "value" = true,
      "comment" = "depending on the character's class, some or all slots can be filled with weapon training, and any not devoted to weapons can be filled with other skills (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSlotsSaveable",
      "value" = true,
      "comment" = "the character is not required to fill all his proficiency slots - those not filled can be saved and used at a later time (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkNoChangeAfterSelection",
      "value" = true,
      "comment" = "once a proficiency has been selected it cannot be changed for any reason (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkUnarmedNeedsMaster",
      "value" = true,
      "comment" = "unarmed combat cannot be taken as a weapon proficiency unless the character is studying under a master (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkOnlySamuraiBushiSpec",
      "value" = true,
      "comment" = "only samurai and bushi can choose to use weapon specialization (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBushiOneWeapon",
      "value" = true,
      "comment" = "the bushi can choose any one weapon to specialize in, the selection made as soon as the character is created, except for samurai (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSamuraiKatanaBow",
      "value" = true,
      "comment" = "only the samurai can specialize in two weapons at once - the katana and the bow; he must specialize in the katana as soon as created but can delay the bow for a later time (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecSpecificType",
      "value" = true,
      "comment" = "melee specialization must be a specific weapon type, not a general class of weapons - the katana yes, all swords no (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecGivesIaijutsu",
      "value" = true,
      "comment" = "the specialist has learned the art of iaijutsu, the fast draw, with the specialized weapon and receives the benefits explained under that proficiency (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkSpecNextAttackRank",
      "value" = true,
      "comment" = "the specialist can make extra multiple attacks beyond those given on the Multiple Attacks Table, utilizing the next higher rank when fighting with his specialized weapon (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowPointBlankDmgDoubled",
      "value" = true,
      "comment" = "the base damage done at point blank is automatically doubled; bonuses to damage for strength and magic are not doubled - they are added to the final total (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowNoBonusBeyond",
      "value" = true,
      "comment" = "at medium range and longer the bow specialist has no special bonus to hit, and at all ranges beyond point blank there are no bonuses to damage (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkBowReadyFiresFirst",
      "value" = true,
      "comment" = "a bow specialist who begins the round with his arrow ready - nocked, drawn and aimed on a target - can automatically fire before any initiative check is made (capture p. 100 of the print pass; compressed p. 52; the print pocked read is a letter slip, settled as nocked)",
    }, {
      "name" = "dhkXbowPointBlankSame",
      "value" = true,
      "comment" = "within point blank the crossbow specialist receives the same benefits as a bow specialist, including the weapon-ready benefit at the start of the round; the multiple attacks depend on the type of crossbow (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhkClassNonprofApplies",
      "value" = true,
      "comment" = "weapons not permitted to a class may be picked up and used, but the non-proficiency penalty for that class always applies - the worst penalty for split class characters - and such disallowed weapons cannot be kept and carried by the character for use later (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhkProhibitionsOverride",
      "value" = true,
      "comment" = "the height and weight prohibitions override the non-proficiency stipulation - the penalty is immaterial, since these weapons cannot be wielded at all (capture p. 101 of the print pass; compressed p. 53)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhkSlotsAtFirstLevel']() != 1  or m['dhkWeaponProfSlotCost']() != 1  or m['dhkSpecMeleeSlots']() != 2  or m['dhkSpecMissileSlots']() != 3  or m['dhkMeleeSpecHit']() != 1  or m['dhkMeleeSpecDmg']() != 2  or m['dhkDoubleSpecSlotCost']() != 1  or m['dhkDoubleSpecHit']() != 3  or m['dhkDoubleSpecDmg']() != 3  or m['dhkBowPointBlankMin']() != 5  or m['dhkBowPointBlankMax']() != 30  or m['dhkBowPointBlankHit']() != 2  or m['dhkBowPointBlankDmg']() != 2  or m['dhkBowShortHit']() != 1  or m['dhkXbowPointBlankMin']() != 5  or m['dhkXbowPointBlankMax']() != 60  or m['dhkXbowShortHit']() != 1  or m['dhkXbowShortDmg']() != 1  or m['dhkXbowMediumHit']() != 1  or m['dhkOtherMissileHit']() != 1  or m['dhkOtherMissileDmg']() != 2  or m['dhkSpecFirstAttNum']() != 3  or m['dhkSpecFirstAttDen']() != 2  or m['dhkSpecFifthAttNum']() != 2  or m['dhkSpecFifthAttDen']() != 1  or m['dhkHeightLimitFeet']() != 5  or m['dhkWeaponLenLimitFeet']() != 12  or m['dhkDaikyuHeightFeet']() != 4  or m['dhkBodyWeightPounds']() != 100  or m['dhkHeavyWeaponGp']() != 200  or  m['dhkPeacefulAsImportant']() != 1  or  m['dhkSlotsWeaponOrPeaceful']() != 1  or  m['dhkSlotsSaveable']() != 1  or  m['dhkNoChangeAfterSelection']() != 1  or  m['dhkUnarmedNeedsMaster']() != 1  or  m['dhkOnlySamuraiBushiSpec']() != 1  or  m['dhkBushiOneWeapon']() != 1  or  m['dhkSamuraiKatanaBow']() != 1  or  m['dhkSpecSpecificType']() != 1  or  m['dhkSpecGivesIaijutsu']() != 1  or  m['dhkSpecNextAttackRank']() != 1  or  m['dhkBowPointBlankDmgDoubled']() != 1  or  m['dhkBowNoBonusBeyond']() != 1  or  m['dhkBowReadyFiresFirst']() != 1  or  m['dhkXbowPointBlankSame']() != 1  or  m['dhkClassNonprofApplies']() != 1  or  m['dhkProhibitionsOverride']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhkSlotsAtFirstLevel']() != 1  or m['dhkWeaponProfSlotCost']() != 1",
      "note" = "the slot-system pins - the 1st-level slots and the one-slot weapon proficiency cost",
    }, {
      "expr" = "m['dhkPeacefulAsImportant']() != 1  or m['dhkSlotsWeaponOrPeaceful']() != 1  or m['dhkSlotsSaveable']() != 1  or m['dhkNoChangeAfterSelection']() != 1",
      "note" = "the slot-rule pins - the fill, the saving and the no-change doctrine",
    }, {
      "expr" = "m['dhkSpecMeleeSlots']() != 2  or m['dhkSpecMissileSlots']() != 3",
      "note" = "the specialization slot-cost pins - two for melee or crossbow, three for other missiles",
    }, {
      "expr" = "m['dhkOnlySamuraiBushiSpec']() != 1  or m['dhkUnarmedNeedsMaster']() != 1  or m['dhkBushiOneWeapon']() != 1  or m['dhkSamuraiKatanaBow']() != 1  or m['dhkSpecSpecificType']() != 1",
      "note" = "the eligibility pins - samurai and bushi only, the unarmed master rule, the bushi one-weapon rule, the katana-and-bow rule, the specific-type rule",
    }, {
      "expr" = "m['dhkMeleeSpecHit']() != 1  or m['dhkMeleeSpecDmg']() != 2",
      "note" = "the melee specialist bonus pins - +1 to hit, +2 damage",
    }, {
      "expr" = "m['dhkSpecFirstAttNum']() != 3  or m['dhkSpecFirstAttDen']() != 2  or m['dhkSpecFifthAttNum']() != 2  or m['dhkSpecFifthAttDen']() != 1",
      "note" = "the attack-example pins - 3/2 at first level, 2/1 at fifth level",
    }, {
      "expr" = "m['dhkSpecGivesIaijutsu']() != 1  or m['dhkSpecNextAttackRank']() != 1",
      "note" = "the iaijutsu and next-attack-rank pins",
    }, {
      "expr" = "m['dhkDoubleSpecSlotCost']() != 1  or m['dhkDoubleSpecHit']() != 3  or m['dhkDoubleSpecDmg']() != 3",
      "note" = "the double-specialization pins - one slot more, +3 to hit and damage",
    }, {
      "expr" = "m['dhkBowPointBlankMin']() != 5  or m['dhkBowPointBlankMax']() != 30  or m['dhkBowPointBlankHit']() != 2  or m['dhkBowPointBlankDmg']() != 2",
      "note" = "the bow point-blank band pins - 5 to 30 feet, +2 to hit and damage",
    }, {
      "expr" = "m['dhkBowShortHit']() != 1  or m['dhkBowPointBlankDmgDoubled']() != 1  or m['dhkBowNoBonusBeyond']() != 1  or m['dhkBowReadyFiresFirst']() != 1",
      "note" = "the bow doctrine pins - +1 at short range, the doubled base damage, no bonus beyond, the ready auto-fire",
    }, {
      "expr" = "m['dhkXbowPointBlankMin']() != 5  or m['dhkXbowPointBlankMax']() != 60  or m['dhkXbowShortHit']() != 1  or m['dhkXbowShortDmg']() != 1  or m['dhkXbowMediumHit']() != 1  or m['dhkXbowPointBlankSame']() != 1",
      "note" = "the crossbow pins - 5 to 60 feet point blank, +1/+1 short, +1 medium, the same benefits",
    }, {
      "expr" = "m['dhkOtherMissileHit']() != 1  or m['dhkOtherMissileDmg']() != 2",
      "note" = "the other-missile specialist pins - +1 to hit, +2 damage",
    }, {
      "expr" = "m['dhkClassNonprofApplies']() != 1  or m['dhkProhibitionsOverride']() != 1",
      "note" = "the weapon-restriction pins - the class penalty applies and the prohibitions override",
    }, {
      "expr" = "m['dhkHeightLimitFeet']() != 5  or m['dhkWeaponLenLimitFeet']() != 12  or m['dhkDaikyuHeightFeet']() != 4  or m['dhkBodyWeightPounds']() != 100  or m['dhkHeavyWeaponGp']() != 200",
      "note" = "the bound pins - 5 feet against 12 feet, the 4-foot daikyu ban, 100 pounds against 200 gp",
    } },
  "audit" = {
      "label" = "R650 OA proficiencies audit",
      "comment" = "OA round thirty-seven (capture pp. 99-101): the Chapter 6 opener - the proficiency slot system and the weapon specialization doctrine with the weapon restrictions",
    },
}
