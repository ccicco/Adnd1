// =========================================================================================
// Adnd1 - rules/oamonk.h
// THE MONK, printed capture pp. 31-35 - the OA monk round
// census 543 -> 544.
//
// verified against capture pp. 31-35 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). The Table 20 hit-points
// column header is settled against the 2018 print (4-sided dice for accum.
// hit points) - the 2-through-18 cells pin as accumulated d4 dice, the level
// plus one. The Table 21 additional-attack and additional-damage cells pin as
// codes (the slash pairs and the plus-dice notation). OCR normalization: may
// riot own horses reads as may not own horses; immune to gees reads as immune
// to geas (prose only)
//
// the gap census after this round: 39 closed, 196 open - the monk boxes with
// Tables 20 and 21 flip (census 543 -> 544); NEXT - R622: the Ninja, capture
// pp. 35-39, Tables 22 and 23, prefix dgi (verify free), audit "R622 OA ninja
// audit", include after rules/oamonk.h
//
namespace rules {

// ---- the monk doctrine pins ----

// Monk prose (capture p. 32): the Strength minimum
inline int dghMonkMinStr()
    { return 15; }

// Monk prose (capture p. 32): the Wisdom minimum
inline int dghMonkMinWis()
    { return 15; }

// Monk prose (capture p. 32): the Dexterity minimum
inline int dghMonkMinDex()
    { return 15; }

// Monk prose (capture p. 32): the Constitution minimum
inline int dghMonkMinCon()
    { return 11; }

// Monk prose (capture p. 32): must always be lawful - good, evil or neutral
// combined with law
inline bool dghMonkLawfulOnly()
    { return true; }

// Monk prose (capture p. 32): no prime requisite - never the experience point
// bonus for high scores
inline bool dghMonkNoPrimeBonus()
    { return true; }

// Monk prose (capture p. 32): never bonuses on to hit or damage rolls for
// high Strength
inline bool dghMonkNoStrAdjust()
    { return true; }

// Monk prose (capture p. 32): never armor class adjustments for high
// Dexterity
inline bool dghMonkNoDexAc()
    { return true; }

// Monk prose (capture pp. 31-32): monks do not advance beyond 17th level
inline int dghMonkMaxLevel()
    { return 17; }

// Monk prose (capture p. 32): begins with 2-8 (2d4) hit points
inline int dghMonkStartDice()
    { return 2; }

// Monk prose (capture p. 32): gains 1d4 hit points per level thereafter
inline int dghMonkHitDie()
    { return 4; }

// Monk prose (capture p. 32): the combat table and saving throw tables of
// thieves
inline bool dghMonkThiefTables()
    { return true; }

// Monk prose (capture p. 32): cannot wear armor or use shields
inline bool dghMonkNoArmor()
    { return true; }

// Monk prose (capture p. 32): the use of flaming oil in combat is forbidden
inline bool dghMonkNoFlamingOil()
    { return true; }

// Monk prose (capture p. 32): one extra point of weapon damage per two
// experience levels
inline int dghMonkWeaponDmgStep()
    { return 2; }

// Monk prose (capture p. 32): base movement of 15 feet, improving per Table
// 21
inline int dghMonkBaseMove()
    { return 15; }

// Monk prose (capture p. 32): five other proficiency slots beyond the style
inline int dghMonkSlots()
    { return 5; }

// Monk prose (capture p. 32): two of the style special maneuvers at start
inline int dghMonkStyleManeuvers()
    { return 2; }

// Monk prose (capture p. 32): all monks have the Missile Deflection maneuver
// free - outside the style slots
inline bool dghMonkMissileDeflection()
    { return true; }

// Monk prose (capture p. 33): the ki power usable a number of times per day
// equal to level
inline int dghMonkKiPerDayMult()
    { return 1; }

// Monk prose (capture p. 33): the 1st-level ki - a successful save vs magic
// means no damage or effect
inline bool dghMonkKiSaveNegates()
    { return true; }

// Monk prose (capture p. 33): the ki use can be declared at any time, even
// after the die is rolled
inline bool dghMonkKiDeclaredLate()
    { return true; }

// ---- the monk level-power pins ----

// Monk prose (capture p. 33): speak with animals at 3rd level, nonmagical
inline int dghMonkSpeakAnimalsLevel()
    { return 3; }

// Monk prose (capture p. 33): the 20-foot fall at 4th level
inline int dghMonkFall20Level()
    { return 4; }

// Monk prose (capture p. 33): fall up to 20 feet without damage
inline int dghMonkFall20Feet()
    { return 20; }

// Monk prose (capture p. 33): provided he is within one foot of a wall
inline int dghMonkFall20WallFeet()
    { return 1; }

// Monk prose (capture p. 33): ESP has only a 30 percent chance at 4th level
inline int dghMonkEspBasePct()
    { return 30; }

// Monk prose (capture p. 33): the ESP protection improves by 2 percent per
// level beyond 4th
inline int dghMonkEspStepPct()
    { return 2; }

// Monk prose (capture p. 33): immune to all disease at 5th level
inline int dghMonkDiseaseLevel()
    { return 5; }

// Monk prose (capture p. 33): at 5th level immune to all types of disease
inline bool dghMonkDiseaseImmune()
    { return true; }

// Monk prose (capture p. 33): at 5th level unaffected by all haste or slow
// spells
inline bool dghMonkHasteSlowImmune()
    { return true; }

// Monk prose (capture p. 33): the 30-foot fall at 6th level
inline int dghMonkFall30Level()
    { return 6; }

// Monk prose (capture p. 33): fall 30 feet without damage
inline int dghMonkFall30Feet()
    { return 30; }

// Monk prose (capture p. 33): provided he is within four feet of a wall
inline int dghMonkFall30WallFeet()
    { return 4; }

// Monk prose (capture pp. 33-34): the cataleptic state lasts turns equal to
// twice his level
inline int dghMonkCatalepticMult()
    { return 2; }

// Monk prose (capture pp. 33-34): the cataleptic duration must be stated at
// the beginning
inline bool dghMonkCatalepticStated()
    { return true; }

// Monk prose (capture p. 34): the self-heal at 7th level
inline int dghMonkHealLevel()
    { return 7; }

// Monk prose (capture p. 34): heals 2-5 points of damage per day
inline int dghMonkHealMin()
    { return 2; }

// Monk prose (capture p. 34): the heal upper bound
inline int dghMonkHealMax()
    { return 5; }

// Monk prose (capture p. 34): the heal increases one point per level beyond
// 7th
inline int dghMonkHealStep()
    { return 1; }

// Monk prose (capture p. 34): speak with plants at 8th level
inline int dghMonkSpeakPlantsLevel()
    { return 8; }

// Monk prose (capture p. 34): attracts 2-5 followers at 8th level
inline int dghMonkFollowerMin()
    { return 2; }

// Monk prose (capture p. 34): the follower upper bound
inline int dghMonkFollowerMax()
    { return 5; }

// Monk prose (capture p. 34): 1-2 more 1st-level monks per level beyond 8th
inline int dghMonkFollowerExtraMin()
    { return 1; }

// Monk prose (capture p. 34): the extra-follower upper bound
inline int dghMonkFollowerExtraMax()
    { return 2; }

// Monk prose (capture p. 34): followers leave when they reach 7th level
inline int dghMonkFollowerLeaveLevel()
    { return 7; }

// Monk prose (capture p. 34): from 9th level the ki gives half damage even on
// a failed save
inline int dghMonkKiHalfFailLevel()
    { return 9; }

// Monk prose (capture p. 34): charm, hypnosis and suggestion have only a 50
// percent chance at 9th
inline int dghMonkCharmBasePct()
    { return 50; }

// Monk prose (capture p. 34): the charm resistance improves by 5 percent per
// level beyond 9th
inline int dghMonkCharmStepPct()
    { return 5; }

// Monk prose (capture p. 34): telepathic and mind blast defense as if
// Intelligence 18 at 10th
inline int dghMonkMindShieldLevel()
    { return 10; }

// Monk prose (capture p. 34): immune to all poison at 11th level
inline int dghMonkPoisonImmuneLevel()
    { return 11; }

// Monk prose (capture p. 34): immune to geas and quest spells at 12th level
inline int dghMonkGeasImmuneLevel()
    { return 12; }

// Monk prose (capture p. 34): one free martial arts special maneuver at 13th
// level
inline int dghMonkFreeManeuverLevel()
    { return 13; }

// ---- the monk monastery and restriction pins ----

// Monk prose (capture p. 34): no henchmen or hirelings until 6th level
inline int dghMonkHenchLevel()
    { return 6; }

// Monk prose (capture p. 34): up to two henchmen at 6th level
inline int dghMonkHenchBase()
    { return 2; }

// Monk prose (capture p. 34): one additional henchman per level beyond 6th
inline int dghMonkHenchStep()
    { return 1; }

// Monk prose (capture p. 34): no family, clan, birth rank, ancestry,
// birthrights or honor points
inline bool dghMonkNoFamilyHonor()
    { return true; }

// Monk prose (capture p. 34): adopts a name appropriate to the monastery,
// never the family name
inline bool dghMonkMonasteryName()
    { return true; }

// Monk prose (capture p. 34): can never hold land or property of any type
inline bool dghMonkNoProperty()
    { return true; }

// Monk prose (capture p. 34): may retain only two magical weapons
inline int dghMonkMagicWeaponCap()
    { return 2; }

// Monk prose (capture p. 34): and three other magical items
inline int dghMonkMagicItemCap()
    { return 3; }

// Monk prose (capture p. 34): DMG magical items only if rings or usable by
// thieves
inline bool dghMonkDmgItemGate()
    { return true; }

// Monk prose (capture p. 34): never trades magical items for better pieces
inline bool dghMonkNoItemTrading()
    { return true; }

// Monk prose (capture p. 35): beyond 7th the monk must find and defeat the
// monk of that level to keep it
inline bool dghMonkMonasteryDuel()
    { return true; }

// Monk prose (capture p. 35): the duel is strictly between the two monks - no
// one can intervene
inline bool dghMonkDuelNoIntervention()
    { return true; }

// Monk prose (capture p. 35): three monks of 8th level attached to a
// monastery
inline int dghMonkMonasteryEights()
    { return 3; }

// Monk prose (capture p. 35): one of each level beyond 8th attached to a
// monastery
inline int dghMonkMonasteryBeyond()
    { return 1; }

// Monk prose (capture p. 35): the printed duel example - a defeated 8th-level
// monk drops to 98,001 xp, the 7th minimum
inline int dghMonkResetXpExample()
    { return 98001; }

// ---- the Table 20 and Table 21 grids ----

// Table 20 (capture pp. 31-32): seventeen rows, levels 1-17
inline int dghT20RowCount()
    { return 17; }

// the experience column: the upper xp bound of each level, 2,250 at 1st to
// 3,250,000 at 16th, then the 3,250,001 floor of the unbounded 17th (capture
// pp. 31-32).
inline int dghT20XpMax(int b)
    {
        switch (b) {
        case 0:
            return 2250;
        case 1:
            return 4750;
        case 2:
            return 10000;
        case 3:
            return 22500;
        case 4:
            return 47500;
        case 5:
            return 98000;
        case 6:
            return 200000;
        case 7:
            return 350000;
        case 8:
            return 500000;
        case 9:
            return 700000;
        case 10:
            return 950000;
        case 11:
            return 1250000;
        case 12:
            return 1750000;
        case 13:
            return 2250000;
        case 14:
            return 2750000;
        case 15:
            return 3250000;
        case 16:
            return 3250001;
        default:
            return -99;
        }
    }

// the accumulated d4 dice column: the 2d4 start plus 1d4 per level - the
// level plus one, 2 through 18 (the 2018 print settles the header: 4-sided
// dice for accum. hit points) (capture pp. 31-32).
inline int dghT20Dice(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        default:
            return -99;
        }
    }

// the level-title code column: 1 Novice, 2 Initiate, 3 Brother, 4 Disciple, 5
// Immaculate, 6 Master, 7 Superior Master, 8 Master of Dragons, 9 Master of
// the North Wind, 10 Master of the West Wind, 11 Master of the South Wind, 12
// Master of the East Wind, 13 Master of Winter, 14 Master of Autumn, 15
// Master of Summer, 16 Master of Spring, 17 Grand Master of Flowers (capture
// pp. 31-32).
inline int dghT20Title(int b)
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
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        default:
            return -99;
        }
    }

// Table 20 (capture p. 31): the level-title codes - 1st is Novice
inline int dghT20TitleNovice()
    { return 1; }

// Table 20 (capture p. 32): 17th is Grand Master of Flowers
inline int dghT20TitleGrandMaster()
    { return 17; }

// Table 21 (capture p. 33): seventeen rows, levels 1-17
inline int dghT21RowCount()
    { return 17; }

// Table 21 (capture p. 33): the additional-attack code 0 - no additional
// attacks
inline int dghT21AtNone()
    { return 0; }

// Table 21 (capture p. 33): the first attack code 1/4 - extra attacks times
// ten plus the round
inline int dghT21AtFirst()
    { return 14; }

// Table 21 (capture p. 33): the top attack code 3/1 - three extra attacks
// every round
inline int dghT21AtLast()
    { return 31; }

// Table 21 (capture p. 33): the damage code 0 - no additional damage
inline int dghT21DmgNone()
    { return 0; }

// Table 21 (capture p. 33): the first dice damage code plus 1D - dice times
// 100 plus points
inline int dghT21DmgFirstDice()
    { return 100; }

// Table 21 (capture p. 33): the top damage code plus 4D
inline int dghT21DmgCap()
    { return 400; }

// Table 21 (capture p. 33): the surprise code 0 - the normal 1st-level
// surprise
inline int dghT21SurpriseNormal()
    { return 0; }

// the armor class column: 10 at 1st improving to -3 at 17th, the style AC
// used only if better (capture p. 33).
inline int dghT21Ac(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 8;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 6;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return -1;
        case 14:
            return -1;
        case 15:
            return -2;
        case 16:
            return -3;
        default:
            return -99;
        }
    }

// the movement column: 15 feet at 1st improving to 32 at 17th (capture p.
// 33).
inline int dghT21Move(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 16;
        case 2:
            return 17;
        case 3:
            return 18;
        case 4:
            return 19;
        case 5:
            return 20;
        case 6:
            return 21;
        case 7:
            return 22;
        case 8:
            return 23;
        case 9:
            return 24;
        case 10:
            return 25;
        case 11:
            return 26;
        case 12:
            return 27;
        case 13:
            return 28;
        case 14:
            return 29;
        case 15:
            return 30;
        case 16:
            return 32;
        default:
            return -99;
        }
    }

// the additional martial-arts attack column as a code - 0 none, then extra
// attacks times ten plus the round: 1/4 = 14, 1/2 = 12, 1/1 = 11, 3/2 = 32,
// 2/1 = 21, 3/1 = 31 (capture p. 33).
inline int dghT21At(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 14;
        case 4:
            return 14;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 11;
        case 9:
            return 11;
        case 10:
            return 32;
        case 11:
            return 32;
        case 12:
            return 32;
        case 13:
            return 21;
        case 14:
            return 21;
        case 15:
            return 31;
        case 16:
            return 31;
        default:
            return -99;
        }
    }

// the additional martial-arts damage column as a code - dice times 100 plus
// points: 0 none, 1, 2, then 100 (+1D), 101 (+1D+1), 102 (+1D+2), 200 (+2D),
// 201 (+2D+1), 300 (+3D), 301 (+3D+1), 400 (+4D) (capture p. 33).
inline int dghT21Dmg(int b)
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
            return 2;
        case 6:
            return 2;
        case 7:
            return 100;
        case 8:
            return 101;
        case 9:
            return 102;
        case 10:
            return 102;
        case 11:
            return 200;
        case 12:
            return 200;
        case 13:
            return 201;
        case 14:
            return 300;
        case 15:
            return 301;
        case 16:
            return 400;
        default:
            return -99;
        }
    }

// the open locks column: 25 percent at 1st to 99 at 17th (capture p. 33).
inline int dghT21OpenLocks(int b)
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
        default:
            return -99;
        }
    }

// the find and remove traps column: 20 percent at 1st to 99 at 17th (capture
// p. 33).
inline int dghT21Traps(int b)
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
            return 99;
        default:
            return -99;
        }
    }

// the move silently column: 15 percent at 1st to 99 at 13th and beyond
// (capture p. 33).
inline int dghT21Silent(int b)
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
            return 99;
        case 13:
            return 99;
        case 14:
            return 99;
        case 15:
            return 99;
        case 16:
            return 99;
        default:
            return -99;
        }
    }

// the hide in shadows column: 10 percent at 1st to 99 at 15th and beyond
// (capture p. 33).
inline int dghT21Hide(int b)
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
            return 99;
        case 15:
            return 99;
        case 16:
            return 99;
        default:
            return -99;
        }
    }

// the hear noise column: 10 percent at 1st to 55 at 17th (capture p. 33).
inline int dghT21Hear(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 30;
        case 9:
            return 30;
        case 10:
            return 35;
        case 11:
            return 35;
        case 12:
            return 40;
        case 13:
            return 40;
        case 14:
            return 50;
        case 15:
            return 50;
        case 16:
            return 55;
        default:
            return -99;
        }
    }

// the climb walls column: 85 percent at 1st to 99 at 15th and beyond (capture
// p. 33).
inline int dghT21Climb(int b)
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
        default:
            return -99;
        }
    }

// the surprise column as a code: 0 the normal 1st-level chance, then the
// surprised percentages 32 at 2nd down to 2 at 17th (capture p. 33).
inline int dghT21Surprise(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 32;
        case 2:
            return 30;
        case 3:
            return 28;
        case 4:
            return 26;
        case 5:
            return 24;
        case 6:
            return 22;
        case 7:
            return 20;
        case 8:
            return 18;
        case 9:
            return 16;
        case 10:
            return 14;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 8;
        case 14:
            return 6;
        case 15:
            return 4;
        case 16:
            return 2;
        default:
            return -99;
        }
    }

}   // namespace rules
