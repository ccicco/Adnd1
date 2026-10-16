// =========================================================================================
// Adnd1 - rules/wsghazd2.h
// R487: the WSG NATURAL HAZARDS closer slice, printed pp. 80-83 (pdf page 82
// is the full-page avalanche illustration plate) - the second and final
// content-density round of the chapter, CLOSING the natural hazards chapter:
// the tidal wave death-rule tail from the R486 cut, the flood and flash flood
// causes with the d6+9-round duration and the afterflow, the flash-flood
// strength-check protrusion chain, the avalanche damage and burial dice with
// the digging and rescue-search rules, the slope, cliff-face and base
// rockfall bands with the shield intercept, the mudslide sinking rules, and
// the quicksand no-suction rules with the pole and swimmer rescues.
// census 411 -> 412.
//
// THE SETTLE: two-way clean on the first pass - the tesseract full-text
// reads, the pdftotext layout read and the tsv coordinate reads agree on
// every number (the 10-15 rounds and 3d8 hours, the 1d3-to-1d6 battering, the
// 10,000 to 5,000 foot flash flood at 30-50 mph, the 2d10-to-3d20 avalanche
// damage with the 50 percent huddle and the 2d3 and 4d3 burials, the 1-foot
// self-dig and the 2 and 3-foot rescue digs, the 10 percent find base with
// the +1 intelligence and +25 modifiers, the 1d6+4 trapped-air rounds, the
// 4-attacks, 5-HD, 1d4 slope rockfall over 1d4+1 rounds, the 75 percent
// shield intercept, the 1-2 round 7-HD 1d6 cliff face with the 1d4-1 and
// 1d6-3 count rolls and the 3-plus and 5-or-6 threshold dice, and the 10-HD
// 1d8 cliff base). The garbles all settled without contest: lo% in both
// readers is 10 percent (the italic-L artifact seen at R484 and R485), l d 3
// and l d 6 are 1d3 and 1d6, ld4 ld6 and ld8 are 1d4 1d6 and 1d8 (a pdfy
// ligature class), bend bars is the book's own term, 1“ per round is the
// 1-inch movement rate, and the book's lenghtens spelling stands. Printed pdf
// page 82 is a full-page avalanche illustration plate - empty in both readers
// by nature, not a failed read - so the text pages of the chapter remainder
// carry the full two-way evidence.
//
// Bounds held: the flash flood runs d6+9 rounds over 30-50 mph from 10,000
// down to 5,000 feet, the avalanche damage spans 2d10 to 3d20 with the burial
// doubling 2d3 to 4d3 at the slope bottom, the dig rates ascend 1, 2 and 3
// feet per round with three diggers maximum, the rockfall monster hit dice
// strictly ascend 5, 7 and 10 with damage dice 1d4, 1d6 and 1d8, the warned
// and unwarned cliff count rolls agree in range, and the climb-check
// threshold sits strictly below the head-hit threshold on both dice.
//
namespace rules {

// ---- The tidal wave death-rule tail ----

// a character directly in the path of a tidal wave dies - if he survives the
// buffeting he will at least be knocked unconscious, and he will drown
// shortly thereafter
inline bool whz2TidalDirectPathDrowns()
    { return true; }

// a character hit by the wave after it has traveled some distance inland and
// lost a lot of its height and velocity can probably survive by going with
// the flow, as long as he has proficiency in swimming
inline bool whz2TidalLateSurvivable()
    { return true; }

// a character who cannot swim or cannot stay afloat is in mortal danger even
// if he is hit at the very end of the inland incursion
inline bool whz2TidalNonSwimmerDoomed()
    { return true; }

// the particular circumstances dictate what happens in any situation, and it
// is up to the Dungeon Master to exercise his judgment when such judgment is
// called for
inline bool whz2TidalDMJudgment()
    { return true; }

// ---- Floods ----

// a flood results from the two most basic properties of water: it flows from
// higher elevation to lower, and it spreads out to cover the bottom and sides
// of whatever contains it
inline bool whz2WaterFlowsDownhill()
    { return true; }

// when a volume of water is too large to be held within a container, the
// overflow flows over and upon the area adjacent to the container
inline bool whz2OverflowBeyondContainer()
    { return true; }

// a flood can occur after a period of heavy rain in a low-lying area or an
// area lower in elevation than the land around it
inline bool whz2FloodFromHeavyRain()
    { return true; }

// in temperate or colder climates during late winter and early spring, a
// flood can result when the temperature is unusually high for several days in
// a row - the heat wave melts the snow cover faster than the ground can
// absorb it
inline bool whz2FloodFromSnowmelt()
    { return true; }

// the snowmelt flood is intensified if the ground under the snow cover is
// frozen or partially frozen, further reducing its ability to soak up the
// water
inline bool whz2FrozenGroundIntensifies()
    { return true; }

// flooding usually occurs only in an area adjacent to a river or a lake fed
// by rivers - the excess water flows to the lowest point, spills over the
// bank or shore, and inundates land not normally underwater
inline bool whz2FloodNearRiverLake()
    { return true; }

// a flash flood is a fleeting (and fleet) phenomenon: a mass of water may
// pass through an area in minutes, in contrast to a regular flood that builds
// slowly and inundates for several days before receding
inline bool whz2FlashFleeting()
    { return true; }

// flash floods occur most often in mountainous or hilly terrain after a heavy
// rain, in locations where a natural body of water is not present - the
// rainfall runs down slopes, accumulates in low spots, and seeks even lower
// elevations
inline bool whz2FlashMountainous()
    { return true; }

// a flash flood that began as a trickle at an elevation of 10,000 feet
inline int whz2FlashStartElevFt()
    { return 10000; }

// can be a rushing torrent by the time it descends to 5,000 feet
inline int whz2FlashLowerElevFt()
    { return 5000; }

// thousands of gallons moving forward and down at a speed of 30 to 50 miles
// per hour - minimum
inline int whz2FlashMinMph()
    { return 30; }

// the flash flood speed maximum
inline int whz2FlashMaxMph()
    { return 50; }

// when a tidal wave rushes inland it produces effects very similar to those
// of a flash flood
inline bool whz2TidalLikeFlashFlood()
    { return true; }

// the only way to avoid a flood is to move away before the area becomes
// inundated - not difficult for a normal flood, since the water level does
// not increase abruptly
inline bool whz2AvoidByMovingAway()
    { return true; }

// it is a bad idea to travel through or make camp in a mountain pass or a
// gully if a storm is brewing or if it has rained within the last two or
// three hours - a flash flood can come rushing through with very little
// warning
inline bool whz2PassGullyWarning()
    { return true; }

// the rain window for the pass-or-gully danger: within the last two or three
// hours
inline int whz2PassRainWindowHrs()
    { return 3; }

// ---- Caught in a flash flood ----

// a character caught in a flash flood with proficiency in swimming can
// probably avoid drowning, but may still suffer damage from being slammed
// against rocks, trees, etc. by the onrushing water
inline bool whz2SwimmerAvoidsDrowning()
    { return true; }

// a character without swimming proficiency can survive by treading water or
// holding his breath, but will need to find a place of refuge before he tires
inline bool whz2NonSwimmerTreads()
    { return true; }

// if the water carries a character past outcroppings and protrusions, he may
// be able to grab something and hold on until the flood moves past - a
// successful Strength Check means he has latched on
inline bool whz2GrabProtrusion()
    { return true; }

// failure on the grab check means he has been battered against the protrusion
// and suffers 1d3 to 1d6 points of damage, depending on the velocity of the
// water and the nature of the protrusion - the low die
inline int whz2GrabFailDmgMin()
    { return 3; }

// the battered-against-protrusion damage high die
inline int whz2GrabFailDmgMax()
    { return 6; }

// after the initial Strength Check succeeds, another Strength Check every two
// rounds for as long as the water continues to rush past; failure means the
// grasp is pulled loose and he is carried downstream until the velocity
// abates or he grabs another protrusion
inline bool whz2HoldEvery2Rounds()
    { return true; }

// with reference to any particular point along its path, a flash flood lasts
// 10-15 rounds (d6+9) - minimum
inline int whz2FlashRoundsMin()
    { return 10; }

// the d6+9 flash flood duration maximum
inline int whz2FlashRoundsMax()
    { return 15; }

// after the flood passes, any level area it moved through is still covered to
// some depth by gently flowing water for the next 3d8 hours - minimum
inline int whz2AfterflowHoursMin()
    { return 3; }

// the 3d8-hour afterflow maximum
inline int whz2AfterflowHoursMax()
    { return 24; }

// ---- Avalanches ----

// technically an avalanche can contain any solid material or mixture, but in
// these rules the term refers specifically to a mass of snow or ice that
// cascades down a mountainside or over a precipice
inline bool whz2AvalancheSnowIce()
    { return true; }

// a rockfall occurs when a mass of earth or rocks, or both, is in motion down
// a slope or over a cliff
inline bool whz2RockfallEarthRock()
    { return true; }

// in a mudslide the moving material is a mixture of earth and water that
// flows down a slope at a relatively slow speed
inline bool whz2MudslideEarthWater()
    { return true; }

// an avalanche can occur on a moderate or severe slope in any mountainous
// region where the terrain has a heavy snow cover - 12 inches or more
inline int whz2AvalancheSnowInches()
    { return 12; }

// the most favorable conditions are present during the daytime when the sun
// is shining and the temperature is abnormally warm or at least higher than
// average - the heat partially melts the snow, which becomes heavier because
// of its greater water content
inline bool whz2AvalancheWarmDay()
    { return true; }

// if areas of bare rock are present near a large snow accumulation the
// avalanche chance is even greater: the sun and air warm the rock, the heat
// radiates through the rock beneath the snow, and the bond keeping the snow
// attached is further weakened
inline bool whz2BareRockIncreases()
    { return true; }

// an avalanche increases in volume and speed as it falls, because more snow
// is pulled loose by the weight and friction of the mass already falling
inline bool whz2AvalancheGrowsAsFalls()
    { return true; }

// there is no good place to be in the path of an avalanche, but a character's
// chance of survival is considerably smaller at the base of a slope than some
// distance up the slope - assuming he avoids being carried down
inline bool whz2BaseWorseThanUpslope()
    { return true; }

// a character caught in an avalanche takes anywhere from 2d10 to 3d20 points
// of damage from impact with the falling snow and debris - the 2d10 minimum
inline int whz2AvalancheDmgMin()
    { return 2; }

// the 3d20 damage maximum; the Dungeon Master sets the dice by the size of
// the avalanche and the character's location when hit
inline int whz2AvalancheDmgMax()
    { return 60; }

// the avalanche damage is halved for a character who, knowing he is going to
// be hit, falls to the ground and curls into a ball to offer as much
// protection as possible
inline bool whz2CurlHalvesDamage()
    { return true; }

// a character standing or moving when an avalanche hits must make a
// successful bend bars roll to avoid becoming part of the avalanche
inline bool whz2StandingBendBars()
    { return true; }

// a character huddled in a protective position has a 50 percent chance of
// maintaining his position and not being swept away by the snow
inline int whz2HuddledHoldPct()
    { return 50; }

// whether swept along or not, a character finds himself buried under 2d3 feet
// of snow when the avalanche subsides - minimum
inline int whz2BuriedFtMin()
    { return 2; }

// the 2d3-foot burial maximum
inline int whz2BuriedFtMax()
    { return 6; }

// or 4d3 feet if he is at the bottom of the slope - minimum
inline int whz2BuriedBottomMin()
    { return 4; }

// the 4d3-foot bottom-of-slope burial maximum
inline int whz2BuriedBottomMax()
    { return 12; }

// if still alive, the buried character must make a Constitution Check:
// success means he is conscious and may be able to dig himself out; failure
// means he is unconscious and must be rescued by others
inline bool whz2BuriedConCheck()
    { return true; }

// a conscious character can dig through the snow at 1 foot per round and
// thereby free himself
inline int whz2DigSelfFtPerRound()
    { return 1; }

// a character who was huddled on the ground and not swept away when the
// avalanche passed over him is properly oriented and always digs in the right
// direction
inline bool whz2HuddledOriented()
    { return true; }

// all other characters must make a successful Wisdom Check, rolled in secret
// by the Dungeon Master, before they know the right direction to dig - once
// per round of digging until a check succeeds; failures mean the effort is
// spent digging parallel to the surface instead of toward it
inline bool whz2OthersWisdomCheck()
    { return true; }

// the base chance of finding the right spot to dig in one round of searching
// is 10 percent
inline int whz2FindBasePct()
    { return 10; }

// modified upward by 1 percent per point of intelligence of the searcher
inline int whz2FindPerIntPct()
    { return 1; }

// and further modified by +25 percent if the buried character is trying to
// dig himself out, since the surface snow is disturbed by his actions
inline int whz2FindVictimDiggingBonusPct()
    { return 25; }

// the find chance is checked separately for each searcher and each buried
// character - three searchers with four buried comrades means twelve checks
// in the first round - and can be re-checked round by round as the search
// continues
inline bool whz2FindPerSearcherPerVictim()
    { return true; }

// a character digging down to a trapped comrade moves snow at 2 feet per
// round with his hands
inline int whz2DigHandsFtPerRound()
    { return 2; }

// or 3 feet per round using an implement such as a weapon or pole to loosen
// the snow
inline int whz2DigToolFtPerRound()
    { return 3; }

// up to three characters can dig for the same victim at the same time
inline int whz2MaxDiggers()
    { return 3; }

// for each extra digger beyond the first, an extra 1 foot of snow can be
// moved per round
inline int whz2ExtraDiggerFtPerRound()
    { return 1; }

// the snow cover over a victim is not airtight and may contain trapped
// pockets of air, so he need not worry immediately about breathing
inline bool whz2SnowNotAirtight()
    { return true; }

// the trapped air supply lasts only 5-10 rounds (1d6+4) - minimum
inline int whz2AirRoundsMin()
    { return 5; }

// the 1d6+4-round air supply maximum
inline int whz2AirRoundsMax()
    { return 10; }

// after the trapped air expires the character is treated as holding his
// breath without a chance to take a deep breath first (see the Swimming
// section); when the hold-breath time limit expires he makes Constitution
// Checks, and a failed check means he has suffocated
inline bool whz2BreathThenConChecks()
    { return true; }

// ---- Rockfalls ----

// rockfalls occur in mountainous areas, especially where a deep valley
// separates two sharply rising peaks
inline bool whz2RockfallValleyPeaks()
    { return true; }

// rockfalls are most likely where rock faces contain many cracks and
// outcroppings, during the time of year when the temperature fluctuates
// between freezing at night and well above freezing during the day - water
// accumulates in the cracks, expands as it freezes, and drives the rock
// masses apart until one breaks away and falls
inline bool whz2RockfallCrackFreezeThaw()
    { return true; }

// some areas are more prone to rockfalls because of the composition of the
// rocks: a cliff or mountainside of crumbling or easily fractured rock can
// produce a significant rockfall
inline bool whz2CrumblingRockProne()
    { return true; }

// a crumbling-rock area can produce a significant rockfall as often as once
// every two months
inline int whz2ProneRockfallMonths()
    { return 2; }

// chunks of loose rock strewn at the base of a cliff or mountainside are a
// sure indication of an area where rockfalls are common
inline bool whz2LooseRockSign()
    { return true; }

// a character caught in a rockfall on the slope of a mountain is attacked 4
// times per round by rocks of sufficient size to do him harm
inline int whz2RockAtkPerRound()
    { return 4; }

// the slope rockfall attacks continue for a duration of 2-5 rounds (1d4+1) -
// minimum
inline int whz2RockDurationMin()
    { return 2; }

// the 1d4+1-round rockfall duration maximum
inline int whz2RockDurationMax()
    { return 5; }

// each rock has the same chance to hit as a monster of 5 hit dice
inline int whz2RockMonsterHd()
    { return 5; }

// each rock that hits causes 1d4 points of damage
inline int whz2RockDmgDie()
    { return 4; }

// a successful Dexterity Check means the character takes only half damage
// from each rock that hits him, reflecting his ability to move and take the
// blows on less vital areas - but any rock that hits does at least 1 point
inline bool whz2DexHalvesRockDmg()
    { return true; }

// a character who takes more than 20 points of damage from the rolling rocks
// is knocked off his feet and swept down the slope, suffering abrasion damage
// and impact damage from the tumble
inline int whz2RockSweepDmgThreshold()
    { return 20; }

// a character climbing a cliff when a rockfall occurs can protect himself
// quite well by holding a shield over his head with both hands
inline bool whz2ShieldOverHead()
    { return true; }

// there is a 75 percent chance that any rock that would otherwise have hit
// the character hits the shield instead
inline int whz2ShieldInterceptPct()
    { return 75; }

// the shield tactic only works if the character has the free use of both
// hands, is carrying a shield, and has time to get it into position before he
// is hit
inline bool whz2ShieldConditions()
    { return true; }

// it takes one round to unstrap a shield from one's back
inline int whz2ShieldUnstrapBackRounds()
    { return 1; }

// or one-half round to unfasten a shield carried on the belt (pinned as 1
// half-round)
inline int whz2ShieldUnstrapBeltHalfRounds()
    { return 1; }

// a rockfall coming down a vertical or near-vertical cliff face lasts 1-2
// rounds - minimum
inline int whz2CliffRockRoundsMin()
    { return 1; }

// the cliff-face rockfall duration maximum
inline int whz2CliffRockRoundsMax()
    { return 2; }

// during the cliff-face rockfall each character in its path is attacked by
// 0-3 rocks per round
inline int whz2CliffRocksMaxPerRound()
    { return 3; }

// each rock on the cliff-face rockfall strikes as a monster of 7 hit dice
inline int whz2CliffRockMonsterHd()
    { return 7; }

// if the characters had a chance to notice rocks at the base of the cliff and
// climbed it anyway, roll 1d4 and subtract 1 to get the number of rocks in
// the appropriate range
inline int whz2CliffNoticedDieMax()
    { return 4; }

// if they had no reason or opportunity to anticipate the rockfall before
// climbing, roll 1d6 and subtract 3
inline int whz2CliffUnnoticedDieMax()
    { return 6; }

// each rock that hits during the cliff-face rockfall does 1d6 points of
// damage
inline int whz2CliffRockDmgDie()
    { return 6; }

// after any cliff-face rockfall damage roll of 3 or more, the victim must
// make a Climbing Check to avoid being knocked from his perch
inline int whz2ClimbCheckDmgRoll()
    { return 3; }

// a cliff-face damage roll of 5 or 6 indicates the character's head has been
// hit
inline int whz2HeadHitDmgRoll()
    { return 5; }

// two hits on the head knock a character unconscious, which will certainly
// cause him to fall unless he is in a very stable position such as a wide
// ledge, or fastened to the cliff face
inline bool whz2UnconsciousFalls()
    { return true; }

// a character standing at the base of a cliff during a rockfall faces the
// same dangers as a climber, except he has no chance of falling and each rock
// strikes as a monster of 10 hit dice
inline int whz2BaseRockMonsterHd()
    { return 10; }

// the damage from each rock that hits a character at the cliff base is 1d8
// instead of 1d6
inline int whz2BaseRockDmgDie()
    { return 8; }

// a base-of-cliff damage roll of 5 or more indicates a hit on the head, and
// two such blows knock him to the ground unconscious, making him more likely
// to be hit by rocks that have yet to come down
inline int whz2BaseHeadHitDmgRoll()
    { return 5; }

// ---- Mudslides ----

// mudslides occur in a specific set of conditions: a moderate or severe slope
// with a fairly thick covering of loose topsoil, usually devoid of vegetation
// or only sparsely covered, that has been drenched with rain along with
// adjacent higher-elevation ground - the earth may absorb so much water that
// it loses its adherence to the subsoil and becomes a giant puddle of thick
// mud
inline bool whz2MudslideConditions()
    { return true; }

// if the mixture gets to the point where it contains as much water as earth,
// the layer of mud slides down a moderate slope and settles in a flat spot at
// lower elevation; on a severe slope the mixture slides when it contains
// substantially less water
inline bool whz2MudslideModerateMix()
    { return true; }

// a character on the slope when a mudslide begins is unable to avoid being
// carried down unless the area contains some solidly rooted vegetation - a
// tree or a large shrub - that he is able to grab
inline bool whz2MudslideGrabVegetation()
    { return true; }

// the trip down is dirty but not, under normal circumstances, dangerous: a
// character takes no abrasion damage from the muddy tumble and no impact
// damage at the end of the ride
inline bool whz2MudslideRideSafe()
    { return true; }

// but if the mudslide ends in a deep valley where a significant depth of mud
// can collect, a character may sink into the mire and suffocate
inline bool whz2MudslideValleySink()
    { return true; }

// a character with swimming proficiency can stay on top of the mud
// indefinitely, as long as his encumbrance enables him to swim
inline bool whz2MudSwimmerStaysOnTop()
    { return true; }

// the proficient swimmer moves along the surface of the mud at 1 inch per
// round in an attempt to reach safety (pinned as 1, the book's 1-inch
// movement rate)
inline int whz2MudSwimMoveInches()
    { return 1; }

// a character without swimming proficiency can tread water on top of the mud
// for half as long as he is able to stay afloat in water
inline bool whz2MudNonSwimmerHalfAfloat()
    { return true; }

// after the non-swimmer's treading time expires, a Strength Check once per
// round: failure indicates he has sunk beneath the surface
inline bool whz2MudStrengthCheckPerRound()
    { return true; }

// a character sunk into the mud can survive for at least as long as he can
// hold his breath; when that time limit expires he must make Constitution
// Checks as described in Holding One's Breath, and a failed check indicates
// he has suffocated
inline bool whz2MudBreathThenCon()
    { return true; }

// ---- Quicksand ----

// in any swamp or wet, low-lying area characters may stumble upon a patch of
// quicksand - an area where water has saturated the ground to such an extent
// and depth that the terrain is thick and mushy
inline bool whz2QuicksandInWetLowland()
    { return true; }

// despite its name, quicksand can be composed of earth as well as sand; in
// such a case it is nothing more than a mudhole, dealt with in the same
// manner as a mudslide
inline bool whz2QuicksandCanBeMud()
    { return true; }

// quicksand actually composed of sand is somewhat more treacherous than muddy
// quicksand, because the water-and-sand mixture is generally not as thick as
// a mudhole, so someone who walks or falls into it sinks more quickly
inline bool whz2SandyQuicksandWorse()
    { return true; }

// contrary to the popular impression, quicksand does not suck a victim
// beneath the surface
inline bool whz2QuicksandNoSuction()
    { return true; }

// someone who keeps his wits about him and his head above the surface can
// save himself by treading water and, with swimming proficiency, making his
// way along the surface to a place of safety
inline bool whz2QuicksandSelfRescue()
    { return true; }

// a character who falls into quicksand is in the same situation as someone
// caught in a mudslide
inline bool whz2QuicksandSameAsMudslide()
    { return true; }

// a nearby companion may be able to help a non-swimmer by extending a pole or
// branch that the victim can grab to help pull himself out
inline bool whz2PoleRescue()
    { return true; }

// a rescuer who enters the quicksand to help a companion must have
// proficiency in swimming or he will find himself in the same situation; a
// swimmer can enter and pull a victim to safety without jeopardizing himself
inline bool whz2RescuerMustSwim()
    { return true; }

}   // namespace rules
