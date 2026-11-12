    // ---- R893 systems audit ----
    // THE SYSTEMS ROUND - Round D of issue 2, two systems on the variant
    // layer. THE WEAPON DAMAGE OPTION (Pickens, folio 30): the expertise
    // cadence - a weapon per 3 Fighter levels or 4 Thief levels, the Thief
    // limited to sword, dagger, their combination, or the sling; the
    // two-weapon combination at dex 13, shielded, no expertise bonus, one
    // Flail or Morning Star at most, the hard pairs at dex 16; the 2-Handed
    // Sword at Strength 16 and dex 9, the one-handed Pick or Battle Axe; and
    // the seventeen-weapon grid, Dagger 1-4 / 2-5 through the Mounted Lance
    // 2-12 / 2-24, with the space column carrying the footnotes - 4, 5 and 6
    // feet for the starred, the not-useable-in-dungeons length rule noted
    // here in prose. THE MONKISH PROMOTION COMBAT (Seaton, folios 4-5): the
    // DPT frame - strength x constitution + 10 x level; the DPG - strength +
    // dexterity + half intelligence; the 10-set turn, the 6-unit set; the
    // three-quarters DPT half-strength line; the five-eighths roll of
    // dexterity for order changes and the return blow, pinned as scanned; the
    // kick rules, the sweep that downs for three units at normal damage, the
    // grab that tells for three units; the recovery ladder - light at 10 DPT,
    // serious at 50, the wish at 150, natural days at half the DPT lost; no
    // challenge to a recovering monk. THE MATRIX (folio 5): the full
    // strike-block-kick grid as printed, CONVERTED to integers - 0 normal, 1
    // blocked, 2 double, 3 triple, 4 sweep, 5 grab, 6 not applicable - the
    // legend pinned beside the grid, the conversion noted, never silent.
    // HONEST BOUNDARIES: the option replaces the Greyhawk damage system only
    // as a noted variant - the engine's canon damage tables are untouched;
    // the arena is a written-orders minisystem for monk advancement, never
    // core canon; the ceremonial prose (the bows, the arena) rides the
    // provenance. The Fischer box flips this round - the issue-2 report's
    // third flip, 3 closed / 1 open, the systems box closing at the NEXT
    // Dragon round per the R796 pre-flip rule.
    {
        using namespace rules;
        int bad = 0;
    if (sysFighterLevelsPerWeapon() != 3
            || sysThiefLevelsPerWeapon() != 4
            || sysThiefWeaponCount() != 4
            || sysTwoWeaponDexMin() != 13
            || sysHardComboDexMin() != 16
            || sysTwoHandedStrMin() != 16
            || sysTwoHandedDexMin() != 9
            || sysOneHandStrMin() != 16
            || sysOneHandDexMin() != 9
            || sysWeaponRows() != 17
            || sysDptLevelMult() != 10
            || sysDpgIntDiv() != 2
            || sysSetsPerTurn() != 10
            || sysUnitsPerSet() != 6
            || sysHalfStrengthPct() != 75
            || sysHalfStrengthDiv() != 2
            || sysChangeRollNum() != 5
            || sysChangeRollDen() != 8
            || sysKickRowMax() != 3
            || sysKickHandBlocksMax() != 2
            || sysJumpLegs() != 1
            || sysSweepDownUnits() != 3
            || sysStampAfterSweep() != 0
            || sysGrabUnits() != 3
            || sysLightWoundDpt() != 10
            || sysSeriousWoundDpt() != 50
            || sysWishDpt() != 150
            || sysNaturalRecoveryDiv() != 2
            || sysMatrixRows() != 8
            || !sysTwoWeaponShielded()
            || !sysNoExpertiseInCombo()
            || !sysOneFlailMorningStar()
            || !sysKickArmLength()
            || !sysStrikeArmLength()
            || !sysXBlockTwoHanded()
            || !sysStrikeFeetGrounded()
            || !sysHandsSplit()
            || !sysRestEachSet()
            || !sysFirstStrikeHighDpt()
            || !sysReturnBlowRoll()
            || !sysConcedeStops()
            || !sysDuckHighMiddle()
            || !sysNoChallengeWhileRecovering()
        )
            ++bad;
        // the seventeen-weapon grid, Normal vs Expert with the space
        // requirements - the footnotes ride the space column, the
        // not-useable-in-dungeons length rule noted in the audit prose (folio
        // 30)
        int CSysWpn[17][5] = {
            {1,4,2,5,0},
            {1,4,1,6,0},
            {1,6,1,6,4},
            {1,8,1,12,4},
            {1,8,1,10,0},
            {1,8,1,10,6},
            {1,6,1,8,5},
            {1,6,2,8,0},
            {1,8,2,12,0},
            {1,10,2,16,0},
            {1,12,1,12,6},
            {1,10,2,12,6},
            {2,12,3,18,6},
            {2,12,2,24,0},
            {1,12,1,12,6},
            {1,6,1,6,0},
            {1,4,1,6,0},
            };
        for (int b = 0;
             b < sysWeaponRows();
             ++b) {
            int vals[5];
            vals[0] = sysWpnNormMin(b);
            vals[1] = sysWpnNormMax(b);
            vals[2] = sysWpnExpMin(b);
            vals[3] = sysWpnExpMax(b);
            vals[4] = sysWpnSpace(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CSysWpn[b][c])
                    ++bad;
            }
        }
        // the strike-block-kick matrix as printed on folio 5, CONVERTED to
        // integers - 0 normal DPG, 1 blocked no effect, 2 double DPG, 3
        // triple DPG, 4 sweep succeeds, 5 grab, 6 not applicable; the grab
        // rows read: the next three units all tell at normal value while the
        // opponent cannot count strikes until the third unit, the blows
        // blockable; the sweep rows read: the opponent is on the ground
        int CSysMx[8][18] = {
            {2,1,1,2,1,0,1,1,2,1,0,2,1,1,1,1,1,1},
            {1,0,2,5,2,0,1,1,2,1,2,0,0,1,1,1,1,1},
            {0,1,2,5,2,0,0,1,3,0,1,0,0,1,1,1,1,1},
            {2,1,0,2,5,0,0,1,1,2,1,1,1,1,1,3,0,0},
            {5,0,3,5,2,2,5,1,1,1,1,1,1,2,1,3,1,1},
            {2,5,0,3,1,1,0,1,1,1,1,1,1,2,2,1,2,1},
            {4,1,1,4,1,4,1,1,4,4,1,1,1,1,4,1,1,1},
            {0,0,2,5,5,0,3,6,6,6,0,0,0,0,0,0,2,0},
            };
        for (int b = 0;
             b < sysMatrixRows();
             ++b) {
            int vals[18];
            vals[0] = sysVsHB(b);
            vals[1] = sysVsMB(b);
            vals[2] = sysVsLB(b);
            vals[3] = sysVsXBH(b);
            vals[4] = sysVsXBL(b);
            vals[5] = sysVsKB(b);
            vals[6] = sysVsR(b);
            vals[7] = sysVsJB(b);
            vals[8] = sysVsJF(b);
            vals[9] = sysVsD(b);
            vals[10] = sysVsRP(b);
            vals[11] = sysVsBF(b);
            vals[12] = sysVsKH(b);
            vals[13] = sysVsFK(b);
            vals[14] = sysVsHK(b);
            vals[15] = sysVsSK(b);
            vals[16] = sysVsSW(b);
            vals[17] = sysVsST(b);
            for (int c = 0; c < 18;
                 ++c) {
                if (vals[c] != CSysMx[b][c])
                    ++bad;
            }
        }
        // the mastery cadence - a weapon per 3 Fighter levels, per 4 Thief
        // levels (folio 30)
    if (sysFighterLevelsPerWeapon() != 3
            || sysThiefLevelsPerWeapon() != 4
        )
            ++bad;
        // the Thief's four expertise choices (folio 30)
    if (sysThiefWeaponCount() != 4
        )
            ++bad;
        // the combination gates - dex 13 for two weapons, 16 for the hard
        // pairs (folio 30)
    if (sysTwoWeaponDexMin() != 13
            || sysHardComboDexMin() != 16
        )
            ++bad;
        // the 2-Handed Sword's Strength 16 / dex 9, and the one-handed pick
        // or axe (folio 30)
    if (sysTwoHandedStrMin() != 16
            || sysTwoHandedDexMin() != 9
            || sysOneHandStrMin() != 16
        )
            ++bad;
        // the Dagger - 1-4 Normal, 2-5 Expert (folio 30)
    if (sysWpnNormMax(0) != 4
            || sysWpnExpMax(0) != 5
        )
            ++bad;
        // the Sword - 1-8 Normal, 1-10 Expert (folio 30)
    if (sysWpnExpMax(4) != 10
            || sysWpnExpMin(4) != 1
        )
            ++bad;
        // the 2-Handed Sword - 2-12 Normal, 3-18 Expert (folio 30)
    if (sysWpnNormMax(12) != 12
            || sysWpnExpMin(12) != 3
            || sysWpnExpMax(12) != 18
        )
            ++bad;
        // the Mounted Lance tops the grid - Expert 2-24 (folio 30)
    if (sysWpnExpMax(13) != 24
        )
            ++bad;
        // the space column - 6 feet for the 2-Handed Sword, 5 the Morning
        // Star, 4 the Dwarf Hammer and Pick (folio 30)
    if (sysWpnSpace(12) != 6
            || sysWpnSpace(6) != 5
            || sysWpnSpace(2) != 4
        )
            ++bad;
        // the Spear Set vs Charge - 1-10 Normal, 2-16 Expert (folio 30)
    if (sysWpnNormMax(9) != 10
            || sysWpnExpMax(9) != 16
        )
            ++bad;
        // the Dagger and Sling Stone need no space (folio 30)
    if (sysWpnSpace(0) != 0
            || sysWpnSpace(16) != 0
        )
            ++bad;
        // the frame - DPT = STR x CON + 10 x level, DPG = STR + DEX + half
        // INT (folio 4)
    if (sysDptLevelMult() != 10
            || sysDpgIntDiv() != 2
        )
            ++bad;
        // the structure - 10 sets a turn, 6 units a set (folio 4)
    if (sysSetsPerTurn() != 10
            || sysUnitsPerSet() != 6
        )
            ++bad;
        // below three-quarters DPT the blows land at half strength (folio 4)
    if (sysHalfStrengthPct() != 75
            || sysHalfStrengthDiv() != 2
        )
            ++bad;
        // the order change takes the five-eighths roll of dexterity, pinned
        // as scanned (folio 4)
    if (sysChangeRollNum() != 5
            || sysChangeRollDen() != 8
        )
            ++bad;
        // the kick rules - three in a row, one or two hand blocks, the
        // one-leg-length jumps (folios 4-5)
    if (sysKickRowMax() != 3
            || sysKickHandBlocksMax() != 2
            || sysJumpLegs() != 1
        )
            ++bad;
        // the sweep downs for three units, the grab tells for three units
        // (folios 4-5)
    if (sysSweepDownUnits() != 3
            || sysGrabUnits() != 3
        )
            ++bad;
        // the Stamp has no effect except after a successful sweep (folio 4)
    if (sysStampAfterSweep() != 0
        )
            ++bad;
        // the recovery ladder - light at 10 DPT, serious at 50, the wish at
        // 150 (folio 4)
    if (sysLightWoundDpt() != 10
            || sysSeriousWoundDpt() != 50
            || sysWishDpt() != 150
        )
            ++bad;
        // without magic, days equal DPT lost times one half (folio 4)
    if (sysNaturalRecoveryDiv() != 2
        )
            ++bad;
        // the matrix opens - the Reverse Punch blocked low, the Knife Hand
        // normal against the Knee Block (folio 5)
    if (sysVsLB(0) != 1
            || sysVsKB(2) != 0
        )
            ++bad;
        // the Knife Hand beats the Duck at normal, the Head Kick does not
        // (folio 5)
    if (sysVsD(2) != 0
            || sysVsD(4) != 1
        )
            ++bad;
        // the grab column - the Head Kick grabbed by the X-Block High, the
        // Reverse Punch doubled past it (folio 5)
    if (sysVsXBH(4) != 5
            || sysVsXBH(0) != 2
        )
            ++bad;
        // the Stamp row - normal against the Knee Block, the Sweep row
        // blocked by the Stamp and its own column (folio 5)
    if (sysVsKB(7) != 0
            || sysVsST(6) != 1
            || sysVsSW(6) != 1
        )
            ++bad;
        // the Sweep row - blocked by Rest and Jump Back, sweeping through
        // Jump Forward and the Duck (folio 5)
    if (sysVsR(6) != 1
            || sysVsJB(6) != 1
            || sysVsJF(6) != 4
            || sysVsD(6) != 4
        )
            ++bad;
        // the Stamp against itself reads normal, not applicable against the
        // Jump Back, and triple damage against the Rest (folio 5)
    if (sysVsST(7) != 0
            || sysVsJB(7) != 6
            || sysVsR(7) != 3
        )
            ++bad;
        // the Head Kick reads normal past the Middle Block, blocked by its
        // own column (folio 5)
    if (sysVsMB(4) != 0
            || sysVsHK(4) != 1
        )
            ++bad;
        // the Front Kick blocked by its own column, tripled past the Side
        // Kick (folio 5)
    if (sysVsFK(3) != 1
            || sysVsSK(3) != 3
        )
            ++bad;
        // the two-weapon doctrine - shielded, no expertise, one Flail or
        // Morning Star (folio 30)
    if (sysTwoWeaponShielded() != 1
            || sysNoExpertiseInCombo() != 1
            || sysOneFlailMorningStar() != 1
        )
            ++bad;
        // the geometry - the arm's-length pair, the two-handed X, the
        // grounded strike (folio 4)
    if (sysKickArmLength() != 1
            || sysStrikeArmLength() != 1
            || sysXBlockTwoHanded() != 1
            || sysStrikeFeetGrounded() != 1
        )
            ++bad;
        // the flow - the higher DPT strikes first, the return blow roll, the
        // concession (folio 4)
    if (sysFirstStrikeHighDpt() != 1
            || sysReturnBlowRoll() != 1
            || sysConcedeStops() != 1
        )
            ++bad;
        // the discipline - the mandatory rest, the Duck, no challenges to a
        // recovering monk (folios 4-5)
    if (sysRestEachSet() != 1
            || sysDuckHighMiddle() != 1
            || sysNoChallengeWhileRecovering() != 1
        )
            ++bad;
        printf("R893 systems audit: bad %d\n", bad);
        if (bad) return 1;
    }
