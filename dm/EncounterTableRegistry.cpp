// ============================================================================
// Adnd1 - dm/EncounterTableRegistry.cpp
// The dungeon encounter table registry loader (R1032; R1033 added
// the water family loader; R1034 the outdoor family and its pick-sets).
// The shape
// follows items::MiscItemRegistry.cpp: a fresh lua_State per file,
// luaL_dofile, the file must leave a table on the stack, typed getters
// with no defaults, errors accumulated in errors(), loadDirectory
// POSIX readdir / Win32 FindFirstFileA with the R74 "no files is not
// an error" and the 3-char-extension guard. STRICT unknown-key
// rejection: these files are one tool's uniform output, so a def
// that carries anything outside its schema is drift and dies loudly.
// ============================================================================

#include "EncounterTableRegistry.h"

#include <cstdio>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace dm {
namespace {

// ---- typed getters: no defaults, wrong type = error ----------------------
// Each leaves the stack exactly as it found it.

bool getStr(lua_State* L, int idx, const char* key, std::string* out,
            std::string* err) {
    lua_getfield(L, idx, key);
    if (lua_isnoneornil(L, -1)) {
        *err = std::string("missing string '") + key + "'";
        lua_pop(L, 1);
        return false;
    }
    if (!lua_isstring(L, -1)) {
        *err = std::string("'") + key + "' is not a string";
        lua_pop(L, 1);
        return false;
    }
    size_t len = 0;
    const char* s = lua_tolstring(L, -1, &len);
    out->assign(s, len);
    lua_pop(L, 1);
    return true;
}

// pair = { lo, hi }: exactly two integers.
bool getIntPair(lua_State* L, int idx, const char* key, int* lo, int* hi,
                std::string* err) {
    lua_getfield(L, idx, key);
    if (!lua_istable(L, -1)) {
        *err = std::string("'") + key + "' is not a table";
        lua_pop(L, 1);
        return false;
    }
    if (lua_rawlen(L, -1) != 2) {
        *err = std::string("'") + key + "' is not a 2-element table";
        lua_pop(L, 1);
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        lua_rawgeti(L, -1, i + 1);
        if (!lua_isinteger(L, -1)) {
            *err = std::string("'") + key + "' element is not an integer";
            lua_pop(L, 1);
            return false;
        }
        if (i == 0) *lo = (int)lua_tointeger(L, -1);
        else        *hi = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    return true;
}

// Reject keys outside the allowed set (schema drift guard).
bool checkAllowedKeys(lua_State* L, int idx, const char* const* allowed,
                      const std::string& where, std::string* err) {
    const int t = lua_absindex(L, idx);
    lua_pushnil(L);
    while (lua_next(L, t) != 0) {
        if (lua_type(L, -2) == LUA_TSTRING) {
            size_t len = 0;
            const char* k = lua_tolstring(L, -2, &len);
            bool ok = false;
            for (int i = 0; allowed[i]; ++i)
                if (std::strcmp(k, allowed[i]) == 0) { ok = true; break; }
            if (!ok) {
                *err = where + ": unknown key '" + k + "'";
                lua_pop(L, 2);
                return false;
            }
        }
        lua_pop(L, 1);
    }
    return true;
}

const char* const kLevelRowKeys[] =
    { "kind", "band", "key", "count", "heads", "number", nullptr };
const char* const kDragonRowKeys[] =
    { "band", "key", "age", nullptr };
const char* const kWaterRowKeys[] =
    { "band", "key", "flags", nullptr };
const char* const kWaterFileKeys[] = { "key", "rows", nullptr };
const char* const kOutdoorRowKeys[] = { "key", "cols", nullptr };
const char* const kOutdoorFileKeys[] = { "key", "rows", nullptr };
const char* const kOutdoorSetKeys[] =
    { "key", "ki_rin", "leprechaun", "porcupine", "iguanodon",
      "lammasu", "wolf_dog", nullptr };
const char* const kMatrixKeys[]  = { "key", "bands", nullptr };
const char* const kLevelKeys[]   = { "key", "rows", nullptr };
const char* const kDragonKeys[]  = { "key", "rows", nullptr };
const char* const kListsKeys[]  =
    { "key", "princes", "arch_devils", "elementals",
      "hill_stone", "fire_frost", "piercers", nullptr };

// R1033: the water family file keys.
bool isWaterKey(const std::string& k) {
    return k.rfind("underwater_", 0) == 0
        || k.rfind("waterborne_", 0) == 0
        || k == "dinosaur_sub";
}

// R1034: the outdoor family file keys. NOTE: outdoor_sets is
// excluded - it must fall through to its own shape branch (the
// outdoor_sets pick-set loader), not the STRICT rows loader.
bool isOutdoorKey(const std::string& k) {
    return k.rfind("outdoor_", 0) == 0 && k != "outdoor_sets";
}

bool isLevelKind(const std::string& k) {
    return k == "monster" || k == "human" || k == "character"
        || k == "dragon" || k == "elemental" || k == "prince"
        || k == "hydra" || k == "none";
}

}  // namespace

// ----------------------------------------------------------------------------
// File load (strict). The file key names the shape:
//   dungeon_level_<n>  rows[]   {kind, band, [key, count] | [key,
//                                heads, number]}
//   dragon_<n>         rows[]   {band, key, age}
//   matrix             bands[]  12 x 10 x {lo, hi, mlv}
//   lists              six string arrays
// ----------------------------------------------------------------------------

bool EncounterTableRegistry::loadFile(const std::string& path,
                                      const std::string& key) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, path.c_str()) != LUA_OK) {
        char buf[512];
        snprintf(buf, sizeof buf, "%s: %s", key.c_str(),
                 lua_tostring(L, -1));
        m_errors.push_back(buf);
        lua_close(L);
        return false;
    }
    if (!lua_istable(L, -1)) {
        m_errors.push_back(key + ": file must return a table");
        lua_close(L);
        return false;
    }

    std::string err;

    if (key.rfind("dungeon_level_", 0) == 0) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kLevelKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key '" + k + "' does not match file";
                            goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kLevelRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterRow row;
                if (!getStr(L, rt, "kind", &row.kind, &err)) goto bad;
                if (!isLevelKind(row.kind)) {
                    err = "unknown kind '" + row.kind + "'"; goto bad;
                }
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (row.kind == "monster" || row.kind == "hydra") {
                    if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                }
                if (row.kind == "monster") {
                    if (!getIntPair(L, rt, "count", &row.a, &row.b, &err))
                        goto bad;
                } else if (row.kind == "hydra") {
                    if (!getIntPair(L, rt, "heads", &row.a, &row.b, &err))
                        goto bad;
                    if (!getIntPair(L, rt, "number",
                                    &row.nmin, &row.nmax, &err)) goto bad;
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_levels.count(key)) { err = "duplicate def key"; goto bad; }
            m_levels[key] = rows;
        }
    } else if (key.rfind("dragon_", 0) == 0) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kDragonKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key '" + k + "' does not match file";
                            goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<DragonAgeRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kDragonRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                DragonAgeRow row;
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                if (!getIntPair(L, rt, "age", &row.ageLo, &row.ageHi, &err))
                    goto bad;
                rows.push_back(row);
                lua_pop(L, 1);
            }
            lua_pop(L, 1);
            if (m_dragons.count(key)) { err = "duplicate def key"; goto bad; }
            m_dragons[key] = rows;
        }
    } else if (key == "matrix") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kMatrixKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "matrix") { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "bands");
        if (!lua_istable(L, -1)) { err = "bands is not a table"; goto bad; }
        {
            const int nb = (int)lua_rawlen(L, -1);
            if (nb != 12) { err = "bands must carry 12 entries"; goto bad; }
            std::vector<std::vector<MatrixEntry>> bands;
            for (int b = 1; b <= nb; ++b) {
                lua_rawgeti(L, -1, b);
                const int bt = lua_gettop(L);
                if (!lua_istable(L, bt) || (int)lua_rawlen(L, bt) != 10) {
                    err = "band " + std::to_string(b)
                        + " must carry 10 entries";
                    goto bad;
                }
                std::vector<MatrixEntry> ents;
                for (int i = 1; i <= 10; ++i) {
                    lua_rawgeti(L, bt, i);
                    const int et = lua_gettop(L);
                    if (!lua_istable(L, et)
                        || (int)lua_rawlen(L, et) != 3) {
                        err = "matrix entry must be a 3-int table";
                        goto bad;
                    }
                    long long v[3];
                    for (int j = 0; j < 3; ++j) {
                        lua_rawgeti(L, et, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "matrix entry field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    ents.push_back(MatrixEntry{ (int)v[0], (int)v[1],
                                                (int)v[2] });
                    lua_pop(L, 1);        // entry
                }
                bands.push_back(ents);
                lua_pop(L, 1);            // band
            }
            lua_pop(L, 1);                // bands array
            if (!m_matrix.empty()) { err = "duplicate def key"; goto bad; }
            m_matrix = bands;
        }
    } else if (key == "lists") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kListsKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "lists") { err = "def key mismatch"; goto bad; }
        }
        {
            const char* const names[] = { "princes", "arch_devils",
                "elementals", "hill_stone", "fire_frost", "piercers" };
            for (int i = 0; i < 6; ++i) {
                lua_getfield(L, t, names[i]);
                if (!lua_istable(L, -1)) {
                    err = std::string("'") + names[i] + "' is not a table";
                    goto bad;
                }
                const int cnt = (int)lua_rawlen(L, -1);
                std::vector<std::string> vals;
                for (int j = 1; j <= cnt; ++j) {
                    lua_rawgeti(L, -1, j);
                    if (!lua_isstring(L, -1)) {
                        err = std::string("'") + names[i]
                            + "' element is not a string";
                        goto bad;
                    }
                    size_t len = 0;
                    const char* s = lua_tolstring(L, -1, &len);
                    vals.push_back(std::string(s, len));
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                if (m_lists.count(names[i])) {
                    err = "duplicate list"; goto bad;
                }
                m_lists[names[i]] = vals;
            }
        }
    } else if (isWaterKey(key)) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kWaterFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key '" + k + "' does not match file";
                            goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterWaterRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kWaterRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterWaterRow row;
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                lua_getfield(L, rt, "flags");
                if (!lua_isinteger(L, -1)) {
                    err = "'flags' is not an integer";
                    lua_pop(L, 1);
                    goto bad;
                }
                row.flags = (int)lua_tointeger(L, -1);
                lua_pop(L, 1);
                // STRICT: the gates are single footnote bits
                if (row.flags != 0 && row.flags != 1
                    && row.flags != 2 && row.flags != 4) {
                    err = "'flags' outside the gate bits";
                    goto bad;
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_waters.count(key)) { err = "duplicate def key"; goto bad; }
            m_waters[key] = rows;
        }
    } else if (isOutdoorKey(key)) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kOutdoorFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key '" + k + "' does not match file";
                            goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterOutdoorRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kOutdoorRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterOutdoorRow row;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                lua_getfield(L, rt, "cols");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 8) {
                    err = "'cols' must carry 8 terrain pairs";
                    lua_pop(L, 1);
                    goto bad;
                }
                for (int c = 0; c < 8; ++c) {
                    lua_rawgeti(L, -1, c + 1);
                    const int ct = lua_gettop(L);
                    if (!lua_istable(L, ct)
                        || (int)lua_rawlen(L, ct) != 2) {
                        err = "cols pair must be {lo, hi}";
                        goto bad;
                    }
                    long long v[2];
                    for (int j = 0; j < 2; ++j) {
                        lua_rawgeti(L, ct, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "cols pair field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);        // pair
                    const int clo = (int)v[0], chi = (int)v[1];
                    if (clo == -1 && chi == -1) {
                        // no entry in this terrain column
                    } else if (clo >= 1 && clo <= 100
                               && chi >= clo && chi <= 100) {
                        row.lo[c] = clo;
                        row.hi[c] = chi;
                    } else {
                        err = "cols pair outside 01-00";
                        goto bad;
                    }
                }
                lua_pop(L, 1);            // cols
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_outdoors.count(key)) { err = "duplicate def key"; goto bad; }
            m_outdoors[key] = rows;
        }
    } else if (key == "outdoor_sets") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kOutdoorSetKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "outdoor_sets") { err = "def key mismatch"; goto bad; }
        }
        {
            const char* const names[6] = { "ki_rin", "leprechaun",
                "porcupine", "iguanodon", "lammasu", "wolf_dog" };
            for (int i = 0; i < 6; ++i) {
                lua_getfield(L, t, names[i]);
                if (!lua_istable(L, -1)) {
                    err = std::string("'") + names[i]
                        + "' is not a table";
                    goto bad;
                }
                const int cnt = (int)lua_rawlen(L, -1);
                if (cnt < 2) {
                    err = std::string("'") + names[i]
                        + "' must carry at least two keys";
                    goto bad;
                }
                std::vector<std::string> vals;
                for (int j = 1; j <= cnt; ++j) {
                    lua_rawgeti(L, -1, j);
                    if (!lua_isstring(L, -1)) {
                        err = std::string("'") + names[i]
                            + "' element is not a string";
                        goto bad;
                    }
                    size_t len = 0;
                    const char* s = lua_tolstring(L, -1, &len);
                    vals.push_back(std::string(s, len));
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                const std::string setKey =
                    std::string(names[i]) + "_set";
                if (m_lists.count(setKey)) {
                    err = "duplicate def key";
                    goto bad;
                }
                m_lists[setKey] = vals;
            }
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }

    lua_close(L);
    return true;

bad:
    m_errors.push_back(key + ": " + err);
    lua_close(L);
    return false;
}

// ----------------------------------------------------------------------------
// Directory load: platform-scoped, the MiscItemRegistry shape.
// ----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>

int EncounterTableRegistry::loadDirectory(const std::string& dirPath) {
    std::string pattern = dirPath + "\\*.lua";
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern.c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) {
        // R74: "no files" is not an error - only hard path errors are -1.
        return GetLastError() == ERROR_FILE_NOT_FOUND ? 0 : -1;
    }
    int count = 0;
    do {
        std::string fname = fd.cFileName;
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "\\" + fname, key)) ++count;
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    return count;
}

#else   // POSIX fallback (Termux, tests/dev on non-Windows)
#include <dirent.h>

int EncounterTableRegistry::loadDirectory(const std::string& dirPath) {
    DIR* d = opendir(dirPath.c_str());
    if (!d) return -1;
    int count = 0;
    struct dirent* e;
    while ((e = readdir(d)) != nullptr) {
        std::string fname = e->d_name;
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "/" + fname, key)) ++count;
    }
    closedir(d);
    return count;
}
#endif

// ----------------------------------------------------------------------------
// Accessors (empty statics for a missing table - the audit counts
// catch that loudly).
// ----------------------------------------------------------------------------

bool EncounterTableRegistry::hasLevel(int n) const {
    return m_levels.count("dungeon_level_" + std::to_string(n)) != 0;
}

bool EncounterTableRegistry::hasDragon(int n) const {
    return m_dragons.count("dragon_" + std::to_string(n)) != 0;
}

const std::vector<EncounterRow>&
EncounterTableRegistry::levelRows(int n) const {
    static const std::vector<EncounterRow> none;
    auto it = m_levels.find("dungeon_level_" + std::to_string(n));
    return it == m_levels.end() ? none : it->second;
}

const std::vector<DragonAgeRow>&
EncounterTableRegistry::dragonRows(int n) const {
    static const std::vector<DragonAgeRow> none;
    auto it = m_dragons.find("dragon_" + std::to_string(n));
    return it == m_dragons.end() ? none : it->second;
}

const std::vector<MatrixEntry>&
EncounterTableRegistry::matrixBand(int band) const {
    static const std::vector<MatrixEntry> none;
    if (band < 0 || band >= (int)m_matrix.size()) return none;
    return m_matrix[band];
}

bool EncounterTableRegistry::hasWater(const std::string& name) const {
    return m_waters.count(name) != 0;
}

const std::vector<EncounterWaterRow>&
EncounterTableRegistry::waterRows(const std::string& name) const {
    static const std::vector<EncounterWaterRow> none;
    auto it = m_waters.find(name);
    return it == m_waters.end() ? none : it->second;
}

bool EncounterTableRegistry::hasOutdoor(const std::string& name) const {
    return m_outdoors.count(name) != 0;
}

const std::vector<EncounterOutdoorRow>&
EncounterTableRegistry::outdoorRows(const std::string& name) const {
    static const std::vector<EncounterOutdoorRow> none;
    auto it = m_outdoors.find(name);
    return it == m_outdoors.end() ? none : it->second;
}

const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {
    static const std::vector<std::string> none;
    auto it = m_lists.find(set);
    return it == m_lists.end() ? none : it->second;
}

} // namespace dm
