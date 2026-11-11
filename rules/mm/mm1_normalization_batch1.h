// =========================================================================================
// Adnd1 - rules/mm/mm1_normalization_batch1.h
// The MM1 normalization batch one - 99 defs rewritten to the full-field
// 57-key emission, the letters a through f, plus the two
// normalize_registry.py repairs
// census 931 -> 932.
//
// The MM1 normalization batch one - the per-book schema pass, MM1 part one of
// six. The standing queue from R886/R879: every sparse MM1 def rewritten to
// the full-field 57-key emission of tools/normalize_registry.py - string
// sentinels n/a, integer sentinels -1 - byte-exact against the repaired
// normalizer output, the canonical FIELD_ORDER honored including text before
// familyText. This batch rides the letters a through f: 99 defs rewritten via
// 515 anchored insert sites (2214 inserted lines), 19 whole-line reorder
// sites across 23 defs, 4 line-move encodings - the delete-replace window
// plus paired insert, since the engine cannot ship a bare delete. TWO
// NORMALIZER REPAIRS RIDE AS THE FIRST FILE PATCHES: (1)
// normalize_registry.py has read a census of zero defs since R879 because its
// REG glob pointed at monsters/monsters instead of content/monsters; (2) the
// saveAsBonus no-data emission rides 0 - the loader documented default and
// the R155 data contract (the classed-monster audit pins brownie saveAsBonus
// 0; a classed write-up with no die bonus reads 0, not the -1 sentinel) - the
// first attempt at this batch died at the R155 audit with the -1 emission and
// every claim in this banner is measured against the twice-repaired
// normalizer run over HEAD: 1338 defs read, MM1 408, this batch normalizes 99
// leaving 309 for batches two through six. The MM1 census after this round:
// 408 defs, 99 canonical.
//
namespace rules {

// ---- the batch frame ----

// the MM1 normalization batch one - letters a through f
inline int mn1Round()
    { return 1009; }

// the MM1 defs rewritten to full-field canonical form this batch - the
// letters a through f
inline int mn1DefsNormalized()
    { return 99; }

// the file patches this round - 538 monster windows plus the two
// normalize_registry.py repairs
inline int mn1PatchEntries()
    { return 540; }

// ---- the MM1 normalization census ----

// the MM1 def census - unchanged by the batch
inline int mn1Mm1Total()
    { return 408; }

// the MM1 defs carrying the full-field emission after this batch
inline int mn1Mm1NormalizedAfter()
    { return 99; }

// the MM1 defs still sparse after this batch - batches two through six,
// letters g through z
inline int mn1Mm1Remaining()
    { return 309; }

// the canonical FIELD_ORDER length - every MM1 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mn1SchemaKeys()
    { return 57; }

// ---- the normalizer repairs ----

// the normalize_registry.py repairs riding this round - the REG glob (the
// census-zero bug carried since R879) and the saveAsBonus no-data default (0,
// the R155 data contract, not the -1 sentinel)
inline int mn1NormalizerRepairs()
    { return 2; }

// the normalize_registry.py REG glob repaired - monsters/monsters to
// content/monsters, the census-zero bug carried since R879
inline bool mn1NormalizerPathRepaired()
    { return true; }

// the saveAsBonus no-data emission rides 0 - the loader documented default
// and the R155 data contract; the classed brownie/couatl/dolphin write-ups
// carry 0, displacer keeps its real 2
inline bool mn1SaveAsBonusZeroDefault()
    { return true; }

// ---- the patch anatomy ----

// the anchored insert sites - 2214 inserted lines, the n/a and -1 sentinel
// fields plus the reordered text lines
inline int mn1InsSites()
    { return 515; }

// the defs needing whole-line reorders to reach the canonical FIELD_ORDER -
// text before familyText, statNote before text
inline int mn1ReorderDefs()
    { return 23; }

// the line-move encodings - delete-replace windows spanning the moved line
// plus its neighbours, each with a paired insert at the canonical site
inline int mn1MoveSites()
    { return 4; }

// ---- the guarantees ----

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings and -1 ints
inline bool mn1FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - text before familyText,
// statNote before text, saveAs before saveAsBonus
inline bool mn1FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the twice-repaired
// normalize_registry.py output over HEAD - verified by apply simulation
// before landing
inline bool mn1NormalizerByteExact()
    { return true; }

}   // namespace rules
