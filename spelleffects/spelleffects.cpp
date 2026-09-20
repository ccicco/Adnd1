// ============================================================================
// Adnd1 — spelleffects/spelleffects.cpp
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
    int target = rules::saveTarget(t.saveClass, t.saveLevel,
                                   (rules::SaveCategory)s.saveCategory);
    return rules::attemptSave(dice, target, t.saveBonus);
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

    for (const TargetDesc& t : targets) {
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
                r = resolveDamageSpell(dice, s, casterLevel, t);
                break;

            // ---- healing ----------------------------------------------------
            case spells::CL_CURE_LIGHT_WOUNDS:
            case spells::CL_CURE_SERIOUS_WOUNDS:
                r = resolveHealingSpell(dice, s, casterLevel, t);
                break;

            // ---- damage (cleric reversible) --------------------------------
            case spells::CL_CAUSE_LIGHT_WOUNDS:
            case spells::CL_CAUSE_SERIOUS_WOUNDS:
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
            case spells::MU_CHARM_PERSON:
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
            case spells::CL_HOLD_PERSON:
                r = resolveStatusSpell(dice, s, STATUS_HELD,
                                       s.durationRounds, t, false);
                break;
            case spells::CL_SILENCE_15:
                r = resolveStatusSpell(dice, s, STATUS_SILENCED,
                                       s.durationRounds, t, false);
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