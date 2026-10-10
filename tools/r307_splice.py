#!/usr/bin/env python3
# tools/r307_splice.py - R307: the fresh
# gap pass (a report round - the R296
# successor). The upload section lists
# diffed against both gap ledgers again;
# the findings recorded, no engine code.
#
# The pass found, DMG-side: the standard
# and expert hirelings cost tables and
# the sage subsection never pinned or
# marked OUT (both opened); the patrols,
# fortresses and castle tables turn out
# pinned since R67 - a bookkeeping
# repair, recorded; the helmet head-AC
# rule, the peasants serfs and slaves
# section, the Appendix C appearance
# family and the glossary and afterword
# recorded OUT. PHB-side: the general
# equipment cost lists opened; the
# vision appendix and the end-of-book
# DM advice sections recorded OUT; the
# hirelings prose, the time and
# initiative reads and the
# reference-sheet repeats recorded as
# covered notes.
#
#   (a) tools/dmg_gap_report.md - the
#       chronicle paragraph.
#   (b) tools/dmg_gap_report.md - the
#       two open boxes (the hirelings
#       cost tables, the sage
#       subsection).
#   (c) tools/dmg_gap_report.md - the
#       OUT bullet (the helmets, the
#       peasants, the Appendix C
#       appearance family, the glossary
#       and afterword).
#   (d) tools/phb_gap_report.md - the
#       R307 scope section and the open
#       box (the general equipment cost
#       lists).
#   (e) tools/phb_gap_report.md - the
#       OUT additions (the vision
#       appendix, the end-of-book advice
#       sections).
#
# Idempotent: safe to run twice; a silent
# run means the paste was truncated - this
# tail ALWAYS prints. An assert follows
# EVERY patch (the R142 lesson). ZERO
# literal backslash bytes in this file
# except the assert continuations, and no
# CONTENT string embeds an apostrophe,
# non-ASCII or (for the gap reports) a
# line past 57 columns. A report round
# adds no audit; the battery census stays
# 231.
# Commit: "R307: the fresh gap pass
# (census 231)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s):
    assert Q not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= 57, 'line too long: ' + ln

# ---- (a) tools/dmg_gap_report.md: the chronicle ----
DMG_A_OLD = NL.join([
    'moves 229 -> 231).',
    '',
    'Categories:',
])
DMG_A_NEW = NL.join([
    'moves 229 -> 231).',
    '',
    'R307 the fresh gap pass (a report',
    'round): the upload section lists',
    'diffed against both ledgers again,',
    'the R296 convention. Two DMG opens',
    '(the boxes in the open-gaps section):',
    'the standard and expert hirelings',
    'cost tables (upload lines 1817 and',
    '1873 - the R121 officers slice and',
    'the R212 spell prices never carried',
    'them) and the sage subsection (the',
    'fields of study, the exact versus',
    'learned question chances; upload line',
    '2110). One bookkeeping repair: the',
    'patrols, fortresses and castle tables',
    '(upload lines 4517-4560) turn out',
    'pinned since R67 (dm/encounters.cpp,',
    'wired R68) - the report never carried',
    'the receipt; recorded here. Four',
    'recorded OUT: the helmet head-AC',
    'rule (upload line 1773), the peasants',
    'serfs and slaves section, the',
    'Appendix C appearance family and the',
    'glossary and afterword back matter.',
    'The phb report carries its own R307',
    'pass; no audit added -',
    'the battery census stays 231.',
    '',
    'Categories:',
])
clean(DMG_A_OLD)
clean(DMG_A_NEW)

# ---- (b) tools/dmg_gap_report.md: the open boxes ----
DMG_B_OLD = NL.join([
    '      cityRuffianKind), audited by the R174 battery',
    '      block. Census 92.',
    '',
    '## Out of scope by design',
])
DMG_B_NEW = NL.join([
    'cityRuffianKind), audited by the',
    '      block. Census 92.',
    '',
    '- [ ] **Standard and expert hirelings',
    '      cost tables (the STANDARD',
    '      HIRELINGS TABLE OF DAILY AND',
    '      MONTHLY COSTS, upload line 1817;',
    '      the EXPERT HIRELINGS TABLE OF',
    '      MONTHLY COSTS IN GOLD PIECES,',
    '      upload line 1873) - OPENED R307:**',
    '      the R121 officers slice',
    '      and the R212 NPC spell prices',
    '      never carried the tables. A',
    '      data candidate: the daily and',
    '      monthly bands pin rules-side',
    '      (the R300 pattern - pure data;',
    '      no site charges them until a',
    '      round wires one). The expert',
    '      types prose and the employment',
    '      prose ride this box, and the PHB',
    '      HIRELINGS prose rides it too',
    '      (the hireling count is never',
    '      charisma-limited; the loyalty',
    '      discussion is the henchmen one).',
    '- [ ] **The sage subsection (upload',
    '      line 2110) - OPENED R307:** the',
    '      fields of study with the special',
    '      knowledge categories, the exact',
    '      versus learned question chances',
    '      and the location prose. A data',
    '      candidate: the fields and chance',
    '      bands pin dm/-side (the',
    '      appendixa.h pattern); no town',
    '      consultation site exists - the',
    '      judgment waits for the pin round.',
    '',
    '## Out of scope by design',
])
clean(DMG_B_OLD)
clean(DMG_B_NEW)

# ---- (c) tools/dmg_gap_report.md: the OUT bullet ----
DMG_C_OLD = NL.join([
    'R172 note and the box below).',
    '',
    '- [x] **Appendix J: herbs, spices and',
])
DMG_C_NEW = NL.join([
    'R172 note and the box below).',
    '',
    '- OUT (R307): the helmet head-AC rule',
    '  (a great helm gives the head AC 1; a',
    '  blow in six strikes the unhelmeted',
    '  head, one in two vs an intelligent',
    '  foe - no hit-location layer; the',
    '  R300 helmet cost rows stay dead',
    '  data), the PEASANTS SERFS AND SLAVES',
    '  section (feudal weapon bans and',
    '  uprisings - domain simulator), the',
    '  Appendix C appearance family (the',
    '  magic-possessed and the',
    '  chance-per-level tables plus the',
    '  appearance dressing - the lair-hoard',
    '  convention already answers what an',
    '  encountered creature carries, and',
    '  the NPC personae appearance is',
    '  R209/R210) and the glossary and',
    '  afterword back matter (prose, no',
    '  tables).',
    '',
    '- [x] **Appendix J: herbs, spices and',
])
clean(DMG_C_OLD)
clean(DMG_C_NEW)

# ---- (d) tools/phb_gap_report.md: the section + open box ----
PHB_D_OLD = NL.join([
    '## Out of engine scope (the R296 additions)',
])
PHB_D_NEW = NL.join([
    '## R307 the fresh gap pass (the fourth',
    'scope round)',
    '',
    'R307 SCOPE PASS. Diffing the PHB upload',
    'section list against this ledger',
    'again, the R296/R299 convention. One',
    'section opened below; two recorded OUT',
    '(the R307 additions at the foot); the',
    'rest are covered notes: the HIRELINGS',
    'prose rides the DMG hirelings box the',
    'sibling ledger opens this round (the',
    'hireling count is never',
    'charisma-limited); the TIME and',
    'end-of-book INITIATIVE reads carry the',
    'DMG-side pins (the turn clock p.38,',
    'the R158 speed factors, the',
    'rules/turn.h round and segment',
    'conventions); the reference-sheet',
    'repeats of the pinned tables read as',
    'copies; the paladin Furthermore list',
    'and the monetary Thus prose are',
    'continuations of covered sections. A',
    'report round adds no audit;',
    'the battery census stays 231.',
    '',
    '## Open items (the R307 addition)',
    '',
    '- [ ] **The general equipment cost',
    '      lists (Clothing, Herbs,',
    '      Livestock, Provisions and',
    '      Transport; upload lines 2344-2430',
    '      with the reference-sheet repeats',
    '      at 13473-13535) - OPENED R307:**',
    '      the R300 cost columns pinned the',
    '      52 arms and the 14 armor rows',
    '      only. The five general lists stay',
    '      unpinned (the clothing and',
    '      footwear prices, the herb costs,',
    '      livestock, the provisions and the',
    '      transport costs - mounts, tack',
    '      and vehicles). A data candidate:',
    '      rules/equipcosts.h grows the rows',
    '      (the R300 pattern; the',
    '      reference-sheet copies resolve any',
    '      ambiguous cell). The judgment',
    '      waits for the pin round.',
    '',
    '## Out of engine scope (the R296 additions)',
])
clean(PHB_D_OLD)
clean(PHB_D_NEW)

# ---- (e) tools/phb_gap_report.md: the OUT additions ----
PHB_E_OLD = NL.join([
    'the pin',
    '  round waits for that source.',
    '',
    'The R178 subclass-arc precedent',
])
PHB_E_NEW = NL.join([
    'the pin',
    '  round waits for that source.',
    '',
    '## Out of engine scope (the R307',
    'additions)',
    '',
    '- INFRAVISION and ULTRAVISION (the',
    '  appendix at upload lines 11842-11848)',
    '  - infravision is pinned as the racial',
    '  datum (R154) and in the lighting',
    '  prose; the engine has no vision-block',
    '  layer (darkness gates the dungeon',
    '  sites by convention).',
    '- The end-of-book DM advice sections',
    '  (COMMUNICATION, NEGOTIATION,',
    '  OBEDIENCE, ORGANIZATION and',
    '  SUCCESSFUL ADVENTURES; upload lines',
    '  11931-12119) - advice prose with no',
    '  mechanical tables; the parley',
    '  machinery lives DMG-side (the R117',
    '  reactions, the R138 talk flavor),',
    '  the end-of-book INITIATIVE is the',
    '  R158 print and the traps prose is',
    '  R125.',
    '',
    'The R178 subclass-arc precedent',
])
clean(PHB_E_OLD)
clean(PHB_E_NEW)

# ---- apply: the DMG patches ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R307 the fresh gap pass (a report' in s:
    already.append('dmg chronicle')
else:
    assert s.count(DMG_A_OLD) == 1, 'dmg a anchor not unique'
    s = s.replace(DMG_A_OLD, DMG_A_NEW)
    applied.append('dmg chronicle')
if '- [ ] **Standard and expert hirelings' in s:
    already.append('dmg open boxes')
else:
    assert s.count(DMG_B_OLD) == 1, 'dmg b anchor not unique'
    s = s.replace(DMG_B_OLD, DMG_B_NEW)
    applied.append('dmg open boxes')
if 'OUT (R307): the helmet head-AC rule' in s:
    already.append('dmg out bullet')
else:
    assert s.count(DMG_C_OLD) == 1, 'dmg c anchor not unique'
    s = s.replace(DMG_C_OLD, DMG_C_NEW)
    applied.append('dmg out bullet')
wr(p, s)

s = rd(p)
assert s.count('R307 the fresh gap pass (a report') == 1, \
    'patch a paragraph'
assert s.count('Categories:') == 1, 'patch a legend head'
assert s.count('moves 229 -> 231') == 1, 'patch a r306 tail'
assert s.count('R306 PINNED the DMG thief commentary') == 1, \
    'patch a r306 paragraph'
assert s.count('- [ ] **Standard and expert hirelings') == 1, \
    'patch b box 1'
assert s.count('- [ ] **The sage subsection') == 1, \
    'patch b box 2'
assert s.count('OPENED R307') == 2, 'patch b opened tags'
assert s.count('OUT (R307): the helmet head-AC rule') == 1, \
    'patch c bullet'
assert s.count('## Out of scope by design') == 1, \
    'patch c section head'
assert s.count('Appendix J: herbs, spices and') == 1, \
    'patch c appendix j box'
assert s.count('- [ ]') == 3, 'dmg open checkbox count'
assert s.count('the battery census stays 231') == 1, \
    'patch a census note'
assert s.count('pinned since R67') == 1, 'patch a repair note'

# ---- apply: the PHB patches ----
p = 'tools/phb_gap_report.md'
s = rd(p)
if '## R307 the fresh gap pass (the fourth' in s:
    already.append('phb scope section')
else:
    assert s.count(PHB_D_OLD) == 1, 'phb d anchor not unique'
    s = s.replace(PHB_D_OLD, PHB_D_NEW)
    applied.append('phb scope section')
if '## Out of engine scope (the R307' in s:
    already.append('phb out additions')
else:
    assert s.count(PHB_E_OLD) == 1, 'phb e anchor not unique'
    s = s.replace(PHB_E_OLD, PHB_E_NEW)
    applied.append('phb out additions')
wr(p, s)

s = rd(p)
assert s.count('## R307 the fresh gap pass (the fourth') == 1, \
    'patch d section head'
assert s.count('## Open items (the R307 addition)') == 1, \
    'patch d open head'
assert s.count('grows the rows') == 1, \
    'patch d box'
assert s.count('OPENED R307') == 1, 'patch d opened tag'
assert s.count('## Out of engine scope (the R307') == 1, \
    'patch e head'
assert s.count('INFRAVISION and ULTRAVISION') == 1, \
    'patch e vision bullet'
assert s.count('end-of-book DM advice sections') == 1, \
    'patch e advice bullet'
assert s.count('## Out of engine scope (the R296') == 1, \
    'patch e r296 head intact'
assert s.count('The R178 subclass-arc precedent') == 1, \
    'patch e tail intact'
assert s.count('- [ ]') == 1, 'phb open checkbox count'
assert s.count('the battery census stays 231') == 1, \
    'patch d census note'

# ---- R307 fails/tail ----
if fails:
    print('R307 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print('R307 splice: FAIL - expected 5 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R307 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R307 note: 5 patches; a report round -')
print('the battery census stays 231; the ledgers')
print('gain three open items')
print('commit: R307: the fresh gap pass (census 231)')

