#!/usr/bin/env python3
"""r81_splice.py -- the R81 "magic items" tranche, one shot:
 (1) spelleffects.h: STATUS_FIRESHIELD + STATUS_ANTIVENOM enums,
     fireShieldDamage() reflect helper;
 (2) spelleffects.cpp: Fire Shield -> FIRESHIELD status; Slow/
     Neutralize Poison -> ANTIVENOM status (passive +N on poison
     saves; the engine's poison is instant-damage, so pending-death
     suspension is out of scope - documented simplification);
 (3) ai/actor.h/.cpp: Character/Actor ringPlus (Ring of Protection
     AC bonus), statusBonus() helper, fire-shield melee reflect,
     antivenom eases SAVE_DEATH_POISON in trySaveVs;
 (4) game/party.h: ringPlus field, toActor seed, claimRing() +
     pickStudySpell() helpers;
 (5) game/state_dungeon.cpp: MIK_OTHER claim case (Ring of
     Protection only; other rings/rods/misc stay appraised);
 (6) game/state_core.cpp: ringplus save line + load case +
     equipment dump shows the ring;
 (7) game/state_town.cpp + appstate.h: townStudyScrolls() - study
     the carried scrolls (chance-to-learn, scroll consumed either
     way, PHB p.10);
 (8) regtest.cpp: R81 rings/scrolls/status audit.
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

# ---------- (1) spelleffects.h: enums + helper ----------
patch('spelleffects/spelleffects.h', [
(
'''    STATUS_SHIELDED,     // mage shield spell
    STATUS_COUNT''',
'''    STATUS_SHIELDED,     // mage shield spell
    STATUS_FIRESHIELD,   // R81: Fire Shield - melee reflect
    STATUS_ANTIVENOM,    // R81: Slow/Neutralize Poison - save bonus
    STATUS_COUNT'''),
(
'''    int        magnitude = 0;    // e.g. shield AC bonus
};''',
'''    int        magnitude = 0;    // e.g. shield AC bonus
};

// R81: Fire Shield reflect - the melee attacker takes half the
// damage dealt, rounded up, minimum 1
inline int fireShieldDamage(int dmg) {
    int r = dmg / 2 + (dmg % 2 ? 1 : 0);
    return r < 1 ? 1 : r;
}'''),
], marker='STATUS_FIRESHIELD')

# ---------- (2) spelleffects.cpp: wire the new statuses ----------
patch('spelleffects/spelleffects.cpp', [
(
'''            case spells::MU_CHARM_PERSON:''',
'''            case spells::MU_FIRE_SHIELD:   // R81
                r = resolveStatusSpell(dice, s, STATUS_FIRESHIELD,
                                       s.durationRounds, t, false);
                break;
            case spells::MU_CHARM_PERSON:'''),
(
'''            case spells::CL_PROTECTION_FROM_EVIL:''',
'''            case spells::CL_SLOW_POISON:        // R81
            case spells::CL_NEUTRALIZE_POISON:   // R81
                r = resolveStatusSpell(dice, s, STATUS_ANTIVENOM,
                                       s.durationRounds, t, false);
                if (!r.saveMade && r.status.kind ==
                        spelleffects::STATUS_ANTIVENOM)
                    r.status.magnitude = 4;   // +4 on poison saves
                break;
            case spells::CL_PROTECTION_FROM_EVIL:'''),
], marker='MU_FIRE_SHIELD:')

# ---------- (3a) ai/actor.h: ring field + statusBonus ----------
patch('ai/actor.h', [
(
'''    int  shieldPlus = 0;''',
'''    int  shieldPlus = 0;
    // R81: Ring of Protection AC bonus (0 = none worn)
    int  ringPlus = 0;'''),
(
'''    bool hasStatus(spelleffects::StatusKind k) const;''',
'''    bool hasStatus(spelleffects::StatusKind k) const;
    // R81: the best magnitude carried for a status (0 when none)
    int statusBonus(spelleffects::StatusKind k) const {
        int b = 0;
        for (const auto& s : statuses)
            if (s.kind == k && s.magnitude > b) b = s.magnitude;
        return b;
    }'''),
], marker='statusBonus')

# ---------- (3b) ai/actor.cpp: AC, reflect, poison saves ----------
patch('ai/actor.cpp', [
(
'''    if (isCharacter) {
        // R55: the carried shield enchantment applies
        return items::effectiveAc(armor, shield, shieldPlus, dex);
    }''',
'''    if (isCharacter) {
        // R55: the carried shield enchantment applies;
        // R81: the Ring of Protection improves AC too
        return items::effectiveAc(armor, shield, shieldPlus, dex)
               - ringPlus;
    }'''),
(
'''    // sleeping targets wake when struck''',
'''    // R81: Fire Shield - melee attackers take half the dealt
    // damage back (rounded up, min 1); melee contact only
    if (defender.hasStatus(spelleffects::STATUS_FIRESHIELD) &&
        attacker.alive()) {
        int ref = spelleffects::fireShieldDamage(dmg);
        attacker.hp -= ref;
        logLine(defender.name + "'s fire shield sears " +
                attacker.name + " (" + std::to_string(ref) + ")");
        if (!attacker.alive()) {
            attacker.hp = 0;
            logLine(attacker.name + " is down!");
        }
    }

    // sleeping targets wake when struck'''),
(
'''        // penalty makes saving HARDER by raising the target
        return rules::attemptSave(m_dice, target + penalty, 0);''',
'''        // R81: antivenom (Slow/Neutralize Poison) eases
        // death/poison saves by the status magnitude
        if ((rules::SaveCategory)saveCategory ==
                rules::SAVE_DEATH_POISON)
            target -= defender.statusBonus(
                spelleffects::STATUS_ANTIVENOM);
        // penalty makes saving HARDER by raising the target
        return rules::attemptSave(m_dice, target + penalty, 0);'''),
], marker='fireShieldDamage(dmg)')

# ---------- (4) party.h: ring field + seeds + helpers ----------
patch('game/party.h', [
(
'''    int shieldPlus = 0;''',
'''    int shieldPlus = 0;
    // R81: Ring of Protection AC bonus (0 = none worn)
    int ringPlus = 0;'''),
(
'''        a.shieldPlus = shieldPlus;   // R56''',
'''        a.shieldPlus = shieldPlus;   // R56
        a.ringPlus = ringPlus;   // R81'''),
(
'''    quiverAdd(c.quiver, plus, qty);
    c.missileAmmo = quiverTotal(c.quiver);
    return true;
}''',
'''    quiverAdd(c.quiver, plus, qty);
    c.missileAmmo = quiverTotal(c.quiver);
    return true;
}

// ----------------------------------------------------------------------------
// R81: the ring + scroll-study helpers
// ----------------------------------------------------------------------------
// claim a Ring of Protection for a member (the III.C table prints no
// +N in the name; +1 is the convention - documented simplification
// vs the PHB's +1/+2 brackets). One ring per member, first taker
// wins; every other ring/rod/misc stays appraised.
inline bool claimRing(Character& c, const std::string& name,
                      int qty) {
    if (c.hp <= 0 || qty != 1 || c.ringPlus > 0) return false;
    if (name.find("Ring of Protection") == std::string::npos)
        return false;
    c.ringPlus = 1;
    return true;
}

// R81: the next spell a member could study from a scroll - the
// lowest-level unknown spell of his class in id order
// (deterministic; regtest pins it). -1 when the book is complete.
inline int pickStudySpell(const Character& c) {
    int best = -1;
    int bestLv = 99;
    for (int id = 0; id < spells::SPELL_COUNT; ++id) {
        const spells::SpellDef& s =
            spells::spell((spells::SpellId)id);
        if (c.classIndex == 1 && s.sclass != spells::SPELL_MU)
            continue;
        if (c.classIndex == 2 && s.sclass != spells::SPELL_CLERIC)
            continue;
        if (c.knowsSpell(id)) continue;
        if (s.level < bestLv) { bestLv = s.level; best = id; }
    }
    return best;
}'''),
], marker='claimRing')

# ---------- (5) state_dungeon.cpp: the ring claim ----------
patch('game/state_dungeon.cpp', [
(
'''                    default:
                        // MIK_OTHER (rings/rods/misc) and declined
                        // ammo stay appraised to gold
                        break;''',
'''                    case dm::treasure::MIK_OTHER:
                        // R81: a Ring of Protection goes to the
                        // first living member without one; every
                        // other ring/rod/misc stays appraised
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (claimRing(c, mi.name, mi.qty)) {
                                snprintf(buf, sizeof buf,
                                         "%s wears the %s.",
                                         c.name.c_str(),
                                         mi.name.c_str());
                                log.add(buf);
                                take = true;
                                break;
                            }
                        }
                        break;
                    default:
                        // declined ammo and unclaimed rings/rods/
                        // misc stay appraised to gold
                        break;'''),
], marker='claimRing(c, mi.name')

# ---------- (6) state_core.cpp: save + load + dump ----------
patch('game/state_core.cpp', [
(
'''            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\\n", c.shieldPlus);''',
'''            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\\n", c.shieldPlus);
            // R81: the Ring of Protection bonus (nonzero only)
            if (c.ringPlus > 0)
                fprintf(f, "ringplus %d\\n", c.ringPlus);'''),
(
'''                if (strcmp(tag, "shieldplus") == 0) {''',
'''                if (strcmp(tag, "ringplus") == 0) {
                    int rg = 0;
                    if (fscanf(f, "%d", &rg) != 1 ||
                        rg < 0 || rg > 5) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (ring).");
                        return false;
                    }
                    c.ringPlus = rg;
                } else if (strcmp(tag, "shieldplus") == 0) {'''),
(
'''            snprintf(buf, sizeof buf, "%s: %s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh);''',
'''            char rg[16];
            if (c.ringPlus > 0) snprintf(rg, sizeof rg,
                                          ", ring +%d",
                                          c.ringPlus);
            else rg[0] = 0;
            snprintf(buf, sizeof buf, "%s: %s%s%s%s%s",
                     c.name.c_str(), melee, ranged, arm, sh, rg);'''),
], marker='ringplus')

# ---------- (7) appstate.h decl ----------
patch('game/appstate.h', [
(
'''    void dumpEquipment();''',
'''    void dumpEquipment();

    // R81: study the carried scrolls (town) - each scroll is an MU
    // spell scroll; one chance-to-learn roll per scroll, consumed
    // on success or failure (PHB p.10 study convention). Win32
    // keybinding is a later shell diff.
    void townStudyScrolls();'''),
], marker='townStudyScrolls')

# ---------- (7b) state_town.cpp implementation ----------
patch('game/state_town.cpp', [
(
'''        if (mode == MODE_OVERLAND) checkArrivedHome();
        if (mode == MODE_SEA) checkArrivedSea();   // R70
    }''',
'''        if (mode == MODE_OVERLAND) checkArrivedHome();
        if (mode == MODE_SEA) checkArrivedSea();   // R70
    }

// ---- R81: study the carried scrolls ----
void AppState::townStudyScrolls(){
        if (mode != MODE_TOWN) return;
        if (party.scrolls <= 0) {
            log.add("You carry no scrolls to study.");
            return;
        }
        int studied = 0, learned = 0;
        char buf[96];
        while (party.scrolls > 0) {
            // the scroll goes to the first living MU with an
            // unknown spell (III.B scrolls are MU spell scrolls;
            // clerics pray, they do not study - PHB convention)
            Character* taker = nullptr;
            int sid = -1;
            for (auto& c : party.members) {
                if (c.hp <= 0 || c.classIndex != 1) continue;
                int pick = pickStudySpell(c);
                if (pick >= 0) { taker = &c; sid = pick; break; }
            }
            if (!taker) break;   // every book is complete
            --party.scrolls;
            ++studied;
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)sid);
            if (spells::rollChanceToLearn(dice,
                    taker->abilities.int_)) {
                taker->knownSpells.push_back(sid);
                snprintf(buf, sizeof buf,
                         "%s masters %s from a scroll!",
                         taker->name.c_str(), s.name);
                log.add(buf);
                ++learned;
            } else {
                snprintf(buf, sizeof buf,
                         "%s fails to master %s; the scroll "
                         "crumbles.",
                         taker->name.c_str(), s.name);
                log.add(buf);
            }
        }
        snprintf(buf, sizeof buf,
                 "Studied %d scroll%s; %d spell%s learned.",
                 studied, studied == 1 ? "" : "s",
                 learned, learned == 1 ? "" : "s");
        log.add(buf);
    }'''),
], marker='townStudyScrolls')

# ---------- (8) regtest.cpp: R81 audit ----------
patch('regtest.cpp', [
(
'''        printf("R80 spells audit: %d spells (MU %d, CL %d), "
               "L4-6 %d, bad %d\\n",
               spells::SPELL_COUNT, mu, cl, l46, bad);
        if (bad) return 1;
    }
    return 0;
            }''',
'''        printf("R80 spells audit: %d spells (MU %d, CL %d), "
               "L4-6 %d, bad %d\\n",
               spells::SPELL_COUNT, mu, cl, l46, bad);
        if (bad) return 1;
    }

    // ---- R81: ring claims, scroll picks, status helpers --------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // a member takes the ring
        if (!claimRing(c, "Ring of Protection", 1)) ++bad;
        if (c.ringPlus != 1) ++bad;
        // one ring per member
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.ringPlus = 0;
        // other rings never claim
        if (claimRing(c, "Ring of Fire Resistance", 1)) ++bad;
        // bundles never claim
        if (claimRing(c, "Ring of Protection", 2)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.hp = 10;
        // scroll-study pick: the lowest-level unknown MU spell,
        // deterministic id order
        c.classIndex = 1;
        c.knownSpells.clear();
        int sid = pickStudySpell(c);
        if (sid < 0) ++bad;
        const spells::SpellDef& s0 =
            spells::spell((spells::SpellId)sid);
        if (s0.sclass != spells::SPELL_MU || s0.level != 1) ++bad;
        c.knownSpells.push_back(sid);
        int sid2 = pickStudySpell(c);
        if (sid2 == sid) ++bad;   // moves on to the next unknown
        // a complete book yields -1
        for (int id = 0; id < spells::SPELL_COUNT; ++id)
            if (spells::spell((spells::SpellId)id).sclass ==
                spells::SPELL_MU)
                c.knownSpells.push_back(id);
        if (pickStudySpell(c) != -1) ++bad;
        // fire shield reflect math: half, rounded up, min 1
        if (fireShieldDamage(1) != 1) ++bad;
        if (fireShieldDamage(5) != 3) ++bad;
        if (fireShieldDamage(8) != 4) ++bad;
        printf("R81 rings/scrolls/status audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }'''),
], marker='R81 rings/scrolls/status audit')

print('; '.join(report))
