// =========================================================================================
// Adnd1 - rules/meta/promotions_mop_mm1_collation.h
// The promotions mop round three - the MM1 collation half, 222 glyph-bearing
// defs repaired and the two lost texts recovered from the print voice
// census 930 -> 931.
//
// The promotions mop round three - the MM1 collation half, the naive-era
// data-quality pass part two. The MM1 census at HEAD: 408 defs, 406 carrying
// text, the Copper Dragon and the Monoclonius the two text-deficient
// exclusions riding from R1007. THE PROVENANCE IS THE SINGLE READABLE PRINT
// VOICE - the archive.org adn-d-1e-monster-manual item, the 1977 print djvu
// scan (the second print scan, the 1979 advanceddungeonsm00gyga, is
// lending-restricted - the R923 single-voice precedent; every reading below
// cites that one voice). TWO TEXTS RECOVERED: the Copper Dragon (p. 32, three
// paragraphs) and the Monoclonius (p. 24, one paragraph), every OCR garble
// adjudicated case by case (drogon to dragon, o claw to a claw, one-holf to
// one-half, three2nd to three 2nd, ot each to at each, the djvu half glyph
// rendered % or Yz read as the half glyph). THE GLYPH REPAIR across 222 defs,
// the mangled-glyph half of the collation: 731 0x14 PDF control codes
// restored to the raw print em-dash (one unspaced - the gold dragon
// weapons-fire; three stat-field glyphs normalized to the landed convention
// instead: the mold hitDice to Nil, the war dog noAppearing to n/a), 77
// U+FFFD replacement glyphs adjudicated against the voice (10 degrees - the
// beholder eye arcs 90/180/270/360, the frog 45-degree jumps; 67 halves -
// sizes, hit dice, the half-inch breath cones and streams). After this round
// the MM1 text census reads 408 of 408 - the naive-era data-quality pass
// complete; the battery line stays loaded 1338, errors 0; the registry grows
// no new files.
//
namespace rules {

// ---- the mop frame ----

// the promotions mop round three - the MM1 collation half
inline int pm3Round()
    { return 1008; }

// the glyph-bearing MM1 defs repaired this round - 197 carrying the 0x14
// control code, 53 carrying the U+FFFD replacement glyph, 28 carrying both
inline int pm3DefsRepaired()
    { return 222; }

// the file_patch windows - 442 glyph repairs plus the two text completions,
// every window simulated green and idempotent by to-presence
inline int pm3PatchEntries()
    { return 444; }

// ---- the repair classes ----

// the 0x14 control codes restored to the raw print em-dash - the PDF
// extraction artifact across the naive-era MM1 texts
inline int pm3EmdashFixes()
    { return 731; }

// the U+FFFD replacement glyphs adjudicated against the print voice - 10
// degree readings, 67 half-glyph readings
inline int pm3UfffdFixes()
    { return 77; }

// the three stat-field glyphs normalized to the landed convention rather than
// the em-dash - the mold hitDice to Nil, the war dog noAppearing to n/a
inline int pm3StatFieldFixes()
    { return 3; }

// ---- the MM1 text census ----

// the MM1 def census at HEAD
inline int pm3Mm1DefsTotal()
    { return 408; }

// the MM1 text census after this round - every def carries its text, the
// naive-era data-quality pass complete
inline int pm3Mm1TextedAfter()
    { return 408; }

// the two lost MM1 texts recovered from the print voice - the Copper Dragon
// (p. 32, three paragraphs) and the Monoclonius (p. 24, one paragraph)
inline int pm3TextsRecovered()
    { return 2; }

// ---- the repair doctrines ----

// the round rides the single readable print voice - the archive.org 1977 djvu
// scan, the 1979 scan lending-restricted, the R923 single-voice precedent
inline bool pm3SingleVoiceProvenance()
    { return true; }

// all 222 repaired defs parse back - the lexer scan stays 1338 of 1338 clean
// and every window is idempotent by to-presence
inline bool pm3GlyphRoundTripGreen()
    { return true; }

// the MM1 text census reads 408 of 408 - the structural half (R1007) and the
// collation half (this round) both landed
inline bool pm3TextCensusComplete()
    { return true; }

}   // namespace rules
