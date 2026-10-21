// =========================================================================================
// Adnd1 - rules/oa81continh.h
// OA MONSTERS - THE CON-TINH, LESSER SPIRIT, printed capture pp. 258-259 -
// the maiden spirit round
// census 632 -> 633.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 163 closed, 72 open - the con-tinh box
// flips (census 632 -> 633); NEXT - R711: the Doc Cu'o'c, Greater Spirit
// (capture p. 259), prefix djy (verify free at the landing), audit "R711 OA
// monsters Doc Cu'o'c audit", include after rules/oa81continh.h
//
namespace rules {

// ---- the stat block ----

// the con-tinh appearance minimum - the 1 of the 1-2 of the stat block (print
// capture p. 258)
inline int djxConTinhNoAppearingMin()
    { return 1; }

// the con-tinh appearance maximum - the 2 of the 1-2 of the stat block (print
// capture p. 258)
inline int djxConTinhNoAppearingMax()
    { return 2; }

// the con-tinh armor class - the AC 7 of the stat block (print capture p.
// 258)
inline int djxConTinhAC()
    { return 7; }

// the con-tinh movement rate - the move 12 of the stat block (print capture
// p. 258)
inline int djxConTinhMove()
    { return 12; }

// the con-tinh hit dice - the HD 6 of the stat block (print capture p. 258)
inline int djxConTinhHD()
    { return 6; }

// the con-tinh attacks per round - the 1 of the stat block (print capture p.
// 258)
inline int djxConTinhAttacks()
    { return 1; }

// the con-tinh damage minimum - the 1 of the 1-6 of the stat block (print
// capture p. 258)
inline int djxConTinhDmgMin()
    { return 1; }

// the con-tinh damage maximum - the 6 of the 1-6 of the stat block (print
// capture p. 258)
inline int djxConTinhDmgMax()
    { return 6; }

// the con-tinh magic resistance - the 20% of the stat block (print capture p.
// 258)
inline int djxConTinhMRPct()
    { return 20; }

// the con-tinh base experience - the 600 of the VI/600 (print capture p. 258)
inline int djxConTinhXPBase()
    { return 600; }

// the con-tinh experience per hit point - the 6/hp of the stat block (print
// capture p. 258)
inline int djxConTinhXPPerHP()
    { return 6; }

// the con-tinh frequency - the rare of the stat block (print capture p. 258)
inline int djxConTinhRare()
    { return 1; }

// the con-tinh in-lair percentage - the 100% of the stat block (print capture
// p. 258)
inline int djxConTinhLair100()
    { return 1; }

// the con-tinh treasure - the type I of the stat block (print capture p. 258)
inline int djxConTinhTreasureI()
    { return 1; }

// the con-tinh special attack - the laugh of the stat block (print capture p.
// 258)
inline int djxConTinhLaughAttack()
    { return 1; }

// the con-tinh intelligence - the standard of the stat block (print capture
// p. 258)
inline int djxConTinhIntStandard()
    { return 1; }

// the con-tinh alignment - the chaotic evil of the stat block (print capture
// p. 258)
inline int djxConTinhChaoticEvil()
    { return 1; }

// the con-tinh size - the M of the stat block (print capture p. 258)
inline int djxConTinhSizeM()
    { return 1; }

// the con-tinh psionics - the Nil ability and the Nil attack/defense modes of
// the stat block (print capture p. 258)
inline int djxConTinhPsionicNil()
    { return 1; }

// ---- the nature ----

// the con-tinh lifeforce tree - always found within 100 feet of the old tree
// (print capture p. 258)
inline int djxConTinhTreeRadiusFt()
    { return 100; }

// the con-tinh nature - an evil spirit creature (print capture p. 258)
inline int djxConTinhEvilSpirit()
    { return 1; }

// the con-tinh folklore - spirits of maidens who died before their time
// (print capture p. 258)
inline int djxConTinhMaidenSpirits()
    { return 1; }

// the con-tinh appearance - much like that of a young girl (print capture p.
// 258)
inline int djxConTinhYoungGirlAppearance()
    { return 1; }

// the con-tinh schedule - only appear at night (print capture p. 258)
inline int djxConTinhNightOnly()
    { return 1; }

// the con-tinh anchor - always found within 100 feet of an old tree, which is
// their life force (print capture p. 258)
inline int djxConTinhTreeLifeforce()
    { return 1; }

// the con-tinh lifeforce rule - should the tree be damaged, the con-tinh
// suffers an appropriate amount of damage (print capture p. 258)
inline int djxConTinhTreeDamageHurts()
    { return 1; }

// the con-tinh lifeforce limit - if the tree is destroyed, the con-tinh is
// destroyed (print capture p. 258)
inline int djxConTinhTreeDestroyedDestroys()
    { return 1; }

// the con-tinh reputation - greatly feared by commoners, the rumored areas
// shunned, especially at night (print capture p. 258)
inline int djxConTinhFearedAndShunned()
    { return 1; }

// the con-tinh daytime habit - hide within the branches of their tree (print
// capture p. 258)
inline int djxConTinhHidesInTreeByDay()
    { return 1; }

// the con-tinh predation - at night they come out hoping to catch travelers
// and foolish locals (print capture p. 258)
inline int djxConTinhNightAmbusher()
    { return 1; }

// ---- the special attacks ----

// the con-tinh laugh - those within 20 feet when it laughs must save (print
// capture p. 258)
inline int djxConTinhLaughRadiusFt()
    { return 20; }

// the con-tinh laugh - the weird laugh it can do three times a night (print
// capture p. 258)
inline int djxConTinhLaughsPerNight()
    { return 3; }

// the con-tinh insanity - the Intelligence and Wisdom reduced to 2 until a
// heal spell is cast (print capture p. 258)
inline int djxConTinhInsanityFloor()
    { return 2; }

// the con-tinh defense - can only be hit by weapons of +2 or greater (print
// capture p. 258)
inline int djxConTinhWeaponPlusRequired()
    { return 2; }

// the con-tinh combat - not particularly fierce, but with two special attacks
// used to great effect (print capture p. 258)
inline int djxConTinhNotFierceButSpecial()
    { return 1; }

// the con-tinh laugh - those within 20 feet must make a successful saving
// throw vs. death or be stricken with insanity (print capture p. 258)
inline int djxConTinhLaughSaveVsDeath()
    { return 1; }

// the con-tinh insanity cure - the reduction lasts until a heal spell is cast
// (print capture p. 258)
inline int djxConTinhHealRestoresInsanity()
    { return 1; }

// the con-tinh possession - the power to possess, as per the spell, once per
// night (print capture p. 258)
inline int djxConTinhPossessionOncePerNight()
    { return 1; }

// the con-tinh possession - can be maintained even during daytime (print
// capture p. 258)
inline int djxConTinhPossessionDaytimeToo()
    { return 1; }

// the con-tinh bane - a successful exorcism spell destroys the creature
// (print capture p. 259)
inline int djxConTinhExorcismDestroys()
    { return 1; }

// the con-tinh curse - any person who destroys the tree must make a saving
// throw vs. spell or suffer an ancient curse (print capture p. 259)
inline int djxConTinhTreeSlayerCursed()
    { return 1; }

// the con-tinh curse - the power is automatic and can occur day or night
// (print capture p. 259)
inline int djxConTinhCurseDayOrNight()
    { return 1; }

}   // namespace rules
