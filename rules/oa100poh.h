// =========================================================================================
// Adnd1 - rules/oa100poh.h
// OA MONSTERS - THE P OH, printed capture pp. 281-282 - the drought spirit
// round
// census 651 -> 652.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 182 closed, 53 open - the p oh box flips
// (census 651 -> 652); NEXT - R730: the Shan Sao (capture pp. 282-283),
// prefix dkr (verify free at the landing), audit "R730 OA monsters Shan Sao
// audit", include after rules/oa100poh.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the very rare of the stat block (print capture p. 281)
inline int dkqFrequencyVeryRare()
    { return 1; }

// the appearing - the 1 of the stat block (print capture p. 281)
inline int dkqAppear()
    { return 1; }

// the armor class - the 4 of the stat block (print capture p. 281)
inline int dkqAC()
    { return 4; }

// the move - the 6 of the stat block (print capture p. 281)
inline int dkqMove()
    { return 6; }

// the hit dice - the 5 of the stat block (print capture p. 281)
inline int dkqHD()
    { return 5; }

// the in-lair percent - the 30% of the stat block (print capture p. 281)
inline int dkqLairPct()
    { return 30; }

// the treasure type - the Q of the stat block (print capture p. 281)
inline int dkqTreasureQ()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 281)
inline int dkqAttackCount()
    { return 1; }

// the damage minimum - the 1 of the 1-6 or by weapon type (print capture p.
// 281)
inline int dkqDmgMin()
    { return 1; }

// the damage maximum - the 6 of the 1-6 or by weapon type (print capture p.
// 281)
inline int dkqDmgMax()
    { return 6; }

// the damage clause - the 1-6 or by weapon type of the stat block (print
// capture p. 281)
inline int dkqDamageOrByWeapon()
    { return 1; }

// the special attacks - the drought of the stat block (print capture p. 281)
inline int dkqSpecialAttacksDrought()
    { return 1; }

// the special defenses - the +1 or better weapons to hit of the stat block
// (print capture p. 281)
inline int dkqPlusOneWeaponsToHit()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 281)
inline int dkqMRStandard()
    { return 1; }

// the intelligence - the high of the stat block (print capture p. 281)
inline int dkqIntHigh()
    { return 1; }

// the alignment - the chaotic evil of the stat block (print capture p. 281)
inline int dkqAlignmentChaoticEvil()
    { return 1; }

// the size class - the S of the stat block (print capture p. 281)
inline int dkqSizeSmall()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 281)
inline int dkqPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 281)
inline int dkqModesNil()
    { return 1; }

// ---- the xp line ----

// the xp base - the 280 of the V/280 + 5 per hp of the xp line (print capture
// p. 281)
inline int dkqXPBase()
    { return 280; }

// the xp per hit point - the 5 of the V/280 + 5/hp (print capture p. 281)
inline int dkqXPPerHP()
    { return 5; }

// ---- the wandering spirit ----

// the build - a small humanoid, standing two to three feet tall (print
// capture p. 281)
inline int dkqSmallHumanoid()
    { return 1; }

// the skin - ruddy bronze (print capture p. 281)
inline int dkqRuddyBronzeSkin()
    { return 1; }

// the hair - red (print capture p. 281)
inline int dkqRedHair()
    { return 1; }

// the habit - a wandering spirit, active during both day and night (print
// capture p. 281)
inline int dkqWanderingSpirit()
    { return 1; }

// the fear - greatly feared by the common folk because of its powers (print
// capture p. 281)
inline int dkqFearedByCommonFolk()
    { return 1; }

// the appeasement - often given gifts and offerings to appease it (print
// capture p. 281)
inline int dkqGivenOfferings()
    { return 1; }

// the haunt - most commonly encountered in agricultural lands well away from
// populous areas (print capture p. 281)
inline int dkqAgriculturalLands()
    { return 1; }

// ---- the drying touch ----

// the club - attacks either with a club cut from a withered and dead tree
// (print capture p. 282)
inline int dkqClubFromWitheredTree()
    { return 1; }

// the rod - or with an iron rod (print capture p. 282)
inline int dkqIronRod()
    { return 1; }

// the drying clause - in addition to the damage, the person struck must make
// a saving throw vs. spell (print capture p. 282)
inline int dkqHitForcesSaveVsSpell()
    { return 1; }

// the save success - if the saving throw is successful, the victim suffers no
// further effect (print capture p. 282)
inline int dkqSaveSuccessNoEffect()
    { return 1; }

// the save failure - the victim is dessicated by the drying touch, suffering
// the loss of one point of Constitution (print capture p. 282)
inline int dkqDessicatedOnFailure()
    { return 1; }

// the drying loss - the failed save costs one point of Constitution (print
// capture p. 282)
inline int dkqConLossPerHit()
    { return 1; }

// the Constitution floor - at Constitution 2 the character is unable to fight
// or stand (print capture p. 282)
inline int dkqConFloor()
    { return 2; }

// the death floor - if the Constitution is reduced to 0, the character is
// dead (print capture p. 282)
inline int dkqConZeroIsDeath()
    { return 1; }

// the invisibility - the p oh can become invisible at will (print capture p.
// 282)
inline int dkqInvisibleAtWill()
    { return 1; }

// ---- the drought ----

// the drought power - the power to create drought as per the wu jen spell
// (print capture p. 282)
inline int dkqCreatesDrought()
    { return 1; }

// the drought uses - the create drought power is usable once per week (print
// capture p. 282)
inline int dkqDroughtPerWeek()
    { return 1; }

// the drought duration - it remains until the p oh cancels it, is slain, or
// the spell is countered by ice blight (print capture p. 282)
inline int dkqDroughtUntilCancelled()
    { return 1; }

// the drought area - it affects a 5-mile diameter area (print capture p. 282)
inline int dkqDroughtDiameterMiles()
    { return 5; }

// the arrival - the p oh arrives in an area, finding some secure lair (print
// capture p. 282)
inline int dkqFindsSecureLair()
    { return 1; }

// the announcement - it appears to the peasants, announcing it has settled in
// their area and that they must venerate and appease it or else (print
// capture p. 282)
inline int dkqAnnouncesToPeasants()
    { return 1; }

// the collection - the p oh collects the offerings while invisible (print
// capture p. 282)
inline int dkqCollectsWhileInvisible()
    { return 1; }

// the truce - if the offerings are suitable, the p oh remains in the area,
// not causing any mischief (print capture p. 282)
inline int dkqSatisfiedByOfferings()
    { return 1; }

// the anger - should the offerings be insufficient, refused, or missed, the p
// oh becomes angered and causes a drought to settle on the area (print
// capture p. 282)
inline int dkqDroughtOnInsufficientOfferings()
    { return 1; }

// the shrines - it is not uncommon to see small shrines dedicated to the p oh
// set up along country roads (print capture p. 282)
inline int dkqCountryRoadShrines()
    { return 1; }

// the punishment clause - on rare occasions a p oh is sent to an area by the
// Celestial Emperor to punish the inhabitants for some failing or crime
// (print capture p. 282)
inline int dkqSentByCelestialEmperor()
    { return 1; }

// the languages - the language of its kind and the trade language (print
// capture p. 282)
inline int dkqSpeaksTwoLanguages()
    { return 1; }

}   // namespace rules
