// =========================================================================================
// Adnd1 - rules/oabr.h
// BIRTHRIGHTS AND TABLE 40, printed capture pp. 68-69 - the OA birthrights
// round
// census 555 -> 556.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T40 bands run contiguously 1 through
// 100 and every honor value sits on its printed row. The T40 result column
// pins as the 0-11 code (blank 0, roll again 1, property share 2, horse 3,
// the 1-6 cash strings 4, armor of quality 5, the 1-8 cash strings 6, weapon
// of quality 7, the 1-4 horses 8, the 2-12 cash strings 9, the magical weapon
// 10, the d100 roll again 11); the die bands pin as the lo and hi bounds; the
// honor column is personal honor. OCR normalization: the print capitalization
// varies (Property Share at 6 and 17-18, Property share at 8, 41-45 and
// 56-60, Armor of quality and Weapon of quality at their rows) - all pin as
// the same codes; rows 4 and 7 read "next higher die or + 10" while row 100
// reads "with + 10 on die roll" (the printed d100 doctrine - both pin as the
// roll-again codes 1 and 11). The Chapter 4 Honor prose (capture pp. 69-73)
// is deliberately left for the next rounds
//
// the gap census after this round: 74 closed, 161 open - the Birthrights
// prose and Table 40 boxes flip (census 555 -> 556); NEXT - R634: the Honor
// chapter opener, the Gaining and Losing Honor prose and Table 41 (Initial
// Honor), capture pp. 69-70, prefix dgu (verify free), audit "R634 OA honor
// audit", include after rules/oabr.h
//
namespace rules {

// ---- the birthright doctrine pins ----

// Table 40 (capture pp. 68-69): twenty-six birthrights rows
inline int dgtT40RowCount()
    { return 26; }

// Birthrights prose (capture p. 68): the first son subtracts one from the
// rolls allowed
inline int dgtFirstSonRollPenalty()
    { return 1; }

// Birthrights prose (capture p. 68): a birthright is something the character
// begins the game with, by virtue of his family clan - an heirloom or a share
// of the family holdings
inline bool dgtBirthrightClanVirtue()
    { return true; }

// Birthrights prose (capture p. 68): it may be nothing, owing to poverty,
// birth order or chance
inline bool dgtBirthrightMayBeNothing()
    { return true; }

// Birthrights prose (capture p. 68): once determined, the birthright is the
// property of both the player character and the family clan
inline bool dgtSharedClanOwnership()
    { return true; }

// Birthrights prose (capture p. 68): if the player character dies, the
// birthright returns to the possession of the family clan
inline bool dgtDeathReturnsToClan()
    { return true; }

// Birthrights prose (capture p. 68): if the character loses a birthright, he
// and his family lose honor
inline bool dgtLostBirthrightLosesHonor()
    { return true; }

// Birthrights prose (capture p. 68): the die type and the number of rolls
// were determined by Table 38: Character Birth
inline bool dgtRollsDeterminedByT38()
    { return true; }

// Birthrights prose (capture p. 68): the number of rolls allowed is modified
// by subtracting the character's birth rank
inline bool dgtBirthRankReducesRolls()
    { return true; }

// T40 honor prose (capture p. 68): the honor gained is personal, not family -
// it is added to the character's honor at the start of the game and does not
// increase the family base honor
inline bool dgtHonorIsPersonal()
    { return true; }

// ---- the effects pins ----

// Property share prose (capture p. 69): the share lower bound, 10 percent of
// the yearly income
inline int dgtPropShareMinPct()
    { return 10; }

// Property share prose (capture p. 69): the share upper bound, 30 percent of
// the yearly income
inline int dgtPropShareMaxPct()
    { return 30; }

// Cash strings prose (capture p. 69): each string holds 100 coins
inline int dgtCashPerString()
    { return 100; }

// Magical weapon prose (capture p. 69): never more magical than +2
inline int dgtMagicWeaponMaxPlus()
    { return 2; }

// Property share prose (capture p. 69): the shares come only from the lands
// held by the father, the grandfather or the head of the family
inline bool dgtPropShareAncestorLandsOnly()
    { return true; }

// Property share prose (capture p. 69): never more than a 30 percent share in
// a single property
inline bool dgtPropShareSingleCap()
    { return true; }

// Property share prose (capture p. 69): if the family holds no productive
// property, the roll is treated as no result
inline bool dgtPropShareNoPropertyRead()
    { return true; }

// Horse prose (capture p. 69): one or more horses of any type desired,
// without a saddle or other tack
inline bool dgtHorseAnyTypeNoTack()
    { return true; }

// Cash strings prose (capture p. 69): the DM determines the type of coin in
// each string
inline bool dgtCashStringDmCoinType()
    { return true; }

// Heirloom prose (capture p. 69): the DM randomly determines the armor type;
// the player chooses the weapon type
inline bool dgtQualityArmorDmWeaponPlayer()
    { return true; }

// Heirloom prose (capture p. 69): the items cannot be given away or sold,
// since they belong in part to the family, and are expected to pass on
// through the family
inline bool dgtQualityItemNotTransferable()
    { return true; }

// Magical weapon prose (capture p. 69): either a sword or a miscellaneous
// weapon, complete with history
inline bool dgtMagicWeaponSwordOrMisc()
    { return true; }

// Magical weapon prose (capture p. 69): the weapon has no special abilities
inline bool dgtMagicWeaponNoSpecialAbilities()
    { return true; }

// Magical weapon prose (capture p. 69): the character can never give away or
// sell the item
inline bool dgtMagicWeaponNeverSold()
    { return true; }

// Magical weapon prose (capture p. 69): losing the item and still living
// means a great loss of honor
inline bool dgtMagicWeaponLostHonorLoss()
    { return true; }

// Roll again prose (capture p. 69): the next larger die (1d4 becomes 1d6, 1d6
// becomes 1d8, etc.), or add 10 when already rolling d100
inline bool dgtRollAgainNextLargerDie()
    { return true; }

// ---- the Table 40 grid ----

// the die-band lower bound column (capture pp. 68-69).
inline int dgtT40DieLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 17;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 31;
        case 12:
            return 34;
        case 13:
            return 41;
        case 14:
            return 46;
        case 15:
            return 51;
        case 16:
            return 56;
        case 17:
            return 61;
        case 18:
            return 64;
        case 19:
            return 71;
        case 20:
            return 76;
        case 21:
            return 81;
        case 22:
            return 91;
        case 23:
            return 96;
        case 24:
            return 99;
        case 25:
            return 100;
        default:
            return -99;
        }
    }

// the die-band upper bound column - the bands run contiguously 1 through 100
// (capture pp. 68-69).
inline int dgtT40DieHi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 16;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 30;
        case 11:
            return 33;
        case 12:
            return 40;
        case 13:
            return 45;
        case 14:
            return 50;
        case 15:
            return 55;
        case 16:
            return 60;
        case 17:
            return 63;
        case 18:
            return 70;
        case 19:
            return 75;
        case 20:
            return 80;
        case 21:
            return 90;
        case 22:
            return 95;
        case 23:
            return 98;
        case 24:
            return 99;
        case 25:
            return 100;
        default:
            return -99;
        }
    }

// the honor column: the personal honor gained, 0 to +4 (capture pp. 68-69).
inline int dgtT40Honor(int b)
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
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 0;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 2;
        case 24:
            return 4;
        case 25:
            return 0;
        default:
            return -99;
        }
    }

// the birthright result column, pinned as the 0-11 code: blank 0, roll again
// 1, property share 2, horse 3, the 1-6 cash strings 4, armor of quality 5,
// the 1-8 cash strings 6, weapon of quality 7, the 1-4 horses 8, the 2-12
// cash strings 9, the magical weapon 10, the d100 roll again 11 (capture pp.
// 68-69).
inline int dgtT40Result(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 0;
        case 15:
            return 6;
        case 16:
            return 2;
        case 17:
            return 7;
        case 18:
            return 0;
        case 19:
            return 5;
        case 20:
            return 8;
        case 21:
            return 0;
        case 22:
            return 9;
        case 23:
            return 7;
        case 24:
            return 10;
        case 25:
            return 11;
        default:
            return -99;
        }
    }

}   // namespace rules
