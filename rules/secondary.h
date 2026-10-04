// ====================================================================
// Adnd1 - rules/secondary.h
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

namespace rules {

// ----------------------------------------------------------------------------
// The secondary skills table (p.12)
// ----------------------------------------------------------------------------

struct SecondarySkillRow {
    int lo;
    int hi;
    const char* name;
};

inline int secondaryRowCount() { return 23; }

// The 23 printed bands: 21 named skills, the NO
// SKILL OF MEASURABLE WORTH band (68-85) and the
// ROLL TWICE IGNORING THIS RESULT HEREAFTER band
// (86-00).
inline const SecondarySkillRow& secondaryRow(int i) {
    static const SecondarySkillRow k[23] = {
        { 1, 2, "Armorer" },
        { 3, 4, "Bowyer/fletcher" },
        { 5, 10, "Farmer/gardener" },
        { 11, 14, "Fisher (netting)" },
        { 15, 20, "Forester" },
        { 21, 23, "Gambler" },
        { 24, 27, "Hunter/fisher (hook and line)" },
        { 28, 32, "Husbandman (animal husbandry)" },
        { 33, 34, "Jeweler/lapidary" },
        { 35, 37, "Leather worker/tanner" },
        { 38, 39, "Limner/painter" },
        { 40, 42, "Mason/carpenter" },
        { 43, 44, "Miner" },
        { 45, 46, "Navigator (fresh or salt water)" },
        { 47, 49, "Sailor (fresh or salt)" },
        { 50, 51, "Shipwright (boats or ships)" },
        { 52, 54, "Tailor/weaver" },
        { 55, 57, "Teamster/freighter" },
        { 58, 60, "Trader/barterer" },
        { 61, 64, "Trapper/furrier" },
        { 65, 67, "Woodworker/cabinetmaker" },
        { 68, 85, "NO SKILL OF MEASURABLE WORTH" },
        { 86, 100, "ROLL TWICE IGNORING THIS RESULT HEREAFTER" }
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return k[i];
}

// True for the NO SKILL band row (index 21).
inline bool secondaryIsNoSkill(int i) {
    return i == 21;
}

// True for the ROLL TWICE band row (index 22).
inline bool secondaryIsRollTwice(int i) {
    return i == 22;
}

// The intro prose: when a player character selects
// a class, this profession is assumed to be that
// which the character has been following
// previously, virtually to the exclusion of all
// other activity - thus the particular individual
// is at 1st level of ability.
inline bool secondaryClassAssumedPriorProfession() {
    return true;
}

// However, some minor knowledge of certain mundane
// skills might belong to the player character -
// information and training from early years or
// incidentally picked up while the individual was
// in apprenticeship learning his or her primary
// professional skills.
inline bool secondaryMinorMundaneKnowledgePossible() {
    return true;
}

// If the particular campaign is aimed at a level
// of play where secondary skills can be taken
// into account, then use the table to assign them
// to player characters, or even to henchmen.
inline bool secondaryCampaignAimedAtSkillsUsesTable() {
    return true;
}

// Assign a skill randomly, or select according to
// the background of the campaign.
inline bool secondaryAssignRandomOrPerBackground() {
    return true;
}

// To determine if a second skill is known, roll on
// the table, and if the dice indicate a result of
// TWO SKILLS, then assign a second, appropriate
// one.
inline bool secondarySecondSkillIfTwoSkills() {
    return true;
}

// The adjudication prose: when secondary skills
// are used, it is up to the DM to create and/or
// adjudicate situations in which these skills are
// used or useful to the player character.
inline bool secondaryDMAdjudicatesSituations() {
    return true;
}

// As a general rule, having a skill will give the
// character the ability to determine the general
// worth and soundness of an item, the ability to
// find food, make small repairs, or actually
// construct (crude) items - the armorer example:
// tell the quality of normal armor, repair chain
// links, or perhaps fashion certain weapons.
inline bool secondarySkillGivesWorthSoundnessRepairs() {
    return true;
}

// To determine the extent of knowledge in
// question, simply assume the role of one of
// these skills, one that you know a little
// something about, and determine what could be
// done with this knowledge. Use this as a scale
// to weigh the relative ability of characters
// with secondary skills.
inline bool secondaryAssumeRoleToScaleAbility() {
    return true;
}

}  // namespace rules

