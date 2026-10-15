// =========================================================================================
// Adnd1 - rules/wsgtents.h
// R472: the WSG PORTABLE SHELTERS slice with TABLE 36 - the p. 61 seam tail
// (a cave in the face of a mountain slope is a superior shelter in all
// respects, assuming the opening faces away from the wind; the Dungeon Master
// judgment prevailing in any circumstances not covered), the portable shelter
// basics (characters mindful of the need for shelter carrying the appropriate
// materials; a single mount or size M pack animal easily transporting all the
// gear for many shelter types with plenty of carrying capacity left over; in
// the absence of an animal a single average-strength character hauling on his
// back enough for himself and a small group at their rest stops), the
// simplest form (a single wooden pole of 6-10 feet plus a fairly large
// expanse of heavy, waterproofed cloth or similarly pliable material; the DM
// may allow a two- or three-piece pole apparatus held by lashings or pegs,
// easier to transport), the pitch rules (the pole anchored at 30 to 45
// degrees, one end braced on the ground and the other a few feet in the air,
// the covering draped over the pole, the edges touching the ground or tied
// down with ropes and stakes, the opening facing opposite the wind), the
// occupancy (enough space for one human or a pair of smaller characters, and
// in a pinch two men with no appreciable loss of protection or comfort), the
// escalation (more elaborate and larger shelters necessary for especially
// vicious weather or a decent-sized group huddling in one tent) and Table 36
// PORTABLE SHELTER CHARACTERISTICS: the four quality bands poor, adequate,
// good, superior by small, medium, large - encumbrance value 350/450/600,
// 500/600/750, 600/800/1000, 750/1000/1500; cost 10/20/30, 30/50/75,
// 75/120/180, 200/300/400 gold pieces; setup time 1d2+1/1d2+2/1d2+3,
// 1d3+1/1d3+2/1d3+3, 1d3+1/1d3+2/1d4+2, 1d4+1/1d4+2/1d4+3 turns; moisture
// resistance light, moderate, heavy, downpour; wind resistance 20/30/40/50
// percent; life span 40/80/120/180 days), printed p. 62.
// census 396 -> 397.
//
// Ground truth two-way, no contested cells, no physical-page reads: the R467
// TSV-GEOMETRY WORKFLOW (the uploaded p62_tsv.tsv word boxes, the twelve-row
// grid rebuilt from the bounding geometry) vs the user-run Termux tesseract
// text of printed p. 62 (p62_full.txt). The two readers AGREE ON ALL 72 GRID
// CELLS (twelve rows by six columns). The pdf text layer (p62_pdfy.txt) is
// the third reader: it garbles the dice glyphs as ld (the known pattern) but
// agrees on every value and on all prose numbers - the 6-10 foot pole, the
// 30-45 degree pitch, the one-human occupancy with the pair-of-smaller and
// two-men-in-a-pinch readings. The GOOD LARGE SETUP OUTLIER 1d4+2 (breaking
// the 1d3+ pattern of its band) is verified in all three readers. The p. 61
// seam tail (the cave sentence completing the p. 61 shelter-quality
// guidelines) opens the page.
//
// All 72 Table 36 cells pinned (the setup time dice split into a die and a
// modifier column, the moisture resistance encoded as a four-step tier); the
// simple-shelter mechanics, the occupancy limits and the hauling rules are
// audit examples.
//
namespace rules {

// ---- The p. 61 seam tail ----

// a cave in the face of a mountain slope is a superior shelter in all
// respects, assuming the opening faces away from the wind - the p. 61 seam
// tail
inline bool wpsCaveSlopeSuperior()
    { return true; }

// the Dungeon Master judgment will prevail in any circumstances not covered
// by the shelter guidelines
inline bool wpsDmJudgmentPrevails()
    { return true; }

// ---- The portable shelter basics ----

// characters properly mindful of the need for good shelter in the wilderness
// will carry the appropriate materials with them
inline bool wpsMindfulCarryGear()
    { return true; }

// a single mount or size M pack animal can easily transport all the gear
// needed for many types of shelters with plenty of carrying capacity left
// over
inline bool wpsPackAnimalHauls()
    { return true; }

// in the absence of an animal, a single character of average strength can
// usually haul on his back enough shelter materials to keep himself and a
// small group of companions comfortable during their rest stops
inline bool wpsAvgCharHauls()
    { return true; }

// in its simplest form a portable shelter is a single pole plus a fairly
// large expanse of heavy, waterproofed cloth or some similarly pliable
// material
inline bool wpsWaterproofClothCover()
    { return true; }

// the simplest portable shelter uses a single wooden pole of 6-10 feet: the
// length floor
inline int wpsPoleMinFeet()
    { return 6; }

// the pole length ceiling
inline int wpsPoleMaxFeet()
    { return 10; }

// the DM may allow a two- or three-piece pole apparatus held together by
// lashings or pegs, easier to transport
inline int wpsMaxPolePieces()
    { return 3; }

// the DM may decide the framework pole need not be a single piece but a two-
// or three-piece apparatus with the parts held together by lashings or pegs
// when assembled
inline bool wpsMultiPiecePole()
    { return true; }

// the pole is anchored at an angle of 30 to 45 degrees: the floor
inline int wpsPitchMinAngle()
    { return 30; }

// the pitch angle ceiling
inline int wpsPitchMaxAngle()
    { return 45; }

// to pitch a simple tent the pole is braced at 30 to 45 degrees, the covering
// draped over it, the edges tied down with ropes and stakes, and the opening
// in front facing opposite the direction the wind is coming from
inline bool wpsPitchAwayFromWind()
    { return true; }

// ---- The occupancy and the categories ----

// this kind of simple shelter provides enough space for one human or a pair
// of smaller characters
inline bool wpsSimpleFitsOneHuman()
    { return true; }

// in a pinch two men can use the simple shelter with no appreciable loss of
// protection or comfort
inline bool wpsTwoMenInPinch()
    { return true; }

// more elaborate and larger shelters are necessary if the weather is
// especially vicious or if all the characters in a decent-sized group intend
// to huddle inside the same tent
inline bool wpsElaborateForVicious()
    { return true; }

// for game purposes portable shelters come in categories related to the
// quality of protection they provide and the number of man-sized characters
// they can comfortably contain
inline bool wpsCategoryByQualityAndCapacity()
    { return true; }

// the Table 36 quality bands: poor, adequate, good, superior
inline int wpsQualityBands()
    { return 4; }

// the Table 36 sizes within each band: small, medium, large
inline int wpsSizesPerBand()
    { return 3; }

// the Table 36 row count: four quality bands x three sizes
inline int wpsRowCount()
    { return 12; }

// ---- Table 36: the portable shelter characteristics ----

// the Table 36 encumbrance value by quality band and size
inline int wpsEncValue(int b)
    {
        switch (b) {
        case 0:
            return 350;
        case 1:
            return 450;
        case 2:
            return 600;
        case 3:
            return 500;
        case 4:
            return 600;
        case 5:
            return 750;
        case 6:
            return 600;
        case 7:
            return 800;
        case 8:
            return 1000;
        case 9:
            return 750;
        case 10:
            return 1000;
        case 11:
            return 1500;
        default:
            return 0;
        }
    }

// the Table 36 cost in gold pieces
inline int wpsCost(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 30;
        case 4:
            return 50;
        case 5:
            return 75;
        case 6:
            return 75;
        case 7:
            return 120;
        case 8:
            return 180;
        case 9:
            return 200;
        case 10:
            return 300;
        case 11:
            return 400;
        default:
            return 0;
        }
    }

// the Table 36 setup time die: rolls of 1d2+1 through 1d4+3 turns
inline int wpsSetupDie(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        default:
            return 0;
        }
    }

// the Table 36 setup time modifier added to the die
inline int wpsSetupMod(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the Table 36 moisture resistance tier: 0 light, 1 moderate, 2 heavy, 3
// downpour
inline int wpsMoistTier(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the Table 36 wind resistance percent
inline int wpsWindRes(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 30;
        case 6:
            return 40;
        case 7:
            return 40;
        case 8:
            return 40;
        case 9:
            return 50;
        case 10:
            return 50;
        case 11:
            return 50;
        default:
            return 0;
        }
    }

// the Table 36 life span in days
inline int wpsLifeSpan(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 40;
        case 2:
            return 40;
        case 3:
            return 80;
        case 4:
            return 80;
        case 5:
            return 80;
        case 6:
            return 120;
        case 7:
            return 120;
        case 8:
            return 120;
        case 9:
            return 180;
        case 10:
            return 180;
        case 11:
            return 180;
        default:
            return 0;
        }
    }

}   // namespace rules
