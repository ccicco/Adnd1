#!/usr/bin/env python3
# R202 splice: the report-sync round. The
# gap-report convention: when a round closes
# an item, the log entry lands in the SAME
# commit. R196's entry landed; R197 through
# R201 are owed - five engine rounds, first-
# try GREEN each, with no log entries. This
# round pays the documentation debt: the
# five entries appended to the round log
# in tools/dmg_gap_report.md, in the
# established style (R193-R196 the
# precedent). A report round adds no audit;
# census stays 118.
#
# Patches: 1 (tools/dmg_gap_report.md).

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: tools/dmg_gap_report.md - the five owed round-log entries
# ---------------------------------------------------------------------------

log = []
log.append('R197 landed the per-spell mental-form flag (the R194')
log.append('seam): spells::spellIsMentalForm flags the registry two')
log.append('will-force forms (charm person - charming; charm')
log.append('monster - mass charming); spellSaveModWis assembles the')
log.append('WIS magical defense adjustment via wisMagicalAttackAdj on')
log.append('those, 0 on everything else. JUDGMENT: the holds are NOT')
log.append('will-force forms - the PHB Serten spell immunity print')
log.append('groups hold with command, domination, fear and scare, apart')
log.append('from beguiling/charm/suggestion. Fear, hypnosis,')
log.append('suggestion, the phantasmal forces ride the flag when their')
log.append('registry rows arrive. New R197 battery audit; census 114.')
log.append('Next: the gap report names the next round.')
log.append('R198 landed the class weapon allowlists - the CHARACTER')
log.append('CLASSES TABLE II weapons column, the monk list home:')
log.append('rules/weapontables.h pins classUsesAnyWeapon (fighter,')
log.append('paladin, ranger, assassin), the limited lists (cleric 7')
log.append('chart rows, druid 9, MU/illusionist 3, thief 8, monk 24)')
log.append('and weaponAllowedForClass. JUDGMENTs: the family words')
log.append('expand to chart variants (flail/mace = footman + horseman,')
log.append('staff = quarterstaff, sling = bullet + stone, hammer =')
log.append('the plain hammer, NOT the lucern); thief sword = short/')
log.append('broad/long per the printed footnote, never bastard or')
log.append('two-handed; monk pole arm = the chart 15 pole-arm rows')
log.append('(pikes and picks out); crossbow pins by name for the monk')
log.append('alone (the chart prints only its quarrels). New R198')
log.append('battery audit; census 115. Next: the two allowance')
log.append('columns right of the weapons column.')
log.append('R199 landed the oil and poison columns of the CHARACTER')
log.append('CLASSES TABLE II - the table is now complete in the')
log.append('engine. The three-valued allowance encoding (1 yes, 0')
log.append('never, -1 referee discretion): classOilUse - yes for')
log.append('every class but the monk (the prose: not even flaming')
log.append('oil is usable by them); classPoisonUse - cleric never,')
log.append('paladin never, assassin yes, the rest the question mark;')
log.append('the evil-cleric footnote as its own modifier,')
log.append('classPoisonUseForAlignment - the prohibition is strictly')
log.append('for clerics NOT of evil alignment; the paladin never is')
log.append('unconditional. New R199 battery audit; census 116. Next:')
log.append('the seam reports name the monk falling rows.')
log.append('R200 landed the monk falling-while-climbing ladder (the')
log.append('print rows under the thief-ability paragraph): 4th')
log.append('(Disciple) fall up to 20 feet within 1 of a wall, 6th')
log.append('(Master) 30 within 4, 13th (Master of Winter) any')
log.append('distance within 8, with the wall-contact rule (damage-')
log.append('free only when periodic contact is possible; tree trunk,')
log.append('cliff face serve). rules/subclassspecials.h:')
log.append('monkWallAssistedFallFeet (0/20/30/-1-any), the proximity')
log.append('column (0/1/4/8), the contact rule. New R200 battery')
log.append('audit; census 117. Next: the NPC monk alignment split.')
log.append('R201 landed the NPC monk alignment split (the monk prose')
log.append('pin: NPC monks align 50% lawful good, 35% lawful')
log.append('neutral, 15% lawful evil): rules/subclassspecials.h -')
log.append('the three percent accessors plus monkNpcAlignRollRange')
log.append('(the cumulative d100 bands: LG 1-50, LN 51-85, LE')
log.append('86-100; out-of-range index the 0-100 miss band). The PC')
log.append('side stays gated by SUB_ALIGN_LAWFUL_ONLY. New R201')
log.append('battery audit; census 118. THE MONK PROSE SEAM IS FULLY')
log.append('MINED - surprise ladder, stun/kill, quivering palm,')
log.append('save advantages, falling ladder, NPC alignment split.')
log.append('Next: the DMG-only tables still unpinned.')

old1 = ('New R196 battery'
        + NL + 'audit; census 113. Next: the gap report names'
        + NL + 'the next round.'
        + NL
        + NL + 'Categories:')

new1 = ('New R196 battery'
        + NL + 'audit; census 113. Next: the gap report names'
        + NL + 'the next round.'
        + NL + NL.join(log)
        + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R197 landed the per-spell mental-form flag',
      old1,
      new1)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R202 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R202 note: 1 patch; the five owed round-log entries land -')
print('R197 through R201 appended to the gap report log;')
print('a report round adds no audit; census stays 118.')
print('commit: R202: the report sync - the R197-R201 round-log')
print('entries appended to the gap report (census stays 118)')

