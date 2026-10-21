// =========================================================================================
// Adnd1 - rules/oa85gargantua.h
// OA MONSTERS - THE GARGANTUA, printed capture pp. 263-265 - the kaiju round
// census 636 -> 637.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 167 closed, 68 open - the gargantua box
// flips (census 636 -> 637); NEXT - R715: the Generals of the Animal Kings,
// Greater Spirits (capture p. 265), prefix dkc (verify free at the landing),
// audit "R715 OA monsters Animal Generals audit", include after
// rules/oa85gargantua.h
//
namespace rules {

// ---- the shared gargantua doctrine ----

// the gargantua type count - the humanoid, the insectoid, the reptilian of
// the three-column stat block (print capture p. 263)
inline int dkbGargantuaTypeCount()
    { return 3; }

// the gargantua regeneration - all possess the ability to regenerate 4 hit
// points per round (print capture p. 264)
inline int dkbGargantuaRegenPerRound()
    { return 4; }

// the gargantua nature - a class of truly monstrous creatures in proportion
// and ferocity, the most frequent forms gigantic humanoids, insects, and
// reptiles (print capture p. 264)
inline int dkbGargantuaMonstrousClass()
    { return 1; }

// the gargantua origin - aberrations of natural processes, throwbacks, or
// crazed magical experiments, unknown; all that is known is they exist and
// occasionally appear to ravage the land (print capture p. 264)
inline int dkbGargantuaOriginUnknown()
    { return 1; }

// the gargantua temperament - some degree of intelligence but the actions
// most often those of mindless brutes bent on destruction for destruction
// sake (print capture p. 264)
inline int dkbGargantuaMindlessBrutes()
    { return 1; }

// the gargantua detection - the ground trembles when they walk, so they
// cannot surprise creatures at all (print capture p. 264)
inline int dkbGargantuaGroundTrembles()
    { return 1; }

// the gargantua sightline - their height makes them easily spotted at a
// distance (print capture p. 264)
inline int dkbGargantuaEasilySpotted()
    { return 1; }

// the gargantua noise - the habit of emitting squealing roars as they move
// and fight makes it almost impossible to ignore their presence (print
// capture p. 264)
inline int dkbGargantuaSquealingRoars()
    { return 1; }

// the gargantua rarity - fortunately rare and seldom bother humans; when they
// appear the arrival is often treated as a national or at least regional
// emergency with every resource mobilized (print capture p. 265)
inline int dkbGargantuaNationalEmergency()
    { return 1; }

// ---- the humanoid gargantua ----

// the humanoid gargantua appearance minimum - the 1 of the 1-2 (print capture
// p. 263)
inline int dkbHumanoidNoAppMin()
    { return 1; }

// the humanoid gargantua appearance maximum - the 2 of the 1-2 (print capture
// p. 263)
inline int dkbHumanoidNoAppMax()
    { return 2; }

// the humanoid gargantua armor class - the AC 4 of the stat block (print
// capture p. 263)
inline int dkbHumanoidAC()
    { return 4; }

// the humanoid gargantua movement rate - the move 21' of the stat block
// (print capture p. 263)
inline int dkbHumanoidMove()
    { return 21; }

// the humanoid gargantua hit dice - the HD 35 of the stat block (print
// capture p. 264)
inline int dkbHumanoidHD()
    { return 35; }

// the humanoid gargantua attacks per round - the 2 fists of the stat block
// (print capture p. 264)
inline int dkbHumanoidAttacks()
    { return 2; }

// the humanoid gargantua fist damage minimum - the 4 of the 4-40/4-40, the
// 4d10 each (print capture p. 264)
inline int dkbHumanoidFistDmgMin()
    { return 4; }

// the humanoid gargantua fist damage maximum - the 40 of the 4-40/4-40 (print
// capture p. 264)
inline int dkbHumanoidFistDmgMax()
    { return 40; }

// the humanoid gargantua trample minimum - the 10 of the 10-100 points of
// damage (print capture p. 264)
inline int dkbHumanoidTrampleDmgMin()
    { return 10; }

// the humanoid gargantua trample maximum - the 100 of the 10-100 (print
// capture p. 264)
inline int dkbHumanoidTrampleDmgMax()
    { return 100; }

// the humanoid gargantua length minimum - the 80' of the 80'-100' size L
// entry (print capture p. 264)
inline int dkbHumanoidSizeMinFt()
    { return 80; }

// the humanoid gargantua length maximum - the 100' of the 80'-100' size L
// entry (print capture p. 264)
inline int dkbHumanoidSizeMaxFt()
    { return 100; }

// the humanoid gargantua height minimum - the 60 of the 60 to 100 feet tall
// (print capture p. 264)
inline int dkbHumanoidHeightMinFt()
    { return 60; }

// the humanoid gargantua height maximum - the 100 of the 60 to 100 feet tall
// (print capture p. 264)
inline int dkbHumanoidHeightMaxFt()
    { return 100; }

// the humanoid gargantua comprehension - able to comprehend the meanings of
// other languages 25% of the time (print capture p. 264)
inline int dkbHumanoidComprehendPct()
    { return 25; }

// the humanoid gargantua base experience - the 16,600 of the 16,600 + 35/hp
// column (print capture p. 264)
inline int dkbHumanoidXPBase()
    { return 16600; }

// the humanoid gargantua experience per hit point - the + 35/hp (print
// capture p. 264)
inline int dkbHumanoidXPPerHP()
    { return 35; }

// the humanoid gargantua frequency - the very rare of the stat block (print
// capture p. 263)
inline int dkbHumanoidVeryRare()
    { return 1; }

// the humanoid gargantua in-lair percentage - the Nil of the stat block
// (print capture p. 264)
inline int dkbHumanoidLairNil()
    { return 1; }

// the humanoid gargantua treasure - the Nil of the stat block (print capture
// p. 264)
inline int dkbHumanoidTreasureNil()
    { return 1; }

// the humanoid gargantua special attack - the trample of the stat block
// (print capture p. 264)
inline int dkbHumanoidTrample()
    { return 1; }

// the humanoid gargantua psionics - the Nil of the stat block (print capture
// p. 264)
inline int dkbHumanoidPsionicNil()
    { return 1; }

// the humanoid gargantua rank - the least intelligent of their kind (print
// capture p. 264)
inline int dkbHumanoidLeastIntelligent()
    { return 1; }

// the humanoid gargantua hide - sometimes covered with fur (print capture p.
// 264)
inline int dkbHumanoidSometimesFurred()
    { return 1; }

// the humanoid gargantua speech - no language of their own (print capture p.
// 264)
inline int dkbHumanoidNoOwnLanguage()
    { return 1; }

// the humanoid gargantua empathy - comprehend other languages 25% of the time
// because of a strong empathy for human emotions (print capture p. 264)
inline int dkbHumanoidHumanEmpathy()
    { return 1; }

// the humanoid gargantua habitat - jagged remote mountains or tiny islands
// far out at sea (print capture p. 264)
inline int dkbHumanoidMountainIslandLair()
    { return 1; }

// ---- the insectoid gargantua ----

// the insectoid gargantua appearance minimum - the 1 of the 1-3 (print
// capture p. 263)
inline int dkbInsectoidNoAppMin()
    { return 1; }

// the insectoid gargantua appearance maximum - the 3 of the 1-3 (print
// capture p. 263)
inline int dkbInsectoidNoAppMax()
    { return 3; }

// the insectoid gargantua armor class - the AC 6 of the stat block (print
// capture p. 263)
inline int dkbInsectoidAC()
    { return 6; }

// the insectoid gargantua ground rate - the 6' of the move 6'/36' (MC:E)
// (print capture p. 263)
inline int dkbInsectoidMoveGround()
    { return 6; }

// the insectoid gargantua fly rate - the 36' of the move 6'/36' maneuver
// class E (print capture p. 263)
inline int dkbInsectoidMoveFly()
    { return 36; }

// the insectoid gargantua attacks per round - the 1 of the stat block (print
// capture p. 264)
inline int dkbInsectoidAttacks()
    { return 1; }

// the insectoid gargantua damage minimum - the 3 of the 3-30 (print capture
// p. 264)
inline int dkbInsectoidDmgMin()
    { return 3; }

// the insectoid gargantua damage maximum - the 30 of the 3-30 (print capture
// p. 264)
inline int dkbInsectoidDmgMax()
    { return 30; }

// the insectoid gargantua size - the L (60') of the stat block (print capture
// p. 264)
inline int dkbInsectoidSizeFt()
    { return 60; }

// the insectoid gargantua larva - starting life with 20 hit dice (the
// stat-block 200 garble settled by the larva read) (print capture p. 264)
inline int dkbInsectoidLarvaHD()
    { return 20; }

// the insectoid gargantua growth - increasing 1 hit die per week (print
// capture p. 264)
inline int dkbInsectoidGrowthPerWeek()
    { return 1; }

// the insectoid gargantua pupation - upon attaining 25 hit dice the larva
// spins a cocoon (print capture p. 264)
inline int dkbInsectoidPupationHD()
    { return 25; }

// the insectoid gargantua pupae duration - the 2 of the 2d4 weeks (print
// capture p. 264)
inline int dkbInsectoidPupaeWeeksDice()
    { return 2; }

// the insectoid gargantua pupae duration sides - the 4 of the 2d4 weeks
// (print capture p. 264)
inline int dkbInsectoidPupaeWeeksSides()
    { return 4; }

// the insectoid gargantua moth - emerging as a gigantic moth with 30 hit dice
// (print capture p. 264)
inline int dkbInsectoidMothHD()
    { return 30; }

// the insectoid larva silk - the strand of cocoon silk shot to a range of 60
// feet (print capture p. 264)
inline int dkbInsectoidSilkRangeFt()
    { return 60; }

// the insectoid larva silk rule - a strand severed with 20 points of damage
// from an edged weapon (print capture p. 264)
inline int dkbInsectoidSilkSeverDmg()
    { return 20; }

// the insectoid larva silk rule - or by monsters of 10 hit dice or more
// (print capture p. 264)
inline int dkbInsectoidSilkSeverHDMonster()
    { return 10; }

// the insectoid moth windstorm - the storm 6' wide (the extent djvu garble
// -24' not pinned, unreadable even by eye-read) (print capture p. 264)
inline int dkbInsectoidWindstormWidthFt()
    { return 6; }

// the insectoid moth windstorm - the save vs. death at a -4 on the die (print
// capture p. 264)
inline int dkbInsectoidWindstormSavePenalty()
    { return 4; }

// the insectoid moth windstorm - the blown back 10' of the 10-40 feet (print
// capture p. 264)
inline int dkbInsectoidBlowbackMinFt()
    { return 10; }

// the insectoid moth windstorm - the blown back 40' of the 10-40 feet (print
// capture p. 264)
inline int dkbInsectoidBlowbackMaxFt()
    { return 40; }

// the insectoid moth windstorm - 1d6 points of damage for every 1' blown
// (print capture p. 264)
inline int dkbInsectoidBlowbackDmgPerFt()
    { return 6; }

// the insectoid gargantua 20 HD experience - the 11,100 + 30/hp tier (print
// capture p. 264)
inline int dkbInsectoidXP20HDBase()
    { return 11100; }

// the insectoid gargantua 20 HD experience per hit point - the + 30/hp (print
// capture p. 264)
inline int dkbInsectoidXP20HDPerHP()
    { return 30; }

// the insectoid gargantua 21 + HD experience - the 13,600 + 35/hp tier (print
// capture p. 264)
inline int dkbInsectoidXP21HDBase()
    { return 13600; }

// the insectoid gargantua 21 + HD experience per hit point - the + 35/hp
// (print capture p. 264)
inline int dkbInsectoidXP21HDPerHP()
    { return 35; }

// the insectoid gargantua frequency - the rare of the stat block (print
// capture p. 263)
inline int dkbInsectoidRare()
    { return 1; }

// the insectoid gargantua in-lair percentage - the Nil of the stat block
// (print capture p. 264)
inline int dkbInsectoidLairNil()
    { return 1; }

// the insectoid gargantua treasure - the Nil of the stat block (print capture
// p. 264)
inline int dkbInsectoidTreasureNil()
    { return 1; }

// the insectoid gargantua special defense - the regeneration of the stat
// block (print capture p. 264)
inline int dkbInsectoidSpecialDefenseRegeneration()
    { return 1; }

// the insectoid gargantua magic resistance - the standard of the stat block
// (print capture p. 264)
inline int dkbInsectoidMRStandard()
    { return 1; }

// the insectoid gargantua intelligence - the Low of the stat block (the
// garble Lo settled by the Low read) (print capture p. 264)
inline int dkbInsectoidIntLow()
    { return 1; }

// the insectoid gargantua alignment - the chaotic neutral of the stat block
// (print capture p. 264)
inline int dkbInsectoidChaoticNeutral()
    { return 1; }

// the insectoid gargantua psionics - the Nil of the stat block (print capture
// p. 264)
inline int dkbInsectoidPsionicNil()
    { return 1; }

// the insectoid gargantua life cycle - the gigantic egg hatching into a
// gigantic larva, the pupae stage, and the final moth form (print capture p.
// 264)
inline int dkbInsectoidGrowthStages()
    { return 1; }

// the insectoid larva silk - exceptionally strong and sticky, adhering to
// whatever it hits, entangling and immobilizing creatures (print capture p.
// 264)
inline int dkbInsectoidSilkEntangles()
    { return 1; }

// the insectoid larva silk rule - a strand severed with a successful bend
// bars/lift gates roll (print capture p. 264)
inline int dkbInsectoidSilkSeverBendBars()
    { return 1; }

// the insectoid moth limitation - lost the ability to spin silk (print
// capture p. 264)
inline int dkbInsectoidMothLosesSilk()
    { return 1; }

// the insectoid moth windstorm - created by flapping its wings, all within
// the path must be solidly anchored or save (print capture p. 264)
inline int dkbInsectoidWindstormByFlapping()
    { return 1; }

// the insectoid gargantua habitat - warm mountainous regions (print capture
// p. 264)
inline int dkbInsectoidWarmMountains()
    { return 1; }

// ---- the reptilian gargantua ----

// the reptilian gargantua appearance minimum - the 1 of the 1-2 (print
// capture p. 263)
inline int dkbReptilianNoAppMin()
    { return 1; }

// the reptilian gargantua appearance maximum - the 2 of the 1-2 (print
// capture p. 263)
inline int dkbReptilianNoAppMax()
    { return 2; }

// the reptilian gargantua armor class - the AC 2 of the stat block (print
// capture p. 263)
inline int dkbReptilianAC()
    { return 2; }

// the reptilian gargantua walking rate - the 18' of the move 18'/12' (print
// capture p. 263)
inline int dkbReptilianMoveWalk()
    { return 18; }

// the reptilian gargantua swimming rate - the 12' of the move 18'/12' (print
// capture p. 263)
inline int dkbReptilianMoveSwim()
    { return 12; }

// the reptilian gargantua hit dice - the HD 50 of the stat block (print
// capture p. 264)
inline int dkbReptilianHD()
    { return 50; }

// the reptilian gargantua attacks per round - the 3 of the stat block (print
// capture p. 264)
inline int dkbReptilianAttacks()
    { return 3; }

// the reptilian gargantua claw damage minimum - the 3 of the 3-30/3-30/6-60
// (print capture p. 264)
inline int dkbReptilianClawDmgMin()
    { return 3; }

// the reptilian gargantua claw damage maximum - the 30 of the 3-30/3-30/6-60
// (print capture p. 264)
inline int dkbReptilianClawDmgMax()
    { return 30; }

// the reptilian gargantua bite damage minimum - the 6 of the 3-30/3-30/6-60
// (print capture p. 264)
inline int dkbReptilianBiteDmgMin()
    { return 6; }

// the reptilian gargantua bite damage maximum - the 60 of the 3-30/3-30/6-60
// (print capture p. 264)
inline int dkbReptilianBiteDmgMax()
    { return 60; }

// the reptilian gargantua length minimum - the 100' of the 100'-200' size L
// entry (print capture p. 264)
inline int dkbReptilianSizeMinFt()
    { return 100; }

// the reptilian gargantua length maximum - the 200' of the 100'-200' size L
// entry (print capture p. 264)
inline int dkbReptilianSizeMaxFt()
    { return 200; }

// the reptilian gargantua trample - if moving upright, trample for 10d10
// points of damage (print capture p. 265)
inline int dkbReptilianTrampleDice()
    { return 10; }

// the reptilian gargantua trample sides - the d10 of the 10d10 (print capture
// p. 265)
inline int dkbReptilianTrampleSides()
    { return 10; }

// the reptilian gargantua tail - sweeps the ground behind them, 90 feet to
// either side (print capture p. 265)
inline int dkbReptilianTailSweepFt()
    { return 90; }

// the reptilian gargantua tail damage - the 8d10 points of damage on a failed
// save vs. death (print capture p. 265)
inline int dkbReptilianTailDmgDice()
    { return 8; }

// the reptilian gargantua tail damage sides - the d10 of the 8d10 (print
// capture p. 265)
inline int dkbReptilianTailDmgSides()
    { return 10; }

// the reptilian gargantua experience - the Level X (all) 22,600 + 35/hp
// (print capture p. 264)
inline int dkbReptilianXPBase()
    { return 22600; }

// the reptilian gargantua experience per hit point - the + 35/hp (print
// capture p. 264)
inline int dkbReptilianXPPerHP()
    { return 35; }

// the reptilian gargantua frequency - the rare of the stat block (print
// capture p. 263)
inline int dkbReptilianRare()
    { return 1; }

// the reptilian gargantua in-lair percentage - the Nil of the stat block
// (print capture p. 264)
inline int dkbReptilianLairNil()
    { return 1; }

// the reptilian gargantua treasure - the Nil of the stat block (print capture
// p. 264)
inline int dkbReptilianTreasureNil()
    { return 1; }

// the reptilian gargantua psionics - the Nil of the stat block (print capture
// p. 264)
inline int dkbReptilianPsionicNil()
    { return 1; }

// the reptilian gargantua form - gigantic often bipedal reptiles, truly
// magnificent, towering above all other creatures (print capture p. 264)
inline int dkbReptilianGiganticBipedal()
    { return 1; }

// the reptilian gargantua speech - unable to speak (print capture p. 264)
inline int dkbReptilianUnableToSpeak()
    { return 1; }

// the reptilian gargantua empathy - a simple empathy able to sense the
// emotions and desires of other creatures (print capture p. 264)
inline int dkbReptilianSimpleEmpathy()
    { return 1; }

// the reptilian gargantua attack form - the front claws and the bite (print
// capture p. 265)
inline int dkbReptilianClawsAndBite()
    { return 1; }

// the reptilian gargantua tail - any creature in the area must make a
// successful saving throw vs. death or suffer the 8d10 (print capture p. 265)
inline int dkbReptilianTailSweepSaveVsDeath()
    { return 1; }

// the reptilian gargantua habitat - tropical islands far out at sea (print
// capture p. 265)
inline int dkbReptilianTropicalIslands()
    { return 1; }

// the reptilian gargantua mobility - they can swim, so isolation does not cut
// them off from the rest of the world (print capture p. 265)
inline int dkbReptilianSwims()
    { return 1; }

}   // namespace rules
