// =========================================================================================
// Adnd1 - rules/wsgswimfold.h
// The WSG SWIMMER'S MOTION-CHAIN FOLD, R500: the second seam round after gap
// closure. The swimming rates (rules/wsgswim.h), the dive leg
// (rules/wsgdive.h), the surfacing and breath rules (rules/wsgbreath.h), the
// moving-water hazards (rules/wsgmwater.h) and the treading economy
// (rules/wsgtread.h) reconciled as one system: one swimmer, one chain, every
// rate and threshold cross-checked between its headers.
// census 424 -> 425.
//
// No new book pages: every value is the landed original re-read from its
// header (wsmHumanSwimRateFt, wsmSubsurfaceNum, wsmHighSpeedMult,
// wsmRestRegainPerTurn, wdvBaseDownRateIn, wdvModEncMult, wdvHeavyEncMult,
// whbBaseSurfRateIn, whbInertRiseFt, wmwFallSaveMinFt, wmwHoldCheckPeriod,
// wtwProfTurnsPerEndPt, wtwCumCheckStep and kin) and re-pinned on the fold
// side so the boundary identities compile and ride the mutant battery. The
// findings: the vertical rates equal each other (both 2 inches) and are half
// the horizontal base (20 vs 40 feet); the Table 24 dive column matches the
// dive prose (x2 moderate, x3 heavy and severe); the encumbrance paradox (the
// moderate speed denominator 2 equals the moderate dive multiplier 2 -
// opposite meanings); the forty-foot agreement (the dive falling-damage
// threshold equals the waterfall save threshold); the mercy drift cap equals
// the light-current range; and the breath Con Checks step +2 while the
// treading Str Checks step +1.
//
// THE SETTLE: census 424 -> 425; the gap report stays 186 closed / 0 open
// (closed - no flips this round); the swimmer's chain has no gaps.
//
namespace rules {

// ---- the breath side ----

// the base breath time is Con/3 rounds, rounded up (whbBreathConDiv).
inline int wmfBreathConDiv()
    { return 3; }

// any character holds breath at least one round (whbMinBreathRounds).
inline int wmfMinBreathRounds()
    { return 1; }

// unprepared or strenuous cuts the time in half (whbPenaltyDiv).
inline int wmfPenaltyDiv()
    { return 2; }

// both penalties together leave one-fourth (whbBothPenaltyDiv).
inline int wmfBothPenaltyDiv()
    { return 4; }

// each Con Check after the first carries a cumulative +2 (whbConCheckStep).
inline int wmfConCheckStep()
    { return 2; }

// the printed example: Con 12 holds 4 rounds (whbExampleRounds).
inline int wmfBreathExampleRounds()
    { return 4; }

// ---- the fold findings ----

// the base downward rate and the base surfacing rate are the same 2 inches -
// the breath header says it in prose: like the diving rate.
inline bool wmfVerticalRatesEqual()
    { return true; }

// the vertical base (20 feet) is exactly half the horizontal base (40 feet) -
// down and up are half as fast as across.
inline bool wmfVerticalHalfHorizontal()
    { return true; }

// the Table 24 dive column (x1, x1, x2, x3, x3) matches the dive prose:
// doubled at moderate, tripled at heavy and severe.
inline bool wmfDiveGridMatchesProse()
    { return true; }

// the same encumbrance that halves horizontal speed doubles the sink rate -
// the dive grid is the inverse of the speed grid.
inline bool wmfEncumbranceParadox()
    { return true; }

// the dive falling-damage threshold and the waterfall save threshold are the
// same 40 feet - the two headers cross-reference each other.
inline bool wmfFortyFootAgreement()
    { return true; }

// the mercy drift cap (1 to 3 inches) equals the light-current range - the
// carried swimmer moves at light-current speed.
inline bool wmfMercyMatchesLightCur()
    { return true; }

// the breath Con Checks step +2 while the treading Str Checks step +1 - both
// cumulative, different ladders.
inline bool wmfCheckStepsDiffer()
    { return true; }

// three endurance economies in one chain: rest regains 3 per turn, high speed
// spends at 1/10, and treading spends 1 point per 2 turns.
inline bool wmfEconomiesDiffer()
    { return true; }

// the subsurface cut (2/3) applies and high speed is barred beneath the
// surface - the two rules meet at the waterline.
inline bool wmfSubsurfaceBeforeHighSpeed()
    { return true; }

// the inert buoyancy rise (5 feet) is one quarter of the deliberate surfacing
// rate (20 feet).
inline bool wmfInertQuarterOfDeliberate()
    { return true; }

// ---- the horizontal side ----

// the base human swimming rate, 4 inches or 40 feet per round
// (wsmHumanSwimRateFt).
inline int wmfSwimRateFt()
    { return 40; }

// the base rate for other PC races and land-based humanoids, 3 inches or 30
// feet (wsmOtherSwimRateFt).
inline int wmfOtherRateFt()
    { return 30; }

// the subsurface cut numerator: 2/3 of the surface rate (wsmSubsurfaceNum).
inline int wmfSubsurfNum()
    { return 2; }

// the subsurface cut denominator: 2/3, rounded up.
inline int wmfSubsurfDen()
    { return 3; }

// high speed doubles the normal movement rate (wsmHighSpeedMult).
inline int wmfHighSpeedMult()
    { return 2; }

// high speed cuts endurance to 1/10, rounded up (wsmHighSpeedEndDiv).
inline int wmfHighSpeedEndDiv()
    { return 10; }

// a resting swimmer regains three turns of endurance per turn of rest
// (wsmRestRegainPerTurn).
inline int wmfRestRegainPerTurn()
    { return 3; }

// a light current modifies the rate by 1 to 3 inches (wsmLightCurMaxIn).
inline int wmfLightCurMaxIn()
    { return 3; }

// a strong current modifies the rate by 4 to 6 inches (wsmStrongCurMinIn).
inline int wmfStrongCurMinIn()
    { return 4; }

// the top of the strong-current range: 4 to 6 inches.
inline int wmfStrongCurMaxIn()
    { return 6; }

// a negative-rate swimmer is carried opposite at 1 to 3 inches
// (wsmMercyDriftMaxIn).
inline int wmfMercyDriftMaxIn()
    { return 3; }

// ---- the moving-water side ----

// the stream hazard rating runs 1 to 10, 1 the most hazardous
// (wmwStreamRateMin).
inline int wmfStreamRateMin()
    { return 1; }

// the top of the stream hazard rating range (wmwStreamRateMax).
inline int wmfStreamRateMax()
    { return 10; }

// a grabbed protrusion is held on a Strength Check once every two rounds
// (wmwHoldCheckPeriod).
inline int wmfHoldCheckPeriod()
    { return 2; }

// the waterfall half-damage rule and the save apply at 40 feet or more
// (wmwFallSaveMinFt).
inline int wmfWaterfallMinFt()
    { return 40; }

// a successful save over 40 but not more than 100 feet means no damage
// (wmwFallSaveMaxFt).
inline int wmfWaterfallMaxFt()
    { return 100; }

// a dive from 40 feet or more may suffer the waterfall falling damage
// (wdvHighDiveMinFt).
inline int wmfHighDiveMinFt()
    { return 40; }

// waterfall damage is one-half of the free-fall amount (wmwFallDamageDiv).
inline int wmfFallDmgDiv()
    { return 2; }

// a saved fall beyond 100 feet costs one-tenth damage, rounded up
// (wmwLongFallDiv).
inline int wmfLongFallDiv()
    { return 10; }

// ---- the treading side ----

// the proficient treader spends one endurance point per two turns
// (wtwProfTurnsPerEndPt).
inline int wmfTreadTurnsPerEndPt()
    { return 2; }

// the nonproficient treader gets one round per strength point
// (wtwNonprofRoundsPerStrPt).
inline int wmfTreadRoundsPerStrPt()
    { return 1; }

// each treading Str Check after the first carries a cumulative +1
// (wtwCumCheckStep).
inline int wmfTreadCheckStep()
    { return 1; }

// the printed example: strength 6 unencumbered treads 12 rounds
// (wtwExampleRounds).
inline int wmfTreadExampleRounds()
    { return 12; }

// the Table 24 endurance multiplier for the unencumbered row: doubled
// (wsmEndNum row 0 over wsmEndDen row 0).
inline int wmfEncMultUnenc()
    { return 2; }

// the Table 24 speed denominator at moderate encumbrance: half speed
// (wsmSpdDen row 2).
inline int wmfSpdDenMod()
    { return 2; }

// the Table 24 speed denominator at heavy encumbrance: quarter speed
// (wsmSpdDen row 3).
inline int wmfSpdDenHeavy()
    { return 4; }

// ---- the vertical side ----

// the base downward rate, 2 inches or 20 feet per round (wdvBaseDownRateIn).
inline int wmfDownRateIn()
    { return 2; }

// the base downward rate in feet per round (wdvBaseDownRateFt).
inline int wmfDownRateFt()
    { return 20; }

// the downward rate doubles for moderately encumbered characters
// (wdvModEncMult).
inline int wmfDiveEncModMult()
    { return 2; }

// the downward rate triples for heavily or severely encumbered characters
// (wdvHeavyEncMult).
inline int wmfDiveEncHeavyMult()
    { return 3; }

// the base surfacing rate, like the diving rate 2 inches (whbBaseSurfRateIn).
inline int wmfSurfRateIn()
    { return 2; }

// an inert character rises by natural buoyancy at 5 feet per round
// (whbInertRiseFt).
inline int wmfInertRiseFt()
    { return 5; }

// the first-round leap bonus caps at 5 inches beyond 40 feet of height
// (wdvLeapCapIn).
inline int wmfLeapCapIn()
    { return 5; }

}   // namespace rules
