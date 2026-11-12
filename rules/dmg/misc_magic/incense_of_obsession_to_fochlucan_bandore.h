// ====================================================================
// Adnd1 - rules/dmg/misc_magic/incense_of_obsession_to_fochlucan_bandore.h
// R270: the III.E misc magic explanation prose part 14
// (DMG p.141-142) - Incense of Obsession through the
// Fochlucan Bandore, part2 lines 630-684 (global =
// 11065 + part2 line). ONE page header inside the slice
// (674, the TREASURE page) falls between the bandore
// paragraph and its song list (one seam, restored). The
// ioun stone property table: the upload mangles rows 3,
// 5 and 12 (the shape cells folded into the roll and
// color cells, the missing space in 5pink) and wraps the
// regeneration cell across rows - the 15-row table
// restored from the 1eonline.info compilation (the R175
// precedent).
// 47 accessors: 41 scalars + 6 array walkers (the stone
// property table), no name collisions with miscprose1.h
// through miscprose13.h. The slice pins kMisc3 rows
// 24-26: the (C) mark on the Incense of Obsession (row
// 24), the triple asterisk on the Ioun Stones (row 25,
// per stone), the quadruple asterisk on the Instrument of
// the Bards (rows 73-78, per level of instrument). Pure
// data + helpers, header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_incense_of_obsession_to_fochlucan_bandore {
public:
    int mmpObsessionDurationHours();
    int mmpObsessionPiecesMin();
    int mmpObsessionPiecesMax();
    int mmpObsessionBurnHours();
    int mmpIounSortCount();
    int mmpIounOwnerRadiusFeet();
    int mmpIounOrbitMinFeet();
    int mmpIounOrbitMaxFeet();
    int mmpIounFoundMin();
    int mmpIounFoundMax();
    int mmpIounTableRowCount();
    int mmpIounDeadRowLo();
    int mmpIounDeadRowHi();
    int mmpIounStatBonusPoints();
    int mmpIounStatCap();
    int mmpIounStatBonusRowCount();
    int mmpIounLevelGainLevels();
    int mmpIounRegenHpPerTurn();
    int mmpIounPurpleStoreMin();
    int mmpIounPurpleStoreMax();
    int mmpIounRoseProtectionBonus();
    int mmpIounGrayPsionicBonus();
    int mmpIounGrayPsionicCap();
    int mmpIounHpToDestroy();
    int mmpIounSaveBonus();
    int mmpIounAttackAc();
    int mmpIounRowRollLo(int i);
    int mmpIounRowRollHi(int i);
    int mmpIounRowAddsStat(int i);
    int mmpIounRowAbsorbMaxLevel(int i);
    int mmpIounRowBurnoutMin(int i);
    int mmpIounRowBurnoutMax(int i);
    int mmpBardInstrumentCount();
    int mmpFochlucanStringCount();
    int mmpFochlucanLowestFaeriePct();
    int mmpFochlucanLowestReversePct();
    int mmpFochlucanFaerieBasePct();
    int mmpFochlucanReverseReductionPerLevelPct();
    int mmpFochlucanSongCount();
    int mmpFochlucanCharmBonusPct();
    int mmpFochlucanEntanglePerDay();
    int mmpFochlucanShillelaghPerDay();
    int mmpFochlucanSpeakAnimalsPerDay();
    int mmpFochlucanLowestSongWorkPct();
    int mmpFochlucanLowestSongFailPct();
    int mmpFochlucanLowestFailDamageMin();
    int mmpFochlucanLowestFailDamageMax();
};
