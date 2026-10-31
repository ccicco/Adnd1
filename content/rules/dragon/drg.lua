-- drg: promoted from tools/spec_r888.json (the The Dragon small variants - the combined issue-1 round: Gold's Languages doctrine (folios 9-10), Smith's Eldar variants (folio 30), and the Bulette lore pin (folio 19));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 888,
  "prefix" = "drg",
  "banner" = {
      "title" = "The Dragon small variants - the combined issue-1 round: Gold's Languages doctrine (folios 9-10), Smith's Eldar variants (folio 30), and the Bulette lore pin (folio 19)",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 1 (June 1976): folios 9-10, Lee Gold's Languages; folio 30, Larry Smith's The Three Kindreds of the Eldar; folio 19, Creature Features - the Bulette, the original Landshark appearance, pinned as LORE against the existing MM2 def monsters/monsters/b/bulette.lua, never a competing def. The voice rides extract/dragon/001/. OD&D-era ink converted per the walk doctrine: the pin IS the conversion, noted, never silent.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. The Bulette pins are lore/provenance only - the MM2 def itself is untouched and holds the stem; the Eldar multipliers ride as the 150-percent 1e conversion of x1.5; the language doctrine is Gold's prose with its one printed number and its anecdote-grade example.",
    },
  "consts" = { {
      "name" = "drgCommonPct",
      "value" = 20,
      "comment" = "the Gold Common tongue doctrine - most humans know Common, and some (20 percent) other creatures and monsters know it (folios 9-10)",
    }, {
      "name" = "drgMutualPctExample",
      "value" = 60,
      "comment" = "the mutual-comprehensibility example - the Caveman Cleric's Cavish read 60 percent mutually comprehensible with the Morlochs (folio 10)",
    }, {
      "name" = "drgNoldorRangePct",
      "value" = 150,
      "comment" = "the Noldor elf spell-range multiplier - all ranges x1.5, converted to the 150-percent 1e form (folio 30)",
    }, {
      "name" = "drgNoldorEffectPct",
      "value" = 150,
      "comment" = "the Noldor elf spell-effect multiplier - all effects x1.5, the 150-percent conversion (folio 30)",
    }, {
      "name" = "drgBulWeakSpots",
      "value" = 2,
      "comment" = "the Bulette's semi-vulnerable spots - only two: the eyes and the underside of the hinged back portion (folio 19)",
    }, {
      "name" = "drgBulEyeAc",
      "value" = 4,
      "comment" = "the Bulette eyes armor class - very small against the overall bulk (folio 19)",
    }, {
      "name" = "drgBulUndersideAc",
      "value" = 6,
      "comment" = "the Bulette underside armor class - exposed only when the crest is raised, about a foot and a half square (folio 19)",
    }, {
      "name" = "drgBulSmallestDice",
      "value" = 6,
      "comment" = "the smallest Bulettes ever seen are of the six-die variety; no young have ever been sighted (folio 19)",
    } },
  "bools" = { {
      "name" = "drgHumansPersonalTongue",
      "value" = true,
      "comment" = "most humans also speak a personal native tongue alongside Common - a current, sub-species, legendary or geographic tongue (folio 10)",
    }, {
      "name" = "drgPersonalTongueThinking",
      "value" = true,
      "comment" = "dungeon-dwelling humans are apt to think in their personal tongues rather than in Common - the telepathic-eavesdropper point (folio 10)",
    }, {
      "name" = "drgMutualByPct",
      "value" = true,
      "comment" = "mutual intelligibility between related tongues is adjudicated by percentage - the Cavish/Morloch precedent (folio 10)",
    }, {
      "name" = "drgNoldorNoLevelCap",
      "value" = true,
      "comment" = "the Noldor elf has no level restriction - a variant against the 1e elf level caps (folio 30)",
    }, {
      "name" = "drgElfDiseaseImmune",
      "value" = true,
      "comment" = "due to Blackmoor, all elves are to be considered immune to any and all sickness and disease (folio 30)",
    }, {
      "name" = "drgBulNeverUnderground",
      "value" = true,
      "comment" = "the Bulette is NEVER found underground (folio 19)",
    }, {
      "name" = "drgBulScalesAsShields",
      "value" = true,
      "comment" = "the scales behind the Bulette's head are highly prized as shields; the teeth are said to be extremely valuable (folio 19)",
    }, {
      "name" = "drgBulPairsTerritorial",
      "value" = true,
      "comment" = "the Bulette is very rare; only mated pairs, if such exist, share the same territory (folio 19)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['drgCommonPct']() != 20",
      "note" = "the Rules' 20 percent - some other creatures and monsters know Common (Gold, folio 9)",
    }, {
      "expr" = "m['drgMutualPctExample']() != 60",
      "note" = "the Morloch encounter - the Cavish read 60 percent mutually comprehensible, enough to learn they were Neutrals and pay the wine tribute (folio 10)",
    }, {
      "expr" = "m['drgHumansPersonalTongue']() != 1 or m['drgPersonalTongueThinking']() != 1",
      "note" = "the personal-tongue doctrine - humans carry one and think in it, the telepathy point (folio 10)",
    }, {
      "expr" = "m['drgMutualByPct']() != 1",
      "note" = "mutual comprehensibility goes by percentage - the Gold precedent (folio 10)",
    }, {
      "expr" = "m['drgNoldorRangePct']() != 150 or m['drgNoldorEffectPct']() != 150",
      "note" = "the Noldor elf - all spell ranges and effects at x1.5, the 150-percent conversion (folio 30)",
    }, {
      "expr" = "6 * m['drgNoldorRangePct']() / 100 != 9",
      "note" = "a 6-inch spell range reads 9 under the Noldor multiplier - the conversion example",
    }, {
      "expr" = "m['drgNoldorNoLevelCap']() != 1 or m['drgElfDiseaseImmune']() != 1",
      "note" = "the Eldar variants - no level restriction, and the Blackmoor-borne disease immunity for all elves (folio 30)",
    }, {
      "expr" = "m['drgBulWeakSpots']() != 2 or m['drgBulEyeAc']() != 4 or m['drgBulUndersideAc']() != 6",
      "note" = "the Bulette's two semi-vulnerable spots - the eyes AC 4, the raised-crest underside AC 6 (folio 19)",
    }, {
      "expr" = "m['drgBulNeverUnderground']() != 1",
      "note" = "NEVER found underground - the Dragon lore doctrine rides against the untouched MM2 def (folio 19)",
    }, {
      "expr" = "m['drgBulSmallestDice']() != 6",
      "note" = "the smallest ever seen are of the six-die variety; no young have ever been sighted (folio 19)",
    }, {
      "expr" = "m['drgBulScalesAsShields']() != 1 or m['drgBulPairsTerritorial']() != 1",
      "note" = "the Bulette provenance - scales prized as shields, teeth valuable, only mated pairs share territory (folio 19)",
    } },
  "audit" = {
      "label" = "R888 Dragon small variants audit",
      "comment" = "THE DRAGON SMALL VARIANTS - the combined issue-1 round, three chains on the variant layer. LANGUAGES (Gold, folios 9-10): the 20-percent Common doctrine, the personal-tongue rules (a native tongue beside Common, thinking in it), and mutual comprehensibility by percentage - the Cavish/Morloch 60-percent encounter is the anecdote-grade example. ELDER (Smith, folio 30): the Noldor elf rides no level restriction, all spell ranges and effects at x1.5 (pinned as the 150-percent 1e conversion), and the Blackmoor-borne doctrine that all elves are immune to any and all sickness and disease - variants against the engine's 1e elf canon (races.h, elf.lua), never core rewrites. THE BULETTE (folio 19): the original Landshark appearance, pinned as LORE and PROVENANCE against the existing MM2 def monsters/monsters/b/bulette.lua - the def is untouched, the stem holds, no competing def ever: the two semi-vulnerable spots (the eyes AC 4, the raised-crest underside AC 6), the never-underground doctrine, the six-die smallest, the scales-as-shields and pairs-territorial lore. HONEST BOUNDARIES: all three chains are OD&D-era variant ink, converted, noted, never silent; Gold's doctrine is prose with one printed number; the Eldar multipliers are the only numeric conversions; the Bulette pins never touch the def's own fields. The Ives gap box flips this round - the dragon report's first flip.",
    },
}
