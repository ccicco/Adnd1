// =========================================================================================
// Adnd1 - rules/mm2o.h
// THE MM2 LETTER O WALK - THE OBLIVIAX, OGRE AQUATIC (MERROW), OLIPHANT,
// OPHIDIAN, OPINICUS, OTTER AND OWL TURNS (the obliviax, the ogre aquatic and
// the oliphant p. 96, the ophidian, the opinicus, the otter and the owl p.
// 97, the owl prose onto p. 98), promoted to the live registry; the O-FLIP
// round, the Letter O gap box flips to closed
// census 731 -> 732.
//
// Round fourteen of the MM2 arc, the THIRD single-letter pass (Curtiss Go
// call on the landed letters LMN walk; the letter O pin-time walk found SEVEN
// entries, all with stat blocks - no doctrine-only family heads; the MM1
// registry already owns the octopus, the ogre, the ogre magi, the oni, the
// ornitholestes, the otyugh and the owlbear prints, so no prior-owned index
// entries ride this round)
//
// The pin headers stay the print-fidelity record; the seven .lua defs ride
// the R791 data_files extension in the MM1 registry schema (the defensive
// coercers load the verbatim print cells, the OStats grid carries the loader
// values)
//
namespace rules {

// ---- the MM2 letter O walk round pins (the R809 census) ----

// The MM2 letter O walk round: the obliviax to owl turns, the THIRD
// single-letter pass (Curtiss Go call on the landed letters LMN walk)
inline int mm2oRound()
    { return 809; }

// The registry census before the R809 promotion (the landed R808 count)
inline int mm2oRegistryBefore()
    { return 699; }

// The registry census after the R809 promotion (7 defs)
inline int mm2oRegistryAfter()
    { return 706; }

// The def count of the R809 walk (the obliviax, merrow, oliphant, ophidian,
// opinicus, otter and owl)
inline int mm2oDefCount()
    { return 7; }

// The pin-time entry census (7 print entries, all with stat blocks, no
// family-head doctrine blocks in the letter O walk)
inline int mm2oEntryCount()
    { return 7; }

// The stat-block heading census of the walk (every letter O entry pins a stat
// block)
inline int mm2oStatBlockHeadings()
    { return 7; }

// The doctrine-only family head census (no letter O family head - no
// GIANT-style doctrine block rides the walk)
inline int mm2oDoctrineHeads()
    { return 0; }

// The letter O heading census (obliviax through owl)
inline int mm2oLetterOHeadings()
    { return 7; }

// The OStats grid row count (one row per def)
inline int mm2oOStatRows()
    { return 7; }

// The MM2 gap report closed box count after the O-flip (the R808 census 19 +
// the Letter O box)
inline int mm2oGapClosed()
    { return 20; }

// The MM2 gap report open box count after the O-flip (the R808 census 18 -
// the Letter O box)
inline int mm2oGapOpen()
    { return 17; }

// The prior-owned letter O index entries (none - the MM1 registry octopus,
// ogre, ogre magi, oni, ornitholestes, otyugh and owlbear prints are MM1
// walks, not MM2 letter O pages)
inline int mm2oPriorOwnedEntries()
    { return 0; }

// ---- the obliviax pins (the R809 MM2 letter O walk) ----

// The obliviax xpValue (II/30 + 1/hp, the flat-hp avgHp 1: 30 + 1x1)
inline int mm2oObliviaxXpValue()
    { return 31; }

// The obliviax experience level (the roman II)
inline int mm2oObliviaxXpLevel()
    { return 2; }

// The memory-steal radius in feet (p. 96)
inline int mm2oObliviaxStealRadiusFeet()
    { return 60; }

// The stolen-memory window in hours (the moss steals the last 24 hours of
// memories)
inline int mm2oObliviaxStealWindowHours()
    { return 24; }

// The failed-eater sickness minimum in turns (3-18 turns)
inline int mm2oObliviaxSickTurnsMin()
    { return 3; }

// The failed-eater sickness maximum in turns
inline int mm2oObliviaxSickTurnsMax()
    { return 18; }

// The rounds to eat the living obliviax and regain the stolen memories
inline int mm2oObliviaxEatRounds()
    { return 1; }

// The mossling defends itself only by casting any stolen spells (p. 96)
inline bool mm2oObliviaxMosslingCastsStolenSpells()
    { return true; }

// A save vs. poison when eating the living obliviax gains all the stolen
// memories including spells
inline bool mm2oObliviaxSaveGainsMemories()
    { return true; }

// ---- the ogre aquatic pins (the R809 MM2 letter O walk) ----

// The merrow xpValue (II/130 + 5/hp, the 4+4 block: 130 + 5x18)
inline int mm2oMerrowXpValue()
    { return 220; }

// The merrow experience level (the roman II)
inline int mm2oMerrowXpLevel()
    { return 2; }

// The 31-36 hp brute variant experience level (the parenthetical IV line, the
// alu-demon range precedent - the grid carries the base)
inline int mm2oMerrowBruteXpLevel()
    { return 4; }

// The 31-36 hp brute variant xp base (the parenthetical IV/250 + 6/hp line)
inline int mm2oMerrowBruteXpBase()
    { return 250; }

// The 31-36 hp brute variant xp per hit point
inline int mm2oMerrowBruteXpPerHp()
    { return 6; }

// The merrow camouflage surprise (4 in 6, attacking from cover)
inline int mm2oMerrowSurpriseOn6()
    { return 4; }

// The swimming-charge spear to-hit bonus (a piercing spear 2-12 at +1 to hit)
inline int mm2oMerrowChargeToHitBonus()
    { return 1; }

// The swimming-charge spear damage maximum (2-12 points)
inline int mm2oMerrowSpearDamageMax()
    { return 12; }

// The merrow water depth minimum (50-250 foot shallows)
inline int mm2oMerrowDepthMinFeet()
    { return 50; }

// The merrow water depth maximum
inline int mm2oMerrowDepthMaxFeet()
    { return 250; }

// The hours a merrow survives out of water
inline int mm2oMerrowHoursOutOfWater()
    { return 2; }

// The lair chief armor class (AC 3, 6+6 hit dice, +2 on damage)
inline int mm2oMerrowChiefAc()
    { return 3; }

// The lair chief hit dice (6+6)
inline int mm2oMerrowChiefHd()
    { return 6; }

// The lair chief hit-dice bonus
inline int mm2oMerrowChiefBonus()
    { return 6; }

// The lair chief damage bonus
inline int mm2oMerrowChiefDamageBonus()
    { return 2; }

// The lair sub-chief count (AC 3, 5+5 hit dice, +1 on damage)
inline int mm2oMerrowSubChiefCount()
    { return 2; }

// The lair sub-chief armor class
inline int mm2oMerrowSubChiefAc()
    { return 3; }

// The lair sub-chief hit dice (5+5)
inline int mm2oMerrowSubChiefHd()
    { return 5; }

// The lair sub-chief hit-dice bonus
inline int mm2oMerrowSubChiefBonus()
    { return 5; }

// The lair sub-chief damage bonus
inline int mm2oMerrowSubChiefDamageBonus()
    { return 1; }

// The female merrow armor class (AC 5, 3+3 hit dice, 1-2/1-2/1-6 damage)
inline int mm2oMerrowFemaleAc()
    { return 5; }

// The female merrow hit dice (3+3)
inline int mm2oMerrowFemaleHd()
    { return 3; }

// The female merrow hit-dice bonus
inline int mm2oMerrowFemaleBonus()
    { return 3; }

// The young merrow armor class (AC 6, 2+2 hit dice, 1-2/1-2/1-4 damage)
inline int mm2oMerrowYoungAc()
    { return 6; }

// The young merrow hit dice (2+2)
inline int mm2oMerrowYoungHd()
    { return 2; }

// The young merrow hit-dice bonus
inline int mm2oMerrowYoungBonus()
    { return 2; }

// The lair shaman count (a normal male or female)
inline int mm2oMerrowShamanCount()
    { return 1; }

// The merrow green coloration hides it (effectively invisible 10-80% of the
// time, depending on terrain)
inline bool mm2oMerrowCamouflageInvisible()
    { return true; }

// Aquatic ogres speak Ogre as well as their own dialect (p. 96)
inline bool mm2oMerrowSpeaksOgre()
    { return true; }

// ---- the oliphant pins (the R809 MM2 letter O walk) ----

// The oliphant xpValue (IV/600 + 12/hp, the 8+4 block: 600 + 12x32)
inline int mm2oOliphantXpValue()
    { return 984; }

// The oliphant experience level (the roman IV)
inline int mm2oOliphantXpLevel()
    { return 4; }

// The trained large-male hit dice (the parenthetical 10+5 variant, kept
// verbatim in the def hitDice text)
inline int mm2oOliphantTrainedHd()
    { return 10; }

// The trained large-male hit-dice bonus
inline int mm2oOliphantTrainedBonus()
    { return 5; }

// The oliphant tusk value minimum (100-400 gp each)
inline int mm2oOliphantTuskValueMin()
    { return 100; }

// The oliphant tusk value maximum
inline int mm2oOliphantTuskValueMax()
    { return 400; }

// The ivory value per pound (about 4 gp)
inline int mm2oOliphantIvoryGpPerPound()
    { return 4; }

// The calf chance per extra oliphant (3 or more encountered: 25% calf)
inline int mm2oOliphantCalfChance()
    { return 25; }

// The half-grown chance per extra oliphant (75%)
inline int mm2oOliphantHalfGrownChance()
    { return 75; }

// The mature male count in a group of 2 or more (all single oliphants are
// male)
inline int mm2oOliphantMatureMalesInGroup()
    { return 1; }

// Oliphants do not fear fire unless it directly threatens them
inline bool mm2oOliphantNoFireFear()
    { return true; }

// All single oliphants are male
inline bool mm2oOliphantSingleAlwaysMale()
    { return true; }

// Properly trained oliphants become engines of destruction, the large males
// growing 10 feet or greater in size (10+5 hit dice)
inline bool mm2oOliphantTrainedEnginesOfDestruction()
    { return true; }

// ---- the ophidian pins (the R809 MM2 letter O walk) ----

// The ophidian xpValue (III/125 + 4/hp, the low-end 3 hit dice read: 125 +
// 4x10)
inline int mm2oOphidianXpValue()
    { return 165; }

// The ophidian experience level (the roman III)
inline int mm2oOphidianXpLevel()
    { return 3; }

// The ophidian bite affliction onset minimum (2-5 days)
inline int mm2oOphidianAfflictionDaysMin()
    { return 2; }

// The ophidian bite affliction onset maximum
inline int mm2oOphidianAfflictionDaysMax()
    { return 5; }

// The ophidian affliction duration minimum (8-16 days)
inline int mm2oOphidianAfflictionDurationMin()
    { return 8; }

// The ophidian affliction duration maximum
inline int mm2oOphidianAfflictionDurationMax()
    { return 16; }

// The ophidian fanged-bite damage maximum (by weapon type and 1-3)
inline int mm2oOphidianBiteDamageMax()
    { return 3; }

// The ophidian fanged bite requires a saving throw vs. poison or the victim
// suffers the lycanthrope-like affliction
inline bool mm2oOphidianPoisonSaveOrAffliction()
    { return true; }

// The affliction process can be prevented by a cure disease spell
inline bool mm2oOphidianCureDiseasePrevents()
    { return true; }

// The affliction turns a human or humanoid into an ophidian and kills any
// other creature
inline bool mm2oOphidianKillsNonhumanoids()
    { return true; }

// Ophidians are usually servants of spirit nagas or similar creatures
inline bool mm2oOphidianServesSpiritNagas()
    { return true; }

// ---- the opinicus pins (the R809 MM2 letter O walk) ----

// The opinicus xpValue (VII/2300 + 12/hp, the 7+7 block: 2300 + 12x31)
inline int mm2oOpinicusXpValue()
    { return 2672; }

// The opinicus experience level (the roman VII)
inline int mm2oOpinicusXpLevel()
    { return 7; }

// The opinicus spell capacity (7th-level clerics, turning undead)
inline int mm2oOpinicusClericLevel()
    { return 7; }

// The holy word casts per day
inline int mm2oOpinicusHolyWordPerDay()
    { return 1; }

// The dimension door casts per day
inline int mm2oOpinicusDimensionDoorPerDay()
    { return 2; }

// The heal casts per day
inline int mm2oOpinicusHealPerDay()
    { return 3; }

// The sun-sparkles gaze damage minimum (2-16 points, the 1/2"x1"x2" cone
// ASCII settle of the print half-glyph)
inline int mm2oOpinicusGazeDamageMin()
    { return 2; }

// The sun-sparkles gaze damage maximum
inline int mm2oOpinicusGazeDamageMax()
    { return 16; }

// The gaze usable interval (once every 10 rounds)
inline int mm2oOpinicusGazeIntervalRounds()
    { return 10; }

// The opinicus surprise roll in its habitat (5 in 6; 3 in 6 elsewhere)
inline int mm2oOpinicusHabitatSurpriseOn6()
    { return 5; }

// The opinicus surprise roll elsewhere
inline int mm2oOpinicusElsewhereSurpriseOn6()
    { return 3; }

// The minor psionic disciplines minimum (3-5)
inline int mm2oOpinicusMinorDisciplinesMin()
    { return 3; }

// The minor psionic disciplines maximum
inline int mm2oOpinicusMinorDisciplinesMax()
    { return 5; }

// The major psionic disciplines minimum (1-2)
inline int mm2oOpinicusMajorDisciplinesMin()
    { return 1; }

// The major psionic disciplines maximum
inline int mm2oOpinicusMajorDisciplinesMax()
    { return 2; }

// The opinicus ground move (21"/30", MC: B - the capture dropped the close
// quote after 30, the transcription confirms)
inline int mm2oOpinicusMoveGround()
    { return 21; }

// The opinicus flying move
inline int mm2oOpinicusMoveFly()
    { return 30; }

// The opinicus psionic ability minimum (205-250)
inline int mm2oOpinicusPsionicMin()
    { return 205; }

// The opinicus psionic ability maximum
inline int mm2oOpinicusPsionicMax()
    { return 250; }

// Due to their keen senses opinicus are never surprised
inline bool mm2oOpinicusNeverSurprised()
    { return true; }

// Opinicus have the spell capacity of 7th-level clerics and can turn undead
inline bool mm2oOpinicusTurnsUndead()
    { return true; }

// The sun-sparkles gaze inflicts one-half damage if a saving throw vs. spells
// is successful
inline bool mm2oOpinicusGazeSaveHalves()
    { return true; }

// The gaze affects undead and creatures of the Lower Outer Planes (Acheron,
// the Nine Hells, Gehenna, Hades, Tartarus, the Abyss and Pandemonium)
inline bool mm2oOpinicusGazeAffectsLowerPlanes()
    { return true; }

// Opinicus can travel both astrally and etherally
inline bool mm2oOpinicusAstralEtherealTravel()
    { return true; }

// ---- the otter pins (the R809 MM2 letter O walk) ----

// The otter xpValue (I/5 + 1/hp, the 1-1 block: 5 + 1x2)
inline int mm2oOtterXpValue()
    { return 7; }

// The otter experience level (the roman I)
inline int mm2oOtterXpLevel()
    { return 1; }

// The sea otter variant hit dice (the parenthetical 1+1, the print
// differences in parentheses above)
inline int mm2oOtterSeaHd()
    { return 1; }

// The sea otter variant hit-dice bonus
inline int mm2oOtterSeaBonus()
    { return 1; }

// The otter damage maximum (1-2; the sea otter parenthetical 1-3)
inline int mm2oOtterDamageMax()
    { return 2; }

// The sea otter damage maximum
inline int mm2oOtterSeaDamageMax()
    { return 3; }

// Otters will attack only if cornered
inline bool mm2oOtterAttacksOnlyIfCornered()
    { return true; }

// ---- the owl pins (the R809 MM2 letter O walk) ----

// The owl xpValue (II/30 + 1/hp: 30 + 1x3)
inline int mm2oOwlXpValue()
    { return 33; }

// The owl experience level (the roman II)
inline int mm2oOwlXpLevel()
    { return 2; }

// The plummeting-attack to-hit bonus (from a 50-foot or greater height)
inline int mm2oOwlPlummetBonus()
    { return 2; }

// The plummet minimum height in feet
inline int mm2oOwlPlummetMinFeet()
    { return 50; }

// The owl surprise roll on prey (5 in 6)
inline int mm2oOwlPreySurpriseOn6()
    { return 5; }

// The owl surprised roll in its daylight roost (3 in 6; never surprised in
// dusk or darkness)
inline int mm2oOwlDaylightRoostSurpriseOn6()
    { return 3; }

// The owl wingspread minimum (4-5 feet, the transcription-settled foot marks)
inline int mm2oOwlWingspreadMinFeet()
    { return 4; }

// The owl wingspread maximum
inline int mm2oOwlWingspreadMaxFeet()
    { return 5; }

// A plummeting owl inflicts twice normal damage, but no beak attack is
// possible
inline bool mm2oOwlPlummetDoubleDamage()
    { return true; }

// Owls have double normal ultravision
inline bool mm2oOwlDoubleUltravision()
    { return true; }

// Owls have quadruple normal hearing
inline bool mm2oOwlQuadrupleHearing()
    { return true; }

// Owls fly in total silence
inline bool mm2oOwlSilentFlight()
    { return true; }

// Owls are never surprised during hours of dusk or darkness
inline bool mm2oOwlNeverSurprisedInDark()
    { return true; }

// The owl 10% in lair chance applies in daylight only (the roosting place)
inline bool mm2oOwlLairDaylightOnly()
    { return true; }

// ---- the OStats grid pins (the R809 MM2 letter O walk) ----

// The armor class cells (the opinicus -2 rides an unquoted number - the R806
// hollyphant -4 precedent; the ophidian "5 or better" reads 5)
inline int mm2oOStatAc(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return -2;
        case 5:
            return 5;
        case 6:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice num cells (the obliviax flat-hp 1-2 read: hitDiceNum 0, the
// bat precedent)
inline int mm2oOStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the otter 1-1 reads bonus -1, the bakemono
// precedent; the oliphant base 8+4, the trained 10+5 the parenthetical
// variant)
inline int mm2oOStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 7;
        case 5:
            return -1;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The avgHp cells (the flat-hp obliviax 1; the floor(3.5 x hd + bonus)
// formula: merrow 18, oliphant 32, ophidian 10, opinicus 31, otter 2, owl 3)
inline int mm2oOStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 18;
        case 2:
            return 32;
        case 3:
            return 10;
        case 4:
            return 31;
        case 5:
            return 2;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the merrow "3 or 1" max read 3, the
// ophidian "1 and 1" sum 2, the obliviax "Nil" floor at 1)
inline int mm2oOStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// The xp base cells (the parenthetical variants - the merrow brute IV/250 +
// 6/hp and the oliphant trained block - ride as consts, not grid cells)
inline int mm2oOStatXp(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 130;
        case 2:
            return 600;
        case 3:
            return 125;
        case 4:
            return 2300;
        case 5:
            return 5;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the obliviax + 1/hp flat-hp read)
inline int mm2oOStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 12;
        case 3:
            return 4;
        case 4:
            return 12;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The in-lair percentage cells (the ophidian "See below" reads 0; the
// obliviax 100%; the owl 10% daylight-only roost)
inline int mm2oOStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 10;
        default:
            return 0;
        }
    }

// The move cells (the ground move reads: the obliviax Nil 0, the merrow 6,
// the ophidian 9, the opinicus 21, the otter 12, the owl 1)
inline int mm2oOStatMove(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 15;
        case 3:
            return 9;
        case 4:
            return 21;
        case 5:
            return 12;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The magic resistance cells (every "Standard" reads 0; the opinicus 35%)
inline int mm2oOStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 35;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
