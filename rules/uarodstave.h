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
// await the PDF - the gap
// item stays open. The rings
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

// ---- the extract ledger ----
// Four of the eleven
// descriptions pin; the
// seven garbled ones stay
// PDF-gated.
inline int uaroCleanCount()
    { return 4; }

inline int uaroGarbledCount()
    { return 7; }

inline int uaroTotalTypes()
    { return 11; }

}   // namespace rules

