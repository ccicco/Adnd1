-- wnv: promoted from tools/spec_r482.json (the R482: the WSG NORMAL VISION slice, printed p. 72 - the first vision-and-visibility round, a pure prose round with NO table (Table 41 waits at p. 73): the chapter frame (as many as three visual senses - normal vision, infravision and ultravision, each with advantages in some situations), the visible-spectrum definition, the 500-yard effective range in clear daylight air, the size M/S/L sighting distances (500/250/at least 1000), the obstruction and elevation semantics, and the worked orc example.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 482,
  "prefix" = "wnv",
  "banner" = {
      "title" = "R482: the WSG NORMAL VISION slice, printed p. 72 - the first vision-and-visibility round, a pure prose round with NO table (Table 41 waits at p. 73): the chapter frame (as many as three visual senses - normal vision, infravision and ultravision, each with advantages in some situations), the visible-spectrum definition, the 500-yard effective range in clear daylight air, the size M/S/L sighting distances (500/250/at least 1000), the obstruction and elevation semantics, and the worked orc example.",
      "provenance" = "The settle: two-way clean on the first pass - the tesseract full-text read and the pdfy layout read agree on every number of the page (the three senses, the 500/250/1000 yards, the six-foot orc, the three-foot grass, the half body), and the tsv confirms the geometry cell by cell; the pdfy header line reads VIS1 (a running head artifact, not content). No contested cells, no vision reads needed.",
      "sentinel" = "Bounds held: the size S distance is exactly half the size M range, the size L floor is exactly double it, and the grass-hidden orc drops to the size S distance because half its body shows.",
    },
  "consts" = { {
      "name" = "wnvVisualSenseCount",
      "value" = 3,
      "comment" = "three types of visual senses: normal vision, infravision and ultravision",
    }, {
      "name" = "wnvRangeYards",
      "value" = 500,
      "comment" = "the effective range of normal vision in clear air during daylight",
    }, {
      "name" = "wnvSizeSYards",
      "value" = 250,
      "comment" = "a size S creature or object is visible from 250 yards",
    }, {
      "name" = "wnvSizeLYards",
      "value" = 1000,
      "comment" = "a size L creature is visible from a distance of at least 1000 yards",
    }, {
      "name" = "wnvExOrcHeightFeet",
      "value" = 6,
      "comment" = "the worked example: a six-foot-tall orc",
    }, {
      "name" = "wnvExGrassHeightFeet",
      "value" = 3,
      "comment" = "the field covered with a three-foot height of grass and foliage",
    }, {
      "name" = "wnvHalfNum",
      "value" = 1,
      "comment" = "half of the orc body shows above the grass",
    }, {
      "name" = "wnvHalfDen",
      "value" = 2,
      "comment" = "the half-body fraction of the grass-hidden example",
    } },
  "bools" = { {
      "name" = "wnvNormalVisionMostCommon",
      "value" = true,
      "comment" = "normal vision is what humans and most other creatures and character races use most of the time",
    }, {
      "name" = "wnvVisibleSpectrumBetween",
      "value" = true,
      "comment" = "normal vision sees images, colors and visual phenomena within the visible spectrum, between the infrared and ultraviolet ranges",
    }, {
      "name" = "wnvSightMeansFastOrSlow",
      "value" = true,
      "comment" = "seeing a great distance and knowing what you see decides moving fast or slow, surprising or being surprised, and sometimes life or death",
    }, {
      "name" = "wnvEachSenseHasTradeoffs",
      "value" = true,
      "comment" = "each visual sense has advantages in some situations and disadvantages at other times",
    }, {
      "name" = "wnvSizeMRecognizedAtRange",
      "value" = true,
      "comment" = "with an unobstructed view a character recognizes the basic form of a size M creature at the effective range",
    }, {
      "name" = "wnvSizeLMayExceed",
      "value" = true,
      "comment" = "exceptionally large creatures or objects - a dragon, a tall building - may be visible at much greater distances",
    }, {
      "name" = "wnvAnythingObstructs",
      "value" = true,
      "comment" = "practically anything in the line of sight can be an obstruction; ideal conditions are rare when viewer and target share ground and elevation",
    }, {
      "name" = "wnvGrassHalvesToSizeS",
      "value" = true,
      "comment" = "under the grass only half the orc body shows, so it is viewed from the size S distance - as if it were a size S creature",
    }, {
      "name" = "wnvElevationUnobstructs",
      "value" = true,
      "comment" = "drastically different elevations often give an unobstructed view - a lone mountain peak sees for miles in any direction",
    }, {
      "name" = "wnvRangeUnchangedOnPeak",
      "value" = true,
      "comment" = "the effective range is unchanged by elevation: the peak character must still be within the range of a size M object to distinguish and possibly identify it",
    }, {
      "name" = "wnvConverseViewerVisible",
      "value" = true,
      "comment" = "the converse holds: the character on the peak is himself visible and recognizable to any other viewers within the effective range",
    }, {
      "name" = "wnvBlessingAndCurse",
      "value" = true,
      "comment" = "long-range visibility can be a blessing and a curse at the same time, depending on one point of view",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the three senses, and the size S distance is half the effective range while the size L floor is double it",
      "expr" = "m['wnvVisualSenseCount']() != 3 or 2 * m['wnvSizeSYards']() != m['wnvRangeYards']() or m['wnvSizeLYards']() != 2 * m['wnvRangeYards']()",
    }, {
      "note" = "the worked example: a six-foot orc over three-foot grass shows half its body and drops to the size S distance",
      "expr" = "m['wnvExOrcHeightFeet']() != 6 or m['wnvExGrassHeightFeet']() != 3 or m['wnvHalfDen']() != 2 * m['wnvHalfNum']() or m['wnvRangeYards']() != 500",
    } },
  "audit" = {
      "label" = "R482 WSG normal vision pin audit",
      "comment" = "The normal vision rules: normal vision is what humans and most other creatures and character races use most of the time - the ability to see images, colors and other visual phenomena within the visible spectrum, between the infrared and ultraviolet ranges. In clear air during daylight the effective range is 500 yards: a character with an unobstructed view recognizes the basic form of a size M creature or object at that distance; a size S creature is visible from 250 yards; a size L creature from at least 1000 yards - or much greater for exceptionally large creatures or objects such as a dragon or a tall building. Practically anything in the line of sight can be an obstruction, and ideal viewing conditions are rare when viewer and target share the ground and elevation: a six-foot-tall orc on a flat featureless plain is visible at 500 yards, but under a three-foot height of grass and foliage only half its body shows, so it is only viewed from 250 yards - as if it were size S. Drastically different elevations often give an unobstructed view: a character on a lone mountain peak sees for miles, but his effective range is unchanged - he must still be within 500 yards of a size M object to distinguish its basic form. The converse holds too: the man on the peak is himself visible and recognizable to any viewer within 500 yards - long-range visibility is a blessing and a curse at once.",
    },
}
