// ============================================================================
// Adnd1 - items/MiscItemRegistry.h
// The misc magic item registry: Lua-driven definitions, the
// MonsterRegistry pattern (R71) applied to the 166 misc magic
// item defs promoted from the III.E explanation prose
// (R1027: the A2 de-wire round - the 23 prose part headers and
// their 23 pin-walking audits retired to boneyard/dmg/, the
// lua defs at content/magic_items/<letter>/<stem>.lua are the
// live record, and this registry is what makes them live).
//
// Each def file returns a table:
//   key, name                      - strings (key == file stem)
//   rows[] (optional - 2 defs are   kMisc table rows:
//            rowless: intro, eyes)
//       name, set ("kMisc1".."kMisc5"),
//       band = { lo, hi }, qty = { lo, hi },
//       xp, xp_hi, gp, gp_hi
//   sources[]                      - { part = 1..23, round = R number }
//   pins[]                         - { name, value, comment? }
//   tables[]                       - { name, values[], comment?, clamp_hi? }
//   subs[] (figurines, bards)      - nested defs: key, name,
//       sources, pins, tables (never rows)
//
// STRICT schema: the defs are tool-written (tools/miscmagic2lua.py
// is the only writer), so anything unexpected - an unknown key,
// a missing required field, a wrong type, a key that does not
// match the file stem, a rows entry inside a sub - is an error,
// not a default. There are no legacy fallbacks and no silent
// coercions; the errors() list names every offender.
//
// Lua C API only (Lua 5.4), per the original project convention.
// ============================================================================

#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

namespace items {

// ----------------------------------------------------------------------------
// One kMisc table row (the printed misc magic tables in dm/treasure.cpp;
// the defs mirror them and the R1027 audit cross-checks the totals).
// ----------------------------------------------------------------------------
struct MiscItemRow {
    std::string name;        // printed table name
    std::string set;         // "kMisc1" .. "kMisc5"
    int bandLo = 0, bandHi = 0;
    int xp = 0, xpHi = 0;
    int gp = 0, gpHi = 0;
    int qtyLo = 0, qtyHi = 0;
};

// One scalar pin (the old mmp<Name>() prose pin, same value).
struct MiscItemPin {
    std::string name;
    long long value = 0;
};

// One table walker (the old static-array walker, same values; a
// clamp_hi entry was a walker whose index clamps at its last row).
struct MiscItemTable {
    std::string name;
    std::vector<long long> values;
    int clampHi = 0;
    bool hasClamp = false;
};

// One item def (or, nested, one sub-item def).
struct MiscItemDef {
    std::string key;
    std::string name;
    std::vector<MiscItemRow> rows;
    std::vector<std::pair<int, int>> sources;   // (part, round)
    std::vector<MiscItemPin> pins;
    std::vector<MiscItemTable> tables;
    std::vector<MiscItemDef> subs;
};

class MiscItemRegistry {
public:
    // Load every <stem>.lua in the directory (one letter dir of
    // content/magic_items). Returns count loaded, or -1 on a hard
    // error (directory unreadable - a missing letter dir is the
    // normal shape, callers ignore -1 like the R71fix loop does).
    // Individual file errors are skipped with a note in errors().
    int loadDirectory(const std::string& dirPath);

    // Registry lookup; nullptr if not loaded.
    const MiscItemDef* find(const std::string& key) const;

    // All loaded defs, key-sorted.
    const std::map<std::string, MiscItemDef>& all() const { return m_defs; }

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, MiscItemDef> m_defs;
    std::vector<std::string> m_errors;
};

} // namespace items
