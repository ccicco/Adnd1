// =========================================================================================
// Adnd1 - rules/dgo.h
// The Dragon issue-8 opener - the Gygax Planes article (folios 4-5), the
// Watson towns article (folios 5-7) and the Kuntz gems re-evaluation (folios
// 22-23): three adjudicated chains in one round
// census 832 -> 833.
//
// Pinned from The Dragon Vol. 1 No. 8 (July 1977), the archive.org scan voice
// (single-voice: no chat-side upload cross-check exists for issue 8; the
// source lives in the archive.org item accessory-dragon-magazine-012). The
// folios: 4-5, the Gygax Designers Forum Planes article - the seven inner
// planes (Prime Material, Positive, Negative, the four Elemental) and sixteen
// outer, the ethereal-to-inner and astral-to-outer split, the astral
// restrictions (Prime Material only, never from the inner planes, first level
// only), one-plane walking, and the planar-existence law - special-metal
// creatures dual-planar, +1-only creatures in two planes, +2 in three,
// weapons removed one plane per plus with the sharpness and vorpal special
// cases; 5-7, the Watson Development of Towns in D&D article - the pawnshop's
// 1-in-6 defective stock, the 1-in-4 foreign merchants, the 1-in-8 thieves'
// quarter encounter per turn, the cartographer's 100-600 gp maps, the
// barber's 1 gp, the stable's 2-3 gp weekly board, the 20 gp soothsayer, the
// 50 gp-per-level magician, the brothel's 20/35 gp fees with the 10-100 gp
// information bribes, the surgeon's 25 gp wound cure at 50 percent and 35 gp
// poison cure at 1-in-6, the library's 100 gp base, Falgrave's 3-18 patrons
// two thirds non-human, and the three-floor limit; 22-23, the Kuntz A
// Re-evaluation of Gems and Jewelry in D&D article - the carat table, the
// basic-values table, the jewelry metal table, the gem-count table and the
// jewelry-type table, the description lists riding the transcript. The
// transcripts ride extract/dragon/008/ (all 32 issue pages); the issue-8 gap
// report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at the printed 3,
// 12, 21, 22, 23 and 24 footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// the Gygax Planes article - though it prefigures the later print - pins as a
// variant layer with provenance, never core canon. The Kuntz garbles ride AS
// SCANNED, noted, never silent: the worked example's table labels read
// swapped against the printed tables' own bands (the 75 x 5 x 3 = 1,125
// arithmetic is the anchor), and the carat table's starred rows overlap by
// the print's own arithmetic with the re-roll footnote noted. The gem-type
// description lists (Table C) ride the transcript, garbled in the OCR and
// never guessed. The editor's standing caution rides: none of this is
// official.
//
namespace rules {

// ---- the Gygax Planes article (folios 4-5) ----

// the inner planes - the Prime Material, Positive and Negative Material, and
// the four Elemental (folios 4-5)
inline int dgoInnerPlanesCount()
    { return 7; }

// the outer planes - sixteen, the religious and philosophical goals of
// mankind and the other intellectual species (folio 5)
inline int dgoOuterPlanesCount()
    { return 16; }

// the Seven Heavens run seven levels in Heaven (folio 5)
inline int dgoSevenHeavensLevels()
    { return 7; }

// the Nine Hells run nine layers - the Nine Hells of the print (folios 4-5)
inline int dgoNineHellsLayers()
    { return 9; }

// the Abyss runs the 666 layers of the print (folios 4-5)
inline int dgoAbyssLayers()
    { return 666; }

// creatures struck only with +1 or greater magical weapons exist wholly and
// simultaneously in two planes (folio 4)
inline int dgoCreaturePlanesAtPlus1()
    { return 2; }

// creatures requiring +2 or better exist in three planes simultaneously
// (folio 4)
inline int dgoCreaturePlanesAtPlus2()
    { return 3; }

// a magic weapon can be removed no further than one plane per point of its
// best to-hit bonus - a +2 retains its magic two planes from the Prime
// Material (folio 4)
inline int dgoWeaponPlanesPerPlus()
    { return 1; }

// walking on the Outer Planes is limited to one plane to either side of the
// starting plane (folio 5)
inline int dgoWalkAdjacentPlanes()
    { return 1; }

// the Ethereal reaches any of the inner planes (folio 4)
inline bool dgoEtherealReachesInner()
    { return true; }

// the Astral reaches the outer planes (folio 4)
inline bool dgoAstralReachesOuter()
    { return true; }

// the traveler must be in the Prime Material to enter the Astral (folio 5)
inline bool dgoAstralFromPrimeOnly()
    { return true; }

// the Astral cannot be reached from the Elemental, Positive or Negative
// Planes (folio 5)
inline bool dgoAstralNotFromInner()
    { return true; }

// the Astral takes a traveler to the first level of the Outer Planes -
// physical travel must be used to proceed to the other levels (folio 5)
inline bool dgoAstralFirstLevelOnly()
    { return true; }

// creatures harmed only by special metals (silver, cold iron) gain the
// invulnerability from partial existence in the Positive or Negative Material
// Plane (folio 4)
inline bool dgoSpecialMetalCreaturesDualPlanar()
    { return true; }

// any person armed with a magic weapon can attack into the Astral or Ethereal
// Plane if aware of the opponent operating there (folio 4)
inline bool dgoMagicWeaponAttacksAcrossPlanes()
    { return true; }

// weapons removed beyond their plane limit lose all magic, becoming normal
// weapons (folio 4)
inline bool dgoWeaponLosesMagicBeyondLimit()
    { return true; }

// the sword of sharpness and the vorpal blade get special treatment under the
// plane-removal law; a life-draining sword operates primarily on the Negative
// Material Plane and gains no such consideration (folio 4)
inline bool dgoSwordOfSharpnessSpecialCase()
    { return true; }

// ---- the Watson towns article (folios 5-7) ----

// pawnshop armor and weapons have a 1-in-6 chance of being defective in some
// manner (folio 6)
inline int dgoPawnshopDefectiveChance()
    { return 6; }

// the cartographer's wilderness and dungeon maps - 100-600 gp by remoteness,
// the minimum (folio 5)
inline int dgoCartographerMapMin()
    { return 100; }

// the cartographer's maps by remoteness - the maximum (folio 5)
inline int dgoCartographerMapMax()
    { return 600; }

// the barber's haircut and shave - one gp (folio 5)
inline int dgoBarberFeeGp()
    { return 1; }

// horses boarded at the stable 2-3 gp per week - the minimum (folio 6)
inline int dgoStableBoardMin()
    { return 2; }

// horses boarded 2-3 gp per week - the maximum (folio 6)
inline int dgoStableBoardMax()
    { return 3; }

// the town square market - a 1-in-4 chance a foreign merchant or two is in
// attendance (folio 6)
inline int dgoForeignMerchantChance()
    { return 4; }

// the dark side of town - a 1-in-8 chance per turn of encountering a thief or
// being attacked by brigands (folio 6)
inline int dgoThievesQuarterEncounter()
    { return 8; }

// the soothsayer predicts an expedition's outcome for 20 gp, drawing on the
// DM's knowledge and an accuracy dieroll (folio 6)
inline int dgoSoothsayerFeeGp()
    { return 20; }

// the town magician casts spells for a fee of 50 gp times spell level (folio
// 6)
inline int dgoMagicianFeePerLevel()
    { return 50; }

// the brothel fee about 20 gp, 35 for the special (folio 6)
inline int dgoBrothelFeeGp()
    { return 20; }

// the brothel brims with privy information for bribes of 10-100 gp - the
// minimum (folio 6)
inline int dgoBrothelInfoBribeMin()
    { return 10; }

// the brothel information bribes 10-100 gp - the maximum (folio 6)
inline int dgoBrothelInfoBribeMax()
    { return 100; }

// one to six male patrons in the brothel waiting area - the minimum (folio 6)
inline int dgoBrothelPatronsMin()
    { return 1; }

// one to six male patrons - the maximum (folio 6)
inline int dgoBrothelPatronsMax()
    { return 6; }

// the surgeon attempts to cure 1-6 wound points for 25 gp at a 50 percent
// chance of success (folio 7)
inline int dgoSurgeonWoundFeeGp()
    { return 25; }

// the surgeon's wound-point cure 1-6 - the minimum (folio 7)
inline int dgoSurgeonWoundCureMin()
    { return 1; }

// the surgeon's wound-point cure 1-6 - the maximum (folio 7)
inline int dgoSurgeonWoundCureMax()
    { return 6; }

// the surgeon attempts to cure poison for 35 gp at a one-in-six chance (folio
// 7)
inline int dgoSurgeonPoisonFeeGp()
    { return 35; }

// the poison cure's one-in-six chance (folio 7)
inline int dgoSurgeonPoisonChance()
    { return 6; }

// the wound cure's 50 percent chance of success (folio 7)
inline int dgoSurgeonWoundSuccessPct()
    { return 50; }

// the library's base value of general information about 100 gp, specific
// facts increasingly more expensive (folio 7)
inline int dgoLibraryBaseFeeGp()
    { return 100; }

// Falgrave's inn - 3-18 patrons, the minimum (folio 7)
inline int dgoFalgravePatronsMin()
    { return 3; }

// Falgrave's inn - 3-18 patrons, the maximum (folio 7)
inline int dgoFalgravePatronsMax()
    { return 18; }

// one to four non-human wayfarers or merchants at Falgrave's - the minimum
// (folio 7)
inline int dgoFalgraveWayfarersMin()
    { return 1; }

// one to four non-human wayfarers - the maximum (folio 7)
inline int dgoFalgraveWayfarersMax()
    { return 4; }

// generally no more than three floors save for a special tower or temple
// (folio 5)
inline int dgoMaxFloors()
    { return 3; }

// the town is laid out like the dungeon, using the same graphic and scale
// system (folio 5)
inline bool dgoTownLayoutSharesDungeonScale()
    { return true; }

// a large town on a hostile border or astride a trade route or waterway is
// most likely walled (folio 5)
inline bool dgoTownWalledOnBorder()
    { return true; }

// a keep nearby or inside houses the ruling lord and his retainers, the local
// law and order (folio 5)
inline bool dgoKeepHousesTheLord()
    { return true; }

// at Falgrave's two thirds of the patrons shall be non-human and half of
// those warriors (folio 7)
inline bool dgoFalgraveNonhumanThirds()
    { return true; }

// the surgeon's maximum of one attempt per day and one successful healing or
// cure per week, paid regardless of success (folio 7)
inline bool dgoSurgeonOneAttemptPerDay()
    { return true; }

// the marketplace is a hot bed of rumor and local gossip, a good percentage
// false (folio 6)
inline bool dgoMarketRumorMill()
    { return true; }

// ---- the Kuntz gems and jewelry article (folios 22-23) ----

// the dgoGemACarat table runs 11 rows - the Kuntz substitution tables (folios
// 22-23)
inline int dgoGemACaratCount()
    { return 11; }

// the dgoGemBValue table runs 10 rows - the Kuntz substitution tables (folios
// 22-23)
inline int dgoGemBValueCount()
    { return 10; }

// the dgoGemDMetal table runs 10 rows - the Kuntz substitution tables (folios
// 22-23)
inline int dgoGemDMetalCount()
    { return 10; }

// the dgoGemECount table runs 7 rows - the Kuntz substitution tables (folios
// 22-23)
inline int dgoGemECountCount()
    { return 7; }

// the dgoGemFType table runs 15 rows - the Kuntz substitution tables (folios
// 22-23)
inline int dgoGemFTypeCount()
    { return 15; }

// the carat band minimum per percentile row of the Kuntz carat table - 01-30
// through 00, the starred rows re-rolled per the print's footnote (folio 22)
inline int dgoGemACaratMin(int b)
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
            return 10;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 30;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// the carat band maximum per percentile row, the print's starred rows
// overlapping by its own arithmetic - as scanned (folio 22)
inline int dgoGemACaratMax(int b)
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
            return 9;
        case 6:
            return 10;
        case 7:
            return 50;
        case 8:
            return 70;
        case 9:
            return 80;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// the gem basic value in gold pieces per carat by percentile band - 10 gp at
// 01-10 through 200 gp at 96-00 (folio 22)
inline int dgoGemBValueGp(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 50;
        case 4:
            return 75;
        case 5:
            return 100;
        case 6:
            return 125;
        case 7:
            return 150;
        case 8:
            return 175;
        case 9:
            return 200;
        default:
            return 0;
        }
    }

// the jewelry metal band value minimum in gold pieces - bronze at 01-20
// through the mithril-plus-platinum 96-00 row (folio 23)
inline int dgoGemDMetalMin(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 100;
        case 3:
            return 500;
        case 4:
            return 500;
        case 5:
            return 1000;
        case 6:
            return 1000;
        case 7:
            return 1000;
        case 8:
            return 1500;
        case 9:
            return 2000;
        default:
            return 0;
        }
    }

// the jewelry metal band value maximum in gold pieces (folio 23)
inline int dgoGemDMetalMax(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 80;
        case 2:
            return 400;
        case 3:
            return 1000;
        case 4:
            return 1500;
        case 5:
            return 2000;
        case 6:
            return 3000;
        case 7:
            return 4000;
        case 8:
            return 4500;
        case 9:
            return 5000;
        default:
            return 0;
        }
    }

// the gem count band minimum per percentile row of the jewelry composition
// table - 2-12 gems at 01-25 through 10-40 at 00 (folio 23)
inline int dgoGemEGemsMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 10;
        default:
            return 0;
        }
    }

// the gem count band maximum per percentile row (folio 23)
inline int dgoGemEGemsMax(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 36;
        case 3:
            return 20;
        case 4:
            return 24;
        case 5:
            return 30;
        case 6:
            return 40;
        default:
            return 0;
        }
    }

// the carat cap per row as printed - 5 at 01-25, 10 at 26-50, 20 at 51-75, 0
// the no-limitations row, and the at-least minimums of 5, 10 and 20 carats
// riding positive with the band semantics in the print (folio 23)
inline int dgoGemECaratCap(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return 10;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// the jewelry type die band minimum - rings at 01-10, bracers 11-20,
// bracelets 21-25, chalices 26-30, cups 31-35, tankards 36-40, earrings
// 41-50, necklaces 51-60, tableware 61-70, candelabra 71-75, anklets 76-80,
// neckbands 81-85, mirrors 86-90, snuff boxes 91-95, statuettes 96-00 (folio
// 23)
inline int dgoGemFBandMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 21;
        case 3:
            return 26;
        case 4:
            return 31;
        case 5:
            return 36;
        case 6:
            return 41;
        case 7:
            return 51;
        case 8:
            return 61;
        case 9:
            return 71;
        case 10:
            return 76;
        case 11:
            return 81;
        case 12:
            return 86;
        case 13:
            return 91;
        case 14:
            return 96;
        default:
            return 0;
        }
    }

// the jewelry type die band maximum (folio 23)
inline int dgoGemFBandMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 35;
        case 5:
            return 40;
        case 6:
            return 50;
        case 7:
            return 60;
        case 8:
            return 70;
        case 9:
            return 75;
        case 10:
            return 80;
        case 11:
            return 85;
        case 12:
            return 90;
        case 13:
            return 95;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

}   // namespace rules
