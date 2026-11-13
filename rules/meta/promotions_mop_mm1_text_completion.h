// =========================================================================================
// Adnd1 - rules/meta/promotions_mop_mm1_text_completion.h
// The promotions mop round two - the MM1 text completion, 136 of the 138
// text-deficient defs filled from the @-record source
// census 929 -> 930.
//
// The promotions mop round two - the MM1 text completion, the naive-era
// data-quality pass part one (the structural half). The MM1 census at HEAD:
// 408 defs, 270 carrying text, 138 text-deficient - the generator dropped the
// prose for every family member, every variant and 25 family carriers. THE
// DERIVATION IS PURELY MECHANICAL from tools/reports/monsters.md, the merged @-record
// source (the single XP and prose authority, the v4 canvas lineage): 25
// carrier defs regain their own text_family prose, 61 family-member defs gain
// their family text_family prose (the print carries the shared description on
// each family entry), 50 variant defs (49 variant-of-a-texted-record plus one
// variant-of-a-member) gain their base or family prose. Every inserted byte
// derives from the source blocks verbatim - no new print ink, no
// adjudication, paragraphs as backslash-n escapes and quotes escaped per the
// landed convention, non-ASCII riding raw exactly as the 270 texted defs
// carry it (seven of the 136 carry the U+FFFD replacement glyph, the
// naive-extraction artifact - flagged as suspects for the collation half of
// the pass). TWO DEFS EXCLUDED, the only MM1 records with no prose anywhere
// in the source: the Copper Dragon (p. 32) and the Monoclonius (p. 24) - the
// extraction lost their text entirely (the Roc and Gas Spore precedent -
// those stat blocks were recovered by user transcription from the print);
// their text awaits the print-voice collation rounds, the second half of the
// data-quality pass. After this round the MM1 text census reads 406 of 408;
// the battery line stays loaded 1338, errors 0 (the R1006 repair holds); the
// registry grows no new files.
//
namespace rules {

// ---- the mop frame ----

// the promotions mop round two - the MM1 text completion
inline int pm2Round()
    { return 1007; }

// the text-deficient MM1 defs completed this round - of the 138 the census
// found, the 136 with derivable prose
inline int pm2DefsCompleted()
    { return 136; }

// the excluded defs - the Copper Dragon and the Monoclonius, the only MM1
// records with no prose anywhere in the @-record source, the extraction
// having lost their text (the Roc and Gas Spore precedent); they await the
// print-voice collation rounds
inline int pm2DefsExcluded()
    { return 2; }

// ---- the derivation classes ----

// the family carriers that regain their own text_family prose - the generator
// had dropped it even from the carrier defs
inline int pm2CarrierDefs()
    { return 25; }

// the family-member defs gaining their family text_family prose - the print
// carries the shared description on each family entry
inline int pm2FamilyMemberDefs()
    { return 61; }

// the variant defs gaining their base or family prose - 49 variants of texted
// records plus one variant of a family member
inline int pm2VariantDefs()
    { return 50; }

// ---- the MM1 text census ----

// the MM1 def census - four hundred eight defs, the registry floor component
// unchanged by this round
inline int pm2Mm1DefsTotal()
    { return 408; }

// the MM1 text census after this round - four hundred six of 408 carrying
// text, 270 before the repair plus the 136 completed here
inline int pm2Mm1TextedAfter()
    { return 406; }

// ---- the repair doctrines ----

// every inserted byte derives verbatim from tools/reports/monsters.md - no new print
// ink, no adjudication, paragraphs escaped and quotes escaped per the landed
// convention
inline bool pm2CompletionMechanical()
    { return true; }

// all 136 repaired defs parse back - the text unescapes to the source prose
// exactly and the whole-tree lexer scan stays 1338 of 1338 clean
inline bool pm2RoundTripGreen()
    { return true; }

// the collation half of the data-quality pass rides ahead - the Copper Dragon
// and Monoclonius texts, the seven U+FFFD suspect glyphs, and the print-voice
// verification of the naive-era prose all await the collation rounds
inline bool pm2CollationHalfRides()
    { return true; }

}   // namespace rules
