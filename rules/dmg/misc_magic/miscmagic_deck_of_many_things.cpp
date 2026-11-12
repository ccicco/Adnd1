// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_deck_of_many_things.h"

int Miscmagic_deck_of_many_things::mmpDeckPlaqueMaterialCount() {
    // plaques of ivory or vellum
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckMinDraws() {
    // announce only 1 draw, or
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckMaxDraws() {
    // opt for 2, 3, or even 4
    return 4;
}

int Miscmagic_deck_of_many_things::mmpDeckJesterBonusDraws() {
    // the jester: 2 additional cards
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckBasePlaqueCount() {
    // the 13-plaque pack
    return 13;
}

int Miscmagic_deck_of_many_things::mmpDeckFullPlaqueCount() {
    // the 22-plaque pack
    return 22;
}

int Miscmagic_deck_of_many_things::mmpDeckBaseChancePct() {
    // 13 plaques at 75 percent
    return 75;
}

int Miscmagic_deck_of_many_things::mmpDeckFullChancePct() {
    // 22 plaques at 25 percent
    return 25;
}

int Miscmagic_deck_of_many_things::mmpDeckAsteriskPlaqueCount() {
    // the 22-pack extras, asterisk-marked
    return 9;
}

int Miscmagic_deck_of_many_things::mmpDeckDiscardPlaqueCount() {
    // jester and fool are discarded
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckBoldFaceStopCount() {
    // The Void and Donjon stop the deck
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckTablePlaqueCount() {
    // the printed plaque table rows
    return 22;
}

int Miscmagic_deck_of_many_things::mmpDeckSunXp() {
    // the Sun: beneficial item and
    return 50000;
}

int Miscmagic_deck_of_many_things::mmpDeckMoonWishesMin() {
    // Moon grants 1-4 wishes
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckMoonWishesMax() {
    // Moon grants 1-4 wishes
    return 4;
}

int Miscmagic_deck_of_many_things::mmpDeckMoonSpellLevel() {
    // same as the ninth level spell
    return 9;
}

int Miscmagic_deck_of_many_things::mmpDeckStarPoints() {
    // Star: 2 points on the major ability
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckStarMaxScore() {
    // if the 2 points would place the score at
    return 19;
}

int Miscmagic_deck_of_many_things::mmpDeckStarFallbackOrderCount() {
    // con, cha, wis, dex, int, str
    return 6;
}

int Miscmagic_deck_of_many_things::mmpDeckCometMidpointProgress() {
    // success: mid-point of the next level
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckThroneCharisma() {
    // Throne: charisma of
    return 18;
}

int Miscmagic_deck_of_many_things::mmpDeckThroneReactionBonusPct() {
    // already-18: still +25 percent reactions
    return 25;
}

int Miscmagic_deck_of_many_things::mmpDeckKeyMapBonusPct() {
    // Key: treasure map at +20 percent
    return 20;
}

int Miscmagic_deck_of_many_things::mmpDeckKeyWeaponCount() {
    // Key: a treasure map plus
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckKnightLevel() {
    // Knight: a 4th level fighter
    return 4;
}

int Miscmagic_deck_of_many_things::mmpDeckKnightBonusPerDie() {
    // the hero: +1 per die
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckKnightAbilityMax() {
    // the hero ability roll caps at
    return 18;
}

int Miscmagic_deck_of_many_things::mmpDeckGemJewelryCount() {
    // Gem: your choice of 20 jewelry
    return 20;
}

int Miscmagic_deck_of_many_things::mmpDeckGemGemCount() {
    // Gem: or 50 gems
    return 50;
}

int Miscmagic_deck_of_many_things::mmpDeckGemGemBaseGp() {
    // the gems: base value
    return 1000;
}

int Miscmagic_deck_of_many_things::mmpDeckGemXpLevelCap() {
    // never more than 1 level rise
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckEuryaleSavePenalty() {
    // Euryale: minus 3 on petrification saves
    return 3;
}

int Miscmagic_deck_of_many_things::mmpDeckRogueHenchmenAlienated() {
    // Rogue: 1 henchman alienated
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckJesterXp() {
    // Jester: gain 10,000 xp instead
    return 10000;
}

int Miscmagic_deck_of_many_things::mmpDeckJesterExtraDraws() {
    // Jester: or 2 more draws
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckFoolXp() {
    // Fool: lose 10,000 xp
    return 10000;
}

int Miscmagic_deck_of_many_things::mmpDeckIdiotIntLossMin() {
    // Idiot: lose 1-4 int
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckIdiotIntLossMax() {
    // Idiot: lose 1-4 int
    return 4;
}

int Miscmagic_deck_of_many_things::mmpDeckSkullDeathAc() {
    // the minor Death AC (negative)
    return -4;
}

int Miscmagic_deck_of_many_things::mmpDeckSkullDeathHp() {
    // the minor Death hit points
    return 33;
}

int Miscmagic_deck_of_many_things::mmpDeckSkullScytheDmgMin() {
    // the scythe: 2-16 hit points
    return 2;
}

int Miscmagic_deck_of_many_things::mmpDeckSkullScytheDmgMax() {
    // the scythe: 2-16 hit points
    return 16;
}

int Miscmagic_deck_of_many_things::mmpDeckSkullUndeadForSpells() {
    // treat the Death as undead
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckFatesPartyEndures() {
    // the party must still endure it
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckDonjonGearStripped() {
    // Donjon: all gear and spells stripped
    return 1;
}

int Miscmagic_deck_of_many_things::mmpDeckPlaqueAsterisk(int i) {
    // the 22-pack extras by row; i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 1, 1, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_deck_of_many_things::mmpDeckPlaqueBoldFace(int i) {
    // The Void (8) and Donjon (21); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

int Miscmagic_deck_of_many_things::mmpDeckPlaqueDiscarded(int i) {
    // Jester (16) and Fool (17); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    };
    return t[i];
}
