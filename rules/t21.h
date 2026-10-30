// =========================================================================================
// Adnd1 - rules/t21.h
// The Dragon issue-21 opener part one - the twenty-NPC personality grid, the
// spell-research doctrine and the foretelling-spell counters
// census 865 -> 866.
//
// The opener of the issue-21 three-round shape - three of the seven
// Curtiss-called chains pinned, the economics, monster blues, Hall of Mystery
// and title kit riding the part-two round. All pinned from The Dragon Vol.
// III No. 6 (December 1978), the Curtiss-provided Dm21.pdf scan voice, print
// folio the PDF page minus two.
//
// The issue-21 print catches pinned as scanned: the contents masthead prints
// Vol. 111 No. 6 for Vol. III and November 1978 for December, the cover also
// prints No. 6, the Suliin article prints Paul Suliin and Ventriliquism, the
// Rollo prose statline prints seven stat numbers, and the Medivar spelling
// rides the Prophet Proofing deterrents. Both inherited watches - the Sullin
// levels 7-9 and the brawling sequel - print nowhere in TD21 and ride to TD
// 22.
//
namespace rules {

// ---- the twenty-NPC personality grid (print 11 + 23 + 27) ----

// the NPC statline count - Blarg through Dassol, twenty personality
// encounters across three print pages the twenty-NPC personality grid (print
// 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcCount()
    { return 20; }

// the first-print-page count - nine NPCs on print 11, ten on print 23, the
// last two on print 27 the twenty-NPC personality grid (print 11 + 23 + 27,
// PDF 13 + 25 + 29)
inline int t21NpcFirstPage()
    { return 9; }

// the mid-print-page count - the ten NPCs Grunt through Pontance on print 23,
// sharing the page with the Judges Guild ad the twenty-NPC personality grid
// (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcMidPage()
    { return 10; }

// the Gantol dual-class level - the 17th-level magic user turned first-level
// fighter, the highest level in the kit the twenty-NPC personality grid
// (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcLevelSeventeen()
    { return 17; }

// the Rollo the Rotund level - the 9th-level magic user owner of Zilch, his
// statline printed in the prose the twenty-NPC personality grid (print 11 +
// 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcRolloLevel()
    { return 9; }

// the Rollo hit points - 24, printed in the prose as 24Htk the twenty-NPC
// personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcRolloHp()
    { return 24; }

// the Rollo armor class - 9, printed in the prose the twenty-NPC personality
// grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcRolloAc()
    { return 9; }

// the Clar werebear height - 12 feet tall in bear form, the claws 1-3 and
// bite 2-8 with the 2-16 hug on an 18 or better the twenty-NPC personality
// grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcClarHeight()
    { return 12; }

// the Rollo print catch - his prose statline prints SEVEN stat numbers 9 17 1
// 1 10 7 17, one more than the six-stat grid the twenty-NPC personality grid
// (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcRolloStatlineSeven()
    { return 7; }

// the Dassol buffoon magnet - 3-18 person crowds while his two 8th-level elf
// thief confederates pick pockets at 70 percent, with the pyrotechnics
// smokescreen escape the twenty-NPC personality grid (print 11 + 23 + 27, PDF
// 13 + 25 + 29)
inline bool t21NpcDassolConfederates()
    { return true; }

// the Gleen pick-everyone doctrine - he picks every pocket in a crowd so
// succeeds only 5 percent, but climbs at 0 percent fall, moves silently at 80
// and hides at 85 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13
// + 25 + 29)
inline bool t21NpcGleenSocks()
    { return true; }

// the Grunt doctrine - no one will sell him weapons, sellers face 4-40 months
// hard labor or a 100-1000 gold fine or both the twenty-NPC personality grid
// (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline bool t21NpcGruntArmsBan()
    { return true; }

// the Zilch-Rollo doctrine - the zombie runs embarrassing errands for the
// 9th-level joker MU and runs away if seriously threatened the twenty-NPC
// personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline bool t21NpcZilchRollo()
    { return true; }

// the Pontance phantasmal-forces cloak - she appears an old woman, the saving
// throw versus magic at minus 4, her true charisma 14 disguised as 9 the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline bool t21NpcPontanceDisguise()
    { return true; }

// the Klund roar - clears the street 60 feet in all directions, the giant
// club swung as a flail to subdue, losers tossed onto roofs for 2-8 the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline bool t21NpcKlundRoar()
    { return true; }

// the level column - the Blarg 3rd through the Gantol 17th, the zombie and
// mummy NPCs pinned at their monster-equivalent fighter levels as printed the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcLevel(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 17;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 9;
        default:
            return -99;
        }
    }

// the hit point column - the Grunt 2 print catch floor through the Tarky 69
// ceiling the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 +
// 29)
inline int t21NpcHp(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 23;
        case 2:
            return 64;
        case 3:
            return 36;
        case 4:
            return 45;
        case 5:
            return 69;
        case 6:
            return 51;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 2;
        case 10:
            return 8;
        case 11:
            return 4;
        case 12:
            return 20;
        case 13:
            return 9;
        case 14:
            return 27;
        case 15:
            return 28;
        case 16:
            return 51;
        case 17:
            return 11;
        case 18:
            return 33;
        case 19:
            return 30;
        default:
            return -99;
        }
    }

// the armor class column - the Gantol -2 through the multiple 9s, the Clar 2
// with the apparent-9 when-human footnote the twenty-NPC personality grid
// (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcAc(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return -2;
        case 3:
            return 7;
        case 4:
            return 2;
        case 5:
            return 7;
        case 6:
            return 9;
        case 7:
            return 7;
        case 8:
            return 9;
        case 9:
            return 2;
        case 10:
            return 8;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 9;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 7;
        case 17:
            return 9;
        case 18:
            return 6;
        case 19:
            return 9;
        default:
            return -99;
        }
    }

// the strength column - the Grunt 4 floor through the 18 band the twenty-NPC
// personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcStr(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 15;
        case 2:
            return 8;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 8;
        case 7:
            return 17;
        case 8:
            return 18;
        case 9:
            return 4;
        case 10:
            return 16;
        case 11:
            return 5;
        case 12:
            return 10;
        case 13:
            return 14;
        case 14:
            return 13;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 8;
        case 18:
            return 15;
        case 19:
            return 8;
        default:
            return -99;
        }
    }

// the intelligence column - the Lontipol 6 floor through the Gantol 17 the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcInt(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 9;
        case 2:
            return 17;
        case 3:
            return 12;
        case 4:
            return 16;
        case 5:
            return 10;
        case 6:
            return 6;
        case 7:
            return 9;
        case 8:
            return 12;
        case 9:
            return 9;
        case 10:
            return 8;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 7;
        case 14:
            return 9;
        case 15:
            return 11;
        case 16:
            return 7;
        case 17:
            return 15;
        case 18:
            return 9;
        case 19:
            return 10;
        default:
            return -99;
        }
    }

// the wisdom column - the Lontipol 19 peak with the Str 8 floor the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcWis(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 14;
        case 5:
            return 8;
        case 6:
            return 19;
        case 7:
            return 10;
        case 8:
            return 8;
        case 9:
            return 11;
        case 10:
            return 4;
        case 11:
            return 14;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 4;
        case 15:
            return 10;
        case 16:
            return 6;
        case 17:
            return 16;
        case 18:
            return 7;
        case 19:
            return 14;
        default:
            return -99;
        }
    }

// the constitution column - the Gleen 7 floor through the Klund 18 the
// twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcCon(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 11;
        case 3:
            return 13;
        case 4:
            return 18;
        case 5:
            return 16;
        case 6:
            return 7;
        case 7:
            return 9;
        case 8:
            return 16;
        case 9:
            return 3;
        case 10:
            return 14;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 10;
        case 15:
            return 14;
        case 16:
            return 18;
        case 17:
            return 6;
        case 18:
            return 13;
        case 19:
            return 8;
        default:
            return -99;
        }
    }

// the dexterity column - the Snir 4 floor through the Iradain 19 archer peak
// the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcDex(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 9;
        case 2:
            return 13;
        case 3:
            return 19;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 10;
        case 11:
            return 16;
        case 12:
            return 10;
        case 13:
            return 8;
        case 14:
            return 10;
        case 15:
            return 9;
        case 16:
            return 10;
        case 17:
            return 13;
        case 18:
            return 10;
        case 19:
            return 14;
        default:
            return -99;
        }
    }

// the charisma column - the Snir 4 floor through the Gleen 18, the Pontance
// 14 with the disguise-9 footnote the twenty-NPC personality grid (print 11 +
// 23 + 27, PDF 13 + 25 + 29)
inline int t21NpcCha(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 11;
        case 5:
            return 14;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 5;
        case 9:
            return 15;
        case 10:
            return 10;
        case 11:
            return 18;
        case 12:
            return 7;
        case 13:
            return 4;
        case 14:
            return 6;
        case 15:
            return 9;
        case 16:
            return 6;
        case 17:
            return 14;
        case 18:
            return 12;
        case 19:
            return 6;
        default:
            return -99;
        }
    }

// the to-hit column - the Grunt -2 through the Clar and Klund +4, the printed
// Ave. pinned 0 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 +
// 25 + 29)
inline int t21NpcToHit(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return -2;
        case 10:
            return 1;
        case 11:
            return -1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        default:
            return -99;
        }
    }

// the to-damage column - the Grunt -1 through the Clar and Klund +6, the
// printed Ave. pinned 0 the twenty-NPC personality grid (print 11 + 23 + 27,
// PDF 13 + 25 + 29)
inline int t21NpcToDmg(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return -1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return -99;
        }
    }

// ---- the spell-research doctrine (print 10) ----

// the Rules of Research count - Rule One no outdoing existing spells, Rule
// Two no cross-profession spells, Rule Three no spell of an unlearnable level
// the spell-research doctrine (print 10, PDF 12)
inline int t21ResearchRules()
    { return 3; }

// the Moon Runes adjudication - too cheap at first level and not worth having
// at third with Explosive Rune there, so second level is the fit the
// spell-research doctrine (print 10, PDF 12)
inline int t21MoonRunesLevel()
    { return 2; }

// the Magic Missile II level - the obvious second-level equivalent,
// researched elsewhere as Magic Javelin the spell-research doctrine (print
// 10, PDF 12)
inline int t21MagicMissileTwoLevel()
    { return 2; }

// the Wall of Water block ceiling - blocks creatures under 5 hit dice the
// spell-research doctrine (print 10, PDF 12)
inline int t21WallWaterBlockHd()
    { return 5; }

// the Wall of Water fiery damage - 6 dice against fiery creatures the
// spell-research doctrine (print 10, PDF 12)
inline int t21WallWaterFireDice()
    { return 6; }

// the Wall of Fire block ceiling - the existing fourth-level wall blocks
// creatures under 4 hit dice the spell-research doctrine (print 10, PDF 12)
inline int t21WallFireBlockHd()
    { return 4; }

// the Wall of Ice fiery damage - only 1 die against fiery creatures the
// spell-research doctrine (print 10, PDF 12)
inline int t21WallIceFireDice()
    { return 1; }

// the Shatterray damage floor - 5 of the 5-30 band, on top of the aiming and
// level-scaling extras the spell-research doctrine (print 10, PDF 12)
inline int t21ShatterrayMin()
    { return 5; }

// the Shatterray damage ceiling - 30 of the 5-30 band the spell-research
// doctrine (print 10, PDF 12)
inline int t21ShatterrayMax()
    { return 30; }

// the Ice Storm damage floor - the Greyhawk fourth-level benchmark at 3-30
// the spell-research doctrine (print 10, PDF 12)
inline int t21IceStormMin()
    { return 3; }

// the Ice Storm damage ceiling - 30 of the 3-30 band, with none of the
// Shatterray advantages the spell-research doctrine (print 10, PDF 12)
inline int t21IceStormMax()
    { return 30; }

// the specialist exception - a Fire-Mage may get Firebolts or Firebeams doing
// equivalent to Fireballs at second level the spell-research doctrine (print
// 10, PDF 12)
inline int t21FireMageBoltsLevel()
    { return 2; }

// Rule One of Research - no researched spell may cause more damage, gain more
// information, summon more powerful beings, or give more control than an
// existing spell of the same or lower level the spell-research doctrine
// (print 10, PDF 12)
inline bool t21RuleOne()
    { return true; }

// Rule Two of Research - a character cannot learn a spell that is the
// province of another profession, the dividing line between magic-user and
// cleric the spell-research doctrine (print 10, PDF 12)
inline bool t21RuleTwo()
    { return true; }

// Rule Three of Research - a character cannot research a spell of a level he
// cannot yet learn the spell-research doctrine (print 10, PDF 12)
inline bool t21RuleThree()
    { return true; }

// the Rule One exception - a researcher of a more suited profession may
// exceed, the Fire-Mage precedent the spell-research doctrine (print 10, PDF
// 12)
inline bool t21SpecialistException()
    { return true; }

// the vending-machine warning - gold in and anything out is the too-common
// shape, the research neither fixes the level, the fit, nor the capability
// the spell-research doctrine (print 10, PDF 12)
inline bool t21VendingMachineWarning()
    { return true; }

// the cleric line - clerics do not manipulate natural or supernatural forces
// to attack: Web, Magic Missile, Fireball the spell-research doctrine (print
// 10, PDF 12)
inline bool t21ClericNoAttackMagic()
    { return true; }

// the magic-user line - no divine guidance or intervention: Detect Traps,
// Speak With Dead, Resurrection the spell-research doctrine (print 10, PDF
// 12)
inline bool t21MuNoDivineAid()
    { return true; }

// the Wall of Water print critique - it demands no concentration while the
// existing walls do, part of the too-much case the spell-research doctrine
// (print 10, PDF 12)
inline bool t21WallWaterNoConcentration()
    { return true; }

// the Suliin spelling print catch - the article prints Paul Suliin and Suliin
// throughout for the Suliin article it critiques, and Ventriliquism for
// Ventriloquism, pinned as scanned the spell-research doctrine (print 10, PDF
// 12)
inline bool t21SuliinSpellingPrintCatch()
    { return true; }

// ---- the foretelling-spell counters (print 9) ----

// the foretelling spell count - Clairvoyance, Clairaudience, Wizard Eye, ESP
// and X-ray vision, the five DM-patience testers the foretelling-spell
// counters (print 9, PDF 11)
inline int t21ForetellingSpells()
    { return 5; }

// the insanity contagion floor - a sane person reading a madman becomes
// insane in the same manner for 2-7 turns the foretelling-spell counters
// (print 9, PDF 11)
inline int t21InsanityContagionMin()
    { return 2; }

// the insanity contagion ceiling - 7 of the 2-7 turn band the
// foretelling-spell counters (print 9, PDF 11)
inline int t21InsanityContagionMax()
    { return 7; }

// the non-directional option - Clairvoyance, Clairaudience and ESP declared
// to return the sights, sounds or thoughts of all beings within 60 feet the
// foretelling-spell counters (print 9, PDF 11)
inline int t21NonDirectionalFeet()
    { return 60; }

// the lead-wall doctrine - three inches of lead sandwiched in the lower-level
// walls, ceilings and floors the foretelling-spell counters (print 9, PDF 11)
inline int t21LeadInches()
    { return 3; }

// the voyeur Wizard Eye flaw - 33 percent of the time it ignores its owner
// and hunts mating monsters or pornographic wall paintings the
// foretelling-spell counters (print 9, PDF 11)
inline int t21VoyeurPct()
    { return 33; }

// the Wizard Eye medallion - projects the spell three times per day the
// foretelling-spell counters (print 9, PDF 11)
inline int t21WizardEyeUsesPerDay()
    { return 3; }

// the Helm of Telepathy trick - the KOBOLD-thinking MU behind the door
// charged with a fifteen hit-die fireball the foretelling-spell counters
// (print 9, PDF 11)
inline int t21HelmFireballDice()
    { return 15; }

// the insanity cross-reference - Kevin Thompson fine article in TD 18
// provides the ESP-counter key the foretelling-spell counters (print 9, PDF
// 11)
inline int t21InsanityArticleIssue()
    { return 18; }

// the Medivar deterrent - a few strategically placed ones discourage
// Clairvoyance, Wizard Eyes and X-ray vision; the print catch rides the
// Medivar spelling, pinned as scanned the foretelling-spell counters (print
// 9, PDF 11)
inline bool t21MedivarDeterrent()
    { return true; }

// the harpy deterrent - just as effective against Clairaudience the
// foretelling-spell counters (print 9, PDF 11)
inline bool t21HarpyDeterrent()
    { return true; }

// the sanity contagion - reading a madman mind or scrying him madly makes the
// reader insane in the same manner, applied to ESP, Clairvoyance and
// Clairaudience users the foretelling-spell counters (print 9, PDF 11)
inline bool t21SanityContagionDoctrine()
    { return true; }

// the Wizard Eye restriction option - unable to penetrate liquids and solids,
// fine for corners and useless for closed rooms the foretelling-spell
// counters (print 9, PDF 11)
inline bool t21WizardEyeNoLiquidsSolids()
    { return true; }

// the X-ray built-in limitation - it cannot penetrate lead the
// foretelling-spell counters (print 9, PDF 11)
inline bool t21XrayLeadBuiltIn()
    { return true; }

// the paranoid NPC doctrine - high-level non-players possess Amulets versus
// ESP and other foretelling protection the foretelling-spell counters (print
// 9, PDF 11)
inline bool t21ParanoidNpcProtection()
    { return true; }

// the Helm of Telepathy dirty trick - the MU thinks KOBOLD into the Helm so
// the charging party eats the fifteen-die fireball the foretelling-spell
// counters (print 9, PDF 11)
inline bool t21HelmKoboldTrick()
    { return true; }

// the medallion economy - the magic-user rented the voyeur Eye to wealthy
// townsmen who loved its blue movies, and made a mint the foretelling-spell
// counters (print 9, PDF 11)
inline bool t21MedallionBlueMovies()
    { return true; }

}   // namespace rules
