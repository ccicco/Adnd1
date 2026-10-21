// =========================================================================================
// Adnd1 - rules/oa86generals.h
// OA MONSTERS - THE GENERALS OF THE ANIMAL KINGS, printed capture pp. 265-266
// - the three generals round
// census 637 -> 638.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 168 closed, 67 open - the animal generals
// box flips (census 637 -> 638); NEXT - R716: the Goblin Rat (capture p.
// 266), prefix dkd (verify free at the landing), audit "R716 OA monsters
// Goblin Rat audit", include after rules/oa86generals.h
//
namespace rules {

// ---- the shared general doctrine ----

// the general type count - the Tiger, the Ox, the Monkey of the three-column
// stat block (print capture p. 265)
inline int dkcGeneralTypeCount()
    { return 3; }

// the general defense - can only be hit by +5 weapons or better (print
// capture p. 265)
inline int dkcGeneralWeaponPlusRequired()
    { return 5; }

// the general spell casting - the ability of a 29th-level wu jen, knowing all
// spells of that class (print capture p. 265)
inline int dkcGeneralWuJenLevel()
    { return 29; }

// the general cloud trapeze - once per day, powerful enough to transport
// themselves and 1,000 other creatures (print capture p. 265)
inline int dkcGeneralCloudTrapezeCreatures()
    { return 1000; }

// the general regeneration - able to regenerate 5 hit points per round (print
// capture p. 265)
inline int dkcGeneralRegenPerRound()
    { return 5; }

// the general at-will battery - the invisible, the ethereal, the astral, the
// shapechange, the teleport no error, usable once per round at will (print
// capture p. 265)
inline int dkcGeneralAtWillCount()
    { return 5; }

// the general always-on battery - the ESP, the comprehend languages, the
// tongues, the detect magic, the know history, in effect at all times (print
// capture p. 265)
inline int dkcGeneralAlwaysOnCount()
    { return 5; }

// the general form - giant-sized humanoid animals of the same type as their
// name, dressed in armor, robes, and weapons befitting a lord of the Animal
// Kings court (print capture p. 265)
inline int dkcGeneralGiantHumanoidAnimals()
    { return 1; }

// the general powers - become invisible, ethereal, or astral at will,
// shapechange, and teleport no error (print capture p. 265)
inline int dkcGeneralAtWillPowers()
    { return 1; }

// the general senses - ESP, comprehend languages, tongues, detect magic, and
// know history at all times (print capture p. 265)
inline int dkcGeneralAlwaysOnPowers()
    { return 1; }

// the general succession - should one be slain, the Animal Kings instantly
// appoint a new general from the ranks of animals, the creature gaining all
// the powers of that type (print capture p. 266)
inline int dkcGeneralReplacedWhenSlain()
    { return 1; }

// the general scarcity - the Animal Kings only appoint a few generals of each
// type at any given time (print capture p. 266)
inline int dkcGeneralFewAtATime()
    { return 1; }

// ---- the shared stat block ----

// the general in-lair percentage - the Nil of all three columns (print
// capture p. 265)
inline int dkcGeneralLairNil()
    { return 1; }

// the general treasure - the Nil of all three columns (print capture p. 265)
inline int dkcGeneralTreasureNil()
    { return 1; }

// the general intelligence - the genius of the stat block (print capture p.
// 265)
inline int dkcGeneralIntGenius()
    { return 1; }

// the general alignment - the lawful neutral of the stat block (print capture
// p. 265)
inline int dkcGeneralLawfulNeutral()
    { return 1; }

// the general size - the L of the stat block (print capture p. 265)
inline int dkcGeneralSizeL()
    { return 1; }

// the general psionics - the Nil attack/defense modes of all three columns
// (print capture p. 265)
inline int dkcGeneralPsionicNil()
    { return 1; }

// ---- the general tiger ----

// the general tiger armor class - the AC -6 of the stat block (print capture
// p. 265)
inline int dkcTigerAC()
    { return -6; }

// the general tiger fly rate - the 36' of the move 36'/24' (print capture p.
// 265)
inline int dkcTigerMoveFly()
    { return 36; }

// the general tiger ground rate - the 24' of the move 36'/24' maneuver class
// A (print capture p. 265)
inline int dkcTigerMoveGround()
    { return 24; }

// the general tiger hit dice - the HD 30 of the stat block (print capture p.
// 265)
inline int dkcTigerHD()
    { return 30; }

// the general tiger attacks per round - the 3 of the stat block (print
// capture p. 265)
inline int dkcTigerAttacks()
    { return 3; }

// the general tiger claw damage minimum - the 1 of the 1-10/1-10/2-20 (print
// capture p. 265)
inline int dkcTigerClawDmgMin()
    { return 1; }

// the general tiger claw damage maximum - the 10 of the 1-10/1-10/2-20 (print
// capture p. 265)
inline int dkcTigerClawDmgMax()
    { return 10; }

// the general tiger bite damage minimum - the 2 of the 1-10/1-10/2-20 (print
// capture p. 265)
inline int dkcTigerBiteDmgMin()
    { return 2; }

// the general tiger bite damage maximum - the 20 of the 1-10/1-10/2-20 (print
// capture p. 265)
inline int dkcTigerBiteDmgMax()
    { return 20; }

// the general tiger magic resistance - the 80% of the stat block (print
// capture p. 265)
inline int dkcTigerMRPct()
    { return 80; }

// the general tiger mien - all creatures within 24' with less than 3 hit dice
// or levels must save vs. spell or flee in panic (print capture p. 265)
inline int dkcTigerPanicRadiusFt()
    { return 24; }

// the general tiger panic rule - the less than 3 hit dice or levels threshold
// (print capture p. 265)
inline int dkcTigerPanicHDLimit()
    { return 3; }

// the general tiger panic duration - the 1d4 turns of fleeing (print capture
// p. 265)
inline int dkcTigerPanicTurnsDice()
    { return 1; }

// the general tiger panic duration sides - the d4 of the 1d4 turns (print
// capture p. 265)
inline int dkcTigerPanicTurnsSides()
    { return 4; }

// the general tiger vorpal sword +5 - the 2d6 + 12 points of damage on a
// successful hit (print capture p. 265)
inline int dkcTigerSwordDmgDice()
    { return 2; }

// the general tiger vorpal sword sides - the d6 of the 2d6 + 12 (print
// capture p. 265)
inline int dkcTigerSwordDmgSides()
    { return 6; }

// the general tiger vorpal sword bonus - the + 12 of the 2d6 + 12 (print
// capture p. 265)
inline int dkcTigerSwordDmgBonus()
    { return 12; }

// the general tiger accuracy - the +3 on his chance to hit, +8 when using the
// sword (print capture p. 265)
inline int dkcTigerToHitBonus()
    { return 3; }

// the general tiger sword accuracy - the +8 when using the sword (print
// capture p. 265)
inline int dkcTigerSwordToHitBonus()
    { return 8; }

// the general tiger host - accompanied by a host of 100 tigers, absolutely
// loyal and instinctively understanding his every command (print capture p.
// 265)
inline int dkcTigerHostCount()
    { return 100; }

// the general tiger experience - the 27,400 of the X/27,400 (print capture p.
// 265)
inline int dkcTigerXPBase()
    { return 27400; }

// the general tiger duty - most frequently dispatched to suppress rebellions
// or carry out orders of punishment (print capture p. 265)
inline int dkcTigerSuppressesRebellions()
    { return 1; }

// the general tiger attack options - 3 attacks per round with the weapon or
// the clawed hands and bite (print capture p. 265)
inline int dkcTigerSwordOrClaws()
    { return 1; }

// the general tiger temperament - extremely proud, hot-tempered, and
// blood-thirsty (print capture p. 265)
inline int dkcTigerProudHotBlooded()
    { return 1; }

// ---- the general ox ----

// the general ox armor class - the AC -8 of the stat block (print capture p.
// 265)
inline int dkcOxAC()
    { return -8; }

// the general ox walking rate - the 18' of the move 18'/21' (print capture p.
// 265)
inline int dkcOxMoveWalk()
    { return 18; }

// the general ox charge rate - the 21' of the move 18'/21' (print capture p.
// 265)
inline int dkcOxMoveCharge()
    { return 21; }

// the general ox hit dice - the HD 36 of the stat block (print capture p.
// 265)
inline int dkcOxHD()
    { return 36; }

// the general ox attacks per round - the 2 of the stat block (print capture
// p. 265)
inline int dkcOxAttacks()
    { return 2; }

// the general ox gore damage minimum - the 2 of the 2-12/2-20 (print capture
// p. 265)
inline int dkcOxGoreDmgMin()
    { return 2; }

// the general ox gore damage maximum - the 12 of the 2-12/2-20 (print capture
// p. 265)
inline int dkcOxGoreDmgMax()
    { return 12; }

// the general ox bite damage minimum - the 2 of the 2-20 of the second attack
// (print capture p. 265)
inline int dkcOxBiteDmgMin()
    { return 2; }

// the general ox bite damage maximum - the 20 of the 2-20 (print capture p.
// 265)
inline int dkcOxBiteDmgMax()
    { return 20; }

// the general ox mace +5 - the 1d10 + 9 points of damage on a successful hit
// (print capture p. 265)
inline int dkcOxMaceDmgDice()
    { return 1; }

// the general ox mace sides - the d10 of the 1d10 + 9 (print capture p. 265)
inline int dkcOxMaceDmgSides()
    { return 10; }

// the general ox mace bonus - the + 9 of the 1d10 + 9 (print capture p. 265)
inline int dkcOxMaceDmgBonus()
    { return 9; }

// the general ox accuracy - the +4 on his chance to hit, +9 with the mace
// (print capture p. 266)
inline int dkcOxToHitBonus()
    { return 4; }

// the general ox mace accuracy - the +9 with the mace (print capture p. 266)
inline int dkcOxMaceToHitBonus()
    { return 9; }

// the general ox host - the 10 of the 10d4 gozu-oni accompanying him (print
// capture p. 266)
inline int dkcOxHostDice()
    { return 10; }

// the general ox host sides - the d4 of the 10d4 gozu-oni (print capture p.
// 266)
inline int dkcOxHostSides()
    { return 4; }

// the general ox experience - the 24,400 of the X/24,400 (print capture p.
// 265)
inline int dkcOxXPBase()
    { return 24400; }

// the general ox experience per hit point - the + 35/hp (print capture p.
// 265)
inline int dkcOxXPPerHP()
    { return 35; }

// the general ox duty - sent when General Tiger needs assistance or to aid a
// particularly righteous human emperor in a great endeavor (print capture p.
// 265)
inline int dkcOxAidAndAssistDuty()
    { return 1; }

// the general ox power - once per turn, crash his hooves to the ground with
// all the effects of an earthquake spell (print capture p. 265)
inline int dkcOxEarthquakeHooves()
    { return 1; }

// the general ox mace +5 - able to fire a meteor swarm once per day (print
// capture p. 265)
inline int dkcOxMeteorSwarmMace()
    { return 1; }

// the general ox attack options - attack with the mace and gore with his
// horns in the same round (print capture p. 266)
inline int dkcOxMaceAndGoreSameRound()
    { return 1; }

// the general ox temperament - extremely intelligent but not a quick thinker,
// sometimes outwitted by clever wit; extremely patient and stubborn, never
// breaking off combat unless ordered by his lord (print capture p. 266)
inline int dkcOxSlowThinker()
    { return 1; }

// the general ox host - the gozu-oni absolutely loyal to him (print capture
// p. 266)
inline int dkcOxLoyalGozuOniHost()
    { return 1; }

// ---- the general monkey ----

// the general monkey armor class - the AC -4 of the stat block (print capture
// p. 265)
inline int dkcMonkeyAC()
    { return -4; }

// the general monkey fly rate - the 48' of the move 48'/36' (print capture p.
// 265)
inline int dkcMonkeyMoveFly()
    { return 48; }

// the general monkey ground rate - the 36' of the move 48'/36' (print capture
// p. 265)
inline int dkcMonkeyMoveGround()
    { return 36; }

// the general monkey hit dice - the HD 24 of the stat block (print capture p.
// 265)
inline int dkcMonkeyHD()
    { return 24; }

// the general monkey attacks per round - the 2 of the stat block (print
// capture p. 265)
inline int dkcMonkeyAttacks()
    { return 2; }

// the general monkey damage minimum - the 2 of the 2-12/2-12 (print capture
// p. 265)
inline int dkcMonkeyDmgMin()
    { return 2; }

// the general monkey damage maximum - the 12 of the 2-12/2-12 (print capture
// p. 265)
inline int dkcMonkeyDmgMax()
    { return 12; }

// the general monkey abilities - all the abilities of a 20th-level ninja
// (print capture p. 266)
inline int dkcMonkeyNinjaLevel()
    { return 20; }

// the general monkey accuracy - the +4 on his chance to hit (print capture p.
// 266)
inline int dkcMonkeyToHitBonus()
    { return 4; }

// the general monkey damage bonus - the +5 on damage (print capture p. 266)
inline int dkcMonkeyDmgBonus()
    { return 5; }

// the general monkey host - 50% of the time accompanied by 10d6 intelligent
// monkeys (print capture p. 266)
inline int dkcMonkeyHostPct()
    { return 50; }

// the general monkey host - the 10 of the 10d6 intelligent monkeys (print
// capture p. 266)
inline int dkcMonkeyHostDice()
    { return 10; }

// the general monkey host - the d6 of the 10d6 monkeys (print capture p. 266)
inline int dkcMonkeyHostSides()
    { return 6; }

// the general monkey host troops - the AC 7, move 12, HD 1, 1 attack, armed
// with swords and spears (print capture p. 266)
inline int dkcMonkeyHostAC()
    { return 7; }

// the general monkey experience - the 24,800 of the X/24,800 (print capture
// p. 265)
inline int dkcMonkeyXPBase()
    { return 24800; }

// the general monkey experience per hit point - the + 35/hp (print capture p.
// 265)
inline int dkcMonkeyXPPerHP()
    { return 35; }

// the general monkey duty - sent on missions which require cleverness and
// stealth (print capture p. 266)
inline int dkcMonkeyCleverStealthMissions()
    { return 1; }

// the general monkey armament - carries a rod of lordly might at all times
// (print capture p. 266)
inline int dkcMonkeyRodOfLordlyMight()
    { return 1; }

// the general monkey temperament - noted for tricks and pranks, of all the
// generals the most likely to challenge or disregard his orders; intensely
// curious, sometimes bribed with interesting information or magic (print
// capture p. 266)
inline int dkcMonkeyTricksAndPranks()
    { return 1; }

}   // namespace rules
