// =========================================================================================
// Adnd1 - rules/wsgboat.h
// The WSG THE BOATING PROFICIENCY, R457: this section deals primarily with
// the effects of not having a character with boating proficiency aboard. In a
// vessel containing no proficient characters, or one in which at least one
// non-proficient character is doing some of the work of rowing or sailing,
// the penalties apply: the movement rates of a kayak, a small canoe and a
// coracle are reduced to one-half of normal; a small rowboat, a large canoe,
// a large rowboat and a small barge to two-thirds of normal; and a large
// barge to three-quarters of normal - the reduction applied before any other
// alterations (wind speed and current speed) are taken into account. The
// chance of capsizing is increased by 25% in any situation where the chance
// is normally greater than 0%, to a maximum of 100%. With more than one
// proficient character aboard: the chance of capsizing is reduced by 20% for
// each proficient character after the first one; the chance of damage to the
// mast or sails is reduced by 20%, assuming the proficient characters have
// some means of making the rigging secure or bracing the mast so that it will
// better withstand the stress. If ALL of the characters helping to row or
// sail a vessel have proficiency in boating, the movement penalties do not
// apply and the movement rates are as given on the table at the beginning of
// this section. Two characters are required to sail a large rowboat, a small
// barge or a large barge; all other vessels can be sailed by one character.
// census 381 -> 382.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 45; the
// user own copy OCR (page 46) cross-checked against the archive djvu word
// layer (Guide_0045) - the prose reads clean two-way and NO eye-reads were
// needed for this round (a pure-prose section, no printed grid).
//
namespace rules {

// ---- the movement fractions ----

// The same eight vessels as Tables 25 and 26: kayak, small canoe, small
// rowboat, coracle, large canoe, large rowboat, small barge and large barge.
inline int wbpVesselCount()
    { return 8; }

// the movement-fraction numerator - the reduced rate is num/den of normal
inline int wbpMoveNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        default:
            return 0;
        }
    }

// the movement-fraction denominator - one-half, two-thirds or three-quarters
inline int wbpMoveDen(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 4;
        default:
            return 0;
        }
    }

// the minimum sail crew - one, or two for the large rowboat, small barge and
// large barge
inline int wbpSailCrew(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        default:
            return 0;
        }
    }

// The movement-rate reduction is applied before any other alterations - wind
// speed and current speed - are taken into account.
inline bool wbpReductionBeforeWindCurrent()
    { return true; }

// If all of the characters helping to row or sail the vessel have
// proficiency, the movement penalties do not apply and the rates are as given
// on the movement table.
inline bool wbpAllProficientWaivesMovePenalty()
    { return true; }

// ---- the capsize penalty ----

// With no proficient character aboard, the chance of capsizing is increased
// by 25% in any situation where the chance is normally greater than 0%.
inline int wbpCapsizeNonprofAdd()
    { return 25; }

// The increased capsize chance can never exceed 100%.
inline int wbpCapsizeCeiling()
    { return 100; }

// The penalties apply in a vessel containing no proficient characters.
inline bool wbpPenaltyIfNoneProficient()
    { return true; }

// The penalties also apply when at least one non-proficient character is
// doing some of the work of rowing or sailing.
inline bool wbpPenaltyIfAnyNonprofWorking()
    { return true; }

// The +25% capsize penalty applies only in situations where the chance is
// normally greater than 0%.
inline bool wbpCapsizeAddOnlyIfBasePositive()
    { return true; }

// The capsize chance after the penalty is capped at the 100% ceiling.
inline bool wbpCapsizeCappedAtCeiling()
    { return true; }

// ---- the proficient crew benefits ----

// The chance of capsizing is reduced by 20% for each proficient character
// after the first one.
inline int wbpCapsizeExtraProfCut()
    { return 20; }

// The chance of damage to the mast or sails is reduced by 20% when more than
// one proficient character is aboard, assuming they can secure the rigging or
// brace the mast.
inline int wbpMastDamageProfCut()
    { return 20; }

// Each proficient character after the first reduces the chance of capsizing.
inline bool wbpExtraProfsReduceCapsize()
    { return true; }

// The mast/sail damage reduction assumes the proficient characters can make
// the rigging secure or brace the mast against the stress.
inline bool wbpMastCutNeedsRiggingBrace()
    { return true; }

// ---- the sail crew minimums ----

// Two characters are required to sail a large rowboat, a small barge or a
// large barge; all other vessels can be sailed by one.
inline int wbpTwoHandedSailCrew()
    { return 2; }

// The two-handed sail-crew minimum holds for the large rowboat, the small
// barge and the large barge; every other vessel sails with one.
inline bool wbpSailCrewIsTwoHanded()
    { return true; }

}   // namespace rules
