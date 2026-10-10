#!/usr/bin/env python3
# tools/r306_splice.py - R306: the thief
# functions wired (the R305 successor - the
# last three take-table columns gain their
# engine sites; hear noise keeps the R120
# portal listen convention).
#
# The PHB THIEF print: hiding in shadows is
# the ability to blend into dark areas and
# remain unobserved; climbing assumes the
# surface is coarse and offers ledges and
# cracks; from the 4th level the read
# languages chance enables the reading of
# instructions and treasure maps. The DMG
# commentary print: hiding is never possible
# under direct (or even indirect)
# observation, and the unobserved attempt
# still stands the hazard of the dice. This
# round wires the three sites: [I] spends
# the turn and the first living thief rolls
# the hide percentile (success sets the flag
# and the next wanderer passes unseen); the
# pit trap draws the climb percentile after
# the strike (a clean climb hauls the victim
# out, a miss still hauls but spends the
# turn); the lair victory draws the read
# percentile once per delve (success pays
# the coins cache).
#
#   (a) rules/thieffunc.h - the wiring-arc
#       head amended and the seven site
#       pins (the hide note, the wander
#       pass, the climb note, the haul turn,
#       the script fold, the cache band).
#   (b) dm/appendixgh.h - the pit family
#       (the five printed pit kinds) and
#       the trapIsPit seam.
#   (c) game/appstate.h - the hiddenThief
#       and scriptTried flags and the two
#       declarations.
#   (d) game/state_dungeon.cpp - the sites:
#       hideExplore, readScript, the pit
#       fold in springTrap and the
#       awardVictory call.
#   (e) game/state_core.cpp - the delve
#       resets.
#   (f) game/state_combat.cpp - the hidden
#       gate at the wander spawn.
#   (g) adnd1.cpp - the [I] key and the
#       hint (the case labels carry the one
#       apostrophe family of the content,
#       built via chr(39), the R303
#       precedent).
#   (h) regtest.cpp - the R306 audit pair
#       (the battery census 229 -> 231):
#       the R306a seam audit walks the
#       take-table boundaries and the pins
#       (evaluable - verified by
#       audit_eval) and the R306 engine
#       audit pins every scenario on
#       seeded sequences (the replica
#       walked the draws first - no
#       compiler in the splice sandbox).
#   (i) tools/phb_gap_report.md - the R298
#       wiring-arc box head amended and the
#       round box (the ledger holds ZERO
#       open items).
#   (j) tools/dmg_gap_report.md - the
#       chronicle paragraph (the DMG pins
#       recorded).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS) and no CONTENT string embeds
# an apostrophe outside the adnd1.cpp case
# labels, non-ASCII or (for the gap reports) a
# line past 57 columns.
# Commit: "R306: the thief functions wired
# (census 231)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
Q = chr(39)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, allow_apos=False):
    if not allow_apos:
        assert Q not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/thieffunc.h: the head + the pins ----
TF_HEAD_OLD = NL.join([
    '// street site; the others wait for engine',
    '// sites that do not exist yet.',
])
TF_HEAD_NEW = NL.join([
    '// street site; R306: the hide, climb and read',
    '// rolls run at the shadow, pit and script',
    '// sites (hear noise keeps the R120 portal',
    '// listen convention).',
])
TF_PINS = NL.join([
    '',
    '// R306: the hide site note - the DMG',
    '// commentary print: hiding in shadows is',
    '// never possible under direct (or even',
    '// indirect) observation, and the unobserved',
    '// attempt still stands the hazard of the',
    '// dice. The engine site runs unobserved (no',
    '// foe on screen - the fold rides the flag).',
    'inline int thfNoteHideObserved() {',
    '    return 1;',
    '}',
    '',
    '// R306: the hidden pass - the PHB blend',
    '// print: the company remains unobserved, so',
    '// one wandering encounter passes unseen; the',
    '// hide roll bought the pass and the flag',
    '// folds at the spawn site',
    'inline int thfHideWanderPasses() {',
    '    return 1;',
    '}',
    '',
    '// R306: the climb site note - the PHB',
    '// print: climbing assumes the surface is',
    '// coarse and offers ledges and cracks for',
    '// toe and hand holds (no DEX column)',
    'inline int thfNoteClimbCoarseSurface() {',
    '    return 1;',
    '}',
    '',
    '// R306: the failed pit haul costs a full',
    '// turn - the climb missed, the ropes come',
    '// out, and the work draws the wander check',
    'inline int thfPitHaulFailTurns() {',
    '    return 1;',
    '}',
    '',
    '// R306: the script note - the PHB print:',
    '// from the 4th level the read languages',
    '// chance enables the reading of instructions',
    '// and treasure maps. JUDGMENT: the monster',
    '// lair holds one script per delve (one try,',
    '// spent whatever the roll reads)',
    'inline int thfReadScriptOncePerDelve() {',
    '    return 1;',
    '}',
    '',
    '// R306: the script cache band - the coins',
    '// cache behind the map rolls 2d6 (the',
    '// TA_REL_COINS shape, scaled by the level)',
    'inline int thfReadScriptCacheMin() {',
    '    return 2;',
    '}',
    '',
    'inline int thfReadScriptCacheMax() {',
    '    return 12;',
    '}',
])
TF_CLOSE_OLD = NL.join([
    '}  // namespace rules',
])
TF_CLOSE_NEW = TF_PINS + NL + NL.join([
    '',
    '}  // namespace rules',
])
for t in (TF_HEAD_OLD, TF_HEAD_NEW, TF_PINS,
          TF_CLOSE_OLD, TF_CLOSE_NEW):
    clean(t, 78)

p = 'rules/thieffunc.h'
s = rd(p)
if 'thfNoteHideObserved' in s:
    already.append('thieffunc.h: the head + the pins')
else:
    assert s.count(TF_HEAD_OLD) == 1, 'tf head anchor not unique'
    assert s.count(TF_CLOSE_OLD) == 1, 'tf close anchor not unique'
    s = s.replace(TF_HEAD_OLD, TF_HEAD_NEW)
    s = s.replace(TF_CLOSE_OLD, TF_CLOSE_NEW)
    wr(p, s)
    applied.append('thieffunc.h: the head + the pins')
s = rd(p)
assert s.count('thfNoteHideObserved') == 1, 'patch a hide note'
assert s.count('thfHideWanderPasses') == 1, 'patch a wander pass'
assert s.count('thfNoteClimbCoarseSurface') == 1, 'patch a climb note'
assert s.count('thfPitHaulFailTurns') == 1, 'patch a haul turn'
assert s.count('thfReadScriptOncePerDelve') == 1, 'patch a script fold'
assert s.count('thfReadScriptCacheMin') == 1, 'patch a cache min'
assert s.count('thfReadScriptCacheMax') == 1, 'patch a cache max'
assert s.count('return 12;') == 1, 'patch a the 2d6 ceiling'
assert s.count('R306: the hide, climb and read') == 1, \
    'patch a head'
assert s.count('the others wait for engine sites') == 0, \
    'patch a stale arc note'
assert s.count('}  // namespace rules') == 1, 'patch a close intact'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) dm/appendixgh.h: the pit family ----
AG_OLD = NL.join([
    '    if (kind < 0 || kind >= TRAP_KIND_COUNT)'
    ' return "unknown";',
    '    return NAMES[kind];',
    '}',
    '',
    '}  // namespace appendixg',
])
AG_NEW = NL.join([
    '    if (kind < 0 || kind >= TRAP_KIND_COUNT)'
    ' return "unknown";',
    '    return NAMES[kind];',
    '}',
    '',
    '// R306: the pit family - the five printed',
    '// Appendix G pit kinds (the trap page), for',
    '// the climb-walls haul at the trap site',
    'inline int trapPitKindMin() {',
    '    return 28;',
    '}',
    '',
    'inline int trapPitKindMax() {',
    '    return 32;',
    '}',
    '',
    'inline bool trapIsPit(int kind) {',
    '    return kind >= trapPitKindMin() &&',
    '           kind <= trapPitKindMax();',
    '}',
    '',
    '}  // namespace appendixg',
])
for t in (AG_OLD, AG_NEW):
    clean(t, 78)

p = 'dm/appendixgh.h'
s = rd(p)
if 'trapIsPit' in s:
    already.append('appendixgh.h: the pit family')
else:
    assert s.count(AG_OLD) == 1, 'ag anchor not unique'
    s = s.replace(AG_OLD, AG_NEW)
    wr(p, s)
    applied.append('appendixgh.h: the pit family')
s = rd(p)
assert s.count('trapIsPit') == 1, 'patch b the pit seam'
assert s.count('trapPitKindMin') == 2, 'patch b the pit floor'
assert s.count('trapPitKindMax') == 2, 'patch b the pit ceiling'
assert s.count('return 28;') == 1, 'patch b the 28'
assert s.count('return 32;') == 1, 'patch b the 32'
assert s.count('}  // namespace appendixg') == 1, \
    'patch b namespace close'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/appstate.h: the flags + the decls ----
AH_MEM_OLD = NL.join([
    '    // R304: the locked doors of this delve',
    '    std::vector<LockedDoor> lockedDoors;',
])
AH_MEM_NEW = NL.join([
    '    // R304: the locked doors of this delve',
    '    std::vector<LockedDoor> lockedDoors;',
    '',
    '    // R306: the hidden thief - one absorbed',
    '    // wanderer per successful hide',
    '    bool hiddenThief = false;',
    '    // R306: the lair script - one read per delve',
    '    bool scriptTried = false;',
])
AH_DECL_OLD = NL.join([
    '    void forceLockedDoor();',
])
AH_DECL_NEW = NL.join([
    '    void forceLockedDoor();',
    '',
    '    // R306: [I] hide - the first living thief',
    '    // blends into the shadows (the R298',
    '    // percentile); success lets one wanderer',
    '    // pass the company unseen',
    '    void hideExplore();',
    '',
    '    // R306: the lair script - the first living',
    '    // thief reads the monster hoard map (the',
    '    // printed percentile; one try per delve)',
    '    void readScript();',
])
for t in (AH_MEM_OLD, AH_MEM_NEW, AH_DECL_OLD, AH_DECL_NEW):
    clean(t, 78)

p = 'game/appstate.h'
s = rd(p)
if 'hideExplore' in s:
    already.append('appstate.h: the flags + the decls')
else:
    assert s.count(AH_MEM_OLD) == 1, 'ah member anchor not unique'
    assert s.count(AH_DECL_OLD) == 1, 'ah decl anchor not unique'
    assert 'hiddenThief' not in s, 'ah flag collision'
    assert 'scriptTried' not in s, 'ah flag collision'
    s = s.replace(AH_MEM_OLD, AH_MEM_NEW)
    s = s.replace(AH_DECL_OLD, AH_DECL_NEW)
    wr(p, s)
    applied.append('appstate.h: the flags + the decls')
s = rd(p)
assert s.count('bool hiddenThief = false;') == 1, 'patch c hide flag'
assert s.count('bool scriptTried = false;') == 1, \
    'patch c script flag'
assert s.count('void hideExplore();') == 1, 'patch c hide decl'
assert s.count('void readScript();') == 1, 'patch c script decl'
assert s.count('void forceLockedDoor();') == 1, 'patch c force decl'
assert s.count('void bumpLockedDoor(int x, int y);') == 1, \
    'patch c bump decl'
assert s.count('std::vector<LockedDoor> lockedDoors;') == 1, \
    'patch c doors member'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_dungeon.cpp: the sites ----
SD_SITE_OLD = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- searchExplore ----',
])
SD_SITE_NEW = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- hideExplore ----',
    '// R306: [I] - the first living thief blends',
    '// into the shadows (the R298 percentile).',
    '// The DMG commentary print: hiding is never',
    '// possible under observation, and the',
    '// unobserved attempt still stands the dice -',
    '// the engine site runs unobserved. The',
    '// success folds at the wander site: one',
    '// wanderer passes the company unseen. The',
    '// turn spends (the bump convention).',
    'void AppState::hideExplore(){',
    '        if (mode != MODE_EXPLORE) return;',
    '        if (!party.alive()) return;',
    '',
    '        ++turnCount;',
    '        tickActivity(1);   // R119: the wait is work too',
    '',
    '        const Character* thief = nullptr;',
    '        for (const auto& t : party.members) {',
    '            if (t.hp <= 0 || t.classIndex != 3) continue;',
    '            thief = &t;',
    '            break;',
    '        }',
    '        if (thief == nullptr) {',
    '            log.add("No thief walks with you - the "',
    '                    "shadows stay empty.");',
    '        } else {',
    '            int roll = (int)rng.below(1000);',
    '            char buf[96];',
    '            if (rules::thfAttemptSucceeds(roll,',
    '                    rules::THF_HIDE_SHADOWS,',
    '                    thief->level, thief->race,',
    '                    (int)thief->abilities.dex)) {',
    '                hiddenThief = true;',
    '                snprintf(buf, sizeof buf,',
    '                         "%s melts into the shadows.",',
    '                         thief->name.c_str());',
    '            } else {',
    '                snprintf(buf, sizeof buf,',
    '                         "%s presses into the shadows - "',
    '                         "they betray the attempt.",',
    '                         thief->name.c_str());',
    '            }',
    '            log.add(buf);',
    '        }',
    '',
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- readScript ----',
    '// R306: the lair script - the monster hoard',
    '// holds a treasure map (the PHB print: the',
    '// read languages chance enables the reading',
    '// of instructions and treasure maps). The',
    '// first living thief reads it once per',
    '// delve (the JUDGMENT); success pays the',
    '// coins cache (the 2d6 shape scaled by the',
    '// level).',
    'void AppState::readScript(){',
    '        if (scriptTried) return;',
    '        scriptTried = true;',
    '',
    '        const Character* thief = nullptr;',
    '        for (const auto& t : party.members) {',
    '            if (t.hp <= 0 || t.classIndex != 3) continue;',
    '            thief = &t;',
    '            break;',
    '        }',
    '        if (thief == nullptr) {',
    '            log.add("The script waits for a thief.");',
    '            return;',
    '        }',
    '        int roll = (int)rng.below(1000);',
    '        char buf[96];',
    '        if (rules::thfAttemptSucceeds(roll,',
    '                rules::THF_READ_LANGUAGES,',
    '                thief->level, thief->race,',
    '                (int)thief->abilities.dex)) {',
    '            int gp = (int)dice.roll(2, 6, 0) * 10 *',
    '                     dungeonLevel;',
    '            party.gold += gp;',
    '            party.delveGold += gp;',
    '            snprintf(buf, sizeof buf,',
    '                     "%s reads the script - a cache "',
    '                     "holds %d gp.",',
    '                     thief->name.c_str(), gp);',
    '        } else {',
    '            snprintf(buf, sizeof buf,',
    '                     "%s squints at the script - it "',
    '                     "stays cryptic.",',
    '                     thief->name.c_str());',
    '        }',
    '        log.add(buf);',
    '    }',
    '',
    '// ---- searchExplore ----',
])
SD_PIT_OLD = NL.join([
    '                     "A trap! %s strikes %s for %d.",',
    '                     dm::appendixg::trapName('
    'room.trapKind),',
    '                     c.name.c_str(), dmg);',
    '        }',
    '        log.add(buf);',
    '        if (!party.alive()) {',
])
SD_PIT_NEW = NL.join([
    '                     "A trap! %s strikes %s for %d.",',
    '                     dm::appendixg::trapName('
    'room.trapKind),',
    '                     c.name.c_str(), dmg);',
    '        }',
    '        log.add(buf);',
    '',
    '        // R306: the pit haul - the first living',
    '        // thief climbs down the wall (the PHB',
    '        // print: climbing assumes a coarse',
    '        // surface with ledges and cracks). A',
    '        // clean climb costs nothing; a missed',
    '        // climb still hauls the victim out but',
    '        // spends the turn (the work draws the',
    '        // wander check, the bump convention)',
    '        if (dm::appendixg::trapIsPit('
    'room.trapKind)) {',
    '            const Character* climber = nullptr;',
    '            for (const auto& t : party.members) {',
    '                if (t.hp <= 0 || t.classIndex != 3)',
    '                    continue;',
    '                climber = &t;',
    '                break;',
    '            }',
    '            if (climber != nullptr) {',
    '                int climb = (int)rng.below(1000);',
    '                char pbuf[128];',
    '                if (rules::thfAttemptSucceeds(climb,',
    '                        rules::THF_CLIMB_WALLS,',
    '                        climber->level, climber->race,',
    '                        (int)climber->abilities.dex)) {',
    '                    snprintf(pbuf, sizeof pbuf,',
    '                             "%s climbs down the pit "',
    '                             "wall and hauls %s out.",',
    '                             climber->name.c_str(),',
    '                             c.name.c_str());',
    '                    log.add(pbuf);',
    '                } else {',
    '                    ++turnCount;',
    '                    tickActivity(1);   // R119: the haul',
    '                    snprintf(pbuf, sizeof pbuf,',
    '                             "%s ropes %s out - the "',
    '                             "haul costs a turn.",',
    '                             climber->name.c_str(),',
    '                             c.name.c_str());',
    '                    log.add(pbuf);',
    '                    // the spent turn draws a wanderer',
    '                    if (dm::wanderCheck(dice, wander))',
    '                        spawnWanderingEncounter();',
    '                }',
    '            }',
    '        }',
    '        if (!party.alive()) {',
])
SD_AWARD_OLD = NL.join([
    '        const bool mmLair = def && '
    '!def->treasure.lair.empty() &&',
    '                           combatRoomIndex >= 0;',
    '        dm::treasure::Hoard hoard;',
])
SD_AWARD_NEW = NL.join([
    '        const bool mmLair = def && '
    '!def->treasure.lair.empty() &&',
    '                           combatRoomIndex >= 0;',
    '        // R306: the lair script - the hoard map',
    '        if (mmLair) readScript();',
    '        dm::treasure::Hoard hoard;',
])
for t in (SD_SITE_OLD, SD_SITE_NEW, SD_PIT_OLD, SD_PIT_NEW,
          SD_AWARD_OLD, SD_AWARD_NEW):
    clean(t, 78)

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'void AppState::hideExplore' in s:
    already.append('state_dungeon.cpp: the sites')
else:
    assert s.count(SD_SITE_OLD) == 1, 'sd site anchor not unique'
    assert s.count(SD_PIT_OLD) == 1, 'sd pit anchor not unique'
    assert s.count(SD_AWARD_OLD) == 1, 'sd award anchor not unique'
    assert 'hiddenThief' not in s, 'sd flag collision'
    assert 'scriptTried' not in s, 'sd flag collision'
    s = s.replace(SD_SITE_OLD, SD_SITE_NEW)
    s = s.replace(SD_PIT_OLD, SD_PIT_NEW)
    s = s.replace(SD_AWARD_OLD, SD_AWARD_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the sites')
s = rd(p)
assert s.count('void AppState::hideExplore') == 1, 'patch d hide site'
assert s.count('void AppState::readScript') == 1, \
    'patch d script site'
assert s.count('trapIsPit') == 1, 'patch d the pit seam call'
assert s.count('if (mmLair) readScript();') == 1, \
    'patch d the award call'
assert s.count('melts into the shadows') == 1, 'patch d melt line'
assert s.count('betray the attempt') == 1, 'patch d betray line'
assert s.count('climbs down the pit') == 1, 'patch d haul line'
assert s.count('ropes %s out') == 1, 'patch d rope line'
assert s.count('waits for a thief') == 1, 'patch d wait line'
assert s.count('hiddenThief') == 1, 'patch d the hide flag'
assert s.count('scriptTried') == 2, 'patch d the script flag'
assert s.count('THF_HIDE_SHADOWS') == 1, 'patch d hide column'
assert s.count('THF_CLIMB_WALLS') == 1, 'patch d climb column'
assert s.count('THF_READ_LANGUAGES') == 1, 'patch d read column'
assert s.count('spawnWanderingEncounter();') == 6, \
    'patch d wander calls'
assert s.count('// ---- searchExplore ----') == 1, \
    'patch d search head'
assert s.count('void AppState::forceLockedDoor') == 1, \
    'patch d force intact'
assert s.count('const bool mmLair = def') == 1, 'patch d lair bool'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) game/state_core.cpp: the delve resets ----
SC_OLD = NL.join([
    '        placeLockedDoors();   '
    '// R304: the locked door feature',
])
SC_NEW = NL.join([
    '        placeLockedDoors();   '
    '// R304: the locked door feature',
    '        hiddenThief = false;   // R306: the hide flag',
    '        scriptTried = false;   // R306: the script flag',
])
for t in (SC_OLD, SC_NEW):
    clean(t, 78)

p = 'game/state_core.cpp'
s = rd(p)
if 'hiddenThief = false;' in s:
    already.append('state_core.cpp: the delve resets')
else:
    assert s.count(SC_OLD) == 1, 'sc anchor not unique'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_core.cpp: the delve resets')
s = rd(p)
assert s.count('hiddenThief = false;') == 1, 'patch e hide reset'
assert s.count('scriptTried = false;') == 1, 'patch e script reset'
assert s.count('placeLockedDoors();') == 1, 'patch e doors intact'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) game/state_combat.cpp: the hidden gate ----
CB_OLD = NL.join([
    'void AppState::spawnWanderingEncounter(){'
    '        if (mode == MODE_COMBAT) return;',
    '        if (!party.alive()) return;',
])
CB_NEW = NL.join([
    'void AppState::spawnWanderingEncounter(){'
    '        if (mode == MODE_COMBAT) return;',
    '        if (!party.alive()) return;',
    '',
    '        // R306: the hidden thief - the hide roll',
    '        // bought one silent pass (the PHB blend',
    '        // prose); the flag is spent here',
    '        if (hiddenThief) {',
    '            hiddenThief = false;',
    '            log.add("The hidden company holds its "',
    '                    "breath - the wanderer passes.");',
    '            return;',
    '        }',
])
# the spawn head line is existing repo text (81
# cols) - the R300 convention cleans it at 90
for t in (CB_OLD, CB_NEW):
    clean(t, 90)
assert all(len(ln) <= 78 for ln in CB_NEW.split(NL)[1:]), \
    'cb new line too long'

p = 'game/state_combat.cpp'
s = rd(p)
if 'the wanderer passes' in s:
    already.append('state_combat.cpp: the hidden gate')
else:
    assert s.count(CB_OLD) == 1, 'cb anchor not unique'
    assert 'hiddenThief' not in s, 'cb flag collision'
    s = s.replace(CB_OLD, CB_NEW)
    wr(p, s)
    applied.append('state_combat.cpp: the hidden gate')
s = rd(p)
assert s.count('hiddenThief') == 2, 'patch f the gate flag'
assert s.count('the wanderer passes') == 1, 'patch f the pass line'
assert s.count('spawnWanderingEncounter') == 3, \
    'patch f spawn mentions'
assert s.count('if (mode == MODE_COMBAT) return;') == 1, \
    'patch f the mode gate'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) adnd1.cpp: the [I] key + the hint ----
AD_CASE_OLD = NL.join([
    '                    // R305: force the adjacent locked door',
    '                    case ' + Q + 'O' + Q + ':',
    '                    case ' + Q + 'o' + Q + ':',
    '                        g_app.forceLockedDoor();',
    '                        break;',
])
AD_CASE_NEW = NL.join([
    '                    // R305: force the adjacent locked door',
    '                    case ' + Q + 'O' + Q + ':',
    '                    case ' + Q + 'o' + Q + ':',
    '                        g_app.forceLockedDoor();',
    '                        break;',
    '',
    '                    // R306: the thief hides in shadows',
    '                    case ' + Q + 'I' + Q + ':',
    '                    case ' + Q + 'i' + Q + ':',
    '                        g_app.hideExplore();',
    '                        break;',
])
AD_HINT_OLD = NL.join([
    '             "[O] force  [K] save  [L] load  '
    '[R] rest  "',
    '             "[B] town",',
])
AD_HINT_NEW = NL.join([
    '             "[I] hide  [O] force  [K] save  '
    '[L] load  "',
    '             "[R] rest  [B] town",',
])
clean(AD_CASE_OLD, 78, allow_apos=True)
clean(AD_CASE_NEW, 78, allow_apos=True)
for t in (AD_HINT_OLD, AD_HINT_NEW):
    clean(t, 78)

p = 'adnd1.cpp'
s = rd(p)
if 'g_app.hideExplore();' in s:
    already.append('adnd1.cpp: the [I] key + the hint')
else:
    assert s.count(AD_CASE_OLD) == 1, 'ad case anchor not unique'
    assert s.count(AD_HINT_OLD) == 1, 'ad hint anchor not unique'
    assert 'hideExplore' not in s, 'ad marker collision'
    s = s.replace(AD_CASE_OLD, AD_CASE_NEW)
    s = s.replace(AD_HINT_OLD, AD_HINT_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the [I] key + the hint')
s = rd(p)
assert s.count('g_app.hideExplore();') == 1, 'patch g the call'
assert (NL.join(['                    case ' + Q + 'I' + Q + ':',
                 '                    case ' + Q + 'i' + Q + ':'])
        in s), 'patch g the case pair'
assert s.count('g_app.forceLockedDoor();') == 1, \
    'patch g force intact'
assert s.count('g_app.quaffExplore();') == 1, 'patch g quaff intact'
assert (s.count('"[I] hide  [O] force  [K] save  '
               '[L] load  "') == 1), 'patch g hint head'
assert s.count('             "[R] rest  [B] town",') == 1, \
    'patch g hint tail'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) regtest.cpp: the audit pair ----
RT_AUD_OLD = NL.join([
    '        printf("R305 door force engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_NEW = NL.join([
    '        printf("R305 door force engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R306a: the thief functions seam audit ----',
    '    // The PHB take-table boundaries (hide in',
    '    // shadows, climb walls, read languages) and',
    '    // the R306 site pins - verified by',
    '    // audit_eval.',
    '    {',
    '        int bad = 0;',
    '        // hide in shadows: the level 1 base',
    '        // reads 10 percent, the 15th 99',
    '        if (rules::thfTakeTenths('
    'rules::THF_HIDE_SHADOWS,',
    '                1) != 100 ||',
    '            rules::thfTakeTenths('
    'rules::THF_HIDE_SHADOWS,',
    '                15) != 990) ++bad;',
    '        // climb walls: the level 1 base reads',
    '        // 85 percent, the 11th 99.1',
    '        if (rules::thfTakeTenths('
    'rules::THF_CLIMB_WALLS,',
    '                1) != 850 ||',
    '            rules::thfTakeTenths('
    'rules::THF_CLIMB_WALLS,',
    '                11) != 991) ++bad;',
    '        // read languages: the dash through the',
    '        // 3rd, 20 percent at the 4th, 80 at 16',
    '        if (rules::thfTakeTenths(',
    '                rules::THF_READ_LANGUAGES, 3) != 0 ||',
    '            rules::thfTakeTenths(',
    '                rules::THF_READ_LANGUAGES,',
    '                4) != 200 ||',
    '            rules::thfTakeTenths(',
    '                rules::THF_READ_LANGUAGES,',
    '                16) != 800) ++bad;',
    '        // climb and read print no DEX column',
    '        if (rules::thfDexAdj(18, '
    'rules::THF_CLIMB_WALLS)',
    '                != 0 ||',
    '            rules::thfDexAdj(18,',
    '                rules::THF_READ_LANGUAGES) != 0) ++bad;',
    '        // the hide ramp: 5 percent per level at',
    '        // the printed band',
    '        if (rules::thfTakeTenths('
    'rules::THF_HIDE_SHADOWS,',
    '                2) - rules::thfTakeTenths(',
    '                rules::THF_HIDE_SHADOWS, 1) != 50)',
    '            ++bad;',
    '        // the read ramp: 5 percent per level',
    '        // past the 4th',
    '        if (rules::thfTakeTenths(',
    '                rules::THF_READ_LANGUAGES, 5) -',
    '            rules::thfTakeTenths(',
    '                rules::THF_READ_LANGUAGES,',
    '                4) != 50) ++bad;',
    '        // the R306 site pins: the observed-hide',
    '        // note, the wander pass, the coarse',
    '        // climb surface and the haul turn',
    '        if (rules::thfNoteHideObserved() != 1 ||',
    '            rules::thfHideWanderPasses() != 1 ||',
    '            rules::thfNoteClimbCoarseSurface() != 1 ||',
    '            rules::thfPitHaulFailTurns() != 1) ++bad;',
    '        // the script pin: one read per delve',
    '        if (rules::thfReadScriptOncePerDelve() != 1)',
    '            ++bad;',
    '        // the cache band rides the 2d6 shape',
    '        if (rules::thfReadScriptCacheMin() != 2 ||',
    '            rules::thfReadScriptCacheMax() != 12 ||',
    '            rules::thfReadScriptCacheMax() -',
    '                rules::thfReadScriptCacheMin() != 10)',
    '            ++bad;',
    '        printf("R306a thief functions seam audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R306: the thief functions engine audit ----',
    '    // The three wired sites: [I] hides the',
    '    // first living thief (the unobserved',
    '    // attempt stands the dice - the DMG',
    '    // commentary print) and the flag folds at',
    '    // the wander spawn; the pit trap draws',
    '    // the climb walls haul (the coarse',
    '    // surface); the monster lair draws the',
    '    // read languages script (one try per',
    '    // delve). Every scenario sits on a seeded',
    '    // sequence the replica walked first (no',
    '    // compiler in the splice sandbox). The',
    '    // seeds discriminate: scenario 3 reads',
    '    // the draw 165 against the zero dex-9',
    '    // chance while scenario 2 reads the same',
    '    // draw under the 17th-level 990; scenario',
    '    // 4 rides the wander d12 read 1 and the',
    '    // hidden gate must absorb it; scenario 6',
    '    // reads the climb 977 over the 850 - the',
    '    // haul spends its turn; scenario 9 reads',
    '    // the script draw 165 under the 200 with',
    '    // the cache 240 gp at level 3 and the',
    '    // second call must draw nothing.',
    '    {',
    '        int bad = 0;',
    '        // scenario 1: no thief - the turn',
    '        // spends and the shadows stay empty',
    '        // (seed 1: the wander d12 reads 2)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character bru;',
    '            bru.name = "Bru";',
    '            bru.classIndex = 0; bru.level = 1;',
    '            bru.race = 0; bru.abilities.str = 10;',
    '            bru.hp = 30; bru.maxHp = 30;',
    '            st.party.members.push_back(bru);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.hideExplore();',
    '            if (st.turnCount != 1) ++bad;',
    '            if (st.hiddenThief) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "the shadows stay empty")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 2: the hide succeeds - the',
    '        // 17th-level chance reads 990 and the',
    '        // draw 165 hides (seed 1: the wander',
    '        // d12 reads 6, quiet)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character filch;',
    '            filch.name = "Filch";',
    '            filch.classIndex = 3; filch.level = 17;',
    '            filch.race = 0; filch.abilities.dex = 13;',
    '            filch.hp = 30; filch.maxHp = 30;',
    '            st.party.members.push_back(filch);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.hideExplore();',
    '            if (st.turnCount != 1 || !st.hiddenThief)',
    '                ++bad;',
    '            if (st.log.get(0).find(',
    '                    "Filch melts into the shadows")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 3: the same draw 165 against',
    '        // the dex-9 level-1 zero chance - the',
    '        // attempt betrays (seed 1)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character green;',
    '            green.name = "Green";',
    '            green.classIndex = 3; green.level = 1;',
    '            green.race = 0; green.abilities.dex = 9;',
    '            green.hp = 30; green.maxHp = 30;',
    '            st.party.members.push_back(green);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.hideExplore();',
    '            if (st.turnCount != 1 || st.hiddenThief)',
    '                ++bad;',
    '            if (st.log.get(0).find(',
    '                    "betray the attempt")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 4: the hide reads 984 (under',
    '        // the 990) and the same-turn wander',
    '        // reads 1 - the hidden gate absorbs it',
    '        // and the flag is spent (seed 10)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character filch;',
    '            filch.name = "Filch";',
    '            filch.classIndex = 3; filch.level = 17;',
    '            filch.race = 0; filch.abilities.dex = 13;',
    '            filch.hp = 30; filch.maxHp = 30;',
    '            st.party.members.push_back(filch);',
    '            st.party.formed = true;',
    '            st.rng.seed(10);',
    '            st.hideExplore();',
    '            if (st.turnCount != 1 || st.hiddenThief)',
    '                ++bad;',
    '            if (st.log.get(0).find(',
    '                    "the wanderer passes")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(1).find(',
    '                    "melts into the shadows")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 5: the pit haul - the find',
    '        // draw 165 misses, the victim pick',
    '        // lands on the fighter, the save 4',
    '        // fails, the strike reads 7 and the',
    '        // climb 721 hauls the fighter out (no',
    '        // turn; seed 1, trap kind 28)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 28;',
    '            Character pounce;',
    '            pounce.name = "Pounce";',
    '            pounce.classIndex = 3; pounce.level = 1;',
    '            pounce.race = 0;',
    '            pounce.abilities.dex = 9;',
    '            pounce.hp = 30; pounce.maxHp = 30;',
    '            st.party.members.push_back(pounce);',
    '            Character fite;',
    '            fite.name = "Fighter";',
    '            fite.classIndex = 0; fite.level = 1;',
    '            fite.hp = 30; fite.maxHp = 30;',
    '            st.party.members.push_back(fite);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.turnCount != 0) ++bad;',
    '            if (st.party.members[0].hp != 30) ++bad;',
    '            if (st.party.members[1].hp != 23) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "climbs down the pit")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(1).find(',
    '                    "strikes Fighter for 7")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 6: the missed climb reads',
    '        // 977 (over the 850) - the ropes still',
    '        // haul the fighter out but the turn',
    '        // spends (seed 9: the wander d12',
    '        // reads 6, quiet)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 28;',
    '            Character pounce;',
    '            pounce.name = "Pounce";',
    '            pounce.classIndex = 3; pounce.level = 1;',
    '            pounce.race = 0;',
    '            pounce.abilities.dex = 9;',
    '            pounce.hp = 30; pounce.maxHp = 30;',
    '            st.party.members.push_back(pounce);',
    '            Character fite;',
    '            fite.name = "Fighter";',
    '            fite.classIndex = 0; fite.level = 1;',
    '            fite.hp = 30; fite.maxHp = 30;',
    '            st.party.members.push_back(fite);',
    '            st.party.formed = true;',
    '            st.rng.seed(9);',
    '            st.springTrap(0);',
    '            if (st.turnCount != 1) ++bad;',
    '            if (st.party.members[1].hp != 22) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "ropes Fighter out")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(1).find(',
    '                    "strikes Fighter for 8")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 7: the non-pit regression -',
    '        // the same seed-1 draws but the arrow',
    '        // kind draws no climb and spends no',
    '        // turn',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character pounce;',
    '            pounce.name = "Pounce";',
    '            pounce.classIndex = 3; pounce.level = 1;',
    '            pounce.race = 0;',
    '            pounce.abilities.dex = 9;',
    '            pounce.hp = 30; pounce.maxHp = 30;',
    '            st.party.members.push_back(pounce);',
    '            Character fite;',
    '            fite.name = "Fighter";',
    '            fite.classIndex = 0; fite.level = 1;',
    '            fite.hp = 30; fite.maxHp = 30;',
    '            st.party.members.push_back(fite);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.turnCount != 0) ++bad;',
    '            if (st.party.members[1].hp != 23) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "strikes Fighter for 7")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("hauls")',
    '                != std::string::npos) ++bad;',
    '            if (st.log.get(0).find("ropes")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // scenario 8: the pit with NO thief -',
    '        // the save 6 fails and the strike reads',
    '        // 8, but no thief draws a climb and no',
    '        // turn spends (seed 1)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 28;',
    '            Character fite;',
    '            fite.name = "Fighter";',
    '            fite.classIndex = 0; fite.level = 1;',
    '            fite.hp = 30; fite.maxHp = 30;',
    '            st.party.members.push_back(fite);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.turnCount != 0) ++bad;',
    '            if (st.party.members[0].hp != 22) ++bad;',
    '            if (st.log.get(0).find("hauls")',
    '                != std::string::npos) ++bad;',
    '            if (st.log.get(0).find("ropes")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // scenario 9: the script reads - the',
    '        // draw 165 lands under the 4th-level',
    '        // 200 and the cache reads 240 gp at',
    '        // level 3; the second call draws',
    '        // nothing (seed 1)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.dungeonLevel = 3;',
    '            Character filch;',
    '            filch.name = "Filch";',
    '            filch.classIndex = 3; filch.level = 4;',
    '            filch.race = 0; filch.abilities.dex = 13;',
    '            filch.hp = 30; filch.maxHp = 30;',
    '            st.party.members.push_back(filch);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.readScript();',
    '            if (!st.scriptTried) ++bad;',
    '            if (st.party.gold != 240) ++bad;',
    '            if (st.party.delveGold != 240) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "a cache holds 240 gp")',
    '                == std::string::npos) ++bad;',
    '            std::string snap = st.log.get(0);',
    '            st.readScript();',
    '            if (st.party.gold != 240) ++bad;',
    '            if (st.log.get(0) != snap) ++bad;',
    '        }',
    '        // scenario 10: the failed read - the',
    '        // draw 330 sits over the 200 and the',
    '        // script stays cryptic; the try is',
    '        // spent either way (seed 2)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.dungeonLevel = 3;',
    '            Character filch;',
    '            filch.name = "Filch";',
    '            filch.classIndex = 3; filch.level = 4;',
    '            filch.race = 0; filch.abilities.dex = 13;',
    '            filch.hp = 30; filch.maxHp = 30;',
    '            st.party.members.push_back(filch);',
    '            st.party.formed = true;',
    '            st.rng.seed(2);',
    '            st.readScript();',
    '            if (!st.scriptTried) ++bad;',
    '            if (st.party.gold != 0) ++bad;',
    '            if (st.log.get(0).find('
    '"stays cryptic")',
    '                == std::string::npos) ++bad;',
    '            std::string snap = st.log.get(0);',
    '            st.readScript();',
    '            if (st.log.get(0) != snap) ++bad;',
    '        }',
    '        // scenario 11: no thief - the script',
    '        // waits (the try still spends; seed 1)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character bru;',
    '            bru.name = "Bru";',
    '            bru.classIndex = 0; bru.level = 1;',
    '            bru.race = 0; bru.abilities.str = 10;',
    '            bru.hp = 30; bru.maxHp = 30;',
    '            st.party.members.push_back(bru);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.readScript();',
    '            if (!st.scriptTried) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "waits for a thief")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        printf("R306 thief functions engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_AUD_OLD, RT_AUD_NEW):
    for ln in t.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
        assert len(ln) <= 76, 'audit line too long: ' + ln
        assert Q not in ln, 'apostrophe in audit'
        if 'printf("' in ln:
            assert ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R306 thief functions engine audit' in s:
    already.append('regtest.cpp: the audit pair')
else:
    assert s.count('audit: bad') == 229, 'rt census not 229'
    assert s.count(RT_AUD_OLD) == 1, 'rt audit anchor not unique'
    assert 'R306a' not in s, 'rt marker collision'
    s = s.replace(RT_AUD_OLD, RT_AUD_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit pair')
s = rd(p)
assert s.count('audit: bad') == 231, 'patch h census wrong'
assert s.count('R306a thief functions seam audit') == 1, \
    'patch h seam label'
assert s.count('R306 thief functions engine audit') == 1, \
    'patch h engine label'
assert s.count('R305 door force engine audit') == 1, \
    'patch h r305 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, \
    'patch h r227 head'
assert s.count('st.hideExplore();') == 4, 'patch h hide calls'
assert s.count('st.readScript();') == 5, 'patch h script calls'
assert s.count('st.springTrap(0);') == 9, 'patch h trap calls'
assert s.count('trapKind = 28') == 3, 'patch h pit kinds'
assert s.count('trapKind = 0') == 7, 'patch h arrow kinds'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) tools/phb_gap_report.md: the head + the box ----
GR298_OLD = NL.join([
    '      R304: the locked-door site rolls the',
    '      open locks draw; the rest stay data) -',
])
GR298_NEW = NL.join([
    '      R304: the locked-door site rolls the',
    '      open locks draw; WIRED R306: the',
    '      shadow, pit and script sites roll the',
    '      hide, climb and read draws; hear noise',
    '      keeps the R120 listen convention) -',
])
GR_INS_OLD = NL.join([
    '      Census 229. The ledger',
    '      holds ZERO open items.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The thief functions wired - WIRED',
    '      R306:** the last three take-table',
    '      columns gain their engine sites.',
    '      rules/thieffunc.h grows the site pins:',
    '      the observed-hide note (the DMG',
    '      commentary print - never under direct',
    '      observation; the engine runs',
    '      unobserved), the wander pass (one',
    '      absorbed wanderer per hide - the PHB',
    '      blend prose), the coarse climb surface',
    '      (the PHB print), the pit haul turn and',
    '      the script fold (one try per delve,',
    '      the 2d6 cache band). The sites: [I]',
    '      in the dungeon spends the turn and the',
    '      first living thief rolls the hide',
    '      percentile - success sets the flag and',
    '      the next wanderer passes unseen; the',
    '      pit trap draws the climb percentile',
    '      after the strike (a clean climb hauls',
    '      the victim out, a miss still hauls',
    '      but spends the turn); the lair victory',
    '      draws the read percentile once per',
    '      delve - success pays the coins cache.',
    '      The R306a battery audit walks the',
    '      boundaries and the pins (evaluable -',
    '      verified by audit_eval); the R306',
    '      engine audit pins every scenario on',
    '      seeded sequences (the replica walked',
    '      the draws first). Census 231. The',
    '      ledger holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      Census 229. The ledger',
    '      holds ZERO open items.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR298_OLD, GR298_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The thief functions wired' in s:
    already.append('phb_gap_report.md: the head + the box')
else:
    assert s.count(GR298_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    assert 'Census 231.' not in s, 'gr marker collision'
    s = s.replace(GR298_OLD, GR298_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the head + the box')
s = rd(p)
assert s.count('The thief functions wired') == 1, 'patch i box'
assert s.count('WIRED R306') == 1, 'patch i wired note'
assert s.count('holds ZERO open items') == 6, \
    'patch i zero notes'
assert s.count('Census 231.') == 1, 'patch i census note'
assert s.count('Census 229.') == 1, 'patch i r305 census'
assert s.count('Census 227.') == 1, 'patch i r304 census'
assert s.count('Census 225.') == 1, 'patch i r303 census'
assert s.count('Census 223.') == 1, 'patch i r302 census'
assert 'Census 221.' in s, 'patch i ate the R301 census'
assert 'Census 215.' in s, 'patch i ate the R298 census'
assert 'PINNED R298' in s, 'patch i ate the R298 box head'
assert 'The locked door forced' in s, 'patch i ate the R305 box'
assert 'The thief locks wired' in s, 'patch i ate the R304 box'
assert 'The thief pockets wired' in s, 'patch i ate the R303 box'
assert '## R299 the party recordings round' in s, \
    'patch i ate the head'
assert s.count('- [ ]') == 0, 'patch i opened an item'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- (j) tools/dmg_gap_report.md: the chronicle ----
DMG_OLD = NL.join([
    'box; the battery census moves 227 -> 229).',
    '',
    'Categories:',
])
DMG_NEW = NL.join([
    'box; the battery census moves 227 -> 229).',
    '',
    'R306 PINNED the DMG thief commentary folds:',
    'the hide site (hiding is never possible',
    'under direct or even indirect observation -',
    'the engine runs the unobserved attempt and',
    'the dice), the climb site (the climb walls',
    'haul at the pit trap - a coarse surface',
    'with ledges and cracks, the PHB print) and',
    'the script site (the read languages draw on',
    'the lair treasure map). The phb report',
    'carries the round box; the battery census',
    'moves 229 -> 231).',
    '',
    'Categories:',
])
for t in (DMG_OLD, DMG_NEW):
    clean(t, 57)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R306 PINNED the DMG thief commentary' in s:
    already.append('dmg_gap_report.md: the chronicle')
else:
    assert s.count(DMG_OLD) == 1, 'dmg anchor not unique'
    s = s.replace(DMG_OLD, DMG_NEW)
    wr(p, s)
    applied.append('dmg_gap_report.md: the chronicle')
s = rd(p)
assert s.count('R306 PINNED the DMG thief commentary') == 1, \
    'patch j note'
assert s.count('moves 229 -> 231') == 1, 'patch j census note'
assert s.count('Categories:') == 1, 'patch j legend head'
assert s.count('R305 PINNED the DMG FIRST DUNGEON') == 1, \
    'patch j r305 chronicle'
assert s.count('- [ ]') == 1, 'patch j checkbox count'
assert 'battery census stays 213.' in s, 'patch j ate the R296 tail'
assert len(applied) + len(already) == 10, 'patch j count wrong'

# ---- R306 fails/tail ----
if fails:
    print('R306 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 10:
    print('R306 splice: FAIL - expected 10 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R306 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R306 note: 10 patches; the battery census 229 -> 231;')
print('the phb ledger holds ZERO open items')
print('commit: R306: the thief functions wired (census 231)')

