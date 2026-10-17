// =========================================================================================
// Adnd1 - rules/dsgmine2.h
// The DSG MINING EXCAVATION, VEINS AND SHORING, R520: printed pp. 49-50 (pdf
// 50-51) - the excavation rules (the hard and slow necessity of tunneling,
// the Table 27 rates grid reprinted from DMG page 106 in cubic feet per miner
// per eight hours across very soft, soft and hard rock - the eight races from
// gnoll/halfling/human 75/50/25 through gnome/kobold 80/60/30, goblin/orc
// 85/65/30, dwarf/hobgoblin 90/70/35, ogre 150/100/50, hill giant 250/150/75
// and fire/frost giant 300/200/100 to stone giant 500/350/175), the per-race
// 10-foot-tunnel miner maxima (the small races 16, man-sized 12, gnoll 8,
// ogre 6, giant 4), the vein rules (the 10x10 tunnel following the shifting
// vein, the 1d6 x 10-feet depth to intersect the vein, the 1d4 direction roll
// on Table 28 - north-south, east-west, northeast-southwest,
// northwest-southeast - the at-least-20-feet run, the secret 1d8 alteration
// roll per 20-foot section on Table 29 - steep descent, shallow descent,
// curves right and left at 10-60 degrees, the 5-6 continues straight, shallow
// ascent, steep ascent - the must-follow rule, the impossible-course run-out
// with the other-direction freedom, the both-ends stop taking priority over
// the Duration of A Mining Site rules, and the gorge pickup at DM
// discretion), and the shoring rules (the wooden or stone support pillars
// against the almost-certain cave-in, the carpenter, stonemason and miner
// proficiencies, the two side braces plus a ceiling brace per 10-foot
// section, the 30 feet of at-least-one-foot-diameter bracing in the standard
// 10x10 tunnel, the four man-hours per set, and the 18/50-strength
// solo-moving threshold with the manpower or animal alternative)
// census 443 -> 444.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~6465-6560) with the pdf Acrobat-Capture layer as the second read (idx 67 =
// printed p. 50) and the compiled-tables appendix reprint as the third read -
// every numeric cell multi-confirmed: the Table 27 grid (chapter djvu clean,
// the Capture window corroborating 90/70/35, 150/100/50 and 250/150/75, the
// appendix reprint corroborating 75/50, 80/60, 85/65, 90/70 and the ogre/hill
// giant rows; the fire/frost 300/200/100 and stone giant 500/350/175 rows
// read from the clean chapter djvu against the DMG page 106 reprint origin),
// the miner maxima 16/12/8/6/4 (chapter + Capture agree), the 1d6 x 10-feet
// vein depth, the 1d4 direction, the 20-foot sections, and the shoring
// numbers 2/1/30/1/4 man-hours with the 18/50 threshold. THE DJVU D6 GARBLE:
// the Table 29 header reads D6 Roll but lists eight results; both the chapter
// and the appendix reprint list the same eight rows and the secret roll is
// 1d8 - settled as a d8 table with the 5-6 band as one row. The DMG page 106
// seam, the DSG page 53 duration seam and the R511 cave-in seam are noted.
// The Products of a Mine grids (Tables 30-32) start the NEXT round per the
// content-density rule.
//
// Three tables pin: Table 27 as an 8x3 rates grid (very soft, soft, hard),
// Table 28 as a 4x2 d4 direction grid (each direction a single face, lo =
// hi), and Table 29 as a 7x2 d8 band grid (the 5-6 continues-straight band
// pinning as one row per the R518 pin-as-printed lesson). The vein depth pins
// as dice + sides consts with the 10-feet multiplier separate per the R508
// convention; the 1d8 alteration roll pins the same way with the D6-header
// garble settled by the appendix reprint. The 18/50 strength threshold pins
// as a prose bool, not a computed comparison. The DMG 106, DSG 53 and R511
// seams are noted; nothing auto-credits.
//
namespace rules {

// ---- the Table 27 excavation grid ----

// excavating a tunnel is hard and time-consuming, but is necessary to remove
// the mineral wealth of the underdark.
inline bool dnfExcavatingHardAndSlow()
    { return true; }

// the Table 27 excavation rates are reprinted from page 106 of the DMG (the
// cross-book seam).
inline bool dnfRatesReprintedFromDmg106()
    { return true; }

// the excavation rates are given in cubic feet per miner per eight-hour
// period.
inline bool dnfRatesPerMinerPerEightHours()
    { return true; }

// the Table 27 mining rates grid carries eight races of miner.
inline int dnfT27RowCount()
    { return 8; }

// the very soft rock rate in cubic feet per miner per eight hours: 0
// gnoll/halfling/human 75, 1 gnome/kobold 80, 2 goblin/orc 85, 3
// dwarf/hobgoblin 90, 4 ogre 150, 5 hill giant 250, 6 fire giant/frost giant
// 300, 7 stone giant 500.
inline int dnfT27VerySoft(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 80;
        case 2:
            return 85;
        case 3:
            return 90;
        case 4:
            return 150;
        case 5:
            return 250;
        case 6:
            return 300;
        case 7:
            return 500;
        default:
            return -99;
        }
    }

// the soft rock rate: 50, 60, 65, 70, 100, 150, 200, 350.
inline int dnfT27Soft(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 65;
        case 3:
            return 70;
        case 4:
            return 100;
        case 5:
            return 150;
        case 6:
            return 200;
        case 7:
            return 350;
        default:
            return -99;
        }
    }

// the hard rock rate: 25, 30, 30, 35, 50, 75, 100, 175.
inline int dnfT27Hard(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 30;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 50;
        case 5:
            return 75;
        case 6:
            return 100;
        case 7:
            return 175;
        default:
            return -99;
        }
    }

// ---- the tunnel miner maxima ----

// the maximum number of miners that can work in a 10-foot-wide tunnel depends
// on race.
inline bool dnfMaxMinersDependsOnRace()
    { return true; }

// the maximum number of miners that can work in a 10-foot-wide tunnel: dwarf,
// gnome, goblin, halfling and kobold 16.
inline int dnfMaxMinersSmall()
    { return 16; }

// hobgoblin, human and orc 12.
inline int dnfMaxMinersMan()
    { return 12; }

// gnoll 8.
inline int dnfMaxMinersGnoll()
    { return 8; }

// ogre 6.
inline int dnfMaxMinersOgre()
    { return 6; }

// giant (any) 4.
inline int dnfMaxMinersGiant()
    { return 4; }

// ---- the vein depth and direction ----

// a mine tunnel must follow the shifting vein of a mineral through the earth.
inline bool dnfTunnelFollowsShiftingVein()
    { return true; }

// a mine tunnel path typically requires a 10-foot-wide tunnel.
inline int dnfTunnelWidthFt()
    { return 10; }

// the typical 10-foot-wide by 10-foot-high tunnel.
inline int dnfTunnelHeightFt()
    { return 10; }

// when a miner first discovers a mineral vein, roll 1d6; the tunnel must be
// dug down to intersect the vein.
inline int dnfVeinDepthDice()
    { return 1; }

// the sides of the 1d6 vein-depth roll, pinned as dice + sides consts per the
// R508 convention.
inline int dnfVeinDepthSides()
    { return 6; }

// multiply the 1d6 result by 10; this is how far down (in feet) the tunnel
// must be dug to intersect the mineral vein.
inline int dnfVeinDepthMultFt()
    { return 10; }

// once the vein is discovered, to determine the path of the vein roll 1d4,
// with the result indicating the direction on Table 28.
inline bool dnfDirectionRollIsD4()
    { return true; }

// the Table 28 vein direction grid carries the four d4 directions.
inline int dnfT28RowCount()
    { return 4; }

// the low end of the d4 direction roll: 0 north-south at 1, 1 east-west at 2,
// 2 northeast-southwest at 3, 3 northwest-southeast at 4.
inline int dnfT28Lo(int b)
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
        default:
            return -99;
        }
    }

// the high end of the d4 direction roll (each direction is a single face).
inline int dnfT28Hi(int b)
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
        default:
            return -99;
        }
    }

// ---- the Table 29 path alterations ----

// the vein always runs at least 20 feet in the indicated direction before the
// next secret alteration roll.
inline bool dnfVeinRunsAtLeastSection()
    { return true; }

// the vein always runs at least 20 feet in the direction indicated; after
// each 20-foot section of tunnel is excavated the DM secretly rolls 1d8 for
// the path.
inline int dnfVeinSectionFt()
    { return 20; }

// the 1d8 alteration roll is made secretly by the DM after each 20-foot
// section.
inline bool dnfAlterationRollIsSecret()
    { return true; }

// the secret per-section vein alteration roll is 1d8, read on Table 29.
inline int dnfVeinAlterationDice()
    { return 1; }

// the sides of the 1d8 alteration roll (the djvu table header garbles D6;
// both the chapter and the appendix reprint list eight rows, settled as D8).
inline int dnfVeinAlterationSides()
    { return 8; }

// the Table 29 vein path alterations grid carries seven bands over the eight
// d8 results (the 5-6 continues-straight band is one row).
inline int dnfT29RowCount()
    { return 7; }

// the low end of the secret d8 alteration roll: 0 steep descent at 1, 1
// shallow descent at 2, 2 curves right (10-60 degrees) at 3, 3 curves left
// (10-60 degrees) at 4, 4 continues straight at 5, 5 shallow ascent at 7, 6
// steep ascent at 8.
inline int dnfT29Lo(int b)
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
            return 7;
        case 6:
            return 8;
        default:
            return -99;
        }
    }

// the high end of the d8 band, the 5-6 continues-straight band pinning as one
// row.
inline int dnfT29Hi(int b)
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
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        default:
            return -99;
        }
    }

// ---- the vein-following rules ----

// miners who wish to continue working the mine must follow the vein, even if
// it goes in a direction they would rather not follow.
inline bool dnfMustFollowUnwantedDirection()
    { return true; }

// if the vein path becomes impossible to follow, such as emerging into thin
// air through a sheer cliff face, that course of the mine has run out -
// though the miners are free to follow the vein in the other direction.
inline bool dnfImpossibleCourseRunsOut()
    { return true; }

// if both directions of a vein end, the mine provides no more minerals; this
// rule takes priority over the Duration of A Mining Site rules (the DSG page
// 53 seam).
inline bool dnfBothEndsStopsMine()
    { return true; }

// in unusual circumstances, such as a vein ending in a cliff with a facing
// cliff across a narrow gorge, characters may attempt to pick up the vein
// again across the gorge; the success is left to the DM’s discretion,
// generally a determined probability and a die roll.
inline bool dnfGorgePickupAtDiscretion()
    { return true; }

// ---- the shoring rules ----

// a tunnel mine must be regularly protected with wooden or stone support
// pillars, called shoring, or else sections of the tunnel will almost
// certainly cave in (the R511 cave-in seam).
inline bool dnfShoringOrCaveIn()
    { return true; }

// shoring can be accomplished by characters with carpenter, stonemason, or
// miner proficiencies.
inline bool dnfShoringProficiencies()
    { return true; }

// each 10-foot section of tunnel requires two side braces and a ceiling
// brace.
inline int dnfShoringSideBraces()
    { return 2; }

// the single ceiling brace of each shoring set.
inline int dnfShoringCeilingBraces()
    { return 1; }

// in the standard 10-wide by 10-high tunnel the shoring set takes 30 feet of
// bracing that is at least one foot in diameter.
inline int dnfShoringBracingFt()
    { return 30; }

// the minimum one-foot diameter of the shoring braces.
inline int dnfShoringDiameterFt()
    { return 1; }

// each set of shoring supports takes four man-hours to construct.
inline int dnfShoringManHours()
    { return 4; }

// unless the character doing the shoring is extremely strong (18/50 or
// greater strength), moving the braces into the mine requires additional
// manpower or animal help.
inline bool dnfStrongSoloMoving()
    { return true; }

}   // namespace rules
