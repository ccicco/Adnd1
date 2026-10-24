// =========================================================================================
// Adnd1 - rules/mm2r.h
// THE MM2 LETTER R WALK - THE RAT (ORDINARY AND VAPOR), RAVEN (ORDINARY, HUGE
// AND GIANT), RETCH PLANT AND ROCK REPTILE TURNS (the two rat blocks p. 105,
// the raven (crow) variant table p. 105, the retch plant and the rock reptile
// p. 106), promoted to the live registry; the R-FLIP round, the Letter R gap
// box flips to closed
// census 734 -> 735.
//
// Round seventeen of the MM2 arc, the SIXTH single-letter pass (Curtiss Go
// call on the landed letter Q walk; the letter R pin-time walk found FOUR
// entries carrying seven stat blocks - no doctrine-only heads; the MM1
// registry prints in r/ are MM1 prints, so no prior-owned index entries ride
// this round)
//
// The pin headers stay the print-fidelity record; the seven .lua defs ride
// the R791 data_files extension in the MM1 registry schema (the defensive
// coercers load the verbatim print cells, the RStats grid carries the loader
// values)
//
namespace rules {

// ---- the MM2 letter R walk round pins (the R812 census) ----

// The MM2 letter R walk round: the ordinary rat to rock reptile turns, the
// SIXTH single-letter pass (Curtiss Go call on the landed letter Q walk)
inline int mm2rRound()
    { return 812; }

// The registry census before the R812 promotion (the landed R811 count)
inline int mm2rRegistryBefore()
    { return 726; }

// The registry census after the R812 promotion (7 defs)
inline int mm2rRegistryAfter()
    { return 733; }

// The seven promoted letter R defs (the ordinary rat, the vapor rat, the
// three raven (crow) columns, the retch plant, the rock reptile)
inline int mm2rDefCount()
    { return 7; }

// The four printed letter R entries (the rat head with its ordinary and vapor
// sub-blocks, the raven (crow) variant table, the retch plant, the rock
// reptile)
inline int mm2rEntryCount()
    { return 4; }

// The seven letter R stat blocks (the rat head carries two, the raven (crow)
// variant table three)
inline int mm2rStatBlockHeadings()
    { return 7; }

// No doctrine-only letter R heads ride this round
inline int mm2rDoctrineHeads()
    { return 0; }

// The four letter R headings on pp. 105-106 (RAT, RAVEN (Crow), RETCH PLANT,
// ROCK REPTILE)
inline int mm2rLetterRHeadings()
    { return 4; }

// The RStats grid row count (one row per def)
inline int mm2rRStatRows()
    { return 7; }

// The MM2 gap census after the R-flip: 23 closed
inline int mm2rGapClosed()
    { return 23; }

// The MM2 gap census after the R-flip: 14 open
inline int mm2rGapOpen()
    { return 14; }

// No prior-owned letter R entries (the MM1 registry prints in r/ - rakshasa,
// ram, red dragon, remorhaz, roc, roper, rot grub, rust monster and the rest
// - are MM1 prints, not MM2 box entries)
inline int mm2rPriorOwnedEntries()
    { return 0; }

// ---- the rat pins (the R812 MM2 letter R walk) ----

// The ordinary rat xpValue (I/2 + 1/hp, the flat-hp avgHp 2: 2 + 1x2)
inline int mm2rRatOrdinaryXpValue()
    { return 4; }

// The ordinary rat xp level (the I read)
inline int mm2rRatOrdinaryXpLevel()
    { return 1; }

// The vapor rat xpValue (II/52 + 2/hp, the 2-dice avgHp 7: 52 + 2x7)
inline int mm2rRatVaporXpValue()
    { return 66; }

// The vapor rat xp level (the II read)
inline int mm2rRatVaporXpLevel()
    { return 2; }

// The ordinary rat filthy bite: 5% chance of causing a serious disease unless
// a save vs. poison indicates otherwise
inline int mm2rRatOrdinaryDiseasePct()
    { return 5; }

// The vapor rat lair: a 25% chance for each of the J, K, L, M, N and C-type
// treasure types
inline int mm2rRatVaporLairTreasurePct()
    { return 25; }

// The vapor rat stinking cloud release affects only 1 individual if within
// 5-8 feet
inline int mm2rRatVaporGasReachFeetMin()
    { return 5; }

// The vapor rat stinking cloud release maximum reach (8 feet; the gas
// dissipates beyond it)
inline int mm2rRatVaporGasReachFeetMax()
    { return 8; }

// Although cowardly, a trapped or cornered rat will fight ferociously
inline bool mm2rRatOrdinaryFightWhenCornered()
    { return true; }

// When starved, rat packs will attack anything alive in order to feed
inline bool mm2rRatOrdinaryStarvingPackAttacks()
    { return true; }

// Normal rats fear fire, but, when driven by hunger, they will sometimes
// brave it
inline bool mm2rRatOrdinaryFearFire()
    { return true; }

// Wounded or seriously threatened vapor rats will always assume gaseous form;
// in such state only very hot or magical fire, lightning, and exceptionally
// strong winds can harm them
inline bool mm2rRatVaporGaseousForm()
    { return true; }

// Whenever one is killed or seriously wounded, it gives off a small puff of
// noxious fumes - the stinking cloud spell equivalent
inline bool mm2rRatVaporStingingCloudRelease()
    { return true; }

// ---- the raven (crow) pins (the R812 MM2 letter R walk) ----

// The ordinary raven xpValue (I/Nil - the phantom Nil-xp precedent)
inline int mm2rRavenOrdinaryXpValue()
    { return 0; }

// The ordinary raven xp level (the I read)
inline int mm2rRavenOrdinaryXpLevel()
    { return 1; }

// The huge raven xpValue (II/30 + 1/hp, the 1-1 avgHp 2: 30 + 1x2)
inline int mm2rRavenHugeXpValue()
    { return 32; }

// The huge raven xp level (the II read)
inline int mm2rRavenHugeXpLevel()
    { return 2; }

// The giant raven xpValue (III/60 + 4/hp, the 3+2 avgHp 12: 60 + 4x12)
inline int mm2rRavenGiantXpValue()
    { return 108; }

// The giant raven xp level (the III read)
inline int mm2rRavenGiantXpLevel()
    { return 3; }

// The raven eye attack: 10% likely to attack an opponent's eye (a 1 in 10
// chance on a hit, with resultant loss of the organ)
inline int mm2rRavenEyeAttackPct()
    { return 10; }

// The raven nest: 25% likely to have several small metal objects, gems, and
// the like in their nests
inline int mm2rRavenNestTreasurePct()
    { return 25; }

// The raven nest Type Q treasure: a 1 in 6 chance per nest
inline int mm2rRavenNestQChanceIn6()
    { return 6; }

// The raven nest Type Q treasure base gem value (10 gp)
inline int mm2rRavenNestGemBaseGp()
    { return 10; }

// The speaking ravens (some huge and most giant specimens) can speak as many
// as 100 words of the common tongue
inline int mm2rRavenCommonWords()
    { return 100; }

// Ravens or crows can never be surprised during lighted conditions
inline bool mm2rRavenNeverSurprisedInLight()
    { return true; }

// The scouts give warning cries, screen themselves, and maintain a safe
// distance while reporting to the flock by raucous calls
inline bool mm2rRavenScoutsGiveWarning()
    { return true; }

// All birds of this sort love objects which glitter and shine
inline bool mm2rRavenLoveGlitteringObjects()
    { return true; }

// Giant ravens are both pugnacious and easily trained (if raised from
// fledglings), and so are often used as guards and messengers
inline bool mm2rRavenGiantEasilyTrained()
    { return true; }

// Huge ravens tend towards a malicious disposition and are known to serve
// evil masters when opportunity permits
inline bool mm2rRavenHugeServeEvilMasters()
    { return true; }

// ---- the retch plant pins (the R812 MM2 letter R walk) ----

// The retch plant xpValue (III/150 + 6/hp, the first-number 5 read avgHp 17:
// 150 + 6x17)
inline int mm2rRetchPlantXpValue()
    { return 252; }

// The retch plant xp level (the III read)
inline int mm2rRetchPlantXpLevel()
    { return 3; }

// The retch plant constantly has from 5-8 globe-like, coconut-sized fruit
// growing at its top
inline int mm2rRetchGlobesMin()
    { return 5; }

// The retch plant globe count maximum
inline int mm2rRetchGlobesMax()
    { return 8; }

// The retch plant globe burst: a nauseating fluid is splashed over a 5-foot
// radius
inline int mm2rRetchSplashRadiusFeet()
    { return 5; }

// The retch plant splash: a 25% chance for splash contact at 5-9 foot
// distance
inline int mm2rRetchSplashContactPct()
    { return 25; }

// The retch plant splash distance band minimum
inline int mm2rRetchSplashContactFeetMin()
    { return 5; }

// The retch plant splash distance band maximum
inline int mm2rRetchSplashContactFeetMax()
    { return 9; }

// The retch plant fluid: creatures splashed vomit and retch for the next 3
// rounds
inline int mm2rRetchRetchingRounds()
    { return 3; }

// The retch plant fluid: for 6 turns (1 hour) thereafter to be at 50% normal
// strength
inline int mm2rRetchWeaknessTurns()
    { return 6; }

// The retch plant weakness strength percent
inline int mm2rRetchWeaknessPct()
    { return 50; }

// The retch plant odor is discernible within a 50-foot radius
inline int mm2rRetchOdorRadiusFeet()
    { return 50; }

// The retch plant odor persists for 1-4 hours
inline int mm2rRetchOdorHoursMin()
    { return 1; }

// The retch plant odor persistence maximum
inline int mm2rRetchOdorHoursMax()
    { return 4; }

// Walking under a retch plant makes it 20% likely that one of its globes will
// fall
inline int mm2rRetchWalkUnderDropPct()
    { return 20; }

// Solid contact with the tree trunk - banging against, running into, or
// climbing it - brings 2-5 of the noisome fruit down
inline int mm2rRetchContactGlobesMin()
    { return 2; }

// The solid-contact globe count maximum
inline int mm2rRetchContactGlobesMax()
    { return 5; }

// The retch plant fluid: there is no saving throw allowed
inline bool mm2rRetchNoSavingThrow()
    { return true; }

// Creatures splashed and unwashed are much more likely to attract carnivores
// at double the normal frequency of checks, with double probabilities of
// encounter
inline bool mm2rRetchCarnivoreAttractionDouble()
    { return true; }

// ---- the rock reptile pins (the R812 MM2 letter R walk) ----

// The rock reptile xpValue (the M-row V/400 + 7/hp, the avgHp 17: 400 + 7x17)
inline int mm2rRockReptileXpValue()
    { return 519; }

// The rock reptile xp level (the M-row V read)
inline int mm2rRockReptileXpLevel()
    { return 5; }

// The rock reptile large (L) xp base (the L-row VI/600)
inline int mm2rRockReptileLargeXpBase()
    { return 600; }

// The rock reptile large (L) xp/hp cell
inline int mm2rRockReptileLargeXpPerHp()
    { return 9; }

// The rock reptile large (L) xpValue (VI/600 + 9/hp, the avgHp 17: 600 +
// 9x17)
inline int mm2rRockReptileLargeXpValue()
    { return 753; }

// The rock reptile large (L) xp level (the VI read)
inline int mm2rRockReptileLargeXpLevel()
    { return 6; }

// The rock reptile length band (M-L, 5-12 feet long)
inline int mm2rRockReptileLengthFeetMin()
    { return 5; }

// The rock reptile length maximum
inline int mm2rRockReptileLengthFeetMax()
    { return 12; }

// The rock reptile surprises on 1-3 (the 3 in 6 basis)
inline int mm2rRockReptileSurpriseMin()
    { return 1; }

// The rock reptile surprise roll maximum
inline int mm2rRockReptileSurpriseMax()
    { return 3; }

// The rock reptile initial rush is at twice normal speed
inline int mm2rRockReptileRushSpeedMultiplier()
    { return 2; }

// The rock reptile bite damage band (1-4)
inline int mm2rRockReptileDamageMin()
    { return 1; }

// The rock reptile bite damage maximum
inline int mm2rRockReptileDamageMax()
    { return 4; }

// The rock reptile damage: +1 point per foot of length
inline int mm2rRockReptileDamagePerFoot()
    { return 1; }

// The rock reptile lair: 25% each for types J, K, L, and M, and also types Q,
// S x 1/4, and T x 1/2
inline int mm2rRockReptileLairTreasurePct()
    { return 25; }

// The rock reptile chameleon-like powers: it can lie in wait in rocky areas,
// appearing to be nothing more than a pile of rubble or rocks
inline bool mm2rRockReptileChameleonPowers()
    { return true; }

// The rock reptile favors darkness but will occasionally venture out in
// daylight if it is sufficiently hungry
inline bool mm2rRockReptileFavorsDarkness()
    { return true; }

// If 2 of the monsters are encountered, they have double metal and gems only
inline bool mm2rRockReptilePairDoubleMetalGems()
    { return true; }

// ---- the RStats grid pins (the R812 MM2 letter R walk) ----

// The armor class cells (the vapor rat 6 (or special) rides the verbatim
// print cell, firstIntIn 6)
inline int mm2rRStatAc(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 4;
        case 5:
            return 8;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// The hit dice num cells (the ordinary rat and the ordinary raven 1/4 reads
// ride the flat-hp path - hdNum 0, the ikiryo precedent; the huge raven 1-1
// reads 1 die; the retch plant 5-8 and the rock reptile 5 read the base 5)
inline int mm2rRStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the huge raven 1-1 reads -1 - the buckawn
// precedent, the hitDice = hdNum + bonus/4 form; the giant raven 3+2 reads
// +2)
inline int mm2rRStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula: the vapor rat 7, the
// raven giant 12, the retch plant and the rock reptile 17; the flat-hp
// 1/4-die reads carry avgHp 2)
inline int mm2rRStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 7;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 12;
        case 5:
            return 17;
        case 6:
            return 17;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the retch plant Nil attacks floored
// at 1)
inline int mm2rRStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The xp base cells (the raven ordinary I/Nil reads 0 - the phantom
// precedent; the rock reptile M-row V/400)
inline int mm2rRStatXp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 52;
        case 2:
            return 0;
        case 3:
            return 30;
        case 4:
            return 60;
        case 5:
            return 150;
        case 6:
            return 400;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the rat ordinary 1, the vapor rat 2, the raven
// huge 1, the raven giant 4, the retch plant 6, the rock reptile 7)
inline int mm2rRStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return 0;
        }
    }

// The in-lair percentage cells (the loader luaGetInt accepts only
// lua_isnumber strings, so the print 30%/25%/15%/10% cells ride as the
// bare-numeral 30/25/15/10 read - the R810 pech and pedipalp precedent; the
// ordinary rat and the retch plant Nil read 0)
inline int mm2rRStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 30;
        case 2:
            return 25;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// The move cells (the ground move reads: the raven 1/1/3 of the multi-mode
// cells, the retch plant Nil reads 0)
inline int mm2rRStatMove(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 12;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The magic resistance cells (every Standard cell reads 0 - the R155 class)
inline int mm2rRStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
