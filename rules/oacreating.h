// =========================================================================================
// Adnd1 - rules/oacreating.h
// CREATING THE PLAYER CHARACTER, printed capture pp. 5-8 - the OA arc opener
// census 536 -> 537.
//
// verified against capture pp. 1-8 of the oa.pdf OCR session (315 capture
// pages, single Mistral-OCR capture; the book prints no page numbers in the
// capture margin so all cites are capture pages; contested cells settle
// book-internal first, then against the physical copy). THE OA GAP REPORT
// LANDS WITH THIS ROUND IN THE SAME COMMIT - the R564 MotP opener pattern:
// tools/oa_gap_report.md ships pre-flip (235 boxes, 0 closed) beside the
// spec, and the engine flips the opener boxes in place.
//
// the gap census after this round: 4 closed, 231 open - the OA arc begins
// (R613b closed the DMO arc at 96/0 with the Chapter 2 parent flip; census
// 536 -> 537); NEXT - R615: the Chapter 1 ability tables (Tables 1-8) close
// on grid pins, prefix dgb, audit "R615 OA ability tables audit", include
// after rules/oacreating.h
//
namespace rules {

// ---- the OA opener pins ----

// the four PC generation methods offered for creating player characters
// (capture p. 6)
inline int dgaMethodCount()
    { return 4; }

// the wish ladder boundary: a wish or alter reality raises a score of 3-15 by
// one full point (capture p. 6)
inline int dgaWishLowCeiling()
    { return 15; }

// the printed wish example: nine more wishes are needed to reach 17 after the
// first one-tenth step (capture p. 6)
inline int dgaWishesFrom16To17()
    { return 9; }

// the military-press yardstick: 10 pounds lifted per point of Strength
// (capture p. 7)
inline int dgaPressLbsPerPoint()
    { return 10; }

// the overhead ceiling: no human or humanoid presses more than twice its own
// body weight (capture p. 7)
inline int dgaBodyWeightCap()
    { return 2; }

// the Strength 18/00 maximum military press in pounds (capture p. 7)
inline int dgaExceptionalLift()
    { return 470; }

// the bushi Strength prime-requisite floor for the experience bonus (capture
// p. 7)
inline int dgaBushiXpFloor()
    { return 15; }

// the preface doctrine: remove the monk from European-type campaigns - what
// is found herein is superior and in the proper surroundings (capture p. 3)
inline bool dgaMonkRetired()
    { return true; }

// the Kara-Tur framework: the book names Shou Lung, T'i Lung and Kozakura as
// the modeled lands (capture p. 5)
inline bool dgaKaraTurNamed()
    { return true; }

// the honor thesis: social skills and personal honor are as important as
// combat abilities (capture p. 5)
inline bool dgaHonorThesis()
    { return true; }

// Method I: roll 4d6 discard the lowest, total the rest, six times, assign
// the six results freely (capture p. 6)
inline bool dgaMethodI()
    { return true; }

// Method II: roll 3d6 twelve times, retain any six scores, assign as desired
// (capture p. 6)
inline bool dgaMethodII()
    { return true; }

// Method III: roll 3d6 six times, assign one result to Strength, then repeat
// per ability in order (capture p. 6)
inline bool dgaMethodIII()
    { return true; }

// Method IV: roll 3d6 in ability order to create twelve characters, then
// choose the preferred one (capture p. 6)
inline bool dgaMethodIV()
    { return true; }

// the run-of-the-mill NPC rule: roll 3d6 per ability, counting any 1 as 3 and
// any 6 as 4 (capture p. 6)
inline bool dgaNpcAveraging()
    { return true; }

// the special-character rule: profession abilities roll 3d6 with +1 added to
// each die that rolls 5 or less (capture p. 6)
inline bool dgaNpcProfessionBoost()
    { return true; }

// the wish rule above the boundary: scores of 16 or better rise only
// one-tenth of a point per wish (capture p. 6)
inline bool dgaWishHighTenth()
    { return true; }

// the wish exemption: magical books and devices can still raise scores of 16
// or better a full point (capture p. 6)
inline bool dgaWishBooksExempt()
    { return true; }

// the 18-Strength press: 180 pounds or own body weight, whichever is greater
// (capture p. 7)
inline bool dgaPressOrBodyWeight()
    { return true; }

// the exceptional-Strength lift ladder: 1 pound per percentage point 1-50, 4
// pounds per point 51-90, 8 pounds per point 91-100 (capture p. 7)
inline bool dgaExceptionalLiftLadder()
    { return true; }

// the bushi prime requisite: Strength 15 or more earns a 10 percent
// experience bonus (capture p. 7)
inline bool dgaBushiXpBonus()
    { return true; }

// the exceptional-Strength roll: samurai, kensai, barbarians and bushi with
// Strength 18 roll percentile dice (capture p. 7)
inline bool dgaExceptionalClasses()
    { return true; }

}   // namespace rules
