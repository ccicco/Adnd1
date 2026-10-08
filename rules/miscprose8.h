// ====================================================================
// Adnd1 - rules/miscprose8.h
// R264: the III.E misc magic explanation prose part 8
// (DMG p.133-134) - Deck of Many Things, part2
// lines 324-400 (global = 11065 + part2 line). ONE
// page header strips (360, the TREASURE page);
// ZERO mid-sentence seams (a first). The 22-plaque
// table pins: 9 asterisk plaques, 2 bold-face stop
// plaques (The Void, Donjon), 2 discarded plaques
// (Jester, Fool). 48 accessors: 45 scalars + 3
// array walkers, no name collisions with
// miscprose1.h through miscprose7.h. The slice
// pins kMisc2 row 18 (Deck of Many Things, 73-76).
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpDeckPlaqueMaterialCount() {
    // plaques of ivory or vellum
    return 2;
}

inline int mmpDeckMinDraws() {
    // announce only 1 draw, or
    return 1;
}

inline int mmpDeckMaxDraws() {
    // opt for 2, 3, or even 4
    return 4;
}

inline int mmpDeckJesterBonusDraws() {
    // the jester: 2 additional cards
    return 2;
}

inline int mmpDeckBasePlaqueCount() {
    // the 13-plaque pack
    return 13;
}

inline int mmpDeckFullPlaqueCount() {
    // the 22-plaque pack
    return 22;
}

inline int mmpDeckBaseChancePct() {
    // 13 plaques at 75 percent
    return 75;
}

inline int mmpDeckFullChancePct() {
    // 22 plaques at 25 percent
    return 25;
}

inline int mmpDeckAsteriskPlaqueCount() {
    // the 22-pack extras, asterisk-marked
    return 9;
}

inline int mmpDeckDiscardPlaqueCount() {
    // jester and fool are discarded
    return 2;
}

inline int mmpDeckBoldFaceStopCount() {
    // The Void and Donjon stop the deck
    return 2;
}

inline int mmpDeckTablePlaqueCount() {
    // the printed plaque table rows
    return 22;
}

inline int mmpDeckSunXp() {
    // the Sun: beneficial item and
    return 50000;
}

inline int mmpDeckMoonWishesMin() {
    // Moon grants 1-4 wishes
    return 1;
}

inline int mmpDeckMoonWishesMax() {
    // Moon grants 1-4 wishes
    return 4;
}

inline int mmpDeckMoonSpellLevel() {
    // same as the ninth level spell
    return 9;
}

inline int mmpDeckStarPoints() {
    // Star: 2 points on the major ability
    return 2;
}

inline int mmpDeckStarMaxScore() {
    // if the 2 points would place the score at
    return 19;
}

inline int mmpDeckStarFallbackOrderCount() {
    // con, cha, wis, dex, int, str
    return 6;
}

inline int mmpDeckCometMidpointProgress() {
    // success: mid-point of the next level
    return 1;
}

inline int mmpDeckThroneCharisma() {
    // Throne: charisma of
    return 18;
}

inline int mmpDeckThroneReactionBonusPct() {
    // already-18: still +25 percent reactions
    return 25;
}

inline int mmpDeckKeyMapBonusPct() {
    // Key: treasure map at +20 percent
    return 20;
}

inline int mmpDeckKeyWeaponCount() {
    // Key: a treasure map plus
    return 1;
}

inline int mmpDeckKnightLevel() {
    // Knight: a 4th level fighter
    return 4;
}

inline int mmpDeckKnightBonusPerDie() {
    // the hero: +1 per die
    return 1;
}

inline int mmpDeckKnightAbilityMax() {
    // the hero ability roll caps at
    return 18;
}

inline int mmpDeckGemJewelryCount() {
    // Gem: your choice of 20 jewelry
    return 20;
}

inline int mmpDeckGemGemCount() {
    // Gem: or 50 gems
    return 50;
}

inline int mmpDeckGemGemBaseGp() {
    // the gems: base value
    return 1000;
}

inline int mmpDeckGemXpLevelCap() {
    // never more than 1 level rise
    return 1;
}

inline int mmpDeckEuryaleSavePenalty() {
    // Euryale: minus 3 on petrification saves
    return 3;
}

inline int mmpDeckRogueHenchmenAlienated() {
    // Rogue: 1 henchman alienated
    return 1;
}

inline int mmpDeckJesterXp() {
    // Jester: gain 10,000 xp instead
    return 10000;
}

inline int mmpDeckJesterExtraDraws() {
    // Jester: or 2 more draws
    return 2;
}

inline int mmpDeckFoolXp() {
    // Fool: lose 10,000 xp
    return 10000;
}

inline int mmpDeckIdiotIntLossMin() {
    // Idiot: lose 1-4 int
    return 1;
}

inline int mmpDeckIdiotIntLossMax() {
    // Idiot: lose 1-4 int
    return 4;
}

inline int mmpDeckSkullDeathAc() {
    // the minor Death AC (negative)
    return -4;
}

inline int mmpDeckSkullDeathHp() {
    // the minor Death hit points
    return 33;
}

inline int mmpDeckSkullScytheDmgMin() {
    // the scythe: 2-16 hit points
    return 2;
}

inline int mmpDeckSkullScytheDmgMax() {
    // the scythe: 2-16 hit points
    return 16;
}

inline int mmpDeckSkullUndeadForSpells() {
    // treat the Death as undead
    return 1;
}

inline int mmpDeckFatesPartyEndures() {
    // the party must still endure it
    return 1;
}

inline int mmpDeckDonjonGearStripped() {
    // Donjon: all gear and spells stripped
    return 1;
}

inline int mmpDeckPlaqueAsterisk(int i) {
    // the 22-pack extras by row; i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int mmpDeckPlaqueBoldFace(int i) {
    // The Void (8) and Donjon (21); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

inline int mmpDeckPlaqueDiscarded(int i) {
    // Jester (16) and Fool (17); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    };
    return t[i];
}

} // namespace rules