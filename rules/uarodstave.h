// ===========================================================================
// Adnd1 - rules/uarodstave.h
// The UA TREASURE (RODS and
// STAVES) prose pins, R379:
// the four clean descriptions
// (pp. 94-96) - the rod of
// alertness, the rod of
// security, the staff-mace,
// the staff of slinging. The
// seven garbled descriptions
// (flailing, passage,
// splendor, staff-spear,
// swarming insects, thunder
// and lightning, woodlands)
// the R397 clean read filled
// - the gap item closed. The
// rings
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the rod of alertness ----
// Indistinguishable from a
// footman's mace +1; upon
// usage the true powers
// reveal themselves.
inline bool uaroAlLooksFootmanMacePlusOne()
    { return true; }

// The possessor gains +1 on
// surprise die rolls and +1
// on initiative in combat.
inline int uaroAlSurpriseBonus()
    { return 1; }

inline int uaroAlInitiativeBonus()
    { return 1; }

// Grasped firmly, the
// concentrating possessor
// detects alignment, evil,
// good, illusion,
// invisibility, lie, or
// magic - none expend
// charges.
inline int uaroAlDetectCount()
    { return 7; }

inline bool uaroAlDetectsExpendNoCharge()
    { return true; }

// Planted and willed to
// alertness: senses any
// creature with intent to
// harm within a 12" radius.
inline int uaroAlSenseRadiusIn()
    { return 12; }

inline bool uaroAlSenseNeedsHarmfulIntent()
    { return true; }

// The eight flanges of the
// macelike head each cast a
// light spell along one
// cardinal direction at 6"
// range; a prayer effect
// covers friendlies in a 2"
// radius; then the mental
// alert warns them.
inline int uaroAlFlangeCount()
    { return 8; }

inline int uaroAlFlangeLightRangeIn()
    { return 6; }

inline int uaroAlPrayerRadiusIn()
    { return 2; }

inline bool uaroAlMentalAlertSent()
    { return true; }

// The animate object uses up
// to 16 objects placed
// around the perimeter of a
// 6"-radius circle centered
// on the rod.
inline int uaroAlAnimateMaxObjects()
    { return 16; }

inline int uaroAlAnimateCircleRadiusIn()
    { return 6; }

// Functions cost 1 charge,
// the animation 1 charge -
// all protective devices at
// once spend 2.
inline int uaroAlFunctionChargeCost()
    { return 1; }

inline int uaroAlAnimateChargeCost()
    { return 1; }

inline int uaroAlAllAtOnceCharges()
    { return 2; }

// Recharge by a cleric of
// 16th or higher level, so
// long as at least 1 charge
// remains.
inline int uaroAlRechargeClericLevel()
    { return 16; }

inline bool uaroAlRechargeNeedsChargeLeft()
    { return true; }

// ---- the rod of security ----
// Each charge creates the
// pocket paradise: the
// possessor plus up to 199
// others stay in safety,
// the maximum 200 days
// divided by the number of
// creatures.
inline int uaroSeDaysBase()
    { return 200; }

inline int uaroSeMaxCreatures()
    { return 200; }

inline int uaroSeOtherCreaturesMax()
    { return 199; }

// One creature stays 200
// days; four stay 50; sixty
// stay 3; a group of 101 to
// 200 stays one day only.
inline int uaroSeExampleOneDays()
    { return 200; }

inline int uaroSeExampleFourDays()
    { return 50; }

inline int uaroSeExampleSixtyDays()
    { return 3; }

inline int uaroSeGroup101to200Days()
    { return 1; }

// Within the paradise: no
// aging (except from
// magical causes such as a
// wish), healing and curing
// at twice the normal rate,
// fresh water and food
// (fruits and vegetables
// only), comfortable
// climate.
inline bool uaroSeNoAging()
    { return true; }

inline int uaroSeHealingRateMult()
    { return 2; }

inline bool uaroSeFoodFruitsVegetables()
    { return true; }

// On expiry all instantly
// reappear where they were;
// occupied space displaces
// the traveller enough for
// re-entry.
inline bool uaroSeReappearOnExpiry()
    { return true; }

// Recharge demands a cleric
// of 16th or higher AND a
// magic-user of 18th or
// higher, jointly.
inline int uaroSeRechargeClericLevel()
    { return 16; }

inline int uaroSeRechargeMuLevel()
    { return 18; }

// ---- the staff-mace ----
// A clerical weapon that
// appears a normal wooden
// trekking staff; a very
// faint alteration dweomer.
inline bool uaroSmClericalWeapon()
    { return true; }

inline bool uaroSmFaintAlterationDweomer()
    { return true; }

// Upon command, one of three
// forms: the quarterstaff +3
// iron-shod, the great mace
// (footman's mace +1, iron),
// the mace (horseman's mace
// +2, iron) - bronzewood
// with iron bands and tips.
inline int uaroSmFormCount()
    { return 3; }

inline int uaroSmQuarterstaffBonus()
    { return 3; }

inline bool uaroSmQuarterstaffIronShod()
    { return true; }

inline int uaroSmGreatMaceBonus()
    { return 1; }

inline int uaroSmMaceBonus()
    { return 2; }

inline bool uaroSmBronzewoodIronBound()
    { return true; }

// ---- the staff of
// slinging ----
// Appears nothing more than
// a +1 quarterstaff; the
// slinging power shows only
// to a druid and only a
// druid may employ it.
inline bool uaroSlAppearsPlusOne()
    { return true; }

inline bool uaroSlDruidOnly()
    { return true; }

// A heavy roughly spherical
// object up to nine inches
// in diameter and five
// pounds adheres to the
// staff end; the overhand
// swing releases the
// missile.
inline int uaroSlMaxObjectDiamInches()
    { return 9; }

inline int uaroSlMaxObjectPounds()
    { return 5; }

inline bool uaroSlReleaseIsOverhandArc()
    { return true; }

// The missile rises 1 foot
// per 1" traveled - or
// nearly vertical, 1 foot
// lateral per 1" of rise.
// Max range 18", short 6",
// medium 12".
inline int uaroSlRiseFeetPerInchRange()
    { return 1; }

inline int uaroSlMaxRangeIn()
    { return 18; }

inline int uaroSlShortRangeIn()
    { return 6; }

inline int uaroSlMediumRangeIn()
    { return 12; }

// One charge hurls a
// man-sized missile as a
// stone giant: range 30",
// 3-30 points per hit.
inline int uaroSlGiantHurlChargeCost()
    { return 1; }

inline int uaroSlGiantHurlRangeIn()
    { return 30; }

inline int uaroSlGiantHurlDmgLo()
    { return 3; }

inline int uaroSlGiantHurlDmgHi()
    { return 30; }

// Either mode bestows +1
// to hit and +1 per die to
// damage; recharge by a
// druid of 12th or higher.
inline int uaroSlHitBonus()
    { return 1; }

inline int uaroSlDmgPerDieBonus()
    { return 1; }

inline int uaroSlRechargeDruidLevel()
    { return 12; }

// ---- the rod of flailing (the R397
// clean read) ----
// A faint alteration dweomer; upon
// command a normal-seeming rod
// becomes a double-headed flail.
inline bool uaroFlailAlterationDweomer()
    { return true; }

inline bool uaroFlailDoubleHeaded()
    { return true; }

// Mounted or in close quarters it is
// the small horseman's weapon:
// 2-5/2-5; otherwise the footman's:
// 2-7/2-8 (S-M/L).
inline bool uaroFlailMountedIsHorseman()
    { return true; }

inline int uaroFlailHorsemanDmgHi()
    { return 5; }

inline int uaroFlailFootmanSmHi()
    { return 7; }

inline int uaroFlailFootmanLHi()
    { return 8; }

inline int uaroFlailDmgLo()
    { return 2; }

// Either form strikes at +3 to hit
// and damage.
inline int uaroFlailBonus()
    { return 3; }

// Both heads are checked when the
// possessor attacks: double hits on
// one opponent or two
// man-sized-or-smaller opponents
// standing side by side.
inline bool uaroFlailBothHeadsChecked()
    { return true; }

inline bool uaroFlailDoubleHitsPossible()
    { return true; }

// One charge grants +4 protection
// and +4 saving throws for 1 turn -
// without needing the weapon form.
inline int uaroFlailProtectionCharges()
    { return 1; }

inline int uaroFlailProtectionBonus()
    { return 4; }

inline int uaroFlailProtectionTurns()
    { return 1; }

// Transforming the rod into a weapon
// or back expends no charges.
inline bool uaroFlailTransformFree()
    { return true; }

// ---- the rod of passage (the R397
// clean read) ----
// One at a time, one per round:
// astral travel, dimension door,
// passwall, phase door, teleport
// without error.
inline int uaroPassFunctionCount()
    { return 5; }

inline int uaroPassPerRound()
    { return 1; }

// One charge activates the rod; each
// function is usable once per
// activation.
inline bool uaroPassEachOncePerActivation()
    { return true; }

inline int uaroPassActivationCharges()
    { return 1; }

// The charge holds one day or until
// all five functions are used; a
// second charge re-opens all five.
inline int uaroPassActiveDays()
    { return 1; }

inline bool uaroPassSecondChargeResets()
    { return true; }

// Astral travel may carry up to five
// creatures (the wielder included),
// but cancels the remaining
// functions.
inline int uaroPassAstralCreaturesMax()
    { return 5; }

inline bool uaroPassAstralCancelsRest()
    { return true; }

// The rod travels along and cannot
// be used or reactivated until
// returned from the Astral Plane.
inline bool uaroPassTravelsToAstral()
    { return true; }

inline bool uaroPassUnusableUntilReturned()
    { return true; }

// Recharge demands a magic-user of
// 20th or higher level.
inline int uaroPassRechargeMuLevel()
    { return 20; }

// ---- the rod of splendor (the R397
// clean read) ----
// The possessor carries a continual
// charisma of 18 while the rod is
// held; at 18 or greater there is no
// further enhancement.
inline int uaroSplendorChaContinual()
    { return 18; }

inline bool uaroSplendorNoGainAt18()
    { return true; }

// One charge creates and garbs noble
// apparel worth 7,000-10,000 gp (d4
// + 6).
inline int uaroSplendorGarbCharges()
    { return 1; }

inline int uaroSplendorGarbLoGp()
    { return 7000; }

inline int uaroSplendorGarbHiGp()
    { return 10000; }

// The fabric 1,000 gp, furs 5,000
// gp, jewel trim 1,000-4,000 gp.
inline int uaroSplendorFabricGp()
    { return 1000; }

inline int uaroSplendorFurGp()
    { return 5000; }

inline int uaroSplendorJewelLoGp()
    { return 1000; }

inline int uaroSplendorJewelHiGp()
    { return 4000; }

// Selling any part, or any forcible
// taking, destroys all of the
// apparel; freely given garments
// stay whole.
inline bool uaroSplendorSaleDestroysAll()
    { return true; }

inline bool uaroSplendorForcedDestroysAll()
    { return true; }

inline bool uaroSplendorGiftPersists()
    { return true; }

// A second charge while wearing the
// created garb is wasted.
inline bool uaroSplendorSecondChargeWasted()
    { return true; }

// One charge also raises a palatial
// silk tent of 1,500-3,000 square
// feet for 100 persons, lasting one
// day.
inline int uaroSplendorTentCharges()
    { return 1; }

inline int uaroSplendorTentLoSqFt()
    { return 1500; }

inline int uaroSplendorTentHiSqFt()
    { return 3000; }

inline int uaroSplendorTentPersons()
    { return 100; }

inline int uaroSplendorTentDays()
    { return 1; }

// The rod cannot be recharged.
inline bool uaroSplendorRechargeable()
    { return false; }

// ---- the staff-spear (the R397
// clean read) ----
// An alteration aura; three
// commands: a spear blade from the
// upper end, elongation to a full 12
// feet, recall to staff form.
inline bool uaroSsAlterationAura()
    { return true; }

inline int uaroSsCommandCount()
    { return 3; }

inline int uaroSsElongateFeet()
    { return 12; }

// Die-roll table: 1-6 is +1 at 1,000
// xp/ 5,000 gp; 7-10 +2,
// 1,500/7,500; 11-13 +3,
// 2,000/10,000; 14-16 +4,
// 2,500/15,000; 17-19 +5,
// 3,000/20,000; 20 +3*,
// 3,500/25,000.
inline int uaroSsTableRowCount()
    { return 6; }

inline int uaroSsBonusMin()
    { return 1; }

inline int uaroSsBonusMax()
    { return 5; }

inline int uaroSsTopRollBonus()
    { return 3; }

// The starred 20 entry does damage
// as a ranseur(2-8) yet still
// thrusts and sets as a spear.
inline bool uaroSsTopRanseur()
    { return true; }

inline int uaroSsRanseurDmgLo()
    { return 2; }

inline int uaroSsRanseurDmgHi()
    { return 8; }

inline int uaroSsXpLo()
    { return 1000; }

inline int uaroSsXpHi()
    { return 3500; }

inline int uaroSsGpLo()
    { return 5000; }

inline int uaroSsGpHi()
    { return 25000; }

// ---- the staff of swarming insects
// (the R397 clean read) ----
// Cleric-types only (cleric, druid,
// shaman, witch doctor); a charge
// creates a swarm of winged biting
// and stinging insects.
inline bool uaroSwarmClericalOnly()
    { return true; }

// Range 6" plus 1" per clerical
// level.
inline int uaroSwarmRangeBaseIn()
    { return 6; }

inline int uaroSwarmRangePerLevelIn()
    { return 1; }

// Sixty insects plus ten per level;
// every ten insects inflict 1 point
// of damage regardless of armor
// class.
inline int uaroSwarmBaseInsects()
    { return 60; }

inline int uaroSwarmInsectsPerLevel()
    { return 10; }

inline int uaroSwarmInsectsPerDmg()
    { return 10; }

inline bool uaroSwarmIgnoresArmorClass()
    { return true; }

// Creatures larger than man-sized
// with natural armor class 5 or
// better are unaffected; the victim
// can do nothing but dislodge or
// kill the swarm.
inline int uaroSwarmLargeNaturalAcMin()
    { return 5; }

// The attack lasts 1 round.
inline int uaroSwarmAttackRounds()
    { return 1; }

// One carved insect-shape vanishes
// per use - the carvings count the
// charges.
inline bool uaroSwarmCarvingsVanish()
    { return true; }

// As many as 50 charges initially;
// never recharged.
inline int uaroSwarmMaxCharges()
    { return 50; }

inline bool uaroSwarmRechargeable()
    { return false; }

// ---- the staff of thunder and
// lightning (the R397 clean read)
// ----
// A stout quarterstaff of ash, oak
// or bronzewood, iron-bound with
// silver rivets; a +2 weapon without
// any charge.
inline int uaroThunderBaseBonus()
    { return 2; }

// THUNDER: strikes at +3; a failed
// save versus rods staves wands
// stuns the opponent for the rest of
// the round struck and grants it
// last initiative the following
// round; 1 charge.
inline int uaroThunderStrikeBonus()
    { return 3; }

inline int uaroThunderStunCharges()
    { return 1; }

inline bool uaroThunderStunRestOfRound()
    { return true; }

inline bool uaroThunderLastInitiative()
    { return true; }

// LIGHTNING: 2-12 extra points of
// shock accompany the strike; metal
// armor is discounted - the target
// is effectively armor class 10; 1
// charge.
inline int uaroThunderShockDmgLo()
    { return 2; }

inline int uaroThunderShockDmgHi()
    { return 12; }

inline int uaroThunderShockCharges()
    { return 1; }

inline bool uaroThunderDiscountsMetal()
    { return true; }

inline int uaroThunderEffectiveAc()
    { return 10; }

// THUNDERCLAP: a cone of deafening
// noise, half an inch at the apex,
// 4" long, 2" wide at the far end;
// failed saves stun 1-2 rounds and
// deafen 1-2 more; savers are deaf
// 1-4 rounds only; 2 charges.
inline int uaroClapCharges()
    { return 2; }

inline int uaroClapApexHalfIn()
    { return 1; }

inline int uaroClapLengthIn()
    { return 4; }

inline int uaroClapFarWidthIn()
    { return 2; }

inline int uaroClapStunLo()
    { return 1; }

inline int uaroClapStunHi()
    { return 2; }

inline int uaroClapDeafLo()
    { return 1; }

inline int uaroClapDeafHi()
    { return 2; }

inline int uaroClapSaverDeafLo()
    { return 1; }

inline int uaroClapSaverDeafHi()
    { return 4; }

// LIGHTNING STROKE: eight dice
// (8d6), 16-48 points, rolls of 1
// count as 2; single or forked; 2
// charges.
inline int uaroStrokeCharges()
    { return 2; }

inline int uaroStrokeDice()
    { return 8; }

inline int uaroStrokeDmgLo()
    { return 16; }

inline int uaroStrokeDmgHi()
    { return 48; }

inline bool uaroStrokeOnesAsTwo()
    { return true; }

inline bool uaroStrokeForkedOrSingle()
    { return true; }

// THUNDER AND LIGHTNING: the
// thunderclap plus a forked bolt;
// 8d6 with 1s and 2s counted as 3,
// 24-48 points; a save means
// deafness and half damage; 4
// charges.
inline int uaroCombinedCharges()
    { return 4; }

inline int uaroCombinedDice()
    { return 8; }

inline int uaroCombinedDmgLo()
    { return 24; }

inline int uaroCombinedDmgHi()
    { return 48; }

inline bool uaroCombinedOnesTwosAsThree()
    { return true; }

inline bool uaroCombinedSaveDeafHalf()
    { return true; }

// Any function activates in segments
// equal to the charges it expends.
inline bool uaroActivationSegsEqualCharges()
    { return true; }

// ---- the staff of the woodlands
// (the R397 clean read) ----
// Oak, ash, or yew, bronze-bound and
// shod; effective only for a druid.
inline bool uaroWoodDruidOnly()
    { return true; }

// Per charge: wall of thorns; animal
// friendship plus speak with
// animals; animate tree.
inline int uaroWoodChargePowerCount()
    { return 3; }

inline int uaroWoodThornWallCharges()
    { return 1; }

inline int uaroWoodAnimalCharges()
    { return 1; }

inline int uaroWoodAnimateCharges()
    { return 1; }

// The animated tree moves at 3" and
// attacks as a largest-sized treant
// - a virtual treant for eight
// rounds per charge.
inline int uaroWoodAnimateMoveIn()
    { return 3; }

inline int uaroWoodAnimateRounds()
    { return 8; }

// One round animates the tree; it
// re-roots on the eighth round, so
// only six rounds are usable.
inline int uaroWoodAnimateRoundToStart()
    { return 1; }

inline int uaroWoodAnimateUsableRounds()
    { return 6; }

inline bool uaroWoodAnimateRerootsOnEighth()
    { return true; }

// Weapon values with once-per-day
// extras: the +4 staff has none; the
// +3 adds pass without trace; the +2
// adds barkskin; the +1 adds the
// tree spell.
inline int uaroWoodTopBonus()
    { return 4; }

inline int uaroWoodPlus3Extras()
    { return 1; }

inline int uaroWoodPlus2Extras()
    { return 2; }

inline int uaroWoodPlus1Extras()
    { return 3; }

inline bool uaroWoodExtrasOncePerDay()
    { return true; }

// Even chances (d4) decide the staff
// sort discovered.
inline int uaroWoodTypeDieSides()
    { return 4; }
// ---- the extract ledger ----
// All eleven descriptions
// pin - the R397 clean read
// filled the seven the
// extract garbled.
inline int uaroCleanCount()
    { return 11; }

inline int uaroGarbledCount()
    { return 0; }

inline int uaroTotalTypes()
    { return 11; }

}   // namespace rules

