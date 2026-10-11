#!/usr/bin/env python3
# R349: the UA NEW CLERIC SPELLS
# pin round, the 7th level (p.
# 42) - exaction and succor; the
# final level. The digit-garble
# family (established R343)
# decodes the two 7s as 1; the
# exaction range position-decodes
# from the interleave. The R341
# continued table prints zero
# 7th-level fragments - both names
# pin from the prose. The item
# CLOSES this round - all seven
# levels pinned.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)
# ---- (a) the seed: the R348 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R348 landed 2026-10-11: commit',
    '  f9e1522, census 275, the UA',
    '  new cleric spells pin round,',
    '  the 6th level',
    '  (rules/uaclericspells6.h):',
    '  forbiddance (the name header',
    '  never prints - identified by',
    '  the near-verbatim 2e',
    '  descendant text; the ethics',
    '  and morals entry ladder with',
    '  the password gate) and heroes',
    '  feast (the twelve-hour',
    '  benefits and the one-hour',
    '  consume rule); the',
    '  digit-garble family decodes',
    '  the two 7s as 1 (both',
    '  corroborated); the',
    '  forbiddance 6s stay genuine;',
    '  the R341 table prints four',
    '  fragments - neither name',
    '  seam-checks; GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R348 landed 2026-10-11' in s:
    already.append('seed: the R348 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R348 record')
s = rd(SD)
assert s.count('R348 landed 2026-10-11') == 1,     'a entry'
assert s.count('R347 landed 2026-10-11') == 1,     'a r347 kept'
assert s.count('R346 landed 2026-10-11') == 1,     'a r346 kept'
assert s.count('R345 landed 2026-10-11') == 1,     'a r345 kept'
assert s.count('R344 landed 2026-10-11') == 1,     'a r344 kept'
assert s.count('R343 landed 2026-10-11') == 1,     'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1,     'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1,     'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1,     'a r340 kept'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'
# ---- (b) NEW rules/uaclericspells7.h ----
US = 'rules/uaclericspells7.h'
if os.path.exists(US) and 'R349' in rd(US):
    already.append('uaclericspells7.h: the pins')
else:
    HDR = r"""// ===========================================================================
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

}   // namespace rules"""
    assert HDR.count('R349') == 1, 'b tag'
    assert HDR.count('{') - HDR.count('}') == 0, 'b braces'
    assert HDR.count('(') - HDR.count(')') == 0, 'b parens'
    clean(HDR, 78)
    assert HDR.count('namespace rules') == 2, 'b ns'
    assert HDR.count('inline') == 56,        'b inline census'
    wr(US, HDR + NL)
    applied.append('uaclericspells7.h: the pins')
assert os.path.exists(US), 'b exists'
assert rd(US).count('R349') == 1, 'b tag kept'
# ---- (c) the gap report: the note (the
# item CLOSES this round) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R349: the 7th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        holes - noted pending the PDF;',
        '        the 7th level stays open.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R349: the 7th level pinned',
    '        (rules/uaclericspells7.h) -',
    '        exaction (the duty or quest',
    '        with the alignment gates and',
    '        the bargain consequences) and',
    '        succor (the prepared-object',
    '        dweomer with the summons',
    '        reverse); the family decodes',
    '        the two 7s as 1; the exaction',
    '        range position-decodes from',
    '        the interleave; the R341',
    '        7th-level column prints no',
    '        fragments - both names pin',
    '        from the prose; the opener',
    '        word, the creature-example',
    '        garble and the two prose',
    '        shatters are OCR holes -',
    '        noted pending the PDF.',
    '      - CLOSED R349: the item closed -',
    '        all seven levels pinned',
    '        (R343-R348 plus this round).',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    OLD_BOX = NL.join([
        '- [ ] **The new cleric spells** (pp.',
        '      32-42) - one item per level:',
    ])
    assert s.count(OLD_BOX) == 1, 'c box'
    NEW_BOX = NL.join([
        '- [x] **The new cleric spells** (pp.',
        '      32-42) - one item per level:',
    ])
    s = s.replace(OLD_BOX, NEW_BOX)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R349: the 7th level pinned') == 1,     'c note'
assert s.count('CLOSED R349: the item closed') == 1,     'c close'
assert s.count('- [x] **The new cleric spells** (pp.') == 1, 'c item closed'
assert s.count('- [ ] **The new cleric spells** (pp.') == 0, 'c open gone'
assert s.count('R348: the 6th level pinned') == 1,     'c r348 kept'
assert s.count('R347: the 5th level pinned') == 1,     'c r347 kept'
assert s.count('R346: the 4th level pinned') == 1,     'c r346 kept'
assert s.count('R345: the 3rd level pinned') == 1,     'c r345 kept'
assert s.count('R344: the 2nd level pinned') == 1,     'c r344 kept'
assert s.count('R343: the 1st level pinned') == 1,     'c r343 kept'
assert s.count('CLOSED R342') == 1, 'c r342 kept'
assert s.count('R341: the readable tables') == 1,     'c r341 kept'
assert s.count('R340: the fragment-verified') == 1,     'c r340 kept'
assert len(applied) + len(already) == 3, 'c count'
# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R349 UA cleric 7th level spells pin audit' in s:
    already.append('regtest.cpp: the R349 audit')
else:
    INC_ANCH = (
        '#include "rules/uaclericspells6.h"'
        '  // R348: the UA new cleric 6th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaclericspells7.h"'
        '  // R349: the UA new cleric 7th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R349: the UA new cleric 7th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (p. 42), the
    // 7th level - exaction (the duty or
    // quest upon a powerful extraplanar
    // creature, the alignment gates, the
    // past-favor or pledge causality, the
    // bargain consequences) and succor
    // (the prepared-object dweomer, the
    // command-word transport, the summons
    // reverse, the 2,000-5,000 gp
    // preparation cost). The digit-garble
    // family decodes this round's two 7s
    // as 1 (the exaction casting matches
    // the abjure precedent; the succor
    // day decode stays verbatim with
    // doubt); the exaction range
    // position-decodes from the
    // interleave. The R341 continued
    // table prints zero 7th-level
    // fragments - both names pin from the
    // prose. The item CLOSES this round -
    // all seven levels pinned.
    {
        using namespace rules;
        int bad = 0;
        // U1: exaction
        {
            if (strcmp(uac7ExactionName(),
                "Exaction (Evocation - Alteration)")
                != 0) ++bad;
            if (!uac7ExactionComponentsVSM()) ++bad;
            if (uac7ExactionLevel() != 7) ++bad;
            // the Range cell interleaves - the
            // bare "1" after the Casting Time
            if (uac7ExactionRangeInches() != 1) ++bad;
            // the casting prints "7 round"
            if (uac7ExactionCastingTimeRounds() != 1)
                ++bad;
            if (!uac7ExactionSaveSpecial()) ++bad;
            if (!uac7ExactionDurationSpecial()) ++bad;
            if (!uac7ExactionAoeOneCreature()) ++bad;
            // the opener word decodes as cast
            if (!uac7ExactionWhenCastOpenerDecoded())
                ++bad;
            if (!uac7ExactionOpenerFragmentLost()) ++bad;
            // the confrontation
            if (!uac7ExactionConfrontsExtraplanar())
                ++bad;
            if (!uac7ExactionRequiresDutyOrQuest()) ++bad;
            // the garbled examples decode
            if (!uac7ExactionExamplesIncludeDevasDemons())
                ++bad;
            if (!uac7ExactionNotOnDeities()) ++bad;
            if (!uac7ExactionExampleFragmentLost()) ++bad;
            // the alignment gates
            if (!uac7ExactionNoEthicalMoralOpposition())
                ++bad;
            if (!uac7ExactionTrueNeutralOpposed()) ++bad;
            // the causality
            if (!uac7ExactionMustKnowOrFairTrade()) ++bad;
            if (!uac7ExactionPastFavorAsCause()) ++bad;
            if (!uac7ExactionPledgeIfNoReason()) ++bad;
            if (!uac7ExactionServiceMustBeReasonable())
                ++bad;
            if (!uac7ExactionActsAsQuest()) ++bad;
            // the completion transport
            if (!uac7ExactionTransportedOnCompletion())
                ++bad;
            if (!uac7ExactionCompletionFragmentLost())
                ++bad;
            // the bargain consequences
            if (!uac7ExactionRewardReturnRequired()) ++bad;
            if (!uac7ExactionCreatureFreedOnReward()) ++bad;
            if (!uac7ExactionFailureInvitesCounterExaction())
                ++bad;
            if (!uac7ExactionFailureGrantsSpellImmunity())
                ++bad;
            if (!uac7ExactionMaterialSymbolPlaneMatterScroll())
                ++bad;
        }
        // U2: succor
        {
            if (strcmp(uac7SuccorName(),
                "Succor (Alteration - Enchantment)"
                " Reversible") != 0) ++bad;
            if (!uac7SuccorReversible()) ++bad;
            if (!uac7SuccorComponentsVSM()) ++bad;
            if (uac7SuccorLevel() != 7) ++bad;
            // the casting prints "7 day"
            if (uac7SuccorCastingTimeDays() != 1) ++bad;
            if (!uac7SuccorRangeTouch()) ++bad;
            if (!uac7SuccorSaveNone()) ++bad;
            if (!uac7SuccorDurationSpecial()) ++bad;
            if (!uac7SuccorAoeOneIndividual()) ++bad;
            // the prepared-object dweomer
            if (!uac7SuccorDweomerInPreparedObject()) ++bad;
            if (uac7SuccorObjectExampleCount() != 3) ++bad;
            for (int i = 0; i < 3; ++i) {
                if (uac7SuccorObjectExampleName(i) == 0)
                    ++bad;
            }
            if (!uac7SuccorRadiatesMagic()) ++bad;
            if (!uac7SuccorTransportsPossessorToSanctuary())
                ++bad;
            // the command-word mechanics
            if (!uac7SuccorGivenWillinglyWithCommandWord())
                ++bad;
            if (!uac7SuccorBreakItemWithCommandWord()) ++bad;
            if (!uac7SuccorWordOfRecallEquivalent()) ++bad;
            if (!uac7SuccorNoOtherCreatures()) ++bad;
            // the summons reverse
            if (!uac7SuccorReverseSummons()) ++bad;
            if (!uac7SuccorReverseVicinityFragmentLost())
                ++bad;
            if (!uac7SuccorClericMayDeclineSummons()) ++bad;
            if (!uac7SuccorDeclineWastesSpell()) ++bad;
            // the preparation cost
            if (uac7SuccorPreparationCostMinGP() != 2000)
                ++bad;
            if (uac7SuccorPreparationCostMaxGP() != 5000)
                ++bad;
            if (!uac7SuccorEitherVersionCosts()) ++bad;
        }
        // U3: the seam
        {
            // the R341 continued table prints
            // zero 7th-level fragments
            if (uastClericFragCount(7) != 0) ++bad;
            if (uastClericFragName(7, 0)[0] != 0) ++bad;
            // neither name seam-checks - the
            // pins are from the prose alone
            if (!uac7ExactionSeamFragmentsOnly()) ++bad;
            if (!uac7SpellsPinFromProse()) ++bad;
        }
        printf("R349 UA cleric 7th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    assert AUDIT.count('{') - AUDIT.count('}') == 0, 'd audit braces'
    assert AUDIT.count('(') - AUDIT.count(')') == 0, 'd audit parens'
    assert AUDIT.count('// U') == 3, 'd U tags'
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R349 audit')
s = rd(RT)
assert s.count(
    'R349 UA cleric 7th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 276, 'd census 276'
assert s.count(
    'R348 UA cleric 6th level spells '
    'pin audit: bad ') == 1, 'd r348 kept'
assert s.count(
    'R347 UA cleric 5th level spells '
    'pin audit: bad ') == 1, 'd r347 kept'
assert s.count(
    'R346 UA cleric 4th level spells '
    'pin audit: bad ') == 1, 'd r346 kept'
assert s.count(
    'R345 UA cleric 3rd level spells '
    'pin audit: bad ') == 1, 'd r345 kept'
assert s.count(
    'R344 UA cleric 2nd level spells '
    'pin audit: bad ') == 1, 'd r344 kept'
assert s.count(
    'R343 UA cleric 1st level spells '
    'pin audit: bad ') == 1, 'd r343 kept'
assert s.count(
    'R342 UA MU and IL tables '
    'pin audit: bad ') == 1, 'd r342 kept'
assert s.count(
    'R341 UA spell tables '
    'pin audit: bad ') == 1, 'd r341 kept'
assert s.count(
    'R340 UA new weapons prose '
    'pin audit: bad ') == 1, 'd r340 kept'
assert s.count('R227: the wis mental save') == 1,     'd r227 kept'
assert s.count(
    '#include "rules/uaclericspells7.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'
# ---- the summary ----
print('R349 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R349 note: the UA new cleric spells')
print('pin round, the 7th level - the two')
print('spell descriptions (exaction with')
print('the alignment gates and the bargain')
print('consequences, succor with the')
print('prepared-object dweomer and the')
print('summons reverse); the family decodes')
print('the two 7s as 1; the exaction range')
print('position-decodes from the interleave;')
print('the R341 7th-level column prints no')
print('fragments - both names pin from the')
print('prose; the opener word, the')
print('creature-example garble and the two')
print('prose shatters are holes - noted')
print('pending the PDF; the item CLOSES -')
print('all seven levels pinned; the')
print('census 275 -> 276')
print('commit: R349: the UA new cleric 7th')
print('level spells pin round (census 276)')

