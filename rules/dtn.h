// =========================================================================================
// Adnd1 - rules/dtn.h
// The Dragon issue-10 opener, part one - the Orgies Inc. article (folios
// 5-6), the Clifton wilderness article (folio 7) and the Random Monsters
// article (folios 9-10): three adjudicated chains in one round, the issue-10
// part-two chains to follow
// census 836 -> 837.
//
// Pinned from The Dragon Vol. 2 No. 4 (October 1977), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 10;
// the source lives in the archive.org item accessory-dragon-magazine-012).
// The folios: 5-6, the Pickens D&D Option: ORGIES, INC. article - experience
// only as treasure is spent, the GP expenditure divided by level capped at
// the class hit-dice allowance, the divisor riding treasure experience only,
// the sacrifice class with its weekly window, tithes and the 100-GP-per-level
// wish or favor option, the lawful-only philanthropy, the MU and alchemist
// research at 250 GP per level per day, the clan-hoard class with no
// withdrawals, the orgy class at 500 GP per level per night halved to 250
// recuperating under 50% with the constitution-days cycle, the halved
// hireling experience, no experience for upkeep, salaries, equipment,
// luxuries or investments, the level-10 fief example at 3400 of 240,000, the
// specialist divisor of 10 for fiefholders, the 500-GP mill returning 100-600
// annually per 100 people, the 60-40 house edge with the halved En Garde
// winnings, and the psionic appendix - 20 GP per psionic point, 100 GP per
// 10% cumulative ability-loss roll, an ability back per 100 psionic points
// regained; 7, the Clifton Designing For Unique Wilderness Encounters article
// - the four-foot-square battlefield, the river across the field at 10% with
// the ford at a further 10%, the swimmer forcing the river onto the field,
// the road bridge or ford, the initial run in four directions with the
// clockwise, straight and counterclockwise courses, the slope facing toward
// or away from the high ground, the 75% slope turn at a watercourse, the
// clear, rough, mountainous, wooded and marshy feature bands with their
// grades - gentle at one level, steep at three - and their roll-again tables,
// the doubled surprise and 20-120 foot sighting in dense woods, the 20-100
// yard sighting in light woods, the halved surprise at maximum sighting in
// clear featureless corners, the opposite-corner placement and the
// proportionate thinning of slopes and streams at larger areas; 9-10, the
// Crabaugh Random Monsters article - the 20-level dungeon basis, the d8 type
// band across mammal, reptile and undead, the intelligence band, the hit-dice
// modifier bands from +2 to -1, the hit-dice AC table for mammal and reptile,
// the level-offset column from +3 at die 1 to -2 at die 12 with the
// dungeon-level meaning, the undead turning as undead of level HD/2 with the
// vampire threshold at 17 and the (1-8)+1 undead AC, and the weapon-or-bite
// damage doctrine by intelligence. The transcripts ride extract/dragon/010/
// (all 34 issue pages); the issue-10 gap report ships pre-flip with its two
// part boxes. PRINT FOLIO = PDF PAGE, verified at the printed 10, 19 and 21
// footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// the Orgies Inc. experience-as-spent option - though it echoes the later
// training-cost doctrine - pins as a variant layer with provenance, never
// core canon. The print quirks ride AS SCANNED, noted, never silent: the
// Random Monsters speed table garbled (the '47' band), the
// special-characteristics grid without its d% axis, the damage grid's '='
// artifacts, the size table's missing small cells and the limbs and exterior
// tables all ride the transcript whole, never guessed; the hit-dice AC
// table's row-12 reptile cell garbled - the band pins, the cell rides
// sentinel; the Clifton '46-600' band reads 46-60 by the print's own band
// arithmetic and the displaced Clear tail rows sit by contiguity; the Snits
// game and the Stellar Conquest diplomacy article scoped out as other
// systems. The editor's standing caution rides: none of this is official.
//
namespace rules {

// ---- the Orgies Inc. article (folios 5-6) ----

// the orgy expenditure maximum, 500 GP per level per night (folio 5)
inline int dtnOrgyMaxGpPerLevel()
    { return 500; }

// the orgy maximum halved to 250 GP when recuperating and under 50% (folio 5)
inline int dtnOrgyRecuperatingMaxGp()
    { return 250; }

// the research expenditure rate, up to 250 GP per level per day for the MU or
// alchemist in his chambers (folio 5)
inline int dtnResearchGpPerLevelDay()
    { return 250; }

// the referee option - a sacrifice of at least 100 GP per level of the giver
// earns a wish or favor (folio 5)
inline int dtnSacrificeFavorGpPerLevel()
    { return 100; }

// the fiefholder specialist cost reduced by a factor of 10, excepting
// assassins and spies (folio 6)
inline int dtnSpecialistFiefDivisor()
    { return 10; }

// the fief income example - a level 10 lord with eight villages of 400 picks
// up 3400 experience points (folio 6)
inline int dtnFiefExampleXp()
    { return 3400; }

// the fief income example total needed for the next level, 240,000 (folio 6)
inline int dtnFiefExampleNeed()
    { return 240000; }

// the fixed investment example - a water-powered mill costing 500 GP (folio
// 6)
inline int dtnMillCostGp()
    { return 500; }

// the mill returns 100-600 GP annually per 100 people within a day march
// (folio 6)
inline int dtnMillAnnualMinGp()
    { return 100; }

// the mill annual return maximum (folio 6)
inline int dtnMillAnnualMaxGp()
    { return 600; }

// the mill return denominator - per 100 people within a day march (folio 6)
inline int dtnMillPeoplePer()
    { return 100; }

// the gambling house rule - the odds at least 60-40 in favor of the House
// (folio 6)
inline int dtnHouseMinEdgePct()
    { return 60; }

// the appendix II psionic rule - each 20 GP spent on an orgy reduces psionic
// point level by one (folio 6)
inline int dtnPsionicGpPerPoint()
    { return 20; }

// every 100 GP spent carries a 10% cumulative chance of eliminating one
// special ability (folio 6)
inline int dtnPsionicGpPerAbilityRoll()
    { return 100; }

// the cumulative special-ability loss chance per 100 GP (folio 6)
inline int dtnPsionicAbilityLossPct()
    { return 10; }

// a special ability returns with each 100 psionic points regained, or all
// lost points regenerate, whichever is least (folio 6)
inline int dtnPsionicAbilityRegenPoints()
    { return 100; }

// the author's frame - in this article Lawful equals Good and Chaotic equals
// Evil (folio 5)
inline bool dtnLawfulGoodEquivalence()
    { return true; }

// the core option - players receive experience only as the treasure is spent,
// not as it is gained (folio 5)
inline bool dtnXpOnlyAsSpent()
    { return true; }

// the expenditure in GP is divided by the level of the character, the divisor
// limited to the hit dice allowed for the class (folio 5)
inline bool dtnXpDivisorIsLevelCappedAtHD()
    { return true; }

// the divisor is used only for treasure experience - monster kills and
// miscellaneous awards are untouched (folio 5)
inline bool dtnDivisorTreasureXpOnly()
    { return true; }

// the sacrifice offering may be made once per week and within one week of
// acquisition, tithes counting; payment or bribe never counts (folio 5)
inline bool dtnSacrificeWeeklyWindow()
    { return true; }

// the philanthropy class - lawfuls only, aid to the poor or any NPC not a
// hireling, a real need required, or the local lawful church (folio 5)
inline bool dtnPhilanthropyLawfulOnly()
    { return true; }

// the research class - magic users and alchemists only, spell research
// counting, production not, never simultaneous (folio 5)
inline bool dtnResearchMuAlchemistOnly()
    { return true; }

// the clan-hoard class - dwarves and clannish folk, members only, no
// withdrawals ever (folio 5)
inline bool dtnClanHoardsClannishOnly()
    { return true; }

// the orgy class - fighting men excluding rangers and paladins, bards,
// thieves and all chaotics excluding monks (folio 5)
inline bool dtnOrgyClassesOnly()
    { return true; }

// a player may orgy as many days as he has constitution points, then must
// rest as many days as he orgied (folio 5)
inline bool dtnOrgyConstitutionDays()
    { return true; }

// hirelings may buy experience with their pay, halved for non-player
// characters (folio 5)
inline bool dtnHirelingXpHalved()
    { return true; }

// general maintenance, upkeep, advertisement, salaries, equipment, luxuries
// and investments yield no experience, investment income may (folio 5)
inline bool dtnNoXpForUpkeep()
    { return true; }

// ---- the Clifton wilderness article (folio 7) ----

// a river flowing through the hex has a 10% chance to flow across the field
// (folio 7)
inline int dtnRiverAcrossFieldPct()
    { return 10; }

// an additional 10% chance the river has a ford (folio 7)
inline int dtnRiverFordChancePct()
    { return 10; }

// a slope crossing a river or stream has a 75% chance to turn, face the
// watercourse and run parallel off the field (folio 7)
inline int dtnSlopeTurnsToWaterPct()
    { return 75; }

// dense woods - normal sighting distance between 20 and 120 feet (folio 7)
inline int dtnDenseWoodsSightingMinFt()
    { return 20; }

// the dense woods sighting maximum in feet (folio 7)
inline int dtnDenseWoodsSightingMaxFt()
    { return 120; }

// light woods - normal sighting distance between 20 and 100 yards (folio 7)
inline int dtnLightWoodsSightingMinYds()
    { return 20; }

// the light woods sighting maximum in yards (folio 7)
inline int dtnLightWoodsSightingMaxYds()
    { return 100; }

// the grade indicates height - a gentle slope is one level (folio 7)
inline int dtnGentleGradeLevels()
    { return 1; }

// a steep slope is three levels (folio 7)
inline int dtnSteepGradeLevels()
    { return 3; }

// the initial run of rivers, streams and slopes - four courses, north-south,
// northeast-southwest, east-west, northwest-southeast (folio 7)
inline int dtnRiverRunDirections()
    { return 4; }

// the encounter field - a four foot square area with terrain determined to
// each corner section of four square feet (folio 7)
inline bool dtnFourFootSquareEncounter()
    { return true; }

// if an encounter with a swimmer is indicated the river is always on the
// field (folio 7)
inline bool dtnSwimmerForcesRiver()
    { return true; }

// a party travelling on a road finds an appropriate bridge or ford at the
// river (folio 7)
inline bool dtnRoadBridgesRiver()
    { return true; }

// if either side is located in dense woods, chances of surprise are doubled
// (folio 7)
inline bool dtnDenseWoodsDoubleSurprise()
    { return true; }

// if both are in featureless areas with clear lines of sight, chances of
// surprise are halved and sighting distance is always maximum (folio 7)
inline bool dtnClearHalveSurprise()
    { return true; }

// monsters and party are placed in opposite corner sections (folio 7)
inline bool dtnOppositeCorners()
    { return true; }

// mapping larger areas decreases the possibility of slopes and streams in
// proportion to the increase in area (folio 7)
inline bool dtnLargerAreaFewerFeatures()
    { return true; }

// the clear terrain feature bands - featureless, hill, rough ground, marsh,
// slope, light woods, stream, pond (folio 7)
inline int dtnClearFeature(int x)
    {
        if (x <= 70) return 0;
        if (x <= 77) return 1;
        if (x <= 82) return 2;
        if (x <= 84) return 3;
        if (x <= 88) return 4;
        if (x <= 93) return 5;
        if (x <= 97) return 6;
        return 7;
    }

// the rough terrain feature bands - featureless, hill, rough ground, slope,
// dense brush, light woods, dense woods, marsh, stream, pond, the 46-600 OCR
// band reading 46-60 by the print arithmetic (folio 7)
inline int dtnRoughFeature(int x)
    {
        if (x <= 25) return 0;
        if (x <= 45) return 1;
        if (x <= 60) return 2;
        if (x <= 70) return 3;
        if (x <= 77) return 4;
        if (x <= 85) return 5;
        if (x <= 89) return 6;
        if (x <= 91) return 7;
        if (x <= 95) return 8;
        return 9;
    }

// the mountainous terrain feature bands - featureless, slope, hill, rough
// ground, dense brush, light woods, dense woods, stream (folio 7)
inline int dtnMountainFeature(int x)
    {
        if (x <= 15) return 0;
        if (x <= 55) return 1;
        if (x <= 60) return 2;
        if (x <= 70) return 3;
        if (x <= 75) return 4;
        if (x <= 87) return 5;
        if (x <= 95) return 6;
        return 7;
    }

// the wooded terrain feature bands - featureless, dense woods, light woods,
// dense brush, rough ground, slope, hill, marsh, stream, pond (folio 7)
inline int dtnWoodedFeature(int x)
    {
        if (x <= 5) return 0;
        if (x <= 40) return 1;
        if (x <= 60) return 2;
        if (x <= 65) return 3;
        if (x <= 68) return 4;
        if (x <= 75) return 5;
        if (x <= 89) return 6;
        if (x <= 91) return 7;
        if (x <= 95) return 8;
        return 9;
    }

// the marshy terrain feature bands - featureless, marsh, pond, stream, dense
// brush, rough ground, dense woods, light woods, gentle hill (folio 7)
inline int dtnMarshyFeature(int x)
    {
        if (x <= 5) return 0;
        if (x <= 25) return 1;
        if (x <= 55) return 2;
        if (x <= 65) return 3;
        if (x <= 80) return 4;
        if (x <= 85) return 5;
        if (x <= 93) return 6;
        if (x <= 98) return 7;
        return 8;
    }

// the clear grade bands - gentle 1-60, average 61-90, steep 91-98, sheer
// 99-00 (folio 7)
inline int dtnClearGrade(int x)
    {
        if (x <= 60) return 0;
        if (x <= 90) return 1;
        if (x <= 98) return 2;
        return 3;
    }

// the rough grade bands - gentle 1-35, average 36-75, steep 76-95, sheer
// 96-00 (folio 7)
inline int dtnRoughGrade(int x)
    {
        if (x <= 35) return 0;
        if (x <= 75) return 1;
        if (x <= 95) return 2;
        return 3;
    }

// the mountainous grade bands - gentle 1-5, average 6-30, steep 31-85, sheer
// 86-00 (folio 7)
inline int dtnMountainGrade(int x)
    {
        if (x <= 5) return 0;
        if (x <= 30) return 1;
        if (x <= 85) return 2;
        return 3;
    }

// the wooded grade bands - gentle 1-50, average 51-85, steep 86-96, sheer
// 97-00 (folio 7)
inline int dtnWoodedGrade(int x)
    {
        if (x <= 50) return 0;
        if (x <= 85) return 1;
        if (x <= 96) return 2;
        return 3;
    }

// the clear roll-again bands - no additional features 1-90, additional light
// woods 91-95, additional rough ground 96-00 (folio 7)
inline int dtnClearExtra(int x)
    {
        if (x <= 90) return 0;
        if (x <= 95) return 1;
        return 2;
    }

// the rough roll-again bands - none, rough ground, dense brush, light woods,
// dense woods (folio 7)
inline int dtnRoughExtra(int x)
    {
        if (x <= 60) return 0;
        if (x <= 75) return 1;
        if (x <= 81) return 2;
        if (x <= 94) return 3;
        return 4;
    }

// the mountainous roll-again bands - none, rough ground, dense brush, light
// woods, dense woods (folio 7)
inline int dtnMountainExtra(int x)
    {
        if (x <= 60) return 0;
        if (x <= 70) return 1;
        if (x <= 77) return 2;
        if (x <= 91) return 3;
        return 4;
    }

// the wooded roll-again bands - none, dense woods, light woods, rough ground,
// dense brush (folio 7)
inline int dtnWoodedExtra(int x)
    {
        if (x <= 15) return 0;
        if (x <= 60) return 1;
        if (x <= 90) return 2;
        if (x <= 94) return 3;
        return 4;
    }

// the marshy roll-again bands - none, marsh (none if hill), dense brush,
// rough ground, dense woods, light woods (folio 7)
inline int dtnMarshyExtra(int x)
    {
        if (x <= 5) return 0;
        if (x <= 50) return 1;
        if (x <= 70) return 2;
        if (x <= 80) return 3;
        if (x <= 93) return 4;
        return 5;
    }

// the course of runs - 1-2 turns clockwise, 3-4 goes straight, 5-6 turns
// counterclockwise (folio 7)
inline int dtnRiverCourse(int x)
    {
        if (x <= 2) return 0;
        if (x <= 4) return 1;
        return 2;
    }

// the facing of slopes - 1-2 faces the high ground, 3-6 faces away (folio 7)
inline int dtnSlopeFacing(int x)
    {
        if (x <= 2) return 0;
        return 1;
    }

// ---- the Random Monsters article (folios 9-10) ----

// the tables geared to a 20-level dungeon, each level populated by monsters
// of the same level (folio 9)
inline int dtnRMDungeonLevels()
    { return 20; }

// undead are turned by clerics as if they were undead of level HD/2 - a 2HD
// undead saves as a zombie (folio 9)
inline int dtnRMUndeadTurnDivisor()
    { return 2; }

// undead of level 17+ are treated as vampires (folio 9)
inline int dtnRMVampireAtLevel()
    { return 17; }

// the undead AC roll - (1-8) + 1 (folio 9)
inline int dtnRMUndeadACBonus()
    { return 1; }

// the hit-dice modifier bands - four d6 bands (folio 9)
inline int dtnRMHDBands()
    { return 4; }

// the hit-dice AC bands - six d12 bands, the row-12 reptile cell garbled in
// the OCR and riding the transcript (folio 9)
inline int dtnRMACBands()
    { return 6; }

// the level-offset bands - six d12 bands from die 1 at +3 to die 12 at -2
// (folio 9)
inline int dtnRMLevelBands()
    { return 6; }

// intelligent monsters do damage by weapon type, unintelligent by bite,
// semi-intelligent 50% chance of each (folio 10)
inline bool dtnRMIntelligentWeaponDamage()
    { return true; }

// the type band - 1-4 mammal, 5-7 reptile, 8 undead (folio 9)
inline int dtnRMTypeBand(int x)
    {
        if (x <= 4) return 0;
        if (x <= 7) return 1;
        return 2;
    }

// the intelligence band - 1-3 highly intelligent, 4-5 semi-intelligent, 6
// unintelligent (folio 9)
inline int dtnRMIntelligenceBand(int x)
    {
        if (x <= 3) return 0;
        if (x <= 5) return 1;
        return 2;
    }

// the hit-dice modifier per d6 band - 1 at +2, 2-3 at +1, 4-5 at 0, 6 at -1
// (folio 9)
inline int dtnRMHDMod(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return -1;
        default:
            return -1;
        }
    }

// the mammal AC per hit-dice d12 band - die 1 at AC 3 through die 12 at AC 8
// (folio 9)
inline int dtnRMACMammal(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        default:
            return -1;
        }
    }

// the reptile AC per band - die 1 at AC 2 through die 10-11 at AC 6, the
// die-12 cell garbled in the OCR and riding the transcript (folio 9)
inline int dtnRMACReptile(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return -1;
        default:
            return -1;
        }
    }

// the level offset per hit-dice d12 band - die 1 at level +3, 2-3 at +2, 4-5
// at +1, 6-9 at level, 10-11 at -1, 12 at -2, level meaning the dungeon level
// on this table only, non-positive results treated per the print (folio 9)
inline int dtnRMLevelOffset(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return -1;
        case 5:
            return -2;
        default:
            return -1;
        }
    }

}   // namespace rules
