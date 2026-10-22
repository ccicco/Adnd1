// =========================================================================================
// Adnd1 - rules/oa134wa.h
// OA SETTING - THE ISLAND OF WA, printed capture p. 304 - the unified
// military state of the shogun
// census 685 -> 686.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 216 closed, 19 open - the Wa box flips
// (census 685 -> 686); NEXT - R764: Kozakura (capture p. 304), prefix dlz
// (verify free at the landing), audit "R764 OA Kozakura audit", include after
// rules/oa134wa.h
//
namespace rules {

// ---- the unified military state ----

// the unified military state - the island of Wa is a unified military state
// (print capture p. 304)
inline int dlyUnifiedMilitaryState()
    { return 1; }

// the emperor honorary - although there is an emperor, the title is honorary
// (print capture p. 304)
inline int dlyEmperorHonorary()
    { return 1; }

// the shogun real power - real power rests in the hands of the shogun (print
// capture p. 304)
inline int dlyShogunRealPower()
    { return 1; }

// the barbarian-suppressing general - the shogun or barbarian-suppressing
// general (print capture p. 304)
inline int dlyBarbarianSuppressingGeneral()
    { return 1; }

// the shogun Hidetomi family - the shogun is always a member of the Hidetomi
// family (print capture p. 304)
inline int dlyShogunHidetomiFamily()
    { return 1; }

// ---- the fief system ----

// the fiefs granted by the shogun - the island divided into fiefs, granted by
// the shogun (print capture p. 304)
inline int dlyFiefsGrantedByShogun()
    { return 1; }

// the daimyo per fief - the fiefs ruled individually by daimyos (print
// capture p. 304)
inline int dlyDaimyoPerFief()
    { return 1; }

// the daimyo total control - each daimyo has total control over his lands,
// provided he obeys and enacts the orders of the shogun (print capture p.
// 304)
inline int dlyDaimyoTotalControl()
    { return 1; }

// the court limited scope - the court of the shogun only involves itself in
// threats against its power and in cases between different fiefs (print
// capture p. 304)
inline int dlyCourtLimitedScope()
    { return 1; }

// the confiscate and resettle - the shogun retains the power to confiscate
// lands or resettle a daimyo to a different fief, a power that helps his
// family retain control (print capture p. 304)
inline int dlyConfiscateAndResettle()
    { return 1; }

// the daimyo service and administration - in return for his fief, the daimyo
// is expected to provide military service and administer his lands (print
// capture p. 304)
inline int dlyDaimyoServiceAndAdmin()
    { return 1; }

// ---- the warrior class ----

// the warrior status raised - the status of the warrior, particularly the
// samurai, raised above all others (print capture p. 304)
inline int dlyWarriorStatusRaised()
    { return 1; }

// the samurai stipend of rice - each daimyo maintains a household of samurai,
// paying them a stipend of rice in return for their service (print capture p.
// 304)
inline int dlySamuraiStipendOfRice()
    { return 1; }

// the samurai absolute service - the samurai expected to give absolute and
// loyal service to their daimyo (print capture p. 304)
inline int dlySamuraiAbsoluteService()
    { return 1; }

// ---- the social order ----

// the social class count - under the warriors come the peasants, then the
// craftsmen, and finally the merchants, four social classes (print capture p.
// 304)
inline int dlySocialClassCount()
    { return 4; }

// the social class ladder - under the warriors come the peasants, then the
// craftsmen, and finally the merchants (print capture p. 304)
inline int dlySocialClassLadder()
    { return 1; }

// the rigid class laws - rigid laws have been enacted to keep each social
// class separate (print capture p. 304)
inline int dlyRigidClassLaws()
    { return 1; }

// the walled wards - cities customarily divided into walled wards (print
// capture p. 304)
inline int dlyWalledWards()
    { return 1; }

// the armed gates night curfew - those living in a ward must pass through
// armed gates to visit other parts of the city and must return to their own
// ward at night (print capture p. 304)
inline int dlyArmedGatesNightCurfew()
    { return 1; }

// the samurai privileges - the samurai given special privileges, particularly
// those of the vendetta and the right to avenge insults, as befits their
// military upbringing (print capture p. 304)
inline int dlySamuraiPrivileges()
    { return 1; }

// the travel strictly controlled - travel is strictly controlled and leaving
// or entering the island is difficult (print capture p. 304)
inline int dlyTravelStrictlyControlled()
    { return 1; }

// the prevent rebellion intent - the intent of these laws and regulations is
// to prevent any possibility of rebellion or civil war against the shogun
// (print capture p. 304)
inline int dlyPreventRebellionIntent()
    { return 1; }

}   // namespace rules
