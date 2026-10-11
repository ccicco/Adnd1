#!/usr/bin/env python3
# R350: the UA NEW DRUID SPELLS pin
# round, the 1st level (pp. 42-43) -
# ceremony (the nine varieties and
# the cast-out permission ladder),
# detect balance, detect poison and
# precipitation (the name header
# lost - identified via the R343
# clerical pin). The digit-garble
# family decodes the three
# "Level: 7" cells as 1. The item
# stays open (the 2nd-7th levels).
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

# ---- (a) the seed: the R349 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R349 landed 2026-10-11: commit',
    '  ba3dc04, census 276, the UA',
    '  new cleric 7th level spells pin',
    '  round (rules/uaclericspells7.h):',
    '  exaction (the alignment gates',
    '  and the bargain consequences)',
    '  and succor (the prepared-object',
    '  dweomer with the summons',
    '  reverse); the family decodes',
    '  the two 7s as 1; the item',
    '  CLOSED - all seven levels',
    '  pinned (R343-R349); the',
    '  new-cleric-spells gap item',
    '  checked off. Lesson: the user',
    '  built the splice in nano (not',
    '  the cat paste); the md5',
    '  drifted (whitespace) yet',
    '  py_compile, the width profile,',
    '  the double-run and the census',
    '  all passed - the gates stay',
    '  the fingerprint, md5 a',
    '  convenience. GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R349 landed 2026-10-11' in s:
    already.append('seed: the R349 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R349 record')
s = rd(SD)
assert s.count('R349 landed 2026-10-11') == 1, 'a entry'
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

# ---- (b) NEW rules/uadruidspells1.h ----
US = 'rules/uadruidspells1.h'
if os.path.exists(US) and 'R350' in rd(US):
    already.append('uadruidspells1.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells1.h
// The UA NEW DRUID SPELLS (pp. 42-43) pins, R350: the 1st-level
// spell descriptions - ceremony, detect balance, detect poison,
// precipitation.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 druid table pin (rules/uaspelltables.h) is the name seam.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): three
//     "Level: 7" cells print where the level is position-certain 1
//     (ceremony, detect poison, precipitation) - the section header
//     reads First Level Spells and detect balance prints a clean
//     "Level: 1" cell. The same family decodes the detect balance
//     casting time "7 segment" and the two "7 round/level"
//     durations (detect balance, detect poison) as 1.
//   - the ceremony opener prints "The druidic ... spell is similar
//     to the clerical spell of the same name" with a stray "y"
//     fragment - the lost word decodes as ceremony (the section
//     subject); the fragment noted.
//   - the ceremony stat block prints empty Components and Casting
//     Time cells - holes; the prose pins mistletoe (always) and
//     the dawn-or-dusk rite setting.
//   - the ceremony variety ladder: the "1st-level druid" and
//     "12th-level druid" prefixes print clean; the three middle
//     group prefixes are lost cells ("id:" is a tail of a lost
//     "...level druid:" prefix) - the group membership and order
//     pin (dedication, investiture; initiation, special vows;
//     hallowed ground), the middle prefix numbers stay holes
//     pending the PDF. The "Th as follows:" line is the scrambled
//     "The effects of the various types of druidic ceremony spells
//     are as follows:" head.
//   - hallowed ground: "his or her willy grove" decodes as the
//     druid's own grove (the "willy" garble noted); the displaced
//     "never" reads "the trees of the grove will never be affected
//     by disease or other natural disasters".
//   - cast out: the permission interleave decodes as the ladder
//     druid <- Archdruid <- Great Druid <- Grand Druid ("Archdruid"
//     prints displaced before "performed"; the "us" fragment is a
//     stray tail); the Grand Druid needs no permission but a
//     Hierophant Druid may reverse the Grand Druid at any time.
//     The adverb after "causing any natural crea- tures to react"
//     is lost - a hole.
//   - the detect poison opener scrambles two columns: "By means of
//     this spell the druid is able to determine if some object,
//     creature, or area contains or has been poisoned."
//   - precipitation: the name header never prints (the stat block
//     follows detect poison's scrambled opener directly);
//     identified by the gap item list plus "identical to the
//     1st-level clerical spell of the same name" - the R343
//     clerical precipitation pin. The duration prints
//     "1 segment/ievel" = level; the range cell prints empty - a
//     hole (the R343 clerical range was lost too).
//
// OCR holes (the item stays open - the 2nd-7th levels pin in later
// rounds; these stay pending the PDF): the ceremony components
// cell beyond the prose mistletoe and the empty casting time cell;
// the three middle ceremony variety prefix numbers; the cast out
// react-adverb; the detect balance range cell; the precipitation
// name header, school line and range cell.
// ===========================================================================

#pragma once

namespace rules {

// ---- ceremony (Invocation), p. 42-43 ----
inline const char* uad1CeremonyName()
    { return "Ceremony (Invocation)"; }

// The stat block prints "Level: 7" - the digit-garble family
// decodes 1 (the section header and the R343 family precedent).
inline int uad1CeremonyLevel()
    { return 1; }

inline bool uad1CeremonyRangeTouch()
    { return true; }

inline bool uad1CeremonySaveSpecial()
    { return true; }

inline bool uad1CeremonyDurationPermanent()
    { return true; }

inline bool uad1CeremonyAoeOneCreatureItemOrArea()
    { return true; }

// The components and casting time cells print empty - holes; the
// prose pins that the components always include mistletoe.
inline bool uad1CeremonyComponentsIncludeMistletoe()
    { return true; }

inline bool uad1CeremonyComponentsCellLost()
    { return true; }

inline bool uad1CeremonyCastingTimeCellLost()
    { return true; }

// The opener decodes: the druidic ceremony spell is similar to the
// clerical spell of the same name.
inline bool uad1CeremonySimilarToClerical()
    { return true; }

inline bool uad1CeremonyNoAuraOfMagic()
    { return true; }

inline bool uad1CeremonyKnowAlignmentRevealsNeutrality()
    { return true; }

// The nine ceremony varieties, in list order. The caster level
// pins clean for the 1st (the first three) and the 12th (cast
// out); the three middle group prefixes are lost cells.
inline int uad1CeremonyVarietyCount()
    { return 9; }

inline const char* uad1CeremonyVarietyName(int i) {
    static const char* const k[9] = {
        "Coming of Age", "Rest Eternal", "Marriage",
        "Dedication", "Investiture", "Initiation",
        "Special Vows", "Hallowed Ground", "Cast Out",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uad1CeremonyVarietyCasterLevel(int i) {
    // 1 for the first three; 12 for cast out; 0 marks the
    // lost middle prefixes (pending the PDF).
    static const int k[9] = {
        1, 1, 1, 0, 0, 0, 0, 0, 12,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// A druid of the indicated or lower level can cast each rite.
inline bool uad1CeremonyIndicatedOrLowerLevel()
    { return true; }

// Coming of age: usually at age 14, symbolic of entrance into
// adulthood; the +1 bonus to a single saving throw matches the
// clerical version.
inline int uad1ComingOfAgeUsualAge()
    { return 14; }

inline int uad1ComingOfAgeSaveBonus()
    { return 1; }

// Rest eternal: the soul is hastened to its final resting place;
// raise dead and resurrection will not restore life afterwards -
// a wish would serve.
inline bool uad1RestEternalBlocksRaiseDeadAndResurrection()
    { return true; }

inline bool uad1RestEternalWishWorks()
    { return true; }

inline bool uad1MarriageIdenticalToClerical()
    { return true; }

// Dedication: taken into the ranks of followers/worshipers,
// provided the character is true neutral; charged, as druids,
// with preserving and protecting nature and the balance.
inline bool uad1DedicationRequiresTrueNeutral()
    { return true; }

inline bool uad1DedicationChargesBalanceKeeping()
    { return true; }

// Investiture: must be performed before a character can become an
// Aspirant (1st-level druid); conveys no other benefit.
inline bool uad1InvestitureBeforeAspirant()
    { return true; }

inline bool uad1InvestitureNoOtherBenefit()
    { return true; }

// Initiation: imbues the shape-changing and woodland-charm
// immunity powers available upon attaining 7th level; must be
// performed immediately after the druid begins advancing through
// the 7th level or it will not work.
inline bool uad1InitiationGrantsShapechangeAndWoodlandImmunity()
    { return true; }

inline bool uad1InitiationMustFollowSeventhLevelStart()
    { return true; }

inline bool uad1InitiationUsuallyBySeventhPlusDruid()
    { return true; }

inline bool uad1InitiationSelfCastUnusual()
    { return true; }

// Special vows: same fashion as the clerical rite; does not work
// upon paladins, but functions upon cavaliers of any alignment.
inline bool uad1SpecialVowsNotOnPaladins()
    { return true; }

inline bool uad1SpecialVowsWorksOnCavaliersAnyAlignment()
    { return true; }

// Hallowed ground: cast on the druid's own grove; the trees will
// never be affected by disease or other natural disasters; the
// ground stays hallowed while the druid keeps the grove as his
// or her permanent base.
inline bool uad1HallowedGroundOwnGrove()
    { return true; }

inline bool uad1HallowedGroundTreesNeverDiseased()
    { return true; }

inline bool uad1HallowedGroundLastsWhilePermanentBase()
    { return true; }

// Cast out: excommunication or punishment for sacrilege upon the
// natural environment or violations of druidic principles; the
// effects may be lessened later by a reversed version cast by the
// same druid or another of at least as high a level; never
// completely neutralized except by a Hierophant Druid of any
// level.
inline bool uad1CastOutExcommunicationForSacrilege()
    { return true; }

inline bool uad1CastOutLessenedByReversedVersion()
    { return true; }

inline bool uad1CastOutReverserAtLeastEqualLevel()
    { return true; }

inline bool uad1CastOutOnlyHierophantNeutralizes()
    { return true; }

// The cast-out druid exudes an aura causing any natural creatures
// to react [adverb lost - a hole]; this includes all animals
// native to the woodlands, domesticated beasts such as horses and
// dogs, and all druids and their followers.
inline bool uad1CastOutAuraAffectsNaturalCreatures()
    { return true; }

inline bool uad1CastOutReactAdverbLost()
    { return true; }

inline bool uad1CastOutAuraIncludesDomesticAndDruids()
    { return true; }

// The permission ladder: a druid needs permission from his or her
// Archdruid; an Archdruid similarly from the Great Druid; the
// Great Druid from the Grand Druid; the Grand Druid needs no
// permission, but a Hierophant Druid may reverse the Grand Druid
// at any time. A denied or offset druid may be punished by
// higher-ranking hierarchy members.
inline bool uad1CastOutNeedsArchdruidPermission()
    { return true; }

inline bool uad1ArchdruidNeedsGreatDruidPermission()
    { return true; }

inline bool uad1GreatDruidNeedsGrandDruidPermission()
    { return true; }

inline bool uad1GrandDruidNeedsNoPermission()
    { return true; }

inline bool uad1GrandDruidReversibleByHierophant()
    { return true; }

inline bool uad1CastOutDeniedOrOffsetPunishable()
    { return true; }

// An unwilling recipient receives a saving throw versus spell,
// at -4, to negate.
inline int uad1CastOutUnwillingSaveMod()
    { return -4; }

// The components always include mistletoe; the rite must be
// performed in a druid grove or another natural, healthy patch
// of forest, normally at dawn or dusk (night and day in balance).
inline bool uad1CeremonyRiteInGroveOrHealthyForest()
    { return true; }

inline bool uad1CeremonyAtDawnOrDusk()
    { return true; }

// ---- detect balance (Divination), p. 43 ----
inline const char* uad1DetectBalanceName()
    { return "Detect Balance (Divination)"; }

inline bool uad1DetectBalanceComponentsVSM()
    { return true; }

// This one prints a clean "Level: 1" cell.
inline int uad1DetectBalanceLevel()
    { return 1; }

// The casting time prints "7 segment" - the digit-garble family
// decodes 1 segment.
inline int uad1DetectBalanceCastingTimeSegments()
    { return 1; }

// The range cell prints empty - a hole.
inline bool uad1DetectBalanceRangeLost()
    { return true; }

inline bool uad1DetectBalanceSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad1DetectBalanceDurationRoundsPerLevel()
    { return 1; }

inline bool uad1DetectBalanceAoeOnePerRound()
    { return true; }

// The spell determines if non-neutral alignments are at work in
// the area of effect or upon the object or creature; a partly
// neutral alignment (neutral good) radiates a mild aura; one
// with no neutral part (chaotic good) gives off a strong aura.
inline bool uad1DetectBalanceDetectsNonNeutralForces()
    { return true; }

inline bool uad1DetectBalancePartlyNeutralMildAura()
    { return true; }

inline bool uad1DetectBalanceNoNeutralPartStrongAura()
    { return true; }

// It does not determine exact alignment - only whether neutral;
// a paladin and a chaotic evil thief radiate the same strength.
inline bool uad1DetectBalanceNotExactAlignment()
    { return true; }

inline bool uad1DetectBalanceSameStrengthForSameNeutrality()
    { return true; }

// It will not function upon non-living items without a natural
// aura (a vial of poison) but works upon an aligned magical
// sword; unknowable alignment or similar magic blocks the read;
// a true neutral subject (another druid) produces a smooth,
// well-balanced aura of neutrality.
inline bool uad1DetectBalanceNoAuraOnPlainItems()
    { return true; }

inline bool uad1DetectBalanceWorksOnAlignedMagicItem()
    { return true; }

inline bool uad1DetectBalanceUnknowableAlignmentBlocks()
    { return true; }

inline bool uad1DetectBalanceTrueNeutralSmoothAura()
    { return true; }

// ---- detect poison (Divination), p. 43 ----
inline const char* uad1DetectPoisonName()
    { return "Detect Poison (Divination)"; }

inline bool uad1DetectPoisonComponentsVSM()
    { return true; }

// The stat block prints "Level: 7" - the family decodes 1.
inline int uad1DetectPoisonLevel()
    { return 1; }

inline bool uad1DetectPoisonRangeZero()
    { return true; }

inline int uad1DetectPoisonCastingTimeRounds()
    { return 1; }

inline bool uad1DetectPoisonSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad1DetectPoisonDurationRoundsPerLevel()
    { return 1; }

inline bool uad1DetectPoisonAoeSpecial()
    { return true; }

// The scrambled opener decodes: by means of this spell the druid
// is able to determine if some object, creature, or area
// contains or has been poisoned.
inline bool uad1DetectPoisonOpenerScrambleDecoded()
    { return true; }

// About 1 cubic yard of space can be perused per round - the
// druid cannot tell if an entire pond is poisoned, but can tell
// of a portion (or something within it) scanned during a round.
inline int uad1DetectPoisonScanVolumeCubicYards()
    { return 1; }

inline bool uad1DetectPoisonPortionNotWholePond()
    { return true; }

// A 5% chance per level of experience also discovers the type of
// poison used or contained: contact (insinuative), ingestive, or
// respirative (gas).
inline int uad1DetectPoisonTypeChancePctPerLevel()
    { return 5; }

inline int uad1DetectPoisonTypeCount()
    { return 3; }

inline const char* uad1DetectPoisonTypeName(int i) {
    static const char* const k[3] = {
        "Contact (Insinuative)", "Ingestive",
        "Respirative (Gas)",
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// More than one area can be scanned during the duration, but any
// single failure on the 5% type roll makes the spell useless for
// type detection for the remainder of that casting.
inline bool uad1DetectPoisonOneFailureEndsTypeDetection()
    { return true; }

// The components are mistletoe plus a yew leaf; the yew leaf
// turns brown if poison is present, so several may be needed to
// utilize the entire duration.
inline bool uad1DetectPoisonMaterialMistletoe()
    { return true; }

inline bool uad1DetectPoisonMaterialYewLeaf()
    { return true; }

inline bool uad1DetectPoisonYewLeafTurnsBrown()
    { return true; }

inline bool uad1DetectPoisonSeveralLeavesNeeded()
    { return true; }

// ---- precipitation, p. 43 ----
// The name header never prints - the stat block follows the
// detect poison scrambled opener directly; identified by the
// gap item list plus "identical to the 1st-level clerical spell
// of the same name" (the R343 clerical pin).
inline const char* uad1PrecipName()
    { return "Precipitation"; }

inline bool uad1PrecipNameHeaderLost()
    { return true; }

inline bool uad1PrecipSchoolLost()
    { return true; }

inline bool uad1PrecipIdenticalToClerical()
    { return true; }

inline bool uad1PrecipComponentsVSM()
    { return true; }

// The stat block prints "Level: 7" - the family decodes 1.
inline int uad1PrecipLevel()
    { return 1; }

inline int uad1PrecipCastingTimeSegments()
    { return 3; }

// The range cell prints empty - a hole (the R343 clerical range
// was lost too).
inline bool uad1PrecipRangeLost()
    { return true; }

// The saving throw prints "None (& special)".
inline bool uad1PrecipSaveNoneAndSpecial()
    { return true; }

// The duration prints "1 segment/ievel" - the OCR "ievel" reads
// level.
inline int uad1PrecipDurationSegmentsPerLevel()
    { return 1; }

inline int uad1PrecipCylinderDiameterInches()
    { return 3; }

inline int uad1PrecipCylinderHeightInches()
    { return 12; }

// The druidic version is identical to the 1st-level clerical
// spell of the same name except that the druid needs mistletoe
// as an additional material component.
inline bool uad1PrecipAddsMistletoeToClerical()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells1.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 99, 'b inline count'
assert s.count('R350') == 1, 'b round tag'
assert s.count('uad1CeremonyVarietyCasterLevel(int i)') == 1, 'b ladder fn'
assert s.count('uad1DetectPoisonTypeName(int i)') == 1, 'b type fn'
assert 'uastDruid1st' not in s, 'b no r341 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 2nd-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R350: the 1st level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '      water to dust), 7th (changestaff).',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R350: the 1st level pinned',
    '        (rules/uadruidspells1.h) - the',
    '        four spell descriptions',
    '        (ceremony with the nine',
    '        varieties and the cast-out',
    '        permission ladder, detect',
    '        balance, detect poison with',
    '        the yew leaf, precipitation',
    '        with the name header lost -',
    '        identified via the R343',
    '        clerical pin); the family',
    '        decodes the three 7s as 1',
    '        (detect balance prints the',
    '        clean 1); the R341 druid',
    '        table prints the four PHB',
    '        names - none of the new',
    '        names seam-checks; the 2nd',
    '        through 7th levels stay open.',
])
    clean(NOTE, 57)
    s = s.replace(
        '      water to dust), 7th (changestaff).' + NL,
        '      water to dust), 7th (changestaff).' + NL
        + NOTE + NL)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R350: the 1st level pinned') == 1, 'c note'
assert s.count('- [ ] **The new druid spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('CLOSED R349') == 1, 'c r349 closed kept'
assert s.count('R349: the 7th level pinned') == 1, 'c r349 kept'
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
if 'R350 UA druid 1st level spells pin audit' in s:
    already.append('regtest.cpp: the R350 audit')
else:
    INC_ANCH = (
        '#include "rules/uaclericspells7.h"'
        '  // R349: the UA new cleric 7th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells1.h"'
        '  // R350: the UA new druid 1st'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R350: the UA new druid 1st level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 42-43),
    // the 1st level - ceremony (the nine
    // varieties with the cast-out
    // permission ladder), detect balance,
    // detect poison (the yew leaf) and
    // precipitation (the name header lost -
    // identified via the R343 clerical
    // pin). The digit-garble family decodes
    // the three "Level: 7" cells, the
    // "7 segment" and the two
    // "7 round/level" cells as 1 (detect
    // balance prints the clean 1). The item
    // stays open (the 2nd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: ceremony
        {
            if (strcmp(uad1CeremonyName(),
                "Ceremony (Invocation)") != 0) ++bad;
            // the "Level: 7" family decode
            if (uad1CeremonyLevel() != 1) ++bad;
            if (!uad1CeremonyRangeTouch()) ++bad;
            if (!uad1CeremonySaveSpecial()) ++bad;
            if (!uad1CeremonyDurationPermanent()) ++bad;
            if (!uad1CeremonyAoeOneCreatureItemOrArea())
                ++bad;
            if (!uad1CeremonyComponentsIncludeMistletoe())
                ++bad;
            // the empty components and casting
            // time cells - holes
            if (!uad1CeremonyComponentsCellLost()) ++bad;
            if (!uad1CeremonyCastingTimeCellLost()) ++bad;
            if (!uad1CeremonySimilarToClerical()) ++bad;
            if (!uad1CeremonyNoAuraOfMagic()) ++bad;
            if (!uad1CeremonyKnowAlignmentRevealsNeutrality())
                ++bad;
            // the nine varieties in list order
            if (uad1CeremonyVarietyCount() != 9) ++bad;
            if (strcmp(uad1CeremonyVarietyName(0),
                "Coming of Age") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(2),
                "Marriage") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(3),
                "Dedication") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(6),
                "Special Vows") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(8),
                "Cast Out") != 0) ++bad;
            // the clean 1st and 12th prefixes;
            // the middle prefixes lost (0)
            if (uad1CeremonyVarietyCasterLevel(0) != 1)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(2) != 1)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(4) != 0)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(8) != 12)
                ++bad;
            if (!uad1CeremonyIndicatedOrLowerLevel())
                ++bad;
            // coming of age
            if (uad1ComingOfAgeUsualAge() != 14) ++bad;
            if (uad1ComingOfAgeSaveBonus() != 1) ++bad;
            // rest eternal
            if (!uad1RestEternalBlocksRaiseDeadAndResurrection())
                ++bad;
            if (!uad1RestEternalWishWorks()) ++bad;
            if (!uad1MarriageIdenticalToClerical()) ++bad;
            // dedication
            if (!uad1DedicationRequiresTrueNeutral()) ++bad;
            if (!uad1DedicationChargesBalanceKeeping())
                ++bad;
            // investiture
            if (!uad1InvestitureBeforeAspirant()) ++bad;
            if (!uad1InvestitureNoOtherBenefit()) ++bad;
            // initiation
            if (!uad1InitiationGrantsShapechangeAndWoodlandImmunity())
                ++bad;
            if (!uad1InitiationMustFollowSeventhLevelStart())
                ++bad;
            if (!uad1InitiationUsuallyBySeventhPlusDruid())
                ++bad;
            if (!uad1InitiationSelfCastUnusual()) ++bad;
            // special vows
            if (!uad1SpecialVowsNotOnPaladins()) ++bad;
            if (!uad1SpecialVowsWorksOnCavaliersAnyAlignment())
                ++bad;
            // hallowed ground
            if (!uad1HallowedGroundOwnGrove()) ++bad;
            if (!uad1HallowedGroundTreesNeverDiseased()) ++bad;
            if (!uad1HallowedGroundLastsWhilePermanentBase())
                ++bad;
            // cast out
            if (!uad1CastOutExcommunicationForSacrilege())
                ++bad;
            if (!uad1CastOutLessenedByReversedVersion())
                ++bad;
            if (!uad1CastOutReverserAtLeastEqualLevel())
                ++bad;
            if (!uad1CastOutOnlyHierophantNeutralizes())
                ++bad;
            if (!uad1CastOutAuraAffectsNaturalCreatures())
                ++bad;
            // the react-adverb lost - a hole
            if (!uad1CastOutReactAdverbLost()) ++bad;
            if (!uad1CastOutAuraIncludesDomesticAndDruids())
                ++bad;
            // the permission ladder
            if (!uad1CastOutNeedsArchdruidPermission())
                ++bad;
            if (!uad1ArchdruidNeedsGreatDruidPermission())
                ++bad;
            if (!uad1GreatDruidNeedsGrandDruidPermission())
                ++bad;
            if (!uad1GrandDruidNeedsNoPermission()) ++bad;
            if (!uad1GrandDruidReversibleByHierophant())
                ++bad;
            if (!uad1CastOutDeniedOrOffsetPunishable())
                ++bad;
            // the unwilling save at -4
            if (uad1CastOutUnwillingSaveMod() != -4) ++bad;
            if (!uad1CeremonyRiteInGroveOrHealthyForest())
                ++bad;
            if (!uad1CeremonyAtDawnOrDusk()) ++bad;
        }
        // U2: detect balance
        {
            if (strcmp(uad1DetectBalanceName(),
                "Detect Balance (Divination)") != 0) ++bad;
            if (!uad1DetectBalanceComponentsVSM()) ++bad;
            // the clean "Level: 1" cell
            if (uad1DetectBalanceLevel() != 1) ++bad;
            // the "7 segment" family decode
            if (uad1DetectBalanceCastingTimeSegments() != 1)
                ++bad;
            // the empty range cell - a hole
            if (!uad1DetectBalanceRangeLost()) ++bad;
            if (!uad1DetectBalanceSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad1DetectBalanceDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad1DetectBalanceAoeOnePerRound()) ++bad;
            if (!uad1DetectBalanceDetectsNonNeutralForces())
                ++bad;
            if (!uad1DetectBalancePartlyNeutralMildAura())
                ++bad;
            if (!uad1DetectBalanceNoNeutralPartStrongAura())
                ++bad;
            if (!uad1DetectBalanceNotExactAlignment()) ++bad;
            if (!uad1DetectBalanceSameStrengthForSameNeutrality())
                ++bad;
            if (!uad1DetectBalanceNoAuraOnPlainItems())
                ++bad;
            if (!uad1DetectBalanceWorksOnAlignedMagicItem())
                ++bad;
            if (!uad1DetectBalanceUnknowableAlignmentBlocks())
                ++bad;
            if (!uad1DetectBalanceTrueNeutralSmoothAura())
                ++bad;
        }
        // U3: detect poison
        {
            if (strcmp(uad1DetectPoisonName(),
                "Detect Poison (Divination)") != 0) ++bad;
            if (!uad1DetectPoisonComponentsVSM()) ++bad;
            // the "Level: 7" family decode
            if (uad1DetectPoisonLevel() != 1) ++bad;
            if (!uad1DetectPoisonRangeZero()) ++bad;
            if (uad1DetectPoisonCastingTimeRounds() != 1)
                ++bad;
            if (!uad1DetectPoisonSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad1DetectPoisonDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad1DetectPoisonAoeSpecial()) ++bad;
            if (!uad1DetectPoisonOpenerScrambleDecoded())
                ++bad;
            if (uad1DetectPoisonScanVolumeCubicYards() != 1)
                ++bad;
            if (!uad1DetectPoisonPortionNotWholePond())
                ++bad;
            if (uad1DetectPoisonTypeChancePctPerLevel() != 5)
                ++bad;
            // the three poison types
            if (uad1DetectPoisonTypeCount() != 3) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(0),
                "Contact (Insinuative)") != 0) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(1),
                "Ingestive") != 0) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(2),
                "Respirative (Gas)") != 0) ++bad;
            if (!uad1DetectPoisonOneFailureEndsTypeDetection())
                ++bad;
            if (!uad1DetectPoisonMaterialMistletoe()) ++bad;
            if (!uad1DetectPoisonMaterialYewLeaf()) ++bad;
            if (!uad1DetectPoisonYewLeafTurnsBrown()) ++bad;
            if (!uad1DetectPoisonSeveralLeavesNeeded())
                ++bad;
        }
        // U4: precipitation
        {
            if (strcmp(uad1PrecipName(),
                "Precipitation") != 0) ++bad;
            // the name header and school never
            // print - holes
            if (!uad1PrecipNameHeaderLost()) ++bad;
            if (!uad1PrecipSchoolLost()) ++bad;
            if (!uad1PrecipIdenticalToClerical()) ++bad;
            if (!uad1PrecipComponentsVSM()) ++bad;
            // the "Level: 7" family decode
            if (uad1PrecipLevel() != 1) ++bad;
            if (uad1PrecipCastingTimeSegments() != 3) ++bad;
            // the empty range cell - a hole
            if (!uad1PrecipRangeLost()) ++bad;
            if (!uad1PrecipSaveNoneAndSpecial()) ++bad;
            // the "1 segment/ievel" decode
            if (uad1PrecipDurationSegmentsPerLevel() != 1)
                ++bad;
            if (uad1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (uad1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (!uad1PrecipAddsMistletoeToClerical()) ++bad;
            // the R343 clerical seam: the
            // cylinder dims match the clerical
            // precipitation pin
            if (uad1PrecipCylinderDiameterInches()
                != uac1PrecipCylinderDiameterInches()) ++bad;
            if (uad1PrecipCylinderHeightInches()
                != uac1PrecipCylinderHeightInches()) ++bad;
        }
        // U5: the R341 table seam
        {
            // the druid 1st-level table prints
            // the four PHB names - none of the
            // four new names seam-checks;
            // they pin from the prose alone
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(0),
                "Locate Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(1),
                "Invisibility to Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(2),
                "Shillelagh") != 0) ++bad;
            if (strcmp(uastDruid1stName(3),
                "Speak With Animals") != 0) ++bad;
        }
        printf("R350 UA druid 1st level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R350 audit')
s = rd(RT)
assert s.count(
    'R350 UA druid 1st level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 277, 'd census 277'
assert s.count(
    'R349 UA cleric 7th level spells'
    ' pin audit: bad ') == 1, 'd r349 kept'
assert s.count(
    'R348 UA cleric 6th level spells'
    ' pin audit: bad ') == 1, 'd r348 kept'
assert s.count(
    'R347 UA cleric 5th level spells'
    ' pin audit: bad ') == 1, 'd r347 kept'
assert s.count(
    'R346 UA cleric 4th level spells'
    ' pin audit: bad ') == 1, 'd r346 kept'
assert s.count(
    'R345 UA cleric 3rd level spells'
    ' pin audit: bad ') == 1, 'd r345 kept'
assert s.count(
    'R344 UA cleric 2nd level spells'
    ' pin audit: bad ') == 1, 'd r344 kept'
assert s.count(
    'R343 UA cleric 1st level spells'
    ' pin audit: bad ') == 1, 'd r343 kept'
assert s.count('R227: the wis mental save') == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uadruidspells1.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R350 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R350 note: the UA new druid spells')
print('pin round, the 1st level - the four')
print('spell descriptions (ceremony with')
print('the nine varieties and the cast-out')
print('permission ladder, detect balance,')
print('detect poison with the yew leaf,')
print('precipitation with the name header')
print('lost - identified via the R343')
print('clerical pin); the family decodes')
print('the three 7s as 1; the R341 druid')
print('table prints the four PHB names -')
print('none of the new names seam-checks;')
print('the item stays open (the 2nd-7th')
print('levels); the census 276 -> 277')
print('commit: R350: the UA new druid 1st')
print('level spells pin round (census 277)')

