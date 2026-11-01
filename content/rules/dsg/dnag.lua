-- dnag: promoted from tools/spec_r538.json (the THE DSG DEEPEARTH AREAS 10-11, R538: printed pp. 84-86 (pdf 85-87) - the individual area key crosses the drowned land and the flayer outpost: Area 10 Sunken Swamp (the ancient earthquake product - the forest and villages that fell into the split faults, the rock faces wedged to leave survivable hollows; more than a dozen huge chambers 1,000 to 4,000 feet wide and 3d6 miles long, dirt-lined over rotted timber, misted by the trickling streams through the fault above, the glowing mosses and fungi as dim light; the survivors' wide shored tunnels of oil-soaked timbers linking each cavern to at least two others; the degenerated sub-savage descendants - cleanliness, education, clothing abandoned, splintered into chosen-few factions with their vengeful-gods legends - 50 to 100 per cavern, primitive emotion-speech, curious hosts who study peaceful visitors for a few weeks and then eat them; the free-for-all savage wars and the reconciliation councils that devour the casualties; the scavengers, shambling mounds, snakes, spiders, toads and frogs over the plentiful fungi; the muggy decay-scented air, the shapeless spongy earth and the smoky peat fires; the sacred survived structures - the vast roofless temple with its gold, silver and platinum relics in the largest chamber, the corroded sacred armory weapons; and the smallest dry cavern where rapid petrification left unburnable stone-like wood), and Area 11 Outpost of the Illithids (the large central cave nearly a mile across and circular, its ceiling climbing more than 100 feet on six mighty stone pillars, the four converging streams feeding the porous outflow-less pond; the four cardinal side caves, each about a mile long, never more than 50 feet wide, ceilings to 20 feet but often 6 or less, each pouring its trickle in; the living-cave formations; about 25 mind flayers in the central cavern, their scouting parties and the alarm for the homelands far below; the carrion-crawler-otyugh-rat-slime-jelly-ooze scavengers of the side caves; the smelly stagnant air and the limited steady water; and the circle of dwarven one-room stone huts around the central pool - a single guard on each entry cave, and the secret trap-doored trove of copper, silver, electrum and gold coins, gems, magical weapons, scrolls and a half-dozen potions));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 538,
  "prefix" = "dnag",
  "banner" = {
      "title" = "THE DSG DEEPEARTH AREAS 10-11, R538: printed pp. 84-86 (pdf 85-87) - the individual area key crosses the drowned land and the flayer outpost: Area 10 Sunken Swamp (the ancient earthquake product - the forest and villages that fell into the split faults, the rock faces wedged to leave survivable hollows; more than a dozen huge chambers 1,000 to 4,000 feet wide and 3d6 miles long, dirt-lined over rotted timber, misted by the trickling streams through the fault above, the glowing mosses and fungi as dim light; the survivors' wide shored tunnels of oil-soaked timbers linking each cavern to at least two others; the degenerated sub-savage descendants - cleanliness, education, clothing abandoned, splintered into chosen-few factions with their vengeful-gods legends - 50 to 100 per cavern, primitive emotion-speech, curious hosts who study peaceful visitors for a few weeks and then eat them; the free-for-all savage wars and the reconciliation councils that devour the casualties; the scavengers, shambling mounds, snakes, spiders, toads and frogs over the plentiful fungi; the muggy decay-scented air, the shapeless spongy earth and the smoky peat fires; the sacred survived structures - the vast roofless temple with its gold, silver and platinum relics in the largest chamber, the corroded sacred armory weapons; and the smallest dry cavern where rapid petrification left unburnable stone-like wood), and Area 11 Outpost of the Illithids (the large central cave nearly a mile across and circular, its ceiling climbing more than 100 feet on six mighty stone pillars, the four converging streams feeding the porous outflow-less pond; the four cardinal side caves, each about a mile long, never more than 50 feet wide, ceilings to 20 feet but often 6 or less, each pouring its trickle in; the living-cave formations; about 25 mind flayers in the central cavern, their scouting parties and the alarm for the homelands far below; the carrion-crawler-otyugh-rat-slime-jelly-ooze scavengers of the side caves; the smelly stagnant air and the limited steady water; and the circle of dwarven one-room stone huts around the central pool - a single guard on each entry cave, and the secret trap-doored trove of copper, silver, electrum and gold coins, gems, magical weapons, scrolls and a half-dozen potions)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~10692-10885) with the pdf Acrobat-Capture layer as the second read (idx 384-392 = the printed pp. 84-87 windows); the compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing number - the dozen-plus chambers, the 1,000-to-4,000-ft widths, the 3d6-mile lengths, the two-others tunnel links, the 50-to-100 populations, the four side caves, the 50-ft widths, the 20-ft and 6-ft ceilings, the mile-long side caves, the mile-diameter central cave, the 100-ft ceiling, the six pillars, the four streams, the 25 illithids and the four guards; the only garbles are non-load-bearing (the djvu Cyrillic-glyph header noise and the 'Plentiful' typo). SEAMS: the Monster Manual denizens (the mind flayers, shambling mounds, carrion crawlers, otyughs and the rest), the R518 water travel where relevant, the earthquake seam shared with Areas 6-7 and 12, and the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open until the setting lands in full (the R527/R533-R537 precedent - the gap report is NOT in the git add). Nothing auto-credits.",
      "sentinel" = "A procedural-plus-prose round: no tables pin. The numbers pin as consts per the R508 convention - the chamber counts, widths and lengths, the tunnel-link and population bounds, the side-cave count and dimensions, the central cave's diameter, ceiling and pillars, the stream, illithid and guard counts, with the 3d6 dice pinned as a count-and-sides pair. The geography, denizens, resources and unique-features prose pins as bools for both areas. The MM/quake/R503 seams are noted; the Deepearth child stays open; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnagChamberMinCount",
      "value" = 12,
      "comment" = "more than a dozen huge chambers make up the sunken swamp region, born of the ancient earthquake that adjusted the water table and dried the nearby caves.",
    }, {
      "name" = "dnagChamberWidthLowFt",
      "value" = 1000,
      "comment" = "the nature of the faulting has resulted in areas of 1,000 to 4,000 feet wide (the low bound).",
    }, {
      "name" = "dnagChamberWidthHighFt",
      "value" = 4000,
      "comment" = "the sunken swamp chambers run 1,000 to 4,000 feet wide (the high bound).",
    }, {
      "name" = "dnagChamberLenDice",
      "value" = 3,
      "comment" = "the sunken swamp chambers are 3d6 miles long (the die count).",
    }, {
      "name" = "dnagChamberLenSides",
      "value" = 6,
      "comment" = "the sunken swamp chambers are 3d6 miles long (the die sides).",
    }, {
      "name" = "dnagTunnelLinkMin",
      "value" = 2,
      "comment" = "the survivors' wide straight tunnels slice through the mounds of earth, linking each cavern to at least two others.",
    }, {
      "name" = "dnagPopLow",
      "value" = 50,
      "comment" = "each of the large caverns hosts a human population ranging from 50-100 dirty, scraggly people (the low bound).",
    }, {
      "name" = "dnagPopHigh",
      "value" = 100,
      "comment" = "each cavern's degenerated human population ranges from 50-100 (the high bound).",
    }, {
      "name" = "dnagSideCaveCount",
      "value" = 4,
      "comment" = "the area is primarily a large central cave with four connecting smaller caves branching in the four cardinal directions of the compass, each higher than the central chamber and each pouring a small trickle of water into it.",
    }, {
      "name" = "dnagSideCaveMaxWidthFt",
      "value" = 50,
      "comment" = "the side caverns are relatively narrow, never more than 50 feet wide at their widest point.",
    }, {
      "name" = "dnagSideCeilMaxFt",
      "value" = 20,
      "comment" = "the side cavern ceilings sometimes climb as much as 20 feet from the floor.",
    }, {
      "name" = "dnagSideCeilTypicalFt",
      "value" = 6,
      "comment" = "the side cavern ceilings more often drop to heights of six feet or even less.",
    }, {
      "name" = "dnagSideCaveLenMiles",
      "value" = 1,
      "comment" = "each of the side caverns is about a mile long.",
    }, {
      "name" = "dnagCentralDiaMiles",
      "value" = 1,
      "comment" = "the large central cave is nearly a mile in diameter and more circular in shape.",
    }, {
      "name" = "dnagCentralCeilFt",
      "value" = 100,
      "comment" = "the central cave ceiling climbs more than 100 feet above the floor at the center of the cavern.",
    }, {
      "name" = "dnagPillarCount",
      "value" = 6,
      "comment" = "earlier denizens erected a series of six mighty stone pillars to support the central cavern's roof.",
    }, {
      "name" = "dnagIllithidCount",
      "value" = 25,
      "comment" = "the only intelligent beings in this remote section of Deepearth are the mind flayers - about 25 of the repulsive creatures live in the large central cavern.",
    }, {
      "name" = "dnagStreamCount",
      "value" = 4,
      "comment" = "at the center of the large cavern the four narrow streams converge to feed a small pond; the pond has no surface outflow, leaking through porous rock and seeping slowly through the earth - four small streams provide the caverns with a limited but steady water supply.",
    }, {
      "name" = "dnagGuardCount",
      "value" = 4,
      "comment" = "a single mind flayer guards each of the four caves leading into this area.",
    } },
  "bools" = { {
      "name" = "dnagQuakeOrigin",
      "value" = true,
      "comment" = "the sunken swamp is the product of an ancient earthquake - probably the same one that adjusted the water table and dried the nearby caves; originally the entire region lay on the surface, where a tall thick forest flourished and many small villages nestled among the trees.",
    }, {
      "name" = "dnagLandFell",
      "value" = true,
      "comment" = "when the faults deep within the earth were split asunder the land fell - trees, buildings, animals and humans were tossed into the gaping holes, massive rock walls toppling inward and crushing most of the unfortunate victims; in a few places the massive rock faces wedged against each other, leaving vast hollow spaces where humans and animals miraculously survived.",
    }, {
      "name" = "dnagDirtLined",
      "value" = true,
      "comment" = "unlike most of the realms of Deepearth the sunken swamp caverns are lined with dirt, the timber and living plants long since rotted into a damp spongy surface; small streams trickle through the cracks in the fault above, dropping a fine mist throughout the area, and slimy mosses and fungi line the rock faces, glowing enough to provide a dim light source.",
    }, {
      "name" = "dnagShoredTunnels",
      "value" = true,
      "comment" = "the separate caverns were originally isolated by vast choking mounds of dirt and tree trunks, but the quake survivors and their descendants worked for centuries to link them; the wide straight tunnels have been shored with ancient timbers from massive trees, thoroughly soaked in oil to delay their inevitable rot.",
    }, {
      "name" = "dnagDegenerated",
      "value" = true,
      "comment" = "the quake survivors' descendants degenerated with each generation - first cleanliness, then education, then clothing abandoned - to a sub-savage state with cannibalism not unheard of; they have splintered into several small groups, each certain that they alone are the chosen race, though their legends tell of a great cataclysmic punishment by vengeful gods and the chosen few selected to purify the race.",
    }, {
      "name" = "dnagPrimitiveSpeech",
      "value" = true,
      "comment" = "the natives' speech has become very primitive - a means of conveying emotion rather than information; suspicious and distrustful of strangers but not automatically unfriendly, they are very curious about the world, and peaceful visitors are usually invited to stay for a few weeks of intense study - after which the visitors are eaten.",
    }, {
      "name" = "dnagSavageWars",
      "value" = true,
      "comment" = "occasionally the population is swept up in a brief period of savage warfare - a massive free-for-all with no allies and every group a mortal enemy; after a few days of slaughter the survivors lose interest, and the great reconciliation council's high point is the devouring of the war casualties.",
    }, {
      "name" = "dnagSwampFauna",
      "value" = true,
      "comment" = "other creatures live on the spongy loam - most varieties of underground scavengers, a few shambling mounds in comfortable lairs, snakes and spiders of all types, and monstrous toads and frogs, with plentiful fungi growths providing key food elements for the humans and some of the other inhabitants.",
    }, {
      "name" = "dnagMistyResources",
      "value" = true,
      "comment" = "the steady misting rain from the surface creates a region of high humidity; the air is muggy and thick, smelling heavily of decay and death, but oxygen is fairly plentiful as the air circulates through the same vents that give access to the water.",
    }, {
      "name" = "dnagPeatFires",
      "value" = true,
      "comment" = "the spongy earth is easy to dig but not solid enough to hold its shape, so it is not used for burrows or structures; in a few places the forest remains have stayed dry and created a peat-like substance that burns long when ignited, but it makes a very smoky smelly fire and is not commonly used.",
    }, {
      "name" = "dnagSacredTemple",
      "value" = true,
      "comment" = "a few surface structures survived the quake relatively intact and are regarded as sacred places; the most prominent is a vast squarish temple of solid stone blocks in the center of the largest chamber - its roof collapsed but all the walls remain, with a large central courtyard and smaller peripheral rooms containing gold, silver and platinum relics the current residents have no use for; the temple is one of the safest places in the swamp since the humans hardly ever venture there.",
    }, {
      "name" = "dnagSacredArmory",
      "value" = true,
      "comment" = "a few other roofless stone structures lie scattered among the caverns - once sturdy vaults, armories and prisons; in one cave an armory still contains an assortment of corroded normal weapons that could be made useful with a little sharpening, but the residents do not employ them since they have been declared sacred.",
    }, {
      "name" = "dnagPetrifiedCavern",
      "value" = true,
      "comment" = "the smallest of the caverns receives no natural water from above, so the trees and building rubble did not rot; a rapid form of petrification set in, leaving wood that looks virtually as it did when it landed, grown hard and almost stone-like, and cannot be burned.",
    }, {
      "name" = "dnagLivingCaves",
      "value" = true,
      "comment" = "the outpost caverns are all of natural origin, bedecked with the full array of beautiful cave formations; the small amount of water here is enough to insure that these are living caves.",
    }, {
      "name" = "dnagIllithidScouts",
      "value" = true,
      "comment" = "the mind flayers occasionally send out small groups to explore and scout nearby areas; the scouting parties sometimes return with prisoners offered as fodder for the other illithids, but their main purpose is to keep track of subterranean activities and sound the alarm over any invasion of the illithid homelands far below.",
    }, {
      "name" = "dnagOutpostScavengers",
      "value" = true,
      "comment" = "the only other denizens are an assortment of scavengers - carrion crawlers, otyughs, rats, giant rats, slimes, jellies and oozes - generally remaining in the four side caverns and surviving on carcasses left behind by the mind flayers; the air is smelly and stagnant, but neither the illithids nor the scavengers seem to mind.",
    }, {
      "name" = "dnagDwarvenHuts",
      "value" = true,
      "comment" = "the mind flayers live in a small group of stone buildings erected by the caverns' previous dwarven occupants - one-room structures arranged in a circle around a central pool.",
    }, {
      "name" = "dnagSecretTreasure",
      "value" = true,
      "comment" = "the mind flayers keep a substantial trove of treasure piled loosely in a secret room below the floor of one of the huts, reached by a trap door treated as a secret door; the treasures include coins of copper, silver, electrum and gold, a few gems, a couple of magical weapons, several scrolls and a half-dozen potions, with the gp value tailored to the needs of the group if discovered.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnagChamberMinCount']() != 12 or m['dnagChamberWidthLowFt']() != 1000 or m['dnagChamberWidthHighFt']() != 4000 or m['dnagChamberLenDice']() != 3 or m['dnagChamberLenSides']() != 6",
      "note" = "the Sunken Swamp chambers: more than a dozen, 1,000 to 4,000 feet wide, 3d6 miles long.",
    }, {
      "expr" = "m['dnagTunnelLinkMin']() != 2 or m['dnagPopLow']() != 50 or m['dnagPopHigh']() != 100",
      "note" = "the survivors' works and numbers: tunnels linking each cavern to at least two others, the 50-to-100-strong cavern populations.",
    }, {
      "expr" = "m['dnagSideCaveCount']() != 4 or m['dnagSideCaveMaxWidthFt']() != 50 or m['dnagSideCeilMaxFt']() != 20 or m['dnagSideCeilTypicalFt']() != 6 or m['dnagSideCaveLenMiles']() != 1",
      "note" = "the outpost side caverns: four of them, never wider than 50 feet, ceilings to 20 feet but often 6 or less, each about a mile long.",
    }, {
      "expr" = "m['dnagCentralDiaMiles']() != 1 or m['dnagCentralCeilFt']() != 100 or m['dnagPillarCount']() != 6 or m['dnagStreamCount']() != 4",
      "note" = "the central cave: nearly a mile across, ceiling over 100 feet, six pillars, four converging streams.",
    }, {
      "expr" = "m['dnagIllithidCount']() != 25 or m['dnagGuardCount']() != 4",
      "note" = "the mind flayers: about 25 in the central cavern, a single guard on each of the four entry caves.",
    } },
  "audit" = {
      "label" = "R538 DSG Deepearth areas 10-11 audit",
      "comment" = "The DSG Deepearth areas 10-11 pin Area 10 (the Sunken Swamp with its quake-fallen chambers, the degenerated cannibal tribes, the sacred temple and the petrified cavern) and Area 11 (the illithid outpost with its four side caves, the pillar-roofed central cavern and the secret treasure trove).",
    },
}
