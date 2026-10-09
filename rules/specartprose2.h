// ====================================================================
// Adnd1 - rules/specartprose2.h
// R281: the III.E Special artifacts explanation
// prose part 2 (DMG p.159-160) - the Axe of the
// Dwarvish Lords, the Baba Yaga Hut and the Codex
// of the Infinite Planes, part2 lines 1184-1235
// (global = 11065 + part2 line), the first three
// of the 29 artifact descriptions. The Axe pins:
// the blade equals a sword of sharpness; the head
// equals a +3 hammer; the handle extends or
// contracts on command to equal a battle or hand
// axe for throwing; the Axe returns 30 feet to its
// thrower; the possessor has dwarven abilities,
// doubled for a dwarf; the life span is 50 percent
// longer; the Axe supposedly bears a curse and was
// lost in the Invoked Devastation; powers 2 of
// table I and 1 each of tables II through VI. The
// Hut pins: 15 feet diameter, 10 feet high; two
// fowl legs 12 feet long; infravision 120 feet;
// 30 rooms on 3 floors; movement 48 inches over
// swamp, 36 over rough or normal terrain and 12
// over hills; obeys commands from 1 key-phrase
// commander; comes to a call from 1 league; the
// legs strike as a hill giant, 2 attacks per
// round, armor class 2, 48 hit points each,
// regenerating 1 per round; 5 foot granite walls;
// powers 4 of table I, 2 of table II, 1 each of
// III through VI. The Codex pins: 99 damned
// pages; 99 percent certain doom at 1 percent
// cumulative per page; keys to instant
// transference to any plane; destroys any
// character under 11th level on touch; 11th or
// higher save versus magic to command; powers 4
// each of tables I and II, 2 each of III through
// VI; the powers activate per the progress of the
// perusal. This round has one seam restored: the
// p.159-160 page break splits the Codex paragraph
// between the 1216 tail (the work will destroy
// instantly any) and the 1221 head (character
// under 11th level) across the blank pair at
// 1217-1218, the TREASURE (ARTIFACTS & RELICS)
// running head at 1219 and the 1220 post-head
// blank. The upload quirks this round: the power
// lines print the counts as N x table with the
// true multiplication sign, 18 of them; the feet
// primes print as the curly right single quote
// and the inch primes as the curly right double
// quote; the Tzunk fragment prints curly quotes;
// the hit point/ melee round slash split carries
// a space - all pinned as plain digits and words,
// apostrophe-free here. 37 accessors: 33 scalars
// + 4 walkers (the three power-count walkers -
// 2,1,1,1,1,1 for the Axe, 4,2,1,1,1,1 for the
// Hut, 4,4,2,2,2,2 for the Codex - and the hut
// move walker 48, 36, 12), no name collisions
// with the miscprose and specart headers. The
// audit cross-pins the R240 sale table rows: the
// Axe band 01 at 55000, the Hut band 02 at
// 90000, the Codex band 03-04 at 62500. Pure
// data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int sapAxeBladeSharpness() {
    // the blade equals a sword of sharpness
    return 1;
}

inline int sapAxeHammerBonus() {
    // the head equals a +3 hammer
    return 3;
}

inline int sapAxeHandleForms() {
    // the handle equals a battle or hand axe
    return 2;
}

inline int sapAxeReturnFeet() {
    // returns 30 feet to its thrower
    return 30;
}

inline int sapAxeDwarfAbilityMultiplier() {
    // dwarven abilities doubled for a dwarf
    return 2;
}

inline int sapAxeLifespanBonusPct() {
    // the life span is 50 percent longer
    return 50;
}

inline int sapAxeBearsCurse() {
    // the Axe supposedly bears a curse
    return 1;
}

inline int sapAxeInvokedDevastationLost() {
    // lost in the Invoked Devastation centuries gone
    return 1;
}

inline int sapAxePowerTotal() {
    // 2 of table I plus 1 each of tables II-VI
    return 7;
}

inline int sapAxePowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapHutDiameterFeet() {
    // a circular thatched structure of 15 feet
    return 15;
}

inline int sapHutHeightFeet() {
    // 10 feet high
    return 10;
}

inline int sapHutLegCount() {
    // two powerful fowl legs
    return 2;
}

inline int sapHutLegLengthFeet() {
    // the legs are 12 feet long stilts
    return 12;
}

inline int sapHutInfravisionFeet() {
    // infravisual ability to 120 feet
    return 120;
}

inline int sapHutRoomCount() {
    // 30 rooms on 3 floors, all furnished
    return 30;
}

inline int sapHutFloorCount() {
    // the 30 rooms sit on 3 floors
    return 3;
}

inline int sapHutMoveTerrainCount() {
    // swamp, rough or normal, hills and forests
    return 3;
}

inline int sapHutMoveInches(int i) {
    // move per terrain; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        48, 36, 12,
    };
    return t[i];
}

inline int sapHutCommanderCount() {
    // obeys the one first using a key phrase
    return 1;
}

inline int sapHutCallRangeLeagues() {
    // comes to a call from 1 league away
    return 1;
}

inline int sapHutLegAttacksPerRound() {
    // the legs deliver blows, 2 attacks per round
    return 2;
}

inline int sapHutLegArmorClass() {
    // the legs are armor class 2
    return 2;
}

inline int sapHutLegHpEach() {
    // the legs take 48 hit points damage each
    return 48;
}

inline int sapHutLegRegenPerRound() {
    // regenerating at 1 hit point per round
    return 1;
}

inline int sapHutWallGraniteFeet() {
    // the walls equal 5 feet thick granite
    return 5;
}

inline int sapHutLegsHillGiantBlows() {
    // the leg blows equal those of a hill giant
    return 1;
}

inline int sapHutPowerTotal() {
    // 4 of I, 2 of II, 1 each of III-VI
    return 10;
}

inline int sapHutPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapCodexDamnedPages() {
    // any person reading its 99 damned pages
    return 99;
}

inline int sapCodexDoomChancePct() {
    // 99 percent certain to meet a terrible fate
    return 99;
}

inline int sapCodexPerilPerPagePct() {
    // 1 percent cumulative chance per page
    return 1;
}

inline int sapCodexTouchKillBelowLevel() {
    // destroys any character under 11th level
    return 11;
}

inline int sapCodexCommandMinLevel() {
    // 11th or higher save versus magic to command
    return 11;
}

inline int sapCodexPerusalActivation() {
    // powers activate per the progress of perusal
    return 1;
}

inline int sapCodexPowerTotal() {
    // 4 each of I-II, 2 each of III-VI
    return 16;
}

inline int sapCodexPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 4, 2, 2, 2, 2,
    };
    return t[i];
}

inline int sapCrownRegaliaSetCount() {
    // these 3 complete sets bestow great powers
    return 3;
}

inline int sapCrownItemsPerSet() {
    // a crown, an orb and a sceptre per champion
    return 3;
}

inline int sapCrownChampionEthosCount() {
    // the champion of each ethic alignment
    return 3;
}

inline int sapCrownPossessionBenefits() {
    // mere possession benefits a same-ethos character
    return 1;
}

inline int sapCrownWrongEthosDamageMin() {
    // a wrong-ethos touch deals 5-30 hit points
    return 5;
}

inline int sapCrownWrongEthosDamageMax() {
    // the upper edge of the 5-30 hit points
    return 30;
}

inline int sapCrownWrongEthosSaveOrDeath() {
    // save versus magic or be instantly killed
    return 1;
}

inline int sapCrownWearerLevelBonus() {
    // raises the level of experience by 1 while worn
    return 1;
}

inline int sapCrownWornPowerTotal() {
    // 2 of table I plus 1 each of tables II-III
    return 4;
}

inline int sapCrownOffEthosMalevolentCount() {
    // 1 malevolent power on a successful save
    return 1;
}

inline int sapCrownOffEthosMalevolentTable() {
    // the malevolent power comes from table IV
    return 4;
}

inline int sapCrownSet2ndPowerTotal() {
    // the same-ethos 2nd item adds 1 each of I-II
    return 2;
}

inline int sapCrownSet3rdPowerTotal() {
    // the 3rd item adds 1 each of I, II, IV-VI
    return 5;
}

inline int sapCrownDetectionRevealsAlignment() {
    // detection magically will not reveal the alignment
    return 0;
}

inline int sapCrownGemCount() {
    // set with 3 precious stones of great size
    return 3;
}

inline int sapCrownSaleGpMin() {
    // 50,000 or more gold pieces if openly sold
    return 50000;
}

inline int sapCrownAlignBandLo(int i) {
    // the alignment band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 7, 15,
    };
    return t[i];
}

inline int sapCrownAlignBandHi(int i) {
    // the alignment band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        6, 14, 20,
    };
    return t[i];
}

inline int sapCrownWornPowerCount(int i) {
    // the worn powers per tables I-III; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        2, 1, 1,
    };
    return t[i];
}

inline int sapCrownSet2ndPowerCount(int i) {
    // the 2nd item powers per tables I-II; i clamps
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    static const int t[2] = {
        1, 1,
    };
    return t[i];
}

inline int sapCrownSet3rdPowerCount(int i) {
    // the 3rd item powers per I, II, IV-VI; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapCrystalOriginUnknown() {
    // the origin and whereabouts entirely unknown
    return 1;
}

inline int sapCrystalDiamondHard() {
    // a diamond-hard mineral the size of a hand
    return 1;
}

inline int sapCrystalTouchRaysBlackFlame() {
    // touched it sends rays, a black flame leaps
    return 1;
}

inline int sapCrystalCharmRadiusFeet() {
    // all creatures within 30 feet save versus magic
    return 30;
}

inline int sapCrystalCharmIsFireCharm() {
    // or charmed as if by a fire charm spell
    return 1;
}

inline int sapCrystalPowersByGazing() {
    // powers drawn by gazing at the Ebon Flame
    return 1;
}

inline int sapCrystalPowerTotal() {
    // 4 of table I, 2 of II, 1 each of III-VI
    return 10;
}

inline int sapCrystalPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapCupTalismanRelicCount() {
    // a pair of holy relics
    return 2;
}

inline int sapCupTalismanPaynimGift() {
    // given by the gods of the Paynims to the
    // most exalted high priest of lawful good
    return 1;
}

inline int sapCupTalismanInvokedDevastationEra() {
    // in the days following the Invoked Devastation
    return 1;
}

inline int sapCupTalismanLostToRaiders() {
    // lost to demi-human raiders, rumored Southeastern
    return 1;
}

inline int sapCupTalismanPotionClassCount() {
    // a cleric, druid, paladin or ranger possessing both
    return 4;
}

inline int sapCupTalismanPotionPerWeek() {
    // may create a potion once per week
    return 1;
}

inline int sapCupGemCount() {
    // set with 12 great gems in electrum settings
    return 12;
}

inline int sapCupJewelryGpMin() {
    // a jewelry value of 75,000 or more gold pieces
    return 75000;
}

inline int sapCupRadiatesMagic() {
    // the Cup does not radiate magic
    return 0;
}

inline int sapCupPowerTotal() {
    // 4 of table I plus 1 of table III
    return 5;
}

inline int sapCupPowerCount(int i) {
    // the cup powers per tables I-III; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        4, 0, 1,
    };
    return t[i];
}

inline int sapTalismanPointCount() {
    // a star of 8 points
    return 8;
}

inline int sapTalismanPointGemCount() {
    // a small gem tipping each point
    return 8;
}

inline int sapTalismanBeadSetCount() {
    // 8 sets of 3 beads each on the chain
    return 8;
}

inline int sapTalismanBeadsPerSet() {
    // silver beading, 8 sets of 3 beads each
    return 3;
}

inline int sapTalismanJewelryGpMin() {
    // a jewelry value of 10,000 or more gold pieces
    return 10000;
}

inline int sapTalismanRadiatesMagic() {
    // the Talisman does not radiate magic either
    return 0;
}

inline int sapTalismanPowerTotal() {
    // 2 of table II plus 1 of table IV
    return 3;
}

inline int sapTalismanPowerCount(int i) {
    // the talisman powers per tables I-IV; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 2, 0, 1,
    };
    return t[i];
}

inline int sapCupTalismanBothPowerTotal() {
    // 1 each of tables V and VI from both
    return 2;
}

inline int sapCupTalismanBothPowerCount(int i) {
    // the both powers per tables V-VI; i clamps
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    static const int t[2] = {
        1, 1,
    };
    return t[i];
}

inline int sapCupTalismanPotionBandCount() {
    // the six bands of the potion table
    return 6;
}

inline int sapCupTalismanPotionBandLo(int i) {
    // the potion band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 11, 16, 18, 20,
    };
    return t[i];
}

inline int sapCupTalismanPotionBandHi(int i) {
    // the potion band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 10, 15, 17, 19, 20,
    };
    return t[i];
}

inline int sapEyeVecnaPhantomRoams() {
    // the phantom of the once supreme lich roams
    return 1;
}

inline int sapEyeDoomSurvivors() {
    // one eye and one hand survived his doom
    return 2;
}

inline int sapEyeFeralGlow() {
    // glows in the same manner as a feral creature
    return 1;
}

inline int sapEyeAppearsAgate() {
    // appears an agate until placed in an eye socket
    return 1;
}

inline int sapEyeGraftIrrevocable() {
    // grafts irrevocably, removed only by slaying
    return 1;
}

inline int sapEyeHostNeutralEvil() {
    // the host alignment becomes neutral evil, never changes
    return 1;
}

inline int sapEyeGrantsInfravision() {
    // the Eye bestows infravision to its host
    return 1;
}

inline int sapEyeGrantsUltravision() {
    // the Eye bestows ultravision to its host
    return 1;
}

inline int sapEyePowerTotal() {
    // 2 each of I-II, 1 each of IV-V (III skipped)
    return 6;
}

inline int sapEyePowerCount(int i) {
    // the powers per tables I-V; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        2, 2, 0, 1, 1,
    };
    return t[i];
}

inline int sapEyePrimaryPowerMalevolent() {
    // the primary power causes a malevolent effect
    return 1;
}

inline int sapHandVecnaLeftHand() {
    // his left hand, imbued with powers
    return 1;
}

inline int sapHandMummifiedExtremity() {
    // a blackened, shriveled mummified extremity
    return 1;
}

inline int sapHandGripStrength() {
    // a functioning member with 18/00 strength
    return 18;
}

inline int sapHandGripStrengthRating() {
    // the printed 00 rating of the 18/00 grip
    return 0;
}

inline int sapHandGripHitOrDamageBonus() {
    // no to hit or damage bonuses
    return 0;
}

inline int sapHandHostTurnsNeutralEvil() {
    // the host eventually turns neutral evil
    return 1;
}

inline int sapHandMajorPowerWakesSpirit() {
    // a major power use wakes a spirit of great evil
    return 1;
}

inline int sapHandPrimaryPowerInstantEvil() {
    // a primary power: instantly neutral evil
    return 1;
}

inline int sapHandSeverBaseChancePct() {
    // severed before powers used, 100 percent certainty
    return 100;
}

inline int sapHandSeverMajorPenaltyPct() {
    // each major power use subtracts 1 percent
    return 1;
}

inline int sapHandSeverPrimaryPenaltyPct() {
    // each primary power use: 10 percent less likely
    return 10;
}

inline int sapHandNoRemovalAtLimit() {
    // at 100 percent subtraction no removal, the host knows
    return 1;
}

inline int sapHandFingerCombinations() {
    // powers work through extended or curled fingers
    return 1;
}

inline int sapHandPowerTotal() {
    // 10 of I, 5 of II, 2 each of III-V, 1 of VI
    return 22;
}

inline int sapHandPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        10, 5, 2, 2, 2, 1,
    };
    return t[i];
}

inline int sapHandGodsOnlyAlteration() {
    // only the most powerful of gods can alter the effects
    return 1;
}

inline int sapHandRecordCombinations() {
    // the note: devise and record the position chart
    return 1;
}

inline int sapOrganPipeCount() {
    // 77 great and small pipes
    return 77;
}

inline int sapOrganStopCount() {
    // the console keys beneath 13 ivory stops
    return 13;
}

inline int sapOrganPedalCount() {
    // 3 great foot pedals
    return 3;
}

inline int sapOrganBellowsElemental() {
    // the bellows worked by a chained air elemental
    return 1;
}

inline int sapOrganStopsVaryVoice() {
    // each stop sounds the pipes in a new voice
    return 1;
}

inline int sapOrganKeysVaryNotes() {
    // the keys vary the notes
    return 1;
}

inline int sapOrganPedalPurposeUnknown() {
    // no one is certain what the pedals serve
    return 1;
}

inline int sapOrganStillWorksDespiteTime() {
    // despite silenced pipes it works mighty magicks
    return 1;
}

inline int sapOrganWrongStopsSummon() {
    // wrong stops summon the undesired or wrong spell
    return 1;
}

inline int sapOrganWrongKeysBackfire() {
    // wrong keys unbind or the magic backfires
    return 1;
}

inline int sapOrganMisplayAlignment() {
    // improper playing may change the alignment
    return 1;
}

inline int sapOrganDmAssignsStopsKeys() {
    // the DM decides the stops and key sequences
    return 1;
}

inline int sapOrganPowerTotal() {
    // 7+7+3+7+7+3 - the total power count
    return 34;
}

inline int sapOrganMisplayNegates() {
    // misplaying negates, reverses, changes effects
    return 1;
}

inline int sapHornResemblesCommonHorns() {
    // exactly resembles horns of blasting, bubbles
    return 1;
}

inline int sapHornSuggestedPowerPct() {
    // the suggested 75 percent power share
    return 75;
}

inline int sapHornSuggestedEffectPct() {
    // the suggested 25 percent effect share
    return 25;
}

inline int sapHornIgnoresInappropriate() {
    // inappropriate results are ignored
    return 1;
}

inline int sapCoatArndOfTdon() {
    // the High Priest Arnd of Tdon possessed it
    return 1;
}

inline int sapCoatChainLinksWeightless() {
    // a shimmering shirt of almost weightless links
    return 1;
}

inline int sapCoatCoveredAreaCount() {
    // covers upper arms, torso and groin
    return 3;
}

inline int sapCoatMinWearerHeightFt() {
    // the minimum 3 foot human-shaped wearer
    return 3;
}

inline int sapCoatMaxWearerHeightFt() {
    // the maximum 8 foot human-shaped wearer
    return 8;
}

inline int sapCoatInvulnerableCovered() {
    // totally invulnerable on covered areas
    return 1;
}

inline int sapCoatUncoveredAc() {
    // AC 5 protection on all other areas
    return 5;
}

inline int sapCoatSaveBonus() {
    // +5 to saving throws as +5 magic armor
    return 5;
}

inline int sapCoatFireResistance() {
    // fire protection as a ring of fire resistance
    return 1;
}

inline int sapCoatElementalImmunityCount() {
    // acid, cold and electrical attacks: no effect
    return 3;
}

inline int sapCoatPowerTotal() {
    // 3+2+2+1+1+1 - the total power count
    return 10;
}

inline int sapOrganPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 7, 3, 7, 7, 3,
    };
    return t[i];
}

inline int sapHornBlastPowerTable(int i) {
    // the power table per 1, 2 or 3 blasts; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 2, 5,
    };
    return t[i];
}

inline int sapHornBlastEffectTable(int i) {
    // the effect table per 1, 2 or 3 blasts; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 6, 4,
    };
    return t[i];
}

inline int sapCoatPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 2, 1, 1, 1,
    };
    return t[i];
}

inline int sapFlaskHeavyUrn() {
    // a small and heavy urn, easily carried
    return 1;
}

inline int sapFlaskTurnipPlug() {
    // stoppered with a turnip-shaped plug
    return 1;
}

inline int sapFlaskSigilRunes() {
    // engraved with sigils, glyphs, runes
    return 1;
}

inline int sapFlaskWordCount() {
    // opening, command, closing and sealing
    return 3;
}

inline int sapFlaskPrisonerCount() {
    // the 5 rumored prisoners within
    return 5;
}

inline int sapFlaskServantEvilOnly() {
    // the Servant loosed only for evil deeds
    return 1;
}

inline int sapFlaskKillBeforeReturn() {
    // it must kill before returning to prison
    return 1;
}

inline int sapFlaskPowerTotal() {
    // 3+0+1+0+1+1 - the total power count
    return 6;
}

inline int sapJacinthGodFashioned() {
    // fashioned by the gods themselves
    return 1;
}

inline int sapJacinthMountainHeart() {
    // the finest corundum from the mountain heart
    return 1;
}

inline int sapJacinthFacetedBeams() {
    // dozens of facets shoot brilliant beams
    return 1;
}

inline int sapJacinthCharmRangeFt() {
    // within 20 feet save vs magic or charmed
    return 20;
}

inline int sapJacinthSultanPossessed() {
    // Sultan Jehef Pehreen possessed it
    return 1;
}

inline int sapJacinthKeolandTrailLost() {
    // into Ket and Keoland, all trace lost
    return 1;
}

inline int sapJacinthGraspPowers() {
    // the possessor firmly grasps the gem
    return 1;
}

inline int sapJacinthPowerTotal() {
    // 2+2+1+1+1+1 - the total power count
    return 8;
}

inline int sapMaskJohydeeTrickedEvil() {
    // the priestess tricked the powers of evil
    return 1;
}

inline int sapMaskOverthrewNation() {
    // used to overthrow their hold on her nation
    return 1;
}

inline int sapMaskCoversFace() {
    // covers the whole face of the wearer
    return 1;
}

inline int sapMaskAssumeLikeness() {
    // assume the likeness of any human-like creature
    return 1;
}

inline int sapMaskBlocksMindContact() {
    // blocks all mind contact, detection, attack
    return 1;
}

inline int sapMaskGazeImmunity() {
    // total immunity to all gaze attacks
    return 1;
}

inline int sapMaskGazeCreatureCount() {
    // basilisk, catoblepas and medusa
    return 3;
}

inline int sapMaskPowerTotal() {
    // 2+1+0+0+0+1 - the total power count
    return 4;
}

inline int sapFlaskPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 0, 1, 0, 1, 1,
    };
    return t[i];
}

inline int sapJacinthPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapMaskPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 0, 0, 0, 1,
    };
    return t[i];
}

inline int sapQuillMasterThiefBest() {
    // the master thief, most successful of his kind
    return 1;
}

inline int sapQuillUnknownAntiquity() {
    // a writing instrument of unknown antiquity
    return 1;
}

inline int sapQuillBearsKurothName() {
    // it now bears the name of Kuroth
    return 1;
}

inline int sapQuillInfallibleScribe() {
    // draws and writes infallibly upon command
    return 1;
}

inline int sapQuillDepictsSeenSpoken() {
    // depicts what its possessor sees or speaks
    return 1;
}

inline int sapQuillPotionTreasureFinding() {
    // it finds treasure as the potion does
    return 1;
}

inline int sapQuillTreasureFindPerMonth() {
    // the treasure finding, times per month
    return 1;
}

inline int sapQuillPowerTotal() {
    // 2+0+1+1+0+1 - the total power count
    return 5;
}

inline int sapQuillPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 0, 1, 1, 0, 1,
    };
    return t[i];
}

inline int sapMaceSaintCuthbertWeapon() {
    // actually used by the Venerable Saint Cuthbert
    return 1;
}

inline int sapMaceFollyOfError() {
    // demonstrated the folly of error to the unbeliever
    return 1;
}

inline int sapMaceRelicsEncased() {
    // holy relics of the Saint encased within
    return 1;
}

inline int sapMaceHitDamageBonus() {
    // the bonus for both hitting and damage
    return 5;
}

inline int sapMaceDisruptionEffects() {
    // it also has disruption effects
    return 1;
}

inline int sapMaceClericStrReq() {
    // wieldable only by clerics of this strength
    return 18;
}

inline int sapMaceLawfulGoodOnly() {
    // the wielder must be of lawful good alignment
    return 1;
}

inline int sapMacePowerTotal() {
    // 3+2+0+0+0+1 - the total power count
    return 6;
}

inline int sapMacePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 0, 0, 0, 1,
    };
    return t[i];
}

inline int sapMachineGodsForgotten() {
    // perhaps built by gods long forgotten
    return 1;
}

inline int sapMachineWorkmanshipUnknown() {
    // workmanship unlike anything known today
    return 1;
}

inline int sapMachineBaronLumEmpire() {
    // used by Baron Lum to build an empire
    return 1;
}

inline int sapMachineLeverCount() {
    // the number of levers it has
    return 60;
}

inline int sapMachineDialCount() {
    // the number of dials it has
    return 40;
}

inline int sapMachineSwitchCount() {
    // the number of switches it has
    return 20;
}

inline int sapMachineControlsTotal() {
    // levers + dials + switches
    return 120;
}

inline int sapMachineHalfFunction() {
    // about one-half of the controls still function
    return 60;
}

inline int sapMachineWeightLb() {
    // bulky and very heavy, in pounds
    return 5500;
}

inline int sapMachineJoltDestroyMax() {
    // a serious jolt destroys up to this many
    return 4;
}

inline int sapMachineBoothCreatures() {
    // the booth fits this many man-sized creatures
    return 4;
}

inline int sapMachinePowerTotal() {
    // 15+15+10+10+15+5 - the total power count
    return 70;
}

inline int sapMachinePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        15, 15, 10, 10, 15, 5,
    };
    return t[i];
}

inline int sapServantLumSameMake() {
    // the same manufacture as the Machine of Lum
    return 1;
}

inline int sapServantAutomatonHeightFt() {
    // it stands over this many feet tall
    return 9;
}

inline int sapServantDepthFt() {
    // it is this many feet deep
    return 6;
}

inline int sapServantWidthFt() {
    // some 4 and one-half feet wide
    return 4;
}

inline int sapServantInsideRiders() {
    // the compartment holds this many man-sized
    return 2;
}

inline int sapServantOutsideSittersMin() {
    // 4 to 5 others may sit outside
    return 4;
}

inline int sapServantCommandPhrases() {
    // the possessor must know the proper phrases
    return 1;
}

inline int sapServantUseCount() {
    // transportation, attack device, fighting machine
    return 3;
}

inline int sapServantArmorClass() {
    // armor class minus 1 (a true-minus quirk)
    return 1;
}

inline int sapServantHitPoints() {
    // it withstands this many hit points
    return 60;
}

inline int sapServantWeaponDamagePct() {
    // weapons do only this percent of normal
    return 50;
}

inline int sapServantRegenPerRound() {
    // it self-repairs this many points per round
    return 2;
}

inline int sapServantMagicResistPct() {
    // its magic resistance, in percent
    return 100;
}

inline int sapServantElementImmuneCount() {
    // acid cold fire heat vacuum water - no effect
    return 6;
}

inline int sapServantElectricalDamagePct() {
    // electrical attacks do only this percent
    return 20;
}

inline int sapServantSpeedInches() {
    // its maximum speed, in inches
    return 3;
}

inline int sapServantOperationHours() {
    // hours of operation before it must rest
    return 12;
}

inline int sapServantRestHours() {
    // it must rest this many hours
    return 1;
}

inline int sapServantPanicRangeInches() {
    // the intelligent-viewer panic range, in inches
    return 12;
}

inline int sapServantPanicSaveBonus() {
    // the bonus on the panic save die roll
    return 2;
}

inline int sapServantAttacksPerRound() {
    // it attacks but this many times per round
    return 1;
}

inline int sapServantBaseHitPct() {
    // the base chance to hit, in percent
    return 15;
}

inline int sapServantDexReduceFloor() {
    // per point of dexterity above this
    return 14;
}

inline int sapServantDexReducePct() {
    // 2 and one-half percent per point above
    return 2;
}

inline int sapServantDamageLowHp() {
    // the low end of a hit, in hit points
    return 10;
}

inline int sapServantDamageHighHp() {
    // the high end of a hit, in hit points
    return 100;
}

inline int sapServantObeysSecretLearners() {
    // it obeys those who learn its secrets
    return 1;
}

inline int sapServantPowerTotal() {
    // 6+6+1+2+0+2 - the total power count
    return 17;
}

inline int sapServantPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 6, 1, 2, 0, 2,
    };
    return t[i];
}

inline int sapOrbGoodDeitiesOrigin() {
    // the good deities conspired to devise it
    return 1;
}

inline int sapOrbDemonsCorrupted() {
    // demon servants changed the magic
    return 1;
}

inline int sapOrbGlobeCount() {
    // the globes of carven white jade
    return 8;
}

inline int sapOrbOnePerAge() {
    // 1 globe for each age of dragon life
    return 1;
}

inline int sapOrbSmallestInches() {
    // the smallest globe, in inches
    return 3;
}

inline int sapOrbLargestInches() {
    // the largest globe, in inches
    return 10;
}

inline int sapOrbBasReliefCovered() {
    // bas reliefs of entwined dragons cover it
    return 1;
}

inline int sapOrbDragonEssence() {
    // it holds the essence of all dragons
    return 1;
}

inline int sapOrbHatchlingIntelligence() {
    // the intelligence of the Hatchling
    return 9;
}

inline int sapOrbHatchlingEgo() {
    // the ego of the Hatchling
    return 9;
}

inline int sapOrbHatchlingPowerTotal() {
    // 3+0+0+0+0+0 - the total power count
    return 3;
}

inline int sapOrbHatchlingPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int sapOrbWyrmkinIntelligence() {
    // the intelligence of the Wyrmkin
    return 10;
}

inline int sapOrbWyrmkinEgo() {
    // the ego of the Wyrmkin
    return 10;
}

inline int sapOrbWyrmkinPowerTotal() {
    // 2+1+0+0+0+0 - the total power count
    return 3;
}

inline int sapOrbWyrmkinPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 0, 0, 0, 0,
    };
    return t[i];
}

inline int sapOrbDragonetteIntelligence() {
    // the intelligence of the Dragonette
    return 11;
}

inline int sapOrbDragonetteEgo() {
    // the ego of the Dragonette
    return 11;
}

inline int sapOrbDragonettePowerTotal() {
    // 3+1+1+0+0+0 - the total power count
    return 5;
}

inline int sapOrbDragonettePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 1, 1, 0, 0, 0,
    };
    return t[i];
}

inline int sapOrbDragonIntelligence() {
    // the intelligence of the Dragon
    return 12;
}

inline int sapOrbDragonEgo() {
    // the ego of the Dragon
    return 12;
}

inline int sapOrbDragonPowerTotal() {
    // 4+1+1+0+0+0 - the total power count
    return 6;
}

inline int sapOrbDragonPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 1, 1, 0, 0, 0,
    };
    return t[i];
}

inline int sapOrbGreatSerpentIntelligence() {
    // the intelligence of the Great Serpent
    return 13;
}

inline int sapOrbGreatSerpentEgo() {
    // the ego of the Great Serpent
    return 13;
}

inline int sapOrbGreatSerpentPowerTotal() {
    // 3+2+1+0+0+1 - the total power count
    return 7;
}

inline int sapOrbGreatSerpentPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 1, 0, 0, 1,
    };
    return t[i];
}

inline int sapOrbFiredrakeOldDragon() {
    // the possessor charms any old dragon
    return 1;
}

inline int sapOrbFiredrakeIntelligence() {
    // the intelligence of the Firedrake
    return 14;
}

inline int sapOrbFiredrakeEgo() {
    // the ego of the Firedrake
    return 14;
}

inline int sapOrbFiredrakePowerTotal() {
    // 3+3+2+0+0+1 - the total power count
    return 9;
}

inline int sapOrbFiredrakePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 0, 0, 1,
    };
    return t[i];
}

inline int sapOrbElderWyrmVeryOldDragon() {
    // the possessor charms any very old dragon
    return 1;
}

inline int sapOrbElderWyrmIntelligence() {
    // the intelligence of the Elder Wyrm
    return 16;
}

inline int sapOrbElderWyrmEgo() {
    // the ego of the Elder Wyrm
    return 16;
}

inline int sapOrbElderWyrmPowerTotal() {
    // 4+3+2+1+1+1 - the total power count
    return 12;
}

inline int sapOrbElderWyrmPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 3, 2, 1, 1, 1,
    };
    return t[i];
}

inline int sapOrbEternalAncientDragon() {
    // the possessor charms any ancient dragon
    return 1;
}

inline int sapOrbEternalTiamatBahamutBonus() {
    // saves, attacks and damage vs Tiamat or Bahamut
    return 8;
}

inline int sapOrbEternalIntelligence() {
    // the intelligence of the Eternal Grand Dragon
    return 18;
}

inline int sapOrbEternalEgo() {
    // the ego of the Eternal Grand Dragon
    return 18;
}

inline int sapOrbEternalPowerTotal() {
    // 4+3+2+1+2+1 - the total power count
    return 13;
}

inline int sapOrbEternalPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 3, 2, 1, 2, 1,
    };
    return t[i];
}

inline int sapOrbNotesEvilComponent() {
    // all of these Orbs have a strong evil component
    return 1;
}

inline int sapOrbNotesNeutralGoodResist() {
    // a neutral or good character saves vs magic to resist
    return 1;
}

inline int sapOrbNotesCharmRangeInches() {
    // the charm range, in inches
    return 5;
}

inline int sapOrbNotesCharmRounds() {
    // the charm requires this many full rounds
    return 1;
}

inline int sapOrbNotesAwakeAndAware() {
    // the subject must be fully awake and aware
    return 1;
}

inline int sapOrbNotesEvilAutoCharmed() {
    // only evil dragons are automatically charmed
    return 1;
}

inline int sapOrbNotesNeutralSavePenalty() {
    // the neutral dragon save penalty, as a magnitude
    return 4;
}

inline int sapOrbNotesGoodSavePenalty() {
    // the good dragon save penalty, as a magnitude
    return 2;
}

inline int sapOrbNotesCharmedWisdomPercent() {
    // charmed characters keep this percent of wisdom
    return 50;
}

inline int sapOrbNotesFeeblemindIntelligence() {
    // feeblemind leaves this intelligence
    return 3;
}

inline int sapOrbNotesInsanePercent() {
    // insanity leaves this percent of normal
    return 50;
}

inline int sapOrbNotesAwakeMindOnly() {
    // the Orb controls only an active and awake mind
    return 1;
}

inline int sapOrbNotesSacrificeDestruction() {
    // destruction by sacrifice to a dragon at hand
    return 1;
}

inline int sapOrbMightOrbCount() {
    // the 3 Orbs of Might
    return 3;
}

inline int sapOrbMightCrownSource() {
    // the legendary source - the foregoing Crown of Might
    return 1;
}

inline int sapOrbMightEvilDieLo() {
    // the evil ethos die band low edge
    return 1;
}

inline int sapOrbMightEvilDieHi() {
    // the evil ethos die band high edge
    return 6;
}

inline int sapOrbMightGoodDieLo() {
    // the good ethos die band low edge
    return 7;
}

inline int sapOrbMightGoodDieHi() {
    // the good ethos die band high edge
    return 14;
}

inline int sapOrbMightNeutralDieLo() {
    // the neutrality ethos die band low edge
    return 15;
}

inline int sapOrbMightNeutralDieHi() {
    // the neutrality ethos die band high edge
    return 20;
}

inline int sapOrbMightTouchDeathSave() {
    // another ethos touching one saves vs magic or dies
    return 1;
}

inline int sapOrbMightTouchDamageLo() {
    // the damage on a successful save, low edge
    return 4;
}

inline int sapOrbMightTouchDamageHi() {
    // the damage on a successful save, high edge
    return 24;
}

inline int sapOrbMightRegaliaTableFour() {
    // with Crown and/or Sceptre, a Table IV malevolence
    return 1;
}

inline int sapOrbMightPlatinumGems() {
    // platinum, gem-encrusted, precious device atop
    return 1;
}

inline int sapOrbMightValueGp() {
    // the open market worth, in gold pieces
    return 100000;
}

inline int sapOrbMightGemOfBrightness() {
    // each Orb equals a Gem of Brightness
    return 1;
}

inline int sapOrbMightPowerEthosCount() {
    // the power table ethos columns - evil, good, neutrality
    return 3;
}

inline int sapOrbMightPowerTotal() {
    // 2+0+1+0+0+0 - the total power count per ethos
    return 3;
}

inline int sapOrbMightPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 0, 1, 0, 0, 0,
    };
    return t[i];
}

inline int sapOrbMightRegaliaPowers() {
    // additional regalia powers - see the Crown of Might
    return 1;
}

inline int sapNightingaleMadeByXagy() {
    // Xagy is one of its makers
    return 1;
}

inline int sapNightingaleJoramyCoMaker() {
    // the volcano goddess Joramy is the other
    return 1;
}

inline int sapNightingaleMadeCenturiesAgo() {
    // Mordenkainen dated it this many centuries back
    return 17;
}

inline int sapNightingaleEhlissaBentAll() {
    // Queen Ehlissa bent all to her will
    return 1;
}

inline int sapNightingaleNeverEscaped() {
    // it never escaped its confinement
    return 1;
}

inline int sapNightingaleGoldenWireCage() {
    // held within a fine mesh of golden wires
    return 1;
}

inline int sapNightingaleWingsPerchPerform() {
    // wings open, hops to the perch, performs
    return 1;
}

inline int sapNightingaleEyeRays() {
    // its eyes shoot scintillating colored rays
    return 1;
}

inline int sapNightingaleSongWonders() {
    // its songs work magical wonders
    return 1;
}

inline int sapNightingaleRaySongSpells() {
    // rays and songs in combination weave spells
    return 1;
}

inline int sapNightingaleSphereRadiusFeet() {
    // the protective sphere radius, in feet
    return 30;
}

inline int sapNightingaleSphereBlocksScrying() {
    // no detection or magic or psionic intrusion
    return 1;
}

inline int sapNightingaleNoHungerThirst() {
    // those within neither hunger nor thirst
    return 1;
}

inline int sapNightingalePowerTotal() {
    // 4+0+1+1+1+1 - the total power count
    return 8;
}

inline int sapNightingalePowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 0, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapRecorderNeedsNoMusician() {
    // it needs no musician to play it
    return 1;
}

inline int sapRecorderPlaysOnCommand() {
    // plays the most complicated airs on command
    return 1;
}

inline int sapRecorderAlarmRadiusFeet() {
    // the stolen-goods alarm radius, in feet
    return 30;
}

inline int sapRecorderAlarmIncludesSelf() {
    // it alarms for itself stolen as well
    return 1;
}

inline int sapRecorderClueWordSongs() {
    // information through clue-word songs
    return 1;
}

inline int sapRecorderRumoredSpells() {
    // rumored to cast spells with its notes
    return 1;
}

inline int sapRecorderPowerTotal() {
    // 5+2+1+1+1+1 - the total power count
    return 11;
}

inline int sapRecorderPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapGaxxAlienOrigin() {
    // its origin is totally alien
    return 1;
}

inline int sapGaxxPlatinumLoopSpinel() {
    // a platinum loop about a fine spinel
    return 1;
}

inline int sapGaxxUnknownGemType() {
    // the workmanship unique, the gem unknown
    return 1;
}

inline int sapGaxxFingerDiscovery() {
    // donned on a finger to discover powers
    return 1;
}

inline int sapGaxxFacetCount() {
    // the nine-faceted gem
    return 9;
}

inline int sapGaxxFacingToTop() {
    // each facet powers when faced to the top
    return 1;
}

inline int sapGaxxTurnsItself() {
    // it turns itself off, on, or when asleep
    return 1;
}

inline int sapGaxxDailyRandomFacet() {
    // a random facet each day, secret to the DM
    return 1;
}

inline int sapGaxxFacetOrderKnown() {
    // one known facing reveals the order
    return 1;
}

inline int sapGaxxCannotBeMarked() {
    // unmarkable - even a wish will not help
    return 1;
}

inline int sapGaxxPowerTotal() {
    // 3+2+1+1+1+1 - the total power count
    return 9;
}

inline int sapGaxxPowerCount(int i) {
    // the powers per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapRodWindDukesMadeIt() {
    // the Wind Dukes of Aaqa are its legendary makers
    return 1;
}

inline int sapRodMadeForBattleOfPesh() {
    // constructed for the great battle of Pesh
    return 1;
}

inline int sapRodPeshChaosVersusLaw() {
    // at Pesh, Chaos and Law contended
    return 1;
}

inline int sapRodShatteredAtPesh() {
    // it was shattered there, its parts scattered
    return 1;
}

inline int sapRodNothingDestroysIt() {
    // nothing could actually destroy it
    return 1;
}

inline int sapRodCorrectOrderSurpassingPower() {
    // correct-order assembly gives surpassing power
    return 1;
}

inline int sapRodPartCount() {
    // the number of parts of the Rod
    return 7;
}

inline int sapRodPartsSlightlyDifferent() {
    // the parts are slightly different from each other
    return 1;
}

inline int sapRodFirstLargestLengthDiameter() {
    // the first is largest in length and diameter
    return 1;
}

inline int sapRodSeventhSmallest() {
    // the seventh is the smallest
    return 1;
}

inline int sapRodNoAlonePower() {
    // no single part has any power or effect alone
    return 1;
}

inline int sapRodPartsLookLikeBatons() {
    // singly each appears a short bar or baton
    return 1;
}

inline int sapRodSeventhLooksLikeWand() {
    // the seventh looks much like a short metal wand
    return 1;
}

inline int sapRodFirstSensesSecond() {
    // the first part senses the direction of the second
    return 1;
}

inline int sapRodSensingNeedsWholeThought() {
    // sensing works only as a fraction of a whole
    return 1;
}

inline int sapRodLeadsOnlyUpward() {
    // a found section leads only to the next higher numbered
    return 1;
}

inline int sapRodOutOfOrderTouchTeleports() {
    // an out-of-order touch teleports the higher piece away
    return 1;
}

inline int sapRodTeleportMinMiles() {
    // the out-of-order teleport minimum, in miles
    return 100;
}

inline int sapRodTeleportMaxMiles() {
    // the out-of-order teleport maximum, in miles
    return 1000;
}

inline int sapRodAssembledLengthFeet() {
    // the fully assembled length, in feet
    return 5;
}

inline int sapRodThreeSectionsGripLock() {
    // three fitted sections hold the grip for life
    return 1;
}

inline int sapRodPartPowersCumulative() {
    // the powers of each part are cumulative when joined
    return 1;
}

inline int sapRodFullPowersNeedAllParts() {
    // the full powers work only when all parts are joined
    return 1;
}

inline int sapRodCannotBeDisassembled() {
    // the possessor cannot disassemble it
    return 1;
}

inline int sapRodPrimeRiskDenominator() {
    // each prime power use: 1 in this many breakup risk
    return 20;
}

inline int sapRodPrimeRiskPercent() {
    // the same breakup risk, in percent
    return 5;
}

inline int sapRodBreakupTeleportMinMiles() {
    // the breakup teleport minimum, in miles
    return 100;
}

inline int sapRodBreakupTeleportMaxMiles() {
    // the breakup teleport maximum, in miles
    return 1200;
}

inline int sapRodOutOfOrderNotCumulative() {
    // out-of-order assembly: the powers are not cumulative
    return 1;
}

inline int sapRodLastPieceJoinedActive() {
    // only the last piece joined stays active, prior negated
    return 1;
}

inline int sapRodInOrderCumulative() {
    // in-order assembly is cumulative to the full powers
    return 1;
}

inline int sapRodAssemblyRowCount() {
    // the assembly powers table rows
    return 6;
}

inline int sapRodAssemblyUseTotal() {
    // 1+1+1+1+1+1 - the assembly use total
    return 6;
}

inline int sapRodCompleteUseTotal() {
    // 1+1+2+2+1 - the complete rod use total
    return 7;
}

inline int sapRodCompleteOrderQuirk() {
    // the complete list prints table V before table IV
    return 1;
}

inline int sapRodCompleteLacksTableVI() {
    // no table VI slot, though the assembly has one
    return 1;
}

inline int sapRodBlankSlotCount() {
    // the DM-fill blank slots, 6 assembly + 7 complete
    return 13;
}

inline int sapRodBlankSlotUnderscores() {
    // the underscores per blank slot
    return 11;
}

inline int sapRodJointTable(int i) {
    // the assembly joint tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 1, 1, 4, 2, 6,
    };
    return t[i];
}

inline int sapRodJointUseCount(int i) {
    // the assembly joint use counts; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapRodCompleteTableUse(int i) {
    // the complete rod uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 2, 1, 2, 0,
    };
    return t[i];
}

inline int sapSceptreCount() {
    // the 3 Sceptres of Might
    return 3;
}

inline int sapSceptreSourceCrownOfMight() {
    // the legendary source: the Crown section
    return 1;
}

inline int sapSceptreEvilBandLo() {
    // the evil ethos band, low die
    return 1;
}

inline int sapSceptreEvilBandHi() {
    // the evil ethos band, high die
    return 6;
}

inline int sapSceptreGoodBandLo() {
    // the good ethos band, low die
    return 7;
}

inline int sapSceptreGoodBandHi() {
    // the good ethos band, high die
    return 14;
}

inline int sapSceptreNeutralBandLo() {
    // the neutrality ethos band, low die
    return 15;
}

inline int sapSceptreNeutralBandHi() {
    // the neutrality ethos band, high die
    return 20;
}

inline int sapSceptreForeignEthosCrownEffects() {
    // a foreign-ethos touch works the Crown effects
    return 1;
}

inline int sapSceptreBronzeInlaidSilver() {
    // wrought of bronze inlaid with silver
    return 1;
}

inline int sapSceptreHugeStoneTipping() {
    // a huge precious stone tips it
    return 1;
}

inline int sapSceptreLengthFeet() {
    // the length, in feet
    return 2;
}

inline int sapSceptreValueGp() {
    // the open market value, in gold pieces
    return 150000;
}

inline int sapSceptreRodOfBeguiling() {
    // it functions as a Rod of Beguiling
    return 1;
}

inline int sapSceptreUseTotal() {
    // 1+1+1 - the use total
    return 3;
}

inline int sapSceptreCrownOrbComboNote() {
    // combo powers with a same-ethos Crown or Orb
    return 1;
}

inline int sapSceptreBlankSlotCount() {
    // the DM-fill blanks, 3 rows of 3 runs each
    return 9;
}

inline int sapSceptreTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 0, 0, 0, 1,
    };
    return t[i];
}

inline int sapKasOfVecnaTheLich() {
    // recorded of the lich Vecna
    return 1;
}

inline int sapKasBodyguardRightHand() {
    // the bodyguard and right hand of Vecna
    return 1;
}

inline int sapKasFlatchetDullGrayMetal() {
    // a long and thin flatchet of dull gray metal
    return 1;
}

inline int sapKasSharpPointKeenEdges() {
    // sharp point, keen edges, magical properties
    return 1;
}

inline int sapKasServedFaithfully() {
    // Kas faithfully served the lich
    return 1;
}

inline int sapKasHubrisGrew() {
    // his power grew and so did his hubris
    return 1;
}

inline int sapKasSwordUrgedHimOn() {
    // the Sword constantly urged him on
    return 1;
}

inline int sapKasGreaterThanVecna() {
    // it said Kas was greater than Vecna himself
    return 1;
}

inline int sapKasCouldRuleInVecnaStead() {
    // with it Kas could rule in Vecna stead
    return 1;
}

inline int sapKasDestroyedVecna() {
    // legend: Kas and his Sword destroyed Vecna
    return 1;
}

inline int sapKasDoomWroughtTogether() {
    // Vecna wrought the lieutenant doom too
    return 1;
}

inline int sapKasWorldBrighter() {
    // the world was made brighter thereby
    return 1;
}

inline int sapKasPowersOnlyHinted() {
    // the powers and effects are only hinted at
    return 1;
}

inline int sapKasRenownedSwordsman() {
    // the most renowned swordsman of his age
    return 1;
}

inline int sapKasPlusBonus() {
    // the enchantment plus of the +6 defender
    return 6;
}

inline int sapKasDefender() {
    // it is a defender
    return 1;
}

inline int sapKasDoubleDamageOffPlane() {
    // double damage to off-plane creatures
    return 1;
}

inline int sapKasNormalDamageOnOtherPlanes() {
    // normal damage when on any other plane
    return 1;
}

inline int sapKasShortSword() {
    // a short sword
    return 1;
}

inline int sapKasEvilChaoticAlignment() {
    // highly evil and chaotic in alignment
    return 1;
}

inline int sapKasIntelligence() {
    // the sword intelligence
    return 15;
}

inline int sapKasEgo() {
    // the sword ego
    return 19;
}

inline int sapKasTriesToControl() {
    // it attempts to control whoever takes it
    return 1;
}

inline int sapKasUseTotal() {
    // 5+2+1+2+2+1 - the use total
    return 13;
}

inline int sapKasBlankSlotCount() {
    // the DM-fill blanks, one per use
    return 13;
}

inline int sapKasPrintsInOrder() {
    // the powers print in order I through VI
    return 1;
}

inline int sapKasTableUse(int i) {
    // the uses per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 2, 1, 2, 2, 1,
    };
    return t[i];
}

inline int sapToothHistoriesSilent() {
    // no history tells of a cleric more
    // powerful than the renowned Dahlver-Nar
    return 1;
}

inline int sapToothGodsGavePowers() {
    // the gods themselves gave the powers
    return 1;
}

inline int sapToothRelicsAreTeeth() {
    // the great relics are his teeth
    return 1;
}

inline int sapToothEachToothHasPower() {
    // each of the Teeth has some power
    return 1;
}

inline int sapToothCount() {
    // the number of Teeth of Dahlver-Nar
    return 32;
}

inline int sapToothBenefitLevels() {
    // quarter, half, or all - 3 levels
    return 3;
}

inline int sapToothQuarterCount() {
    // a full quarter of the teeth
    return 8;
}

inline int sapToothHalfCount() {
    // half of the teeth
    return 16;
}

inline int sapToothGraftsInMouth() {
    // placed into the mouth to gain power
    return 1;
}

inline int sapToothLikeMissingTooth() {
    // grafts in place of a like missing tooth
    return 1;
}

inline int sapToothNeverRemoved() {
    // never removed once so emplaced
    return 1;
}

inline int sapToothRemovalOnlyByDemise() {
    // removal only by the possessor demise
    return 1;
}

inline int sapToothPowersCumulative() {
    // the powers and effects are cumulative
    return 1;
}

inline int sapToothUseTotal() {
    // the tooth table use total, 32 teeth
    return 32;
}

inline int sapToothTableOneCount() {
    // the teeth of table I in the tooth table
    return 21;
}

inline int sapToothTableTwoCount() {
    // the II teeth: 2, 16, 24 and 28
    return 4;
}

inline int sapToothTableThreeCount() {
    // the III teeth: 3, 9, 26 and 29
    return 4;
}

inline int sapToothTableFourCount() {
    // the lone table IV tooth
    return 1;
}

inline int sapToothTableFiveCount() {
    // the tooth table carries no table V
    return 0;
}

inline int sapToothTableSixCount() {
    // the VI teeth: 7 and 14
    return 2;
}

inline int sapToothLoneFourTooth() {
    // tooth 21 is the lone table IV tooth
    return 21;
}

inline int sapToothFirstSixTooth() {
    // tooth 7 is the first table VI tooth
    return 7;
}

inline int sapToothSecondSixTooth() {
    // tooth 14 is the second table VI tooth
    return 14;
}

inline int sapToothUnderscoreRunLen() {
    // every blank is a 14-underscore run
    return 14;
}

inline int sapToothBlankSlotCount() {
    // 32 + 8 x 2 + 3 DM-fill blanks
    return 51;
}

inline int sapToothXSignCount() {
    // the true multiplication signs, 51
    return 51;
}

inline int sapToothSetPairRows() {
    // the 8 two-column set table rows
    return 8;
}

inline int sapToothSetQuarterRows() {
    // the quarter rows: 1-8, 9-16,
    // 17-24 and 25-32
    return 4;
}

inline int sapToothSetHalfRepeatQuarters() {
    // the half rows repeat the quarter rows
    return 1;
}

inline int sapToothSetFiveRows() {
    // the V rows: 1-16, 17-32 and 1-32
    return 3;
}

inline int sapToothSetLeftTwoCount() {
    // set table left column: 8 rows of II
    return 8;
}

inline int sapToothSetLeftFiveCount() {
    // set table left column: 3 rows of V
    return 3;
}

inline int sapToothSetRightThreeCount() {
    // set table right column III entries
    return 4;
}

inline int sapToothSetRightFourCount() {
    // set table right column IV entries
    return 2;
}

inline int sapToothSetRightSixCount() {
    // set table right column VI entries
    return 2;
}

inline int sapToothTableUse(int i) {
    // the teeth per tables I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        21, 4, 4, 1, 0, 2,
    };
    return t[i];
}

inline int sapToothSetRightUse(int i) {
    // right-column sets per I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        0, 0, 4, 2, 0, 2,
    };
    return t[i];
}

}  // namespace rules