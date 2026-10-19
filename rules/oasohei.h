// =========================================================================================
// Adnd1 - rules/oasohei.h
// THE SOHEI, printed capture pp. 45-47 - the OA sohei round
// census 547 -> 548.
//
// verified against capture pp. 45-47 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). Two cells settled against
// the 2018 print BEFORE pinning, per the settling doctrine: the T29 row-4
// level cell (the capture prints 3 against four dice; the 2018 prints 4) and
// the fanaticism roll bonus (the capture prints plus 2; the 2018 prints minus
// 2, a lost plus against the sustain-himself reading). The T30 row 0 covers
// the printed levels 1-5 blank row; row k is level k plus 5. The dashes pin
// as zeros. OCR normalization: 1stlevel reads as 1st-level (prose only)
//
// the gap census after this round: 52 closed, 183 open - the sohei boxes with
// Tables 29 and 30 flip (census 547 -> 548); NEXT - R626: the Wu Jen, capture
// pp. 47-51, Table 31, prefix dgm (verify free), audit "R626 OA wu jen
// audit", include after rules/oasohei.h
//
namespace rules {

// ---- the sohei doctrine pins ----

// Sohei prose (capture p. 46): the Strength minimum
inline int dglSoheiMinStr()
    { return 13; }

// Sohei prose (capture p. 46): the Wisdom minimum
inline int dglSoheiMinWis()
    { return 10; }

// Sohei prose (capture p. 46): the Constitution minimum
inline int dglSoheiMinCon()
    { return 10; }

// Sohei prose (capture p. 46): two prime requisites - Strength and Wisdom
inline bool dglSoheiDualPrime()
    { return true; }

// Sohei prose (capture p. 46): both Strength and Wisdom 15 or greater earn
// the 10 percent experience bonus
inline int dglSoheiBonusStat()
    { return 15; }

// Sohei prose (capture p. 46): the bonus value
inline int dglSoheiBonusPct()
    { return 10; }

// Sohei prose (capture p. 46): must be lawful - good, neutral or evil,
// regardless of the home monastery alignment
inline bool dglSoheiLawfulOnly()
    { return true; }

// Sohei prose (capture p. 46): the 10-sided hit die, one per level
inline int dglSoheiHitDie()
    { return 10; }

// Sohei prose (capture p. 46): four proficiency slots at the beginning, any
// allowed weapon or peaceful art
inline int dglSoheiSlots()
    { return 4; }

// Sohei prose (capture p. 46): the combat and saving throw tables of clerics
inline bool dglSoheiClericTables()
    { return true; }

// Sohei prose (capture p. 46): allowed any armor and the Table 13 weapons
inline bool dglSoheiAnyArmor()
    { return true; }

// Sohei prose (capture p. 46): at higher levels casts shukenja spells - only
// the listed ones, with the same Table 27 bonuses and failure chances
inline bool dglSoheiCastShukenjaSpells()
    { return true; }

// Sohei prose (capture p. 46): more militant than holy, subject to the leader
// of the temple, defending the monastery and advancing its claims
inline bool dglSoheiMilitant()
    { return true; }

// Sohei prose (capture p. 47): the weapon of choice must be one with which he
// already has proficiency
inline bool dglSoheiWeaponChoiceProficiency()
    { return true; }

// Sohei prose (capture p. 47): the weapon of choice earns +1 on to hit and
// damage rolls
inline int dglSoheiWeaponChoiceBonus()
    { return 1; }

// ---- the sohei ki pins ----

// Sohei prose (capture p. 47): the berserk ki focus at 3rd level
inline int dglSoheiKiLevel()
    { return 3; }

// Sohei prose (capture p. 47): the berserk state lasts one turn
inline int dglSoheiKiDurationTurns()
    { return 1; }

// Sohei prose (capture p. 47): the berserk ki once per day
inline int dglSoheiKiPerDay()
    { return 1; }

// Sohei prose (capture p. 47): one extra attack per round in the berserk
// state
inline int dglSoheiKiExtraAttacks()
    { return 1; }

// Sohei prose (capture p. 47): the Armor Class improves by 1 in the berserk
// state
inline int dglSoheiKiAcBonus()
    { return 1; }

// Sohei prose (capture p. 47): the movement increases by 3 feet in the
// berserk state
inline int dglSoheiKiMoveBonus()
    { return 3; }

// Sohei prose (capture p. 47): an additional +1 on to hit, damage and saving
// throw rolls in the berserk state
inline int dglSoheiKiRollBonus()
    { return 1; }

// Sohei prose (capture p. 47): in the berserk state he can dodge or deflect
// missile weapons with a successful save vs breath weapon
inline bool dglSoheiKiMissileDeflection()
    { return true; }

// Sohei prose (capture p. 47): the fanaticism at 5th level - fighting on
// after 0 hit points
inline int dglSoheiFanaticLevel()
    { return 5; }

// Sohei prose (capture p. 47): the fight continues until -10 hit points or
// the enemy is defeated
inline int dglSoheiFanaticDeathHp()
    { return -10; }

// Sohei prose (capture p. 47): the +2 on to hit and damage rolls from the
// final ki reserves - the 2018 print lost the plus
inline int dglSoheiFanaticRollBonus()
    { return 2; }

// Sohei prose (capture p. 47): the fanaticism is a final act - no other
// actions, then collapse and death, earning posthumous honor
inline bool dglSoheiFanaticFinalAct()
    { return true; }

// ---- the sohei command pins ----

// Sohei prose (capture p. 47): the command over other sohei at 6th level
inline int dglSoheiCommandLevel()
    { return 6; }

// Sohei prose (capture p. 47): command over 10-30 other sohei, all 1st level
inline int dglSoheiCommandMin()
    { return 10; }

// Sohei prose (capture p. 47): the command upper bound
inline int dglSoheiCommandMax()
    { return 30; }

// Sohei prose (capture p. 47): the command grows by 10 sohei per level above
// 6th
inline int dglSoheiCommandStep()
    { return 10; }

// Sohei prose (capture p. 47): the fallen in the command are always replaced
// by additional 1st-level sohei
inline bool dglSoheiCommandReplaceable()
    { return true; }

// Sohei prose (capture p. 47): the command is lost only if all within it
// other than the commander are slain
inline bool dglSoheiCommandLostIfSlain()
    { return true; }

// Sohei prose (capture p. 47): the monastery commission at 9th level
inline int dglSoheiCommissionLevel()
    { return 9; }

// Sohei prose (capture p. 47): the commission makes him the commander of all
// sohei at the new monastery, still subject to the parent
inline bool dglSoheiCommissionCommander()
    { return true; }

// Sohei prose (capture p. 47): the less-strict rules - no meat but fish is
// allowed, no excess; no injunction against killing or violence though
// outright murder is a sin
inline bool dglSoheiFishAllowed()
    { return true; }

// Sohei prose (capture p. 47): full experience only for the monastery cause -
// one-half otherwise
inline int dglSoheiOffCauseXpDiv()
    { return 2; }

// Sohei prose (capture p. 47): any caste, no Table 38 roll required - the
// monastery is the new family
inline bool dglSoheiAnyCaste()
    { return true; }

// Sohei prose (capture p. 47): affected by honor more than a shukenja, but
// never gains honor for the actions of his monastery
inline bool dglSoheiHonorImportant()
    { return true; }

// ---- the Table 29 and Table 30 grids ----

// Table 29 (capture p. 45): twelve rows, levels 1-12
inline int dglT29RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 2,000 at 1st to
// 950,000 at 12th (capture p. 45).
inline int dglT29XpMax(int b)
    {
        switch (b) {
        case 0:
            return 2000;
        case 1:
            return 4000;
        case 2:
            return 7000;
        case 3:
            return 13000;
        case 4:
            return 24000;
        case 5:
            return 48000;
        case 6:
            return 85000;
        case 7:
            return 150000;
        case 8:
            return 350000;
        case 9:
            return 550000;
        case 10:
            return 750000;
        case 11:
            return 950000;
        default:
            return -99;
        }
    }

// the accumulated d10 dice column: one per level through 9th, then held at 9
// - the row-4 level cell OCR-mangled in the capture (3 against four dice) and
// settled against the 2018 print as level 4 (capture p. 45).
inline int dglT29Dice(int b)
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
// beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 45).
inline int dglT29HpBonus(int b)
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

// Table 29 note (capture pp. 45-46): 200,000 experience points are required
// for each level beyond 12th
inline int dglT29XpBeyond()
    { return 200000; }

// Table 29 note (capture p. 46): sohei gain 1 hp per level beyond 9th
inline int dglT29HpBeyond()
    { return 1; }

// Table 30 (capture p. 46): the levels 1-5 blank row plus the 6th through
// 29th rows - row 0 covers levels 1-5, row k is level k plus 5
inline int dglT30RowCount()
    { return 25; }

// Table 30 (capture p. 46): four spell-level columns, 1st through 4th
inline int dglT30SpellLevels()
    { return 4; }

// Table 30 (capture p. 46): no spells until 6th level
inline int dglT30FirstSpellLevel()
    { return 6; }

// Table 30 (capture p. 46): the maximum castable per spell level - seven 1st
// through six 4th
inline int dglT30MaxCastable()
    { return 7; }

// the 1st-level spells column: the row 0 levels 1-5 blank, then 1 at 6th to 7
// at 29th - the row index is the level minus 5 (capture p. 46).
inline int dglT30S1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
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
            return 3;
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
            return 6;
        case 23:
            return 6;
        case 24:
            return 7;
        default:
            return -99;
        }
    }

// the 2nd-level spells column: none until 7th, then 1 to 7 at 29th (capture
// p. 46).
inline int dglT30S2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 7;
        default:
            return -99;
        }
    }

// the 3rd-level spells column: none until 10th, then 1 to 6 at 29th (capture
// p. 46).
inline int dglT30S3(int b)
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
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 6;
        default:
            return -99;
        }
    }

// the 4th-level spells column: none until 15th, then 1 to 6 at 29th (capture
// p. 46).
inline int dglT30S4(int b)
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
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 4;
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
            return 6;
        case 24:
            return 6;
        default:
            return -99;
        }
    }

}   // namespace rules
