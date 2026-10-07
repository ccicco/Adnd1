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
#include "game/appstate.h"  // R233: the multi-class audit
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
#include "rules/klm.h"  // R171: pp.221-224 appendices K L and M
#include "rules/herbs.h"  // R172: p.220 appendix J herbs spices and medicinal vegetables
#include "rules/secondary.h"  // R173: p.12 secondary skills
#include "rules/subclasses.h"  // R179: the subclass registry
#include "rules/subclassgates.h"  // R180: the qualification and race gates
#include "rules/attacksround.h"  // R181: attacks per melee round
#include "rules/druidspells.h"  // R182: the druid spell layer
#include "rules/illusionspells.h"  // R183: the illusionist spell layer
#include "rules/palrangerspells.h"  // R184: the paladin and ranger spell layers
#include "rules/multiclass.h"  // R185: the multi-class and dual-class rules
#include "rules/bard.h"  // R186: the bard (Appendix II)
#include "rules/subclassspecials.h"  // R187: the per-subclass specials
#include "rules/xpadjust.h"  // R188: the prime requisite XP adjustment
#include "rules/weapontables.h"  // R189: the weapon weight and damage table
#include "rules/startmoney.h"  // R190: the starting money by class
#include "rules/armorratings.h"  // R191: the armor class ratings
#include "rules/wisdom.h"  // R192: Wisdom Tables I and II
#include "rules/itemsavethrow.h"  // R204: p.80 item saving throw matrix
#include "rules/spying.h"  // R205: pp.19-20 the spying tables
#include "rules/pursuit.h"  // R206: pp.67-69 pursuit and evasion
#include "rules/taxation.h"  // R207: p.90 the town taxation system
#include "rules/socialrank.h"  // R208: pp.88-89 social class and rank
#include "rules/npcpersonae.h"  // R209: pp.114-115 NPC personae facts
#include "rules/npctraits.h"  // R210: pp.115-116 NPC personae traits
#include "rules/npcbody.h"  // R211: pp.115-116 height, weight, languages
#include "rules/hirecost.h"  // R212: pp.116-118 hire spell costs, troop control
#include "rules/construct.h"  // R213: pp.106-108 construction and siege economics
#include "rules/siegefire.h"  // R214: pp.108-110 war machine fire, siege attack, defensive values
#include "rules/conduct.h"  // R215: pp.110-112 conducting the game pins
#include "rules/magres.h"  // R216: pp.114-119 magical research pins
#include "rules/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins
#include "rules/energydrain.h"  // R218: pp.119-122 use of magic items and energy draining pins
#include "rules/treasdet.h"  // R219: pp.120-123 treasure random determination tables
#include "rules/hoard.h"  // R220: p.123 the combined hoard table
#include "rules/potions.h"  // R221: pp.125-126 the potions prose pins
#include "rules/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins
#include "rules/rings.h"  // R223: p.127 the rings footnote pins
#include "rules/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins
#include "rules/miscmagic1.h"  // R225: p.128 the misc table 1 pins
#include "rules/miscmagic2.h"  // R226: p.128 the misc table 2 pins
#include "rules/miscmagic3.h"  // R237: p.129 the misc table 3 pins
#include "rules/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins
#include "rules/miscmagic5.h"  // R239: p.130 the misc table 5 pins
#include "rules/specart.h"  // R240: p.130-131 the III.E Special artifacts pins
#include "rules/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins
#include "rules/swords.h"  // R242: p.131 the III.G swords pins
#include "rules/mweapons.h"  // R243: p.131-132 the III.H misc weapons pins
#include "rules/rodsprose.h"  // R244: pp.141-142 the III.D rods prose pins
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
        int bad = 0, mu = 0, cl = 0, dr = 0, il = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            // R129: the band widens to 1-9 - the p.14
            // caster-aging spells ride as levels 7-9
            if (s.level < 1 || s.level > 9) ++bad;
            // R228: the druid registry rows ride
            // SPELL_DRUID (77 spells, levels 1-7);
            // R229: the illusionist rows ride
            // SPELL_ILLUSIONIST (61 spells)
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC &&
                s.sclass != spells::SPELL_DRUID &&
                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu;
            else if (s.sclass == spells::SPELL_DRUID) ++dr;
            else if (s.sclass == spells::SPELL_ILLUSIONIST) ++il;
            else ++cl;
            if (s.level >= 4 && s.level <= 6) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }
        if (l46 < 12) ++bad;   // the R80 roster landed
        // R228: the druid rows match the R182 roster
        // cell by cell (level, reversible, class)
        for (int i = 0; i < rules::druidSpellTotal(); ++i) {
            const spells::SpellDef& s = spells::spell(
                (spells::SpellId)(
                    spells::DR_ANIMAL_FRIENDSHIP + i));
            if (s.level != rules::druidSpell(i).level ||
                (s.reversible ? 1 : 0) !=
                    rules::druidSpell(i).reversible ||
                s.sclass != spells::SPELL_DRUID) ++bad;
        }
        // R229: the illusionist rows match the R183
        // roster cell by cell (level, class; the
        // illusionist print carries no reversible
        // markers)
        for (int i = 0; i < rules::illusionistSpellTotal(); ++i) {
            const spells::SpellDef& s = spells::spell(
                (spells::SpellId)(
                    spells::IL_AUDIBLE_GLAMER + i));
            if (s.level != rules::illusionistSpell(i).level ||
                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;
        }
        printf("R80 spells audit: %d spells (MU %d, CL %d, DR %d, IL %d), "
               "L4-6 %d, bad %d\n",
               spells::SPELL_COUNT, mu, cl, dr, il, l46, bad);
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
    // ---- R176: the printed XP tables audit -------
    // PHB pp.20-31: the four printed class XP
    // boundary rows, pinned R176 (the R162 open
    // box closed). Convention: the XP to attain
    // level N is the band lower bound - 1. The
    // 13-row walk per class, the printed adders
    // via the beyond-table probes, and the clamps.
    {
        int bad = 0;
        static const int kF[13] = {
            0, 2000, 4000, 8000, 18000, 35000,
            70000, 125000, 250000, 500000,
            750000, 1000000, 1250000
        };
        static const int kM[13] = {
            0, 2500, 5000, 10000, 22500, 40000,
            60000, 90000, 135000, 250000,
            375000, 750000, 1125000
        };
        static const int kC[13] = {
            0, 1500, 3000, 6000, 13000, 27500,
            55000, 110000, 225000, 450000,
            675000, 900000, 1125000
        };
        static const int kT[13] = {
            0, 1250, 2500, 5000, 10000, 20000,
            42500, 70000, 110000, 160000,
            220000, 440000, 660000
        };
        for (int i = 0; i < 13; ++i) {
            if (rules::xpForLevel(rules::CLASS_FIGHTER,
                                  i + 1) != kF[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_MAGIC_USER,
                                  i + 1) != kM[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_CLERIC,
                                  i + 1) != kC[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_THIEF,
                                  i + 1) != kT[i]) ++bad;
        }
        // the printed adders, probed beyond the rows
        // (fighter 250k past the 11th, MU 375k past
        // the 12th, cleric 225k past the 11th, thief
        // 220k past the 12th)
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 14)
            != 1500000) ++bad;
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 15)
            != 1750000) ++bad;
        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 14)
            != 1500000) ++bad;
        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 15)
            != 1875000) ++bad;
        if (rules::xpForLevel(rules::CLASS_CLERIC, 14)
            != 1350000) ++bad;
        if (rules::xpForLevel(rules::CLASS_CLERIC, 15)
            != 1575000) ++bad;
        if (rules::xpForLevel(rules::CLASS_THIEF, 14)
            != 880000) ++bad;
        if (rules::xpForLevel(rules::CLASS_THIEF, 15)
            != 1100000) ++bad;
        // the clamps: level 0 or below reads 0, a bad
        // class reads 0
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 0) != 0 ||
            rules::xpForLevel(rules::CLASS_FIGHTER, -5) != 0)
            ++bad;
        if (rules::xpForLevel(-1, 5) != 0 ||
            rules::xpForLevel(99, 5) != 0) ++bad;
        printf("R176 printed XP tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R178c: the DEX and CON tables audit ----
    // PHB pp.11-12: the printed DEX reaction and
    // defensive ladders and the CON hit-point,
    // system-shock and resurrection-survival
    // columns, pinned R178c (the R177 founding
    // read divergences 1 and 2 closed). The
    // 16-score walks and the clamps.
    {
        int bad = 0;
        static const int kDexRe[16] = {
            -3, -2, -1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 2, 3
        };
        static const int kDexDef[16] = {
            4, 3, 2, 1, 0, 0, 0, 0, 0, 0,
            0, 0, -1, -2, -3, -4
        };
        static const int kConHp[16] = {
            -2, -1, -1, -1, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 2, 2, 2
        };
        static const int kShock[16] = {
            35, 40, 45, 50, 55, 60, 65, 70, 75,
            80, 85, 88, 91, 95, 97, 99
        };
        static const int kRes[16] = {
            40, 45, 50, 55, 60, 65, 70, 75, 80,
            85, 90, 92, 94, 96, 98, 100
        };
        for (int i = 0; i < 16; ++i) {
            uint8_t s = (uint8_t)(i + 3);
            if (rules::dexReactionAdj(s) != kDexRe[i]) ++bad;
            if (rules::dexDefensiveAdj(s) != kDexDef[i]) ++bad;
            if (rules::conHPAdj(s) != kConHp[i]) ++bad;
            if (rules::conSystemShock(s) != kShock[i]) ++bad;
            if (rules::conResSurvival(s) != kRes[i]) ++bad;
        }
        // the clamps: low scores read the first row,
        // high scores the last
        if (rules::dexReactionAdj(0) != -3 ||
            rules::dexReactionAdj(99) != 3) ++bad;
        if (rules::dexDefensiveAdj(0) != 4 ||
            rules::dexDefensiveAdj(99) != -4) ++bad;
        if (rules::conSystemShock(0) != 35 ||
            rules::conSystemShock(99) != 99) ++bad;
        if (rules::conResSurvival(0) != 40 ||
            rules::conResSurvival(99) != 100) ++bad;
        if (rules::conHPAdj(2) != -2 ||
            rules::conHPAdj(18) != 2) ++bad;
        printf("R178c DEX and CON tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R179: the subclass registry audit -------
    // The six pinned subclass defs from the printed
    // PHB class tables: the XP attain rows cell by
    // cell, the title ladders, the caps, the hit
    // dice, the two-dice first levels (ranger,
    // monk), the adders, the base-class map, and
    // the clamps (the R176 attain convention).
    {
        int bad = 0;
        if (rules::subclassCount() != 6) ++bad;
        // the base-class map: paladin fighter,
        // ranger fighter, druid cleric,
        // illusionist MU, assassin thief, monk none
        static const int kBase[6] = { 0, 0, 2, 1, 3, -1 };
        static const int kCap[6]  = { 9, 10, 14, 10, 10, 17 };
        static const int kHpB[6]  = { 3, 2, 2, 1, 2, 0 };
        static const int kDie[6]  = { 10, 8, 8, 4, 6, 4 };
        static const int kTwo[6]  = { 0, 1, 0, 0, 0, 1 };
        static const int kRows[6] = { 11, 12, 14, 12, 15, 17 };
        static const int kAdder[6] = { 350000, 325000, 0,
                                     220000, 0, 0 };
        static const int kXpPal[11] = {
            0, 2750, 5500, 12000, 24000,
            45000, 95000, 175000, 350000, 700000, 1050000
        };
        static const int kXpRng[12] = {
            0, 2250, 4500, 10000, 20000,
            40000, 90000, 150000, 225000, 325000,
            650000, 975000
        };
        static const int kXpDru[14] = {
            0, 2000, 4000, 7500, 12500,
            20000, 35000, 60000, 90000, 125000,
            200000, 300000, 750000, 1500000
        };
        static const int kXpIll[12] = {
            0, 2250, 4500, 9000, 18000,
            35000, 60000, 95000, 145000, 220000,
            440000, 660000
        };
        static const int kXpAsn[15] = {
            0, 1500, 3000, 6000, 12000,
            25000, 50000, 100000, 200000, 300000,
            425000, 575000, 750000, 1000000, 1500000
        };
        static const int kXpMnk[17] = {
            0, 2250, 4750, 10000, 22500,
            47500, 98000, 200000, 350000, 500000,
            700000, 950000, 1250000, 1750000,
            2250000, 2750000, 3250000
        };
        for (int i = 0; i < 6; ++i) {
            const rules::SubclassDef& d =
                rules::subclassDef(i);
            if (d.base != kBase[i]) ++bad;
            if (d.levelCap != kCap[i]) ++bad;
            if (d.hpBeyondCap != kHpB[i]) ++bad;
            if (d.hitDie != kDie[i]) ++bad;
            if (d.twoDiceFirstLevel != kTwo[i]) ++bad;
            if (d.xpRowCount != kRows[i]) ++bad;
            if (d.xpAdder != kAdder[i]) ++bad;
            if (d.titleCount != d.xpRowCount) ++bad;
        }
        for (int l = 1; l <= 11; ++l)
            if (rules::subclassXpFor(0, l) != kXpPal[l-1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpFor(1, l) != kXpRng[l-1]) ++bad;
        for (int l = 1; l <= 14; ++l)
            if (rules::subclassXpFor(2, l) != kXpDru[l-1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpFor(3, l) != kXpIll[l-1]) ++bad;
        for (int l = 1; l <= 15; ++l)
            if (rules::subclassXpFor(4, l) != kXpAsn[l-1]) ++bad;
        for (int l = 1; l <= 17; ++l)
            if (rules::subclassXpFor(5, l) != kXpMnk[l-1]) ++bad;
        // the adder probes: paladin, ranger,
        // illusionist; the ceiling rows repeat for
        // the adder-0 defs
        if (rules::subclassXpFor(0, 12) != 1400000 ||
            rules::subclassXpFor(0, 13) != 1750000) ++bad;
        if (rules::subclassXpFor(1, 13) != 1300000 ||
            rules::subclassXpFor(1, 14) != 1625000) ++bad;
        if (rules::subclassXpFor(3, 13) != 880000 ||
            rules::subclassXpFor(3, 14) != 1100000) ++bad;
        if (rules::subclassXpFor(2, 15) != 1500000 ||
            rules::subclassXpFor(4, 16) != 1500000 ||
            rules::subclassXpFor(5, 18) != 3250000) ++bad;
        // title spot rows and clamps
        if (std::string(rules::subclassTitle(0, 9))
            != "Paladin") ++bad;
        if (std::string(rules::subclassTitle(1, 8))
            != "Ranger") ++bad;
        if (std::string(rules::subclassTitle(2, 14))
            != "The Great Druid") ++bad;
        if (std::string(rules::subclassTitle(3, 10))
            != "Illusionist") ++bad;
        if (std::string(rules::subclassTitle(4, 15))
            != "Grandfather of Assassins") ++bad;
        if (std::string(rules::subclassTitle(5, 17))
            != "Grand Master of Flowers") ++bad;
        if (std::string(rules::subclassTitle(5, 1))
            != "Novice") ++bad;
        if (std::string(rules::subclassTitle(0, 0))
            != "Gallant") ++bad;
        if (std::string(rules::subclassTitle(0, 99))
            != "Paladin (11th level)") ++bad;
        if (rules::subclassXpFor(0, 0) != 0 ||
            rules::subclassXpFor(5, -3) != 0) ++bad;
        printf("R179 subclass registry audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R180: the qualification and race gates audit ----
    // The class-section ability minimums, the Table I
    // alignment letters, the printed XP bonus rules,
    // Character Race Tables I and II cell by cell, the
    // footnote-8 gnome illusionist conditional, and the
    // meets-min / bonus-earned probes.
    {
        int bad = 0;
        // the ability minimums, in Ability enum order
        const int kGMin[6][6] = {
            { 12,  9, 13,  0,  9, 17 },
            { 13, 13, 14,  0, 14,  0 },
            {  0,  0, 12,  0,  0, 15 },
            {  0, 15,  0, 16,  0,  0 },
            { 12, 11,  0, 12,  0,  0 },
            { 15,  0, 15, 15, 11,  0 }
        };
        // Table I, CharRace column order
        const int kGAllowed[6][7] = {
            { 1, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 1, 0, 0 },
            { 1, 0, 0, 1, 0, 0, 0 },
            { 1, 1, 1, 1, 1, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0 }
        };
        // Table II: 0 forbidden, -1 unlimited, -n NPC-only
        const int kGCap[6][7] = {
            { -1,  0,  0,  0,  0,  0,  0 },
            { -1,  0,  0,  0,  8,  0,  0 },
            { -1,  0,  0,  0, -1, -6,  0 },
            { -1,  0,  0,  7,  0,  0,  0 },
            { -1,  9, 10,  8, 11,  0, -1 },
            { -1,  0,  0,  0,  0,  0,  0 }
        };
        // the alignment requirements and bonus rules
        const int kGAlign[6] = { 1, 2, 3, 0, 4, 5 };
        const int kGBonus[6] = { 1, 2, 3, 0, 0, 0 };
        for (int i = 0; i < 6; ++i) {
            for (int ab = 0; ab < 6; ++ab)
                if (rules::subclassAbilityMin(
                        i, (rules::Ability)ab)
                    != kGMin[i][ab]) ++bad;
            for (int r = 0; r < 7; ++r) {
                if (rules::subclassRaceAllowed(
                        i, (rules::CharRace)r)
                    != kGAllowed[i][r]) ++bad;
                if (rules::subclassRaceCap(
                        i, (rules::CharRace)r)
                    != kGCap[i][r]) ++bad;
            }
            if (rules::subclassAlignmentReq(i)
                != kGAlign[i]) ++bad;
            if (rules::subclassXpBonusRule(i)
                != kGBonus[i]) ++bad;
        }
        // the NPC-only convention: the halfling druid (6)
        if (!rules::subclassCapIsNpcOnly(
                2, rules::RACE_HALFLING)) ++bad;
        if (rules::subclassCapIsNpcOnly(
                1, rules::RACE_HALF_ELF)) ++bad;
        if (rules::subclassCapIsNpcOnly(
                0, rules::RACE_HUMAN)) ++bad;
        // the footnote-8 conditional (gnome illusionist)
        if (rules::illusionistGnomeCap(16, 18) != 5) ++bad;
        if (rules::illusionistGnomeCap(18, 16) != 5) ++bad;
        if (rules::illusionistGnomeCap(17, 16) != 5) ++bad;
        if (rules::illusionistGnomeCap(17, 17) != 6) ++bad;
        if (rules::illusionistGnomeCap(18, 18) != 6) ++bad;
        // meets-min probes: at the minimums passes,
        // one point short fails, one over passes
        rules::AbilityScores s;
        s.set(rules::ABILITY_STR, 12);
        s.set(rules::ABILITY_INT, 9);
        s.set(rules::ABILITY_WIS, 13);
        s.set(rules::ABILITY_DEX, 3);
        s.set(rules::ABILITY_CON, 9);
        s.set(rules::ABILITY_CHA, 17);
        if (!rules::subclassMeetsAbilityMin(0, s)) ++bad;
        s.set(rules::ABILITY_CHA, 16);
        if (rules::subclassMeetsAbilityMin(0, s)) ++bad;
        s.set(rules::ABILITY_STR, 15);
        s.set(rules::ABILITY_INT, 15);
        s.set(rules::ABILITY_WIS, 15);
        s.set(rules::ABILITY_DEX, 15);
        s.set(rules::ABILITY_CON, 11);
        s.set(rules::ABILITY_CHA, 3);
        if (!rules::subclassMeetsAbilityMin(5, s)) ++bad;
        s.set(rules::ABILITY_CON, 10);
        if (rules::subclassMeetsAbilityMin(5, s)) ++bad;
        s.set(rules::ABILITY_CON, 12);
        // bonus-earned probes: all over 15 earns the
        // printed bonus; at 15 nothing earns
        rules::AbilityScores b;
        b.set(rules::ABILITY_STR, 16);
        b.set(rules::ABILITY_INT, 16);
        b.set(rules::ABILITY_WIS, 16);
        b.set(rules::ABILITY_DEX, 10);
        b.set(rules::ABILITY_CON, 10);
        b.set(rules::ABILITY_CHA, 16);
        if (!rules::subclassXpBonusEarned(0, b)) ++bad;
        if (!rules::subclassXpBonusEarned(1, b)) ++bad;
        if (!rules::subclassXpBonusEarned(2, b)) ++bad;
        if (rules::subclassXpBonusEarned(3, b)) ++bad;
        if (rules::subclassXpBonusEarned(4, b)) ++bad;
        if (rules::subclassXpBonusEarned(5, b)) ++bad;
        rules::AbilityScores n;
        n.set(rules::ABILITY_STR, 15);
        n.set(rules::ABILITY_INT, 15);
        n.set(rules::ABILITY_WIS, 15);
        n.set(rules::ABILITY_DEX, 10);
        n.set(rules::ABILITY_CON, 10);
        n.set(rules::ABILITY_CHA, 15);
        if (rules::subclassXpBonusEarned(0, n)) ++bad;
        if (rules::subclassXpBonusEarned(1, n)) ++bad;
        if (rules::subclassXpBonusEarned(2, n)) ++bad;
        if (rules::subclassXpBonusEarned(3, n)) ++bad;
        if (rules::subclassXpBonusEarned(4, n)) ++bad;
        if (rules::subclassXpBonusEarned(5, n)) ++bad;
        printf("R180 qualification and race gates audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R230: the subclass creation seam audit ----
    // The runtime base classes, the con classes, the
    // starting-age bands, the two-dice flags, the hit
    // dice, the player-eligibility gate (Table I with
    // Table II agreement), and the effective level cap
    // (Table II with the footnote-8 gnome conditional).
    {
        int bad = 0;
        static const int kBase[6] = {
            0, 0, 2, 1, 3, 0
        };
        static const int kCon[6] = {
            0, 0, 2, 1, 3, 3
        };
        static const int kAge[6] = {
            15, 15, 18, 24, 18, 15
        };
        static const int kTwo[6] = {
            0, 1, 0, 0, 0, 1
        };
        static const int kDie[6] = {
            10, 8, 8, 4, 6, 4
        };
        // Table I, flat 42 (the R180 walk)
        static const int kAllowed[42] = {
            1, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 1, 0, 0, 0,
            1, 1, 1, 1, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0
        };
        // the runtime base classes (the monk rides
        // fighter - the JUDGMENT)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassRuntimeBase(i)
                != kBase[i]) ++bad;
        // the con classes (paladin/ranger the fighter
        // group; the monk is not - the registry pin)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassConClass(i)
                != kCon[i]) ++bad;
        // the starting-age bands
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassStartAgeBase(i)
                != kAge[i]) ++bad;
        // the two-dice flags (ranger, monk)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassTwoDiceFirstLevel(i)
                != kTwo[i]) ++bad;
        // the hit dice (d10 d8 d8 d4 d6 d4)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassHitDie(i)
                != kDie[i]) ++bad;
        // the player-eligibility gate agrees with the
        // R180 Table I walk, cell by cell
        for (int i = 0; i <= 5; ++i)
            for (int r = 0; r <= 6; ++r)
                if (rules::subclassPlayerAllowed(
                        i, (rules::CharRace)r)
                    != kAllowed[i * 7 + r]) ++bad;
        // the effective caps: the Table II matrix with
        // the footnote-8 gnome illusionist conditional
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 16, 18) != 5) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 17, 16) != 5) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 17, 17) != 6) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)0, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)1, 18, 18) != 0) ++bad;
        if (rules::subclassLevelCapFor(
                0, (rules::CharRace)0, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                0, (rules::CharRace)1, 18, 18) != 0) ++bad;
        if (rules::subclassLevelCapFor(
                1, (rules::CharRace)4, 18, 18) != 8) ++bad;
        if (rules::subclassLevelCapFor(
                2, (rules::CharRace)5, 18, 18) != -6) ++bad;
        if (rules::subclassLevelCapFor(
                4, (rules::CharRace)2, 18, 18) != 10) ++bad;
        if (rules::subclassLevelCapFor(
                4, (rules::CharRace)6, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                5, (rules::CharRace)0, 18, 18) != -1) ++bad;
        // the clamps
        if (rules::subclassPlayerAllowed(
                99, (rules::CharRace)99) != 0) ++bad;
        if (rules::subclassPlayerAllowed(
                -1, (rules::CharRace)-1) != 1) ++bad;
        if (rules::subclassHitDie(-1) != 10) ++bad;
        if (rules::subclassHitDie(99) != 4) ++bad;
        if (rules::subclassRuntimeBase(-3) != 0) ++bad;
        if (rules::subclassRuntimeBase(99) != 0) ++bad;
        printf("R230 subclass creation seam audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R231: the subclass leveling seam audit ----
    // The printed XP attain rows cell by cell (the
    // R176 convention), the adders past the rows,
    // the fixed-hp levels, the fixed hp past them,
    // and the effective leveling cap.
    {
        int bad = 0;
        static const int kPal[11] = {
            0, 2750, 5500, 12000, 24000,
            45000, 95000, 175000, 350000, 700000,
            1050000
        };
        static const int kRng[12] = {
            0, 2250, 4500, 10000, 20000,
            40000, 90000, 150000, 225000, 325000,
            650000, 975000
        };
        static const int kDru[14] = {
            0, 2000, 4000, 7500, 12500,
            20000, 35000, 60000, 90000, 125000,
            200000, 300000, 750000, 1500000
        };
        static const int kIll[12] = {
            0, 2250, 4500, 9000, 18000,
            35000, 60000, 95000, 145000, 220000,
            440000, 660000
        };
        static const int kAsn[15] = {
            0, 1500, 3000, 6000, 12000,
            25000, 50000, 100000, 200000, 300000,
            425000, 575000, 750000, 1000000,
            1500000
        };
        static const int kMnk[17] = {
            0, 2250, 4750, 10000, 22500,
            47500, 98000, 200000, 350000, 500000,
            700000, 950000, 1250000, 1750000,
            2250000, 2750000, 3250000
        };
        for (int l = 1; l <= 11; ++l)
            if (rules::subclassXpToAttain(0, l)
                != kPal[l - 1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpToAttain(1, l)
                != kRng[l - 1]) ++bad;
        for (int l = 1; l <= 14; ++l)
            if (rules::subclassXpToAttain(2, l)
                != kDru[l - 1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpToAttain(3, l)
                != kIll[l - 1]) ++bad;
        for (int l = 1; l <= 15; ++l)
            if (rules::subclassXpToAttain(4, l)
                != kAsn[l - 1]) ++bad;
        for (int l = 1; l <= 17; ++l)
            if (rules::subclassXpToAttain(5, l)
                != kMnk[l - 1]) ++bad;
        // the adders past the printed rows: paladin
        // 350k, ranger 325k, illusionist 220k; the
        // druid, assassin and monk print none - the
        // top row repeats (the ceiling)
        if (rules::subclassXpToAttain(0, 12)
            != 1400000) ++bad;
        if (rules::subclassXpToAttain(0, 13)
            != 1750000) ++bad;
        if (rules::subclassXpToAttain(1, 13)
            != 1300000) ++bad;
        if (rules::subclassXpToAttain(3, 13)
            != 880000) ++bad;
        if (rules::subclassXpToAttain(2, 15)
            != 1500000) ++bad;
        if (rules::subclassXpToAttain(4, 16)
            != 1500000) ++bad;
        if (rules::subclassXpToAttain(5, 18)
            != 3250000) ++bad;
        // level 1 attains at 0
        if (rules::subclassXpToAttain(0, 1) != 0) ++bad;
        // the fixed-hp levels and the fixed hp past
        // them (the R179 pins)
        static const int kFix[6] = {
            9, 10, 9, 10, 10, 17
        };
        static const int kHpB[6] = {
            3, 2, 2, 1, 2, 0
        };
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassFixedHpLevel(i)
                != kFix[i]) ++bad;
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassHpBeyondFixed(i)
                != kHpB[i]) ++bad;
        // the leveling stops (the R179 levelCap pins;
        // the druid 14 - the hierarchy ceiling, where
        // the fixed hp starts at the 9th)
        static const int kStop[6] = {
            9, 10, 14, 10, 10, 17
        };
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassLevelStop(i)
                != kStop[i]) ++bad;
        // the effective leveling cap: the leveling
        // level minus a positive Table II race cap
        // (the footnote-8 gnome conditional included)
        if (rules::subclassLevelCapTotal(
                0, (rules::CharRace)0, 18, 18) != 9) ++bad;
        if (rules::subclassLevelCapTotal(
                2, (rules::CharRace)0, 18, 18) != 14) ++bad;
        if (rules::subclassLevelCapTotal(
                1, (rules::CharRace)4, 18, 18) != 8) ++bad;
        if (rules::subclassLevelCapTotal(
                3, (rules::CharRace)3, 17, 17) != 6) ++bad;
        if (rules::subclassLevelCapTotal(
                3, (rules::CharRace)3, 16, 18) != 5) ++bad;
        if (rules::subclassLevelCapTotal(
                4, (rules::CharRace)1, 18, 18) != 9) ++bad;
        if (rules::subclassLevelCapTotal(
                5, (rules::CharRace)0, 18, 18) != 17) ++bad;
        // the clamps
        if (rules::subclassXpToAttain(-1, 2)
            != 2750) ++bad;
        if (rules::subclassXpToAttain(99, 2)
            != 2250) ++bad;
        if (rules::subclassFixedHpLevel(-3) != 9) ++bad;
        if (rules::subclassFixedHpLevel(99) != 17) ++bad;
        if (rules::subclassLevelStop(-3) != 9) ++bad;
        if (rules::subclassLevelStop(99) != 17) ++bad;
        printf("R231 subclass leveling seam audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R232: the subclass specials hooks audit ----
    // The specials the engine reads: the toActor subclass
    // propagation and the monk attack rate, the monk
    // open-hand ladder cells and attack slashes, the
    // backstab ladder and hit bonus, the ranger
    // giant-class roster and bonus, and the lay-hands
    // career-day field contract (an engine audit - the
    // R174 convention; the C++ battery is the gate).
    {
        int bad = 0;
        // the toActor propagation + the monk attack rate
        {
            Character c;
            c.subclass = rules::SUB_MONK;
            c.level = 12;
            ai::Actor a = c.toActor();
            if (a.subclass != rules::SUB_MONK) ++bad;
            if (a.attacksPerRound() != 2) ++bad;   // 12th: 5/2
            c.level = 1;
            a = c.toActor();
            if (a.attacksPerRound() != 1) ++bad;   // 1st: 1/1
            c.subclass = -1;
            a = c.toActor();
            if (a.subclass != -1) ++bad;
            if (a.attacksPerRound() != 1) ++bad;   // fighter L1
        }
        // the monk open-hand ladder cells (Monks Table II)
        if (rules::monkLadderRow(1).dmgLo != 1 ||
            rules::monkLadderRow(1).dmgHi != 3) ++bad;
        if (rules::monkLadderRow(13).dmgLo != 5 ||
            rules::monkLadderRow(13).dmgHi != 17) ++bad;
        if (rules::monkLadderRow(17).dmgLo != 8 ||
            rules::monkLadderRow(17).dmgHi != 32) ++bad;
        // the monk attack slashes (the printed cycle)
        if (rules::monkOpenHandAttacks(4).attacks != 5 ||
            rules::monkOpenHandAttacks(4).rounds != 4) ++bad;
        if (rules::monkOpenHandAttacks(12).attacks != 5 ||
            rules::monkOpenHandAttacks(12).rounds != 2) ++bad;
        // the backstab ladder (double 1-4 ... quintuple
        // 13-16, clamped at quintuple)
        static const int kMult[16] = {
            2, 2, 2, 2, 3, 3, 3, 3,
            4, 4, 4, 4, 5, 5, 5, 5
        };
        for (int l = 1; l <= 16; ++l)
            if (rules::backstabMultiplier(l)
                != kMult[l - 1]) ++bad;
        if (rules::backstabMultiplier(17) != 5) ++bad;
        if (rules::backstabHitBonusDie() != 4) ++bad;
        if (rules::backstabHitBonusPercent() != 20) ++bad;
        // the assassin reads full level backstabbing
        if (rules::assassinBackstabLevel(7) != 7) ++bad;
        if (rules::assassinThiefSkillLevel(7) != 5) ++bad;
        // the ranger giant-class roster (the R184 data
        // the hook reads)
        if (rules::rangerGiantClassCount() != 11) ++bad;
        if (!rules::rangerIsGiantClass("ogre mage")) ++bad;
        if (!rules::rangerIsGiantClass("ogre")) ++bad;
        if (rules::rangerIsGiantClass("purple worm")) ++bad;
        if (rules::rangerIsGiantClass("ogre ish")) ++bad;
        if (rules::rangerGiantClassBonus(7) != 7) ++bad;
        if (rules::rangerGiantClassBonus(0) != 0) ++bad;
        // the lay-hands field contract: -1 = never used
        {
            Character c;
            if (c.layHandsDay != -1) ++bad;
            c.layHandsDay = 100;
            if (c.layHandsDay == -1) ++bad;
        }
        printf("R232 subclass specials hooks audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R233a: the multi-class seam audit ----
    // The combo bit helpers (the pure-expression
    // seam), the R185 quotient/stalled machinery,
    // and the combo table joins the engine reads
    // (an evaluable block - verified by audit_eval).
    {
        int bad = 0;
        // the bit helpers: count, ordered bits, the
        // base-class and subclass maps
        if (rules::multiClassCount(0) != 0) ++bad;
        if (rules::multiClassCount(3) != 2) ++bad;
        if (rules::multiClassCount(11) != 3) ++bad;
        if (rules::multiClassCount(127) != 7) ++bad;
        if (rules::multiClassCount(6) != 2) ++bad;
        if (rules::multiClassCount(48) != 2) ++bad;
        if (rules::multiClassBitAt(11, 0) != 1) ++bad;
        if (rules::multiClassBitAt(11, 1) != 2) ++bad;
        if (rules::multiClassBitAt(11, 2) != 8) ++bad;
        if (rules::multiClassBitAt(5, 1) != 4) ++bad;
        if (rules::multiClassBitAt(36, 1) != 32) ++bad;
        if (rules::multiClassBitAt(6, 0) != 2) ++bad;
        if (rules::multiClassBitAt(6, 1) != 4) ++bad;
        if (rules::multiClassBitAt(48, 0) != 16) ++bad;
        if (rules::multiClassBitAt(48, 1) != 32) ++bad;
        if (rules::multiClassBitAt(36, 0) != 4) ++bad;
        if (rules::multiClassBitAt(24, 0) != 8) ++bad;
        if (rules::multiClassBitAt(24, 1) != 16) ++bad;
        if (rules::multiClassBitAt(68, 0) != 4) ++bad;
        if (rules::multiClassBitAt(68, 1) != 64) ++bad;
        if (rules::multiClassBaseOfBit(1) != 0) ++bad;
        if (rules::multiClassBaseOfBit(16) != 1) ++bad;
        if (rules::multiClassBaseOfBit(32) != 0) ++bad;
        if (rules::multiClassBaseOfBit(64) != 3) ++bad;
        if (rules::multiClassSubOfBit(1) != -1) ++bad;
        if (rules::multiClassSubOfBit(16) != 3) ++bad;
        if (rules::multiClassSubOfBit(32) != 1) ++bad;
        if (rules::multiClassSubOfBit(64) != 4) ++bad;
        // the quotient and stalled rules (R185)
        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(1, 2) != 1) ++bad;
        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;
        if (rules::multiclassHitDieStalled(8, 9)) ++bad;
        // the combo table joins (the R185 rows the
        // engine reads)
        if (rules::multiClassComboCount(4) != 8) ++bad;
        if (rules::multiClassCombo(4, 0) != 5) ++bad;
        if (rules::multiClassCombo(6, 2) != 68) ++bad;
        printf("R233a multi-class seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R233: the multi-class engine audit ----
    // The toActor primary convention, the creation
    // gates and the member factory (an engine audit -
    // the R174/R232 convention; the C++ battery is
    // the gate).
    {
        int bad = 0;
        // the Character + toActor primary convention
        {
            Character c;
            if (c.multiMask != 0) ++bad;
            c.multiMask = 11;   // F/MU/T
            ai::Actor a = c.toActor();
            if (a.classIndex != 0) ++bad;
            if (a.subclass != -1) ++bad;
            c.multiMask = 24;   // I/T: thief primary
            a = c.toActor();
            if (a.classIndex != 3) ++bad;
            if (a.subclass != -1) ++bad;
            c.multiMask = 68;   // C/A: cleric primary
            a = c.toActor();
            if (a.classIndex != 2) ++bad;
            if (a.subclass != -1) ++bad;
        }
        // the creation gates + the member factory
        {
            CreationState cr;
            cr.racePick = 4;   // half-elf
            cr.rolled.str = 12; cr.rolled.int_ = 12;
            cr.rolled.wis = 12; cr.rolled.dex = 12;
            cr.rolled.con = 12; cr.rolled.cha = 12;
            // the half-elf multi-class cleric WIS 13
            if (cr.multiEligible(5)) ++bad;   // WIS 12
            cr.rolled.wis = 13;
            if (!cr.multiEligible(5)) ++bad;   // C/F
            if (!cr.multiEligible(3)) ++bad;   // F/MU
            if (cr.multiEligible(24)) ++bad;   // I/T: no elf bit here
            // the factory: F/MU - the fighter primary,
            // the hp quotient bounds (d10 + d4 at
            // CON 12, quotients 1..7), the MU kit
            Character mc = cr.makeMultiMember(3);
            if (mc.multiMask != 3) ++bad;
            if (mc.classIndex != 0) ++bad;
            if (mc.subclass != -1) ++bad;
            if (mc.hp < 1 || mc.hp > 7) ++bad;
            if (mc.armor.id != items::ARMOR_NONE_EQUIPPED)
                ++bad;
            if (mc.shield) ++bad;
            // the dwarf F/T - the thief kit
            cr.racePick = 1;
            cr.rolled.str = 12; cr.rolled.dex = 12;
            Character dt = cr.makeMultiMember(9);
            if (dt.multiMask != 9) ++bad;
            if (dt.armor.id != items::ARMOR_LEATHER) ++bad;
            if (dt.shield) ++bad;
            // the half-orc C/A - the assassin primary
            cr.racePick = 6;
            cr.rolled.wis = 13;
            Character ca = cr.makeMultiMember(68);
            if (ca.subclass != -1) ++bad;
            if (ca.classIndex != 2) ++bad;
        }
        printf("R233 multi-class engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R234a: the dual-class seam audit ----
    // The R185 gates and the R234 pure-expression
    // seam (an evaluable block - verified by
    // audit_eval).
    {
        int bad = 0;
        // the race gate: humans only
        if (!rules::dualClassRaceAllowed(0)) ++bad;
        if (rules::dualClassRaceAllowed(1)) ++bad;
        if (rules::dualClassRaceAllowed(6)) ++bad;
        // the prime gates: 15+ old, 17+ new
        if (rules::dualClassPrimeGate(14, 17)) ++bad;
        if (rules::dualClassPrimeGate(15, 16)) ++bad;
        if (!rules::dualClassPrimeGate(15, 17)) ++bad;
        if (!rules::dualClassPrimeGate(16, 18)) ++bad;
        // the exceeded boundary: the new die begins
        // when the new level EXCEEDS the old
        if (rules::dualClassNewDieDue(6, 6) != 0) ++bad;
        if (rules::dualClassNewDieDue(7, 6) != 1) ++bad;
        if (rules::dualClassNewDieDue(1, 1) != 0) ++bad;
        // the XP negation: the resort stance negates
        // until exceeded, then mixing is free
        if (rules::dualClassXpNegated(1, 1, 6, 1) != 1) ++bad;
        if (rules::dualClassXpNegated(1, 6, 6, 1) != 1) ++bad;
        if (rules::dualClassXpNegated(1, 7, 6, 1) != 0) ++bad;
        if (rules::dualClassXpNegated(1, 1, 6, 0) != 0) ++bad;
        if (rules::dualClassXpNegated(0, 1, 6, 1) != 0) ++bad;
        printf("R234a dual-class seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R234: the dual-class engine audit ----
    // The switch gates, the retained hit dice, the
    // 1st-level restart, the XP negation and the
    // exceeded-level die (an engine audit - the C++
    // battery is the gate).
    {
        int bad = 0;
        {
            Character c;
            c.race = 0;   // human
            c.abilities.str = 15;
            c.abilities.int_ = 17;
            c.classIndex = 0;   // the printed example: fighter
            c.level = 6;
            c.hp = c.maxHp = 40;
            if (!c.canSwitchProfession(1)) ++bad;
            // the refusals: same class, wrong race,
            // low old prime, low new prime
            if (c.canSwitchProfession(0)) ++bad;
            c.race = 1;
            if (c.canSwitchProfession(1)) ++bad;
            c.race = 0;
            c.abilities.str = 14;
            if (c.canSwitchProfession(1)) ++bad;
            c.abilities.str = 15;
            c.abilities.int_ = 16;
            if (c.canSwitchProfession(1)) ++bad;
            c.abilities.int_ = 17;
            // the switch: hit dice kept, 1st-level
            // restart, the MU kit
            rules::Rng r{1};
            rules::Dice d(r);
            if (!c.switchProfession(1, d)) ++bad;
            if (c.dualOldClass != 0) ++bad;
            if (c.dualOldLevel != 6) ++bad;
            if (c.classIndex != 1) ++bad;
            if (c.level != 1) ++bad;
            if (c.xp != 0) ++bad;
            if (c.hp != 40 || c.maxHp != 40) ++bad;
            if (c.armor.id != items::ARMOR_NONE_EQUIPPED)
                ++bad;
            if (c.shield) ++bad;
            // one switch only
            if (c.canSwitchProfession(2)) ++bad;
        }
        // the XP negation and the exceeded die, on a
        // live party train loop
        {
            Party p;
            Character c;
            c.name = "Swit";
            c.race = 0;
            c.abilities.str = 15;
            c.abilities.int_ = 17;
            c.classIndex = 0;
            c.level = 2;
            c.hp = c.maxHp = 12;
            rules::Rng r{7};
            rules::Dice d(r);
            if (!c.switchProfession(1, d)) ++bad;
            p.members.push_back(c);
            MessageLog log;
            // the resort stance negates the award
            p.members[0].oldClassUse = true;
            p.gainXp(1000, d, log);
            if (p.members[0].xp != 0) ++bad;
            // strict: the award flows and queues
            p.members[0].oldClassUse = false;
            p.gainXp(1000, d, log);
            if (p.members[0].xp <= 0) ++bad;
            p.members[0].xp = 100000;
            // no die at or below the old level
            int hpAtOld = p.members[0].maxHp;
            p.gainXp(0, d, log);
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 2) ++bad;
            if (p.members[0].maxHp != hpAtOld) ++bad;
            // the new-class die once exceeded
            p.gainXp(0, d, log);
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 3) ++bad;
            if (p.members[0].maxHp <= hpAtOld) ++bad;
        }
        printf("R234 dual-class engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R235a: the bard career seam audit ----
    // The career windows, the Table I ladders and
    // the gates (an evaluable block - verified by
    // audit_eval).
    {
        int bad = 0;
        // the career gate: fighter 5th-7th, then
        // thief 5th-9th
        if (!rules::bardCareerGate(5, 5)) ++bad;
        if (!rules::bardCareerGate(7, 9)) ++bad;
        if (rules::bardCareerGate(4, 5)) ++bad;
        if (rules::bardCareerGate(8, 5)) ++bad;
        if (rules::bardCareerGate(5, 4)) ++bad;
        if (rules::bardCareerGate(5, 10)) ++bad;
        // the Table I d6 column: 0 at 1st, 1-10 at
        // 2nd-11th, then 10+1 through 10+12
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(2) != 1) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        if (rules::bardHitDice(0) != 0) ++bad;
        if (rules::bardHitDice(24) != 22) ++bad;
        // the Table I XP ladder (bard XP only)
        if (rules::bardXpForLevel(1) != 0) ++bad;
        if (rules::bardXpForLevel(2) != 2001) ++bad;
        if (rules::bardXpForLevel(11) != 150001) ++bad;
        if (rules::bardXpForLevel(12) != 200001) ++bad;
        if (rules::bardXpForLevel(13) != 400001) ++bad;
        if (rules::bardXpForLevel(20) != 1800001) ++bad;
        if (rules::bardXpForLevel(23) != 3000001) ++bad;
        // the Table I druid slots
        if (rules::bardDruidSlots(1, 1) != 1) ++bad;
        if (rules::bardDruidSlots(1, 2) != 0) ++bad;
        if (rules::bardDruidSlots(4, 2) != 1) ++bad;
        if (rules::bardDruidSlots(14, 5) != 2) ++bad;
        if (rules::bardDruidSlots(15, 1) != 3) ++bad;
        if (rules::bardDruidSlots(16, 1) != 4) ++bad;
        if (rules::bardDruidSlots(19, 1) != 5) ++bad;
        if (rules::bardDruidSlots(23, 5) != 5) ++bad;
        // the druid ability cap: 12th until the 23rd
        if (rules::bardDruidCastLevel(1) != 1) ++bad;
        if (rules::bardDruidCastLevel(12) != 12) ++bad;
        if (rules::bardDruidCastLevel(13) != 12) ++bad;
        if (rules::bardDruidCastLevel(22) != 12) ++bad;
        if (rules::bardDruidCastLevel(23) != 13) ++bad;
        // the henchmen ladder
        if (rules::bardHenchmen(4) != 0) ++bad;
        if (rules::bardHenchmen(5) != 1) ++bad;
        if (rules::bardHenchmen(8) != 2) ++bad;
        if (rules::bardHenchmen(23) != 999) ++bad;
        // the ability and race gates, Table III
        if (!rules::bardAbilityGate(15, 15, 15, 15,
                                12, 10)) ++bad;
        if (rules::bardAbilityGate(14, 15, 15, 15,
                                12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                                11, 10)) ++bad;
        if (!rules::bardRaceAllowed(0)) ++bad;
        if (!rules::bardRaceAllowed(4)) ++bad;
        if (rules::bardRaceAllowed(1)) ++bad;
        if (rules::bardShieldAllowed()) ++bad;
        if (!rules::bardOilAllowed()) ++bad;
        printf("R235a bard career seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R235: the bard engine audit ----
    // The career gates, the retained hit dice,
    // the 1st-level restart, the Table I queue and
    // the promotion die (an engine audit - the C++
    // battery is the gate).
    {
        int bad = 0;
        {
            Character c;
            c.race = 0;   // human
            c.abilities.str = 15;
            c.abilities.wis = 15;
            c.abilities.dex = 15;
            c.abilities.cha = 15;
            c.abilities.int_ = 12;
            c.abilities.con = 10;
            c.classIndex = 3;   // the thief leg
            c.level = 6;
            c.dualOldClass = 0;   // the fighter leg
            c.dualOldLevel = 6;
            c.hp = c.maxHp = 30;
            if (!c.canBeginBardStudies()) ++bad;
            // the refusals: wrong race, fighter
            // window, thief window, low CHA, a
            // plain class, already a bard
            c.race = 1;
            if (c.canBeginBardStudies()) ++bad;
            c.race = 0;
            c.dualOldLevel = 4;
            if (c.canBeginBardStudies()) ++bad;
            c.dualOldLevel = 6;
            c.level = 10;
            if (c.canBeginBardStudies()) ++bad;
            c.level = 6;
            c.abilities.cha = 14;
            if (c.canBeginBardStudies()) ++bad;
            c.abilities.cha = 15;
            c.classIndex = 0;
            if (c.canBeginBardStudies()) ++bad;
            c.classIndex = 3;
            // the studies: hit dice kept, 1st-level
            // restart, the Table III kit, the
            // Table I level-1 slots
            c.beginBardStudies();
            if (!c.bard) ++bad;
            if (c.classIndex != 2) ++bad;
            if (c.subclass != -1) ++bad;
            if (c.level != 1) ++bad;
            if (c.xp != 0) ++bad;
            if (c.hp != 30 || c.maxHp != 30) ++bad;
            if (c.dualOldClass != -1) ++bad;
            if (c.armor.id != items::ARMOR_LEATHER) ++bad;
            if (c.shield) ++bad;
            if (c.slotsByLevel[0] != 1) ++bad;
            if (c.slotsByLevel[1] != 0) ++bad;
            if (c.slotsByLevel[5] != 0) ++bad;
            if (c.canBeginBardStudies()) ++bad;
        }
        // the Table I queue and the promotion die,
        // on a live party train loop
        {
            Party p;
            Character c;
            c.name = "Rhymer";
            c.bard = true;
            c.classIndex = 2;
            c.level = 1;
            c.hp = c.maxHp = 30;
            p.members.push_back(c);
            rules::Rng r{7};
            rules::Dice d(r);
            MessageLog log;
            p.gainXp(2500, d, log);
            if (p.members[0].xp != 2500) ++bad;
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 2) ++bad;
            if (p.members[0].maxHp <= 30) ++bad;
        }
        printf("R235 bard engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R236: the bard specials audit ----
    // The poetics seam (the R236 helpers), the
    // Table II lore and charm percents, the
    // language ladder, and the Table I dice.
    {
        int bad = 0;
        // the poetics seam: the +1 ferocity, the
        // 2 rounds required, the round and alive gates
        if (rules::bardPoeticsHitBonus() != 1) ++bad;
        if (rules::bardPoeticsRoundsRequired() != 2) ++bad;
        if (rules::bardPoeticsActive(0, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(1, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(2, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(3, 1) != 1) ++bad;
        if (rules::bardPoeticsActive(9, 1) != 1) ++bad;
        if (rules::bardPoeticsActive(9, 0) != 0) ++bad;
        if (rules::bardPoeticsActive(1, 2) != 0) ++bad;
        // Table II legend lore (the 14th-level 55
        // IS as printed - the R186 pin)
        if (rules::bardLegendLorePercent(0) != 0) ++bad;
        if (rules::bardLegendLorePercent(1) != 0) ++bad;
        if (rules::bardLegendLorePercent(5) != 13) ++bad;
        if (rules::bardLegendLorePercent(13) != 56) ++bad;
        if (rules::bardLegendLorePercent(14) != 55) ++bad;
        if (rules::bardLegendLorePercent(23) != 99) ++bad;
        if (rules::bardLegendLorePercent(99) != 99) ++bad;
        // Table II charm (a miss at 0th - the clamp)
        if (rules::bardCharmPercent(1) != 15) ++bad;
        if (rules::bardCharmPercent(5) != 30) ++bad;
        if (rules::bardCharmPercent(14) != 60) ++bad;
        if (rules::bardCharmPercent(23) != 95) ++bad;
        // the language ladder (a new tongue at the
        // printed levels, none at 1st-3rd)
        if (rules::bardLanguages(1) != 0) ++bad;
        if (rules::bardLanguages(3) != 0) ++bad;
        if (rules::bardLanguages(4) != 1) ++bad;
        if (rules::bardLanguages(23) != 1) ++bad;
        // the Table I dice (d6 through 11, then +1)
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        printf("R236 bard specials audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R181: the attacks per melee round audit ----
    // The fighter-group bands, the under-one-hit-die
    // note, every monk ladder cell, the monk weapon
    // damage ladder, and the turn.cpp repin.
    {
        int bad = 0;
        // the fighter-group bands: level probes around every
        // printed edge (fighter/paladin 6,7,12,13; ranger
        // 7,8,14,15)
        const int kMid[3]  = { 7, 7, 8 };
        const int kHigh[3] = { 13, 13, 15 };
        for (int k = 0; k < 3; ++k) {
            for (int lv = 1; lv <= 20; ++lv) {
                rules::AtkRate r =
                    rules::fighterGroupAttacks(k, lv);
                int att = 1, rds = 1;
                if (lv >= kHigh[k]) { att = 2; rds = 1; }
                else if (lv >= kMid[k]) { att = 3; rds = 2; }
                if (r.attacks != att || r.rounds != rds) ++bad;
            }
        }
        // the under-one-hit-die note: one attack per
        // fighter experience level
        if (rules::fighterAttacksVsSubOneHitDice(1) != 1) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(7) != 7) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(13) != 13) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(0) != 1) ++bad;
        // every monk ladder cell (Monks Table II)
        const int kMnkAc[17] = {
            10, 9, 8, 7, 7, 6, 5, 4, 3, 3, 2, 1, 0,
            -1, -1, -2, -3
        };
        const int kMnkMove[17] = {
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
            26, 27, 28, 29, 30, 32
        };
        const int kMnkAtt[17] = {
            1, 1, 1, 5, 5, 3, 3, 3, 2, 2, 5, 5, 5,
            3, 3, 4, 4
        };
        const int kMnkRds[17] = {
            1, 1, 1, 4, 4, 2, 2, 2, 1, 1, 2, 2, 2,
            1, 1, 1, 1
        };
        const int kMnkLo[17] = {
            1, 1, 1, 1, 2, 2, 3, 2, 3, 3, 4, 4, 5,
            5, 6, 5, 8
        };
        const int kMnkHi[17] = {
            3, 4, 6, 6, 7, 8, 9, 12, 12, 13, 13, 16,
            17, 20, 24, 30, 32
        };
        if (rules::monkLadderRowCount() != 17) ++bad;
        for (int lv = 1; lv <= 17; ++lv) {
            const rules::MonkLadderRow& r =
                rules::monkLadderRow(lv);
            if (r.level != lv) ++bad;
            if (r.acClass != kMnkAc[lv-1]) ++bad;
            if (r.moveInches != kMnkMove[lv-1]) ++bad;
            if (r.atkAttacks != kMnkAtt[lv-1]) ++bad;
            if (r.atkRounds != kMnkRds[lv-1]) ++bad;
            if (r.dmgLo != kMnkLo[lv-1]) ++bad;
            if (r.dmgHi != kMnkHi[lv-1]) ++bad;
        }
        // clamps: level 0 and 99 read level 1 and 17
        if (rules::monkLadderRow(0).level != 1) ++bad;
        if (rules::monkLadderRow(99).level != 17) ++bad;
        if (rules::monkOpenHandAttacks(4).attacks != 5
            || rules::monkOpenHandAttacks(4).rounds != 4) ++bad;
        // the monk weapon damage ladder (doubled form:
        // +1/2 per level, Grand Master +8 1/2)
        if (rules::monkWeaponDamageBonus2x(1) != 1) ++bad;
        if (rules::monkWeaponDamageBonus2x(2) != 2) ++bad;
        if (rules::monkWeaponDamageBonus2x(17) != 17) ++bad;
        if (rules::monkWeaponDamageBonus2x(99) != 17) ++bad;
        // the turn.cpp repin: the base-class function uses the
        // fighter bands (the heavy round of the printed cycle)
        if (rules::meleeAttacksPerRound(0, 6) != 1) ++bad;
        if (rules::meleeAttacksPerRound(0, 7) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 12) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 13) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 20) != 2) ++bad;
        if (rules::meleeAttacksPerRound(1, 20) != 1) ++bad;
        if (rules::meleeAttacksPerRound(2, 20) != 1) ++bad;
        if (rules::meleeAttacksPerRound(3, 20) != 1) ++bad;
        printf("R181 attacks per melee round audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R182: the druid spell layer audit ----
    // Every printed slot cell of the 14x7 table, every
    // roster row, the per-level counts, the reversible
    // flags and name spot-checks from the print.
    {
        int bad = 0;
        // the full slots table, cell by cell
        static const int kSlots[14][7] = {
            { 2, 0, 0, 0, 0, 0, 0 },
            { 2, 1, 0, 0, 0, 0, 0 },
            { 3, 2, 1, 0, 0, 0, 0 },
            { 4, 2, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 1, 0, 0, 0 },
            { 4, 4, 3, 1, 0, 0, 0 },
            { 4, 4, 3, 2, 0, 0, 0 },
            { 5, 4, 3, 2, 1, 0, 0 },
            { 5, 4, 3, 3, 2, 0, 0 },
            { 5, 5, 3, 3, 2, 1, 0 },
            { 5, 5, 4, 4, 3, 2, 1 },
            { 6, 5, 5, 5, 4, 3, 2 },
            { 6, 6, 6, 6, 5, 4, 3 },
        };
        for (int dl = 1; dl <= 14; ++dl)
            for (int sl = 1; sl <= 7; ++sl)
                if (rules::druidSpellSlots(dl, sl)
                    != kSlots[dl-1][sl-1]) ++bad;
        // the clamps: level 0 and 99 read level 1 and 14;
        // spell level 0 and 99 read 1 and 7
        if (rules::druidSpellSlots(0, 1) != 2) ++bad;
        if (rules::druidSpellSlots(99, 7) != 3) ++bad;
        if (rules::druidSpellSlots(14, 8) != 3) ++bad;
        if (rules::druidSpellSlots(1, 0) != 2) ++bad;
        // the roster: 77 rows, every level and flag
        if (rules::druidSpellTotal() != 77) ++bad;
        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };
        int revCount = 0;
        for (int i = 0; i < 77; ++i) {
            const rules::DruidSpell& s =
                rules::druidSpell(i);
            if (s.level < 1 || s.level > 7) ++bad;
            if (s.reversible != 0 && s.reversible != 1) ++bad;
            byLevel[s.level] += 1;
            revCount += s.reversible;
        }
        // the printed per-level counts 12/12/12/12/8/12/9
        if (byLevel[1] != 12 || byLevel[2] != 12
            || byLevel[3] != 12 || byLevel[4] != 12) ++bad;
        if (byLevel[5] != 8 || byLevel[6] != 12
            || byLevel[7] != 9) ++bad;
        // 16 printed reversible spells
        if (revCount != 16) ++bad;
        for (int sl = 1; sl <= 7; ++sl) {
            int want = (sl == 5) ? 8
                : ((sl == 7) ? 9 : 12);
            if (rules::druidSpellCountByLevel(sl)
                != want) ++bad;
        }
        // name and flag spot-checks (the print)
        if (std::string(rules::druidSpell(0).name)
            != "Animal Friendship") ++bad;
        if (std::string(rules::druidSpell(9).name)
            != "Purify Water") ++bad;
        if (rules::druidSpell(9).reversible != 1) ++bad;
        if (std::string(rules::druidSpell(38).name)
            != "Control Temperature, 10' Radius") ++bad;
        if (std::string(rules::druidSpell(34).name)
            != "Tree") ++bad;
        if (std::string(rules::druidSpell(71).name)
            != "Chariot Of Sustarre") ++bad;
        if (std::string(rules::druidSpell(76).name)
            != "Transmute Metal To Wood") ++bad;
        if (rules::druidSpell(76).level != 7) ++bad;
        if (rules::druidSpell(69).reversible != 1) ++bad;
        // roster index spot-probes: level-1 rows 0-11,
        // level-2 rows 12-23, level-3 24-35, level-4
        // 36-47, level-5 48-55, level-6 56-67, level-7 68-76
        if (rules::druidSpell(12).level != 2) ++bad;
        if (rules::druidSpell(36).level != 4) ++bad;
        if (rules::druidSpell(48).level != 5) ++bad;
        if (rules::druidSpell(56).level != 6) ++bad;
        if (rules::druidSpell(68).level != 7) ++bad;
        printf("R182 druid spell layer audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R183: the illusionist spell layer audit ----
    // Every printed slot cell of the 26x7 table, every
    // roster row, the per-level counts and name spot-
    // checks from the print.
    {
        int bad = 0;
        // the full slots table, cell by cell
        static const int kSlots[26][7] = {
            { 1, 0, 0, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0, 0, 0 },
            { 2, 1, 0, 0, 0, 0, 0 },
            { 3, 2, 0, 0, 0, 0, 0 },
            { 4, 2, 1, 0, 0, 0, 0 },
            { 4, 3, 1, 0, 0, 0, 0 },
            { 4, 3, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 1, 0, 0, 0 },
            { 5, 3, 3, 2, 0, 0, 0 },
            { 5, 4, 3, 2, 1, 0, 0 },
            { 5, 4, 3, 3, 2, 0, 0 },
            { 5, 5, 4, 3, 2, 1, 0 },
            { 5, 5, 4, 3, 2, 2, 0 },
            { 5, 5, 4, 3, 2, 2, 1 },
            { 5, 5, 4, 4, 2, 2, 2 },
            { 5, 5, 5, 4, 3, 2, 2 },
            { 5, 5, 5, 5, 3, 2, 2 },
            { 5, 5, 5, 5, 3, 3, 2 },
            { 5, 5, 5, 5, 4, 3, 2 },
            { 5, 5, 5, 5, 4, 3, 3 },
            { 5, 5, 5, 5, 5, 4, 3 },
            { 5, 5, 5, 5, 5, 5, 4 },
            { 5, 5, 5, 5, 5, 5, 5 },
            { 6, 6, 6, 6, 5, 5, 5 },
            { 6, 6, 6, 6, 6, 6, 6 },
            { 7, 7, 7, 7, 6, 6, 6 },
        };
        for (int il = 1; il <= 26; ++il)
            for (int sl = 1; sl <= 7; ++sl)
                if (rules::illusionistSpellSlots(il, sl)
                    != kSlots[il-1][sl-1]) ++bad;
        // the clamps: level 0 and 99 read level 1 and 26;
        // spell level 0 and 99 read 1 and 7
        if (rules::illusionistSpellSlots(0, 1) != 1) ++bad;
        if (rules::illusionistSpellSlots(99, 7) != 6) ++bad;
        if (rules::illusionistSpellSlots(26, 8) != 6) ++bad;
        if (rules::illusionistSpellSlots(1, 0) != 1) ++bad;
        // the roster: 61 rows, every level
        if (rules::illusionistSpellTotal() != 61) ++bad;
        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };
        for (int i = 0; i < 61; ++i) {
            const rules::IllusionistSpell& s =
                rules::illusionistSpell(i);
            if (s.level < 1 || s.level > 7) ++bad;
            byLevel[s.level] += 1;
        }
        // the printed per-level counts 8/16/11/5/12/4/5
        if (byLevel[1] != 8 || byLevel[2] != 16
            || byLevel[3] != 11 || byLevel[4] != 5) ++bad;
        if (byLevel[5] != 12 || byLevel[6] != 4
            || byLevel[7] != 5) ++bad;
        for (int sl = 1; sl <= 7; ++sl) {
            int want = (sl == 1) ? 8
                : ((sl == 2) ? 16 : ((sl == 3) ? 11
                : ((sl == 4) ? 5 : ((sl == 5) ? 12
                : ((sl == 6) ? 4 : 5)))));
            if (rules::illusionistSpellCountByLevel(sl)
                != want) ++bad;
        }
        // name spot-checks (the print, the book order)
        if (std::string(rules::illusionistSpell(0).name)
            != "Audible Glamer") ++bad;
        if (std::string(rules::illusionistSpell(7).name)
            != "Wall Of Fog") ++bad;
        if (std::string(rules::illusionistSpell(8).name)
            != "Blindness") ++bad;
        if (std::string(rules::illusionistSpell(23).name)
            != "Ventriloquism") ++bad;
        if (std::string(rules::illusionistSpell(24).name)
            != "Invisibility, 10' Radius") ++bad;
        if (std::string(rules::illusionistSpell(34).name)
            != "Massmorph") ++bad;
        if (std::string(rules::illusionistSpell(39).name)
            != "Shadow Monsters") ++bad;
        if (std::string(rules::illusionistSpell(51).name)
            != "Shades") ++bad;
        if (std::string(rules::illusionistSpell(55).name)
            != "Veil") ++bad;
        if (std::string(rules::illusionistSpell(60).name)
            != "Vision") ++bad;
        // roster index spot-probes: level-1 rows 0-7,
        // level-2 8-23, level-3 24-34, level-4 35-39,
        // level-5 40-51, level-6 52-55, level-7 56-60
        if (rules::illusionistSpell(8).level != 2) ++bad;
        if (rules::illusionistSpell(24).level != 3) ++bad;
        if (rules::illusionistSpell(35).level != 4) ++bad;
        if (rules::illusionistSpell(40).level != 5) ++bad;
        if (rules::illusionistSpell(52).level != 6) ++bad;
        if (rules::illusionistSpell(56).level != 7) ++bad;
        printf("R183 illusionist spell layer audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R184: the paladin and ranger spell layers audit ----
    // Every printed slot cell of both progressions,
    // the specials ladders and the giant-class roster.
    {
        int bad = 0;
        // the paladin table, cell by cell (levels 9-20)
        static const int kPal[12][4] = {
            { 1, 0, 0, 0 },
            { 2, 0, 0, 0 },
            { 2, 1, 0, 0 },
            { 2, 2, 0, 0 },
            { 2, 2, 1, 0 },
            { 3, 2, 1, 0 },
            { 3, 2, 1, 1 },
            { 3, 3, 1, 1 },
            { 3, 3, 2, 1 },
            { 3, 3, 3, 1 },
            { 3, 3, 3, 2 },
            { 3, 3, 3, 3 },
        };
        for (int pl = 9; pl <= 20; ++pl)
            for (int sl = 1; sl <= 4; ++sl)
                if (rules::paladinSpellSlots(pl, sl)
                    != kPal[pl-9][sl-1]) ++bad;
        // the ranger table, cell by cell (levels 8-17,
        // druidic 1-3 and MU 1-2)
        static const int kRng[10][5] = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 1, 0 },
            { 2, 0, 0, 1, 0 },
            { 2, 0, 0, 2, 0 },
            { 2, 1, 0, 2, 1 },
            { 2, 1, 0, 2, 1 },
            { 2, 2, 0, 2, 2 },
            { 2, 2, 0, 2, 2 },
            { 2, 2, 1, 2, 2 },
            { 2, 2, 2, 2, 2 },
        };
        for (int rl = 8; rl <= 17; ++rl) {
            for (int sl = 1; sl <= 3; ++sl)
                if (rules::rangerSpellSlots(rl, 0, sl)
                    != kRng[rl-8][sl-1]) ++bad;
            for (int sl = 1; sl <= 2; ++sl)
                if (rules::rangerSpellSlots(rl, 1, sl)
                    != kRng[rl-8][sl+2]) ++bad;
        }
        // below the spell bands: 0 slots
        if (rules::paladinSpellSlots(8, 1) != 0) ++bad;
        if (rules::paladinSpellSlots(1, 1) != 0) ++bad;
        if (rules::rangerSpellSlots(7, 0, 1) != 0) ++bad;
        if (rules::rangerSpellSlots(9, 1, 1) != 1) ++bad;
        // the clamps: past the max-ability rows
        if (rules::paladinSpellSlots(21, 1) != 3) ++bad;
        if (rules::paladinSpellSlots(99, 4) != 3) ++bad;
        if (rules::rangerSpellSlots(18, 0, 3) != 2) ++bad;
        if (rules::rangerSpellSlots(99, 1, 2) != 2) ++bad;
        // the clamps: spell level out of range reads
        // the band edges (druidic 4 pins as level 3, MU 3
        // as level 2)
        if (rules::rangerSpellSlots(17, 0, 4) != 2) ++bad;
        if (rules::rangerSpellSlots(17, 1, 3) != 2) ++bad;
        // the shared-list wiring
        if (rules::paladinSpellListClass()
            != rules::CLASS_CLERIC) ++bad;
        if (rules::rangerDruidicSpellListClass()
            != rules::CLASS_CLERIC) ++bad;
        if (rules::rangerMagicSpellListClass()
            != rules::CLASS_MAGIC_USER) ++bad;
        // lay on hands: 2 hp per level, once per day
        if (rules::paladinLayOnHandsHp(1) != 2) ++bad;
        if (rules::paladinLayOnHandsHp(9) != 18) ++bad;
        if (rules::paladinLayOnHandsHp(20) != 40) ++bad;
        if (rules::paladinLayOnHandsHp(0) != 0) ++bad;
        // cure disease: one per week per five levels
        if (rules::paladinCureDiseasePerWeek(1) != 1) ++bad;
        if (rules::paladinCureDiseasePerWeek(5) != 1) ++bad;
        if (rules::paladinCureDiseasePerWeek(6) != 2) ++bad;
        if (rules::paladinCureDiseasePerWeek(10) != 2) ++bad;
        if (rules::paladinCureDiseasePerWeek(11) != 3) ++bad;
        if (rules::paladinCureDiseasePerWeek(15) != 3) ++bad;
        if (rules::paladinCureDiseasePerWeek(16) != 4) ++bad;
        // the giant-class roster: 11 creatures
        if (rules::rangerGiantClassCount() != 11) ++bad;
        if (std::string(rules::rangerGiantClassName(0))
            != "bugbear") ++bad;
        if (std::string(rules::rangerGiantClassName(10))
            != "troll") ++bad;
        if (!rules::rangerIsGiantClass("ogre mage")) ++bad;
        if (!rules::rangerIsGiantClass("kobold")) ++bad;
        if (rules::rangerIsGiantClass("lizard man")) ++bad;  // R184b: the ogre probe fix
        if (rules::rangerIsGiantClass("giant frog")) ++bad;
        if (rules::rangerIsGiantClass("")) ++bad;
        // the bonus: +1 per ranger level
        if (rules::rangerGiantClassBonus(5) != 5) ++bad;
        if (rules::rangerGiantClassBonus(17) != 17) ++bad;
        if (rules::rangerGiantClassBonus(0) != 0) ++bad;
        printf("R184 paladin and ranger spell layers audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R185: the multi-class and dual-class audit ----
    // Every race x combo cell, the quotient and split
    // ladders, the allowances and the dual-class gates.
    {
        int bad = 0;
        // the combo counts (human 0, dwarf 1, elf 4,
        // gnome 3, half-elf 8, halfling 1, half-orc 5)
        static const int kCount[7] = {
            0,
            1,
            4,
            3,
            8,
            1,
            5,
        };
        for (int r = 0; r < 7; ++r)
            if (rules::multiClassComboCount(r)
                != kCount[r]) ++bad;
        // every printed combo, positive
        if (!rules::multiClassAllowed(1, 9)) ++bad;
        if (!rules::multiClassAllowed(2, 3)) ++bad;
        if (!rules::multiClassAllowed(2, 9)) ++bad;
        if (!rules::multiClassAllowed(2, 10)) ++bad;
        if (!rules::multiClassAllowed(2, 11)) ++bad;
        if (!rules::multiClassAllowed(3, 17)) ++bad;
        if (!rules::multiClassAllowed(3, 9)) ++bad;
        if (!rules::multiClassAllowed(3, 24)) ++bad;
        if (!rules::multiClassAllowed(4, 5)) ++bad;
        if (!rules::multiClassAllowed(4, 36)) ++bad;
        if (!rules::multiClassAllowed(4, 6)) ++bad;
        if (!rules::multiClassAllowed(4, 3)) ++bad;
        if (!rules::multiClassAllowed(4, 9)) ++bad;
        if (!rules::multiClassAllowed(4, 10)) ++bad;
        if (!rules::multiClassAllowed(4, 7)) ++bad;
        if (!rules::multiClassAllowed(4, 11)) ++bad;
        if (!rules::multiClassAllowed(5, 9)) ++bad;
        if (!rules::multiClassAllowed(6, 5)) ++bad;
        if (!rules::multiClassAllowed(6, 12)) ++bad;
        if (!rules::multiClassAllowed(6, 68)) ++bad;
        if (!rules::multiClassAllowed(6, 9)) ++bad;
        if (!rules::multiClassAllowed(6, 65)) ++bad;
        // the negative probes: unprinted combos
        if (rules::multiClassAllowed(0,
            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        if (rules::multiClassPossible(0)) ++bad;
        if (rules::multiClassAllowed(1,
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (rules::multiClassAllowed(2,
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiClassAllowed(3,
            rules::MC_FIGHTER | rules::MC_RANGER)) ++bad;
        if (rules::multiClassAllowed(5,
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (rules::multiClassAllowed(6,
            rules::MC_FIGHTER | rules::MC_ILLUSIONIST)) ++bad;
        if (rules::multiClassAllowed(4, 0)) ++bad;
        if (rules::multiClassAllowed(4, 1)) ++bad;
        // the clamped reads: index past the list
        // reads the last combo
        if (rules::multiClassCombo(4, 8)
            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER
               | rules::MC_THIEF)) ++bad;
        if (rules::multiClassCombo(4, 99)
            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER
               | rules::MC_THIEF)) ++bad;
        if (rules::multiClassCombo(0, 3) != 0) ++bad;
        if (rules::multiClassCombo(1, 7)
            != (rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        // the hit-point quotient ladder: fractions
        // under one half drop, one half and up
        // rounds up
        if (rules::multiclassHpQuotient(7, 2) != 4) ++bad;
        if (rules::multiclassHpQuotient(6, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(4, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(10, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(11, 3) != 4) ++bad;
        if (rules::multiclassHpQuotient(13, 3) != 4) ++bad;
        if (rules::multiclassHpQuotient(14, 3) != 5) ++bad;
        if (rules::multiclassHpQuotient(9, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(8, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(0, 0) != 0) ++bad;
        // the even XP split
        if (rules::multiclassXpShare(3000, 2) != 1500) ++bad;
        if (rules::multiclassXpShare(900, 3) != 300) ++bad;
        if (rules::multiclassXpShare(3000, 3) != 1000) ++bad;
        if (rules::multiclassXpShare(0, 2) != 0) ++bad;
        // the stalled-hit-dice rule
        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;
        if (!rules::multiclassHitDieStalled(11, 9)) ++bad;
        if (rules::multiclassHitDieStalled(8, 9)) ++bad;
        if (rules::multiclassHitDieStalled(0, 9)) ++bad;
        // the allowances
        if (!rules::multiclassThiefLimited(
            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        if (rules::multiclassThiefLimited(
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiclassThiefLimited(
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (!rules::multiclassClericEdgedOk(
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiclassClericEdgedOk(
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        // the half-elf cleric WIS minimum
        if (rules::halfelfClericWisMin() != 13) ++bad;
        // the dual-class gates
        if (!rules::dualClassRaceAllowed(0)) ++bad;
        if (rules::dualClassRaceAllowed(1)) ++bad;
        if (rules::dualClassRaceAllowed(2)) ++bad;
        if (rules::dualClassRaceAllowed(3)) ++bad;
        if (rules::dualClassRaceAllowed(4)) ++bad;
        if (rules::dualClassRaceAllowed(5)) ++bad;
        if (rules::dualClassRaceAllowed(6)) ++bad;
        if (!rules::dualClassPrimeGate(15, 17)) ++bad;
        if (!rules::dualClassPrimeGate(16, 18)) ++bad;
        if (rules::dualClassPrimeGate(14, 17)) ++bad;
        if (rules::dualClassPrimeGate(15, 16)) ++bad;
        if (rules::dualClassPrimeGate(9, 9)) ++bad;
        if (rules::DUAL_CLASS_OLD_PRIME_MIN != 15) ++bad;
        if (rules::DUAL_CLASS_NEW_PRIME_MIN != 17) ++bad;
        printf("R185 multi-class and dual-class audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R186: the bard audit ----
    // Every cell of Tables I and II, the gates,
    // the ladders and the wiring.
    {
        int bad = 0;
        // the ability gate: STR WIS DEX CHA 15+,
        // INT 12, CON 10
        if (!rules::bardAbilityGate(15, 15, 15, 15,
                                12, 10)) ++bad;
        if (!rules::bardAbilityGate(18, 16, 15, 17,
                                13, 11)) ++bad;
        if (rules::bardAbilityGate(14, 15, 15, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 14, 15, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 14, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 14,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                               11, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                               12, 9)) ++bad;
        // the race gate: human or half-elf
        if (!rules::bardRaceAllowed(0)) ++bad;
        if (!rules::bardRaceAllowed(4)) ++bad;
        if (rules::bardRaceAllowed(1)) ++bad;
        if (rules::bardRaceAllowed(2)) ++bad;
        if (rules::bardRaceAllowed(3)) ++bad;
        if (rules::bardRaceAllowed(5)) ++bad;
        if (rules::bardRaceAllowed(6)) ++bad;
        // the progression windows
        if (!rules::bardFighterWindow(5)) ++bad;
        if (!rules::bardFighterWindow(6)) ++bad;
        if (!rules::bardFighterWindow(7)) ++bad;
        if (rules::bardFighterWindow(4)) ++bad;
        if (rules::bardFighterWindow(8)) ++bad;
        if (rules::bardFighterWindow(9)) ++bad;
        if (!rules::bardThiefWindow(5)) ++bad;
        if (!rules::bardThiefWindow(9)) ++bad;
        if (rules::bardThiefWindow(4)) ++bad;
        if (rules::bardThiefWindow(10)) ++bad;
        if (!rules::bardNeutralOnly()) ++bad;
        // Bards Table I, cell by cell: the XP
        // thresholds, the titles, the hit dice,
        // the druid slots
        static const int kXp[23] = {
            0,
            2001,
            4001,
            8001,
            16001,
            25001,
            40001,
            60001,
            85001,
            110001,
            150001,
            200001,
            400001,
            600001,
            800001,
            1000001,
            1200001,
            1400001,
            1600001,
            1800001,
            2000001,
            2200001,
            3000001,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardXpForLevel(lv)
                != kXp[lv-1]) ++bad;
        static const char* const kTitles[23] = {
            "Rhymer",
            "Lyrist",
            "Sonnateer",
            "Skald",
            "Racaraide",
            "Joungleur",
            "Troubador",
            "Minstrel",
            "Muse",
            "Lorist",
            "Bard",
            "Master Bard",
            "M. Bard 13th",
            "M. Bard 14th",
            "M. Bard 15th",
            "M. Bard 16th",
            "M. Bard 17th",
            "M. Bard 18th",
            "M. Bard 19th",
            "M. Bard 20th",
            "M. Bard 21st",
            "M. Bard 22nd",
            "M. Bard 23rd",
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (std::string(rules::bardTitle(lv))
                != kTitles[lv-1]) ++bad;
        static const int kSlots[23][5] = {
            { 1, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0 },
            { 3, 0, 0, 0, 0 },
            { 3, 1, 0, 0, 0 },
            { 3, 2, 0, 0, 0 },
            { 3, 3, 0, 0, 0 },
            { 3, 3, 1, 0, 0 },
            { 3, 3, 2, 0, 0 },
            { 3, 3, 3, 0, 0 },
            { 3, 3, 3, 1, 0 },
            { 3, 3, 3, 2, 0 },
            { 3, 3, 3, 3, 0 },
            { 3, 3, 3, 3, 1 },
            { 3, 3, 3, 3, 2 },
            { 3, 3, 3, 3, 3 },
            { 4, 3, 3, 3, 3 },
            { 4, 4, 3, 3, 3 },
            { 4, 4, 4, 3, 3 },
            { 5, 4, 4, 4, 3 },
            { 5, 4, 4, 4, 4 },
            { 5, 5, 4, 4, 4 },
            { 5, 5, 5, 4, 4 },
            { 5, 5, 5, 5, 5 },
        };
        for (int lv = 1; lv <= 23; ++lv)
            for (int sl = 1; sl <= 5; ++sl)
                if (rules::bardDruidSlots(lv, sl)
                    != kSlots[lv-1][sl-1]) ++bad;
        // the hit dice ladder: 0*, 1-10, then
        // 10+1 through 10+12
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(2) != 1) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        if (rules::bardHitDice(0) != 0) ++bad;
        if (rules::bardHitDice(99) != 22) ++bad;
        // the clamps: level and spell level
        if (rules::bardXpForLevel(0) != 0) ++bad;
        if (rules::bardXpForLevel(99) != 3000001) ++bad;
        if (rules::bardDruidSlots(0, 1) != 0) ++bad;
        if (rules::bardDruidSlots(24, 1) != 5) ++bad;
        if (rules::bardDruidSlots(23, 6) != 5) ++bad;
        if (rules::bardDruidSlots(23, 0) != 5) ++bad;
        if (std::string(rules::bardTitle(24))
            != "M. Bard 23rd") ++bad;
        // the druid cast ladder: same level,
        // capped at 12th until the 23rd casts
        // at 13th
        if (rules::bardDruidCastLevel(1) != 1) ++bad;
        if (rules::bardDruidCastLevel(5) != 5) ++bad;
        if (rules::bardDruidCastLevel(12) != 12) ++bad;
        if (rules::bardDruidCastLevel(13) != 12) ++bad;
        if (rules::bardDruidCastLevel(22) != 12) ++bad;
        if (rules::bardDruidCastLevel(23) != 13) ++bad;
        if (rules::bardDruidCastLevel(0) != 0) ++bad;
        // Bards Table II, cell by cell: the
        // colleges, the languages, the percents
        static const char* const kCollege[23] = {
            "Probationer",
            "Fochlucan",
            "Fochlucan",
            "Fochlucan",
            "Mac-Fuirmidh",
            "Mac-Fuirmidh",
            "Mac-Fuirmidh",
            "Doss",
            "Doss",
            "Doss",
            "Canaith",
            "Canaith",
            "Canaith",
            "Cli",
            "Cli",
            "Cli",
            "Anstruth",
            "Anstruth",
            "Anstruth",
            "Ollamh",
            "Ollamh",
            "Ollamh",
            "Magna Alumnae",
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (std::string(rules::bardCollege(lv))
                != kCollege[lv-1]) ++bad;
        static const int kLang[23] = {
            0,
            0,
            0,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            1,
            1,
            1,
            1,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardLanguages(lv)
                != kLang[lv-1]) ++bad;
        static const int kCharm[23] = {
            15,
            20,
            22,
            24,
            30,
            32,
            34,
            40,
            42,
            44,
            50,
            53,
            56,
            60,
            63,
            66,
            70,
            73,
            76,
            80,
            84,
            88,
            95,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardCharmPercent(lv)
                != kCharm[lv-1]) ++bad;
        static const int kLore[23] = {
            0,
            5,
            7,
            10,
            13,
            16,
            20,
            25,
            30,
            35,
            50,
            53,
            56,
            55,
            60,
            65,
            70,
            75,
            80,
            85,
            90,
            95,
            99,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardLegendLorePercent(lv)
                != kLore[lv-1]) ++bad;
        // Table III: the weapon roster
        if (rules::bardWeaponCount() != 9) ++bad;
        if (!rules::bardWeaponAllowed("scimitar")) ++bad;
        if (!rules::bardWeaponAllowed("sword")) ++bad;
        if (!rules::bardWeaponAllowed("club")) ++bad;
        if (!rules::bardWeaponAllowed("staff")) ++bad;
        if (rules::bardWeaponAllowed("long bow")) ++bad;
        if (rules::bardWeaponAllowed("battle axe")) ++bad;
        if (rules::bardWeaponAllowed("")) ++bad;
        if (std::string(rules::bardWeaponName(0))
            != "club") ++bad;
        if (std::string(rules::bardWeaponName(8))
            != "sword") ++bad;
        // Table III: the armor and use pins
        if (!rules::bardOilAllowed()) ++bad;
        if (rules::bardPoisonAllowed(false)) ++bad;
        if (!rules::bardPoisonAllowed(true)) ++bad;
        if (rules::bardShieldAllowed()) ++bad;
        // the poetics layers
        if (rules::BARD_POETIC_ROUNDS != 2) ++bad;
        if (rules::BARD_POETIC_TURN != 1) ++bad;
        if (rules::BARD_MORALE_BONUS != 10) ++bad;
        if (rules::BARD_HIT_BONUS != 1) ++bad;
        // the henchmen ladder: 1 at 5th, 2 at
        // 8th, 3 at 11th, 4 at 14th, 5 at 17th,
        // 6 at 20th, any number at 23rd
        if (rules::bardHenchmen(1) != 0) ++bad;
        if (rules::bardHenchmen(4) != 0) ++bad;
        if (rules::bardHenchmen(5) != 1) ++bad;
        if (rules::bardHenchmen(7) != 1) ++bad;
        if (rules::bardHenchmen(8) != 2) ++bad;
        if (rules::bardHenchmen(11) != 3) ++bad;
        if (rules::bardHenchmen(14) != 4) ++bad;
        if (rules::bardHenchmen(17) != 5) ++bad;
        if (rules::bardHenchmen(20) != 6) ++bad;
        if (rules::bardHenchmen(22) != 6) ++bad;
        if (rules::bardHenchmen(23) != 999) ++bad;
        if (rules::bardHenchmen(0) != 0) ++bad;
        // the musical item bonuses
        if (rules::bardDrumsOfPanicSaveMod() != -1) ++bad;
        if (rules::bardHornOfBlastingDamageFactorPercent()
            != 150) ++bad;
        if (rules::bardLyreOfBuildingFactor() != 2) ++bad;
        if (rules::bardPipesOfSewerRatFactor() != 2) ++bad;
        printf("R186 the bard audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R187: the per-subclass specials audit ----
    // Every fee cell, the disguise ladder, backstab,
    // the skill sharing, the monk specials A-K, the
    // stun/kill rules, the ranger numbers, the
    // paladin turn ladder.
    {
        int bad = 0;
        // the fee table, cell by cell (15 x 8)
        static const int kFees[15][8] = {
            { 50, 100, 150, 200, 250, 0, 0, 0 },
            { 60, 120, 175, 250, 300, 350, 0, 0 },
            { 75, 150, 225, 300, 400, 500, 0, 0 },
            { 100, 200, 300, 450, 600, 750, 1000, 0 },
            { 150, 300, 450, 700, 900, 1100, 1300, 1500 },
            { 250, 500, 750, 1000, 1300, 1600, 2000, 2500 },
            { 400, 800, 1200, 1600, 2000, 2500, 3500, 4500 },
            { 600, 1200, 1800, 2400, 3000, 3750, 5000, 7500 },
            { 850, 1700, 2600, 3500, 4400, 6000, 7500, 10000 },
            { 1200, 2400, 3600, 4800, 6000, 8000, 10000, 15000 },
            { 1700, 3500, 5100, 7000, 9000, 12000, 15000, 20000 },
            { 2500, 5000, 7500, 10000, 13000, 17500, 20000, 25000 },
            { 3500, 7000, 11000, 15000, 19000, 25000, 32500, 40000 },
            { 5000, 10000, 15000, 20000, 27500, 35000, 45000, 60000 },
            { 10000, 20000, 35000, 50000, 75000, 100000, 150000, 250000 },
        };
        for (int al = 1; al <= 15; ++al)
            for (int b = 0; b < 8; ++b)
                if (rules::assassinMinimumFee(al, b)
                    != kFees[al-1][b]) ++bad;
        // the dash cells pin as 0
        if (rules::assassinMinimumFee(1, 5) != 0) ++bad;
        if (rules::assassinMinimumFee(1, 6) != 0) ++bad;
        if (rules::assassinMinimumFee(1, 7) != 0) ++bad;
        if (rules::assassinMinimumFee(4, 7) != 0) ++bad;
        // the clamps: level and band
        if (rules::assassinMinimumFee(0, 0) != 50) ++bad;
        if (rules::assassinMinimumFee(99, 7) != 250000) ++bad;
        if (rules::assassinMinimumFee(15, 99) != 250000) ++bad;
        if (rules::assassinMinimumFee(15, -5) != 10000) ++bad;
        // the victim bands
        if (rules::assassinVictimBand(0) != 0) ++bad;
        if (rules::assassinVictimBand(2) != 1) ++bad;
        if (rules::assassinVictimBand(3) != 2) ++bad;
        if (rules::assassinVictimBand(6) != 3) ++bad;
        if (rules::assassinVictimBand(9) != 4) ++bad;
        if (rules::assassinVictimBand(12) != 5) ++bad;
        if (rules::assassinVictimBand(15) != 6) ++bad;
        if (rules::assassinVictimBand(16) != 7) ++bad;
        if (rules::assassinVictimBand(99) != 7) ++bad;
        if (rules::assassinVictimBand(-5) != 0) ++bad;
        // the disguise ladder: base 2, +2 per pose,
        // max 8, then the observer adjustment
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 24) != 2) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, false, false, 24) != 4) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, false, 24) != 6) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 24) != 8) ++bad;
        // the print example: INT+WIS 20 reduces the
        // chance by 4%
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 20) != -2) ++bad;
        // INT+WIS above 30 increases by 1% per point
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 36) != 8) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 18) != 2) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 31) != 9) ++bad;
        // backstab: the multiplier ladder
        if (rules::backstabMultiplier(1) != 2) ++bad;
        if (rules::backstabMultiplier(4) != 2) ++bad;
        if (rules::backstabMultiplier(5) != 3) ++bad;
        if (rules::backstabMultiplier(8) != 3) ++bad;
        if (rules::backstabMultiplier(9) != 4) ++bad;
        if (rules::backstabMultiplier(12) != 4) ++bad;
        if (rules::backstabMultiplier(13) != 5) ++bad;
        if (rules::backstabMultiplier(16) != 5) ++bad;
        if (rules::backstabMultiplier(17) != 5) ++bad;
        if (rules::backstabMultiplier(0) != 2) ++bad;
        if (rules::backstabHitBonusPercent() != 20) ++bad;
        if (rules::backstabHitBonusDie() != 4) ++bad;
        // the thief-skill sharing
        if (rules::assassinThiefSkillLevel(3) != 1) ++bad;
        if (rules::assassinThiefSkillLevel(4) != 2) ++bad;
        if (rules::assassinThiefSkillLevel(15) != 13) ++bad;
        if (rules::assassinThiefSkillLevel(1) != 1) ++bad;
        if (rules::assassinThiefSkillLevel(2) != 1) ++bad;
        if (rules::assassinBackstabLevel(3) != 3) ++bad;
        if (rules::assassinBackstabLevel(15) != 15) ++bad;
        if (rules::assassinBackstabLevel(1) != 1) ++bad;
        if (rules::monkThiefSkillLevel(1) != 1) ++bad;
        if (rules::monkThiefSkillLevel(7) != 7) ++bad;
        if (rules::monkThiefSkillLevel(17) != 17) ++bad;
        if (rules::monkThiefAbilityCount() != 6) ++bad;
        if (std::string(rules::monkThiefAbilityName(0))
            != "open locks") ++bad;
        if (std::string(rules::monkThiefAbilityName(5))
            != "climb walls") ++bad;
        // the monk surprise ladder
        if (rules::monkSurprisedPercent(1) != 33) ++bad;
        if (rules::monkSurprisedPercent(2) != 32) ++bad;
        if (rules::monkSurprisedPercent(3) != 30) ++bad;
        if (rules::monkSurprisedPercent(4) != 28) ++bad;
        if (rules::monkSurprisedPercent(5) != 26) ++bad;
        if (rules::monkSurprisedPercent(13) != 10) ++bad;
        if (rules::monkSurprisedPercent(17) != 2) ++bad;
        if (rules::monkSurprisedPercent(18) != 0) ++bad;
        if (rules::monkSurprisedPercent(0) != 33) ++bad;
        // the specials ladder A-K
        if (rules::monkSpecialsCount(1) != 0) ++bad;
        if (rules::monkSpecialsCount(2) != 0) ++bad;
        if (rules::monkSpecialsCount(3) != 1) ++bad;
        if (rules::monkSpecialsCount(7) != 5) ++bad;
        if (rules::monkSpecialsCount(13) != 11) ++bad;
        if (rules::monkSpecialsCount(17) != 11) ++bad;
        if (rules::monkSpecialLetter(0) != 'A') ++bad;
        if (rules::monkSpecialLetter(10) != 'K') ++bad;
        if (rules::monkSpecialLetter(99) != 'K') ++bad;
        if (rules::monkSpecialLevel(0) != 3) ++bad;
        if (rules::monkSpecialLevel(10) != 13) ++bad;
        // the individual specials
        if (rules::monkSpeakWithAnimalsLevel() != 3) ++bad;
        if (rules::monkEspSuccessPercent(3) != 100) ++bad;
        if (rules::monkEspSuccessPercent(4) != 30) ++bad;
        if (rules::monkEspSuccessPercent(5) != 28) ++bad;
        if (rules::monkEspSuccessPercent(6) != 26) ++bad;
        if (rules::monkEspSuccessPercent(20) != 0) ++bad;
        if (rules::monkDiseaseImmuneLevel() != 5) ++bad;
        if (rules::monkCatalepsyTurns(5) != 0) ++bad;
        if (rules::monkCatalepsyTurns(6) != 12) ++bad;
        if (rules::monkCatalepsyTurns(7) != 14) ++bad;
        if (rules::monkHealBonusPerDay(6) != 0) ++bad;
        if (rules::monkHealBonusPerDay(7) != 1) ++bad;
        if (rules::monkHealBonusPerDay(8) != 2) ++bad;
        if (rules::monkHealBonusPerDay(9) != 3) ++bad;
        if (rules::monkSpeakWithPlantsLevel() != 8) ++bad;
        if (rules::monkCharmAffectPercent(8) != 100) ++bad;
        if (rules::monkCharmAffectPercent(9) != 50) ++bad;
        if (rules::monkCharmAffectPercent(10) != 45) ++bad;
        if (rules::monkCharmAffectPercent(11) != 40) ++bad;
        if (rules::monkCharmAffectPercent(19) != 0) ++bad;
        if (rules::monkMindBlastLevel() != 10) ++bad;
        if (rules::monkMindBlastEffectiveInt() != 18) ++bad;
        if (rules::monkPoisonImmuneLevel() != 11) ++bad;
        if (rules::monkGeasImmuneLevel() != 12) ++bad;
        if (rules::monkQuiveringPalmLevel() != 13) ++bad;
        if (rules::monkQuiveringPalmAttemptsPerWeek()
            != 1) ++bad;
        if (rules::monkQuiveringPalmTouchRounds() != 3) ++bad;
        if (rules::monkQuiveringPalmHpCapPercent() != 200) ++bad;
        // the stun and kill rules
        if (rules::monkStunMargin() != 5) ++bad;
        if (rules::monkStunRoundsDie() != 6) ++bad;
        // the print example: AC -1 at 7th is a
        // negative chance; a 9th-level monk vs
        // AC 5 is 7%
        if (rules::monkKillPercent(-1, 7) != -1) ++bad;
        if (rules::monkKillPercent(5, 9) != 7) ++bad;
        if (rules::monkKillPercent(5, 7) != 5) ++bad;
        if (rules::monkKillPercent(0, 10) != 3) ++bad;
        if (rules::monkKillPercent(3, 1) != 3) ++bad;
        if (rules::monkHalfDamageOnFailedSaveLevel()
            != 9) ++bad;
        // the ranger surprise numbers
        if (!rules::rangerSurpriseOnD6(1)) ++bad;
        if (!rules::rangerSurpriseOnD6(3)) ++bad;
        if (rules::rangerSurpriseOnD6(4)) ++bad;
        if (rules::rangerSurpriseOnD6(0)) ++bad;
        if (rules::rangerSurpriseOnD6(7)) ++bad;
        if (!rules::rangerSurprisedOnD6(1)) ++bad;
        if (rules::rangerSurprisedOnD6(2)) ++bad;
        if (rules::rangerSurprisedOnD6(0)) ++bad;
        // the paladin turn ladder: cleric of
        // level minus two, from 3rd
        if (rules::paladinTurnClericLevel(2) != 0) ++bad;
        if (rules::paladinTurnClericLevel(3) != 1) ++bad;
        if (rules::paladinTurnClericLevel(4) != 2) ++bad;
        if (rules::paladinTurnClericLevel(5) != 3) ++bad;
        if (rules::paladinTurnClericLevel(11) != 9) ++bad;
        if (rules::paladinTurnClericLevel(0) != 0) ++bad;
        printf("R187 per-subclass specials audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R188: the prime requisite XP adjustment audit ----
    // Every printed gate, positive and negative, and the
    // worked-example rounding ladder.
    {
        int bad = 0;
        // the base-class gates at the 16 boundary
        if (!rules::xpBonusQualifiesBase(
                rules::CLASS_FIGHTER, 16, 10, 10, 10)) ++bad;
        if (!rules::xpBonusQualifiesBase(
                rules::CLASS_MAGIC_USER, 10, 16, 10, 10)) ++bad;
        if (!rules::xpBonusQualifiesBase(
                rules::CLASS_CLERIC, 10, 10, 16, 10)) ++bad;
        if (!rules::xpBonusQualifiesBase(
                rules::CLASS_THIEF, 10, 10, 10, 16)) ++bad;
        // the negative probes at 15 (the gate score fails)
        if (rules::xpBonusQualifiesBase(
                rules::CLASS_FIGHTER, 15, 18, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesBase(
                rules::CLASS_MAGIC_USER, 18, 15, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesBase(
                rules::CLASS_CLERIC, 18, 18, 15, 18)) ++bad;
        if (rules::xpBonusQualifiesBase(
                rules::CLASS_THIEF, 18, 18, 18, 15)) ++bad;
        // the pct wrappers
        if (rules::baseXpBonusPct(
                rules::CLASS_FIGHTER, 16, 10, 10, 10) != 10) ++bad;
        if (rules::baseXpBonusPct(
                rules::CLASS_FIGHTER, 15, 10, 10, 10) != 0) ++bad;
        // out-of-range base indices
        if (rules::xpBonusQualifiesBase(
                7, 18, 18, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesBase(
                -1, 18, 18, 18, 18)) ++bad;
        // the subclass gates at the 16 boundary
        if (!rules::xpBonusQualifiesSubclass(
                rules::SUB_PALADIN, 16, 10, 16, 10)) ++bad;
        if (!rules::xpBonusQualifiesSubclass(
                rules::SUB_RANGER, 16, 16, 16, 10)) ++bad;
        if (!rules::xpBonusQualifiesSubclass(
                rules::SUB_DRUID, 10, 10, 16, 16)) ++bad;
        // the paladin negative probes: STR or WIS at 15
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_PALADIN, 15, 10, 18, 10)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_PALADIN, 18, 10, 15, 10)) ++bad;
        // the ranger negative probes: any of the three at 15
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_RANGER, 15, 16, 16, 10)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_RANGER, 16, 15, 16, 10)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_RANGER, 16, 16, 15, 10)) ++bad;
        // the druid negative probes: WIS or CHA at 15
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_DRUID, 10, 10, 15, 18)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_DRUID, 10, 10, 18, 15)) ++bad;
        // the never-classes, even at 18 in every score
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_ILLUSIONIST, 18, 18, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_ASSASSIN, 18, 18, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                rules::SUB_MONK, 18, 18, 18, 18)) ++bad;
        // the pct wrapper and out-of-range indices
        if (rules::subclassXpBonusPct(
                rules::SUB_RANGER, 16, 16, 16, 10) != 10) ++bad;
        if (rules::subclassXpBonusPct(
                rules::SUB_MONK, 18, 18, 18, 18) != 0) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                6, 18, 18, 18, 18)) ++bad;
        if (rules::xpBonusQualifiesSubclass(
                99, 18, 18, 18, 18)) ++bad;
        // the rounding ladder: the printed worked
        // example and the edges
        if (rules::xpBonusAmount(975) != 98) ++bad;
        if (rules::xpBonusTotal(975) != 1073) ++bad;
        if (rules::xpBonusAmount(974) != 98) ++bad;
        if (rules::xpBonusAmount(976) != 98) ++bad;
        if (rules::xpBonusAmount(0) != 0) ++bad;
        if (rules::xpBonusAmount(1) != 1) ++bad;
        if (rules::xpBonusAmount(10) != 1) ++bad;
        if (rules::xpBonusAmount(11) != 2) ++bad;
        if (rules::xpBonusAmount(100) != 10) ++bad;
        if (rules::xpBonusAmount(9750) != 975) ++bad;
        if (rules::xpBonusAmount(-50) != 0) ++bad;
        if (rules::xpBonusTotal(0) != 0) ++bad;
        printf("R188 prime requisite XP adjustment audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R189: the weapon tables verify audit ----
    // All 50 weight/damage rows, the speed cross-verify
    // against the R158 ladder, and the printed notes.
    {
        int bad = 0;
        // the weight/damage chart, row by row (50 cells
        // x weight, S/M min/max, L min/max)
        if (rules::weaponChartRowCount() != 50) ++bad;
        static const int kWeight[50] = {
            2,
            75,
            50,
            125,
            100,
            150,
            15,
            30,
            10,
            5,
            60,
            80,
            150,
            35,
            75,
            75,
            100,
            80,
            150,
            175,
            150,
            50,
            20,
            40,
            50,
            100,
            150,
            100,
            50,
            125,
            80,
            60,
            40,
            80,
            1,
            2,
            50,
            40,
            2,
            1,
            40,
            50,
            50,
            100,
            75,
            60,
            35,
            250,
            50,
            125,
        };
        static const int kSM[50][2] = {
            { 1, 6 },
            { 1, 8 },
            { 1, 6 },
            { 2, 8 },
            { 1, 8 },
            { 2, 8 },
            { 1, 6 },
            { 1, 6 },
            { 1, 4 },
            { 1, 3 },
            { 1, 6 },
            { 1, 8 },
            { 2, 7 },
            { 2, 5 },
            { 1, 8 },
            { 1, 6 },
            { 2, 8 },
            { 2, 8 },
            { 2, 8 },
            { 1, 10 },
            { 2, 8 },
            { 2, 5 },
            { 1, 6 },
            { 1, 6 },
            { 1, 6 },
            { 2, 7 },
            { 3, 9 },
            { 2, 7 },
            { 1, 6 },
            { 2, 8 },
            { 1, 6 },
            { 2, 7 },
            { 2, 5 },
            { 1, 6 },
            { 1, 4 },
            { 2, 5 },
            { 2, 8 },
            { 1, 8 },
            { 2, 5 },
            { 1, 4 },
            { 1, 6 },
            { 2, 7 },
            { 1, 6 },
            { 2, 8 },
            { 2, 8 },
            { 1, 8 },
            { 1, 6 },
            { 1, 10 },
            { 2, 7 },
            { 2, 8 },
        };
        static const int kL[50][2] = {
            { 1, 6 },
            { 1, 8 },
            { 1, 4 },
            { 3, 12 },
            { 1, 6 },
            { 1, 10 },
            { 1, 3 },
            { 1, 3 },
            { 1, 3 },
            { 1, 2 },
            { 1, 8 },
            { 1, 10 },
            { 2, 8 },
            { 2, 5 },
            { 2, 8 },
            { 1, 10 },
            { 2, 12 },
            { 1, 8 },
            { 2, 8 },
            { 2, 12 },
            { 1, 6 },
            { 1, 4 },
            { 1, 6 },
            { 1, 4 },
            { 1, 8 },
            { 2, 12 },
            { 3, 18 },
            { 1, 6 },
            { 1, 4 },
            { 2, 7 },
            { 2, 7 },
            { 2, 8 },
            { 1, 4 },
            { 1, 12 },
            { 1, 4 },
            { 2, 7 },
            { 2, 8 },
            { 1, 8 },
            { 2, 7 },
            { 1, 4 },
            { 1, 8 },
            { 2, 12 },
            { 1, 6 },
            { 2, 16 },
            { 2, 7 },
            { 1, 12 },
            { 1, 8 },
            { 3, 18 },
            { 3, 12 },
            { 2, 8 },
        };
        for (int i = 0; i < 50; ++i) {
            if (rules::weaponChartWeight(i) != kWeight[i]) ++bad;
            if (rules::weaponChartDamageSMMin(i) != kSM[i][0]) ++bad;
            if (rules::weaponChartDamageSMMax(i) != kSM[i][1]) ++bad;
            if (rules::weaponChartDamageLMin(i) != kL[i][0]) ++bad;
            if (rules::weaponChartDamageLMax(i) != kL[i][1]) ++bad;
        }
        // the name ladder, head and tail
        if (std::string(rules::weaponChartName(0))
            != "arrow") ++bad;
        if (std::string(rules::weaponChartName(49))
            != "voulge") ++bad;
        if (std::string(rules::weaponChartName(40))
            != "spear") ++bad;
        // spot rows against the print
        if (rules::weaponChartWeight(1) != 75) ++bad;
        if (rules::weaponChartDamageSMMin(1) != 1
            || rules::weaponChartDamageSMMax(1) != 8) ++bad;
        if (rules::weaponChartDamageLMin(26) != 3
            || rules::weaponChartDamageLMax(26) != 18) ++bad;
        if (rules::weaponChartWeight(47) != 250) ++bad;
        if (rules::weaponChartDamageLMin(47) != 3
            || rules::weaponChartDamageLMax(47) != 18) ++bad;
        if (rules::weaponChartDamageSMMin(43) != 2
            || rules::weaponChartDamageSMMax(43) != 8) ++bad;
        if (rules::weaponChartDamageLMin(43) != 2
            || rules::weaponChartDamageLMax(43) != 16) ++bad;
        // the clamps: index out of range reads the edges
        if (rules::weaponChartWeight(-5) != 2) ++bad;
        if (rules::weaponChartWeight(99) != 125) ++bad;
        if (std::string(rules::weaponChartName(-1))
            != "arrow") ++bad;
        // the spear weight spread: the print 40-60
        {
            int lo = 0, hi = 0;
            rules::spearWeightRange(lo, hi);
            if (lo != 40 || hi != 60) ++bad;
            if (rules::weaponChartWeight(40) != 40) ++bad;
        }
        // the speed cross-verify: every verified pair
        // matches the R158 engine ladder value
        if (rules::weaponSpeedVerifiedCount() != 18) ++bad;
        for (int i = 0; i < 18; ++i) {
            const char* n = rules::weaponSpeedVerifiedName(i);
            int printed = rules::weaponSpeedVerifiedFactor(i);
            int engine = rules::weaponSpeedFactor(n);
            if (engine != printed) ++bad;
        }
        // the spear default 7 sits inside the printed 6-8
        {
            int lo = 0, hi = 0;
            rules::spearSpeedFactorRange(lo, hi);
            if (lo != 6 || hi != 8) ++bad;
            if (rules::weaponSpeedFactor("spear") != 7) ++bad;
        }
        // the horseman flail: OCR-mangled cell, the engine
        // 6 stays recorded convention
        if (rules::weaponSpeedFactor("horseman flail") != 6) ++bad;
        // unknown weapons read 0 (the caller decides)
        if (rules::weaponSpeedFactor("vorpal blade") != 0) ++bad;
        // the printed notes: the lances double from a
        // charging mount, rows 24-26 only
        if (!rules::lanceChargingDouble(24)) ++bad;
        if (!rules::lanceChargingDouble(25)) ++bad;
        if (!rules::lanceChargingDouble(26)) ++bad;
        if (rules::lanceChargingDouble(23)) ++bad;
        if (rules::lanceChargingDouble(27)) ++bad;
        if (!rules::spearSetChargingDouble()) ++bad;
        // the chart-2 combat note
        if (rules::weaponBackOrUnseenBonus() != 2) ++bad;
        if (rules::weaponStunnedProneMotionlessBonus()
            != 4) ++bad;
        printf("R189 weapon tables verify audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R190: the starting money audit ----
    // All five printed rows, the clamps, the
    // monk no-x10 finding, the support ladder.
    {
        int bad = 0;
        // the four class rows, cell by cell
        // (fighter 5d4x10, magic-user 2d4x10,
        // cleric 3d6x10, thief 2d6x10)
        static const int kCnt[4] = { 5, 2, 3, 2 };
        static const int kFace[4] = { 4, 4, 6, 6 };
        static const int kMult[4] = { 10, 10, 10, 10 };
        static const int kMin[4] = { 50, 20, 30, 20 };
        static const int kMax[4] = { 200, 80, 180, 120 };
        for (int c = 0; c < 4; ++c) {
            if (rules::startingMoneyDiceCount(c) != kCnt[c]) ++bad;
            if (rules::startingMoneyDieFaces(c) != kFace[c]) ++bad;
            if (rules::startingMoneyMultiplier(c) != kMult[c]) ++bad;
            if (rules::startingMoneyMin(c) != kMin[c]) ++bad;
            if (rules::startingMoneyMax(c) != kMax[c]) ++bad;
        }
        // the clamps: out-of-range reads the edges
        if (rules::startingMoneyDiceCount(-5) != 5) ++bad;
        if (rules::startingMoneyMax(-5) != 200) ++bad;
        if (rules::startingMoneyDiceCount(99) != 2) ++bad;
        if (rules::startingMoneyMax(99) != 120) ++bad;
        // the monk row: the print 5-20 gp (5d4)
        // with NO x10 - the one un-multiplied row
        if (rules::monkStartingMoneyDiceCount() != 5) ++bad;
        if (rules::monkStartingMoneyDieFaces() != 4) ++bad;
        if (rules::monkStartingMoneyMultiplier() != 1) ++bad;
        if (rules::monkStartingMoneyMin() != 5) ++bad;
        if (rules::monkStartingMoneyMax() != 20) ++bad;
        // the DMG companion: not less than 100 gp
        // per level per month
        if (rules::pcMonthlySupportCost(1) != 100) ++bad;
        if (rules::pcMonthlySupportCost(5) != 500) ++bad;
        if (rules::pcMonthlySupportCost(12) != 1200) ++bad;
        // the level clamp: 0 reads the 1st
        if (rules::pcMonthlySupportCost(0) != 100) ++bad;
        printf("R190 starting money audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R191: the armor class ratings audit ----
    // The engine armor rows against the printed ARMOR
    // CLASS TABLE, the effectiveAc composites, the
    // new ratings ladder.
    {
        int bad = 0;
        // the printed ladder rows (the shield
        // composites are base - 1)
        if (rules::armorRatingRowCount() != 11) ++bad;
        static const int kLad[11] = {
            10, 9, 8, 8, 7, 7, 6, 5, 4, 4, 3
        };
        for (int i = 0; i < 11; ++i) {
            if (rules::armorRatingAc(i) != kLad[i]) ++bad;
        }
        if (std::string(rules::armorRatingName(0))
            != "none") ++bad;
        if (std::string(rules::armorRatingName(10))
            != "plate mail") ++bad;
        if (rules::armorRatingShieldStep() != 1) ++bad;
        // the engine armor rows vs the print:
        // none 10, padded 8, leather 8, studded 7,
        // ring 7, scale 6, chain 5, splinted 4,
        // banded 4, plate 3 (the none row repinned
        // R191: was 9)
        static const int kBase[10] = {
            10, 8, 8, 7, 7, 6, 5, 4, 4, 3
        };
        for (int i = 0; i < 10; ++i) {
            if (items::armor((items::ArmorId)i).baseAc
                != kBase[i]) ++bad;
        }
        // the effectiveAc composites:
        items::ArmorInstance ar{};
        // unarmored, DEX 10: the printed 10
        ar.id = items::ARMOR_NONE_EQUIPPED;
        if (items::effectiveAc(ar, false, 0, 10) != 10) ++bad;
        // shield only: the printed 9
        if (items::effectiveAc(ar, true, 0, 10) != 9) ++bad;
        // leather: the printed 8; with shield 7
        ar.id = items::ARMOR_LEATHER;
        if (items::effectiveAc(ar, false, 0, 10) != 8) ++bad;
        if (items::effectiveAc(ar, true, 0, 10) != 7) ++bad;
        // plate mail + shield, DEX 10: the printed 2
        ar.id = items::ARMOR_PLATE;
        if (items::effectiveAc(ar, true, 0, 10) != 2) ++bad;
        // the DEX worked example (the ability text):
        // plate + shield normally AC 2; DEX 3 -> 6;
        // DEX 18 -> -2
        if (items::effectiveAc(ar, true, 0, 3) != 6) ++bad;
        if (items::effectiveAc(ar, true, 0, 18) != -2) ++bad;
        // the magic-shield example: unarmored with
        // a +1 shield is AC 8, +2 shield AC 7
        ar.id = items::ARMOR_NONE_EQUIPPED;
        if (items::effectiveAc(ar, true, 1, 10) != 8) ++bad;
        if (items::effectiveAc(ar, true, 2, 10) != 7) ++bad;
        // the magic plate example: plate +3 armor,
        // +5 shield -> AC -6 (3 - 3 - 1 - 5)
        ar.id = items::ARMOR_PLATE;
        ar.plus = 3;
        if (items::effectiveAc(ar, true, 5, 10) != -6) ++bad;
        ar.plus = 0;
        // the magic rule: each +1 lowers AC 1 and
        // converts to 5% hit likelihood
        if (rules::armorRatingMagicAc(1) != 1) ++bad;
        if (rules::armorRatingMagicAc(3) != 3) ++bad;
        if (rules::armorRatingMagicHitPct(1) != 5) ++bad;
        if (rules::armorRatingMagicHitPct(2) != 10) ++bad;
        if (rules::armorRatingMagicAc(-2) != 0) ++bad;
        // the printed notes
        if (!rules::armorRatingShieldNegatedFlankRear()) ++bad;
        if (!rules::armorRatingMagicWeightless()) ++bad;
        printf("R191 armor class ratings audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R192: the wisdom tables audit ----
    // Wisdom Tables I and II cell for cell, the
    // gates, the wiring composites, a seeded roll.
    {
        int bad = 0;
        // Wisdom Table I: the magical attack ladder
        static const int kAdj[16] = {
            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
             1,  2,  3,  4
        };
        for (int w = 3; w <= 18; ++w) {
            if (rules::wisMagicalAttackAdj((uint8_t)w)
                != kAdj[w - 3]) ++bad;
        }
        // the clamps read the edge rows
        if (rules::wisMagicalAttackAdj(0) != -3) ++bad;
        if (rules::wisMagicalAttackAdj(99) != 4) ++bad;
        // the Table I high-circle gates
        if (rules::wisSpellLevelMin(6) != 17) ++bad;
        if (rules::wisSpellLevelMin(7) != 18) ++bad;
        if (rules::wisSpellLevelMin(5) != 0) ++bad;
        if (rules::wisSpellLevelMin(1) != 0) ++bad;
        // Wisdom Table II: the bonus ladder (rows 9-18,
        // spell levels 1-4)
        static const int kBon[10][4] = {
            { 0, 0, 0, 0 },   // 9
            { 0, 0, 0, 0 },   // 10
            { 0, 0, 0, 0 },   // 11
            { 0, 0, 0, 0 },   // 12
            { 1, 0, 0, 0 },   // 13
            { 2, 0, 0, 0 },   // 14
            { 2, 1, 0, 0 },   // 15
            { 2, 2, 0, 0 },   // 16
            { 2, 2, 1, 0 },   // 17
            { 2, 2, 1, 1 }    // 18
        };
        for (int w = 9; w <= 18; ++w) {
            for (int sl = 1; sl <= 4; ++sl) {
                if (rules::wisBonusSpells((uint8_t)w, sl)
                    != kBon[w - 9][sl - 1]) ++bad;
            }
        }
        // out-of-range spell levels read 0; wis clamps
        if (rules::wisBonusSpells(18, 5) != 0) ++bad;
        if (rules::wisBonusSpells(18, 0) != 0) ++bad;
        if (rules::wisBonusSpells(8, 1) != 0) ++bad;
        if (rules::wisBonusSpells(25, 1) != 2) ++bad;
        // the failure ladder
        static const int kFail[10] = {
            20, 15, 10, 5, 0, 0, 0, 0, 0, 0
        };
        for (int w = 9; w <= 18; ++w) {
            if (rules::wisSpellFailurePct((uint8_t)w)
                != kFail[w - 9]) ++bad;
        }
        if (rules::wisSpellFailurePct(3) != 20) ++bad;
        if (rules::wisSpellFailurePct(25) != 0) ++bad;
        // the wiring: cleric slots with wisdom
        // (L1 base 1 + wis-13 bonus 1 = 2)
        if (spells::clericSpellSlotsWithWis(1, 1, 13) != 2) ++bad;
        // wis 9: no bonus, no failure escape
        if (spells::clericSpellSlotsWithWis(1, 1, 9) != 1) ++bad;
        // L3 2nd base 1 + wis-15 bonus 1 = 2
        if (spells::clericSpellSlotsWithWis(3, 2, 15) != 2) ++bad;
        // L2 2nd base 0: the bonus is NOT granted (the
        // printed entitlement note)
        if (spells::clericSpellSlotsWithWis(2, 2, 18) != 0) ++bad;
        // L12 1st base 6 + wis-18 bonus 2 = 8
        if (spells::clericSpellSlotsWithWis(12, 1, 18) != 8) ++bad;
        // the high-circle gates: L11 6th is 1 in the
        // table, but wis 16 fails the Wis-17 gate
        if (spells::clericSpellSlotsWithWis(11, 6, 16) != 0) ++bad;
        if (spells::clericSpellSlotsWithWis(11, 6, 17) != 1) ++bad;
        // L16 7th is 1 in the table (the printed ** row),
        // wis 17 fails the Wis-18 gate, wis 18 reads it
        if (spells::clericSpellSlotsWithWis(16, 7, 17) != 0) ++bad;
        if (spells::clericSpellSlotsWithWis(16, 7, 18) != 1) ++bad;
        // the failure roll, seeded: equal-or-less fails
        {
            rules::Rng r192(2026);
            rules::Dice d(r192);
            int first = (int)d.d100();
            rules::Rng r192b(2026);
            rules::Dice db(r192b);
            bool failed = spells::rollClericSpellFailure(db, 12);
            if (failed != (first <= 5)) ++bad;
            // wis 13+: pct 0, never fails, no roll
            rules::Rng r192c(2026);
            rules::Dice dc(r192c);
            if (spells::rollClericSpellFailure(dc, 13)) ++bad;
        }
        printf("R192 wisdom tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R193: the charisma table audit ----
    // The printed CHARISMA TABLE, all three columns,
    // all 16 scores - the reaction percent ladder,
    // the henchmen column, the loyalty percents.
    {
        int bad = 0;
        // the reaction adjustment: the printed percent
        // ladder (-25 at 3 through +35 at 18)
        static const int kReact[16] = {
            -25, -20, -15, -10, -5,
              0,   0,   0,   0,   0,
              5,  10,  15,  25,  30,  35
        };
        static const int kHench[16] = {
             1,  1,  2,  2,  3,  3,  4,  4,
             4,  5,  5,  6,  7,  8, 10, 15
        };
        static const int kLoyal[16] = {
            -30, -25, -20, -15, -10, -5,
             0,   0,   0,   0,   0,
             5,  15,  20,  30,  40
        };
        for (int c = 3; c <= 18; ++c) {
            if (rules::chaReactionAdj((uint8_t)c)
                != kReact[c - 3]) ++bad;
            if (rules::chaHenchmenMax((uint8_t)c)
                != kHench[c - 3]) ++bad;
            if (rules::chaLoyaltyBase((uint8_t)c)
                != kLoyal[c - 3]) ++bad;
        }
        // the cha 18 tail cells
        if (rules::chaReactionAdj(18) != 35) ++bad;
        if (rules::chaHenchmenMax(18) != 15) ++bad;
        if (rules::chaLoyaltyBase(18) != 40) ++bad;
        // the two historically divergent henchmen cells:
        // cha 4 reads 1, cha 12 reads 5 (the R177 founding read)
        if (rules::chaHenchmenMax(4) != 1) ++bad;
        if (rules::chaHenchmenMax(12) != 5) ++bad;
        // the clamps read the edge rows
        if (rules::chaReactionAdj(0) != -25) ++bad;
        if (rules::chaReactionAdj(99) != 35) ++bad;
        if (rules::chaHenchmenMax(0) != 1) ++bad;
        if (rules::chaHenchmenMax(99) != 15) ++bad;
        if (rules::chaLoyaltyBase(0) != -30) ++bad;
        if (rules::chaLoyaltyBase(99) != 40) ++bad;
        // the reaction bands consume the percent scale:
        // a cha-18 leader adds +35 to the d100 reaction
        // roll, a cha-3 leader -25
        if (rules::chaReactionAdj(18) + 50 != 85) ++bad;
        if (rules::chaReactionAdj(3) + 50 != 25) ++bad;
        printf("R193 charisma table audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R194: the wisdom magical defense repin audit ----
    // The printed Wisdom Table I ladder, cell for cell, and
    // the delegation agreement with the R192 header pin.
    {
        int bad = 0;
        // the printed ladder (3 through 18):
        // -3, -2, -1, -1, -1, then none through 14,
        // then +1 +2 +3 +4
        static const int kAdj[16] = {
            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
             1,  2,  3,  4
        };
        for (int w = 3; w <= 18; ++w) {
            if (rules::wisMagDefAdj((uint8_t)w)
                != kAdj[w - 3]) ++bad;
        }
        // the delegation: wisMagDefAdj and the R192 header
        // accessor read the same ladder at every score
        for (int w = 0; w <= 25; ++w) {
            if (rules::wisMagDefAdj((uint8_t)w)
                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;
        }
        // the clamps read the edge rows
        if (rules::wisMagDefAdj(0) != -3) ++bad;
        if (rules::wisMagDefAdj(99) != 4) ++bad;
        // the historically divergent cells (the R177 read:
        // the engine convention capped at -2/+2)
        if (rules::wisMagDefAdj(3) != -3) ++bad;
        if (rules::wisMagDefAdj(17) != 3) ++bad;
        if (rules::wisMagDefAdj(18) != 4) ++bad;
        printf("R194 wisdom defense repin audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R195: the INT languages repin audit ----
    // The printed INTELLIGENCE TABLE I additional-
    // languages column, cell for cell.
    {
        int bad = 0;
        // the printed column (3 through 18):
        // none through 7, then one per two scores
        // up to seven at 18
        static const int kLang[16] = {
            0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
            4, 4, 5, 6, 7
        };
        for (int i = 3; i <= 18; ++i) {
            if (rules::intExtraLanguages((uint8_t)i)
                != kLang[i - 3]) ++bad;
        }
        // the clamps read the edge rows
        if (rules::intExtraLanguages(0) != 0) ++bad;
        if (rules::intExtraLanguages(99) != 7) ++bad;
        // the historically divergent cells, the R177 read:
        // the engine convention gave a language at 4-5
        if (rules::intExtraLanguages(4) != 0) ++bad;
        if (rules::intExtraLanguages(6) != 0) ++bad;
        if (rules::intExtraLanguages(9) != 1) ++bad;
        if (rules::intExtraLanguages(17) != 6) ++bad;
        if (rules::intExtraLanguages(18) != 7) ++bad;
        printf("R195 INT languages repin audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R196: the INT Table II audit ----
    // The printed INTELLIGENCE TABLE II: the chance-to-know
    // percents and the min/max spells-per-level columns,
    // cell for cell.
    {
        int bad = 0;
        // the chance-to-know percents (9 through 19+)
        static const int kPct[11] = {
             0, 35, 45, 45, 45, 55, 55, 65, 65, 75,
            85
        };
        // probes at 9-18, then the 19+ row
        for (int i = 9; i <= 18; ++i) {
            if (spells::chanceToLearnPct((uint8_t)i)
                != kPct[i - 8]) ++bad;
        }
        if (spells::chanceToLearnPct(19) != 95) ++bad;
        if (spells::chanceToLearnPct(25) != 95) ++bad;
        if (spells::chanceToLearnPct(8) != 0) ++bad;
        // the historically divergent cells (the R196 find):
        // 10 read 35, 16 read 70, 17 read 85, 18 read 95
        if (spells::chanceToLearnPct(10) != 45) ++bad;
        if (spells::chanceToLearnPct(16) != 65) ++bad;
        if (spells::chanceToLearnPct(17) != 75) ++bad;
        if (spells::chanceToLearnPct(18) != 85) ++bad;
        // the min spells-per-level column
        static const int kMin[11] = {
             0, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9
        };
        for (int i = 9; i <= 18; ++i) {
            if (spells::minSpellsPerLevel((uint8_t)i)
                != kMin[i - 8]) ++bad;
        }
        if (spells::minSpellsPerLevel(19) != 10) ++bad;
        if (spells::minSpellsPerLevel(8) != 0) ++bad;
        // the max spells-per-level column
        static const int kMax[11] = {
             0, 6, 7, 7, 7, 9, 9, 11, 11, 14, 18
        };
        for (int i = 9; i <= 18; ++i) {
            if (spells::maxSpellsPerLevel((uint8_t)i)
                != kMax[i - 8]) ++bad;
        }
        // the 19+ row: 10 / All (unlimited = -1)
        if (spells::minSpellsPerLevel(19) != 10) ++bad;
        if (spells::maxSpellsPerLevel(19) != -1) ++bad;
        if (spells::maxSpellsPerLevel(25) != -1) ++bad;
        // the band shape: min <= max at every score
        for (int i = 9; i <= 25; ++i) {
            int lo = spells::minSpellsPerLevel((uint8_t)i);
            int hi = spells::maxSpellsPerLevel((uint8_t)i);
            if (hi >= 0 && lo > hi) ++bad;   // R196c: -1 is unlimited
        }
        printf("R196 INT table II audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R197: the mental-form flag audit ----
    // The printed Wisdom Table I note: the magical defense
    // adjustment rides only will-force forms. The registry
    // holds two: charm person (charming) and charm monster
    // (mass charming). The holds are not will-force forms.
    {
        int bad = 0;
        // the flagged rows
        if (!spells::spellIsMentalForm(spells::MU_CHARM_PERSON))
            ++bad;
        if (!spells::spellIsMentalForm(spells::MU_CHARM_MONSTER))
            ++bad;
        // the unflagged rows: holds are not will-force forms,
        // and the physical/utility spells are not either
        if (spells::spellIsMentalForm(spells::MU_HOLD_MONSTER)) ++bad;
        if (spells::spellIsMentalForm(spells::CL_HOLD_PERSON)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_SLEEP)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_FIREBALL)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_MAGIC_MISSILE)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_POLYMORPH_OTHER))
            ++bad;
        if (spells::spellIsMentalForm(spells::CL_SILENCE_15)) ++bad;
        // the assembly: the ladder on mental forms
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 18) != 4)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 3) != -3)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 10) != 0)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_MONSTER, 17) != 3)
            ++bad;
        // and 0 off them, whatever the wisdom
        if (spells::spellSaveModWis(spells::MU_FIREBALL, 3) != 0)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_MAGIC_MISSILE, 18) != 0)
            ++bad;
        // the ladder handoff: the helper IS wisMagicalAttackAdj
        for (int w = 3; w <= 18; ++w) {
            if (spells::spellSaveModWis(
                    spells::MU_CHARM_PERSON, (uint8_t)w)
                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;
        }
        printf("R197 mental-form flag audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R198: the class weapon allowlists audit ----
    // The CHARACTER CLASSES TABLE II weapons column, cell
    // for cell: the any-weapon rows, the limited lists, the
    // family expansions, the thief sword footnote, the monk
    // pole-arm family and the crossbow.
    {
        int bad = 0;
        // the any-weapon rows
        if (!rules::classUsesAnyWeapon(2)) ++bad;   // fighter
        if (!rules::classUsesAnyWeapon(3)) ++bad;   // paladin
        if (!rules::classUsesAnyWeapon(4)) ++bad;   // ranger
        if (!rules::classUsesAnyWeapon(8)) ++bad;   // assassin
        if (rules::classUsesAnyWeapon(0)) ++bad;    // cleric
        if (rules::classUsesAnyWeapon(1)) ++bad;    // druid
        if (rules::classUsesAnyWeapon(5)) ++bad;    // MU
        if (rules::classUsesAnyWeapon(6)) ++bad;    // illusionist
        if (rules::classUsesAnyWeapon(7)) ++bad;    // thief
        if (rules::classUsesAnyWeapon(9)) ++bad;    // monk
        // the counts
        static const int kCount[10] = {
             7,  9, -1, -1, -1,  3,  3,  8, -1, 24
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classAllowedWeaponCount(c)
                != kCount[c]) ++bad;
        }
        // the monk list, the ten printed weapons
        if (!rules::weaponAllowedForClass(9, "bo stick")) ++bad;
        if (!rules::weaponAllowedForClass(9, "club")) ++bad;
        if (!rules::weaponAllowedForClass(9, "crossbow")) ++bad;
        if (!rules::weaponAllowedForClass(9, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(9, "hand axe")) ++bad;
        if (!rules::weaponAllowedForClass(9, "javelin")) ++bad;
        if (!rules::weaponAllowedForClass(9, "jo stick")) ++bad;
        if (!rules::weaponAllowedForClass(9, "spear")) ++bad;
        if (!rules::weaponAllowedForClass(9, "quarterstaff"))
            ++bad;
        // the monk pole-arm family, all 15 rows
        static const char* const kPoleArm[15] = {
            "bardiche", "bec de corbin", "bill-guisarme",
            "fauchard", "fauchard-fork", "military fork",
            "glaive", "glaive-guisarme", "guisarme",
            "guisarme-voulge", "halberd", "partisan",
            "ransseur", "spetum", "voulge"
        };
        for (int i = 0; i < 15; ++i) {
            if (!rules::weaponAllowedForClass(9, kPoleArm[i]))
                ++bad;
            // the family is the monk print - not the MU or thief
            if (rules::weaponAllowedForClass(5, kPoleArm[i]))
                ++bad;
            if (rules::weaponAllowedForClass(7, kPoleArm[i]))
                ++bad;
        }
        // what the monk denies
        if (rules::weaponAllowedForClass(9, "battle axe")) ++bad;
        if (rules::weaponAllowedForClass(9, "long sword")) ++bad;
        if (rules::weaponAllowedForClass(9, "morning star")) ++bad;
        // the cleric list, the family expansions
        if (!rules::weaponAllowedForClass(0, "club")) ++bad;
        if (!rules::weaponAllowedForClass(0, "footman flail"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "horseman flail"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "hammer")) ++bad;
        if (!rules::weaponAllowedForClass(0, "footman mace"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "horseman mace"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "quarterstaff")) ++bad;
        // the cleric denies
        if (rules::weaponAllowedForClass(0, "dagger")) ++bad;
        if (rules::weaponAllowedForClass(0, "short sword")) ++bad;
        if (rules::weaponAllowedForClass(0, "scimitar")) ++bad;
        if (rules::weaponAllowedForClass(0, "lucern hammer")) ++bad;
        // the druid list
        if (!rules::weaponAllowedForClass(1, "scimitar")) ++bad;
        if (!rules::weaponAllowedForClass(1, "spear")) ++bad;
        if (!rules::weaponAllowedForClass(1, "hammer")) ++bad;
        if (!rules::weaponAllowedForClass(1, "sling bullet"))
            ++bad;
        if (!rules::weaponAllowedForClass(1, "sling stone")) ++bad;
        if (!rules::weaponAllowedForClass(1, "quarterstaff")) ++bad;
        if (rules::weaponAllowedForClass(1, "footman mace")) ++bad;
        if (rules::weaponAllowedForClass(1, "long sword")) ++bad;
        // the MU and illusionist lists
        if (!rules::weaponAllowedForClass(5, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(5, "dart")) ++bad;
        if (!rules::weaponAllowedForClass(5, "quarterstaff"))
            ++bad;
        if (rules::weaponAllowedForClass(5, "club")) ++bad;
        if (rules::weaponAllowedForClass(5, "long sword")) ++bad;
        if (!rules::weaponAllowedForClass(6, "dagger")) ++bad;
        if (rules::weaponAllowedForClass(6, "battle axe")) ++bad;
        // the thief list and the sword footnote
        if (!rules::weaponAllowedForClass(7, "club")) ++bad;
        if (!rules::weaponAllowedForClass(7, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(7, "dart")) ++bad;
        if (!rules::weaponAllowedForClass(7, "sling stone")) ++bad;
        if (!rules::weaponAllowedForClass(7, "short sword")) ++bad;
        if (!rules::weaponAllowedForClass(7, "broad sword")) ++bad;
        if (!rules::weaponAllowedForClass(7, "long sword")) ++bad;
        if (rules::weaponAllowedForClass(7, "bastard sword"))
            ++bad;
        if (rules::weaponAllowedForClass(7, "two-handed sword"))
            ++bad;
        if (rules::weaponAllowedForClass(7, "spear")) ++bad;
        // the crossbow is the monk print alone
        if (rules::weaponAllowedForClass(7, "crossbow")) ++bad;
        if (rules::weaponAllowedForClass(5, "crossbow")) ++bad;
        if (rules::weaponAllowedForClass(0, "crossbow")) ++bad;
        // the any-weapon rows take everything asked
        if (!rules::weaponAllowedForClass(2, "two-handed sword"))
            ++bad;
        if (!rules::weaponAllowedForClass(3, "bastard sword"))
            ++bad;
        if (!rules::weaponAllowedForClass(4, "halberd")) ++bad;
        if (!rules::weaponAllowedForClass(8, "morning star")) ++bad;
        // the list walk agrees with the membership test
        for (int c = 0; c < 10; ++c) {
            int n = rules::classAllowedWeaponCount(c);
            if (n <= 0) continue;
            for (int i = 0; i < n; ++i) {
                if (!rules::weaponAllowedForClass(
                        c, rules::classAllowedWeaponName(c, i)))
                    ++bad;
            }
        }
        printf("R198 class weapon allowlists audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R199: the oil and poison columns audit ----
    // The CHARACTER CLASSES TABLE II oil and poison
    // columns, cell for cell - the three-valued
    // allowance encoding: 1 yes, 0 never, -1 referee.
    {
        int bad = 0;
        // the encoding
        if (rules::classAllowanceYes() != 1) ++bad;
        if (rules::classAllowanceNever() != 0) ++bad;
        if (rules::classAllowanceReferee() != -1) ++bad;
        // the Oil column: yes for every class but the monk
        static const int kOil[10] = {
             1,  1,  1,  1,  1,  1,  1,  1,  1,  0
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classOilUse(c) != kOil[c]) ++bad;
        }
        // the Poison column: cleric and paladin never,
        // assassin yes, the rest the question mark
        static const int kPoison[10] = {
             0, -1, -1,  0, -1, -1, -1, -1,  1, -1
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classPoisonUse(c) != kPoison[c]) ++bad;
        }
        // the cleric footnote: the prohibition is strictly
        // for clerics not of evil alignment - an evil cleric
        // reads the referee discretion
        if (rules::classPoisonUseForAlignment(0, false) != 0) ++bad;
        if (rules::classPoisonUseForAlignment(0, true) != -1) ++bad;
        // the paladin never is unconditional - no footnote
        if (rules::classPoisonUseForAlignment(3, true) != 0) ++bad;
        if (rules::classPoisonUseForAlignment(3, false) != 0) ++bad;
        // the other rows pass through untouched
        if (rules::classPoisonUseForAlignment(8, false) != 1) ++bad;
        if (rules::classPoisonUseForAlignment(9, true) != -1) ++bad;
        printf("R199 oil and poison columns audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R200: the falling-while-climbing ladder audit ----
    // The print rungs: 4th = 20 feet within 1 of a wall,
    // 6th = 30 feet within 4, 13th = any distance within 8.
    {
        int bad = 0;
        // the fall distance ladder: 0 below 4th, 20 at 4th-5th,
        // 30 at 6th-12th (seven levels), -1 at 13th and up
        static const int kFall[17] = {
             0,  0,  0, 20, 20, 30, 30, 30, 30, 30,
            30, 30, -1, -1, -1, -1, -1
        };
        for (int lv = 1; lv <= 17; ++lv) {
            if (rules::monkWallAssistedFallFeet(lv)
                != kFall[lv - 1]) ++bad;
        }
        // the clamps
        if (rules::monkWallAssistedFallFeet(0) != 0) ++bad;
        if (rules::monkWallAssistedFallFeet(99) != -1) ++bad;
        // the proximity ladder: 0 below 4th, 1 at 4th-5th,
        // 4 at 6th-12th (seven levels), 8 at 13th and up
        static const int kProx[17] = {
             0,  0,  0,  1,  1,  4,  4,  4,  4,  4,
             4,  4,  8,  8,  8,  8,  8
        };
        for (int lv = 1; lv <= 17; ++lv) {
            if (rules::monkWallAssistedFallProximityFeet(lv)
                != kProx[lv - 1]) ++bad;
        }
        if (rules::monkWallAssistedFallProximityFeet(0) != 0) ++bad;
        if (rules::monkWallAssistedFallProximityFeet(99) != 8)
            ++bad;
        // the wall-contact rule
        if (!rules::monkWallAssistedFallRequiresContact()) ++bad;
        // the rung boundaries: the three print cells
        if (rules::monkWallAssistedFallFeet(4) != 20)
            ++bad;   // 4th: Disciple, 20 within 1
        if (rules::monkWallAssistedFallProximityFeet(4) != 1) ++bad;
        if (rules::monkWallAssistedFallFeet(6) != 30)
            ++bad;   // 6th: Master, 30 within 4
        if (rules::monkWallAssistedFallProximityFeet(6) != 4) ++bad;
        if (rules::monkWallAssistedFallFeet(13) != -1)
            ++bad;   // 13th: Master of Winter, any within 8
        if (rules::monkWallAssistedFallProximityFeet(13) != 8)
            ++bad;
        printf("R200 falling ladder audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R201: the NPC monk alignment split audit ----
    // The monk prose: NPC monks align 50% lawful good,
    // 35% lawful neutral, 15% lawful evil - the split sums
    // to 100 and the d100 bands tile the die.
    {
        int bad = 0;
        // the three percents
        if (rules::monkNpcAlignLawfulGoodPercent() != 50) ++bad;
        if (rules::monkNpcAlignLawfulNeutralPercent() != 35) ++bad;
        if (rules::monkNpcAlignLawfulEvilPercent() != 15) ++bad;
        // the census sums to 100
        int sum = rules::monkNpcAlignLawfulGoodPercent()
                  + rules::monkNpcAlignLawfulNeutralPercent()
                  + rules::monkNpcAlignLawfulEvilPercent();
        if (sum != 100) ++bad;
        // the d100 bands: contiguous, in order, cover the die
        static const int kLo[3]  = { 1, 51, 86 };
        static const int kHi[3]  = { 50, 85, 100 };
        for (int i = 0; i < 3; ++i) {
            int lo, hi;
            rules::monkNpcAlignRollRange(i, lo, hi);
            if (lo != kLo[i]) ++bad;
            if (hi != kHi[i]) ++bad;
        }
        // the contiguity: each band starts at the prior plus one
        for (int i = 1; i < 3; ++i) {
            int lo, hi, plo, phi;
            rules::monkNpcAlignRollRange(i, lo, hi);
            rules::monkNpcAlignRollRange(i - 1, plo, phi);
            if (lo != phi + 1) ++bad;
            if (lo > hi) ++bad;
        }
        // the bands match the percents: LG 50 wide, LN 35, LE 15
        int lo, hi;
        rules::monkNpcAlignRollRange(0, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulGoodPercent()) ++bad;
        rules::monkNpcAlignRollRange(1, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulNeutralPercent()) ++bad;
        rules::monkNpcAlignRollRange(2, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulEvilPercent()) ++bad;
        // the out-of-range miss band
        rules::monkNpcAlignRollRange(3, lo, hi);
        if (lo != 0 || hi != 100) ++bad;
        printf("R201 NPC monk alignment audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R203: the apparent armor AC audit ----
    // The p.38 column key repin: the row keys the armor
    // worn - base + shield - never the magic/DEX-shifted
    // effective AC. The book: the adjustments are for
    // weapons versus specific types of armor, not
    // necessarily against actual armor class.
    {
        int bad = 0;
        // the apparent armor AC cells: armor base + shield
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_NONE_EQUIPPED;
            if (items::apparentArmorAc(ar, false) != 10) ++bad;
            // the shield column: the book prints shield
            // only as AC 9
            if (items::apparentArmorAc(ar, true) != 9) ++bad;
            ar.id = items::ARMOR_LEATHER;
            if (items::apparentArmorAc(ar, false) != 8) ++bad;
            if (items::apparentArmorAc(ar, true) != 7) ++bad;
            ar.id = items::ARMOR_PLATE;
            if (items::apparentArmorAc(ar, false) != 3) ++bad;
            if (items::apparentArmorAc(ar, true) != 2) ++bad;
        }
        // the enchantment plus does NOT shift the key
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_PLATE;
            ar.plus = 5;
            if (items::apparentArmorAc(ar, false) != 3) ++bad;
        }
        // the contrast: DEX and plus shift the effective AC,
        // never the apparent - a plate +2, shield, DEX 18
        // defender reads effective -4, apparent 2
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_PLATE;
            ar.plus = 2;
            rules::ExceptionalStrength noEx;
            int eff = items::effectiveAc(ar, true, 0, 18);
            int app = items::apparentArmorAc(ar, true);
            if (eff != -4) ++bad;   // the to-hit target
            if (app != 2) ++bad;    // the p.38 row key
            // the dagger row keyed each way: the old fold
            // read column 0 (-4); the repin reads column 2
            // (-3) - the fix, pinned as two exact values
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, eff) != -4) ++bad;
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, app) != -3) ++bad;
            // the composition chain: STR 10 neutral, no
            // enchant, dagger vs the plate-and-shield
            // defender - the row reads the armor, -3
            items::WeaponInstance w;
            w.id = items::WPN_DAGGER;
            if (items::attackAdjustment(w, noEx, 10, app) != -3)
                ++bad;
            // and keyed on the effective AC it would read
            // -4 - the retired approximation, pinned
            if (items::attackAdjustment(w, noEx, 10, eff) != -4)
                ++bad;
        }
        // the shield-only column: dagger vs AC 9 reads +1
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_NONE_EQUIPPED;
            int app = items::apparentArmorAc(ar, true);
            if (app != 9) ++bad;
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, app) != 1) ++bad;
        }
        printf("R203 apparent armor AC audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R204: the item saving throw matrix audit ----
    // DMG p.80 matrix III: all 154 cells (14 materials x
    // 11 attack forms) transcribed, plus the modifiers -
    // the magical ladder, the own-mode +5, the fall surface
    // and distance adjustments, the cold-strike footnote,
    // the normal-fire exposure rounds - and the R157
    // cross-checks: the grenade break saves must equal the
    // matrix cells (ceramic flask 18/12, crystal vial
    // 19/14).
    {
        int bad = 0;
        static const int kCells[14][11] = {
            { 11, 16, 10, 20,  6, 17,  9,  3,  2,  8, 1 },
            {  4, 18, 12, 19, 11,  5,  3,  2,  4,  2, 1 },
            { 12,  6,  3, 20,  2, 20, 16, 13,  1, 18, 1 },
            {  6, 19, 14, 20, 13, 10,  6,  3,  7, 15, 5 },
            {  5, 20, 15, 20, 14, 11,  7,  4,  6, 17, 1 },
            { 10,  4,  2, 20,  1, 13,  6,  4,  3, 13, 1 },
            { 15,  0,  0, 20,  0, 15, 14, 13, 12, 18, 15 },
            {  7,  6,  2, 17,  2,  6,  2,  1,  1,  1, 1 },
            { 13, 14,  9, 19,  4, 18, 13,  5,  1,  6, 1 },
            { 12, 20, 15, 20, 13, 14,  9,  5,  6, 18, 1 },
            { 16, 11,  6, 20,  0, 25, 21, 18,  2, 20, 1 },
            {  3, 17,  7, 18,  4,  7,  3,  2,  1, 14, 2 },
            {  9, 13,  6, 20,  2, 15, 11,  9,  1, 10, 1 },
            {  8, 10,  3, 19,  1, 11,  7,  5,  1, 12, 1 },
        };
        for (int m = 0; m < rules::ISM_COUNT; ++m)
            for (int f = 0; f < rules::ISF_COUNT; ++f)
                if (rules::itemSaveTarget(
                        (rules::ItemSaveMaterial)m,
                        (rules::ItemSaveForm)f)
                        != kCells[m][f]) ++bad;
        // names present for every row and form
        for (int m = 0; m < rules::ISM_COUNT; ++m)
            if (!*rules::itemSaveMaterialName(
                    (rules::ItemSaveMaterial)m)) ++bad;
        for (int f = 0; f < rules::ISF_COUNT; ++f)
            if (!*rules::itemSaveFormName(
                    (rules::ItemSaveForm)f)) ++bad;
        // the R157 cross-checks: the grenade break saves
        // are the matrix BLOW cells - ceramic flasks
        // (acid, oil) the ceramic row, crystal vials (holy
        // or unholy water, poison) the crystal row
        if (rules::itemSaveTarget(rules::ISM_CERAMIC,
                rules::ISF_BLOW_CRUSHING)
                != rules::grenadeBreakSaveCrushing(
                      rules::GREN_ACID)) ++bad;
        if (rules::itemSaveTarget(rules::ISM_CERAMIC,
                rules::ISF_BLOW_NORMAL)
                != rules::grenadeBreakSaveNormal(
                      rules::GREN_OIL)) ++bad;
        if (rules::itemSaveTarget(rules::ISM_CRYSTAL_VIAL,
                rules::ISF_BLOW_CRUSHING)
                != rules::grenadeBreakSaveCrushing(
                      rules::GREN_HOLY_WATER)) ++bad;
        if (rules::itemSaveTarget(rules::ISM_CRYSTAL_VIAL,
                rules::ISF_BLOW_NORMAL)
                != rules::grenadeBreakSaveNormal(
                      rules::GREN_POISON)) ++bad;
        // the liquid row: no save vs blow, fall, normal fire
        if (rules::itemSaveTarget(rules::ISM_LIQUID,
                rules::ISF_BLOW_CRUSHING) != 0) ++bad;
        if (rules::itemSaveTarget(rules::ISM_LIQUID,
                rules::ISF_FALL) != 0) ++bad;
        if (rules::itemSaveTarget(rules::ISM_LIQUID,
                rules::ISF_FIRE_NORMAL) != 13) ++bad;
        // the magical ladder: +1 saves at +2, +2 at +3,
        // +3 at +4, a +5 sword at +6; non-magical 0
        if (rules::itemSaveMagicalBonus(0) != 0 ||
            rules::itemSaveMagicalBonus(1) != 2 ||
            rules::itemSaveMagicalBonus(2) != 3 ||
            rules::itemSaveMagicalBonus(3) != 4 ||
            rules::itemSaveMagicalBonus(5) != 6) ++bad;
        if (rules::itemSaveOwnModeBonus() != 5) ++bad;
        // the fall surfaces: hard 0, wood-like +1, fleshy +5
        if (rules::itemSaveFallSurfaceAdj(
                rules::ISFS_HARD) != 0 ||
            rules::itemSaveFallSurfaceAdj(
                rules::ISFS_WOODLIKE) != 1 ||
            rules::itemSaveFallSurfaceAdj(
                rules::ISFS_FLESHY) != 5) ++bad;
        // the fall distance: through 5 feet free, each 5
        // past the first costs 1
        if (rules::itemSaveFallDistanceAdj(5) != 0 ||
            rules::itemSaveFallDistanceAdj(9) != 0 ||
            rules::itemSaveFallDistanceAdj(10) != -1 ||
            rules::itemSaveFallDistanceAdj(25) != -4 ||
            rules::itemSaveFallDistanceAdj(100) != -19) ++bad;
        // the cold-strike footnote: -10 on the die
        if (rules::itemSaveHardMetalColdStrikePenalty() != 10)
            ++bad;
        // normal-fire exposure: parchment 1, cloth 2, bone 3;
        // the unprinted tail reads 0 (caller-side)
        if (rules::itemSaveNormalFireRoundsToAffect(
                rules::ISM_PARCHMENT_PAPER) != 1 ||
            rules::itemSaveNormalFireRoundsToAffect(
                rules::ISM_CLOTH) != 2 ||
            rules::itemSaveNormalFireRoundsToAffect(
                rules::ISM_BONE_IVORY) != 3 ||
            rules::itemSaveNormalFireRoundsToAffect(
                rules::ISM_GLASS) != 0) ++bad;
        // the save convention: SAVES on roll + adj >= target
        if (!rules::itemSavesOn(17, 18, 2)) ++bad;
        if (rules::itemSavesOn(15, 18, 2)) ++bad;
        if (!rules::itemSavesOn(18, 18, 0)) ++bad;
        if (rules::itemSavesOn(17, 18, 0)) ++bad;
        printf("R204 item saving throw matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R205: the spying tables audit ----
    // DMG pp.19-20: the success table (spy level
    // 1-17 x the three categories), the mission
    // days, the discovery formula with the
    // precaution tiers, the failure bands with
    // the modifiers, the torture outcomes and
    // the fanatical rule.
    {
        int bad = 0;
        // the success table, all 51 cells
        static const int kS[17][3] = {
            { 50, 30, 10 },
            { 55, 35, 15 },
            { 60, 35, 15 },
            { 65, 40, 20 },
            { 70, 45, 25 },
            { 75, 50, 25 },
            { 80, 55, 30 },
            { 85, 60, 35 },
            { 85, 60, 40 },
            { 90, 65, 45 },
            { 90, 65, 50 },
            { 95, 65, 50 },
            { 95, 70, 50 },
            { 95, 70, 50 },
            { 95, 75, 50 },
            { 95, 75, 55 },
            { 95, 75, 60 },
        };
        for (int lvl = 1; lvl <= 17; ++lvl)
            for (int c = 0; c < 3; ++c)
                if (rules::spySuccessChance(lvl,
                        (rules::SpyCategory)c)
                        != kS[lvl - 1][c]) ++bad;
        // the level clamps: 0 reads row 1, 18+ row 17
        if (rules::spySuccessChance(0, rules::SPY_SIMPLE) != 50 ||
            rules::spySuccessChance(18, rules::SPY_SIMPLE) != 95)
            ++bad;
        // the hired-spy level cap
        if (rules::spyHiredLevelCap() != 8) ++bad;
        // the mission days: simple 1-8, difficult 5-40,
        // extraordinary as required (0-0)
        int lo, hi;
        rules::spyMissionDays(rules::SPY_SIMPLE, lo, hi);
        if (lo != 1 || hi != 8) ++bad;
        rules::spyMissionDays(rules::SPY_DIFFICULT, lo, hi);
        if (lo != 5 || hi != 40) ++bad;
        rules::spyMissionDays(rules::SPY_EXTRAORDINARY, lo, hi);
        if (lo != 0 || hi != 0) ++bad;
        // the discovery formula: cumulative 1 percent
        // per day capped at 10, minus the level, floor 1
        if (rules::spyModifiedDiscoveryChance(1, 0) != 1 ||
            rules::spyModifiedDiscoveryChance(3, 1) != 2 ||
            rules::spyModifiedDiscoveryChance(10, 3) != 7 ||
            rules::spyModifiedDiscoveryChance(30, 5) != 5 ||
            rules::spyModifiedDiscoveryChance(30, 12) != 1 ||
            rules::spyModifiedDiscoveryChance(0, 1) != 1) ++bad;
        // the precaution tiers: checks per week and the
        // percent each check reads (no precautions is a
        // flat 1 percent, the modified percent ignored)
        if (rules::spyPrecautionChecksPerWeek(
                rules::SPYP_NONE) != 1 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_MINIMAL) != 1 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_MODERATE) != 2 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_STRONG) != 2) ++bad;
        if (rules::spyDiscoveryCheckPercent(
                rules::SPYP_NONE, 7) != 1 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_MINIMAL, 7) != 7 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_MODERATE, 7) != 7 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_STRONG, 7) != 14) ++bad;
        // the tenfold window: 20-50 days, x10
        if (rules::spyPostCaptureWindowLo() != 20 ||
            rules::spyPostCaptureWindowHi() != 50 ||
            rules::spyPostCaptureChanceMultiple() != 10)
            ++bad;
        // the failure bands: the five edges
        if (rules::spyFailureResult(1) != rules::SPYF_RETRY ||
            rules::spyFailureResult(35) != rules::SPYF_RETRY ||
            rules::spyFailureResult(36)
                != rules::SPYF_COMPROMISED_90 ||
            rules::spyFailureResult(60)
                != rules::SPYF_COMPROMISED_90 ||
            rules::spyFailureResult(61)
                != rules::SPYF_IMPRISONED_SILENT ||
            rules::spyFailureResult(80)
                != rules::SPYF_IMPRISONED_SILENT ||
            rules::spyFailureResult(81)
                != rules::SPYF_CAUGHT_TORTURED ||
            rules::spyFailureResult(95)
                != rules::SPYF_CAUGHT_TORTURED ||
            rules::spyFailureResult(96)
                != rules::SPYF_KILLED_OR_TURNED ||
            rules::spyFailureResult(100)
                != rules::SPYF_KILLED_OR_TURNED) ++bad;
        // the failure-score modifiers: difficult +10,
        // extraordinary -5, discovered +25
        if (rules::spyFailureScoreAdj(
                rules::SPY_SIMPLE, false) != 0 ||
            rules::spyFailureScoreAdj(
                rules::SPY_DIFFICULT, false) != 10 ||
            rules::spyFailureScoreAdj(
                rules::SPY_EXTRAORDINARY, false) != -5 ||
            rules::spyFailureScoreAdj(
                rules::SPY_DIFFICULT, true) != 35) ++bad;
        // the 36-60 band: 90 percent further failure
        if (rules::spyCompromisedFailChance() != 90) ++bad;
        // the torture outcomes: 1-2 dead, 3-4 revealed,
        // 5-6 turncoat
        if (rules::spyTortureOutcome(1) != rules::SPYT_DEAD ||
            rules::spyTortureOutcome(2) != rules::SPYT_DEAD ||
            rules::spyTortureOutcome(3)
                != rules::SPYT_REVEALED ||
            rules::spyTortureOutcome(4)
                != rules::SPYT_REVEALED ||
            rules::spyTortureOutcome(5)
                != rules::SPYT_TURNCOAT ||
            rules::spyTortureOutcome(6)
                != rules::SPYT_TURNCOAT) ++bad;
        // the fanatical rule: never a double agent;
        // any dice total over 60 is suicide
        if (!rules::spyFanaticalNeverDoubleAgent()) ++bad;
        if (rules::spyFanaticalSuicided(60)) ++bad;
        if (!rules::spyFanaticalSuicided(61)) ++bad;
        printf("R205 spying tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R206: the pursuit and evasion audit ----
    // DMG pp.67-69: the underground pursuit
    // likelihood ladder, the three end-condition
    // cases by relative speed, the food and
    // treasure distractions, the multiple-choice
    // and detection radii, and the outdoor
    // evasion table (base 80 with the speed,
    // terrain, size and light adjustments).
    {
        int bad = 0;
        // the motivated semi-intelligent band
        if (rules::pursueLikelihoodMotivatedSemi() != 80)
            ++bad;
        // the low-intelligence ladder: 20 / 40 /
        // 80, and 100 when the outnumbering
        // pursuers feel greatly superior
        if (rules::pursueLikelihoodLowInt(
                true, false, false) != 20 ||
            rules::pursueLikelihoodLowInt(
                false, true, false) != 40 ||
            rules::pursueLikelihoodLowInt(
                false, false, false) != 80 ||
            rules::pursueLikelihoodLowInt(
                false, false, true) != 100) ++bad;
        // the end-condition distances and caps by
        // relative speed: 100/50/5 rounds,
        // 150/80/1 turn, 200/none/no cap
        if (rules::pursuitEndSightFeet(
                rules::PURS_PURSUED_FASTER) != 100 ||
            rules::pursuitEndSightFeet(
                rules::PURS_EQUAL_SPEED) != 150 ||
            rules::pursuitEndSightFeet(
                rules::PURS_PURSUER_FASTER) != 0) ++bad;
        if (rules::pursuitEndOutOfSightFeet(
                rules::PURS_PURSUED_FASTER) != 50 ||
            rules::pursuitEndOutOfSightFeet(
                rules::PURS_EQUAL_SPEED) != 80 ||
            rules::pursuitEndOutOfSightFeet(
                rules::PURS_PURSUER_FASTER) != 200) ++bad;
        if (rules::pursuitEndRoundCap(
                rules::PURS_PURSUED_FASTER) != 5 ||
            rules::pursuitEndRoundCap(
                rules::PURS_EQUAL_SPEED) != 10 ||
            rules::pursuitEndRoundCap(
                rules::PURS_PURSUER_FASTER) != -1) ++bad;
        // the composition: in sight at 101 feet
        // ends the faster-pursued case; 100 does
        // not; out of sight lost at 201 ends the
        // pursuer-faster case; past the round cap
        // without a gain ends it
        if (!rules::pursuitEnds(
                rules::PURS_PURSUED_FASTER, true, 101,
                false, 0, 0, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_PURSUED_FASTER, true, 100,
                false, 0, 0, false)) ++bad;
        if (!rules::pursuitEnds(
                rules::PURS_PURSUER_FASTER, false, 0,
                true, 201, 0, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_PURSUER_FASTER, false, 0,
                true, 200, 0, false)) ++bad;
        if (!rules::pursuitEnds(
                rules::PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, true)) ++bad;
        // the movement procedure: 3 phases per
        // round, contact at 10 feet
        if (rules::pursuitPhasesPerRound() != 3 ||
            rules::pursuitConfrontFeet() != 10) ++bad;
        // the food distraction: 100 percent for
        // non-intelligent; d10 base + 10 per point
        // below 5; the confirm roll at or under
        if (rules::foodDistractionPercent(0, 0) != 100 ||
            rules::foodDistractionPercent(5, 5) != 50 ||
            rules::foodDistractionPercent(5, 2) != 80 ||
            rules::foodDistractionPercent(9, 1) != 100 ||
            rules::foodDistractionPercent(3, 7) != 30)
            ++bad;
        // at 100 percent the distraction is automatic -
        // the print spares the second d10 - so the
        // function returns true: pinned as correct
        if (!rules::foodDistractionSucceeds(100, 1) ||
            !rules::foodDistractionSucceeds(80, 8) ||
            rules::foodDistractionSucceeds(80, 9) ||
            !rules::foodDistractionSucceeds(30, 3) ||
            rules::foodDistractionSucceeds(30, 4) ||
            rules::foodDistractionBreakRounds() != 1)
            ++bad;
        // the treasure distraction: +10 per 10
        // items for low intelligence, +10 per
        // 100 gp of value
        if (rules::treasureDistractionLowInt(
                20, 20) != 40 ||
            rules::treasureDistractionLowInt(
                20, 100) != 100 ||
            rules::treasureDistractionValueBonus(
                250) != 20 ||
            rules::treasureDistractionValueBonus(
                99) != 0) ++bad;
        // the multiple-choice and detection radii
        if (rules::pursuitWrongChoiceWays(3) != 2 ||
            rules::pursuitWrongChoiceWays(2) != 1)
            ++bad;
        if (rules::pursuitCornerSightFeet() != 60 ||
            rules::pursuitHearingMetalFeet() != 90 ||
            rules::pursuitHearingBootsFeet() != 60 ||
            rules::pursuitHearingQuietFeet() != 30)
            ++bad;
        // the outdoor table: base 80, every
        // adjustment row cell for cell
        if (rules::evadeOutdoorBase() != 80) ++bad;
        if (rules::evadeOutdoorSpeedAdj(
                rules::PURS_PURSUED_FASTER) != 10 ||
            rules::evadeOutdoorSpeedAdj(
                rules::PURS_EQUAL_SPEED) != 0 ||
            rules::evadeOutdoorSpeedAdj(
                rules::PURS_PURSUER_FASTER) != -20) ++bad;
        if (rules::evadeOutdoorTerrainAdj(
                rules::EVT_PLAIN_DESERT_WATER) != -50 ||
            rules::evadeOutdoorTerrainAdj(
                rules::EVT_SCRUB_ROUGH_HILLS_MARSH) != 10 ||
            rules::evadeOutdoorTerrainAdj(
                rules::EVT_FOREST_MOUNTAINS) != 30) ++bad;
        if (rules::evadeOutdoorPursuedSizeAdj(5) != 10 ||
            rules::evadeOutdoorPursuedSizeAdj(6) != 0 ||
            rules::evadeOutdoorPursuedSizeAdj(11) != 0 ||
            rules::evadeOutdoorPursuedSizeAdj(12)
                != -20 ||
            rules::evadeOutdoorPursuedSizeAdj(50)
                != -20 ||
            rules::evadeOutdoorPursuedSizeAdj(51)
                != -50) ++bad;
        if (rules::evadeOutdoorPursuerSizeAdj(11)
                != -20 ||
            rules::evadeOutdoorPursuerSizeAdj(12) != 0 ||
            rules::evadeOutdoorPursuerSizeAdj(24) != 0 ||
            rules::evadeOutdoorPursuerSizeAdj(25)
                != 10) ++bad;
        if (rules::evadeOutdoorLightAdj(
                rules::EVL_FULL_DAYLIGHT) != -30 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_TWILIGHT) != -10 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_BRIGHT_MOONLIGHT) != 0 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_STARLIGHT) != 20 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_DARK_NIGHT) != 50) ++bad;
        // the assembly: a lone pursued party,
        // pursuer faster, plain, dark night -
        // 80 - 20 - 50 + 10 + 10 + 50 = 80; a
        // 6-member party, equal speed, forest,
        // 12-24 pursuers, daylight - 80 + 30 -
        // 30 = 80; and a 12-member party, equal
        // speed, plain, twilight, 30 pursuers -
        // 80 - 50 - 20 + 10 - 10 = 10 (the +10
        // is the over-24-pursuers band)
        if (rules::evadeOutdoorChance(
                rules::PURS_PURSUER_FASTER,
                rules::EVT_PLAIN_DESERT_WATER,
                1, 25, rules::EVL_DARK_NIGHT) != 80 ||
            rules::evadeOutdoorChance(
                rules::PURS_EQUAL_SPEED,
                rules::EVT_FOREST_MOUNTAINS,
                6, 12, rules::EVL_FULL_DAYLIGHT) != 80 ||
            rules::evadeOutdoorChance(
                rules::PURS_EQUAL_SPEED,
                rules::EVT_PLAIN_DESERT_WATER,
                12, 30, rules::EVL_TWILIGHT) != 10)
            ++bad;
        // the outdoor surprise rule and the
        // hourly recheck
        if (!rules::evadeAutoOnSurprise(true) ||
            rules::evadeAutoOnSurprise(false) ||
            !rules::evadePossibleWhenSurprised(false) ||
            rules::evadePossibleWhenSurprised(true) ||
            !rules::evadeOutdoorConfronts(0) ||
            !rules::evadeOutdoorConfronts(-10) ||
            rules::evadeOutdoorConfronts(1)) ++bad;
        printf("R206 pursuit and evasion audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R207: the town taxation audit ----
    // DMG p.90: the worked example town - the
    // import duty, the luxury tariff, the entry
    // fee, the head tax, the foreigner sales
    // tax, the property tax, citizenship, the
    // foreign-coin fines and exchange rate,
    // the gem surtax and the toll-evasion
    // penalties.
    {
        int bad = 0;
        // the import duty: 1 percent, doubled for
        // foreigners
        if (rules::taxImportDutyPercent(false) != 1 ||
            rules::taxImportDutyPercent(true) != 2) ++bad;
        // the luxury tariff: 5 percent on sale
        if (rules::taxLuxuryTariffPercent() != 5) ++bad;
        // the entry fee: 1 copper a citizen, 5 a
        // non-citizen, per head or wheel
        if (rules::taxEntryFeeCopper(false) != 1 ||
            rules::taxEntryFeeCopper(true) != 5) ++bad;
        // the annual head tax: 1 copper a peasant,
        // 1 silver a freeman, 1 gold a gentleman or
        // noble (the coin units 1/10/100)
        if (rules::taxHeadTaxAnnual(rules::TAXS_PEASANT) != 1 ||
            rules::taxHeadTaxAnnual(rules::TAXS_FREEMAN) != 10 ||
            rules::taxHeadTaxAnnual(
                rules::TAXS_GENTLEMAN_NOBLE) != 100) ++bad;
        // the foreigner sales tax: 10 percent, no
        // service tax on them
        if (rules::taxForeignerSalesTaxPercent() != 10 ||
            rules::taxForeignerServiceTaxPercent() != 0)
            ++bad;
        // the tithe pledge and the property tax
        if (!rules::taxTithePledgeRequired() ||
            rules::taxPropertyTaxPercent() != 5) ++bad;
        // citizenship: one month plus 10 gold
        if (rules::taxCitizenshipResidenceDays() != 30 ||
            rules::taxCitizenshipFeeGold() != 10) ++bad;
        // foreign coin: the merchant fine 5 percent,
        // the 90 percent exchange, the 100-noble
        // limit, the 50 percent over-limit fine,
        // the 24-hour grace, the 10 percent gem
        // surtax
        if (rules::taxForeignCoinMerchantFinePercent() != 5 ||
            rules::taxExchangeRatePercent() != 90 ||
            rules::taxForeignCoinLimitSilverNobles() != 100 ||
            rules::taxForeignCoinOverLimitFinePercent() != 50 ||
            rules::taxMoneyChangerGraceHours() != 24 ||
            rules::taxGemSurtaxPercent() != 10) ++bad;
        // the exchange arithmetic: 10 foreign
        // coppers bring 9 domestic; 100 bring 90
        if (rules::taxExchangeDomestic(10) != 9 ||
            rules::taxExchangeDomestic(100) != 90 ||
            rules::taxExchangeDomestic(1) != 0) ++bad;
        // the over-limit fine: over 100 nobles is
        // fined unless within 24 hours and bound for
        // the changers; at or under the limit never;
        // over the limit with the grace and the
        // direction is spared
        if (!rules::taxForeignCoinFineApplies(
                101, 25, true)) ++bad;
        if (rules::taxForeignCoinFineApplies(
                100, 25, true)) ++bad;
        if (rules::taxForeignCoinFineApplies(
                101, 24, true)) ++bad;
        if (!rules::taxForeignCoinFineApplies(
                101, 24, false)) ++bad;
        if (!rules::taxForeignCoinFineApplies(
                101, 25, false)) ++bad;
        // toll evasion: confiscation, fine and
        // imprisonment possible
        if (!rules::taxTollEvasionConfiscates() ||
            !rules::taxTollEvasionImprisons()) ++bad;
        printf("R207 town taxation audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R208: the social class and rank audit ----
    // DMG pp.88-89: the government forms,
    // the worked example aristocracy, the
    // town and city social structure and
    // offices, the knights and the noble
    // title ladders.
    {
        int bad = 0;
        // the government forms: 19 named,
        // each with its print definition trait
        if (rules::govFormCount() != 19) ++bad;
        static const int kTrait[19] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18,
        };
        for (int f = 0; f < 19; ++f)
            if (rules::govFormTrait(f) != kTrait[f]) ++bad;
        // the distinctive definitions, pinned
        if (rules::govFormTrait(rules::GOV_GYNARCHY)
                != rules::GOVT_FEMALES_ONLY ||
            rules::govFormTrait(rules::GOV_MATRIARCHY)
                != rules::GOVT_ELDEST_FEMALES) ++bad;
        if (rules::govFormTrait(rules::GOV_THEOCRACY)
                != rules::GOVT_GOD_RULE) ++bad;
        if (rules::govFormTrait(rules::GOV_MAGOCRACY)
                != rules::GOVT_MAGIC_USERS_ONLY ||
            rules::govFormTrait(rules::GOV_PLUTOCRACY)
                != rules::GOVT_THE_WEALTHY) ++bad;
        if (rules::govFormTrait(rules::GOV_PEDOCRACY)
                != rules::GOVT_THE_LEARNED ||
            rules::govFormTrait(rules::GOV_GERIATOCRACY)
                != rules::GOVT_ELDERLY_ONLY) ++bad;
        if (rules::govFormTrait(rules::GOV_SYNDICRACY)
                != rules::GOVT_SYNDICS_BUSINESS) ++bad;
        if (rules::govFormTrait(rules::GOV_FEUDALITY)
                != rules::GOVT_LAYERED_FEALTY ||
            rules::govFormTrait(rules::GOV_HIERARCHY)
                != rules::GOVT_RELIGIOUS_LIKE_FEUDAL) ++bad;
        if (rules::govFormTrait(rules::GOV_MONARCHY)
                != rules::GOVT_SINGLE_HEREDITARY_SOVEREIGN
            || rules::govFormTrait(rules::GOV_OLIGARCHY)
                != rules::GOVT_FEW_COEQUAL) ++bad;
        // the worked example aristocracy: all
        // three - service, land, income tax
        if (!rules::aristocratEligible(true, 100, 10) ||
            rules::aristocratEligible(false, 100, 10) ||
            rules::aristocratEligible(true, 99, 10) ||
            rules::aristocratEligible(true, 100, 9) ||
            !rules::aristocratEligible(true, 500, 50))
            ++bad;
        // the merchant waiver: land waived at
        // 20 gold pieces of annual business tax
        if (!rules::aristocratMerchantEligible(true, 20) ||
            rules::aristocratMerchantEligible(true, 19) ||
            !rules::aristocratMerchantEligible(true, 100) ||
            rules::aristocratMerchantEligible(false, 20))
            ++bad;
        // the offices: aristocrats only; the
        // senate from their number; tribunals
        // from former senators; the police
        // appointment from former officers
        if (!rules::officeEligible(true) ||
            rules::officeEligible(false) ||
            !rules::senateEligible(true) ||
            rules::senateEligible(false)) ++bad;
        if (!rules::tribunalEligible(true) ||
            rules::tribunalEligible(false) ||
            !rules::policeAppointedFrom(true) ||
            rules::policeAppointedFrom(false)) ++bad;
        // the town classes: three, and what
        // each draws
        if (rules::townClassCount() != 3) ++bad;
        if (!rules::townDrawsImportantLawmakers(
                rules::TOWN_UPPER) ||
            rules::townDrawsImportantLawmakers(
                rules::TOWN_MIDDLE) ||
            rules::townDrawsImportantLawmakers(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::townProvidesLesserOfficials(
                rules::TOWN_MIDDLE) ||
            rules::townProvidesLesserOfficials(
                rules::TOWN_UPPER) ||
            rules::townProvidesLesserOfficials(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::townDrawsCommonCouncil(
                rules::TOWN_LOWER) ||
            rules::townDrawsCommonCouncil(
                rules::TOWN_UPPER) ||
            rules::townDrawsCommonCouncil(
                rules::TOWN_MIDDLE)) ++bad;
        // the mayor: three titles, lifetime,
        // upper class only
        if (rules::mayorTitleCount() != 3 ||
            !rules::mayorOfficeLifetime() ||
            rules::mayorOfficeSourceClass()
                != rules::TOWN_UPPER) ++bad;
        // the aldermen: three titles, chosen by
        // the upper class as major officers,
        // elected by the middle class
        if (rules::aldermanTitleCount() != 3 ||
            !rules::aldermenChosenBy(rules::TOWN_UPPER) ||
            rules::aldermenChosenBy(rules::TOWN_MIDDLE) ||
            rules::aldermenChosenBy(rules::TOWN_LOWER) ||
            !rules::aldermenElectedBy(rules::TOWN_MIDDLE) ||
            rules::aldermenElectedBy(rules::TOWN_UPPER))
            ++bad;
        // the strata: judiciary and military
        // command upper; law, customs and tax
        // officials middle
        if (rules::townJudiciaryStratum()
                != rules::TOWN_UPPER ||
            rules::townMilitaryCommandStratum()
                != rules::TOWN_UPPER) ++bad;
        if (rules::lawEnforcementSourceClass()
                != rules::TOWN_MIDDLE ||
            rules::customsOfficialSourceClass()
                != rules::TOWN_MIDDLE ||
            rules::taxOfficialSourceClass()
                != rules::TOWN_MIDDLE) ++bad;
        // the councilors: selected by upper
        // and middle and the free lower; petty
        // officials lower, administrative only
        if (!rules::councilorSelectedBy(
                rules::TOWN_UPPER) ||
            !rules::councilorSelectedBy(
                rules::TOWN_MIDDLE) ||
            rules::councilorSelectedBy(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::councilorSelectedByLower(true) ||
            rules::councilorSelectedByLower(false) ||
            rules::pettyOfficialsSourceClass()
                != rules::TOWN_LOWER ||
            !rules::pettyOfficialRoleAdministrative())
            ++bad;
        // the constabulary: citizen soldiers,
        // watch or police, militia in great
        // need; the bulk hired mercenaries
        if (!rules::constabularyIncludesCitizenSoldiers() ||
            !rules::constabularyIncludesWatchOrPolice() ||
            !rules::militiaCalledInGreatNeed() ||
            !rules::soldieryBulkMercenaries()) ++bad;
        // the knights: non-hereditary peers,
        // precedence varying by order
        if (rules::knightsHereditary() ||
            !rules::knightPrecedenceVariesByOrder())
            ++bad;
        // the northern European ladder: 10
        // secular titles, emperor highest,
        // knight lowest; duke precedes prince
        // per the print table
        if (rules::nobleTitleRNCount() != 10 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_EMPEROR) != 0 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_KING) != 1 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_DUKE) != 2 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_PRINCE) != 3 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_MARQUIS) != 4 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_COUNT_EARL) != 5 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_VISCOUNT) != 6 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_BARON_THANE) != 7 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_BARONET) != 8 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_KNIGHT) != 9) ++bad;
        // the ecclesiastical ranks among the
        // nobility: archbishop, bishop, abbot,
        // prior
        if (rules::ecclesiasticalRanksAmongNobility() != 4)
            ++bad;
        // the German equivalents: seven mapped
        if (rules::germanEquivalentCount() != 7 ||
            rules::germanEquivalentOf(rules::NT_KNIGHT)
                != rules::GT_RITTER ||
            rules::germanEquivalentOf(rules::NT_EMPEROR)
                != -1 ||
            rules::germanEquivalentOf(rules::NT_DUKE)
                != rules::GT_PFALZGRAF ||
            rules::germanEquivalentOf(rules::NT_PRINCE)
                != rules::GT_HERZOG ||
            rules::germanEquivalentOf(rules::NT_BARON_THANE)
                != -1) ++bad;
        // the Asian titles: twenty listed
        if (rules::asianTitleCount() != 20) ++bad;
        printf("R208 social class and rank audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R209: the NPC personae facts audit ----
    // DMG pp.114-115: the classed, occupied
    // and demi-human ability adjustments,
    // the facts tables, the sanity asterisk
    // rule, and the p.11 die rules.
    {
        int bad = 0;
        // the class table: abilities and amounts
        // (ability codes: 0 STR, 1 INT, 2 WIS, 3 DEX,
        // 4 CON, 5 CHA, 6 none - the Ability enum)
        static const int kAdjAb[30] = {
            2, 6, 6,
            6, 6, 6,
            0, 4, 6,
            0, 4, 6,
            0, 4, 6,
            1, 3, 6,
            6, 6, 6,
            6, 6, 6,
            3, 1, 6,
            3, 1, 0,
        };
        static const int kAdjAmt[30] = {
            2, 0, 0,   0, 0, 0,   2, 1, 0,
            2, 1, 0,   2, 1, 0,   2, 1, 0,
            0, 0, 0,   0, 0, 0,   2, 1, 0,
            2, 1, 1,
        };
        if (rules::npcClassCount() != 10) ++bad;
        for (int c = 0; c < 10; ++c)
            for (int s = 0; s < 3; ++s)
                if (rules::npcClassAdjAbility(c, s)
                        != kAdjAb[c * 3 + s] ||
                    rules::npcClassAdjAmount(c, s)
                        != kAdjAmt[c * 3 + s]) ++bad;
        // the class minimums: druid 12/14,
        // ranger 12, paladin 17, illusionist
        // 15/15, monk 12/15/15
        if (rules::npcClassMinAbility(
                rules::NPCP_DRUID, 0) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_DRUID, 0) != 12 ||
            rules::npcClassMinAbility(
                rules::NPCP_DRUID, 1) != 5 ||
            rules::npcClassMinValue(
                rules::NPCP_DRUID, 1) != 14) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_RANGER, 0) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_RANGER, 0) != 12) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_PALADIN, 0) != 5 ||
            rules::npcClassMinValue(
                rules::NPCP_PALADIN, 0) != 17) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_ILLUSIONIST, 0) != 1 ||
            rules::npcClassMinValue(
                rules::NPCP_ILLUSIONIST, 0) != 15 ||
            rules::npcClassMinAbility(
                rules::NPCP_ILLUSIONIST, 1) != 3 ||
            rules::npcClassMinValue(
                rules::NPCP_ILLUSIONIST, 1) != 15) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_MONK, 0) != 0 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 0) != 12 ||
            rules::npcClassMinAbility(
                rules::NPCP_MONK, 1) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 1) != 15 ||
            rules::npcClassMinAbility(
                rules::NPCP_MONK, 2) != 3 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 2) != 15) ++bad;
        // the no-minimum classes read none
        for (int s = 0; s < 3; ++s)
            if (rules::npcClassMinAbility(
                    rules::NPCP_CLERIC, s)
                    != 6 ||
                rules::npcClassMinValue(
                    rules::NPCP_CLERIC, s) != 0 ||
                rules::npcClassMinAbility(
                    rules::NPCP_THIEF, s)
                    != 6 ||
                rules::npcClassMinValue(
                    rules::NPCP_THIEF, s) != 0) ++bad;
        // the ability limit clamp
        if (rules::npcAdjustedAbility(18, 2) != 18 ||
            rules::npcAdjustedAbility(3, -1) != 3 ||
            rules::npcAdjustedAbility(10, 2) != 12) ++bad;
        // the occupations: laborer strength
        // +1 to +3, mercenary strength +1 and
        // constitution +3 with 4 minimum hit
        // points, merchant 12/12 minimums
        if (rules::npcOccupationCount() != 3) ++bad;
        if (rules::npcOccupationAdjAbility(
                rules::NPCO_LABORER, 0) != 0 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_LABORER, 0) != 1 ||
            rules::npcOccupationAdjMax(
                rules::NPCO_LABORER, 0) != 3) ++bad;
        if (rules::npcOccupationAdjAbility(
                rules::NPCO_MERCENARY, 0) != 0 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_MERCENARY, 0) != 1 ||
            rules::npcOccupationAdjAbility(
                rules::NPCO_MERCENARY, 1) != 4 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_MERCENARY, 1) != 3 ||
            rules::npcMercenaryMinHitPoints() != 4) ++bad;
        if (rules::npcOccupationMinAbility(
                rules::NPCO_MERCHANT, 0) != 1 ||
            rules::npcOccupationMinValue(
                rules::NPCO_MERCHANT, 0) != 12 ||
            rules::npcOccupationMinAbility(
                rules::NPCO_MERCHANT, 1) != 5 ||
            rules::npcOccupationMinValue(
                rules::NPCO_MERCHANT, 1) != 12) ++bad;
        // the demi-human table (the DMG one,
        // not the PHB one)
        if (rules::npcDemiRaceCount() != 4) ++bad;
        static const int kRaceAb[12] = {
            0, 4, 5,
            1, 3, 6,
            2, 4, 5,
            3, 4, 6,
        };
        static const int kRaceAmt[12] = {
            1, 1, -1,   1, 1, 0,
            1, 1, -1,   1, 1, 0,
        };
        for (int r = 0; r < 4; ++r)
            for (int s = 0; s < 3; ++s)
                if (rules::npcRaceAdjAbility(r, s)
                        != kRaceAb[r * 3 + s] ||
                    rules::npcRaceAdjAmount(r, s)
                        != kRaceAmt[r * 3 + s]) ++bad;
        // the alignment table, every face
        static const int kAlign[10] = {
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            8,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactAlign(d) != kAlign[d - 1]) ++bad;
        if (rules::npcFactAlign(0) != rules::NPCA_TRUE) ++bad;
        // the possessions table, every face
        static const int kWealth[10] = {
            0, 1, 1,
            2, 2,
            2, 2,
            3, 4,
            5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactWealth(d) != kWealth[d - 1]) ++bad;
        // the appearance age bands, every face
        static const int kAge[10] = {
            0, 1,
            1, 2,
            2, 2,
            2, 3,
            4, 5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactAgeBand(d) != kAge[d - 1]) ++bad;
        // the general appearance words,
        // every face, all ten distinct
        static const int kLook[10] = {
            0, 1,
            2, 3,
            4, 5,
            6, 7,
            8, 9,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactGeneralLook(d) != kLook[d - 1]) ++bad;
        // the sanity table, every face
        static const int kSanity[10] = {
            0, 1,
            1, 1,
            1, 1,
            2, 3,
            4, 5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactSanity(d) != kSanity[d - 1]) ++bad;
        // the asterisk rows: insane and
        // maniacal only
        if (!rules::npcSanityIsMarked(
                rules::NPCS_INSANE) ||
            !rules::npcSanityIsMarked(
                rules::NPCS_MANIACAL) ||
            rules::npcSanityIsMarked(                rules::NPCS_NEUROTIC) ||
            rules::npcSanityIsMarked(                rules::NPCS_NORMAL)) ++bad;
        // the asterisk resolution: a marked
        // first roll takes the second roll,
        // an unmarked first roll stands
        if (rules::npcSanityResolved(9, 10)
                != rules::NPCS_MANIACAL ||
            rules::npcSanityResolved(10, 9)
                != rules::NPCS_INSANE ||
            rules::npcSanityResolved(9, 3)
                != rules::NPCS_NORMAL ||
            rules::npcSanityResolved(4, 10)
                != rules::NPCS_NORMAL ||
            rules::npcSanityResolved(2, 8)
                != rules::NPCS_NORMAL) ++bad;
        // the p.11 die rules
        if (rules::npcGeneralCharacterDie(1) != 3 ||
            rules::npcGeneralCharacterDie(6) != 4 ||
            rules::npcGeneralCharacterDie(3) != 3 ||
            rules::npcGeneralCharacterDie(5) != 5) ++bad;
        if (rules::npcSpecialCharacterDieBonus(1) != 1 ||
            rules::npcSpecialCharacterDieBonus(5) != 1 ||
            rules::npcSpecialCharacterDieBonus(6) != 0) ++bad;
        // no fewer than three General Tendencies
        if (rules::npcMinGeneralTendencies() != 3) ++bad;
        printf("R209 NPC personae facts audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R210: the NPC personae traits audit ----
    // DMG pp.115-116: the general tendencies,
    // personality, interests and the word
    // tables, the morals asterisk rule, and the
    // reaction adjustment percents.
    {
        int bad = 0;
        // the tendencies: 24 rows, the d6 halves
        if (rules::npcTendencyCount() != 24) ++bad;
        if (rules::npcTraitTendency(1, 1) != 0 ||
            rules::npcTraitTendency(3, 12) != 11 ||
            rules::npcTraitTendency(4, 1) != 12 ||
            rules::npcTraitTendency(6, 12) != 23 ||
            rules::npcTraitTendency(2, 5)
                != rules::NPT_HELPFUL_KINDLY ||
            rules::npcTraitTendency(5, 6)
                != rules::NPT_FOUL_BARBARIC ||
            rules::npcTraitTendency(1, 24) != 11 ||
            rules::npcTraitTendency(9, 1) != 12) ++bad;
        // the personality: the column split and
        // the per-column words
        if (rules::npcTraitPersonalityType(1)
                != rules::NPPTY_AVERAGE ||
            rules::npcTraitPersonalityType(5)
                != rules::NPPTY_AVERAGE ||
            rules::npcTraitPersonalityType(6)
                != rules::NPPTY_EXTROVERTED ||
            rules::npcTraitPersonalityType(7)
                != rules::NPPTY_EXTROVERTED ||
            rules::npcTraitPersonalityType(8)
                != rules::NPPTY_INTROVERTED) ++bad;
        if (rules::npcTraitPersonality(1, 1)
                != rules::NPPW_MODEST ||
            rules::npcTraitPersonality(1, 8)
                != rules::NPPW_ABRASIVE ||
            rules::npcTraitPersonality(6, 1)
                != rules::NPPW_FORCEFUL ||
            rules::npcTraitPersonality(7, 7)
                != rules::NPPW_RASH ||
            rules::npcTraitPersonality(8, 1)
                != rules::NPPW_RETIRING ||
            rules::npcTraitPersonality(8, 8)
                != rules::NPPW_SOLITARY_SECRETIVE) ++bad;
        // every personality cell: the identity
        // walk (col base + row)
        static const int kPersColBase[3] = { 0, 8, 16 };
        for (int c = 0; c < 3; ++c)
            for (int r = 1; r <= 8; ++r)
                if (rules::npcTraitPersonality(
                        c == 0 ? 1 : (c == 1 ? 6 : 8), r)
                    != kPersColBase[c] + r - 1) ++bad;
        // the interests: the halves, the
        // collector rows and the none rows
        if (rules::npcInterestCount() != 24) ++bad;
        if (rules::npcTraitInterest(1, 1)
                != rules::NPI_RELIGION ||
            rules::npcTraitInterest(3, 12)
                != rules::NPI_POLITICS ||
            rules::npcTraitInterest(4, 1)
                != rules::NPI_WINES_SPIRITS ||
            rules::npcTraitInterest(5, 5)
                != rules::NPI_COLLECTOR_1 ||
            rules::npcTraitInterest(6, 12)
                != rules::NPI_NONE_2) ++bad;
        for (int i = 16; i <= 19; ++i)
            if (!rules::npcInterestIsCollector(i)) ++bad;
        if (rules::npcInterestIsCollector(15) ||
            rules::npcInterestIsCollector(20)) ++bad;
        // the disposition, intellect and
        // collections word faces
        if (rules::npcTraitDisposition(1)
                != rules::NPD_CHEERFUL ||
            rules::npcTraitDisposition(3)
                != rules::NPD_COMPASSIONATE_SENSITIVE ||
            rules::npcTraitDisposition(10)
                != rules::NPD_HARSH ||
            rules::npcTraitDisposition(0)
                != rules::NPD_HARSH) ++bad;
        if (rules::npcTraitIntellect(1)
                != rules::NPIQ_DULL ||
            rules::npcTraitIntellect(6)
                != rules::NPIQ_DREAMING ||
            rules::npcTraitIntellect(10)
                != rules::NPIQ_BRILLIANT) ++bad;
        if (!rules::npcIntellectModifiesRating(
                rules::NPIQ_SCHEMING) ||
            !rules::npcIntellectModifiesRating(                rules::NPIQ_DREAMING) ||
            rules::npcIntellectModifiesRating(                rules::NPIQ_ACTIVE_1)) ++bad;
        if (rules::npcTraitCollection(1)
                != rules::NPCOL_KNIVES_DAGGERS ||
            rules::npcTraitCollection(2)
                != rules::NPCOL_SWORDS ||
            rules::npcTraitCollection(12)
                != rules::NPCOL_ARTWORK) ++bad;
        // the nature, materialism, honesty,
        // bravery, energy and thrift faces
        if (rules::npcTraitNature(1)
                != rules::NPNT_SOFT_HEARTED ||
            rules::npcTraitNature(6)
                != rules::NPNT_VENGEFUL) ++bad;
        if (rules::npcTraitMaterialism(1)
                != rules::NPM_AESTHETIC ||
            rules::npcTraitMaterialism(6)
                != rules::NPM_AVARICIOUS) ++bad;
        if (rules::npcTraitHonesty(1)
                != rules::NPH_SCRUPULOUS ||
            rules::npcTraitHonesty(4)
                != rules::NPH_AVERAGE_1 ||
            rules::npcTraitHonesty(6)
                != rules::NPH_AVERAGE_3 ||
            rules::npcTraitHonesty(7)
                != rules::NPH_LIAR) ++bad;
        if (rules::npcTraitBravery(4)
                != rules::NPB_FOOLHARDY ||
            rules::npcTraitBravery(7)
                != rules::NPB_COWARDLY) ++bad;
        if (rules::npcTraitEnergy(1)
                != rules::NPE_SLOTHFUL ||
            rules::npcTraitEnergy(8)
                != rules::NPE_DRIVEN) ++bad;
        if (rules::npcTraitThrift(1)
                != rules::NPTHR_MISERLY ||
            rules::npcTraitThrift(6)
                != rules::NPTHR_SPENDTHRIFT_1 ||
            rules::npcTraitThrift(8)
                != rules::NPTHR_WASTREL) ++bad;
        // the morals: the faces, the marked
        // rows and the asterisk resolution
        if (rules::npcTraitMorals(1)
                != rules::NPMOR_ASCETIC ||
            rules::npcTraitMorals(5)
                != rules::NPMOR_LUSTY_1 ||
            rules::npcTraitMorals(10)
                != rules::NPMOR_PERVERTED ||
            rules::npcTraitMorals(12)
                != rules::NPMOR_DEPRAVED) ++bad;
        if (!rules::npcMoralsIsMarked(                rules::NPMOR_PERVERTED) ||
            !rules::npcMoralsIsMarked(                rules::NPMOR_SADISTIC) ||
            !rules::npcMoralsIsMarked(                rules::NPMOR_DEPRAVED) ||
            rules::npcMoralsIsMarked(                rules::NPMOR_AMORAL) ||
            rules::npcMoralsIsMarked(                rules::NPMOR_ASCETIC)) ++bad;
        if (rules::npcMoralsResolved(12, 11)
                != rules::NPMOR_SADISTIC ||
            rules::npcMoralsResolved(10, 10)
                != rules::NPMOR_PERVERTED ||
            rules::npcMoralsResolved(10, 3)
                != rules::NPMOR_NORMAL_1 ||
            rules::npcMoralsResolved(4, 12)
                != rules::NPMOR_NORMAL_2 ||
            rules::npcMoralsResolved(2, 11)
                != rules::NPMOR_VIRTUOUS) ++bad;
        // the piety faces: the average run
        // 5-8
        if (rules::npcTraitPiety(1)
                != rules::NPP_SAINTLY ||
            rules::npcTraitPiety(2)
                != rules::NPP_MARTYR_ZEALOT ||
            rules::npcTraitPiety(5)
                != rules::NPP_AVERAGE_1 ||
            rules::npcTraitPiety(8)
                != rules::NPP_AVERAGE_4 ||
            rules::npcTraitPiety(12)
                != rules::NPP_IRRELIGIOUS) ++bad;
        // the reaction adjustment percents:
        // the print mins and maxes
        if (rules::npcReactGroupCount() != 9) ++bad;
        static const int kReactMin[9] = {
            -1, 1, 1, 1, 1, 1, 1, 1, 1,
        };
        static const int kReactMax[9] = {
            6, 10, 20, 6, 4, 8, 20, 8, 20,
        };
        for (int g = 0; g < 9; ++g)
            if (rules::npcReactionAdjMin(g)
                    != kReactMin[g] ||
                rules::npcReactionAdjMax(g)
                    != kReactMax[g]) ++bad;
        // the d6/d8/d12/d10 clamps hold at the
        // extremes
        if (rules::npcTraitTendency(0, 0) != 0 ||
            rules::npcTraitTendency(7, 13) != 23 ||
            rules::npcTraitPersonality(9, 9)
                != rules::NPPW_SOLITARY_SECRETIVE ||
            rules::npcTraitMorals(0) != 0) ++bad;
        printf("R210 NPC personae traits audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R211: the NPC body and language audit ----
    // DMG pp.115-116: the height and weight
    // tables and determination bands, and the
    // random language table.
    {
        int bad = 0;
        // the averages and dice, every cell
        if (rules::npcBodyRaceCount() != 7) ++bad;
        static const int kHAvg[14] = {
            48, 60, 42, 66, 36, 66, 72,
            46, 54, 39, 62, 33, 62, 66,
        };
        static const int kWAvg[14] = {
            150, 100, 80, 130, 60, 150, 175,
            120, 80, 75, 100, 50, 120, 130,
        };
        static const int kHDice[28] = {
            104, 104, 103, 106, 103, 104, 112,
            106, 106, 103, 106, 106, 104, 112,
            104, 104, 103, 106, 103, 103, 106,
            104, 106, 103, 106, 103, 103, 108,
        };
        static const int kWDice[28] = {
            208, 110, 204, 120, 204, 208, 312,
            212, 120, 206, 120, 206, 410, 512,
            208, 110, 108, 112, 204, 306, 310,
            210, 206, 108, 208, 204, 408, 412,
        };
        for (int f = 0; f <= 1; ++f)
            for (int r = 0; r < 7; ++r)
                if (rules::npcHeightAvgInches(f, r)
                        != kHAvg[f * 7 + r] ||
                    rules::npcWeightAvgPounds(f, r)
                        != kWAvg[f * 7 + r]) ++bad;
        for (int f = 0; f <= 1; ++f)
            for (int d = 0; d <= 1; ++d)
                for (int r = 0; r < 7; ++r)
                    if (rules::npcHeightDie(f, r, d)
                            != kHDice[f * 14 + d * 7 + r] ||
                        rules::npcWeightDie(f, r, d)
                            != kWDice[f * 14 + d * 7 + r]) ++bad;
        // the packing: count and sides
        if (rules::npcDieCount(212) != 2 ||
            rules::npcDieSides(212) != 12 ||
            rules::npcDieCount(410) != 4 ||
            rules::npcDieSides(410) != 10 ||
            rules::npcDieCount(512) != 5 ||
            rules::npcDieSides(512) != 12 ||
            rules::npcDieCount(120) != 1 ||
            rules::npcDieSides(120) != 20) ++bad;
        // the determination bands: the edges
        static const int kHUnder[7] = { 15, 10, 20, 35, 10, 45, 20 };
        static const int kHAvgE[7] = { 80, 80, 85, 90, 90, 75, 80 };
        static const int kWUnder[7] = { 20, 15, 20, 20, 10, 30, 25 };
        static const int kWAvgE[7] = { 65, 90, 75, 85, 50, 55, 75 };
        for (int r = 0; r < 7; ++r)
            if (rules::npcHeightBandUnderEdge(r)
                    != kHUnder[r] ||
                rules::npcHeightBandAvgEdge(r)
                    != kHAvgE[r] ||
                rules::npcWeightBandUnderEdge(r)
                    != kWUnder[r] ||
                rules::npcWeightBandAvgEdge(r)
                    != kWAvgE[r]) ++bad;
        // the class walk: edges and clamps
        if (rules::npcDetermineHeightClass(                rules::NBR_DWARF, 15) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 16) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 80) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 81) != 2) ++bad;
        if (rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 45) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 46) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 75) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 76) != 2) ++bad;
        if (rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 25) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 26) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 75) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 76) != 2) ++bad;
        if (rules::npcDetermineHeightClass(                rules::NBR_ELF, 10) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_ELF, 11) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 15) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 16) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 90) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 91) != 2) ++bad;
        if (rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 10) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 11) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 50) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 51) != 2) ++bad;
        // the clamps: 0 reads under, 101 reads
        // over
        if (rules::npcDetermineHeightClass(                rules::NBR_DWARF, 0) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 101) != 2) ++bad;
        // the language table: every face
        if (rules::npcLanguageKindCount() != 55) ++bad;
        static const int kLang[100] = {
            0, 1, 1, 2,
            3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
            13,
            14, 14, 14, 14, 14,
            15, 15, 15, 15, 15,
            16,
            17,
            18, 19, 20, 21, 22, 23, 24, 25,
            26, 26, 26, 26,
            27,
            28, 28, 28, 28,
            29, 29, 29, 29, 29,
            30, 30,
            31, 31, 31,
            32,
            33, 33, 33,
            34,
            35,
            36,
            37, 38, 39,
            40,
            41,
            42, 42, 42, 42,
            43,
            44, 44, 44, 44, 44,
            45,
            46,
            47,
            48,
            49,
            50,
            51,
            52,
            53,
            54, 54, 54, 54, 54, 54, 54, 54,
            54, 54, 54, 54, 54, 54, 54,
        };
        for (int d = 1; d <= 100; ++d)
            if (rules::npcLanguageFor(d) != kLang[d - 1]) ++bad;
        // the language boundaries: each band
        // start and the kind codes
        if (rules::npcLanguageFor(1)
                != rules::NPC_LG_BROWNIE ||
            rules::npcLanguageFor(2)
                != rules::NPC_LG_BUGBEAR ||
            rules::npcLanguageFor(4)
                != rules::NPC_LG_CENTAUR ||
            rules::npcLanguageFor(5)
                != rules::NPC_LG_DRAGON_BLACK ||
            rules::npcLanguageFor(14)
                != rules::NPC_LG_DRAGON_WHITE ||
            rules::npcLanguageFor(15)
                != rules::NPC_LG_DRYAD ||
            rules::npcLanguageFor(16)
                != rules::NPC_LG_DWARVISH ||
            rules::npcLanguageFor(21)
                != rules::NPC_LG_ELVISH ||
            rules::npcLanguageFor(26)
                != rules::NPC_LG_ETTIN ||
            rules::npcLanguageFor(28)
                != rules::NPC_LG_GIANT_CLOUD ||
            rules::npcLanguageFor(31)
                != rules::NPC_LG_GIANT_HILL_1 ||
            rules::npcLanguageFor(33)
                != rules::NPC_LG_GIANT_HILL_3 ||
            rules::npcLanguageFor(35)
                != rules::NPC_LG_GIANT_STORM ||
            rules::npcLanguageFor(36)
                != rules::NPC_LG_GOBLIN ||
            rules::npcLanguageFor(40)
                != rules::NPC_LG_GNOLL ||
            rules::npcLanguageFor(41)
                != rules::NPC_LG_GNOME ||
            rules::npcLanguageFor(45)
                != rules::NPC_LG_HALFLING ||
            rules::npcLanguageFor(50)
                != rules::NPC_LG_HOBGOBLIN ||
            rules::npcLanguageFor(52)
                != rules::NPC_LG_KOBOLD ||
            rules::npcLanguageFor(55)
                != rules::NPC_LG_LAMMASU ||
            rules::npcLanguageFor(56)
                != rules::NPC_LG_LIZARD_MAN ||
            rules::npcLanguageFor(59)
                != rules::NPC_LG_MANTICORE ||
            rules::npcLanguageFor(60)
                != rules::NPC_LG_MEDUSIAN ||
            rules::npcLanguageFor(61)
                != rules::NPC_LG_MINOTAUR ||
            rules::npcLanguageFor(62)
                != rules::NPC_LG_NAGA_GUARDIAN ||
            rules::npcLanguageFor(64)
                != rules::NPC_LG_NAGA_WATER ||
            rules::npcLanguageFor(65)
                != rules::NPC_LG_NIXIE ||
            rules::npcLanguageFor(66)
                != rules::NPC_LG_NYMPH ||
            rules::npcLanguageFor(67)
                != rules::NPC_LG_OGRISH ||
            rules::npcLanguageFor(71)
                != rules::NPC_LG_OGRE_MAGIAN ||
            rules::npcLanguageFor(72)
                != rules::NPC_LG_ORCISH ||
            rules::npcLanguageFor(77)
                != rules::NPC_LG_PIXIE ||
            rules::npcLanguageFor(78)
                != rules::NPC_LG_SALAMANDER ||
            rules::npcLanguageFor(79)
                != rules::NPC_LG_SATYR ||
            rules::npcLanguageFor(80)
                != rules::NPC_LG_SHEDU ||
            rules::npcLanguageFor(81)
                != rules::NPC_LG_SPRITE ||
            rules::npcLanguageFor(82)
                != rules::NPC_LG_SYLPH ||
            rules::npcLanguageFor(83)
                != rules::NPC_LG_TITAN ||
            rules::npcLanguageFor(84)
                != rules::NPC_LG_TROLL ||
            rules::npcLanguageFor(85)
                != rules::NPC_LG_XORN ||
            rules::npcLanguageFor(86)
                != rules::NPC_LG_HUMAN_FOREIGN ||
            rules::npcLanguageFor(100)
                != rules::NPC_LG_HUMAN_FOREIGN) ++bad;
        // the language clamps
        if (rules::npcLanguageFor(0)
                != rules::NPC_LG_BROWNIE ||
            rules::npcLanguageFor(101)
                != rules::NPC_LG_HUMAN_FOREIGN) ++bad;
        printf("R211 NPC body and language audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R212: the hire costs and non-human troops audit ----
    // DMG pp.116-118: the cleric spell
    // hire prices, the travel and risk
    // multipliers, the charm-opposite
    // rule, and the non-human troop
    // control percents.
    {
        int bad = 0;
        // the spell price table, every cell
        if (rules::hireSpellCount() != 40
            || rules::HS_COUNT != 40
            || rules::HS_GATE != 20
            || rules::HS_TRUE_SEEING != 39
            || rules::HU_FLAT != 0
            || rules::HU_PER_PERSON != 1
            || rules::HU_PER_CASTER_LEVEL != 2
            || rules::HU_PER_RECIPIENT_LEVEL != 3
            || rules::HU_PER_PERSON_PER_CASTER_LEVEL != 4
            || rules::HU_PER_POINT_HEALED != 5
            || rules::HU_BASE_PLUS_PER_QUESTION != 6
            || rules::HU_BASE_PLUS_PER_CASTER_LEVEL != 7
            || rules::HU_BASE_PLUS_PER_RECIPIENT_LEVEL != 8) ++bad;
        static const int kBase[40] = {
            0, 0, 300, 0, 1000, 500, 10000,
            1000, 1000, 100, 350, 600, 100,
            150, 1000, 0, 1000, 10000,
            0, 0, 50000, 0, 0, 1000, 0,
            4000, 0, 0, 100, 1000, 15000,
            0, 0, 0, 10000, 0, 0, 0, 500, 0,
        };
        static const int kUnit[40] = {
            1, 3, 0, 4, 6, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 0,
            2, 2, 0, 2, 5, 0, 2, 0, 2, 2,
            0, 7, 0, 2, 2, 2, 8, 2, 2, 2,
            0, 2,
        };
        static const int kRate[40] = {
            5000, 500, 0, 5, 500, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 100,
            0, 0,
            1000, 500, 0, 100, 200, 0,
            1000, 0, 50, 50, 0, 500, 0,
            500, 50, 100, 1000, 100, 200,
            100, 0, 400,
        };
        for (int s = 0; s < 40; ++s)
            if (rules::hireSpellBase(s) != kBase[s] ||
                rules::hireSpellUnit(s) != kUnit[s] ||
                rules::hireSpellRate(s) != kRate[s]) ++bad;
        // the unit semantics, one pin per
        // unit code
        if (rules::hireSpellUnit(rules::HS_AUGURY)
                != rules::HU_FLAT ||
            rules::hireSpellUnit(rules::HS_ASTRAL_SPELL)
                != rules::HU_PER_PERSON ||
            rules::hireSpellUnit(rules::HS_DISPEL_MAGIC)
                != rules::HU_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_ATONEMENT)
                != rules::HU_PER_RECIPIENT_LEVEL ||
            rules::hireSpellUnit(rules::HS_BLESS)
                != rules::HU_PER_PERSON_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_HEAL)
                != rules::HU_PER_POINT_HEALED ||
            rules::hireSpellUnit(rules::HS_COMMUNE)
                != rules::HU_BASE_PLUS_PER_QUESTION ||
            rules::hireSpellUnit(rules::HS_RAISE_DEAD)
                != rules::HU_BASE_PLUS_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_RESTORATION)
                != rules::HU_BASE_PLUS_PER_RECIPIENT_LEVEL) ++bad;
        // the sample prices, worked from
        // the print clauses
        if (rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                0, 1, 0, 0, 0) != 5000 ||
            rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                0, 4, 0, 0, 0) != 20000 ||
            rules::hireSpellCost(rules::HS_ATONEMENT,
                0, 0, 7, 0, 0) != 3500 ||
            rules::hireSpellCost(rules::HS_AUGURY,
                12, 3, 5, 2, 4) != 300 ||
            rules::hireSpellCost(rules::HS_BLESS,
                5, 6, 0, 0, 0) != 150 ||
            rules::hireSpellCost(rules::HS_COMMUNE,
                0, 0, 0, 3, 0) != 2500 ||
            rules::hireSpellCost(rules::HS_COMMUNE,
                0, 0, 0, 0, 0) != 1000 ||
            rules::hireSpellCost(rules::HS_DISPEL_MAGIC,
                11, 0, 0, 0, 0) != 1100 ||
            rules::hireSpellCost(rules::HS_EXORCISE,
                3, 0, 0, 0, 0) != 3000 ||
            rules::hireSpellCost(rules::HS_GATE,
                17, 9, 9, 9, 9) != 50000 ||
            rules::hireSpellCost(rules::HS_HEAL,
                0, 0, 0, 0, 15) != 3000 ||
            rules::hireSpellCost(rules::HS_HEAL,
                0, 0, 0, 0, 0) != 0 ||
            rules::hireSpellCost(rules::HS_RAISE_DEAD,
                9, 0, 0, 0, 0) != 5500 ||
            rules::hireSpellCost(rules::HS_RESTORATION,
                0, 0, 8, 0, 0) != 18000 ||
            rules::hireSpellCost(rules::HS_SLOW_POISON,
                12, 0, 0, 0, 0) != 2400 ||
            rules::hireSpellCost(rules::HS_TONGUES,
                9, 5, 5, 5, 5) != 500 ||
            rules::hireSpellCost(rules::HS_TRUE_SEEING,
                7, 0, 0, 0, 0) != 2800) ++bad;
        // the clamps: no input produces
        // negative gold, and the spell
        // index clamps to the first and
        // last rows
        if (rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                -3, -4, -5, -6, -7) != 0 ||
            rules::hireSpellCost(-9, 5, 5, 5, 5, 5)
                != rules::hireSpellCost(0, 5, 5, 5, 5, 5) ||
            rules::hireSpellCost(99, 5, 5, 5, 5, 5)
                != rules::hireSpellCost(39, 5, 5, 5, 5, 5)) ++bad;
        // the hiring clauses
        if (rules::hireTravelNotAtRiskFactor() != 2 ||
            rules::hireAtRiskFactor() != 5 ||
            rules::hireRiskRefusalPossible() != 1 ||
            rules::hireCharmOppositePercent() != 25 ||
            rules::hireAttackSpellEntriesPriced() != 0 ||
            rules::hireHiredCastersAccompanyParty() != 0 ||
            rules::hireInterruptRaisesRates() != 1) ++bad;
        // the troop control table, every cell
        if (rules::troopRaceCount() != 7
            || rules::TR_TROOP_COUNT != 7
            || rules::TR_BUGBEAR != 0
            || rules::TR_ORC != 6) ++bad;
        static const int kCtrl[21] = {
            30, 50, 80,
            30, 40, 80,
            40, 50, 90,
            20, 40, 90,
            25, 50, 95,
            10, 60, 100,
            20, 50, 90,
        };
        for (int r = 0; r < 7; ++r)
            for (int c = 0; c < 3; ++c)
                if (rules::troopControlPercent(r, c)
                        != kCtrl[r * 3 + c]) ++bad;
        // the troop clamps and edge cases
        if (rules::troopControlPercent(
                rules::TR_LIZARDMAN, 2) != 100 ||
            rules::troopControlPercent(
                rules::TR_BUGBEAR, 0) != 30 ||
            rules::troopControlPercent(
                rules::TR_KOBOLD, 2) != 95 ||
            rules::troopControlPercent(
                rules::TR_GNOLL, 1) != 40 ||
            rules::troopControlPercent(
                rules::TR_HOBGOBLIN, 0) != 20 ||
            rules::troopControlPercent(
                rules::TR_GOBLIN, 2) != 90 ||
            rules::troopControlPercent(
                rules::TR_ORC, 1) != 50 ||
            rules::troopControlPercent(-1, 1)
                != rules::troopControlPercent(0, 1) ||
            rules::troopControlPercent(7, 1)
                != rules::troopControlPercent(6, 1) ||
            rules::troopControlPercent(3, -2)
                != rules::troopControlPercent(3, 0) ||
            rules::troopControlPercent(3, 9)
                != rules::troopControlPercent(3, 2)) ++bad;
        // the troop clauses
        if (rules::troopFightsFriendlyHumansPercent() != 25 ||
            rules::troopWeakLeaderWithOfficersPossible() != 0 ||
            rules::troopHighPayViewedAsWeakness() != 1 ||
            rules::demiHumanTroopsServeHumanMaster() != 0) ++bad;
        printf("R212 hire costs and non-human troops audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R213: the construction and siege economics audit ----
    // DMG pp.106-108: the mining tables,
    // the construction time pins, the
    // constructions cost table, and the
    // siege engine costs.
    {
        int bad = 0;
        // the mining table: every cell
        if (rules::miningGroupCount() != 8
            || rules::MG_COUNT != 8
            || rules::MG_GNOLL_HALFLING_HUMAN != 0
            || rules::MG_STONE_GIANT != 7
            || rules::MRK_VERY_SOFT != 0
            || rules::MRK_SOFT != 1
            || rules::MRK_HARD != 2) ++bad;
        static const int kMine[24] = {
            75, 50, 25,
            80, 60, 30,
            85, 65, 30,
            90, 70, 35,
            150, 100, 50,
            250, 150, 75,
            300, 200, 100,
            500, 350, 175,
        };
        for (int g = 0; g < 8; ++g)
            for (int r = 0; r < 3; ++r)
                if (rules::miningCubicFeetPer8h(g, r)
                        != kMine[g * 3 + r]) ++bad;
        if (rules::miningCubicFeetPer8h(
                rules::MG_STONE_GIANT, rules::MRK_HARD)
                != 175 ||
            rules::miningCubicFeetPer8h(0, 0) != 75 ||
            rules::miningCubicFeetPer8h(-5, 9) != 25) ++bad;
        // the multiple-workers volume: linear
        if (rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, 3)
                != 450 ||
            rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, 0)
                != 0 ||
            rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, -7)
                != 0 ||
            rules::miningVolumeCubicFeet(
                rules::MG_OGRE, rules::MRK_VERY_SOFT, 4)
                != 600) ++bad;
        // the shaft capacity and the shifts
        if (rules::SG_COUNT != 5
            || rules::SG_SMALL != 0
            || rules::SG_MAN != 1
            || rules::SG_GNOLL != 2
            || rules::SG_OGRE != 3
            || rules::SG_GIANT_ANY != 4) ++bad;
        static const int kShaft[5] = { 16, 12, 8, 6, 4 };
        for (int s = 0; s < 5; ++s)
            if (rules::shaftMaxMiners(s) != kShaft[s]) ++bad;
        if (rules::shaftMaxMiners(-1) != 16 ||
            rules::shaftMaxMiners(9) != 4 ||
            rules::shaftWidthFeet() != 10 ||
            rules::shaftPeakFeet() != 16 ||
            rules::constructionHoursPerDay() != 24 ||
            rules::workerMaxHoursPerDay() != 8 ||
            rules::maxShiftsPerDay() != 3) ++bad;
        // the natural cave area chances
        static const int kNat[4] = { 10, 2, 5, 1 };
        for (int r = 0; r < 4; ++r)
            if (rules::naturalCaveChancePct(r)
                    != kNat[r]) ++bad;
        if (rules::NR_COUNT != 4 ||
            rules::NR_LIMESTONE_VERY_SOFT != 0 ||
            rules::NR_OTHER_SEDIMENTARY_SOFT != 1 ||
            rules::NR_LAVA_HARD != 2 ||
            rules::NR_OTHER_IGNEOUS_HARD != 3 ||
            rules::naturalCaveChancePct(-3) != 10 ||
            rules::naturalCaveChancePct(9) != 1) ++bad;
        // the slave or unwilling labor
        if (rules::slaveGuardPerWorkers() != 4 ||
            rules::slaveEfficiencyMinPct() != 50 ||
            rules::slaveEfficiencyMaxPct() != 80 ||
            rules::slaveEfficiencyPct(16) != 50 ||
            rules::slaveEfficiencyPct(20) != 50 ||
            rules::slaveEfficiencyPct(12) != 60 ||
            rules::slaveEfficiencyPct(15) != 60 ||
            rules::slaveEfficiencyPct(10) != 70 ||
            rules::slaveEfficiencyPct(8) != 70 ||
            rules::slaveEfficiencyPct(5) != 80 ||
            rules::slaveEfficiencyPct(4) != 80 ||
            rules::slaveEfficiencyPct(1) != 80 ||
            rules::slaveEfficiencyPct(0) != 80 ||
            rules::slaveEfficiencyPct(-3) != 80) ++bad;
        // the construction time pins
        if (rules::ditchCrewMin() != 3 ||
            rules::ditchCrewMax() != 4 ||
            rules::ditchWeeks() != 6 ||
            rules::heavyClayTimeFactor() != 2 ||
            rules::stoneFortressWeeksPer10FootCube() != 1 ||
            rules::stoneRateFactor(100) != 1 ||
            rules::stoneRateFactor(149) != 1 ||
            rules::stoneRateFactor(150) != 2 ||
            rules::stoneRateFactor(200) != 2 ||
            rules::stoneRateFactor(249) != 2 ||
            rules::stoneRateFactor(250) != 3 ||
            rules::stoneRateFactor(400) != 3 ||
            rules::stoneRateFactor(-5) != 1 ||
            rules::stoneBuildingMonths() != 4 ||
            rules::woodBuildingMonths() != 2 ||
            rules::hoardingsFeetPerDay() != 10) ++bad;
        // the castle estimates
        if (rules::CK_COUNT != 4 ||
            rules::CK_MOAT_HOUSE_SHELL_KEEP_SMALL != 0 ||
            rules::CK_LARGE_CONCENTRIC_WALLING_TOWN != 3) ++bad;
        static const int kYears[4] = { 1, 2, 3, 5 };
        static const int kMoLo[4] = { 2, 1, 2, 1 };
        static const int kMoHi[4] = { 8, 6, 8, 12 };
        for (int k = 0; k < 4; ++k)
            if (rules::castleYears(k) != kYears[k] ||
                rules::castleExtraMonthsMin(k) != kMoLo[k] ||
                rules::castleExtraMonthsMax(k) != kMoHi[k]) ++bad;
        if (rules::citizenLaborTimePct() != 50) ++bad;
        // the constructions cost table: every
        // row
        if (rules::constructionItemCount() != 44
            || rules::CI_COUNT != 44
            || rules::CI_ARROW_SLIT != 0
            || rules::CI_WINDOW_SHUTTERED_BARRED != 43
            || rules::CI_BARBICAN != 2
            || rules::CI_WALL_CURTAIN != 41
            || rules::CI_TOWER_ROUND_20 != 33) ++bad;
        static const int kCost[44] = {
            3, 5, 4000, 300, 50, 20, 500,
            200, 15, 10, 100, 100, 50, 2, 10,
            25, 400, 3, 2000, 10,
            100, 6, 10, 250, 10, 100, 10, 25,
            4, 500, 100, 50, 10,
            850, 1350, 1600, 600, 900, 1200,
            100, 500, 1000, 7, 10,
        };
        for (int i = 0; i < 44; ++i)
            if (rules::constructionCost(i) != kCost[i]) ++bad;
        if (rules::constructionCost(rules::CI_BARBICAN)
                != 4000 ||
            rules::constructionCost(rules::CI_GATEHOUSE_STONE)
                != 2000 ||
            rules::constructionCost(rules::CI_TOWER_ROUND_20)
                != 850 ||
            rules::constructionCost(rules::CI_WALL_CURTAIN)
                != 1000 ||
            rules::constructionCost(rules::CI_PORTCULLIS)
                != 500 ||
            rules::constructionCost(rules::CI_BUILDING_STONE)
                != 500 ||
            rules::constructionCost(rules::CI_BUILDING_WOOD)
                != 200 ||
            rules::constructionCost(rules::CI_MURDER_HOLE)
                != 10 ||
            rules::constructionCost(rules::CI_PIT)
                != 4 ||
            rules::constructionCost(rules::CI_DOOR_TRAP)
                != 2 ||
            rules::constructionCost(
                rules::CI_WINDOW_SHUTTERED) != 7) ++bad;
        if (rules::constructionCost(-3)
                != rules::constructionCost(0) ||
            rules::constructionCost(99)
                != rules::constructionCost(43)) ++bad;
        // the per-square-foot adjustments
        if (rules::doorIronAdjustGpPerSqFt() != 2 ||
            rules::doorSecretLargerGpPerSqFt() != 5 ||
            rules::doorTrapAdjustSpPerSqFt() != 1 ||
            rules::doorWoodenAdjustSpPerSqFt() != 2 ||
            rules::doorReinforcedAdjustSpPerSqFt() != 5 ||
            rules::drawbridgeAdjustGpPerSqFt() != 2 ||
            rules::portcullisAdjustGpPerSqFt() != 2) ++bad;
        // the stone course formula
        if (rules::buildingStoneCoursePct() != 10 ||
            rules::buildingStoneCostCourses(500, 1) != 500 ||
            rules::buildingStoneCostCourses(500, 10) != 950 ||
            rules::buildingStoneCostCourses(500, 2) != 550 ||
            rules::buildingStoneCostCourses(200, 3) != 240 ||
            rules::buildingStoneCostCourses(500, 0) != 500 ||
            rules::buildingStoneCostCourses(500, -4) != 500) ++bad;
        // the tunnel ground factors
        if (rules::TG_COUNT != 3 ||
            rules::TG_SOFT_EARTH != 0 ||
            rules::TG_HARD_EARTH != 1 ||
            rules::TG_SOLID_ROCK != 2 ||
            rules::tunnelCostFactor(0) != 1 ||
            rules::tunnelCostFactor(1) != 2 ||
            rules::tunnelCostFactor(2) != 5 ||
            rules::tunnelCostFactor(9) != 5 ||
            rules::tunnelCostFactor(-1) != 1) ++bad;
        // the combination clauses
        if (rules::rampartAboveDitchCostPct() != 20 ||
            rules::battlementSectionFeet() != 14 ||
            rules::battlementMerlons() != 2 ||
            rules::battlementMerlonWidthFeet() != 4 ||
            rules::battlementEmbrasures() != 2 ||
            rules::battlementEmbrasureWidthFeet() != 3 ||
            rules::buttressSectionsPer20Feet() != 3) ++bad;
        // the siege engine costs
        if (rules::siegeDeviceCount() != 12
            || rules::SD_COUNT != 12
            || rules::SD_BALLISTA != 0
            || rules::SD_TREBUCHET != 11) ++bad;
        static const int kEng[12] = {
            75, 200, 150, 50, 350, 150,
            15, 500, 20, 800, 500, 500,
        };
        for (int d = 0; d < 12; ++d)
            if (rules::siegeDeviceCost(d) != kEng[d]) ++bad;
        if (rules::siegeDeviceCost(rules::SD_BALLISTA) != 75 ||
            rules::siegeDeviceCost(rules::SD_TREBUCHET)
                != 500 ||
            rules::siegeDeviceCost(rules::SD_SIEGE_TOWER)
                != 800 ||
            rules::siegeDeviceCost(rules::SD_MANTLET)
                != 15 ||
            rules::siegeDeviceCost(-1)
                != rules::siegeDeviceCost(0) ||
            rules::siegeDeviceCost(12)
                != rules::siegeDeviceCost(11)) ++bad;
        printf("R213 construction and siege economics audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R214: the war machine fire and siege values audit ----
    // DMG pp.108-110: the fire table, the hit
    // determination modifiers, the siege
    // attack matrix, and the defensive
    // values.
    {
        int bad = 0;
        // the fire table: every device cell
        if (rules::fireDeviceCount() != 6
            || rules::FD_COUNT != 6
            || rules::FD_BALLISTA != 0
            || rules::FD_TREBUCHET != 5
            || rules::SM_WOOD != 0
            || rules::SM_EARTH != 1
            || rules::SM_SOFT_STONE != 2
            || rules::SM_HARD_ROCK != 3) ++bad;
        static const int kFof[6] = { 45, 15, 30, 0, 0, 10 };
        static const int kRMin[6] = { 1, 72, 60, 0, 0, 96 };
        static const int kRMax[6] = { 128, 144, 120, 1, 1, 192 };
        static const int kSmMin[6] = { 2, 2, 2, 9, 9, 3 };
        static const int kSmMax[6] = { 12, 24, 20, 16, 16, 30 };
        static const int kLMin[6] = { 3, 4, 3, 7, 13, 5 };
        static const int kLMax[6] = { 18, 16, 12, 12, 24, 20 };
        static const int kRoMin[6] = { 25, 25, 25, 50, 50, 25 };
        static const int kRoMax[6] = { 50, 25, 25, 50, 50, 25 };
        static const int kCrMin[6] = { 2, 6, 4, 10, 10, 8 };
        static const int kCrMax[6] = { 4, 10, 6, 20, 20, 12 };
        for (int d = 0; d < 6; ++d)
            if (rules::siegeFieldOfFireDegrees(d)
                    != kFof[d] ||
                rules::siegeRangeMinQuarterInches(d)
                    != kRMin[d] ||
                rules::siegeRangeMaxQuarterInches(d)
                    != kRMax[d] ||
                rules::siegeDamageSMMin(d) != kSmMin[d] ||
                rules::siegeDamageSMMax(d) != kSmMax[d] ||
                rules::siegeDamageLMin(d) != kLMin[d] ||
                rules::siegeDamageLMax(d) != kLMax[d] ||
                rules::siegeRateOfFireMinHundredths(d)
                    != kRoMin[d] ||
                rules::siegeRateOfFireMaxHundredths(d)
                    != kRoMax[d] ||
                rules::siegeCrewMin(d) != kCrMin[d] ||
                rules::siegeCrewMax(d) != kCrMax[d]) ++bad;
        if (rules::siegeFieldOfFireDegrees(
                rules::FD_BALLISTA) != 45 ||
            rules::siegeFieldOfFireDegrees(
                rules::FD_RAM) != 0 ||
            rules::siegeRangeMinQuarterInches(
                rules::FD_BALLISTA) != 1 ||
            rules::siegeRangeMaxQuarterInches(
                rules::FD_BALLISTA) != 128 ||
            rules::siegeRangeMaxQuarterInches(
                rules::FD_TREBUCHET) != 192) ++bad;
        if (rules::siegeFieldOfFireDegrees(-3) != 45 ||
            rules::siegeRangeMaxQuarterInches(9) != 192 ||
            rules::siegeCrewMin(-1) != 2 ||
            rules::siegeCrewMax(12) != 12) ++bad;
        // the crew rules
        if (rules::siegeBelowMinCrewRatePct() != 50 ||
            rules::siegeBallistaMaxCrewRateFactor() != 2 ||
            rules::siegeOtherMaxCrewRateFactor() != 1) ++bad;
        // the hit determination conventions
        if (rules::wmHitTargetAc() != 0 ||
            rules::wmBallistaTargetAc() != 10) ++bad;
        // the d20 modifiers
        if (rules::wmModTargetStationary() != 3 ||
            rules::wmModMoveUnder3() != 0 ||
            rules::wmModMove3to12() != -3 ||
            rules::wmModSizeMan() != -2 ||
            rules::wmModSizeHorse() != 0 ||
            rules::wmModSizeGiant() != 2 ||
            rules::wmModSizeMediumBuilding() != 4 ||
            rules::wmModSizeLargeBuilding() != 6 ||
            rules::wmModSubsequentStationary() != 4 ||
            rules::wmWeatherCalm() != 1 ||
            rules::wmWeatherBreeze() != 0 ||
            rules::wmWeatherStrong() != -2 ||
            rules::wmWeatherStorm() != -4 ||
            rules::wmDirectFireBonus() != 4) ++bad;
        // the trajectory and cover rules
        if (rules::wmBallistaInterveningBlocks() != 1 ||
            rules::wmCatapultInterveningBlocks() != 0 ||
            rules::wmBallistaUnseenFirePossible() != 0 ||
            rules::wmUnseenScatterGrenadeRule() != 1 ||
            rules::wmGrenadeDiameterSmallCatFeet() != 1 ||
            rules::wmGrenadeDiameterTrebuchetFeet() != 2) ++bad;
        // the siege attack matrix: every cell
        if (rules::siegeAttackKindCount() != 22
            || rules::SK_COUNT != 22
            || rules::SK_BIGBY_FIST != 0
            || rules::SK_TREBUCHET_MISSILE != 21
            || rules::SK_HORN_OF_BLASTING != 15
            || rules::SK_EARTHQUAKE != 6) ++bad;
        static const int kQ[88] = {
            4, 0, 2, 1,
            24, 0, 16, 8,
            16, 0, 8, 4,
            0, 40, 0, 0,
            8, 8, 8, 8,
            8, 40, 8, 4,
            0, 0, 0, 0,
            2, 0, 0, 0,
            12, 0, 4, 2,
            8, 0, 4, 2,
            4, 0, 2, 1,
            16, 0, 8, 4,
            24, 0, 16, 8,
            12, 4, 8, 4,
            12, 4, 4, 2,
            72, 24, 32, 16,
            2, 0, 0, 0,
            0, 80, 0, 0,
            4, 0, 1, 0,
            2, 2, 2, 1,
            32, 8, 8, 4,
            32, 0, 20, 12,
        };
        for (int k = 0; k < 22; ++k)
            for (int m = 0; m < 4; ++m)
                if (rules::siegeAttackQuarterPoints(k, m)
                        != kQ[k * 4 + m]) ++bad;
        // the per-round and per-level flags
        static const int kP[22] = {
            1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
            1, 0, 0, 1, 1, 0, 0, 0, 1, 1,
            1, 0,
        };
        static const int kLv[22] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0,
        };
        for (int k = 0; k < 22; ++k)
            if (rules::siegeAttackPerRound(k)
                    != kP[k] ||
                rules::siegeAttackPerCasterLevel(k)
                    != kLv[k]) ++bad;
        if (rules::siegeAttackPerCasterLevel(
                rules::SK_FIREBALL) != 1 ||
            rules::siegeAttackPerCasterLevel(
                rules::SK_LIGHTNING_BOLT) != 1 ||
            rules::siegeAttackPerRound(
                rules::SK_HORN_OF_BLASTING) != 0 ||
            rules::siegeAttackPerRound(
                rules::SK_TREANT) != 1 ||
            rules::siegeFireDamageWetReductionPct()
                != 50 ||
            rules::siegeSowScrewEarthOnly() != 1 ||
            rules::siegeSoftStoneIncludes() != 1) ++bad;
        // the spot cells
        if (rules::siegeAttackQuarterPoints(
                rules::SK_BIGBY_FIST, rules::SM_WOOD)
                != 4 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_HORN_OF_BLASTING,
                rules::SM_HARD_ROCK) != 16 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_DIG, rules::SM_EARTH) != 40 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_MOVE_EARTH, rules::SM_EARTH)
                != 80 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_RAM, rules::SM_SOFT_STONE)
                != 1 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_TREBUCHET_MISSILE,
                rules::SM_SOFT_STONE) != 20) ++bad;
        if (rules::siegeAttackQuarterPoints(-9, 0)
                != rules::siegeAttackQuarterPoints(0, 0) ||
            rules::siegeAttackQuarterPoints(99, 3)
                != rules::siegeAttackQuarterPoints(21, 3)) ++bad;
        // the earthquake dice rows
        static const int kQkMin[4] = { 5, 5, 5, 5 };
        static const int kQkMax[4] = { 60, 30, 60, 30 };
        for (int m = 0; m < 4; ++m)
            if (rules::siegeAttackQuakeMin(m)
                    != kQkMin[m] ||
                rules::siegeAttackQuakeMax(m)
                    != kQkMax[m]) ++bad;
        if (rules::siegeAttackQuakeMin(-3) != 5 ||
            rules::siegeAttackQuakeMax(9) != 30) ++bad;
        // the construction defensive values
        if (rules::defensiveKindCount() != 26
            || rules::DK_COUNT != 26
            || rules::DK_BARBICAN != 0
            || rules::DK_WINDOW_BARRED != 25
            || rules::DK_TOWER_ROUND != 20
            || rules::DK_WALL_CURTAIN != 23) ++bad;
        static const int kDMin[26] = {
            150, 25, 20, 12, 10, 8, 20, 10,
            1, 3, 10, 8, 120, 2, 10, 6,
            20, 15, 12, 20, 40, 30, 40, 20,
            4, 12,
        };
        static const int kDMax[26] = {
            150, 25, 20, 12, 10, 16, 20, 10,
            1, 3, 15, 12, 120, 2, 10, 12,
            20, 15, 12, 20, 80, 50, 40, 20,
            4, 12,
        };
        for (int k = 0; k < 26; ++k)
            if (rules::constructionDefensiveMin(k)
                    != kDMin[k] ||
                rules::constructionDefensiveMax(k)
                    != kDMax[k]) ++bad;
        if (rules::constructionDefensiveMin(
                rules::DK_BUILDING_WOOD) != 8 ||
            rules::constructionDefensiveMax(
                rules::DK_BUILDING_WOOD) != 16 ||
            rules::constructionDefensiveMax(
                rules::DK_TOWER_ROUND) != 80 ||
            rules::constructionDefensiveMax(
                rules::DK_TOWER_SQUARE) != 50 ||
            rules::constructionDefensiveMin(
                rules::DK_GATEHOUSE) != 120) ++bad;
        if (rules::constructionDefensiveMin(-3)
                != rules::constructionDefensiveMin(0) ||
            rules::constructionDefensiveMax(99)
                != rules::constructionDefensiveMax(25)) ++bad;
        // the defensive footnotes
        if (rules::dkBarbicanExcludesGates() != 1 ||
            rules::dkSupportsFallFirst() != 1 ||
            rules::dkRampartUnaffectedByMissiles() != 1 ||
            rules::dkCurtainWallThicknessFeet() != 10 ||
            rules::dkCurtainWallBreachAreaFeet() != 10) ++bad;
        // the device MHP (the R213 device enum)
        static const int kMhp[12] = {
            2, 6, 4, 2, 10, 4,
            3, 12, 0, 16, 12, 8,
        };
        for (int d = 0; d < 12; ++d)
            if (rules::siegeDeviceMhp(d) != kMhp[d]) ++bad;
        if (rules::siegeDeviceMhp(rules::SD_BALLISTA) != 2 ||
            rules::siegeDeviceMhp(rules::SD_SIEGE_TOWER)
                != 16 ||
            rules::siegeDeviceMhp(rules::SD_RAM_CATCHER)
                != 0 ||
            rules::siegeDeviceMhp(-1) != 2 ||
            rules::siegeDeviceMhp(12) != 8) ++bad;
        // the additional attack forms
        if (rules::miningBreachCurtainFeet() != 10 ||
            rules::miningBreachDamagePoints() != 10 ||
            rules::sappingDamagePerTurn() != 1) ++bad;
        printf("R214 war machine fire and siege values audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R215: the conducting the game pins audit ----
    // DMG pp.110-112: the divine intervention
    // procedure, the planes rule, the secret
    // rolls, the system shock clause, the
    // integration numbers, the multiple
    // characters rules, the troublesome
    // measures.
    {
        int bad = 0;
        // the divine intervention procedure
        if (rules::deityCreatureSentFirstAskPct() != 10 ||
            rules::deityComeChancePct(12) != 12 ||
            rules::deityComeChancePct(0) != 0 ||
            rules::deityComeChancePct(-5) != 0) ++bad;
        if (rules::deityModEachPreviousIntervention() != -5 ||
            rules::deityModAlignmentMedial() != -5 ||
            rules::deityModAlignmentBorderline() != -10 ||
            rules::deityModDirectConfrontation() != -10 ||
            rules::deityModOpposingDiametric() != 1 ||
            rules::deityModServingProximately() != 25) ++bad;
        if (rules::deityInterventionPct(10, 0, 0, 0, 0, 0, 0)
                != 10 ||
            rules::deityInterventionPct(10, 1, 0, 0, 0, 0, 0)
                != 5 ||
            rules::deityInterventionPct(10, 2, 0, 0, 0, 0, 0)
                != 0 ||
            rules::deityInterventionPct(
                10, 1, 1, 1, 1, 0, 0) != -20 ||
            rules::deityInterventionPct(
                10, 0, 0, 0, 0, 1, 1) != 36 ||
            rules::deityInterventionPct(20, 1, 1, 1, 1, 1, 1) != 16 ||
            rules::deityInterventionPct(
                5, 9, 9, 9, 9, 9, 9) != -39 ||
            rules::deityInterventionPct(
                -3, 0, 0, 0, 0, 0, 0) != 0) ++bad;
        // the planes rule
        if (rules::IP_COUNT != 7
            || rules::IP_PRIME_MATERIAL != 0
            || rules::IP_ELEMENTAL != 3
            || rules::IP_OUTER != 4
            || rules::IP_POSITIVE != 5
            || rules::IP_NEGATIVE != 6) ++bad;
        static const int kPlane[7] = { 1, 1, 1, 2, 0, 0, 0 };
        for (int p = 0; p < 7; ++p)
            if (rules::interventionPlaneAllowed(p)
                    != kPlane[p]) ++bad;
        if (rules::interventionPlaneAllowed(-3) != 1 ||
            rules::interventionPlaneAllowed(9) != 0 ||
            rules::elementalGodsBlockOuterDeities() != 1) ++bad;
        // the secret rolls and the system shock clause
        if (rules::secretRollKindCount() != 7
            || rules::SR_COUNT != 7
            || rules::SR_LISTENING != 0
            || rules::SR_ATTACKS_WITHOUT_KNOWLEDGE != 6) ++bad;
        for (int k = -1; k < 8; ++k)
            if (rules::rollIsSecretAlways(k) != 1) ++bad;
        if (rules::systemShockRollNeverTampered() != 1 ||
            rules::systemShockFailureForeverDead() != 1) ++bad;
        // the integration numbers
        if (rules::integrationAveragingDieMin() != 2 ||
            rules::integrationAveragingDieMax() != 5 ||
            rules::integrationAverageWorksUpToLevel() != 8 ||
            rules::integrationAboveCeilingStartLevel() != 4 ||
            rules::neophyteFullCoopLevel() != 3) ++bad;
        // the multiple characters rules
        if (rules::multipleCharactersProhibited() != 0 ||
            rules::multipleCharactersFreeInterchange()
                != 0) ++bad;
        // the troublesome-player measures
        if (rules::troublesomeCharismaLossPoints() != 1 ||
            rules::etherealMummyAlwaysSurprise() != 1) ++bad;
        printf("R215 conducting the game pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R216: the magical research pins audit ----
    // DMG pp.114-119: the holy/unholy water
    // receptacles, the spell research
    // economics and chance, the manufacture
    // gates, and the potion rules.
    {
        int bad = 0;
        // the receptacles: 5 metals
        static const int kCap[5] = { 6, 10, 18, 32, 50 };
        static const int kBMin[5] = { 130, 1900, 8000, 19000, 110000 };
        static const int kBMax[5] = { 180, 2400, 12000, 22000, 200000 };
        static const int kFont[5] = { 200, 500, 1000, 1500, 2000 };
        for (int m = 0; m < 5; ++m)
            if (rules::receptVialCapacity(m) != kCap[m] ||
                rules::receptBasinCostMin(m) != kBMin[m] ||
                rules::receptBasinCostMax(m) != kBMax[m] ||
                rules::receptFontCost(m) != kFont[m]) ++bad;
        if (rules::receptVialCapacity(-3) != 6 ||
            rules::receptVialCapacity(9) != 50 ||
            rules::receptBasinCostMin(4) != 110000 ||
            rules::receptBasinCostMax(4) != 200000 ||
            rules::receptFontCost(4) != 2000) ++bad;
        // mixed metals interpolate capacity
        if (rules::receptMixedCapacity(0, 1, 50) != 8 ||
            rules::receptMixedCapacity(0, 1, 100) != 6 ||
            rules::receptMixedCapacity(0, 1, 0) != 10 ||
            rules::receptMixedCapacity(2, 3, 50) != 25) ++bad;
        // the vials, weeks and limits
        if (rules::receptVialCostMin() != 2 ||
            rules::receptVialCostMax() != 5 ||
            rules::receptFontWeeksMin() != 4 ||
            rules::receptFontWeeksMax() != 10) ++bad;
        if (rules::receptCreationsPerWeek() != 1 ||
            rules::receptRitualHoursRest() != 8 ||
            rules::receptFontsPerEdifice() != 1) ++bad;
        if (rules::receptDefilementMinPct() != 20 ||
            rules::receptDefilementMaxPct() != 50 ||
            rules::receptDefilementWeeksMin() != 4 ||
            rules::receptDefilementWeeksMax() != 6) ++bad;
        if (rules::receptLycanthropyDelayMin() != 1 ||
            rules::receptLycanthropyDelayMax() != 4) ++bad;
        // the spell research economics
        if (rules::researchBaseCostPerLevelWeek() != 200 ||
            rules::researchVarCostMin() != 100 ||
            rules::researchVarCostMax() != 400 ||
            rules::researchNoLibraryFactor() != 10) ++bad;
        if (rules::researchWeeklyCost(3, 100, 1) != 900 ||
            rules::researchWeeklyCost(1, 400, 1) != 600 ||
            rules::researchWeeklyCost(2, 100, 0) != 4200) ++bad;
        if (rules::researchMinWeeks(1) != 2 ||
            rules::researchMinWeeks(9) != 10) ++bad;
        // the research chance: base 10-50 by
        // extra gp, + INT + level - 2 x SL
        if (rules::researchChancePct(12, 5, 3, 0) != 21 ||
            rules::researchChancePct(12, 5, 3, 2000) != 31 ||
            rules::researchChancePct(12, 5, 3, 8000) != 61 ||
            rules::researchChancePct(12, 5, 3, 20000) != 61 ||
            rules::researchChancePct(16, 9, 9, 8000) != 57) ++bad;
        if (rules::researchInterruptionWeeksLost(3) != 3 ||
            rules::researchInterruptionWeeksLost(-4) != 0 ||
            rules::researchHoursPerDay() != 8) ++bad;
        if (rules::researchImpossibleBeyondMuLevel() != 9 ||
            rules::researchImpossibleBeyondClericLevel() != 7) ++bad;
        if (rules::researchComboSpellLevel(2, 3) != 6 ||
            rules::researchLibraryGatherWeeks(4) != 4) ++bad;
        // the manufacture gates
        if (rules::manufactureClericLevel() != 11 ||
            rules::manufactureWizardLevel() != 12 ||
            rules::manufactureIllusionistLevel() != 11) ++bad;
        if (rules::playersMakeBooksArtifactsRelics() != 0 ||
            rules::playersMakeDwarvenElvenSpecials() != 0) ++bad;
        // the potion rules
        if (rules::potionMinLevelWithAlchemist() != 7 ||
            rules::potionAlchemistOptionalLevel() != 11 ||
            rules::potionAlchemistReductionPct() != 50 ||
            rules::potionsAtATime() != 1) ++bad;
        if (rules::potionLabCostMin() != 200 ||
            rules::potionLabCostMax() != 1000 ||
            rules::potionLabUpkeepPctMonthly() != 10) ++bad;
        if (rules::potionCostGp(250) != 250 ||
            rules::potionDays(250) != 3 ||
            rules::potionCostGp(0) != 200 ||
            rules::potionDays(0) != 2 ||
            rules::potionDays(101) != 2 ||
            rules::potionDays(100) != 1) ++bad;
        if (rules::potionAssassinPoisonLevel() != 9 ||
            rules::potionDelusionFailureMinPct() != 5 ||
            rules::potionDelusionFailureMaxPct() != 20) ++bad;
        printf("R216 magical research pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R217: the scroll manufacture and fabrication pins audit ----
    // DMG pp.118-121: the scroll inscription
    // rules and failure chance, and the
    // fabrication of other magic items.
    {
        int bad = 0;
        // the inscription gates
        if (rules::scrollMinInscribeLevel() != 7 ||
            rules::inscriberClassCount() != 4 ||
            rules::spellMustBeEmployable() != 1) ++bad;
        // the protection scroll split
        if (rules::PS_COUNT != 8 ||
            rules::PS_UNDEAD != 2 ||
            rules::PS_DEMONS != 3 ||
            rules::PS_PETRIFICATION != 7) ++bad;
        if (rules::protectionClericalCount() != 3 ||
            rules::protectionMuCount() != 5 ||
            rules::curseScrollsAnySpellUser() != 1) ++bad;
        for (int k = -1; k < 9; ++k)
            if (rules::protectionScrollIsClerical(k)
                    != ((k > 2) ? 0 : 1)) ++bad;
        // the materials
        if (rules::SCM_COUNT != 3) ++bad;
        static const int kMatCost[3] = { 2, 4, 8 };
        static const int kMatMod[3] = { 5, 0, -5 };
        for (int m = 0; m < 3; ++m)
            if (rules::scrollSheetCostMin(m) != kMatCost[m] ||
                rules::scrollMaterialFailMod(m) != kMatMod[m]) ++bad;
        if (rules::scrollSheetCostMin(-2) != 2 ||
            rules::scrollSheetCostMin(9) != 8) ++bad;
        if (rules::quillPerSpell() != 1 ||
            rules::quillNamedCreatures() != 6 ||
            rules::inkBaseCount() != 2 ||
            rules::inkPerSpellDistinct() != 1) ++bad;
        // the preparation and failure rules
        if (rules::scrollPrepDays(1) != 1 ||
            rules::scrollPrepDays(2) != 2 ||
            rules::scrollPrepDays(7) != 7 ||
            rules::prepMustBeContinuous() != 1) ++bad;
        if (rules::scrollFailurePct(7, 14, 1) != 13 ||
            rules::scrollFailurePct(1, 1, 1) != 20 ||
            rules::scrollFailurePct(1, 7, 1) != 14 ||
            rules::scrollFailurePct(9, 7, 1) != 22 ||
            rules::scrollFailurePct(1, 7, 0) != 19 ||
            rules::scrollFailurePct(1, 7, 2) != 9) ++bad;
        if (rules::scrollSuccessRollIsGreaterThan() != 1 ||
            rules::scrollMaxSpells() != 7 ||
            rules::oneFailureBlocksFurther() != 1) ++bad;
        // transcribing an unknown spell
        if (rules::transcribeNeedsReadMagic() != 1 ||
            rules::transcribeDays(4) != 4 ||
            rules::transcribeEraseFromScroll() != 1 ||
            rules::ownScrollsNeedNoReadMagic() != 1) ++bad;
        // the fabrication of other magic items
        if (rules::fabricateNeedsEnchantAnItem() != 1 ||
            rules::fabricateClericalUsesEnchant() != 0) ++bad;
        if (rules::fabRestDays(2000) != 20 ||
            rules::fabRestDays(100) != 1 ||
            rules::fabRestDays(101) != 2 ||
            rules::fabRestDays(250) != 3 ||
            rules::fabRestDays(-5) != 0 ||
            rules::fabRestNoAdventuringOrSpells() != 1) ++bad;
        if (rules::permanentDweomerNeedsPermanency() != 1 ||
            rules::chargedItemsNeedPermanency() != 0) ++bad;
        // the cleric and druid retreat
        if (rules::clericRetreatDays() != 14 ||
            rules::clericFastDays() != 7 ||
            rules::clericPurifyDays() != 1 ||
            rules::clericEmpowerPctPerDay() != 1 ||
            rules::clericChargedSpellWindowHours() != 24) ++bad;
        // the illusionist gates
        if (rules::illusionistScrollLevel() != 7 ||
            rules::illusionistOneShotChargedLevel() != 11 ||
            rules::illusionistPermanentDweomerLevel() != 14 ||
            rules::illusionistMajorCreationInstillHours() != 16 ||
            rules::illusionistPermanentGemCost() != 10000) ++bad;
        // the charmed or enslaved maker rule
        if (rules::enslavedMakerCanFabricate() != 0) ++bad;
        printf("R217 scroll manufacture and fabrication pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R218: the use of magic items and energy draining pins audit ----
    // DMG pp.119-122: the potion, oil,
    // command word and scrying conventions,
    // and the energy drain level-loss
    // mechanics.
    {
        int bad = 0;
        // drinking potions and applying oils
        if (rules::potionOpenConsumeSegments() != 1 ||
            rules::potionDelayMin() != 2 ||
            rules::potionDelayMax() != 5) ++bad;
        if (rules::oilDecantSegments() != 1 ||
            rules::oilSpreadMin() != 2 ||
            rules::oilSpreadMax() != 5) ++bad;
        // command words
        if (rules::rodStaffWandNeedsCommandWord() != 1 ||
            rules::commandWordInfoSpellCount() != 3) ++bad;
        // crystal balls and scrying
        if (rules::scryingDetectable() != 1 ||
            rules::scryingDetectionUsesInvisibilityTable() != 1 ||
            rules::scryingDarknessStopsForSpellDuration() != 1 ||
            rules::scryingDispelStopsHours() != 24) ++bad;
        // the energy drain level-loss mechanics
        if (rules::drainLosesLevelHitPointsAndAbilities() != 1 ||
            rules::drainXpToMidpointOfNextLower() != 1) ++bad;
        if (rules::drainBelowFirstIsZeroLevel() != 1 ||
            rules::zeroLevelNeverGainsAgain() != 1) ++bad;
        if (rules::isDeadIfZeroLevelDrained(0) != 1 ||
            rules::isDeadIfZeroLevelDrained(-2) != 1 ||
            rules::isDeadIfZeroLevelDrained(1) != 0 ||
            rules::isDeadIfZeroLevelDrained(5) != 0) ++bad;
        // the multiclass drain rules
        if (rules::multiclassLosesHighestLevel() != 1 ||
            rules::equalLevelsLoseGreatestXpClass() != 1 ||
            rules::twoLevelDrainSplitsAcrossClasses() != 1) ++bad;
        // the drained-all undead fate
        if (rules::drainedAllMayBecomeUndead() != 1 ||
            rules::lesserUndeadHalfHitDice() != 1 ||
            rules::lesserUndeadControlledBySlayer() != 1 ||
            rules::fullHdRegainUponSlayerDestruction() != 1) ++bad;
        if (rules::lesserVampireLevel(8) != 4 ||
            rules::lesserVampireLevel(0) != 0 ||
            rules::lesserVampireLevel(-3) != 0 ||
            rules::lesserVampireLevel(3) != 1) ++bad;
        printf("R218 use of magic items and energy draining pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R219: the treasure random determination tables audit ----
    // DMG pp.120-123: map or magic, the map
    // table with its outdoor and containment
    // sub-tables, and the monetary and magic
    // treasure trove tables.
    {
        int bad = 0;
        // Table I: map or magic
        if (rules::mapOrMagicIsMap(5) != 1 ||
            rules::mapOrMagicIsMap(10) != 1 ||
            rules::mapOrMagicIsMap(11) != 0 ||
            rules::mapOrMagicIsMap(100) != 0 ||
            rules::mapOrMagicIsMap(-3) != 1 ||
            rules::mapOrMagicIsMap(150) != 0) ++bad;
        // Table II: the map table
        if (rules::MT_COUNT != 4 ||
            rules::MT_FALSE != 0 ||
            rules::MT_MONETARY != 1 ||
            rules::MT_MAGIC != 2 ||
            rules::MT_COMBINED != 3) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (rules::mapTableResult(r) !=
                ((r <= 5) ? 0 :
                 ((r <= 70) ? 1 :
                  ((r <= 90) ? 2 : 3)))) ++bad;
        if (rules::mapTableResult(0) != 0 ||
            rules::mapTableResult(999) != 3 ||
            rules::mapNeverListsTreasure() != 1) ++bad;
        // the outdoor destination sub-table
        for (int r = 1; r <= 100; ++r)
            if (rules::mapDestIsLairCaves(r) !=
                ((r <= 20) ? 1 : 0) ||
                rules::mapDestMilesMin(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 5 :
                  ((r <= 90) ? 10 : 50))) ||
                rules::mapDestMilesMax(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 8 :
                  ((r <= 90) ? 40 : 500)))) ++bad;
        if (rules::mapDirectionDie() != 8 ||
            rules::mapDirectionNorthIsOne() != 1) ++bad;
        // the containment sub-table
        if (rules::MCON_COUNT != 6 ||
            rules::MCON_BURIED_UNGUARDED != 0 ||
            rules::MCON_IN_TOWN != 5) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (rules::mapContainment(r) !=
                ((r <= 10) ? 0 :
                 ((r <= 20) ? 1 :
                  ((r <= 70) ? 2 :
                   ((r <= 80) ? 3 :
                    ((r <= 90) ? 4 : 5)))))) ++bad;
        if (rules::mapContainment(0) != 0 ||
            rules::mapContainment(300) != 5 ||
            rules::lowValueLessGuarded() != 1) ++bad;
        // Table II.A: monetary treasure
        if (rules::monetaryRowCount() != 9) ++bad;
        if (rules::monetaryBandLo(0) != 1 ||
            rules::monetaryBandHi(0) != 2 ||
            rules::monetaryBandLo(1) != 3 ||
            rules::monetaryBandHi(1) != 5 ||
            rules::monetaryBandLo(2) != 6 ||
            rules::monetaryBandHi(2) != 10 ||
            rules::monetaryBandLo(3) != 11 ||
            rules::monetaryBandHi(3) != 12 ||
            rules::monetaryBandLo(4) != 13 ||
            rules::monetaryBandHi(4) != 15 ||
            rules::monetaryBandLo(5) != 16 ||
            rules::monetaryBandHi(5) != 17 ||
            rules::monetaryBandLo(6) != 18 ||
            rules::monetaryBandHi(6) != 18 ||
            rules::monetaryBandLo(7) != 19 ||
            rules::monetaryBandHi(7) != 19 ||
            rules::monetaryBandLo(8) != 20 ||
            rules::monetaryBandHi(8) != 20) ++bad;
        if (rules::monetaryBandLo(-3) != 1 ||
            rules::monetaryBandHi(-3) != 2 ||
            rules::monetaryBandLo(9) != 20 ||
            rules::monetaryBandHi(9) != 20) ++bad;
        if (rules::monetaryPipMin(0) != 2 ||
            rules::monetaryPipMax(0) != 8 ||
            rules::monetaryMult(0) != 10000) ++bad;
        if (rules::monetaryQty(0, 2) != 20000 ||
            rules::monetaryQty(0, 8) != 80000 ||
            rules::monetaryQty(0, 99) != 80000) ++bad;
        if (rules::monetaryPipMin(1) != 2 ||
            rules::monetaryPipMax(1) != 5 ||
            rules::monetaryMult(1) != 10000) ++bad;
        if (rules::monetaryQty(1, 2) != 20000 ||
            rules::monetaryQty(1, 5) != 50000) ++bad;
        if (rules::monetaryPipMin(2) != 5 ||
            rules::monetaryPipMax(2) != 30 ||
            rules::monetaryMult(2) != 1000) ++bad;
        if (rules::monetaryQty(2, 5) != 5000 ||
            rules::monetaryQty(2, 30) != 30000) ++bad;
        if (rules::monetaryPipMin(3) != 3 ||
            rules::monetaryPipMax(3) != 18 ||
            rules::monetaryMult(3) != 1000) ++bad;
        if (rules::monetaryQty(3, 3) != 3000 ||
            rules::monetaryQty(3, 18) != 18000) ++bad;
        if (rules::monetaryPipMin(4) != 5 ||
            rules::monetaryPipMax(4) != 20 ||
            rules::monetaryMult(4) != 100) ++bad;
        if (rules::monetaryQty(4, 5) != 500 ||
            rules::monetaryQty(4, 20) != 2000) ++bad;
        if (rules::monetaryPipMin(5) != 1 ||
            rules::monetaryPipMax(5) != 10 ||
            rules::monetaryMult(5) != 10) ++bad;
        if (rules::monetaryQty(5, 1) != 10 ||
            rules::monetaryQty(5, 10) != 100) ++bad;
        if (rules::jewelryPipMin() != 5 ||
            rules::jewelryPipMax() != 50) ++bad;
        if (rules::monetaryReRollMax() != 17 ||
            rules::monetaryExtraRolls(18) != 2 ||
            rules::monetaryExtraRolls(19) != 3 ||
            rules::monetaryExtraRolls(5) != 1 ||
            rules::monetaryExtraRolls(20) != 1) ++bad;
        if (rules::monetaryEachItemRow() != 20 ||
            rules::monetaryEachItemCoversRows() != 17 ||
            rules::abandonedTheftChanceIsDmSet() != 1) ++bad;
        // Table II.B: magic treasure
        static const int kMagLo[7] = {
            1, 6, 9, 13, 15, 19, 20,
        };
        static const int kMagHi[7] = {
            5, 8, 12, 14, 18, 19, 20,
        };
        static const int kMagItems[7] = {
            1, 2, 3, 3, 12, 4, 5,
        };
        if (rules::magicBandCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::magicBandLo(i) != kMagLo[i] ||
                rules::magicBandHi(i) != kMagHi[i] ||
                rules::magicBandItems(i) != kMagItems[i]) ++bad;
        if (rules::magicBandLo(-1) != 1 ||
            rules::magicBandHi(-1) != 5 ||
            rules::magicBandLo(8) != 20 ||
            rules::magicBandHi(8) != 20 ||
            rules::magicBandItems(8) != 5) ++bad;
        if (rules::magicBandExtraPotions(0) != 4 ||
            rules::magicBandExtraPotions(1) != 0) ++bad;
        if (rules::magicBandPotions(4) != 6 ||
            rules::magicBandScrolls(4) != 6 ||
            rules::magicBandPotions(0) != 0) ++bad;
        if (rules::magicBandSwords(2) != 1 ||
            rules::magicBandArmorOrShield(2) != 1 ||
            rules::magicBandMiscWeapons(2) != 1) ++bad;
        if (rules::magicBandNoSwordOrPotions(3) != 1 ||
            rules::magicBandNoSwordOrPotions(2) != 0) ++bad;
        if (rules::magicBandRings(5) != 1 ||
            rules::magicBandRings(6) != 0) ++bad;
        if (rules::magicBandRods(5) != 1 ||
            rules::magicBandRods(6) != 1 ||
            rules::magicBandRods(4) != 0) ++bad;
        if (rules::magicBandMiscMagic(6) != 1 ||
            rules::magicBandMiscMagic(5) != 0) ++bad;
        if (rules::magicTableWeightedByDesign() != 1) ++bad;
        printf("R219 treasure random determination tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R220: the combined hoard table pins audit ----
    // DMG p.123: the II.C combined hoard
    // bands and their monetary and magic
    // trove references.
    {
        int bad = 0;
        // the banding: a full 1-100 walk
        if (rules::hoardBandCount() != 10) ++bad;
        static const int kBand[100] = {
            0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,
            1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,
            2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,
            3,3,3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4,4,4,
            5,5,5,5,5, 6,6,6,6,6, 7,7,7,7,7,
            8,8,8,8,8,8, 9,9,9,9,
        };
        for (int r = 1; r <= 100; ++r)
            if (rules::hoardBandOfRoll(r) !=
                kBand[r - 1]) ++bad;
        if (rules::hoardBandOfRoll(0) != 0 ||
            rules::hoardBandOfRoll(999) != 9) ++bad;
        // the on-hand monetary rows
        static const int kMonCnt[10] = {
            1, 1, 2, 3, 2, 4, 1, 1, 0, 0,
        };
        static const int kMonRow[10][4] = {
            { 0, 0, 0, 0 },
            { 2, 2, 2, 2 },
            { 1, 2, 2, 2 },
            { 0, 1, 2, 2 },
            { 2, 3, 3, 3 },
            { 1, 2, 3, 5 },
            { 8, 8, 8, 8 },
            { 8, 8, 8, 8 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMonetaryRowCount(b) != kMonCnt[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 4; ++i)
                if (rules::hoardMonetaryRow(b, i) !=
                    kMonRow[b][i]) ++bad;
        if (rules::hoardMonetaryRow(5, -3) != 1 ||
            rules::hoardMonetaryRow(5, 99) != 5 ||
            rules::hoardMonetaryRowCount(-2) != 1 ||
            rules::hoardMonetaryRowCount(99) != 0) ++bad;
        // the on-hand magic rows
        static const int kMagCnt[10] = {
            1, 1, 2, 2, 2, 2, 0, 0, 1, 2,
        };
        static const int kMagRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 4 },
            { 2, 3 },
            { 1, 4 },
            { 0, 2 },
            { 0, 0 },
            { 0, 0 },
            { 6, 6 },
            { 4, 6 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMagicRowCount(b) != kMagCnt[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMagicRow(b, i) !=
                    kMagRow[b][i]) ++bad;
        if (rules::hoardMagicRow(9, -1) != 4 ||
            rules::hoardMagicRow(9, 99) != 6) ++bad;
        // the map-to-monetary references
        static const int kMapMon[10] = {
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        };
        static const int kMapMonRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 1 },
            { 3, 4 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMapsToMonetary(b) != kMapMon[b] ||
                rules::hoardMapMonetaryRowCount(b) !=
                kMapMon[b] * 2) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMapMonetaryRow(b, i) !=
                    kMapMonRow[b][i]) ++bad;
        // the map-to-magic references
        static const int kMapMag[10] = {
            0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        };
        static const int kMapMagRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 7, 7 },
            { 0, 0 },
            { 0, 0 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMapsToMagic(b) != kMapMag[b] ||
                rules::hoardMapMagicRowCount(b) != kMapMag[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMapMagicRow(b, i) !=
                    kMapMagRow[b][i]) ++bad;
        // the design notes
        if (rules::hoardMustBeHiddenTrappedGuarded() != 1 ||
            rules::hoardDistantPlaces() != 1) ++bad;
        printf("R220 combined hoard table pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R221: the III.A potions prose pins audit ----
    // DMG pp.125-126: the three footnotes
    // that frame the III.A POTIONS table -
    // the * control die rolls, the **
    // DM-misleading potions, the (F)
    // fighter-only potions.
    {
        int bad = 0;
        // the row identity: the 35 die bands
        if (rules::potionRowCount() != 35) ++bad;
    static const int kLo[35] = {
        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,
        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,
        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,
        88, 91, 94, 97, 98,
    };
    static const int kHi[35] = {
        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,
        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,
        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,
        90, 93, 96, 97, 100,
    };
        for (int i = 0; i < 35; ++i)
            if (rules::potionRowLo(i) != kLo[i] ||
                rules::potionRowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 35; ++i)
            if (rules::potionRowLo(i) !=
                rules::potionRowHi(i - 1) + 1) ++bad;
        if (rules::potionRowLo(-5) != 1 ||
            rules::potionRowLo(99) != 98 ||
            rules::potionRowHi(99) != 100) ++bad;
        // the * control rows

    static const int kC[35] = {
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
    };
    static const int kM[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
    };
    static const int kF[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
    };
        for (int i = 0; i < 35; ++i)
            if (rules::potionIsControl(i) != kC[i] ||
                rules::potionIsMislead(i) != kM[i] ||
                rules::potionIsFighterOnly(i) != kF[i])
                ++bad;
        if (rules::potionControlCount() != 6 ||
            rules::potionMisleadCount() != 2 ||
            rules::potionFighterOnlyCount() != 4) ++bad;
        // the * rows: Animal and Undead Control
        if (!rules::potionIsControl(0) ||
            !rules::potionIsControl(33)) ++bad;
        // JUDGMENT: Plant Control prints with
        // NO star - pinned as printed
        if (rules::potionIsControl(26)) ++bad;
        // the ** rows: Delusion and Poison
        if (!rules::potionIsMislead(4) ||
            !rules::potionIsMislead(28)) ++bad;
        // the (F) rows: Giant Strength,
        // Heroism, Invulnerability, Super-Heroism
        if (!rules::potionIsFighterOnly(13) ||
            !rules::potionIsFighterOnly(16) ||
            !rules::potionIsFighterOnly(19) ||
            !rules::potionIsFighterOnly(30)) ++bad;
        // clamped flag reads
        if (rules::potionIsControl(-9) != 1 ||
            rules::potionIsFighterOnly(99) != 0) ++bad;
        printf("R221 potions prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R222: the III.B scrolls prose pins audit ----
    // DMG pp.126-127: the spell-scroll
    // structure (with the illusionist
    // alternative ranges), the
    // protection scroll values, the
    // curse sub-table and the sale/
    // x.p. prose.
    {
        int bad = 0;
        // the spell-scroll rows
        if (rules::scrollSpellRowCount() != 16) ++bad;
        static const int kSLo[16] = {
            1, 11, 17, 20, 25, 28, 33, 36, 40, 43,
            47, 50, 53, 55, 58, 60,
        };
        static const int kSHi[16] = {
            10, 16, 19, 24, 27, 32, 35, 39, 42, 46,
            49, 52, 54, 57, 59, 60,
        };
        static const int kN[16] = {
            1, 1, 1, 2, 2, 3, 3, 4, 4, 5,
            5, 6, 6, 7, 7, 7,
        };
        static const int kLvLo[16] = {
            1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
            1, 1, 3, 1, 2, 4,
        };
        static const int kLvHi[16] = {
            4, 6, 9, 4, 8, 4, 9, 6, 8, 6,
            8, 6, 8, 8, 9, 9,
        };
        static const int kAlt[16] = {
            0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
            1, 0, 1, 0, 0, 1,
        };
        static const int kALo[16] = {
            0, 0, 2, 0, 1, 0, 2, 0, 1, 0,
            1, 0, 3, 0, 0, 4,
        };
        static const int kAHi[16] = {
            0, 0, 7, 0, 6, 0, 7, 0, 6, 0,
            6, 0, 6, 0, 0, 7,
        };
        for (int i = 0; i < 16; ++i)
            if (rules::scrollSpellRowLo(i) != kSLo[i] ||
                rules::scrollSpellRowHi(i) != kSHi[i] ||
                rules::scrollSpellRowN(i) != kN[i]) ++bad;
        for (int i = 0; i < 16; ++i)
            if (rules::scrollSpellRowLvLo(i) != kLvLo[i] ||
                rules::scrollSpellRowLvHi(i) != kLvHi[i] ||
                rules::scrollSpellRowHasAlt(i) != kAlt[i] ||
                rules::scrollSpellRowAltLvLo(i) != kALo[i] ||
                rules::scrollSpellRowAltLvHi(i) != kAHi[i])
                ++bad;
        for (int i = 1; i < 16; ++i)
            if (rules::scrollSpellRowLo(i) !=
                rules::scrollSpellRowHi(i - 1) + 1) ++bad;
        if (rules::scrollSpellRowLo(-5) != 1 ||
            rules::scrollSpellRowHi(99) != 60) ++bad;
        // the alt rows are the 2, 4, 6, 8,
        // 10, 12 and 15 indices; alt lo =
        // main lo, alt hi < main hi
        if (rules::scrollSpellAltRangeCount() != 7) ++bad;
        if (!rules::scrollSpellRowHasAlt(2) ||
            !rules::scrollSpellRowHasAlt(4) ||
            !rules::scrollSpellRowHasAlt(6) ||
            !rules::scrollSpellRowHasAlt(8) ||
            !rules::scrollSpellRowHasAlt(10) ||
            !rules::scrollSpellRowHasAlt(12) ||
            !rules::scrollSpellRowHasAlt(15)) ++bad;
        if (rules::scrollSpellRowHasAlt(0) ||
            rules::scrollSpellRowHasAlt(13)) ++bad;
        if (rules::scrollSpellRowAltLvLo(2) != 2 ||
            rules::scrollSpellRowAltLvHi(2) != 7 ||
            rules::scrollSpellRowAltLvHi(15) != 7 ||
            rules::scrollSpellRowAltLvLo(12) != 3) ++bad;
        // the protection scroll rows
        if (rules::scrollProtRowCount() != 8) ++bad;
        static const int kPLo[8] = {
            61, 63, 65, 71, 77, 83, 88, 93,
        };
        static const int kPHi[8] = {
            62, 64, 70, 76, 82, 87, 92, 97,
        };
        static const int kPxp[8] = {
            2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::scrollProtRowLo(i) != kPLo[i] ||
                rules::scrollProtRowHi(i) != kPHi[i] ||
                rules::scrollProtRowXp(i) != kPxp[i]) ++bad;
        if (rules::scrollProtRowLo(0) != 61 ||
            rules::scrollProtRowHi(7) != 97 ||
            rules::scrollProtRowXp(0) != 2500 ||
            rules::scrollProtRowXp(3) != 1000) ++bad;
        for (int i = 1; i < 8; ++i)
            if (rules::scrollProtRowLo(i) !=
                rules::scrollProtRowHi(i - 1) + 1) ++bad;
        // the curse sub-table rows
        if (rules::scrollCurseRowCount() != 8) ++bad;
        static const int kCLo[8] = {
            1, 26, 31, 41, 51, 76, 91, 100,
        };
        static const int kCHi[8] = {
            25, 30, 40, 50, 75, 90, 99, 100,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::scrollCurseRowLo(i) != kCLo[i] ||
                rules::scrollCurseRowHi(i) != kCHi[i]) ++bad;
        for (int i = 1; i < 8; ++i)
            if (rules::scrollCurseRowLo(i) !=
                rules::scrollCurseRowHi(i - 1) + 1) ++bad;
        // row 00 is the 100 singleton
        if (rules::scrollCurseRowLo(7) != 100 ||
            rules::scrollCurseRowHi(7) != 100 ||
            rules::scrollCurseRowLo(-9) != 1 ||
            rules::scrollCurseRowHi(99) != 100) ++bad;
        // the prose constants
        if (rules::scrollSpellXpPerLevel() != 100 ||
            rules::scrollSpellSaleMultiplier() != 3 ||
            rules::scrollProtectionSaleMultiplier() != 5)
            ++bad;
        if (!rules::scrollDmMustConvinceRead() ||
            !rules::scrollUnreadMayFade() ||
            !rules::scrollCurseTakesEffectImmediately())
            ++bad;
        if (rules::scrollCurseDiseaseOnsetMin() != 2 ||
            rules::scrollCurseDiseaseOnsetMax() != 8 ||
            rules::scrollCurseTransportMinMiles() != 200 ||
            rules::scrollCurseTransportMaxMiles() != 1200 ||
            rules::scrollCurseTransportRadius() != 20 ||
            rules::scrollCurseRandomSpellLevel() != 12)
            ++bad;
        printf("R222 scrolls prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R223: the III.C rings footnote pins audit ----
    // DMG p.127: the (M) magic-user-only
    // mark and the double-dagger
    // charge-limited rows.
    {
        int bad = 0;
        // the row identity: the 24 die bands
        if (rules::ringRowCount() != 24) ++bad;
        static const int kLo[24] = {
            1, 7, 13, 15, 16, 22, 28, 31, 34, 41,
            44, 45, 61, 62, 64, 66, 70, 76, 78, 80,
            86, 91, 99, 100,
        };
        static const int kHi[24] = {
            6, 12, 14, 15, 21, 27, 30, 33, 40, 43,
            44, 60, 61, 63, 65, 69, 75, 77, 79, 85,
            90, 98, 99, 100,
        };
        static const int kMu[24] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 0,
        };
        static const int kChg[24] = {
            0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 1, 1, 0,
            0, 0, 1, 0,
        };
        for (int i = 0; i < 24; ++i)
            if (rules::ringRowLo(i) != kLo[i] ||
                rules::ringRowHi(i) != kHi[i] ||
                rules::ringIsMuOnly(i) != kMu[i] ||
                rules::ringIsChargeLimited(i) != kChg[i])
                ++bad;
        for (int i = 1; i < 24; ++i)
            if (rules::ringRowLo(i) !=
                rules::ringRowHi(i - 1) + 1) ++bad;
        if (rules::ringRowLo(-5) != 1 ||
            rules::ringRowHi(99) != 100) ++bad;
        // the singleton rows: Djinni
        // Summoning 13-14, Regeneration 61,
        // Wizardry 99, X-Ray Vision 100
        if (rules::ringRowLo(2) != 13 ||
            rules::ringRowHi(2) != 14 ||
            rules::ringRowLo(12) != 61 ||
            rules::ringRowLo(22) != 99 ||
            rules::ringRowHi(22) != 99 ||
            rules::ringRowLo(23) != 100 ||
            rules::ringRowHi(23) != 100) ++bad;
        // the charge rows: the seven
        // double-dagger rings
        if (rules::ringChargeLimitedCount() != 7) ++bad;
        if (!rules::ringIsChargeLimited(2) ||
            !rules::ringIsChargeLimited(7) ||
            !rules::ringIsChargeLimited(10) ||
            !rules::ringIsChargeLimited(11) ||
            !rules::ringIsChargeLimited(17) ||
            !rules::ringIsChargeLimited(18) ||
            !rules::ringIsChargeLimited(22)) ++bad;
        if (rules::ringIsChargeLimited(0) ||
            rules::ringIsChargeLimited(1) ||
            rules::ringIsChargeLimited(3) ||
            rules::ringIsChargeLimited(12) ||
            rules::ringIsChargeLimited(15) ||
            rules::ringIsChargeLimited(23)) ++bad;
        // the (M) row: Wizardry only,
        // and it is ALSO charge-limited
        if (rules::ringMuOnlyCount() != 1) ++bad;
        if (!rules::ringIsMuOnly(22) ||
            !rules::ringIsChargeLimited(22)) ++bad;
        if (rules::ringIsMuOnly(0) ||
            rules::ringIsMuOnly(23)) ++bad;
        // clamped flag reads land on
        // Contrariness and X-Ray Vision:
        // both unmarked
        if (rules::ringIsChargeLimited(-99) ||
            rules::ringIsChargeLimited(99) ||
            rules::ringIsMuOnly(-99)) ++bad;
        printf("R223 rings footnote pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R224: the III.D rods/staves/wands pins audit ----
    // DMG pp.127-128: the class-usable
    // marks and the full-charges asterisk.
    {
        int bad = 0;
        // the row identity: the 30 die bands
        if (rules::rswRowCount() != 30) ++bad;
        static const int kLo[30] = {
            1, 4, 5, 15, 17, 18, 19, 20, 21, 23,
            24, 25, 28, 32, 34, 35, 39, 42, 45, 48,
            53, 57, 60, 69, 74, 79, 87, 90, 93, 95,
        };
        static const int kHi[30] = {
            3, 4, 14, 16, 17, 18, 19, 20, 22, 23,
            24, 27, 31, 33, 34, 38, 41, 44, 47, 52,
            56, 59, 68, 73, 78, 86, 89, 92, 94, 100,
        };
        static const int kC[30] = {
            1, 1, 0, 0, 1, 0, 1, 1, 1, 0,
            0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kM[30] = {
            1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 0,
            1, 1, 0, 0, 0, 0, 1, 1, 0, 0,
        };
        static const int kF[30] = {
            0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kT[30] = {
            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kAny[30] = {
            0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
            0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
        };
        for (int i = 0; i < 30; ++i)
            if (rules::rswRowLo(i) != kLo[i] ||
                rules::rswRowHi(i) != kHi[i] ||
                rules::rswUsableByCleric(i) != kC[i] ||
                rules::rswUsableByMagicUser(i) != kM[i] ||
                rules::rswUsableByFighter(i) != kF[i] ||
                rules::rswUsableByThief(i) != kT[i] ||
                rules::rswAnyClass(i) != kAny[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (rules::rswRowLo(i) !=
                rules::rswRowHi(i - 1) + 1) ++bad;
        if (rules::rswRowLo(-5) != 1 ||
            rules::rswRowHi(99) != 100) ++bad;
        // every row: the any flag excludes
        // the class marks, and a non-any row
        // carries at least one class mark
        for (int i = 0; i < 30; ++i)
            if (rules::rswAnyClass(i) &&
                (rules::rswUsableByCleric(i) ||
                 rules::rswUsableByMagicUser(i) ||
                 rules::rswUsableByFighter(i) ||
                 rules::rswUsableByThief(i))) ++bad;
        for (int i = 0; i < 30; ++i)
            if (!rules::rswAnyClass(i) &&
                !rules::rswUsableByCleric(i) &&
                !rules::rswUsableByMagicUser(i) &&
                !rules::rswUsableByFighter(i) &&
                !rules::rswUsableByThief(i)) ++bad;
        // the famous rows: Absorption (C, M),
        // Beguiling (C, M, T), Cancellation
        // (any), Lordly Might (F), Smiting
        // (C, F), the Magi (M), Wonder (any)
        if (!rules::rswUsableByCleric(0) ||
            !rules::rswUsableByMagicUser(0) ||
            rules::rswAnyClass(0)) ++bad;
        if (!rules::rswUsableByThief(1)) ++bad;
        if (!rules::rswAnyClass(2) ||
            rules::rswUsableByCleric(2)) ++bad;
        if (!rules::rswUsableByFighter(3) ||
            rules::rswUsableByCleric(3) ||
            rules::rswUsableByMagicUser(3)) ++bad;
        if (!rules::rswUsableByCleric(6) ||
            !rules::rswUsableByFighter(6)) ++bad;
        if (!rules::rswUsableByMagicUser(9) ||
            rules::rswUsableByCleric(9)) ++bad;
        if (!rules::rswAnyClass(29) ||
            rules::rswUsableByThief(29)) ++bad;
        // clamped flag reads land on
        // Absorption (C, M) and Wonder (any)
        if (!rules::rswUsableByCleric(-99) ||
            rules::rswAnyClass(-99) ||
            rules::rswUsableByCleric(99) ||
            !rules::rswAnyClass(99)) ++bad;
        // the full-charges asterisk
        if (!rules::rswFullChargesAssumed()) ++bad;
        printf("R224 rods staves wands pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R225: the III.E table 1 pins audit ----
    // DMG p.128: the class marks and the
    // special rows of TABLE (III.E.) 1.
    {
        int bad = 0;
        // the row identity: the 33 die bands
        if (rules::m1RowCount() != 33) ++bad;
        static const int kLo[33] = {
            1, 3, 5, 6, 8, 12, 14, 17, 18, 21,
            22, 27, 28, 30, 32, 33, 34, 35, 36, 37,
            43, 48, 52, 56, 59, 60, 80, 82, 85, 86,
            93, 94, 99,
        };
        static const int kHi[33] = {
            2, 4, 5, 7, 11, 13, 16, 17, 20, 21,
            26, 27, 29, 31, 32, 33, 34, 35, 36, 42,
            47, 51, 55, 58, 59, 79, 81, 84, 85, 92,
            93, 98, 100,
        };
        static const int kM[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 0, 0, 1, 1, 0,
            0, 0, 0,
        };
        static const int kC[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kArt[33] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kBrac[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0,
        };
        static const int kPurse[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1,
        };
        for (int i = 0; i < 33; ++i)
            if (rules::m1RowLo(i) != kLo[i] ||
                rules::m1RowHi(i) != kHi[i] ||
                rules::m1UsableByMagicUser(i) != kM[i] ||
                rules::m1UsableByCleric(i) != kC[i] ||
                rules::m1IsArtifactRelicRow(i) != kArt[i] ||
                rules::m1IsPerAcPointValued(i) != kBrac[i] ||
                rules::m1IsTieredPurseRow(i) != kPurse[i])
                ++bad;
        for (int i = 1; i < 33; ++i)
            if (rules::m1RowLo(i) !=
                rules::m1RowHi(i - 1) + 1) ++bad;
        if (rules::m1RowLo(-5) != 1 ||
            rules::m1RowHi(99) != 100) ++bad;
        // the class marks: the two Books
        // are (C); the Bowls and Braziers
        // are (M)
        if (rules::m1MagicUserCount() != 4 ||
            rules::m1ClericCount() != 2) ++bad;
        if (!rules::m1UsableByCleric(15) ||
            !rules::m1UsableByCleric(17) ||
            rules::m1UsableByCleric(16)) ++bad;
        if (!rules::m1UsableByMagicUser(23) ||
            !rules::m1UsableByMagicUser(24) ||
            !rules::m1UsableByMagicUser(27) ||
            !rules::m1UsableByMagicUser(28) ||
            rules::m1UsableByMagicUser(22)) ++bad;
        // the special rows: Artifact or
        // Relic 17, Bracers 60-79, the
        // Purse 99-00
        if (!rules::m1IsArtifactRelicRow(7) ||
            rules::m1IsArtifactRelicRow(6)) ++bad;
        if (!rules::m1IsPerAcPointValued(26) ||
            rules::m1IsPerAcPointValued(27)) ++bad;
        if (!rules::m1IsTieredPurseRow(32) ||
            rules::m1IsTieredPurseRow(31)) ++bad;
        // the Bracers asterisk: per AC
        // point above 10 - AC 6 (four
        // points) is 2,000 x.p. / 12,000 gp
        if (rules::m1BracersPerAcXp() != 500 ||
            rules::m1BracersPerAcGp() != 3000 ||
            rules::m1BracersPerAcXp() * 4 != 2000 ||
            rules::m1BracersPerAcGp() * 4 != 12000)
            ++bad;
        // clamped flag reads land on the
        // Alchemy Jug (unmarked) and the
        // Purse (tiered)
        if (rules::m1UsableByMagicUser(-99) ||
            rules::m1UsableByCleric(-99) ||
            !rules::m1IsTieredPurseRow(99)) ++bad;
        printf("R225 misc table 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R226: the III.E table 2 pins audit ----
    // DMG p.128: the class marks and the
    // asterisk rows of TABLE (III.E.) 2.
    {
        int bad = 0;
        // the row identity: the 30 die bands
        if (rules::m2RowCount() != 30) ++bad;
        static const int kLo[30] = {
            1, 7, 9, 11, 12, 14, 15, 19, 28, 31,
            33, 56, 61, 62, 64, 66, 68, 70, 73, 77,
            78, 80, 86, 92, 93, 94, 95, 96, 98, 100,
        };
        static const int kHi[30] = {
            6, 8, 10, 11, 13, 14, 18, 27, 30, 32,
            55, 60, 61, 63, 65, 67, 69, 72, 76, 77,
            79, 85, 91, 92, 93, 94, 95, 97, 99, 100,
        };
        static const int kC[30] = {
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kM[30] = {
            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        };
        static const int kPP[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kFeat[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kTri[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        };
        for (int i = 0; i < 30; ++i)
            if (rules::m2RowLo(i) != kLo[i] ||
                rules::m2RowHi(i) != kHi[i] ||
                rules::m2UsableByCleric(i) != kC[i] ||
                rules::m2UsableByMagicUser(i) != kM[i] ||
                rules::m2IsPerPlusValued(i) != kPP[i] ||
                rules::m2HasFeatureAsterisk(i) != kFeat[i] ||
                rules::m2IsTripleStar(i) != kTri[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (rules::m2RowLo(i) !=
                rules::m2RowHi(i - 1) + 1) ++bad;
        if (rules::m2RowLo(-5) != 1 ||
            rules::m2RowHi(99) != 100) ++bad;
        // the class marks: the Candle is
        // (C); the Censers, the Balls and
        // the Eyes of Charming are (M)
        if (rules::m2ClericCount() != 1 ||
            rules::m2MagicUserCount() != 5) ++bad;
        if (!rules::m2UsableByCleric(0) ||
            rules::m2UsableByCleric(1)) ++bad;
        if (!rules::m2UsableByMagicUser(2) ||
            !rules::m2UsableByMagicUser(3) ||
            !rules::m2UsableByMagicUser(11) ||
            !rules::m2UsableByMagicUser(12) ||
            !rules::m2UsableByMagicUser(26) ||
            rules::m2UsableByMagicUser(1) ||
            rules::m2UsableByMagicUser(27)) ++bad;
        // the asterisk rows: Cloak of
        // Protection 33-55 per plus,
        // Crystal Ball 56-60 the feature
        // asterisk, Eyes of Petrification
        // 00 the triple star
        if (!rules::m2IsPerPlusValued(10) ||
            rules::m2IsPerPlusValued(11)) ++bad;
        if (!rules::m2HasFeatureAsterisk(11) ||
            rules::m2HasFeatureAsterisk(10)) ++bad;
        if (!rules::m2IsTripleStar(29) ||
            rules::m2IsTripleStar(28)) ++bad;
        // a +2 cloak is 2,000 x.p. /
        // 20,000 g.p.
        if (rules::m2CloakPerPlusXp() != 1000 ||
            rules::m2CloakPerPlusGp() != 10000 ||
            rules::m2CloakPerPlusXp() * 2 != 2000 ||
            rules::m2CloakPerPlusGp() * 2 != 20000)
            ++bad;
        // a crystal ball with two extra
        // features is 3,000 x.p. (base +
        // 2 x 100%)
        if (rules::m2CrystalBallBaseXp() != 1000 ||
            rules::m2CrystalBallBaseGp() != 5000 ||
            rules::m2CrystalBallFeatureBonusPct() != 100 ||
            rules::m2CrystalBallBaseXp() + 2 *
            (rules::m2CrystalBallBaseXp() *
             rules::m2CrystalBallFeatureBonusPct() / 100)
                != 3000) ++bad;
        // clamped flag reads land on the
        // Candle (C) and Eyes of
        // Petrification (triple)
        if (!rules::m2UsableByCleric(-99) ||
            rules::m2UsableByMagicUser(-99) ||
            !rules::m2IsTripleStar(99)) ++bad;
        printf("R226 misc table 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R237: the III.E table 3 pins audit ----
    // DMG p.129: the class marks and the
    // asterisk ladder of TABLE (III.E.) 3.
    {
        int bad = 0;
        // the row identity: the 33 die bands
        if (rules::m3RowCount() != 33) ++bad;
        static const int kLo[33] = {
            1, 16, 17, 19, 21, 23, 26, 27, 28, 29,
            30, 31, 36, 38, 40, 41, 46, 47, 49, 50,
            54, 61, 64, 66, 71, 72, 73, 79, 81, 86,
            91, 92, 93,
        };
        static const int kHi[33] = {
            15, 16, 18, 20, 22, 25, 26, 27, 28, 29,
            30, 35, 37, 39, 40, 45, 46, 48, 49, 53,
            60, 63, 65, 70, 71, 72, 78, 80, 85, 90,
            91, 92, 100,
        };
        static const int kC[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kF[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            0, 0, 0,
        };
        static const int kT[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kStar[33] = {
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            2, 0, 0, 0, 0, 3, 4, 0, 0, 0,
            0, 0, 0,
        };
        static const int kFacet[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0,
        };
        for (int i = 0; i < 33; ++i)
            if (rules::m3RowLo(i) != kLo[i] ||
                rules::m3RowHi(i) != kHi[i] ||
                rules::m3UsableByCleric(i) != kC[i] ||
                rules::m3UsableByFighter(i) != kF[i] ||
                rules::m3UsableByThief(i) != kT[i] ||
                rules::m3StarCount(i) != kStar[i] ||
                rules::m3IsPerFacetValued(i) != kFacet[i])
                ++bad;
        for (int i = 1; i < 33; ++i)
            if (rules::m3RowLo(i) !=
                rules::m3RowHi(i - 1) + 1) ++bad;
        if (rules::m3RowLo(-5) != 1 ||
            rules::m3RowHi(99) != 100) ++bad;
        // the class marks: the two Gauntlets and
        // two Girdles are (C, F, T); the Horn of
        // the Tritons is (C, F); the Incenses are
        // (C); the Javelins are (F); NO (M) rows
        // ride this table
        if (rules::m3ClericCount() != 7 ||
            rules::m3FighterCount() != 7 ||
            rules::m3ThiefCount() != 4) ++bad;
        if (!rules::m3UsableByCleric(4) ||
            !rules::m3UsableByFighter(4) ||
            !rules::m3UsableByThief(4)) ++bad;
        if (rules::m3UsableByCleric(3) ||
            rules::m3UsableByFighter(3) ||
            rules::m3UsableByThief(3)) ++bad;
        if (!rules::m3UsableByCleric(19) ||
            !rules::m3UsableByFighter(19) ||
            rules::m3UsableByThief(19)) ++bad;
        if (!rules::m3UsableByCleric(23) ||
            rules::m3UsableByFighter(23)) ++bad;
        if (!rules::m3UsableByFighter(28) ||
            !rules::m3UsableByFighter(29) ||
            rules::m3UsableByCleric(28)) ++bad;
        // the asterisk ladder: the Figurine
        // 01-15 (1 star, per hit die), the Horn
        // of Valhalla 54-60 (2 stars, double
        // bronze / triple iron), the Ioun Stones
        // 72 (3 stars, per stone), the
        // Instrument of the Bards 73-78 (4
        // stars, per level of instrument for
        // bards - the footnote the book upload
        // drops, restored from the compilation)
        if (rules::m3StarCount(0) != 1 ||
            rules::m3StarCount(20) != 2 ||
            rules::m3StarCount(25) != 3 ||
            rules::m3StarCount(26) != 4 ||
            rules::m3StarCount(1) != 0) ++bad;
        // a 4-hit-die figurine is 400 x.p. /
        // 4,000 g.p.
        if (rules::m3FigurinePerHitDieXp() != 100 ||
            rules::m3FigurinePerHitDieGp() != 1000 ||
            rules::m3FigurinePerHitDieXp() * 4 != 400 ||
            rules::m3FigurinePerHitDieGp() * 4 != 4000)
            ++bad;
        // the bronze horn doubles (2,000 /
        // 30,000), the iron horn triples
        // (3,000 / 45,000)
        if (rules::m3ValhallaBaseXp() != 1000 ||
            rules::m3ValhallaBaseGp() != 15000 ||
            rules::m3ValhallaBronzeMult() != 2 ||
            rules::m3ValhallaIronMult() != 3 ||
            rules::m3ValhallaBaseXp() *
            rules::m3ValhallaBronzeMult() != 2000 ||
            rules::m3ValhallaBaseGp() *
            rules::m3ValhallaBronzeMult() != 30000 ||
            rules::m3ValhallaBaseXp() *
            rules::m3ValhallaIronMult() != 3000 ||
            rules::m3ValhallaBaseGp() *
            rules::m3ValhallaIronMult() != 45000)
            ++bad;
        // per stone: five stones are 1,500 x.p.
        if (rules::m3IounPerStoneXp() != 300 ||
            rules::m3IounPerStoneGp() != 5000 ||
            rules::m3IounPerStoneXp() * 5 != 1500)
            ++bad;
        // the bardic instruments ride the
        // college ladder: the 3rd-college Doss
        // instrument is 3,000 x.p. / 15,000 g.p.
        if (rules::m3InstrumentBaseXp() != 1000 ||
            rules::m3InstrumentBaseGp() != 5000 ||
            rules::m3InstrumentBaseXp() * 3 != 3000 ||
            rules::m3InstrumentBaseGp() * 3 != 15000)
            ++bad;
        // the Jewel of Flawlessness 92: no x.p.,
        // 1,000 g.p. per facet
        if (!rules::m3IsPerFacetValued(31) ||
            rules::m3IsPerFacetValued(30) ||
            rules::m3JewelPerFacetGp() != 1000 ||
            rules::m3JewelPerFacetGp() * 3 != 3000)
            ++bad;
        // clamped reads land on the Figurine
        // (1 star) below and the unmarked
        // 93-00 Ointment above
        if (rules::m3StarCount(-99) != 1 ||
            rules::m3UsableByCleric(99) ||
            rules::m3IsPerFacetValued(99)) ++bad;
        printf("R237 misc table 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R238: the III.E table 4 pins audit ----
    // DMG p.129-130: the class marks, the
    // asterisk ladder and the dual-value rows
    // of TABLE (III.E.) 4.
    {
        int bad = 0;
        // the row identity: the 36 die bands
        if (rules::m4RowCount() != 36) ++bad;
        static const int kLo[36] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 16, 18, 19, 20, 21, 24, 28,
            34, 36, 39, 43, 45, 47, 49, 51, 54, 61,
            65, 71, 75, 77, 85, 86,
        };
        static const int kHi[36] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 15, 17, 18, 19, 20, 23, 27, 33,
            35, 38, 42, 44, 46, 48, 50, 53, 60, 64,
            70, 74, 76, 84, 85, 100,
        };
        static const int kC[36] = {
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 0,
        };
        static const int kF[36] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kM[36] = {
            1, 1, 1, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kT[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kStar[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
            0, 0, 0, 3, 4, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kDual[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1,
        };
        for (int i = 0; i < 36; ++i)
            if (rules::m4RowLo(i) != kLo[i] ||
                rules::m4RowHi(i) != kHi[i] ||
                rules::m4UsableByCleric(i) != kC[i] ||
                rules::m4UsableByFighter(i) != kF[i] ||
                rules::m4UsableByMagicUser(i) != kM[i] ||
                rules::m4UsableByThief(i) != kT[i] ||
                rules::m4StarCount(i) != kStar[i] ||
                rules::m4IsDualValued(i) != kDual[i])
                ++bad;
        for (int i = 1; i < 36; ++i)
            if (rules::m4RowLo(i) !=
                rules::m4RowHi(i - 1) + 1) ++bad;
        if (rules::m4RowLo(-5) != 1 ||
            rules::m4RowHi(99) != 100) ++bad;
        // the class marks: the Librams and the
        // Pearl of Power are (M); the Golems
        // Manual is (C, M); the Puissant Manual
        // and the Mattock are (F); the
        // Stealthy Manual and the Nets are (T)
        if (rules::m4ClericCount() != 8 ||
            rules::m4FighterCount() != 4 ||
            rules::m4MagicUserCount() != 6 ||
            rules::m4ThiefCount() != 3) ++bad;
        if (!rules::m4UsableByMagicUser(0) ||
            !rules::m4UsableByMagicUser(1) ||
            !rules::m4UsableByMagicUser(2)) ++bad;
        if (!rules::m4UsableByCleric(6) ||
            !rules::m4UsableByMagicUser(6)) ++bad;
        if (!rules::m4UsableByFighter(7) ||
            rules::m4UsableByCleric(7)) ++bad;
        if (!rules::m4UsableByThief(9) ||
            rules::m4UsableByFighter(9)) ++bad;
        if (!rules::m4UsableByFighter(10) ||
            rules::m4UsableByMagicUser(10)) ++bad;
        if (rules::m4UsableByCleric(8) ||
            rules::m4UsableByFighter(8) ||
            rules::m4UsableByMagicUser(8) ||
            rules::m4UsableByThief(8)) ++bad;
        if (!rules::m4UsableByMagicUser(14) ||
            rules::m4UsableByMagicUser(15)) ++bad;
        if (!rules::m4UsableByCleric(19) ||
            rules::m4UsableByMagicUser(19)) ++bad;
        if (!rules::m4UsableByCleric(21) ||
            !rules::m4UsableByFighter(21) ||
            !rules::m4UsableByThief(21) ||
            !rules::m4UsableByCleric(22) ||
            !rules::m4UsableByFighter(22) ||
            !rules::m4UsableByThief(22)) ++bad;
        if (!rules::m4UsableByMagicUser(24) ||
            !rules::m4UsableByCleric(25) ||
            rules::m4UsableByCleric(24)) ++bad;
        if (!rules::m4UsableByCleric(30) ||
            !rules::m4UsableByCleric(31) ||
            !rules::m4UsableByCleric(32)) ++bad;
        if (rules::m4UsableByCleric(33) ||
            rules::m4UsableByCleric(34)) ++bad;
        // the asterisk ladder: the Necklace of
        // Missiles 24-27 (1 star, per hit die of
        // each missile), the Prayer Beads 28-33
        // (2 stars, per special bead), the
        // Pigments 43-44 (3 stars, per pot), the
        // Pearl of Power 45-46 (4 stars, per
        // level of spell)
        if (rules::m4StarCount(18) != 1 ||
            rules::m4StarCount(19) != 2 ||
            rules::m4StarCount(23) != 3 ||
            rules::m4StarCount(24) != 4 ||
            rules::m4StarCount(17) != 0) ++bad;
        // a 5-hit-die missile is 250 x.p. /
        // 1,000 g.p.
        if (rules::m4MissilePerHitDieXp() != 50 ||
            rules::m4MissilePerHitDieGp() != 200 ||
            rules::m4MissilePerHitDieXp() * 5 != 250 ||
            rules::m4MissilePerHitDieGp() * 5 != 1000)
            ++bad;
        // two special beads are 1,000 x.p. /
        // 6,000 g.p.
        if (rules::m4BeadPerSpecialXp() != 500 ||
            rules::m4BeadPerSpecialGp() != 3000 ||
            rules::m4BeadPerSpecialXp() * 2 != 1000 ||
            rules::m4BeadPerSpecialGp() * 2 != 6000)
            ++bad;
        // two pots of pigments are 1,000 x.p.
        // / 6,000 g.p.
        if (rules::m4PigmentsPerPotXp() != 500 ||
            rules::m4PigmentsPerPotGp() != 3000 ||
            rules::m4PigmentsPerPotXp() * 2 != 1000 ||
            rules::m4PigmentsPerPotGp() * 2 != 6000)
            ++bad;
        // a 3rd-level spell pearl is 600 x.p. /
        // 6,000 g.p.
        if (rules::m4PearlPerSpellLevelXp() != 200 ||
            rules::m4PearlPerSpellLevelGp() != 2000 ||
            rules::m4PearlPerSpellLevelXp() * 3 != 600 ||
            rules::m4PearlPerSpellLevelGp() * 3 != 6000)
            ++bad;
        // the dual rows: the Medallion of ESP
        // 1,000/3,000 x.p., 10,000/30,000 g.p.;
        // the Feather Token 500/1,000 x.p.,
        // 2,000/7,000 g.p.
        if (!rules::m4IsDualValued(12) ||
            rules::m4IsDualValued(13) ||
            !rules::m4IsDualValued(35) ||
            rules::m4IsDualValued(34)) ++bad;
        if (rules::m4MedallionEspXpLow() != 1000 ||
            rules::m4MedallionEspXpHigh() != 3000 ||
            rules::m4MedallionEspGpLow() != 10000 ||
            rules::m4MedallionEspGpHigh() != 30000)
            ++bad;
        if (rules::m4FeatherTokenXpLow() != 500 ||
            rules::m4FeatherTokenXpHigh() != 1000 ||
            rules::m4FeatherTokenGpLow() != 2000 ||
            rules::m4FeatherTokenGpHigh() != 7000)
            ++bad;
        // clamped reads land on the first
        // Libram (M, unstarred) below and the
        // Feather Token (dual) above
        if (rules::m4StarCount(-99) != 0 ||
            !rules::m4UsableByMagicUser(-99) ||
            !rules::m4IsDualValued(99) ||
            rules::m4UsableByCleric(99)) ++bad;
        printf("R238 misc table 4 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R239: the III.E table 5 pins audit ----
    // DMG p.130: the class marks of TABLE
    // (III.E.) 5 - no asterisk rows, dual-value
    // rows or footnotes ride this table.
    {
        int bad = 0;
        // the row identity: the 35 die bands
        if (rules::m5RowCount() != 35) ++bad;
        static const int kLo[35] = {
            1, 2, 9, 10, 11, 12, 20, 26, 28, 32,
            33, 34, 35, 36, 39, 41, 47, 48, 49, 51,
            53, 55, 58, 59, 61, 67, 68, 69, 70, 77,
            79, 84, 86, 88, 91,
        };
        static const int kHi[35] = {
            1, 8, 9, 10, 11, 19, 25, 27, 31, 32,
            33, 34, 35, 38, 40, 46, 47, 48, 50, 52,
            54, 57, 58, 60, 66, 67, 68, 69, 76, 78,
            83, 85, 87, 90, 100,
        };
        static const int kC[35] = {
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0,
        };
        static const int kF[35] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 0, 0, 0,
        };
        static const int kM[35] = {
            1, 0, 1, 1, 1, 1, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
        };
        static const int kT[35] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0,
        };
        for (int i = 0; i < 35; ++i)
            if (rules::m5RowLo(i) != kLo[i] ||
                rules::m5RowHi(i) != kHi[i] ||
                rules::m5UsableByCleric(i) != kC[i] ||
                rules::m5UsableByFighter(i) != kF[i] ||
                rules::m5UsableByMagicUser(i) != kM[i] ||
                rules::m5UsableByThief(i) != kT[i])
                ++bad;
        for (int i = 1; i < 35; ++i)
            if (rules::m5RowLo(i) !=
                rules::m5RowHi(i - 1) + 1) ++bad;
        if (rules::m5RowLo(-5) != 1 ||
            rules::m5RowHi(99) != 100) ++bad;
        // the class marks: the five Robes, the
        // Rug, the Sphere and the Sphere
        // Talisman are (M); the Scintillating
        // Robe, the two Talismans and the two
        // command/warning Tridents are (C); the
        // Saw, the Spade, the Submission
        // Trident and the command/warning
        // Tridents are (F); the command/warning
        // Tridents are (T)
        if (rules::m5ClericCount() != 5 ||
            rules::m5FighterCount() != 5 ||
            rules::m5MagicUserCount() != 8 ||
            rules::m5ThiefCount() != 2) ++bad;
        if (!rules::m5UsableByMagicUser(0) ||
            rules::m5UsableByCleric(0)) ++bad;
        if (rules::m5UsableByMagicUser(1) ||
            rules::m5UsableByCleric(1) ||
            rules::m5UsableByFighter(1) ||
            rules::m5UsableByThief(1)) ++bad;
        if (!rules::m5UsableByMagicUser(2) ||
            !rules::m5UsableByMagicUser(3) ||
            !rules::m5UsableByMagicUser(5)) ++bad;
        if (!rules::m5UsableByCleric(4) ||
            !rules::m5UsableByMagicUser(4)) ++bad;
        if (!rules::m5UsableByMagicUser(10) ||
            !rules::m5UsableByFighter(11) ||
            rules::m5UsableByCleric(12)) ++bad;
        if (!rules::m5UsableByFighter(16) ||
            !rules::m5UsableByMagicUser(17)) ++bad;
        if (!rules::m5UsableByCleric(21) ||
            !rules::m5UsableByMagicUser(22) ||
            !rules::m5UsableByCleric(23) ||
            rules::m5UsableByCleric(24)) ++bad;
        if (rules::m5UsableByCleric(25) ||
            rules::m5UsableByCleric(26) ||
            rules::m5UsableByCleric(27)) ++bad;
        if (!rules::m5UsableByCleric(28) ||
            !rules::m5UsableByFighter(28) ||
            !rules::m5UsableByThief(28) ||
            !rules::m5UsableByCleric(30) ||
            !rules::m5UsableByFighter(30) ||
            !rules::m5UsableByThief(30)) ++bad;
        if (!rules::m5UsableByFighter(29) ||
            rules::m5UsableByCleric(29) ||
            rules::m5UsableByThief(29)) ++bad;
        if (rules::m5UsableByCleric(31) ||
            rules::m5UsableByFighter(31) ||
            rules::m5UsableByThief(31)) ++bad;
        // clamped reads land on the (M) Robe of
        // the Archmagi below and the unmarked
        // Wings of Flying above
        if (!rules::m5UsableByMagicUser(-99) ||
            rules::m5UsableByCleric(99) ||
            rules::m5UsableByFighter(99) ||
            rules::m5UsableByThief(99)) ++bad;
        printf("R239 misc table 5 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R240: the III.E Special artifacts pins audit ----
    // DMG p.130-131: the artifact g.p. sale
    // value table - the 29 rows, the value
    // conventions and the no-x.p. footnote.
    {
        int bad = 0;
        // the row identity: the 29 die bands
        if (rules::saRowCount() != 29) ++bad;
        static const int kLo[29] = {
            1, 2, 3, 5, 21, 22, 23, 25, 26, 27,
            28, 30, 32, 33, 34, 36, 38, 39, 41, 48,
            64, 65, 67, 69, 75, 92, 93, 99, 100,
        };
        static const int kHi[29] = {
            1, 2, 4, 20, 21, 22, 24, 25, 26, 27,
            29, 31, 32, 33, 35, 37, 38, 40, 47, 63,
            64, 66, 68, 74, 91, 92, 98, 99, 100,
        };
        static const int kGp[29] = {
            55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,
            25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,
            72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,
            150000, 97000, 5000, 0, 10000,
        };
        static const int kGpHi[29] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kXp[29] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 29; ++i)
            if (rules::saRowLo(i) != kLo[i] ||
                rules::saRowHi(i) != kHi[i] ||
                rules::saSaleGp(i) != kGp[i] ||
                rules::saSaleGpHi(i) != kGpHi[i] ||
                rules::saXpValue(i) != kXp[i])
                ++bad;
        for (int i = 1; i < 29; ++i)
            if (rules::saRowLo(i) !=
                rules::saRowHi(i - 1) + 1) ++bad;
        if (rules::saRowLo(-5) != 1 ||
            rules::saRowHi(99) != 100) ++bad;
        // the printed sale values: the Axe of
        // the Dwarvish Lords, the Jacinth of
        // Inestimable Beauty, the Mighty
        // Servant of Leuk-O, the Marvelous
        // Nightingale, the Sceptre of Might
        // and the Sword of Kas
        if (rules::saSaleGp(0) != 55000 ||
            rules::saSaleGp(12) != 100000 ||
            rules::saSaleGp(17) != 185000 ||
            rules::saSaleGp(20) != 112500 ||
            rules::saSaleGp(24) != 150000 ||
            rules::saSaleGp(25) != 97000) ++bad;
        // the Orb of the Dragonkind uniform
        // range 10,000-80,000 (count 1)
        if (rules::saSaleGp(18) != 10000 ||
            rules::saSaleGpHi(18) != 80000 ||
            rules::saDualRangeCount() != 1) ++bad;
        // the Teeth of Dahlver-Nar at 5,000
        // per tooth (count 1)
        if (rules::saSaleGp(26) != 5000 ||
            rules::saSaleGpHi(26) != 0 ||
            rules::saPerToothRowCount() != 1) ++bad;
        // the Throne of the Gods prints NO
        // sale value (count 1)
        if (rules::saSaleGp(27) != 0 ||
            rules::saSaleGpHi(27) != 0 ||
            rules::saNoSaleRowCount() != 1) ++bad;
        // the Wand of Orcus rides the 00
        // band - pinned as 100
        if (rules::saRowLo(28) != 100 ||
            rules::saSaleGp(28) != 10000) ++bad;
        // the no-x.p. convention: every row
        if (rules::saNoXpRowCount() != 29) ++bad;
        // clamped reads land on the Axe below
        // and the Wand of Orcus above
        if (rules::saSaleGp(-99) != 55000 ||
            rules::saSaleGp(99) != 10000 ||
            rules::saXpValue(-99) != 0 ||
            rules::saXpValue(99) != 0) ++bad;
        printf("R240 special artifacts pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R241: the III.F armor and shield pins audit ----
    // DMG p.129-130: the magic armor and shield
    // table - the 26 rows, the two cursed
    // no-x.p. rows and the size footnote.
    {
        int bad = 0;
        // the row identity: the 26 die bands
        if (rules::asRowCount() != 26) ++bad;
        static const int kLo[26] = {
            1, 6, 10, 12, 20, 27, 33, 36, 38,
            39, 40, 45, 51, 56, 60, 64, 67, 69,
            70, 76, 85, 90, 94, 96, 97, 98,
        };
        static const int kHi[26] = {
            5, 9, 11, 19, 26, 32, 35, 37, 38,
            39, 44, 50, 55, 59, 63, 66, 68, 69,
            75, 84, 89, 93, 95, 96, 97, 100,
        };
        static const int kXp[26] = {
            600, 1200, 2000, 300, 800, 1750, 2750, 3500, 4500,
            5000, 0, 400, 500, 1100, 700, 1500, 2250, 3000,
            400, 250, 500, 800, 1200, 1750, 400, 0,
        };
        static const int kGp[26] = {
            3500, 7500, 12500, 2000, 5000, 10500, 15500, 20500, 27500,
            30000, 1500, 2500, 3000, 6750, 4000, 8500, 14500, 19000,
            2500, 2500, 5000, 8000, 12000, 17500, 4000, 750,
        };
        for (int i = 0; i < 26; ++i)
            if (rules::asRowLo(i) != kLo[i] ||
                rules::asRowHi(i) != kHi[i] ||
                rules::asXpValue(i) != kXp[i] ||
                rules::asSaleGp(i) != kGp[i])
                ++bad;
        for (int i = 1; i < 26; ++i)
            if (rules::asRowLo(i) !=
                rules::asRowHi(i - 1) + 1) ++bad;
        if (rules::asRowLo(-5) != 1 ||
            rules::asRowHi(99) != 100) ++bad;
        // the printed values: Chain Mail +1,
        // Leather Armor +1, Plate Mail of
        // Etherealness, Shield +5 and the
        // large missile Shield
        if (rules::asXpValue(0) != 600 ||
            rules::asSaleGp(0) != 3500) ++bad;
        if (rules::asXpValue(3) != 300 ||
            rules::asSaleGp(3) != 2000) ++bad;
        if (rules::asXpValue(9) != 5000 ||
            rules::asSaleGp(9) != 30000) ++bad;
        if (rules::asXpValue(23) != 1750 ||
            rules::asSaleGp(23) != 17500) ++bad;
        if (rules::asXpValue(24) != 400 ||
            rules::asSaleGp(24) != 4000) ++bad;
        // the TWO cursed no-x.p. rows: the
        // Plate Mail of Vulnerability and the
        // Shield -1 missile attractor
        if (rules::asXpValue(10) != 0 ||
            rules::asSaleGp(10) != 1500 ||
            rules::asXpValue(25) != 0 ||
            rules::asSaleGp(25) != 750 ||
            rules::asNoXpCount() != 2) ++bad;
        // the missile attractor rides the 98-00
        // band - pinned as 98 through 100
        if (rules::asRowLo(25) != 98 ||
            rules::asRowHi(25) != 100) ++bad;
        // the armor SIZE footnote: 65/20/10/5
        // sums to 100
        if (rules::asManSizedPct() != 65 ||
            rules::asElfSizedPct() != 20 ||
            rules::asDwarfSizedPct() != 10 ||
            rules::asSmallUserPct() != 5) ++bad;
        if (rules::asManSizedPct() +
            rules::asElfSizedPct() +
            rules::asDwarfSizedPct() +
            rules::asSmallUserPct() != 100) ++bad;
        // clamped reads land on Chain Mail +1
        // below and the missile attractor above
        if (rules::asSaleGp(-99) != 3500 ||
            rules::asSaleGp(99) != 750 ||
            rules::asXpValue(-99) != 600 ||
            rules::asXpValue(99) != 0) ++bad;
        printf("R241 armor and shield pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R242: the III.G swords pins audit ----
    // DMG p.131: the magic swords table - the 26
    // rows, the three cursed no-sale rows, the
    // size note and the tiered bonuses.
    {
        int bad = 0;
        // the row identity: the 26 die bands
        if (rules::swRowCount() != 26) ++bad;
        static const int kLo[26] = {
            1, 26, 31, 36, 41, 46, 50, 51, 59,
            63, 67, 68, 72, 75, 77, 78, 79, 80,
            81, 82, 83, 84, 85, 86, 91, 96,
        };
        static const int kHi[26] = {
            25, 30, 35, 40, 45, 49, 50, 58, 62,
            66, 67, 71, 74, 76, 77, 78, 79, 80,
            81, 82, 83, 84, 85, 90, 95, 100,
        };
        static const int kXp[26] = {
            400, 600, 700, 800, 800, 900, 1000, 800, 900,
            900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,
            4400, 4400, 5000, 7000, 10000, 400, 600, 900,
        };
        static const int kGp[26] = {
            2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,
            4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,
            22000, 22000, 25000, 35000, 50000, 0, 0, 0,
        };
        for (int i = 0; i < 26; ++i)
            if (rules::swRowLo(i) != kLo[i] ||
                rules::swRowHi(i) != kHi[i] ||
                rules::swXpValue(i) != kXp[i] ||
                rules::swSaleGp(i) != kGp[i])
                ++bad;
        for (int i = 1; i < 26; ++i)
            if (rules::swRowLo(i) !=
                rules::swRowHi(i - 1) + 1) ++bad;
        if (rules::swRowLo(-5) != 1 ||
            rules::swRowHi(99) != 100) ++bad;
        // the printed values: Sword +1, Luck
        // Blade, Nine Lives Stealer, Holy
        // Avenger and the Vorpal Weapon
        if (rules::swXpValue(0) != 400 ||
            rules::swSaleGp(0) != 2000) ++bad;
        if (rules::swXpValue(6) != 1000 ||
            rules::swSaleGp(6) != 5000) ++bad;
        if (rules::swXpValue(10) != 1600 ||
            rules::swSaleGp(10) != 8000) ++bad;
        if (rules::swXpValue(17) != 4000 ||
            rules::swSaleGp(17) != 20000) ++bad;
        if (rules::swXpValue(22) != 10000 ||
            rules::swSaleGp(22) != 50000) ++bad;
        // the THREE cursed swords print --- g.p.
        // sale values: +1 Cursed, -2 Cursed and
        // the Berserking (rows 23, 24, 25)
        if (rules::swXpValue(23) != 400 ||
            rules::swSaleGp(23) != 0 ||
            rules::swXpValue(24) != 600 ||
            rules::swSaleGp(24) != 0 ||
            rules::swXpValue(25) != 900 ||
            rules::swSaleGp(25) != 0 ||
            rules::swNoSaleCount() != 3) ++bad;
        // the Berserking rides the 96-00 band -
        // pinned as 96 through 100
        if (rules::swRowLo(25) != 96 ||
            rules::swRowHi(25) != 100) ++bad;
        // the sword SIZE note: 70/20/5/4/1 sums
        // to 100
        if (rules::swLongswordPct() != 70 ||
            rules::swBroadswordPct() != 20 ||
            rules::swShortswordPct() != 5 ||
            rules::swBastardPct() != 4 ||
            rules::swTwoHandedPct() != 1) ++bad;
        if (rules::swLongswordPct() +
            rules::swBroadswordPct() +
            rules::swShortswordPct() +
            rules::swBastardPct() +
            rules::swTwoHandedPct() != 100) ++bad;
        // the tiered bonuses: the Flame Tongue
        // ladder 2/3/4 and the Frost Brand +6
        if (rules::swFlameVsRegenBonus() != 2 ||
            rules::swFlameVsColdAvianBonus() != 3 ||
            rules::swFlameVsUndeadBonus() != 4 ||
            rules::swFrostVsFireBonus() != 6) ++bad;
        if (rules::swFlameVsRegenBonus() *
            rules::swFlameVsColdAvianBonus() -
            rules::swFlameVsRegenBonus() !=
            rules::swFlameVsUndeadBonus()) ++bad;
        // clamped reads land on Sword +1 below
        // and the Cursed Berserking above
        if (rules::swSaleGp(-99) != 2000 ||
            rules::swSaleGp(99) != 0 ||
            rules::swXpValue(-99) != 400 ||
            rules::swXpValue(99) != 900) ++bad;
        printf("R242 swords pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R243: the III.H misc weapons pins audit ----
    // DMG p.131-132: the miscellaneous weapons
    // table - the 36 rows, the ammo quantity
    // ranges and the duplicate Hammer +2 rows.
    {
        int bad = 0;
        // the row identity: the 36 die bands
        if (rules::mwRowCount() != 36) ++bad;
        static const int kLo[36] = {
            1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,
            37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,
            73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,
        };
        static const int kHi[36] = {
            8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,
            37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,
            75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,
        };
        static const int kXp[36] = {
            20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,
            1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,
            700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,
        };
        static const int kGp[36] = {
            120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,
            7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,
            4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,
        };
        static const int kQlo[36] = {
            2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kQhi[36] = {
            24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 36; ++i)
            if (rules::mwRowLo(i) != kLo[i] ||
                rules::mwRowHi(i) != kHi[i] ||
                rules::mwXpValue(i) != kXp[i] ||
                rules::mwSaleGp(i) != kGp[i] ||
                rules::mwQtyLo(i) != kQlo[i] ||
                rules::mwQtyHi(i) != kQhi[i])
                ++bad;
        for (int i = 1; i < 36; ++i)
            if (rules::mwRowLo(i) !=
                rules::mwRowHi(i - 1) + 1) ++bad;
        if (rules::mwRowLo(-5) != 1 ||
            rules::mwRowHi(99) != 100) ++bad;
        // the printed values: the Arrow of
        // Slaying, the Crossbow of Speed, the
        // Dagger of Venom, the Hammer of
        // Thunderbolts, the Mace of Disruption
        // and the Trident (Military Fork)
        if (rules::mwXpValue(3) != 250 ||
            rules::mwSaleGp(3) != 2500) ++bad;
        if (rules::mwXpValue(13) != 1500 ||
            rules::mwSaleGp(13) != 7500) ++bad;
        if (rules::mwXpValue(16) != 350 ||
            rules::mwSaleGp(16) != 3000) ++bad;
        if (rules::mwXpValue(21) != 2500 ||
            rules::mwSaleGp(21) != 25000) ++bad;
        if (rules::mwXpValue(25) != 1750 ||
            rules::mwSaleGp(25) != 17500) ++bad;
        if (rules::mwXpValue(35) != 1500 ||
            rules::mwSaleGp(35) != 12500) ++bad;
        // the FOUR ammo quantity ranges: the
        // three Arrows 2-24/2-16/2-12 and the
        // Bolt 2-20 (0/0 means a single item)
        if (rules::mwQtyLo(0) != 2 ||
            rules::mwQtyHi(0) != 24 ||
            rules::mwQtyLo(1) != 2 ||
            rules::mwQtyHi(1) != 16 ||
            rules::mwQtyLo(2) != 2 ||
            rules::mwQtyHi(2) != 12 ||
            rules::mwQtyLo(9) != 2 ||
            rules::mwQtyHi(9) != 20 ||
            rules::mwQtyRangeCount() != 4) ++bad;
        if (rules::mwQtyLo(5) != 0 ||
            rules::mwQtyHi(5) != 0 ||
            rules::mwQtyLo(35) != 0 ||
            rules::mwQtyHi(35) != 0) ++bad;
        // the TWO duplicate Hammer +2 rows: the
        // book prints the name twice with
        // different values (p.125)
        if (rules::mwXpValue(18) != 300 ||
            rules::mwSaleGp(18) != 2500 ||
            rules::mwXpValue(19) != 650 ||
            rules::mwSaleGp(19) != 6000 ||
            rules::mwDuplicateNameCount() != 2) ++bad;
        // the cursed Backbiter prints --- x.p.
        if (rules::mwXpValue(34) != 0 ||
            rules::mwSaleGp(34) != 1000 ||
            rules::mwNoXpCount() != 1) ++bad;
        // the Trident (Military Fork) rides the
        // 00 band - pinned as 100
        if (rules::mwRowLo(35) != 100 ||
            rules::mwRowHi(35) != 100) ++bad;
        // clamped reads land on the Arrow +1
        // below and the Trident above
        if (rules::mwSaleGp(-99) != 120 ||
            rules::mwSaleGp(99) != 12500 ||
            rules::mwQtyLo(-99) != 2 ||
            rules::mwQtyHi(99) != 0) ++bad;
        printf("R243 misc weapons pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R244: the III.D rods explanation prose pins audit ----
    // DMG pp.141-142: the section conventions
    // and the seven rods of the RODS, et al.
    // explanation prose.
    {
        int bad = 0;
        // the charges conventions: rods 50 minus
        // 0-9, staves 25 minus 0-5, wands 100
        // minus 0-19
        if (rules::rpRodChargesMax() != 50 ||
            rules::rpRodChargesDieLo() != 0 ||
            rules::rpRodChargesDieHi() != 9) ++bad;
        if (rules::rpStaffChargesMax() != 25 ||
            rules::rpStaffChargesDieLo() != 0 ||
            rules::rpStaffChargesDieHi() != 5) ++bad;
        if (rules::rpWandChargesMax() != 100 ||
            rules::rpWandChargesDieLo() != 0 ||
            rules::rpWandChargesDieHi() != 19) ++bad;
        // the drained-crumble, command-word and
        // silence conventions
        if (rules::rpDrainedCrumble() != 1 ||
            rules::rpCommandWordRule() != 1 ||
            rules::rpSilenceBlocks() != 1) ++bad;
        // the seven rods are the first seven rows
        // of the engine III.D table - bands 01-19,
        // the staff rows from 20 (the R224 pins)
        if (rules::rpRodCount() != 7 ||
            rules::rswRowLo(0) != 1 ||
            rules::rswRowHi(6) != 19 ||
            rules::rswRowLo(7) != 20) ++bad;
        // Rod of Absorption
        if (rules::rpAbsorbMaxSpellLevels() != 50 ||
            rules::rpAbsorbCastSegments() != 1 ||
            rules::rpAbsorbRechargeable() != 0) ++bad;
        // Rod of Beguiling
        if (rules::rpBeguileRadiusInches() != 2 ||
            rules::rpBeguileMinIntelligence() != 1 ||
            rules::rpBeguileHasSave() != 0 ||
            rules::rpBeguileTurnsPerCharge() != 1 ||
            rules::rpBeguileRechargeable() != 1) ++bad;
        // Rod of Cancellation - the 11-row item
        // saving throw table
        static const int kCanc[11] = {
            20, 19, 17, 14, 13, 15, 12, 3, 11, 9, 10,
        };
        if (rules::rpCancSaveCount() != 11) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rules::rpCancSaveValue(i) != kCanc[i]) ++bad;
        // the +5 armor/shield and holy sword variants
        if (rules::rpCancArmorShieldPlus5() != 8 ||
            rules::rpCancHolySword() != 7) ++bad;
        // drained items are not restorable, and the
        // rod turns brittle
        if (rules::rpCancDrainedRestorable() != 0 ||
            rules::rpCancRodBecomesBrittle() != 1) ++bad;
        // clamped reads land on the potion row below
        // and the misc weapon row above
        if (rules::rpCancSaveValue(-9) != 20 ||
            rules::rpCancSaveValue(99) != 10) ++bad;
        // Rod of Lordly Might
        if (rules::rpLmWeightPounds() != 10 ||
            rules::rpLmMinStrength() != 16 ||
            rules::rpLmStrBelowPenalty() != 1 ||
            rules::rpLmSpellLikeCount() != 3 ||
            rules::rpLmSpellCostCharges() != 1 ||
            rules::rpLmFearRangeInches() != 6 ||
            rules::rpLmDrainHpLo() != 2 ||
            rules::rpLmDrainHpHi() != 8) ++bad;
        // the four weapon forms: +2 mace, +1 flame
        // sword, +4 battle axe, +3 spear
        static const int kLmBonus[4] = {
            2, 1, 4, 3,
        };
        if (rules::rpLmWeaponFormCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::rpLmWeaponBonus(i) != kLmBonus[i]) ++bad;
        // the spear lengths and the mundane uses
        if (rules::rpLmSpearLenMinFeet() != 6 ||
            rules::rpLmSpearLenMaxFeet() != 15 ||
            rules::rpLmSpearHandleMaxFeet() != 12 ||
            rules::rpLmMundaneUseCount() != 3 ||
            rules::rpLmPoleGrowthPerSegment() != 5 ||
            rules::rpLmPoleMaxFeet() != 50 ||
            rules::rpLmPoleBearPounds() != 4000 ||
            rules::rpLmDoorForceMaxFeet() != 30) ++bad;
        // weapon functions 2 and 3 die with the
        // charges, and the rod never recharges
        if (rules::rpLmExhaustedWeaponCeaseLo() != 2 ||
            rules::rpLmExhaustedWeaponCeaseHi() != 3 ||
            rules::rpLmRechargeable() != 0) ++bad;
        // clamped bonus reads land on the mace below
        // and the spear above
        if (rules::rpLmWeaponBonus(-9) != 2 ||
            rules::rpLmWeaponBonus(99) != 3) ++bad;
        // Rod of Resurrection - the charge table by
        // class (11) and race (7)
        static const int kResClass[11] = {
            1, 2, 2, 1, 2, 3, 3, 3, 4, 3, 2,
        };
        static const int kResRace[7] = {
            3, 4, 3, 2, 2, 4, 1,
        };
        if (rules::rpResUsesPerDay() != 1 ||
            rules::rpResClassCount() != 11 ||
            rules::rpResRaceCount() != 7) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rules::rpResClassCharges(i) != kResClass[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::rpResRaceCharges(i) != kResRace[i]) ++bad;
        // multi-classed takes the least favorable
        if (rules::rpResMultiLeastFavorable() != 1 ||
            rules::rpResRechargeable() != 0) ++bad;
        // clamped reads land on the cleric below and
        // the bard above, the dwarf below and the
        // human above
        if (rules::rpResClassCharges(-9) != 1 ||
            rules::rpResClassCharges(99) != 2 ||
            rules::rpResRaceCharges(-9) != 3 ||
            rules::rpResRaceCharges(99) != 1) ++bad;
        // Rod of Rulership
        if (rules::rpRuleRadiusInches() != 12 ||
            rules::rpRuleHdLo() != 200 ||
            rules::rpRuleHdHi() != 500 ||
            rules::rpRuleSaveIntMin() != 15 ||
            rules::rpRuleSaveHdMin() != 12 ||
            rules::rpRuleActivateSegments() != 5 ||
            rules::rpRuleTurnsPerCharge() != 1 ||
            rules::rpRuleRechargeable() != 0) ++bad;
        // Rod of Smiting
        if (rules::rpSmiteBonus() != 3 ||
            rules::rpSmiteDamageLo() != 4 ||
            rules::rpSmiteDamageHi() != 11 ||
            rules::rpSmiteGolemDamageLo() != 8 ||
            rules::rpSmiteGolemDamageHi() != 22 ||
            rules::rpSmiteGolemDestroyRoll() != 20 ||
            rules::rpSmiteGolemHitChargeDrain() != 1 ||
            rules::rpSmiteOuterTripleRoll() != 20 ||
            rules::rpSmiteOuterChargeDrain() != 1 ||
            rules::rpSmiteOuterDamageMultiple() != 3 ||
            rules::rpSmiteRechargeable() != 0) ++bad;
        printf("R244 rods prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R227: the wis mental save wiring audit ----
    // PHB Wisdom Table I: the magical attack
    // saving throw adjustment now reaches the
    // spell save rolls - the R192 ladder had
    // zero callers. The gate seam
    // rules::wisMentalSaveAdj (wisdom.h); the
    // delegation spells::spellSaveModWis; the
    // spelleffects fold (saveBonus carries the
    // gated ladder; the descriptor carries the
    // defender WIS). Charm person and charm
    // monster are the registry mental forms.
    {
        int bad = 0;
        if (rules::wisMentalSaveAdj(3, true) != -3 ||
            rules::wisMentalSaveAdj(4, true) != -2 ||
            rules::wisMentalSaveAdj(5, true) != -1 ||
            rules::wisMentalSaveAdj(7, true) != -1 ||
            rules::wisMentalSaveAdj(8, true) != 0 ||
            rules::wisMentalSaveAdj(14, true) != 0 ||
            rules::wisMentalSaveAdj(15, true) != 1 ||
            rules::wisMentalSaveAdj(16, true) != 2 ||
            rules::wisMentalSaveAdj(17, true) != 3 ||
            rules::wisMentalSaveAdj(18, true) != 4) ++bad;
        // the ladder clamps (below 3, above 18)
        if (rules::wisMentalSaveAdj(0, true) != -3 ||
            rules::wisMentalSaveAdj(19, true) != 4 ||
            rules::wisMentalSaveAdj(25, true) != 4) ++bad;
        // non-mental forms read flat 0
        if (rules::wisMentalSaveAdj(18, false) != 0 ||
            rules::wisMentalSaveAdj(3, false) != 0 ||
            rules::wisMentalSaveAdj(10, false) != 0) ++bad;
        // ladder consistency: the gated form
        // equals the R192 ladder cell by cell
        for (int w = 3; w <= 18; ++w)
            if (rules::wisMentalSaveAdj(w, true) !=
                    rules::wisMagicalAttackAdj(w) ||
                rules::wisMentalSaveAdj(w, false) != 0) ++bad;
        // the fold: an existing caller-side
        // saveBonus rides WITH the gate, not
        // instead of it (+2 probe)
        static const int kW[5] = { 3, 8, 12, 15, 18, };
        for (int i = 0; i < 5; ++i)
            if (rules::wisMentalSaveAdj(kW[i], true) + 2 !=
                    rules::wisMagicalAttackAdj(kW[i]) + 2) ++bad;
        for (int i = 0; i < 5; ++i)
            if (rules::wisMentalSaveAdj(kW[i], false) + 2 != 2) ++bad;
        printf("R227 wis mental save wiring audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R228: the druid registry parameters audit ----
    // The evaluable seam walk: the rules/druidspells.h
    // R228 parameter tables vs the book-pin arrays (the
    // PHB spell description headers). The registry rows
    // themselves are walked by the extended R80 battery
    // block - spells.cpp structs are outside the
    // audit_eval subset.
    {
        int bad = 0;
        static const int kLv[77] = {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
            5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 6, 7, 7,
            7, 7, 7, 7, 7, 7, 7,
        };
        static const int kRv[77] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
            0, 1, 0, 0, 1, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 1, 0, 0,
        };
        static const int kCt[77] = {
            360, 3, 3, 3, 3, 4, 10, 10, 10, 10,
            1, 3, 3, 4, 60, 4, 3, 60, 4, 10,
            4, 4, 4, 4, 60, 10, 5, 5, 10, 5,
            5, 30, 10, 10, 5, 5, 6, 0, 6, 6,
            6, 6, 6, 6, 6, 6, 10, 60, 7, 7,
            7, 60, 7, 5, 60, 7, 8, 10, 7, 60,
            7, 8, 8, 3, 8, 8, 60, 60, 60, 9,
            60, 60, 9, 5, 9, 60, 9,
        };
        static const int kRg[77] = {
            1, 0, 0, 8, 8, 0, 0, 0, 0, 4,
            0, 0, 0, 8, 1, 0, 1, 0, 4, 0,
            0, 0, 0, 1, 0, 0, 8, 0, 16, 0,
            16, 0, 0, 3, 0, 0, 4, 12, 0, 0,
            8, 8, 8, 0, 4, 0, 0, 0, 8, 6,
            0, 0, 0, 32, 8, 0, 8, 0, 4, 8,
            16, 0, 16, 0, 0, 8, 0, 8, 4, 4,
            0, 1, 0, 6, 16, 0, 8,
        };
        static const int kDu[77] = {
            0, 12, 4, 10, 4, 10, 1, 10, 120, 0,
            1, 2, 4, 0, 0, 0, 4, 0, 7, 10,
            4, 2, 10, 0, 10, 0, 2, 0, 0, 0,
            0, 0, 0, 1, 60, 60, 0, 0, 40, 0,
            0, 0, 1, 10, 1, 0, 10, 2, 2, 0,
            10, 0, 10, 10, 0, 0, 0, 10, 2, 10,
            0, 0, 0, 0, 4, 10, 0, 1, 1, 10,
            0, 60, 4, 0, 1, 0, 0,
        };
        static const int kAo[77] = {
            0, 0, 0, 2, 4, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 36, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 1, 4, 0, 0,
            1, 0, 0, 2, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
        };
        static const int kSv[77] = {
            4, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, 4, -1, -1, -1, 4, -1, -1,
            -1, -1, 4, -1, 4, -1, 4, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, 4, -1, -1,
            -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, 4, 4, -1, -1,
        };
        static const int kTg[77] = {
            1, 2, 2, 2, 2, 1, 2, 1, 4, 2,
            4, 1, 1, 1, 2, 1, 1, 4, 4, 2,
            4, 4, 4, 4, 2, 1, 1, 1, 2, 1,
            4, 2, 2, 4, 0, 1, 4, 4, 2, 1,
            2, 2, 4, 4, 2, 1, 2, 2, 2, 4,
            2, 4, 2, 2, 4, 4, 4, 2, 2, 4,
            2, 1, 1, 4, 2, 2, 4, 2, 4, 4,
            4, 4, 4, 1, 2, 1, 4,
        };
        for (int i = 0; i < 77; ++i)
            if (rules::druidSpellLevel(i) != kLv[i] ||
                rules::druidSpellRev(i) != kRv[i] ||
                rules::druidSpellCt(i) != kCt[i] ||
                rules::druidSpellRangeTens(i) != kRg[i] ||
                rules::druidSpellDur(i) != kDu[i] ||
                rules::druidSpellAoeTens(i) != kAo[i] ||
                rules::druidSpellSaveCat(i) != kSv[i] ||
                rules::druidSpellTarget(i) != kTg[i]) ++bad;
        // the clamps: -5 and 99 read rows 0 and 76
        if (rules::druidSpellLevel(-5) != kLv[0] ||
            rules::druidSpellLevel(99) != kLv[76] ||
            rules::druidSpellCt(99) != kCt[76]) ++bad;
        // the level histogram ladder: the seam pins
        // the printed roster counts (12/12/12/12/8/
        // 12/9 - R182); every seam level sits in 1..7
        // (the reversible count 16 and the 11 Neg./
        // half saves are properties of the pin arrays
        // above, walked cellwise)
        static const int kHist[7] = { 12, 12, 12, 12, 8, 12, 9 };
        for (int l = 1; l <= 7; ++l)
            if (rules::druidSpellCountByLevel(l) != kHist[l - 1]) ++bad;
        for (int i = 0; i < 77; ++i)
            if (rules::druidSpellLevel(i) < 1 ||
                rules::druidSpellLevel(i) > 7) ++bad;
        // the R182 slot table cross-checks (a spell-level
        // 8 query clamps to the 7th: 3)
        if (rules::druidSpellSlots(1, 1) != 2 ||
            rules::druidSpellSlots(12, 4) != 4 ||
            rules::druidSpellSlots(14, 7) != 3 ||
            rules::druidSpellSlots(14, 8) != 3) ++bad;
        printf("R228 druid registry parameters audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R229: the illusionist registry parameters audit ----
    // The evaluable seam walk: the rules/illusionspells.h
    // R229 parameter tables vs the book-pin arrays (the
    // PHB illusionist spell description headers; the
    // OCR-scattered blocks pinned as JUDGMENTs). The
    // registry rows themselves are walked by the extended
    // R80 battery block - spells.cpp structs are outside
    // the audit_eval subset.
    {
        int bad = 0;
        static const int kLv[61] = {
            1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
            7,
        };
        static const int kCt[61] = {
            5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
            2, 2, 2, 2, 2, 2, 3, 2, 4, 2,
            50, 2, 0, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 4, 3, 4, 4, 4, 60, 4, 4,
            5, 5, 60, 5, 5, 6, 2, 6, 5, 6,
            5, 6, 9, 10, 5, 3, 0, 180, 7, 7,
            7,
        };
        static const int kRg[61] = {
            6, 1, 0, 0, 3, 6, 6, 3, 3, 0,
            6, 0, 1, 0, 6, 0, 1, 0, 0, 0,
            2, 3, 0, 1, 0, 6, 6, 0, 1, 1,
            0, 6, 0, 3, 1, 8, 0, 0, 0, 3,
            0, 3, 1, 0, 0, 3, 1, 1, 5, 1,
            1, 3, 3, 0, 6, 1, 0, 0, 0, 1,
            0,
        };
        static const int kDu[61] = {
            3, 5, 2, 1, 1, 10, 0, 2, 0, 3,
            0, 2, 4, 0, 0, 0, 0, 0, 0, 3,
            0, 1, 0, 4, 0, 0, 0, 10, 0, 0,
            20, 0, 4, 40, 0, 1, 30, 60, 1, 1,
            1, 1, 60, 0, 1, 40, 40, 0, 0, 0,
            1, 1, 1, 1, 0, 10, 0, 0, 0, 10,
            0,
        };
        static const int kAo[61] = {
            0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 3, 6, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0,
        };
        static const int kSv[61] = {
            -1, -1, -1, -1, 4, -1, -1, -1, 4, -1,
            4, -1, -1, 4, -1, -1, -1, -1, 4, -1,
            -1, 4, -1, -1, -1, -1, -1, -1, 4, 4,
            -1, -1, -1, 4, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1,
        };
        static const int kTg[61] = {
            4, 2, 0, 4, 3, 2, 2, 4, 1, 0,
            1, 2, 2, 2, 2, 1, 4, 4, 2, 0,
            2, 4, 1, 4, 2, 2, 2, 0, 2, 2,
            4, 2, 1, 1, 2, 2, 3, 4, 1, 2,
            2, 2, 4, 1, 4, 3, 4, 2, 4, 2,
            2, 2, 4, 1, 4, 2, 0, 4, 2, 4,
            0,
        };
        for (int i = 0; i < 61; ++i)
            if (rules::illusionistSpellLevel(i) != kLv[i] ||
                rules::illusionistSpellCt(i) != kCt[i] ||
                rules::illusionistSpellRangeTens(i) != kRg[i] ||
                rules::illusionistSpellDur(i) != kDu[i] ||
                rules::illusionistSpellAoeTens(i) != kAo[i] ||
                rules::illusionistSpellSaveCat(i) != kSv[i] ||
                rules::illusionistSpellTarget(i) != kTg[i]) ++bad;
        // the clamps: -5 and 99 read rows 0 and 60
        if (rules::illusionistSpellLevel(-5) != kLv[0] ||
            rules::illusionistSpellLevel(99) != kLv[60] ||
            rules::illusionistSpellCt(99) != kCt[60]) ++bad;
        // the level histogram ladder: the seam pins the
        // printed roster counts (8/16/11/5/12/4/5 - R183);
        // every seam level sits in 1..7
        static const int kHist[7] = { 8, 16, 11, 5, 12, 4, 5 };
        for (int l = 1; l <= 7; ++l)
            if (rules::illusionistSpellCountByLevel(l) != kHist[l - 1]) ++bad;
        for (int i = 0; i < 61; ++i)
            if (rules::illusionistSpellLevel(i) < 1 ||
                rules::illusionistSpellLevel(i) > 7) ++bad;
        // the R183 slot table cross-checks (past 26 the
        // table clamps to the 26th row; a spell-level 8
        // query clamps to the 7th)
        if (rules::illusionistSpellSlots(1, 1) != 1 ||
            rules::illusionistSpellSlots(5, 2) != 2 ||
            rules::illusionistSpellSlots(12, 4) != 3 ||
            rules::illusionistSpellSlots(26, 7) != 6 ||
            rules::illusionistSpellSlots(30, 8) != 6) ++bad;
        printf("R229 illusionist registry parameters audit: bad %d\n", bad);
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
    // ---- R171: appendices K L and M audit -------------
    // DMG pp.221-224: the substance word lists, the
    // conjured animals table and the summoned monsters
    // tables, cell by cell (the trusted-compilation
    // judgments recorded in the gap report).
    {
        int bad = 0;
        // Appendix K: the appearance list
        static const char* kApp[10] = {
            "bubbling", "cloudy", "effervescent",
            "fuming", "oily", "smoky", "syrupy",
            "vaporous", "viscous", "watery"
        };
        if (rules::klmAppearanceCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i)
            if (std::string(rules::klmAppearance(i))
                    != kApp[i])
                ++bad;
        // the transparency list with parentheticals
        static const char* kTr[10] = {
            "clear (transparent)",
            "flecked (transparent and other)",
            "layered (color or transparency)",
            "luminous (determine transparency)",
            "opaline (glowing)",
            "phosphorescent (determine transparency)",
            "rainbowed (transparent)",
            "ribboned (determine transparency)",
            "translucent",
            "variegated (determine colors)"
        };
        static const bool kTrDet[10] = {
            false, false, false, true, false, true,
            false, true, false, true
        };
        if (rules::klmTransparencyCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i) {
            if (std::string(rules::klmTransparency(i))
                    != kTr[i])
                ++bad;
            if (rules::klmTransparencyNeedsDetermination(i)
                    != kTrDet[i])
                ++bad;
        }
        // the color list: 11 groups, 74 words
        static const char* kGrp[11] = {
            "METALLIC", "WHITE", "GRAY", "BROWN",
            "BLACK", "VIOLET", "YELLOW", "RED",
            "GREEN", "BLUE", "ORANGE"
        };
        static const int kGrpN[11] = {
            6, 4, 3, 6, 5, 10, 10, 16, 3, 6, 5
        };
        static const char* kCol[74] = {
            "brassy", "bronze", "coppery", "gold",
            "silvery", "steely",
            "bone", "colorless", "ivory", "pearl",
            "dove", "dun", "neutral",
            "chocolate", "ecru", "fawn", "mahogany",
            "tan", "terra cotta",
            "ebony", "inky", "pitchy", "sable",
            "sooty",
            "fuchsia", "heliotrope", "lake", "lavender",
            "lilac", "magenta", "mauve", "plum", "puce",
            "purple",
            "amber", "buff", "citrine", "cream",
            "fallow", "flaxen", "ochre", "peach",
            "saffron", "straw",
            "carmine", "cerise", "cherry", "cinnabar",
            "coral", "crimson", "madder", "maroon",
            "pink", "rose", "ruby", "russet", "rust",
            "sanguine", "scarlet", "vermillion",
            "aquamarine", "emerald", "olive",
            "azure", "cerulean", "indigo", "sapphire",
            "turquoise", "ultramarine",
            "apricot", "flame", "golden", "salmon",
            "tawny"
        };
        static const int kColOff[11] = {
            0, 6, 10, 13, 19, 24, 34, 44, 60, 63, 69
        };
        if (rules::klmColorGroupCount() != 11) ++bad;
        int colTotal = 0;
        for (int g = 0; g < 11; ++g) {
            if (std::string(rules::klmColorGroupName(g))
                    != kGrp[g])
                ++bad;
            if (rules::klmColorGroupSize(g) != kGrpN[g])
                ++bad;
            colTotal += kGrpN[g];
            for (int j = 0; j < kGrpN[g]; ++j)
                if (std::string(
                        rules::klmColorWord(g, j))
                        != kCol[kColOff[g] + j])
                    ++bad;
        }
        if (colTotal != 74) ++bad;
        // the taste and/or odor list
        static const char* kTa[28] = {
            "acidic", "bilious", "bitter",
            "burning/biting", "buttery", "dusty",
            "earthy", "fiery", "fishy", "greasy",
            "herbal", "honeyed", "lemony", "meaty",
            "metallic", "milky", "musty", "oniony",
            "peppery", "perfumy", "salty",
            "soothing/sugary", "sour", "spicy",
            "sweet", "tart", "vinegary", "watery"
        };
        if (rules::klmTasteCount() != 28) ++bad;
        for (int i = 0; i < 28; ++i)
            if (std::string(rules::klmTaste(i)) != kTa[i])
                ++bad;
        if (!rules::klmUsedWithDungeonDressing()) ++bad;
        // Appendix L: the prose
        if (!rules::klmConjFractionalCostCharged() ||
            !rules::klmConjRandomSelectionWhereSeveral() ||
            !rules::klmConjCasterCannotSpecify() ||
            rules::klmConjWhaleMaxHitDiceCost() != 36 ||
            !rules::klmConjWaterSwimmersAndFlyersOnly())
            ++bad;
        // the conjured animals categories: bands,
        // names and quarter costs, cell by cell
        static const int kCjN[4] = { 5, 4, 15, 13 };
        static const int kCjLo[37] = {
            1, 16, 46, 56, 66,
            1, 26, 36, 61,
            1, 6, 11, 16, 21, 31, 41, 46, 56, 66,
            76, 81, 86, 91, 96,
            1, 6, 16, 21, 31, 41, 46, 51, 56, 61,
            66, 76, 86
        };
        static const int kCjHi[37] = {
            15, 45, 55, 65, 100,
            25, 35, 60, 100,
            5, 10, 15, 20, 30, 40, 45, 55, 65, 75,
            80, 85, 90, 95, 100,
            5, 15, 20, 30, 40, 45, 50, 55, 60, 65,
            75, 85, 100
        };
        static const int kCjQ[37] = {
            5, 5, 2, 2, 2,
            6, 8, 8, 8,
            12, 12, 12, 12, 10, 10, 12, 13, 12, 13,
            10, 12, 12, 10, 12,
            17, 15, 16, 15, 16, 16, 16, 17, 14, 16,
            16, 15, 15
        };
        static const char* kCjName[37] = {
            "baboon", "dog, wild", "flightless bird",
            "jackal", "rat, giant",
            "badger", "flightless bird", "herd animal",
            "horse, wild",
            "axe beak", "badger, giant", "boar/warthog",
            "camel", "cattle, wild", "dog, war",
            "flightless bird", "goat, giant", "hyena",
            "lion, mountain", "lynx, giant", "mule",
            "stag", "wolf", "wolverine",
            "ape", "bear, black", "beaver, giant",
            "boar, wild", "bull", "eagle, giant",
            "Irish deer", "jaguar", "leopard",
            "owl, giant", "ram, giant",
            "weasel, giant", "wolf, dire"
        };
        if (rules::klmConjCategoryCount() != 4) ++bad;
        int cjFlat = 0;
        for (int c = 0; c < 4; ++c) {
            if (rules::klmConjRowCount(c) != kCjN[c])
                ++bad;
            for (int r = 0; r < kCjN[c]; ++r) {
                const rules::ConjuredAnimalRow& row =
                    rules::klmConjRow(c, r);
                if (row.lo != kCjLo[cjFlat] ||
                    row.hi != kCjHi[cjFlat] ||
                    row.costQ != kCjQ[cjFlat] ||
                    std::string(row.name)
                        != kCjName[cjFlat])
                    ++bad;
                ++cjFlat;
            }
        }
        if (cjFlat != 37) ++bad;
        // the 5-and-up roster (band columns are OCR
        // debt, the open finding)
        // R175: the 20-name roster became the full
        // banded table (26 rows) - the count check
        // here keeps the R171 audit honest; the
        // cell-by-cell check lives in the R175
        // audit block below
        if (rules::klmConjHigherCount() != 26)
            ++bad;
        // Appendix M: the prose
        if (!rules::klmSummonEvilUsesParenthesis() ||
            !rules::klmSummonDMMaySelectAndAppoint())
            ++bad;
        // the 7 land tables: bands, names and evil
        // alternates, cell by cell
        static const int kLdN[7] = {
            6, 6, 12, 12, 12, 16, 34
        };
        static const int kLdLo[98] = {
            1, 11, 26, 41, 56, 71,
            1, 16, 26, 46, 61, 76,
            1, 8, 18, 26, 33, 41, 48, 58, 68, 76,
            86, 96,
            1, 8, 16, 26, 36, 43, 51, 59, 68, 77,
            87, 94,
            1, 8, 18, 27, 37, 46, 56, 64, 73, 79,
            86, 91,
            1, 7, 13, 20, 27, 32, 39, 44, 52, 57,
            64, 69, 79, 85, 89, 93,
            1, 4, 7, 10, 13, 16, 19, 22, 24, 27,
            30, 33, 36, 39, 42, 44, 47, 50, 53, 56,
            59, 62, 65, 68, 71, 74, 77, 80, 83, 86,
            89, 92, 95, 98
        };
        static const int kLdHi[98] = {
            10, 25, 40, 55, 70, 100,
            15, 25, 45, 60, 75, 100,
            7, 17, 25, 32, 40, 47, 57, 67, 75, 85,
            95, 100,
            7, 15, 25, 35, 42, 50, 58, 67, 76, 86,
            93, 100,
            7, 17, 26, 36, 45, 55, 63, 72, 78, 85,
            90, 100,
            6, 12, 19, 26, 31, 38, 43, 51, 56, 63,
            68, 78, 84, 88, 92, 100,
            3, 6, 9, 12, 15, 18, 21, 23, 26, 29,
            32, 35, 38, 41, 43, 46, 49, 52, 55, 58,
            61, 64, 67, 70, 73, 76, 79, 82, 85, 88,
            91, 94, 97, 100
        };
        static const char* kLdName[98] = {
            "demon, manes", "goblin", "hobgoblin",
            "kobold", "orc", "rat, giant",
            "centipede, giant", "devil, lemure",
            "gnoll", "stirge", "toad, giant",
            "troglodyte",
            "beetle, boring", "bugbear",
            "gelatinous cube", "ghoul",
            "lizard, giant", "lycanthrope, wererat",
            "ochre jelly", "ogre", "spider, huge",
            "spider, large", "tick, giant",
            "weasel, giant",
            "ape, carnivorous", "gargoyle", "ghast",
            "gray ooze", "hell hound",
            "hydra, 5 heads",
            "lycanthrope, werewolf", "owlbear",
            "shadow", "snake, giant, constrictor",
            "toad, ice", "toad, poisonous",
            "cockatrice", "displacer beast",
            "doppleganger", "hydra, 7 heads",
            "leucrotta", "lizard, subterranean",
            "lycanthrope, wereboar", "minotaur",
            "snake, giant, amphisbaena",
            "snake, giant, poisonous",
            "snake, giant, spitting", "spider, giant",
            "carrion crawler", "devil, erinyes",
            "hydra, 8 heads", "jackalwere",
            "lycanthrope, weretiger", "manticore",
            "ogre magi", "otyugh", "rakshasa",
            "salamander", "spider, phase", "troll",
            "wight", "wind walker", "wraith",
            "wyvern",
            "chimera", "demon, succubus",
            "demon, type I", "demon, type II",
            "demon, type III", "devil, barbed",
            "devil, bone", "devil, horned", "ettin",
            "giant, fire", "giant, frost",
            "giant, hill", "giant, stone", "gorgon",
            "groaning spirit", "hydra, 10 heads",
            "hydra, pyro-, 8 heads",
            "intellect devourer", "invisible stalker",
            "lamia", "lizard, fire", "mind flayer",
            "mummy", "naga, spirit", "neo-otyugh",
            "night hag", "roper", "shambling mound",
            "slug, giant", "spectre",
            "sphinx, hieraco- (andro-)", "umber hulk",
            "will-o-wisp", "xorn"
        };
        static const char* kLdEvil[98] = {
            "", "dwarf", "elf", "halfling",
            "gnome", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "blink dog", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "lammasu",
            "werebear", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "couatl", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "shedu", "",
            "", "", "", "",
            "", ""
        };
        if (rules::klmSummonLandTableCount() != 7)
            ++bad;
        int ldFlat = 0;
        for (int t = 0; t < 7; ++t) {
            if (rules::klmSummonLandRowCount(t)
                    != kLdN[t])
                ++bad;
            for (int r = 0; r < kLdN[t]; ++r) {
                const rules::SummonedMonsterRow& row =
                    rules::klmSummonLandRow(t, r);
                if (row.lo != kLdLo[ldFlat] ||
                    row.hi != kLdHi[ldFlat] ||
                    std::string(row.name)
                        != kLdName[ldFlat])
                    ++bad;
                // the evil alternate: empty string or null
                const char* alt = row.evilAlt;
                if (kLdEvil[ldFlat][0] == 0) {
                    if (alt != 0) ++bad;
                } else {
                    if (alt == 0 ||
                        std::string(alt) != kLdEvil[ldFlat])
                        ++bad;
                }
                ++ldFlat;
            }
        }
        if (ldFlat != 98) ++bad;
        // the 13 water tables, cell by cell
        static const int kWtN[13] = {
            2, 2, 1, 2, 2, 2, 4, 3, 2, 4, 2, 2, 3
        };
        static const int kWtLo[31] = {
            1, 68,   1, 51,   1,   1, 34,   1, 34,
            1, 51,   1, 34, 51, 68,   1, 41, 81,
            1, 81,   1, 51, 71, 91,   1, 34,
            1, 21,   1, 16, 71
        };
        static const int kWtHi[31] = {
            67, 100,   50, 100,   100,   33, 100,
            33, 100,   50, 100,   33, 50, 67, 100,
            40, 80, 100,   80, 100,   50, 70, 90,
            100,   33, 100,   20, 100,   15, 70,
            100
        };
        static const char* kWtName[31] = {
            "koalinth", "nixie",
            "koalinth", "merman",
            "lizard man",
            "ixitxachitl", "locathah",
            "crab, giant", "lacedon",
            "lacedon", "sahuagin",
            "beetle, water, giant", "crayfish, giant",
            "kopoacinth", "spider, water, giant",
            "kopoacinth", "lobster (crayfish), giant",
            "triton",
            "crocodile, giant", "water weird",
            "crocodile, giant", "sea hag", "sea lion",
            "water weird",
            "octopus, giant", "snake, sea, giant",
            "morkoth", "naga, water",
            "morkoth", "ray, manta", "squid, giant"
        };
        static const char* kWtEvil[31] = {
            "hobgoblin", "",
            "hobgoblin", "",
            "",
            "", "",
            "", "ghoul",
            "ghoul", "",
            "", "", "gargoyle", "",
            "gargoyle", "", "",
            "", "",
            "", "", "", "",
            "", "",
            "", "",
            "", "", ""
        };
        static const char* kWtTab[13] = {
            "Monster Summoning I, fresh water",
            "Monster Summoning I, salt water",
            "Monster Summoning II, fresh water",
            "Monster Summoning II, salt water",
            "Monster Summoning III, fresh water",
            "Monster Summoning III, salt water",
            "Monster Summoning IV, fresh water",
            "Monster Summoning IV, salt water",
            "Monster Summoning V, fresh water",
            "Monster Summoning V, salt water",
            "Monster Summoning VI, fresh or salt water",
            "Monster Summoning VII, fresh water",
            "Monster Summoning VII, salt water"
        };
        if (rules::klmSummonWaterTableCount() != 13)
            ++bad;
        int wtFlat = 0;
        for (int t = 0; t < 13; ++t) {
            if (rules::klmSummonWaterRowCount(t)
                    != kWtN[t])
                ++bad;
            if (std::string(
                    rules::klmSummonWaterTableName(t))
                    != kWtTab[t])
                ++bad;
            for (int r = 0; r < kWtN[t]; ++r) {
                const rules::SummonedMonsterRow& row =
                    rules::klmSummonWaterRow(t, r);
                if (row.lo != kWtLo[wtFlat] ||
                    row.hi != kWtHi[wtFlat] ||
                    std::string(row.name)
                        != kWtName[wtFlat])
                    ++bad;
                const char* alt = row.evilAlt;
                if (kWtEvil[wtFlat][0] == 0) {
                    if (alt != 0) ++bad;
                } else {
                    if (alt == 0 ||
                        std::string(alt) != kWtEvil[wtFlat])
                        ++bad;
                }
                ++wtFlat;
            }
        }
        if (wtFlat != 31) ++bad;
        printf("R171 appendices K L and M audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R175: appendix L 5-and-up table audit -----
    // DMG p.222: the full 5-and-up section the
    // book upload drops - pinned from the
    // 1eonline.info compilation (the repo-trusted
    // source). Hit dice categories 5-14, 26 rows
    // cell by cell: the banded categories (5, 6,
    // 7, 8, 10, 12) with every dice-score column;
    // the bandless rows (9, 11, 13, 14) the print
    // dashes, pinned as lo/hi 0. JUDGMENT: the
    // compilation spelling woolly (the R171 wooly
    // corrected); the bandless rows carry no
    // dice-score column, so only the contiguity
    // walk gates the banded ones.
    {
        int bad = 0;
        static const int kCat[26] = {
            5, 5, 5, 5, 5, 5, 5,
            6, 6, 6, 6,
            7, 7,
            8, 8, 8,
            9,
            10, 10,
            11,
            12, 12,
            13, 13,
            14, 14
        };
        static const int kLo[26] = {
             1, 11, 26, 36, 51, 71, 86,
             1, 41, 61, 81,
             1, 66,
             1, 31, 71,
             0,
             1, 61,
             0,
             1, 61,
             0, 0,
             0, 0
        };
        static const int kHi[26] = {
            10, 25, 35, 50, 70, 85, 100,
            40, 60, 80, 100,
            65, 100,
            30, 70, 100,
            0,
            60, 100,
            0,
            60, 100,
            0, 0,
            0, 0
        };
        static const char* const kNm[26] = {
            "ape, carnivorous",
            "buffalo",
            "hyena, giant",
            "otter, giant",
            "skunk, giant",
            "stag, giant",
            "wolverine, giant",
            "bear, brown",
            "lion",
            "porcupine, giant",
            "tiger",
            "boar, giant",
            "lion, spotted",
            "bear, cave",
            "hippopotamus",
            "tiger, sabre-tooth",
            "rhinoceros",
            "elephant",
            "rhinoceros, woolly",
            "elephant (loxodont)",
            "mastodon",
            "titanothere",
            "mammoth",
            "whale (small)",
            "baluchitherium",
            "whale (small)"
        };
        static const int kCost[26] = {
            20, 20, 20, 20, 20, 20, 20,
            25, 22, 24, 25,
            28, 26,
            30, 32, 30,
            34,
            40, 40,
            44,
            48, 48,
            52, 52,
            56, 56
        };
        if (rules::klmConjHigherCount() != 26) ++bad;
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if (r.cat  != kCat[i])  ++bad;
            if (r.lo   != kLo[i])   ++bad;
            if (r.hi   != kHi[i])   ++bad;
            if (std::string(r.name) != kNm[i]) ++bad;
            if (r.cost != kCost[i]) ++bad;
        }
        // the clamps: index -1 and 26+ read the ends
        if (rules::klmConjHigherRow(-1).cat != 5 ||
            rules::klmConjHigherRow(99).cat != 14)
            ++bad;
        // the banded categories: first row lo 1,
        // contiguous bands, last row hi 100
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if (r.lo == 0) continue;   // bandless
            bool first = (i == 0) ||
                rules::klmConjHigherRow(i - 1).cat
                    != r.cat;
            bool last = (i == 25) ||
                rules::klmConjHigherRow(i + 1).cat
                    != r.cat;
            if (first && r.lo != 1) ++bad;
            if (last) {
                if (r.hi != 100) ++bad;
            } else {
                const rules::ConjHigherRow& n =
                    rules::klmConjHigherRow(i + 1);
                if (r.hi + 1 != n.lo) ++bad;
            }
        }
        // the bandless categories are 9, 11, 13, 14
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if ((r.cat == 9 || r.cat == 11 ||
                 r.cat == 13 || r.cat == 14)
                && (r.lo != 0 || r.hi != 0)) ++bad;
        }
        // the whale cap and the water note stand
        if (rules::klmConjWhaleMaxHitDiceCost() != 36)
            ++bad;
        if (!rules::klmConjWaterSwimmersAndFlyersOnly())
            ++bad;
        printf("R175 appendix L 5-and-up table audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R172: appendix J herbs audit --------------
    // DMG p.220: the alphabetical plant and uses
    // table, 171 rows, cell by cell - the
    // trusted-compilation judgments recorded in
    // the gap report.
    {
        int bad = 0;
        static const char* jP[171] = {
            "abscess root (sweet root)",
            "acacia (Gum Arabic)",
            "aconite (monkshood, wolfsbane, friar's cap, etc.)",
            "acorn",
            "adder's tongue",
            "adrue",
            "agar-agar (jelly)",
            "agaric",
            "agrimony (cocklebur, stickwort)",
            "alder",
            "alkanet root",
            "all-heal (wound-wort)",
            "almond milk/powder",
            "aloe (bitter aloe)",
            "amaranth (red cockscomb, love-lies-bleeding)",
            "ammoniacum (Persian Gum)",
            "angelica",
            "anise",
            "arbutus (mayflower)",
            "areca nut (betel nut)",
            "arenaria rubra (sandwort)",
            "arrach (goosefoot)",
            "artichoke juice",
            "asafetida (gum asafetida, devil's dung, food of the gods)",
            "asarabacca (hazelwort, wild nard)",
            "ash (bark and leaves of)",
            "asparagus juice/root",
            "avens (colewort, herb bennet)",
            "bael",
            "balm (sweet balm) leaves",
            "balm of gilead",
            "balmony (bitter herb, snake head)",
            "barley",
            "basil",
            "bay leaf",
            "beet",
            "belladonna (deadly nightshade, dwale, black cherry root)",
            "benne (sesam, sesame)",
            "benzoin (gum benzoin)",
            "berberis",
            "beth root (lamb's quarters)",
            "bilberry (huckleberry, hurtleberry, whortleberry)",
            "birch (white birch)",
            "birthwort",
            "bistort (adderwort)",
            "bittersweet (felonwort, scarlet berry, woody nightshade)",
            "blackberry (dewberry)",
            "black currant",
            "black willow (pussy willow) bark",
            "blueberry - see bilberry",
            "blue flag (flag lily, poison flag, water flag, water lily)",
            "blue mallow (common mallow)",
            "boneset (thoughtwort)",
            "borage",
            "box leaves",
            "bryony",
            "bugle",
            "burdock",
            "butterbur",
            "cabbage juice",
            "calotopis (mudar bark)",
            "camphor (gum camphor)",
            "caraway",
            "cardamom",
            "carrot juice and seeds",
            "castor oil bush",
            "catnip",
            "cayenne",
            "celery",
            "chamomile",
            "chaulmoogra oil",
            "cherry gum",
            "chervil",
            "chives",
            "cinnamon",
            "cleavers (goosegrass)",
            "clover",
            "cloves",
            "comfrey root (healing herb)",
            "coriander",
            "couchgrass",
            "cucumber",
            "cumin seed",
            "dandelion",
            "digitalis (dead men's bells, fairy bells, fairy cap, fairy fingers, foxglove, etc.)",
            "dill",
            "ergot (rye smut)",
            "eyebright",
            "fennel",
            "fenugreek",
            "fig",
            "figwort (scrofula plant, throatwort)",
            "fireweed",
            "fluellin",
            "garden burnet",
            "garlic",
            "gelsemium (wild woodbine)",
            "gentian (bitter root, felwort)",
            "geranium (sweet geranium)",
            "ginger",
            "ginseng",
            "goat's rue",
            "grape juice",
            "hartstongue",
            "hawthorn",
            "hedge mustard",
            "hellebore",
            "honeysuckle",
            "horehound, white",
            "horehound, black",
            "horseradish",
            "hyssop",
            "ipecac",
            "irish moss",
            "jambul seed",
            "jewel weed (balsam weed, pale touch-me-not)",
            "juniper berry",
            "jurubera",
            "kelp (seawrack)",
            "larkspur (knight's spur)",
            "leek",
            "lily-of-the-valley",
            "lotus",
            "lucerne (alfalfa)",
            "lycopodium (common club moss, fox tail, lamb's tail)",
            "mace",
            "marigold",
            "marjoram",
            "masterwort",
            "mistletoe",
            "muira-puama",
            "mustard",
            "nutmeg",
            "nux vomica (poison nut)",
            "onion",
            "oregano",
            "paprika",
            "parsley",
            "parsnip",
            "peach seed",
            "pepper, black",
            "peppermint",
            "pitcher plant",
            "plantain (ripple grass, waybread)",
            "pomegranate",
            "poppy",
            "pumpkin seed",
            "quince",
            "radish",
            "raspberry",
            "rhubarb",
            "rose",
            "rosemary",
            "saffron",
            "sage",
            "sarsaparilla (china root, spikenard)",
            "scopolis",
            "scullcap (madweed)",
            "senna",
            "spearmint",
            "strawberry",
            "summer savory",
            "tamarind",
            "tansy",
            "tarragon",
            "tea",
            "thyme",
            "turmeric",
            "turnip",
            "watercress",
            "white bryony (mandragora)",
        };
        static const char* jU[171] = {
            "respiratory disorders",
            "tissue repair",
            "sedative/drives off werewolves",
            "tissue hardening",
            "emetic, emollient",
            "anti-vomiting, sedative",
            "anti-inflammation, nutrient",
            "astringent, purgative",
            "muscle toner, diuretic",
            "anti-inflammation, tonic",
            "emollient, antiseptic, wormer",
            "antiseptic, anti-spasmodic",
            "nutrient/emollient",
            "bites, burns, laxative, tonic/insect repellent",
            "astringent, anti-hemorrhaging",
            "stimulant, respiratory aid",
            "lungs, liver, spleen, vision, hearing",
            "antacid, digestion, coughing",
            "astringent, bladder infection",
            "astringent, tape wormer",
            "diuretic, urinary diseases",
            "sedative (nervous tension or hysteria in particular)",
            "jaundice curative",
            "aphrodisiac, brain and nervous stimulant, tonic, many more",
            "emetic, purgative",
            "laxative, anti-inflammation, fever",
            "sedative, heart problems/anti-oxalic acid",
            "astringent, anti-hemorrhaging, anti-weakness, tonic, more",
            "anti-inflammation, ulcers",
            "calms nerves, fevers",
            "nutrient, organ stimulant (general)",
            "tissue builder and strengthener, liver ailments, wormer",
            "nutrient (recuperative)",
            "nervous disorders",
            "?",
            "organic cleanser",
            "diuretic, sedative, pain reliever, anti-opiate, circulation, stimulant, poison/lycanthropy cure",
            "respiratory disorders, eye infections, more",
            "expectorant, stimulant, antiseptic, wounds and sores",
            "fevers",
            "astringent, coughs, tonic, anti-hemorrhaging, more",
            "anti-thirst, dropsy, typhoid, more",
            "intestines and stomach, venereal diseases, skin conditions",
            "circulatory stimulant",
            "astringent",
            "abscesses, lymph infections, swelling and inflammation",
            "astringent, tonic, dysentery",
            "diuretic, antiseptic, blood purifier",
            "astringent, antiseptic",
            "",
            "diuretic, cathartic, blood purifier (vs. poison), wound healing, venereal disease, much more",
            "coughs, colds",
            "fevers, tonic, skin diseases",
            "coughs, lung infections",
            "tonic, blood purifier",
            "paralysis, bruises",
            "gastrointestinal disorders, hemorrhaging",
            "laxative, tuberculosis, more",
            "fevers, urinary complaints",
            "ulcer and stomach treatment",
            "skin leprosy, elephantiasis, more",
            "bruises, sprains, chills, fevers, cardiac stimulant",
            "antacid, aids digestion",
            "?",
            "tonic for improved health",
            "purgative, cathartic",
            "colds, fevers, anti-spasmodic, hysteria",
            "stimulant",
            "liver functions, tonic, stimulant",
            "nervous conditions, ear and tooth aches",
            "fevers, sedative, skin eruptions",
            "respiratory infections/food substitute",
            "?",
            "colds, general diseases/evil eye",
            "disinfectant, nausea, preservative",
            "fevers, circulation, blood purifier, wounds, liver disease",
            "tonic",
            "anesthetic, circulation, germicide, disinfectant",
            "colds, respiratory conditions, wounds, bone fractures, gangrene, much, much more",
            "tonic",
            "bladder and urinary infections",
            "inflammation",
            "stimulant",
            "diuretic, purgative, tonic",
            "heart stimulant, tonic, kidney treatment (poison)",
            "nausea",
            "hemorrhaging, venereal diseases",
            "astringent, eye infections",
            "digestion, weight control, muscle tone, reflexes, vision, much, much more",
            "stimulant",
            "demulcent",
            "abscesses, wounds, pain killer",
            "astringent, anti-spasmodic",
            "astringent, tissue strengthener",
            "?",
            "coughs, colds, blood purifier, detoxifier, kills parasites/wards off vampires",
            "sedative, nerve tonic, fevers, more",
            "tonic, fevers, anti-venom",
            "alkalizer",
            "stimulant, colds, cramps",
            "glandular stimulant, vision, dizziness, headaches, weakness",
            "diuretic, wormer (vermifuge)",
            "blood fortifier",
            "cough, liver, spleen, bladder",
            "heart, arteries",
            "throat, lungs",
            "heart tonic (rootlets are poison)",
            "liver, spleen, respiratory disorders",
            "coughs, pulmonary diseases, anti-venom",
            "stimulant, wormer, hemorrhaging",
            "tonic, antiseptic, wormer",
            "respiratory ailments, jaundice, blood purifier, tonic, cuts and wounds, more",
            "dysentery, mouth infections, more",
            "coughs, scalds, burns",
            "blood purifier, diabetes",
            "diuretic, kidneys, skin growths, fungus, infections, liver",
            "aphrodisiac, stimulant, disinfectant, venereal disease, more",
            "anemia",
            "thyroid, heart, arteries, much more",
            "external parasites",
            "same as chives",
            "heart tonic",
            "?",
            "strength",
            "wounds, lungs, kidneys, more",
            "stimulant",
            "fevers, varicosities, eyes, heart",
            "melancholia, dizziness, brain disorders, toothaches",
            "stimulates organs, anti-spasmodic, more",
            "convulsions, hysteria, narcotic, tonic, typhoid fever, heart",
            "aphrodisiac",
            "emetic, counter-irritant, colds, fevers",
            "nausea, vomiting, diarrhea",
            "stimulant, debility tonic",
            "poultice, colds (as chives)",
            "germicide, pain killer",
            "stimulant, poultice",
            "blood purifier",
            "fevers",
            "fevers, blood tonic",
            "sprains, neuritis",
            "?",
            "small pox preventative and cure, stomach, liver, kidneys",
            "minor wounds, stings, rashes",
            "nerve sedative, wormer",
            "?",
            "virility, organ tonic",
            "eye disease, dysentery, skin disorders",
            "blood purifier, liver",
            "fevers, tonic",
            "astringent, cathartic",
            "colds, fevers",
            "germicide, muscle tonic/drives off evil spirits",
            "scarlet fever, measles, respiratory infections",
            "tonic, wounds",
            "system balance, blood purifier, venereal disease, many more",
            "nerve and muscle sedative, pain killer, coughs",
            "nervous disorders, rabies",
            "purgative",
            "?",
            "vision, swelling and inflammation",
            "blood purifier, palsy",
            "infection, gangrene",
            "tonic, narcotic, wormer",
            "?",
            "poison antidote",
            "antiseptic, blood purifier",
            "?",
            "mouth disease, throat",
            "blood tonic (anemia)",
            "cathartic, respiratory diseases, heart, kidneys",
        };
        if (rules::herbsRowCount() != 171) ++bad;
        for (int i = 0; i < 171; ++i) {
            if (std::string(rules::herbsRow(i).plant)
                    != jP[i])
                ++bad;
            if (std::string(rules::herbsRow(i).uses)
                    != jU[i])
                ++bad;
        }
        // the rows the book leaves with unknown uses
        int unknowns = 0;
        for (int i = 0; i < 171; ++i)
            if (std::string(rules::herbsRow(i).uses) == "?")
                ++unknowns;
        if (unknowns != 10) ++bad;
        if (rules::herbsUnknownUsesCount() != 10) ++bad;
        // the one cross-reference row (blueberry)
        int crossrefs = 0;
        for (int i = 0; i < 171; ++i)
            if (rules::herbsIsCrossReference(i))
                ++crossrefs;
        if (crossrefs != 1) ++bad;
        if (!rules::herbsIsCrossReference(49)) ++bad;
        if (std::string(rules::herbsRow(49).plant)
                != "blueberry - see bilberry")
            ++bad;
        if (std::string(rules::herbsRow(49).uses)
                != "")
            ++bad;
        // the intro and closing prose
        if (!rules::herbsIntroHundredsReputedMedicinalAndMagic() ||
            !rules::herbsIntroNotWithinScopeToDetailAll() ||
            !rules::herbsIntroAlphabeticalOneOrTwoComments() ||
            !rules::herbsIntroHerbologistPursuesScholarlyTexts() ||
            !rules::herbsClosingGuideForPotionsInksItems() ||
            !rules::herbsClosingAddOrDeleteAsDesired() ||
            !rules::herbsClosingFolkUsesMagicDMPurview())
            ++bad;
        printf("R172 appendix J herbs audit: bad %d\n", bad);
        if (bad) return 1;
    }
    // ---- R173: secondary skills audit ------------------
    // DMG p.12: the player character non-professional
    // skills - the 23-band table cell by cell and the
    // when-to-use guidance (the judgments recorded in
    // the gap report).
    {
        int bad = 0;
        static const int kLo[23] = {
            1, 3, 5, 11, 15, 21, 24, 28, 33, 35, 38, 40,
            43, 45, 47, 50, 52, 55, 58, 61, 65, 68, 86
        };
        static const int kHi[23] = {
            2, 4, 10, 14, 20, 23, 27, 32, 34, 37, 39, 42,
            44, 46, 49, 51, 54, 57, 60, 64, 67, 85, 100
        };
        static const char* kName[23] = {
            "Armorer",
            "Bowyer/fletcher",
            "Farmer/gardener",
            "Fisher (netting)",
            "Forester",
            "Gambler",
            "Hunter/fisher (hook and line)",
            "Husbandman (animal husbandry)",
            "Jeweler/lapidary",
            "Leather worker/tanner",
            "Limner/painter",
            "Mason/carpenter",
            "Miner",
            "Navigator (fresh or salt water)",
            "Sailor (fresh or salt)",
            "Shipwright (boats or ships)",
            "Tailor/weaver",
            "Teamster/freighter",
            "Trader/barterer",
            "Trapper/furrier",
            "Woodworker/cabinetmaker",
            "NO SKILL OF MEASURABLE WORTH",
            "ROLL TWICE IGNORING THIS RESULT HEREAFTER"
        };
        if (rules::secondaryRowCount() != 23) ++bad;
        for (int i = 0; i < 23; ++i) {
            const rules::SecondarySkillRow& row =
                rules::secondaryRow(i);
            if (row.lo != kLo[i] || row.hi != kHi[i] ||
                std::string(row.name) != kName[i])
                ++bad;
        }
        // the band arithmetic: 1 through 100 clean
        if (kLo[0] != 1) ++bad;
        for (int i = 0; i < 22; ++i)
            if (kHi[i] + 1 != kLo[i + 1]) ++bad;
        if (kHi[22] != 100) ++bad;
        // the special rows
        if (!rules::secondaryIsNoSkill(21)) ++bad;
        if (rules::secondaryIsNoSkill(20)) ++bad;
        if (rules::secondaryIsNoSkill(22)) ++bad;
        if (!rules::secondaryIsRollTwice(22)) ++bad;
        if (rules::secondaryIsRollTwice(21)) ++bad;
        // the intro and adjudication prose
        if (!rules::secondaryClassAssumedPriorProfession() ||
            !rules::secondaryMinorMundaneKnowledgePossible() ||
            !rules::secondaryCampaignAimedAtSkillsUsesTable() ||
            !rules::secondaryAssignRandomOrPerBackground() ||
            !rules::secondarySecondSkillIfTwoSkills() ||
            !rules::secondaryDMAdjudicatesSituations() ||
            !rules::secondarySkillGivesWorthSoundnessRepairs() ||
            !rules::secondaryAssumeRoleToScaleAbility())
            ++bad;
        printf("R173 secondary skills audit: bad %d\n", bad);
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
    // ---- R174: city fiction notes audit ----
    // The two remaining R64 flavor notes, pinned from
    // the fresh DMG upload (p.191-192): the noble
    // gender coin (nobleman-with-retainers 75% /
    // noblewoman 25%, the R149-corrected reading)
    // with the noblewoman 75% sedan-chair likelihood
    // (carriers and linkboys at night), and the
    // ruffian matrix footnote - 1 in 4 half-orc or
    // humanoid (goblin, hobgoblin, kobold, orc),
    // banded as five equal fifths of the quarter
    // (the weights unstated, documented). Every band
    // edge pinned both ways plus the 1-100 sweep.
    {
        int bad = 0;
        // the noble gender coin (p.191): 2 bands
        static const struct { int lo, hi; const char* k; }
            kNoble[] = {
            {  1, 75, "nobleman" },
            { 76,100, "noblewoman" },
        };
        for (int i = 0; i < 2; ++i) {
            if (std::string(dm::cityNobleKind(kNoble[i].lo))
                != kNoble[i].k) ++bad;
            if (std::string(dm::cityNobleKind(kNoble[i].hi))
                != kNoble[i].k) ++bad;
            if (kNoble[i].lo > 1 && std::string(
                    dm::cityNobleKind(kNoble[i].lo - 1))
                == kNoble[i].k) ++bad;
        }
        // the noblewoman ride (p.192): 2 bands
        static const struct { int lo, hi; const char* k; }
            kSedan[] = {
            {  1, 75, "sedan chair" },
            { 76,100, "on foot" },
        };
        for (int i = 0; i < 2; ++i) {
            if (std::string(
                    dm::cityNoblewomanSedan(kSedan[i].lo))
                != kSedan[i].k) ++bad;
            if (std::string(
                    dm::cityNoblewomanSedan(kSedan[i].hi))
                != kSedan[i].k) ++bad;
            if (kSedan[i].lo > 1 && std::string(
                    dm::cityNoblewomanSedan(kSedan[i].lo - 1))
                == kSedan[i].k) ++bad;
        }
        // the ruffian 1-in-4 note (p.191): 6 bands
        static const struct { int lo, hi; const char* k; }
            kRuff[] = {
            {   1, 75, "human" },
            {  76, 80, "half-orc" },
            {  81, 85, "goblin" },
            {  86, 90, "hobgoblin" },
            {  91, 95, "kobold" },
            {  96,100, "orc" },
        };
        for (int i = 0; i < 6; ++i) {
            if (std::string(dm::cityRuffianKind(kRuff[i].lo))
                != kRuff[i].k) ++bad;
            if (std::string(dm::cityRuffianKind(kRuff[i].hi))
                != kRuff[i].k) ++bad;
            if (kRuff[i].lo > 1 && std::string(
                    dm::cityRuffianKind(kRuff[i].lo - 1))
                == kRuff[i].k) ++bad;
        }
        // the sweep: every percentile yields a kind on
        // all three tables (the clamps cover <1 / >100)
        for (int p = 1; p <= 100; ++p) {
            if (!*dm::cityNobleKind(p)) ++bad;
            if (!*dm::cityNoblewomanSedan(p)) ++bad;
            if (!*dm::cityRuffianKind(p)) ++bad;
        }
        printf("R174 city fiction notes audit: bad %d\n", bad);
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
        // the registry grew to 192 (R229): MU 31, CL 23,
        // DR 77, IL 61
        if (spells::SPELL_COUNT != 192) ++bad;
        {
            int mu = 0, cl = 0, dr = 0, il = 0;
            for (int id = 0; id < spells::SPELL_COUNT; ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_MU) ++mu;
                else if (s.sclass == spells::SPELL_DRUID) ++dr;
                else if (s.sclass == spells::SPELL_ILLUSIONIST) ++il;
                else ++cl;
            }
            if (mu != 31 || cl != 23 || dr != 77 ||
                il != 61) ++bad;
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
