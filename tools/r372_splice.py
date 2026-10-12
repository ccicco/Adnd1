
# R372: the UA cavalier followers
# and henchmen pin round (pp. 74-75):
# the cavalier follower tables and
# the henchman rules - the men-at-
# arms dice ladder (all d4, 1d4 at
# 4th through 48d4 at 10th, non-
# cumulative, no gain if the roll is
# not higher), the four equipment
# percentile rows (both outfits each,
# the medium warhorses at 91-00),
# the leader rules (the 5th-level
# fighter per 20, the 6th per 60
# with the 3rd-level lieutenant, no
# replacement if slain), the
# neutral-cause and evil-bandit reads
# with the 1 and 5 percent per level
# monster chances, the +3/+1 henchman
# bonus and the alignment type table,
# the retainer ladder (the prose's
# Knight at 6th flagged against the
# Cavaliers Table I grid's Knight at
# 5th), the paladin rules; the R368
# seam cross-checks the title and
# rank cells, the R371 seam the armor
# costs; two items flip CLOSED; the
# census 298 -> 299.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)



# ---- (a) the seed: the R371 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R371 landed 2026-10-12: commit',
    '  cfa4ec9, census 298, the UA',
    '  expanded armor pin round',
    '  (rules/uaarmor.h): the armor and',
    '  encumbrance table rows (the',
    '  banded, bronze plate, field',
    '  plate, full plate, ring, scale,',
    '  splint and studded leather rows',
    '  with the costs, weights,',
    '  movements, bulk flags and the',
    '  shield rows) and the four',
    '  descriptions (the bronze plate',
    '  AC 4 with the rear-attack',
    '  exposure, the elfin chain',
    '  thief-wearable read, the field',
    '  plate absorption with the cap',
    '  and repair costs, the full',
    '  plate); the R191 seam the plate',
    '  AC ladder, the R334 seam the',
    '  thief elfin rows, the R370 seam',
    '  the barding weight read; two',
    '  items CLOSED; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R371 landed 2026-10-12' in s:
    already.append('seed: the R371 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R371 record')
s = rd(SD)
assert s.count(
    'R371 landed 2026-10-12'
) == 1, 'a entry'
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a R370 kept'
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a R369 kept'
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a R368 kept'
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a R367 kept'
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a R364 kept'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'



# ---- (b) NEW rules/uafollowers.h ----
P = 'rules/uafollowers.h'
if os.path.exists(P) and 'R372' in rd(P):
    already.append('uafollowers.h: the pins')
else:
    HDR = r"""// ===========================================================================
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
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uafollowers.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 49, 'b inline count'
assert s.count('R372') == 1, 'b round tag'
assert s.count(
    'uafolDiceCount'
    ) >= 1, 'b fn'
assert 'uacaq' not in s, 'b no uacaq ref'
assert 'uaila' not in s, 'b no uaila ref'
assert 'uabk' not in s, 'b no uabk ref'
assert 'uailc' not in s, 'b no uailc ref'
assert 'uasoc' not in s, 'b no uasoc ref'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uasm1' not in s, 'b no uasm1 ref'
assert 'armorRating' not in s, 'b no armorRating ref'
assert 'thiefArmor' not in s, 'b no thiefArmor ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the two closes ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **The cavalier follower tables**' in s:
    already.append('gap: the followers close')
else:
    OLD = NL.join([
        '- [ ] **The cavalier follower tables**',
        '      (p. 74) - the men-at-arms dice per',
        '      level (1-4 at 4th through 48-192',
        '      at 10th, non-cumulative, no gain',
        '      if the roll is not higher); the',
        '      equipment percentile rows; the',
        '      leader rules (a 5th-level fighter',
        '      per 20 troops, a 6th per 60, the',
        '      3rd-level lieutenant); the',
        '      neutral and evil follower rules;',
        '      the 1 percent per level monster',
        '      follower.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [x] **The cavalier follower tables**',
        '      (p. 74) - the men-at-arms dice per',
        '      level (1-4 at 4th through 48-192',
        '      at 10th, non-cumulative, no gain',
        '      if the roll is not higher); the',
        '      equipment percentile rows; the',
        '      leader rules (a 5th-level fighter',
        '      per 20 troops, a 6th per 60, the',
        '      3rd-level lieutenant); the',
        '      neutral and evil follower rules;',
        '      the 1 percent per level monster',
        '      follower.',
        '      - CLOSED R372: the pin round',
        '        (rules/uafollowers.h) - the',
        '        dice ladder (all d4, the',
        '        min-count max-times-four',
        '        invariant), the four',
        '        equipment percentile rows',
        '        with both outfits each, the',
        '        leader and lieutenant',
        '        rules, the neutral-cause',
        '        and evil-bandit reads, the',
        '        1 and 5 percent monster',
        '        chances; the R371 seam',
        '        cross-checks the armor',
        '        costs; CLOSED.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the followers close')
if '- [x] **The henchman rules**' in s:
    already.append('gap: the henchman close')
else:
    OLD = NL.join([
        '- [ ] **The henchman rules** (p. 75) -',
        '      the charisma +3 (good) or +1',
        '      (else) bonus; the alignment-based',
        '      henchman-type table; the retainer',
        '      ladder (Armigers/Scutifers at 4th,',
        '      the Esquire at 6th, the Horseman',
        '      herald and Lancer guard at 7th,',
        '      the extra man-at-arms at 8th); the',
        '      paladin retainer rules.'
    ])
    assert s.count(OLD) == 1, 'c2 old'
    NEW = NL.join([
        '- [ ] **The henchman rules** (p. 75) -',
        '      the charisma +3 (good) or +1',
        '      (else) bonus; the alignment-based',
        '      henchman-type table; the retainer',
        '      ladder (Armigers/Scutifers at 4th,',
        '      the Esquire at 6th, the Horseman',
        '      herald and Lancer guard at 7th,',
        '      the extra man-at-arms at 8th); the',
        '      paladin retainer rules.',
        '      - CLOSED R372: the pin round',
        '        (rules/uafollowers.h) - the',
        '        +3/+1 henchman bonus, the',
        '        alignment type table (the',
        '        paladin, thief and assassin',
        '        cells), the retainer ladder',
        '        (the prose Knight at 6th',
        '        flagged against the R368',
        "        grid's Knight at 5th), the",
        '        care-and-upkeep service, the',
        '        paladin cavalier-only',
        '        retainers; the R368 seam',
        '        cross-checks the title',
        '        cells; CLOSED.'
    ])
    NEW = NEW.replace(
        '- [ ] **The henchman rules**',
        '- [x] **The henchman rules**', 1)
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the henchman close')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c1 flip'
assert s.count(
    '- [x] **The henchman rules**'
) == 1, 'c2 flip'
assert s.count(
    '(rules/uafollowers.h) - the'
) == 2, 'c notes'
assert s.count(
    '- [ ] **The comeliness creation note**'
) == 1, 'c comeliness kept open'
assert s.count(
    '- [ ] **The new weapon descriptions**'
) == 1, 'c weapons kept open'
assert s.count(
    '- [x] **The expanded armor table**'
) == 1, 'c r371 table kept closed'
assert s.count(
    '- [x] **Warhorses and barding**'
) == 1, 'c r370 kept closed'
assert s.count(
    '- [x] **Cavaliers Table I**'
) == 1, 'c r368 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 4, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R372 UA cavalier followers pin audit' in s:
    already.append('regtest.cpp: the R372 audit')
else:
    INC_ANCH = ('#include "rules/uaarmor.h"  // '
        'R371: the UA expanded armor')
    INC_NEW = NL.join([
        '#include "rules/uaarmor.h"  // R371: the UA expanded armor',
        '#include "rules/uafollowers.h"  // R372: the UA cavalier followers'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R372: the UA cavalier
    // followers pin audit ----
    // The UA CAVALIER FOLLOWERS AND
    // HENCHMEN (pp. 74-75): the
    // men-at-arms dice ladder (all
    // d4, 1d4 at 4th through 48d4 at
    // 10th, non-cumulative, no gain
    // if the roll is not higher than
    // the current count), the four
    // equipment percentile rows (the
    // two outfits each, the medium
    // warhorses at 91-00), the
    // leader rules (the 5th-level
    // fighter per 20 troops, the 6th
    // per 60 with the 3rd-level
    // lieutenant, no replacement if
    // slain), the neutral-cause and
    // evil-bandit reads with the 1
    // and 5 percent per level monster
    // chances, the +3/+1 henchman
    // bonus and the alignment type
    // table, the retainer ladder (the
    // prose Knight at 6th flagged
    // against the R368 grid's Knight
    // at 5th), the paladin rules; the
    // R368 seam cross-checks the
    // title and rank cells, the R371
    // seam the armor costs; two
    // items flip CLOSED; the census
    // 298 -> 299.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uafolFollowersStartLevel() != 4)
                ++bad;
            if (uafolFollowersTopLevel() != 10)
                ++bad;
            if (uafolDiceSides(4) != 4) ++bad;
            if (uafolDiceSides(10) != 4) ++bad;
            if (uafolDiceSides(3) != 0) ++bad;
            if (uafolDiceSides(11) != 0) ++bad;
            if (uafolDiceCumulative()) ++bad;
            if (!uafolNoGainIfRollNotHigher())
                ++bad;
            if (uafolRowOneJavelinCount() != 3)
                ++bad;
            if (!uafolRowOneLightCavRingMailShield())
                ++bad;
            if (!uafolRowOneHeavyInfScalePoleArmClub())
                ++bad;
            if (!uafolRowTwoSplintMorningStarHandAxe())
                ++bad;
            if (!uafolRowTwoLeatherPikeShortSword())
                ++bad;
            if (!uafolRowThreeHeavyCrossbowShortSword())
                ++bad;
            if (!uafolRowThreeLightCrossbowMilitaryFork())
                ++bad;
            if (!uafolRowFourBandedShieldLanceMace())
                ++bad;
            if (!uafolRowFourStuddedLeatherLongSwordFlail())
                ++bad;
            if (uafolLeaderFighterLevel() != 5)
                ++bad;
            if (uafolLeaderTroopDenominator() != 20)
                ++bad;
            if (uafolSeniorLeaderLevel() != 6)
                ++bad;
            if (uafolSeniorLeaderTroops() != 60)
                ++bad;
            if (uafolLieutenantLevel() != 3)
                ++bad;
            if (!uafolLeadersNotReplacedIfSlain())
                ++bad;
            if (!uafolNeutralSpecificCause())
                ++bad;
            if (!uafolNeutralLeaveIfElsewhere())
                ++bad;
            if (!uafolEvilBanditsBrigands())
                ++bad;
            if (uafolEvilMonsterFollowerPctPerLevel()
                    != 1) ++bad;
            if (uafolEvilMonsterCooperatePctPerLevel()
                    != 5) ++bad;
            if (uafolHenchmanBonusGood() != 3)
                ++bad;
            if (uafolHenchmanBonusOther() != 1)
                ++bad;
            if (!uafolHenchmanGoodPaladins())
                ++bad;
            if (!uafolHenchmanNeutralThieves())
                ++bad;
            if (!uafolHenchmanEvilAssassins())
                ++bad;
            if (uafolRetainerStartLevel() != 4)
                ++bad;
            if (uafolRetainerArmigerLevel() != 1)
                ++bad;
            if (uafolRetainerScutiferLevel() != 2)
                ++bad;
            if (uafolEsquireLevel() != 3) ++bad;
            if (!uafolRetainerKnightProseConflict())
                ++bad;
            if (uafolHeraldGuardLevel() != 7)
                ++bad;
            if (uafolExtraManAtArmsLevel() != 8)
                ++bad;
            if (uafolChevalierTravelFreedomLevel()
                    != 9) ++bad;
            if (!uafolRetainersServeForCareAndUpkeep())
                ++bad;
            if (!uafolPaladinNoFollowers()) ++bad;
            if (!uafolPaladinRetainersMustBeCavaliers())
                ++bad;
        // ---- the dice ladder loops ----
            static const int kCnt[11] = {
                0, 0, 0, 0, 1, 2, 3,
                6, 12, 24, 48};
            for (int l = 4; l <= 10; ++l) {
                if (uafolDiceCount(l) != kCnt[l])
                    ++bad;
                if (uafolFollowersMin(l)
                        != kCnt[l]) ++bad;
                if (uafolFollowersMax(l)
                        != 4 * kCnt[l]) ++bad;
            }
            if (uafolDiceCount(3) != 0) ++bad;
            if (uafolDiceCount(11) != 0) ++bad;
        // ---- the equipment rows ----
            if (uafolEquipRowCount() != 4)
                ++bad;
            static const int kLo[4] = {
                1, 51, 76, 91};
            static const int kHi[4] = {
                50, 75, 90, 100};
            for (int r = 0; r < 4; ++r) {
                if (uafolEquipRowLo(r) != kLo[r])
                    ++bad;
                if (uafolEquipRowHi(r) != kHi[r])
                    ++bad;
                if (r < 3 && kHi[r] + 1
                        != kLo[r + 1]) ++bad;
                if (uafolEquipRowIsCavalry(r)
                        != (r == 0 || r == 3))
                    ++bad;
                if (uafolEquipRowMediumWarhorse(r)
                        != (r == 3)) ++bad;
            }
            if (uafolEquipRowLo(0) != 1) ++bad;
            if (uafolEquipRowHi(3) != 100) ++bad;
        // ---- the retainer ladder order ----
            if (uafolRetainerStartLevel()
                    >= uafolHeraldGuardLevel())
                ++bad;
            if (uafolHeraldGuardLevel()
                    >= uafolExtraManAtArmsLevel())
                ++bad;
            if (uafolExtraManAtArmsLevel()
                    >= uafolChevalierTravelFreedomLevel())
                ++bad;
        // ---- the R368 seam ----
            // the retainer start rides the
            // Knight Errant cell; the 7th
            // the Grand Knight, the 8th the
            // Banneret, the 9th the
            // Chevalier
            if (strcmp(uacavtTitle(
                        uafolRetainerStartLevel()),
                    "Knight Errant") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolHeraldGuardLevel()),
                    "Grand Knight") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolExtraManAtArmsLevel()),
                    "Banneret") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolChevalierTravelFreedomLevel()),
                    "Chevalier") != 0) ++bad;
            // the retainer ranks ride the
            // title ladder cells: the
            // Armiger, the Scutifer, the
            // Esquire, the Horseman, the
            // Lancer
            if (strcmp(uacavtTitle(
                        uafolRetainerArmigerLevel()),
                    "Armiger") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolRetainerScutiferLevel()),
                    "Scutifer") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolEsquireLevel()),
                    "Esquire") != 0) ++bad;
            if (strcmp(uacavtTitle(0),
                    "Horseman") != 0) ++bad;
            if (strcmp(uacavtTitle(-1),
                    "Lancer") != 0) ++bad;
        // ---- the R371 seam ----
            // the equipment rows name the
            // armors the expanded table
            // priced
            if (uaarmRingMailCost() != 30) ++bad;
            if (uaarmScaleMailCost() != 45) ++bad;
            if (uaarmSplintMailCost() != 80) ++bad;
            if (uaarmBandedCost() != 90) ++bad;
            if (uaarmStuddedLeatherCost() != 15)
                ++bad;
        printf("R372 UA cavalier followers pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R372 audit')
s = rd(RT)
assert s.count(
    'R372 UA cavalier followers pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R355 UA druid 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R354 UA druid 6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R353 UA druid 5th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R352 UA druid 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R351 UA druid 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R350 UA druid 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R349 UA cleric 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 299, 'd census 299'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uafollowers.h"'
) == 1, 'd new include'
for h in (
        'rules/cavalier.h',
        'rules/classtables.h',
        'rules/uabirth.h',
        'rules/uasocialclass.h',
        'rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h',
        'rules/uacavtable.h',
        'rules/uacantacq.h',
        'rules/uasmalls1.h',
        'rules/uailacquisition.h',
        'rules/thiefarmor.h',
        'rules/armorratings.h'):
    assert s.count(
        '#include "' + h + '"'
        ) == 1, 'd kept include'
for i in range(1, 8):
    assert s.count(
        '#include "rules/uailspells%d.h"'
        % i) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 5, 'd count'


# ---- the summary ----
print(
    'R372 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R372 note: the cavalier followers',
    'and henchmen round - the dice',
    'ladder (all d4, the min-count',
    'max-times-four invariant), the',
    'four equipment percentile rows,',
    'the leader rules, the neutral and',
    'evil reads with the 1 and 5',
    'percent monster chances, the',
    'henchman bonus and type table,',
    'the retainer ladder (the Knight',
    'prose conflict flagged), the',
    'paladin retainers; the R368 seam',
    'cross-checks the title and rank',
    'cells, the R371 seam the armor',
    'costs; two items flip CLOSED;',
    'the census 298 -> 299'
])
print(NOTE)
print('commit: R372: the UA cavalier')
print('followers pin round (census 299)',)

