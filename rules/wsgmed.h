// =========================================================================================
// Adnd1 - rules/wsgmed.h
// R478: the WSG MEDICINAL PLANTS slice, printed p. 69 - the eighth
// camping-arc round, a TABLE round pinning Table 40: the availability of
// medicinal plants as two 34-row grids (the vegetation chance and the locate
// chance, four seasons apiece) over the terrain-climate frame (D, F, H, M, P,
// Se and Sw - Arctic with no swamp row), plus the slash entry semantics, the
// identify-half rule, the plant-lore always-correct rule, the search
// discipline and the worked example citing Appendix J in the DMG at pages
// 220-221.
// census 402 -> 403.
//
// The settle: the pdf layer DROPPED the entire leftmost terrain-code column
// and ALL five seacoast rows; tesseract kept the codes but garbled many slash
// cells (10110, 5110, 1510, 4010, 75140, 2010) and missed the seacoast rows
// plus the Arctic M row. Every contested cell was settled by targeted vision
// reads with two agreeing independent reads apiece (this round needed SEVEN
// reads); Arctic has no Sw row (six terrains, 34 rows total); and the book
// own worked example - tropical hills winter, vegetation 90 and locate 30 -
// independently confirms the settled row 29.
//
// Bounds held by the grids: every vegetation chance stays in 0-100, every
// locate chance in 0-50; the identify cut is the locate chance halved.
//
namespace rules {

// ---- The terrain and climate frame ----

// five climate bands: arctic through tropical
inline int wmpClimateCount()
    { return 5; }

// seven terrain types per climate: D F H M P Se Sw
inline int wmpTerrainCount()
    { return 7; }

// the arctic band has no Sw row - only six terrains
inline int wmpArcticTerrainCount()
    { return 6; }

// Table 40 rows: 6 arctic plus four climates of 7
inline int wmpRowCount()
    { return 34; }

// the arctic band has no swamp terrain row
inline bool wmpArcticHasNoSwamp()
    { return true; }

// ---- The slash entry semantics ----

// the identify cut: the second roll at one-half or less
inline int wmpIdentifyNum()
    { return 1; }

// of the locate chance identifies the desired plant
inline int wmpIdentifyDen()
    { return 2; }

// the left number of the slash is the vegetation chance
inline bool wmpVegChanceIsLeft()
    { return true; }

// the right number is the one-turn locate chance
inline bool wmpLocateChanceIsRight()
    { return true; }

// an upper-half roll finds the wrong type, assumed right
inline bool wmpUpperHalfWrongType()
    { return true; }

// plant lore proficiency always finds the desired type
inline bool wmpPlantLoreAlwaysRight()
    { return true; }

// ---- The search discipline ----

// one search per turn while the character keeps moving
inline int wmpSearchesPerTurn()
    { return 1; }

// the search is by function, not by one specific plant
inline bool wmpSearchByFunction()
    { return true; }

// continual searching requires never re-searching an area
inline bool wmpKeepMoving()
    { return true; }

// repeated searches of one area auto-fail
inline bool wmpRepeatSearchFails()
    { return true; }

// the searcher concentrates and moves slowed
inline bool wmpSearchSlowsMovement()
    { return true; }

// the DM may add surprise and reaction penalties
inline bool wmpDmMayAddPenalties()
    { return true; }

// the DM may disregard rolls aimed at hoarding medicine
inline bool wmpDmGuardsAbuse()
    { return true; }

// ---- Table 40: the vegetation chance grid ----

// Table 40 vegetation chance: winter
inline int wmpVegWinter(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 70;
        case 8:
            return 20;
        case 9:
            return 10;
        case 10:
            return 20;
        case 11:
            return 25;
        case 12:
            return 15;
        case 13:
            return 10;
        case 14:
            return 80;
        case 15:
            return 65;
        case 16:
            return 20;
        case 17:
            return 50;
        case 18:
            return 50;
        case 19:
            return 30;
        case 20:
            return 5;
        case 21:
            return 90;
        case 22:
            return 80;
        case 23:
            return 40;
        case 24:
            return 80;
        case 25:
            return 80;
        case 26:
            return 40;
        case 27:
            return 5;
        case 28:
            return 100;
        case 29:
            return 90;
        case 30:
            return 85;
        case 31:
            return 100;
        case 32:
            return 90;
        case 33:
            return 50;
        default:
            return 0;
        }
    }

// Table 40 vegetation chance: spring
inline int wmpVegSpring(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 5;
        case 7:
            return 85;
        case 8:
            return 30;
        case 9:
            return 15;
        case 10:
            return 30;
        case 11:
            return 35;
        case 12:
            return 20;
        case 13:
            return 5;
        case 14:
            return 90;
        case 15:
            return 75;
        case 16:
            return 30;
        case 17:
            return 60;
        case 18:
            return 65;
        case 19:
            return 35;
        case 20:
            return 5;
        case 21:
            return 100;
        case 22:
            return 90;
        case 23:
            return 55;
        case 24:
            return 90;
        case 25:
            return 90;
        case 26:
            return 50;
        case 27:
            return 5;
        case 28:
            return 100;
        case 29:
            return 100;
        case 30:
            return 90;
        case 31:
            return 100;
        case 32:
            return 95;
        case 33:
            return 60;
        default:
            return 0;
        }
    }

// Table 40 vegetation chance: summer
inline int wmpVegSummer(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 15;
        case 7:
            return 100;
        case 8:
            return 40;
        case 9:
            return 20;
        case 10:
            return 50;
        case 11:
            return 50;
        case 12:
            return 30;
        case 13:
            return 5;
        case 14:
            return 100;
        case 15:
            return 90;
        case 16:
            return 40;
        case 17:
            return 75;
        case 18:
            return 80;
        case 19:
            return 40;
        case 20:
            return 0;
        case 21:
            return 100;
        case 22:
            return 100;
        case 23:
            return 75;
        case 24:
            return 100;
        case 25:
            return 100;
        case 26:
            return 50;
        case 27:
            return 0;
        case 28:
            return 100;
        case 29:
            return 100;
        case 30:
            return 90;
        case 31:
            return 100;
        case 32:
            return 100;
        case 33:
            return 70;
        default:
            return 0;
        }
    }

// Table 40 vegetation chance: autumn
inline int wmpVegAutumn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 5;
        case 7:
            return 75;
        case 8:
            return 25;
        case 9:
            return 15;
        case 10:
            return 30;
        case 11:
            return 35;
        case 12:
            return 20;
        case 13:
            return 5;
        case 14:
            return 90;
        case 15:
            return 80;
        case 16:
            return 30;
        case 17:
            return 60;
        case 18:
            return 65;
        case 19:
            return 35;
        case 20:
            return 5;
        case 21:
            return 100;
        case 22:
            return 95;
        case 23:
            return 60;
        case 24:
            return 100;
        case 25:
            return 95;
        case 26:
            return 50;
        case 27:
            return 5;
        case 28:
            return 100;
        case 29:
            return 95;
        case 30:
            return 90;
        case 31:
            return 100;
        case 32:
            return 95;
        case 33:
            return 60;
        default:
            return 0;
        }
    }

// ---- Table 40: the locate chance grid ----

// Table 40 locate chance: winter
inline int wmpLocWinter(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 30;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 30;
        case 15:
            return 20;
        case 16:
            return 20;
        case 17:
            return 20;
        case 18:
            return 20;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 40;
        case 22:
            return 40;
        case 23:
            return 30;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 10;
        case 27:
            return 10;
        case 28:
            return 40;
        case 29:
            return 30;
        case 30:
            return 40;
        case 31:
            return 40;
        case 32:
            return 30;
        case 33:
            return 10;
        default:
            return 0;
        }
    }

// Table 40 locate chance: spring
inline int wmpLocSpring(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 10;
        case 7:
            return 30;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 30;
        case 11:
            return 20;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 30;
        case 15:
            return 30;
        case 16:
            return 30;
        case 17:
            return 30;
        case 18:
            return 30;
        case 19:
            return 20;
        case 20:
            return 10;
        case 21:
            return 40;
        case 22:
            return 40;
        case 23:
            return 40;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 20;
        case 27:
            return 10;
        case 28:
            return 40;
        case 29:
            return 30;
        case 30:
            return 40;
        case 31:
            return 40;
        case 32:
            return 40;
        case 33:
            return 10;
        default:
            return 0;
        }
    }

// Table 40 locate chance: summer
inline int wmpLocSummer(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 10;
        case 7:
            return 20;
        case 8:
            return 30;
        case 9:
            return 30;
        case 10:
            return 30;
        case 11:
            return 30;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 30;
        case 15:
            return 40;
        case 16:
            return 30;
        case 17:
            return 40;
        case 18:
            return 30;
        case 19:
            return 20;
        case 20:
            return 0;
        case 21:
            return 40;
        case 22:
            return 50;
        case 23:
            return 40;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 20;
        case 27:
            return 0;
        case 28:
            return 30;
        case 29:
            return 30;
        case 30:
            return 30;
        case 31:
            return 40;
        case 32:
            return 40;
        case 33:
            return 20;
        default:
            return 0;
        }
    }

// Table 40 locate chance: autumn
inline int wmpLocAutumn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 30;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 20;
        case 13:
            return 20;
        case 14:
            return 30;
        case 15:
            return 20;
        case 16:
            return 20;
        case 17:
            return 20;
        case 18:
            return 20;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 40;
        case 22:
            return 50;
        case 23:
            return 30;
        case 24:
            return 40;
        case 25:
            return 30;
        case 26:
            return 10;
        case 27:
            return 10;
        case 28:
            return 40;
        case 29:
            return 30;
        case 30:
            return 40;
        case 31:
            return 30;
        case 32:
            return 30;
        case 33:
            return 10;
        default:
            return 0;
        }
    }

// ---- The worked example and Appendix J ----

// Appendix J in the DMG starts at page 220
inline int wmpAppendixJFirstPage()
    { return 220; }

// Appendix J in the DMG ends at page 221
inline int wmpAppendixJLastPage()
    { return 221; }

// the worked example: tropical hills winter vegetation 90
inline int wmpExVegPct()
    { return 90; }

// the worked example: the locate chance for that cell
inline int wmpExLocatePct()
    { return 30; }

// the example second roll: the plant is the right type
inline int wmpExRoll()
    { return 15; }

// rolls 16-30 find a plant of the wrong type, believed right
inline int wmpExWrongMinRoll()
    { return 16; }

// the top of the wrong-type band equals the locate chance
inline int wmpExWrongMaxRoll()
    { return 30; }

// rolls above 30 find no medicinal plant at all
inline int wmpExFailMinRoll()
    { return 31; }

}   // namespace rules
