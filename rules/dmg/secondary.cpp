// R-refactor: split from secondary.h - definitions
#include "rules/dmg/secondary.h"

int Secondary::secondaryRowCount() { return 23; }

const SecondarySkillRow& Secondary::secondaryRow(int i) {
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

bool Secondary::secondaryIsNoSkill(int i) {
    return i == 21;
}

bool Secondary::secondaryIsRollTwice(int i) {
    return i == 22;
}

bool Secondary::secondaryClassAssumedPriorProfession() {
    return true;
}

bool Secondary::secondaryMinorMundaneKnowledgePossible() {
    return true;
}

bool Secondary::secondaryCampaignAimedAtSkillsUsesTable() {
    return true;
}

bool Secondary::secondaryAssignRandomOrPerBackground() {
    return true;
}

bool Secondary::secondarySecondSkillIfTwoSkills() {
    return true;
}

bool Secondary::secondaryDMAdjudicatesSituations() {
    return true;
}

bool Secondary::secondarySkillGivesWorthSoundnessRepairs() {
    return true;
}

bool Secondary::secondaryAssumeRoleToScaleAbility() {
    return true;
}
