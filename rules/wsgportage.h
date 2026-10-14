// =========================================================================================
// Adnd1 - rules/wsgportage.h
// The WSG PORTAGING, R458: it is not unusual for areas of the wilderness to
// be dotted with small lakes or streams separated from one another by short
// expanses of land, and characters may find it desirable or necessary to
// portage their vessels (carry them overland) from one body of water to
// another rather than leave them behind. As with all encumbrance values, the
// ones given for watercraft account for the bulkiness of the vessel as well
// as its actual weight. If a character is able to support the listed amount
// without becoming severely encumbered, and if the vessel is smaller than a
// large rowboat, he can portage the vessel by himself. Severely encumbered
// characters cannot portage, or help to portage, a vessel. A large rowboat or
// a small barge requires at least two characters to share its encumbrance,
// and a large barge must be portaged by at least four characters. No vessel
// can be portaged by more than twice the minimum number needed to carry it -
// a third character is of no use in an attempt to portage a small canoe;
// despite his presence, the canoe must be able to be carried by the other two
// characters, or it cannot be portaged. Any character portaging or helping to
// portage a vessel can move no faster than 3 inches of movement (3 miles in
// eight hours, or 30 feet per round), regardless of terrain or his overall
// encumbrance status.
// census 382 -> 383.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 45-46
// (the section spans the page break); the user own copy OCR (pages 46-47)
// cross-checked against the archive djvu word layer (Guide_0045/0046) - the
// prose reads clean two-way, with only the usual page-break garble in the
// djvu (the solo- portage clause, which the user OCR reads whole and the
// continuation text confirms); NO eye-reads needed (a pure-prose section, no
// printed grid).
//
namespace rules {

// ---- the solo-portage gate ----

// The same eight vessels as Tables 25 and 26: kayak, small canoe, small
// rowboat, coracle, large canoe, large rowboat, small barge and large barge.
inline int wpgVesselCount()
    { return 8; }

// A vessel smaller than a large rowboat can be portaged by a single
// character.
inline bool wpgSoloBelowLargeRowboat()
    { return true; }

// The solo porter must be able to support the listed encumbrance amount
// without becoming severely encumbered.
inline bool wpgSoloNeedsNoSevereEncumbrance()
    { return true; }

// Severely encumbered characters cannot portage, or help to portage, a
// vessel.
inline bool wpgSevereBlocksPortageAndHelp()
    { return true; }

// ---- the portage crews ----

// the minimum portage crew - one below the large rowboat, two for the large
// rowboat and small barge, four for the large barge
inline int wpgMinCrew(int b)
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
            return 4;
        default:
            return 0;
        }
    }

// the maximum portage crew - twice the minimum: two, two, two, two, two,
// four, four and eight
inline int wpgMaxCrew(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 8;
        default:
            return 0;
        }
    }

// No vessel can be portaged by more than twice the minimum number needed to
// carry it.
inline int wpgMaxCrewMultiplier()
    { return 2; }

// A large barge must be portaged by at least four characters.
inline int wpgLargeBargeMinCrew()
    { return 4; }

// The multiple porters of a larger vessel share its encumbrance between them.
inline bool wpgCrewSharesEncumbrance()
    { return true; }

// No vessel can be portaged by more than twice its minimum crew - the crew
// grid hard-codes the cap per vessel.
inline bool wpgCrewCappedAtTwiceMin()
    { return true; }

// A character beyond the maximum crew is of no use - a third character cannot
// help two others portage a small canoe.
inline bool wpgBeyondMaxIsUseless()
    { return true; }

// ---- the portage move rate ----

// Any character portaging or helping to portage a vessel can move no faster
// than 3 inches of movement.
inline int wpgPortageMoveInches()
    { return 3; }

// The portage move rate is 3 miles in eight hours on the large scale.
inline int wpgPortageMilesPerHalfDay()
    { return 3; }

// The portage move rate is 30 feet per round on the small scale.
inline int wpgPortageFeetPerRound()
    { return 30; }

// The 3-inch portage move rate holds regardless of terrain.
inline bool wpgMoveCapIgnoresTerrain()
    { return true; }

// The 3-inch portage move rate holds regardless of the overall encumbrance
// status.
inline bool wpgMoveCapIgnoresEncumbrance()
    { return true; }

}   // namespace rules
