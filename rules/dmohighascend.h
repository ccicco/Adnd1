// =========================================================================================
// Adnd1 - rules/dmohighascend.h
// DEMIHUMANS AND DIVINE ASCENSION - DMO Chapter 7, round five of five: the
// demihuman advancement doctrine (retirement is what is supposed to happen,
// do not ignore the limits, the limits are the price of the demihuman
// advantages), the four solutions (a wish or 10th-level transformation spell
// to become human; a wish or 10th-level imbue spell per level beyond the
// racial maximum with the experience earned; the Slow Advancement rule with
// humans pulling ahead from 10th level; slow-after-max with the racial heroic
// task per extra level), the beyond-30th ceiling (all advancement stops at
// 30th, the pinnacle of mortal achievement, more hit points than five normal
// men, powers greater than the avatars), and the divine ascension path (seek
// anytime after 20th, never turn back, the divine sponsor, the gift at the
// experience-point total value, the 500,000-per-point saving throw benefit
// down to a minimum of three, the Table 59 offering roll with the three match
// columns, the heroic task with its five examples, no ability score under 13,
// the demigod-and-NPC ending, and the closing line: AD&D is a game of heroes,
// not gods).
// census 534 -> 535.
//
// verified against printed pp. 178-179 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns, the djvu.txt full texts; the tsr02156
// ABBYY read is primary and the tesseract read is cross-checked; leaf N =
// printed page N). A prose-only round with no printed grids; both captures
// agree on every number. The only OCR artifact is the standing lOth-for-10th
// misread both captures make on the spell names (transformation, imbue),
// settled as 10th-level per the index and the standing OCR class. THE CHAPTER
// 7 PARENT flips with this round: every Chapter 7 child has now landed (R608
// through R612).
//
// the gap census after this round: 93 closed, 3 open - the Chapter 7 parent
// and its last two children flip in round five of five; the DMO arc closes on
// R613 (the Appendix: Spell Dueling Characteristics, pp. 180-188) and the
// Index (pp. 189-192).
//
namespace rules {

// ---- the DMO demihuman doctrine pins ----

// the demihuman doctrine: demihuman characters are usually forced to retire
// or assume secondary roles once human characters reach high levels and the
// demihumans reach their advancement limits - that is exactly what is
// supposed to happen (printed p. 178).
inline bool dfbRetireIsIntended()
    { return true; }

// the demihuman doctrine: do not ignore demihuman advancement limits - many
// DMs are tempted to, especially when players are unwilling to retire their
// high-level demihuman characters (printed p. 178).
inline bool dfbDontIgnoreLimits()
    { return true; }

// the demihuman doctrine: the advancement limits are the price players must
// pay for gaining demihuman advantages at lower levels (printed p. 178).
inline bool dfbLimitsAreThePrice()
    { return true; }

// the demihuman doctrine: ignoring the advancement limits unbalances play by
// placing high-level power in the hands of characters who already have extra
// abilities (printed p. 178).
inline bool dfbIgnoringUnbalancesPlay()
    { return true; }

// the demihuman doctrine: ignoring the advancement limits is grossly unfair
// to players who chose human characters and labored to reach the point where
// their choices pay dividends in unlimited advancement (printed p. 178).
inline bool dfbUnfairToHumanPlayers()
    { return true; }

// the demihuman solutions count: the DM can solve the demihuman advancement
// problem in four ways without forcing demihuman characters out of the game
// (printed p. 178).
inline int dfbSolutionCount()
    { return 4; }

// the demihuman doctrine: demihuman advancement limits are a fact of life in
// any AD&D game world (printed p. 178).
inline bool dfbLimitsFactOfLife()
    { return true; }

// the first solution: a demihuman character can use a wish or 10th-level
// transformation spell to become human - the character might still look and
// act demihuman but has put aside the racial characteristics and special
// racial abilities that held the character back (printed p. 178).
inline bool dfbSolutionWishTransformation()
    { return true; }

// the second solution: a demihuman character can use a wish or 10th-level
// imbue spell to gain one level beyond the normal racial maximum (printed p.
// 178).
inline bool dfbSolutionWishImbue()
    { return true; }

// the second solution gate: the character must have earned enough experience
// to actually gain the level (printed p. 178).
inline bool dfbImbueNeedsEarnedXp()
    { return true; }

// the second solution cost: each level gained beyond the maximum requires one
// wish or 10th-level imbue spell (printed p. 178).
inline int dfbImbueSpellsPerLevel()
    { return 1; }

// the third solution: the DM can use the Slow Advancement rule from Chapter 2
// of the Dungeon Master Guide (printed p. 178).
inline bool dfbSolutionSlowAdvancement()
    { return true; }

// the third solution note: at low levels slow advancement does not much
// affect play, but humans begin to pull ahead fairly rapidly once the
// characters reach 10th level or so (printed p. 178).
inline int dfbSlowPullAheadLevel()
    { return 10; }

// the fourth solution: the DM can apply the Slow Advancement rule only after
// demihuman characters reach their maximum levels - representing their
// struggle to stay focused despite the distractions of being a demihuman
// (printed pp. 178-179).
inline bool dfbSolutionSlowOnlyAfterMax()
    { return true; }

// the fourth solution doctrine: reflect the demihuman nonhuman viewpoint by
// requiring a heroic task that furthers the interests of the character race
// each time the character advances a level beyond the usual maximum (printed
// pp. 178-179).
inline bool dfbRacialTaskPerExtraLevel()
    { return true; }

// the fourth solution example: an elf wizard might undertake a quest to
// protect a tract of virgin forest and perhaps establish a colony there -
// this kind of effort marks the character as a racial hero instead of a
// demihuman with human interests (printed p. 179).
inline bool dfbRacialHeroExample()
    { return true; }

// ---- the DMO beyond-30th pins ----

// the mortal ceiling: all character advancement stops at 30th level, which
// represents the pinnacle of mortal achievement (printed p. 179).
inline int dfbAdvancementStopsLevel()
    { return 30; }

// the 30th-level note: at this level even a wizard has more hit points than
// five normal men (printed p. 179).
inline bool dfbWizardMoreHpThanFiveMen()
    { return true; }

// the 30th-level note: characters of any class have powers greater than the
// avatars that deities use to conduct business in the mortal world (printed
// p. 179).
inline bool dfbPowersExceedAvatars()
    { return true; }

// the 30th-level note: once a character has gotten this far there is nowhere
// else to go - or is there? (the printed hook into divine ascension) (printed
// p. 179).
inline bool dfbNowhereElseToGo()
    { return true; }

// ---- the DMO ascension path pins ----

// the ascension gate: with the DM approval a character can abandon his or her
// profession and follow a different path to power - divine ascension requires
// a great deal of attention and creativity from both DM and player, and only
// the barest guidelines are given because each character and campaign are
// unique (printed p. 179).
inline bool dfbNeedsDmApproval()
    { return true; }

// the ascension timing: a character can seek to ascend anytime after reaching
// 20th level, or earlier if the DM allows it (printed p. 179).
inline int dfbAscendMinLevel()
    { return 20; }

// the ascension timing: once a character has reached 30th level this is the
// only option that allows the character any further advancement (printed p.
// 179).
inline bool dfbOnlyOptionAfter30()
    { return true; }

// the ascension doctrine: once the character embarks on the path to godhood
// he can never turn back (printed p. 179).
inline bool dfbNeverTurnBack()
    { return true; }

// the ascension doctrine: the character ceases advancing in the original
// class (printed p. 179).
inline bool dfbCeasesClassAdvancement()
    { return true; }

// the ascension doctrine: the character retains all class abilities but gives
// up normal adventuring and acts with a new purpose (printed p. 179).
inline bool dfbRetainsClassAbilities()
    { return true; }

// the ascension procedure: the character must seek a divine sponsor - usually
// a deity appropriate to the character alignment, original class and race -
// and prepare a special offering for that deity (printed p. 179).
inline bool dfbNeedsDivineSponsor()
    { return true; }

// the ascension offering: the gift can be anything the character desires and
// the DM agrees to, and the donation need not be a single item (printed p.
// 179).
inline bool dfbGiftDmAgreed()
    { return true; }

// the ascension offering floor: the gift monetary value must be at least
// equal to the character experience point total - the ratio is one copper or
// coin of value per experience point (printed p. 179).
inline int dfbGiftMinValueXpRatio()
    { return 1; }

// the ascension procedure: while preparing the offering the character
// receives experience points normally (printed p. 179).
inline bool dfbXpNormalDuringPreparation()
    { return true; }

// the ascension benefit: for each 500,000 experience points gained the
// character can lower one saving throw number one point (printed p. 179).
inline int dfbSaveThrowXpStep()
    { return 500000; }

// the ascension benefit floor: the saving throw numbers go down to a minimum
// saving throw of three (printed p. 179).
inline int dfbSaveThrowMin()
    { return 3; }

// the ascension doctrine: the ability to reduce saving throw numbers below
// the normal minimum for the character original class is special, and it is
// why the character must give up the original class (printed p. 179).
inline bool dfbBelowClassMinimumSpecial()
    { return true; }

// the ascension doctrine: the character gains no other benefits from
// accumulated experience - no hit points, proficiencies, skills, etc.
// (printed p. 179).
inline bool dfbNoOtherXpBenefits()
    { return true; }

// ---- the DMO ascension offering and task pins ----

// the ascension procedure: when the offering is completed the character must
// journey to the deity abode and present the gift (printed p. 179).
inline bool dfbJourneyToAbode()
    { return true; }

// the ascension procedure: if the character has been true to the principles
// of alignment and profession the deity probably accepts the gift (printed p.
// 179).
inline bool dfbTrueCharactersLikelyAccepted()
    { return true; }

// the ascension procedure: if in doubt use Table 59 Encounter Reactions from
// the Dungeon Master Guide - matching deity alignment and portfolio use the
// first column, a slight mismatch the second, otherwise the third (printed p.
// 179).
inline bool dfbTable59ReactionRoll()
    { return true; }

// the ascension procedure: if the reaction roll is friendly the deity accepts
// the gift (printed p. 179).
inline bool dfbFriendlyAccepts()
    { return true; }

// the ascension procedure: if not, the deity destroys the gift and sends the
// character away - the character can try again with the same deity or with
// another deity (printed p. 179).
inline bool dfbUnfriendlyDestroysGift()
    { return true; }

// the ascension procedure: the character might not get an immediate audience
// - just finding and entering the deity abode could be an adventure in
// itself, and the Planescape setting material can provide details (printed p.
// 179).
inline bool dfbMaybeNoImmediateAudience()
    { return true; }

// the ascension procedure: once the deity accepts the gift it assigns some
// heroic task to the character, and completing the task proves the character
// mettle - in a Planescape campaign the character becomes the deity proxy
// (printed p. 179).
inline bool dfbDeityAssignsTask()
    { return true; }

// the ascension task examples: five sample heroic tasks are listed (printed
// p. 179).
inline int dfbTaskExampleCount()
    { return 5; }

// the first task example: found a dynasty (printed p. 179).
inline bool dfbTaskExampleDynasty()
    { return true; }

// the second task example: create a new magical item or spell that others
// seek to imitate (printed p. 179).
inline bool dfbTaskExampleCreation()
    { return true; }

// the third task example: find and destroy an artifact from an opposing
// alignment (printed p. 179).
inline bool dfbTaskExampleArtifact()
    { return true; }

// the fourth task example: find and defeat the avatar of a rival deity
// (printed p. 179).
inline bool dfbTaskExampleRivalAvatar()
    { return true; }

// the fifth task example: build a lasting monument to the deity (printed p.
// 179).
inline bool dfbTaskExampleMonument()
    { return true; }

// the ascension procedure: it is up to the DM to create a suitable task and
// design a series of adventures so the character can complete it (printed p.
// 179).
inline bool dfbDmDesignsTaskAdventures()
    { return true; }

// the ascension completion: the character must complete the task and earn
// enough experience to lower all saving throw numbers to three (printed p.
// 179).
inline bool dfbTaskNeedsAllSavesAtThree()
    { return true; }

// the ascension completion floor: the character cannot have any ability score
// or subability score lower than 13 (printed p. 179).
inline int dfbMinAbilityScore()
    { return 13; }

// the ascension completion: when all of that is accomplished the character
// becomes a demigod and companion to the sponsor - and the character becomes
// an NPC under the DM control (printed p. 179).
inline bool dfbBecomesDemigod()
    { return true; }

// the ascension epilogue: some players may be upset that they have worked
// hard only to lose control of their characters - remind them of their
// contributions to the campaign world (printed p. 179).
inline bool dfbPlayersMayBeUpset()
    { return true; }

// the ascension epilogue: new characters can worship their retired heroes and
// demigods, and the players should be invited to help construct the new
// powers portfolios (printed p. 179).
inline bool dfbNewCharactersWorshipHeroes()
    { return true; }

// the ascension epilogue, pinned verbatim: AD&D is a game of heroes, not gods
// (printed p. 179).
inline bool dfbHeroesNotGods()
    { return true; }

}   // namespace rules
