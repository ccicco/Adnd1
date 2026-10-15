// =========================================================================================
// Adnd1 - rules/wsginfra.h
// R483: the WSG INFRAVISION and TABLE 41 slice, printed p. 73 - the second
// vision-and-visibility round, a TABLE round: the heat-vision definition with
// the 60/30/120 infravisual ranges, and the six-condition four-light-level
// outdoor range of normal vision grid with its size M/L/S doubling and
// halving semantics, the long-range concentration assumption, the
// prone-target and three-foot-grass hiding rules, the daylight dual-scan gaze
// discipline and the moonlight/darkness footing discipline.
// census 407 -> 408.
//
// The settle: two-way clean on the first pass - the tesseract full-text read,
// the pdfy layout read and the tsv coordinate read agree on every number of
// the page (all 24 grid cells, the 60/30/120 infravision ranges, the
// double/halve factors), with the tsv confirming the two-line heavy-snow and
// heavy-fog rows cell by cell; the infravision paragraph is cut mid-word at
// the page bottom (In-), its continuation belonging to p. 74 with the
// ultravision round. No contested cells, no vision reads needed.
//
// Bounds held: moonlight never reads below darkness in any condition, blowing
// sand is the one condition whose daylight equals twilight, and the deep-race
// range is exactly double the standard range which is exactly double the
// halfling range.
//
namespace rules {

// ---- Table 41: the outdoor range grid ----

// six weather and obstruction conditions in Table 41
inline int wivConditionCount()
    { return 6; }

// four light levels: daylight, twilight, moonlight, darkness
inline int wivLightLevelCount()
    { return 4; }

// Table 41 outdoor range in yards: daylight
inline int wivDaylightYards(int b)
    {
        switch (b) {
        case 0:
            return 500;
        case 1:
            return 400;
        case 2:
            return 150;
        case 3:
            return 50;
        case 4:
            return 35;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// Table 41 outdoor range in yards: twilight
inline int wivTwilightYards(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 250;
        case 2:
            return 100;
        case 3:
            return 30;
        case 4:
            return 25;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// Table 41 outdoor range in yards: moonlight
inline int wivMoonlightYards(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 25;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 10;
        default:
            return 0;
        }
    }

// Table 41 outdoor range in yards: darkness
inline int wivDarknessYards(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 15;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 5;
        default:
            return 0;
        }
    }

// ---- The yard and size semantics ----

// the Table 41 entries are expressed in yards
inline bool wivYardsUnits()
    { return true; }

// the given range is the distance at which a viewer discerns a size M object
// that stands out from the terrain and its surroundings
inline bool wivSizeMStandsOut()
    { return true; }

// double the size M range for a size L object
inline int wivSizeLDoubleFactor()
    { return 2; }

// halve the size M range for a size S object
inline int wivSizeSHalfFactor()
    { return 2; }

// ---- The gaze discipline in good light ----

// seeing at the given range assumes the viewer is concentrating on long-range
// vision
inline bool wivAssumesLongRangeFocus()
    { return true; }

// the target, if one exists, is not concealed or trying to keep from being
// seen
inline bool wivTargetNotConcealed()
    { return true; }

// a target lying down on a flat featureless plain is greatly harder to spot
// from long distance
inline bool wivLyingDownReduces()
    { return true; }

// in three-foot-high grass a prone target is effectively invisible until the
// viewer is very close
inline bool wivGrassHidesUntilClose()
    { return true; }

// in daylight or twilight a character can employ long-range and short-range
// normal vision at the same time
inline bool wivDaylightDualScan()
    { return true; }

// the dual scan works by shifting his gaze every few seconds
inline bool wivGazeShiftEveryFewSeconds()
    { return true; }

// in sufficient illumination a character can move at full normal speed and
// stay aware of features at both ranges while keeping his gaze shifting
inline bool wivFullSpeedDualScan()
    { return true; }

// ---- The dark-terrain discipline ----

// in moonlight or darkness it is much harder to keep moving and stay
// cognizant of short-range and long-range objects at once
inline bool wivDarkScanDegrades()
    { return true; }

// a lone character on the move in moonlight or darkness is usually better off
// watching what he is walking on
inline bool wivDarkFootingFirst()
    { return true; }

// two or more travelers best divide lookout duty: one peers far ahead,
// another watches the ground a few paces ahead
inline bool wivLookoutDutySplit()
    { return true; }

// the safest way to scan the distance in poor illumination is to first come
// to a stop and then peer ahead
inline bool wivStopAndPeerSafest()
    { return true; }

// even stopped and peering, a nearby hazard moving toward him silent and
// unseen is not ruled out
inline bool wivMovingHazardUnseen()
    { return true; }

// ---- The infravision definition and ranges ----

// infravision, or heat vision, is the ability to see the shapes of objects by
// sensing radiation in the infrared spectrum
inline bool wivHeatVisionDefinition()
    { return true; }

// all nonhuman player characters have infravision
inline bool wivAllNonhumanHaveInfravision()
    { return true; }

// most nonhuman player characters see this far (outdoor scale)
inline int wivInfravisionRangeYards()
    { return 60; }

// most of them have it out to a range of 60 yards (outdoor scale)
inline bool wivMostOutTo60Yards()
    { return true; }

// halflings other than pure-blooded Stouts: 30 yards
inline int wivHalflingRangeYards()
    { return 30; }

// halflings other than pure-blooded Stouts have an infravisual range of 30
// yards
inline bool wivHalfling30UnlessStout()
    { return true; }

// drow, duergar and deep gnomes: 120 yards
inline int wivDeepRangeYards()
    { return 120; }

// drow, duergar and deep gnomes have infravision out to 120 yards
inline bool wivDeepRaces120()
    { return true; }

// the infravision ranges are outdoor scale, like the Table 41 ranges
inline bool wivOutdoorScaleNote()
    { return true; }

}   // namespace rules
