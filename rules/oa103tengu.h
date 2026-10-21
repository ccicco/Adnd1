// =========================================================================================
// Adnd1 - rules/oa103tengu.h
// OA MONSTERS - THE TENGU, printed capture pp. 284-285 - the mountain spirit
// round
// census 654 -> 655.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 185 closed, 50 open - the tengu box flips
// (census 654 -> 655); NEXT - R733: the Chapter 13 treasure opener, the
// Magical Items Usable By Class table (capture p. 285), prefix dku (verify
// free at the landing), audit "R733 OA treasure class usage audit", include
// after rules/oa103tengu.h
//
namespace rules {

// ---- the stat grid ----

// the tengu table row count - the crow-headed and the humanoid of the stat
// grid (print capture p. 284)
inline int dktTenguCount()
    { return 2; }

// the appearing minimum - the 1 of the 1-4 and the 1-3 (print capture p. 284)
inline int dktTenguAppearMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        default:
            return 0;
        }
    }

// the appearing maximum - the 4 and the 3 of the two columns (print capture
// p. 284)
inline int dktTenguAppearMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        default:
            return 0;
        }
    }

// the armor class - the 6 of the crow and the 4 of the humanoid (print
// capture p. 284)
inline int dktTenguAC(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        default:
            return 0;
        }
    }

// the ground move - the 9 of the crow and the 12 whole of the humanoid, the
// half pinned as dktHumMoveHalf below, the capture misreading 12 1 for the 12
// 1/2 (print capture p. 284)
inline int dktTenguMoveGround(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 12;
        default:
            return 0;
        }
    }

// the fly move - the 24 of the crow and the 15 of the humanoid (print capture
// p. 284)
inline int dktTenguMoveFly(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 15;
        default:
            return 0;
        }
    }

// the hit dice minimum - the 2 of the 2 to 5 and the 5 of the 5 to 10 (print
// capture p. 284)
inline int dktTenguHDMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        default:
            return 0;
        }
    }

// the hit dice maximum - the 5 and the 10 of the two ladders (print capture
// p. 284)
inline int dktTenguHDMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        default:
            return 0;
        }
    }

// the in-lair percent - the 10% and the 20% (print capture p. 284)
inline int dktTenguLairPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        default:
            return 0;
        }
    }

// the attack count - the 1 of the crow and the 2 of the humanoid (print
// capture p. 284)
inline int dktTenguAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
            return 0;
        }
    }

// the damage minimum - the 1 of the 1-8 and the 1-6 (print capture p. 284)
inline int dktTenguDmgMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        default:
            return 0;
        }
    }

// the damage maximum - the 8 of the 1-8 and the 6 of the 1-6 (print capture
// p. 284)
inline int dktTenguDmgMax(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        default:
            return 0;
        }
    }

// the crow frequency - the rare of the stat grid (print capture p. 284)
inline int dktCrowRare()
    { return 1; }

// the humanoid frequency - the rare of the stat grid (print capture p. 284)
inline int dktHumRare()
    { return 1; }

// the maneuver class - the C of both move lines of the stat grid (print
// capture p. 284)
inline int dktMCC()
    { return 1; }

// the treasure type - the C of both columns (print capture p. 284)
inline int dktTreasureC()
    { return 1; }

// the crow special attacks - the spells of the stat grid (print capture p.
// 284)
inline int dktCrowSpecialAttacksSpells()
    { return 1; }

// the humanoid special attacks - the spells of the stat grid (print capture
// p. 284)
inline int dktHumSpecialAttacksSpells()
    { return 1; }

// the crow special defenses - the nil of the stat grid (print capture p. 284)
inline int dktCrowDefensesNil()
    { return 1; }

// the humanoid special defense - the invisibility of the stat grid (print
// capture p. 284)
inline int dktHumInvisibility()
    { return 1; }

// the magic resistance - the standard of both columns (print capture p. 284)
inline int dktMRStandard()
    { return 1; }

// the crow intelligence - the low to average of the stat grid (print capture
// p. 284)
inline int dktCrowIntLowToAverage()
    { return 1; }

// the humanoid intelligence - the high to very of the stat grid (print
// capture p. 284)
inline int dktHumIntHighToVery()
    { return 1; }

// the crow alignment - the chaotic evil of the stat grid (print capture p.
// 284)
inline int dktCrowChaoticEvil()
    { return 1; }

// the humanoid alignment - the chaotic neutral of the stat grid (print
// capture p. 284)
inline int dktHumChaoticNeutral()
    { return 1; }

// the size class - the S of both columns (print capture p. 284)
inline int dktSizeSmall()
    { return 1; }

// the psionic ability - the nil of both columns (print capture p. 284)
inline int dktPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of both columns (print capture p.
// 284)
inline int dktModesNil()
    { return 1; }

// the humanoid damage clause - the 1-6 or by weapon type of the stat grid
// (print capture p. 284)
inline int dktHumDamageByWeapon()
    { return 1; }

// the half of the humanoid ground move - the print 12 1/2 pinned whole as 12
// with the half here, the ints-only splice mirror (print capture p. 284)
inline int dktHumMoveHalf()
    { return 1; }

// ---- the crow xp ladder ----

// the crow xp rung count - the 2 to 5 HD ladder of the crow-headed tengu
// (print capture p. 284)
inline int dktCrowXPCount()
    { return 4; }

// the crow xp base - the 28, 50, 85, and 130 of the four rungs, the capture
// misreading 11 for the II and III rungs (print capture p. 284)
inline int dktXPCrowBase(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 50;
        case 2:
            return 85;
        case 3:
            return 130;
        default:
            return 0;
        }
    }

// the crow xp per hit point - the 2, 3, 4, and 5 of the four rungs (print
// capture p. 284)
inline int dktXPCrowPerHP(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        default:
            return 0;
        }
    }

// ---- the humanoid xp ladder ----

// the humanoid xp rung count - the 5 to 10 HD ladder of the humanoid tengu,
// the capture misreading 70 for the 10 HD rung (print capture p. 284)
inline int dktHumXPCount()
    { return 6; }

// the humanoid xp base - the 360, 625, 950, 1,450, 2,300, and 3,450 of the
// six rungs (print capture p. 284)
inline int dktXPHumBase(int b)
    {
        switch (b) {
        case 0:
            return 360;
        case 1:
            return 625;
        case 2:
            return 950;
        case 3:
            return 1450;
        case 4:
            return 2300;
        case 5:
            return 3450;
        default:
            return 0;
        }
    }

// the humanoid xp per hit point - the 5, 6, 8, 10, 12, and 14 of the six
// rungs (print capture p. 284)
inline int dktXPHumPerHP(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        case 5:
            return 14;
        default:
            return 0;
        }
    }

// ---- the race ----

// the nature - a race of birdlike humanoid creatures found in uninhabited
// mountain areas, though not far from settled lands (print capture p. 284)
inline int dktBirdlikeHumanoids()
    { return 1; }

// the lore - many people believe they were the original inhabitants of the
// land before the arrival of humans (print capture p. 284)
inline int dktOriginalInhabitants()
    { return 1; }

// the displacement - once the humans arrived with their organization and
// culture, the tengu were pushed deeper and deeper into the mountains (print
// capture p. 284)
inline int dktPushedIntoMountains()
    { return 1; }

// the haunts - they now dwell in forest glades, meadows, and on the banks of
// streams and ponds (print capture p. 284)
inline int dktGladesAndBanks()
    { return 1; }

// the society - somewhat solitary creatures who do not form villages or
// permanent communities (print capture p. 284)
inline int dktNoVillages()
    { return 1; }

// the split - there are two types of tengu, the crow-headed and the humanoid
// (print capture p. 284)
inline int dktTwoTypes()
    { return 1; }

// ---- the crow-headed tengu ----

// the crow build - a humanoid two to three feet tall with the head and beak
// of a crow (print capture p. 284)
inline int dktCrowTwoToThreeFeet()
    { return 1; }

// the crow wings - feathered wings sprout from between their shoulder blades
// (print capture p. 284)
inline int dktCrowFeatheredWings()
    { return 1; }

// the crow temper - evil and malicious, seeking to cause harm to all humans
// who stray into their territory (print capture p. 284)
inline int dktCrowEvilMalicious()
    { return 1; }

// the crow weapons - they fight with katana and wakizashi (print capture p.
// 284)
inline int dktCrowKatanaWakizashi()
    { return 1; }

// the crow languages - the language of tengu, that of animals, and the human
// language of the area (print capture p. 284)
inline int dktCrowSpeaksThree()
    { return 1; }

// the crow mimicry - able to perfectly mimic voices of those they have heard
// (print capture p. 284)
inline int dktCrowPerfectMimicry()
    { return 1; }

// the crow spells - able to use polymorph self and shout spells three times
// per day (print capture p. 284)
inline int dktCrowPolymorphAndShout()
    { return 1; }

// the polymorph uses - the crow tengu use polymorph self and shout three
// times per day; the humanoid tengu use polymorph self, shout, and phantasmal
// force three times per day (print capture p. 284)
inline int dktPolymorphPerDay()
    { return 3; }

// the crow standing - they have lower status than the humanoid tengu and
// follow orders from these creatures in deference to their rank (print
// capture p. 284)
inline int dktCrowLowerStatus()
    { return 1; }

// ---- the humanoid tengu ----

// the humanoid build - stand from three to four feet tall (print capture p.
// 284)
inline int dktHumThreeToFourFeet()
    { return 1; }

// the humanoid look - normal human faces except that the skin is red or blue
// and their noses are exceptionally long (print capture p. 284)
inline int dktHumLongNoses()
    { return 1; }

// the humanoid wings - they may or may not have stunted feathered wings on
// their backs, growing between their shoulder blades (print capture p. 284)
inline int dktHumStuntedWings()
    { return 1; }

// the humanoid thrice powers - polymorph self, shout, and phantasmal force
// three times per day (print capture p. 284)
inline int dktHumThricePowers()
    { return 1; }

// the humanoid invisibility - become invisible at will (print capture p. 284)
inline int dktHumInvisibleAtWill()
    { return 1; }

// the humanoid weekly powers - reward or ancient curse once per week (print
// capture p. 284)
inline int dktHumWeeklyPowers()
    { return 1; }

// the humanoid misdirection - use misdirection once per turn (print capture
// p. 284)
inline int dktHumMisdirectionPerTurn()
    { return 1; }

// the humanoid ghost light - use ghost light once per round (print capture p.
// 284)
inline int dktHumGhostLightPerRound()
    { return 1; }

// the humanoid mimicry - they can mimic any human or animal sound perfectly
// (print capture p. 285)
inline int dktHumPerfectMimicry()
    { return 1; }

// the humanoid languages - the language of their own kind, that of the local
// human population, and the languages of animals (print capture p. 285)
inline int dktHumSpeaksThree()
    { return 1; }

// the humanoid dual ability - the spellcasting ability of a shukenja and the
// combat ability of a kensai, both of the same experience level as their hit
// dice (print capture p. 285)
inline int dktHumShukenjaAndKensai()
    { return 1; }

// the humanoid arts - they know one martial arts style with two to five
// special maneuvers in that style (print capture p. 285)
inline int dktHumOneMartialStyle()
    { return 1; }

// the martial arts minimum - the humanoid tengu know one style with two to
// five special maneuvers, the 2 of the 2-5 (print capture p. 285)
inline int dktManeuverCountMin()
    { return 2; }

// the martial arts maximum - the 5 of the 2 to 5 special maneuvers in that
// style (print capture p. 285)
inline int dktManeuverCountMax()
    { return 5; }

// the humanoid fan - they always carry a fan made of brightly colored
// feathers (print capture p. 285)
inline int dktHumFeatherFan()
    { return 1; }

// the folded fan - the fan has magical properties, allowing it to be used as
// a normal katana when folded (print capture p. 285)
inline int dktHumFanAsKatana()
    { return 1; }

// the fanned fan - when fanned it can create a wind equal to a strong gale as
// per wind breath, cast a quickgrowth spell, or cause abnormal growth or
// shrinkage of a facial feature, the nose or ears most common (print capture
// p. 285)
inline int dktHumFanWindAndGrowth()
    { return 1; }

// ---- the tricks and the tutoring ----

// the humanoid temper - while not evil, they are not overly fond of humans
// and often play cruel tricks upon humans (print capture p. 285)
inline int dktHumCruelTricks()
    { return 1; }

// the humanoid liking - they have a liking for shukenja, wu jen, and kensai
// who specialize in the sword (print capture p. 285)
inline int dktHumLikesSwordSpecialists()
    { return 1; }

// the humanoid tutoring - on rare occasions they tutor a sword kensai,
// teaching him the secrets of their skill, which takes 1 to 3 months and
// earns the kensai 1,000 XP (print capture p. 285)
inline int dktHumTutorsKensai()
    { return 1; }

// the tutoring minimum - the sword kensai tutoring takes 1 to 3 months, the 1
// of the 1-3 (print capture p. 285)
inline int dktKensaiTutorMonthsMin()
    { return 1; }

// the tutoring maximum - the 3 of the 1 to 3 months (print capture p. 285)
inline int dktKensaiTutorMonthsMax()
    { return 3; }

// the tutoring reward - such tutoring automatically earns the kensai
// character 1,000 XP (print capture p. 285)
inline int dktKensaiTutorXP()
    { return 1000; }

// the character - all tengu are extremely secretive and capricious (print
// capture p. 285)
inline int dktSecretiveCapricious()
    { return 1; }

// the mystery - little is known about their way of life (print capture p.
// 285)
inline int dktLittleKnown()
    { return 1; }

// the bribe - quite fond of strong drink and can be bribed, appeased, or
// befriended with large offerings of sake (print capture p. 285)
inline int dktFondOfSake()
    { return 1; }

// the music - they also have a taste for music, particularly that of the
// flute and drum (print capture p. 285)
inline int dktTasteForMusic()
    { return 1; }

}   // namespace rules
