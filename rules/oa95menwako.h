// =========================================================================================
// Adnd1 - rules/oa95menwako.h
// OA MONSTERS - THE MEN WAKO, printed capture pp. 275-276 - the sea pirate
// round
// census 646 -> 647.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 177 closed, 58 open - the men wako box
// flips (census 646 -> 647); NEXT - R725: the Nat, the Lesser Spirit (capture
// pp. 276-278), prefix dkm (verify free at the landing), audit "R725 OA
// monsters Nat audit", include after rules/oa95menwako.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the uncommon of the stat block (print capture p. 275)
inline int dklFrequencyUncommon()
    { return 1; }

// the appearing minimum - the 30 of the 30-180 of the stat block (print
// capture p. 275)
inline int dklAppearMin()
    { return 30; }

// the appearing maximum - the 180 of the 30-180 of the stat block (print
// capture p. 275)
inline int dklAppearMax()
    { return 180; }

// the armor class - the see below of the stat block (print capture p. 275)
inline int dklACSeeBelow()
    { return 1; }

// the move - the 12 of the stat block (print capture p. 275)
inline int dklMove()
    { return 12; }

// the hit dice - the 1 of the 1 (2-7 hit points) of the stat block (print
// capture p. 275)
inline int dklHD()
    { return 1; }

// the hit point minimum - the 2 of the 2-7 of the stat block (print capture
// p. 275)
inline int dklHPMin()
    { return 2; }

// the hit point maximum - the 7 of the 2-7 of the stat block (print capture
// p. 275)
inline int dklHPMax()
    { return 7; }

// the in-lair percent - the 100% of the stat block (print capture p. 275)
inline int dklLairPct()
    { return 100; }

// the treasure type - the A of the stat block (print capture p. 275)
inline int dklTreasureA()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 275)
inline int dklAttackCount()
    { return 1; }

// the damage per attack - the by weapon type of the stat block (print capture
// p. 275)
inline int dklDamageByWeapon()
    { return 1; }

// the special attacks - the leader types of the stat block (print capture p.
// 275)
inline int dklSpecialAttacksLeaderTypes()
    { return 1; }

// the special defenses - the leader types of the stat block (print capture p.
// 275)
inline int dklSpecialDefensesLeaderTypes()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 275)
inline int dklMRStandard()
    { return 1; }

// the intelligence - the average to very of the stat block (print capture p.
// 275)
inline int dklIntelligenceAvgToVery()
    { return 1; }

// the alignment - the lawful evil of the stat block (print capture p. 275)
inline int dklAlignmentLawfulEvil()
    { return 1; }

// the size class - the M of the stat block (print capture p. 276)
inline int dklSizeMedium()
    { return 1; }

// the psionic ability - the leader types of the stat block (print capture p.
// 276)
inline int dklPsionicLeaderTypes()
    { return 1; }

// the attack and defense modes - the leader types of the stat block (print
// capture p. 276)
inline int dklModesLeaderTypes()
    { return 1; }

// ---- the xp line ----

// the xp base - the 14 of the 1/14 + 1 per hp of the xp line (print capture
// p. 276)
inline int dklXPBase()
    { return 14; }

// the xp per hit point - the 1 of the 1/14 + 1/hp of the xp line (print
// capture p. 276)
inline int dklXPPerHP()
    { return 1; }

// ---- the sea raiders ----

// the sea trade - like their brethren the buccaneers and pirates, the wako
// ply the warm seas, boarding ships and raiding coastal towns (print capture
// p. 276)
inline int dklPlyTheWarmSeas()
    { return 1; }

// the reputation - a vicious scourge, greatly feared by all who travel the
// seas of Kara-Tur (print capture p. 276)
inline int dklFearedScourge()
    { return 1; }

// the composition - men of low class who fled their homelands or were hired
// by powerful lords, desperate and dangerous men (print capture p. 276)
inline int dklLowClassOrigins()
    { return 1; }

// the western fear - even the fierce western pirates, from their few
// encounters, regard them with fear (print capture p. 276)
inline int dklWesternPirateFear()
    { return 1; }

// ---- the ferocity ----

// the disregard for death - knowing that horrible tortures and death await
// them should they be captured (print capture p. 276)
inline int dklDisregardForDeath()
    { return 1; }

// the last stand - they fight to the last man no matter how hopeless the
// situation (print capture p. 276)
inline int dklFightToLastMan()
    { return 1; }

// the prisoners - they take no prisoners, except women who are carried to
// their towns as slaves (print capture p. 276)
inline int dklNoPrisonersButWomen()
    { return 1; }

// the ferocity - this attitude renders them utterly ferocious in battle
// (print capture p. 276)
inline int dklUtterlyFerocious()
    { return 1; }

// the hit roll bonus - all wako fight with a +2 on hit rolls (print capture
// p. 276)
inline int dklHitPlus()
    { return 2; }

// the damage bonus - all wako fight with a +1 on damage (print capture p.
// 276)
inline int dklDmgPlus()
    { return 1; }

// ---- the leaders ----

// the bushi leader level - the 5th-level bushi present for every 30 wako
// (print capture p. 276)
inline int dklBushiLevel()
    { return 5; }

// the bushi leader rate - one 5th-level bushi per 30 wako (print capture p.
// 276)
inline int dklBushiPer()
    { return 30; }

// the barbarian leader level - the 7th-level barbarian for every 60 wako
// (print capture p. 276)
inline int dklBarbarianLevel()
    { return 7; }

// the barbarian leader rate - one 7th-level barbarian per 60 wako (print
// capture p. 276)
inline int dklBarbarianPer()
    { return 60; }

// the leader count rule - the bushi and barbarian leaders are in addition to
// the numbers indicated by the dice (print capture p. 276)
inline int dklLeadersInAdditionToDice()
    { return 1; }

// the command - they are always led by a 10th-level samurai (print capture p.
// 276)
inline int dklAlwaysSamuraiLed()
    { return 1; }

// the samurai leader level - always led by a 10th-level samurai (print
// capture p. 276)
inline int dklSamuraiLevel()
    { return 10; }

// the lieutenant level - the barbarian lieutenant of 8th level with the
// samurai (print capture p. 276)
inline int dklLieutenantLevel()
    { return 8; }

// the bushi mates minimum - the 1 of the 1-3 mates of 6th level (print
// capture p. 276)
inline int dklMatesMin()
    { return 1; }

// the bushi mates maximum - the 3 of the 1-3 mates of 6th level (print
// capture p. 276)
inline int dklMatesMax()
    { return 3; }

// the bushi mates level - the 6th level of the bushi mates (print capture p.
// 276)
inline int dklMateLevel()
    { return 6; }

// the wu jen chance - the 5% chance per 30 wako that a wu jen is present
// (print capture p. 276)
inline int dklWuJenChancePct()
    { return 5; }

// the wu jen rate - the 5% chance for every 30 wako present (print capture p.
// 276)
inline int dklWuJenPer()
    { return 30; }

// the wu jen level minimum - the 6 of the 6th to 9th level (print capture p.
// 276)
inline int dklWuJenLevelMin()
    { return 6; }

// the wu jen level maximum - the 9 of the 6th to 9th level (print capture p.
// 276)
inline int dklWuJenLevelMax()
    { return 9; }

// ---- the arms table ----

// the arms table row count - the six arms mixes of the wako force (print
// capture p. 276)
inline int dklWakoCount()
    { return 6; }

// the arms percentage - row by row the hara-ate-gawa and sword, the sword and
// bow, the do-maru and sword, the kote and spear, the kote and do-maru and
// sword and bow, the haramaki and sword and spear and bow; the capture
// misreads 150 and kote 8 spear are the 15 and the kote and spear of the
// print (print capture p. 276)
inline int dklArmsPct(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 10;
        default:
            return 0;
        }
    }

// the leaders armor - all leaders and high level types wear o-yoroi (print
// capture p. 276)
inline int dklLeadersWearOYoroi()
    { return 1; }

// ---- the lair ----

// the lair kind - the lair of the wako is a permanent settlement (print
// capture p. 276)
inline int dklLairPermanentSettlement()
    { return 1; }

// the lair location - possibly on the lands of the sponsoring lord (print
// capture p. 276)
inline int dklLairOnSponsorLands()
    { return 1; }

// the lair defense - it is walled and is well defended and patrolled (print
// capture p. 276)
inline int dklLairWalledPatrolled()
    { return 1; }

}   // namespace rules
