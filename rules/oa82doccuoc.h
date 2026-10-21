// =========================================================================================
// Adnd1 - rules/oa82doccuoc.h
// OA MONSTERS - THE DOC CU'O'C, GREATER SPIRIT, printed capture p. 259 - the
// one-legged protector round
// census 633 -> 634.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 164 closed, 71 open - the doc cu'o'c box
// flips (census 633 -> 634); NEXT - R712: the Oriental Dragons (capture pp.
// 259-260), prefix djz (verify free at the landing), audit "R712 OA monsters
// Oriental Dragons audit", include after rules/oa82doccuoc.h
//
namespace rules {

// ---- the stat block ----

// the doc cu'o'c appearance count - the 1 of the stat block (print capture p.
// 259)
inline int djyDocCuocNoAppearing()
    { return 1; }

// the doc cu'o'c armor class - the AC -3 of the stat block (print capture p.
// 259)
inline int djyDocCuocAC()
    { return -3; }

// the doc cu'o'c movement rate - the move 24 of the stat block (print capture
// p. 259)
inline int djyDocCuocMove()
    { return 24; }

// the doc cu'o'c hit dice - the HD 10 of the stat block (print capture p.
// 259)
inline int djyDocCuocHD()
    { return 10; }

// the doc cu'o'c in-lair percentage - the 10% of the stat block (print
// capture p. 259)
inline int djyDocCuocLairPct()
    { return 10; }

// the doc cu'o'c attacks per round - the 2 of the stat block (print capture
// p. 259)
inline int djyDocCuocAttacks()
    { return 2; }

// the doc cu'o'c damage minimum - the 1 of the 1-8/1-8 + special (print
// capture p. 259)
inline int djyDocCuocDmgMin()
    { return 1; }

// the doc cu'o'c damage maximum - the 8 of the 1-8/1-8 + special (print
// capture p. 259)
inline int djyDocCuocDmgMax()
    { return 8; }

// the doc cu'o'c magic resistance - the 70% of the stat block (print capture
// p. 259)
inline int djyDocCuocMRPct()
    { return 70; }

// the doc cu'o'c experience level - the VIII of the VIII/3,600 (print capture
// p. 259)
inline int djyDocCuocXPLevel()
    { return 8; }

// the doc cu'o'c base experience - the 3,600 of the VIII/3,600 (print capture
// p. 259)
inline int djyDocCuocXPBase()
    { return 3600; }

// the doc cu'o'c experience per hit point - the 14/hp of the stat block
// (print capture p. 259)
inline int djyDocCuocXPPerHP()
    { return 14; }

// the doc cu'o'c frequency - the very rare of the stat block (print capture
// p. 259)
inline int djyDocCuocVeryRare()
    { return 1; }

// the doc cu'o'c treasure - the type G of the stat block (print capture p.
// 259)
inline int djyDocCuocTreasureG()
    { return 1; }

// the doc cu'o'c intelligence - the genius of the stat block (print capture
// p. 259)
inline int djyDocCuocIntGenius()
    { return 1; }

// the doc cu'o'c alignment - the chaotic good of the stat block (print
// capture p. 259)
inline int djyDocCuocChaoticGood()
    { return 1; }

// the doc cu'o'c size - the M of the stat block (print capture p. 259)
inline int djyDocCuocSizeM()
    { return 1; }

// the doc cu'o'c psionics - the Nil ability and the Nil attack/defense modes
// of the stat block (print capture p. 259)
inline int djyDocCuocPsionicNil()
    { return 1; }

// ---- the nature ----

// the doc cu'o'c form - the body of half a man standing on one leg (print
// capture p. 259)
inline int djyDocCuocHalfManOneLeg()
    { return 1; }

// the doc cu'o'c axe - holding in one hand an axe which it always carries
// (print capture p. 259)
inline int djyDocCuocAlwaysCarriesAxe()
    { return 1; }

// the doc cu'o'c covenant - beneficial and helpful if continually given small
// offerings and included in local worship ceremonies (print capture p. 259)
inline int djyDocCuocBeneficialIfOffered()
    { return 1; }

// the doc cu'o'c charge - the protector of the local countryside, placing
// under his protection the inhabitants of a house or village (print capture
// p. 259)
inline int djyDocCuocCountrysideProtector()
    { return 1; }

// the doc cu'o'c sight - can see invisible objects and spirits at all times
// (print capture p. 259)
inline int djyDocCuocSeesInvisible()
    { return 1; }

// the doc cu'o'c power - able to become invisible at will (print capture p.
// 259)
inline int djyDocCuocInvisibleAtWill()
    { return 1; }

// the doc cu'o'c enmity - great enemies of evil spirits, most of their
// protection involving driving these creatures off (print capture p. 259)
inline int djyDocCuocEvilSpiritEnemies()
    { return 1; }

// the doc cu'o'c doctrine - uses spell powers to ensure good weather for
// crops and harvesting (print capture p. 259)
inline int djyDocCuocCropWeatherDoctrine()
    { return 1; }

// the doc cu'o'c restraint - seldom if ever directly involved in mortal
// affairs, at most using spells at night to relieve a condition or correct a
// wrong (print capture p. 259)
inline int djyDocCuocSeldomDirectInvolvement()
    { return 1; }

// the doc cu'o'c priority - concerned with protecting the land, not
// necessarily the inhabitants, their good fortune mostly an indirect outcome
// (print capture p. 259)
inline int djyDocCuocProtectsLandNotPeople()
    { return 1; }

// ---- the axe and the lair ----

// the doc cu'o'c defense - can only be hit by weapons of +3 or greater (print
// capture p. 259)
inline int djyDocCuocWeaponPlusRequired()
    { return 3; }

// the doc cu'o'c once-per-day battery - the cure disease, the remove
// paralysis, the cure blindness, the oath, the remove curse (print capture p.
// 259)
inline int djyDocCuocOncePerDaySpells()
    { return 5; }

// the doc cu'o'c three-per-day battery - the control weather and the astral,
// up to 3 times per day (print capture p. 259)
inline int djyDocCuocThricePerDaySpells()
    { return 2; }

// the doc cu'o'c axe - the 1d8 points of damage from the weapon (print
// capture p. 259)
inline int djyDocCuocAxeDmgMax()
    { return 8; }

// the doc cu'o'c axe - delivers a massive electrical shock, damage equal to
// its current hit points (print capture p. 259)
inline int djyDocCuocAxeElectricalShock()
    { return 1; }

// the doc cu'o'c shock - the victim is allowed a saving throw vs. spell, a
// successful save reducing the damage taken by half (print capture p. 259)
inline int djyDocCuocShockSaveVsSpellHalves()
    { return 1; }

// the doc cu'o'c lair - never found on the Prime Material Plane, forms a lair
// somewhere on the Astral Plane, returning only occasionally (print capture
// p. 259)
inline int djyDocCuocLairAstralPlane()
    { return 1; }

// the doc cu'o'c hoard - stores the offerings given it and items obtained
// from vanquished evil spirits (print capture p. 259)
inline int djyDocCuocStoresOfferingsAndTrophies()
    { return 1; }

// the doc cu'o'c retribution - should the lair be robbed, returns to the
// Prime Material Plane and uses its spells to wreak havoc over the area it
// protects (print capture p. 259)
inline int djyDocCuocRobberyHavocRule()
    { return 1; }

// the doc cu'o'c departure - once the havoc is done, it leaves, never again
// protecting the area (print capture p. 259)
inline int djyDocCuocLeavesForeverAfterHavoc()
    { return 1; }

}   // namespace rules
