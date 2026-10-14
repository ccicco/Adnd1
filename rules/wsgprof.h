// =========================================================================================
// Adnd1 - rules/wsgprof.h
// The WSG WILDERNESS
// PROFICIENCIES, R425:
// the wilderness arc
// opener. The printed
// p. 12 grids pin whole
// (Table 1: the 14 class
// rows; Table 2: the 25
// proficiency rows) with
// the Proficiency Check
// system, the improving
// rule and the slot rules;
// census 350 -> 351.
// Pin-era pattern (R322);
// the WSG arc mirrors the
// R322 UA opener.
//
// Provenance: the WSG
// scan (archive.org item
// pdfy-B3Fz83tZ3TV7zOc8),
// pdf page 13 = printed
// p. 12 - the Table 1/2
// grids read from the
// IIIF page image (the
// text layer drops the
// grid columns); the rule
// prose verified whole.
namespace rules {

// ---- the Proficiency
// ---- Check system ----

// A Proficiency Check is
// a roll of 1d20 against
// the Appropriate
// Ability.
inline bool wsgCheckRolls1d20()
    { return true; }
// The check uses a
// twenty-sided die.
inline int wsgCheckDieSides()
    { return 20; }
// An unmodified die roll
// of 19 or 20 always
// fails.
inline int wsgCheckAutoFail()
    { return 19; }
// An Appropriate Ability
// score greater than 18
// is treated as 18.
inline int wsgAbilityCap()
    { return 18; }
// Even a character with an
// Appropriate Ability of
// 18 or better keeps at
// least a 10 percent
// (2 in 20) chance of
// failing any check.
inline int wsgCheckFloorIn20()
    { return 2; }
// An improved proficiency
// succeeds on an
// unmodified 19.
inline bool wsgImproved19Succeeds()
    { return true; }
// No matter how much a
// proficiency is improved,
// an unmodified 20 still
// fails.
inline bool wsgNatural20Fails()
    { return true; }
// Improving an existing
// proficiency (a
// nonweapon slot gained at
// 3rd level or higher):
// each extra slot gives a
// cumulative -2 die-roll
// modifier.
inline int wsgImprovingStep()
    { return -2; }
// Improving uses slots
// gained at 3rd level or
// higher.
inline int wsgImprovingMinLevel()
    { return 3; }

// ---- the slot rules ----

// A weapon proficiency
// slot can be filled with
// a nonweapon proficiency.
inline bool wsgWeaponSlotHoldsNonweapon()
    { return true; }
// The reverse is not
// allowed: a nonweapon
// slot never holds a
// weapon proficiency.
inline bool wsgNonweaponSlotHoldsWeapon()
    { return false; }

// ---- the expanding
// ---- optional rule ----

// The Dungeon Master may
// allow one additional
// nonweapon proficiency
// slot at 1st level -
// only if all of the
// character nonweapon
// slots are filled right
// away.
inline int wsgExpandingBonusSlots()
    { return 1; }
// The extra slot comes at
// 1st level only.
inline bool wsgExpandingFirstLevelOnly()
    { return true; }
// A delayed extra slot is
// lost and cannot be
// filled later.
inline bool wsgExpandingDelayedIsLost()
    { return true; }

// ---- the Table 1
// ---- footnotes ----

// 0-level horsemen and
// lancers begin with one
// nonweapon proficiency.
inline int wsgHorsemanZeroLevelSlots()
    { return 1; }
// The horseman second
// nonweapon proficiency
// arrives at 1st level.
inline int wsgHorsemanSecondSlotLevel()
    { return 1; }
// The bard Table 1 row
// reads "as other classes"
// - the -1 sentinel below.
inline bool wsgBardAsOtherClasses()
    { return true; }

// ---- Table 1: the 14
// ---- class rows ----

// The census: 14 rows.
inline int wsgClassCount()
    { return 14; }
// The initial weapon
// slots by class (the
// left of the slash; the
// bard -1 sentinel = as
// other classes).
inline int wsgInitialWeaponSlots(
    int c)
    {
        switch (c) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return -1;
        default:
            return 0;
        }
    }

// The initial nonweapon
// slots by class (the
// right of the slash).
inline int wsgInitialNonweaponSlots(
    int c)
    {
        switch (c) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return -1;
        default:
            return 0;
        }
    }

// The weapon slots added
// per N levels (always
// 1).
inline int wsgAddWeaponSlots(
    int c)
    {
        switch (c) {
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The nonweapon slots
// added per N levels
// (the magic-user and
// illusionist add 2).
inline int wsgAddNonweaponSlots(
    int c)
    {
        switch (c) {
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The add-per-N-levels
// column by class; 1st
// level counts, so the
// first add comes ready
// to begin level N+1.
// (The census: 2x4, 3x2,
// 4x5, 5x1, 6x2.)
inline int wsgAddEveryLevels(
    int c)
    {
        switch (c) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 4;
        default:
            return 0;
        }
    }


// ---- Table 2: the 25
// ---- proficiency rows ----

// The census: 25 rows.
inline int wsgProfCount()
    { return 25; }

// The ability codes: 1
// WIS, 2 INT, 3 DEX,
// 4 CON, 5 STR, 0 NA.
// (The census: WIS 11,
// INT 3, DEX 2, CON 1,
// STR 1, NA 7.)
// The slots by
// proficiency (the
// census: 1x20, 2x5).
inline int wsgSlots(
    int p)
    {
        switch (p) {
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        default:
            return 0;
        }
    }

// The Appropriate
// Ability by
// proficiency; 0 = NA.
inline int wsgAbility(
    int p)
    {
        switch (p) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 5;
        case 23:
            return 0;
        case 24:
            return 1;
        default:
            return 0;
        }
    }

// The die-roll modifier
// by proficiency; 99 =
// NA - the proficiency
// never makes a check.
inline int wsgModifier(
    int p)
    {
        switch (p) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 99;
        case 4:
            return -1;
        case 5:
            return -2;
        case 6:
            return -1;
        case 7:
            return 99;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return -2;
        case 12:
            return -1;
        case 13:
            return 99;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return -3;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 99;
        case 20:
            return 99;
        case 21:
            return 99;
        case 22:
            return 0;
        case 23:
            return 99;
        case 24:
            return 1;
        default:
            return 0;
        }
    }

// True when the
// proficiency never makes
// a Proficiency Check
// (the NA-ability and the
// 99-modifier rows agree
// row for row).
inline bool wsgProfNeverChecks(int p)
    {
        switch (p) {
        case 3:
        case 7:
        case 13:
        case 19:
        case 20:
        case 21:
        case 23:
            return true;
        default:
            return false;
        }
    }

// ---- the ledger ----

// The Table 2 slot
// census: one-slot rows.
inline int wsgSingleSlotProfs()
    { return 20; }
// The Table 2 slot
// census: two-slot rows.
inline int wsgDoubleSlotProfs()
    { return 5; }
// The Table 2 ability
// census: wisdom rows.
inline int wsgWisdomProfs()
    { return 11; }
// The census of the rows
// that never make a
// check.
inline int wsgNeverCheckProfs()
    { return 7; }
// The harshest Table 2
// modifier: riding,
// land-based.
inline int wsgHardestModifier()
    { return -3; }

}   // namespace rules
