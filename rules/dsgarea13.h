// =========================================================================================
// Adnd1 - rules/dsgarea13.h
// THE DSG DEEPEARTH AREAS 26-27, R546: printed pp. 95-96 (pdf 96-97) - the
// individual area key crosses the dead ground and the crowded maze: Area 26
// the Hallowed Grounds (the multitude of natural caverns holding some of the
// largest chambers in all Deepearth - ceilings 1,000 feet or more, caverns
// over a mile wide and a dozen miles long, floors cut by bridged gorges, side
// tunnels, ruins and fortifications; the streams and small deep lakes; the
// barren beaten look with broken formations and collapsed bridges; the battle
// debris of broken weapons, shattered war machines and thousands upon
// thousands of skeletons - drow, duergar, svirfneblin, derro, plus the
// skeleton-less pech, cloakers and illithids who also fought and died; the
// sacrosanct spirits rising as wights, wraiths, spectres, ghosts and
// skeletons to marshall against trespassers, each huge cavern commanded by a
// single lich; the plentiful air and water but no food; the
// centuries-scavenged battlefields; and the treasure houses - city or
// fortification ruins holding thousands of weapons, mundane armor and war
// machines, fortunes in coins, gems and jewelry, and battle magic - weapons,
// armor, scrolls, rings, potions, wands, rods and miscellaneous items beyond
// measure - each guarded by an undead army commanded by a lich of 18-27th
// level (17 + 1d10), twenty percent of the liches magic user/clerics and the
// other 80% magic-users only), and Area 27 the Melting Pot (the contrast
// realm of many small caverns in an intricate maze of natural and artificial
// tunnels, amply watered with lustrous formations; the dwellings of most
// intelligent creatures known to Deepearth - drow, duergar, pech, derro,
// cloakers, myconids, umber hulks, even kuo-toa - each race in a 1d12-cave
// niche, vigorously defended with fortified construction, traps and war
// training; the rothe herds and edible fungus plots; the sacred unpollutable
// water sources; the nearly exhausted mineral veins and the wise use of raw
// materials; and the long-history secret passages and concealed entrances
// giving many possible routes between locations).
// census 469 -> 470.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~12258-12360) with the pdf Acrobat-Capture layer as the second read
// (capture idx 216 = the printed p. 95 window carrying Area 26 in full and
// the Area 27 head); the compiled-tables appendix has no reprint of this
// prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing
// number - the 1,000-ft ceilings, the mile-wide dozen-mile-long caverns, the
// 18-27th-level liches rolled as 17 + 1d10, the 20/80 lich caste split and
// the 1d12-cave niches; the only garbles settled cross-read (the djvu 1410
// and 8096 for the capture 1d10 and 80%, the capture ld12 for the djvu 1d12).
// SEAMS: the Monster Manual undead (the wights, wraiths, spectres, ghosts,
// skeletons and liches) and denizens (the drow, duergar, pech, derro,
// cloakers, myconids, umber hulks, kuo-toa, rothe), the magic-item economy of
// the treasure houses (the R80 rounds), and the R521-R522 mining (the
// exhausted veins). A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains
// open until the setting lands in full (the R527/R533-R545 precedent - the
// gap report is NOT in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the ceiling minimum, the lich level bounds and the
// 17+1d10 dice-sides-base triple, the lich caste percentage, and the 1d12
// niche dice-sides pair. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The
// undead/MM/magic-item/mining seams are noted; the Deepearth child stays
// open; nothing auto-credits.
//
namespace rules {

// ---- the Area 26 Hallowed Grounds section ----

// this multitude of natural caverns includes some of the largest chambers in
// all of Deepearth, with numerous excavated side tunnels and places showing
// fortifications and the ruins of large cities.
inline bool dnaoVastCaverns()
    { return true; }

// soaring ceilings reach 1,000 feet or more above the floors.
inline int dnaoCeilMinFt()
    { return 1000; }

// caverns over a mile wide and a dozen miles long are common.
inline bool dnaoMileWideChambers()
    { return true; }

// many cavern floors are cut by deep, wide gorges, several of which have been
// bridged.
inline bool dnaoGorgeBridges()
    { return true; }

// several streams provide the area's water supply and some caverns contain
// small, deep lakes.
inline bool dnaoStreamsLakes()
    { return true; }

// the caves once held many elegant formations but now have a barren and
// beaten look - stalactites and stalagmites broken, many bridges collapsed.
inline bool dnaoBarrenBeaten()
    { return true; }

// the debris of battle lies everywhere: broken weapons, shattered war
// machines, and thousands upon thousands of skeletons.
inline bool dnaoBattleDebris()
    { return true; }

// nothing lives here anymore, though the caverns were once highly prized; the
// skeletons include drow, duergar, svirfneblin and derro, and the
// skeleton-less pech, cloakers and illithids also fought and died for control
// of these caverns.
inline bool dnaoNothingLives()
    { return true; }

// the spirits of the fallen warriors wish their battlegrounds to remain
// sacrosanct and rise up against trespassers: wights, wraiths, spectres,
// ghosts and skeletons marshall their forces to attack.
inline bool dnaoSpiritLegions()
    { return true; }

// each of the huge caverns contains a single lich that commands the many
// undead.
inline bool dnaoLichPerCavern()
    { return true; }

// air and water are plentiful, but food is unavailable unless characters
// carry it with them.
inline bool dnaoNoFood()
    { return true; }

// each lich presides over a collection of valuables harvested from the
// battlefields by its undead minions over centuries; characters searching the
// battlefields find nothing but broken weapons, useless armor and other
// wreckage.
inline bool dnaoScavengedFields()
    { return true; }

// each lich has selected the ruin of a once-vast city or fortification as its
// lair and treasure house, each holding thousands of normal weapons, mundane
// armor pieces and even war machines, plus a small fortune in coins, gems and
// jewelry plucked from the dead.
inline bool dnaoTreasureHouses()
    { return true; }

// each treasure house contains a wide variety of magical items useful in
// battle - weapons, armor, scrolls, rings, potions, wands, rods and
// miscellaneous items beyond measure - guarded by a veritable army of undead.
inline bool dnaoBattleMagic()
    { return true; }

// each treasure house army is commanded by a lich of 18-27th level (the low
// bound).
inline int dnaoLichLvlMin()
    { return 18; }

// the commanding liches range up to 27th level (the high bound).
inline int dnaoLichLvlMax()
    { return 27; }

// the lich level is 17 + 1d10 (the die count).
inline int dnaoLichLvlDice()
    { return 1; }

// the lich level is 17 + 1d10 (the die sides).
inline int dnaoLichLvlSides()
    { return 10; }

// the lich level is 17 + 1d10 (the base).
inline int dnaoLichLvlBase()
    { return 17; }

// twenty percent of the liches are magic user/clerics and the other 80% are
// only magic-users.
inline int dnaoLichDualPct()
    { return 20; }

// ---- the Area 27 Melting Pot section ----

// in contrast to the neighboring area, this realm features many small caverns
// connected by an intricate maze of tunnels and caverns of both natural and
// artificial origin; the caves receive ample water and the many formations
// retain a great deal of lustre.
inline bool dnaoSmallCavernMaze()
    { return true; }

// the caverns provide dwellings for most types of intelligent creatures known
// to Deepearth - populations of drow, duergar, pech, derro, cloakers,
// myconids, umber hulks and even kuo-toa.
inline bool dnaoEveryRace()
    { return true; }

// each race has secured a small niche of 1d12 caves (the die count).
inline int dnaoNicheDice()
    { return 1; }

// each racial niche is 1d12 caves (the die sides).
inline int dnaoNicheSides()
    { return 12; }

// necessity has insured that each group is prepared to vigorously pursue its
// own defense: most construction effort goes to strengthening defenses,
// constructing traps and training individuals for war.
inline bool dnaoVigorousDefense()
    { return true; }

// many of these races keep herds of rothe and raise large plots of edible
// fungus for sustenance.
inline bool dnaoRotheFungus()
    { return true; }

// all creatures of the area agree that water sources are sacred and cannot be
// polluted or poisoned in the cause of war.
inline bool dnaoSacredWater()
    { return true; }

// many mineral resources were once available throughout this realm, but
// nearly all such veins have been exhausted; the creatures have learned to
// use wisely what raw materials they can find.
inline bool dnaoExhaustedVeins()
    { return true; }

// the long crowded history has left its mark in secret passages and
// connecting tunnels: inhabitants tunnel around areas that get in their way,
// so there are many possible routes between locations, often masked behind
// secret or concealed entrances.
inline bool dnaoSecretRoutes()
    { return true; }

}   // namespace rules
