// ====================================================================
// Adnd1 - rules/dmg/conduct.h
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

// R-refactor: namespace rules -> class Conduct (instance methods)
class Conduct {
public:


// -----------------------------------------------------------------------
// The divine intervention procedure.
// -----------------------------------------------------------------------
    int deityCreatureSentFirstAskPct();
    int deityComeChancePct(int level);
    int deityModEachPreviousIntervention();
    int deityModAlignmentMedial();
    int deityModAlignmentBorderline();
    int deityModDirectConfrontation();
    int deityModOpposingDiametric();
    int deityModServingProximately();
    int deityInterventionPct(int level, int previousCount, int alignmentMedial, int alignmentBorderline, int directConfrontation, int opposingDiametric, int servingProximately);
    int interventionPlaneAllowed(int plane);
    int elementalGodsBlockOuterDeities();
    int secretRollKindCount();
    int rollIsSecretAlways(int kind);
    int systemShockRollNeverTampered();
    int systemShockFailureForeverDead();


// -----------------------------------------------------------------------
// The player integration numbers.
// -----------------------------------------------------------------------
    int integrationAveragingDieMin();
    int integrationAveragingDieMax();
    int integrationAverageWorksUpToLevel();
    int integrationAboveCeilingStartLevel();
    int neophyteFullCoopLevel();


// -----------------------------------------------------------------------
// The multiple characters rules.
// -----------------------------------------------------------------------
    int multipleCharactersProhibited();
    int multipleCharactersFreeInterchange();


// -----------------------------------------------------------------------
// The troublesome-player measures.
// -----------------------------------------------------------------------
    int troublesomeCharismaLossPoints();
    int etherealMummyAlwaysSurprise();
};
