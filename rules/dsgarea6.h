// =========================================================================================
// Adnd1 - rules/dsgarea6.h
// THE DSG DEEPEARTH AREAS 12-13, R539: printed pp. 86-87 (pdf 87-88) - the
// individual area key crosses the battleground and the empty quarter: Area 12
// Combat Zone (one of the most wide-open areas of Deepearth, over three miles
// wide and four miles long with very little rock fill; the cataclysmic
// earthquake that dropped the surrounding rock into the depths and left the
// treacherous bizarre landscape; the dozen mighty blocks, each hundreds of
// feet in diameter, holding up the sagging ceiling; the gorge-split floor
// where no one walks 100 feet at one elevation - the 10- and 20-foot drops,
// the 100-foot barriers; the jermalaine-widened passages to Areas 9 and 13,
// three by five feet at their smallest; the decimated, defeatist jermalaine
// of the pillar-base caves against the disciplined pech - under 100 strong,
// outnumbered at least 10 to 1, their stone wagons and wall-of-stone bridges
// and ramps, breaking into combat units and driving off every attack at
// minimal loss; the rat hordes, the ceiling-route mobats, the pillar-roaming
// chimera and the low-reach basilisk nests; the circulating air and the
// column-side waterfalls feeding the short-lived porous-floor pools; the
// quake-gathered iron, lead and gold veins with the jade and onyx deposits
// and the undiscovered surface gemstones; and the hollow-shell sabotage - a
// fifth of the bridges collapsing under more than 50 pounds, the 16
// camouflaged troves of 2d6-x-1,000-gp gems, matching gold coins and
// lead-and-iron ingots behind their 16-foot walls of stone), and Area 13
// Empty Caverns (the narrow tunnel to Area 12 and the southern canyon crack
// to Area 7; the numerous fairly small caverns and their maze of
// interconnecting passages, pinching under 18 inches in places; the classic
// dead caves with dull brittle formations under the dust; the thousands of
// sleeping bats, the preying basilisks and the floor-swarming carnivorous
// beetles; the two-end ventilation with no water, fungi or mold; and the
// abandoned intelligent-creature lair tunnels of the largest cave, dry since
// the water sources died)
// census 462 -> 463.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~10892-11036) with the pdf Acrobat-Capture layer as the second read (idx
// 392-396 = the printed pp. 86-88 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the three-by-four-mile zone, the dozen blocks,
// the 100-ft walk cap, the 10/20/100-ft barriers, the 3x5-ft passages, the
// sub-100 pech at 10-to-1 odds, the 20% sabotage rate at the 50-lb/500-gp
// collapse weight, the 16 troves with their 2d6-x-1,000-gp gems and 16-ft
// seals, and the 18-inch pinch; the only garbles are non-load-bearing (the
// djvu 'Adozen' spacing and 'asimilar', the Capture 'zbne', 'wallofstone' and
// 'widelyvarying' spacing noise). SEAMS: the Monster Manual denizens (the
// jermalaine, pech, chimera, basilisks, mobats and the rest), the PHB wall of
// stone and detect magic, the shared earthquake seam with Areas 6-7 and
// 10-12, the R521-R522 mining, and the R503 re-grain. A ZERO-FLIP ROUND: the
// pp. 75-98 Deepearth child remains open until the setting lands in full (the
// R527/R533-R538 precedent - the gap report is NOT in the git add). Nothing
// auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the zone's dimensions, the block and barrier counts,
// the passage sizes, the pech ceiling and odds, the sabotage percentage and
// collapse weights, the trove count, gem dice and seal thickness, and the
// empty-cavern pinch, with the 2d6-x-1,000 dice pinned as a
// count-sides-multiplier triple. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The
// MM/PHB/quake/mining/R503 seams are noted; the Deepearth child stays open;
// nothing auto-credits.
//
namespace rules {

// ---- the Area 12 Combat Zone section ----

// the combat zone is one of the most wide-open areas of Deepearth - over
// three miles wide.
inline int dnahZoneWideMiles()
    { return 3; }

// the combat zone stretches four miles long, very little of it filled with
// rock.
inline int dnahZoneLongMiles()
    { return 4; }

// a dozen mighty blocks of stone, each hundreds of feet in diameter, support
// the sagging ceiling after the cataclysmic earthquake wrecked fearful
// changes here.
inline int dnahBlockCount()
    { return 12; }

// the combat zone was originally a large natural cavern, but centuries ago a
// cataclysmic earthquake wreaked fearful changes - most of the rock around
// the caverns fell away into the depths of the earth, creating a treacherous
// and bizarre landscape; unlike the sunken swamp, material and creatures from
// the surface did not fall into this region.
inline bool dnahQuakeLandscape()
    { return true; }

// the cavern floor is split with so many gorges, chasms and cliffs that it is
// impossible to walk more than 100 feet at the same elevation.
inline int dnahWalkMaxFt()
    { return 100; }

// some of the floor obstacles drop or climb a mere 10 or 20 feet (the low
// bound).
inline int dnahBarrierLowFt()
    { return 10; }

// the smaller obstacles drop or climb 10 or 20 feet (the high bound).
inline int dnahBarrierHighFt()
    { return 20; }

// other obstacles present barriers 100 feet high or deep.
inline int dnahBarrierMaxFt()
    { return 100; }

// the connecting passages to Areas 9 and 13, originally natural caves widened
// by the jermalaine, are at their smallest about three feet high.
inline int dnahPassHtFt()
    { return 3; }

// the jermalaine-widened connecting passages are at their smallest about five
// feet wide.
inline int dnahPassWidFt()
    { return 5; }

// a thriving jermalaine community in the original cavern was decimated by the
// quake, and the survivors have not tried to rebuild or re-excavate their
// homes; they live in small caves among the bases of the support pillars, no
// less malicious or vandalistic than usual for their race but defeatist -
// running from danger long before retreat seems warranted.
inline bool dnahDecimatedJermalaine()
    { return true; }

// the pech inhabiting the combat zone are a disciplined, business-like group
// numbering less than 100, outnumbered at least 10 to 1 by the jermalaine.
inline int dnahPechMaxCount()
    { return 100; }

// the pech are outnumbered at least 10 to 1 by the numerous but unorganized
// jermalaine, whose regular attacks on pech work parties are routinely driven
// off.
inline int dnahOddsRatio()
    { return 10; }

// the pech roam freely throughout the vast chamber, pulling heavy stone
// wagons in their search for mineral wealth and using their innate wall of
// stone ability to erect bridges and ramps so the wagons can go wherever they
// do; when the jermalaine attack, the pech instantly cease working and break
// into combat units, invariably driving off the foe while sustaining minimal
// losses.
inline bool dnahPechWagons()
    { return true; }

// other denizens include hordes of rats living among the jermalaine and many
// bats, including mobats, entering and leaving through unknown routes in the
// ceiling; a chimera roams among the pillars, and several nests of basilisks
// are located among the lowest reaches of the chamber.
inline bool dnahZoneFauna()
    { return true; }

// the huge chamber is well-supplied with air and water - hidden passages in
// the lofty ceiling let air circulate, and surface water seeps through in
// several locations, running down the cracked and rough sides of the massive
// supporting columns from cracks to ledges in many small waterfalls; small
// fresh pools form at pillar bases but quickly drain through the cracked
// porous floor to deeper areas, and no streams flow along the bottom.
inline bool dnahColumnWaterfalls()
    { return true; }

// the tumultuous earthquake forces brought slabs of rock from widely varying
// levels of the earth into this chamber, and this diversity has drawn the
// pech - veins of iron, lead and gold are all accessible, with small
// excavated deposits of jade and onyx, and several other gemstone types near
// the surface yet to be discovered.
inline bool dnahQuakeOres()
    { return true; }

// about 20% of the pech bridges and ramps have been sabotaged - chipped to a
// hollow shell - and will collapse if anything heavier than 50 pounds (500
// gp) tries to cross; alert characters tapping the stone will notice a hollow
// sound.
inline int dnahSabotagePct()
    { return 20; }

// the sabotaged bridges collapse under anything heavier than 50 pounds (500
// gp).
inline int dnahCollapseWeightLb()
    { return 50; }

// the sabotaged bridges collapse under anything heavier than 50 pounds, i.e.
// 500 gp of weight.
inline int dnahCollapseWeightGp()
    { return 500; }

// the pech bridges and ramps create a haphazard series of pathways throughout
// the roughly floored cavern, most sturdy enough for any creatures; the
// sabotaged fifth are hollow shells chipped away by pech stonework skill.
inline bool dnahHollowBridges()
    { return true; }

// in 16 different locations throughout the chamber the pech have excavated
// small holes to store their treasures, sealed over with camouflaged wall of
// stone spells that radiate magic to a detect magic spell.
inline int dnahTroveCount()
    { return 16; }

// each treasure trove contains an assortment of gems worth 2d6 x 1,000 gp
// (the die count).
inline int dnahTroveGemsDice()
    { return 2; }

// each trove's gems are worth 2d6 x 1,000 gp (the die sides).
inline int dnahTroveGemsSides()
    { return 6; }

// each trove's gems are worth 2d6 x 1,000 gp (the multiplier), with a pile of
// gold coins worth a similar amount and hundreds of lead and iron ingots
// besides.
inline int dnahTroveGemsMultGp()
    { return 1000; }

// the wall of stone covering each trove is 16 feet thick.
inline int dnahTroveSealFt()
    { return 16; }

// ---- the Area 13 Empty Caverns section ----

// the empty caverns are attached by a narrow tunnel to Area 12 (the Combat
// Zone) and to Area 7 (the Grand Canyon of Deepearth) by a narrow crack in
// the southern end of the canyon; the caverns themselves are numerous and
// fairly small.
inline bool dnahNarrowAttachments()
    { return true; }

// the empty caverns are a maze of interconnecting passages; in some areas
// passages of less than 18 inches in diameter restrict the movement of many
// creatures, with fairly easy access throughout for creatures smaller than
// human size.
inline int dnahPassDiaMaxIn()
    { return 18; }

// the empty caverns are all of natural origin, but water no longer flows here
// - classic examples of dead caves with dull, brittle formations that the
// slightest pressure breaks apart, and dust covering everything.
inline bool dnahDeadDustyCaves()
    { return true; }

// the only denizens are thousands of bats that often fly here to sleep,
// clinging to the walls and ceiling, a few basilisks that attempt to prey on
// the flying mammals, and swarms of scavenging carnivorous beetles crawling
// about on the floor.
inline bool dnahBatRoost()
    { return true; }

// air circulates through the caverns thanks to ventilation from both ends of
// the area; there is no water, fungi, or mold here.
inline bool dnahDryVentilation()
    { return true; }

// in the area's largest cave a number of tunnels have been excavated in one
// wall - once the lairs of a group of intelligent creatures, abandoned when
// the water sources dried up, now as dusty and decayed as the rest of the
// area.
inline bool dnahAbandonedLairs()
    { return true; }

}   // namespace rules
