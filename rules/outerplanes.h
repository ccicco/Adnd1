// =========================================================================================
// Adnd1 - rules/outerplanes.h
// THE OUTER PLANES IN GENERAL - printed pp. 73-84, the general-doctrine
// round: the Great Wheel and the seventeen planes, the reaching through the
// Astral, the localized-gravity survival, the realm and layer borders, the
// encounter doctrines, the school-by-school magic limits, the item decay, and
// the Styx with Oceanus.
// census 500 -> 501.
//
// verified against printed pp. 73-84 of the uploaded motp.pdf OCR; the
// general doctrine pins carry the wheel structure, the reaching methods, the
// border rules, and the cross-plane features exactly as printed, with the
// plane-by-plane descriptions left for the rounds that follow.
//
// the gap census after this round: 59 closed, 31 open - SIX boxes fall (the
// general-doctrine parent, the arrival table, the alteration table, the
// turning modifiers, the unique-powers and human-traveler doctrines); the
// seventeen named planes begin next.
//
namespace rules {

// ---- the outer planes general pins ----

// the Great Wheel: 16 pieces (each the upper layer of a plane, joined to its
// two neighbors) with the Prime/Ethereal/inner cluster at the hub - plus the
// 17th plane, Concordant Opposition, off the wheel below; the planes align
// good-vs-evil and Law-vs-Chaos, Arcadia-to-Gladsheim the Upper,
// Acheron-to-Pandemonium the Lower.
inline int ddfOuterPlaneCount()
    { return 17; }

// the layer counts: Nirvana 1, Arcadia 3, Seven Heavens 7, Twin Paradises 2,
// Elysium 4, Happy Hunting Grounds 3, Olympus 3, Gladsheim 3, Limbo 5,
// Pandemonium 4, Abyss 666 (the best estimate, an asterisk in the printed
// table), Tarterus 6, Hades 3, Gehenna 4, Nine Hells 9, Acheron 4, Concordant
// Opposition 1.
inline int ddfAbyssLayerEstimate()
    { return 666; }

// the plane shift arrival table (the tuning-fork spell grants little
// control): 1-20 within 100 yards of the visualized spot, 21-60 within 10
// miles, 61-90 within 100 miles, 91-00 within 1,000 miles and usually in
// another Power's realm; deeper layers by chord combinations.
inline int ddfPlaneShiftOnTargetPct()
    { return 20; }

// the interplanar portals (conduit-like, top-layer, varying appearance -
// apple-tree fog in Arcadia, foul caves below): a 1-in-6 chance of finding
// one per day of searching, unless the local Powers closed them.
inline int ddfPortalFindDenom()
    { return 6; }

// the portal traffic rule: portals between outer planes are often (50%)
// one-way and often (50%) intermittent (hours to weeks, appearing days to
// years apart); crossing each new plane costs a magic item another plus (a
// sword +3 is +1 in the first outer plane and nonmagical one plane later -
// re-enter the Astral to restore it).
inline int ddfPortalOneWayPct()
    { return 50; }

// the interlayer borders: overlapping Ethereal-style barriers, breached by a
// Wisdom ability check (same breach point = same arrival spot); 70% of
// barriers are one-way; the Hells' barriers open into mid-air a half mile up,
// the Heavens' onto mountain tops.
inline int ddfInterlayerOneWayPct()
    { return 70; }

// the Chaos-plane alteration risk (Happy Hunting Grounds-to-Tarterus
// inclusive): created- or shape-changed matter risks a random effect at 20%
// (HHG/Tarterus), 40% (Olympus/Abyss), 60% (Gladsheim/Pandemonium), 80%
// (Limbo); on the d100 follow-up, 1-10 nothing, 11-30 appearance only, 31-50
// properties only, 51-70 nearby form/original abilities, 71-90 nearby
// form/abilities, 91-00 anything.
inline int ddfChaosAlterMaxPct()
    { return 80; }

// the unique-Powers encounter doctrine: demon lords, solars, Demi- and Lesser
// and Greater Powers appear as random encounters only on a 2 or a 20 of a
// typical table; otherwise out on their own missions, ignoring those who pose
// no threat to their realms.
inline int ddfUniquePowerRollLow()
    { return 2; }

// the vacant-body rule: raise dead, resurrect and magic jar leave a body open
// to native spirits at 1% per day per layer of depth (3rd-layer Hades = 3%
// per day, Abyss 100th layer = occupied within a day); the usurper is never
// unique and must be exorcised.
inline int ddfBodyHabitPctPerLayer()
    { return 1; }

// the turning-undead modifiers (evil undead only): Elysium +4 levels, Twin
// Paradises/Happy Hunting Grounds +3, Seven Heavens/Olympus +2,
// Arcadia/Gladsheim +1, Nirvana/Concordant Opposition/Limbo same,
// Acheron/Pandemonium -1, Nine Hells/Abyss -2, Gehenna/Tarterus -3, Hades -4;
// reversed for evil clerics.
inline int ddfTurnModMax()
    { return 4; }

// the river Styx: touch, drink or immersion forgets the entire past life -
// save vs. spell acts as a forget cast by a 15th-level wizard (the last five
// minutes gone), protecting for ten minutes; the standard drowning chance
// applies to immersion.
inline int ddfStyxForgetCasterLevel()
    { return 15; }

// the Styx crossing: a 50% chance of being dragged into another plane before
// reaching shore; boats add a 20% overturn chance (small) or 10% (large);
// crossing or boating draws 5d6 hydrodaemons or 3d4 styx devils at 40%.
inline int ddfStyxDraggedPct()
    { return 50; }

// the Styx boatmen: Charon ferries anywhere on the river plus the
// Astral/Ethereal/Prime in 1d100 turns (never stopping for others); the
// charonadaemons take 1d10 days with a 10% per-day chance of hostile fellow
// passengers; Charon interferes only if his boat is threatened.
inline int ddfCharonTransitTurns()
    { return 100; }

// the reaching: ALL outer-plane travel passes through the Astral (no direct
// vortices) - by conduits (one Prime mooring, one realm terminus, one round,
// unnoticed, bodies carried), by spell (plane shift, gate under the
// Power-transport rules, teleport without error, succor), by device (amulet
// of the planes, well of many worlds), or by color pool - the projected
// traveler builds a new body of the destination plane's stuff (magma-bodies
// immune to fire, doubly hurt by water), keeps his silver cord (a snap in the
// outers does NOT kill - it only bars return), and failed magic items stay
// behind, eroding in 1d10 turns.
inline bool ddfReachingDoctrine()
    { return true; }

// the survival: the outer planes are like the Primes only more so -
// breath-stale atmospheres, 1:1 true/subjective time, hunger and thirst at
// Prime rates; gravity is LOCALIZED (a general down for miles, then a new one
// - realm borders often mark gravity edges), magnetic directions differ per
// realm (the orcanthium planar compass spins near boundaries, the power
// compass gem flashes for manifested Powers); infravision works, ultravision
// does not.
inline bool ddfSurvivalDoctrine()
    { return true; }

// the magic in general: extradimensional space works (rope trick), Astral
// access only in the topmost layer, inner-plane spells fail; cantrips pop
// harmlessly; abjurations suffer the home-court rule (no effect on natives of
// the current plane); conjurations summon only natives of adjacent planes,
// uncontrolled; divinations read the plane's alignment over individuals';
// true sight freezes Law/Chaos viewers 1d10 turns (feeblemind save) and
// converts good/evil viewers (alignment save); enchantments: confusion at -4
// saves in Chaos planes, +4 in Law planes; necromantics cannot touch natives
// in their home planes.
inline bool ddfMagicDoctrine()
    { return true; }

// the item decay: weapons and armor lose one plus per plane crossed (layers
// do not count), nonmagical items lose special abilities (save
// outer-plane-creature-specific weapons, which keep their powers everywhere);
// set-AC items unaffected; extradimensional items work, Astral items only
// topmost-layer, Ethereal/inner-tapping items dead; holy swords regain
// Astral-lost pluses; Prime poison cannot touch outer-planar natives at home.
inline bool ddfItemDecayRule()
    { return true; }

// the human travelers: uncommon on the first layer, rare at best deeper -
// many arrived against their will (wrong conduits, offended Powers), so the
// class mix is wide (fighter 5-20, MU 3-30, paladin 4-24 on the human
// subtable); groups run 1-400 strong, and groups of four or fewer are
// exceptional (add four to the level range).
inline bool ddfHumanTravelerDoctrine()
    { return true; }

// the native-body doctrine: only weaker nonnatives are physically present;
// stronger ones (greater daemons, hierarch modrons, powerful slaadi) leave
// their bodies behind and form new ones as in astral projection; unique
// creatures outside home are always in nonoriginal bodies; natives slain in
// their own planes die permanently.
inline bool ddfNativeBodyRule()
    { return true; }

// the PC adjustments: clerics regain spells only in their deity's home plane
// (else 1st-2nd only); druid abilities negated save shapechange (never fatal)
// and hierophant abilities (appearance-alter exempt from Chaos-plane
// effects); thieves and fighters unaffected; rangers keep tracking and
// giant-class bonuses; barbarians are LEAST threatened here (a familiar realm
// counts as well-known); paladins keep detect evil, cure disease and lay on
// hands even on natives - the exception to necromantic limits - and their
// mounts speak Lawful Good in the upper Law planes.
inline bool ddfPcAdjustments()
    { return true; }

// the spell-crystals: one-inch to one-foot facets in nearly every layer,
// indistinguishable to travelers and natives below Intelligence 19 (who CAN
// identify the spell); touch triggers the stored divination or summoning - a
// summons to the traveler's home plane sends him safely there, to an
// alternate Prime makes him an extradimensional creature; astral projectors
// are bounced to a random plane.
inline bool ddfSpellCrystalRule()
    { return true; }

// the river Oceanus: the wholesome counterpart of the Styx - from Thalasia
// (Elysium's third layer) through Elysium's upper layers, across the Happy
// Hunting Grounds' topmost layer, to rest in Osea (Olympus' second layer);
// safe to drink, natural river dangers only, no supernatural boatmen.
inline bool ddfOceanusRule()
    { return true; }

// the Styx course: a permanent conduit through the top layers of the seven
// lower planes (Acheron, Nine Hells - via Stygia on the fifth - Gehenna,
// Hades, Tarterus, the Abyss' deeper layers, Pandemonium), skipping between
// planes non-linearly (Acheron to the Abyss in hours); it does NOT reach the
// Astral, but portals on its banks let the boatmen cross.
inline bool ddfStyxCourseRule()
    { return true; }

}   // namespace rules
