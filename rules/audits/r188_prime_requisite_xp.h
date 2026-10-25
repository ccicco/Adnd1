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
    #include "rules/audits/r189_weapon_tables_verify.h"  // R827: migrated
    #include "rules/audits/r190_starting_money.h"  // R827: migrated
    #include "rules/audits/r191_armor_class_ratings.h"  // R827: migrated
    #include "rules/audits/r192_wisdom_tables.h"  // R827: migrated
    #include "rules/audits/r193_charisma_table.h"  // R827: migrated
