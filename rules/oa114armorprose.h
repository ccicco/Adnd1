// =========================================================================================
// Adnd1 - rules/oa114armorprose.h
// OA TREASURE - THE ARMOR AND SHIELD PROSE, printed capture p. 289 - the
// armor determination round
// census 665 -> 666.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 196 closed, 39 open - the armor prose box
// flips (census 665 -> 666); NEXT - R744: Table 75: Magical Armor (capture p.
// 289), prefix dlf (verify free at the landing), audit "R744 OA Table 75
// armor audit", include after rules/oa114armorprose.h
//
namespace rules {

// ---- the determination ----

// the purpose - to determine the type of magical armor found and its
// properties (print capture p. 289)
inline int dleDetermineTypeAndProperties()
    { return 1; }

// the freedom - the DM randomly rolls on the following tables or selects from
// the tables the features he wants (print capture p. 289)
inline int dleRollOrSelect()
    { return 1; }

// ---- the two steps ----

// the type table number - the Table 75 Magical Armor rolled first to
// determine the armor type (print capture p. 289)
inline int dleTypeTable()
    { return 75; }

// the first property table - the Table 76 Magical Armor Properties rolled
// after the type (print capture p. 289)
inline int dlePropertyTableFirst()
    { return 76; }

// the second property table - the Table 77 Special Properties of the armor
// (print capture p. 289)
inline int dlePropertyTableSecond()
    { return 77; }

// the first step - roll on the Table 75 to determine the armor type (print
// capture p. 289)
inline int dleFirstStepRollTable75()
    { return 1; }

// the second step - after determining the type of armor, roll on the Tables
// 76 and 77 to determine its properties (print capture p. 289)
inline int dleThenRollTables76And77()
    { return 1; }

}   // namespace rules
