// ===========================================================================
// Adnd1 - rules/uamiscprose5.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 5, R385: the
// Q-S stretch - eleven pins,
// seven fully clean (the robe
// of stars, the scarab versus
// golems, the shadow
// lanthorn, the shoes of
// Fharlanghn, the slippers of
// kicking, the slippers of
// spider climbing, the
// sovereign glue) plus four
// mechanics-clean with flagged
// holes (the quiver of
// Ehlonna's command sentence,
// the robe of vermin's removal
// tail, the sheet of
// smallness' intro seam, the
// spoon of stirring's table
// cell). Nothing in Q-S fully
// garbles; S-Z rides the
// later part. The part-4 and
// skeleton seams ride in the
// regtest audit, not here.
// The R398 clean read
// filled every flagged hole
// named above.
namespace rules {

// ---- the quiver of Ehlonna
// ----
// An arrow container that
// appears a typical device to
// hold about a score of
// shafts; an alteration aura
// under examination; three
// distinct portions.
inline bool uamm5QehAppearsTypicalArrowCase()
    { return true; }

inline int uamm5QehAppearsToHoldShafts()
    { return 20; }

inline bool uamm5QehAlterationAura()
    { return true; }

inline bool uamm5QehThreeDistinctPortions()
    { return true; }

// The first and smallest
// portion holds up to 60
// arrow-like objects; the
// second, slightly longer,
// up to 18 javelin-like; the
// third and longest, up to 6
// spear- or staff-like.
inline int uamm5QehArrowPortionCapacity()
    { return 60; }

inline int uamm5QehJavelinPortionCapacity()
    { return 18; }

inline int uamm5QehSpearPortionCapacity()
    { return 6; }

// The command sentence
// OCR-scrambles; the
// reconstruction: the
// possessor commands the
// quiver to produce whatever
// is wished - an arrow, a
// javelin, and so on - one
// each round; flagged.
inline bool uamm5QehProducesOnCommand()
    { return true; }

inline bool uamm5QehOnePerRound()
    { return true; }

// The R398 clean read fills
// the sentence: the possessor
// need merely command the
// quiver to produce whatever
// is wished each round -
// "an arrow +1", "an arrow
// +3", "a javelin".
inline bool uamm5QehNamesVariants()
    { return true; }

inline bool uamm5QehCommandSentenceGarbles()
    { return false; }

// ---- the robe of stars ----
// A rather ordinary-appearing
// garment typical of magic-
// user apparel; a strong aura
// of alteration and evocation
// under examination.
inline bool uamm5RstOrdinaryAppearance()
    { return true; }

inline bool uamm5RstStrongAlterationEvocationAura()
    { return true; }

// Enables the wearer to
// travel the Astral Plane
// physically, along with all
// worn or carried; survives
// comfortably in the void of
// outer space as well.
inline bool uamm5RstAstralTravelPhysical()
    { return true; }

inline bool uamm5RstCarriesGearAlong()
    { return true; }

inline bool uamm5RstVoidSurvivalComfort()
    { return true; }

// +1 on all saving throws in
// other situations.
inline int uamm5RstSaveBonus()
    { return 1; }

// Up to six of the stars
// embroidered on the chest
// portion serve as missile
// weapons, provided the
// magic-user is proficient
// with darts; each star is a
// +5 throwing weapon to hit
// and damage, maximum range
// 6 inches, base damage 2-8
// per hit.
inline int uamm5RstStarMissiles()
    { return 6; }

inline bool uamm5RstNeedsDartProficiency()
    { return true; }

inline int uamm5RstStarBonus()
    { return 5; }

inline int uamm5RstStarRangeIn()
    { return 6; }

inline int uamm5RstStarDamageLo()
    { return 2; }

inline int uamm5RstStarDamageHi()
    { return 8; }

inline bool uamm5RstStarsOnChest()
    { return true; }

// Unused stars replace
// themselves at one per day;
// if all six are used, all
// the robe's power is gone
// forever.
inline int uamm5RstStarsRegrowPerDay()
    { return 1; }

inline bool uamm5RstAllUsedLosesPowerForever()
    { return true; }

// ---- the robe of vermin
// ----
// A magical-seeming garment
// radiating a dim
// enchantment aura; the
// wearer notices nothing
// unusual when donned - it
// conveys some power then,
// protection +1 for example.
inline bool uamm5RveDimEnchantmentAura()
    { return true; }

inline bool uamm5RveSeemsBeneficialAtFirst()
    { return true; }

inline int uamm5RveInitialProtectionBonus()
    { return 1; }

// In any situation requiring
// concentration and action
// against hostile opponents,
// the true nature reveals:
// a multitude of vermin
// bites; the wearer must
// cease other activities to
// scratch and shift, cannot
// gain initiative, suffers a
// 50% chance of being unable
// to complete a spell, and
// all other manual actions
// at one-half normal
// probability.
inline bool uamm5RveVerminBiteInCombat()
    { return true; }

inline bool uamm5RveCannotGainInitiative()
    { return true; }

inline int uamm5RveSpellFailurePct()
    { return 50; }

inline bool uamm5RveManualActionsHalfProb()
    { return true; }

// The removal tail
// OCR-scrambles; the
// reconstruction: the robe
// is removed only by means
// of a remove curse or
// similar magic-preventing
// magic; flagged.
// The R398 clean read
// confirms the removal tail -
// only a remove curse or
// similar magic strips the
// robe.
inline bool uamm5RveRemovalTailGarbles()
    { return false; }

inline bool uamm5RveRemovalNeedsRemoveCurse()
    { return true; }

// ---- the scarab versus
// golems ----
// A magical pin enabling its
// wearer to detect any form
// of golem within 60 feet,
// with actual concentration.
inline bool uamm5SvgPinDetectsGolems()
    { return true; }

inline int uamm5SvgDetectRangeFt()
    { return 60; }

inline bool uamm5SvgNeedsConcentration()
    { return true; }

// Enables the possessor to
// combat a golem with
// hand-held or missile
// weapons as if a normal
// monster - hit and damage
// as if no special defenses;
// effective against any
// lesser golem created by
// the 5th-level clerical
// golem spell.
inline bool uamm5SvgCombatsAsNormalMonster()
    { return true; }

inline bool uamm5SvgLesserGolemsOnly()
    { return true; }

inline int uamm5SvgClericalSpellLevel()
    { return 5; }

// The protective-abilities
// table: six dice-roll rows;
// the flesh row carries 400
// XP and 3,200 gp; the
// any-golem row (96-00)
// carries 1,250 XP and
// 12,500 gp.
inline int uamm5SvgTableRows()
    { return 6; }

inline int uamm5SvgFleshXp()
    { return 400; }

inline int uamm5SvgFleshGp()
    { return 3200; }

inline int uamm5SvgAnyGolemRowLo()
    { return 96; }

inline int uamm5SvgAnyGolemRowHi()
    { return 100; }

inline int uamm5SvgAnyGolemXp()
    { return 1250; }

inline int uamm5SvgAnyGolemGp()
    { return 12500; }

// ---- the shadow lanthorn
// ----
// A mundane-appearing light
// radiating a faint, evil
// dweomer.
inline bool uamm5SlaMundaneAppearance()
    { return true; }

inline bool uamm5SlaFaintEvilDweomer()
    { return true; }

// Fueled by oil rendered
// from the fat of human
// corpses, its beam
// generates 5-8 shadows
// serving the possessor for
// as long as it burns; when
// the oil is consumed the
// shadows disappear;
// typical burning time one
// hour.
inline bool uamm5SlaNeedsCorpseFatOil()
    { return true; }

inline int uamm5SlaShadowsLo()
    { return 5; }

inline int uamm5SlaShadowsHi()
    { return 8; }

inline bool uamm5SlaShadowsServePossessor()
    { return true; }

inline bool uamm5SlaShadowsVanishWhenConsumed()
    { return true; }

inline int uamm5SlaBurningHours()
    { return 1; }

// Characters of good
// alignment lose experience
// points equal to the
// item's value if they do
// not destroy the device.
inline bool uamm5SlaGoodLosesXpIfKept()
    { return true; }

// ---- the sheet of
// smallness ----
// Appears a well-made piece
// of very fine linen or
// silk, one side white, the
// other black; the intro
// prose OCR-scrambles; an
// alteration aura is
// detectable from the cloth;
// flagged.
inline bool uamm5SsmFineClothAppearance()
    { return true; }

inline bool uamm5SsmOneSideWhite()
    { return true; }

inline bool uamm5SsmOtherSideBlack()
    { return true; }

// The R398 clean read fills
// the intro: one side of the
// sheet carries a larger
// pattern than the other.
inline bool uamm5SsmOneSideLargerPattern()
    { return true; }

inline bool uamm5SsmIntroSeamGarbles()
    { return false; }

inline bool uamm5SsmAlterationAura()
    { return true; }

// Any item of regular
// magical sort (not an
// artifact or relic)
// wrapped within shrinks to
// 1/12 its normal size and
// weight; wrapped touching
// the reverse side, it
// grows back to normal.
inline bool uamm5SsmShrinksToTwelfth()
    { return true; }

inline bool uamm5SsmNoArtifactsOrRelics()
    { return true; }

inline bool uamm5SsmReverseSideRestores()
    { return true; }

// The dweomer affects no
// living material; no shrunk
// item is functional or
// usable in reduced form; a
// change in size takes a
// full two rounds,
// shrinking or restoring.
inline bool uamm5SsmNoLivingMaterial()
    { return true; }

inline bool uamm5SsmNonFunctionalWhenSmall()
    { return true; }

inline int uamm5SsmChangeRounds()
    { return 2; }

// ---- the shoes of
// Fharlanghn ----
// Low, thick-soled shoes so
// durable they never wear
// out; the wearer never
// grows fatigued from
// walking, easily
// maintaining 20-30 miles
// per day.
inline bool uamm5SfaNeverWearOut()
    { return true; }

inline bool uamm5SfaNeverFatigued()
    { return true; }

inline int uamm5SfaMilesPerDayLo()
    { return 20; }

inline int uamm5SfaMilesPerDayHi()
    { return 30; }

// Neutral or neutral good
// wearers additionally:
// never trip, step into a
// snare or pit, or become
// entangled; climb up or
// down 45-degree hills
// without effort; walk
// narrow ledges or slippery
// logs without a slip.
inline bool uamm5SfaNeverTripsOrSnared()
    { return true; }

inline int uamm5SfaHillClimbAngleDeg()
    { return 45; }

inline bool uamm5SfaSureFootedOnLedges()
    { return true; }

// A worshiper of Fharlanghn
// gains more: becoming lost
// is impossible; nothing
// walking on the earth can
// surprise; run at 18-inch
// movement and jump up to 20
// feet; climb vertical
// surfaces as a 10th-level
// thief; tread on any earth
// as on a smooth roadway.
inline bool uamm5SfaWorshipperNeverLost()
    { return true; }

inline bool uamm5SfaWorshipperNoSurprise()
    { return true; }

inline int uamm5SfaWorshipperRunIn()
    { return 18; }

inline int uamm5SfaWorshipperJumpFt()
    { return 20; }

inline int uamm5SfaWorshipperThiefClimbLevel()
    { return 10; }

inline bool uamm5SfaWorshipperEarthAsRoad()
    { return true; }

// At least a dozen pairs
// are known in treasure
// troves.
inline int uamm5SfaKnownPairs()
    { return 12; }

// ---- the slippers of
// kicking ----
// The wearer utilizes feet
// as effective weapons: two
// attacks each combat round
// (two special attacks if
// foregoing other methods),
// attack level unchanged.
inline bool uamm5SkiFeetAsWeapons()
    { return true; }

inline int uamm5SkiAttacksPerRound()
    { return 2; }

inline bool uamm5SkiSpecialNeedsForegoing()
    { return true; }

inline bool uamm5SkiAttackLevelUnchanged()
    { return true; }

// Damage: 1-6 versus
// man-sized or smaller, 1-4
// versus larger than
// man-sized; the dweomer
// inflicts twice normal
// damage in a separate
// category, recovered by the
// opponent after one
// complete turn, like
// stunning.
inline int uamm5SkiDamageManSizedLo()
    { return 1; }

inline int uamm5SkiDamageManSizedHi()
    { return 6; }

inline int uamm5SkiDamageLargerLo()
    { return 1; }

inline int uamm5SkiDamageLargerHi()
    { return 4; }

inline bool uamm5SkiDoubleDamageSeparate()
    { return true; }

inline bool uamm5SkiExtraRecoveredAfterTurn()
    { return true; }

// The printed example: a
// larger opponent takes 3
// (plus 3) and 4 (plus 4);
// at the 11th round it
// recovers the 7 extra
// points as the stunning
// wears off.
inline int uamm5SkiExamplePlusOne()
    { return 3; }

inline int uamm5SkiExamplePlusTwo()
    { return 4; }

inline int uamm5SkiExampleRecovered()
    { return 7; }

// Worn by a character with
// martial arts skills, the
// effect is merely +1 on
// foot attacks and damage.
inline int uamm5SkiMartialArtsBonus()
    { return 1; }

inline bool uamm5SkiMartialArtsNoDouble()
    { return true; }

// ---- the slippers of
// spider climbing ----
// Totally unremarkable in
// appearance, a faint
// alteration dweomer under
// detection; worn, they
// enable movement at 6-inch
// rate on vertical surfaces
// or upside down along
// ceilings, hands free.
inline bool uamm5SscUnremarkableAppearance()
    { return true; }

inline bool uamm5SscFaintAlterationDweomer()
    { return true; }

inline int uamm5SscClimbRateIn()
    { return 6; }

inline bool uamm5SscCeilingsToo()
    { return true; }

inline bool uamm5SscHandsFree()
    { return true; }

// Extremely slippery
// surfaces - ice, oiled or
// greased - make the
// slippers useless.
inline bool uamm5SscUselessOnSlippery()
    { return true; }

// ---- the sovereign glue
// ----
// A pale amber substance,
// thick and viscous;
// containable only within a
// flask coated with oil of
// slipperiness; after each
// pouring, a fresh oil
// application must be made
// within 1 round to keep
// the glue from adhering to
// the container.
inline bool uamm5SglPaleAmberViscous()
    { return true; }

inline bool uamm5SglNeedsSlipperinessFlask()
    { return true; }

inline int uamm5SglReoilWithinRounds()
    { return 1; }

inline bool uamm5SglElseAdheresToFlask()
    { return true; }

// One ounce covers about
// one square foot, bonding
// virtually any two
// substances permanently;
// the glue takes one full
// round to set - pulled
// apart earlier, that
// application is worthless.
inline int uamm5SglSqFtPerOunce()
    { return 1; }

inline bool uamm5SglPermanentBond()
    { return true; }

inline int uamm5SglSetRounds()
    { return 1; }

inline bool uamm5SglEarlyPullRuinsApplication()
    { return true; }

// A set bond separates only
// by rending one object or
// the other, except by oil
// of etherealness or
// ultimate solution, the
// only solvents; a typical
// container holds 1-10
// ounces.
inline bool uamm5SglSetBondRends()
    { return true; }

inline bool uamm5SglDissolvedByEtherealnessOrUltimate()
    { return true; }

inline int uamm5SglOuncesLo()
    { return 1; }

inline int uamm5SglOuncesHi()
    { return 10; }

// ---- the spoon of
// stirring ----
// A normal, unremarkable
// spoon that radiates no
// magic unless dipped into
// a potion; inserted, it
// gives off a burst of
// alteration magic, and the
// contents change into some
// other potion - the spoon
// seems normal thereafter,
// reusable on the same or
// different potions.
inline bool uamm5SstUnremarkableSpoon()
    { return true; }

inline bool uamm5SstRadiatesOnlyInPotion()
    { return true; }

inline bool uamm5SstAlterationBurst()
    { return true; }

inline bool uamm5SstChangesPotion()
    { return true; }

inline bool uamm5SstReusable()
    { return true; }

// The same potion treated
// more than three times - a
// fourth usage - loses all
// magic, a noisome liquor
// of no value.
inline int uamm5SstMaxUsesPerPotion()
    { return 3; }

inline bool uamm5SstFourthUseRuins()
    { return true; }

// The R398 clean read fills
// the cell: the new type is
// diced from Table III.A or
// Table III.A.2.
inline bool uamm5SstAlsoTableThreeA()
    { return true; }

inline bool uamm5SstTableCellGarbles()
    { return false; }

inline bool uamm5SstDeterminedByTable()
    { return true; }

// A same-type result changes
// the appearance and the
// strength: twice normal on
// 01-50, half normal on
// 51-00.
inline bool uamm5SstSameResultChangesAppearance()
    { return true; }

inline int uamm5SstTwiceStrengthLo()
    { return 1; }

inline int uamm5SstTwiceStrengthHi()
    { return 50; }

inline int uamm5SstHalfStrengthLo()
    { return 51; }

inline int uamm5SstHalfStrengthHi()
    { return 100; }

// ---- the part ledger ----
// Eleven Q-S items, all
// fully clean - the R398
// clean read filled the four
// flagged holes, none fully
// garbled.
inline int uamm5PartItemTotal()
    { return 11; }

inline int uamm5PartCleanCount()
    { return 11; }

inline int uamm5PartFlaggedCount()
    { return 0; }

inline int uamm5PartGarbledCount()
    { return 0; }

}   // namespace rules

