// R-refactor: split from specart_axe_of_the_dwarvish_lords_to_codex.h - definitions
#include "rules/dmg/specart_axe_of_the_dwarvish_lords_to_codex.h"

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeBladeSharpness() {
    // the blade equals a sword of sharpness
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeHammerBonus() {
    // the head equals a +3 hammer
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeHandleForms() {
    // the handle equals a battle or hand axe
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeReturnFeet() {
    // returns 30 feet to its thrower
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeDwarfAbilityMultiplier() {
    // dwarven abilities doubled for a dwarf
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeLifespanBonusPct() {
    // the life span is 50 percent longer
    return 50;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeBearsCurse() {
    // the Axe supposedly bears a curse
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxeInvokedDevastationLost() {
    // lost in the Invoked Devastation centuries gone
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxePowerTotal() {
    // 2 of table I plus 1 each of tables II-VI
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapAxePowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutDiameterFeet() {
    // a circular thatched structure of 15 feet
    return 15;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutHeightFeet() {
    // 10 feet high
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegCount() {
    // two powerful fowl legs
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegLengthFeet() {
    // the legs are 12 feet long stilts
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutInfravisionFeet() {
    // infravisual ability to 120 feet
    return 120;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutRoomCount() {
    // 30 rooms on 3 floors, all furnished
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutFloorCount() {
    // the 30 rooms sit on 3 floors
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutMoveTerrainCount() {
    // swamp, rough or normal, hills and forests
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutMoveInches(int i) {
    // move per terrain; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        48, 36, 12,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutCommanderCount() {
    // obeys the one first using a key phrase
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutCallRangeLeagues() {
    // comes to a call from 1 league away
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegAttacksPerRound() {
    // the legs deliver blows, 2 attacks per round
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegArmorClass() {
    // the legs are armor class 2
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegHpEach() {
    // the legs take 48 hit points damage each
    return 48;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegRegenPerRound() {
    // regenerating at 1 hit point per round
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutWallGraniteFeet() {
    // the walls equal 5 feet thick granite
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutLegsHillGiantBlows() {
    // the leg blows equal those of a hill giant
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutPowerTotal() {
    // 4 of I, 2 of II, 1 each of III-VI
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHutPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexDamnedPages() {
    // any person reading its 99 damned pages
    return 99;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexDoomChancePct() {
    // 99 percent certain to meet a terrible fate
    return 99;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexPerilPerPagePct() {
    // 1 percent cumulative chance per page
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexTouchKillBelowLevel() {
    // destroys any character under 11th level
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexCommandMinLevel() {
    // 11th or higher save versus magic to command
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexPerusalActivation() {
    // powers activate per the progress of perusal
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexPowerTotal() {
    // 4 each of I-II, 2 each of III-VI
    return 16;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCodexPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 4, 2, 2, 2, 2,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownRegaliaSetCount() {
    // these 3 complete sets bestow great powers
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownItemsPerSet() {
    // a crown, an orb and a sceptre per champion
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownChampionEthosCount() {
    // the champion of each ethic alignment
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownPossessionBenefits() {
    // mere possession benefits a same-ethos character
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWrongEthosDamageMin() {
    // a wrong-ethos touch deals 5-30 hit points
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWrongEthosDamageMax() {
    // the upper edge of the 5-30 hit points
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWrongEthosSaveOrDeath() {
    // save versus magic or be instantly killed
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWearerLevelBonus() {
    // raises the level of experience by 1 while worn
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWornPowerTotal() {
    // 2 of table I plus 1 each of tables II-III
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownOffEthosMalevolentCount() {
    // 1 malevolent power on a successful save
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownOffEthosMalevolentTable() {
    // the malevolent power comes from table IV
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownSet2ndPowerTotal() {
    // the same-ethos 2nd item adds 1 each of I-II
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownSet3rdPowerTotal() {
    // the 3rd item adds 1 each of I, II, IV-VI
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownDetectionRevealsAlignment() {
    // detection magically will not reveal the alignment
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownGemCount() {
    // set with 3 precious stones of great size
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownSaleGpMin() {
    // 50,000 or more gold pieces if openly sold
    return 50000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownAlignBandLo(int i) {
    // the alignment band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 7, 15,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownAlignBandHi(int i) {
    // the alignment band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        6, 14, 20,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownWornPowerCount(int i) {
    // the worn powers per tables I-III; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        2, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownSet2ndPowerCount(int i) {
    // the 2nd item powers per tables I-II; i clamps
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    static const int t[2] = {
        1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrownSet3rdPowerCount(int i) {
    // the 3rd item powers per I, II, IV-VI; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalOriginUnknown() {
    // the origin and whereabouts entirely unknown
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalDiamondHard() {
    // a diamond-hard mineral the size of a hand
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalTouchRaysBlackFlame() {
    // touched it sends rays, a black flame leaps
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalCharmRadiusFeet() {
    // all creatures within 30 feet save versus magic
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalCharmIsFireCharm() {
    // or charmed as if by a fire charm spell
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalPowersByGazing() {
    // powers drawn by gazing at the Ebon Flame
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalPowerTotal() {
    // 4 of table I, 2 of II, 1 each of III-VI
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCrystalPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanRelicCount() {
    // a pair of holy relics
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPaynimGift() {
    // given by the gods of the Paynims to the
    // most exalted high priest of lawful good
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanInvokedDevastationEra() {
    // in the days following the Invoked Devastation
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanLostToRaiders() {
    // lost to demi-human raiders, rumored Southeastern
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPotionClassCount() {
    // a cleric, druid, paladin or ranger possessing both
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPotionPerWeek() {
    // may create a potion once per week
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupGemCount() {
    // set with 12 great gems in electrum settings
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupJewelryGpMin() {
    // a jewelry value of 75,000 or more gold pieces
    return 75000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupRadiatesMagic() {
    // the Cup does not radiate magic
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupPowerTotal() {
    // 4 of table I plus 1 of table III
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupPowerCount(int i) {
    // the cup powers per tables I-III; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        4, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanPointCount() {
    // a star of 8 points
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanPointGemCount() {
    // a small gem tipping each point
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanBeadSetCount() {
    // 8 sets of 3 beads each on the chain
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanBeadsPerSet() {
    // silver beading, 8 sets of 3 beads each
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanJewelryGpMin() {
    // a jewelry value of 10,000 or more gold pieces
    return 10000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanRadiatesMagic() {
    // the Talisman does not radiate magic either
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanPowerTotal() {
    // 2 of table II plus 1 of table IV
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapTalismanPowerCount(int i) {
    // the talisman powers per tables I-IV; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 2, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanBothPowerTotal() {
    // 1 each of tables V and VI from both
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanBothPowerCount(int i) {
    // the both powers per tables V-VI; i clamps
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    static const int t[2] = {
        1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPotionBandCount() {
    // the six bands of the potion table
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPotionBandLo(int i) {
    // the potion band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 11, 16, 18, 20,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCupTalismanPotionBandHi(int i) {
    // the potion band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 10, 15, 17, 19, 20,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeVecnaPhantomRoams() {
    // the phantom of the once supreme lich roams
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeDoomSurvivors() {
    // one eye and one hand survived his doom
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeFeralGlow() {
    // glows in the same manner as a feral creature
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeAppearsAgate() {
    // appears an agate until placed in an eye socket
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeGraftIrrevocable() {
    // grafts irrevocably, removed only by slaying
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeHostNeutralEvil() {
    // the host alignment becomes neutral evil, never changes
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeGrantsInfravision() {
    // the Eye bestows infravision to its host
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyeGrantsUltravision() {
    // the Eye bestows ultravision to its host
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyePowerTotal() {
    // 2 each of I-II, 1 each of IV-V (III skipped)
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyePowerCount(int i) {
    // the powers per tables I-V; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        2, 2, 0, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapEyePrimaryPowerMalevolent() {
    // the primary power causes a malevolent effect
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandVecnaLeftHand() {
    // his left hand, imbued with powers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandMummifiedExtremity() {
    // a blackened, shriveled mummified extremity
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandGripStrength() {
    // a functioning member with 18/00 strength
    return 18;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandGripStrengthRating() {
    // the printed 00 rating of the 18/00 grip
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandGripHitOrDamageBonus() {
    // no to hit or damage bonuses
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandHostTurnsNeutralEvil() {
    // the host eventually turns neutral evil
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandMajorPowerWakesSpirit() {
    // a major power use wakes a spirit of great evil
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandPrimaryPowerInstantEvil() {
    // a primary power: instantly neutral evil
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandSeverBaseChancePct() {
    // severed before powers used, 100 percent certainty
    return 100;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandSeverMajorPenaltyPct() {
    // each major power use subtracts 1 percent
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandSeverPrimaryPenaltyPct() {
    // each primary power use: 10 percent less likely
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandNoRemovalAtLimit() {
    // at 100 percent subtraction no removal, the host knows
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandFingerCombinations() {
    // powers work through extended or curled fingers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandPowerTotal() {
    // 10 of I, 5 of II, 2 each of III-V, 1 of VI
    return 22;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        10, 5, 2, 2, 2, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandGodsOnlyAlteration() {
    // only the most powerful of gods can alter the effects
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHandRecordCombinations() {
    // the note: devise and record the position chart
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganPipeCount() {
    // 77 great and small pipes
    return 77;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganStopCount() {
    // the console keys beneath 13 ivory stops
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganPedalCount() {
    // 3 great foot pedals
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganBellowsElemental() {
    // the bellows worked by a chained air elemental
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganStopsVaryVoice() {
    // each stop sounds the pipes in a new voice
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganKeysVaryNotes() {
    // the keys vary the notes
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganPedalPurposeUnknown() {
    // no one is certain what the pedals serve
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganStillWorksDespiteTime() {
    // despite silenced pipes it works mighty magicks
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganWrongStopsSummon() {
    // wrong stops summon the undesired or wrong spell
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganWrongKeysBackfire() {
    // wrong keys unbind or the magic backfires
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganMisplayAlignment() {
    // improper playing may change the alignment
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganDmAssignsStopsKeys() {
    // the DM decides the stops and key sequences
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganPowerTotal() {
    // 7+7+3+7+7+3 - the total power count
    return 34;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganMisplayNegates() {
    // misplaying negates, reverses, changes effects
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornResemblesCommonHorns() {
    // exactly resembles horns of blasting, bubbles
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornSuggestedPowerPct() {
    // the suggested 75 percent power share
    return 75;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornSuggestedEffectPct() {
    // the suggested 25 percent effect share
    return 25;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornIgnoresInappropriate() {
    // inappropriate results are ignored
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatArndOfTdon() {
    // the High Priest Arnd of Tdon possessed it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatChainLinksWeightless() {
    // a shimmering shirt of almost weightless links
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatCoveredAreaCount() {
    // covers upper arms, torso and groin
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatMinWearerHeightFt() {
    // the minimum 3 foot human-shaped wearer
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatMaxWearerHeightFt() {
    // the maximum 8 foot human-shaped wearer
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatInvulnerableCovered() {
    // totally invulnerable on covered areas
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatUncoveredAc() {
    // AC 5 protection on all other areas
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatSaveBonus() {
    // +5 to saving throws as +5 magic armor
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatFireResistance() {
    // fire protection as a ring of fire resistance
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatElementalImmunityCount() {
    // acid, cold and electrical attacks: no effect
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatPowerTotal() {
    // 3+2+2+1+1+1 - the total power count
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrganPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 7, 3, 7, 7, 3,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornBlastPowerTable(int i) {
    // the power table per 1, 2 or 3 blasts; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 2, 5,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapHornBlastEffectTable(int i) {
    // the effect table per 1, 2 or 3 blasts; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 6, 4,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapCoatPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 2, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskHeavyUrn() {
    // a small and heavy urn, easily carried
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskTurnipPlug() {
    // stoppered with a turnip-shaped plug
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskSigilRunes() {
    // engraved with sigils, glyphs, runes
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskWordCount() {
    // opening, command, closing and sealing
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskPrisonerCount() {
    // the 5 rumored prisoners within
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskServantEvilOnly() {
    // the Servant loosed only for evil deeds
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskKillBeforeReturn() {
    // it must kill before returning to prison
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskPowerTotal() {
    // 3+0+1+0+1+1 - the total power count
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthGodFashioned() {
    // fashioned by the gods themselves
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthMountainHeart() {
    // the finest corundum from the mountain heart
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthFacetedBeams() {
    // dozens of facets shoot brilliant beams
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthCharmRangeFt() {
    // within 20 feet save vs magic or charmed
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthSultanPossessed() {
    // Sultan Jehef Pehreen possessed it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthKeolandTrailLost() {
    // into Ket and Keoland, all trace lost
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthGraspPowers() {
    // the possessor firmly grasps the gem
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthPowerTotal() {
    // 2+2+1+1+1+1 - the total power count
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskJohydeeTrickedEvil() {
    // the priestess tricked the powers of evil
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskOverthrewNation() {
    // used to overthrow their hold on her nation
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskCoversFace() {
    // covers the whole face of the wearer
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskAssumeLikeness() {
    // assume the likeness of any human-like creature
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskBlocksMindContact() {
    // blocks all mind contact, detection, attack
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskGazeImmunity() {
    // total immunity to all gaze attacks
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskGazeCreatureCount() {
    // basilisk, catoblepas and medusa
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskPowerTotal() {
    // 2+1+0+0+0+1 - the total power count
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFlaskPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 0, 1, 0, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapJacinthPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 2, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaskPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 0, 0, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillMasterThiefBest() {
    // the master thief, most successful of his kind
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillUnknownAntiquity() {
    // a writing instrument of unknown antiquity
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillBearsKurothName() {
    // it now bears the name of Kuroth
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillInfallibleScribe() {
    // draws and writes infallibly upon command
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillDepictsSeenSpoken() {
    // depicts what its possessor sees or speaks
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillPotionTreasureFinding() {
    // it finds treasure as the potion does
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillTreasureFindPerMonth() {
    // the treasure finding, times per month
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillPowerTotal() {
    // 2+0+1+1+0+1 - the total power count
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapQuillPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 0, 1, 1, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceSaintCuthbertWeapon() {
    // actually used by the Venerable Saint Cuthbert
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceFollyOfError() {
    // demonstrated the folly of error to the unbeliever
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceRelicsEncased() {
    // holy relics of the Saint encased within
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceHitDamageBonus() {
    // the bonus for both hitting and damage
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceDisruptionEffects() {
    // it also has disruption effects
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceClericStrReq() {
    // wieldable only by clerics of this strength
    return 18;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMaceLawfulGoodOnly() {
    // the wielder must be of lawful good alignment
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMacePowerTotal() {
    // 3+2+0+0+0+1 - the total power count
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMacePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 0, 0, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineGodsForgotten() {
    // perhaps built by gods long forgotten
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineWorkmanshipUnknown() {
    // workmanship unlike anything known today
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineBaronLumEmpire() {
    // used by Baron Lum to build an empire
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineLeverCount() {
    // the number of levers it has
    return 60;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineDialCount() {
    // the number of dials it has
    return 40;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineSwitchCount() {
    // the number of switches it has
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineControlsTotal() {
    // levers + dials + switches
    return 120;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineHalfFunction() {
    // about one-half of the controls still function
    return 60;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineWeightLb() {
    // bulky and very heavy, in pounds
    return 5500;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineJoltDestroyMax() {
    // a serious jolt destroys up to this many
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachineBoothCreatures() {
    // the booth fits this many man-sized creatures
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachinePowerTotal() {
    // 15+15+10+10+15+5 - the total power count
    return 70;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapMachinePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        15, 15, 10, 10, 15, 5,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantLumSameMake() {
    // the same manufacture as the Machine of Lum
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantAutomatonHeightFt() {
    // it stands over this many feet tall
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantDepthFt() {
    // it is this many feet deep
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantWidthFt() {
    // some 4 and one-half feet wide
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantInsideRiders() {
    // the compartment holds this many man-sized
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantOutsideSittersMin() {
    // 4 to 5 others may sit outside
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantCommandPhrases() {
    // the possessor must know the proper phrases
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantUseCount() {
    // transportation, attack device, fighting machine
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantArmorClass() {
    // armor class minus 1 (a true-minus quirk)
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantHitPoints() {
    // it withstands this many hit points
    return 60;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantWeaponDamagePct() {
    // weapons do only this percent of normal
    return 50;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantRegenPerRound() {
    // it self-repairs this many points per round
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantMagicResistPct() {
    // its magic resistance, in percent
    return 100;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantElementImmuneCount() {
    // acid cold fire heat vacuum water - no effect
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantElectricalDamagePct() {
    // electrical attacks do only this percent
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantSpeedInches() {
    // its maximum speed, in inches
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantOperationHours() {
    // hours of operation before it must rest
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantRestHours() {
    // it must rest this many hours
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantPanicRangeInches() {
    // the intelligent-viewer panic range, in inches
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantPanicSaveBonus() {
    // the bonus on the panic save die roll
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantAttacksPerRound() {
    // it attacks but this many times per round
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantBaseHitPct() {
    // the base chance to hit, in percent
    return 15;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantDexReduceFloor() {
    // per point of dexterity above this
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantDexReducePct() {
    // 2 and one-half percent per point above
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantDamageLowHp() {
    // the low end of a hit, in hit points
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantDamageHighHp() {
    // the high end of a hit, in hit points
    return 100;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantObeysSecretLearners() {
    // it obeys those who learn its secrets
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantPowerTotal() {
    // 6+6+1+2+0+2 - the total power count
    return 17;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapServantPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 6, 1, 2, 0, 2,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGoodDeitiesOrigin() {
    // the good deities conspired to devise it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDemonsCorrupted() {
    // demon servants changed the magic
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGlobeCount() {
    // the globes of carven white jade
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbOnePerAge() {
    // 1 globe for each age of dragon life
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbSmallestInches() {
    // the smallest globe, in inches
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbLargestInches() {
    // the largest globe, in inches
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbBasReliefCovered() {
    // bas reliefs of entwined dragons cover it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonEssence() {
    // it holds the essence of all dragons
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbHatchlingIntelligence() {
    // the intelligence of the Hatchling
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbHatchlingEgo() {
    // the ego of the Hatchling
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbHatchlingPowerTotal() {
    // 3+0+0+0+0+0 - the total power count
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbHatchlingPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbWyrmkinIntelligence() {
    // the intelligence of the Wyrmkin
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbWyrmkinEgo() {
    // the ego of the Wyrmkin
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbWyrmkinPowerTotal() {
    // 2+1+0+0+0+0 - the total power count
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbWyrmkinPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 0, 0, 0, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonetteIntelligence() {
    // the intelligence of the Dragonette
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonetteEgo() {
    // the ego of the Dragonette
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonettePowerTotal() {
    // 3+1+1+0+0+0 - the total power count
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonettePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 1, 1, 0, 0, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonIntelligence() {
    // the intelligence of the Dragon
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonEgo() {
    // the ego of the Dragon
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonPowerTotal() {
    // 4+1+1+0+0+0 - the total power count
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbDragonPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 1, 1, 0, 0, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGreatSerpentIntelligence() {
    // the intelligence of the Great Serpent
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGreatSerpentEgo() {
    // the ego of the Great Serpent
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGreatSerpentPowerTotal() {
    // 3+2+1+0+0+1 - the total power count
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbGreatSerpentPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 1, 0, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbFiredrakeOldDragon() {
    // the possessor charms any old dragon
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbFiredrakeIntelligence() {
    // the intelligence of the Firedrake
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbFiredrakeEgo() {
    // the ego of the Firedrake
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbFiredrakePowerTotal() {
    // 3+3+2+0+0+1 - the total power count
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbFiredrakePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 0, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbElderWyrmVeryOldDragon() {
    // the possessor charms any very old dragon
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbElderWyrmIntelligence() {
    // the intelligence of the Elder Wyrm
    return 16;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbElderWyrmEgo() {
    // the ego of the Elder Wyrm
    return 16;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbElderWyrmPowerTotal() {
    // 4+3+2+1+1+1 - the total power count
    return 12;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbElderWyrmPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 3, 2, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalAncientDragon() {
    // the possessor charms any ancient dragon
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalTiamatBahamutBonus() {
    // saves, attacks and damage vs Tiamat or Bahamut
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalIntelligence() {
    // the intelligence of the Eternal Grand Dragon
    return 18;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalEgo() {
    // the ego of the Eternal Grand Dragon
    return 18;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalPowerTotal() {
    // 4+3+2+1+2+1 - the total power count
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbEternalPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 3, 2, 1, 2, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesEvilComponent() {
    // all of these Orbs have a strong evil component
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesNeutralGoodResist() {
    // a neutral or good character saves vs magic to resist
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesCharmRangeInches() {
    // the charm range, in inches
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesCharmRounds() {
    // the charm requires this many full rounds
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesAwakeAndAware() {
    // the subject must be fully awake and aware
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesEvilAutoCharmed() {
    // only evil dragons are automatically charmed
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesNeutralSavePenalty() {
    // the neutral dragon save penalty, as a magnitude
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesGoodSavePenalty() {
    // the good dragon save penalty, as a magnitude
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesCharmedWisdomPercent() {
    // charmed characters keep this percent of wisdom
    return 50;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesFeeblemindIntelligence() {
    // feeblemind leaves this intelligence
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesInsanePercent() {
    // insanity leaves this percent of normal
    return 50;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesAwakeMindOnly() {
    // the Orb controls only an active and awake mind
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbNotesSacrificeDestruction() {
    // destruction by sacrifice to a dragon at hand
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightOrbCount() {
    // the 3 Orbs of Might
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightCrownSource() {
    // the legendary source - the foregoing Crown of Might
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightEvilDieLo() {
    // the evil ethos die band low edge
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightEvilDieHi() {
    // the evil ethos die band high edge
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightGoodDieLo() {
    // the good ethos die band low edge
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightGoodDieHi() {
    // the good ethos die band high edge
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightNeutralDieLo() {
    // the neutrality ethos die band low edge
    return 15;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightNeutralDieHi() {
    // the neutrality ethos die band high edge
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightTouchDeathSave() {
    // another ethos touching one saves vs magic or dies
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightTouchDamageLo() {
    // the damage on a successful save, low edge
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightTouchDamageHi() {
    // the damage on a successful save, high edge
    return 24;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightRegaliaTableFour() {
    // with Crown and/or Sceptre, a Table IV malevolence
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightPlatinumGems() {
    // platinum, gem-encrusted, precious device atop
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightValueGp() {
    // the open market worth, in gold pieces
    return 100000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightGemOfBrightness() {
    // each Orb equals a Gem of Brightness
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightPowerEthosCount() {
    // the power table ethos columns - evil, good, neutrality
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightPowerTotal() {
    // 2+0+1+0+0+0 - the total power count per ethos
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 0, 1, 0, 0, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapOrbMightRegaliaPowers() {
    // additional regalia powers - see the Crown of Might
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleMadeByXagy() {
    // Xagy is one of its makers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleJoramyCoMaker() {
    // the volcano goddess Joramy is the other
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleMadeCenturiesAgo() {
    // Mordenkainen dated it this many centuries back
    return 17;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleEhlissaBentAll() {
    // Queen Ehlissa bent all to her will
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleNeverEscaped() {
    // it never escaped its confinement
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleGoldenWireCage() {
    // held within a fine mesh of golden wires
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleWingsPerchPerform() {
    // wings open, hops to the perch, performs
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleEyeRays() {
    // its eyes shoot scintillating colored rays
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleSongWonders() {
    // its songs work magical wonders
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleRaySongSpells() {
    // rays and songs in combination weave spells
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleSphereRadiusFeet() {
    // the protective sphere radius, in feet
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleSphereBlocksScrying() {
    // no detection or magic or psionic intrusion
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingaleNoHungerThirst() {
    // those within neither hunger nor thirst
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingalePowerTotal() {
    // 4+0+1+1+1+1 - the total power count
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapNightingalePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 0, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderNeedsNoMusician() {
    // it needs no musician to play it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderPlaysOnCommand() {
    // plays the most complicated airs on command
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderAlarmRadiusFeet() {
    // the stolen-goods alarm radius, in feet
    return 30;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderAlarmIncludesSelf() {
    // it alarms for itself stolen as well
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderClueWordSongs() {
    // information through clue-word songs
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderRumoredSpells() {
    // rumored to cast spells with its notes
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderPowerTotal() {
    // 5+2+1+1+1+1 - the total power count
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRecorderPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 2, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxAlienOrigin() {
    // its origin is totally alien
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxPlatinumLoopSpinel() {
    // a platinum loop about a fine spinel
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxUnknownGemType() {
    // the workmanship unique, the gem unknown
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxFingerDiscovery() {
    // donned on a finger to discover powers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxFacetCount() {
    // the nine-faceted gem
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxFacingToTop() {
    // each facet powers when faced to the top
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxTurnsItself() {
    // it turns itself off, on, or when asleep
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxDailyRandomFacet() {
    // a random facet each day, secret to the DM
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxFacetOrderKnown() {
    // one known facing reveals the order
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxCannotBeMarked() {
    // unmarkable - even a wish will not help
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxPowerTotal() {
    // 3+2+1+1+1+1 - the total power count
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapGaxxPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodWindDukesMadeIt() {
    // the Wind Dukes of Aaqa are its legendary makers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodMadeForBattleOfPesh() {
    // constructed for the great battle of Pesh
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPeshChaosVersusLaw() {
    // at Pesh, Chaos and Law contended
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodShatteredAtPesh() {
    // it was shattered there, its parts scattered
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodNothingDestroysIt() {
    // nothing could actually destroy it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCorrectOrderSurpassingPower() {
    // correct-order assembly gives surpassing power
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPartCount() {
    // the number of parts of the Rod
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPartsSlightlyDifferent() {
    // the parts are slightly different from each other
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodFirstLargestLengthDiameter() {
    // the first is largest in length and diameter
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodSeventhSmallest() {
    // the seventh is the smallest
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodNoAlonePower() {
    // no single part has any power or effect alone
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPartsLookLikeBatons() {
    // singly each appears a short bar or baton
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodSeventhLooksLikeWand() {
    // the seventh looks much like a short metal wand
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodFirstSensesSecond() {
    // the first part senses the direction of the second
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodSensingNeedsWholeThought() {
    // sensing works only as a fraction of a whole
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodLeadsOnlyUpward() {
    // a found section leads only to the next higher numbered
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodOutOfOrderTouchTeleports() {
    // an out-of-order touch teleports the higher piece away
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodTeleportMinMiles() {
    // the out-of-order teleport minimum, in miles
    return 100;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodTeleportMaxMiles() {
    // the out-of-order teleport maximum, in miles
    return 1000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodAssembledLengthFeet() {
    // the fully assembled length, in feet
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodThreeSectionsGripLock() {
    // three fitted sections hold the grip for life
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPartPowersCumulative() {
    // the powers of each part are cumulative when joined
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodFullPowersNeedAllParts() {
    // the full powers work only when all parts are joined
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCannotBeDisassembled() {
    // the possessor cannot disassemble it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPrimeRiskDenominator() {
    // each prime power use: 1 in this many breakup risk
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodPrimeRiskPercent() {
    // the same breakup risk, in percent
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodBreakupTeleportMinMiles() {
    // the breakup teleport minimum, in miles
    return 100;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodBreakupTeleportMaxMiles() {
    // the breakup teleport maximum, in miles
    return 1200;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodOutOfOrderNotCumulative() {
    // out-of-order assembly: the powers are not cumulative
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodLastPieceJoinedActive() {
    // only the last piece joined stays active, prior negated
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodInOrderCumulative() {
    // in-order assembly is cumulative to the full powers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodAssemblyRowCount() {
    // the assembly powers table rows
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodAssemblyUseTotal() {
    // 1+1+1+1+1+1 - the assembly use total
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCompleteUseTotal() {
    // 1+1+2+2+1 - the complete rod use total
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCompleteOrderQuirk() {
    // the complete list prints table V before table IV
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCompleteLacksTableVI() {
    // no table VI slot, though the assembly has one
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodBlankSlotCount() {
    // the DM-fill blank slots, 6 assembly + 7 complete
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodBlankSlotUnderscores() {
    // the underscores per blank slot
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodJointTable(int i) {
    // the assembly joint tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 1, 1, 4, 2, 6,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodJointUseCount(int i) {
    // the assembly joint use counts; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 1, 1, 1, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapRodCompleteTableUse(int i) {
    // the complete rod uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 2, 1, 2, 0,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreCount() {
    // the 3 Sceptres of Might
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreSourceCrownOfMight() {
    // the legendary source: the Crown section
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreEvilBandLo() {
    // the evil ethos band, low die
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreEvilBandHi() {
    // the evil ethos band, high die
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreGoodBandLo() {
    // the good ethos band, low die
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreGoodBandHi() {
    // the good ethos band, high die
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreNeutralBandLo() {
    // the neutrality ethos band, low die
    return 15;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreNeutralBandHi() {
    // the neutrality ethos band, high die
    return 20;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreForeignEthosCrownEffects() {
    // a foreign-ethos touch works the Crown effects
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreBronzeInlaidSilver() {
    // wrought of bronze inlaid with silver
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreHugeStoneTipping() {
    // a huge precious stone tips it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreLengthFeet() {
    // the length, in feet
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreValueGp() {
    // the open market value, in gold pieces
    return 150000;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreRodOfBeguiling() {
    // it functions as a Rod of Beguiling
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreUseTotal() {
    // 1+1+1 - the use total
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreCrownOrbComboNote() {
    // combo powers with a same-ethos Crown or Orb
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreBlankSlotCount() {
    // the DM-fill blanks, 3 rows of 3 runs each
    return 9;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapSceptreTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 0, 0, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasOfVecnaTheLich() {
    // recorded of the lich Vecna
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasBodyguardRightHand() {
    // the bodyguard and right hand of Vecna
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasFlatchetDullGrayMetal() {
    // a long and thin flatchet of dull gray metal
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasSharpPointKeenEdges() {
    // sharp point, keen edges, magical properties
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasServedFaithfully() {
    // Kas faithfully served the lich
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasHubrisGrew() {
    // his power grew and so did his hubris
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasSwordUrgedHimOn() {
    // the Sword constantly urged him on
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasGreaterThanVecna() {
    // it said Kas was greater than Vecna himself
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasCouldRuleInVecnaStead() {
    // with it Kas could rule in Vecna stead
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasDestroyedVecna() {
    // legend: Kas and his Sword destroyed Vecna
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasDoomWroughtTogether() {
    // Vecna wrought the lieutenant doom too
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasWorldBrighter() {
    // the world was made brighter thereby
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasPowersOnlyHinted() {
    // the powers and effects are only hinted at
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasRenownedSwordsman() {
    // the most renowned swordsman of his age
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasPlusBonus() {
    // the enchantment plus of the +6 defender
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasDefender() {
    // it is a defender
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasDoubleDamageOffPlane() {
    // double damage to off-plane creatures
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasNormalDamageOnOtherPlanes() {
    // normal damage when on any other plane
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasShortSword() {
    // a short sword
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasEvilChaoticAlignment() {
    // highly evil and chaotic in alignment
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasIntelligence() {
    // the sword intelligence
    return 15;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasEgo() {
    // the sword ego
    return 19;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasTriesToControl() {
    // it attempts to control whoever takes it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasUseTotal() {
    // 5+2+1+2+2+1 - the use total
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasBlankSlotCount() {
    // the DM-fill blanks, one per use
    return 13;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasPrintsInOrder() {
    // the powers print in order I through VI
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapKasTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 2, 1, 2, 2, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothHistoriesSilent() {
    // no history tells of a cleric more
    // powerful than the renowned Dahlver-Nar
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothGodsGavePowers() {
    // the gods themselves gave the powers
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothRelicsAreTeeth() {
    // the great relics are his teeth
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothEachToothHasPower() {
    // each of the Teeth has some power
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothCount() {
    // the number of Teeth of Dahlver-Nar
    return 32;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothBenefitLevels() {
    // quarter, half, or all - 3 levels
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothQuarterCount() {
    // a full quarter of the teeth
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothHalfCount() {
    // half of the teeth
    return 16;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothGraftsInMouth() {
    // placed into the mouth to gain power
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothLikeMissingTooth() {
    // grafts in place of a like missing tooth
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothNeverRemoved() {
    // never removed once so emplaced
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothRemovalOnlyByDemise() {
    // removal only by the possessor demise
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothPowersCumulative() {
    // the powers and effects are cumulative
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothUseTotal() {
    // the tooth table use total, 32 teeth
    return 32;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableOneCount() {
    // the teeth of table I in the tooth table
    return 21;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableTwoCount() {
    // the II teeth: 2, 16, 24 and 28
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableThreeCount() {
    // the III teeth: 3, 9, 26 and 29
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableFourCount() {
    // the lone table IV tooth
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableFiveCount() {
    // the tooth table carries no table V
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableSixCount() {
    // the VI teeth: 7 and 14
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothLoneFourTooth() {
    // tooth 21 is the lone table IV tooth
    return 21;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothFirstSixTooth() {
    // tooth 7 is the first table VI tooth
    return 7;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSecondSixTooth() {
    // tooth 14 is the second table VI tooth
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothUnderscoreRunLen() {
    // every blank is a 14-underscore run
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothBlankSlotCount() {
    // 32 + 8 x 2 + 3 DM-fill blanks
    return 51;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothXSignCount() {
    // the true multiplication signs, 51
    return 51;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetPairRows() {
    // the 8 two-column set table rows
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetQuarterRows() {
    // the quarter rows: 1-8, 9-16,
    // 17-24 and 25-32
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetHalfRepeatQuarters() {
    // the half rows repeat the quarter rows
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetFiveRows() {
    // the V rows: 1-16, 17-32 and 1-32
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetLeftTwoCount() {
    // set table left column: 8 rows of II
    return 8;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetLeftFiveCount() {
    // set table left column: 3 rows of V
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetRightThreeCount() {
    // set table right column III entries
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetRightFourCount() {
    // set table right column IV entries
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetRightSixCount() {
    // set table right column VI entries
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothTableUse(int i) {
    // the teeth per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        21, 4, 4, 1, 0, 2,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapToothSetRightUse(int i) {
    // right-column sets per I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        0, 0, 4, 2, 0, 2,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneCarvenMountainHeart() {
    // carven from the heart of a majestic mountain
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneMassiveStoneChair() {
    // a massive stone chair
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneMosaicsIvoryMetals() {
    // inlaid with mosaics of ivory and metals
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneSetAboutGems() {
    // set about with gems
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneGodsActuallySat() {
    // certain gods actually sat on it
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneWithinGreatCavern() {
    // supposedly within a great cavern
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneImmobileImmovable() {
    // part of the mountain core, immovable
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneAffectsAnyoneSeated() {
    // anyone daring to seat is subject
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneCertainMagicItem() {
    // certain, per fables, to gain a magic item
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneMalevolentEffectToo() {
    // but subject to malevolent effect too
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneItemGainOnlyOnce() {
    // the same character cannot again gain
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneProperWordsGestures() {
    // the proper words and gestures, followed
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneGraspOptions() {
    // either arm, both, or none
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneUseTotal() {
    // 3+3+2+2+2+2 - the use total
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableOneCount() {
    // the uses of table I
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableTwoCount() {
    // the uses of table II
    return 3;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableThreeCount() {
    // the uses of table III
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableFourCount() {
    // the uses of table IV
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableFiveCount() {
    // the uses of table V
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableSixCount() {
    // the uses of table VI
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneBlankSlotCount() {
    // the DM-fill blanks, one per use
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneXSignCount() {
    // the true multiplication signs, 6
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneBulletLineCount() {
    // the Throne lines carry no bullets
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapThroneTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 2, 2, 2,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandDemonPrinceProperty() {
    // the ghastly weapon of the demon prince
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandPassesToPrimeMaterial() {
    // at times allowed to pass to the Prime
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandWreakChaosEvil() {
    // to wreak chaos and evil on the living
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandMonsterManualRef() {
    // see MONSTER MANUAL, Demon, Orcus
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandSavingThrowVersusMagic() {
    // the victim saves versus magic
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandAvoidsDeathAnnihilation() {
    // to avoid death or annihilation
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandImmuneCount() {
    // gods, godlings, demon lords, greater
    // devils, saints, demi-gods - 6 ranks
    return 6;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandUseTotal() {
    // 4+2+2+1+0+1 - the use total
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableOneCount() {
    // the uses of table I
    return 4;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableTwoCount() {
    // the uses of table II
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableThreeCount() {
    // the uses of table III
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableFourCount() {
    // the uses of table IV
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableFiveCount() {
    // the Wand prints no table V line
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableSixCount() {
    // the uses of table VI
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandBlankSlotCount() {
    // the DM-fill blanks, one per use
    return 10;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandXSignCount() {
    // the true multiplication signs, 5
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandBulletLineCount() {
    // all 5 Wand table lines carry bullets
    return 5;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandFourOneSpaceSeparator() {
    // the 4 x I line joins runs 3 and 4
    // with a space, not a comma
    return 1;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandFourOneCommaCount() {
    // only 2 commas on the 4 x I line
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapWandTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 2, 1, 0, 1,
    };
    return t[i];
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalXSignCount() {
    // the round total of true x-signs
    return 11;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalBlankRunCount() {
    // the round total of DM-fill blanks
    return 24;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalUnderscoreRunLen() {
    // every blank is a 14-underscore run
    return 14;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalCurlyApostropheCount() {
    // the mountain core, the Throne magic
    return 2;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalEmDashCount() {
    // the section prints no em dashes
    return 0;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalPageSeamLine() {
    // the absorbed running head, part2 line
    return 1797;
}

int Specart_axe_of_the_dwarvish_lords_to_codex::sapFinalSpecialDescriptionCount() {
    // the 29 III.E Special descriptions
    return 29;
}
