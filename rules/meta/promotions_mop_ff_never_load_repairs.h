// =========================================================================================
// Adnd1 - rules/meta/promotions_mop_ff_never_load_repairs.h
// The promotions mop round one - the twenty-five FF never-load defs repaired,
// the registry floor 1338 of 1338
// census 928 -> 929.
//
// The promotions mop arc opener - the registry never-load repair, Curtiss's
// post-UA-arc call (all the promotion loose ends, one arc). The R900 lesson
// named the ground truth: the battery line is the only registry truth, never
// the file count - and the line has read 1313 loaded, errors 25 since the
// R924 re-measure. The 25 broken defs are all Fiend Folio promotions of the
// R836-R842 FF arc (the bloodworm, the carbuncle, the caryatid column,
// Cryonax, the dark pair, the death pair, the dire corby, the doombat, the
// enveloper, the eye pair, the fire trio, the flail snail, Imix, Lolth,
// Ogremoch, Olhydra, the pan lung, the styx devil, the tien lung, Yan-C-Bin
// and the yu lung): each carries its text field with RAW NEWLINES where the
// backslash-n escapes belong - the emitter of the FF batches never escaped
// the paragraph breaks, so the Lua 5.4 loader dies at the text line with
// unfinished-string errors, exactly the pre-R900 print-fidelity state the
// cfc/d21/l22/l23 pins carried forward. THE REPAIR IS PURELY MECHANICAL:
// every raw newline inside the text strings becomes a backslash-n escape - no
// ink touched, no field touched but the text line, every other byte of every
// file identical, and the sandbox proof: all 25 unescape back to the landed
// bytes exactly, the whole-tree lexer scan reads 1338 of 1338 clean after the
// repair, and the xp audit anticipates no anomaly (all 25 are ff_print defs
// with clean xp fields). The battery line moves to loaded 1338, errors 0 -
// the registry floor meets the file count for the first time since the R900
// lesson. The historical snapshot pins stand as landed (the cfc 1311/1333/25
// and the d21/l22/l23 1313/1338/25 records are the historical states they
// pinned); the mop retires the never-load doctrine, not the history.
//
namespace rules {

// ---- the mop frame ----

// the promotions mop arc opener round
inline int pm1Round()
    { return 1006; }

// the repaired defs - the twenty-five FF promotion defs of the R836-R842 arc
// that carried raw newlines in their text fields
inline int pm1RepairedDefs()
    { return 25; }

// the raw newlines escaped to backslash-n across the twenty-five text fields
// - the only bytes changed
inline int pm1ParagraphBreaksEscaped()
    { return 174; }

// ---- the registry ground truth ----

// the battery line after the repair - loaded 1338, errors 0, the registry
// floor meeting the file count for the first time since the R900 lesson
inline int pm1RegistryLoadedAfter()
    { return 1338; }

// the base lua file count under content/monsters - unchanged by this round,
// every file now loading
inline int pm1BaseLuaFiles()
    { return 1338; }

// the never-load count after the repair - zero, the pre-R900 state retired
inline int pm1NeverLoadAfter()
    { return 0; }

// the historical never-load count the R924 re-measure pinned - 1313 loaded /
// 1338 base / 25 never-load, the state this round retires
inline int pm1PreviousNeverLoad()
    { return 25; }

// ---- the repair doctrines ----

// the repair touches no ink - every raw newline becomes a backslash-n escape
// and every other byte of every file is identical, the unescape proof equal
inline bool pm1RepairMechanical()
    { return true; }

// the whole-tree lexer scan reads 1338 of 1338 clean after the repair - the
// unfinished-string class dies at this round
inline bool pm1RoundTripGreen()
    { return true; }

// the battery line is the only registry ground truth (the R900 lesson) - and
// the line now reads loaded 1338, errors 0; the historical snapshot pins
// stand as landed
inline bool pm1GroundTruthReplaced()
    { return true; }

}   // namespace rules
