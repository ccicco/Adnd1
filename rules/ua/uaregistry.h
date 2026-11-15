// ===========================================================================
// Adnd1 - rules/ua/uaregistry.h
// The R1056 UA classes-family registry seam.
//
// content/tables/ua_classes/ via
// items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom) and the rows
// readers (the R1051 dzRows idiom). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in the thirteen
// rules/ua headers keeps its signature,
// clamp and branch; only the array read
// moves behind the registry.
// DO NOT hand-edit: tools/r1056_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the R1056 registry seam ---------------

inline items::MiscItemRegistry&
uaReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "ua_classes");
    }
    return reg;
}

// the name rows of one def
inline const std::vector<
    items::MiscItemRow>& uaRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = uaReg().find(key);
        it = cache.emplace(
            key, d ? d->rows
                   : std::vector<
                        items::
                        MiscItemRow>()
                   ).first;
    }
    return it->second;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* uaTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = uaReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

}  // namespace rules
