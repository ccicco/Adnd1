// =========================================================================================
// Adnd1 - rules/dsgdecay.h
// The DSG STRUCTURAL DECAY, R516: printed p. 43 (pdf 44) - the underground
// environment inflicting relatively swift decay upon wooden structures, the
// typical-location assumption of very humid air, the almost-completely-dry
// areas where wooden objects decay at a mere 2 or 3% of the given rate, the
// 1d6-year rot onset for anything made of wood and kept underground, the
// creosote-or-sealant doubling of the onset period, the 5% chance of collapse
// per multiple of the onset roll that passes with the roll-1 structure at 5%
// per year and a 20-year maximum (100%) and the roll-6 structure lasting as
// much as 120 years, the check whenever any activity puts unusual stress upon
// the structure, and the d100 roll against the percentage chance of collapse
// census 439 -> 440.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~5500-5525) with the pdf Acrobat-Capture layer as the second read (idx 62 =
// printed p. 43) - every number dual-confirmed: the 2 or 3% dry band, the
// 1d6-year rot onset (the djvu garble 146 = 1d6 settled by the Capture read),
// the creosote doubling, the 5%-per-multiple collapse chance with the roll-1
// = 20-year and roll-6 = 120-year worked examples, and the stress check made
// with a d100 roll (the djvu garble 4100 = d100). The Underground Waterways
// section starts the NEXT round per the content-density rule.
//
// No table in this section - the pins are consts and bools only. The 1d6 rot
// onset pins as dice + sides consts per the R508 convention. The collapse
// math stays prose: the 20-year and 120-year worked examples pin as consts
// but the engine multiplies nothing - nothing auto-credits.
//
namespace rules {

// ---- the structural decay opener ----

// the underground environment inflicts relatively swift decay upon wooden
// structures; the effects assume the presence of very humid air, the typical
// underground location.
inline bool dnsHumidAirAssumed()
    { return true; }

// in almost completely dry subterranean areas the wooden decay runs at a mere
// 2 or 3% of the given rate.
inline bool dnsDryAreasMereFractionOfRate()
    { return true; }

// in subterranean areas that are almost completely dry, the decay of wooden
// objects is a mere 2 or 3% of the rate given.
inline int dnsDryRateLowPct()
    { return 2; }

// the high end of the almost-completely-dry decay band: a mere 2 or 3% of the
// typical humid rate (the djvu garble class: 2 or 3% reads clean).
inline int dnsDryRateHighPct()
    { return 3; }

// ---- the rot onset and the sealant ----

// anything made out of wood and kept underground begins to show signs of rot
// after 1d6 years - the dice of the onset roll (the djvu garble 146 = 1d6,
// settled by the Capture read).
inline int dnsRotOnsetYearsDice()
    { return 1; }

// the sides of the 1d6-year rot-onset roll, pinned as dice + sides consts per
// the R508 convention.
inline int dnsRotOnsetYearsSides()
    { return 6; }

// creosote or some other sealing substance doubles the rot-onset period.
inline bool dnsCreosoteOrSealantDoubles()
    { return true; }

// if the wood is soaked in creosote or some other sealing substance, this
// period is doubled.
inline int dnsCreosotePeriodMultiplier()
    { return 2; }

// ---- the collapse chance ladder ----

// the rot creates a 5% chance of collapse for each multiple of the 1d6 onset
// roll that passes.
inline int dnsCollapseChancePerMultiplePct()
    { return 5; }

// the collapse chance accrues per multiple of the 1d6 onset roll that passes
// - the roll sets both the interval and the lifetime.
inline bool dnsCollapseChancePerMultipleOfOnset()
    { return true; }

// if the first roll was a 1, there is a 5% chance of collapse every year, and
// the structure would last a maximum of 20 years (at which time the chance of
// collapse is 100%).
inline int dnsRollOneMaxYears()
    { return 20; }

// if the original roll was a 6, however, the structure might last as much as
// 120 years (6 multiples x the 5% ladder).
inline int dnsRollSixMaxYears()
    { return 120; }

// ---- the stress check ----

// the wooden structure should be checked whenever any activity puts unusual
// stress upon it.
inline bool dnsCheckOnUnusualStress()
    { return true; }

// the check is made with a d100 roll (the djvu garble 4100 = d100, settled by
// the Capture read) against the percentage chance of collapse for the
// structure.
inline bool dnsStressCheckIsD100()
    { return true; }

}   // namespace rules
