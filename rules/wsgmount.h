// =========================================================================================
// Adnd1 - rules/wsgmount.h
// R490: the WSG MOUNTS AND BEASTS OF BURDEN chapter slice, printed pp. 90-94
// - the round CLOSING the chapter: the twelve-animal catalog from the ape and
// the bear through the yak with every terrain bar, temperature floor and
// ration multiplier, the animals-as-individuals personality rules, the Table
// 42 1d12 reaction grid across fire, weather, noise, odor and other with the
// noticed-agitated-panicked bands and the two-round windows, the fire and
// weather and noise and odor commentary, and the calming and understanding
// rules - the magic in the wilderness chapter rides to R491.
// census 414 -> 415.
//
// THE SETTLE: the catalog pages two-way clean - the pdftotext layout reads
// and the tesseract tsv reconstructions agree on every number (the ape 1-in-6
// and 50 degrees and 50 percent and 10x and 8x and 25, the bear 30 and 8x and
// 6x, the camel 50 degrees and two days and two weeks and the half capacity
// and 10x and 20x, the dog 40 degrees and 2-3 inches and two days and 50
// percent and seven and 200 and 300 and the 3-inch step and the four-dog
// 9/6/3 and the single-dog 6/3, the elephant 50 degrees and the 3-inch
// slowdown and fifty and thirty and two days and 50 percent every six hours,
// the horse one turn per six and the half-ration bit and the 2 percent per
// eight hours and the draft 1 percent and 01 at 12 hours and 02 permanent and
// the four and four rations, the mule half an hour and the three-fourths for
// three days, the pony 2 percent and three rations, the ram 70 degrees and 6
// and 4 rising to 6 above the 50-degree high, the sheep two dozen and six per
// handler and 50 percent per hour and 70 degrees and the 2 and 2, and the yak
// 30 degrees and 6 and 4). The Table 42 garbles settled: the layout 8110112
// class is 8/10/12 with the slash rendered as a one, the ampersand and
// copyright glyphs in the camel and donkey other cells are both 6, and the
// two-number cells print a bare trailing slash after the agitated number -
// pixel-identical to the interior slash - meaning no third number and no
// panic, pinned as the sentinel 13. The MULE ROW defeated tesseract outright
// (confidence 0.0 on two cells, the row prints in lighter ink) and pdftotext
// dropped the horse-other, mule and pony rows entirely: settled by a template
// glyph pass on the 300-dpi png - digits and slashes harvested from the same
// table's confidently-read cells, matched at the light-ink thresholds -
// giving fire 6/11, weather 6/12, noise 6/11, odor 7/12 and other 6/10/12,
// agreeing with every tesseract fragment it did manage. The elephant noise
// cell initially misread from its row-rule contamination and re-settled to
// 8/12 on the proper band. Book typos: greater that that, geta, eal, occurin,
// 1in 6. The reaction, calming and understanding prose two-way clean (1d12,
// two rounds, 2d3 turns, one-quarter and one mile, 20 percent and two
// attempts, the 50-50 motion split, +2 and +4).
//
// Bounds held: every Table 42 cell ascends noticed to agitated to panicked,
// the sentinel 13 appears only in panic columns (one in fire, three in
// weather, three in noise, two in odor, none in other), the donkey row is
// uniform 4 or 6 over 10 over 12, the mule carries four sentinels with its
// full other band, the panic modifier doubles the agitated modifier, the bear
// reverts at 30 percent while the ape splits 50-50, the dog team loses 200
// and 300 gold pieces per dog short with the 3-inch rate cut per three dogs,
// the horse lame 01 recovers at 12 hours while 02 is permanent, the ram water
// rises from 4 to 6 above the 50-degree daily high, the sheep handler step
// matches the control count at six, and the yak is the coldest at 30 degrees.
//
namespace rules {

// ---- The chapter opener ----

// a large variety of land-based animals can be used by characters as mounts
// and beasts of burden; nearly every type has a distinctive personality with
// traits that set it apart, making the animal relatively more or less useful
// in certain circumstances
inline bool wmbCatalogIntro()
    { return true; }

// the movement rates and encumbrance capacities of the most often employed
// mounts and pack animals are described in the section on Encumbrance and
// Movement; this section gives their behavior, proper care and feeding, and
// the special factors characters may have to contend with when employing a
// certain animal
inline bool wmbCatalogCrossRefs()
    { return true; }

// ---- Ape, gorilla ----

// among the animals considered here the gorilla has the highest intelligence
// rating
inline bool wmbApeHighestInt()
    { return true; }

// a gorilla that can be befriended (naturally or magically) can be trained to
// follow simple instructions as well as transport equipment
inline bool wmbApeBefriendTrain()
    { return true; }

// a gorilla might be made to serve as the point man on an expedition,
// avoiding putting a character in jeopardy by requiring him to serve in that
// capacity
inline bool wmbApePointMan()
    { return true; }

// a gorilla is not capable of moving with any great degree of stealth; a
// group containing one or more of these animals has a smaller-than-normal
// chance of being able to surprise another character or creature
inline bool wmbApeNotStealthy()
    { return true; }

// the surprise reduction should be at least 1 in 6, perhaps greater in
// certain circumstances
inline int wmbApeSurpriseMin()
    { return 1; }

// gorillas can be persuaded to serve as pack animals in any forest, hills or
// plains area where the effective temperature does not drop below 50 degrees
inline int wmbApeMinTempF()
    { return 50; }

// forced to remain in a colder area or to move on any prohibited terrain, a
// gorilla becomes lethargic or aggressive and deserts the group at its first
// opportunity - perhaps taking along anything it was carrying (certainly so
// if the equipment is strapped to its body)
inline bool wmbApeProhibitedDeserts()
    { return true; }

// the lethargic-or-aggressive split on prohibited terrain: a 50 percent
// chance of either
inline int wmbApeDesertChancePct()
    { return 50; }

// a gorilla requires ten times as much food as a man does on a daily basis to
// maintain full strength and vitality - plants will suffice, since gorillas
// are primarily herbivorous
inline int wmbApeFoodMult()
    { return 10; }

// a gorilla requires eight times as much water as a man does on a daily basis
inline int wmbApeWaterMult()
    { return 8; }

// if allowed to hunt and forage for itself, there is a 25 percent chance
// every time it goes out that it will not return
inline int wmbApeForageFailPct()
    { return 25; }

// ---- Bear, brown ----

// this animal cannot reliably be used to carry anyone or anything unless it
// is magically befriended and trained
inline bool wmbBearNeedsMagic()
    { return true; }

// a bear can be domesticated and trained by non-magical means, but there is a
// chance per month thereafter that it will revert to its natural temperament
// and head back for the wild
inline bool wmbBearNonmagicRevert()
    { return true; }

// the non-magical bear reversion chance: 30 percent per month
inline int wmbBearRevertPct()
    { return 30; }

// a bear used as a mount or pack animal will traverse any kind of terrain
// except for swamp and desert
inline bool wmbBearTerrain()
    { return true; }

// its nonretractable claws make it sure-footed on most terrain but prevent it
// from negotiating smooth slopes that are severely or moderately inclined
inline bool wmbBearClaws()
    { return true; }

// a bear is omnivorous; it can and will eat anything that a man can eat
inline bool wmbBearOmnivorous()
    { return true; }

// a bear needs eight times as much food as a man does to maintain full
// strength
inline int wmbBearFoodMult()
    { return 8; }

// a bear needs six times as much water as a man does to maintain full
// strength
inline int wmbBearWaterMult()
    { return 6; }

// ---- Camel ----

// for game purposes the single-humped camel (the dromedary) is the variety
// exclusively suited for hot desert regions
inline bool wmbCamelDromedaryDesert()
    { return true; }

// the dromedary cannot move in mountains, forests or swamps at all
inline bool wmbCamelNoMove()
    { return true; }

// the dromedary cannot negotiate a severe slope of any sort in any other
// terrain
inline bool wmbCamelNoSevereSlope()
    { return true; }

// the dromedary becomes weak and lethargic if forced to be exposed to
// temperatures lower than 50 degrees
inline int wmbCamelMinTempF()
    { return 50; }

// the dromedary weakens when exposed below its temperature floor for more
// than two days in a row
inline int wmbCamelWeakDays()
    { return 2; }

// the double-humped camel (the bactrian) has smaller feet than the dromedary
// and is able to negotiate rocky or mountainous terrain; it can also be used
// in the desert, but like its one-humped cousin it will balk at being taken
// into a forest or a swamp
inline bool wmbCamelBactrian()
    { return true; }

// a camel of either sort can go for up to two weeks without eating or
// drinking, living off the water and nutrients stored in its hump or humps
inline int wmbCamelMaxDepriveWeeks()
    { return 2; }

// during the second week of such deprivation a camel's carrying capacity is
// reduced to one-half of normal
inline bool wmbCamelSecondWeekHalf()
    { return true; }

// the second-week carrying capacity: one-half of normal
inline int wmbCamelDeprivedCapPct()
    { return 50; }

// the animal must be fed and watered at least once every two weeks, or at the
// end of that period its condition will rapidly deteriorate
inline int wmbCamelFeedWeeks()
    { return 2; }

// an empty camel needs ten times as much food (plants) as the daily ration
// for one man
inline int wmbCamelEmptyFoodMult()
    { return 10; }

// an empty camel needs twenty times as much water as the daily ration for one
// man
inline int wmbCamelEmptyWaterMult()
    { return 20; }

// reduce these amounts proportionately if it has been less than two weeks
// since the camel's last meal
inline bool wmbCamelProportionate()
    { return true; }

// ---- Dog, sled ----

// the animals that pull a sled and its contents over snowy or smooth terrain
// are hardy and dependable, but the sled dog is physiologically suited to
// cold weather
inline bool wmbDogColdAdapted()
    { return true; }

// the sled and its dogs are only usable when the temperature is lower than 40
// degrees
inline int wmbDogMaxTempF()
    { return 40; }

// the ground must have at least a significant amount of snow cover - the
// minimum: 2 inches
inline int wmbDogSnowMinIn()
    { return 2; }

// the significant snow cover range: 2-3 inches
inline int wmbDogSnowMaxIn()
    { return 3; }

// a sled dog must be fed at least as much as a man's ration of food and water
// every day to maintain full strength; water is free for the taking in the
// form of snow
inline bool wmbDogRation()
    { return true; }

// if sled dogs are forced to go for more than two days without solid food,
// the cannibalism risk begins
inline int wmbDogStarveDays()
    { return 2; }

// there is a 50 percent chance on each day after the starvation threshold
// that the stronger members of the group will kill and eat one or two of the
// weaker ones
inline int wmbDogCannibalPct()
    { return 50; }

// explorers have avoided this grisly occurrence by killing one of the dogs
// before the others get around to it - a tactic for only the direst
// circumstances
inline bool wmbDogCannibalDetail()
    { return true; }

// the optimum number of dogs pulling a sled is seven
inline int wmbDogTeamFull()
    { return 7; }

// for every dog less than the optimum number, the normal-load encumbrance
// limit for the team is reduced by 200 gold pieces
inline int wmbDogNormalLossGp()
    { return 200; }

// for every dog less than the optimum number, the maximum-load encumbrance
// limit is reduced by 300 gold pieces
inline int wmbDogMaxLossGp()
    { return 300; }

// for every three dogs less than the optimum, all movement rates are reduced
inline int wmbDogRateStepDogs()
    { return 3; }

// the movement rate loss per three dogs short: 3 inches
inline int wmbDogRateLossIn()
    { return 3; }

// a four-dog sled moves at 9 inches with a normal load and 6 inches with a
// full load on normal terrain, or 3 inches with a normal load over rugged
// terrain
inline bool wmbDogFourDogRates()
    { return true; }

// the four-dog sled normal-load rate on normal terrain: 9 inches
inline int wmbDogFourNormalIn()
    { return 9; }

// the four-dog sled full-load rate on normal terrain: 6 inches
inline int wmbDogFourFullIn()
    { return 6; }

// the four-dog sled normal-load rate over rugged terrain: 3 inches
inline int wmbDogFourRuggedIn()
    { return 3; }

// a sled pulled by a single dog cannot move over rugged terrain at all, and
// has rates of 6 and 3 inches on normal terrain
inline bool wmbDogSingleDog()
    { return true; }

// the single-dog sled normal-load rate on normal terrain: 6 inches
inline int wmbDogOneNormalIn()
    { return 6; }

// the single-dog sled full-load rate on normal terrain: 3 inches
inline int wmbDogOneFullIn()
    { return 3; }

// ---- Donkey ----

// the abilities and characteristics of a donkey are generally the same as
// those of a mule, except for differences noted in this section and in the
// section on Movement and Encumbrance
inline bool wmbDonkeySameAsMule()
    { return true; }

// ---- Elephant ----

// a trained elephant is the only kind anyone should attempt to ride or use,
// and it will generally respond only to particular verbal commands taught to
// it by the trainer - do not buy an elephant unless the command words are
// included in the price
inline bool wmbEleTrainedOnly()
    { return true; }

// an elephant can only be used in a climate where the temperature does not
// drop below 50 degrees
inline int wmbEleMinTempF()
    { return 50; }

// an elephant will not travel up or down a mountain or any severe slope;
// elephants can negotiate mountainous terrain only if a relatively level pass
// exists between the peaks
inline bool wmbEleNoSlope()
    { return true; }

// in an environment where it can forage for itself along the way, an elephant
// will eat its fill of food (plants) while traveling - but it will move
// slower when doing so
inline bool wmbEleForageSlower()
    { return true; }

// the foraging elephant moves 3 inches slower
inline int wmbEleForageSlowIn()
    { return 3; }

// if food and water are not readily available, an elephant must be fed the
// equivalent of fifty food rations each day to maintain full strength
inline int wmbEleFoodRations()
    { return 50; }

// the daily water requirement for a non-foraging elephant: thirty water
// rations
inline int wmbEleWaterRations()
    { return 30; }

// an elephant forced to travel for more than two days without getting its
// full rations risks bolting
inline int wmbEleBoltDays()
    { return 2; }

// the bolt check: every six hours
inline int wmbEleBoltCheckHours()
    { return 6; }

// there is a 50 percent chance on each bolt check that the elephant will bolt
// and head in the direction where it believes the nearest food and water
// sources to be
inline int wmbEleBoltPct()
    { return 50; }

// ---- Horse ----

// perhaps the most numerous, and certainly one of the most fragile, beasts of
// burden available to the adventuring character
inline bool wmbHorseFragile()
    { return true; }

// the horse is an exception to the general stamina rules of the Encumbrance
// and Movement section: in addition to requiring rest after traveling for a
// number of hours, any horse carrying more than its normal load must be
// rested after its turns of travel
inline bool wmbHorseStaminaException()
    { return true; }

// an overloaded horse must be rested for at least one turn
inline int wmbHorseLoadRestTurns()
    { return 1; }

// the overloaded-horse rest interval: after six turns of travel
inline int wmbHorseLoadTravelTurns()
    { return 6; }

// to provide the most benefit, the rest stop should include a bit of food and
// water - a bit to a horse is one-half of a man's daily ration - and most or
// all of the animal's load should be taken off its back, even if only for a
// few minutes
inline bool wmbHorseRestBit()
    { return true; }

// the bit of food or water is one-half of a man's daily ration
inline int wmbHorseBitPct()
    { return 50; }

// all mounts and pack animals can go lame or become unable to travel through
// injury, but a horse is particularly susceptible to this problem
inline bool wmbHorseLameSusceptible()
    { return true; }

// there is a 2 percent chance (a roll of 01 or 02 on percentile dice) for
// every eight hours of travel through rugged or very rugged terrain that a
// horse will pull up lame, or stumble over an obstacle and become injured
inline int wmbHorseLamePct()
    { return 2; }

// the lame-or-injured check interval: every eight hours of rugged or very
// rugged travel
inline int wmbHorseLameHours()
    { return 8; }

// the chance is only 1 percent (roll of 01) for a draft horse
inline int wmbDraftLamePct()
    { return 1; }

// if the dice roll is 01, the horse is injured and cannot immediately move
// farther, but it will recover after its hours of rest
inline bool wmbHorseLameTemporary()
    { return true; }

// the 01-injury recovery: after 12 hours of rest
inline int wmbHorseRecoverHours()
    { return 12; }

// if the dice roll is 02, the horse is permanently injured and can no longer
// be used to carry a burden
inline bool wmbHorseLamePermanent()
    { return true; }

// a horse needs four rations of food (plants or grain) every day to remain at
// full strength
inline int wmbHorseFoodRations()
    { return 4; }

// a horse needs at least four rations of water every day to remain at full
// strength
inline int wmbHorseWaterRations()
    { return 4; }

// ---- Mule ----

// a mule is a much hardier and stronger animal than a horse, but its
// advantage is offset by its slower movement rate over normal terrain; it
// travels over rugged and very rugged terrain at least as well as a horse,
// and because its carrying capacity is greater than that of most horses it is
// often the best animal to take on a journey through potentially treacherous
// terrain
inline bool wmbMuleHardier()
    { return true; }

// mules are particularly noted for their capriciousness, which usually
// manifests itself in stubbornness: a mule may remain rooted to one spot for
// half an hour or longer
inline bool wmbMuleStubborn()
    { return true; }

// the stubborn mule can stay rooted to one spot for half an hour or longer
inline int wmbMuleStubbornMin()
    { return 30; }

// a character can get a stubborn mule to move without causing injury to the
// animal by making a Strength Check, but the mule will only take a few steps
// before pulling up short again - a long succession of Strength Checks gets
// very tedious, and it is usually better simply to wait until the mule
// decides to move again
inline bool wmbMuleStrengthCheck()
    { return true; }

// a mule normally needs the same amount of food (plants or grain) and water
// as a horse does, except for its reduced-ration tolerance
inline bool wmbMuleSameAsHorse()
    { return true; }

// a mule can be kept on three-fourths normal rations before suffering any
// adverse effects
inline int wmbMuleShortRationPct()
    { return 75; }

// the mule tolerates its reduced rations for as many as three consecutive
// days
inline int wmbMuleShortRationDays()
    { return 3; }

// ---- Pony ----

// most of the general statements about horses apply to ponies as well
inline bool wmbPonyLikeHorse()
    { return true; }

// ponies can be specially bred for traveling in mountainous terrain, and in
// such a case the Dungeon Master may allow them to move through such areas at
// a faster rate than what is given in the section on Encumbrance and Movement
inline bool wmbPonyMountainBred()
    { return true; }

// a pony's chance of going lame is 2 percent for every eight hours spent
// traversing rugged or very rugged terrain
inline int wmbPonyLamePct()
    { return 2; }

// the pony lame check interval: every eight hours
inline int wmbPonyLameHours()
    { return 8; }

// a pony must have three rations of food or water per day
inline int wmbPonyRations()
    { return 3; }

// ---- Ram, giant ----

// either a giant ram (the male) or a giant ewe (the female) can be used as a
// mount or pack animal, but rams are generally preferred because they can be
// trained to charge an opponent on command
inline bool wmbRamChargeTrained()
    { return true; }

// these animals are only found naturally in hills or mountains in a temperate
// or subarctic climate
inline bool wmbRamHabitat()
    { return true; }

// they will not willingly stay in any area where the temperature regularly
// goes higher than 70 degrees
inline int wmbRamMaxTempF()
    { return 70; }

// as part of their domestication and training they can be persuaded to travel
// on flat, dry terrain except for deserts
inline bool wmbRamPersuadedTerrain()
    { return true; }

// giant rams and ewes will not willingly enter forests or swamps
inline bool wmbRamNoForestSwamp()
    { return true; }

// a giant ram or giant ewe needs six rations of food per day
inline int wmbRamFoodRations()
    { return 6; }

// a giant ram or giant ewe needs four rations of water per day
inline int wmbRamWaterRations()
    { return 4; }

// in an area where the daily high temperature exceeds 50 degrees, the animal
// needs six rations of water instead of only four
inline int wmbRamHotWaterRations()
    { return 6; }

// the daily-high threshold that raises the giant ram's water requirement: 50
// degrees
inline int wmbRamHotTempF()
    { return 50; }

// ---- Sheep ----

// even though they are not normally thought of as pack animals, sheep can be
// useful for this purpose: each animal can carry a small load, and a small
// herd of two dozen has a greater carrying capacity than many larger animals
// have
inline bool wmbSheepPackUse()
    { return true; }

// the animals' herding instinct, plus some effort on the part of the
// accompanying characters, will keep them in a cohesive group and headed in
// the desired direction
inline bool wmbSheepHerding()
    { return true; }

// no special ability or proficiency is needed to shepherd a group of sheep
inline bool wmbSheepNoProfNeeded()
    { return true; }

// as a rule one character (mounted or afoot) can only control six sheep on
// the move
inline int wmbSheepPerHandler()
    { return 6; }

// for every additional six sheep (or fraction thereof) in the flock, another
// character (or a dog trained in sheepherding) is needed to help keep them in
// line
inline bool wmbSheepExtraHandlers()
    { return true; }

// the additional-handler step: every six sheep or fraction thereof
inline int wmbSheepStepPerHandler()
    { return 6; }

// if a flock is moved while not properly supervised, there is a 50 percent
// chance per hour of travel that the entire flock will develop a mind of its
// own and head in a random direction - which may be, but probably will not
// be, the direction they were supposed to go
inline int wmbSheepUnsupervisedPct()
    { return 50; }

// sheep will travel in temperate or colder climates, or in any area where the
// temperature does not exceed 70 degrees; they will not willingly enter, or
// stay in, forests, deserts or swamps
inline bool wmbSheepClimate()
    { return true; }

// the sheep temperature ceiling: 70 degrees
inline int wmbSheepMaxTempF()
    { return 70; }

// a sheep needs two rations of food (plants) to remain at full strength
inline int wmbSheepFoodRations()
    { return 2; }

// a sheep needs two rations of water to remain at full strength
inline int wmbSheepWaterRations()
    { return 2; }

// a sheep being used to carry nondurable supplies (things that are used up
// along the way, such as food for characters, arrows, crossbow bolts) can
// itself be used for food when its usefulness as a carrier is over
inline bool wmbSheepNondurable()
    { return true; }

// ---- Yak ----

// the yak is similar in most respects to a giant ram, except that its range
// of terrain and temperature is even smaller
inline bool wmbYakLikeRam()
    { return true; }

// a yak can only be used in mountainous terrain
inline bool wmbYakMountainous()
    { return true; }

// a yak can only be used in arctic or subarctic climates where the
// temperature does not climb above 30 degrees
inline int wmbYakMaxTempF()
    { return 30; }

// normal terrain occurring inside a mountainous area - flat, or sloping at
// only a very gentle incline - does not preclude the use of a yak, since the
// animal is still being kept inside a mountainous area
inline bool wmbYakNormalTerrainNote()
    { return true; }

// a yak needs six rations of food per day to remain at full strength
inline int wmbYakFoodRations()
    { return 6; }

// a yak needs four rations of water per day to remain at full strength
inline int wmbYakWaterRations()
    { return 4; }

// ---- Animals as individuals ----

// the animals that accompany a party can be bit players in the adventure:
// taken for granted, they will serve capably and uncomplainingly as long as
// you keep them fed, do not work them too hard, and do not try to take them
// where they cannot go
inline bool wmbIndivBitPlayers()
    { return true; }

// taking things one small step further, it is not difficult and can be very
// interesting to treat each mount and pack animal as a unique sort of
// non-player character
inline bool wmbIndivNpcTreatment()
    { return true; }

// a character can sometimes gain valuable information about an animal from
// its former owner (assuming the seller is reputable and honest); the Dungeon
// Master can use this to modify the general characteristics of the animal,
// taking into account its individuality
inline bool wmbIndivFormerOwner()
    { return true; }

// the sure-footed example: a horse known to be very sure-footed but hating to
// get his feet wet is less susceptible to going lame and might move slightly
// faster in rugged or very rugged terrain than a normal horse - but it will
// not willingly enter a swamp or ford a river, and if forced it will either
// travel slower than normal, or might balk or even panic
inline bool wmbIndivSurefootedExample()
    { return true; }

// if an animal is captured in the wild, trial and error is the only way for a
// character to find out what its personality is like, short of magical means
// such as a speak with animals spell
inline bool wmbIndivWildTrial()
    { return true; }

// if unsure how an animal will react in a certain situation, expose the
// creature to the situation under controlled circumstances - lead it into a
// stream just before breaking camp when it is calm and well rested, not while
// being chased by hobgoblins across a ford
inline bool wmbIndivControlledExposure()
    { return true; }

// animals appreciate calmness and stability; they do not like being exposed
// to unpleasant or potentially harmful conditions, do not like being startled
// or upset by something they did not expect, and may behave irrationally when
// something out of the ordinary happens
inline bool wmbIndivCalmStability()
    { return true; }

// all normal (non-fantastic) animals have an instinctive fear of fire
inline bool wmbIndivFireFear()
    { return true; }

// to varying degrees, animals have an innate ability to sense when a drastic
// change in the weather is about to occur
inline bool wmbIndivWeatherSense()
    { return true; }

// all of them can be startled by a loud noise, or bothered by an unpleasant
// smell
inline bool wmbIndivStartleNoiseSmell()
    { return true; }

// as a general rule an animal's sense of smell and sense of hearing are more
// acute than those of a human or demihuman: when an animal appears nervous or
// excited, it may be because it has perceived something that the character
// riding or leading it has not yet noticed
inline bool wmbIndivAcuteSenses()
    { return true; }

// most animals are not intelligent enough to be capricious; when they seem to
// be bothered, it is a good bet that they are not acting that way just
// because they feel like it
inline bool wmbIndivNotCapricious()
    { return true; }

// ---- Table 42: reactions of animals ----

// the Table 42 row count: ape-gorilla, bear-brown, camel-any, dog-sled,
// donkey, elephant-any, horse-draft, horse-wild, horse-other, mule, pony,
// ram-giant, sheep, yak - in that order
inline int wmbT42AnimalCount()
    { return 14; }

// fire: the noticed threshold, equal to or greater than on 1d12
inline int wmbT42FireN(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 6;
        case 12:
            return 4;
        case 13:
            return 7;
        default:
            return 13;
        }
    }

// fire: the agitated threshold
inline int wmbT42FireA(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 9;
        case 6:
            return 11;
        case 7:
            return 10;
        case 8:
            return 9;
        case 9:
            return 11;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 10;
        default:
            return 13;
        }
    }

// fire: the panicked threshold - 13 is the sentinel, an impossible 1d12
// result standing for the bare trailing slash, meaning no third number given
// so the animal will not become panicked
inline int wmbT42FireP(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 11;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 11;
        case 9:
            return 13;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return 13;
        }
    }

// weather: the noticed threshold
inline int wmbT42WeatherN(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 8;
        case 12:
            return 7;
        case 13:
            return 7;
        default:
            return 13;
        }
    }

// weather: the agitated threshold
inline int wmbT42WeatherA(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 11;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 10;
        case 9:
            return 12;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 10;
        case 13:
            return 10;
        default:
            return 13;
        }
    }

// weather: the panicked threshold or the sentinel
inline int wmbT42WeatherP(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 13;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return 13;
        }
    }

// noise: the noticed threshold
inline int wmbT42NoiseN(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 8;
        default:
            return 13;
        }
    }

// noise: the agitated threshold
inline int wmbT42NoiseA(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 11;
        case 2:
            return 11;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 10;
        case 13:
            return 11;
        default:
            return 13;
        }
    }

// noise: the panicked threshold or the sentinel
inline int wmbT42NoiseP(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 13;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return 13;
        }
    }

// odor: the noticed threshold
inline int wmbT42OdorN(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 8;
        case 13:
            return 6;
        default:
            return 13;
        }
    }

// odor: the agitated threshold
inline int wmbT42OdorA(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 9;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 12;
        case 10:
            return 10;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 10;
        default:
            return 13;
        }
    }

// odor: the panicked threshold or the sentinel
inline int wmbT42OdorP(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 11;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 13;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return 13;
        }
    }

// other: the noticed threshold
inline int wmbT42OtherN(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 7;
        default:
            return 13;
        }
    }

// other: the agitated threshold
inline int wmbT42OtherA(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 10;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 10;
        default:
            return 13;
        }
    }

// other: the panicked threshold or the sentinel
inline int wmbT42OtherP(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 11;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return 13;
        }
    }

// ---- The reaction bands ----

// when an animal is exposed to one of the Table 42 conditions, the Dungeon
// Master rolls 1d12 to ascertain the animal's reaction
inline int wmbReactDie()
    { return 12; }

// a result equal to or greater than the leftmost number means the animal has
// noticed the condition, sometimes before any characters have perceived it:
// noticeably nervous or excited, pacing or prancing skittishly and making
// vocal sounds for no apparent reason
inline bool wmbReactNoticed()
    { return true; }

// a result equal to or greater than the second number means the animal may
// become agitated: unless a character takes steps to calm or control it
// within two rounds, the abnormal behavior becomes more pronounced - it will
// refuse to move, or proceed very cautiously, if forced to travel toward the
// threat it perceives
inline bool wmbReactAgitated()
    { return true; }

// the window to calm or control an excited animal before its behavior
// worsens: within two rounds
inline int wmbReactCalmRounds()
    { return 2; }

// if the character has not figured out what is bothering the animal by the
// time it becomes agitated, it is a good idea to trust the animal's instinct:
// do not force it to move in a direction it does not want to go, or better
// yet allow it to move in a direction of its choosing
inline bool wmbReactTrustInstinct()
    { return true; }

// a result equal to or greater than the third number, if one is given, means
// the animal may become panicked: unless calmed and brought under control
// within two rounds of when it became excited, it will behave in a manner
// that seems utterly irrational but is motivated by self-preservation, doing
// everything in its power to move away from the perceived threat
inline bool wmbReactPanicked()
    { return true; }

// the panicked animal is utterly uncontrollable by normal nonmagical means:
// 2d3 turns - the dice count
inline int wmbReactPanicDice()
    { return 2; }

// the panicked-uncontrollable duration die: 2d3 turns
inline int wmbReactPanicDie()
    { return 3; }

// the panicked animal remains uncontrollable for the 2d3 turns or until it
// has moved sufficiently far away from the threat, whichever amount of time
// is greater
inline bool wmbReactPanicDuration()
    { return true; }

// if no third number is given in the Table 42 entry, the animal will not
// become panicked from that condition
inline bool wmbReactNoThirdNoPanic()
    { return true; }

// fire frightens an animal more than any other force or source of energy
// found in nature; even an animal that has never seen a fire knows
// instinctively that flames are to be avoided - this also applies to
// non-flaming natural heat sources such as flowing lava, and to magical fire
// that produces heat, but not to a flamelike phenomenon that does not give
// off heat, such as a faerie fire spell
inline bool wmbFireGreatest()
    { return true; }

// an animal can become accustomed to the nearby presence of a small fire if
// it learns to associate the fire with something good - tie the horse, build
// the campfire, then feed it or let it graze; after a few days of the
// sequence it may actually look forward to the evening fire
inline bool wmbFireCampfireHabit()
    { return true; }

// no animal will ever be comfortable in the vicinity of any blaze larger than
// a normal campfire, regardless of how many times it is exposed to a large
// fire without being harmed
inline bool wmbFireNeverComfortableLarge()
    { return true; }

// an animal may sense the presence of a bonfire or similarly large blaze - a
// burning building, a wall of fire spell - from as far away as one-quarter
// mile, and an even larger conflagration such as a forest fire or grass fire
// covering a large area from one mile, usually long before a character is
// aware the fire is nearby
inline bool wmbFireSensing()
    { return true; }

// the large-blaze sensing distance: one-quarter mile - the numerator
inline int wmbFireBonfireMiNum()
    { return 1; }

// the large-blaze sensing distance: one-quarter mile - the denominator
inline int wmbFireBonfireMiDen()
    { return 4; }

// the forest-fire-scale conflagration sensing distance: one mile
inline int wmbFireConflagrationMi()
    { return 1; }

// weather changes are noticeable to animals before the signs come within
// sight range of characters; an animal becomes excited when it senses any
// upcoming significant change, such as an approaching moderate rainstorm, but
// becomes agitated or panicked only if the change is very drastic and very
// imminent, such as an approaching lightning storm or tornado - extremely
// unusual behavior with no other obvious cause may mean hazardous weather is
// on the way
inline bool wmbWeatherSenseDetail()
    { return true; }

// noise in this context is a sound loud enough and sharp enough to startle a
// nearby animal - a shout, a crack of thunder, the clang of a sword on a
// metal shield; an animal can become accustomed to a particular noise through
// frequent exposure, such as simulated combat complete with whoops, growls
// and clangs during training to prevent panic in melee
inline bool wmbNoiseDetail()
    { return true; }

// an animal with exceptionally sensitive hearing will not become agitated or
// panicked when it detects a sound inaudible to its rider or owner, though it
// may become excited - a character with proficiency in animal lore might
// ascertain the nature of what the animal is reacting to
inline bool wmbSharpHearing()
    { return true; }

// odor will only produce an extreme reaction when the scent is strong and
// pungent, which usually means it can be smelled by a character as well; an
// animal with an exceptionally sensitive nose will not become agitated or
// panicked by an odor too faint for a character to perceive, unless the
// animal associates the odor with something harmful or unpleasant
inline bool wmbOdorDetail()
    { return true; }

// the other column covers a wide range of stimuli - some little thing that
// goes unnoticed by characters and most animals but excites, agitates or
// panics a certain animal: a quirk that personalizes it, like the donkey that
// plods through a mosquito-infested swamp oblivious to bugs on its snout but
// flies into a bucking frenzy when one gets inside its ear, the elephant that
// refuses a shallow stream unless relieved of its entire burden, the lead
// sled dog that refuses light snow crust and thereby saves the party on thin
// ice, and the bear-scarred horse that will not tolerate a bear as a pack
// animal but sounds the alarm long before a wild bear approaches the campsite
inline bool wmbOtherQuirks()
    { return true; }

// ---- Calming an excited animal ----

// any character can try to soothe an animal that has become excited
inline bool wmbCalmAnyoneTries()
    { return true; }

// someone with proficiency in animal handling has a reasonably good chance of
// calming the beast, assuming he has an above-average wisdom score
inline bool wmbCalmProfChance()
    { return true; }

// a proficient character can make a new attempt every round if his previous
// attempt failed, or if more than one animal is excited
inline bool wmbCalmProfEveryRound()
    { return true; }

// a character without proficiency in animal handling has a straight 20
// percent chance of bringing an excited animal under control
inline int wmbCalmNonprofPct()
    { return 20; }

// a nonproficient character can only make two such attempts on the same
// animal, in successive rounds if desired
inline int wmbCalmNonprofAttempts()
    { return 2; }

// any character who attempts to calm an animal can take no other action in
// the same round except for movement, if necessary
inline bool wmbCalmOnlyMove()
    { return true; }

// if an animal is in motion when it becomes excited, it will remain in
// motion; if it is stationary, it will either remain still or begin moving,
// with an even chance of each occurrence
inline bool wmbCalmMotionState()
    { return true; }

// the stationary excited animal splits evenly: a 50 percent chance of each of
// remaining still or beginning to move
inline int wmbCalmMovePct()
    { return 50; }

// a character attempting to soothe a moving animal must either be riding it
// or be able to keep up with it as it moves along
inline bool wmbCalmSootheMoving()
    { return true; }

// if an animal becomes agitated or panicked, only a character with
// proficiency in animal handling has any chance of calming the beast
inline bool wmbCalmAgitatedProfOnly()
    { return true; }

// the calming Proficiency Check is made with a +2 modifier to the die roll if
// the animal is agitated
inline int wmbCalmAgitatedMod()
    { return 2; }

// the calming Proficiency Check is made with a +4 modifier to the die roll if
// the animal is panicked
inline int wmbCalmPanickedMod()
    { return 4; }

// even if an animal is calmed, there is no guarantee it will not become
// excited again in the following round: if the condition that upset it is
// still evident to the animal, it may become excited all over again and
// require the constant attention of an animal handler to prevent it from
// doing something drastic
inline bool wmbCalmReexcite()
    { return true; }

// ---- Understanding an animal ----

// a character with proficiency in animal lore has the ability - partially
// innate, partially learned - to make at least an educated guess about why an
// animal is acting a certain way, even if the reason for its behavior is not
// obvious to the character
inline bool wmbUnderstandProf()
    { return true; }

// a character without the proficiency may still draw logical conclusions from
// what his physical senses tell him - thunder and a skittish horse - but he
// can guess and cannot always know what is bothering his mount
inline bool wmbUnderstandNonprof()
    { return true; }

// in contrast, the proficient character can usually determine the cause with
// certainty, which also has the effect of ruling out any other possibilities
inline bool wmbUnderstandCertainty()
    { return true; }

}   // namespace rules
