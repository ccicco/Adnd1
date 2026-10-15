// =========================================================================================
// Adnd1 - rules/wsgforage.h
// R463: the WSG FOOD GATHERING AND FORAGING slice - the foraging check with
// the proficiency advantage, Table 30 (the 33-row terrain-by-season foraging
// success grid over the five climate regions) and the inedible plants
// dispatch, printed pp. 53-54.
// census 387 -> 388.
//
// Ground truth three-way: the archive djvu word layer vs the pdfy PDF text
// layer vs the pixel reads of the Table 30 scan (leaf 0053 of the pdfy item,
// full native 2432x3194 decode). The two text layers disagree or drop the
// Tem-F winter, St-P/Se/Sw winter, Tro-M winter and Tro-Se spring cells and
// both garble the Arctic P and Se rows - the pixels settled every one: a
// glyph-level NCC classifier over same-page font templates (leave-one-out
// 62/62) plus vision reads of the contrast-stretched cell crops, every
// disputed digit at 0.83-0.94 correlation with the runner-up 0.2-0.3 behind.
//
// All 132 grid cells pinned; the foraging mechanics (the two-turn check, the
// proficient 2-in-2 or 1-in-1, the -20 inedible shift, the four-turn search
// limit, the one-mile move-on, the 1d8 inedible bands) are audit examples.
//
namespace rules {

// ---- Table 30: the foraging success grid ----

// the Table 30 Arctic grid rows: desert, hills, mountains, plains and
// scrublands - no forest or swamp row
inline int wfgArcRowCount()
    { return 5; }

// the Table 30 Win foraging chance (percent, two turns)
inline int wfgArcWinChn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        default:
            return 0;
        }
    }

// the Table 30 Win inedible chance (percent of the take)
inline int wfgArcWinInd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 75;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 75;
        default:
            return 0;
        }
    }

// the Table 30 Spr foraging chance (percent, two turns)
inline int wfgArcSprChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        default:
            return 0;
        }
    }

// the Table 30 Spr inedible chance (percent of the take)
inline int wfgArcSprInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 60;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Sum foraging chance (percent, two turns)
inline int wfgArcSumChn(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 15;
        default:
            return 0;
        }
    }

// the Table 30 Sum inedible chance (percent of the take)
inline int wfgArcSumInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 60;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Aut foraging chance (percent, two turns)
inline int wfgArcAutChn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        default:
            return 0;
        }
    }

// the Table 30 Aut inedible chance (percent of the take)
inline int wfgArcAutInd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 50;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 75;
        default:
            return 0;
        }
    }

// the Table 30 Subarctic grid rows (the standard seven terrains)
inline int wfgSubRowCount()
    { return 7; }

// the Table 30 Win foraging chance (percent, two turns)
inline int wfgSubWinChn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 70;
        case 2:
            return 20;
        case 3:
            return 10;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// the Table 30 Win inedible chance (percent of the take)
inline int wfgSubWinInd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 40;
        case 5:
            return 60;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Spr foraging chance (percent, two turns)
inline int wfgSubSprChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 85;
        case 2:
            return 30;
        case 3:
            return 15;
        case 4:
            return 30;
        case 5:
            return 35;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// the Table 30 Spr inedible chance (percent of the take)
inline int wfgSubSprInd(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 40;
        case 5:
            return 50;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Sum foraging chance (percent, two turns)
inline int wfgSubSumChn(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 100;
        case 2:
            return 40;
        case 3:
            return 20;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// the Table 30 Sum inedible chance (percent of the take)
inline int wfgSubSumInd(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 40;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 40;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Aut foraging chance (percent, two turns)
inline int wfgSubAutChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 75;
        case 2:
            return 25;
        case 3:
            return 15;
        case 4:
            return 30;
        case 5:
            return 35;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// the Table 30 Aut inedible chance (percent of the take)
inline int wfgSubAutInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Temperate grid rows (the standard seven terrains)
inline int wfgTemRowCount()
    { return 7; }

// the Table 30 Win foraging chance (percent, two turns)
inline int wfgTemWinChn(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 80;
        case 2:
            return 65;
        case 3:
            return 20;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// the Table 30 Win inedible chance (percent of the take)
inline int wfgTemWinInd(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 50;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Spr foraging chance (percent, two turns)
inline int wfgTemSprChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 90;
        case 2:
            return 75;
        case 3:
            return 30;
        case 4:
            return 60;
        case 5:
            return 65;
        case 6:
            return 35;
        default:
            return 0;
        }
    }

// the Table 30 Spr inedible chance (percent of the take)
inline int wfgTemSprInd(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 40;
        case 2:
            return 40;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 40;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Sum foraging chance (percent, two turns)
inline int wfgTemSumChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 90;
        case 3:
            return 40;
        case 4:
            return 75;
        case 5:
            return 80;
        case 6:
            return 40;
        default:
            return 0;
        }
    }

// the Table 30 Sum inedible chance (percent of the take)
inline int wfgTemSumInd(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 40;
        case 2:
            return 35;
        case 3:
            return 40;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Aut foraging chance (percent, two turns)
inline int wfgTemAutChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 90;
        case 2:
            return 80;
        case 3:
            return 30;
        case 4:
            return 60;
        case 5:
            return 65;
        case 6:
            return 35;
        default:
            return 0;
        }
    }

// the Table 30 Aut inedible chance (percent of the take)
inline int wfgTemAutInd(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Subtropical grid rows (the standard seven terrains)
inline int wfgStiRowCount()
    { return 7; }

// the Table 30 Win foraging chance (percent, two turns)
inline int wfgStiWinChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 90;
        case 2:
            return 80;
        case 3:
            return 40;
        case 4:
            return 80;
        case 5:
            return 80;
        case 6:
            return 40;
        default:
            return 0;
        }
    }

// the Table 30 Win inedible chance (percent of the take)
inline int wfgStiWinInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 30;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Spr foraging chance (percent, two turns)
inline int wfgStiSprChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 90;
        case 3:
            return 55;
        case 4:
            return 90;
        case 5:
            return 90;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Spr inedible chance (percent of the take)
inline int wfgStiSprInd(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 30;
        case 2:
            return 30;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Sum foraging chance (percent, two turns)
inline int wfgStiSumChn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 100;
        case 2:
            return 100;
        case 3:
            return 75;
        case 4:
            return 100;
        case 5:
            return 100;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Sum inedible chance (percent of the take)
inline int wfgStiSumInd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 30;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Aut foraging chance (percent, two turns)
inline int wfgStiAutChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 95;
        case 3:
            return 60;
        case 4:
            return 100;
        case 5:
            return 95;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Aut inedible chance (percent of the take)
inline int wfgStiAutInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 30;
        case 2:
            return 25;
        case 3:
            return 40;
        case 4:
            return 35;
        case 5:
            return 40;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Tropical grid rows (the standard seven terrains)
inline int wfgTroRowCount()
    { return 7; }

// the Table 30 Win foraging chance (percent, two turns)
inline int wfgTroWinChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 90;
        case 3:
            return 85;
        case 4:
            return 100;
        case 5:
            return 90;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Win inedible chance (percent of the take)
inline int wfgTroWinInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 30;
        case 2:
            return 30;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Spr foraging chance (percent, two turns)
inline int wfgTroSprChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 100;
        case 3:
            return 90;
        case 4:
            return 100;
        case 5:
            return 95;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Spr inedible chance (percent of the take)
inline int wfgTroSprInd(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 30;
        case 2:
            return 40;
        case 3:
            return 30;
        case 4:
            return 45;
        case 5:
            return 50;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Sum foraging chance (percent, two turns)
inline int wfgTroSumChn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 100;
        case 2:
            return 100;
        case 3:
            return 90;
        case 4:
            return 100;
        case 5:
            return 100;
        case 6:
            return 70;
        default:
            return 0;
        }
    }

// the Table 30 Sum inedible chance (percent of the take)
inline int wfgTroSumInd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 40;
        case 2:
            return 40;
        case 3:
            return 40;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// the Table 30 Aut foraging chance (percent, two turns)
inline int wfgTroAutChn(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 100;
        case 2:
            return 95;
        case 3:
            return 90;
        case 4:
            return 100;
        case 5:
            return 95;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// the Table 30 Aut inedible chance (percent of the take)
inline int wfgTroAutInd(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 30;
        case 2:
            return 35;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 50;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// ---- The foraging check ----

// a normal character forages two turns per check: the chance to find one full
// day's ration
inline int wfgCheckTurnsNormal()
    { return 2; }

// one full day's ration of plant life is two pounds of fruit, vegetables
// and/or greenery
inline int wfgRationPounds()
    { return 2; }

// with the foraging proficiency: two full rations located in the same two
// turns of foraging
inline int wfgProfRationsPerCheck()
    { return 2; }

// with the proficiency: one full ration located in one turn of foraging
inline int wfgProfTurnsPerRation()
    { return 1; }

// with the proficiency: the chance of the take being inedible is 20% lower
// than a normal character's
inline int wfgProfInedibleReduction()
    { return 20; }

// the proficient character's chance of locating potentially edible plants is
// no greater than any other character's
inline bool wfgProfFindChanceNormal()
    { return true; }

// fruitless to spend more than four turns attempting to find food - no
// further searching produces better results
inline int wfgSearchTurnsMax()
    { return 4; }

// the four-turn limit is two foraging checks for a normal character
inline int wfgChecksMaxNormal()
    { return 2; }

// the four-turn limit is four foraging checks for one with the proficiency
inline int wfgChecksMaxProf()
    { return 4; }

// after a fruitless search the group must travel at least one mile before
// foraging again
inline int wfgMilesBeforeReforage()
    { return 1; }

// if every character searches the limit and no food is found, the group must
// move on before foraging again
inline bool wfgGroupMustMoveOn()
    { return true; }

// ---- Inedible plants: the 1d8 dispatch ----

// the inedible-plants band on 1d8: 1 poisonous band 0, 2-4 tainted band 1,
// 5-8 no food value band 2
inline int wfgInedBandFor(int r)
    {
        if (r <= 1) return 0;
        if (r <= 4) return 1;
        return 2;
    }

// the inedible-plants dispatch roll is 1d8
inline int wfgInedRollMax()
    { return 8; }

// poisonous plants: cramps begin 1d10 rounds after eating
inline int wfgPoisonCrampOnsetDie()
    { return 10; }

// poisonous plants: the cramps last 2d10 turns
inline int wfgPoisonCrampTurnsDice()
    { return 2; }

// poisonous plants: the cramp duration die is d10
inline int wfgPoisonCrampTurnsDie()
    { return 10; }

// poisonous plants: 1d4 hit points lost per turn while the cramps persist
inline int wfgPoisonHpPerTurnDie()
    { return 4; }

// poisonous plants: hit points regained at 1d4 per hour with rest
inline int wfgPoisonRegainPerHourDie()
    { return 4; }

// the poison recovery requires at least one pint of water per hour while
// resting
inline int wfgPoisonRestWaterPintsPerHour()
    { return 1; }

// poisonous plants hit anyone who eats a half-ration or more
inline bool wfgPoisonHalfRationTriggers()
    { return true; }

// a saving throw versus poison halves both the cramp duration and the damage
inline bool wfgPoisonSaveHalves()
    { return true; }

// a slow poison spell acts the same as a successful saving throw
inline bool wfgSlowPoisonActsAsSave()
    { return true; }

// slow poison on a character who made his save: one-fourth duration and
// damage
inline int wfgSlowPoisonSaveStackNum()
    { return 1; }

// slow poison on a character who made his save: the one-fourth denominator
inline int wfgSlowPoisonSaveStackDen()
    { return 4; }

// a neutralize poison spell halts the cramps and negates any damage that
// would be suffered subsequently
inline bool wfgNeutralizeHaltsCramps()
    { return true; }

// neutralize poison does not negate damage taken before the spell was applied
inline bool wfgNeutralizeNoPriorDamage()
    { return true; }

// tainted plants: cramps begin within 1d10 rounds
inline int wfgTaintCrampOnsetDie()
    { return 10; }

// tainted plants: the cramps last 1d10 turns
inline int wfgTaintCrampTurnsDie()
    { return 10; }

// tainted plants: 1d2 hit points lost per turn while the cramps persist
inline int wfgTaintHpPerTurnDie()
    { return 2; }

// tainted plants affect the consumer as half-strength poison
inline int wfgTaintHalfNum()
    { return 1; }

// the tainted half-strength denominator
inline int wfgTaintHalfDen()
    { return 2; }

// tainted plants: a saving throw versus poison reduces duration and damage by
// half
inline bool wfgTaintSaveHalves()
    { return true; }

// tainted plants: a neutralize poison or cure disease spell halts duration
// and damage as soon as it is cast
inline bool wfgTaintCureDiseaseHalts()
    { return true; }

// the 5-8 no-value plants provide no food value aside from the water they
// might contain
inline bool wfgNoValueWaterOnly()
    { return true; }

// no-value plants fill the stomach but affect the system as though no food
// was eaten
inline bool wfgNoValueFullNoNourish()
    { return true; }

// ---- When not to use the table ----

// camp in an apple grove or a cornfield edge: a 100% chance of coming back
// with food, whatever the table says
inline bool wfgOrchardGuaranteed()
    { return true; }

// gathering all the ripe fruit from the trees instead of picking some up off
// the ground: little or no chance the food is inedible
inline bool wfgRipePickedInedibleNearZero()
    { return true; }

// the table must not unswervingly dictate what happens - common sense and
// reasonable judgment prevail
inline bool wfgTableNotUnerring()
    { return true; }

}   // namespace rules
