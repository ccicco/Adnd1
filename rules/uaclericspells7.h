// ===========================================================================
// Adnd1 - rules/uaclericspells7.h
// The UA NEW CLERIC SPELLS (p. 42) pins, R349: the 7th-level
// spell descriptions - exaction and succor. With this round
// all seven levels are pinned (R343 through this round) and the
// gap item CLOSES.
// Pin-era pattern (R322): pinned data only - no engine site
// exists. The R341 continued table prints ZERO 7th-level
// fragments (the column is empty) - both names pin from the
// prose alone.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (established R343, corroborated
//     each round since): the OCR prints 7 where 1 belongs in
//     the stat cells. This round's two 7s decode as 1, both
//     verbatim with doubt pending the PDF: exaction casting
//     "7 round" = 1 round (the abjure precedent, R346, prints
//     the same garble); succor casting "7 day" = 1 day (no
//     corroboration found - the later editions' prints do not
//     show the casting time in the reachable text).
//   - the exaction stat cells interleave: the Range cell prints
//     blank and the bare value "1" prints after the Casting
//     Time line - position-decoded as Range 1 inch (the R346
//     cloak interleave precedent).
//   - the exaction creature-example sentence garbles:
//     "including or devas dei- and powerful "name" demons ...
//     but not ties of any sort" - the hyphen fragment "dei-"
//     and the tail "ties" are the split word DEITIES; decoded:
//     including devas, deities and powerful "name" demons, for
//     instance, but not deities of any sort.
//   - the exaction opener prints "When this spell is" with the
//     next word lost - decoded as "When this spell is cast"
//     (the universal spell-opener formula); flagged.
//   - the exaction mid-prose shatters: "which is to / upon /
//     perform the required service. / of the / service, the
//     subject creature is transported" - decoded: the spell
//     acts as a quest upon the creature which is to perform
//     the required service; upon completion of the service,
//     the subject creature is transported to the vicinity of
//     the cleric; the exact words of the shatter stay a hole.
//   - the succor prose runs past a page-header interleave: the
//     banner "## DRUID SPELLS (1ST LEVEL)" prints mid-sentence
//     ("...will be instantly transported to / [banner] / the
//     sanctuary of the cleric...") - the banner is not content;
//     the sentence is read through it.
//   - the succor reverse shatters: "transported to the it /
//     iate vicinity of the / of the / item when it is broken"
//     - decoded: transported to the immediate vicinity of the
//     [bearer] of the item; the possessor word is lost - a
//     hole; the sense (immediate vicinity of the item when
//     broken and the command word said) is pinned.
//   - the curly marks (established R343): the range prints 1
//     with the right double quote; the summons prints curly
//     double quotes; the pins normalize to ASCII.
//
// OCR holes (the item CLOSES this round; these stay pending
// the PDF): the exaction opener word; the creature-example
// garble region; the completion-transport shatter; the succor
// reverse vicinity shatter (the possessor word); the two
// family casting-time decodes.
// ===========================================================================

#pragma once

namespace rules {

// ---- exaction (Evocation - Alteration), p. 42 ----
inline const char* uac7ExactionName()
    { return "Exaction (Evocation - Alteration)"; }

inline bool uac7ExactionComponentsVSM()
    { return true; }

inline int uac7ExactionLevel()
    { return 7; }

// The Range cell prints blank; the bare "1" prints after the
// Casting Time line - position-decoded as 1 inch.
inline int uac7ExactionRangeInches()
    { return 1; }

// The casting time prints "7 round" - the digit-garble family
// decodes 1 round (the abjure precedent); verbatim with doubt
// pending the PDF.
inline int uac7ExactionCastingTimeRounds()
    { return 1; }

inline bool uac7ExactionSaveSpecial()
    { return true; }

inline bool uac7ExactionDurationSpecial()
    { return true; }

inline bool uac7ExactionAoeOneCreature()
    { return true; }

// The opener prints "When this spell is" with the next word
// lost - decoded as "cast" (the universal formula); flagged.
inline bool uac7ExactionWhenCastOpenerDecoded()
    { return true; }

inline bool uac7ExactionOpenerFragmentLost()
    { return true; }

// Confronts some powerful creature from another plane and
// requires of it some duty or quest.
inline bool uac7ExactionConfrontsExtraplanar()
    { return true; }

inline bool uac7ExactionRequiresDutyOrQuest()
    { return true; }

// The garbled examples decoded: including devas, deities and
// powerful "name" demons, for instance - but not deities of
// any sort.
inline bool uac7ExactionExamplesIncludeDevasDemons()
    { return true; }

inline bool uac7ExactionNotOnDeities()
    { return true; }

inline bool uac7ExactionExampleFragmentLost()
    { return true; }

// The creature may not be one ethically or morally opposed to
// the cleric - not evil if the cleric is good, not chaotic if
// the cleric is lawful.
inline bool uac7ExactionNoEthicalMoralOpposition()
    { return true; }

// An absolute (true) neutral creature is in effect greatly
// opposed to both good and evil, and both law and chaos.
inline bool uac7ExactionTrueNeutralOpposed()
    { return true; }

// The caster must know something about the creature to exact
// service from it, or else offer some fair trade in return.
inline bool uac7ExactionMustKnowOrFairTrade()
    { return true; }

// If the cleric knows the creature has received a favor from
// someone of the cleric's alignment, the exaction can name
// this as cause.
inline bool uac7ExactionPastFavorAsCause()
    { return true; }

// If no balancing reason for service is known, some valuable
// gift or service must be pledged in return.
inline bool uac7ExactionPledgeIfNoReason()
    { return true; }

// The service exacted must be reasonable with respect to the
// past or promised favor or reward.
inline bool uac7ExactionServiceMustBeReasonable()
    { return true; }

// The spell then acts as a quest upon the creature which is
// to perform the required service.
inline bool uac7ExactionActsAsQuest()
    { return true; }

// The shattered completion clause decoded: upon completion of
// the service, the subject creature is transported to the
// vicinity of the cleric; the exact words stay a hole.
inline bool uac7ExactionTransportedOnCompletion()
    { return true; }

inline bool uac7ExactionCompletionFragmentLost()
    { return true; }

// The cleric must then and there return the promised reward -
// irrevocable cancellation of a past debt or the giving of
// some service or other material reward.
inline bool uac7ExactionRewardReturnRequired()
    { return true; }

// Upon so doing, the creature is instantly freed to return to
// its own plane.
inline bool uac7ExactionCreatureFreedOnReward()
    { return true; }

// Failure to fulfill the promise to the letter: at the very
// least, the cleric becomes subject to exaction by the
// subject creature or by its master, liege, etc.
inline bool uac7ExactionFailureInvitesCounterExaction()
    { return true; }

// At worst, the creature may attack the reneging cleric
// without fear of any of his or her spells affecting it -
// total immunity from the spell powers of the cleric so
// doing.
inline bool uac7ExactionFailureGrantsSpellImmunity()
    { return true; }

// The material: the cleric's holy/unholy symbol, some matter
// or substance from the plane of the creature, and knowledge
// of the creature's nature and/or actions written out on a
// parchment leaf that is burned to seal the bargain.
inline bool uac7ExactionMaterialSymbolPlaneMatterScroll()
    { return true; }

// ---- succor (Alteration - Enchantment) Reversible, p. 42 ----
inline const char* uac7SuccorName()
    { return "Succor (Alteration - Enchantment)"
             " Reversible"; }

inline bool uac7SuccorReversible()
    { return true; }

inline bool uac7SuccorComponentsVSM()
    { return true; }

inline int uac7SuccorLevel()
    { return 7; }

// The casting time prints "7 day" - the family decodes 1 day;
// no corroboration found - verbatim with doubt pending the
// PDF.
inline int uac7SuccorCastingTimeDays()
    { return 1; }

inline bool uac7SuccorRangeTouch()
    { return true; }

inline bool uac7SuccorSaveNone()
    { return true; }

inline bool uac7SuccorDurationSpecial()
    { return true; }

inline bool uac7SuccorAoeOneIndividual()
    { return true; }

// Creates a powerful dweomer in some specially prepared
// object - a string of prayer beads, a small clay tablet, an
// ivory baton, etc.
inline bool uac7SuccorDweomerInPreparedObject()
    { return true; }

inline int uac7SuccorObjectExampleCount()
    { return 3; }

inline const char* uac7SuccorObjectExampleName(int i)
    { static const char* const k[3] = {
        "a string of prayer beads",
        "a small clay tablet", "an ivory baton" };
      if (i < 0) i = 0; if (i > 2) i = 2;
      return k[i]; }

// The object radiates magic, for it contains the power to
// instantaneously transport its possessor to the sanctuary of
// the cleric who created its dweomer.
inline bool uac7SuccorRadiatesMagic()
    { return true; }

inline bool uac7SuccorTransportsPossessorToSanctuary()
    { return true; }

// Once the item is magicked, the cleric must give it willingly
// to an individual, at the same time informing him or her of
// a command word.
inline bool uac7SuccorGivenWillinglyWithCommandWord()
    { return true; }

// To use the item, the recipient must speak the command word
// at the same time that he or she rends or breaks the item.
inline bool uac7SuccorBreakItemWithCommandWord()
    { return true; }

// The individual and all worn and carried gear is instantly
// transported to the sanctuary of the cleric - just as if
// capable of speaking a word of recall spell. No other
// creatures can be affected.
inline bool uac7SuccorWordOfRecallEquivalent()
    { return true; }

inline bool uac7SuccorNoOtherCreatures()
    { return true; }

// The reversed application: enables the cleric to be
// transported to the immediate vicinity of the item when it
// is broken and the command word said - the possessor word is
// lost in the shatter; the sense is pinned.
inline bool uac7SuccorReverseSummons()
    { return true; }

inline bool uac7SuccorReverseVicinityFragmentLost()
    { return true; }

// The cleric can choose not to be affected by this summons,
// deciding at the instant when the transportation is to take
// place.
inline bool uac7SuccorClericMayDeclineSummons()
    { return true; }

// If the cleric declines, the opportunity is gone forever and
// the spell is wasted.
inline bool uac7SuccorDeclineWastesSpell()
    { return true; }

// The cost of preparing the special item (for either version
// of the spell) varies from 2,000 to 5,000 gold pieces.
inline int uac7SuccorPreparationCostMinGP()
    { return 2000; }

inline int uac7SuccorPreparationCostMaxGP()
    { return 5000; }

inline bool uac7SuccorEitherVersionCosts()
    { return true; }

// The R341 continued table: the 7th-level column prints ZERO
// fragments (the column is empty) - both of this round's
// names pin from the prose alone.
inline bool uac7ExactionSeamFragmentsOnly()
    { return true; }

inline bool uac7SpellsPinFromProse()
    { return true; }

}   // namespace rules
