// =========================================================================================
// Adnd1 - rules/oa135kozakura.h
// OA SETTING - THE ISLAND OF KOZAKURA, printed capture p. 304 - the turbulent
// land of the daimyo wars
// census 686 -> 687.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 217 closed, 18 open - the Kozakura box
// flips (census 686 -> 687); NEXT - R765: Gajin (capture p. 304), prefix dma
// (verify free at the landing), audit "R765 OA Gajin audit", include after
// rules/oa135kozakura.h
//
namespace rules {

// ---- the island and its people ----

// the Little Cherry Blossom name - Kozakura, meaning Little Cherry Blossom
// (print capture p. 304)
inline int dlzLittleCherryBlossomName()
    { return 1; }

// the same race as Wa - inhabited by the same race of people as found on Wa
// (print capture p. 304)
inline int dlzSameRaceAsWa()
    { return 1; }

// the shared customs and traditions - Kozakura shares virtually the same
// customs and traditions as Wa (print capture p. 304)
inline int dlzSharedCustomsTraditions()
    { return 1; }

// the far from unified state - Kozakura is far from a unified state (print
// capture p. 304)
inline int dlzFarFromUnifiedState()
    { return 1; }

// ---- the daimyo wars ----

// the incessant daimyo warfare - for several centuries the scene of incessant
// warfare between powerful daimyos (print capture p. 304)
inline int dlzIncessantDaimyoWarfare()
    { return 1; }

// the shogun title struggle - all the daimyos struggling to gain the title of
// shogun (print capture p. 304)
inline int dlzShogunTitleStruggle()
    { return 1; }

// the fiefs and estates rule - the island divided into fiefs and estates,
// ruled by the daimyos (print capture p. 304)
inline int dlzFiefsAndEstatesRule()
    { return 1; }

// ---- the turbulent haven ----

// the turbulent fortunes - a very turbulent place where fortunes and might
// can be achieved by those of even the most common upbringing (print capture
// p. 304)
inline int dlzTurbulentFortunes()
    { return 1; }

// the adventurer haven - the perfect place for the adventurer seeking fame
// and fortune (print capture p. 304)
inline int dlzAdventurerHaven()
    { return 1; }

// ---- the political struggle ----

// the struggle sides - the raging struggle has two sides, the daimyos who
// support the emperor and the remains of the bakufu (print capture p. 304)
inline int dlzStruggleSides()
    { return 2; }

// the emperor regains power - the daimyos who support the emperor in his bid
// to regain his long-lost political power (print capture p. 304)
inline int dlzEmperorRegainsPower()
    { return 1; }

// the bakufu remains oppose - the remains of the bakufu, the shogunal
// government, on the other side of the struggle (print capture p. 304)
inline int dlzBakufuRemainsOppose()
    { return 1; }

// the families allied to each side - each side attempting to ally the
// remaining families on the island (print capture p. 304)
inline int dlzFamiliesAlliedEachSide()
    { return 1; }

// the loyalty or power motive - some families joining out of loyalty, others
// seeing the chance to amass more power themselves (print capture p. 304)
inline int dlzLoyaltyOrPowerMotive()
    { return 1; }

// the allied to both sides - some families arranging to be allied to both
// sides so they cannot lose (print capture p. 304)
inline int dlzAlliedToBothSides()
    { return 1; }

// ---- the warrior class ----

// the warrior most respected - the warrior the most respected and powerful
// class (print capture p. 304)
inline int dlzWarriorMostRespected()
    { return 1; }

// the lacks rigid laws - Kozakura lacks the rigid laws of Wa (print capture
// p. 304)
inline int dlzLacksRigidLaws()
    { return 1; }

// the peasant risen to lord - more than once a humble peasant risen to
// powerful lord through his military skill (print capture p. 304)
inline int dlzPeasantRisenToLord()
    { return 1; }

}   // namespace rules
