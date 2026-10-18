// =========================================================================================
// Adnd1 - rules/dmoworlds.h
// THE WORLD RATINGS - DMO Chapter 2 continues: Table 2 the chronological
// ladder (one local week = one base second on C2, one hundred base years on
// C20; visitors age at local time, spell durations local), Table 3 the
// magical ladder (dead magic at M2, the ninth-level bar at M8,
// spellbooks-free at M19, study-free at M20; demihumans save vs. death at
// M5-or-less, fantastic penalties from M6; items lose one plus per plane,
// four planes the maximum span), Table 4 the technological ladder (steel at
// 10-12 through FTL at 20; high-tech devices go inert low, advanced tech
// works like magic at a five-point margin), Table 5 the ecological grid
// (constitution, damage, and the poison save at severe, hostile, and deadly),
// and the world quirks (the Ravenloft infusion, the Athas metal bar, the
// named-spell bar, the dominant-race retaliation at M14+, the distance-immune
// world).
// census 524 -> 525.
//
// verified against printed pp. 46-54 of the uploaded DMO session capture
// (part 1, printed page N at OCR page N+1); Table 2 from p. 46, Table 3 from
// pp. 46-47, Table 4 from pp. 51-52, Table 5 and the quirks from pp. 52-54;
// the Table 2 and Table 3 rows carry the printed magnitude and unit codes
// (the engine grids are numeric); the Table 4 prose ladder pins as the eight
// era-threshold consts per the R595 ladder precedent.
//
// the gap census after this round: 19 closed, 77 open - the rating tables and
// the quirks are closed; the monster-doctrine boxes (the +/-1/2/3 modifier
// doctrine and Tables 6-22) follow.
//
namespace rules {

// ---- the DMO world-rating pins ----

// the chronological grid row count: 17 rows spanning the ratings C2 through
// C20, the 10-12 band as one row (printed p. 46, Table 2).
inline int delChronoCount()
    { return 17; }

// the magical grid row count: 17 rows spanning the ratings M2 through M20,
// the 10-12 band as one row (printed pp. 46-47, Table 3).
inline int delMagicCount()
    { return 17; }

// the ecological condition grid row count: three conditions - constitution
// loss, damage, and the poison save - each at severe, hostile, and deadly
// intensity (printed p. 54, Table 5).
inline int delEcologyCount()
    { return 3; }

// the fast-time threshold: in worlds rated 9 or less time flows more quickly
// than the base campaign - travelers return home to find almost no time has
// passed (printed p. 46).
inline int delChronoFastMax()
    { return 9; }

// the slow-time threshold: in worlds rated 13 or more time flows more slowly
// - travelers return to find their world greatly changed after even a short
// visit (printed p. 46).
inline int delChronoSlowMin()
    { return 13; }

// the ninth-level bar: no character can cast a 9th-level spell on a world
// rated M8 or lower; stored spells and items are the exception (printed p.
// 48).
inline int delMagicNoNinthMax()
    { return 8; }

// the spellbook-free tier: on worlds rated M19 or higher wizards do not
// require spellbooks - after a good night's sleep they meditate and acquire
// any available spell, just as priests do (printed p. 51).
inline int delMagicSpellbookFreeMin()
    { return 19; }

// the study-free tier: on M20 worlds wizards and priests do not require study
// time at all - they call spells to mind as needed, still limited by spells
// per day and components (printed p. 51).
inline int delMagicStudyFreeMin()
    { return 20; }

// the demihuman bar: demihumans (elves, gnomes, dwarves, orcs, ogres, and
// similar) must save vs. death magic immediately when entering worlds rated
// M5 or less - failure is death (printed p. 52).
inline int delDemihumanDeathSaveMax()
    { return 5; }

// the demihuman deprivation maximum: -4 on an M2 world - the penalty grows
// one point per rating below 5, with the hit-point loss floored at one point
// per hit die (printed p. 52).
inline int delDemihumanMaxPenalty()
    { return 4; }

// the fantastic-creature bar: fantastic creatures (centaurs, dragons,
// chimeras, pixies, tanar'ri and others) suffer similar penalties beginning
// on worlds rated M6 (printed p. 52).
inline int delFantasticPenaltyStartMax()
    { return 6; }

// the fantastic deprivation maximum: -5 on an M2 world (printed p. 52).
inline int delFantasticMaxPenalty()
    { return 5; }

// the item decay: magical weapons, armor, and protective devices are attuned
// to their world of making and lose one plus per plane removed from home -
// all Prime Material worlds share one plane (printed p. 52).
inline int delItemPlusLossPerPlane()
    { return 1; }

// the planar span: the maximum distance between planes is four - Inner Plane
// to Ethereal to Prime Material to Astral to Outer Plane; the Astral and
// Ethereal are one removed from the Prime, the Inner and Outer two (printed
// p. 52).
inline int delMaxPlaneDistance()
    { return 4; }

// the psionic high-magic tier: on worlds rated M13 or greater psionics are
// unaffected, though some worlds - the Demiplane of Ravenloft - have quirks
// that reach even psionics (printed p. 51).
inline int delPspUnaffectedMin()
    { return 13; }

// the open-world divine agreement: priests lose one level of spellcasting
// ability for every plane they are removed from their deity's home plane - a
// 10th-level priest one plane away casts as 9th (printed p. 49).
inline int delPriestLossPerPlane()
    { return 1; }

// the great-ring worked example: a priest whose deity resides on Mount
// Celestia and who visits the Abyss loses seven levels of spellcasting
// ability, tracing the path along the ring (printed p. 50).
inline int delPriestCelestiaAbyssLoss()
    { return 7; }

// the major-race minor tier: minor abilities (similar to 1st-2nd level
// spells, usable 1-3 times a day) function on worlds rated M7 or higher
// (printed p. 52).
inline int delMajorRaceMinorMin()
    { return 7; }

// the major-race major tier: major abilities (similar to 3rd-5th level
// spells) function on worlds rated M8 or higher, the creature also carrying
// 4-6 minor abilities usable once a turn or once an hour (printed p. 52).
inline int delMajorRaceMajorMin()
    { return 8; }

// the major-race extraordinary tier: extraordinary abilities (similar to
// 6th-7th level spells, once a day) function on worlds rated M9 or higher,
// with 6-10 minor abilities at will and 4-6 major abilities once a turn or
// hour (printed p. 52).
inline int delMajorRaceExtraordinaryMin()
    { return 9; }

// the natural spellcasting bands: minor spellcasting is 1st-3rd level
// (printed p. 50).
inline int delNaturalMinorMax()
    { return 3; }

// the natural spellcasting bands: major spellcasting is 4th-7th level
// (printed p. 50).
inline int delNaturalMajorMax()
    { return 7; }

// the natural spellcasting bands: extraordinary spellcasting is 8th-11th
// level - the abilities retained when visiting lower-rated worlds, though
// casting times extend and high levels still become unavailable (printed p.
// 50).
inline int delNaturalExtraordinaryMax()
    { return 11; }

// the tech ladder, the steel rung: ratings of 10-12 indicate the medieval
// technology common to most AD&D campaigns - steel tools and weapons, coal
// mining, trade and craft guilds, small slow sailing ships, feudal
// governments, extensive trade (printed pp. 51-52, Table 4).
inline int delTechSteelMin()
    { return 10; }

// the tech ladder, the firearm rung: cannons and ocean-going sailing ships
// arrive at 13; firearms, printing, and intercontinental trade at 14 (printed
// p. 52, Table 4).
inline int delTechFirearmMin()
    { return 14; }

// the tech ladder, the steam rung: steam engines, blast furnaces, and
// mechanical calculating machines at 15 (printed p. 52, Table 4).
inline int delTechSteamMin()
    { return 15; }

// the tech ladder, the combustion rung: internal combustion engines, light
// aircraft, steamships, railroads, and labor unions at 16 (printed p. 52,
// Table 4).
inline int delTechCombustionMin()
    { return 16; }

// the tech ladder, the nuclear rung: nuclear power, civil and military
// aircraft, and electronic computers at 17 (printed p. 52, Table 4).
inline int delTechNuclearMin()
    { return 17; }

// the tech ladder, the fusion rung: fusion power, commercial spacecraft,
// laser weapons, genetic engineering, and intercontinental governments at 18
// (printed p. 52, Table 4).
inline int delTechFusionMin()
    { return 18; }

// the tech ladder, the robot rung: sentient robots and computers, solar
// power, and portable nuclear power at 19 (printed p. 52, Table 4).
inline int delTechRobotMin()
    { return 19; }

// the tech ladder, the FTL rung: faster-than-light space travel, matter
// transmission and replication, and interplanetary governments at 20; the low
// end - tools unknown and fire unharnessed at 2, stone at 3, copper at 4-5,
// iron at 6 (printed p. 52, Table 4).
inline int delTechFtlMin()
    { return 20; }

// the advanced-tech rule: sufficiently advanced technology works just like
// magic - an item whose technological rating exceeds the local technological
// rating still works if it also exceeds the local magical rating by at least
// five; steam engines require local T15 or higher or M10 or lower (printed p.
// 53).
inline int delAdvancedTechMagicMargin()
    { return 5; }

// the hazard band: worlds rated E6 or less inflict one or more of the table
// effects upon visitors from the base campaign, the type reflecting the
// environment's nature (printed p. 53).
inline int delEcologyHazardMax()
    { return 6; }

// the paradise band: worlds rated E18 or higher seem paradises to visitors
// from E12 or less - with optional perils (the sleep until attacked, the
// flower's confusion-like euphoria with its singing and dancing) (printed p.
// 54).
inline int delEcologyParadiseMin()
    { return 18; }

// the native-intolerance band: natives of worlds rated E16 or higher cannot
// tolerate less benign worlds (printed p. 54).
inline int delEcologyNativeIntoleranceMin()
    { return 16; }

// the native intolerance, severe: E16+ natives suffer severe-condition
// effects on worlds rated five less than their home worlds (printed p. 54).
inline int delNativeSevereGap()
    { return 5; }

// the native intolerance, hostile: hostile penalties on worlds rated six less
// than home (printed p. 54).
inline int delNativeHostileGap()
    { return 6; }

// the native intolerance, deadly: deadly penalties on worlds rated seven or
// more less than home (printed p. 54).
inline int delNativeDeadlyGap()
    { return 7; }

// the chronological locality doctrine: characters are governed by local time
// wherever they are - a year on a C2 world ages the visitor a year while less
// than a minute passes at home; spell durations are local too (10 rounds on
// C11 is 10 rounds on C2 or C20); the flow always seems normal, even inside
// closed extra-dimensional spaces (portable holes, bags of holding, rope
// trick), with the shift imperceptible though clues appear (the noon portal
// into moonlit night) (printed p. 47).
inline bool delChronoLocalityDoctrine()
    { return true; }

// the low-magic casting-time doctrine: low-magic worlds impose a x2 to x5
// multiplier on casting times; an adjusted casting time of 10 or more
// requires full rounds - 10 completes at the end of the round it began, 20 at
// the end of the second round; the odd remainder completes the next round at
// that initiative modifier (the fireball at 3 on an M6 world: adjusted 12,
// one full round, done in the second at modifier 2) (printed pp. 47-49).
inline bool delMagicCastingTimeDoctrine()
    { return true; }

// the spell-modification doctrine: spells are modified by enhancement (one
// level higher, never on M9 or lower), diminution (one level lower),
// nullification (common on M9 or lower, rare on Prime worlds rated M10+ but
// frequent on highly magical outer planes and demiplanes), and alteration -
// superficial (the steam fireball), minor (the clairaudience ears with the
// save penalty vs. sound), or catastrophic (the berserk summons, the meteor
// swarm on the caster); natives often immune, PCs can learn the precautions;
// the Limbo Intelligence check negates any failed spell (printed p. 49).
inline bool delMagicModificationDoctrine()
    { return true; }

// the priest planar doctrine: four world classes - open (lose levels by
// divine distance; all Outer Planes), closed (cast memorized but regain
// nothing above 2nd; many Prime worlds, pockets, demiplanes), restricted (all
// spells lost; very rare), unrestricted (full power; the Astral, Ethereal,
// and all known Inner planes); deities treat their focus Prime worlds as
// home; granted abilities generally function at full power by agreement,
// local conditions prevailing (no flame strike on the Plane of Elemental
// Water); divine agreement can circumvent the world's magical rating entirely
// (printed pp. 49-50).
inline bool delPriestPlanarDoctrine()
    { return true; }

// the psionic doctrine: psionicists suffer less than spellcasters - the
// energies are personal and travel with the character; on M13+ worlds
// unaffected, on M9 or less the powers work but PSP costs rise for both
// initiating and maintaining; insufficient PSPs bar the power; local
// conditions never increase damage dice, duration, or range - increased cost
// is never an advantage (printed pp. 51-52).
inline bool delPspDoctrine()
    { return true; }

// the item decay doctrine: items trace the shortest possible path home
// (unlike priest spells); an inert item still functions as its normal self
// (an inert suit of magical armor is still armor) and keeps its magical aura
// for detect magic, reviving when conditions improve; the cloak +3 example -
// full power across the Prime, +2 in the Astral or Ethereal, +1 on any Outer
// or Inner plane (printed p. 52).
inline bool delItemDecayDoctrine()
    { return true; }

// the item-function doctrine: as portable containers of power, items often
// function on low-magic worlds where their effects cannot be cast (the staff
// of the magi producing wall of fire on an M3 world); but a modified school
// reaches its items too (the catastrophically altered conjuration making
// Bucknard's everfull purse and a bag of tricks dangerous); stored spells and
// items bypass the spell-level bars (printed pp. 48, 52).
inline bool delMagicItemFunctionDoctrine()
    { return true; }

// the natural spellcasting doctrine: intelligent natives of high-magic worlds
// cast naturally in the three bands, retained when visiting lower-rated
// worlds (with extended casting times and the high-level bars still
// applying); the abilities add to class abilities freely - the M20 fighter
// casts in metal armor, the M20 wizard still shuns armor but may enjoy extra
// spells or priest casting (printed pp. 50-51).
inline bool delNaturalSpellcastingDoctrine()
    { return true; }

// the major-race doctrine: a major race dominates its world as humans and
// demihumans dominate standard campaigns (the tanar'ri of the Abyss, the
// githyanki of the Astral); members native to high-magic worlds always have
// spell-like abilities in the three tiers, subject to local modifications -
// but natives always ignore their home world's detrimental effects (printed
// p. 52).
inline bool delMajorRaceDoctrine()
    { return true; }

// the technological notes doctrine: sample items appear when affordable or in
// common use (the T5 algebra inventor working alone; not every T17 resident
// owns a jet, but they are in general use); devices from low-tech worlds work
// anywhere, but devices from high-tech worlds carried low go inert if they
// have moving parts, circuitry, or depend on chemical reactions - the T16
// flashlight dies on a T8 world, the stainless steel ax still chops but loses
// its rust resistance, and a club is a club everywhere (printed p. 53).
inline bool delTechNotesDoctrine()
    { return true; }

// the ecological doctrine: E2 is completely hostile, E20 a paradise, 10-12
// generally earthlike with hazardous extremes (deserts, ocean depths,
// high-altitude thin air); the E6-or-less effects are the DM's choice
// reflecting the environment (the acidic atmosphere damaging, the polluted
// air draining Constitution); severe conditions allow mundane precautions (a
// desert or polar cap), hostile conditions threaten immediately (arctic
// water, volcanic gases - minor protective magic negates: endure cold/heat,
// ring of fire resistance, ring of warmth), deadly conditions kill within
// minutes (the lunar surface, a volcano's interior), and the listed deadly
// effects are minimums - the Plane of Elemental Fire demands a save vs.
// breath weapon or death, 5d10 damage even on a success (printed pp. 53-54).
inline bool delEcologyDoctrine()
    { return true; }

// the quirk doctrine: quirks are essential, serendipitous, or imposed -
// possibly changeable by the PCs; the infusion force twists everything
// (Ravenloft's evil bars all alignment detection and corrupts effects and
// psionics; on a Prime world it is temporary, removable by destroying the
// source); the conjuration bar (Athas - metal cannot be permanently created,
// the wall of iron falls to pieces); the named-spell bar (Melf's minute
// meteors unknown unless imported or researched from scratch); the
// dominant-race retaliation (possible only on M14+, leaders detect and
// retaliate against magical or psionic attacks - spell turning, the venomous
// insects per point of damage, the random spell); and the distance-immune
// world (items ignore planar distance, usually unrestricted) (printed pp.
// 53-54).
inline bool delQuirkDoctrine()
    { return true; }

// the Table 2 base-campaign time magnitude, by rating row (the fast rungs
// 2-9, the typical band 10-12, the slow rungs 13-20; one week of local time
// equals the base time shown).
inline int delChronoBaseMag(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 15;
        case 2:
            return 1;
        case 3:
            return 10;
        case 4:
            return 30;
        case 5:
            return 1;
        case 6:
            return 6;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
            return 5;
        case 14:
            return 10;
        case 15:
            return 30;
        case 16:
            return 100;
        default:
            return -99;
        }
    }

// the Table 2 unit code: 1 second, 2 minute, 3 hour, 4 day, 5 week, 6 month,
// 7 year - the unit of the base-campaign time magnitude.
inline int delChronoBaseUnit(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 7;
        default:
            return -99;
        }
    }

// the Table 2 rating, the row key: the campaign-time rating C2 through C20,
// the 10-12 band carried as one row keyed 10.
inline int delChronoRating(int b)
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
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 15;
        case 12:
            return 16;
        case 13:
            return 17;
        case 14:
            return 18;
        case 15:
            return 19;
        case 16:
            return 20;
        default:
            return -99;
        }
    }

// the Table 3 rating, the row key: the magic rating M2 through M20, the 10-12
// band carried as one row keyed 10.
inline int delMagicRating(int b)
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
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 15;
        case 12:
            return 16;
        case 13:
            return 17;
        case 14:
            return 18;
        case 15:
            return 19;
        case 16:
            return 20;
        default:
            return -99;
        }
    }

// the Table 3 highest spell level castable at the rating (0 on the dead-magic
// M2 row).
inline int delMagicMaxLevel(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
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
        case 14:
            return 10;
        case 15:
            return 10;
        case 16:
            return 10;
        default:
            return -99;
        }
    }

// the Table 3 casting-time and PSP multiplier (0 on M2 where nothing
// functions).
inline int delMagicCastMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        default:
            return -99;
        }
    }

// the low end of the range of schools of magic modified (0 where none are
// modified).
inline int delMagicSchoolsMin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 3;
        default:
            return -99;
        }
    }

// the high end of the range of schools of magic modified (0 where none are
// modified).
inline int delMagicSchoolsMax(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 7;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 7;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 9;
        case 16:
            return 9;
        default:
            return -99;
        }
    }

// the Table 5 roll count for the condition (the number of dice rolled; 0
// where no die is rolled - the poison save row).
inline int delEcologyRollCount(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the Table 5 die size (0 where no die is rolled - the poison save row is one
// saving throw at the end of each exposure period, failure immediate death).
inline int delEcologyDieSize(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 0;
        default:
            return -99;
        }
    }

// the Table 5 severe-condition period code: 1 day, 2 hour, 3 round.
inline int delEcologySeverePeriod(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the Table 5 hostile-condition period code: 1 day, 2 hour, 3 round.
inline int delEcologyHostilePeriod(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the Table 5 deadly-condition period code: 1 day, 2 hour, 3 round - the
// deadly effects are minimums.
inline int delEcologyDeadlyPeriod(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        default:
            return -99;
        }
    }

}   // namespace rules
