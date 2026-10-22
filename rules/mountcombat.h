// =========================================================================================
// Adnd1 - rules/mountcombat.h
// THE MOUNTED-COMBAT ENGINE SITE - the R403 charge lands: the mount actor,
// the mounted resolution, and the charge closed
// census 698 -> 699.
//
// The last ungated deferred item: the R403 mount layer consolidated six
// feeder seams and left the charge open because the engine had no mount
// actor. The site lands through the R774/R775 file-patch seam as five
// spec-declared patches: the Character mount field in game/party.h (0 =
// afoot, the v1-save default), the beginCombat mounted read in
// game/state_combat.cpp (the first living members riding report the company
// mounted - the combat open prints the riders), the rules/mountlayer.h
// contract flip (ONE span patch: the site exists, the charge closed), and the
// regtest.cpp R403 span flip (one byte-exact block carrying both conditions -
// the audit now fails if the site goes missing or the charge reopens). The
// state_combat TU is in the preflight build, so the site is compile-gated
// like every audit block. The mount field is a seam, not a save line: nothing
// writes mountKind yet (a later round may carry the saddle acquisition and
// the save line).
//
// Zero book pages: the provenance is the engine site (the R403 seam closing
// against its already-landed feeders).
//
namespace rules {

// ---- the mount site (the R403 charge) ----

// The R403 mount layer - the six feeder seams and the layer contract the site
// charges.
inline int dnoMountLayerRound()
    { return 403; }

// The site round: the mount actor lands, the mounted resolution opens, the
// charge closes.
inline int dnoMountSiteRound()
    { return 776; }

// The feeders stay pinned in their own headers (R123, R170, R189, R321, R328,
// R356); the site reads the layer, it does not re-pin them.
inline int dnoMountedFeederSeams()
    { return 6; }

// The mount actor site: the Character carries the mount field (0 = afoot, the
// v1-save default).
inline bool dnoCharacterCarriesMount()
    { return true; }

// The mounted resolution seam: beginCombat counts the living riders and
// prints them at the combat open.
inline bool dnoCombatOpenReadsMount()
    { return true; }

// The mount layer charge closes with the site: the layer site-exists bool
// flips true, the charge-open bool flips false.
inline bool dnoChargeClosedWithSite()
    { return true; }

// The R403 audit conditions flip with the site - the audit fails if the site
// goes missing or the charge reopens.
inline bool dnoR403AuditFollowsSite()
    { return true; }

}   // namespace rules
