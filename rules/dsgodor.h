// =========================================================================================
// Adnd1 - rules/dsgodor.h
// The DSG ODOR DETECTION, R510: the printed pp. 37-38 (pdf 38-39) - the
// opener (the sense of smell giving advance warning of nearby hazards, useful
// only with no overpowering scent nearby), the Wisdom Check procedure (at
// first encounter, secret and non-repeating, rechecked only on a stronger
// scent or a harder wind, full Wisdom only for easily-noticed odors), the dog
// rules (Wisdom 16 for this check only, the doubled distance before the
// negative modifiers, described reactions and trained responses), the Table
// 15 row definitions (the fire sizes at 1 and 6-8 feet, the oil and
// conflagration categories, the odorous gases, the three creature odor
// strengths with the 50% lair-scent roll, cooking food), the Table 15
// detection grid across the four distance bands with the printed dash for no
// detection, the Table 16 wind effects on odors (strong, medium and light
// winds against upwind, crosswind and downwind sources) and the wind
// definitions (upwind from the source, downwind away, crosswind
// perpendicular; strong winds extinguishing torches, medium flickering them,
// light almost unnoticeable)
// census 434 -> 435.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read - every numeric cell
// dual-confirmed, with a THREE-WAY settlement for the disputed small-fires
// row: the chapter djvu read "9, -4, -8, (c)" is corrected by the book's own
// compiled-tables appendix reprint (djvu.txt line 15520: "small 0 -4 -B -")
// and by the design ladder (every other cell even, the rows stepping in 2s
// and 4s) to 0, -4, -8, dash; the appendix garbles *2 = +2, T. = -4, 22 = -2,
// =6 = -6, =2 = -2, -B = -8; the Table 16 garbles 110 = 1/10, I4 = 1/4, the
// Acrobat 112 = 1/2. The CAVE-INS heading and the causes prose on the same
// printed page start the NEXT round per the content-density rule (the
// R507-to-R508 tail precedent).
//
// Table 15 pins as a 9x5 grid with the -99 sentinel for the printed dash
// (sentinel census 0/0/0/1/3: the small row and mild-odor row undetectable at
// 1000-5000 feet, the no-odor row undetectable past 360 feet). Table 16 pins
// in the percent-of-distance encoding: Normal 100, 1/2 = 50, No detection 0,
// Double 200, 1/10 = 10, 1/4 = 25. The R509 dnaOdorlessGasNoWisCheck pin is
// the p. 37 prose seam of this section - nothing auto-credited.
//
namespace rules {

// ---- the odor detection procedure ----

// the basic procedure for a character to detect an odor is a Wisdom Check
// made when the scent is first encountered.
inline bool dnvOdorWisCheckOnFirstEncounter()
    { return true; }

// another check may be made if the scent grows very strong.
inline bool dnvOdorRecheckOnStrongerScent()
    { return true; }

// another check may also be made if a change in the wind carries the scent to
// the character with increased force.
inline bool dnvOdorRecheckOnWindShift()
    { return true; }

// this sense is only useful to a character when no other overpowering scent
// is in close proximity to him or permeating the area.
inline bool dnvOdorOnlyWithoutOverpoweringScent()
    { return true; }

// the Wisdom Check should be made by the DM so that the players are not
// alerted that they should be on the lookout for something.
inline bool dnvOdorCheckMadeByDm()
    { return true; }

// if an odor is not noticed when it is first encountered, it will probably
// not be noticed thereafter unless something occurs to draw the characters'
// attention to it.
inline bool dnvOdorNotRepeatedIfMissed()
    { return true; }

// the Wisdom Check is only made using the character's full Wisdom score if
// the odor is strong enough to be easily noticed - the strength of an odor is
// a DM judgment call.
inline bool dnvOdorFullWisOnlyIfEasilyNoticed()
    { return true; }

// the number found by cross-referencing the source of the odor with the
// character's distance from the source is a modifier to the Wisdom Check.
inline bool dnvOdorCrossRefIsWisMod()
    { return true; }

// a dash in the Table 15 grid indicates that the odor cannot be detected that
// far away.
inline bool dnvOdorDashMeansNoDetection()
    { return true; }

// ---- the dog checks ----

// if the party has any dogs accompanying them, the DM may also check for the
// dogs if they would be alerted by the scent - the scent of a monster would
// almost certainly alert them, while the odor of a campfire probably would
// not.
inline bool dnvDogCheckWhenAlerted()
    { return true; }

// dogs are all assumed to have a Wisdom of 16, for purposes of this check
// only.
inline int dnvDogWisScore()
    { return 16; }

// if a dog smells something, the DM should describe the dog's reaction in
// appropriate terms - a growl of warning, perhaps, or a cringe of fear.
inline bool dnvDogReactionDescribed()
    { return true; }

// if a dog has been trained to react in a certain way, then that reaction
// should be used; sophisticated responses require considerable training.
inline bool dnvDogTrainedReactionUsed()
    { return true; }

// if a dog is making the check, double the distance listed on Table 15 before
// implementing the negative modifiers.
inline int dnvOdorDogDistanceMult()
    { return 2; }

// ---- the Table 15 row definitions ----

// small fires are used for cooking or keeping a small group of individuals
// warm; they are generally one foot or less in diameter.
inline int dnvFireSmallMaxDiameterFt()
    { return 1; }

// large fires - bonfires, large campfires, funeral pyres and other relatively
// sizeable but controlled blazes - can be 6-8 feet in diameter: the low end.
inline int dnvFireLargeMinDiameterFt()
    { return 6; }

// a large fire can be 6-8 feet in diameter, with the flames rising even
// higher: the high end.
inline int dnvFireLargeMaxDiameterFt()
    { return 8; }

// oil fires are fires where oil, creosote, or coal is burning; some pungent
// chemicals, when burned, create fires in this category.
inline bool dnvOilFireCategory()
    { return true; }

// conflagrations are huge fires, often burning out of control; a large boat,
// a bridge, or a building creates a conflagration when it burns.
inline bool dnvConflagrationCategory()
    { return true; }

// odorous gases are those with distinctive smells, such as sulphur or methane
// (swamp gas).
inline bool dnvOdorousGasCategory()
    { return true; }

// strong-odor creatures use an odor as a means of marking terrain (such as
// males among the great cats) or defending themselves (such as skunks).
inline bool dnvStrongOdorCreatureCategory()
    { return true; }

// the area near the lair of a strong-odor creature always carries the
// distinctive scent, but it is only 50% likely to be encountered if the
// creature is prowling outside of its lair.
inline int dnvStrongOdorLairPct()
    { return 50; }

// mild-odor creatures are those whose living quarters or presence is
// generally accompanied by a distinctive odor - pigs, most herd animals
// (especially domestic ones), and bands of orcs or other humanoid types with
// somewhat casual personal hygiene habits.
inline bool dnvMildOdorCreatureCategory()
    { return true; }

// no-odor creatures are those that take care to remove sources of odor from
// their lairs - humans fall into this category, as do birds and reptiles.
inline bool dnvNoOdorCreatureCategory()
    { return true; }

// cooking food is just that.
inline bool dnvCookingFoodCategory()
    { return true; }

// ---- the Table 15 distance bands ----

// the first distance band runs 1-120 feet from the source.
inline int dnvOdorBand1MaxFt()
    { return 120; }

// the second distance band opens at 121 feet.
inline int dnvOdorBand2MinFt()
    { return 121; }

// the second distance band closes at 360 feet.
inline int dnvOdorBand2MaxFt()
    { return 360; }

// the third distance band opens at 361 feet.
inline int dnvOdorBand3MinFt()
    { return 361; }

// the third distance band closes at 1000 feet.
inline int dnvOdorBand3MaxFt()
    { return 1000; }

// the fourth distance band opens at 1000 feet.
inline int dnvOdorBand4MinFt()
    { return 1000; }

// the fourth distance band closes at 5000 feet.
inline int dnvOdorBand4MaxFt()
    { return 5000; }

// ---- the Table 15 odor detection grid ----

// the Table 15 carries nine odor sources: four fire sizes, one gas, three
// creature strengths and cooking food.
inline int dnvT15RowCount()
    { return 9; }

// the row key: 0 small fire, 1 large fire, 2 oil fire, 3 conflagration, 4
// odorous gas, 5 strong-odor creature, 6 mild-odor creature, 7 no-odor
// creature, 8 cooking food.
inline int dnvT15Src(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        default:
            return -99;
        }
    }

// the Wisdom Check modifier at 1-120 feet.
inline int dnvT15Mod1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return -2;
        case 7:
            return -6;
        case 8:
            return 2;
        default:
            return -99;
        }
    }

// the Wisdom Check modifier at 121-360 feet.
inline int dnvT15Mod2(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return -2;
        case 6:
            return -6;
        case 7:
            return -10;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the Wisdom Check modifier at 361-1000 feet.
inline int dnvT15Mod3(int b)
    {
        switch (b) {
        case 0:
            return -8;
        case 1:
            return -4;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return -6;
        case 6:
            return -10;
        case 7:
            return -99;
        case 8:
            return -2;
        default:
            return -99;
        }
    }

// the Wisdom Check modifier at 1000-5000 feet; -99 = the printed dash, the
// odor cannot be detected that far away.
inline int dnvT15Mod4(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -8;
        case 2:
            return -4;
        case 3:
            return 0;
        case 4:
            return -4;
        case 5:
            return -10;
        case 6:
            return -99;
        case 7:
            return -99;
        case 8:
            return -6;
        default:
            return -99;
        }
    }

// ---- the Table 16 wind effects grid ----

// the Table 16 carries three wind forces: strong, medium and light.
inline int dnvT16RowCount()
    { return 3; }

// the row key: 0 strong wind, 1 medium wind, 2 light wind.
inline int dnvT16Force(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the percent of the Table 15 detection distance when the wind blows from the
// source toward the character (upwind): 100 = Normal, 200 = Double.
inline int dnvT16Upwind(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 200;
        case 2:
            return 200;
        default:
            return -99;
        }
    }

// the percent of the Table 15 detection distance when the wind blows
// perpendicular to the source-bearing line (crosswind): 100 = Normal, 50 =
// 1/2.
inline int dnvT16Crosswind(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 100;
        default:
            return -99;
        }
    }

// the percent of the Table 15 detection distance when the wind blows the odor
// away from the character (downwind): 0 = No detection, 10 = 1/10, 25 = 1/4.
inline int dnvT16Downwind(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 25;
        default:
            return -99;
        }
    }

// if any currents of air are prevalent in the underground area, the wind
// direction can serve as an additional modifier to odor detection - Table 16
// lists the modifications to the distances at which odors are detectable.
inline bool dnvWindForceModifierWhenCurrents()
    { return true; }

// a distance factor listed as 1/2 on Table 16 means the distances for each of
// the Table 15 categories are reduced to 1/2 of the original.
inline bool dnvWindHalfMeansHalfDistance()
    { return true; }

// ---- the wind definitions ----

// upwind sources mean that the wind is blowing from the direction of the
// odor's source toward the character.
inline bool dnvUpwindDefinition()
    { return true; }

// downwind means that the wind is blowing the odor away from the character.
inline bool dnvDownwindDefinition()
    { return true; }

// crosswind means that the wind is blowing perpendicular to the direction
// between the character and the source of the odor.
inline bool dnvCrosswindDefinition()
    { return true; }

// strong winds are those capable of extinguishing torches and other small
// fires, and of raising clouds of dust.
inline bool dnvStrongWindExtinguishesTorches()
    { return true; }

// medium winds cause torches to flicker, and extinguish small flames such as
// candles.
inline bool dnvMediumWindFlickersTorches()
    { return true; }

// light winds are almost unnoticeable to characters.
inline bool dnvLightWindUnnoticeable()
    { return true; }

}   // namespace rules
