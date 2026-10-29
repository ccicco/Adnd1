// =========================================================================================
// Adnd1 - rules/brw.h
// The Dragon issue-11 opener - the Kuntz brawling article (folio 7) and the
// Ward quarterstaff article (folios 26-27): two adjudicated chains in one
// round
// census 839 -> 840.
//
// Pinned from The Dragon Vol. II No. 5 (December 1977), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 11;
// the source lives in the archive.org item accessory-dragon-magazine-012,
// file Accessory - Dragon Magazine #011_djvu.xml). PRINT FOLIO = PDF PAGE,
// verified at the TOC alignments - the guest editorial at 5, the brawling
// article at 7, the Sorcerer's Scroll column at 16, the Sea Magic byline at
// 17, the quarterstaff rules at 26 and the Fineous Fingers comic at 29; no
// printed footer digits survive this scan. The transcripts ride
// extract/dragon/011/p001 through p038; the article CHAIN is the ink unit,
// not the folio.
//
// The punch grid's row-2 plus-four-or-higher cell garbles in the DjVu OCR (a
// quoted 3) and rides the -9 sentinel with its one-cell census; the four
// clean row-2 cells anchor to the print's own snake-eyes note (the plus-3 -4
// for 40 percent, the 0-or-lower -1 for 10); the -5 haymaker of the legend
// never prints clean in the grid. The quarterstaff worked example's 7-or-more
// hit floor reads against the rules text's third-stage 9 less the
// dexterity-18 plus-3 = 6 - the rules text is the pin, the discrepancy noted
// never silent.
//
namespace rules {

// ---- the Kuntz brawling article (folio 7) ----

// the first-move gap - a dexterity +2 or more comparatively moves first
// (folio 7)
inline int brwFirstMoveDexGap()
    { return 2; }

// two six-sided dice drive the brawl (folio 7)
inline int brwBrawlDiceCount()
    { return 2; }

// the six-sided brawl die (folio 7)
inline int brwBrawlDiceSides()
    { return 6; }

// a punch hits on a 2-7 roll, above that a miss (folio 7)
inline int brwPunchHitMax()
    { return 7; }

// second and further punches need a 2-6 (folio 7)
inline int brwPunchSecondHitMax()
    { return 6; }

// each extra punch rides at -1 per die roll (folio 7)
inline int brwExtraPunchPenalty()
    { return 1; }

// zero constitution points drops the brawler unconscious (folio 7)
inline int brwUnconsciousAtCon()
    { return 0; }

// the snake-eyes knockout chance is the netted score times 10 percent (folio
// 7)
inline int brwKnockoutPercentPerPoint()
    { return 10; }

// a G2 or higher is needed to break a grapple (folio 7)
inline int brwBreakFreeMinG()
    { return 2; }

// the grappling grid rows - the 2d6 rolls 2 through 12 (folio 7)
inline int brwGrappleRows()
    { return 11; }

// the punch grid rows - the 2d6 rolls 2 through 12 (folio 7)
inline int brwPunchRows()
    { return 11; }

// combine and average the grapple dexterity and strength of both players,
// rounded down (folio 7)
inline bool brwAveragedGrappleRoundsDown()
    { return true; }

// brawl damage subtracts from the constitution score (folio 7)
inline bool brwConstitutionIsBrawlPool()
    { return true; }

// constitution changes force re-comparisons during the next round (folio 7)
inline bool brwRecompareOnConChange()
    { return true; }

// a dexterity doubling or trebling the opponent's grants that many more
// punches (folio 7)
inline bool brwDexMultiplesGrantExtraPunches()
    { return true; }

// an NG on the attacker's continue-hold roll frees the defender to punch or
// grapple (folio 7)
inline bool brwContinueHoldNgFrees()
    { return true; }

// a roll of snake eyes on the punch grid opens the automatic-knockout chance
// (folio 7)
inline bool brwSnakeEyesKnockoutRoll()
    { return true; }

// G1 through G4 mean grappled for that many points of damage, NG no grapple
// (folio 7)
inline bool brwGCodesAreDamage()
    { return true; }

// the difference band - call with 4 minus the attacker's advantage: band 0
// the +4-or-higher column, 1 the +3, 2 the +2, 3 the +1, the tail the
// 0-or-lower (folio 7)
inline int brwDiffBand(int x)
    {
        if (x <= 0) return 0;
        if (x <= 1) return 1;
        if (x <= 2) return 2;
        if (x <= 3) return 3;
        return 4;
    }

// the grappling grid, +4 or higher column - the 2d6 rows 2 through 12 as
// G-code 1-4, 0 the NG (folio 7)
inline int brwGrapplePlus4Hi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        default:
            return -1;
        }
    }

// the grappling grid, +3 column (folio 7)
inline int brwGrapplePlus3(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        default:
            return -1;
        }
    }

// the grappling grid, +2 column (folio 7)
inline int brwGrapplePlus2(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -1;
        }
    }

// the grappling grid, +1 column (folio 7)
inline int brwGrapplePlus1(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -1;
        }
    }

// the grappling grid, 0-or-lower column (folio 7)
inline int brwGrappleZeroLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
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
        default:
            return -1;
        }
    }

// the punch grid, +4 or higher column - the 2d6 rows as damage points, 0 the
// miss, the row-2 cell riding the -9 sentinel (folio 7)
inline int brwPunchPlus4Hi(int b)
    {
        switch (b) {
        case 0:
            return -9;
        case 1:
            return -3;
        case 2:
            return -3;
        case 3:
            return -3;
        case 4:
            return -2;
        case 5:
            return -2;
        case 6:
            return -2;
        case 7:
            return -2;
        case 8:
            return -2;
        case 9:
            return -1;
        case 10:
            return -1;
        default:
            return -9;
        }
    }

// the punch grid, +3 column - the row-2 -4 solid punch of the snake-eyes note
// (folio 7)
inline int brwPunchPlus3(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -3;
        case 2:
            return -3;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -2;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return 0;
        default:
            return -9;
        }
    }

// the punch grid, +2 column (folio 7)
inline int brwPunchPlus2(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -9;
        }
    }

// the punch grid, +1 column (folio 7)
inline int brwPunchPlus1(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -9;
        }
    }

// the punch grid, 0-or-lower column - the row-2 -1 of the 10-percent note
// (folio 7)
inline int brwPunchZeroLo(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
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
        default:
            return -9;
        }
    }

// ---- the Ward quarterstaff article (folios 26-27) ----

// a first-stage staffer hits on a 12 or more (folio 26)
inline int brwStageOneHit()
    { return 12; }

// a second-stage staffer hits on an 11 (folio 26)
inline int brwStageTwoHit()
    { return 11; }

// a third-stage staffer hits on a 9 (folio 26)
inline int brwStageThreeHit()
    { return 9; }

// a hit rolls a six-sided die for damage plus strength bonuses (folio 26)
inline int brwStaffDamageSides()
    { return 6; }

// an unmodified hit of 20 adds one point of damage to the die (folio 26)
inline int brwNaturalTwentyBonus()
    { return 1; }

// a double attacker takes an extra three points of damage if hit that turn,
// not per hit (folio 26)
inline int brwDoubleAttackExtraDamage()
    { return 3; }

// two strikes doing more than four points force the opponent to defend twice
// next turn (folio 26)
inline int brwForcedDefendThreshold()
    { return 4; }

// a double defense negating all damage grants plus one on the first strike
// next turn (folio 26)
inline int brwFullNegateNextBonus()
    { return 1; }

// chainmail absorbs four points of damage every time the wearer is hit (folio
// 26)
inline int brwChainmailAbsorb()
    { return 4; }

// chainmail adds 3 to the wearer's hit roll (folio 26)
inline int brwChainmailHitPenalty()
    { return 3; }

// platemail absorbs six points of damage every time the wearer is hit (folio
// 26)
inline int brwPlateAbsorb()
    { return 6; }

// platemail adds 5 to the wearer's hit roll (folio 26)
inline int brwPlateHitPenalty()
    { return 5; }

// a staffer fights until he is down to one Combat Index point, then out cold
// (folio 26)
inline int brwOutColdAtPoints()
    { return 1; }

// 50 matches against equal-or-better opponents drive the stage ladder (folio
// 26)
inline int brwAdvanceMatches()
    { return 50; }

// winning 30 of the 50 matches raises a first-stage staffer to second (folio
// 26)
inline int brwAdvanceWins()
    { return 30; }

// doubling the matches-and-wins raises a second-stage staffer to third (folio
// 26)
inline int brwAdvanceDoubleFactor()
    { return 2; }

// an 18 strength adds plus 2 on damage (folio 26)
inline int brwStrBonusEighteen()
    { return 2; }

// a 17 strength adds plus 1 on damage (folio 26)
inline int brwStrBonusSeventeen()
    { return 1; }

// an 18 constitution absorbs 2 points of damage every melee turn (folio 26)
inline int brwConAbsorbEighteen()
    { return 2; }

// a 17 constitution absorbs 1 point of damage every melee turn (folio 26)
inline int brwConAbsorbSeventeen()
    { return 1; }

// the dexterity ladder rows - the 16, 17 and 18 bonuses (folio 26)
inline int brwDexLadderRows()
    { return 3; }

// the nine merry men of Robin Hood's band statted for historical simulations
// (folio 27)
inline int brwMerryMen()
    { return 9; }

// each staffer chooses attack-attack, attack-defend or defend-defend each
// melee turn (folio 26)
inline bool brwThreeMeleeOptions()
    { return true; }

// all staff combat is simultaneous regardless of any first hit (folio 26)
inline bool brwCombatSimultaneous()
    { return true; }

// the suggested option - secretly write down each melee turn's plan (folio
// 26)
inline bool brwSecretOrdersOption()
    { return true; }

// chainmail and platemail absorb their points every time the wearer is hit
// (folio 26)
inline bool brwArmorAbsorbsPerHit()
    { return true; }

// a staffer struck twice for more than four points is forced to defend twice
// next turn (folio 26)
inline bool brwDoubleStrikeForcesDefend()
    { return true; }

// a double defense negating all the damage grants plus one on the first
// strike next turn (folio 26)
inline bool brwFullNegateGrantsPlusOne()
    { return true; }

// the Combat Index is the strength plus constitution scores added together
// (folio 26)
inline bool brwCombatIndexIsStrCon()
    { return true; }

// experience raises the stage - the 50-match ladder at 30 wins (folio 26)
inline bool brwStageAdvancementByMatches()
    { return true; }

// the merry men carry their probable qualities for historical simulations
// (folio 27)
inline bool brwMerryMenForHistoricalSim()
    { return true; }

// the dexterity ladder hit pluses - the rows the 16, 17 and 18 dexterity
// (folio 26)
inline int brwDexHitPlus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return -1;
        }
    }

// the dexterity ladder absorbs - plus 2, 1 and none across the ladder (folio
// 26)
inline int brwDexAbsorb(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -1;
        }
    }

// the merry men strength scores (folio 27)
inline int brwMerryStr(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 17;
        case 6:
            return 17;
        case 7:
            return 17;
        case 8:
            return 17;
        default:
            return -1;
        }
    }

// the merry men dexterity scores (folio 27)
inline int brwMerryDex(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 17;
        case 3:
            return 17;
        case 4:
            return 16;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 16;
        case 8:
            return 17;
        default:
            return -1;
        }
    }

// the merry men constitution scores (folio 27)
inline int brwMerryCon(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 17;
        case 3:
            return 15;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 17;
        default:
            return -1;
        }
    }

// the merry men proficiency stages (folio 27)
inline int brwMerryStage(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 2;
        default:
            return -1;
        }
    }

}   // namespace rules
