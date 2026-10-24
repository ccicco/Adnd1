// =========================================================================================
// Adnd1 - rules/lungp.h
// THE LUNG PROMOTION - THE LUNG WANG AND SHEN LUNG DEFS (FF print pp. 28-29:
// the stat blocks behind the three R818 aquatic lung dragon cross-ref cells,
// the first FF defs, the ff_print class), the QUEUED-DISCOVERY round - the 3
// keyless cells rewire, the registry 810 -> 812, no gap boxes flip - the MM2
// arc gap stays 37 closed 0 open
// census 743 -> 744.
//
// Round twenty-six of the MM2 arc, the promotion seam round (the lung/shan
// candidate queued on the landed R820; two defs promoted, the 3 aquatic cells
// rewired, the walk-key census 189 -> 192)
//
// The pin header stays the print-fidelity record; the defs carry the pp.
// 28-29 stat blocks, the rewire rides the file patches, and the walk
// cross-checks the defs and the cells live
//
namespace rules {

// ---- the R821 census ----

// The lung promotion round: the queued R818 discovery closed (the lung/shan
// candidate on the landed R820)
inline int lungpRound()
    { return 821; }

// The FF print folio of the Lung Wang (Sea Dragon) stat block
inline int lungpWangPrintPage()
    { return 28; }

// The FF print folio of the Shen Lung (Spirit Dragon) stat block
inline int lungpShenPrintPage()
    { return 29; }

// The lung wang stat block armor class
inline int lungpWangStatArmorClass()
    { return 0; }

// The lung wang stat block hit dice (the low end of the 11-13 range)
inline int lungpWangStatHitDice()
    { return 11; }

// The lung wang book-average hit points (11 x 3.5, floored)
inline int lungpWangStatAvgHp()
    { return 38; }

// The lung wang stat block attacks (2 claws and the bite)
inline int lungpWangStatNumAttacks()
    { return 3; }

// The lung wang 11-12 HD band base XP
inline int lungpWangStatXp()
    { return 4550; }

// The lung wang per-hit-point XP
inline int lungpWangStatXpPerHp()
    { return 16; }

// The lung wang full kill XP (4550 + 16 x 38)
inline int lungpWangStatXpValue()
    { return 5158; }

// The lung wang percentage in lair
inline int lungpWangLairPct()
    { return 60; }

// The lung wang scaly command minimum creatures
inline int lungpWangScalyCommandMin()
    { return 4; }

// The lung wang scaly command maximum creatures (x the age level)
inline int lungpWangScalyCommandMax()
    { return 40; }

// The lung wang steam cone length in feet
inline int lungpWangSteamConeLengthFt()
    { return 100; }

// The lung wang steam cone base width in feet
inline int lungpWangSteamConeWidthFt()
    { return 50; }

// The lung wang steam cone uses per day
inline int lungpWangSteamPerDay()
    { return 3; }

// The shen lung stat block armor class
inline int lungpShenStatArmorClass()
    { return 1; }

// The shen lung stat block hit dice (the low end of the 9-11 range)
inline int lungpShenStatHitDice()
    { return 9; }

// The shen lung book-average hit points (9 x 3.5, floored)
inline int lungpShenStatAvgHp()
    { return 31; }

// The shen lung stat block attacks (2 claws, bite, tail spike)
inline int lungpShenStatNumAttacks()
    { return 4; }

// The shen lung 9 HD band base XP
inline int lungpShenStatXp()
    { return 1400; }

// The shen lung per-hit-point XP
inline int lungpShenStatXpPerHp()
    { return 12; }

// The shen lung full kill XP (1400 + 12 x 31)
inline int lungpShenStatXpValue()
    { return 1772; }

// The shen lung percentage in lair
inline int lungpShenLairPct()
    { return 60; }

// The shen lung scaly command minimum creatures
inline int lungpShenScalyCommandMin()
    { return 2; }

// The shen lung scaly command maximum creatures (x the age level)
inline int lungpShenScalyCommandMax()
    { return 20; }

// The shen lung water fire damage (2-12 points)
inline int lungpShenWaterFireMax()
    { return 12; }

// The shen lung no insect/arachnid/arthropod radius in feet
inline int lungpShenNoInsectRadiusFt()
    { return 60; }

// The shen lung bless and curse casts per day each
inline int lungpShenBlessCursePerDay()
    { return 1; }

// The shen lung control weather and ice storm casts per day each
inline int lungpShenWeatherIcePerDay()
    { return 3; }

// The registry def count before the promotion
inline int lungpRegistryBefore()
    { return 810; }

// ---- the opening doctrine (the R821 census) ----

// The defs promoted from the FF print (the first FF defs, the new ff_print xp
// class, the R73 allowed list patched to carry it)
inline bool lungpPromotedFromFfPrint()
    { return true; }

// The MM2 index settles the 3 lung cells as FF crossrefs (Sea Dragon Lung
// Wang, Spirit Dragon Shan Lung) - the promotion seam is the FF print,
// superseding the OA-seam expectation the R818 prose recorded
inline bool lungpIndexFrefsPointAtFf()
    { return true; }

// The two-voice name settle: the MM2 index OCR reads Shan Lung - the FF print
// header reads Shen Lung (the chiang lung prose agrees) and Shen wins
inline bool lungpShanShenSettled()
    { return true; }

// The two-voice damage settle: the block OCR reads the bite 5-36 - the prose
// reads 6-36 and the prose wins
inline bool lungpWangDamageSettled()
    { return true; }

// The lung wang doctrine: the turtle body and the shen lung head, breathes
// water or air, lifts or rams any ship
inline bool lungpWangTurtleBodied()
    { return true; }

// The lung wang demand tribute from every passing ship
inline bool lungpWangDemandsTribute()
    { return true; }

// The lung wang carry the scaly command power but no water fire and no spells
// beyond those general to oriental dragons
inline bool lungpWangNoWaterFire()
    { return true; }

// The shen lung have no breath weapon (the tail spike is not poisonous)
inline bool lungpShenNoBreathWeapon()
    { return true; }

// The shen lung take no lightning damage, take double fire damage, and are
// immune to poison
inline bool lungpShenLightningFirePoison()
    { return true; }

// The shen lung are manoeuvrability class E and share their language with the
// pan lung
inline bool lungpShenManoeuvrabilityE()
    { return true; }

// The rewired cells keep their src 0 cells (the R818 source census unchanged,
// the LungDragonRows const stays 3)
inline bool lungpSourceCellsUnchanged()
    { return true; }

// The R817-R820 registry-floor consts stand as their own round snapshots (the
// >= floor checks stay green)
inline bool lungpFloorConstsStaySnapshots()
    { return true; }

// No gap boxes flip this round (the MM2 arc gap stays 37 closed 0 open)
inline bool lungpNoGapBoxesFlip()
    { return true; }

// ---- the R821 rewire census ----

// The registry def count after the promotion (2 defs)
inline int lungpRegistryAfter()
    { return 812; }

// The FF defs before the promotion (the registry carried none)
inline int lungpFfDefsBefore()
    { return 0; }

// The FF defs after the promotion (the first FF defs)
inline int lungpFfDefsAfter()
    { return 2; }

// The 3 keyless R818 aquatic lung dragon cells rewired to the new keys
inline int lungpCellsRewired()
    { return 3; }

// The cold freshwater surface grid row of the rekeyed sea dragon cell (die
// 19)
inline int lungpCellCfsRow()
    { return 17; }

// The cold saltwater depths grid row of the rekeyed sea dragon cell (die 20)
inline int lungpCellCsdRow()
    { return 18; }

// The river freshwater depths grid row of the rekeyed spirit dragon cell (die
// 18)
inline int lungpCellRfdRow()
    { return 16; }

// The R818 walk-key census before the rewire
inline int lungpWalkKeyRowsBefore()
    { return 189; }

// The R818 walk-key census after the rewire (the header const and the audit
// expression both ride as file patches)
inline int lungpWalkKeyRowsAfter()
    { return 192; }

}   // namespace rules
