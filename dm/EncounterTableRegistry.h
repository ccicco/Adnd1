// ============================================================================
// Adnd1 - dm/EncounterTableRegistry.h
// The DMG Appendix C dungeon encounter table registry (R1032): the
// retired kLevel/kDrag/kMatrix/pool arrays of dm/encounters.cpp live
// as lua under content/tables/encounters/ and load through this
// class. The shape follows items::MiscItemRegistry.h: typed getters
// with no defaults, STRICT unknown-key rejection, errors accumulated
// in errors(), the R74 directory contract. The R52 print-fidelity
// record (Premium reprint p.174-179, OCR-verified) is the source;
// tools/r1032_splice.py is the only writer.
// ============================================================================

#pragma once

#include <map>
#include <string>
#include <vector>

namespace dm {

// One Monster Level Table row. kind is one of monster/human/character/
// dragon/elemental/prince/hydra/none. a,b are the count range (monster)
// or head range (hydra); nmin,nmax the hydra number appearing.
struct EncounterRow {
    std::string kind;
    int lo = 0, hi = 0;
    std::string key;             // "" for the band-only kinds
    int a = 0, b = 0, nmin = 0, nmax = 0;
};

// One Dragon Subtable row (age bracket 1-8 range).
struct DragonAgeRow {
    int lo = 0, hi = 0;
    std::string key;
    int ageLo = 0, ageHi = 0;
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };

class EncounterTableRegistry {
public:
    // Load every <stem>.lua in the directory. Returns count loaded, or
    // -1 on a hard error (directory unreadable). File errors are
    // skipped with a note in errors().
    int loadDirectory(const std::string& dirPath);

    bool hasLevel(int n) const;            // dungeon_level_n, n 1..10
    bool hasDragon(int n) const;          // dragon_n, n 3..10
    const std::vector<EncounterRow>& levelRows(int n) const;
    const std::vector<DragonAgeRow>& dragonRows(int n) const;
    // band 0..11 -> the 10 matrix entries of that dungeon-level band
    const std::vector<MatrixEntry>& matrixBand(int band) const;
    // set: princes / arch_devils / elementals / hill_stone /
    // fire_frost / piercers
    const std::vector<std::string>& list(const std::string& set) const;

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, std::vector<EncounterRow>> m_levels;
    std::map<std::string, std::vector<DragonAgeRow>> m_dragons;
    std::vector<std::vector<MatrixEntry>> m_matrix;   // 12 x 10
    std::map<std::string, std::vector<std::string>> m_lists;
    std::vector<std::string> m_errors;
};

} // namespace dm
