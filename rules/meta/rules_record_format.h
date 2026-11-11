// =========================================================================================
// Adnd1 - rules/meta/rules_record_format.h
// The rules record format - the Lua record shape for content/rules/
// census 890 -> 891.
//
// The content-structure arc round three, no book ink: the rules record format
// adjudicated with Curtiss 2026-10-31 - one Lua record per pin round, the
// mechanical translation of the round's spec JSON (the spec stays the
// adjudicated record, the lua is promoted, never hand-edited); buckets by
// source book (phb, dmg, ddg, dragon, ...), one file per round; the battery
// derives from records (rverify semantics) and regtest shrinks to engine plus
// smoke once it is GREEN record-side; the Dragon set (issues 2-26, 128 specs)
// promotes first. The format document rides doc/rules_record_format.md.
//
namespace rules {

// ---- the format frame ----

// the record fields - round, prefix, banner, consts, bools, switches, tables,
// chains, examples, audit
inline int rpfRecordSections()
    { return 10; }

// the model pools - consts, bools, switches, tables, chains (the speclib
// shape)
inline int rpfModelPools()
    { return 5; }

// the first batch - Dragon issues 2-26, twenty-five issues all closed
inline int rpfDragonIssues()
    { return 25; }

// the Dragon round specs, the promotion source set measured at R968
inline int rpfDragonSpecs()
    { return 128; }

// the batch rides the 128-spec measure (the count the promotion builder
// walks)
inline int rpfBatchSize()
    { return 128; }

// the record format version - the R968 shape, versioned for the promotion
// tooling
inline int rpfFormatVersion()
    { return 1; }

// ---- the format doctrines ----

// one Lua record per pin round - a bucket holds many records, the file is the
// adjudication (Curtiss, 2026-10-31)
inline bool rpfRecordPerRound()
    { return true; }

// buckets by source book - content/rules/{phb,dmg,ddg,dragon,...}/, the
// printed taxonomy
inline bool rpfBucketByBook()
    { return true; }

// records are mechanical translations of the spec JSONs - the translation
// back is the proof
inline bool rpfPromotedFromSpecs()
    { return true; }

// DO NOT hand-edit a record - fix the spec and re-promote (the monster def
// doctrine)
inline bool rpfNoHandEdit()
    { return true; }

// the battery derives from records - speclib semantics, rverify's mutants,
// pointed at records
inline bool rpfBatteryFromRecords()
    { return true; }

// the Dragon set promotes first - recent specs, easy verify - then the walk
// books
inline bool rpfDragonFirst()
    { return true; }

}   // namespace rules
