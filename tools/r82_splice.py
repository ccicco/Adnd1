#!/usr/bin/env python3
"""r82_splice.py -- the R82 "death and revival" tranche, one shot:
 (1) spelleffects.h: STATUS_POLYMORPHED enum, TargetDesc.hitDice,
     deathSpellBudget() helper (used by spelleffects.cpp AND regtest);
 (2) spelleffects.cpp: MU_DISINTEGRATE (save or slain - lethal
     damage = target hp), MU_DEATH_SPELL (no save, kills up to
     4 x caster level HD, undead immune, spent in target order -
     documented simplification), MU_POLYMORPH_OTHER (save or
     STATUS_POLYMORPHED, held-like);
 (3) ai/actor.cpp: asTarget fills hitDice; canAct honors
     STATUS_POLYMORPHED;
 (4) party.h: canRaiseDead() helper;
 (5) state_town.cpp + appstate.h: townRaiseDead() - a 7th+ level
     cleric raises one dead member per rite (1000 gp offering),
     survival roll vs rules::conResSurvival, raised at 1 hp;
 (6) regtest.cpp: R82 death/revival audit.
Content-anchored on exact bytes; idempotent (per-file markers).
Run from repo root."""
import sys

def rw(p): return open(p, encoding='utf-8').read()
def wr(p, s): open(p, 'w', encoding='utf-8').write(s)
report = []

def patch(path, pairs, marker):
    if marker in rw(path):
        report.append(path + ': already patched')
        return
    src = rw(path)
    for old, new in pairs:
        n = src.count(old)
        assert n == 1, ('anchor not unique (%d) in ' % n) + path \
            + ' :: ' + old[:60]
        src = src.replace(old, new, 1)
    wr(path, src)
    report.append(path + ': patched (%d edits)' % len(pairs))

# ---------- (1) spelleffects.h: enum + hitDice + budget helper ----------
patch('spelleffects/spelleffects.h', [
(
'''    STATUS_ANTIVENOM,    // R81: Slow/Neutralize Poison - save bonus
    STATUS_COUNT''',
'''    STATUS_ANTIVENOM,    // R81: Slow/Neutralize Poison - save bonus
    STATUS_POLYMORPHED,  // R82: Polymorph Other - held-like
    STATUS_COUNT'''),
(
'''    int hp = 10;
    int maxHp = 10;''',
'''    int hp = 10;
    int maxHp = 10;
    float hitDice = 1.0f;   // R82: Death Spell HD budgeting'''),
(
'''// R81: Fire Shield reflect - the melee attacker takes half the
// damage dealt, rounded up, minimum 1
inline int fireShieldDamage(int dmg) {''',
'''// R82: Death Spell HD budget (PHB L6 MU): the spell snuffs out
// up to 4 x caster level hit dice of creatures.
inline int deathSpellBudget(int casterLevel) {
    if (casterLevel < 1) casterLevel = 1;
    return casterLevel * 4;
}

// R81: Fire Shield reflect - the melee attacker takes half the
// damage dealt, rounded up, minimum 1
inline int fireShieldDamage(int dmg) {'''),
], marker='STATUS_POLYMORPHED')

# ---------- (2) spelleffects.cpp: the three cases ----------
patch('spelleffects/spelleffects.cpp', [
(
'''    SpellCastResult out;
    const spells::SpellDef& s = spells::spell(id);

    for (const TargetDesc& t : targets) {''',
'''    SpellCastResult out;
    const spells::SpellDef& s = spells::spell(id);

    // R82: Death Spell HD budget - kills up to 4 x caster level
    // hit dice of creatures, spent in target order
    int deathBudget = (id == spells::MU_DEATH_SPELL)
                          ? deathSpellBudget(casterLevel) : 0;

    for (const TargetDesc& t : targets) {'''),
(
'''            case spells::MU_FIRE_SHIELD:   // R81''',
'''            case spells::MU_DISINTEGRATE: {   // R82
                // save vs. spells or disintegrated: lethal damage
                r.affected = true;
                r.saveMade = trySave(dice, s, t);
                if (r.saveMade) {
                    snprintf(r.note, sizeof r.note,
                             "%s: saved", s.name);
                } else {
                    r.damage = t.hp;   // the target is destroyed
                    snprintf(r.note, sizeof r.note,
                             "%s: disintegrated!", s.name);
                }
                break;
            }
            case spells::MU_DEATH_SPELL: {   // R82
                r.affected = true;
                if (t.isUndead) {
                    snprintf(r.note, sizeof r.note,
                             "%s: no effect (undead)", s.name);
                    break;
                }
                // no save; the HD budget decides (fractional HD
                // costs 1 - a 4-hd budget takes four 1-hd orcs
                // or one 4-hd ogre)
                int cost = (int)t.hitDice;
                if (cost < 1) cost = 1;
                if (deathBudget >= 1 && cost <= deathBudget) {
                    deathBudget -= cost;
                    r.damage = t.hp;
                    snprintf(r.note, sizeof r.note,
                             "%s: life force snuffed out!", s.name);
                } else {
                    snprintf(r.note, sizeof r.note,
                             "%s: unaffected", s.name);
                }
                break;
            }
            case spells::MU_POLYMORPH_OTHER:   // R82
                r = resolveStatusSpell(dice, s, STATUS_POLYMORPHED,
                                       s.durationRounds, t, false);
                break;
            case spells::MU_FIRE_SHIELD:   // R81'''),
], marker='MU_DISINTEGRATE')

# ---------- (3) ai/actor.cpp: hitDice + canAct ----------
patch('ai/actor.cpp', [
(
'''    t.magicResistPct = isCharacter ? 0 : magicResistPct;''',
'''    t.magicResistPct = isCharacter ? 0 : magicResistPct;
    t.hitDice = hitDice;   // R82: Death Spell budgeting'''),
(
'''    if (hasStatus(spelleffects::STATUS_HELD)) return false;
    if (psionicStunned) return false;   // R46''',
'''    if (hasStatus(spelleffects::STATUS_HELD)) return false;
    if (hasStatus(spelleffects::STATUS_POLYMORPHED)) return false;
    if (psionicStunned) return false;   // R46'''),
], marker='STATUS_POLYMORPHED')

# ---------- (4) party.h: canRaiseDead ----------
patch('game/party.h', [
(
'''// R81: the next spell a member could study from a scroll - the''',
'''// ----------------------------------------------------------------------------
// R82: revival helper
// ----------------------------------------------------------------------------
// Raise Dead eligibility: a living 7th+ level cleric (PHB p. 46 -
// clerics gain 5th-level spells at 7th, Raise Dead among them).
inline bool canRaiseDead(const Character& c) {
    return c.classIndex == 2 && c.level >= 7 && c.hp > 0;
}

// R81: the next spell a member could study from a scroll - the'''),
], marker='canRaiseDead')

# ---------- (5) appstate.h decl ----------
patch('game/appstate.h', [
(
'''    void townStudyScrolls();''',
'''    void townStudyScrolls();

    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    void townRaiseDead();'''),
], marker='townRaiseDead')

# ---------- (5b) state_town.cpp implementation ----------
patch('game/state_town.cpp', [
(
'''// ---- R81: study the carried scrolls ----''',
'''// ---- R82: raise a dead member ----
void AppState::townRaiseDead(){
        if (mode != MODE_TOWN) return;
        // the rite needs a living 7th+ level cleric
        const Character* cleric = nullptr;
        for (const auto& c : party.members) {
            if (canRaiseDead(c)) { cleric = &c; break; }
        }
        if (!cleric) {
            log.add("No cleric of 7th level or better is "
                    "able to raise the dead.");
            return;
        }
        // the first dead member (hp 0 in the roster)
        Character* dead = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) { dead = &c; break; }
        }
        if (!dead) {
            log.add("No member of the company is dead.");
            return;
        }
        if (party.gold < 1000) {
            log.add("The temple demands a 1,000 gp offering "
                    "for the rite.");
            return;
        }
        party.gold -= 1000;
        char buf[96];
        int survival = rules::conResSurvival(dead->abilities.con);
        if ((int)dice.roll(1, 100, 0) <= survival) {
            dead->hp = 1;
            snprintf(buf, sizeof buf,
                     "%s returns to life at %s's word!",
                     dead->name.c_str(), cleric->name.c_str());
            log.add(buf);
        } else {
            snprintf(buf, sizeof buf,
                     "%s's spirit cannot return; the offering "
                     "is spent.",
                     dead->name.c_str());
            log.add(buf);
        }
    }

// ---- R81: study the carried scrolls ----'''),
], marker='townRaiseDead')

# ---------- (6) regtest.cpp: R82 audit ----------
patch('regtest.cpp', [
(
'''        printf("R81 rings/scrolls/status audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }''',
'''        printf("R81 rings/scrolls/status audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R82: death and revival -----------------------------------
    {
        int bad = 0;
        // Death Spell HD budget: 4 x caster level, min level 1
        if (spelleffects::deathSpellBudget(1) != 4) ++bad;
        if (spelleffects::deathSpellBudget(6) != 24) ++bad;
        if (spelleffects::deathSpellBudget(12) != 48) ++bad;
        if (spelleffects::deathSpellBudget(0) != 4) ++bad;   // clamp
        // Raise Dead eligibility: living cleric 7th+
        Character c;
        c.classIndex = 2;
        c.level = 6;
        c.hp = 10;
        if (canRaiseDead(c)) ++bad;
        c.level = 7;
        if (!canRaiseDead(c)) ++bad;
        // a fighter never raises
        c.classIndex = 0;
        if (canRaiseDead(c)) ++bad;
        // the dead cleric cannot raise
        c.classIndex = 2;
        c.hp = 0;
        if (canRaiseDead(c)) ++bad;
        // resurrection survival table sanity (PHB CON table):
        // every value is a percent in 35..100
        for (int con = 3; con <= 18; ++con) {
            int sv = rules::conResSurvival((uint8_t)con);
            if (sv < 35 || sv > 100) ++bad;
        }
        printf("R82 death/revival audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }'''),
], marker='R82 death/revival audit')

print('; '.join(report))
