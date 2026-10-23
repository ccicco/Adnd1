// =========================================================================================
// Adnd1 - rules/owedpins.h
// THE OWED PINS AND THE DEITY SITE - four feeds in one round: the lance
// lengths, the spear spread, the Appendix S bridge, the closing bar
// census 704 -> 705.
//
// R780 left the lance printed lengths contract-side and the R158 spear at its
// default 7; R405 left the deity pins site-less and the Appendix S charge
// open; R781 left the DMG p.66 fold without its charging bar. R782 closes all
// four. The lance cells (10/12/14 feet, 1 foot of space required) pin as data
// from the compilation print the R189 speed-verify duty already trusts. The
// spear spread gains its length key (the 6/7/8 cells the R158 range helper
// always implied). The deity site lands as a bridge: every Appendix S stat
// block becomes a monster-side Actor - the printed hp and AC whole, the
// attack halves halved, the damage span on the dice plus the floor - and a
// live regtest site block walks all 23 blocks through it (the R405 layer
// contract flips with its audit; the five charts stay their own seam). And
// the closing bar: a mounted front in round one is a closing charge, exempt
// from the case-1 tie order and the case-2 extra window (speedFactorApplies
// reads it at last); the monster side never lance-charges - the R779 boundary
// stands - its mounted round one reads as the closing bar alone. Honest
// boundaries: the deity matrix stays on the monster HD convention (hitDice
// 1.0), the spawn path stays contract-side, no engine caller reads a lance
// length yet, and the R780 engine sense stands
//
// Zero new book pages: the lance cells ride the compilation print the R189
// duty trusts, the spear spread rides the R158 print already honored, the
// deity blocks ride the R406 stat-block pins, and the closing bar rides DMG
// p.66 already honored in weaponspeed.h
//
namespace rules {

// ---- the lance cells and the spear spread (the R782 wiring) ----

// The feeder seam this round owes: the R780 round left the printed lengths
// contract-side; the pinned cells answer it
inline int owdLanceCellsFeederRound()
    { return 780; }

// The lance space-required cell: 1 foot of frontage per the print (the
// proficiency space rule reads it)
inline int owdLanceSpaceRequiredFt()
    { return 1; }

// The light horse lance printed length: 10 feet (the compilation cell the
// R780 boundary owed)
inline int owdLightLanceLengthFt()
    { return 10; }

// The medium horse lance printed length: 12 feet (the cell behind the print's
// 6-speed quirk)
inline int owdMediumLanceLengthFt()
    { return 12; }

// The heavy horse lance printed length: 14 feet (the compilation cell)
inline int owdHeavyLanceLengthFt()
    { return 14; }

// The lance length and space-required cells ride the compilation print (the
// R780 contract-side boundary closes on the data side; no engine caller reads
// a length yet - the R780 engine sense stands)
inline bool owdLanceCellsRideThePrint()
    { return true; }

// The feeder seam the spear spread extends: the R158 ladder kept the spear at
// its default 7 - the printed spread now has its own key
inline int owdSpearSpreadFeederRound()
    { return 158; }

// The short spear cell: 5 feet and under reads the 6 factor
inline int owdSpearShortLengthFt()
    { return 5; }

// The long spear cell: 13 feet and over reads the 8 factor
inline int owdSpearLongLengthFt()
    { return 13; }

// The short spear speed factor (the spread's fast end)
inline int owdSpearShortSpeedFactor()
    { return 6; }

// The middle spear speed factor: the R158 default keeps its sense (the
// spread's middle band)
inline int owdSpearMiddleSpeedFactor()
    { return 7; }

// The long spear speed factor (the spread's slow end)
inline int owdSpearLongSpeedFactor()
    { return 8; }

// The spear 6..8 spread is pinned at last: the R158 range helper gains its
// length-keyed companion
inline bool owdSpearSpreadEndsPin()
    { return true; }

// The middle lengths keep the R158 default 7 (the name-keyed ladder and the
// length key agree there)
inline bool owdSpearMiddleKeepsDefault()
    { return true; }

// ---- the deity site and the closing bar (the R782 wiring) ----

// The deity seam round: the R405 pins precede the site, and the R782 bridge
// builds it
inline int owdDeitySeamRound()
    { return 405; }

// The bridge round: the Appendix S stat blocks become monster-side Actors
inline int owdDeityBridgeRound()
    { return 782; }

// The Appendix S stat-block census: 23 blocks ride the bridge (the R405
// registry order)
inline int owdDeityStatBlockCount()
    { return 23; }

// The deity actor site exists now - the R405 no-site contract is STRUCK (the
// bridge answers it)
inline bool owdDeitySiteExistsNow()
    { return true; }

// The bridge copies every printed cell of the stat block: the hp and AC
// whole, the halves halved, the damage span floored
inline bool owdDeityBridgeCopiesTheBlock()
    { return true; }

// The Appendix S stat-block charge closes with the bridge (the R405 open flag
// flips false; the five charts stay their own seam)
inline bool owdDeityChargeCloses()
    { return true; }

// The DMG p.66 closing bar reads the fronts: a mounted front in round one is
// a closing charge
inline bool owdChargingFrontReadsTheBar()
    { return true; }

// The charging round is exempt from the case-1 tie order (speedFactorApplies
// gates the fold)
inline bool owdChargingExemptsTheTieOrder()
    { return true; }

// The charging round is exempt from the case-2 extra-attack window (the
// round-one read joins case 1)
inline bool owdChargingExemptsTheExtraWindow()
    { return true; }

// The monster side never lance-charges (the R779 boundary stands); its
// mounted round one reads as the closing bar alone
inline bool owdMonsterSideNeverCharges()
    { return true; }

}   // namespace rules
