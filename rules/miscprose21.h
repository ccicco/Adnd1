// ====================================================================
// Adnd1 - rules/miscprose21.h
// R277: the III.E misc magic explanation prose part 21
// (DMG p.153-154) - the Robe of the Archmagi, the Robe
// of Blending, the Robe of Eyes, the Robe of Powerlessness,
// the Robe of Scintillating Colors and the Robe of Useful
// Items, part2 lines 1002-1052 (global = 11065 + part2
// line), pinning the kMisc5 rows 0-5 of the 35-row III.E.5
// table - the slice that opens the table. This round has
// one seam: the Powerlessness paragraph splits between the
// 1018 tail (and becomes) and the 1021 head (weak as well),
// with the 1019-1020 pair of blanks - the p.153-154 page
// break with no running head - seam restored here. The
// upload quirks this round: the OCR splits two words with
// a space (magic- user and language/ noise); the curly
// apostrophes print in the robe and wearer possessives;
// curly quotes wrap see, eyes and flowing; the foot and
// inch primes print as curly marks; the 20%/minus 4
// reduction prints the true minus sign; the coffer and
// window rows carry one-half and multiplication signs;
// the door and window rows separate with em-dashes - all
// pinned as plain digits and words, apostrophe-free here.
// The part1 quirks: the six robe rows print side-by-side
// with armor-table columns (part1 9875-9880); the
// Powerlessness row prints --- in the x.p. column; the
// Scintillating row misplaces 2,750 after the (C, M)
// marks. The useful items table flattens its two header
// rows (Dice and Roll Result each on an own line) and
// prints 13 die bands, pinned as the twin walkers.
// 67 accessors: 65 scalars + 2 walkers (the useful item
// die bands), no name collisions with miscprose1.h
// through miscprose20.h. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpArchmagiWhitePct() {
    // white: 45 percent (good alignment)
    return 45;
}

inline int mmpArchmagiGrayPct() {
    // gray: 30 percent (neutral alignment)
    return 30;
}

inline int mmpArchmagiBlackPct() {
    // black: 25 percent (evil alignment)
    return 25;
}

inline int mmpArchmagiAcClass() {
    // power 1: serves as armor equal to AC 5
    return 5;
}

inline int mmpArchmagiMagicResistPct() {
    // power 2: confers a 5 percent magic resistance
    return 5;
}

inline int mmpArchmagiSaveBonus() {
    // power 3: adds +1 to saving throw scores
    return 1;
}

inline int mmpArchmagiPenaltyPct() {
    // power 4: worn spells cut foe magic
    // resistance and saves by 20 percent
    return 20;
}

inline int mmpArchmagiPenaltyMinus() {
    // the saving throw half of the 20 percent cut
    return 4;
}

inline int mmpArchmagiCharmFamilyCount() {
    // the seven spells of the power 4 list
    return 7;
}

inline int mmpArchmagiClashDmgMin() {
    // white on evil: take 18-51 hit points
    return 18;
}

inline int mmpArchmagiClashDmgMax() {
    // the clash damage ceiling
    return 51;
}

inline int mmpArchmagiClashDiceCount() {
    // the clash dice are 11d4
    return 11;
}

inline int mmpArchmagiClashDiceBonus() {
    // the clash dice bonus is +7
    return 7;
}

inline int mmpArchmagiClashXpMin() {
    // and lose 18,000-51,000 experience points
    return 18000;
}

inline int mmpArchmagiClashXpMax() {
    // the clash experience loss ceiling
    return 51000;
}

inline int mmpArchmagiGrayDmgMin() {
    // the gray or crossed clash: 6-24 hit points
    return 6;
}

inline int mmpArchmagiGrayDmgMax() {
    // the gray clash damage ceiling
    return 24;
}

inline int mmpArchmagiGrayXpMin() {
    // 6,000-24,000 experience points loss
    return 6000;
}

inline int mmpArchmagiGrayXpMax() {
    // the gray experience loss ceiling
    return 24000;
}

inline int mmpBlendDetectRangeInches() {
    // within 3 inches something amiss is detectable
    return 3;
}

inline int mmpBlendDetectPerIntPct() {
    // 1 percent per intelligence point chance
    return 1;
}

inline int mmpBlendDetectIntMin() {
    // exceptional (15+) or better intelligence
    return 15;
}

inline int mmpBlendLevelDetectIntMin() {
    // low intelligence (5+) or better and
    return 5;
}

inline int mmpBlendLevelDetectLevelMin() {
    // 10 or more levels of experience or hit dice
    return 10;
}

inline int mmpBlendDetectPerLevelPct() {
    // 1 percent per level or hit die chance
    return 1;
}

inline int mmpBlendExamplePct() {
    // the 18 int / 12th level example: 30 percent
    return 30;
}

inline int mmpEyesInfravisionInches() {
    // infravisual capability to 12 inch range
    return 12;
}

inline int mmpEyesSeeInvisibleInches() {
    // invisible things within a 24 inch
    // normal vision range
    return 24;
}

inline int mmpEyesSeeInfraredInches() {
    // or 12 inches if infravision is used
    return 12;
}

inline int mmpEyesTrackRangerLevel() {
    // tracks as if a 12th level ranger
    return 12;
}

inline int mmpEyesBlindLightMin() {
    // a light spell blinds it for 1-3 rounds
    return 1;
}

inline int mmpEyesBlindLightMax() {
    // the light blindness ceiling
    return 3;
}

inline int mmpEyesBlindContinualMin() {
    // a continual light for 2-8 rounds
    return 2;
}

inline int mmpEyesBlindContinualMax() {
    // the continual light blindness ceiling
    return 8;
}

inline int mmpPowerlessIntelligence() {
    // the wearer drops to 3 intelligence
    return 3;
}

inline int mmpPowerlessStrength() {
    // and becomes weak as well (3 strength)
    return 3;
}

inline int mmpScintIntMin() {
    // needs intelligence of 15 or higher
    return 15;
}

inline int mmpScintWisMin() {
    // and a wisdom of 13 or more
    return 13;
}

inline int mmpScintLightFeet() {
    // sheds light in a 40 foot diameter sphere
    return 40;
}

inline int mmpScintStartRounds() {
    // a full round to cause the colors to flow
    return 1;
}

inline int mmpScintTransfixMin() {
    // stand transfixed for 2-5 rounds
    return 2;
}

inline int mmpScintTransfixMax() {
    // the transfix ceiling
    return 5;
}

inline int mmpScintHitPctPerRound() {
    // 5 percent harder to hit per round of play
    return 5;
}

inline int mmpScintHitPctMax() {
    // to a maximum of 25 percent (minus 5)
    return 25;
}

inline int mmpScintHitMaxRounds() {
    // attained after 5 continuous rounds
    return 5;
}

inline int mmpScintCastRangeInches() {
    // activity within 1 inch of the start point
    return 1;
}

inline int mmpScintHypnotizeMin() {
    // non-combat hypnosis for 2-5 turns
    return 2;
}

inline int mmpScintHypnotizeMax() {
    // the non-combat hypnosis ceiling
    return 5;
}

inline int mmpUsefulDetachRounds() {
    // detach any 1 of the patches in 1 round
    return 1;
}

inline int mmpUsefulBaseEach() {
    // always 2 each of the base patches
    return 2;
}

inline int mmpUsefulBaseCount() {
    // the six base patch kinds (3 table rows)
    return 6;
}

inline int mmpUsefulExtraMin() {
    // 4-16 extra items which must be diced for
    return 4;
}

inline int mmpUsefulExtraMax() {
    // the extra item ceiling
    return 16;
}

inline int mmpUsefulGpBag() {
    // bag of 100 gold pieces
    return 100;
}

inline int mmpUsefulCofferGp() {
    // the silver coffer: 500 g.p. value
    return 500;
}

inline int mmpUsefulGemsCount() {
    // gems, 10 of
    return 10;
}

inline int mmpUsefulGemValueGp() {
    // 100 gold piece value each
    return 100;
}

inline int mmpUsefulLadderFeet() {
    // wooden ladder, 24 feet long
    return 24;
}

inline int mmpUsefulPitCubicFeet() {
    // pit, 10 cubic feet, open
    return 10;
}

inline int mmpUsefulRowboatFeet() {
    // rowboat, 12 feet long
    return 12;
}

inline int mmpUsefulWindowWidthFeet() {
    // window, 2 feet wide
    return 2;
}

inline int mmpUsefulWindowHeightFeet() {
    // 4 feet high
    return 4;
}

inline int mmpUsefulWindowDepthFeet() {
    // up to 2 feet deep
    return 2;
}

inline int mmpUsefulScrollSpells() {
    // scroll of 1 spell
    return 1;
}

inline int mmpUsefulWarDogsPair() {
    // war dogs, pair
    return 2;
}

inline int mmpUsefulRowLo(int i) {
    // the printed extra item band lower edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        1, 9, 16, 23, 31, 45, 52,
        60, 69, 76, 84, 91, 97,
    };
    return t[i];
}

inline int mmpUsefulRowHi(int i) {
    // the printed extra item band upper edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        8, 15, 22, 30, 44, 51, 59,
        68, 75, 83, 90, 96, 100,
    };
    return t[i];
}

}  // namespace rules