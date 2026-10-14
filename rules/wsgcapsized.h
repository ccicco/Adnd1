// =========================================================================================
// Adnd1 - rules/wsgcapsized.h
// The WSG USE OF A CAPSIZED VESSEL, R459: because of the natural buoyancy of
// the materials from which they are made, most vessels can remain afloat just
// beneath the surface of the water even after they are capsized or after they
// have suffered hull damage. However, this is true only of vessels that are
// carrying no passengers and not more than 10% of their listed maximum cargo
// capacity. For example, if characters in a small rowboat that is foundering
// can get out of it and toss overboard all but 200 gp worth of their cargo or
// gear, the craft will sink to slightly beneath the surface of the water and
// remain there. It is then possible for characters to cling to the sides of
// the craft and use it as a flotation device, as long as their weight is
// evenly distributed. A capsized craft will support a number of characters
// equal to twice its normal capacity; that is, up to eight characters can
// cluster around the sides of a large rowboat and use it to keep from going
// under themselves. If this weight limit is exceeded, or if the weight is not
// evenly distributed, the craft will sink too far below the surface to be
// usable in this fashion.
// census 383 -> 384.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 46; the
// user own copy OCR (page 47) cross-checked against the archive djvu word
// layer (Guide_0046) - the prose reads clean two-way; NO eye-reads needed (a
// pure-prose section, no printed grid).
//
namespace rules {

// ---- the buoyancy preconditions ----

// The same eight vessels as Tables 25 and 26: kayak, small canoe, small
// rowboat, coracle, large canoe, large rowboat, small barge and large barge.
inline int wcvVesselCount()
    { return 8; }

// Because of the natural buoyancy of their materials, most vessels can remain
// afloat just beneath the surface even after capsizing or hull damage.
inline bool wcvBuoyantJustBeneathSurface()
    { return true; }

// The flotation holds both for a capsized vessel and for one that has
// suffered hull damage.
inline bool wcvWorksAfterCapsizeOrHullDamage()
    { return true; }

// The flotation trick holds only for vessels carrying not more than 10% of
// their listed maximum cargo capacity.
inline int wcvMaxCargoPercent()
    { return 10; }

// The flotation is true only of vessels carrying no passengers.
inline bool wcvRequiresNoPassengers()
    { return true; }

// The flotation is true only of vessels carrying not more than 10% of their
// listed maximum cargo capacity.
inline bool wcvCargoWithinMaxPercent()
    { return true; }

// The small-rowboat example: the foundering craft remains beneath the surface
// once all but 200 gp worth of cargo or gear is tossed overboard.
inline int wcvExampleRowboatCargoGp()
    { return 200; }

// ---- the flotation support ----

// A capsized craft will support a number of characters equal to twice its
// normal capacity.
inline int wcvSupportMultiplier()
    { return 2; }

// The large-rowboat example: up to eight characters can cluster around the
// sides and use it to keep from going under.
inline int wcvExampleRowboatSupport()
    { return 8; }

// Characters can cling to the sides of the sunken craft and use it as a
// flotation device.
inline bool wcvClingToSidesAsFlotation()
    { return true; }

// The flotation holds only as long as the clinging weight is evenly
// distributed.
inline bool wcvWeightMustBeEven()
    { return true; }

// ---- the sink rules ----

// If the twice-capacity weight limit is exceeded, the craft sinks too far
// below the surface to be usable.
inline bool wcvExcessWeightSinks()
    { return true; }

// If the weight is not evenly distributed, the craft sinks too far below the
// surface to be usable.
inline bool wcvUnevenWeightSinks()
    { return true; }

}   // namespace rules
