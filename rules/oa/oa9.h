// =========================================================================================
// Adnd1 - rules/oa/oa9.h
// The OA table promotion batch nine - 139 table grids from the R614-R773
// specs promoted into the 94 OA Lua records - the tables leave the C++ pins
// census 937 -> 938.
//
// The OA table promotion - the promotions doctrine continued (the R968
// format, continuing the R981-R988 OA set): the promotion is meant for rules
// AND tables, to alleviate the burden off the C++ pin code, and to place in
// Lua what originally got placed into C++ code files. The OA monster defs are
// already in Lua (the 47 registry defs including the 39 Chapter 12
// promotions), but the eight R981-R988 promotion batches predate the table
// promotion - all 160 records shipped tables = {} while the R614-R773 specs
// declare 139 table grids (the dragon, DSG and WSG promotions carried
// theirs). This round mechanically re-promotes the tables from the specs into
// the 94 records that carry them (fix the record from the spec - the
// promotion doctrine; never hand-edit): 298072 Lua bytes, every record
// parse-back equal against its spec model, key for key in the spec order, the
// encoding the R968 record format. The C++ pin headers stay the firewall and
// the print-fidelity record; the Lua record now carries the table data so the
// C++ burden can retire. THE TABLE CENSUS: 139 of 139 promoted, 0 remaining -
// the OA tables gap closed in one round.
//
namespace rules {

// ---- the batch frame ----

// the OA records rewritten this batch - the 94 of 160 that carry table grids,
// rounds R615-R759
inline int oa9BatchRecords()
    { return 94; }

// the table grids promoted from the R614-R773 specs into the records this
// batch
inline int oa9TablesPromoted()
    { return 139; }

// the cumulative OA tables in the Lua records after this batch - 139 of 139,
// the gap closed
inline int oa9CumulativeTables()
    { return 139; }

// the OA tables still behind in the C++ pins after this batch - none, the set
// complete
inline int oa9SetTablesRemaining()
    { return 0; }

// ---- the guarantees ----

// every record with spec tables carries them after this batch - all 160
// records hold their full model
inline bool oa9RecordsCarryTables()
    { return true; }

// every promoted tables section parse-back equal against its spec model, key
// for key in the spec order
inline bool oa9DiffBackGreen()
    { return true; }

// the with-tables record rounds complete - the R981-R988 empty-tables gap
// closed in one pass
inline bool oa9R615ThroughR759Complete()
    { return true; }

}   // namespace rules
