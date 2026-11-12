// ====================================================================
// Adnd1 - rules/dmg/miscmagic_deck_of_many_things.h
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

// R-refactor: namespace rules -> class Miscmagic_deck_of_many_things (instance methods)
class Miscmagic_deck_of_many_things {
public:
    int mmpDeckPlaqueMaterialCount();
    int mmpDeckMinDraws();
    int mmpDeckMaxDraws();
    int mmpDeckJesterBonusDraws();
    int mmpDeckBasePlaqueCount();
    int mmpDeckFullPlaqueCount();
    int mmpDeckBaseChancePct();
    int mmpDeckFullChancePct();
    int mmpDeckAsteriskPlaqueCount();
    int mmpDeckDiscardPlaqueCount();
    int mmpDeckBoldFaceStopCount();
    int mmpDeckTablePlaqueCount();
    int mmpDeckSunXp();
    int mmpDeckMoonWishesMin();
    int mmpDeckMoonWishesMax();
    int mmpDeckMoonSpellLevel();
    int mmpDeckStarPoints();
    int mmpDeckStarMaxScore();
    int mmpDeckStarFallbackOrderCount();
    int mmpDeckCometMidpointProgress();
    int mmpDeckThroneCharisma();
    int mmpDeckThroneReactionBonusPct();
    int mmpDeckKeyMapBonusPct();
    int mmpDeckKeyWeaponCount();
    int mmpDeckKnightLevel();
    int mmpDeckKnightBonusPerDie();
    int mmpDeckKnightAbilityMax();
    int mmpDeckGemJewelryCount();
    int mmpDeckGemGemCount();
    int mmpDeckGemGemBaseGp();
    int mmpDeckGemXpLevelCap();
    int mmpDeckEuryaleSavePenalty();
    int mmpDeckRogueHenchmenAlienated();
    int mmpDeckJesterXp();
    int mmpDeckJesterExtraDraws();
    int mmpDeckFoolXp();
    int mmpDeckIdiotIntLossMin();
    int mmpDeckIdiotIntLossMax();
    int mmpDeckSkullDeathAc();
    int mmpDeckSkullDeathHp();
    int mmpDeckSkullScytheDmgMin();
    int mmpDeckSkullScytheDmgMax();
    int mmpDeckSkullUndeadForSpells();
    int mmpDeckFatesPartyEndures();
    int mmpDeckDonjonGearStripped();
    int mmpDeckPlaqueAsterisk(int i);
    int mmpDeckPlaqueBoldFace(int i);
    int mmpDeckPlaqueDiscarded(int i);
};
