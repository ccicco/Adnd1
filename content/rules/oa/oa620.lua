-- oa620: promoted from rules/oakensai.h (the THE KENSAI, printed capture pp. 28-31 - the OA sword saint round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 620,
  "prefix" = "oa620",
  "banner" = {
      "title" = "THE KENSAI, printed capture pp. 28-31 - the OA sword saint round",
      "provenance" = "census 542 -> 543.  verified against capture pp. 28-31 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). The Table 19 special-abilities column pins as a coded ladder (meditation, the 1-in-6 surprise, two weapons and fear, the pupils, the whirlwind). OCR normalization: practice daisy reads as practice daily (prose only). This push ALSO carries the still-unlanded R618 v3 amendment (spec_r618 08fa91d7 -> 9ea88b9e, oaraces.h 3786b6c2 -> 615b853c) - the R619 fold silently failed because the rn flow stages only the current round files; this time the two prior-round files must be added explicitly.  the gap census after this round: 36 closed, 199 open - the kensai boxes with Tables 18 and 19 flip (census 542 -> 543); NEXT - R621: the Monk - the discipline ladder, the quirks, Tables 20 and 21, prefix dgh (verify free), audit \"R621 OA monk audit\", include after rules/oakensai.h",
    },
  "consts" = { {
      "name" = "dggKensaiMinStr",
      "value" = 12,
      "comment" = "Kensai prose (capture p. 29): the Strength minimum",
    }, {
      "name" = "dggKensaiMinWis",
      "value" = 12,
      "comment" = "Kensai prose (capture p. 29): the Wisdom minimum",
    }, {
      "name" = "dggKensaiMinDex",
      "value" = 14,
      "comment" = "Kensai prose (capture p. 29): the Dexterity minimum",
    }, {
      "name" = "dggKensaiHitDie",
      "value" = 10,
      "comment" = "Kensai prose (capture p. 29): the 10-sided hit die, one per level",
    }, {
      "name" = "dggKensaiSlots",
      "value" = 3,
      "comment" = "Kensai prose (capture p. 29): three initial proficiency slots - the free chosen-weapon proficiency costs none; only one slot may buy a second weapon; the rest must be peaceful skills",
    }, {
      "name" = "dggKensaiNaturalAcBase",
      "value" = 23,
      "comment" = "Kensai prose (capture p. 29): the natural AC formula - 23 minus Dexterity (the printed Dex 16 to AC 7 example)",
    }, {
      "name" = "dggKensaiAcStepLevels",
      "value" = 3,
      "comment" = "Kensai prose (capture p. 29): the natural AC improves one step per three levels",
    }, {
      "name" = "dggKensaiInitBase",
      "value" = 1,
      "comment" = "Kensai prose (capture p. 29): +1 on all initiative rolls, melee and missile, self only in a group",
    }, {
      "name" = "dggKensaiSaveBonus",
      "value" = 1,
      "comment" = "Kensai prose (capture p. 29): +1 on all saving throws",
    }, {
      "name" = "dggKensaiDuelBonusVsOthers",
      "value" = 2,
      "comment" = "Kensai prose (capture p. 29): the psychic-duel bonus vs. non-kensai; vs. another kensai only the levels count",
    }, {
      "name" = "dggKensaiDmgLevels",
      "value" = 5,
      "comment" = "Kensai prose (capture p. 30): the damage bonus steps - +1 at 2nd, again at 5th, 8th, 10th and 12th, total +5",
    }, {
      "name" = "dggKensaiHitLevels",
      "value" = 5,
      "comment" = "Kensai prose (capture p. 30): the to-hit bonus steps - +1 at 3rd, again at 5th, 8th, 10th and 12th, total +5 and the equivalence of a magical +5 weapon",
    }, {
      "name" = "dggKensaiInitTwo",
      "value" = 2,
      "comment" = "Kensai prose (capture p. 30): the initiative bonus rises to +2 at 5th (the printed total modifier)",
    }, {
      "name" = "dggKensaiInitThree",
      "value" = 3,
      "comment" = "Kensai prose (capture p. 30): the initiative bonus rises to +3 at 9th",
    }, {
      "name" = "dggKensaiMeditateLevel",
      "value" = 4,
      "comment" = "Kensai prose (capture p. 30): at 4th level meditates like a shukenja",
    }, {
      "name" = "dggKensaiSurpriseLevel",
      "value" = 6,
      "comment" = "Kensai prose (capture p. 30): at 6th level surprised only on a 1 on 1d6",
    }, {
      "name" = "dggKensaiTwoWeaponsLevel",
      "value" = 7,
      "comment" = "Kensai prose (capture p. 30): at 7th level two weapons simultaneously with no penalty, and causes fear as a samurai",
    }, {
      "name" = "dggKensaiPupilDie",
      "value" = 6,
      "comment" = "Kensai prose (capture p. 30): at 9th level attracts 1d6 pupils, all 1st-level kensai specializing in the master weapon",
    }, {
      "name" = "dggKensaiPupilDepartPct",
      "value" = 5,
      "comment" = "Kensai prose (capture p. 30): a 5 percent chance per level that a pupil ends studies and leaves",
    }, {
      "name" = "dggKensaiPupilLossPct",
      "value" = 50,
      "comment" = "Kensai prose (capture p. 30): a 50 percent chance per pupil of leaving when the master loses a duel to a lower-level kensai",
    }, {
      "name" = "dggKensaiWhirlwindLevel",
      "value" = 11,
      "comment" = "Kensai prose (capture p. 30): the whirlwind attack at 11th level",
    }, {
      "name" = "dggKensaiWhirlwindRange",
      "value" = 10,
      "comment" = "Kensai prose (capture p. 30): the whirlwind attacks all opponents within 10 feet once in the same round",
    }, {
      "name" = "dggKensaiDuelXpMultiplier",
      "value" = 2,
      "comment" = "Kensai prose (capture p. 31): double experience for defeating another kensai in a duel; a duel with a particular opponent once per level",
    }, {
      "name" = "dggKensaiPracticeHours",
      "value" = 2,
      "comment" = "Kensai prose (capture p. 31): at least two hours of daily practice; every skipped two-hour session must be made up before advancing (four hours per day when catching up - the printed Kiyomori example)",
    }, {
      "name" = "dggT18RowCount",
      "value" = 12,
      "comment" = "Table 18 (capture pp. 28-29): twelve rows, levels 1-12",
    }, {
      "name" = "dggT18XpBeyond",
      "value" = 250000,
      "comment" = "Table 18 note (capture p. 29): 250,000 experience points per level beyond 12th",
    }, {
      "name" = "dggT18HpBeyond",
      "value" = 2,
      "comment" = "Table 18 note (capture p. 29): 2 hit points per level beyond 9th",
    }, {
      "name" = "dggT19RowCount",
      "value" = 12,
      "comment" = "Table 19 (capture p. 30): twelve rows, levels 1 through 12+",
    }, {
      "name" = "dggT19SpecNone",
      "value" = 0,
      "comment" = "Table 19 special code (capture p. 30): none",
    }, {
      "name" = "dggT19SpecMeditate",
      "value" = 1,
      "comment" = "Table 19 special code (capture p. 30): meditation at 4th",
    }, {
      "name" = "dggT19SpecSurprise",
      "value" = 2,
      "comment" = "Table 19 special code (capture p. 30): the 1-in-6 surprise at 6th",
    }, {
      "name" = "dggT19SpecTwoWeapons",
      "value" = 3,
      "comment" = "Table 19 special code (capture p. 30): two weapons and fear at 7th",
    }, {
      "name" = "dggT19SpecPupils",
      "value" = 4,
      "comment" = "Table 19 special code (capture p. 30): the 1-6 pupils at 9th",
    }, {
      "name" = "dggT19SpecWhirlwind",
      "value" = 5,
      "comment" = "Table 19 special code (capture p. 30): the whirlwind attack at 11th",
    } },
  "bools" = { {
      "name" = "dggKensaiDualPrime",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): Wisdom and Dexterity are the prime requisites - both 14 or higher earns the 10 percent experience bonus",
    }, {
      "name" = "dggKensaiLawfulOnly",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): must be lawful - good, evil or neutral; humans, hengeyokai and spirit folk only",
    }, {
      "name" = "dggKensaiFighterTables",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): the fighter combat and saving throw tables; any weapon, no armor",
    }, {
      "name" = "dggKensaiNinjaHonorUnless",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): ninja preferred weapons lose honor - unless it is the chosen weapon",
    }, {
      "name" = "dggKensaiNoDexAdjustments",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): no Reaction/Attack or Defensive Adjustments from Dexterity - the natural AC replaces them",
    }, {
      "name" = "dggKensaiKiMaxDamage",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): the ki power - maximum damage on one attack with the specialty weapon, announced before the to-hit roll, times per day equal to level",
    }, {
      "name" = "dggKensaiImmuneFear",
      "value" = true,
      "comment" = "Kensai prose (capture p. 29): all kensai are immune to fear",
    }, {
      "name" = "dggKensaiPupilGain",
      "value" = true,
      "comment" = "Kensai prose (capture p. 30): defeating a higher-level kensai in a duel gains 1-2 additional pupils",
    }, {
      "name" = "dggKensaiWhirlwindCostsAllKi",
      "value" = true,
      "comment" = "Kensai prose (capture p. 30): the whirlwind requires the entire day ki (none used before), specialty weapon only, initiative applies, no max-damage guarantee, all other bonuses apply",
    }, {
      "name" = "dggKensaiNoMagicSpecialty",
      "value" = true,
      "comment" = "Kensai prose (capture p. 30): never a magical weapon of the specialty type - no true measure of skill; all armor prohibited",
    }, {
      "name" = "dggKensaiHalfXpOtherWeapon",
      "value" = true,
      "comment" = "Kensai prose (capture p. 30): one-half experience for opponents defeated with a non-specialty weapon - even in part, unless fighting with specialty and another weapon at once",
    }, {
      "name" = "dggKensaiDuelChallenge",
      "value" = true,
      "comment" = "Kensai prose (capture p. 31): on each level gain a 10-times-new-level percent chance of a duel challenge from a same-level kensai",
    }, {
      "name" = "dggKensaiDuelRefuseCost",
      "value" = true,
      "comment" = "Kensai prose (capture p. 31): refusing or losing the duel forfeits the new level (bottom of the old) and loses honor; the 10th level must be dueled for; NPC duels cost honor only, never a level",
    }, {
      "name" = "dggKensaiDuelConditions",
      "value" = true,
      "comment" = "Kensai prose (capture p. 31): the duel need not be to the death - surrender, first blood, first strike or first draw; no magical weapons or armor; no aid or support",
    }, {
      "name" = "dggKensaiHonorDemotion",
      "value" = true,
      "comment" = "Kensai prose (capture p. 31): honor below the family honor means demotion to bushi of the same level - abilities kept, no new kensai abilities, bushi advancement",
    }, {
      "name" = "dggKensaiBirthRequired",
      "value" = true,
      "comment" = "Kensai prose (capture p. 31): not high birth by requirement but must roll Table 38 - treated socially by birth until the reputation forms",
    } },
  "switches" = { {
      "name" = "dggT18XpMax",
      "values" = { 3000, 5500, 10000, 22000, 44000, 88000, 150000, 250000, 500000, 750000, 1000000, 1250000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 3,000 at 1st to 1,250,000 at 12th (capture pp. 28-29).",
    }, {
      "name" = "dggT18Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d10 dice column: one per level through 9th, then held at 9 (capture pp. 28-29).",
    }, {
      "name" = "dggT18HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 2 per level beyond 9th: 0 through 9th, then 2, 4, 6 (capture pp. 28-29).",
    }, {
      "name" = "dggT19Init",
      "values" = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3 },
      "default" = -99,
      "comment" = "the initiative bonus column: +1 at 1st, +2 from 5th, +3 from 9th (capture p. 30).",
    }, {
      "name" = "dggT19Ac",
      "values" = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4 },
      "default" = -99,
      "comment" = "the AC bonus column: +1 at 3rd stepping to +4 at 10th (capture p. 30).",
    }, {
      "name" = "dggT19Dmg",
      "values" = { 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5 },
      "default" = -99,
      "comment" = "the damage bonus column: +1 at 2nd stepping to +5 at 12+ (capture p. 30).",
    }, {
      "name" = "dggT19Hit",
      "values" = { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5 },
      "default" = -99,
      "comment" = "the to-hit bonus column: +1 at 3rd stepping to +5 at 12+ (capture p. 30).",
    }, {
      "name" = "dggT19Special",
      "values" = { 0, 0, 0, 1, 0, 2, 3, 0, 4, 0, 5, 0 },
      "default" = -99,
      "comment" = "the special code column: none 0, meditation 1 at 4th, the 1-in-6 surprise 2 at 6th, two weapons and fear 3 at 7th, the 1-6 pupils 4 at 9th, the whirlwind 5 at 11th (capture p. 30).",
    } },
  "tables" = { {
      "name" = "dggT18Grid",
      "tag" = "T18",
      "count" = "dggT18RowCount",
      "sentinel" = -99,
      "cols" = { "dggT18XpMax", "dggT18Dice", "dggT18HpBonus" },
      "data" = { { 3000, 1, 0 }, { 5500, 2, 0 }, { 10000, 3, 0 }, { 22000, 4, 0 }, { 44000, 5, 0 }, { 88000, 6, 0 }, { 150000, 7, 0 }, { 250000, 8, 0 }, { 500000, 9, 0 }, { 750000, 9, 2 }, { 1000000, 9, 4 }, { 1250000, 9, 6 } },
      "comment" = "the Table 18 kensai advancement grid (capture pp. 28-29)",
      "col_comments" = { "the experience column: the upper xp bound of each level, 3,000 at 1st to 1,250,000 at 12th (capture pp. 28-29).", "the accumulated d10 dice column: one per level through 9th, then held at 9 (capture pp. 28-29).", "the hit-point bonus column: the printed 9-plus-N cells - 2 per level beyond 9th: 0 through 9th, then 2, 4, 6 (capture pp. 28-29)." },
      "audit_comment" = "the Table 18 grid: the level xp bounds and the accumulated dice plus bonus (capture pp. 28-29)",
    }, {
      "name" = "dggT19Grid",
      "tag" = "T19",
      "count" = "dggT19RowCount",
      "sentinel" = -99,
      "cols" = { "dggT19Init", "dggT19Ac", "dggT19Dmg", "dggT19Hit", "dggT19Special" },
      "data" = { { 1, 0, 0, 0, 0 }, { 1, 0, 1, 0, 0 }, { 1, 1, 1, 1, 0 }, { 1, 1, 1, 1, 1 }, { 2, 1, 2, 2, 0 }, { 2, 2, 2, 2, 2 }, { 2, 2, 2, 2, 3 }, { 2, 3, 3, 3, 0 }, { 3, 3, 3, 3, 4 }, { 3, 4, 4, 4, 0 }, { 3, 4, 4, 4, 5 }, { 3, 4, 5, 5, 0 } },
      "comment" = "the Table 19 kensai bonuses grid (capture p. 30)",
      "col_comments" = { "the initiative bonus column: +1 at 1st, +2 from 5th, +3 from 9th (capture p. 30).", "the AC bonus column: +1 at 3rd stepping to +4 at 10th (capture p. 30).", "the damage bonus column: +1 at 2nd stepping to +5 at 12+ (capture p. 30).", "the to-hit bonus column: +1 at 3rd stepping to +5 at 12+ (capture p. 30).", "the special code column: none 0, meditation 1 at 4th, the 1-in-6 surprise 2 at 6th, two weapons and fear 3 at 7th, the 1-6 pupils 4 at 9th, the whirlwind 5 at 11th (capture p. 30)." },
      "audit_comment" = "the Table 19 grid: the initiative, AC, damage and to-hit ladders with the special power codes across levels 1-12+ (capture p. 30)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dggKensaiMinStr']() != 12  or m['dggKensaiMinWis']() != 12  or m['dggKensaiMinDex']() != 14  or m['dggKensaiHitDie']() != 10  or m['dggKensaiSlots']() != 3  or m['dggKensaiNaturalAcBase']() != 23  or m['dggKensaiAcStepLevels']() != 3  or m['dggKensaiInitBase']() != 1  or m['dggKensaiSaveBonus']() != 1  or m['dggKensaiDuelBonusVsOthers']() != 2  or m['dggKensaiDmgLevels']() != 5  or m['dggKensaiHitLevels']() != 5  or m['dggKensaiInitTwo']() != 2  or m['dggKensaiInitThree']() != 3  or m['dggKensaiMeditateLevel']() != 4  or m['dggKensaiSurpriseLevel']() != 6  or m['dggKensaiTwoWeaponsLevel']() != 7  or m['dggKensaiPupilDie']() != 6  or m['dggKensaiPupilDepartPct']() != 5  or m['dggKensaiPupilLossPct']() != 50  or m['dggKensaiWhirlwindLevel']() != 11  or m['dggKensaiWhirlwindRange']() != 10  or m['dggKensaiDuelXpMultiplier']() != 2  or m['dggKensaiPracticeHours']() != 2  or m['dggT18RowCount']() != 12  or m['dggT18XpBeyond']() != 250000  or m['dggT18HpBeyond']() != 2  or m['dggT19RowCount']() != 12  or m['dggT19SpecNone']() != 0  or m['dggT19SpecMeditate']() != 1  or m['dggT19SpecSurprise']() != 2  or m['dggT19SpecTwoWeapons']() != 3  or m['dggT19SpecPupils']() != 4  or m['dggT19SpecWhirlwind']() != 5  or  m['dggKensaiDualPrime']() != 1  or  m['dggKensaiLawfulOnly']() != 1  or  m['dggKensaiFighterTables']() != 1  or  m['dggKensaiNinjaHonorUnless']() != 1  or  m['dggKensaiNoDexAdjustments']() != 1  or  m['dggKensaiKiMaxDamage']() != 1  or  m['dggKensaiImmuneFear']() != 1  or  m['dggKensaiPupilGain']() != 1  or  m['dggKensaiWhirlwindCostsAllKi']() != 1  or  m['dggKensaiNoMagicSpecialty']() != 1  or  m['dggKensaiHalfXpOtherWeapon']() != 1  or  m['dggKensaiDuelChallenge']() != 1  or  m['dggKensaiDuelRefuseCost']() != 1  or  m['dggKensaiDuelConditions']() != 1  or  m['dggKensaiHonorDemotion']() != 1  or  m['dggKensaiBirthRequired']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dggKensaiDualPrime']() != 1",
      "note" = "the dggKensaiDualPrime pin",
    }, {
      "expr" = "m['dggKensaiMinStr']() != 12",
      "note" = "the dggKensaiMinStr pin",
    }, {
      "expr" = "m['dggKensaiMinWis']() != 12",
      "note" = "the dggKensaiMinWis pin",
    }, {
      "expr" = "m['dggKensaiMinDex']() != 14",
      "note" = "the dggKensaiMinDex pin",
    }, {
      "expr" = "m['dggKensaiLawfulOnly']() != 1",
      "note" = "the dggKensaiLawfulOnly pin",
    }, {
      "expr" = "m['dggKensaiHitDie']() != 10",
      "note" = "the dggKensaiHitDie pin",
    }, {
      "expr" = "m['dggKensaiFighterTables']() != 1",
      "note" = "the dggKensaiFighterTables pin",
    }, {
      "expr" = "m['dggKensaiNinjaHonorUnless']() != 1",
      "note" = "the dggKensaiNinjaHonorUnless pin",
    }, {
      "expr" = "m['dggKensaiSlots']() != 3",
      "note" = "the dggKensaiSlots pin",
    }, {
      "expr" = "m['dggKensaiNoDexAdjustments']() != 1",
      "note" = "the dggKensaiNoDexAdjustments pin",
    }, {
      "expr" = "m['dggKensaiNaturalAcBase']() != 23",
      "note" = "the dggKensaiNaturalAcBase pin",
    }, {
      "expr" = "m['dggKensaiAcStepLevels']() != 3",
      "note" = "the dggKensaiAcStepLevels pin",
    }, {
      "expr" = "m['dggKensaiInitBase']() != 1",
      "note" = "the dggKensaiInitBase pin",
    }, {
      "expr" = "m['dggKensaiSaveBonus']() != 1",
      "note" = "the dggKensaiSaveBonus pin",
    }, {
      "expr" = "m['dggKensaiKiMaxDamage']() != 1",
      "note" = "the dggKensaiKiMaxDamage pin",
    }, {
      "expr" = "m['dggKensaiDuelBonusVsOthers']() != 2",
      "note" = "the dggKensaiDuelBonusVsOthers pin",
    }, {
      "expr" = "m['dggKensaiImmuneFear']() != 1",
      "note" = "the dggKensaiImmuneFear pin",
    }, {
      "expr" = "m['dggKensaiDmgLevels']() != 5",
      "note" = "the dggKensaiDmgLevels pin",
    }, {
      "expr" = "m['dggKensaiHitLevels']() != 5",
      "note" = "the dggKensaiHitLevels pin",
    }, {
      "expr" = "m['dggKensaiInitTwo']() != 2",
      "note" = "the dggKensaiInitTwo pin",
    }, {
      "expr" = "m['dggKensaiInitThree']() != 3",
      "note" = "the dggKensaiInitThree pin",
    }, {
      "expr" = "m['dggKensaiMeditateLevel']() != 4",
      "note" = "the dggKensaiMeditateLevel pin",
    }, {
      "expr" = "m['dggKensaiSurpriseLevel']() != 6",
      "note" = "the dggKensaiSurpriseLevel pin",
    }, {
      "expr" = "m['dggKensaiTwoWeaponsLevel']() != 7",
      "note" = "the dggKensaiTwoWeaponsLevel pin",
    }, {
      "expr" = "m['dggKensaiPupilDie']() != 6",
      "note" = "the dggKensaiPupilDie pin",
    }, {
      "expr" = "m['dggKensaiPupilDepartPct']() != 5",
      "note" = "the dggKensaiPupilDepartPct pin",
    }, {
      "expr" = "m['dggKensaiPupilLossPct']() != 50",
      "note" = "the dggKensaiPupilLossPct pin",
    }, {
      "expr" = "m['dggKensaiPupilGain']() != 1",
      "note" = "the dggKensaiPupilGain pin",
    }, {
      "expr" = "m['dggKensaiWhirlwindLevel']() != 11",
      "note" = "the dggKensaiWhirlwindLevel pin",
    }, {
      "expr" = "m['dggKensaiWhirlwindRange']() != 10",
      "note" = "the dggKensaiWhirlwindRange pin",
    }, {
      "expr" = "m['dggKensaiWhirlwindCostsAllKi']() != 1",
      "note" = "the dggKensaiWhirlwindCostsAllKi pin",
    }, {
      "expr" = "m['dggKensaiNoMagicSpecialty']() != 1",
      "note" = "the dggKensaiNoMagicSpecialty pin",
    }, {
      "expr" = "m['dggKensaiHalfXpOtherWeapon']() != 1",
      "note" = "the dggKensaiHalfXpOtherWeapon pin",
    }, {
      "expr" = "m['dggKensaiDuelXpMultiplier']() != 2",
      "note" = "the dggKensaiDuelXpMultiplier pin",
    }, {
      "expr" = "m['dggKensaiPracticeHours']() != 2",
      "note" = "the dggKensaiPracticeHours pin",
    }, {
      "expr" = "m['dggKensaiDuelChallenge']() != 1",
      "note" = "the dggKensaiDuelChallenge pin",
    }, {
      "expr" = "m['dggKensaiDuelRefuseCost']() != 1",
      "note" = "the dggKensaiDuelRefuseCost pin",
    }, {
      "expr" = "m['dggKensaiDuelConditions']() != 1",
      "note" = "the dggKensaiDuelConditions pin",
    }, {
      "expr" = "m['dggKensaiHonorDemotion']() != 1",
      "note" = "the dggKensaiHonorDemotion pin",
    }, {
      "expr" = "m['dggKensaiBirthRequired']() != 1",
      "note" = "the dggKensaiBirthRequired pin",
    }, {
      "expr" = "m['dggT18RowCount']() != 12",
      "note" = "the dggT18RowCount pin",
    }, {
      "expr" = "m['dggT18XpBeyond']() != 250000",
      "note" = "the dggT18XpBeyond pin",
    }, {
      "expr" = "m['dggT18HpBeyond']() != 2",
      "note" = "the dggT18HpBeyond pin",
    }, {
      "expr" = "m['dggT19RowCount']() != 12",
      "note" = "the dggT19RowCount pin",
    }, {
      "expr" = "m['dggT19SpecNone']() != 0",
      "note" = "the dggT19SpecNone pin",
    }, {
      "expr" = "m['dggT19SpecMeditate']() != 1",
      "note" = "the dggT19SpecMeditate pin",
    }, {
      "expr" = "m['dggT19SpecSurprise']() != 2",
      "note" = "the dggT19SpecSurprise pin",
    }, {
      "expr" = "m['dggT19SpecTwoWeapons']() != 3",
      "note" = "the dggT19SpecTwoWeapons pin",
    }, {
      "expr" = "m['dggT19SpecPupils']() != 4",
      "note" = "the dggT19SpecPupils pin",
    }, {
      "expr" = "m['dggT19SpecWhirlwind']() != 5",
      "note" = "the dggT19SpecWhirlwind pin",
    }, {
      "expr" = "m['dggKensaiNaturalAcBase']() - 16 != 7",
      "note" = "the natural AC formula - Dex 16 gives AC 7 (capture p. 29)",
    }, {
      "expr" = "m['dggT19Init'](11) != 3  or m['dggT19Ac'](11) != 4  or m['dggT19Dmg'](11) != 5  or m['dggT19Hit'](11) != 5",
      "note" = "the T19 capstones - initiative +3, AC +4, damage and hit +5 (capture p. 30)",
    }, {
      "expr" = "m['dggT18Dice'](9) != 9  or m['dggT18HpBonus'](9) != 2",
      "note" = "the T18 level-10 row - nine dice plus the 2 bonus (capture p. 29)",
    }, {
      "expr" = "m['dggT19Special'](10) != 5",
      "note" = "the whirlwind special sits at level 11 (capture p. 30)",
    }, {
      "expr" = "m['dggT18HpBeyond']() != 2",
      "note" = "the kensai and bushi beyond-9th hp steps agree (capture pp. 27, 29)",
    }, {
      "expr" = "m['dggKensaiDuelXpMultiplier']() != 2",
      "note" = "the duel multiplier doubles (capture p. 31)",
    }, {
      "expr" = "m['dggT18XpMax'](0) != 3000 or m['dggT18XpMax'](1) != 5500 or m['dggT18XpMax'](2) != 10000 or m['dggT18XpMax'](3) != 22000 or m['dggT18XpMax'](4) != 44000 or m['dggT18XpMax'](5) != 88000 or m['dggT18XpMax'](6) != 150000 or m['dggT18XpMax'](7) != 250000",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dggT18XpMax'](8) != 500000 or m['dggT18XpMax'](9) != 750000 or m['dggT18XpMax'](10) != 1000000 or m['dggT18XpMax'](11) != 1250000 or m['dggT18XpMax'](12) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R620 OA kensai audit",
      "comment" = "OA round seven (capture pp. 28-31): the kensai - the dual prime requisites, the natural AC formula and step, the initiative and ki powers, the damage and to-hit ladders, the pupil and whirlwind powers, the restrictions and practice, and the duel doctrine with the honor demotion.",
    },
}
