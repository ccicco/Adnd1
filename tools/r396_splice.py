#!/usr/bin/env python3
# R396: the UA new-potions prose
# completion - the R376 remainder
# fills, the item closes.
#
# The clean PDF read (pp. 90-91,
# the same clean OCR as R394/R395)
# delivers the seven descriptions
# the extract garbled: the oils
# of acid resistance,
# disenchantment, elemental
# invulnerability, impact, and
# the philters of beauty,
# glibness, stammering and
# stuttering.
#
# 1. rules/uapotprose.h (R376):
#    seven description sections
#    pin (~46 accessors); the part
#    ledger flips 12/7 -> 19/0;
#    the header note closes.
# 2. regtest.cpp: the R376 ledger
#    asserts and the R377 seam
#    flip to the filled reads (the
#    R391b precedent); a new R396
#    audit block lands before the
#    R227 anchor; the census
#    322 -> 323.
# 3. tools/ua_gap_report.md: the
#    new-potions item flips
#    AMENDED R396: closed.
# 4. The seed takes the R395
#    record.
import io

NL = chr(10)
BS = chr(92)
NN = BS + 'n'

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def B(*lines):
    return NL.join(lines) + NL


def die(msg):
    raise SystemExit('R396 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def flipall(path, old, new, expect, label):
    s = rd(path)
    if s.count(new) == expect:
        already.append(label)
        return
    n = s.count(old)
    if n != expect:
        die('%s: old text count %d, expected %d'
            % (label, n, expect))
    wr(path, s.replace(old, new))
    applied.append(label)


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = B(
    '- R395 landed 2026-10-13: commit',
    '  1278168 (census 322, preflight',
    '  GREEN), the UA Treasure Table',
    '  III row bodies: the clean pp.',
    '  84-89 read delivers every row',
    '  body of all TWENTY-ONE tables',
    '  (573 rows, perfect 1-100',
    '  contiguity) - NEW',
    '  rules/uadetrows.h (23',
    '  accessors, flattened arrays:',
    '  dice bands, names, marks,',
    '  the x.p./g.p. columns as lo/',
    '  hi pairs with the -1 none',
    '  sentinel); the R375 skeleton',
    '  flips (row-bodies-garble',
    '  false x15 regtest sites; the',
    '  seventh misc sub-table name',
    '  III.E.7 reads clean) and the',
    '  category names correct to',
    '  Rings/Swords (the R375',
    '  extract read them singular);',
    '  both gap items flip AMENDED',
    '  R395: closed - the UA report',
    '  has no open table items. The',
    '  generator stack (gen/emit/',
    '  audit/build/sim) emits the',
    '  header, the audit and the',
    '  splice from rows.json. The',
    '  ./nn save hash diverged for',
    '  the third round running yet',
    '  the copy passed the battery -',
    '  stable and benign; the md5',
    '  stays advisory.').rstrip(NL)
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R395 landed 2026-10-13' in s:
    already.append('seed: the R395 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R395 record')
s = rd(SD)
if s.count('R395 landed 2026-10-13') != 1:
    die('the R395 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) uapotprose.h ============
PP = 'rules/uapotprose.h'

pair(PP, B(
    '// ventriloquism, vitality. The',
    '// seven garbled descriptions',
    '// (acid resistance,',
    '// disenchantment, elemental,',
    '// impact, the philters of',
    '// beauty and glibness,',
    '// stammering) await the PDF -',
    '// the gap item stays open.'
    ' The').rstrip(NL),
    B(
    '// ventriloquism, vitality. The',
    '// seven PDF-gated fills',
    '// landed R396 (acid',
    '// resistance, disenchantment,',
    '// elemental, impact, the',
    '// philters of beauty,',
    '// glibness, stammering) -',
    '// the gap item closed.'
    ' The').rstrip(NL),
    'potprose: the header note')

FILLS = B(
    '// ---- the oil of acid',
    '// resistance (the R396 clean',
    '// read) ----',
    '// Confers virtual',
    '// invulnerability to acid on',
    '// skin, cloth, or any other',
    '// material; one application',
    '// lasts a full day, but each',
    '// acid exposure eats the',
    '// remaining potency by as',
    '// many minutes as the acid',
    '// would have caused hit',
    '// points of damage to',
    '// exposed flesh.',
    'inline bool uappAcidResCoversAnyMaterial()',
    '    { return true; }',
    '',
    'inline int uappAcidResDurationHours()',
    '    { return 24; }',
    '',
    '// The largest black dragon',
    '// example: 64 minutes lost,',
    '// 32 with a save versus',
    '// breath weapon.',
    'inline int uappAcidResBigBlackMinutes()',
    '    { return 64; }',
    '',
    'inline int uappAcidResBigBlackSavedMinutes()',
    '    { return 32; }',
    '',
    '// One flask: one man-sized',
    '// creature for 24 hours, or',
    '// 24 creatures for one hour -',
    '// any combination between.',
    'inline int uappAcidResOneManSizeHours()',
    '    { return 24; }',
    '',
    'inline int uappAcidResOneHourCreatures()',
    '    { return 24; }',
    '',
    '// A horse is equivalent to',
    '// eight man-sized creatures.',
    'inline int uappAcidResHorseEqualsMen()',
    '    { return 8; }',
    '',
    '// ---- the oil of',
    '// disenchantment (the R396',
    '// clean read) ----',
    '// Removes all enchantment/',
    '// charm dweomers placed upon',
    '// living things; rubbed on an',
    '// object, the object\'s dweomer',
    '// is lost for 21-30 turns',
    '// (d10 + 20),',
    '// then returns once the oil',
    '// has lost its potency. The',
    '// oil radiates no magic and',
    '// masks the dweomer of',
    '// whatever it coats while',
    '// effective.',
    'inline bool uappDisenRemovesFromLiving()',
    '    { return true; }',
    '',
    'inline int uappDisenLostTurnsLo()',
    '    { return 21; }',
    '',
    'inline int uappDisenLostTurnsHi()',
    '    { return 30; }',
    '',
    'inline bool uappDisenItemRegainsDweomer()',
    '    { return true; }',
    '',
    'inline bool uappDisenRadiatesMagic()',
    '    { return false; }',
    '',
    'inline bool uappDisenMasksDweomer()',
    '    { return true; }',
    '',
    '// ---- the oil of elemental',
    '// invulnerability (the R396',
    '// clean read) ----',
    '// Equal chances of the four',
    '// basic sorts (air, earth,',
    '// fire, water - roll d4);',
    '// total invulnerability to',
    '// normal elemental forces on',
    '// the Prime Material Plane;',
    '// elemental creatures still',
    '// damage at -1 per die.',
    'inline int uappElemInvSortCount()',
    '    { return 4; }',
    '',
    'inline int uappElemInvSortDieSides()',
    '    { return 4; }',
    '',
    'inline bool uappElemInvNormalElementalProof()',
    '    { return true; }',
    '',
    '// A 10% chance any container',
    '// is usable on any Elemental',
    '// or Paraelemental Plane.',
    'inline int uappElemInvPlaneUsablePct()',
    '    { return 10; }',
    '',
    'inline int uappElemInvMonsterDamagePerDie()',
    '    { return -1; }',
    '',
    '// One individual for eight',
    '// days, or eight individuals',
    '// for one day.',
    'inline int uappElemInvCoverageIndividuals()',
    '    { return 8; }',
    '',
    'inline int uappElemInvCoverageDays()',
    '    { return 8; }',
    '',
    '// ---- the oil of impact (the',
    '// R396 clean read) ----',
    '// Charges blunt weapons and',
    '// missiles - hurled hammers,',
    '// hurled clubs, sling stones,',
    '// sling bullets - with a',
    '// powerful dweomer; a flask',
    '// holds 3-5 applications; a',
    '// hand-held weapon keeps the',
    '// dweomer 9-12 rounds, a',
    '// missile carries a single',
    '// charge.',
    'inline bool uappImpactBluntAndMissiles()',
    '    { return true; }',
    '',
    'inline int uappImpactMissileKindCount()',
    '    { return 4; }',
    '',
    'inline int uappImpactApplicationsLo()',
    '    { return 3; }',
    '',
    'inline int uappImpactApplicationsHi()',
    '    { return 5; }',
    '',
    'inline int uappImpactHandRoundsLo()',
    '    { return 9; }',
    '',
    'inline int uappImpactHandRoundsHi()',
    '    { return 12; }',
    '',
    'inline bool uappImpactMissileSingleCharge()',
    '    { return true; }',
    '',
    '// One application treats 4-5',
    '// sling missiles or 2 larger',
    '// weapons.',
    'inline int uappImpactSlingPerAppLo()',
    '    { return 4; }',
    '',
    'inline int uappImpactSlingPerAppHi()',
    '    { return 5; }',
    '',
    'inline int uappImpactLargerWeaponsPerApp()',
    '    { return 2; }',
    '',
    '// The hand weapon gains +3 to',
    '// hit and +6 damage; missiles',
    '// are +3 both.',
    'inline int uappImpactHandHitBonus()',
    '    { return 3; }',
    '',
    'inline int uappImpactHandDamageBonus()',
    '    { return 6; }',
    '',
    'inline int uappImpactMissileHitBonus()',
    '    { return 3; }',
    '',
    'inline int uappImpactMissileDamageBonus()',
    '    { return 3; }',
    '',
    '// ---- the philter of beauty',
    '// (the R396 clean read) ----',
    '// +1 charisma (18 maximum) and',
    '// +1 to +4 comeliness for the',
    '// duration; if the effects wear',
    '// off within sight of a',
    '// creature influenced by the',
    '// enhanced scores, that',
    '// creature turns hostile and',
    '// attacks.',
    'inline int uappBeautyChaBonus()',
    '    { return 1; }',
    '',
    'inline int uappBeautyChaMax()',
    '    { return 18; }',
    '',
    'inline int uappBeautyComelinessLo()',
    '    { return 1; }',
    '',
    'inline int uappBeautyComelinessHi()',
    '    { return 4; }',
    '',
    'inline bool uappBeautyWearOffSightedHostile()',
    '    { return true; }',
    '',
    '// ---- the philter of',
    '// glibness (the R396 clean',
    '// read) ----',
    '// The imbiber speaks fluently',
    '// - even lies - smoothly and',
    '// undetectably; magical',
    '// investigation gives altered',
    '// results, revealing only a',
    '// minor stretching of the',
    '// truth.',
    'inline bool uappGlibSpeechUndetectable()',
    '    { return true; }',
    '',
    'inline bool uappGlibDetectLieShowsStretching()',
    '    { return true; }',
    '',
    '// ---- the philter of',
    '// stammering and stuttering',
    '// (the R396 clean read) ----',
    '// Seems a beneficial draught',
    '// (glibness or',
    '// persuasiveness), but nothing',
    '// meaningful can be said',
    '// properly - spell verbal',
    '// components, scroll text,',
    '// conversation all fail - and',
    '// hearers react at -25%.',
    'inline bool uappStamSeemsBeneficial()',
    '    { return true; }',
    '',
    'inline bool uappStamMeaningfulSpeechFails()',
    '    { return true; }',
    '',
    'inline bool uappStamHitsSpellComponents()',
    '    { return true; }',
    '',
    'inline int uappStamReactionPenaltyPct()',
    '    { return 25; }',
    '').rstrip(NL)

pair(PP, B(
    '// ---- the part ledger ----').rstrip(NL),
    FILLS + NL + NL +
    '// ---- the part ledger ----',
    'potprose: the seven fill sections')

pair(PP, B(
    '// ---- the part ledger ----',
    '// Twelve of the nineteen',
    '// descriptions pin; the seven',
    '// garbled ones stay PDF-gated.',
    'inline int uappPartCleanCount()',
    '    { return 12; }',
    '',
    'inline int uappPartGarbledCount()',
    '    { return 7; }').rstrip(NL),
    B(
    '// ---- the part ledger ----',
    '// All nineteen descriptions',
    '// pin - the R396 clean read',
    '// filled the seven the',
    '// extract garbled.',
    'inline int uappPartCleanCount()',
    '    { return 19; }',
    '',
    'inline int uappPartGarbledCount()',
    '    { return 0; }').rstrip(NL),
    'potprose: the part ledger')

# ============ (c) the gap report ============
GP = 'tools/ua_gap_report.md'

pair(GP, B(
    '        stammering) - the item',
    '        stays OPEN, PDF-gated',
    '        for the garbled',
    '        remainder.',
    '- [ ] **The new scrolls**'
    ' (pp. 91-93).').rstrip(NL),
    B(
    '        stammering) - the item',
    '        stays OPEN, PDF-gated',
    '        for the garbled',
    '        remainder.',
    '      - AMENDED R396: closed -',
    '        the clean pp. 90-91 read',
    '        (the same clean PDF as',
    '        R394/R395) fills all',
    '        seven: the oils of acid',
    '        resistance (the 64/32',
    '        black-dragon minutes,',
    '        the horse-equals-eight),',
    '        disenchantment (the',
    '        21-30 lost turns, the',
    '        dweomer masking),',
    '        elemental',
    '        invulnerability (the d4',
    '        sorts, the 10% plane',
    '        chance, the -1 per die),',
    '        impact (the 3-5',
    '        applications, the +3/+6',
    '        hand read), and the',
    '        philters of beauty (the',
    '        +1/+1-4 scores, the',
    '        wear-off hostility),',
    '        glibness (the undetectable',
    '        speech), stammering (the',
    '        -25% reactions) - all',
    '        nineteen descriptions',
    '        pin (rules/uapotprose.h).',
    '- [ ] **The new scrolls**'
    ' (pp. 91-93).').rstrip(NL),
    'gap: the new-potions item')

# ============ (d) regtest.cpp ============
RT = 'regtest.cpp'

pair(RT, B(
    '    // ventriloquism, vitality. The',
    '    // seven garbled descriptions',
    '    // stay PDF-gated. The R375').rstrip(NL),
    B(
    '    // ventriloquism, vitality. The',
    '    // seven garbled descriptions',
    '    // filled by the R396 clean',
    '    // read. The R375').rstrip(NL),
    'regtest R376: the block comment')

flipall(RT,
    'if (uappPartCleanCount() != 12) ++bad;',
    'if (uappPartCleanCount() != 19) ++bad;',
    2, 'regtest: the clean ledger flips')

flipall(RT,
    'if (uappPartGarbledCount() != 7) ++bad;',
    'if (uappPartGarbledCount() != 0) ++bad;',
    2, 'regtest: the garbled ledger flips')

AUD = B(
    '    // ---- R396: the UA potions',
    '    // prose completion pin',
    '    // audit ----',
    '    // The clean read fills the',
    '    // seven PDF-gated',
    '    // descriptions (pp. 90-91):',
    '    // the oils of acid',
    '    // resistance,',
    '    // disenchantment, elemental',
    '    // invulnerability, impact,',
    '    // and the philters of',
    '    // beauty, glibness,',
    '    // stammering - the R376',
    '    // item closes, all nineteen',
    '    // descriptions pin.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the acid resistance ----',
    '            if (!uappAcidResCoversAnyMaterial())',
    '                ++bad;',
    '            if (uappAcidResDurationHours() != 24)',
    '                ++bad;',
    '            if (uappAcidResBigBlackMinutes()',
    '                    != 64) ++bad;',
    '            if (uappAcidResBigBlackSavedMinutes()',
    '                    != 32) ++bad;',
    '            if (uappAcidResOneManSizeHours()',
    '                    != 24) ++bad;',
    '            if (uappAcidResOneHourCreatures()',
    '                    != 24) ++bad;',
    '            if (uappAcidResHorseEqualsMen()',
    '                    != 8) ++bad;',
    '            // the day and the',
    '            // creatures-per-hour',
    '            // trade against the',
    '            // flask',
    '            if (uappAcidResOneManSizeHours()',
    '                    != uappAcidResOneHour'
    'Creatures())',
    '                ++bad;',
    '        // ---- the disenchantment ----',
    '            if (!uappDisenRemovesFromLiving())',
    '                ++bad;',
    '            if (uappDisenLostTurnsLo() != 21)',
    '                ++bad;',
    '            if (uappDisenLostTurnsHi() != 30)',
    '                ++bad;',
    '            // the lost-turns band',
    '            // is d10 + 20',
    '            if (uappDisenLostTurnsHi()',
    '                    - uappDisenLostTurnsLo()',
    '                    != 9) ++bad;',
    '            if (!uappDisenItemRegainsDweomer())',
    '                ++bad;',
    '            if (uappDisenRadiatesMagic()) ++bad;',
    '            if (!uappDisenMasksDweomer()) ++bad;',
    '        // ---- the elemental',
    '        // invulnerability ----',
    '            if (uappElemInvSortCount() != 4)',
    '                ++bad;',
    '            if (uappElemInvSortDieSides()',
    '                    != uappElemInvSortCount())',
    '                ++bad;',
    '            if (!uappElemInvNormalElementalProof())',
    '                ++bad;',
    '            if (uappElemInvPlaneUsablePct()',
    '                    != 10) ++bad;',
    '            if (uappElemInvMonsterDamagePerDie()',
    '                    != -1) ++bad;',
    '            // one for eight days or',
    '            // eight for one day',
    '            if (uappElemInvCoverageIndividuals()',
    '                    != 8) ++bad;',
    '            if (uappElemInvCoverageDays()',
    '                    != uappElemInvCoverage'
    'Individuals())',
    '                ++bad;',
    '        // ---- the impact ----',
    '            if (!uappImpactBluntAndMissiles())',
    '                ++bad;',
    '            if (uappImpactMissileKindCount()',
    '                    != 4) ++bad;',
    '            if (uappImpactApplicationsLo() != 3)',
    '                ++bad;',
    '            if (uappImpactApplicationsHi() != 5)',
    '                ++bad;',
    '            if (uappImpactHandRoundsLo() != 9)',
    '                ++bad;',
    '            if (uappImpactHandRoundsHi() != 12)',
    '                ++bad;',
    '            if (!uappImpactMissileSingleCharge())',
    '                ++bad;',
    '            if (uappImpactSlingPerAppLo() != 4)',
    '                ++bad;',
    '            if (uappImpactSlingPerAppHi() != 5)',
    '                ++bad;',
    '            if (uappImpactLargerWeaponsPerApp()',
    '                    != 2) ++bad;',
    '            if (uappImpactHandHitBonus() != 3)',
    '                ++bad;',
    '            // the hand weapon\'s',
    '            // damage doubles its',
    '            // hit bonus',
    '            if (uappImpactHandDamageBonus()',
    '                    != uappImpactHandHitBonus()',
    '                    * 2) ++bad;',
    '            if (uappImpactMissileHitBonus()',
    '                    != 3) ++bad;',
    '            if (uappImpactMissileDamageBonus()',
    '                    != uappImpactMissileHit'
    'Bonus())',
    '                ++bad;',
    '        // ---- the beauty ----',
    '            if (uappBeautyChaBonus() != 1)',
    '                ++bad;',
    '            if (uappBeautyChaMax() != 18)',
    '                ++bad;',
    '            if (uappBeautyComelinessLo() != 1)',
    '                ++bad;',
    '            if (uappBeautyComelinessHi() != 4)',
    '                ++bad;',
    '            if (!uappBeautyWearOffSightedHostile())',
    '                ++bad;',
    '        // ---- the glibness ----',
    '            if (!uappGlibSpeechUndetectable())',
    '                ++bad;',
    '            if (!uappGlibDetectLieShows'
    'Stretching())',
    '                ++bad;',
    '        // ---- the stammering ----',
    '            if (!uappStamSeemsBeneficial())',
    '                ++bad;',
    '            if (!uappStamMeaningfulSpeech'
    'Fails())',
    '                ++bad;',
    '            if (!uappStamHitsSpellComponents())',
    '                ++bad;',
    '            if (uappStamReactionPenaltyPct()',
    '                    != 25) ++bad;',
    '        // ---- the ledger seam ----',
    '            // the R376/R377 ledger',
    '            // asserts carry the',
    '            // flipped counts; the',
    '            // fills ride here',
    '            if (uappPartCleanCount()',
    '                    + uappPartGarbledCount()',
    '                    != 19) ++bad;',
    '        printf("R396 UA potions prose'
    ' completion pin audit: bad %d'
    + NN + '", bad);',
    '        if (bad) return 1;',
    '    }').rstrip(NL)

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R396 audit block')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 323:
    die('the census %d' % s.count('audit: bad'))
if s.count('R396 UA potions prose completion'
           ' pin audit') != 1:
    die('the R396 audit label')
if s.count('uappPartCleanCount() != 19') != 2:
    die('the flipped clean ledger')
if s.count('uappPartGarbledCount() != 0') != 2:
    die('the flipped garbled ledger')
p = rd(PP)
if p.count('inline') != 118:
    die('the potprose inline count %d'
        % p.count('inline'))
if p.count('return false;') != 2:
    die('the potprose false count %d'
        % p.count('return false;'))
if p.count('uappAcidRes') != 7:
    die('the acid accessor count')
g = rd(GP)
if g.count('AMENDED R396') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R396'))
if g.count('CLOSED R396') != 0:
    die('an unexpected CLOSED R396')

print('R396 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean PDF read fills the'
      ' seven PDF-gated')
print('  potion descriptions - all'
      ' nineteen pin; the')
print('  R376 item closes; census 322 -> 323')
print('commit: R396: the UA new-potions'
      ' prose completion (census 323)')

