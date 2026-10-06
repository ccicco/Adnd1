// ============================================================================
// Adnd1 - spelleffects/spelleffects.cpp
// Resolution dispatch by spell and target type.
// ============================================================================

#include "spelleffects.h"

#include <cstdio>
#include <cstring>

namespace spelleffects {

static const char* const kStatusNames[STATUS_COUNT] = {
    "None", "Asleep", "Charmed", "Hasted", "Slowed",
    "Silenced", "Held", "Invisible", "Protected", "Shielded"
};

const char* statusName(StatusKind s) {
    return kStatusNames[s < 0 || s >= STATUS_COUNT ? 0 : s];
}

// ----------------------------------------------------------------------------
// Damage / healing rolls
// ----------------------------------------------------------------------------

int rollDamage(Dice& dice, const spells::SpellDef& s, int casterLevel) {
    if (s.dmgSides <= 0) return 0;
    int diceCount = s.dmgCount * casterLevel;
    if (diceCount > 10) diceCount = 10;   // PHB cap (fireball etc.)
    return (int)dice.roll((uint32_t)diceCount, (uint32_t)s.dmgSides, 0);
}

int rollHealing(Dice& dice, const spells::SpellDef& s, int casterLevel) {
    if (s.dmgSides <= 0) return 0;
    int diceCount = s.dmgCount + (casterLevel - 1) / 2;   // +1/2 lvls
    if (diceCount > 8) diceCount = 8;
    return (int)dice.roll((uint32_t)diceCount, (uint32_t)s.dmgSides, 0);
}

bool tickStatus(StatusEffect& st) {
    if (st.kind == STATUS_NONE) return false;
    if (st.roundsRemaining == 0) {
        st.kind = STATUS_NONE;      // permanent until dispelled: stays
        return true;
    }
    --st.roundsRemaining;
    if (st.roundsRemaining <= 0) {
        st.kind = STATUS_NONE;
        return false;
    }
    return true;
}

// ----------------------------------------------------------------------------
// Save helper: attempts the spell's save category for a target.
// ----------------------------------------------------------------------------

static bool trySave(Dice& dice, const spells::SpellDef& s,
                    const TargetDesc& t) {
    if (s.saveCategory < 0) return false;   // no save allowed
    // R147: matrix II.D halves the non-intelligent save
    // level (except death/poison); the dwarf CON bonus
    // (PHB p.16) eases wands, spells and death-poison
    // saves.
    int lvl = effectiveSaveLevel(t.saveLevel,
                                 t.saveNonIntelligent,
                                 s.saveCategory);
    int target = rules::saveTarget(t.saveClass, lvl,
                                   (rules::SaveCategory)s.saveCategory);
    // R155: matrix II.C - a classed monster saves on its most
    // favorable matrix; saveBonus carries the monster die bonus
    // (displacer beast +2).
    if (t.saveAsMask)
        target = rules::mostFavorableSaveTarget(
            t.saveAsMask, t.saveAsLevels, t.saveClass, lvl,
            (rules::SaveCategory)s.saveCategory);
    int bonus = t.saveBonus;
    if (s.saveCategory == rules::SAVE_WANDS ||
        s.saveCategory == rules::SAVE_SPELLS ||
        s.saveCategory == rules::SAVE_DEATH_POISON)
        bonus += t.saveDwarfBonus;
    return rules::attemptSave(dice, target, bonus);
}

// ----------------------------------------------------------------------------
// Core resolution
// ----------------------------------------------------------------------------

static TargetResult resolveDamageSpell(Dice& dice, const spells::SpellDef& s,
                                       int casterLevel,
                                       const TargetDesc& t) {
    TargetResult r;
    r.affected = true;
    int dmg = rollDamage(dice, s, casterLevel);
    r.saveMade = trySave(dice, s, t);
    if (r.saveMade) dmg /= 2;   // save for half
    r.damage = dmg;
    snprintf(r.note, sizeof r.note, "%s: %d damage%s",
             s.name, dmg, r.saveMade ? " (saved for half)" : "");
    return r;
}

static TargetResult resolveHealingSpell(Dice& dice, const spells::SpellDef& s,
                                        int casterLevel,
                                        const TargetDesc& t) {
    TargetResult r;
    r.affected = true;
    int heal = rollHealing(dice, s, casterLevel);
    r.damage = -heal;   // convention: negative damage = healing
    snprintf(r.note, sizeof r.note, "%s: %d healed", s.name, heal);
    return r;
}

static TargetResult resolveStatusSpell(Dice& dice, const spells::SpellDef& s,
                                       StatusKind kind, int rounds,
                                       const TargetDesc& t,
                                       bool charmRules) {
    TargetResult r;
    r.affected = true;

    // charm person: humanoids only, not undead
    if (charmRules && t.isUndead) {
        snprintf(r.note, sizeof r.note, "%s: no effect (undead)",
                 s.name);
        return r;
    }

    r.saveMade = trySave(dice, s, t);
    if (r.saveMade) {
        snprintf(r.note, sizeof r.note, "%s: saved", s.name);
        return r;
    }
    r.status.kind = kind;
    r.status.roundsRemaining = s.durationRounds > 0 ? s.durationRounds : 0;
    snprintf(r.note, sizeof r.note, "%s: %s", s.name, statusName(kind));
    return r;
}

SpellCastResult resolveSpell(Dice& dice, spells::SpellId id,
                             int casterLevel,
                             const std::vector<TargetDesc>& targets) {
    SpellCastResult out;
    const spells::SpellDef& s = spells::spell(id);

    // R82: Death Spell HD budget - kills up to 4 x caster level
    // hit dice of creatures, spent in target order
    int deathBudget = (id == spells::MU_DEATH_SPELL)
                          ? deathSpellBudget(casterLevel) : 0;

    for (TargetDesc t : targets) {
        // R227: t is now a per-target copy:
        // the Wisdom Table I magical defense
        // adjustment (mental-form spells
        // only; the WIS rides the descriptor)
        // folds into saveBonus here - the
        // field the TargetDesc comment
        // reserves for it - so trySave pays
        // it with every other caller-side
        // modifier. The gate reads the spell
        // id (charm person and charm monster
        // are the registry mental forms
        // today).
        t.saveBonus += spells::spellSaveModWis(id, t.saveWis);
        TargetResult r;

        // magic resistance first (R6): blocks everything
        if (t.magicResistPct > 0 &&
            rules::magicResistanceBlocks(dice, t.magicResistPct)) {
            r.affected = true;
            r.resisted = true;
            snprintf(r.note, sizeof r.note, "%s: resisted", s.name);
            out.perTarget.push_back(r);
            continue;
        }

        switch (id) {
            // ---- damage -----------------------------------------------------
            case spells::MU_FIREBALL:
            case spells::MU_LIGHTNING_BOLT:
            case spells::MU_ICE_STORM:      // R80
            case spells::MU_CONE_OF_COLD:   // R80
                r = resolveDamageSpell(dice, s, casterLevel, t);
                break;

            // ---- healing ----------------------------------------------------
            case spells::CL_CURE_LIGHT_WOUNDS:
            case spells::CL_CURE_SERIOUS_WOUNDS:
            case spells::CL_CURE_CRITICAL_WOUNDS:   // R80
            case spells::CL_HEAL:                   // R80
                r = resolveHealingSpell(dice, s, casterLevel, t);
                break;

            // ---- damage (cleric reversible) --------------------------------
            case spells::CL_CAUSE_LIGHT_WOUNDS:
            case spells::CL_CAUSE_SERIOUS_WOUNDS:
            case spells::CL_CAUSE_CRITICAL_WOUNDS:  // R80
                r = resolveDamageSpell(dice, s, casterLevel, t);
                break;

            // ---- statuses ---------------------------------------------------
            case spells::MU_SLEEP: {
                // sleep: no save, 2d4 HD of creatures; per-target here:
                // level/HD <= 4 affected (2+ HD save vs large). No save
                // for 1e sleep; resisted only by MR (checked above) and
                // undead are immune.
                r.affected = true;
                if (t.isUndead) {
                    snprintf(r.note, sizeof r.note, "Sleep: no effect");
                } else {
                    r.status.kind = STATUS_SLEEP;
                    r.status.roundsRemaining = 0;   // sleep: sleepers wake on damage
                    snprintf(r.note, sizeof r.note, "Sleep: asleep");
                }
                break;
            }
            case spells::MU_DISINTEGRATE: {   // R82
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
            case spells::MU_FIRE_SHIELD:   // R81
                r = resolveStatusSpell(dice, s, STATUS_FIRESHIELD,
                                       s.durationRounds, t, false);
                break;
            case spells::MU_CHARM_PERSON:
            case spells::MU_CHARM_MONSTER:   // R80
                r = resolveStatusSpell(dice, s, STATUS_CHARMED, 0, t, true);
                break;
            case spells::MU_SHIELD:
                r = resolveStatusSpell(dice, s, STATUS_SHIELDED,
                                       s.durationRounds, t, false);
                if (!r.saveMade && r.status.kind == STATUS_SHIELDED)
                    r.status.magnitude = 1;   // shield: AC -... handled by combat
                break;
            case spells::MU_INVISIBILITY:
            case spells::MU_INVISIBILITY_10:
                r = resolveStatusSpell(dice, s, STATUS_INVISIBLE,
                                       0, t, false);   // until attacked
                break;
            case spells::MU_HASTE:
                r = resolveStatusSpell(dice, s, STATUS_HASTED,
                                       s.durationRounds, t, false);
                break;
            case spells::MU_WEB:
                r = resolveStatusSpell(dice, s, STATUS_HELD,
                                       s.durationRounds, t, false);
                break;
            case spells::MU_HOLD_MONSTER:   // R80
            case spells::CL_HOLD_PERSON:
                r = resolveStatusSpell(dice, s, STATUS_HELD,
                                       s.durationRounds, t, false);
                break;
            case spells::CL_SILENCE_15:
                r = resolveStatusSpell(dice, s, STATUS_SILENCED,
                                       s.durationRounds, t, false);
                break;
            case spells::CL_SLOW_POISON:        // R81
            case spells::CL_NEUTRALIZE_POISON:   // R81
                r = resolveStatusSpell(dice, s, STATUS_ANTIVENOM,
                                       s.durationRounds, t, false);
                if (!r.saveMade && r.status.kind ==
                        spelleffects::STATUS_ANTIVENOM)
                    r.status.magnitude = 4;   // +4 on poison saves
                break;
            case spells::CL_PROTECTION_FROM_EVIL:
                r = resolveStatusSpell(dice, s, STATUS_PROT_EVIL,
                                       s.durationRounds, t, false);
                break;

            // ---- everything else: utility, no per-target effect yet ------
            default:
                r.affected = true;
                snprintf(r.note, sizeof r.note, "%s: cast", s.name);
                break;
        }

        out.perTarget.push_back(r);
    }
    return out;
}

} // namespace spelleffects