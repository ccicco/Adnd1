// =========================================================================================
// Adnd1 - rules/dsgmine4.h
// The DSG QUALITY OF MINE PRODUCTS, R522: printed pp. 50-51 (pdf 51-52) - the
// metals rules: the quality of the metal or ore equals the coins producible
// from the metal mined by a single miner in a week (the ore usually heavily
// mixed with rock, the smelter proficiency processing it to pure state, the
// rare pure-nugget vein), the Table 33 ore quality grid over the 1d10 roll
// for five metals (copper 100/200/250/300/350/400/500/750/1000/2000, iron
// 200/300/500/700/900/1200/1600/2000/3000/4000, silver
// 25/50/100/200/300/400/500/750/1000/2000, gold
// 10/25/50/100/200/300/400/500/750/1000, platinum
// 5/10/20/40/75/100/250/400/800/1000), the pure-vein rule (a 10 on the
// quality roll means roll again - another 10 is a pure vein requiring no
// smelting, 1-9 smelts normally), the unsmelted selling (no more than 25%,
// possibly 5%, by the buyer's transport and smelting difficulty), and the
// iron equivalences (1000 coins of iron = a full plate suit, 100 spear
// points, or 500 arrowheads); and the gemstones rules: the rough unrecognized
// stones identified by miner or jeweler proficiency after 1d6 turns of study,
// the quality as stones per man-week and average value of the finished stones
// (Table 34 - bloodstone 2d10 at 20 + 10d6 gp, amber 1d10 at 6d100 gp, onyx
// 3d10 at 10 + 10d6 gp, turquoise and agate 4d10 at 5d6 gp, aquamarine 1d10
// at 10 x 5d6 gp, garnet and alexandrite 1d10 at 100 x 1d4 gp, jade 2d10 at
// 10 x 5d6 gp, amethyst 1d10 at 100 x 1d6 gp, topaz 2d10 at 100 x 1d4 gp, jet
// 1d10 at 10 x 5d6 gp, opal 1d10/3 at 200 x 1d6 gp, ruby 1d10/3 at 200 x 1d8
// gp, sapphire 1d10/4 at 200 x 1d8 gp, diamond 1d10/5 at 300 x 1d6 gp,
// emerald 1d10/5 at 300 x 1d8 gp, the footnote rows rolling 1d10 divided by
// 3/4/5 and rounded up), the unfinished selling (no greater than 25%,
// possibly 10%), and the weekly value re-roll (the week's quality applying to
// all miners that week, the miner count set before the rolls)
// census 445 -> 446.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the machine reads are the IA djvu OCR (djvu.txt lines
// ~6625-6700), the pdf Acrobat-Capture layer (idx 121 = printed pp. 50-51
// window, idx 122 = the Table 34 page) and the compiled-tables appendix
// reprint. THE OCR-FAILURE ROUND: both grids are the garble of the round, and
// the garbles are text the OCR layers simply failed - the Table 33 copper and
// iron rows are dropped by every machine read (the appendix keeps only a
// 2000/4000 tail glimpse), and the Table 34 machine reads lost the stone
// labels and shuffled the count/value cells into fragments. Both grids were
// settled by Curtiss reading the physical pages via screenshot: Table 33 from
// the printed p. 50 screenshot (two vision passes agreeing on all fifty
// cells; the iron row was read twice digit by digit), Table 34 from two
// printed p. 51 screenshots with the final contested cell - onyx 10 + 10d6 gp
// - settled by Curtiss's direct read after the vision passes wobbled the
// operator and die count. The machine reads corroborate the T33
// silver/gold/platinum rows (djvu and Capture agree with the appendix on all
// three) and the T34 middle rows (the appendix fragments confirm agate 4d10,
// amethyst 100 x 1d6, topaz 100 x 1d4, emerald 1d10/5 at 300 x 1d8, diamond
// 1d10/5, the opal/ruby/sapphire 200-multiplier band, and the onyx 10d6
// tail). The physical book outranks the scan (the R521 bloodstone lesson, now
// twice exercised). NOTE: amber appears in Table 34 but not in Table 32's
// gemstone list - pinned as printed per the R517 never-repair lesson. The
// quality grids pin as numeric engine tables (T33 five metal columns over ten
// rolls; T34 seven columns encoding count dice/sides/divisor and value
// add/mult/dice/sides). The placer-value, smelting and duration rules start
// the NEXT round per the content-density rule.
//
// Two tables pin: Table 33 as a 10x5 quality grid (one column per metal, ten
// rows for the d10 rolls), and Table 34 as a 17x7 grid encoding each stone
// row as count dice, count sides, divide divisor, value addend, value
// multiplier, value dice and value sides - the dice expressions pinned as
// numbers per the R508 dice convention, with the divisor column carrying the
// /3 /4 /5 footnote rows. The 1d10 ore quality roll and the 1d6-turn
// identification pin as dice + sides consts. The pure-vein 10, the selling
// percentages (ore 25/5, stones 25/10) and the iron equivalences
// (1000/100/500) pin as consts. The smelter processing, the pure-vein rules,
// the weekly re-roll applying to all miners, and the round-up footnote pin as
// prose bools. The physical-read provenance is load-bearing for the T33
// copper/iron rows and the T34 top rows; the R517 seam (amber absent from
// Table 32) is noted; nothing auto-credits.
//
namespace rules {

// ---- the Table 33 ore quality grid ----

// a metal mine usually yields the metal in its ore form, heavily mixed with
// rock.
inline bool dnqtOreMixedWithRock()
    { return true; }

// generally a character with smelter proficiency must process the ore to its
// pure metallic state (a very pure nugget vein may occasionally be
// discovered).
inline bool dnqtSmelterPurifies()
    { return true; }

// the quality of the metal or ore equals the number of coins producible from
// the metal mined by a single miner in a week.
inline bool dnqtQualityCoinsPerMinerWeek()
    { return true; }

// the ore quality roll is one die.
inline int dnqtOreQualityDice()
    { return 1; }

// the ore quality roll is 1d10 compared on Table 33; the result is the coins
// of metal the mine yields in one man-week.
inline int dnqtOreQualitySides()
    { return 10; }

// the Table 33 ore quality grid carries the ten d10 quality rolls.
inline int dnqtT33RowCount()
    { return 10; }

// the copper coins per man-week by d10 roll 1-10: 100, 200, 250, 300, 350,
// 400, 500, 750, 1000, 2000 (physical read; the machine reads lost the copper
// row).
inline int dnqtT33Copper(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 200;
        case 2:
            return 250;
        case 3:
            return 300;
        case 4:
            return 350;
        case 5:
            return 400;
        case 6:
            return 500;
        case 7:
            return 750;
        case 8:
            return 1000;
        case 9:
            return 2000;
        default:
            return -99;
        }
    }

// the iron coins per man-week: 200, 300, 500, 700, 900, 1200, 1600, 2000,
// 3000, 4000 (physical read; the iron row is dropped by every machine read -
// the appendix keeps only the 2000/4000 tail glimpses).
inline int dnqtT33Iron(int b)
    {
        switch (b) {
        case 0:
            return 200;
        case 1:
            return 300;
        case 2:
            return 500;
        case 3:
            return 700;
        case 4:
            return 900;
        case 5:
            return 1200;
        case 6:
            return 1600;
        case 7:
            return 2000;
        case 8:
            return 3000;
        case 9:
            return 4000;
        default:
            return -99;
        }
    }

// the silver coins per man-week: 25, 50, 100, 200, 300, 400, 500, 750, 1000,
// 2000.
inline int dnqtT33Silver(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 200;
        case 4:
            return 300;
        case 5:
            return 400;
        case 6:
            return 500;
        case 7:
            return 750;
        case 8:
            return 1000;
        case 9:
            return 2000;
        default:
            return -99;
        }
    }

// the gold coins per man-week: 10, 25, 50, 100, 200, 300, 400, 500, 750,
// 1000.
inline int dnqtT33Gold(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 25;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 200;
        case 5:
            return 300;
        case 6:
            return 400;
        case 7:
            return 500;
        case 8:
            return 750;
        case 9:
            return 1000;
        default:
            return -99;
        }
    }

// the platinum coins per man-week: 5, 10, 20, 40, 75, 100, 250, 400, 800,
// 1000.
inline int dnqtT33Platinum(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 40;
        case 4:
            return 75;
        case 5:
            return 100;
        case 6:
            return 250;
        case 7:
            return 400;
        case 8:
            return 800;
        case 9:
            return 1000;
        default:
            return -99;
        }
    }

// ---- the pure vein and the selling of ore ----

// a 10 followed by another 10 on the quality roll is a pure vein of metal
// requiring no smelting.
inline bool dnqtPureVeinNeedsNoSmelting()
    { return true; }

// if the second quality roll is 1-9, the metal must be smelted normally.
inline bool dnqtPureVeinSmeltOtherwise()
    { return true; }

// the coinage amount indicates how much metal is produced - it does not mean
// the metal must be used to make coins (particularly true of iron).
inline bool dnqtCoinageIndicatesMetalAmount()
    { return true; }

// a 10 on the quality roll means roll 1d10 again; another 10 is a pure vein
// of metal.
inline int dnqtOrePureVeinRoll()
    { return 10; }

// ore sold without smelting brings no more than 25% of the pure metal value.
inline int dnqtUnsmeltedOreSellMaxPct()
    { return 25; }

// unsmelted ore might bring as low as 5% of the pure metal worth.
inline int dnqtUnsmeltedOreSellMinPct()
    { return 5; }

// one thousand coins worth of iron equals a full suit of plate armor.
inline int dnqtIronCoinPlate()
    { return 1000; }

// one thousand coins worth of iron equals 100 spear points.
inline int dnqtIronCoinSpearPoints()
    { return 100; }

// one thousand coins worth of iron equals 500 arrowheads.
inline int dnqtIronCoinArrowheads()
    { return 500; }

// ---- the Table 34 gemstone quality grid ----

// gemstones fresh from the mine are rough, often unrecognizable, and not
// nearly as valuable as after finishing.
inline bool dnqtStonesRoughUnrecognized()
    { return true; }

// characters with miner or jeweler proficiency can correctly identify a stone
// after study; others simply see another rock.
inline bool dnqtMinerOrJewelerIdentifies()
    { return true; }

// the stone identification study is one die of turns (miner or jeweler
// proficiency).
inline int dnqtStoneIdentifyDice()
    { return 1; }

// a proficient character identifies a rough stone after 1d6 turns of study;
// others simply see another rock.
inline int dnqtStoneIdentifySides()
    { return 6; }

// the number of stones is the amount that one miner can excavate in a week;
// the value is the average for the finished stones.
inline bool dnqtStoneCountPerMinerWeek()
    { return true; }

// the value of a gemstone find does not remain constant - it is rolled each
// week for that week's output.
inline bool dnqtStoneValueRolledEachWeek()
    { return true; }

// the quality determined for the week applies to all miners working that
// entire week, and the number of miners is determined before the dice rolls.
inline bool dnqtQualityAppliesAllMinersWeek()
    { return true; }

// for the Table 34 division rows, roll 1d10, divide the result by 3, 4, or 5
// as indicated, and round up.
inline bool dnqtDivideAndRoundUp()
    { return true; }

// unfinished stones sell for no greater than 25% of the listed value.
inline int dnqtUnfinishedStonesSellMaxPct()
    { return 25; }

// unfinished stones might sell for as low as 10% of the listed value.
inline int dnqtUnfinishedStonesSellMinPct()
    { return 10; }

// the Table 34 gemstone quality grid carries seventeen stone rows.
inline int dnqtT34RowCount()
    { return 17; }

// the stones-per-man-week die count, in the printed row order bloodstone
// through emerald: 2, 1, 3, 4, 4, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1.
inline int dnqtT34CountDice(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 2;
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

// the stones-per-man-week die sides: d10 throughout.
inline int dnqtT34CountSides(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 10;
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

// the divide-and-round-up divisor (the footnote rows): 1 everywhere except
// opal 3, ruby 3, sapphire 4, diamond 5, emerald 5.
inline int dnqtT34CountDiv(int b)
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
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        default:
            return -99;
        }
    }

// the additive base of the average value: bloodstone 20 (20 + 10d6 gp), onyx
// 10 (10 + 10d6 gp), all other rows 0.
inline int dnqtT34ValAdd(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 10;
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
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        default:
            return -99;
        }
    }

// the average-value multiplier: 1 except aquamarine 10, garnet 100, jade 10,
// alexandrite 100, amethyst 100, topaz 100, jet 10, opal 200, ruby 200,
// sapphire 200, diamond 300, emerald 300.
inline int dnqtT34ValMult(int b)
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
            return 10;
        case 6:
            return 100;
        case 7:
            return 10;
        case 8:
            return 100;
        case 9:
            return 100;
        case 10:
            return 100;
        case 11:
            return 10;
        case 12:
            return 200;
        case 13:
            return 200;
        case 14:
            return 200;
        case 15:
            return 300;
        case 16:
            return 300;
        default:
            return -99;
        }
    }

// the average-value die count: bloodstone 10, amber 6, onyx 10, turquoise 5,
// agate 5, aquamarine 5, garnet 1, jade 5, alexandrite 1, amethyst 1, topaz
// 1, jet 5, opal 1, ruby 1, sapphire 1, diamond 1, emerald 1.
inline int dnqtT34ValDice(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 6;
        case 2:
            return 10;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 5;
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

// the average-value die sides: 6, 100, 6, 6, 6, 6, 4, 6, 4, 6, 4, 6, 6, 8, 8,
// 6, 8 (amber 6d100 gp; the printed order is as pinned).
inline int dnqtT34ValSides(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 100;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 8;
        case 14:
            return 8;
        case 15:
            return 6;
        case 16:
            return 8;
        default:
            return -99;
        }
    }

}   // namespace rules
