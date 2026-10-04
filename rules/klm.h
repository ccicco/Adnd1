// ====================================================================
// Adnd1 - rules/klm.h
// R171: Appendices K, L and M (DMG pp.221-224) -
// the magical substance word lists, the conjured
// animals table and the summoned monsters tables.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls and selects; support tables for
// the conjure and summon spell effects).
//
// JUDGMENTs: the K lists were cell-verified against
// the 1eonline.info compilation (the repo-trusted
// source, the R146 precedent); the Appendix L
// 5-and-up band columns are OCR debt (open finding) -
// the printed roster, the whale cap and the water
// note are pinned; the Appendix M water tables for
// summonings II-VI come from the trusted compilation,
// which agrees with the upload on the I and VII water
// tables the upload shows.
// ====================================================================

#pragma once

namespace rules {

// ----------------------------------------------------------------------------
// Appendix K: describing magical substances (p.221)
// ----------------------------------------------------------------------------

inline int klmAppearanceCount() { return 10; }

inline const char* klmAppearance(int i) {
    static const char* const k[10] = {
        "bubbling",
        "cloudy",
        "effervescent",
        "fuming",
        "oily",
        "smoky",
        "syrupy",
        "vaporous",
        "viscous",
        "watery"
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

inline int klmTransparencyCount() { return 10; }

// The printed text with its parenthetical.
inline const char* klmTransparency(int i) {
    static const char* const k[10] = {
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
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

// True where the printed parenthetical asks the
// reader to determine transparency or colors.
inline bool klmTransparencyNeedsDetermination(int i) {
    static const bool k[10] = {
        false, false, false, true, false, true,
        false, true, false, true
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

// The color list: 74 words in 11 printed groups.
inline int klmColorGroupCount() { return 11; }

inline const char* klmColorGroupName(int g) {
    static const char* const k[11] = {
        "METALLIC", "WHITE", "GRAY", "BROWN",
        "BLACK", "VIOLET", "YELLOW", "RED",
        "GREEN", "BLUE", "ORANGE"
    };
    if (g < 0) g = 0;
    if (g > 10) g = 10;
    return k[g];
}

inline int klmColorGroupSize(int g) {
    static const int k[11] = {
        6, 4, 3, 6, 5, 10, 10, 16, 3, 6, 5
    };
    if (g < 0) g = 0;
    if (g > 10) g = 10;
    return k[g];
}

// The word at index j within group g.
inline const char* klmColorWord(int g, int j) {
    static const char* const k[74] = {
        // METALLIC
        "brassy", "bronze", "coppery", "gold",
        "silvery", "steely",
        // WHITE
        "bone", "colorless", "ivory", "pearl",
        // GRAY
        "dove", "dun", "neutral",
        // BROWN
        "chocolate", "ecru", "fawn", "mahogany",
        "tan", "terra cotta",
        // BLACK
        "ebony", "inky", "pitchy", "sable",
        "sooty",
        // VIOLET
        "fuchsia", "heliotrope", "lake", "lavender",
        "lilac", "magenta", "mauve", "plum", "puce",
        "purple",
        // YELLOW
        "amber", "buff", "citrine", "cream",
        "fallow", "flaxen", "ochre", "peach",
        "saffron", "straw",
        // RED
        "carmine", "cerise", "cherry", "cinnabar",
        "coral", "crimson", "madder", "maroon",
        "pink", "rose", "ruby", "russet", "rust",
        "sanguine", "scarlet", "vermillion",
        // GREEN
        "aquamarine", "emerald", "olive",
        // BLUE
        "azure", "cerulean", "indigo", "sapphire",
        "turquoise", "ultramarine",
        // ORANGE
        "apricot", "flame", "golden", "salmon",
        "tawny"
    };
    static const int kOff[11] = {
        0, 6, 10, 13, 19, 24, 34, 44, 60, 63, 69
    };
    if (g < 0) g = 0;
    if (g > 10) g = 10;
    if (j < 0) j = 0;
    if (j >= klmColorGroupSize(g))
        j = klmColorGroupSize(g) - 1;
    return k[kOff[g] + j];
}

inline int klmTasteCount() { return 28; }

inline const char* klmTaste(int i) {
    static const char* const k[28] = {
        "acidic",
        "bilious",
        "bitter",
        "burning/biting",
        "buttery",
        "dusty",
        "earthy",
        "fiery",
        "fishy",
        "greasy",
        "herbal",
        "honeyed",
        "lemony",
        "meaty",
        "metallic",
        "milky",
        "musty",
        "oniony",
        "peppery",
        "perfumy",
        "salty",
        "soothing/sugary",
        "sour",
        "spicy",
        "sweet",
        "tart",
        "vinegary",
        "watery"
    };
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    return k[i];
}

// In combination with Appendix I dungeon dressing
// or by itself.
inline bool klmUsedWithDungeonDressing() {
    return true;
}

// ----------------------------------------------------------------------------
// Appendix L: conjured animals (pp.222-223)
// ----------------------------------------------------------------------------

struct ConjuredAnimalRow {
    int lo;
    int hi;
    const char* name;
    int costQ;  // the hit dice cost in quarters
};

// The prose: fractional hit point costs must be
// charged off against the total conjurable; where
// several possibilities exist a number for random
// selection has been assigned, for the caster cannot
// specify what sort of animal will come.
inline bool klmConjFractionalCostCharged() {
    return true;
}
inline bool klmConjRandomSelectionWhereSeveral() {
    return true;
}
inline bool klmConjCasterCannotSpecify() {
    return true;
}

inline int klmConjCategoryCount() { return 4; }

inline int klmConjRowCount(int c) {
    static const int k[4] = { 5, 4, 15, 13 };
    if (c < 0) c = 0;
    if (c > 3) c = 3;
    return k[c];
}

inline const ConjuredAnimalRow& klmConjRow(int c, int r) {
    static const ConjuredAnimalRow k[37] = {
        // category 1
        { 1, 15, "baboon", 5 },
        { 16, 45, "dog, wild", 5 },
        { 46, 55, "flightless bird", 2 },
        { 56, 65, "jackal", 2 },
        { 66, 100, "rat, giant", 2 },
        // category 2
        { 1, 25, "badger", 6 },
        { 26, 35, "flightless bird", 8 },
        { 36, 60, "herd animal", 8 },
        { 61, 100, "horse, wild", 8 },
        // category 3
        { 1, 5, "axe beak", 12 },
        { 6, 10, "badger, giant", 12 },
        { 11, 15, "boar/warthog", 12 },
        { 16, 20, "camel", 12 },
        { 21, 30, "cattle, wild", 10 },
        { 31, 40, "dog, war", 10 },
        { 41, 45, "flightless bird", 12 },
        { 46, 55, "goat, giant", 13 },
        { 56, 65, "hyena", 12 },
        { 66, 75, "lion, mountain", 13 },
        { 76, 80, "lynx, giant", 10 },
        { 81, 85, "mule", 12 },
        { 86, 90, "stag", 12 },
        { 91, 95, "wolf", 10 },
        { 96, 100, "wolverine", 12 },
        // category 4
        { 1, 5, "ape", 17 },
        { 6, 15, "bear, black", 15 },
        { 16, 20, "beaver, giant", 16 },
        { 21, 30, "boar, wild", 15 },
        { 31, 40, "bull", 16 },
        { 41, 45, "eagle, giant", 16 },
        { 46, 50, "Irish deer", 16 },
        { 51, 55, "jaguar", 17 },
        { 56, 60, "leopard", 14 },
        { 61, 65, "owl, giant", 16 },
        { 66, 75, "ram, giant", 16 },
        { 76, 85, "weasel, giant", 15 },
        { 86, 100, "wolf, dire", 15 }
    };
    static const int kOff[4] = { 0, 5, 9, 24 };
    if (c < 0) c = 0;
    if (c > 3) c = 3;
    if (r < 0) r = 0;
    if (r >= klmConjRowCount(c)) r = klmConjRowCount(c) - 1;
    return k[kOff[c] + r];
}

// The 5-and-up roster: the printed animal names.
// The band columns of this section are OCR debt
// (see the gap report open finding).
inline int klmConjHigherRosterCount() { return 20; }

inline const char* klmConjHigherRosterName(int i) {
    static const char* const k[20] = {
        "ape, carnivorous",
        "baluchitherium",
        "bear, brown",
        "elephant",
        "elephant (loxodont)",
        "hippopotamus",
        "hyena, giant",
        "lion, spotted",
        "mammoth",
        "mastodon",
        "otter, giant",
        "porcupine, giant",
        "rhinoceros",
        "rhinoceros, wooly",
        "stag, giant",
        "tiger",
        "tiger, sabre-tooth",
        "titanothere",
        "whale (small)",
        "wolverine, giant"
    };
    if (i < 0) i = 0;
    if (i > 19) i = 19;
    return k[i];
}

// Whales only, to a maximum of 36 hit dice cost.
inline int klmConjWhaleMaxHitDiceCost() { return 36; }

// If in or on water, only the appropriate sorts
// of animals can be called, i.e. swimmers and
// flying ones, where applicable.
inline bool klmConjWaterSwimmersAndFlyersOnly() {
    return true;
}

// ----------------------------------------------------------------------------
// Appendix M: summoned monsters (pp.223-224)
// ----------------------------------------------------------------------------

struct SummonedMonsterRow {
    int lo;
    int hi;
    const char* name;
    const char* evilAlt;  // null: no parenthesis
};

// If the summoner is evil, the monster in
// parentheses may be used; and it is always
// within the DM purview to select the monster
// and appoint the numbers.
inline bool klmSummonEvilUsesParenthesis() {
    return true;
}
inline bool klmSummonDMMaySelectAndAppoint() {
    return true;
}

inline int klmSummonLandTableCount() { return 7; }

inline int klmSummonLandRowCount(int t) {
    static const int k[7] = { 6, 6, 12, 12, 12, 16, 34 };
    if (t < 0) t = 0;
    if (t > 6) t = 6;
    return k[t];
}

inline const SummonedMonsterRow& klmSummonLandRow(
        int t, int r) {
    static const SummonedMonsterRow k[98] = {
        // Monster Summoning I
        { 1, 10, "demon, manes", 0 },
        { 11, 25, "goblin", "dwarf" },
        { 26, 40, "hobgoblin", "elf" },
        { 41, 55, "kobold", "halfling" },
        { 56, 70, "orc", "gnome" },
        { 71, 100, "rat, giant", 0 },
        // Monster Summoning II
        { 1, 15, "centipede, giant", 0 },
        { 16, 25, "devil, lemure", 0 },
        { 26, 45, "gnoll", 0 },
        { 46, 60, "stirge", 0 },
        { 61, 75, "toad, giant", 0 },
        { 76, 100, "troglodyte", 0 },
        // Monster Summoning III
        { 1, 7, "beetle, boring", 0 },
        { 8, 17, "bugbear", 0 },
        { 18, 25, "gelatinous cube", 0 },
        { 26, 32, "ghoul", 0 },
        { 33, 40, "lizard, giant", 0 },
        { 41, 47, "lycanthrope, wererat", 0 },
        { 48, 57, "ochre jelly", 0 },
        { 58, 67, "ogre", 0 },
        { 68, 75, "spider, huge", 0 },
        { 76, 85, "spider, large", 0 },
        { 86, 95, "tick, giant", 0 },
        { 96, 100, "weasel, giant", 0 },
        // Monster Summoning IV
        { 1, 7, "ape, carnivorous", 0 },
        { 8, 15, "gargoyle", "blink dog" },
        { 16, 25, "ghast", 0 },
        { 26, 35, "gray ooze", 0 },
        { 36, 42, "hell hound", 0 },
        { 43, 50, "hydra, 5 heads", 0 },
        { 51, 58, "lycanthrope, werewolf", 0 },
        { 59, 67, "owlbear", 0 },
        { 68, 76, "shadow", 0 },
        { 77, 86, "snake, giant, constrictor", 0 },
        { 87, 93, "toad, ice", 0 },
        { 94, 100, "toad, poisonous", 0 },
        // Monster Summoning V
        { 1, 7, "cockatrice", 0 },
        { 8, 17, "displacer beast", 0 },
        { 18, 26, "doppleganger", 0 },
        { 27, 36, "hydra, 7 heads", 0 },
        { 37, 45, "leucrotta", 0 },
        { 46, 55, "lizard, subterranean", 0 },
        { 56, 63, "lycanthrope, wereboar", 0 },
        { 64, 72, "minotaur", 0 },
        { 73, 78, "snake, giant, amphisbaena", 0 },
        { 79, 85, "snake, giant, poisonous", 0 },
        { 86, 90, "snake, giant, spitting", 0 },
        { 91, 100, "spider, giant", 0 },
        // Monster Summoning VI
        { 1, 6, "carrion crawler", 0 },
        { 7, 12, "devil, erinyes", 0 },
        { 13, 19, "hydra, 8 heads", 0 },
        { 20, 26, "jackalwere", "lammasu" },
        { 27, 31, "lycanthrope, weretiger", "werebear" },
        { 32, 38, "manticore", 0 },
        { 39, 43, "ogre magi", 0 },
        { 44, 51, "otyugh", 0 },
        { 52, 56, "rakshasa", 0 },
        { 57, 63, "salamander", 0 },
        { 64, 68, "spider, phase", 0 },
        { 69, 78, "troll", 0 },
        { 79, 84, "wight", 0 },
        { 85, 88, "wind walker", 0 },
        { 89, 92, "wraith", 0 },
        { 93, 100, "wyvern", 0 },
        // Monster Summoning VII
        { 1, 3, "chimera", "couatl" },
        { 4, 6, "demon, succubus", 0 },
        { 7, 9, "demon, type I", 0 },
        { 10, 12, "demon, type II", 0 },
        { 13, 15, "demon, type III", 0 },
        { 16, 18, "devil, barbed", 0 },
        { 19, 21, "devil, bone", 0 },
        { 22, 23, "devil, horned", 0 },
        { 24, 26, "ettin", 0 },
        { 27, 29, "giant, fire", 0 },
        { 30, 32, "giant, frost", 0 },
        { 33, 35, "giant, hill", 0 },
        { 36, 38, "giant, stone", 0 },
        { 39, 41, "gorgon", 0 },
        { 42, 43, "groaning spirit", 0 },
        { 44, 46, "hydra, 10 heads", 0 },
        { 47, 49, "hydra, pyro-, 8 heads", 0 },
        { 50, 52, "intellect devourer", 0 },
        { 53, 55, "invisible stalker", 0 },
        { 56, 58, "lamia", 0 },
        { 59, 61, "lizard, fire", 0 },
        { 62, 64, "mind flayer", 0 },
        { 65, 67, "mummy", 0 },
        { 68, 70, "naga, spirit", 0 },
        { 71, 73, "neo-otyugh", 0 },
        { 74, 76, "night hag", 0 },
        { 77, 79, "roper", "shedu" },
        { 80, 82, "shambling mound", 0 },
        { 83, 85, "slug, giant", 0 },
        { 86, 88, "spectre", 0 },
        { 89, 91, "sphinx, hieraco- (andro-)", 0 },
        { 92, 94, "umber hulk", 0 },
        { 95, 97, "will-o-wisp", 0 },
        { 98, 100, "xorn", 0 }
    };
    static const int kOff[7] = {
        0, 6, 12, 24, 36, 48, 64
    };
    if (t < 0) t = 0;
    if (t > 6) t = 6;
    if (r < 0) r = 0;
    if (r >= klmSummonLandRowCount(t))
        r = klmSummonLandRowCount(t) - 1;
    return k[kOff[t] + r];
}

// The water tables: fresh and salt for each
// summoning (VI is fresh or salt, one table).
inline int klmSummonWaterTableCount() { return 13; }

inline const char* klmSummonWaterTableName(int t) {
    static const char* const k[13] = {
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
    if (t < 0) t = 0;
    if (t > 12) t = 12;
    return k[t];
}

inline int klmSummonWaterRowCount(int t) {
    static const int k[13] = {
        2, 2, 1, 2, 2, 2, 4, 3, 2, 4, 2, 2, 3
    };
    if (t < 0) t = 0;
    if (t > 12) t = 12;
    return k[t];
}

inline const SummonedMonsterRow& klmSummonWaterRow(
        int t, int r) {
    static const SummonedMonsterRow k[31] = {
        // I, fresh
        { 1, 67, "koalinth", "hobgoblin" },
        { 68, 100, "nixie", 0 },
        // I, salt
        { 1, 50, "koalinth", "hobgoblin" },
        { 51, 100, "merman", 0 },
        // II, fresh
        { 1, 100, "lizard man", 0 },
        // II, salt
        { 1, 33, "ixitxachitl", 0 },
        { 34, 100, "locathah", 0 },
        // III, fresh
        { 1, 33, "crab, giant", 0 },
        { 34, 100, "lacedon", "ghoul" },
        // III, salt
        { 1, 50, "lacedon", "ghoul" },
        { 51, 100, "sahuagin", 0 },
        // IV, fresh
        { 1, 33, "beetle, water, giant", 0 },
        { 34, 50, "crayfish, giant", 0 },
        { 51, 67, "kopoacinth", "gargoyle" },
        { 68, 100, "spider, water, giant", 0 },
        // IV, salt
        { 1, 40, "kopoacinth", "gargoyle" },
        { 41, 80, "lobster (crayfish), giant", 0 },
        { 81, 100, "triton", 0 },
        // V, fresh
        { 1, 80, "crocodile, giant", 0 },
        { 81, 100, "water weird", 0 },
        // V, salt
        { 1, 50, "crocodile, giant", 0 },
        { 51, 70, "sea hag", 0 },
        { 71, 90, "sea lion", 0 },
        { 91, 100, "water weird", 0 },
        // VI, fresh or salt
        { 1, 33, "octopus, giant", 0 },
        { 34, 100, "snake, sea, giant", 0 },
        // VII, fresh
        { 1, 20, "morkoth", 0 },
        { 21, 100, "naga, water", 0 },
        // VII, salt
        { 1, 15, "morkoth", 0 },
        { 16, 70, "ray, manta", 0 },
        { 71, 100, "squid, giant", 0 }
    };
    static const int kOff[13] = {
        0, 2, 4, 5, 7, 9, 11, 15, 18, 20, 24, 26, 28
    };
    if (t < 0) t = 0;
    if (t > 12) t = 12;
    if (r < 0) r = 0;
    if (r >= klmSummonWaterRowCount(t))
        r = klmSummonWaterRowCount(t) - 1;
    return k[kOff[t] + r];
}

} // namespace rules
