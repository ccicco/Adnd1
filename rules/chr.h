// =========================================================================================
// Adnd1 - rules/chr.h
// The character round - Smith's new-view Dwarves (folios 26-27), Stock and
// Lane's birth tables (folios 14-16) and the Pulsipher Eldar deltas (folios
// 20-21)
// census 820 -> 821.
//
// Pinned from The Dragon Vol. 1 No. 3 (October 1976): folios 26-27, Larry
// Smith's A New View of Dwarves - the nine-level Fighting Man ladder with the
// dice-plus forms split to base and bonus, the kingship of the seven families
// with Durin on the 7-8 of a d8, the Greyhawk cleric and thief options with
// their swapped dice, the fourteen abilities, the reaction modifiers with the
// Goblins-and-Orcs auto attack, and the folk wisdom; folios 14-16, Brad Stock
// and Brian Lane's Birth Tables for D&D - the ten-table character generation
// system from social class through sibling rank, social rank wealth, the
// three skills groups, the nobility rolls with the royalty rules, the
// adventurer fathers, the race rolls with the dice grid and requirement
// bands, and the previous-experience multipliers; folios 20-21, Lewis
// Pulsipher's letter - the Silvan, Sindar and Eldar-proper system with the
// True Sight powers and the over-sea doctrine, as deltas against the R888
// Smith Eldar pin. The editors ran the Smith rebuttal beside the letter; both
// systems stand, the deltas noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// '00' percentile convention CONVERTS to 100 throughout the birth tables and
// the 'nil' bands pin as 0, every conversion noted, never silent; the race
// requirement grid's printed 'any' CONVERTS to the 3-18 range; the ladder's
// dice-plus forms split to base and bonus; the auto-attack reaction row pins
// AS SCANNED as the sentinel 9; the OCR's split Very-Wealthy rows and column
// shifts in the social-rank tables, the garbled ladder footnote, the royalty
// table's interleaved wealth labels and the sibling note 'No one receives
// Allowance' ride AS SCANNED, unpinned or noted, no figure pixels to check;
// the crafts list pins as a count with the names in the audit comment; the
// Pulsipher system rides as DELTAS against the R888 Smith pin, both authored
// systems standing side by side on the variant layer, never a rewrite.
//
namespace rules {

// ---- the new-view Dwarves (folios 26-27) ----

// the chrDwarfLadder table runs 9 rows (folio 26)
inline int chrDwarfLadderLevels()
    { return 9; }

// 17-plus Strength is needed for 7th level, pinned as 17 (folio 26)
inline int chrDwfStrFor7th()
    { return 17; }

// 18 Strength is needed for 8th level (folio 26)
inline int chrDwfStrFor8th()
    { return 18; }

// the ladder footnote's 12-plus Intelligence requirement, pinned as 12 - the
// OCR line garbles across the table edge, pinned as scanned (folio 26)
inline int chrDwfKingIntMin()
    { return 12; }

// the ladder footnote's 12-plus Wisdom requirement, pinned as 12 - the OCR
// line garbles across the table edge, pinned as scanned (folio 26)
inline int chrDwfKingWisMin()
    { return 12; }

// there are only 7 families of Dwarves, so only 7 Dwarf Kings (folio 26)
inline int chrDwarfFamilies()
    { return 7; }

// tribe and line are decided on an eight-sided die (folio 26)
inline int chrDwarfTribeDieSides()
    { return 8; }

// rolls of 7 and 8 are the tribe of Durin - the minimum (folio 26)
inline int chrDwarfTribeDurinLo()
    { return 7; }

// a Wisdom of 15 or better lets a Dwarf opt to be a cleric (folio 26)
inline int chrDwarfClericWisMin()
    { return 15; }

// a 17 Wisdom allows the Dwarf cleric to reach 7th level (folio 26)
inline int chrDwarfCleric7thWis()
    { return 17; }

// an 18 Wisdom allows the Dwarf cleric to reach 8th level (folio 26)
inline int chrDwarfCleric8thWis()
    { return 18; }

// Dwarf clerics roll an eight-sided die for points (folio 26)
inline int chrDwarfClericHitDie()
    { return 8; }

// Dwarf thieves roll a six-sided die for points (folio 26)
inline int chrDwarfThiefHitDie()
    { return 6; }

// high magic resistance - Dwarves add 4 levels when rolling their saving
// throws (folio 26)
inline int chrDwarfSaveBonusLevels()
    { return 4; }

// Dwarves may fully employ the +3 War Hammer (folio 26)
inline int chrDwarfWarHammerBonus()
    { return 3; }

// the slant-passage detection roll is on a six-sided die (folio 26)
inline int chrDwarfSlantDieSides()
    { return 6; }

// Dwarves note slanting passages, traps, shifting walls and rooms on a die
// roll of 1-4 (folio 26)
inline int chrDwarfSlantRollMax()
    { return 4; }

// fighting the Giant Class, Dwarves add +1 to hit probabilities (folio 26)
inline int chrDwarfGiantClassHitMod()
    { return 1; }

// fighting the Giant Class, Dwarves subtract 1 from chances to be hit -
// pinned as an armor-class bonus of 1, the printed double-negative noted
// (folio 26)
inline int chrDwarfGiantClassAcMod()
    { return 1; }

// Smiths work requires an Intelligence of 9 or better (folio 26)
inline int chrDwarfSmithIntMin()
    { return 9; }

// Smiths work requires a Strength of 9 or better (folio 26)
inline int chrDwarfSmithStrMin()
    { return 9; }

// Armorers work requires an Intelligence of 12 or better (folio 26)
inline int chrDwarfArmorerIntMin()
    { return 12; }

// Armorers work requires a Strength of 9 or better (folio 26)
inline int chrDwarfArmorerStrMin()
    { return 9; }

// Engineers work requires an Intelligence of 15 or better (folio 26)
inline int chrDwarfEngineerIntMin()
    { return 15; }

// all other weapons are used at minus 1 to hit - pinned as 1, the sign
// carried in the comment (folio 26)
inline int chrDwarfOtherWeaponHitMod()
    { return 1; }

// Dwarves with a Dexterity of 17 or greater can swim naturally; all others
// must learn (folio 26)
inline int chrDwarfSwimDexMin()
    { return 17; }

// only Dwarves with an Intelligence of 12 or better will even consider
// getting on a horse - and only then at great need, the folio-27 continuation
// of the folio-26 sentence (folios 26-27)
inline int chrDwarfHorseIntMin()
    { return 12; }

// Dwarves reach maturity around the age of 50 (folio 27)
inline int chrDwarfMaturityAge()
    { return 50; }

// Dwarves live to be about 250 years old (folio 27)
inline int chrDwarfLifespanYears()
    { return 250; }

// the chrDwarfReactions table runs 6 rows (folio 27)
inline int chrDwarfReactionCount()
    { return 6; }

// the Kingship of each line is open - the first dwarf to obtain it becomes
// that tribe's King and holds it until death (folio 26)
inline bool chrDwarfKingshipFirst()
    { return true; }

// when a Dwarf King is made for a tribe, no other dwarf of that tribe may
// become 9th level until he dies (folio 26)
inline bool chrDwarfKingBlocksLevel()
    { return true; }

// since according to Greyhawk there can be Dwarf clerics, players should be
// allowed the option - with all the benefits and restrictions of both cleric
// and dwarf (folio 26)
inline bool chrDwarfClericsAllowed()
    { return true; }

// Dwarf thieves are as listed in Greyhawk with the exception of the hit dice
// (folio 26)
inline bool chrDwarfThievesGreyhawk()
    { return true; }

// Dwarves may not be Magicians, Assassins, Monks, Paladins, Illusionists,
// Rangers or Sages (folio 26)
inline bool chrDwarfForbiddenClasses()
    { return true; }

// noting new construction is done automatically (folio 26)
inline bool chrDwarfNewConstructionAuto()
    { return true; }

// Dwarves are able to understand the languages of Goblins, Orcs and
// Hobgoblins (folio 26)
inline bool chrDwarfUnderstandsGobOrcHob()
    { return true; }

// Dwarves can speak Gnome and Kobold - the OCR's 'Kolbold' garble noted - in
// addition to their regular tongues (folio 26)
inline bool chrDwarfSpeaksGnomeKobold()
    { return true; }

// Dwarves may judge properly the full value of gems and jewels (folio 26)
inline bool chrDwarfJudgesGems()
    { return true; }

// Dwarves can feel, when handling armor or weapons, whether it is magical in
// nature (folio 26)
inline bool chrDwarfFeelsMagic()
    { return true; }

// crossbows and short bows are the Dwarves' only bow-type weapons (folio 26)
inline bool chrDwarfBowsOnly()
    { return true; }

// the regular weapons - Dagger, Hand Axe, Sword, Battle Axe, War Hammer and
// Spear (folio 26)
inline bool chrDwarfRegularWeapons()
    { return true; }

// Dwarves have a fear of traveling on water, so it will be very hard to
// convince them of the need to learn to swim (folio 26)
inline bool chrDwarfWaterFear()
    { return true; }

// Dwarves have a great hate for Orcs and Goblins and dislike Elves to a great
// extent - insulting Elves is a hobby, as is chopping the heads off Orcs and
// Goblins (folio 27)
inline bool chrDwarfHatesOrcsGoblins()
    { return true; }

// Dwarves have their own rough system of honor, and when an oath is given it
// is never broken (folio 27)
inline bool chrDwarfOathsNeverBroken()
    { return true; }

// Dwarves of the same Folk will never attack their own Folk (folio 27)
inline bool chrDwarfNeverAttackOwnFolk()
    { return true; }

// the level - 1 through 9 (folio 26)
inline int chrDwfLvlLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        default:
            return 9;
        }
    }

// the title code - 1 Dwarf, 2 Warrior, 3 Spearman, 4 Dwarf Hero, 5
// Swordbearer, 6 Axewielder, 7 Champion, 8 Dwarf Lord, 9 Dwarf King (folio
// 26)
inline int chrDwfLvlNameCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        default:
            return 9;
        }
    }

// the hit-dice base - 1 through 8, then 10 for the King, the printed
// dice-plus forms split to base and bonus (folio 26)
inline int chrDwfLvlHitBase(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 10;
        default:
            return 9;
        }
    }

// the hit-dice bonus - the +2 of the 1st-level Dwarf, +1 of the 2nd, then
// flat, then the Champion and Lord extras, +1 for the King (folio 26)
inline int chrDwfLvlHitBonus(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        default:
            return 9;
        }
    }

// the experience points - 0 through 320,000 (folio 26)
inline int chrDwfLvlXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2500;
        case 2:
            return 5000;
        case 3:
            return 10000;
        case 4:
            return 20000;
        case 5:
            return 40000;
        case 6:
            return 80000;
        case 7:
            return 160000;
        case 8:
            return 320000;
        default:
            return 9;
        }
    }

// the fights-as-a-man level - 1 through 10 (folio 26)
inline int chrDwfLvlFightsAs(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 10;
        default:
            return 9;
        }
    }

// the fights-as modifier - +2, +1, then flat Men, then +1, +2, +1 (folio 26)
inline int chrDwfLvlFightsAsBonus(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        default:
            return 9;
        }
    }

// the reaction row code - 1 Goblins and Orcs, 2 Sindar, Silvan Elves and all
// men, 3 all others except those listed, 4 Hobbits and Noldor Elves, 5
// Dwarves of different Folks, 6 Dwarves of the same Folk (folio 27)
inline int chrDwfReactCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the reaction die modifier - the auto-attack row pinned as the sentinel 9,
// the sign of the minus rows carried in this comment (folio 27)
inline int chrDwfReactMod(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        default:
            return 9;
        }
    }

// ---- the birth tables (folios 14-16) ----

// the skills divide into three groups, plus the crafts list (folio 15)
inline int chrBirthSkillsGroups()
    { return 3; }

// the allowance arrives each month for the first year (folio 15)
inline int chrBirthAllowanceMonths()
    { return 12; }

// the allowance runs until the player reaches 3rd level, whichever comes
// first (folio 15)
inline int chrBirthAllowanceLevelCap()
    { return 3; }

// the chrBirthClass table runs 4 rows (folio 14)
inline int chrBirthClassCount()
    { return 4; }

// the chrSiblingRank table runs 5 rows (folio 14)
inline int chrSiblingBandCount()
    { return 5; }

// the sibling rank roll is on an eight-sided die (folio 14)
inline int chrSiblingDieSides()
    { return 8; }

// the orphan check is on a six-sided die (folio 14)
inline int chrOrphanDieSides()
    { return 6; }

// a roll of 1 on the six-sided die orphans the player (folio 14)
inline int chrOrphanRoll()
    { return 1; }

// the 1st son receives 10 percent more Initial and Allowance (folio 14)
inline int chrBirthFirstSonPct()
    { return 10; }

// the bastard receives 10 percent less - pinned as 10, the 'less' carried in
// the comment (folio 14)
inline int chrBirthBastardPct()
    { return 10; }

// the chrRankCommoner table runs 4 rows (folio 15)
inline int chrRankCommonerCount()
    { return 4; }

// the chrRankMerchant table runs 5 rows (folio 15)
inline int chrRankMerchantCount()
    { return 5; }

// the chrRankGentleman table runs 5 rows (folio 15)
inline int chrRankGentlemanCount()
    { return 5; }

// the chrRankNoble table runs 6 rows (folio 15)
inline int chrRankNobleCount()
    { return 6; }

// the chrFatherOcc table runs 4 rows (folio 15)
inline int chrFatherOccCount()
    { return 4; }

// the chrSkillGroup1 table runs 10 rows (folio 15)
inline int chrSkillGroup1Count()
    { return 10; }

// Group 1 note - a Peasant may not roll above 70 (folio 15)
inline int chrSkillsPeasantMax()
    { return 70; }

// Group 1 note - a Well-to-do may not roll below 31 (folio 15)
inline int chrSkillsWellToDoMin()
    { return 31; }

// Group 1 note - a Wealthy may not roll below 52, with 52-55 equalling
// Adventurer (folio 15)
inline int chrSkillsWealthyMin()
    { return 52; }

// the chrSkillGroup2 table runs 10 rows (folio 15)
inline int chrSkillGroup2Count()
    { return 10; }

// the chrSkillGroup3 table runs 20 rows (folio 15)
inline int chrSkillGroup3Count()
    { return 20; }

// the Interpreter knows languages as if his intelligence were 3 higher (folio
// 15)
inline int chrSkillsInterpreterIntBonus()
    { return 3; }

// the Soldier receives +1 on hit probability until he reaches 4th level
// (folio 15)
inline int chrSkillsSoldierHitBonus()
    { return 1; }

// the Soldier's hit bonus runs until 4th level (folio 15)
inline int chrSkillsSoldierLevelCap()
    { return 4; }

// the Orator/Actor receives +1 when rolling random reactions of monsters
// (folio 15)
inline int chrSkillsOratorReactionBonus()
    { return 1; }

// the crafts list runs twelve trades - Tailor, Smith, Fletcher, Cobbler,
// Horseman, Weaver, Carpenter, Armorer, Bowyer, Mason, Cartographer, Jeweler,
// the names carried in the audit comment (folio 15)
inline int chrCraftsCount()
    { return 12; }

// the skills rolls are on the percentile dice, the numbers ignored when
// choosing a player's skills (folio 15)
inline int chrSkillsDieSides()
    { return 100; }

// the chrNobleTitle table runs 6 rows (folio 15)
inline int chrNobleTitleCount()
    { return 6; }

// the chrRoyaltyKin table runs 5 rows (folio 15)
inline int chrRoyaltyKinCount()
    { return 5; }

// the immediate royal family's initial gold - 1000 (folio 15)
inline int chrRoyaltyImmediateInitial()
    { return 1000; }

// the immediate royal family's allowance - 100 (folio 15)
inline int chrRoyaltyImmediateAllow()
    { return 100; }

// the chrPosKnight table runs 5 rows (folio 15)
inline int chrPosKnightCount()
    { return 5; }

// a Knight father has a 30 percent chance of being an Adventurer (folio 15)
inline int chrKnightAdventurerPct()
    { return 30; }

// the chrPosBaron table runs 6 rows (folio 15)
inline int chrPosBaronCount()
    { return 6; }

// a Baron father has a 25 percent chance of being an Adventurer (folio 15)
inline int chrBaronAdventurerPct()
    { return 25; }

// the chrPosCount table runs 6 rows (folio 15)
inline int chrPosCountCount()
    { return 6; }

// a Count father has a 20 percent chance of being an Adventurer (folio 15)
inline int chrCountAdventurerPct()
    { return 20; }

// the chrPosMarquis table runs 7 rows (folio 15)
inline int chrPosMarquisCount()
    { return 7; }

// a Marquis father has a 15 percent chance of being an Adventurer (folio 15)
inline int chrMarquisAdventurerPct()
    { return 15; }

// the chrPosDuke table runs 7 rows (folio 15)
inline int chrPosDukeCount()
    { return 7; }

// a Duke father has a 15 percent chance of being an Adventurer (folio 15)
inline int chrDukeAdventurerPct()
    { return 15; }

// the chrAdvComLevels table runs 4 rows (folio 16)
inline int chrAdvComLevelsCount()
    { return 4; }

// the chrAdvMerLevels table runs 6 rows (folio 16)
inline int chrAdvMerLevelsCount()
    { return 6; }

// the chrAdvGenLevels table runs 8 rows (folio 16)
inline int chrAdvGenLevelsCount()
    { return 8; }

// the chrAdvNobLevels table runs 9 rows (folio 16)
inline int chrAdvNobLevelsCount()
    { return 9; }

// the chrAdvComClass table runs 2 rows (folio 16)
inline int chrAdvComClassCount()
    { return 2; }

// the chrAdvMerClass table runs 4 rows (folio 16)
inline int chrAdvMerClassCount()
    { return 4; }

// the chrAdvGenClass table runs 4 rows (folio 16)
inline int chrAdvGenClassCount()
    { return 4; }

// the chrAdvNobClass table runs 4 rows (folio 16)
inline int chrAdvNobClassCount()
    { return 4; }

// the chrRaceCommoner table runs 5 rows (folio 16)
inline int chrRaceCommonerCount()
    { return 5; }

// the chrRaceMerchant table runs 4 rows (folio 16)
inline int chrRaceMerchantCount()
    { return 4; }

// the chrRaceGentleNoble table runs 5 rows (folio 16)
inline int chrRaceGentleNobleCount()
    { return 5; }

// the race rolls are on a twelve-sided die (folio 16)
inline int chrRaceTable1DieSides()
    { return 12; }

// the chrRaceDice table runs 6 rows (folio 16)
inline int chrRaceDiceCount()
    { return 6; }

// the chrRaceReq table runs 6 rows (folio 16)
inline int chrRaceReqCount()
    { return 6; }

// the chrPrevCom table runs 4 rows (folio 16)
inline int chrPrevComCount()
    { return 4; }

// the chrPrevMer table runs 5 rows (folio 16)
inline int chrPrevMerCount()
    { return 5; }

// the chrPrevGen table runs 6 rows (folio 16)
inline int chrPrevGenCount()
    { return 6; }

// the chrPrevNob table runs 7 rows (folio 16)
inline int chrPrevNobCount()
    { return 7; }

// the 1st son receives the inheritance (folio 14)
inline bool chrBirthFirstSonInherits()
    { return true; }

// one of a player's skills must be his father's occupation, unless prohibited
// (folio 15)
inline bool chrSkillsFatherOccupation()
    { return true; }

// a player may not choose the first 5 Group 3 skills - they are prohibited
// (folio 15)
inline bool chrSkillsGroup3FirstFiveProhibited()
    { return true; }

// no player may be an Adventurer - the possibility is taken care of under
// previous experience, and fathers roll on the adventurers table (folio 15)
inline bool chrSkillsNoPlayerAdventurer()
    { return true; }

// a child in the immediate royal family is never an orphan (folio 15)
inline bool chrRoyaltyNeverOrphan()
    { return true; }

// if a player's social rank does not conform to the minimum wealth, it is
// immediately raised to that level (folio 15)
inline bool chrRoyaltyRaiseRank()
    { return true; }

// after the Table 2 roll, all but the immediate family return to Table 1 and
// reroll, ignoring 96-00 (folio 15)
inline bool chrRoyaltyRerollIgnore()
    { return true; }

// the father's title is immediately raised one notch - Knight to Baron, Duke
// to Duke (folio 15)
inline bool chrRoyaltyTitleOneNotch()
    { return true; }

// the authors' campaign ruling - the world is dominated by humans, so a
// non-human cannot be higher than Earl (folio 16)
inline bool chrNobilityNonHumanEarlCap()
    { return true; }

// either or both race tables can be used; the authors both use Table 2, and
// Table 1 has been used in the past (folio 16)
inline bool chrRaceTable2Preferred()
    { return true; }

// a variation of Table 2 substitutes 9-18 wherever 13-18 appears, making it
// easier to become a non-human (folio 16)
inline bool chrRaceVariant9To18()
    { return true; }

// rather than letting any player be an elf and then limiting advancement,
// limit the number who can be elves by placing the requirements on the
// features - whoever heard of an ugly elf (folio 16)
inline bool chrRaceLimitByRequirements()
    { return true; }

// the percentile band's low roll (folio 14)
inline int chrBCLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 86;
        case 3:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll, the 00 convention pinned as 100 (folio 14)
inline int chrBCHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 85;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the social class code - 1 Commoner, 2 Merchant, 3 Gentleman, 4 Noble (folio
// 14)
inline int chrBCCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the eight-sided roll's low face (folio 14)
inline int chrSibLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 9;
        }
    }

// the eight-sided roll's high face (folio 14)
inline int chrSibHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 8;
        default:
            return 9;
        }
    }

// the rank code - 1 first son, 2 second son, 3 third son, 4 fourth son, 5
// bastard (folio 14)
inline int chrSibCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrComLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 26;
        case 2:
            return 41;
        case 3:
            return 71;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrComHi(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 40;
        case 2:
            return 70;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the initial gold, multiplied by the player's level (folio 15)
inline int chrComInitial(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 60;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the monthly allowance (folio 15)
inline int chrComAllow(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return 10;
        default:
            return 9;
        }
    }

// the inheritance (folio 15)
inline int chrComInherit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 50;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the skills code, 1 for A - one skill from Group 1 (folio 15)
inline int chrComSkills(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrMerLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 26;
        case 2:
            return 61;
        case 3:
            return 81;
        case 4:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrMerHi(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 60;
        case 2:
            return 80;
        case 3:
            return 95;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the initial gold (folio 15)
inline int chrMerInitial(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 100;
        case 2:
            return 120;
        case 3:
            return 170;
        case 4:
            return 200;
        default:
            return 9;
        }
    }

// the monthly allowance (folio 15)
inline int chrMerAllow(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 30;
        default:
            return 9;
        }
    }

// the inheritance - the Very Wealthy 400 rides the OCR's split '4 0 0' token,
// pinned as scanned (folio 15)
inline int chrMerInherit(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 150;
        case 2:
            return 200;
        case 3:
            return 250;
        case 4:
            return 400;
        default:
            return 9;
        }
    }

// the skills code, 2 for B on the first four rows and 3 for C on Very Wealthy
// (folio 15)
inline int chrMerSkills(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrGenLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 66;
        case 3:
            return 91;
        case 4:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrGenHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 65;
        case 2:
            return 90;
        case 3:
            return 95;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the initial gold (folio 15)
inline int chrGenInitial(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 100;
        case 2:
            return 150;
        case 3:
            return 200;
        case 4:
            return 250;
        default:
            return 9;
        }
    }

// the monthly allowance (folio 15)
inline int chrGenAllow(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 35;
        default:
            return 9;
        }
    }

// the inheritance - the Very Wealthy 600 rides the OCR's shifted columns,
// pinned as scanned (folio 15)
inline int chrGenInherit(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 150;
        case 2:
            return 250;
        case 3:
            return 350;
        case 4:
            return 600;
        default:
            return 9;
        }
    }

// the skills code - B then C, with the Very Wealthy row's letter riding the
// OCR column shift as scanned (folio 15)
inline int chrGenSkills(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrNobLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 41;
        case 3:
            return 86;
        case 4:
            return 96;
        case 5:
            return 98;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrNobHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 40;
        case 2:
            return 85;
        case 3:
            return 95;
        case 4:
            return 97;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the initial gold (folio 15)
inline int chrNobInitial(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 120;
        case 2:
            return 200;
        case 3:
            return 250;
        case 4:
            return 300;
        case 5:
            return 400;
        default:
            return 9;
        }
    }

// the monthly allowance (folio 15)
inline int chrNobAllow(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 25;
        case 3:
            return 35;
        case 4:
            return 45;
        case 5:
            return 60;
        default:
            return 9;
        }
    }

// the inheritance - the Very Wealthy 1000 rides the OCR's shifted columns,
// pinned as scanned (folio 15)
inline int chrNobInherit(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 150;
        case 2:
            return 300;
        case 3:
            return 450;
        case 4:
            return 700;
        case 5:
            return 1000;
        default:
            return 9;
        }
    }

// the skills code - D, D, E, E, F, F (folio 15)
inline int chrNobSkills(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the social class code - 1 Commoner, 2 Merchant, 3 Gentleman, 4 Noble (folio
// 15)
inline int chrFthClassCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the skills group the father's occupation is rolled under (folio 15)
inline int chrFthOccGroup(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrSk1Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 56;
        case 3:
            return 61;
        case 4:
            return 66;
        case 5:
            return 71;
        case 6:
            return 76;
        case 7:
            return 86;
        case 8:
            return 96;
        case 9:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrSk1Hi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 55;
        case 2:
            return 60;
        case 3:
            return 65;
        case 4:
            return 70;
        case 5:
            return 75;
        case 6:
            return 85;
        case 7:
            return 95;
        case 8:
            return 99;
        case 9:
            return 100;
        default:
            return 9;
        }
    }

// the skill code - 1 Vagabond, 2 Farmer/Serf, 3 Tinker, 4 Miner, 5 Woodsman,
// 6 Sailor, 7 Fisherman, 8 Craftsman, 9 Soldier, 10 Adventurer (folio 15)
inline int chrSk1Code(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrSk2Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 61;
        case 3:
            return 66;
        case 4:
            return 71;
        case 5:
            return 76;
        case 6:
            return 81;
        case 7:
            return 86;
        case 8:
            return 91;
        case 9:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrSk2Hi(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 60;
        case 2:
            return 65;
        case 3:
            return 70;
        case 4:
            return 75;
        case 5:
            return 80;
        case 6:
            return 85;
        case 7:
            return 90;
        case 8:
            return 95;
        case 9:
            return 100;
        default:
            return 9;
        }
    }

// the skill code - 1 Normal Merchant, 2 Ind. Craftsman, 3 Scribe, 4 Seaman, 5
// Slaver, 6 Animal Trainer, 7 Shipwright, 8 Master Merchant, 9 Bird Trainer,
// 10 Adventurer (folio 15)
inline int chrSk2Code(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrSk3Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 9;
        case 4:
            return 12;
        case 5:
            return 16;
        case 6:
            return 21;
        case 7:
            return 26;
        case 8:
            return 31;
        case 9:
            return 41;
        case 10:
            return 46;
        case 11:
            return 51;
        case 12:
            return 56;
        case 13:
            return 61;
        case 14:
            return 66;
        case 15:
            return 71;
        case 16:
            return 76;
        case 17:
            return 81;
        case 18:
            return 86;
        case 19:
            return 91;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrSk3Hi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 11;
        case 4:
            return 15;
        case 5:
            return 20;
        case 6:
            return 25;
        case 7:
            return 30;
        case 8:
            return 40;
        case 9:
            return 45;
        case 10:
            return 50;
        case 11:
            return 55;
        case 12:
            return 60;
        case 13:
            return 65;
        case 14:
            return 70;
        case 15:
            return 75;
        case 16:
            return 80;
        case 17:
            return 85;
        case 18:
            return 90;
        case 19:
            return 100;
        default:
            return 9;
        }
    }

// the skill code - 1 Assassin/Spytracker, 2 Sheriff, 3 Magistrate, 4 Sage, 5
// Alchemist, 6 Physician, 7 Artist/Sculptor/Musician, 8 Engineer, 9 Soldier,
// 10 Interpreter, 11 Writer, 12 Astronomer, 13 Don Juan, 14 Orator/Actor, 15
// Dream Interpreter, 16 Biologist, 17 Seaman, 18 Gambler, 19 Astrologer, 20
// Adventurer (folio 15)
inline int chrSk3Code(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        case 17:
            return 18;
        case 18:
            return 19;
        case 19:
            return 20;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrTtlLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 61;
        case 3:
            return 81;
        case 4:
            return 91;
        case 5:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrTtlHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 60;
        case 2:
            return 80;
        case 3:
            return 90;
        case 4:
            return 95;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the title code - 1 Knight, 2 Baron, 3 Count (Earl), 4 Marquis, 5 Duke, 6
// Royalty (folio 15)
inline int chrTtlCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrRoyLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 61;
        case 3:
            return 81;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrRoyHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 60;
        case 2:
            return 80;
        case 3:
            return 99;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the kin code - 1 Distant, 2 3rd Cousin, 3 2nd Cousin, 4 1st Cousin, 5
// Immediate Family (folio 15)
inline int chrRoyCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrPoKLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 51;
        case 3:
            return 91;
        case 4:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrPoKHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 90;
        case 3:
            return 95;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the position code - 1 Land Holder Only, 2 Orator, 3 In Army, 4 Courtier, 5
// Sheriff, 6 Magistrate, 7 Advisor to the King, with the Adventurer a
// separate roll (folio 15)
inline int chrPoKCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrPoBLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 51;
        case 3:
            return 81;
        case 4:
            return 91;
        case 5:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrPoBHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 80;
        case 3:
            return 90;
        case 4:
            return 95;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the position code as in the Knight table (folio 15)
inline int chrPoBCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrPoCLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 46;
        case 3:
            return 66;
        case 4:
            return 81;
        case 5:
            return 91;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrPoCHi(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 45;
        case 2:
            return 65;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the position code as in the Knight table (folio 15)
inline int chrPoCCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrPoMLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 36;
        case 3:
            return 51;
        case 4:
            return 81;
        case 5:
            return 91;
        case 6:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrPoMHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 35;
        case 2:
            return 50;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 99;
        case 6:
            return 100;
        default:
            return 9;
        }
    }

// the position code - the six plus 7 Advisor to the King (folio 15)
inline int chrPoMCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 15)
inline int chrPoDLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 26;
        case 3:
            return 41;
        case 4:
            return 73;
        case 5:
            return 83;
        case 6:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 15)
inline int chrPoDHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 40;
        case 3:
            return 72;
        case 4:
            return 82;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 9;
        }
    }

// the position code - the seven-band Advisor set (folio 15)
inline int chrPoDCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrACLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 71;
        case 3:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrACHi(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 70;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the Commoner father's adventurer level (folio 16)
inline int chrACLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrAMLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 66;
        case 3:
            return 76;
        case 4:
            return 86;
        case 5:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrAMHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 65;
        case 2:
            return 75;
        case 3:
            return 85;
        case 4:
            return 95;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the Merchant father's adventurer level (folio 16)
inline int chrAMLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrAGLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 51;
        case 3:
            return 66;
        case 4:
            return 81;
        case 5:
            return 91;
        case 6:
            return 96;
        case 7:
            return 99;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrAGHi(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 50;
        case 2:
            return 65;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 95;
        case 6:
            return 98;
        case 7:
            return 100;
        default:
            return 9;
        }
    }

// the Gentleman father's adventurer level (folio 16)
inline int chrAGLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrANLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 46;
        case 3:
            return 61;
        case 4:
            return 76;
        case 5:
            return 86;
        case 6:
            return 91;
        case 7:
            return 95;
        case 8:
            return 99;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrANHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 45;
        case 2:
            return 60;
        case 3:
            return 75;
        case 4:
            return 85;
        case 5:
            return 90;
        case 6:
            return 94;
        case 7:
            return 98;
        case 8:
            return 100;
        default:
            return 9;
        }
    }

// the Noble father's adventurer level (folio 16)
inline int chrANLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        default:
            return 9;
        }
    }

// the eight-sided roll's low face (folio 16)
inline int chrCCLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        default:
            return 9;
        }
    }

// the eight-sided roll's high face (folio 16)
inline int chrCCHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 8;
        default:
            return 9;
        }
    }

// the class code - 1 fighter, 2 thief, 3 cleric, 4 magic-user (folio 16)
inline int chrCCCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
            return 9;
        }
    }

// the eight-sided roll's low face (folio 16)
inline int chrCMLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 8;
        default:
            return 9;
        }
    }

// the eight-sided roll's high face (folio 16)
inline int chrCMHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 8;
        default:
            return 9;
        }
    }

// the class code as in the Commoner table (folio 16)
inline int chrCMCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the eight-sided roll's low face (folio 16)
inline int chrCGLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 7;
        default:
            return 9;
        }
    }

// the eight-sided roll's high face (folio 16)
inline int chrCGHi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        default:
            return 9;
        }
    }

// the class code as in the Commoner table (folio 16)
inline int chrCGCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the eight-sided roll's low face (folio 16)
inline int chrCNLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        default:
            return 9;
        }
    }

// the eight-sided roll's high face (folio 16)
inline int chrCNHi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 8;
        default:
            return 9;
        }
    }

// the class code as in the Commoner table (folio 16)
inline int chrCNCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the twelve-sided roll's low face (folio 16)
inline int chrR1CLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 11;
        case 4:
            return 12;
        default:
            return 9;
        }
    }

// the twelve-sided roll's high face (folio 16)
inline int chrR1CHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 12;
        default:
            return 9;
        }
    }

// the race code - 1 Half-goblin, 2 Half-orc, 3 Human, 4 Half-elf or Dwarf, 5
// Hobbit (folio 16)
inline int chrR1CCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the twelve-sided roll's low face (folio 16)
inline int chrR1MLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 12;
        default:
            return 9;
        }
    }

// the twelve-sided roll's high face (folio 16)
inline int chrR1MHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 11;
        case 3:
            return 12;
        default:
            return 9;
        }
    }

// the race code - 1 Hobbit, 2 Half-elf, 3 Human, 4 Dwarf (folio 16)
inline int chrR1MCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return 9;
        }
    }

// the twelve-sided roll's low face (folio 16)
inline int chrR1GLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 9;
        case 4:
            return 11;
        default:
            return 9;
        }
    }

// the twelve-sided roll's high face (folio 16)
inline int chrR1GHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        default:
            return 9;
        }
    }

// the race code - 1 Hobbit, 2 Half-elf, 3 Human, 4 Dwarf, 5 Elf (folio 16)
inline int chrR1GCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the race code - 1 Half-goblin/Half-orc, 2 Elf, 3 Dwarf, 4 Half-elf, 5
// Hobbit, 6 Human (folio 16)
inline int chrDiceRaceCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the number of Strength dice rolled (folio 16)
inline int chrDiceStr(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the number of Intelligence dice rolled (folio 16)
inline int chrDiceInt(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the number of Wisdom dice rolled (folio 16)
inline int chrDiceWis(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the number of Constitution dice rolled (folio 16)
inline int chrDiceCon(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the number of Dexterity dice rolled (folio 16)
inline int chrDiceDex(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the number of Charisma dice rolled (folio 16)
inline int chrDiceCha(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the race code - 1 Half-goblin/orc, 2 Elf, 3 Dwarf, 4 Half-elf, 5 Hobbit, 6
// Human (folio 16)
inline int chrReqRaceCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the Strength requirement's minimum - the printed 'any' pinned as 3 (folio
// 16)
inline int chrReqStrMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 9;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Strength requirement's maximum - the printed 'any' pinned as 18 (folio
// 16)
inline int chrReqStrMax(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 12;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the Intelligence requirement's minimum (folio 16)
inline int chrReqIntMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Intelligence requirement's maximum (folio 16)
inline int chrReqIntMax(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the Wisdom requirement's minimum (folio 16)
inline int chrReqWisMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 9;
        case 2:
            return 3;
        case 3:
            return 9;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Wisdom requirement's maximum (folio 16)
inline int chrReqWisMax(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the Constitution requirement's minimum (folio 16)
inline int chrReqConMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 9;
        case 2:
            return 13;
        case 3:
            return 3;
        case 4:
            return 13;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Constitution requirement's maximum (folio 16)
inline int chrReqConMax(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the Dexterity requirement's minimum (folio 16)
inline int chrReqDexMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 9;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 13;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Dexterity requirement's maximum (folio 16)
inline int chrReqDexMax(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the Charisma requirement's minimum (folio 16)
inline int chrReqChaMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 13;
        case 2:
            return 3;
        case 3:
            return 13;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the Charisma requirement's maximum (folio 16)
inline int chrReqChaMax(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrPCLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 86;
        case 2:
            return 97;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrPCHi(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 96;
        case 2:
            return 99;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the experience multiplier - 0 pins the 'nil' band (folio 16)
inline int chrPCMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 50;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrPMLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 71;
        case 2:
            return 91;
        case 3:
            return 97;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrPMHi(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 90;
        case 2:
            return 96;
        case 3:
            return 99;
        case 4:
            return 100;
        default:
            return 9;
        }
    }

// the experience multiplier (folio 16)
inline int chrPMMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 70;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrPGLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 61;
        case 2:
            return 81;
        case 3:
            return 94;
        case 4:
            return 98;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrPGHi(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 80;
        case 2:
            return 93;
        case 3:
            return 97;
        case 4:
            return 99;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the experience multiplier (folio 16)
inline int chrPGMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 70;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 16)
inline int chrPNLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 71;
        case 3:
            return 86;
        case 4:
            return 93;
        case 5:
            return 98;
        case 6:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 16)
inline int chrPNHi(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 70;
        case 2:
            return 85;
        case 3:
            return 92;
        case 4:
            return 97;
        case 5:
            return 99;
        case 6:
            return 100;
        default:
            return 9;
        }
    }

// the experience multiplier (folio 16)
inline int chrPNMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 50;
        case 4:
            return 70;
        case 5:
            return 100;
        case 6:
            return 130;
        default:
            return 9;
        }
    }

// ---- the Pulsipher Eldar deltas (folios 20-21) ----

// the Silvan elf advances to 8th level fighter (folio 21)
inline int chrSilvanFighterMax()
    { return 8; }

// a Silvan elf with 18 strength advances to 9th level fighter (folio 21)
inline int chrSilvanFighterMaxStr18()
    { return 9; }

// the Silvan elf advances to 4th level magic-user (folio 21)
inline int chrSilvanMuMax()
    { return 4; }

// a Silvan elf with 18 intelligence advances to 5th level magic-user (folio
// 21)
inline int chrSilvanMuMaxInt18()
    { return 5; }

// the Sindar must have at least average abilities in all six categories -
// average pinned as 9 (folio 21)
inline int chrSindarStatMin()
    { return 9; }

// the Sindar must total at least 63 across the six categories (folio 21)
inline int chrSindarTotalMin()
    { return 63; }

// the Sindarin elf advances to 8th level magic-user (folio 21)
inline int chrSindarMuMax()
    { return 8; }

// a Sindarin elf with 18 intelligence advances to 9th level magic-user (folio
// 21)
inline int chrSindarMuMaxInt18()
    { return 9; }

// the Sindarin elf advances to 4th level fighter (folio 21)
inline int chrSindarFighterMax()
    { return 4; }

// a Sindarin elf with 17 strength advances to 5th level fighter (folio 21)
inline int chrSindarFighterMaxStr17()
    { return 5; }

// a Sindarin elf with 18 strength advances to 6th level fighter (folio 21)
inline int chrSindarFighterMaxStr18()
    { return 6; }

// the Eldar proper require a minimum 13 wisdom, on top of the Sindar
// requirements (folio 21)
inline int chrEldarWisMin()
    { return 13; }

// the Eldar proper must total at least 67 - the addition reflects gains
// acquired in Valinor, a game-balance addition Pulsipher calls not realistic
// (folio 21)
inline int chrEldarTotalMin()
    { return 67; }

// an Eldar proper may advance to 11th level magic-user, maximum regardless of
// intelligence (folio 21)
inline int chrEldarMuMax()
    { return 11; }

// an Eldar proper may advance to 11th level fighter, maximum regardless of
// strength (folio 21)
inline int chrEldarFighterMax()
    { return 11; }

// the Eldar speak mind-to-mind with each other at a range of 2 and a half per
// level of the more experienced - pinned as five half-units, the conversion
// noted (folio 21)
inline int chrEldarMindRangePerLevel()
    { return 5; }

// the Eldar's True Sight adds +1 per level versus phantasmal forces (folio
// 21)
inline int chrEldarPhantasmalPerLevel()
    { return 1; }

// the Eldar see through illusions at 5 percent per level (folio 21)
inline int chrEldarIllusionPctPerLevel()
    { return 5; }

// the Eldar see the true shape of a polymorphed being at 3 percent per level
// - the worked example reads a 5th level at 15 percent (folio 21)
inline int chrEldarPolymorphPctPerLevel()
    { return 3; }

// the Eldar see the true shape of a shape-changed being at 1 percent per
// level (folio 21)
inline int chrEldarShapeChangePctPerLevel()
    { return 1; }

// a realistic chance of going over sea is one in one thousand per year for
// the Eldar proper (folio 21)
inline int chrSeaEldarDenominator()
    { return 1000; }

// the Sindar's over-sea chance is one in one hundred per year once they have
// seen the western ocean (folio 21)
inline int chrSeaSindarSeenDenominator()
    { return 100; }

// the Sindar's over-sea chance is one in ten thousand per year before they
// have seen the western ocean (folio 21)
inline int chrSeaSindarUnseenDenominator()
    { return 10000; }

// there are no ability requirements for Silvan elves (folio 21)
inline bool chrSilvanNoReqs()
    { return true; }

// the Silvan elves have all powers listed in D&D (folio 21)
inline bool chrSilvanDdPowers()
    { return true; }

// the Silvan elves are immune to disease (folio 21)
inline bool chrSilvanDiseaseImmune()
    { return true; }

// the Silvan elves are immune to aging effects, such as a Staff of Withering,
// because they are naturally immortal (folio 21)
inline bool chrSilvanAgingImmune()
    { return true; }

// the Silvan elves may be Lawful or Neutral and are never evil (folio 21)
inline bool chrSilvanLawfulOrNeutral()
    { return true; }

// an Eldar proper may take 11th level magic-user or 11th level fighter, but
// not both - the player chooses one path when he becomes Eldar proper (folio
// 21)
inline bool chrEldarOnePathOnly()
    { return true; }

// the Eldar may learn one language per intelligence point, but do not begin
// with knowledge of orc, gnoll or hobgoblin (folio 21)
inline bool chrEldarLangPerIntPoint()
    { return true; }

// the Eldar can calm and control their own animals (folio 21)
inline bool chrEldarCalmAnimals()
    { return true; }

// the Eldar can communicate simply with small birds and other innocuous
// creatures - no monsters (folio 21)
inline bool chrEldarBirdSpeech()
    { return true; }

// the Eldar have keen eyesight, treated as two-power binoculars or a
// microscope (folio 21)
inline bool chrEldarKeenEyes()
    { return true; }

// optionally the Eldar see hidden - but not invisible - enemies at 1 percent
// per level: shadows, Blending, Beguiling (folio 21)
inline bool chrEldarHiddenOptional()
    { return true; }

// when an Eldar sees through an illusion or a true shape, he is unaware that
// the illusion or false shape exists (folio 21)
inline bool chrEldarUnawareOnSuccess()
    { return true; }

// do not roll the over-sea chance at all until the elf has reached his
// maximum level (folio 21)
inline bool chrSeaWaitUntilMaxLevel()
    { return true; }

// the Silvan elves never went over sea - Pulsipher calls Smith's provision
// for it ridiculous (folio 21)
inline bool chrSilvanNeverCrossSea()
    { return true; }

// half-elves have the same requirements and powers as Eldar proper, but
// advance as specified in Greyhawk (folio 21)
inline bool chrHalfElfSameAsEldar()
    { return true; }

// all Eldar and half-elves are Lawful and good in this world (folio 21)
inline bool chrEldarAllLawfulGood()
    { return true; }

// for convenience one can refer to Eldar proper as Noldor, but this is not
// accurate (folio 21)
inline bool chrEldarNoldorShorthand()
    { return true; }

// the deltas against the R888 Smith pin, never silent: Smith's Noldor carry
// no level cap where Pulsipher caps the one path at 11th, Smith's 150-percent
// ranges-and-effects advantage is rejected as too large and unbalancing with
// no source justification, the disease immunity extends to aging effects, and
// Smith's high over-sea chances are replaced by the one-in-a-thousand
// doctrine (folios 20-21)
inline bool chrEldarRejectsSmithDelta()
    { return true; }

}   // namespace rules
