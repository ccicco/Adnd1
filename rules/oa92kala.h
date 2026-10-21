// =========================================================================================
// Adnd1 - rules/oa92kala.h
// OA MONSTERS - THE KALA, printed capture pp. 272-273 - the paired columns
// round
// census 643 -> 644.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 174 closed, 61 open - the kala box flips
// (census 643 -> 644); NEXT - R722: the Kappa (capture p. 273), prefix dkj
// (verify free at the landing), audit "R722 OA monsters Kappa audit", include
// after rules/oa92kala.h
//
namespace rules {

// ---- the stat table ----

// the kala type count - the Cave and the Earth of the two-column stat block
// (print capture p. 272)
inline int dkiKalaCount()
    { return 2; }

// the appearing minimum - the 1 of both columns (print capture p. 272)
inline int dkiKalaAppearMin(int b)
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

// the appearing maximum - the 10 of the Cave, the 12 of the Earth (print
// capture p. 272)
inline int dkiKalaAppearMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        default:
            return 0;
        }
    }

// the armor class - the -1 of the Cave, the 2 of the Earth (print capture p.
// 272)
inline int dkiKalaAC(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 2;
        default:
            return 0;
        }
    }

// the move - the 9 of the Cave, the 12 of the Earth (print capture p. 272)
inline int dkiKalaMove(int b)
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

// the hit dice - the 8 of the Cave, the 6 of the Earth (print capture p. 272)
inline int dkiKalaHD(int b)
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

// the in-lair percentage - the 30% of the Cave, the 25% of the Earth (print
// capture p. 272)
inline int dkiKalaLairPct(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 25;
        default:
            return 0;
        }
    }

// the damage minimum - the 1 of both columns (print capture p. 272)
inline int dkiKalaDmgMin(int b)
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

// the damage maximum - the 8 of the Cave, the 6 of the Earth (print capture
// p. 272)
inline int dkiKalaDmgMax(int b)
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

// ---- the shared stat lines ----

// the frequency - the rare of both columns (print capture p. 272)
inline int dkiFrequencyRare()
    { return 1; }

// the attack count - the 2 of the number of attacks (print capture p. 272)
inline int dkiAttackCount()
    { return 2; }

// the special defenses - the nil of both columns (print capture p. 272)
inline int dkiSpecialDefensesNil()
    { return 1; }

// the magic resistance - the standard of both columns (print capture p. 272)
inline int dkiMagicResistStandard()
    { return 1; }

// the intelligence - the low of both columns (print capture p. 273)
inline int dkiIntelligenceLow()
    { return 1; }

// the alignment - the neutral of both columns (print capture p. 273)
inline int dkiAlignmentNeutral()
    { return 1; }

// the size class - the M of both columns (print capture p. 273)
inline int dkiSizeMedium()
    { return 1; }

// the psionic ability - the nil and the nil attack/defense modes of both
// columns (print capture p. 273)
inline int dkiPsionicNil()
    { return 1; }

// the 6 HD xp base - the 825 of the VI/825 + 10 per hp (print capture p. 273)
inline int dkiXP6Base()
    { return 825; }

// the 6 HD xp per hit point - the 10 of the VI/825 + 10/hp (print capture p.
// 273)
inline int dkiXP6PerHP()
    { return 10; }

// the 8 HD xp base - the 1,275 of the VII/1,275 + 6 per hp (print capture p.
// 273)
inline int dkiXP8Base()
    { return 1275; }

// the 8 HD xp per hit point - the 6 of the VII/1,275 + 6/hp (print capture p.
// 273)
inline int dkiXP8PerHP()
    { return 6; }

// ---- the spirit race ----

// the race - an ancient and primitive spirit race of humanoids (print capture
// p. 273)
inline int dkiAncientPrimitiveSpiritRace()
    { return 1; }

// the range - found in the cold wastelands (print capture p. 273)
inline int dkiColdWastelands()
    { return 1; }

// the look - appear similar to normal humans (print capture p. 273)
inline int dkiSimilarToHumans()
    { return 1; }

// the first tell - the pointed heads (print capture p. 273)
inline int dkiPointedHeads()
    { return 1; }

// the second tell - the large feet that aid moving through the snow (print
// capture p. 273)
inline int dkiLargeFeet()
    { return 1; }

// the hardiness - inured to the cold, never wearing more than a loincloth
// (print capture p. 273)
inline int dkiInuredToCold()
    { return 1; }

// the temper - quite ferocious (print capture p. 273)
inline int dkiFerocious()
    { return 1; }

// the diet - cannibalistic, raiding camps and villages for their food (print
// capture p. 273)
inline int dkiCannibalistic()
    { return 1; }

// ---- the hunters ----

// the first craft - expert trackers and hunters (print capture p. 273)
inline int dkiExpertTrackers()
    { return 1; }

// the second craft - hunters of the cold wastelands (print capture p. 273)
inline int dkiExpertHunters()
    { return 1; }

// the tracking base - the base 80% chance of following a trail (print capture
// p. 273)
inline int dkiTrackBasePct()
    { return 80; }

// the first arms - the clawed hands (print capture p. 273)
inline int dkiClawedHands()
    { return 1; }

// the second arms - the primitive stone axes, one held in each hand (print
// capture p. 273)
inline int dkiStoneAxes()
    { return 1; }

// ---- the cave kala pain ladder ----

// the cave kala bite - injects a terrible poison causing wracking pains
// unless the save vs. poison is made (print capture p. 273)
inline int dkiCaveBitePoison()
    { return 1; }

// the pain onset - the pains begin slowly and build in intensity (print
// capture p. 273)
inline int dkiPainBuildsSlowly()
    { return 1; }

// the pain ladder length - the five rounds of the cave kala poison (print
// capture p. 273)
inline int dkiPainRounds()
    { return 5; }

// the round one pain - the discomfort of a strong headache (print capture p.
// 273)
inline int dkiPainRound1Headache()
    { return 1; }

// the round two penalty - the -1 to hit and damage with the +1 on saving
// throws (print capture p. 273)
inline int dkiPainRound2ToHitPenalty()
    { return 1; }

// the round three penalty - the -2/+2 spread (print capture p. 273)
inline int dkiPainRound3Penalty()
    { return 2; }

// the round four penalty - the excruciating -4/+4 spread (print capture p.
// 273)
inline int dkiPainRound4Penalty()
    { return 4; }

// the round five pain - the victim is incapacitated, unable to take any
// action (print capture p. 273)
inline int dkiPainRound5Incapacitated()
    { return 1; }

// the pain duration minimum - the 1 of the 1-3 turns (print capture p. 273)
inline int dkiPainTurnsMin()
    { return 1; }

// the pain duration maximum - the 3 of the 1-3 turns (print capture p. 273)
inline int dkiPainTurnsMax()
    { return 3; }

// ---- the earth kala disease breath ----

// the earth kala breath - causes disease in all who fail the saving throw vs.
// death (print capture p. 273)
inline int dkiEarthBreathDisease()
    { return 1; }

// the disease breath range - the five feet of the earth kala breath (print
// capture p. 273)
inline int dkiDiseaseRangeFeet()
    { return 5; }

// the disease breath width - the two feet of the earth kala breath (print
// capture p. 273)
inline int dkiDiseaseWidthFeet()
    { return 2; }

// the disease damage dice - the 1d6 hit points lost per day (print capture p.
// 273)
inline int dkiDiseaseDmgDice()
    { return 1; }

// the disease damage sides - the 1d6 hit points lost per day (print capture
// p. 273)
inline int dkiDiseaseDmgSides()
    { return 6; }

// the disease clause - the victim cannot heal or benefit from magical healing
// (print capture p. 273)
inline int dkiDiseaseBlocksHealing()
    { return 1; }

// ---- the lairs and tongues ----

// the cave kala lair - hidden caves deep in the forest (print capture p. 273)
inline int dkiCaveLairsInCaves()
    { return 1; }

// the earth kala life - nomadic, moving their camps according to the season
// and the hunting (print capture p. 273)
inline int dkiEarthNomadic()
    { return 1; }

// the first tongue - the language of the northern tribes (print capture p.
// 273)
inline int dkiSpeaksNorthernTribes()
    { return 1; }

// the second tongue - the language of their own kind (print capture p. 273)
inline int dkiSpeaksOwnKind()
    { return 1; }

}   // namespace rules
