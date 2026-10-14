// =========================================================================================
// Adnd1 - rules/wsgvessels.h
// The WSG MOVEMENT IN WATERBORNE VEHICLES, R455: Table 25, the WATERBORNE
// VEHICLE CHARACTERISTICS of the eight inland vessels - kayak (length 8-12,
// width 2-3, capacity 1 + 1000, large move 18/24/12/14, small move
// 160/200/120/180, enc. 600-800, startup 1-2, hull 1-2, draught 1/4), small
// canoe (10-15, 2-3, 2 + 2500, 20/30/10/12, 160/200/120/180, 700-900, 1-2,
// 1-2, 1/4), small rowboat (8-12, 2-4, 2 + 2000, 16/24/12/14, 120/180/90/120,
// 700-1000, 1-3, 1-3, 1/2), coracle (10-15, 3-5, 2 + 2000, 12/18/6/8,
// 45/60/30/45, 900-1200, 1-3, 1-2, 1/2), large canoe (15-20, 2-3, 2 + 4000,
// 20/30/10/12, 120/180/90/120, 1000-1200, 1-3, 2-3, 1/3), large rowboat
// (15-20, 3-4, 4 + 4000, 16/24/8/10, 45/90/45/60, 1200-1600, 2-5, 2-4, 3/4),
// small barge (15-20, 8-12, 4 + 6000, 16/24/8/9, 45/60/30/45, 4000-6000, 2-6,
// 1-6, 3/4) and large barge (25-45, 12-20, 6 + 7500, 8/16/4/5, 30/60/20/30,
// 10000+, 5-10, 2-8, draught 1). Large move is miles per half-day under
// normal sail, maximum sail, normal oar and maximum oar; small move is feet
// per round under the same four. The modifications: if the water is moving
// the vessel drifts with the current at that speed - downstream the normal
// sail or normal oar rate ADDS the current, upstream the current is DEDUCTED
// and maximum sail or oar may be needed for headway. Normal sail assumes
// movement in the direction of the wind blowing between 20 and 30 miles per
// hour: subtract 1 inch (one mile per half-day or 10 feet per round) for each
// 10 mph of wind below 20, add 2 inches for each 10 mph above 30 - and a
// vessel cannot be successfully sailed if the wind is less than 5 miles per
// hour. Maximum sail applies when moving at RIGHT ANGLES to the wind, with
// the same wind-speed modifiers; a vessel sailed INTO the wind has its normal
// sail rate reduced by 3 inches per 10 mph of wind speed, to a minimum of 1
// inch in any case. The maximum oar rate is extremely strenuous: a character
// must rest or row at the normal rate for one turn after two turns of such
// effort or risk fatigue - a fatigued oarsman can only propel the craft at
// HALF normal speed, and if forced to row at normal speed he becomes
// exhausted after one turn. A craft can be rowed by fewer characters than the
// capacity figure, but only at a PROPORTIONATE fraction of its movement rate
// - the printed example: three people rowing a large rowboat travel 6 miles
// in eight hours at normal oar (three-quarters of 8) or 45 feet per round at
// maximum oar (three-quarters of 60). All these rates and modifiers assume at
// least one character aboard with proficiency in boating. The rules cover
// only inland-waterway vessels - galleys, merchant ships and warships are out
// of scope. Census 379 -> 380.
// census 379 -> 380.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 44 with
// the movement-modification prose continuing on p. 45; the user own copy OCR
// (pages 45-46) cross-checked against the archive djvu word layer
// (Guide_0044, Guide_0045) - the prose reads clean two-way, but the djvu
// TRUNCATES the printed Table 25 (only six of eight rows, the draught column
// garbled, the barge rows missing), so the grid was settled by TWO
// independent IIIF eye-reads of leaf $44, which agree with the OCR exactly on
// all eight rows and every cell, including the 10000+ open-ended encumbrance
// of the large barge.
//
// Eight boats for the inland waters, from the one-man kayak to the 45-foot
// barge: four move rates apiece - sail and oar, normal and maximum - plus
// capacity, encumbrance, startup, hull and draught. Drift with the current,
// add it going down, lose it going up; sail best at right angles to a
// 20-to-30-mile wind, lose 3 inches rowing into it, none at all under 5; row
// hard for two turns, rest for one, or row short-handed at a fraction - three
// men in a large rowboat make 6 miles a half-day and 45 feet a round.
//
namespace rules {

// ---- the vessel grid ----

// Table 25 lists eight waterborne vehicles: kayak, small canoe, small
// rowboat, coracle, large canoe, large rowboat, small barge and large barge.
inline int wvbVesselCount()
    { return 8; }

// These rules are limited to vessels normally found on inland waterways,
// primarily lakes and rivers; galleys, merchant ships and warships are
// seagoing vessels and out of scope.
inline bool wvbInlandVesselsOnly()
    { return true; }

// The capacity figures assume cargo and passengers are distributed evenly in
// or on the vessel; a rowboat loaded too heavily on one side will capsize
// fairly easily even under its limit.
inline bool wvbLoadDistributedEvenly()
    { return true; }

// The maximum-oar figures are relatively low because the accelerated movement
// can only be maintained for short periods, so the gain in mileage over time
// is small.
inline bool wvbMaxOarLowGainRationale()
    { return true; }

// If a craft is operated in water the same depth as its draught figure, there
// may be a chance (at the DM discretion) of hull damage, particularly for a
// less sturdy type such as a kayak or coracle.
inline bool wvbDraughtHullDamageRisk()
    { return true; }

// The minimum vessel length in feet: 8, 10, 8, 10, 15, 15, 15, 25.
inline int wvbLenMin(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 10;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 15;
        case 6:
            return 15;
        case 7:
            return 25;
        default:
            return 0;
        }
    }

// The maximum vessel length in feet: 12, 15, 12, 15, 20, 20, 20, 45.
inline int wvbLenMax(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 45;
        default:
            return 0;
        }
    }

// The minimum vessel width in feet: 2, 2, 2, 3, 2, 3, 8, 12.
inline int wvbWidMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 8;
        case 7:
            return 12;
        default:
            return 0;
        }
    }

// The maximum vessel width in feet: 3, 3, 4, 5, 3, 4, 12, 20.
inline int wvbWidMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 12;
        case 7:
            return 20;
        default:
            return 0;
        }
    }

// The comfortable passenger capacity: 1, 2, 2, 2, 2, 4, 4, 6.
inline int wvbCapPax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 6;
        default:
            return 0;
        }
    }

// The cargo encumbrance value in gold pieces: 1000, 2500, 2000, 2000, 4000,
// 4000, 6000, 7500.
inline int wvbCapGp(int b)
    {
        switch (b) {
        case 0:
            return 1000;
        case 1:
            return 2500;
        case 2:
            return 2000;
        case 3:
            return 2000;
        case 4:
            return 4000;
        case 5:
            return 4000;
        case 6:
            return 6000;
        case 7:
            return 7500;
        default:
            return 0;
        }
    }

// The minimum encumbrance value in gold pieces: 600, 700, 700, 900, 1000,
// 1200, 4000, 10000.
inline int wvbEncMin(int b)
    {
        switch (b) {
        case 0:
            return 600;
        case 1:
            return 700;
        case 2:
            return 700;
        case 3:
            return 900;
        case 4:
            return 1000;
        case 5:
            return 1200;
        case 6:
            return 4000;
        case 7:
            return 10000;
        default:
            return 0;
        }
    }

// The maximum encumbrance value in gold pieces: 800, 900, 1000, 1200, 1200,
// 1600, 6000, 0 - the 0 marks the large barge open-ended 10000+.
inline int wvbEncMax(int b)
    {
        switch (b) {
        case 0:
            return 800;
        case 1:
            return 900;
        case 2:
            return 1000;
        case 3:
            return 1200;
        case 4:
            return 1200;
        case 5:
            return 1600;
        case 6:
            return 6000;
        case 7:
            return 0;
        default:
            return 0;
        }
    }

// The minimum startup time in rounds to normal speed: 1, 1, 1, 1, 1, 2, 2, 5.
inline int wvbSuMin(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 5;
        default:
            return 0;
        }
    }

// The maximum startup time in rounds to maximum speed: 2, 2, 3, 3, 3, 5, 6,
// 10.
inline int wvbSuMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 10;
        default:
            return 0;
        }
    }

// The minimum hull value: 1, 1, 1, 1, 2, 2, 1, 2.
inline int wvbHullMin(int b)
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
            return 1;
        case 7:
            return 2;
        default:
            return 0;
        }
    }

// The maximum hull value: 2, 2, 3, 2, 3, 4, 6, 8.
inline int wvbHullMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 8;
        default:
            return 0;
        }
    }

// The draught numerator in feet: 1, 1, 1, 1, 1, 3, 3, 1.
inline int wvbDrNum(int b)
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
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        default:
            return 0;
        }
    }

// The draught denominator in feet: 4, 4, 2, 2, 3, 4, 4, 1.
inline int wvbDrDen(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 1;
        default:
            return 0;
        }
    }

// The large-scale normal sail rate, miles per half-day: 18, 20, 16, 12, 20,
// 16, 16, 8.
inline int wvbLgSailN(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 20;
        case 2:
            return 16;
        case 3:
            return 12;
        case 4:
            return 20;
        case 5:
            return 16;
        case 6:
            return 16;
        case 7:
            return 8;
        default:
            return 0;
        }
    }

// The large-scale maximum sail rate, miles per half-day: 24, 30, 24, 18, 30,
// 24, 24, 16.
inline int wvbLgSailM(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 30;
        case 2:
            return 24;
        case 3:
            return 18;
        case 4:
            return 30;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 16;
        default:
            return 0;
        }
    }

// The large-scale normal oar rate, miles per half-day: 12, 10, 12, 6, 10, 8,
// 8, 4.
inline int wvbLgOarN(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 12;
        case 3:
            return 6;
        case 4:
            return 10;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 4;
        default:
            return 0;
        }
    }

// The large-scale maximum oar rate, miles per half-day: 14, 12, 14, 8, 12,
// 10, 9, 5.
inline int wvbLgOarM(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 8;
        case 4:
            return 12;
        case 5:
            return 10;
        case 6:
            return 9;
        case 7:
            return 5;
        default:
            return 0;
        }
    }

// The small-scale normal sail rate, feet per round: 160, 160, 120, 45, 120,
// 45, 45, 30.
inline int wvbSmSailN(int b)
    {
        switch (b) {
        case 0:
            return 160;
        case 1:
            return 160;
        case 2:
            return 120;
        case 3:
            return 45;
        case 4:
            return 120;
        case 5:
            return 45;
        case 6:
            return 45;
        case 7:
            return 30;
        default:
            return 0;
        }
    }

// The small-scale maximum sail rate, feet per round: 200, 200, 180, 60, 180,
// 90, 60, 60.
inline int wvbSmSailM(int b)
    {
        switch (b) {
        case 0:
            return 200;
        case 1:
            return 200;
        case 2:
            return 180;
        case 3:
            return 60;
        case 4:
            return 180;
        case 5:
            return 90;
        case 6:
            return 60;
        case 7:
            return 60;
        default:
            return 0;
        }
    }

// The small-scale normal oar rate, feet per round: 120, 120, 90, 30, 90, 45,
// 30, 20.
inline int wvbSmOarN(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 120;
        case 2:
            return 90;
        case 3:
            return 30;
        case 4:
            return 90;
        case 5:
            return 45;
        case 6:
            return 30;
        case 7:
            return 20;
        default:
            return 0;
        }
    }

// The small-scale maximum oar rate, feet per round: 180, 180, 120, 45, 120,
// 60, 45, 30.
inline int wvbSmOarM(int b)
    {
        switch (b) {
        case 0:
            return 180;
        case 1:
            return 180;
        case 2:
            return 120;
        case 3:
            return 45;
        case 4:
            return 120;
        case 5:
            return 60;
        case 6:
            return 45;
        case 7:
            return 30;
        default:
            return 0;
        }
    }

// ---- the movement modifications ----

// All the given movement rates and the modifiers in this section assume the
// presence on board of at least one character with proficiency in boating.
inline bool wvbProficiencyAssumed()
    { return true; }

// If the water is moving, a vessel will drift with the current at that speed.
inline bool wvbCurrentDrift()
    { return true; }

// If the craft is sailed or rowed while moving downstream, the normal sail or
// normal oar rate is added to the speed of the current to determine the
// actual movement rate.
inline bool wvbCurrentAddsDownstream()
    { return true; }

// The converse applies against the current: the speed of the water is
// deducted from the given movement rate, and maximum sail or maximum oar may
// be necessary to make headway.
inline bool wvbCurrentSubtractsUpstream()
    { return true; }

// The normal sail rates assume the craft is being moved in the direction of
// the wind.
inline bool wvbSailAssumesWindDirection()
    { return true; }

// The normal sail rates assume the craft is moved in the direction of the
// wind, and that the wind is blowing between 20 and 30 miles per hour.
inline int wvbWindBandMin()
    { return 20; }

// The top of the assumed wind band for normal sail: 20 to 30 miles per hour.
inline int wvbWindBandMax()
    { return 30; }

// Subtract 1 inch (one mile per half-day or 10 feet per round) for each 10
// miles per hour of wind speed less than 20.
inline int wvbWindLowStep()
    { return 1; }

// Add 2 inches for each 10 miles per hour of wind speed greater than 30.
inline int wvbWindHighStep()
    { return 2; }

// One inch of vessel movement is one mile per half-day of eight hours on the
// large scale.
inline int wvbInchPerHalfDayMiles()
    { return 1; }

// One inch of vessel movement is 10 feet per round on the small scale.
inline int wvbInchPerRoundFt()
    { return 10; }

// A vessel cannot be successfully sailed if the wind is less than 5 miles per
// hour.
inline bool wvbNoSailBelowMinWind()
    { return true; }

// A vessel cannot be successfully sailed if the wind is less than 5 miles per
// hour.
inline int wvbMinSailWind()
    { return 5; }

// The maximum sail rate applies if a vessel is moving at right angles to the
// wind, with the same wind-speed modifiers for below 20 or above 30 miles per
// hour.
inline bool wvbMaxSailRightAngles()
    { return true; }

// A vessel being sailed into the wind has its normal sail rate reduced by 3
// inches per 10 miles per hour of wind speed, to a minimum of 1 inch in any
// case.
inline bool wvbIntoWindReduced()
    { return true; }

// A vessel being sailed into the wind has its normal sail rate reduced by 3
// inches for each 10 miles per hour of wind speed.
inline int wvbIntoWindStep()
    { return 3; }

// The into-wind reduction bottoms out: the normal sail rate has a minimum of
// 1 inch (1 mile per eight hours or 10 feet per round) in any case.
inline int wvbIntoWindMinIn()
    { return 1; }

// ---- the oarsmen ----

// Traveling at the maximum oar rate is considered extremely strenuous
// activity for any character engaged in propelling the craft.
inline bool wvbMaxOarStrenuous()
    { return true; }

// Traveling at the maximum oar rate is considered extremely strenuous
// activity: the effort can be maintained for two turns before rest is
// required.
inline int wvbMaxOarEffortTurns()
    { return 2; }

// After two turns of maximum-oar effort the character must rest, or simply
// row at the normal rate, for one turn, or run the risk of becoming fatigued
// and subsequently exhausted.
inline int wvbMaxOarRestTurns()
    { return 1; }

// A fatigued oarsman or paddler can only propel his craft at half normal
// speed until his condition is alleviated.
inline bool wvbFatiguedHalfSpeed()
    { return true; }

// An oarsman or paddler who becomes fatigued can only propel his craft at
// half normal speed until his condition is alleviated.
inline int wvbFatiguedSpeedDiv()
    { return 2; }

// If a fatigued oarsman is forced to continue rowing at normal speed, he will
// automatically become exhausted after one turn of such activity.
inline bool wvbFatiguedForcedExhaust()
    { return true; }

// If a fatigued oarsman is forced to continue rowing at normal speed, he will
// automatically become exhausted after one turn of such activity.
inline int wvbFatiguedExhaustTurns()
    { return 1; }

// A craft can be rowed or paddled by fewer characters than the capacity
// figure, but the vessel can only be moved at a proportionate fraction of its
// movement rate.
inline bool wvbShorthandedProportional()
    { return true; }

// The printed example: three people row a large rowboat, one fewer than the
// four listed under its capacity figure.
inline int wvbExRowers()
    { return 3; }

// The printed example: three people rowing a large rowboat can only travel 6
// miles in eight hours at the normal oar rate - three-quarters of the 8-mile
// figure.
inline int wvbExNormalOarMiles()
    { return 6; }

// The printed example: the same three rowers travel 45 feet per round in
// small-scale movement under the maximum oar rate - three-quarters of the
// 60-foot figure.
inline int wvbExMaxOarFt()
    { return 45; }

}   // namespace rules
