// =========================================================================================
// Adnd1 - rules/oaanc.h
// MASTER FAMILY CHART AND ANCESTRY, printed capture pp. 64-65 - the OA
// ancestry round
// census 553 -> 554.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T39 bands run contiguously 1 through
// 100 and every honor value sits on its printed row. The T39 result column
// pins as the 0-34 code (blank 0, roll again 1, criminal 2 through tragic
// event 34); the die bands pin as lo and hi bounds. OCR normalization: the
// T39 classic artist reads as the prose classical artist; the T39 roll-again
// rows 6, 10 and 20 read "next higher die or + 10" while row 97 reads "+ 10
// on die roll" (the printed d100 doctrine - both pin as the roll-again code);
// Folk Hero capitalized as printed; the Assigning Ancestral Holdings and
// Birthrights prose (capture pp. 67-69) is deliberately left for the next
// rounds
//
// the gap census after this round: 71 closed, 164 open - the Master Family
// Chart, Ancestry prose and Table 39 boxes flip (census 553 -> 554); NEXT -
// R632: the Assigning Ancestral Holdings prose, capture pp. 67-68, the
// head-of-family rule and the NPC-only holdings, prefix dgs (verify free),
// audit "R632 OA holdings audit", include after rules/oaanc.h
//
namespace rules {

// ---- the master family chart pins ----

// Master chart prose (capture pp. 64-65): the chart records names, birth
// ranks, honor, alliances and relationships for all families
inline bool dgrMasterChartPurpose()
    { return true; }

// Master chart prose (capture pp. 64-65): the emperor or supreme ruler holds
// the center space
inline bool dgrMasterChartCenter()
    { return true; }

// Master chart prose (capture pp. 64-65): the high birth rank families sit
// closer to the center
inline bool dgrMasterChartRankDistance()
    { return true; }

// Master chart prose (capture pp. 64-65): dashed for marriage, solid for
// blood, dotted for allies, arrows for enemies
inline bool dgrMasterChartLineCodes()
    { return true; }

// ---- the ancestry doctrine pins ----

// Table 39 (capture p. 65): forty-six ancestry rows
inline int dgrT39RowCount()
    { return 46; }

// Ancestry prose (capture p. 65): the ancestry covers holdings, debts,
// alliances, feuds and notable deeds
inline bool dgrAncestryBeyondAncestors()
    { return true; }

// Ancestry prose (capture p. 65): the player and the DM supply the names and
// details together
inline bool dgrAncestryCooperativeDetail()
    { return true; }

// Ancestry prose (capture p. 65): the Table 39 honor adds to the Character
// Birth honor for the family base honor
inline bool dgrHonorAddsToBirth()
    { return true; }

// Ancestral alliance prose (capture p. 65): the +20 percent reaction modifier
// between allied families
inline int dgrAllianceBonusPct()
    { return 20; }

// Ancestral feud prose (capture p. 65): the -40 percent reaction modifier
// between feud families
inline int dgrFeudModPct()
    { return -40; }

// Advantageous marriage prose (capture p. 65): the daughter married 1-3
// social levels higher
inline int dgrAdvMarriageLevels()
    { return 3; }

// Land prose (capture p. 65): the property income lower bound, 10 ch'ien
inline int dgrLandIncomeMin()
    { return 10; }

// Land prose (capture p. 65): the property income upper bound, 2,000 ch'ien
inline int dgrLandIncomeMax()
    { return 2000; }

// Estate prose (capture p. 65): the estate income lower bound, 100 ch'ien
inline int dgrEstateIncomeMin()
    { return 100; }

// Estate prose (capture p. 65): the estate income upper bound, 1,000 ch'ien
inline int dgrEstateIncomeMax()
    { return 1000; }

// Merchant fleet prose (capture p. 65): the fleet lower bound, 2 ships
inline int dgrFleetShipsMin()
    { return 2; }

// Merchant fleet prose (capture p. 65): the fleet upper bound, 5 ships
inline int dgrFleetShipsMax()
    { return 5; }

// Merchant fleet prose (capture p. 65): the fleet income lower bound, 100
// ch'ien
inline int dgrFleetIncomeMin()
    { return 100; }

// Merchant fleet prose (capture p. 65): the fleet income upper bound, 1,000
// ch'ien
inline int dgrFleetIncomeMax()
    { return 1000; }

// Folk hero prose (capture p. 65): the +10 percent reaction bonus with NPC
// commoners
inline int dgrFolkHeroBonusPct()
    { return 10; }

// Notorious money lender prose (capture p. 65): the character gains an extra
// roll on Table 40
inline bool dgrMoneylenderExtraRoll()
    { return true; }

// Hereditary title prose (capture p. 65): the title passes to the son when
// the head dies
inline bool dgrHereditaryTitlePassesToSon()
    { return true; }

// Secret society prose (capture p. 65): the connection provides the player
// character contacts inside the society
inline bool dgrSecretSocietyContacts()
    { return true; }

// Tragic event prose (capture p. 65): the nobility of the ancestor's
// suffering increases the family honor
inline bool dgrTragicEventAddsHonor()
    { return true; }

// Roll again prose (capture p. 65): reroll on the next larger die, or add 10
// when already rolling d100
inline bool dgrRollAgainNextDie()
    { return true; }

// ---- the Table 39 grid ----

// the die-band lower bound column (capture p. 65).
inline int dgrT39DieLo(int b)
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
            return 9;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 16;
        case 10:
            return 20;
        case 11:
            return 21;
        case 12:
            return 25;
        case 13:
            return 27;
        case 14:
            return 32;
        case 15:
            return 36;
        case 16:
            return 39;
        case 17:
            return 40;
        case 18:
            return 43;
        case 19:
            return 45;
        case 20:
            return 46;
        case 21:
            return 47;
        case 22:
            return 50;
        case 23:
            return 51;
        case 24:
            return 55;
        case 25:
            return 57;
        case 26:
            return 58;
        case 27:
            return 59;
        case 28:
            return 60;
        case 29:
            return 64;
        case 30:
            return 70;
        case 31:
            return 71;
        case 32:
            return 72;
        case 33:
            return 73;
        case 34:
            return 78;
        case 35:
            return 79;
        case 36:
            return 80;
        case 37:
            return 81;
        case 38:
            return 86;
        case 39:
            return 88;
        case 40:
            return 92;
        case 41:
            return 94;
        case 42:
            return 97;
        case 43:
            return 98;
        case 44:
            return 99;
        case 45:
            return 100;
        default:
            return -99;
        }
    }

// the die-band upper bound column - the bands run contiguously 1 through 100
// (capture p. 65).
inline int dgrT39DieHi(int b)
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
            return 8;
        case 5:
            return 9;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 15;
        case 9:
            return 19;
        case 10:
            return 20;
        case 11:
            return 24;
        case 12:
            return 26;
        case 13:
            return 31;
        case 14:
            return 35;
        case 15:
            return 38;
        case 16:
            return 39;
        case 17:
            return 42;
        case 18:
            return 44;
        case 19:
            return 45;
        case 20:
            return 46;
        case 21:
            return 49;
        case 22:
            return 50;
        case 23:
            return 54;
        case 24:
            return 56;
        case 25:
            return 57;
        case 26:
            return 58;
        case 27:
            return 59;
        case 28:
            return 63;
        case 29:
            return 69;
        case 30:
            return 70;
        case 31:
            return 71;
        case 32:
            return 72;
        case 33:
            return 77;
        case 34:
            return 78;
        case 35:
            return 79;
        case 36:
            return 80;
        case 37:
            return 85;
        case 38:
            return 87;
        case 39:
            return 91;
        case 40:
            return 93;
        case 41:
            return 96;
        case 42:
            return 97;
        case 43:
            return 98;
        case 44:
            return 99;
        case 45:
            return 100;
        default:
            return -99;
        }
    }

// the honor column: the family honor adjustment, -20 to +15 (capture p. 65).
inline int dgrT39Honor(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -15;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return -10;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 6;
        case 17:
            return 8;
        case 18:
            return 10;
        case 19:
            return 7;
        case 20:
            return -10;
        case 21:
            return 0;
        case 22:
            return -10;
        case 23:
            return 6;
        case 24:
            return 7;
        case 25:
            return 9;
        case 26:
            return 1;
        case 27:
            return 8;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 10;
        case 31:
            return -20;
        case 32:
            return 15;
        case 33:
            return 0;
        case 34:
            return 12;
        case 35:
            return -5;
        case 36:
            return -7;
        case 37:
            return 0;
        case 38:
            return 4;
        case 39:
            return 2;
        case 40:
            return -5;
        case 41:
            return 7;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 3;
        case 45:
            return 0;
        default:
            return -99;
        }
    }

// the ancestry result column, pinned as the 0-34 code: blank 0, roll again 1,
// criminal 2 through tragic event 34 (capture p. 65).
inline int dgrT39Result(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 8;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 9;
        case 13:
            return 10;
        case 14:
            return 11;
        case 15:
            return 0;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 14;
        case 19:
            return 15;
        case 20:
            return 16;
        case 21:
            return 0;
        case 22:
            return 17;
        case 23:
            return 18;
        case 24:
            return 19;
        case 25:
            return 20;
        case 26:
            return 21;
        case 27:
            return 22;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 23;
        case 31:
            return 24;
        case 32:
            return 25;
        case 33:
            return 0;
        case 34:
            return 26;
        case 35:
            return 27;
        case 36:
            return 28;
        case 37:
            return 0;
        case 38:
            return 29;
        case 39:
            return 30;
        case 40:
            return 31;
        case 41:
            return 32;
        case 42:
            return 1;
        case 43:
            return 33;
        case 44:
            return 34;
        case 45:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
