// ====================================================================
// Adnd1 - rules/dmg/construct.h
// R213: the construction and siege
// economics (DMG pp.106-108) - the
// mining tables, the construction time
// pins, the constructions cost table,
// and the siege engine costs.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the crews and the campaign
// milieu; the tables and factors read
// here).
//
// Conventions and judgments, named in
// place:
//   - Miner order: the print order of
//     the cubic volume table - gnoll,
//     halfling and human first, stone
//     giant last. The rock columns: very
//     soft, soft, hard. The print cells
//     are cubic feet of rock per 8 hours
//     of labor per miner.
//   - Multiple workers: each extra miner
//     adds an appropriate additional
//     volume, providing there is room in
//     the shaft - read as linear (the
//     per-miner figure times the head
//     count).
//   - The shaft: the typical shaft is 10
//     feet wide, arched to a 16 foot (or
//     so) peak; the max miners per
//     10-foot shaft: 16 (dwarf, gnome,
//     goblin, halfling, kobold), 12
//     (hobgoblin, human, orc), 8 (gnoll),
//     6 (ogre), 4 (giant of any type).
//   - Multiple shifts: construction can
//     run 24 hours per day, but no worker
//     may toil more than 8 hours per day -
//     three shifts of fresh workers.
//   - Natural cave areas: limestone (very
//     soft) 1 in 10, other sedimentary
//     (soft) 1 in 50, lava (hard) 1 in
//     20, other igneous (hard) 1 in 100 -
//     pinned as percents (10, 2, 5, 1).
//   - Slave or unwilling labor: 50 to 80
//     percent of normal efficiency, by
//     foreman ratio - 1 per 16 workers is
//     50 percent, 1 per 12 is 60, 1 per 8
//     is 70, 1 per 4 is 80; the guard
//     minimum is 1 comparable guard per 4
//     workers.
//   - Construction time: the ditch (100
//     feet long, 10 deep, 20 wide) assumes
//     a crew of 3-4 men for six weeks;
//     heavy clay doubles the time.
//     Fortress-like stone work takes one
//     week per 10-foot cubic section;
//     adding 50 percent to the
//     expenditure doubles the rate, 250
//     percent triples it - the maximum
//     increase. A normal stone building
//     takes four months; wood takes half
//     of that; wooden hoardings go up at
//     a 10-foot section per day.
//   - The castle estimates: moat house,
//     shell keep or small castle 1 year
//     plus 2-8 months; small castle with
//     outer and inner walls or medium
//     castle 2 years plus 1-6 months;
//     medium castle with outer and inner
//     walls or large castle 3 years plus
//     2-8 months; large concentric castle
//     or walling an average town 5 years
//     plus 1-12 months. The month ranges
//     are pinned as low and high edges
//     (the dice reading is the caller
//     own). Citizens willingly laboring
//     reduce urban walling time by 50
//     percent.
//   - The 44-row CONSTRUCTIONS table: the
//     print order, arrow slit (3 gp)
//     through window shuttered and barred
//     (10 gp).
//   - The per-square-foot adjustments:
//     iron door 2 gp per square foot of
//     added or subtracted half-inch iron;
//     secret door 5 gp per square foot of
//     increased size; trap door 1 silver
//     per added square foot; wooden door
//     2 silver per square foot of
//     alteration; reinforced door 5 silver
//     per square foot; drawbridge 2 gp
//     and portcullis 2 gp per square foot
//     of alteration.
//   - The stone building course formula:
//     wall thickness increases the cost
//     by 10 percent of the initial cost
//     per course of stone (1 foot thick) -
//     the print worked example: the 500 gp
//     building upgraded to 10-foot walls
//     costs 950 gp.
//   - The underground tunnel: dug through
//     soft earth at the listed cost, hard
//     earth +100 percent (x2), solid rock
//     500 percent (x5).
//   - A rampart built immediately above
//     one side of a ditch costs only 20
//     percent of the shown amount.
//   - A 14-foot battlement section has two
//     4-foot merlons and two 3-foot
//     embrasures; buttressing a wall up to
//     20 feet high takes the equivalent
//     of three buttress sections.
//   - The siege engine costs: the print
//     order, ballista (mangonel, scorpion)
//     75 gp through trebuchet 500 gp.
// ====================================================================

#pragma once



// -----------------------------------------------------------------------
// The miner groups and rock columns.
// -----------------------------------------------------------------------
enum MiningGroup {
    MG_GNOLL_HALFLING_HUMAN = 0,
    MG_GNOME_KOBOLD,
    MG_GOBLIN_ORC,
    MG_DWARF_HOBGOBLIN,
    MG_OGRE,
    MG_HILL_GIANT,
    MG_FIRE_FROST_GIANT,
    MG_STONE_GIANT,
    MG_COUNT
};


enum MineRock {
    MRK_VERY_SOFT = 0,
    MRK_SOFT,
    MRK_HARD,
};



// -----------------------------------------------------------------------
// The shaft capacity and the shifts.
// -----------------------------------------------------------------------
enum ShaftGroup {
    SG_SMALL = 0,
    SG_MAN,
    SG_GNOLL,
    SG_OGRE,
    SG_GIANT_ANY,
    SG_COUNT
};



// -----------------------------------------------------------------------
// The natural cave area chances (percents).
// -----------------------------------------------------------------------
enum NaturalRock {
    NR_LIMESTONE_VERY_SOFT = 0,
    NR_OTHER_SEDIMENTARY_SOFT,
    NR_LAVA_HARD,
    NR_OTHER_IGNEOUS_HARD,
    NR_COUNT
};


enum CastleKind {
    CK_MOAT_HOUSE_SHELL_KEEP_SMALL = 0,
    CK_SMALL_CASTLE_MEDIUM,
    CK_MEDIUM_CASTLE_LARGE,
    CK_LARGE_CONCENTRIC_WALLING_TOWN,
    CK_COUNT
};



// -----------------------------------------------------------------------
// The constructions cost table: 44 rows,
// the print order, gold pieces.
// -----------------------------------------------------------------------
enum ConsItem {
    CI_ARROW_SLIT = 0,
    CI_ARROW_SLIT_CROSLETTED,
    CI_BARBICAN,
    CI_BARTIZAN,
    CI_BATTER_PLINTH_SPLAY,
    CI_BATTLEMENT,
    CI_BUILDING_STONE,
    CI_BUILDING_WOOD,
    CI_BUTTRESS_STONE,
    CI_CATWALK_WOODEN,
    CI_DITCH,
    CI_DOOR_IRON,
    CI_DOOR_SECRET,
    CI_DOOR_TRAP,
    CI_DOOR_WOODEN,
    CI_DOOR_WOODEN_REINFORCED,
    CI_DRAWBRIDGE,
    CI_EMBRASURE_SHUTTERS,
    CI_GATEHOUSE_STONE,
    CI_HOARDINGS_WOODEN,
    CI_MACHICOLATION_STONE,
    CI_MERLON,
    CI_MERLON_PIERCED,
    CI_MOAT,
    CI_MURDER_HOLE,
    CI_PALISADE_WOODEN,
    CI_PARAPET_STONE,
    CI_PILASTER,
    CI_PIT,
    CI_PORTCULLIS,
    CI_RAMPART_EARTH,
    CI_STAIRS_STONE,
    CI_STAIRS_WOODEN,
    CI_TOWER_ROUND_20,
    CI_TOWER_ROUND_30,
    CI_TOWER_ROUND_40,
    CI_TOWER_SQUARE_10,
    CI_TOWER_SQUARE_20,
    CI_TOWER_SQUARE_30,
    CI_TUNNEL,
    CI_WALL_BASTION,
    CI_WALL_CURTAIN,
    CI_WINDOW_SHUTTERED,
    CI_WINDOW_SHUTTERED_BARRED,
    CI_COUNT
};


enum TunnelGround {
    TG_SOFT_EARTH = 0,
    TG_HARD_EARTH,
    TG_SOLID_ROCK,
    TG_COUNT
};


enum SiegeDevice {
    SD_BALLISTA = 0,
    SD_CATAPULT_HEAVY,
    SD_CATAPULT_LIGHT,
    SD_CAULDRON,
    SD_GALLERY,
    SD_HOIST,
    SD_MANTLET,
    SD_RAM,
    SD_RAM_CATCHER,
    SD_SIEGE_TOWER,
    SD_SOW,
    SD_TREBUCHET,
    SD_COUNT
};

// R-refactor: namespace rules -> class Construct (instance methods)
class Construct {
public:
    int miningGroupCount();
    int miningCubicFeetPer8h(int group, int rock);
    int miningVolumeCubicFeet(int group, int rock, int miners);
    int shaftMaxMiners(int group);
    int shaftWidthFeet();
    int shaftPeakFeet();
    int constructionHoursPerDay();
    int workerMaxHoursPerDay();
    int maxShiftsPerDay();
    int naturalCaveChancePct(int rock);


// -----------------------------------------------------------------------
// The slave or unwilling labor efficiency.
// -----------------------------------------------------------------------
    int slaveGuardPerWorkers();
    int slaveEfficiencyMinPct();
    int slaveEfficiencyMaxPct();
    int slaveEfficiencyPct(int workersPerForeman);


// -----------------------------------------------------------------------
// The construction time pins.
// -----------------------------------------------------------------------
    int ditchCrewMin();
    int ditchCrewMax();
    int ditchWeeks();
    int heavyClayTimeFactor();
    int stoneFortressWeeksPer10FootCube();
    int stoneRateFactor(int costPct);
    int stoneBuildingMonths();
    int woodBuildingMonths();
    int hoardingsFeetPerDay();
    int castleYears(int kind);
    int castleExtraMonthsMin(int kind);
    int castleExtraMonthsMax(int kind);
    int citizenLaborTimePct();
    int constructionItemCount();
    int constructionCost(int item);


// -----------------------------------------------------------------------
// The per-square-foot adjustment rates.
// -----------------------------------------------------------------------
    int doorIronAdjustGpPerSqFt();
    int doorSecretLargerGpPerSqFt();
    int doorTrapAdjustSpPerSqFt();
    int doorWoodenAdjustSpPerSqFt();
    int doorReinforcedAdjustSpPerSqFt();
    int drawbridgeAdjustGpPerSqFt();
    int portcullisAdjustGpPerSqFt();


// -----------------------------------------------------------------------
// The stone course formula and the tunnel
// ground factors.
// -----------------------------------------------------------------------
    int buildingStoneCoursePct();
    int buildingStoneCostCourses(int baseGp, int courses);
    int tunnelCostFactor(int ground);


// -----------------------------------------------------------------------
// The combination clauses and the siege
// engine costs.
// -----------------------------------------------------------------------
    int rampartAboveDitchCostPct();
    int battlementSectionFeet();
    int battlementMerlons();
    int battlementMerlonWidthFeet();
    int battlementEmbrasures();
    int battlementEmbrasureWidthFeet();
    int buttressSectionsPer20Feet();
    int siegeDeviceCount();
    int siegeDeviceCost(int device);
};
