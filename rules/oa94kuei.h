// =========================================================================================
// Adnd1 - rules/oa94kuei.h
// OA MONSTERS - THE KUEI, printed capture pp. 274-275 - the demon ghost round
// census 645 -> 646.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 176 closed, 59 open - the kuei box flips
// (census 645 -> 646); NEXT - R724: the Men Wako, the Sea Pirate (capture p.
// 275), prefix dkl (verify free at the landing), audit "R724 OA monsters Men
// Wako audit", include after rules/oa94kuei.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the rare of the stat block (print capture p. 274)
inline int dkkFrequencyRare()
    { return 1; }

// the appearing - the 1 of the stat block (print capture p. 274)
inline int dkkAppear()
    { return 1; }

// the kuei armor class - the AC -4 of the stat block (print capture p. 274)
inline int dkkAC()
    { return -4; }

// the kuei move - the 18 of the stat block (print capture p. 274)
inline int dkkMove()
    { return 18; }

// the hit dice minimum - the 3 of the 3 to 6 (print capture p. 274)
inline int dkkHDMin()
    { return 3; }

// the hit dice maximum - the 6 of the 3 to 6 (print capture p. 274)
inline int dkkHDMax()
    { return 6; }

// the in-lair - the nil of the stat block (print capture p. 274)
inline int dkkLairNil()
    { return 1; }

// the treasure type - the nil of the stat block (print capture p. 274)
inline int dkkTreasureNil()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 274)
inline int dkkAttackCount()
    { return 1; }

// the special attack - the possession of the stat block (print capture p.
// 274)
inline int dkkSpecialAttackPossession()
    { return 1; }

// the special defenses - the see below of the stat block (print capture p.
// 274)
inline int dkkSpecialDefensesSeeBelow()
    { return 1; }

// the magic resistance - the 10% of the stat block (print capture p. 274)
inline int dkkMRPct()
    { return 10; }

// the intelligence - the average to very of the stat block (print capture p.
// 274)
inline int dkkIntelligenceAvgToVery()
    { return 1; }

// the alignment - the see below of the stat block (print capture p. 274)
inline int dkkAlignmentSeeBelow()
    { return 1; }

// the size class - the M of the stat block (print capture p. 274)
inline int dkkSizeMedium()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 274)
inline int dkkPsionicNil()
    { return 1; }

// the attack and defense modes - the see below of the stat block (print
// capture p. 274)
inline int dkkModesSeeBelow()
    { return 1; }

// ---- the xp ladder ----

// the 3 HD xp base - the 180 of the IV/180 + 3 per hp (print capture p. 275)
inline int dkkXP3Base()
    { return 180; }

// the 3 HD xp per hit point - the 3 of the IV/180 + 3/hp (print capture p.
// 275)
inline int dkkXP3PerHP()
    { return 3; }

// the 4 HD xp base - the 275 of the V/275 + 4 per hp (print capture p. 275)
inline int dkkXP4Base()
    { return 275; }

// the 4 HD xp per hit point - the 4 of the V/275 + 4/hp (print capture p.
// 275)
inline int dkkXP4PerHP()
    { return 4; }

// the 5 HD xp base - the 405 of the V/405 + 5 per hp (print capture p. 275)
inline int dkkXP5Base()
    { return 405; }

// the 5 HD xp per hit point - the 5 of the V/405 + 5/hp (print capture p.
// 275)
inline int dkkXP5PerHP()
    { return 5; }

// the 6 HD xp base - the 725 of the VI/725 + 6 per hp (print capture p. 275)
inline int dkkXP6Base()
    { return 725; }

// the 6 HD xp per hit point - the 6 of the VI/725 + 6/hp (print capture p.
// 275)
inline int dkkXP6PerHP()
    { return 6; }

// ---- the demon ghost ----

// the nature - a spirit of the dead, now in the form of a demon-ghost (print
// capture p. 275)
inline int dkkSpiritOfTheDead()
    { return 1; }

// the first origin - a person dies unburied (print capture p. 275)
inline int dkkDiesUnburied()
    { return 1; }

// the second origin - dies with his life unfulfilled (print capture p. 275)
inline int dkkDiesUnfulfilled()
    { return 1; }

// the third origin - dies by violence unavenged (print capture p. 275)
inline int dkkDiesViolenceUnavenged()
    { return 1; }

// the look - appears exactly as the person did in life with a solid seeming
// body (print capture p. 275)
inline int dkkAppearsAsInLife()
    { return 1; }

// the incorporeal clause - cannot be physically touched, objects pass
// harmlessly through them (print capture p. 275)
inline int dkkCannotBeTouched()
    { return 1; }

// the sun clause - not affected by sunlight (print capture p. 275)
inline int dkkUnaffectedBySunlight()
    { return 1; }

// the night clause - most active at night (print capture p. 275)
inline int dkkMostActiveAtNight()
    { return 1; }

// the alignment rule - the alignment depends on the nature of the task they
// must fulfill (print capture p. 275)
inline int dkkAlignmentByTask()
    { return 1; }

// ---- the powers table ----

// the kuei table row count - the 3 to 6 hit dice ladder of the powers table
// (print capture p. 275)
inline int dkkKueiCount()
    { return 4; }

// the weapon needed to hit - the +1 at 3 HD up to the +4 at 6 HD (print
// capture p. 275)
inline int dkkPowersWeaponPlus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 0;
        }
    }

// the damage minimum - the 1 of the 1-6 up to the 1-12 ladder (print capture
// p. 275)
inline int dkkPowersDmgMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the damage maximum - the 6 at 3 HD, the 8 at 4 HD, the 10 at 5 HD, the 12
// at 6 HD (print capture p. 275)
inline int dkkPowersDmgMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 12;
        default:
            return 0;
        }
    }

// the power rule - the power of a kuei is dependent upon its hit dice (print
// capture p. 275)
inline int dkkPowersByHitDice()
    { return 1; }

// ---- the immunities ----

// the first power - can become ethereal at will (print capture p. 275)
inline int dkkEtherealAtWill()
    { return 1; }

// the second power - the ability to possess a person, as per the spell (print
// capture p. 275)
inline int dkkPossessAsPerSpell()
    { return 1; }

// the possession uses - the three times per day of the possess power (print
// capture p. 275)
inline int dkkPossessPerDay()
    { return 3; }

// the first immunity - immune to ESP (print capture p. 275)
inline int dkkImmuneToESP()
    { return 1; }

// the second immunity - immune to all charm, enchantment, illusion, and water
// spells (print capture p. 275)
inline int dkkImmuneToCharmEnchantIllusionWater()
    { return 1; }

// the third immunity - immune to all forms of psionic attack (print capture
// p. 275)
inline int dkkImmuneToPsionicAttack()
    { return 1; }

// the fourth immunity - suffers no damage from normal fire and cold (print
// capture p. 275)
inline int dkkNoNormalFireColdDamage()
    { return 1; }

// the fifth immunity - magical fire and cold only cause half the normal
// damage (print capture p. 275)
inline int dkkHalfMagicalFireCold()
    { return 1; }

// the magical element divisor - magical fire and cold only cause half damage,
// the damage halved (print capture p. 275)
inline int dkkMagicalFireColdMult()
    { return 2; }

// ---- the possession ----

// the opening move - normally attempts to possess a victim when encountered
// (print capture p. 275)
inline int dkkAttemptsPossessionFirst()
    { return 1; }

// the takeover - the form of the kuei disappears and it takes control of the
// victim (print capture p. 275)
inline int dkkFormDisappearsOnPossession()
    { return 1; }

// the purpose - uses the physical body to complete the task that binds it to
// the Prime Material Plane (print capture p. 275)
inline int dkkUsesBodyForTask()
    { return 1; }

// the first task - to seek vengeance on its killer (print capture p. 275)
inline int dkkTaskVengeance()
    { return 1; }

// the second task - to fulfill an oath (print capture p. 275)
inline int dkkTaskFulfillOath()
    { return 1; }

// the third task - to arrange the temple ceremonies necessary to release it
// (print capture p. 275)
inline int dkkTaskTempleCeremonies()
    { return 1; }

// the duration clause - when fulfilling an oath the kuei may possess the
// victim for a long time (print capture p. 275)
inline int dkkLongPossessionPossible()
    { return 1; }

// the tale - the kuei possessing her sister to fulfill an oath of marriage,
// remaining for many years before being discovered (print capture p. 275)
inline int dkkSisterMarriageStory()
    { return 1; }

// the first release - broken by the death of the victim (print capture p.
// 275)
inline int dkkBreakByVictimDeath()
    { return 1; }

// the second release - fulfillment of the task (print capture p. 275)
inline int dkkBreakByTaskFulfilled()
    { return 1; }

// the third release - exorcism or another spell intended to drive out spirits
// (print capture p. 275)
inline int dkkBreakByExorcism()
    { return 1; }

// the aftermath - the victim returns to his normal senses with no knowledge
// of what has transpired (print capture p. 275)
inline int dkkVictimRemembersNothing()
    { return 1; }

}   // namespace rules
