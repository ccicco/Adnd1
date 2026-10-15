// =========================================================================================
// Adnd1 - rules/wsgshelter.h
// R471: the WSG NATURAL SHELTERS slice with TABLE 35 - the arc opener
// (comfortable manmade structures not conveniently appearing whenever
// characters need shelter and warmth; through well-mapped territory the route
// plannable to arrive at marked natural shelters, through unfamiliar terrain
// the lucky find: a small cave on a rocky slope, a thick grove at the edge of
// a grassy plain, a pile of dead wood in a swamp), the two major factors (the
// terrain and the time of year), the Table 35 grid (the percentage chance of
// finding a natural shelter or easily obtainable construction materials:
// Desert constant 20 across the seasons, Forest 90/100/100/100, Hills
// 40/60/70/60, Mountains constant 40, Plains 30/40/40/30, Swamp 40/50/50/40),
// the check discipline (the DM checks whenever characters indicate they are
// looking; a failed check allows further checks at three-turn intervals while
// they keep moving, until shelter is found or they stop and camp
// unsheltered), the forest construction rules (an evergreen forest scrounges
// long straight wood and boughs easily; a forest of normal or light density
// cuts boughs or branches to lay across a grid of poles for a roof and,
// properly positioned, protection from wind and precipitation; pack animals
// may not enter closely packed vegetation without a path; it takes 3-8 turns
// - 1d6+2 - for a single character to obtain the materials, minus 2 turns per
// additional helper down to a minimum of 3, then another 6 turns to lash the
// poles and bind the shingles, minus 1 turn per helper to a maximum of two
// helpers, the construction time halved with a rope use proficiency character
// among the workers), the terrain notes (the desert has no usable vegetation
// but occasional surface irregularities - large rocks, small crevasses, a
// steeply sloping sand dune - sheltering at least one side; hills full of
// irregular windbreak terrain with sturdy vegetation abundant in spring,
// summer and autumn; mountains rough and rocky with little or no vegetation,
// any vegetation treated as hills or forest, the mountain entries modeling
// natural features - a cave, alcove or chimney between rock faces - large
// enough to contain the party where the wind cannot get inside; plains
// generally flat, a small gully two or three feet deep getting a character
// out of the wind but the worst shelter in heavy rain, windbreak materials
// scavengable where vegetation is more substantial than grasses and knee-high
// scrub, the material time 7-12 turns in non-lush terrain vs the 3-8 forest;
// the swamp usually scavengeable with debris piles, fallen trees or similar
// features serving as a shelter or its foundation) and the shelter-quality
// guidelines (many small pieces of vegetation: poor, at best adequate; few
// large sturdy pieces: adequate or perhaps good; the side of a large rock
// facing away from the wind: good wind protection but only adequate or poor
// against precipitation - the guidelines seam mid-sentence onto p. 62 at the
// cave sentence), printed p. 61.
// census 395 -> 396.
//
// Ground truth two-way: the user-run Termux tesseract text of printed p. 61
// (the --psm 4 run) vs a VISION READ of the uploaded page image
// (pg61-000.png). The pdf text layer garbles the Table 35 grid badly
// (dropping the Forest, Hills and Mountains rows entirely and reading 4c for
// the Plains autumn 40) and serves as the prose-only third reader. The
// tesseract and vision reads AGREE ON ALL 24 TABLE CELLS: Desert 20/20/20/20,
// Forest 90/100/100/100, Hills 40/60/70/60, Mountains 40/40/40/40, Plains
// 30/40/40/30, Swamp 40/50/50/40 - no contested cells, no physical-page
// reads. The prose numbers agree across tesseract and the pdf layer: the
// 1d6+2 dice, the minus-2 helper reduction with the 3-turn floor, the 6-turn
// lashing with the minus-1 helper reduction and the two-helper cap, the
// rope-use halving, the 7-12 plains ladder, the three-turn check interval and
// the two-or-three-foot gully depth. The section prose ends mid-sentence at
// the page foot (A cave in the face of a mountain...), the tail running onto
// p. 62 with the portable-shelters material.
//
// A TABLE round after three prose rounds: the 24-cell Table 35 grid pins as
// four season columns, the construction ladders and the terrain notes as
// consts and bools, every one audit-verified against the model.
//
namespace rules {

// ---- The find chance ----

// the terrain and the time of year are the major factors in determining the
// chance to locate a natural shelter or construct one from natural materials
inline bool wnsTerrainSeasonMajor()
    { return true; }

// the Dungeon Master should check whenever characters indicate that they are
// looking for shelter; failed checks with the party still moving allow
// rechecks until shelter is found or they stop and camp unsheltered
inline bool wnsCheckOnLooking()
    { return true; }

// after a failed shelter check with the party still moving, further checks at
// intervals of three turns
inline int wnsRecheckIntervalTurns()
    { return 3; }

// the Table 35 terrain row count: desert, forest, hills, mountains, plains,
// swamp
inline int wnsTerrainCount()
    { return 6; }

// the Table 35 winter find pct
inline int wnsWinter(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 90;
        case 2:
            return 40;
        case 3:
            return 40;
        case 4:
            return 30;
        case 5:
            return 40;
        default:
            return 0;
        }
    }

// the Table 35 spring find pct
inline int wnsSpring(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 60;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 50;
        default:
            return 0;
        }
    }

// the Table 35 summer find pct
inline int wnsSummer(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 70;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 50;
        default:
            return 0;
        }
    }

// the Table 35 autumn find pct
inline int wnsAutumn(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 60;
        case 3:
            return 40;
        case 4:
            return 30;
        case 5:
            return 40;
        default:
            return 0;
        }
    }

// ---- The forest construction rules ----

// in an evergreen forest it is fairly easy to scrounge long, straight pieces
// of wood and boughs to make a windbreak; forest areas are replete with
// natural shelter
inline bool wnsForestEasyMaterials()
    { return true; }

// in a forest of normal or even light density, boughs or branches cut and
// laid across a grid of poles give characters a roof and, properly
// positioned, protection from the full force of wind and precipitation
inline bool wnsBoughRoofShelter()
    { return true; }

// pack animals may not be willing or able to enter an area of closely packed
// vegetation unless there is a path into it or through it that they can
// negotiate
inline bool wnsPackAnimalsNeedPath()
    { return true; }

// a single character obtains simple-shelter materials in a forest in 3-8
// turns (1d6+2): the dice floor
inline int wnsForestMatsMinTurns()
    { return 3; }

// the forest material time: the dice ceiling (6+2)
inline int wnsForestMatsMaxTurns()
    { return 8; }

// minus 2 turns of material time for each additional character assisting in
// the work
inline int wnsHelperMatsReduction()
    { return 2; }

// the helper reduction bottoms out: a minimum of 3 turns of material time
inline int wnsMatsTimeFloor()
    { return 3; }

// another 6 turns for a character to lash together the poles and bind the
// shingles to the grid
inline int wnsLashBaseTurns()
    { return 6; }

// minus 1 turn of lashing for each additional character assisting
inline int wnsHelperLashReduction()
    { return 1; }

// the lashing helper reduction caps at a maximum of two helpers
inline int wnsMaxLashHelpers()
    { return 2; }

// the construction time is halved if a character with proficiency in rope use
// is among those doing the work
inline bool wnsRopeUseHalvesTime()
    { return true; }

// ---- The terrain notes ----

// desert terrain has no usable vegetation, but occasional surface
// irregularities - large rocks, small crevasses, a steeply sloping sand dune
// - provide shelter on at least one side
inline bool wnsDesertSurfaceIrregularities()
    { return true; }

// hills are full of irregular terrain that can serve as a simple windbreak;
// during spring, summer and autumn thick sturdy vegetation is fairly abundant
// for a greenery windbreak just as in a forest
inline bool wnsHillsWindbreak()
    { return true; }

// mountains are rough, rocky areas with little or no vegetation; any existing
// mountain vegetation is treated as hills or forest for the find chance, and
// the mountain table entries model natural features - a cave, alcove or
// chimney between two rock faces - large enough to contain the party and
// located where the wind cannot get inside
inline bool wnsMountainVegetationReading()
    { return true; }

// on a flat plain or in a mountainous area at high elevation it is
// practically impossible to find such materials: characters hope for a
// natural feature - a shallow gully, a small cave beneath a rock outcropping
inline bool wnsPlainMtnImpossible()
    { return true; }

// plains are generally flat but not necessarily featureless: a small gully,
// two or three feet deep, gets a character out of the wind - but a gully is
// the worst possible shelter in very heavy rain
inline bool wnsPlainsGully()
    { return true; }

// if a plain has vegetation more substantial than grasses and knee-high scrub
// brush, characters may scavenge enough branches and greenery for a windbreak
// (in non-lush terrain the material time is 7-12 turns vs the 3-8 forest)
inline bool wnsPlainsScavengeWindbreak()
    { return true; }

// in non-lush plains terrain a single character needs 7-12 turns for enough
// materials (vs the 3-8 forest): the floor
inline int wnsPlainsMatsMinTurns()
    { return 7; }

// the plains material time: the ceiling
inline int wnsPlainsMatsMaxTurns()
    { return 12; }

// swamp areas usually have scavengeable vegetation, and it is not too
// unlikely to come across a pile of debris, a fallen tree or a similar
// terrain feature that serves as a shelter or the foundation for one
inline bool wnsSwampDebrisShelter()
    { return true; }

// ---- The shelter-quality guidelines ----

// a natural shelter constructed from many small pieces of vegetation is
// usually a poor shelter, at best adequate
inline bool wnsQualityManySmallPoor()
    { return true; }

// a shelter made from relatively few pieces of large, sturdy vegetation is
// adequate or perhaps good
inline bool wnsQualityFewLargeGood()
    { return true; }

// the side of a large rock facing away from the wind offers good protection
// from the wind, but only adequate or poor protection from precipitation
inline bool wnsRockSideWindGood()
    { return true; }

}   // namespace rules
