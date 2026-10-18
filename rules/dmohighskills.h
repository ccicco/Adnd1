// =========================================================================================
// Adnd1 - rules/dmohighskills.h
// HIGH-LEVEL SKILLS AND WARRIORS - DMO Chapter 7, round two of five: the
// skills doctrine (success as the number or less on 1d20, the Table 41
// ability adjustments, the fixed drop of limited-use skills with the
// zero-or-less lockout that ability adjustments cannot lift and that spreads
// to dependent skills, the opposed-roll cases with re-rolled ties, the
// slot-and-character-point cost reading, the 16 mortal base-score ceiling
// that wishes cannot touch), the Table 40 skill roster (33 rows in four class
// bands - eleven warriors, three wizards, eight priests, eleven rogues - with
// the level requirements, base scores, relevant abilities and costs; the two
// blank priest cost cells pinned as printed blanks), the Table 42 warrior
// advancement grid (fighter 3.0M to 5.5M XP in 250K steps, paladin/ranger
// 3.6M to 6.6M in 300K steps, the weapon and nonweapon proficiency columns,
// the 9+N hit points with the Con-bonus footnote), the fighter
// breech-immunity ladder (+1 at 21st to +4 at 30th, any weapon including bare
// hands, no bonus, not magical, undiminished by planar distance or magic
// disruption) and intimidation (the 10-yard plain-sight use, the 4+1
// auto-retreat, the 4+2 save vs. death magic, the -2 within 60 feet, the
// per-three-levels -2 growth to -6), the ranger followers/scroll/scrying
// powers and the paladin scroll/cure/disease-immunity powers, and all eleven
// warrior skills - adaptation, all-around attack, bravery, captivate, death
// blow, frighten/challenge, hardiness, inner focus, sense danger, signature
// item and signature mount.
// census 531 -> 532.
//
// verified against printed pp. 145-156 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns, the djvu.txt full texts; the tsr02156
// ABBYY read is primary and the tesseract read is cross-checked; leaf N =
// printed page N). The Table 40 roster, Table 41 grid and Table 42 grid from
// pp. 145-147, the skills doctrine from p. 146, the fighter, ranger and
// paladin powers from pp. 147-149, and the eleven skill descriptions from pp.
// 148-156. Three contested cells settled against the physical copy
// (2026-10-18): the Divine Voice and Detect Deception cost cells are blank in
// print as in both captures, and the bravery prerequisite line prints
// invulnerability - pinned verbatim. The Table 42 20th-level proficiency row
// reads weapon 10, nonweapon 9 per the physical copy.
//
// the gap census after this round: 87 closed, 9 open - three Chapter 7
// children flip in round two of five (the parent stays open until R612); the
// DMO arc continues with R610 (Wizards and Priests, Tables 43-46, pp.
// 156-167).
//
namespace rules {

// ---- the DMO skills-doctrine pins ----

// the skill success check: success is rolling the skill's number or less on
// 1d20 (printed p. 146).
inline int deySkillDieSides()
    { return 20; }

// the mortal ceiling: no mortal can ever have a base score of more than 16 in
// any skill (printed p. 146).
inline int deyMaxSkillBase()
    { return 16; }

// the group lock: characters cannot learn skills from outside their groups
// (printed p. 146).
inline bool deySkillsNoCrossGroup()
    { return true; }

// the Table 41 rule: a character's ability scores can alter the chance for
// success in most cases (printed p. 146).
inline bool deySkillAbilityAdjustApplies()
    { return true; }

// the cost reading: the first cost number is the cost in nonweapon
// proficiency slots unless otherwise indicated (printed p. 146).
inline bool deySkillCostFirstIsSlots()
    { return true; }

// the parenthesized cost: the number in parentheses is the skill's character
// point cost under the Skills & Powers point system (printed p. 146).
inline bool deySkillCostParensIsPoints()
    { return true; }

// the improvement route: a base success number can be improved by devoting
// extra slots or character points to the skill (printed p. 146).
inline bool deySkillBaseImprovableWithSlots()
    { return true; }

// the limited-use rule: the success numbers of limited-use skills drop by a
// fixed amount each time they are used (printed p. 146).
inline bool deySkillLimitedUseDropsFixed()
    { return true; }

// the exhaustion rule: once a base score is reduced to zero or less the skill
// cannot be used for a set period, usually one day (printed p. 146).
inline bool deySkillZeroUnavailableADay()
    { return true; }

// the dependent-skill rule: any skill based upon the reduced skill is
// likewise unavailable (printed p. 146).
inline bool deySkillDependentsUnavailable()
    { return true; }

// the no-restore rule: even if the Table 41 ability adjustment raises the
// score above zero the skill stays unavailable until the listed time has
// passed (printed p. 146).
inline bool deySkillAbilityCantRestore()
    { return true; }

// the recovery rule: the base score returns to normal after the listed time
// has elapsed (printed p. 146).
inline bool deySkillBaseRecoversAfterPeriod()
    { return true; }

// the opposed roll, first case: if one opponent fails, the creature who
// succeeded wins the contest (printed p. 146).
inline bool deyOpposedOneFailsOtherWins()
    { return true; }

// the opposed roll, second case: if both make their rolls, the opponent with
// the higher roll wins (printed p. 146).
inline bool deyOpposedBothMakeHigherWins()
    { return true; }

// the opposed roll, third case: if both opponents fail, some unusual result
// usually occurs (printed p. 146).
inline bool deyOpposedBothFailUnusual()
    { return true; }

// the opposed roll, ties: all ties are re-rolled (printed p. 146).
inline bool deyOpposedTiesRerolled()
    { return true; }

// the wish proof: wishes have no effect on the base-score limit of 16
// (printed p. 146).
inline bool deyWishesNoEffectOnLimit()
    { return true; }

// the framing: skills are similar to nonweapon proficiencies but with a much
// more dramatic effect and a minimum level requirement (printed p. 146).
inline bool deySkillsMoreDramaticThanProficiencies()
    { return true; }

// ---- the DMO Table 41 modifier pins ----

// the Table 41 row count: eleven ability bands from 3-or-less up to 18-plus
// (printed p. 146).
inline int deyT41RowCount()
    { return 11; }

// the ability-score band of Table 41: a score of 3 or less reads band 0 (-5),
// 4 band 1, 5 band 2, 6 band 3, 7 band 4, 8 through 13 band 5 (modifier 0),
// 14 band 6 (+1), 15 band 7 (+2), 16 band 8 (+3), 17 band 9 (+4), and 18 or
// more the tail band 10 (+5) (printed p. 146).
inline int deyT41Band(int x)
    {
        if (x <= 3) return 0;
        if (x <= 4) return 1;
        if (x <= 5) return 2;
        if (x <= 6) return 3;
        if (x <= 7) return 4;
        if (x <= 13) return 5;
        if (x <= 14) return 6;
        if (x <= 15) return 7;
        if (x <= 16) return 8;
        if (x <= 17) return 9;
        return 10;
    }

// the modifier column: -5, -4, -3, -2, -1, 0, +1, +2, +3, +4, +5 across the
// eleven ability bands (printed p. 146).
inline int deyT41Mod(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -4;
        case 2:
            return -3;
        case 3:
            return -2;
        case 4:
            return -1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 5;
        default:
            return -99;
        }
    }

// ---- the DMO Table 40 roster pins ----

// the Table 40 row count: thirty-three skills - eleven warriors, three
// wizards, eight priests, eleven rogues (printed pp. 145-146).
inline int deyT40RowCount()
    { return 33; }

// the Table 40 warrior band: rows 0 through 10 hold the eleven warrior skills
// (printed pp. 145-146).
inline int deyT40WarriorBase()
    { return 0; }

// the Table 40 wizard band: rows 11 through 13 hold the three wizard skills
// (printed pp. 145-146).
inline int deyT40WizardBase()
    { return 11; }

// the Table 40 priest band: rows 14 through 21 hold the eight priest skills
// (printed pp. 145-146).
inline int deyT40PriestBase()
    { return 14; }

// the Table 40 rogue band: rows 22 through 32 hold the eleven rogue skills
// (printed pp. 145-146).
inline int deyT40RogueBase()
    { return 22; }

// the requirement-level column: the minimum class level of each skill -
// warriors 10 or 15, wizards 12, priests 10, 15 or 21, rogues 11, 16 or 21
// (printed pp. 145-146).
inline int deyT40ReqLevel(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 15;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 15;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 10;
        case 15:
            return 15;
        case 16:
            return 10;
        case 17:
            return 15;
        case 18:
            return 10;
        case 19:
            return 21;
        case 20:
            return 15;
        case 21:
            return 15;
        case 22:
            return 11;
        case 23:
            return 11;
        case 24:
            return 16;
        case 25:
            return 11;
        case 26:
            return 11;
        case 27:
            return 16;
        case 28:
            return 11;
        case 29:
            return 16;
        case 30:
            return 16;
        case 31:
            return 21;
        case 32:
            return 16;
        default:
            return -99;
        }
    }

// the base-score column: 9 adaptation, none printed for all-around attack, 4
// bravery, 4 captivate, none printed for death blow, 4 frighten/challenge, 4
// hardiness, 4 inner focus, 10 signature item, 9 signature mount, 6 sense
// danger; the eight unprinted cells pin -99 (printed pp. 145-146).
inline int deyT40Base(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -99;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return -99;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 10;
        case 9:
            return 9;
        case 10:
            return 6;
        case 11:
            return 4;
        case 12:
            return 10;
        case 13:
            return 8;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return -99;
        case 22:
            return 10;
        case 23:
            return 4;
        case 24:
            return -99;
        case 25:
            return 11;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return 5;
        case 29:
            return 4;
        case 30:
            return 6;
        case 31:
            return -99;
        case 32:
            return -99;
        default:
            return -99;
        }
    }

// the ability-code column: 1 Intelligence/Reason, 2 Wisdom/Willpower, 3
// Charisma/Appearance, 4 Constitution/Fitness, 5 Wisdom/Intuition, 6
// Charisma/Leadership, 7 Intelligence/Knowledge, 8 Dexterity/Balance; the
// eight N/A cells pin -99 (printed pp. 145-146).
inline int deyT40Ability(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -99;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return -99;
        case 5:
            return 6;
        case 6:
            return 4;
        case 7:
            return 2;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 2;
        case 12:
            return 5;
        case 13:
            return 7;
        case 14:
            return 2;
        case 15:
            return 6;
        case 16:
            return 2;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 2;
        case 20:
            return 5;
        case 21:
            return -99;
        case 22:
            return 1;
        case 23:
            return 7;
        case 24:
            return -99;
        case 25:
            return 8;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return 2;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return -99;
        case 32:
            return -99;
        default:
            return -99;
        }
    }

// the slot-cost column: 1 or 2 nonweapon proficiency slots per skill, -99 at
// the two blank priest cells (Divine Voice row 15, Detect Deception row 17)
// (printed pp. 145-146).
inline int deyT40CostSlots(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return -99;
        case 16:
            return 1;
        case 17:
            return -99;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 1;
        case 29:
            return 2;
        case 30:
            return 2;
        case 31:
            return 1;
        case 32:
            return 1;
        default:
            return -99;
        }
    }

// the point-cost column: the parenthesized Skills & Powers character point
// cost, 3 or 6 - always three times the slot cost where printed, -99 at the
// two blank priest cells (printed pp. 145-146).
inline int deyT40CostCP(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 3;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 6;
        case 9:
            return 3;
        case 10:
            return 6;
        case 11:
            return 3;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return -99;
        case 16:
            return 3;
        case 17:
            return -99;
        case 18:
            return 3;
        case 19:
            return 6;
        case 20:
            return 3;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 3;
        case 27:
            return 6;
        case 28:
            return 3;
        case 29:
            return 6;
        case 30:
            return 6;
        case 31:
            return 3;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// ---- the DMO Table 40 prerequisite pins ----

// the captivate prerequisite: warrior 15+ and the bravery skill (printed pp.
// 145-146).
inline bool deyCaptivateNeedsBravery()
    { return true; }

// the frighten/challenge prerequisite: warrior 10+ and the bravery skill
// (printed pp. 145-146).
inline bool deyFrightenNeedsBravery()
    { return true; }

// the hardiness prerequisite: warrior 15+ and the bravery skill (printed pp.
// 145-146).
inline bool deyHardinessNeedsBravery()
    { return true; }

// the divine strength prerequisite: priest 10+ and eminence (printed pp.
// 145-146).
inline bool deyDivineStrengthNeedsEminence()
    { return true; }

// the divine voice prerequisite: priest 15+ and eminence (printed pp.
// 145-146).
inline bool deyDivineVoiceNeedsEminence()
    { return true; }

// the detect deception prerequisite: priest 15+ and eminence (printed pp.
// 145-146).
inline bool deyDetectDeceptionNeedsEminence()
    { return true; }

// the invincibility prerequisite: priest 21+ and eminence (printed pp.
// 145-146).
inline bool deyInvincibilityNeedsEminence()
    { return true; }

// the smite prerequisite: priest 15+ and eminence (printed pp. 145-146).
inline bool deySmiteNeedsEminence()
    { return true; }

// the shadow flight prerequisite: rogue 21+ and shadow travel (printed pp.
// 145-146).
inline bool deyShadowFlightNeedsShadowTravel()
    { return true; }

// ---- the DMO warrior advancement pins ----

// the warrior THACO stop: warriors' THACO ceases to improve once they reach
// level 20 (printed p. 146).
inline int deyWarriorThacoStopLevel()
    { return 20; }

// the advancement ceiling: warriors continue to receive extra proficiencies
// and hit points until level 30 (printed p. 146).
inline int deyWarriorAdvLimit()
    { return 30; }

// the power threshold: warriors automatically receive special powers
// beginning at 21st level (printed p. 146).
inline int deyWarriorPowerLevel()
    { return 21; }

// the skill threshold: all warriors have access to the special skills
// beginning at level 10 (printed p. 146).
inline int deyWarriorSkillLevel()
    { return 10; }

// the Table 42 row count: eleven levels from 20th through 30th (printed p.
// 147).
inline int deyT42RowCount()
    { return 11; }

// the Table 42 footnote: bonus hit points from high Constitution scores are
// not added after 9th level (printed p. 147).
inline bool deyT42ConBonusStopsAfter9()
    { return true; }

// the fighter experience column: 3,000,000 at 20th rising in 250,000 steps to
// 5,500,000 at 30th (printed p. 147).
inline int deyT42FighterXP(int b)
    {
        switch (b) {
        case 0:
            return 3000000;
        case 1:
            return 3250000;
        case 2:
            return 3500000;
        case 3:
            return 3750000;
        case 4:
            return 4000000;
        case 5:
            return 4250000;
        case 6:
            return 4500000;
        case 7:
            return 4750000;
        case 8:
            return 5000000;
        case 9:
            return 5250000;
        case 10:
            return 5500000;
        default:
            return -99;
        }
    }

// the paladin/ranger experience column: 3,600,000 at 20th rising in 300,000
// steps to 6,600,000 at 30th (printed p. 147).
inline int deyT42PalRangerXP(int b)
    {
        switch (b) {
        case 0:
            return 3600000;
        case 1:
            return 3900000;
        case 2:
            return 4200000;
        case 3:
            return 4500000;
        case 4:
            return 4800000;
        case 5:
            return 5100000;
        case 6:
            return 5400000;
        case 7:
            return 5700000;
        case 8:
            return 6000000;
        case 9:
            return 6300000;
        case 10:
            return 6600000;
        default:
            return -99;
        }
    }

// the weapon proficiency column: 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14 -
// one more every three levels (printed p. 147).
inline int deyT42WeaponProf(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 13;
        case 8:
            return 13;
        case 9:
            return 13;
        case 10:
            return 14;
        default:
            return -99;
        }
    }

// the nonweapon proficiency column: 9, 10, 10, 10, 11, 11, 11, 12, 12, 12, 13
// - always one behind the weapon column (printed p. 147).
inline int deyT42NonweaponProf(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 11;
        case 6:
            return 11;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 13;
        default:
            return -99;
        }
    }

// the hit-point base column: the constant 9 of the printed 9-plus-N hit-point
// cells (printed p. 147).
inline int deyT42HpBase(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 9;
        default:
            return -99;
        }
    }

// the hit-point bonus column: 33 at 20th rising in +3 steps to 63 at 30th
// (printed p. 147).
inline int deyT42HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 36;
        case 2:
            return 39;
        case 3:
            return 42;
        case 4:
            return 45;
        case 5:
            return 48;
        case 6:
            return 51;
        case 7:
            return 54;
        case 8:
            return 57;
        case 9:
            return 60;
        case 10:
            return 63;
        default:
            return -99;
        }
    }

// ---- the DMO fighter breech-immunity pins ----

// the breech threshold: beginning at 21st level a fighter can harm creatures
// hit only by +1 or better magical weapons (printed pp. 147-148).
inline int deyBreechStartLevel()
    { return 21; }

// the breech-immunity ladder: level 20 or less stays in band 0 (no breech),
// 21st through 23rd band 1 (harms +1-or-better creatures), 24th through 26th
// band 2 (+2), 27th through 29th band 3 (+3), and 30th or more the tail band
// 4 (+4) (printed pp. 147-148).
inline int deyBreechBand(int x)
    {
        if (x <= 20) return 0;
        if (x <= 23) return 1;
        if (x <= 26) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the breech weapon rule: any weapon qualifies, including bare hands (printed
// pp. 147-148).
inline bool deyBreechAnyWeaponIncludingBareHands()
    { return true; }

// the breech no-bonus rule: the fighter gets no attack or damage bonus, only
// the ability to harm (printed pp. 147-148).
inline bool deyBreechNoAttackBonus()
    { return true; }

// the breech nature: the power is not magical (printed pp. 147-148).
inline bool deyBreechNotMagical()
    { return true; }

// the breech reach: not diminished by planar distances or effects that
// disrupt magic (printed pp. 147-148).
inline bool deyBreechUndiminishedByPlanarOrAntimagic()
    { return true; }

// ---- the DMO fighter intimidation pins ----

// the intimidation threshold: a fighter of 21st level or higher can shake an
// enemy's resolve before combat begins (printed pp. 148-149).
inline int deyIntimidationStartLevel()
    { return 21; }

// the intimidation range: close enough to see the opponent's face clearly, 10
// yards in good visibility (printed pp. 148-149).
inline int deyIntimidationSightYards()
    { return 10; }

// the intimidation auto-retreat: opponents with 4+1 Hit Dice/levels or less
// automatically retreat (the printed 4+1 form) (printed pp. 148-149).
inline int deyIntimidationAutoRetreatHd()
    { return 4; }

// the intimidation save threshold: opponents with more than 4+2 Hit
// Dice/levels get a saving throw vs. death magic (the printed 4+2 form)
// (printed pp. 148-149).
inline int deyIntimidationSaveHd()
    { return 4; }

// the intimidation stay penalty: a failed save leaves a -2 penalty on all
// initiative, attack, saving throw and ability check rolls while the fighter
// remains within 60 feet (printed pp. 148-149).
inline int deyIntimidationStayPenalty()
    { return 2; }

// the intimidation penalty range: the -2 penalties apply within 60 feet of
// the fighter and return when the creature re-enters (printed pp. 148-149).
inline int deyIntimidationRange()
    { return 60; }

// the intimidation growth: for every three levels gained after receiving the
// ability the opponent saves at an additional -2 (printed pp. 148-149).
inline int deyIntimidationPenaltyStep()
    { return 3; }

// the intimidation increment: the per-three-levels saving throw adjustment is
// -2 per step - 24th level -2, 27th -4, 30th -6 (printed pp. 148-149).
inline int deyIntimidationPenaltyIncrement()
    { return 2; }

// the intimidation save ladder: 21st through 23rd band 0 (no penalty), 24th
// through 26th band 1 (saves at -2), 27th through 29th band 2 (-4), and 30th
// or more the tail band 3 (-6) (printed pp. 148-149).
inline int deyIntimidationPenaltyBand(int x)
    {
        if (x <= 23) return 0;
        if (x <= 26) return 1;
        if (x <= 29) return 2;
        return 3;
    }

// the intimidation classification: use does not constitute an attack (printed
// pp. 148-149).
inline bool deyIntimidationNotAnAttack()
    { return true; }

// the intimidation initiative: there is no initiative modifier (printed pp.
// 148-149).
inline bool deyIntimidationNoInitModifier()
    { return true; }

// the retreat form: the creature does not flee in panic but cautiously backs
// away (printed pp. 148-149).
inline bool deyIntimidationCautiousRetreat()
    { return true; }

// the day-long effect: intimidated creatures seek to avoid any confrontation
// with the fighter for the rest of the day (printed pp. 148-149).
inline bool deyIntimidationAvoidsRestOfDay()
    { return true; }

// the counterattack clause: if the fighter or party attacks, the creature is
// free to return the attack (printed pp. 148-149).
inline bool deyIntimidationFreeToCounterattack()
    { return true; }

// the visibility requirement: the fighter must be in plain sight (printed pp.
// 148-149).
inline bool deyIntimidationMustBeInPlainSight()
    { return true; }

// ---- the DMO ranger and paladin pins ----

// the ranger follower threshold: at 21st level a ranger attracts 2d6 more
// followers (printed pp. 148-149).
inline int deyRangerFollowerLevel1()
    { return 21; }

// the ranger follower repeat: another group of 2d6 followers at 26th level
// (printed pp. 148-149).
inline int deyRangerFollowerLevel2()
    { return 26; }

// the ranger follower dice: 2d6 followers per group (printed pp. 148-149).
inline int deyRangerFollowerDiceCount()
    { return 2; }

// the ranger follower die: d6 for the follower groups (printed pp. 148-149).
inline int deyRangerFollowerDieSides()
    { return 6; }

// the ranger scroll threshold: at 21st level a ranger can read priest scrolls
// (printed pp. 148-149).
inline int deyRangerScrollLevel()
    { return 21; }

// the ranger effective level: the ranger's level counts as 9th for spell
// failure, scroll writing and scrying (printed pp. 148-149).
inline int deyRangerEffectiveLevel()
    { return 9; }

// the ranger scroll-writing threshold: at 24th level a ranger can prepare
// scrolls of priest spells per the Chapter 4 rules (printed pp. 148-149).
inline int deyRangerScrollWriteLevel()
    { return 24; }

// the ranger scrying threshold: at 27th level a ranger can employ crystal
// balls and other scrying devices as a 9th-level wizard (printed pp.
// 148-149).
inline int deyRangerScryingLevel()
    { return 27; }

// the ranger item use: the ranger can also use priest magical items at 21st
// level (printed pp. 148-149).
inline bool deyRangerUsePriestItems()
    { return true; }

// the paladin scroll threshold: at 21st level a paladin can read priest
// scrolls (printed pp. 148-149).
inline int deyPaladinScrollLevel()
    { return 21; }

// the paladin effective level: 9th for spell failure and scroll writing
// (printed pp. 148-149).
inline int deyPaladinEffectiveLevel()
    { return 9; }

// the paladin scroll-writing threshold: at 24th level a paladin can prepare
// scrolls of priest spells (printed pp. 148-149).
inline int deyPaladinScrollWriteLevel()
    { return 24; }

// the paladin disease threshold: at 27th level a paladin becomes immune to
// all forms of disease (printed pp. 148-149).
inline int deyPaladinDiseaseImmunityLevel()
    { return 27; }

// the paladin cursed-disease immunity: even cursed afflictions such as mummy
// rot and lycanthropy (printed pp. 148-149).
inline bool deyPaladinImmuneCursedDisease()
    { return true; }

// the paladin exception one: not immune to disease inflicted by true dweomers
// (printed pp. 148-149).
inline bool deyPaladinNotImmuneTrueDweomers()
    { return true; }

// the paladin exception two: not immune to the special powers of priests
// higher level than the paladin (printed pp. 148-149).
inline bool deyPaladinNotImmuneHigherPriestPowers()
    { return true; }

// the paladin cure upgrade: the cure disease ability now cures cursed
// afflictions such as mummy rot and lycanthropy (printed pp. 148-149).
inline bool deyPaladinCureCursedAfflictions()
    { return true; }

// the paladin curse removal: cures any curse or affliction cast by a
// character of lower level than the paladin (printed pp. 148-149).
inline bool deyPaladinCureLowerLevelCurses()
    { return true; }

// the paladin item curse: the cure applies to cursed magical items as well
// (printed pp. 148-149).
inline bool deyPaladinCureCursedItems()
    { return true; }

// ---- the DMO warrior adaptation pins ----

// the adaptation target: the +6 foreign environment penalty to initiative
// (printed pp. 148-149).
inline int deyAdaptForeignInitPenalty()
    { return 6; }

// the adaptation check bonus: +3 (or +15%) to environment saving throws and
// ability checks (printed pp. 148-149).
inline int deyAdaptCheckBonus()
    { return 3; }

// the adaptation fog penalty: characters who cannot observe their
// surroundings suffer -4 to the skill check (printed pp. 148-149).
inline int deyAdaptUnseenPenalty()
    { return 4; }

// the adaptation duration: the entire battle plus one day per character level
// (printed pp. 148-149).
inline int deyAdaptBonusDaysPerLevel()
    { return 1; }

// the adaptation practice: at least eight hours a week of practice in the
// environment extends the effect indefinitely (printed pp. 148-149).
inline int deyAdaptPracticeHours()
    { return 8; }

// the permanent adaptation cost: one extra weapon or nonweapon proficiency
// slot (printed pp. 148-149).
inline int deyAdaptPermanentSlotCost()
    { return 1; }

// the permanent adaptation point cost: three character points (printed pp.
// 148-149).
inline int deyAdaptPermanentCpCost()
    { return 3; }

// the adaptation effect: no combat or initiative penalties for fighting in an
// unfavorable environment (printed pp. 148-149).
inline bool deyAdaptNegatesCombatPenalties()
    { return true; }

// the adaptation check cadence: checked at the end of each round in combat,
// every round until successful (printed pp. 148-149).
inline bool deyAdaptCheckEachRound()
    { return true; }

// the adaptation limit one: no effect on situational movement penalties or
// physically impossible conditions (printed pp. 148-149).
inline bool deyAdaptNoSituationalMovement()
    { return true; }

// the adaptation limit two: no effect on penalties from magical properties,
// vision or lighting (printed pp. 148-149).
inline bool deyAdaptNoMagicalOrVisionPenalties()
    { return true; }

// the adaptation extension: eight hours a week of practice extends the effect
// indefinitely (printed pp. 148-149).
inline bool deyAdaptIndefiniteWithPractice()
    { return true; }

// the adaptation permanence: the extra-slot cost buys a permanent adjustment
// if paid before the adaptation fades (printed pp. 148-149).
inline bool deyAdaptPermanentOption()
    { return true; }

// the adaptation freedom: the check requires only a moment's thought and does
// not prevent other actions (printed pp. 148-149).
inline bool deyAdaptNoOtherActionCost()
    { return true; }

// ---- the DMO all-around attack pins ----

// the all-around radius: the hail of blows damages every enemy within 5 feet
// (printed pp. 149-150).
inline int deyAAARadius()
    { return 5; }

// the all-around damage die: d8 per die of area damage (printed pp. 149-150).
inline int deyAAADamageDie()
    { return 8; }

// the all-around invisibility rule: invisible opponents can be harmed if
// their effective Armor Class after the -4 invisibility bonus is not better
// than the original target's (printed pp. 149-150).
inline int deyAAAInvisibilityAcBonus()
    { return 4; }

// the all-around damage ladder: warrior levels 10-14 band 0 (1d8 area
// damage), 15-19 band 1 (2d8), 20-24 band 2 (3d8), 25-29 band 3 (4d8), and 30
// or more the tail band 4 (5d8) - one die plus the band (printed pp.
// 149-150).
inline int deyAAADamageBand(int x)
    {
        if (x <= 14) return 0;
        if (x <= 19) return 1;
        if (x <= 24) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the all-around timing: must be announced in the round's player
// determination step (printed pp. 149-150).
inline bool deyAAAAnnouncedInDeterminationStep()
    { return true; }

// the all-around trigger: the radius damage comes only if the initial blow
// kills the opponent (printed pp. 149-150).
inline bool deyAAAKillTriggersBlast()
    { return true; }

// the all-around exclusion: enemies larger than the original target or with
// better Armor Class are not harmed (printed pp. 149-150).
inline bool deyAAALargerOrBetterAcExcluded()
    { return true; }

// the all-around immunity: opponents immune to the weapon used cannot be
// harmed (printed pp. 149-150).
inline bool deyAAAWeaponImmuneExcluded()
    { return true; }

// the all-around failure: if the initial attack misses, the all-around attack
// fails (printed pp. 149-150).
inline bool deyAAAInitialMissFails()
    { return true; }

// the all-around no-kill rule: damage that fails to kill leaves no radius
// effect (printed pp. 149-150).
inline bool deyAAANoKillNoRadius()
    { return true; }

// the all-around restriction: the warrior cannot move or take another action
// that round (printed pp. 149-150).
inline bool deyAAANoMoveOrOtherAction()
    { return true; }

// the all-around weapon set: any melee weapon the warrior is proficient with
// (printed pp. 149-150).
inline bool deyAAAMeleeProficientWeaponsOnly()
    { return true; }

// the all-around balance: beyond the initial attack, the warrior's combat
// bonuses are not a factor (printed pp. 149-150).
inline bool deyAAACombatBonusesIrrelevant()
    { return true; }

// ---- the DMO bravery pins ----

// the bravery drain: each use of captivate, frighten/challenge or hardiness
// reduces the base bravery score by two for the rest of the day (printed pp.
// 149-150).
inline int deyBraveryDerivedCost()
    { return 2; }

// the bravery effect: a successful check negates the fear effect - no saving
// throw necessary (printed pp. 149-150).
inline bool deyBraveryNegatesUnnaturalFear()
    { return true; }

// the bravery fallback: if the check fails the warrior still gets a saving
// throw if one is normally allowed (printed pp. 149-150).
inline bool deyBraverySaveStillAllowedOnFail()
    { return true; }

// the bravery paladin use: paladins can use it against turning attempts by
// evil priests (printed pp. 149-150).
inline bool deyBraveryPaladinVsEvilTurning()
    { return true; }

// the bravery prerequisite: printed verbatim, the skill is a prerequisite for
// the captivate, frighten/challenge, and invulnerability skills (the printed
// invulnerability wording held in both captures and the physical copy)
// (printed pp. 149-150).
inline bool deyBraveryPrereqForCaptivateFrightenInvulnerability()
    { return true; }

// the bravery exhaustion: once the base score falls to zero the character
// cannot use bravery or the other three skills for the rest of the day
// (printed pp. 149-150).
inline bool deyBraveryZeroBlocksAllFour()
    { return true; }

// ---- the DMO captivate pins ----

// the captivate suggestion: planted as the 3rd-level wizard spell (printed p.
// 150).
inline int deyCapSuggestionWizardLevel()
    { return 3; }

// the captivate gift: an appropriate gift or useful favor makes the saving
// throw at -4 (printed p. 150).
inline int deyCapGiftSavePenalty()
    { return 4; }

// the captivate immunity: creatures with 8 or more Hit Dice/levels are immune
// (printed p. 150).
inline int deyCapHdImmune()
    { return 8; }

// the captivate drain: each suggestion attempt reduces the base bravery score
// by two (printed p. 150).
inline int deyCapBraveryCost()
    { return 2; }

// the captivate baseline: children, members of the opposite sex and other
// warriors tend to be friendly toward the character when of the same race
// (printed p. 150).
inline bool deyCapSameRaceFriendly()
    { return true; }

// the captivate alignment: alignments are similar when they share one common
// element - law, neutrality, chaos, good or evil (printed p. 150).
inline bool deyCapSimilarAlignmentOneElement()
    { return true; }

// the captivate auto-suggestion: the NPC automatically obeys if the
// suggestion involves no risk, loss or embarrassment (printed p. 150).
inline bool deyCapSuggestionAutoIfNoRisk()
    { return true; }

// the captivate save outcome, printed verbatim: if the saving throw succeeds
// the NPC tries to flee from the warrior's presence (printed p. 150).
inline bool deyCapSuccessfulSaveFlees()
    { return true; }

// the captivate break: any hostile act or threat, including a failed
// suggestion, breaks the effect (printed p. 150).
inline bool deyCapHostileActBreaks()
    { return true; }

// the captivate attachment: extended personal contact lets the DM secretly
// roll for a troublesome NPC attachment (printed p. 150).
inline bool deyCapExtendedContactAttachment()
    { return true; }

// ---- the DMO death blow pins ----

// the death blow timing: must be announced in the round's player
// determination step (printed pp. 150-151).
inline bool deyDeathBlowAnnounced()
    { return true; }

// the death blow save: a hit deals normal damage and the opponent must save
// vs. death magic or be slain immediately (printed pp. 150-151).
inline bool deyDeathBlowSaveVsDeathMagic()
    { return true; }

// the death blow defense: protective device bonuses (magical armor, rings of
// protection) always apply to the save (printed pp. 150-151).
inline bool deyDeathBlowProtectiveDevicesApply()
    { return true; }

// the death blow option: the DM may use the Table 36 or Table 38 saving throw
// modifiers (printed pp. 150-151).
inline bool deyDeathBlowOptionalT36T38Modifiers()
    { return true; }

// the death blow immunity one: opponents with more Hit Dice/levels than the
// warrior are immune (printed pp. 150-151).
inline bool deyDeathBlowMoreHdImmune()
    { return true; }

// the death blow immunity two: creatures not normally vulnerable to the
// weapon are immune (printed pp. 150-151).
inline bool deyDeathBlowWeaponImmuneImmune()
    { return true; }

// the death blow restriction: it is the only attack the warrior can make that
// round (printed pp. 150-151).
inline bool deyDeathBlowOnlyAttackThatRound()
    { return true; }

// the death blow exception: attacks of opportunity are allowed (printed pp.
// 150-151).
inline bool deyDeathBlowAooAllowed()
    { return true; }

// the death blow combo: can be combined with an all-around attack (printed
// pp. 150-151).
inline bool deyDeathBlowCombinesAllAround()
    { return true; }

// the death blow combo limit: only the initial target of the all-around
// attack faces the instant death effect (printed pp. 150-151).
inline bool deyDeathBlowOnlyInitialTargetDies()
    { return true; }

// ---- the DMO frighten/challenge pins ----

// the frighten aura target: a group of creatures of 4 Hit Dice/levels or less
// (printed pp. 151-152).
inline int deyFrightAuraHd()
    { return 4; }

// the frighten flee duration: creatures flee for 1d10 additional rounds after
// pursuit ends (printed pp. 151-152).
inline int deyFrightFleeRoundsDie()
    { return 10; }

// the frighten friendly-save: creatures within 30 feet of a friendly creature
// immune to the aura get a saving throw vs. spell (printed pp. 151-152).
inline int deyFrightImmuneFriendRange()
    { return 30; }

// the frighten form: the warrior must shout and charge (printed pp. 151-152).
inline bool deyFrightShoutAndCharge()
    { return true; }

// the frighten senses: the creatures must see and hear the warrior (printed
// pp. 151-152).
inline bool deyFrightMustSeeAndHear()
    { return true; }

// the frighten immunity one: undead are not affected (printed pp. 151-152).
inline bool deyFrightUndeadImmune()
    { return true; }

// the frighten immunity two: creatures with no morale scores (conjured or
// summoned creatures under control) are not affected (printed pp. 151-152).
inline bool deyFrightNoMoraleImmune()
    { return true; }

// the frighten negation: a cloak of bravery spell negates the effect (printed
// pp. 151-152).
inline bool deyFrightCloakOfBraveryNegates()
    { return true; }

// the frighten natural 20: if the skill roll is a 20 the affected creatures
// attack the warrior instead (printed pp. 151-152).
inline bool deyFrightNatural20Attacks()
    { return true; }

// the frighten pursuit: if the warrior flees the creatures pursue as long as
// they can see him (printed pp. 151-152).
inline bool deyFrightWarriorFleesTheyPursue()
    { return true; }

// the challenge target: the creature must have at least 10 Hit Dice or levels
// (printed pp. 151-152).
inline int deyChallengeMinHd()
    { return 10; }

// the challenge range: about 100 yards if light and visibility are good
// (printed pp. 151-152).
inline int deyChallengeSightYards()
    { return 100; }

// the challenge modifier one: -6 to the skill score with no attempt to
// role-play the challenge (printed pp. 151-152).
inline int deyChallengeNoRoleplayPenalty()
    { return 6; }

// the challenge modifier two: -4 for only a feeble role-playing attempt
// (printed pp. 151-152).
inline int deyChallengeFeeblePenalty()
    { return 4; }

// the challenge modifier three: +1 to the opponent's Wisdom/Willpower per
// companion accompanying the warrior (printed pp. 151-152).
inline int deyChallengeCompanionBonus()
    { return 1; }

// the challenge modifier four: +1 for any damage plus an additional +1 per
// 10% of original hit points lost (printed pp. 151-152).
inline int deyChallengeDamageBonusStep()
    { return 10; }

// the challenge weak-powers modifier: +10 to the opponent's Wisdom/Willpower
// for creatures with weak combat powers (printed pp. 151-152).
inline int deyChallengeWeakBonus()
    { return 10; }

// the challenge weak definition one: THACO 14 or higher (printed pp.
// 151-152).
inline int deyChallengeWeakThaco()
    { return 14; }

// the challenge weak definition two: Armor Class 2 or worse (printed pp.
// 151-152).
inline int deyChallengeWeakAc()
    { return 2; }

// the challenge weak definition three: no physical attack inflicting more
// than 6 hit points of damage (printed pp. 151-152).
inline int deyChallengeWeakMaxDamage()
    { return 6; }

// the challenge both-fail retreat: the warrior stays away 1d4 rounds (printed
// pp. 151-152).
inline int deyChallengeRetreatRoundsDie()
    { return 4; }

// the challenge drain: each use of either form lowers the bravery skill by
// one for the rest of the day (printed pp. 151-152).
inline int deyChallengeBraveryCost()
    { return 1; }

// the frighten counter-morale: if the warrior attacks, the creatures
// automatically pass morale checks for the next 1d10 rounds (printed pp.
// 151-152).
inline int deyChallengeMoraleRoundsDie()
    { return 10; }

// the challenge roll: an opposed roll using the warrior's Charisma/Leadership
// against the target's Wisdom/Willpower (printed pp. 151-152).
inline bool deyChallengeOpposedChaVsWis()
    { return true; }

// the challenge compulsion: the winner's target must immediately advance and
// engage in physical combat unless restrained (printed pp. 151-152).
inline bool deyChallengeWinnerMustCloseToMelee()
    { return true; }

// the challenge restraint: restraint breaks the compulsion but keeps the
// creatures occupied a full round (printed pp. 151-152).
inline bool deyChallengeRestraintTakesFullRound()
    { return true; }

// the challenge break-off: unwilling creatures can save vs. spell each round
// to break off (printed pp. 151-152).
inline bool deyChallengeUnwillingSaveEachRound()
    { return true; }

// the challenge attack set: spells or missile weapons allowed, but the
// creature must close to melee range first (printed pp. 151-152).
inline bool deyChallengeSpellsMissilesAfterClosing()
    { return true; }

// the challenge natural 20: any roll of 20 is a failure regardless of the
// modified score (printed pp. 151-152).
inline bool deyChallengeNatural20AlwaysFails()
    { return true; }

// the challenge double fail: the warrior loses confidence and must retreat
// into cover or move away at top speed (printed pp. 151-152).
inline bool deyChallengeBothFailWarriorRetreats()
    { return true; }

// the challenge retreat out: the bravery skill can avoid the mandatory
// retreat (printed pp. 151-152).
inline bool deyChallengeBraveryAvoidsRetreat()
    { return true; }

// the challenge gaze: a fighter can use his intimidation gaze while issuing a
// challenge if the opponent is in range (printed pp. 151-152).
inline bool deyChallengeGazeCombosInRange()
    { return true; }

// ---- the DMO hardiness pins ----

// the hardiness minor recovery: unconsciousness for 1 day (printed pp.
// 152-153).
inline int deyHardMinorDays()
    { return 1; }

// the hardiness severe recovery: unconsciousness for 1 week (printed pp.
// 152-153).
inline int deyHardSevereWeeks()
    { return 1; }

// the hardiness extreme recovery: unconsciousness for 1 month (printed pp.
// 152-153).
inline int deyHardExtremeMonths()
    { return 1; }

// the hardiness heroic floor: a successful check lets the warrior fight until
// -20 hit points instead of dying at zero (printed pp. 152-153).
inline int deyHardHeroicFloor()
    { return -20; }

// the hardiness regen wake: regeneration to -19 or more during the delay
// restores consciousness (printed pp. 152-153).
inline int deyHardConsciousAt()
    { return -19; }

// the hardiness drain: each use lowers the base bravery score by two for the
// rest of the day (printed pp. 152-153).
inline int deyHardBraveryCost()
    { return 2; }

// the hardiness worked example: a 17th-level fighter with 34 of 115 hit
// points delays power word kill (printed pp. 152-153).
inline int deyHardExampleLevel()
    { return 17; }

// the hardiness worked example hit points left: 34 (printed pp. 152-153).
inline int deyHardExampleHpLeft()
    { return 34; }

// the hardiness worked example hit point total: 115 (printed pp. 152-153).
inline int deyHardExampleHpTotal()
    { return 115; }

// the hardiness worked example delay: five rounds, then heal lifts him over
// 60 hit points and the power word kill fizzles (printed pp. 152-153).
inline int deyHardExampleDelay()
    { return 5; }

// the hardiness worked example immunity: over 60 hit points carries immunity
// to power word kill (printed pp. 152-153).
inline int deyHardExampleImmuneHp()
    { return 60; }

// the hardiness multi-effect example: a vampire drained two levels, a lich
// added paralysis (printed pp. 152-153).
inline int deyHardVampireLevels()
    { return 2; }

// the hardiness paralysis recovery: another week for the paralysis (printed
// pp. 152-153).
inline int deyHardParalysisWeeks()
    { return 1; }

// the hardiness nine-week sum: one month per drained level plus the paralysis
// week (printed pp. 152-153).
inline int deyHardExampleWeeks()
    { return 9; }

// the hardiness delay ladder: warrior levels 15-19 band 0 (5 rounds of
// delay), 20-24 band 1 (10), 25-29 band 2 (15), and 30 or more the tail band
// 3 (20) - five rounds times one plus the band (printed pp. 152-153).
inline int deyHardDelayBand(int x)
    {
        if (x <= 19) return 0;
        if (x <= 24) return 1;
        if (x <= 29) return 2;
        return 3;
    }

// the hardiness save order: if the effect allows a saving throw the warrior
// rolls the save before checking the skill (printed pp. 152-153).
inline bool deyHardSaveFirst()
    { return true; }

// the hardiness exclusion one: no delay of simple damage from any source,
// including continuing damage such as Melf's acid arrow or a sword of
// wounding (printed pp. 152-153).
inline bool deyHardNoSimpleOrContinuingDamage()
    { return true; }

// the hardiness exclusion two: no protection against effects not directly
// harmful such as magical charms, entanglement or imprisonment (printed pp.
// 152-153).
inline bool deyHardNoCharmsEntangleImprison()
    { return true; }

// the hardiness cure window: the appropriate cure before the delay ends means
// no harm (printed pp. 152-153).
inline bool deyHardCureWithinDelayNoHarm()
    { return true; }

// the hardiness short effects: an effect whose duration is shorter than the
// delay never lands (printed pp. 152-153).
inline bool deyHardShorterDurationNoEffect()
    { return true; }

// the hardiness recovery roll: a system shock roll at the end of the recovery
// time (printed pp. 152-153).
inline bool deyHardSystemShockAtEnd()
    { return true; }

// the hardiness success: a successful system shock awakens the character
// fully healed, the delayed magic nullified (printed pp. 152-153).
inline bool deyHardShockSuccessHeals()
    { return true; }

// the hardiness failure: a failed system shock means the full force of the
// effect (printed pp. 152-153).
inline bool deyHardShockFailFullForce()
    { return true; }

// the hardiness stacking: multiple effects mean system shock rolls at the end
// of each recovery period, no awakening until all are made (printed pp.
// 152-153).
inline bool deyHardMultipleEffectsSequential()
    { return true; }

// the hardiness sleeping cure: a cure applied while unconscious recovers the
// character immediately and automatically (printed pp. 152-153).
inline bool deyHardUnconsciousRecoversInstantly()
    { return true; }

// the heroic effort duration: the warrior functions at negative hit points
// for rounds equal to the delay (printed pp. 152-153).
inline bool deyHardHeroicDelayRounds()
    { return true; }

// the heroic effort price: reduced to -20 or less the character dies once the
// delay expires (printed pp. 152-153).
inline bool deyHardHeroicDeathAtDelayEnd()
    { return true; }

// the heroic rescue: a raise dead or resurrection cast during the delay
// prevents death (printed pp. 152-153).
inline bool deyHardRaiseDuringDelaySaves()
    { return true; }

// the regeneration clause: a character returned to life through regeneration
// need not make a system shock roll (printed pp. 152-153).
inline bool deyHardRegenNoShock()
    { return true; }

// the amulet clause: an amulet of life protection works like regeneration
// with no system shock roll (printed pp. 152-153).
inline bool deyHardAmuletNoShock()
    { return true; }

// the hardiness gate: the skill is ineffective once the base bravery score is
// zero or less (printed pp. 152-153).
inline bool deyHardIneffectiveAtZeroBravery()
    { return true; }

// ---- the DMO inner focus pins ----

// the inner focus duration: the improvement lasts one round per character
// level (printed pp. 153-154).
inline int deyFocusBoostDurationPerLevel()
    { return 1; }

// the inner focus cost: the other two eligible ability scores drop by two for
// the same duration (printed pp. 153-154).
inline int deyFocusOtherScoresPenalty()
    { return 2; }

// the inner focus extraordinary rule: an extraordinary Strength score of
// 18/01-18/00 reduces to 16 (printed pp. 153-154).
inline int deyFocusExtraordinaryFloor()
    { return 16; }

// the inner focus drain: each attempt, successful or not, lowers the base
// skill score by two for the day (printed pp. 153-154).
inline int deyFocusAttemptCost()
    { return 2; }

// the inner focus ladder: warrior levels 10-14 band 0 (boost to 18, 18/00
// under the subabilities rule), 15-19 band 1 (19), 20-24 band 2 (20), 25-29
// band 3 (21), and 30 or more the tail band 4 (22) - the improved score is 18
// plus the band (printed pp. 153-154).
inline int deyFocusBand(int x)
    {
        if (x <= 14) return 0;
        if (x <= 19) return 1;
        if (x <= 24) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the inner focus limit: only one ability score improvement can operate at
// any given time (printed pp. 153-154).
inline bool deyFocusOneBoostAtATime()
    { return true; }

// the inner focus round: no other actions while concentrating one round to
// raise the score (printed pp. 153-154).
inline bool deyFocusConcentrationRoundOnlyAction()
    { return true; }

// the inner focus control: the warrior can end the boost and restore the
// other scores at any time (printed pp. 153-154).
inline bool deyFocusBoostEndsAtWill()
    { return true; }

// the inner focus ceiling: no effect if the ability score is already higher
// than the table value (printed pp. 153-154).
inline bool deyFocusNoEffectIfAlreadyHigher()
    { return true; }

// the inner focus subabilities: under the optional rule both subabilities of
// the boosted score rise to the same value (printed pp. 153-154).
inline bool deyFocusSubabilitiesRaisedEqual()
    { return true; }

// ---- the DMO sense danger pins ----

// the sense danger ambush scan: an area roughly 200 yards square in a single
// round (printed pp. 154-155).
inline int deySenseAmbushScanYards()
    { return 200; }

// the sense danger readiness cube: a 30-foot cube of battle-readiness per
// round (printed pp. 154-155).
inline int deySenseReadinessCube()
    { return 30; }

// the sense danger hidden radius: invisible, ethereal, astral, out-of-phase
// or hidden creatures within 30 feet (printed pp. 154-155).
inline int deySenseHiddenRadius()
    { return 30; }

// the sense danger hidden cost: a +1 initiative penalty on the round the
// hidden-enemy sense is used (printed pp. 154-155).
inline int deySenseHiddenInitPenalty()
    { return 1; }

// the sense danger proficiency synergy: the alertness proficiency grants a +1
// bonus to the skill score (printed pp. 154-155).
inline int deySenseAlertnessBonus()
    { return 1; }

// the size-up low bar: hit points 20% or less of the warrior's and THACO at
// least 15 points higher (printed pp. 154-155).
inline int deySenseLowHpPct()
    { return 20; }

// the size-up low THACO difference: at least 15 points higher (printed pp.
// 154-155).
inline int deySenseLowThacoDiff()
    { return 15; }

// the size-up moderate bar: hit points 21-50% of the warrior's or THACO at
// least 10 points higher (printed pp. 154-155).
inline int deySenseModerateHpPct()
    { return 50; }

// the size-up moderate THACO difference: at least 10 points higher (printed
// pp. 154-155).
inline int deySenseModerateThacoDiff()
    { return 10; }

// the size-up significant bar: hit points 51-70% of the warrior's and THACO
// at least 5 points higher (printed pp. 154-155).
inline int deySenseSignificantHpPctLow()
    { return 51; }

// the size-up significant ceiling: up to 70% of the warrior's hit points
// (printed pp. 154-155).
inline int deySenseSignificantHpPctHigh()
    { return 70; }

// the size-up significant THACO difference: at least 5 points higher (printed
// pp. 154-155).
inline int deySenseSignificantThacoDiff()
    { return 5; }

// the size-up dangerous bar: hit points 71-100% of the warrior's and THACO
// less than 5 points higher, but not lower (printed pp. 154-155).
inline int deySenseDangerousHpPctLow()
    { return 71; }

// the size-up dangerous ceiling: up to 100% of the warrior's hit points
// (printed pp. 154-155).
inline int deySenseDangerousHpPctHigh()
    { return 100; }

// the sense danger secret roll: a fail at 19 or less detects nothing, a
// natural 20 a false indication (printed pp. 154-155).
inline int deySenseFailThreshold()
    { return 19; }

// the sense danger subskill ladder: levels 15-19 band 0 (one subskill known),
// 20-24 band 1 (two), 25-29 band 2 (three), and 30 or more the tail band 3
// (four) - one subskill plus the band (printed pp. 154-155).
inline int deySenseKnownBand(int x)
    {
        if (x <= 19) return 0;
        if (x <= 24) return 1;
        if (x <= 29) return 2;
        return 3;
    }

// the sense danger structure: the skill is actually five different subskills
// (printed pp. 154-155).
inline bool deySenseFiveSubskills()
    { return true; }

// the sense danger double purchase: buying the skill twice grants one extra
// subskill (printed pp. 154-155).
inline bool deySenseDoublePurchaseExtraSubskill()
    { return true; }

// the sense danger spread: any improvement to the skill number improves all
// known subskills (printed pp. 154-155).
inline bool deySenseImprovementAllSubskills()
    { return true; }

// the ambush scan cadence: an area can be scanned only once each turn
// (printed pp. 154-155).
inline bool deySenseAmbushOncePerTurn()
    { return true; }

// the ambush scan yield: approximately how many creatures are hiding and
// their approximate size (printed pp. 154-155).
inline bool deySenseAmbushRevealsCountAndSize()
    { return true; }

// the back-attack defense: success negates surprise and all rear-attack
// bonuses including a thief's backstab (printed pp. 154-155).
inline bool deySenseBackNegatesSurpriseAndBonuses()
    { return true; }

// the back-attack dexterity: Dexterity/Balance defensive bonuses apply even
// without turning (printed pp. 154-155).
inline bool deySenseBackDexBonusApplies()
    { return true; }

// the back-attack shield: shield bonuses apply only if the character turns
// around (printed pp. 154-155).
inline bool deySenseBackShieldOnlyIfTurns()
    { return true; }

// the back-attack limit: unlike the barbarian's back protection, no free
// counterattack (printed pp. 154-155).
inline bool deySenseNoFreeCounterattack()
    { return true; }

// the hidden-enemy cadence: one check per round (printed pp. 154-155).
inline bool deySenseHiddenOncePerRound()
    { return true; }

// the hidden-enemy limit: no disguised creatures in plain sight, no
// intentions revealed (printed pp. 154-155).
inline bool deySenseHiddenNoDisguiseOrIntent()
    { return true; }

// the sense danger roll: the DM should roll the check secretly (printed pp.
// 154-155).
inline bool deySenseDmSecretRoll()
    { return true; }

// the sense danger plain fail: a fail at 19 or less means the character
// detects nothing (printed pp. 154-155).
inline bool deySenseFail19DetectsNothing()
    { return true; }

// the sense danger false read: a fail on a 20 gives a false indication
// (printed pp. 154-155).
inline bool deySenseNatural20FalseIndication()
    { return true; }

// the false-read limit: a false indication has no effect on a back attack
// (printed pp. 154-155).
inline bool deySenseFalseNoBackAttackEffect()
    { return true; }

// the size-up ambiguity: a creature qualifying for more than one category
// lets the DM choose which is detected (printed pp. 154-155).
inline bool deySenseDmChoosesCategory()
    { return true; }

// the size-up deadly bar: more hit points and a lower THACO than the warrior
// (printed pp. 154-155).
inline bool deySenseDeadlyMoreHpLowerThaco()
    { return true; }

// the size-up limit: no indication of magical abilities, innate powers or
// breath weapons (printed pp. 154-155).
inline bool deySenseNoMagicOrSpellPowers()
    { return true; }

// ---- the DMO signature item pins ----

// the signature item ownership: the usual period is one level's worth of
// advancement (printed pp. 155-156).
inline int deySigItemOwnLevels()
    { return 1; }

// the signature item nonmagical replacement: indistinguishable from the
// original after about one month (printed pp. 155-156).
inline int deySigItemReplacementMonths()
    { return 1; }

// the signature item magical replacement: the character loses five times the
// item's experience point value (printed pp. 155-156).
inline int deySigItemMagicXpMultiple()
    { return 5; }

// the signature item re-enchantment: the new item matches the original after
// about one month (printed pp. 155-156).
inline int deySigItemEnchantMonths()
    { return 1; }

// the signature item categories: armor, weapon, shield and miscellaneous
// magical item - one item each (printed pp. 155-156).
inline int deySigItemCategories()
    { return 4; }

// the signature item vision: one skill check per day to see a lost or stolen
// item's location (printed pp. 155-156).
inline int deySigItemVisionChecksPerDay()
    { return 1; }

// the signature item designation: give it a name and note something
// distinctive (printed pp. 155-156).
inline bool deySigItemNamedAndDistinctive()
    { return true; }

// the signature item designation roll: no skill check required (printed pp.
// 155-156).
inline bool deySigItemNoCheckToDesignate()
    { return true; }

// the signature item link: as soon as it is designated, described and named
// the warrior forms an empathic link (printed pp. 155-156).
inline bool deySigItemEmpathicLinkOnNaming()
    { return true; }

// the signature item habit: owned for an extended period and used regularly
// (printed pp. 155-156).
inline bool deySigItemMustOwnAndUseRegularly()
    { return true; }

// the signature item form: only nonconsumable items qualify, rechargeables
// allowed (printed pp. 155-156).
inline bool deySigItemNonconsumableOnly()
    { return true; }

// the signature item protection: item saving throws automatically succeed
// while the owner carries the item and survives the event (printed pp.
// 155-156).
inline bool deySigItemItemSavesAutoSucceed()
    { return true; }

// the signature item condition: the auto-save holds only if the owner
// survives the event (printed pp. 155-156).
inline bool deySigItemOwnerMustSurvive()
    { return true; }

// the signature item destruction: deliberate actions leading to item saving
// throws can destroy it (printed pp. 155-156).
inline bool deySigItemDeliberateActsCanDestroy()
    { return true; }

// the signature item lapse: if the owner does not survive the item rolls
// normally, and a link broken by the same event stays broken (printed pp.
// 155-156).
inline bool deySigItemDeadOwnerNormalRoll()
    { return true; }

// the signature item vision limit: an item on another plane shows only the
// plane (printed pp. 155-156).
inline bool deySigItemOtherPlanePlaneOnly()
    { return true; }

// the signature item hidden vision: a magically hidden item reveals the fact
// and its general location (printed pp. 155-156).
inline bool deySigItemMagicallyHiddenFactAndArea()
    { return true; }

// the signature item cheap replacement: a similar item with the same name
// re-forms the link (printed pp. 155-156).
inline bool deySigItemNonmagicalReplacementByName()
    { return true; }

// the signature item magical replacement: an item of quality plus a
// successful skill check recreates the enchantment (printed pp. 155-156).
inline bool deySigItemMagicalNeedsQualityAndCheck()
    { return true; }

// the signature item refusal: unwilling to pay the experience cost breaks the
// link (printed pp. 155-156).
inline bool deySigItemXpLossOrBrokenLink()
    { return true; }

// the signature item artifact bar: artifacts cannot be restored in this
// manner (printed pp. 155-156).
inline bool deySigItemArtifactsExcluded()
    { return true; }

// the signature item count: one item from each of the four categories, each
// at full cost (printed pp. 155-156).
inline bool deySigItemOnePerCategory()
    { return true; }

// the signature item pairs: at the DM's option pairs of magical items might
// qualify as one (printed pp. 155-156).
inline bool deySigItemPairsAtDmOption()
    { return true; }

// the signature item spread: improving the skill score applies to all
// signature equipment (printed pp. 155-156).
inline bool deySigItemImprovementAllItems()
    { return true; }

// the signature item neglect: voluntarily giving it away or not making a
// reasonable recovery effort breaks the link (printed pp. 155-156).
inline bool deySigItemNeglectBreaksLink()
    { return true; }

// ---- the DMO signature mount pins ----

// the signature mount size: no more than 10 Hit Dice (printed p. 156).
inline int deySigMountMaxHd()
    { return 10; }

// the signature mount toughness: at least four hit points per Hit Die
// (printed p. 156).
inline int deySigMountMinHpPerHd()
    { return 4; }

// the signature mount example: the 5+5 heavy war horse needs at least 25 hit
// points (printed p. 156).
inline int deySigMountHeavyWarHorseMinHp()
    { return 25; }

// the signature mount link bonus: one hit point per character level at the
// link, plus one more each level gained (printed p. 156).
inline int deySigMountHpPerLevel()
    { return 1; }

// the signature mount clever mount: Intelligence 5 or more need not be
// trained if it willingly serves (printed p. 156).
inline int deySigMountSmartInt()
    { return 5; }

// the signature mount vision: one skill check per day to see a replacement
// mount (printed p. 156).
inline int deySigMountVisionChecksPerDay()
    { return 1; }

// the signature mount training: it must be tamed and recognize the warrior as
// master (printed p. 156).
inline bool deySigMountMustBeTamed()
    { return true; }

// the signature mount naming: the warrior must name it and make it
// recognizable (printed p. 156).
inline bool deySigMountMustBeNamedAndRecognizable()
    { return true; }

// the signature mount area save: no damage from area attacks if the rider
// saves (printed p. 156).
inline bool deySigMountAreaNoDamageIfRiderSaves()
    { return true; }

// the signature mount half: if the rider fails but survives, the mount saves
// for half or no damage using the rider's number (printed p. 156).
inline bool deySigMountHalfOrNoneOnRiderFail()
    { return true; }

// the signature mount direct save: effects targeted at the mount use the
// rider's save while they are together (printed p. 156).
inline bool deySigMountDirectAttacksUseRiderSave()
    { return true; }

// the signature mount power words: must be potent enough to overcome the
// rider, affecting only the mount if targeted there (printed p. 156).
inline bool deySigMountPowerWordMustOvercomeRider()
    { return true; }

// the signature mount alone: without the rider it uses its own save and
// suffers normal effects (printed p. 156).
inline bool deySigMountAloneOwnSave()
    { return true; }

// the signature mount death: a new mount of the same type and hit points can
// be acquired (printed p. 156).
inline bool deySigMountKilledSameTypeReplacement()
    { return true; }

// the signature mount terrain rule: one mount per different type of terrain
// (printed p. 156).
inline bool deySigMountOnePerTerrain()
    { return true; }

// the signature mount service: it willingly serves the warrior once obtained
// (printed p. 156).
inline bool deySigMountWillinglyServesIfFound()
    { return true; }

}   // namespace rules
