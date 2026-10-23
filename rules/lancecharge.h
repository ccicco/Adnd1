// =========================================================================================
// Adnd1 - rules/lancecharge.h
// THE LANCE CHARGE - the R189 feeder goes live, the three lances ride the
// registry
// census 701 -> 702.
//
// The mount arc reaches its first combat fold: R776 seated the rider, R777
// sold the horse, R778 put the company in the saddle - and now the lance
// lands. The three lances (light, medium, heavy horse) join the engine
// registry as items (the R314 deep-crossbow pattern), every cell riding the
// already-pinned R189 chart rows 24-26 (the 50/100/150 gold-piece weights,
// the S/M dice 1-6/2-7/3-9, the L dice 1-8/2-12/3-18) and the one printed PHB
// arms price (6 g.p., shared by all three kinds). The combat Actor gains
// mountKind (toActor copies it), and resolveMelee doubles the rider's
// round-one lance damage - the engine has no charge command, so the round-one
// strike reads as the charge, the mount covering the closing ground (the
// JUDGMENT, the R232 surprise-as-from-behind pattern). Honest boundaries: the
// p.38 chart carries no lance row (zero adjustment, the R145 audit extended),
// the R158 speed ladder names no lance (unknown default), and the spear
// set-to-receive needs a charging FOE - contract-side. Every touched TU
// (items, actor, party, state_combat via the battery build) is compile-gated
//
// Zero new book pages: the dice, weights and price ride the already-pinned
// R189 chart and the R300/R308 equipcosts row
//
namespace rules {

// ---- the lance charge (the R779 wiring) ----

// The feeder seam this round charges: the R189 chart asterisk - the three
// lances do twice the indicated damage from a charging mount.
inline int lncChargeFeederRound()
    { return 189; }

// The lance charge round: the three lances ride the registry, the charge fold
// lands.
inline int lncLanceChargeRound()
    { return 779; }

// The three lances: light horse, medium horse, heavy horse (the R189 chart
// rows 24-26).
inline int lncLanceRowCount()
    { return 3; }

// Twice the indicated damage when employed from a charging mount (the chart
// asterisk).
inline int lncLanceChargeMultiplier()
    { return 2; }

// The one printed PHB arms price the three lances share (the equipcosts lance
// row, 6 g.p.).
inline int lncLancePriceGold()
    { return 6; }

// The R189 asterisk goes live: a rider's round-one lance strike doubles its
// damage (ai/actor.cpp resolveMelee).
inline bool lncLancesDoubleFromChargingMount()
    { return true; }

// The engine has no charge command: the rider's round-one strike reads as the
// charge - the mount covers the closing ground (the JUDGMENT, the R232
// surprise-as-from-behind pattern).
inline bool lncRiderRoundOneReadsAsTheCharge()
    { return true; }

// The combat Actor carries mountKind (ai/actor.h; 0 = afoot).
inline bool lncActorCarriesTheMount()
    { return true; }

// Character.toActor copies the mount field into the combat actor
// (game/party.h).
inline bool lncToActorCopiesTheMount()
    { return true; }

// The three registry rows carry the R189 chart cells: the 50/100/150
// gold-piece weights, the S/M dice 1-6/2-7/3-9, the L dice 1-8/2-12/3-18.
inline bool lncLanceRowsRideTheR189Cells()
    { return true; }

// The p.38 weapon-vs-AC chart lists no lance: the zero adjustment row is the
// no-adjustment JUDGMENT (the R145 audit rows extended in the same round).
inline bool lncP38CarriesNoLanceRow()
    { return true; }

// The R158 DMG speed ladder names no lance: the speed factor rides the
// unknown default, contract-side until a pin lands.
inline bool lncLanceSpeedStaysUnknown()
    { return true; }

// The spear set-to-receive needs a charging FOE - no monster charge concept
// exists; the R189 double-asterisk pin stays contract-side.
inline bool lncSpearSetReceivesContractSide()
    { return true; }

}   // namespace rules
