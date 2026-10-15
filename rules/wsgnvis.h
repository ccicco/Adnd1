// =========================================================================================
// Adnd1 - rules/wsgnvis.h
// R482: the WSG NORMAL VISION slice, printed p. 72 - the first
// vision-and-visibility round, a pure prose round with NO table (Table 41
// waits at p. 73): the chapter frame (as many as three visual senses - normal
// vision, infravision and ultravision, each with advantages in some
// situations), the visible-spectrum definition, the 500-yard effective range
// in clear daylight air, the size M/S/L sighting distances (500/250/at least
// 1000), the obstruction and elevation semantics, and the worked orc example.
// census 406 -> 407.
//
// The settle: two-way clean on the first pass - the tesseract full-text read
// and the pdfy layout read agree on every number of the page (the three
// senses, the 500/250/1000 yards, the six-foot orc, the three-foot grass, the
// half body), and the tsv confirms the geometry cell by cell; the pdfy header
// line reads VIS1 (a running head artifact, not content). No contested cells,
// no vision reads needed.
//
// Bounds held: the size S distance is exactly half the size M range, the size
// L floor is exactly double it, and the grass-hidden orc drops to the size S
// distance because half its body shows.
//
namespace rules {

// ---- The chapter frame ----

// seeing a great distance and knowing what you see decides moving fast or
// slow, surprising or being surprised, and sometimes life or death
inline bool wnvSightMeansFastOrSlow()
    { return true; }

// three types of visual senses: normal vision, infravision and ultravision
inline int wnvVisualSenseCount()
    { return 3; }

// each visual sense has advantages in some situations and disadvantages at
// other times
inline bool wnvEachSenseHasTradeoffs()
    { return true; }

// ---- The definition and the range ----

// normal vision is what humans and most other creatures and character races
// use most of the time
inline bool wnvNormalVisionMostCommon()
    { return true; }

// normal vision sees images, colors and visual phenomena within the visible
// spectrum, between the infrared and ultraviolet ranges
inline bool wnvVisibleSpectrumBetween()
    { return true; }

// the effective range of normal vision in clear air during daylight
inline int wnvRangeYards()
    { return 500; }

// with an unobstructed view a character recognizes the basic form of a size M
// creature at the effective range
inline bool wnvSizeMRecognizedAtRange()
    { return true; }

// ---- The size-based sighting distances ----

// a size S creature or object is visible from 250 yards
inline int wnvSizeSYards()
    { return 250; }

// a size L creature is visible from a distance of at least 1000 yards
inline int wnvSizeLYards()
    { return 1000; }

// exceptionally large creatures or objects - a dragon, a tall building - may
// be visible at much greater distances
inline bool wnvSizeLMayExceed()
    { return true; }

// ---- The obstruction and elevation semantics ----

// practically anything in the line of sight can be an obstruction; ideal
// conditions are rare when viewer and target share ground and elevation
inline bool wnvAnythingObstructs()
    { return true; }

// the worked example: a six-foot-tall orc
inline int wnvExOrcHeightFeet()
    { return 6; }

// the field covered with a three-foot height of grass and foliage
inline int wnvExGrassHeightFeet()
    { return 3; }

// half of the orc body shows above the grass
inline int wnvHalfNum()
    { return 1; }

// the half-body fraction of the grass-hidden example
inline int wnvHalfDen()
    { return 2; }

// under the grass only half the orc body shows, so it is viewed from the size
// S distance - as if it were a size S creature
inline bool wnvGrassHalvesToSizeS()
    { return true; }

// drastically different elevations often give an unobstructed view - a lone
// mountain peak sees for miles in any direction
inline bool wnvElevationUnobstructs()
    { return true; }

// the effective range is unchanged by elevation: the peak character must
// still be within the range of a size M object to distinguish and possibly
// identify it
inline bool wnvRangeUnchangedOnPeak()
    { return true; }

// the converse holds: the character on the peak is himself visible and
// recognizable to any other viewers within the effective range
inline bool wnvConverseViewerVisible()
    { return true; }

// long-range visibility can be a blessing and a curse at the same time,
// depending on one point of view
inline bool wnvBlessingAndCurse()
    { return true; }

}   // namespace rules
