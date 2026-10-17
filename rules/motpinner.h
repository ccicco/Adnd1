// =========================================================================================
// Adnd1 - rules/motpinner.h
// THE MotP INNER PLANES IN GENERAL - printed pp. 22-31, the doctrine round
// for the inner half of the book: the sphere arrangement, the hostility, the
// reaching, the survival, the local gravity, the guides, the decay rule, and
// the spell matrix - the plane rounds that follow pin against this frame.
// census 490 -> 491.
//
// verified against printed pp. 22-31 of the uploaded motp.pdf OCR; the
// school-effects matrix summarized in the audit comment with its per-school
// pins to land in the plane rounds where the text gives plane-by-plane
// particulars.
//
// the gap census after this round: 21 closed, 69 open - the doctrine and the
// decay table are the frame; every plane round ahead flips its own box on its
// own pins.
//
namespace rules {

// ---- the inner planes doctrine pins ----

// the six major elemental planes (Fire, Earth, Air, Water, Positive Energy,
// Negative Energy) plus the twelve minor (four para-, eight quasi-), arranged
// on a sphere with the Prime and Ethereal inside.
inline int dcvInnerMajorPlaneCount()
    { return 6; }

// the twelve minor planes: the para- (Smoke, Ice, Ooze, Magma) between the
// elementals, the quasi- (Lightning, Steam, Radiance, Minerals, Vacuum, Salt,
// Ash, Dust) between the elementals and the energy planes.
inline int dcvInnerMinorPlaneCount()
    { return 12; }

// except on the plane of elemental Air, normal breathing is impossible in the
// inner planes: the unprotected traveler suffocates or drowns in 2d4 rounds
// (this pin, the die side; or use the DSG holding-breath rules).
inline int dcvBreathlessDieSides()
    { return 4; }

// a chosen "down" without supporting mass drops the traveler 1,000 feet per
// round; reverse the direction to slow, reverse one full round then negate to
// stop; momentum is conserved and a strike deals falling damage (1d6 per 10
// feet, 20d6 max).
inline int dcvFallRateFeet()
    { return 1000; }

// guided travel times: 10-100 hours to a border with another inner plane,
// 100-1,000 hours to a specific location within a plane; a polymorphed
// self-guide doubles all times (not truly a native).
inline int dcvGuideBorderHours()
    { return 100; }

// the elemental guide inducement rate: 100 gp worth per hour of service -
// gems for Earth, rare wood for Fire, perfume for Air, scents and potions for
// Water; genies take 100 gp or magic, and fight alongside for magic.
inline int dcvGuideInducementGP()
    { return 100; }

// human travelers are almost always in groups (use the p. 16 chart for number
// and levels); a lone human traveler in the inner planes is never less than
// 20th level.
inline int dcvHumanLoneMinLevel()
    { return 20; }

// the inborn hostility: all eighteen inner planes are hostile to life not of
// the inner planes, Prime Material life in particular - wander only with
// specific protection or stay in the Border Ethereal.
inline bool dcvInbornHostility()
    { return true; }

// inner-plane natives see into the Ethereal from their home plane, attack
// ethereal beings, and can enter the Ethereal (only from home) to pursue -
// but cannot reach the Prime without aid or a free-standing gate.
inline bool dcvNativesSeeBorderEthereal()
    { return true; }

// the subjective-time reversal: one true day equals two subjective days in
// the inner planes - the traveler tires twice as quickly but rests and learns
// spells twice per elemental day; healing and research run faster.
inline bool dcvTimeFasterInner()
    { return true; }

// gravity is determined by the intelligent beings in the area: any sentient
// being chooses his own "down"; undecided means weightless; hierophants of
// sufficient level are treated as natives.
inline bool dcvLocalGravity()
    { return true; }

// ultravision does not function in the inner planes (no reflected ultraviolet
// radiation); vision limits vary by plane - para-planes take the more
// restrictive neighbor, quasi-planes take the adjoining elemental plane.
inline bool dcvUltravisionFails()
    { return true; }

// the unaided traveler moves at normal rate but at the end of every turn the
// DM rolls a random direction - without an objective in sight or an elemental
// guide, the infinite plane defeats navigation.
inline bool dcvUnguidedRandomDirection()
    { return true; }

// natives cannot be harmed by attacks of their own elemental type while in
// the inner planes - a fireball against salamanders inspires derision;
// Negative natives shrug energy drain.
inline bool dcvElementalImmunityHome()
    { return true; }

}   // namespace rules
