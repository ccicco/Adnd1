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

    #include "rules/audits/r230_subclass_creation_seam.h"  // R827: migrated
    #include "rules/audits/r231_subclass_leveling_seam.h"  // R827: migrated
    #include "rules/audits/r232_subclass_specials_hooks.h"  // R827: migrated
    #include "rules/audits/r233a_multi_class_seam.h"  // R827: migrated
    #include "rules/audits/r233_multi_class_engine.h"  // R827: migrated
    #include "rules/audits/r234a_dual_class_seam.h"  // R827: migrated
    #include "rules/audits/r234_dual_class_engine.h"  // R827: migrated
    #include "rules/audits/r235a_bard_career_seam.h"  // R827: migrated
    #include "rules/audits/r235_bard_engine.h"  // R827: migrated
    #include "rules/audits/r236_bard_specials.h"  // R827: migrated
    #include "rules/audits/r181_attacks_per_melee_round.h"  // R827: migrated
    #include "rules/audits/r182_druid_spell_layer.h"  // R827: migrated
    #include "rules/audits/r183_illusionist_spell_layer.h"  // R827: migrated
