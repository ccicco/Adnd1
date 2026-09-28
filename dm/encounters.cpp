// ============================================================================
// Adnd1 — dm/encounters.cpp — see encounters.h
//
// R52: the DMG Appendix C dungeon tables (Premium reprint p.174-179,
// OCR-verified against the uploaded DMG): Determination Matrix, Monster
// Level Tables I-X (verbatim dice ranges and numbers), per-level Dragon
// Subtables with age categories, Human Subtable. Character Subtable
// parties and the D3-module daemons re-roll (DMG's own advice).
//
// Footnoted substitutions per the printed tables: Badger (L I, below
// 2nd dungeon level) -> Hobgoblin; Halfling (L I, below 4th) -> Giant
// Rat; Giant Badger (L II, below 3rd) -> Gnoll. "Titan, minor" maps to
// the lesser-titan AC-2 record; "Lizard, subterranean" -> fire lizard.
// ============================================================================

#include "encounters.h"

#include <algorithm>

namespace dm {
namespace {

enum RowKind {
    ROW_MONSTER, ROW_HUMAN, ROW_CHARACTER, ROW_DRAGON, ROW_HYDRA,
    ROW_ELEMENTAL, ROW_PRINCE, ROW_NONE
};

struct Row {
    int lo, hi;             // percentile range
    int kind;
    const char* key;
    int a, b;               // count range (monster) or head range (hydra)
    int nmin, nmax;        // hydra number appearing
};

struct DragonRow {
    int lo, hi;
    const char* key;
    int ageLo, ageHi;      // age bracket 1-8 range
};

// ---- Monster Level 1 ----
static const Row kLevel1[] = {
    { 1, 2, ROW_MONSTER, "giant_ant", 1, 4, 0, 0 },
    { 3, 4, ROW_MONSTER, "hobgoblin", 2, 8, 0, 0 },
    { 5, 14, ROW_MONSTER, "fire_beetle", 1, 4, 0, 0 },
    { 15, 15, ROW_MONSTER, "manes", 1, 4, 0, 0 },
    { 16, 17, ROW_MONSTER, "dwarf", 4, 14, 0, 0 },
    { 18, 18, ROW_MONSTER, "ear_seeker", 1, 1, 0, 0 },
    { 19, 19, ROW_MONSTER, "elf", 3, 11, 0, 0 },
    { 20, 21, ROW_MONSTER, "gnome", 5, 15, 0, 0 },
    { 22, 26, ROW_MONSTER, "goblin", 6, 15, 0, 0 },
    { 27, 28, ROW_MONSTER, "giant_rat", 5, 20, 0, 0 },
    { 29, 33, ROW_MONSTER, "hobgoblin", 2, 8, 0, 0 },
    { 34, 48, ROW_HUMAN, "", 0, 0, 0, 0 },
    { 49, 54, ROW_MONSTER, "kobold", 6, 18, 0, 0 },
    { 55, 66, ROW_MONSTER, "orc", 7, 12, 0, 0 },
    { 67, 70, ROW_MONSTER, "PIERCER", 1, 3, 0, 0 },
    { 71, 83, ROW_MONSTER, "giant_rat", 5, 20, 0, 0 },
    { 84, 85, ROW_MONSTER, "rot_grub", 1, 3, 0, 0 },
    { 86, 96, ROW_MONSTER, "shrieker", 1, 2, 0, 0 },
    { 97, 98, ROW_MONSTER, "skeleton", 1, 4, 0, 0 },
    { 99, 100, ROW_MONSTER, "zombie", 1, 3, 0, 0 },
};

// ---- Monster Level 2 ----
static const Row kLevel2[] = {
    { 1, 1, ROW_MONSTER, "gnoll", 4, 10, 0, 0 },
    { 2, 16, ROW_MONSTER, "giant_centipede", 3, 13, 0, 0 },
    { 17, 27, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 28, 29, ROW_MONSTER, "lemure", 2, 5, 0, 0 },
    { 30, 31, ROW_MONSTER, "gas_spore", 1, 2, 0, 0 },
    { 32, 38, ROW_MONSTER, "gnoll", 4, 10, 0, 0 },
    { 39, 46, ROW_MONSTER, "PIERCER", 1, 4, 0, 0 },
    { 47, 58, ROW_MONSTER, "giant_rat", 6, 24, 0, 0 },
    { 59, 60, ROW_MONSTER, "rot_grub", 1, 4, 0, 0 },
    { 61, 72, ROW_MONSTER, "shrieker", 1, 3, 0, 0 },
    { 73, 77, ROW_MONSTER, "stirge", 5, 15, 0, 0 },
    { 78, 87, ROW_MONSTER, "giant_toad", 1, 4, 0, 0 },
    { 88, 100, ROW_MONSTER, "troglodyte", 2, 8, 0, 0 },
};

// ---- Monster Level 3 ----
static const Row kLevel3[] = {
    { 1, 10, ROW_MONSTER, "boring_beetle", 1, 3, 0, 0 },
    { 11, 20, ROW_MONSTER, "bugbear", 2, 7, 0, 0 },
    { 21, 30, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 31, 32, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 33, 34, ROW_MONSTER, "violet_fungus", 1, 3, 0, 0 },
    { 35, 40, ROW_MONSTER, "gelatinous_cube", 1, 1, 0, 0 },
    { 41, 45, ROW_MONSTER, "ghoul", 1, 4, 0, 0 },
    { 46, 50, ROW_MONSTER, "giant_lizard", 1, 3, 0, 0 },
    { 51, 54, ROW_MONSTER, "wererat", 2, 5, 0, 0 },
    { 55, 60, ROW_MONSTER, "ochre_jelly", 1, 1, 0, 0 },
    { 61, 72, ROW_MONSTER, "ogre", 1, 3, 0, 0 },
    { 73, 74, ROW_MONSTER, "PIERCER", 2, 5, 0, 0 },
    { 75, 75, ROW_MONSTER, "rot_grub", 1, 4, 0, 0 },
    { 76, 77, ROW_MONSTER, "shrieker", 2, 5, 0, 0 },
    { 78, 84, ROW_MONSTER, "huge_spider", 1, 3, 0, 0 },
    { 85, 93, ROW_MONSTER, "large_spider", 2, 5, 0, 0 },
    { 94, 95, ROW_MONSTER, "giant_tick", 1, 3, 0, 0 },
    { 96, 100, ROW_MONSTER, "giant_weasel", 1, 4, 0, 0 },
};

// ---- Monster Level 4 ----
static const Row kLevel4[] = {
    { 1, 8, ROW_MONSTER, "carnivorous_ape", 1, 3, 0, 0 },
    { 9, 14, ROW_MONSTER, "blink_dog", 2, 5, 0, 0 },
    { 15, 22, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 23, 24, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 25, 30, ROW_MONSTER, "gargoyle", 1, 2, 0, 0 },
    { 31, 36, ROW_MONSTER, "ghost", 1, 4, 0, 0 },
    { 37, 40, ROW_MONSTER, "gray_ooze", 1, 1, 0, 0 },
    { 41, 44, ROW_MONSTER, "hell_hound", 1, 2, 0, 0 },
    { 45, 47, ROW_HYDRA, "hydra", 5, 6, 1, 1 },
    { 48, 48, ROW_HYDRA, "hydra", 5, 5, 1, 1 },
    { 49, 62, ROW_MONSTER, "werewolf", 1, 2, 0, 0 },
    { 63, 75, ROW_MONSTER, "yellow_mold", 1, 1, 0, 0 },
    { 76, 78, ROW_MONSTER, "owlbear", 1, 2, 0, 0 },
    { 79, 79, ROW_MONSTER, "rust_monster", 1, 1, 0, 0 },
    { 80, 82, ROW_MONSTER, "shadow", 1, 3, 0, 0 },
    { 83, 90, ROW_MONSTER, "constrictor_snake", 1, 1, 0, 0 },
    { 91, 94, ROW_MONSTER, "su_monster", 1, 2, 0, 0 },
    { 95, 96, ROW_MONSTER, "ice_toad", 1, 1, 0, 0 },
    { 97, 100, ROW_MONSTER, "poisonous_toad", 1, 3, 0, 0 },
};

// ---- Monster Level 5 ----
static const Row kLevel5[] = {
    { 1, 8, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 9, 15, ROW_MONSTER, "cockatrice", 1, 2, 0, 0 },
    { 16, 18, ROW_MONSTER, "displacer_beast", 1, 2, 0, 0 },
    { 19, 22, ROW_MONSTER, "doppelganger", 1, 3, 0, 0 },
    { 23, 24, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 25, 26, ROW_HYDRA, "hydra", 7, 7, 1, 1 },
    { 27, 27, ROW_HYDRA, "hydra", 6, 6, 1, 1 },
    { 28, 28, ROW_MONSTER, "imp", 1, 2, 0, 0 },
    { 29, 31, ROW_MONSTER, "leucrotta", 1, 2, 0, 0 },
    { 32, 50, ROW_MONSTER, "fire_lizard", 1, 3, 0, 0 },
    { 51, 52, ROW_MONSTER, "wereboar", 1, 3, 0, 0 },
    { 53, 60, ROW_MONSTER, "minotaur", 1, 3, 0, 0 },
    { 61, 64, ROW_MONSTER, "yellow_mold", 1, 1, 0, 0 },
    { 65, 65, ROW_MONSTER, "quasit", 1, 1, 0, 0 },
    { 66, 67, ROW_MONSTER, "rust_monster", 1, 1, 0, 0 },
    { 68, 70, ROW_MONSTER, "shrieker", 2, 5, 0, 0 },
    { 71, 72, ROW_MONSTER, "slithering_tracker", 1, 1, 0, 0 },
    { 73, 74, ROW_MONSTER, "amphisbaena_snake", 1, 1, 0, 0 },
    { 75, 82, ROW_MONSTER, "poisonous_snake", 1, 1, 0, 0 },
    { 83, 86, ROW_MONSTER, "spitting_snake", 1, 1, 0, 0 },
    { 87, 100, ROW_MONSTER, "giant_spider", 1, 2, 0, 0 },
};

// ---- Monster Level 6 ----
static const Row kLevel6[] = {
    { 1, 3, ROW_MONSTER, "basilisk", 1, 1, 0, 0 },
    { 4, 10, ROW_MONSTER, "carrion_crawler", 1, 2, 0, 0 },
    { 11, 16, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 17, 17, ROW_MONSTER, "erinyes", 1, 2, 0, 0 },
    { 18, 19, ROW_MONSTER, "djinni", 1, 1, 0, 0 },
    { 20, 21, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 22, 25, ROW_MONSTER, "green_slime", 1, 1, 0, 0 },
    { 26, 28, ROW_HYDRA, "hydra", 8, 9, 1, 1 },
    { 29, 32, ROW_MONSTER, "jackalwere", 1, 2, 0, 0 },
    { 33, 36, ROW_MONSTER, "lammasu", 1, 3, 0, 0 },
    { 37, 38, ROW_MONSTER, "werebear", 1, 1, 0, 0 },
    { 39, 41, ROW_MONSTER, "weretiger", 1, 2, 0, 0 },
    { 42, 50, ROW_MONSTER, "manticore", 1, 2, 0, 0 },
    { 51, 55, ROW_MONSTER, "medusa", 1, 1, 0, 0 },
    { 56, 56, ROW_MONSTER, "brown_mold", 1, 1, 0, 0 },
    { 57, 58, ROW_MONSTER, "yellow_mold", 1, 1, 0, 0 },
    { 59, 60, ROW_MONSTER, "ogre_magi", 1, 2, 0, 0 },
    { 61, 68, ROW_MONSTER, "otyugh", 1, 1, 0, 0 },
    { 69, 70, ROW_MONSTER, "rakshasa", 1, 1, 0, 0 },
    { 71, 73, ROW_MONSTER, "salamander", 1, 2, 0, 0 },
    { 74, 77, ROW_MONSTER, "phase_spider", 1, 3, 0, 0 },
    { 78, 88, ROW_MONSTER, "troll", 1, 3, 0, 0 },
    { 89, 93, ROW_MONSTER, "wight", 1, 4, 0, 0 },
    { 94, 95, ROW_MONSTER, "wind_walker", 1, 2, 0, 0 },
    { 96, 98, ROW_MONSTER, "wraith", 1, 2, 0, 0 },
    { 99, 100, ROW_MONSTER, "wyvern", 1, 1, 0, 0 },
};

// ---- Monster Level 7 ----
static const Row kLevel7[] = {
    { 1, 5, ROW_MONSTER, "black_pudding", 1, 1, 0, 0 },
    { 6, 10, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 11, 14, ROW_MONSTER, "chimera", 1, 2, 0, 0 },
    { 15, 15, ROW_MONSTER, "succubus", 1, 1, 0, 0 },
    { 16, 16, ROW_MONSTER, "type_i_vrock", 1, 1, 0, 0 },
    { 17, 17, ROW_MONSTER, "type_ii_hezrou", 1, 1, 0, 0 },
    { 18, 18, ROW_MONSTER, "type_iii_glabrezu", 1, 1, 0, 0 },
    { 19, 19, ROW_MONSTER, "barbed_devil", 1, 1, 0, 0 },
    { 20, 20, ROW_MONSTER, "bone_devil", 1, 1, 0, 0 },
    { 21, 21, ROW_MONSTER, "horned_devil", 1, 1, 0, 0 },
    { 22, 23, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 24, 24, ROW_MONSTER, "efreeti", 1, 1, 0, 0 },
    { 25, 26, ROW_ELEMENTAL, "", 0, 0, 0, 0 },
    { 27, 30, ROW_MONSTER, "ettin", 1, 2, 0, 0 },
    { 31, 35, ROW_MONSTER, "HILL_STONE", 1, 3, 0, 0 },
    { 36, 38, ROW_MONSTER, "FIRE_FROST", 1, 2, 0, 0 },
    { 39, 39, ROW_MONSTER, "flesh_golem", 1, 1, 0, 0 },
    { 40, 41, ROW_MONSTER, "gorgon", 1, 1, 0, 0 },
    { 42, 43, ROW_MONSTER, "groaning_spirit", 1, 1, 0, 0 },
    { 44, 46, ROW_HYDRA, "hydra", 10, 12, 1, 1 },
    { 47, 47, ROW_HYDRA, "hydra", 7, 9, 1, 1 },
    { 48, 49, ROW_MONSTER, "intellect_devourer", 1, 1, 0, 0 },
    { 50, 50, ROW_MONSTER, "invisible_stalker", 1, 1, 0, 0 },
    { 51, 52, ROW_MONSTER, "lamia", 1, 2, 0, 0 },
    { 53, 56, ROW_MONSTER, "fire_lizard", 1, 3, 0, 0 },
    { 57, 59, ROW_MONSTER, "lurker_above", 1, 1, 0, 0 },
    { 60, 60, ROW_MONSTER, "REROLL", 0, 0, 0, 0 },
    { 61, 63, ROW_MONSTER, "mimic", 1, 1, 0, 0 },
    { 64, 65, ROW_MONSTER, "mind_flayer", 1, 2, 0, 0 },
    { 66, 69, ROW_MONSTER, "mummy", 1, 2, 0, 0 },
    { 70, 70, ROW_MONSTER, "spirit_naga", 1, 2, 0, 0 },
    { 71, 73, ROW_MONSTER, "neo_otyugh", 1, 1, 0, 0 },
    { 74, 74, ROW_MONSTER, "night_hag", 1, 2, 0, 0 },
    { 75, 78, ROW_MONSTER, "roper", 1, 2, 0, 0 },
    { 79, 82, ROW_MONSTER, "shambling_mound", 1, 2, 0, 0 },
    { 83, 86, ROW_MONSTER, "shedu", 1, 2, 0, 0 },
    { 87, 87, ROW_MONSTER, "giant_slug", 1, 1, 0, 0 },
    { 88, 91, ROW_MONSTER, "spectre", 1, 1, 0, 0 },
    { 92, 93, ROW_MONSTER, "trapper", 1, 1, 0, 0 },
    { 94, 95, ROW_MONSTER, "umber_hulk", 1, 1, 0, 0 },
    { 96, 97, ROW_MONSTER, "will_o_wisp", 1, 3, 0, 0 },
    { 98, 100, ROW_MONSTER, "xorn", 1, 3, 0, 0 },
};

// ---- Monster Level 8 ----
static const Row kLevel8[] = {
    { 1, 1, ROW_MONSTER, "aerial_servant", 1, 1, 0, 0 },
    { 2, 6, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 7, 7, ROW_MONSTER, "type_iv_demon_nalfeshnee", 1, 1, 0, 0 },
    { 8, 8, ROW_MONSTER, "type_v_demon_marilith", 1, 1, 0, 0 },
    { 9, 9, ROW_MONSTER, "type_vi_demon_balor", 1, 1, 0, 0 },
    { 10, 10, ROW_MONSTER, "ice_devil", 1, 1, 0, 0 },
    { 11, 12, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 13, 17, ROW_MONSTER, "ghost", 1, 1, 0, 0 },
    { 18, 21, ROW_MONSTER, "cloud_giant", 1, 2, 0, 0 },
    { 22, 23, ROW_MONSTER, "clay_golem", 1, 1, 0, 0 },
    { 24, 26, ROW_HYDRA, "hydra", 13, 16, 1, 1 },
    { 27, 27, ROW_HYDRA, "hydra", 12, 12, 1, 1 },
    { 28, 29, ROW_MONSTER, "intellect_devourer", 1, 2, 0, 0 },
    { 30, 35, ROW_MONSTER, "lurker_above", 1, 1, 0, 0 },
    { 36, 41, ROW_MONSTER, "brown_mold", 1, 1, 0, 0 },
    { 42, 43, ROW_MONSTER, "yellow_mold", 1, 1, 0, 0 },
    { 44, 47, ROW_MONSTER, "mind_flayer", 1, 4, 0, 0 },
    { 48, 50, ROW_MONSTER, "guardian_naga", 1, 2, 0, 0 },
    { 51, 56, ROW_MONSTER, "neo_otyugh", 1, 1, 0, 0 },
    { 57, 64, ROW_MONSTER, "purple_worm", 1, 1, 0, 0 },
    { 65, 69, ROW_MONSTER, "rust_monster", 1, 1, 0, 0 },
    { 70, 73, ROW_MONSTER, "giant_slug", 1, 1, 0, 0 },
    { 74, 78, ROW_MONSTER, "trapper", 1, 1, 0, 0 },
    { 79, 86, ROW_MONSTER, "vampire", 1, 1, 0, 0 },
    { 87, 92, ROW_MONSTER, "will_o_wisp", 2, 5, 0, 0 },
    { 93, 100, ROW_MONSTER, "xorn", 2, 5, 0, 0 },
};

// ---- Monster Level 9 ----
static const Row kLevel9[] = {
    { 1, 9, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 10, 12, ROW_MONSTER, "pit_fiend", 1, 1, 0, 0 },
    { 13, 15, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 16, 21, ROW_MONSTER, "storm_giant", 1, 2, 0, 0 },
    { 22, 23, ROW_MONSTER, "stone_golem", 1, 1, 0, 0 },
    { 24, 30, ROW_HYDRA, "hydra", 17, 20, 1, 1 },
    { 31, 33, ROW_HYDRA, "hydra", 12, 12, 1, 1 },
    { 34, 40, ROW_MONSTER, "brown_mold", 1, 1, 0, 0 },
    { 41, 50, ROW_MONSTER, "yellow_mold", 1, 1, 0, 0 },
    { 51, 52, ROW_MONSTER, "REROLL", 0, 0, 0, 0 },
    { 53, 64, ROW_MONSTER, "purple_worm", 1, 1, 0, 0 },
    { 65, 67, ROW_MONSTER, "rust_monster", 1, 1, 0, 0 },
    { 68, 69, ROW_MONSTER, "lesser_titan_ac_1", 1, 1, 0, 0 },
    { 70, 73, ROW_MONSTER, "lesser_titan_ac_2", 1, 1, 0, 0 },
    { 74, 80, ROW_MONSTER, "umber_hulk", 1, 4, 0, 0 },
    { 81, 83, ROW_MONSTER, "vampire", 1, 1, 0, 0 },
    { 84, 93, ROW_MONSTER, "will_o_wisp", 2, 5, 0, 0 },
    { 94, 100, ROW_MONSTER, "xorn", 2, 9, 0, 0 },
};

// ---- Monster Level 10 ----
static const Row kLevel10[] = {
    { 1, 12, ROW_MONSTER, "beholder", 1, 1, 0, 0 },
    { 13, 20, ROW_CHARACTER, "", 0, 0, 0, 0 },
    { 21, 28, ROW_PRINCE, "", 0, 0, 0, 0 },
    { 29, 30, ROW_PRINCE, "", 0, 0, 0, 0 },
    { 31, 40, ROW_DRAGON, "", 0, 0, 0, 0 },
    { 41, 50, ROW_MONSTER, "iron_golem", 1, 1, 0, 0 },
    { 51, 60, ROW_MONSTER, "lich", 1, 1, 0, 0 },
    { 61, 70, ROW_MONSTER, "elder_titan_ac_2", 1, 1, 0, 0 },
    { 71, 80, ROW_MONSTER, "vampire", 1, 1, 0, 0 },
    { 81, 100, ROW_NONE, "", 0, 0, 0, 0 },
};

// ---- Dragon Subtable (monster level 3) ----
static const DragonRow kDrag3[] = {
    { 1, 28, "black_dragon", 1, 1 },
    { 29, 62, "brass_dragon", 1, 1 },
    { 63, 100, "white_dragon", 1, 1 },
};

// ---- Dragon Subtable (monster level 4) ----
static const DragonRow kDrag4[] = {
    { 1, 9, "black_dragon", 2, 3 },
    { 10, 20, "blue_dragon", 1, 2 },
    { 21, 30, "brass_dragon", 2, 3 },
    { 31, 37, "bronze_dragon", 1, 2 },
    { 38, 50, "copper_dragon", 1, 2 },
    { 51, 54, "gold_dragon", 1, 2 },
    { 55, 70, "green_dragon", 1, 2 },
    { 71, 80, "red_dragon", 1, 2 },
    { 81, 88, "silver_dragon", 1, 2 },
    { 89, 100, "white_dragon", 2, 3 },
};

// ---- Dragon Subtable (monster level 5) ----
static const DragonRow kDrag5[] = {
    { 1, 8, "black_dragon", 4, 5 },
    { 9, 20, "blue_dragon", 3, 4 },
    { 21, 30, "brass_dragon", 4, 5 },
    { 31, 37, "bronze_dragon", 3, 4 },
    { 38, 50, "copper_dragon", 3, 4 },
    { 51, 54, "gold_dragon", 3, 4 },
    { 55, 70, "green_dragon", 3, 4 },
    { 71, 80, "red_dragon", 3, 4 },
    { 81, 88, "silver_dragon", 3, 4 },
    { 89, 100, "white_dragon", 4, 5 },
};

// ---- Dragon Subtable (monster level 6) ----
static const DragonRow kDrag6[] = {
    { 1, 8, "black_dragon", 6, 6 },
    { 9, 19, "blue_dragon", 5, 5 },
    { 20, 29, "brass_dragon", 6, 6 },
    { 30, 36, "bronze_dragon", 5, 5 },
    { 37, 48, "copper_dragon", 5, 5 },
    { 49, 52, "gold_dragon", 5, 5 },
    { 53, 65, "green_dragon", 5, 5 },
    { 66, 78, "red_dragon", 5, 5 },
    { 79, 87, "silver_dragon", 5, 5 },
    { 88, 100, "white_dragon", 6, 6 },
};

// ---- Dragon Subtable (monster level 7) ----
static const DragonRow kDrag7[] = {
    { 1, 10, "black_dragon", 7, 7 },
    { 11, 21, "blue_dragon", 6, 6 },
    { 22, 29, "brass_dragon", 7, 7 },
    { 30, 36, "bronze_dragon", 6, 6 },
    { 37, 48, "copper_dragon", 6, 6 },
    { 49, 52, "gold_dragon", 6, 6 },
    { 53, 66, "green_dragon", 6, 6 },
    { 67, 80, "red_dragon", 6, 6 },
    { 81, 87, "silver_dragon", 6, 6 },
    { 88, 100, "white_dragon", 7, 7 },
};

// ---- Dragon Subtable (monster level 8) ----
static const DragonRow kDrag8[] = {
    { 1, 13, "black_dragon", 8, 8 },
    { 14, 24, "blue_dragon", 7, 7 },
    { 25, 31, "brass_dragon", 8, 8 },
    { 32, 35, "bronze_dragon", 7, 7 },
    { 36, 43, "copper_dragon", 7, 7 },
    { 44, 47, "gold_dragon", 7, 7 },
    { 48, 62, "green_dragon", 7, 7 },
    { 63, 78, "red_dragon", 7, 7 },
    { 79, 82, "silver_dragon", 7, 7 },
    { 83, 100, "white_dragon", 8, 8 },
};

// ---- Dragon Subtable (monster level 9) ----
static const DragonRow kDrag9[] = {
    { 1, 10, "black_dragon", 6, 8 },
    { 11, 22, "blue_dragon", 8, 8 },
    { 23, 31, "brass_dragon", 6, 8 },
    { 32, 34, "bronze_dragon", 8, 8 },
    { 35, 42, "copper_dragon", 8, 8 },
    { 43, 46, "gold_dragon", 8, 8 },
    { 47, 62, "green_dragon", 8, 8 },
    { 63, 78, "red_dragon", 8, 8 },
    { 79, 82, "silver_dragon", 8, 8 },
    { 83, 100, "white_dragon", 7, 8 },
};

// ---- Dragon Subtable (monster level 10) ----
static const DragonRow kDrag10[] = {
    { 1, 20, "blue_dragon", 7, 8 },
    { 21, 26, "bronze_dragon", 7, 8 },
    { 27, 33, "copper_dragon", 7, 8 },
    { 34, 35, "chromatic_dragon", 8, 8 },
    { 36, 40, "gold_dragon", 6, 8 },
    { 41, 60, "green_dragon", 7, 8 },
    { 61, 63, "platinum_dragon", 8, 8 },
    { 64, 94, "red_dragon", 6, 8 },
    { 95, 100, "silver_dragon", 6, 8 },
};

// ---- Determination Matrix: dungeon level 1..16+ -> d20 -> level I-X ----
struct MatrixBand { int lo, hi, mlv; };
static const MatrixBand kMatrix[12][10] = {
    {{1,16,1}, {17,19,2}, {20,20,3}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
    {{1,12,1}, {13,16,2}, {17,18,3}, {19,19,4}, {20,20,5}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
    {{1,5,1}, {6,10,2}, {11,16,3}, {17,18,4}, {19,19,5}, {20,20,6}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
    {{1,3,1}, {4,6,2}, {7,12,3}, {13,16,4}, {17,18,5}, {19,19,6}, {20,20,7}, {0,0,1}, {0,0,1}, {0,0,1}},
    {{1,2,1}, {3,4,2}, {5,6,3}, {7,12,4}, {13,16,5}, {17,18,6}, {19,19,7}, {20,20,8}, {0,0,1}, {0,0,1}},
    {{1,1,1}, {2,3,2}, {4,5,3}, {6,10,4}, {11,14,5}, {15,16,6}, {17,18,7}, {19,19,8}, {20,20,9}, {0,0,1}},
    {{1,1,1}, {2,2,2}, {3,4,3}, {5,7,4}, {8,10,5}, {11,14,6}, {15,16,7}, {17,18,8}, {19,19,9}, {20,20,10}},
    {{1,1,1}, {2,2,2}, {3,3,3}, {4,5,4}, {6,8,5}, {9,12,6}, {13,15,7}, {16,17,8}, {18,19,9}, {20,20,10}},
    {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,6,5}, {7,9,6}, {10,12,7}, {13,16,8}, {17,19,9}, {20,20,10}},
    {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5}, {6,7,6}, {8,9,7}, {10,12,8}, {13,18,9}, {19,20,10}},
    {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5}, {6,6,6}, {7,8,7}, {9,11,8}, {12,17,9}, {18,20,10}},
    {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5}, {6,6,6}, {7,7,7}, {8,10,8}, {11,16,9}, {17,20,10}},
};

static const char* kPrinces[] = { "demogorgon", "juiblex", "orcus", "yeenoghu" };
static const char* kArchDevils[] = { "asmodeus", "baalzebul", "dispater", "geryon" };
static const char* kElementals[] = {
    "air_elemental", "earth_elemental", "fire_elemental", "water_elemental" };
static const char* kHillStone[] = { "hill_giant", "stone_giant" };
static const char* kFireFrost[] = { "fire_giant", "frost_giant" };
static const char* kPiercers[] = {
    "piercer_smallest", "piercer_small", "piercer_medium", "piercer_largest" };

const Row* levelTable(int mlv, size_t& count) {
    switch (mlv) {
        case 1:  count = sizeof kLevel1 / sizeof kLevel1[0]; return kLevel1;
        case 2:  count = sizeof kLevel2 / sizeof kLevel2[0]; return kLevel2;
        case 3:  count = sizeof kLevel3 / sizeof kLevel3[0]; return kLevel3;
        case 4:  count = sizeof kLevel4 / sizeof kLevel4[0]; return kLevel4;
        case 5:  count = sizeof kLevel5 / sizeof kLevel5[0]; return kLevel5;
        case 6:  count = sizeof kLevel6 / sizeof kLevel6[0]; return kLevel6;
        case 7:  count = sizeof kLevel7 / sizeof kLevel7[0]; return kLevel7;
        case 8:  count = sizeof kLevel8 / sizeof kLevel8[0]; return kLevel8;
        case 9:  count = sizeof kLevel9 / sizeof kLevel9[0]; return kLevel9;
        default: count = sizeof kLevel10 / sizeof kLevel10[0]; return kLevel10;
    }
}

const DragonRow* dragonTable(int mlv, size_t& count) {
    switch (mlv) {
        case 3:  count = sizeof kDrag3 / sizeof kDrag3[0]; return kDrag3;
        case 4:  count = sizeof kDrag4 / sizeof kDrag4[0]; return kDrag4;
        case 5:  count = sizeof kDrag5 / sizeof kDrag5[0]; return kDrag5;
        case 6:  count = sizeof kDrag6 / sizeof kDrag6[0]; return kDrag6;
        case 7:  count = sizeof kDrag7 / sizeof kDrag7[0]; return kDrag7;
        case 8:  count = sizeof kDrag8 / sizeof kDrag8[0]; return kDrag8;
        case 9:  count = sizeof kDrag9 / sizeof kDrag9[0]; return kDrag9;
        default: count = sizeof kDrag10 / sizeof kDrag10[0]; return kDrag10;
    }
}

} // namespace

int monsterLevelFor(int dungeonLevel, int d20) {
    int band = dungeonLevel < 1 ? 0
             : dungeonLevel >= 16 ? 11 : dungeonLevel - 1;
    const MatrixBand* row = kMatrix[band];
    for (int i = 0; i < 10; ++i)
        if (row[i].lo > 0 && d20 >= row[i].lo && d20 <= row[i].hi)
            return i + 1;
    return 1;
}

DungeonEncounter rollDungeonEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int d20, int pctile, int pctile2, int dungeonLevel) {
    DungeonEncounter e;

    for (int attempt = 0; attempt < 24; ++attempt) {
        int mlv = monsterLevelFor(dungeonLevel, d20);
        size_t count = 0;
        const Row* t = levelTable(mlv, count);
        const Row* row = nullptr;
        for (size_t i = 0; i < count; ++i)
            if (pctile >= t[i].lo && pctile <= t[i].hi) { row = &t[i]; break; }
        if (!row) return e;

        switch ((RowKind)row->kind) {
        case ROW_MONSTER: {
            std::string key = row->key;
            if (key == "REROLL") break;
            if (key == "HILL_STONE")  key = kHillStone[pctile2 % 2];
            if (key == "FIRE_FROST") key = kFireFrost[pctile2 % 2];
            if (key == "PIERCER")
                key = kPiercers[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = (row->a == row->b)
                ? row->a
                : row->a + (int)dice.roll(1,
                        (uint32_t)(row->b - row->a + 1), 0) - 1;
            return e;
        }
        case ROW_HYDRA: {
            if (!reg.find(row->key)) break;
            e.key = row->key;
            e.headsLo = row->a;
            e.headsHi = row->b;
            e.count = row->nmin;
            return e;
        }
        case ROW_DRAGON: {
            size_t dc = 0;
            const DragonRow* dt = dragonTable(mlv, dc);
            const DragonRow* dr = nullptr;
            for (size_t i = 0; i < dc; ++i)
                if (pctile2 >= dt[i].lo && pctile2 <= dt[i].hi)
                    { dr = &dt[i]; break; }
            if (!dr) return e;
            if (!reg.find(dr->key)) break;
            e.key = dr->key;
            e.ageLo = dr->ageLo;
            e.ageHi = dr->ageHi;
            e.count = (mlv >= 9)
                ? (int)dice.roll(1, 2, 0)   // DMG: 1-2 at ML IX/X
                : 1;
            return e;
        }
        case ROW_ELEMENTAL: {
            const char* key = kElementals[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = 1;
            return e;
        }
        case ROW_PRINCE: {
            const char* const* pool =
                (row->hi <= 28) ? kPrinces : kArchDevils;
            const char* key = pool[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = 1;
            return e;
        }
        case ROW_HUMAN: {
            // Human Subtable: 01-25 Bandit, 26-30 Berserker,
            // 31-45 Brigand (chaotic evil bandits), 46-00 Character
            if (pctile2 <= 25)      e.key = "bandit";
            else if (pctile2 <= 30) e.key = "berserker";
            else if (pctile2 <= 45) e.key = "bandit";
            else {
                // R53: Character Subtable party (DMG p.176)
                e.party = rollCharacterParty(dice, dungeonLevel, mlv);
                e.isParty = true;
                e.key = "character_party";
                e.count = e.party.size();
                return e;
            }
            if (!reg.find(e.key)) break;
            e.count = (e.key == "berserker")
                ? 2 + (int)dice.roll(1, 7, 0)      // 3-9
                : 4 + (int)dice.roll(1, 11, 0);    // 5-15
            return e;
        }
        case ROW_CHARACTER: {
            // R53: the Character Subtable resolves here —
            // a classed NPC party (DMG p.176)
            e.party = rollCharacterParty(dice, dungeonLevel, mlv);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }
        case ROW_NONE:
        default:
            return e;    // NO ENCOUNTER (Monster Level X 81-00)
        }

        // DMG advice: ignore & re-roll
        d20     = 1 + (int)dice.roll(1, 20, 0);
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

namespace {
void pushUnique(std::vector<std::string>& v, const char* key) {
    std::string k(key);
    for (const auto& s : v) if (s == k) return;
    v.push_back(k);
}
} // namespace

std::vector<std::string> encounterKeys(
        const monsters::MonsterRegistry& reg, int dungeonLevel) {
    std::vector<std::string> out;
    int band = dungeonLevel < 1 ? 0
             : dungeonLevel >= 16 ? 11 : dungeonLevel - 1;
    const MatrixBand* row = kMatrix[band];
    for (int i = 0; i < 10; ++i) {
        if (row[i].lo <= 0) continue;
        int mlv = i + 1;
        size_t count = 0;
        const Row* t = levelTable(mlv, count);
        for (size_t r = 0; r < count; ++r) {
            const Row* rw = &t[r];
            if (rw->kind == ROW_MONSTER) {
                std::string key = rw->key;
                if (key == "REROLL") continue;
                if (key == "HILL_STONE") {
                    pushUnique(out, kHillStone[0]);
                    pushUnique(out, kHillStone[1]);
                    continue;
                }
                if (key == "FIRE_FROST") {
                    pushUnique(out, kFireFrost[0]);
                    pushUnique(out, kFireFrost[1]);
                    continue;
                }
                if (key == "PIERCER") {
                    for (int p = 0; p < 4; ++p)
                        pushUnique(out, kPiercers[p]);
                    continue;
                }
                if (reg.find(key)) pushUnique(out, key.c_str());
            } else if (rw->kind == ROW_HYDRA) {
                if (reg.find(rw->key)) pushUnique(out, rw->key);
            } else if (rw->kind == ROW_DRAGON) {
                size_t dc = 0;
                const DragonRow* dt = dragonTable(mlv, dc);
                for (size_t d = 0; d < dc; ++d)
                    if (reg.find(dt[d].key)) pushUnique(out, dt[d].key);
            } else if (rw->kind == ROW_ELEMENTAL) {
                for (int el = 0; el < 4; ++el)
                    if (reg.find(kElementals[el])) pushUnique(out, kElementals[el]);
            } else if (rw->kind == ROW_PRINCE) {
                for (int p = 0; p < 4; ++p)
                    if (reg.find(kPrinces[p])) pushUnique(out, kPrinces[p]);
                for (int p = 0; p < 4; ++p)
                    if (reg.find(kArchDevils[p])) pushUnique(out, kArchDevils[p]);
            } else if (rw->kind == ROW_HUMAN) {
                if (reg.find("bandit")) pushUnique(out, "bandit");
                if (reg.find("berserker")) pushUnique(out, "berserker");
            }
        }
    }
    return out;
}

// ----------------------------------------------------------------------------
// R53: the Character Subtable (DMG p.176), verbatim ranges and
// per-profession maxima. The engine's four classes absorb the
// rest per the book's closest-approximation advice.
// ----------------------------------------------------------------------------
namespace {

struct ProfRow { int lo, hi, max; };   // subtable percentile + max/party

enum ProfId {
    PROF_CLERIC, PROF_DRUID, PROF_FIGHTER, PROF_PALADIN, PROF_RANGER,
    PROF_MU, PROF_ILLUSIONIST, PROF_THIEF, PROF_ASSASSIN, PROF_MONK_BARD,
    PROF_COUNT
};

// 01-17 Cleric / 18-20 Druid / 21-60 Fighter / 61-62 Paladin /
// 63-65 Ranger / 66-86 Magic-user / 87-88 Illusionist /
// 89-98 Thief / 99 Assassin / 00 Monk or Bard
const ProfRow kProfTable[PROF_COUNT] = {
    {  1, 17, 3},   // cleric
    { 18, 20, 2},   // druid
    { 21, 60, 5},   // fighter
    { 61, 62, 2},   // paladin
    { 63, 65, 2},   // ranger
    { 66, 86, 3},   // magic-user
    { 87, 88, 1},   // illusionist
    { 89, 98, 4},   // thief
    { 99, 99, 2},   // assassin
    {100,100, 1},   // monk or bard
};

int profFor(int pctile) {
    for (int i = 0; i < PROF_COUNT; ++i)
        if (pctile >= kProfTable[i].lo && pctile <= kProfTable[i].hi)
            return i;
    return PROF_FIGHTER;
}

// engine class per profession (closest approximation, DMG advice)
int classForProf(int prof) {
    switch (prof) {
        case PROF_CLERIC:
        case PROF_DRUID:        return rules::CLASS_CLERIC;
        case PROF_MU:
        case PROF_ILLUSIONIST:  return rules::CLASS_MAGIC_USER;
        case PROF_THIEF:
        case PROF_ASSASSIN:     return rules::CLASS_THIEF;
        case PROF_MONK_BARD:    return rules::CLASS_THIEF;   // bard
        default:                return rules::CLASS_FIGHTER; // fighter/
    }                           // paladin/ranger/monk
}

// DMG p.176: character level = dungeon or monster level, whichever
// is greater, through the 4th; thereafter d6+6 adjusted toward the
// dungeon level (not to exceed 12 unless the dungeon is 16th+).
int characterLevelFor(rules::Dice& dice, int dungeonLevel,
                      int monsterLevel) {
    int base = dungeonLevel > monsterLevel ? dungeonLevel : monsterLevel;
    if (base < 1) base = 1;
    if (base <= 4) return base;
    int lvl = 6 + (int)dice.roll(1, 6, 0);       // 7-12
    if (lvl > dungeonLevel)      --lvl;
    else if (lvl < dungeonLevel) ++lvl;
    if (lvl > 12 && dungeonLevel < 16) lvl = 12;
    return lvl;
}

// DMG p.176: henchman level = master/3 (fractions below one-half
// round down, else up), plus one level per three master levels
// when the master is above 8th (bonus in whole levels).
int henchmanLevelFor(int masterLevel) {
    int base = (2 * masterLevel + 3) / 6;   // round-to-nearest thirds
    int bonus = masterLevel > 8 ? masterLevel / 3 : 0;
    int lvl = base + bonus;
    return lvl < 1 ? 1 : lvl;
}

} // namespace

// ----------------------------------------------------------------------------
// R55: DMG p.176-177 party magic items — the level-chance
// ladder and Tables I-IV. Only implementable outcomes carry a
// mechanical effect (weapon/armor/shield/missile pluses); the
// rest of each table (potions, scrolls, rings, staves, wands,
// miscellany) is represented in the fiction but rolls as NONE.
// Table II/III are headed "(d8, d6)": implemented as d8 within a
// half, d6 1-3/4-6 picking the half (a uniform 1-16 reading of
// the two-dice notation).
// ----------------------------------------------------------------------------
namespace {

enum ItemKind { ITEM_NONE, ITEM_WPN, ITEM_RNG, ITEM_ARM, ITEM_SHD,
                ITEM_ARM_SET };   // armor+shield sold as one set

struct ItemRow {
    int kind;   // ItemKind
    int a, b;   // pluses (b = shield plus for ARM_SET rows)
};

// Table I (d20)
const ItemRow kTableI[20] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 10-12
    {ITEM_ARM,1,0},    // 13: leather +1
    {ITEM_SHD,1,0},    // 14: shield +1
    {ITEM_WPN,1,0},    // 15: sword +1
    {ITEM_RNG,1,0},    // 16: 10 arrows +1
    {ITEM_RNG,2,0},    // 17: 4 bolts +2
    {ITEM_WPN,1,0},    // 18: dagger +1 or +2 (+1 taken)
    {ITEM_WPN,2,0},    // 19: javelin +2
    {ITEM_WPN,1,0},    // 20: mace +1
};

// Table II (d8 + d6-half, 16 rows)
const ItemRow kTableII[16] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 10-12
    {ITEM_ARM_SET,1,2},  // 13: chainmail +1, shield +2
    {ITEM_ARM,4,0},      // 14: splint mail +4
    {ITEM_WPN,3,0},      // 15: sword +3
    {ITEM_WPN,2,0},      // 16: crossbow of speed / hammer +2
};

// Table III (d8 + d6-half, 16 rows)
const ItemRow kTableIII[16] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0},                    // 10-11
    {ITEM_ARM_SET,3,2},  // 12: plate +3, shield +2
    {ITEM_SHD,5,0},      // 13: shield +5
    {ITEM_WPN,4,0},      // 14: sword +4, defender
    {ITEM_WPN,3,0},      // 15: mace +3
    {ITEM_WPN,3,0},      // 16: spear +3
};

// Table IV (d12)
const ItemRow kTableIV[12] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_ARM_SET,4,3},  // 10: plate +4, shield +3
    {ITEM_WPN,1,0},      // 11: sword of wounding (+1 to-hit)
    {ITEM_NONE,0,0},     // 12: arrow of slaying
};

const ItemRow& rollTable(rules::Dice& dice, const ItemRow* t, int n,
                        bool halfDice) {
    int row;
    if (halfDice)   // "(d8, d6)": d6 1-3 -> first half, 4-6 second
        row = (int)dice.roll(1, 8, 0) +
              ((int)dice.roll(1, 6, 0) > 3 ? n / 2 : 0) - 1;
    else
        row = (int)dice.roll(1, (uint32_t)n, 0) - 1;
    if (row < 0) row = 0;
    if (row >= n) row = n - 1;
    return t[row];
}

void applyItem(const ItemRow& r, PartyMember& m) {
    switch (r.kind) {
        case ITEM_WPN: if (r.a > m.wpnPlus) m.wpnPlus = r.a; break;
        case ITEM_RNG: if (r.a > m.rngPlus) m.rngPlus = r.a; break;
        case ITEM_ARM: if (r.a > m.armPlus) m.armPlus = r.a; break;
        case ITEM_SHD: if (r.a > m.shdPlus) m.shdPlus = r.a; break;
        case ITEM_ARM_SET:
            if (r.a > m.armPlus) m.armPlus = r.a;
            if (r.b > m.shdPlus) m.shdPlus = r.b;
            break;
        default: break;   // unmodeled device (fiction only)
    }
}

// DMG p.176 level-chance ladder: {level, pctI, nI, pctII, nII,
// pctIII, nIII, pctIV, nIV}. pct -1 = automatic (the printed
// "3 items" rows). Level 13+ uses the 13th row.
const int kLadder[13][9] = {
    { 1,  10, 1,   0, 0,   0, 0,   0, 0},
    { 2,  20, 2,   0, 0,   0, 0,   0, 0},
    { 3,  30, 2,  10, 1,   0, 0,   0, 0},
    { 4,  40, 2,  20, 1,   0, 0,   0, 0},
    { 5,  50, 2,  30, 1,   0, 0,   0, 0},
    { 6,  60, 3,  40, 2,   0, 0,   0, 0},
    { 7,  70, 3,  50, 2,  10, 1,   0, 0},
    { 8,  80, 3,  60, 2,  20, 1,   0, 0},
    { 9,  90, 3,  70, 2,  30, 1,   0, 0},
    {10,  -1, 3,  80, 2,  40, 1,   0, 0},
    {11,  -1, 3,  90, 2,  50, 1,  10, 1},
    {12,  -1, 3,  -1, 2,  60, 1,  20, 1},
    {13,  -1, 3,  -1, 2,  -1, 1,  60, 1},
};

void rollMagicItemsFor(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // men-at-arms: hp is all they need
    int li = m.level - 1;
    if (li > 12) li = 12;
    const int* row = kLadder[li];
    for (int t = 0; t < row[2]; ++t)                     // Table I
        if (row[1] < 0 || (int)dice.roll(1, 100, 0) <= row[1])
            applyItem(rollTable(dice, kTableI, 20, false), m);
    for (int t = 0; t < row[4]; ++t)                     // Table II
        if (row[3] < 0 || (int)dice.roll(1, 100, 0) <= row[3])
            applyItem(rollTable(dice, kTableII, 16, true), m);
    for (int t = 0; t < row[6]; ++t)                     // Table III
        if (row[5] < 0 || (int)dice.roll(1, 100, 0) <= row[5])
            applyItem(rollTable(dice, kTableIII, 16, true), m);
    for (int t = 0; t < row[8]; ++t)                     // Table IV
        if (row[7] < 0 || (int)dice.roll(1, 100, 0) <= row[7])
            applyItem(rollTable(dice, kTableIV, 12, false), m);
}

} // namespace

CharacterParty rollCharacterParty(rules::Dice& dice,
                                  int dungeonLevel, int monsterLevel) {
    CharacterParty p;

    // 2-5 characters (d4+1)
    int nChars = 1 + (int)dice.roll(1, 4, 0);

    int perProf[PROF_COUNT] = {0};
    bool hasPaladin = false, hasAssassin = false;

    for (int i = 0; i < nChars; ++i) {
        int prof = PROF_FIGHTER;
        // re-roll contradictions (paladin with assassin) and
        // per-profession maxima (DMG: ignore such rolls)
        for (int attempt = 0; attempt < 24; ++attempt) {
            int pct = (int)dice.roll(1, 100, 0);
            int cand = profFor(pct);
            if (perProf[cand] >= kProfTable[cand].max) continue;
            if ((cand == PROF_ASSASSIN && hasPaladin) ||
                (cand == PROF_PALADIN && hasAssassin)) continue;
            prof = cand;
            break;
        }
        ++perProf[prof];
        if (prof == PROF_PALADIN) hasPaladin = true;
        if (prof == PROF_ASSASSIN) hasAssassin = true;

        PartyMember m;
        m.classIndex = classForProf(prof);
        m.level = characterLevelFor(dice, dungeonLevel, monsterLevel);
        rollMagicItemsFor(dice, m);   // R55: DMG p.176-177
        p.members.push_back(m);
    }

    // followers round the party out to nine: men-at-arms on
    // dungeon levels 1-3, classed henchmen on 4+
    int followers = 9 - nChars;
    bool menAtArms = dungeonLevel <= 3;
    for (int i = 0; i < followers; ++i) {
        PartyMember m;
        if (menAtArms) {
            // 0-level men: hp is all they need (DMG p.176)
            m.manAtArms = true;
            m.classIndex = rules::CLASS_FIGHTER;   // kit + saves
            m.level = 0;
        } else {
            // henchmen: profession by subtable (paladins and
            // party-contradictory assassins re-rolled), level
            // one-third of the master's (rotating assignment)
            int prof = PROF_FIGHTER;
            for (int attempt = 0; attempt < 24; ++attempt) {
                int pct = (int)dice.roll(1, 100, 0);
                int cand = profFor(pct);
                if (cand == PROF_PALADIN) continue;
                if (cand == PROF_ASSASSIN &&
                    (hasAssassin || hasPaladin)) continue;
                if (perProf[cand] >= kProfTable[cand].max) continue;
                prof = cand;
                break;
            }
            m.henchman = true;
            m.classIndex = classForProf(prof);
            m.level = henchmanLevelFor(
                p.members[(size_t)(i % nChars)].level);
            rollMagicItemsFor(dice, m);   // R55: henchmen too
        }
        p.members.push_back(m);
    }
    return p;
}

// R58: DMG p.63 Encounter Reactions — percentile adjusted for
// the spokesman's Charisma, compared to the printed bands. The
// p.63 "loyalty adjustment as if the creature were a henchman" is
// not modeled (documented simplification — the strangers owe
// the party no tracked loyalty). The p.176 Confrontation shift:
// a party that feels weak avoids, negotiates or bluffs (+10).
PartyReaction rollPartyReaction(rules::Dice& dice, int chaAdj,
                                bool npcWeaker) {
    int score = (int)dice.roll(1, 100, 0) + chaAdj;
    if (npcWeaker) score += 10;   // p.176 Confrontation
    if (score <= 5)  return PartyReaction::ViolentlyHostile;
    if (score <= 25) return PartyReaction::Hostile;
    if (score <= 45) return PartyReaction::UncertainNegative;
    if (score <= 55) return PartyReaction::Neutral;
    if (score <= 75) return PartyReaction::UncertainPositive;
    if (score <= 95) return PartyReaction::Friendly;
    return PartyReaction::Enthusiastic;
}

// ----------------------------------------------------------------------------
// R60: the underwater tables (DMG Appendix C, Premium reprint
// p.179-181, OCR-verified): Fresh Water shallow (to 50') / deep
// (below 50'), Salt Water (large bodies) shallow (to 100') /
// deep (below 100'), and the Dinosaur Subtable. The DMG prints
// no number columns — "The numbers of monsters encountered are
// those shown in MONSTER MANUAL" — so count comes from the
// registry's noAppearing fields (0/0 falls back to 1).
//
// Footnotes are modeled as re-rolls per the book's own
// "otherwise roll again":
//   *   cool waters only
//   **  warm (sub-tropical and tropical) waters only
// The Dinosaur Subtable adds: * deep water only (dinichthys);
// the fresh-water ** gate rides on the parent Dinosaur rows
// (Elasmosaurus / Mosasaurus / Plesiosaurus "must be in a
// relatively warm clime" in fresh water).
//
// Key substitutions (no dedicated Lua record, per the R52
// footnoted-substitution convention): Koalinth -> hobgoblin,
// Kopoacinth -> gargoyle, Lacedon -> ghoul, Elf (aquatic) ->
// elf, "Mottled (purple) worm" -> purple_worm, "Whale,
// carnivorous" (large/medium/small) -> killer_whale (the MM's
// carnivorous whale), plain "Whale" (large/medium/small) ->
// whale. All other rows map 1:1 to registry keys (verified
// against the 408-lua tree).
// ----------------------------------------------------------------------------
namespace {

enum WaterFlagBits { WF_NONE = 0, WF_COOL_ONLY = 1, WF_WARM_ONLY = 2,
                     WF_DEEP_ONLY = 4 };

struct WaterRow { int lo, hi; const char* key; int flags; };

// ---- Fresh Water, Shallow Water Encounters (to 50') — DMG p.180 ----
static const WaterRow kFreshShallow[] = {
    {  1,  6, "giant_beaver",    WF_COOL_ONLY},
    {  7, 10, "giant_crayfish",  WF_NONE},
    { 11, 18, "crocodile",       WF_WARM_ONLY},
    { 19, 20, "giant_crocodile", WF_WARM_ONLY},
    { 21, 23, "DINOSAUR",        WF_WARM_ONLY},
    { 24, 26, "electric",        WF_WARM_ONLY},
    { 27, 32, "giant_frog",      WF_NONE},
    { 33, 34, "killer_frog",     WF_NONE},
    { 35, 35, "poisonous_frog",  WF_NONE},
    { 36, 40, "giant_gar",       WF_NONE},
    { 41, 42, "green_slime",     WF_COOL_ONLY},
    { 43, 47, "hippocampus",     WF_NONE},
    { 48, 52, "hippopotamus",    WF_WARM_ONLY},
    { 53, 56, "hobgoblin",       WF_NONE},   // Koalinth
    { 57, 58, "gargoyle",        WF_NONE},   // Kopoacinth
    { 59, 60, "ghoul",           WF_NONE},   // Lacedon
    { 61, 65, "lamprey",         WF_COOL_ONLY},
    { 66, 71, "giant_leech",     WF_NONE},
    { 72, 76, "lizard_man",      WF_NONE},
    { 77, 77, "water_naga",      WF_NONE},
    { 78, 81, "nixie",           WF_COOL_ONLY},
    { 82, 82, "nymph",           WF_NONE},
    { 83, 87, "giant_otter",     WF_NONE},
    { 88, 90, "giant_pike",      WF_NONE},
    { 91, 94, "water_spider",    WF_NONE},
    { 95, 99, "snapping_turtle", WF_NONE},
    {100,100, "water_weird",     WF_NONE},
};

// ---- Fresh Water, Deep Water Encounters (below 50') — DMG p.180 ----
static const WaterRow kFreshDeep[] = {
    {  1,  1, "giant_beaver",    WF_COOL_ONLY},
    {  2,  6, "water_beetle",    WF_NONE},
    {  7,  9, "giant_crayfish",  WF_NONE},
    { 10, 14, "giant_crocodile", WF_WARM_ONLY},
    { 15, 20, "DINOSAUR",       WF_WARM_ONLY},
    { 21, 21, "dragon_turtle",   WF_NONE},
    { 22, 25, "electric",        WF_WARM_ONLY},
    { 26, 32, "giant_gar",       WF_NONE},
    { 33, 34, "storm_giant",     WF_NONE},
    { 35, 36, "hippocampus",     WF_NONE},
    { 37, 38, "hobgoblin",       WF_NONE},   // Koalinth
    { 39, 43, "gargoyle",        WF_NONE},   // Kopoacinth
    { 44, 47, "ghoul",           WF_NONE},   // Lacedon
    { 48, 55, "giant_lamprey",   WF_COOL_ONLY},
    { 56, 60, "lizard_man",      WF_NONE},
    { 61, 63, "purple_worm",     WF_NONE},   // Mottled worm
    { 64, 64, "water_naga",      WF_NONE},
    { 65, 70, "nixie",           WF_NONE},
    { 71, 76, "giant_otter",     WF_NONE},
    { 77, 86, "giant_pike",      WF_NONE},
    { 87, 95, "water_spider",    WF_NONE},
    { 96, 99, "snapping_turtle", WF_NONE},
    {100,100, "water_weird",     WF_NONE},
};

// ---- Salt Water, Shallow Water Encounters (to 100') — DMG p.181 ----
static const WaterRow kSaltShallow[] = {
    {  1,  2, "barracuda",            WF_NONE},
    {  3,  5, "giant_crab",            WF_NONE},
    {  6,  6, "giant_crayfish",        WF_NONE},
    {  7,  8, "DINOSAUR",             WF_NONE},
    {  9, 12, "dolphin",               WF_NONE},
    { 13, 13, "giant_eel",            WF_NONE},
    { 14, 17, "weed",                  WF_NONE},
    { 18, 19, "elf",                   WF_NONE},   // Elf, aquatic
    { 20, 21, "floating_eye",          WF_NONE},
    { 22, 22, "storm_giant",           WF_NONE},
    { 23, 26, "hippocampus",           WF_NONE},
    { 27, 28, "ixitxachitl",           WF_NONE},
    { 29, 34, "hobgoblin",             WF_NONE},   // Koalinth
    { 35, 36, "gargoyle",              WF_NONE},   // Kopoacinth
    { 37, 38, "ghoul",                 WF_NONE},   // Lacedon
    { 39, 41, "locathah",              WF_NONE},
    { 42, 43, "masher",                WF_NONE},
    { 44, 46, "merman",                WF_NONE},
    { 47, 47, "nymph",                 WF_NONE},
    { 48, 49, "ochre_jelly",           WF_NONE},
    { 50, 51, "octopus",               WF_NONE},
    { 52, 54, "portuguese_man_o_war",  WF_NONE},
    { 55, 56, "manta_ray",             WF_NONE},
    { 57, 58, "pungi_ray",             WF_NONE},
    { 59, 60, "sting_ray",             WF_NONE},
    { 61, 65, "sahuagin",              WF_NONE},
    { 66, 66, "sea_hag",               WF_NONE},
    { 67, 72, "sea_horse",             WF_NONE},
    { 73, 78, "sea_lion",              WF_NONE},
    { 79, 81, "shark",                 WF_NONE},
    { 82, 82, "giant_shark",           WF_NONE},
    { 83, 83, "sea_snake",             WF_NONE},
    { 84, 84, "giant_squid",           WF_NONE},
    { 85, 87, "strangle_weed",         WF_NONE},
    { 88, 90, "triton",                WF_NONE},
    { 91, 91, "sea_turtle",            WF_NONE},
    { 92, 92, "killer_whale",          WF_NONE},   // carnivorous large
    { 93, 93, "killer_whale",          WF_NONE},   // carnivorous medium
    { 94, 96, "killer_whale",          WF_NONE},   // carnivorous small
    { 97, 97, "whale",                 WF_NONE},   // whale large
    { 98, 98, "whale",                 WF_NONE},   // whale medium
    { 99,100, "whale",                 WF_NONE},   // whale small
};

// ---- Salt Water, Deep Water Encounters (below 100') — DMG p.181 ----
static const WaterRow kSaltDeep[] = {
    {  1,  3, "giant_crayfish",   WF_NONE},
    {  4,  5, "giant_crocodile",  WF_NONE},
    {  6, 12, "DINOSAUR",        WF_NONE},
    { 13, 20, "dolphin",          WF_NONE},
    { 21, 21, "dragon_turtle",    WF_NONE},
    { 22, 23, "giant_eel",       WF_NONE},
    { 24, 24, "eye_of_the_deep",  WF_NONE},
    { 25, 25, "storm_giant",      WF_NONE},
    { 26, 30, "hippocampus",      WF_NONE},
    { 31, 33, "ixitxachitl",      WF_NONE},
    { 34, 35, "hobgoblin",        WF_NONE},   // Koalinth
    { 36, 38, "gargoyle",         WF_NONE},   // Kopoacinth
    { 39, 40, "ghoul",            WF_NONE},   // Lacedon
    { 41, 42, "giant_lamprey",    WF_NONE},
    { 43, 44, "locathah",         WF_NONE},
    { 45, 45, "masher",           WF_NONE},
    { 46, 50, "merman",           WF_NONE},
    { 51, 52, "morkoth",          WF_NONE},
    { 53, 54, "octopus",          WF_NONE},
    { 55, 57, "manta_ray",        WF_NONE},
    { 58, 61, "sahuagin",         WF_NONE},
    { 62, 63, "sea_hag",          WF_NONE},
    { 64, 68, "sea_horse",        WF_NONE},
    { 69, 73, "sea_lion",         WF_NONE},
    { 74, 78, "giant_shark",      WF_NONE},
    { 79, 80, "sea_snake",        WF_NONE},
    { 81, 82, "giant_squid",      WF_NONE},
    { 83, 85, "triton",           WF_NONE},
    { 86, 86, "sea_turtle",       WF_NONE},
    { 87, 88, "killer_whale",     WF_NONE},   // carnivorous large
    { 89, 90, "killer_whale",     WF_NONE},   // carnivorous medium
    { 91, 92, "killer_whale",     WF_NONE},   // carnivorous small
    { 93, 95, "whale",            WF_NONE},   // whale large
    { 96, 98, "whale",            WF_NONE},   // whale medium
    { 99,100, "whale",            WF_NONE},   // whale small
};

// ---- Dinosaur Subtable — DMG p.190 ----
static const WaterRow kDinoSub[] = {
    {  1, 15, "archelon_ischyros", WF_NONE},
    { 16, 35, "dinichthys",        WF_DEEP_ONLY},
    { 36, 55, "elasmosaurus",      WF_NONE},
    { 56, 75, "mosasaurus",        WF_NONE},
    { 76,100, "plesiosaurus",      WF_NONE},
};

const WaterRow* waterTable(WaterBody body, WaterDepth depth,
                           size_t& count) {
    const WaterRow* t;
    if (body == WaterBody::FRESH) {
        if (depth == WaterDepth::SHALLOW) {
            t = kFreshShallow; count = sizeof kFreshShallow / sizeof kFreshShallow[0];
        } else {
            t = kFreshDeep;    count = sizeof kFreshDeep    / sizeof kFreshDeep[0];
        }
    } else {
        if (depth == WaterDepth::SHALLOW) {
            t = kSaltShallow;  count = sizeof kSaltShallow  / sizeof kSaltShallow[0];
        } else {
            t = kSaltDeep;     count = sizeof kSaltDeep     / sizeof kSaltDeep[0];
        }
    }
    return t;
}

} // namespace

DungeonEncounter rollWaterEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    size_t n = 0;
    const WaterRow* t = waterTable(body, depth, n);

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (pctile >= t[i].lo && pctile <= t[i].hi) { row = &t[i]; break; }
        if (!row) return e;

        // footnote clime gates (DMG: "otherwise roll again")
        bool ok = true;
        if ((row->flags & WF_COOL_ONLY) && clime == WaterClime::WARM)
            ok = false;
        if ((row->flags & WF_WARM_ONLY) && clime == WaterClime::COOL)
            ok = false;

        std::string key = row->key;
        if (ok && key == "DINOSAUR") {
            const WaterRow* dr = nullptr;
            for (size_t i = 0;
                 i < sizeof kDinoSub / sizeof kDinoSub[0]; ++i)
                if (pctile2 >= kDinoSub[i].lo && pctile2 <= kDinoSub[i].hi)
                    { dr = &kDinoSub[i]; break; }
            if (!dr) return e;    // subtable covers 01-00; defensive
            // Dinosaur Subtable *: deep water only (dinichthys)
            if ((dr->flags & WF_DEEP_ONLY) && depth == WaterDepth::SHALLOW)
                ok = false;
            else
                key = dr->key;
        }

        if (ok) {
            const monsters::MonsterDef* def = reg.find(key);
            if (def) {
                e.key = key;
                // numbers per MONSTER MANUAL (registry noAppearing;
                // 0/0 falls back to a single specimen)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(1,
                                (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
                return e;
            }
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> waterEncounterKeys(
        const monsters::MonsterRegistry& reg,
        WaterBody body, WaterDepth depth) {
    std::vector<std::string> out;
    size_t n = 0;
    const WaterRow* t = waterTable(body, depth, n);
    for (size_t i = 0; i < n; ++i) {
        std::string key = t[i].key;
        if (key == "DINOSAUR") {
            for (size_t d = 0;
                 d < sizeof kDinoSub / sizeof kDinoSub[0]; ++d)
                if (reg.find(kDinoSub[d].key))
                    pushUnique(out, kDinoSub[d].key);
        } else if (reg.find(key)) {
            pushUnique(out, key.c_str());
        }
    }
    return out;
}

} // namespace dm
