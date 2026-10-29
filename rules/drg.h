// =========================================================================================
// Adnd1 - rules/drg.h
// The Dragon small variants - the combined issue-1 round: Gold's Languages
// doctrine (folios 9-10), Smith's Eldar variants (folio 30), and the Bulette
// lore pin (folio 19)
// census 810 -> 811.
//
// Pinned from The Dragon Vol. 1 No. 1 (June 1976): folios 9-10, Lee Gold's
// Languages; folio 30, Larry Smith's The Three Kindreds of the Eldar; folio
// 19, Creature Features - the Bulette, the original Landshark appearance,
// pinned as LORE against the existing MM2 def
// monsters/monsters/b/bulette.lua, never a competing def. The voice rides
// extract/dragon/001/. OD&D-era ink converted per the walk doctrine: the pin
// IS the conversion, noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Bulette pins are lore/provenance only - the MM2 def itself is untouched and
// holds the stem; the Eldar multipliers ride as the 150-percent 1e conversion
// of x1.5; the language doctrine is Gold's prose with its one printed number
// and its anecdote-grade example.
//
namespace rules {

// ---- the language doctrine (Gold, folios 9-10) ----

// the Gold Common tongue doctrine - most humans know Common, and some (20
// percent) other creatures and monsters know it (folios 9-10)
inline int drgCommonPct()
    { return 20; }

// most humans also speak a personal native tongue alongside Common - a
// current, sub-species, legendary or geographic tongue (folio 10)
inline bool drgHumansPersonalTongue()
    { return true; }

// dungeon-dwelling humans are apt to think in their personal tongues rather
// than in Common - the telepathic-eavesdropper point (folio 10)
inline bool drgPersonalTongueThinking()
    { return true; }

// mutual intelligibility between related tongues is adjudicated by percentage
// - the Cavish/Morloch precedent (folio 10)
inline bool drgMutualByPct()
    { return true; }

// the mutual-comprehensibility example - the Caveman Cleric's Cavish read 60
// percent mutually comprehensible with the Morlochs (folio 10)
inline int drgMutualPctExample()
    { return 60; }

// ---- the Eldar variants (Smith, folio 30) ----

// the Noldor elf has no level restriction - a variant against the 1e elf
// level caps (folio 30)
inline bool drgNoldorNoLevelCap()
    { return true; }

// the Noldor elf spell-range multiplier - all ranges x1.5, converted to the
// 150-percent 1e form (folio 30)
inline int drgNoldorRangePct()
    { return 150; }

// the Noldor elf spell-effect multiplier - all effects x1.5, the 150-percent
// conversion (folio 30)
inline int drgNoldorEffectPct()
    { return 150; }

// due to Blackmoor, all elves are to be considered immune to any and all
// sickness and disease (folio 30)
inline bool drgElfDiseaseImmune()
    { return true; }

// ---- the Bulette lore (folio 19) ----

// the Bulette's semi-vulnerable spots - only two: the eyes and the underside
// of the hinged back portion (folio 19)
inline int drgBulWeakSpots()
    { return 2; }

// the Bulette eyes armor class - very small against the overall bulk (folio
// 19)
inline int drgBulEyeAc()
    { return 4; }

// the Bulette underside armor class - exposed only when the crest is raised,
// about a foot and a half square (folio 19)
inline int drgBulUndersideAc()
    { return 6; }

// the Bulette is NEVER found underground (folio 19)
inline bool drgBulNeverUnderground()
    { return true; }

// the smallest Bulettes ever seen are of the six-die variety; no young have
// ever been sighted (folio 19)
inline int drgBulSmallestDice()
    { return 6; }

// the scales behind the Bulette's head are highly prized as shields; the
// teeth are said to be extremely valuable (folio 19)
inline bool drgBulScalesAsShields()
    { return true; }

// the Bulette is very rare; only mated pairs, if such exist, share the same
// territory (folio 19)
inline bool drgBulPairsTerritorial()
    { return true; }

}   // namespace rules
