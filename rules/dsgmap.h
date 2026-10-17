// =========================================================================================
// Adnd1 - rules/dsgmap.h
// THE DSG MAPPING YOUR SETTINGS, R557: printed pp. 114-117 - the mapping
// doctrine, the chapter closing in a single round with the child flipped in
// the same commit: the head (the orthographic map as the architectural
// blueprint showing exact relative sizes for distance and direction; the
// separate map per elevation level with the stairways and well shafts hard to
// picture; the perspective alternative - detailed 3-D maps for multi-level
// settings, the book's grids photocopied); Basic Mapping Considerations (the
// effective map communicating the necessary information, often in a few
// minutes of pencil and scratch paper; the tools - the straightedge, compass,
// protractor, templates, the felt-tip and razor-point pens thicker than the
// grid); Perspective Mapping (the advantages - the 3-D nature, the clearer
// level positions, the visible inter-level connections; the costs - the
// raised staircases and platforms obscuring the areas behind, the cramped
// rear squares, the drawing time; the two starting techniques - the photocopy
// method with the personal-use permission and the enlarged copies, the
// tracing-paper method with the tape fastened to clear tape, never the page);
// Selecting a Grid (the overall-shape match - the square grids for castles
// and dungeons, the narrow for caverns; the occluded areas designed to need
// little detail - the empty room or solid rock behind the tall stairway; the
// important detail toward the front, the lower platforms front and the higher
// rear, the stage-set imagining); Selecting a Starting Point (the design
// started near the front with the large squares for the intricate areas, the
// entrance possibly far to the rear; the control square centered under the
// highest tower, lining up the levels - the photocopies held to the light,
// the pencil marks); Drawing the Map (the orthographic likeness with the
// not-true squares; the outer limit first, or the huge staircase or central
// atrium spanning levels); Mapping Symbols (the orthographic symbols
// translating directly - doors, trapdoors, curtains, furniture; the 3-D
// objects changed to portray vertically too; the printed symbols from simple
// to elaborate); Splitting the Grid (the altitude mimicry by cut and shifted
// pieces; the tracing method - the paper pulled down to the scaled height;
// the photocopy method - the cut-outs placed at the proper elevation, the
// 20-foot platform twice the 10-foot-square distance above the cut line);
// Horizon Lines (the horizontal orientation; the perpendicular verticals with
// the T-square or the 90-degree triangle); Geomorphic Mapping (the time
// problem and the unpredictable PCs; the same-shape sections with the
// standardized edge points abutting any neighbor - the tremendous
// combinations; the underground, city, and fortress suitability; the
// small-part sections with their several unused areas; the shapes - the
// easiest squares, the three-orientation triangles needing more, the
// many-position harder hexagons; the planned connections; the standardized
// symmetric locations - the exact center or the 1/3-in pairs; the 60 x
// 60-foot section with its one or two connections per side against the
// square-mile realm's six to eight; the 75% entry rule against the enclosing
// dead ends); and Using Geomorphs (the random generation of huge areas with
// the deliberate exceptions; the numbered geomorphs and the d3/d4/d6
// placement rolls for which face is north; the placed section as normal
// setting - the matching edge connections proceeding unnoticed, the
// mismatches dead-ending; the variety and orientations hiding the revisited
// sections) - the round ending before the perspective grid plates, which are
// graphics and pin nothing.
// census 480 -> 481.
//
// djvu lines 14880-15430 with the Capture-layer pdf 114-118 cross-read (the
// pure-python extractor). The two reads agree across the round; no
// OCR-failure cells (the djvu quirks - '44' and '46' for d4 and d6, the
// Cyrillic page headers - settle by the cross-read). The chapter ends after
// the using-geomorphs tail; the perspective grid plates pp. 118-120 are
// graphics and pin nothing, and the compiled tables open at p. 121. A
// CLEAN-READ ROUND. The mapping your settings child flips [x] in the same
// commit (the single-round chapter precedent, as R530-R532): the gap census
// moves 141/14 -> 142/13.
//
// The DM section: R530 the environment, R531 the geography, R532 the
// cultures, R533-R548 the Deepearth key, R549 the Deepearth flip, R550-R555
// the campaign chapter, R556 the campaign flip, R557 the mapping chapter
// closed; next the compiled tables p. 121, then the DM-section parent and the
// front-matter chapter p. 6, then the arc tail.
//
namespace rules {

// ---- the head section ----

// the orthographic map - the typical top-view blueprint of corridors, rooms,
// and doorways showing exact relative sizes, useful for recording distance
// and direction
inline bool dcjOrthoDefines()
    { return true; }

// a separate orthographic map must be drawn for each elevation level;
// stairways and well shafts running through levels are hard to picture across
// the assortment
inline bool dcjOrthoLevelSplit()
    { return true; }

// the perspective alternative: 3-D maps for multi-level settings above or
// below ground, learning a few points and photocopying the book's grids
inline bool dcjPerspectiveIntro()
    { return true; }

// ---- the basic considerations section ----

// an effective map communicates the necessary information; often accomplished
// in a few minutes with pencil and scratch paper
inline bool dcjEffectiveMap()
    { return true; }

// the tools improve appearance and legibility: straightedge, compass,
// protractor, templates, and felt-tip or razor-point pens drawing slightly
// thicker than the grid
inline bool dcjMappingTools()
    { return true; }

// ---- the perspective mapping section ----

// the perspective advantages: the 3-D nature conveyed realistically, each
// level's position relative to the others clearer, the inter-level
// connections easier to see
inline bool dcjPerspective3D()
    { return true; }

// the perspective costs: raised features (staircases, platforms, ramps)
// obscure the areas behind them, the rear squares cramp detail, and the map
// takes more time to draw
inline bool dcjPerspectiveCosts()
    { return true; }

// the reward: maps communicating much more than room size or which wall holds
// the door
inline bool dcjPerspectiveReward()
    { return true; }

// technique one: photocopies of the grid - one per floor with extras for
// careful work, enlarged copies helpful; the photocopying permission granted
// for personal use
inline bool dcjStartPhotocopy()
    { return true; }

// technique two: the tracing-paper tablet - grid portions traced and details
// drawn in, held by hand or taped; the tape fastened to clear tape on the
// grid pages, never the book page itself
inline bool dcjStartTracing()
    { return true; }

// ---- the selecting a grid section ----

// select the grid matching the overall shape: the square grids for castles
// and dungeons, the longer narrower grids for caverns and walls
inline bool dcjGridShapeMatch()
    { return true; }

// design the occluded areas to need little detail: the large empty room or
// the solid rock directly behind the tall stairway
inline bool dcjGridObscureDesign()
    { return true; }

// the important detailed areas go toward the front of the grid; the lower
// platforms front and the higher rear - the stage-set imagining with the
// whole acting area visible
inline bool dcjGridFrontDetail()
    { return true; }

// ---- the starting point section ----

// start the design as close to the front as possible - the large front
// squares for the most intricate areas, though the entrance itself may lie
// far to the rear
inline bool dcjStartFront()
    { return true; }

// the control square: a single grid square roughly centered under the highest
// tower or the top level's midpoint, lining up the levels - photocopies held
// to the light, pencil marks on the traced copies
inline bool dcjControlSquare()
    { return true; }

// ---- the drawing section ----

// with the grid established, drawing a perspective map is much like an
// orthographic one - the biggest difference being the not-true squares of the
// grid
inline bool dcjDrawLikeOrtho()
    { return true; }

// draw the outer limit of the design first to visualize the structure and
// line up the levels - or start with the huge staircase or central atrium
// spanning several levels
inline bool dcjDrawOuterFirst()
    { return true; }

// ---- the symbols section ----

// orthographic symbols translate directly - doors, trapdoors, curtains,
// furniture - while the 3-D objects change slightly, portrayed vertically as
// well as horizontally
inline bool dcjSymbolsTranslated()
    { return true; }

// the 3-D symbols printed beside the grids - photocopy, trace, or cut and
// paste; styles from simple to elaborate, the familiarity developing quickly
inline bool dcjSymbolStyles()
    { return true; }

// ---- the splitting section ----

// the splitting example scale: each square on the grid equals 10 feet
inline int dcjGridSquareFeet()
    { return 10; }

// the splitting example: the platform raised 20 feet above the main floor
inline int dcjPlatformExampleFeet()
    { return 20; }

// mimic minor altitude changes by cutting the grid into pieces shifted up or
// down - especially for uneven underground environments
inline bool dcjSplitGrid()
    { return true; }

// the tracing method: the main floor grid drawn except the raised areas, the
// tracing paper pulled down until the area sits at the scaled height, the
// area drawn in its correct location; below-floor areas by moving the paper
// up
inline bool dcjSplitTracing()
    { return true; }

// the photocopy method: the raised areas cut from a copy, the rest glued to
// another sheet, the cut-outs placed at the proper elevation - the 20-foot
// platform twice the 10-foot-square distance above the cut line
inline bool dcjSplitPhotocopy()
    { return true; }

// ---- the horizon section ----

// each sample grid includes a horizon line; orient the grid so the horizon is
// horizontal to view it correctly
inline bool dcjHorizonOrient()
    { return true; }

// verticals drawn perpendicular to the horizon line - pillars, staircases,
// and ladders not toppling - with a T-square or a 90-degree triangle
inline bool dcjHorizonVertical()
    { return true; }

// ---- the geomorphic mapping section ----

// the geomorphic problem: the DM lacks time to map every region the PCs may
// visit, and their actions are unpredictable - mapping only the immediate
// future is unreliable
inline bool dcjGeomorphProblem()
    { return true; }

// geomorphic maps: same shape and size, with standardized entry and exit
// points around the edges; any edge abuts a neighbor, yielding a tremendous
// number of combinations
inline bool dcjGeomorphDefines()
    { return true; }

// the geomorphic advantage: not mapping every square foot of a massive region
// - combinations of geomorphs create the needed areas; well-suited to
// underground settings, large cities, and sprawling fortresses
inline bool dcjGeomorphSuitable()
    { return true; }

// a single geomorphic section portrays only a small part of the setting,
// assembled like puzzle pieces - and a block may contain several separate
// adventure areas, of which you need not use all
inline bool dcjGeomorphSections()
    { return true; }

// the shapes: squares, equilateral triangles, or hexagons - squares easiest,
// triangles limited to three orientations (needing more geomorphs), hexagons
// with the most positions but harder to draw; the square combines the best
// features
inline bool dcjGeomorphShapes()
    { return true; }

// plan the possible connections between sections - plenty of route options
// without every connection leading through
inline bool dcjGeomorphPlanConnections()
    { return true; }

// the small geomorph section: a 60 x 60-foot square per map section
inline int dcjGeomorphSectionFeet()
    { return 60; }

// the small-section connections: perhaps only one potential connection per
// side - the minimum
inline int dcjGeomorphSmallConnsMin()
    { return 1; }

// the small-section connections: no more than two potential connections per
// side - the maximum
inline int dcjGeomorphSmallConnsMax()
    { return 2; }

// the square-mile realm section connections: as many as six per side - the
// minimum
inline int dcjGeomorphLargeConnsMin()
    { return 6; }

// the square-mile realm section connections: as many as eight per side - the
// maximum
inline int dcjGeomorphLargeConnsMax()
    { return 8; }

// at least 75% of the possible connections on each geomorph should provide a
// means of entry into another map section
inline int dcjGeomorphEntryPct()
    { return 75; }

// the connections standardized and symmetric left-right: the exact center of
// each side or a pair each 1/3 of the distance in from the edge - measured
// carefully or the sections will not line up
inline bool dcjGeomorphStandardized()
    { return true; }

// ---- the using geomorphs section ----

// with a collection of geomorphs, randomly generate areas of huge proportions
// - though a fitting section may be placed deliberately; the overall map
// generated by a few die rolls and varied placement
inline bool dcjGeomorphRandom()
    { return true; }

// the placement rolls: number the geomorphs and roll for the starting
// section; the positions equal the sides - the d3, d4, or d6 rolled to
// determine which face is north
inline bool dcjGeomorphPositions()
    { return true; }

// a placed geomorph is treated as a normal part of the setting map; at a
// section edge, roll a new geomorph and its orientation - matching
// connections proceed unnoticed, mismatches wander into a dead end and
// another path
inline bool dcjGeomorphExplore()
    { return true; }

// variety and many orientations create a huge region of well-mapped terrain -
// the players never knowing they pass through sections previously explored
inline bool dcjGeomorphVariety()
    { return true; }

}   // namespace rules
