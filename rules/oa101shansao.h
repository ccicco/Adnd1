// =========================================================================================
// Adnd1 - rules/oa101shansao.h
// OA MONSTERS - THE SHAN SAO, printed capture pp. 282-283 - the woodlander
// round
// census 652 -> 653.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 183 closed, 52 open - the shan sao box
// flips (census 652 -> 653); NEXT - R731: the Shirokinukatsukami, the Greater
// Spirit (capture pp. 283-284), prefix dks (verify free at the landing),
// audit "R731 OA monsters Shirokinukatsukami audit", include after
// rules/oa101shansao.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the uncommon of the stat block (print capture p. 282)
inline int dkrFrequencyUncommon()
    { return 1; }

// the appearing minimum - the 1 of the 1-10, times 3 in the lair, of the stat
// block (print capture p. 282)
inline int dkrAppearMin()
    { return 1; }

// the appearing maximum - the 10 of the 1-10 of the stat block (print capture
// p. 282)
inline int dkrAppearMax()
    { return 10; }

// the lair multiplier - the x3 in lair of the appearing line (print capture
// p. 282)
inline int dkrLairMultiplier()
    { return 3; }

// the armor class - the 4 of the stat block (print capture p. 282)
inline int dkrAC()
    { return 4; }

// the ground move - the 6 of the 6/15 of the stat block (print capture p.
// 282)
inline int dkrMoveGround()
    { return 6; }

// the fly move - the 15 of the 6/15, the bird polymorph hence the flying
// speed (print capture p. 282)
inline int dkrMoveFly()
    { return 15; }

// the maneuver class - the A of the stat block move line (print capture p.
// 282)
inline int dkrMCA()
    { return 1; }

// the hit dice minimum - the 2 of the 2-4 of the stat block (print capture p.
// 282)
inline int dkrHDMin()
    { return 2; }

// the hit dice maximum - the 4 of the 2-4 of the stat block (print capture p.
// 282)
inline int dkrHDMax()
    { return 4; }

// the in-lair percent - the 10% of the stat block (print capture p. 282)
inline int dkrLairPct()
    { return 10; }

// the treasure type - the B of the stat block (print capture p. 282)
inline int dkrTreasureB()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 282)
inline int dkrAttackCount()
    { return 1; }

// the damage minimum - the 1 of the 1-6 (print capture p. 282)
inline int dkrDmgMin()
    { return 1; }

// the damage maximum - the 6 of the 1-6 (print capture p. 282)
inline int dkrDmgMax()
    { return 6; }

// the special attacks - the disease of the stat block (print capture p. 282)
inline int dkrSpecialAttacksDisease()
    { return 1; }

// the special defense - the summon tigers of the stat block (print capture p.
// 282)
inline int dkrSummonTigers()
    { return 1; }

// the special defense - the immune to fear of the stat block (print capture
// p. 282)
inline int dkrImmuneToFear()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 282)
inline int dkrMRStandard()
    { return 1; }

// the intelligence - the average of the stat block (print capture p. 282)
inline int dkrIntAverage()
    { return 1; }

// the alignment - the chaotic neutral of the stat block (print capture p.
// 282)
inline int dkrAlignmentChaoticNeutral()
    { return 1; }

// the size class - the S of the stat block (print capture p. 282)
inline int dkrSizeSmall()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 282)
inline int dkrPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 282)
inline int dkrModesNil()
    { return 1; }

// ---- the xp ladder ----

// the 2 HD xp base - the 36 of the II/36 + 2 per hp (print capture p. 282)
inline int dkrXP2Base()
    { return 36; }

// the 2 HD xp per hit point - the 2 of the II/36 + 2/hp (print capture p.
// 282)
inline int dkrXP2PerHP()
    { return 2; }

// the 3 HD xp base - the 65 of the III/65 + 3 per hp (print capture p. 282)
inline int dkrXP3Base()
    { return 65; }

// the 3 HD xp per hit point - the 3 of the III/65 + 3/hp (print capture p.
// 282)
inline int dkrXP3PerHP()
    { return 3; }

// the 4 HD xp base - the 110 of the III/110 + 4 per hp, the capture
// misreading 111 for III (print capture p. 282)
inline int dkrXP4Base()
    { return 110; }

// the 4 HD xp per hit point - the 4 of the III/110 + 4/hp (print capture p.
// 282)
inline int dkrXP4PerHP()
    { return 4; }

// ---- the woodlanders ----

// the build - a race of one-foot-tall humanoids (print capture p. 282)
inline int dkrOneFootTall()
    { return 1; }

// the home - they live in woodland hills (print capture p. 282)
inline int dkrWoodlandHills()
    { return 1; }

// the character - known for being an extremely fearless and private race,
// having little communication with the outside world (print capture p. 282)
inline int dkrFearlessAndPrivate()
    { return 1; }

// the temper - quick to take offense and equally quick to return it (print
// capture p. 282)
inline int dkrQuickToTakeOffense()
    { return 1; }

// the skill - quite adept at defending themselves (print capture p. 282)
inline int dkrAdeptAtDefense()
    { return 1; }

// ---- the powers ----

// the polymorph - they can polymorph three times per day, assuming the shape
// of a bird (print capture p. 282)
inline int dkrPolymorphIntoBird()
    { return 1; }

// the polymorph uses - the shan sao can polymorph three times per day (print
// capture p. 282)
inline int dkrPolymorphPerDay()
    { return 3; }

// the weapons - in combat they fight with short swords, darts, and uchi-ne
// (print capture p. 282)
inline int dkrFightsWithSwordsDartsUchiNe()
    { return 1; }

// the disease power - once per day they can cause disease as per the spell,
// except they need not touch their victim, only point at him within 10 feet
// (print capture p. 282)
inline int dkrCausesDiseaseOncePerDay()
    { return 1; }

// the disease range - they need not touch their victim, only point if he is
// within 10 feet (print capture p. 282)
inline int dkrDiseaseRangeFt()
    { return 10; }

// the summon power - once per day the shan sao can summon 1-3 tigers within a
// half mile radius, if the DM determines any are present (print capture p.
// 282)
inline int dkrSummonsTigersOncePerDay()
    { return 1; }

// the tiger minimum - the 1 of the 1-3 tigers summoned within a half mile
// (print capture p. 282)
inline int dkrTigerSummonMin()
    { return 1; }

// the tiger maximum - the 3 of the 1-3 tigers summoned within a half mile
// (print capture p. 282)
inline int dkrTigerSummonMax()
    { return 3; }

// the tiger loyalty - the tigers fight for the shan sao and are able to
// understand his desires and needs (print capture p. 282)
inline int dkrTigersArriveAndFight()
    { return 1; }

// the tiger arrival die - the tigers arrive in 1d6 turns (print capture p.
// 282)
inline int dkrTigerArrivalDie()
    { return 6; }

// the spellcasters - the 5% chance shan sao casts spells equal to a wu jen of
// the same level as its hit dice (print capture p. 283)
inline int dkrWuJenSpellcasters()
    { return 1; }

// the spellcaster chance - the 5% chance any shan sao encountered casts
// spells equal to a wu jen of its hit-dice level (print capture p. 283)
inline int dkrWuJenChancePct()
    { return 5; }

// ---- the village ----

// the village - they make their homes in the hearts of thick bamboo groves
// (print capture p. 283)
inline int dkrBambooGroveHomes()
    { return 1; }

// the houses - they live in simple thatched houses, centered around a
// communal cooking pot (print capture p. 283)
inline int dkrThatchedHouses()
    { return 1; }

// the females - in addition to the dice roll there are 50% more females, of 1
// HD, who fight to defend their homes (print capture p. 283)
inline int dkrFemalesDefend()
    { return 1; }

// the female bonus - in addition to the dice roll there are 50% more who are
// females (print capture p. 283)
inline int dkrFemaleBonusPct()
    { return 50; }

// the female hit dice - the females have 1 HD and fight to defend their homes
// (print capture p. 283)
inline int dkrFemaleHD()
    { return 1; }

// the guards - the 10% chance the village is guarded by 1-2 tigers who lair
// with the shan sao (print capture p. 283)
inline int dkrVillageGuardTigers()
    { return 1; }

// the village guard chance - the 10% chance the village is guarded by 1-2
// tigers who lair with the shan sao (print capture p. 283)
inline int dkrVillageGuardChancePct()
    { return 10; }

// the village guard minimum - the 1 of the 1-2 guard tigers (print capture p.
// 283)
inline int dkrVillageGuardTigersMin()
    { return 1; }

// the village guard maximum - the 2 of the 1-2 guard tigers (print capture p.
// 283)
inline int dkrVillageGuardTigersMax()
    { return 2; }

// the dislike - they do not like loud noises, particularly bursting bamboo
// (print capture p. 283)
inline int dkrDislikeLoudNoises()
    { return 1; }

// the languages - the language of their own kind, the trade language, and
// that of the animal court (print capture p. 283)
inline int dkrSpeaksThreeLanguages()
    { return 1; }

}   // namespace rules
