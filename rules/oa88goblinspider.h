// =========================================================================================
// Adnd1 - rules/oa88goblinspider.h
// OA MONSTERS - THE GOBLIN SPIDER, printed capture p. 267 - the trapdoor
// ambush round
// census 639 -> 640.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 170 closed, 65 open - the goblin spider
// box flips (census 639 -> 640); NEXT - R718: the Hai Nu (capture p. 268),
// prefix dkf (verify free at the landing), audit "R718 OA monsters Hai Nu
// audit", include after rules/oa88goblinspider.h
//
namespace rules {

// ---- the stat block ----

// the appearing minimum - the 1 of the 1-4 appearing (print capture p. 267)
inline int dkeAppearMin()
    { return 1; }

// the appearing maximum - the 4 of the 1-4 appearing (print capture p. 267)
inline int dkeAppearMax()
    { return 4; }

// the goblin spider armor class - the AC 4 of the stat block (print capture
// p. 267)
inline int dkeAC()
    { return 4; }

// the goblin spider move - the 18 of the move 18 (print capture p. 267)
inline int dkeMove()
    { return 18; }

// the hit dice minimum - the 6 of the 6 to 9 (print capture p. 267)
inline int dkeHDMin()
    { return 6; }

// the hit dice maximum - the 9 of the 6 to 9 (print capture p. 267)
inline int dkeHDMax()
    { return 9; }

// the in-lair percentage - the 80% of the stat block (print capture p. 267)
inline int dkeLairPct()
    { return 80; }

// the frequency - the rare of the stat block (print capture p. 267)
inline int dkeFrequencyRare()
    { return 1; }

// the treasure type - the C of the stat block (print capture p. 267)
inline int dkeTreasureTypeC()
    { return 1; }

// the attack count - the 2 of the number of attacks (print capture p. 267)
inline int dkeAttackCount()
    { return 2; }

// the damage minimum - the 1 of the 1-8 per attack (print capture p. 267)
inline int dkeDmgMin()
    { return 1; }

// the damage maximum - the 8 of the 1-8 per attack (print capture p. 267)
inline int dkeDmgMax()
    { return 8; }

// the first special attack - the surprise of the stat block (print capture p.
// 267)
inline int dkeSpecialAttackSurprise()
    { return 1; }

// the second special attack - the grasp of the stat block (print capture p.
// 267)
inline int dkeSpecialAttackGrasp()
    { return 1; }

// the weapon requirement - the +1 or better weapons to hit (print capture p.
// 267)
inline int dkeWeaponPlusRequired()
    { return 1; }

// the magic resistance - the 20% of the stat block (print capture p. 267)
inline int dkeMagicResistPct()
    { return 20; }

// the intelligence - the low of the stat block (print capture p. 267)
inline int dkeIntelligenceLow()
    { return 1; }

// the alignment - the neutral evil of the stat block (print capture p. 267)
inline int dkeAlignmentNeutralEvil()
    { return 1; }

// the size class - the L of the L 8-10 (print capture p. 267)
inline int dkeSizeLarge()
    { return 1; }

// the size minimum - the 8 of the L 8-10 (print capture p. 267)
inline int dkeSizeMinFeet()
    { return 8; }

// the size maximum - the 10 of the L 8-10 (print capture p. 267)
inline int dkeSizeMaxFeet()
    { return 10; }

// the psionic ability - the nil of the stat block (print capture p. 267)
inline int dkePsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 267)
inline int dkePsionicModesNil()
    { return 1; }

// ---- the xp ladder ----

// the 6 HD xp base - the 575 of the VI/575 + 6 per hp (print capture p. 267)
inline int dkeXP6Base()
    { return 575; }

// the 6 HD xp per hit point - the 6 of the VI/575 + 6/hp (print capture p.
// 267)
inline int dkeXP6PerHP()
    { return 6; }

// the 6 HD xp level - the VI of the VI/575 + 6/hp (print capture p. 267)
inline int dkeXP6LevelVI()
    { return 1; }

// the 7 HD xp base - the 900 of the VI/900 + 8 per hp (print capture p. 267)
inline int dkeXP7Base()
    { return 900; }

// the 7 HD xp per hit point - the 8 of the VI/900 + 8/hp (print capture p.
// 267)
inline int dkeXP7PerHP()
    { return 8; }

// the 7 HD xp level - the VI of the VI/900 + 8/hp (print capture p. 267)
inline int dkeXP7LevelVI()
    { return 1; }

// the 8 HD xp base - the 1,350 of the VII/1,350 + 10 per hp (print capture p.
// 267)
inline int dkeXP8Base()
    { return 1350; }

// the 8 HD xp per hit point - the 10 of the VII/1,350 + 10/hp (print capture
// p. 267)
inline int dkeXP8PerHP()
    { return 10; }

// the 8 HD xp level - the VII of the VII/1,350 + 10/hp (print capture p. 267)
inline int dkeXP8LevelVII()
    { return 1; }

// the 9 HD xp base - the 2,200 of the VII/2,200 + 12 per hp (print capture p.
// 267)
inline int dkeXP9Base()
    { return 2200; }

// the 9 HD xp per hit point - the 12 of the VII/2,200 + 12/hp (print capture
// p. 267)
inline int dkeXP9PerHP()
    { return 12; }

// the 9 HD xp level - the VII of the VII/2,200 + 12/hp (print capture p. 267)
inline int dkeXP9LevelVII()
    { return 1; }

// ---- the earth spider ----

// the name - the goblin spider or earth spider (print capture p. 267)
inline int dkeEarthSpiderName()
    { return 1; }

// the look - a huge furry spider of particularly evil cast (print capture p.
// 267)
inline int dkeHugeFurryEvilCast()
    { return 1; }

// the habitat - dwell far from human habitations (print capture p. 267)
inline int dkeDwellFarFromHumans()
    { return 1; }

// the range - the rough wooded mountains common to Kara-Tur (print capture p.
// 267)
inline int dkeWoodedMountains()
    { return 1; }

// the history - once dominated large sections of the land now controlled by
// humans (print capture p. 267)
inline int dkeFormerDominion()
    { return 1; }

// the grudge - view humans and their allies as invaders to their homelands
// (print capture p. 267)
inline int dkeViewHumansAsInvaders()
    { return 1; }

// the malice - take every opportunity to cause harm to human travelers and
// settlers on the edges of their territories (print capture p. 267)
inline int dkeHarmTravelersAndSettlers()
    { return 1; }

// ---- the trapdoor ambush ----

// the web clause - goblin spiders do not spin webs (print capture p. 267)
inline int dkeNoWebs()
    { return 1; }

// the lair - making their lairs in tunnels underground (print capture p. 267)
inline int dkeLairInTunnels()
    { return 1; }

// the door - the entrances carefully concealed by trapdoor openings (print
// capture p. 267)
inline int dkeTrapdoorEntrances()
    { return 1; }

// the trigger - able to detect the vibrations of creatures passing overhead
// (print capture p. 267)
inline int dkeDetectVibrationsOverhead()
    { return 1; }

// the ambush surprise - springing suddenly from the lair, surprising on a 1-4
// (print capture p. 267)
inline int dkeSurpriseDieMax()
    { return 4; }

// the abduction - attempt to grab their victim and drag him back into the
// lair, closing the door behind them (print capture p. 267)
inline int dkeDragIntoLair()
    { return 1; }

// ---- the grasp ----

// the grasp - in any melee round with both attacks hitting, the victim has
// been grasped and held (print capture p. 267)
inline int dkeBothHitsGrasp()
    { return 1; }

// the held victim penalty - held victims fight with a -4 on their chances to
// hit (print capture p. 267)
inline int dkeHeldToHitPenalty()
    { return 4; }

// the escape - a successful bend bars/lift gates roll frees the victim from
// the grip (print capture p. 267)
inline int dkeBendBarsFrees()
    { return 1; }

// the rescue - those not held can help free the victim (print capture p. 267)
inline int dkeHelpersWrenchLoose()
    { return 1; }

// the rescue strength - 20 or more points of Strength to wrench the victim
// loose (print capture p. 267)
inline int dkeFreeStrengthPoints()
    { return 20; }

// the rescue party - at least two characters to wrench the victim loose
// (print capture p. 267)
inline int dkeFreeMinCharacters()
    { return 2; }

// the grip cost - while gripping a victim, it cannot make any other attacks
// (print capture p. 267)
inline int dkeGrippingBlocksAttacks()
    { return 1; }

// ---- the mimicry and the tongues ----

// the mimicry - excellent mimics, able to imitate any voice or animal sound
// they hear (print capture p. 267)
inline int dkeExcellentMimic()
    { return 1; }

// the parrot clause - when imitating languages they do not understand they
// can only repeat words they have heard spoken (print capture p. 267)
inline int dkeUnknownTonguesRepeatOnly()
    { return 1; }

// the mind - not exceptionally intelligent, but clever and devious (print
// capture p. 267)
inline int dkeCleverAndDevious()
    { return 1; }

// the lure - often using their mimicry to lure victims to their doom (print
// capture p. 267)
inline int dkeMimicryLuresVictims()
    { return 1; }

// the first tongue - their own language (print capture p. 267)
inline int dkeSpeaksOwnLanguage()
    { return 1; }

// the second tongue - the language of spiders (print capture p. 267)
inline int dkeSpeaksSpiderLanguage()
    { return 1; }

// the third tongue - the trade language (print capture p. 267)
inline int dkeSpeaksTradeLanguage()
    { return 1; }

// the fourth tongue - the language common to the human inhabitants near their
// lair (print capture p. 267)
inline int dkeSpeaksLocalHuman()
    { return 1; }

// ---- the giant spider guards ----

// the guard chance - the 30% chance of 2d4 giant spiders near any lair (print
// capture p. 268)
inline int dkeGuardsPct()
    { return 30; }

// the guard dice - the 2d4 giant spiders in the immediate vicinity (print
// capture p. 268)
inline int dkeGuardsDice()
    { return 2; }

// the guard dice sides - the 2d4 giant spiders in the immediate vicinity
// (print capture p. 268)
inline int dkeGuardsSides()
    { return 4; }

// the retinue - 2d4 giant spiders in the immediate vicinity serve as guards
// and assist them in any battle (print capture p. 268)
inline int dkeGiantSpiderGuards()
    { return 1; }

}   // namespace rules
