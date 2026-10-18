// =========================================================================================
// Adnd1 - rules/dmohighrogues.h
// ROGUES BEYOND 20TH - DMO Chapter 7, round four of five: the rogue
// advancement grid (the printed body caption reads Table 47 - the same number
// the priest spell progression caption printed - with 2,200,000 XP at 20th in
// 220K steps and the printed 120K final step to 4,300,000 at 30th, weapon and
// nonweapon proficiencies, the 10+N d6 hit points with the
// Con-bonus-after-10th footnote), the thieving doctrine (the 95 percent cap
// below 11th, no limit from 11th, 96-or-higher automatic failure, penalties
// from the base score), the five new thieving skills with their base scores
// and the racial, Dexterity-aim and armor adjustment grids (Tables 48 through
// 51), the thief powers (five skills at 21st, 50 S&P character points with
// the 9-skill overflow rule, the 24th-level scroll ladder at 25 percent), the
// bard powers (two skills at 21st, 20 points, the 21st-level scroll ladder at
// 15 percent, 55 percent item identification, wands at 24th, item creation at
// 27th) with the Table 52 bard spell progression, and all eleven rogue skills
// (adaptation, classify traps, evasion, fall and jump, featherfoot,
// improvised attack, inner focus, nondetection, sense danger, shadow flight
// and shadow travel).
// census 533 -> 534.
//
// verified against printed pp. 167-177 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns, the djvu.txt full texts; the tsr02156
// ABBYY read is primary and the tesseract read is cross-checked; leaf N =
// printed page N). TWO contested cells settled against the physical copy
// (user-confirmed 2026-10-18): the Table 47 level-30 experience print reads
// 4,300,000 (the ABBYY read; tesseract read 4,500,000 and the series would
// give 4,400,000) with the final step only 120,000 points; and the Table 50
// tunneling row prints a dash at Dexterity 17 and +30 percent at Dexterity 22
// (the tesseract read; the ABBYY capture dropped the final cell). TWO more
// printed quirks held: the rogue advancement caption shares the printed
// number 47 with the priest spell progression caption (whose contents entry
// reads 46); and the Table 49 halfling detect magic cell prints +5 without
// the percent sign its row siblings carry.
//
// the gap census after this round: 90 closed, 6 open - one Chapter 7 child
// flips in round four of five (the parent stays open until R612); the DMO arc
// closes with R612 (Demihumans + Beyond 30th / Divine Ascension, pp. 178-179)
// then the Appendix and Index.
//
namespace rules {

// ---- the DMO rogue doctrine pins ----

// the rogue skills gate: rogues also have access to a host of special skills
// beginning at 11th level (printed p. 167).
inline int dfaRogueSkillStartLevel()
    { return 11; }

// the rogue advancement ceiling: rogues continue to receive extra
// proficiencies and hit points until level 30 (printed p. 167).
inline int dfaRogueAdvLimit()
    { return 30; }

// the rogue power note: rogues receive extra abilities at 21st level (printed
// p. 167).
inline int dfaRogueExtraAbilityLevel()
    { return 21; }

// the thieving score cap: rogues of 10th level or lower are limited to scores
// of 95 percent or less in thieving skills (printed p. 167).
inline int dfaThiefScoreCap()
    { return 95; }

// the thieving cap lift: once a rogue reaches 11th level the 95 percent
// limitation is removed and there is no limit to how far a skill can be
// improved (printed p. 167).
inline int dfaThiefCapLiftLevel()
    { return 11; }

// the thieving auto-fail roll: no matter what the skill score, any roll of 96
// percent or higher is an automatic failure (printed p. 167).
inline int dfaThiefAutoFailRoll()
    { return 96; }

// the thieving cap doctrine: once a single skill reaches 95 percent the
// character must spend discretionary points on other skills (printed p. 167).
inline bool dfaThief95CapSpendElsewhere()
    { return true; }

// the thieving cap doctrine: if all the thieving skill scores are 95 percent,
// the discretionary points are lost (printed p. 167).
inline bool dfaThiefAll95PointsLost()
    { return true; }

// the thieving cap doctrine: discretionary points the character lost earlier
// are not regained when the cap is lifted at 11th level (printed p. 167).
inline bool dfaThiefLostPointsNotRegained()
    { return true; }

// the thieving penalty rule: any penalties to the roll are subtracted from
// the base score (printed p. 167).
inline bool dfaThiefPenaltiesFromBase()
    { return true; }

// the Jobare find/remove traps score: 120 percent (printed p. 167).
inline int dfaJobareTrapScore()
    { return 120; }

// the Jobare magical trap chance: a 120 percent score gives a 60 percent
// chance because magical traps reduce the score by half (printed p. 167).
inline int dfaJobareMagicalTrapChance()
    { return 60; }

// the Jobare open locks score: 100 percent (printed p. 167).
inline int dfaJobareLockScore()
    { return 100; }

// the masterful lock penalty: a masterful lock imposes a penalty of 60
// percent (printed p. 167).
inline int dfaJobareMasterfulPenalty()
    { return 60; }

// the Jobare masterful lock chance: the 100 percent score less the 60 percent
// penalty leaves a 40 percent chance (printed p. 167).
inline int dfaJobareMasterfulChance()
    { return 40; }

// ---- the DMO rogue advancement pins ----

// the Table 47 row count: eleven levels from 20th through 30th (printed p.
// 168).
inline int dfaT47RowCount()
    { return 11; }

// the Table 47 experience base: 2,200,000 experience points at 20th level
// (printed p. 168).
inline int dfaT47XpBase()
    { return 2200000; }

// the Table 47 experience step: 220,000 experience points per level from 21st
// through 29th (printed p. 168).
inline int dfaT47XpStep()
    { return 220000; }

// the Table 47 30th-level experience print: 4,300,000 points - the ABBYY
// capture reads 4,300,000, the tesseract capture reads 4,500,000, and the
// series would give 4,400,000; settled against the physical copy,
// user-confirmed 2026-10-18, and the printed value 4,300,000 is held (printed
// p. 168).
inline int dfaT47Xp30()
    { return 4300000; }

// the Table 47 printed quirk: the final 29th-to-30th experience step is only
// 120,000 points, not the 220,000-point series the first ten steps follow
// (settled against the physical copy, user-confirmed 2026-10-18) (printed p.
// 168).
inline bool dfaT47FinalStepShort()
    { return true; }

// the Table 47 hit-point base: the constant 10 of the printed 10-plus-N d6
// hit-point cells (printed p. 168).
inline int dfaT47HpBase()
    { return 10; }

// the Table 47 hit-point step: the per-level bonus climbs from 20 to 40 in
// plus-two steps (printed p. 168).
inline int dfaT47HpStep()
    { return 2; }

// the Table 47 footnote: bonus hit points from high Constitution scores are
// not added after 10th level - the rogue footnote reads 10TH where the
// warrior and wizard tables read 9th (pinned verbatim) (printed p. 168).
inline bool dfaT47ConBonusStopsAfter10()
    { return true; }

// the Table 47 caption duplication: this body caption prints Table 47, the
// same printed number the priest spell progression body caption uses on
// printed p. 161 (whose contents entry reads Table 46) - the printed book
// numbers two different tables 47 (printed pp. 161, 168).
inline bool dfaT47CaptionSharesPrintedNumber()
    { return true; }

// the experience column: 2,200,000 at 20th in 220,000 steps to 4,180,000 at
// 29th, then the printed 120,000 final step to 4,300,000 at 30th (printed p.
// 168).
inline int dfaT47Xp(int b)
    {
        switch (b) {
        case 0:
            return 2200000;
        case 1:
            return 2420000;
        case 2:
            return 2640000;
        case 3:
            return 2860000;
        case 4:
            return 3080000;
        case 5:
            return 3300000;
        case 6:
            return 3520000;
        case 7:
            return 3740000;
        case 8:
            return 3960000;
        case 9:
            return 4180000;
        case 10:
            return 4300000;
        default:
            return -99;
        }
    }

// the weapon proficiency column: 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9 across
// levels 20-30 (printed p. 168).
inline int dfaT47WeaponProf(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 8;
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

// the nonweapon proficiency column: 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10 - one
// more every four levels (printed p. 168).
inline int dfaT47NonweaponProf(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 10;
        default:
            return -99;
        }
    }

// the hit-point base column: the constant 10 of the printed 10-plus-N cells
// (printed p. 168).
inline int dfaT47HpBaseCol(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 10;
        default:
            return -99;
        }
    }

// the hit-point bonus column: 20 at 20th rising in plus-two steps to 40 at
// 30th (printed p. 168).
inline int dfaT47HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 22;
        case 2:
            return 24;
        case 3:
            return 26;
        case 4:
            return 28;
        case 5:
            return 30;
        case 6:
            return 32;
        case 7:
            return 34;
        case 8:
            return 36;
        case 9:
            return 38;
        case 10:
            return 40;
        default:
            return -99;
        }
    }

// ---- the DMO thieving grids ----

// the new thieving skill count: at 21st level a thief gains five new skills
// (printed p. 168).
inline int dfaNewThiefSkillCount()
    { return 5; }

// the bribe base chance: 5 percent (printed p. 169).
inline int dfaBribeBase()
    { return 5; }

// the detect illusion base chance: 10 percent (printed p. 169).
inline int dfaDetectIllusionBase()
    { return 10; }

// the detect magic base chance: 5 percent (printed p. 169).
inline int dfaDetectMagicBase()
    { return 5; }

// the escape bonds base chance: 10 percent (printed p. 169).
inline int dfaEscapeBondsBase()
    { return 10; }

// the tunneling base chance: 15 percent (printed p. 169).
inline int dfaTunnelingBase()
    { return 15; }

// the new thieving skill doctrine: the character can immediately apply
// discretionary points to the new skills (printed p. 168).
inline bool dfaNewSkillsApplyPointsImmediately()
    { return true; }

// the Table 49 printed quirk: the halfling detect magic cell prints +5
// without the percent sign its row siblings carry (pinned per the primary
// ABBYY capture; the value is unchanged) (printed p. 169).
inline bool dfaT49HalflingDetectMagicNoPercent()
    { return true; }

// the Table 50 printed quirk: the tunneling row prints a dash at Dexterity 17
// and jumps from +20 percent at 21 to +30 percent at 22 with no +25 percent
// cell - the tesseract capture reads the full row, the ABBYY capture drops
// the final cell; settled against the physical copy, user-confirmed
// 2026-10-18 (printed p. 170).
inline bool dfaT50TunnelingDashAt17()
    { return true; }

// the Table 49 row count: five skills (printed p. 169).
inline int dfaT49RowCount()
    { return 5; }

// the Table 50 row count: two skills (escape bonds and tunneling) (printed p.
// 170).
inline int dfaT50RowCount()
    { return 2; }

// the Table 51 row count: three skills (printed p. 170).
inline int dfaT51RowCount()
    { return 3; }

// the dwarf column: minus 5 on bribe, plus 5 on detect illusion, plus 5 on
// detect magic, no escape bonds adjustment, plus 10 on tunneling (printed p.
// 169).
inline int dfaT49Dwarf(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 0;
        case 4:
            return 10;
        default:
            return -99;
        }
    }

// the elf column: plus 15 on bribe, no detect illusion adjustment, plus 10 on
// detect magic, no escape bonds adjustment, minus 10 on tunneling (printed p.
// 169).
inline int dfaT49Elf(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 0;
        case 4:
            return -10;
        default:
            return -99;
        }
    }

// the gnome column: plus 5 on bribe, plus 10 on detect illusion, plus 5 on
// detect magic, no escape bonds adjustment, plus 5 on tunneling (printed p.
// 169).
inline int dfaT49Gnome(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 0;
        case 4:
            return 5;
        default:
            return -99;
        }
    }

// the half-elf column: plus 5 on bribe, plus 5 on detect illusion, plus 5 on
// detect magic, no escape bonds adjustment, minus 5 on tunneling (printed p.
// 169).
inline int dfaT49Halfelf(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 0;
        case 4:
            return -5;
        default:
            return -99;
        }
    }

// the halfling column: no bribe, detect illusion or detect magic adjustment
// beyond the printed +5 cell, plus 10 on escape bonds, plus 5 on tunneling
// (printed p. 169).
inline int dfaT49Halfling(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        default:
            return -99;
        }
    }

// the human column: no racial adjustments on any of the five skills (printed
// p. 169).
inline int dfaT49Human(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// the Dexterity 9 column: escape bonds minus 15, tunneling minus 10 (printed
// p. 170).
inline int dfaT50Dex9(int b)
    {
        switch (b) {
        case 0:
            return -15;
        case 1:
            return -10;
        default:
            return -99;
        }
    }

// the Dexterity 10 column: escape bonds minus 10, tunneling minus 5 (printed
// p. 170).
inline int dfaT50Dex10(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -5;
        default:
            return -99;
        }
    }

// the Dexterity 11 column: escape bonds minus 5, tunneling no adjustment
// (printed p. 170).
inline int dfaT50Dex11(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// the Dexterity 12-16 column: no adjustment on either skill (printed p. 170).
inline int dfaT50Dex1216(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// the Dexterity 17 column: escape bonds plus 5, tunneling the printed dash
// (no adjustment) (printed p. 170).
inline int dfaT50Dex17(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// the Dexterity 18 column: escape bonds plus 10, tunneling plus 5 (printed p.
// 170).
inline int dfaT50Dex18(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 5;
        default:
            return -99;
        }
    }

// the Dexterity 19 column: escape bonds plus 15, tunneling plus 10 (printed
// p. 170).
inline int dfaT50Dex19(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 10;
        default:
            return -99;
        }
    }

// the Dexterity 20 column: escape bonds plus 20, tunneling plus 15 (printed
// p. 170).
inline int dfaT50Dex20(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        default:
            return -99;
        }
    }

// the Dexterity 21 column: escape bonds plus 25, tunneling plus 20 (printed
// p. 170).
inline int dfaT50Dex21(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        default:
            return -99;
        }
    }

// the Dexterity 22 column: escape bonds plus 30, tunneling the printed plus
// 30 (printed p. 170).
inline int dfaT50Dex22(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 30;
        default:
            return -99;
        }
    }

// the no armor column: bribe minus 10, escape bonds plus 5, tunneling plus 10
// (printed p. 170).
inline int dfaT51NoArmor(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return 5;
        case 2:
            return 10;
        default:
            return -99;
        }
    }

// the elven chain column: bribe plus 5, escape bonds minus 5, tunneling minus
// 5 (printed p. 170).
inline int dfaT51ElvenChain(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return -5;
        case 2:
            return -5;
        default:
            return -99;
        }
    }

// the padded or studded leather column: bribe minus 5, escape bonds minus 5,
// tunneling minus 10 (printed p. 170).
inline int dfaT51Leather(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -5;
        case 2:
            return -10;
        default:
            return -99;
        }
    }

// ---- the DMO bribe skill pins ----

// the bribe status table row count: four NPC stations (printed pp. 168-169).
inline int dfaBribeRowCount()
    { return 4; }

// the bribe doctrine: only one bribe can be attempted per target (printed pp.
// 168-169).
inline bool dfaBribeOneAttemptPerTarget()
    { return true; }

// the bribe doctrine: if the attempt fails the DM makes a reaction roll for
// the target to determine how he counters the bribe (printed pp. 168-169).
inline bool dfaBribeFailReactionRoll()
    { return true; }

// the bribe doctrine: the DM must decide if the NPC in question can be bribed
// - not everyone is susceptible (printed pp. 168-169).
inline bool dfaBribeNotEveryoneSusceptible()
    { return true; }

// the bribe doctrine: no character can be bribed to do something that falls
// outside his job or station (printed pp. 168-169).
inline bool dfaBribeNotOutsideStation()
    { return true; }

// the bribe doctrine: a bribed NPC does not perform any action that takes
// more than a few minutes of effort or places himself in danger - the task
// must strike the character as quick and harmless (printed pp. 168-169).
inline bool dfaBribeNeverDangerousOrLong()
    { return true; }

// the bribe doctrine: a simple bribe never induces a character to compromise
// something he believes in (printed pp. 168-169).
inline bool dfaBribeNeverAgainstBeliefs()
    { return true; }

// the bribe procedure: secretly roll 1d20 against Table 59 of the Dungeon
// Master Guide and do not tell the player the reaction - simply role play the
// response (printed pp. 168-169).
inline bool dfaBribeSecretReactionRoll()
    { return true; }

// the bribe procedure: if the reaction roll is friendly the NPC probably does
// what the thief wants without a bribe (printed pp. 168-169).
inline bool dfaBribeFriendlyNeedsNoBribe()
    { return true; }

// the bribe procedure: the amount required is the status table roll
// multiplied by the difference between the reaction roll and the highest
// number on Table 59 that is a friendly result (printed pp. 168-169).
inline bool dfaBribeMultiplyByDifference()
    { return true; }

// the bribe procedure: the player should never be told the NPC station, the
// base bribe value, or the initial reaction roll (printed p. 169).
inline bool dfaBribePlayerNeverToldValues()
    { return true; }

// the bribe dice column: 2d4 for a peasant or slave, 3d8 for a freeman or
// soldier, 5d10 for a merchant or officer, 5d100 for a noble or general
// (printed pp. 168-169).
inline int dfaBribeDice(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 5;
        default:
            return -99;
        }
    }

// the bribe die size column: the second number of each dice notation - 4, 8,
// 10 and 100 (printed pp. 168-169).
inline int dfaBribeSides(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 100;
        default:
            return -99;
        }
    }

// the Jobare bribe example reaction roll: a 13 on the first column of Table
// 59 makes the peasant cautious (printed p. 169).
inline int dfaJobareReactionRoll()
    { return 13; }

// the Jobare bribe example friendly ceiling: the highest number that gives a
// friendly result on the first column of Table 59 is a 7 (printed p. 169).
inline int dfaJobareFriendlyMax()
    { return 7; }

// the Jobare bribe example difference: 13 minus 7 leaves 6 (printed p. 169).
inline int dfaJobareBribeDiff()
    { return 6; }

// the Jobare bribe example base value: the secret 2d4 roll comes up 5 copper
// pieces (printed p. 169).
inline int dfaJobareBaseBribeCp()
    { return 5; }

// the Jobare bribe example payment: 5 times 6 makes at least 30 copper pieces
// for an effective bribe (printed p. 169).
inline int dfaJobarePaidCp()
    { return 30; }

// ---- the DMO detect, bonds and tunneling pins ----

// the detect illusion range: thieves can see through visible illusions within
// their line of sight up to 90 feet away (printed p. 169).
inline int dfaDetectIllusionRange()
    { return 90; }

// the detect illusion doctrine: detection is not automatic - the thief must
// spend a round concentrating on the area of effect (printed p. 169).
inline bool dfaDetectIllusionNeedsRound()
    { return true; }

// the detect illusion doctrine: the thief perceives the illusion as a
// translucent image, as though it were a light mist - the more real the
// illusion the more solid the image (printed p. 169).
inline bool dfaDetectIllusionTranslucent()
    { return true; }

// the detect illusion doctrine: invisibility and other nonvisible effects
// cannot be discerned (printed p. 169).
inline bool dfaDetectIllusionNotVsNonvisible()
    { return true; }

// the detect illusion doctrine: knowing that something is an illusion is not
// necessarily a fail-safe defense, such as in the case of a simulacrum
// (printed p. 169).
inline bool dfaDetectIllusionNotFailSafe()
    { return true; }

// the detect magic range: thieves can spot magical emanations within their
// line of sight up to 60 feet away (printed p. 169).
inline int dfaDetectMagicRange()
    { return 60; }

// the detect magic intensity ladder: dim, faint, moderate, strong and
// overwhelming - five intensity levels (printed p. 169).
inline int dfaDetectMagicIntensityCount()
    { return 5; }

// the detect magic doctrine: the ability can be blocked by the same things
// that prevent detect magic spells from operating (printed p. 169).
inline bool dfaDetectMagicBlockedLikeSpell()
    { return true; }

// the escape bonds timing: the skill takes five rounds to use (printed p.
// 169).
inline int dfaEscapeBondsRounds()
    { return 5; }

// the escape bonds hurry penalty: the thief suffers a minus 5 percent penalty
// for each round shaved from the required time (printed p. 169).
inline int dfaEscapeBondsHurryPenalty()
    { return 5; }

// the escape bonds doctrine: the thief must roll to break free of every
// device binding him - tied at wrists and ankles means two successful rolls
// (printed p. 169).
inline bool dfaEscapeBondsRollPerDevice()
    { return true; }

// the escape bonds doctrine: locked items also require the thief to
// successfully pick the locks (printed p. 169).
inline bool dfaEscapeBondsLockedNeedPicks()
    { return true; }

// the escape bonds doctrine: a failure on any attempt means the thief cannot
// loosen that bond or pick the lock (printed p. 169).
inline bool dfaEscapeBondsFailCantRetryThatBond()
    { return true; }

// the tunneling chunk: the table shows the time required to dig a 10 foot
// tunnel with adequate tools, and every 10 feet requires a skill check
// (printed p. 169).
inline int dfaTunnelChunkFeet()
    { return 10; }

// the tunneling doctrine: a failed skill check means the front of the tunnel
// collapses (printed p. 169).
inline bool dfaTunnelCollapseOnFail()
    { return true; }

// the tunneling doctrine: a collapsed tunnel can be re-dug at the loose earth
// rate (printed p. 169).
inline bool dfaTunnelRedugAtLooseRate()
    { return true; }

// the tunneling earth table row count: three earth types (printed p. 169).
inline int dfaTunnelRowCount()
    { return 3; }

// the earth modifier column: minus 10 for sand or loose earth, zero for
// packed earth, plus 10 for rock (printed p. 169).
inline int dfaTunnelMod(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return 0;
        case 2:
            return 10;
        default:
            return -99;
        }
    }

// the earth hours column: 5 hours for sand or loose earth, 10 for packed
// earth, 30 for rock (printed p. 169).
inline int dfaTunnelHours(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 30;
        default:
            return -99;
        }
    }

// ---- the DMO thief 21st-level powers pins ----

// the thief S&P bonus: if the Skills and Powers character point system is in
// play the thief gains 50 bonus character points at 21st level to buy
// thieving skills from Table 27 (printed p. 170).
inline int dfaThiefSkillBonusCp()
    { return 50; }

// the thief S&P overflow gate: if the thief already has 9 or more of the
// Table 27 skills the points go to proficiencies and high-level rogue skills
// instead (printed p. 170).
inline int dfaThiefSpSkillThreshold()
    { return 9; }

// the thief S&P doctrine: a thief who already has 9 or more of the listed
// skills cannot spend all 50 points on thieving skills (printed p. 170).
inline bool dfaThiefSpOverflowToProficiencies()
    { return true; }

// the thief doctrine: the ability to acquire additional thieving skills is a
// special bonus for reaching 21st level - it is not normally possible to gain
// additional thieving skills after the character is created (printed p. 170).
inline bool dfaThiefExtraSkillsOnlyAt21st()
    { return true; }

// the thief scroll gate: at 24th level a thief begins to develop an
// understanding of magic and can read some spell scrolls (printed p. 170).
inline int dfaThiefScrollLevel()
    { return 24; }

// the thief scroll failure: scroll spells of higher level than the listed
// level have the standard 25 percent chance for a reversed or harmful effect
// (printed p. 170).
inline int dfaThiefScrollFailPct()
    { return 25; }

// the thief scroll doctrine: there is no chance for failure when reading a
// scroll of the listed level or less (printed p. 170).
inline bool dfaThiefScrollNoFailAtOrBelow()
    { return true; }

// the thief scroll ladder: thief levels 23 or less band 0 (no scroll use),
// 24-26 band 1 (1st-level scrolls), 27-28 band 2 (2nd-level scrolls), and 29
// or more the tail band 3 (3rd-level scrolls) (printed p. 170).
inline int dfaThiefScrollBand(int x)
    {
        if (x <= 23) return 0;
        if (x <= 26) return 1;
        if (x <= 28) return 2;
        return 3;
    }

// ---- the DMO bard powers pins ----

// the bard new skill count: at 21st level a bard gains two of the five new
// skills listed in the thief section (printed pp. 170-171).
inline int dfaBardNewSkillCount()
    { return 2; }

// the bard new skill gate: the two new thieving skills arrive at 21st level
// (printed pp. 170-171).
inline int dfaBardNewSkillLevel()
    { return 21; }

// the bard S&P bonus: under the Skills and Powers system the bard gains 20
// bonus character points at 21st level (printed p. 170).
inline int dfaBardSkillBonusCp()
    { return 20; }

// the bard scroll gate: also at 21st level a bard can read wizard spells from
// scrolls with no chance of failure provided the bard is high enough level to
// cast the spell (printed pp. 170-171).
inline int dfaBardScrollLevel()
    { return 21; }

// the bard scroll failure: the bard has the standard 15 percent chance for a
// reversed or harmful effect when reading wizard spells of higher level than
// castable or priest spells above the table level (printed pp. 170-171).
inline int dfaBardScrollFailPct()
    { return 15; }

// the bard scroll doctrine: wizard scrolls of a level the bard can cast are
// read with no chance of failure (printed pp. 170-171).
inline bool dfaBardScrollWizardNoFailIfCastable()
    { return true; }

// the bard scroll ladder: bard levels 20 or less band 0 (no scroll use),
// 21-23 band 1 (1st), 24-26 band 2 (2nd), 27-29 band 3 (3rd), and 30 or more
// the tail band 4 (4th-level scrolls) (printed pp. 170-171).
inline int dfaBardScrollBand(int x)
    {
        if (x <= 20) return 0;
        if (x <= 23) return 1;
        if (x <= 26) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the bard item identification gate: at 21st level a bard can analyze magical
// items and determine something about their specific powers (printed p. 171).
inline int dfaBardIdentifyLevel()
    { return 21; }

// the bard item identification chance: for each hour spent studying an item
// the character has a 55 percent chance to determine a single power (printed
// p. 171).
inline int dfaBardIdentifyChance()
    { return 55; }

// the bard item identification limit: the item exact magical bonuses and
// number of charges are never revealed (printed p. 171).
inline bool dfaBardIdentifyNoBonusesCharges()
    { return true; }

// the bard item identification doctrine: the bard need not handle the item or
// expend any materials - merely examining it closely (printed p. 171).
inline bool dfaBardIdentifyNoHandling()
    { return true; }

// the bard magical item use gate: at 24th level a bard can use wands, staves
// and rods as a wizard of the same level (printed p. 171).
inline int dfaBardItemUseLevel()
    { return 24; }

// the bard item creation gate: at 27th level a bard can write wizard spells
// the character knows and brew potions as a wizard of the same level (printed
// p. 171).
inline int dfaBardItemCreationLevel()
    { return 27; }

// the Table 52 row count: eleven levels from 20th through 30th (printed p.
// 171).
inline int dfaT52RowCount()
    { return 11; }

// the 1st-level column: 4 through 24th, 5 from 25th, 6 from 28th (printed p.
// 171).
inline int dfaT52L1(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        default:
            return -99;
        }
    }

// the 2nd-level column: 4 through 24th, 5 from 26th, 6 at 30th (printed p.
// 171).
inline int dfaT52L2(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 6;
        default:
            return -99;
        }
    }

// the 3rd-level column: 3 at 20th, 4 from 21st, 5 from 26th, 6 at 30th
// (printed p. 171).
inline int dfaT52L3(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 6;
        default:
            return -99;
        }
    }

// the 4th-level column: 4 through 25th, 5 from 26th, 6 at 30th (printed p.
// 171).
inline int dfaT52L4(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 6;
        default:
            return -99;
        }
    }

// the 5th-level column: 4 through 25th, 5 from 26th (printed p. 171).
inline int dfaT52L5(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        default:
            return -99;
        }
    }

// the 6th-level column: 3 at 20th, 4 from 21st, 5 from 28th (printed p. 171).
inline int dfaT52L6(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        default:
            return -99;
        }
    }

// the 7th-level column: the printed dash at 20th, then 1 at 21st climbing to
// 5 at 28th (printed p. 171).
inline int dfaT52L7(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        default:
            return -99;
        }
    }

// the 8th-level column: the printed dashes through 28th, then 1 at 29th and
// 30th (printed p. 171).
inline int dfaT52L8(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        default:
            return -99;
        }
    }

// ---- the DMO rogue skills: adaptation and traps ----

// the adaptation doctrine: except where noted the rogue skill is identical to
// the warrior skill of the same name (printed p. 171).
inline bool dfaAdaptLikeWarriorSkill()
    { return true; }

// the adaptation initiative note: successful rogues do not suffer combat and
// initiative penalties for fighting in an unfavorable environment, most
// notably the plus 6 foreign environment penalty to initiative (printed p.
// 171).
inline int dfaAdaptInitPenaltyAvoided()
    { return 6; }

// the adaptation check bonus: if the environment includes special saving
// throws or ability checks due to physical conditions, characters
// successfully using the skill receive a plus 3 (or plus 15 percent) bonus to
// the check (printed p. 171).
inline int dfaAdaptCheckBonus()
    { return 3; }

// the adaptation vision penalty: characters who cannot observe their
// surroundings suffer a minus 4 penalty to the skill check (printed p. 171).
inline int dfaAdaptBlindCheckPenalty()
    { return 4; }

// the adaptation practice: the effect can be extended indefinitely if the
// character practices fighting in the environment for at least 8 hours a week
// (printed p. 171).
inline int dfaAdaptPracticeHours()
    { return 8; }

// the adaptation permanent cost: at an extra cost of one weapon or nonweapon
// proficiency slot (or three character points) the character can become
// permanently adjusted to fighting in the environment (printed p. 172).
inline int dfaAdaptPermanentCp()
    { return 3; }

// the adaptation limit: the skill does not allow characters to ignore
// situational movement penalties or environmental factors that are not combat
// related, or conditions that are physically impossible to overcome (printed
// p. 171).
inline bool dfaAdaptNoSituationalOrNoncombat()
    { return true; }

// the adaptation limit: the skill has no effect on penalties derived from an
// environment magical properties or on penalties based on vision or lighting
// (printed p. 171).
inline bool dfaAdaptNoMagicalOrVisionPenalties()
    { return true; }

// the adaptation procedure: at the end of each round in combat the character
// checks the skill - it requires only a moment thought, can be checked every
// round until successful, and does not prevent other actions (printed pp.
// 171-172).
inline bool dfaAdaptCheckEachRound()
    { return true; }

// the adaptation duration: once the skill succeeds the character temporarily
// ignores the environment special effects for the entire battle plus one day
// per character level thereafter (printed p. 172).
inline bool dfaAdaptLastsBattlePlusDays()
    { return true; }

// the adaptation permanent gate: the permanent adjustment holds only if the
// additional cost is paid before the adaptation fades (printed p. 172).
inline bool dfaAdaptPermanentBeforeFade()
    { return true; }

// the classify traps limit: the skill is useless without the find traps
// ability (printed pp. 171-172).
inline bool dfaClassifyNeedsFindTraps()
    { return true; }

// the classify traps doctrine: a successful roll reveals the trap exact
// nature - how it works, what it does to people who trigger it, and where its
// attacks are aimed provided the rogue can observe those areas (printed pp.
// 171-172).
inline bool dfaClassifyRevealsExactNature()
    { return true; }

// the classify traps timing: the examination requires at least a turn for
// basic constructs and possibly much longer for very elaborate traps (printed
// p. 172).
inline int dfaClassifyExamTurns()
    { return 1; }

// the classify traps limit: a magical or invisible trap reduces the rogue
// success number, including ability score bonuses, by half with fractions
// rounded up (printed p. 172).
inline bool dfaClassifyMagicalHalvedRoundUp()
    { return true; }

// the classify traps false assumption: a roll of 20 means the rogue has made
// a false assumption about what the trap does (printed p. 172).
inline int dfaClassifyFalseRoll()
    { return 20; }

// the classify traps doctrine: a failed roll of less than 20 means the rogue
// cannot determine anything special about the trap (printed p. 172).
inline bool dfaClassifyFailUnder20LearnsNothing()
    { return true; }

// the classify traps doctrine: the DM should make the skill roll secretly
// (printed p. 172).
inline bool dfaClassifySecretRoll()
    { return true; }

// the classify traps disarm option: after a successful examination the
// character can make two remove traps rolls taking only the best result
// (printed p. 172).
inline bool dfaClassifyTwoRemoveRollsBest()
    { return true; }

// the classify traps bypass option: the rogue can trigger the trap from a
// safe place - if complete avoidance is impossible the rogue saves vs. breath
// weapon, is unharmed on success, and takes half damage on failure (printed
// p. 172).
inline bool dfaClassifyBypassSaveVsBreath()
    { return true; }

// the classify traps evasion note: if the rogue also has the evasion skill
// the character gets a plus 2 bonus to the saving throw (printed p. 172).
inline int dfaClassifyEvasionSaveBonus()
    { return 2; }

// the classify traps companion option: companions warned by the rogue can
// attempt breath weapon saving throws to avoid the effects and suffer only
// half damage on a failed save (printed p. 172).
inline bool dfaClassifyCompanionsMaySave()
    { return true; }

// the classify traps doctrine: when a trap attack cannot have a half effect
// the DM can require another saving throw against the trap attack form or
// rule that characters are fully effected when they fail the breath weapon
// saving throw (printed p. 172).
inline bool dfaClassifyNoHalfEffectRuling()
    { return true; }

// ---- the DMO rogue skills: evasion and fall/jump ----

// the evasion doctrine: the skill operates automatically whenever a rogue is
// subjected to an energy attack that causes damage (printed p. 172).
inline bool dfaEvasionAutomatic()
    { return true; }

// the evasion doctrine: the rogue rolls a normal saving throw vs. the effect
// and suffers no damage if it is successful (printed p. 172).
inline bool dfaEvasionNoDamageOnSave()
    { return true; }

// the evasion limit: the skill is not effective against effects that do not
// inflict damage or that do not normally allow a saving throw - a bronze
// dragon repulsion breath, a gorgon petrifying breath or magic missile spells
// (printed p. 172).
inline bool dfaEvasionNotVsNonDamage()
    { return true; }

// the evasion missile rule: the rogue can avoid missiles fired from fixed
// points such as traps and siege engines, but not from creatures (printed p.
// 172).
inline bool dfaEvasionFixedMissilesOnly()
    { return true; }

// the evasion missile rule: if not surprised the rogue avoids the missile
// with a successful saving throw vs. breath weapon (printed p. 172).
inline bool dfaEvasionNeedsNotSurprised()
    { return true; }

// the fall/jump safe distance base: 30 feet plus 30 feet per band - 30 at
// 11th to 210 at 30th (printed pp. 172-173).
inline int dfaFallSafeBase()
    { return 30; }

// the fall/jump surface distance column count: seven level bands (printed pp.
// 172-173).
inline int dfaFallSurfaceRowCount()
    { return 7; }

// the fall/jump level ladder: rogue levels 11-13 band 0 (30 feet), 14-16 band
// 1 (60), 17-19 band 2 (90), 20-21 band 3 (120), 22-24 band 4 (150), 25-27
// band 5 (180), and 28 or more the tail band 6 (210) - the safe fall distance
// is 30 feet plus 30 feet per band (printed pp. 172-173).
inline int dfaFallBand(int x)
    {
        if (x <= 13) return 0;
        if (x <= 16) return 1;
        if (x <= 19) return 2;
        if (x <= 21) return 3;
        if (x <= 24) return 4;
        if (x <= 27) return 5;
        return 6;
    }

// the fall/jump surface rule: rogues who simply step off a precipice or fall
// while climbing are always within one foot of a vertical surface unless it
// has a negative slope (printed p. 173).
inline bool dfaFallAlwaysWithinOneFoot()
    { return true; }

// the fall/jump surface rule: any surface that can provide a reasonable
// amount of friction is sufficient (ropes, tree trunks, walls) while very
// smooth or slippery surfaces are useless (ice walls, greased poles, walls of
// force) (printed p. 173).
inline bool dfaFallFrictionSurfacesOk()
    { return true; }

// the fall/jump damage rule: if the fall is longer than the safe distance
// allowed for the rogue level, subtract the safe distance from the total
// distance before determining damage from the fall (printed p. 173).
inline bool dfaFallDamageOnExcess()
    { return true; }

// the surface distance column: 1, 2, 3, 5, 7, 9 and 11 feet across the seven
// level bands (printed pp. 172-173).
inline int dfaFallSurface(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 9;
        case 6:
            return 11;
        default:
            return -99;
        }
    }

// the Jobare shaft example level: a 20th level thief whose skill roll
// succeeds (printed p. 173).
inline int dfaJobareFallLevel()
    { return 20; }

// the Jobare shaft example: the shaft goes down 150 feet (printed p. 173).
inline int dfaJobareShaftFeet()
    { return 150; }

// the Jobare shaft example: the shaft opens into a chamber 30 feet high
// (printed p. 173).
inline int dfaJobareChamberFeet()
    { return 30; }

// the Jobare shaft example: the 20th level thief breaks only the first 120
// feet of his fall (printed p. 173).
inline int dfaJobareBreakFeet()
    { return 120; }

// the Jobare shaft example: the final 60 feet of the fall go unbroken (150
// plus 30 less 120) (printed p. 173).
inline int dfaJobareFinalFeet()
    { return 60; }

// the Jobare shaft example damage: 6d6 points of damage for the final 60 feet
// (printed p. 173).
inline int dfaJobareFallDice()
    { return 6; }

// the Jobare shaft example damage die: d6 (printed p. 173).
inline int dfaJobareFallSides()
    { return 6; }

// the Jobare shaft example 30th-level note: even a 30th level thief would
// suffer 3d6 because there was no surface within reach to break the final 30
// feet (printed p. 173).
inline int dfaJobare30thDice()
    { return 3; }

// the Jobare shaft example 30th-level note: the chamber has no wall within
// reach for the final 30 feet (printed p. 173).
inline int dfaJobare30thFeet()
    { return 30; }

// ---- the DMO rogue skills: featherfoot and improvised attack ----

// the featherfoot gate: the skill is a function of the rogue move silently
// ability, which is a requirement for using this skill (printed p. 173).
inline bool dfaFeatherNeedsMoveSilently()
    { return true; }

// the featherfoot level ladder: rogue levels 11-13 band 0 (soft surfaces),
// 14-16 band 1 (very soft surfaces), and 17 or more the tail band 2 (liquid
// surfaces) (printed p. 173).
inline int dfaFeatherBand(int x)
    {
        if (x <= 13) return 0;
        if (x <= 16) return 1;
        return 2;
    }

// the featherfoot grid row count: three surface bands (printed p. 173).
inline int dfaFeatherRowCount()
    { return 3; }

// the featherfoot limit: the rogue must stop and make contact with the
// surface after moving the allowed distance (printed p. 173).
inline bool dfaFeatherMustStopAtDistance()
    { return true; }

// the featherfoot doctrine: the character moves in complete silence and
// leaves no tracks on the ground, and the character weight does not press
// down upon the surface at all (printed p. 173).
inline bool dfaFeatherSilentNoTracks()
    { return true; }

// the featherfoot doctrine: the character does not set off any alarm or trap
// triggered by weight and does not trigger a squeaking floors spell (printed
// p. 173).
inline bool dfaFeatherNoWeightTriggers()
    { return true; }

// the surface distance column: 30 feet over soft, 60 over very soft, 120 over
// liquid (printed p. 173).
inline int dfaFeatherDistance(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 60;
        case 2:
            return 120;
        default:
            return -99;
        }
    }

// the movement column: movement rate 12 over soft, 15 over very soft, 18 over
// liquid (printed p. 173).
inline int dfaFeatherMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 18;
        default:
            return -99;
        }
    }

// the improvised attack allotment: a rogue can use this skill only once a
// day, but can learn the skill multiple times - three learnings give three
// improvised attacks each day (printed p. 174).
inline int dfaImprovisedDailyPerLearning()
    { return 1; }

// the improvised attack doctrine: each time the rogue learns the skill again
// the daily allotment grows by one (printed p. 174).
inline bool dfaImprovisedLearnMultipleTimes()
    { return true; }

// the improvised attack blinding effect: the opponent suffers the full
// penalties for darkness - minus 4 to attacks, saving throws and Armor Class,
// with movement reduced to one third (printed p. 174).
inline int dfaImprovisedBlindPenalty()
    { return 4; }

// the improvised attack blinding clear roll: the blinding effect lasts until
// the opponent clears his vision, which requires a roll of 9 or less on 1d20
// (printed p. 174).
inline int dfaImprovisedBlindClearRoll()
    { return 9; }

// the improvised attack blinding note: the blindfighting proficiency does not
// reduce the penalties, and many creatures cannot be blinded because they
// have no visual organs (printed p. 174).
inline bool dfaImprovisedBlindfightingNoHelp()
    { return true; }

// the improvised attack disarm effect: the opponent saves vs. petrification
// or loses the use of one weapon; recovering a dropped weapon takes a half
// move and a stuck weapon needs a successful open doors roll (printed p.
// 174).
inline bool dfaImprovisedDisarmStuckNeedsOpenDoors()
    { return true; }

// the improvised attack immobilize effect: the opponent works free only on a
// roll of 9 or less on 1d20 (printed p. 174).
inline int dfaImprovisedImmobFreeRoll()
    { return 9; }

// the improvised attack kill effect offset: a failed save vs. death magic
// reduces the creature hit points to minus ten instantly - the offset ten is
// pinned (printed p. 174).
inline int dfaImprovisedKillHpOffset()
    { return 10; }

// the improvised attack kill limit: opponents with more Hit Dice or a higher
// level than the rogue are immune to kill effects and take normal damage
// (printed p. 174).
inline bool dfaImprovisedKillHigherHdImmune()
    { return true; }

// the improvised attack stun duration dice: 2d4 rounds (printed p. 174).
inline int dfaImprovisedStunDice()
    { return 2; }

// the improvised attack stun die: d4 (printed p. 174).
inline int dfaImprovisedStunSides()
    { return 4; }

// the improvised attack stun penalty: the stunned character suffers a minus 2
// penalty to Armor Class, attack rolls, saving throws and ability checks
// (printed p. 174).
inline int dfaImprovisedStunPenalty()
    { return 2; }

// the improvised attack stun doctrine: a stunned character is unable to cast
// spells, attack, or move at more than half speed (printed p. 174).
inline bool dfaImprovisedStunNoSpellsAttack()
    { return true; }

// the improvised attack trip damage: creatures that fall while moving at
// speeds greater than 12 might suffer minor damage - 1d3 at the DM option
// (printed p. 174).
inline int dfaImprovisedTripLowSides()
    { return 3; }

// the improvised attack trip damage: 1d6 points at the DM option (printed p.
// 174).
inline int dfaImprovisedTripHighSides()
    { return 6; }

// the improvised attack procedure: the attack must be announced in the
// declaration phase and described exactly in the resolution phase - a simple
// called shot never qualifies (printed p. 174).
inline bool dfaImprovisedAnnounceDeclareDescribe()
    { return true; }

// the improvised attack procedure: the rogue makes a normal attack roll with
// standard combat modifiers; the backstab bonus applies to rear attacks, the
// Dexterity/Aim missile bonus usually applies, and Strength/Muscle bonuses
// apply to blows (printed p. 174).
inline bool dfaImprovisedNormalAttackRoll()
    { return true; }

// the improvised attack doctrine: if the attack succeeds the opponent suffers
// no damage but must roll a saving throw or suffer the special effect
// (printed p. 174).
inline bool dfaImprovisedSuccessNoDamage()
    { return true; }

// the improvised attack save modifier: plus 6 if the rogue player made no
// attempt to role play or describe the attack (printed p. 174).
inline int dfaImprovisedSaveNoRoleplay()
    { return 6; }

// the improvised attack save modifier: plus 4 if the rogue player makes only
// a feeble attempt to role play or describe the attack (printed p. 174).
inline int dfaImprovisedSaveFeeble()
    { return 4; }

// the improvised attack save modifier: plus 2 to plus 6 if the attack
// described is physically unlikely to have the desired effect (printed p.
// 174).
inline bool dfaImprovisedSaveUnlikelyRange()
    { return true; }

// the improvised attack save modifier: the save is automatic if the method
// described is completely inadequate (printed p. 174).
inline bool dfaImprovisedSaveAutoIfInadequate()
    { return true; }

// the improvised attack save modifier: plus 2 if the rogue has used the same
// trick earlier in the adventure (printed p. 174).
inline int dfaImprovisedSaveTrickAdventure()
    { return 2; }

// the improvised attack save modifier: plus 4 if the rogue has used the trick
// earlier in the same encounter (printed p. 174).
inline int dfaImprovisedSaveTrickEncounter()
    { return 4; }

// the improvised attack save modifier: plus 6 if the rogue has used the trick
// on the same creature during this adventure (printed p. 174).
inline int dfaImprovisedSaveSameCreatureAdventure()
    { return 6; }

// the improvised attack save modifier: plus 8 if the rogue has used the trick
// on the same creature this encounter (printed p. 174).
inline int dfaImprovisedSaveSameCreatureEncounter()
    { return 8; }

// the improvised attack save modifier: minus 2 if the opponent is surprised
// (printed p. 174).
inline int dfaImprovisedSaveSurprised()
    { return 2; }

// the improvised attack save modifier: minus 4 if the attack described is
// particularly appropriate (printed p. 174).
inline int dfaImprovisedSaveAppropriate()
    { return 4; }

// the improvised attack option: the optional saving throw modifiers from
// Table 36 or Table 38 can be applied if the DM wishes (printed p. 174).
inline bool dfaImprovisedTable3638Optional()
    { return true; }

// the improvised attack trick establishment: if a rogue has successfully used
// the same improvised attack in three separate adventures the character can
// purchase the skill again at the next level to make the trick a permanent
// part of the character skills (printed p. 174).
inline bool dfaImprovisedTrickThreeAdventures()
    { return true; }

// the improvised attack trick doctrine: an established trick can be used once
// per encounter without the usual penalty for multiple use, though
// situational penalties still apply (printed p. 174).
inline bool dfaImprovisedTrickOncePerEncounter()
    { return true; }

// the improvised attack trick doctrine: using an established trick does not
// count toward the daily allotment unless the trick is used more than once in
// a single encounter (printed p. 174).
inline bool dfaImprovisedTrickNotDailyAllotment()
    { return true; }

// the improvised attack trick doctrine: opponents who have fought the rogue
// previously and are prepared for an established trick gain a plus 6 saving
// throw bonus against it (printed p. 174).
inline bool dfaImprovisedTrickPreparedPlus6()
    { return true; }

// the Jobare trick hat example: the surprised man rolls a 2 on the surprise
// die (printed p. 174).
inline int dfaJobareSurpriseRoll()
    { return 2; }

// the Jobare trick hat example: the DM and player agree the clamped hat is a
// blinding attack, the attack succeeds, and the man fails his save vs. breath
// weapon at minus 2 - later Jobare establishes the trick hat as a permanent
// skill (printed p. 174).
inline bool dfaJobareHatBlindExample()
    { return true; }

// ---- the DMO rogue skills: focus and nondetection ----

// the inner focus doctrine: the rogue skill marshals personal energies to
// provide a temporary bonus to Dexterity, Intelligence or Constitution scores
// and is otherwise similar to the warrior skill of the same name (printed p.
// 175).
inline bool dfaFocusLikeWarriorSkill()
    { return true; }

// the inner focus boost ladder: rogue levels 11-15 band 0 (boost to 18),
// 16-20 band 1 (19), 21-25 band 2 (20), and 26 or more the tail band 3 (21) -
// the improved score is 18 plus the band (printed p. 175).
inline int dfaFocusBand(int x)
    {
        if (x <= 15) return 0;
        if (x <= 20) return 1;
        if (x <= 25) return 2;
        return 3;
    }

// the inner focus boost base: the improved score is 18 plus the band - 18,
// 19, 20 and 21 across the ladder (printed p. 175).
inline int dfaFocusBoostBase()
    { return 18; }

// the inner focus other penalty: the other two eligible ability scores are
// reduced by two points each while the boost lasts (printed p. 175).
inline int dfaFocusOtherPenalty()
    { return 2; }

// the inner focus duration: the improvement lasts one round per character
// level (printed p. 175).
inline int dfaFocusDurationPerLevel()
    { return 1; }

// the inner focus drain: each attempt, successful or not, during a single day
// lowers the base skill score by two (printed p. 175).
inline int dfaFocusAttemptCost()
    { return 2; }

// the inner focus ceiling: if the character ability score is already higher
// than the value listed on the table this skill has no effect - the priest
// wording again, not the wizard equal to or higher (pinned verbatim) (printed
// p. 175).
inline bool dfaFocusAlreadyHigherNoEffect()
    { return true; }

// the inner focus doctrine: the rogue can end the boost - and restore the
// values of the other two ability scores - at any time (printed p. 175).
inline bool dfaFocusEndAtWill()
    { return true; }

// the inner focus doctrine: under the optional subabilities rule both
// subabilities scores in the increased ability are raised to the same value
// (printed p. 175).
inline bool dfaFocusSubabilitiesRaisedEqual()
    { return true; }

// the inner focus limit: a character can have only one ability score
// improvement from this skill operating at any given time (printed p. 175).
inline bool dfaFocusOneBoostAtATime()
    { return true; }

// the inner focus procedure: the rogue can take no other actions during the
// round spent concentrating on raising the selected ability score (printed p.
// 175).
inline bool dfaFocusNoOtherActions()
    { return true; }

// the inner focus doctrine: bonuses from an increased score are applied
// immediately when the skill succeeds and are immediately lost when the boost
// duration ends - reduced score effects are likewise restored when the
// improvement ends (printed p. 175).
inline bool dfaFocusBonusesImmediate()
    { return true; }

// the nondetection spell: rogues can shield themselves from many types of
// magical divination as the 3rd level wizard spell of the same name (printed
// p. 176).
inline int dfaNondetectionSpellLevel()
    { return 3; }

// the nondetection doctrine: a successful skill check defeats a spell such as
// ESP, clairaudience or detect invisibility, or a magical item such as a
// crystal ball (printed p. 176).
inline bool dfaNondetectionBeatsDivinations()
    { return true; }

// the nondetection doctrine: even if the roll fails the rogue is still
// entitled to any applicable saving throws (printed p. 176).
inline bool dfaNondetectionSavesEvenOnFail()
    { return true; }

// the nondetection reach: the skill is also effective against the sense
// danger skill (printed p. 176).
inline bool dfaNondetectionBeatsSenseDanger()
    { return true; }

// the nondetection reach: the skill is also effective against the priest
// detect deception skill (printed p. 176).
inline bool dfaNondetectionBeatsDetectDeception()
    { return true; }

// the nondetection procedure: when subjected to one of these powers the rogue
// can attempt an opposed Wisdom/Willpower check to remain undetected (printed
// p. 176).
inline bool dfaNondetectionOpposedWillpower()
    { return true; }

// the nondetection limit: the skill is not effective against know alignment,
// true seeing, commune or contact other plane (printed p. 176).
inline bool dfaNondetectionNotVsFourSpells()
    { return true; }

// the nondetection limit: the skill is not effective against the detection
// abilities of legendary monsters, wyrm and great wyrm dragons, or deities
// (printed p. 176).
inline bool dfaNondetectionNotVsLegendaryOrDeities()
    { return true; }

// ---- the DMO rogue skills: sense danger and shadows ----

// the sense danger subskill count: four subskills - ambushes, concealed
// weapons, hostile intentions and impending attacks (printed p. 176).
inline int dfaSenseSubskillCount()
    { return 4; }

// the sense danger subskill ladder: rogue levels 15 or less band 0 (skill
// unavailable), 16-20 band 1 (one subskill), 21-25 band 2 (two subskills),
// and 26 or more the tail band 3 (three subskills) - the subskill count is
// the band (printed pp. 176-177).
inline int dfaSenseBand(int x)
    {
        if (x <= 15) return 0;
        if (x <= 20) return 1;
        if (x <= 25) return 2;
        return 3;
    }

// the sense danger doctrine: if the character purchases this skill twice the
// rogue gains one extra subskill (printed p. 176).
inline bool dfaSenseSecondPurchaseExtra()
    { return true; }

// the sense danger doctrine: any improvement to the skill number improves all
// the subskills the character knows (printed p. 176).
inline bool dfaSenseImprovesAllSubskills()
    { return true; }

// the sense danger ambush scan: the rogue can scan an area roughly 200 yards
// square in a single round (printed p. 176).
inline int dfaSenseAmbushYards()
    { return 200; }

// the sense danger ambush limit: an area can be scanned only once each turn
// (printed p. 176).
inline bool dfaSenseAmbushOncePerTurn()
    { return true; }

// the sense danger ambush doctrine: a successful scan reveals approximately
// how many creatures are hiding in the area and their approximate size
// (printed p. 176).
inline bool dfaSenseAmbushRevealsCountAndSize()
    { return true; }

// the sense danger concealed weapons doctrine: a successful check reveals the
// weapon general size, location and type (printed p. 176).
inline bool dfaSenseConcealedRevealsSizeLocationType()
    { return true; }

// the sense danger concealed weapons doctrine: faced with an unknown creature
// a successful check determines its attack modes (printed p. 176).
inline bool dfaSenseUnknownCreatureAttackModes()
    { return true; }

// the sense danger concealed weapons note: unlike the warrior version a rogue
// can detect magically concealed weapons (printed p. 176).
inline bool dfaSenseMagicalConcealmentDetected()
    { return true; }

// the sense danger hostile intentions doctrine: a successful roll gives a
// general level of hostility - low, medium or high - but not how well
// prepared the creature is, nor how likely it is to attack (printed p. 176).
inline bool dfaSenseHostilityNotPreparedness()
    { return true; }

// the sense danger impending attacks doctrine: the rogue receives a vague
// impression of the attacker general direction (front, rear, left, right) and
// distance (close, far) (printed p. 176).
inline bool dfaSenseImpendingDirectionAndDistance()
    { return true; }

// the sense danger impending attacks bonus: a successful skill check gives a
// plus 2 bonus on surprise rolls (printed p. 176).
inline int dfaSenseImpendingSurpriseBonus()
    { return 2; }

// the sense danger impending attacks bonus: a successful skill check gives a
// plus 1 bonus to the initiative roll during the first round of combat if the
// character is not surprised (printed p. 176).
inline int dfaSenseImpendingInitBonus()
    { return 1; }

// the sense danger impending attacks limit: unlike the warrior back
// protection the rogue must turn to face the attacker to negate rear attack
// bonuses - if surprised the attacker receives all rear attack bonuses
// including backstab adjustments (printed p. 176).
inline bool dfaSenseImpendingMustFace()
    { return true; }

// the sense danger procedure: the DM should roll the check secretly (printed
// p. 176).
inline bool dfaSenseSecretRolls()
    { return true; }

// the sense danger false indication: if the roll fails on a 20 the character
// gets a false indication (printed p. 176).
inline int dfaSenseFalseRoll()
    { return 20; }

// the sense danger false indication: it has no effect on an impending attack
// (printed p. 176).
inline bool dfaSenseFalseNotImpending()
    { return true; }

// the sense danger alertness note: a character with the alertness proficiency
// receives a plus 1 bonus to the skill score (printed p. 176).
inline int dfaSenseAlertnessBonus()
    { return 1; }

// the shadow flight doctrine: the ability is similar to the shadow travel
// skill except a successful hide in shadows roll allows the character to fly
// silently from shadow to shadow (printed p. 177).
inline bool dfaFlightLikeShadowTravel()
    { return true; }

// the shadow flight procedure: the rogue must begin with a successful hide in
// shadows roll (printed p. 177).
inline bool dfaFlightNeedsHideInShadows()
    { return true; }

// the shadow flight weak shadow rate: 15 with maneuverability class D
// (printed p. 177).
inline int dfaFlightWeakRate()
    { return 15; }

// the shadow flight strong shadow rate: 18 with maneuverability class C
// (printed p. 177).
inline int dfaFlightStrongRate()
    { return 18; }

// the shadow flight very shadowy rate: 24 with maneuverability class B
// (printed p. 177).
inline int dfaFlightVeryRate()
    { return 24; }

// the shadow flight limit: with no shadow flight is not possible and movement
// is normal (printed p. 177).
inline bool dfaFlightNoFlightWithoutShadow()
    { return true; }

// the shadow flight leap: once an hour the rogue can instantly move up to 360
// yards as a dimension door spell (printed p. 177).
inline int dfaFlightLeapYards()
    { return 360; }

// the shadow flight leap frequency: once an hour (printed p. 177).
inline int dfaFlightLeapPerHour()
    { return 1; }

// the shadow flight leap limit: the destination must be at least as shadowy
// as the rogue current position (printed p. 177).
inline bool dfaFlightLeapNeedsAsShadowy()
    { return true; }

// the shadow flight limit: while flying or traveling instantaneously the
// rogue can be no more than lightly encumbered (printed p. 177).
inline bool dfaFlightLightEncumbranceOnly()
    { return true; }

// the shadow flight limit: the rogue can carry other creatures if their
// weight does not exceed the light encumbrance limit (printed p. 177).
inline bool dfaFlightCarryWithinLimit()
    { return true; }

// the shadow travel procedure: the rogue must first successfully hide in
// shadows, which is required to use this skill (printed p. 177).
inline bool dfaShadowNeedsHideInShadows()
    { return true; }

// the shadow travel weak shadow rate: movement rate 15 (printed p. 177).
inline int dfaShadowWeakRate()
    { return 15; }

// the shadow travel strong shadow rate: movement rate 18 (printed p. 177).
inline int dfaShadowStrongRate()
    { return 18; }

// the shadow travel very shadowy rate: movement rate 24 (printed p. 177).
inline int dfaShadowVeryRate()
    { return 24; }

// the shadow travel limit: with no shadows available the movement rate is
// normal (printed p. 177).
inline bool dfaShadowNoShadowsNormal()
    { return true; }

// the shadow travel doctrine: the rogue is visible when moving between
// shadows but remains hidden while within them (printed p. 177).
inline bool dfaShadowVisibleBetweenShadows()
    { return true; }

// the shadow travel doctrine: accelerated movement lasts until the character
// attacks or the shadows get weaker; the rogue can re-enter and resume on any
// round without an attack (printed p. 177).
inline bool dfaShadowEndsOnAttack()
    { return true; }

// the shadow travel doctrine: shadow movement is not silent, but the rogue
// can attempt a move silently roll while moving through shadows and still
// move at the accelerated rate (printed p. 177).
inline bool dfaShadowNotSilent()
    { return true; }

// the shadow travel doctrine: accelerated movement is subject to normal
// modifiers for terrain and encumbrance (printed p. 177).
inline bool dfaShadowTerrainAndEncumbranceApply()
    { return true; }

}   // namespace rules
