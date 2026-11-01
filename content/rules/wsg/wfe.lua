-- wfe: promoted from tools/spec_r481.json (the R481: the WSG FIRST AID EQUIPMENT slice, printed p. 71 - the eleventh camping-arc round and the LAST of the medicine chapter, a pure prose round with NO table: the four essentials - bandages, splints, stretcher and litter - with the party gear-advice frame (nobody goes through an adventure unscathed, so pack the materials for administering aid to the injured).);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 481,
  "prefix" = "wfe",
  "banner" = {
      "title" = "R481: the WSG FIRST AID EQUIPMENT slice, printed p. 71 - the eleventh camping-arc round and the LAST of the medicine chapter, a pure prose round with NO table: the four essentials - bandages, splints, stretcher and litter - with the party gear-advice frame (nobody goes through an adventure unscathed, so pack the materials for administering aid to the injured).",
      "provenance" = "The settle: two-way clean on the first pass - the tesseract full-text read and the pdfy layout read agree on every number of the section (the 2-3 foot splint length, the two-pole stretcher, the half-weight carry bars), and the tsv confirms the geometry cell by cell; no contested cells, no vision reads needed. The skin ailments and other-injuries prose at the top of the page belongs to the injuries chapter landed at R480 and stays out of scope here.",
      "sentinel" = "Bounds held: the splint length runs 2-3 feet; both carry bars use one-half of the victim weight - two carriers on a stretcher, one on a litter.",
    },
  "consts" = { {
      "name" = "wfeEquipmentKindCount",
      "value" = 4,
      "comment" = "four essentials: bandages, splints, stretcher, litter",
    }, {
      "name" = "wfeSplintMinFeet",
      "value" = 2,
      "comment" = "the packed splint pieces are 2-3 feet long",
    }, {
      "name" = "wfeSplintMaxFeet",
      "value" = 3,
      "comment" = "the top of the splint length range",
    }, {
      "name" = "wfeStretcherPoleCount",
      "value" = 2,
      "comment" = "the stretcher needs a pair of poles",
    }, {
      "name" = "wfeStretcherCarriers",
      "value" = 2,
      "comment" = "two comrades carry a stretcher-borne victim",
    }, {
      "name" = "wfeLitterCarriers",
      "value" = 1,
      "comment" = "one carrier suffices for a bound litter victim",
    }, {
      "name" = "wfeHalfNum",
      "value" = 1,
      "comment" = "each carrier supports half of the victim weight",
    }, {
      "name" = "wfeHalfDen",
      "value" = 2,
      "comment" = "the half-weight fraction on both stretcher and litter",
    } },
  "bools" = { {
      "name" = "wfePartyPacksAidMaterials",
      "value" = true,
      "comment" = "it is a good idea for the party gear to include the materials for administering aid to the injured in the line of duty",
    }, {
      "name" = "wfeBandagesCleanFabric",
      "value" = true,
      "comment" = "at least one backpack should contain several swatches of clean fabric for covering and binding wounds and burns",
    }, {
      "name" = "wfeClothingStripsInPinch",
      "value" = true,
      "comment" = "in a pinch an article of clothing torn into strips can be used for bandages",
    }, {
      "name" = "wfeClothingCarriesInfection",
      "value" = true,
      "comment" = "an adventurer clothing is usually not clean, so infection remains possible even when the wound is bandaged",
    }, {
      "name" = "wfeSplintsUnneededInWood",
      "value" = true,
      "comment" = "splints may be unnecessary when the journey passes through a wooded area",
    }, {
      "name" = "wfeSplintsPackedForMountainDesert",
      "value" = true,
      "comment" = "for a mountain climb or a desert crossing it is wise to pack a couple of straight, short rigid pieces bound along the sides of a broken limb to keep the bones properly aligned",
    }, {
      "name" = "wfeLeatherHideAsSplint",
      "value" = true,
      "comment" = "a large piece of thick leather or untanned hide works as a splint if large and rigid enough to immobilize the limb and the joints on both sides, like a plaster cast",
    }, {
      "name" = "wfeStretcherPartsCarriedSeparately",
      "value" = true,
      "comment" = "most groups carry the stretcher parts separately and assemble the stretcher if and when it is needed",
    }, {
      "name" = "wfeStretcherPolesAsTallAsVictim",
      "value" = true,
      "comment" = "the poles must be at least as long as the injured character height",
    }, {
      "name" = "wfeStretcherNeedsSurfaceAndBinding",
      "value" = true,
      "comment" = "sturdy cloth or leather large enough to recline on, plus rope or cord of sufficient length to bind the poles to the edges",
    }, {
      "name" = "wfeStretcherTwoCarryHalfEach",
      "value" = true,
      "comment" = "two comrades can carry the victim as long as each supports half the weight without being too encumbered to move",
    }, {
      "name" = "wfeLitterSameAsStretcher",
      "value" = true,
      "comment" = "the litter is essentially the same as a stretcher, except extra rope or cord binds the victim to the frame",
    }, {
      "name" = "wfeLitterOneCarrierOrBeast",
      "value" = true,
      "comment" = "one character, mount or beast of burden can transport the bound victim while supporting half the weight",
    }, {
      "name" = "wfeLitterUnwiseOnRugged",
      "value" = true,
      "comment" = "it is usually not wise to transport a litter over rugged or very rugged terrain",
    }, {
      "name" = "wfeLitterDragsAndJostles",
      "value" = true,
      "comment" = "one end of the litter is always on the ground and the victim is jostled as it skids and bumps along",
    }, {
      "name" = "wfeDmMayRuleRoughHandlingDamage",
      "value" = true,
      "comment" = "if the victim must be kept motionless, the DM may rule that a rugged trip causes further damage from the rough handling",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the four essentials, and the splint length runs 2-3 feet",
      "expr" = "m['wfeEquipmentKindCount']() != 4 or m['wfeSplintMinFeet']() != 2 or m['wfeSplintMaxFeet']() != 3 or m['wfeSplintMinFeet']() > m['wfeSplintMaxFeet']()",
    }, {
      "note" = "the carry bars: two stretcher carriers, one litter carrier, each at half the weight",
      "expr" = "m['wfeStretcherCarriers']() != 2 or m['wfeLitterCarriers']() != 1 or m['wfeHalfDen']() != 2 * m['wfeHalfNum']() or m['wfeStretcherPoleCount']() != 2",
    } },
  "audit" = {
      "label" = "R481 WSG first aid equipment pin audit",
      "comment" = "The first aid equipment rules: bandages (several swatches of clean fabric for covering and binding wounds and burns; clothing torn into strips works in a pinch but adventurers clothing is usually not clean, leaving a possibility of infection even when the wound is bandaged), splints (not necessary when traveling through a wooded area, but wise to pack for a mountain climb or a desert crossing: a couple of straight, short 2-3-foot pieces of wood or other rigid material bound along the sides of a broken limb to keep the bones properly aligned; a large piece of thick leather or untanned hide works too, if large and rigid enough to keep the limb and the joints on both sides immobilized, in the same manner as a plaster cast), the stretcher (parts carried separately and assembled when needed: two poles at least as long as the injured character height, sturdy cloth or leather large enough to recline on, and rope or cord of sufficient length to bind the poles to the edges; two comrades can carry the victim as long as each supports half the weight without being too encumbered to move), and the litter (essentially a stretcher plus extra rope or cord to bind the victim to the frame; one character - or one mount or beast of burden - can transport the bound victim, supporting half the weight; unwise over rugged or very rugged terrain because one end always drags on the ground and the victim is jostled as the litter skids and bumps; the DM may rule the trip causes further damage from the rough handling).",
    },
}
