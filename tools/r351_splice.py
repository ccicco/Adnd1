#!/usr/bin/env python3
# R351: the UA NEW DRUID SPELLS pin
# round, the 2nd level (pp. 43-44) -
# flame blade (the undead and fire
# damage modifiers), goodberry (the
# name header lost), the reflecting
# pool (the "Pool ion -" name garble,
# the scrying mechanics) and slow
# poison (the herbal antidote
# chance). The digit-garble family
# decodes the "7 round" and the two
# "7 round/level" cells as 1. The
# item stays open (the 3rd-7th
# levels).
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R350 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R350 landed 2026-10-11: commit',
    '  037cdf6, census 277, the UA',
    '  new druid 1st level spells pin',
    '  round (rules/uadruidspells1.h):',
    '  ceremony (the nine varieties',
    '  with the cast-out permission',
    '  ladder), detect balance, detect',
    '  poison and precipitation (the',
    '  name header lost - identified',
    '  via the R343 clerical pin); the',
    '  family decodes the three 7s as',
    '  1; the druid ladder opens. The',
    '  ritual block is gates-only now',
    '  (the file creation is the',
    '  user-side step, done in nano).',
    '  Lesson: the second nano md5',
    '  drift with all gates green -',
    '  the double-run plus the census',
    '  stay the fingerprint. GREEN on',
    '  the first run.',
])
s = rd(SD)
if 'R350 landed 2026-10-11' in s:
    already.append('seed: the R350 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R350 record')
s = rd(SD)
assert s.count('R350 landed 2026-10-11') == 1, 'a entry'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R348 landed 2026-10-11') == 1, 'a r348 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R346 landed 2026-10-11') == 1, 'a r346 kept'
assert s.count('R345 landed 2026-10-11') == 1, 'a r345 kept'
assert s.count('R344 landed 2026-10-11') == 1, 'a r344 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1, 'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1, 'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1, 'a r340 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uadruidspells2.h ----
US = 'rules/uadruidspells2.h'
if os.path.exists(US) and 'R351' in rd(US):
    already.append('uadruidspells2.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells2.h
// The UA NEW DRUID SPELLS (pp. 43-44) pins, R351: the 2nd-level
// spell descriptions - flame blade, goodberry, reflecting pool
// and slow poison.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the flame
//     blade and reflecting pool durations print "7 round/level"
//     and the goodberry casting time prints "7 round" - the
//     family decodes each as 1 (flame blade prints a clean
//     "Level: 2" cell).
//   - the goodberry name header and school never print (the
//     stat block follows the flame blade material sentence
//     directly); identified by the prose "goodberry spell" plus
//     the gap item list.
//   - the reflecting pool name header prints "Pool ion -" - a
//     two-column garble of "Reflecting Pool"; identified by the
//     prose "cast through a reflecting pool" plus the gap item
//     list. The school never prints.
//   - the flame blade damage sentence splits after "if the
//     creature is": the scrambled fragments reassemble as the
//     -2 clause (a fire-dweller or which uses fire attack form)
//     and the protected-from-fire sentence (no damage can be
//     inflicted upon a creature which is protected from fire).
//   - the flame blade material fragments reassemble: "In
//     addition to mistletoe, the druid must have a leaf of the
//     sumac in order to cast this spell" (the "class. order"
//     fragment carries the lost "order").
//   - the flame blade area cell prints "3 long, sword-like
//     blade" - the unit mark is lost; position-decoded as a
//     3-foot blade, pinned with doubt pending the PDF.
//   - the goodberry duration prints "1 day + 1/level" - the
//     per-level unit is lost; pinned verbatim with the unit
//     flagged as a hole.
//   - the reflecting pool material fragments scramble around
//     the walnut oil: mistletoe plus oil extracted from nuts
//     such as the walnut; the measure fragment stays a hole.
//   - the reflecting pool prose loses the spell name after
//     "the spells starshine and" - a hole (see hereafter points
//     into this chapter).
//   - the slow poison range cell prints head-lost as "ge:
//     Touch" = Range: Touch; the level cell never prints -
//     position-certain 2 by the section header. The stray "that"
//     fragment after the saving throw is the tail of the
//     "is able to determine that" clause.
//
// OCR holes (the item stays open - the 3rd-7th levels pin in
// later rounds; these stay pending the PDF): the goodberry name
// header and school; the goodberry duration unit; the reflecting
// pool name header and school; the reflecting pool material
// measure; the lost spell name after "starshine and"; the flame
// blade area unit mark.
// ===========================================================================

#pragma once

namespace rules {

// ---- flame blade (Evocation), p. 43 ----
inline const char* uad2FlameBladeName()
    { return "Flame Blade (Evocation)"; }

inline bool uad2FlameBladeComponentsVSM()
    { return true; }

inline int uad2FlameBladeLevel()
    { return 2; }

inline int uad2FlameBladeCastingTimeSegments()
    { return 3; }

inline int uad2FlameBladeRangeInches()
    { return 0; }

inline bool uad2FlameBladeSaveNone()
    { return true; }

// The duration prints "7 round/level" - the digit-garble family
// decodes 1 round/level.
inline int uad2FlameBladeDurationRoundsPerLevel()
    { return 1; }

// The area cell prints "3 long, sword-like blade" - the unit
// mark is lost; position-decoded as 3 feet, with doubt.
inline int uad2FlameBladeBladeLengthFeet()
    { return 3; }

inline bool uad2FlameBladeBladeUnitLost()
    { return true; }

// A blazing ray of red-hot fire springs from the druid's hand,
// wielded as if it were a scimitar.
inline bool uad2FlameBladeWieldedAsScimitar()
    { return true; }

// A successful hit inflicts 5-8 points of damage; +2 if the
// creature is undead or especially vulnerable to fire; -2 if a
// fire-dweller or a fire-attack-form user.
inline int uad2FlameBladeDamageMin()
    { return 5; }

inline int uad2FlameBladeDamageMax()
    { return 8; }

inline int uad2FlameBladeUndeadOrFireVulnerableBonus()
    { return 2; }

inline int uad2FlameBladeFireDwellerPenalty()
    { return -2; }

// No damage can be inflicted upon a creature protected from
// fire (the interleave decode).
inline bool uad2FlameBladeNoDamageOnFireProtected()
    { return true; }

// The blade will ignite dry materials such as straw, sticks,
// cloth, etc.
inline bool uad2FlameBladeIgnitesDryMaterials()
    { return true; }

// Not a magical weapon in the normal sense except with respect
// to undead monsters - creatures struck only by magical weapons
// are not harmed unless of the undead class.
inline bool uad2FlameBladeNotMagicalExceptVsUndead()
    { return true; }

inline bool uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead()
    { return true; }

// The material: mistletoe plus a leaf of the sumac (the
// interleave decode; the "order" fragment).
inline bool uad2FlameBladeMaterialMistletoe()
    { return true; }

inline bool uad2FlameBladeMaterialSumacLeaf()
    { return true; }

inline bool uad2FlameBladeMaterialInterleaveDecoded()
    { return true; }

// ---- goodberry, p. 44 ----
// The name header and school never print; identified by the
// prose "goodberry spell" plus the gap item list.
inline const char* uad2GoodberryName()
    { return "Goodberry"; }

inline bool uad2GoodberryNameHeaderLost()
    { return true; }

inline bool uad2GoodberrySchoolLost()
    { return true; }

inline bool uad2GoodberryComponentsVSM()
    { return true; }

inline int uad2GoodberryLevel()
    { return 2; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uad2GoodberryCastingTimeRounds()
    { return 1; }

inline bool uad2GoodberryRangeTouch()
    { return true; }

inline bool uad2GoodberrySaveNone()
    { return true; }

// The duration prints "1 day + 1/level" - the per-level unit is
// lost; pinned verbatim with the unit flagged.
inline int uad2GoodberryDurationDaysBase()
    { return 1; }

inline int uad2GoodberryDurationPerLevelAddend()
    { return 1; }

inline bool uad2GoodberryDurationUnitLost()
    { return true; }

inline int uad2GoodberryBerriesMin()
    { return 2; }

inline int uad2GoodberryBerriesMax()
    { return 8; }

// The casting druid (or any druid of 3rd or higher level)
// immediately discerns the affected berries; detect magic
// discovers them also.
inline bool uad2GoodberryDiscernedByDruid3rdPlus()
    { return true; }

inline bool uad2GoodberryDetectMagicReveals()
    { return true; }

// Each berry either nourishes a hungry man-size creature as a
// full meal or cures 1 point of damage, to a maximum of 8
// points of curing in any 24-hour period.
inline bool uad2GoodberryNourishAsFullMeal()
    { return true; }

inline int uad2GoodberryCurePerBerry()
    { return 1; }

inline int uad2GoodberryCureMaxPer24h()
    { return 8; }

// The reverse, badberry: rotten berries appear wholesome but
// each delivers 1 point of poison damage, no saving throw.
inline bool uad2GoodberryReverseBadberry()
    { return true; }

inline int uad2GoodberryBadberryPoisonPoints()
    { return 1; }

inline bool uad2GoodberryBadberryNoSave()
    { return true; }

// The material is mistletoe passed over the freshly picked,
// edible berries; the example list tail survives (currants,
// gooseberries, etc.) - the first list item is lost.
inline bool uad2GoodberryMaterialMistletoe()
    { return true; }

inline bool uad2GoodberryExampleListFirstItemLost()
    { return true; }

// ---- reflecting pool, p. 44 ----
// The name header prints "Pool ion -" - a two-column garble of
// Reflecting Pool; identified by the prose "cast through a
// reflecting pool" plus the gap item list.
inline const char* uad2ReflectingPoolName()
    { return "Reflecting Pool"; }

inline bool uad2ReflectingPoolNameHeaderGarbled()
    { return true; }

inline bool uad2ReflectingPoolSchoolLost()
    { return true; }

inline bool uad2ReflectingPoolComponentsVSM()
    { return true; }

inline int uad2ReflectingPoolLevel()
    { return 2; }

inline int uad2ReflectingPoolCastingTimeHours()
    { return 2; }

inline int uad2ReflectingPoolRangeInches()
    { return 1; }

inline bool uad2ReflectingPoolSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad2ReflectingPoolDurationRoundsPerLevel()
    { return 1; }

inline bool uad2ReflectingPoolAoeSpecial()
    { return true; }

// The pool is normal water in a natural setting, acting as a
// scrying device of no greater diameter than 2 feet per level
// of the caster.
inline bool uad2ReflectingPoolNaturalWaterOnly()
    { return true; }

inline int uad2ReflectingPoolDiameterFeetPerLevel()
    { return 2; }

// Similar to a crystal ball, in the fashion of the magic-user
// magic mirror and the clerical magic font.
inline bool uad2ReflectingPoolCrystalBallLike()
    { return true; }

inline bool uad2ReflectingPoolMagicMirrorAndFontRef()
    { return true; }

// The scrying extends only to planes coexistent with or
// bordering the Prime Material - the Inner Planes, including
// the Para-elemental Planes and the Plane of Shadow; the
// crystal ball penalties (DMG) apply beyond the druid's own
// plane.
inline bool uad2ReflectingPoolCoexistentPlanesOnly()
    { return true; }

inline bool uad2ReflectingPoolIncludesParaElementalAndShadow()
    { return true; }

inline bool uad2ReflectingPoolCrystalBallPenaltiesApply()
    { return true; }

// The spells cast through the pool, with a 5% per level chance
// of operating correctly: detect magic, detect snares and pits,
// detect poison.
inline int uad2ReflectingPoolCastThroughChancePctPerLevel()
    { return 5; }

inline int uad2ReflectingPoolCastThroughCount()
    { return 3; }

inline const char* uad2ReflectingPoolCastThroughName(int i) {
    static const char* const k[3] = {
        "Detect Magic", "Detect Snares and Pits",
        "Detect Poison",
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// Infravision and ultravision operate normally through the
// pool, as will the spells starshine and [the companion name
// is lost - a hole].
inline bool uad2ReflectingPoolInfraAndUltravisionNormal()
    { return true; }

inline bool uad2ReflectingPoolStarshineOperates()
    { return true; }

inline bool uad2ReflectingPoolCompanionSpellNameLost()
    { return true; }

// The material: mistletoe and oil extracted from nuts such as
// the walnut; the measure fragment stays a hole.
inline bool uad2ReflectingPoolMaterialMistletoe()
    { return true; }

inline bool uad2ReflectingPoolMaterialNutOil()
    { return true; }

inline bool uad2ReflectingPoolMaterialMeasureLost()
    { return true; }

// ---- slow poison (Necromantic), p. 44 ----
inline const char* uad2SlowPoisonName()
    { return "Slow Poison (Necromantic)"; }

inline bool uad2SlowPoisonComponentsVSM()
    { return true; }

// The level cell never prints - position-certain 2 by the
// section header.
inline int uad2SlowPoisonLevel()
    { return 2; }

// The range cell prints head-lost as "ge: Touch" = Touch.
inline bool uad2SlowPoisonRangeTouch()
    { return true; }

inline bool uad2SlowPoisonRangeCellHeadLost()
    { return true; }

inline bool uad2SlowPoisonSaveNone()
    { return true; }

inline int uad2SlowPoisonDurationHoursPerLevel()
    { return 1; }

inline bool uad2SlowPoisonAoeCreatureTouched()
    { return true; }

inline int uad2SlowPoisonCastingTimeSegments()
    { return 1; }

// Identical to the 2nd-level clerical slow poison, except: if
// the poison was made from some living plant, the druid has a
// 5% chance per level of knowing an herbal antidote which will
// neutralize the poison.
inline bool uad2SlowPoisonIdenticalToClerical()
    { return true; }

inline int uad2SlowPoisonAntidoteChancePctPerLevel()
    { return 5; }

inline bool uad2SlowPoisonPlantPoisonCondition()
    { return true; }

// If the actual type of poison is not given by the DM, a
// successful detect poison (type) indicates an organic poison
// which can be countered; a dice roll equal to or less than
// the druid's chance indicates neutralization.
inline bool uad2SlowPoisonDetectPoisonIndicatesOrganic()
    { return true; }

inline bool uad2SlowPoisonRollEqualOrLessNeutralizes()
    { return true; }

// The material: mistletoe, plus crushed garlic rubbed on the
// recipient's feet; antidotes from green vegetables outdoors or
// an herbalist or similar source.
inline bool uad2SlowPoisonMaterialMistletoe()
    { return true; }

inline bool uad2SlowPoisonMaterialGarlicOnFeet()
    { return true; }

inline bool uad2SlowPoisonAntidoteOutdoorOrHerbalist()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells2.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 87, 'b inline count'
assert s.count('R351') == 1, 'b round tag'
assert s.count('uad2ReflectingPoolCastThroughName(int i)') == 1, 'b cast fn'
assert s.count('uad2FlameBladeName()') == 1, 'b flame fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uad1' not in s, 'b no r350 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 3rd-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R351: the 2nd level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        through 7th levels stay open.',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R351: the 2nd level pinned',
    '        (rules/uadruidspells2.h) - the',
    '        four spell descriptions',
    '        (flame blade with the undead',
    '        and fire damage modifiers,',
    '        goodberry with the name',
    '        header lost, the reflecting',
    '        pool behind the "Pool ion -"',
    '        name garble with the',
    '        scrying mechanics, slow',
    '        poison with the herbal',
    '        antidote chance); the family',
    '        decodes the three 7s as 1',
    '        (flame blade prints the',
    '        clean 2); the R341 druid',
    '        table prints no 2nd-level',
    '        roster - all four names pin',
    '        from the prose; the 3rd',
    '        through 7th levels stay open.',
])
    clean(NOTE, 57)
    s = s.replace(
        '        through 7th levels stay open.' + NL,
        '        through 7th levels stay open.' + NL
        + NOTE + NL)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R351: the 2nd level pinned') == 1, 'c note'
assert s.count('- [ ] **The new druid spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R350: the 1st level pinned') == 1, 'c r350 kept'
assert s.count('R349: the 7th level pinned') == 1, 'c r349 kept'
assert s.count('CLOSED R349') == 1, 'c r349 closed kept'
assert s.count('R348: the 6th level pinned') == 1, 'c r348 kept'
assert s.count('R347: the 5th level pinned') == 1, 'c r347 kept'
assert s.count('R346: the 4th level pinned') == 1, 'c r346 kept'
assert s.count('R345: the 3rd level pinned') == 1, 'c r345 kept'
assert s.count('R344: the 2nd level pinned') == 1, 'c r344 kept'
assert s.count('R343: the 1st level pinned') == 1, 'c r343 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R351 UA druid 2nd level spells pin audit' in s:
    already.append('regtest.cpp: the R351 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells1.h"'
        '  // R350: the UA new druid 1st'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells2.h"'
        '  // R351: the UA new druid 2nd'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R351: the UA new druid 2nd level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 43-44),
    // the 2nd level - flame blade (the
    // undead/fire damage modifiers), goodberry
    // (the name header lost), reflecting pool
    // (the "Pool ion -" garble, the scrying
    // mechanics) and slow poison (the herbal
    // antidote chance). The digit-garble family
    // decodes the "7 round" and the two
    // "7 round/level" cells as 1 (flame blade
    // prints the clean 2). The item stays open
    // (the 3rd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: flame blade
        {
            if (strcmp(uad2FlameBladeName(),
                "Flame Blade (Evocation)") != 0) ++bad;
            if (!uad2FlameBladeComponentsVSM()) ++bad;
            if (uad2FlameBladeLevel() != 2) ++bad;
            if (uad2FlameBladeCastingTimeSegments() != 3)
                ++bad;
            if (uad2FlameBladeRangeInches() != 0) ++bad;
            if (!uad2FlameBladeSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad2FlameBladeDurationRoundsPerLevel()
                != 1) ++bad;
            // the "3 long" area cell - the unit
            // lost, position-decoded
            if (uad2FlameBladeBladeLengthFeet() != 3)
                ++bad;
            if (!uad2FlameBladeBladeUnitLost()) ++bad;
            if (!uad2FlameBladeWieldedAsScimitar()) ++bad;
            // the damage 5-8 and the modifiers
            if (uad2FlameBladeDamageMin() != 5) ++bad;
            if (uad2FlameBladeDamageMax() != 8) ++bad;
            if (uad2FlameBladeUndeadOrFireVulnerableBonus()
                != 2) ++bad;
            if (uad2FlameBladeFireDwellerPenalty() != -2)
                ++bad;
            // the interleave decode
            if (!uad2FlameBladeNoDamageOnFireProtected())
                ++bad;
            if (!uad2FlameBladeIgnitesDryMaterials()) ++bad;
            if (!uad2FlameBladeNotMagicalExceptVsUndead())
                ++bad;
            if (!uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead())
                ++bad;
            // the material: mistletoe plus the
            // sumac leaf
            if (!uad2FlameBladeMaterialMistletoe()) ++bad;
            if (!uad2FlameBladeMaterialSumacLeaf()) ++bad;
            if (!uad2FlameBladeMaterialInterleaveDecoded())
                ++bad;
        }
        // U2: goodberry
        {
            if (strcmp(uad2GoodberryName(),
                "Goodberry") != 0) ++bad;
            // the name header and school never
            // print - holes
            if (!uad2GoodberryNameHeaderLost()) ++bad;
            if (!uad2GoodberrySchoolLost()) ++bad;
            if (!uad2GoodberryComponentsVSM()) ++bad;
            if (uad2GoodberryLevel() != 2) ++bad;
            // the "7 round" family decode
            if (uad2GoodberryCastingTimeRounds() != 1)
                ++bad;
            if (!uad2GoodberryRangeTouch()) ++bad;
            if (!uad2GoodberrySaveNone()) ++bad;
            // the "1 day + 1/level" duration - the
            // unit lost
            if (uad2GoodberryDurationDaysBase() != 1)
                ++bad;
            if (uad2GoodberryDurationPerLevelAddend() != 1)
                ++bad;
            if (!uad2GoodberryDurationUnitLost()) ++bad;
            if (uad2GoodberryBerriesMin() != 2) ++bad;
            if (uad2GoodberryBerriesMax() != 8) ++bad;
            if (!uad2GoodberryDiscernedByDruid3rdPlus())
                ++bad;
            if (!uad2GoodberryDetectMagicReveals()) ++bad;
            if (!uad2GoodberryNourishAsFullMeal()) ++bad;
            if (uad2GoodberryCurePerBerry() != 1) ++bad;
            if (uad2GoodberryCureMaxPer24h() != 8) ++bad;
            // the badberry reverse
            if (!uad2GoodberryReverseBadberry()) ++bad;
            if (uad2GoodberryBadberryPoisonPoints() != 1)
                ++bad;
            if (!uad2GoodberryBadberryNoSave()) ++bad;
            if (!uad2GoodberryMaterialMistletoe()) ++bad;
            // the example list first item lost
            if (!uad2GoodberryExampleListFirstItemLost())
                ++bad;
        }
        // U3: reflecting pool
        {
            if (strcmp(uad2ReflectingPoolName(),
                "Reflecting Pool") != 0) ++bad;
            // the "Pool ion -" garble
            if (!uad2ReflectingPoolNameHeaderGarbled())
                ++bad;
            if (!uad2ReflectingPoolSchoolLost()) ++bad;
            if (!uad2ReflectingPoolComponentsVSM()) ++bad;
            if (uad2ReflectingPoolLevel() != 2) ++bad;
            if (uad2ReflectingPoolCastingTimeHours() != 2)
                ++bad;
            if (uad2ReflectingPoolRangeInches() != 1) ++bad;
            if (!uad2ReflectingPoolSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad2ReflectingPoolDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad2ReflectingPoolAoeSpecial()) ++bad;
            if (!uad2ReflectingPoolNaturalWaterOnly())
                ++bad;
            if (uad2ReflectingPoolDiameterFeetPerLevel()
                != 2) ++bad;
            if (!uad2ReflectingPoolCrystalBallLike()) ++bad;
            if (!uad2ReflectingPoolMagicMirrorAndFontRef())
                ++bad;
            if (!uad2ReflectingPoolCoexistentPlanesOnly())
                ++bad;
            if (!uad2ReflectingPoolIncludesParaElementalAndShadow())
                ++bad;
            if (!uad2ReflectingPoolCrystalBallPenaltiesApply())
                ++bad;
            // the cast-through mechanics
            if (uad2ReflectingPoolCastThroughChancePctPerLevel()
                != 5) ++bad;
            if (uad2ReflectingPoolCastThroughCount() != 3)
                ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(0),
                "Detect Magic") != 0) ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(1),
                "Detect Snares and Pits") != 0) ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(2),
                "Detect Poison") != 0) ++bad;
            if (!uad2ReflectingPoolInfraAndUltravisionNormal())
                ++bad;
            if (!uad2ReflectingPoolStarshineOperates()) ++bad;
            // the companion spell name lost
            if (!uad2ReflectingPoolCompanionSpellNameLost())
                ++bad;
            // the material: mistletoe plus the
            // nut oil; the measure lost
            if (!uad2ReflectingPoolMaterialMistletoe())
                ++bad;
            if (!uad2ReflectingPoolMaterialNutOil()) ++bad;
            if (!uad2ReflectingPoolMaterialMeasureLost())
                ++bad;
        }
        // U4: slow poison
        {
            if (strcmp(uad2SlowPoisonName(),
                "Slow Poison (Necromantic)") != 0) ++bad;
            if (!uad2SlowPoisonComponentsVSM()) ++bad;
            // the level cell lost - section-
            // certain 2
            if (uad2SlowPoisonLevel() != 2) ++bad;
            // the "ge: Touch" head-lost range
            if (!uad2SlowPoisonRangeTouch()) ++bad;
            if (!uad2SlowPoisonRangeCellHeadLost()) ++bad;
            if (!uad2SlowPoisonSaveNone()) ++bad;
            if (uad2SlowPoisonDurationHoursPerLevel() != 1)
                ++bad;
            if (!uad2SlowPoisonAoeCreatureTouched()) ++bad;
            if (uad2SlowPoisonCastingTimeSegments() != 1)
                ++bad;
            // the clerical identity and the
            // herbal antidote chance
            if (!uad2SlowPoisonIdenticalToClerical())
                ++bad;
            if (uad2SlowPoisonAntidoteChancePctPerLevel()
                != 5) ++bad;
            if (!uad2SlowPoisonPlantPoisonCondition())
                ++bad;
            if (!uad2SlowPoisonDetectPoisonIndicatesOrganic())
                ++bad;
            if (!uad2SlowPoisonRollEqualOrLessNeutralizes())
                ++bad;
            if (!uad2SlowPoisonMaterialMistletoe()) ++bad;
            if (!uad2SlowPoisonMaterialGarlicOnFeet()) ++bad;
            if (!uad2SlowPoisonAntidoteOutdoorOrHerbalist())
                ++bad;
        }
        // U5: the R341 table seam
        {
            // The druid table (p. 29) prints no
            // 2nd-level roster - the 2nd and 3rd
            // columns are OCR-lost in R341; the
            // readable neighbors prove the pin
            // kept. All four 2nd-level names pin
            // from the prose alone.
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(0),
                "Locate Animals") != 0) ++bad;
            if (uastDruid4thCount() != 6) ++bad;
            if (strcmp(uastDruid4thName(0),
                "Cure Serious Wounds") != 0) ++bad;
            if (uastDruid5thCount() != 6) ++bad;
            if (strcmp(uastDruid5thName(0),
                "Commune With Nature") != 0) ++bad;
        }
        printf("R351 UA druid 2nd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R351 audit')
s = rd(RT)
assert s.count(
    'R351 UA druid 2nd level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 278, 'd census 278'
assert s.count(
    'R350 UA druid 1st level spells'
    ' pin audit: bad ') == 1, 'd r350 kept'
assert s.count(
    'R349 UA cleric 7th level spells'
    ' pin audit: bad ') == 1, 'd r349 kept'
assert s.count(
    'R348 UA cleric 6th level spells'
    ' pin audit: bad ') == 1, 'd r348 kept'
assert s.count(
    'R343 UA cleric 1st level spells'
    ' pin audit: bad ') == 1, 'd r343 kept'
assert s.count('R227: the wis mental save') == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uadruidspells2.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R351 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R351 note: the UA new druid spells')
print('pin round, the 2nd level - the four')
print('spell descriptions (flame blade with')
print('the undead and fire damage modifiers,')
print('goodberry with the name header lost,')
print('the reflecting pool behind the name')
print('garble with the scrying mechanics,')
print('slow poison with the herbal antidote')
print('chance); the family decodes the three')
print('7s as 1; the R341 druid table prints')
print('no 2nd-level roster - all four names')
print('pin from the prose; the item stays')
print('open (the 3rd-7th levels); the census')
print('277 -> 278')
print('commit: R351: the UA new druid 2nd')
print('level spells pin round (census 278)')

