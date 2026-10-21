// =========================================================================================
// Adnd1 - rules/oa90hsingsing.h
// OA MONSTERS - THE HSING-SING, printed capture p. 269 - the war-season round
// census 641 -> 642.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 172 closed, 63 open - the hsing-sing box
// flips (census 641 -> 642); NEXT - R720: the Hu Hsien, Lesser Spirit
// (capture pp. 269-272), prefix dkh (verify free at the landing), audit "R720
// OA monsters Hu Hsien audit", include after rules/oa90hsingsing.h
//
namespace rules {

// ---- the stat block ----

// the appearing minimum - the 2 of the 2-20 appearing (print capture p. 269)
inline int dkgAppearMin()
    { return 2; }

// the appearing maximum - the 20 of the 2-20 appearing (print capture p. 269)
inline int dkgAppearMax()
    { return 20; }

// the hsing-sing armor class - the AC 6 of the stat block (print capture p.
// 269)
inline int dkgAC()
    { return 6; }

// the walking rate - the 6 of the move 6/9 (print capture p. 269)
inline int dkgMoveWalk()
    { return 6; }

// the climbing rate - the 9 of the move 6/9 (print capture p. 269)
inline int dkgMoveClimb()
    { return 9; }

// the hit dice - the 2 of the 2+1 (print capture p. 269)
inline int dkgHD()
    { return 2; }

// the hit dice bonus - the +1 of the 2+1 (print capture p. 269)
inline int dkgHDPlus()
    { return 1; }

// the in-lair percentage - the 25% of the stat block (print capture p. 269)
inline int dkgLairPct()
    { return 25; }

// the frequency - the rare of the stat block (print capture p. 269)
inline int dkgFrequencyRare()
    { return 1; }

// the treasure type - the B of the stat block (print capture p. 269)
inline int dkgTreasureTypeB()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 269)
inline int dkgAttackCount()
    { return 1; }

// the damage minimum - the 1 of the 1-6 or by weapon type (print capture p.
// 269)
inline int dkgDmgMin()
    { return 1; }

// the damage maximum - the 6 of the 1-6 or by weapon type (print capture p.
// 269)
inline int dkgDmgMax()
    { return 6; }

// the damage clause - the 1-6 or by weapon type of the stat block (print
// capture p. 269)
inline int dkgDamageByWeaponType()
    { return 1; }

// the special attacks - the nil of the stat block (print capture p. 269)
inline int dkgSpecialAttacksNil()
    { return 1; }

// the special defenses - the nil of the stat block (print capture p. 269)
inline int dkgSpecialDefensesNil()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 269)
inline int dkgMagicResistStandard()
    { return 1; }

// the intelligence - the average of the stat block (print capture p. 269)
inline int dkgIntelligenceAverage()
    { return 1; }

// the alignment - the neutral of the stat block (print capture p. 269)
inline int dkgAlignmentNeutral()
    { return 1; }

// the size class - the M of the stat block (print capture p. 269)
inline int dkgSizeMedium()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 269)
inline int dkgPsionicNil()
    { return 1; }

// the level value - the II of the II/35 + 3/hp (print capture p. 269)
inline int dkgLevelII()
    { return 1; }

// the xp base - the 35 of the II/35 + 3 per hp (print capture p. 269)
inline int dkgXPBase()
    { return 35; }

// the xp per hit point - the 3 of the II/35 + 3/hp (print capture p. 269)
inline int dkgXPPerHP()
    { return 3; }

// ---- the ape-like race ----

// the race - ape-like humanoids, white-furred and with the faces of men
// (print capture p. 269)
inline int dkgApeLikeHumanoids()
    { return 1; }

// the coat - white-furred (print capture p. 269)
inline int dkgWhiteFurred()
    { return 1; }

// the face - with the faces of men (print capture p. 269)
inline int dkgFacesOfMen()
    { return 1; }

// the range - the mountainous sub-tropical forests (print capture p. 269)
inline int dkgMountainousSubTropicalForests()
    { return 1; }

// the tongues - the language of their own race and the trade language (print
// capture p. 269)
inline int dkgSpeaksOwnAndTrade()
    { return 1; }

// ---- the strong-drink trade ----

// the temperament - normally prefer to be left alone (print capture p. 269)
inline int dkgPrefersLeftAlone()
    { return 1; }

// the vice - a weakness for strong drink brings them to human villages to
// trade (print capture p. 269)
inline int dkgWeaknessForStrongDrink()
    { return 1; }

// the outbound trade - the parrots, feathers of rare birds, scented woods,
// and exotic fruits of the forest enclaves (print capture p. 269)
inline int dkgTradesRareTreasures()
    { return 1; }

// the inbound trade - the forged metal, pottery, wine, and rice they take in
// exchange (print capture p. 269)
inline int dkgTakesMetalPotteryWineRice()
    { return 1; }

// the craft clause - practice no crafts themselves, preferring a simple
// existence (print capture p. 269)
inline int dkgPracticesNoCrafts()
    { return 1; }

// the scholars view - held as perfect examples of the principles of harmony
// with nature and non-action (print capture p. 269)
inline int dkgHarmonyWithNature()
    { return 1; }

// ---- the war season ----

// the caveat - not entirely peaceful (print capture p. 269)
inline int dkgNotEntirelyPeaceful()
    { return 1; }

// the war season - the extremely savage and aggressive annual raiding period
// (print capture p. 269)
inline int dkgWarSeason()
    { return 1; }

// the war season cadence - once per year they go on a war-season (print
// capture p. 269)
inline int dkgWarSeasonPerYear()
    { return 1; }

// the muster - organize themselves into raiding bands attacking settlements
// on the edges of their territory (print capture p. 269)
inline int dkgOrganizesRaidingBands()
    { return 1; }

// the impartiality - attacks impartial, pillaging good and evil creatures
// alike (print capture p. 269)
inline int dkgImpartialPillage()
    { return 1; }

// the raid memory - clever enough not to strike the same settlement two years
// in a row (print capture p. 269)
inline int dkgRaidMemoryYears()
    { return 2; }

// the clever rotation - never striking the same settlement two years in a row
// (print capture p. 269)
inline int dkgNeverSameSettlementTwice()
    { return 1; }

// ---- the war gear and the poisons ----

// the first war gear - the spear (print capture p. 269)
inline int dkgCarriesSpears()
    { return 1; }

// the second war gear - the parang (print capture p. 269)
inline int dkgCarriesParangs()
    { return 1; }

// the third war gear - the blowgun (print capture p. 269)
inline int dkgCarriesBlowguns()
    { return 1; }

// the fourth war gear - the wicker shield (print capture p. 269)
inline int dkgCarriesWickerShields()
    { return 1; }

// the poison craft - quite adept at using poisons, the blowgun darts always
// dipped in noxious concoctions (print capture p. 269)
inline int dkgAdeptWithPoisons()
    { return 1; }

// the principal poison count - the two poisons of the blowgun darts (print
// capture p. 269)
inline int dkgPoisonCount()
    { return 2; }

// the first poison - causes death if the saving throw vs. poison is failed
// (print capture p. 269)
inline int dkgPoisonOneDeath()
    { return 1; }

// the first poison failed save - death if the saving throw vs. poison is
// failed (print capture p. 269)
inline int dkgPoisonOneFailedSaveDeath()
    { return 0; }

// the first poison save - the 1d8 points of damage if the save is successful
// (print capture p. 269)
inline int dkgPoisonOneSaveDamage()
    { return 1; }

// the first poison save damage dice - the 1d8 points of damage on a
// successful save (print capture p. 269)
inline int dkgPoisonOneSaveDmgDice()
    { return 1; }

// the first poison save damage sides - the 1d8 points of damage on a
// successful save (print capture p. 269)
inline int dkgPoisonOneSaveDmgSides()
    { return 8; }

// the second poison - a strong muscle relaxant paralyzing the victim on a
// failed save (print capture p. 269)
inline int dkgPoisonTwoMuscleRelaxant()
    { return 1; }

// the second poison paralysis dice - the 2d6 turns of paralysis on a failed
// save (print capture p. 269)
inline int dkgPoisonTwoParalysisTurnsDice()
    { return 2; }

// the second poison paralysis sides - the 2d6 turns of paralysis on a failed
// save (print capture p. 269)
inline int dkgPoisonTwoParalysisTurnsSides()
    { return 6; }

// the second poison save - slowing him for 1d6 turns if the save is
// successful (print capture p. 269)
inline int dkgPoisonTwoSaveSlows()
    { return 1; }

// the second poison slow dice - the 1d6 turns of slowing on a successful save
// (print capture p. 269)
inline int dkgPoisonTwoSlowTurnsDice()
    { return 1; }

// the second poison slow sides - the 1d6 turns of slowing on a successful
// save (print capture p. 269)
inline int dkgPoisonTwoSlowTurnsSides()
    { return 6; }

// ---- the tree lair ----

// the lair - a large tree in the forest (print capture p. 269)
inline int dkgLairInLargeTree()
    { return 1; }

// the quarters - simple sleeping platforms with thatched roofs in the
// branches (print capture p. 269)
inline int dkgSleepingPlatforms()
    { return 1; }

// the lair female share - the females and children equal to 50% of the number
// encountered (print capture p. 269)
inline int dkgLairFemalePct()
    { return 50; }

// the female hit dice - the 1 hit die of the females fighting from the
// branches (print capture p. 269)
inline int dkgFemaleHD()
    { return 1; }

// the lair defense - the females fight from the branches, hurling clubs and
// stones at attackers (print capture p. 269)
inline int dkgFemalesFightFromBranches()
    { return 1; }

// the grudge - despise the tasloi, which sometimes wander up from their
// tropical homes on raids (print capture p. 269)
inline int dkgDespisesTasloi()
    { return 1; }

}   // namespace rules
