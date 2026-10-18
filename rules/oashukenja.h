// =========================================================================================
// Adnd1 - rules/oashukenja.h
// THE SHUKENJA, printed capture pp. 42-45 - the OA shukenja round
// census 546 -> 547.
//
// verified against capture pp. 42-45 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). The T26 row-1 and row-12 xp
// bounds are OCR-mangled in the capture (0-1 250 and 1,200,00) and settled
// against the 2018 print BEFORE pinning (1,250 and 1,200,000) per the
// settling doctrine. The T27 spell-bonus column pins as cumulative codes and
// the T28 dashes pin as zeros. OCR normalization: minimum scares reads as
// minimum scores; principal attitude reads as principal attribute; t has
// failed reads as it has failed (prose only)
//
// the gap census after this round: 49 closed, 186 open - the shukenja boxes
// with Tables 26, 27 and 28 flip (census 546 -> 547); NEXT - R625: the Sohei,
// capture pp. 45-47, Tables 29 and 30, prefix dgl (verify free), audit "R625
// OA sohei audit", include after rules/oashukenja.h
//
namespace rules {

// ---- the shukenja doctrine pins ----

// Shukenja prose (capture p. 43): the Wisdom minimum
inline int dgkShukenjaMinWis()
    { return 12; }

// Shukenja prose (capture p. 43): the Strength minimum
inline int dgkShukenjaMinStr()
    { return 9; }

// Shukenja prose (capture p. 43): the Constitution minimum
inline int dgkShukenjaMinCon()
    { return 9; }

// Shukenja prose (capture p. 43): must have good alignment - lawful, neutral
// or chaotic
inline bool dgkShukenjaGoodOnly()
    { return true; }

// Shukenja prose (capture p. 43): both Wisdom and Constitution 15 or greater
// earn the 10 percent experience bonus
inline int dgkShukenjaBonusStat()
    { return 15; }

// Shukenja prose (capture p. 43): the bonus value
inline int dgkShukenjaBonusPct()
    { return 10; }

// Shukenja prose (capture p. 44): the 6-sided hit die, one per level
inline int dgkShukenjaHitDie()
    { return 6; }

// Shukenja prose (capture p. 44): six proficiency slots at 1st level
inline int dgkShukenjaSlots()
    { return 6; }

// Shukenja prose (capture p. 44): only two of the slots may hold weapon
// proficiencies
inline int dgkShukenjaWeaponSlots()
    { return 2; }

// Shukenja prose (capture p. 44): one of the four non-weapon slots must be
// religion
inline bool dgkShukenjaReligionSlot()
    { return true; }

// Shukenja prose (capture p. 44): another slot must be calligraphy
inline bool dgkShukenjaCalligraphySlot()
    { return true; }

// Shukenja prose (capture p. 44): the combat and saving throw tables of
// clerics
inline bool dgkShukenjaClericTables()
    { return true; }

// Shukenja prose (capture p. 44): limited to studded leather or lesser armor,
// though certain individual pieces can be worn
inline bool dgkShukenjaStuddedLeatherCap()
    { return true; }

// Shukenja prose (capture p. 43): the self-sacrifice places him outside the
// caste system, respected by all members of society
inline bool dgkShukenjaOutsideCaste()
    { return true; }

// Shukenja prose (capture p. 44): no separate organized church - the temples
// are more or less independent, the beliefs intermingled
inline bool dgkShukenjaNoOrganizedChurch()
    { return true; }

// ---- the shukenja training pins ----

// Shukenja prose (capture p. 44): the ritual training - marriages,
// christenings, funeral rites, holy days and purifications
inline bool dgkShukenjaRitualTraining()
    { return true; }

// Shukenja prose (capture p. 44): the 5 percent per level chance to remove a
// curse with the purification ritual
inline int dgkShukenjaCursePctPerLevel()
    { return 5; }

// Shukenja prose (capture p. 44): the sanctified area has a 5-foot radius
inline int dgkShukenjaSanctifyRadius()
    { return 5; }

// Shukenja prose (capture p. 44): the printed 75 square feet of the
// sanctified area
inline int dgkShukenjaSanctifyArea()
    { return 75; }

// Shukenja prose (capture p. 44): +1 on to hit and saving throws vs evil
// spirits inside the circle
inline int dgkShukenjaSanctifyBonus()
    { return 1; }

// Shukenja prose (capture p. 44): the sanctified bonus lasts only while the
// shukenja remains within the circle
inline bool dgkShukenjaSanctifyWhilePresent()
    { return true; }

// Shukenja prose (capture p. 44): multiple purifications have no cumulative
// effect
inline bool dgkShukenjaSanctifyNoStack()
    { return true; }

// Shukenja prose (capture p. 44): one hour of uninterrupted meditation is as
// restful as two hours of sleep
inline int dgkShukenjaMeditationDiv()
    { return 2; }

// Shukenja prose (capture p. 44): meditating, he is oblivious to hunger,
// thirst, heat and cold but suffers no surprise or initiative penalties
inline bool dgkShukenjaMeditationAware()
    { return true; }

// Shukenja prose (capture p. 45): the self-defense training gives a free
// initial unarmed-combat style outside the slots
inline bool dgkShukenjaFreeStyle()
    { return true; }

// ---- the shukenja ethos pins ----

// Shukenja prose (capture p. 45): the ki focus improves the saving throw by
// +3
inline int dgkShukenjaKiSaveBonus()
    { return 3; }

// Shukenja prose (capture p. 45): the ki usable a number of times per day
// equal to level
inline int dgkShukenjaKiPerDayMult()
    { return 1; }

// Shukenja prose (capture p. 45): the ki decision can be made any point in
// the round unless the save die is already rolled
inline bool dgkShukenjaKiBeforeDieRolled()
    { return true; }

// Shukenja prose (capture p. 45): half the normal experience points for
// slaying or defeating humans and monsters
inline int dgkShukenjaDefeatedXpDiv()
    { return 2; }

// Shukenja prose (capture p. 45): full experience for defeating evil spirits
inline bool dgkShukenjaEvilSpiritFullXp()
    { return true; }

// Shukenja prose (capture p. 45): sworn to poverty - experience only for
// treasure donated to charity or the poor
inline bool dgkShukenjaDonatedTreasureXp()
    { return true; }

// Shukenja prose (capture p. 45): 100 experience points per spell level used
// to heal or aid an NPC outside the party
inline int dgkShukenjaHealXpPerSpellLevel()
    { return 100; }

// Shukenja prose (capture p. 45): cannot eat meat, must refrain from violence
// whenever possible, avoid immoderate drinking and eating
inline bool dgkShukenjaNoMeat()
    { return true; }

// Shukenja prose (capture p. 45): breaking the rules brings DM punishment -
// lost spell levels, lost honor or a penance; forced breaks count
inline bool dgkShukenjaRulePunishments()
    { return true; }

// Shukenja prose (capture p. 45): the religious life severs all ties - no
// family, clan or Table 38 birth roll
inline bool dgkShukenjaNoFamily()
    { return true; }

// Shukenja prose (capture p. 45): exempt from many honor penalties and
// bonuses - he has honor but it seldom reaches the heights
inline bool dgkShukenjaHonorLight()
    { return true; }

// ---- the Table 26, Table 27 and Table 28 grids ----

// Table 26 (capture p. 42): twelve rows, levels 1-12
inline int dgkT26RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 1,250 at 1st to
// 1,200,000 at 12th - the row-1 and row-12 bounds OCR-mangled in the capture
// (0-1 250 and 1,200,00) and settled against the 2018 print (capture p. 42).
inline int dgkT26XpMax(int b)
    {
        switch (b) {
        case 0:
            return 1250;
        case 1:
            return 3000;
        case 2:
            return 5500;
        case 3:
            return 11000;
        case 4:
            return 22000;
        case 5:
            return 44000;
        case 6:
            return 90000;
        case 7:
            return 150000;
        case 8:
            return 300000;
        case 9:
            return 600000;
        case 10:
            return 900000;
        case 11:
            return 1200000;
        default:
            return -99;
        }
    }

// the accumulated d6 dice column: one per level through 9th, then held at 9
// (capture p. 42).
inline int dgkT26Dice(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 9;
        default:
            return -99;
        }
    }

// the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level
// beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 42).
inline int dgkT26HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 3;
        default:
            return -99;
        }
    }

// Table 26 note (capture p. 42): 250,000 experience points are required for
// each level beyond 12th
inline int dgkT26XpBeyond()
    { return 250000; }

// Table 26 note (capture p. 42): shukenja gain 1 hp per level beyond 9th
inline int dgkT26HpBeyond()
    { return 1; }

// Table 27 (capture p. 43): ten rows, Wisdom scores 9 through 18
inline int dgkT27RowCount()
    { return 10; }

// Table 27 (capture p. 43): the first ability score row is 9 - the row index
// is the score minus 9
inline int dgkT27FirstScore()
    { return 9; }

// the spell-bonus code column: 0 none through Wisdom 12, then one additional
// 1st-level spell at 13-14 (code 1), one 2nd at 15-16 (code 2), one 3rd at 17
// (code 3), one 4th at 18 (code 4) - cumulative (capture p. 43).
inline int dgkT27Bonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        default:
            return -99;
        }
    }

// the spell-failure column: the percent chance a cast spell fails - 20 at
// Wisdom 9 down to 0 at 13 and above (capture p. 43).
inline int dgkT27Failure(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 5;
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
            return 0;
        default:
            return -99;
        }
    }

// Table 27 (capture p. 43): the spell-bonus code 0 - no bonus spells
inline int dgkT27BonusNone()
    { return 0; }

// Table 27 (capture p. 43): the code 1 - one additional 1st-level spell
inline int dgkT27BonusFirst()
    { return 1; }

// Table 27 (capture p. 43): the code 2 - one additional 2nd-level spell
inline int dgkT27BonusSecond()
    { return 2; }

// Table 27 (capture p. 43): the code 3 - one additional 3rd-level spell,
// Wisdom 17
inline int dgkT27BonusThird()
    { return 3; }

// Table 27 (capture p. 43): the code 4 - one additional 4th-level spell,
// Wisdom 18
inline int dgkT27BonusFourth()
    { return 4; }

// Table 27 footnote (capture p. 43): Wisdom 17 is the minimum for use of
// 6th-level spells
inline int dgkT27Spell6WisMin()
    { return 17; }

// Table 27 footnote (capture p. 43): Wisdom 18 is the minimum for use of
// 7th-level spells
inline int dgkT27Spell7WisMin()
    { return 18; }

// Table 28 (capture pp. 43-44): twenty-nine rows, levels 1-29
inline int dgkT28RowCount()
    { return 29; }

// Table 28 (capture p. 43): seven spell-level columns, 1st through 7th
inline int dgkT28SpellLevels()
    { return 7; }

// Table 28 (capture pp. 43-44): the maximum castable per spell level - nine
// 1st through five 7th
inline int dgkT28MaxCastable()
    { return 9; }

// the 1st-level spells column: 1 at 1st to 9 from 22nd (capture pp. 43-44).
inline int dgkT28S1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 8;
        case 21:
            return 9;
        case 22:
            return 9;
        case 23:
            return 9;
        case 24:
            return 9;
        case 25:
            return 9;
        case 26:
            return 9;
        case 27:
            return 9;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 2nd-level spells column: none until 4th, then 1 to 9 from 25th (capture
// pp. 43-44).
inline int dgkT28S2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
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
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 8;
        case 23:
            return 8;
        case 24:
            return 9;
        case 25:
            return 9;
        case 26:
            return 9;
        case 27:
            return 9;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 3rd-level spells column: none until 6th, then 1 to 9 from 28th (capture
// pp. 43-44).
inline int dgkT28S3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 8;
        case 26:
            return 8;
        case 27:
            return 9;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 4th-level spells column: none until 8th, then 1 to 9 at 29th (capture
// pp. 43-44).
inline int dgkT28S4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 6;
        case 24:
            return 6;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 8;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 5th-level spells column: none until 10th, then 1 to 8 at 29th (capture
// pp. 43-44).
inline int dgkT28S5(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 6;
        case 25:
            return 6;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 8;
        default:
            return -99;
        }
    }

// the 6th-level spells column: none until 14th, then 1 to 7 at 29th (capture
// pp. 43-44).
inline int dgkT28S6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 5;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 6;
        case 27:
            return 6;
        case 28:
            return 7;
        default:
            return -99;
        }
    }

// the 7th-level spells column: none until 18th, then 1 to 5 at 29th (capture
// pp. 43-44).
inline int dgkT28S7(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 3;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 5;
        default:
            return -99;
        }
    }

}   // namespace rules
