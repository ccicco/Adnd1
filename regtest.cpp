#include "monsters/MonsterRegistry.h"
#include "dm/encounters.h"
#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates
#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
#include "dm/appendixp.h"  // R147: pp.225-226 Appendix P tables
#include "dm/appendixi.h"  // R150: pp.217-220 Appendix I dressing
#include "dm/appendixo.h"  // R151: p.225 Appendix O item weights
#include "dm/dungeon.h"    // R124: generator smoke in the audit
#include "game/party.h"
#include "rules/combat.h"
#include "rules/saves.h"
#include "spells/spells.h"
#include "abilities/abilities.h"
#include "rules/races.h"   // R154: pp.15-18 Race Tables I-III
#include "rules/grenade.h"  // R157: pp.64-65 grenade-like missiles
#include "rules/weaponspeed.h"  // R158: p.66 weapon speed factors
#include "rules/subdue.h"  // R159: p.67 striking to subdue
#include "rules/weaponless.h"  // R160: pp.72-73 weaponless combat
#include "rules/twoweapon.h"  // R161: p.70 attacks with two weapons
#include "rules/poison.h"  // R163: p.20 the poison table
#include "rules/assassinate.h"  // R164: p.75 the assassination table
#include "rules/miscibility.h"  // R165: p.119 potion miscibility
#include "rules/insanity.h"  // R166: pp.82-83 intoxication and insanity
#include "rules/disease.h"  // R167: pp.13-14 disease and parasitic infestation
#include "rules/uwspells.h"  // R168: p.57 underwater spell use
#include "rules/humrpref.h"  // R169: p.106 humanoid racial preferences
#include "rules/followers.h"  // R170: pp.16-18 followers by class
#include <cstdio>
#include <string>

// R126: does the band list carry this exact (key, lo, hi)
// pin? - the wilderness line-diff audit's spot-check helper
static bool bandHas(const std::vector<dm::OutdoorBand>& b,
                    const char* k, int lo, int hi) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi) return true;
    return false;
}

// R127: the waterborne spot-check helper - exact key, band,
// and footnote-gate flags (1 = cool only, 2 = warm only,
// 4 = deep only)
static bool waterBandHas(const std::vector<dm::WaterborneBand>& b,
                         const char* k, int lo, int hi, int fl) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi
            && x.flags == fl) return true;
    return false;
}

int main() {
    monsters::MonsterRegistry reg;

    // R71fix: the 408 monster lua files live in letter subdirectories
    // (monsters/monsters/a/aarakocra.lua, ...), but loadDirectory() reads
    // only one flat directory level. Load every letter dir and total the
    // counts; a missing/empty dir contributes 0 (loadDirectory returns
    // -1 only if the directory itself cannot be opened, so ignore -1).
    int n = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string dir = "monsters/monsters/";
        dir.push_back(c);
        int m = reg.loadDirectory(dir);
        if (m > 0) n += m;
    }
    printf("loaded %d, errors %zu\n", n, reg.errors().size());
    for (auto& e : reg.errors()) printf("ERR: %s\n", e.c_str());
    for (const char* k : {"wight", "purple_worm", "ankheg", "goblin"}) {
        auto* d = reg.find(k);
        if (d) printf("%-12s AC%3d HD %.1f atk %d dmg 1d%d xp %d und %d\n",
            k, d->armorClass, d->hitDice, d->attacks, d->damageSides,
            d->xpValue, (int)d->undead);
    }

    // ---- R73: XP sanity audit over the full bestiary ------------------
    // merged_mm1 entries carry cross-checked book XP (R49); anything
    // with a non-positive xp there, or a negative xpPerHp, or an
    // unrecognized xpSource, is an anomaly worth eyeballing.
    {
        int anom = 0, checked = 0;
        for (const auto& kv : reg.all()) {
            const auto& d = kv.second;
            ++checked;
            bool bad = false;
            if (d.xpSource == "merged_mm1" && d.xpValue <= 0) bad = true;
            if (d.xpPerHp < 0) bad = true;
            if (d.xpSource != "merged_mm1" && d.xpSource != "perm_x10" &&
                d.xpSource != "role_variant" && d.xpSource != "by_hit_dice" &&
                d.xpSource != "age_bracket" && d.xpSource != "by_head_count" &&
                d.xpSource != "by_level") bad = true;
            if (bad && anom < 10) {
                printf("ANOM: %-24s xpSource=%s xpValue=%d xpPerHp=%d\n",
                       kv.first.c_str(), d.xpSource.c_str(),
                       d.xpValue, d.xpPerHp);
            }
            if (bad) ++anom;
        }
        printf("xp audit: %d defs checked, %d anomalies\n", checked, anom);
    }

    // ---- R74: encounter generator smoke test --------------------------
    // Deterministic + statistical checks over rollEncounter():
    //   - every pick resolves to a loaded def
    //   - count within [min,max] unless clamped to the cap
    //   - lairPct==0 monsters never generate a lair
    //   - unique monsters excluded unless allowed
    {
        rules::Rng rng(12345);
        rules::Dice dice(rng);
        dm::encounters::EncounterOptions opt;
        int n = 2000, bad = 0, lairs = 0, clamped = 0;
        for (int i = 0; i < n; ++i) {
            dm::encounters::Encounter e;
            if (!dm::encounters::rollEncounter(reg, dice, opt, e)) {
                ++bad; continue;
            }
            if (!e.def) { ++bad; continue; }
            int lo = e.def->noAppearingMin, hi = e.def->noAppearingMax;
            if (hi < lo) hi = lo;
            if (lo == 0 && hi == 0) {   // R75b: no data - count forced 1
                if (e.count != 1) ++bad;
            } else if (!e.clamped && (e.count < lo || e.count > hi)) ++bad;
            if (e.count < 1 || e.count > opt.countCap) ++bad;
            if (e.clamped && e.rawCount <= opt.countCap) ++bad;
            if (e.inLair && e.def->lairPct <= 0) ++bad;
            if (e.def->frequency == "unique" || e.def->xpSource == "perm_x10")
                ++bad;
            if (e.inLair) ++lairs;
            if (e.clamped) ++clamped;
        }
        // statistical: with 2000 rolls and the full bestiary, some
        // lairs and clamped counts (goblin "40-400") must have appeared
        if (lairs == 0 || clamped == 0) ++bad;
        printf("encounter smoke: %d rolls, %d bad, %d lairs, %d clamped\n",
               n, bad, lairs, clamped);
        // alignment-filter sanity: every pick matches the filter
        dm::encounters::EncounterOptions eo;
        eo.alignmentFilter = "chaotic";
        int fbad = 0;   // R75b: own counter - the smoke's `bad` leaked here
        for (int i = 0; i < 500; ++i) {
            dm::encounters::Encounter e;
            if (!dm::encounters::rollEncounter(reg, dice, eo, e) ||
                e.def->alignment.compare(0, 7, "chaotic") != 0) { ++fbad; break; }
        }
        printf("encounter filter: %s\n", fbad ? "FAIL" : "OK");
    }

    // ---- R75: specials audit + toActor copy check ----------------------
    // The bug: toActor() never copied def.specials onto the Actor, so
    // R18's resolveSpecial was dead code for every registry monster.
    {
        int withSp = 0, drain = 0, pois = 0, para = 0, breath = 0;
        for (const auto& kv : reg.all()) {
            if (kv.second.specials.empty()) continue;
            ++withSp;
            for (const auto& sp : kv.second.specials) {
                if (sp.type == monsters::SPECIAL_ENERGY_DRAIN) ++drain;
                if (sp.type == monsters::SPECIAL_POISON)       ++pois;
                if (sp.type == monsters::SPECIAL_PARALYSIS)    ++para;
                if (sp.type == monsters::SPECIAL_BREATH_WEAPON) ++breath;
            }
        }
        printf("specials census: %d monsters, drain %d poison %d "
               "paralysis %d breath %d\n",
               withSp, drain, pois, para, breath);
        // census must be non-degenerate: a 408-monster bestiary with
        // the keyword derivation MUST have found some of each class
        if (drain < 1 || pois < 5 || para < 1 || breath < 5) {
            printf("FAIL: specials census degenerate\n");
            return 1;
        }

        // toActor must copy specials (the R75 fix) - test the first
        // monster of each special type rather than hardcoded keys
        rules::Rng rng2(999);
        rules::Dice dice2(rng2);
        int bad = 0;
        const char* probe[4] = { nullptr, nullptr, nullptr, nullptr };
        for (const auto& kv : reg.all()) {
            for (const auto& sp : kv.second.specials) {
                int t = (int)sp.type;
                if (t >= 1 && t <= 4 && !probe[t - 1])
                    probe[t - 1] = kv.second.key.c_str();
            }
        }
        for (int t = 1; t <= 4; ++t) {
            if (!probe[t - 1]) {
                printf("FAIL: no monster with special type %d\n", t);
                return 1;
            }
            auto* d = reg.find(probe[t - 1]);
            ai::Actor a = reg.toActor(probe[t - 1], dice2);
            if (a.specials.size() != d->specials.size()) { ++bad; continue; }
            for (size_t i = 0; i < a.specials.size(); ++i)
                if (a.specials[i].type != (int)d->specials[i].type ||
                    a.specials[i].drainLevels != d->specials[i].drainLevels)
                    ++bad;
        }
        printf("toActor specials: %s\n", bad ? "FAIL" : "OK");
        if (bad) return 1;
    }

    // ---- R76: magic item category audit --------------------------------
    // Every rolled item carries its DMG III category; healing potions
    // are detectable by name+category; weapon plus parses from names.
    {
        rules::Rng rng3(777);
        rules::Dice dice3(rng3);
        int n = 20000, bad = 0, potions = 0, scrolls = 0, swords = 0,
            armor = 0, healing = 0;
        bool seenCat[12] = { false };
        for (int i = 0; i < n; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(dice3);
            if (m.category < 0 || m.category > 11) { ++bad; continue; }
            seenCat[m.category] = true;
            if (m.category == dm::treasure::MIC_POTION) {
                ++potions;
                // category contract: III.A rows are "Potion of ..." plus
                // the printed Oil (64-69) and Philter (70-75) bands
                if (m.name.compare(0, 9, "Potion of") != 0 &&
                    m.name.compare(0, 7, "Oil of ") != 0 &&
                    m.name.compare(0, 11, "Philter of ") != 0) ++bad;
                if (m.isHealingPotion()) {
                    ++healing;
                    if (m.name != "Potion of Healing" &&
                        m.name != "Potion of Extra-Healing") ++bad;
                }
            }
            if (m.category == dm::treasure::MIC_SCROLL) ++scrolls;
            if (m.category == dm::treasure::MIC_SWORD) {
                ++swords;
                if (m.name.compare(0, 5, "Sword") != 0) ++bad;
                // plus rows must parse to 1-5
                int plus = m.weaponPlus();
                if (plus > 5) ++bad;
            }
            if (m.category == dm::treasure::MIC_ARMOR) ++armor;
        }
        // statistical: 20000 rolls must hit every category, and the
        // potion band (20%) must include healing draughts
        for (int c = 0; c < 12; ++c)
            if (!seenCat[c]) ++bad;
        if (potions < 500 || scrolls < 300 || swords < 300 ||
            armor < 500 || healing < 30) ++bad;
        printf("magic item audit: %d rolls, bad %d, potions %d "
               "(healing %d), scrolls %d, swords %d, armor %d\n",
               n, bad, potions, healing, scrolls, swords, armor);

        // deterministic helper unit checks (own counter - the audit's
        // `bad` must not leak here, the R75b lesson twice over)
        int hbad = 0;
        dm::treasure::MagicItem u;
        u.category = dm::treasure::MIC_POTION;
        u.name = "Potion of Healing";        if (!u.isHealingPotion()) ++hbad;
        u.name = "Potion of Flying";        if (u.isHealingPotion()) ++hbad;
        u.name = "Potion of Extra-Healing"; if (!u.isHealingPotion()) ++hbad;
        u.category = dm::treasure::MIC_SWORD;   // category gates potions
        if (u.isHealingPotion()) ++hbad;
        u.name = "Sword +3, Frost Brand";
        if (u.weaponPlus() != 3) ++hbad;
        u.name = "Sword, Vorpal Weapon";
        if (u.weaponPlus() != 0) ++hbad;
        u.name = "Arrow +2";
        if (u.weaponPlus() != 2) ++hbad;
        u.name = "Cloak of Protection +4";
        if (u.weaponPlus() != 4) ++hbad;      // parse works anywhere
        printf("magic helpers: %s\n", hbad ? "FAIL" : "OK");
        if (bad || hbad) return 1;
    }

    // ---- R77: kind & curse classification audit -------------------------
    // kind() must agree with category+name; cursed rows must carry
    // the flag (claim layers skip them).
    {
        int kbad = 0;
        // deterministic units
        dm::treasure::MagicItem u;
        u.category = dm::treasure::MIC_SWORD;
        u.name = "Sword +3, Frost Brand";
        if (u.kind() != dm::treasure::MIK_SWORD) ++kbad;
        if (u.cursed()) ++kbad;
        u.category = dm::treasure::MIC_SCROLL;
        if (u.kind() != dm::treasure::MIK_SCROLL) ++kbad;
        u.category = dm::treasure::MIC_ARMOR;
        u.name = "Shield +2";
        if (u.kind() != dm::treasure::MIK_SHIELD) ++kbad;
        u.name = "Chain Mail +1";
        if (u.kind() != dm::treasure::MIK_ARMOR) ++kbad;
        u.category = dm::treasure::MIC_WEAPON;
        u.name = "Arrow +2";
        if (u.kind() != dm::treasure::MIK_AMMO) ++kbad;
        u.name = "Bow +1";
        if (u.kind() != dm::treasure::MIK_MISSILE) ++kbad;
        u.name = "Mace +2";
        if (u.kind() != dm::treasure::MIK_MELEE) ++kbad;
        u.name = "Sword +1, Cursed";
        if (!u.cursed()) ++kbad;               // curse detector
        u.category = dm::treasure::MIC_ARMOR;
        u.name = "Plate Mail of Vulnerability";
        if (!u.cursed()) ++kbad;
        u.name = "Shield -1, missile attractor";
        if (!u.cursed()) ++kbad;
        u.category = dm::treasure::MIC_WEAPON;
        u.name = "Spear, Cursed Backbiter";
        if (!u.cursed()) ++kbad;

        // statistical: rolled items agree with category constraints
        rules::Rng rng4(4242);
        rules::Dice dice4(rng4);
        int n = 20000, swords = 0, shields = 0, armor = 0,
            melee = 0, missile = 0, ammo = 0, cursed = 0;
        for (int i = 0; i < n; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(dice4);
            switch (m.kind()) {
            case dm::treasure::MIK_SWORD:
                ++swords;
                if (m.category != dm::treasure::MIC_SWORD) ++kbad;
                break;
            case dm::treasure::MIK_SHIELD:
                ++shields;
                if (m.category != dm::treasure::MIC_ARMOR ||
                    m.name.find("Shield") == std::string::npos)
                    ++kbad;
                break;
            case dm::treasure::MIK_ARMOR:
                ++armor;
                if (m.category != dm::treasure::MIC_ARMOR) ++kbad;
                break;
            case dm::treasure::MIK_MELEE:
                ++melee;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            case dm::treasure::MIK_MISSILE:
                ++missile;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            case dm::treasure::MIK_AMMO:
                ++ammo;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            default:
                break;
            }
            if (m.cursed()) {
                ++cursed;
                // curse words must actually appear (no false positives)
                if (m.name.find("Cursed") == std::string::npos &&
                    m.name.find("Vulnerability") == std::string::npos &&
                    m.name.find("attractor") == std::string::npos &&
                    m.name.find("Backbiter") == std::string::npos)
                    ++kbad;
            }
        }
        // every claimable band must occur across 20000 rolls
        if (swords < 200 || shields < 100 || armor < 200 ||
            melee < 100 || missile < 20 || ammo < 40 || cursed < 10)
            ++kbad;
        printf("kind audit: %d rolls, bad %d, swords %d, shields %d, "
               "armor %d, melee %d, missile %d, ammo %d, cursed %d\n",
               n, kbad, swords, shields, armor, melee, missile,
               ammo, cursed);
        if (kbad) return 1;
    }

    // ---- R79: ammo bundle claims + carried caps -----------------------
    {
        int bad = 0;
        Character c;
        c.name = "Rolf";
        c.hp = 10;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.missileAmmo = 4;
        // enchanted arrows fit the bow
        if (!claimAmmoBundle(c, "Arrow +2", 12)) ++bad;
        if (c.missileAmmo != 16) ++bad;
        // bolts do not fit a bow
        if (claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // a crossbow takes bolts
        c.rangedWeapon.id = items::WPN_CROSSBOW_LIGHT;
        if (!claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // the singular specials never claim
        if (claimAmmoBundle(c, "Arrow of Slaying", 1)) ++bad;
        if (claimAmmoBundle(c, "Arrow of Direction", 1)) ++bad;
        // a long bow takes arrows too
        c.rangedWeapon.id = items::WPN_LONG_BOW;
        if (!claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        c.hp = 10;
        // quiver cap: the bundle still pockets (true), the count
        // just stops at the cap
        c.quiver.clear();   // R80: bundle semantics
        c.missileAmmo = QUIVER_CAP;
        if (!claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        if (c.missileAmmo != QUIVER_CAP) ++bad;
        // carried-stack cap: clamps up, never down
        int stack = CARRIED_CAP - 4;
        addCapped(stack, 100, CARRIED_CAP);
        if (stack != CARRIED_CAP) ++bad;
        addCapped(stack, -50, CARRIED_CAP);
        if (stack != CARRIED_CAP - 50) ++bad;
        printf("R79 claim/caps audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R80: quiver bundle math --------------------------------------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // same-plus merge + tail-trim cap
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverAdd(c.quiver, 0, 2);      // merges into the 0-band
        if (quiverTotal(c.quiver) != 9) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        quiverAdd(c.quiver, 5, 1000);   // over the cap: tail trims
        if (quiverTotal(c.quiver) != QUIVER_CAP) ++bad;
        // front-first consumption: mundane before magic
        c.quiver.clear();
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverConsumeShots(c.quiver, 5);
        if (quiverTotal(c.quiver) != 2) ++bad;
        if (quiverNextPlus(c.quiver) != 2) ++bad;
        quiverConsumeShots(c.quiver, 99);   // drains
        if (quiverTotal(c.quiver) != 0) ++bad;
        // restock refills the mundane band only
        quiverRestock(c.quiver, 20);
        if (quiverTotal(c.quiver) != 20) ++bad;
        quiverAdd(c.quiver, 2, 3);
        quiverRestock(c.quiver, 20);   // leaves the +2 band alone
        if (quiverTotal(c.quiver) != 23) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        printf("R80 quiver audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R80: spell table L4-6 -----------------------------------------
    {
        int bad = 0, mu = 0, cl = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            // R129: the band widens to 1-9 - the p.14
            // caster-aging spells ride as levels 7-9
            if (s.level < 1 || s.level > 9) ++bad;
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu; else ++cl;
            if (s.level >= 4 && s.level <= 6) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }
        if (l46 < 12) ++bad;   // the R80 roster landed
        printf("R80 spells audit: %d spells (MU %d, CL %d), "
               "L4-6 %d, bad %d\n",
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
        if (spelleffects::fireShieldDamage(1) != 1) ++bad;
        if (spelleffects::fireShieldDamage(5) != 3) ++bad;
        if (spelleffects::fireShieldDamage(8) != 4) ++bad;
        printf("R81 rings/scrolls/status audit: bad %d\n", bad);
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
            if (sv < 30 || sv > 100) ++bad;
        }
        printf("R82 death/revival audit: bad %d\n", bad);
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
        // every registry row sits in 1..9 (the R83 gate
        // domain, widened R129 alongside the R80 band: the
        // six p.14 caster-aging spells ride as levels 7-9)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 9) ++bad;
        }
        printf("R83 teleport audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R85: the pack audit ----
    {
        int bad = 0;
        // packAdd honors the cap
        Character c;
        c.hp = 10;
        PackItem p0{};
        p0.kind = 0;
        p0.id = (int)items::WPN_LONG_SWORD;
        p0.plus = 1;
        p0.gp = 100;
        int added = 0;
        while (packAdd(c, p0) && added < 99) ++added;
        if (added != PACK_CAP) ++bad;
        if (packAdd(c, p0)) ++bad;   // full pack refuses
        // names reconstruct from the tables
        PackItem w{};
        w.kind = 0;
        w.id = (int)items::WPN_LONG_SWORD;
        w.plus = 2;
        w.gp = 500;
        if (packItemName(w) != "Long Sword +2") ++bad;
        PackItem a{};
        a.kind = 1;
        a.id = (int)items::ARMOR_CHAIN_MAIL;
        a.plus = 0;
        a.gp = 75;
        if (packItemName(a) != "Chain Mail") ++bad;
        PackItem s{};
        s.kind = 2;
        s.id = 0;
        s.plus = 1;
        s.gp = 50;
        if (packItemName(s) != "Shield +1") ++bad;
        PackItem sb{};
        sb.kind = 2;
        sb.id = 0;
        sb.plus = 0;
        sb.gp = 10;
        if (packItemName(sb) != "Shield") ++bad;
        // improves routing
        c.pack.clear();
        c.weapon.id = items::WPN_LONG_SWORD;
        c.weapon.plus = 0;
        if (!packImproves(c, w)) ++bad;   // +2 over mundane
        c.weapon.plus = 2;
        if (packImproves(c, w)) ++bad;    // equal plus: no swap
        c.shield = false;
        c.shieldPlus = 0;
        if (!packImproves(c, s)) ++bad;   // no shield: wear it
        c.shield = true;
        c.shieldPlus = 3;
        if (packImproves(c, s)) ++bad;    // worse plus: no
        // armor routing via effectiveAc
        c.armor.id = items::ARMOR_LEATHER;
        c.armor.plus = 0;
        PackItem a2{};
        a2.kind = 1;
        a2.id = (int)items::ARMOR_CHAIN_MAIL;
        a2.plus = 0;
        a2.gp = 75;
        if (!packImproves(c, a2)) ++bad;  // chain beats leather
        c.armor.id = items::ARMOR_PLATE;
        if (packImproves(c, a2)) ++bad;   // plate wins: no
        // ranged routing: missile weapons look at the RANGED slot
        PackItem b{};
        b.kind = 0;
        b.id = (int)items::WPN_SHORT_BOW;
        b.plus = 1;
        b.gp = 100;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.rangedWeapon.plus = 0;
        c.weapon.plus = 5;   // melee far better - must not matter
        if (!packImproves(c, b)) ++bad;
        c.rangedWeapon.plus = 3;
        if (packImproves(c, b)) ++bad;
        // dead members never improve
        c.hp = 0;
        if (packImproves(c, w)) ++bad;
        printf("R85 pack audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R86: cursed/hire audit ----
    {
        int bad = 0;
        // the cursed-name routing the claim guard depends on:
        // cursed items never reach the gear cases, so they can
        // never become pack cargo (the carry invariant)
        {
            dm::treasure::MagicItem mi;
            mi.name = "Sword +1, Cursed";
            if (!mi.cursed()) ++bad;
            mi.name = "Shield -1, Vulnerability";
            if (!mi.cursed()) ++bad;
            mi.name = "Hematite attractor of Armor";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword -2, Backbiter";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword +2, Frost Brand";
            if (mi.cursed()) ++bad;
            mi.name = "Chain Mail +2";
            if (mi.cursed()) ++bad;
        }
        // defense in depth: a negative-plus item never improves
        // a kit even if some future path offered it as cargo
        {
            Character c;
            c.hp = 10;
            c.weapon.id = items::WPN_LONG_SWORD;
            c.weapon.plus = 0;
            PackItem cw{};
            cw.kind = 0;
            cw.id = (int)items::WPN_LONG_SWORD;
            cw.plus = -1;
            cw.gp = 300;
            if (packImproves(c, cw)) ++bad;
            // any shield beats none (even a cursed one would),
            // so wear a mundane shield first: -1 must lose
            c.shield = true;
            c.shieldPlus = 0;
            PackItem cs{};
            cs.kind = 2;
            cs.plus = -1;
            cs.gp = 50;
            if (packImproves(c, cs)) ++bad;
        }
        printf("R86 cursed/hire audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R87: burden audit ----
    {
        int bad = 0;
        // item weights come from the tables (gp units)
        PackItem w1{};
        w1.kind = 0;
        w1.id = (int)items::WPN_LONG_SWORD;
        if (packItemWeight(w1) != 75) ++bad;    // PHB p.37
        PackItem a1{};
        a1.kind = 1;
        a1.id = (int)items::ARMOR_PLATE;
        if (packItemWeight(a1) != 450) ++bad;   // PHB p.36
        PackItem s1{};
        s1.kind = 2;
        if (packItemWeight(s1) != 100) ++bad;
        PackItem badId{};
        badId.kind = 0;
        badId.id = 999;
        if (packItemWeight(badId) != 0) ++bad;  // out of range
        // band + movement sanity (STR 10 scale = 350/700/1050)
        if (items::encumbranceBand(0, 10) !=
            items::ENC_UNENCUMBERED) ++bad;
        if (items::encumbranceBand(700, 10) != items::ENC_LIGHT)
            ++bad;
        if (items::encumbranceBand(1050, 10) !=
            items::ENC_MODERATE) ++bad;
        if (items::encumbranceBand(1051, 10) !=
            items::ENC_HEAVY) ++bad;
        if (items::movementForBand(items::ENC_UNENCUMBERED) != 120)
            ++bad;
        if (items::movementForBand(items::ENC_HEAVY) != 30) ++bad;
        // STR 18 scales the bands up (heavy 1050 -> 1890)
        if (items::encumbranceBand(1890, 18) !=
            items::ENC_MODERATE) ++bad;
        // the packAdd encumbrance gate: a STR 10 member in
        // plate kit (dagger 20 + plate 450 = 470 worn) can
        // carry ONE spare plate (920, moderate) - the second
        // would go heavy (1370 > 1050) and is refused
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_PLATE;
            if (carriedWeight(c) != 470) ++bad;
            if (!packAdd(c, a1)) ++bad;    // 920: moderate, ok
            if (packAdd(c, a1)) ++bad;     // 1370: heavy, no
            if (c.pack.size() != 1) ++bad;
        }
        // STR 18 shoulders more before the gate trips
        {
            Character c;
            c.hp = 10;
            c.abilities.str = 18;
            c.armor.id = items::ARMOR_PLATE;
            if (!packAdd(c, a1)) ++bad;    // 920
            if (!packAdd(c, a1)) ++bad;    // 1370
            if (!packAdd(c, a1)) ++bad;    // 1820 <= 1890
            if (packAdd(c, a1)) ++bad;     // 2270: heavy, no
            if (c.pack.size() != 3) ++bad;
        }
        // the R85 cap still binds first for mundane loot
        {
            Character c;
            c.hp = 10;
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            int added = 0;
            while (packAdd(c, sw) && added < 99) ++added;
            if (added != PACK_CAP) ++bad;  // 470 gp: cap, not wt
        }
        // the hire's load: sword 75 + plate 450 + shield 100
        // = 625 worn; STR 12 heavy threshold is 1260
        {
            Party p;
            p.henchmanPresent = true;
            p.henchmanPlate = true;   // plate kit (R46 ladder top)
            if (henchmanCarryWeight(p) != 625) ++bad;
            if (!henchmanCanShoulder(p, a1)) ++bad;   // 1075
            p.henchmanPack.push_back(a1);
            if (henchmanCanShoulder(p, a1)) ++bad;    // 1525
        }
        printf("R87 burden audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R88: warning audit ----
    {
        int bad = 0;
        // the company moves at the slowest living member's
        // band; dead members and empty packs do not slow it
        {
            Party p;
            // default kit: dagger + no armor = 20 gp
            if (partyMoveRate(p) != 120) ++bad;   // nobody: base
            Character a;
            a.hp = 10;                            // STR 10, kit
            if (carriedWeight(a) != 20) ++bad;
            p.members.push_back(a);
            int wa = carriedWeight(a);
            int ma = partyMoveRate(p);
            if (ma != items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
            // a HEAVY companion drags the whole company to 30
            Character h;
            h.hp = 10;
            h.abilities.str = 10;
            h.armor.id = items::ARMOR_PLATE;      // 470 worn
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            if (!packAdd(h, a1)) ++bad;            // 920: moderate
            if (packAdd(h, a1)) ++bad;             // 1370: refused
            // push the weight over heavy via direct pack
            // push (bypasses the R87 gate on purpose)
            PackItem big{};
            big.kind = 1;
            big.id = (int)items::ARMOR_PLATE;
            h.pack.push_back(big);                // 1370: heavy
            if (items::encumbranceBand(carriedWeight(h), 10) !=
                items::ENC_HEAVY) ++bad;
            p.members.push_back(h);
            if (partyMoveRate(p) != 30) ++bad;
            // the dead do not slow the company
            Character d;
            d.hp = 0;
            d.armor.id = items::ARMOR_PLATE;
            PackItem many{};
            many.kind = 1;
            many.id = (int)items::ARMOR_PLATE;
            for (int i = 0; i < 6; ++i) d.pack.push_back(many);
            p.members.push_back(d);
            if (partyMoveRate(p) != 30) ++bad;    // h still slow
            p.members.pop_back();
            p.members.pop_back();                 // drop h
            if (partyMoveRate(p) !=
                items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
        }
        // the [E] swap weight pin: equipping plate from the
        // pack CONSERVES carriedWeight (the old leather kit
        // returns to the pack as the keepsake) - the swap
        // can never create a HEAVY load by itself; the [E]
        // warning is a state echo, not a cause
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_LEATHER;
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            c.pack.push_back(a1);
            int before = carriedWeight(c);        // 20+150+450
            if (before != 620) ++bad;
            // simulate the townSwapGear armor branch
            PackItem old{};
            old.kind = 1;
            old.id = (int)c.armor.id;
            old.plus = c.armor.plus;
            c.armor.id = (items::ArmorId)a1.id;
            c.armor.plus = a1.plus;
            c.pack[0] = old;
            int after = carriedWeight(c);
            if (after != before) ++bad;            // conserved
        }
        printf("R88 warning audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R89: pace audit ----
    {
        int bad = 0;
        // the coin share: 10 coins per gp unit, split across
        // the living only
        {
            Party p;
            if (coinWeightShare(p) != 0) ++bad;   // no gold
            p.gold = 4000;
            if (coinWeightShare(p) != 0) ++bad;   // nobody living
            Character a, b2, c2, d2;
            a.hp = 10; b2.hp = 10; c2.hp = 10; d2.hp = 10;
            p.members.push_back(a);
            p.members.push_back(b2);
            p.members.push_back(c2);
            p.members.push_back(d2);
            if (coinWeightShare(p) != 100) ++bad;  // 4000/10/4
            p.members[3].hp = 0;                   // the dead
            if (coinWeightShare(p) != 133) ++bad;  // 4000/10/3
            p.gold = 4999;                         // floor
            if (coinWeightShare(p) != 166) ++bad;  // 4999/30
        }
        // the true load: kit + cargo + coin share
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            // default kit: dagger 20 gp
            if (memberLoad(p, c) != 20) ++bad;
            p.gold = 1000;
            if (memberLoad(p, c) != 120) ++bad;    // +100 coin
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            c.pack.push_back(sw);
            if (memberLoad(p, c) != 195) ++bad;    // +75 cargo
        }
        // the pace cost: 120'->10, 90'->13, 60'->20, 30'->40
        if (paceStepTenths(120) != 10) ++bad;
        if (paceStepTenths(90)  != 13) ++bad;
        if (paceStepTenths(60)  != 20) ++bad;
        if (paceStepTenths(30)  != 40) ++bad;
        // coins slow the company: a lone STR 10 member hauling
        // 20,000 gp carries 2000 wt -> HEAVY -> 30' -> four
        // wander bites per step
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            if (partyMoveRate(p) != 120) ++bad;
            p.gold = 20000;
            if (partyMoveRate(p) != 30) ++bad;
            if (paceStepTenths(partyMoveRate(p)) != 40) ++bad;
            // spending it all in town is instant relief
            p.gold = 0;
            if (partyMoveRate(p) != 120) ++bad;
        }
        printf("R89 pace audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R90: clock audit ----
    {
        int bad = 0;
        // the camp costs: 48 turns complete, 4 interrupted
        if (restTurns(false) != 48) ++bad;
        if (restTurns(true)  != 4)  ++bad;
        // the tick math: a 90' company (13 tenths/step) ticks
        // late but never loses time - 10 steps = 13 turns
        {
            int debt = 0;
            int ticks = 0;
            for (int i = 0; i < 10; ++i)
                ticks += ticksFromDebt(debt, 13);
            if (ticks != 13 || debt != 0) ++bad;
        }
        // a 30' company (40 tenths) ticks 4 per step, no debt
        {
            int debt = 0;
            if (ticksFromDebt(debt, 40) != 4) ++bad;
            if (debt != 0) ++bad;
        }
        // a 120' company (10 tenths) ticks exactly 1 per step
        {
            int debt = 0;
            for (int i = 0; i < 100; ++i) {
                if (ticksFromDebt(debt, 10) != 1) ++bad;
                if (debt != 0) ++bad;
            }
        }
        // the debt never leaks across an odd pace change:
        // 3 steps at 13 -> 3 ticks, debt 9; one more at 10
        // -> 9+10=19 -> a tick, debt 9 again (the remainder
        // carries; time is conserved, never lost)
        {
            int debt = 0;
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 13->3
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 16->6
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 19->9
            if (debt != 9) ++bad;
            if (ticksFromDebt(debt, 10) != 1) ++bad;  // 19->9
            if (debt != 9) ++bad;
        }
        printf("R90 clock audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R91: stairs audit ----
    {
        int bad = 0;
        // the descent costs 6 hours (36 turns) - rest parity:
        // hours of time, pace-free, one wander bite at the end
        if (descentTurns() != 36) ++bad;
        // the clock model is coherent: camp 48, interrupted
        // watch 4, stairs 36 - all under a 120' day (144 turns)
        if (restTurns(false) + descentTurns() > 144) ++bad;
        if (restTurns(true) + descentTurns() > 144) ++bad;
        // a descend-then-camp day (36 + 48) plus a 60-step
        // unburdened march (60) still fits the day
        if (36 + 48 + 60 > 144) ++bad;
        printf("R91 stairs audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R92: road audit ----
    {
        int bad = 0;
        // the climb: 12 turns per level
        if (ascentTurns(1) != 12) ++bad;
        if (ascentTurns(3) != 36) ++bad;
        if (ascentTurns(6) != 72) ++bad;
        // stairs symmetry: one descent (36) out-climbs three
        // levels of ascent (36) - the way down clears ground,
        // the way up re-walks it
        if (descentTurns() != ascentTurns(3)) ++bad;
        // a deep delve is expensive to leave: level 10 costs
        // 120 turns (20 hours - a full adventuring day)
        if (ascentTurns(10) != 120) ++bad;
        // clock-model coherence: a shallow delve (descend 36
        // + climb 12 + camp 48 = 96) fits a 144-turn day;
        // a deep delve to 6 does NOT (36 + 72 + 48 = 156) -
        // multi-day delves are the honest consequence of depth
        if (descentTurns() + ascentTurns(1) + restTurns(false)
            > 144) ++bad;
        if (descentTurns() + ascentTurns(6) + restTurns(false)
            <= 144) ++bad;
        printf("R92 road audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R93: ledger audit ----
    {
        int bad = 0;
        // the deepest tracker: monotone, never forgets
        if (deepestOf(0, 1) != 1) ++bad;    // a first delve
        if (deepestOf(1, 3) != 3) ++bad;    // deeper wins
        if (deepestOf(5, 3) != 5) ++bad;    // shallower loses
        if (deepestOf(5, 5) != 5) ++bad;    // equal holds
        // the ledger starts clean
        {
            Party p;
            if (p.delveCount != 0 || p.deepestLevel != 0 ||
                p.totalGold != 0) ++bad;
        }
        // a simulated career: 4 delves, deepest 3, gross
        // take banks - the arithmetic the report line prints
        {
            Party p;
            p.deepestLevel = deepestOf(p.deepestLevel, 1);
            p.deepestLevel = deepestOf(p.deepestLevel, 3);
            int hauls[4] = {400, 1200, 0, 800};
            for (int i = 0; i < 4; ++i) {
                ++p.delveCount;
                p.totalGold += hauls[i];
            }
            if (p.delveCount != 4) ++bad;
            if (p.deepestLevel != 3) ++bad;
            if (p.totalGold != 2400) ++bad;
        }
        printf("R93 ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R94: nerve audit ----
    {
        int bad = 0;
        // the event deltas
        if (loyaltyDriftDeepDescent() != -2) ++bad;
        if (loyaltyDriftDelveDone()   !=  3) ++bad;
        if (loyaltyDriftHardWatch()   != -1) ++bad;
        // the clamp: 0..125 (the loader's bounds)
        if (clampLoyalty(-5) != 0) ++bad;
        if (clampLoyalty(130) != 125) ++bad;
        if (clampLoyalty(50) != 50) ++bad;
        // a simulated career: hired at 50 (CHA 10, no adj),
        // one record descent (48), a hard watch (47), then
        // the completed delve (50) - a rough delve nets even;
        // a clean one gains
        {
            int loy = 50;
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            if (loy != 48) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 47) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 50) ++bad;
            // a clean delve (record + done only): 48 + 3 = 51
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 51) ++bad;
        }
        // the floor holds under a cowardly streak
        {
            int loy = 1;
            for (int i = 0; i < 5; ++i)
                loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 0) ++bad;
        }
        printf("R94 nerve audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R95: calendar audit ----
    {
        int bad = 0;
        // the conversion: 144 turns to the day
        if (turnsPerDay() != 144) ++bad;
        if (dungeonDays(0)    != 0) ++bad;
        if (dungeonDays(143)  != 0) ++bad;   // not yet a day
        if (dungeonDays(144)  != 1) ++bad;
        if (dungeonDays(156)  != 1) ++bad;   // a deep delve's
        if (dungeonDays(288)  != 2) ++bad;   // remainder is
        if (dungeonDays(1000) != 6) ++bad;   // honest floors
        // the ledger bounds still hold with days: a full
        // delve day (36 descent + 60 march + 48 camp = 144)
        // is exactly one career day
        if (descentTurns() + 60 + restTurns(false)
            != turnsPerDay()) ++bad;
        // the calendar starts clean and only grows
        {
            Party p;
            if (p.careerDays != 0) ++bad;
            p.careerDays += dungeonDays(144);
            p.careerDays += 1;               // an overland day
            p.careerDays += 1;               // a sea day
            if (p.careerDays != 3) ++bad;
        }
        printf("R95 calendar audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R96: town clock audit ----
    {
        int bad = 0;
        // training costs days equal to the new level
        if (trainingDays(2) != 2) ++bad;
        if (trainingDays(3) != 3) ++bad;
        if (trainingDays(9) != 9) ++bad;
        // the 1st rank is never free, the 20th never
        // costs more than the keep's patience (bound 1..20)
        if (trainingDays(1) < 1) ++bad;
        if (trainingDays(20) > 20) ++bad;
        // a town week: three inn nights and one promotion
        // to 3rd level - 3 + 3 days, no more, no less
        {
            Party p;
            p.careerDays = 0;
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += trainingDays(3);       // the drills
            if (p.careerDays != 6) ++bad;
        }
        printf("R96 town clock audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R97: gray beard audit ----
    {
        int bad = 0;
        // starting age bases: fighter youngest, MU latest
        if (startAgeBase(rules::CLASS_FIGHTER)    != 15) ++bad;
        if (startAgeBase(rules::CLASS_MAGIC_USER) != 24) ++bad;
        if (startAgeBase(rules::CLASS_CLERIC)     != 18) ++bad;
        if (startAgeBase(rules::CLASS_THIEF)      != 18) ++bad;
        // rolled bounds: fighter 16..19, MU 26..40
        {
            rules::Rng r{1};
            rules::Dice d(r);
            for (int i = 0; i < 200; ++i) {
                int f = rollStartingAge(rules::CLASS_FIGHTER, d);
                int m = rollStartingAge(rules::CLASS_MAGIC_USER, d);
                if (f < 16 || f > 19) ++bad;
                if (m < 26 || m > 40) ++bad;
            }
        }
        // the clock turns years only at whole 365s
        {
            Character c;
            c.startAge = 20;
            if (ageYears(c, 0)   != 20) ++bad;
            if (ageYears(c, 364) != 20) ++bad;
            if (ageYears(c, 365) != 21) ++bad;
            if (ageYears(c, 730) != 22) ++bad;
        }
        // an unknown youth (v1 save) stays 0 until the
        // clock grows years of its own
        {
            Character c;
            if (c.startAge != 0) ++bad;
            if (ageYears(c, 364) != 0) ++bad;
            if (ageYears(c, 365) != 1) ++bad;
        }
        printf("R97 gray beard audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R114: aging audit ----
    {
        int bad = 0;
        // the book's five human brackets (DMG p.13-14):
        // young adult <= 20, mature <= 40, middle aged
        // <= 60, old <= 90, venerable 91+
        if (ageBracket(20) != 0) ++bad;
        if (ageBracket(21) != 1) ++bad;
        if (ageBracket(40) != 1) ++bad;
        if (ageBracket(41) != 2) ++bad;
        if (ageBracket(60) != 2) ++bad;
        if (ageBracket(61) != 3) ++bad;
        if (ageBracket(90) != 3) ++bad;
        if (ageBracket(91) != 4) ++bad;
        // the book's per-bracket adjustments (DMG p.14)
        if (ageAbilityDelta(0, rules::ABILITY_STR) != 0)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_STR) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_CHA) != 0)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_STR) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_DEX) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_DEX) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CHA) != 0)
            ++bad;
        // CHA is never touched at any bracket
        if (ageAbilityDelta(0, rules::ABILITY_CHA) != 0)
            ++bad;
        for (int b = 1; b <= 4; ++b)
            if (ageAbilityDelta(b, rules::ABILITY_CHA) != 0)
                ++bad;
        // mature applies once and clamps at the ceiling
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  3);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);   // mature
            if (c.abilities.get(rules::ABILITY_STR) != 18)
                ++bad;                // 18+1 clipped at ceiling
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;                // no CON bend at mature
            if (c.abilities.get(rules::ABILITY_INT) != 17)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 9)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;                // untouched
        }
        // a full life: STR 17, CON 9, INT 17, WIS 16,
        // DEX 9 through the four bends (cumulative)
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 17);
            c.abilities.set(rules::ABILITY_CON,  9);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 16);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);
            applyAgeBracket(c, 2);
            applyAgeBracket(c, 3);
            applyAgeBracket(c, 4);
            // STR 17+1-1-2-1=14, CON 9-1-1-1=6,
            // INT 17+1+1=19 -> 18 (clipped; the book
            // would let WIS pass 18 - WIS 16+4=20
            // -> 18 too, documented), DEX 9-2-1=6
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;
        }
        printf("R114 aging audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R115: magic weapon gate audit ----
    {
        int bad = 0;
        // the book's gate (p.76): a defender struck only
        // by +N weapons is hit by +N or better - pinned
        // so no refactor can flip the convention
        if (!rules::weaponSufficient(0, 0)) ++bad;
        if (rules::weaponSufficient(1, 0)) ++bad;
        if (!rules::weaponSufficient(1, 1)) ++bad;
        if (rules::weaponSufficient(2, 1)) ++bad;
        if (!rules::weaponSufficient(2, 2)) ++bad;
        if (rules::weaponSufficient(3, 2)) ++bad;
        if (!rules::weaponSufficient(3, 3)) ++bad;
        if (rules::weaponSufficient(4, 3)) ++bad;
        if (!rules::weaponSufficient(4, 4)) ++bad;
        printf("R115 magic weapon gate audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R115: magic aging audit ----
    {
        int bad = 0;
        // the book's table (DMG p.14): haste costs its
        // recipient 1 year; the caster-aged causes await
        // their spells
        if (spells::magicalAgingYears(spells::MU_HASTE) != 1)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_FIREBALL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::CL_HEAL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_TELEPORT) != 0)
            ++bad;
        // the stolen years ride the age clock: 20 -> 21
        // crosses into mature (+1 STR, +1 WIS)
        {
            Character c;
            c.startAge = 20;
            c.abilities.set(rules::ABILITY_STR, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_CON, 10);
            if (ageYears(c, 0) != 20) ++bad;
            applyMagicalAging(c, 0, 1);
            if (c.magicAgeYears != 1) ++bad;
            if (ageYears(c, 0) != 21) ++bad;
            if (ageYears(c, 3650) != 31) ++bad;  // +10 career
            if (c.abilities.get(rules::ABILITY_STR) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 10)
                ++bad;    // no CON bend at mature
        }
        // zero years is a no-op
        {
            Character c;
            c.startAge = 30;
            applyMagicalAging(c, 0, 0);
            if (c.magicAgeYears != 0) ++bad;
            if (ageYears(c, 0) != 30) ++bad;
        }
        // one crossing: 39 -> 44 enters middle aged
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            applyMagicalAging(c, 364, 5);   // 39 -> 44
            if (c.magicAgeYears != 5) ++bad;
            if (ageYears(c, 364) != 44) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
        }
        // two crossings at once: 39 -> 61 enters old,
        // middle aged's bend then old's, progressively
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX, 15);
            applyMagicalAging(c, 0, 22);   // 39 -> 61
            // STR 15-1-2=12, CON 15-1-1=13, INT 10+1=11,
            // WIS 10+1+1=12, DEX 15-2=13
            if (ageYears(c, 0) != 61) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 13)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 13)
                ++bad;
        }
        printf("R115 magic aging audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R116: missile range audit ----
    {
        int bad = 0;
        // the book's note (DMG p.75): missiles -2 at
        // medium range, -5 at long. Medium is twice the
        // registry's short range, long three times
        // (documented derivation); beyond long, no
        // shot is possible
        // helper sweep at short = 40' (the sling): the
        // short band is 0..40 (mod 0, in range)
        if (!rules::missileInRange(0, 40)) ++bad;
        if (!rules::missileInRange(40, 40)) ++bad;
        if (rules::missileRangeMod(0, 40) != 0) ++bad;
        if (rules::missileRangeMod(40, 40) != 0) ++bad;
        if (!rules::missileInRange(120, 40)) ++bad;
        if (rules::missileInRange(121, 40)) ++bad;
        if (rules::missileRangeMod(41, 40) != -2) ++bad;
        if (rules::missileRangeMod(80, 40) != -2) ++bad;
        if (rules::missileRangeMod(81, 40) != -5) ++bad;
        if (rules::missileRangeMod(120, 40) != -5) ++bad;
        if (rules::missileRangeMod(39, 40) != 0) ++bad;
        // the registry's missile weapons, pinned: sling
        // 40, short bow 50, long bow 70, crossbow 60
        if (items::weapon(items::WPN_SLING).rangeTens != 4)
            ++bad;
        if (items::weapon(items::WPN_SHORT_BOW).rangeTens != 5)
            ++bad;
        if (items::weapon(items::WPN_LONG_BOW).rangeTens != 7)
            ++bad;
        if (items::weapon(items::WPN_CROSSBOW_LIGHT).rangeTens
                != 6) ++bad;
        // the engagement's geometry (R43): 50' at the
        // opening band - the sling's first-round volley
        // is at medium (-2), the bows' at short (0)
        if (rules::missileRangeMod(50, 40) != -2) ++bad;
        if (rules::missileRangeMod(50, 50) != 0) ++bad;
        if (rules::missileRangeMod(50, 60) != 0) ++bad;
        if (rules::missileRangeMod(50, 70) != 0) ++bad;
        printf("R116 missile range audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R117: encounter reactions audit ----
    {
        int bad = 0;
        // the book's seven bands (DMG p.64), every
        // edge pinned on the pure banding helper
        if (dm::reactionForScore(5) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(6) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(25) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(26) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(45) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(46) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(55) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(56) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(75) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(76) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(95) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(96) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        if (dm::reactionForScore(100) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        // clamped at both ends (the book's "01 (or
        // less)" and "96-00 (or greater)")
        if (dm::reactionForScore(0) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(-4) != dm::REACTION_VIOLENT)
            ++bad;   // a -4 CHA adj can drive it below
        if (dm::reactionForScore(104) != dm::REACTION_ENTHUSIASTIC)
            ++bad;   // a +4 CHA adj can drive it above
        // the enum keeps the book's order (a caller
        // may compare magnitudes: violent < ... <
        // enthusiastic)
        if (dm::REACTION_VIOLENT != 0 ||
            dm::REACTION_HOSTILE != 1 ||
            dm::REACTION_UNCERTAIN_NEG != 2 ||
            dm::REACTION_NEUTRAL != 3 ||
            dm::REACTION_UNCERTAIN_POS != 4 ||
            dm::REACTION_FRIENDLY != 5 ||
            dm::REACTION_ENTHUSIASTIC != 6) ++bad;
        // smoke: 200 seeded rolls land in range and
        // both ends of the table are reachable
        {
            rules::Rng rng7(4242);
            rules::Dice dice7(rng7);
            bool sawLow = false, sawHigh = false;
            for (int i = 0; i < 200; ++i) {
                dm::Reaction r = dm::rollReaction(dice7, 0);
                if (r < dm::REACTION_VIOLENT ||
                    r > dm::REACTION_ENTHUSIASTIC) ++bad;
                if (r <= dm::REACTION_HOSTILE) sawLow = true;
                if (r >= dm::REACTION_FRIENDLY) sawHigh = true;
            }
            if (!sawLow || !sawHigh) ++bad;
        }
        printf("R117 encounter reactions audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R118: listening at doors audit ----
    {
        int bad = 0;
        // the book's table (DMG p.60): all seven
        // racial entries pinned, in 20
        if (abilities::raceListenIn20(abilities::LISTEN_DWARF)    != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_ELF)      != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_GNOME)   != 4)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ELF) != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALFLING) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ORC) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HUMAN)   != 2)
            ++bad;
        // out-of-range race -> the human band
        // (documented default)
        if (abilities::raceListenIn20(abilities::LISTEN_RACE_COUNT) != 2)
            ++bad;
        // the keen-eared bonus (1 or 2 in 20,
        // the caller passes it)
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 0) != 2)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 2) != 4)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 1) != 5)
            ++bad;
        // clamps at both ends
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, -9) != 0)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 20) != 20)
            ++bad;
        // thieves ride hear-noise (PHB) as in-20
        // bands (pct/5): L1 10% -> 2, L5 20% -> 4,
        // L12 35% -> 7, L13+ repeats the L12 row
        if (abilities::thiefListenIn20(1, 0)  != 2) ++bad;
        if (abilities::thiefListenIn20(5, 0)  != 4) ++bad;
        if (abilities::thiefListenIn20(12, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(13, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(9, 2)  != 8) ++bad;
        // clamps, and the derivation cross-checked
        // against the skill table itself
        if (abilities::thiefListenIn20(1, -9)  != 0)  ++bad;
        if (abilities::thiefListenIn20(12, 20) != 20) ++bad;
        for (int lvl = 1; lvl <= 14; ++lvl) {
            int expected =
                abilities::thiefSkillBase(abilities::SKILL_HEAR_NOISE,
                                         lvl) / 5;
            if (abilities::thiefListenIn20(lvl, 0) != expected)
                ++bad;
        }
        // the roll: d20 <= chance; the edges and a
        // seeded smoke with both ends reachable
        {
            rules::Rng rng8(6180);
            rules::Dice dice8(rng8);
            for (int i = 0; i < 100; ++i) {
                if (abilities::listenAtDoor(dice8, 0))  ++bad;
                if (!abilities::listenAtDoor(dice8, 20)) ++bad;
            }
            int hits = 0, misses = 0;
            for (int i = 0; i < 2000; ++i) {
                if (abilities::listenAtDoor(dice8, 2)) ++hits;
                else ++misses;
            }
            if (hits == 0 || misses == 0) ++bad;
        }
        printf("R118 listening at doors audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R119: forced rest audit ----
    {
        int bad = 0;
        // the book (DMG p.38): rest at least one turn
        // in six - turns 1-5 may be activity, the
        // sixth is owed
        if (forcedRestDue(0)) ++bad;
        if (forcedRestDue(1)) ++bad;
        if (forcedRestDue(4)) ++bad;
        if (!forcedRestDue(5)) ++bad;
        if (!forcedRestDue(6)) ++bad;
        if (!forcedRestDue(30)) ++bad;
        // combat or any other strenuous activity owes
        // a turn of rest (DMG p.38)
        if (strenuousRestTurns() != 1) ++bad;
        printf("R119 forced rest audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R120: parley and listening wiring audit ----
    {
        int bad = 0;
        // the book's starred bands (DMG p.64): only
        // violently hostile and hostile mean immediate
        // attack; the other five bands are parley
        if (!dm::reactionAttacks(dm::REACTION_VIOLENT)) ++bad;
        if (!dm::reactionAttacks(dm::REACTION_HOSTILE)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_NEG)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_NEUTRAL)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_POS)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_FRIENDLY)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_ENTHUSIASTIC)) ++bad;
        // the best listener: a thief rides hear-noise,
        // no thief rides the human band (R114); level 0
        // clamps to the L1 row
        if (abilities::bestListenIn20(false, 0) != 2) ++bad;
        if (abilities::bestListenIn20(false, 9) != 2) ++bad;
        if (abilities::bestListenIn20(true, 0)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 1)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 5)  != 4) ++bad;
        if (abilities::bestListenIn20(true, 12) != 7) ++bad;
        if (abilities::bestListenIn20(true, 13) != 7) ++bad;
        printf("R120 parley and listening audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R121: crew officers audit ----
    {
        int bad = 0;
        // the book (DMG p.35): for every 20 crewmen,
        // 1 lieutenant and 2 mates
        if (crewLieutenantsFor(20) != 1) ++bad;
        if (crewMatesFor(20) != 2)       ++bad;
        if (crewLieutenantsFor(40) != 2) ++bad;
        if (crewMatesFor(40) != 4)       ++bad;
        // a short company still ships one lieutenant
        if (crewLieutenantsFor(19) != 1) ++bad;
        if (crewMatesFor(19) != 2)       ++bad;
        // no crew, no officers
        if (crewLieutenantsFor(0) != 0)  ++bad;
        if (crewMatesFor(0) != 0)        ++bad;
        if (crewOfficerWages(0) != 0)   ++bad;
        // wages: captain 100 + lieutenant 100 + mates 60
        // (100 gp/level, L1 hires - documented; mates are
        // serjeants at 30 gp, p.34)
        if (crewOfficerWages(20) != 260) ++bad;
        if (crewOfficerWages(40) != 420) ++bad;
        // shares (DMG p.35): captain 25, each lieutenant 5,
        // each mate 1, crew 5 - and the PC keeps the rest
        if (crewCaptainSharePct()    != 25) ++bad;
        if (crewLieutenantSharePct() !=  5) ++bad;
        if (crewMateSharePct()       !=  1) ++bad;
        if (crewCrewSharePct()       !=  5) ++bad;
        if (crewOfficerSharePct(20)  != 32) ++bad;
        if (crewTotalSharePct(20)    != 37) ++bad;
        if (crewOfficerSharePct(40)  != 39) ++bad;
        if (crewTotalSharePct(40)    != 44) ++bad;
        if (100 - crewTotalSharePct(20) != 63) ++bad;
        printf("R121 crew officers audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R122: treasure line-diff audit ---------------------------------
    // The R122 line-by-line diff against the printed tables (DMG
    // pp.121-125) found all 383 rows faithful; this audit pins what
    // was diffed so a future edit cannot drift silently: every
    // table's row count, every row's dice-band continuity (1..100,
    // no gaps or overlaps), and the famous rows - the errata
    // corrections (the treasure.h header list), the printed range
    // (Ring of Protection), the no-value rows (Delusion, Poison, the
    // Throne of the Gods), the twin "Hammer +2" rows printed as-is,
    // the bundle quantities (arrows, bolts), and the cursed shield.
    {
        int bad = 0;
        // printed row counts: III.A, III.B (structure: 16 spell
        // bands + 8 protection scrolls + 1 curse row), III.C-H,
        // then 12 = the Special artifact table
        static const int kRows[13] = { 35, 25, 24, 30, 33,
                                       30, 33, 36, 35, 26,
                                       26, 36, 29 };
        for (int c = 0; c <= 12; ++c) {
            if (dm::treasure::magicTablePinCount(c) != kRows[c])
                ++bad;
        }
        // dice-band continuity on every ItemRow table
        for (int c = 0; c <= 12; ++c) {
            if (c == 1) continue;      // III.B: no ItemRow rows
            dm::treasure::TablePin p, prev;
            int n = dm::treasure::magicTablePinCount(c);
            for (int i = 0; i < n; ++i) {
                if (!dm::treasure::magicTablePin(c, i, &p)) {
                    ++bad; break;
                }
                if (p.lo < 1 || p.hi < p.lo || p.hi > 100) ++bad;
                if (i == 0     && p.lo != 1)         ++bad;
                if (i > 0      && p.lo != prev.hi + 1) ++bad;
                if (i == n - 1 && p.hi != 100)       ++bad;
                prev = p;
            }
        }
        dm::treasure::TablePin p;
        // III.A edge rows: 01-03 Animal Control 250/400, the
        // no-xp Delusion (13-15, gp 150) and Poison (82-84, no
        // values at all), 98-00 Water Breathing 400/900
        if (!dm::treasure::magicTablePin(0, 0, &p)) ++bad;
        else if (p.lo != 1 || p.hi != 3 || p.xp != 250 ||
                 p.gp != 400 ||
                 std::string(p.name) != "Potion of Animal Control")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 4, &p)) ++bad;
        else if (p.lo != 13 || p.hi != 15 || p.xp != 0 ||
                 p.gp != 150 ||
                 std::string(p.name) != "Potion of Delusion")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 28, &p)) ++bad;
        else if (p.lo != 82 || p.hi != 84 || p.xp != 0 ||
                 p.gp != 0 ||
                 std::string(p.name) != "Potion of Poison") ++bad;
        if (!dm::treasure::magicTablePin(0, 34, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 400 ||
                 p.gp != 900 ||
                 std::string(p.name) != "Potion of Water Breathing")
            ++bad;
        // III.C: the printed range row (Ring of Protection
        // 45-60, xp 2,000-4,000, gp 10,000-20,000) and the 00 row
        if (!dm::treasure::magicTablePin(2, 11, &p)) ++bad;
        else if (p.lo != 45 || p.hi != 60 ||
                 p.xp != 2000 || p.xpHi != 4000 ||
                 p.gp != 10000 || p.gpHi != 20000 ||
                 std::string(p.name) != "Ring of Protection") ++bad;
        if (!dm::treasure::magicTablePin(2, 23, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.xp != 4000 ||
                 std::string(p.name) != "Ring of X-Ray Vision") ++bad;
        // III.E.5: the Robe/Rope errata rows
        if (!dm::treasure::magicTablePin(8, 1, &p)) ++bad;
        else if (p.lo != 2 || p.hi != 8 || p.xp != 3500 ||
                 std::string(p.name) != "Robe of Blending") ++bad;
        if (!dm::treasure::magicTablePin(8, 7, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 27 || p.gp != 1000 ||
                 std::string(p.name) != "Rope of Constriction") ++bad;
        // Special: Heward's (printed Howard's), the valueless
        // Throne, and 00 Wand of Orcus
        if (!dm::treasure::magicTablePin(12, 8, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 26 || p.gp != 25000 ||
                 std::string(p.name) != "Heward's Mystical Organ")
            ++bad;
        if (!dm::treasure::magicTablePin(12, 27, &p)) ++bad;
        else if (p.lo != 99 || p.gp != 0 ||
                 std::string(p.name) != "Throne of the Gods") ++bad;
        if (!dm::treasure::magicTablePin(12, 28, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.gp != 10000 ||
                 std::string(p.name) != "Wand of Orcus") ++bad;
        // III.G: the Flame Tongue row (46-49) and the cursed rows
        // with no sale value
        if (!dm::treasure::magicTablePin(10, 5, &p)) ++bad;
        else if (p.lo != 46 || p.hi != 49 || p.xp != 900 ||
                 p.gp != 4500 ||
                 std::string(p.name) != "Sword +1, Flame Tongue")
            ++bad;
        if (!dm::treasure::magicTablePin(10, 25, &p)) ++bad;
        else if (p.lo != 96 || p.hi != 100 || p.gp != 0 ||
                 std::string(p.name) !=
                     "Sword, Cursed Berserking") ++bad;
        // III.H: the twin Hammer +2 rows printed as-is, and the
        // bundle quantities (Arrow +1 2-24, Bolt +2 2-20)
        if (!dm::treasure::magicTablePin(11, 18, &p)) ++bad;
        else if (p.lo != 57 || p.hi != 60 || p.xp != 300 ||
                 p.gp != 2500 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 19, &p)) ++bad;
        else if (p.lo != 61 || p.hi != 62 || p.xp != 650 ||
                 p.gp != 6000 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 0, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 24 ||
                 std::string(p.name) != "Arrow +1") ++bad;
        if (!dm::treasure::magicTablePin(11, 9, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 20 ||
                 std::string(p.name) != "Bolt +2") ++bad;
        // III.F: the cursed shield (98-00, no xp, gp 750)
        if (!dm::treasure::magicTablePin(9, 25, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 0 ||
                 p.gp != 750 ||
                 std::string(p.name) != "Shield -1, missile attractor")
            ++bad;
        printf("R122 treasure line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R123: outdoor movement audit ---------------------------------
    // The DMG pp.58-59 daily rates, pinned: the afoot table
    // (burden x terrain class, all nine cells), the burden
    // thresholds, the route-terrain mapping, the mounted and
    // afloat tables, and the company pace (the slowest
    // walker's rate from the true loads, the hire at his
    // kit, the fallen skipped).
    {
        int bad = 0;
        // the afoot table, all nine cells
        static const int kFoot[3][3] = {
            { 30, 20, 10 }, { 20, 10, 5 }, { 10, 5, 2 } };
        for (int b = 0; b < 3; ++b)
            for (int t = 0; t < 3; ++t)
                if (dm::footMilesPerDay(
                        (dm::FootBurden)b, (dm::TerrainClass)t)
                    != kFoot[b][t]) ++bad;
        // the burden thresholds (p.58-59)
        if (dm::footBurdenFor(0)  != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(25) != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(26) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(60) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(61) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(90) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(91) != dm::FB_HEAVY)   ++bad;
        // the route-terrain mapping (the 8 routes)
        if (dm::terrainClass(dm::T_PLAIN) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_SCRUB) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_DESERT) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_FOREST) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_ROUGH) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_HILLS) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MOUNTAINS)
            != dm::TC_VERY_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MARSH)
            != dm::TC_VERY_RUGGED) ++bad;
        // mounted (p.58-59): the four mounts and the
        // road-only carts (the book's dash is 0)
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_NORMAL) != 60) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_RUGGED) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_VERY_RUGGED) != 5) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_MEDIUM, dm::TC_NORMAL) != 40) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_HEAVY, dm::TC_NORMAL) != 30) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_DRAFT, dm::TC_RUGGED) != 15) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_NORMAL) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_VERY_RUGGED) != 0) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_RUGGED) != 10) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_VERY_RUGGED) != 0) ++bad;
        // afloat, oared: raft, boat, galley, merchant, warship
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_LAKE) != 15) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_BOAT_SMALL, dm::WATER_RIVER) != 35)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_SEA) != 30)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 20)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 20) ++bad;
        // afloat, sailed: the coaster's sea rate, the lake
        // bands, and the printed ranges (equal lo/hi where
        // the book prints one number)
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80 ||
            dm::sailedMilesHi(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 70 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 25 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 35) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 40 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        // the company pace: the slowest walker sets it, the
        // fallen are skipped, the hire counts at his kit
        {
            Party p;
            Character a; a.hp = 10; a.name = "Strider";
            p.members.push_back(a);
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_VERY_RUGGED)
                != 10) ++bad;
            Character b; b.hp = 10; b.name = "Plate";
            b.armor.id = items::ARMOR_PLATE;
            p.members.push_back(b);   // 450 gp wt: heavy
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_RUGGED) != 5)
                ++bad;
            p.members[1].hp = 0;   // the laden one falls
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            Party q;
            q.henchmanPresent = true;   // 625 gp wt: heavy
            if (companyFootMilesPerDay(q, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(q, dm::TC_VERY_RUGGED)
                != 2) ++bad;
        }
        printf("R123 outdoor movement audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R124: appendix A dressing audit ----------------------------------
    // The DMG pp.169-172 tables (Appendix A), pinned
    // row-by-row in dm/appendixa.h: the periodic check,
    // doors (both halves), side passages, passage
    // width, the special passages and their
    // stream/river/chasm chances, turns, chamber and
    // room shapes, the unusual shape/size sub-tables,
    // exits (count, location, direction), room
    // contents and the stairway variant, treasure by
    // level, containers, guards, hiding, stairs, tricks
    // and traps, gas, caves, pools, lakes and magic
    // pools with their sub-tables. The walk's four
    // wired helpers follow the bands, and the
    // generator still carves.
    {
        int bad = 0;
        namespace AP = dm::appendixa;
        // TABLE I: periodic check (p.170)
        static const AP::PassageCheck kT1[21] = {
            AP::PC_COUNT,
            AP::PC_STRAIGHT, AP::PC_STRAIGHT,
            AP::PC_DOOR, AP::PC_DOOR, AP::PC_DOOR,
            AP::PC_SIDE, AP::PC_SIDE, AP::PC_SIDE,
            AP::PC_SIDE, AP::PC_SIDE,
            AP::PC_TURN, AP::PC_TURN, AP::PC_TURN,
            AP::PC_CHAMBER, AP::PC_CHAMBER, AP::PC_CHAMBER,
            AP::PC_STAIRS, AP::PC_DEAD_END, AP::PC_TRICK_TRAP,
            AP::PC_WANDERER
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::passageCheckFor(r) != kT1[r]) ++bad;
        // TABLE II: doors (p.170)
        for (int r = 1; r <= 6; ++r)
            if (AP::doorLocationFor(r) != AP::DL_LEFT) ++bad;
        for (int r = 7; r <= 12; ++r)
            if (AP::doorLocationFor(r) != AP::DL_RIGHT) ++bad;
        for (int r = 13; r <= 20; ++r)
            if (AP::doorLocationFor(r) != AP::DL_AHEAD) ++bad;
        for (int r = 1; r <= 4; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_PARALLEL) ++bad;
        for (int r = 5; r <= 8; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_STRAIGHT_AHEAD) ++bad;
        if (AP::spaceBeyondFor(9) != AP::SB_45_AHEAD) ++bad;
        if (AP::spaceBeyondFor(10) != AP::SB_45_BEHIND) ++bad;
        for (int r = 11; r <= 18; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_ROOM) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_CHAMBER) ++bad;
        // TABLE III: side passages (p.170)
        static const AP::SidePassage kT3[21] = {
            AP::SP_COUNT,
            AP::SP_L90, AP::SP_L90,
            AP::SP_R90, AP::SP_R90,
            AP::SP_L45_AHEAD, AP::SP_R45_AHEAD,
            AP::SP_L45_BEHIND, AP::SP_R45_BEHIND,
            AP::SP_L_CURVE, AP::SP_R_CURVE,
            AP::SP_T, AP::SP_T, AP::SP_T,
            AP::SP_Y, AP::SP_Y,
            AP::SP_FOURWAY, AP::SP_FOURWAY,
            AP::SP_FOURWAY, AP::SP_FOURWAY,
            AP::SP_X
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::sidePassageFor(r) != kT3[r]) ++bad;
        // TABLE III.A: passage width (p.170)
        for (int r = 1; r <= 12; ++r)
            if (AP::passageWidthFeetFor(r) != 10) ++bad;
        for (int r = 13; r <= 16; ++r)
            if (AP::passageWidthFeetFor(r) != 20) ++bad;
        if (AP::passageWidthFeetFor(17) != 30) ++bad;
        if (AP::passageWidthFeetFor(18) != 5) ++bad;
        if (AP::passageWidthFeetFor(19) != -1 ||
            AP::passageWidthFeetFor(20) != -1) ++bad;
        // TABLE III.B: special passages (p.170)
        static const AP::SpecialPassage kSp[21] = {
            AP::SPEC_COUNT,
            AP::SPEC_COLUMNS_CENTER, AP::SPEC_COLUMNS_CENTER,
            AP::SPEC_COLUMNS_CENTER, AP::SPEC_COLUMNS_CENTER,
            AP::SPEC_COLUMNS_DOUBLE, AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE, AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_GALLERIES, AP::SPEC_COLUMNS_GALLERIES,
            AP::SPEC_STREAM, AP::SPEC_STREAM, AP::SPEC_STREAM,
            AP::SPEC_RIVER, AP::SPEC_RIVER,
            AP::SPEC_RIVER, AP::SPEC_RIVER, AP::SPEC_CHASM
        };
        static const int kSpW[21] = { 0,
            40, 40, 40, 40, 40, 40, 40,
            50, 50, 50, 50, 50,
            10, 10, 10, 20, 20, 40, 60, 20 };
        for (int r = 1; r <= 20; ++r) {
            AP::SpecialPass sp = AP::specialPassageFor(r);
            if (sp.kind != kSp[r] || sp.widthFt != kSpW[r]) ++bad;
        }
        // III.B footnotes: the stream/river/chasm chances
        for (int r = 1; r <= 15; ++r)
            if (!AP::streamBridged(r)) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::streamBridged(r)) ++bad;
        for (int r = 1; r <= 10; ++r)
            if (AP::riverFeature(r) != AP::WF_BRIDGED) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::riverFeature(r) != AP::WF_BOAT) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::riverFeature(r) != AP::WF_OBSTACLE) ++bad;
        for (int r = 1; r <= 10; ++r)
            if (AP::chasmFeature(r) != AP::CF_BRIDGED) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::chasmFeature(r) != AP::CF_JUMPING) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::chasmFeature(r) != AP::CF_OBSTACLE) ++bad;
        // TABLE IV: turns (p.170)
        static const AP::TurnKind kT4[21] = {
            AP::T_L90,
            AP::T_L90, AP::T_L90, AP::T_L90, AP::T_L90,
            AP::T_L90, AP::T_L90, AP::T_L90, AP::T_L90,
            AP::T_L45_AHEAD, AP::T_L45_BEHIND,
            AP::T_R90, AP::T_R90, AP::T_R90, AP::T_R90,
            AP::T_R90, AP::T_R90, AP::T_R90, AP::T_R90,
            AP::T_R45_AHEAD, AP::T_R45_BEHIND
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::turnFor(r) != kT4[r]) ++bad;
        // TABLE V: chamber and room shapes (p.171)
        static const int kChW[21] = { 0,
            20, 20, 20, 20, 30, 30, 40, 40,
            20, 20, 20, 20, 20, 30, 30, 40, 40, 0, 0, 0 };
        static const int kChH[21] = { 0,
            20, 20, 20, 20, 30, 30, 40, 40,
            30, 30, 30, 30, 30, 50, 50, 60, 60, 0, 0, 0 };
        for (int r = 1; r <= 20; ++r) {
            AP::SpaceShape s;
            AP::chamberShapeFor(r, s);
            if (s.unusual != (r >= 18) || s.wFt != kChW[r] ||
                s.hFt != kChH[r]) ++bad;
        }
        static const int kRmW[18] = { 0,
            10, 10, 20, 20, 30, 30, 40, 40,
            10, 10, 20, 20, 20, 20, 20, 30, 30 };
        static const int kRmH[18] = { 0,
            10, 10, 20, 20, 30, 30, 40, 40,
            20, 20, 30, 30, 30, 40, 40, 40, 40 };
        for (int r = 1; r <= 17; ++r) {
            AP::SpaceShape s;
            if (!AP::roomShapeFor(r, s)) ++bad;
            else if (s.wFt != kRmW[r] || s.hFt != kRmH[r] ||
                     s.unusual) ++bad;
        }
        for (int r = 18; r <= 20; ++r) {
            AP::SpaceShape s;
            if (AP::roomShapeFor(r, s)) ++bad;   // blank
        }
        // TABLE V.A: unusual shape (p.171)
        static const AP::UnusualShape kUs[21] = {
            AP::US_CIRCULAR,
            AP::US_CIRCULAR, AP::US_CIRCULAR,
            AP::US_CIRCULAR, AP::US_CIRCULAR,
            AP::US_CIRCULAR,
            AP::US_TRIANGULAR, AP::US_TRIANGULAR,
            AP::US_TRIANGULAR,
            AP::US_TRAPEZOIDAL, AP::US_TRAPEZOIDAL,
            AP::US_TRAPEZOIDAL,
            AP::US_ODD, AP::US_ODD,
            AP::US_OVAL, AP::US_OVAL,
            AP::US_HEXAGONAL, AP::US_HEXAGONAL,
            AP::US_OCTAGONAL, AP::US_OCTAGONAL,
            AP::US_CAVE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::unusualShapeFor(r) != kUs[r]) ++bad;
        for (int r = 1; r <= 5; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_POOL) ++bad;
        for (int r = 6; r <= 7; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_WELL) ++bad;
        for (int r = 8; r <= 10; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_SHAFT) ++bad;
        for (int r = 11; r <= 20; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_NORMAL) ++bad;
        // TABLE V.B: unusual size (p.171)
        static const int kUB[21] = { 0,
            500, 500, 500, 900, 900, 900, 1300, 1300,
            2000, 2000, 2700, 2700, 3400, 3400,
            -1, -1, -1, -1, -1, -1 };
        for (int r = 1; r <= 20; ++r)
            if (AP::unusualSizeBaseFor(r) != kUB[r]) ++bad;
        // TABLE V.C: number of exits (p.171)
        if (AP::exitsFor(1, false) != 1 || AP::exitsFor(3, true) != 2)
            ++bad;
        if (AP::exitsFor(4, false) != 2 || AP::exitsFor(6, true) != 3)
            ++bad;
        if (AP::exitsFor(7, false) != 3 || AP::exitsFor(9, true) != 4)
            ++bad;
        if (AP::exitsFor(10, false) != 0 || AP::exitsFor(12, true) != 1)
            ++bad;
        if (AP::exitsFor(13, false) != 0 || AP::exitsFor(15, true) != 1)
            ++bad;
        if (AP::exitsFor(16, false) != AP::kExitsRollD4 ||
            AP::exitsFor(18, true) != AP::kExitsRollD4) ++bad;
        if (AP::exitsFor(19, false) != 1 || AP::exitsFor(20, true) != 1)
            ++bad;
        // TABLE V.D: exit location (p.171)
        for (int r = 1; r <= 7; ++r)
            if (AP::exitLocationFor(r) != AP::EL_OPPOSITE) ++bad;
        for (int r = 8; r <= 12; ++r)
            if (AP::exitLocationFor(r) != AP::EL_LEFT) ++bad;
        for (int r = 13; r <= 17; ++r)
            if (AP::exitLocationFor(r) != AP::EL_RIGHT) ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::exitLocationFor(r) != AP::EL_SAME) ++bad;
        // TABLE V.E: exit direction (p.171)
        for (int r = 1; r <= 16; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_STRAIGHT) ++bad;
        for (int r = 17; r <= 18; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_45_LR) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_45_RL) ++bad;
        // TABLE V.F: room contents (p.171)
        static const dm::RoomContents kRC[21] = {
            dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_MONSTER, dm::ROOM_MONSTER,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_SPECIAL, dm::ROOM_TRAP, dm::ROOM_TREASURE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::roomContentsFor(r) != kRC[r]) ++bad;
        // the contents-18 stairway variant (the book's
        // print skips band 6 - pinned as printed)
        for (int r = 1; r <= 6; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_UP1) ++bad;
        for (int r = 7; r <= 8; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_UP2) ++bad;
        for (int r = 9; r <= 14; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_DOWN1) ++bad;
        for (int r = 15; r <= 19; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_DOWN2) ++bad;
        if (AP::stairwayVariantFor(20) != AP::SV_DOWN3) ++bad;
        // TABLE V.G: treasure by level (p.171, d%)
        for (int r = 1; r <= 100; ++r) {
            AP::TreasureRow t = AP::treasureFor(r);
            AP::TreasureKind ek;
            int eb = 0;
            if (r <= 25)      { ek = AP::TR_CP; eb = 1000; }
            else if (r <= 50) { ek = AP::TR_SP; eb = 1000; }
            else if (r <= 65) { ek = AP::TR_EP; eb = 750; }
            else if (r <= 80) { ek = AP::TR_GP; eb = 250; }
            else if (r <= 90) { ek = AP::TR_PP; eb = 100; }
            else if (r <= 94) { ek = AP::TR_GEMS; eb = 1; }
            else if (r <= 97) { ek = AP::TR_JEWELRY; eb = 1; }
            else              { ek = AP::TR_MAGIC; }
            if (t.kind != ek || t.basePerLevel != eb) ++bad;
        }
        // TABLE V.H: containers (p.171)
        static const AP::Container kCn[21] = {
            AP::C_LOOSE,
            AP::C_BAGS, AP::C_BAGS,
            AP::C_SACKS, AP::C_SACKS,
            AP::C_SMALL_COFFERS, AP::C_SMALL_COFFERS,
            AP::C_CHESTS, AP::C_CHESTS,
            AP::C_HUGE_CHESTS, AP::C_HUGE_CHESTS,
            AP::C_POTTERY_JARS, AP::C_POTTERY_JARS,
            AP::C_METAL_URNS, AP::C_METAL_URNS,
            AP::C_STONE_CONTAINERS, AP::C_STONE_CONTAINERS,
            AP::C_IRON_TRUNKS, AP::C_IRON_TRUNKS,
            AP::C_LOOSE, AP::C_LOOSE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::containerFor(r) != kCn[r]) ++bad;
        for (int r = 1; r <= 8; ++r)
            if (!AP::containerGuarded(r)) ++bad;
        for (int r = 9; r <= 20; ++r)
            if (AP::containerGuarded(r)) ++bad;
        // TABLE V.I: guarded by (p.171)
        static const AP::Guard kGd[21] = {
            AP::G_SYMBOL,
            AP::G_CONTACT_POISON_CONTAINER,
            AP::G_CONTACT_POISON_CONTAINER,
            AP::G_CONTACT_POISON_TREASURE,
            AP::G_CONTACT_POISON_TREASURE,
            AP::G_NEEDLES_LOCK, AP::G_NEEDLES_LOCK,
            AP::G_NEEDLES_HANDLES,
            AP::G_DARTS_FRONT,
            AP::G_DARTS_TOP,
            AP::G_DARTS_BOTTOM,
            AP::G_BLADE_SCYTHE, AP::G_BLADE_SCYTHE,
            AP::G_CREATURES,
            AP::G_GAS,
            AP::G_TRAPDOOR_FRONT,
            AP::G_TRAPDOOR_6FT,
            AP::G_STONE_BLOCK,
            AP::G_SPEARS,
            AP::G_EXPLOSIVE_RUNES,
            AP::G_SYMBOL
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::guardedByFor(r) != kGd[r]) ++bad;
        // TABLE V.J: hidden by/in (p.171)
        static const AP::Hidden kHd[21] = {
            AP::H_SECRET_ROOM,
            AP::H_INVISIBILITY, AP::H_INVISIBILITY,
            AP::H_INVISIBILITY,
            AP::H_ILLUSION, AP::H_ILLUSION,
            AP::H_SECRET_SPACE_UNDER,
            AP::H_SECRET_COMPARTMENT, AP::H_SECRET_COMPARTMENT,
            AP::H_ORDINARY_ITEM,
            AP::H_DISGUISED,
            AP::H_TRASH_DUNG,
            AP::H_LOOSE_FLOOR_STONE, AP::H_LOOSE_FLOOR_STONE,
            AP::H_LOOSE_WALL_STONE, AP::H_LOOSE_WALL_STONE,
            AP::H_SECRET_ROOM, AP::H_SECRET_ROOM,
            AP::H_SECRET_ROOM, AP::H_SECRET_ROOM,
            AP::H_SECRET_ROOM
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::hiddenByFor(r) != kHd[r]) ++bad;
        // TABLE VI: stairs (p.172)
        static const AP::StairKind kSt[21] = {
            AP::ST_UP1_DOWN2,
            AP::ST_DOWN1, AP::ST_DOWN1, AP::ST_DOWN1,
            AP::ST_DOWN1, AP::ST_DOWN1,
            AP::ST_DOWN2,
            AP::ST_DOWN3,
            AP::ST_UP1,
            AP::ST_UP_DEAD,
            AP::ST_DOWN_DEAD,
            AP::ST_CHIMNEY_UP1,
            AP::ST_CHIMNEY_UP2,
            AP::ST_CHIMNEY_DOWN2,
            AP::ST_TRAPDOOR_DOWN1, AP::ST_TRAPDOOR_DOWN1,
            AP::ST_TRAPDOOR_DOWN1,
            AP::ST_TRAPDOOR_DOWN2,
            AP::ST_UP1_DOWN2, AP::ST_UP1_DOWN2,
            AP::ST_UP1_DOWN2
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::stairsFor(r) != kSt[r]) ++bad;
        if (AP::stairEgressDoorIn20(AP::ST_DOWN1) != 1 ||
            AP::stairEgressDoorIn20(AP::ST_DOWN2) != 2 ||
            AP::stairEgressDoorIn20(AP::ST_DOWN3) != 3) ++bad;
        if (AP::stairEgressDoorIn20(AP::ST_UP1) != 0) ++bad;
        // TABLE VII: trick/trap (p.172)
        static const AP::TrickTrap kTt[21] = {
            AP::TT_CHUTE,
            AP::TT_SECRET_DOOR, AP::TT_SECRET_DOOR,
            AP::TT_SECRET_DOOR, AP::TT_SECRET_DOOR,
            AP::TT_SECRET_DOOR,
            AP::TT_PIT, AP::TT_PIT,
            AP::TT_PIT_SPIKED,
            AP::TT_ELEVATOR_DOWN1,
            AP::TT_ELEVATOR_DOWN2,
            AP::TT_ELEVATOR_2TO5,
            AP::TT_SLIDING_WALL,
            AP::TT_OIL_CINDER,
            AP::TT_PIT_CRUSHING,
            AP::TT_ARROW_TRAP,
            AP::TT_SPEAR_TRAP,
            AP::TT_GAS,
            AP::TT_FALLING_DOOR_STONE,
            AP::TT_ILLUSIONARY_WALL,
            AP::TT_CHUTE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::trickTrapFor(r) != kTt[r]) ++bad;
        // TABLE VII.A: gas (p.172)
        static const AP::GasKind kGs[21] = {
            AP::GAS_POISON,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE,
            AP::GAS_BLIND, AP::GAS_BLIND,
            AP::GAS_FEAR, AP::GAS_FEAR, AP::GAS_FEAR,
            AP::GAS_SLEEP,
            AP::GAS_STRENGTH, AP::GAS_STRENGTH,
            AP::GAS_STRENGTH, AP::GAS_STRENGTH,
            AP::GAS_STRENGTH,
            AP::GAS_SICKNESS,
            AP::GAS_POISON
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::gasFor(r) != kGs[r]) ++bad;
        // TABLE VIII: caves and caverns (p.172)
        static const int kCvW[21] = { 0,
            40, 40, 40, 40, 40, 50, 50,
            20, 20, 35, 35, 95, 95, 95, 120, 120, 150, 150,
            275, 275 };
        static const int kCvH[21] = { 0,
            60, 60, 60, 60, 60, 75, 75,
            30, 30, 50, 50, 125, 125, 125, 150, 150,
            200, 200, 375, 375 };
        static const int kCvW2[21] = { 0,
            0, 0, 0, 0, 0, 0, 0,
            60, 60, 80, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        static const int kCvH2[21] = { 0,
            0, 0, 0, 0, 0, 0, 0,
            60, 60, 90, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        static const bool kCvP[21] = { false,
            false, false, false, false, false, false, false,
            false, false, true, true, true, true, true,
            false, false, true, true, false, false };
        static const bool kCvL[21] = { false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false,
            false, false, false, false, false,
            true, true };
        for (int r = 1; r <= 20; ++r) {
            AP::CaveSize c = AP::caveFor(r);
            if (c.wFt != kCvW[r] || c.hFt != kCvH[r] ||
                c.w2Ft != kCvW2[r] || c.h2Ft != kCvH2[r] ||
                c.pool != kCvP[r] || c.lake != kCvL[r]) ++bad;
        }
        // TABLE VIII.A: pools (p.172)
        for (int r = 1; r <= 8; ++r)
            if (AP::poolFor(r) != AP::POOL_NONE) ++bad;
        for (int r = 9; r <= 10; ++r)
            if (AP::poolFor(r) != AP::POOL_NO_MONSTER) ++bad;
        for (int r = 11; r <= 12; ++r)
            if (AP::poolFor(r) != AP::POOL_MONSTER) ++bad;
        for (int r = 13; r <= 18; ++r)
            if (AP::poolFor(r) != AP::POOL_MONSTER_TREASURE) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::poolFor(r) != AP::POOL_MAGICAL) ++bad;
        // TABLE VIII.B: lakes (p.172)
        for (int r = 1; r <= 10; ++r)
            if (AP::lakeFor(r) != AP::LAKE_NONE) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::lakeFor(r) != AP::LAKE_NO_MONSTERS) ++bad;
        for (int r = 16; r <= 18; ++r)
            if (AP::lakeFor(r) != AP::LAKE_MONSTERS) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::lakeFor(r) != AP::LAKE_ENCHANTED) ++bad;
        // TABLE VIII.C: magic pools (p.172)
        for (int r = 1; r <= 8; ++r)
            if (AP::magicPoolFor(r) != AP::MP_GOLD_TO_PLATINUM_LEAD)
                ++bad;
        for (int r = 9; r <= 15; ++r)
            if (AP::magicPoolFor(r) != AP::MP_CHARACTERISTIC) ++bad;
        for (int r = 16; r <= 17; ++r)
            if (AP::magicPoolFor(r) != AP::MP_TALKING) ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::magicPoolFor(r) != AP::MP_TRANSPORTER) ++bad;
        for (int r = 1; r <= 11; ++r)
            if (!AP::goldBecomesPlatinum(r)) ++bad;
        for (int r = 12; r <= 20; ++r)
            if (AP::goldBecomesPlatinum(r)) ++bad;
        for (int r = 1; r <= 6; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_LAWFUL_GOOD)
                ++bad;
        for (int r = 7; r <= 9; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_LAWFUL_EVIL)
                ++bad;
        for (int r = 10; r <= 12; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_CHAOTIC_GOOD)
                ++bad;
        for (int r = 13; r <= 17; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_CHAOTIC_EVIL)
                ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_NEUTRAL)
                ++bad;
        for (int r = 1; r <= 7; ++r)
            if (AP::transportDestFor(r) != AP::TD_SURFACE) ++bad;
        for (int r = 8; r <= 12; ++r)
            if (AP::transportDestFor(r) != AP::TD_ELSEWHERE_LEVEL)
                ++bad;
        for (int r = 13; r <= 16; ++r)
            if (AP::transportDestFor(r) != AP::TD_ONE_DOWN) ++bad;
        for (int r = 17; r <= 20; ++r)
            if (AP::transportDestFor(r) != AP::TD_100_MILES) ++bad;
        // the walk's four wired helpers follow the
        // pinned bands, and the generator still carves
        {
            rules::Rng rng(20241002u);
            rules::Dice dice(rng);
            int seen[dm::ROOM_CONTENTS_COUNT] = { 0 };
            for (int i = 0; i < 4000; ++i)
                ++seen[dm::rollRoomContents(dice)];
            for (int k = 0; k < dm::ROOM_CONTENTS_COUNT; ++k)
                if (seen[k] == 0) ++bad;
            for (int i = 0; i < 400; ++i) {
                int w = dm::rollPassageWidth(dice);
                if (w < 1 || w > 3) ++bad;
            }
            int seenF[dm::PASSAGE_FEATURE_COUNT] = { 0 };
            for (int i = 0; i < 4000; ++i)
                ++seenF[dm::rollPassageFeature(dice)];
            // Table I's carveable outcomes all appear;
            // cross is Table III data, not a Table I row
            if (seenF[dm::PASSAGE_STRAIGHT] == 0 ||
                seenF[dm::PASSAGE_TURN] == 0 ||
                seenF[dm::PASSAGE_T_JUNCTION] == 0 ||
                seenF[dm::PASSAGE_CHAMBER] == 0 ||
                seenF[dm::PASSAGE_DEAD_END] == 0) ++bad;
            for (int i = 0; i < 400; ++i) {
                int w, h;
                dm::rollRoomSize(dice, w, h);
                if (w < 1 || w > 4 || h < 1 || h > 4) ++bad;
            }
            dm::DungeonResult d = dm::generateDungeon(4242u);
            if (d.rooms.empty()) ++bad;
            for (const auto& r : d.rooms) {
                if (r.w < 1 || r.h < 1 || r.x < 0 || r.y < 0 ||
                    r.x + r.w > world::MAP_TILES_X ||
                    r.y + r.h > world::MAP_TILES_Y) ++bad;
                if (r.contents < dm::ROOM_EMPTY ||
                    r.contents >= dm::ROOM_CONTENTS_COUNT) ++bad;
            }
        }
        printf("R124 appendix A dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R125: traps and tricks audit (App G/H) ----
    {
        int bad = 0;
        {
            namespace AG = dm::appendixg;
            namespace AH = dm::appendixh;
            // band continuity: the 46 bands tile 1-100 with
            // no gaps and no overlaps (the band edges chain)
            int lo = 1;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                if (AG::trapBandLo(k) != lo) ++bad;
                if (AG::trapBandHi(k) < AG::trapBandLo(k)) ++bad;
                lo = AG::trapBandHi(k) + 1;
            }
            if (lo != 101) ++bad;
            // spot pins from the printed page (p.216)
            if (AG::trapFor(3) != AG::TRAP_ARROW) ++bad;
            if (AG::trapFor(6) != AG::TRAP_ARROW_POISONED) ++bad;
            if (AG::trapFor(9) != AG::TRAP_CALTROPS) ++bad;
            if (AG::trapFor(19) != AG::TRAP_DOOR_ONE_WAY) ++bad;
            if (AG::trapFor(24) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(30) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(46) != AG::TRAP_GAS_OBSCURING) ++bad;
            if (AG::trapFor(57) != AG::TRAP_LIGHTNING_BOLT) ++bad;
            if (AG::trapFor(63) != AG::TRAP_PIT) ++bad;
            if (AG::trapFor(70) != AG::TRAP_PIT_SPIKES) ++bad;
            if (AG::trapFor(72) != AG::TRAP_PIT_POISONED_SPIKES) ++bad;
            if (AG::trapFor(77) != AG::TRAP_BARS_FALLING) ++bad;
            if (AG::trapFor(83) != AG::TRAP_SCYTHE) ++bad;
            if (AG::trapFor(87) != AG::TRAP_SPEAR) ++bad;
            if (AG::trapFor(88) != AG::TRAP_SPEAR_POISONED) ++bad;
            if (AG::trapFor(91) != AG::TRAP_TELEPORTER) ++bad;
            if (AG::trapFor(92) != AG::TRAP_VENT_ACID) ++bad;
            if (AG::trapFor(95) != AG::TRAP_VENT_GAS) ++bad;
            if (AG::trapFor(100) != AG::TRAP_VENT_GAS) ++bad;
            // counts, and every name nonempty and pure ASCII
            if (AG::TRAP_KIND_COUNT != 46) ++bad;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                const char* nm = AG::trapName(k);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // Appendix H: the feature (37) and attribute
            // (65) dressing lists, same name discipline
            if (AH::TRICK_FEATURE_COUNT != 37) ++bad;
            if (AH::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
            for (int f = 0; f < AH::TRICK_FEATURE_COUNT; ++f) {
                const char* nm = AH::trickFeatureName(f);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            for (int a = 0; a < AH::TRICK_ATTRIBUTE_COUNT; ++a) {
                const char* nm = AH::trickAttributeName(a);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // every d% face lands in range (full loop)
            for (int r = 1; r <= 100; ++r)
                if (AG::trapFor(r) < 0 ||
                    AG::trapFor(r) >= AG::TRAP_KIND_COUNT) ++bad;
            // the dressing combo smoke
            if (AH::trickSummary(AH::TF_ALTAR, AH::TA_ANIMATED)
                    != "Altar (Animated)") ++bad;
        }
        printf("R125 traps and tricks audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R126: wilderness line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
        // every served climate/terrain column chains 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the R63 outdoor tables)
        for (int c = 0; c < 8; ++c) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                    (OE::OutdoorClime)c, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the eleven terrain-column subtables chain likewise;
        // SUB_SPHINX_T is the tropical single-column footnote
        static const char* kSubs[12] = {
            "SUB_DEMIHUMAN", "SUB_DRAGON", "SUB_FROG",
            "SUB_GIANT", "SUB_HUMANOID", "SUB_LYCANTHROPE",
            "SUB_MEN", "SUB_SNAKE", "SUB_SPHINX",
            "SUB_SPIDER", "SUB_UNDEAD", "SUB_SPHINX_T"
        };
        for (const char* s : kSubs) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                    s, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // spot pins from the verified transcription - the
        // documented OCR/print folds (R63 header, R126
        // line-diff vs. the 1eonline Appendix C compilation)
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_SCRUB);
            if (!bandHas(b, "SUB_HUMANOID", 26, 32)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_PLAIN);
            if (!bandHas(b, "giant_eagle", 15, 16)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_ROUGH);
            if (!bandHas(b, "giant_scorpion", 84, 85)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_MOUNTAINS);
            if (!bandHas(b, "bandit", 23, 30)) ++bad;
        }
        {
            // the tropical mountains Sphinx row resolves off
            // the p.189 single-column footnote - all four
            std::vector<std::string> k = OE::outdoorEncounterKeys(
                reg, OE::OC_TROPICAL, OE::T_MOUNTAINS);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "androsphinx" || x == "criosphinx" ||
                    x == "gynosphinx" || x == "hieracosphinx") ++seen;
            }
            if (seen != 4) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_SUB_ARCTIC, OE::T_MARSH);
            if (!bandHas(b, "caveman", 56, 65)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_ARCTIC, OE::T_MOUNTAINS);
            if (!bandHas(b, "yeti", 91, 100)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_DRAGON", OE::T_FOREST);
            if (!bandHas(b, "chimera", 23, 30)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_GIANT", OE::T_HILLS);
            if (!bandHas(b, "stone_giant", 82, 98)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_MEN", OE::T_MARSH);
            if (!bandHas(b, "pilgrim", 36, 50)) ++bad;
            if (!bandHas(b, "caveman", 51, 100)) ++bad;
        }
        printf("R126 wilderness line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R127: waterborne line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
        // the four p.190 waterborne tables chain 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the p.190 waterborne set)
        for (int body = 0; body < 2; ++body) {
            for (int dep = 0; dep < 2; ++dep) {
                std::vector<OE::WaterborneBand> b =
                    OE::waterborneBands(
                        (OE::WaterBody)body,
                        (OE::WaterDepth)dep);
                if (b.empty()) { ++bad; continue; }
                int lo = 1;
                for (const OE::WaterborneBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the shared p.190 Dinosaur Subtable chains likewise
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            int lo = 1;
            for (const OE::WaterborneBand& x : b) {
                if (x.lo != lo || x.hi < x.lo) ++bad;
                lo = x.hi + 1;
            }
            if (lo != 101) ++bad;
        }
        // spot pins from the verified transcription - flags:
        // 1 = cool only, 2 = warm only, 4 = deep only
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_beaver", 1, 15, 1)) ++bad;
            if (!waterBandHas(b, "nixie", 61, 65, 1)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 11, 15, 2)) ++bad;
            if (!waterBandHas(b, "nixie", 86, 90, 2)) ++bad;
            if (!waterBandHas(b, "buccaneer", 34, 48, 0)) ++bad;
            if (!waterBandHas(b, "merchant", 49, 78, 0)) ++bad;
            if (!waterBandHas(b, "buccaneer", 79, 84, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_crocodile", 1, 2, 2)) ++bad;
            if (!waterBandHas(b, "DINOSAUR", 3, 10, 0)) ++bad;
            if (!waterBandHas(b, "caveman", 68, 70, 0)) ++bad;
            if (!waterBandHas(b, "merman", 71, 73, 0)) ++bad;
            if (!waterBandHas(b, "black_whale", 91, 96, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 97, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 1, 5, 0)) ++bad;
            if (!waterBandHas(b, "giant_squid", 54, 55, 0)) ++bad;
            if (!waterBandHas(b, "sperm_whale", 69, 72, 0)) ++bad;
            if (!waterBandHas(b, "whale", 86, 90, 0)) ++bad;
            if (!waterBandHas(b, "right_whale", 91, 95, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 96, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            if (!waterBandHas(b, "archelon_ischyros", 1, 15, 0)) ++bad;
            if (!waterBandHas(b, "dinichthys", 16, 35, 4)) ++bad;
            if (!waterBandHas(b, "plesiosaurus", 76, 100, 0)) ++bad;
        }
        {
            // the Men substitutions resolve, and no phantom
            // mermaid/pirate key survives
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "merman" || x == "buccaneer" ||
                    x == "merchant" || x == "giant_squid" ||
                    x == "sperm_whale") ++seen;
            }
            if (seen != 5) ++bad;
        }
        {
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "mermaid" || x == "pirate") ++bad;
                if (x == "caveman" || x == "merman") ++seen;
            }
            if (seen != 2) ++bad;
        }
        printf("R127 waterborne line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R128: special rooms audit ----
    {
        int bad = 0;
        // the Appendix H lists R128 wires: counts, names,
        // the summary phrase, and the first-effects slice
        if (dm::appendixh::TRICK_FEATURE_COUNT != 37) ++bad;
        if (dm::appendixh::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
        for (int f = 0; f < dm::appendixh::TRICK_FEATURE_COUNT;
             ++f) {
            const char* n = dm::appendixh::trickFeatureName(f);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        for (int a = 0;
             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
            const char* n =
                dm::appendixh::trickAttributeName(a);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        // out-of-range reads fall to "unknown"
        if (std::string(dm::appendixh::trickFeatureName(
                dm::appendixh::TRICK_FEATURE_COUNT))
            != "unknown") ++bad;
        if (std::string(dm::appendixh::trickAttributeName(
                dm::appendixh::TRICK_ATTRIBUTE_COUNT))
            != "unknown") ++bad;
        // the summary phrase: first and last combos
        if (dm::appendixh::trickSummary(0, 0)
            != "Altar (Ages)") ++bad;
        if (dm::appendixh::trickSummary(
                dm::appendixh::TRICK_FEATURE_COUNT - 1,
                dm::appendixh::TRICK_ATTRIBUTE_COUNT - 1)
            != "Well (Wish fulfillment, reversal)") ++bad;
        // the slices: exactly fifty-two mechanical
        // (R132 5 -> 11, R133 11 -> 16, R134 16 -> 19,
        // R135 19 -> 24, R136 24 -> 29, R139 29 -> 40,
        // R140 40 -> 52)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COINS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_GEMS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_MAGIC_ITEM) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOOTS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POISON)) ++bad;
        // R132: counterfeit joined the mechanical set; the
        // talks stay dressing
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        printf("R128 special rooms audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R130: high-level slots audit ----
    // PHB class-table pins: corrected low rows, printed
    // high rows, the holds past the print, and the gates.
    // Line-diff source: the 1eonline.info PHB compilation.
    // R130b: namespaced spells:: calls (the first R130
    // paste ran bare names - caught by the user's build).
    {
        int bad = 0;
        // the corrected R80 rows (levels 7-12)
        if (spells::spellSlots(spells::SPELL_MU, 7, 1) != 4) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 2) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 10, 4) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 11, 5) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 12, 5) != 4) ++bad;
        // R130c: the L12 print gives ONE 6th-level slot
        // (L12 = 4,4,4,4,4,1) - the r130b pin read the
        // 5th column twice
        if (spells::spellSlots(spells::SPELL_MU, 12, 6) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 6, 3) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 7, 4) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 8, 4) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 10, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 11, 1) != 5) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 12, 1) != 6) ++bad;
        // the printed high rows (13-20)
        if (spells::spellSlots(spells::SPELL_MU, 13, 6) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 17, 7) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 18, 9) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 20, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 13, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 16, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 17, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 20, 7) != 2) ++bad;
        // the holds past the print (L29 = the final row)
        if (spells::spellSlots(spells::SPELL_MU, 29, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 29, 7) != 7) ++bad;
        // the gates: cleric 7th at 17; INT 17 -> 7, 18 -> 9
        if (spells::maxSpellLevelForClericLevel(16) != 6) ++bad;
        if (spells::maxSpellLevelForClericLevel(17) != 7) ++bad;
        if (spells::maxSpellLevelForClericLevel(29) != 7) ++bad;
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        if (spells::maxSpellLevelForInt(17) != 7) ++bad;
        if (spells::maxSpellLevelForInt(18) != 9) ++bad;
        printf("R130 high-level slots audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R131: slot plumbing audit ----
    // The R130 tables made levels 7-9 real; this pins the
    // per-day plumbing that carries them (the named R130
    // debt): both arrays nine deep and zero-defaulted,
    // and toActor carries the 7th-9th columns to the
    // encounter party (the fill/copy loops are app-side -
    // pinned by the R130 table values they draw from).
    {
        int bad = 0;
        Character c;
        // the Character pool is nine deep and zeroed
        if (sizeof(c.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (c.slotsByLevel[lv] != 0) ++bad;
        // the Actor pool likewise
        ai::Actor a0;
        if (sizeof(a0.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (a0.slotsByLevel[lv] != 0) ++bad;
        // toActor carries the high columns (index 6-8 =
        // spell levels 7-9)
        c.classIndex = 1;   // MU
        c.level = 18;
        c.slotsByLevel[6] = 1;   // a 7th-circle slot
        c.slotsByLevel[7] = 2;   // 8th
        c.slotsByLevel[8] = 1;   // 9th (the Wish circle)
        ai::Actor a = c.toActor();
        if (a.slotsByLevel[6] != 1) ++bad;
        if (a.slotsByLevel[7] != 2) ++bad;
        if (a.slotsByLevel[8] != 1) ++bad;
        printf("R131 slot plumbing audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R147: dwarf CON magic-save bonus audit ----
    // PHB p.16: dwarves add their constitution to saves
    // vs. wands/staves/rods, spells, and poison. The
    // formula con*2/7 clamped 0..5 matches every printed
    // band (4-6 +1, 7-10 +2, 11-13 +3, 14-17 +4, 18+ +5).
    {
        int bad = 0;
        static const int kPins[][2] = {
            { 3, 0 }, { 4, 1 }, { 6, 1 }, { 7, 2 },
            { 10, 2 }, { 11, 3 }, { 13, 3 }, { 14, 4 },
            { 17, 4 }, { 18, 5 }, { 21, 5 },
        };
        for (int i = 0; i < 11; ++i)
            if (rules::dwarfConSaveBonus(
                    (uint8_t)kPins[i][0]) != kPins[i][1]) ++bad;
        int prev = -1;
        for (int c = 1; c <= 30; ++c) {
            int b = rules::dwarfConSaveBonus((uint8_t)c);
            if (b < 0 || b > 5) ++bad;
            if (b < prev) ++bad;
            prev = b;
        }
        printf("R147 dwarf CON save bonus audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R147: matrix II.D audit ----
    // DMG p.80 footnote D: non-intelligence saves at
    // half hit dice rounded up - half the II.B-stepped
    // level - except vs. death/poison. Pins: the halving
    // against the stepped level, the category exception,
    // the iron_golem/goblin mapping, and the census
    // (exactly 90 of the 408 print intelligence "non";
    // "animal" keeps II.B - a named judgment call).
    {
        int bad = 0;
        struct { float hd; int lvl; int half; } kPin[] = {
            { 0.5f, 1, 1 }, { 2.0f, 2, 1 },
            { 3.0f, 3, 2 }, { 4.0f, 4, 2 },
            { 4.75f, 5, 3 }, { 6.0f, 6, 3 },
            { 8.5f, 9, 5 }, { 10.0f, 10, 5 },
            { 12.0f, 12, 6 }, { 16.0f, 16, 8 },
            { 20.0f, 20, 10 },
        };
        for (int i = 0; i < 11; ++i) {
            int lvl = rules::monsterSaveLevel(kPin[i].hd);
            if (lvl != kPin[i].lvl) ++bad;
            int h = spelleffects::effectiveSaveLevel(
                lvl, true, rules::SAVE_SPELLS);
            if (h != kPin[i].half) ++bad;
            if (spelleffects::effectiveSaveLevel(
                    lvl, true, rules::SAVE_DEATH_POISON)
                != lvl) ++bad;
        }
        if (spelleffects::effectiveSaveLevel(
                9, false, rules::SAVE_SPELLS) != 9) ++bad;
        {
            rules::Rng rngII(20261004);
            rules::Dice diceII(rngII);
            if (!reg.toActor("iron_golem", diceII)
                    .nonIntelligent) ++bad;
            if (reg.toActor("goblin", diceII)
                    .nonIntelligent) ++bad;
            int non = 0;
            for (const auto& kv : reg.all())
                if (reg.toActor(kv.first, diceII)
                        .nonIntelligent) ++non;
            if (non != 90) ++bad;
        }
        printf("R147 matrix II.D audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R147: Appendix P audit ----
    // DMG pp.225-226: every table cell pinned (level
    // bands, protective + weapon percentages per class,
    // potion rows), Gonzo's worked example (15%/level
    // chain at 9th = 135; +2 chance 9 + 45 = 54, rolled
    // 51 -> at least +2; +3 check 9, rolled 99 -> just
    // +2), band sweeps, and the kit smoke (2000 members,
    // level 9, class i%4, seed 20261003 - floors arm
    // 1200 / shield 600 / weapon 1500).
    {
        int bad = 0;
        static const int kLo[3][3] = {
            { 1, 1, 2 }, { 5, 5, 7 }, { 8, 8, 9 },
        };
        static const int kHi[3][3] = {
            { 2, 3, 4 }, { 7, 8, 9 }, { 10, 11, 12 },
        };
        for (int b = 0; b < 3; ++b)
            for (int o = 0; o < 3; ++o) {
                if (dm::appendixp::bandLevelLo(b, o)
                    != kLo[b][o]) ++bad;
                if (dm::appendixp::bandLevelHi(b, o)
                    != kHi[b][o]) ++bad;
            }
        static const int kProt[4][7] = {
            { 10, 6, 8, 10, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 15, 4 },
            { 10, 5, 6, 8, 0, 2, 0 },
            { 0, 0, 0, 0, 10, 4, 0 },
        };
        for (int c = 0; c < 4; ++c)
            for (int k = 0; k < 7; ++k)
                if (dm::appendixp::protectivePct(c, k)
                    != kProt[c][k]) ++bad;
        static const int kWpn[4][7] = {
            { 10, 10, 0, 7, 8, 1, 10 },
            { 15, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 12, 0, 0, 0, 0 },
            { 12, 11, 0, 0, 0, 0, 0 },
        };
        for (int c = 0; c < 4; ++c)
            for (int k = 0; k < 7; ++k)
                if (dm::appendixp::weaponPct(c, k)
                    != kWpn[c][k]) ++bad;
        static const int kPot[4][2] = {
            { 8, 1 }, { 10, 3 }, { 6, 1 }, { 9, 2 },
        };
        for (int c = 0; c < 4; ++c) {
            if (dm::appendixp::potionPct(c)
                != kPot[c][0]) ++bad;
            if (dm::appendixp::potionMax(c)
                != kPot[c][1]) ++bad;
        }
        for (int p = 1; p <= 10; ++p)
            if (!*dm::appendixp::potionType(p)) ++bad;
        if (dm::appendixp::itemChancePct(15, 9)
            != 135) ++bad;
        if (dm::appendixp::plusTwoChancePct(15, 9)
            != 54) ++bad;
        if (dm::appendixp::plusThreeChancePct(9)
            != 9) ++bad;
        {
            rules::Rng rngP(20261003);
            rules::Dice diceP(rngP);
            for (int i = 0; i < 200; ++i) {
                int v = dm::appendixp::abilityRoll(diceP);
                if (v < 3 || v > 18) ++bad;
            }
            int items = 0, plus2 = 0, plus3 = 0;
            for (int i = 0; i < 4000; ++i) {
                int p = dm::appendixp::rollItemPlus(
                    diceP, 15, 9);
                if (p > 0) ++items;
                if (p >= 2) ++plus2;
                if (p == 3) ++plus3;
            }
            if (items != 4000) ++bad;
            if (plus2 < 1900 || plus2 > 2420) ++bad;
            if (plus3 < 100 || plus3 > 300) ++bad;
            int arm = 0, shd = 0, wpn = 0;
            for (int i = 0; i < 2000; ++i) {
                dm::appendixp::MemberMagic m =
                    dm::appendixp::rollMemberMagic(
                        diceP, i % 4, 9);
                if (m.armorPlus > 0) ++arm;
                if (m.shieldPlus > 0) ++shd;
                if (m.weaponPlus > 0) ++wpn;
            }
            if (arm < 1200) ++bad;
            if (shd < 600) ++bad;
            if (wpn < 1500) ++bad;
        }
        printf("R147 Appendix P audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R150: appendix I dressing audit ------------------------------
    // The DMG pp.217-220 dressing lists (Appendix I), pinned
    // band-by-band in dm/appendixi.h: air currents, odors,
    // air, general items and unexplained sounds. Every band
    // edge pinned both ways, the house discipline: at the
    // edge the kind, one past the edge the next. The 00 fold
    // and the clamp are pinned too. Count corrections, named
    // in the header: the R149 box said 16/100/68 bands; the
    // prints read 14/54/58 (odors 14 and air 6 were right).
    {
        int bad = 0;
        namespace AI = dm::appendixi;
        if (AI::AC_COUNT != 14 || AI::OD_COUNT != 14 ||
            AI::AIR_COUNT != 6 || AI::GI_COUNT != 54 ||
            AI::SK_COUNT != 58) ++bad;
        // air currents: 14 bands, edges both ways
        static const struct { int lo, hi; AI::AirCurrent k; }
            kAC[] = {
            {  1,  5, AI::AC_BREEZE_SLIGHT },
            {  6, 10, AI::AC_BREEZE_SLIGHT_DAMP },
            { 11, 12, AI::AC_BREEZE_GUSTING },
            { 13, 18, AI::AC_COLD_CURRENT },
            { 19, 20, AI::AC_DOWNDRAFT_SLIGHT },
            { 21, 22, AI::AC_DOWNDRAFT_STRONG },
            { 23, 69, AI::AC_STILL },
            { 70, 75, AI::AC_STILL_VERY_CHILL },
            { 76, 85, AI::AC_STILL_WARM },
            { 86, 87, AI::AC_UPDRAFT_SLIGHT },
            { 88, 89, AI::AC_UPDRAFT_STRONG },
            { 90, 93, AI::AC_WIND_STRONG },
            { 94, 95, AI::AC_WIND_STRONG_GUSTING },
            { 96,100, AI::AC_WIND_STRONG_MOANING },
        };
        for (size_t i = 0; i < sizeof(kAC)/sizeof(kAC[0]); ++i) {
            if (AI::airCurrentFor(kAC[i].lo) != kAC[i].k) ++bad;
            if (AI::airCurrentFor(kAC[i].hi) != kAC[i].k) ++bad;
            if (i + 1 < sizeof(kAC)/sizeof(kAC[0]) &&
                AI::airCurrentFor(kAC[i].hi + 1) != kAC[i+1].k)
                ++bad;
        }
        if (AI::airCurrentFor(0) != AI::AC_WIND_STRONG_MOANING)
            ++bad;   // 00 folds to 100
        // odors: 14 bands
        static const struct { int lo, hi; AI::Odor k; }
            kOD[] = {
            {  1,  3, AI::OD_ACRID },
            {  4,  5, AI::OD_CHLORINE },
            {  6, 39, AI::OD_DANK_MOULDY },
            { 40, 49, AI::OD_EARTHY },
            { 50, 57, AI::OD_MANURE },
            { 58, 61, AI::OD_METALLIC },
            { 62, 65, AI::OD_OZONE },
            { 66, 70, AI::OD_PUTRID },
            { 71, 75, AI::OD_ROTTING_VEGETATION },
            { 76, 77, AI::OD_SALTY_WET },
            { 78, 82, AI::OD_SMOKY },
            { 83, 89, AI::OD_STALE_FETID },
            { 90, 95, AI::OD_SULPHUROUS },
            { 96,100, AI::OD_URINE },
        };
        for (size_t i = 0; i < sizeof(kOD)/sizeof(kOD[0]); ++i) {
            if (AI::odorFor(kOD[i].lo) != kOD[i].k) ++bad;
            if (AI::odorFor(kOD[i].hi) != kOD[i].k) ++bad;
            if (i + 1 < sizeof(kOD)/sizeof(kOD[0]) &&
                AI::odorFor(kOD[i].hi + 1) != kOD[i+1].k) ++bad;
        }
        if (AI::odorFor(0) != AI::OD_URINE) ++bad;
        // air: 6 bands
        static const struct { int lo, hi; AI::AirState k; }
            kAIR[] = {
            {  1, 70, AI::AIR_CLEAR },
            { 71, 80, AI::AIR_FOGGY },
            { 81, 88, AI::AIR_FOGGY_NEAR_FLOOR },
            { 89, 90, AI::AIR_HAZY_DUST },
            { 91, 98, AI::AIR_HAZY_SMOKE },
            { 99,100, AI::AIR_MISTED },
        };
        for (size_t i = 0; i < sizeof(kAIR)/sizeof(kAIR[0]); ++i) {
            if (AI::airStateFor(kAIR[i].lo) != kAIR[i].k) ++bad;
            if (AI::airStateFor(kAIR[i].hi) != kAIR[i].k) ++bad;
            if (i + 1 < sizeof(kAIR)/sizeof(kAIR[0]) &&
                AI::airStateFor(kAIR[i].hi + 1) != kAIR[i+1].k)
                ++bad;
        }
        if (AI::airStateFor(0) != AI::AIR_MISTED) ++bad;
        // general items: 54 bands
        static const struct { int lo, hi; AI::GeneralItem k; }
            kGI[] = {
            {  1,  1, AI::GI_ARROW_BROKEN },
            {  2,  4, AI::GI_ASHES },
            {  5,  6, AI::GI_BONES },
            {  7,  7, AI::GI_BOTTLE_BROKEN },
            {  8,  8, AI::GI_CHAIN_CORRODED },
            {  9,  9, AI::GI_CLUB_SPLINTERED },
            { 10, 19, AI::GI_COBWEBS },
            { 20, 20, AI::GI_COIN_COPPER_BENT },
            { 21, 22, AI::GI_CRACKS_CEILING },
            { 23, 24, AI::GI_CRACKS_FLOOR },
            { 25, 26, AI::GI_CRACKS_WALL },
            { 27, 27, AI::GI_DAGGER_HILT },
            { 28, 29, AI::GI_DAMPNESS_CEILING },
            { 30, 33, AI::GI_DAMPNESS_WALL },
            { 34, 40, AI::GI_DRIPPING },
            { 41, 41, AI::GI_DRIED_BLOOD },
            { 42, 44, AI::GI_DUNG },
            { 45, 49, AI::GI_DUST },
            { 50, 50, AI::GI_FLASK_CRACKED },
            { 51, 51, AI::GI_FOOD_SCRAPS },
            { 52, 52, AI::GI_FUNGI_COMMON },
            { 53, 55, AI::GI_GUANO },
            { 56, 56, AI::GI_HAIR_FUR_BITS },
            { 57, 57, AI::GI_HAMMER_HEAD_CRACKED },
            { 58, 58, AI::GI_HELMET_DENTED },
            { 59, 59, AI::GI_IRON_BAR_BENT },
            { 60, 60, AI::GI_JAVELIN_HEAD_BLUNT },
            { 61, 61, AI::GI_LEATHER_BOOT },
            { 62, 64, AI::GI_LEAVES_TWIGS },
            { 65, 68, AI::GI_MOLD },
            { 69, 69, AI::GI_PICK_HANDLE },
            { 70, 70, AI::GI_POLE_BROKEN },
            { 71, 71, AI::GI_POTTERY_SHARDS },
            { 72, 73, AI::GI_RAGS },
            { 74, 74, AI::GI_ROPE_ROTTEN },
            { 75, 76, AI::GI_RUBBLE_DIRT },
            { 77, 77, AI::GI_SACK_TORN },
            { 78, 78, AI::GI_SLIMY_CEILING },
            { 79, 79, AI::GI_SLIMY_FLOOR },
            { 80, 80, AI::GI_SLIMY_WALL },
            { 81, 81, AI::GI_SPIKE_RUSTED },
            { 82, 83, AI::GI_STICKS },
            { 84, 84, AI::GI_STONES_SMALL },
            { 85, 85, AI::GI_STRAW },
            { 86, 86, AI::GI_SWORD_BLADE_BROKEN },
            { 87, 87, AI::GI_TEETH_SCATTERED },
            { 88, 88, AI::GI_TORCH_STUB },
            { 89, 89, AI::GI_WALL_SCRATCHINGS },
            { 90, 91, AI::GI_WATER_SMALL_PUDDLE },
            { 92, 93, AI::GI_WATER_LARGE_PUDDLE },
            { 94, 95, AI::GI_WATER_TRICKLE },
            { 96, 96, AI::GI_WAX_DRIPPINGS },
            { 97, 97, AI::GI_WAX_BLOB },
            { 98,100, AI::GI_WOOD_PIECES_ROTTING },
        };
        for (size_t i = 0; i < sizeof(kGI)/sizeof(kGI[0]); ++i) {
            if (AI::generalItemFor(kGI[i].lo) != kGI[i].k) ++bad;
            if (AI::generalItemFor(kGI[i].hi) != kGI[i].k) ++bad;
            if (i + 1 < sizeof(kGI)/sizeof(kGI[0]) &&
                AI::generalItemFor(kGI[i].hi + 1) != kGI[i+1].k)
                ++bad;
        }
        if (AI::generalItemFor(0) != AI::GI_WOOD_PIECES_ROTTING)
            ++bad;
        // unexplained sounds: 58 bands
        static const struct { int lo, hi; AI::SoundKind k; }
            kSK[] = {
            {  1,  5, AI::SK_BANG_SLAM },
            {  6,  6, AI::SK_BELLOW },
            {  7,  7, AI::SK_BONG },
            {  8,  8, AI::SK_BUZZING },
            {  9, 10, AI::SK_CHANTING },
            { 11, 11, AI::SK_CHIMING },
            { 12, 12, AI::SK_CHIRPING },
            { 13, 13, AI::SK_CLANKING },
            { 14, 14, AI::SK_CLASHING },
            { 15, 15, AI::SK_CLICKING },
            { 16, 16, AI::SK_COUGHING },
            { 17, 18, AI::SK_CREAKING },
            { 19, 19, AI::SK_DRUMMING },
            { 20, 23, AI::SK_FOOTSTEPS_AHEAD },
            { 24, 26, AI::SK_FOOTSTEPS_APPROACHING },
            { 27, 29, AI::SK_FOOTSTEPS_BEHIND },
            { 30, 31, AI::SK_FOOTSTEPS_RECEDING },
            { 32, 33, AI::SK_FOOTSTEPS_SIDE },
            { 34, 35, AI::SK_GIGGLING },
            { 36, 36, AI::SK_GONG },
            { 37, 39, AI::SK_GRATING },
            { 40, 41, AI::SK_GROANING },
            { 42, 42, AI::SK_GRUNTING },
            { 43, 44, AI::SK_HISSING },
            { 45, 45, AI::SK_HOOTING },
            { 46, 46, AI::SK_HORN },
            { 47, 47, AI::SK_HOWLING },
            { 48, 48, AI::SK_HUMMING },
            { 49, 49, AI::SK_JINGLING },
            { 50, 53, AI::SK_KNOCKING },
            { 54, 55, AI::SK_LAUGHTER },
            { 56, 57, AI::SK_MOANING },
            { 58, 60, AI::SK_MURMURING },
            { 61, 61, AI::SK_MUSIC },
            { 62, 62, AI::SK_RATTLING },
            { 63, 63, AI::SK_RINGING },
            { 64, 64, AI::SK_ROAR },
            { 65, 68, AI::SK_RUSTLING },
            { 69, 72, AI::SK_SCRATCHING },
            { 73, 74, AI::SK_SCREAMING },
            { 75, 77, AI::SK_SCUTTLING },
            { 78, 78, AI::SK_SHUFFLING },
            { 79, 80, AI::SK_SLITHERING },
            { 81, 81, AI::SK_SNAPPING },
            { 82, 82, AI::SK_SNEEZING },
            { 83, 83, AI::SK_SOBBING },
            { 84, 84, AI::SK_SPLASHING },
            { 85, 85, AI::SK_SPLINTERING },
            { 86, 87, AI::SK_SQUEAKING },
            { 88, 88, AI::SK_SQUEALING },
            { 89, 90, AI::SK_TAPPING },
            { 91, 92, AI::SK_THUD },
            { 93, 94, AI::SK_THUMPING },
            { 95, 95, AI::SK_TINKLING },
            { 96, 96, AI::SK_TWANGING },
            { 97, 97, AI::SK_WHINING },
            { 98, 98, AI::SK_WHISPERING },
            { 99,100, AI::SK_WHISTLING },
        };
        for (size_t i = 0; i < sizeof(kSK)/sizeof(kSK[0]); ++i) {
            if (AI::soundFor(kSK[i].lo) != kSK[i].k) ++bad;
            if (AI::soundFor(kSK[i].hi) != kSK[i].k) ++bad;
            if (i + 1 < sizeof(kSK)/sizeof(kSK[0]) &&
                AI::soundFor(kSK[i].hi + 1) != kSK[i+1].k) ++bad;
        }
        if (AI::soundFor(0) != AI::SK_WHISTLING) ++bad;
        printf("R150 appendix I dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R151: Appendix O encumbrance audit -----------------------------
    // The DMG p.225 Appendix O weight list, pinned row by
    // row in dm/appendixo.h: the 64 printed items - 57
    // exact rows, the 7 printed ranges (the four chests,
    // gem, small jewelry, tapestry) both ends, the
    // tapestry open tail, the 1500 g.p. (150#) carry max
    // and the four exemption wordings. Seven
    // representative name wordings are pinned too. The
    // caller is items::encumbranceBand (PHB p.38); this
    // is its printed per-item source.
    {
        int bad = 0;
        namespace AO = dm::appendixo;
        if (AO::GR_COUNT != 64 || AO::EX_COUNT != 4 ||
            AO::MAX_CARRY_GP != 1500) ++bad;
        // all 64 rows: lo and hi pinned, the name
        // non-empty, printed order kept
        static const struct { int lo, hi; AO::Gear g; }
            kGR[] = {
            {   20,   20, AO::GR_BACKPACK },
            {    3,    3, AO::GR_BELT },
            {   10,   10, AO::GR_BELT_POUCH_LARGE },
            {    5,    5, AO::GR_BELT_POUCH_SMALL },
            {  200,  200, AO::GR_BOOK_LARGE_METAL_BOUND },
            {   60,   60, AO::GR_BOOTS_HARD },
            {   30,   30, AO::GR_BOOTS_SOFT },
            {   60,   60, AO::GR_BOTTLES_FLAGONS },
            {   80,   80, AO::GR_BOW_COMPOSITE_LONG },
            {   50,   50, AO::GR_BOW_COMPOSITE_SHORT },
            {  100,  100, AO::GR_BOW_LONG },
            {   50,   50, AO::GR_BOW_SHORT },
            {   50,   50, AO::GR_CALTROP },
            {    5,    5, AO::GR_CANDLE },
            { 1000, 5000, AO::GR_CHEST_LARGE_SOLID_IRON },
            {  200,  500, AO::GR_CHEST_SMALL_SOLID_IRON },
            {  100,  250, AO::GR_CHEST_SMALL_WOODEN },
            {  500, 1500, AO::GR_CHEST_LARGE_WOODEN },
            {   30,   30, AO::GR_CLOTHES_ONE_SET },
            {    2,    2, AO::GR_CORD_10FT },
            {   80,   80, AO::GR_CROSSBOW_HEAVY },
            {   50,   50, AO::GR_CROSSBOW_LIGHT },
            {  150,  150, AO::GR_CRYSTAL_BALL },
            {    7,    7, AO::GR_FLASK_EMPTY },
            {   20,   20, AO::GR_FLASK_FULL },
            {    1,    5, AO::GR_GEM },
            {  100,  100, AO::GR_GRAPNEL },
            {   10,   10, AO::GR_HAND_TOOL },
            {   45,   45, AO::GR_HELM },
            {  100,  100, AO::GR_HELM_GREAT },
            {   25,   25, AO::GR_HOLY_WATER_BOTTLE },
            {   50,   50, AO::GR_HORN },
            {   50,   50, AO::GR_JEWELRY_LARGE },
            {    1,    5, AO::GR_JEWELRY_SMALL },
            {   60,   60, AO::GR_LANTERN },
            {    5,    5, AO::GR_MIRROR },
            {  350,  350, AO::GR_MUSICAL_INSTRUMENT },
            {  100,  100, AO::GR_POLE_10FT },
            {    1,    1, AO::GR_PURSE },
            {   30,   30, AO::GR_QUIVER },
            {   75,   75, AO::GR_RATIONS_IRON },
            {  200,  200, AO::GR_RATIONS_STANDARD },
            {   50,   50, AO::GR_ROBE_FOLDED },
            {   25,   25, AO::GR_ROBE_WORN },
            {   60,   60, AO::GR_ROD },
            {   75,   75, AO::GR_ROPE_50FT },
            {   20,   20, AO::GR_SACK_LARGE },
            {    5,    5, AO::GR_SACK_SMALL },
            {  250,  250, AO::GR_SADDLE_LIGHT_HORSE },
            {  500,  500, AO::GR_SADDLE_HEAVY_HORSE },
            {  150,  150, AO::GR_SADDLEBAG },
            {   20,   20, AO::GR_SADDLE_BLANKET },
            {   50,   50, AO::GR_SCROLL_CASE_BONE_IVORY },
            {   25,   25, AO::GR_SCROLL_CASE_LEATHER },
            {   10,   10, AO::GR_SPIKE },
            {  100,  100, AO::GR_STAFF },
            {   50, 1000, AO::GR_TAPESTRY },
            {    2,    2, AO::GR_TINDERBOX },
            {   25,   25, AO::GR_TORCH },
            {   60,   60, AO::GR_WAND_BONE_IVORY_CASE },
            {   80,   80, AO::GR_WAND_BOX },
            {   30,   30, AO::GR_WAND_LEATHER_CASE },
            {    5,    5, AO::GR_WATERSKIN_EMPTY },
            {   50,   50, AO::GR_WATERSKIN_FULL },
        };
        for (size_t i = 0; i < sizeof(kGR)/sizeof(kGR[0]); ++i) {
            if (AO::lo(kGR[i].g) != kGR[i].lo) ++bad;
            if (AO::hi(kGR[i].g) != kGR[i].hi) ++bad;
            if (std::string(AO::name(kGR[i].g)).empty()) ++bad;
        }
        // the open tail: tapestry alone
        for (int g = 0; g < AO::GR_COUNT; ++g) {
            if (AO::openEnded((AO::Gear)g) !=
                (g == (int)AO::GR_TAPESTRY)) ++bad;
        }
        // 7 representative name wordings (the
        // sub-row, footnote, wrapping, pad and ft
        // spellings pinned as printed)
        if (std::string(AO::name(AO::GR_BELT_POUCH_SMALL)) !=
            "Belt pouch, small") ++bad;
        if (std::string(AO::name(AO::GR_BOOK_LARGE_METAL_BOUND)) !=
            "Book, large metal-bound") ++bad;
        if (std::string(AO::name(AO::GR_CRYSTAL_BALL)) !=
            "Crystal ball, base and wrapping") ++bad;
        if (std::string(AO::name(AO::GR_MUSICAL_INSTRUMENT)) !=
            "Musical instrument") ++bad;
        if (std::string(AO::name(AO::GR_SADDLE_BLANKET)) !=
            "Saddle blanket (pad)") ++bad;
        if (std::string(AO::name(AO::GR_CORD_10FT)) !=
            "Cord, 10 ft.") ++bad;
        if (std::string(AO::name(AO::GR_ROPE_50FT)) !=
            "Rope, 50 ft.") ++bad;
        // the four exemption wordings, as printed
        if (std::string(AO::exemptName(
            AO::EX_MATERIAL_COMPONENTS)) !=
            "material components (unless large and bulky)") ++bad;
        if (std::string(AO::exemptName(AO::EX_HELM)) !=
            "any helm but great helm, if the character has any armor")
            ++bad;
        if (std::string(AO::exemptName(AO::EX_CLOTHING)) !=
            "one set of clothing") ++bad;
        if (std::string(AO::exemptName(AO::EX_THIEVES_PICKS)) !=
            "thieves' picks and tools") ++bad;
        printf("R151 Appendix O encumbrance audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R152: becoming-lost check audit -------------------------------
    // The DMG p.49 lost check, pinned in dm/outdoormove.h:
    // the 8 terrain chances in 10, the three direction
    // limitations and the lost-heading dice read clockwise
    // - the book prints NO chance of the party ever
    // accidentally moving in the desired direction when
    // lost, so the mapping never returns 0. The dice are
    // the callers; the accessors are deterministic.
    {
        int bad = 0;
        namespace OM = dm;
        // the 8 printed rows: chance in 10 and limitation
        static const struct { int c; OM::DirectionLimit dl; }
            kLost[] = {
            { 1, OM::DL_60 },   // plain
            { 3, OM::DL_60 },   // scrub
            { 7, OM::DL_ANY },  // forest
            { 3, OM::DL_60 },   // rough
            { 4, OM::DL_60 },   // desert
            { 2, OM::DL_60 },   // hills
            { 5, OM::DL_120 },  // mountains
            { 6, OM::DL_ANY },  // marsh
        };
        for (int i = 0; i < 8; ++i) {
            if (OM::lostChanceIn10((OM::OutdoorTerrain)i)
                != kLost[i].c) ++bad;
            if (OM::directionLimitFor((OM::OutdoorTerrain)i)
                != kLost[i].dl) ++bad;
        }
        // 60 degrees: 1-3 left, 4-6 right, both edges
        if (OM::lostAngleDeg(1, 1, OM::DL_60) != -60) ++bad;
        if (OM::lostAngleDeg(3, 1, OM::DL_60) != -60) ++bad;
        if (OM::lostAngleDeg(4, 1, OM::DL_60) != 60) ++bad;
        if (OM::lostAngleDeg(6, 1, OM::DL_60) != 60) ++bad;
        // 120: the second d6 picks the arc, both edges
        if (OM::lostAngleDeg(1, 3, OM::DL_120) != -60) ++bad;
        if (OM::lostAngleDeg(1, 4, OM::DL_120) != -120) ++bad;
        if (OM::lostAngleDeg(3, 6, OM::DL_120) != -120) ++bad;
        if (OM::lostAngleDeg(4, 3, OM::DL_120) != 60) ++bad;
        if (OM::lostAngleDeg(4, 4, OM::DL_120) != 120) ++bad;
        if (OM::lostAngleDeg(6, 6, OM::DL_120) != 120) ++bad;
        // any: single d6 read clockwise, both edges
        if (OM::lostAngleDeg(1, 1, OM::DL_ANY) != 60) ++bad;
        if (OM::lostAngleDeg(2, 1, OM::DL_ANY) != 120) ++bad;
        if (OM::lostAngleDeg(3, 1, OM::DL_ANY) != 180) ++bad;
        if (OM::lostAngleDeg(4, 1, OM::DL_ANY) != 180) ++bad;
        if (OM::lostAngleDeg(5, 1, OM::DL_ANY) != -120) ++bad;
        if (OM::lostAngleDeg(6, 1, OM::DL_ANY) != -60) ++bad;
        // never the desired direction, every face
        for (int dl = 0; dl < OM::DL_COUNT; ++dl)
            for (int a = 1; a <= 6; ++a)
                for (int b = 1; b <= 6; ++b)
                    if (OM::lostAngleDeg(a, b,
                        (OM::DirectionLimit)dl) == 0)
                        ++bad;
        printf("R152 becoming-lost audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R153: exceptional strength audit -------------------------------
    // The PHB p.9 STR Table II, all five printed columns
    // pinned for the full 3-18/00 table: hit probability,
    // damage adjustment, weight allowance in g.p., open
    // doors on a d6 (with the locked/barred/held
    // parentheticals on 18/91-99 and 18/00) and bend
    // bars/lift gates. This is the DIVERGENCE FIX round:
    // the original ex bands carried unsourced carry and
    // press numbers and misread the 18/91-99 hit/damage
    // and 18/51-75 damage cells - the printed values
    // replace them, named in character.h and the gap
    // report.
    {
        int bad = 0;
        namespace RS = rules;
        // the 15 printed rows: score, ex flag, pct, hit,
        // dmg, weight g.p., open doors, locked doors,
        // bend bars percent
        static const struct {
            int str; bool ex; int pct;
            int hit, dmg, wt, door, locked, bend;
        } kT2[] = {
            {  3, false,   0, -3, -1, -350, 1, 0,  0 },
            {  5, false,   0, -2, -1, -250, 1, 0,  0 },
            {  7, false,   0, -1,  0, -150, 1, 0,  0 },
            {  9, false,   0,  0,  0,    0, 2, 0,  1 },
            { 11, false,   0,  0,  0,    0, 2, 0,  2 },
            { 13, false,   0,  0,  0,  100, 2, 0,  4 },
            { 15, false,   0,  0,  0,  200, 2, 0,  7 },
            { 16, false,   0,  0,  1,  350, 3, 0, 10 },
            { 17, false,   0,  1,  1,  500, 3, 0, 13 },
            { 18, false,   0,  1,  2,  750, 3, 0, 16 },
            { 18, true,  25,  1,  3, 1000, 3, 0, 20 },
            { 18, true,  60,  2,  3, 1250, 4, 0, 25 },
            { 18, true,  85,  2,  4, 1500, 4, 0, 30 },
            { 18, true,  95,  2,  5, 2000, 4, 1, 35 },
            { 18, true, 100,  3,  6, 3000, 5, 2, 40 },
        };
        for (size_t i = 0; i < sizeof(kT2)/sizeof(kT2[0]); ++i) {
            RS::ExceptionalStrength ex;
            ex.has = kT2[i].ex; ex.pct = kT2[i].pct;
            if (RS::strHitAdj(kT2[i].str, ex) != kT2[i].hit)
                ++bad;
            if (RS::strDmgAdj(kT2[i].str, ex) != kT2[i].dmg)
                ++bad;
            if (RS::strWeightAllowGp(kT2[i].str, ex)
                != kT2[i].wt) ++bad;
            if (RS::strOpenDoorsMax(kT2[i].str, ex)
                != kT2[i].door) ++bad;
            if (RS::strOpenDoorsLockedMax(kT2[i].str, ex)
                != kT2[i].locked) ++bad;
            if (RS::strBendBarsPct(kT2[i].str, ex)
                != kT2[i].bend) ++bad;
        }
        // the percentile fold edges, both sides of each
        RS::ExceptionalStrength ex; ex.has = true;
        ex.pct = 50;
        if (ex.hitAdj() != 1 || ex.dmgAdj() != 3
            || ex.weightAllowGp() != 1000
            || ex.openDoorsMax() != 3
            || ex.bendBarsPct() != 20) ++bad;
        ex.pct = 51;  if (ex.hitAdj() != 2) ++bad;
        ex.pct = 75;  if (ex.dmgAdj() != 3
            || ex.weightAllowGp() != 1250
            || ex.bendBarsPct() != 25) ++bad;
        ex.pct = 76;  if (ex.dmgAdj() != 4
            || ex.weightAllowGp() != 1500
            || ex.openDoorsMax() != 4
            || ex.bendBarsPct() != 30) ++bad;
        ex.pct = 90;  if (ex.hitAdj() != 2
            || ex.dmgAdj() != 4) ++bad;
        ex.pct = 91;  if (ex.dmgAdj() != 5
            || ex.weightAllowGp() != 2000
            || ex.bendBarsPct() != 35
            || ex.openDoorsLockedMax() != 1) ++bad;
        ex.pct = 99;  if (ex.hitAdj() != 2
            || ex.openDoorsLockedMax() != 1) ++bad;
        ex.pct = 100; if (ex.hitAdj() != 3 || ex.dmgAdj() != 6
            || ex.weightAllowGp() != 3000
            || ex.openDoorsMax() != 5
            || ex.openDoorsLockedMax() != 2
            || ex.bendBarsPct() != 40) ++bad;
        // exceptional strength replaces the plain 18 row,
        // it does not add to it (PHB p.9)
        if (RS::strHitAdj(18, ex) != 3
            || RS::strDmgAdj(18, ex) != 6
            || RS::strBendBarsPct(18, ex) != 40) ++bad;
        printf("R153 exceptional strength audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R154: PC races audit ---------------------------------
    // PHB pp.15-18, Race Tables I-III: the racial ability
    // adjustments, the Table III minimums and maximums
    // (male and female columns), infravision, the
    // sleep-and-charm resistance, the CON magic-save bonus
    // (dwarf, gnome, halfling - the R147 shape) with the
    // poison finding (the print gives the gnome MAGIC
    // ONLY; dwarf and halfling ride poison too - the gap
    // box claimed gnome poison, the print wins), Race
    // Table I class limitations, the footnoted Race Table
    // II level caps, the goblin-kind and giant-kind
    // to-hit lists and the detection lists. The creation
    // RACE stage itself lives in appstate/adnd1 (the game
    // layer is outside the battery build; its syntax gate
    // compiles appstate.h via game/*.cpp).
    {
        int bad = 0;
        namespace RS = rules;
        // the Penalties and Bonuses list, all races x abilities
        static const int kAdj[7][6] = {
            {  0,  0,  0,  0,  0,  0 },   // human
            {  0,  0,  0,  0,  1, -1 },   // dwarf
            {  0,  0,  0,  1, -1,  0 },   // elf
            {  0,  0,  0,  0,  0,  0 },   // gnome
            {  0,  0,  0,  0,  0,  0 },   // half-elf
            { -1,  0,  0,  1,  0,  0 },   // halfling
            {  1,  0,  0,  0,  1, -2 },   // half-orc
        };
        for (int r = 0; r < 7; ++r)
            for (int a = 0; a < 6; ++a)
                if (RS::raceAbilityAdj((RS::CharRace)r,
                        (RS::Ability)a) != kAdj[r][a])
                    ++bad;
        // Table III minimums (identical M/F in print)
        static const int kMin[7][6] = {
            {  3,  3,  3,  3,  3,  3 },   // human
            {  8,  3,  3,  3, 12,  3 },   // dwarf
            {  3,  8,  3,  7,  6,  8 },   // elf
            {  6,  7,  3,  3,  8,  3 },   // gnome
            {  3,  4,  3,  6,  6,  3 },   // half-elf
            {  6,  6,  3,  8, 10,  3 },   // halfling
            {  6,  3,  3,  3, 13,  3 },   // half-orc
        };
        // Table III maximums, male then female columns
        static const int kMaxM[7][6] = {
            { 18, 18, 18, 18, 18, 18 },   // human
            { 18, 18, 18, 17, 19, 16 },   // dwarf
            { 18, 18, 18, 19, 18, 18 },   // elf
            { 18, 18, 18, 18, 18, 18 },   // gnome
            { 18, 18, 18, 18, 18, 18 },   // half-elf
            { 17, 18, 17, 18, 19, 18 },   // halfling
            { 18, 17, 14, 17, 19, 12 },   // half-orc
        };
        static const int kMaxF[7][6] = {
            { 18, 18, 18, 18, 18, 18 },   // human
            { 17, 18, 18, 17, 19, 16 },   // dwarf
            { 16, 18, 18, 19, 18, 18 },   // elf
            { 15, 18, 18, 18, 18, 18 },   // gnome
            { 17, 18, 18, 18, 18, 18 },   // half-elf
            { 14, 18, 17, 18, 19, 18 },   // halfling
            { 18, 17, 14, 17, 19, 12 },   // half-orc
        };
        for (int r = 0; r < 7; ++r)
            for (int a = 0; a < 6; ++a) {
                if (RS::raceAbilityMin((RS::CharRace)r,
                        (RS::Ability)a, false) != kMin[r][a])
                    ++bad;
                if (RS::raceAbilityMin((RS::CharRace)r,
                        (RS::Ability)a, true) != kMin[r][a])
                    ++bad;
                if (RS::raceAbilityMax((RS::CharRace)r,
                        (RS::Ability)a, false) != kMaxM[r][a])
                    ++bad;
                if (RS::raceAbilityMax((RS::CharRace)r,
                        (RS::Ability)a, true) != kMaxF[r][a])
                    ++bad;
            }
        // infravision and sleep-and-charm resistance
        static const int kInfra[7] = { 0, 60, 60, 60, 60, 30, 60 };
        static const int kSleep[7] = { 0,  0, 90,  0, 30,  0,  0 };
        for (int r = 0; r < 7; ++r) {
            if (RS::raceInfravisionFeet((RS::CharRace)r)
                != kInfra[r]) ++bad;
            if (RS::raceSleepCharmResistPct((RS::CharRace)r)
                != kSleep[r]) ++bad;
        }
        // the CON magic-save bands, every score 3-18, per
        // race - plus the poison finding (gnome: magic only)
        for (int c = 3; c <= 18; ++c) {
            int shape = (c * 2) / 7;
            if (shape > 5) shape = 5;
            for (int r = 0; r < 7; ++r) {
                bool magicRace =
                    r == RS::RACE_DWARF || r == RS::RACE_GNOME
                    || r == RS::RACE_HALFLING;
                bool poisonRace =
                    r == RS::RACE_DWARF || r == RS::RACE_HALFLING;
                if (RS::raceMagicSaveBonus((RS::CharRace)r,
                        (uint8_t)c) != (magicRace ? shape : 0))
                    ++bad;
                if (RS::racePoisonSaveBonus((RS::CharRace)r,
                        (uint8_t)c) != (poisonRace ? shape : 0))
                    ++bad;
            }
        }
        // Race Table I: class limitations, the base four
        static const bool kAllow[4][7] = {
            { true, true, true, true, true, true, true },   // F
            { true, false, true, false, true, false, false },   // MU
            { true, false, false, false, true, false, true },   // C
            { true, true, true, true, true, true, true },   // T
        };
        for (int ci = 0; ci < 4; ++ci)
            for (int r = 0; r < 7; ++r)
                if (RS::classAllowedForRace(ci,
                        (RS::CharRace)r) != kAllow[ci][r])
                    ++bad;
        // Race Table II level caps, with the footnotes
        static const struct {
            int ci; int r; int s; int dex; int cap;
        } kCap[] = {
            // fighter, footnote STR ladders
            { 0, 1, 16, 0,  7 }, { 0, 1, 17, 0,  8 },
            { 0, 1, 18, 0,  9 },
            { 0, 2, 16, 0,  5 }, { 0, 2, 17, 0,  6 },
            { 0, 2, 18, 0,  7 },
            { 0, 3, 17, 0,  5 }, { 0, 3, 18, 0,  6 },
            { 0, 4, 16, 0,  6 }, { 0, 4, 17, 0,  7 },
            { 0, 4, 18, 0,  8 },
            { 0, 5, 16, 0,  4 }, { 0, 5, 17, 0,  5 },
            { 0, 5, 18, 0,  6 },
            { 0, 6,  0, 0, 10 },
            // magic-user, footnote INT ladders
            { 1, 2, 16, 0,  9 }, { 1, 2, 17, 0, 10 },
            { 1, 2, 18, 0, 11 },
            { 1, 4, 16, 0,  6 }, { 1, 4, 17, 0,  7 },
            { 1, 4, 18, 0,  8 },
            // cleric caps (half-elf, half-orc)
            { 2, 4,  0, 0,  5 },
            { 2, 6,  0, 0,  4 },
            // thief, the half-orc footnote DEX ladder
            { 3, 6,  0, 16, 6 }, { 3, 6,  0, 17, 7 },
            { 3, 6,  0, 18, 8 },
            // unlimited: human everywhere, dwarf thief
            { 0, 0,  0, 0, -1 }, { 1, 0,  0, 0, -1 },
            { 2, 0,  0, 0, -1 }, { 3, 0,  0, 0, -1 },
            { 3, 1,  0, 0, -1 },
            // not allowed: MU dwarf, cleric dwarf/elf/gnome
            { 1, 1, 18, 0,  0 }, { 2, 1,  0, 0,  0 },
            { 2, 2,  0, 0,  0 }, { 2, 3,  0, 0,  0 },
        };
        for (size_t i = 0; i < sizeof(kCap)/sizeof(kCap[0]); ++i)
            if (RS::raceLevelCap(kCap[i].ci,
                    (RS::CharRace)kCap[i].r,
                    (uint8_t)kCap[i].s,
                    (uint8_t)kCap[i].s,
                    (uint8_t)kCap[i].dex) != kCap[i].cap)
                ++bad;
        // the goblin-kind and giant-kind to-hit lists
        static const struct {
            int r; const char* foe; int bonus; int pen;
        } kFoe[] = {
            { 1, "half-orc",   1, 0 }, { 1, "goblin", 1, 0 },
            { 1, "hobgoblin",  1, 0 }, { 1, "orc",    1, 0 },
            { 1, "gnoll",      0, 0 }, { 1, "kobold", 0, 0 },
            { 1, "ogre",       0, 4 }, { 1, "troll",  0, 4 },
            { 1, "ogre mage",  0, 4 }, { 1, "giant",  0, 4 },
            { 1, "titan",      0, 4 },
            { 1, "gnoll",      0, 0 },   // dwarf: no gnoll pen
            { 1, "bugbear",    0, 0 },
            { 3, "kobold",     1, 0 }, { 3, "goblin", 1, 0 },
            { 3, "orc",        0, 0 },
            { 3, "gnoll",      0, 4 }, { 3, "bugbear", 0, 4 },
            { 3, "ogre",       0, 4 }, { 3, "troll",   0, 4 },
            { 3, "ogre mage",  0, 4 }, { 3, "giant",  0, 4 },
            { 3, "titan",      0, 4 },
            { 0, "goblin",     0, 0 }, { 2, "ogre",   0, 0 },
            { 4, "goblin",     0, 0 },
        };
        for (size_t i = 0; i < sizeof(kFoe)/sizeof(kFoe[0]); ++i)
            if (RS::raceBonusVsFoeName((RS::CharRace)kFoe[i].r,
                    kFoe[i].foe) != kFoe[i].bonus
                || RS::raceFoeAttackPenalty(
                    (RS::CharRace)kFoe[i].r,
                    kFoe[i].foe) != kFoe[i].pen)
                ++bad;
        // the detection lists, in-N pairs + spot percents
        static const struct {
            int r; RS::DetectKind k; int num; int den;
        } kDet[] = {
            { 1, RS::DET_GRADE,           3,  4 },
            { 1, RS::DET_NEW_CONSTRUCTION, 3,  4 },
            { 1, RS::DET_SLIDING_WALLS,   4,  6 },
            { 1, RS::DET_STONE_TRAPS,      2,  4 },
            { 1, RS::DET_DEPTH,            1,  2 },
            { 3, RS::DET_GRADE,            8, 10 },
            { 3, RS::DET_UNSAFE_SURFACES,  7, 10 },
            { 3, RS::DET_DEPTH,            6, 10 },
            { 3, RS::DET_DIRECTION,        1,  2 },
            { 5, RS::DET_GRADE,            3,  4 },
            { 5, RS::DET_DIRECTION,        1,  2 },
            { 2, RS::DET_SECRET_PASS,      1,  6 },
            { 2, RS::DET_SECRET_SEARCH,     2,  6 },
            { 2, RS::DET_CONCEALED_SEARCH,  3,  6 },
            { 4, RS::DET_SECRET_PASS,      1,  6 },
            { 4, RS::DET_SECRET_SEARCH,     2,  6 },
            { 4, RS::DET_CONCEALED_SEARCH,  3,  6 },
        };
        for (size_t i = 0; i < sizeof(kDet)/sizeof(kDet[0]); ++i) {
            RS::ChanceIn c = RS::raceDetectChance(
                (RS::CharRace)kDet[i].r, kDet[i].k);
            if (c.num != kDet[i].num || c.den != kDet[i].den)
                ++bad;
        }
        // a race with no entry reads 0-in-0 (and pct 0)
        for (int r = 0; r < 7; ++r) {
            RS::ChanceIn c = RS::raceDetectChance(
                (RS::CharRace)r, RS::DET_SLIDING_WALLS);
            bool dwarf = (r == RS::RACE_DWARF);
            if (dwarf != (c.num == 4 && c.den == 6)) ++bad;
            if (RS::raceDetectPct((RS::CharRace)r,
                    RS::DET_SLIDING_WALLS) != (dwarf ? 66 : 0))
                ++bad;
        }
        if (RS::raceDetectPct(RS::RACE_DWARF,
                RS::DET_GRADE) != 75
            || RS::raceDetectPct(RS::RACE_ELF,
                RS::DET_SECRET_PASS) != 16) ++bad;
        // applyRacialAdjustments + eligibility spot checks
        RS::AbilityScores s;
        s.str = 18; s.con = 18; s.cha = 18;
        RS::applyRacialAdjustments(s, RS::RACE_DWARF, false);
        if (s.str != 18 || s.con != 19 || s.cha != 16) ++bad;
        s.str = 18; s.dex = 18; s.con = 18;
        RS::applyRacialAdjustments(s, RS::RACE_ELF, false);
        if (s.str != 18 || s.dex != 19 || s.con != 17) ++bad;
        s.str = 18; s.dex = 18;
        RS::applyRacialAdjustments(s, RS::RACE_ELF, true);
        if (s.str != 16) ++bad;   // female STR max 16
        s.str = 18; s.dex = 18; s.con = 18;
        RS::applyRacialAdjustments(s, RS::RACE_HALFLING, false);
        if (s.str != 17 || s.dex != 18) ++bad;
        s.str = 18; s.con = 18; s.cha = 18;
        RS::applyRacialAdjustments(s, RS::RACE_HALF_ORC, false);
        // STR 18+1 clamps to the 18 max, CON reaches 19,
        // CHA 18-2 = 16 clamps to the 12 max (Table III)
        if (s.str != 18 || s.con != 19 || s.cha != 12) ++bad;
        RS::AbilityScores e;
        e.con = 11;
        if (!RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;
        e.con = 10;
        if (RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;
        e.con = 18; e.str = 7;
        if (!RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false))
            ++bad;
        e.str = 6;
        if (RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false)) ++bad;
        printf("R154 PC races audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R155: classed monsters audit ------------------------
    // DMG p.80 matrix II.C: a monster with class abilities
    // saves on its MOST FAVORABLE matrix (footnotes 1-2). The
    // five MM1 classed write-ups (brownie, dolphin, displacer
    // beast, couatl, ki-rin) pin the saveAs data pass: the Lua
    // key parses into class bits + per-class levels, the +2
    // displacer die bonus rides the actor saveBonus, and the
    // displacer magicResistance no longer misreads as 12% MR.
    // Judgment left for a later lane: ixitxachitl (clerical,
    // per-leader) and the humanoid classed LEADERS are
    // per-encounter extras, not base-monster data.
    {
        int bad = 0;
        // the couatl cell: MU 5 AND cleric 7 vs a fighter-6
        // base - matrix I rows: F6 {11,13,12,13,14}, MU5
        // {14,11,13,15,12}, C7 {7,11,10,13,12}; min
        // {7,11,10,13,12}
        int lvls[4] = {0, 5, 7, 0};
        static const int kCouatl[5] = { 7, 11, 10, 13, 12 };
        for (int c = 0; c < 5; ++c)
            if (rules::mostFavorableSaveTarget(
                    rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC,
                    lvls, 0, 6,
                    (rules::SaveCategory)c) != kCouatl[c])
                ++bad;
        // the brownie cell: cleric 9 beats a fighter-3 base
        // (F3 = the 1-2 band row {13,15,14,16,16})
        int bl[4] = {0, 0, 9, 0};
        static const int kBrownie[5] = { 7, 11, 10, 13, 12 };
        for (int c = 0; c < 5; ++c) {
            if (rules::mostFavorableSaveTarget(
                    rules::SAVE_AS_CLERIC, bl, 0, 3,
                    (rules::SaveCategory)c) != kBrownie[c])
                ++bad;
            if (rules::mostFavorableSaveTarget(0, bl, 0, 3,
                    (rules::SaveCategory)c) !=
                    rules::saveTarget(0, 3, (rules::SaveCategory)c))
                ++bad;
        }
        // the zero-bit skip: a set bit with level 0 must not
        // tighten the fighter 0-level row (spells 19)
        int z[4] = {0, 0, 0, 0};
        if (rules::mostFavorableSaveTarget(
                rules::SAVE_AS_THIEF, z, 0, 0,
                rules::SAVE_SPELLS) != 19)
            ++bad;
        // the five MM1 write-ups, via the registry
        const monsters::MonsterDef* d = reg.find("brownie");
        if (!d || d->saveAsMask != rules::SAVE_AS_CLERIC ||
                d->saveAsLevels[2] != 9 || d->saveAsBonus != 0)
            ++bad;
        d = reg.find("dolphin");
        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||
                d->saveAsLevels[0] != 4)
            ++bad;
        d = reg.find("displacer_beast");
        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||
                d->saveAsLevels[0] != 12 || d->saveAsBonus != 2 ||
                d->magicResist != 0)
            ++bad;
        d = reg.find("couatl");
        if (!d || d->saveAsMask !=
                (rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC)
            || d->saveAsLevels[1] != 5 || d->saveAsLevels[2] != 7)
            ++bad;
        d = reg.find("ki_rin");
        if (!d || d->saveAsMask != rules::SAVE_AS_MAGIC_USER ||
                d->saveAsLevels[1] != 18)
            ++bad;
        // and the actor carry: the displacer holds the +2 die
        // bonus and the fighter-12 bits. asTarget() lives in
        // ai/actor.cpp, outside the battery link (step 2 links
        // no ai TU) - the header fields are checked here; the
        // carry itself rides the syntax gate (step 1 compiles
        // ai/actor.cpp), the R147 convention.
        {
            rules::Rng rngX(1);
            rules::Dice diceX(rngX);
            ai::Actor a = reg.toActor("displacer_beast", diceX);
            if (a.saveAsMask != rules::SAVE_AS_FIGHTER ||
                    a.saveAsBonus != 2 || a.saveAsLevels[0] != 12)
                ++bad;
        }
        printf("R155 classed monsters audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R156: convention party audit --------------------
    // DMG pp.225-226 Appendix P: rollMemberMagic gains its
    // first engine caller - rollConventionParty builds the
    // encounter-shaped party from caller-chosen classes, the
    // band/option level roll, and the R147 kit tables; the
    // member roller also lands the six 4d6-best-of scores.
    {
        int bad = 0;
        // the member roller: the level stays in the band,
        // the six scores stay in 3-18, the kit in 0-3, and
        // the class clamps
        {
            rules::Rng rngC(20261004);
            rules::Dice diceC(rngC);
            for (int b = 0; b < 3; ++b)
                for (int o = 0; o < 3; ++o)
                    for (int c = 0; c < 4; ++c)
                        for (int t = 0; t < 40; ++t) {
                            dm::appendixp::SpurMember m =
                                dm::appendixp::rollSpurMember(
                                    diceC, b, o, c);
                            if (m.classIndex != c) ++bad;
                            if (m.level <
                                    dm::appendixp::bandLevelLo(b, o)
                                || m.level >
                                    dm::appendixp::bandLevelHi(b, o))
                                ++bad;
                            for (int a = 0; a < 6; ++a)
                                if (m.abilities[a] < 3 ||
                                    m.abilities[a] > 18) ++bad;
                            if (m.kit.armorPlus < 0 ||
                                m.kit.armorPlus > 3 ||
                                m.kit.weaponPlus < 0 ||
                                m.kit.weaponPlus > 3 ||
                                m.kit.shieldPlus < 0 ||
                                m.kit.shieldPlus > 3) ++bad;
                        }
            dm::appendixp::SpurMember m9 =
                dm::appendixp::rollSpurMember(diceC, 0, 0, 9);
            if (m9.classIndex != 3) ++bad;
        }
        // the party generator: sizes clamp 1-9, each member
        // maps its replayed spur member (same seed = the
        // same dice stream), levels stay in the band, and a
        // null class list lands fighters
        {
            rules::Rng rngA(424242);
            rules::Dice diceA(rngA);
            int cls[5] = {0, 1, 2, 3, 1};
            dm::CharacterParty p =
                dm::rollConventionParty(diceA, 1, 1, cls, 5);
            if (p.size() != 5) ++bad;
            rules::Rng rngB(424242);
            rules::Dice diceB(rngB);
            for (int i = 0; i < 5; ++i) {
                dm::appendixp::SpurMember s =
                    dm::appendixp::rollSpurMember(
                        diceB, 1, 1, cls[i]);
                const dm::PartyMember& pm = p.members[i];
                if (pm.classIndex != s.classIndex ||
                    pm.level != s.level ||
                    pm.armPlus != s.kit.armorPlus ||
                    pm.wpnPlus != s.kit.weaponPlus ||
                    pm.shdPlus != s.kit.shieldPlus) ++bad;
                if (pm.level < 5 || pm.level > 8) ++bad;
            }
            dm::CharacterParty tiny =
                dm::rollConventionParty(diceA, 2, 2, nullptr, -3);
            if (tiny.size() != 1) ++bad;
            int cls9[12];
            for (int i = 0; i < 12; ++i) cls9[i] = i % 4;
            dm::CharacterParty big =
                dm::rollConventionParty(diceA, 0, 0, cls9, 12);
            if (big.size() != 9) ++bad;
            dm::CharacterParty nul =
                dm::rollConventionParty(diceA, 0, 2, nullptr, 3);
            for (int i = 0; i < 3; ++i)
                if (nul.members[i].classIndex != 0) ++bad;
        }
        printf("R156 convention party audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R157: grenade-like missiles audit ---------------
    // DMG pp.64-65: the thrown-flask layer - container
    // sizes, the effect table (direct-hit and splash dice
    // pairs), the 3-inch range bands, the item-save break
    // rule (the p.80 matrix rows: ceramic flask 18/12,
    // crystal vial 19/14), the 3-foot splash-save radius,
    // the d6/d8 miss tables (the direction cone), the p.65
    // holy/unholy water targeting, the flaming-oil
    // crossing damage, the 2-5 gp vial cost and the p.64
    // boulder drops.
    {
        int bad = 0;
        // sizes and names
        static const int kOz[5] = { 8, 4, 4, 16, 4 };
        for (int k = 0; k < 5; ++k) {
            if (rules::grenadeSizeOz((rules::GrenadeKind)k)
                != kOz[k]) ++bad;
            if (!*rules::grenadeName((rules::GrenadeKind)k))
                ++bad;
        }
        // the effect table
        static const int kDLo[5] = { 2, 2, 2, 2, 0 };
        static const int kDHi[5] = { 8, 7, 7, 12, 0 };
        static const int kDia[5] = { 1, 1, 1, 3, 1 };
        static const int kSLo[5] = { 1, 2, 2, 1, 0 };
        static const int kSHi[5] = { 1, 2, 2, 3, 0 };
        for (int k = 0; k < 5; ++k) {
            int lo, hi;
            rules::grenadeDirectHit((rules::GrenadeKind)k, lo, hi);
            if (lo != kDLo[k] || hi != kDHi[k]) ++bad;
            rules::grenadeSplashDamage(
                (rules::GrenadeKind)k, lo, hi);
            if (lo != kSLo[k] || hi != kSHi[k]) ++bad;
            if (rules::grenadeSplashDiameterFeet(
                    (rules::GrenadeKind)k) != kDia[k]) ++bad;
        }
        // oil: the second-round burn + the segment burn
        int olo, ohi;
        rules::grenadeOilSecondRound(olo, ohi);
        if (olo != 1 || ohi != 6) ++bad;
        if (rules::grenadeOilBurnSegmentsMax() != 3 ||
            rules::grenadeOilBurnDamagePerSegment() != 1)
            ++bad;
        // the splash-save radius
        if (rules::grenadeSplashRadiusFeet() != 3) ++bad;
        // range bands
        if (rules::grenadeRangeMaxInches() != 3) ++bad;
        if (rules::grenadeRangeToHitAdj(1) != 0 ||
            rules::grenadeRangeToHitAdj(2) != -2 ||
            rules::grenadeRangeToHitAdj(3) != -5) ++bad;
        // the break saves (the p.80 matrix rows)
        static const int kCrush[5] = { 18, 19, 19, 18, 19 };
        static const int kNorm[5]  = { 12, 14, 14, 12, 14 };
        for (int k = 0; k < 5; ++k) {
            if (rules::grenadeBreakSaveCrushing(
                    (rules::GrenadeKind)k) != kCrush[k] ||
                rules::grenadeBreakSaveNormal(
                    (rules::GrenadeKind)k) != kNorm[k]) ++bad;
        }
        // the miss tables: distance dice + direction cone
        {
            rules::Rng rngG(20261005);
            rules::Dice diceG(rngG);
            for (int t = 0; t < 500; ++t) {
                int d6 = rules::grenadeMissDistance(diceG, false);
                int d4 = rules::grenadeMissDistance(diceG, true);
                int dir = rules::grenadeMissDirection(diceG);
                if (d6 < 1 || d6 > 6) ++bad;
                if (d4 < 1 || d4 > 4) ++bad;
                if (dir < 1 || dir > 8) ++bad;
                if (!*rules::grenadeMissDirectionName(dir))
                    ++bad;
            }
            std::string n1 = rules::grenadeMissDirectionName(1);
            std::string n4 = rules::grenadeMissDirectionName(4);
            std::string n5 = rules::grenadeMissDirectionName(5);
            std::string n8 = rules::grenadeMissDirectionName(8);
            if (n1 != "long right" || n4 != "short (before)" ||
                n5 != "short left" || n8 != "long (over)")
                ++bad;
        }
        // holy/unholy water targeting (p.65)
        if (!rules::holyWaterAffects(true, true, true) ||
            !rules::holyWaterAffects(true, false, true) ||
            !rules::holyWaterAffects(false, true, true) ||
            rules::holyWaterAffects(false, false, true) ||
            rules::holyWaterAffects(true, true, false))
            ++bad;
        if (!rules::unholyWaterAffects(true, true) ||
            rules::unholyWaterAffects(false, true) ||
            rules::unholyWaterAffects(true, false))
            ++bad;
        // crossing flaming oil + the vial cost
        int wlo, whi;
        rules::flamingOilWalkDamage(wlo, whi);
        if (wlo != 1 || whi != 6) ++bad;
        if (rules::grenadeVialCostLo() != 2 ||
            rules::grenadeVialCostHi() != 5) ++bad;
        // boulders: diameters + the drop window
        if (rules::grenadeBoulderDiameterFeet(false) != 1 ||
            rules::grenadeBoulderDiameterFeet(true) != 2)
            ++bad;
        if (rules::grenadeBoulderDropDamage(14, 10) != 10 ||
            rules::grenadeBoulderDropDamage(14, 60) != 60 ||
            rules::grenadeBoulderDropDamage(14, 100) != 60 ||
            rules::grenadeBoulderDropDamage(28, 30) != 60 ||
            rules::grenadeBoulderDropDamage(14, 5) != 10 ||
            rules::grenadeBoulderDropDamage(13, 60) != 0)
            ++bad;
        // roller smoke: bounds sweeps
        {
            rules::Rng rngH(777);
            rules::Dice diceH(rngH);
            for (int t = 0; t < 400; ++t) {
                for (int k = 0; k < 5; ++k) {
                    int lo, hi;
                    rules::grenadeDirectHit(
                        (rules::GrenadeKind)k, lo, hi);
                    int v = rules::rollGrenadeDirectHit(
                        diceH, (rules::GrenadeKind)k);
                    if (v < lo || v > hi) ++bad;
                    rules::grenadeSplashDamage(
                        (rules::GrenadeKind)k, lo, hi);
                    int s = rules::rollGrenadeSplashDamage(
                        diceH, (rules::GrenadeKind)k);
                    if (s < lo || s > hi) ++bad;
                }
                int o = rules::rollGrenadeOilSecondRound(diceH);
                if (o < 1 || o > 6) ++bad;
                int w = rules::rollFlamingOilWalkDamage(diceH);
                if (w < 1 || w > 6) ++bad;
                int b = rules::rollGrenadeBoulderFlatDamage(
                    diceH, 28);
                if (b < 2 || b > 12) ++bad;
                if (rules::rollGrenadeBoulderFlatDamage(
                        diceH, 13) != 0) ++bad;
            }
        }
        printf("R157 grenade missiles audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R158: weapon speed factors audit ---------------
    // DMG p.66 + the PHB p.38 factor column: the tie order
    // (lower factor first), the extra-attacks windows, and
    // the weapon-vs-spell strike segment (factor minus the
    // losing initiative die, negatives as positive).
    {
        int bad = 0;
        // the named factor table (PHB p.38 + the DMG examples)
        static const char* const kN[9] = {
            "fist", "dagger", "short sword", "hammer",
            "long sword", "broad sword", "two-handed sword",
            "pike", "quarterstaff"
        };
        static const int kSf[9] = { 1, 2, 3, 4, 5, 5, 10, 13, 4 };
        for (int i = 0; i < 9; ++i) {
            if (rules::weaponSpeedFactor(kN[i]) != kSf[i])
                ++bad;
        }
        static const char* const kN2[8] = {
            "club", "hand axe", "scimitar", "horseman mace",
            "horseman flail", "footman mace", "footman flail",
            "morning star"
        };
        static const int kSf2[8] = { 4, 4, 4, 6, 6, 7, 7, 7 };
        for (int i = 0; i < 8; ++i) {
            if (rules::weaponSpeedFactor(kN2[i]) != kSf2[i])
                ++bad;
        }
        if (rules::weaponSpeedFactor("spear") != 7) ++bad;
        if (rules::weaponSpeedFactor("no such weapon") != 0)
            ++bad;
        // the spear 6-8 print range
        int rlo, rhi;
        rules::spearSpeedFactorRange(rlo, rhi);
        if (rlo != 6 || rhi != 8) ++bad;
        // case 1: the DMG example chain (lower strikes first)
        if (rules::speedFactorFirst(1, 2) != -1 ||
            rules::speedFactorFirst(2, 3) != -1 ||
            rules::speedFactorFirst(3, 4) != -1 ||
            rules::speedFactorFirst(4, 1) != 1 ||
            rules::speedFactorFirst(5, 5) != 0) ++bad;
        // case 2: the extra-attack windows
        if (rules::speedFactorAttacksBefore(1, 2) != 1 ||
            rules::speedFactorAttacksBefore(2, 4) != 1 ||
            rules::speedFactorAttacksBefore(1, 4) != 2 ||
            rules::speedFactorAttacksBefore(3, 10) != 2 ||
            rules::speedFactorAttacksBefore(5, 10) != 2 ||
            rules::speedFactorAttacksBefore(2, 13) != 3 ||
            rules::speedFactorAttacksBefore(2, 12) != 3 ||
            rules::speedFactorAttacksBefore(5, 5) != 1) ++bad;
        // case 2: closing/charging exemption
        if (rules::speedFactorApplies(true) ||
            !rules::speedFactorApplies(false)) ++bad;
        // case 3: the strike segment (negatives as positive)
        if (rules::weaponVsActivitySegment(5, 1) != 4 ||
            rules::weaponVsActivitySegment(5, 2) != 3 ||
            rules::weaponVsActivitySegment(5, 3) != 2 ||
            rules::weaponVsActivitySegment(5, 5) != 0 ||
            rules::weaponVsActivitySegment(2, 3) != 1 ||
            rules::weaponVsActivitySegment(2, 4) != 2 ||
            rules::weaponVsActivitySegment(2, 5) != 3 ||
            rules::weaponVsActivitySegment(10, 1) != 9 ||
            rules::weaponVsActivitySegment(10, 6) != 4) ++bad;
        // case 3: the fireball example (casting 3 segments)
        if (rules::weaponVsActivityOrder(4, 3) != 1 ||
            rules::weaponVsActivityOrder(3, 3) != 0 ||
            rules::weaponVsActivityOrder(2, 3) != -1 ||
            rules::weaponVsActivityOrder(1, 3) != -1 ||
            rules::weaponVsActivityOrder(0, 3) != -1 ||
            rules::weaponVsActivityOrder(9, 3) != 1) ++bad;
        // simultaneous: no factor modification
        if (rules::speedFactorModifiedWhenSimultaneous())
            ++bad;
        printf("R158 weapon speed factors audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R159: striking to subdue audit ---------------
    // DMG p.67: the 75/25 accounting, applicability, the
    // knockout threshold; the MM dragon capture: the kind
    // table, the int gate, the percent ratio (the example
    // rounds), the automatic subdual, the sale price.
    {
        int bad = 0;
        // the 75/25 accounting
        if (rules::subdualTemporaryPct() != 75 ||
            rules::subdualRealPct() != 25) ++bad;
        if (rules::subdualRealDamage(40) != 10) ++bad;
        if (rules::subdualRealDamage(8) != 2 ||
            rules::subdualRealDamage(4) != 1 ||
            rules::subdualRealDamage(1) != 0 ||
            rules::subdualRealDamage(0) != 0 ||
            rules::subdualRealDamage(-5) != 0) ++bad;
        // applicability: MM-stated or humanoid, never PCs
        if (!rules::subdualEffectiveAgainst(true, false) ||
            rules::subdualEffectiveAgainst(false, false) ||
            rules::subdualEffectiveAgainst(true, true))
            ++bad;
        // the knockout threshold
        if (!rules::subdualKnockout(10, 10) ||
            !rules::subdualKnockout(11, 10) ||
            rules::subdualKnockout(9, 10) ||
            !rules::subdualKnockout(3, 0)) ++bad;
        // the dragon kind table
        if (!rules::dragonSubduable(rules::DRAGON_BRASS) ||
            !rules::dragonSubduable(rules::DRAGON_BRONZE) ||
            !rules::dragonSubduable(rules::DRAGON_COPPER) ||
            rules::dragonSubduable(rules::DRAGON_WHITE) ||
            rules::dragonSubduable(rules::DRAGON_BLACK) ||
            rules::dragonSubduable(rules::DRAGON_GREEN) ||
            rules::dragonSubduable(rules::DRAGON_BLUE) ||
            rules::dragonSubduable(rules::DRAGON_RED) ||
            rules::dragonSubduable(rules::DRAGON_SILVER) ||
            rules::dragonSubduable(rules::DRAGON_GOLD) ||
            rules::dragonSubduable(rules::DRAGON_PLATINUM))
            ++bad;
        // the attacker int gate (average = 9)
        if (rules::subduableByAttackerInt(8) ||
            !rules::subduableByAttackerInt(9) ||
            !rules::subduableByAttackerInt(12)) ++bad;
        // the announce-before-combat convention
        if (!rules::subdualFormIsKilling(false) ||
            rules::subdualFormIsKilling(true)) ++bad;
        // the percent ratio: the MM example rounds
        if (rules::dragonSubdualPercent(44, 88) != 50 ||
            rules::dragonSubdualPercent(67, 88) != 76 ||
            rules::dragonSubdualPercent(77, 88) != 88 ||
            rules::dragonSubdualPercent(0, 88) != 0 ||
            rules::dragonSubdualPercent(1, 8) != 13 ||
            rules::dragonSubdualPercent(88, 88) != 100 ||
            rules::dragonSubdualPercent(176, 88) != 200) ++bad;
        // percentile sweep + the automatic subdual
        {
            rules::Rng rngS(20261006);
            rules::Dice diceS(rngS);
            int hi = 0, loSeen = false, hiSeen = false;
            for (int t = 0; t < 600; ++t) {
                int roll = (int)diceS.roll(1, 100, 0);
                if (roll < 1 || roll > 100) ++bad;
                if (roll > hi) hi = roll;
            }
            // a 100% ratio: every roll subdues
            for (int t = 0; t < 50; ++t)
                if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;
            // the MM example states: automatic at 1:1
            if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;
            // a 0% ratio: only a rolled 1 edge (roll 1 <= 0
            // is false; nothing subdues)
            for (int t = 0; t < 50; ++t)
                if (rules::dragonSubdued(diceS, 0, 88)) ++bad;
            // price sweep: 100-800 gp per hit point
            for (int t = 0; t < 200; ++t) {
                int p = rules::subduedDragonPricePerHp(diceS);
                if (p < 100 || p > 800 || p % 100 != 0) ++bad;
            }
            (void)hi; (void)loSeen; (void)hiSeen;
        }
        if (!rules::subduedDragonRideable()) ++bad;
        printf("R159 striking to subdue audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R160: weaponless combat audit --------------------
    // DMG pp.72-73: pummel, grapple, overbear - the three
    // tables, the base scores, the modifier lists, the
    // damage accounting, the initiative priority, the
    // hold ladder and the general notes.
    {
        int bad = 0;
        // the tier tables: boundary sweeps + damage bases
        static const int kPumScores[14] = {
            -5, 0, 1, 20, 21, 40, 41, 60, 61, 80, 81, 100,
            101, 250
        };
        static const int kPumIdx[14] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6
        };
        static const int kPumDmg[7] = { 0, 0, 2, 4, 6, 8, 10 };
        for (int i = 0; i < 14; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_PUMMEL, kPumScores[i]);
            if (idx != kPumIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_PUMMEL, i) != kPumDmg[i]) ++bad;
        static const int kGraScores[14] = {
            -5, 20, 21, 40, 41, 55, 56, 70, 71, 85, 86, 95,
            96, 300
        };
        static const int kGraIdx[14] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6
        };
        static const int kGraDmg[7] = { 0, 1, 2, 3, 5, 6, 8 };
        for (int i = 0; i < 14; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_GRAPPLE, kGraScores[i]);
            if (idx != kGraIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_GRAPPLE, i) != kGraDmg[i]) ++bad;
        static const int kOvbScores[12] = {
            -5, 20, 21, 40, 41, 60, 61, 80, 81, 100, 101, 400
        };
        static const int kOvbIdx[12] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
        };
        static const int kOvbDmg[6] = { 0, 0, 1, 2, 3, 4 };
        for (int i = 0; i < 12; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_OVERBEAR, kOvbScores[i]);
            if (idx != kOvbIdx[i]) ++bad;
        }
        for (int i = 0; i < 6; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_OVERBEAR, i) != kOvbDmg[i]) ++bad;
        // tier names non-empty
        for (int k = 0; k < 3; ++k) {
            int n = 0;
            const rules::WeaponlessTier* t =
                rules::weaponlessTiers(
                    (rules::WeaponlessKind)k, n);
            for (int i = 0; i < n; ++i)
                if (!t[i].name || !*t[i].name) ++bad;
        }
        // base scores
        if (rules::pummelBaseChance(10) != 100 ||
            rules::pummelBaseChance(9) != 90 ||
            rules::pummelBaseChance(0) != 0 ||
            rules::pummelBaseChance(-1) != -10 ||
            rules::pummelBaseChance(3) != 30) ++bad;
        if (rules::grappleBaseChance(5, 2) != 52 ||
            rules::grappleBaseChance(10, 0) != 100 ||
            rules::grappleBaseChance(0, 3) != 3) ++bad;
        // pummel base-chance modifiers
        if (rules::pummelHitAdj(15, 0, 0, false, false,
                               12, false) != 15 ||
            rules::pummelHitAdj(0, 1, 0, false, false,
                               12, false) != 1 ||
            rules::pummelHitAdj(0, 0, -2, false, false,
                               12, false) != 2 ||
            rules::pummelHitAdj(0, 0, 9, false, false,
                               12, false) != 9 ||
            rules::pummelHitAdj(0, 0, 0, true, false,
                               12, false) != 10 ||
            rules::pummelHitAdj(0, 0, 0, false, true,
                               12, false) != 20 ||
            rules::pummelHitAdj(0, 0, 0, true, true,
                               12, false) != 30 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               15, false) != -5 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               12, true) != -10 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               15, true) != -15) ++bad;
        if (!rules::pummelAutomaticHit(true) ||
            rules::pummelAutomaticHit(false)) ++bad;
        // pummel strike modifiers
        if (rules::pummelStrikeAdj(3, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 3 ||
            rules::pummelStrikeAdj(0, 10, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 2 ||
            rules::pummelStrikeAdj(0, 20, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 4 ||
            rules::pummelStrikeAdj(0, 0,
                rules::WLP_WOODEN_MAILED,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 5 ||
            rules::pummelStrikeAdj(0, 0,
                rules::WLP_METAL_POMMEL,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, true, true, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 50 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 2, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != -4 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, true,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_LEATHER_PADDED, false,
                rules::WLH_NONE) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_CHAIN_RING_SCALE, false,
                rules::WLH_NONE) != -20 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, true,
                rules::WLH_NONE) != -30 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_BANDED_PLATE_SPLINT, true,
                rules::WLH_NONE) != -70 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_OPEN) != -5 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NASALED) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_VISORED) != -20) ++bad;
        // grapple base modifiers
        if (rules::grappleBaseAdj(14, rules::WLA_NONE,
                false, 0, false) != 14 ||
            rules::grappleBaseAdj(0,
                rules::WLA_LEATHER_PADDED, false, 0,
                false) != 10 ||
            rules::grappleBaseAdj(0,
                rules::WLA_CHAIN_RING_SCALE, false, 0,
                false) != 20 ||
            rules::grappleBaseAdj(0,
                rules::WLA_BANDED_PLATE_SPLINT, false, 0,
                false) != 30 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                true, 0, false) != 20 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                false, 2, false) != -20 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                false, 0, true) != -20) ++bad;
        // grapple hold modifiers
        if (rules::grappleHoldAdj(5, 5, 0, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 10, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 1 ||
            rules::grappleHoldAdj(0, 0, 0, true, true,
                true, 0, 0, 0, 0, 0, false, false,
                false) != 60 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 20, 0, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, -10, 0, 0, 0, 0, false, false,
                false) != -5 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 20, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 3, 0, 0, false, false,
                false) != -6 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 2, 0, false, false,
                false) != -2 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 10, false, false,
                false) != -1 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 0, true, true,
                true) != -30) ++bad;
        // overbear modifiers
        if (rules::overbearAdj(3, 0, false, false, false,
                0, 0, 0, 0, 0, false) != 3 ||
            rules::overbearAdj(0, 10, false, false, false,
                0, 0, 0, 0, 0, false) != 2 ||
            rules::overbearAdj(0, 0, true, false, false,
                0, 0, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, true, false,
                0, 0, 0, 0, 0, false) != 15 ||
            rules::overbearAdj(0, 0, false, false, true,
                0, 0, 0, 0, 0, false) != 20 ||
            rules::overbearAdj(0, 0, false, false, false,
                10, 0, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 20, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 2, 0, 0, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 10, 0, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 1, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 0, true) != -10) ++bad;
        // the damage accounting
        if (rules::weaponlessActualPct(rules::WL_PUMMEL) != 25
            || rules::weaponlessActualPct(
                   rules::WL_GRAPPLE) != 25
            || rules::weaponlessActualPct(
                   rules::WL_OVERBEAR) != 50) ++bad;
        if (rules::weaponlessHealPerRound() != 1) ++bad;
        if (rules::weaponlessUnconsciousRounds(0) != 1 ||
            rules::weaponlessUnconsciousRounds(4) != 5 ||
            rules::weaponlessUnconsciousRounds(7) != 8 ||
            rules::weaponlessUnconsciousRounds(-3) != 1)
            ++bad;
        if (rules::weaponlessTrussRounds() != 1) ++bad;
        if (rules::weaponlessPummelAttacksPerRound() != 2)
            ++bad;
        if (!rules::grappleAttackAndCounterPerRound() ||
            !rules::grappleHoldActsFirst()) ++bad;
        if (rules::grappleHandsFree(true) ||
            !rules::grappleHandsFree(false)) ++bad;
        if (!rules::overbearAllowsOccupiedHands() ||
            !rules::overbearRequiresFollowUp()) ++bad;
        // the shared variable: bounds sweeps
        {
            rules::Rng rngW(20261007);
            rules::Dice diceW(rngW);
            for (int t = 0; t < 500; ++t) {
                int av = rules::weaponlessVariable(
                    diceW, 1, true);
                int dv = rules::weaponlessVariable(
                    diceW, 2, false);
                if (av < 2 || av > 7) ++bad;
                if (dv < 3 || dv > 6) ++bad;
            }
        }
        if (rules::weaponlessUnconsciousGetsVariable())
            ++bad;
        // initiative priority: surprise, charge, dex, roll
        if (rules::weaponlessInitiativeFirst(
                true, false, false, true, 10, 18, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, true, true, false, 18, 10, 6, 1) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, true, false, 10, 18, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 16, 12, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 16, 1, 6) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 5, 3) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 3, 5) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 4, 4) != 0)
            ++bad;
        // the hold ladder + the stunned counter rule
        if (!rules::grappleHoldBreaks(1, 0) ||
            rules::grappleHoldBreaks(0, 1) ||
            rules::grappleHoldBreaks(2, 2) ||
            !rules::grappleStunnedAllowsImmediateSecond())
            ++bad;
        // the general notes
        if (!rules::weaponlessWeaponWielderFirst(false) ||
            rules::weaponlessWeaponWielderFirst(true))
            ++bad;
        if (!rules::weaponlessBehindNegatesShieldAndDex())
            ++bad;
        if (!rules::bearLikeHuggerGrappples() ||
            !rules::weaponlessMonsterOverbears()) ++bad;
        if (!rules::monkOpenHandUnimpeded()) ++bad;
        printf("R160 weaponless combat audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R161: attacks with two weapons audit --------
    // DMG p.70: the penalty ladder (primary -2, secondary
    // -4, eased above dex 15, never positive), the
    // dagger/hand-axe second-weapon gate, the no-parry
    // rule, the low-dex add-to-each rule, the discarded
    // shield.
    {
        int bad = 0;
        // the second-weapon gate
        if (!rules::twoWeaponSecondaryAllowed("dagger") ||
            !rules::twoWeaponSecondaryAllowed(
                "hand axe") ||
            rules::twoWeaponSecondaryAllowed("long sword")
            || rules::twoWeaponSecondaryAllowed("club") ||
            rules::twoWeaponSecondaryAllowed("spear") ||
            rules::twoWeaponSecondaryAllowed("")) ++bad;
        // the penalty ladder: dex 3 through 18
        static const int kDex[8] = { 3, 5, 6, 9, 15, 16, 17, 18 };
        static const int kPri[8] = { -2, -2, -2, -2, -2, -1, 0, 0 };
        static const int kSec[8] = { -4, -4, -4, -4, -4, -3, -2, -1 };
        for (int i = 0; i < 8; ++i) {
            if (rules::twoWeaponPrimaryPenalty(
                    kDex[i]) != kPri[i]) ++bad;
            if (rules::twoWeaponSecondaryPenalty(
                    kDex[i]) != kSec[i]) ++bad;
        }
        // never a positive rating, even at absurd dex
        if (rules::twoWeaponPrimaryPenalty(20) != 0 ||
            rules::twoWeaponPrimaryPenalty(25) != 0) ++bad;
        // the low-dex rule: dex below 6 adds to EACH
        if (!rules::twoWeaponLowDexAddsToEach(3) ||
            !rules::twoWeaponLowDexAddsToEach(5) ||
            rules::twoWeaponLowDexAddsToEach(6) ||
            rules::twoWeaponLowDexAddsToEach(9)) ++bad;
        // the secondary weapon never shields or parries
        if (rules::twoWeaponSecondaryParries()) ++bad;
        // fighting two-handed discards the shield
        if (rules::twoWeaponAllowsShield()) ++bad;
        printf("R161 two weapons audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R162: level title ladders audit ---------
    // PHB p.20-31: the printed per-level titles for
    // the four engine classes. The cleric level 5
    // title cell prints blank; JUDGMENT: it carries
    // the level 4 title down (Curate).
    {
        static const char* const kF[9] = {
            "Veteran", "Warrior", "Swordsman", "Hero",
            "Swashbuckler", "Myrmidon", "Champion",
            "Superhero", "Lord"
        };
        static const char* const kM[11] = {
            "Prestidigitator", "Evoker", "Conjurer",
            "Theurgist", "Thaumaturgist", "Magician",
            "Enchanter", "Warlock", "Sorcerer",
            "Necromancer", "Wizard"
        };
        static const char* const kC[9] = {
            "Acolyte", "Adept", "Priest", "Curate",
            "Curate", "Canon", "Lama", "Patriarch",
            "High Priest"
        };
        static const char* const kT[10] = {
            "Rogue (Apprentice)", "Footpad", "Cutpurse",
            "Robber", "Burglar", "Filcher", "Sharper",
            "Magsman", "Thief", "Master Thief"
        };
        int bad = 0;
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_FIGHTER, i + 1)) != kF[i])
                ++bad;
        for (int i = 0; i < 11; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_MAGIC_USER, i + 1)) != kM[i])
                ++bad;
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_CLERIC, i + 1)) != kC[i])
                ++bad;
        for (int i = 0; i < 10; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_THIEF, i + 1)) != kT[i])
                ++bad;
        // the clamp conventions: a level above the
        // cap reads the top title; level 0 or below
        // reads the first title; a bad class reads
        // Unknown
        if (std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 10)) != kF[8] ||
            std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 99)) != kF[8] ||
            std::string(rules::titleFor(
                rules::CLASS_MAGIC_USER, 12)) != kM[10] ||
            std::string(rules::titleFor(
                rules::CLASS_CLERIC, 10)) != kC[8] ||
            std::string(rules::titleFor(
                rules::CLASS_THIEF, 11)) != kT[9]) ++bad;
        if (std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 0)) != kF[0] ||
            std::string(rules::titleFor(
                rules::CLASS_THIEF, -3)) != kT[0]) ++bad;
        if (std::string(rules::titleFor(-1, 1)) != "Unknown" ||
            std::string(rules::titleFor(99, 1)) != "Unknown")
            ++bad;
        printf("R162 level title ladders audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R163: the poison table audit -------------
    // DMG p.20: the purchased-poison table - ingestive
    // A-E and insinuative A-D, each with cost, onset
    // (and unit), the damage classes, the footnote save
    // bonuses and detection chances - plus the class
    // rules and the blade-venom decay.
    {
        int bad = 0;
        // the ingestive column: A-E
        static const int kInCost[5] = { 5, 30, 200, 500, 1000 };
        static const int kInSaveDmg[5] = { 10, 15, 20, 25, 30 };
        static const int kInNoSaveDmg[5] = { 20, 30, 40, -1, -1 };
        static const int kInOnMin[5] = { 2, 2, 1, 1, 1 };
        static const int kInOnMax[5] = { 8, 5, 2, 1, 4 };
        for (int g = 0; g < 5; ++g) {
            if (rules::poisonCostPerDose(
                    rules::POISON_INGESTIVE, g) != kInCost[g])
                ++bad;
            if (rules::poisonDamageIfSave(
                    rules::POISON_INGESTIVE, g) != kInSaveDmg[g])
                ++bad;
            int nsd = rules::poisonDamageIfNoSave(
                rules::POISON_INGESTIVE, g);
            if (kInNoSaveDmg[g] == -1) {
                if (!rules::poisonKillsIfNoSave(
                        rules::POISON_INGESTIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInNoSaveDmg[g]) ++bad;
            if (rules::poisonOnsetMin(
                    rules::POISON_INGESTIVE, g) != kInOnMin[g] ||
                rules::poisonOnsetMax(
                    rules::POISON_INGESTIVE, g) != kInOnMax[g])
                ++bad;
            if (rules::poisonOnsetUnit(
                    rules::POISON_INGESTIVE, g)
                    != rules::POISON_UNIT_ROUND && g <= 2) ++bad;
        }
        // ingestive D reads segments, E turns
        if (rules::poisonOnsetUnit(
                rules::POISON_INGESTIVE, 3)
                != rules::POISON_UNIT_SEGMENT ||
            rules::poisonOnsetUnit(
                rules::POISON_INGESTIVE, 4)
                != rules::POISON_UNIT_TURN) ++bad;
        // the insinuative column: A-D
        static const int kInsCost[4] = { 10, 75, 600, 1500 };
        static const int kInsNoSaveDmg[4] = { 15, 25, 35, -1 };
        static const int kInsOnMin[4] = { 2, 1, 1, 1 };
        static const int kInsOnMax[4] = { 5, 3, 1, 1 };
        for (int g = 0; g < 4; ++g) {
            if (rules::poisonCostPerDose(
                    rules::POISON_INSINUATIVE, g) != kInsCost[g])
                ++bad;
            if (rules::poisonDamageIfSave(
                    rules::POISON_INSINUATIVE, g) != 0) ++bad;
            int nsd = rules::poisonDamageIfNoSave(
                rules::POISON_INSINUATIVE, g);
            if (kInsNoSaveDmg[g] == -1) {
                if (!rules::poisonKillsIfNoSave(
                        rules::POISON_INSINUATIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInsNoSaveDmg[g]) ++bad;
            if (rules::poisonOnsetMin(
                    rules::POISON_INSINUATIVE, g) != kInsOnMin[g] ||
                rules::poisonOnsetMax(
                    rules::POISON_INSINUATIVE, g) != kInsOnMax[g])
                ++bad;
            if (rules::poisonOnsetUnit(
                    rules::POISON_INSINUATIVE, g)
                != rules::POISON_UNIT_ROUND) ++bad;
        }
        // grade E is ingestive only
        if (rules::poisonGradeExists(
                rules::POISON_INSINUATIVE, 4) ||
            !rules::poisonGradeExists(
                rules::POISON_INSINUATIVE, 3) ||
            !rules::poisonGradeExists(
                rules::POISON_INGESTIVE, 4) ||
            rules::poisonGradeExists(
                rules::POISON_INGESTIVE, 5) ||
            rules::poisonGradeExists(
                rules::POISON_INGESTIVE, -1)) ++bad;
        // the footnotes: +4/+3/+2/+1 save, E none;
        // detection 80/65/40/15, E none
        static const int kBonus[5] = { 4, 3, 2, 1, 0 };
        static const int kDetect[5] = { 80, 65, 40, 15, 0 };
        for (int g = 0; g < 5; ++g) {
            if (rules::poisonVictimSaveBonus(
                    rules::POISON_INGESTIVE, g) != kBonus[g])
                ++bad;
            if (rules::poisonDetectChance(
                    rules::POISON_INGESTIVE, g) != kDetect[g])
                ++bad;
        }
        for (int g = 0; g < 4; ++g) {
            if (rules::poisonVictimSaveBonus(
                    rules::POISON_INSINUATIVE, g) != kBonus[g])
                ++bad;
            if (rules::poisonDetectChance(
                    rules::POISON_INSINUATIVE, g) != kDetect[g])
                ++bad;
        }
        // the user efficiency ladder
        if (rules::poisonUserEfficiencyAdj(true, true) != 0 ||
            rules::poisonUserEfficiencyAdj(true, false) != 1 ||
            rules::poisonUserEfficiencyAdj(false, true) != 2 ||
            rules::poisonUserEfficiencyAdj(false, false) != 2)
            ++bad;
        // monster poison: all-or-nothing, dual-use
        if (!rules::poisonMonsterAllOrNothing() ||
            !rules::poisonMonsterDualUse()) ++bad;
        // blade venom decay: full, half, gone
        if (rules::poisonBladeVenomPotencyPercent(0) != 100 ||
            rules::poisonBladeVenomPotencyPercent(1) != 50 ||
            rules::poisonBladeVenomPotencyPercent(2) != 0 ||
            rules::poisonBladeVenomPotencyPercent(3) != 0 ||
            !rules::poisonBladeVenomDecayedGivesSaveBonus(1) ||
            rules::poisonBladeVenomDecayedGivesSaveBonus(0))
            ++bad;
        printf("R163 poison table audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R164: the assassination table audit -------
    // DMG p.75: the assassins table - every printed
    // cell pinned, the dashes read as no chance, the
    // band mapping, the level clamps, and the
    // helpless-opponents footnote.
    {
        static const int kExp[15][10] = {
            { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },
            { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },
            { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },
            { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },
            { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },
            { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },
            { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },
            { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },
            { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },
            { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },
            { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },
            { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },
            { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },
            { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },
            { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }
        };
        int bad = 0;
        // every printed cell, through the band mapping
        for (int lvl = 1; lvl <= 15; ++lvl) {
            for (int v = 0; v <= 19; ++v) {
                int col = (v >= 18) ? 9 : v / 2;
                if (rules::assassinationChance(lvl, v)
                        != kExp[lvl - 1][col]) ++bad;
            }
        }
        // the dashes read as -1: no chance at all
        if (rules::assassinationChance(1, 12) != -1 ||
            rules::assassinationChance(1, 18) != -1 ||
            rules::assassinationChance(8, 18) != -1 ||
            rules::assassinationChance(9, 18) != -1)
            ++bad;
        // spot cells off the band edges: a level 18 and
        // a level 25 victim both read the 18+ column
        if (rules::assassinationChance(10, 18) != 1 ||
            rules::assassinationChance(10, 25) != 1 ||
            rules::assassinationChance(15, 18) != 30)
            ++bad;
        // the level clamps: below 1 reads row 1,
        // above 15 reads row 15
        if (rules::assassinationChance(0, 0) != 50 ||
            rules::assassinationChance(-2, 4) != 35 ||
            rules::assassinationChance(16, 0) != 100 ||
            rules::assassinationChance(20, 8) != 99)
            ++bad;
        // the victim band mapping
        if (rules::assassinationVictimBand(-5) != 0 ||
            rules::assassinationVictimBand(0) != 0 ||
            rules::assassinationVictimBand(1) != 0 ||
            rules::assassinationVictimBand(2) != 1 ||
            rules::assassinationVictimBand(3) != 1 ||
            rules::assassinationVictimBand(17) != 8 ||
            rules::assassinationVictimBand(18) != 9 ||
            rules::assassinationVictimBand(99) != 9)
            ++bad;
        // the helpless-opponents footnote
        if (!rules::assassinationTableCoversHelpless())
            ++bad;
        printf("R164 assassination table audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R165: potion miscibility audit ------------
    // DMG p.119: the miscibility d100 bands, the
    // trigger conditions, the explosion and poison
    // numbers, the boost, and the named campaign
    // options.
    {
        int bad = 0;
        // the band boundaries: probe every d100 face
        for (int r = 1; r <= 100; ++r) {
            rules::MiscibilityResult want;
            if (r == 1) want = rules::MISC_EXPLOSION;
            else if (r <= 3) want = rules::MISC_LETHAL_POISON;
            else if (r <= 8) want = rules::MISC_MILD_POISON;
            else if (r <= 15) want = rules::MISC_BOTH_DESTROYED;
            else if (r <= 25) want = rules::MISC_ONE_CANCELLED;
            else if (r <= 35) want = rules::MISC_BOTH_HALF;
            else if (r <= 90) want = rules::MISC_COMPATIBLE;
            else if (r <= 99) want = rules::MISC_ONE_BOOSTED;
            else want = rules::MISC_DISCOVERY;
            if (rules::miscibilityRoll(r) != want) ++bad;
        }
        // the clamps
        if (rules::miscibilityRoll(0) != rules::MISC_EXPLOSION ||
            rules::miscibilityRoll(-7) != rules::MISC_EXPLOSION ||
            rules::miscibilityRoll(101) != rules::MISC_DISCOVERY ||
            rules::miscibilityRoll(999) != rules::MISC_DISCOVERY)
            ++bad;
        // the trigger conditions
        if (!rules::miscibilityTestNeeded(true, false) ||
            !rules::miscibilityTestNeeded(false, true) ||
            rules::miscibilityTestNeeded(false, false)) ++bad;
        // the explosion numbers
        if (rules::miscibilityExplosionInternalMin() != 6 ||
            rules::miscibilityExplosionInternalMax() != 60 ||
            rules::miscibilityExplosionBlastNearMin() != 1 ||
            rules::miscibilityExplosionBlastNearMax() != 10 ||
            rules::miscibilityExplosionBlastNearRadius() != 5 ||
            rules::miscibilityExplosionBlastFarMin() != 4 ||
            rules::miscibilityExplosionBlastFarMax() != 24 ||
            rules::miscibilityExplosionBlastFarRadius() != 10)
            ++bad;
        // the mild poison duration and the gas cloud
        if (rules::miscibilityMildPoisonDurationMin() != 5 ||
            rules::miscibilityMildPoisonDurationMax() != 20 ||
            rules::miscibilityGasCloudRadius() != 10) ++bad;
        // the boost
        if (rules::miscibilityBoostPercent() != 150) ++bad;
        // the named campaign options
        if (!rules::miscibilityOptionDelusionMixes() ||
            !rules::miscibilityOptionTreasureFindingLethal() ||
            rules::miscibilityOptionEtherealLostPercent() != 50 ||
            rules::miscibilityOptionEtherealLostMinDays() != 5 ||
            rules::miscibilityOptionEtherealLostMaxDays() != 30)
            ++bad;
        printf("R165 potion miscibility audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R166: intoxication and insanity audit ------
    // DMG pp.82-83: the intoxication table, the
    // recovery table with the stimulant multipliers,
    // the comatose sleep, the 20 named insanity
    // forms with the mild-star and each form printed
    // numeric parameter, and the duration classes.
    {
        int bad = 0;
        // the intoxication table: slight/moderate/great
        static const int kBrave[3] = { 1, 2, 4 };
        static const int kMorale[3] = { 5, 10, 15 };
        static const int kInt[3] = { -1, -3, -6 };
        static const int kWis[3] = { -1, -4, -7 };
        static const int kDex[3] = { 0, -2, -5 };
        static const int kCha[3] = { 0, -1, -4 };
        static const int kAtk[3] = { 0, -1, -5 };
        static const int kHp[3] = { 0, 1, 3 };
        for (int i = 0; i < 3; ++i) {
            rules::IntoxState s =
                (i == 0) ? rules::INTOX_SLIGHT
                : (i == 1) ? rules::INTOX_MODERATE
                : rules::INTOX_GREAT;
            if (rules::intoxicationBraveryAdjust(s) != kBrave[i] ||
                rules::intoxicationMoraleAdjust(s) != kMorale[i] ||
                rules::intoxicationIntelligenceAdjust(s) != kInt[i] ||
                rules::intoxicationWisdomAdjust(s) != kWis[i] ||
                rules::intoxicationDexterityAdjust(s) != kDex[i] ||
                rules::intoxicationCharismaAdjust(s) != kCha[i] ||
                rules::intoxicationAttackDiceAdjust(s) != kAtk[i] ||
                rules::intoxicationHitPointAdjust(s) != kHp[i])
                ++bad;
        }
        // the magic-save raise rides the attack-dice
        // number: 1/5 points, 5/25 percent
        if (rules::intoxicationMagicSaveRaise(
                rules::INTOX_MODERATE) != 1 ||
            rules::intoxicationMagicSaveRaise(
                rules::INTOX_GREAT) != 5 ||
            rules::intoxicationMagicSaveRaisePercent(
                rules::INTOX_MODERATE) != 5 ||
            rules::intoxicationMagicSaveRaisePercent(
                rules::INTOX_GREAT) != 25) ++bad;
        // sober and comatose read zero on every row
        if (rules::intoxicationBraveryAdjust(rules::INTOX_SOBER) != 0 ||
            rules::intoxicationHitPointAdjust(rules::INTOX_COMATOSE) != 0)
            ++bad;
        // comatose sleep 7-10 hours
        if (rules::intoxicationComatoseSleepMin() != 7 ||
            rules::intoxicationComatoseSleepMax() != 10) ++bad;
        // the recovery table: hours and multipliers
        static const int kRecMin[4] = { 1, 2, 4, 7 };
        static const int kRecMax[4] = { 2, 4, 6, 10 };
        static const int kMild[4] = { 80, 85, 90, 95 };
        static const int kStrong[4] = { 50, 55, 55, 60 };
        for (int i = 0; i < 4; ++i) {
            rules::IntoxState s =
                (rules::IntoxState)(i + 1);
            if (rules::intoxicationRecoveryMin(s) != kRecMin[i] ||
                rules::intoxicationRecoveryMax(s) != kRecMax[i] ||
                rules::intoxicationStimulantPercent(s, false)
                    != kMild[i] ||
                rules::intoxicationStimulantPercent(s, true)
                    != kStrong[i])
                ++bad;
        }
        // the strong-stimulant constitution risk
        if (rules::intoxicationStrongStimulantConChance() != 5 ||
            rules::intoxicationStrongStimulantConLoss() != 1)
            ++bad;
        // the 20 named forms in printed order
        static const char* const kNames[20] = {
            "dipsomania", "kleptomania", "schizoid",
            "pathological liar", "monomania",
            "dementia praecox", "melancholia",
            "megalomania", "delusional insanity",
            "schizophrenia", "mania", "lunacy",
            "paranoia", "manic-depressive",
            "hallucinatory insanity", "sado-masochism",
            "homicidal mania", "hebephrenia",
            "suicidal mania", "catatonia"
        };
        for (int i = 1; i <= 20; ++i)
            if (std::string(rules::insanityName(i))
                    != kNames[i - 1]) ++bad;
        if (std::string(rules::insanityName(0))
                != kNames[0] ||
            std::string(rules::insanityName(21))
                != kNames[19]) ++bad;
        // the mild star: types 1-4 only
        for (int i = 1; i <= 20; ++i)
            if (rules::insanityIsMild(i) != (i <= 4)) ++bad;
        // the duration classes
        if (rules::insanityTemporaryWeeksMin() != 2 ||
            rules::insanityTemporaryWeeksMax() != 12 ||
            rules::insanityMildWeeksMin() != 1 ||
            rules::insanityMildWeeksMax() != 4) ++bad;
        // the per-form printed parameters
        if (rules::insanityDipsomaniaContinueNearAlcohol() != 50 ||
            rules::insanityDipsomaniaContinueOtherwise() != 10 ||
            rules::insanityKleptomaniaSeenChance() != 90 ||
            rules::insanityKleptomaniaThiefPenalty() != -10 ||
            rules::insanityDementiaPraecoxIgnoreChance() != 25 ||
            rules::insanityMelancholiaIgnoreChance() != 50)
            ++bad;
        if (rules::insanitySchizophreniaPersonalitiesMin() != 1 ||
            rules::insanitySchizophreniaPersonalitiesMax() != 4 ||
            rules::insanityOnsetChanceIn6() != 1 ||
            rules::insanityManiaDurationMinTurns() != 2 ||
            rules::insanityManiaDurationMaxTurns() != 12)
            ++bad;
        // the mania strength states: 18/50, 18/75,
        // 18/00 - the percent-of-exceptional encoding
        if (rules::insanityManiaStrengthState(1) != 50 ||
            rules::insanityManiaStrengthState(2) != 75 ||
            rules::insanityManiaStrengthState(3) != 100 ||
            rules::insanityManiaStrengthState(6) != 100)
            ++bad;
        if (rules::insanityManicDepressiveCycleMinDays() != 1 ||
            rules::insanityManicDepressiveCycleMaxDays() != 4 ||
            rules::insanityManicDepressiveFlipChance() != 90 ||
            rules::insanityHallucinatoryNormalChance() != 50 ||
            rules::insanityHallucinatoryDurationMinTurns() != 1 ||
            rules::insanityHallucinatoryDurationMaxTurns() != 20)
            ++bad;
        if (rules::insanitySadoMasoNormalMinDays() != 1 ||
            rules::insanitySadoMasoNormalMaxDays() != 3 ||
            rules::insanityHomicidalIntervalMinDays() != 1 ||
            rules::insanityHomicidalIntervalMaxDays() != 4 ||
            rules::insanityHomicidalMelancholiaMinDays() != 1 ||
            rules::insanityHomicidalMelancholiaMaxDays() != 6)
            ++bad;
        if (rules::insanityHebephreniaEnrageChance() != 75 ||
            rules::insanityHebephreniaCatatonicMinHours() != 1 ||
            rules::insanityHebephreniaCatatonicMaxHours() != 6 ||
            rules::insanitySuicidalScaleMin() != 10 ||
            rules::insanitySuicidalScaleMax() != 80 ||
            rules::insanitySuicidalManiaMinTurns() != 2 ||
            rules::insanitySuicidalManiaMaxTurns() != 8 ||
            rules::insanitySuicidalMelancholyMinDays() != 2 ||
            rules::insanitySuicidalMelancholyMaxDays() != 12 ||
            rules::insanityCatatoniaReactionChance() != 1)
            ++bad;
        printf("R166 intoxication and insanity audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R167: disease and infestation audit --------
    // DMG pp.13-14: the contraction chances with
    // every printed modifier, the 16-row disease
    // table and the 6-row parasite table cell by
    // cell, the severity effects, the die roll
    // adjustments, the per-area numbers, and the
    // death relapse.
    {
        int bad = 0;
        // the contraction bases and modifiers
        if (rules::diseaseContractBasePercent() != 2 ||
            rules::parasiteContractBasePercent() != 3)
            ++bad;
        if (rules::diseaseModCurrentlyAfflicted() != 1 ||
            rules::diseaseModCrowding() != 1 ||
            rules::diseaseModFilth() != 1 ||
            rules::diseaseModOld() != 2 ||
            rules::diseaseModMarshEnvironment() != 2 ||
            rules::diseaseModHotMoist() != 2 ||
            rules::diseaseModVenerable() != 5 ||
            rules::diseaseModCarrierExposure() != 10 ||
            rules::diseaseModCoolClimate() != -1 ||
            rules::diseaseModColdHighMountains() != -2 ||
            rules::diseaseModShipboardPastTwoWeeks() != -2)
            ++bad;
        if (rules::parasiteModFilth() != 1 ||
            rules::parasiteModImproperlyCookedMeat() != 2 ||
            rules::parasiteModPollutedWater() != 5 ||
            rules::parasiteModSwampJungle() != 5 ||
            rules::parasiteModCoolOrDesert() != -1 ||
            rules::parasiteModColdOrCoolDesert() != -1)
            ++bad;
        if (!rules::diseaseWeeklyCheckWhenFavorable() ||
            !rules::diseaseCheckOnEachCarrierExposure())
            ++bad;
        // the 16-row disease table, cell by cell
        static const int kAcuteHi[16] = {
            3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
            7, 5, 6, 6, 5, 6
        };
        static const int kMildHi[16] = {
            2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
            6, 5, 6, 5, 5, 5
        };
        static const int kSevereHi[16] = {
            5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
            8, 7, 8, 7, 7, 7
        };
        static const int kTermHi[16] = {
            8, 8, 8, 8, 8, 8, 8, 8, 8, 0,
            0, 8, 0, 8, 8, 8
        };
        if (rules::diseaseAreaCount() != 16) ++bad;
        for (int i = 0; i < 16; ++i) {
            if (rules::diseaseAcuteHi(i) != kAcuteHi[i] ||
                rules::diseaseChronicLo(i)
                    != kAcuteHi[i] + 1 ||
                rules::diseaseSeverityMildHi(i) != kMildHi[i] ||
                rules::diseaseSeveritySevereHi(i)
                    != kSevereHi[i] ||
                rules::diseaseSeverityTerminalHi(i)
                    != kTermHi[i])
                ++bad;
            if (rules::diseaseHasTerminalColumn(i)
                    != (kTermHi[i] != 0)) ++bad;
            // acute below the line, chronic above it
            if (!rules::diseaseIsAcute(i, kAcuteHi[i]) ||
                rules::diseaseIsAcute(i, kAcuteHi[i] + 1) ||
                rules::diseaseIsChronic(i, kAcuteHi[i]) ||
                !rules::diseaseIsChronic(i, kAcuteHi[i] + 1))
                ++bad;
        }
        // spot the severity splits: row 0 (blood)
        // mild 1-2, severe 3-5, terminal 6-8
        if (rules::diseaseSeverityMildHi(0) != 2 ||
            rules::diseaseSeveritySevereHi(0) != 5 ||
            rules::diseaseSeverityTerminalHi(0) != 8) ++bad;
        // the d100 row mapping, probed at every band
        static const int kRowForD100[12] = {
            1, 4, 5, 7, 9, 13, 19, 41, 43, 49, 53, 97
        };
        static const int kWantRow[12] = {
            0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15
        };
        for (int i = 0; i < 12; ++i)
            if (rules::diseaseAreaForD100(kRowForD100[i])
                    != kWantRow[i]) ++bad;
        if (rules::diseaseAreaForD100(100) != 15 ||
            rules::diseaseAreaForD100(86) != 14)
            ++bad;
        // the 6-row parasite table, cell by cell
        static const int kParMild[6] = { 2, 2, 1, 1, 7, 2 };
        static const int kParSevere[6] = { 5, 7, 3, 4, 8, 7 };
        static const int kParTerm[6] = { 8, 8, 8, 8, 0, 8 };
        if (rules::parasiteAreaCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i) {
            if (rules::parasiteSeverityMildHi(i) != kParMild[i] ||
                rules::parasiteSeveritySevereHi(i) != kParSevere[i] ||
                rules::parasiteSeverityTerminalHi(i) != kParTerm[i])
                ++bad;
        }
        if (rules::parasiteAreaForD100(10) != 0 ||
            rules::parasiteAreaForD100(11) != 1 ||
            rules::parasiteAreaForD100(35) != 1 ||
            rules::parasiteAreaForD100(36) != 2 ||
            rules::parasiteAreaForD100(41) != 3 ||
            rules::parasiteAreaForD100(46) != 4 ||
            rules::parasiteAreaForD100(75) != 4 ||
            rules::parasiteAreaForD100(76) != 5 ||
            rules::parasiteAreaForD100(100) != 5)
            ++bad;
        // the severity effects
        if (rules::diseaseMildWeeksMin() != 1 ||
            rules::diseaseMildWeeksMax() != 3 ||
            rules::diseaseSevereHitPointPercent() != 50 ||
            rules::diseaseSevereDisabledWeeksMin() != 1 ||
            rules::diseaseSevereDisabledWeeksMax() != 2 ||
            rules::diseaseSevereMildRecoveryWeeksMin() != 1 ||
            rules::diseaseSevereMildRecoveryWeeksMax() != 2 ||
            rules::diseaseTerminalDaysMin() != 1 ||
            rules::diseaseTerminalDaysMax() != 12)
            ++bad;
        // the terminal units: brain hours, blood and
        // bones, gastro, skin, urinary weeks,
        // cardio-renal days, generative, muscles,
        // respiratory months
        if (rules::diseaseTerminalUnit(2)
                != rules::DUR_HOURS ||
            rules::diseaseTerminalUnit(0)
                != rules::DUR_WEEKS ||
            rules::diseaseTerminalUnit(1)
                != rules::DUR_WEEKS ||
            rules::diseaseTerminalUnit(3)
                != rules::DUR_DAYS ||
            rules::diseaseTerminalUnit(8)
                != rules::DUR_MONTHS ||
            rules::diseaseTerminalUnit(11)
                != rules::DUR_MONTHS ||
            rules::diseaseTerminalUnit(13)
                != rules::DUR_MONTHS)
            ++bad;
        // the function-loss terminals and the special
        // connective case
        if (!rules::diseaseTerminalIsFunctionLoss(5) ||
            !rules::diseaseTerminalIsFunctionLoss(6) ||
            rules::diseaseTerminalIsFunctionLoss(0) ||
            rules::diseaseEyesBlindBothChance() != 50 ||
            !rules::diseaseTerminalTreatedAsChronicSevere(4) ||
            rules::diseaseTerminalTreatedAsChronicSevere(0))
            ++bad;
        // the per-area ability losses
        if (rules::diseaseBloodWeeklyStrLoss() != 1 ||
            rules::diseaseBloodWeeklyConLoss() != 1 ||
            rules::diseaseBrainIntLoss() != 1 ||
            rules::diseaseBrainDexLoss() != 1 ||
            rules::diseaseConnectiveMonthlyLoss() != 1 ||
            rules::diseaseGastroStrConLoss() != 1 ||
            rules::diseaseJointsDexLoss() != 1 ||
            rules::diseaseMucousConLoss() != 1 ||
            rules::diseaseMuscleStrDexLoss() != 1 ||
            rules::diseaseMuscleSeverePermanentChance() != 25 ||
            rules::diseaseNoseThroatSevereConLossChance() != 10 ||
            rules::diseaseRespiratoryLossChance() != 10 ||
            rules::diseaseSkinSevereChaLossChance() != 10 ||
            rules::diseaseSkinChronicMildChance() != 10 ||
            rules::diseaseSkinChronicSevereChance() != 25 ||
            rules::diseaseUrinaryLossChance() != 20)
            ++bad;
        // the constitution ladder on the die rolls
        static const int kCon[8] = { 1, 3, 6, 10, 13, 16, 18, 19 };
        static const int kAdj[8] = { 2, 1, 0, -1, -2, -3, -4, -4 };
        for (int i = 0; i < 8; ++i)
            if (rules::diseaseConRollAdjust(kCon[i]) != kAdj[i])
                ++bad;
        if (rules::diseaseAdjustChronicDisease() != 1 ||
            rules::diseaseAdjustSevereInfestation() != 1 ||
            rules::diseaseAdjustLowHitPoints() != 1 ||
            rules::diseaseAdjustmentsApplyToParasites() ||
            !rules::diseaseRollMeansNoContraction(0) ||
            !rules::diseaseRollMeansNoContraction(-2) ||
            rules::diseaseRollMeansNoContraction(1))
            ++bad;
        // death from disease or infestation
        if (rules::diseaseDeathRelapseChance() != 90 ||
            rules::diseasePermanentLossFixedByCurative())
            ++bad;
        printf("R167 disease and infestation audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R168: underwater spell use audit ------------
    // DMG p.57: the general limits, the two printed
    // spell lists (cannot-cast by class and level,
    // altered effects) and the altered numerics.
    {
        int bad = 0;
        // the general paragraph
        if (!rules::uwSpellRangesAsDungeons() ||
            !rules::uwFireSpellsFailExceptInAiryWater() ||
            !rules::uwElectricalSpellsConductedToArea() ||
            !rules::uwMaterialComponentsAltered())
            ++bad;
        // the cannot-cast list: 41 entries
        // (9 cleric, 22 druid, 10 magic-user)
        if (rules::uwCannotCastCount() != 41) ++bad;
        if (rules::uwCannotCastClassCount("cleric") != 9 ||
            rules::uwCannotCastClassCount("druid") != 22 ||
            rules::uwCannotCastClassCount("magic-user") != 10)
            ++bad;
        // 11 entries carry the printed asterisk mark
        {
            int marks = 0;
            for (int i = 0; i < rules::uwCannotCastCount();
                 ++i)
                if (rules::uwCannotCast(i).printedMark) ++marks;
            if (marks != 11) ++bad;
        }
        // spot the rows: first and last of each class
        if (std::string(rules::uwCannotCast(0).cls) != "cleric" ||
            rules::uwCannotCast(0).level != 3 ||
            std::string(rules::uwCannotCast(0).name)
                != "speak with dead" ||
            !rules::uwCannotCast(0).printedMark)
            ++bad;
        if (std::string(rules::uwCannotCast(8).cls) != "cleric" ||
            rules::uwCannotCast(8).level != 7 ||
            std::string(rules::uwCannotCast(8).name)
                != "wind walk")
            ++bad;
        if (std::string(rules::uwCannotCast(9).cls) != "druid" ||
            rules::uwCannotCast(9).level != 1 ||
            std::string(rules::uwCannotCast(9).name)
                != "predict weather")
            ++bad;
        if (std::string(rules::uwCannotCast(30).cls) != "druid" ||
            rules::uwCannotCast(30).level != 7 ||
            std::string(rules::uwCannotCast(30).name)
                != "fire storm")
            ++bad;
        if (std::string(rules::uwCannotCast(31).cls)
                != "magic-user" ||
            rules::uwCannotCast(31).level != 1 ||
            std::string(rules::uwCannotCast(31).name)
                != "affect normal fires" ||
            !rules::uwCannotCast(31).printedMark)
            ++bad;
        if (std::string(rules::uwCannotCast(40).cls)
                != "magic-user" ||
            rules::uwCannotCast(40).level != 4 ||
            std::string(rules::uwCannotCast(40).name)
                != "fire trap")
            ++bad;
        // the middle rows: cleric atonement and
        // flame strike, druid produce fire
        if (std::string(rules::uwCannotCast(3).name)
                != "atonement" ||
            std::string(rules::uwCannotCast(4).name)
                != "flame strike" ||
            std::string(rules::uwCannotCast(17).name)
                != "produce fire" ||
            rules::uwCannotCast(17).level != 4)
            ++bad;
        // the membership probe, both ways
        if (!rules::uwIsCannotCast("cleric", 5, "flame strike") ||
            !rules::uwIsCannotCast("druid", 2, "produce flame") ||
            !rules::uwIsCannotCast("magic-user", 3, "fireball"))
            ++bad;
        if (rules::uwIsCannotCast("cleric", 1, "cure light wounds") ||
            rules::uwIsCannotCast("magic-user", 3, "fly") ||
            rules::uwIsCannotCast("druid", 4, "plant growth"))
            ++bad;
        // the printed reverse/shield notes
        if (!rules::uwHeatMetalReverseChillWorks() ||
            !rules::uwFireShieldColdFlameWorks())
            ++bad;
        // the altered-effects list: 10 entries
        // (2 cleric, 1 druid, 7 magic-user)
        if (rules::uwAlteredCount() != 10) ++bad;
        {
            int cl = 0, dr = 0, mu = 0;
            for (int i = 0; i < 10; ++i) {
                std::string c = rules::uwAltered(i).cls;
                if (c == "cleric") ++cl;
                else if (c == "druid") ++dr;
                else ++mu;
            }
            if (cl != 2 || dr != 1 || mu != 7) ++bad;
        }
        static const int kAltLevel[10] = {
            6, 7, 7, 3, 3, 3, 3, 5, 6, 6
        };
        for (int i = 0; i < 10; ++i)
            if (rules::uwAltered(i).level != kAltLevel[i])
                ++bad;
        if (std::string(rules::uwAltered(0).name) != "part water" ||
            std::string(rules::uwAltered(0).cls) != "cleric" ||
            std::string(rules::uwAltered(2).name)
                != "conjure earth elemental" ||
            std::string(rules::uwAltered(4).name)
                != "lightning bolt" ||
            std::string(rules::uwAltered(7).name)
                != "conjure elemental" ||
            std::string(rules::uwAltered(8).name)
                != "freezing sphere (Otiluke)" ||
            std::string(rules::uwAltered(9).name) != "part water")
            ++bad;
        // the altered-effect text, spot pinned
        if (std::string(rules::uwAltered(0).effect)
                != "tunnel through deep water, no wider than 10 feet" ||
            std::string(rules::uwAltered(3).effect)
                != "swim easily at any depth, even encumbered, speed 9 inches")
            ++bad;
        // the altered-effect numerics
        if (rules::uwPartWaterTunnelDiameterFeet() != 10)
            ++bad;
        if (rules::uwEarthquakeStunRoundsMin() != 5 ||
            rules::uwEarthquakeStunRoundsMax() != 20 ||
            !rules::uwEarthquakeSaveVsDeathMagic())
            ++bad;
        if (!rules::uwConjureEarthElementalConfinedToFloor())
            ++bad;
        if (rules::uwFlyMaxSpeedInches() != 9 ||
            rules::uwLightningBoltRadiusInches() != 2 ||
            !rules::uwLightningBoltSaveForHalf())
            ++bad;
        if (rules::uwIceStormHailDamageMin() != 1 ||
            rules::uwIceStormHailDamageMax() != 10 ||
            !rules::uwIceStormSleetNoEffect() ||
            !rules::uwWallOfIceFloatsToSurface())
            ++bad;
        if (!rules::uwConjureElementalAirOrFireImpossible() ||
            !rules::uwConjureElementalWaterFine())
            ++bad;
        if (rules::uwFreezingSphereCubicFeetPerLevel() != 50 ||
            rules::uwFreezingSphereDurationRoundsPerLevel() != 1 ||
            !rules::uwFreezingSphereCasterSuffocates())
            ++bad;
        printf("R168 underwater spell use audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R169: humanoid racial preferences audit ----
    // DMG p.106: the nine-race matrix cell by
    // cell, the star marks, the letter key and
    // the usage and compatibility prose.
    {
        int bad = 0;
        // the nine race names, in print order
        if (rules::humRPrefRaceCount() != 9) ++bad;
        static const char* kRace[9] = {
            "bugbear", "gnoll", "goblin", "hill giant",
            "hobgoblin", "kobold", "ogre", "orc", "troll"
        };
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::humRPrefRaceName(i))
                    != kRace[i])
                ++bad;
        // the race index probe, both ways
        if (rules::humRPrefRaceIndex("hobgoblin") != 4 ||
            rules::humRPrefRaceIndex("troll") != 8 ||
            rules::humRPrefRaceIndex("bugbear") != 0 ||
            rules::humRPrefRaceIndex("purple worm") != -1)
            ++bad;
        // the full 81-cell matrix and the star
        // marks, cell by cell
        static const rules::HumRPrefCode kWant[9][9] = {
            { rules::HPREF_P, rules::HPREF_T, rules::HPREF_G, rules::HPREF_T, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N },
            { rules::HPREF_T, rules::HPREF_P, rules::HPREF_A, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_T, rules::HPREF_N },
            { rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_N, rules::HPREF_T, rules::HPREF_G, rules::HPREF_H, rules::HPREF_N, rules::HPREF_A },
            { rules::HPREF_G, rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_A, rules::HPREF_A, rules::HPREF_G, rules::HPREF_N, rules::HPREF_T },
            { rules::HPREF_T, rules::HPREF_N, rules::HPREF_N, rules::HPREF_N, rules::HPREF_H, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H },
            { rules::HPREF_A, rules::HPREF_H, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_H, rules::HPREF_A, rules::HPREF_T },
            { rules::HPREF_T, rules::HPREF_T, rules::HPREF_A, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_T, rules::HPREF_T },
            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_H, rules::HPREF_H },
            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_N }
        };
        static const int kStar[9][9] = {
            { 0, 1, 0, 0, 1, 1, 0, 1, 0 },
            { 0, 0, 1, 0, 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 0 },
            { 0, 0, 1, 0, 2, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 1, 0, 1, 0 },
            { 0, 0, 1, 0, 0, 1, 0, 2, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 2 }
        };
        int nP = 0, nG = 0, nT = 0, nN = 0,
            nA = 0, nH = 0, nSingle = 0, nDouble = 0;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (rules::humRPrefCode(r, c) != kWant[r][c])
                    ++bad;
                if (rules::humRPrefStars(r, c)
                        != kStar[r][c])
                    ++bad;
                if (rules::humRPrefBullyMark(r, c)
                        != (kStar[r][c] == 1))
                    ++bad;
                if (rules::humRPrefRivalTribe(r, c)
                        != (kStar[r][c] == 2))
                    ++bad;
                switch (rules::humRPrefCode(r, c)) {
                case rules::HPREF_P: ++nP; break;
                case rules::HPREF_G: ++nG; break;
                case rules::HPREF_T: ++nT; break;
                case rules::HPREF_N: ++nN; break;
                case rules::HPREF_A: ++nA; break;
                case rules::HPREF_H: ++nH; break;
                }
                if (rules::humRPrefStars(r, c) == 1) ++nSingle;
                if (rules::humRPrefStars(r, c) == 2) ++nDouble;
            }
        }
        // the letter census: P 6, G 10, T 18,
        // N 14, A 25, H 8 (81 cells)
        if (nP != 6 || nG != 10 || nT != 18 ||
            nN != 14 || nA != 25 || nH != 8)
            ++bad;
        // 18 single stars, 3 double stars
        if (nSingle != 18 || nDouble != 3) ++bad;
        // the self cells: six print P, the
        // hobgoblin, orc and troll cells print the
        // double star (rival tribe or family
        // group)
        for (int i = 0; i < 9; ++i) {
            bool selfP =
                rules::humRPrefCode(i, i) == rules::HPREF_P;
            bool rival = rules::humRPrefRivalTribe(i, i);
            if (i == 4 || i == 7 || i == 8) {
                if (selfP || !rival) ++bad;
            } else {
                if (!selfP || rival) ++bad;
            }
        }
        // the letter key names and letters
        if (std::string(rules::humRPrefCodeName(
                rules::HPREF_P)) != "preference" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_G)) != "goodwill" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_T)) != "tolerate" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_N)) != "neutral negative" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_A)) != "antipathy" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_H)) != "hatred" ||
            rules::humRPrefCodeLetter(rules::HPREF_P) != 'P' ||
            rules::humRPrefCodeLetter(rules::HPREF_G) != 'G' ||
            rules::humRPrefCodeLetter(rules::HPREF_T) != 'T' ||
            rules::humRPrefCodeLetter(rules::HPREF_N) != 'N' ||
            rules::humRPrefCodeLetter(rules::HPREF_A) != 'A' ||
            rules::humRPrefCodeLetter(rules::HPREF_H) != 'H')
            ++bad;
        // the letter semantics
        if (!rules::humCodeAllowsCoOperation(
                rules::HPREF_P) ||
            !rules::humCodeAllowsCoOperation(
                rules::HPREF_G) ||
            rules::humCodeAllowsCoOperation(rules::HPREF_T) ||
            !rules::humCodeNoHostilityLikely(rules::HPREF_T) ||
            rules::humCodeNoHostilityLikely(rules::HPREF_N) ||
            !rules::humCodeNoAidIfIllBefalls(rules::HPREF_N) ||
            rules::humCodeNoAidIfIllBefalls(rules::HPREF_G))
            ++bad;
        // the antipathy and hatred behavior
        if (!rules::humAntipathyDesertIfLeadersWeak() ||
            !rules::humHatredBreaksOutAtFirstOpportunity() ||
            !rules::humHatredDesertsNearStrongHatedBody())
            ++bad;
        // the usage prose: side by side within 12
        // inches, no intervening troops or screen
        if (rules::humSideBySideVisibilityRangeInches() != 12 ||
            !rules::humInterveningTroopsOrScreenBlocks())
            ++bad;
        // the compatibility prose
        if (!rules::humDemihumanCompatibilityFromPHBTable() ||
            !rules::humLizardMenHatedByAllHumanoidsSaveKobolds() ||
            !rules::humKoboldsSuspiciousOfLizardMen() ||
            !rules::humHumanTroopsSuspiciousOfLizardMen())
            ++bad;
        // spot probes of the matrix in print
        // coordinates
        if (rules::humRPrefCode(0, 2) != rules::HPREF_G ||
            rules::humRPrefCode(2, 0) != rules::HPREF_G ||
            rules::humRPrefCode(4, 8) != rules::HPREF_H ||
            rules::humRPrefCode(8, 4) != rules::HPREF_H ||
            rules::humRPrefCode(1, 6) != rules::HPREF_G ||
            rules::humRPrefCode(6, 1) != rules::HPREF_T ||
            rules::humRPrefCode(5, 1) != rules::HPREF_H ||
            rules::humRPrefCode(5, 6) != rules::HPREF_H)
            ++bad;
        if (!rules::humRPrefBullyMark(0, 1) ||
            !rules::humRPrefBullyMark(0, 4) ||
            !rules::humRPrefBullyMark(6, 5) ||
            !rules::humRPrefBullyMark(7, 5) ||
            !rules::humRPrefBullyMark(3, 7) ||
            !rules::humRPrefBullyMark(4, 2) ||
            rules::humRPrefBullyMark(4, 4) ||
            rules::humRPrefBullyMark(2, 5) ||
            rules::humRPrefRivalTribe(0, 4))
            ++bad;
        printf("R169 humanoid racial preferences audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R170: followers by class audit ----------------
    // DMG pp.16-18: the cleric, fighter, ranger,
    // thief and assassin recruitment tables,
    // the multi-class tables, the Grandfather
    // ladder, the arrival timing and the
    // paladin warhorse, cell by cell.
    {
        int bad = 0;
        // the cleric categories: 7, roll for
        // each, all 0 level men-at-arms
        if (rules::folClericCategoryCount() != 7 ||
            !rules::folClericRollForEachCategory() ||
            !rules::folClericAllZeroLevel() ||
            !rules::folPoleArmRandomOrAssigned())
            ++bad;
        static const int kClMin[7] =
            { 2, 3, 5, 5, 5, 5, 10 };
        static const int kClMax[7] =
            { 8, 12, 30, 20, 30, 30, 60 };
        for (int i = 0; i < 7; ++i) {
            if (rules::folClericUnit(i).nMin != kClMin[i] ||
                rules::folClericUnit(i).nMax != kClMax[i])
                ++bad;
        }
        if (std::string(rules::folClericUnit(0).kind)
                != "heavy cavalry" ||
            std::string(rules::folClericUnit(0).armor)
                != "plate mail and shield" ||
            std::string(rules::folClericUnit(0).weapons)
                != "lance, broad sword, mace" ||
            std::string(rules::folClericUnit(2).weapons)
                != "light crossbow, pick" ||
            std::string(rules::folClericUnit(6).kind)
                != "light infantry" ||
            std::string(rules::folClericUnit(6).weapons)
                != "spear, club")
            ++bad;
        // the fighter leader: 4 bands, levels
        // 5, 6, 6, 7
        static const int kLvl[4] = { 5, 6, 6, 7 };
        if (rules::folFighterLeaderBandCount() != 4 ||
            !rules::folFighterRollOnceLeaderOnceTroops())
            ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::folFighterLeader(i).level != kLvl[i])
                ++bad;
        if (rules::folFighterLeaderForD100(40) != 0 ||
            rules::folFighterLeaderForD100(41) != 1 ||
            rules::folFighterLeaderForD100(76) != 2 ||
            rules::folFighterLeaderForD100(96) != 3)
            ++bad;
        if (std::string(rules::folFighterLeader(0).gear)
                != "plate mail and shield, +2 magic battle axe" ||
            std::string(rules::folFighterLeader(3).gear)
                != "+1 plate mail and +1 shield, +2 magic sword (no special abilities), rides a heavy warhorse with horseshoes of speed")
            ++bad;
        // the fighter troops: 4 bands
        if (rules::folFighterTroopsBandCount() != 4)
            ++bad;
        if (rules::folFighterTroopsForD100(50) != 0 ||
            rules::folFighterTroopsForD100(51) != 1 ||
            rules::folFighterTroopsForD100(91) != 3)
            ++bad;
        if (std::string(rules::folFighterTroops(1).text)
                != "80 heavy infantry, 20 with splint mail, 60 with leather armor, 20 with morning star and hand axe, 60 with pike and short sword")
            ++bad;
        if (std::string(rules::folFighterTroops(2).text)
                != "60 crossbowmen, chain mail, 40 with heavy crossbow and short sword, 20 with light crossbow and military fork")
            ++bad;
        // the ranger: 2d12, the adjustment ladder
        static const int kRAdj[9] =
            { 25, 15, 10, 5, 0, -5, -10, -20, -30 };
        if (rules::folRangerCountDice() != 2 ||
            rules::folRangerCountDieSides() != 12 ||
            rules::folRangerAdjustBandCount() != 9 ||
            rules::folRangerSpecialThreshold() != 70 ||
            !rules::folRangerOneGroupPerCategory() ||
            !rules::folRangerRerollImpermissibleOrUnder01())
            ++bad;
        for (int i = 0; i < 9; ++i) {
            int roll = rules::folRangerAdjust(i).lo;
            if (rules::folRangerAdjustFor2d12(roll)
                    != kRAdj[i])
                ++bad;
            if (rules::folRangerAdjustFor2d12(
                    rules::folRangerAdjust(i).hi) != kRAdj[i])
                ++bad;
        }
        // +10 and +5 apply to the first roll only
        if (!rules::folRangerAdjustFirstRollOnly(4) ||
            !rules::folRangerAdjustFirstRollOnly(5) ||
            rules::folRangerAdjustFirstRollOnly(2) ||
            rules::folRangerAdjustFirstRollOnly(21))
            ++bad;
        // the thief: 4d6, the level ladder
        static const int kTAdj[6] =
            { 20, 15, 5, 0, -5, -10 };
        if (rules::folThiefCountDice() != 4 ||
            rules::folThiefCountDieSides() != 6 ||
            rules::folThiefLevelAdjustBandCount() != 6)
            ++bad;
        for (int i = 0; i < 6; ++i) {
            if (rules::folThiefLevelAdjustFor4d6(
                    rules::folThiefLevelAdjust(i).lo)
                != kTAdj[i])
                ++bad;
            if (rules::folThiefLevelAdjustFor4d6(
                    rules::folThiefLevelAdjust(i).hi)
                != kTAdj[i])
                ++bad;
        }
        // the thief category bands
        if (rules::folThiefCategoryForD100(50) != 1 ||
            rules::folThiefCategoryForD100(51) != 2 ||
            rules::folThiefCategoryForD100(71) != 3 ||
            rules::folThiefCategoryForD100(81) != 4 ||
            rules::folThiefCategoryForD100(91) != 5 ||
            rules::folThiefCategoryForD100(96) != 6)
            ++bad;
        // the race of thief: 7 bands, edges probed
        if (rules::folThiefRaceBandCount() != 7)
            ++bad;
        static const char* kTRace[7] = {
            "dwarven", "elven", "gnomish", "half-elven",
            "halfling", "half-orcish", "human"
        };
        for (int i = 0; i < 7; ++i)
            if (std::string(rules::folThiefRace(i).name)
                    != kTRace[i])
                ++bad;
        if (rules::folThiefRaceForD100(10) != 0 ||
            rules::folThiefRaceForD100(11) != 1 ||
            rules::folThiefRaceForD100(55) != 5 ||
            rules::folThiefRaceForD100(56) != 6 ||
            rules::folThiefRaceForD100(100) != 6)
            ++bad;
        // the level of thief: 7 bands
        if (rules::folThiefLevelBandCount() != 7)
            ++bad;
        if (rules::folThiefLevelForD100(20) != 0 ||
            rules::folThiefLevelForD100(21) != 1 ||
            rules::folThiefLevelForD100(96) != 6 ||
            rules::folThiefLevelBand(0).level != 1 ||
            rules::folThiefLevelBand(6).level != 7 ||
            rules::folThiefLevelBand(0).star != 1)
            ++bad;
        // the humans table I: 5 classes
        if (rules::folHumanClassBandCount() != 5)
            ++bad;
        if (std::string(rules::folHumanClass(0).cls)
                != "cleric" ||
            rules::folHumanClass(0).lvMin != 1 ||
            rules::folHumanClass(0).lvMax != 4 ||
            std::string(rules::folHumanClass(1).cls)
                != "druid" ||
            rules::folHumanClass(1).lvMin != 2 ||
            rules::folHumanClass(1).lvMax != 5 ||
            std::string(rules::folHumanClass(2).cls)
                != "fighter" ||
            rules::folHumanClass(2).lvMax != 6 ||
            std::string(rules::folHumanClass(3).cls)
                != "ranger" ||
            rules::folHumanClass(3).lvMax != 3 ||
            std::string(rules::folHumanClass(4).cls)
                != "magic-user" ||
            rules::folHumanClass(4).lvMax != 3)
            ++bad;
        // the demi-humans table II: 12 rows,
        // every band edge probed
        if (rules::folDemiHumanBandCount() != 12)
            ++bad;
        static const int kDHNum[12] =
            { 2, 1, 2, 1, 1, 3, 1, 1, 1, 1, 3, 1 };
        for (int i = 0; i < 12; ++i)
            if (rules::folDemiHuman(i).number != kDHNum[i])
                ++bad;
        if (std::string(rules::folDemiHuman(0).raceClass)
                != "dwarf fighter" ||
            rules::folDemiHuman(0).lvMin != 1 ||
            rules::folDemiHuman(0).lvMax != 4 ||
            std::string(rules::folDemiHuman(2).raceClass)
                != "elf fighter" ||
            rules::folDemiHuman(2).lvMin != 2 ||
            rules::folDemiHuman(2).lvMax != 5 ||
            std::string(rules::folDemiHuman(4).raceClass)
                != "elf fighter/magic-user/thief" ||
            std::string(rules::folDemiHuman(6).raceClass)
                != "gnome fighter/illusionist" ||
            std::string(rules::folDemiHuman(7).raceClass)
                != "half-elf cleric/ranger" ||
            std::string(rules::folDemiHuman(11).raceClass)
                != "halfling fighter/thief")
            ++bad;
        // the multi-class thief professions (d6)
        if (std::string(rules::folThiefOtherProfession(0, 3))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(1, 3))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(1, 4))
                != "magic-user" ||
            std::string(rules::folThiefOtherProfession(1, 6))
                != "fighter/magic-user" ||
            std::string(rules::folThiefOtherProfession(2, 5))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(2, 6))
                != "illusionist" ||
            std::string(rules::folThiefOtherProfession(3, 6))
                != "fighter/magic-user" ||
            std::string(rules::folThiefOtherProfession(4, 2))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(5, 3))
                != "cleric" ||
            std::string(rules::folThiefOtherProfession(5, 4))
                != "fighter" ||
            !rules::folThiefFollowersAlwaysNeutralGood())
            ++bad;
        // the animals, mounts, creatures and special
        // tables: band edges and numbers
        if (rules::folAnimalBandCount() != 5 ||
            rules::folMountBandCount() != 3 ||
            rules::folCreatureBandCount() != 5 ||
            rules::folSpecialBandCount() != 5)
            ++bad;
        if (std::string(rules::folAnimal(0).name)
                != "bear, black" ||
            rules::folAnimal(0).nMin != 1 ||
            std::string(rules::folAnimal(2).name)
                != "blink dog" ||
            rules::folAnimal(2).nMin != 2 ||
            rules::folAnimal(2).nMax != 2 ||
            std::string(rules::folAnimal(4).name)
                != "owl, giant")
            ++bad;
        if (std::string(rules::folMount(0).name)
                != "centaur" ||
            rules::folMount(0).nMin != 1 ||
            rules::folMount(0).nMax != 3 ||
            std::string(rules::folMount(2).name)
                != "pegasus" ||
            rules::folMount(2).nMax != 1)
            ++bad;
        if (std::string(rules::folCreature(0).name)
                != "brownie" ||
            rules::folCreature(0).nMin != 1 ||
            rules::folCreature(0).nMax != 2 ||
            std::string(rules::folCreature(1).name)
                != "pixie" ||
            rules::folCreature(1).nMax != 4 ||
            std::string(rules::folCreature(2).name)
                != "pseudo-dragon")
            ++bad;
        if (std::string(rules::folSpecial(0).name)
                != "copper dragon" ||
            rules::folSpecial(0).star != 1 ||
            std::string(rules::folSpecial(1).name)
                != "giant, storm" ||
            std::string(rules::folSpecial(2).name)
                != "treant" ||
            rules::folSpecial(2).nMin != 2 ||
            rules::folSpecial(2).nMax != 5 ||
            std::string(rules::folSpecial(3).name)
                != "werebear" ||
            rules::folSpecial(4).nMax != 2)
            ++bad;
        // the assassin: 7d4, 75 percent desert,
        // newcomers 1st level
        if (rules::folAssassinCountDice() != 7 ||
            rules::folAssassinCountDieSides() != 4 ||
            !rules::folAssassinAdjustForPopulation() ||
            rules::folAssassinDesertChance() != 75 ||
            !rules::folAssassinNewcomersFirstLevel())
            ++bad;
        // the race of assassin: 6 bands including
        // the half-orcish 26-50 (the OCR gap,
        // pinned as the print)
        if (rules::folAssassinRaceBandCount() != 6)
            ++bad;
        if (rules::folAssassinRaceForD100(5) != 0 ||
            rules::folAssassinRaceForD100(6) != 1 ||
            rules::folAssassinRaceForD100(16) != 3 ||
            rules::folAssassinRaceForD100(26) != 4 ||
            rules::folAssassinRaceForD100(50) != 4 ||
            rules::folAssassinRaceForD100(51) != 5 ||
            std::string(rules::folAssassinRace(4).name)
                != "half-orcish")
            ++bad;
        // the level of assassin: 8 bands
        if (rules::folAssassinLevelBandCount() != 8)
            ++bad;
        if (rules::folAssassinLevelForD100(15) != 0 ||
            rules::folAssassinLevelForD100(16) != 1 ||
            rules::folAssassinLevelBand(0).level != 1 ||
            rules::folAssassinLevelBand(0).star != 1 ||
            rules::folAssassinLevelBand(1).star != 1 ||
            rules::folAssassinLevelBand(7).level != 8 ||
            rules::folAssassinLevelForD100(96) != 7 ||
            rules::folAssassinMultiClassChance() != 25)
            ++bad;
        // the multi-classed assassin professions
        if (std::string(rules::folAssassinOtherProfession(0, 3))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(1, 5))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(2, 4))
                != "fighter" ||
            std::string(rules::folAssassinOtherProfession(2, 5))
                != "illusionist" ||
            std::string(rules::folAssassinOtherProfession(3, 2))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(4, 2))
                != "fighter" ||
            std::string(rules::folAssassinOtherProfession(4, 3))
                != "cleric")
            ++bad;
        // the Grandfather/Grandmother ladder
        {
            int total = 0;
            for (int i = 0; i < 7; ++i)
                total += rules::folGrandfatherCountAt(i);
            if (total != 28) ++bad;
        }
        if (rules::folGrandfatherCountAt(0) != 1 ||
            rules::folGrandfatherLevelAt(0) != 8 ||
            rules::folGrandfatherCountAt(6) != 7 ||
            rules::folGrandfatherLevelAt(6) != 2 ||
            rules::folGrandfatherTotalMidLevel() != 28 ||
            rules::folGrandfatherFirstLevelMin() != 4 ||
            rules::folGrandfatherFirstLevelMax() != 16 ||
            rules::folGrandfatherDisplacedLeaveChance() != 75 ||
            rules::folGrandfatherNewLeaderMax() != 44)
            ++bad;
        // the arrival timing
        if (rules::folArrivalTensAdjust(1) != 0 ||
            rules::folArrivalTensAdjust(2) != 0 ||
            rules::folArrivalTensAdjust(3) != 10 ||
            rules::folArrivalTensAdjust(4) != 10 ||
            rules::folArrivalTensAdjust(5) != 20 ||
            rules::folArrivalTensAdjust(6) != 20 ||
            rules::folArrivalDayMax() != 30 ||
            rules::folArrivalIntervalDaysMin() != 1 ||
            rules::folArrivalIntervalDaysMax() != 8 ||
            rules::folArrivalWaitDaysMin() != 1 ||
            rules::folArrivalWaitDaysMax() != 4 ||
            !rules::folArrivalUnreceivedGoneForever() ||
            !rules::folHenchmanOrServantMayReceive())
            ++bad;
        // the paladin warhorse
        if (rules::folPaladinWarhorseMinLevel() != 4 ||
            rules::folPaladinJourneyMaxDaysRide() != 7 ||
            rules::folPaladinTaskWeeksMin() != 2 ||
            rules::folPaladinWarhorseServiceYears() != 10 ||
            !rules::folPaladinWarhorseMayBeWild() ||
            !rules::folPaladinGuardedByEvilFighterSameLevel())
            ++bad;
        printf("R170 followers by class audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R146: city flavor subtables audit ----
    // The two flavor subtables R64 named as unmodeled:
    // the p.191 drunk identity table ("the character(s)
    // found drunk should be diced for") and the p.192
    // harlot type table, both cell-verified at the
    // raw-HTML level of the 1eonline.info compilation -
    // the repo-trusted source; the DMG re-upload's OCR
    // debt stands (the compilation's 'Haughy' is the
    // printed 'haughty', corrected). Fiction-only
    // descriptors; every band edge pinned both ways: at
    // the edge the kind, one below the edge the next.
    {
        int bad = 0;
        // the drunk's dice-for identity (p.191): 20 bands
        static const struct { int lo, hi; const char* k; }
            kDrunk[] = {
            {   1,  2, "assassin" },
            {   3,10, "bandit" },
            { 11,18, "brigand" },
            { 19,20, "city guard" },
            { 21,22, "city official" },
            { 23,25, "city watchman" },
            { 26,27, "cleric" },
            { 28,29, "druid" },
            { 30,38, "fighter" },
            { 39,45, "gentleman" },
            { 46,48, "illusionist" },
            { 49,63, "laborer" },
            { 64,65, "magic-user" },
            { 66,73, "mercenary" },
            { 74,80, "merchant" },
            { 81,82, "noble" },
            { 83,90, "rake" },
            { 91,95, "ruffian" },
            { 96,97, "thief" },
            { 98,100, "tradesman" },
        };
        for (int i = 0; i < 20; ++i) {
            if (std::string(dm::cityDrunkKind(kDrunk[i].lo))
                != kDrunk[i].k) ++bad;
            if (std::string(dm::cityDrunkKind(kDrunk[i].hi))
                != kDrunk[i].k) ++bad;
            if (kDrunk[i].lo > 1 && std::string(
                    dm::cityDrunkKind(kDrunk[i].lo - 1))
                == kDrunk[i].k) ++bad;
        }
        // the harlot's type (p.192): 12 bands
        static const struct { int lo, hi; const char* k; }
            kHarlot[] = {
            {   1,10, "slovenly trull" },
            { 11,25, "brazen strumpet" },
            { 26,35, "cheap trollop" },
            { 36,50, "typical streetwalker" },
            { 51,65, "saucy tart" },
            { 66,75, "wanton wench" },
            { 76,85, "expensive doxy" },
            { 86,90, "haughty courtesan" },
            { 91,92, "aged madam" },
            { 93,94, "wealthy procuress" },
            { 95,98, "sly pimp" },
            { 99,100, "rich panderer" },
        };
        for (int i = 0; i < 12; ++i) {
            if (std::string(dm::cityHarlotKind(kHarlot[i].lo))
                != kHarlot[i].k) ++bad;
            if (std::string(dm::cityHarlotKind(kHarlot[i].hi))
                != kHarlot[i].k) ++bad;
            if (kHarlot[i].lo > 1 && std::string(
                    dm::cityHarlotKind(kHarlot[i].lo - 1))
                == kHarlot[i].k) ++bad;
        }
        // the sweep: every percentile yields a kind on
        // both tables (the clamps cover <1 / >100)
        for (int p = 1; p <= 100; ++p) {
            if (!*dm::cityDrunkKind(p)) ++bad;
            if (!*dm::cityHarlotKind(p)) ++bad;
        }
        printf("R146 city flavor audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R145: PHB p.38 weapon table audit ----
    // The per-weapon 'to hit' adjustment rows - PHB p.38,
    // both charts (melee weapons from the first, bows,
    // crossbow, and sling from the hurled/missile chart),
    // transcribed from the 1eonline.info compilation,
    // the repo-trusted source; the PHB re-upload still
    // owes the book-verify pass. Column order is the
    // book's: AC 0..10. The 3-class approximation R144
    // named closes here - the engine now carries the real
    // rows; the old rules::weaponVsAcAdjustment class
    // table stays pinned by the R144 audit (fallback).
    {
        int bad = 0;
        // every cell of every row (15 x 11 = 165 pins)
        static const int kRows[items::WPN_COUNT][11] = {
            // Dagger
            {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 },
            // Hand Axe
            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 },
            // Short Sword
            {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 },
            // Long Sword
            {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 },
            // Battle Axe
            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 },
            // Mace
            {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 },
            // Flail
            {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 },
            // Morning Star
            { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 },
            // Spear
            {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 },
            // Quarterstaff
            {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 },
            // Club
            {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 },
            // Short Bow
            {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 },
            // Long Bow
            {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 },
            // Light Crossbow
            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },
            // Sling
            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },
        };
        for (int i = 0; i < items::WPN_COUNT; ++i) {
            const items::WeaponDef& w =
                items::weapon((items::WeaponId)i);
            for (int ac = 0; ac <= 10; ++ac)
                if (w.acAdj[ac] != kRows[i][ac]) ++bad;
        }
        // the clamps: the table runs AC 0..10
        if (items::weaponAcAdjustment(
                items::WPN_DAGGER, -3) != -4) ++bad;
        if (items::weaponAcAdjustment(
                items::WPN_DAGGER, 12) != 3) ++bad;
        // composition: STR 17 (+1), a +1 dagger, and the
        // p.38 row - vs. AC 10 (+3) that is +5; vs. AC 0
        // (-4) that is -2
        {
            items::WeaponInstance w;
            w.id = items::WPN_DAGGER;
            w.plus = 1;
            rules::ExceptionalStrength noEx;
            if (items::attackAdjustment(w, noEx, 17, 10)
                != 5) ++bad;
            if (items::attackAdjustment(w, noEx, 17, 0)
                != -2) ++bad;
        }
        // the p.71 closure: the sling bullet's +3 vs. no
        // armor - a named R144 approximation - is now the
        // engine's own row
        if (items::weaponAcAdjustment(
                items::WPN_SLING, 10) != 3) ++bad;
        // and the p.71 example's axe '+1 vs. no armor' is
        // one of the book's editorial errors: the p.38
        // battle axe row reads +2, and the engine follows
        // p.38 (Gygax: the example 'slipped past and never
        // got corrected')
        if (items::weaponAcAdjustment(
                items::WPN_BATTLE_AXE, 10) != 2) ++bad;
        printf("R145 weapon table audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R144: p.71 golden melee audit ----
    // The book's own worked fight, transcribed from the
    // 1eonline.info compilation (the DMG re-upload's OCR
    // died in the preface - the book-verify debt stands).
    // The engine matches every printed matrix cell, the
    // STR 17 adjustments, the fighter save, and the mace-
    // vs-plate row. The example's other weapon numbers are
    // the book's own editorial errors (Gygax, on the
    // example: 'added by the editors, thus slipped past
    // and never got corrected') or per-weapon rows beyond
    // the engine's 3-class p.38 approximation - both
    // pinned here AS the engine's values, both named in
    // the gap report.
    {
        int bad = 0;
        // Aggro the Axe, F4, vs. Balto unarmored (AC 10):
        // the book - 'Aggro needs a base 8 to hit Balto'
        if (rules::attackNumber(0, 4, 10) != 8) ++bad;
        // Arlanni, T2, sling vs. Blastum unarmored:
        // 'would usually need an 11 to hit'
        if (rules::attackNumber(3, 2, 10) != 11) ++bad;
        // Gutboy Barrelhouse, F6 dwarf, hammer vs. Arkayn
        // in scale mail and shield (AC 5): '11 before
        // bonuses'
        if (rules::attackNumber(0, 6, 5) != 11) ++bad;
        // Barjin, F4 side of the 4/5 F/MU, sword vs. the
        // same cleric: 'needs a 13 or better to hit'
        if (rules::attackNumber(0, 4, 5) != 13) ++bad;
        // Arkayn, C4, mace vs. Gutboy's effective AC 1:
        // 'Arkayn needs a base 17 to hit AC 1'
        if (rules::attackNumber(2, 4, 1) != 17) ++bad;
        // Balto the monk, staff vs. Aggro in plate and
        // shield (AC 2): the book's base 18 - the engine
        // has no monk class (4 classes), so the pin rides
        // the fighter L1 approximation, and the number
        // still agrees
        if (rules::attackMatrixFighter(1, 2) != 18) ++bad;
        // Gutboy's STR 17: '+l to hit due to strength'
        // and '1 point of bonus damage from strength'
        {
            rules::ExceptionalStrength noEx;
            if (rules::strHitAdj(17, noEx) != 1) ++bad;
            if (rules::strDmgAdj(17, noEx) != 1) ++bad;
        }
        // Gutboy's save vs. Arkayn's command: the book -
        // 'he therefore needs a 10 or better to save
        // (instead of a 14)' - a 6th-level fighter's
        // spell save is the printed 14
        if (rules::saveTarget(0, 6, rules::SAVE_SPELLS)
            != 14) ++bad;
        // Arkayn's mace vs. Gutboy's splint mail (the
        // book's AC type 3): '+1 armor class adjustment,
        // so he really only needs a 16 or better' - the
        // engine's bludgeoning-vs-plate row is the same
        // +1, so 17 - 1 = 16
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_PLATE) != 1) ++bad;
        if (rules::attackNumber(2, 4, 1) -
            rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_PLATE) != 16) ++bad;
        // THE DIVERGENCES - pinned as the engine's values,
        // with the book's numbers in the comments:
        // Aggro's axe: the book gives the specific-weapon
        // row '+1 to hit vs. no armor' (base 8 - 1 magic -
        // 1 axe = 6); the engine's 3-class approximation
        // is slashing-neutral vs. no armor (8 - 1 magic =
        // 7). Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_SLASHING,
                rules::AC_TYPE_NONE) != 0) ++bad;
        // Arlanni's sling bullet: the book's row is +3 vs.
        // no armor (11 - 3 = 8 needed); the engine's
        // piercing class is neutral vs. no armor (11
        // needed). Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_PIERCING,
                rules::AC_TYPE_NONE) != 0) ++bad;
        // Gutboy's hammer vs. scale mail: the book's row
        // is +1 (11 - 1 STR - 1 hammer = 9); the engine's
        // bludgeoning class is neutral vs. leather/scale.
        // Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_LEATHER) != 0) ++bad;
        // Balto's staff: the book's '-7 armor class
        // adjustment' (18 + 7 = 20 needed) is one of the
        // example's editorial errors - the same sentence
        // even names 'sword vs. plate mail and shield'
        // for a staff attack, and Gygax confirmed the
        // example 'slipped past and never got corrected'.
        // The engine's staff (bludgeoning) vs. Aggro's
        // plate (AC 2 = the chain column) is neutral. The
        // engine does NOT copy the book's error.
        if (rules::attackNumber(0, 1, 2) != 18) ++bad;
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_CHAIN) != 0) ++bad;
        // Gutboy the dwarf's CON 16 save bonus: the book
        // applies '+4' to the spell save (14 - 4 = 10);
        // the engine models the CON adjustment only vs.
        // poison, not the dwarf's magic saves. Named gap,
        // gap report.
        // (no engine hook to pin - the gap is the pin)
        printf("R144 golden melee audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R143: crypt wing audit ----
    // The sample dungeon's crypts are delved at last:
    // three crypt chambers off a spine south of the
    // dome, SEALED behind the seventh knob's door (rock
    // until openCryptDoor turns it), laired per the
    // book's crypt-column area hints, and the crypt
    // wandering column wired - the evil cleric row rides
    // the Character-foe path in the engine (no audit
    // hook; the row's hobgoblins are pinned in R142).
    {
        int bad = 0;
        dm::DungeonResult d =
            dm::sampledungeon::buildSampleDungeon();
        // the crypt wing hangs south of the dome
        if (d.rooms.size() < 6) {
            ++bad;
        } else {
            if (d.rooms[3].x != 40 || d.rooms[3].y != 38 ||
                d.rooms[3].w != 4 || d.rooms[3].h != 3) ++bad;
            if (d.rooms[4].x != 46 || d.rooms[4].y != 38 ||
                d.rooms[4].w != 4 || d.rooms[4].h != 3) ++bad;
            if (d.rooms[5].x != 52 || d.rooms[5].y != 38 ||
                d.rooms[5].w != 4 || d.rooms[5].h != 3) ++bad;
        }
        // the crypt chambers are carved walkable
        for (int i = 3; i < 6 && i < (int)d.rooms.size();
             ++i) {
            const dm::GeneratedRoom& r = d.rooms[i];
            for (int yy = 0; yy < r.h; ++yy)
                for (int xx = 0; xx < r.w; ++xx)
                    if (!d.map.walkable(r.x + xx, r.y + yy))
                        ++bad;
        }
        // the descent and the spine
        if (!d.map.walkable(47, 35) ||
            !d.map.walkable(47, 36)) ++bad;
        for (int x = 40; x <= 55; ++x)
            if (!d.map.walkable(x, 37)) ++bad;
        // the knob door is SEALED rock until turned
        if (d.map.walkable(dm::sampledungeon::kCryptDoorX,
                          dm::sampledungeon::kCryptDoorY))
            ++bad;
        if (dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;
        dm::sampledungeon::openCryptDoor(d.map);
        if (!dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;
        if (d.map.at(dm::sampledungeon::kCryptDoorX,
                     dm::sampledungeon::kCryptDoorY) !=
            world::TILE_DOOR) ++bad;
        // the wing's boundary: the halls sit above the
        // knob, the crypts below it
        if (dm::sampledungeon::inCrypts(31, 31)) ++bad;
        if (!dm::sampledungeon::inCrypts(47, 37)) ++bad;
        if (!dm::sampledungeon::inCrypts(53, 40)) ++bad;
        // the crypt texts: nonempty, pure ASCII
        for (int i = 3; i < 6; ++i) {
            const char* t =
                dm::sampledungeon::sampleRoomText(i);
            if (!t || !t[0]) { ++bad; continue; }
            for (const char* p = t; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        printf("R143 crypt wing audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R142: sample dungeon audit ----
    // The DMG's own sample delve (pp.94-96, the MONASTERY
    // CELLARS) is keyed as pure data: three rooms (room 0
    // exactly the book 30 foot square entry chamber = 3x3
    // tiles at 10 feet), the two d4 wandering tables, and
    // the keyed texts. The crypt column, the crypt-cleric
    // row, and the crypts behind the seventh knob ride the
    // future-crypts debt (data now, delve later).
    {
        int bad = 0;
        // the sample seed is not the default delve seed
        if (dm::sampledungeon::kSampleSeed == 1) ++bad;
        dm::DungeonResult d =
            dm::sampledungeon::buildSampleDungeon();
        // six rooms: the three keyed chambers plus the
        // three crypt chambers of the R143 crypt wing
        if (d.rooms.size() != 6) {
            ++bad;
        } else {
            if (d.rooms[0].x != 30 || d.rooms[0].y != 30) ++bad;
            if (d.rooms[0].w != 3 || d.rooms[0].h != 3) ++bad;
            if (d.rooms[1].w != 4 || d.rooms[1].h != 5) ++bad;
            if (d.rooms[2].w != 4 || d.rooms[2].h != 4) ++bad;
        }
        // the entry stair lands at the chamber center
        if (d.entryX != 31 || d.entryY != 31) ++bad;
        if (!d.map.walkable(d.entryX, d.entryY)) ++bad;
        // every room tile is walkable
        for (int i = 0; i < (int)d.rooms.size(); ++i) {
            const dm::GeneratedRoom& r = d.rooms[i];
            if (r.w <= 0 || r.h <= 0) { ++bad; continue; }
            for (int yy = 0; yy < r.h; ++yy)
                for (int xx = 0; xx < r.w; ++xx)
                    if (!d.map.walkable(r.x + xx, r.y + yy))
                        ++bad;
        }
        // the passage knits the three chambers together
        for (int x = 33; x <= 45; ++x)
            if (!d.map.walkable(x, 31)) ++bad;
        // determinism: two builds agree tile for tile
        {
            dm::DungeonResult d2 =
                dm::sampledungeon::buildSampleDungeon();
            for (int y = 0; y < world::MAP_TILES_Y; ++y)
                for (int x = 0; x < world::MAP_TILES_X; ++x)
                    if (d.map.at(x, y) != d2.map.at(x, y)) ++bad;
            if (d2.entryX != d.entryX ||
                d2.entryY != d.entryY) ++bad;
        }
        // the halls table, row for row (p.96)
        {
            dm::sampledungeon::SampleWanderingRow w;
            w = dm::sampledungeon::sampleWandering(false, 1);
            if (std::string(w.key) != "goblin" ||
                w.lo != 3 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 2);
            if (std::string(w.key) != "bandit" ||
                w.lo != 2 || w.hi != 5) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 3);
            if (std::string(w.key) != "giant_rat" ||
                w.lo != 7 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 4);
            if (std::string(w.key) != "fire_beetle" ||
                w.lo != 1 || w.hi != 2) ++bad;
        }
        // the crypt column, row for row (future data)
        {
            dm::sampledungeon::SampleWanderingRow w;
            w = dm::sampledungeon::sampleWandering(true, 1);
            if (std::string(w.key) != "ghoul" ||
                w.lo != 1 || w.hi != 2) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 2);
            if (std::string(w.key) != "hobgoblin" ||
                w.lo != 2 || w.hi != 2) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 3);
            if (std::string(w.key) != "giant_rat" ||
                w.lo != 7 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 4);
            if (std::string(w.key) != "skeleton" ||
                w.lo != 2 || w.hi != 5) ++bad;
        }
        // the six keyed texts: nonempty, pure ASCII
        for (int i = 0; i < 6; ++i) {
            const char* t =
                dm::sampledungeon::sampleRoomText(i);
            if (!t || !t[0]) { ++bad; continue; }
            for (const char* p = t; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        printf("R142 sample dungeon audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R141: engagement geometry audit ----
    // The R43 50' debt closes: a room fight opens at
    // the chamber's longest interior dimension in 10'
    // bands (floored at the 50' corridor convention,
    // capped at 120') - so the R116 long band (-5) is
    // finally reachable in play.
    {
        int bad = 0;
        // the pure helper: floor at 5, cap at 12, the
        // longest dimension wins
        if (rules::engagementBands(0, 0) != 5) ++bad;
        if (rules::engagementBands(2, 3) != 5) ++bad;
        if (rules::engagementBands(5, 5) != 5) ++bad;
        if (rules::engagementBands(7, 4) != 7) ++bad;
        if (rules::engagementBands(4, 9) != 9) ++bad;
        if (rules::engagementBands(12, 12) != 12) ++bad;
        if (rules::engagementBands(20, 30) != 12) ++bad;
        // the long band in play: a 12-tile chamber opens
        // at 120' - a sling (40' short) fires its long
        // shot at -5, and one band beyond is impossible
        int bands = rules::engagementBands(12, 5);
        if (bands != 12) ++bad;
        if (rules::missileRangeMod(bands * 10, 40) != -5)
            ++bad;
        if (!rules::missileInRange(bands * 10, 40)) ++bad;
        // the corridor convention holds: the old 50'
        // opening is the sling's medium band
        if (rules::missileRangeMod(50, 40) != -2) ++bad;
        if (rules::missileRangeMod(50, 50) != 0) ++bad;
        printf("R141 engagement geometry audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R140: final sweep audit ----
    // The Appendix H list is CLOSED: 52 mechanical,
    // 11 talky, and 2 dressing by design (anti-magic
    // needs a magic-use hook, enrages needs a berserk
    // hook - neither engine exists; documented). The
    // final twelve: animated, combination, enlarges,
    // false, gravity lesser/nil/varying, moves,
    // randomly-acts, sloping, symbiotic, wish
    // reversal (all conventions - names only).
    {
        int bad = 0;
        {
            int mech = 0, talky = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
                if (dm::appendixh::trickIsTalky(a)) ++talky;
            }
            if (mech != 52) ++bad;
            if (talky != 11) ++bad;
            if (mech + talky + 2 !=
                dm::appendixh::TRICK_ATTRIBUTE_COUNT) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANIMATED) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_COMBINATION) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENLARGES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FALSE) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_LESSER) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_NIL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_VARYING) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RANDOMLY_ACTS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SYMBIOTIC) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH_REVERSAL)) ++bad;
        // the two honest deeps stay dressing - by design
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC) ||
            dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        // and the twelve never talk
        if (dm::appendixh::trickIsTalky(
                dm::appendixh::TA_ANIMATED) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_RANDOMLY_ACTS) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_WISH_REVERSAL)) ++bad;
        printf("R140 final sweep audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R139: engine-deep change-family audit ----
    // The eleven deepest attributes are wired at last:
    // the change family (align, attribute, class,
    // minds, sex), both distorted readings, both
    // resisting readings, geases, disintegrates - the
    // mechanical set grows to forty (all conventions;
    // the print gives names only).
    {
        int bad = 0;
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_ALIGN) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_ATTRIBUTE) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_CLASS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_MINDS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_SEX)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISTORTED_WL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISTORTED_HD) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RESISTING_GENERAL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RESISTING_SPECIFIC) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GEASES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISINTEGRATES)) ++bad;
        // the honest deeps stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC) ||
            dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        // and the eleven never talk
        if (dm::appendixh::trickIsTalky(
                dm::appendixh::TA_CHANGE_ALIGN) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_GEASES) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_DISINTEGRATES)) ++bad;
        printf("R139 engine-deep change-family audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R138: talk-flavor parley audit ----
    // The talks-class attributes stay non-mechanical -
    // they answer the X key instead: the engage hook
    // logs each one's flavor line (repeatable; talk
    // never spends the trick).
    {
        int bad = 0;
        {
            int talky = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsTalky(a)) ++talky;
            if (talky != 11) ++bad;
        }
        // every talky line: nonempty, ASCII, distinct,
        // and never mechanical
        for (int a = 0;
             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
            if (!dm::appendixh::trickIsTalky(a)) continue;
            const char* la =
                dm::appendixh::trickTalkLine(a);
            if (!la || !*la) ++bad;
            for (const char* q = la; q && *q; ++q)
                if ((unsigned char)*q > 127) ++bad;
            if (dm::appendixh::trickIsMechanical(a)) ++bad;
            for (int b = a + 1;
                 b < dm::appendixh::TRICK_ATTRIBUTE_COUNT;
                 ++b) {
                if (!dm::appendixh::trickIsTalky(b)) continue;
                if (std::string(la) ==
                        std::string(
                            dm::appendixh::trickTalkLine(b)))
                    ++bad;
            }
        }
        // the smart line pinned exact
        if (std::string(dm::appendixh::trickTalkLine(
                dm::appendixh::TA_TALKS_SMART)) !=
            "The feature speaks learnedly of the dungeon's history.")
            ++bad;
        printf("R138 talk-flavor parley audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R137: deliberate-engage hook audit ----
    // The hook's pure surface: the engage prompt the
    // dungeon logs on first sight (sight alone no longer
    // springs a mechanical curiosity - the company
    // chooses; the X key engages).
    {
        int bad = 0;
        const char* p = dm::appendixh::trickEngagePrompt();
        if (!p || !*p) ++bad;
        if (std::string(p) !=
            "Press X to engage the feature - or move on.")
            ++bad;
        for (const char* q = p; q && *q; ++q)
            if ((unsigned char)*q > 127) ++bad;
        printf("R137 deliberate-engage hook audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R136: odds-and-ends slice audit ----
    // The stragglers are wired: the R135 twenty-four
    // plus rising, suspends, appearing, invisible, and
    // gaseous (all conventions - the print gives no
    // figures). Anti-magic STAYS dressing: an honest
    // suppression zone needs a magic-use hook the
    // engine does not expose yet.
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (the
        // R136 five: rising, suspends, appearing,
        // invisible, gaseous)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R136 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RISING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUSPENDS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_APPEARING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_INVISIBLE)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GASEOUS)) ++bad;
        // the unwired deeps stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        printf("R136 odds-and-ends slice audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R135: room-geometry slice audit ----
    // The Appendix H mechanical set grows to
    // twenty-four: the R134 nineteen plus one-way,
    // pivots, spinning, shifting, and sliding (all
    // positional conventions - the print gives no
    // mechanics; each moves or commits the company
    // within the room rect).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R135 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ONE_WAY)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_PIVOTS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SPINNING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHIFTING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLIDING)) ++bad;
        // the R140 final sweep wired sloping and moves
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES)) ++bad;
        printf("R135 room-geometry slice audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R134: deep-effects slice audit ----
    // The deep waters are wired: the R133 sixteen plus
    // wish, gravity greater, and polymorph (all
    // conventions - the print gives no figures; the
    // wish stays benevolent: heal the company, restore
    // a member, or a gold shower).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (R135
        // and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R134 three are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POLYMORPH)) ++bad;
        // the talk-flavor set stays dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_SMART)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUGGESTS)) ++bad;
        printf("R134 deep-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R133: third-effects slice audit ----
    // The Appendix H mechanical set grows to sixteen: the
    // R132 eleven plus attacks, fruit, greed, teleports,
    // and collapsing (all conventions - the print gives
    // no figures for these five; the teleport follows
    // the print's intra-level AREA example).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65
        // (R135 and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R133 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ATTACKS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FRUIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GREED)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TELEPORTS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_COLLAPSING)) ++bad;
        // the talk-flavor set stays dressing (R134 wired
        // the deep waters: wish, gravity, polymorph)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_SMART)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUGGESTS)) ++bad;
        printf("R133 third-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R132: second-effects slice audit ----
    // The Appendix H mechanical set grows to eleven: the
    // R128 five plus ages, flesh to stone, both shocks,
    // counterfeit coins, and takes/steals (print sources:
    // the altar ages 10 years, the face petrifies on a
    // failed save, the pedestal shocks 5-50 hp;
    // counterfeit crumbles worthless; takes/steals is a
    // convention - the print gives no figure).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (R135 and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R132 six are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_AGES)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FLESH_TO_STONE)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_METAL)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_MAGIC)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TAKES)) ++bad;
        // the flavor set stays dressing (R134 wired the
        // deep waters: wish and gravity are mechanical)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_POETRY)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POINTS)) ++bad;
        printf("R132 second-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R129: caster aging audit ----
    {
        int bad = 0;
        // the registry grew to 54: MU 31, CL 23
        if (spells::SPELL_COUNT != 54) ++bad;
        {
            int mu = 0, cl = 0;
            for (int id = 0; id < spells::SPELL_COUNT; ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_MU) ++mu;
                else ++cl;
            }
            if (mu != 31 || cl != 23) ++bad;
        }
        // the six p.14 rows: name, class, level, self-target
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_LIMITED_WISH);
            if (std::string(d.name) != "Limited Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_ALTER_REALITY);
            if (std::string(d.name) != "Alter Reality" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_WISH);
            if (std::string(d.name) != "Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_GATE);
            if (std::string(d.name) != "Gate" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESTORATION);
            if (std::string(d.name) != "Restoration" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESURRECTION);
            if (std::string(d.name) != "Resurrection" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        // the DMG p.14 pins: the caster-aged causes
        if (spells::magicalAgingYears(
                spells::MU_LIMITED_WISH) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESTORATION) != 2) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_ALTER_REALITY) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_WISH) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESURRECTION) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_GATE) != 5) ++bad;
        // the R115 precedent stands
        if (spells::magicalAgingYears(
                spells::MU_HASTE) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_FIREBALL) != 0) ++bad;
        // R130: the printed tables now encode 1-9; these
        // 12th-level pins still hold (no 7th-9th at 12)
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 7) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 9) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_CLERIC, 12, 7) != 0) ++bad;
        printf("R129 caster aging audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----
    {
        int bad = 0;
        // the hire rides the same clock, from an unknown
        // youth default
        {
            Party p;
            if (p.henchmanStartAge != 0) ++bad;
            p.henchmanStartAge = 17;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 364;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 365;
            if (hireAgeYears(p) != 18) ++bad;
            p.careerDays = 3650;
            if (hireAgeYears(p) != 27) ++bad;
        }
        // the save/load contract, PINNED: a present flag,
        // four ints, the NAME, then six trailing ints (the
        // pre-R100 save put the name last and never loaded)
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (present != 1) ++bad;
            if (hp != 8 || mx != 8 || lv != 1 || loy != 50)
                ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge);
            if (got != 6) ++bad;
            if (hxp != 2000 || hpu != 300 || dgv != 500)
                ++bad;
            if (wpl != 1 || spl != 1) ++bad;
            if (hge != 17) ++bad;
        }
        printf("R100 hire's years audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R101: plate kit audit ----
    {
        int bad = 0;
        // the extended contract, PINNED: seven trailing
        // ints now - the seventh is the plate kit
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl);
            if (got != 7) ++bad;
            if (hpl != 1) ++bad;
        }
        // the plate off - the trailing 0 parses too
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 1;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl) != 7) ++bad;
            if (hpl != 0) ++bad;
        }
        // the crew line parses both ways
        {
            int cw = -1;
            char tg[16];
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1;
            if (sscanf("crew 0", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 0) ++bad;
        }
        // the plate buys plate: the R46 ladder top
        {
            Party p;
            if (p.henchmanPlate) ++bad;
            if (p.party_plate_kit() != items::ARMOR_CHAIN_MAIL)
                ++bad;
            p.henchmanPlate = true;
            if (p.party_plate_kit() != items::ARMOR_PLATE)
                ++bad;
        }
        // a fresh crew is not hired (the save default)
        {
            Party p;
            if (p.crewHired) ++bad;
        }
        printf("R101 plate kit audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R102: ledger of everything audit ----
    {
        int bad = 0;
        // the field-vs-save sweep, PINNED: every durable
        // Party/Character field has a save tag; the only
        // transient fields are by documented design
        {
            Party p;
            p.gold = 100; p.kills = 5; p.potions = 3;
            p.scrolls = 2; p.careerDays = 10;
            p.delveCount = 4; p.deepestLevel = 6;
            p.totalGold = 9000; p.identifyScrolls = 1;
            p.strongholdBuilt = true; p.strongholdOwner = 0;
            p.crewHired = true; p.formed = true;
            // a fresh party defaults clean - the sweep's
            // zero-state: nothing durable is left behind
            Party q;
            if (q.gold != 0 || q.kills != 0) ++bad;
            if (q.scrolls != 0 || q.potions != 0) ++bad;
            if (q.careerDays != 0) ++bad;
            if (q.delveCount != 0 || q.totalGold != 0)
                ++bad;
            if (q.strongholdBuilt || q.crewHired) ++bad;
            if (q.henchmanPresent || q.henchmanPlate) ++bad;
            if (q.identifyScrolls != 0) ++bad;
        }
        // the carried-scrolls line parses, both ways
        {
            int scr = -1;
            char tg[16];
            if (sscanf("cscrolls 7", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (std::string(tg) != "cscrolls" || scr != 7)
                ++bad;
            scr = -1;
            if (sscanf("cscrolls 0", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (scr != 0) ++bad;
        }
        // the tag is distinct from idscrolls (both load
        // branches must route independently)
        {
            char tg1[16] = "", tg2[16] = "";
            int a = -1, b = -1;
            if (sscanf("idscrolls 2", "%15s %d", tg1, &a)
                != 2) ++bad;
            if (sscanf("cscrolls 5", "%15s %d", tg2, &b)
                != 2) ++bad;
            if (std::string(tg1) == std::string(tg2))
                ++bad;
            if (a != 2 || b != 5) ++bad;
        }
        // the guard matches the cap the dungeon adds with
        if (CARRIED_CAP != 9999) ++bad;
        printf("R102 ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R103: carrot audit ----
    {
        int bad = 0;
        // the upkeep ladder: 100/level, +100 for the raise
        if (henchmanUpkeep(1, false) != 100) ++bad;
        if (henchmanUpkeep(1, true)  != 200) ++bad;
        if (henchmanUpkeep(3, false) != 300) ++bad;
        if (henchmanUpkeep(3, true)  != 400) ++bad;
        // the carrot weights
        if (loyaltyGift() != 5)  ++bad;
        if (loyaltyRaise() != 10) ++bad;
        // the gift cannot farm past contentment: the gate
        // is the PRE-gift loyalty, the drift clamps at 125
        if (loyaltyDrift(99, loyaltyGift()) != 104) ++bad;
        if (loyaltyDrift(125, loyaltyGift()) != 125) ++bad;
        // a fresh hire has taken no raise
        {
            Party p;
            if (p.henchmanRaise) ++bad;
            if (henchmanUpkeep(p.henchmanLevel,
                               p.henchmanRaise) != 100) ++bad;
        }
        // the contract, PINNED at eight trailing ints (the
        // eighth is the raise; older saves stop at seven)
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1, 1);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0, hrr = 0;
            int got = sscanf(line + pos,
                             "%d %d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl, &hrr);
            if (got != 8) ++bad;
            if (hpl != 1 || hrr != 1) ++bad;
        }
        // raise off parses too
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0, 0);
            int pos = 0;
            char tg[16];
            int present, hp, mx, lv, loy;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp, hpu, dgv, wpl, spl, hge, hpl = 1, hrr = 1;
            hxp = hpu = dgv = wpl = spl = hge = 0;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl, &hrr) != 8) ++bad;
            if (hpl != 0 || hrr != 0) ++bad;
        }
        printf("R103 carrot audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R104: scales audit ----
    {
        int bad = 0;
        Party p;
        MessageLog log;
        // a short purse refuses, moves no gold, and the
        // refusal is the shop's own words
        p.gold = 49;
        if (spendGold(p, log, 50,
                      "The priest shakes his head - 50 gp."))
            ++bad;
        if (p.gold != 49) ++bad;
        if (log.get(0) !=
            "The priest shakes his head - 50 gp.") ++bad;
        // exact coin spends to zero
        p.gold = 50;
        if (!spendGold(p, log, 50, "The fletcher wants 30 gp."))
            ++bad;
        if (p.gold != 0) ++bad;
        // a fat purse pays and keeps the change
        p.gold = 200;
        if (!spendGold(p, log, 75, "The armorer wants 75 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        // and refuses at 125 what it afforded at 200
        if (spendGold(p, log, 126, "The scribe wants 200 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        if (log.get(0) != "The scribe wants 200 gp.") ++bad;
        printf("R104 scales audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R105: crew nerve audit ----
    {
        int bad = 0;
        // the drift weights and the floor
        if (crewDriftPaid()   !=  2)   ++bad;
        if (crewDriftUnpaid() != -10)  ++bad;
        if (crewDriftShare()  !=  3)   ++bad;
        if (crewHireMorale()  !=  60)  ++bad;
        if (crewDesertBelow() !=  25)  ++bad;
        // the clamp bounds
        if (clampCrewMorale(-1) != 0)     ++bad;
        if (clampCrewMorale(101) != 100)  ++bad;
        if (clampCrewMorale(60)  != 60)   ++bad;
        // the desertion arithmetic: three unpaid wages
        // from a fresh signing, then the floor
        {
            Party p;
            p.crewHired = true;
            p.crewMorale = crewHireMorale();
            for (int i = 0; i < 3; ++i)
                p.crewMorale = clampCrewMorale(
                    p.crewMorale + crewDriftUnpaid());
            // 60 - 30 = 30, still aboard
            if (p.crewMorale != 30) ++bad;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftUnpaid());
            // 20, below the 25 floor - desertion
            if (p.crewMorale >= crewDesertBelow()) ++bad;
        }
        // the recovery path: two paid wages + a share
        // from 30
        {
            Party p;
            p.crewMorale = 30;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftShare());
            if (p.crewMorale != 37) ++bad;
        }
        // the crew line contract: flag then morale, and
        // the older one-int form still parses
        {
            int cw = -1, cm = -1;
            char tg[16];
            if (sscanf("crew 1 60", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 1 || cm != 60) ++bad;
            cw = -1;
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1; cm = -1;
            if (sscanf("crew 0 0", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 0 || cm != 0) ++bad;
        }
        printf("R105 crew nerve audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R106: keep ledger audit ----
    {
        int bad = 0;
        // the month clock: 30 career days to the month
        if (keepUpkeepPerMonth() != 200) ++bad;
        if (keepMonthsElapsed(0, 90, 0) != 3)  ++bad;
        if (keepMonthsElapsed(0, 90, 3) != 0)  ++bad;
        if (keepMonthsElapsed(0, 90, 4) != 0)  ++bad;
        if (keepMonthsElapsed(0, 29, 0) != 0)  ++bad;
        if (keepMonthsElapsed(40, 100, 0) != 2) ++bad;
        // an unknown build day bills nothing (the billing
        // site stamps it first)
        if (keepMonthsElapsed(-1, 500, 0) != 0) ++bad;
        // a fresh party owes the keep nothing
        {
            Party p;
            if (p.strongholdBuilt) ++bad;
            if (p.strongholdBuiltDay != -1) ++bad;
            if (p.strongholdMonthsBilled != 0) ++bad;
            if (p.strongholdDebt != 0) ++bad;
        }
        // the garnish arithmetic: rents vs a standing debt
        {
            Party p;
            p.strongholdDebt = 500;
            int g = (p.strongholdDebt < 200)
                        ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 300) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 100) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 100 || p.strongholdDebt != 0) ++bad;
        }
        // a half-year idle keep bills six months
        {
            Party p;
            p.strongholdBuilt = true;
            p.strongholdBuiltDay = 0;
            p.careerDays = 185;
            int months = keepMonthsElapsed(
                p.strongholdBuiltDay, p.careerDays,
                p.strongholdMonthsBilled);
            if (months != 6) ++bad;
            if (months * keepUpkeepPerMonth() != 1200)
                ++bad;
        }
        // the stronghold line contract: the legacy two-int
        // form and the five-int form both parse
        {
            char tg[16];
            int b = -1, ow = -1, bd = -9, mb = -9, dt = -9;
            if (sscanf("stronghold 1 0 40 2 150",
                       "%15s %d %d %d %d %d",
                       tg, &b, &ow, &bd, &mb, &dt) != 6)
                ++bad;
            if (b != 1 || ow != 0 || bd != 40 ||
                mb != 2 || dt != 150) ++bad;
            b = -1; ow = -1;
            if (sscanf("stronghold 1 0", "%15s %d %d",
                       tg, &b, &ow) != 3) ++bad;
            if (b != 1 || ow != 0) ++bad;
        }
        printf("R106 keep ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R109: turning undead audit (DMG p.75-76 matrix III) ----
    {
        int bad = 0;
        // the printed table, spot-checked cell for cell
        {
            struct Cell { int lvl, kind, result, target, count; };
            const Cell cells[] = {
                { 1,  0, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                { 1,  1, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_12 },
                { 1,  2, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                { 1,  3, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 1,  4, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 1,  5, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
                { 2,  5, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 3,  6, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 4,  7, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 5,  8, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 6,  9, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 7, 10, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 8, 11, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 8, 12, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_2  },
                { 4,  0, rules::TURN_ALL,      0, rules::TURN_COUNT_1_12 },
                { 6,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_1_12 },
                { 8,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 9, 11, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                {14, 11, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                {14, 12, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_2  },
                {20,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 0,  0, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
            };
            for (const Cell& c : cells) {
                rules::TurnAttempt t = rules::turnUndead(c.lvl, c.kind);
                if (t.result != c.result || t.target != c.target ||
                    t.countKind != c.count) ++bad;
            }
        }
        // every cell of the table is a legal value
        for (int kind = 0; kind < 13; ++kind) {
            for (int lvl = 1; lvl <= 20; ++lvl) {
                rules::TurnAttempt t = rules::turnUndead(lvl, kind);
                if (t.result == rules::TURN_CHANCE &&
                    (t.target < 4 || t.target > 20)) ++bad;
                if (t.result == rules::TURN_NONE) {
                    // dashes only past skeleton and zombie
                    if (kind == 0 || kind == 1) ++bad;
                }
            }
        }
        // the roll and count mechanics stay in bounds
        {
            rules::Rng rng(109);
            rules::Dice dice(rng);
            int seen1to12 = 0, seen7to12 = 0, seen1to2 = 0;
            int success = 0;
            for (int i = 0; i < 20000; ++i) {
                rules::TurnAttempt t =
                    rules::turnUndead(1, 0);   // skeleton, target 10
                if (rules::rollTurnSuccess(dice, t)) {
                    ++success;
                    int n = rules::rollTurnCount(dice, t);
                    if (n < 1 || n > 12) ++bad;
                    if (n == 12) seen1to12 = 1;
                }
                rules::TurnAttempt s =
                    rules::turnUndead(14, 12); // special, 1-2
                int n = rules::rollTurnCount(dice, s);
                if (n < 1 || n > 2) ++bad;
                if (n == 2) seen1to2 = 1;
                rules::TurnAttempt d =
                    rules::turnUndead(8, 0);   // D* skeleton
                int m = rules::rollTurnCount(dice, d);
                if (m < 7 || m > 12) ++bad;
                if (m == 7) seen7to12 = 1;
            }
            if (seen1to12 == 0 || seen1to2 == 0 ||
                seen7to12 == 0) ++bad;
            if (success == 0 || success == 20000) ++bad;
        }
        printf("R109 turn audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R110: saving throws audit (DMG p.79-80 matrix I) ----
    {
        int bad = 0;
        // the banded tables, pinned band by band (repo category
        // order: Death, Wands, Petrify, Breath, Spells)
        {
            struct SC { int cls, lvl, cat, want; };
            const SC sc[] = {
                // fighter 1-2 band
                {0, 1, rules::SAVE_DEATH_POISON,  14},
                {0, 1, rules::SAVE_WANDS,         16},
                {0, 1, rules::SAVE_PETRIFY_POLY,  15},
                {0, 1, rules::SAVE_BREATH,        17},
                {0, 1, rules::SAVE_SPELLS,        17},
                {0, 2, rules::SAVE_DEATH_POISON,  14},  // band mate
                {0, 0, rules::SAVE_DEATH_POISON,  16},  // 0-level row
                {0, 3, rules::SAVE_DEATH_POISON,  13},  // 3-4 band
                {0, 9, rules::SAVE_SPELLS,        11},  // 9-10 band
                {0, 9, rules::SAVE_BREATH,         9},  // dips below wands
                {0, 17, rules::SAVE_DEATH_POISON,  3},  // 17+ band
                {0, 25, rules::SAVE_DEATH_POISON,  3},  // beyond: last band
                // cleric - the big fix: L1 death save is 10, not 14
                {2, 1, rules::SAVE_DEATH_POISON,  10},
                {2, 1, rules::SAVE_WANDS,         14},
                {2, 3, rules::SAVE_DEATH_POISON,  10},  // band 1-3
                {2, 4, rules::SAVE_DEATH_POISON,   9},  // band 4-6
                {2, 12, rules::SAVE_SPELLS,        11}, // band 10-12
                {2, 19, rules::SAVE_DEATH_POISON,   2}, // 19+ band
                // magic-user
                {1, 1, rules::SAVE_DEATH_POISON,  14},
                {1, 1, rules::SAVE_WANDS,         11},
                {1, 5, rules::SAVE_SPELLS,        12},  // band 1-5
                {1, 6, rules::SAVE_SPELLS,        10},  // band 6-10
                {1, 21, rules::SAVE_SPELLS,         4}, // 21+ band
                {1, 25, rules::SAVE_SPELLS,         4},
                // thief (1-4 happens to match the old linear row)
                {3, 1, rules::SAVE_DEATH_POISON,  13},
                {3, 1, rules::SAVE_WANDS,         14},
                {3, 4, rules::SAVE_DEATH_POISON,  13},  // band 1-4
                {3, 5, rules::SAVE_DEATH_POISON,  12},  // band 5-8
                {3, 21, rules::SAVE_SPELLS,         5},  // 21+ band
            };
            for (const SC& s : sc) {
                if (rules::saveTarget(s.cls, s.lvl,
                                       (rules::SaveCategory)s.cat)
                    != s.want) ++bad;
            }
        }
        // the tables never worsen with level and stay in bounds
        for (int cls = 0; cls < 4; ++cls) {
            for (int cat = 0; cat < rules::SAVE_COUNT; ++cat) {
                int prev = 99;
                for (int lvl = 1; lvl <= 25; ++lvl) {
                    int v = rules::saveTarget(cls, lvl,
                                              (rules::SaveCategory)cat);
                    if (v < 2 || v > 20) ++bad;
                    if (v > prev) ++bad;
                    prev = v;
                }
            }
        }
        // monster HD -> save level (matrix II.B stepping)
        {
            const float hds[]  = { 0.5f, 1.0f, 1.25f, 1.5f, 1.75f,
                                  2.25f, 2.5f, 4.8f, 16.0f, 40.0f };
            const int   want[] = { 1, 1, 2, 2, 2, 3, 3, 5, 16, 21 };
            for (int i = 0; i < 10; ++i)
                if (rules::monsterSaveLevel(hds[i]) != want[i]) ++bad;
        }
        // a natural 1 is ALWAYS failure, whatever the modifier
        {
            rules::Rng rng(110);
            rules::Dice dice(rng);
            int fails = 0;
            for (int i = 0; i < 20000; ++i) {
                // target 1, modifier +19: only a natural 1 fails
                if (!rules::attemptSave(dice, 1, 19)) ++fails;
            }
            if (fails == 0 || fails == 20000) ++bad;
        }
        printf("R110 saves audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R111: fighter attack matrix audit (DMG p.75 I.B) ----
    {
        int bad = 0;
        // the printed table, pinned band by band
        {
            struct TC { int lvl, ac, want; };
            const TC tc[] = {
                // AC 10 row across the bands (the negatives are the
                // book's own: a 17+ fighter hits AC 10 on any roll)
                { 1, 10, 10}, { 2, 10, 10},   // band 1-2 mates
                { 3, 10,  8}, { 4, 10,  8},   // band 3-4
                { 5, 10,  6}, { 9, 10,  2},   // bands 5-6, 9-10
                {11, 10,  0}, {15, 10, -4}, {17, 10, -6},
                {20, 10, -6},                // 17+ is the last band
                // 0-level column (0-level humans and halflings)
                { 0, 10, 11}, { 0,  0, 20}, { 0, -5, 21}, { 0, -10, 26},
                // AC 0 row down the bands
                { 1,  0, 20}, { 3,  0, 18}, { 5,  0, 16},
                { 7,  0, 14}, { 9,  0, 12}, {11,  0, 10},
                {13,  0,  8}, {15,  0,  6}, {17,  0,  4},
                // the deep-AC rows
                { 1, -1, 20}, { 1, -5, 20}, { 1, -10, 25},
                {17, -10, 14},
                // negatives mid-table
                {13,  7,  1}, {15,  6,  0}, {17,  5, -1},
                // AC clamps: past 10 uses the AC 10 row,
                // past -10 the AC -10 row
                { 1, 12, 10}, { 1, -12, 25},
            };
            for (const TC& t : tc) {
                if (rules::attackMatrixFighter(t.lvl, t.ac) != t.want)
                    ++bad;
            }
        }
        // the table only improves with level, only worsens with AC,
        // and stays in the book's bounds at every cell
        for (int lvl = 0; lvl <= 20; ++lvl) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v < -6 || v > 26) ++bad;
                if (v < prevAc) ++bad;   // better AC never easier
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevLvl = 99;
            for (int lvl = 0; lvl <= 20; ++lvl) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v > prevLvl) ++bad;  // level never worsens
                prevLvl = v;
            }
        }
        // a negative target hits on everything but a natural 1
        {
            rules::Rng rng(111);
            rules::Dice dice(rng);
            int hits = 0;
            for (int i = 0; i < 20000; ++i) {
                if (rules::attackRollHits(dice, -6, 0)) ++hits;
            }
            if (hits == 0 || hits == 20000) ++bad;
        }
        printf("R111 attack matrix audit: bad %d\n", bad);
    }

    // ---- R112: monster attack matrix audit (DMG p.75-76 II) ----
    {
        int bad = 0;
        // the printed table: a representative hit dice for each
        // of the 12 bands, pinned at notable ACs
        {
            struct MC { float hd; int ac, want; };
            const MC mc[] = {
                {0.50f,  10,  11},  // band 0
                {0.50f,   0,  20},  // band 0
                {0.50f,  -5,  21},  // band 0
                {0.50f, -10,  26},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.00f,   0,  20},  // band 1
                {1.00f,  -5,  20},  // band 1
                {1.00f, -10,  25},  // band 1
                {1.30f,  10,   9},  // band 2
                {1.30f,   0,  19},  // band 2
                {1.30f,  -5,  20},  // band 2
                {1.30f, -10,  24},  // band 2
                {1.60f,  10,   8},  // band 3
                {1.60f,   0,  18},  // band 3
                {1.60f,  -5,  20},  // band 3
                {1.60f, -10,  23},  // band 3
                {2.00f,  10,   6},  // band 4
                {2.00f,   0,  16},  // band 4
                {2.00f,  -5,  20},  // band 4
                {2.00f, -10,  21},  // band 4
                {4.00f,  10,   5},  // band 5
                {4.00f,   0,  15},  // band 5
                {4.00f,  -5,  20},  // band 5
                {4.00f, -10,  20},  // band 5
                {6.00f,  10,   3},  // band 6
                {6.00f,   0,  13},  // band 6
                {6.00f,  -5,  18},  // band 6
                {6.00f, -10,  20},  // band 6
                {8.00f,  10,   2},  // band 7
                {8.00f,   0,  12},  // band 7
                {8.00f,  -5,  17},  // band 7
                {8.00f, -10,  20},  // band 7
                {10.00f, 10,   0},  // band 8
                {10.00f,  0,  10},  // band 8
                {10.00f, -5,  15},  // band 8
                {10.00f, -10, 20},  // band 8
                {12.00f, 10,  -1},  // band 9
                {12.00f,  0,   9},  // band 9
                {12.00f, -5,  14},  // band 9
                {12.00f, -10, 19},  // band 9
                {14.00f, 10,  -2},  // band 10
                {14.00f,  0,   8},  // band 10
                {14.00f, -5,  13},  // band 10
                {14.00f, -10, 18},  // band 10
                {16.00f, 10,  -3},  // band 11
                {16.00f,  0,   7},  // band 11
                {16.00f, -5,  12},  // band 11
                {16.00f, -10, 17},  // band 11
                {0.99f,  10,  11},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.25f,  10,   9},  // band 2
                {1.50f,  10,   8},  // band 3
                {2.00f,  10,   6},  // band 4
                {3.99f,  10,   6},  // band 4
                {4.00f,  10,   5},  // band 5
                {15.99f, 10,  -2},  // band 10
                {16.00f, 10,  -3},  // band 11
                {40.00f, 10,  -3},  // band 11
            };
            for (const MC& m : mc) {
                if (rules::attackMatrixMonster(m.hd, m.ac) != m.want)
                    ++bad;
            }
        }
        // the table only improves with hit dice, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v < -3 || v > 26) ++bad;
                if (v < prevAc) ++bad;
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevHd = 99;
            for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v > prevHd) ++bad;
                prevHd = v;
            }
        }
        printf("R112 monster matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R113: class attack matrices audit (DMG p.75 I.A/I.C/I.D) ----
    {
        int bad = 0;
        // the printed tables: a representative level for each band,
        // pinned at notable ACs (fighter keeps I.B, R111's audit)
        {
            struct CC { int cls, level, ac, want; };
            const CC cc[] = {
                {2,  1,  10,  10},  // cleric band 0
                {2,  1,   0,  20},  // cleric band 0
                {2,  1,  -5,  20},  // cleric band 0
                {2,  1, -10,  25},  // cleric band 0
                {2,  4,  10,   8},  // cleric band 1
                {2,  4,   0,  18},  // cleric band 1
                {2,  4,  -5,  20},  // cleric band 1
                {2,  4, -10,  23},  // cleric band 1
                {2,  7,  10,   6},  // cleric band 2
                {2,  7,   0,  16},  // cleric band 2
                {2,  7,  -5,  20},  // cleric band 2
                {2,  7, -10,  21},  // cleric band 2
                {2, 10,  10,   4},  // cleric band 3
                {2, 10,   0,  14},  // cleric band 3
                {2, 10,  -5,  19},  // cleric band 3
                {2, 10, -10,  20},  // cleric band 3
                {2, 13,  10,   2},  // cleric band 4
                {2, 13,   0,  12},  // cleric band 4
                {2, 13,  -5,  17},  // cleric band 4
                {2, 13, -10,  20},  // cleric band 4
                {2, 16,  10,   0},  // cleric band 5
                {2, 16,   0,  10},  // cleric band 5
                {2, 16,  -5,  15},  // cleric band 5
                {2, 16, -10,  20},  // cleric band 5
                {2, 19,  10,  -1},  // cleric band 6
                {2, 19,   0,   9},  // cleric band 6
                {2, 19,  -5,  14},  // cleric band 6
                {2, 19, -10,  19},  // cleric band 6
                {1,  1,  10,  11},  // MU band 0
                {1,  1,   0,  20},  // MU band 0
                {1,  1,  -5,  21},  // MU band 0
                {1,  1, -10,  26},  // MU band 0
                {1,  6,  10,   9},  // MU band 1
                {1,  6,   0,  19},  // MU band 1
                {1,  6,  -5,  20},  // MU band 1
                {1,  6, -10,  24},  // MU band 1
                {1, 11,  10,   6},  // MU band 2
                {1, 11,   0,  16},  // MU band 2
                {1, 11,  -5,  20},  // MU band 2
                {1, 11, -10,  21},  // MU band 2
                {1, 16,  10,   3},  // MU band 3
                {1, 16,   0,  13},  // MU band 3
                {1, 16,  -5,  18},  // MU band 3
                {1, 16, -10,  20},  // MU band 3
                {1, 21,  10,   1},  // MU band 4
                {1, 21,   0,  11},  // MU band 4
                {1, 21,  -5,  16},  // MU band 4
                {1, 21, -10,  20},  // MU band 4
                {3,  1,  10,  11},  // thief band 0
                {3,  1,   0,  20},  // thief band 0
                {3,  1,  -5,  21},  // thief band 0
                {3,  1, -10,  26},  // thief band 0
                {3,  5,  10,   9},  // thief band 1
                {3,  5,   0,  19},  // thief band 1
                {3,  5,  -5,  20},  // thief band 1
                {3,  5, -10,  24},  // thief band 1
                {3,  9,  10,   6},  // thief band 2
                {3,  9,   0,  16},  // thief band 2
                {3,  9,  -5,  20},  // thief band 2
                {3,  9, -10,  21},  // thief band 2
                {3, 13,  10,   4},  // thief band 3
                {3, 13,   0,  14},  // thief band 3
                {3, 13,  -5,  19},  // thief band 3
                {3, 13, -10,  20},  // thief band 3
                {3, 17,  10,   2},  // thief band 4
                {3, 17,   0,  12},  // thief band 4
                {3, 17,  -5,  17},  // thief band 4
                {3, 17, -10,  20},  // thief band 4
                {3, 21,  10,   0},  // thief band 5
                {3, 21,   0,  10},  // thief band 5
                {3, 21,  -5,  15},  // thief band 5
                {3, 21, -10,  20},  // thief band 5
                {2,  1,  10,  10},  // cleric L1 band 0
                {2,  3,  10,  10},  // cleric L3 band 0 edge
                {2,  4,  10,   8},  // cleric L4 band 1
                {2, 18,  10,   0},  // cleric L18 band 5
                {2, 19,  10,  -1},  // cleric L19+ band 6
                {1,  5,  10,  11},  // MU L5 band 0 edge
                {1,  6,  10,   9},  // MU L6 band 1
                {1, 20,  10,   3},  // MU L20 band 3
                {1, 21,  10,   1},  // MU L21+ band 4
                {3,  4,  10,  11},  // thief L4 band 0 edge
                {3,  5,  10,   9},  // thief L5 band 1
                {3, 20,  10,   2},  // thief L20 band 4
                {3, 21,  10,   0},  // thief L21+ band 5
            };
            for (const CC& m : cc) {
                if (rules::attackNumber(m.cls, m.level, m.ac) != m.want)
                    ++bad;
            }
        }
        // fighter (classIndex 0) still rides matrix I.B
        {
            int v = rules::attackNumber(0, 1, 10);
            if (v != 10) ++bad;
            v = rules::attackNumber(0, 0, 10);
            if (v != 11) ++bad;   // 0-level: I.B band 0
        }
        // each table only improves with level, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (int cls = 1; cls <= 3; ++cls) {
            for (int level = 1; level <= 21; ++level) {
                int prevAc = -99;
                for (int ac = 12; ac >= -12; --ac) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v < -6 || v > 26) ++bad;
                    if (v < prevAc) ++bad;
                    prevAc = v;
                }
            }
            for (int ac = 10; ac >= -10; --ac) {
                int prevLvl = 99;
                for (int level = 1; level <= 21; ++level) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v > prevLvl) ++bad;
                    prevLvl = v;
                }
            }
        }
        printf("R113 class matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
