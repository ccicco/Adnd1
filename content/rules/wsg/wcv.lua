-- wcv: promoted from tools/spec_r459.json (the The WSG USE OF A CAPSIZED VESSEL, R459: because of the natural buoyancy of the materials from which they are made, most vessels can remain afloat just beneath the surface of the water even after they are capsized or after they have suffered hull damage. However, this is true only of vessels that are carrying no passengers and not more than 10% of their listed maximum cargo capacity. For example, if characters in a small rowboat that is foundering can get out of it and toss overboard all but 200 gp worth of their cargo or gear, the craft will sink to slightly beneath the surface of the water and remain there. It is then possible for characters to cling to the sides of the craft and use it as a flotation device, as long as their weight is evenly distributed. A capsized craft will support a number of characters equal to twice its normal capacity; that is, up to eight characters can cluster around the sides of a large rowboat and use it to keep from going under themselves. If this weight limit is exceeded, or if the weight is not evenly distributed, the craft will sink too far below the surface to be usable in this fashion.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 459,
  "prefix" = "wcv",
  "banner" = {
      "title" = "The WSG USE OF A CAPSIZED VESSEL, R459: because of the natural buoyancy of the materials from which they are made, most vessels can remain afloat just beneath the surface of the water even after they are capsized or after they have suffered hull damage. However, this is true only of vessels that are carrying no passengers and not more than 10% of their listed maximum cargo capacity. For example, if characters in a small rowboat that is foundering can get out of it and toss overboard all but 200 gp worth of their cargo or gear, the craft will sink to slightly beneath the surface of the water and remain there. It is then possible for characters to cling to the sides of the craft and use it as a flotation device, as long as their weight is evenly distributed. A capsized craft will support a number of characters equal to twice its normal capacity; that is, up to eight characters can cluster around the sides of a large rowboat and use it to keep from going under themselves. If this weight limit is exceeded, or if the weight is not evenly distributed, the craft will sink too far below the surface to be usable in this fashion.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 46; the user own copy OCR (page 47) cross-checked against the archive djvu word layer (Guide_0046) - the prose reads clean two-way; NO eye-reads needed (a pure-prose section, no printed grid).",
    },
  "consts" = { {
      "name" = "wcvVesselCount",
      "value" = 8,
      "comment" = "The same eight vessels as Tables 25 and 26: kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge and large barge.",
    }, {
      "name" = "wcvMaxCargoPercent",
      "value" = 10,
      "comment" = "The flotation trick holds only for vessels carrying not more than 10% of their listed maximum cargo capacity.",
    }, {
      "name" = "wcvSupportMultiplier",
      "value" = 2,
      "comment" = "A capsized craft will support a number of characters equal to twice its normal capacity.",
    }, {
      "name" = "wcvExampleRowboatCargoGp",
      "value" = 200,
      "comment" = "The small-rowboat example: the foundering craft remains beneath the surface once all but 200 gp worth of cargo or gear is tossed overboard.",
    }, {
      "name" = "wcvExampleRowboatSupport",
      "value" = 8,
      "comment" = "The large-rowboat example: up to eight characters can cluster around the sides and use it to keep from going under.",
    } },
  "bools" = { {
      "name" = "wcvBuoyantJustBeneathSurface",
      "value" = true,
      "comment" = "Because of the natural buoyancy of their materials, most vessels can remain afloat just beneath the surface even after capsizing or hull damage.",
    }, {
      "name" = "wcvWorksAfterCapsizeOrHullDamage",
      "value" = true,
      "comment" = "The flotation holds both for a capsized vessel and for one that has suffered hull damage.",
    }, {
      "name" = "wcvRequiresNoPassengers",
      "value" = true,
      "comment" = "The flotation is true only of vessels carrying no passengers.",
    }, {
      "name" = "wcvCargoWithinMaxPercent",
      "value" = true,
      "comment" = "The flotation is true only of vessels carrying not more than 10% of their listed maximum cargo capacity.",
    }, {
      "name" = "wcvClingToSidesAsFlotation",
      "value" = true,
      "comment" = "Characters can cling to the sides of the sunken craft and use it as a flotation device.",
    }, {
      "name" = "wcvWeightMustBeEven",
      "value" = true,
      "comment" = "The flotation holds only as long as the clinging weight is evenly distributed.",
    }, {
      "name" = "wcvExcessWeightSinks",
      "value" = true,
      "comment" = "If the twice-capacity weight limit is exceeded, the craft sinks too far below the surface to be usable.",
    }, {
      "name" = "wcvUnevenWeightSinks",
      "value" = true,
      "comment" = "If the weight is not evenly distributed, the craft sinks too far below the surface to be usable.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wcvMaxCargoPercent']() != 10 or m['wcvExampleRowboatCargoGp']() != 200 or m['wcvExampleRowboatCargoGp']() != 20 * m['wcvMaxCargoPercent']()",
      "note" = "the 10% cargo condition with the small-rowboat example: 200 gp is ten percent of the 2000 gp listed maximum cargo capacity",
    }, {
      "expr" = "m['wcvSupportMultiplier']() != 2 or m['wcvExampleRowboatSupport']() != 8 or m['wcvExampleRowboatSupport']() != 4 * m['wcvSupportMultiplier']()",
      "note" = "the twice-capacity support: the large rowboat with a normal capacity of four supports eight clinging characters - twice its capacity",
    }, {
      "expr" = "m['wcvRequiresNoPassengers']() != 1 or m['wcvCargoWithinMaxPercent']() != 1 or m['wcvWeightMustBeEven']() != 1",
      "note" = "the three preconditions: no passengers, cargo within the 10% limit, and the clinging weight evenly distributed",
    }, {
      "expr" = "m['wcvExcessWeightSinks']() != 1 or m['wcvUnevenWeightSinks']() != 1",
      "note" = "the two sink triggers: exceeding the twice-capacity weight limit, or uneven weight distribution - either sinks the craft too far below the surface to be usable",
    } },
  "audit" = {
      "label" = "R459 WSG capsized use pin audit",
      "comment" = "The capsized-use slice pins the natural buoyancy (most vessels remain afloat just beneath the surface after capsizing or hull damage), the flotation preconditions (no passengers and no more than 10% of the listed maximum cargo capacity, with the small-rowboat 200 gp example), the cling-to-the-sides flotation with the even-weight-distribution requirement, the twice-capacity support figure (eight characters around a large rowboat), and the sink rules when the weight limit is exceeded or the weight is unevenly distributed (rules/wsg/wsgcapsized.h, prefix wcv); census 383 -> 384.",
    },
}
