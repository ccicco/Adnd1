// =========================================================================================
// Adnd1 - rules/oa83dragons.h
// OA MONSTERS - THE ORIENTAL DRAGONS, printed capture pp. 259-262 - the
// celestial bureau round
// census 634 -> 635.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 165 closed, 70 open - the oriental dragons
// box flips (census 634 -> 635); NEXT - R713: the Gaki, Lesser Spirit
// (capture pp. 262-263), prefix dka (verify free at the landing), audit "R713
// OA monsters Gaki audit", include after rules/oa83dragons.h
//
namespace rules {

// ---- the Celestial Bureaucracy ----

// the Celestial Bureaucracy position table - the seven dragon offices (print
// capture p. 260)
inline int djzBureauPositionRows()
    { return 7; }

// the oriental dragons additions - the chiang lung and the tun mi lung found
// in the Orient in addition to the FIEND FOLIO Tome list (print capture p.
// 260)
inline int djzAdditionDragons()
    { return 2; }

// the bureau doctrine - most oriental dragons are officials in the Celestial
// Bureaucracy, each type charged with an aspect of government (print capture
// p. 260)
inline int djzDragonsCelestialOfficials()
    { return 1; }

// the bureau report - once per year each dragon goes to the Celestial Palace
// and files a report of the previous year (print capture p. 260)
inline int djzYearlyPalaceReport()
    { return 1; }

// the bureau review - the report examined by the appropriate censors, rewards
// and punishments handed out (print capture p. 260)
inline int djzCensorsRewardPunish()
    { return 1; }

// the bureau turnover - corrupt or incompetent dragons removed and replaced
// by new appointees (print capture p. 260)
inline int djzCorruptDragonsReplaced()
    { return 1; }

// the bureau announcement - changes made known to humans by dreams announcing
// the new official and his arrival date (print capture p. 260)
inline int djzChangesAnnouncedByDreams()
    { return 1; }

// the human response - a ceremonial procession and banquet of offerings to
// please and curry favor with the new dragon (print capture p. 260)
inline int djzHumansCurryFavorProcession()
    { return 1; }

// the li lung office - control of the energies of the earth (print capture p.
// 260)
inline int djzLiLungEarthEnergies()
    { return 1; }

// the lung wang office - guardians of sea creatures, aide to the Sea Lords
// (print capture p. 260)
inline int djzLungWangSeaGuardians()
    { return 1; }

// the pan lung office - guardians of hidden places (print capture p. 260)
inline int djzPanLungHiddenPlaces()
    { return 1; }

// the shen lung office - aides to the chiang lung (print capture p. 260)
inline int djzShenLungAides()
    { return 1; }

// the t'ien lung office - masters of weather except rain (print capture p.
// 260)
inline int djzTienLungWeatherMasters()
    { return 1; }

// the chiang lung office - guardians of rivers and lakes, bringers of rain
// (print capture p. 260)
inline int djzChiangLungPosition()
    { return 1; }

// the tun mi lung office - dispenser of ocean storms (print capture p. 260)
inline int djzTunMiLungPosition()
    { return 1; }

// the yu lung exclusion - no official position, not of the greater dragon
// class, receives no offerings and has no cult (print capture p. 260)
inline int djzYuLungNoPosition()
    { return 1; }

// ---- the chiang lung stat block ----

// the chiang lung appearance minimum - the 1 of the 1-2 (print capture p.
// 260)
inline int djzChiangNoAppMin()
    { return 1; }

// the chiang lung appearance maximum - the 2 of the 1-2 (print capture p.
// 260)
inline int djzChiangNoAppMax()
    { return 2; }

// the chiang lung armor class - the AC 2 of the stat block (print capture p.
// 260)
inline int djzChiangAC()
    { return 2; }

// the chiang lung walk rate - the 12' of the move 12'/18'//24' (print capture
// p. 260)
inline int djzChiangMoveWalk()
    { return 12; }

// the chiang lung swim rate - the 18' of the move 12'/18'//24' (print capture
// p. 260)
inline int djzChiangMoveSwim()
    { return 18; }

// the chiang lung fly rate - the 24' of the move 12'/18'//24' (print capture
// p. 260)
inline int djzChiangMoveFly()
    { return 24; }

// the chiang lung hit-dice minimum - the 10 of the 10-12 (print capture p.
// 260)
inline int djzChiangHDMin()
    { return 10; }

// the chiang lung hit-dice maximum - the 12 of the 10-12 (print capture p.
// 260)
inline int djzChiangHDMax()
    { return 12; }

// the chiang lung in-lair percentage - the 80% of the stat block (print
// capture p. 260)
inline int djzChiangLairPct()
    { return 80; }

// the chiang lung attacks per round - the 3 of the stat block (print capture
// p. 260)
inline int djzChiangAttacks()
    { return 3; }

// the chiang lung claw damage minimum - the 1 of the 1-6/1-6/3-36 (print
// capture p. 260)
inline int djzChiangClawDmgMin()
    { return 1; }

// the chiang lung claw damage maximum - the 6 of the 1-6/1-6/3-36 (print
// capture p. 260)
inline int djzChiangClawDmgMax()
    { return 6; }

// the chiang lung bite damage minimum - the 3 of the 1-6/1-6/3-36 (print
// capture p. 260)
inline int djzChiangBiteDmgMin()
    { return 3; }

// the chiang lung bite damage maximum - the 36 of the 1-6/1-6/3-36 (print
// capture p. 260)
inline int djzChiangBiteDmgMax()
    { return 36; }

// the chiang lung magic resistance - the 10% of the stat block (print capture
// p. 260)
inline int djzChiangMRPct()
    { return 10; }

// the chiang lung length minimum - the 50' of the 50'-60' size L entry (print
// capture p. 260)
inline int djzChiangSizeMinFt()
    { return 50; }

// the chiang lung length maximum - the 60' of the 50'-60' size L entry (print
// capture p. 260)
inline int djzChiangSizeMaxFt()
    { return 60; }

// the chiang lung 10 HD experience - the VII/13,750 + 14 per hp tier (the
// djvu garble VII113,750 settled by the VII/13,750 read) (print capture p.
// 260)
inline int djzChiangXP10HDBase()
    { return 13750; }

// the chiang lung 10 HD experience per hit point - the + 14 of the VII/13,750
// tier (print capture p. 260)
inline int djzChiangXP10HDPerHP()
    { return 14; }

// the chiang lung 11 and 12 HD experience level - the VIII of the VIII/5,400
// tier (print capture p. 260)
inline int djzChiangXP1112HDLevel()
    { return 8; }

// the chiang lung 11 and 12 HD experience - the VIII/5,400 + 16 per hp tier
// (print capture p. 260)
inline int djzChiangXP1112HDBase()
    { return 5400; }

// the chiang lung 11 and 12 HD experience per hit point - the + 16 of the
// VIII/5,400 tier (print capture p. 260)
inline int djzChiangXP1112HDPerHP()
    { return 16; }

// the chiang lung frequency - the rare of the stat block (print capture p.
// 260)
inline int djzChiangRare()
    { return 1; }

// the chiang lung treasure - the type F of the stat block (print capture p.
// 260)
inline int djzChiangTreasureF()
    { return 1; }

// the chiang lung intelligence - the high to genius of the stat block (print
// capture p. 260)
inline int djzChiangIntHighToGenius()
    { return 1; }

// the chiang lung alignment - the lawful neutral tending to good (print
// capture p. 260)
inline int djzChiangLawfulNeutralGood()
    { return 1; }

// the chiang lung psionics - the Nil ability and the Nil attack/defense modes
// (print capture p. 260)
inline int djzChiangPsionicNil()
    { return 1; }

// ---- the chiang lung nature ----

// the chiang lung at-will battery - the bless, curse, omen, fate, dispel
// evil, control weather, remove curse, usable once per round (print capture
// p. 261)
inline int djzChiangAtWillSpellCount()
    { return 7; }

// the chiang lung once-per-day spells - the major creation and the reward
// (print capture p. 261)
inline int djzChiangOncePerDaySpellCount()
    { return 2; }

// the chiang lung languages - the Celestial Court, the fishes, the shen lung,
// their own, all human languages (print capture p. 261)
inline int djzChiangLangCount()
    { return 5; }

// the chiang lung lower water - the 1-square-mile radius per age level as
// desired (print capture p. 261)
inline int djzChiangLowerWaterSqMiPerAge()
    { return 1; }

// the chiang lung human form - armed with a sword +5 (print capture p. 261)
inline int djzChiangHumanFormSwordPlus()
    { return 5; }

// the chiang lung bodyguard minimum - the 1 of the 1d6 shen lung at the
// mansion (print capture p. 261)
inline int djzChiangBodyguardShenMin()
    { return 1; }

// the chiang lung bodyguard maximum - the 6 of the 1d6 shen lung (print
// capture p. 261)
inline int djzChiangBodyguardShenMax()
    { return 6; }

// the chiang lung children minimum - the 2 of the 2d4 children present (print
// capture p. 261)
inline int djzChiangChildrenMin()
    { return 2; }

// the chiang lung children maximum - the 4 of the 2d4 children (print capture
// p. 261)
inline int djzChiangChildrenMax()
    { return 4; }

// the chiang lung outside-lair escort - the 75% chance of 1d4 lesser nature
// spirits (print capture p. 261)
inline int djzChiangOutsideSpiritPct()
    { return 75; }

// the chiang lung outside-lair spirits minimum - the 1 of the 1d4 (print
// capture p. 261)
inline int djzChiangOutsideSpiritMin()
    { return 1; }

// the chiang lung outside-lair spirits maximum - the 4 of the 1d4 (print
// capture p. 261)
inline int djzChiangOutsideSpiritMax()
    { return 4; }

// the chiang lung outside-lair shen - the 40% chance of 1-2 shen lung (print
// capture p. 261)
inline int djzChiangOutsideShenPct()
    { return 40; }

// the chiang lung outside-lair shen minimum - the 1 of the 1-2 (print capture
// p. 261)
inline int djzChiangOutsideShenMin()
    { return 1; }

// the chiang lung outside-lair shen maximum - the 2 of the 1-2 (print capture
// p. 261)
inline int djzChiangOutsideShenMax()
    { return 2; }

// the chiang lung office in practice - lords of rivers and lakes, responsible
// for the denizens of the waters, the giving of rain, and the flow of waters
// (print capture p. 261)
inline int djzChiangRiverLakeLord()
    { return 1; }

// the chiang lung ubiquity - one present in every river and lake, seldom
// appearing to humans outside their jurisdiction (print capture p. 261)
inline int djzChiangEveryWaterPresent()
    { return 1; }

// the chiang lung obedience - act upon the orders of the Celestial Emperor
// and report to him once a year (print capture p. 261)
inline int djzChiangEmperorOrders()
    { return 1; }

// the chiang lung flight - wingless, flying through the power of a magical
// pearl lodged in the brain (print capture p. 261)
inline int djzChiangPearlFlight()
    { return 1; }

// the chiang lung change - polymorph to any form desired beyond the common
// oriental dragon powers (print capture p. 261)
inline int djzChiangPolymorphAny()
    { return 1; }

// the chiang lung breath - expels dark rain clouds, enabling rain when and
// where desired (print capture p. 261)
inline int djzChiangRainCloudBreath()
    { return 1; }

// the chiang lung petition - humans make offerings beseeching intercession
// with the Celestial Emperor for rain in drought or lessened waters in flood
// (print capture p. 261)
inline int djzChiangOfferingIntercession()
    { return 1; }

// the chiang lung discipline - do not act unless properly ordered, for
// disobedience is punished by death (print capture p. 261)
inline int djzChiangNoActionWithoutOrders()
    { return 1; }

// the chiang lung escort - any person accompanied can breathe and move
// underwater as if on dry land (print capture p. 261)
inline int djzChiangUnderwaterEscort()
    { return 1; }

// the chiang lung tsunami - cast upon special orders of the Celestial Emperor
// (print capture p. 261)
inline int djzChiangTsunamiOnOrders()
    { return 1; }

// the chiang lung blade - in human form armed with a sword +5 so massive
// others need a bend bars/lift gates roll to use it (print capture p. 261)
inline int djzChiangSwordBendBars()
    { return 1; }

// the chiang lung lair - a magical palace under the waves, always of great
// size and wealth regardless of the size of the river or lake (print capture
// p. 261)
inline int djzChiangPalaceUnderWaves()
    { return 1; }

// the chiang lung hoard rule - items stolen from the mansion become worthless
// upon reaching the surface; only items freely given are exempt (print
// capture p. 261)
inline int djzChiangStolenGoodsWorthless()
    { return 1; }

// the chiang lung preference - always assumes human form in the mansion and
// seems to prefer it (print capture p. 261)
inline int djzChiangMansionHumanForm()
    { return 1; }

// the chiang lung court - well-attended by lesser nature spirit servants also
// in human form (print capture p. 261)
inline int djzChiangSpiritServants()
    { return 1; }

// the chiang lung pastime - a fondness for virtuous scholars and men of
// learning, entertaining them on lavish boats posing as wealthy nobles, the
// scholar waking at dawn alone with a token (print capture p. 261)
inline int djzChiangScholarBoatParties()
    { return 1; }

// the chiang lung daughters - strikingly beautiful and gracious, given in
// marriage to a courageous or clever hero, a great honor seldom refused; the
// liaison ends sadly as she returns home never to see her husband again, and
// the children of such a marriage are spirit folk (print capture p. 261)
inline int djzChiangDaughterMarriages()
    { return 1; }

// ---- the tun mi lung stat block ----

// the tun mi lung appearance count - the 1 of the stat block (print capture
// p. 261)
inline int djzTunMiNoApp()
    { return 1; }

// the tun mi lung armor class - the AC -1 of the stat block (print capture p.
// 261)
inline int djzTunMiAC()
    { return -1; }

// the tun mi lung movement rate - the move 9 of the stat block (print capture
// p. 261)
inline int djzTunMiMove()
    { return 9; }

// the tun mi lung hit-dice minimum - the 10 of the 10-12 (print capture p.
// 261)
inline int djzTunMiHDMin()
    { return 10; }

// the tun mi lung hit-dice maximum - the 12 of the 10-12 (print capture p.
// 261)
inline int djzTunMiHDMax()
    { return 12; }

// the tun mi lung in-lair percentage - the 20% of the stat block (print
// capture p. 261)
inline int djzTunMiLairPct()
    { return 20; }

// the tun mi lung attacks per round - the 3 of the stat block (print capture
// p. 262)
inline int djzTunMiAttacks()
    { return 3; }

// the tun mi lung claw damage minimum - the 1 of the 1-3/1-3/2-20 (print
// capture p. 262)
inline int djzTunMiClawDmgMin()
    { return 1; }

// the tun mi lung claw damage maximum - the 3 of the 1-3/1-3/2-20 (print
// capture p. 262)
inline int djzTunMiClawDmgMax()
    { return 3; }

// the tun mi lung bite damage minimum - the 2 of the 1-3/1-3/2-20 (print
// capture p. 262)
inline int djzTunMiBiteDmgMin()
    { return 2; }

// the tun mi lung bite damage maximum - the 20 of the 1-3/1-3/2-20 (print
// capture p. 262)
inline int djzTunMiBiteDmgMax()
    { return 20; }

// the tun mi lung length minimum - the 60' of the 60'-80' size L entry (print
// capture p. 262)
inline int djzTunMiSizeMinFt()
    { return 60; }

// the tun mi lung length maximum - the 80' of the 60'-80' size L entry (print
// capture p. 262)
inline int djzTunMiSizeMaxFt()
    { return 80; }

// the tun mi lung 11 and 12 HD experience - the VII/14,400 + 16 per hp tier
// (the djvu garble V11114,400 settled by the VII/14,400 read) (print capture
// p. 262)
inline int djzTunMiXP1112HDBase()
    { return 14400; }

// the tun mi lung 11 and 12 HD experience per hit point - the + 16 of the
// VII/14,400 tier (print capture p. 262)
inline int djzTunMiXP1112HDPerHP()
    { return 16; }

// the tun mi lung frequency - the very rare of the stat block (print capture
// p. 261)
inline int djzTunMiVeryRare()
    { return 1; }

// the tun mi lung treasure - the type F of the stat block (print capture p.
// 261)
inline int djzTunMiTreasureF()
    { return 1; }

// the tun mi lung magic resistance - the standard of the stat block (print
// capture p. 262)
inline int djzTunMiMRStandard()
    { return 1; }

// the tun mi lung intelligence - the average of the stat block (print capture
// p. 262)
inline int djzTunMiIntAverage()
    { return 1; }

// the tun mi lung alignment - the neutral evil of the stat block (print
// capture p. 262)
inline int djzTunMiNeutralEvil()
    { return 1; }

// the tun mi lung size - the L of the stat block (print capture p. 262)
inline int djzTunMiSizeL()
    { return 1; }

// the tun mi lung psionics - the Nil ability and the Nil attack/defense modes
// (print capture p. 262)
inline int djzTunMiPsionicNil()
    { return 1; }

// ---- the tun mi lung nature ----

// the tun mi lung divine wind - the radius equal to five times the age level
// in miles (print capture p. 262)
inline int djzTunMiDivineWindMilesPerAge()
    { return 5; }

// the tun mi lung divine wind duration - the 6 of the 6d4 hours (print
// capture p. 262)
inline int djzTunMiDivineWindDurationDice()
    { return 6; }

// the tun mi lung divine wind duration sides - the 4 of the 6d4 hours (print
// capture p. 262)
inline int djzTunMiDivineWindDurationSides()
    { return 4; }

// the tun mi lung languages - all sea creatures, the Celestial Court, the Sea
// Lords (print capture p. 262)
inline int djzTunMiLangCount()
    { return 3; }

// the tun mi lung habitat - dwells in the seas and oceans, most commonly
// encountered in the sky along seacoasts or far out to sea (print capture p.
// 262)
inline int djzTunMiSeaSkyHabitat()
    { return 1; }

// the tun mi lung flight - wingless, the power of flight from a magical pearl
// lodged in its brain (print capture p. 262)
inline int djzTunMiPearlFlight()
    { return 1; }

// the tun mi lung charge - causing destructive typhoons and hurricanes
// ravaging the coasts of warmer lands, a task they enjoy greatly (print
// capture p. 262)
inline int djzTunMiTyphoonDuty()
    { return 1; }

// the tun mi lung temper - supposed to act only on the orders of the
// Celestial Bureaucracy but launches destructive rampages out of sheer
// maliciousness, so great their power even the Celestial Emperor finds them
// hard to restrain and punish (print capture p. 262)
inline int djzTunMiMaliciousRampages()
    { return 1; }

// the tun mi lung divine wind - summonable only once per week, the dragon
// always at the center of the storm, which moves along with him (print
// capture p. 262)
inline int djzTunMiDivineWindOncePerWeek()
    { return 1; }

// the tun mi lung fallback - should the typhoon power be insufficient,
// attacks with claws and bite; possesses no breath weapon (print capture p.
// 262)
inline int djzTunMiClawsAndBiteFallback()
    { return 1; }

// the tun mi lung immunity - immune to all water- and air-based attacks
// (print capture p. 262)
inline int djzTunMiImmuneWaterAir()
    { return 1; }

// the tun mi lung lair - nothing conclusive known, probably palaces
// appropriate to their station in remote corners of the ocean, their evil
// nature making them unwelcome to the peaceful and cultured creatures of the
// sea (print capture p. 262)
inline int djzTunMiRemoteUnderseaLair()
    { return 1; }

}   // namespace rules
