// =========================================================================================
// Adnd1 - rules/wsgwater.h
// R467: the WSG FINDING WATER slice - the water-finding checks (two per day,
// extra searches automatically fail, the table not used where water is
// obviously and readily available), the snow-and-ice exception (water for the
// taking if the party can melt it, the figures assume no snow or ice cover,
// ice at 30 degrees or lower with the taint read from the table, freshly
// fallen snow the purest water in nature), the nearby-fresh-water and
// seacoast notes (the dig-to-the-water-table 100% above the high tide line
// and no more than two feet deep, the deeper the saltier) and Table 34: the
// chance of finding water grid by climate, terrain and season, printed p. 58
// with the grid on p. 59.
// census 391 -> 392.
//
// Ground truth four-way, a NEW WORKFLOW (the user decision this round): the
// user ran tesseract ON TERMUX over the pdfimages-extracted scan of printed
// p. 59 (poppler pdfimages -f 60, TSV output with word bounding boxes), and
// the grid was REBUILT FROM GEOMETRY - the terrain-code column at x 130-165,
// the season cells at x 190/285/385/480, one row per 20 pixels of y - instead
// of trusting any reader reading order. The tesseract reads cross-check
// against the pdfy embedded OCR layer and the djvu word layer: all three
// agree on every one of the 224 values. The slash-loss cells (tesseract 570,
// 5170, 60740, 30730, 70170) all resolve to the obvious xx/yy splits
// confirmed by the other two readers. The low-confidence terrain labels
// (subarctic E, temperate =%) resolve to F (forest) - vision confirmed, and
// forest is the missing terrain in both bands. The ONE contested value:
// Tropical swamp Spring reads 90/75 in BOTH text layers (tesseract conf 40,
// djvu 90/75, pdfy 90/75) but 90/80 in two vision reads; the USER READ THE
// PHYSICAL PAGE and settled it: 90/75 - the only taint value in the whole
// table not ending in 0, pinned as printed. The arctic rows are constant
// across all four seasons; the swamp rows carry the highest find chances; the
// desert rows the lowest. The seacoast and snow mechanics come from the same
// tesseract pass (the p59_full --psm 4 text) and the printed p. 58 intro from
// the pdfy layer, cross-checked against the user p58 tesseract run. The
// where-water-is-found section (the DM standing-water reduction and the
// water-table definition) stays in the p. 59 gap - NOT flipped this round.
//
// All 224 Table 34 values pinned (the find% and the taint% per climate per
// terrain per season); the water-finding mechanics are audit examples,
// including the human-verified Tropical swamp 90/75 cell and the arctic
// constant rows.
//
namespace rules {

// ---- The water-finding checks ----

// a single character or a group traveling together can make two water-finding
// checks per day
inline int wfwChecksPerDay()
    { return 2; }

// searches conducted more often than two per day automatically fail
inline bool wfwExtraSearchAutoFail()
    { return true; }

// the table should not be used in any circumstances where water is obviously
// and readily available
inline bool wfwNotUsedWhenObvious()
    { return true; }

// characters on the bank or shore of fresh water still use the table for the
// taint chance unless the water is known pure and drinkable
inline bool wfwNearbyFreshWaterTaintCheck()
    { return true; }

// ---- Table 34: the chance of finding water grid ----

// the Table 34 row count: five climate bands x the terrain rows (arctic has
// no forest row; the other four climates run D/F/H/M/P/Sw)
inline int wfwRowCount()
    { return 28; }

// the Table 34 winter find% (left of the slash)
inline int wfwWinFind(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 10;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 10;
        case 9:
            return 40;
        case 10:
            return 5;
        case 11:
            return 30;
        case 12:
            return 30;
        case 13:
            return 20;
        case 14:
            return 20;
        case 15:
            return 60;
        case 16:
            return 5;
        case 17:
            return 60;
        case 18:
            return 30;
        case 19:
            return 40;
        case 20:
            return 20;
        case 21:
            return 70;
        case 22:
            return 5;
        case 23:
            return 80;
        case 24:
            return 15;
        case 25:
            return 40;
        case 26:
            return 20;
        case 27:
            return 70;
        default:
            return 0;
        }
    }

// the Table 34 winter taint% (right of the slash)
inline int wfwWinTaint(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 60;
        case 5:
            return 40;
        case 6:
            return 40;
        case 7:
            return 30;
        case 8:
            return 50;
        case 9:
            return 60;
        case 10:
            return 70;
        case 11:
            return 30;
        case 12:
            return 40;
        case 13:
            return 30;
        case 14:
            return 50;
        case 15:
            return 70;
        case 16:
            return 70;
        case 17:
            return 40;
        case 18:
            return 40;
        case 19:
            return 30;
        case 20:
            return 50;
        case 21:
            return 70;
        case 22:
            return 70;
        case 23:
            return 50;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 50;
        case 27:
            return 70;
        default:
            return 0;
        }
    }

// the Table 34 spring find%
inline int wfwSprFind(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 10;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 60;
        case 10:
            return 5;
        case 11:
            return 40;
        case 12:
            return 40;
        case 13:
            return 20;
        case 14:
            return 40;
        case 15:
            return 70;
        case 16:
            return 5;
        case 17:
            return 70;
        case 18:
            return 50;
        case 19:
            return 60;
        case 20:
            return 40;
        case 21:
            return 80;
        case 22:
            return 10;
        case 23:
            return 80;
        case 24:
            return 20;
        case 25:
            return 70;
        case 26:
            return 50;
        case 27:
            return 90;
        default:
            return 0;
        }
    }

// the Table 34 spring taint%
inline int wfwSprTaint(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 60;
        case 5:
            return 40;
        case 6:
            return 40;
        case 7:
            return 30;
        case 8:
            return 50;
        case 9:
            return 60;
        case 10:
            return 70;
        case 11:
            return 30;
        case 12:
            return 40;
        case 13:
            return 30;
        case 14:
            return 50;
        case 15:
            return 70;
        case 16:
            return 70;
        case 17:
            return 50;
        case 18:
            return 40;
        case 19:
            return 40;
        case 20:
            return 40;
        case 21:
            return 70;
        case 22:
            return 70;
        case 23:
            return 60;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 50;
        case 27:
            return 75;
        default:
            return 0;
        }
    }

// the Table 34 summer find%
inline int wfwSumFind(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 20;
        case 9:
            return 50;
        case 10:
            return 5;
        case 11:
            return 30;
        case 12:
            return 40;
        case 13:
            return 15;
        case 14:
            return 40;
        case 15:
            return 80;
        case 16:
            return 5;
        case 17:
            return 70;
        case 18:
            return 50;
        case 19:
            return 50;
        case 20:
            return 30;
        case 21:
            return 90;
        case 22:
            return 5;
        case 23:
            return 80;
        case 24:
            return 30;
        case 25:
            return 60;
        case 26:
            return 60;
        case 27:
            return 90;
        default:
            return 0;
        }
    }

// the Table 34 summer taint%
inline int wfwSumTaint(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 60;
        case 5:
            return 50;
        case 6:
            return 50;
        case 7:
            return 30;
        case 8:
            return 50;
        case 9:
            return 60;
        case 10:
            return 70;
        case 11:
            return 30;
        case 12:
            return 50;
        case 13:
            return 30;
        case 14:
            return 50;
        case 15:
            return 80;
        case 16:
            return 80;
        case 17:
            return 60;
        case 18:
            return 40;
        case 19:
            return 50;
        case 20:
            return 40;
        case 21:
            return 80;
        case 22:
            return 80;
        case 23:
            return 70;
        case 24:
            return 50;
        case 25:
            return 40;
        case 26:
            return 60;
        case 27:
            return 80;
        default:
            return 0;
        }
    }

// the Table 34 autumn find%
inline int wfwAutFind(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 15;
        case 9:
            return 50;
        case 10:
            return 5;
        case 11:
            return 30;
        case 12:
            return 30;
        case 13:
            return 20;
        case 14:
            return 30;
        case 15:
            return 60;
        case 16:
            return 5;
        case 17:
            return 60;
        case 18:
            return 40;
        case 19:
            return 40;
        case 20:
            return 20;
        case 21:
            return 70;
        case 22:
            return 5;
        case 23:
            return 80;
        case 24:
            return 15;
        case 25:
            return 70;
        case 26:
            return 50;
        case 27:
            return 80;
        default:
            return 0;
        }
    }

// the Table 34 autumn taint%
inline int wfwAutTaint(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 60;
        case 5:
            return 40;
        case 6:
            return 40;
        case 7:
            return 30;
        case 8:
            return 50;
        case 9:
            return 60;
        case 10:
            return 80;
        case 11:
            return 30;
        case 12:
            return 40;
        case 13:
            return 30;
        case 14:
            return 50;
        case 15:
            return 70;
        case 16:
            return 80;
        case 17:
            return 50;
        case 18:
            return 40;
        case 19:
            return 40;
        case 20:
            return 50;
        case 21:
            return 80;
        case 22:
            return 80;
        case 23:
            return 60;
        case 24:
            return 40;
        case 25:
            return 40;
        case 26:
            return 50;
        case 27:
            return 80;
        default:
            return 0;
        }
    }

// ---- The obvious-water exceptions ----

// with snow or ice cover the water is there for the taking as long as
// characters are willing and able to melt the snow or ice
inline bool wfwSnowIceCoverFreeWater()
    { return true; }

// the Table 34 figures assume that no snow or ice cover exists
inline bool wfwTableAssumesNoSnowIce()
    { return true; }

// if the actual temperature is 30 degrees or lower, any water found in an
// area with no snow or ice cover will be in the form of ice
inline int wfwIceTempGate()
    { return 30; }

// ice is no more free of foreign substances than the water it formed from:
// the percentage chance of tainted ice is taken from the table as if water
// had been found
inline bool wfwIceTaintPerTable()
    { return true; }

// freshly fallen snow is the purest form of water available in nature; melted
// snow satisfies the water need as long as enough snow is available - a mere
// dusting provides little liquid
inline bool wfwFreshSnowPurest()
    { return true; }

// drinking sea water actually dehydrates the character: the salt increases
// the body need for water, in large quantities or over a long period
inline bool wfwSeaWaterDehydrates()
    { return true; }

// in any seacoast area the chance of finding drinkable water by digging down
// to the water table is 100%
inline int wfwSeacoastDigPct()
    { return 100; }

// the seacoast dig hole must be dug above the high tide line for the 100%
// chance to hold
inline bool wfwSeacoastDigAboveTide()
    { return true; }

// the seacoast dig hole must be no more than two feet deep for the 100%
// chance to hold
inline int wfwSeacoastDigMaxFt()
    { return 2; }

// the deeper one digs toward the seacoast water table, the saltier the water;
// digging too deep in one hole recovers water as undrinkable as the sea,
// though the loose soil filters out most of the salt near the surface
inline bool wfwDigDeeperSaltier()
    { return true; }

// ---- The water-quality guidelines ----

// river water is more likely pure closer to the source than downstream
inline bool wfwRiverPurerUpstream()
    { return true; }

// lake water is more likely pure where a river flows in than along the
// opposite shoreline where the water stagnates
inline bool wfwLakePurerAtInflow()
    { return true; }

// fast-flowing water is generally more pure than standing water
inline bool wfwFastFlowPurer()
    { return true; }

// ground water, found by digging beneath the surface, is usually more pure
// than water found above the ground
inline bool wfwGroundWaterPurer()
    { return true; }

}   // namespace rules
