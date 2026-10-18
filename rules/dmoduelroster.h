// =========================================================================================
// Adnd1 - rules/dmoduelroster.h
// THE SPELL DUELING ROSTER AND INDEX - the DMO Appendix (Spell Dueling
// Characteristics, printed pp. 180-188) and the closing Index (pp. 189-192):
// the complete per-spell dueling roster, 707 entries in 24 letter sections A
// through Z (no X or Y - no dueling spells begin with them), each pinned with
// its school (priest or wizard), level 1-9, usage code (the A/D/L/M/Any
// bitmask: A 1, D 2, L 4, M 8, Any 16, combinations summed), power rating PR
// 10-19, movement value MV 1-5 single or ranged, the Tome of Magic dagger
// mark and the Chapter 5 special-effect asterisk mark.
// census 535 -> 536.
//
// verified against printed pp. 180-192 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns; the ABBYY tsr02156 read is primary,
// the tesseract read cross-checked entry by entry - all 707 rows parsed from
// the primary band with zero unparsed lines and the usage histogram identical
// across the handoff audit). STANDING OCR CLASSES, all settled dual-capture:
// (1) the F class - 38 usage cells read F, a code absent from the legend,
// cross-checked to the leech code L on every member and pinned as the leech
// mask 4; (2) the four printed PR exceptions (Consequence PR 15, Disguise PR
// 19, Fire Shield PR 19, Fumble PR 19) confirmed in both captures and pinned
// as printed; (3) the Thought Capture usage cell prints a bare digit -
// confirmed against the physical copy 2026-10-18 and pinned as the no-code
// value 0; (4) the Barkskin entry prints PR 11 MV 1 without the comma; (5)
// the marker glyphs garble as digits, letters and quotes in both captures -
// the dagger (ToM) class reads 1, t, f, r, apostrophe, caret or plus and the
// asterisk (special) class reads s, 5, 8, quote or star; the two classes were
// adjudicated entry by entry against the printed legend, the Chapter 5
// special dueling characteristics lists (the five groups - mental or
// debilitating, creature-summoning, illusions, reversible, teleportation -
// plus the individual abilities) and the Tome of Magic roster itself,
// including the second-printing Mind Tracker (which replaced Mindkiller) and
// the wild-magic asterisks of the ToM pages. NAME REPAIRS, each dual-capture
// verified: Animal Summoning El reads Animal Summoning III; Past Fife reads
// Past Life; Otiluke's Tele ki netic Sphere reads Telekinetic; Screens reads
// Screen (the attached s is the asterisk); Far Reaching If reads Far Reaching
// II (the second I and the dagger merged in both captures); Mind Log reads
// Mind Fog. Names pinned as the DMO prints them where DMO and the source
// books differ: Thoughtweave (the ToM prints Thoughtwave), Impending
// Permission (the ToM prints Impeding Permission), Magical Stone (the PHB
// prints Magic Stone), The Great Circle seated in the G section as printed.
// THE INDEX FLIPS HERE: the closing index carries no numbers of its own - the
// DMO gap report closes at 96 boxes, 96 closed, 0 open, the full arc R599
// through R613.
//
// the gap census after this round: 96 closed, 0 open - the Appendix and the
// Index both flip in R613 and the DMO arc is fully closed; census 535 -> 536;
// NEXT - none: the DMO gap report is complete; consult the user for the next
// arc.
//
namespace rules {

// ---- the DMO roster doctrine pins ----

// the full dueling roster: 707 spell entries across 24 letter sections A
// through Z (no X or Y section - no dueling spells begin with those letters)
// (printed pp. 180-188).
inline int dfcRosterCount()
    { return 707; }

// the roster section count: 24 letter sections from A to Z (printed pp.
// 180-188).
inline int dfcSectionCount()
    { return 24; }

// the largest section: the S section carries 84 dueling spells (printed pp.
// 184-185).
inline int dfcMaxSectionCount()
    { return 84; }

// the smallest section: the Q section carries a single dueling spell, Quest
// (printed p. 183).
inline int dfcMinSectionCount()
    { return 1; }

// the power rating doctrine: PR equals the spell level plus nine, giving the
// 10-18 PR band for 1st- through 9th-level spells (printed p. 180; the R606
// detPRBase doctrine).
inline int dfcPrBase()
    { return 9; }

// the minimum power rating on the roster: PR 10 for every 1st-level dueling
// spell (printed pp. 180-188).
inline int dfcMinPr()
    { return 10; }

// the doctrine maximum power rating: PR 18 for every 9th-level dueling spell
// (printed pp. 180-188).
inline int dfcMaxPr()
    { return 18; }

// the highest power rating actually printed on the roster: PR 19 on Disguise,
// Fire Shield and Fumble - three of the four printed PR exceptions (printed
// pp. 181-182).
inline int dfcMaxPrPrinted()
    { return 19; }

// the printed PR exceptions: exactly four roster entries break the
// level-plus-nine doctrine - Consequence (PR 15 at 5th), Disguise (PR 19 at
// 5th), Fire Shield (PR 19 at 4th) and Fumble (PR 19 at 4th) - all four
// confirmed in both captures and pinned as printed (printed pp. 181-182).
inline int dfcPrExceptionCount()
    { return 4; }

// the lowest spell level on the roster: 1st (printed pp. 180-188).
inline int dfcMinLevel()
    { return 1; }

// the highest spell level on the roster: 9th (printed pp. 180-188).
inline int dfcMaxLevel()
    { return 9; }

// the minimum movement value: MV 1 (printed pp. 180-188).
inline int dfcMinMv()
    { return 1; }

// the maximum movement value: MV 5 (printed pp. 180-188).
inline int dfcMaxMv()
    { return 5; }

// the usage code bitmask: A (attack) is 1 (the printed legend: A = Attack;
// printed p. 180).
inline int dfcUsageMaskA()
    { return 1; }

// the usage code bitmask: D (defense) is 2 (the printed legend: D = Defense;
// printed p. 180).
inline int dfcUsageMaskD()
    { return 2; }

// the usage code bitmask: L (leech) is 4 (the printed legend: L = Leech;
// printed p. 180).
inline int dfcUsageMaskL()
    { return 4; }

// the usage code bitmask: M (missile) is 8 (the printed legend: M = Missile;
// printed p. 180).
inline int dfcUsageMaskM()
    { return 8; }

// the usage code bitmask: Any is 16 (the printed legend: Any = any function;
// printed p. 180).
inline int dfcUsageMaskAny()
    { return 16; }

// the school code: 0 for a priest spell (the roster prints (P n); printed pp.
// 180-188).
inline int dfcSchoolPriest()
    { return 0; }

// the school code: 1 for a wizard spell (the roster prints (W n); printed pp.
// 180-188).
inline int dfcSchoolWizard()
    { return 1; }

// the F-read OCR artifact class: 38 roster entries read usage F in both
// captures - F is not a legend code; the class is the leech code L misread by
// the primary capture (confirmed against the tesseract read entry by entry)
// and every F read pins as the leech mask 4 (printed pp. 180-188).
inline int dfcFReadCount()
    { return 38; }

// the pinned usage mask for every F-read entry: the leech mask 4 (printed pp.
// 180-188).
inline int dfcFReadPinnedMask()
    { return 4; }

// the Tome of Magic census: 209 roster entries carry the dagger mark (the
// legend t = spell from the Tome of Magic; printed p. 180) - the mark class
// verified spell by spell against the Tome of Magic roster, including the
// second-printing Mind Tracker that replaced Mindkiller.
inline int dfcTomeMarkedCount()
    { return 209; }

// the special-effect census: 148 roster entries carry the asterisk mark (the
// legend * = the spell has a special effect; see Chapter 5, pp. 108-116) plus
// the Chapter 3 spell clarification entries the typesetter also flagged
// (printed pp. 180-188).
inline int dfcSpecialMarkedCount()
    { return 148; }

// the printed Thought Capture quirk: the usage code cell prints a bare digit,
// not a legend code (confirmed against the physical copy, 2026-10-18) -
// pinned as usage 0, the no-code value (printed p. 187).
inline int dfcThoughtCaptureUsage()
    { return 0; }

// the Any-function entries: 8 roster entries read usage Any (printed pp.
// 180-188).
inline int dfcAnyCount()
    { return 8; }

// the roster legend: A = Attack (printed p. 180).
inline bool dfcLegendA()
    { return true; }

// the roster legend: D = Defense (printed p. 180).
inline bool dfcLegendD()
    { return true; }

// the roster legend: L = Leech (printed p. 180).
inline bool dfcLegendL()
    { return true; }

// the roster legend: M = Missile (printed p. 180).
inline bool dfcLegendM()
    { return true; }

// the roster legend: AD = Attack/Defense - a spell that serves as both an
// attack and a defense (printed p. 180).
inline bool dfcLegendAd()
    { return true; }

// the roster legend: Any = a spell that can serve any function - attack,
// defense, missile or leech (printed p. 180).
inline bool dfcLegendAny()
    { return true; }

// the roster legend: the dagger mark t means the spell comes from the Tome of
// Magic (printed p. 180).
inline bool dfcLegendTomeMark()
    { return true; }

// the roster legend: the asterisk mark means the spell has a special effect -
// see Chapter 5, the special dueling characteristics (printed p. 180).
inline bool dfcLegendSpecialMark()
    { return true; }

// the PR doctrine: a dueling spell power rating equals its spell level plus
// nine, as printed for all but four roster entries (printed p. 180).
inline bool dfcPrLevelPlus9()
    { return true; }

// the roster scope: the PR/MV/usage codes describe a spell only within the
// dueling arena system of Chapter 5 (printed pp. 96-117 and 180).
inline bool dfcCodesDuelOnly()
    { return true; }

// the F-read class: every usage cell that reads F is the leech code L misread
// - F is not a legend code, and the tesseract cross-check reads L for every
// member of the class (printed pp. 180-188).
inline bool dfcFReadsAreLeech()
    { return true; }

// the Thought Capture quirk: the usage code cell prints a bare digit where a
// legend letter belongs - verified against the physical copy on 2026-10-18
// and pinned as printed (printed p. 187).
inline bool dfcThoughtCapturePrintsDigit()
    { return true; }

// the four printed PR exceptions pin as printed: Consequence PR 15, Disguise
// PR 19, Fire Shield PR 19 and Fumble PR 19, each confirmed identically in
// both captures (printed pp. 181-182).
inline bool dfcPrExceptionsAsPrinted()
    { return true; }

// the Barkskin printed quirk: the entry prints PR 11 MV 1 without the comma
// every other entry carries - both captures agree, pinned as printed, data
// unaffected (printed p. 181).
inline bool dfcBarkskinMissingComma()
    { return true; }

// the Index box flips with this round: the closing index (pp. 189-192)
// completes the DMO gap report at 96 closed and 0 open - the full DMO arc is
// closed from R599 through R613.
inline bool dfcIndexClosesDmoArc()
    { return true; }

// ---- the DMO dueling roster A section pins ----

// the A section roster count: 49 dueling spells (printed pp. 180-188).
inline int dfcACount()
    { return 49; }

// the A section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcASchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 1;
        default:
            return -99;
        }
    }

// the A section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcALevel(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 2;
        case 14:
            return 8;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 4;
        case 27:
            return 5;
        case 28:
            return 6;
        case 29:
            return 3;
        case 30:
            return 5;
        case 31:
            return 6;
        case 32:
            return 7;
        case 33:
            return 6;
        case 34:
            return 6;
        case 35:
            return 5;
        case 36:
            return 8;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 7;
        case 40:
            return 9;
        case 41:
            return 3;
        case 42:
            return 5;
        case 43:
            return 1;
        case 44:
            return 3;
        case 45:
            return 6;
        case 46:
            return 2;
        case 47:
            return 2;
        case 48:
            return 5;
        default:
            return -99;
        }
    }

// the A section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcAUsage(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 16;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 2;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 2;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 3;
        case 27:
            return 3;
        case 28:
            return 3;
        case 29:
            return 4;
        case 30:
            return 4;
        case 31:
            return 3;
        case 32:
            return 3;
        case 33:
            return 2;
        case 34:
            return 3;
        case 35:
            return 2;
        case 36:
            return 4;
        case 37:
            return 2;
        case 38:
            return 4;
        case 39:
            return 4;
        case 40:
            return 4;
        case 41:
            return 4;
        case 42:
            return 4;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 4;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 4;
        default:
            return -99;
        }
    }

// the A section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcAPr(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 16;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 10;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 14;
        case 12:
            return 13;
        case 13:
            return 11;
        case 14:
            return 17;
        case 15:
            return 14;
        case 16:
            return 14;
        case 17:
            return 12;
        case 18:
            return 12;
        case 19:
            return 10;
        case 20:
            return 11;
        case 21:
            return 12;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 14;
        case 25:
            return 14;
        case 26:
            return 13;
        case 27:
            return 14;
        case 28:
            return 15;
        case 29:
            return 12;
        case 30:
            return 14;
        case 31:
            return 15;
        case 32:
            return 16;
        case 33:
            return 15;
        case 34:
            return 15;
        case 35:
            return 14;
        case 36:
            return 17;
        case 37:
            return 10;
        case 38:
            return 10;
        case 39:
            return 16;
        case 40:
            return 18;
        case 41:
            return 12;
        case 42:
            return 14;
        case 43:
            return 10;
        case 44:
            return 12;
        case 45:
            return 15;
        case 46:
            return 11;
        case 47:
            return 11;
        case 48:
            return 14;
        default:
            return -99;
        }
    }

// the A section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcAMvMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 2;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 5;
        case 27:
            return 5;
        case 28:
            return 5;
        case 29:
            return 2;
        case 30:
            return 2;
        case 31:
            return 3;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 3;
        case 37:
            return 3;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 2;
        case 42:
            return 1;
        case 43:
            return 4;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 2;
        default:
            return -99;
        }
    }

// the A section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcAMvMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 2;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 5;
        case 27:
            return 5;
        case 28:
            return 5;
        case 29:
            return 2;
        case 30:
            return 2;
        case 31:
            return 3;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 3;
        case 37:
            return 3;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 2;
        case 42:
            return 1;
        case 43:
            return 5;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 2;
        default:
            return -99;
        }
    }

// the A section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcATome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 1;
        case 36:
            return 0;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 0;
        case 47:
            return 1;
        case 48:
            return 0;
        default:
            return -99;
        }
    }

// the A section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcASpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster B section pins ----

// the B section roster count: 22 dueling spells (printed pp. 180-188).
inline int dfcBCount()
    { return 22; }

// the B section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcBSchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
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
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the B section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcBLevel(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 8;
        case 10:
            return 6;
        case 11:
            return 1;
        case 12:
            return 5;
        case 13:
            return 4;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 7;
        case 17:
            return 6;
        case 18:
            return 2;
        case 19:
            return 4;
        case 20:
            return 7;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the B section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcBUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the B section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcBPr(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 11;
        case 2:
            return 14;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 14;
        case 8:
            return 11;
        case 9:
            return 17;
        case 10:
            return 15;
        case 11:
            return 10;
        case 12:
            return 14;
        case 13:
            return 13;
        case 14:
            return 11;
        case 15:
            return 12;
        case 16:
            return 16;
        case 17:
            return 15;
        case 18:
            return 11;
        case 19:
            return 13;
        case 20:
            return 16;
        case 21:
            return 10;
        default:
            return -99;
        }
    }

// the B section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcBMvMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the B section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcBMvMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the B section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcBTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 0;
        default:
            return -99;
        }
    }

// the B section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcBSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster C section pins ----

// the C section roster count: 72 dueling spells (printed pp. 180-188).
inline int dfcCCount()
    { return 72; }

// the C section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcCSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 1;
        case 45:
            return 0;
        case 46:
            return 1;
        case 47:
            return 0;
        case 48:
            return 1;
        case 49:
            return 0;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 0;
        case 53:
            return 1;
        case 54:
            return 0;
        case 55:
            return 1;
        case 56:
            return 0;
        case 57:
            return 1;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 1;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        default:
            return -99;
        }
    }

// the C section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcCLevel(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 9;
        case 7:
            return 6;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 7;
        case 11:
            return 2;
        case 12:
            return 5;
        case 13:
            return 2;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 7;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 7;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 3;
        case 26:
            return 3;
        case 27:
            return 6;
        case 28:
            return 5;
        case 29:
            return 4;
        case 30:
            return 8;
        case 31:
            return 5;
        case 32:
            return 5;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 5;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 4;
        case 40:
            return 5;
        case 41:
            return 7;
        case 42:
            return 4;
        case 43:
            return 6;
        case 44:
            return 6;
        case 45:
            return 7;
        case 46:
            return 5;
        case 47:
            return 6;
        case 48:
            return 1;
        case 49:
            return 5;
        case 50:
            return 5;
        case 51:
            return 4;
        case 52:
            return 3;
        case 53:
            return 2;
        case 54:
            return 4;
        case 55:
            return 7;
        case 56:
            return 7;
        case 57:
            return 6;
        case 58:
            return 5;
        case 59:
            return 1;
        case 60:
            return 3;
        case 61:
            return 3;
        case 62:
            return 2;
        case 63:
            return 1;
        case 64:
            return 7;
        case 65:
            return 6;
        case 66:
            return 9;
        case 67:
            return 3;
        case 68:
            return 5;
        case 69:
            return 3;
        case 70:
            return 1;
        case 71:
            return 4;
        default:
            return -99;
        }
    }

// the C section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcCUsage(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 7;
        case 6:
            return 4;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 4;
        case 22:
            return 1;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 4;
        case 29:
            return 2;
        case 30:
            return 4;
        case 31:
            return 1;
        case 32:
            return 2;
        case 33:
            return 1;
        case 34:
            return 4;
        case 35:
            return 1;
        case 36:
            return 4;
        case 37:
            return 4;
        case 38:
            return 4;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 3;
        case 47:
            return 3;
        case 48:
            return 4;
        case 49:
            return 4;
        case 50:
            return 4;
        case 51:
            return 4;
        case 52:
            return 1;
        case 53:
            return 1;
        case 54:
            return 2;
        case 55:
            return 4;
        case 56:
            return 4;
        case 57:
            return 4;
        case 58:
            return 2;
        case 59:
            return 2;
        case 60:
            return 4;
        case 61:
            return 4;
        case 62:
            return 4;
        case 63:
            return 4;
        case 64:
            return 3;
        case 65:
            return 2;
        case 66:
            return 4;
        case 67:
            return 2;
        case 68:
            return 2;
        case 69:
            return 2;
        case 70:
            return 2;
        case 71:
            return 2;
        default:
            return -99;
        }
    }

// the C section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcCPr(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 10;
        case 6:
            return 18;
        case 7:
            return 15;
        case 8:
            return 14;
        case 9:
            return 10;
        case 10:
            return 16;
        case 11:
            return 11;
        case 12:
            return 14;
        case 13:
            return 11;
        case 14:
            return 13;
        case 15:
            return 14;
        case 16:
            return 13;
        case 17:
            return 16;
        case 18:
            return 13;
        case 19:
            return 10;
        case 20:
            return 11;
        case 21:
            return 16;
        case 22:
            return 10;
        case 23:
            return 12;
        case 24:
            return 13;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 15;
        case 28:
            return 14;
        case 29:
            return 13;
        case 30:
            return 17;
        case 31:
            return 14;
        case 32:
            return 14;
        case 33:
            return 10;
        case 34:
            return 10;
        case 35:
            return 10;
        case 36:
            return 14;
        case 37:
            return 14;
        case 38:
            return 10;
        case 39:
            return 13;
        case 40:
            return 14;
        case 41:
            return 16;
        case 42:
            return 13;
        case 43:
            return 15;
        case 44:
            return 15;
        case 45:
            return 16;
        case 46:
            return 14;
        case 47:
            return 15;
        case 48:
            return 10;
        case 49:
            return 15;
        case 50:
            return 14;
        case 51:
            return 13;
        case 52:
            return 12;
        case 53:
            return 11;
        case 54:
            return 13;
        case 55:
            return 16;
        case 56:
            return 16;
        case 57:
            return 15;
        case 58:
            return 14;
        case 59:
            return 10;
        case 60:
            return 12;
        case 61:
            return 12;
        case 62:
            return 11;
        case 63:
            return 10;
        case 64:
            return 16;
        case 65:
            return 15;
        case 66:
            return 18;
        case 67:
            return 12;
        case 68:
            return 14;
        case 69:
            return 12;
        case 70:
            return 10;
        case 71:
            return 13;
        default:
            return -99;
        }
    }

// the C section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcCMvMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 5;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 2;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 5;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 2;
        case 40:
            return 4;
        case 41:
            return 4;
        case 42:
            return 5;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 5;
        case 49:
            return 1;
        case 50:
            return 5;
        case 51:
            return 3;
        case 52:
            return 5;
        case 53:
            return 4;
        case 54:
            return 1;
        case 55:
            return 4;
        case 56:
            return 5;
        case 57:
            return 5;
        case 58:
            return 1;
        case 59:
            return 5;
        case 60:
            return 1;
        case 61:
            return 2;
        case 62:
            return 1;
        case 63:
            return 3;
        case 64:
            return 1;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        default:
            return -99;
        }
    }

// the C section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcCMvMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 5;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 5;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 2;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 5;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 2;
        case 40:
            return 4;
        case 41:
            return 4;
        case 42:
            return 5;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 5;
        case 49:
            return 1;
        case 50:
            return 5;
        case 51:
            return 3;
        case 52:
            return 5;
        case 53:
            return 4;
        case 54:
            return 1;
        case 55:
            return 4;
        case 56:
            return 5;
        case 57:
            return 5;
        case 58:
            return 1;
        case 59:
            return 5;
        case 60:
            return 1;
        case 61:
            return 2;
        case 62:
            return 1;
        case 63:
            return 3;
        case 64:
            return 1;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        default:
            return -99;
        }
    }

// the C section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcCTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 1;
        case 60:
            return 1;
        case 61:
            return 0;
        case 62:
            return 1;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 1;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        default:
            return -99;
        }
    }

// the C section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcCSpecial(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 1;
        case 51:
            return 0;
        case 52:
            return 1;
        case 53:
            return 1;
        case 54:
            return 1;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster D section pins ----

// the D section roster count: 47 dueling spells (printed pp. 180-188).
inline int dfcDCount()
    { return 47; }

// the D section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcDSchool(int b)
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
            return 1;
        case 6:
            return 0;
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
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 0;
        default:
            return -99;
        }
    }

// the D section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcDLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 7;
        case 8:
            return 3;
        case 9:
            return 8;
        case 10:
            return 6;
        case 11:
            return 5;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 6;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 6;
        case 29:
            return 5;
        case 30:
            return 6;
        case 31:
            return 5;
        case 32:
            return 5;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 2;
        case 36:
            return 5;
        case 37:
            return 4;
        case 38:
            return 4;
        case 39:
            return 7;
        case 40:
            return 5;
        case 41:
            return 6;
        case 42:
            return 2;
        case 43:
            return 7;
        case 44:
            return 5;
        case 45:
            return 7;
        case 46:
            return 2;
        default:
            return -99;
        }
    }

// the D section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcDUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 12;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 2;
        case 29:
            return 4;
        case 30:
            return 1;
        case 31:
            return 4;
        case 32:
            return 2;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 4;
        case 36:
            return 4;
        case 37:
            return 4;
        case 38:
            return 4;
        case 39:
            return 4;
        case 40:
            return 1;
        case 41:
            return 4;
        case 42:
            return 2;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 2;
        case 46:
            return 3;
        default:
            return -99;
        }
    }

// the D section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcDPr(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 11;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 16;
        case 8:
            return 12;
        case 9:
            return 17;
        case 10:
            return 15;
        case 11:
            return 14;
        case 12:
            return 11;
        case 13:
            return 10;
        case 14:
            return 11;
        case 15:
            return 11;
        case 16:
            return 13;
        case 17:
            return 10;
        case 18:
            return 10;
        case 19:
            return 10;
        case 20:
            return 13;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 13;
        case 24:
            return 13;
        case 25:
            return 15;
        case 26:
            return 13;
        case 27:
            return 13;
        case 28:
            return 15;
        case 29:
            return 19;
        case 30:
            return 15;
        case 31:
            return 14;
        case 32:
            return 14;
        case 33:
            return 12;
        case 34:
            return 12;
        case 35:
            return 11;
        case 36:
            return 14;
        case 37:
            return 13;
        case 38:
            return 13;
        case 39:
            return 16;
        case 40:
            return 14;
        case 41:
            return 15;
        case 42:
            return 11;
        case 43:
            return 16;
        case 44:
            return 14;
        case 45:
            return 16;
        case 46:
            return 11;
        default:
            return -99;
        }
    }

// the D section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcDMvMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 5;
        case 31:
            return 2;
        case 32:
            return 1;
        case 33:
            return 4;
        case 34:
            return 5;
        case 35:
            return 1;
        case 36:
            return 4;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 4;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 5;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 3;
        default:
            return -99;
        }
    }

// the D section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcDMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 5;
        case 31:
            return 2;
        case 32:
            return 1;
        case 33:
            return 4;
        case 34:
            return 5;
        case 35:
            return 1;
        case 36:
            return 5;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 5;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 5;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 3;
        default:
            return -99;
        }
    }

// the D section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcDTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        default:
            return -99;
        }
    }

// the D section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcDSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 1;
        case 46:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster E section pins ----

// the E section roster count: 31 dueling spells (printed pp. 180-188).
inline int dfcECount()
    { return 31; }

// the E section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcESchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        default:
            return -99;
        }
    }

// the E section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcELevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 7;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 9;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 6;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 9;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 6;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 9;
        case 21:
            return 4;
        case 22:
            return 7;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 5;
        case 26:
            return 6;
        case 27:
            return 3;
        case 28:
            return 5;
        case 29:
            return 5;
        case 30:
            return 6;
        default:
            return -99;
        }
    }

// the E section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcEUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 8;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 5;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 4;
        case 29:
            return 4;
        case 30:
            return 1;
        default:
            return -99;
        }
    }

// the E section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcEPr(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 16;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 18;
        case 5:
            return 14;
        case 6:
            return 13;
        case 7:
            return 12;
        case 8:
            return 11;
        case 9:
            return 10;
        case 10:
            return 15;
        case 11:
            return 13;
        case 12:
            return 10;
        case 13:
            return 18;
        case 14:
            return 13;
        case 15:
            return 10;
        case 16:
            return 15;
        case 17:
            return 10;
        case 18:
            return 11;
        case 19:
            return 10;
        case 20:
            return 18;
        case 21:
            return 13;
        case 22:
            return 16;
        case 23:
            return 12;
        case 24:
            return 13;
        case 25:
            return 14;
        case 26:
            return 15;
        case 27:
            return 12;
        case 28:
            return 14;
        case 29:
            return 14;
        case 30:
            return 15;
        default:
            return -99;
        }
    }

// the E section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcEMvMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 2;
        case 8:
            return 5;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 3;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 1;
        case 30:
            return 2;
        default:
            return -99;
        }
    }

// the E section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcEMvMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 3;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 1;
        case 30:
            return 2;
        default:
            return -99;
        }
    }

// the E section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcETome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 0;
        default:
            return -99;
        }
    }

// the E section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcESpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster F section pins ----

// the F section roster count: 46 dueling spells (printed pp. 180-188).
inline int dfcFCount()
    { return 46; }

// the F section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcFSchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
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
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 0;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return 0;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// the F section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcFLevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 6;
        case 21:
            return 4;
        case 22:
            return 7;
        case 23:
            return 2;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 3;
        case 27:
            return 2;
        case 28:
            return 5;
        case 29:
            return 3;
        case 30:
            return 2;
        case 31:
            return 3;
        case 32:
            return 4;
        case 33:
            return 2;
        case 34:
            return 2;
        case 35:
            return 3;
        case 36:
            return 6;
        case 37:
            return 7;
        case 38:
            return 9;
        case 39:
            return 6;
        case 40:
            return 2;
        case 41:
            return 4;
        case 42:
            return 4;
        case 43:
            return 1;
        case 44:
            return 2;
        case 45:
            return 4;
        default:
            return -99;
        }
    }

// the F section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcFUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 8;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 2;
        case 20:
            return 8;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 8;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return 4;
        case 32:
            return 4;
        case 33:
            return 3;
        case 34:
            return 4;
        case 35:
            return 4;
        case 36:
            return 4;
        case 37:
            return 3;
        case 38:
            return 2;
        case 39:
            return 1;
        case 40:
            return 5;
        case 41:
            return 4;
        case 42:
            return 2;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// the F section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcFPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 10;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 13;
        case 7:
            return 10;
        case 8:
            return 14;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 10;
        case 12:
            return 11;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 12;
        case 16:
            return 10;
        case 17:
            return 13;
        case 18:
            return 12;
        case 19:
            return 13;
        case 20:
            return 15;
        case 21:
            return 19;
        case 22:
            return 16;
        case 23:
            return 11;
        case 24:
            return 13;
        case 25:
            return 10;
        case 26:
            return 12;
        case 27:
            return 11;
        case 28:
            return 14;
        case 29:
            return 12;
        case 30:
            return 11;
        case 31:
            return 12;
        case 32:
            return 13;
        case 33:
            return 11;
        case 34:
            return 11;
        case 35:
            return 12;
        case 36:
            return 15;
        case 37:
            return 16;
        case 38:
            return 18;
        case 39:
            return 15;
        case 40:
            return 11;
        case 41:
            return 13;
        case 42:
            return 13;
        case 43:
            return 10;
        case 44:
            return 11;
        case 45:
            return 19;
        default:
            return -99;
        }
    }

// the F section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcFMvMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
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
            return 4;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 5;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 5;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 4;
        case 27:
            return 1;
        case 28:
            return 4;
        case 29:
            return 1;
        case 30:
            return 2;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 2;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 4;
        case 38:
            return 1;
        case 39:
            return 5;
        case 40:
            return 3;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 4;
        default:
            return -99;
        }
    }

// the F section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcFMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
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
            return 5;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 5;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 5;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 5;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 5;
        case 27:
            return 1;
        case 28:
            return 4;
        case 29:
            return 1;
        case 30:
            return 2;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 2;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 5;
        case 38:
            return 1;
        case 39:
            return 5;
        case 40:
            return 3;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 5;
        default:
            return -99;
        }
    }

// the F section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcFTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 1;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 1;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 1;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// the F section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcFSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster G section pins ----

// the G section roster count: 22 dueling spells (printed pp. 180-188).
inline int dfcGCount()
    { return 22; }

// the G section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcGSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the G section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcGLevel(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 9;
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 8;
        case 8:
            return 2;
        case 9:
            return 6;
        case 10:
            return 9;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 6;
        case 14:
            return 1;
        case 15:
            return 6;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 8;
        case 21:
            return 3;
        default:
            return -99;
        }
    }

// the G section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcGUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 2;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 1;
        case 21:
            return 4;
        default:
            return -99;
        }
    }

// the G section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcGPr(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 18;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 13;
        case 5:
            return 13;
        case 6:
            return 15;
        case 7:
            return 17;
        case 8:
            return 11;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 12;
        case 12:
            return 11;
        case 13:
            return 15;
        case 14:
            return 10;
        case 15:
            return 15;
        case 16:
            return 13;
        case 17:
            return 14;
        case 18:
            return 15;
        case 19:
            return 15;
        case 20:
            return 17;
        case 21:
            return 12;
        default:
            return -99;
        }
    }

// the G section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcGMvMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
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
            return 5;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 4;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the G section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcGMvMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 5;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the G section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcGTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        default:
            return -99;
        }
    }

// the G section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcGSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster H section pins ----

// the H section roster count: 24 dueling spells (printed pp. 180-188).
inline int dfcHCount()
    { return 24; }

// the H section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcHSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        default:
            return -99;
        }
    }

// the H section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcHLevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 5;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 7;
        case 16:
            return 8;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 8;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 2;
        case 23:
            return 1;
        default:
            return -99;
        }
    }

// the H section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcHUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 9;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 4;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 5;
        case 23:
            return 5;
        default:
            return -99;
        }
    }

// the H section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcHPr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 16;
        case 4:
            return 15;
        case 5:
            return 11;
        case 6:
            return 12;
        case 7:
            return 15;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 14;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 10;
        case 14:
            return 12;
        case 15:
            return 16;
        case 16:
            return 17;
        case 17:
            return 11;
        case 18:
            return 10;
        case 19:
            return 17;
        case 20:
            return 16;
        case 21:
            return 16;
        case 22:
            return 11;
        case 23:
            return 10;
        default:
            return -99;
        }
    }

// the H section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcHMvMin(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 5;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 5;
        case 22:
            return 1;
        case 23:
            return 2;
        default:
            return -99;
        }
    }

// the H section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcHMvMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 5;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 5;
        case 22:
            return 1;
        case 23:
            return 2;
        default:
            return -99;
        }
    }

// the H section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcHTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return -99;
        }
    }

// the H section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcHSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster I section pins ----

// the I section roster count: 26 dueling spells (printed pp. 180-188).
inline int dfcICount()
    { return 26; }

// the I section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcISchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
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
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        default:
            return -99;
        }
    }

// the I section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcILevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 7;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 9;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 8;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 5;
        case 16:
            return 7;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 6;
        case 24:
            return 2;
        case 25:
            return 3;
        default:
            return -99;
        }
    }

// the I section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcIUsage(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 4;
        case 11:
            return 16;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 4;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 4;
        default:
            return -99;
        }
    }

// the I section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcIPr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 11;
        case 2:
            return 10;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 16;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 18;
        case 10:
            return 13;
        case 11:
            return 11;
        case 12:
            return 17;
        case 13:
            return 12;
        case 14:
            return 11;
        case 15:
            return 14;
        case 16:
            return 16;
        case 17:
            return 13;
        case 18:
            return 11;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 12;
        case 22:
            return 12;
        case 23:
            return 15;
        case 24:
            return 11;
        case 25:
            return 12;
        default:
            return -99;
        }
    }

// the I section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcIMvMin(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 5;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 1;
        default:
            return -99;
        }
    }

// the I section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcIMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 5;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 5;
        case 25:
            return 1;
        default:
            return -99;
        }
    }

// the I section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcITome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        default:
            return -99;
        }
    }

// the I section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcISpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster J section pins ----

// the J section roster count: 2 dueling spells (printed pp. 180-188).
inline int dfcJCount()
    { return 2; }

// the J section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcJSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return -99;
        }
    }

// the J section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcJLevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        default:
            return -99;
        }
    }

// the J section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcJUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        default:
            return -99;
        }
    }

// the J section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcJPr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 10;
        default:
            return -99;
        }
    }

// the J section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcJMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        default:
            return -99;
        }
    }

// the J section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcJMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        default:
            return -99;
        }
    }

// the J section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcJTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// the J section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcJSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster K section pins ----

// the K section roster count: 8 dueling spells (printed pp. 180-188).
inline int dfcKCount()
    { return 8; }

// the K section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcKSchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// the K section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcKLevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the K section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcKUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        default:
            return -99;
        }
    }

// the K section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcKPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 11;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 10;
        case 7:
            return 10;
        default:
            return -99;
        }
    }

// the K section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcKMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the K section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcKMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the K section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcKTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the K section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcKSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster L section pins ----

// the L section roster count: 26 dueling spells (printed pp. 180-188).
inline int dfcLCount()
    { return 26; }

// the L section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcLSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
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
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 1;
        default:
            return -99;
        }
    }

// the L section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcLLevel(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 7;
        case 15:
            return 3;
        case 16:
            return 6;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 5;
        case 24:
            return 4;
        case 25:
            return 6;
        default:
            return -99;
        }
    }

// the L section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcLUsage(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 8;
        case 14:
            return 16;
        case 15:
            return 4;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        default:
            return -99;
        }
    }

// the L section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcLPr(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 12;
        case 8:
            return 11;
        case 9:
            return 11;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 11;
        case 13:
            return 12;
        case 14:
            return 16;
        case 15:
            return 12;
        case 16:
            return 15;
        case 17:
            return 10;
        case 18:
            return 13;
        case 19:
            return 12;
        case 20:
            return 11;
        case 21:
            return 10;
        case 22:
            return 12;
        case 23:
            return 14;
        case 24:
            return 13;
        case 25:
            return 15;
        default:
            return -99;
        }
    }

// the L section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcLMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 5;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 5;
        case 25:
            return 4;
        default:
            return -99;
        }
    }

// the L section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcLMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 5;
        case 25:
            return 4;
        default:
            return -99;
        }
    }

// the L section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcLTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        default:
            return -99;
        }
    }

// the L section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcLSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster M section pins ----

// the M section roster count: 69 dueling spells (printed pp. 180-188).
inline int dfcMCount()
    { return 69; }

// the M section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcMSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 0;
        case 7:
            return 0;
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
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 1;
        case 53:
            return 1;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 1;
        case 61:
            return 1;
        case 62:
            return 1;
        case 63:
            return 1;
        case 64:
            return 1;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 0;
        case 68:
            return 0;
        default:
            return -99;
        }
    }

// the M section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcMLevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 3;
        case 8:
            return 5;
        case 9:
            return 7;
        case 10:
            return 4;
        case 11:
            return 8;
        case 12:
            return 7;
        case 13:
            return 6;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 8;
        case 18:
            return 5;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 5;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 1;
        case 29:
            return 9;
        case 30:
            return 8;
        case 31:
            return 5;
        case 32:
            return 7;
        case 33:
            return 2;
        case 34:
            return 5;
        case 35:
            return 4;
        case 36:
            return 4;
        case 37:
            return 3;
        case 38:
            return 4;
        case 39:
            return 6;
        case 40:
            return 2;
        case 41:
            return 3;
        case 42:
            return 2;
        case 43:
            return 6;
        case 44:
            return 1;
        case 45:
            return 4;
        case 46:
            return 2;
        case 47:
            return 3;
        case 48:
            return 6;
        case 49:
            return 3;
        case 50:
            return 4;
        case 51:
            return 5;
        case 52:
            return 6;
        case 53:
            return 7;
        case 54:
            return 8;
        case 55:
            return 9;
        case 56:
            return 5;
        case 57:
            return 1;
        case 58:
            return 4;
        case 59:
            return 9;
        case 60:
            return 5;
        case 61:
            return 6;
        case 62:
            return 7;
        case 63:
            return 7;
        case 64:
            return 1;
        case 65:
            return 6;
        case 66:
            return 1;
        case 67:
            return 2;
        case 68:
            return 2;
        default:
            return -99;
        }
    }

// the M section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcMUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 8;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 1;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 2;
        case 20:
            return 8;
        case 21:
            return 8;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 4;
        case 29:
            return 8;
        case 30:
            return 2;
        case 31:
            return 5;
        case 32:
            return 4;
        case 33:
            return 4;
        case 34:
            return 1;
        case 35:
            return 4;
        case 36:
            return 3;
        case 37:
            return 5;
        case 38:
            return 3;
        case 39:
            return 4;
        case 40:
            return 2;
        case 41:
            return 1;
        case 42:
            return 4;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 4;
        case 46:
            return 3;
        case 47:
            return 4;
        case 48:
            return 4;
        case 49:
            return 3;
        case 50:
            return 3;
        case 51:
            return 3;
        case 52:
            return 3;
        case 53:
            return 3;
        case 54:
            return 3;
        case 55:
            return 3;
        case 56:
            return 4;
        case 57:
            return 4;
        case 58:
            return 4;
        case 59:
            return 3;
        case 60:
            return 2;
        case 61:
            return 4;
        case 62:
            return 4;
        case 63:
            return 1;
        case 64:
            return 4;
        case 65:
            return 4;
        case 66:
            return 4;
        case 67:
            return 1;
        case 68:
            return 4;
        default:
            return -99;
        }
    }

// the M section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcMPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 13;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 14;
        case 6:
            return 10;
        case 7:
            return 12;
        case 8:
            return 14;
        case 9:
            return 16;
        case 10:
            return 13;
        case 11:
            return 17;
        case 12:
            return 16;
        case 13:
            return 15;
        case 14:
            return 11;
        case 15:
            return 12;
        case 16:
            return 13;
        case 17:
            return 17;
        case 18:
            return 14;
        case 19:
            return 12;
        case 20:
            return 11;
        case 21:
            return 12;
        case 22:
            return 12;
        case 23:
            return 14;
        case 24:
            return 10;
        case 25:
            return 13;
        case 26:
            return 10;
        case 27:
            return 11;
        case 28:
            return 10;
        case 29:
            return 18;
        case 30:
            return 17;
        case 31:
            return 14;
        case 32:
            return 16;
        case 33:
            return 11;
        case 34:
            return 14;
        case 35:
            return 13;
        case 36:
            return 13;
        case 37:
            return 12;
        case 38:
            return 13;
        case 39:
            return 15;
        case 40:
            return 11;
        case 41:
            return 12;
        case 42:
            return 11;
        case 43:
            return 15;
        case 44:
            return 10;
        case 45:
            return 13;
        case 46:
            return 11;
        case 47:
            return 12;
        case 48:
            return 15;
        case 49:
            return 12;
        case 50:
            return 13;
        case 51:
            return 14;
        case 52:
            return 15;
        case 53:
            return 16;
        case 54:
            return 17;
        case 55:
            return 18;
        case 56:
            return 14;
        case 57:
            return 10;
        case 58:
            return 13;
        case 59:
            return 18;
        case 60:
            return 14;
        case 61:
            return 15;
        case 62:
            return 16;
        case 63:
            return 16;
        case 64:
            return 10;
        case 65:
            return 15;
        case 66:
            return 10;
        case 67:
            return 11;
        case 68:
            return 11;
        default:
            return -99;
        }
    }

// the M section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcMMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 2;
        case 31:
            return 4;
        case 32:
            return 5;
        case 33:
            return 2;
        case 34:
            return 3;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 2;
        case 38:
            return 1;
        case 39:
            return 5;
        case 40:
            return 1;
        case 41:
            return 4;
        case 42:
            return 3;
        case 43:
            return 2;
        case 44:
            return 1;
        case 45:
            return 2;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 3;
        case 49:
            return 3;
        case 50:
            return 3;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 4;
        case 54:
            return 4;
        case 55:
            return 4;
        case 56:
            return 5;
        case 57:
            return 5;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 2;
        case 61:
            return 1;
        case 62:
            return 2;
        case 63:
            return 3;
        case 64:
            return 2;
        case 65:
            return 5;
        case 66:
            return 1;
        case 67:
            return 3;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the M section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcMMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 2;
        case 31:
            return 4;
        case 32:
            return 5;
        case 33:
            return 5;
        case 34:
            return 4;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 2;
        case 38:
            return 1;
        case 39:
            return 5;
        case 40:
            return 1;
        case 41:
            return 5;
        case 42:
            return 3;
        case 43:
            return 2;
        case 44:
            return 1;
        case 45:
            return 2;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 3;
        case 49:
            return 3;
        case 50:
            return 3;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 4;
        case 54:
            return 4;
        case 55:
            return 4;
        case 56:
            return 5;
        case 57:
            return 5;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 2;
        case 61:
            return 1;
        case 62:
            return 2;
        case 63:
            return 3;
        case 64:
            return 2;
        case 65:
            return 5;
        case 66:
            return 1;
        case 67:
            return 3;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the M section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcMTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 0;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 1;
        case 58:
            return 1;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the M section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcMSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 1;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster N section pins ----

// the N section roster count: 7 dueling spells (printed pp. 180-188).
inline int dfcNCount()
    { return 7; }

// the N section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcNSchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the N section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcNLevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the N section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcNUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 4;
        default:
            return -99;
        }
    }

// the N section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcNPr(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 12;
        case 6:
            return 10;
        default:
            return -99;
        }
    }

// the N section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcNMvMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
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
        default:
            return -99;
        }
    }

// the N section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcNMvMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
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
        default:
            return -99;
        }
    }

// the N section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcNTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return -99;
        }
    }

// the N section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcNSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster O section pins ----

// the O section roster count: 5 dueling spells (printed pp. 180-188).
inline int dfcOCount()
    { return 5; }

// the O section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcOSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the O section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcOLevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 8;
        default:
            return -99;
        }
    }

// the O section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcOUsage(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 9;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the O section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcOPr(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 15;
        case 2:
            return 13;
        case 3:
            return 17;
        case 4:
            return 17;
        default:
            return -99;
        }
    }

// the O section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcOMvMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the O section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcOMvMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the O section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcOTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// the O section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcOSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster P section pins ----

// the P section roster count: 46 dueling spells (printed pp. 180-188).
inline int dfcPCount()
    { return 46; }

// the P section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcPSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
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
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// the P section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcPLevel(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 8;
        case 8:
            return 6;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 3;
        case 13:
            return 7;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 8;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 8;
        case 23:
            return 9;
        case 24:
            return 7;
        case 25:
            return 3;
        case 26:
            return 9;
        case 27:
            return 7;
        case 28:
            return 8;
        case 29:
            return 4;
        case 30:
            return 4;
        case 31:
            return 2;
        case 32:
            return 6;
        case 33:
            return 6;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 4;
        case 38:
            return 3;
        case 39:
            return 3;
        case 40:
            return 4;
        case 41:
            return 3;
        case 42:
            return 2;
        case 43:
            return 1;
        case 44:
            return 3;
        case 45:
            return 2;
        default:
            return -99;
        }
    }

// the P section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcPUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 16;
        case 9:
            return 4;
        case 10:
            return 16;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return 8;
        case 32:
            return 16;
        case 33:
            return 4;
        case 34:
            return 2;
        case 35:
            return 2;
        case 36:
            return 2;
        case 37:
            return 2;
        case 38:
            return 2;
        case 39:
            return 2;
        case 40:
            return 2;
        case 41:
            return 2;
        case 42:
            return 2;
        case 43:
            return 4;
        case 44:
            return 1;
        case 45:
            return 1;
        default:
            return -99;
        }
    }

// the P section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcPPr(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 14;
        case 3:
            return 10;
        case 4:
            return 14;
        case 5:
            return 11;
        case 6:
            return 10;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 13;
        case 12:
            return 12;
        case 13:
            return 16;
        case 14:
            return 15;
        case 15:
            return 14;
        case 16:
            return 13;
        case 17:
            return 12;
        case 18:
            return 13;
        case 19:
            return 17;
        case 20:
            return 13;
        case 21:
            return 13;
        case 22:
            return 17;
        case 23:
            return 18;
        case 24:
            return 16;
        case 25:
            return 12;
        case 26:
            return 18;
        case 27:
            return 16;
        case 28:
            return 17;
        case 29:
            return 13;
        case 30:
            return 13;
        case 31:
            return 11;
        case 32:
            return 15;
        case 33:
            return 15;
        case 34:
            return 11;
        case 35:
            return 10;
        case 36:
            return 10;
        case 37:
            return 13;
        case 38:
            return 12;
        case 39:
            return 12;
        case 40:
            return 13;
        case 41:
            return 12;
        case 42:
            return 11;
        case 43:
            return 10;
        case 44:
            return 12;
        case 45:
            return 11;
        default:
            return -99;
        }
    }

// the P section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcPMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 5;
        case 33:
            return 5;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 5;
        case 45:
            return 5;
        default:
            return -99;
        }
    }

// the P section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcPMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 1;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 5;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 5;
        case 33:
            return 5;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 5;
        case 45:
            return 5;
        default:
            return -99;
        }
    }

// the P section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcPTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        default:
            return -99;
        }
    }

// the P section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcPSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster Q section pins ----

// the Q section roster count: 1 dueling spells (printed pp. 180-188).
inline int dfcQCount()
    { return 1; }

// the Q section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcQSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        default:
            return -99;
        }
    }

// the Q section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcQLevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        default:
            return -99;
        }
    }

// the Q section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcQUsage(int b)
    {
        switch (b) {
        case 0:
            return 1;
        default:
            return -99;
        }
    }

// the Q section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcQPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        default:
            return -99;
        }
    }

// the Q section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcQMvMin(int b)
    {
        switch (b) {
        case 0:
            return 4;
        default:
            return -99;
        }
    }

// the Q section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcQMvMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        default:
            return -99;
        }
    }

// the Q section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcQTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        default:
            return -99;
        }
    }

// the Q section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcQSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster R section pins ----

// the R section roster count: 29 dueling spells (printed pp. 180-188).
inline int dfcRCount()
    { return 29; }

// the R section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcRSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        default:
            return -99;
        }
    }

// the R section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcRLevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 6;
        case 20:
            return 2;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 6;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 1;
        case 28:
            return 2;
        default:
            return -99;
        }
    }

// the R section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcRUsage(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 5;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 4;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 1;
        case 27:
            return 4;
        case 28:
            return 4;
        default:
            return -99;
        }
    }

// the R section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcRPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 13;
        case 2:
            return 14;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 13;
        case 7:
            return 11;
        case 8:
            return 10;
        case 9:
            return 13;
        case 10:
            return 16;
        case 11:
            return 16;
        case 12:
            return 15;
        case 13:
            return 12;
        case 14:
            return 13;
        case 15:
            return 10;
        case 16:
            return 12;
        case 17:
            return 14;
        case 18:
            return 13;
        case 19:
            return 15;
        case 20:
            return 11;
        case 21:
            return 16;
        case 22:
            return 16;
        case 23:
            return 16;
        case 24:
            return 15;
        case 25:
            return 11;
        case 26:
            return 12;
        case 27:
            return 10;
        case 28:
            return 11;
        default:
            return -99;
        }
    }

// the R section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcRMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 1;
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
            return 3;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 3;
        case 25:
            return 2;
        case 26:
            return 4;
        case 27:
            return 1;
        case 28:
            return 1;
        default:
            return -99;
        }
    }

// the R section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcRMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 1;
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
            return 3;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 5;
        case 24:
            return 3;
        case 25:
            return 5;
        case 26:
            return 4;
        case 27:
            return 1;
        case 28:
            return 1;
        default:
            return -99;
        }
    }

// the R section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcRTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return -99;
        }
    }

// the R section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcRSpecial(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster S section pins ----

// the S section roster count: 84 dueling spells (printed pp. 180-188).
inline int dfcSCount()
    { return 84; }

// the S section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcSSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
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
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 1;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 0;
        case 61:
            return 1;
        case 62:
            return 0;
        case 63:
            return 1;
        case 64:
            return 1;
        case 65:
            return 0;
        case 66:
            return 1;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 1;
        case 75:
            return 1;
        case 76:
            return 1;
        case 77:
            return 0;
        case 78:
            return 1;
        case 79:
            return 1;
        case 80:
            return 1;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 1;
        default:
            return -99;
        }
    }

// the S section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcSLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 8;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 8;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 5;
        case 16:
            return 7;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 7;
        case 20:
            return 9;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 5;
        case 27:
            return 2;
        case 28:
            return 7;
        case 29:
            return 8;
        case 30:
            return 6;
        case 31:
            return 1;
        case 32:
            return 3;
        case 33:
            return 2;
        case 34:
            return 3;
        case 35:
            return 2;
        case 36:
            return 3;
        case 37:
            return 6;
        case 38:
            return 4;
        case 39:
            return 4;
        case 40:
            return 7;
        case 41:
            return 2;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 6;
        case 45:
            return 4;
        case 46:
            return 3;
        case 47:
            return 2;
        case 48:
            return 4;
        case 49:
            return 7;
        case 50:
            return 7;
        case 51:
            return 1;
        case 52:
            return 3;
        case 53:
            return 5;
        case 54:
            return 3;
        case 55:
            return 7;
        case 56:
            return 2;
        case 57:
            return 6;
        case 58:
            return 1;
        case 59:
            return 3;
        case 60:
            return 3;
        case 61:
            return 9;
        case 62:
            return 3;
        case 63:
            return 7;
        case 64:
            return 7;
        case 65:
            return 4;
        case 66:
            return 2;
        case 67:
            return 3;
        case 68:
            return 6;
        case 69:
            return 6;
        case 70:
            return 4;
        case 71:
            return 2;
        case 72:
            return 3;
        case 73:
            return 7;
        case 74:
            return 9;
        case 75:
            return 7;
        case 76:
            return 3;
        case 77:
            return 3;
        case 78:
            return 4;
        case 79:
            return 5;
        case 80:
            return 2;
        case 81:
            return 7;
        case 82:
            return 7;
        case 83:
            return 8;
        default:
            return -99;
        }
    }

// the S section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcSUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 8;
        case 17:
            return 9;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 2;
        case 21:
            return 5;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 4;
        case 29:
            return 1;
        case 30:
            return 4;
        case 31:
            return 5;
        case 32:
            return 1;
        case 33:
            return 4;
        case 34:
            return 4;
        case 35:
            return 4;
        case 36:
            return 1;
        case 37:
            return 8;
        case 38:
            return 4;
        case 39:
            return 4;
        case 40:
            return 4;
        case 41:
            return 4;
        case 42:
            return 4;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 4;
        case 46:
            return 16;
        case 47:
            return 4;
        case 48:
            return 2;
        case 49:
            return 2;
        case 50:
            return 2;
        case 51:
            return 4;
        case 52:
            return 2;
        case 53:
            return 2;
        case 54:
            return 2;
        case 55:
            return 4;
        case 56:
            return 8;
        case 57:
            return 4;
        case 58:
            return 5;
        case 59:
            return 4;
        case 60:
            return 4;
        case 61:
            return 2;
        case 62:
            return 4;
        case 63:
            return 4;
        case 64:
            return 4;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 4;
        case 68:
            return 4;
        case 69:
            return 5;
        case 70:
            return 2;
        case 71:
            return 4;
        case 72:
            return 4;
        case 73:
            return 4;
        case 74:
            return 4;
        case 75:
            return 1;
        case 76:
            return 1;
        case 77:
            return 1;
        case 78:
            return 3;
        case 79:
            return 1;
        case 80:
            return 1;
        case 81:
            return 4;
        case 82:
            return 3;
        case 83:
            return 3;
        default:
            return -99;
        }
    }

// the S section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcSPr(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 14;
        case 2:
            return 11;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 17;
        case 6:
            return 12;
        case 7:
            return 15;
        case 8:
            return 14;
        case 9:
            return 14;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 17;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 14;
        case 16:
            return 16;
        case 17:
            return 14;
        case 18:
            return 13;
        case 19:
            return 16;
        case 20:
            return 18;
        case 21:
            return 11;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 10;
        case 25:
            return 13;
        case 26:
            return 14;
        case 27:
            return 11;
        case 28:
            return 16;
        case 29:
            return 17;
        case 30:
            return 15;
        case 31:
            return 10;
        case 32:
            return 12;
        case 33:
            return 11;
        case 34:
            return 12;
        case 35:
            return 11;
        case 36:
            return 12;
        case 37:
            return 15;
        case 38:
            return 13;
        case 39:
            return 13;
        case 40:
            return 16;
        case 41:
            return 11;
        case 42:
            return 10;
        case 43:
            return 12;
        case 44:
            return 15;
        case 45:
            return 13;
        case 46:
            return 12;
        case 47:
            return 11;
        case 48:
            return 13;
        case 49:
            return 16;
        case 50:
            return 16;
        case 51:
            return 10;
        case 52:
            return 12;
        case 53:
            return 14;
        case 54:
            return 12;
        case 55:
            return 16;
        case 56:
            return 11;
        case 57:
            return 15;
        case 58:
            return 10;
        case 59:
            return 12;
        case 60:
            return 12;
        case 61:
            return 18;
        case 62:
            return 12;
        case 63:
            return 16;
        case 64:
            return 16;
        case 65:
            return 13;
        case 66:
            return 11;
        case 67:
            return 12;
        case 68:
            return 15;
        case 69:
            return 15;
        case 70:
            return 13;
        case 71:
            return 11;
        case 72:
            return 12;
        case 73:
            return 16;
        case 74:
            return 18;
        case 75:
            return 16;
        case 76:
            return 12;
        case 77:
            return 12;
        case 78:
            return 13;
        case 79:
            return 14;
        case 80:
            return 11;
        case 81:
            return 16;
        case 82:
            return 16;
        case 83:
            return 17;
        default:
            return -99;
        }
    }

// the S section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcSMvMin(int b)
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
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 2;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 1;
        case 31:
            return 3;
        case 32:
            return 5;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 1;
        case 37:
            return 3;
        case 38:
            return 3;
        case 39:
            return 4;
        case 40:
            return 3;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 2;
        case 44:
            return 3;
        case 45:
            return 1;
        case 46:
            return 4;
        case 47:
            return 3;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 4;
        case 53:
            return 3;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 2;
        case 57:
            return 1;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 3;
        case 61:
            return 1;
        case 62:
            return 3;
        case 63:
            return 1;
        case 64:
            return 1;
        case 65:
            return 3;
        case 66:
            return 3;
        case 67:
            return 1;
        case 68:
            return 1;
        case 69:
            return 5;
        case 70:
            return 1;
        case 71:
            return 1;
        case 72:
            return 2;
        case 73:
            return 5;
        case 74:
            return 5;
        case 75:
            return 3;
        case 76:
            return 3;
        case 77:
            return 3;
        case 78:
            return 5;
        case 79:
            return 2;
        case 80:
            return 4;
        case 81:
            return 5;
        case 82:
            return 1;
        case 83:
            return 1;
        default:
            return -99;
        }
    }

// the S section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcSMvMax(int b)
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
            return 5;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 2;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 5;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 1;
        case 31:
            return 3;
        case 32:
            return 5;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 1;
        case 37:
            return 3;
        case 38:
            return 3;
        case 39:
            return 5;
        case 40:
            return 3;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 2;
        case 44:
            return 3;
        case 45:
            return 1;
        case 46:
            return 5;
        case 47:
            return 5;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 4;
        case 53:
            return 3;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 2;
        case 57:
            return 1;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 3;
        case 61:
            return 1;
        case 62:
            return 5;
        case 63:
            return 1;
        case 64:
            return 1;
        case 65:
            return 3;
        case 66:
            return 3;
        case 67:
            return 1;
        case 68:
            return 1;
        case 69:
            return 5;
        case 70:
            return 1;
        case 71:
            return 1;
        case 72:
            return 2;
        case 73:
            return 5;
        case 74:
            return 5;
        case 75:
            return 3;
        case 76:
            return 3;
        case 77:
            return 3;
        case 78:
            return 5;
        case 79:
            return 2;
        case 80:
            return 4;
        case 81:
            return 5;
        case 82:
            return 1;
        case 83:
            return 1;
        default:
            return -99;
        }
    }

// the S section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcSTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 0;
        case 42:
            return 1;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 0;
        case 57:
            return 1;
        case 58:
            return 0;
        case 59:
            return 1;
        case 60:
            return 1;
        case 61:
            return 1;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 1;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 1;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 1;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 1;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        default:
            return -99;
        }
    }

// the S section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcSSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 1;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 1;
        case 47:
            return 0;
        case 48:
            return 1;
        case 49:
            return 0;
        case 50:
            return 1;
        case 51:
            return 0;
        case 52:
            return 1;
        case 53:
            return 1;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 1;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 1;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 1;
        case 74:
            return 1;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster T section pins ----

// the T section roster count: 37 dueling spells (printed pp. 180-188).
inline int dfcTCount()
    { return 37; }

// the T section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcTSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 1;
        default:
            return -99;
        }
    }

// the T section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcTLevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 9;
        case 9:
            return 1;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 4;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 5;
        case 17:
            return 4;
        case 18:
            return 7;
        case 19:
            return 5;
        case 20:
            return 9;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 7;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 6;
        case 27:
            return 6;
        case 28:
            return 6;
        case 29:
            return 8;
        case 30:
            return 3;
        case 31:
            return 4;
        case 32:
            return 2;
        case 33:
            return 5;
        case 34:
            return 6;
        case 35:
            return 6;
        case 36:
            return 4;
        default:
            return -99;
        }
    }

// the T section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcTUsage(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 12;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 0;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 1;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 4;
        case 29:
            return 1;
        case 30:
            return 2;
        case 31:
            return 4;
        case 32:
            return 1;
        case 33:
            return 2;
        case 34:
            return 2;
        case 35:
            return 4;
        case 36:
            return 4;
        default:
            return -99;
        }
    }

// the T section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcTPr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 11;
        case 2:
            return 10;
        case 3:
            return 14;
        case 4:
            return 12;
        case 5:
            return 14;
        case 6:
            return 16;
        case 7:
            return 12;
        case 8:
            return 18;
        case 9:
            return 10;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 13;
        case 13:
            return 12;
        case 14:
            return 13;
        case 15:
            return 10;
        case 16:
            return 14;
        case 17:
            return 13;
        case 18:
            return 16;
        case 19:
            return 14;
        case 20:
            return 18;
        case 21:
            return 12;
        case 22:
            return 13;
        case 23:
            return 16;
        case 24:
            return 14;
        case 25:
            return 14;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 15;
        case 29:
            return 17;
        case 30:
            return 12;
        case 31:
            return 13;
        case 32:
            return 11;
        case 33:
            return 14;
        case 34:
            return 15;
        case 35:
            return 15;
        case 36:
            return 13;
        default:
            return -99;
        }
    }

// the T section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcTMvMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 4;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 5;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        default:
            return -99;
        }
    }

// the T section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcTMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 5;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 4;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 5;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        default:
            return -99;
        }
    }

// the T section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcTTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        default:
            return -99;
        }
    }

// the T section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcTSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster U section pins ----

// the U section roster count: 7 dueling spells (printed pp. 180-188).
inline int dfcUCount()
    { return 7; }

// the U section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcUSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        default:
            return -99;
        }
    }

// the U section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcULevel(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 4;
        default:
            return -99;
        }
    }

// the U section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcUUsage(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 4;
        case 6:
            return 4;
        default:
            return -99;
        }
    }

// the U section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcUPr(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 16;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 10;
        case 6:
            return 13;
        default:
            return -99;
        }
    }

// the U section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcUMvMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the U section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcUMvMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the U section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcUTome(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the U section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcUSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster V section pins ----

// the V section roster count: 8 dueling spells (printed pp. 180-188).
inline int dfcVCount()
    { return 8; }

// the V section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcVSchool(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the V section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcVLevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 1;
        case 5:
            return 7;
        case 6:
            return 5;
        case 7:
            return 5;
        default:
            return -99;
        }
    }

// the V section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcVUsage(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the V section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcVPr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 12;
        case 2:
            return 16;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 16;
        case 6:
            return 14;
        case 7:
            return 14;
        default:
            return -99;
        }
    }

// the V section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcVMvMin(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// the V section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcVMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 5;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// the V section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcVTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// the V section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcVSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster W section pins ----

// the W section roster count: 37 dueling spells (printed pp. 180-188).
inline int dfcWCount()
    { return 37; }

// the W section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcWSchool(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 0;
        case 35:
            return 1;
        case 36:
            return 0;
        default:
            return -99;
        }
    }

// the W section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcWLevel(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 4;
        case 16:
            return 6;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 9;
        case 20:
            return 2;
        case 21:
            return 9;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 9;
        case 25:
            return 8;
        case 26:
            return 7;
        case 27:
            return 3;
        case 28:
            return 9;
        case 29:
            return 2;
        case 30:
            return 4;
        case 31:
            return 2;
        case 32:
            return 1;
        case 33:
            return 3;
        case 34:
            return 6;
        case 35:
            return 3;
        case 36:
            return 2;
        default:
            return -99;
        }
    }

// the W section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcWUsage(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 3;
        case 28:
            return 16;
        case 29:
            return 2;
        case 30:
            return 4;
        case 31:
            return 4;
        case 32:
            return 4;
        case 33:
            return 4;
        case 34:
            return 4;
        case 35:
            return 4;
        case 36:
            return 3;
        default:
            return -99;
        }
    }

// the W section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcWPr(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 14;
        case 2:
            return 13;
        case 3:
            return 10;
        case 4:
            return 14;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 14;
        case 15:
            return 13;
        case 16:
            return 15;
        case 17:
            return 11;
        case 18:
            return 10;
        case 19:
            return 18;
        case 20:
            return 11;
        case 21:
            return 18;
        case 22:
            return 15;
        case 23:
            return 15;
        case 24:
            return 18;
        case 25:
            return 17;
        case 26:
            return 16;
        case 27:
            return 12;
        case 28:
            return 18;
        case 29:
            return 11;
        case 30:
            return 13;
        case 31:
            return 11;
        case 32:
            return 10;
        case 33:
            return 12;
        case 34:
            return 15;
        case 35:
            return 12;
        case 36:
            return 11;
        default:
            return -99;
        }
    }

// the W section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcWMvMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 5;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 5;
        case 27:
            return 3;
        case 28:
            return 5;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 5;
        case 35:
            return 1;
        case 36:
            return 3;
        default:
            return -99;
        }
    }

// the W section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcWMvMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 5;
        case 27:
            return 5;
        case 28:
            return 5;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 5;
        case 35:
            return 1;
        case 36:
            return 3;
        default:
            return -99;
        }
    }

// the W section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcWTome(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        default:
            return -99;
        }
    }

// the W section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcWSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO dueling roster Z section pins ----

// the Z section roster count: 2 dueling spells (printed pp. 180-188).
inline int dfcZCount()
    { return 2; }

// the Z section school column: 0 = priest, 1 = wizard, in printed order
// (printed pp. 180-188).
inline int dfcZSchool(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

// the Z section level column: the (W n)/(P n) level 1-9 in printed order
// (printed pp. 180-188).
inline int dfcZLevel(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        default:
            return -99;
        }
    }

// the Z section usage column: the A/D/L/M/Any bitmask in printed order - the
// 38 F reads pin as the leech mask 4 and Thought Capture pins as 0 as printed
// (printed pp. 180-188).
inline int dfcZUsage(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        default:
            return -99;
        }
    }

// the Z section power rating column: PR 10-19 in printed order, the
// level-plus-nine doctrine with the printed exceptions pinned as printed
// (printed pp. 180-188).
inline int dfcZPr(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 11;
        default:
            return -99;
        }
    }

// the Z section movement minimum column: MV 1-5 (printed pp. 180-188).
inline int dfcZMvMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        default:
            return -99;
        }
    }

// the Z section movement maximum column: MV 1-5, equal to the minimum for
// single-value entries (printed pp. 180-188).
inline int dfcZMvMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        default:
            return -99;
        }
    }

// the Z section Tome of Magic mark column: 1 where the printed dagger stands
// (printed pp. 180-188).
inline int dfcZTome(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return -99;
        }
    }

// the Z section special-effect mark column: 1 where the printed asterisk
// stands (printed pp. 180-188).
inline int dfcZSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
