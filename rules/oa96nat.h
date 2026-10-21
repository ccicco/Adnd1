// =========================================================================================
// Adnd1 - rules/oa96nat.h
// OA MONSTERS - THE NAT, printed capture pp. 276-278 - the lesser spirit
// round
// census 647 -> 648.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 178 closed, 57 open - the nat box flips
// (census 647 -> 648); NEXT - R726: the Nature Spirits, the Lesser and the
// Greater (capture pp. 278-279), prefix dkn (verify free at the landing),
// audit "R726 OA monsters Nature Spirits audit", include after
// rules/oa96nat.h
//
namespace rules {

// ---- the stat table ----

// the nat table row count - the einsaung, the hkum yang, and the lu of the
// stat table (print capture p. 276)
inline int dkmNatCount()
    { return 3; }

// the armor class - the 2, the 0, and the -2 of the three columns; the hkum
// yang AC 0 collides with the sentinel, so this column census is 1 (print
// capture p. 276)
inline int dkmNatAC(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return -2;
        default:
            return 0;
        }
    }

// the move - the 12, the 12, and the 9 of the three columns (print capture p.
// 276)
inline int dkmNatMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 9;
        default:
            return 0;
        }
    }

// the hit dice - the 2, the 4, and the 8 of the three columns (print capture
// p. 276)
inline int dkmNatHD(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 8;
        default:
            return 0;
        }
    }

// the in-lair percent - the 100, the 100, and the 80 (print capture p. 276)
inline int dkmNatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        case 2:
            return 80;
        default:
            return 0;
        }
    }

// the attack count - the 1, the 2, and the 3 (print capture p. 276)
inline int dkmNatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return 0;
        }
    }

// the magic resistance - the 10%, the 30%, and the 10% (print capture p. 276)
inline int dkmNatMRPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// the weapon floor - the +1, the +2, and the +3 needed to hit the einsaung,
// the hkum yang, and the lu (print capture p. 277 and print capture p. 278)
inline int dkmNatWeaponPlus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return 0;
        }
    }

// the xp base - the 113 of the III/113 + 2, the 405 of the V/405 + 4, and the
// 2,250 of the VII/2,250 + 10, capture p. 277 (print capture p. 277)
inline int dkmNatXPBase(int b)
    {
        switch (b) {
        case 0:
            return 113;
        case 1:
            return 405;
        case 2:
            return 2250;
        default:
            return 0;
        }
    }

// the xp per hit point - the 2, the 4, and the 10 of the three xp lines
// (print capture p. 277)
inline int dkmNatXPPerHP(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// the damage minimum - the 1 of the 1-6 and of the 1-8 ladders (print capture
// p. 276)
inline int dkmNatDmgMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 0;
        }
    }

// the damage maximum - the 6 of the 1-6 and 1-6/1-6, the 8 of the 1-8/1-8/1-8
// (print capture p. 276)
inline int dkmNatDmgMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 0;
        }
    }

// the appearing - the 1 of every column of the stat table (print capture p.
// 276)
inline int dkmAppear()
    { return 1; }

// the einsaung frequency - the rare of the stat table header, where the
// capture carries the frequencies rather than a row (print capture p. 276)
inline int dkmEinsaungRare()
    { return 1; }

// the hkum yang frequency - the very rare of the stat table header (print
// capture p. 276)
inline int dkmHkumVeryRare()
    { return 1; }

// the lu frequency - the rare of the stat table header (print capture p. 276)
inline int dkmLuRare()
    { return 1; }

// the einsaung alignment - the chaotic good of the stat table (print capture
// p. 276)
inline int dkmEinsaungChaoticGood()
    { return 1; }

// the hkum yang alignment - the neutral of the stat table (print capture p.
// 276)
inline int dkmHkumNeutral()
    { return 1; }

// the lu alignment - the chaotic evil of the stat table (print capture p.
// 276)
inline int dkmLuChaoticEvil()
    { return 1; }

// the einsaung intelligence - the very of the stat table (print capture p.
// 276)
inline int dkmEinsaungIntVery()
    { return 1; }

// the hkum yang intelligence - the standard of the stat table (print capture
// p. 276)
inline int dkmHkumIntStandard()
    { return 1; }

// the lu intelligence - the low of the stat table (print capture p. 276)
inline int dkmLuIntLow()
    { return 1; }

// the einsaung size - the S of the stat table (print capture p. 276)
inline int dkmEinsaungSizeSmall()
    { return 1; }

// the hkum yang size - the M of the stat table (print capture p. 276)
inline int dkmHkumSizeMedium()
    { return 1; }

// the lu size - the M of the stat table (print capture p. 276)
inline int dkmLuSizeMedium()
    { return 1; }

// the treasure type - the nil of every column of the stat table (print
// capture p. 276)
inline int dkmTreasureNil()
    { return 1; }

// the psionic ability - the nil of every column of the stat table (print
// capture p. 276)
inline int dkmPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of every column, capture p. 277
// (print capture p. 277)
inline int dkmModesNil()
    { return 1; }

// the hkum yang special attack - the fear of the stat table (print capture p.
// 276)
inline int dkmHkumFearAttack()
    { return 1; }

// the lu special attack - the disease of the stat table (print capture p.
// 276)
inline int dkmLuDiseaseAttack()
    { return 1; }

// the special defenses - the see below of the stat table, the weapon floors
// and the auras riding below (print capture p. 276)
inline int dkmDefensesSeeBelow()
    { return 1; }

// ---- the lesser spirit nature ----

// the habitat - a group of lesser spirits found in tropical jungles (print
// capture p. 277)
inline int dkmTropicalJungleSpirits()
    { return 1; }

// the look - humanoid in appearance, with brightly colored skins and a
// general demonic cast (print capture p. 277)
inline int dkmHumanoidDemonicCast()
    { return 1; }

// the hair - wild and tangled (print capture p. 277)
inline int dkmWildTangledHair()
    { return 1; }

// the hands - they end in long, clawed fingernails (print capture p. 277)
inline int dkmLongClawedFingernails()
    { return 1; }

// the teeth - all have sharp, fanged teeth (print capture p. 277)
inline int dkmSharpFangedTeeth()
    { return 1; }

// the bite clause - although not all rats are able to bite effectively (print
// capture p. 277)
inline int dkmNotAllBiteEffectively()
    { return 1; }

// the first at-will power - become invisible (print capture p. 277)
inline int dkmAtWillInvisible()
    { return 1; }

// the second at-will power - levitate (print capture p. 277)
inline int dkmAtWillLevitate()
    { return 1; }

// the third at-will power - ESP (print capture p. 277)
inline int dkmAtWillESP()
    { return 1; }

// the fourth at-will power - comprehend languages (print capture p. 277)
inline int dkmAtWillComprehendLanguages()
    { return 1; }

// the fifth at-will power - deflection (print capture p. 277)
inline int dkmAtWillDeflection()
    { return 1; }

// the sixth at-will power - dream vision (print capture p. 277)
inline int dkmAtWillDreamVision()
    { return 1; }

// the seventh at-will power - possess animal (print capture p. 277)
inline int dkmAtWillPossessAnimal()
    { return 1; }

// the eighth at-will power - detect shapechanger (print capture p. 277)
inline int dkmAtWillDetectShapechanger()
    { return 1; }

// the ninth at-will power - quickgrowth (print capture p. 277)
inline int dkmAtWillQuickgrowth()
    { return 1; }

// the tenth at-will power - passwall (print capture p. 277)
inline int dkmAtWillPasswall()
    { return 1; }

// the eleventh at-will power - dancing blade (print capture p. 277)
inline int dkmAtWillDancingBlade()
    { return 1; }

// the immunity - they are immune to poisons and diseases (print capture p.
// 277)
inline int dkmImmuneToPoisonAndDisease()
    { return 1; }

// the element clause - half damage from electrical and fire attacks, no
// damage if the saving throw is made (print capture p. 277)
inline int dkmHalfElectricalFireDamage()
    { return 1; }

// the element divisor - the rats suffer half damage from electrical and fire
// attacks, no damage if the save is made (print capture p. 277)
inline int dkmElemDmgDivisor()
    { return 2; }

// the languages - the language of their own kind and the wu jen language
// common to their area (print capture p. 277)
inline int dkmSpeakOwnAndWuJenLanguage()
    { return 1; }

// ---- the einsaung nat ----

// the temper - a beneficial and helpful spirit if properly pleased by
// offerings of food and small treasures (print capture p. 277)
inline int dkmEinsaungBeneficialIfPleased()
    { return 1; }

// the residence - if properly beseeched it takes up residence in the house
// (print capture p. 277)
inline int dkmEinsaungTakesUpResidence()
    { return 1; }

// the luck - to have such a rat residing in one's home is a sign of good luck
// (' + P277 + ')
inline int dkmEinsaungGoodLuckSign()
    { return 1; }

// the departure - if the rat should ever leave the inhabitants take this as a
// sign of grievous fortune or evil to come (print capture p. 277)
inline int dkmEinsaungDepartureIllOmen()
    { return 1; }

// the home post - the home of the einsaung is always the south cornerpost of
// the house (print capture p. 277)
inline int dkmEinsaungSouthCornerpost()
    { return 1; }

// the actual lair - on the Ethereal Plane, though the einsaung centers its
// effects around the post (print capture p. 277)
inline int dkmEinsaungLairEthereal()
    { return 1; }

// the offerings - they are always placed at the south cornerpost (print
// capture p. 277)
inline int dkmEinsaungOfferingsAtPost()
    { return 1; }

// the einsaung at-will powers - become ethereal, beneficence, know history,
// slow poison, detect curse, protection from evil 10-foot radius, and
// polymorph self, all at will once per round (print capture p. 277)
inline int dkmEinsaungExtraAtWillPowers()
    { return 1; }

// the einsaung daily powers - omen and cure disease once per day (print
// capture p. 277)
inline int dkmEinsaungDailyPowers()
    { return 1; }

// the einsaung weekly powers - dispel evil and possess once per week (print
// capture p. 277)
inline int dkmEinsaungWeeklyPowers()
    { return 1; }

// the bless aura - radiates an aura with the same effect as a bless upon the
// owner and family of the house (print capture p. 277)
inline int dkmEinsaungBlessAura()
    { return 1; }

// the aura reach - the radius always covers the entire house and any attached
// grounds (print capture p. 277)
inline int dkmEinsaungAuraCoversHouse()
    { return 1; }

// the shyness - extremely shy, preferring to remain invisible and ethereal
// (print capture p. 277)
inline int dkmEinsaungShy()
    { return 1; }

// the distress clause - in times of distress it uses its powers without
// revealing itself or possesses a person and acts through them (print capture
// p. 277)
inline int dkmEinsaungActsThroughPossession()
    { return 1; }

// the combat clause - they prefer to avoid combat either directly or
// indirectly (print capture p. 277)
inline int dkmEinsaungAvoidsCombat()
    { return 1; }

// the aid - most often helps the household by providing advice, information
// which mysteriously appears, and good fortune (print capture p. 277)
inline int dkmEinsaungAidsByAdvice()
    { return 1; }

// the children clause - it reveals itself in order to play when only children
// are present (print capture p. 277)
inline int dkmEinsaungPlaysWithChildren()
    { return 1; }

// ---- the hkum yang nat ----

// the standing - although a protector, more feared than respected for its
// powers (print capture p. 277)
inline int dkmHkumFearedProtector()
    { return 1; }

// the charge - assumes the role of protector of an entire village, generally
// a village of fierce savages as befits its nature (print capture p. 277)
inline int dkmHkumVillageProtector()
    { return 1; }

// the residence - some central point, the head stakes of a headhunting tribe
// or the main building of a warrior tribe (print capture p. 277)
inline int dkmHkumCentralResidence()
    { return 1; }

// the offerings - given the spoils of the tribe's battles which it carries
// back to its lair on the Ethereal Plane (print capture p. 277)
inline int dkmHkumSpoilsToEthereal()
    { return 1; }

// the displeasure - should it grow displeased it brings misfortune and
// disaster to the village (print capture p. 277)
inline int dkmHkumDispleasureDisaster()
    { return 1; }

// the defense - so long as properly appeased it assists in the defense of the
// village from attack by both human and spirit enemies (print capture p. 277)
inline int dkmHkumDefendsVillage()
    { return 1; }

// the hkum yang at-will powers - purify food and drink, create spring, snake
// summon, dispel magic, castigate, oath, hail of stones, fire rain, elemental
// burst, and become ethereal, all usable at will once per round, the capture
// misreading wilt for will (print capture p. 277)
inline int dkmHkumExtraAtWillPowers()
    { return 1; }

// the animate powers - animate fire and animate wood, three times per day
// (print capture p. 277)
inline int dkmHkumAnimateFireWood()
    { return 1; }

// the animate uses - the hkum yang animate fire and animate wood three times
// per day (print capture p. 277)
inline int dkmAnimFireWoodPerDay()
    { return 3; }

// the hkum yang daily powers - quell and remove curse once per day (print
// capture p. 277)
inline int dkmHkumDailyPowers()
    { return 1; }

// the hkum yang weekly power - ancient curse once per week (print capture p.
// 277)
inline int dkmHkumWeeklyPowers()
    { return 1; }

// the fear aura - radiates an aura of fear which causes those who fail the
// saving throw vs. spell to flee in panic (print capture p. 277)
inline int dkmHkumFearAura()
    { return 1; }

// the fear aura radius - the 10-foot radius of the hkum yang fear aura (print
// capture p. 277)
inline int dkmFearRadius()
    { return 10; }

// the panic minimum - the 2 of the 2-5 rounds of fleeing in panic (print
// capture p. 277)
inline int dkmFearFleeMin()
    { return 2; }

// the panic maximum - the 5 of the 2-5 rounds of fleeing in panic (print
// capture p. 277)
inline int dkmFearFleeMax()
    { return 5; }

// the fear limit - the power only affects those who can see the hkum yang,
// either because it appears or is detected (print capture p. 277)
inline int dkmHkumFearSightOnly()
    { return 1; }

// ---- the lu nat ----

// the temper - totally evil and malicious, seeking to cause harm whenever
// possible (print capture p. 277)
inline int dkmLuTotallyEvil()
    { return 1; }

// the lair - always found in a graveyard or cemetery, where it disturbs the
// rest of the dead (print capture p. 277)
inline int dkmLuGraveyardLair()
    { return 1; }

// the wits - fortunately it is simple-minded and can be appeased by offerings
// of food (print capture p. 277)
inline int dkmLuSimpleMinded()
    { return 1; }

// the hunger clause - when it grows hungry it descends upon a village causing
// sickness and death until the offerings are resumed (print capture p. 277)
inline int dkmLuHungryDescent()
    { return 1; }

// the lu at-will powers - apparition, transfix, melt, fire shuriken, and
// stinking cloud, all at will once per round (print capture p. 278)
inline int dkmLuExtraAtWillPowers()
    { return 1; }

// the lu thrice powers - curse and creeping darkness three times per day
// (print capture p. 278)
inline int dkmLuCurseCreepingDarkness()
    { return 1; }

// the lu curse uses - the curse and creeping darkness three times per day
// (print capture p. 278)
inline int dkmLuCursePerDay()
    { return 3; }

// the lu daily powers - water to poison and wood rot once per day (print
// capture p. 278)
inline int dkmLuDailyPowers()
    { return 1; }

// the disease cloud - surrounded by an invisible cloud of disease (print
// capture p. 278)
inline int dkmLuDiseaseCloud()
    { return 1; }

// the disease cloud diameter - the 10-foot diameter of the lu invisible
// disease cloud (print capture p. 278)
inline int dkmDiseaseCloudDiameter()
    { return 10; }

// the cloud save - all within must make a successful saving throw vs. death
// each round spent in the cloud or become afflicted with a rotting disease
// (print capture p. 278)
inline int dkmLuCloudSaveVsDeath()
    { return 1; }

// the disease loss die - the 1d10 hit points per turn of the rotting disease
// (print capture p. 278)
inline int dkmDiseaseHPPerTurn()
    { return 10; }

// the cure clause - until cured the victim cannot heal naturally or benefit
// from healing spells (print capture p. 278)
inline int dkmLuNoHealingUntilCured()
    { return 1; }

}   // namespace rules
