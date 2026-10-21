// =========================================================================================
// Adnd1 - rules/oa99oni.h
// OA MONSTERS - THE ONI, printed capture pp. 280-281 - the fearsome spirit
// round
// census 650 -> 651.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 181 closed, 54 open - the oni box flips
// (census 650 -> 651); NEXT - R729: the P oh, the Lesser Spirit (capture pp.
// 281-282), prefix dkq (verify free at the landing), audit "R729 OA monsters
// P oh audit", include after rules/oa99oni.h
//
namespace rules {

// ---- the stat grid ----

// the oni table row count - the common, the go-zu, and the me-zu of the stat
// grid (print capture p. 280)
inline int dkpOniCount()
    { return 3; }

// the appearing minimum - the 1 of the 1-100, 1-20, and 1-20; the capture
// misreads i-100 for the 1-100 of the common (print capture p. 280)
inline int dkpOniAppearMin(int b)
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

// the appearing maximum - the 100 and the 20 and the 20 of the three columns
// (print capture p. 280)
inline int dkpOniAppearMax(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 20;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

// the armor class - the 4, the 0, and the 2 of the three columns (print
// capture p. 280)
inline int dkpOniAC(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 0;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// the move - the 9, the 9, and the 12 (print capture p. 280)
inline int dkpOniMove(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 9;
        case 2:
            return 12;
        default:
            return 0;
        }
    }

// the hit dice - the 8, the 12, and the 10 of the three columns (print
// capture p. 280)
inline int dkpOniHD(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 12;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// the hit dice bonus - the 0 of the common, the 8 of the 12 + 8, and the 5 of
// the 10 + 5 (print capture p. 280)
inline int dkpOniHDBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 8;
        case 2:
            return 5;
        default:
            return 0;
        }
    }

// the attack count - the 2, the 3, and the 2 (print capture p. 280)
inline int dkpOniAttacks(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// the magic resistance - the 0 of the common standard, the 20%, and the 40%
// (print capture p. 280)
inline int dkpOniMRPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 40;
        default:
            return 0;
        }
    }

// the xp base - the 650 of the VI/650 + 10, the 5,250 of the VIII/5,250 + 16,
// and the 3,150 of the VIII/3,150 + 14 (print capture p. 280)
inline int dkpOniXPBase(int b)
    {
        switch (b) {
        case 0:
            return 650;
        case 1:
            return 5250;
        case 2:
            return 3150;
        default:
            return 0;
        }
    }

// the xp per hit point - the 10, the 16, and the 14 of the three xp lines
// (print capture p. 280)
inline int dkpOniXPPerHP(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 16;
        case 2:
            return 14;
        default:
            return 0;
        }
    }

// the common oni frequency - the common of the stat grid header (print
// capture p. 280)
inline int dkpCommonOniCommon()
    { return 1; }

// the go-zu frequency - the very rare of the stat grid header (print capture
// p. 280)
inline int dkpGoZuVeryRare()
    { return 1; }

// the me-zu frequency - the very rare of the stat grid header (print capture
// p. 280)
inline int dkpMeZuVeryRare()
    { return 1; }

// the common oni alignment - the lawful evil of the stat grid, the capture
// row reading Lawful evil (print capture p. 280)
inline int dkpCommonChaoticEvil()
    { return 1; }

// the go-zu and me-zu alignment - the lawful neutral of both columns of the
// stat grid (print capture p. 280)
inline int dkpGoZuMeZuLawfulNeutral()
    { return 1; }

// the common oni intelligence - the average of the stat grid (print capture
// p. 280)
inline int dkpCommonIntAverage()
    { return 1; }

// the go-zu and me-zu intelligence - the high of both columns (print capture
// p. 280)
inline int dkpGoZuMeZuIntHigh()
    { return 1; }

// the size class - the L of all three columns of the stat grid (print capture
// p. 280)
inline int dkpSizeLarge()
    { return 1; }

// the psionic ability - the nil of all three columns (print capture p. 280)
inline int dkpPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of all three columns (print capture
// p. 280)
inline int dkpModesNil()
    { return 1; }

// the common oni special attacks - the spells of the stat grid (print capture
// p. 280)
inline int dkpCommonSpecialAttacksSpells()
    { return 1; }

// the go-zu and me-zu special attacks - the see below of both columns (print
// capture p. 280)
inline int dkpGoZuMeZuSpecialSeeBelow()
    { return 1; }

// the common oni special defenses - the nil of the stat grid (print capture
// p. 280)
inline int dkpCommonDefensesNil()
    { return 1; }

// the go-zu and me-zu special defenses - the regeneration of both columns
// (print capture p. 280)
inline int dkpGoZuMeZuRegeneration()
    { return 1; }

// the common oni magic resistance - the standard of the stat grid (print
// capture p. 280)
inline int dkpCommonMRStandard()
    { return 1; }

// ---- the fearsome spirit ----

// the nature - the oni are fearsome spirits who dwell in desolate and
// forbidding places (print capture p. 280)
inline int dkpFearsomeSpirits()
    { return 1; }

// the common height - stand seven to eight feet tall (print capture p. 280)
inline int dkpSevenToEightFeet()
    { return 1; }

// the eyes - have one to three eyes (print capture p. 280)
inline int dkpOneToThreeEyes()
    { return 1; }

// the horns - one or two horns on their head (print capture p. 280)
inline int dkpOneOrTwoHorns()
    { return 1; }

// the limbs - arms and legs covered with coarse hair (print capture p. 280)
inline int dkpCoarseHairLimbs()
    { return 1; }

// the hands - they end in dirty, thick talons (print capture p. 280)
inline int dkpDirtyThickTalons()
    { return 1; }

// the skin - normally red, but other colors including green, black, orange,
// and purple have been seen (print capture p. 280)
inline int dkpSkinNormallyRed()
    { return 1; }

// the blue skins - there are also blue-skinned oni, although these are more
// commonly known as ogre magi (print capture p. 280)
inline int dkpBlueSkinnedOgreMagi()
    { return 1; }

// the dress - imitates that of the local human population, although more
// ragged and dirty than their human counterparts (print capture p. 280)
inline int dkpDressImitatesHumans()
    { return 1; }

// ---- the common oni ----

// the common haunts - found living in rocky mountain regions, deserted ruins,
// graveyards, and other sites commonly considered haunted (print capture p.
// 280)
inline int dkpCommonHaunts()
    { return 1; }

// the highway clause - occasionally they take up residence along a lonely
// highway at a shrine or gate, terrorizing all who go by (print capture p.
// 280)
inline int dkpHighwayShrineTerror()
    { return 1; }

// the temper - bloodthirsty and cruel, attacking for food and the sheer
// delight of cruelty (print capture p. 280)
inline int dkpBloodthirstyCruel()
    { return 1; }

// the common weapons - they commonly fight with two-handed swords wielded in
// one hand or their powerful claws (print capture p. 280)
inline int dkpTwoHandedSwordOrClaws()
    { return 1; }

// the common oni polymorph uses - polymorph self three times per day (print
// capture p. 280)
inline int dkpPolymorphSelfPerDay()
    { return 3; }

// the common oni fly uses - fly as per the spell three times per day (print
// capture p. 280)
inline int dkpFlyPerDay()
    { return 3; }

// the common oni invisible uses - become invisible two times per day (print
// capture p. 280)
inline int dkpInvisiblePerDay()
    { return 2; }

// the common oni cloud trapeze uses - for themselves only once per day (print
// capture p. 280)
inline int dkpCloudTrapezePerDay()
    { return 1; }

// the fear power - cause fear at will (print capture p. 280)
inline int dkpCauseFearAtWill()
    { return 1; }

// the command - frequently found in command of lesser creatures such as
// bakemono, goblin rats, and gaki (print capture p. 280)
inline int dkpCommandsLesserCreatures()
    { return 1; }

// the summon chance - the 10% chance the common oni commands lesser creatures
// (print capture p. 280)
inline int dkpCommonSummonChancePct()
    { return 10; }

// the summon die - when encountered there is a 10% chance the oni is
// accompanied by 2d10 of these creatures, the die of the 2d10 (print capture
// p. 280)
inline int dkpCommonSummonDice()
    { return 10; }

// the lair court - encountered in their lair there are always 4d10 bakemono
// or goblin rats present, attending the court of the more powerful oni (print
// capture p. 281)
inline int dkpLairCourt()
    { return 1; }

// the lair guard die - in their lair there are always 4d10 bakemono or goblin
// rats present, the die of the 4d10 (print capture p. 281)
inline int dkpLairGuardDice()
    { return 10; }

// the common languages - able to speak the language of their kind and the
// languages of tengu, bakemono, hengeyokai, and the local human population
// (print capture p. 281)
inline int dkpCommonSpeaksFive()
    { return 1; }

// ---- the go-zu oni ----

// the go-zu heads - stand eight to nine feet tall with a hulking body and the
// heads of bulls (print capture p. 281)
inline int dkpGoZuBullHeads()
    { return 1; }

// the go-zu height minimum - the eight of the eight to nine feet tall (print
// capture p. 281)
inline int dkpGoZuHeightMinFt()
    { return 8; }

// the go-zu height maximum - the nine of the eight to nine feet tall (print
// capture p. 281)
inline int dkpGoZuHeightMaxFt()
    { return 9; }

// the go-zu standing - unlike the common oni, servants and soldiers of the
// Celestial Empire (print capture p. 281)
inline int dkpGoZuCelestialSoldiers()
    { return 1; }

// the army clause - the go-zu and the me-zu form the bulk of the Celestial
// Emperor army in times of trouble and insurrection (print capture p. 281)
inline int dkpGoZuMeZuEmperorsArmy()
    { return 1; }

// the dead lands - they also oversee the lands of the dead and escort the
// reluctant departed there (print capture p. 281)
inline int dkpGoZuOverseeLandsOfDead()
    { return 1; }

// the go-zu dress - they dress in armor and robes appropriate to their
// position as soldiers of the Celestial Emperor (print capture p. 281)
inline int dkpGoZuSoldierDress()
    { return 1; }

// the go-zu weapons - they fight with two-handed swords, spears, naginata,
// halberds, and tridents (print capture p. 281)
inline int dkpGoZuWeaponRoster()
    { return 1; }

// the go-zu combat - able to make two attacks with a weapon or their hands
// per round and gore with their horns (print capture p. 281)
inline int dkpGoZuTwoAttacksAndGore()
    { return 1; }

// the go-zu at-will powers - polymorph self, cause fear, become invisible,
// fly, and cast fire shuriken (print capture p. 281)
inline int dkpGoZuAtWillPowers()
    { return 1; }

// the go-zu cloud trapeze - twice per day (print capture p. 281)
inline int dkpGoZuCloudTrapezeTwicePerDay()
    { return 1; }

// the go-zu detection - they can automatically detect invisible creatures and
// objects (print capture p. 281)
inline int dkpGoZuAutoDetectInvisible()
    { return 1; }

// the regeneration rate - the go-zu and me-zu regenerate 3 hit points per
// round (print capture p. 281)
inline int dkpCommonRegenPerRound()
    { return 3; }

// the go-zu strength - equal to that of a hill giant (print capture p. 281)
inline int dkpGoZuHillGiantStrength()
    { return 1; }

// the go-zu languages - all human languages and those of tengu, oni,
// bakemono, animals, and the Celestial Court (print capture p. 281)
inline int dkpGoZuLanguages()
    { return 1; }

// ---- the me-zu oni ----

// the me-zu standing - the most important of all oni (print capture p. 281)
inline int dkpMeZuMostImportant()
    { return 1; }

// the me-zu look - ogre sized with the heads of horses (print capture p. 281)
inline int dkpMeZuHorseHeads()
    { return 1; }

// the me-zu rank - like the go-zu, servants and soldiers of the Celestial
// Emperor, although generally holding positions of higher rank within his
// army (print capture p. 281)
inline int dkpMeZuHigherRank()
    { return 1; }

// the me-zu extra tools - in addition to the weapons used by the go-zu oni,
// they are also known to use whips and lassos to deal with their victims
// (print capture p. 281)
inline int dkpMeZuWhipsAndLassos()
    { return 1; }

// the me-zu at-will powers - polymorph self, become invisible, cause fear,
// and fly (print capture p. 281)
inline int dkpMeZuAtWillPowers()
    { return 1; }

// the me-zu plane shifts - become ethereal or astral two times per day (print
// capture p. 281)
inline int dkpMeZuEtherealAstralTwicePerDay()
    { return 1; }

// the me-zu cloud trapeze - three times per day (print capture p. 281)
inline int dkpMeZuCloudTrapezeThricePerDay()
    { return 1; }

// the me-zu spellcasting - the spell casting ability of a wu jen of the same
// experience level as their hit dice (print capture p. 281)
inline int dkpMeZuWuJenSpellcasting()
    { return 1; }

// the me-zu sight - the sight abilities as per the true seeing spell in
// effect at all times (print capture p. 281)
inline int dkpMeZuTrueSeeingAlways()
    { return 1; }

// the me-zu languages - able to speak and understand any language (print
// capture p. 281)
inline int dkpMeZuAnyLanguage()
    { return 1; }

// the me-zu strength - equal to that of a stone giant (print capture p. 281)
inline int dkpMeZuStoneGiantStrength()
    { return 1; }

// the me-zu errand - when encountered they are on some mission assigned by
// the Celestial Empire and do not brook any interference or delay to this
// mission (print capture p. 281)
inline int dkpMeZuOnCelestialMission()
    { return 1; }

}   // namespace rules
