// =========================================================================================
// Adnd1 - rules/oa84gaki.h
// OA MONSTERS - THE GAKI, LESSER SPIRIT, printed capture pp. 262-263 - the
// four hungry spirits round
// census 635 -> 636.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 166 closed, 69 open - the gaki box flips
// (census 635 -> 636); NEXT - R714: the Gargantua (capture pp. 263-265),
// prefix dkb (verify free at the landing), audit "R714 OA monsters Gargantua
// audit", include after rules/oa84gaki.h
//
namespace rules {

// ---- the shared gaki doctrine ----

// the gaki type count - the jiki-ketsu, the jiki-niku, the shikki, the shinen
// of the four-column stat block (print capture p. 262)
inline int dkaGakiTypeCount()
    { return 4; }

// the gaki power - the passwall three times per day (print capture p. 263)
inline int dkaGakiPasswallPerDay()
    { return 3; }

// the gaki origin - spirits of the wicked returned to the Prime Material
// Plane as horrid monsters, punishment for their sins (print capture p. 263)
inline int dkaGakiSpiritsOfWicked()
    { return 1; }

// the gaki type rule - the nature of the crimes committed in life determines
// the type the spirit returns as (print capture p. 263)
inline int dkaGakiCrimesDetermineType()
    { return 1; }

// the gaki compulsion - inflicted with terrible pains and needs compelling
// them to do evil actions (print capture p. 263)
inline int dkaGakiCompelledEvil()
    { return 1; }

// the gaki hunger - always hungry and thirsty, but eating and drinking does
// not satisfy their desires (print capture p. 263)
inline int dkaGakiNeverSated()
    { return 1; }

// the gaki power - become invisible at will (print capture p. 263)
inline int dkaGakiInvisibleAtWill()
    { return 1; }

// the gaki power - polymorph into an insect at will, moving at the flying
// speed listed (print capture p. 263)
inline int dkaGakiInsectPolymorph()
    { return 1; }

// the gaki immunity - immune to all charm, hold, drowsy insect or sleep
// spells (print capture p. 263)
inline int dkaGakiImmuneMentalSpells()
    { return 1; }

// the gaki vulnerability - as spirits, subject to all spells which affect
// spirit creatures (print capture p. 263)
inline int dkaGakiSubjectToSpiritSpells()
    { return 1; }

// ---- the jiki-ketsu-gaki ----

// the jiki-ketsu appearance count - the 1 of the stat block (print capture p.
// 262)
inline int dkaJikiKetsuNoApp()
    { return 1; }

// the jiki-ketsu armor class - the AC 2 of the stat block (print capture p.
// 262)
inline int dkaJikiKetsuAC()
    { return 2; }

// the jiki-ketsu flying rate - the 12' of the move 12'/6' (print capture p.
// 262)
inline int dkaJikiKetsuMoveFly()
    { return 12; }

// the jiki-ketsu ground rate - the 6' of the move 12'/6' (print capture p.
// 262)
inline int dkaJikiKetsuMoveGround()
    { return 6; }

// the jiki-ketsu hit dice - the HD 8 of the stat block (print capture p. 262)
inline int dkaJikiKetsuHD()
    { return 8; }

// the jiki-ketsu attacks per round - the 3 of the stat block (print capture
// p. 262)
inline int dkaJikiKetsuAttacks()
    { return 3; }

// the jiki-ketsu claw damage minimum - the 1 of the 1-3/1-3/1-8 (print
// capture p. 262)
inline int dkaJikiKetsuClawDmgMin()
    { return 1; }

// the jiki-ketsu claw damage maximum - the 3 of the 1-3/1-3/1-8 (print
// capture p. 262)
inline int dkaJikiKetsuClawDmgMax()
    { return 3; }

// the jiki-ketsu bite damage maximum - the 8 of the 1-3/1-3/1-8 (print
// capture p. 262)
inline int dkaJikiKetsuBiteDmgMax()
    { return 8; }

// the jiki-ketsu blood drain minimum - the 1 of the 1-10 hit points per round
// (print capture p. 263)
inline int dkaJikiKetsuBloodDrainMin()
    { return 1; }

// the jiki-ketsu blood drain maximum - the 10 of the 1-10 hit points per
// round (print capture p. 263)
inline int dkaJikiKetsuBloodDrainMax()
    { return 10; }

// the jiki-ketsu regeneration - 1 hit point per round (print capture p. 263)
inline int dkaJikiKetsuRegenPerRound()
    { return 1; }

// the jiki-ketsu base experience - the 1,075 of the VII/1,075 (print capture
// p. 263)
inline int dkaJikiKetsuXPBase()
    { return 1075; }

// the jiki-ketsu experience per hit point - the + 10/hp (print capture p.
// 263)
inline int dkaJikiKetsuXPPerHP()
    { return 10; }

// the jiki-ketsu frequency - the very rare of the stat block (print capture
// p. 262)
inline int dkaJikiKetsuVeryRare()
    { return 1; }

// the jiki-ketsu in-lair percentage - the Nil of the stat block (print
// capture p. 262)
inline int dkaJikiKetsuLairNil()
    { return 1; }

// the jiki-ketsu treasure - the Nil of the stat block (print capture p. 262)
inline int dkaJikiKetsuTreasureNil()
    { return 1; }

// the jiki-ketsu rank - the most fearsome of all gaki, gaunt humanoids with
// sharp fangs and clawed hands (print capture p. 263)
inline int dkaJikiKetsuMostFearsome()
    { return 1; }

// the jiki-ketsu drive - vampiric, driven to drain the blood of human victims
// (print capture p. 263)
inline int dkaJikiKetsuVampiric()
    { return 1; }

// the jiki-ketsu bite - a successful bite remains gripped to the victim, the
// drain automatic with no hit roll needed (print capture p. 263)
inline int dkaJikiKetsuBiteGrips()
    { return 1; }

// the jiki-ketsu grip - once attached they do not let go until the victim is
// slain or they are destroyed (print capture p. 263)
inline int dkaJikiKetsuNeverLetsGo()
    { return 1; }

// the jiki-ketsu defense - can only be hit by +3 weapons or better (print
// capture p. 263)
inline int dkaJikiKetsuPlus3Weapons()
    { return 1; }

// the jiki-ketsu immunity - immune to all cold and fire-based attacks (print
// capture p. 263)
inline int dkaJikiKetsuImmuneColdFire()
    { return 1; }

// the jiki-ketsu schedule - most active at night (print capture p. 263)
inline int dkaJikiKetsuNightActive()
    { return 1; }

// ---- the jiki-niku-gaki ----

// the jiki-niku appearance minimum - the 1 of the 1-4 (print capture p. 262)
inline int dkaJikiNikuNoAppMin()
    { return 1; }

// the jiki-niku appearance maximum - the 4 of the 1-4 (print capture p. 262)
inline int dkaJikiNikuNoAppMax()
    { return 4; }

// the jiki-niku armor class - the AC 6 of the stat block (print capture p.
// 262)
inline int dkaJikiNikuAC()
    { return 6; }

// the jiki-niku hit dice - the HD 3 of the stat block (print capture p. 262)
inline int dkaJikiNikuHD()
    { return 3; }

// the jiki-niku attacks per round - the 3 of the stat block (print capture p.
// 262)
inline int dkaJikiNikuAttacks()
    { return 3; }

// the jiki-niku claw damage minimum - the 1 of the 1-4/1-4/1-8 (print capture
// p. 262)
inline int dkaJikiNikuClawDmgMin()
    { return 1; }

// the jiki-niku claw damage maximum - the 4 of the 1-4/1-4/1-8 (print capture
// p. 262)
inline int dkaJikiNikuClawDmgMax()
    { return 4; }

// the jiki-niku bite damage maximum - the 8 of the 1-4/1-4/1-8 (print capture
// p. 262)
inline int dkaJikiNikuBiteDmgMax()
    { return 8; }

// the jiki-niku regeneration - 1 hit point per turn (print capture p. 263)
inline int dkaJikiNikuRegenPerTurn()
    { return 1; }

// the jiki-niku base experience - the 50 of the II/50 (print capture p. 263)
inline int dkaJikiNikuXPBase()
    { return 50; }

// the jiki-niku experience per hit point - the + 3/hp (print capture p. 263)
inline int dkaJikiNikuXPPerHP()
    { return 3; }

// the jiki-niku frequency - the rare of the stat block (print capture p. 262)
inline int dkaJikiNikuRare()
    { return 1; }

// the jiki-niku in-lair percentage - the Nil of the stat block (print capture
// p. 262)
inline int dkaJikiNikuLairNil()
    { return 1; }

// the jiki-niku treasure - the Nil of the stat block (print capture p. 262)
inline int dkaJikiNikuTreasureNil()
    { return 1; }

// the jiki-niku rank - the most common type of gaki (print capture p. 263)
inline int dkaJikiNikuMostCommon()
    { return 1; }

// the jiki-niku drive - compelled to hunt and eat flesh, preferably human
// (print capture p. 263)
inline int dkaJikiNikuFleshEater()
    { return 1; }

// the jiki-niku appearance - identical to the jiki-ketsu-gaki (print capture
// p. 263)
inline int dkaJikiNikuIdenticalAppearance()
    { return 1; }

// the jiki-niku tactics - attack with claws and bite, attempting to slay
// their victims and carry them off (print capture p. 263)
inline int dkaJikiNikuCarriesOffVictims()
    { return 1; }

// the jiki-niku locale - most frequently found near graveyards or on lonely
// roads and trails (print capture p. 263)
inline int dkaJikiNikuGraveyardHaunts()
    { return 1; }

// ---- the shikki-gaki ----

// the shikki appearance count - the 1 of the stat block (print capture p.
// 262)
inline int dkaShikkiNoApp()
    { return 1; }

// the shikki armor class - the AC 4 of the stat block (print capture p. 262)
inline int dkaShikkiAC()
    { return 4; }

// the shikki flying rate - the 12' of the move 12'/6' (print capture p. 262)
inline int dkaShikkiMoveFly()
    { return 12; }

// the shikki ground rate - the 6' of the move 12'/6' (print capture p. 262)
inline int dkaShikkiMoveGround()
    { return 6; }

// the shikki hit dice - the HD 5 of the stat block (print capture p. 262)
inline int dkaShikkiHD()
    { return 5; }

// the shikki attacks per round - the 2 of the stat block (print capture p.
// 262)
inline int dkaShikkiAttacks()
    { return 2; }

// the shikki claw damage minimum - the 1 of the 1-4/1-4 (print capture p.
// 262)
inline int dkaShikkiClawDmgMin()
    { return 1; }

// the shikki claw damage maximum - the 4 of the 1-4/1-4 (print capture p.
// 262)
inline int dkaShikkiClawDmgMax()
    { return 4; }

// the shikki disease onset - the 2 of the 2d6 turns (print capture p. 263)
inline int dkaShikkiDiseaseOnsetDice()
    { return 2; }

// the shikki disease onset sides - the 6 of the 2d6 turns (print capture p.
// 263)
inline int dkaShikkiDiseaseOnsetSides()
    { return 6; }

// the shikki disease - the victim loses 1 hit point per hour of delirium
// (print capture p. 263)
inline int dkaShikkiHPPerHour()
    { return 1; }

// the shikki disease duration minimum - the 2 of the 2-5 days (print capture
// p. 263)
inline int dkaShikkiDiseaseDaysMin()
    { return 2; }

// the shikki disease duration maximum - the 5 of the 2-5 days (print capture
// p. 263)
inline int dkaShikkiDiseaseDaysMax()
    { return 5; }

// the shikki regeneration - 2 hit points per turn (print capture p. 263)
inline int dkaShikkiRegenPerTurn()
    { return 2; }

// the shikki base experience - the 245 of the IV/245 (print capture p. 263)
inline int dkaShikkiXPBase()
    { return 245; }

// the shikki experience per hit point - the + 5/hp (print capture p. 263)
inline int dkaShikkiXPPerHP()
    { return 5; }

// the shikki frequency - the uncommon of the stat block (print capture p.
// 262)
inline int dkaShikkiUncommon()
    { return 1; }

// the shikki in-lair percentage - the Nil of the stat block (print capture p.
// 262)
inline int dkaShikkiLairNil()
    { return 1; }

// the shikki treasure - the Nil of the stat block (print capture p. 262)
inline int dkaShikkiTreasureNil()
    { return 1; }

// the shikki nature - this type of gaki causes disease, gaunt humanoids
// pocked by disease and decay (print capture p. 263)
inline int dkaShikkiCausesDisease()
    { return 1; }

// the shikki disease rule - any creature struck must make a saving throw vs.
// poison, the save repeated each time the gaki scores a successful hit (print
// capture p. 263)
inline int dkaShikkiSaveVsPoisonPerHit()
    { return 1; }

// the shikki disease course - the victim becomes delirious with intense
// chills and fevers, unable to act, cast spells, or think clearly, no natural
// recovery and healing spells have no effect until the disease is cured or
// ends (print capture p. 263)
inline int dkaShikkiDelirium()
    { return 1; }

// the shikki defense - can only be hit by +1 weapons or greater (print
// capture p. 263)
inline int dkaShikkiPlus1Weapons()
    { return 1; }

// the shikki immunity - immune to all types of disease and poison (print
// capture p. 263)
inline int dkaShikkiImmuneDiseasePoison()
    { return 1; }

// ---- the shinen-gaki ----

// the shinen appearance minimum - the 1 of the 1-3 (print capture p. 262)
inline int dkaShinenNoAppMin()
    { return 1; }

// the shinen appearance maximum - the 3 of the 1-3 (print capture p. 262)
inline int dkaShinenNoAppMax()
    { return 3; }

// the shinen armor class - the AC 0 of the stat block (print capture p. 262)
inline int dkaShinenAC()
    { return 0; }

// the shinen hit dice - the HD 4 of the stat block (print capture p. 262)
inline int dkaShinenHD()
    { return 4; }

// the shinen attacks per round - the 1 of the stat block (print capture p.
// 262)
inline int dkaShinenAttacks()
    { return 1; }

// the shinen damage minimum - the 1 of the 1-8 of the stat block (print
// capture p. 262)
inline int dkaShinenDmgMin()
    { return 1; }

// the shinen damage maximum - the 8 of the 1-8 of the stat block (print
// capture p. 262)
inline int dkaShinenDmgMax()
    { return 8; }

// the shinen fire damage - the 1d10 points of fire damage to those struck
// (print capture p. 263)
inline int dkaShinenFireDmgMax()
    { return 10; }

// the shinen vulnerability - saves at a -2 from water-based attacks (print
// capture p. 263)
inline int dkaShinenWaterSavePenalty()
    { return 2; }

// the shinen vulnerability - suffers +1 hit point per die of damage done
// (print capture p. 263)
inline int dkaShinenWaterBonusPerDie()
    { return 1; }

// the shinen regeneration - 3 hit points per turn (print capture p. 263)
inline int dkaShinenRegenPerTurn()
    { return 3; }

// the shinen base experience - the 135 of the III/135 (print capture p. 263)
inline int dkaShinenXPBase()
    { return 135; }

// the shinen experience per hit point - the + 4/hp (print capture p. 263)
inline int dkaShinenXPPerHP()
    { return 4; }

// the shinen frequency - the uncommon of the stat block (print capture p.
// 262)
inline int dkaShinenUncommon()
    { return 1; }

// the shinen in-lair percentage - the Nil of the stat block (print capture p.
// 262)
inline int dkaShinenLairNil()
    { return 1; }

// the shinen treasure - the Nil of the stat block (print capture p. 262)
inline int dkaShikenTreasureNil()
    { return 1; }

// the shinen movement - the move 0 of the stat block, traveling by insect
// polymorph alone (print capture p. 262)
inline int dkaShinenMove0()
    { return 1; }

// the shinen rank - the least dangerous type of gaki, appearing as a moving
// fire (print capture p. 263)
inline int dkaShinenLeastDangerous()
    { return 1; }

// the shinen tactics - encountered on lonely roads or woods, tries to lure
// victims to grassy or wooded areas, then ignites the surroundings to trap
// the victim in a circle of flame (print capture p. 263)
inline int dkaShinenLuresToFlammableGround()
    { return 1; }

// the shinen immunity - immune to all fire-based attacks (print capture p.
// 263)
inline int dkaShinenImmuneFire()
    { return 1; }

// the shinen defense - can only be struck by +2 weapons or better (print
// capture p. 263)
inline int dkaShinenPlus2Weapons()
    { return 1; }

}   // namespace rules
