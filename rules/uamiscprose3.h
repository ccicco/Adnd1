// ===========================================================================
// Adnd1 - rules/uamiscprose3.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 3, R383: the
// G-H stretch - eleven pins,
// two fully clean (the gloves
// of missile snaring, the hat
// of stupidity) plus nine
// mechanics-clean with flagged
// holes (the gem of insight's
// recall seam, the girdle of
// dwarvenkind's racial block,
// the girdle of many pouches'
// tail, the gloves of
// thievery's level cells, the
// hat of difference's loss
// seam, the hat of disguise's
// removal seam, the haversack's
// quart merge, the horn of
// fog's rounds/minutes seam,
// the horn of goodness' eaten
// header). Nothing in G-H
// fully garbles; I-Z rides
// the later parts. The
// part-2 and skeleton seams
// ride in the regtest audit,
// not here.
// The R398 clean read
// filled every flagged hole
// named above.
namespace rules {

// ---- the gem of insight ----
// A well-cut stone of not
// less than 5,000 gp value;
// a faint enchantment aura
// under detection.
inline int uamm3GemMinValueGp()
    { return 5000; }

inline bool uamm3GemFaintEnchantmentAura()
    { return true; }

// The possessor begins to
// feel its power after one
// week; after two weeks the
// understanding arrives.
inline int uamm3GemFeelPowerWeeks()
    { return 1; }

inline int uamm3GemUnderstandAfterWeeks()
    { return 2; }

// While kept: recall, better
// memory, insight - one point
// of intelligence and one of
// wisdom. The recall
// sentences OCR-scramble; the
// mechanics read; flagged.
inline int uamm3GemIntGain()
    { return 1; }

inline int uamm3GemWisGain()
    { return 1; }

// The R398 clean read fills
// the recall seam: any one
// such gem functions but
// once every 50 years.
inline int uamm3GemYearsBetweenFunctions()
    { return 50; }

inline bool uamm3GemRecallSeamGarbles()
    { return false; }

// Keep it three months: past
// the period the intelligence
// point remains but the
// wisdom point is lost.
inline int uamm3GemKeepMonths()
    { return 3; }

inline bool uamm3GemIntStaysBeyondPeriod()
    { return true; }

inline bool uamm3GemWisLostBeyondPeriod()
    { return true; }

// A second gem never increases
// either score, even if the
// first left no permanent
// gain.
inline bool uamm3GemSecondGemInert()
    { return true; }

// ---- the girdle of
// dwarvenkind ----
// Charisma by audience: -1
// with non-dwarves and their
// ilk, +1 with stout
// halflings and all gnomes,
// +2 as regarded by dwarves.
inline int uamm3GdkChaNonDwarvesAdj()
    { return -1; }

inline int uamm3GdkChaStoutHalflingsAdj()
    { return 1; }

inline int uamm3GdkChaGnomesAdj()
    { return 1; }

inline int uamm3GdkChaDwarvesAdj()
    { return 2; }

// The dweomer grants the
// dwarvish language -
// understand, speak, read.
inline bool uamm3GdkSpeaksDwarvish()
    { return true; }

// The racial-benefits block
// OCR-scrambles; the
// reconstruction: the dwarf
// saving-throw bonuses apply
// underground; all benefits
// last only while the girdle
// is worn; the extra-language
// and giant-type armor class
// benefits never apply;
// flagged.
inline bool uamm3GdkUndergroundSaveBonusesApply()
    { return true; }

inline bool uamm3GdkBenefitsOnlyWhileWorn()
    { return true; }

inline bool uamm3GdkNoGiantTypeAcBenefit()
    { return true; }

inline bool uamm3GdkNoExtraLanguages()
    { return true; }

// The R398 clean read fills
// the racial block: +1
// constitution, saving throw
// bonuses based on total
// constitution, 6"
// infravision, and detection
// of approximate depth
// underground.
inline int uamm3GdkConBonus()
    { return 1; }

inline bool uamm3GdkSavesByCon()
    { return true; }

inline int uamm3GdkInfravisionIn()
    { return 6; }

inline bool uamm3GdkDepthDetection()
    { return true; }

inline bool uamm3GdkRacialBlockGarbles()
    { return false; }

// ---- the girdle of many
// pouches ----
// A broad waist-belt that
// radiates a strong
// enchantment dweomer with a
// fainter alteration aura.
inline bool uamm3GmpStrongEnchantmentAura()
    { return true; }

inline bool uamm3GmpFainterAlterationAura()
    { return true; }

// Eight apparent pouches on
// the inner front, seven
// more behind each - 64
// magical pouches in all.
inline int uamm3GmpApparentPouches()
    { return 8; }

inline int uamm3GmpTotalPouches()
    { return 64; }

inline int uamm3GmpBehindEach()
    { return 7; }

// Each pouch is a miniature
// bag of holding: one cubic
// foot, up to 10 pounds.
inline int uamm3GmpPouchCuFt()
    { return 1; }

inline int uamm3GmpPouchLbs()
    { return 10; }

// Responds to the wearer's
// thoughts, providing a full
// pouch or an empty one as
// desired; prized by spell
// casters for components.
inline bool uamm3GmpRespondsToThoughts()
    { return true; }

inline bool uamm3GmpFullOrEmptyAsDesired()
    { return true; }

inline bool uamm3GmpPrizedBySpellcasters()
    { return true; }

// The R398 clean read shows
// the 50-years fragment as
// gem-of-insight bleed - the
// girdle text reads whole.
inline bool uamm3GmpTailSeamGarbles()
    { return false; }

// ---- the gloves of missile
// snaring ----
// A slight enchantment and
// alteration dweomer; once
// snugly worn they meld with
// the hands, nearly
// invisible - undetectable
// beyond 5 feet.
inline bool uamm3GmsSlightEnchantmentAura()
    { return true; }

inline bool uamm3GmsMeldWithHands()
    { return true; }

inline int uamm3GmsUndetectableBeyondFt()
    { return 5; }

// Either or both hands, if
// not already holding
// something, pick missiles
// out of the air - small,
// hand-hurled or
// weapon-propelled.
inline bool uamm3GmsNeedEmptyHands()
    { return true; }

inline bool uamm3GmsCatchHandHurled()
    { return true; }

inline bool uamm3GmsCatchWeaponPropelled()
    { return true; }

// The caught missile can be
// returned to the sender as
// an attack; a weapon that
// magically returns is
// merely stopped - no attack
// from returning it.
inline bool uamm3GmsCanReturnMissile()
    { return true; }

inline bool uamm3GmsMagicReturnPreventsOnly()
    { return true; }

inline bool uamm3GmsMagicReturnNoAttack()
    { return true; }

// ---- the gloves of
// thievery ----
// Normal-seeming handwear
// with a faint enchantment
// and alteration aura;
// invisible on the hands
// except to magical sight.
inline bool uamm3GthFaintEnchantmentAura()
    { return true; }

inline bool uamm3GthInvisibleExceptMagic()
    { return true; }

// The R398 clean read fills
// the level cells: open locks
// as a 7th-level thief, pick
// pockets as a 5th-level
// thief; a further +5% in
// both categories if the
// wearer is already at or
// above the stated levels.
inline int uamm3GthOpenLocksLevel()
    { return 7; }

inline int uamm3GthPickPocketsLevel()
    { return 5; }

inline bool uamm3GthLevelCellsGarble()
    { return false; }

inline int uamm3GthBonusPctIfAdvanced()
    { return 5; }

inline bool uamm3GthBonusNeedsStatedLevels()
    { return true; }

// ---- the hat of difference
// ----
// Donned, the wearer assumes
// the role of a character of
// any different profession -
// but only at 1st-level
// ability.
inline bool uamm3HdfAssumesOtherProfession()
    { return true; }

inline bool uamm3HdfFirstLevelAbilityOnly()
    { return true; }

// Experience gained is in the
// assumed role only, and
// cumulative: a level reached
// is retained on later
// wearings.
inline bool uamm3HdfXpInAssumedRole()
    { return true; }

inline bool uamm3HdfXpCumulative()
    { return true; }

inline bool uamm3HdfLevelRetainedOnRewearing()
    { return true; }

// Progress continues
// indefinitely while worn;
// the loss conditions (the
// discarded-or-stolen seam)
// OCR-scramble - flagged.
inline bool uamm3HdfProgressIndefinite()
    { return true; }

inline bool uamm3HdfLostIfDiscarded()
    { return true; }

// The R398 clean read fills
// the loss seam: discard,
// loss, theft, or a 24-hour
// absence beyond a one-mile
// radius loses all assumed
// experience.
inline int uamm3HdfLossRadiusMiles()
    { return 1; }

inline int uamm3HdfLossHours()
    { return 24; }

inline bool uamm3HdfLostIfStolen()
    { return true; }

inline bool uamm3HdfLossSeamGarbles()
    { return false; }

// Hit points and ability
// scores are always the
// actual character's.
inline bool uamm3HdfHitPointsStayActual()
    { return true; }

inline bool uamm3HdfAbilityScoresStayActual()
    { return true; }

// ---- the hat of disguise
// ----
// A powerful enchantment that
// alters the appearance:
// hair, eyes, complexion any
// color; sex male or female;
// facial features highly
// mutable.
inline bool uamm3HdgHairAnyColor()
    { return true; }

inline bool uamm3HdgEyesAnyColor()
    { return true; }

inline bool uamm3HdgComplexionAnyColor()
    { return true; }

inline bool uamm3HdgSexChange()
    { return true; }

inline bool uamm3HdgFacialMutable()
    { return true; }

// Height varies plus or minus
// 25%, weight plus or minus
// 50% of actual.
inline int uamm3HdgHeightPct()
    { return 25; }

inline int uamm3HdgWeightPct()
    { return 50; }

// Removing the hat dispels
// the dweomer instantly, but
// it can be used over and
// over - the R398 clean read
// fills the removal seam.
inline bool uamm3HdgRemovalDispelsInstantly()
    { return true; }

inline bool uamm3HdgReusableOverAndOver()
    { return true; }

inline bool uamm3HdgRemovalSeamGarbles()
    { return false; }

// The hat itself can appear
// as a comb, ribbon, head
// band, fillet, cap, coif,
// hood, helmet, etc.
inline bool uamm3HdgAppearsAsAccessories()
    { return true; }

// ---- the hat of stupidity
// ----
// Totally indistinguishable
// from other magical
// headgear, even under
// detection; only placing it
// on the head reveals its
// powers.
inline bool uamm3HdsIndistinguishableByDetection()
    { return true; }

inline bool uamm3HdsOnlyWearingReveals()
    { return true; }

// The wearer believes the hat
// beneficial and always wants
// it on, especially for
// thinking and spell casting.
inline bool uamm3HdsWearerBelievesBeneficial()
    { return true; }

inline bool uamm3HdsWearerWantsHatOn()
    { return true; }

// Intelligence lowers to 7,
// or by 1 if already 7 or
// lower; only remove curse or
// similar magic frees the
// wearer. Fully clean in the
// extract.
inline int uamm3HdsIntLoweredTo()
    { return 7; }

inline int uamm3HdsIntLoweredByIfAlreadyLow()
    { return 1; }

inline bool uamm3HdsOnlyRemoveCurseFrees()
    { return true; }

// ---- Heward's handy
// haversack ----
// An ordinary-seeming
// well-made backpack, finely
// tanned leather with brass
// hardware and buckles.
inline bool uamm3HavOrdinaryAppearance()
    { return true; }

// Two side pouches, each
// appearing to hold about a
// quart (the "aquart" merge
// OCR-artifacts) but each a
// bag of holding for 2 cubic
// feet or 20 pounds; flagged.
inline int uamm3HavSidePouches()
    { return 2; }

inline int uamm3HavSidePouchCuFt()
    { return 2; }

inline int uamm3HavSidePouchLbs()
    { return 20; }

// The R398 clean read fills
// the merge: each side pouch
// appears large enough to
// hold about a quart of
// material.
inline bool uamm3HavAppearsQuart()
    { return true; }

inline bool uamm3HavQuartMergeGarbles()
    { return false; }

// The large central portion:
// 8 cubic feet, 80 pounds.
inline int uamm3HavCentralCuFt()
    { return 8; }

inline int uamm3HavCentralLbs()
    { return 80; }

// The greater dweomer: the
// item reached for is on top
// of whatever else is in that
// part - no digging.
inline bool uamm3HavSoughtItemOnTop()
    { return true; }

// The haversack and its
// contents gain +2 on all
// saving throws.
inline int uamm3HavSaveBonus()
    { return 2; }

// ---- the horn of fog ----
// A small buglelike device
// that blows a thick cloud of
// heavy fog equal to an
// illusionist's fog cloud
// spell; each round of
// blowing creates a 10-foot
// cubic cloud.
inline bool uamm3HfgSmallBuglelike()
    { return true; }

inline bool uamm3HfgFogCloudEquivalent()
    { return true; }

inline int uamm3HfgCubePerRoundFt()
    { return 10; }

// The vapors last 2-8 rounds
// after the last round of
// winding; a round's pause
// begins a new cloud.
inline int uamm3HfgCloudLastsLoRounds()
    { return 2; }

inline int uamm3HfgCloudLastsHiRounds()
    { return 8; }

inline bool uamm3HfgPauseStartsNewCloud()
    { return true; }

// The R398 clean read prints
// the book's own seam: each
// cloud lasts but 2-8 more
// minutes after the next note
// begins.
inline int uamm3HfgDriftMinutesLo()
    { return 2; }

inline int uamm3HfgDriftMinutesHi()
    { return 8; }

inline bool uamm3HfgRoundsMinutesSeamGarbles()
    { return false; }

// ---- the horn of goodness
// ----
// The second horn's header is
// eaten by the fog merge; the
// mechanics read. It adapts
// to the ethical disposition
// of its possessor - good or
// evil effect by alignment;
// flagged.
inline bool uamm3HgdAdaptsToEthicalDisposition()
    { return true; }

// The R398 clean read prints
// the eaten header: the horn
// is named goodness/evil.
inline bool uamm3HgdNamedGoodnessEvil()
    { return true; }

inline bool uamm3HgdHeaderSeamGarbles()
    { return false; }

// Absolutely neutral ethical
// alignment: no power
// whatsoever.
inline bool uamm3HgdNeutralNoPower()
    { return true; }

// A good owner winds a
// protection from evil in a
// 10-foot radius for 10
// rounds; each friendly or
// allied creature in the area
// is affected as if granted
// the spell.
inline bool uamm3HgdGoodProtectionFromEvil()
    { return true; }

inline int uamm3HgdRadiusFt()
    { return 10; }

inline int uamm3HgdDurationRounds()
    { return 10; }

inline bool uamm3HgdAlliesAffectedToo()
    { return true; }

// An evil horn works the
// reverse of the noted spell
// within the area; the horn
// is blown but once per day.
inline bool uamm3HgdEvilReversesSpell()
    { return true; }

inline bool uamm3HgdOncePerDay()
    { return true; }

// ---- the part ledger ----
// Eleven G-H items, all
// fully clean - the R398
// clean read filled the nine
// flagged holes, none fully
// garbled.
inline int uamm3PartItemTotal()
    { return 11; }

inline int uamm3PartCleanCount()
    { return 11; }

inline int uamm3PartFlaggedCount()
    { return 0; }

inline int uamm3PartGarbledCount()
    { return 0; }

}   // namespace rules

