// =========================================================================================
// Adnd1 - rules/oa89hainu.h
// OA MONSTERS - THE HAI NU, printed capture p. 268 - the Sea Lord servitors
// round
// census 640 -> 641.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 171 closed, 64 open - the hai nu box flips
// (census 640 -> 641); NEXT - R719: the Hsing-Sing (capture p. 269), prefix
// dkg (verify free at the landing), audit "R719 OA monsters Hsing-Sing
// audit", include after rules/oa89hainu.h
//
namespace rules {

// ---- the stat block ----

// the appearing minimum - the 4 of the 4-40 appearing (print capture p. 268)
inline int dkfAppearMin()
    { return 4; }

// the appearing maximum - the 40 of the 4-40 appearing (print capture p. 268)
inline int dkfAppearMax()
    { return 40; }

// the hai nu armor class - the AC 7 of the stat block (print capture p. 268)
inline int dkfAC()
    { return 7; }

// the walking rate - the 6 of the move 6/15 (print capture p. 268)
inline int dkfMoveWalk()
    { return 6; }

// the swimming rate - the 15 of the move 6/15 (print capture p. 268)
inline int dkfMoveSwim()
    { return 15; }

// the hit dice minimum - the 1 of the 1 to 4 (print capture p. 268)
inline int dkfHDMin()
    { return 1; }

// the hit dice maximum - the 4 of the 1 to 4 (print capture p. 268)
inline int dkfHDMax()
    { return 4; }

// the in-lair percentage - the 30% of the stat block (print capture p. 268)
inline int dkfLairPct()
    { return 30; }

// the frequency - the rare of the stat block (print capture p. 268)
inline int dkfFrequencyRare()
    { return 1; }

// the treasure type - the U of the stat block (print capture p. 268)
inline int dkfTreasureTypeU()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 268)
inline int dkfAttackCount()
    { return 1; }

// the damage clause - the by weapon type of the stat block (print capture p.
// 268)
inline int dkfDamageByWeaponType()
    { return 1; }

// the special attacks - the nil of the stat block (print capture p. 268)
inline int dkfSpecialAttacksNil()
    { return 1; }

// the special defense - the immune to water attacks of the stat block (print
// capture p. 268)
inline int dkfImmuneToWaterAttacks()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 268)
inline int dkfMagicResistStandard()
    { return 1; }

// the intelligence - the average to high of the stat block (print capture p.
// 268)
inline int dkfIntelligenceAvgToHigh()
    { return 1; }

// the alignment - the lawful neutral of the stat block (print capture p. 268)
inline int dkfAlignmentLawfulNeutral()
    { return 1; }

// the size class - the M of the stat block (print capture p. 268)
inline int dkfSizeMedium()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 268)
inline int dkfPsionicNil()
    { return 1; }

// ---- the xp ladder ----

// the 1 HD xp base - the I/14 of the xp ladder (print capture p. 268)
inline int dkfXP1Base()
    { return 14; }

// the 1 HD xp per hit point - the 14 + 1/hp of the xp ladder (print capture
// p. 268)
inline int dkfXP1PerHP()
    { return 1; }

// the 2 HD xp base - the II/28 of the xp ladder (print capture p. 268)
inline int dkfXP2Base()
    { return 28; }

// the 2 HD xp per hit point - the 28 + 2/hp of the xp ladder (print capture
// p. 268)
inline int dkfXP2PerHP()
    { return 2; }

// the 3 HD xp base - the III/50 of the xp ladder (print capture p. 268)
inline int dkfXP3Base()
    { return 50; }

// the 3 HD xp per hit point - the 50 + 3/hp of the xp ladder (print capture
// p. 268)
inline int dkfXP3PerHP()
    { return 3; }

// the 4 HD xp base - the IV/85 of the xp ladder (print capture p. 268)
inline int dkfXP4Base()
    { return 85; }

// the 4 HD xp per hit point - the 85 + 4/hp of the xp ladder (print capture
// p. 268)
inline int dkfXP4PerHP()
    { return 4; }

// ---- the aquatic servitor ----

// the nature - an aquatic race of creatures (print capture p. 268)
inline int dkfAquaticRace()
    { return 1; }

// the form - humanoid with webbed hands and feet (print capture p. 268)
inline int dkfWebbedHandsAndFeet()
    { return 1; }

// the coat - bodies covered with a soft fur that shimmers in many different
// colors (print capture p. 268)
inline int dkfShimmeringFur()
    { return 1; }

// the range - the warm shallow seas of the sub-tropical and tropical regions
// (print capture p. 268)
inline int dkfWarmShallowSeas()
    { return 1; }

// the work - gathering fish and attending the court of the Lord of the Sea
// (print capture p. 268)
inline int dkfGathersFish()
    { return 1; }

// the allegiance - attending the court of the Lord of the Sea (print capture
// p. 268)
inline int dkfAttendsSeaLordCourt()
    { return 1; }

// the tongues - only the language of their own race and the court language of
// the Sea Lord (print capture p. 268)
inline int dkfSpeaksOnlyOwnAndCourt()
    { return 1; }

// ---- the matriarchal community ----

// the community - the hulls of sunken ships and the stands of thick kelp
// (print capture p. 268)
inline int dkfLairSunkenShipsAndKelp()
    { return 1; }

// the taste - love bright treasures and gather precious cargoes from ships
// (print capture p. 268)
inline int dkfLovesBrightTreasures()
    { return 1; }

// the society - matriarchal, dominated by the females (print capture p. 268)
inline int dkfSocietyMatriarchal()
    { return 1; }

// the female share - the 75% of those encountered are female (print capture
// p. 268)
inline int dkfFemalePct()
    { return 75; }

// the matron hit dice - the 6 HD of the community matron (print capture p.
// 268)
inline int dkfMatronHD()
    { return 6; }

// the matron armor class - the AC 5 of the community matron (print capture p.
// 268)
inline int dkfMatronAC()
    { return 5; }

// the leader - each community is led by a matron (print capture p. 268)
inline int dkfMatronLeadsCommunity()
    { return 1; }

// the defense corps - the tamed sharks defending the community (print capture
// p. 268)
inline int dkfTamedSharkGuards()
    { return 1; }

// the shark dice - the 2d6 tamed sharks defending the community (print
// capture p. 268)
inline int dkfSharkDice()
    { return 2; }

// the shark dice sides - the 2d6 tamed sharks defending the community (print
// capture p. 268)
inline int dkfSharkSides()
    { return 6; }

// the diplomacy - quite good relations with sharks, porpoises, and whales
// (print capture p. 268)
inline int dkfGoodRelationsSeaCreatures()
    { return 1; }

// the escort chance - the 40% chance of the sea creatures present with any
// band (print capture p. 268)
inline int dkfEscortPct()
    { return 40; }

// the escort dice - the 3d4 sharks, porpoises, or whales with any band (print
// capture p. 268)
inline int dkfEscortDice()
    { return 3; }

// the escort dice sides - the 3d4 sharks, porpoises, or whales with any band
// (print capture p. 268)
inline int dkfEscortSides()
    { return 4; }

// ---- the arms table ----

// the arms table row count - the four weapon mixes of the encountered band
// (print capture p. 268)
inline int dkfArmsCount()
    { return 4; }

// the arms percentage - row by row the short sword, the trident and speargun,
// the trident and dagger, the short sword and net (print capture p. 268)
inline int dkfArmsPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 50;
        case 2:
            return 20;
        case 3:
            return 10;
        default:
            return 0;
        }
    }

// ---- the fisherman feud ----

// the restraint - seldom attack surface vessels, preferring to be left alone
// (print capture p. 268)
inline int dkfSeldomAttackVessels()
    { return 1; }

// the temperament - by nature quite peaceful and friendly (print capture p.
// 268)
inline int dkfPeacefulAndFriendly()
    { return 1; }

// the resolve - vigorously defend their hunting grounds and homes from
// outsiders (print capture p. 268)
inline int dkfDefendsHuntingGrounds()
    { return 1; }

// the harassment - the cut lines, fouled nets, and small leaks for fishermen
// who ply their waters (print capture p. 268)
inline int dkfCutsFishermenLines()
    { return 1; }

// the escalation - petition the Lord of the Sea for more drastic action
// (print capture p. 268)
inline int dkfPetitionsSeaLord()
    { return 1; }

// ---- the element vulnerabilities ----

// the water need - cannot survive very long out of water (print capture p.
// 269)
inline int dkfCannotLongSurviveOutOfWater()
    { return 1; }

// the out-of-water damage - the 1 point each round spent totally out of water
// (print capture p. 269)
inline int dkfOutOfWaterDmgPerRound()
    { return 1; }

// the fire vulnerability - the double normal damage from fire-based attacks
// (print capture p. 269)
inline int dkfFireDamageMult()
    { return 2; }

// the cold vulnerability - the +1 per die of damage from cold-based attacks
// (print capture p. 269)
inline int dkfColdBonusPerDie()
    { return 1; }

// the water immunity - immune to all forms of water-based attack (print
// capture p. 269)
inline int dkfImmuneToAllWaterForms()
    { return 1; }

}   // namespace rules
