#!/usr/bin/env python3
# R348: the UA NEW CLERIC SPELLS
# pin round, the 6th level (p.
# 41) - forbiddance and heroes
# feast; only two spells print at
# this level. The forbiddance
# name header never prints -
# identified by the near-verbatim
# 2e descendant text. The
# digit-garble family (established
# R343) decodes the two 7s as 1,
# both corroborated; the
# forbiddance 6s stay genuine.
# The R341 continued table prints
# four 6th-level fragments -
# neither name seam-checks. The
# item stays open (the 7th level).
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
# ---- (a) the seed: the R347 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R347 landed 2026-10-11: commit',
    '  ed961b6, census 274, the UA',
    '  new cleric spells pin round,',
    '  the 5th level',
    '  (rules/uaclericspells5.h):',
    '  air walk with the ascent and',
    '  descent ladder and the gust',
    '  interplay, animate dead',
    '  monsters, golem with the four',
    '  material ladders, magic font',
    '  with the vial capacity rule,',
    '  rainbow with the four',
    '  applications and the seven',
    '  colors and draughts, and spike',
    '  stones (the prose prints in',
    '  the cleric chapter - the druid',
    '  item seam-checks against this',
    '  pin); the digit-garble family',
    '  decodes the three stat-cell',
    '  7s as 1; the rainbow',
    '  7-missiles and the golem',
    '  7-foot ceiling stay genuine;',
    '  the R341 table prints seven',
    '  fragments - magic font',
    '  seam-checks; the animate dead',
    '  monsters and rainbow Range',
    '  cells and the straw golem SD',
    '  decode are OCR holes - noted',
    '  pending the PDF; GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R347 landed 2026-10-11' in s:
    already.append('seed: the R347 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R347 record')
s = rd(SD)
assert s.count('R347 landed 2026-10-11') == 1,     'a entry'
assert s.count('R346 landed 2026-10-11') == 1,     'a r346 kept'
assert s.count('R345 landed 2026-10-11') == 1,     'a r345 kept'
assert s.count('R344 landed 2026-10-11') == 1,     'a r344 kept'
assert s.count('R343 landed 2026-10-11') == 1,     'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1,     'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1,     'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1,     'a r340 kept'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'
# ---- (b) NEW rules/uaclericspells6.h ----
US = 'rules/uaclericspells6.h'
if os.path.exists(US) and 'R348' in rd(US):
    already.append('uaclericspells6.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaclericspells6.h
// The UA NEW CLERIC SPELLS (p. 41) pins, R348: the 6th-level
// spell descriptions - forbiddance and heroes feast. Only two
// spells print at this level; the 7th (p. 42) pins next round.
// Pin-era pattern (R322): pinned data only - no engine site
// exists. The R341 continued table prints four 6th-level
// fragments (Conjure Animals, Find The Path, Speak With
// Monsters, Stone Tell) - neither of this round's two names
// seam-checks; they pin from the prose alone.
//
// JUDGMENTs (the decode method):
//   - the forbiddance name header never prints: the section
//     runs straight from "## Sixth Level Spells:" into
//     "Components: V, S, M". The spell is identified by its
//     near-verbatim 2e descendant ("This spell can be used to
//     secure a consecrated area... locked by a password",
//     good/evil weighing heavier than law/chaos) as
//     FORBIDDANCE, school Abjuration per the same source -
//     an external decode, flagged *Lost, pending the PDF.
//   - the digit-garble family (established R343, corroborated
//     each round since): the OCR prints 7 where 1 belongs in
//     the stat cells. This round's two 7s decode as 1, BOTH
//     corroborated: heroes feast casting "7 turn" = 1 turn
//     (the later editions print a 10-minute = 1-turn casting
//     time), and heroes feast duration "7 hour" = 1 hour
//     (the prose: "The feast takes one full hour to consume"
//     - the dweomer lasts the hour of the feast).
//   - the forbiddance stat cells carry genuine 6s (not the
//     family): Level 6, Range 3 inches, Casting Time 6
//     rounds, Area of Effect 6 cubic inches per level - the
//     level-matching pattern holds; pinned verbatim.
//   - the forbiddance AoE prints "6 cubic "/level" - the
//     stray straight quote is OCR noise for the inch mark;
//     decoded as 6 cubic inches per level (the game-scale
//     inch, as the range cells).
//   - the curly marks (established R343): the range cells
//     print 3 and 1 with the right double quote; the names
//     print the curly apostrophe (Heroes feast, the caster
//     spell's effect); the pins normalize to ASCII.
//   - the forbiddance prose carries two shattered regions:
//     (1) "Intruders who enter by making saving throws
//     will [?] uneasy and tense" - the verb lost; (2) the
//     material sentence: "In addition to the cler- / include
//     / water, / symbol, / and iron/sulfur" - decoded: in
//     addition to the cleric's [holy/unholy symbol], the
//     components include [holy/unholy] water, the symbol,
//     and iron/sulfur; both regions flagged, sense pinned.
//
// OCR holes (the item stays open - the 7th level pins next
// round; these stay pending the PDF): the forbiddance name
// and school header (externally decoded); the uneasy-verb
// fragment; the material-sentence fragment region.
// ===========================================================================

#pragma once

namespace rules {

// ---- forbiddance (Abjuration, decoded), p. 41 ----
// The name header never prints - identified by the
// near-verbatim 2e descendant text; school per the same.
inline const char* uac6ForbidName()
    { return "Forbiddance (Abjuration)"; }

inline bool uac6ForbidNameHeaderLost()
    { return true; }

inline bool uac6ForbidComponentsVSM()
    { return true; }

inline int uac6ForbidLevel()
    { return 6; }

inline int uac6ForbidRangeInches()
    { return 3; }

// A genuine 6, not the digit-garble family - the level
// pattern holds; pinned verbatim.
inline int uac6ForbidCastingTimeRounds()
    { return 6; }

inline bool uac6ForbidDurationPermanent()
    { return true; }

inline bool uac6ForbidSaveSpecial()
    { return true; }

// The AoE prints "6 cubic "/level" - the stray quote is
// noise for the inch mark.
inline int uac6ForbidAoeCubicInchesPerLevel()
    { return 6; }

// Usable only to secure a consecrated area (cf. the
// ceremony spell).
inline bool uac6ForbidRequiresConsecratedArea()
    { return true; }

inline bool uac6ForbidCfCeremonySpell()
    { return true; }

// The effect on the enchanted area is based on the ethics
// (law/chaos) and morals (good/evil) of those trying to
// enter it, relative to the caster's.
inline bool uac6ForbidBasedOnEthicsAndMorals()
    { return true; }

// Identical morals and ethics: cannot enter the area unless
// the password is known (no saving throw).
inline bool uac6ForbidIdenticalNeedsPassword()
    { return true; }

inline bool uac6ForbidIdenticalNoSave()
    { return true; }

// Different ethics: save versus spell to enter the area;
// if failed, take 2-12 points of damage.
inline bool uac6ForbidDiffEthicsSaveVsSpell()
    { return true; }

inline int uac6ForbidDiffEthicsDamageMin()
    { return 2; }

inline int uac6ForbidDiffEthicsDamageMax()
    { return 12; }

// Different morals: save versus spell to enter the area;
// if failed, take 4-24 points of damage.
inline bool uac6ForbidDiffMoralsSaveVsSpell()
    { return true; }

inline int uac6ForbidDiffMoralsDamageMin()
    { return 4; }

inline int uac6ForbidDiffMoralsDamageMax()
    { return 24; }

// Once a saving throw is failed, an intruder can never
// enter the forbidden area until the dweomer ceases.
inline bool uac6ForbidFailedSaveBarsEntry()
    { return true; }

// Effects are cumulative, and multiple required saving
// throws are certainly possible.
inline bool uac6ForbidEffectsCumulative()
    { return true; }

inline bool uac6ForbidMultipleSavesPossible()
    { return true; }

// The caster is immune to the spell's effect.
inline bool uac6ForbidCasterImmune()
    { return true; }

// Intruders who enter by making saving throws will [verb
// lost] be uneasy and tense, despite their success - the
// fragment region stays a hole.
inline bool uac6ForbidIntrudersUneasyTense()
    { return true; }

inline bool uac6ForbidUneasyVerbFragmentLost()
    { return true; }

// The shattered material sentence decoded: in addition to
// the cleric's symbol, the components include holy/unholy
// water, the symbol, and iron/sulfur.
inline bool uac6ForbidMaterialWaterSymbolIronSulfur()
    { return true; }

inline bool uac6ForbidMaterialFragmentLost()
    { return true; }

inline bool uac6ForbidSeamFragmentsOnly()
    { return true; }

// ---- heroes feast (Evocation), p. 41 ----
// The name prints the curly apostrophe; the pin normalizes
// to ASCII (the established decode).
inline const char* uac6FeastName()
    { return "Heroes' Feast (Evocation)"; }

inline bool uac6FeastComponentsVSM()
    { return true; }

inline int uac6FeastLevel()
    { return 6; }

inline int uac6FeastRangeInches()
    { return 1; }

// The casting time prints "7 turn" - the family decodes
// 1 turn, corroborated by the later editions' 10-minute
// (1-turn) casting time.
inline int uac6FeastCastingTimeTurns()
    { return 1; }

// The duration prints "7 hour" - the family decodes
// 1 hour, corroborated by the one-full-hour prose: the
// dweomer lasts the hour of the feast.
inline int uac6FeastDurationHours()
    { return 1; }

inline bool uac6FeastSaveNone()
    { return true; }

inline bool uac6FeastAoeOnePerLevel()
    { return true; }

// Enables the cleric to bring forth a great feast serving
// as many creatures as the cleric has levels of
// experience.
inline bool uac6FeastServesOnePerLevel()
    { return true; }

// The spell creates a magnificent table, chairs, service,
// and all the necessary food and drink.
inline bool uac6FeastCreatesTableService()
    { return true; }

// Those partaking are cured of all diseases.
inline bool uac6FeastCuresAllDiseases()
    { return true; }

// Immune to poison for 12 hours.
inline int uac6FeastPoisonImmunityHours()
    { return 12; }

// Healed of 5-8 points of damage after imbibing the
// nectar-like beverage.
inline int uac6FeastHealDamageMin()
    { return 5; }

inline int uac6FeastHealDamageMax()
    { return 8; }

// The ambrosia-like food equals a bless spell that lasts
// for 12 hours.
inline bool uac6FeastAmbrosiaEqualsBless()
    { return true; }

inline int uac6FeastBlessHours()
    { return 12; }

// During this period, the consumers are immune to fear,
// hopelessness, and panic.
inline bool uac6FeastImmuneFearHopePanic()
    { return true; }

// The feast takes one full hour to consume; the
// beneficial effects do not set in until after this hour
// is over.
inline int uac6FeastConsumeHours()
    { return 1; }

inline bool uac6FeastEffectsAfterTheHour()
    { return true; }

// If the feast is interrupted for any reason, the spell is
// ruined and all effects of the dweomer are negated.
inline bool uac6FeastInterruptRuinsAll()
    { return true; }

// The material: the holy/unholy symbol and specially
// fermented honey taken from the cells of bee larvae
// destined for royal status.
inline bool uac6FeastMaterialSymbolHoney()
    { return true; }

inline bool uac6FeastHoneyRoyalLarvae()
    { return true; }

// The R341 continued table: the 6th-level column prints
// four fragments (Conjure Animals, Find The Path, Speak
// With Monsters, Stone Tell) - neither of this round's
// two names seam-checks; they pin from the prose alone.
inline bool uac6SpellsPinFromProse()
    { return true; }

}   // namespace rules"""
    assert HDR.count('R348') == 1, 'b tag'
    assert HDR.count('{') - HDR.count('}') == 0, 'b braces'
    assert HDR.count('(') - HDR.count(')') == 0, 'b parens'
    clean(HDR, 78)
    assert HDR.count('namespace rules') == 2, 'b ns'
    assert HDR.count('inline') == 52,        'b inline census'
    wr(US, HDR + NL)
    applied.append('uaclericspells6.h: the pins')
assert os.path.exists(US), 'b exists'
assert rd(US).count('R348') == 1, 'b tag kept'
# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 7th level) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R348: the 6th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        PDF; the 6th-7th levels',
        '        stay open.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R348: the 6th level pinned',
    '        (rules/uaclericspells6.h) -',
    '        forbiddance (the name header',
    '        never prints - identified by',
    '        the 2e descendant text) and',
    '        heroes feast (the twelve-hour',
    '        benefits); the family decodes',
    '        the two 7s as 1 (both',
    '        corroborated); the R341 table',
    '        prints four fragments - neither',
    '        name seam-checks; the name',
    '        header and the two prose',
    '        fragment regions are OCR',
    '        holes - noted pending the PDF;',
    '        the 7th level stays open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R348: the 6th level pinned') == 1,     'c note'
assert s.count('- [ ] **The new cleric spells** (pp.') == 1, 'c stays open'
assert s.count('R347: the 5th level pinned') == 1,     'c r347 kept'
assert s.count('R346: the 4th level pinned') == 1,     'c r346 kept'
assert s.count('R345: the 3rd level pinned') == 1,     'c r345 kept'
assert s.count('R344: the 2nd level pinned') == 1,     'c r344 kept'
assert s.count('R343: the 1st level pinned') == 1,     'c r343 kept'
assert s.count('CLOSED R342') == 1, 'c r342 kept'
assert s.count('R341: the readable tables') == 1,     'c r341 kept'
assert s.count('R340: the fragment-verified') == 1,     'c r340 kept'
assert len(applied) + len(already) == 3, 'c count'
# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R348 UA cleric 6th level spells pin audit' in s:
    already.append('regtest.cpp: the R348 audit')
else:
    INC_ANCH = (
        '#include "rules/uaclericspells5.h"'
        '  // R347: the UA new cleric 5th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaclericspells6.h"'
        '  // R348: the UA new cleric 6th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R348: the UA new cleric 6th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (p. 41), the
    // 6th level - only two spells print at
    // this level: forbiddance (the name
    // header never prints - identified by
    // the near-verbatim 2e descendant; the
    // ethics/morals entry ladder with the
    // password gate) and heroes feast (the
    // twelve-hour benefits and the
    // one-hour consume rule). The
    // digit-garble family decodes this
    // round's two 7s as 1 - both
    // corroborated (the later editions'
    // 1-turn casting time; the one-full-hour
    // prose); the forbiddance 6s stay
    // genuine. The R341 continued table
    // prints four 6th-level fragments -
    // neither name seam-checks. The item
    // stays open (the 7th level).
    {
        using namespace rules;
        int bad = 0;
        // U1: forbiddance
        {
            if (strcmp(uac6ForbidName(),
                "Forbiddance (Abjuration)") != 0) ++bad;
            // the name header never prints - an
            // external decode, a hole
            if (!uac6ForbidNameHeaderLost()) ++bad;
            if (!uac6ForbidComponentsVSM()) ++bad;
            if (uac6ForbidLevel() != 6) ++bad;
            if (uac6ForbidRangeInches() != 3) ++bad;
            // a genuine 6, not the family
            if (uac6ForbidCastingTimeRounds() != 6) ++bad;
            if (!uac6ForbidDurationPermanent()) ++bad;
            if (!uac6ForbidSaveSpecial()) ++bad;
            // the AoE prints "6 cubic "/level"
            if (uac6ForbidAoeCubicInchesPerLevel() != 6)
                ++bad;
            // the consecrated-area gate
            if (!uac6ForbidRequiresConsecratedArea()) ++bad;
            if (!uac6ForbidCfCeremonySpell()) ++bad;
            if (!uac6ForbidBasedOnEthicsAndMorals()) ++bad;
            // the entry ladder
            if (!uac6ForbidIdenticalNeedsPassword()) ++bad;
            if (!uac6ForbidIdenticalNoSave()) ++bad;
            if (!uac6ForbidDiffEthicsSaveVsSpell()) ++bad;
            if (uac6ForbidDiffEthicsDamageMin() != 2) ++bad;
            if (uac6ForbidDiffEthicsDamageMax() != 12)
                ++bad;
            if (!uac6ForbidDiffMoralsSaveVsSpell()) ++bad;
            if (uac6ForbidDiffMoralsDamageMin() != 4) ++bad;
            if (uac6ForbidDiffMoralsDamageMax() != 24)
                ++bad;
            if (!uac6ForbidFailedSaveBarsEntry()) ++bad;
            if (!uac6ForbidEffectsCumulative()) ++bad;
            if (!uac6ForbidMultipleSavesPossible()) ++bad;
            if (!uac6ForbidCasterImmune()) ++bad;
            if (!uac6ForbidIntrudersUneasyTense()) ++bad;
            if (!uac6ForbidUneasyVerbFragmentLost()) ++bad;
            // the shattered material sentence
            if (!uac6ForbidMaterialWaterSymbolIronSulfur())
                ++bad;
            if (!uac6ForbidMaterialFragmentLost()) ++bad;
            if (!uac6ForbidSeamFragmentsOnly()) ++bad;
        }
        // U2: heroes feast
        {
            if (strcmp(uac6FeastName(),
                "Heroes' Feast (Evocation)") != 0) ++bad;
            if (!uac6FeastComponentsVSM()) ++bad;
            if (uac6FeastLevel() != 6) ++bad;
            if (uac6FeastRangeInches() != 1) ++bad;
            // the casting prints "7 turn" - the
            // family decodes 1 turn (corroborated)
            if (uac6FeastCastingTimeTurns() != 1) ++bad;
            // the duration prints "7 hour" - the
            // family decodes 1 hour (corroborated)
            if (uac6FeastDurationHours() != 1) ++bad;
            if (!uac6FeastSaveNone()) ++bad;
            if (!uac6FeastAoeOnePerLevel()) ++bad;
            if (!uac6FeastServesOnePerLevel()) ++bad;
            if (!uac6FeastCreatesTableService()) ++bad;
            // the twelve-hour benefits
            if (!uac6FeastCuresAllDiseases()) ++bad;
            if (uac6FeastPoisonImmunityHours() != 12) ++bad;
            if (uac6FeastHealDamageMin() != 5) ++bad;
            if (uac6FeastHealDamageMax() != 8) ++bad;
            if (!uac6FeastAmbrosiaEqualsBless()) ++bad;
            if (uac6FeastBlessHours() != 12) ++bad;
            if (!uac6FeastImmuneFearHopePanic()) ++bad;
            // the one-hour consume rule
            if (uac6FeastConsumeHours() != 1) ++bad;
            if (!uac6FeastEffectsAfterTheHour()) ++bad;
            if (!uac6FeastInterruptRuinsAll()) ++bad;
            // the material
            if (!uac6FeastMaterialSymbolHoney()) ++bad;
            if (!uac6FeastHoneyRoyalLarvae()) ++bad;
        }
        // U3: the seam
        {
            // the R341 continued table prints four
            // 6th-level fragments
            if (uastClericFragCount(6) != 4) ++bad;
            static const char* const n[4] = {
                "Conjure Animals", "Find The Path",
                "Speak With Monsters", "Stone Tell" };
            for (int i = 0; i < 4; ++i) {
                if (strcmp(uastClericFragName(6, i), n[i])
                    != 0) ++bad;
            }
            // neither of this round's names
            // seam-checks - the pins are from the
            // prose alone
            if (!uac6ForbidSeamFragmentsOnly()) ++bad;
            if (!uac6SpellsPinFromProse()) ++bad;
        }
        printf("R348 UA cleric 6th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    assert AUDIT.count('{') - AUDIT.count('}') == 0, 'd audit braces'
    assert AUDIT.count('(') - AUDIT.count(')') == 0, 'd audit parens'
    assert AUDIT.count('// U') == 3, 'd U tags'
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R348 audit')
s = rd(RT)
assert s.count(
    'R348 UA cleric 6th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 275, 'd census 275'
assert s.count(
    'R347 UA cleric 5th level spells '
    'pin audit: bad ') == 1, 'd r347 kept'
assert s.count(
    'R346 UA cleric 4th level spells '
    'pin audit: bad ') == 1, 'd r346 kept'
assert s.count(
    'R345 UA cleric 3rd level spells '
    'pin audit: bad ') == 1, 'd r345 kept'
assert s.count(
    'R344 UA cleric 2nd level spells '
    'pin audit: bad ') == 1, 'd r344 kept'
assert s.count(
    'R343 UA cleric 1st level spells '
    'pin audit: bad ') == 1, 'd r343 kept'
assert s.count(
    'R342 UA MU and IL tables '
    'pin audit: bad ') == 1, 'd r342 kept'
assert s.count(
    'R341 UA spell tables '
    'pin audit: bad ') == 1, 'd r341 kept'
assert s.count(
    'R340 UA new weapons prose '
    'pin audit: bad ') == 1, 'd r340 kept'
assert s.count('R227: the wis mental save') == 1,     'd r227 kept'
assert s.count(
    '#include "rules/uaclericspells6.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'
# ---- the summary ----
print('R348 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R348 note: the UA new cleric spells')
print('pin round, the 6th level - the two')
print('spell descriptions (forbiddance with')
print('the ethics and morals entry ladder')
print('and the password gate, heroes feast')
print('with the twelve-hour benefits and')
print('the one-hour consume rule); the')
print('digit-garble family decodes the two')
print('7s as 1 (both corroborated); the')
print('forbiddance name header never prints')
print('- identified by the 2e descendant')
print('text; the R341 continued table')
print('prints four fragments - neither name')
print('seam-checks; the name header and the')
print('two prose fragment regions are holes')
print('- noted pending the PDF; the item')
print('stays open (the 7th level); the')
print('census 274 -> 275')
print('commit: R348: the UA new cleric 6th')
print('level spells pin round (census 275)')

