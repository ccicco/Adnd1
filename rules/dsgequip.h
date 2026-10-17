// =========================================================================================
// Adnd1 - rules/dsgequip.h
// The DSG NEW EQUIPMENT COSTS AND WEIGHTS, R525: printed pp. 56-57 (pdf
// 57-58) - the chapter frame (the equipment primarily for underground
// exploration but usable in any AD&D campaign, listed with average cost and
// typical encumbrance, descriptions to follow, the specific uses tied to the
// climbing, mining and underground water travel rules) and the Table 35
// cost/weight grid: the twenty general rows (air bladder 15 gp and 20 gp,
// basket large 5 sp and 80 gp, basket small 2 sp and 40 gp, beacon 40 gp and
// 200 gp, birdcage 5 sp and 50 gp, box small gold 100 gp and 20 gp, box small
// lead 20 gp and 20 gp, crampons 40 gp and 50 gp, crowbar 3 gp and 75 gp,
// drill iron 5 gp and 50 gp, grappling hook 75 gp and 75 gp, lantern
// waterproof 50 gp and 50 gp, lard pint 5 cp and 20 gp, oil waterproofing 1
// gp and 20 gp, pickaxe 20 gp and 200 gp, powder chalk 2 sp and 20 gp, pulley
// 25 gp and 60 gp, reed hollow 1 sp and 1 pc, shovel 10 gp and 180 gp,
// whistle 1 sp and 1 pc) and the four transportation rows (boat collapsible
// 500 gp and 600 gp, canoe small 100 gp and 800 gp, canoe large 300 gp and
// 1,600 gp, kayak 250 gp and 500 gp); and the equipment for proficiencies:
// the fourteen initial costs and minimum spaces (animal trainer 100 gp and
// 1-20 acres, armorer 1,250 gp and 20 x 20, blacksmith 1,000 gp and 30 x 30,
// boatwright 1,000 gp and 50 x 120, bowyer/fletcher 250 gp and 20 x 20,
// carpenter 400 gp and varies by task, gem cutter 2,225 gp and 15 x 15,
// leatherworker 300 gp and 15 x 15, miner 750 gp and varies, potter 600 gp
// and 20 x 30, smelter 2,000 gp and 50 x 50, stonemason 250 gp and varies,
// weaponsmith 1,500 gp and 40 x 30, weaver 500 gp and 30 x 30), the rule that
// a proficiency is only partially effective without the necessary space, and
// the raw-materials exclusion - the costs do not include the raw materials
// (an armorer or blacksmith needs iron, hardwood or coal), which run 11-20%
// (1d10 + 10) of the finished work value
// census 448 -> 449.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~7205-7265) with the pdf Acrobat-Capture layer as the second read (idx 131
// = the printed p. 56 window, idx 133 = the p. 57 window); the
// compiled-tables appendix has an equipment reprint but it shares the same
// failed OCR layer. AN OCR-FAILURE ROUND, THE THIRD OF THE MINING STRETCH:
// the Table 35 grid failed in both machine reads with genuine conflicts
// between them - the djvu garbled every sp as the Cyrillic ар and dropped the
// basket-small cost entirely, while the Capture layer dropped the lard, reed
// and whistle cells and mislabeled others - and the vision passes over
// Curtiss's screenshots wobbled the currency units (air bladder 15 sp/5 sp/15
// gp across passes). The grid was settled by Curtiss reading the physical
// printed p. 56: air bladder 15 gp (the direct read that also exposed the
// sp-pattern assumption as unsafe), basket small 2 sp and 40 gp, basket large
// 5 sp and 80 gp, crowbar 3 gp, pulley 25 gp and 60 gp, reed 1 sp and 1 pc,
// whistle 1 sp and 1 pc. The machine reads corroborate the clean cells (the
// beacon, boxes, crampons, drill, grappling hook, lantern, oil, pickaxe,
// powder and shovel rows agree across djvu and Capture), the four
// transportation rows, and the full fourteen-row proficiency list (both reads
// agree on every cost; the areas share only the trivial degree-sign glyph
// garble). The reed and whistle weight prints 1 pc - the book's own
// abbreviation in the coin-weight column, pinned as printed per the
// never-repair rule. The new-equipment descriptions and the transportation
// prose (children 138-139) land NEXT round per the content-density rule; the
// descriptions text is already extracted and clean in both machine reads. The
// R518 water-travel, R520 mining and climbing seams are noted; nothing
// auto-credits.
//
// Two tables pin: Table 35 as a 24x2 grid (cost in copper pieces normalized,
// weight in gold-piece coin weight - the twenty general rows plus the four
// transportation rows), and the proficiency equipment as a 14x2 grid (initial
// cost in gold pieces, minimum space in square feet with the sentinel -99 for
// the animal-trainer acres and the carpenter/miner/stonemason Varies rows).
// The raw-material percent pins as dice + sides + add consts (1d10 + 10
// giving the 11-20% range) per the R508 convention. The frame rules pin as
// prose bools: the any-campaign usability, the cost-and-encumbrance listing,
// the space-required rule, the raw-materials exclusion with the
// armorer/blacksmith example, and the printed 1-pc pin. The physical-read
// provenance is load-bearing for the seven OCR-failed cells (the air bladder,
// basket-small, basket-large, crowbar, pulley, reed and whistle cells); the
// R517/R521/R522 lessons apply. The climbing/mining/water-travel seams are
// noted; nothing auto-credits.
//
namespace rules {

// ---- the chapter frame ----

// the new equipment, while primarily intended for underground exploration,
// can be used in any AD&D game campaign.
inline bool dntaUsableAnyCampaign()
    { return true; }

// the new equipment is listed with its average cost and typical encumbrance,
// with descriptions following the lists.
inline bool dntaListedWithCostAndEncumbrance()
    { return true; }

// specific uses of some equipment are explained under the rules for climbing,
// mining, and underground water travel (the cross-chapter seams).
inline bool dntaUsesTiedToRules()
    { return true; }

// the Table 35 cost/weight grid carries twenty general rows plus the four
// Transportation rows (the collapsible boat, the two canoes and the kayak).
inline int dntaT35RowCount()
    { return 24; }

// the cost in copper pieces, rows air bladder, basket large, basket small,
// beacon, birdcage, box gold, box lead, crampons, crowbar, drill, grappling
// hook, lantern waterproof, lard, oil, pickaxe, powder chalk, pulley, reed,
// shovel, whistle, boat, canoe small, canoe large, kayak: 1500, 50, 20, 4000,
// 50, 10000, 2000, 4000, 300, 500, 7500, 5000, 5, 100, 2000, 20, 2500, 10,
// 1000, 10, 50000, 10000, 30000, 25000.
inline int dntaT35CostCp(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 50;
        case 2:
            return 20;
        case 3:
            return 4000;
        case 4:
            return 50;
        case 5:
            return 10000;
        case 6:
            return 2000;
        case 7:
            return 4000;
        case 8:
            return 300;
        case 9:
            return 500;
        case 10:
            return 7500;
        case 11:
            return 5000;
        case 12:
            return 5;
        case 13:
            return 100;
        case 14:
            return 2000;
        case 15:
            return 20;
        case 16:
            return 2500;
        case 17:
            return 10;
        case 18:
            return 1000;
        case 19:
            return 10;
        case 20:
            return 50000;
        case 21:
            return 10000;
        case 22:
            return 30000;
        case 23:
            return 25000;
        default:
            return -99;
        }
    }

// the typical encumbrance in gold-piece coin weight, same row order: 20, 80,
// 40, 200, 50, 20, 20, 50, 75, 50, 75, 50, 20, 20, 200, 20, 60, 1, 180, 1,
// 600, 800, 1600, 500 (the reed and whistle print 1 pc).
inline int dntaT35WtGp(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 80;
        case 2:
            return 40;
        case 3:
            return 200;
        case 4:
            return 50;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 50;
        case 8:
            return 75;
        case 9:
            return 50;
        case 10:
            return 75;
        case 11:
            return 50;
        case 12:
            return 20;
        case 13:
            return 20;
        case 14:
            return 200;
        case 15:
            return 20;
        case 16:
            return 60;
        case 17:
            return 1;
        case 18:
            return 180;
        case 19:
            return 1;
        case 20:
            return 600;
        case 21:
            return 800;
        case 22:
            return 1600;
        case 23:
            return 500;
        default:
            return -99;
        }
    }

// ---- the equipment for proficiencies ----

// the proficiency equipment gives the initial cost and the minimum space the
// operation requires - if the necessary space is not available, the
// proficiency is only partially effective.
inline bool dntaProfSpaceRequired()
    { return true; }

// the given costs do not include the raw materials characters must buy before
// using most proficiencies - an armorer or blacksmith needs iron, hardwood or
// coal for the forge; the raw materials cost 11-20% (1d10 + 10) of the
// finished work value.
inline bool dntaProfCostsExcludeRawMaterials()
    { return true; }

// the raw-material cost roll is one die.
inline int dntaRawMatDice()
    { return 1; }

// the cost of raw materials is 11-20% of the finished work value - 1d10 + 10.
inline int dntaRawMatSides()
    { return 10; }

// the +10 add makes the 1d10 raw-material roll the 11-20% range.
inline int dntaRawMatAddPct()
    { return 10; }

// the proficiency equipment grid carries fourteen proficiencies from animal
// trainer through weaver.
inline int dntaProfRowCount()
    { return 14; }

// the initial equipment cost in gold pieces, rows animal trainer, armorer,
// blacksmith, boatwright, bowyer fletcher, carpenter, gem cutter,
// leatherworker, miner, potter, smelter, stonemason, weaponsmith, weaver:
// 100, 1250, 1000, 1000, 250, 400, 2225, 300, 750, 600, 2000, 250, 1500, 500.
inline int dntaProfCostGp(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 1250;
        case 2:
            return 1000;
        case 3:
            return 1000;
        case 4:
            return 250;
        case 5:
            return 400;
        case 6:
            return 2225;
        case 7:
            return 300;
        case 8:
            return 750;
        case 9:
            return 600;
        case 10:
            return 2000;
        case 11:
            return 250;
        case 12:
            return 1500;
        case 13:
            return 500;
        default:
            return -99;
        }
    }

// the minimum space in square feet: -99 the animal trainer 1-20 acres varies,
// 400 armorer 20 x 20, 900 blacksmith 30 x 30, 6000 boatwright 50 x 120, 400
// bowyer 20 x 20, -99 carpenter varies by task, 225 gem cutter 15 x 15, 225
// leatherworker 15 x 15, -99 miner varies, 600 potter 20 x 30, 2500 smelter
// 50 x 50, -99 stonemason varies, 1200 weaponsmith 40 x 30, 900 weaver 30 x
// 30.
inline int dntaProfAreaSqft(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 400;
        case 2:
            return 900;
        case 3:
            return 6000;
        case 4:
            return 400;
        case 5:
            return -99;
        case 6:
            return 225;
        case 7:
            return 225;
        case 8:
            return -99;
        case 9:
            return 600;
        case 10:
            return 2500;
        case 11:
            return -99;
        case 12:
            return 1200;
        case 13:
            return 900;
        default:
            return -99;
        }
    }

// ---- the grid footnotes ----

// the reed and whistle weight cells print as 1 pc (the book's own
// abbreviation in the coin-weight column, pinned as printed per the
// never-repair rule).
inline bool dntaReedWhistleWeightPrintedPc()
    { return true; }

// the animal trainer needs little specialized equipment - at most a few
// harnesses or leashes - but the training of most animals requires a great
// deal of room, generally some kind of outdoor space, with shelter and food
// if boarding animals (the 1-20 acres area varies).
inline bool dntaAnimalTrainerSpaceVaries()
    { return true; }

// the carpenter area varies by task, and the miner and stonemason areas vary
// - the three Varies rows of the proficiency grid.
inline bool dntaCarpenterMinerStonemasonVary()
    { return true; }

}   // namespace rules
