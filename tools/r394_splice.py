
#!/usr/bin/env python3
# R394: the UA DM tables manifest sweep
#
# The clean PDF read (pp. 74, 76,
# 82-83, 106-108) fills the flagged
# holes and closes the DM tables
# manifest:
#
# 1. rules/uasmalls1.h (R370): the
#    Method V dice-count table - the
#    full 12 x 7 matrix pins cell by
#    cell; the barding movement
#    columns REPIN (a divergence fix:
#    the R370 labels sat one column
#    off - light scale 15 chain NA,
#    medium scale 15 chain 12, heavy
#    leather 15 scale 14 chain 13).
# 2. rules/uasocialclass.h (R367): the
#    LLC label cell reads clean (the
#    roster head is Freed slaves); the
#    halfling parenthetical confirms
#    the band.
# 3. rules/uabirth.h (R367): the
#    high-elf sign pins negative
#    (-20); the section intro reads
#    clean.
# 4. rules/uaappendq.h (R389): every
#    flagged hole fills (the System I
#    six-foot example, the pummeling
#    row bodies with the merged
#    middle column, the large-object
#    damage 1-4, the acrobat tumbling
#    note, the kicking tail, the
#    grappling fills, the overbearing
#    AC prose); all six parts fully
#    clean.
#
# The regtest R367/R370/R389 audit
# blocks amend to the filled reads
# (the R391b precedent); a new R394
# audit block lands before the R227
# anchor; the census 320 -> 321. Ten
# DM-manifest items flip CLOSED (the
# Clerical Quick Reference rides the
# Appendix S OUT; Treasure Table III
# stays open on the III.A-III.H row
# bodies); the seed takes the R393
# record.
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
    raise SystemExit('R394 splice ABORT: ' + msg)


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


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = B(
    '- R393 landed 2026-10-13: commit',
    '  b069288, census 320, the',
    '  PDF-read completion sweep: the',
    '  clean PDF fills the three',
    '  fragment-round holes -',
    '  weaponspec.h all 24 spec',
    '  cells plus the superseding',
    '  note; thiefarmor.h the Open',
    '  Locks 0/-5/-10, no-armor',
    '  dashes, band-2 2/1,',
    '  footnote-1 tail, footnote-4',
    '  orphaned (the print anomaly);',
    '  uailacquisition.h the IL',
    '  starting list column-wise',
    '  decode (the R365 interleave',
    '  corrected). regtest',
    '  R331/R334/R365 amend to the',
    '  filled reads; the R393 audit',
    '  lands before the R227 anchor;',
    '  the three gap items flip',
    '  AMENDED R393: closed. The',
    '  body was rebuilt semantically',
    '  after the sandbox lost the',
    '  verified original (the',
    '  published md5 differs by',
    '  design); the Termux copy via',
    '  ./nn hashed differently yet',
    '  passed the battery - the ./nn',
    '  save path may not be',
    '  byte-faithful; verify the tail',
    '  bytes next round.').rstrip(NL)
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R393 landed 2026-10-13' in s:
    already.append('seed: the R393 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R393 record')
s = rd(SD)
if s.count('R393 landed 2026-10-13') != 1:
    die('the R393 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) uasmalls1.h ============
SM = 'rules/uasmalls1.h'

pair(SM, B(
    '//   - the barding table: light 21/15'
    ' with scale and',
    '//     plate not allowed, medium'
    ' 17/15 with the scale',
    '//     cell garbled and plate not'
    ' allowed, heavy',
    '//     14/13/12 with the leather'
    ' cell lost - the two',
    '//     lost cells flagged pending'
    ' the PDF; the',
    '//     endurance, magical-barding'
    ' and other-steeds',
    '//     prose prints clean.',
    '').rstrip(NL), B(
    '//   - R394: the clean PDF read fills'
    ' the',
    '//     Method V dice-count table (the'
    ' 12 x 7',
    '//     matrix cell by cell) and repins'
    ' the',
    '//     barding columns - the R370'
    ' labels sat',
    '//     one column off: light leather'
    ' 21 scale',
    '//     15 chain NA, medium 17/15/12,'
    ' heavy',
    '//     leather 15 scale 14 chain 13'
    ' plate 12.',
    '').rstrip(NL), 'smalls: the header note')

pair(SM, B(
    '// The dice-count table body extracts'
    ' empty -',
    '// every cell a hole pending the PDF.',
    'inline bool uasm1MethodVTableCellsLost()',
    '    { return true; }'),
    B(
    '// The dice-count table body extracts',
    '// empty in the markdown; the R394',
    '// clean PDF read fills the matrix.',
    'inline bool uasm1MethodVTableCellsLost()',
    '    { return false; }'),
    'smalls: the Method V cells marker')

pair(SM, B(
    'inline int uasm1BardLightChain()',
    '    { return 15; }',
    '',
    'inline bool uasm1BardLightScaleNa()',
    '    { return true; }'),
    B(
    '// The R394 clean read: the light row',
    '// is leather 21, scale 15, chain NA',
    '// - the R370 15 sat on the scale',
    '// cell and the NA on the chain.',
    'inline int uasm1BardLightScale()',
    '    { return 15; }',
    '',
    'inline bool uasm1BardLightChainNa()',
    '    { return true; }',
    '',
    'inline int uasm1BardLightChain()',
    '    { return 0; }',
    '',
    'inline bool uasm1BardLightScaleNa()',
    '    { return false; }'),
    'smalls: the light barding row')

pair(SM, B(
    'inline int uasm1BardMediumChain()',
    '    { return 15; }',
    '',
    '// The medium scale cell garbles in the',
    '// extract - a hole pending the PDF.',
    'inline bool uasm1BardMediumScaleCellLost()',
    '    { return true; }'),
    B(
    '// The R394 clean read: medium scale',
    '// 15, chain 12 - the R370 15 was',
    '// the scale value on the chain cell.',
    'inline int uasm1BardMediumScale()',
    '    { return 15; }',
    '',
    'inline int uasm1BardMediumChain()',
    '    { return 12; }',
    '',
    'inline bool uasm1BardMediumScaleCellLost()',
    '    { return false; }'),
    'smalls: the medium barding row')

pair(SM, B(
    '// The heavy leather cell is lost - a'
    ' hole',
    '// pending the PDF.',
    'inline bool uasm1BardHeavyLeatherCellLost()',
    '    { return true; }',
    '',
    'inline int uasm1BardHeavyChain()',
    '    { return 14; }',
    '',
    'inline int uasm1BardHeavyScale()',
    '    { return 13; }'),
    B(
    '// The R394 clean read: the heavy row',
    '// is leather 15, scale 14, chain 13',
    '// - the R370 values sat one column',
    '// left.',
    'inline int uasm1BardHeavyLeather()',
    '    { return 15; }',
    '',
    'inline bool uasm1BardHeavyLeatherCellLost()',
    '    { return false; }',
    '',
    'inline int uasm1BardHeavyChain()',
    '    { return 13; }',
    '',
    'inline int uasm1BardHeavyScale()',
    '    { return 14; }'),
    'smalls: the heavy barding row')

MVSEC = B(
    '// ---- the Method V dice-count',
    '// table (p. 74, the R394 clean',
    '// read) ----',
    '// Rows: 0 Cavalier, 1 Paladin,',
    '// 2 Cleric, 3 Druid, 4 Fighter,',
    '// 5 Barbarian, 6 Ranger,',
    '// 7 Magic-user, 8 Illusionist,',
    '// 9 Thief, 10 Assassin, 11 Monk.',
    '// Columns: 0 Str, 1 Int, 2 Wis,',
    '// 3 Dex, 4 Con, 5 Cha, 6 Com.',
    'inline int uasm1MethodVClassCount()',
    '    { return 12; }',
    '',
    'inline int uasm1MethodVAbilityCount()',
    '    { return 7; }',
    '',
    'inline int uasm1MethodVDice(int cls,'
    ' int ab) {',
    '    static const int k[12][7] = {',
    '        {8, 6, 4, 7, 9, 3, 5},',
    '        {7, 5, 8, 3, 6, 9, 4},',
    '        {7, 4, 9, 5, 8, 6, 3},',
    '        {7, 4, 8, 5, 6, 9, 3},',
    '        {9, 3, 5, 7, 8, 6, 4},',
    '        {9, 3, 5, 7, 8, 6, 4},',
    '        {7, 6, 8, 5, 9, 4, 3},',
    '        {4, 9, 7, 8, 6, 5, 3},',
    '        {3, 8, 7, 9, 5, 6, 4},',
    '        {6, 5, 3, 9, 7, 4, 8},',
    '        {6, 7, 4, 9, 8, 3, 5},',
    '        {7, 5, 9, 8, 6, 4, 3},',
    '    };',
    '    if (cls < 0) cls = 0;',
    '    if (cls > 11) cls = 11;',
    '    if (ab < 0) ab = 0;',
    '    if (ab > 6) ab = 6;',
    '    return k[cls][ab];',
    '}',
    '').rstrip(NL)
pair(SM, B(
    '// ---- the barding movement table'
    ' (p. 76) ----'),
    MVSEC + NL + NL +
    '// ---- the barding movement table'
    ' (p. 76) ----',
    'smalls: the Method V matrix section')

# ========== (c) uasocialclass.h ==========
SC = 'rules/uasocialclass.h'

pair(SC, B(
    '//   - the halfling placement prints'
    ' "ULC (they are',
    '//     small and rustic)" - the'
    ' parenthetical reads',
    '//     against the printed band; the'
    ' print wins, the',
    '//     divergence flagged pending the'
    ' PDF.',
    '').rstrip(NL), B(
    '//   - the halfling placement prints'
    ' "ULC (they are',
    '//     small and rustic)" - the'
    ' parenthetical reads',
    '//     against the printed band; the'
    ' print wins, the',
    '//     divergence flagged pending the'
    ' PDF.',
    '//   - R394: the clean PDF read fills'
    ' the LLC',
    '//     label cell (the roster head is'
    ' Freed',
    '//     slaves) and confirms the'
    ' halfling',
    '//     parenthetical.',
    '').rstrip(NL), 'social: the header note')

pair(SC, B(
    '    static const char* const r0[8] = {',
    '        "slaves", "peasants",'
    ' "tinkers",'),
    B(
    '    static const char* const r0[8] = {',
    '        "Freed slaves", "peasants",',
    '        "tinkers",'),
    'social: the LLC roster head')

pair(SC, B(
    'inline bool uasocLlcLabelCellGarbled()',
    '    { return true; }'),
    B(
    '// The R394 clean read: the LLC label',
    '// cell reads clean.',
    'inline bool uasocLlcLabelCellGarbled()',
    '    { return false; }'),
    'social: the LLC label marker')

pair(SC, B(
    'inline bool'
    ' uasocHalflingParentheticalDivergence()',
    '    { return true; }'),
    B(
    '// The R394 clean read: the halfling',
    '// parenthetical confirms the ULC',
    '// band.',
    'inline bool'
    ' uasocHalflingParentheticalDivergence()',
    '    { return false; }'),
    'social: the halfling marker')

# ============ (d) uabirth.h ============
UB = 'rules/uabirth.h'

pair(UB, B(
    '// The high-elf cell prints a bare 20'
    ' - the sign is',
    '// lost in the print; the magnitude'
    ' pins.',
    'inline int uabirthElfHighModMagnitude()',
    '    { return 20; }',
    '',
    'inline bool uabirthElfHighModSignLost()',
    '    { return true; }'),
    B(
    '// The R394 clean read: the high-elf',
    '// cell prints -20 - the sign pins',
    '// negative like every other cell.',
    'inline int uabirthElfHighModMagnitude()',
    '    { return 20; }',
    '',
    'inline int uabirthElfHighMod()',
    '    { return -20; }',
    '',
    'inline bool uabirthElfHighModSignLost()',
    '    { return false; }'),
    'birth: the high-elf sign')

pair(UB, B(
    'inline bool uabirthIntroGarbled()',
    '    { return true; }'),
    B(
    '// The R394 clean read: the section',
    '// intro reads clean in the PDF.',
    'inline bool uabirthIntroGarbled()',
    '    { return false; }'),
    'birth: the intro marker')

# ========== (e) uaappendq.h ==========
UQ = 'rules/uaappendq.h'

pair(UQ, B(
    'inline bool uaqSysOneSixFtExampleGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqSysOneSixFtExampleGarbles()',
    '    { return false; }'),
    'appendq: the System I marker')

pair(UQ, B(
    'inline bool uaqPumDemonExceptionGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqPumDemonExceptionGarbles()',
    '    { return false; }'),
    'appendq: the demon marker')

pair(UQ, B(
    '// The Pummeling Table: 3',
    '// vulnerability rows by 4',
    '// object columns, the',
    '// chance per point of',
    '// strength of stunning;',
    'inline int uaqPumTableRows()',
    '    { return 3; }',
    '',
    'inline int uaqPumTableCols()',
    '    { return 4; }'),
    B(
    '// The Pummeling Table: 3',
    '// vulnerability rows by 3 data',
    '// columns (the R394 clean read: the',
    '// print merges small hard with',
    '// large soft in the middle',
    '// column), the chance per point of',
    '// strength of stunning;',
    'inline int uaqPumTableRows()',
    '    { return 3; }',
    '',
    'inline int uaqPumTableCols()',
    '    { return 3; }'),
    'appendq: the pummeling cols repin')

pair(UQ, B(
    'inline bool uaqPumTableRowBodiesGarble()',
    '    { return true; }'),
    B(
    'inline bool uaqPumTableRowBodiesGarble()',
    '    { return false; }'),
    'appendq: the row-bodies marker')

pair(UQ, B(
    'inline bool uaqPumLargeDamageCellsGarble()',
    '    { return true; }'),
    B(
    'inline bool uaqPumLargeDamageCellsGarble()',
    '    { return false; }'),
    'appendq: the large-damage marker')

pair(UQ, B(
    'inline bool uaqPumThiefTumblingNoteGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqPumThiefTumblingNoteGarbles()',
    '    { return false; }'),
    'appendq: the tumbling marker')

pair(UQ, B(
    'inline bool uaqKickSmallerTailGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqKickSmallerTailGarbles()',
    '    { return false; }'),
    'appendq: the kicking marker')

pair(UQ, B(
    'inline bool uaqGrapPurposeSentenceGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqGrapPurposeSentenceGarbles()',
    '    { return false; }'),
    'appendq: the grap purpose marker')

pair(UQ, B(
    'inline bool uaqGrapLargerWordGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqGrapLargerWordGarbles()',
    '    { return false; }'),
    'appendq: the grap word marker')

pair(UQ, B(
    'inline bool uaqGrapStr17ExampleTailGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqGrapStr17ExampleTailGarbles()',
    '    { return false; }'),
    'appendq: the Str-17 marker')

pair(UQ, B(
    'inline bool uaqGrapDefMBandsGarble()',
    '    { return true; }'),
    B(
    'inline bool uaqGrapDefMBandsGarble()',
    '    { return false; }'),
    'appendq: the grap M-band marker')

pair(UQ, B(
    'inline bool uaqOvbAcProseGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqOvbAcProseGarbles()',
    '    { return false; }'),
    'appendq: the ovb prose marker')

pair(UQ, B(
    'inline bool uaqOvbWeakestSentenceGarbles()',
    '    { return true; }'),
    B(
    'inline bool uaqOvbWeakestSentenceGarbles()',
    '    { return false; }'),
    'appendq: the weakest marker')

pair(UQ, B(
    '// The part ledger: six',
    '// items, one fully clean,',
    '// five flagged, none fully',
    '// garbled.',
    'inline int uaqPartItemTotal()',
    '    { return 6; }',
    '',
    'inline int uaqPartCleanCount()',
    '    { return 1; }',
    '',
    'inline int uaqPartFlaggedCount()',
    '    { return 5; }'),
    B(
    '// The part ledger: six items - the',
    '// R394 clean read fills every',
    '// flagged hole; all six fully',
    '// clean, none garbled.',
    'inline int uaqPartItemTotal()',
    '    { return 6; }',
    '',
    'inline int uaqPartCleanCount()',
    '    { return 6; }',
    '',
    'inline int uaqPartFlaggedCount()',
    '    { return 0; }'),
    'appendq: the part ledger')

UQSEC = B(
    '// ---- the R394 clean-read fills ----',
    '// The clean PDF pages 106-108 fill',
    '// every flagged hole of the R389 pin.',
    '',
    '// System I: the six-foot example -',
    '// a six-foot being affects creatures',
    '// 7 1/2 feet or shorter.',
    'inline int uaqSysOneSixFtExampleFt()',
    '    { return 6; }',
    '',
    'inline int uaqSysOneSixFtLimitTenths()',
    '    { return 75; }',
    '',
    '// Pummeling: all demons, though not',
    '// semi-demons.',
    'inline bool uaqPumSemiDemonException()',
    '    { return true; }',
    '',
    '// The Pummeling Table row bodies: the',
    '// print merges small hard with large',
    '// soft in the middle column.',
    'inline bool uaqPumMergedMiddleColumn()',
    '    { return true; }',
    '',
    '// Unexposed: no effect small soft;',
    '// 1 percent per point and 20 at',
    '// 18/01 merged; 2 percent and 40',
    '// large hard.',
    'inline bool uaqPumUnexSmallSoftNoEffect()',
    '    { return true; }',
    '',
    'inline int uaqPumUnexMergedPerPt()',
    '    { return 1; }',
    '',
    'inline int uaqPumUnexMergedCap()',
    '    { return 20; }',
    '',
    'inline int uaqPumUnexLargeHardPerPt()',
    '    { return 2; }',
    '',
    'inline int uaqPumUnexLargeHardCap()',
    '    { return 40; }',
    '',
    '// Semi-exposed: 1 and 20 small soft;',
    '// 2 and 40 merged; 4 and 75 large',
    '// hard.',
    'inline int uaqPumSemiSmallSoftPerPt()',
    '    { return 1; }',
    '',
    'inline int uaqPumSemiSmallSoftCap()',
    '    { return 20; }',
    '',
    'inline int uaqPumSemiMergedPerPt()',
    '    { return 2; }',
    '',
    'inline int uaqPumSemiMergedCap()',
    '    { return 40; }',
    '',
    'inline int uaqPumSemiLargeHardPerPt()',
    '    { return 4; }',
    '',
    'inline int uaqPumSemiLargeHardCap()',
    '    { return 75; }',
    '',
    '// The large-object damage: all large',
    '// objects inflict 1-4.',
    'inline int uaqPumLargeDamageLo()',
    '    { return 1; }',
    '',
    'inline int uaqPumLargeDamageHi()',
    '    { return 4; }',
    '',
    '// The thief-acrobat tumbling note: the',
    '// Tumbling Attack percentage adds to',
    '// the own stun chance, capped at 95;',
    '// the Tumbling Defense percentage',
    '// subtracts from the attacker chance',
    '// while tumbling.',
    'inline bool uaqPumAcrobatAttackAdds()',
    '    { return true; }',
    '',
    'inline int uaqPumAcrobatStunCap()',
    '    { return 95; }',
    '',
    'inline bool uaqPumAcrobatDefenseSubtracts()',
    '    { return true; }',
    '',
    '// Kicking: a smaller target counts the',
    '// overall armor, the most vulnerable',
    '// read.',
    'inline bool uaqKickSmallerOverallArmor()',
    '    { return true; }',
    '',
    '// Grappling: the Str-17 example - an',
    '// effective armor class one step',
    '// better than usual.',
    'inline bool uaqGrapStr17OneStepBetterAc()',
    '    { return true; }',
    '',
    '// The size-M band: three size-M',
    '// attackers, or one or two size-L.',
    'inline int uaqGrapDefMBySizeLHi()',
    '    { return 2; }',
    '',
    '// Overbearing: all defensive bonuses',
    '// count; the effective AC modifies for',
    '// relative size and for four or more',
    '// legs.',
    'inline bool uaqOvbAllBonusesConsidered()',
    '    { return true; }',
    '',
    'inline bool'
    ' uaqOvbAcModifiedForRelativeSize()',
    '    { return true; }',
    '',
    'inline bool uaqOvbAcAffectedFourPlusLegs()',
    '    { return true; }',
    '').rstrip(NL)
pair(UQ, '}   // namespace rules',
    UQSEC + NL + '}   // namespace rules',
    'appendq: the R394 fill section')

# ========= (f) the gap report ==========
GP = 'tools/ua_gap_report.md'

pair(GP, B(
    '        the dice-count table cells',
    '        extract empty - the cell',
    '        body a hole in-header',
    '        pending the PDF; CLOSED.'),
    B(
    '        the dice-count table cells',
    '        extract empty in the',
    '        markdown - the R394 clean',
    '        PDF read fills the 12 x 7',
    '        matrix cell by cell;',
    '        CLOSED clean.'),
    'gap: the Method V item')

pair(GP, B(
    '        percentage sums',
    '        cross-check; CLOSED.'),
    B(
    '        percentage sums',
    '        cross-check; the R394 clean',
    '        read repins the columns',
    '        (light 21/15/NA/NA, medium',
    '        17/15/12/NA, heavy',
    '        15/14/13/12 - the R370',
    '        heavy values sat one',
    '        column left); CLOSED clean.'),
    'gap: the warhorse item')

pair(GP, B(
    '        profession rule; the LLC label',
    '        cell garbles and the halfling',
    '        ULC parenthetical divergence',
    '        flagged pending the PDF; the',
    '        R336 seam cross-checks the',
    '        cavalier money stations.'),
    B(
    '        profession rule; the LLC label',
    '        cell garbles and the halfling',
    '        ULC parenthetical divergence',
    '        flagged pending the PDF - the',
    '        R394 clean read fills the',
    '        label (Freed slaves) and',
    '        confirms the parenthetical;',
    '        the R336 seam cross-checks the',
    '        cavalier money stations.'),
    'gap: the social class item')

pair(GP, B(
    '        the section intro garbles and',
    '        the high-elf sign cell lost -',
    '        flagged in-header pending the',
    '        PDF.'),
    B(
    '        the section intro garbles and',
    '        the high-elf sign cell lost -',
    '        the R394 clean read fills',
    '        both (the intro clean, the',
    '        sign negative -20).'),
    'gap: the birth item')

pair(GP, B(
    '        pins as its own data layer -',
    '        the R374 dial precedent),',
    '        stays PDF-gated only.'),
    B(
    '        pins as its own data layer -',
    '        the R374 dial precedent),',
    '        stays PDF-gated only.',
    '      - AMENDED R394: closed - the',
    '        clean pp. 106-108 read fills',
    '        every flagged hole (the System',
    '        I six-foot example, the',
    '        pummeling row bodies and',
    '        large-object damage, the',
    '        acrobat tumbling note, the',
    '        kicking tail, the grappling',
    '        purpose and size word and',
    '        Str-17 tail and M-band, the',
    '        overbearing AC prose and',
    '        weakest tail, the demon',
    '        exception); all six parts',
    '        fully clean.'),
    'gap: the Appendix Q item')

pair(GP, B(
    '- [ ] Armor, Types and Encumbrance (p.',
    '      75) - the armor table item'
    ' above.'),
    B(
    '- [x] Armor, Types and Encumbrance (p.',
    '      75).',
    '      - CLOSED R371 (rules/uaarmor.h);',
    '        the R394 manifest sweep.'),
    'gap: the armor manifest item')

pair(GP, B(
    '- [ ] Barded Warhorse Movement Rate (p.',
    '      76).'),
    B(
    '- [x] Barded Warhorse Movement Rate (p.',
    '      76).',
    '      - CLOSED R370 + the R394 clean',
    '        read (the column repin,',
    '        rules/uasmalls1.h).'),
    'gap: the barding manifest item')

pair(GP, '- [ ] Birth Table (p. 83).',
    B(
    '- [x] Birth Table (p. 83).',
    '      - CLOSED R367 (rules/uabirth.h);',
    '        the R394 clean read confirms.'),
    'gap: the birth manifest item')

pair(GP, B(
    '- [ ] Character Generation Method V (p.',
    '      74).'),
    B(
    '- [x] Character Generation Method V (p.',
    '      74).',
    '      - CLOSED R370 + the R394 clean',
    '        read (the dice-count matrix,',
    '        rules/uasmalls1.h).'),
    'gap: the Method V manifest item')

pair(GP, '- [ ] Hit Points, Starting (p. 74).',
    B(
    '- [x] Hit Points, Starting (p. 74).',
    '      - CLOSED R370'
    ' (rules/uasmalls1.h).'),
    'gap: the hit points manifest item')

pair(GP, B(
    '- [ ] Illusionist Spells, Starting List',
    '      (p. 80).'),
    B(
    '- [x] Illusionist Spells, Starting List',
    '      (p. 80).',
    '      - CLOSED R365 + the R393 clean',
    '        read (rules/uailacquisition.h).'),
    'gap: the IL list manifest item')

pair(GP, B(
    '- [ ] Overbearing, Armor Class',
    '      Adjustments (p. 108).'),
    B(
    '- [x] Overbearing, Armor Class',
    '      Adjustments (p. 108).',
    '      - CLOSED R389 + the R394 clean',
    '        read (the AC prose fill,',
    '        rules/uaappendq.h).'),
    'gap: the overbearing manifest item')

pair(GP, B(
    '- [ ] Parents Marital Status Table (p.',
    '      83).'),
    B(
    '- [x] Parents Marital Status Table (p.',
    '      83).',
    '      - CLOSED R367 (rules/uabirth.h).'),
    'gap: the marital manifest item')

pair(GP, B(
    '- [ ] Pummeling Table, Chance of',
    '      Stunning (p. 107).'),
    B(
    '- [x] Pummeling Table, Chance of',
    '      Stunning (p. 107).',
    '      - CLOSED R389 + the R394 clean',
    '        read (the row bodies,',
    '        rules/uaappendq.h).'),
    'gap: the pummeling manifest item')

pair(GP, '- [ ] Social Class Table (p. 82).',
    B(
    '- [x] Social Class Table (p. 82).',
    '      - CLOSED R367 + the R394 clean',
    '        read (the LLC label fill,',
    '        rules/uasocialclass.h).'),
    'gap: the social manifest item')

# ========== (g) regtest.cpp ==========
RT = 'regtest.cpp'

pair(RT, '            if (!uasocLlcLabelCell'
    'Garbled()) ++bad;',
    '            if (uasocLlcLabelCell'
    'Garbled()) ++bad;',
    'regtest R367: the LLC assert')

pair(RT, '            if (!uasocHalfling'
    'ParentheticalDivergence()) ++bad;',
    '            if (uasocHalfling'
    'ParentheticalDivergence()) ++bad;',
    'regtest R367: the halfling assert')

pair(RT, '            if (!uabirthElfHigh'
    'ModSignLost()) ++bad;',
    '            if (uabirthElfHigh'
    'ModSignLost()) ++bad;',
    'regtest R367: the high-elf assert')

pair(RT, '            if (!uabirthIntro'
    'Garbled()) ++bad;',
    '            if (uabirthIntro'
    'Garbled()) ++bad;',
    'regtest R367: the intro assert')

pair(RT, B(
    '            if (!uasm1MethodV'
    'TableCellsLost())',
    '                ++bad;'),
    B(
    '            if (uasm1MethodV'
    'TableCellsLost())',
    '                ++bad;'),
    'regtest R370: the Method V assert')

pair(RT, B(
    '            if (uasm1BardLightChain()'
    ' != 15)',
    '                ++bad;'),
    B(
    '            if (!uasm1BardLight'
    'ChainNa())',
    '                ++bad;',
    '            if (uasm1BardLightScale()'
    ' != 15)',
    '                ++bad;'),
    'regtest R370: the light asserts')

pair(RT, '            if (!uasm1BardLight'
    'ScaleNa()) ++bad;',
    '            if (uasm1BardLight'
    'ScaleNa()) ++bad;',
    'regtest R370: the light NA assert')

pair(RT, B(
    '            if (uasm1BardMediumChain()'
    ' != 15)',
    '                ++bad;'),
    B(
    '            if (uasm1BardMediumChain()'
    ' != 12)',
    '                ++bad;'),
    'regtest R370: the medium chain')

pair(RT, B(
    '            if (!uasm1BardMedium'
    'ScaleCellLost())',
    '                ++bad;'),
    B(
    '            if (uasm1BardMedium'
    'ScaleCellLost())',
    '                ++bad;',
    '            if (uasm1BardMediumScale()'
    ' != 15)',
    '                ++bad;'),
    'regtest R370: the medium scale')

pair(RT, B(
    '            if (!uasm1BardHeavy'
    'LeatherCellLost())',
    '                ++bad;'),
    B(
    '            if (uasm1BardHeavy'
    'LeatherCellLost())',
    '                ++bad;',
    '            if (uasm1BardHeavyLeather()'
    ' != 15)',
    '                ++bad;'),
    'regtest R370: the heavy leather')

pair(RT, B(
    '            if (uasm1BardHeavyChain()'
    ' != 14)',
    '                ++bad;'),
    B(
    '            if (uasm1BardHeavyChain()'
    ' != 13)',
    '                ++bad;'),
    'regtest R370: the heavy chain')

pair(RT, B(
    '            if (uasm1BardHeavyScale()'
    ' != 13)',
    '                ++bad;'),
    B(
    '            if (uasm1BardHeavyScale()'
    ' != 14)',
    '                ++bad;'),
    'regtest R370: the heavy scale')

pair(RT, B(
    '            if (uasm1BardHeavyChain()',
    '                    <= uasm1BardHeavy'
    'Scale()) ++bad;',
    '            if (uasm1BardHeavyScale()',
    '                    <= uasm1BardHeavy'
    'Plate()) ++bad;'),
    B(
    '            if (uasm1BardHeavyLeather()',
    '                    <= uasm1BardHeavy'
    'Scale()) ++bad;',
    '            if (uasm1BardHeavyChain()',
    '                    <= uasm1BardHeavy'
    'Plate()) ++bad;'),
    'regtest R370: the monotonic pair')

R389_FLIPS = [
    ('uaqSysOneSixFtExampleGarbles',
     'regtest R389: the System I flip'),
    ('uaqPumDemonExceptionGarbles',
     'regtest R389: the demon flip'),
    ('uaqPumTableRowBodiesGarble',
     'regtest R389: the row-bodies flip'),
    ('uaqPumLargeDamageCellsGarble',
     'regtest R389: the large-damage flip'),
    ('uaqPumThiefTumblingNoteGarbles',
     'regtest R389: the tumbling flip'),
    ('uaqKickSmallerTailGarbles',
     'regtest R389: the kicking flip'),
    ('uaqGrapPurposeSentenceGarbles',
     'regtest R389: the purpose flip'),
    ('uaqGrapLargerWordGarbles',
     'regtest R389: the word flip'),
    ('uaqGrapStr17ExampleTailGarbles',
     'regtest R389: the Str-17 flip'),
    ('uaqGrapDefMBandsGarble',
     'regtest R389: the M-band flip'),
    ('uaqOvbAcProseGarbles',
     'regtest R389: the prose flip'),
    ('uaqOvbWeakestSentenceGarbles',
     'regtest R389: the weakest flip'),
]
for fn, lab in R389_FLIPS:
    pair(RT, '            if (!' + fn
        + '()) ++bad;',
        '            if (' + fn
        + '()) ++bad;', lab)

pair(RT, '            if (uaqPumTableCols()'
    ' != 4) ++bad;',
    '            if (uaqPumTableCols()'
    ' != 3) ++bad;',
    'regtest R389: the cols assert')

pair(RT, '            if (uaqPartCleanCount()'
    ' != 1) ++bad;',
    '            if (uaqPartCleanCount()'
    ' != 6) ++bad;',
    'regtest R389: the clean ledger')

pair(RT, '            if (uaqPartFlaggedCount()'
    ' != 5) ++bad;',
    '            if (uaqPartFlaggedCount()'
    ' != 0) ++bad;',
    'regtest R389: the flagged ledger')

R394BLK = B(
    '    // ---- R394: the UA DM tables',
    '    // manifest sweep pin audit ----',
    '    // The clean PDF read (pp. 74, 76,',
    '    // 82-83, 106-108) fills the flagged',
    '    // holes and closes the DM tables',
    '    // manifest: Method V (the 12 x 7',
    '    // dice-count matrix), the barding',
    '    // movement column repin (the R370',
    '    // labels sat one column off), the',
    '    // LLC label, the high-elf sign, the',
    '    // Appendix Q hole set. Ten manifest',
    '    // items flip CLOSED; the census',
    '    // 320 -> 321.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the Method V matrix ----',
    '            static const int mv[12][7]'
    ' = {',
    '                {8, 6, 4, 7, 9, 3, 5},',
    '                {7, 5, 8, 3, 6, 9, 4},',
    '                {7, 4, 9, 5, 8, 6, 3},',
    '                {7, 4, 8, 5, 6, 9, 3},',
    '                {9, 3, 5, 7, 8, 6, 4},',
    '                {9, 3, 5, 7, 8, 6, 4},',
    '                {7, 6, 8, 5, 9, 4, 3},',
    '                {4, 9, 7, 8, 6, 5, 3},',
    '                {3, 8, 7, 9, 5, 6, 4},',
    '                {6, 5, 3, 9, 7, 4, 8},',
    '                {6, 7, 4, 9, 8, 3, 5},',
    '                {7, 5, 9, 8, 6, 4, 3},',
    '            };',
    '            if (uasm1MethodVClassCount()'
    ' != 12)',
    '                ++bad;',
    '            if (uasm1MethodVAbilityCount()'
    ' != 7)',
    '                ++bad;',
    '            for (int c = 0; c < 12; ++c) {',
    '                for (int a = 0; a < 7;'
    ' ++a) {',
    '                    if (uasm1MethodVDice('
    'c, a)',
    '                            != mv[c][a])'
    ' ++bad;',
    '                }',
    '            }',
    '            // the fighter strength cell',
    '            // matches the printed example',
    '            if (uasm1MethodVDice(4, 0)',
    '                    != uasm1MethodV'
    'FighterStrengthDice())',
    '                ++bad;',
    '            // every cell between 3 and 9',
    '            for (int c = 0; c < 12; ++c) {',
    '                for (int a = 0; a < 7;'
    ' ++a) {',
    '                    if (uasm1MethodVDice('
    'c, a) < 3)',
    '                        ++bad;',
    '                    if (uasm1MethodVDice('
    'c, a) > 9)',
    '                        ++bad;',
    '                }',
    '            }',
    '        // ---- the barding repin ----',
    '            if (uasm1BardLightLeather()',
    '                    <= uasm1BardLight'
    'Scale()) ++bad;',
    '            if (uasm1BardMediumLeather()',
    '                    <= uasm1BardMedium'
    'Scale()) ++bad;',
    '            if (uasm1BardMediumScale()',
    '                    <= uasm1BardMedium'
    'Chain()) ++bad;',
    '            if (uasm1BardHeavyLeather()',
    '                    <= uasm1BardHeavy'
    'Scale()) ++bad;',
    '            if (uasm1BardHeavyScale()',
    '                    <= uasm1BardHeavy'
    'Chain()) ++bad;',
    '            if (uasm1BardHeavyChain()',
    '                    <= uasm1BardHeavy'
    'Plate()) ++bad;',
    '            // the ladder: lighter horses',
    '            // run faster in leather',
    '            if (uasm1BardMediumLeather()',
    '                    <= uasm1BardHeavy'
    'Leather())',
    '                ++bad;',
    '        // ---- the social class fill ----',
    '            if (strcmp(uasocRosterName(0,'
    ' 0),',
    '                    "Freed slaves") != 0)'
    ' ++bad;',
    '            if (uasocLlcLabelCell'
    'Garbled()) ++bad;',
    '            if (uasocHalfling'
    'ParentheticalDivergence())',
    '                ++bad;',
    '        // ---- the birth fill ----',
    '            if (uabirthElfHighMod()'
    ' != -20) ++bad;',
    '            if (uabirthElfHighMod'
    'Magnitude() != 20) ++bad;',
    '            if (uabirthElfHighMod'
    'SignLost()) ++bad;',
    '        // ---- the Appendix Q fills ----',
    '            if (uaqSysOneSixFtExampleFt()'
    ' != 6)',
    '                ++bad;',
    '            if (uaqSysOneSixFtLimit'
    'Tenths() != 75)',
    '                ++bad;',
    '            // 6 feet at 125 percent is',
    '            // 75 tenths (7 1/2 feet)',
    '            if (uaqSysOneSixFtExampleFt()',
    '                    * uaqSysOneHeight'
    'PctLimit()',
    '                    / 10 != uaqSysOne'
    'SixFtLimitTenths())',
    '                ++bad;',
    '            if (!uaqPumSemiDemon'
    'Exception()) ++bad;',
    '            if (!uaqPumMergedMiddle'
    'Column()) ++bad;',
    '            if (!uaqPumUnexSmallSoft'
    'NoEffect())',
    '                ++bad;',
    '            if (uaqPumUnexMergedPerPt()'
    ' != 1) ++bad;',
    '            if (uaqPumUnexMergedCap()'
    ' != 20) ++bad;',
    '            if (uaqPumUnexLargeHardPerPt()'
    ' != 2)',
    '                ++bad;',
    '            if (uaqPumUnexLargeHardCap()'
    ' != 40)',
    '                ++bad;',
    '            if (uaqPumSemiSmallSoftPerPt()'
    ' != 1)',
    '                ++bad;',
    '            if (uaqPumSemiSmallSoftCap()'
    ' != 20)',
    '                ++bad;',
    '            if (uaqPumSemiMergedPerPt()'
    ' != 2) ++bad;',
    '            if (uaqPumSemiMergedCap()'
    ' != 40) ++bad;',
    '            if (uaqPumSemiLargeHardPerPt()'
    ' != 4)',
    '                ++bad;',
    '            if (uaqPumSemiLargeHardCap()'
    ' != 75)',
    '                ++bad;',
    '            // the exposed row completes',
    '            // the 3 x 3 walk (the R389',
    '            // pins seam-agree)',
    '            if (uaqPumExposedSmallSoft'
    'PerPt()',
    '                    != uaqPumSemi'
    'MergedPerPt())',
    '                ++bad;',
    '            if (uaqPumExposedSmallHard'
    'PerPt()',
    '                    != uaqPumSemi'
    'LargeHardPerPt())',
    '                ++bad;',
    '            // the R389 fragment pairs',
    '            // attribute to the cells',
    '            if (uaqPumFragPair1PerPt()',
    '                    != uaqPumSemi'
    'SmallSoftPerPt())',
    '                ++bad;',
    '            if (uaqPumFragPair2PerPt()',
    '                    != uaqPumSemi'
    'MergedPerPt())',
    '                ++bad;',
    '            if (uaqPumFragPair3PerPt()',
    '                    != uaqPumSemi'
    'LargeHardPerPt())',
    '                ++bad;',
    '            if (uaqPumUnexMergedPerPt()',
    '                    != uaqPumFrag'
    'Pair1PerPt())',
    '                ++bad;',
    '            if (uaqPumLargeDamageLo()'
    ' != 1) ++bad;',
    '            if (uaqPumLargeDamageHi()'
    ' != 4) ++bad;',
    '            if (!uaqPumAcrobat'
    'AttackAdds()) ++bad;',
    '            if (uaqPumAcrobatStunCap()'
    ' != 95) ++bad;',
    '            if (!uaqPumAcrobat'
    'DefenseSubtracts()) ++bad;',
    '            if (!uaqKickSmaller'
    'OverallArmor())',
    '                ++bad;',
    '            if (!uaqGrapStr17'
    'OneStepBetterAc())',
    '                ++bad;',
    '            if (uaqGrapDefMBySizeLHi()',
    '                    < uaqGrapDef'
    'SBySizeL())',
    '                ++bad;',
    '            if (!uaqOvbAllBonuses'
    'Considered()) ++bad;',
    '            if (!uaqOvbAcModified'
    'ForRelativeSize())',
    '                ++bad;',
    '            if (!uaqOvbAcAffected'
    'FourPlusLegs())',
    '                ++bad;',
    '        printf("R394 UA DM tables'
    ' manifest pin audit: bad %d' + NN
    + '", bad);',
    '        if (bad) return 1;',
    '    }',
    '').rstrip(NL)
pair(RT, '    // ---- R227: the wis mental'
    ' save wiring audit ----',
    R394BLK + NL + NL +
    '    // ---- R227: the wis mental'
    ' save wiring audit ----',
    'regtest: the R394 audit block')

# ========== the final verification ==========
s = rd(RT)
if s.count('audit: bad ') != 321:
    die('the regtest census %d (want 321)'
        % s.count('audit: bad '))
if s.count(
    'R394 UA DM tables manifest pin'
    ' audit: bad ') != 1:
    die('the R394 audit count %d'
        % s.count(
        'R394 UA DM tables manifest pin'
        ' audit: bad '))
if s.count(
    'R389 UA weaponless combat pin'
    ' audit: bad ') != 1:
    die('the kept R389 label')
if s.count(
    'R370 UA DM-section smalls pin'
    ' audit: bad ') != 1:
    die('the kept R370 label')
if s.count(
    'R227: the wis mental save wiring'
    ' audit') != 1:
    die('the kept R227 anchor')
s = rd(GP)
if s.count('AMENDED R394') != 1:
    die('the gap report amended count %d'
        % s.count('AMENDED R394'))
if s.count('CLOSED R394') != 0:
    die('an unexpected CLOSED R394')
sm = rd(SM)
if sm.count('uasm1MethodVDice') != 1:
    die('the Method V matrix accessor %d'
        % sm.count('uasm1MethodVDice'))
uq = rd(UQ)
if uq.count('return false;') != 12:
    die('the appendq flip count %d'
        % uq.count('return false;'))

print('R394 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean PDF read fills the'
      ' DM-section holes')
print('  uasmalls1.h: the Method V 12 x 7'
      ' matrix; the barding')
print('    column repin (a divergence fix:'
      ' the R370 labels sat')
print('    one column off - light scale 15'
      ' chain NA, medium')
print('    17/15/12, heavy 15/14/13/12)')
print('  uasocialclass.h: the LLC label'
      ' (Freed slaves), the')
print('    halfling parenthetical confirmed')
print('  uabirth.h: the high-elf sign -20,'
      ' the intro clean')
print('  uaappendq.h: every flagged hole'
      ' filled - all six')
print('    parts fully clean')
print('  the DM tables manifest: ten items'
      ' flip CLOSED')
print('    (the Clerical Quick Reference'
      ' rides Appendix S;')
print('    Treasure Table III stays open'
      ' on III.A-III.H)')
print('  regtest census 320 -> 321')
print('commit: R394: the UA DM tables'
      ' manifest sweep (census 321)')

