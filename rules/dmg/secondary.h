// ====================================================================
// Adnd1 - rules/dmg/secondary.h
// R173: Secondary skills (DMG p.12) - the player
// character non-professional skills: the 23-band
// SECONDARY SKILLS TABLE and the when-to-use
// guidance for PC backgrounds.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls and selects).
//
// JUDGMENTs: cell-verified against the book upload
// (band arithmetic 1-100 clean) and independently
// confirmed band for band by the mjyoung.net
// transcription; the upload spelling wins where the
// transcription paraphrases.
// ====================================================================

#pragma once



// ----------------------------------------------------------------------------
// The secondary skills table (p.12)
// ----------------------------------------------------------------------------
struct SecondarySkillRow {
    int lo;
    int hi;
    const char* name;
};

// R-refactor: namespace rules -> class Secondary (instance methods)
class Secondary {
public:
    int secondaryRowCount();


// The 23 printed bands: 21 named skills, the NO
// SKILL OF MEASURABLE WORTH band (68-85) and the
// ROLL TWICE IGNORING THIS RESULT HEREAFTER band
// (86-00).
    const SecondarySkillRow& secondaryRow(int i);


// True for the NO SKILL band row (index 21).
    bool secondaryIsNoSkill(int i);


// True for the ROLL TWICE band row (index 22).
    bool secondaryIsRollTwice(int i);


// The intro prose: when a player character selects
// a class, this profession is assumed to be that
// which the character has been following
// previously, virtually to the exclusion of all
// other activity - thus the particular individual
// is at 1st level of ability.
    bool secondaryClassAssumedPriorProfession();


// However, some minor knowledge of certain mundane
// skills might belong to the player character -
// information and training from early years or
// incidentally picked up while the individual was
// in apprenticeship learning his or her primary
// professional skills.
    bool secondaryMinorMundaneKnowledgePossible();


// If the particular campaign is aimed at a level
// of play where secondary skills can be taken
// into account, then use the table to assign them
// to player characters, or even to henchmen.
    bool secondaryCampaignAimedAtSkillsUsesTable();


// Assign a skill randomly, or select according to
// the background of the campaign.
    bool secondaryAssignRandomOrPerBackground();


// To determine if a second skill is known, roll on
// the table, and if the dice indicate a result of
// TWO SKILLS, then assign a second, appropriate
// one.
    bool secondarySecondSkillIfTwoSkills();


// The adjudication prose: when secondary skills
// are used, it is up to the DM to create and/or
// adjudicate situations in which these skills are
// used or useful to the player character.
    bool secondaryDMAdjudicatesSituations();


// As a general rule, having a skill will give the
// character the ability to determine the general
// worth and soundness of an item, the ability to
// find food, make small repairs, or actually
// construct (crude) items - the armorer example:
// tell the quality of normal armor, repair chain
// links, or perhaps fashion certain weapons.
    bool secondarySkillGivesWorthSoundnessRepairs();


// To determine the extent of knowledge in
// question, simply assume the role of one of
// these skills, one that you know a little
// something about, and determine what could be
// done with this knowledge. Use this as a scale
// to weigh the relative ability of characters
// with secondary skills.
    bool secondaryAssumeRoleToScaleAbility();
};
