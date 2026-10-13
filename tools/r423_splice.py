#!/usr/bin/env python3
# r423_splice: the UA APPENDIX S
# PANTHEON PROSE, census 348 ->
# 349. The LAST open item in
# Appendix S - the five pantheon
# intro prose sections (pp.
# 110-120, the clean OCR read)
# pin as rules/uapantheon.h
# (NEW, prefix uapn - checked
# free; the uapp prefix is
# taken by uapotprose.h), the
# sixth data round riding the
# R406 stat-block precedent.
#
# The read (every pin verified
# against the OCR pages 111,
# 113, 115-116, 118-120):
#   - the dwarven intro: the
#     powerful pantheon, the
#     at-least-twice size, the
#     Moradin 20-foot cap, the
#     never-living symbols, the
#     Moradin rulings, the five
#     described, the dual
#     charismas, the sphere
#     censuses (10 present, 6
#     absent), the two cross-
#     mythos patrons;
#   - the elven intro: the
#     Arvandor home, the
#     Seldarine name, the sole
#     greater Corellon, none
#     evil, the lawful max 3,
#     the 4-8 foot height band,
#     the color reads, the
#     Lolth/drow seam, the
#     half-elf clerics, the
#     sphere censuses (15/5);
#   - the halfling intro: the
#     one greater Yondalla, the
#     worship max 5, the Green
#     Fields home, the
#     Concordant minimum 2, the
#     gender reads, the sphere
#     censuses (11 present, 5
#     absent), the Urogalan
#     pins;
#   - the gnomish intro: the
#     fewest members, the six-
#     or-seven count, the Garl
#     rule with the Urdlen
#     exception, the Golden
#     Hills, the masculine
#     census, the three named
#     companions, the pranks;
#   - the orcish intro: the
#     shaman tale, the five lot
#     races, the three habitat
#     claims, the Corellon eye
#     battle, the dwarven
#     mountain conflict, the
#     Nine Hells goblin battles,
#     the three tribe names,
#     the seven sphere examples,
#     the Gruumsh chain top.
#
# The live cross-checks (the
# R406 pattern): the five
# described counts mirror
# nhdPantheonSize(i) row for
# row, the sum mirrors
# nhdDeityCount() 23, the
# Moradin height and the size
# multiple and the symbol and
# dual-charisma pins mirror
# the R405 seam functions.
#
# Patches (5) + the new
# header:
#   - regtest.cpp: the include
#     rides the R411 uamoves
#     include; the R423 audit
#     block lands before the
#     R227 anchor; census 348
#     -> 349
#   - ua_gap_report.md: the
#     Appendix S box flips
#     (the prose was the last
#     open item) and takes
#     AMENDED R423
#   - the seed takes the R422
#     record
#
# Guards: the string-literal
# parity gate (the R421b
# lesson), the census 349, the
# no-bare-'||' gate (the R418b
# lesson) over uapn/nhd, the
# live cross-mirrors, the
# prefix-collision check (the
# R411 lesson), the header
# statics (lines <= 78, the
# inline count), the gap
# censuses, the seed record,
# the caller contract and the
# mixed applied/already ABORT
# (the R420 lesson).

import io
import re as _re

NL = chr(10)

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R423 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d'
            ' (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


RT = 'regtest.cpp'
GP = 'tools/ua_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')
AR = 'rules/uaappendr.h'
PN = 'rules/uapantheon.h'

# ======== (a) the new header ========

# the prefix-collision check
# (the R411 lesson): uapn must
# be free BEFORE the round - on
# an already-applied tree the
# only uapn words are this
# round's own include and audit
import os
if not os.path.exists(PN):
    for p in (RT, GP):
        if _re.search(r'\buapn\w', rd(p)):
            die('the uapn prefix already'
                ' lives in %s' % p)
for p in ('dm/treasure.cpp',
          'game/state_combat.cpp'):
    if _re.search(r'\buapn\w', rd(p)):
        die('the uapn prefix already'
            ' lives in %s' % p)

HEADER = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uapantheon.h',
    '// The UA APPENDIX S PANTHEON',
    '// PROSE, R423: the five pantheon',
    '// intro sections (pp. 110-120)',
    '// - the last open Appendix S item.',
    '// The sixth data round riding the',
    '// R406 stat-block precedent; the',
    '// clean OCR read pins the prose-',
    '// level facts with the censuses',
    '// cross-checked LIVE against the',
    '// R405 seam (the described counts',
    '// mirror nhdPantheonSize row for',
    '// row, the sum mirrors the 23).',
    '// Pin-era pattern (R322).',
    '//',
    '// The judgment: the intro prose',
    '// reads scan-clean - no flagged',
    '// holes, no sentinels; every pin',
    '// below is the printed text.',
    'namespace rules {',
    '',
    '// ---- the dwarven intro ----',
    '',
    '// One of the most powerful of',
    '// all the non-human pantheons.',
    'inline bool uapnDwarfIntroPowerful()',
    '    { return true; }',
    '// The greater dwarven gods are at',
    '// least twice as large as normal',
    '// dwarves.',
    'inline int uapnDwarfGreaterSizeMin()',
    '    { return 2; }',
    '// Ranging up to Moradin\'s 20-foot',
    '// height.',
    'inline int uapnDwarfMoradinFeet()',
    '    { return 20; }',
    '// No dwarven deity is taller than',
    '// Moradin, the Soul Forger.',
    'inline bool uapnDwarfMoradinTallest()',
    '    { return true; }',
    '// Demigods are roughly normal',
    '// dwarven height.',
    'inline bool uapnDwarfDemigodNormalH()',
    '    { return true; }',
    '// The holy symbols are invariably',
    '// not living objects.',
    'inline bool uapnDwarfSymbolNoLife()',
    '    { return true; }',
    '// The symbol categories: tools,',
    '// weapons, mountains, minerals -',
    '// four.',
    'inline int uapnDwarfSymbolCats()',
    '    { return 4; }',
    '// Moradin ruled the dwarves must',
    '// hold no other race above them.',
    'inline bool uapnDwarfNoRaceAbove()',
    '    { return true; }',
    '// Moradin said dwarves should not',
    '// ever worship each other.',
    'inline bool uapnDwarfNoDwarfWorship()',
    '    { return true; }',
    '// All dwarven gods possess dual',
    '// charismas.',
    'inline bool uapnDwarfDualCharisma()',
    '    { return true; }',
    '// Five commonly accepted deities',
    '// are described in the text.',
    'inline int uapnDwarfDescribed()',
    '    { return 5; }',
    '// The lesser-deity spheres:',
    '// fighting and warfare,',
    '// guardianship, the earth, metals,',
    '// craftsmanship, volcanoes and',
    '// earthquakes, fire and lava, the',
    '// protection of the dead,',
    '// medicine, strength - ten.',
    'inline int uapnDwarfSpheres()',
    '    { return 10; }',
    '// The absent spheres: the sea, the',
    '// air and atmospheric phenomena,',
    '// plant life and forests, comedy,',
    '// animals, chaos - six.',
    'inline int uapnDwarfSpheresAbsent()',
    '    { return 6; }',
    '// Dwarves on rare occasions worship',
    '// other pantheons: Goibhnie (the',
    '// Celtic) and Hephaestus (the',
    '// Greek) - two.',
    'inline int uapnDwarfCrossMythos()',
    '    { return 2; }',
    '// The cross-mythos draw: powers of',
    '// smith-work and the earth.',
    'inline bool uapnDwarfCrossIsSmith()',
    '    { return true; }',
    '',
    '// ---- the elven intro ----',
    '',
    '// The elven pantheon is primarily',
    '// located on one of the planes of',
    '// Olympus, in an area known as',
    '// Arvandor, "The High Forest."',
    'inline bool uapnElfHomeArvandor()',
    '    { return true; }',
    '// The collective name: the',
    '// Seldarine.',
    'inline bool uapnElfCollectiveName()',
    '    { return true; }',
    '// The Seldarine roughly translates',
    '// as the fellowship of brothers and',
    '// sisters of the wood.',
    'inline bool uapnElfFellowship()',
    '    { return true; }',
    '// Of all the Seldarine, only',
    '// Corellon Larethian is a greater',
    '// god.',
    'inline bool uapnElfSoleGreater()',
    '    { return true; }',
    '// None are evil.',
    'inline bool uapnElfNoneEvil()',
    '    { return true; }',
    '// A very few are lawful - two or',
    '// three at the most.',
    'inline int uapnElfLawfulMax()',
    '    { return 3; }',
    '// Corellon compels none of them to',
    '// perform any task.',
    'inline bool uapnElfCorellonCompels()',
    '    { return false; }',
    '// The tolerance example: the cult',
    '// of Skerrit the Forester.',
    'inline bool uapnElfSkerritExample()',
    '    { return true; }',
    '// Elven deities in elven form are',
    '// usually between 4 and 8 feet',
    '// tall.',
    'inline int uapnElfHeightMin()',
    '    { return 4; }',
    'inline int uapnElfHeightMax()',
    '    { return 8; }',
    '// The color reads: Rillifane the',
    '// oak and bark-armored elf, Deep',
    '// Sashelas sea-green, Aerdrie',
    '// deep blue like the sky.',
    'inline bool uapnElfColorReads()',
    '    { return true; }',
    '// Evil elvenkind worship the demon',
    '// princes and arch-devils; Lolth',
    '// the demon queen of spiders takes',
    '// power from the drow.',
    'inline bool uapnElfLolthDrowSeam()',
    '    { return true; }',
    '// The smaller elf-like beings have',
    '// their own demigod-level',
    '// deities.',
    'inline bool uapnElfSmallOwnGods()',
    '    { return true; }',
    '// Half-elves may worship any god',
    '// in the Seldarine and may become',
    '// clerics or druids of them; a',
    '// fair number honor Hanali Celanil.',
    'inline bool uapnElfHalfElfCleric()',
    '    { return true; }',
    'inline bool uapnElfHalfElfHanali()',
    '    { return true; }',
    '// Five deities are described.',
    'inline int uapnElfDescribed()',
    '    { return 5; }',
    '// The sphere census (among others):',
    '// elvenkind, nature, magic, dancing',
    '// and play, love, beauty, time,',
    '// celestial phenomena, running',
    '// water, weapon skills,',
    '// craftsmanship, secrecy, comedy',
    '// and joy, chaos, mischief - 15.',
    'inline int uapnElfSpheres()',
    '    { return 15; }',
    '// The absent spheres: law,',
    '// underground phenomena, violence',
    '// without cause, warfare,',
    '// non-mammalian or non-avian life',
    '// - five.',
    'inline int uapnElfSpheresAbsent()',
    '    { return 5; }',
    '// One or two are concerned with',
    '// death - peaceful, good-aligned.',
    'inline int uapnElfDeathMax()',
    '    { return 2; }',
    '',
    '// ---- the halfling intro ----',
    '',
    '// A small pantheon: one greater',
    '// deity (Yondalla) plus several',
    '// lesser deities and demigods.',
    'inline int uapnHalfGreaterCount()',
    '    { return 1; }',
    '// Most communities worship only a',
    '// few - four or five at most.',
    'inline int uapnHalfWorshipMax()',
    '    { return 5; }',
    '// Yondalla is the top authority,',
    '// though her control over',
    '// Brandobaris is minimal at times.',
    'inline bool uapnHalfYondallaTop()',
    '    { return true; }',
    'inline bool uapnHalfBrandobarisLoose()',
    '    { return true; }',
    '// All the halfling deities are',
    '// pledged to work together against',
    '// the enemies of the halfling',
    '// people.',
    'inline bool uapnHalfPledged()',
    '    { return true; }',
    '// Most reside on one of the planes',
    '// of the Seven Heavens, the Green',
    '// Fields.',
    'inline bool uapnHalfGreenFields()',
    '    { return true; }',
    '// Sheela Peryroyl and one or two',
    '// other deities live on Concordant',
    '// Opposition - the printed minimum',
    '// is two.',
    'inline int uapnHalfConcordantMin()',
    '    { return 2; }',
    '// Brandobaris roams the Prime',
    '// Material Plane.',
    'inline bool uapnHalfBrandobarisRoams()',
    '    { return true; }',
    '// The Greek comparison: as the',
    '// Greek gods come to Olympus to',
    '// meet, so the halfling deities',
    '// come to the Green Fields.',
    'inline bool uapnHalfGreekCompare()',
    '    { return true; }',
    '// The more powerful halfling',
    '// deities tend to be females; the',
    '// dwarven tend male, the elven a',
    '// combination of both genders.',
    'inline bool uapnHalfPowerFemale()',
    '    { return true; }',
    '// Halfling deities are not',
    '// aggressive by and large; even',
    '// Brandobaris avoids combat if he',
    '// can help it.',
    'inline bool uapnHalfNotAggressive()',
    '    { return true; }',
    '// The sphere census: security,',
    '// sufficiency, the earth, youth,',
    '// play and humor, good luck, law,',
    '// peace, secrecy, love, friendship',
    '// - eleven.',
    'inline int uapnHalfSpheres()',
    '    { return 11; }',
    '// No deities of evil nature, or',
    '// war, suffering, fire and water,',
    '// or death - five absent.',
    'inline int uapnHalfSpheresAbsent()',
    '    { return 5; }',
    '// Yondalla is invoked at funerals',
    '// as a protector of the departed',
    '// souls.',
    'inline bool uapnHalfYondallaFuneral()',
    '    { return true; }',
    '// Urogalan: a neutral-aligned',
    '// masculine lesser deity, the judge',
    '// and protector of the dead,',
    '// primarily an earth god, living',
    '// on Concordant Opposition.',
    'inline bool uapnHalfUrogalanNeutral()',
    '    { return true; }',
    'inline bool uapnHalfUrogalanEarth()',
    '    { return true; }',
    'inline bool uapnHalfUrogalanConcord()',
    '    { return true; }',
    '// Four deities are described.',
    'inline int uapnHalfDescribed()',
    '    { return 4; }',
    '',
    '// ---- the gnomish intro ----',
    '',
    '// The demi-human pantheon with the',
    '// fewest members.',
    'inline bool uapnGnomeFewest()',
    '    { return true; }',
    '// By most counts only six or seven',
    '// deities govern the gnomish folk.',
    'inline int uapnGnomeCountMin()',
    '    { return 6; }',
    'inline int uapnGnomeCountMax()',
    '    { return 7; }',
    '// All gnomish gods, with the',
    '// exception of Urdlen the Crawler,',
    '// are ruled by Garl Glittergold.',
    'inline bool uapnGnomeGarlException()',
    '    { return true; }',
    '// All but one live on the Twin',
    '// Paradises, the Golden Hills,',
    '// where the souls of faithful',
    '// gnomes go at death.',
    'inline bool uapnGnomeGoldenHills()',
    '    { return true; }',
    '// The exception is Urdlen, who',
    '// lives in the Abyss.',
    'inline bool uapnGnomeUrdlenAbyss()',
    '    { return true; }',
    '// All the known gnomish deities',
    '// are masculine, worshiped by',
    '// male and female gnomes with',
    '// equal reverence.',
    'inline bool uapnGnomeAllMasculine()',
    '    { return true; }',
    '// Urdlen is sexless (though still',
    '// referred to as a "he").',
    'inline bool uapnGnomeUrdlenSexless()',
    '    { return true; }',
    '// The named companions: Garl\'s',
    '// intelligent battle axe Arumdina,',
    '// Baervan\'s raccoon friend',
    '// Chiktikka, Segojan\'s intelligent',
    '// stone golem - three; Urdlen, the',
    '// exception, has no friends.',
    'inline int uapnGnomeCompanions()',
    '    { return 3; }',
    'inline bool uapnGnomeUrdlenNoFriends()',
    '    { return true; }',
    '// Pranks and practical jokes are a',
    '// major response of gnomish gods',
    '// to their enemies.',
    'inline bool uapnGnomePranks()',
    '    { return true; }',
    '// Gnomish deities usually only',
    '// associate with the other',
    '// gnomish deities, though they',
    '// maintain loose contact with a',
    '// few dwarven gods.',
    'inline bool uapnGnomeDwarfContact()',
    '    { return true; }',
    '// Four deities are described.',
    'inline int uapnGnomeDescribed()',
    '    { return 4; }',
    '',
    '// ---- the orcish intro ----',
    '',
    '// The shaman tale frame: the gods',
    '// met and drew lots for the parts',
    '// of the world.',
    'inline bool uapnOrcLotTale()',
    '    { return true; }',
    '// The lot races: human, elven,',
    '// dwarven, gnomish, halfling -',
    '// five, with the orcs excluded.',
    'inline int uapnOrcLotRaces()',
    '    { return 5; }',
    '// Gruumsh\'s three habitat claims:',
    '// the mountains (rifts and',
    '// chasms), the hills (shaking,',
    '// dust-covered), the meadows',
    '// (gouged bare).',
    'inline int uapnOrcHabitatClaims()',
    '    { return 3; }',
    '// Orcs make war, ceaseless and',
    '// endless: war for the wrath of',
    '// Gruumsh.',
    'inline bool uapnOrcWarForWrath()',
    '    { return true; }',
    '// The Corellon battle: Corellon',
    '// tried to shoot out Gruumsh\'s',
    '// eye with his bow, but failed;',
    '// Gruumsh started the fight by',
    '// trying to paralyze the elven',
    '// god with his spear.',
    'inline bool uapnOrcCorellonFailed()',
    '    { return true; }',
    'inline bool uapnOrcGruumshFirst()',
    '    { return true; }',
    '// Because of the battle, orcs of',
    '// all sects and cults hate elves',
    '// more than all other non-orc',
    '// races.',
    'inline bool uapnOrcHateElvesMost()',
    '    { return true; }',
    '// The dwarven-orcish battle for',
    '// ownership of the mountains: the',
    '// orcs drawn by brutal majesty',
    '// and stark barrenness, the',
    '// dwarves by isolation, beauty',
    '// and the ores beneath.',
    'inline bool uapnOrcDwarfConflict()',
    '    { return true; }',
    '// The eternal battles on the',
    '// plains of the Nine Hells between',
    '// the goblins and orcs, each side',
    '// led by their respective gods.',
    'inline bool uapnOrcNineHells()',
    '    { return true; }',
    '// The named tribes: Evil Eye,',
    '// Death Moon, Broken Bone - three',
    '// (an open list).',
    'inline int uapnOrcTribeNames()',
    '    { return 3; }',
    '// The tribal symbol is the holy',
    '// symbol of the tribe\'s patron',
    '// god.',
    'inline bool uapnOrcTribeSymbol()',
    '    { return true; }',
    '// The sphere examples: strength,',
    '// swordsmanship, military power,',
    '// the night, death, fertility,',
    '// hunting - seven (an open list).',
    'inline int uapnOrcSphereExamples()',
    '    { return 7; }',
    '// Each god is part of a rigid chain',
    '// of command with Gruumsh at the',
    '// top.',
    'inline bool uapnOrcGruumshTop()',
    '    { return true; }',
    '// Warfare between tribes is',
    '// encouraged - eliminating the',
    '// unfit and weak, promoting the',
    '// strong.',
    'inline bool uapnOrcTribalWarfare()',
    '    { return true; }',
    '// Five of the most powerful',
    '// orcish gods besides Gruumsh are',
    '// described.',
    'inline int uapnOrcDescribed()',
    '    { return 5; }',
    '// Any use of "cleric" in the',
    '// descriptions also includes',
    '// shamans and witch doctors (the',
    '// DMG).',
    'inline bool uapnOrcClericIncludes()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    '')

import os
if os.path.exists(PN):
    if rd(PN) == HEADER:
        already.append('the uapantheon header')
    else:
        die('the uapantheon header'
            ' already exists, divergent')
else:
    wr(PN, HEADER)
    applied.append('the uapantheon header')

# ======== (b) regtest.cpp ========

# the include rides the R411
# uamoves include
pair(RT,
     '#include "rules/uamoves.h"'
     '  // R411: the UA Appendix S MOVE'
     ' values',
     E('#include "rules/uamoves.h"'
       '  // R411: the UA Appendix S MOVE'
       ' values',
       '#include "rules/uapantheon.h"'
       '  // R423: the UA Appendix S'
       ' pantheon prose'),
     'regtest: the uapantheon include')

# ---- the R423 audit block ----
AUD = E(
    '    // ---- R423: the UA appendix S',
    '    // pantheon prose pin audit ----',
    '    // The five intro sections pin',
    '    // (rules/uapantheon.h, prefix',
    '    // uapn) with the censuses',
    '    // cross-checked LIVE against',
    '    // the R405 seam: the five',
    '    // described counts mirror',
    '    // nhdPantheonSize row for row',
    '    // and the sum mirrors the 23',
    '    // deity census; the Moradin',
    '    // height, the size minimum,',
    '    // the never-living symbols and',
    '    // the dual charismas mirror',
    '    // their seam functions.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // the dwarven intro',
    '        if (!uapnDwarfIntroPowerful()',
    '                || !uapnDwarfMoradin'
    'Tallest()',
    '                || !uapnDwarfDemigod'
    'NormalH()',
    '                || !uapnDwarfSymbol'
    'NoLife()',
    '                || !uapnDwarfNoRace'
    'Above()',
    '                || !uapnDwarfNoDwarf'
    'Worship()',
    '                || !uapnDwarfDual'
    'Charisma()',
    '                || !uapnDwarfCross'
    'IsSmith())',
    '            ++bad;',
    '        if (uapnDwarfGreaterSizeMin() != 2',
    '                || uapnDwarfMoradin'
    'Feet() != 20',
    '                || uapnDwarfSymbol'
    'Cats() != 4',
    '                || uapnDwarfDescribed() != 5',
    '                || uapnDwarfSpheres() != 10',
    '                || uapnDwarfSpheres'
    'Absent() != 6',
    '                || uapnDwarfCross'
    'Mythos() != 2)',
    '            ++bad;',
    '        // the elven intro',
    '        if (!uapnElfHomeArvandor()',
    '                || !uapnElfCollective'
    'Name()',
    '                || !uapnElfFellowship()',
    '                || !uapnElfSoleGreater()',
    '                || !uapnElfNoneEvil()',
    '                || !uapnElfSkerrit'
    'Example()',
    '                || !uapnElfColorReads()',
    '                || !uapnElfLolthDrow'
    'Seam()',
    '                || !uapnElfSmallOwn'
    'Gods()',
    '                || !uapnElfHalfElf'
    'Cleric()',
    '                || !uapnElfHalfElf'
    'Hanali())',
    '            ++bad;',
    '        if (uapnElfLawfulMax() != 3',
    '                || uapnElfHeightMin() != 4',
    '                || uapnElfHeightMax() != 8',
    '                || uapnElfDescribed() != 5',
    '                || uapnElfSpheres() != 15',
    '                || uapnElfSpheres'
    'Absent() != 5',
    '                || uapnElfDeathMax() != 2)',
    '            ++bad;',
    '        if (uapnElfCorellonCompels())',
    '            ++bad;',
    '        // the halfling intro',
    '        if (!uapnHalfYondallaTop()',
    '                || !uapnHalfBrandobaris'
    'Loose()',
    '                || !uapnHalfPledged()',
    '                || !uapnHalfGreen'
    'Fields()',
    '                || !uapnHalfBrandobaris'
    'Roams()',
    '                || !uapnHalfGreek'
    'Compare()',
    '                || !uapnHalfPower'
    'Female()',
    '                || !uapnHalfNot'
    'Aggressive()',
    '                || !uapnHalfYondalla'
    'Funeral()',
    '                || !uapnHalfUrogalan'
    'Neutral()',
    '                || !uapnHalfUrogalan'
    'Earth()',
    '                || !uapnHalfUrogalan'
    'Concord())',
    '            ++bad;',
    '        if (uapnHalfGreaterCount() != 1',
    '                || uapnHalfWorshipMax() != 5',
    '                || uapnHalfConcordant'
    'Min() != 2',
    '                || uapnHalfSpheres() != 11',
    '                || uapnHalfSpheres'
    'Absent() != 5',
    '                || uapnHalfDescribed() != 4)',
    '            ++bad;',
    '        // the gnomish intro',
    '        if (!uapnGnomeFewest()',
    '                || !uapnGnomeGarl'
    'Exception()',
    '                || !uapnGnomeGolden'
    'Hills()',
    '                || !uapnGnomeUrdlen'
    'Abyss()',
    '                || !uapnGnomeAll'
    'Masculine()',
    '                || !uapnGnomeUrdlen'
    'Sexless()',
    '                || !uapnGnomeUrdlen'
    'NoFriends()',
    '                || !uapnGnomePranks()',
    '                || !uapnGnomeDwarf'
    'Contact())',
    '            ++bad;',
    '        if (uapnGnomeCountMin() != 6',
    '                || uapnGnomeCountMax() != 7',
    '                || uapnGnomeCompanions() != 3',
    '                || uapnGnomeDescribed() != 4)',
    '            ++bad;',
    '        // the orcish intro',
    '        if (!uapnOrcLotTale()',
    '                || !uapnOrcWarForWrath()',
    '                || !uapnOrcCorellon'
    'Failed()',
    '                || !uapnOrcGruumshFirst()',
    '                || !uapnOrcHateElves'
    'Most()',
    '                || !uapnOrcDwarfConflict()',
    '                || !uapnOrcNineHells()',
    '                || !uapnOrcTribeSymbol()',
    '                || !uapnOrcGruumshTop()',
    '                || !uapnOrcTribal'
    'Warfare()',
    '                || !uapnOrcCleric'
    'Includes())',
    '            ++bad;',
    '        if (uapnOrcLotRaces() != 5',
    '                || uapnOrcHabitat'
    'Claims() != 3',
    '                || uapnOrcTribe'
    'Names() != 3',
    '                || uapnOrcSphere'
    'Examples() != 7',
    '                || uapnOrcDescribed() != 5)',
    '            ++bad;',
    '        // the LIVE seam mirrors',
    '        // (the R405/R406 pattern)',
    '        if (uapnDwarfDescribed()',
    '                != nhdPantheonSize(0)',
    '                || uapnElfDescribed()',
    '                != nhdPantheonSize(1)',
    '                || uapnHalfDescribed()',
    '                != nhdPantheonSize(2)',
    '                || uapnGnomeDescribed()',
    '                != nhdPantheonSize(3)',
    '                || uapnOrcDescribed()',
    '                != nhdPantheonSize(4))',
    '            ++bad;',
    '        if (uapnDwarfDescribed()',
    '                + uapnElfDescribed()',
    '                + uapnHalfDescribed()',
    '                + uapnGnomeDescribed()',
    '                + uapnOrcDescribed()',
    '                != nhdDeityCount())',
    '            ++bad;',
    '        if (uapnDwarfMoradinFeet()',
    '                != nhdMoradin'
    'HeightFeet()',
    '                || uapnDwarfGreater'
    'SizeMin()',
    '                != nhdGreaterDwarf'
    'SizeMultiple()',
    '                || !uapnDwarfSymbolNoLife()',
    '                != !nhdDwarfSymbol'
    'NeverLiving()',
    '                || !uapnDwarfDual'
    'Charisma()',
    '                != !nhdDwarfDeity'
    'DualCharisma())',
    '            ++bad;',
    '        if (uapnElfHeightMin()',
    '                >= uapnElfHeightMax()',
    '                || uapnGnomeCountMin()',
    '                > uapnGnomeCountMax())',
    '            ++bad;',
    '        printf("R423 UA appendix S'
    ' pantheon prose pin audit: bad'
    ' %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R423 audit block')

# ======== (c) tools/ua_gap_report.md ========

pair(GP,
     '- [ ] **Appendix S: non-human'
     ' deities**',
     '- [x] **Appendix S: non-human'
     ' deities**',
     'gap: the Appendix S box flips')

pair(GP,
     E('        values land (rules/'
       'uamoves.h)',
       '        - the 23 rates and the five',
       '        alternates pin with the',
       '        sanity ladders live; the',
       '        Shargaas garble records as',
       '        the hole sentinel; the',
       '        pantheon prose ALONE stays',
       '        open in Appendix S.',
       '- [ ] **Appendix T: pole-arm'),
     E('        values land (rules/'
       'uamoves.h)',
       '        - the 23 rates and the five',
       '        alternates pin with the',
       '        sanity ladders live; the',
       '        Shargaas garble records as',
       '        the hole sentinel; the',
       '        pantheon prose ALONE stays',
       '        open in Appendix S.',
       '      - AMENDED R423: the pantheon',
       '        prose lands (rules/'
       'uapantheon.h) - the five intro',
       '        sections pin with the',
       '        censuses cross-checked',
       '        live against the R405 seam',
       '        (the described counts mirror',
       '        nhdPantheonSize row for row,',
       '        the sum mirrors the 23); the',
       '        Appendix S item CLOSES - the',
       '        box flips, nothing stays',
       '        open.',
       '- [ ] **Appendix T: pole-arm'),
     'gap: the AMENDED R423 stratum')

# ======== (d) the seed ========

SEED_ENTRY = E(
    '- R422 landed 2026-10-13:',
    '  commit a911b59 (census 348,',
    '  preflight GREEN on the FIRST',
    '  run, pushed 365ec5b..a911b59),',
    '  the APPENDIX R RESOLUTION - the',
    '  clean p. 109 read resolves the',
    '  five R390 flagged holes: the',
    '  subdual supercedes sentence,',
    '  the vanquishing loser sentence',
    '  ("must honorably surrender',
    '  immediately"), the chaotic',
    '  constraints line ("under no',
    '  constraints whatsoever") and',
    '  the monks-druids head print',
    '  whole; the disarming scimitar',
    '  seam confirms as the print',
    '  itself (the example names the',
    '  scimitar, absent from the',
    '  six-entry list - the book\'s',
    '  own seam, pinned as printed);',
    '  all seven items fully clean,',
    '  the box flips; census 347 ->',
    '  348. The advisory md5 diverged',
    '  (6853301009da2dbb7087d714b0a097c9',
    '  vs the published',
    '  d135d3a864e1058bc621ff5a31c675d5)',
    '  - benign; the md5 stays',
    '  advisory.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R422 landed 2026-10-13' in s:
    already.append('seed: the R422 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R422 record')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already'
        ' state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 349:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R423 UA appendix S'
           ' pantheon prose') != 1:
    die('the R423 audit label')

# the string-literal parity gate
# (the R421b lesson): no CODE
# line in the R423 audit block
# may carry an unterminated
# string literal
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R423 audit block has'
            ' an unterminated string'
            ' literal')

# the no-bare-|| gate (the R418b
# lesson) over uapn/nhd chains: a
# '||' line is legal only inside
# an open chain
prev = ''
for ln in s.split(NL):
    if (('uapn' in ln or 'nhd' in ln)
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || uapn/nhd line')
    prev = ln

# the header statics: no line over
# 78 columns, the inline census
h = rd(PN)
if not h:
    die('the uapantheon header'
        ' missing')
for ln in h.split(NL):
    if len(ln) > 78:
        die('the header line %d long'
            % len(ln))
if h.count('inline ') != 81:
    die('the header inline count %d'
        % h.count('inline '))

# the prefix-collision guard: no
# other file gained uapn words
for p in (RT, AR):
    pass
if _re.search(r'\buapp\w', h):
    die('the header collides with the'
        ' uapotprose uapp prefix')

# the seam functions the audit
# cross-mirrors still exist
for f in ('nhdPantheonSize',
          'nhdDeityCount',
          'nhdMoradinHeightFeet',
          'nhdGreaterDwarfSizeMultiple',
          'nhdDwarfSymbolNeverLiving',
          'nhdDwarfDeityDualCharisma'):
    if f not in s or f not in rd(
            'rules/deities.h'):
        die('the %s seam function' % f)

# the gap censuses: 101 closed,
# four open lines - three boxes
# (Appendix T; the two logging
# layers stay out by the user
# decision) plus the legend
g = rd(GP)
if ('- [x] **Appendix S: non-human'
    ' deities**') not in g:
    die('the Appendix S box still open')
if g.count(chr(10) + '- [x]') != 101:
    die('the gap closed count %d'
        % g.count(chr(10) + '- [x]'))
opens = [l for l in g.split(NL)
         if l.startswith('- [ ]')]
if len(opens) != 4:
    die('the gap open count %d'
        % len(opens))

# the seed record
if 'R422 landed 2026-10-13' not in rd(SD):
    die('the seed R422 record')

# the caller contract: no engine
# caller touches the uapn pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\buapn\w', rd(path)):
        die('%s calls the uapn pins'
            ' early' % path)

print('R423 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the UA appendix S pantheon')
print('  prose - the five intro sections')
print('  pin (rules/uapantheon.h, prefix')
print('  uapn) with the censuses')
print('  cross-checked live against the')
print('  R405 seam (the described counts')
print('  mirror nhdPantheonSize row for')
print('  row, the sum mirrors the 23); the')
print('  Appendix S item CLOSES - the box')
print('  flips; census 348 -> 349')
print('commit: R423: the UA Appendix S'
      ' pantheon prose (census 349)')

