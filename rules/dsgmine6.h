// =========================================================================================
// Adnd1 - rules/dsgmine6.h
// The DSG HIRELING LOYALTY AND THE P. 55 HAZARDS, R524: printed pp. 54-55
// (pdf 55-56) - the hireling loyalty: a PC group cannot usually run a mine
// alone (even with a miner-proficiency supervisor, a large mine needs hired
// strong arms; adventurers better used as scouts and guards when the claim is
// questionable or monsters possible), loyalty insignificant in iron or copper
// mines but a precious-metal or gemstone find a great temptation, the
// standard DMG page-36 Loyalty Check with the foreman as the liege, the + or
// - 10% security modifiers (a post-shift search +10%, no PCs present at shift
// end -10%), pay evaluated against the mine's value (the 1,000 gp of diamonds
// for a 20 gp wage), and the failed check not an immediate grab-and-run - the
// DM weighs the NPC's Intelligence, only perhaps 8-or-less attempting
// unplanned theft, exceptionally high Intelligence preparing the theft and
// the getaway or concealment, the thief stealing 1d6 x 10% of his daily
// output; the natural hazards: flooding from a tapped underground water body
// or digging below the water table (adjudicated from the DM's map, the
// below-level escape very difficult, at-level a race to the exit, above-level
// easy; the flooded mine needing draining or pumping), and mine cave-ins
// (shoring partially preventing but never eliminating - a tunnel shored every
// 10 feet at 2% weekly, no shoring 50%, partial shoring interpolated;
// external forces adding an earthquake 1d4 x 10%, a heavy rain or flood 1d3 x
// 10%, burrowers like umber hulks and ankhegs 1% per hit die; the d100
// location roll from one designated end 01 to the other 100; the automatic
// 20-foot-long, 10-foot-thick fallen ceiling; chain reactions checked
// normally); and the unnatural hazards: the unnamed evil lurking deep in the
// earth at DM creativity (the burial-ground undead, the concerned deep
// monsters), the drow and duergar regarding mineral wealth as their own with
// intervention rising in direct proportion to the mine's value, and the
// planar-gate risk - the vigorous miners breaking through to another plane,
// or much more likely some horrid lower-plane denizen finding a path into the
// world up the deep-plunging tunnel
// census 447 -> 448.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~7048-7215) with the pdf Acrobat-Capture layer as the second read (idx 127
// = the printed p. 54 window, idx 129 = the printed p. 55 window); the
// compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND:
// both machine reads agree on every load-bearing number - the 10% modifiers,
// the Intelligence-8 threshold, the 1d6 x 10% theft, the 2%/50%
// shored/unshored weekly cave-in chances, the 1d4 x 10% earthquake and 1d3 x
// 10% rain adds, the 1% per hit die, the d100 location roll, the 20 x 10 ft
// ceiling, and the 1200-ft/30-roll/360-ft worked example. SEAMS: the DMG
// page-36 Loyalty Check (cross-book, nothing auto-credited), the R520 shoring
// rules (the every-10-foot interval matching the R520 per-10-foot-section
// braces), the R511 chain-reaction cave-in rules, the R518 water-travel
// rules, and the R503 hazards survey. The mining block is fully closed with
// this round (all children 118-133 flipped); the natural/unnatural hazards
// are the last open children of the big underground-environment chapter (pp.
// 36-55), so the chapter parent line becomes closeable at the next census
// check. The new-equipment chapter (Table 35) starts the NEXT round per the
// content-density rule.
//
// A prose round: no tables pin. The dice pin as consts per the R508
// convention - the 1d6 x 10% theft of daily output, the 1d4 x 10% earthquake
// and 1d3 x 10% rain cave-in adds, and the d100 end-to-end cave-in location
// roll. The thresholds pin as consts: the 10% loyalty modifiers, the
// Intelligence-8 unplanned-theft line, the 2%/50% shored/unshored weekly
// chances, the 1% per hit die of burrowers, and the 20 x 10 ft fallen
// ceiling. The rest pins as prose bools: the hired-help and scout/guard
// split, the temptation and pay-evaluation rules, the foreman-as-liege check,
// the Intelligence-driven theft planning, the flooding adjudication and
// escape gradient, the shoring interpolation, the chain-reaction reference,
// and the unnamed-evil, burial-ground, deep-monster, jealous-race and
// planar-gate threats. The DMG-36, R520, R511 and R518 seams are noted;
// nothing auto-credits.
//
namespace rules {

// ---- the hireling loyalty check ----

// a PC group cannot usually run a mining operation by themselves - even with
// a miner-proficiency supervisor, a large mine requires hired strong arms.
inline bool dnswHiredHelpRequired()
    { return true; }

// if the claim is of questionable legality or a monster attack is possible,
// skilled adventurers are better used as scouts and guards while low-level
// laborers excavate.
inline bool dnswAdventurersScoutAndGuard()
    { return true; }

// hireling loyalty is not a significant problem in an iron or copper mine,
// but a precious metal or gemstone find presents employees a great
// opportunity to steal.
inline bool dnswPreciousFindsTempt()
    { return true; }

// the NPC reaction to temptation uses the standard Loyalty Check procedure
// outlined in the DMG on page 36 (the cross-book seam).
inline bool dnswDmg36LoyaltyCheck()
    { return true; }

// for this Loyalty Check, treat the foreman of the mining operation as the
// liege when determining modifiers.
inline bool dnswForemanIsLiege()
    { return true; }

// the mine-security loyalty modifiers are + or - 10% (a post-shift search
// +10%, no PCs present at the shift end -10%).
inline int dnswLoyaltyModPct()
    { return 10; }

// additional + or - 10% modifiers reflect the mine's security: a post-shift
// search deters theft (+10%), while no PCs present as the miners leave
// invites it (-10%).
inline bool dnswSecurityModifiers()
    { return true; }

// for loyalty modification, the NPC's pay is evaluated against the value of
// the mine - a miner excavating 1,000 gp of diamonds for 20 gp feels
// underpaid however good the wage.
inline bool dnswPayJudgedAgainstMineValue()
    { return true; }

// ---- the theft after a failed check ----

// a failed Loyalty Check does not mean the NPC immediately pockets valuables
// and runs - the DM must consider the NPC's Intelligence and concoct a
// suitable theft plan.
inline bool dnswFailedCheckNotImmediate()
    { return true; }

// only workers with low Intelligence, perhaps 8 or less, attempt a theft with
// no planning.
inline int dnswLowIntUnplanned()
    { return 8; }

// an exceptionally high Intelligence thief goes to great lengths preparing
// the theft and ensuring the getaway or concealing that the theft occurred.
inline bool dnswHighIntPlansTheft()
    { return true; }

// the thief-output roll is one die.
inline int dnswTheftDice()
    { return 1; }

// the thief steals 1d6 x 10% of his daily output.
inline int dnswTheftSides()
    { return 6; }

// the 1d6 result times 10 is the percent of daily output stolen.
inline int dnswTheftPctMult()
    { return 10; }

// ---- the flooding hazard ----

// flooding occurs if excavators accidentally tap an underground body of water
// or dig below the water table; the chance depends on the proximity of such
// bodies, adjudicated from a carefully drawn DM map.
inline bool dnswFloodFromTappedWater()
    { return true; }

// characters below the water level have a very difficult time escaping,
// characters at the flow level race the water to the nearest exit, and
// characters above escape with relative ease.
inline bool dnswFloodEscapeGradient()
    { return true; }

// after a flood disaster a mine is very difficult to work unless the water
// can be drained or pumped away; a mine reaching the water table slowly fills
// and closes unless water is removed faster than it flows in.
inline bool dnswFloodedMineNeedsPumping()
    { return true; }

// ---- the cave-in hazard ----

// proper shoring partially prevents but cannot eliminate cave-ins; a
// partially shored tunnel's chance is calculated by the DM between the 2% and
// 50% extremes.
inline bool dnswShoringPartialNotTotal()
    { return true; }

// a tunnel shored at every 10-foot interval stands only a 2% chance per week
// of a cave-in (the R520 shoring seam).
inline int dnswShoredCaveInPct()
    { return 2; }

// a tunnel with no shoring whatsoever runs a 50% weekly chance of a cave-in.
inline int dnswUnshoredCaveInPct()
    { return 50; }

// external forces add to the cave-in chance: an earthquake 1d4 x 10%, a heavy
// rain or flood 1d3 x 10%, and burrowing creatures 1% per hit die.
inline bool dnswExternalForcesAdd()
    { return true; }

// the earthquake modifier roll is one die.
inline int dnswQuakeDice()
    { return 1; }

// an earthquake adds 1d4 x 10% to the cave-in chance.
inline int dnswQuakeSides()
    { return 4; }

// the 1d4 result times 10 is the earthquake percent add.
inline int dnswQuakePctMult()
    { return 10; }

// the heavy-rain modifier roll is one die.
inline int dnswRainDice()
    { return 1; }

// a heavy rain or flood increases the cave-in chance by 1d3 x 10%.
inline int dnswRainSides()
    { return 3; }

// the 1d3 result times 10 is the rain percent add.
inline int dnswRainPctMult()
    { return 10; }

// burrowing creatures such as umber hulks and ankhegs increase the cave-in
// chance by 1% per hit die of intruding monsters.
inline int dnswBurrowerPctPerHitDie()
    { return 1; }

// the cave-in location roll is one die.
inline int dnswCaveInLocDice()
    { return 1; }

// the DM designates one end of the mine 01 and the other 100 and rolls d100:
// the result places the cave-in along the tunnel (a 30 on a 1200-foot shaft
// is about 360 feet from the entrance).
inline int dnswCaveInLocSides()
    { return 100; }

// a cave-in automatically brings down a ceiling section 20 feet long.
inline int dnswCaveInLenFt()
    { return 20; }

// the fallen ceiling section is 10 feet thick.
inline int dnswCaveInThickFt()
    { return 10; }

// chain reaction cave-ins are checked for normally (the R511 seam).
inline bool dnswChainReactionNormal()
    { return true; }

// ---- the unnatural hazards ----

// a common element of Underdark campaigns is the unnamed evil lurking deep
// within the earth - the exact encounter is the DM's creativity, with many
// things possible where magic is common.
inline bool dnswUnnamedEvilLurks()
    { return true; }

// the excavation might penetrate a long-forgotten burial ground, awakening
// its hideous undead denizens.
inline bool dnswBurialGroundUndead()
    { return true; }

// deep-dwelling monsters may become concerned about surface dwellers
// penetrating so far under the earth.
inline bool dnswDeepMonstersConcerned()
    { return true; }

// Underdark races such as the drow and the duergar regard mineral wealth as
// their own and look jealously on outsiders exploiting it - the intervention
// threat rises in direct proportion to the mine's value.
inline bool dnswUnderdarkRacesJealous()
    { return true; }

// vigorous mining might discover a gate to another plane: miners might pass
// through inadvertently, or - much more likely - some horrid lower-plane
// denizen finds a path into the world up the deep-plunging tunnel.
inline bool dnswPlanarGateRisk()
    { return true; }

}   // namespace rules
