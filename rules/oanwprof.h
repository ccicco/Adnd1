// =========================================================================================
// Adnd1 - rules/oanwprof.h
// NON-WEAPON PROFICIENCIES, printed capture pp. 101-103 - the OA non-weapon
// proficiencies round
// census 574 -> 575.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the section -
// the prose cross-checked doctrine by doctrine between the two passes (the
// categories, the learning requirements and the base-chance rules opening on
// capture p. 101 of the print pass, the slot-improvement floor, the
// magical-item rule, the Akimori example, the optional bonuses and the
// success-and-failure doctrine printing on p. 102, the contests closing on p.
// 103; compressed p. 53 carries the full pass). Every doctrine agrees between
// the passes save one OCR artifact class: the compressed pass renders the
// slot bonus and the optional bonuses as minus signs (adds - 1 to the die
// roll, a bonus of - 1, - 2, he is now - 3 on the die roll) where the print
// pass prints the pluses (+1 per slot, +1 and +2 bonuses, +1 and +3 on the
// die roll) - the Akimori arithmetic (17 to 16 to 14, the chance FALLS as the
// bonus rises) would read nonsense with genuine minuses on the die-roll
// modifiers, so the print signs settle genuine pluses per the R650
// plus-as-minus artifact precedent, and the pins carry the print reading. The
// numbers pin as consts - the four categories, the second-level improvement
// opening, the +1 slot bonus, the never-below-3 floor, the Akimori example
// pair (base 17, chances 16 and 14 at third and fourth), the optional +1/+2
// bonuses and the informal/formal contest experience at 50 and 100 times the
// host's level; the categorical rules pin as bools - the only-barbarians
// rule, the category learning environments, the no-study-times doctrine, the
// tools-and-guidance requirement, the base-like-to-hit doctrine, the
// never-improves rule, the magical-only-if-known rule, the strictly-optional
// rule, the success-and-failure doctrines and the contest rules (formal vs
// impromptu, the elimination resolution, the inauspicious all-fail rule).
// Names and text ride comments - Torimatsu Akimori, the calligraphy example,
// weapon-smith and armorer as the always-roll proficiencies. The Proficiency
// Tables cross-references (Tables 56 and 58-61) close in their own rounds
//
// the gap census after this round: 104 closed, 131 open - the Non-Weapon
// Proficiencies box flips (census 574 -> 575); NEXT - R653: Table 56
// (Character Proficiencies), capture p. 99, prefix dhn (verify free), audit
// "R653 OA character proficiencies audit", include after rules/oanwprof.h
//
namespace rules {

// ---- the category and learning pins ----

// the four peaceful-skill categories - Common, Artisan, Court and Barbarian
// (capture p. 101 of the print pass; compressed p. 53)
inline int dhmCategoryCount()
    { return 4; }

// only barbarian characters can learn barbarian proficiencies (capture p. 101
// of the print pass; compressed p. 53)
inline bool dhmOnlyBarbariansLearnBarbarian()
    { return true; }

// the categories set the learning environment and assist the DM with NPC
// proficiencies - the peasant the Common list, the noble the Court list
// (capture p. 101 of the print pass; compressed p. 53)
inline bool dhmCategoriesSetLearningEnvironment()
    { return true; }

// no required times of study for the peaceful proficiencies (capture p. 101
// of the print pass; compressed p. 53)
inline bool dhmNoRequiredStudyTimes()
    { return true; }

// learning needs the tools at hand plus an environment with training and
// guidance from those skilled in the art (capture p. 101 of the print pass;
// compressed p. 53)
inline bool dhmLearningNeedsToolsAndGuidance()
    { return true; }

// the amount of contact with the masters purposely left undecided (capture p.
// 101 of the print pass; compressed p. 53)
inline bool dhmContactAmountUndecided()
    { return true; }

// ---- the base-chance and slot-improvement pins ----

// the base number is identical to the to-hit roll - this number or greater on
// 1d20 succeeds (capture p. 101 of the print pass; compressed p. 53)
inline bool dhmBaseLikeToHitRoll()
    { return true; }

// the base number never improves with level, unlike weapon proficiencies
// (capture p. 101 of the print pass; compressed p. 53)
inline bool dhmBaseNeverImprovesWithLevel()
    { return true; }

// the slot improvement opens at second level or beyond (capture p. 101 of the
// print pass; compressed p. 53)
inline int dhmImproveFromLevel()
    { return 2; }

// each additional slot spent adds +1 to the die roll - the print pass prints
// the plus, the compressed renders it as a minus (the R650 artifact class;
// capture p. 101 of the print pass; compressed p. 53)
inline int dhmSlotBonusPerSlot()
    { return 1; }

// no limit to the slots spent on a single peaceful proficiency (capture p.
// 102 of the print pass; compressed p. 53)
inline bool dhmNoLimitOnSlotsSpent()
    { return true; }

// the chance of success after all modifiers never less than 3 on 1d20
// (capture p. 102 of the print pass; compressed p. 53)
inline int dhmSuccessFloor()
    { return 3; }

// magical proficiency items only help if the proficiency is already known
// (capture p. 102 of the print pass; compressed p. 53)
inline bool dhmMagicOnlyIfKnown()
    { return true; }

// ---- the Akimori calligraphy example pins ----

// the Akimori example - two slots to gain calligraphy at first level (capture
// p. 102 of the print pass; compressed p. 53)
inline int dhmAkimoriCalligSlots()
    { return 2; }

// the calligraphy base chance of success 17 (capture p. 102 of the print
// pass; compressed p. 53)
inline int dhmAkimoriCalligBase()
    { return 17; }

// the chance at third level 16 - one additional slot, +1 on the die roll
// (capture p. 102 of the print pass; compressed p. 53)
inline int dhmAkimoriChanceAtThird()
    { return 16; }

// the chance at fourth level 14 - two more slots, +3 on the die roll (capture
// p. 102 of the print pass; compressed p. 53)
inline int dhmAkimoriChanceAtFourth()
    { return 14; }

// ---- the optional bonus pins ----

// the optional bonus for providing an example of the skill - +1 (capture p.
// 102 of the print pass; compressed p. 53)
inline int dhmOptExampleBonus()
    { return 1; }

// the optional bonus for actually performing the skill - +2 (capture p. 102
// of the print pass; compressed p. 53)
inline int dhmOptPerformBonus()
    { return 2; }

// the optional bonuses rest on the actions of the player, not the character
// (capture p. 102 of the print pass; compressed p. 53)
inline bool dhmOptPlayerNotCharacter()
    { return true; }

// the peaceful proficiency bonus rule is strictly optional (capture p. 102 of
// the print pass; compressed p. 53)
inline bool dhmOptStrictlyOptional()
    { return true; }

// ---- the success-and-failure pins ----

// most peaceful proficiencies have no clear-cut success or failure - no die
// roll required in normal cases (capture p. 102 of the print pass; compressed
// p. 53)
inline bool dhmMostNoClearCutCheck()
    { return true; }

// the quality roll - at or above the base chance is superior work, below is
// average or worse (capture p. 102 of the print pass; compressed p. 53)
inline bool dhmQualityRollAtBaseSuperior()
    { return true; }

// some proficiencies - weapon-smith, armorer - always roll, noted on the
// Proficiency Tables (capture p. 102 of the print pass; compressed p. 53)
inline bool dhmSomeAlwaysRoll()
    { return true; }

// ---- the contest pins ----

// contests in the peaceful arts are a regular feature of life in the OA world
// (capture p. 102 of the print pass; compressed p. 53)
inline bool dhmContestsRegularFeature()
    { return true; }

// the victors gain honor and experience, the defeated lose honor - the
// outcome moves the social position (capture p. 102 of the print pass;
// compressed p. 53)
inline bool dhmVictorsGainHonorAndXP()
    { return true; }

// formal contests at court or noble households are announced in advance, with
// a chosen subject or improvisation (capture p. 102 of the print pass;
// compressed p. 53)
inline bool dhmFormalAnnouncedInAdvance()
    { return true; }

// non-attendance at a formal contest costs a small loss of honor unless
// circumstances prevent it (capture p. 103 of the print pass; compressed p.
// 53)
inline bool dhmNonattendanceLosesHonor()
    { return true; }

// impromptu contests carry smaller honor gains and losses than formal affairs
// (capture p. 103 of the print pass; compressed p. 53)
inline bool dhmImpromptuSmallerStakes()
    { return true; }

// the contest resolution - a failed die roll eliminates the contestant,
// repeats until one remains the winner (capture p. 103 of the print pass;
// compressed p. 53)
inline bool dhmFailureEliminatesContestant()
    { return true; }

// if all entrants fail the first die roll the contest is inauspicious - no
// winner, no honor changes (capture p. 103 of the print pass; compressed p.
// 53)
inline bool dhmAllFailFirstIsInauspicious()
    { return true; }

// the informal contest win - experience 50 times the host's level (capture p.
// 103 of the print pass; compressed p. 53)
inline int dhmInformalContestXPBase()
    { return 50; }

// the formal contest win - experience 100 times the host's level (capture p.
// 103 of the print pass; compressed p. 53)
inline int dhmFormalContestXPBase()
    { return 100; }

}   // namespace rules
