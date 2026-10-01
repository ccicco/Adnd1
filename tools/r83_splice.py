#!/usr/bin/env python3
# R83-CHUNK-1-START
# R83 "TELEPORT + TOWN KEYS" splice - content-anchored, idempotent.
# Patches (7 patch groups, 6 files):
#   game/appstate.h   - L4-6 cast gate (3 -> 6) in castableSpells;
#                       comment notes for the two town rites
#   ai/actor.h        - Encounter::teleported() getter + flag
#   ai/actor.cpp      - resolveCast gate 3 -> 6; MU_TELEPORT party
#                       escape intercept; round ends with result 4
#   game/state_combat.cpp - endCombat: no spoils + town landing on
#                       a teleport escape; outcome case 4
#   adnd1.cpp         - town keys [L] study / [R] raise; drawTown
#                       collision fix ([O] was overdrawn) + menu;
#                       spell menu 1-9 + A-G cast keys
#   regtest.cpp       - "R83 teleport audit: bad 0"
# All anchors and all inserted text are ASCII-only (protocol rule).

import sys, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)

REPORT = []

def patch(fname, old, new, tag, count=1):
    """Exact-substring patch. Idempotent: skips if 'new' present.
    (The check keys on NEW content - where old is a substring of
    new, keying on old would re-apply forever.)"""
    s = rd(fname)
    if new in s:
        REPORT.append("%s: already patched" % tag)
        return True
    n = s.count(old)
    if n != count:
        REPORT.append("%s: FAIL (anchor x%d, want %d)" % (tag, n, count))
        return False
    s = s.replace(old, new, count)
    wr(fname, s)
    REPORT.append("%s: patched" % tag)
    return True

OK = True

# ---------------------------------------------------------------------------
# 1) game/appstate.h - the L4-6 casting gate
# ---------------------------------------------------------------------------
OK &= patch('game/appstate.h',
"""            if (s.level < 1 || s.level > 3) continue;
            if (s.level > maxLv) continue;""",
"""            // R83: the L4-6 ladder is castable - the old 1-3
            // gate left R80/R82's higher spells forever pending
            if (s.level < 1 || s.level > 6) continue;
            if (s.level > maxLv) continue;""",
'appstate.h cast gate')
# R83-CHUNK-1-END
# R83-CHUNK-2-START
OK &= patch('game/appstate.h',
"""    // on success or failure (PHB p.10 study convention). Win32
    // keybinding is a later shell diff.
    void townStudyScrolls();""",
"""    // on success or failure (PHB p.10 study convention).
    // R83: bound to the [L] town key.
    void townStudyScrolls();""",
'appstate.h study comment')

OK &= patch('game/appstate.h',
"""    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    void townRaiseDead();""",
"""    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    // R83: bound to the [R] town key.
    void townRaiseDead();""",
'appstate.h raise comment')

# ---------------------------------------------------------------------------
# 2) ai/actor.h - the teleport flag + getter
# ---------------------------------------------------------------------------
OK &= patch('ai/actor.h',
"""    void requestThrow(int memberIndex) {
        m_throwMember = memberIndex;
    }
""",
"""    void requestThrow(int memberIndex) {
        m_throwMember = memberIndex;
    }

    // R83: a party Teleport ends the encounter - the game layer
    // reads this after the round to route the company to town
    // (result 4, no spoils).
    bool teleported() const { return m_teleported; }
""",
'actor.h getter')

OK &= patch('ai/actor.h',
"""    int  m_throwMember = -1;                // R36 (-1 = none)
""",
"""    int  m_throwMember = -1;                // R36 (-1 = none)

    bool m_teleported = false;              // R83: Teleport escape
""",
'actor.h member')

# ---------------------------------------------------------------------------
# 3) ai/actor.cpp - gate, intercept, round-end
# ---------------------------------------------------------------------------
OK &= patch('ai/actor.cpp',
"""    if (s.level < 1 || s.level > 3) return;
    if (caster.slotsByLevel[s.level - 1] <= 0) {""",
"""    // R83: the L4-6 ladder is castable (was gated at 3)
    if (s.level < 1 || s.level > 6) return;
    if (caster.slotsByLevel[s.level - 1] <= 0) {""",
'actor.cpp cast gate')
# R83-CHUNK-2-END
# R83-CHUNK-3-START
OK &= patch('ai/actor.cpp',
"""    --caster.slotsByLevel[s.level - 1];
    logLine(caster.name + " casts " + s.name + "!");
""",
"""    --caster.slotsByLevel[s.level - 1];
    logLine(caster.name + " casts " + s.name + "!");

    // R83: Teleport is a party-level escape, not a per-target
    // effect - the caster whisks the whole company home. The
    // town is the party's established base, "very familiar" in
    // PHB terms, so the mishap table is waived (documented
    // simplification). The slot is spent above; the round ends
    // (result 4) and the game layer lands the company in town.
    if (id == spells::MU_TELEPORT && caster.team == 0) {
        m_teleported = true;
        logLine("The air folds around the company!");
        return;
    }
""",
'actor.cpp teleport intercept')

OK &= patch('ai/actor.cpp',
"""            resolveCast(attacker,
                        isParty ? castSpell : monsterCastSpell);
            if (teamAlive(0) == 0 || teamAlive(1) == 0) break;
            continue;""",
"""            resolveCast(attacker,
                        isParty ? castSpell : monsterCastSpell);
            if (m_teleported) return 4;   // R83: the escape ends
                                          // the round immediately
            if (teamAlive(0) == 0 || teamAlive(1) == 0) break;
            continue;""",
'actor.cpp round end')

# ---------------------------------------------------------------------------
# 4) game/state_combat.cpp - endCombat teleport branch
# ---------------------------------------------------------------------------
OK &= patch('game/state_combat.cpp',
"""void AppState::endCombat(){
        if (combat.encounter) {""",
"""void AppState::endCombat(){
        // R83: a teleport escape - no spoils, and the company
        // lands in town (read before the encounter resets)
        bool teleported = combat.encounter &&
                          combat.encounter->teleported();
        if (combat.encounter) {""",
'state_combat.cpp teleported flag')
# R83-CHUNK-3-END
# R83-CHUNK-4-START
OK &= patch('game/state_combat.cpp',
"""            awardVictory();
""",
"""            if (!teleported)   // R83: no spoils from an escape
                awardVictory();
""",
'state_combat.cpp no spoils')

OK &= patch('game/state_combat.cpp',
"""                case 3: outcome = "The monsters fled."; break;
                default: outcome = "The fight ends."; break;""",
"""                case 3: outcome = "The monsters fled."; break;
                case 4: outcome = "The company teleports away!"; break;
                default: outcome = "The fight ends."; break;""",
'state_combat.cpp outcome')

OK &= patch('game/state_combat.cpp',
"""        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail""",
"""        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail
        if (teleported) {   // R83: the spell lands the company
            mode = MODE_TOWN;   // in town, not back on the trail
            billTownVisit();
        }""",
'state_combat.cpp town landing')

# ---------------------------------------------------------------------------
# 5) adnd1.cpp - town keys, drawTown rework, spell menu keys
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""                    case 'B':
                    case 'b':
                    case VK_ESCAPE:
                        g_app.leaveTown();
                        break;""",
"""                    // R83: the study desk and the temple rite
                    case 'L':
                    case 'l':
                        g_app.townStudyScrolls();
                        break;

                    case 'R':
                    case 'r':
                        g_app.townRaiseDead();
                        break;

                    case 'B':
                    case 'b':
                    case VK_ESCAPE:
                        g_app.leaveTown();
                        break;""",
'adnd1.cpp town keys')
# R83-CHUNK-4-END
# R83-CHUNK-5-START

# drawTown: the [O] line was overdrawn by [B]/[Esc] at y=528
# (pre-existing bug - overland departure was invisible). The
# em-dash lines cannot be anchors (ASCII-only rule), so the
# block is located by line scan and replaced whole.
def patch_draw_town():
    fname = 'adnd1.cpp'
    s = rd(fname)
    new_block = """    SetTextColor(dc, RGB(160, 150, 120));
    snprintf(line, sizeof line,
             "[O] overland  [V] sea  [W] city - set out");
    TextOutA(dc, 20, 528, line, (int)strlen(line));

    // R83: the study desk and the temple rite
    snprintf(line, sizeof line, "[L] Study the carried scrolls");
    TextOutA(dc, 20, 552, line, (int)strlen(line));
    snprintf(line, sizeof line, "[R] Raise a fallen member - 1,000 gp");
    TextOutA(dc, 20, 576, line, (int)strlen(line));

    snprintf(line, sizeof line, "[B]/[Esc] return to the dungeon");
    TextOutA(dc, 20, 600, line, (int)strlen(line));
"""
    if '[L] Study the carried scrolls' in s:
        REPORT.append('adnd1.cpp drawTown: already patched')
        return True
    lines = s.split('\n')
    start = end = -1
    for i, ln in enumerate(lines):
        if '[O] Set out overland' in ln:
            start = i - 1   # the SetTextColor line above it
        if '[B]/[Esc] return to the dungeon' in ln:
            end = i + 2     # its snprintf + its TextOutA
            break
    if start < 0 or end < start:
        REPORT.append('adnd1.cpp drawTown: FAIL (block not found)')
        return False
    if 'SetTextColor(dc, RGB(160, 150, 120));' not in lines[start]:
        REPORT.append('adnd1.cpp drawTown: FAIL (SetTextColor misplaced)')
        return False
    if 'TextOutA' not in lines[end - 1]:
        REPORT.append('adnd1.cpp drawTown: FAIL (TextOutA misplaced)')
        return False
    lines[start:end] = new_block.split('\n')[:-1]
    wr(fname, '\n'.join(lines))
    REPORT.append('adnd1.cpp drawTown: patched')
    return True

OK &= patch_draw_town()

# spell menu: header + input keys + render rows
OK &= patch('adnd1.cpp',
"""([1-9] cast, [c/esc] close)""",
"""([1-9A-G] cast, [esc] close)""",
'adnd1.cpp menu header')
# R83-CHUNK-5-END
# R83-CHUNK-6-START
OK &= patch('adnd1.cpp',
"""                    if (wp == 'C' || wp == 'c' || wp == VK_ESCAPE) {
                        g_app.combat.spellMenuOpen = false;
                    } else if (wp >= '1' && wp <= '9') {
                        int pick = (int)(wp - '1');""",
"""                    // R83: [esc] closes - letters are cast keys
                    // now (a full-book MU needs [A-G] to reach the
                    // L4-6 ladder)
                    if (wp == VK_ESCAPE) {
                        g_app.combat.spellMenuOpen = false;
                    } else if ((wp >= '1' && wp <= '9') ||
                               (wp >= 'A' && wp <= 'G') ||
                               (wp >= 'a' && wp <= 'g')) {
                        int pick = (wp <= '9')
                                       ? (int)(wp - '1')
                                       : 9 + (int)(wp - (wp < 'a' ? 'A' : 'a'));""",
'adnd1.cpp menu keys')

OK &= patch('adnd1.cpp',
"""        int sy = 180;
        for (size_t i = 0; i < list.size() && i < 9; ++i) {
            const spells::SpellDef& s = spells::spell(list[i]);
            char row[96];
            snprintf(row, sizeof row,
                     "  [%d] %-20s L%d  ct%d seg  (%d slots)",
                     (int)i + 1, s.name, s.level, s.castingTime,""",
"""        int sy = 180;
        // R83: 16 cast keys - [1-9] then [A-G]
        for (size_t i = 0; i < list.size() && i < 16; ++i) {
            const spells::SpellDef& s = spells::spell(list[i]);
            char keych = (i < 9) ? (char)('1' + i)
                                 : (char)('A' + (i - 9));
            char row[96];
            snprintf(row, sizeof row,
                     "  [%c] %-20s L%d  ct%d seg  (%d slots)",
                     keych, s.name, s.level, s.castingTime,""",
'adnd1.cpp menu rows')
# R83-CHUNK-6-END
# R83-CHUNK-7-START

# ---------------------------------------------------------------------------
# 6) regtest.cpp - the R83 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R82 death/revival audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R82 death/revival audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R83: teleport + L4-6 casting gates audit ----
    {
        int bad = 0;
        // the Teleport registry row (values from kSpells)
        const spells::SpellDef& tp =
            spells::spell(spells::MU_TELEPORT);
        if (std::string(tp.name) != "Teleport") ++bad;
        if (tp.sclass != spells::SPELL_MU) ++bad;
        if (tp.level != 5) ++bad;
        if (tp.castingTime < 1) ++bad;
        if (tp.saveCategory != -1) ++bad;
        if (tp.target != spells::TARGET_SPECIAL) ++bad;
        if (tp.reversible) ++bad;
        // L5 MU slots start at class level 9 (kMuSlots row 9)
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 5) != 0) ++bad;
        // INT gates the L5 (PHB p.10): 15 reaches L5, 16 reaches L6
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        // every registry row sits in 1..6 (the R83 gate domain)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 6) ++bad;
        }
        printf("R83 teleport audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp audit')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R83 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R83-CHUNK-7-END
