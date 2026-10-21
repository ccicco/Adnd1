// =========================================================================================
// Adnd1 - rules/oa102shiro.h
// OA MONSTERS - THE SHIROKINUKATSUKAMI, printed capture pp. 283-284 - the
// Eater of Dreams round
// census 653 -> 654.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 184 closed, 51 open - the
// shirokinukatsukami box flips (census 653 -> 654); NEXT - R732: the Tengu
// (capture p. 284), prefix dkt (verify free at the landing), audit "R732 OA
// monsters Tengu audit", include after rules/oa102shiro.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the very rare of the stat block (print capture p. 283)
inline int dksFrequencyVeryRare()
    { return 1; }

// the appearing - the 1 of the stat block (print capture p. 283)
inline int dksAppear()
    { return 1; }

// the armor class - the AC -2 of the stat block (print capture p. 283)
inline int dksAC()
    { return -2; }

// the move - the 18 of the 18/18 of the stat block, the capture doubling the
// print (print capture p. 283)
inline int dksMove()
    { return 18; }

// the maneuver class - the A of the stat block move line (print capture p.
// 283)
inline int dksMCA()
    { return 1; }

// the hit dice - the 12 of the stat block (print capture p. 283)
inline int dksHD()
    { return 12; }

// the in-lair - the nil of the stat block (print capture p. 283)
inline int dksLairNil()
    { return 1; }

// the treasure type - the nil of the stat block (print capture p. 283)
inline int dksTreasureNil()
    { return 1; }

// the attack count - the 3 of the number of attacks (print capture p. 283)
inline int dksAttackCount()
    { return 3; }

// the special attacks and defenses - the see below of both lines of the stat
// block (print capture p. 283)
inline int dksSpecialsSeeBelow()
    { return 1; }

// the magic resistance - the 50% of the stat block (print capture p. 283)
inline int dksMRPct()
    { return 50; }

// the intelligence - the genius of the stat block (print capture p. 283)
inline int dksIntGenius()
    { return 1; }

// the alignment - the lawful good of the stat block (print capture p. 283)
inline int dksAlignmentLawfulGood()
    { return 1; }

// the size class - the L of the stat block (print capture p. 283)
inline int dksSizeLarge()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 283)
inline int dksPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 283)
inline int dksModesNil()
    { return 1; }

// ---- the xp line ----

// the xp base - the 1,200 of the IX/1,200 + 16 per hp, the capture misreading
// 1X for IX (print capture p. 283)
inline int dksXPBase()
    { return 1200; }

// the xp per hit point - the 16 of the IX/1,200 + 16/hp (print capture p.
// 283)
inline int dksXPPerHP()
    { return 16; }

// ---- the Eater of Dreams ----

// the name - a powerful and kindly spirit also known as the Eater of Dreams
// (print capture p. 283)
inline int dksEaterOfDreams()
    { return 1; }

// the look - the body of a horse, the face of a lion, the trunk and tusks of
// an elephant, the tail of a cow, and the feet of a tiger (print capture p.
// 283)
inline int dksCompositeAppearance()
    { return 1; }

// the resemblance - sometimes mistaken for the baku, to which it bears a
// slight superficial resemblance (print capture p. 283)
inline int dksMistakenForBaku()
    { return 1; }

// the cause - a staunch foe of evil spirits and sendings, often coming in the
// night to protect mortals tormented by these (print capture p. 283)
inline int dksFoeOfEvilSpirits()
    { return 1; }

// the roaming - it has no permanent homeland but roams the night world and
// the Celestial lands searching out evil (print capture p. 283)
inline int dksNoPermanentHomeland()
    { return 1; }

// the rarity of kind - it is quite likely there are no more than four
// shirokinukatsukami in existence (print capture p. 283)
inline int dksMaxInExistence()
    { return 4; }

// ---- the combat ----

// the attacks - it attacks with its front paws and its goring tusks (print
// capture p. 283)
inline int dksAttacksWithPawsAndTusks()
    { return 1; }

// the front paw damage minimum - the 2 of the 2-5 of the first paw (print
// capture p. 283)
inline int dksPawDmgMin()
    { return 2; }

// the front paw damage maximum - the 5 of the 2-5 of the first paw (print
// capture p. 283)
inline int dksPawDmgMax()
    { return 5; }

// the tusk damage minimum - the 3 of the 3-18 of the goring tusks (print
// capture p. 283)
inline int dksTuskDmgMin()
    { return 3; }

// the tusk damage maximum - the 18 of the 3-18 of the goring tusks (print
// capture p. 283)
inline int dksTuskDmgMax()
    { return 18; }

// the rake clause - if both paws score a hit it rakes its victim with its
// back paws for 2d4 points of damage each (print capture p. 283)
inline int dksRakeOnDoublePawHit()
    { return 1; }

// the rake dice - the back paws rake for 2d4 points of damage each (print
// capture p. 283)
inline int dksRakeDice()
    { return 2; }

// the rake die - the d4 of the 2d4 back-paw rake (print capture p. 283)
inline int dksRakeDie()
    { return 4; }

// the rake rolls - normal hit rolls must be made for these two additional
// attacks (print capture p. 283)
inline int dksRakeNeedsHitRolls()
    { return 1; }

// ---- the powers ----

// the first constant power - detect evil, constantly in effect (print capture
// p. 283)
inline int dksConstantDetectEvil()
    { return 1; }

// the second constant power - detect shapechanger, constantly in effect
// (print capture p. 283)
inline int dksConstantDetectShapechanger()
    { return 1; }

// the third constant power - detect charm, constantly in effect (print
// capture p. 283)
inline int dksConstantDetectCharm()
    { return 1; }

// the fourth constant power - detect harmony, constantly in effect (print
// capture p. 283)
inline int dksConstantDetectHarmony()
    { return 1; }

// the fifth constant power - ESP, constantly in effect (print capture p. 283)
inline int dksConstantESP()
    { return 1; }

// the first at-will power - invisibility (print capture p. 283)
inline int dksAtWillInvisibility()
    { return 1; }

// the second at-will power - become astral (print capture p. 283)
inline int dksAtWillBecomeAstral()
    { return 1; }

// the third at-will power - dream sight (print capture p. 283)
inline int dksAtWillDreamSight()
    { return 1; }

// the fourth at-will power - dream vision (print capture p. 283)
inline int dksAtWillDreamVision()
    { return 1; }

// the fifth at-will power - protection from evil, 10-foot radius (print
// capture p. 283)
inline int dksAtWillProtectionFromEvil()
    { return 1; }

// the sixth at-will power - teleport with no error (print capture p. 283)
inline int dksAtWillTeleportNoError()
    { return 1; }

// the seventh at-will power - smoke form, all usable at will once per round
// (print capture p. 283)
inline int dksAtWillSmokeForm()
    { return 1; }

// the first thrice-daily power - dispel evil (print capture p. 283)
inline int dksThriceDispelEvil()
    { return 1; }

// the second thrice-daily power - cloud trapeze (print capture p. 283)
inline int dksThriceCloudTrapeze()
    { return 1; }

// the third thrice-daily power - pacify (print capture p. 283)
inline int dksThricePacify()
    { return 1; }

// the fourth thrice-daily power - exorcise (print capture p. 283)
inline int dksThriceExorcise()
    { return 1; }

// the fifth thrice-daily power - obedience (print capture p. 283)
inline int dksThriceObedience()
    { return 1; }

// the thrice-daily uses - the dispel evil, cloud trapeze, pacify, exorcise,
// and obedience powers, three times per day (print capture p. 283)
inline int dksThricePerDay()
    { return 3; }

// the daily powers - restore spirit and heal, usable once per day (print
// capture p. 283)
inline int dksDailyRestoreAndHeal()
    { return 1; }

// ---- the immunities ----

// the weapon floor - can only be hit by +3 weapons or better (print capture
// p. 283)
inline int dksWeaponPlus()
    { return 3; }

// the regeneration rate - regenerates damage at 2 hit points per round (print
// capture p. 283)
inline int dksRegenPerRound()
    { return 2; }

// the first immunity - immune to air-based attacks (print capture p. 283)
inline int dksImmuneToAirAttacks()
    { return 1; }

// the second immunity - suffers half or no damage from fire-based attacks
// (print capture p. 283)
inline int dksHalfOrNoFireDamage()
    { return 1; }

// the third immunity - immune to poison (print capture p. 283)
inline int dksImmuneToPoison()
    { return 1; }

// ---- the bedside guardian ----

// the arrival - to those who successfully beseech its aid, the creature
// arrives in the night, usually invisible or in smoke form (print capture p.
// 283)
inline int dksArrivesAtNight()
    { return 1; }

// the entrance - slipping into the bedchamber (print capture p. 283)
inline int dksSlipsIntoBedchamber()
    { return 1; }

// the vigil - it takes a position at the head of the bed, guarding over its
// charge (print capture p. 283)
inline int dksGuardsAtHeadOfBed()
    { return 1; }

// the night work - during the night it uses its powers to destroy or drive
// away evil spirits (print capture p. 283)
inline int dksDestroysEvilSpirits()
    { return 1; }

// the departure - leaving with the first light of dawn (print capture p. 284)
inline int dksLeavesAtFirstLight()
    { return 1; }

// the hour - it only appears at night and is never seen during the daytime
// (print capture p. 284)
inline int dksOnlyAppearsAtNight()
    { return 1; }

// the dispatch - it is sometimes sent by the Celestial Emperor to
// specifically protect some deserving or noted person (print capture p. 284)
inline int dksSentByCelestialEmperor()
    { return 1; }

}   // namespace rules
