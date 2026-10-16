// =========================================================================================
// Adnd1 - rules/wsgrecon.h
// The WSG GAP RECONCILIATION, R496: the bookkeeping round that closes the
// distance between the gap report and the landed pins. The WSG arc rounds
// R425-R495 pinned every section of the book, but twenty-four boxes were
// never ticked: eleven chapter parents whose children all closed, nine
// manifest table lines whose grids landed with their chapter rounds, and the
// four movement items that pin inside the R435/R434/R432 headers.
// census 420 -> 421.
//
// This round pins no new book material: every flipped box is verified against
// its landed original (rules/wsgenvfx.h, wsgencum.h, wsgvehicle.h,
// wsgclimb.h, wsggrap.h, wsgchasm.h, wsgjump.h, wsgvis.h, wsgswim.h,
// wsgvessels.h, wsgcapsizing.h, wsgflymounts.h, wsgmount.h and the chapter
// headers). What remains open after this round: the overview chapter (pp.
// 7-10, eleven boxes - the seven terrain descriptions, the hierarchy of
// terrain, the bodies of water, the climate) and the wilderness proficiencies
// prose (pp. 11-17, four boxes - the nonweapon list, the choosing-skills
// rules, the proficiency descriptions).
//
// THE SETTLE: the gap report lands at 171 closed / 15 open, every open box a
// genuinely un-pinned prose stretch; census 420 -> 421.
//
namespace rules {

// ---- the reconciliation opener ----

// the gap report at the R495 landing reads 147 closed boxes.
inline int wgrClosedBefore()
    { return 147; }

// the gap report at the R495 landing reads 39 open boxes.
inline int wgrOpenBefore()
    { return 39; }

// this round flips twenty-four boxes that were already pinned by earlier
// rounds but never ticked.
inline int wgrFlippedCount()
    { return 24; }

// after this round the report reads 171 closed boxes.
inline int wgrClosedAfter()
    { return 171; }

// after this round the report reads 15 open boxes - every one a genuinely
// un-pinned prose stretch.
inline int wgrOpenAfter()
    { return 15; }

// the audit census at the R495 landing.
inline int wgrCensusBefore()
    { return 420; }

// the audit census after this round.
inline int wgrCensusAfter()
    { return 421; }

// ---- the flipped classes ----

// eleven chapter parents flip - each with every child already closed by a
// landed round.
inline int wgrChapterParents()
    { return 11; }

// nine manifest table lines flip - Tables 20-27 and 42, each pinned with its
// chapter round.
inline int wgrManifestLines()
    { return 9; }

// three climbing items flip - the surface types, the surface conditions and
// the chance of falling.
inline int wgrClimbItems()
    { return 3; }

// the movement across special terrain item flips - the vehicle and snow rules
// of R434/R432.
inline int wgrSpecialTerrainItems()
    { return 1; }

// ---- the open remainder ----

// the overview chapter keeps eleven open boxes - the parent and its ten
// children (pp. 7-10).
inline int wgrOverviewOpen()
    { return 11; }

// the wilderness proficiencies chapter keeps four open boxes - the parent,
// the nonweapon list, the choosing rules and the descriptions (pp. 11-17).
inline int wgrProficienciesOpen()
    { return 4; }

// ---- the flipped chapter parents ----

// effects of the environment: every child closed by R427, R429, R430 and
// R431.
inline bool wgrEnvFxParentOk()
    { return true; }

// encumbrance and movement: every child closed by R432 through R450 (and the
// four R496 flips below).
inline bool wgrEncumMoveParentOk()
    { return true; }

// food and water: every child closed by R462 through R470.
inline bool wgrFoodWaterParentOk()
    { return true; }

// camping and campfires: every child closed by R471 through R477.
inline bool wgrCampParentOk()
    { return true; }

// medicine and first aid: every child closed by R478 through R481.
inline bool wgrMedicineParentOk()
    { return true; }

// vision and visibility: every child closed by R482 through R485.
inline bool wgrVisionParentOk()
    { return true; }

// natural hazards: every child closed by R486 and R487.
inline bool wgrHazardsParentOk()
    { return true; }

// wilderness combat: every child closed by R488 and R489.
inline bool wgrCombatParentOk()
    { return true; }

// fatigue and exhaustion: every child closed by R489.
inline bool wgrFatigueParentOk()
    { return true; }

// mounts and beasts of burden: every child closed by R490.
inline bool wgrMountsParentOk()
    { return true; }

// magic in the wilderness: every child closed by R491.
inline bool wgrMagicParentOk()
    { return true; }

// ---- the flipped manifest lines ----

// Table 20 pins with the grappling-hook round R444 (rules/wsggrap.h - the ten
// terrain rows with the catch chances).
inline bool wgrT20Pinned()
    { return true; }

// Table 21 pins with the chasm-crossing round R445 (rules/wsgchasm.h - the
// five level-band ranges).
inline bool wgrT21Pinned()
    { return true; }

// Table 22 pins with the jumping round R448 (rules/wsgjump.h - the seven
// distance bands).
inline bool wgrT22Pinned()
    { return true; }

// Table 23 pins with the reduced-visibility round R449 (rules/wsgvis.h - the
// three light rows by the five conditions).
inline bool wgrT23Pinned()
    { return true; }

// Table 24 pins with the swimming round R450 (rules/wsgswim.h - the five
// encumbrance rows by the four functions).
inline bool wgrT24Pinned()
    { return true; }

// Table 25 pins with the waterborne-vehicles round R455 (rules/wsgvessels.h -
// the eight vessels by the ten characteristics).
inline bool wgrT25Pinned()
    { return true; }

// Table 26 pins with the capsizing round R456 (rules/wsgcapsizing.h - the
// eight vessels by the four conditions).
inline bool wgrT26Pinned()
    { return true; }

// Table 27 pins with the flying-mounts round R460 (rules/wsgflymounts.h - the
// 41 creatures by the seven columns).
inline bool wgrT27Pinned()
    { return true; }

// Table 42 pins with the mounts round R490 (rules/wsgmount.h - the reaction
// grid).
inline bool wgrT42Pinned()
    { return true; }

// ---- the flipped movement items ----

// the surface types pin with R435: the gentle (15-30 degrees), moderate
// (31-50), severe (51-70) and cliff (71-plus) bands with the rise rates.
inline bool wgrSurfaceTypesPinned()
    { return true; }

// the surface conditions pin with R435: the non-slippery, slightly slippery
// and slippery rate columns of the climbing grid.
inline bool wgrSurfaceConditionsPinned()
    { return true; }

// the chance of falling pins with R435: 100 minus the Climbing Rating, the
// non-thief base rating 40 and the mountaineering 80 with tools on a
// restricted surface.
inline bool wgrFallChancePinned()
    { return true; }

// the movement across special terrain pins with R434 and R432: the
// no-very-rugged vehicle bar, the pathless one-category-worse rule and the
// snow-depth thresholds.
inline bool wgrSpecialTerrainPinned()
    { return true; }

}   // namespace rules
