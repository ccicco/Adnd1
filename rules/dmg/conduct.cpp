// R-refactor: split from conduct.h - definitions
#include "rules/dmg/conduct.h"

int Conduct::deityCreatureSentFirstAskPct() {
    // exemplary in faithfulness, first ask:
    // a straight 10 percent chance some
    // creature is sent to aid
    return 10;
}

int Conduct::deityComeChancePct(int level) {
    // the 00 roll: the chance the deity
    // itself comes equals the character
    // level of experience
    if (level < 0) level = 0;
    return level;
}

int Conduct::deityModEachPreviousIntervention() { return -5; }

int Conduct::deityModAlignmentMedial() { return -5; }

int Conduct::deityModAlignmentBorderline() { return -10; }

int Conduct::deityModDirectConfrontation() { return -10; }

int Conduct::deityModOpposingDiametric() { return 1; }

int Conduct::deityModServingProximately() { return 25; }

int Conduct::deityInterventionPct(int level, int previousCount, int alignmentMedial, int alignmentBorderline, int directConfrontation, int opposingDiametric, int servingProximately) {
    // the full modified chance; each
    // previous intervention STACKS -5 (the
    // count is taken as-is, floored at 0);
    // the five situation clauses are 0/1
    // flags, clamped to once each. No
    // floor: the print sets none.
    if (level < 0) level = 0;
    if (previousCount < 0) previousCount = 0;
    if (alignmentMedial < 0) alignmentMedial = 0;
    if (alignmentMedial > 1) alignmentMedial = 1;
    if (alignmentBorderline < 0) alignmentBorderline = 0;
    if (alignmentBorderline > 1) alignmentBorderline = 1;
    if (directConfrontation < 0) directConfrontation = 0;
    if (directConfrontation > 1) directConfrontation = 1;
    if (opposingDiametric < 0) opposingDiametric = 0;
    if (opposingDiametric > 1) opposingDiametric = 1;
    if (servingProximately < 0) servingProximately = 0;
    if (servingProximately > 1) servingProximately = 1;
    return level
        + deityModEachPreviousIntervention() * previousCount
        + deityModAlignmentMedial() * alignmentMedial
        + deityModAlignmentBorderline() * alignmentBorderline
        + deityModDirectConfrontation() * directConfrontation
        + deityModOpposingDiametric() * opposingDiametric
        + deityModServingProximately() * servingProximately;
}

int Conduct::interventionPlaneAllowed(int plane) {
    // Prime Material, Astral and Ethereal:
    // yes; Elemental: DM option; Outer,
    // Positive and Negative: no
    if (plane < 0) plane = 0;
    if (plane > 6) plane = 6;
    static const int t[7] = {
        1, 1, 1, 2, 0, 0, 0,
    };
    return t[plane];
}

int Conduct::elementalGodsBlockOuterDeities() {
    // if elemental gods are placed on the
    // Elemental Planes, the Outer deities
    // will NOT go there
    return 1;
}

int Conduct::secretRollKindCount() { return 7; }

int Conduct::rollIsSecretAlways(int kind) {
    // every kind on the list is always made
    // secretly
    if (kind < 0) kind = 0;
    if (kind > 6) kind = 6;
    return 1;
}

int Conduct::systemShockRollNeverTampered() {
    // the one die roll never to tamper with
    return 1;
}

int Conduct::systemShockFailureForeverDead() {
    // a failed system shock roll to be
    // raised is FOREVER DEAD
    return 1;
}

int Conduct::integrationAveragingDieMin() {
    // the d4 + 1 averaging die: 2
    return 2;
}

int Conduct::integrationAveragingDieMax() {
    // the d4 + 1 averaging die: 5
    return 5;
}

int Conduct::integrationAverageWorksUpToLevel() {
    // the averaging die works up to an
    // average of 8th level
    return 8;
}

int Conduct::integrationAboveCeilingStartLevel() {
    // above the ceiling, newcomers start at
    // 4th or higher
    return 4;
}

int Conduct::neophyteFullCoopLevel() {
    // full co-operation at 3rd or 4th level
    // (3 pinned as the low edge)
    return 3;
}

int Conduct::multipleCharactersProhibited() {
    // no absolute prohibition
    return 0;
}

int Conduct::multipleCharactersFreeInterchange() {
    // money and valuables cannot be freely
    // interchanged
    return 0;
}

int Conduct::troublesomeCharismaLossPoints() {
    // the permanent loss of a point of
    // charisma
    return 1;
}

int Conduct::etherealMummyAlwaysSurprise() {
    // the ethereal mummy always strikes by
    // surprise
    return 1;
}
