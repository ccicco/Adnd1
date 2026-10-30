// =========================================================================================
// Adnd1 - rules/g21.h
// The Dragon issue-21 opener part two - the gold-piece inflation doctrine,
// the natural-history monster doctrine, the Hall of Mystery and the M-U
// titles kit
// census 866 -> 867.
//
// The part-two round of the issue-21 three-round shape - the four remaining
// Curtiss-called chains pinned after the R943 personality grid,
// spell-research doctrine and foretelling counters, the R945 pure flip to
// close both report-021 boxes to follow. All pinned from The Dragon Vol. III
// No. 6 (December 1978), the Curtiss-provided Dm21.pdf scan voice, print
// folio the PDF page minus two.
//
// The issue-21 part-two print catches pinned as scanned: the Blume prose
// walks seven columns against the ten-column chart and prints WIZARD for the
// M-U contents line, the kit spellings print Magnificance, Irrestible,
// Reknown, Belligerant, Contretious and Sourge, the Callison inflation prints
// D-and-D with a lower-case d and drops its letters twice, the monster blues
// prints the envision and ol-Gandalf, and the Turnbull census prints Otyugl
// with the verse Ann-for-And and the apiece-of-red-material typos - all
// pinned as scanned, the conversion noted
//
namespace rules {

// ---- the gold-piece inflation doctrine (print 9) ----

// the primary analogy - one gold piece imagined equal to one dollar, the
// yardstick of the whole doctrine the gold-piece inflation doctrine (print 9)
inline int g21InflationGpDollarRatio()
    { return 1; }

// the richer alternate floor - a gold piece worth maybe 5 or 10 dollars,
// making the loot floods even more unbelievable the gold-piece inflation
// doctrine (print 9)
inline int g21InflationGpDollarAltMin()
    { return 5; }

// the richer alternate ceiling of the same maybe-5-or-10 passage the
// gold-piece inflation doctrine (print 9)
inline int g21InflationGpDollarAltMax()
    { return 10; }

// the Callison campaign starting purse floor - players initially receive 1-10
// gold pieces, the grumbling preconditioned players noted the gold-piece
// inflation doctrine (print 9)
inline int g21InflationNewbieGoldMin()
    { return 1; }

// the starting purse ceiling of the same 1-10 passage the gold-piece
// inflation doctrine (print 9)
inline int g21InflationNewbieGoldMax()
    { return 10; }

// the Gygax article reference - Strategic Review Vol. II No. 2, D-and-D is
// Only as Good as the DM, the reprint wish noted the gold-piece inflation
// doctrine (print 9)
inline int g21InflationStrategicReviewVol()
    { return 2; }

// the issue number of the same Strategic Review reference the gold-piece
// inflation doctrine (print 9)
inline int g21InflationStrategicReviewNo()
    { return 2; }

// the anecdote dungeon level - a purple dragon on the 1st level handing out
// the plus-5 gifts just because he liked me the gold-piece inflation doctrine
// (print 9)
inline int g21InflationPurpleDragonLevel()
    { return 1; }

// the purple dragon gift count - one plus 5 sword the gold-piece inflation
// doctrine (print 9)
inline int g21InflationPlusFiveSwords()
    { return 1; }

// the purple dragon gift count - two plus 5 spears riding the same sword the
// gold-piece inflation doctrine (print 9)
inline int g21InflationPlusFiveSpears()
    { return 2; }

// the critique - rewarding experience only for money spent drains the loot
// but is unrealistic; most cultures gain power by gaining material wealth the
// gold-piece inflation doctrine (print 9)
inline bool g21InflationSpendForXpCritique()
    { return true; }

// the Callison fix - cut the prices when cutting the take, bringing silver
// and copper back into real use the gold-piece inflation doctrine (print 9)
inline bool g21InflationSilverCopperRevived()
    { return true; }

// the variety critique - platinum and electrum merely leapfrog the
// inflation-ridden gold piece the gold-piece inflation doctrine (print 9)
inline bool g21InflationPlatinumElectrumCritique()
    { return true; }

// the closing doctrine - SMALL IS BEAUTIFUL, the dungeon master is god,
// throttle the gold, the castles and the demi-god levels the gold-piece
// inflation doctrine (print 9)
inline bool g21InflationSmallIsBeautiful()
    { return true; }

// the peasant absurdity - commoners walking around with hundreds of gold
// pieces on their persons the gold-piece inflation doctrine (print 9)
inline bool g21InflationPeasantHundredsGp()
    { return true; }

// the sibling campaign reference - EPT named alongside D-and-D as a campaign
// world suffering the same inflation the gold-piece inflation doctrine (print
// 9)
inline bool g21InflationEptReference()
    { return true; }

// the print catch - the article prints D-and-D with a lower-case d and drops
// its letters twice: the wont and the can for they will, pinned as scanned
// the gold-piece inflation doctrine (print 9)
inline bool g21InflationTypoPrintCatch()
    { return true; }

// ---- the natural-history monster doctrine (print 8) ----

// the centipede armor class floor - the corrected image, long sleek hairless
// hard-exoskeleton creatures moving with blinding speed, AC 2-3 as printed
// with the question mark noted the natural-history monster doctrine (print 8)
inline int g21MonsterCentipedeAcMin()
    { return 2; }

// the centipede armor class ceiling of the same AC 2-3 passage the
// natural-history monster doctrine (print 8)
inline int g21MonsterCentipedeAcMax()
    { return 3; }

// the snake doctrine - poison or constriction, never both weapons on one
// serpent the natural-history monster doctrine (print 8)
inline bool g21MonsterSnakeNeverBoth()
    { return true; }

// the reptile limit - snakes are cold-blooded and cannot live in cold areas,
// a bonus for magic-users with a cold spell the natural-history monster
// doctrine (print 8)
inline bool g21MonsterSnakeColdBlooded()
    { return true; }

// the snake senses - all snakes are deaf but pick up ground vibrations, the
// elven boots exception noted the natural-history monster doctrine (print 8)
inline bool g21MonsterSnakeDeafVibration()
    { return true; }

// the coil bonus - a snake that coils up before striking gains the initiative
// edge against the foolish the natural-history monster doctrine (print 8)
inline bool g21MonsterSnakeCoilInitiative()
    { return true; }

// the web doctrine - web weavers hunt live prey paralyzed by the poison and
// wrapped for a future meal the natural-history monster doctrine (print 8)
inline bool g21MonsterSpiderLivePrey()
    { return true; }

// the spider census - most spiders live alone, only a few types keep
// community webs the natural-history monster doctrine (print 8)
inline bool g21MonsterSpiderSolitary()
    { return true; }

// the trap-door spider - covering pits and doorways with its prey door,
// hollow-sound detectable, usually complete surprise from behind the
// natural-history monster doctrine (print 8)
inline bool g21MonsterTrapdoorSurprise()
    { return true; }

// the scorpion census - scorpions always live alone, mating and brood
// excepted the natural-history monster doctrine (print 8)
inline bool g21MonsterScorpionSolitary()
    { return true; }

// the ant census - giant ants are positively social animals, scent trails and
// the single-queen colony the natural-history monster doctrine (print 8)
inline bool g21MonsterAntSocial()
    { return true; }

// the variance doctrine - no typical giant spider; hit dice and poison levels
// vary as much as the food-gathering methods the natural-history monster
// doctrine (print 8)
inline bool g21MonsterNoTypicalSpider()
    { return true; }

// the source doctrine - Mother Nature as the limitless monster well: mammals,
// reptiles, birds, insects, crustaceans, arthropods, arachnids, fish,
// protozoans and the plants the natural-history monster doctrine (print 8)
inline bool g21MonsterNaturalSource()
    { return true; }

// the print catch - the article prints the envision for they envision,
// ol-Gandalf run together and Needless-to-say hyphenated, pinned as scanned
// the natural-history monster doctrine (print 8)
inline bool g21MonsterEnvisionPrintCatch()
    { return true; }

// ---- the Hall of Mystery do-it-yourself module (print 14-15) ----

// the room count - eight surrounding rooms i through viii keyed to the
// Excalibur dial the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallRooms()
    { return 8; }

// the mirror count - five large mirrors around the hall the Hall of Mystery
// do-it-yourself module (print 14-15)
inline int g21HallMirrors()
    { return 5; }

// each mirror 10 feet square, bottom edges only a few inches from the floor
// the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallMirrorSquareFeet()
    { return 10; }

// mirrors b, d and e are the ordinary ones, placed useful to some passages
// the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallOrdinaryMirrors()
    { return 3; }

// the hall ceiling - 45 feet, bare, lit from an unseen source above the Hall
// of Mystery do-it-yourself module (print 14-15)
inline int g21HallCeilingFeet()
    { return 45; }

// the mirror c life-trapping section - circular, about 6 feet across, covered
// by the red material the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallLifeTrapDiameterFeet()
    { return 6; }

// the center rock cylinder - smooth, 5 feet high, domed on the top the Hall
// of Mystery do-it-yourself module (print 14-15)
inline int g21HallCylinderHeightFeet()
    { return 5; }

// the dial - nine positions, the neutral o plus i through viii in gold-paint
// Roman numerals the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallDialPositions()
    { return 9; }

// the teleport limit - three people per room, no more the Hall of Mystery
// do-it-yourself module (print 14-15)
inline int g21HallTeleportLimit()
    { return 3; }

// the word - Excalibur spoken three times, the verse saying repeated twice,
// the parchment written in Lawful the Hall of Mystery do-it-yourself module
// (print 14-15)
inline int g21HallExcaliburSpeaks()
    { return 3; }

// the trapper census - corridors to rooms i, iii, v and vii each hold a
// Trapper the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallTrapperCorridors()
    { return 4; }

// the hall guards - two Umber Hulks in the Greenlands version the Hall of
// Mystery do-it-yourself module (print 14-15)
inline int g21HallUmberHulks()
    { return 2; }

// the long-corridor rooms hold two monster guards each, the Magic Absorbers
// riding the long corridors the Hall of Mystery do-it-yourself module (print
// 14-15)
inline int g21HallLongCorridorGuards()
    { return 2; }

// the short-corridor rooms hold one monster guard each the Hall of Mystery
// do-it-yourself module (print 14-15)
inline int g21HallShortCorridorGuards()
    { return 1; }

// the Magic Absorber credit - a Nicolai Shapero creation from Alarums and
// Excursions issue 12 the Hall of Mystery do-it-yourself module (print 14-15)
inline int g21HallAbsorberSourceIssue()
    { return 12; }

// the closing anecdote - an 11th-level Paladin on one leg, sack over head,
// the British anthem sung in Hebrew the Hall of Mystery do-it-yourself module
// (print 14-15)
inline int g21HallAnecdotePaladinLevel()
    { return 11; }

// mirror a is the Mirror of Opposition the Hall of Mystery do-it-yourself
// module (print 14-15)
inline bool g21HallMirrorAOpposition()
    { return true; }

// mirror c carries the Life Trapping section, one Life inside - the Succubus
// in the Turnbull version the Hall of Mystery do-it-yourself module (print
// 14-15)
inline bool g21HallMirrorCLifeTrap()
    { return true; }

// no mirror magic operates until the muslin sheet is drawn aside the Hall of
// Mystery do-it-yourself module (print 14-15)
inline bool g21HallMuslinSeals()
    { return true; }

// the pointer arrival display - violent but harmless pyrotechnics as the
// operator teleports the Hall of Mystery do-it-yourself module (print 14-15)
inline bool g21HallPyrotechnicsHarmless()
    { return true; }

// a fourth teleporter to a full room is displaced one room clockwise, two
// rooms if that is full too the Hall of Mystery do-it-yourself module (print
// 14-15)
inline bool g21HallFourthDisplaced()
    { return true; }

// the steel panels slide noiselessly up into the ceiling as the cylinder
// sectors hinge back the Hall of Mystery do-it-yourself module (print 14-15)
inline bool g21HallPanelsSync()
    { return true; }

// the dial ceases operating until the pointer rests back at the neutral o,
// then works again the Hall of Mystery do-it-yourself module (print 14-15)
inline bool g21HallPointerNeutralReset()
    { return true; }

// the print catch - the monster census prints Otyugl for the otyugh, pinned
// as scanned the Hall of Mystery do-it-yourself module (print 14-15)
inline bool g21HallOtyuglSpellingPrintCatch()
    { return true; }

// the verse print catch - Ann for And in the rampant pillar line, and apiece
// for a piece in the red material note, pinned as scanned the Hall of Mystery
// do-it-yourself module (print 14-15)
inline bool g21HallVersePrintCatch()
    { return true; }

// the room column - i through viii: the Night Hag, Intellect Devourer,
// Otyugl, Mind Flayer, Ettin, Manticore, Shambling Mound and Flesh Golem
// census
inline int g21HallRoomNumber(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the trapper column - corridors to rooms i, iii, v and vii hold the
// Trappers, the untrappered corridors pinned 0
inline int g21HallRoomTrapper(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// the printed hit dice column - only the room iii Otyugl prints its 7 hit
// dice, the rest pinned 0 as unprinted, the conversion noted
inline int g21HallRoomPrintedHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 7;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// ---- the M-U titles kit (print 7) ----

// the chart census - the kit prints ten columns across its two tables the M-U
// titles kit (print 7)
inline int g21TitleKitChartColumns()
    { return 10; }

// the prose walk - the instructions walk only columns one through seven, the
// print catch against the ten-column chart the M-U titles kit (print 7)
inline int g21TitleKitProseColumns()
    { return 7; }

// the worked example - Rogor the 20th-level Paladin: the Captain General, His
// All Triumphant Magnificance, the Colossal, Destroyer of Evil the M-U titles
// kit (print 7)
inline int g21TitleKitRogorLevel()
    { return 20; }

// the customization doctrine - delete columns one and five, embellish three
// and seven, the second Rogor example the M-U titles kit (print 7)
inline bool g21TitleKitDeleteEmbellish()
    { return true; }

// the header print catch - the question prints 25th LEVEL WIZARD where the
// contents line and the article title say M-U the M-U titles kit (print 7)
inline bool g21TitleKitWizardHeaderPrintCatch()
    { return true; }

// the spelling print catches - Magnificance, Irrestible, Reknown,
// Belligerant, Contretious and Sourge, all pinned as scanned the M-U titles
// kit (print 7)
inline bool g21TitleKitSpellingPrintCatch()
    { return true; }

// the standing answer - whatever he wants, the kit guaranteed to impress
// players with the splendor and might of the NPCs the M-U titles kit (print
// 7)
inline bool g21TitleKitWhateverHeWants()
    { return true; }

}   // namespace rules
