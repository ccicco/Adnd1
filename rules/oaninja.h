// =========================================================================================
// Adnd1 - rules/oaninja.h
// THE NINJA, printed capture pp. 35-39 - the OA ninja round
// census 544 -> 545.
//
// verified against capture pp. 35-39 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). Two cells settled against
// the 2018 print BEFORE pinning, per the settling doctrine: the T22 level-2
// bound pins as 8,000 (the 2018 8,001 cell contradicts its own next-row floor
// of 8,001) and the T23 Dex-11 pockets cell pins as -5 (the 2018 05 reading
// lost its minus against the ladder). The T24 pole-vault column pins in half
// feet. OCR normalization: 15 points for the bushi class reads as 1-5 points;
// infraction reads as infravision; 1096 reads as 10 percent (prose only)
//
// the gap census after this round: 43 closed, 192 open - the ninja boxes with
// Tables 22, 23 and 24 flip (census 544 -> 545); NEXT - R623: the Samurai,
// capture pp. 39-42, Table 25, prefix dgj (verify free), audit "R623 OA
// samurai audit", include after rules/oaninja.h
//
namespace rules {

// ---- the ninja doctrine pins ----

// Ninja prose (capture p. 36): the Dexterity minimum
inline int dgiNinjaMinDex()
    { return 14; }

// Ninja prose (capture p. 36): the Charisma minimum
inline int dgiNinjaMinCha()
    { return 14; }

// Ninja prose (capture p. 36): the Intelligence minimum
inline int dgiNinjaMinInt()
    { return 15; }

// Ninja prose (capture p. 36): the ninja class is only open to human
// characters
inline bool dgiNinjaHumanOnly()
    { return true; }

// Ninja prose (capture p. 36): not an independent class - the character must
// first qualify for the bushi, sohei, wu jen or yakuza class
inline bool dgiNinjaSplitClassOnly()
    { return true; }

// Ninja prose (capture p. 36): no prime requisite - the 10 percent bonus
// never applies to the ninja class even when earned in the other class
inline bool dgiNinjaNoPrimeBonus()
    { return true; }

// Ninja prose (capture p. 36): the experience points split between the two
// classes - normally exactly in half, the DM may skew
inline int dgiNinjaXpSplitDiv()
    { return 2; }

// Ninja prose (capture p. 36): 1-2 hit points for advancing a ninja level
inline int dgiNinjaHpMin()
    { return 1; }

// Ninja prose (capture p. 36): the hit-point upper bound per ninja level
inline int dgiNinjaHpMax()
    { return 2; }

// Ninja prose (capture p. 36): never the high-Constitution hit point bonus on
// the ninja rolls
inline bool dgiNinjaNoConBonusHp()
    { return true; }

// Ninja prose (capture p. 36): the other-class hit points - roll the normal
// die and divide the result by two
inline int dgiNinjaOtherHpDiv()
    { return 2; }

// Ninja prose (capture p. 36): the halved other-class die is rounded up, then
// the Constitution bonus of that class applies
inline bool dgiNinjaOtherHpRoundedUp()
    { return true; }

// Ninja prose (capture p. 36): the printed 1st-level bushi/ninja example -
// from 2 hit points (1-5 for the bushi class plus 1-2 for the ninja class)
inline int dgiNinjaExampleHpMin()
    { return 2; }

// Ninja prose (capture p. 36): the bushi/ninja example upper bound (5 plus 2)
inline int dgiNinjaExampleHpMax()
    { return 7; }

// Ninja prose (capture p. 36): always the saving throw tables of thieves
inline bool dgiNinjaThiefSaves()
    { return true; }

// Ninja prose (capture p. 36): the combat table of the other character class
inline bool dgiNinjaOtherCombatTable()
    { return true; }

// Ninja prose (capture p. 37): two proficiency slots at the beginning usable
// for the special ninja items
inline int dgiNinjaSlots()
    { return 2; }

// Ninja prose (capture p. 37): the special ninja weapons (Tables 49, 50 and
// 51) cost no honor, regardless of the other class
inline bool dgiNinjaWeaponsNoHonorLoss()
    { return true; }

// Ninja prose (capture p. 37): bushi/ninja who use other-class proficiencies
// to master ninja weapons lose honor
inline bool dgiNinjaCrossSlotHonorLoss()
    { return true; }

// Ninja prose (capture p. 37): wears the armor of the other class, though
// certain ninja abilities may not work in armor
inline bool dgiNinjaOtherClassArmor()
    { return true; }

// Ninja prose (capture p. 37): any magical items of the other class plus the
// ninja-only items
inline bool dgiNinjaMagicItemsUnion()
    { return true; }

// ---- the ninja capability pins ----

// Ninja prose (capture p. 37): move silently cannot be used while wearing
// metal armor
inline bool dgiNinjaSilentNoMetal()
    { return true; }

// Ninja prose (capture p. 37): nightingale floors reduce the move silently
// chance by one-half
inline int dgiNinjaNightingaleDiv()
    { return 2; }

// Ninja prose (capture p. 37): hide in shadows cannot be used while someone
// is watching - the character always thinks he is hidden
inline bool dgiNinjaHideWatched()
    { return true; }

// Ninja prose (capture p. 37): near a heat source the skill works against
// infravision - the heat blinds it
inline bool dgiNinjaHideInfravision()
    { return true; }

// Ninja prose (capture p. 37): find/remove traps works only for small traps,
// not large ones
inline bool dgiNinjaTrapsSmallOnly()
    { return true; }

// Ninja prose (capture p. 37): only one attempt per character per trap - an
// equal chance to remove once found
inline bool dgiNinjaTrapsOneAttempt()
    { return true; }

// Ninja prose (capture p. 37): climb walls cannot be used in metal armor
// other than chain mail
inline bool dgiNinjaClimbChainMail()
    { return true; }

// Ninja prose (capture p. 37): one climb check at the midpoint - failure
// means the fall at the midpoint
inline bool dgiNinjaClimbMidpointCheck()
    { return true; }

// Ninja prose (capture p. 37): disguise covers any general class of person of
// about the same height, weight and age
inline bool dgiNinjaDisguiseClassOnly()
    { return true; }

// Ninja prose (capture p. 37): the opposite-sex disguise chance is reduced by
// half
inline int dgiNinjaDisguiseSexDiv()
    { return 2; }

// Ninja prose (capture p. 37): impersonating a specific person is one-half
// the normal disguise percentage
inline int dgiNinjaDisguisePersonDiv()
    { return 2; }

// Ninja prose (capture p. 37): one month of close observation restores the
// normal impersonation chance
inline int dgiNinjaDisguiseObserveDays()
    { return 30; }

// Ninja prose (capture p. 37): once a specific-person impersonation fails,
// that person can never be impersonated
inline bool dgiNinjaDisguiseFailForever()
    { return true; }

// Ninja prose (capture p. 37): the DMG assassination tables, carefully
// planned, DM-adjusted - not a combat skill, unusable in melee
inline bool dgiNinjaAssassinatePlanned()
    { return true; }

// Ninja prose (capture p. 37): tightrope walking works on surfaces angled at
// 45 degrees or less
inline int dgiNinjaTightropeAngle()
    { return 45; }

// Ninja prose (capture p. 37): one tightrope check per 60 feet covered
inline int dgiNinjaTightropeCheckFeet()
    { return 60; }

// Ninja prose (capture p. 37): the tightrope movement rate, 60 feet per round
inline int dgiNinjaTightropeMove()
    { return 60; }

// Ninja prose (capture p. 37): a balancing item increases the tightrope
// chance by 10 percent
inline int dgiNinjaTightropeBalanceBonus()
    { return 10; }

// Ninja prose (capture pp. 37-38): moderate winds lower the tightrope chance
// by 10 percent
inline int dgiNinjaTightropeModerateWind()
    { return -10; }

// Ninja prose (capture p. 38): strong winds lower the tightrope chance by 20
// percent
inline int dgiNinjaTightropeStrongWind()
    { return -20; }

// Ninja prose (capture p. 38): gusting winds lower the tightrope chance by 30
// percent
inline int dgiNinjaTightropeGustingWind()
    { return -30; }

// Ninja prose (capture p. 38): fighting one-handed on a tightrope suffers -5
// to hit plus an immediate fall check
inline int dgiNinjaTightropeFightPenalty()
    { return -5; }

// Ninja prose (capture p. 38): no metal armor when pole vaulting
inline bool dgiNinjaVaultNoMetal()
    { return true; }

// Ninja prose (capture p. 38): the pole vault needs a 30-foot running start
inline int dgiNinjaVaultRunFeet()
    { return 30; }

// Ninja prose (capture p. 38): the pole must be at least four feet longer
// than the character
inline int dgiNinjaVaultPoleExtraFeet()
    { return 4; }

// Ninja prose (capture p. 38): vaulting atop an obstacle reduces the maximum
// height by 1 foot
inline int dgiNinjaVaultObstacleReduction()
    { return 1; }

// Ninja prose (capture p. 38): a distance vault covers twice the length of
// the pole
inline int dgiNinjaVaultDistanceMult()
    { return 2; }

// Ninja prose (capture p. 38): the safe fall allows no metal armor other than
// chain mail
inline bool dgiNinjaFallChainMail()
    { return true; }

// Ninja prose (capture p. 38): the safe fall needs a reachable vertical
// surface; beyond the stated distance the full damage applies
inline bool dgiNinjaFallVerticalSurface()
    { return true; }

// Ninja prose (capture p. 38): one escape attempt only - with guards present
// it is easily thwarted
inline bool dgiNinjaEscapeOneAttempt()
    { return true; }

// Ninja prose (capture p. 38): the escape attempt takes 1d10 rounds
inline int dgiNinjaEscapeRoundsDie()
    { return 10; }

// Ninja prose (capture p. 38): one try per lock per experience level
inline int dgiNinjaOpenLocksPerLevel()
    { return 1; }

// Ninja prose (capture p. 38): a failed lock never opens - the retry comes at
// the next experience level
inline bool dgiNinjaOpenLocksLockedForever()
    { return true; }

// Ninja prose (capture p. 38): the backstab strikes unnoticed from behind -
// the usual Strength, class and magic modifiers apply before the multiplier
inline bool dgiNinjaBackstabUnnoticed()
    { return true; }

// ---- the ninja ki and honor pins ----

// Ninja prose (capture p. 39): the breath-holding ki at 1st level - rounds
// equal to the ninja level
inline int dgiNinjaKiBreathLevel()
    { return 1; }

// Ninja prose (capture p. 39): the breath-holding ki is usable only once per
// day
inline bool dgiNinjaKiBreathOnceDaily()
    { return true; }

// Ninja prose (capture p. 39): the water-walking ki at 5th level
inline int dgiNinjaKiWaterLevel()
    { return 5; }

// Ninja prose (capture p. 39): the water walk crosses 5 feet of water per
// ninja level
inline int dgiNinjaKiWaterFeetPerLevel()
    { return 5; }

// Ninja prose (capture p. 39): the water-walking movement rate, 30 feet per
// round
inline int dgiNinjaKiWaterMove()
    { return 30; }

// Ninja prose (capture p. 39): the water-walking uses per day equal to the
// ninja level
inline int dgiNinjaKiWaterPerDayMult()
    { return 1; }

// Ninja prose (capture p. 39): any injury breaks the water-walking
// concentration
inline bool dgiNinjaKiWaterBrokenByInjury()
    { return true; }

// Ninja prose (capture p. 39): the wall-passing ki at 12th level - the
// ultimate ninja power
inline int dgiNinjaKiWallLevel()
    { return 12; }

// Ninja prose (capture p. 39): three rounds of concentration before entering
// the wall
inline int dgiNinjaKiWallPrepRounds()
    { return 3; }

// Ninja prose (capture p. 39): the wall pass lasts one round
inline int dgiNinjaKiWallDurationRounds()
    { return 1; }

// Ninja prose (capture p. 39): the wall pass moves 1 foot per experience
// level; not through by the end means death inside
inline int dgiNinjaKiWallFeetPerLevel()
    { return 1; }

// Ninja prose (capture p. 39): the wall pass needs the entire day ki -
// disturbance loses this and all other ki powers for the day
inline bool dgiNinjaKiWallCostsAllKi()
    { return true; }

// Ninja prose (capture p. 39): ruled absolutely by the head of the family -
// disobedience brings assassination attempts until the character dies or
// slays the head
inline bool dgiNinjaFamilyRule()
    { return true; }

// Ninja prose (capture p. 39): all missions come from the head of the family
// - the DM may forbid missions against player characters
inline bool dgiNinjaMissionsFromHead()
    { return true; }

// Ninja prose (capture p. 39): discovery of the true identity costs honor -
// others may know he is a ninja but never who he is
inline bool dgiNinjaIdentityCost()
    { return true; }

// Ninja prose (capture p. 39): failing a mission costs honor but the mission
// can be attempted again
inline bool dgiNinjaMissionRetryable()
    { return true; }

// Ninja prose (capture p. 39): refusing a mission loses all honor - defiance
// of the head of the family
inline bool dgiNinjaMissionRefusalAllHonor()
    { return true; }

// Ninja prose (capture p. 39): the ninja must maintain his honor above the
// family honor - the ninja honor measures obedience and loyalty
inline bool dgiNinjaHonorAboveFamily()
    { return true; }

// Ninja prose (capture p. 39): failing that carries the same punishment as
// disobedience, death - a survivor is a nukenin
inline bool dgiNinjaNukeDeathOrNukenin()
    { return true; }

// Ninja prose (capture p. 39): a nukenin needs twice the normal experience
// points to advance as a ninja - the other class advances normally
inline int dgiNinjaNukeXpMult()
    { return 2; }

// ---- the Table 22, Table 23 and Table 24 grids ----

// Table 22 (capture pp. 35-36): twelve rows, levels 1-12
inline int dgiT22RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 4,000 at 1st to
// 1,900,000 at 12th (capture pp. 35-36).
inline int dgiT22XpMax(int b)
    {
        switch (b) {
        case 0:
            return 4000;
        case 1:
            return 8000;
        case 2:
            return 15000;
        case 3:
            return 30000;
        case 4:
            return 60000;
        case 5:
            return 120000;
        case 6:
            return 240000;
        case 7:
            return 500000;
        case 8:
            return 1000000;
        case 9:
            return 1300000;
        case 10:
            return 1600000;
        case 11:
            return 1900000;
        default:
            return -99;
        }
    }

// the hit points per level column: the printed 1-2 range through 9th, then 1
// for the 10th through 12th rows (capture pp. 35-36).
inline int dgiT22HpMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        default:
            return -99;
        }
    }

// Table 22 note (capture p. 36): 300,000 experience points are required for
// each level beyond 12th
inline int dgiT22XpBeyond()
    { return 300000; }

// Table 22 (capture pp. 35-36): the hit-point column reads 1 for the 10th
// through 12th rows - 1 hp per level beyond 9th
inline int dgiT22HpBeyond()
    { return 1; }

// Table 23 (capture p. 36): ten rows, Dexterity scores 9 through 18
inline int dgiT23RowCount()
    { return 10; }

// Table 23 (capture p. 36): the first ability score row is 9 - the row index
// is the score minus 9
inline int dgiT23FirstScore()
    { return 9; }

// the picking pockets column: -15 percent at Dex 9 to +10 at 18 (capture p.
// 36).
inline int dgiT23Pockets(int b)
    {
        switch (b) {
        case 0:
            return -15;
        case 1:
            return -10;
        case 2:
            return -5;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the locating and removing traps column: -10 percent at Dex 9 to +5 at 18
// (capture p. 36).
inline int dgiT23Traps(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -10;
        case 2:
            return -5;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 5;
        default:
            return -99;
        }
    }

// the moving silently column: -20 percent at Dex 9 to +10 at 18 (capture p.
// 36).
inline int dgiT23Silent(int b)
    {
        switch (b) {
        case 0:
            return -20;
        case 1:
            return -15;
        case 2:
            return -10;
        case 3:
            return -5;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the hiding in shadows column: -10 percent at Dex 9 to +10 at 18 (capture p.
// 36).
inline int dgiT23Hide(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -5;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the open locks column: -15 percent at Dex 9 to +10 at 18 (capture p. 36).
inline int dgiT23Locks(int b)
    {
        switch (b) {
        case 0:
            return -15;
        case 1:
            return -10;
        case 2:
            return -5;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// Table 24 (capture pp. 38-39): twenty rows, levels 1-20
inline int dgiT24RowCount()
    { return 20; }

// Table 24 (capture pp. 38-39): the pole vault column is in half feet - the 8
// through 18 prime cells are the printed heights times two
inline int dgiT24VaultHalfFoot()
    { return 2; }

// the hide in shadows column: 10 percent at 1st to 99 at 20th (capture pp.
// 38-39).
inline int dgiT24Hide(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 31;
        case 5:
            return 37;
        case 6:
            return 43;
        case 7:
            return 49;
        case 8:
            return 56;
        case 9:
            return 63;
        case 10:
            return 70;
        case 11:
            return 77;
        case 12:
            return 85;
        case 13:
            return 93;
        case 14:
            return 94;
        case 15:
            return 95;
        case 16:
            return 96;
        case 17:
            return 97;
        case 18:
            return 98;
        case 19:
            return 99;
        default:
            return -99;
        }
    }

// the move silently column: 15 percent at 1st to 99 from 17th (capture pp.
// 38-39).
inline int dgiT24Silent(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 21;
        case 2:
            return 27;
        case 3:
            return 33;
        case 4:
            return 40;
        case 5:
            return 47;
        case 6:
            return 55;
        case 7:
            return 62;
        case 8:
            return 70;
        case 9:
            return 78;
        case 10:
            return 86;
        case 11:
            return 94;
        case 12:
            return 95;
        case 13:
            return 96;
        case 14:
            return 97;
        case 15:
            return 98;
        case 16:
            return 99;
        case 17:
            return 99;
        case 18:
            return 99;
        case 19:
            return 99;
        default:
            return -99;
        }
    }

// the find and remove traps column: 20 percent at 1st to 95 from 13th
// (capture pp. 38-39).
inline int dgiT24Traps(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 55;
        case 8:
            return 60;
        case 9:
            return 65;
        case 10:
            return 70;
        case 11:
            return 75;
        case 12:
            return 80;
        case 13:
            return 85;
        case 14:
            return 90;
        case 15:
            return 95;
        case 16:
            return 95;
        case 17:
            return 95;
        case 18:
            return 95;
        case 19:
            return 95;
        default:
            return -99;
        }
    }

// the climb walls column: 85 percent at 1st to 99 from 15th (capture pp.
// 38-39).
inline int dgiT24Climb(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 86;
        case 2:
            return 87;
        case 3:
            return 88;
        case 4:
            return 89;
        case 5:
            return 90;
        case 6:
            return 91;
        case 7:
            return 92;
        case 8:
            return 93;
        case 9:
            return 94;
        case 10:
            return 95;
        case 11:
            return 96;
        case 12:
            return 97;
        case 13:
            return 98;
        case 14:
            return 99;
        case 15:
            return 99;
        case 16:
            return 99;
        case 17:
            return 99;
        case 18:
            return 99;
        case 19:
            return 99;
        default:
            return -99;
        }
    }

// the disguise column: 20 percent at 1st to 96 at 20th (capture pp. 38-39).
inline int dgiT24Disguise(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 24;
        case 2:
            return 28;
        case 3:
            return 32;
        case 4:
            return 36;
        case 5:
            return 40;
        case 6:
            return 44;
        case 7:
            return 48;
        case 8:
            return 52;
        case 9:
            return 56;
        case 10:
            return 60;
        case 11:
            return 64;
        case 12:
            return 68;
        case 13:
            return 72;
        case 14:
            return 76;
        case 15:
            return 80;
        case 16:
            return 84;
        case 17:
            return 88;
        case 18:
            return 92;
        case 19:
            return 96;
        default:
            return -99;
        }
    }

// the open locks column: 25 percent at 1st to 99 from 17th (capture pp.
// 38-39).
inline int dgiT24Locks(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 29;
        case 2:
            return 33;
        case 3:
            return 37;
        case 4:
            return 42;
        case 5:
            return 47;
        case 6:
            return 52;
        case 7:
            return 57;
        case 8:
            return 62;
        case 9:
            return 67;
        case 10:
            return 72;
        case 11:
            return 77;
        case 12:
            return 82;
        case 13:
            return 87;
        case 14:
            return 92;
        case 15:
            return 97;
        case 16:
            return 99;
        case 17:
            return 99;
        case 18:
            return 99;
        case 19:
            return 99;
        default:
            return -99;
        }
    }

// the tightrope walk column: 20 percent at 1st to 99 at 20th (capture pp.
// 38-39).
inline int dgiT24Tightrope(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 55;
        case 8:
            return 60;
        case 9:
            return 65;
        case 10:
            return 70;
        case 11:
            return 75;
        case 12:
            return 80;
        case 13:
            return 85;
        case 14:
            return 90;
        case 15:
            return 95;
        case 16:
            return 96;
        case 17:
            return 97;
        case 18:
            return 98;
        case 19:
            return 99;
        default:
            return -99;
        }
    }

// the pole vault column in half feet: 16 (8 feet) at 1st to 36 (18 feet) at
// 20th (capture pp. 38-39).
inline int dgiT24Vault(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 18;
        case 2:
            return 19;
        case 3:
            return 20;
        case 4:
            return 21;
        case 5:
            return 22;
        case 6:
            return 23;
        case 7:
            return 24;
        case 8:
            return 25;
        case 9:
            return 26;
        case 10:
            return 27;
        case 11:
            return 28;
        case 12:
            return 29;
        case 13:
            return 30;
        case 14:
            return 31;
        case 15:
            return 32;
        case 16:
            return 33;
        case 17:
            return 34;
        case 18:
            return 35;
        case 19:
            return 36;
        default:
            return -99;
        }
    }

// the fall column: 0 feet at 1st and 2nd, then 10 at 3rd climbing 5 per level
// to 95 at 20th (capture pp. 38-39).
inline int dgiT24Fall(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 30;
        case 7:
            return 35;
        case 8:
            return 40;
        case 9:
            return 45;
        case 10:
            return 50;
        case 11:
            return 55;
        case 12:
            return 60;
        case 13:
            return 65;
        case 14:
            return 70;
        case 15:
            return 75;
        case 16:
            return 80;
        case 17:
            return 85;
        case 18:
            return 90;
        case 19:
            return 95;
        default:
            return -99;
        }
    }

// the escape column: 10 percent at 1st to 86 at 20th (capture pp. 38-39).
inline int dgiT24Escape(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 14;
        case 2:
            return 18;
        case 3:
            return 22;
        case 4:
            return 26;
        case 5:
            return 30;
        case 6:
            return 34;
        case 7:
            return 38;
        case 8:
            return 42;
        case 9:
            return 46;
        case 10:
            return 50;
        case 11:
            return 54;
        case 12:
            return 58;
        case 13:
            return 62;
        case 14:
            return 66;
        case 15:
            return 70;
        case 16:
            return 74;
        case 17:
            return 78;
        case 18:
            return 82;
        case 19:
            return 86;
        default:
            return -99;
        }
    }

// the backstab multiplier column: x2 at 1st, x3 at 5th, x4 at 10th, x5 at
// 20th (capture pp. 38-39).
inline int dgiT24Backstab(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 5;
        default:
            return -99;
        }
    }

}   // namespace rules
