// =========================================================================================
// Adnd1 - rules/oahonor.h
// THE HONOR OPENER AND TABLE 41, printed capture pp. 69-70 - the OA honor
// round
// census 556 -> 557.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T41 rows are five fixed base honors
// plus the single die-roll row (the yakuza 1d20 + 20 read pins as the 21-40
// bounds; the class row order pins as the 0-6 code: shukenja, sohei, kensai,
// bushi, hengeyokai, wu jen, yakuza). The T41 base-honor column pins as the
// lo and hi bounds. OCR normalization: none required for this range beyond
// the yakuza die read - the honor opener prose carries the printed em dashes.
// The Altering Family Honor and Effects of Honor prose and Table 42 (capture
// pp. 70-72) are deliberately left for the next rounds
//
// the gap census after this round: 76 closed, 159 open - the Gaining and
// Losing Honor prose and Table 41 boxes flip (census 556 -> 557); NEXT -
// R635: the Altering Family Honor prose and the Effects of Honor prose with
// Table 42, capture pp. 70-72, the family ledger and the reaction doctrine,
// prefix dgv (verify free), audit "R635 OA effects of honor audit", include
// after rules/oahonor.h
//
namespace rules {

// ---- the honor doctrine pins ----

// Honor opener prose (capture pp. 69-70): honor reflects the character and
// the character of his family - the family affects the character and vice
// versa
inline bool dguHonorReflectsFamily()
    { return true; }

// Honor opener prose (capture pp. 69-70): with honor comes respect, power,
// influence and position; without it, disrespect, humiliation and insults
inline bool dguHonorBringsRespect()
    { return true; }

// Honor opener prose (capture pp. 69-70): honor is easier to lose than to
// gain
inline bool dguHonorEasierToLose()
    { return true; }

// Honor opener prose (capture pp. 69-70): breaking faith, treachery,
// cowardice and unavenged insults cause a loss of honor
inline bool dguDishonorDeeds()
    { return true; }

// Honor opener prose (capture pp. 69-70): valiant deeds, self-sacrifice,
// mastery of skills and keeping faith earn honor
inline bool dguHonorDeeds()
    { return true; }

// Honor opener prose (capture pp. 69-70): gaining honor brings better
// encounter reactions, gifts and better replacement characters
inline bool dguHonorImprovesReactions()
    { return true; }

// Honor opener prose (capture pp. 69-70): oriental honor is not a judgment of
// good and evil - a cruel villain can hold high honor and a heroic samurai
// low honor
inline bool dguHonorNotAlignment()
    { return true; }

// Honor opener prose (capture pp. 69-70): honor measures the deeds of the
// character and the family clan - obedience, loyalty, talent and success,
// regardless of alignment
inline bool dguHonorDeedsBoth()
    { return true; }

// Honor points prose (capture pp. 69-70): players record honor points - the
// DM gives them at the end of an adventure or major encounter and takes them
// away for dishonorable actions
inline bool dguHonorPointsTracked()
    { return true; }

// Honor points prose (capture pp. 69-70): characters do not earn honor points
// for every adventure - they must do something special
inline bool dguNotEveryAdventure()
    { return true; }

// ---- the starting honor pins ----

// Table 41 (capture p. 70): seven initial-honor rows
inline int dguT41RowCount()
    { return 7; }

// Starting honor prose (capture p. 70): family-clan characters start with the
// base honor determined by birth rank, adjusted by the Table 39 results - the
// family honor
inline bool dguClanStartByBirthRank()
    { return true; }

// Starting honor prose (capture p. 70): a negative family honor is raised to
// 0
inline bool dguFamilyHonorFloorZero()
    { return true; }

// Starting honor prose (capture p. 70): the starting honor is the family
// honor plus the birthright bonuses plus the character's lowest ability score
inline bool dguClanStartAddsBirthrights()
    { return true; }

// Starting honor prose (capture p. 70): characters without family clans take
// the Table 41 base honor by class or race, plus the lowest ability score
inline bool dguNoClanT41Base()
    { return true; }

// ---- the gaining and losing pins ----

// Gaining and losing prose (capture p. 70): no character can have more than
// 100 points of honor
inline int dguHonorMax()
    { return 100; }

// Gaining and losing prose (capture p. 70): classes gain and lose honor at
// different rates - a samurai's honor fluctuates more than a wu jen's or
// shukenja's
inline bool dguClassSensitivity()
    { return true; }

// Gaining and losing prose (capture p. 70): honor points are always awarded
// by the DM, normally at the end of an adventure; the DM's judgment is final;
// the typical awards are listed on Table 42
inline bool dguDmAwardsHonor()
    { return true; }

// Gaining and losing prose (capture p. 70): the list cannot cover every
// situation - the DM relies on his judgment using the table as a guideline
inline bool dguDmJudgment()
    { return true; }

// ---- the Table 41 grid ----

// the initial-honor lower bound column, by class row - 0 shukenja, 1 sohei, 2
// kensai, 3 bushi, 4 hengeyokai, 5 wu jen, 6 yakuza (capture p. 70).
inline int dguT41BaseLo(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 25;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 21;
        default:
            return -99;
        }
    }

// the initial-honor upper bound column - the fixed rows pin lo equal to hi;
// the yakuza row reads 1d20 + 20, pinning as 21 through 40 (capture p. 70).
inline int dguT41BaseHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 25;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 40;
        default:
            return -99;
        }
    }

}   // namespace rules
