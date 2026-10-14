// =========================================================================================
// Adnd1 - rules/wsgflymounts.h
// The WSG FLYING MOUNTS, R460: using a flying mount changes the way a
// character looks at things - terrain becomes scenery and long distance takes
// on a new meaning, but there is no place to hide from arrows, hailstones or
// lightning, and falling out of a saddle several hundred feet up is more than
// momentary discomfort. Table 27, the CHARACTERISTICS OF FLYING MOUNTS, in
// four categories: A, dragons and dragonlike creatures - black dragon
// 9000/18000 at 24/12 with stamina 24/6, blue and bronze 15000/30000 with
// 27/6, brass as the black, celestial 5000/10000 at 48/24 with 12/6, cloud
// dragon 18000/36000 at 39/18 with 30/6 (ridden only in solid form, as the
// mist dragon 18000/36000 at 33/15 with the same stamina), coiled 3000/4500
// at 12/6, copper 12000/24000, dracolisk 3000/5000 at 15/6 with 2/1, dragonne
// 1500 at a single 9 rate with 2/1, dragonnel 6000/10000 at 18/9 MC D with
// 12/3, earth 2000/3000, gold 21000/42000 at 30/15 with 30/6, green
// 12000/18000, red and silver 18000/36000 with 30/6, spirit 4000/6500 at
// 12/6, white 6000/12000 at 30/15 with 18/6, and wyvern 10000/20000 at 24/12
// with 18/6; B, birds and birdlike - boobrie 1000/1500 at 15/9 with the
// unusual 3/3 stamina, giant eagle 1000/1500 at 48/18 with 9/3, pteranodon
// 1500 at a single 15 rate MC D with 2/1, giant pterosaur 2000 at a single 12
// rate with 3/1, roc 50000/100000 at 30/15 with 30/6, and giant vulture
// 1000/1500 at 24/12 with 3/2; C, winged mammals - chimera 4500 at a single
// 18 rate with 12/3, griffon 5500/8000 at 30/15 MC D with 18/6, gorgimera
// 5000 at a single 15 rate, hippogriff 4000/6000 at 36/18 MC D with 15/3,
// manticore 3000 at a single 18 rate with 6/3, opinicus 1000/1500 at 30/15 MC
// C with 3/1, and pegasus 4000/6500 at 48/24 MC D with 12/3; D, other
// fantastic - aarakocra 1500 at a single 36 rate MC D with 3/2, androsphinx
// 7500/9500 with 18/6, criosphinx 7000/9000 with 15/6, dragon horse 3000/5000
// at 48/24 MC C with 12/3, gynosphinx 5000/8000 with 15/6, hieracosphinx
// 7000/8500 at 36/18 with 18/6, giant mantis 2000/3000 at 12/6 with 6/3, and
// yeth hound 2000/3000 at 27/12 MC C with 9/3. The columns: normal load is
// the encumbrance carried at the full rate; maximum load is the greatest load
// while aloft (a dash means normal is also maximum; anything more and the
// mount is unable or unwilling to leave the ground, or plummets to the
// nearest landing spot); the move rate is full/reduced in miles per half-day
// (a 0 right of the slash means one rate always); the MC when ridden is
// always one class lower than natural, except E which cannot be reduced; and
// the stamina is safe turns aloft / turns of rest, with the over-normal-load
// flying time cut by one turn or one-third of normal, whichever is greater
// (inapplicable to dash creatures, which cannot fly at all over their normal
// load). The listed mounts come from the Monster Manual, the Fiend Folio, and
// Monster Manual II: native to the Prime Material, normally found in a
// wilderness, and size M or L able to carry through the air; the DM assigns
// stats for unlisted creatures using the table as a guide. Trained mounts are
// not easy to find and not cheap; an untrained uncooperative beast can be
// ridden but the rider is at its mercy. A coerced mount may refuse loads, fly
// slowly, or insist on rest - full benefit requires willingness. Feeding:
// most need at least triple rations daily, up to fifty rations for one of the
// biggest dragon types, and the specialized appetites (the manticore
// preferring human flesh) may force hunting with the mount. Loads need saddle
// and containers, ideally distributed evenly on both sides; a load twice as
// heavy on one side doubles its entire encumbrance value.
// census 384 -> 385.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 47-48;
// the user own copy OCR (pages 48-49) cross-checked against the archive djvu
// word layer (Guide_0047/0048) - the djvu GARBLES the Table 27 word layer
// (rows misaligned, labels and values dropped), so the grid was settled by
// TWO independent IIIF eye-reads of leaf $47 which agree with the OCR exactly
// on all 41 rows and all 7 columns - with the cloud dragon move rate resolved
// at high resolution (native 2411px crop) as 39/18, the bulk 1600px reads
// misresolving the 9 as a 3, as both text layers read 39.
//
namespace rules {

// ---- the category A grid ----

// Category A, the dragons and dragonlike creatures: black, blue, brass,
// bronze, celestial, cloud, coiled, copper, dracolisk, dragonne, dragonnel,
// earth, gold, green, mist, red, silver, spirit, white and wyvern.
inline int wfmCatACount()
    { return 20; }

// the normal load in gold pieces - the encumbrance the creature carries and
// still flies at its full rate
inline int wfmANorm(int b)
    {
        switch (b) {
        case 0:
            return 9000;
        case 1:
            return 15000;
        case 2:
            return 9000;
        case 3:
            return 15000;
        case 4:
            return 5000;
        case 5:
            return 18000;
        case 6:
            return 3000;
        case 7:
            return 12000;
        case 8:
            return 3000;
        case 9:
            return 1500;
        case 10:
            return 6000;
        case 11:
            return 2000;
        case 12:
            return 21000;
        case 13:
            return 12000;
        case 14:
            return 18000;
        case 15:
            return 18000;
        case 16:
            return 18000;
        case 17:
            return 4000;
        case 18:
            return 6000;
        case 19:
            return 10000;
        default:
            return 0;
        }
    }

// the maximum load - the greatest encumbrance it can carry aloft; the printed
// dash means normal = maximum (encoded directly)
inline int wfmAMax(int b)
    {
        switch (b) {
        case 0:
            return 18000;
        case 1:
            return 30000;
        case 2:
            return 18000;
        case 3:
            return 30000;
        case 4:
            return 10000;
        case 5:
            return 36000;
        case 6:
            return 4500;
        case 7:
            return 24000;
        case 8:
            return 5000;
        case 9:
            return 1500;
        case 10:
            return 10000;
        case 11:
            return 3000;
        case 12:
            return 42000;
        case 13:
            return 18000;
        case 14:
            return 36000;
        case 15:
            return 36000;
        case 16:
            return 36000;
        case 17:
            return 6500;
        case 18:
            return 12000;
        case 19:
            return 20000;
        default:
            return 0;
        }
    }

// the full normal flying move rate in miles per half-day
inline int wfmAMove(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 24;
        case 4:
            return 48;
        case 5:
            return 39;
        case 6:
            return 12;
        case 7:
            return 24;
        case 8:
            return 15;
        case 9:
            return 9;
        case 10:
            return 18;
        case 11:
            return 24;
        case 12:
            return 30;
        case 13:
            return 24;
        case 14:
            return 33;
        case 15:
            return 24;
        case 16:
            return 24;
        case 17:
            return 12;
        case 18:
            return 30;
        case 19:
            return 24;
        default:
            return 0;
        }
    }

// the reduced move rate when burdened above a normal load; 0 means a single
// rate creature
inline int wfmAMoveRed(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 24;
        case 5:
            return 18;
        case 6:
            return 6;
        case 7:
            return 12;
        case 8:
            return 6;
        case 9:
            return 0;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 15;
        case 13:
            return 12;
        case 14:
            return 15;
        case 15:
            return 12;
        case 16:
            return 12;
        case 17:
            return 6;
        case 18:
            return 15;
        case 19:
            return 12;
        default:
            return 0;
        }
    }

// the maneuverability class when carrying a rider or equipment, on the
// A=1..E=5 scale
inline int wfmAMc(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        default:
            return 0;
        }
    }

// the consecutive turns the creature can safely remain aloft with a normal
// load
inline int wfmASta(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 27;
        case 2:
            return 24;
        case 3:
            return 27;
        case 4:
            return 12;
        case 5:
            return 30;
        case 6:
            return 9;
        case 7:
            return 24;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 12;
        case 11:
            return 9;
        case 12:
            return 30;
        case 13:
            return 24;
        case 14:
            return 30;
        case 15:
            return 30;
        case 16:
            return 30;
        case 17:
            return 9;
        case 18:
            return 18;
        case 19:
            return 18;
        default:
            return 0;
        }
    }

// the turns of rest needed between flights to retain full strength and
// capacity
inline int wfmARest(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 6;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// The cloud dragon and the mist dragon can only be ridden when in solid form.
inline bool wfmCloudMistSolidFormOnly()
    { return true; }

// ---- the category B grid ----

// Category B, the birds and birdlike creatures: boobrie, giant eagle,
// pteranodon, giant pterosaur, roc and giant vulture.
inline int wfmCatBCount()
    { return 6; }

// the normal load in gold pieces - the encumbrance the creature carries and
// still flies at its full rate
inline int wfmBNorm(int b)
    {
        switch (b) {
        case 0:
            return 1000;
        case 1:
            return 1000;
        case 2:
            return 1500;
        case 3:
            return 2000;
        case 4:
            return 50000;
        case 5:
            return 1000;
        default:
            return 0;
        }
    }

// the maximum load - the greatest encumbrance it can carry aloft; the printed
// dash means normal = maximum (encoded directly)
inline int wfmBMax(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 1500;
        case 2:
            return 1500;
        case 3:
            return 2000;
        case 4:
            return 100000;
        case 5:
            return 1500;
        default:
            return 0;
        }
    }

// the full normal flying move rate in miles per half-day
inline int wfmBMove(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 48;
        case 2:
            return 15;
        case 3:
            return 12;
        case 4:
            return 30;
        case 5:
            return 24;
        default:
            return 0;
        }
    }

// the reduced move rate when burdened above a normal load; 0 means a single
// rate creature
inline int wfmBMoveRed(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 12;
        default:
            return 0;
        }
    }

// the maneuverability class when carrying a rider or equipment, on the
// A=1..E=5 scale
inline int wfmBMc(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        default:
            return 0;
        }
    }

// the consecutive turns the creature can safely remain aloft with a normal
// load
inline int wfmBSta(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 9;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 30;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// the turns of rest needed between flights to retain full strength and
// capacity
inline int wfmBRest(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 6;
        case 5:
            return 2;
        default:
            return 0;
        }
    }

// ---- the category C grid ----

// Category C, the winged mammalian creatures: chimera, griffon, gorgimera,
// hippogriff, manticore, opinicus and pegasus.
inline int wfmCatCCount()
    { return 7; }

// the normal load in gold pieces - the encumbrance the creature carries and
// still flies at its full rate
inline int wfmCNorm(int b)
    {
        switch (b) {
        case 0:
            return 4500;
        case 1:
            return 5500;
        case 2:
            return 5000;
        case 3:
            return 4000;
        case 4:
            return 3000;
        case 5:
            return 1000;
        case 6:
            return 4000;
        default:
            return 0;
        }
    }

// the maximum load - the greatest encumbrance it can carry aloft; the printed
// dash means normal = maximum (encoded directly)
inline int wfmCMax(int b)
    {
        switch (b) {
        case 0:
            return 4500;
        case 1:
            return 8000;
        case 2:
            return 5000;
        case 3:
            return 6000;
        case 4:
            return 3000;
        case 5:
            return 1500;
        case 6:
            return 6500;
        default:
            return 0;
        }
    }

// the full normal flying move rate in miles per half-day
inline int wfmCMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 30;
        case 2:
            return 15;
        case 3:
            return 36;
        case 4:
            return 18;
        case 5:
            return 30;
        case 6:
            return 48;
        default:
            return 0;
        }
    }

// the reduced move rate when burdened above a normal load; 0 means a single
// rate creature
inline int wfmCMoveRed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 18;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 24;
        default:
            return 0;
        }
    }

// the maneuverability class when carrying a rider or equipment, on the
// A=1..E=5 scale
inline int wfmCMc(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 4;
        default:
            return 0;
        }
    }

// the consecutive turns the creature can safely remain aloft with a normal
// load
inline int wfmCSta(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 9;
        case 3:
            return 15;
        case 4:
            return 6;
        case 5:
            return 3;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// the turns of rest needed between flights to retain full strength and
// capacity
inline int wfmCRest(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// ---- the category D grid ----

// Category D, the other fantastic creatures: aarakocra, androsphinx,
// criosphinx, dragon horse, gynosphinx, hieracosphinx, giant mantis and yeth
// hound.
inline int wfmCatDCount()
    { return 8; }

// The four categories total 41 flying mounts, drawn from the Monster Manual,
// the Fiend Folio and Monster Manual II.
inline int wfmTotalCreatures()
    { return 41; }

// the normal load in gold pieces - the encumbrance the creature carries and
// still flies at its full rate
inline int wfmDNorm(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 7500;
        case 2:
            return 7000;
        case 3:
            return 3000;
        case 4:
            return 5000;
        case 5:
            return 7000;
        case 6:
            return 2000;
        case 7:
            return 2000;
        default:
            return 0;
        }
    }

// the maximum load - the greatest encumbrance it can carry aloft; the printed
// dash means normal = maximum (encoded directly)
inline int wfmDMax(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 9500;
        case 2:
            return 9000;
        case 3:
            return 5000;
        case 4:
            return 8000;
        case 5:
            return 8500;
        case 6:
            return 3000;
        case 7:
            return 3000;
        default:
            return 0;
        }
    }

// the full normal flying move rate in miles per half-day
inline int wfmDMove(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 30;
        case 2:
            return 24;
        case 3:
            return 48;
        case 4:
            return 24;
        case 5:
            return 36;
        case 6:
            return 12;
        case 7:
            return 27;
        default:
            return 0;
        }
    }

// the reduced move rate when burdened above a normal load; 0 means a single
// rate creature
inline int wfmDMoveRed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 24;
        case 4:
            return 12;
        case 5:
            return 18;
        case 6:
            return 6;
        case 7:
            return 12;
        default:
            return 0;
        }
    }

// the maneuverability class when carrying a rider or equipment, on the
// A=1..E=5 scale
inline int wfmDMc(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 3;
        default:
            return 0;
        }
    }

// the consecutive turns the creature can safely remain aloft with a normal
// load
inline int wfmDSta(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 18;
        case 2:
            return 15;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 18;
        case 6:
            return 6;
        case 7:
            return 9;
        default:
            return 0;
        }
    }

// the turns of rest needed between flights to retain full strength and
// capacity
inline int wfmDRest(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return 0;
        }
    }

// ---- the column definitions ----

// A mount asked to carry more than its maximum load will be unable or
// unwilling to leave the ground.
inline bool wfmOverMaxNeverLifts()
    { return true; }

// A mount already aloft when overloaded will immediately plummet toward the
// nearest landing spot.
inline bool wfmOverMaxPlummets()
    { return true; }

// A printed dash for maximum load means the normal load is also the maximum
// load.
inline bool wfmDashMaxEqualsNormal()
    { return true; }

// A creature with no maximum-load rating cannot fly at all if its normal load
// amount is exceeded.
inline bool wfmDashCannotFlyOverNormal()
    { return true; }

// The right-of-slash reduced move rate goes into effect whenever the mount is
// burdened above a normal load.
inline bool wfmReducedRateWhenOverloaded()
    { return true; }

// A 0 right of the slash means the creature has only one movement rate, which
// always applies as long as it is able and willing to fly.
inline bool wfmZeroRateMeansSingleRate()
    { return true; }

// ---- the maneuverability and stamina rules ----

// The MC when carrying a rider or equipment is always one class lower than
// the natural class.
inline int wfmMcRiddenDrop()
    { return 1; }

// A natural maneuverability class of E (5 on the A=1..E=5 scale) cannot be
// reduced any further.
inline int wfmMcFloor()
    { return 5; }

// The MC when ridden is one class lower than natural (B to C, C to D, and so
// on).
inline bool wfmMcDropsWhenRidden()
    { return true; }

// Beasts with a natural MC of E keep class E when ridden - it cannot be
// reduced any further.
inline bool wfmMcEStaysE()
    { return true; }

// Carrying more than a normal load cuts the safe flying time by one turn...
inline int wfmOverloadStaCutTurns()
    { return 1; }

// ...or by one-third of the normal stamina rating, whichever is greater.
inline int wfmOverloadStaThird()
    { return 3; }

// The over-normal-load safe-time cut is the greater of one turn and one-third
// of the normal stamina rating.
inline bool wfmStaCutIsGreaterOf()
    { return true; }

// The right stamina figure is the turns of rest needed between flights to
// retain full strength and carrying capacity.
inline bool wfmStaRestBetweenFlights()
    { return true; }

// ---- the listing criteria ----

// Listing criterion: the creature is native to, or normally found on, the
// Prime Material Plane.
inline bool wfmListedIfPrimeMaterial()
    { return true; }

// Listing criterion: the creature is normally found in a wilderness, not a
// subterranean, environment.
inline bool wfmListedIfWildernessNative()
    { return true; }

// Listing criterion: the creature is size M or L with a physical form able to
// carry passengers or objects through the air.
inline bool wfmListedIfSizeMOrL()
    { return true; }

// For an unlisted creature serving as aerial transport, the DM assigns
// statistics using its game description and the table as guidelines.
inline bool wfmDmAssignsUnlistedStats()
    { return true; }

// ---- the training and willingness rules ----

// Creatures trained for use as mounts may not be easy to locate, and they
// will not come cheap.
inline bool wfmTrainedScarceAndDear()
    { return true; }

// An untrained uncooperative creature can still be ridden, but without
// magical assistance the rider is completely at the mercy of the beast, which
// goes where it wants and will not voluntarily keep the rider aboard.
inline bool wfmUntrainedAtMercy()
    { return true; }

// A beast forced to serve against its will may refuse to carry more than its
// coercer, may fly more slowly, or may insist on more frequent rest.
inline bool wfmCoercedMaySkimp()
    { return true; }

// Full benefit in carrying capacity, movement, maneuverability and stamina
// requires a willing mount, even if the willingness is temporary and
// artificially induced.
inline bool wfmFullBenefitNeedsWillingness()
    { return true; }

// ---- the feeding and load rules ----

// Most flying mounts need at least triple rations of food and water each day
// compared to a human.
inline int wfmRationsMultiple()
    { return 3; }

// One of the biggest dragon types may need as much as fifty rations per day.
inline int wfmBigDragonRations()
    { return 50; }

// A flying mount will rarely carry equipment or cargo that is not contained -
// a bare treasure chest brings at least a movement reduction.
inline bool wfmLoadsNeedContainers()
    { return true; }

// The encumbrance value of the load rises with the side imbalance: doubled
// when one side carries twice the other, and so forth.
inline bool wfmUnevenLoadRaisesEnc()
    { return true; }

}   // namespace rules
