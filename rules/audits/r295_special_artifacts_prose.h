    // ---- R295: the III.E Special artifacts
    // explanation prose part 16 ----
    // The Throne of the Gods and the
    // Wand of Orcus, the 28th and 29th
    // descriptions, part2 lines 1782-1814.
    // No break absorbed - the round closes
    // on the standard blank at 1814; the
    // page seam at 1797 absorbed (a running
    // head inside the round).
    {
        int bad = 0;
        // the Throne prose scalars
        if (rules::sapThroneCarvenMountainHeart() != 1 ||
            rules::sapThroneMassiveStoneChair() != 1 ||
            rules::sapThroneMosaicsIvoryMetals() != 1 ||
            rules::sapThroneSetAboutGems() != 1 ||
            rules::sapThroneGodsActuallySat() != 1 ||
            rules::sapThroneWithinGreatCavern() != 1 ||
            rules::sapThroneImmobileImmovable() != 1 ||
            rules::sapThroneAffectsAnyoneSeated() != 1 ||
            rules::sapThroneCertainMagicItem() != 1 ||
            rules::sapThroneMalevolentEffectToo() != 1 ||
            rules::sapThroneItemGainOnlyOnce() != 1 ||
            rules::sapThroneProperWordsGestures() != 1 ||
            rules::sapThroneGraspOptions() != 3) ++bad;
        // the Throne table scalars
        if (rules::sapThroneUseTotal() != 14 ||
            rules::sapThroneTableOneCount() != 3 ||
            rules::sapThroneTableTwoCount() != 3 ||
            rules::sapThroneTableThreeCount() != 2 ||
            rules::sapThroneTableFourCount() != 2 ||
            rules::sapThroneTableFiveCount() != 2 ||
            rules::sapThroneTableSixCount() != 2 ||
            rules::sapThroneBlankSlotCount() != 14 ||
            rules::sapThroneXSignCount() != 6 ||
            rules::sapThroneBulletLineCount() != 0) ++bad;
        static const int kT[6] = {
            3, 3, 2, 2, 2, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapThroneTableUse(i) != kT[i]) ++bad;
        if (rules::sapThroneTableUse(0) +
            rules::sapThroneTableUse(1) +
            rules::sapThroneTableUse(2) +
            rules::sapThroneTableUse(3) +
            rules::sapThroneTableUse(4) +
            rules::sapThroneTableUse(5) !=
            rules::sapThroneUseTotal()) ++bad;
        // the Wand prose scalars
        if (rules::sapWandDemonPrinceProperty() != 1 ||
            rules::sapWandPassesToPrimeMaterial() != 1 ||
            rules::sapWandWreakChaosEvil() != 1 ||
            rules::sapWandMonsterManualRef() != 1 ||
            rules::sapWandSavingThrowVersusMagic() != 1 ||
            rules::sapWandAvoidsDeathAnnihilation() != 1 ||
            rules::sapWandImmuneCount() != 6) ++bad;
        // the Wand table scalars
        if (rules::sapWandUseTotal() != 10 ||
            rules::sapWandTableOneCount() != 4 ||
            rules::sapWandTableTwoCount() != 2 ||
            rules::sapWandTableThreeCount() != 2 ||
            rules::sapWandTableFourCount() != 1 ||
            rules::sapWandTableFiveCount() != 0 ||
            rules::sapWandTableSixCount() != 1 ||
            rules::sapWandBlankSlotCount() != 10 ||
            rules::sapWandXSignCount() != 5 ||
            rules::sapWandBulletLineCount() != 5 ||
            rules::sapWandFourOneSpaceSeparator() != 1 ||
            rules::sapWandFourOneCommaCount() != 2) ++bad;
        static const int kW[6] = {
            4, 2, 2, 1, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapWandTableUse(i) != kW[i]) ++bad;
        if (rules::sapWandTableUse(0) +
            rules::sapWandTableUse(1) +
            rules::sapWandTableUse(2) +
            rules::sapWandTableUse(3) +
            rules::sapWandTableUse(4) +
            rules::sapWandTableUse(5) !=
            rules::sapWandUseTotal()) ++bad;
        // the finale scalars and identities
        if (rules::sapFinalXSignCount() != 11 ||
            rules::sapFinalBlankRunCount() != 24 ||
            rules::sapFinalUnderscoreRunLen() != 14 ||
            rules::sapFinalCurlyApostropheCount() != 2 ||
            rules::sapFinalEmDashCount() != 0 ||
            rules::sapFinalPageSeamLine() != 1797 ||
            rules::sapFinalSpecialDescriptionCount() != 29 ||
            rules::sapFinalXSignCount() !=
            rules::sapThroneXSignCount() +
            rules::sapWandXSignCount() ||
            rules::sapFinalBlankRunCount() !=
            rules::sapThroneBlankSlotCount() +
            rules::sapWandBlankSlotCount() ||
            rules::sapThroneBlankSlotCount() !=
            rules::sapThroneUseTotal() ||
            rules::sapWandBlankSlotCount() !=
            rules::sapWandUseTotal() ||
            rules::sapWandBulletLineCount() !=
            rules::sapWandXSignCount() ||
            rules::sapWandTableFourCount() !=
            rules::sapWandTableSixCount() ||
            rules::sapWandFourOneCommaCount() !=
            rules::sapWandTableOneCount() - 2) ++bad;
        // the cross-pins: the R240 sale rows 27
        // and 28 (the Throne priced ---, the
        // Wand at 10000)
        if (rules::saRowLo(27) != 99 ||
            rules::saRowHi(27) != 99 ||
            rules::saSaleGp(27) != 0 ||
            rules::saSaleGpHi(27) != 0 ||
            rules::saRowLo(28) != 100 ||
            rules::saRowHi(28) != 100 ||
            rules::saSaleGp(28) != 10000 ||
            rules::saSaleGpHi(28) != 0) ++bad;
        printf("R295 special artifacts prose part 16 pins audit: bad %d\n", bad);
    }
    #include "r297_weapon_proficiency_table.h"  // R828: migrated
    #include "r298_thief_function_take_tabl.h"  // R828: migrated
    #include "r299a_party_kit_recordings_se.h"  // R828: migrated
    #include "r299_party_kit_recordings_eng.h"  // R828: migrated
    #include "r300a_equipment_cost_columns_.h"  // R828: migrated
    #include "r300_equipment_costs_engine.h"  // R828: migrated
    #include "r301a_thief_percentile_seam.h"  // R828: migrated
    #include "r301_thief_trap_rolls_engine.h"  // R828: migrated
    #include "r302a_thief_silence_seam.h"  // R828: migrated
    #include "r302_thief_silence_engine.h"  // R828: migrated
    #include "r303a_thief_pockets_seam.h"  // R828: migrated
    #include "r303_thief_pockets_engine.h"  // R828: migrated
    #include "r304a_thief_locks_seam.h"  // R828: migrated
    #include "r304_thief_locks_engine.h"  // R828: migrated
    #include "r305a_door_force_seam.h"  // R828: migrated
    #include "r305_door_force_engine.h"  // R828: migrated
    #include "r306a_thief_functions_seam.h"  // R828: migrated
    #include "r306_thief_functions_engine.h"  // R828: migrated
    #include "r308_general_equipment_lists.h"  // R828: migrated
    #include "r309_hirelings_cost_tables.h"  // R828: migrated
    #include "r310_sage_subsection.h"  // R828: migrated
    #include "r311_underwater_environment.h"  // R828: migrated
    #include "r312a_flooded_crossing_seam.h"  // R828: migrated
    #include "r312_flooded_crossing_engine.h"  // R828: migrated
    #include "r313a_underwater_fight_seam.h"  // R828: migrated
    #include "r313_underwater_fight_engine.h"  // R828: migrated
    #include "r314a_crossbow_and_aquatic_se.h"  // R828: migrated
    #include "r314_crossbow_and_aquatic_eng.h"  // R828: migrated
    #include "r315_net_throwers_engine.h"  // R828: migrated
    #include "r316_underwater_vision_seam.h"  // R828: migrated
    #include "r317_infravision_fold.h"  // R828: migrated
    #include "r318_net_entrap_layer.h"  // R828: migrated
    #include "r319_underwater_vision_multip.h"  // R828: migrated
    #include "r320_breathing_aids.h"  // R828: migrated
    #include "r321_aerial_chapter.h"  // R828: migrated
    #include "r322_comeliness_pins.h"  // R828: migrated
    #include "r323_subrace_layer_seam.h"  // R828: migrated
    #include "r324_subrace_level_limits.h"  // R828: migrated
    #include "r325_subrace_level_cap.h"  // R828: migrated
    #include "r326_subrace_creation.h"  // R828: migrated
    #include "r327_class_tables_pin.h"  // R828: migrated
    #include "r328_cavalier_pin.h"  // R828: migrated
    #include "r329_paladin_reparent_pin.h"  // R828: migrated
    #include "r330_druid_hierophant_pin.h"  // R828: migrated
    #include "r331_weapon_spec_prose_pin.h"  // R828: migrated
    #include "r332_barbarian_pin.h"  // R828: migrated
    #include "r333_ranger_expansion_pin.h"  // R828: migrated
    #include "r334_thief_armor_and_attacks_.h"  // R828: migrated
    #include "r335_thief_acrobat_pin.h"  // R828: migrated
    #include "r336_cavalier_money_pin.h"  // R828: migrated
    #include "r337_ua_weight_and_damage_pin.h"  // R828: migrated
    #include "r338_ua_missile_data_pin.h"  // R828: migrated
    #include "r339_ua_proficiency_pin.h"  // R828: migrated
    #include "r340_ua_new_weapons_prose_pin.h"  // R828: migrated
    #include "r341_ua_spell_tables_pin.h"  // R828: migrated
    #include "r342_ua_mu_and_il_tables_pin.h"  // R828: migrated
    #include "r343_ua_cleric_1st_level_spel.h"  // R828: migrated
    #include "r344_ua_cleric_2nd_level_spel.h"  // R828: migrated
    #include "r345_ua_cleric_3rd_level_spel.h"  // R828: migrated
    #include "r346_ua_cleric_4th_level_spel.h"  // R828: migrated
    #include "r347_ua_cleric_5th_level_spel.h"  // R828: migrated
    #include "r348_ua_cleric_6th_level_spel.h"  // R828: migrated
    #include "r349_ua_cleric_7th_level_spel.h"  // R828: migrated
    #include "r350_ua_druid_1st_level_spell.h"  // R828: migrated
    #include "r351_ua_druid_2nd_level_spell.h"  // R828: migrated
    #include "r352_ua_druid_3rd_level_spell.h"  // R828: migrated
    #include "r353_ua_druid_5th_level_spell.h"  // R828: migrated
    #include "r354_ua_druid_6th_level_spell.h"  // R828: migrated
    #include "r355_ua_druid_7th_level_spell.h"  // R828: migrated
    #include "r356_ua_mu_1st_level_spells_p.h"  // R828: migrated
    #include "r357_ua_mu_2nd_level_spells_p.h"  // R829: migrated
    #include "r358_ua_mu_3rd_level_spells_p.h"  // R829: migrated
    #include "r359_ua_mu_4th_level_spells_p.h"  // R829: migrated
    #include "r360_ua_mu_5th_6th_level_spel.h"  // R829: migrated
    #include "r361_ua_mu_7th_level_spells_p.h"  // R829: migrated
    #include "r362_ua_mu_8th_9th_level_spel.h"  // R829: migrated
    #include "r363_ua_il_cantrips_1st_2nd_p.h"  // R829: migrated
    #include "r364_ua_il_3rd_4th_5th_spells.h"  // R829: migrated
    #include "r365_ua_il_6th_7th_and_dm_pin.h"  // R829: migrated
    #include "r366_ua_dm_section_spells_pin.h"  // R829: migrated
    #include "r367_ua_social_birth_pin.h"  // R829: migrated
    #include "r368_ua_cavaliers_table_i_pin.h"  // R829: migrated
    #include "r369_ua_cantrip_acquisition_p.h"  // R829: migrated
    #include "r370_ua_dm_section_smalls_pin.h"  // R829: migrated
    #include "r371_ua_expanded_armor_pin.h"  // R829: migrated
    #include "r372_ua_cavalier_followers_pi.h"  // R829: migrated
    #include "r373_ua_comeliness_note_pin.h"  // R829: migrated
    #include "r374_ua_treasure_dial_pin.h"  // R829: migrated
    #include "r375_ua_determination_skeleto.h"  // R829: migrated
    #include "r376_ua_new_potions_prose_par.h"  // R829: migrated
    #include "r377_ua_new_scrolls_protectio.h"  // R829: migrated
    #include "r378_ua_new_rings_prose_pin.h"  // R829: migrated
    #include "r379_ua_new_rods_staves_prose.h"  // R829: migrated
    #include "r380_ua_new_wands_prose_pin.h"  // R829: migrated
    #include "r381_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r382_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r383_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r384_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r385_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r386_ua_misc_magic_prose_part.h"  // R829: migrated
    #include "r387_ua_armor_and_swords_pros.h"  // R829: migrated
    #include "r388_ua_misc_weapons_prose_pi.h"  // R829: migrated
    #include "r389_ua_weaponless_combat_pin.h"  // R829: migrated
    #include "r390_ua_non_lethal_combat_pin.h"  // R829: migrated
    #include "r391_ua_pole_arm_nomenclature.h"  // R829: migrated
    #include "r392_ua_players_tables_pin.h"  // R829: migrated
    #include "r393_pdf_read_completion_pin.h"  // R829: migrated
    #include "r394_ua_dm_tables_manifest_pi.h"  // R829: migrated
    #include "r395_ua_treasure_row_bodies_p.h"  // R829: migrated
    #include "r396_ua_potions_prose_complet.h"  // R829: migrated
    #include "r397_ua_treasure_smalls_pin.h"  // R829: migrated
    #include "r398_ua_misc_magic_holes_pin.h"  // R829: migrated
    #include "r399_ua_armor_weapons_holes_p.h"  // R829: migrated
    #include "r400_ua_comeliness_site.h"  // R829: migrated
    #include "r401_ua_cantrip_tier_seam.h"  // R829: migrated
    #include "r402_ua_treasure_dial_seam.h"  // R829: migrated
    #include "r403_mount_layer_seam.h"  // R829: migrated
    #include "r404_psionics_seam.h"  // R829: migrated
    #include "r405_deity_layer_seam.h"  // R829: migrated
    #include "r406_ua_appendix_s_stat_block.h"  // R829: migrated
    #include "r407_ua_appendix_s_clerical_c.h"  // R829: migrated
    #include "r408_ua_armor_class_table_pin.h"  // R829: migrated
    #include "r409_ua_appendix_s_stat_lines.h"  // R829: migrated
    #include "r410_ua_appendix_s_class_line.h"  // R829: migrated
    #include "r411_ua_appendix_s_move_value.h"  // R829: migrated
    #include "r412_ua_useful_cantrips_pin.h"  // R829: migrated
    #include "r413_ua_reversed_cantrips_pin.h"  // R829: migrated
    #include "r414_ua_legerdemain_cantrips_.h"  // R829: migrated
    #include "r415_ua_person_affecting_cant.h"  // R829: migrated
    #include "r416_ua_personal_cantrips_pin.h"  // R829: migrated
    #include "r417_ua_haunting_sound_cantri.h"  // R829: migrated
    #include "r418_ua_cantrip_cast_times_pa.h"  // R829: migrated
    #include "r419_ua_cantrip_cast_times_pa.h"  // R829: migrated
    #include "r421_ua_il_cantrip_cast_times.h"  // R829: migrated
    #include "r422_ua_appendix_r_resolution.h"  // R829: migrated
    #include "r423_ua_appendix_s_pantheon_p.h"  // R829: migrated
    #include "r424_ua_appendix_t_resolution.h"  // R829: migrated
    #include "r425_wsg_proficiencies_pin.h"  // R829: migrated
    #include "r426_wsg_dressing_pin.h"  // R829: migrated
    #include "r427_wsg_environment_pin.h"  // R829: migrated
    #include "r429_wsg_special_weather_pin.h"  // R829: migrated
    #include "r430_wsg_heat_and_cold_pin.h"  // R829: migrated
    #include "r431_wsg_equipment_pin.h"  // R829: migrated
    #include "r432_wsg_encumbrance_pin.h"  // R829: migrated
    #include "r433_wsg_animals_pin.h"  // R829: migrated
    #include "r434_wsg_vehicles_pin.h"  // R829: migrated
    #include "r435_wsg_climbing_pin.h"  // R829: migrated
    #include "r436_wsg_climbing_checks_pin.h"  // R829: migrated
    #include "r437_wsg_falling_damage_pin.h"  // R829: migrated
    #include "r438_wsg_tumbling_damage_pin.h"  // R829: migrated
    #include "r439_wsg_stopping_a_fall_pin.h"  // R829: migrated
    #include "r440_wsg_rope_use_pin.h"  // R829: migrated
    #include "r441_wsg_roping_together_pin.h"  // R829: migrated
    #include "r442_wsg_rappelling_pin.h"  // R829: migrated
    #include "r443_wsg_belaying_pin.h"  // R829: migrated
    #include "r444_wsg_grappling_hooks_pin.h"  // R829: migrated
    #include "r445_wsg_chasm_crossing_pin.h"  // R829: migrated
    #include "r446_wsg_mountaineering_pin.h"  // R829: migrated
    #include "r447_wsg_slippery_surface_mov.h"  // R829: migrated
    #include "r448_wsg_jumping_pin.h"  // R829: migrated
    #include "r449_wsg_reduced_visibility_p.h"  // R829: migrated
    #include "r450_wsg_swimming_pin.h"  // R829: migrated
    #include "r451_wsg_moving_water_pin.h"  // R829: migrated
    #include "r452_wsg_diving_and_surfacing.h"  // R829: migrated
    #include "r453_wsg_treading_water_pin.h"  // R829: migrated
    #include "r454_wsg_holding_breath_pin.h"  // R829: migrated
    #include "r455_wsg_waterborne_vehicles_.h"  // R829: migrated
    #include "r456_wsg_capsizing_pin.h"  // R829: migrated
    #include "r457_wsg_boating_pin.h"  // R829: migrated
    #include "r458_wsg_portaging_pin.h"  // R829: migrated
    #include "r459_wsg_capsized_use_pin.h"  // R830: migrated
    #include "r460_wsg_flying_mounts_pin.h"  // R830: migrated
    #include "r461_wsg_airborne_fall_chance.h"  // R830: migrated
    #include "r462_wsg_food_and_water_pin.h"  // R830: migrated
    #include "r463_wsg_foraging_pin.h"  // R830: migrated
    #include "r464_wsg_hunting_pin.h"  // R830: migrated
    #include "r465_wsg_fishing_pin.h"  // R830: migrated
    #include "r466_wsg_food_carrying_pin.h"  // R830: migrated
    #include "r467_wsg_finding_water_pin.h"  // R830: migrated
    #include "r468_wsg_where_water_pin.h"  // R830: migrated
    #include "r469_wsg_water_in_the_desert_.h"  // R830: migrated
    #include "r470_wsg_purifying_water_pin.h"  // R830: migrated
    #include "r471_wsg_natural_shelters_pin.h"  // R830: migrated
    #include "r472_wsg_portable_shelters_pi.h"  // R830: migrated
    #include "r473_wsg_sleep_and_shelter_pi.h"  // R830: migrated
    #include "r474_wsg_rest_quality_and_fir.h"  // R830: migrated
    #include "r475_wsg_fuel_and_fire_safety.h"  // R830: migrated
    #include "r476_wsg_uncontrollable_fires.h"  // R830: migrated
    #include "r477_wsg_damage_from_fire_pin.h"  // R830: migrated
    #include "r478_wsg_medicinal_plants_pin.h"  // R830: migrated
    #include "r479_wsg_plant_lore_pin.h"  // R830: migrated
    #include "r480_wsg_injuries_treatment_p.h"  // R830: migrated
    #include "r481_wsg_first_aid_equipment_.h"  // R830: migrated
    #include "r482_wsg_normal_vision_pin.h"  // R830: migrated
    #include "r483_wsg_infravision_pin.h"  // R830: migrated
    #include "r484_wsg_ultravision_pin.h"  // R830: migrated
    #include "r485_wsg_artificial_illuminat.h"  // R830: migrated
    #include "r486_wsg_natural_hazards_pin.h"  // R830: migrated
    #include "r487_wsg_hazards_closer_pin.h"  // R830: migrated
    #include "r488_wsg_wilderness_combat_op.h"  // R830: migrated
    #include "r489_wsg_fatigue_chapter_pin.h"  // R830: migrated
    #include "r490_wsg_mounts_and_beasts_pi.h"  // R830: migrated
    #include "r491_wsg_magic_in_the_wildern.h"  // R830: migrated
    #include "r492_wsg_dm_section_pin.h"  // R830: migrated
