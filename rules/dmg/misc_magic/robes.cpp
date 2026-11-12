// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/robes.h"

int Miscmagic_robes::mmpArchmagiWhitePct() {
    // white: 45 percent (good alignment)
    return 45;
}

int Miscmagic_robes::mmpArchmagiGrayPct() {
    // gray: 30 percent (neutral alignment)
    return 30;
}

int Miscmagic_robes::mmpArchmagiBlackPct() {
    // black: 25 percent (evil alignment)
    return 25;
}

int Miscmagic_robes::mmpArchmagiAcClass() {
    // power 1: serves as armor equal to AC 5
    return 5;
}

int Miscmagic_robes::mmpArchmagiMagicResistPct() {
    // power 2: confers a 5 percent magic resistance
    return 5;
}

int Miscmagic_robes::mmpArchmagiSaveBonus() {
    // power 3: adds +1 to saving throw scores
    return 1;
}

int Miscmagic_robes::mmpArchmagiPenaltyPct() {
    // power 4: worn spells cut foe magic
    // resistance and saves by 20 percent
    return 20;
}

int Miscmagic_robes::mmpArchmagiPenaltyMinus() {
    // the saving throw half of the 20 percent cut
    return 4;
}

int Miscmagic_robes::mmpArchmagiCharmFamilyCount() {
    // the seven spells of the power 4 list
    return 7;
}

int Miscmagic_robes::mmpArchmagiClashDmgMin() {
    // white on evil: take 18-51 hit points
    return 18;
}

int Miscmagic_robes::mmpArchmagiClashDmgMax() {
    // the clash damage ceiling
    return 51;
}

int Miscmagic_robes::mmpArchmagiClashDiceCount() {
    // the clash dice are 11d4
    return 11;
}

int Miscmagic_robes::mmpArchmagiClashDiceBonus() {
    // the clash dice bonus is +7
    return 7;
}

int Miscmagic_robes::mmpArchmagiClashXpMin() {
    // and lose 18,000-51,000 experience points
    return 18000;
}

int Miscmagic_robes::mmpArchmagiClashXpMax() {
    // the clash experience loss ceiling
    return 51000;
}

int Miscmagic_robes::mmpArchmagiGrayDmgMin() {
    // the gray or crossed clash: 6-24 hit points
    return 6;
}

int Miscmagic_robes::mmpArchmagiGrayDmgMax() {
    // the gray clash damage ceiling
    return 24;
}

int Miscmagic_robes::mmpArchmagiGrayXpMin() {
    // 6,000-24,000 experience points loss
    return 6000;
}

int Miscmagic_robes::mmpArchmagiGrayXpMax() {
    // the gray experience loss ceiling
    return 24000;
}

int Miscmagic_robes::mmpBlendDetectRangeInches() {
    // within 3 inches something amiss is detectable
    return 3;
}

int Miscmagic_robes::mmpBlendDetectPerIntPct() {
    // 1 percent per intelligence point chance
    return 1;
}

int Miscmagic_robes::mmpBlendDetectIntMin() {
    // exceptional (15+) or better intelligence
    return 15;
}

int Miscmagic_robes::mmpBlendLevelDetectIntMin() {
    // low intelligence (5+) or better and
    return 5;
}

int Miscmagic_robes::mmpBlendLevelDetectLevelMin() {
    // 10 or more levels of experience or hit dice
    return 10;
}

int Miscmagic_robes::mmpBlendDetectPerLevelPct() {
    // 1 percent per level or hit die chance
    return 1;
}

int Miscmagic_robes::mmpBlendExamplePct() {
    // the 18 int / 12th level example: 30 percent
    return 30;
}

int Miscmagic_robes::mmpEyesInfravisionInches() {
    // infravisual capability to 12 inch range
    return 12;
}

int Miscmagic_robes::mmpEyesSeeInvisibleInches() {
    // invisible things within a 24 inch
    // normal vision range
    return 24;
}

int Miscmagic_robes::mmpEyesSeeInfraredInches() {
    // or 12 inches if infravision is used
    return 12;
}

int Miscmagic_robes::mmpEyesTrackRangerLevel() {
    // tracks as if a 12th level ranger
    return 12;
}

int Miscmagic_robes::mmpEyesBlindLightMin() {
    // a light spell blinds it for 1-3 rounds
    return 1;
}

int Miscmagic_robes::mmpEyesBlindLightMax() {
    // the light blindness ceiling
    return 3;
}

int Miscmagic_robes::mmpEyesBlindContinualMin() {
    // a continual light for 2-8 rounds
    return 2;
}

int Miscmagic_robes::mmpEyesBlindContinualMax() {
    // the continual light blindness ceiling
    return 8;
}

int Miscmagic_robes::mmpPowerlessIntelligence() {
    // the wearer drops to 3 intelligence
    return 3;
}

int Miscmagic_robes::mmpPowerlessStrength() {
    // and becomes weak as well (3 strength)
    return 3;
}

int Miscmagic_robes::mmpScintIntMin() {
    // needs intelligence of 15 or higher
    return 15;
}

int Miscmagic_robes::mmpScintWisMin() {
    // and a wisdom of 13 or more
    return 13;
}

int Miscmagic_robes::mmpScintLightFeet() {
    // sheds light in a 40 foot diameter sphere
    return 40;
}

int Miscmagic_robes::mmpScintStartRounds() {
    // a full round to cause the colors to flow
    return 1;
}

int Miscmagic_robes::mmpScintTransfixMin() {
    // stand transfixed for 2-5 rounds
    return 2;
}

int Miscmagic_robes::mmpScintTransfixMax() {
    // the transfix ceiling
    return 5;
}

int Miscmagic_robes::mmpScintHitPctPerRound() {
    // 5 percent harder to hit per round of play
    return 5;
}

int Miscmagic_robes::mmpScintHitPctMax() {
    // to a maximum of 25 percent (minus 5)
    return 25;
}

int Miscmagic_robes::mmpScintHitMaxRounds() {
    // attained after 5 continuous rounds
    return 5;
}

int Miscmagic_robes::mmpScintCastRangeInches() {
    // activity within 1 inch of the start point
    return 1;
}

int Miscmagic_robes::mmpScintHypnotizeMin() {
    // non-combat hypnosis for 2-5 turns
    return 2;
}

int Miscmagic_robes::mmpScintHypnotizeMax() {
    // the non-combat hypnosis ceiling
    return 5;
}

int Miscmagic_robes::mmpUsefulDetachRounds() {
    // detach any 1 of the patches in 1 round
    return 1;
}

int Miscmagic_robes::mmpUsefulBaseEach() {
    // always 2 each of the base patches
    return 2;
}

int Miscmagic_robes::mmpUsefulBaseCount() {
    // the six base patch kinds (3 table rows)
    return 6;
}

int Miscmagic_robes::mmpUsefulExtraMin() {
    // 4-16 extra items which must be diced for
    return 4;
}

int Miscmagic_robes::mmpUsefulExtraMax() {
    // the extra item ceiling
    return 16;
}

int Miscmagic_robes::mmpUsefulGpBag() {
    // bag of 100 gold pieces
    return 100;
}

int Miscmagic_robes::mmpUsefulCofferGp() {
    // the silver coffer: 500 g.p. value
    return 500;
}

int Miscmagic_robes::mmpUsefulGemsCount() {
    // gems, 10 of
    return 10;
}

int Miscmagic_robes::mmpUsefulGemValueGp() {
    // 100 gold piece value each
    return 100;
}

int Miscmagic_robes::mmpUsefulLadderFeet() {
    // wooden ladder, 24 feet long
    return 24;
}

int Miscmagic_robes::mmpUsefulPitCubicFeet() {
    // pit, 10 cubic feet, open
    return 10;
}

int Miscmagic_robes::mmpUsefulRowboatFeet() {
    // rowboat, 12 feet long
    return 12;
}

int Miscmagic_robes::mmpUsefulWindowWidthFeet() {
    // window, 2 feet wide
    return 2;
}

int Miscmagic_robes::mmpUsefulWindowHeightFeet() {
    // 4 feet high
    return 4;
}

int Miscmagic_robes::mmpUsefulWindowDepthFeet() {
    // up to 2 feet deep
    return 2;
}

int Miscmagic_robes::mmpUsefulScrollSpells() {
    // scroll of 1 spell
    return 1;
}

int Miscmagic_robes::mmpUsefulWarDogsPair() {
    // war dogs, pair
    return 2;
}

int Miscmagic_robes::mmpUsefulRowLo(int i) {
    // the printed extra item band lower edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        1, 9, 16, 23, 31, 45, 52,
        60, 69, 76, 84, 91, 97,
    };
    return t[i];
}

int Miscmagic_robes::mmpUsefulRowHi(int i) {
    // the printed extra item band upper edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        8, 15, 22, 30, 44, 51, 59,
        68, 75, 83, 90, 96, 100,
    };
    return t[i];
}
