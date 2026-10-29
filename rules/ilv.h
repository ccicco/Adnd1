// =========================================================================================
// Adnd1 - rules/ilv.h
// The Dragon issue-12 opener part one - the Ovalle illusionist article
// (folios 6-7) and the Endersby and Carroll ship cargo article (folio 12):
// two adjudicated chains, the mythos pair to follow
// census 841 -> 842.
//
// Pinned from The Dragon Vol. II No. 6 (February 1978), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 12;
// the source lives in the archive.org item accessory-dragon-magazine-012,
// file Accessory - Dragon Magazine #012_djvu.xml). PRINT FOLIO = PDF PAGE,
// verified at the TOC alignments (5, 6, 8, 12, 13, 18, 28); the TOC's folio 2
// for the lightning bolt essay is a print misprint, the article riding folio
// 12, noted as scanned. The transcripts ride extract/dragon/012/p001 through
// p032; the article CHAIN is the ink unit, not the folio.
//
// The cargo grid's Spice and Ivory value cells print blank in the scan and
// the Foreign slaves cell prints a count (20-60 people) not a gold figure -
// all three ride the -1 sentinel with the census, the count riding the
// transcript. The illusionist ladder's fifth-level header garbles as Sth and
// the Cause Serious Wounds damage garbles as a bar reading 1 point - the
// ladder's arithmetic is the anchor. Two slipped teasers noted: the brawling
// long-term-effects sequel and the Name That Monster winners both fail to
// print, harvestable later.
//
namespace rules {

// ---- the Ovalle illusionist article (folios 6-7) ----

// a 7 percent chance per level of recognizing a disguised creature or
// polymorphed object (folio 6)
inline int ilvRecognizePercentPerLevel()
    { return 7; }

// Wall of Fog lasts 3-12 plus level turns after concentration ceases (folio
// 7)
inline int ilvWallOfFogMinTurns()
    { return 3; }

// the Wall of Fog duration ceiling (folio 7)
inline int ilvWallOfFogMaxTurns()
    { return 12; }

// Displacement places the image 0-10 feet from the true location (folio 7)
inline int ilvDisplacementMinFeet()
    { return 0; }

// the Displacement image distance ceiling, variable at will (folio 7)
inline int ilvDisplacementMaxFeet()
    { return 10; }

// Displacement lasts 1-6 turns plus level of caster (folio 7)
inline int ilvDisplacementMinTurns()
    { return 1; }

// the Displacement duration die ceiling (folio 7)
inline int ilvDisplacementMaxTurns()
    { return 6; }

// Multiple Hypnosis affects 1-4 (folio 7)
inline int ilvMultipleHypnosisMinTargets()
    { return 1; }

// the Multiple Hypnosis target ceiling (folio 7)
inline int ilvMultipleHypnosisMaxTargets()
    { return 4; }

// Hypnotize Monster affects all creatures, treat as charm monster +2 (folio
// 7)
inline int ilvHypnotizeMonsterCharmBonus()
    { return 2; }

// Feeblemind at Magic User 30 percent off saving throw (folio 7)
inline int ilvFeeblemindMuSavePenalty()
    { return 30; }

// Feeblemind at Cleric 10 percent off; illusionists save normal (folio 7)
inline int ilvFeeblemindClericSavePenalty()
    { return 10; }

// Shadow Magic Finger of Death causes disease or affects 2 levels (folio 7)
inline int ilvFingerOfDeathLevelDrain()
    { return 2; }

// Shadow Magic Blade Barrier does 1-8 points damage (folio 7)
inline int ilvBladeBarrierMinDamage()
    { return 1; }

// the Blade Barrier damage ceiling (folio 7)
inline int ilvBladeBarrierMaxDamage()
    { return 8; }

// Shadow Magic Cause Serious Wounds does 1 point damage - the print's garbled
// bar reading 1 (folio 7)
inline int ilvCauseSeriousWoundsDamage()
    { return 1; }

// the Gaze of Umber Hulk range - as far as can be seen, 6 or 12 inches (folio
// 7)
inline int ilvGazeRangeNearInches()
    { return 6; }

// the gaze range far reading (folio 7)
inline int ilvGazeRangeFarInches()
    { return 12; }

// Demi Shadow Magic Power Word Kill affects 1-4 hit points (folio 7)
inline int ilvPowerWordKillMinHp()
    { return 1; }

// the Power Word Kill hit-point ceiling (folio 7)
inline int ilvPowerWordKillMaxHp()
    { return 4; }

// Demi Shadow Magic Holy Word affects 2-16 first-level types (folio 7)
inline int ilvHolyWordMinFirstLevelTypes()
    { return 2; }

// the Holy Word first-level-type ceiling (folio 7)
inline int ilvHolyWordMaxFirstLevelTypes()
    { return 16; }

// Demi Shadow Magic Prismatic Wall does 2 or 4 points damage (folio 7)
inline int ilvPrismaticWallDamageLow()
    { return 2; }

// the Prismatic Wall damage high reading (folio 7)
inline int ilvPrismaticWallDamageHigh()
    { return 4; }

// Demi Shadow Magic Ice Storm does 1-6 points damage (folio 7)
inline int ilvIceStormMinDamage()
    { return 1; }

// the Ice Storm damage ceiling (folio 7)
inline int ilvIceStormMaxDamage()
    { return 6; }

// the first-level MU spell research - save vs magic or wait two game weeks,
// then save by intelligence or wait two more (folio 7)
inline int ilvMUSpellResearchWaitWeeks()
    { return 2; }

// shield is a fourth-level illusionist spell - defensive spells trade with
// less penalty (folios 6-7)
inline int ilvShieldIllusionistSpellLevel()
    { return 4; }

// improved invisibility is a fifth-level magic-user spell (folio 6)
inline int ilvImprovedInvisibilityMuSpellLevel()
    { return 5; }

// second-level MU spells - same as first level except double the time penalty
// (folio 7)
inline int ilvSecondLevelWaitMultiplier()
    { return 2; }

// the explanation-of-spells ladder runs the first through seventh levels
// (folio 7)
inline int ilvSpellLadderLevels()
    { return 7; }

// an illusionist innately discriminates illusionist-thrown spells from the
// same spells thrown by a magic user or cleric (folio 6)
inline bool ilvRecognizesColleagueWork()
    { return true; }

// illusionists cannot use fireballs or lightning (folio 6)
inline bool ilvNoFireballOrLightning()
    { return true; }

// offensive spells cannot be traded without great penalty (folio 6)
inline bool ilvOffensiveSpellsCostlyToTrade()
    { return true; }

// defensive spells can be traded with less penalty (folio 6)
inline bool ilvDefensiveSpellsTradeEasier()
    { return true; }

// informational spells like detect magic, contact higher plane and legend
// lore are freely tradeable at the same level (folio 6)
inline bool ilvInformationalSpellsFreelyTradeable()
    { return true; }

// Vision as an exception can never be researched (folio 6)
inline bool ilvVisionNeverResearchable()
    { return true; }

// illusionists have the ability to attack astral and ethereal monsters (folio
// 6)
inline bool ilvAttacksAstralAndEthereal()
    { return true; }

// spells using the eyes as point of focus need no speech or overt hand
// motions (folio 7)
inline bool ilvEyeFocusSpellsSilent()
    { return true; }

// Gaze Reflection bounces visual spells or rays of light, not other magic
// (folio 7)
inline bool ilvGazeReflectionBouncesVisualOnly()
    { return true; }

// posthypnotic suggestions take effect after hypnosis is released, a save for
// each, on saving the charm breaks (folio 7)
inline bool ilvPosthypnoticSuggestionSaves()
    { return true; }

// Dispel Illusion works against any illusion-type spell and automatically
// dispels MU-cast illusionist spells (folio 7)
inline bool ilvDispelAutoVsMuCast()
    { return true; }

// Personal Silence is as clerical silence for the caster (folio 7)
inline bool ilvPersonalSilenceClone()
    { return true; }

// Improved Displacement is as displacement 10-foot radius with unlimited
// duration (folio 7)
inline bool ilvImprovedDisplacementUnlimited()
    { return true; }

// Sensory Displacement - save vs magic or the victim is blind, deaf and
// disoriented until dispelled (folio 7)
inline bool ilvSensoryDisplacementBlinds()
    { return true; }

// Discord - save vs magic or the victim acts as if wearing rings of delusion
// and contrariness (folio 7)
inline bool ilvDiscordDelusionEffect()
    { return true; }

// the Gaze of Umber Hulk can affect the illusionist by reflection; must meet
// eyes, lasts while he concentrates (folio 7)
inline bool ilvGazeReflectedBack()
    { return true; }

// Create Spectres - the spectres have no draining ability, harmed by neither
// weapons nor magic save haste (halving lifespan) and time stop (destroying)
// (folio 7)
inline bool ilvSpectresWeaponImmune()
    { return true; }

// the researched first-level MU spell use never wears off unless
// level-drained, feebleminded or dispelled (folio 7)
inline bool ilvMUSpellResearchPermanent()
    { return true; }

// the sixth-level Basilisk Gaze - same as Umber Hulk Gaze except the save is
// against turning to stone (folio 7)
inline bool ilvBasiliskGazeTurnsToStone()
    { return true; }

// the seventh-level Alter Reality is the same as before but a full wish, not
// limited wish (folio 7)
inline bool ilvAlterRealityFullWish()
    { return true; }

// ---- the Endersby and Carroll ship cargo article (folio 12) ----

// a small merchant ship holds up to twelve units of cargo (folio 12)
inline int ilvSmallMerchantUnits()
    { return 12; }

// a large merchant ship holds up to thirty units (folio 12)
inline int ilvLargeMerchantUnits()
    { return 30; }

// roll a six-sided die for each kind of treasure possible (folio 12)
inline int ilvCargoKindDieSides()
    { return 6; }

// each roll of a one means one to six units of that cargo on board (folio 12)
inline int ilvCargoUnitsMin()
    { return 1; }

// the cargo unit ceiling per one-roll (folio 12)
inline int ilvCargoUnitsMax()
    { return 6; }

// a 15 percent chance that a few passengers are aboard - merchants,
// adventurers or noblemen (folio 12)
inline int ilvPassengerChancePercent()
    { return 15; }

// the cargo value grid rows - spice, silk, precious stones, ivory, precious
// wood, tea, cotton, jewelry, cloth, exotic livestock, fruits and vegetables,
// foreign slaves (folio 12)
inline int ilvCargoRows()
    { return 12; }

// cargo is determined only after grappling and surrender or annihilation of
// enemy forces (folio 12)
inline bool ilvCargoAfterSurrenderOnly()
    { return true; }

// if the total units exceed the ship's capacity, neglect the least valuable
// cargo (folio 12)
inline bool ilvOverflowDropsLeastValuable()
    { return true; }

// also roll for treasure - type A (folio 12)
inline bool ilvCargoTreasureTypeA()
    { return true; }

// the value-per-unit gold pieces - spice sentinel, silk 1000, precious stones
// 1000, ivory sentinel, precious wood 300, tea 350, cotton 250, jewelry 1000,
// cloth 250, exotic livestock 250, fruits and vegetables 100, foreign slaves
// sentinel (folio 12)
inline int ilvCargoGoldPerUnit(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 1000;
        case 2:
            return 1000;
        case 3:
            return -1;
        case 4:
            return 300;
        case 5:
            return 350;
        case 6:
            return 250;
        case 7:
            return 1000;
        case 8:
            return 250;
        case 9:
            return 250;
        case 10:
            return 100;
        case 11:
            return -1;
        default:
            return -1;
        }
    }

}   // namespace rules
