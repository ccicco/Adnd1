// =========================================================================================
// Adnd1 - rules/dsgplay.h
// The DSG IMPROVING PLAY OPENER: EXPEDITION PLANNING, BEASTS OF BURDEN,
// WATERCRAFT, R528: printed pp. 59-60 (pdf 60-61) - the frame (game habits
// causing problems, the recommendations grouped into expedition planning,
// speeding play, and effective fighting) and the expedition planning: the
// success or failure often determined before leaving base - more often the
// failure - so learn everything possible first (NPC interviews, the
// approaches and periphery, magic for insight, even rumors having a basis in
// fact, the basilisk slithering meaning mirrors); scout with light
// avoid-combat parties (one or two thieves, invisibility spells, gaseous-form
// potions) and keep scouting during the adventure (the listening-at-doors
// function, one character looking before the group enters, cutting ambush
// risk and raising tactical options); and the type-of-expedition preparation
// - objectives, duration and areas considered, ready to climb or descend
// cliffs, cross water, provide light, feed for an extended period and still
// return, extra food for opportunity, foot travel on the rough going,
// waterways the easy fast access for boaters but notoriously dangerous and
// unpredictable (the placid stream turning cascade or vanishing crack),
// beasts of burden where smooth; the mules: 2,000 gp of evenly distributed
// saddlebag weight no encumbrance, 6,000 gp maximum at 1/2 speed refusing
// over eight hours a day, the 50% persuadable six-foot-or-less chasm (never
// wider, never loaded over 2,000, no mind-changing on failure),
// average-steepness stairs and human footing with hands-required slopes too
// steep, the 50% very-steep slope, the 90% willing swim and six-foot jump
// into water (refusing over 2,000 gp), the 3-inch-per-round swim, the string
// following its leader (a refused leader unhitched, never changing its mind),
// the strange-odor jitters at 25% bolt/bray/freeze/normal (one check for the
// group), and the 360-ft stone noise muffled to 90 ft with leather or cloth
// boots replaced daily; the dogs: the 100-lb war-dog varieties (shepherds,
// malamutes, wolfhounds), trained per the animal-trainer proficiency, 200 gp
// without penalty, 500 gp maximum at half speed and -4 to all attacks, no
// swimming or steep climbing over 200 gp, the 50% attack-strangers tendency
// (restrained dogs barking instead), the advanced-training discipline (no
// attack or bark unless directed, hand signals needing sight), and the
// keen-smell-and-hearing darkness penalties of -2 instead of -4; and the
// watercraft: the kayak nimblest and roughest-capable but requiring
// small-boat proficiency from all characters, larger craft carrying more
// together but limited in rough or narrow waters, the collapsible boat
// flexible but bulky and less sturdy, waterborne scouting the more vital (the
// waterway ascertained ahead, the one-way current needing a return plan)
// census 451 -> 452.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~7564-7848) with the pdf Acrobat-Capture layer as the second read (idx 137
// = the printed p. 59 window, idx 139 = the printed p. 60 window); the
// compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND:
// both machine reads agree on every load-bearing number - the mule
// 2,000/6,000 gp with the half-speed and 8-hour rules, the 50% chasm at six
// feet, the 50% very-steep slope, the 90% swim, the 3-inch swim rate, the 25%
// odor quartet, the 360/90-ft noise, the dog 200/500 gp with the -4, the
// 100-pound weight, the 50% stranger attack, and the -2-not--4 darkness. The
// only garbles are the standing glyph classes (djvu "5096" reading as 50%,
// the "üsing" lead). SEAMS: the Monster Manual mule and war dog definitions
// (cross-book), the animal-trainer proficiency (R506/R527), the small-boat
// proficiency (R518 water travel), and the R526 collapsible boat. The
// improving-play chapter split per the content-density rule: this round
// covers children 142-144 (the planning opener), and R529 takes fighting
// effectively, diversions, speeding play, creative spell use, languages and
// mapping (children 145-150). Nothing auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the mule weights (2,000 free, 6,000 max), the half-speed
// divisor and 8-hour cap, the 50% chasm at 6 ft and the 50% steep slope, the
// 90% water willingness with the 6-ft jump, the 3-inch swim, the 25% odor
// quartet, the 360/90-ft noise, the dog weights (200/500 gp, 100 lbs), the -4
// overload penalty, the 50% stranger attack, and the -2 darkness penalty. The
// rest pins as prose bools: the three-category frame, the early-determined
// success, the scouting and rumor rules, the expedition preparation, the
// transport tradeoffs, the mule string/footing/stairs rules, the dog training
// and discipline, and the watercraft comparisons. The Monster Manual,
// R506/R527, and R518/R526 seams are noted; nothing auto-credits.
//
namespace rules {

// ---- the expedition planning frame ----

// the improving-play tactics are grouped into three categories: expedition
// planning, speeding play of the game, and effective fighting.
inline bool dnipThreeCategories()
    { return true; }

// the success or failure of an expedition is often determined before the
// party leaves base - more often the failure, from a neglected vital feature,
// an essential piece of equipment, or missing information.
inline bool dnipSuccessDeterminedEarly()
    { return true; }

// before leaving, characters should make strong efforts to learn everything
// possible about the setting: NPC interviews, exploring the approaches and
// periphery, and using magic for insight.
inline bool dnipLearnEverythingFirst()
    { return true; }

// even rumors should not be disregarded, for such talk often has a basis in
// fact - basilisk rumors mean wise characters bring mirrors.
inline bool dnipRumorsHaveBasis()
    { return true; }

// a scouting mission comprises characters traveling much more lightly than
// normal, avoiding combat at all costs - one or two thieves, possibly aided
// by invisibility spells, potions of gaseous form, or other magical
// protection.
inline bool dnipScoutLightAvoidCombat()
    { return true; }

// scouting continues during the adventure: listening at a door before
// smashing it is a scouting function, and at least one character should look
// at an area before the whole group enters - reducing ambush risk and
// increasing tactical options.
inline bool dnipScoutDuringAdventure()
    { return true; }

// ---- the type of expedition ----

// an underground expedition of any length needs considerable planning: the
// objectives, the length of time, and the areas to explore all considered,
// with the objective ideally a task motivating the PCs.
inline bool dnipExpeditionPlanningNeeds()
    { return true; }

// the PCs must be prepared to climb or descend cliffs, cross water by
// swimming or boat, provide light sources, feed themselves for an extended
// period, and still return to the surface.
inline bool dnipPrepareForTerrain()
    { return true; }

// smart adventurers carry more food than needed, so opportunities for further
// adventuring are not restricted by supply considerations.
inline bool dnipExtraFoodCarried()
    { return true; }

// if the going is extremely rough - steep descents and narrow passages - the
// characters must travel on foot, carrying everything in backpacks.
inline bool dnipRoughGoingOnFoot()
    { return true; }

// waterways often provide easy access to underground regions: boating
// characters carry more equipment and travel faster than walkers.
inline bool dnipWaterwaysEasyAccess()
    { return true; }

// underground waterways are notoriously dangerous and unpredictable - a
// placid stream can become a churning cascade or disappear through a crack,
// blocking exploration.
inline bool dnipWaterwaysDangerous()
    { return true; }

// ---- the mules ----

// mules are the most commonly employed beasts of burden - somewhat reliable
// supply mounts that walk as far as any character.
inline bool dnipMuleMostCommon()
    { return true; }

// up to 2,000 gp of weight, evenly distributed in saddlebags, does not
// encumber a mule.
inline int dnipMuleFreeWtGp()
    { return 2000; }

// a mule carries up to a maximum of 6,000 gp at half speed.
inline int dnipMuleMaxWtGp()
    { return 6000; }

// a mule loaded over 2,000 gp travels at 1/2 speed.
inline int dnipMuleOverHalfSpeedDiv()
    { return 2; }

// an overloaded mule refuses to walk for more than eight hours a day.
inline int dnipMuleMaxWalkHours()
    { return 8; }

// there is a 50% chance that a mule can be persuaded to jump a chasm six feet
// wide or less - and it never jumps a wider gap, and never while carrying
// more than 2,000 gp.
inline int dnipMuleChasmPct()
    { return 50; }

// the persuadable chasm is six feet wide or less.
inline int dnipMuleChasmMaxFt()
    { return 6; }

// there is a 50% chance that a mule can be persuaded to climb or descend a
// very steep slope.
inline int dnipMuleSteepPct()
    { return 50; }

// a mule walks and climbs stairways of average steepness or a little steeper,
// keeping its footing as well as a human - but a slope requiring hands is too
// steep.
inline bool dnipMuleStairsAndFooting()
    { return true; }

// there is a 90% probability that a mule is willing to swim or jump into
// water - though it refuses to enter water carrying more than 2,000 gp.
inline int dnipMuleWaterPct()
    { return 90; }

// a mule jumps from a height of up to six feet to enter water.
inline int dnipMuleJumpHeightFt()
    { return 6; }

// a swimming mule travels at a rate of 3 inches (30 feet) per round.
inline int dnipMuleSwimInches()
    { return 3; }

// mules in a string all follow the leader: if the leader performs a task the
// others automatically follow, and a refusing leader can be unhitched for the
// next mule to be checked - the old leader never changes its mind.
inline bool dnipMuleStringLeader()
    { return true; }

// an odor-alarmed mule bolts (25%), brays in panic (25%), freezes in place
// (25%), or functions normally (25%) - a single check for a whole group of
// mules.
inline int dnipMuleOdorPct()
    { return 25; }

// mules tend to be very jittery at strange smells, and a party employing
// mules can always be followed.
inline bool dnipMuleOdorJittery()
    { return true; }

// mules walking on stone make noise audible to a distance of 360 feet.
inline int dnipMuleNoiseFt()
    { return 360; }

// leather or cloth boots wrapped around the hooves reduce the audible
// distance to 90 feet - the muffles must be replaced daily.
inline int dnipMuleMuffledNoiseFt()
    { return 90; }

// ---- the dogs ----

// the dogs described are all varieties of the war dog (per the Monster
// Manual), resembling large German shepherds (Alsatians), malamutes, or
// wolfhounds.
inline bool dnipDogWarDogVarieties()
    { return true; }

// the war-dog varieties described generally weigh about 100 pounds.
inline int dnipDogWeightLbs()
    { return 100; }

// a dog must have animal-trainer proficiency training before serving as a
// pack animal, and can negotiate slopes of the same steepness as a mule.
inline bool dnipDogTrainingRequired()
    { return true; }

// a trained dog fitted with small saddlebags carries up to 200 gp without
// penalties to movement or combat.
inline int dnipDogFreeWtGp()
    { return 200; }

// a dog can be loaded with up to 500 gp of weight.
inline int dnipDogMaxWtGp()
    { return 500; }

// an overloaded dog moves at half speed and suffers a -4 modifier to all
// attacks - and cannot swim or climb steep slopes over 200 gp.
inline int dnipDogOverloadAtkPenalty()
    { return 4; }

// dogs have a 50% chance to attack anything that does not belong to their
// party unless physically restrained - restrained dogs that would attack
// instead bark loudly and savagely.
inline int dnipDogStrangerPct()
    { return 50; }

// a dog with successfully completed advanced training is much more
// disciplined - not attacking or barking unless directed by its master, and
// trainable to hand signals it must see to obey.
inline bool dnipDogAdvancedDiscipline()
    { return true; }

// dogs have no infravision, but their keen senses of smell and hearing aid
// them in darkness.
inline bool dnipDogKeenSenses()
    { return true; }

// a dog's penalties for attacking, damage, and AC in complete darkness are
// all -2 instead of the normal -4.
inline int dnipDogDarkPenalty()
    { return 2; }

// ---- the watercraft ----

// the kayak is certainly the most nimble craft, capable of handling the
// roughest water - but all characters must have small-boat proficiency for a
// kayak expedition to succeed.
inline bool dnipKayakMostNimble()
    { return true; }

// larger craft have greater cargo capacity and keep the PCs together in one
// boat, but much more limited utility in rough or narrow waters.
inline bool dnipLargerCraftTradeoff()
    { return true; }

// collapsible boats allow flexible planning, carried overland for stretches,
// but are bulky and difficult to carry for long distances and not as sturdy
// as other vessels.
inline bool dnipCollapsibleTradeoff()
    { return true; }

// if a waterborne expedition is planned, scouting becomes even more
// important: the nature of the waterway must be ascertained as far ahead as
// possible, and if a current is relied upon one way, some other means of
// return must be arranged.
inline bool dnipWaterScoutVital()
    { return true; }

}   // namespace rules
