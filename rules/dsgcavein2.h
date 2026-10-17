// =========================================================================================
// Adnd1 - rules/dsgcavein2.h
// The DSG CAVE-INS PART II, R512: the printed pp. 39-40 (pdf 40-41) - the
// chain reactions (even a small cave-in weakening supporting structures, the
// nearby ceilings and walls checked, the per-section d100 vs Table 18, the
// equal-or-less collapse at about the same area, the within-10% significant
// weakening, the forced adjacent checks with the tertiary chance half rounded
// up and each subsequent roll halved, the decayed exception keeping the
// original chance, the 9th-level druid transmute rock to mud example with the
// 31-vs-48 collapse, the 42-vs-24 hold, the side rolls 12/65/97/33, the
// secondary 1/2 and tertiary 1/4) and the effects (the falling distance and
// rough landing on top, the bridge along its unsupported length, the tunnel
// ceiling never wider than the tunnel, the random 20x20 roughly square base
// area, the chain checks per adjacent square radically increasing the size,
// the three-foot layer assumption with the two-foot example, the 4d8 per 10
// feet of thickness with the save vs petrification for half, the 30-foot 12d8
// example reduced to 6d8, the mud and silt at half with the save halving
// again, and the water at half with a save for 1/4, the first 10-foot
// thickness only, no weight damage, the drowning risk)
// census 436 -> 437.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read (idx 52 = printed p. 40) - every
// numeric cell dual-confirmed: the Table 18 grid confirmed THREE WAYS - the
// chapter djvu read (Ceiling 48%/32%, Wall 32%/12%, Ledge/bridge 5%/12%,
// Support Column 80%/4%), the compiled-tables appendix reprint (djvu.txt line
// 15559, the garble 4896 = 48%) and the Capture layer (the Support Column
// 80%/4% row and the example sequence) all agree; the djvu garble 648 = 6d8
// settled by the Capture 6d8 read; the djvu garble 114damage = 1/4 damage
// settled by the Capture 1/4 read; the djvu 112 and 114 halves/quarters read
// as 1/2 and 1/4. The example side roll 33 exceeds the 32% wall chance, so
// exactly one side continues. The Defensive Point Values section starts the
// NEXT round per the content-density rule.
//
// Table 18 pins as a 4x3 grid: the row key, the area-above percent and the
// area-next-to percent, each a d100 chance that collapses on an equal-or-less
// roll. The cascade divisors pin as exact integers (tertiary 2, subsequent 2,
// example secondary 2 and tertiary 4). The 4d8 damage pins as dice + sides
// consts per the R508 dsgbatt.h convention, with the 30-foot 12d8 example and
// its save-reduced 6d8. The R511 dsgcavein.h pins are the causes seam and
// nothing auto-credits.
//
namespace rules {

// ---- the chain reaction opener ----

// the force of gravity is constantly working destruction on underworld
// ceilings; even a small cave-in can so weaken supporting structures that a
// massive chain reaction of collapse begins immediately or threatens an area
// in the near future.
inline bool dnxSmallCaveInWeakensSupports()
    { return true; }

// when a cave-in occurs, the areas of nearby ceilings and walls must be
// checked to see if they weaken or collapse as a result of the original
// cave-in.
inline bool dnxAdjacentAreasMustBeChecked()
    { return true; }

// the DM rolls d100 and compares the result to Table 18: Cave-in Chain
// Reaction, rolling for each section of adjacent material, to determine the
// extent of the cave-in.
inline bool dnxDmRollsD100PerSection()
    { return true; }

// ---- the chain reaction reading ----

// a d100 result that is equal to or less than the number listed indicates
// that the adjacent area has also collapsed.
inline bool dnxEqualOrLessCollapses()
    { return true; }

// the area of a chain reaction collapse is about the same as that of the
// original cave-in.
inline bool dnxCollapseSameAreaAsOriginal()
    { return true; }

// if the die roll does not indicate a collapse but is within 10% of the
// chance listed, the area is significantly weakened and might collapse at any
// moment.
inline int dnxWeakenedWithinPct()
    { return 10; }

// a significantly weakened area, missed by the chain reaction roll by less
// than the weakened band, might collapse at any moment.
inline bool dnxWeakenedMayCollapseAnyMoment()
    { return true; }

// areas that collapse as a result of a chain reaction force checks for chain
// reaction collapses in all adjacent areas.
inline bool dnxChainCollapseForcesMoreChecks()
    { return true; }

// the percentage chance for a tertiary collapse is half the chance for the
// original chain reaction cave-in.
inline int dnxTertiaryChanceDiv()
    { return 2; }

// the halved tertiary chance is rounded up.
inline bool dnxTertiaryRoundedUp()
    { return true; }

// if the chain reaction continues, each subsequent roll is made with 1/2 the
// chance of the chain reaction roll that forced it.
inline bool dnxEachSubsequentRollHalved()
    { return true; }

// the divisor applied to the forcing roll chance for each subsequent chain
// reaction roll.
inline int dnxSubsequentRollDiv()
    { return 2; }

// ---- the decayed exception ----

// if an area is exceptionally weak and decayed, the DM may ignore the
// declining chance of a chain reaction cave-in and use the original cave-in
// chance for all subsequent rolls.
inline bool dnxDecayedIgnoresDecline()
    { return true; }

// the decayed exception is common in areas heavily eroded by water or other
// natural forces, or constructed long ago and left to fall into ruin.
inline bool dnxDecayedErodedOrAncient()
    { return true; }

// ---- the chain reaction example ----

// the example caster is a 9th-level druid using transmute rock to mud on a
// stone ceiling.
inline int dnxExampleDruidLevel()
    { return 9; }

// the spell affects an area of rock 100 feet long.
inline int dnxExampleSpellLengthFt()
    { return 100; }

// the spell area is 80 feet wide.
inline int dnxExampleSpellWidthFt()
    { return 80; }

// the spell area is 10 feet thick, and all the stone in it converts to mud
// and falls.
inline int dnxExampleSpellThickFt()
    { return 10; }

// the d100 roll for the area immediately above the mud ceiling is a 31,
// indicating another layer of rock falls on top of the mud.
inline int dnxExampleAboveRoll()
    { return 31; }

// the example roll of 31 against the 48% ceiling chain reaction chance means
// the area above also collapses.
inline bool dnxExampleAboveCollapses()
    { return true; }

// the triggered roll for the rock on top of the stone that just fell is made
// at 1/2 the original probability, or 24.
inline int dnxExampleAboveSecondChance()
    { return 24; }

// the next roll is a 42, greater than the 24 needed, so the second layer
// above does not collapse.
inline int dnxExampleAboveSecondRoll()
    { return 42; }

// the example second layer above the original collapse does not collapse.
inline bool dnxExampleSecondLayerHolds()
    { return true; }

// the first of the four d100 rolls checking the sides of the spell area for a
// chain reaction.
inline int dnxExampleSideRoll1()
    { return 12; }

// the second side roll.
inline int dnxExampleSideRoll2()
    { return 65; }

// the third side roll.
inline int dnxExampleSideRoll3()
    { return 97; }

// the fourth side roll.
inline int dnxExampleSideRoll4()
    { return 33; }

// only one of the four sides of the spell area continues to collapse.
inline bool dnxExampleOneSideContinues()
    { return true; }

// the secondary collapse forces additional checks for the area immediately
// above it and for the areas to the three sides that have not already
// collapsed.
inline bool dnxExampleSecondaryChecksRequired()
    { return true; }

// the secondary checks have only 1/2 the chance listed on the chain reaction
// table, since the cave-in triggering them was itself a chain reaction.
inline int dnxExampleSecondaryDiv()
    { return 2; }

// a collapse triggered by a secondary check causes tertiary checks with only
// 1/4 the chance listed.
inline int dnxExampleTertiaryDiv()
    { return 4; }

// ---- the cave-in base area ----

// the effect of a cave-in upon characters and creatures in the area depends
// on where they are and the amount of rock that is falling.
inline bool dnxEffectDependsOnPositionAndRock()
    { return true; }

// if characters are on top of something that collapses, consider the distance
// fallen and treat the landing surface as rough, per the expanded falling
// rules (page 19).
inline bool dnxOnTopUseFallingRules()
    { return true; }

// the base area of a cave-in can often be determined by the structure or
// surface that is collapsing.
inline bool dnxBaseAreaFromStructure()
    { return true; }

// a bridge that collapses will collapse along its entire unsupported length.
inline bool dnxBridgeFallsUnsupportedLength()
    { return true; }

// a tunnel ceiling collapse can never be wider than the tunnel itself.
inline bool dnxTunnelCeilingNeverWider()
    { return true; }

// where the size of the cave-in must be determined randomly, such as the
// ceiling of a vast chamber, assume the base cave-in occurs in an area of 20
// feet by 20 feet.
inline int dnxBaseAreaFtX()
    { return 20; }

// the other side of the assumed base area: 20 feet.
inline int dnxBaseAreaFtY()
    { return 20; }

// the randomly determined base cave-in area is roughly square in shape.
inline bool dnxBaseAreaRoughlySquare()
    { return true; }

// chain reactions must be checked for each adjacent square area, as well as
// in the ceiling directly above the rock that has caved in.
inline bool dnxChainCheckedPerAdjacentSquare()
    { return true; }

// chain reactions radically increase the total size of a cave-in.
inline bool dnxChainRadicallyIncreasesSize()
    { return true; }

// ---- the falling layer ----

// if a layer of rock falls from a ceiling or wall, assume that the layer is
// three feet thick unless other considerations apply.
inline int dnxLayerThickFtDefault()
    { return 3; }

// the three-foot layer assumption yields to other considerations when they
// apply.
inline bool dnxLayerThickUnlessOtherwise()
    { return true; }

// a two-foot-thick layer of stone serving as a ceiling in one chamber and a
// floor in the one above is never more than two feet thick when it collapses.
inline bool dnxThinFloorLayerExample()
    { return true; }

// the example thin layer: two feet of stone.
inline int dnxFloorLayerExampleFt()
    { return 2; }

// if a three-foot-thick section of collapsing rock leaves additional stone
// above it, that stone should be checked for a chain reaction cave-in.
inline bool dnxThreeFtLeavesStoneCheckChain()
    { return true; }

// ---- the falling damage ----

// characters beneath an area of rock that collapses take an average base
// damage of 4d8 per character per 10 feet (or less) of thickness of fallen
// rock.
inline int dnxFallingDamageDice()
    { return 4; }

// the falling rock damage die: d8.
inline int dnxFallingDamageSides()
    { return 8; }

// the damage reckoning unit: 10 feet of thickness, or less, per 4d8 of
// damage.
inline int dnxDamagePerThicknessFt()
    { return 10; }

// characters beneath a collapse are allowed a saving throw vs. petrification
// for half damage.
inline bool dnxSavePetrificationHalf()
    { return true; }

// the worked example: a 30-foot thickness of rock crashing down on characters
// in a cavern.
inline int dnxExampleThicknessFt()
    { return 30; }

// the 30-foot example thickness inflicts 12d8 points of damage on each
// character.
inline int dnxExampleDamageDice()
    { return 12; }

// the example saving throw vs. petrification reduces the 12d8 to 6d8 (the
// djvu garble 648, settled by the Acrobat layer read of 6d8).
inline int dnxExampleSaveDice()
    { return 6; }

// ---- the mud and water damage ----

// if the falling material is mud, silt, or any other sludgy substance, the
// damage inflicted on characters below is only half that caused by falling
// rock.
inline bool dnxMudHalfRockDamage()
    { return true; }

// the mud/silt divisor: half of falling rock damage.
inline int dnxMudDamageDiv()
    { return 2; }

// characters beneath falling mud or silt are also entitled to a saving throw
// vs. petrification, which if successful halves this damage again.
inline bool dnxMudSaveHalvesAgain()
    { return true; }

// falling water inflicts 1/2 of the normal damage.
inline bool dnxWaterHalfRockDamage()
    { return true; }

// the falling water divisor: half of normal damage.
inline int dnxWaterDamageDiv()
    { return 2; }

// falling water allows a save for 1/4 damage (the djvu garble 114damage =
// 1/4, settled by the Acrobat layer).
inline int dnxWaterSaveDiv()
    { return 4; }

// in the case of water the damage is inflicted for the first 10-foot
// thickness of falling material only.
inline int dnxWaterChargedThicknessFt()
    { return 10; }

// even if the character remains under a column of pouring water, he does not
// sustain additional damage from the weight of the water.
inline bool dnxWaterNoWeightDamage()
    { return true; }

// a character under a column of pouring water is quite possibly unable to
// breathe and needs to escape the water or drown.
inline bool dnxWaterColumnDrowningRisk()
    { return true; }

// ---- the Table 18 chain grid ----

// the Table 18 carries four original-location rows: ceiling, wall, ledge or
// bridge, and support column.
inline int dnxT18RowCount()
    { return 4; }

// the row key: 0 a ceiling, 1 a wall, 2 a ledge or bridge, 3 a support
// column.
inline int dnxT18Loc(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return -99;
        }
    }

// the percent chance that the area above the original cave-in also collapses
// on a d100 roll equal to or less than this number.
inline int dnxT18Above(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 32;
        case 2:
            return 5;
        case 3:
            return 80;
        default:
            return -99;
        }
    }

// the percent chance that the area next to the original cave-in also
// collapses on a d100 roll equal to or less than this number.
inline int dnxT18Next(int b)
    {
        switch (b) {
        case 0:
            return 32;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

}   // namespace rules
