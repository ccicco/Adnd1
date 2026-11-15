// ===========================================================================
// Adnd1 - rules/seams/siegefirereg.h
// The R1061 siegefire-family registry seam.
//
// content/tables/siegefire/ (R1061)
// via items::MiscItemRegistry: the R1058
// weapons-family wTable idiom, rowless
// (the siegefire family is flat int
// columns only, no rows readers). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in
// rules/dmg/siegefire.h keeps its
// signature, clamp and comment; only the
// array read moves behind the registry.
// The R1058 weaponsreg / R1059 miscreg
// precedent, seated at rules/seams.
// DO NOT hand-edit: tools/r1061_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the siegefire family registry seam ----

inline items::MiscItemRegistry&
sfReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "siegefire");
    }
    return reg;
}

// one named int table of one def
// (null when absent or empty -
// the R1058 long long note rides
// here unchanged)
inline const std::vector<
    long long>* sfTable(
        const char* key,
        const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    std::string ck =
        std::string(key)
        + "/" + tag;
    auto it = cache.find(ck);
    if (it == cache.end()) {
        const items::
            MiscItemDef* d =
            sfReg().find(key);
        const std::vector<
            long long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables)
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
        }
        it = cache.emplace(
            ck, v ? *v
                  : std::vector<
                        long long>()
            ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

}   // namespace rules

