// ===========================================================================
// Adnd1 - rules/seams/miscreg.h
// The R1059 misc-magic family registry seam.
//
// content/tables/miscmagic/ (R1059)
// via items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom) and the rows
// readers (the R1051 dzRows idiom). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in the weapons
// family headers keeps its signature, clamp
// and branch; only the array read moves
// behind the registry. The R1058 weaponsreg
// precedent, seated at rules/seams.
// DO NOT hand-edit: tools/r1059_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the misc-magic family registry seam ----

inline items::MiscItemRegistry&
mReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "miscmagic");
    }
    return reg;
}

// the name rows of one def
inline const std::vector<
    items::MiscItemRow>& mRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = mReg().find(key);
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
// (null when absent or empty -
// the MiscItemTable values are
// long long, NOT long: the
// R1058 preflight lesson)
inline const std::vector<
    long long>* mTable(
        const char* key,
        const char* tag) {
    static std::map<std::string,
        std::vector<
            long long>>
        cache;
    std::string ck =
        std::string(key)
        + "/" + tag;
    auto it = cache.find(ck);
    if (it == cache.end()) {
        const items::
            MiscItemDef*
            d = mReg().find(key);
        const std::vector<
            long long>* v = nullptr;
        if (d) {
            for (const auto&
                     t : d->tables)
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
