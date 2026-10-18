// =========================================================================================
// Adnd1 - rules/oakensai.h
// THE KENSAI, printed capture pp. 28-31 - the OA sword saint round
// census 542 -> 543.
//
// verified against capture pp. 28-31 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). The Table 19
// special-abilities column pins as a coded ladder (meditation, the 1-in-6
// surprise, two weapons and fear, the pupils, the whirlwind). OCR
// normalization: practice daisy reads as practice daily (prose only). This
// push ALSO carries the still-unlanded R618 v3 amendment (spec_r618 08fa91d7
// -> 9ea88b9e, oaraces.h 3786b6c2 -> 615b853c) - the R619 fold silently
// failed because the rn flow stages only the current round files; this time
// the two prior-round files must be added explicitly.
//
// the gap census after this round: 36 closed, 199 open - the kensai boxes
// with Tables 18 and 19 flip (census 542 -> 543); NEXT - R621: the Monk - the
// discipline ladder, the quirks, Tables 20 and 21, prefix dgh (verify free),
// audit "R621 OA monk audit", include after rules/oakensai.h
//
namespace rules {

// ---- the kensai doctrine pins ----

// Kensai prose (capture p. 29): Wisdom and Dexterity are the prime requisites
// - both 14 or higher earns the 10 percent experience bonus
inline bool dggKensaiDualPrime()
    { return true; }

// Kensai prose (capture p. 29): the Strength minimum
inline int dggKensaiMinStr()
    { return 12; }

// Kensai prose (capture p. 29): the Wisdom minimum
inline int dggKensaiMinWis()
    { return 12; }

// Kensai prose (capture p. 29): the Dexterity minimum
inline int dggKensaiMinDex()
    { return 14; }

// Kensai prose (capture p. 29): must be lawful - good, evil or neutral;
// humans, hengeyokai and spirit folk only
inline bool dggKensaiLawfulOnly()
    { return true; }

// Kensai prose (capture p. 29): the 10-sided hit die, one per level
inline int dggKensaiHitDie()
    { return 10; }

// Kensai prose (capture p. 29): the fighter combat and saving throw tables;
// any weapon, no armor
inline bool dggKensaiFighterTables()
    { return true; }

// Kensai prose (capture p. 29): ninja preferred weapons lose honor - unless
// it is the chosen weapon
inline bool dggKensaiNinjaHonorUnless()
    { return true; }

// Kensai prose (capture p. 29): three initial proficiency slots - the free
// chosen-weapon proficiency costs none; only one slot may buy a second
// weapon; the rest must be peaceful skills
inline int dggKensaiSlots()
    { return 3; }

// Kensai prose (capture p. 29): no Reaction/Attack or Defensive Adjustments
// from Dexterity - the natural AC replaces them
inline bool dggKensaiNoDexAdjustments()
    { return true; }

// Kensai prose (capture p. 29): the natural AC formula - 23 minus Dexterity
// (the printed Dex 16 to AC 7 example)
inline int dggKensaiNaturalAcBase()
    { return 23; }

// Kensai prose (capture p. 29): the natural AC improves one step per three
// levels
inline int dggKensaiAcStepLevels()
    { return 3; }

// Kensai prose (capture p. 29): +1 on all initiative rolls, melee and
// missile, self only in a group
inline int dggKensaiInitBase()
    { return 1; }

// Kensai prose (capture p. 29): +1 on all saving throws
inline int dggKensaiSaveBonus()
    { return 1; }

// Kensai prose (capture p. 29): the ki power - maximum damage on one attack
// with the specialty weapon, announced before the to-hit roll, times per day
// equal to level
inline bool dggKensaiKiMaxDamage()
    { return true; }

// Kensai prose (capture p. 29): the psychic-duel bonus vs. non-kensai; vs.
// another kensai only the levels count
inline int dggKensaiDuelBonusVsOthers()
    { return 2; }

// Kensai prose (capture p. 29): all kensai are immune to fear
inline bool dggKensaiImmuneFear()
    { return true; }

// ---- the kensai level-power pins ----

// Kensai prose (capture p. 30): the damage bonus steps - +1 at 2nd, again at
// 5th, 8th, 10th and 12th, total +5
inline int dggKensaiDmgLevels()
    { return 5; }

// Kensai prose (capture p. 30): the to-hit bonus steps - +1 at 3rd, again at
// 5th, 8th, 10th and 12th, total +5 and the equivalence of a magical +5
// weapon
inline int dggKensaiHitLevels()
    { return 5; }

// Kensai prose (capture p. 30): the initiative bonus rises to +2 at 5th (the
// printed total modifier)
inline int dggKensaiInitTwo()
    { return 2; }

// Kensai prose (capture p. 30): the initiative bonus rises to +3 at 9th
inline int dggKensaiInitThree()
    { return 3; }

// Kensai prose (capture p. 30): at 4th level meditates like a shukenja
inline int dggKensaiMeditateLevel()
    { return 4; }

// Kensai prose (capture p. 30): at 6th level surprised only on a 1 on 1d6
inline int dggKensaiSurpriseLevel()
    { return 6; }

// Kensai prose (capture p. 30): at 7th level two weapons simultaneously with
// no penalty, and causes fear as a samurai
inline int dggKensaiTwoWeaponsLevel()
    { return 7; }

// Kensai prose (capture p. 30): at 9th level attracts 1d6 pupils, all
// 1st-level kensai specializing in the master weapon
inline int dggKensaiPupilDie()
    { return 6; }

// Kensai prose (capture p. 30): a 5 percent chance per level that a pupil
// ends studies and leaves
inline int dggKensaiPupilDepartPct()
    { return 5; }

// Kensai prose (capture p. 30): a 50 percent chance per pupil of leaving when
// the master loses a duel to a lower-level kensai
inline int dggKensaiPupilLossPct()
    { return 50; }

// Kensai prose (capture p. 30): defeating a higher-level kensai in a duel
// gains 1-2 additional pupils
inline bool dggKensaiPupilGain()
    { return true; }

// Kensai prose (capture p. 30): the whirlwind attack at 11th level
inline int dggKensaiWhirlwindLevel()
    { return 11; }

// Kensai prose (capture p. 30): the whirlwind attacks all opponents within 10
// feet once in the same round
inline int dggKensaiWhirlwindRange()
    { return 10; }

// Kensai prose (capture p. 30): the whirlwind requires the entire day ki
// (none used before), specialty weapon only, initiative applies, no
// max-damage guarantee, all other bonuses apply
inline bool dggKensaiWhirlwindCostsAllKi()
    { return true; }

// ---- the kensai restriction and duel pins ----

// Kensai prose (capture p. 30): never a magical weapon of the specialty type
// - no true measure of skill; all armor prohibited
inline bool dggKensaiNoMagicSpecialty()
    { return true; }

// Kensai prose (capture p. 30): one-half experience for opponents defeated
// with a non-specialty weapon - even in part, unless fighting with specialty
// and another weapon at once
inline bool dggKensaiHalfXpOtherWeapon()
    { return true; }

// Kensai prose (capture p. 31): double experience for defeating another
// kensai in a duel; a duel with a particular opponent once per level
inline int dggKensaiDuelXpMultiplier()
    { return 2; }

// Kensai prose (capture p. 31): at least two hours of daily practice; every
// skipped two-hour session must be made up before advancing (four hours per
// day when catching up - the printed Kiyomori example)
inline int dggKensaiPracticeHours()
    { return 2; }

// Kensai prose (capture p. 31): on each level gain a 10-times-new-level
// percent chance of a duel challenge from a same-level kensai
inline bool dggKensaiDuelChallenge()
    { return true; }

// Kensai prose (capture p. 31): refusing or losing the duel forfeits the new
// level (bottom of the old) and loses honor; the 10th level must be dueled
// for; NPC duels cost honor only, never a level
inline bool dggKensaiDuelRefuseCost()
    { return true; }

// Kensai prose (capture p. 31): the duel need not be to the death -
// surrender, first blood, first strike or first draw; no magical weapons or
// armor; no aid or support
inline bool dggKensaiDuelConditions()
    { return true; }

// Kensai prose (capture p. 31): honor below the family honor means demotion
// to bushi of the same level - abilities kept, no new kensai abilities, bushi
// advancement
inline bool dggKensaiHonorDemotion()
    { return true; }

// Kensai prose (capture p. 31): not high birth by requirement but must roll
// Table 38 - treated socially by birth until the reputation forms
inline bool dggKensaiBirthRequired()
    { return true; }

// ---- the Table 18 and Table 19 grids ----

// Table 18 (capture pp. 28-29): twelve rows, levels 1-12
inline int dggT18RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 3,000 at 1st to
// 1,250,000 at 12th (capture pp. 28-29).
inline int dggT18XpMax(int b)
    {
        switch (b) {
        case 0:
            return 3000;
        case 1:
            return 5500;
        case 2:
            return 10000;
        case 3:
            return 22000;
        case 4:
            return 44000;
        case 5:
            return 88000;
        case 6:
            return 150000;
        case 7:
            return 250000;
        case 8:
            return 500000;
        case 9:
            return 750000;
        case 10:
            return 1000000;
        case 11:
            return 1250000;
        default:
            return -99;
        }
    }

// the accumulated d10 dice column: one per level through 9th, then held at 9
// (capture pp. 28-29).
inline int dggT18Dice(int b)
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

// the hit-point bonus column: the printed 9-plus-N cells - 2 per level beyond
// 9th: 0 through 9th, then 2, 4, 6 (capture pp. 28-29).
inline int dggT18HpBonus(int b)
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
            return 2;
        case 10:
            return 4;
        case 11:
            return 6;
        default:
            return -99;
        }
    }

// Table 18 note (capture p. 29): 250,000 experience points per level beyond
// 12th
inline int dggT18XpBeyond()
    { return 250000; }

// Table 18 note (capture p. 29): 2 hit points per level beyond 9th
inline int dggT18HpBeyond()
    { return 2; }

// Table 19 (capture p. 30): twelve rows, levels 1 through 12+
inline int dggT19RowCount()
    { return 12; }

// Table 19 special code (capture p. 30): none
inline int dggT19SpecNone()
    { return 0; }

// Table 19 special code (capture p. 30): meditation at 4th
inline int dggT19SpecMeditate()
    { return 1; }

// Table 19 special code (capture p. 30): the 1-in-6 surprise at 6th
inline int dggT19SpecSurprise()
    { return 2; }

// Table 19 special code (capture p. 30): two weapons and fear at 7th
inline int dggT19SpecTwoWeapons()
    { return 3; }

// Table 19 special code (capture p. 30): the 1-6 pupils at 9th
inline int dggT19SpecPupils()
    { return 4; }

// Table 19 special code (capture p. 30): the whirlwind attack at 11th
inline int dggT19SpecWhirlwind()
    { return 5; }

// the initiative bonus column: +1 at 1st, +2 from 5th, +3 from 9th (capture
// p. 30).
inline int dggT19Init(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
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
        default:
            return -99;
        }
    }

// the AC bonus column: +1 at 3rd stepping to +4 at 10th (capture p. 30).
inline int dggT19Ac(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
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
        default:
            return -99;
        }
    }

// the damage bonus column: +1 at 2nd stepping to +5 at 12+ (capture p. 30).
inline int dggT19Dmg(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 5;
        default:
            return -99;
        }
    }

// the to-hit bonus column: +1 at 3rd stepping to +5 at 12+ (capture p. 30).
inline int dggT19Hit(int b)
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
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 5;
        default:
            return -99;
        }
    }

// the special code column: none 0, meditation 1 at 4th, the 1-in-6 surprise 2
// at 6th, two weapons and fear 3 at 7th, the 1-6 pupils 4 at 9th, the
// whirlwind 5 at 11th (capture p. 30).
inline int dggT19Special(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 5;
        case 11:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
