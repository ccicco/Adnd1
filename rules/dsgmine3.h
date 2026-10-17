// =========================================================================================
// Adnd1 - rules/dsgmine3.h
// The DSG MINING PRODUCTS OF A MINE, R521: printed p. 50 (pdf 51) - the
// products rules: when a miner successfully locates minerals the player rolls
// 1d100 on Table 30 Mining Products (the nine bands - copper 01-30, tin
// 31-40, lead 41-66, iron 67-84, silver 85-92, gold 93-97, platinum 98,
// mithril 99, gemstones 00), the mithril possibility (the material needed for
// elven chain mail, a mithril mine only deep under the earth in the most
// solid of bedrock - if the locale qualifies the player rolls 1d10 on Table
// 31 Mithril Check, otherwise reroll on Table 30; Table 31 gives silver, gold
// and platinum at highest quality on 1-5/6-8/9 and mithril on 10), and the
// gemstone determination on Table 32 (sixteen stone types in d100 bands from
// bloodstone 01-08 and onyx 09-18 through emerald 93-96, with 97-99 rolling
// twice and 00 rolling three times - the 97-or-greater result grants its
// additional rolls immediately and any additional 97+ grants them again with
// no limit, a duplicated substance is noted as Jade x2 and yields twice the
// usual amount, and one quality level applies to all stones of a single type
// in a mine)
// census 444 -> 445.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~6588-6650) with the pdf Acrobat-Capture layer as the second read (idx
// 119-121 = printed pp. 49-51 window) and the compiled-tables appendix
// reprint as the third read. THE BLOODSTONE READ: the Table 32 01-08 row is
// the garble of the round - the djvu drops the row entirely (the table jumps
// from the header to 09-18 onyx), the Capture layer renders it as a "-1/^^"
// fragment, and the appendix reprint drops it too; all three machine reads
// fail the row, and it was settled as BLOODSTONE (01-08) by Curtiss reading
// the physical printed page 50 - the physical read outranks the scan.
// Everything else multi-confirms: the Table 30 nine bands (djvu clean,
// Capture corroborating iron 67-84 through gold 93-97, the appendix reprint
// corroborating the full ladder), the Table 31 four bands (djvu, Capture and
// appendix all agree on 1-5/6-8/9/10 with the highest-quality
// silver/gold/platinum), and the Table 32 bands from 09-18 onyx through 00
// (djvu and Capture agree; the appendix adds the 55-60 amethyst row the
// chapter djvu dropped). The 1d10 mithril check pins as dice + sides consts
// per the R508 convention (the djvu "1410" and Capture "ldlO" garbles both
// read as 1d10). The 00 band pins as roll 100. The Tables 33-34 quality grids
// start the NEXT round per the content-density rule.
//
// Three tables pin: Table 30 as a 9x2 d100 band grid (the 00 gemstones band
// pinned as roll 100), Table 31 as a 4x2 d10 band grid, and Table 32 as an
// 18x2 d100 band grid (sixteen stone types plus the roll-twice and
// roll-three-times bands, the 00 band as 100). The 1d100 products roll and
// the 1d10 mithril check pin as dice + sides consts per the R508 convention.
// The 97-or-greater extra-roll threshold pins as a const; the unlimited
// recursion, the duplicate doubling and the one-quality-per-type rules pin as
// prose bools. The 01-08 bloodstone row pins from the physical book read (the
// standing physical-outranks-scan lesson). The R518/R520 seams (DMG 106
// rates, DSG 53 duration) are noted; nothing auto-credits.
//
namespace rules {

// ---- the Table 30 mining products ----

// when a miner successfully locates minerals, the player rolls 1d100 and
// finds the result on Table 30: Mining Products.
inline bool dnprRollT30OnLocatingMinerals()
    { return true; }

// the products roll is one die.
inline int dnprT30Dice()
    { return 1; }

// the products roll is 1d100 when a miner successfully locates minerals.
inline int dnprT30Sides()
    { return 100; }

// the Table 30 mining products grid carries nine d100 bands (the 00 gemstones
// band pinned as roll 100).
inline int dnprT30RowCount()
    { return 9; }

// the product band low roll: 0 copper 01-30, 1 tin 31-40, 2 lead 41-66, 3
// iron 67-84, 4 silver 85-92, 5 gold 93-97, 6 platinum 98, 7 mithril 99 (the
// elven-chain material, check Table 31 in deep solid bedrock, else reroll
// here), 8 gemstones 00 (roll on Table 32).
inline int dnprT30Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 41;
        case 3:
            return 67;
        case 4:
            return 85;
        case 5:
            return 93;
        case 6:
            return 98;
        case 7:
            return 99;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// the product band high roll: 30, 40, 66, 84, 92, 97, 98, 99, 100 (the 00
// band pinned as 100).
inline int dnprT30Hi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 66;
        case 3:
            return 84;
        case 4:
            return 92;
        case 5:
            return 97;
        case 6:
            return 98;
        case 7:
            return 99;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// ---- the mithril check ----

// the Table 30 mithril entry is the possibility of mithril, the material
// needed to create elven chain mail.
inline bool dnprMithrilForElvenChainMail()
    { return true; }

// a mithril mine can only exist deep under the earth in the most solid of
// bedrock.
inline bool dnprMithrilOnlyDeepSolidBedrock()
    { return true; }

// if the locale of the mine is in such an area, the player rolls 1d10 against
// Table 31: Mithril Check; otherwise, reroll on the Mining Products table.
inline bool dnprMithrilElseRerollT30()
    { return true; }

// the Table 31 silver, gold and platinum results are the highest quality of
// their metal.
inline bool dnprT31MetalsHighestQuality()
    { return true; }

// the mithril check roll is one die.
inline int dnprMithrilCheckDice()
    { return 1; }

// the mithril check roll is 1d10 compared to Table 31 (the djvu "1410" and
// Capture "ldlO" garbles both read as 1d10).
inline int dnprMithrilCheckSides()
    { return 10; }

// the Table 31 mithril check grid carries the four d10 bands.
inline int dnprT31RowCount()
    { return 4; }

// the mithril check band low roll: 0 silver (highest quality) 1-5, 1 gold
// (highest quality) 6-8, 2 platinum (highest quality) 9, 3 mithril 10.
inline int dnprT31Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 10;
        default:
            return -99;
        }
    }

// the mithril check band high roll: 5, 8, 9, 10.
inline int dnprT31Hi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 10;
        default:
            return -99;
        }
    }

// ---- the Table 32 gemstones ----

// the Table 32 gemstones grid carries eighteen d100 bands (sixteen stone
// types plus the roll-twice and roll-three-times bands).
inline int dnprT32RowCount()
    { return 18; }

// a roll of 97 or greater on Table 32 immediately grants the additional rolls
// indicated.
inline int dnprT32ExtraRollThreshold()
    { return 97; }

// if a 97 or greater is rolled on Table 32, the player immediately makes the
// additional rolls indicated.
inline bool dnprT32ExtraRollsImmediate()
    { return true; }

// any additional roll that again yields 97 or better grants its additional
// rolls - there is no limit to the number of rolls possible.
inline bool dnprT32ExtraRollsNoLimit()
    { return true; }

// a result yielding the same substance twice is noted (e.g., Jade x2) - the
// mine yields twice the usual amount of that mineral.
inline bool dnprT32DuplicateDoublesYield()
    { return true; }

// the same level of quality applies to all of a single type of stone found in
// a mine.
inline bool dnprT32OneQualityPerType()
    { return true; }

// the gemstone band low roll: 0 bloodstone 01-08, 1 onyx 09-18, 2 turquoise
// 19-24, 3 agate 25-30, 4 aquamarine 31-36, 5 garnet 37-42, 6 jade 43-48, 7
// alexandrite 49-54, 8 amethyst 55-60, 9 topaz 61-66, 10 jet 67-72, 11 opal
// 73-77, 12 ruby 78-82, 13 sapphire 83-87, 14 diamond 88-92, 15 emerald
// 93-96, 16 roll twice 97-99, 17 roll three times 00.
inline int dnprT32Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 9;
        case 2:
            return 19;
        case 3:
            return 25;
        case 4:
            return 31;
        case 5:
            return 37;
        case 6:
            return 43;
        case 7:
            return 49;
        case 8:
            return 55;
        case 9:
            return 61;
        case 10:
            return 67;
        case 11:
            return 73;
        case 12:
            return 78;
        case 13:
            return 83;
        case 14:
            return 88;
        case 15:
            return 93;
        case 16:
            return 97;
        case 17:
            return 100;
        default:
            return -99;
        }
    }

// the gemstone band high roll: 8, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 77,
// 82, 87, 92, 96, 99, 100 (the 00 band pinned as 100).
inline int dnprT32Hi(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 18;
        case 2:
            return 24;
        case 3:
            return 30;
        case 4:
            return 36;
        case 5:
            return 42;
        case 6:
            return 48;
        case 7:
            return 54;
        case 8:
            return 60;
        case 9:
            return 66;
        case 10:
            return 72;
        case 11:
            return 77;
        case 12:
            return 82;
        case 13:
            return 87;
        case 14:
            return 92;
        case 15:
            return 96;
        case 16:
            return 99;
        case 17:
            return 100;
        default:
            return -99;
        }
    }

}   // namespace rules
