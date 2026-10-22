// =========================================================================================
// Adnd1 - rules/oa119weaponsprose.h
// OA TREASURE - THE WEAPONS PROSE, printed capture pp. 291-294 - the weapons
// flow round
// census 670 -> 671.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 201 closed, 34 open - the weapons prose
// box flips (census 670 -> 671); NEXT - R749: Table 78: Magical Weapons
// (capture p. 291), prefix dlk (verify free at the landing), audit "R749 OA
// Table 78 weapons audit", include after rules/oa119weaponsprose.h
//
namespace rules {

// ---- the flow ----

// the trigger - the magical weapon rolled on the Table III of the DMG (print
// capture p. 291)
inline int dljRolledOnTableIII()
    { return 1; }

// the general type table - the Table 78 rolled to determine the general type
// of weapon (print capture p. 291)
inline int dljGeneralTypeTable()
    { return 78; }

// the first step - roll on the Table 78 to determine the general type of
// weapon (print capture p. 291)
inline int dljStepOneGeneralType()
    { return 1; }

// the property table - the Table 79 rolled to find the magical property of
// the weapon (print capture p. 291)
inline int dljPropertyTable()
    { return 79; }

// the second step - roll on the Table 79 to find the magical property of the
// weapon (print capture p. 291)
inline int dljStepTwoProperty()
    { return 1; }

// the first specific table - the Table 80 opening the range of the specific
// type tables (print capture p. 291)
inline int dljSpecificTableFirst()
    { return 80; }

// the last specific table - the Table 85 closing the range of the specific
// type tables (print capture p. 291)
inline int dljSpecificTableLast()
    { return 85; }

// the third step - roll on the appropriate table of the Tables 80-85 to
// determine the specific type of weapon (print capture p. 291)
inline int dljStepThreeSpecificType()
    { return 1; }

}   // namespace rules
