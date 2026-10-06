// ====================================================================
// Adnd1 - rules/conduct.h
// R215: the conducting the game pins (DMG
// pp.110-112) - the divine intervention
// procedure and planes rule, the secret
// dice-roll list, the system shock clause,
// the player integration numbers, the
// multiple characters rules, and the
// troublesome-player measures.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the actual beseeching and the
// campaign milieu; the procedure and the
// numeric conventions read here).
//
// Conventions and judgments, named in
// place:
//   - Divine intervention: a character
//     exemplary in faithfulness asking for
//     the FIRST time gets a straight 10
//     percent chance that some creature is
//     sent to aid. If 00 is rolled, the
//     chance that the deity ITSELF comes
//     equals the character level of
//     experience, modified by the six
//     clauses. EACH previous intervention
//     on behalf of the character stacks
//     -5 percent (a count, not a flag);
//     medial alignment behavior -5,
//     borderline -10, a situation requiring
//     direct confrontation with another
//     deity -10, opposing forces of
//     diametrically opposed alignment +1,
//     serving the deity proximately +25 -
//     these five are 0/1 flags, clamped.
//     The total may go negative (no
//     intervention); the print sets no
//     floor, so none is applied.
//   - The planes rule: deities will not
//     intervene on the Outer Planes (the
//     habitation of other deities), nor on
//     the Positive or Negative Material
//     Planes. Elemental Plane intervention
//     is DM option (pinned 2 - and if
//     elemental gods are placed there, the
//     Outer deities will NOT go).
//     Intervention occurs on the Prime
//     Material in most cases, with
//     occasional intervention in the Astral
//     and Ethereal Planes (pinned 1).
//   - The secret rolls: listening, hiding
//     in shadows, detecting traps, moving
//     silently, finding secret doors,
//     monster saving throws, and attacks
//     made upon the party without their
//     possible knowledge - 7 kinds, always
//     made secretly.
//   - The system shock roll to be raised
//     from the dead is the one die roll the
//     DM never tampers with; failure is
//     FOREVER DEAD (both pinned 1).
//   - Player integration: an experienced
//     player without a character enters at
//     roughly the average level - at an
//     average of 4th, an averaging die d4
//     + 1 gives 2 to 5. This works up to an
//     average of 8th; above that, newcomers
//     start at 4th or higher. A neophyte
//     gains full co-operation with veterans
//     at 3rd or 4th level (3 pinned as the
//     low edge).
//   - Multiple characters: no absolute
//     prohibition (allowed 1), but money
//     and valuables cannot be freely
//     interchanged (0) and each is played
//     as an individual.
//   - Troublesome players: strong steps
//     short of expulsion include the
//     permanent loss of a point of charisma
//     (1) and the ethereal mummy which
//     always strikes by surprise (1).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The divine intervention procedure.
// -----------------------------------------------------------------------
inline int deityCreatureSentFirstAskPct() {
    // exemplary in faithfulness, first ask:
    // a straight 10 percent chance some
    // creature is sent to aid
    return 10;
}

inline int deityComeChancePct(int level) {
    // the 00 roll: the chance the deity
    // itself comes equals the character
    // level of experience
    if (level < 0) level = 0;
    return level;
}

inline int deityModEachPreviousIntervention() { return -5; }

inline int deityModAlignmentMedial() { return -5; }

inline int deityModAlignmentBorderline() { return -10; }

inline int deityModDirectConfrontation() { return -10; }

inline int deityModOpposingDiametric() { return 1; }

inline int deityModServingProximately() { return 25; }

inline int deityInterventionPct(int level,
                                 int previousCount,
                                 int alignmentMedial,
                                 int alignmentBorderline,
                                 int directConfrontation,
                                 int opposingDiametric,
                                 int servingProximately) {
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

// -----------------------------------------------------------------------
// The planes rule: 0 no, 1 yes, 2 DM option.
// -----------------------------------------------------------------------
enum InterventionPlane {
    IP_PRIME_MATERIAL = 0,
    IP_ASTRAL,
    IP_ETHEREAL,
    IP_ELEMENTAL,
    IP_OUTER,
    IP_POSITIVE,
    IP_NEGATIVE,
    IP_COUNT
};

inline int interventionPlaneAllowed(int plane) {
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

inline int elementalGodsBlockOuterDeities() {
    // if elemental gods are placed on the
    // Elemental Planes, the Outer deities
    // will NOT go there
    return 1;
}

// -----------------------------------------------------------------------
// The secret dice rolls and the system shock
// clause.
// -----------------------------------------------------------------------
enum SecretRollKind {
    SR_LISTENING = 0,
    SR_HIDING_IN_SHADOWS,
    SR_DETECTING_TRAPS,
    SR_MOVING_SILENTLY,
    SR_FINDING_SECRET_DOORS,
    SR_MONSTER_SAVING_THROWS,
    SR_ATTACKS_WITHOUT_KNOWLEDGE,
    SR_COUNT
};

inline int secretRollKindCount() { return 7; }

inline int rollIsSecretAlways(int kind) {
    // every kind on the list is always made
    // secretly
    if (kind < 0) kind = 0;
    if (kind > 6) kind = 6;
    return 1;
}

inline int systemShockRollNeverTampered() {
    // the one die roll never to tamper with
    return 1;
}

inline int systemShockFailureForeverDead() {
    // a failed system shock roll to be
    // raised is FOREVER DEAD
    return 1;
}

// -----------------------------------------------------------------------
// The player integration numbers.
// -----------------------------------------------------------------------
inline int integrationAveragingDieMin() {
    // the d4 + 1 averaging die: 2
    return 2;
}

inline int integrationAveragingDieMax() {
    // the d4 + 1 averaging die: 5
    return 5;
}

inline int integrationAverageWorksUpToLevel() {
    // the averaging die works up to an
    // average of 8th level
    return 8;
}

inline int integrationAboveCeilingStartLevel() {
    // above the ceiling, newcomers start at
    // 4th or higher
    return 4;
}

inline int neophyteFullCoopLevel() {
    // full co-operation at 3rd or 4th level
    // (3 pinned as the low edge)
    return 3;
}

// -----------------------------------------------------------------------
// The multiple characters rules.
// -----------------------------------------------------------------------
inline int multipleCharactersProhibited() {
    // no absolute prohibition
    return 0;
}

inline int multipleCharactersFreeInterchange() {
    // money and valuables cannot be freely
    // interchanged
    return 0;
}

// -----------------------------------------------------------------------
// The troublesome-player measures.
// -----------------------------------------------------------------------
inline int troublesomeCharismaLossPoints() {
    // the permanent loss of a point of
    // charisma
    return 1;
}

inline int etherealMummyAlwaysSurprise() {
    // the ethereal mummy always strikes by
    // surprise
    return 1;
}

}  // namespace rules
