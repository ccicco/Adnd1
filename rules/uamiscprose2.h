// ===========================================================================
// Adnd1 - rules/uamiscprose2.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 2, R382: the
// D-E stretch - eight pins,
// one fully clean (the dust
// of tracelessness) plus
// seven mechanics-clean with
// flagged holes (the deck of
// illusions' card list, the
// dicerion's description
// seam, the dust of dryness'
// elemental-save cell, the
// dust of illusion's intro,
// the egg of desire's int
// seam, the egg of reason's
// 18+ increment cell, the
// egg of shattering's attack
// seam). Nothing in D-E
// fully garbles; F-Z rides
// the later parts. The
// part-1 and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the deck of illusions
// ----
// A set of parchment cards in
// an ivory, leather, or wood
// box; a full deck holds 34
// plaques. A drawn card cast
// out forms an illusion with
// audial and visual
// components that lasts until
// it is dispelled.
inline int uamm2DekCardCount()
    { return 34; }

inline bool uamm2DekAudialVisual()
    { return true; }

inline bool uamm2DekLastsUntilDispelled()
    { return true; }

// The illusory creature will
// not go more than 30 feet
// from where the card lands.
inline int uamm2DekLeashFt()
    { return 30; }

// When the illusion is
// dispelled, the card blanks
// and cannot be used again;
// picking the card up
// dispels the illusion
// instantly.
inline bool uamm2DekCardBlanksAfterUse()
    { return true; }

inline bool uamm2DekPickupDispelsInstantly()
    { return true; }

// Two jokers, showing the
// deck's owner. The card
// list OCR-garbles (stray
// rows, "bgoblin", "rc");
// the deck mechanics read;
// flagged.
inline int uamm2DekJokers()
    { return 2; }

inline bool uamm2DekCardListGarbles()
    { return true; }

// ---- the dicerion of light
// and darkness ----
// A clerical candlestick with
// two branches - silver and
// mithral bright, iron and
// adamantite dark; the
// branch-band description
// OCR-scrambles, the
// mechanics read; flagged.
inline bool uamm2DicTwoBranches()
    { return true; }

// About 1 foot tall, a
// weight of 30-40 gold
// pieces.
inline int uamm2DicHeightIn()
    { return 1; }

inline int uamm2DicWeightGpLo()
    { return 30; }

inline int uamm2DicWeightGpHi()
    { return 40; }

// Must have specially
// manufactured candles -
// purest wax with powdered
// obsidian and crystal,
// blessed and consecrated
// (the ceremony spell).
inline bool uamm2DicNeedsSpecialCandles()
    { return true; }

inline bool uamm2DicCandlesBlessedConsecrated()
    { return true; }

// Both candles alight: the
// cleric sees into any
// darkness or the brightest
// light as if it were normal
// daylight.
inline bool uamm2DicBothAlightSeeAll()
    { return true; }

// On command the candles emit
// a metallic illumination
// that dispels natural
// shadows (not the undead
// creature) within a
// 30-foot radius; while so
// employed the dark/light
// vision boon ends.
inline int uamm2DicShadowDispelRadiusFt()
    { return 30; }

inline bool uamm2DicDispelNaturalShadowsOnly()
    { return true; }

inline bool uamm2DicDispelEndsVisionBoon()
    { return true; }

// A candle burns 5-8 turns
// in a gentle draft; a
// strong draft cuts 1-2
// turns; still air lasts
// 9-16 turns.
inline int uamm2DicBurnGentleLo()
    { return 5; }

inline int uamm2DicBurnGentleHi()
    { return 8; }

inline int uamm2DicBurnStrongCutLo()
    { return 1; }

inline int uamm2DicBurnStrongCutHi()
    { return 2; }

inline int uamm2DicBurnStillLo()
    { return 9; }

inline int uamm2DicBurnStillHi()
    { return 16; }

// Only the black-arm candle
// alight: a 15-foot darkness
// sphere englobes the cleric
// without hampering him or
// her; a bright light
// striking the eyes then
// blinds 1-4 rounds.
inline int uamm2DicDarkSphereFt()
    { return 15; }

inline bool uamm2DicDarkSphereWearerFree()
    { return true; }

inline int uamm2DicBrightLightBlindLo()
    { return 1; }

inline int uamm2DicBrightLightBlindHi()
    { return 4; }

// Only the bright-branch
// candle alight: a brilliant
// sphere surrounds the
// cleric, whose vision stays
// unimpaired while the
// dicerion is touched or
// held; darkness (evil)
// creatures blind 2-8
// rounds, light (good)
// creatures blind 1-4
// rounds on looking.
inline bool uamm2DicLightSphereWearerOk()
    { return true; }

inline int uamm2DicEvilBlindLo()
    { return 2; }

inline int uamm2DicEvilBlindHi()
    { return 8; }

inline int uamm2DicGoodBlindLo()
    { return 1; }

inline int uamm2DicGoodBlindHi()
    { return 4; }

// Magical darkness while the
// bright power works blinds
// the cleric 1-4 rounds;
// even with one candle
// burning, both branches
// must hold tapers.
inline int uamm2DicMagDarkBlindLo()
    { return 1; }

inline int uamm2DicMagDarkBlindHi()
    { return 4; }

inline bool uamm2DicBothBranchesNeedTapers()
    { return true; }

inline bool uamm2DicDescSeamGarbles()
    { return true; }

// ---- the dust of dryness
// ----
// A pinch cast into water
// negates 1 cubic yard of
// liquid and becomes a
// marble-sized pellet;
// hurled down, the pellet
// breaks and releases the
// same volume of water.
inline int uamm2DdrCuYardsPerPinch()
    { return 1; }

inline bool uamm2DdrPelletReleasesSame()
    { return true; }

// Sprinkled over an area it
// negates a precipitation or
// cloudburst spell, or dries
// up 1 cubic rod of water.
inline bool uamm2DdrSprinkleNegatesPrecip()
    { return true; }

inline int uamm2DdrSprinkleCuRods()
    { return 1; }

// It affects only water
// forms (fresh, salt,
// brackish, alkaline).
inline bool uamm2DdrWaterFormsOnly()
    { return true; }

// Against a water elemental
// or similar creature the
// creature must save versus
// spell - that sentence
// OCR-scrambles ("save spell
// or b"), the rest reads; a
// save still inflicts 6-30
// points of damage; flagged.
inline bool uamm2DdrElementalSaveVsSpell()
    { return true; }

inline int uamm2DdrElementalDmgLo()
    { return 6; }

inline int uamm2DdrElementalDmgHi()
    { return 30; }

inline bool uamm2DdrElementalSeamGarbles()
    { return true; }

// A pouch holds 11-20
// pinches and works while at
// least half the original
// amount remains.
inline int uamm2DdrPouchLo()
    { return 11; }

inline int uamm2DdrPouchHi()
    { return 20; }

inline bool uamm2DdrWorksWhileHalfRemains()
    { return true; }

// ---- the dust of illusion
// ----
// The intro sentences
// OCR-scramble; the
// mechanics read. A pinch
// lets the dusted creature
// appear as any
// similar-shape creature
// with a size variance of
// plus or minus 50%;
// flagged.
inline bool uamm2DilSimilarShapeOnly()
    { return true; }

inline int uamm2DilSizeVariancePct()
    { return 50; }

inline bool uamm2DilIntroGarbles()
    { return true; }

// An unwilling recipient is
// allowed a saving throw to
// escape the effect; the
// sprinkler must envision
// the illusion as the powder
// is shaken.
inline bool uamm2DilUnwillingSaveEscapes()
    { return true; }

inline bool uamm2DilSprinklerEnvisions()
    { return true; }

// The illusionary power
// lasts 7-12 hours unless
// dispelled; a pouch holds
// 11-20 pinches.
inline int uamm2DilDurationLo()
    { return 7; }

inline int uamm2DilDurationHi()
    { return 12; }

inline int uamm2DilPouchLo()
    { return 11; }

inline int uamm2DilPouchHi()
    { return 20; }

// ---- the dust of
// tracelessness ----
// A pinch tossed into the
// air makes a chamber of up
// to 1,000 square feet look
// dustily abandoned for a
// decade; along a trail it
// obliterates the passage of
// as many as a dozen men and
// horses for a mile back.
inline int uamm2DtrChamberSqFt()
    { return 1000; }

inline bool uamm2DtrDecadeLook()
    { return true; }

inline int uamm2DtrTrailMenHorses()
    { return 12; }

inline int uamm2DtrTrailMiles()
    { return 1; }

// No magical radiation
// occurs; a finely sewn
// pouch holds 13-24 pinches.
// Fully clean in the
// extract.
inline bool uamm2DtrNoRadiation()
    { return true; }

inline int uamm2DtrPouchLo()
    { return 13; }

inline int uamm2DtrPouchHi()
    { return 24; }

// ---- the egg of desire
// ----
// At least five sorts of
// small ovoid; placed on its
// large end and touched
// right it rocks and chimes;
// viewers within 20 feet
// save versus spell.
inline int uamm2EgdSortCount()
    { return 5; }

inline bool uamm2EgdRocksAndChimes()
    { return true; }

inline bool uamm2EgdViewerSaveVsSpell()
    { return true; }

inline int uamm2EgdViewingRangeFt()
    { return 20; }

// Black holds permanently;
// Bone takes the most prized
// magic item; Crystal all
// gems; Golden all precious
// metals - each then leave
// and forget; Scarlet holds
// one minute, then rage at
// the first living thing
// seen.
inline bool uamm2EgdBlackHoldsPermanent()
    { return true; }

inline bool uamm2EgdBonePrizedMagicItem()
    { return true; }

inline bool uamm2EgdCrystalAllGems()
    { return true; }

inline bool uamm2EgdGoldenAllMetals()
    { return true; }

inline int uamm2EgdScarletHoldMinutes()
    { return 1; }

inline bool uamm2EgdScarletRageAttacksFirst()
    { return true; }

// Removal only by a magic
// (the seam prints "a magic
// or remove curse spell")
// remove curse; the
// low-intelligence seam
// OCR-scrambles ("y an
// egg"), the table reads;
// flagged.
inline bool uamm2EgdRemovalRemoveCurse()
    { return true; }

inline bool uamm2EgdLowIntGrabsDropped()
    { return true; }

inline bool uamm2EgdIntSeamGarbles()
    { return true; }

// XP and gp sale values by
// sort: Black 500 and 5,000,
// Bone 900 and 10,000,
// Crystal 800 and 9,000,
// Golden 600 and 4,000,
// Scarlet 700 and 3,500.
inline int uamm2EgdXpForSort(int i) {
    static const int k[5] = {
        500, 900, 800, 600, 700};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uamm2EgdGpForSort(int i) {
    static const int k[5] = {
        5000, 10000, 9000, 4000,
        3500};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// ---- the egg of reason
// ----
// Always coated with oil of
// timelessness; the eater
// first saves versus poison
// with no bonuses or dies,
// and the poison cannot be
// neutralized.
inline bool uamm2EgrCoatedOilTimelessness()
    { return true; }

inline bool uamm2EgrSaveVsPoisonNoBonus()
    { return true; }

inline bool uamm2EgrPoisonNotNeutralizable()
    { return true; }

// If it does not slay: one
// point of intelligence (60%)
// or wisdom (40%); the
// success chance is 100 minus
// twice the current score.
inline int uamm2EgrIntChancePct()
    { return 60; }

inline int uamm2EgrWisChancePct()
    { return 40; }

inline int uamm2EgrGainPoints()
    { return 1; }

inline int uamm2EgrSuccessChanceForScore(
        int sc) {
    if (sc < 3) sc = 3;
    if (sc > 18) sc = 18;
    return 100 - 2 * sc;
}

// The 18-or-higher increment
// cell OCR-garbles (""so
// point at a time ... 10
// eggs") - flagged; racial
// limitations apply.
inline bool uamm2EgrHighScoreCellGarbles()
    { return true; }

inline bool uamm2EgrRacialLimitsApply()
    { return true; }

// If the oil is removed, the
// egg still may poison but
// has lost the
// ability-enhancing
// property.
inline bool uamm2EgrOilRemovedStillPoison()
    { return true; }

inline bool uamm2EgrOilRemovedNoEnhance()
    { return true; }

// ---- the egg of shattering
// ----
// Shatters with a loud noise
// when handled normally or
// touched by a detection
// spell, sending fragments
// within a 1-inch radius (as
// printed); the attack
// sentence OCR-scrambles but
// reconstructs; flagged.
inline bool uamm2EgsShattersOnHandleOrDetect()
    { return true; }

inline int uamm2EgsFragRadiusIn()
    { return 1; }

inline bool uamm2EgsAttackSeamGarbles()
    { return true; }

// Creatures in the area are
// attacked using actual armor
// class only, no dexterity
// bonuses; each hit by 1-4
// fragments takes 2-7 points
// per fragment.
inline bool uamm2EgsActualAcOnly()
    { return true; }

inline bool uamm2EgsNoDexBonus()
    { return true; }

inline int uamm2EgsFragHitsLo()
    { return 1; }

inline int uamm2EgsFragHitsHi()
    { return 4; }

inline int uamm2EgsFragDmgLo()
    { return 2; }

inline int uamm2EgsFragDmgHi()
    { return 7; }

// Fragile objects within 1
// foot break automatically;
// within 2 feet they save
// versus crushing blow.
inline int uamm2EgsFragileAutoFt()
    { return 1; }

inline int uamm2EgsFragileSaveFt()
    { return 2; }

inline bool uamm2EgsSaveVsCrushingBlow()
    { return true; }

// ---- the part ledger ----
// Eight D-E items: one fully
// clean, seven flagged, none
// fully garbled.
inline int uamm2PartItemTotal()
    { return 8; }

inline int uamm2PartCleanCount()
    { return 1; }

inline int uamm2PartFlaggedCount()
    { return 7; }

inline int uamm2PartGarbledCount()
    { return 0; }

}   // namespace rules

