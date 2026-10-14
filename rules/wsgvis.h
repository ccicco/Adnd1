// =========================================================================================
// Adnd1 - rules/wsgvis.h
// The WSG OVERLAND MOVEMENT IN REDUCED VISIBILITY, R449: the visibility prose
// and TABLE 23 MOVEMENT IN REDUCED VISIBILITY - all movement rates previously
// described assume daylight under conditions that do not impair visibility.
// Table 23 gives the maximum safe speed, as a fraction of the character's or
// animal's current normal movement rate, for a character on foot or riding or
// driving an animal in less than ideal visibility: three light rows
// (daylight, moonlight, darkness) x five conditions (clear, moderate fog,
// heavy fog or snow, heavy snow with wind, blowing sand or dust), from 1/1
// down to 1/8. All other factors (encumbrance, terrain, climbing, etc.) are
// applied FIRST to determine the current normal rate, and then that number is
// multiplied by the table entry; the 1/1 at daylight/clear means no further
// reduction. On foot at the maximum safe speed in daylight, short-range
// vision extends far enough to avoid easily visible hazards - he will not
// walk into a tree or stumble over an exposed root; at night the safe speed
// does NOT keep him safe from hazards (a pit or cliff edge unless he tests
// the surface or probes ahead with a pole). Infravision detects
// heat-detectable hazards in moonlight or darkness (a warm-blooded creature
// in ambush - yes; a cliff edge - usually no). Exceeding the maximum safe
// speed demands a Dexterity Check per obstacle - failure means he or the
// animal blundered into it or stopped short, possibly throwing him from the
// saddle, off the wagon seat or over the chariot front; and in no event can
// the speed exceed twice the table figure or the full normal movement rate,
// whichever is less. Census 373 -> 374.
// census 373 -> 374.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 40-41;
// the user own copy OCR (pages 41-42) cross-checked against the archive djvu
// word layer (Guide_0040.djvu with the Guide_0041.djvu head) - the prose
// reads CLEAN two-way, every number (the 2x cap and the 1/8
// sandstorm-in-darkness example) matched exactly; the Table 23 grid is
// GARBLED in the djvu word layer, so every cell was confirmed by TWO
// independent IIIF eye-reads of leaf 40 - the OCR and both eye-reads agree on
// all 15 fractions.
//
// Multiply the current normal rate by the Table 23 fraction to get the
// maximum safe speed - 1/1 in clear daylight, down to 1/8 in blowing sand or
// dust at night - and never push past twice that figure without a Dexterity
// check at every obstacle.
//
namespace rules {

// ---- the reduced visibility prose rules ----

// All movement rates previously described assume that the character is
// traveling in daylight, under conditions that do not impair visibility.
inline bool wsvRatesAssumeDaylight()
    { return true; }

// All other factors affecting movement (encumbrance, terrain, climbing, etc.)
// are applied to determine the current normal movement rate, and then that
// number is multiplied by the appropriate entry from Table 23.
inline bool wsvOtherFactorsFirst()
    { return true; }

// The entry of 1/1 for Daylight/Clear means that movement is not further
// reduced under these conditions.
inline bool wsvDaylightClearNoCut()
    { return true; }

// On foot and moving at the maximum safe speed during daylight, his
// short-range vision extends far enough to avoid hazards easily visible under
// clear daylight - he will not walk into a tree or stumble over an exposed
// root.
inline bool wsvDaylightFootHazardSafe()
    { return true; }

// Moving at the maximum safe speed will not necessarily keep him safe from
// hazards at night, in moonlight or darkness - he can fall into a pit or
// stroll off a cliff unless he tests the surface or probes the ground ahead
// with a pole.
inline bool wsvNightHazardsRemain()
    { return true; }

// Infravision can detect certain hazards under moonlight or darkness provided
// they are heat-detectable - a warm-blooded creature lying in wait usually
// yes, a cliff edge usually no.
inline bool wsvInfravisionHeatOnly()
    { return true; }

// If a character attempts to move, or force an animal to move, faster than
// the maximum safe speed in any conditions of limited visibility, he must
// make a successful Dexterity Check whenever he or the animal encounters an
// obstacle.
inline bool wsvFasterNeedsDexCheck()
    { return true; }

// Failure on the check indicates that he or the animal has blundered into the
// obstacle, or that the animal has stopped short - quite possibly throwing
// the character from the saddle, dislodging him from his wagon seat, or
// throwing him forward into or over the front of a chariot.
inline bool wsvBlunderConsequences()
    { return true; }

// A character or an animal under his control cannot exceed the maximum safe
// speed by more than twice the figure given, or move faster than the full
// normal movement rate, whichever is less.
inline int wsvSpeedCapMult()
    { return 2; }

// ---- the Table 23 visibility grid ----

// Table 23 has three light rows: daylight, moonlight and darkness.
inline int wsvLightCount()
    { return 3; }

// Table 23 has five visibility conditions: clear, moderate fog, heavy fog or
// snow, heavy snow with wind, and blowing sand or dust.
inline int wsvCondCount()
    { return 5; }

// The numerator of the maximum safe speed fraction under Clear conditions, by
// light row.
inline int wsvNumClear(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return 1;
        }
    }

// The denominator under Clear conditions: 1/1 in daylight, 2/3 in moonlight,
// 1/2 in darkness.
inline int wsvDenClear(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        default:
            return 1;
        }
    }

// The numerator under Moderate Fog.
inline int wsvNumModFog(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 1;
        }
    }

// The denominator under Moderate Fog: 5/6, 1/2, 1/3.
inline int wsvDenModFog(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 3;
        default:
            return 1;
        }
    }

// The numerator under Heavy Fog or Snow.
inline int wsvNumHeavyFog(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 1;
        }
    }

// The denominator under Heavy Fog or Snow: 3/4, 1/3, 1/4.
inline int wsvDenHeavyFog(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 4;
        default:
            return 1;
        }
    }

// The numerator under Heavy Snow with Wind.
inline int wsvNumHeavySnow(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 1;
        }
    }

// The denominator under Heavy Snow with Wind: 2/3, 1/4, 1/6.
inline int wsvDenHeavySnow(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 6;
        default:
            return 1;
        }
    }

// The numerator under Blowing Sand or Dust.
inline int wsvNumBlowing(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 1;
        }
    }

// The denominator under Blowing Sand or Dust: 1/2, 1/6, 1/8 - the worst cell
// in the table.
inline int wsvDenBlowing(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 1;
        }
    }

}   // namespace rules
