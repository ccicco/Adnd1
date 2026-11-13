// ============================================================================
// Adnd1 - items/MiscItemRegistry.cpp
// The misc magic item registry loader (R1027). See the header for
// the schema and the strictness contract. The shape follows
// monsters/MonsterRegistry.cpp: a fresh lua_State per file,
// luaL_dofile, the file must leave a table on the stack, typed
// getters with no defaults, errors accumulated in errors(),
// loadDirectory POSIX readdir / Win32 FindFirstFileA with the
// R74 "no files is not an error" and the 3-char-extension guard.
//
// Stack discipline: every helper is push/pop balanced, and every
// array walk pushes its element, parses it with the helpers at
// stack top, then pops exactly the element; the array itself is
// popped once after the loop. Error paths return immediately
// without unwinding - loadFile closes the lua_State, so a
// transient imbalance on a dying load leaks nothing.
//
// The one deliberate divergence from MonsterRegistry: STRICT
// unknown-key rejection. Monster defs are historical and tolerant;
// misc defs are one tool's uniform output, so a def that carries
// anything outside {key, name, rows, sources, pins, tables, subs}
// (or a sub that carries rows) is schema drift and dies loudly.
// ============================================================================

#include "MiscItemRegistry.h"

#include <cstdio>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace items {
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

bool getInt(lua_State* L, int idx, const char* key, long long* out,
            std::string* err) {
    lua_getfield(L, idx, key);
    if (lua_isnoneornil(L, -1)) {
        *err = std::string("missing integer '") + key + "'";
        lua_pop(L, 1);
        return false;
    }
    if (!lua_isinteger(L, -1)) {
        *err = std::string("'") + key + "' is not an integer";
        lua_pop(L, 1);
        return false;
    }
    *out = lua_tointeger(L, -1);
    lua_pop(L, 1);
    return true;
}

// band = { lo, hi } / qty = { lo, hi }: exactly two integers.
bool getIntPair(lua_State* L, int idx, const char* key, int* lo, int* hi,
                std::string* err) {
    lua_getfield(L, idx, key);            // pair on top
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
        lua_rawgeti(L, -1, i + 1);        // element on top
        if (!lua_isinteger(L, -1)) {
            *err = std::string("'") + key + "' element is not an integer";
            lua_pop(L, 1);
            return false;                 // pair stays; loadFile bails
        }
        if (i == 0) *lo = (int)lua_tointeger(L, -1);
        else        *hi = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pop(L, 1);                        // pair
    return true;
}

// A comment, when present, must be a string. The loader does not
// keep comments (print-fidelity prose, not engine data); this
// only enforces the type so a malformed def cannot slip through.
bool checkOptionalString(lua_State* L, int idx, const char* key,
                         std::string* err) {
    lua_getfield(L, idx, key);
    if (!lua_isnoneornil(L, -1) && !lua_isstring(L, -1)) {
        *err = std::string("'") + key + "' is present but not a string";
        lua_pop(L, 1);
        return false;
    }
    lua_pop(L, 1);
    return true;
}

// Reject keys outside the allowed set (schema drift guard).
// Balanced: lua_next idiom pops key+value each step, the final
// key is left by lua_next itself and popped on loop exit.
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
                lua_pop(L, 2);            // key + value
                return false;
            }
        }
        lua_pop(L, 1);                    // value; key feeds next lua_next
    }
    return true;
}

const char* const kDefKeys[] =
    { "key", "name", "rows", "sources", "pins", "tables", "subs", nullptr };
const char* const kRowKeys[] =
    { "name", "set", "band", "xp", "xp_hi", "gp", "gp_hi", "qty", nullptr };
const char* const kSourceKeys[] = { "part", "round", nullptr };
const char* const kPinKeys[] = { "name", "value", "comment", nullptr };
const char* const kTableKeys[] =
    { "name", "comment", "clamp_hi", "values", nullptr };
const char* const kSubKeys[] =
    { "key", "name", "sources", "pins", "tables", nullptr };

// ---- one def table -------------------------------------------------------
// The def table sits at idx (its absolute position is stable for
// the whole call: every helper and sub-walk is push/pop balanced).
// allowRows: true for a top-level def (rows[] optional), false
// for a sub (rows[] forbidden).

bool parseDef(lua_State* L, int idx, MiscItemDef& def,
              const std::string& where, bool allowRows,
              std::string* err) {
    if (!lua_istable(L, idx)) {
        *err = where + ": not a table";
        return false;
    }
    if (!checkAllowedKeys(L, idx, allowRows ? kDefKeys : kSubKeys,
                          where, err)) return false;

    if (!getStr(L, idx, "key", &def.key, err)) return false;
    if (!getStr(L, idx, "name", &def.name, err)) return false;

    // ---- rows[] - optional at top level (intro and eyes are
    // rowless section pseudo-items), FORBIDDEN inside a sub.
    lua_getfield(L, idx, "rows");         // array (or nil) on top
    if (allowRows) {
        if (!lua_isnoneornil(L, -1)) {
            if (!lua_istable(L, -1)) {
                *err = where + ": rows is not a table";
                lua_pop(L, 1);
                return false;
            }
            const int n = (int)lua_rawlen(L, -1);
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);    // row on top
                if (!lua_istable(L, -1)) {
                    *err = where + ": rows[" + std::to_string(i)
                           + "] is not a table";
                    lua_pop(L, 1);
                    return false;
                }
                if (!checkAllowedKeys(L, -1, kRowKeys,
                                      where + " rows", err)) return false;
                MiscItemRow r;
                long long xp = 0, xpHi = 0, gp = 0, gpHi = 0;
                if (!getStr(L, -1, "name", &r.name, err) ||
                    !getStr(L, -1, "set", &r.set, err) ||
                    !getIntPair(L, -1, "band", &r.bandLo, &r.bandHi, err) ||
                    !getIntPair(L, -1, "qty", &r.qtyLo, &r.qtyHi, err) ||
                    !getInt(L, -1, "xp", &xp, err) ||
                    !getInt(L, -1, "xp_hi", &xpHi, err) ||
                    !getInt(L, -1, "gp", &gp, err) ||
                    !getInt(L, -1, "gp_hi", &gpHi, err)) return false;
                r.xp = (int)xp; r.xpHi = (int)xpHi;
                r.gp = (int)gp; r.gpHi = (int)gpHi;
                def.rows.push_back(r);
                lua_pop(L, 1);            // row
            }
        }
    } else if (!lua_isnoneornil(L, -1)) {
        *err = where + ": a sub must not carry rows[]";
        lua_pop(L, 1);
        return false;
    }
    lua_pop(L, 1);                        // rows array (or the nil)

    // ---- sources[] ----
    lua_getfield(L, idx, "sources");
    if (!lua_istable(L, -1)) {
        *err = where + ": missing sources[]";
        lua_pop(L, 1);
        return false;
    }
    const int nsrc = (int)lua_rawlen(L, -1);
    for (int i = 1; i <= nsrc; ++i) {
        lua_rawgeti(L, -1, i);            // source on top
        if (!lua_istable(L, -1)) {
            *err = where + ": sources[" + std::to_string(i)
                   + "] is not a table";
            lua_pop(L, 1);
            return false;
        }
        if (!checkAllowedKeys(L, -1, kSourceKeys,
                              where + " sources", err)) return false;
        long long part = 0, round = 0;
        if (!getInt(L, -1, "part", &part, err) ||
            !getInt(L, -1, "round", &round, err)) return false;
        def.sources.push_back({(int)part, (int)round});
        lua_pop(L, 1);                   // source
    }
    lua_pop(L, 1);                       // sources array

    // ---- pins[] ----
    lua_getfield(L, idx, "pins");
    if (!lua_istable(L, -1)) {
        *err = where + ": missing pins[]";
        lua_pop(L, 1);
        return false;
    }
    const int npin = (int)lua_rawlen(L, -1);
    for (int i = 1; i <= npin; ++i) {
        lua_rawgeti(L, -1, i);           // pin on top
        if (!lua_istable(L, -1)) {
            *err = where + ": pins[" + std::to_string(i)
                   + "] is not a table";
            lua_pop(L, 1);
            return false;
        }
        if (!checkAllowedKeys(L, -1, kPinKeys,
                              where + " pins", err)) return false;
        MiscItemPin p;
        if (!getStr(L, -1, "name", &p.name, err) ||
            !checkOptionalString(L, -1, "comment", err)) return false;
        long long v = 0;
        if (!getInt(L, -1, "value", &v, err)) return false;
        p.value = v;
        def.pins.push_back(p);
        lua_pop(L, 1);                  // pin
    }
    lua_pop(L, 1);                      // pins array

    // ---- tables[] ----
    lua_getfield(L, idx, "tables");
    if (!lua_istable(L, -1)) {
        *err = where + ": missing tables[]";
        lua_pop(L, 1);
        return false;
    }
    const int ntab = (int)lua_rawlen(L, -1);
    for (int i = 1; i <= ntab; ++i) {
        lua_rawgeti(L, -1, i);          // table entry on top
        if (!lua_istable(L, -1)) {
            *err = where + ": tables[" + std::to_string(i)
                   + "] is not a table";
            lua_pop(L, 1);
            return false;
        }
        if (!checkAllowedKeys(L, -1, kTableKeys,
                              where + " tables", err)) return false;
        MiscItemTable t;
        if (!getStr(L, -1, "name", &t.name, err) ||
            !checkOptionalString(L, -1, "comment", err)) return false;
        // clamp_hi - optional integer.
        lua_getfield(L, -1, "clamp_hi");
        if (!lua_isnoneornil(L, -1)) {
            if (!lua_isinteger(L, -1)) {
                *err = where + ": tables[" + std::to_string(i)
                       + "].clamp_hi is not an integer";
                lua_pop(L, 1);
                return false;
            }
            t.clampHi = (int)lua_tointeger(L, -1);
            t.hasClamp = true;
        }
        lua_pop(L, 1);                  // clamp_hi
        // values[] - required, integers.
        lua_getfield(L, -1, "values");  // values on top
        if (!lua_istable(L, -1)) {
            *err = where + ": tables[" + std::to_string(i)
                   + "].values is not a table";
            lua_pop(L, 1);
            return false;
        }
        const int nval = (int)lua_rawlen(L, -1);
        for (int j = 1; j <= nval; ++j) {
            lua_rawgeti(L, -1, j);      // value on top
            if (!lua_isinteger(L, -1)) {
                *err = where + ": tables[" + std::to_string(i)
                       + "].values[" + std::to_string(j)
                       + "] is not an integer";
                lua_pop(L, 1);
                return false;
            }
            t.values.push_back(lua_tointeger(L, -1));
            lua_pop(L, 1);              // value
        }
        lua_pop(L, 1);                  // values
        def.tables.push_back(t);
        lua_pop(L, 1);                  // table entry
    }
    lua_pop(L, 1);                      // tables array

    // ---- subs[] - optional, nested defs without rows ----
    lua_getfield(L, idx, "subs");
    if (!lua_isnoneornil(L, -1)) {
        if (!lua_istable(L, -1)) {
            *err = where + ": subs is not a table";
            lua_pop(L, 1);
            return false;
        }
        const int nsub = (int)lua_rawlen(L, -1);
        for (int i = 1; i <= nsub; ++i) {
            lua_rawgeti(L, -1, i);      // sub on top
            def.subs.push_back(MiscItemDef());
            if (!parseDef(L, lua_gettop(L), def.subs.back(),
                          where + " subs[" + std::to_string(i) + "]",
                          false, err)) return false;
            lua_pop(L, 1);              // sub
        }
        lua_pop(L, 1);                  // subs array
    } else {
        lua_pop(L, 1);                  // the nil
    }

    return true;
}

}  // namespace

// ----------------------------------------------------------------------------
// File load (strict; see header).
// ----------------------------------------------------------------------------
bool MiscItemRegistry::loadFile(const std::string& path,
                                const std::string& key) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);   // registry files may use string concat in comments

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

    MiscItemDef def;
    std::string err;
    if (!parseDef(L, lua_gettop(L), def, key, true, &err)) {
        m_errors.push_back(key + ": " + err);
        lua_close(L);
        return false;
    }
    if (def.key != key) {
        m_errors.push_back(key + ": def key '" + def.key
                           + "' does not match file stem");
        lua_close(L);
        return false;
    }
    if (m_defs.count(def.key)) {
        m_errors.push_back(key + ": duplicate def key");
        lua_close(L);
        return false;
    }
    m_defs[def.key] = def;
    lua_close(L);
    return true;
}

// ----------------------------------------------------------------------------
// Directory load: platform-scoped, the MonsterRegistry shape.
// ----------------------------------------------------------------------------
#ifdef _WIN32
#include <windows.h>

int MiscItemRegistry::loadDirectory(const std::string& dirPath) {
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
        // R74: the 3-char-extension quirk - guard exactly like POSIX.
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

int MiscItemRegistry::loadDirectory(const std::string& dirPath) {
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

const MiscItemDef* MiscItemRegistry::find(const std::string& key) const {
    auto it = m_defs.find(key);
    return it == m_defs.end() ? nullptr : &it->second;
}

}  // namespace items
