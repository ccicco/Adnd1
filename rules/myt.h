// =========================================================================================
// Adnd1 - rules/myt.h
// The Dragon issue-12 opener part two - the Persian Mythos by Jerome
// Arkenberg (folios 8-11) and the Lovecraftian Mythos by Rob Kuntz with J.
// Eric Holmes (folios 18-21): the mythos pair, both GD&H-compatible
// census 842 -> 843.
//
// Pinned from The Dragon Vol. II No. 6 (February 1978), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 12;
// the source lives in the archive.org item accessory-dragon-magazine-012,
// file Accessory - Dragon Magazine #012_djvu.xml). PRINT FOLIO = PDF PAGE,
// verified at the TOC alignments (5, 6, 8, 12, 13, 18, 28). The transcripts
// ride extract/dragon/012/p001 through p032, landed at R919; the article
// CHAIN is the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: the Persian grid's Atar
// armor-class and psionic cells print bar garbles and the Vayu move prints
// 187/36 for the 18/36 dual rate; the hero strength cells print as fraction
// garbles - Yima 185 (18/95), Hoshang 189 (18/90), Takhmoruw 1859 (18/59),
// Faridun 18;;, Keresaspa 18,5 (18/50) - all riding the -1 sentinel with the
// census, the clean stats pinning clean; the unlimited hit-point and spell
// cells of Ahura Mazda and Ahriman print words and ride the sentinel; the
// Lovecraftian grid's see-below magic cells and resistant-to-all-psionic
// cells ride the sentinel, and the Yig split armor class pins as head-3
// chest-5 consts with the grid cell riding the sentinel. The one-visual-check
// precedent of R919 (the full-res scan plus the djvu word geometry) stands
// for any future cell dispute.
//
namespace rules {

// ---- the Persian Mythos (folios 8-11) ----

// the Persian Mythos stat grid - thirteen rows: Ahura Mazda, Ahriman, the
// archangel block, the seven yazatas, the hero block, the archdemon block and
// the demon block (folios 8-11)
inline int mytPersianRows()
    { return 13; }

// the six Persian heroes on the common block - Yima, Hoshang, Takhmoruw,
// Thrita, Faridun and Keresaspa (folio 10)
inline int mytPersianHeroRows()
    { return 6; }

// the seven archangels of Ahura Mazda on the common stat block - Vohu Manah,
// Asha, Kshathra Vairya, Armaiti, Haurvatat and Ameretat, Sraosha and Mithra
// (folios 8-9)
inline int mytPersianArchangels()
    { return 7; }

// the seven yazatas - Vayu, Tishtrya, Ardvi Sura Anahita, Verethragna,
// Rapithwin, Atar and Haoma (folio 9)
inline int mytPersianYazatas()
    { return 7; }

// Sraosha is a warrior in armor armed with a battle axe +3 (folio 8)
inline int mytSraoshaBattleAxePlus()
    { return 3; }

// Mithra wields a pike of silver +1 (folio 9)
inline int mytMithraPikePlus()
    { return 1; }

// Mithra wears gold armor +3 (folio 9)
inline int mytMithraArmorPlus()
    { return 3; }

// Vayu carries a sharp spear +1 (folio 9)
inline int mytVayuSpearPlus()
    { return 1; }

// the rest of Vayu's weapons are gold, all +2 to hit (folio 9)
inline int mytVayuGoldWeaponsPlus()
    { return 2; }

// Tishtrya takes three forms - a boy of fifteen, a bull and a horse (folio 9)
inline int mytTishtryaForms()
    { return 3; }

// Verethragna has ten forms, from a strong wind to a man with a golden sword
// (folio 9)
inline int mytVerethragnaForms()
    { return 10; }

// the Persian gods split dualist - the forces of good are Lawful, the forces
// of evil Chaotic (folio 8)
inline bool mytPersianDualistSplit()
    { return true; }

// Haoma is both plant and god, dying pressed and defeating evil for the
// faithful (folio 9)
inline bool mytHaomaPlantAndGod()
    { return true; }

// Tishtrya fights greatly in any form only when animal sacrifices sustain him
// (folio 9)
inline bool mytTishtryaSustainedBySacrifice()
    { return true; }

// the armor class - Ahura Mazda and Ahriman minus 2, the archangels, yazatas,
// archdemons and demons 2, Haoma 3; the Atar cell prints a bar garble and the
// hero block prints As a Normal Man, both riding the sentinel (folios 8-10)
inline int mytPersianAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return -1;
        case 9:
            return 3;
        case 10:
            return -1;
        case 11:
            return 2;
        case 12:
            return 2;
        default:
            return -1;
        }
    }

// the move in inches - the supreme pair 20, the archangels and archdemons 18,
// the yazatas 15 or 18, the heroes 12; the Vayu cell garbles as 187/36 for
// the 18/36 dual rate and rides the sentinel (folios 8-10)
inline int mytPersianMove(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 18;
        case 3:
            return -1;
        case 4:
            return 15;
        case 5:
            return 15;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 18;
        case 9:
            return 15;
        case 10:
            return 12;
        case 11:
            return 18;
        case 12:
            return 15;
        default:
            return -1;
        }
    }

// the hit points - Ahriman 300, the archangels and archdemons 250, the demons
// 200, Tishtrya and Rapithwin 225, Anahita and Haoma 175, the heroes 100; the
// Ahura Mazda cell prints Unlimited and rides the sentinel (folios 8-10)
inline int mytPersianHp(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 300;
        case 2:
            return 250;
        case 3:
            return 250;
        case 4:
            return 225;
        case 5:
            return 175;
        case 6:
            return 250;
        case 7:
            return 225;
        case 8:
            return 250;
        case 9:
            return 175;
        case 10:
            return 100;
        case 11:
            return 250;
        case 12:
            return 200;
        default:
            return -1;
        }
    }

// the magic-user level - the archangels and archdemons Wizard 20th, the
// yazatas Wizard 14th except Haoma 12th, the heroes Nil as zero; the supreme
// pair print Unlimited Spells and ride the sentinel (folios 8-10)
inline int mytPersianMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 20;
        case 3:
            return 14;
        case 4:
            return 14;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 14;
        case 8:
            return 14;
        case 9:
            return 12;
        case 10:
            return 0;
        case 11:
            return 20;
        case 12:
            return 14;
        default:
            return -1;
        }
    }

// the fighter level - the supreme pair Lord 40th, the archangels, archdemons
// and Vayu 15th, the demons and most yazatas 14th, Anahita 11th, Haoma 10th,
// the heroes Lord 12th; Vayu prints 15th without the Lord prefix, noted as
// scanned (folios 8-10)
inline int mytPersianFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 40;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 14;
        case 5:
            return 11;
        case 6:
            return 15;
        case 7:
            return 14;
        case 8:
            return 14;
        case 9:
            return 10;
        case 10:
            return 12;
        case 11:
            return 15;
        case 12:
            return 14;
        default:
            return -1;
        }
    }

// the psionic class - the supreme pair Class 6, the archangels and archdemons
// Class 1, the yazatas Class 2 except Haoma Class 3, the heroes Nil as zero;
// the Atar cell prints a bar garble and rides the sentinel (folios 8-10)
inline int mytPersianPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return -1;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 2;
        default:
            return -1;
        }
    }

// the strength - Thrita 15 pins clean; Yima prints 185 (18/95), Hoshang 189
// (18/90), Takhmoruw 1859 (18/59), Faridun 18;; and Keresaspa 18,5 (18/50),
// all fraction garbles riding the sentinel as-scanned (folio 10)
inline int mytPersianHeroStr(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return -1;
        default:
            return -1;
        }
    }

// the intelligence - Yima 17, Hoshang 17, Takhmoruw 16, Thrita 17, Faridun
// 14, Keresaspa 14 (folio 10)
inline int mytPersianHeroInt(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 17;
        case 2:
            return 16;
        case 3:
            return 17;
        case 4:
            return 14;
        case 5:
            return 14;
        default:
            return -1;
        }
    }

// the wisdom - Yima 9, Hoshang 13, Takhmoruw 12, Thrita 18, Faridun 8,
// Keresaspa 12 (folio 10)
inline int mytPersianHeroWis(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 18;
        case 4:
            return 8;
        case 5:
            return 12;
        default:
            return -1;
        }
    }

// the constitution - Yima 17, Hoshang 18, Takhmoruw 16, Thrita 15, Faridun
// 17, Keresaspa 17 (folio 10)
inline int mytPersianHeroCon(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 16;
        case 3:
            return 15;
        case 4:
            return 17;
        case 5:
            return 17;
        default:
            return -1;
        }
    }

// the dexterity - Yima 17, Hoshang 17, Takhmoruw 16, Thrita 12, Faridun 17,
// Keresaspa 17 (folio 10)
inline int mytPersianHeroDex(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 17;
        case 2:
            return 16;
        case 3:
            return 12;
        case 4:
            return 17;
        case 5:
            return 17;
        default:
            return -1;
        }
    }

// the charisma - Yima 17, Hoshang 16, Takhmoruw 16, Thrita 12, Faridun 15,
// Keresaspa 17 (folio 10)
inline int mytPersianHeroCha(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 16;
        case 2:
            return 16;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 17;
        default:
            return -1;
        }
    }

// ---- the Lovecraftian Mythos (folios 18-21) ----

// the Great Old Ones stat grid - nine rows: Azathoth, Cthulhu, Hastur,
// Nyarlathotep, Shub-Niggurath, Cthuga, Ithaqua, Yig and Yog Sothoth (folios
// 18-21)
inline int mytGOORows()
    { return 9; }

// the inhuman and partly-human races grid - six rows: the Byakhee, the Deep
// Ones, the Great Race, the Old Ones, the Mi-Go and the Shaggoths (folio 21)
inline int mytRaceRows()
    { return 6; }

// evil callers run a 25 percent chance of being destroyed by the gods they
// evoke (folio 18)
inline int mytCallDestroyedPercent()
    { return 25; }

// a 50 percent chance of a servant of the Old Ones appearing to a caller
// (folio 18)
inline int mytCallServantPercent()
    { return 50; }

// a 25 percent chance of the god itself appearing and cooperating (folio 18)
inline int mytCallGodPercent()
    { return 25; }

// an attacking god ravages the countryside for 1-6 turns, the floor (folio
// 18)
inline int mytRavageMinTurns()
    { return 1; }

// the ravage ceiling, 1-6 turns, then the god disappears (folio 18)
inline int mytRavageMaxTurns()
    { return 6; }

// Azathoth's saving throw against all forms of magic is 5 (folio 18)
inline int mytAzathothSaveVsMagic()
    { return 5; }

// Cthulhu regenerates 10 hit points per melee round (folio 18)
inline int mytCthulhuRegen()
    { return 10; }

// if the Elder Seal breaks, everyone within 100 miles saves or goes insane
// (folio 18)
inline int mytCthulhuInsanityRadiusMiles()
    { return 100; }

// Cthulhu calls up 10-100 Deep Ones from the sea, the floor (folio 18)
inline int mytCthulhuDeepOnesMin()
    { return 10; }

// the Deep One call ceiling, 10-100 (folio 18)
inline int mytCthulhuDeepOnesMax()
    { return 100; }

// Hastur regenerates 5 hits per melee round (folio 18)
inline int mytHasturRegen()
    { return 5; }

// Hastur moves 12 and flies 36 (folio 18)
inline int mytHasturFlyInches()
    { return 36; }

// Hastur calls 1-10 Byakhee or Mi-Go from Lost Carcosa and Yuggoth, the floor
// (folio 18)
inline int mytHasturCallsMin()
    { return 1; }

// the Byakhee-or-Mi-Go call ceiling, 1-10 (folio 18)
inline int mytHasturCallsMax()
    { return 10; }

// Nyarlathotep's presence-charm covers a 30-foot radius (folio 18)
inline int mytNyarlathotepCharmRadiusFeet()
    { return 30; }

// the Nyarlathotep charm saves are made at -2 to the die roll (folio 18)
inline int mytNyarlathotepCharmSavePenalty()
    { return 2; }

// Nyarlathotep calls an army of 10-1000 wild beasts or mindless humans, the
// floor (folio 18)
inline int mytNyarlathotepArmyMin()
    { return 10; }

// the army call ceiling, 10-1000 (folio 18)
inline int mytNyarlathotepArmyMax()
    { return 1000; }

// the Shub-Niggurath grey pool is 100 feet across (folio 18)
inline int mytShubPoolDiameterFeet()
    { return 100; }

// the pool puts forth 1-10 small monsters per melee round, the floor (folio
// 18)
inline int mytShubSpawnMin()
    { return 1; }

// the spawn ceiling, 1-10 per melee round (folio 18)
inline int mytShubSpawnMax()
    { return 10; }

// Shub-Niggurath throws charm person or monster spells of the 15th level,
// once per turn (folio 18)
inline int mytShubCharmLevel()
    { return 15; }

// Cthuga uses all fire-connected spells three times a day for each spell
// (folio 20)
inline int mytCthugaFireSpellsPerDay()
    { return 3; }

// Cthuga summons up to 8 twelve-hit-die fire elementals, once per week (folio
// 20)
inline int mytCthugaFireElementals()
    { return 8; }

// the Cthuga fire elementals are 12-hit-die flame creatures (folio 20)
inline int mytCthugaElementalHD()
    { return 12; }

// Cthuga strikes once per melee round for 3-30 points of fire damage, the
// floor (folio 20)
inline int mytCthugaDamageMin()
    { return 3; }

// the Cthuga strike ceiling, 3-30 (folio 20)
inline int mytCthugaDamageMax()
    { return 30; }

// Cthuga ignites flammables within a 10-yard radius of his body (folio 20)
inline int mytCthugaIgnitionRadiusYards()
    { return 10; }

// Cthuga may only be struck effectively by +3 or better weapons (folio 20)
inline int mytCthugaWeaponPlusNeeded()
    { return 3; }

// Ithaqua summons one 16-die air elemental per day (folio 20)
inline int mytIthaquaAirElementalHD()
    { return 16; }

// Ithaqua strikes twice per melee round doing 2-16 points of buffet damage
// per hit, the floor (folio 20)
inline int mytIthaquaDamageMin()
    { return 2; }

// the buffet ceiling, 2-16 per hit (folio 20)
inline int mytIthaquaDamageMax()
    { return 16; }

// Ithaqua takes 2 hit points extra per die of magical fire damage (folio 20)
inline int mytIthaquaFireExtraPerDie()
    { return 2; }

// Yig's split armor class - 3 for the head (folio 20)
inline int mytYigHeadAc()
    { return 3; }

// Yig's split armor class - 5 for the chest and underbelly (folio 20)
inline int mytYigBodyAc()
    { return 5; }

// Yig surprises opponents on a six-sided die roll of 1-4, the floor (folio
// 20)
inline int mytYigSurpriseMin()
    { return 1; }

// the Yig surprise ceiling, 1-4 (folio 20)
inline int mytYigSurpriseMax()
    { return 4; }

// Yig controls all serpents within a one-square-mile radius of himself (folio
// 20)
inline int mytYigControlRadiusMiles()
    { return 1; }

// near his lair Yig is attended by 2-20 giant venomous snakes, the floor
// (folio 20)
inline int mytYigSnakesMin()
    { return 2; }

// the attendant-snake ceiling, 2-20 (folio 20)
inline int mytYigSnakesMax()
    { return 20; }

// the attendant giant snakes are 4-6 hit die, the floor (folio 20)
inline int mytYigSnakeHDMin()
    { return 4; }

// the attendant-snake hit-die ceiling, 4-6 (folio 20)
inline int mytYigSnakeHDMax()
    { return 6; }

// Yig strikes for 2-11 hit points of fang damage, the floor (folio 20)
inline int mytYigFangDamageMin()
    { return 2; }

// the fang ceiling, 2-11 (folio 20)
inline int mytYigFangDamageMax()
    { return 11; }

// the Yig poison save rolls at -3 to the die roll, failure dying immediately
// (folio 20)
inline int mytYigPoisonSavePenalty()
    { return 3; }

// Yog Sothoth gates one spawn, subject race or D&D demon in or out per melee
// round (folio 20)
inline int mytYogGatesPerMelee()
    { return 1; }

// the Byakhee talons do 2-12 points of damage, the floor (folio 21)
inline int mytByakheeTalonDamageMin()
    { return 2; }

// the talon ceiling, 2-12 (folio 21)
inline int mytByakheeTalonDamageMax()
    { return 12; }

// the Byakhee beak does 2-9 points of damage, the floor (folio 21)
inline int mytByakheeBeakDamageMin()
    { return 2; }

// the beak ceiling, 2-9 (folio 21)
inline int mytByakheeBeakDamageMax()
    { return 9; }

// the Deep Ones appear in numbers of 1-100, the floor (folio 21)
inline int mytDeepOnesMin()
    { return 1; }

// the Deep One appearance ceiling, 1-100 (folio 21)
inline int mytDeepOnesMax()
    { return 100; }

// every large Deep One group has at least one evil cleric of level 3-10, the
// floor (folio 21)
inline int mytDeepOnesClericMin()
    { return 3; }

// the Deep One cleric ceiling, level 3-10 (folio 21)
inline int mytDeepOnesClericMax()
    { return 10; }

// the Mi-Go move 15 and fly 30 (folio 21)
inline int mytMiGoFlyInches()
    { return 30; }

// the Elder Sign grey stone stars are armor class minus 2, broken only by
// magic or incredible force (folio 20)
inline int mytElderSignAc()
    { return -2; }

// characters below level 5 reading the Necronomicon run a 25 percent chance
// of chaotic-evil alignment change or madness, DM-adjusted (folio 20)
inline int mytNecronomiconMadnessPercent()
    { return 25; }

// the Necronomicon madness roll applies below level 5 (folio 20)
inline int mytNecronomiconLevelCutoff()
    { return 5; }

// Azathoth is mindless and totally resistant to mental attack (folio 18)
inline bool mytAzathothMindless()
    { return true; }

// Cthulhu is totally resistant to water, cold and vacuum (folio 18)
inline bool mytCthulhuResistantWaterColdVacuum()
    { return true; }

// Cthulhu retreats when confronted with the intact Elder Sign, another Old
// One or natural catastrophe (folio 18)
inline bool mytCthulhuRetreatsAtElderSign()
    { return true; }

// Hastur is immune to cold and vacuum (folio 18)
inline bool mytHasturImmuneColdVacuum()
    { return true; }

// anyone encountering Hastur must save against fear (folio 18)
inline bool mytHasturFearSaveRequired()
    { return true; }

// the Nyarlathotep charm save, once made, never needs checking again (folio
// 18)
inline bool mytNyarlathotepCharmOneSaveOnly()
    { return true; }

// Shub-Niggurath's spawned monsters ignore strangers but attack on her
// command (folio 18)
inline bool mytShubMonstersAttackOnCommand()
    { return true; }

// only +3 or better weapons damage Cthuga, lesser magical weapons forcing
// saves against disintegration (folio 20)
inline bool mytCthugaPlusThreeWeaponsOnly()
    { return true; }

// metal non-magical weapons melt upon touching Cthuga (folio 20)
inline bool mytCthugaMetalMelts()
    { return true; }

// Ithaqua may wind walk as the spell anytime he wishes (folio 20)
inline bool mytIthaquaWindWalkAtWill()
    { return true; }

// the Ithaqua air elemental goes beyond controlling range with no
// concentration required (folio 20)
inline bool mytIthaquaAirElementalRoamsFree()
    { return true; }

// Yig moves silently, detects enemies and tracks as a ranger, all at 100
// percent efficiency (folio 20)
inline bool mytYigRangerSenses()
    { return true; }

// all those failing the Yig poison save die immediately (folio 20)
inline bool mytYigPoisonSaveFailsDies()
    { return true; }

// Yog Sothoth is not subject to the laws of space and time, appearing at
// various parts of the universe simultaneously (folio 20)
inline bool mytYogNotSubjectToSpaceTime()
    { return true; }

// the Byakhee and those they carry are protected from cold and vacuum (folio
// 21)
inline bool mytByakheeProtectedColdVacuum()
    { return true; }

// the Byakhee obey those who carry the Elder Sign or appeal successfully to
// Hastur (folio 21)
inline bool mytByakheeElderSignObeys()
    { return true; }

// the Deep Ones are amphibious, growing more icthytic with age (folio 21)
inline bool mytDeepOnesAmphibious()
    { return true; }

// the Great Race projects minds across time and space, seizing control of any
// intelligent creature's body (folio 21)
inline bool mytGreatRaceMindSwap()
    { return true; }

// unlike the servants of the Old Ones, the Great Race is lawful and neutral
// (folio 21)
inline bool mytGreatRaceLawfulNeutral()
    { return true; }

// the Mi-Go are immune to cold, dark and vacuum, flying interstellar space
// (folio 21)
inline bool mytMiGoImmuneColdVacuum()
    { return true; }

// the Elder Sign acts on the evil minions of the Old Ones as a powerful charm
// spell, as a crucifix on a vampire (folio 20)
inline bool mytElderSignCharmVsMinions()
    { return true; }

// the Elder Sign is less strong against the Great Old Ones themselves (folio
// 20)
inline bool mytElderSignWeakerVsGOO()
    { return true; }

// the armor class - Azathoth minus 2, the rest 2 except Shub-Niggurath 4; the
// Yig cell prints the 3/5 head-and-body split (pinned as consts) and rides
// the sentinel (folios 18-20)
inline int mytGOOAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return -1;
        case 8:
            return 2;
        default:
            return -1;
        }
    }

// the move in inches - Azathoth prints infinite, Cthulhu, Hastur and
// Nyarlathotep 12, Shub-Niggurath 6, Cthuga 12, Ithaqua 12 plus special, Yig
// 18, Yog Sothoth 24; the Azathoth cell rides the sentinel (folios 18-20)
inline int mytGOOMove(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 6;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 18;
        case 8:
            return 24;
        default:
            return -1;
        }
    }

// the hit points - Azathoth 300, Cthulhu and Hastur 200, Nyarlathotep 150,
// Shub-Niggurath and Yog Sothoth 300, Cthuga and Ithaqua 175, Yig 125 (folios
// 18-20)
inline int mytGOOHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 200;
        case 2:
            return 200;
        case 3:
            return 150;
        case 4:
            return 300;
        case 5:
            return 175;
        case 6:
            return 175;
        case 7:
            return 125;
        case 8:
            return 300;
        default:
            return -1;
        }
    }

// the fighter level - Azathoth and Hastur 20th, Cthulhu and Yig 15th,
// Nyarlathotep 15th, Cthuga 17th, Ithaqua 16th, Yog Sothoth 20th; the
// Shub-Niggurath cell prints see below and rides the sentinel (folios 18-20)
inline int mytGOOFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return 17;
        case 6:
            return 16;
        case 7:
            return 15;
        case 8:
            return 20;
        default:
            return -1;
        }
    }

// the magic-user level - Nyarlathotep and Yog Sothoth 15th, Azathoth none as
// zero; the Cthulhu, Hastur, Shub-Niggurath, Cthuga, Ithaqua and Yig cells
// print see below and ride the sentinel (folios 18-20)
inline int mytGOOMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 15;
        default:
            return -1;
        }
    }

// the psionic class - Cthulhu and Yog Sothoth Class 1, Nyarlathotep and
// Shub-Niggurath Class 2, Cthuga, Ithaqua and Yig Class 6; the Azathoth and
// Hastur cells print resistant-to-all-psionic text and ride the sentinel
// (folios 18-20)
inline int mytGOOPsiClass(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 1;
        case 2:
            return -1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 1;
        default:
            return -1;
        }
    }

// the armor class - the Byakhee and Great Race 5, the Deep Ones and Mi-Go 3,
// the Old Ones 5, the Shaggoths 4 (folio 21)
inline int mytRaceAc(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 4;
        default:
            return -1;
        }
    }

// the move in inches - the Byakhee 36, the Deep Ones 12 with the 36 in-water
// rate, the Great Race and Old Ones 12, the Mi-Go 15 flying 30, the Shaggoths
// 18 (folio 21)
inline int mytRaceMove(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 18;
        default:
            return -1;
        }
    }

// the hit points - the Byakhee 100, the Deep Ones 10, the Great Race 30, the
// Old Ones 50, the Mi-Go 35, the Shaggoths 70 (folio 21)
inline int mytRaceHp(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 10;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 35;
        case 5:
            return 70;
        default:
            return -1;
        }
    }

// the fighter level - the Byakhee 10th, the Deep Ones 3rd, the Great Race
// 6th, the Old Ones 8th, the Mi-Go 8th, the Shaggoths 8th (folio 21)
inline int mytRaceFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 8;
        default:
            return -1;
        }
    }

// the magic-user level - the Deep Ones, Great Race, Old Ones and Shaggoths
// print none or no magical powers, pinned as zero; the Byakhee and Mi-Go
// cells print see below and ride the sentinel (folio 21)
inline int mytRaceMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return -1;
        case 5:
            return 0;
        default:
            return -1;
        }
    }

// the psionic class - the Byakhee Class 5, the Great Race Class 1, the Mi-Go
// Class 5, the Deep Ones and Old Ones none as zero; the Shaggoth cell prints
// resistant-to-psionic text and rides the sentinel (folio 21)
inline int mytRacePsiClass(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return -1;
        default:
            return -1;
        }
    }

}   // namespace rules
