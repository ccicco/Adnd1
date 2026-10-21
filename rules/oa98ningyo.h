// =========================================================================================
// Adnd1 - rules/oa98ningyo.h
// OA MONSTERS - THE NINGYO, printed capture pp. 279-280 - the sea folk round
// census 649 -> 650.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 180 closed, 55 open - the ningyo box flips
// (census 649 -> 650); NEXT - R728: the Oni, the Lesser Spirit (capture pp.
// 280-281), prefix dkp (verify free at the landing), audit "R728 OA monsters
// Oni audit", include after rules/oa98ningyo.h
//
namespace rules {

// ---- the stat block ----

// the frequency - the rare of the stat block (print capture p. 279)
inline int dkoFrequencyRare()
    { return 1; }

// the appearing minimum - the 2 of the 2-20 of the stat block (print capture
// p. 279)
inline int dkoAppearMin()
    { return 2; }

// the appearing maximum - the 20 of the 2-20 of the stat block (print capture
// p. 279)
inline int dkoAppearMax()
    { return 20; }

// the armor class - the 7 of the stat block (print capture p. 279)
inline int dkoAC()
    { return 7; }

// the move - the swim 18 of the stat block, the capture doubling the slash of
// the print (print capture p. 279)
inline int dkoMove()
    { return 18; }

// the hit dice minimum - the 2 of the 2 to 5 of the stat block (print capture
// p. 279)
inline int dkoHDMin()
    { return 2; }

// the hit dice maximum - the 5 of the 2 to 5 of the stat block (print capture
// p. 279)
inline int dkoHDMax()
    { return 5; }

// the in-lair percent - the 30% of the stat block (print capture p. 279)
inline int dkoLairPct()
    { return 30; }

// the treasure type - the I of the stat block (print capture p. 279)
inline int dkoTreasureI()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 279)
inline int dkoAttackCount()
    { return 1; }

// the damage per attack - the by weapon type of the stat block (print capture
// p. 279)
inline int dkoDamageByWeapon()
    { return 1; }

// the special attacks - the spells of the stat block (print capture p. 279)
inline int dkoSpecialAttacksSpells()
    { return 1; }

// the special defenses - the spells of the stat block (print capture p. 279)
inline int dkoSpecialDefensesSpells()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 279)
inline int dkoMRStandard()
    { return 1; }

// the intelligence - the very of the stat block (print capture p. 279)
inline int dkoIntVery()
    { return 1; }

// the alignment - the chaotic good of the stat block (print capture p. 279)
inline int dkoAlignmentChaoticGood()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 279)
inline int dkoPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 279)
inline int dkoModesNil()
    { return 1; }

// ---- the xp ladder ----

// the 2 HD xp base - the 73 of the III/73 + 2 per hp (print capture p. 279)
inline int dkoXP2Base()
    { return 73; }

// the 2 HD xp per hit point - the 2 of the III/73 + 2/hp (print capture p.
// 279)
inline int dkoXP2PerHP()
    { return 2; }

// the 3 HD xp base - the 105 of the III/105 + 3 per hp, the capture
// misreading 111 for III (print capture p. 279)
inline int dkoXP3Base()
    { return 105; }

// the 3 HD xp per hit point - the 3 of the III/105 + 3/hp (print capture p.
// 279)
inline int dkoXP3PerHP()
    { return 3; }

// the 4 HD xp base - the 150 of the III/150 + 4 per hp (print capture p. 279)
inline int dkoXP4Base()
    { return 150; }

// the 4 HD xp per hit point - the 4 of the III/150 + 4/hp (print capture p.
// 279)
inline int dkoXP4PerHP()
    { return 4; }

// the 5 HD xp base - the 205 of the IV/205 + 5 per hp (print capture p. 279)
inline int dkoXP5Base()
    { return 205; }

// the 5 HD xp per hit point - the 5 of the IV/205 + 5/hp (print capture p.
// 279)
inline int dkoXP5PerHP()
    { return 5; }

// ---- the sea folk ----

// the kin - a close relative of the merman and mermaid, virtually identical
// in appearance (print capture p. 279)
inline int dkoMermanRelative()
    { return 1; }

// the mark - except that it always has flaming red hair (print capture p.
// 279)
inline int dkoFlamingRedHair()
    { return 1; }

// the home - they dwell under the waves and rarely come to the surface (print
// capture p. 279)
inline int dkoDwellUnderWaves()
    { return 1; }

// the allegiance - preferring to serve the Sea Lord rather than become
// involved in the affairs of men (print capture p. 279)
inline int dkoServeTheSeaLord()
    { return 1; }

// the temper - quite kindly and helpful to humans (print capture p. 280)
inline int dkoKindlyHelpful()
    { return 1; }

// the sailors - they consider them protectors and sometimes make offerings to
// them, especially during great storms (print capture p. 280)
inline int dkoSailorsProtectors()
    { return 1; }

// ---- the bearing ----

// the arms - ningyo normally do not carry weapons (print capture p. 280)
inline int dkoNormallyUnarmed()
    { return 1; }

// the armed choice - when armed they have either a trident or spear (print
// capture p. 280)
inline int dkoArmedTridentOrSpear()
    { return 1; }

// the bearing - generally peaceful and non-combative, preferring to avoid a
// fight whenever possible (print capture p. 280)
inline int dkoPeacefulNonCombative()
    { return 1; }

// the exception - if forced, they fight with whatever weapons are available
// (print capture p. 280)
inline int dkoFightIfForced()
    { return 1; }

// the spellcasting - they have the spellcasting abilities of a shukenja and
// wu jen of a level equal to their hit dice, so a 3 HD ningyo has the spell
// ability of a 3rd-level shukenja and wu jen (print capture p. 280)
inline int dkoSpellcastingShukenjaWuJen()
    { return 1; }

// ---- the life ----

// the society - they do not form communities under the sea (print capture p.
// 280)
inline int dkoNoUnderseaCommunities()
    { return 1; }

// the roaming - instead they roam with the currents and follow the schools of
// fish upon which they feed (print capture p. 280)
inline int dkoRoamWithCurrents()
    { return 1; }

// the water need - they cannot survive out of water for any length of time
// (print capture p. 280)
inline int dkoCannotSurviveOutOfWater()
    { return 1; }

// the surface loss - they lose 1 hit point per round spent above the surface
// (print capture p. 280)
inline int dkoSurfaceLossPerRound()
    { return 1; }

// the languages - they speak the languages of the Sea Lord, fishes, and the
// trade language (print capture p. 280)
inline int dkoSpeakThreeLanguages()
    { return 1; }

}   // namespace rules
