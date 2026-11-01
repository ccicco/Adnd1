-- oa623: promoted from rules/oasamurai.h (the THE SAMURAI, printed capture pp. 39-42 - the OA samurai round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 623,
  "prefix" = "oa623",
  "banner" = {
      "title" = "THE SAMURAI, printed capture pp. 39-42 - the OA samurai round",
      "provenance" = "census 545 -> 546.  verified against capture pp. 39-42 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). The Table 25 hit-points header is settled against the 2018 print (10-sided dice for accum. hit points) - the dice column pins as accumulated d10 with the printed 9-plus-N cells. The Table 25 grid itself sits as an extracted image in the first capture; the cells pin from the page-40 continuation with the 2018 print confirming every cell. OCR normalization: 2d level reads as 2nd level; a fitting homes reads as a fitting home; Stunned character cannot reads as the stunned cannot (prose only)  the gap census after this round: 45 closed, 190 open - the samurai boxes with Table 25 flip (census 545 -> 546); NEXT - R624: the Shukenja, capture pp. 42-45, Tables 26, 27 and 28, prefix dgk (verify free), audit \"R624 OA shukenja audit\", include after rules/oasamurai.h",
    },
  "consts" = { {
      "name" = "dgjSamuraiMinStr",
      "value" = 13,
      "comment" = "Samurai prose (capture p. 40): the Strength minimum",
    }, {
      "name" = "dgjSamuraiMinWis",
      "value" = 13,
      "comment" = "Samurai prose (capture p. 40): the Wisdom minimum",
    }, {
      "name" = "dgjSamuraiMinCon",
      "value" = 13,
      "comment" = "Samurai prose (capture p. 40): the Constitution minimum",
    }, {
      "name" = "dgjSamuraiMinInt",
      "value" = 14,
      "comment" = "Samurai prose (capture p. 40): the Intelligence minimum",
    }, {
      "name" = "dgjSamuraiHitDie",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 40): the 10-sided hit die, one per level",
    }, {
      "name" = "dgjSamuraiSlots",
      "value" = 5,
      "comment" = "Samurai prose (capture p. 40): five proficiency slots at 1st level",
    }, {
      "name" = "dgjSamuraiBirthBonus",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 40): the +10 bonus on the Table 38 Character Birth roll for the highest caste",
    }, {
      "name" = "dgjSamuraiHorseLevel",
      "value" = 2,
      "comment" = "Samurai prose (capture p. 40): horsemanship proficiency required at 2nd level",
    }, {
      "name" = "dgjSamuraiBowLevel",
      "value" = 3,
      "comment" = "Samurai prose (capture p. 40): bow proficiency required by 3rd level",
    }, {
      "name" = "dgjSamuraiArtsLevel",
      "value" = 6,
      "comment" = "Samurai prose (capture p. 40): calligraphy, painting and poetry proficiencies required by 6th level",
    }, {
      "name" = "dgjSamuraiArtsCount",
      "value" = 3,
      "comment" = "Samurai prose (capture p. 40): the three arts proficiencies",
    }, {
      "name" = "dgjSamuraiKiLevel",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the ki focus at 1st level",
    }, {
      "name" = "dgjSamuraiKiRounds",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the ki effect lasts one round",
    }, {
      "name" = "dgjSamuraiKiPerDayMult",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the ki usable a number of times per day equal to level - the printed 7th-level example",
    }, {
      "name" = "dgjSamuraiDmgBaseLevel",
      "value" = 2,
      "comment" = "Samurai prose (capture p. 41): the +1 damage bonus starting at 2nd level",
    }, {
      "name" = "dgjSamuraiDmgBase",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the base damage bonus",
    }, {
      "name" = "dgjSamuraiDmgStepLevels",
      "value" = 3,
      "comment" = "Samurai prose (capture p. 41): the bonus increases one point per three levels beyond 2nd - +2 at 5th, +3 at 8th",
    }, {
      "name" = "dgjSamuraiSurpriseLevel",
      "value" = 3,
      "comment" = "Samurai prose (capture p. 41): surprised only on a 1 on 1d6 from 3rd level",
    }, {
      "name" = "dgjSamuraiSurpriseRoll",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the surprise roll value",
    }, {
      "name" = "dgjSamuraiFearImmuneLevel",
      "value" = 5,
      "comment" = "Samurai prose (capture p. 41): immune to all types of fear from 5th level",
    }, {
      "name" = "dgjSamuraiAppFearLevel",
      "value" = 6,
      "comment" = "Samurai prose (capture p. 41): the appearance fear at 6th level",
    }, {
      "name" = "dgjSamuraiAppFearHdMax",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the appearance fear affects creatures of 1 Hit Die or less",
    }, {
      "name" = "dgjSamuraiJitoLevel",
      "value" = 7,
      "comment" = "Samurai prose (capture p. 41): the jito stewardship offer at 7th level",
    }, {
      "name" = "dgjSamuraiJitoTaxShareDiv",
      "value" = 4,
      "comment" = "Samurai prose (capture p. 41): the jito receives one-quarter of the taxes he collects",
    }, {
      "name" = "dgjSamuraiJitoBushi",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 41): the daimyo provides the new jito with 10 bushi",
    }, {
      "name" = "dgjSamuraiJitoSamuraiMin",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): one to four samurai provided with the jito grant",
    }, {
      "name" = "dgjSamuraiJitoSamuraiMax",
      "value" = 4,
      "comment" = "Samurai prose (capture p. 41): the samurai upper bound of the jito grant",
    }, {
      "name" = "dgjSamuraiJitoFollowerLevelMin",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the jito followers are all of 1st to 3rd level",
    }, {
      "name" = "dgjSamuraiJitoFollowerLevelMax",
      "value" = 3,
      "comment" = "Samurai prose (capture p. 41): the follower level upper bound",
    }, {
      "name" = "dgjSamuraiShugoLevel",
      "value" = 8,
      "comment" = "Samurai prose (capture p. 41): the shugo position offered at 8th level",
    }, {
      "name" = "dgjSamuraiShugoBushiDice",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 41): the shugo attracts 10d10 bushi followers",
    }, {
      "name" = "dgjSamuraiShugoNinjaPct",
      "value" = 20,
      "comment" = "Samurai prose (capture p. 41): the 20 percent chance that one of the bushi is an infiltrator ninja",
    }, {
      "name" = "dgjSamuraiSamuraiLevel",
      "value" = 9,
      "comment" = "Samurai prose (capture p. 41): the 2d10 samurai attracted at 9th level",
    }, {
      "name" = "dgjSamuraiSamuraiDice",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 41): the 2d10 samurai follower die",
    }, {
      "name" = "dgjSamuraiSpecialistMin",
      "value" = 2,
      "comment" = "Samurai prose (capture p. 41): 2-7 specialists request service at 9th level",
    }, {
      "name" = "dgjSamuraiSpecialistMax",
      "value" = 7,
      "comment" = "Samurai prose (capture p. 41): the specialist upper bound",
    }, {
      "name" = "dgjSamuraiSpecialistNinjaPct",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 41): the 10 percent chance one specialist is a ninja spy",
    }, {
      "name" = "dgjSamuraiGreatKiaiLevel",
      "value" = 9,
      "comment" = "Samurai prose (capture p. 41): the great kiai at 9th level",
    }, {
      "name" = "dgjSamuraiGreatKiaiRounds",
      "value" = 2,
      "comment" = "Samurai prose (capture p. 41): the great kiai raises Strength to 18/00 for two rounds",
    }, {
      "name" = "dgjSamuraiGreatKiaiRadius",
      "value" = 10,
      "comment" = "Samurai prose (capture p. 41): all enemies within 10 feet must save vs paralyzation",
    }, {
      "name" = "dgjSamuraiGreatKiaiStunRounds",
      "value" = 1,
      "comment" = "Samurai prose (capture p. 41): the failed save means stunned for one round",
    }, {
      "name" = "dgjSamuraiRoninXpMult",
      "value" = 2,
      "comment" = "Samurai prose (capture p. 42): the ronin advances at double the normal experience point cost",
    }, {
      "name" = "dgjT25RowCount",
      "value" = 12,
      "comment" = "Table 25 (capture pp. 39-40): twelve rows, levels 1-12",
    }, {
      "name" = "dgjT25XpBeyond",
      "value" = 300000,
      "comment" = "Table 25 note (capture p. 40): 300,000 experience points are required for each level beyond 12th",
    }, {
      "name" = "dgjT25HpBeyond",
      "value" = 2,
      "comment" = "Table 25 note (capture p. 40): samurai gain 2 hp per level beyond 10th",
    } },
  "bools" = { {
      "name" = "dgjSamuraiLawfulOnly",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): must be of lawful alignment - good, evil or neutral",
    }, {
      "name" = "dgjSamuraiFighterTables",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): fights and makes saving throws as a fighter",
    }, {
      "name" = "dgjSamuraiNoPrimeBonus",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): no prime requisite - no experience point bonuses for high scores",
    }, {
      "name" = "dgjSamuraiKatanaRequired",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): every samurai must specialize with the katana",
    }, {
      "name" = "dgjSamuraiTwoWeaponOnly",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): only samurai may specialize in two weapons at once - katana and daikyu",
    }, {
      "name" = "dgjSamuraiAnyArmorNoShield",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): any armor but never a shield",
    }, {
      "name" = "dgjSamuraiNinjaWeaponsHonorLoss",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): gaining proficiency with and using ninja-favored weapons costs honor",
    }, {
      "name" = "dgjSamuraiHighestCaste",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): human or spirit folk samurai belong to the highest caste, commonly of noble birth",
    }, {
      "name" = "dgjSamuraiKorobokuruSponsor",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): korobokuru need a daimyo sponsor and skip Table 38, automatically beginning at Upper Class",
    }, {
      "name" = "dgjSamuraiKorobokuruBushi",
      "value" = true,
      "comment" = "Samurai prose (capture p. 40): until the sponsor is found the korobokuru samurai is treated as a bushi, unable to advance beyond 1st level",
    }, {
      "name" = "dgjSamuraiKiStrength1800",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the ki focus with the kiai shout raises Strength to 18/00",
    }, {
      "name" = "dgjSamuraiAppFearControllable",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the appearance fear is turned on and off at will; a passed save means immunity for the encounter",
    }, {
      "name" = "dgjSamuraiAppFearSaveAllowed",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the appearance fear allows a saving throw vs breath weapon",
    }, {
      "name" = "dgjSamuraiJitoOptional",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the jito stewardship is not required - refusal earns a fitting home in the city or bakufu",
    }, {
      "name" = "dgjSamuraiJitoDaimyoLoyal",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the jito followers are ultimately loyal to the daimyo but faithfully serve the character unless the daimyo intervenes",
    }, {
      "name" = "dgjSamuraiJitoRetained",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the jito position is retained from that point on, even after establishing his own family",
    }, {
      "name" = "dgjSamuraiJitoDaimyoProperty",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the property remains the daimyo - only he may dispose of it; a jito usurpation is not unknown",
    }, {
      "name" = "dgjSamuraiOneNinjaPerHousehold",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): no more than one ninja will ever operate in any household",
    }, {
      "name" = "dgjSamuraiShugoLoyalWhilePaid",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the shugo bushi stay loyal while adequately paid, housed, fed and the master does not look too bleak",
    }, {
      "name" = "dgjSamuraiFollowersAbsoluteLoyal",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the 9th-level samurai followers are absolutely loyal, as befits his station",
    }, {
      "name" = "dgjSamuraiGreatKiaiOnceDaily",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the great kiai only once per day",
    }, {
      "name" = "dgjSamuraiGreatKiaiExcludesKi",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the normal ki power and the great kiai cannot be used on the same day",
    }, {
      "name" = "dgjSamuraiGreatKiaiStunEffects",
      "value" = true,
      "comment" = "Samurai prose (capture p. 41): the stunned gain no Armor Class bonuses for Dexterity or shields and cannot move or attack",
    }, {
      "name" = "dgjSamuraiBushidoPrecepts",
      "value" = true,
      "comment" = "Samurai prose (capture p. 42): the bushido precepts - obedience, the death protest, no failure, the greatest service, vengeance, the shared dishonor, no mercy, the repaid debts, the cowardice",
    }, {
      "name" = "dgjSamuraiRoninDemotion",
      "value" = true,
      "comment" = "Samurai prose (capture p. 42): honor below the set values loses the samurai status - the ronin is a samurai without a master",
    }, {
      "name" = "dgjSamuraiRoninRetainsAbilities",
      "value" = true,
      "comment" = "Samurai prose (capture p. 42): the ronin retains the samurai abilities except property and attracting fighting men",
    }, {
      "name" = "dgjSamuraiRoninReturnable",
      "value" = true,
      "comment" = "Samurai prose (capture p. 42): a ronin returns to full status provided his honor is above the required level and the daimyo accepts him",
    } },
  "switches" = { {
      "name" = "dgjT25XpMax",
      "values" = { 2500, 5000, 10000, 18000, 36500, 75000, 135000, 235000, 400000, 650000, 1000000, 1300000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 2,500 at 1st to 1,300,000 at 12th (capture pp. 39-40).",
    }, {
      "name" = "dgjT25Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d10 dice column: one per level through 9th, then held at 9 (capture pp. 39-40).",
    }, {
      "name" = "dgjT25HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 2 hp per level beyond 10th: 0 through 9th, then 2, 4, 6 (capture pp. 39-40).",
    }, {
      "name" = "dgjT25Dmg",
      "values" = { 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4 },
      "default" = -99,
      "comment" = "the damage bonus column: 0 at 1st, +1 from 2nd, +2 from 5th, +3 from 8th, +4 from 11th (capture pp. 39-40).",
    } },
  "tables" = { {
      "name" = "dgjT25Grid",
      "tag" = "T25",
      "count" = "dgjT25RowCount",
      "sentinel" = -99,
      "cols" = { "dgjT25XpMax", "dgjT25Dice", "dgjT25HpBonus", "dgjT25Dmg" },
      "data" = { { 2500, 1, 0, 0 }, { 5000, 2, 0, 1 }, { 10000, 3, 0, 1 }, { 18000, 4, 0, 1 }, { 36500, 5, 0, 2 }, { 75000, 6, 0, 2 }, { 135000, 7, 0, 2 }, { 235000, 8, 0, 3 }, { 400000, 9, 0, 3 }, { 650000, 9, 2, 3 }, { 1000000, 9, 4, 4 }, { 1300000, 9, 6, 4 } },
      "comment" = "the Table 25 samurai advancement grid (capture pp. 39-40)",
      "col_comments" = { "the experience column: the upper xp bound of each level, 2,500 at 1st to 1,300,000 at 12th (capture pp. 39-40).", "the accumulated d10 dice column: one per level through 9th, then held at 9 (capture pp. 39-40).", "the hit-point bonus column: the printed 9-plus-N cells - 2 hp per level beyond 10th: 0 through 9th, then 2, 4, 6 (capture pp. 39-40).", "the damage bonus column: 0 at 1st, +1 from 2nd, +2 from 5th, +3 from 8th, +4 from 11th (capture pp. 39-40)." },
      "audit_comment" = "the Table 25 grid: the xp bounds, the accumulated dice plus bonus and the damage ladder (capture pp. 39-40)",
      "sentinel_census" = { 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgjSamuraiMinStr']() != 13  or m['dgjSamuraiMinWis']() != 13  or m['dgjSamuraiMinCon']() != 13  or m['dgjSamuraiMinInt']() != 14  or m['dgjSamuraiHitDie']() != 10  or m['dgjSamuraiSlots']() != 5  or m['dgjSamuraiBirthBonus']() != 10  or m['dgjSamuraiHorseLevel']() != 2  or m['dgjSamuraiBowLevel']() != 3  or m['dgjSamuraiArtsLevel']() != 6  or m['dgjSamuraiArtsCount']() != 3  or m['dgjSamuraiKiLevel']() != 1  or m['dgjSamuraiKiRounds']() != 1  or m['dgjSamuraiKiPerDayMult']() != 1  or m['dgjSamuraiDmgBaseLevel']() != 2  or m['dgjSamuraiDmgBase']() != 1  or m['dgjSamuraiDmgStepLevels']() != 3  or m['dgjSamuraiSurpriseLevel']() != 3  or m['dgjSamuraiSurpriseRoll']() != 1  or m['dgjSamuraiFearImmuneLevel']() != 5  or m['dgjSamuraiAppFearLevel']() != 6  or m['dgjSamuraiAppFearHdMax']() != 1  or m['dgjSamuraiJitoLevel']() != 7  or m['dgjSamuraiJitoTaxShareDiv']() != 4  or m['dgjSamuraiJitoBushi']() != 10  or m['dgjSamuraiJitoSamuraiMin']() != 1  or m['dgjSamuraiJitoSamuraiMax']() != 4  or m['dgjSamuraiJitoFollowerLevelMin']() != 1  or m['dgjSamuraiJitoFollowerLevelMax']() != 3  or m['dgjSamuraiShugoLevel']() != 8  or m['dgjSamuraiShugoBushiDice']() != 10  or m['dgjSamuraiShugoNinjaPct']() != 20  or m['dgjSamuraiSamuraiLevel']() != 9  or m['dgjSamuraiSamuraiDice']() != 10  or m['dgjSamuraiSpecialistMin']() != 2  or m['dgjSamuraiSpecialistMax']() != 7  or m['dgjSamuraiSpecialistNinjaPct']() != 10  or m['dgjSamuraiGreatKiaiLevel']() != 9  or m['dgjSamuraiGreatKiaiRounds']() != 2  or m['dgjSamuraiGreatKiaiRadius']() != 10  or m['dgjSamuraiGreatKiaiStunRounds']() != 1  or m['dgjSamuraiRoninXpMult']() != 2  or m['dgjT25RowCount']() != 12  or m['dgjT25XpBeyond']() != 300000  or m['dgjT25HpBeyond']() != 2  or  m['dgjSamuraiLawfulOnly']() != 1  or  m['dgjSamuraiFighterTables']() != 1  or  m['dgjSamuraiNoPrimeBonus']() != 1  or  m['dgjSamuraiKatanaRequired']() != 1  or  m['dgjSamuraiTwoWeaponOnly']() != 1  or  m['dgjSamuraiAnyArmorNoShield']() != 1  or  m['dgjSamuraiNinjaWeaponsHonorLoss']() != 1  or  m['dgjSamuraiHighestCaste']() != 1  or  m['dgjSamuraiKorobokuruSponsor']() != 1  or  m['dgjSamuraiKorobokuruBushi']() != 1  or  m['dgjSamuraiKiStrength1800']() != 1  or  m['dgjSamuraiAppFearControllable']() != 1  or  m['dgjSamuraiAppFearSaveAllowed']() != 1  or  m['dgjSamuraiJitoOptional']() != 1  or  m['dgjSamuraiJitoDaimyoLoyal']() != 1  or  m['dgjSamuraiJitoRetained']() != 1  or  m['dgjSamuraiJitoDaimyoProperty']() != 1  or  m['dgjSamuraiOneNinjaPerHousehold']() != 1  or  m['dgjSamuraiShugoLoyalWhilePaid']() != 1  or  m['dgjSamuraiFollowersAbsoluteLoyal']() != 1  or  m['dgjSamuraiGreatKiaiOnceDaily']() != 1  or  m['dgjSamuraiGreatKiaiExcludesKi']() != 1  or  m['dgjSamuraiGreatKiaiStunEffects']() != 1  or  m['dgjSamuraiBushidoPrecepts']() != 1  or  m['dgjSamuraiRoninDemotion']() != 1  or  m['dgjSamuraiRoninRetainsAbilities']() != 1  or  m['dgjSamuraiRoninReturnable']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgjSamuraiMinStr']() != 13",
      "note" = "the dgjSamuraiMinStr pin",
    }, {
      "expr" = "m['dgjSamuraiMinWis']() != 13",
      "note" = "the dgjSamuraiMinWis pin",
    }, {
      "expr" = "m['dgjSamuraiMinCon']() != 13",
      "note" = "the dgjSamuraiMinCon pin",
    }, {
      "expr" = "m['dgjSamuraiMinInt']() != 14",
      "note" = "the dgjSamuraiMinInt pin",
    }, {
      "expr" = "m['dgjSamuraiHitDie']() != 10",
      "note" = "the dgjSamuraiHitDie pin",
    }, {
      "expr" = "m['dgjSamuraiSlots']() != 5",
      "note" = "the dgjSamuraiSlots pin",
    }, {
      "expr" = "m['dgjSamuraiBirthBonus']() != 10",
      "note" = "the dgjSamuraiBirthBonus pin",
    }, {
      "expr" = "m['dgjSamuraiHorseLevel']() != 2",
      "note" = "the dgjSamuraiHorseLevel pin",
    }, {
      "expr" = "m['dgjSamuraiBowLevel']() != 3",
      "note" = "the dgjSamuraiBowLevel pin",
    }, {
      "expr" = "m['dgjSamuraiArtsLevel']() != 6",
      "note" = "the dgjSamuraiArtsLevel pin",
    }, {
      "expr" = "m['dgjSamuraiArtsCount']() != 3",
      "note" = "the dgjSamuraiArtsCount pin",
    }, {
      "expr" = "m['dgjSamuraiKiLevel']() != 1",
      "note" = "the dgjSamuraiKiLevel pin",
    }, {
      "expr" = "m['dgjSamuraiKiRounds']() != 1",
      "note" = "the dgjSamuraiKiRounds pin",
    }, {
      "expr" = "m['dgjSamuraiKiPerDayMult']() != 1",
      "note" = "the dgjSamuraiKiPerDayMult pin",
    }, {
      "expr" = "m['dgjSamuraiDmgBaseLevel']() != 2",
      "note" = "the dgjSamuraiDmgBaseLevel pin",
    }, {
      "expr" = "m['dgjSamuraiDmgBase']() != 1",
      "note" = "the dgjSamuraiDmgBase pin",
    }, {
      "expr" = "m['dgjSamuraiDmgStepLevels']() != 3",
      "note" = "the dgjSamuraiDmgStepLevels pin",
    }, {
      "expr" = "m['dgjSamuraiSurpriseLevel']() != 3",
      "note" = "the dgjSamuraiSurpriseLevel pin",
    }, {
      "expr" = "m['dgjSamuraiSurpriseRoll']() != 1",
      "note" = "the dgjSamuraiSurpriseRoll pin",
    }, {
      "expr" = "m['dgjSamuraiFearImmuneLevel']() != 5",
      "note" = "the dgjSamuraiFearImmuneLevel pin",
    }, {
      "expr" = "m['dgjSamuraiAppFearLevel']() != 6",
      "note" = "the dgjSamuraiAppFearLevel pin",
    }, {
      "expr" = "m['dgjSamuraiAppFearHdMax']() != 1",
      "note" = "the dgjSamuraiAppFearHdMax pin",
    }, {
      "expr" = "m['dgjSamuraiJitoLevel']() != 7",
      "note" = "the dgjSamuraiJitoLevel pin",
    }, {
      "expr" = "m['dgjSamuraiJitoTaxShareDiv']() != 4",
      "note" = "the dgjSamuraiJitoTaxShareDiv pin",
    }, {
      "expr" = "m['dgjSamuraiJitoBushi']() != 10",
      "note" = "the dgjSamuraiJitoBushi pin",
    }, {
      "expr" = "m['dgjSamuraiJitoSamuraiMin']() != 1",
      "note" = "the dgjSamuraiJitoSamuraiMin pin",
    }, {
      "expr" = "m['dgjSamuraiJitoSamuraiMax']() != 4",
      "note" = "the dgjSamuraiJitoSamuraiMax pin",
    }, {
      "expr" = "m['dgjSamuraiJitoFollowerLevelMin']() != 1",
      "note" = "the dgjSamuraiJitoFollowerLevelMin pin",
    }, {
      "expr" = "m['dgjSamuraiJitoFollowerLevelMax']() != 3",
      "note" = "the dgjSamuraiJitoFollowerLevelMax pin",
    }, {
      "expr" = "m['dgjSamuraiShugoLevel']() != 8",
      "note" = "the dgjSamuraiShugoLevel pin",
    }, {
      "expr" = "m['dgjSamuraiShugoBushiDice']() != 10",
      "note" = "the dgjSamuraiShugoBushiDice pin",
    }, {
      "expr" = "m['dgjSamuraiShugoNinjaPct']() != 20",
      "note" = "the dgjSamuraiShugoNinjaPct pin",
    }, {
      "expr" = "m['dgjSamuraiSamuraiLevel']() != 9",
      "note" = "the dgjSamuraiSamuraiLevel pin",
    }, {
      "expr" = "m['dgjSamuraiSamuraiDice']() != 10",
      "note" = "the dgjSamuraiSamuraiDice pin",
    }, {
      "expr" = "m['dgjSamuraiSpecialistMin']() != 2",
      "note" = "the dgjSamuraiSpecialistMin pin",
    }, {
      "expr" = "m['dgjSamuraiSpecialistMax']() != 7",
      "note" = "the dgjSamuraiSpecialistMax pin",
    }, {
      "expr" = "m['dgjSamuraiSpecialistNinjaPct']() != 10",
      "note" = "the dgjSamuraiSpecialistNinjaPct pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiLevel']() != 9",
      "note" = "the dgjSamuraiGreatKiaiLevel pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiRounds']() != 2",
      "note" = "the dgjSamuraiGreatKiaiRounds pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiRadius']() != 10",
      "note" = "the dgjSamuraiGreatKiaiRadius pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiStunRounds']() != 1",
      "note" = "the dgjSamuraiGreatKiaiStunRounds pin",
    }, {
      "expr" = "m['dgjSamuraiRoninXpMult']() != 2",
      "note" = "the dgjSamuraiRoninXpMult pin",
    }, {
      "expr" = "m['dgjT25RowCount']() != 12",
      "note" = "the dgjT25RowCount pin",
    }, {
      "expr" = "m['dgjT25XpBeyond']() != 300000",
      "note" = "the dgjT25XpBeyond pin",
    }, {
      "expr" = "m['dgjT25HpBeyond']() != 2",
      "note" = "the dgjT25HpBeyond pin",
    }, {
      "expr" = "m['dgjSamuraiLawfulOnly']() != 1",
      "note" = "the dgjSamuraiLawfulOnly pin",
    }, {
      "expr" = "m['dgjSamuraiFighterTables']() != 1",
      "note" = "the dgjSamuraiFighterTables pin",
    }, {
      "expr" = "m['dgjSamuraiNoPrimeBonus']() != 1",
      "note" = "the dgjSamuraiNoPrimeBonus pin",
    }, {
      "expr" = "m['dgjSamuraiKatanaRequired']() != 1",
      "note" = "the dgjSamuraiKatanaRequired pin",
    }, {
      "expr" = "m['dgjSamuraiTwoWeaponOnly']() != 1",
      "note" = "the dgjSamuraiTwoWeaponOnly pin",
    }, {
      "expr" = "m['dgjSamuraiAnyArmorNoShield']() != 1",
      "note" = "the dgjSamuraiAnyArmorNoShield pin",
    }, {
      "expr" = "m['dgjSamuraiNinjaWeaponsHonorLoss']() != 1",
      "note" = "the dgjSamuraiNinjaWeaponsHonorLoss pin",
    }, {
      "expr" = "m['dgjSamuraiHighestCaste']() != 1",
      "note" = "the dgjSamuraiHighestCaste pin",
    }, {
      "expr" = "m['dgjSamuraiKorobokuruSponsor']() != 1",
      "note" = "the dgjSamuraiKorobokuruSponsor pin",
    }, {
      "expr" = "m['dgjSamuraiKorobokuruBushi']() != 1",
      "note" = "the dgjSamuraiKorobokuruBushi pin",
    }, {
      "expr" = "m['dgjSamuraiKiStrength1800']() != 1",
      "note" = "the dgjSamuraiKiStrength1800 pin",
    }, {
      "expr" = "m['dgjSamuraiAppFearControllable']() != 1",
      "note" = "the dgjSamuraiAppFearControllable pin",
    }, {
      "expr" = "m['dgjSamuraiAppFearSaveAllowed']() != 1",
      "note" = "the dgjSamuraiAppFearSaveAllowed pin",
    }, {
      "expr" = "m['dgjSamuraiJitoOptional']() != 1",
      "note" = "the dgjSamuraiJitoOptional pin",
    }, {
      "expr" = "m['dgjSamuraiJitoDaimyoLoyal']() != 1",
      "note" = "the dgjSamuraiJitoDaimyoLoyal pin",
    }, {
      "expr" = "m['dgjSamuraiJitoRetained']() != 1",
      "note" = "the dgjSamuraiJitoRetained pin",
    }, {
      "expr" = "m['dgjSamuraiJitoDaimyoProperty']() != 1",
      "note" = "the dgjSamuraiJitoDaimyoProperty pin",
    }, {
      "expr" = "m['dgjSamuraiOneNinjaPerHousehold']() != 1",
      "note" = "the dgjSamuraiOneNinjaPerHousehold pin",
    }, {
      "expr" = "m['dgjSamuraiShugoLoyalWhilePaid']() != 1",
      "note" = "the dgjSamuraiShugoLoyalWhilePaid pin",
    }, {
      "expr" = "m['dgjSamuraiFollowersAbsoluteLoyal']() != 1",
      "note" = "the dgjSamuraiFollowersAbsoluteLoyal pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiOnceDaily']() != 1",
      "note" = "the dgjSamuraiGreatKiaiOnceDaily pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiExcludesKi']() != 1",
      "note" = "the dgjSamuraiGreatKiaiExcludesKi pin",
    }, {
      "expr" = "m['dgjSamuraiGreatKiaiStunEffects']() != 1",
      "note" = "the dgjSamuraiGreatKiaiStunEffects pin",
    }, {
      "expr" = "m['dgjSamuraiBushidoPrecepts']() != 1",
      "note" = "the dgjSamuraiBushidoPrecepts pin",
    }, {
      "expr" = "m['dgjSamuraiRoninDemotion']() != 1",
      "note" = "the dgjSamuraiRoninDemotion pin",
    }, {
      "expr" = "m['dgjSamuraiRoninRetainsAbilities']() != 1",
      "note" = "the dgjSamuraiRoninRetainsAbilities pin",
    }, {
      "expr" = "m['dgjSamuraiRoninReturnable']() != 1",
      "note" = "the dgjSamuraiRoninReturnable pin",
    }, {
      "expr" = "m['dgjT25XpMax'](0) != 2500  or m['dgjT25Dice'](0) != 1  or m['dgjT25HpBonus'](0) != 0  or m['dgjT25Dmg'](0) != 0",
      "note" = "the T25 first row - 2,500 xp, one die, no bonuses (capture p. 40)",
    }, {
      "expr" = "m['dgjT25XpMax'](11) != 1300000  or m['dgjT25Dice'](11) != 9  or m['dgjT25HpBonus'](11) != 6  or m['dgjT25Dmg'](11) != 4",
      "note" = "the T25 capstone - 1,300,000 xp, nine dice plus six, +4 damage (capture p. 40)",
    }, {
      "expr" = "m['dgjT25Dice'](9) != 9  or m['dgjT25HpBonus'](9) != 2",
      "note" = "the T25 9-plus-N cells open on the 10th-level row (capture p. 40)",
    }, {
      "expr" = "m['dgjT25Dmg'](4) != 2  or m['dgjT25Dmg'](7) != 3  or m['dgjSamuraiDmgStepLevels']() != 3",
      "note" = "the T25 damage ladder agrees with the prose - +2 at 5th, +3 at 8th (capture pp. 39-41)",
    }, {
      "expr" = "m['dgjT25HpBeyond']() != 2  or m['dgjT25XpBeyond']() != 300000",
      "note" = "the T25 beyond-10th hp step and the beyond-12th xp step (capture p. 40)",
    }, {
      "expr" = "m['dgjSamuraiKiPerDayMult']() * 7 != 7",
      "note" = "the ki ladder - the printed 7th-level example uses the ki seven times in a day (capture p. 41)",
    }, {
      "expr" = "m['dgjSamuraiJitoBushi']() != 10  or m['dgjSamuraiJitoSamuraiMin']() != 1  or m['dgjSamuraiJitoSamuraiMax']() != 4",
      "note" = "the jito grant - 10 bushi plus one to four samurai of 1st to 3rd (capture p. 41)",
    }, {
      "expr" = "m['dgjSamuraiSamuraiDice']() != 10  or m['dgjSamuraiSpecialistMin']() != 2  or m['dgjSamuraiSpecialistMax']() != 7",
      "note" = "the 9th-level followers - 2d10 samurai and the 2-7 specialists (capture p. 41)",
    } },
  "audit" = {
      "label" = "R623 OA samurai audit",
      "comment" = "OA round ten (capture pp. 39-42): the samurai - the minima, the caste birth doctrine, the ki powers, the stewardships with the follower doctrines, the bushido precepts and the ronin",
    },
}
