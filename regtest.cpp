#include "monsters/MonsterRegistry.h"
#include "dm/encounters.h"
#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates
#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
#include "dm/dungeon.h"    // R124: generator smoke in the audit
#include "game/party.h"
#include "rules/combat.h"
#include "rules/saves.h"
#include "spells/spells.h"
#include "abilities/abilities.h"
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
