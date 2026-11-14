// ============================================================================
// Adnd1 - dm/EncounterTableRegistry.h
// The DMG Appendix C dungeon encounter table registry (R1032): the
// retired kLevel/kDrag/kMatrix/pool arrays of dm/encounters.cpp live
// as lua under content/tables/encounters/ and load through this
// class. The shape follows items::MiscItemRegistry.h: typed getters
// with no defaults, STRICT unknown-key rejection, errors accumulated
// in errors(), the R74 directory contract. The R52 print-fidelity
// record (Premium reprint p.174-179, OCR-verified) is the source;
// tools/r1032_splice.py (dungeon family),
// tools/r1033_splice.py (water family),
// tools/r1034_splice.py (outdoor family) and
// tools/r1035_splice.py (city family) are the only writers.
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

// One water encounter table row (R1033): the R60 underwater set,
// the R127 waterborne set and the shared p.190 Dinosaur Subtable.
// flags carries the footnote gates: 1 = cool waters only,
// 2 = warm waters only, 4 = deep water only.
struct EncounterWaterRow {
    std::string key;
    int lo = 0, hi = 0;
    int flags = 0;
};

// One outdoor (wilderness) encounter table row (R1034): the R63
// eight climate tables, the eleven SUB_* terrain subtables and the
// single-column tropical Sphinx Subtable (replicated across the
// eight terrain columns - the footnote is terrain-independent).
// lo/hi carry one percentile band per terrain column
// (Plain/Scrub/Forest/Rough/Desert/Hills/Mountains/Marsh);
// -1 = the row prints no entry in that column.
struct EncounterOutdoorRow {
    std::string key;
    int lo[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
    int hi[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
};

// R1035: the city family. One matrix row carries the day and
// night percentile bands of the DMG p.191 city matrix
// (-1 = the book prints no band there); the flavor and
// protection band tables share EncounterCityBand; the printed
// encounter numbers roll plus + nDd (fixed >= 0 overrides);
// the p.192 magic chances carry one percent-per-level entry
// per group (0 fighter-ish, 1 cleric, 2 magic-user).
struct EncounterCityRow {
    std::string key;
    int loDay = -1, hiDay = -1;
    int loNight = -1, hiNight = -1;
};
struct EncounterCityBand {
    int lo = 0, hi = 0;
    std::string kind;
};
struct EncounterCityCount {
    int n = 0, d = 0, plus = 0;
    int nN = 0, dN = 0, plusN = 0;
    bool hasNight = false;
    int fixed = -1;             // -1: dice path; >= 0: printed constant
};
struct EncounterCityMagic {
    std::string category;
    int groups[3] = { 0, 0, 0 };
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
    // name: underwater_fresh_shallow / underwater_fresh_deep /
    // underwater_salt_shallow / underwater_salt_deep / dinosaur_sub /
    // waterborne_fresh_small / waterborne_fresh_large /
    // waterborne_salt_shallow / waterborne_salt_deep (R1033)
    bool hasWater(const std::string& name) const;
    const std::vector<EncounterWaterRow>& waterRows(
        const std::string& name) const;
    // name: outdoor_arctic / outdoor_sub_arctic /
    // outdoor_temperate_wild / outdoor_temperate_inhabited /
    // outdoor_faerie / outdoor_pleistocene / outdoor_dinosaur_age /
    // outdoor_tropical / outdoor_sub_demihuman / outdoor_sub_dragon /
    // outdoor_sub_frog / outdoor_sub_giant / outdoor_sub_humanoid /
    // outdoor_sub_lycanthrope / outdoor_sub_men / outdoor_sub_snake /
    // outdoor_sub_sphinx / outdoor_sub_spider / outdoor_sub_undead /
    // outdoor_sphinx_t (R1034)
    bool hasOutdoor(const std::string& name) const;
    const std::vector<EncounterOutdoorRow>& outdoorRows(
        const std::string& name) const;
    // band 0..11 -> the 10 matrix entries of that dungeon-level band
    const std::vector<MatrixEntry>& matrixBand(int band) const;
    // set: princes / arch_devils / elementals / hill_stone /
    // fire_frost / piercers / ki_rin_set / leprechaun_set /
    // porcupine_set / iguanodon_set / lammasu_set / wolf_dog_set
    const std::vector<std::string>& list(const std::string& set) const;
    // R1035: the city family views. cityBandLookup clamps the
    // percentile to 1-100 and returns false when no band matches
    // (the flavorKindFor contract). cityCount returns nullptr for
    // an absent key - the caller rolls one specimen.
    bool hasCityMatrix() const;
    const std::vector<EncounterCityRow>& cityRows() const;
    bool hasCityBands(const std::string& name) const;
    const std::vector<EncounterCityBand>& cityBands(
        const std::string& name) const;
    bool cityBandLookup(const std::string& name, int pctile,
                        std::string* kind) const;
    const EncounterCityCount* cityCount(const std::string& key) const;
    const std::vector<EncounterCityMagic>& cityMagic() const;

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, std::vector<EncounterRow>> m_levels;
    std::map<std::string, std::vector<DragonAgeRow>> m_dragons;
    std::map<std::string, std::vector<EncounterWaterRow>> m_waters;
    std::map<std::string, std::vector<EncounterOutdoorRow>> m_outdoors;
    std::vector<std::vector<MatrixEntry>> m_matrix;   // 12 x 10
    std::map<std::string, std::vector<std::string>> m_lists;
    // R1035: the city family (one matrix, the band tables, the
    // count dice and the magic chances).
    std::vector<EncounterCityRow> m_city;
    std::map<std::string, std::vector<EncounterCityBand>> m_cityBands;
    std::map<std::string, EncounterCityCount> m_cityCounts;
    std::vector<EncounterCityMagic> m_cityMagic;
    std::vector<std::string> m_errors;
};

} // namespace dm
