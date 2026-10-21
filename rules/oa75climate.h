// =========================================================================================
// Adnd1 - rules/oa75climate.h
// OA CLIMATE GROUPINGS, printed capture pp. 252-253 - the climate doctrine
// and cross-reference round
// census 626 -> 627.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE SEVEN GROUPINGS: the Sub-Arctic Forests (the 18
// creatures - bear, carp, deer through tiger, wolf, wolverine); the Temperate
// Plain/Forest (the 20 - badger through wolverine); the Steppelands (the 13 -
// the Bactrian camel through wolf); the Sub-Tropical Forest (the 18 -
// alligator through wolf); the Tropical Forest (the 18 - badger through wild
// boar); the Cold Oceans (the 6 - cod through seal); the Warm Oceans (the 4 -
// dolphin through shark); the 61 distinct creatures across the seven. THE
// DOCTRINE: the creatures unique to Kara-Tur; the common creatures held at
// bay by stormy oceans, grim mountain ranges, and scalding deserts; the
// grouping by geography and climate; the common and game creatures off the
// encounter tables. THE CROSS-REFERENCE: the Creatures from Previous Books -
// 124 entries alphabetical, the MMI 59, the FF 18, the MMII 46, the LL 1; the
// list aids the DM and is not exclusive - the listed are those most likely to
// fit the mythos. THE CELESTIAL BUREAUCRACY: the Celestial Emperor heads the
// government of the spirits; the officials can be corrupt, disobedient, just,
// or incompetent, replaced after the yearly examination of their activities.
// The prose codifies per the R431 calculus
//
// the gap census after this round: 157 closed, 78 open - the Climate
// Groupings box flips (census 626 -> 627); NEXT - R705: the Chapter 12
// monster roster opener - the Bajang (capture pp. 253-254), prefix djs
// (verify free at the landing), audit "R705 OA monsters Bajang audit",
// include after rules/oa75climate.h
//
namespace rules {

// ---- the climate groupings ----

// the climate grouping count - the seven climate groupings of the Chapter 12
// opening (print capture p. 252)
inline int djrOA75GroupCount()
    { return 7; }

// the distinct climate-grouped game creature count - the 61 distinct names
// across the seven groupings (print capture p. 252)
inline int djrOA75CreatureCount()
    { return 61; }

// the sub-arctic forests grouping - the 18 game creatures listed (print
// capture p. 252)
inline int djrOA75SubArcticCount()
    { return 18; }

// the temperate plain/forest regions grouping - the 20 game creatures listed
// (print capture p. 252)
inline int djrOA75TemperateCount()
    { return 20; }

// the steppelands grouping - the 13 game creatures listed (print capture p.
// 252)
inline int djrOA75SteppelandsCount()
    { return 13; }

// the sub-tropical forest regions grouping - the 18 game creatures listed
// (print capture p. 252)
inline int djrOA75SubTropicalCount()
    { return 18; }

// the tropical forest regions grouping - the 18 game creatures listed (print
// capture p. 252)
inline int djrOA75TropicalCount()
    { return 18; }

// the cold oceans grouping - the 6 game creatures listed (print capture p.
// 252)
inline int djrOA75ColdCount()
    { return 6; }

// the warm oceans grouping - the 4 game creatures listed (print capture p.
// 252)
inline int djrOA75WarmCount()
    { return 4; }

// ---- the creatures from previous books ----

// the Creatures from Previous Books count - the 124 cross-referenced monsters
// (print capture pp. 252-253)
inline int djrOA75CrossCount()
    { return 124; }

// the Creatures from Previous Books - the 59 entries sourced from the MMI
// (print capture pp. 252-253)
inline int djrOA75CrossMMICount()
    { return 59; }

// the Creatures from Previous Books - the 18 entries sourced from the FF
// (print capture pp. 252-253)
inline int djrOA75CrossFFCount()
    { return 18; }

// the Creatures from Previous Books - the 46 entries sourced from the MMII
// (print capture pp. 252-253)
inline int djrOA75CrossMMIICount()
    { return 46; }

// the Creatures from Previous Books - the 1 entries sourced from the LL
// (print capture pp. 252-253)
inline int djrOA75CrossLLCount()
    { return 1; }

// the Creatures from Previous Books - listed alphabetically to aid the DM in
// creating his own adventures (print capture p. 252)
inline bool djrOA75CrossListAidsDM()
    { return true; }

// the Creatures from Previous Books - simply because a creature is not listed
// does not mean it cannot appear in an oriental adventure; the list is those
// most likely to fit the mythos and style (print capture pp. 252-253)
inline bool djrOA75CrossNotExclusive()
    { return true; }

// ---- the doctrine ----

// the Chapter 12 doctrine - a number of creatures unique to Kara-Tur,
// described in this section (print capture p. 252)
inline bool djrOA75UniqueCreaturesExist()
    { return true; }

// the Chapter 12 doctrine - creatures common elsewhere never made their
// appearance in Kara-Tur, held at bay by stormy oceans, grim mountain ranges,
// and scalding deserts (print capture p. 252)
inline bool djrOA75HeldAtBayByGeography()
    { return true; }

// the Chapter 12 doctrine - the animals and monsters grouped under the type
// of geography and climate they inhabit (print capture p. 252)
inline bool djrOA75GroupedByClimate()
    { return true; }

// the Chapter 12 doctrine - common and game creatures are not described in
// this section nor on the majority of the encounter tables, listed to inform
// the DM of the typical wild game per climate (print capture p. 252)
inline bool djrOA75GameCreaturesNotOnTables()
    { return true; }

// the Chapter 12 doctrine - the Celestial Emperor heads the Celestial
// Bureaucracy, the government of the spirits; many spirit creatures hold
// offices, receive and carry out orders, punish the wicked, and file reports
// (print capture p. 253)
inline bool djrOA75CelestialBureaucracy()
    { return true; }

// the Celestial Bureaucracy - like real-world bureaucrats the spirit
// officials can be corrupt, disobedient, just, or incompetent, and can be
// replaced, their activities examined yearly (print capture p. 253)
inline bool djrOA75OfficialsReplaceable()
    { return true; }

}   // namespace rules
