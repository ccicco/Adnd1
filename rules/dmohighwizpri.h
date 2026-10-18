// =========================================================================================
// Adnd1 - rules/dmohighwizpri.h
// WIZARDS AND PRIESTS BEYOND 20TH - DMO Chapter 7, round three of five: the
// wizard advancement grid (Table 43: 3,750,000 XP at 20th in 375K steps to
// 7,500,000 at 30th, weapon and nonweapon proficiencies, the 10+N d4 hit
// points with the Con-bonus footnote) and spell progression (Table 44: levels
// 20-30 by spell level 1-10, the true dweomers climbing
// 1-1-1-2-2-2-3-3-3-4-4), the sage ability (21st: two categories with one
// Alchemy or Chemistry, 6-or-less on 1d20; 24th specific and 27th exacting
// questions at 1d6 books of 1,000 gp each), the three wizard skills (mental
// focus with its 18-to-22 boost ladder, signature item with its six
// categories, spell sculpting with its 500-gp-per-level focus, the
// damage/duration/range/casting-time sculptings and the 1st-to-7th cap
// ladder), the priest doctrine (all priests cast true dweomers at 20th,
// divine power, the deity-interest rules), the priest advancement grid (Table
// 45: cleric 225K and druid 500K XP steps, the 9+N d8 hit points), the priest
// spell progression grid (the printed body caption reads Table 47 while the
// contents lists Table 46 - held per the body caption; spells by level 1-7
// plus the true dweomer column 1-1-2-2-2-3-3-4-4-4-4), the priest powers
// (quest spells without sacrifice, improved undead turning at 21st with the
// Wulf lich-and-vampires example, spell selection at 21/25/27, the holy army
// at 1 troop per 1,000 XP with its officer chain and pay rules), and all nine
// priest skills (divine strength, divine voice, divine will, detect
// deception, eminence, invincibility, loan, smite and spell talisman).
// census 532 -> 533.
//
// verified against printed pp. 156-167 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns, the djvu.txt full texts; the tsr02156
// ABBYY read is primary and the tesseract read is cross-checked; leaf N =
// printed page N). Four printed quirks held: (1) the priest spell progression
// table caption prints Table 47 in the body while both captures contents
// pages read Table 46 - the body caption is held and the conflict is printed,
// not an OCR split; (2) the spell talisman skill is absent from the Table 40
// roster - pinned from its detail section at priest 12+; (3) the eminence
// prose lists divine will among its five prerequisite skills while Table 40
// and the divine will detail read priest 10+ without eminence - both pinned
// verbatim; (4) the wizard mental focus ceiling reads equal to or higher
// while the priest divine strength reads already higher - each pinned
// verbatim.
//
// the gap census after this round: 89 closed, 7 open - two Chapter 7 children
// flip in round three of five (the parent stays open until R612); the DMO arc
// continues with R611 (Rogues, Tables 48-52, pp. 167-171).
//
namespace rules {

// ---- the DMO wizard advancement pins ----

// the wizard advancement ceiling: wizards continue to receive extra
// proficiencies and hit points until level 30 (printed p. 156).
inline int dezWizAdvLimit()
    { return 30; }

// the wizard skills note: wizards receive very little in the way of special
// skills once they reach 20th level (printed p. 156).
inline int dezWizSkillPauseLevel()
    { return 20; }

// the Table 43 row count: eleven levels from 20th through 30th (printed p.
// 156).
inline int dezT43RowCount()
    { return 11; }

// the Table 43 experience step: 375,000 experience points per level beyond
// 20th (printed p. 156).
inline int dezT43XpStep()
    { return 375000; }

// the Table 43 hit-point base: the constant 10 of the printed 10-plus-N d4
// hit-point cells (printed p. 156).
inline int dezT43HpBase()
    { return 10; }

// the Table 43 footnote: bonus hit points from high Constitution scores are
// not added after 9th level (printed p. 156).
inline bool dezT43ConBonusStopsAfter9()
    { return true; }

// the wizard power note: the ever-increasing number of spells, including
// 10th-level spells, gives wizards a great deal of power already (printed p.
// 156).
inline bool dezWizTenthLevelSpellsCount()
    { return true; }

// the wizard framing: physically weak, but the right combination of
// protective magical items makes them all but invulnerable except to
// high-level warriors and other high-level wizards (printed p. 156).
inline bool dezWizIntroPhysicallyWeak()
    { return true; }

// the experience column: 3,750,000 at 20th rising in 375,000 steps to
// 7,500,000 at 30th (printed p. 156).
inline int dezT43Xp(int b)
    {
        switch (b) {
        case 0:
            return 3750000;
        case 1:
            return 4125000;
        case 2:
            return 4500000;
        case 3:
            return 4875000;
        case 4:
            return 5250000;
        case 5:
            return 5625000;
        case 6:
            return 6000000;
        case 7:
            return 6375000;
        case 8:
            return 6750000;
        case 9:
            return 7125000;
        case 10:
            return 7500000;
        default:
            return -99;
        }
    }

// the weapon proficiency column: 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6 across
// levels 20-30 (printed p. 156).
inline int dezT43WeaponProf(int b)
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
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
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

// the nonweapon proficiency column: 10, 11, 11, 11, 12, 12, 12, 13, 13, 13,
// 14 - one more every three levels (printed p. 156).
inline int dezT43NonweaponProf(int b)
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

// the hit-point base column: the constant 10 of the printed 10-plus-N cells
// (printed p. 156).
inline int dezT43HpBaseCol(int b)
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

// the hit-point bonus column: 10 at 20th rising in +1 steps to 20 at 30th
// (printed p. 156).
inline int dezT43HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 12;
        case 3:
            return 13;
        case 4:
            return 14;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 17;
        case 8:
            return 18;
        case 9:
            return 19;
        case 10:
            return 20;
        default:
            return -99;
        }
    }

// ---- the DMO wizard spell-progression pins ----

// the Table 44 row count: eleven levels from 20th through 30th (printed p.
// 157).
inline int dezT44RowCount()
    { return 11; }

// the 1st-level column: 5 at 20th through 25th, 6 at 26th through 28th, 7 at
// 29th and 30th (printed p. 157).
inline int dezT44L1(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 2nd-level column: 5 at 20th through 25th, 6 at 26th through 28th, 7 at
// 29th and 30th (printed p. 157).
inline int dezT44L2(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 3rd-level column: 5 at 20th through 25th, 6 at 26th through 28th, 7 at
// 29th and 30th (printed p. 157).
inline int dezT44L3(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 4th-level column: 5 at 20th through 25th, 6 at 26th through 28th, 7 at
// 29th and 30th (printed p. 157).
inline int dezT44L4(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 5th-level column: 5 at 20th, 5 at 21st, 5 through 25th, then 5, 6, 6,
// 6, 6, 7, 7 - reaching 6 at 27th and 7 at 30th (printed p. 157).
inline int dezT44L5(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 6th-level column: 4 at 20th and 21st, 5 at 22nd through 25th, 5 at
// 26th, 6 at 27th and 28th, 6 at 29th, 7 at 30th (printed p. 157).
inline int dezT44L6(int b)
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
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 7th-level column: 3 at 20th, 4 at 21st and 22nd, 5 at 23rd through
// 25th, 5 at 26th, 6 at 27th, 6 at 28th and 29th, 7 at 30th (printed p. 157).
inline int dezT44L7(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 7;
        default:
            return -99;
        }
    }

// the 8th-level column: 3 at 20th, 4 at 21st and 22nd, 5 at 23rd through 30th
// (printed p. 157).
inline int dezT44L8(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
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

// the 9th-level column: 2 at 20th and 21st, 3 at 22nd and 23rd, 4 at 24th, 5
// at 25th and 26th, 5 at 27th, 6 at 28th, 6 at 29th, 6 at 30th (printed p.
// 157).
inline int dezT44L9(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
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

// the 10th-level column: the true dweomers per day - 1 at 20th through 22nd,
// 2 at 23rd through 25th, 3 at 26th through 28th, 4 at 29th and 30th (printed
// p. 157).
inline int dezT44L10(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        default:
            return -99;
        }
    }

// ---- the DMO sage ability pins ----

// the sage threshold: at 21st level a wizard has accumulated enough books and
// esoteric knowledge to function as a sage (printed pp. 157-158).
inline int dezSageStartLevel()
    { return 21; }

// the sage categories: the wizard can answer general questions in two
// categories from the Dungeon Master Guide Table 61 (printed pp. 157-158).
inline int dezSageCategoryCount()
    { return 2; }

// the sage base chance: 6 or less on 1d20 to answer a general question,
// modified by the Intelligence/Knowledge bonus (printed pp. 157-158).
inline int dezSageBaseChance()
    { return 6; }

// the sage specific threshold: at 24th level the character can answer
// specific questions after acquiring 1d6 books or scrolls (printed pp.
// 157-158).
inline int dezSageSpecificLevel()
    { return 24; }

// the sage exacting threshold: at 27th level the character can answer
// exacting questions after acquiring 1d6 additional books or scrolls (printed
// pp. 157-158).
inline int dezSageExactingLevel()
    { return 27; }

// the sage book count: 1d6 books or scrolls per threshold (printed pp.
// 157-158).
inline int dezSageBookDieSides()
    { return 6; }

// the sage book cost: 1,000 gold pieces each (printed pp. 157-158).
inline int dezSageBookCost()
    { return 1000; }

// the sage research example: a simple but specific history question takes
// 1d3+1 weeks of study (printed p. 158).
inline int dezSageResearchWeeksDieSides()
    { return 3; }

// the sage research weeks bonus: the 1d3+1 form (printed p. 158).
inline int dezSageResearchWeeksBonus()
    { return 1; }

// the sage research cost: 100 gold pieces a week, the same as the cost to
// discover a potion formula (printed p. 158).
inline int dezSageResearchCostPerWeek()
    { return 100; }

// the esoteric research floor: a very difficult and esoteric question might
// require as much time and money as a 6th-level spell (printed p. 158).
inline int dezSageEsotericSpellMinLevel()
    { return 6; }

// the esoteric research ceiling: as much as a 6th- or 7th-level spell, with
// the chance to know the answer the same as successfully researching the
// spell (printed p. 158).
inline int dezSageEsotericSpellMaxLevel()
    { return 7; }

// the sage constraint: one of the two categories must be Alchemy or
// Chemistry, reflecting the knowledge of magical potions and scroll inks
// (printed pp. 157-158).
inline bool dezSageOneCategoryAlchemyOrChemistry()
    { return true; }

// the sage second category: the player can choose it or the DM can assign one
// (printed pp. 157-158).
inline bool dezSageOtherCategoryPlayerOrDm()
    { return true; }

// the sage fallback: a difficult question can always be answered by
// consulting another character, undertaking an adventure, or lengthy and
// expensive research (printed p. 158).
inline bool dezSageDifficultAnswersOtherRoutes()
    { return true; }

// ---- the DMO mental focus pins ----

// the mental focus boost base: the improved score is 18 plus the level band
// (printed p. 158).
inline int dezWizFocusBoostBase()
    { return 18; }

// the mental focus duration: the improvement lasts one round per character
// level (printed p. 158).
inline int dezWizFocusDurationPerLevel()
    { return 1; }

// the mental focus cost: the other two eligible ability scores drop by two
// for the same duration (printed p. 158).
inline int dezWizFocusOtherScoresPenalty()
    { return 2; }

// the mental focus drain: each attempt, successful or not, lowers the base
// skill score by two for the day (printed p. 158).
inline int dezWizFocusAttemptCost()
    { return 2; }

// the mental focus boost ladder: wizard levels 12-16 band 0 (boost to 18),
// 17-20 band 1 (19), 21-25 band 2 (20), 26-29 band 3 (21), and 30 or more the
// tail band 4 (22) - the improved score is 18 plus the band (printed p. 158).
inline int dezWizFocusBand(int x)
    {
        if (x <= 16) return 0;
        if (x <= 20) return 1;
        if (x <= 25) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the mental focus targets: a temporary bonus to Intelligence, Wisdom or
// Dexterity (printed p. 158).
inline bool dezWizFocusIntWisDex()
    { return true; }

// the mental focus limit: only one ability score improvement can operate at
// any given time (printed p. 158).
inline bool dezWizFocusOneBoostAtATime()
    { return true; }

// the mental focus round: no other actions while concentrating one round
// (printed p. 158).
inline bool dezWizFocusConcentrationRoundOnlyAction()
    { return true; }

// the mental focus control: the wizard can end the boost and restore the
// other scores at any time (printed p. 158).
inline bool dezWizFocusBoostEndsAtWill()
    { return true; }

// the mental focus ceiling: no effect if the ability score is already equal
// to or higher than the table value - the wizard wording, printed verbatim
// (printed p. 158).
inline bool dezWizFocusNoEffectIfEqualOrHigher()
    { return true; }

// the mental focus subabilities: under the optional rule both subabilities of
// the boosted score rise to the same value (printed p. 158).
inline bool dezWizFocusSubabilitiesRaisedEqual()
    { return true; }

// the mental focus timing: bonuses apply immediately on success and are lost
// immediately when the boost ends (printed p. 158).
inline bool dezWizFocusBonusesImmediate()
    { return true; }

// ---- the DMO wizard signature item pins ----

// the wizard signature item categories: ring, rod, staff, wand, miscellaneous
// magic and weapon (printed p. 158).
inline int dezWizSigItemCategoryCount()
    { return 6; }

// the wizard signature item: except as noted, operates exactly like the
// warrior skill of the same name (printed p. 158).
inline bool dezWizSigItemLikeWarriorSkill()
    { return true; }

// the wizard signature item limit: as many items as the wizard pays for, but
// no more than one of any type of item (printed p. 158).
inline bool dezWizSigItemOnePerType()
    { return true; }

// ---- the DMO spell sculpting pins ----

// the sculpting focus: a focus item must be worth at least 500 gold pieces
// per spell level (printed pp. 158-159).
inline int dezSculptFocusCostPerLevel()
    { return 500; }

// the sculpting damage boost: an extra two dice of damage of the type
// normally rolled (printed pp. 158-159).
inline int dezSculptDamageDice()
    { return 2; }

// the sculpting duration boost: the total duration is doubled (printed pp.
// 158-159).
inline int dezSculptDurationMultiple()
    { return 2; }

// the sculpting range boost: the range is doubled (printed pp. 158-159).
inline int dezSculptRangeMultiple()
    { return 2; }

// the sculpting casting floor: the casting time is cut in half, to a minimum
// of 1 (printed pp. 158-159).
inline int dezSculptMinCastingTime()
    { return 1; }

// the sculpting focus risk: if the failure roll is a 20 the focus item is
// destroyed (printed pp. 158-159).
inline int dezSculptFailDestroysRoll()
    { return 20; }

// the sculpting fireball example: a sculpted fireball inflicts 12d6 - the
// 10d6 base plus the extra two dice (printed pp. 158-159).
inline int dezSculptFireballBaseDice()
    { return 10; }

// the sculpting fireball total: 12d6 points of damage (printed pp. 158-159).
inline int dezSculptFireballSculptedDice()
    { return 12; }

// the sculpting burning hands example: a 20th-level wizard sculpts burning
// hands to 3d3+20 - the 1d3 base die plus the extra two dice (printed pp.
// 158-159).
inline int dezSculptBurningHandsBaseDice()
    { return 1; }

// the sculpting magic missile example: five missiles at 20th level, sculpted
// to a total of 7d4+7 (printed pp. 158-159).
inline int dezSculptMagicMissileBaseDice()
    { return 5; }

// the highest spell level a wizard can sculpt: levels 12-14 band 0 (1st),
// 15-17 band 1 (2nd), 18-20 band 2 (3rd), 21-23 band 3 (4th), 24-26 band 4
// (5th), 27-29 band 5 (6th), and 30 or more the tail band 6 (7th) - one plus
// the band (printed pp. 158-159).
inline int dezSpellCapBand(int x)
    {
        if (x <= 14) return 0;
        if (x <= 17) return 1;
        if (x <= 20) return 2;
        if (x <= 23) return 3;
        if (x <= 26) return 4;
        if (x <= 29) return 5;
        return 6;
    }

// the sculpting preparation: the wizard must prepare an item to focus and
// reshape the spell energy - a small object such as a jewel, wand or amulet
// (printed pp. 158-159).
inline bool dezSculptRequiresFocusItem()
    { return true; }

// the sculpting component: the focus item is an additional material
// component, normally not consumed (printed pp. 158-159).
inline bool dezSculptFocusNotConsumed()
    { return true; }

// the sculpting failure: a failed skill roll casts the spell normally
// (printed pp. 158-159).
inline bool dezSculptFailCastsNormally()
    { return true; }

// the sculpting limit: it is not possible to sculpt a spell more than once
// (printed pp. 158-159).
inline bool dezSculptOnceOnly()
    { return true; }

// the sculpting range exclusion: a spell with a range of touch or 0 cannot be
// extended (printed pp. 158-159).
inline bool dezSculptNoTouchOrZeroRange()
    { return true; }

// the sculpting duration exclusion: spells with instantaneous durations
// cannot be extended (printed pp. 158-159).
inline bool dezSculptNoInstantaneousDuration()
    { return true; }

// the sculpting order: if local conditions lengthen the casting time, apply
// the multiplier first, then cut the result in half (printed pp. 158-159).
inline bool dezSculptLocalMultiplierFirst()
    { return true; }

// the sculpting damage exclusion: spells that do not use dice rolls to
// determine damage cannot be sculpted for damage (printed pp. 158-159).
inline bool dezSculptNoDicelessDamage()
    { return true; }

// the sculpting missile rule: spells with individual damage dice such as
// magic missile are not increased individually - the extra dice can join one
// missile or split across two (printed pp. 158-159).
inline bool dezSculptIndividualDiceNotIncreased()
    { return true; }

// the sculpting metamagic combo: a metamagic spell can apply to a sculpted
// spell provided the effects do not duplicate (printed pp. 158-159).
inline bool dezSculptMetamagicAllowedIfNoDuplication()
    { return true; }

// the sculpting cost: learning to sculpt more than one spell requires the
// full skill cost for each spell (printed pp. 158-159).
inline bool dezSculptFullCostPerSpell()
    { return true; }

// the sculpting improvement: a base-score increase applies to all spells the
// wizard knows how to sculpt (printed pp. 158-159).
inline bool dezSculptImprovementAllSpells()
    { return true; }

// the sculpting cast: the wizard must meet all the usual requirements to cast
// the spell (printed pp. 158-159).
inline bool dezSculstRequirementsStillMet()
    { return true; }

// ---- the DMO priest doctrine pins ----

// the priest advancement ceiling: priests receive extra proficiencies and hit
// points through 30th level (printed pp. 159-160).
inline int dezPriestAdvLimit()
    { return 30; }

// the priest skill threshold: priests have access to special skills beginning
// at 10th level (printed pp. 159-160).
inline int dezPriestSkillLevel()
    { return 10; }

// the priest true dweomer threshold: all priests, even druids, gain the
// ability to cast true dweomers when they reach 20th level (printed pp.
// 159-160).
inline int dezPriestTdStartLevel()
    { return 20; }

// the priest dweomer rule: all priests, even druids, cast true dweomers at
// 20th level - a new approach to magic very high-level druids can understand
// and use (printed pp. 159-160).
inline bool dezAllPriestsCastTrueDweomers()
    { return true; }

// the priest dweomer naming: for a priest a true dweomer might be called an
// 8th-level spell, but it functions just like a wizard true dweomer (printed
// pp. 159-160).
inline bool dezPriestTdMightBeCalled8th()
    { return true; }

// the priest dweomer source: unlike wizards, priests use divine power to
// create their true dweomers (printed pp. 159-160).
inline bool dezPriestTdUsesDivinePower()
    { return true; }

// the priest dweomer constraint: any true dweomer a priest casts must promote
// the deity interests in some way (printed pp. 159-160).
inline bool dezPriestTdMustPromoteDeityInterests()
    { return true; }

// the priest dweomer standing: the priest must be in good standing with the
// deity, having observed the requirements of both the alignment and the ethos
// (printed pp. 159-160).
inline bool dezPriestTdRequiresGoodStanding()
    { return true; }

// the priest dweomer judgment: a true dweomer impacting the deity sphere of
// control or portfolio is likely to be granted unless it runs contrary to
// that power wishes (printed pp. 159-160).
inline bool dezPriestTdSpherePortfolioLikelyGranted()
    { return true; }

// the priest dweomer check: when in doubt, check the spheres of normal spells
// the priest can cast - effects found in those spells are probably acceptable
// (printed pp. 159-160).
inline bool dezPriestTdCheckSpheresWhenInDoubt()
    { return true; }

// the priest framing: priests combine spellcasting abilities with combat
// power, formidable with magical armor and weapons, but their primary
// strength comes from spells (printed pp. 159-160).
inline bool dezPriestsFormidableInCombat()
    { return true; }

// ---- the DMO priest advancement pins ----

// the Table 45 row count: eleven levels from 20th through 30th (printed p.
// 160).
inline int dezT45RowCount()
    { return 11; }

// the Table 45 cleric step: 225,000 experience points per level beyond 20th
// (printed p. 160).
inline int dezT45ClericXpStep()
    { return 225000; }

// the Table 45 druid step: 500,000 experience points per level beyond 20th
// (printed p. 160).
inline int dezT45DruidXpStep()
    { return 500000; }

// the Table 45 hit-point base: the constant 9 of the printed 9-plus-N d8
// hit-point cells (printed p. 160).
inline int dezT45HpBase()
    { return 9; }

// the Table 45 hit-point step: +2 per level beyond 20th (printed p. 160).
inline int dezT45HpStep()
    { return 2; }

// the Table 45 footnote: bonus hit points from high Constitution scores are
// not added after 9th level (printed p. 160).
inline bool dezT45ConBonusStopsAfter9()
    { return true; }

// the cleric experience column: 2,700,000 at 20th rising in 225,000 steps to
// 4,950,000 at 30th (printed p. 160).
inline int dezT45ClericXp(int b)
    {
        switch (b) {
        case 0:
            return 2700000;
        case 1:
            return 2925000;
        case 2:
            return 3150000;
        case 3:
            return 3375000;
        case 4:
            return 3600000;
        case 5:
            return 3825000;
        case 6:
            return 4050000;
        case 7:
            return 4275000;
        case 8:
            return 4500000;
        case 9:
            return 4725000;
        case 10:
            return 4950000;
        default:
            return -99;
        }
    }

// the druid experience column: 2,000,000 at 20th rising in 500,000 steps to
// 7,000,000 at 30th (printed p. 160).
inline int dezT45DruidXp(int b)
    {
        switch (b) {
        case 0:
            return 2000000;
        case 1:
            return 2500000;
        case 2:
            return 3000000;
        case 3:
            return 3500000;
        case 4:
            return 4000000;
        case 5:
            return 4500000;
        case 6:
            return 5000000;
        case 7:
            return 5500000;
        case 8:
            return 6000000;
        case 9:
            return 6500000;
        case 10:
            return 7000000;
        default:
            return -99;
        }
    }

// the weapon proficiency column: 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9 - one more
// every four levels (printed p. 160).
inline int dezT45WeaponProf(int b)
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

// the nonweapon proficiency column: 10, 11, 11, 11, 12, 12, 12, 13, 13, 13,
// 14 - one more every three levels (printed p. 160).
inline int dezT45NonweaponProf(int b)
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

// the hit-point base column: the constant 9 of the printed 9-plus-N cells
// (printed p. 160).
inline int dezT45HpBaseCol(int b)
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

// the hit-point bonus column: 22 at 20th rising in +2 steps to 42 at 30th
// (printed p. 160).
inline int dezT45HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 24;
        case 2:
            return 26;
        case 3:
            return 28;
        case 4:
            return 30;
        case 5:
            return 32;
        case 6:
            return 34;
        case 7:
            return 36;
        case 8:
            return 38;
        case 9:
            return 40;
        case 10:
            return 42;
        default:
            return -99;
        }
    }

// ---- the DMO priest spell-progression pins ----

// the priest spell progression row count: eleven levels from 20th through
// 30th (printed p. 161).
inline int dezT47RowCount()
    { return 11; }

// the 1st-level column: 9 at every level 20 through 30 (printed p. 161).
inline int dezT47L1(int b)
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

// the 2nd-level column: 9 at every level 20 through 30 (printed p. 161).
inline int dezT47L2(int b)
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

// the 3rd-level column: 9 at every level 20 through 30 (printed p. 161).
inline int dezT47L3(int b)
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

// the 4th-level column: 8 at 20th, then 9 at every level 21 through 30
// (printed p. 161).
inline int dezT47L4(int b)
    {
        switch (b) {
        case 0:
            return 8;
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

// the 5th-level column: 7 at 20th, 8 at 21st, then 9 at every level 22
// through 30 (printed p. 161).
inline int dezT47L5(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
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

// the 6th-level column: 5 at 20th, 6 at 21st and 22nd, 7 at 23rd, 8 at 24th
// and 25th, then 9 at every level 26 through 30 (printed p. 161).
inline int dezT47L6(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 8;
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

// the 7th-level column: 2 at 20th and 21st, 3 at 22nd through 24th, 4 at 25th
// and 26th, 5 at 27th, 6 at 28th, 7 at 29th, 8 at 30th (printed p. 161).
inline int dezT47L7(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        default:
            return -99;
        }
    }

// the true dweomer column: 1 at 20th and 21st, 2 at 22nd through 24th, 3 at
// 25th and 26th, then 4 at every level 27 through 30 (printed p. 161).
inline int dezT47Td(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        default:
            return -99;
        }
    }

// ---- the DMO priest powers pins ----

// the quest spell gate: any priest with access to true dweomers can receive a
// quest spell (printed p. 160).
inline int dezQuestSpellLevel()
    { return 20; }

// the improved turning threshold: upon reaching 21st level a priest with the
// granted power to turn undead can use it multiple times in the same
// encounter (printed p. 160).
inline int dezImprovedTurningLevel()
    { return 21; }

// the first spell selection: at 21st level the priest gains minor access to a
// new sphere or another level in a minor sphere (printed pp. 160-161).
inline int dezSpellSelectLevel1()
    { return 21; }

// the second spell selection: at 25th level the priest gains minor access to
// another sphere or adds another level in a minor sphere, including the one
// added or enhanced at 21st (printed pp. 160-161).
inline int dezSpellSelectLevel2()
    { return 25; }

// the third spell selection: at 27th level the priest gains minor access to
// another sphere or adds another level in a minor sphere, including all
// previously added or enhanced (printed pp. 160-161).
inline int dezSpellSelectLevel3()
    { return 27; }

// the Wulf turning example: Wulf is a 21st-level cleric (printed p. 160).
inline int dezWulfTurnLevel()
    { return 21; }

// the Wulf turning example roll: a 7 on the turning attempt (printed p. 160).
inline int dezWulfTurnRoll()
    { return 7; }

// the Wulf destroy dice: 2d6 plus 2d4 destroyed (printed p. 160).
inline int dezWulfDestroyDiceCount()
    { return 2; }

// the Wulf destroy major die: the 2d6 half (printed p. 160).
inline int dezWulfDestroyMajorSides()
    { return 6; }

// the Wulf destroy minor die: the 2d4 half (printed p. 160).
inline int dezWulfDestroyMinorSides()
    { return 4; }

// the Wulf vampire roll: 2d6 to turn the vampires (printed p. 160).
inline int dezWulfVampireRollSides()
    { return 6; }

// the Wulf vampire roll result: a 5, leaving one vampire unaffected (printed
// p. 160).
inline int dezWulfVampireRollResult()
    { return 5; }

// the Wulf example foes: six vampires, a lich, and a horde of skeletons and
// ghouls (printed p. 160).
inline int dezWulfVampires()
    { return 6; }

// the Wulf vampire outcome: one vampire unaffected by the 5 (printed p. 160).
inline int dezWulfVampiresUnaffected()
    { return 1; }

// the quest spell rule: a priest with access to true dweomers receives a
// quest spell without sacrificing any spellcasting ability (printed p. 160).
inline bool dezQuestSpellNoSacrifice()
    { return true; }

// the quest spell catch: all other requirements for receiving a quest spell
// must be met normally, per the Tome of Magic (printed p. 160).
inline bool dezQuestSpellOtherRequirementsNormal()
    { return true; }

// the improved turning rule: the priest may continue to turn undead so long
// as prior attempts against the same group were successful (printed p. 160).
inline bool dezTurningRepeatWhileSuccessful()
    { return true; }

// the improved turning stop: once an attempt fails the priest cannot continue
// (printed p. 160).
inline bool dezTurningStopsAfterFail()
    { return true; }

// the improved turning mixed groups: further attempts to turn the unaffected
// creatures of a mixed group are useless (printed p. 160).
inline bool dezTurningMixedGroupUselessOnUnaffected()
    { return true; }

// the improved turning weaker creatures: weaker creatures continue to be
// affected as long as attempts against them succeed (printed p. 160).
inline bool dezTurningWeakerContinueIfSucceed()
    { return true; }

// the Wulf lich outcome: the roll of 7 is insufficient to turn the lich, and
// it stays unaffected on later rounds (printed p. 160).
inline bool dezWulfLichUnaffected()
    { return true; }

// the spell selection form: either minor access to a previously inaccessible
// sphere or access to another level in an existing minor sphere (printed pp.
// 160-161).
inline bool dezSpellSelectMinorOrLevelEitherWay()
    { return true; }

// the spell selection chooser: the DM can make the selection or let the
// player choose (printed pp. 160-161).
inline bool dezSpellSelectDmOrPlayerChooses()
    { return true; }

// ---- the DMO holy army pins ----

// the holy army threshold: a priest of 21st level or higher (printed pp.
// 161-162).
inline int dezArmyMinLevel()
    { return 21; }

// the holy army size: as many troops as the priest experience point total
// divided by 1,000 (printed pp. 161-162).
inline int dezArmyTroopsPerXp()
    { return 1000; }

// the holy army example: a priest who has just attained 21st level can summon
// 2,925 troops (printed pp. 161-162).
inline int dezArmyExampleTroops()
    { return 2925; }

// the holy army example priest: 21st level (printed pp. 161-162).
inline int dezArmyExamplePriestLevel()
    { return 21; }

// the holy army example commander: one commander of half the priest level,
// round down - 10th (printed pp. 161-162).
inline int dezArmyExampleCommander()
    { return 10; }

// the holy army example subcommanders: two of half the commander level - 5th
// (printed pp. 161-162).
inline int dezArmyExampleSubcommander()
    { return 5; }

// the holy army example lieutenants: four of half the subcommander level -
// 2nd (printed pp. 161-162).
inline int dezArmyExampleLieutenant()
    { return 2; }

// the holy army example sergeants: eight of half the lieutenant level - 1st
// (printed pp. 161-162).
inline int dezArmyExampleSergeant()
    { return 1; }

// the holy army paladin chance: 10 percent that any given officer is a
// paladin if the priest is lawful good (printed pp. 161-162).
inline int dezArmyPaladinChance()
    { return 10; }

// the holy army ranger chance: 10 percent that any commander is a ranger if
// the priest is of any good alignment and the task is in the wilderness
// (printed pp. 161-162).
inline int dezArmyRangerChance()
    { return 10; }

// the holy army gathering: two weeks to gather for every 500 people in it
// (printed pp. 161-162).
inline int dezArmyGatherWeeksPer500()
    { return 2; }

// the holy army duration: a maximum of one month for each level of the
// summoning priest (printed pp. 161-162).
inline int dezArmyDurationMonthsPerLevel()
    { return 1; }

// the holy army pay, low end: 2 gold pieces per 0-level trooper (printed pp.
// 161-162).
inline int dezArmyTroopPayLow()
    { return 2; }

// the holy army pay, high end: 4 gold pieces per 0-level trooper (printed pp.
// 161-162).
inline int dezArmyTroopPayHigh()
    { return 4; }

// the holy army officer pay: 100 gold pieces per level for commanders and
// priests (printed pp. 161-162).
inline int dezArmyOfficerPayPerLevel()
    { return 100; }

// the holy army extension: the troops remain active for an additional 2d4
// months (printed pp. 161-162).
inline int dezArmyExtensionDice()
    { return 2; }

// the holy army extension die: d4 (printed pp. 161-162).
inline int dezArmyExtensionDieSides()
    { return 4; }

// the holy army task: called up to accomplish a single task through force of
// arms - destroying a castle, temple or town, rescuing a captive, recovering
// a stolen item, bringing a fugitive to justice, deposing a ruler (printed
// pp. 161-162).
inline bool dezArmySingleTask()
    { return true; }

// the holy army constraint: the task cannot violate the principles of the
// priest alignment or ethos (printed pp. 161-162).
inline bool dezArmyTaskWithinAlignment()
    { return true; }

// the holy army limit: cannot summon one while another is in the field
// (printed pp. 161-162).
inline bool dezArmyOneAtATime()
    { return true; }

// the holy army frequency: no more than one each year (printed pp. 161-162).
inline bool dezArmyOncePerYear()
    { return true; }

// the holy army clergy: each commander and assistant is accompanied by a
// priest or cleric of similar level (printed pp. 161-162).
inline bool dezArmyOfficersHavePriests()
    { return true; }

// the holy army summoning place: somewhere people worship the character deity
// openly (printed pp. 161-162).
inline bool dezArmyOpenWorshipRequired()
    { return true; }

// the holy army slow gather: if worshippers are not common in the area the
// gathering time is doubled (printed pp. 161-162).
inline bool dezArmyGatherDoubledIfUncommon()
    { return true; }

// the holy army option: the priest can summon a smaller army (printed pp.
// 161-162).
inline bool dezArmySmallerAllowed()
    { return true; }

// the holy army extension route: pay the troops well or make a successful
// Charisma/Leadership check (printed pp. 161-162).
inline bool dezArmyPayOrCharismaCheck()
    { return true; }

// the holy army condition: the army goal must be within easy reach (printed
// pp. 161-162).
inline bool dezArmyGoalWithinReach()
    { return true; }

// the holy army disband: troops may remain together as an independent force -
// best seen home to keep radical elements from taking control (printed pp.
// 161-162).
inline bool dezArmyDisbandIndependenceRisk()
    { return true; }

// ---- the DMO divine strength pins ----

// the divine strength boost base: the improved score is 18 plus the level
// band (printed p. 161).
inline int dezPriestFocusBoostBase()
    { return 18; }

// the divine strength duration: the improvement lasts one round per character
// level (printed p. 161).
inline int dezPriestFocusDurationPerLevel()
    { return 1; }

// the divine strength cost: the other two eligible ability scores drop by two
// for the same duration (printed p. 161).
inline int dezPriestFocusOtherScoresPenalty()
    { return 2; }

// the divine strength drain: each attempt, successful or not, lowers the base
// skill score by two for the day (printed p. 161).
inline int dezPriestFocusAttemptCost()
    { return 2; }

// the divine strength ladder: priest levels 10-14 band 0 (boost to 18), 15-19
// band 1 (19), 20-24 band 2 (20), 25-29 band 3 (21), and 30 or more the tail
// band 4 (22) - the improved score is 18 plus the band (printed p. 161).
inline int dezPriestFocusBand(int x)
    {
        if (x <= 14) return 0;
        if (x <= 19) return 1;
        if (x <= 24) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the divine strength targets: a temporary bonus to Wisdom, Strength or
// Charisma (printed p. 161).
inline bool dezPriestFocusWisStrCha()
    { return true; }

// the divine strength casting note: the priest gains no bonus spells from
// this skill (printed p. 161).
inline bool dezPriestFocusNoBonusSpells()
    { return true; }

// the divine strength Wisdom note: a Wisdom score of 19 or higher grants
// immunity to certain spells per the Player Handbook Table 5 (printed p.
// 161).
inline bool dezPriestFocusWis19Immunity()
    { return true; }

// the divine strength limit: only one ability score improvement can operate
// at any given time (printed p. 161).
inline bool dezPriestFocusOneBoostAtATime()
    { return true; }

// the divine strength round: no other actions while concentrating (printed p.
// 161).
inline bool dezPriestFocusConcentrationRoundOnlyAction()
    { return true; }

// the divine strength control: the priest can end the boost and restore the
// other scores at any time (printed p. 161).
inline bool dezPriestFocusBoostEndsAtWill()
    { return true; }

// the divine strength ceiling: no effect if the ability score is already
// higher than the table value - the priest wording, printed verbatim (printed
// p. 161).
inline bool dezPriestFocusNoEffectIfHigher()
    { return true; }

// the divine strength subabilities: under the optional rule both subabilities
// of the boosted score rise to the same value (printed p. 161).
inline bool dezPriestFocusSubabilitiesRaisedEqual()
    { return true; }

// ---- the DMO divine voice pins ----

// the divine voice reach: every creature within 180 feet can hear the priest
// (printed p. 161).
inline int dezVoiceRangeFeet()
    { return 180; }

// the divine voice penetration: up to 10 feet of solid rock (printed p. 161).
inline int dezVoiceRockFeet()
    { return 10; }

// the divine voice penetration: or three inches of lead (printed p. 161).
inline int dezVoiceLeadInches()
    { return 3; }

// the divine voice enthrall gate: creatures with less than 5 Hit Dice or
// levels are automatically enthralled (printed p. 161).
inline int dezVoiceAutoEnthralHd()
    { return 5; }

// the divine voice spell: enthralled as the 2nd-level priest spell (printed
// p. 161).
inline int dezVoiceEnthralSpellLevel()
    { return 2; }

// the divine voice hold: the audience can be held enthralled for up to one
// hour (printed p. 161).
inline int dezVoiceHoldHours()
    { return 1; }

// the divine voice suggestion: a mass suggestion as the 6th-level wizard
// spell (printed p. 161).
inline int dezVoiceMassSuggestionLevel()
    { return 6; }

// the divine voice drain: each use reduces the base eminence score by two
// (printed p. 161).
inline int dezVoiceEminenceCost()
    { return 2; }

// the divine voice drain period: for one week (printed p. 161).
inline int dezVoiceEminenceDays()
    { return 7; }

// the divine voice form: the priest must speak loudly and clearly for a full
// round, the check made at the end of the round (printed p. 161).
inline bool dezVoiceFullRoundSpeech()
    { return true; }

// the divine voice silence rule: the voice penetrates silence spells (printed
// p. 161).
inline bool dezVoicePenetratesSilence()
    { return true; }

// the divine voice shielding: antimagic shells, prismatic spheres, cubes of
// force and 10th-level ward spells shield their occupants (printed p. 161).
inline bool dezVoiceAntimagicShields()
    { return true; }

// the divine voice hearing: creatures magically deafened cannot hear it
// (printed p. 161).
inline bool dezVoiceMagicalDeafnessBlocks()
    { return true; }

// the divine voice save: creatures with 5 or more Hit Dice or levels can save
// vs. spell to avoid the effect (printed p. 161).
inline bool dezVoiceSaveVsSpellOthers()
    { return true; }

// the divine voice understanding: creatures do not have to understand the
// words, merely hear them (printed p. 161).
inline bool dezVoiceHearingOnlyRequired()
    { return true; }

// the divine voice immunities: undead and creatures normally immune to charm
// spells, such as golems, are not affected (printed p. 161).
inline bool dezVoiceUndeadAndCharmImmuneUnaffected()
    { return true; }

// the divine voice willpower gate: creatures with Wisdom/Willpower scores of
// 19 or more are not affected (printed p. 161).
inline bool dezVoiceWis19Immune()
    { return true; }

// the divine voice break: excessive jeering can break the effects, per the
// enthrall spell description (printed p. 161).
inline bool dezVoiceJeeringBreaks()
    { return true; }

// the divine voice limit: only one mass suggestion per use of the skill
// (printed p. 161).
inline bool dezVoiceOneMassSuggestionPerUse()
    { return true; }

// the divine voice suggestion save: no saving throw against the mass
// suggestion if completed before the enthrall effect ends (printed p. 161).
inline bool dezVoiceNoSaveIfBeforeEnthralEnds()
    { return true; }

// the divine voice spread: the mass suggestion affects every creature
// currently enthralled regardless of the priest level (printed p. 161).
inline bool dezVoiceAffectsAllEnthralled()
    { return true; }

// the divine voice gate: ineffective if the eminence score is zero or less
// (printed p. 161).
inline bool dezVoiceIneffectiveAtZeroEminence()
    { return true; }

// ---- the DMO divine will pins ----

// the divine will drain: each use reduces the base eminence score by two
// (printed p. 162).
inline int dezWillEminenceCost()
    { return 2; }

// the divine will drain period: for one day (printed p. 162).
inline int dezWillEminenceDays()
    { return 1; }

// the divine will effect: a successful check negates the compulsion, no
// saving throw necessary (printed p. 162).
inline bool dezWillNegatesCompulsion()
    { return true; }

// the divine will fallback: if the check fails the priest still gets a saving
// throw if one is normally allowed (printed p. 162).
inline bool dezWillSaveOnFail()
    { return true; }

// the divine will scope: effective against any effect that makes the priest
// act according to another creature will - all forms of charm, geas, quest,
// fear, beguiling, command (printed p. 162).
inline bool dezWillCoversAllCompulsions()
    { return true; }

// the divine will magic jar: the invading psyche is ejected (printed p. 162).
inline bool dezWillEjectsMagicJarPsyche()
    { return true; }

// the divine will gate: ineffective when the eminence score is zero or less
// (printed p. 162).
inline bool dezWillIneffectiveAtZero()
    { return true; }

// ---- the DMO detect deception pins ----

// the detect deception retry: an unsuccessful check leaves the priest aware
// of the failure and he must wait one turn to try again (printed pp.
// 162-163).
inline int dezDeceiveRetryTurns()
    { return 1; }

// the detect deception drain: each use lowers the base eminence score by two
// (printed pp. 162-163).
inline int dezDeceiveEminenceCost()
    { return 2; }

// the detect deception drain period: for one week (printed pp. 162-163).
inline int dezDeceiveEminenceDays()
    { return 7; }

// the detect deception duration ladder: priest levels 15-17 band 0 (one
// turn), 18-20 band 1 (two turns), 21-23 band 2 (three turns), 24-26 band 3
// (four turns), and 27 or more band 4 (five turns): one turn plus the band
// (printed p. 162).
inline int dezDeceiveDurationBand(int x)
    {
        if (x <= 17) return 0;
        if (x <= 20) return 1;
        if (x <= 23) return 2;
        if (x <= 26) return 3;
        return 4;
    }

// the detect deception effect: a successful roll uncovers any falsehood
// encountered, false images from illusions or false statements from creatures
// (printed pp. 162-163).
inline bool dezDeceiveSeesFalsehoods()
    { return true; }

// the detect deception speech: while in effect the priest detects all forms
// of spoken falsehoods automatically for the duration (printed pp. 162-163).
inline bool dezDeceiveAutoSpokenFalsehoods()
    { return true; }

// the detect deception nuance: unlike a detect lie spell the priest knows
// when a creature is deliberately evading the truth (printed pp. 162-163).
inline bool dezDeceiveKnowsEvasionVsLie()
    { return true; }

// the detect deception limit: the skill does not tell the priest what the
// truth is, only that a lie or evasion was heard (printed pp. 162-163).
inline bool dezDeceiveNoTruthRevealed()
    { return true; }

// the detect deception magic speech: if magic allows falsehoods to be spoken
// the priest cannot hear the protected creature speak, revealing the
// falsehood indirectly (printed pp. 162-163).
inline bool dezDeceiveMagicSpeechUnheard()
    { return true; }

// the detect deception visions: an immediate saving throw vs. spell to see
// through any false vision or visual distortion from a spell, item or
// creature (printed pp. 162-163).
inline bool dezDeceiveImmediateSaveVsIllusion()
    { return true; }

// the detect deception roll: the DM should make the vision save secretly
// (printed pp. 162-163).
inline bool dezDeceiveDmSecretRoll()
    { return true; }

// the detect deception sight: a successful save shows the false image as a
// fine, semi-transparent mist (printed pp. 162-163).
inline bool dezDeceiveSeesMist()
    { return true; }

// the detect deception targets: works against all false and misleading images
// - mirror image, blur, shadow door, phantasmal force and other misleading
// spells (printed pp. 162-163).
inline bool dezDeceiveWorksVsVisualSpells()
    { return true; }

// the detect deception exclusion: illusion spells that create no image, such
// as invisibility, are not affected (printed pp. 162-163).
inline bool dezDeceiveNotVsInvisibility()
    { return true; }

// the detect deception items: defeats cloaks of displacement, robes of
// blending and similar items (printed pp. 162-163).
inline bool dezDeceiveDefeatsDisplacementBlending()
    { return true; }

// the detect deception shape limit: no power against effects that disguise
// through physical changes, such as polymorph self or shape change (printed
// pp. 162-163).
inline bool dezDeceiveNotVsPhysicalChanges()
    { return true; }

// the detect deception gate: ineffective when the base eminence score is zero
// or less (printed pp. 162-163).
inline bool dezDeceiveIneffectiveAtZero()
    { return true; }

// ---- the DMO eminence pins ----

// the eminence aura duration: one round for each level attained (printed p.
// 163).
inline int dezEminenceDurationPerLevel()
    { return 1; }

// the eminence reaction bonus: +4 encounter reaction when dealing with
// worshippers of the priest deity or creatures of the same alignment (printed
// p. 163).
inline int dezEminenceReactionBonus()
    { return 4; }

// the eminence fear radius: hostile creatures feel the shudder of fear within
// 30 feet of the priest (printed p. 163).
inline int dezEminenceFearRadius()
    { return 30; }

// the eminence flee gate: creatures of less than 4th level or 4 Hit Dice flee
// until the priest is no longer in sight (printed p. 163).
inline int dezEminenceFleeLevel()
    { return 4; }

// the eminence drain: each attempt to raise the aura reduces the base
// eminence score by two (printed p. 163).
inline int dezEminenceCost()
    { return 2; }

// the eminence drain period: for one week (printed p. 163).
inline int dezEminenceDays()
    { return 7; }

// the eminence aura: undetectable except by a true seeing spell (printed p.
// 163).
inline bool dezEminenceAuraUndetectable()
    { return true; }

// the eminence halo: true seeing reveals a bright silver, inky black or pearl
// gray halo depending on the priest alignment (printed p. 163).
inline bool dezEminenceHaloByAlignment()
    { return true; }

// the eminence trigger: if the priest wills it the fear takes hold (printed
// p. 163).
inline bool dezEminenceFearAtWill()
    { return true; }

// the eminence save: more powerful creatures get a saving throw vs. spell to
// negate the fear (printed p. 163).
inline bool dezEminenceSaveForStronger()
    { return true; }

// the eminence reach: works against all types of creatures, even those
// normally immune to fear attacks such as undead (printed p. 163).
inline bool dezEminenceWorksVsFearImmune()
    { return true; }

// the eminence negations: a cloak of bravery or remove fear spell breaks the
// effect (printed p. 163).
inline bool dezEminenceCloakOrRemoveFearBreaks()
    { return true; }

// the eminence counters: a successful use of the warrior skill bravery or the
// priest skill divine will breaks the effect (printed p. 163).
inline bool dezEminenceSkillBreaks()
    { return true; }

// the eminence resistance: once a creature has resisted the fear it is not
// subject to fear effects from the same priest for the rest of the day
// (printed p. 163).
inline bool dezEminenceOnceResistedImmuneRestOfDay()
    { return true; }

// the eminence opposition: creatures within 30 feet of an opposing priest
// using eminence are not subject to the fear if the second priest level is
// equal or higher (printed p. 163).
inline bool dezEminenceOpposingPriestShields()
    { return true; }

// the eminence gate: ineffective when the base eminence score is zero or less
// (printed p. 163).
inline bool dezEminenceIneffectiveAtZero()
    { return true; }

// the eminence prerequisite list, printed verbatim: a prerequisite for the
// divine strength, divine voice, divine will, detect deception and
// invincibility skills - noting the printed tension: the Table 40 roster and
// the divine will detail read Priest 10+ without eminence (printed p. 163).
inline bool dezEminencePrereqFiveSkills()
    { return true; }

// the eminence drain rule: each use of the five dependent skills reduces the
// base eminence score by two for either one day or one week, depending on the
// skill used (printed p. 163).
inline bool dezEminenceDrainsBySkill()
    { return true; }

// the eminence lockout: once the base score falls to zero the priest cannot
// use eminence or any of the other skills (printed p. 163).
inline bool dezEminenceZeroBlocksAll()
    { return true; }

// the eminence smite link: the smite skill is connected to the eminence score
// but can be used, at some risk, when eminence is zero or less (printed p.
// 163).
inline bool dezSmiteConnectedButUsableAtZero()
    { return true; }

// ---- the DMO invincibility pins ----

// the invincibility delay base: five rounds times one plus the level band
// (printed pp. 163-165).
inline int dezInvDelayBase()
    { return 5; }

// the invincibility heroic floor: a successful check lets the priest fight
// until -20 hit points instead of dying at zero (printed pp. 163-165).
inline int dezInvHeroicFloor()
    { return -20; }

// the invincibility regen wake: regeneration to -19 or more during the delay
// restores consciousness (printed pp. 163-165).
inline int dezInvConsciousAt()
    { return -19; }

// the invincibility drain: each use lowers the base eminence score by two
// (printed pp. 163-165).
inline int dezInvEminenceCost()
    { return 2; }

// the invincibility minor recovery: unconsciousness for 1 day (printed pp.
// 163-165).
inline int dezInvMinorDays()
    { return 1; }

// the invincibility severe recovery: unconsciousness for 1 week (printed pp.
// 163-165).
inline int dezInvSevereWeeks()
    { return 1; }

// the invincibility extreme recovery: unconsciousness for 1 month (printed
// pp. 163-165).
inline int dezInvExtremeMonths()
    { return 1; }

// the invincibility worked example: a 25th-level priest (printed pp.
// 163-165).
inline int dezInvExampleLevel()
    { return 25; }

// the invincibility example hit points left: 52 (printed pp. 163-165).
inline int dezInvExampleHpLeft()
    { return 52; }

// the invincibility example hit point total: 107 (printed pp. 163-165).
inline int dezInvExampleHpTotal()
    { return 107; }

// the invincibility example delay: ten rounds, then heal lifts him over 60
// hit points and the power word kill fizzles (printed pp. 163-165).
inline int dezInvExampleDelay()
    { return 10; }

// the invincibility example immunity: over 60 hit points carries immunity to
// power word kill (printed pp. 163-165).
inline int dezInvExampleImmuneHp()
    { return 60; }

// the invincibility example timing: the heal comes four rounds into the ten
// (printed pp. 163-165).
inline int dezInvExampleHealRound()
    { return 4; }

// the invincibility example system shock: a 15 Constitution character
// (printed pp. 163-165).
inline int dezInvExampleCon()
    { return 15; }

// the invincibility example system shock roll: 96 percent (printed pp.
// 163-165).
inline int dezInvExampleShockRoll()
    { return 96; }

// the invincibility example margin: 6 percent over what he needed - the roll
// fails and he wakes just long enough to die (printed pp. 163-165).
inline int dezInvExampleShockMargin()
    { return 6; }

// the invincibility multi-effect example: a vampire drained two levels, a
// lich added paralysis (printed pp. 163-165).
inline int dezInvVampireLevels()
    { return 2; }

// the invincibility paralysis recovery: another week (printed pp. 163-165).
inline int dezInvParalysisWeeks()
    { return 1; }

// the invincibility nine-week sum: one month per drained level plus the
// paralysis week (printed pp. 163-165).
inline int dezInvNineWeeks()
    { return 9; }

// the invincibility delay ladder: priest levels 21-23 band 0 (5 rounds of
// delay), 24-26 band 1 (10 rounds), and 27 or more the tail band 2 (15
// rounds) - five rounds times one plus the band (printed pp. 163-165).
inline int dezInvDelayBand(int x)
    {
        if (x <= 23) return 0;
        if (x <= 26) return 1;
        return 2;
    }

// the invincibility kinship: very similar to the warrior skill hardiness
// (printed pp. 163-165).
inline bool dezInvLikeWarriorHardiness()
    { return true; }

// the invincibility save order: if the effect allows a saving throw the
// priest rolls the save before checking the skill (printed pp. 163-165).
inline bool dezInvSaveFirst()
    { return true; }

// the invincibility exclusion one: no delay of simple damage from any source,
// including continuing damage such as Melf acid arrow or a sword of wounding,
// or purely physical damage such as severed limbs or broken bones (printed
// pp. 163-165).
inline bool dezInvNoSimpleOrContinuingDamage()
    { return true; }

// the invincibility exclusion two: no protection against effects not directly
// harmful such as magical charms, entanglement or imprisonment (printed pp.
// 163-165).
inline bool dezInvNoCharmsEntangleImprison()
    { return true; }

// the invincibility cure window: the appropriate cure before the delay ends
// means no harm (printed pp. 163-165).
inline bool dezInvCureWithinDelayNoHarm()
    { return true; }

// the invincibility short effects: an effect whose duration is shorter than
// the delay never lands (printed pp. 163-165).
inline bool dezInvShorterDurationNoEffect()
    { return true; }

// the invincibility recovery roll: a system shock roll at the end of the
// recovery time (printed pp. 163-165).
inline bool dezInvSystemShockAtEnd()
    { return true; }

// the invincibility success: a successful system shock awakens the priest
// fully healed, the delayed magic nullified (printed pp. 163-165).
inline bool dezInvShockSuccessHeals()
    { return true; }

// the invincibility failure: a failed system shock means the full force of
// the effect - possible to rest for months and wake only to die (printed pp.
// 163-165).
inline bool dezInvShockFailFullForce()
    { return true; }

// the invincibility stacking: multiple effects mean system shock rolls at the
// end of each recovery period, the order chosen by the player, no awakening
// until all are made (printed pp. 163-165).
inline bool dezInvMultipleEffectsSequential()
    { return true; }

// the invincibility sleeping cure: a cure applied while unconscious recovers
// the priest immediately and automatically (printed pp. 163-165).
inline bool dezInvUnconsciousRecoversInstantly()
    { return true; }

// the heroic effort duration: the priest functions at negative hit points for
// rounds equal to the delay (printed pp. 163-165).
inline bool dezInvHeroicRoundsEqualDelay()
    { return true; }

// the heroic effort price: reduced to -20 or less the character dies once the
// delay expires (printed pp. 163-165).
inline bool dezInvHeroicDeathAtDelayEnd()
    { return true; }

// the heroic rescue: a raise dead or resurrection cast during the delay
// prevents death (printed pp. 163-165).
inline bool dezInvRaiseDuringDelaySaves()
    { return true; }

// the invincibility regeneration: a character returned to life through
// regeneration need not make a system shock roll (printed pp. 163-165).
inline bool dezInvRegenNoShock()
    { return true; }

// the invincibility amulet: an amulet of life protection works like
// regeneration with no system shock roll (printed pp. 163-165).
inline bool dezInvAmuletNoShock()
    { return true; }

// the invincibility gate: ineffective when the base eminence score is zero or
// less (printed pp. 163-165).
inline bool dezInvIneffectiveAtZero()
    { return true; }

// the invincibility drain period: for the rest of the day, unlike the
// one-week drains of the other eminence skills (printed pp. 163-165).
inline bool dezInvDrainRestOfDay()
    { return true; }

// ---- the DMO loan pins ----

// the loan duration: transferred hit points remain with the recipient for 24
// hours or until lost in an attack (printed p. 165).
inline int dezLoanHours()
    { return 24; }

// the loan ladder row count: four level bands (printed p. 165).
inline int dezLoanBandCount()
    { return 4; }

// the loan drain: each attempt lowers the base score by two (printed p. 165).
inline int dezLoanCost()
    { return 2; }

// the loan drain period: for one week (printed p. 165).
inline int dezLoanDays()
    { return 7; }

// the loan band: priest levels 15-19 band 0 (1d8+2 hit points), 20-24 band 1
// (2d6+4), 25-29 band 2 (3d6+6), and 30 or more the tail band 3 (4d6+8), read
// through the dezLoanGrid (printed p. 165).
inline int dezLoanBand(int x)
    {
        if (x <= 19) return 0;
        if (x <= 24) return 1;
        if (x <= 29) return 2;
        return 3;
    }

// the loan dice-count column: 1, 2, 3, 4 dice across the four bands (printed
// p. 165).
inline int dezLoanDice(int b)
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
            return -99;
        }
    }

// the loan die-sides column: d8 in the first band, d6 in the other three
// (printed p. 165).
inline int dezLoanSides(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        default:
            return -99;
        }
    }

// the loan bonus column: +2, +4, +6, +8 across the four bands (printed p.
// 165).
inline int dezLoanBonus(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        default:
            return -99;
        }
    }

// the loan effect: a successful roll transfers a small amount of hit points
// from the priest to a living creature or vice versa (printed p. 165).
inline bool dezLoanTransfersVitality()
    { return true; }

// the loan unwilling donor: an attack roll is required before the skill roll
// (printed p. 165).
inline bool dezLoanUnwillingNeedsAttackRoll()
    { return true; }

// the loan loss: the donor loses the points as though subjected to a damaging
// attack, restorable by rest or magical healing (printed p. 165).
inline bool dezLoanLostLikeDamage()
    { return true; }

// the loan overdose: if the donor has insufficient hit points only those
// available transfer and the donor dies (printed p. 165).
inline bool dezLoanDonorDiesIfInsufficient()
    { return true; }

// the loan gate: useless once the base score falls to zero or less (printed
// p. 165).
inline bool dezLoanUselessAtZero()
    { return true; }

// ---- the DMO smite pins ----

// the smite cone near end: 5 feet in diameter at the priest body (printed pp.
// 165-166).
inline int dezSmiteBodyDiameter()
    { return 5; }

// the smite cone far end: 30 feet in diameter at the far end (printed pp.
// 165-166).
inline int dezSmiteFarDiameter()
    { return 30; }

// the smite cone length base: 30 feet plus 20 per level band (printed pp.
// 165-166).
inline int dezSmiteLengthBase()
    { return 30; }

// the smite cone length step: +20 feet per band - 30, 50, 70, 90, 110
// (printed pp. 165-166).
inline int dezSmiteLengthStep()
    { return 20; }

// the smite awe save gate: creatures with more than 10 Hit Dice or levels get
// a saving throw vs. spell (printed pp. 165-166).
inline int dezSmiteAweSaveHd()
    { return 10; }

// the smite awe duration: one round per priest level plus 1d8 rounds (printed
// pp. 165-166).
inline int dezSmiteAweExtraDieSides()
    { return 8; }

// the smite blind save gate: only creatures with 12 or more levels or Hit
// Dice get a saving throw vs. breath weapon (printed pp. 165-166).
inline int dezSmiteBlindSaveHd()
    { return 12; }

// the smite blind movement: two-thirds the normal rate (printed pp. 165-166).
inline int dezSmiteBlindMoveNum()
    { return 2; }

// the smite blind movement: 2/3 rate, the denominator (printed pp. 165-166).
inline int dezSmiteBlindMoveDen()
    { return 3; }

// the smite blind penalty: -4 to attack rolls, saving throws, initiative
// rolls and ability checks (printed pp. 165-166).
inline int dezSmiteBlindPenalty()
    { return 4; }

// the smite deaf movement: three-quarters the normal rate (printed pp.
// 165-166).
inline int dezSmiteDeafMoveNum()
    { return 3; }

// the smite deaf movement: 3/4 rate, the denominator (printed pp. 165-166).
inline int dezSmiteDeafMoveDen()
    { return 4; }

// the smite deaf penalty: -2 to attack rolls, initiative rolls and ability
// checks (printed pp. 165-166).
inline int dezSmiteDeafPenalty()
    { return 2; }

// the smite deaf casting: 50 percent chance any attempted spell fails
// outright (printed pp. 165-166).
inline int dezSmiteDeafSpellFailPct()
    { return 50; }

// the smite burn damage: 6d8 points, save vs. breath weapon for half (printed
// pp. 165-166).
inline int dezSmiteBurnDice()
    { return 6; }

// the smite burn die: d8 (printed pp. 165-166).
inline int dezSmiteBurnSides()
    { return 8; }

// the smite death damage: a doubled burning effect, 12d8, save vs. spells for
// half (printed pp. 165-166).
inline int dezSmiteDeathDice()
    { return 12; }

// the smite death dust gate: enemies with 4 Hit Dice/levels or less are
// immediately reduced to dust (printed pp. 165-166).
inline int dezSmiteDeathDustHd()
    { return 4; }

// the smite immobilize gate: creatures of 6+1 Hit Dice/levels or less are
// automatically paralyzed - the printed 6+1 form (printed pp. 165-166).
inline int dezSmiteImmobHd()
    { return 6; }

// the smite immobilize duration: 1d4+2 turns, the dice (printed pp. 165-166).
inline int dezSmiteImmobTurnsDice()
    { return 1; }

// the smite immobilize duration: 1d4+2 turns, the die (printed pp. 165-166).
inline int dezSmiteImmobTurnsSides()
    { return 4; }

// the smite immobilize duration: 1d4+2 turns, the bonus (printed pp.
// 165-166).
inline int dezSmiteImmobTurnsBonus()
    { return 2; }

// the smite slow gate: creatures with less than 8+1 Hit Dice or levels get no
// saving throw - the printed 8+1 form (printed pp. 165-166).
inline int dezSmiteSlowHd()
    { return 8; }

// the smite slow effect: the same as the 3rd-level wizard spell slow (printed
// pp. 165-166).
inline int dezSmiteSlowSpellLevel()
    { return 3; }

// the smite slow duration: 1d4+2 turns, the dice (printed pp. 165-166).
inline int dezSmiteSlowTurnsDice()
    { return 1; }

// the smite slow duration: 1d4+2 turns, the die (printed pp. 165-166).
inline int dezSmiteSlowTurnsSides()
    { return 4; }

// the smite slow duration: 1d4+2 turns, the bonus (printed pp. 165-166).
inline int dezSmiteSlowTurnsBonus()
    { return 2; }

// the smite drain: each use reduces the base eminence score by two (printed
// pp. 165-166).
inline int dezSmiteEminenceCost()
    { return 2; }

// the smite drain period: for one week (printed pp. 165-166).
inline int dezSmiteDays()
    { return 7; }

// the Marissa example: an eminence score of 4 (printed pp. 165-166).
inline int dezSmiteMarissaEminence()
    { return 4; }

// the Marissa example: a Charisma/Leadership bonus of +4 (printed pp.
// 165-166).
inline int dezSmiteMarissaBonus()
    { return 4; }

// the Marissa example first forced roll: a 3, and the smite works (printed
// pp. 165-166).
inline int dezSmiteMarissaRoll1()
    { return 3; }

// the Marissa example second forced roll: an 18, and it fails (printed pp.
// 165-166).
inline int dezSmiteMarissaRoll2()
    { return 18; }

// the Marissa example after the second smite: a base eminence of -2, raised
// to 2 by the bonus (printed pp. 165-166).
inline int dezSmiteMarissaAfterFirst()
    { return -2; }

// the Marissa example after the failed second smite: -4, leaving no chance to
// smite again (printed pp. 165-166).
inline int dezSmiteMarissaAfterSecond()
    { return -4; }

// the smite cone length ladder: priest levels 18-20 band 0 (a 30 foot cone),
// 21-23 band 1 (50 feet), 24-26 band 2 (70 feet), 27-29 band 3 (90 feet), and
// 30 or more the tail band 4 (110 feet) - 30 feet plus 20 per band (printed
// pp. 165-166).
inline int dezSmiteConeBand(int x)
    {
        if (x <= 20) return 0;
        if (x <= 23) return 1;
        if (x <= 26) return 2;
        if (x <= 29) return 3;
        return 4;
    }

// the smite cone: issues from the priest body in any direction the character
// wishes (printed pp. 165-166).
inline bool dezSmiteConeAnyDirection()
    { return true; }

// the smite control: the priest has no control over the effect, the DM
// chooses from the list (printed pp. 165-166).
inline bool dezSmiteDmChoosesEffect()
    { return true; }

// the smite targeting: only the priest enemies are harmed - allies, innocent
// bystanders and worshippers in good standing are not affected (printed pp.
// 165-166).
inline bool dezSmiteOnlyEnemiesHarmed()
    { return true; }

// the smite awe default: granted when the deity does not find the targets
// offensive or threatening, or when a simple demonstration of power suffices
// (printed pp. 165-166).
inline bool dezSmiteAweDefault()
    { return true; }

// the smite awe image: a two-dimensional depiction of the deity or its symbol
// appears before the priest (printed pp. 165-166).
inline bool dezSmiteAweDepiction()
    { return true; }

// the smite awe save: even on a successful save creatures are awestruck one
// round, regardless of personal immunities (printed pp. 165-166).
inline bool dezSmiteAweOneRoundEvenOnSave()
    { return true; }

// the smite awe upkeep: creatures remain awestruck only while the priest
// stays motionless and concentrates (printed pp. 165-166).
inline bool dezSmiteAweRequiresMotionless()
    { return true; }

// the smite awe latecomers: enemies entering the cone after the image appears
// are fully subject even if they avert their eyes (printed pp. 165-166).
inline bool dezSmiteAweLatecomersSubject()
    { return true; }

// the smite awe break: any motion or the slightest break in concentration
// ends the effect, as does any offensive action by the priest allies (printed
// pp. 165-166).
inline bool dezSmiteAweMotionBreaks()
    { return true; }

// the smite awe distractions: loud noises, magical displays, attacks or
// attempts to steal awestruck equipment or harm them break the effect
// (printed pp. 165-166).
inline bool dezSmiteAweDistractionBreaks()
    { return true; }

// the smite blind casting: blinded spellcasters cannot cast unless they can
// touch their targets (printed pp. 165-166).
inline bool dezSmiteBlindTouchCastingOnly()
    { return true; }

// the smite blind duration: until a heal or cure blindness or deafness spell
// (printed pp. 165-166).
inline bool dezSmiteBlindUntilHealed()
    { return true; }

// the smite burn kill: creatures killed by the flames are reduced to piles of
// ash, no regeneration possible (printed pp. 165-166).
inline bool dezSmiteBurnAshNoRegen()
    { return true; }

// the smite burn equipment: if the target fails the save or is killed, its
// equipment must save vs. disintegration or be reduced to dust (printed pp.
// 165-166).
inline bool dezSmiteBurnEquipmentSaves()
    { return true; }

// the smite burn nature: heatless flames that do not harm the area but can
// affect equipment (printed pp. 165-166).
inline bool dezSmiteBurnHeatless()
    { return true; }

// the smite deaf duration: until a heal or cure blindness or deafness spell
// (printed pp. 165-166).
inline bool dezSmiteDeafUntilHealed()
    { return true; }

// the smite death effect: enemies beyond the dust gate suffer a doubled
// burning effect (printed pp. 165-166).
inline bool dezSmiteDeathDoubledBurn()
    { return true; }

// the smite immobilize form: paralyzed flesh turns into a rigid crystalline
// substance easily shattered (printed pp. 165-166).
inline bool dezSmiteImmobCrystalline()
    { return true; }

// the smite immobilize save: creatures beyond the auto-paralyze gate get a
// save vs. petrification to negate (printed pp. 165-166).
inline bool dezSmiteImmobSaveVsPetrification()
    { return true; }

// the smite immobilize defense: free action is useless against it (printed
// pp. 165-166).
inline bool dezSmiteImmobFreeActionUseless()
    { return true; }

// the smite immobilize kill: striking the crystalline body with any hard
// object forces a save as rock crystal vs. crushing blow, only ring, cloak
// and armor bonuses count, failure is death (printed pp. 165-166).
inline bool dezSmiteImmobShatterKill()
    { return true; }

// the smite plague form: as a cause disease spell, the debilitating
// reversed-cure-disease form with a foul stench (printed pp. 165-166).
inline bool dezSmitePlagueDebilitating()
    { return true; }

// the smite plague limits: neither contagious nor fatal (printed pp.
// 165-166).
inline bool dezSmitePlagueNotContagiousOrFatal()
    { return true; }

// the smite plague cure: a cure disease or breath of life spell from a caster
// of higher level than the priest (printed pp. 165-166).
inline bool dezSmitePlagueHigherLevelCure()
    { return true; }

// the smite plague grant: when the targets are offensive but pose no danger
// to the deity interests (printed pp. 165-166).
inline bool dezSmitePlagueWhenOffensive()
    { return true; }

// the smite slow grant: when the deity is offended but the enemies pose no
// immediate threat to a sacred site, the priest or friendly creatures
// (printed pp. 165-166).
inline bool dezSmiteSlowWhenNoImmediateThreat()
    { return true; }

// the smite free use: with a positive eminence score the priest need not roll
// to smite (printed pp. 165-166).
inline bool dezSmiteNoRollWithPositiveEminence()
    { return true; }

// the smite at zero: with zero or less eminence the priest rolls an eminence
// check, possible only with a Charisma/Leadership bonus large enough to
// offset the negative base (printed pp. 165-166).
inline bool dezSmiteCheckAtZeroOrLess()
    { return true; }

// the smite failure: a failed check displeases the deity (printed pp.
// 165-166).
inline bool dezSmiteFailDispleasesDeity()
    { return true; }

// the smite backlash: at best no effect occurs, at worst the deity directs a
// smite effect upon the priest (printed pp. 165-166).
inline bool dezSmiteFailMaySmitePriest()
    { return true; }

// the Marissa example: the awe effect on the kobolds is broken by a fighter
// wading in with an all-around attack (printed pp. 165-166).
inline bool dezSmiteMarissaAweBrokenByAttack()
    { return true; }

// ---- the DMO spell talisman pins ----

// the spell talisman requirement: priest 12+ - noting the skill is absent
// from the Table 40 roster (printed pp. 166-167).
inline int dezTalReqLevel()
    { return 12; }

// the spell talisman base score: 4 (printed pp. 166-167).
inline int dezTalBase()
    { return 4; }

// the spell talisman slot cost: 1 (printed pp. 166-167).
inline int dezTalCostSlots()
    { return 1; }

// the spell talisman point cost: 3 character points (printed pp. 166-167).
inline int dezTalCostCp()
    { return 3; }

// the talisman worth: at least 100 gold pieces per spell level (printed pp.
// 166-167).
inline int dezTalCostPerLevel()
    { return 100; }

// the talisman storage: a maximum of 24 hours before it crumbles into dust
// and the spell is lost (printed pp. 166-167).
inline int dezTalHours()
    { return 24; }

// the talisman separation: more than one hour from the priest crumbles it
// (printed pp. 166-167).
inline int dezTalSeparateHours()
    { return 1; }

// the talisman release initiative: a +2 modifier (printed pp. 166-167).
inline int dezTalInitBonus()
    { return 2; }

// the Wulf talisman example: a 21st-level priest can have up to 21 levels of
// spells stored (printed pp. 166-167).
inline int dezWulfStoredTotal()
    { return 21; }

// the Wulf talisman example: two spells of 4th level (printed pp. 166-167).
inline int dezWulfStored4th()
    { return 2; }

// the Wulf talisman example: two 3rd-level spells (printed pp. 166-167).
inline int dezWulfStored3rd()
    { return 2; }

// the Wulf talisman example: seven 1st-level spells (printed pp. 166-167).
inline int dezWulfStored1st()
    { return 7; }

// the talisman timing: cast at the beginning of each day, after praying for
// spells, directing the energy into the talisman (printed pp. 166-167).
inline bool dezTalCastAtDayStart()
    { return true; }

// the talisman form: a small object such as a jewel, crystal bead or holy
// symbol blessed by the priest (printed pp. 166-167).
inline bool dezTalSmallObject()
    { return true; }

// the talisman roll: a successful skill roll is required to place a spell
// (printed pp. 166-167).
inline bool dezTalRollToPlace()
    { return true; }

// the talisman failure: if the roll fails the spell is wasted (printed pp.
// 166-167).
inline bool dezTalFailWastesSpell()
    { return true; }

// the talisman casting: all material components on hand and all usual casting
// requirements met (printed pp. 166-167).
inline bool dezTalComponentsRequired()
    { return true; }

// the talisman price: casting effects such as unnatural aging hit the priest
// even if the spell was not placed (printed pp. 166-167).
inline bool dezTalCastingEffectsOnFail()
    { return true; }

// the talisman capacity: the total levels stored cannot exceed the priest
// level (printed pp. 166-167).
inline bool dezTalTotalCappedAtLevel()
    { return true; }

// the talisman spell cap: the highest level spell a priest can place follows
// the same printed ladder as spell sculpting, 1st at 12-14 up to 7th at 30
// plus, read through dezSpellCapBand (printed pp. 166-167).
inline bool dezTalCapSharedLadder()
    { return true; }

// the talisman release: the priest must be holding or carrying the item and
// concentrate briefly and utter a few words (printed pp. 166-167).
inline bool dezTalReleaseRequiresContact()
    { return true; }

// the talisman release guard: the release cannot be disrupted (printed pp.
// 166-167).
inline bool dezTalReleaseUndisruptable()
    { return true; }

// the talisman release limit: a gagged or silenced priest could not release
// the spell (printed pp. 166-167).
inline bool dezTalGaggedOrSilencedBlocks()
    { return true; }

// the talisman release cost: releasing the spell destroys the talisman, the
// spell functioning as if cast normally (printed pp. 166-167).
inline bool dezTalDestroysTalisman()
    { return true; }

// the talisman lock: no being other than the storing priest can release the
// energy (printed pp. 166-167).
inline bool dezTalOnlyStorerReleases()
    { return true; }

// the talisman memory: if the priest memorizes spells again before the 24
// hours expire the stored spell cannot be regained (printed pp. 166-167).
inline bool dezTalNoRememorizeBefore24h()
    { return true; }

// the talisman one-way: a spell cannot transfer from talisman back into
// memory (printed pp. 166-167).
inline bool dezTalNoTransferBack()
    { return true; }

// the talisman destruction: a destroyed talisman loses the spell (printed pp.
// 166-167).
inline bool dezTalDestroyedSpellLost()
    { return true; }

// the talisman fade: the spell fades from memory when released or lost
// (printed pp. 166-167).
inline bool dezTalFadesOnReleaseOrLoss()
    { return true; }

// the talisman planar reach: stored spells can be cast on worlds where the
// local magical factor would not allow the spell (printed pp. 166-167).
inline bool dezTalCastsWhereFactorDisallows()
    { return true; }

// the talisman storage limit: a spell cannot be stored unless the local
// conditions allow the spell to be cast (printed pp. 166-167).
inline bool dezTalStoreNeedsLocalConditions()
    { return true; }

// the talisman release modifier: the +2 initiative is never affected by the
// local magical factor (printed pp. 166-167).
inline bool dezTalInitUnaffectedByFactor()
    { return true; }

}   // namespace rules
