// =========================================================================================
// Adnd1 - rules/oa136gajin.h
// OA SETTING - THE GAJIN DOCTRINE, printed capture p. 304 - the insular lands
// and the outside barbarians
// census 687 -> 688.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 218 closed, 17 open - the Gajin box flips
// (census 687 -> 688); NEXT - R766: Food (capture p. 307, the Chapter 15
// daily-life opener), prefix dmb (verify free at the landing), audit "R766 OA
// Daily Life Food audit", include after rules/oa136gajin.h
//
namespace rules {

// ---- the closed lands ----

// the outside classes introduced - players who already have the AD&D game
// rules may want to introduce character classes from these worlds into the
// lands of Oriental Adventures (print capture p. 304)
inline int dmaOutsideClassesIntroduced()
    { return 1; }

// the lands very different - these lands are very different from those of the
// standard classes (print capture p. 304)
inline int dmaLandsVeryDifferent()
    { return 1; }

// the insular closed lands - the lands described in this book are insular and
// closed, avoiding contact with the outside world when possible (print
// capture p. 304)
inline int dmaInsularClosedLands()
    { return 1; }

// the trade infrequent and controlled - trade exists with the outside world
// but is infrequent and carefully controlled (print capture p. 304)
inline int dmaTradeInfrequentControlled()
    { return 1; }

// the routes vanish danger - many ply the sea lanes and caravan routes with
// gold and treasures only to disappear at the hands of bandits or other, more
// cruel, dangers (print capture p. 304)
inline int dmaRoutesVanishDanger()
    { return 1; }

// ---- the separation doctrine ----

// the standard class count - the standard classes of fighter, magic user,
// cleric, and thief, four classes (print capture p. 304)
inline int dmaStandardClassCount()
    { return 4; }

// the peculiar traits count - the result of the separation has left the
// inhabitants with two peculiar traits (print capture p. 304)
inline int dmaPeculiarTraitsCount()
    { return 2; }

// the separation traits result - the result of this separation has left the
// inhabitants with peculiar traits (print capture p. 304)
inline int dmaSeparationTraitsResult()
    { return 1; }

// the lack of curiosity - the first trait is a lack of curiosity about the
// rest of the world (print capture p. 304)
inline int dmaLackOfCuriosity()
    { return 1; }

// the hostile barbarians view - to most people of the Oriental lands the
// outside world is filled with rude and hostile barbarians (print capture p.
// 304)
inline int dmaHostileBarbariansView()
    { return 1; }

// the gajin name - the rude and hostile barbarians of the outside world are
// known as gajin (print capture p. 304)
inline int dmaGajinName()
    { return 1; }

// the gajin not dealt with - as such they are not dealt with (print capture
// p. 304)
inline int dmaGajinNotDealtWith()
    { return 1; }

}   // namespace rules
