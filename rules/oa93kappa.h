// =========================================================================================
// Adnd1 - rules/oa93kappa.h
// OA MONSTERS - THE KAPPA, printed capture p. 273 - the paired columns round
// census 644 -> 645.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 175 closed, 60 open - the kappa box flips
// (census 644 -> 645); NEXT - R723: the Kuei, Lesser Spirit (capture p. 274),
// prefix dkk (verify free at the landing), audit "R723 OA monsters Kuei
// audit", include after rules/oa93kappa.h
//
namespace rules {

// ---- the stat table ----

// the kappa type count - the Common and the Vampiric of the two-column stat
// block (print capture p. 273)
inline int dkjKappaCount()
    { return 2; }

// the appearing minimum - the 1 of both columns (print capture p. 273)
inline int dkjKappaAppearMin(int b)
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

// the appearing maximum - the 6 of the Common, the 2 of the Vampiric (print
// capture p. 273)
inline int dkjKappaAppearMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 2;
        default:
            return 0;
        }
    }

// the front armor class - the 3 of the Common, the 0 of the Vampiric (print
// capture p. 273)
inline int dkjKappaFrontAC(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        default:
            return 0;
        }
    }

// the move rate - the 6 of the Common, the 9 of the Vampiric, both swimming
// 18 (print capture p. 273)
inline int dkjKappaMove(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 9;
        default:
            return 0;
        }
    }

// the hit dice - the 4 of the Common, the 7 of the Vampiric (print capture p.
// 273)
inline int dkjKappaHD(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 7;
        default:
            return 0;
        }
    }

// the in-lair percentage - the 70% of the Common, the 80% of the Vampiric
// (print capture p. 273)
inline int dkjKappaLairPct(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 80;
        default:
            return 0;
        }
    }

// the attack count - the 2 of the Common, the 3 of the Vampiric (print
// capture p. 273)
inline int dkjKappaAttacks(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        default:
            return 0;
        }
    }

// the claw damage minimum - the 5 of both columns (print capture p. 273)
inline int dkjKappaClawMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        default:
            return 0;
        }
    }

// the claw damage maximum - the 10 of both columns (print capture p. 273)
inline int dkjKappaClawMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        default:
            return 0;
        }
    }

// ---- the shared stat lines ----

// the common frequency - the rare of the first column (print capture p. 273)
inline int dkjFrequencyRare()
    { return 1; }

// the vampiric frequency - the very rare of the second column (print capture
// p. 273)
inline int dkjVampFrequencyVeryRare()
    { return 1; }

// the treasure type - the D of both columns (print capture p. 273)
inline int dkjTreasureTypeD()
    { return 1; }

// the common special attacks - the nil of the first column (print capture p.
// 273)
inline int dkjSpecialAttackNil()
    { return 1; }

// the vampiric special attack - the strength drain of the second column
// (print capture p. 273)
inline int dkjVampStrengthDrain()
    { return 1; }

// the special defenses - the regeneration of both columns (print capture p.
// 273)
inline int dkjSpecialDefenseRegeneration()
    { return 1; }

// the magic resistance - the standard of both columns (print capture p. 273)
inline int dkjMagicResistStandard()
    { return 1; }

// the common intelligence - the low to average of the first column (print
// capture p. 273)
inline int dkjIntelligenceLowToAverage()
    { return 1; }

// the vampiric intelligence - the average of the second column (print capture
// p. 273)
inline int dkjVampIntelligenceAverage()
    { return 1; }

// the alignment - the chaotic evil of both columns (print capture p. 273)
inline int dkjAlignmentChaoticEvil()
    { return 1; }

// the size class - the S of both columns (print capture p. 273)
inline int dkjSizeSmall()
    { return 1; }

// the psionic ability - the nil and the nil attack/defense modes of both
// columns (print capture p. 273)
inline int dkjPsionicNil()
    { return 1; }

// the common xp level - the III of the III/135 + 4/hp (print capture p. 273)
inline int dkjCommonLevelIII()
    { return 1; }

// the common xp base - the 135 of the III/135 + 4 per hp (print capture p.
// 273)
inline int dkjCommonXPBase()
    { return 135; }

// the common xp per hit point - the 4 of the III/135 + 4/hp (print capture p.
// 273)
inline int dkjCommonXPPerHP()
    { return 4; }

// the vampiric xp level flag - the VI of the VI/1,000 + 10/hp (print capture
// p. 273)
inline int dkjVampLevelVI()
    { return 1; }

// the vampiric xp base - the 1,000 of the VI/1,000 + 10 per hp (print capture
// p. 273)
inline int dkjVampXPBase()
    { return 1000; }

// the vampiric xp per hit point - the 10 of the VI/1,000 + 10/hp (print
// capture p. 273)
inline int dkjVampXPPerHP()
    { return 10; }

// ---- the water sprite ----

// the race - amphibious humanoid creatures of fresh water (print capture p.
// 274)
inline int dkjAmphibiousHumanoids()
    { return 1; }

// the waters - the lakes, ponds, rivers, and streams of fresh water (print
// capture p. 274)
inline int dkjFreshWaterHabitat()
    { return 1; }

// the height - the approximately two feet of the little creatures (print
// capture p. 274)
inline int dkjHeightFeet()
    { return 2; }

// the build - the general proportions of a young boy (print capture p. 274)
inline int dkjBoyProportions()
    { return 1; }

// the shell - the thick tortoise-like shell on the back, the AC -2 for back
// attacks (print capture p. 274)
inline int dkjTortoiseShell()
    { return 1; }

// the bowl - the concave top of the head, a small bowl filled with water
// (print capture p. 274)
inline int dkjConcaveBowlHead()
    { return 1; }

// the vampiric tell - eyes which glow with a red fire (print capture p. 274)
inline int dkjVampRedGlowingEyes()
    { return 1; }

// ---- the strength and the arts ----

// the kappa strength - the 18/00 of the incredible Strength (print capture p.
// 274)
inline int dkjStrength()
    { return 18; }

// the strength to-hit - the +3 on the chance to hit in combat (print capture
// p. 274)
inline int dkjToHitBonus()
    { return 3; }

// the style - masters of one style of martial arts (print capture p. 274)
inline int dkjMartialArtsMasters()
    { return 1; }

// the maneuver dice - the 1d6 special maneuvers of their martial arts style
// (print capture p. 274)
inline int dkjManeuverDice()
    { return 1; }

// the maneuver sides - the 1d6 special maneuvers of their martial arts style
// (print capture p. 274)
inline int dkjManeuverSides()
    { return 6; }

// the common arms - fight with their clawed hands, rending the opponent
// (print capture p. 274)
inline int dkjClawedHands()
    { return 1; }

// the vampiric arms - also attack with their bite (print capture p. 274)
inline int dkjVampBiteAttack()
    { return 1; }

// ---- the vampiric grip ----

// the bite grip - once a successful bite is scored, the vampiric kappa retain
// the grip (print capture p. 274)
inline int dkjVampRetainsGrip()
    { return 1; }

// the grip clause - draining one point of Strength each round but causing no
// further damage (print capture p. 274)
inline int dkjGripNoFurtherDamage()
    { return 1; }

// the drain rate - one point of Strength each round of the retained bite grip
// (print capture p. 274)
inline int dkjDrainPerRound()
    { return 1; }

// the first release - the grip can only be broken by slaying the vampiric
// kappa (print capture p. 274)
inline int dkjGripBrokenBySlaying()
    { return 1; }

// the second release - or emptying the bowl in the top of its head (print
// capture p. 274)
inline int dkjGripBrokenByEmptyBowl()
    { return 1; }

// the third release - or a successful bend bars/lift gates roll (print
// capture p. 274)
inline int dkjGripBrokenByBendBars()
    { return 1; }

// the death clause - if the Strength reaches 0, the victim is slain (print
// capture p. 274)
inline int dkjSlainAtZeroStrength()
    { return 1; }

// the bite disease - the debilitating disease from the bite (print capture p.
// 274)
inline int dkjBiteDisease()
    { return 1; }

// the disease chance - the 50% chance of contracting a debilitating disease
// from the bite (print capture p. 274)
inline int dkjDiseaseChancePct()
    { return 50; }

// the disease drain minimum - the 1 of the 1-3 Strength points per day (print
// capture p. 274)
inline int dkjDiseaseMinPerDay()
    { return 1; }

// the disease drain maximum - the 3 of the 1-3 Strength points per day (print
// capture p. 274)
inline int dkjDiseaseMaxPerDay()
    { return 3; }

// the disease course - the loss of 1-3 Strength points per day until cured or
// the victim dies (print capture p. 274)
inline int dkjDiseaseDrainsUntilCured()
    { return 1; }

// the disease recovery - if cured, Strength points recovered at 2-5 per day
// of rest (print capture p. 274)
inline int dkjDiseaseRecoveredByRest()
    { return 1; }

// the recovery minimum - the 2 of the 2-5 Strength points per day of rest
// (print capture p. 274)
inline int dkjRecoveryMinPerDay()
    { return 2; }

// the recovery maximum - the 5 of the 2-5 Strength points per day of rest
// (print capture p. 274)
inline int dkjRecoveryMaxPerDay()
    { return 5; }

// ---- the bowl and the water ----

// the power source - a water-dwelling race that draws its power from water
// (print capture p. 274)
inline int dkjPowerFromWater()
    { return 1; }

// the bowl water - filled from the particular stream or lake that is the lair
// (print capture p. 274)
inline int dkjBowlFilledFromLair()
    { return 1; }

// the filled clause - so long as the bowl remains filled, the kappa possesses
// its powers (print capture p. 274)
inline int dkjPowersWhileFilled()
    { return 1; }

// the emptied clause - should the bowl ever be emptied, the kappa loses its
// powers (print capture p. 274)
inline int dkjLosesPowersWhenEmptied()
    { return 1; }

// the emptied strength - its Strength becomes normal (print capture p. 274)
inline int dkjEmptyStrengthNormal()
    { return 1; }

// the emptied regeneration - loses the ability to regenerate damage (print
// capture p. 274)
inline int dkjEmptyLosesRegeneration()
    { return 1; }

// the emptied drain - loses hit points at 2 per round until the water is
// restored (print capture p. 274)
inline int dkjEmptyLosesHPPerRound()
    { return 1; }

// the empty-bowl loss - the kappa loses hit points at the rate of 2 per round
// until the water is restored (print capture p. 274)
inline int dkjDehydratePerRound()
    { return 2; }

// the bow - can infrequently be tricked into bowing, thus spilling the water
// (print capture p. 274)
inline int dkjTrickedByBowing()
    { return 1; }

// the wariness - most kappa are more clever than the bow trick (print capture
// p. 274)
inline int dkjCleverAboutBowTrick()
    { return 1; }

// the first spill - the water can be spilled if the opponent makes a
// successful bend bars/lift gates roll (print capture p. 274)
inline int dkjSpillByBendBars()
    { return 1; }

// the second spill - or a martial arts throw special maneuver (print capture
// p. 274)
inline int dkjSpillByThrowManeuver()
    { return 1; }

// the guard - the natural agility and grace are sufficient to prevent
// spillage (print capture p. 274)
inline int dkjAgilityPreventsSpillage()
    { return 1; }

// the immunity - immune to water-based spells (print capture p. 274)
inline int dkjImmuneToWaterSpells()
    { return 1; }

// ---- the lair and the cravings ----

// the lair - under rocks and bridges in bodies of fresh water (print capture
// p. 274)
inline int dkjLairsUnderRocksAndBridges()
    { return 1; }

// the ambush - normally appear to waylay lone travelers, dragging them
// underwater to their doom (print capture p. 274)
inline int dkjWaylaysLoneTravelers()
    { return 1; }

// the first craving - particularly fond of horseflesh, often grabbing and
// dragging horses underwater (print capture p. 274)
inline int dkjFondOfHorseflesh()
    { return 1; }

// the second craving - fond of melons and cucumbers, appeased by offerings
// (print capture p. 274)
inline int dkjFondOfMelonsAndCucumbers()
    { return 1; }

// the custom - throwing a few fruits into the water before crossing a bridge
// or straying near the bank (print capture p. 274)
inline int dkjOfferingsBeforeCrossing()
    { return 1; }

// ---- the regeneration ----

// the regeneration - the 1 hit point per round of all kappa (print capture p.
// 274)
inline int dkjRegenPerRound()
    { return 1; }

}   // namespace rules
