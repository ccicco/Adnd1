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

// R62: 1e class/race allowances for the fiction layer
bool raceAllowsClass(int race, int classIndex) {
    switch (race) {
        case RACE_DWARF:
        case RACE_HALFLING:
            return classIndex == rules::CLASS_FIGHTER ||
                   classIndex == rules::CLASS_THIEF;
        case RACE_ELF:
        case RACE_GNOME:
            return classIndex != rules::CLASS_CLERIC;
        case RACE_HALF_ORC:
            return classIndex != rules::CLASS_MAGIC_USER;
        default:
            return true;   // human, half-elf: any class
    }
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
        m.race = rollNpcRace(dice, m.classIndex);   // R62
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
            m.race = RACE_HUMAN;   // R62: 0-level men
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
            // R62: a henchman follows his master's folk when
            // his profession allows it (design fiction)
            {
                int masterRace =
                    p.members[(size_t)(i % nChars)].race;
                m.race = raceAllowsClass(masterRace, m.classIndex)
                       ? masterRace
                       : rollNpcRace(dice, m.classIndex);
            }
            m.level = henchmanLevelFor(
                p.members[(size_t)(i % nChars)].level);
            rollMagicItemsFor(dice, m);   // R55: henchmen too
        }
        p.members.push_back(m);
    }
    return p;
}

// R62: the p.192 race-check adjective for fiction strings.
const char* npcRaceAdjective(int race) {
    switch (race) {
        case RACE_DWARF:     return "dwarven ";
        case RACE_ELF:       return "elven ";
        case RACE_GNOME:     return "gnomish ";
        case RACE_HALF_ELF:  return "half-elven ";
        case RACE_HALFLING:  return "halfling ";
        case RACE_HALF_ORC:  return "half-orc ";
        default:             return "";   // human
    }
}

// R62: DMG p.192 race check with class-contradiction re-rolls.
int rollNpcRace(rules::Dice& dice, int classIndex) {
    for (int attempt = 0; attempt < 24; ++attempt) {
        int pct = (int)dice.roll(1, 100, 0);
        int race = RACE_HUMAN;
        if      (pct <= 8)  race = RACE_DWARF;
        else if (pct <= 13) race = RACE_ELF;
        else if (pct <= 15) race = RACE_GNOME;
        else if (pct <= 23) race = RACE_HALF_ELF;
        else if (pct <= 25) race = RACE_HALFLING;
        else if (pct <= 30) race = RACE_HALF_ORC;
        if (raceAllowsClass(race, classIndex)) return race;
    }
    return RACE_HUMAN;
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
// elf, "Mottled (purple) worm" -> purple_worm. R61: the
// whale-size rows now map to distinct MM Whale entries —
// carnivorous L/M/S -> sperm_whale/killer_whale/black_whale,
// plain L/M/S -> whale/right_whale/white_whale_beluga
// (R60 approximated them to single keys). All other rows map
// 1:1 to registry keys (verified against the 408-lua tree).
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
    { 92, 92, "sperm_whale",          WF_NONE},   // carnivorous large
    { 93, 93, "killer_whale",          WF_NONE},   // carnivorous medium
    { 94, 96, "black_whale",           WF_NONE},   // carnivorous small
    { 97, 97, "whale",                 WF_NONE},   // whale large
    { 98, 98, "right_whale",           WF_NONE},   // whale medium
    { 99,100, "white_whale_beluga",    WF_NONE},   // whale small
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
    { 87, 88, "sperm_whale",      WF_NONE},   // carnivorous large
    { 89, 90, "killer_whale",     WF_NONE},   // carnivorous medium
    { 91, 92, "black_whale",      WF_NONE},   // carnivorous small
    { 93, 95, "whale",            WF_NONE},   // whale large
    { 96, 98, "right_whale",      WF_NONE},   // whale medium
    { 99,100, "white_whale_beluga", WF_NONE},   // whale small
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

// ----------------------------------------------------------------------------
// R63: the outdoor (wilderness) encounter tables — DMG Appendix C
// (Premium reprint p.182-191, OCR-verified against the uploaded DMG).
// Eight climate tables, each a creature-major table across eight
// terrain columns: Plain, Scrub, Forest, Rough, Desert, Hills,
// Mountains, Marsh. (Rough includes ruins within five miles of the
// party per the book footnote.) Subtables — Demi-Human, Dragon, Frog,
// Giant, Humanoid, Lycanthrope, Men, Snake, Sphinx, Spider, Undead —
// resolve on the second percentile against the same terrain column;
// the tropical table's Sphinx footnote is a single-column subtable
// instead. Pick-sets (Ki-rin/Lammasu/Shedu, Leprechaun/Brownie,
// Porcupine/Skunk, Iguanodon/Lambeosaurus, Lammasu/Shedu,
// Wolf/Wild dog) resolve on the second percentile modulo set size;
// Porcupine/Skunk maps to giant_porcupine/giant_skunk (the
// bestiary carries the giant varieties only).
// The DMG prints no number columns — "the numbers of monsters
// encountered are those shown in MONSTER MANUAL" — so counts
// come from the registry's noAppearing fields, as in R60.
// Substitutions documented in-row: Men, tribesmen -> caveman and
// nomad -> dervish (no separate bestiary entries), brigand -> bandit,
// Camel -> wild_camel, Misc reptiles -> giant_lizard
// (book fn *), "Pterodactyl, small" -> pteranodon, Nothosaurus ->
// megalosaurus (book fn **), Treant -> treant_mature_middle_aged,
// Titan -> titan. The Men Subtable Character row (10% of the
// remainder in all cases) resolves as a character party of levels
// 7-10 per the p.187 wilderness note: rollCharacterParty(dice, 8, 8).
// OCR defects corrected in-row, each documented: Sub-Arctic marsh
// caveman 56-55 -> 56-65; inhabited 2nd "Ghost" -> ghast; tropical
// bandit mountains 23-28 -> 23-30; tropical dervish mountains
// 46-47 / marsh 29-30 printed but dropped (column-shift artifacts);
// Faerie giant boar forest 09-11 -> 09-12; temperate wild giant
// eagle plain 15 -> 15-16 (printed gap at 16); tropical dervish
// hills 46-55 -> 46-47 (desert-column bleed, merchant 48-55
// follows); Dragon subtable chimera forest 24-30 -> 23-30; Giant
// subtable stone giant hills 81-98 -> 82-98; Lycanthrope subtable
// 2nd "Werebear" row -> wereboar; Undead subtable 2nd "Ghost" row
// -> ghast; Men subtable marsh pilgrim 36-30 -> 36-50 and tribesman
// 31-00 -> 51-00.

namespace {

struct OutdoorRow {
    const char* key;   // registry key, SUB_* / *_SET pseudo-key
    short lo[8];       // per-terrain percentile low (-1 = no entry)
    short hi[8];       // per-terrain percentile high (-1 = no entry)
};


// Arctic Conditions (DMG Appendix C)
// 
static const OutdoorRow kOutArctic[] = {
{"brown_bear",
  {1, -1, -1, 1, -1, -1, 1, -1},
  {10, -1, -1, 9, -1, -1, 7, -1}}   // polar: white-coated brown bear (book fn a),
{"white_dragon",
  {11, -1, -1, 10, -1, -1, 8, -1},
  {12, -1, -1, 12, -1, -1, 15, -1}},
{"frost_giant",
  {13, -1, -1, 13, -1, -1, 16, -1},
  {15, -1, -1, 15, -1, -1, 20, -1}},
{"herd_animal",
  {16, -1, -1, 16, -1, -1, 21, -1},
  {55, -1, -1, 55, -1, -1, 55, -1}},
{"caveman",
  {56, -1, -1, 56, -1, -1, 56, -1},
  {65, -1, -1, 60, -1, -1, 60, -1}}   // Men, tribesmen -> caveman,
{"giant_owl",
  {66, -1, -1, 61, -1, -1, 61, -1},
  {70, -1, -1, 70, -1, -1, 70, -1}},
{"remorhaz",
  {71, -1, -1, 71, -1, -1, 71, -1},
  {72, -1, -1, 75, -1, -1, 72, -1}},
{"constrictor_snake",
  {73, -1, -1, 76, -1, -1, 73, -1},
  {74, -1, -1, 80, -1, -1, 75, -1}}   // white-furred constrictor (book fn b),
{"ice_toad",
  {75, -1, -1, 81, -1, -1, 76, -1},
  {80, -1, -1, 83, -1, -1, 80, -1}},
{"wolf",
  {81, -1, -1, 84, -1, -1, 81, -1},
  {90, -1, -1, 91, -1, -1, 86, -1}},
{"winter_wolf",
  {91, -1, -1, 92, -1, -1, 87, -1},
  {95, -1, -1, 95, -1, -1, 90, -1}},
{"yeti",
  {96, -1, -1, 96, -1, -1, 91, -1},
  {100, -1, -1, 100, -1, -1, 100, -1}}
};

// Sub-Arctic Conditions (DMG Appendix C)
// 
static const OutdoorRow kOutSubArctic[] = {
{"brown_bear",
  {-1, 1, 1, 1, -1, 1, -1, -1},
  {-1, 5, 10, 5, -1, 5, -1, -1}},
{"cave_bear",
  {-1, -1, 11, 6, -1, 6, 1, -1},
  {-1, -1, 15, 10, -1, 10, 15, -1}},
{"white_dragon",
  {1, 6, -1, 11, -1, 11, 16, 1},
  {5, 10, -1, 15, -1, 15, 25, 5}},
{"frost_giant",
  {6, 11, 16, 16, -1, 16, 26, -1},
  {10, 15, 20, 20, -1, 20, 30, -1}},
{"gnoll",
  {11, 16, 21, 21, -1, 21, 31, 6},
  {15, 20, 25, 25, -1, 25, 35, 20}},
{"hell_hound",
  {-1, -1, 26, 26, -1, 26, 36, -1},
  {-1, -1, 27, 27, -1, 27, 40, -1}},
{"herd_animal",
  {16, 21, 28, 28, -1, 28, 41, 21},
  {40, 40, 38, 40, -1, 50, 60, 50}},
{"giant_lynx",
  {-1, -1, 39, -1, -1, -1, -1, -1},
  {-1, -1, 45, -1, -1, -1, -1, -1}},
{"mammoth",
  {41, 41, 46, -1, -1, -1, -1, -1},
  {45, 50, 50, -1, -1, -1, -1, -1}},
{"mastodon",
  {46, 51, 51, -1, -1, -1, -1, 51},
  {55, 55, 55, -1, -1, -1, -1, 55}},
{"caveman",
  {56, 56, 56, 41, -1, 51, -1, 56},
  {65, 65, 65, 50, -1, 60, -1, 65}}   // Men, tribesmen (marsh 56-55 OCR defect -> 56-65, documented),
{"giant_owl",
  {66, 66, 66, 51, -1, 61, 61, 66},
  {70, 70, 70, 55, -1, 65, 65, 75}},
{"giant_ram",
  {-1, -1, -1, 56, -1, 66, 66, -1},
  {-1, -1, -1, 60, -1, 70, 70, -1}},
{"giant_rat",
  {-1, -1, 71, 61, -1, -1, -1, 76},
  {-1, -1, 75, 65, -1, -1, -1, 85}},
{"remorhaz",
  {-1, -1, -1, 66, -1, -1, 71, -1},
  {-1, -1, -1, 67, -1, -1, 75, -1}},
{"woolly_rhinoceros",
  {71, 71, -1, -1, -1, 71, -1, -1},
  {80, 80, -1, -1, -1, 75, -1, -1}},
{"tiger",
  {81, 81, 76, 68, -1, 76, -1, -1},
  {90, 90, 80, 75, -1, 80, -1, -1}},
{"ice_toad",
  {-1, -1, -1, -1, -1, -1, -1, 86},
  {-1, -1, -1, -1, -1, -1, -1, 90}},
{"troll",
  {-1, -1, 81, 76, -1, 81, 76, 91},
  {-1, -1, 85, 80, -1, 85, 85, 100}},
{"wolf",
  {91, 91, 86, 81, -1, 86, 86, -1},
  {100, 100, 95, 90, -1, 92, 92, -1}},
{"winter_wolf",
  {-1, -1, -1, -1, -1, 93, 93, -1},
  {-1, -1, -1, -1, -1, 94, 95, -1}},
{"wolverine",
  {-1, -1, 96, 91, -1, 95, -1, -1},
  {-1, -1, 98, 96, -1, 96, -1, -1}},
{"giant_wolverine",
  {-1, -1, 99, 97, -1, 97, -1, -1},
  {-1, -1, 100, 98, -1, 98, -1, -1}},
{"yeti",
  {-1, -1, -1, 99, -1, 99, 96, -1},
  {-1, -1, -1, 100, -1, 100, 100, -1}}
};

// Temperate, Uninhabited / Wilderness (DMG Appendix C)
// 
static const OutdoorRow kOutTemperateWild[] = {
{"giant_ant",
  {1, 1, 1, 1, -1, 1, -1, -1},
  {1, 1, 1, 1, -1, 1, -1, -1}},
{"badger",
  {-1, -1, 2, 2, -1, -1, -1, -1},
  {-1, -1, 2, 3, -1, -1, -1, -1}},
{"giant_badger",
  {-1, -1, -1, 4, -1, -1, -1, -1},
  {-1, -1, -1, 4, -1, -1, -1, -1}},
{"brown_bear",
  {2, 2, 3, 5, -1, 2, 1, -1},
  {2, 2, 4, 5, -1, 3, 2, -1}},
{"giant_beaver",
  {-1, -1, -1, -1, -1, -1, -1, 1},
  {-1, -1, -1, -1, -1, -1, -1, 1}},
{"bombardier_beetle",
  {-1, -1, 5, -1, -1, -1, -1, -1},
  {-1, -1, 5, -1, -1, -1, -1, -1}},
{"stag_beetle",
  {-1, -1, 6, -1, -1, -1, -1, -1},
  {-1, -1, 6, -1, -1, -1, -1, -1}},
{"beholder",
  {-1, -1, -1, -1, -1, -1, -1, 2},
  {-1, -1, -1, -1, -1, -1, -1, 2}},
{"blink_dog",
  {3, 3, 7, 6, 1, 4, 3, -1},
  {3, 3, 7, 6, 1, 4, 3, -1}},
{"wild_boar",
  {4, 4, 8, 7, -1, -1, -1, -1},
  {4, 5, 8, 7, -1, -1, -1, -1}},
{"bugbear",
  {5, 6, 9, 8, -1, 5, 4, -1},
  {5, 6, 9, 8, -1, 8, 5, -1}},
{"wild_cattle",
  {6, 7, 10, -1, -1, 9, -1, -1},
  {9, 8, 10, -1, -1, 9, -1, -1}}   // Bull/Cattle, wild,
{"catoblepas",
  {-1, -1, -1, -1, -1, -1, -1, 3},
  {-1, -1, -1, -1, -1, -1, -1, 5}},
{"SUB_DEMIHUMAN",
  {10, 9, 11, 9, -1, 10, 6, -1},
  {10, 9, 11, 9, -1, 20, 7, -1}},
{"displacer_beast",
  {-1, -1, 12, 10, -1, -1, 8, 6},
  {-1, -1, 12, 10, -1, -1, 8, 6}},
{"wild_dog",
  {11, 10, 13, 11, 2, 21, 9, -1},
  {12, 10, 13, 11, 5, 22, 9, -1}},
{"SUB_DRAGON",
  {13, 11, 14, 12, 6, 23, 10, 7},
  {14, 11, 14, 12, 7, 24, 11, 7}},
{"dragonne",
  {-1, -1, -1, 13, 8, -1, 12, -1},
  {-1, -1, -1, 13, 8, -1, 12, -1}},
{"giant_eagle",
  {15, -1, 15, 14, 9, 25, 13, 8},
  {16, -1, 15, 14, 9, 25, 14, 8}}   // P 15-15 OCR -> 15-16 to cover the printed gap at 16 before Giant 17-18 (documented),
{"SUB_FROG",
  {-1, -1, -1, -1, -1, -1, -1, 9},
  {-1, -1, -1, -1, -1, -1, -1, 15}},
{"gargoyle",
  {-1, -1, -1, -1, -1, -1, 15, 16},
  {-1, -1, -1, -1, -1, -1, 16, 16}},
{"SUB_GIANT",
  {17, 12, 16, 15, -1, 26, 17, -1},
  {18, 13, 16, 16, -1, 27, 28, -1}},
{"giant_goat",
  {-1, -1, -1, 17, -1, 28, 29, -1},
  {-1, -1, -1, 17, -1, 30, 29, -1}},
{"griffon",
  {19, 14, 17, 18, 10, 31, 30, -1},
  {19, 14, 17, 18, 11, 32, 30, -1}},
{"herd_animal",
  {20, 15, 18, 19, 12, 33, -1, -1},
  {25, 20, 20, 20, 12, 35, -1, -1}},
{"hippogriff",
  {26, 21, 21, 21, 13, 36, 31, -1},
  {27, 22, 22, 22, 14, 37, 32, -1}},
{"wild_horse",
  {28, 23, 23, 23, 15, 38, -1, -1},
  {30, 25, 25, 25, 19, 39, -1, -1}},
{"SUB_HUMANOID",
  {31, 26, 26, 26, 20, 40, 33, 17},
  {33, 32, 30, 30, 28, 50, 40, 30}},
{"jackal",
  {34, 33, -1, -1, -1, -1, -1, -1},
  {38, 34, -1, -1, -1, -1, -1, -1}}   // 10% jackalwere (book fn **),
{"KI_RIN_SET",
  {39, 35, 31, 31, 29, 51, 41, 31},
  {39, 35, 31, 31, 30, 51, 41, 31}}   // Ki-rin/Lammasu/Shedu,
{"LEPRECHAUN_SET",
  {-1, -1, 32, -1, -1, 52, -1, -1},
  {-1, -1, 32, -1, -1, 53, -1, -1}}   // Leprechaun/Brownie,
{"leucrotta",
  {-1, -1, -1, 32, -1, -1, 42, 32},
  {-1, -1, -1, 33, -1, -1, 42, 32}},
{"lion",
  {40, 36, 33, 34, 31, 54, -1, -1},
  {49, 40, 35, 35, 40, 55, -1, -1}},
{"giant_lizard",
  {-1, -1, 36, 36, 41, -1, -1, 33},
  {-1, -1, 36, 37, 44, -1, -1, 36}},
{"SUB_LYCANTHROPE",
  {50, -1, 37, 38, -1, 56, 43, -1},
  {50, -1, 38, 39, -1, 58, 45, -1}},
{"giant_lynx",
  {-1, -1, 39, -1, -1, -1, -1, -1},
  {-1, -1, 40, -1, -1, -1, -1, -1}},
{"SUB_MEN",
  {51, 41, 41, 40, 45, 59, 46, 37},
  {70, 60, 50, 50, 69, 70, 60, 52}},
{"ogre",
  {71, 61, 51, 51, -1, 71, 61, -1},
  {74, 65, 55, 55, -1, 75, 65, -1}}   // 10% ogre magi (book fn ***),
{"giant_owl",
  {75, 66, 56, 56, 70, 76, 66, 53},
  {75, 66, 58, 56, 70, 76, 66, 53}},
{"owlbear",
  {-1, -1, 59, -1, -1, -1, -1, 54},
  {-1, -1, 60, -1, -1, -1, -1, 54}},
{"pegasus",
  {76, 67, -1, 57, 71, 77, 67, -1},
  {77, 67, -1, 57, 74, 77, 67, -1}},
{"PORCUPINE_SET",
  {-1, 68, 61, 58, -1, 78, -1, -1},
  {-1, 69, 63, 58, -1, 78, -1, -1}}   // Porcupine/Skunk -> giant_porcupine/giant_skunk (bestiary has the giant varieties only, documented),
{"pseudo_dragon",
  {-1, 70, 64, -1, -1, -1, -1, -1},
  {-1, 70, 65, -1, -1, -1, -1, -1}},
{"shambling_mound",
  {-1, -1, 66, -1, -1, -1, -1, 55},
  {-1, -1, 66, -1, -1, -1, -1, 58}},
{"SUB_SNAKE",
  {78, 71, 67, 59, 75, 79, 68, 59},
  {78, 71, 68, 60, 79, 79, 68, 72}},
{"SUB_SPHINX",
  {-1, -1, 69, 61, 80, 80, 69, 73},
  {-1, -1, 70, 63, 89, 81, 72, 78}},
{"SUB_SPIDER",
  {79, 72, 71, 64, 90, 82, -1, -1},
  {80, 80, 73, 65, 93, 83, -1, -1}},
{"stag",
  {81, 81, 74, 66, -1, 84, -1, -1},
  {81, 85, 76, 66, -1, 87, -1, -1}},
{"giant_tick",
  {-1, 86, 77, -1, -1, -1, -1, -1},
  {-1, 86, 78, -1, -1, -1, -1, -1}},
{"giant_toad",
  {82, 87, 79, 67, -1, 88, -1, 79},
  {82, 87, 79, 67, -1, 88, -1, 83}},
{"treant_mature_middle_aged",
  {-1, -1, 80, -1, -1, -1, -1, -1},
  {-1, -1, 84, -1, -1, -1, -1, -1}}   // Treant -> mature specimen,
{"troll",
  {83, 88, 85, 68, -1, 89, 73, 84},
  {84, 88, 85, 75, -1, 89, 78, 86}},
{"SUB_UNDEAD",
  {-1, -1, 86, 76, -1, 90, 79, 87},
  {-1, -1, 87, 80, -1, 91, 83, 92}},
{"giant_wasp",
  {85, 89, 88, 81, 94, 92, -1, 93},
  {86, 89, 88, 82, 95, 92, -1, 94}},
{"giant_weasel",
  {87, 90, 89, 83, -1, 93, 84, 95},
  {87, 91, 89, 84, -1, 93, 86, 96}},
{"will_o_wisp",
  {-1, -1, 90, 85, -1, -1, 87, 97},
  {-1, -1, 90, 86, -1, -1, 92, 100}},
{"wind_walker",
  {-1, -1, -1, -1, -1, -1, 93, -1},
  {-1, -1, -1, -1, -1, -1, 94, -1}},
{"wolf",
  {88, 92, 91, 87, 96, 94, 95, -1},
  {97, 97, 97, 97, 100, 98, 96, -1}},
{"worg",
  {98, 98, 98, 98, -1, 99, 97, -1},
  {100, 100, 100, 100, -1, 100, 100, -1}}
};

// Temperate, Inhabited and/or Patrolled (DMG Appendix C)
// 
static const OutdoorRow kOutTemperateInhabited[] = {
{"ankheg",
  {1, 1, 1, -1, -1, 1, -1, -1},
  {2, 1, 2, -1, -1, 1, -1, -1}},
{"giant_ant",
  {3, 2, 3, 1, -1, 2, -1, -1},
  {5, 2, 4, 2, -1, 2, -1, -1}},
{"black_bear",
  {-1, 3, 5, 3, -1, -1, 1, 1},
  {-1, 4, 7, 4, -1, -1, 2, 5}},
{"bombardier_beetle",
  {6, 5, 8, -1, -1, 3, -1, -1},
  {6, 5, 9, -1, -1, 3, -1, -1}},
{"stag_beetle",
  {7, 6, 10, -1, -1, -1, -1, -1},
  {7, 6, 11, -1, -1, -1, -1, -1}},
{"wild_boar",
  {8, 7, 12, 5, -1, 4, -1, 6},
  {10, 8, 14, 6, -1, 5, -1, 8}},
{"bulette",
  {11, 9, -1, -1, -1, 6, -1, -1},
  {11, 9, -1, -1, -1, 6, -1, -1}},
{"dwarf",
  {-1, -1, -1, 7, -1, 7, 3, -1},
  {-1, -1, -1, 8, -1, 8, 15, -1}},
{"elf",
  {12, 10, 15, -1, -1, 9, -1, -1},
  {12, 11, 18, -1, -1, 10, -1, -1}},
{"ghost",
  {-1, -1, -1, 9, -1, -1, -1, -1},
  {-1, -1, -1, 10, -1, -1, -1, -1}},
{"ghast",
  {-1, -1, -1, 11, -1, -1, -1, -1},
  {-1, -1, -1, 11, -1, -1, -1, -1}}   // 2nd 'Ghost' row -> ghast (OCR dup, documented),
{"ghoul",
  {-1, -1, -1, 12, -1, -1, -1, 9},
  {-1, -1, -1, 14, -1, -1, -1, 10}},
{"hill_giant",
  {13, 12, 19, 15, -1, 11, 16, -1},
  {13, 12, 19, 16, -1, 15, 17, -1}},
{"gnoll",
  {14, 13, 20, 17, 1, 16, 18, 11},
  {15, 13, 20, 18, 3, 17, 19, 13}},
{"gnome",
  {16, -1, 21, 19, -1, 18, 20, -1},
  {16, -1, 22, 20, -1, 21, 21, -1}},
{"goblin",
  {17, -1, 23, 21, -1, 22, 22, -1},
  {18, -1, 23, 22, -1, 23, 24, -1}},
{"groaning_spirit",
  {19, 14, -1, -1, -1, 24, -1, 14},
  {19, 14, -1, -1, -1, 24, -1, 14}},
{"halfling",
  {20, 15, 24, -1, -1, 25, -1, -1},
  {21, 15, 24, -1, -1, 27, -1, -1}},
{"hobgoblin",
  {22, 16, 25, 23, -1, 28, 25, 15},
  {22, 17, 25, 23, -1, 28, 26, 15}},
{"leprechaun",
  {23, -1, -1, -1, -1, 29, -1, -1},
  {23, -1, -1, -1, -1, 30, -1, -1}},
{"werebear",
  {-1, -1, 26, -1, -1, -1, 27, -1},
  {-1, -1, 26, -1, -1, -1, 27, -1}},
{"wereboar",
  {-1, 18, 27, -1, -1, -1, -1, -1},
  {-1, 19, 27, -1, -1, -1, -1, -1}},
{"wererat",
  {-1, 20, -1, 24, -1, -1, -1, 16},
  {-1, 20, -1, 25, -1, -1, -1, 16}},
{"weretiger",
  {24, 21, 28, -1, -1, -1, -1, -1},
  {24, 21, 28, -1, -1, -1, -1, -1}},
{"werewolf",
  {25, -1, 29, 26, -1, 31, 28, 17},
  {26, -1, 29, 26, -1, 31, 29, 17}},
{"manticore",
  {27, 22, -1, 27, 4, 32, 30, 18},
  {27, 22, -1, 27, 7, 32, 30, 19}},
{"bandit",
  {28, 23, 30, 28, 8, 33, 31, 20},
  {32, 27, 32, 32, 12, 36, 32, 22}}   // Men, bandit,
{"berserker",
  {33, 28, 33, 33, 13, 37, 33, 23},
  {34, 29, 35, 34, 14, 38, 34, 24}}   // Men, berserker,
{"bandit",
  {35, 30, 36, 35, 15, 39, 35, 25},
  {38, 34, 40, 39, 19, 44, 39, 29}}   // Men, brigand -> bandit,
{"dervish",
  {39, 35, 41, 40, 20, 45, 40, -1},
  {40, 36, 42, 44, 30, 46, 41, -1}}   // Men, dervish,
{"merchant",
  {41, 37, 43, 45, 31, 47, 42, -1},
  {68, 56, 55, 55, 56, 60, 51, -1}}   // Men, merchant,
{"dervish",
  {69, 57, -1, 56, 57, 61, -1, -1},
  {70, 58, -1, 57, 76, 62, -1, -1}}   // Men, nomad -> dervish (no nomad lua, documented),
{"pilgrim",
  {71, 59, 56, 58, 77, 63, 52, 30},
  {80, 69, 60, 63, 84, 67, 59, 31}}   // Men, pilgrim,
{"ogre",
  {81, 70, 61, 64, -1, 68, 60, 32},
  {83, 76, 70, 69, -1, 75, 67, 40}},
{"orc",
  {84, 77, 71, 70, 85, 76, 68, 41},
  {87, 86, 82, 82, 94, 85, 80, 60}},
{"giant_rat",
  {88, 87, 83, 83, -1, 86, -1, 61},
  {89, 89, 85, 85, -1, 88, -1, 75}},
{"giant_skunk",
  {90, 90, 86, 86, -1, 89, -1, -1},
  {91, 91, 91, 87, -1, 90, -1, -1}},
{"vampire",
  {92, -1, 92, -1, 95, -1, 81, 76},
  {92, -1, 92, -1, 95, -1, 87, 80}},
{"will_o_wisp",
  {-1, -1, -1, 88, -1, -1, 88, 81},
  {-1, -1, -1, 89, -1, -1, 89, 100}},
{"wolf",
  {93, 92, 93, 90, 96, 91, 90, -1},
  {100, 100, 100, 100, 100, 100, 100, -1}}
};

// Faerie (plane) (DMG Appendix C)
// 
static const OutdoorRow kOutFaerie[] = {
{"carnivorous_ape",
  {-1, -1, 1, -1, -1, -1, 1, -1},
  {-1, -1, 3, -1, -1, -1, 2, -1}},
{"basilisk",
  {-1, -1, 4, -1, -1, 1, 3, -1},
  {-1, -1, 4, -1, -1, 1, 3, -1}},
{"brown_bear",
  {-1, -1, 5, -1, -1, 2, 4, -1},
  {-1, -1, 8, -1, -1, 3, 8, -1}},
{"giant_boar",
  {1, -1, 9, -1, -1, 4, -1, -1},
  {2, -1, 12, -1, -1, 5, -1, -1}}   // Boar, wild, giant (F extended 09-11->09-12 to cover the printed gap, documented),
{"brownie",
  {-1, -1, 13, -1, -1, 6, -1, -1},
  {-1, -1, 13, -1, -1, 8, -1, -1}},
{"bull",
  {3, -1, 14, -1, -1, 9, -1, -1},
  {8, -1, 15, -1, -1, 10, -1, -1}}   // Bull, wild,
{"centaur",
  {9, -1, 16, -1, -1, 11, -1, -1},
  {12, -1, 16, -1, -1, 14, -1, -1}},
{"chimera",
  {13, -1, 17, -1, -1, 15, 9, -1},
  {14, -1, 17, -1, -1, 16, 14, -1}},
{"cockatrice",
  {-1, -1, 18, -1, -1, -1, 15, -1},
  {-1, -1, 18, -1, -1, -1, 15, -1}},
{"dryad",
  {-1, -1, 19, -1, -1, -1, -1, -1},
  {-1, -1, 19, -1, -1, -1, -1, -1}},
{"dwarf",
  {-1, -1, -1, -1, -1, 17, 16, -1},
  {-1, -1, -1, -1, -1, 18, 22, -1}},
{"elf",
  {15, -1, 20, -1, -1, 19, 23, -1},
  {15, -1, 22, -1, -1, 22, 23, -1}},
{"ettin",
  {16, -1, 23, -1, -1, 23, 24, -1},
  {18, -1, 23, -1, -1, 23, 26, -1}},
{"gnome",
  {-1, -1, 24, -1, -1, 24, 27, -1},
  {-1, -1, 25, -1, -1, 27, 28, -1}},
{"gorgon",
  {19, -1, 26, -1, -1, 28, 29, -1},
  {21, -1, 26, -1, -1, 28, 29, -1}},
{"griffon",
  {22, -1, 27, -1, -1, 29, 30, -1},
  {25, -1, 27, -1, -1, 30, 31, -1}},
{"harpy",
  {26, -1, -1, -1, -1, 31, 32, -1},
  {26, -1, -1, -1, -1, 31, 33, -1}},
{"hippogriff",
  {27, -1, -1, -1, -1, 32, 34, -1},
  {30, -1, -1, -1, -1, 33, 36, -1}},
{"leopard",
  {31, -1, 28, -1, -1, 34, 37, -1},
  {32, -1, 31, -1, -1, 34, 37, -1}},
{"mountain_lion",
  {-1, -1, -1, -1, -1, 35, 38, -1},
  {-1, -1, -1, -1, -1, 35, 39, -1}},
{"manticore",
  {33, -1, 32, -1, -1, 36, 40, -1},
  {36, -1, 33, -1, -1, 37, 40, -1}},
{"bandit",
  {37, -1, 34, -1, -1, 38, 41, -1},
  {38, -1, 38, -1, -1, 39, 41, -1}}   // Men, bandit,
{"dervish",
  {39, -1, 39, -1, -1, 40, 42, -1},
  {41, -1, 39, -1, -1, 41, 42, -1}}   // Men, dervish,
{"pilgrim",
  {42, -1, 40, -1, -1, 42, 43, -1},
  {46, -1, 41, -1, -1, 43, 44, -1}}   // Men, pilgrim,
{"caveman",
  {47, -1, 42, -1, -1, 44, 45, -1},
  {51, -1, 44, -1, -1, 46, 45, -1}}   // Men, tribesmen -> caveman,
{"ogre",
  {52, -1, 45, -1, -1, 47, 46, -1},
  {59, -1, 47, -1, -1, 48, 50, -1}},
{"pegasus",
  {60, -1, -1, -1, -1, 49, 51, -1},
  {65, -1, -1, -1, -1, 49, 55, -1}},
{"peryton",
  {66, -1, 48, -1, -1, 50, 56, -1},
  {69, -1, 50, -1, -1, 51, 58, -1}},
{"pixie",
  {70, -1, 51, -1, -1, 52, -1, -1},
  {76, -1, 55, -1, -1, 53, -1, -1}},
{"satyr",
  {77, -1, 56, -1, -1, 54, -1, -1},
  {77, -1, 65, -1, -1, 55, -1, -1}},
{"sprite",
  {78, -1, 66, -1, -1, 56, -1, -1},
  {79, -1, 70, -1, -1, 57, -1, -1}},
{"giant_stag",
  {80, -1, 71, -1, -1, 58, 59, -1},
  {81, -1, 75, -1, -1, 60, 60, -1}},
{"stirge",
  {82, -1, 76, -1, -1, 61, 61, -1},
  {83, -1, 78, -1, -1, 65, 65, -1}},
{"su_monster",
  {-1, -1, 79, -1, -1, -1, -1, -1},
  {-1, -1, 85, -1, -1, -1, -1, -1}},
{"sylph",
  {84, -1, 86, -1, -1, 66, 66, -1},
  {86, -1, 86, -1, -1, 70, 70, -1}},
{"troll",
  {87, -1, 87, -1, -1, 71, 71, -1},
  {88, -1, 88, -1, -1, 75, 85, -1}},
{"unicorn",
  {89, -1, 89, -1, -1, 76, -1, -1},
  {90, -1, 96, -1, -1, 80, -1, -1}},
{"wolf",
  {91, -1, 97, -1, -1, 81, 86, -1},
  {100, -1, 100, -1, -1, 100, 100, -1}}
};

// Pleistocene Conditions (DMG Appendix C)
// 
static const OutdoorRow kOutPleistocene[] = {
{"axe_beak",
  {1, 1, -1, -1, -1, -1, -1, -1},
  {5, 2, -1, -1, -1, -1, -1, -1}},
{"baluchitherium",
  {6, 3, 1, -1, -1, -1, -1, -1},
  {10, 7, 5, -1, -1, -1, -1, -1}},
{"cave_bear",
  {-1, -1, 6, 1, -1, 1, 1, -1},
  {-1, -1, 7, 5, -1, 5, 20, -1}},
{"giant_boar",
  {11, 8, 8, 6, -1, 6, -1, -1},
  {13, 12, 12, 9, -1, 10, -1, -1}},
{"bull",
  {14, 13, 13, -1, -1, 11, -1, -1},
  {16, 14, 14, -1, -1, 13, -1, -1}},
{"wild_camel",
  {-1, 15, 15, -1, -1, -1, -1, -1},
  {-1, 17, 17, -1, -1, -1, -1, -1}}   // Camel -> wild_camel (no camel.lua),
{"wild_cattle",
  {17, 18, 18, 10, -1, 14, -1, -1},
  {21, 20, 19, 11, -1, 16, -1, -1}},
{"giant_crocodile",
  {-1, 21, -1, 12, -1, -1, -1, 1},
  {-1, 23, -1, 15, -1, -1, -1, 20}}   // book fn **: only if water nearby, else wild cattle (no water map - kept, documented),
{"flightless_bird",
  {22, 24, -1, 16, -1, 17, -1, 21},
  {26, 25, -1, 25, -1, 20, -1, 70}},
{"herd_animal",
  {27, 26, 20, 26, -1, 21, 21, 71},
  {50, 50, 50, 65, -1, 50, 50, 90}},
{"giant_hyena",
  {51, 51, -1, 66, -1, 51, -1, -1},
  {55, 55, -1, 75, -1, 55, -1, -1}},
{"irish_deer",
  {-1, -1, 51, -1, -1, 56, 51, -1},
  {-1, -1, 55, -1, -1, 60, 60, -1}},
{"spotted_lion",
  {56, 56, 56, 76, -1, 61, 61, -1},
  {57, 57, 60, 85, -1, 65, 70, -1}},
{"mammoth",
  {58, 58, 61, -1, -1, 66, -1, -1},
  {65, 65, 65, -1, -1, 70, -1, -1}},
{"mastodon",
  {66, 66, 66, -1, -1, 71, -1, 91},
  {70, 70, 70, -1, -1, 75, -1, 98}}   // fn ***: shovel-toothed proboscidia (flavor),
{"caveman",
  {-1, -1, 71, 86, -1, 76, 71, -1},
  {-1, -1, 75, 90, -1, 80, 90, -1}}   // Men, cavemen,
{"woolly_rhinoceros",
  {71, 71, -1, -1, -1, 81, -1, -1},
  {75, 75, -1, -1, -1, 85, -1, -1}},
{"giant_stag",
  {76, 76, 76, -1, -1, 86, -1, -1},
  {80, 80, 80, -1, -1, 90, -1, -1}},
{"constrictor_snake",
  {-1, -1, 81, -1, -1, -1, -1, 99},
  {-1, -1, 82, -1, -1, -1, -1, 100}},
{"sabre_tooth_tiger",
  {81, 81, 83, -1, -1, 91, -1, -1},
  {87, 90, 90, -1, -1, 92, -1, -1}},
{"titanotherium",
  {88, 91, -1, -1, -1, -1, -1, -1},
  {95, 95, -1, -1, -1, -1, -1, -1}},
{"giant_weasel",
  {96, 96, 91, -1, -1, 93, -1, -1},
  {98, 98, 95, -1, -1, 95, -1, -1}}   // fn *: 'cat-like' early carnivore (flavor),
{"dire_wolf",
  {99, 99, 96, 91, -1, 96, 91, -1},
  {100, 100, 100, 100, -1, 100, 100, -1}}
};

// Dinosaur Age (DMG Appendix C)
// 
static const OutdoorRow kOutDinosaurAge[] = {
{"anatosaurus",
  {1, 1, 1, -1, -1, -1, -1, 1},
  {10, 6, 8, -1, -1, -1, -1, 12}},
{"ankylosaurus",
  {11, 7, -1, -1, -1, -1, -1, -1},
  {12, 10, -1, -1, -1, -1, -1, -1}},
{"antrodemus",
  {-1, 11, 9, -1, -1, -1, -1, -1},
  {-1, 12, 14, -1, -1, -1, -1, -1}},
{"apatosaurus",
  {13, 13, 15, -1, -1, -1, -1, 13},
  {13, 13, 19, -1, -1, -1, -1, 18}}   // dagger: only if water nearby (no water map - kept, documented),
{"brachiosaurus",
  {14, 14, 20, -1, -1, -1, -1, 19},
  {14, 14, 20, -1, -1, -1, -1, 23}}   // dagger fn (as above),
{"camarasaurus",
  {15, 15, 21, -1, -1, -1, -1, 24},
  {15, 17, 23, -1, -1, -1, -1, 28}},
{"ceratosaurus",
  {-1, 18, 24, -1, -1, -1, -1, -1},
  {-1, 22, 28, -1, -1, -1, -1, -1}},
{"cetiosaurus",
  {16, 23, 29, -1, -1, -1, -1, 29},
  {16, 23, 29, -1, -1, -1, -1, 34}}   // dagger fn,
{"giant_crocodile",
  {-1, -1, -1, -1, -1, -1, -1, 35},
  {-1, -1, -1, -1, -1, -1, -1, 40}},
{"diplodocus",
  {17, 24, 30, -1, -1, -1, -1, 41},
  {17, 24, 30, -1, -1, -1, -1, 48}}   // dagger fn,
{"gorgosaurus",
  {18, 25, -1, -1, -1, -1, -1, -1},
  {20, 28, -1, -1, -1, -1, -1, -1}},
{"IGUANODON_SET",
  {21, 29, 31, -1, -1, -1, -1, 49},
  {40, 35, 40, -1, -1, -1, -1, 56}}   // Iguanodon/Lambeosaurus,
{"giant_lizard",
  {-1, -1, 41, -1, -1, -1, -1, 57},
  {-1, -1, 45, -1, -1, -1, -1, 60}},
{"minotaur_lizard",
  {41, -1, -1, -1, -1, -1, -1, 61},
  {42, -1, -1, -1, -1, -1, -1, 63}},
{"megalosaurus",
  {-1, -1, 46, -1, -1, -1, -1, -1},
  {-1, -1, 50, -1, -1, -1, -1, -1}},
{"monoclonius",
  {43, 36, -1, -1, -1, -1, -1, -1},
  {46, 41, -1, -1, -1, -1, -1, -1}},
{"MISC_REPTILE",
  {47, 42, 51, -1, -1, -1, -1, 64},
  {53, 47, 55, -1, -1, -1, -1, 65}}   // Misc small-medium reptiles -> giant_lizard (fn *, documented),
{"megalosaurus",
  {-1, -1, -1, -1, -1, -1, -1, 66},
  {-1, -1, -1, -1, -1, -1, -1, 71}}   // Nothosaurus -> megalosaurus per book fn **,
{"paleoscincus",
  {-1, -1, 56, -1, -1, -1, -1, 72},
  {-1, -1, 63, -1, -1, -1, -1, 76}},
{"pentaceratops",
  {54, 48, -1, -1, -1, -1, -1, -1},
  {67, 54, -1, -1, -1, -1, -1, -1}},
{"plateosaurus",
  {-1, 55, 64, -1, -1, -1, -1, -1},
  {-1, 60, 80, -1, -1, -1, -1, -1}},
{"pteranodon",
  {68, 61, -1, -1, -1, -1, -1, 77},
  {69, 62, -1, -1, -1, -1, -1, 82}}   // 'Pterodactyl, small' -> pteranodon (fn *, documented),
{"pteranodon",
  {70, 63, -1, -1, -1, -1, -1, 83},
  {76, 67, -1, -1, -1, -1, -1, 89}},
{"constrictor_snake",
  {-1, 68, 81, -1, -1, -1, -1, 90},
  {-1, 69, 85, -1, -1, -1, -1, 100}},
{"stegosaurus",
  {-1, 70, 86, -1, -1, -1, -1, -1},
  {-1, 82, 95, -1, -1, -1, -1, -1}},
{"styracosaurus",
  {77, 83, -1, -1, -1, -1, -1, -1},
  {79, 87, -1, -1, -1, -1, -1, -1}},
{"teratosaurus",
  {80, 88, 96, -1, -1, -1, -1, -1},
  {82, 89, 100, -1, -1, -1, -1, -1}},
{"triceratops",
  {83, 90, -1, -1, -1, -1, -1, -1},
  {92, 95, -1, -1, -1, -1, -1, -1}},
{"tyrannosaurus_rex",
  {93, 96, -1, -1, -1, -1, -1, -1},
  {100, 100, -1, -1, -1, -1, -1, -1}}
};

// Tropical Conditions (DMG Appendix C)
// 
static const OutdoorRow kOutTropical[] = {
{"giant_ant",
  {1, 1, 1, 1, -1, 1, -1, -1},
  {2, 2, 2, 2, -1, 2, -1, -1}},
{"ape",
  {-1, -1, 3, -1, -1, -1, -1, -1},
  {-1, -1, 5, -1, -1, -1, -1, -1}},
{"baboon",
  {-1, 3, 6, 3, 1, -1, 1, -1},
  {-1, 5, 6, 7, 4, -1, 3, -1}},
{"black_bear",
  {-1, -1, 7, 8, -1, -1, 4, -1},
  {-1, -1, 9, 9, -1, -1, 6, -1}},
{"rhinoceros_beetle",
  {-1, -1, 10, -1, -1, -1, -1, -1},
  {-1, -1, 12, -1, -1, -1, -1, -1}},
{"warthog",
  {3, 6, -1, 10, -1, -1, -1, -1},
  {5, 8, -1, 13, -1, -1, -1, -1}},
{"buffalo",
  {6, 9, -1, 14, -1, 3, -1, 1},
  {10, 12, -1, 15, -1, 7, -1, 10}},
{"wild_camel",
  {-1, -1, -1, -1, 5, -1, -1, -1},
  {-1, -1, -1, -1, 11, -1, -1, -1}}   // Camel -> wild_camel (no camel.lua),
{"giant_centipede",
  {-1, -1, 13, -1, 12, -1, -1, -1},
  {-1, -1, 16, -1, 14, -1, -1, -1}},
{"couatl",
  {-1, -1, 17, -1, -1, -1, -1, -1},
  {-1, -1, 18, -1, -1, -1, -1, -1}},
{"crocodile",
  {-1, -1, -1, -1, -1, -1, -1, 11},
  {-1, -1, -1, -1, -1, -1, -1, 35}},
{"elephant",
  {-1, 13, 19, -1, -1, 8, -1, -1},
  {-1, 16, 24, -1, -1, 10, -1, -1}},
{"loxodont",
  {-1, 17, 25, -1, -1, -1, -1, -1},
  {-1, 20, 30, -1, -1, -1, -1, -1}},
{"flightless_bird",
  {11, 21, -1, -1, -1, -1, -1, -1},
  {16, 22, -1, -1, -1, -1, -1, -1}},
{"herd_animal",
  {17, 23, 31, 16, 15, 11, 7, -1},
  {35, 35, 33, 18, 16, 20, 10, -1}},
{"hippopotamus",
  {-1, -1, -1, -1, -1, -1, -1, 36},
  {-1, -1, -1, -1, -1, -1, -1, 50}},
{"hyena",
  {36, 36, -1, 19, -1, 21, -1, -1},
  {40, 40, -1, 25, -1, 25, -1, -1}},
{"jackal",
  {41, 41, -1, 26, 17, 26, -1, -1},
  {44, 44, -1, 29, 24, 29, -1, -1}},
{"jackalwere",
  {45, 45, -1, 30, 25, 30, -1, -1},
  {45, 45, -1, 30, 25, 30, -1, -1}},
{"jaguar",
  {-1, -1, 34, -1, -1, -1, -1, -1},
  {-1, -1, 38, -1, -1, -1, -1, -1}},
{"lamia",
  {-1, -1, 39, 31, 26, -1, -1, -1},
  {-1, -1, 40, 35, 28, -1, -1, -1}},
{"LAMMASU_SET",
  {-1, 46, -1, 36, 29, 31, 11, -1},
  {-1, 46, -1, 38, 35, 32, 15, -1}}   // Lammasu/Shedu,
{"giant_leech",
  {-1, -1, -1, -1, -1, -1, -1, 51},
  {-1, -1, -1, -1, -1, -1, -1, 60}},
{"leopard",
  {-1, 47, 41, 39, 36, -1, 16, -1},
  {-1, 50, 47, 40, 37, -1, 20, -1}},
{"lion",
  {46, 51, 48, -1, 38, 33, -1, -1},
  {55, 55, 50, -1, 40, 38, -1, -1}},
{"minotaur_lizard",
  {-1, -1, -1, 41, -1, -1, -1, -1},
  {-1, -1, -1, 45, -1, -1, -1, -1}},
{"weretiger",
  {-1, -1, 51, -1, -1, 39, 21, -1},
  {-1, -1, 52, -1, -1, 40, 22, -1}},
{"bandit",
  {56, 56, 53, 46, 41, 41, 23, -1},
  {59, 59, 56, 48, 45, 45, 30, -1}}   // Men, bandit (slavers, book fn **; M col 23-28 printed -> 23-30 covers OCR gap, documented),
{"dervish",
  {60, -1, -1, 49, 46, 46, -1, -1},
  {60, -1, -1, 50, 55, 47, -1, -1}}   // Men, dervish (M 46-47 / W 29-30 printed but column-shift artifacts - dropped, documented); H 46-55 OCR bleed from desert col -> 46-47 (merchant 48-55 follows, documented),
{"merchant",
  {61, 60, -1, 51, 56, 48, 31, -1},
  {68, 65, -1, 53, 65, 55, 35, -1}}   // Men, merchant,
{"dervish",
  {69, -1, -1, 54, 66, 56, -1, -1},
  {70, -1, -1, 60, 81, 63, -1, -1}}   // Men, nomad -> dervish (documented),
{"pilgrim",
  {-1, -1, -1, 61, 82, 64, 36, -1},
  {-1, -1, -1, 68, 83, 68, 38, -1}}   // Men, pilgrim,
{"caveman",
  {-1, 66, 57, 69, -1, 69, 39, 61},
  {-1, 71, 60, 72, -1, 74, 50, 73}}   // Men, tribesman -> caveman,
{"guardian_naga",
  {-1, -1, -1, 73, -1, 75, 51, -1},
  {-1, -1, -1, 74, -1, 75, 53, -1}},
{"spirit_naga",
  {-1, -1, -1, 75, -1, 76, 54, 74},
  {-1, -1, -1, 76, -1, 78, 55, 75}},
{"rakshasa",
  {-1, -1, -1, 77, -1, 79, 56, -1},
  {-1, -1, -1, 80, -1, 80, 60, -1}},
{"rhinoceros",
  {71, 72, -1, -1, -1, -1, -1, -1},
  {80, 77, -1, -1, -1, -1, -1, -1}},
{"roc",
  {81, 78, -1, 81, -1, 81, 61, -1},
  {85, 84, -1, 83, -1, 85, 70, -1}},
{"giant_scorpion",
  {86, 85, 61, 84, 84, -1, -1, -1},
  {90, 86, 64, 85, 89, -1, -1, -1}},
{"amphisbaena_snake",
  {91, -1, -1, -1, 90, -1, -1, -1},
  {92, -1, -1, -1, 91, -1, -1, -1}},
{"constrictor_snake",
  {-1, -1, 65, -1, -1, -1, -1, 76},
  {-1, -1, 70, -1, -1, -1, -1, 80}}   // Snake, constricting,
{"poisonous_snake",
  {-1, 87, 71, 86, 92, -1, 71, 81},
  {-1, 92, 74, 88, 93, -1, 75, 85}},
{"spitting_snake",
  {93, -1, 75, 89, 94, 86, -1, -1},
  {95, -1, 76, 90, 95, 87, -1, -1}},
{"spectre",
  {-1, -1, -1, 91, -1, -1, -1, -1},
  {-1, -1, -1, 93, -1, -1, -1, -1}},
{"SUB_SPHINX_T",
  {-1, -1, -1, 94, 96, 88, 76, -1},
  {-1, -1, -1, 95, 100, 90, 80, -1}}   // tropical Sphinx Subtable,
{"giant_spider",
  {-1, -1, 77, -1, -1, -1, -1, -1},
  {-1, -1, 80, -1, -1, -1, -1, -1}},
{"huge_spider",
  {-1, -1, 81, -1, -1, -1, -1, -1},
  {-1, -1, 86, -1, -1, -1, -1, -1}},
{"large_spider",
  {-1, 93, -1, -1, -1, -1, -1, 86},
  {-1, 95, -1, -1, -1, -1, -1, 89}},
{"tiger",
  {-1, -1, 87, -1, -1, 91, 81, -1},
  {-1, -1, 95, -1, -1, 95, 90, -1}},
{"giant_toad",
  {-1, -1, 96, -1, -1, -1, -1, 90},
  {-1, -1, 98, -1, -1, -1, -1, 96}},
{"poisonous_toad",
  {-1, -1, 99, -1, -1, -1, -1, 97},
  {-1, -1, 100, -1, -1, -1, -1, 100}},
{"WOLF_DOG_SET",
  {96, 96, -1, 96, -1, 96, 91, -1},
  {100, 100, -1, 100, -1, 100, 100, -1}}   // Wolf/Wild dog
};

// The eleven subtables, resolved per terrain column on the
// second percentile (DMG p.185-186).

// Demi-Human Subtable
// 
static const OutdoorRow kOutDemiHuman[] = {
{"dwarf",
  {1, 1, 1, 1, -1, 1, 1, -1},
  {5, 5, 5, 10, -1, 20, 70, -1}},
{"elf",
  {6, 6, 6, 11, -1, 21, 71, -1},
  {70, 60, 70, 15, -1, 30, 75, -1}},
{"gnome",
  {71, 61, 71, 16, -1, 31, 76, -1},
  {80, 80, 95, 85, -1, 70, 95, -1}},
{"halfling",
  {81, 81, 96, 86, -1, 71, 96, -1},
  {100, 100, 100, 100, -1, 100, 100, -1}}
};

// Dragon Subtable
// 
static const OutdoorRow kOutDragon[] = {
{"black_dragon",
  {1, 1, 1, 1, 1, 1, 1, 1},
  {2, 2, 16, 30, 2, 6, 4, 50}},
{"blue_dragon",
  {3, 3, 17, 31, 3, 7, 5, 51},
  {4, 4, 18, 32, 20, 10, 15, 52}},
{"brass_dragon",
  {5, 5, 19, 33, 21, 11, 16, 53},
  {6, 6, 20, 40, 65, 20, 17, 54}},
{"bronze_dragon",
  {7, 7, 21, 41, 66, 21, 18, 55},
  {8, 8, 22, 45, 67, 25, 25, 56}},
{"chimera",
  {9, 9, 23, 46, 68, 26, 26, 57},
  {10, 10, 30, 50, 70, 35, 30, 58}}   // F 24-30 OCR -> 23-30 to cover the printed gap, documented,
{"copper_dragon",
  {11, 11, 31, 51, 71, 36, 31, 59},
  {12, 14, 35, 55, 80, 45, 40, 60}},
{"gold_dragon",
  {13, 15, 36, 56, 81, 46, 41, 61},
  {28, 16, 40, 57, 82, 50, 45, 62}},
{"green_dragon",
  {29, 17, 41, 58, 83, 51, 46, 63},
  {30, 36, 80, 59, 84, 52, 47, 75}},
{"red_dragon",
  {31, 37, 81, 60, 85, 53, 48, 76},
  {32, 38, 82, 64, 88, 60, 60, 77}},
{"white_dragon",
  {33, 39, 83, 65, 89, 61, 61, 78},
  {34, 40, 84, 66, 90, 65, 95, 79}},
{"wyvern",
  {35, 41, 85, 67, 91, 66, 96, 80},
  {100, 100, 100, 100, 100, 100, 100, 100}}
};

// Frog Subtable
// 
static const OutdoorRow kOutFrog[] = {
{"giant_frog",
  {-1, -1, -1, -1, -1, -1, -1, 1},
  {-1, -1, -1, -1, -1, -1, -1, 70}},
{"killer_frog",
  {-1, -1, -1, -1, -1, -1, -1, 71},
  {-1, -1, -1, -1, -1, -1, -1, 80}},
{"poisonous_frog",
  {-1, -1, -1, -1, -1, -1, -1, 81},
  {-1, -1, -1, -1, -1, -1, -1, 100}}
};

// Giant Subtable
// 
static const OutdoorRow kOutGiant[] = {
{"cloud_giant",
  {1, 1, 1, 1, -1, 1, 1, -1},
  {2, 2, 2, 2, -1, 3, 15, -1}},
{"ettin",
  {3, 3, 3, 3, -1, 4, 16, -1},
  {4, 5, 10, 10, -1, 10, 20, -1}},
{"fire_giant",
  {5, 6, 11, 11, -1, 11, 21, -1},
  {6, 7, 12, 20, -1, 15, 30, -1}},
{"frost_giant",
  {7, 8, 13, 21, -1, 16, 31, -1},
  {8, 9, 14, 25, -1, 20, 45, -1}},
{"hill_giant",
  {9, 10, 15, 26, -1, 21, 46, -1},
  {95, 94, 93, 85, -1, 81, 50, -1}},
{"stone_giant",
  {96, 95, 94, 86, -1, 82, 51, -1},
  {98, 98, 98, 98, -1, 98, 90, -1}}   // H 81-98 OCR -> 82-98 for contiguous coverage after hill 21-81, documented,
{"storm_giant",
  {99, 99, 99, 99, -1, 99, 91, -1},
  {99, 99, 99, 99, -1, 99, 98, -1}},
{"titan",
  {100, 100, 100, 100, -1, 100, 99, -1},
  {100, 100, 100, 100, -1, 100, 100, -1}}
};

// Humanoid Subtable
// 
static const OutdoorRow kOutHumanoid[] = {
{"gnoll",
  {1, 1, 1, 1, -1, 1, 1, 1},
  {5, 10, 10, 20, -1, 25, 15, 25}},
{"goblin",
  {6, 11, 11, 21, 1, 26, 16, 26},
  {10, 15, 20, 30, 40, 50, 50, 35}},
{"hobgoblin",
  {11, 16, 21, 31, 41, 51, 51, 36},
  {15, 50, 30, 50, 90, 75, 65, 75}},
{"kobold",
  {-1, 51, 31, 51, -1, -1, -1, -1},
  {-1, 80, 80, 55, -1, -1, -1, -1}},
{"orc",
  {16, 81, 81, 56, 91, 76, 66, 76},
  {100, 100, 100, 100, 100, 100, 100, 100}}
};

// Lycanthrope Subtable
// 
static const OutdoorRow kOutLycanthrope[] = {
{"werebear",
  {1, -1, 1, 1, -1, 1, 1, -1},
  {2, -1, 10, 2, -1, 2, 75, -1}},
{"wereboar",
  {3, -1, 11, 3, -1, 3, -1, -1},
  {25, -1, 70, 15, -1, 15, -1, -1}}   // 2nd printed 'Werebear' row is Wereboar (OCR dup, documented),
{"wererat",
  {26, -1, -1, 16, -1, 16, 76, -1},
  {30, -1, -1, 90, -1, 20, 80, -1}},
{"weretiger",
  {31, -1, 71, -1, -1, 21, 81, -1},
  {40, -1, 90, -1, -1, 30, 90, -1}},
{"werewolf",
  {41, -1, 91, 91, -1, 31, 91, -1},
  {100, -1, 100, 100, -1, 100, 100, -1}}
};

// Men Subtable
// 
static const OutdoorRow kOutMen[] = {
{"bandit",
  {1, 1, 1, 1, 1, 1, 1, 1},
  {5, 10, 10, 10, 5, 10, 5, 5}},
{"berserker",
  {6, 11, -1, 11, -1, 11, 6, -1},
  {7, 12, -1, 12, -1, 12, 10, -1}},
{"bandit",
  {8, 13, 11, 13, 6, 13, 11, 6},
  {10, 15, 15, 15, 10, 20, 20, 10}}   // Men, brigand -> bandit (no brigand.lua),
{"SUB_CHARACTER",
  {11, 16, 16, 16, 11, 21, 21, 11},
  {20, 25, 25, 25, 20, 30, 30, 20}}   // Character row: 10% of the remainder in all cases -> rollCharacterParty(dice, 8, 8), levels 7-10 (p.187 note),
{"dervish",
  {21, 26, -1, 26, 21, 31, 31, -1},
  {22, 27, -1, 27, 50, 40, 35, -1}},
{"merchant",
  {23, 28, 26, 28, 51, 41, 36, 21},
  {60, 60, 40, 50, 75, 65, 50, 35}},
{"dervish",
  {61, 61, -1, 51, 76, 66, -1, -1},
  {90, 80, -1, 60, 95, 80, -1, -1}}   // Men, nomad -> dervish (no nomad.lua),
{"pilgrim",
  {91, 81, 41, 61, 96, 81, 51, 36},
  {95, 85, 45, 80, 100, 90, 65, 50}}   // Marsh W 36-30 OCR defect -> 36-50 (documented),
{"caveman",
  {96, 86, 46, 81, -1, 91, 66, 51},
  {100, 100, 100, 100, -1, 100, 100, 100}}   // Men, tribesman -> caveman; marsh 31-00 OCR defect -> 51-00 (documented)
};

// Snake Subtable
// 
static const OutdoorRow kOutSnake[] = {
{"amphisbaena_snake",
  {1, 1, -1, -1, 1, 1, -1, -1},
  {10, 5, -1, -1, 15, 5, -1, -1}},
{"constrictor_snake",
  {-1, 6, 1, 1, -1, 6, -1, 1},
  {-1, 10, 65, 5, -1, 10, -1, 70}},
{"poisonous_snake",
  {11, 11, 66, 6, 16, 11, 1, 71},
  {80, 80, 95, 95, 90, 90, 90, 100}},
{"spitting_snake",
  {81, 81, 96, 96, 91, 91, 91, -1},
  {100, 100, 100, 100, 100, 100, 100, -1}}
};

// Sphinx Subtable
// 
static const OutdoorRow kOutSphinx[] = {
{"androsphinx",
  {-1, -1, 1, 1, 1, 1, 1, 1},
  {-1, -1, 5, 10, 40, 10, 15, 5}},
{"criosphinx",
  {-1, -1, 6, 11, 41, 11, 16, 6},
  {-1, -1, 75, 30, 50, 70, 35, 55}},
{"gynosphinx",
  {-1, -1, 76, 31, 51, 71, 36, 56},
  {-1, -1, 80, 50, 90, 80, 55, 65}},
{"hieracosphinx",
  {-1, -1, 81, 51, 91, 81, 56, 66},
  {-1, -1, 100, 100, 100, 100, 100, 100}}
};

// Spider Subtable
// 
static const OutdoorRow kOutSpider[] = {
{"giant_spider",
  {-1, -1, 1, -1, -1, -1, -1, -1},
  {-1, -1, 55, -1, -1, -1, -1, -1}},
{"huge_spider",
  {1, 1, 56, 1, -1, 1, -1, -1},
  {15, 25, 75, 20, -1, 20, -1, -1}},
{"large_spider",
  {16, 26, 76, 21, 1, 21, -1, -1},
  {100, 100, 80, 100, 100, 100, -1, -1}},
{"phase_spider",
  {-1, -1, 81, -1, -1, -1, -1, -1},
  {-1, -1, 100, -1, -1, -1, -1, -1}}
};

// Undead Subtable
// 
static const OutdoorRow kOutUndead[] = {
{"ghost",
  {-1, -1, 1, 1, -1, 1, 1, 1},
  {-1, -1, 10, 15, -1, 10, 10, 15}},
{"ghast",
  {-1, -1, 11, 16, -1, 11, 11, 16},
  {-1, -1, 12, 20, -1, 12, 13, 18}}   // 2nd printed 'Ghost' row is Ghast (OCR dup, documented),
{"ghoul",
  {-1, -1, 13, 21, -1, 13, 14, 19},
  {-1, -1, 55, 55, -1, 35, 30, 75}},
{"lich",
  {-1, -1, 56, 56, -1, 36, 31, -1},
  {-1, -1, 56, 60, -1, 40, 35, -1}},
{"mummy",
  {-1, -1, -1, 61, -1, 41, 36, -1},
  {-1, -1, -1, 70, -1, 55, 40, -1}},
{"shadow",
  {-1, -1, 57, 71, -1, 56, 41, 76},
  {-1, -1, 70, 84, -1, 61, 50, 81}},
{"spectre",
  {-1, -1, 71, 85, -1, 62, 51, 82},
  {-1, -1, 79, 87, -1, 64, 60, 91}},
{"vampire",
  {-1, -1, 80, 88, -1, 65, 61, 92},
  {-1, -1, 89, 89, -1, 74, 75, 93}},
{"wight",
  {-1, -1, 90, 90, -1, 75, 76, -1},
  {-1, -1, 96, 98, -1, 97, 94, -1}},
{"wraith",
  {-1, -1, 97, 99, -1, 98, 95, 94},
  {-1, -1, 100, 100, -1, 100, 100, 100}}
};

// pick-sets (second percentile modulo size)
static const char* const kOutKiRinSet[]      = {"ki_rin", "lammasu", "shedu"};
static const char* const kOutLeprechaunSet[] = {"leprechaun", "brownie"};
static const char* const kOutPorcupineSet[]  = {"giant_porcupine", "giant_skunk"};
static const char* const kOutIguanodonSet[] = {"iguanodon", "lambeosaurus"};
static const char* const kOutLammasuSet[]   = {"lammasu", "shedu"};
static const char* const kOutWolfDogSet[]  = {"wolf", "wild_dog"};

} // namespace

// Resolve a main-table row (or Men-subtable row) at the terrain
// column: returns the registry key, or handles SUB_* dispatch and
// pick-sets. isParty set for the Men Character row. False return
// means no encounter (defensive; every printed column covers 01-00).
static bool resolveOutdoorKey(const OutdoorRow* row, int terrain,
                              int pctile2, std::string& key) {
    (void)terrain;   // sets don't vary by terrain
    key = row->key;
    if      (key == "KI_RIN_SET")      key = kOutKiRinSet[pctile2 % 3];
    else if (key == "LEPRECHAUN_SET")  key = kOutLeprechaunSet[pctile2 % 2];
    else if (key == "PORCUPINE_SET")   key = kOutPorcupineSet[pctile2 % 2];
    else if (key == "IGUANODON_SET")   key = kOutIguanodonSet[pctile2 % 2];
    else if (key == "LAMMASU_SET")     key = kOutLammasuSet[pctile2 % 2];
    else if (key == "WOLF_DOG_SET")    key = kOutWolfDogSet[pctile2 % 2];
    else if (key == "MISC_REPTILE")    key = "giant_lizard";
    else if (key == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable (p.189)
        if      (pctile2 <= 10) key = "androsphinx";
        else if (pctile2 <= 40) key = "criosphinx";
        else if (pctile2 <= 70) key = "gynosphinx";
        else                    key = "hieracosphinx";
    } else if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
        // terrain-column subtable, resolved on pctile2
        const OutdoorRow* sub = nullptr; size_t n = 0;
        if      (key == "SUB_DEMIHUMAN")  { sub = kOutDemiHuman;    n = sizeof kOutDemiHuman    / sizeof kOutDemiHuman[0];    }
        else if (key == "SUB_DRAGON")     { sub = kOutDragon;       n = sizeof kOutDragon       / sizeof kOutDragon[0];       }
        else if (key == "SUB_FROG")       { sub = kOutFrog;         n = sizeof kOutFrog         / sizeof kOutFrog[0];         }
        else if (key == "SUB_GIANT")     { sub = kOutGiant;         n = sizeof kOutGiant         / sizeof kOutGiant[0];         }
        else if (key == "SUB_HUMANOID")   { sub = kOutHumanoid;     n = sizeof kOutHumanoid      / sizeof kOutHumanoid[0];      }
        else if (key == "SUB_LYCANTHROPE"){ sub = kOutLycanthrope;  n = sizeof kOutLycanthrope  / sizeof kOutLycanthrope[0];  }
        else if (key == "SUB_MEN")       { sub = kOutMen;          n = sizeof kOutMen          / sizeof kOutMen[0];          }
        else if (key == "SUB_SNAKE")      { sub = kOutSnake;        n = sizeof kOutSnake         / sizeof kOutSnake[0];        }
        else if (key == "SUB_SPHINX")     { sub = kOutSphinx;       n = sizeof kOutSphinx        / sizeof kOutSphinx[0];       }
        else if (key == "SUB_SPIDER")     { sub = kOutSpider;       n = sizeof kOutSpider        / sizeof kOutSpider[0];       }
        else if (key == "SUB_UNDEAD")     { sub = kOutUndead;       n = sizeof kOutUndead        / sizeof kOutUndead[0];       }
        else return false;
        const OutdoorRow* sr = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (sub[i].lo[terrain] >= 0 &&
                pctile2 >= sub[i].lo[terrain] && pctile2 <= sub[i].hi[terrain])
                { sr = &sub[i]; break; }
        if (!sr) return false;
        return resolveOutdoorKey(sr, terrain, pctile2, key);
    }
    return true;
}

// The registry keys one climate/terrain column can produce — the
// regtest-style companion of rollOutdoorEncounter.
static void pushOutKeys(std::vector<std::string>& out,
                        const monsters::MonsterRegistry& reg,
                        const OutdoorRow* t, size_t n, int terrain) {
    for (size_t i = 0; i < n; ++i) {
        if (t[i].lo[terrain] < 0) continue;
        std::string key = t[i].key;
        if (key == "SUB_CHARACTER") { pushUnique(out, "character_party"); continue; }
        if (key == "MISC_REPTILE")  { pushUnique(out, "giant_lizard"); continue; }
        if (key == "KI_RIN_SET") {
            for (const char* k : kOutKiRinSet) pushUnique(out, k);
            continue;
        }
        if (key == "LEPRECHAUN_SET") {
            for (const char* k : kOutLeprechaunSet) pushUnique(out, k);
            continue;
        }
        if (key == "PORCUPINE_SET") {
            for (const char* k : kOutPorcupineSet) pushUnique(out, k);
            continue;
        }
        if (key == "IGUANODON_SET") {
            for (const char* k : kOutIguanodonSet) pushUnique(out, k);
            continue;
        }
        if (key == "LAMMASU_SET") {
            for (const char* k : kOutLammasuSet) pushUnique(out, k);
            continue;
        }
        if (key == "WOLF_DOG_SET") {
            for (const char* k : kOutWolfDogSet) pushUnique(out, k);
            continue;
        }
        if (key == "SUB_SPHINX_T") {
            pushUnique(out, "androsphinx"); pushUnique(out, "criosphinx");
            pushUnique(out, "gynosphinx");  pushUnique(out, "hieracosphinx");
            continue;
        }
        if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
            const OutdoorRow* sub = nullptr; size_t sn = 0;
            if      (key == "SUB_DEMIHUMAN")  { sub = kOutDemiHuman;    sn = sizeof kOutDemiHuman    / sizeof kOutDemiHuman[0];    }
            else if (key == "SUB_DRAGON")     { sub = kOutDragon;       sn = sizeof kOutDragon       / sizeof kOutDragon[0];       }
            else if (key == "SUB_FROG")       { sub = kOutFrog;         sn = sizeof kOutFrog         / sizeof kOutFrog[0];         }
            else if (key == "SUB_GIANT")     { sub = kOutGiant;        sn = sizeof kOutGiant         / sizeof kOutGiant[0];        }
            else if (key == "SUB_HUMANOID")   { sub = kOutHumanoid;     sn = sizeof kOutHumanoid      / sizeof kOutHumanoid[0];     }
            else if (key == "SUB_LYCANTHROPE"){ sub = kOutLycanthrope; sn = sizeof kOutLycanthrope  / sizeof kOutLycanthrope[0];  }
            else if (key == "SUB_MEN")       { sub = kOutMen;          sn = sizeof kOutMen          / sizeof kOutMen[0];          }
            else if (key == "SUB_SNAKE")      { sub = kOutSnake;        sn = sizeof kOutSnake        / sizeof kOutSnake[0];        }
            else if (key == "SUB_SPHINX")     { sub = kOutSphinx;       sn = sizeof kOutSphinx        / sizeof kOutSphinx[0];       }
            else if (key == "SUB_SPIDER")     { sub = kOutSpider;       sn = sizeof kOutSpider        / sizeof kOutSpider[0];       }
            else if (key == "SUB_UNDEAD")     { sub = kOutUndead;       sn = sizeof kOutUndead        / sizeof kOutUndead[0];       }
            if (sub) pushOutKeys(out, reg, sub, sn, terrain);
            continue;
        }
        if (reg.find(key)) pushUnique(out, key.c_str());
    }
}

namespace {

const OutdoorRow* outTable(OutdoorClime clime, size_t& n) {
    switch (clime) {
        case OC_ARCTIC:              n = sizeof kOutArctic              / sizeof kOutArctic[0];              return kOutArctic;
        case OC_SUB_ARCTIC:          n = sizeof kOutSubArctic          / sizeof kOutSubArctic[0];          return kOutSubArctic;
        case OC_TEMPERATE_WILD:      n = sizeof kOutTemperateWild      / sizeof kOutTemperateWild[0];      return kOutTemperateWild;
        case OC_TEMPERATE_INHABITED: n = sizeof kOutTemperateInhabited  / sizeof kOutTemperateInhabited[0]; return kOutTemperateInhabited;
        case OC_FAERIE:              n = sizeof kOutFaerie              / sizeof kOutFaerie[0];              return kOutFaerie;
        case OC_PLEISTOCENE:         n = sizeof kOutPleistocene         / sizeof kOutPleistocene[0];         return kOutPleistocene;
        case OC_DINOSAUR_AGE:        n = sizeof kOutDinosaurAge         / sizeof kOutDinosaurAge[0];         return kOutDinosaurAge;
        case OC_TROPICAL:            n = sizeof kOutTropical            / sizeof kOutTropical[0];           return kOutTropical;
    }
    n = 0; return nullptr;
}

} // namespace

DungeonEncounter rollOutdoorEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        OutdoorClime clime, OutdoorTerrain terrain) {
    DungeonEncounter e;

    size_t n = 0;
    const OutdoorRow* t = outTable(clime, n);
    if (!t) return e;
    int ti = (int)terrain;

    for (int attempt = 0; attempt < 24; ++attempt) {
        const OutdoorRow* row = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (t[i].lo[ti] >= 0 &&
                pctile >= t[i].lo[ti] && pctile <= t[i].hi[ti])
                { row = &t[i]; break; }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key;
        if (!resolveOutdoorKey(row, ti, pctile2, key)) return e;

        if (key == "SUB_CHARACTER") {
            // Men Subtable Character row — wilderness character
            // party, levels 7-10 (p.187 note)
            e.party = rollCharacterParty(dice, 8, 8);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            // numbers per MONSTER MANUAL (registry noAppearing;
            // 0/0 falls back to a single specimen)
            if (def->noAppearingMin > 0) {
                int lo = def->noAppearingMin;
                int hi = def->noAppearingMax < lo ? lo : def->noAppearingMax;
                e.count = (lo == hi)
                    ? lo
                    : lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
            } else {
                e.count = 1;
            }
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> outdoorEncounterKeys(
        const monsters::MonsterRegistry& reg,
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<std::string> out;
    size_t n = 0;
    const OutdoorRow* t = outTable(clime, n);
    if (t) pushOutKeys(out, reg, t, n, (int)terrain);
    return out;
}

// ----------------------------------------------------------------------------
// R64: the CITY/TOWN ENCOUNTER MATRIX — DMG Appendix C (Premium
// reprint p.190-192, OCR-verified against the uploaded DMG). One
// matrix, two percentile columns (daytime / nighttime; several
// rows are night-only, marked "-" in the book). Asterisked types
// (assassin, city guard, cleric, druid, fighter, illusionist,
// magic-user, ranger, thief) roll the p.191 race check —
// rollNpcRace (R62); unasterisked classed types are human (1e
// class restrictions: paladin, monk, rake, city watch, city
// official). Classed and service encounters resolve as
// character parties built to the p.191-192 explanations; the
// civilian fictions (beggar, drunk, goodwife, harlot, laborer,
// peddler, gentleman, noble, mercenary, merchant, pilgrim,
// press gang, ruffian, tradesman, bard) carry printed counts
// but no bestiary entry — their flavor subtables (harlot type
// p.192, drunk-of-what-type p.191, noble gender, ruffian 1-in-4
// half-orc/humanoid) are fiction the engine does not model,
// documented in the row comments. Numbers are the printed
// encounter numbers, not the registry's wilderness-scale
// noAppearing (bandit registry 20-200 vs. printed night 3-12;
// giant rat registry 5-50 vs. printed 2-8 day / 4-24 night).
// "Demon or Nycadaemon (60%/40%)" and "Devil or Mezzadaemon
// (50%/50%)" re-roll per the R52 mezzodaemon/nycadaemon
// precedent and the book's own advice ("they may be ignored
// entirely if desirable", p.191). The lich half of "Vampire or
// Lich (75%/25%)" and the ghast half of "Ghoul or Ghast
// (30%/70%)" take the ghost treatment — one specimen — where
// the book prints no separate number (lich) or the ghoul's
// 4-16 (ghast, same-as-ghoul per the ghost text). Bard (of
// "Monk or Bard 60%/40%") is a single fiction NPC: the 1e
// bard's dual fighter/thief abilities are unmodeled here.
// Book "Doppleganger" -> doppelganger (MM spelling,
// the bestiary key). OCR defects corrected: night 36 printed "Ghost or Ghoul
// (30%/70%)" is "Ghoul or Ghast" (37 is Ghost; the
// explanations print both ghoul 4-16 and ghast);
// "Wereat" -> Wererat, "Wereiger" -> Weretiger (night 91-93 /
// 94). Day bandits print no number ("a nondescript group being
// seen") — 3-12, the nighttime number, is used, documented.
// City magic (p.192): 1st-or-higher classed city NPCs roll
// the CHANCE PER LEVEL FOR MAGIC ITEM table per category;
// potions, scrolls, rings, wands and misc magic have no
// mechanical effect here (R55 precedent), protection devices
// roll the printed subtable. No appstate wiring — the game
// has no city/town play yet (R60/R63 precedent).

namespace {

struct CityRow {
    short loDay, hiDay;      // daytime percentile (-0 = no row)
    short loNight, hiNight;  // nighttime percentile
    const char* key;
};

// CITY/TOWN ENCOUNTER MATRIX (DMG p.191)
static const CityRow kCityMatrix[] = {
{1,1,1,3,"assassin"},
{2,2,4,5,"bandit"},
{3,12,6,8,"beggar"},
{13,13,9,10,"brigand"},
{14,18,11,11,"city_guard"},
{19,21,12,12,"city_official"},
{22,23,13,21,"city_watchman"},
{24,25,22,22,"cleric"},
{0,0,23,23,"demon_or_nycadaemon"},
{0,0,24,24,"devil_or_mezzadaemon"},
{0,0,25,25,"doppelganger"},
{26,26,26,26,"druid"},
{27,27,27,31,"drunk"},
{28,29,32,33,"fighter"},
{30,33,34,35,"gentleman"},
{0,0,36,36,"ghoul_or_ghast"},
{0,0,37,37,"ghost"},
{34,34,38,42,"giant_rat"},
{35,39,43,43,"goodwife"},
{40,41,44,50,"harlot"},
{42,42,51,51,"illusionist"},
{43,50,52,52,"laborer_or_peddler"},
{51,51,53,53,"magic_user"},
{52,55,54,58,"mercenary"},
{56,62,59,60,"merchant"},
{63,63,61,61,"monk_or_bard"},
{0,0,62,62,"night_hag"},
{64,65,63,64,"noble"},
{66,66,65,65,"paladin"},
{67,69,66,66,"pilgrim"},
{70,70,67,67,"press_gang"},
{71,72,68,71,"rake"},
{0,0,72,72,"rakshasa"},
{73,73,73,73,"ranger"},
{74,78,74,80,"ruffian"},
{0,0,81,81,"shadow"},
{0,0,82,82,"spectre"},
{79,82,83,88,"thief"},
{83,97,89,90,"tradesman"},
{98,98,91,93,"wererat"},
{99,99,94,94,"weretiger"},
{100,100,95,96,"werewolf"},
{0,0,97,97,"wight"},
{0,0,98,98,"will_o_wisp"},
{0,0,99,99,"wraith"},
{0,0,100,100,"vampire_or_lich"}
};

// printed encounter numbers for the non-party results
int cityCountFor(rules::Dice& dice, const std::string& key, bool night) {
    (void)night;
    if (key == "bandit" || key == "brigand")
        return 2 + (int)dice.roll(1, 10, 0);          // 3-12 night; day documented
    if (key == "beggar")
        return (int)dice.roll(1, 2, 0);               // 1, possibly 2
    if (key == "doppelganger")
        return 2 + (int)dice.roll(1, 4, 0);           // d4+2 = 3-6
    if (key == "giant_rat")
        return night
            ? 1 + (int)dice.roll(1, 24, 0)            // 4-24 night
            : (int)dice.roll(2, 4, 0);                // 2-8 day
    if (key == "ghoul" || key == "ghast")
        return 4 + (int)dice.roll(1, 13, 0);          // 4-16
    if (key == "drunk")
        return (int)dice.roll(1, 4, 0);               // 1-4 revelers/bums
    if (key == "gentleman")
        return (int)dice.roll(1, 5, 0);               // 1 + 0-4 company
    if (key == "laborer")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "peddler")
        return 1;
    if (key == "mercenary")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "merchant")
        return (int)dice.roll(1, 3, 0);               // 1-3 (night guards fiction)
    if (key == "bard")
        return 1;
    if (key == "night_hag")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "noble")
        return 1;
    if (key == "pilgrim")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "press_gang")
        return 1 + (int)dice.roll(1, 16, 0);          // 2-16
    if (key == "rakshasa")
        return (int)dice.roll(1, 3, 0);               // 1-3
    if (key == "ruffian")
        return 6 + (int)dice.roll(1, 6, 0);           // d6+6 = 7-12
    if (key == "shadow")
        return 2 + (int)dice.roll(1, 7, 0);           // 2-8
    if (key == "spectre")
        return (int)dice.roll(1, 3, 0);               // 1-3
    if (key == "tradesman")
        return (int)dice.roll(2, 4, 0);               // 2-8
    if (key == "wererat")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "weretiger")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "werewolf")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "wight")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "will_o_wisp")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "wraith")
        return (int)dice.roll(1, 4, 0);              // 1-4
    // ghost, ghoul's kin, vampire, lich, doppelganger's kin,
    // goodwife, harlot, paladin-less singles: one specimen
    return 1;
}

// p.192 protection device subtable (the mechanically usable
// outcomes; the amulet of life protection has no mechanical
// effect here — R55 precedent)
enum { PROT_RING1, PROT_RING2, PROT_RING3, PROT_AMULET,
       PROT_BRACERS6, PROT_BRACERS4, PROT_BRACERS2,
       PROT_DISPLACEMENT, PROT_CLOAK1, PROT_CLOAK2, PROT_CLOAK3 };

static int rollProtectionDevice(rules::Dice& dice) {
    int p = (int)dice.roll(1, 100, 0);
    if (p <= 25) return PROT_RING1;
    if (p <= 30) return PROT_RING2;
    if (p == 31) return PROT_RING3;
    if (p == 32) return PROT_AMULET;
    if (p <= 55) return PROT_BRACERS6;
    if (p <= 70) return PROT_BRACERS4;
    if (p <= 75) return PROT_BRACERS2;
    if (p <= 82) return PROT_DISPLACEMENT;
    if (p <= 95) return PROT_CLOAK1;
    if (p <= 99) return PROT_CLOAK2;
    return PROT_CLOAK3;
}

// "The power of the item must be commensurate with the level of
// the possessor" (p.192): +1 at 1st-5th, +2 at 6th-11th, +3 at
// 12th and above (documented approximation, R55's ladder spirit)
static int plusForLevel(int level) {
    if (level >= 12) return 3;
    if (level >= 6)  return 2;
    return 1;
}

} // namespace

// R64: p.192 CHANCE PER LEVEL FOR MAGIC ITEM — one percentile
// roll per category at (chance x level). Group 0: assassin,
// fighter, thief, etc.; group 1: cleric, druid; group 2:
// magic-user. The printed monk column has no engine class
// (monks resolve as fighters per R53) — documented. Potions,
// scrolls, rings, wands/staffs/rods and misc magic exist in
// the fiction but have no mechanical effect here (R55).
static void rollCityMagicItems(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // 0-level men: hp is all they need

    int group = (m.classIndex == rules::CLASS_CLERIC) ? 1
              : (m.classIndex == rules::CLASS_MAGIC_USER) ? 2 : 0;

    //                g0   g1   g2   (percent per level)
    const int sword   [3] = { 10,  0,  0 };
    const int miscWpn [3] = {  5, 10,  5 };
    const int armor   [3] = { 10, 10,  0 };
    const int protect [3] = {  2,  2, 10 };

    int lvl = m.level;
    if ((int)dice.roll(1, 100, 0) <= sword[group] * lvl)
        m.wpnPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= miscWpn[group] * lvl)
        m.rngPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= armor[group] * lvl) {
        m.armPlus = plusForLevel(lvl);
        // "Armor &/or Shield" — the shield is a coin-flip half
        // of the category (documented split)
        if ((int)dice.roll(1, 2, 0) == 2)
            m.shdPlus = plusForLevel(lvl);
    }
    if ((int)dice.roll(1, 100, 0) <= protect[group] * lvl) {
        switch (rollProtectionDevice(dice)) {
            case PROT_RING1: case PROT_CLOAK1: m.shdPlus += 1; break;
            case PROT_RING2: case PROT_CLOAK2: m.shdPlus += 2; break;
            case PROT_RING3: case PROT_CLOAK3: m.shdPlus += 3; break;
            // bracers replace armor: the AC-6/4/2 sets read as
            // +2/+4/+6 unarmored (documented approximation)
            case PROT_BRACERS6: m.armPlus = (m.armPlus > 2) ? m.armPlus : 2; break;
            case PROT_BRACERS4: m.armPlus = (m.armPlus > 4) ? m.armPlus : 4; break;
            case PROT_BRACERS2: m.armPlus = (m.armPlus > 6) ? m.armPlus : 6; break;
            // cloak of displacement: -2 AC in the MM
            case PROT_DISPLACEMENT: m.shdPlus += 2; break;
            case PROT_AMULET:
            default: break;   // fiction only
        }
    }
}

// R64: build a city party to the p.191-192 explanations.
// asterisk = rollNpcRace (R62); unasterisked classed types are
// human (1e class restrictions). Followers and leaders are
// henchmen; 0-level guardsmen are men-at-arms (R53 shapes).
static CharacterParty rollCityParty(rules::Dice& dice,
                                    const char* type, bool night) {
    CharacterParty p;
    const std::string t(type);

    auto add = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
        return m;
    };
    auto addHench = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.henchman = true;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
    };
    auto addMan = [&](int n) {
        for (int i = 0; i < n; ++i) {
            PartyMember m;
            m.manAtArms = true;               // 0-level men (R53)
            m.classIndex = rules::CLASS_FIGHTER;
            m.level = 0;
            m.race = RACE_HUMAN;
            p.members.push_back(m);
        }
    };

    if (t == "assassin") {
        // 1-3 assassins; the book prints no level here — the
        // 5th-8th ruffian bodyguard range, the only city
        // assassin range printed, is used (documented)
        int n = (int)dice.roll(1, 3, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_THIEF, 4 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "cleric") {
        // cleric 6th-11th (d6+5) + 0-5 lesser clerics (d4 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        int n = (int)dice.roll(1, 6, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
    } else if (t == "druid") {
        // druid 6th-11th; 50% 0-3 lesser druids (d4 level),
        // else 1-4 fighters (d6 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "fighter") {
        // fighter 6th-12th (2d4+4) + 0-3 henchmen (d4 level)
        add(rules::CLASS_FIGHTER,
            4 + (int)dice.roll(2, 4, 0), true);
        int n = (int)dice.roll(1, 4, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 4, 0), true);
    } else if (t == "illusionist") {
        // illusionist 7th-10th (d4+6); 50% 0-3 apprentices
        // (d4 level), else 1-3 fighter guards (d6 level)
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 4, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 3, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "magic_user") {
        // magic-user 7th-12th (d6+6) + 1-4 henchmen: 45%
        // apprentices (d6 level), 30% fighter guards (d4+3),
        // 25% a mixture "providing 2 or 4 henchmen" — the
        // count is forced to 2 or 4 and split evenly
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 6, 0), true);
        int roll = (int)dice.roll(1, 100, 0);
        if (roll <= 45) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 6, 0), true);
        } else if (roll <= 75) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         3 + (int)dice.roll(1, 4, 0), true);
        } else {
            int n = ((int)dice.roll(1, 2, 0) == 1) ? 2 : 4;
            for (int i = 0; i < n; ++i)
                addHench((i % 2 == 0) ? rules::CLASS_MAGIC_USER
                                      : rules::CLASS_FIGHTER,
                         (i % 2 == 0) ? (int)dice.roll(1, 6, 0)
                                      : 3 + (int)dice.roll(1, 4, 0),
                         true);
        }
    } else if (t == "monk") {
        // one monk, 7th-10th (d4+6); monks resolve as fighters
        // (R53 closest-approximation), human (no asterisk)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "paladin") {
        // one paladin, 6th-9th (d4+5); human (1e requirement)
        add(rules::CLASS_FIGHTER, 5 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "ranger") {
        // one ranger, 7th-10th (d4+6), race-checked (*)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "thief") {
        // thief 8th-11th (d4+7) + 0-2 apprentices (d4 level)
        add(rules::CLASS_THIEF, 7 + (int)dice.roll(1, 4, 0), true);
        int n = (int)dice.roll(1, 3, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_THIEF, (int)dice.roll(1, 4, 0), true);
    } else if (t == "rake") {
        // 2-5 young gentlemen fighters, 5th-10th (d6+4)
        int n = 1 + (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_FIGHTER,
                4 + (int)dice.roll(1, 6, 0), false);
    } else if (t == "city_guard") {
        // 2-16 0-level guardsmen; 1 leader (2 if more than 8,
        // 3 if more than 12) of 2nd-5th (d4+1); plus an
        // indentured magic-user of 1st-4th — all race-checked
        // (the matrix asterisks the City guard)
        int n = 1 + (int)dice.roll(1, 16, 0);
        addMan(n);
        int leaders = (n > 12) ? 3 : (n > 8) ? 2 : 1;
        for (int i = 0; i < leaders; ++i)
            addHench(rules::CLASS_FIGHTER,
                     1 + (int)dice.roll(1, 4, 0), true);
        addHench(rules::CLASS_MAGIC_USER,
                 (int)dice.roll(1, 4, 0), true);
    } else if (t == "city_watchman") {
        // day: 5 men + 1st-3rd sergeant; night: double numbers
        // plus a 4th/5th-level lieutenant; always accompanied
        // by an indentured cleric of 2nd-5th (d4+1)
        addMan(night ? 10 : 5);
        addHench(rules::CLASS_FIGHTER,
                 (int)dice.roll(1, 3, 0), false);   // sergeant
        if (night)
            addHench(rules::CLASS_FIGHTER,
                     3 + (int)dice.roll(1, 2, 0), false);  // lieutenant
        addHench(rules::CLASS_CLERIC,
                 1 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "city_official") {
        // a minor bureaucrat (10% a major official with 2-8
        // guards); always 1-4 personal fighters (d4 level).
        // The official is fiction — a man-at-arms shape —
        // the guards are classed. No asterisk: human.
        addMan(1);
        bool major = (int)dice.roll(1, 10, 0) == 10;
        if (major)
            addMan(1 + (int)dice.roll(1, 8, 0));
        int n = (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER,
                     (int)dice.roll(1, 4, 0), false);
    }
    (void)add;
    return p;
}

DungeonEncounter rollCityEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2, CityTime time) {
    DungeonEncounter e;

    for (int attempt = 0; attempt < 24; ++attempt) {
        const CityRow* row = nullptr;
        for (size_t i = 0;
             i < sizeof kCityMatrix / sizeof kCityMatrix[0]; ++i) {
            short lo, hi;
            if (time == CITY_DAY) { lo = kCityMatrix[i].loDay;  hi = kCityMatrix[i].hiDay;  }
            else                  { lo = kCityMatrix[i].loNight; hi = kCityMatrix[i].hiNight; }
            if (lo > 0 && pctile >= lo && pctile <= hi)
                { row = &kCityMatrix[i]; break; }
        }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key = row->key;

        // the book's own advice: "they may be ignored entirely
        // if desirable ... treat these encounters as highly
        // special" (p.191); nycadaemon/mezzadaemon are
        // unimplemented (R52) — ignore & re-roll
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon") {
            pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
            pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
            continue;
        }

        // printed 50/50 - 75/25 splits (second percentile)
        if (key == "laborer_or_peddler")
            key = (pctile2 <= 50) ? "laborer" : "peddler";
        else if (key == "monk_or_bard")
            key = (pctile2 <= 60) ? "monk" : "bard";
        else if (key == "ghoul_or_ghast")
            key = (pctile2 <= 30) ? "ghoul" : "ghast";
        else if (key == "vampire_or_lich")
            key = (pctile2 <= 75) ? "vampire" : "lich";
        else if (key == "brigand")
            key = "bandit";   // "the same as bandit encounters"

        // classed / service encounters: character parties
        if (key == "assassin" || key == "cleric" || key == "druid" ||
            key == "fighter" || key == "illusionist" ||
            key == "magic_user" || key == "monk" || key == "paladin" ||
            key == "ranger" || key == "thief" || key == "rake" ||
            key == "city_guard" || key == "city_official" ||
            key == "city_watchman") {
            e.party = rollCityParty(dice, key.c_str(),
                                    time == CITY_NIGHT);
            e.isParty = true;
            e.key = key;
            e.count = e.party.size();
            return e;
        }

        e.key = key;
        e.count = cityCountFor(dice, key,
                               time == CITY_NIGHT);
        (void)reg;   // fiction keys may not be registry keys;
                     // the regtest companion lists both
        return e;
    }
    return e;
}

// Every result key the matrix can produce — registry keys for
// the monsters, fiction keys for the civilians, party-type
// keys for the classed and service encounters (resolved as
// character parties). The regtest companion of
// rollCityEncounter.
std::vector<std::string> cityEncounterKeys(
        const monsters::MonsterRegistry& reg) {
    std::vector<std::string> out;
    for (size_t i = 0;
         i < sizeof kCityMatrix / sizeof kCityMatrix[0]; ++i) {
        std::string key = kCityMatrix[i].key;
        if (key == "laborer_or_peddler") {
            pushUnique(out, "laborer");
            pushUnique(out, "peddler");
            continue;
        }
        if (key == "monk_or_bard") {
            pushUnique(out, "monk");
            pushUnique(out, "bard");
            continue;
        }
        if (key == "ghoul_or_ghast") {
            pushUnique(out, "ghoul");
            pushUnique(out, "ghast");
            continue;
        }
        if (key == "vampire_or_lich") {
            pushUnique(out, "vampire");
            pushUnique(out, "lich");
            continue;
        }
        if (key == "brigand") {
            pushUnique(out, "bandit");
            continue;
        }
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon")
            continue;   // ignored & re-rolled (documented)
        pushUnique(out, key.c_str());
    }
    (void)reg;
    return out;
}


} // namespace dm
