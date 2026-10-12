// ===========================================================================
// Adnd1 - rules/uafollowers.h
// The UA CAVALIER FOLLOWERS AND
// HENCHMEN (pp. 74-75) pins, R372:
// the cavalier follower tables and
// the henchman rules.
// The men-at-arms dice ladder (all
// d4, non-cumulative, no gain if
// the roll is not higher than the
// current count); the four
// equipment percentile rows (both
// outfits each, the medium
// warhorses at 91-00); the leader
// rules (a 5th-level fighter per 20
// troops, a 6th per 60 with a
// 3rd-level lieutenant, no
// replacement if slain); the
// neutral-cause and evil-bandit
// reads with the 1 and 5 percent
// per level monster chances; the
// +3/+1 henchman bonus and the
// alignment type table; the
// retainer ladder - the Armiger /
// Scutifer start at 4th (Knight
// Errant), the Esquire at 6th (the
// prose's "Knight (6th level)"
// conflicts with the Cavaliers
// Table I grid's Knight at 5th -
// flagged), the Horseman herald
// and Lancer guard at 7th, the
// extra mounted man-at-arms at
// 8th, the Chevalier travel
// freedom at 9th; the paladin
// retainers. The seams ride the
// R368 title cells and the R371
// armor costs (checked in the
// regtest audit, not here).
namespace rules {

// ---- the men-at-arms dice ----
// The ladder starts at 4th (Knight
// Errant) and tops at 10th.
inline int uafolFollowersStartLevel()
    { return 4; }

inline int uafolFollowersTopLevel()
    { return 10; }

// The dice counts: 1d4 at 4th, 2d4
// at 5th, 3d4 at 6th, 6d4 at 7th,
// 12d4 at 8th, 24d4 at 9th and
// 48d4 at 10th. All sides are 4.
inline int uafolDiceCount(int level) {
    if (level < 4) return 0;
    if (level > 10) return 0;
    static const int k[7] = {
        1, 2, 3, 6, 12, 24, 48
    };
    return k[level - 4];
}

inline int uafolDiceSides(int level) {
    if (level < 4 || level > 10)
        return 0;
    return 4;
}

// The min is the count; the max is
// the count times four (the d4
// invariant).
inline int uafolFollowersMin(int level)
    { return uafolDiceCount(level); }

inline int uafolFollowersMax(int level)
    { return 4 * uafolDiceCount(level); }

// The ranges are gained on a
// per-level basis - not
// cumulative.
inline bool uafolDiceCumulative()
    { return false; }

// If the new roll is equal to or
// lower than the current number,
// no new followers are gained.
inline bool uafolNoGainIfRollNotHigher()
    { return true; }

// ---- the equipment rows ----
// Four percentile rows, each with
// two outfits; the 91-00 cavalry
// rides medium warhorses.
inline int uafolEquipRowCount()
    { return 4; }

inline int uafolEquipRowLo(int row) {
    if (row < 0 || row > 3) return 0;
    static const int k[4] = {
        1, 51, 76, 91
    };
    return k[row];
}

inline int uafolEquipRowHi(int row) {
    if (row < 0 || row > 3) return 0;
    static const int k[4] = {
        50, 75, 90, 100
    };
    return k[row];
}

// Rows 01-50 and 91-00 are cavalry;
// rows 51-75 and 76-90 are foot.
inline bool uafolEquipRowIsCavalry(int row)
    { return row == 0 || row == 3; }

// Only the 91-00 cavalry rides
// medium warhorses.
inline bool uafolEquipRowMediumWarhorse(int row)
    { return row == 3; }

// 01-50: light cavalry in ring mail
// and shield, 3 javelins, long
// sword and hand axe; or heavy
// infantry in scale mail, pole arm
// of choice and club.
inline int uafolRowOneJavelinCount()
    { return 3; }

inline bool uafolRowOneLightCavRingMailShield()
    { return true; }

inline bool uafolRowOneHeavyInfScalePoleArmClub()
    { return true; }

// 51-75: heavy infantry in splint
// mail with morning star and hand
// axe; or heavy infantry in
// leather armor with pike and
// short sword.
inline bool uafolRowTwoSplintMorningStarHandAxe()
    { return true; }

inline bool uafolRowTwoLeatherPikeShortSword()
    { return true; }

// 76-90: crossbowmen in chain mail
// with heavy crossbow and short
// sword; or crossbowmen in chain
// mail with light crossbow and
// military fork.
inline bool uafolRowThreeHeavyCrossbowShortSword()
    { return true; }

inline bool uafolRowThreeLightCrossbowMilitaryFork()
    { return true; }

// 91-00: cavalry in banded mail and
// shield with lance and horseman's
// mace; or cavalry in studded
// leather with long sword and
// horseman's flail.
inline bool uafolRowFourBandedShieldLanceMace()
    { return true; }

inline bool uafolRowFourStuddedLeatherLongSwordFlail()
    { return true; }

// ---- the leaders ----
// For every 20 troops a 5th-level
// fighter follower/leader; for
// every 60 a 6th-level fighter
// leader plus a 3rd-level fighter
// lieutenant. Leaders slain are
// not replaced.
inline int uafolLeaderFighterLevel()
    { return 5; }

inline int uafolLeaderTroopDenominator()
    { return 20; }

inline int uafolSeniorLeaderLevel()
    { return 6; }

inline int uafolSeniorLeaderTroops()
    { return 60; }

inline int uafolLieutenantLevel()
    { return 3; }

inline bool uafolLeadersNotReplacedIfSlain()
    { return true; }

// ---- the neutral and evil reads ----
// Neutral cavaliers attract
// followers only for a specific,
// neutral cause; the followers
// leave if the cavalier goes
// elsewhere.
inline bool uafolNeutralSpecificCause()
    { return true; }

inline bool uafolNeutralLeaveIfElsewhere()
    { return true; }

// Evil cavaliers attract only
// bandits and brigands (orcs or
// hobgoblins in the right area).
inline bool uafolEvilBanditsBrigands()
    { return true; }

// The 1% per level chance an
// encountered intelligent monster
// of fewer hit dice and similar
// alignment becomes a follower;
// the 5% per level chance of
// cooperation.
inline int uafolEvilMonsterFollowerPctPerLevel()
    { return 1; }

inline int uafolEvilMonsterCooperatePctPerLevel()
    { return 5; }

// ---- the henchmen ----
// The Charisma Table count with a
// +3 bonus for good cavaliers, +1
// for neutral or evil.
inline int uafolHenchmanBonusGood()
    { return 3; }

inline int uafolHenchmanBonusOther()
    { return 1; }

// The alignment type table cells
// that differ from the plain
// lists: good accepts paladins,
// neutral accepts thieves, evil
// swaps in assassins.
inline bool uafolHenchmanGoodPaladins()
    { return true; }

inline bool uafolHenchmanNeutralThieves()
    { return true; }

inline bool uafolHenchmanEvilAssassins()
    { return true; }

// ---- the retainers ----
// At 4th (Knight Errant) the good
// cavalier must acquire at least
// one retainer - Armigers
// (level 1) or Scutifers
// (level 2) or both.
inline int uafolRetainerStartLevel()
    { return 4; }

inline int uafolRetainerArmigerLevel()
    { return 1; }

inline int uafolRetainerScutiferLevel()
    { return 2; }

inline int uafolEsquireLevel()
    { return 3; }

// The prose: "Upon becoming a
// Knight (6th level), an Esquire
// (level 3) must be added" - but
// the Cavaliers Table I grid
// prints Knight at 5th, not 6th;
// the conflict is flagged here.
inline bool uafolRetainerKnightProseConflict()
    { return true; }

// At 7th a Horseman herald and a
// Lancer guard are added; at 8th
// (Banneret) an extra mounted
// man-at-arms; at 9th (Chevalier)
// the cavalier may travel with or
// without retainers.
inline int uafolHeraldGuardLevel()
    { return 7; }

inline int uafolExtraManAtArmsLevel()
    { return 8; }

inline int uafolChevalierTravelFreedomLevel()
    { return 9; }

// Retainers serve for care, upkeep
// and training; gifts always
// accepted.
inline bool uafolRetainersServeForCareAndUpkeep()
    { return true; }

// ---- the paladin retainers ----
inline bool uafolPaladinNoFollowers()
    { return true; }

inline bool uafolPaladinRetainersMustBeCavaliers()
    { return true; }

}   // namespace rules

