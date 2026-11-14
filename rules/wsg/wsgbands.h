// ============================================================================
// Adnd1 - rules/wsg/wsgbands.h
// The R1048 WSG band-table seam: the small
// printed roll-band dispatches (wsgforage.h
// wfgInedBandFor, wsgweathx.h
// wwyCycloneDriftFor) ride
// items::MiscItemRegistry from
// content/tables/wsg/ (def keys
// wsg_inedible_bands, wsg_cyclone_drift_bands;
// rows name = the band tag, band = the roll
// band, gp = the band index). One registry,
// one loader, shared by both headers (the
// R1032-R1044 header-only idiom; every
// accessor signature is unchanged - the
// r463/r494 audits pin them).
// ============================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

inline items::MiscItemRegistry& wsgBandReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/wsg");
    }
    return reg;
}

inline const std::vector<items::MiscItemRow>&
wsgBandRows(const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d =
            wsgBandReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}

}  // namespace rules
