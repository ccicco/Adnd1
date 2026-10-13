#!/usr/bin/env python3
# R398: the UA misc magic
# flagged holes completion -
# the clean PDF read fills
# every flagged hole the six
# misc magic prose parts
# carry.
#
# The same clean OCR as
# R394-R397 (pp. 98-104)
# delivers the 33 flagged
# seams across the six parts:
#
# 1. rules/uamiscprose1.h
#    (R381): six flags drop -
#    the amulet's 9th-level
#    cell, the anything item's
#    tail, the boccob book's
#    save cell and scribing
#    tail, the boots of varied
#    tracks' row-one print,
#    the chime's opening; the
#    part ledger flips 8/5 ->
#    13/0.
# 2. rules/uamiscprose2.h
#    (R382): seven flags drop -
#    the deck of illusions'
#    card list (eight rank
#    rows of four plus the
#    jokers), the dicerion's
#    description seam, the
#    dusts' seams, the three
#    egg seams; 1/7 -> 8/0.
# 3. rules/uamiscprose3.h
#    (R383): nine flags drop -
#    the gem's 50-year
#    function cell, the
#    girdles' blocks, the
#    gloves of thievery's
#    level cells (7th/5th),
#    the hats' seams, the
#    haversack's quart, the
#    horns' seams; 2/9 ->
#    11/0.
# 4. rules/uamiscprose4.h
#    (R384): four flags drop -
#    the lens of ultravision's
#    diameter cell (1.5
#    inches), Murlynd's
#    spoon's diet tail, the
#    philosopher's stone's
#    pounds cells (50-500
#    iron, 10-100 lead), the
#    prison of Zagyg's
#    attunement seam and
#    quarter-foot shrink;
#    5/4 -> 9/0.
# 5. rules/uamiscprose5.h
#    (R385): four flags drop -
#    the quiver of Ehlonna's
#    command sentence, the
#    robe of vermin's removal
#    tail, the sheet of
#    smallness' intro seam,
#    the spoon of stirring's
#    table cell; 7/4 -> 11/0.
# 6. rules/uamiscprose6.h
#    (R386): three flags drop -
#    the stone horse's
#    activation seam, the
#    ultimate solution's
#    disintegrate seam,
#    Zagyg's gp tail; 2/3 ->
#    5/0.
# 7. regtest.cpp: the six
#    part ledgers and their
#    seams flip, the 33 flag
#    asserts invert, the four
#    provisional value pins
#    correct, a new R398
#    audit block lands before
#    the R227 anchor; census
#    324 -> 325.
# 8. tools/ua_gap_report.md:
#    the misc magic item takes
#    an AMENDED R398: closed
#    sub-entry.
# 9. The seed takes the R397
#    record.
import io

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
        'R398 splice ABORT: ' + msg)


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


def forms(cond):
    return ('if (%s) ++bad;' % cond,
            'if (%s)' % cond + NL
            + '                ++bad;')


def flip1(path, expr, expect, label):
    s = rd(path)
    if ('!' + expr) not in s:
        already.append(label)
        return
    oA, oB = forms('!' + expr)
    n = s.count(oA) + s.count(oB)
    if n != expect:
        die('%s: old text count %d,'
            ' expected %d'
            % (label, n, expect))
    nA, nB = forms(expr)
    s = s.replace(oA, nA)
    s = s.replace(oB, nB)
    wr(path, s)
    applied.append(label)


def flipled(path, expr, oldval,
            newval, expect, label):
    s = rd(path)
    ocond = '%s != %d' % (expr, oldval)
    ncond = '%s != %d' % (expr, newval)
    oA, oB = forms(ocond)
    nA, nB = forms(ncond)
    if s.count(nA) + s.count(nB) \
            == expect:
        already.append(label)
        return
    n = s.count(oA) + s.count(oB)
    if n != expect:
        die('%s: old text count %d,'
            ' expected %d'
            % (label, n, expect))
    s = s.replace(oA, nA)
    s = s.replace(oB, nB)
    wr(path, s)
    applied.append(label)


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R397 landed 2026-10-13:',
    '  commit 7e8cc89 (census 324,',
    '  preflight GREEN), the UA',
    '  scrolls rings rods staves',
    '  wands prose completion:',
    '  the clean pp. 91-98 read',
    '  fills the four PDF-gated',
    '  treasure items - the four',
    '  scroll types',
    '  (rules/uaprotscr.h), the',
    '  seven rings',
    '  (rules/uaringprose.h), the',
    '  seven rods and staves',
    '  (rules/uarodstave.h), the',
    '  two wand holes and five',
    '  garbled wands',
    '  (rules/uawandprose.h); all',
    '  four gap items flip',
    '  AMENDED R397: closed -',
    '  every UA treasure',
    '  description pins. The',
    '  ./nn save hash diverged',
    '  for the fifth round running',
    '  yet the copy passed the',
    '  battery - stable and',
    '  benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R397 landed 2026-10-13' in s:
    already.append('seed: the R397 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R397 record')
s = rd(SD)
if s.count('R397 landed 2026-10-13') != 1:
    die('the R397 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) the six headers ============
P1 = 'rules/uamiscprose1.h'
P2 = 'rules/uamiscprose2.h'
P3 = 'rules/uamiscprose3.h'
P4 = 'rules/uamiscprose4.h'
P5 = 'rules/uamiscprose5.h'
P6 = 'rules/uamiscprose6.h'
NS = NL + 'namespace rules {'
NNOTE = ['// The R398 clean read',
         '// filled every flagged hole',
         '// named above.']

# ---- part 1 ----

pair(P1, E(
    '// and skeleton seams ride in',
    '// the regtest audit, not',
    '// here.') + NS,
    E(
    '// and skeleton seams ride in',
    '// the regtest audit, not',
    '// here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose1: the header note')

pair(P1, E(
    'inline bool uammAmuNinthCellGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read',
    '// confirms the 9th-level',
    '// cell - the turning table',
    '// prints clean.',
    'inline bool uammAmuNinthCellGarbles()',
    '    { return false; }'),
    'prose1: the amulet 9th cell')

pair(P1, E(
    'inline int uammAnyLongTermUseLimit()',
    '    { return 3; }',
    '',
    'inline bool uammAnyTailGarbles()',
    '    { return true; }'),
    E(
    'inline int uammAnyLongTermUseLimit()',
    '    { return 3; }',
    '',
    '// The R398 clean read fills',
    '// the tail: a long-term form',
    '// (such as a helm of',
    '// underwater action) lasts',
    '// one day - 24 hours.',
    'inline int uammAnyLongTermHours()',
    '    { return 24; }',
    '',
    'inline bool uammAnyTailGarbles()',
    '    { return false; }'),
    'prose1: the anything tail')

pair(P1, E(
    '// +3 on saving throws - the',
    '// save-category cell ("leather',
    '// or ...") OCR-truncates,',
    '// flagged.',
    'inline int uammBocSaveBonus()',
    '    { return 3; }',
    '',
    'inline bool uammBocSaveCellGarbles()',
    '    { return true; }'),
    E(
    '// +3 on saving throws, as',
    '// the "leather or book"',
    '// category - the R398',
    '// clean read fills the cell.',
    'inline int uammBocSaveBonus()',
    '    { return 3; }',
    '',
    'inline bool'
    ' uammBocSaveAsLeatherOrBook()',
    '    { return true; }',
    '',
    'inline bool uammBocSaveCellGarbles()',
    '    { return false; }'),
    'prose1: the boccob save cell')

pair(P1, E(
    'inline bool uammBocScribingTailGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the tail: such librams are',
    '// totally unlikely to be',
    '// discovered randomly with',
    '// spells written therein -',
    '// enscribed works are kept',
    '// carefully by their owners.',
    'inline bool uammBocRarelyFound'
    'Inscribed()',
    '    { return true; }',
    '',
    'inline bool uammBocKeptByOwners()',
    '    { return true; }',
    '',
    'inline bool uammBocScribingTail'
    'Garbles()',
    '    { return false; }'),
    'prose1: the boccob scribing tail')

pair(P1, E(
    'inline bool uammBvtRowOnePrintGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read prints',
    '// the table - row one the',
    '// basilisk, row sixteen the',
    '// wyvern; the mechanics',
    '// already pin the rest.',
    'inline bool uammBvtRowOneBasilisk()',
    '    { return true; }',
    '',
    'inline bool uammBvtRowSixteenWyvern()',
    '    { return true; }',
    '',
    'inline bool uammBvtRowOnePrint'
    'Garbles()',
    '    { return false; }'),
    'prose1: the boots row-one print')

pair(P1, E(
    '// The opening sentence',
    '// OCR-scrambles - the item',
    '// name garbles into the',
    '// mechanics; flagged. Struck',
    '// only once per turn; the',
    '// resonant tone lasts three',
    '// full rounds.',
    'inline bool uammChiOpeningGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read prints',
    '// the opening clean; struck',
    '// only once per turn; the',
    '// resonant tone lasts three',
    '// full rounds.',
    'inline bool uammChiOpeningGarbles()',
    '    { return false; }'),
    'prose1: the chime opening')

pair(P1, E(
    '// ---- the part ledger ----',
    '// Thirteen A-C items: eight',
    '// fully clean, five',
    '// mechanics-clean with',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uammPartItemTotal()',
    '    { return 13; }',
    '',
    'inline int uammPartCleanCount()',
    '    { return 8; }',
    '',
    'inline int uammPartFlaggedCount()',
    '    { return 5; }'),
    E(
    '// ---- the part ledger ----',
    '// Thirteen A-C items, all',
    '// fully clean - the R398',
    '// clean read filled the five',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uammPartItemTotal()',
    '    { return 13; }',
    '',
    'inline int uammPartCleanCount()',
    '    { return 13; }',
    '',
    'inline int uammPartFlaggedCount()',
    '    { return 0; }'),
    'prose1: the part ledger')

# ---- part 2 ----

pair(P2, E(
    '// part-1 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.') + NS,
    E(
    '// part-1 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose2: the header note')

pair(P2, E(
    '// Two jokers, showing the',
    "// deck's owner. The card",
    '// list OCR-garbles (stray',
    '// rows, "bgoblin", "rc");',
    '// the deck mechanics read;',
    '// flagged.',
    'inline int uamm2DekJokers()',
    '    { return 2; }',
    '',
    'inline bool uamm2DekCardListGarbles()',
    '    { return true; }'),
    E(
    '// Two jokers, showing the',
    "// deck's owner. The R398",
    '// clean read prints the list:',
    '// eight rank rows (ace down',
    '// to the deuce) of four',
    '// cards each - the ace is',
    '// the red dragon, the low',
    '// row shows goblins and',
    '// kobolds - 32 plaques plus',
    '// the jokers.',
    'inline int uamm2DekJokers()',
    '    { return 2; }',
    '',
    'inline int uamm2DekRankRows()',
    '    { return 8; }',
    '',
    'inline int uamm2DekCardsPerRank()',
    '    { return 4; }',
    '',
    'inline bool uamm2DekAceIsRedDragon()',
    '    { return true; }',
    '',
    'inline bool uamm2DekLowRowIsTwo()',
    '    { return true; }',
    '',
    'inline bool uamm2DekCardList'
    'Garbles()',
    '    { return false; }'),
    'prose2: the deck card list')

pair(P2, E(
    'inline bool uamm2DicDescSeamGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the description seam: the',
    '// bright branch silver and',
    '// mithral, the dark arm iron',
    '// and adamantite, the base',
    '// spreads to eight legs.',
    'inline bool uamm2DicBrightSilver'
    'Mithral()',
    '    { return true; }',
    '',
    'inline bool uamm2DicDarkIron'
    'Adamantite()',
    '    { return true; }',
    '',
    'inline int uamm2DicBaseLegs()',
    '    { return 8; }',
    '',
    'inline bool uamm2DicDescSeam'
    'Garbles()',
    '    { return false; }'),
    'prose2: the dicerion seam')

pair(P2, E(
    'inline bool uamm2DdrElementalSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the seam: an elemental or',
    '// similar creature must',
    '// save versus spell or be',
    '// destroyed.',
    'inline bool uamm2DdrSaveOr'
    'Destroyed()',
    '    { return true; }',
    '',
    'inline bool uamm2DdrElementalSeam'
    'Garbles()',
    '    { return false; }'),
    'prose2: the dryness seam')

pair(P2, E(
    'inline bool uamm2DilIntroGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the intro: the powder',
    '// resembles chalk dust or',
    '// powdered graphite -',
    '// unless it is stared at.',
    'inline bool uamm2DilResemblesChalk'
    'Graphite()',
    '    { return true; }',
    '',
    'inline bool uamm2DilChangesUnder'
    'Scrutiny()',
    '    { return true; }',
    '',
    'inline bool uamm2DilIntroGarbles()',
    '    { return false; }'),
    'prose2: the illusion intro')

pair(P2, E(
    '// Removal only by a magic',
    '// (the seam prints "a magic',
    '// or remove curse spell")',
    '// remove curse; the',
    '// low-intelligence seam',
    '// OCR-scrambles ("y an',
    '// egg"), the table reads;',
    '// flagged.',
    'inline bool uamm2EgdRemovalRemove'
    'Curse()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdLowIntGrabs'
    'Dropped()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdIntSeamGarbles()',
    '    { return true; }'),
    E(
    '// Removal only by a dispel',
    '// magic or remove curse',
    '// spell - the R398 clean',
    '// read fills the seam.',
    'inline bool uamm2EgdRemovalRemove'
    'Curse()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdRemovalAlso'
    'DispelMagic()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdLowIntGrabs'
    'Dropped()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdLowIntUnder'
    'Seven()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdLowIntCovets()',
    '    { return true; }',
    '',
    'inline bool uamm2EgdIntSeamGarbles()',
    '    { return false; }'),
    'prose2: the desire seams')

pair(P2, E(
    '// The 18-or-higher increment',
    '// cell OCR-garbles (""so',
    '// point at a time ... 10',
    '// eggs") - flagged; racial',
    '// limitations apply.',
    'inline bool uamm2EgrHighScoreCell'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the cell: scores of 18 or',
    '// higher rise only',
    '// one-tenth point at a time -',
    '// ten eggs of reason per',
    '// point above 18; racial',
    '// limitations apply.',
    'inline bool uamm2EgrHighScore'
    'TenthPoint()',
    '    { return true; }',
    '',
    'inline int uamm2EgrEggsPerPoint'
    'Above18()',
    '    { return 10; }',
    '',
    'inline bool uamm2EgrHighScoreCell'
    'Garbles()',
    '    { return false; }'),
    'prose2: the reason 18+ cell')

pair(P2, E(
    'inline bool uamm2EgsAttackSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read',
    '// confirms the attack',
    '// sentence - fragments strike',
    '// using actual armor class',
    '// only.',
    'inline bool uamm2EgsAttackSeam'
    'Garbles()',
    '    { return false; }'),
    'prose2: the shattering seam')

pair(P2, E(
    '// ---- the part ledger ----',
    '// Eight D-E items: one fully',
    '// clean, seven flagged, none',
    '// fully garbled.',
    'inline int uamm2PartItemTotal()',
    '    { return 8; }',
    '',
    'inline int uamm2PartCleanCount()',
    '    { return 1; }',
    '',
    'inline int uamm2PartFlaggedCount()',
    '    { return 7; }'),
    E(
    '// ---- the part ledger ----',
    '// Eight D-E items, all fully',
    '// clean - the R398 clean read',
    '// filled the seven flagged',
    '// holes, none fully garbled.',
    'inline int uamm2PartItemTotal()',
    '    { return 8; }',
    '',
    'inline int uamm2PartCleanCount()',
    '    { return 8; }',
    '',
    'inline int uamm2PartFlaggedCount()',
    '    { return 0; }'),
    'prose2: the part ledger')

# ---- part 3 ----

pair(P3, E(
    '// part-2 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.') + NS,
    E(
    '// part-2 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose3: the header note')

pair(P3, E(
    'inline bool uamm3GemRecallSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the recall seam: any one',
    '// such gem functions but',
    '// once every 50 years.',
    'inline int uamm3GemYearsBetween'
    'Functions()',
    '    { return 50; }',
    '',
    'inline bool uamm3GemRecallSeam'
    'Garbles()',
    '    { return false; }'),
    'prose3: the gem recall seam')

pair(P3, E(
    'inline bool uamm3GdkRacialBlock'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the racial block: +1',
    '// constitution, saving throw',
    '// bonuses based on total',
    '// constitution, 6"',
    '// infravision, and detection',
    '// of approximate depth',
    '// underground.',
    'inline int uamm3GdkConBonus()',
    '    { return 1; }',
    '',
    'inline bool uamm3GdkSavesByCon()',
    '    { return true; }',
    '',
    'inline int uamm3GdkInfravisionIn()',
    '    { return 6; }',
    '',
    'inline bool uamm3GdkDepthDetection()',
    '    { return true; }',
    '',
    'inline bool uamm3GdkRacialBlock'
    'Garbles()',
    '    { return false; }'),
    'prose3: the dwarvenkind block')

pair(P3, E(
    '// A garbled tail sentence (a',
    '// 50-years fragment) rides',
    '// the extract; flagged.',
    'inline bool uamm3GmpTailSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read shows',
    '// the 50-years fragment as',
    '// gem-of-insight bleed - the',
    '// girdle text reads whole.',
    'inline bool uamm3GmpTailSeam'
    'Garbles()',
    '    { return false; }'),
    'prose3: the many pouches tail')

pair(P3, E(
    '// Opens locks and picks',
    '// pockets as a thief of the',
    '// stated levels - the level',
    '// cells OCR-scramble ("Sth",',
    '// the 7th); a further +5% in',
    '// both categories if the',
    '// wearer is already at or',
    '// above the stated levels;',
    '// flagged.',
    'inline bool uamm3GthLevelCells'
    'Garble()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the level cells: open locks',
    '// as a 7th-level thief, pick',
    '// pockets as a 5th-level',
    '// thief; a further +5% in',
    '// both categories if the',
    '// wearer is already at or',
    '// above the stated levels.',
    'inline int uamm3GthOpenLocks'
    'Level()',
    '    { return 7; }',
    '',
    'inline int uamm3GthPickPockets'
    'Level()',
    '    { return 5; }',
    '',
    'inline bool uamm3GthLevelCells'
    'Garble()',
    '    { return false; }'),
    'prose3: the thievery cells')

pair(P3, E(
    '// Removing the hat dispels',
    '// the dweomer instantly, but',
    '// it can be used over and',
    '// over; the removal sentence',
    '// OCR-scrambles - flagged.',
    'inline bool uamm3HdgRemovalDispels'
    'Instantly()',
    '    { return true; }',
    '',
    'inline bool uamm3HdgReusableOver'
    'AndOver()',
    '    { return true; }',
    '',
    'inline bool uamm3HdgRemovalSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// Removing the hat dispels',
    '// the dweomer instantly, but',
    '// it can be used over and',
    '// over - the R398 clean read',
    '// fills the removal seam.',
    'inline bool uamm3HdgRemovalDispels'
    'Instantly()',
    '    { return true; }',
    '',
    'inline bool uamm3HdgReusableOver'
    'AndOver()',
    '    { return true; }',
    '',
    'inline bool uamm3HdgRemovalSeam'
    'Garbles()',
    '    { return false; }'),
    'prose3: the disguise seam')

pair(P3, E(
    'inline bool uamm3HdfLossSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the loss seam: discard,',
    '// loss, theft, or a 24-hour',
    '// absence beyond a one-mile',
    '// radius loses all assumed',
    '// experience.',
    'inline int uamm3HdfLossRadiusMiles()',
    '    { return 1; }',
    '',
    'inline int uamm3HdfLossHours()',
    '    { return 24; }',
    '',
    'inline bool uamm3HdfLostIfStolen()',
    '    { return true; }',
    '',
    'inline bool uamm3HdfLossSeam'
    'Garbles()',
    '    { return false; }'),
    'prose3: the difference seam')

pair(P3, E(
    'inline bool uamm3HavQuartMerge'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the merge: each side pouch',
    '// appears large enough to',
    '// hold about a quart of',
    '// material.',
    'inline bool uamm3HavAppearsQuart()',
    '    { return true; }',
    '',
    'inline bool uamm3HavQuartMerge'
    'Garbles()',
    '    { return false; }'),
    'prose3: the haversack quart')

pair(P3, E(
    '// The note drops abruptly at',
    '// the end (the OOO0O00-UMP!',
    '// artifact), and the duration',
    '// prose mixes rounds and',
    "// minutes - the book's own",
    '// seam; flagged.',
    'inline bool uamm3HfgRoundsMinutes'
    'SeamGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read prints',
    "// the book's own seam: each",
    '// cloud lasts but 2-8 more',
    '// minutes after the next note',
    '// begins.',
    'inline int uamm3HfgDriftMinutesLo()',
    '    { return 2; }',
    '',
    'inline int uamm3HfgDriftMinutesHi()',
    '    { return 8; }',
    '',
    'inline bool uamm3HfgRoundsMinutes'
    'SeamGarbles()',
    '    { return false; }'),
    'prose3: the fog seam')

pair(P3, E(
    'inline bool uamm3HgdHeaderSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read prints',
    '// the eaten header: the horn',
    '// is named goodness/evil.',
    'inline bool uamm3HgdNamedGoodness'
    'Evil()',
    '    { return true; }',
    '',
    'inline bool uamm3HgdHeaderSeam'
    'Garbles()',
    '    { return false; }'),
    'prose3: the goodness header')

pair(P3, E(
    '// ---- the part ledger ----',
    '// Eleven G-H items: two fully',
    '// clean, nine flagged, none',
    '// fully garbled.',
    'inline int uamm3PartItemTotal()',
    '    { return 11; }',
    '',
    'inline int uamm3PartCleanCount()',
    '    { return 2; }',
    '',
    'inline int uamm3PartFlaggedCount()',
    '    { return 9; }'),
    E(
    '// ---- the part ledger ----',
    '// Eleven G-H items, all',
    '// fully clean - the R398',
    '// clean read filled the nine',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uamm3PartItemTotal()',
    '    { return 11; }',
    '',
    'inline int uamm3PartCleanCount()',
    '    { return 11; }',
    '',
    'inline int uamm3PartFlaggedCount()',
    '    { return 0; }'),
    'prose3: the part ledger')

# ---- part 4 ----

pair(P4, E(
    '// part-3 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.') + NS,
    E(
    '// part-3 and skeleton seams',
    '// ride in the regtest audit,',
    '// not here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose4: the header note')

pair(P4, E(
    "// The printed diameter cell",
    '// garbles ("1\'z inches") -',
    '// read as about one and a',
    '// half inches; flagged.',
    'inline int uamm4LulDiameterIn()',
    '    { return 1; }',
    '',
    'inline bool uamm4LulDiameterCell'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the cell: the lens is about',
    '// one and a half inches in',
    '// diameter - 15 tenths.',
    'inline int uamm4LulDiameterTenths'
    'In()',
    '    { return 15; }',
    '',
    'inline bool uamm4LulDiameterCell'
    'Garbles()',
    '    { return false; }'),
    'prose4: the ultravision cell')

pair(P4, E(
    '// The nourishment seam',
    '// OCR-scrambles; the',
    '// reconstruction: the gruel',
    '// is highly nourishing, and',
    '// the spoon produces enough',
    '// in a day to feed up to',
    '// four humans; flagged.',
    'inline bool uamm4MslHighly'
    'Nourishing()',
    '    { return true; }',
    '',
    'inline int uamm4MslFeedsHumans'
    'PerDay()',
    '    { return 4; }',
    '',
    'inline bool uamm4MslGruelTail'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the seam: the gruel is',
    '// highly nourishing,',
    '// sustains any diet, and the',
    '// spoon produces enough in a',
    '// day to feed up to four',
    '// humans.',
    'inline bool uamm4MslHighly'
    'Nourishing()',
    '    { return true; }',
    '',
    'inline bool uamm4MslSustainsAll'
    'Diets()',
    '    { return true; }',
    '',
    'inline int uamm4MslFeedsHumans'
    'PerDay()',
    '    { return 4; }',
    '',
    'inline bool uamm4MslGruelTail'
    'Garbles()',
    '    { return false; }'),
    'prose4: the spoon tail')

pair(P4, E(
    '// The transmutation amount',
    '// cells OCR-scramble; the',
    '// reconstruction: up to 50',
    '// pounds of iron into silver,',
    '// or 100 pounds of lead into',
    '// gold, from a single stone;',
    '// either an alchemist or a',
    '// magic-user can effectuate',
    '// it; flagged.',
    'inline int uamm4PstIronLbsPer'
    'Stone()',
    '    { return 50; }',
    '',
    'inline int uamm4PstLeadLbsPer'
    'Stone()',
    '    { return 100; }',
    '',
    'inline bool uamm4PstAlchemistOr'
    'MagicUser()',
    '    { return true; }',
    '',
    'inline bool uamm4PstTransmutation'
    'CellsGarble()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the cells: from 50 to 500',
    '// pounds of iron into silver,',
    '// or 10 to 100 pounds of lead',
    '// into gold, from a single',
    '// stone; either an alchemist',
    '// or a magic-user can',
    '// effectuate it.',
    'inline int uamm4PstIronLbsLo()',
    '    { return 50; }',
    '',
    'inline int uamm4PstIronLbsHi()',
    '    { return 500; }',
    '',
    'inline int uamm4PstLeadLbsLo()',
    '    { return 10; }',
    '',
    'inline int uamm4PstLeadLbsHi()',
    '    { return 100; }',
    '',
    'inline bool uamm4PstAlchemistOrMagicUser()',
    '    { return true; }',
    '',
    'inline bool uamm4PstTransmutationCellsGarble()',
    '    { return false; }'),
    'prose4: the stone cells')

pair(P4, E(
    '// The attunement sentence',
    '// OCR-scrambles; the',
    '// reconstruction: each prison',
    '// attunes itself to the',
    '// possessor when he or she',
    '// learns the activation',
    '// wording; flagged.',
    'inline bool uamm4PzaAttunementSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the seam: the cage carries',
    '// an anti-magic and',
    '// non-detection spell in and',
    '// upon it, and each prison',
    '// attunes itself to the',
    '// possessor who learns the',
    '// activation wording.',
    'inline bool uamm4PzaPermanent'
    'AntiMagic()',
    '    { return true; }',
    '',
    'inline bool uamm4PzaNonDetection()',
    '    { return true; }',
    '',
    'inline bool uamm4PzaAttunesTo'
    'Owner()',
    '    { return true; }',
    '',
    'inline bool uamm4PzaAttunementSeam'
    'Garbles()',
    '    { return false; }'),
    'prose4: the prison seam')

pair(P4, E(
    '// A failed save versus spell',
    '// shrinks the victim to about',
    '// a foot in height and',
    '// transports it',
    '// instantaneously into the',
    '// cage.',
    'inline bool uamm4PzaSaveVsSpell()',
    '    { return true; }',
    '',
    'inline int uamm4PzaShrinksToHeight'
    'Ft()',
    '    { return 1; }'),
    E(
    '// A failed save versus spell',
    '// shrinks the victim to about',
    '// a quarter foot - three',
    '// inches - in height and',
    '// transports it',
    '// instantaneously into the',
    '// cage.',
    'inline bool uamm4PzaSaveVsSpell()',
    '    { return true; }',
    '',
    'inline int uamm4PzaShrinksToHeight'
    'In()',
    '    { return 3; }'),
    'prose4: the prison shrink')

pair(P4, E(
    '// ---- the part ledger ----',
    '// Nine I-P items: five fully',
    '// clean, four flagged, none',
    '// fully garbled.',
    'inline int uamm4PartItemTotal()',
    '    { return 9; }',
    '',
    'inline int uamm4PartCleanCount()',
    '    { return 5; }',
    '',
    'inline int uamm4PartFlaggedCount()',
    '    { return 4; }'),
    E(
    '// ---- the part ledger ----',
    '// Nine I-P items, all fully',
    '// clean - the R398 clean read',
    '// filled the four flagged',
    '// holes, none fully garbled.',
    'inline int uamm4PartItemTotal()',
    '    { return 9; }',
    '',
    'inline int uamm4PartCleanCount()',
    '    { return 9; }',
    '',
    'inline int uamm4PartFlaggedCount()',
    '    { return 0; }'),
    'prose4: the part ledger')

# ---- part 5 ----

pair(P5, E(
    '// later part. The part-4 and',
    '// skeleton seams ride in the',
    '// regtest audit, not here.') + NS,
    E(
    '// later part. The part-4 and',
    '// skeleton seams ride in the',
    '// regtest audit, not here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose5: the header note')

pair(P5, E(
    'inline bool uamm5QehCommand'
    'SentenceGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the sentence: the possessor',
    '// need merely command the',
    '// quiver to produce whatever',
    '// is wished each round -',
    '// "an arrow +1", "an arrow',
    '// +3", "a javelin".',
    'inline bool uamm5QehNames'
    'Variants()',
    '    { return true; }',
    '',
    'inline bool uamm5QehCommand'
    'SentenceGarbles()',
    '    { return false; }'),
    'prose5: the quiver sentence')

pair(P5, E(
    'inline bool uamm5RveRemovalTail'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read',
    '// confirms the removal tail -',
    '// only a remove curse or',
    '// similar magic strips the',
    '// robe.',
    'inline bool uamm5RveRemovalTail'
    'Garbles()',
    '    { return false; }'),
    'prose5: the vermin tail')

pair(P5, E(
    'inline bool uamm5SsmIntroSeam'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the intro: one side of the',
    '// sheet carries a larger',
    '// pattern than the other.',
    'inline bool uamm5SsmOneSideLargerPattern()',
    '    { return true; }',
    '',
    'inline bool uamm5SsmIntroSeamGarbles()',
    '    { return false; }'),
    'prose5: the smallness seam')

pair(P5, E(
    '// The table-reference cell',
    '// OCR-scrambles; the',
    '// reconstruction: the type',
    '// produced is diced from',
    '// Table III.A.2; flagged.',
    'inline bool uamm5SstTableCell'
    'Garbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the cell: the new type is',
    '// diced from Table III.A or',
    '// Table III.A.2.',
    'inline bool uamm5SstAlsoTable'
    'ThreeA()',
    '    { return true; }',
    '',
    'inline bool uamm5SstTableCellGarbles()',
    '    { return false; }'),
    'prose5: the stirring cell')

pair(P5, E(
    '// ---- the part ledger ----',
    '// Eleven Q-S items: seven',
    '// fully clean, four flagged,',
    '// none fully garbled.',
    'inline int uamm5PartItemTotal()',
    '    { return 11; }',
    '',
    'inline int uamm5PartCleanCount()',
    '    { return 7; }',
    '',
    'inline int uamm5PartFlaggedCount()',
    '    { return 4; }'),
    E(
    '// ---- the part ledger ----',
    '// Eleven Q-S items, all',
    '// fully clean - the R398',
    '// clean read filled the four',
    '// flagged holes, none fully',
    '// garbled.',
    'inline int uamm5PartItemTotal()',
    '    { return 11; }',
    '',
    'inline int uamm5PartCleanCount()',
    '    { return 11; }',
    '',
    'inline int uamm5PartFlaggedCount()',
    '    { return 0; }'),
    'prose5: the part ledger')

# ---- part 6 ----

pair(P6, E(
    '// skeleton seams ride in',
    '// the regtest audit, not',
    '// here.') + NS,
    E(
    '// skeleton seams ride in',
    '// the regtest audit, not',
    '// here.',
    '// The R398 clean read',
    '// filled every flagged hole',
    '// named above.') + NS,
    'prose6: the header note')

pair(P6, E(
    'inline bool uamm6ShActivationSeamGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read prints',
    '// the activation seam clean -',
    '// the word animates the steed',
    '// to carry and attack.',
    'inline bool uamm6ShActivationSeamGarbles()',
    '    { return false; }'),
    'prose6: the horse seam')

pair(P6, E(
    'inline bool uamm6UsoTransmutationSeamGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the seam: an ounce dissolves',
    '// a cubic foot as a',
    '// disintegrate spell had been',
    '// employed.',
    'inline bool uamm6UsoAsDisintegrate()',
    '    { return true; }',
    '',
    'inline bool uamm6UsoTransmutationSeamGarbles()',
    '    { return false; }'),
    'prose6: the solution seam')

pair(P6, E(
    'inline bool uamm6ZscGpTailGarbles()',
    '    { return true; }'),
    E(
    '// The R398 clean read fills',
    '// the gp tail: the sale value',
    '// runs 1,000 times the uses -',
    '// 2,000 to 7,000.',
    'inline bool uamm6ZscGpTailGarbles()',
    '    { return false; }'),
    'prose6: the Zagyg tail')

pair(P6, E(
    '// ---- the part ledger ----',
    '// Five S-Z items: two fully',
    '// clean, three flagged, none',
    '// fully garbled.',
    'inline int uamm6PartItemTotal()',
    '    { return 5; }',
    '',
    'inline int uamm6PartCleanCount()',
    '    { return 2; }',
    '',
    'inline int uamm6PartFlaggedCount()',
    '    { return 3; }'),
    E(
    '// ---- the part ledger ----',
    '// Five S-Z items, all fully',
    '// clean - the R398 clean read',
    '// filled the three flagged',
    '// holes, none fully garbled.',
    'inline int uamm6PartItemTotal()',
    '    { return 5; }',
    '',
    'inline int uamm6PartCleanCount()',
    '    { return 5; }',
    '',
    'inline int uamm6PartFlaggedCount()',
    '    { return 0; }'),
    'prose6: the part ledger')

# ============ (c) the gap report ============
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '        garbles - the item AMENDED,',
    '        the prose pinned A-Z, stays',
    '        PDF-gated only.',
    '- [ ] **The new armor and'
    ' shields and'),
    E(
    '        garbles - the item AMENDED,',
    '      - AMENDED R398: closed -',
    '        the clean PDF read (the',
    '        same clean OCR as',
    '        R394-R397) fills every',
    '        flagged hole the six',
    '        misc magic prose parts',
    '        carry (33 flag seams,',
    '        rules/uamiscprose1.h',
    '        through',
    '        rules/uamiscprose6.h):',
    "        the amulet's 9th-level",
    '        cell, the anything',
    "        item's 24-hour tail, the",
    "        boccob book's save",
    '        category and scribing',
    '        tail, the boots of',
    "        varied tracks' row",
    "        prints, the chime's",
    '        opening, the deck of',
    "        illusions' card list",
    '        (eight ranks of four',
    '        plus the jokers), the',
    "        dicerion's description",
    "        seam, the dusts' seams,",
    '        the three egg seams,',
    "        the gem's 50-year",
    "        function, the girdles'",
    '        blocks, the gloves of',
    "        thievery's level cells",
    "        (7th/5th), the hats'",
    "        seams, the haversack's",
    "        quart, the horns' seams,",
    "        the lens' diameter (one",
    '        and a half inches),',
    "        Murlynd's spoon's diet",
    '        tail, the',
    "        philosopher's stone's",
    '        pounds cells (50-500',
    '        iron, 10-100 lead), the',
    "        prison's attunement and",
    '        quarter-foot shrink,',
    "        the quiver's command",
    '        sentence, the robe of',
    "        vermin's removal tail,",
    "        the sheet's pattern",
    '        side, the spoon of',
    "        stirring's table cells,",
    '        the stone',
    "        horse's activation, the",
    '        ultimate',
    "        solution's disintegrate",
    "        seam, Zagyg's gp tail -",
    '        every part ledger runs',
    '        clean, no flagged hole',
    '        remains.',
    '- [ ] **The new armor and'
    ' shields and'),
    'gap: the misc magic item')

# ============ (d) regtest.cpp ============
RT = 'regtest.cpp'

# the six block notes
for r, n in (('R381', 'part 1'),
            ('R382', 'part 2'),
            ('R383', 'part 3'),
            ('R384', 'part 4'),
            ('R385', 'part 5'),
            ('R386', 'part 6')):
    pair(RT,
         E('    // ---- %s: the UA misc'
           ' magic' % r,
           '    // prose %s pin audit'
           ' ----' % n),
         E('    // ---- %s: the UA misc'
           ' magic' % r,
           '    // prose %s pin audit'
           ' ----' % n,
           '    // The R398 clean read'
           ' fills',
           '    // every flagged hole'
           ' this',
           '    // block names.'),
         'regtest %s: the block note'
         % r)

# the twelve part-ledger asserts
flipled(RT, 'uammPartCleanCount()',
        8, 13, 2, 'regtest: the P1 clean ledger')
flipled(RT, 'uammPartFlaggedCount()',
        5, 0, 2, 'regtest: the P1 flagged')
flipled(RT, 'uamm2PartCleanCount()',
        1, 8, 2, 'regtest: the P2 clean ledger')
flipled(RT, 'uamm2PartFlaggedCount()',
        7, 0, 2, 'regtest: the P2 flagged')
flipled(RT, 'uamm3PartCleanCount()',
        2, 11, 2, 'regtest: the P3 clean ledger')
flipled(RT, 'uamm3PartFlaggedCount()',
        9, 0, 2, 'regtest: the P3 flagged')
flipled(RT, 'uamm4PartCleanCount()',
        5, 9, 2, 'regtest: the P4 clean ledger')
flipled(RT, 'uamm4PartFlaggedCount()',
        4, 0, 2, 'regtest: the P4 flagged')
flipled(RT, 'uamm5PartCleanCount()',
        7, 11, 2, 'regtest: the P5 clean ledger')
flipled(RT, 'uamm5PartFlaggedCount()',
        4, 0, 2, 'regtest: the P5 flagged')
flipled(RT, 'uamm6PartCleanCount()',
        2, 5, 2, 'regtest: the P6 clean ledger')
flipled(RT, 'uamm6PartFlaggedCount()',
        3, 0, 2, 'regtest: the P6 flagged')

# the 33 flag asserts invert
FLAGS = [
    'uammAmuNinthCellGarbles',
    'uammAnyTailGarbles',
    'uammBocSaveCellGarbles',
    'uammBocScribingTailGarbles',
    'uammBvtRowOnePrintGarbles',
    'uammChiOpeningGarbles',
    'uamm2DekCardListGarbles',
    'uamm2DicDescSeamGarbles',
    'uamm2DdrElementalSeamGarbles',
    'uamm2DilIntroGarbles',
    'uamm2EgdIntSeamGarbles',
    'uamm2EgrHighScoreCellGarbles',
    'uamm2EgsAttackSeamGarbles',
    'uamm3GemRecallSeamGarbles',
    'uamm3GdkRacialBlockGarbles',
    'uamm3GmpTailSeamGarbles',
    'uamm3GthLevelCellsGarble',
    'uamm3HdfLossSeamGarbles',
    'uamm3HdgRemovalSeamGarbles',
    'uamm3HavQuartMergeGarbles',
    'uamm3HfgRoundsMinutesSeamGarbles',
    'uamm3HgdHeaderSeamGarbles',
    'uamm4LulDiameterCellGarbles',
    'uamm4MslGruelTailGarbles',
    'uamm4PstTransmutationCellsGarble',
    'uamm4PzaAttunementSeamGarbles',
    'uamm5QehCommandSentenceGarbles',
    'uamm5RveRemovalTailGarbles',
    'uamm5SsmIntroSeamGarbles',
    'uamm5SstTableCellGarbles',
    'uamm6ShActivationSeamGarbles',
    'uamm6UsoTransmutationSeamGarbles',
    'uamm6ZscGpTailGarbles',
]

for nm in FLAGS:
    flip1(RT, nm + '()', 1,
          'regtest: the %s assert'
          % nm)

# the four provisional value
# pins correct
pair(RT, E(
    '            if (uamm4LulDiameterIn()'
    ' != 1) ++bad;'),
    E(
    '            if (uamm4LulDiameter'
    'TenthsIn() != 15) ++bad;'),
    'regtest: the lens value')

pair(RT, E(
    '            if (uamm4PstIronLbsPer'
    'Stone() != 50)',
    '                ++bad;',
    '            if (uamm4PstLeadLbsPer'
    'Stone() != 100)',
    '                ++bad;'),
    E(
    '            if (uamm4PstIronLbsLo()'
    ' != 50)',
    '                ++bad;',
    '            if (uamm4PstIronLbsHi()'
    ' != 500)',
    '                ++bad;',
    '            if (uamm4PstLeadLbsLo()'
    ' != 10)',
    '                ++bad;',
    '            if (uamm4PstLeadLbsHi()'
    ' != 100)',
    '                ++bad;'),
    'regtest: the stone values')

pair(RT, E(
    '            // the lead transmutes at',
    '            // twice the iron weight',
    '            if (2 * uamm4PstIronLbsPer'
    'Stone()',
    '                    != uamm4PstLead'
    'LbsPerStone())',
    '                ++bad;'),
    E(
    '            // the lead band is the',
    '            // iron band divided by',
    '            // five at both ends',
    '            if (uamm4PstIronLbsLo()',
    '                    / 5 != uamm4PstLead'
    'LbsLo())',
    '                ++bad;',
    '            if (uamm4PstIronLbsHi()',
    '                    / 5 != uamm4PstLead'
    'LbsHi())',
    '                ++bad;'),
    'regtest: the stone cross-check')

pair(RT, E(
    '            if (uamm4PzaShrinksToHeight'
    'Ft() != 1)',
    '                ++bad;'),
    E(
    '            if (uamm4PzaShrinksToHeight'
    'In() != 3)',
    '                ++bad;'),
    'regtest: the prison value')

# the new R398 audit block
NEWPINS = [
    ('uammAnyLongTermHours', 24),
    ('uammBocSaveAsLeatherOrBook', True),
    ('uammBocRarelyFoundInscribed', True),
    ('uammBocKeptByOwners', True),
    ('uammBvtRowOneBasilisk', True),
    ('uammBvtRowSixteenWyvern', True),
    ('uamm2DekRankRows', 8),
    ('uamm2DekCardsPerRank', 4),
    ('uamm2DekAceIsRedDragon', True),
    ('uamm2DekLowRowIsTwo', True),
    ('uamm2DicBrightSilverMithral', True),
    ('uamm2DicDarkIronAdamantite', True),
    ('uamm2DicBaseLegs', 8),
    ('uamm2DdrSaveOrDestroyed', True),
    ('uamm2DilResemblesChalkGraphite',
     True),
    ('uamm2DilChangesUnderScrutiny',
     True),
    ('uamm2EgdRemovalAlsoDispelMagic',
     True),
    ('uamm2EgdLowIntUnderSeven', True),
    ('uamm2EgdLowIntCovets', True),
    ('uamm2EgrHighScoreTenthPoint',
     True),
    ('uamm2EgrEggsPerPointAbove18', 10),
    ('uamm3GemYearsBetweenFunctions', 50),
    ('uamm3GdkConBonus', 1),
    ('uamm3GdkSavesByCon', True),
    ('uamm3GdkInfravisionIn', 6),
    ('uamm3GdkDepthDetection', True),
    ('uamm3GthOpenLocksLevel', 7),
    ('uamm3GthPickPocketsLevel', 5),
    ('uamm3HdfLossRadiusMiles', 1),
    ('uamm3HdfLossHours', 24),
    ('uamm3HdfLostIfStolen', True),
    ('uamm3HavAppearsQuart', True),
    ('uamm3HfgDriftMinutesLo', 2),
    ('uamm3HfgDriftMinutesHi', 8),
    ('uamm3HgdNamedGoodnessEvil', True),
    ('uamm4LulDiameterTenthsIn', 15),
    ('uamm4MslSustainsAllDiets', True),
    ('uamm4PstIronLbsLo', 50),
    ('uamm4PstIronLbsHi', 500),
    ('uamm4PstLeadLbsLo', 10),
    ('uamm4PstLeadLbsHi', 100),
    ('uamm4PzaPermanentAntiMagic', True),
    ('uamm4PzaNonDetection', True),
    ('uamm4PzaAttunesToOwner', True),
    ('uamm4PzaShrinksToHeightIn', 3),
    ('uamm5QehNamesVariants', True),
    ('uamm5SsmOneSideLargerPattern',
     True),
    ('uamm5SstAlsoTableThreeA', True),
    ('uamm6UsoAsDisintegrate', True),
]


def pin_lines(pins):
    out = []
    for nm, val in pins:
        if val is True:
            cond = '!' + nm + '()'
        else:
            cond = '%s() != %d' % (nm, val)
        stmt = 'if (%s) ++bad;' % cond
        if 12 + len(stmt) <= 78:
            out.append('            ' + stmt)
        else:
            out.append('            if (%s)' % cond)
            out.append('                ++bad;')
    return out


AUD = ['    // ---- R398: the UA misc magic',
       '    // flagged holes pin audit ----',
       '    // The clean read (pp.',
       '    // 98-104) fills every',
       '    // flagged hole the six',
       '    // misc prose parts carry -',
       '    // all 33 flags drop and',
       '    // every part ledger runs',
       '    // clean/0.',
       '    {',
       '        using namespace rules;',
       '        int bad = 0;']
AUD.extend(pin_lines(NEWPINS))
AUD.extend([
    '        // ---- the cross-checks',
    '        // ----',
    '            // the deck is eight',
    '            // rank rows of four',
    '            // plus the jokers',
    '            if (uamm2DekRankRows()',
    '                    * uamm2DekCards'
    'PerRank()',
    '                    + uamm2DekJokers()',
    '                    != uamm2DekCard'
    'Count())',
    '                ++bad;',
    '            // ten eggs of reason',
    '            // raise an 18+ score',
    '            // one point',
    '            if (10 * uamm2EgrEggs'
    'PerPointAbove18()',
    '                    != 100) ++bad;',
    '            // the thievery locks',
    '            // outrank the pockets',
    '            if (uamm3GthOpenLocks'
    'Level()',
    '                    <= uamm3GthPick'
    'PocketsLevel())',
    '                ++bad;',
    '            // the fog drift band',
    '            // runs 2-8 minutes',
    '            if (uamm3HfgDriftMinutes'
    'Lo()',
    '                    >= uamm3HfgDrift'
    'MinutesHi())',
    '                ++bad;',
    '            // the anything tail is',
    '            // one day - 24 hours',
    '            if (uammAnyLongTermHours()',
    '                    != uammAnyLongTerm'
    'UseLimit() * 8) ++bad;',
    '            // the lens diameter is',
    '            // one and a half inches',
    '            if (uamm4LulDiameter'
    'TenthsIn()',
    '                    / 10 != 1) ++bad;',
    '            if (uamm4LulDiameter'
    'TenthsIn()',
    '                    % 10 != 5) ++bad;',
    '            // the lead band is the',
    '            // iron band divided by',
    '            // five at both ends',
    '            if (uamm4PstIronLbsLo()',
    '                    / 5 != uamm4Pst'
    'LeadLbsLo())',
    '                ++bad;',
    '            if (uamm4PstIronLbsHi()',
    '                    / 5 != uamm4Pst'
    'LeadLbsHi())',
    '                ++bad;',
    '            // the prison shrink is',
    '            // a quarter foot',
    '            if (4 * uamm4PzaShrinks'
    'ToHeightIn()',
    '                    != 12) ++bad;',
    '        // ---- the ledger seam ----',
    '            // all six part ledgers',
    '            // run clean, no flags',
    '            if (uammPartCleanCount()',
    '                    != uammPart'
    'ItemTotal())',
    '                ++bad;',
    '            if (uammPartFlaggedCount()',
    '                    != 0) ++bad;',
    '            if (uamm2PartCleanCount()',
    '                    != uamm2Part'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamm2PartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '            if (uamm3PartCleanCount()',
    '                    != uamm3Part'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamm3PartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '            if (uamm4PartCleanCount()',
    '                    != uamm4Part'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamm4PartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '            if (uamm5PartCleanCount()',
    '                    != uamm5Part'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamm5PartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '            if (uamm6PartCleanCount()',
    '                    != uamm6Part'
    'ItemTotal())',
    '                ++bad;',
    '            if (uamm6PartFlagged'
    'Count()',
    '                    != 0) ++bad;',
    '        printf("R398 UA misc magic holes'
    ' pin audit: bad %d' + chr(92)
    + 'n", bad);',
    '        if (bad) return 1;',
    '    }'])

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, NL.join(AUD) + NL + R227,
     'regtest: the R398 audit block')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 325:
    die('the census %d' % s.count('audit: bad'))
if s.count('R398 UA misc magic holes'
           ' pin audit') != 1:
    die('the R398 audit label')

for nm in FLAGS:
    if ('!' + nm + '()') in s:
        die('the %s old assert' % nm)
    if s.count('%s()' % nm) != 1:
        die('the %s assert count' % nm)

for expr, val in (
        ('uammPartCleanCount()', 13),
        ('uammPartFlaggedCount()', 0),
        ('uamm2PartCleanCount()', 8),
        ('uamm2PartFlaggedCount()', 0),
        ('uamm3PartCleanCount()', 11),
        ('uamm3PartFlaggedCount()', 0),
        ('uamm4PartCleanCount()', 9),
        ('uamm4PartFlaggedCount()', 0),
        ('uamm5PartCleanCount()', 11),
        ('uamm5PartFlaggedCount()', 0),
        ('uamm6PartCleanCount()', 5),
        ('uamm6PartFlaggedCount()', 0)):
    oA, oB = forms('%s != %d'
                   % (expr, val))
    n = s.count(oA) + s.count(oB)
    if n != 2:
        die('the flipped %s count %d'
            % (expr, n))

if s.count('uamm4LulDiameter'
           'TenthsIn()') != 4:
    die('the lens value count')
if s.count('uamm4PstIronLbsLo()') != 4:
    die('the stone iron lo count')
if s.count('uamm4PzaShrinksToHeight'
           'In()') != 3:
    die('the prison value count')
if 'uamm4LulDiameterIn()' in s:
    die('the old lens pin lingers')
if 'uamm4PstIronLbsPerStone()' in s:
    die('the old stone pin lingers')
if 'uamm4PzaShrinksToHeightFt()' in s:
    die('the old prison pin lingers')

WANT_INLINE = {P1: 132, P2: 122, P3: 117,
               P4: 133, P5: 135, P6: 85}
WANT_FALSE = {P1: 6, P2: 7, P3: 9,
              P4: 4, P5: 4, P6: 3}

for path in (P1, P2, P3, P4, P5, P6):
    p = rd(path)
    if p.count('inline') \
            != WANT_INLINE[path]:
        die('%s inline count %d,'
            ' expected %d'
            % (path, p.count('inline'),
               WANT_INLINE[path]))
    if p.count('return false;') \
            != WANT_FALSE[path]:
        die('%s false count %d,'
            ' expected %d'
            % (path, p.count('return false;'),
               WANT_FALSE[path]))
    if not p.endswith(NL):
        die('%s trailing newline' % path)

g = rd(GP)
if g.count('AMENDED R398') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R398'))

print('R398 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean PDF read fills'
      ' every flagged hole')
print('  the six misc magic prose parts'
      ' carry - all 33 flags')
print('  drop, the four provisional pins'
      ' correct, and every')
print('  part ledger runs clean;'
      ' census 324 -> 325')
print('commit: R398: the UA misc magic'
      ' flagged holes completion'
      ' (census 325)')

