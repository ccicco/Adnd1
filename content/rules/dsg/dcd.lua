-- dcd: promoted from tools/spec_r551.json (the THE REST OF WORLDS OF ADVENTURE, R551: printed pp. 101-103 (pdf 102-104) - the second half of the setting-design doctrine: the location-type variety (underworld settings lack the surface's climate criterion and still require variety; natural and artificial settings as the source; each area's size, shape and physical features carrying one or two unique characteristics; the inhabitants as another variety source - the all-orcs-and-ogres expedition boring quickly without tactical ingenuity; the individualistic monsters - the orc chieftain fancying himself a fashion judge outfitting his troops garishly, the chieftain starved for outside news keeping captives alive for stories; the stale-campaign surprise cure), the dangerous/safe mix (the kill-or-be-killed game losing its lustre for even the bloodthirsty; the friendly NPC encounters dropped in now and then; the realistic shoot-first consequences; the tranquil havens making the danger more exciting; the no-regular-haven-violations rule - adventurers lose their basic motivations without any expectation of peace), Consistency (the fantastic location built on an underlying idea of why it is there and how it functions; the familiarity-over-realism doctrine with the dragon example - unreal, yet familiar by extrapolation to its world; the source consistency without slavish re-creation - the augmenting pieces used, the inconsistent ignored; the medieval-Europe familiarity of the castle and the blacksmith/serf/ merchant roles; the world founded on rules all creatures and civilizations live and die by, the established principles stable absent very strong reason; the simple nature laws - seasons, snowy mountaintops, regular tides - fixed for the campaign's duration; the growing exploration familiarity; the social-interaction familiarity with the caught treasury thief paying the stiff lawful penalty, laws extending into fantasy, the thief's role very dull without them), the Intelligent Races questionnaire (the foresight demand - quickly designed races blowing up in the DM's face, the original race extensive, the known-race branch a base to expand upon; the appearance central with the game statistics, creatures looking the way they do for a reason, the related-race framework, the challenge/terrify/befriend role fit; the livelihood - food and its source, the anti-devouring defenses, the specialized combat tactics, the neighbor problem, the infighting; the civilization extent - literacy, metalworking and building, beyond-borders knowledge - and its consequences for conflicts and documented vs oral history; the settlement scale with the manufactured/ natural dwelling split and the technology level; the customs - the forgotten ritual reasons, the societal-preservation roots, the empty-palm/ handshake show-no-weapon example, the outsider puzzlement, the develop-a-few-per-race advice; the limitations - weaknesses, leader skill, weapons, combat morale, immunities and invulnerabilities; the preferences - the glock-devouring dislike, the isolation-vs-trade split, the resemblance-driven first impressions), and Uniqueness (every DM's own style making each campaign unique to an extent; the within-world creative additions - unusual names, new architecture and plant life, original city- problem handling, unusual superstitions; the faithful-recreation exception - the fantasy-book DM as true to the source's spirit as possible).);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 551,
  "prefix" = "dcd",
  "banner" = {
      "title" = "THE REST OF WORLDS OF ADVENTURE, R551: printed pp. 101-103 (pdf 102-104) - the second half of the setting-design doctrine: the location-type variety (underworld settings lack the surface's climate criterion and still require variety; natural and artificial settings as the source; each area's size, shape and physical features carrying one or two unique characteristics; the inhabitants as another variety source - the all-orcs-and-ogres expedition boring quickly without tactical ingenuity; the individualistic monsters - the orc chieftain fancying himself a fashion judge outfitting his troops garishly, the chieftain starved for outside news keeping captives alive for stories; the stale-campaign surprise cure), the dangerous/safe mix (the kill-or-be-killed game losing its lustre for even the bloodthirsty; the friendly NPC encounters dropped in now and then; the realistic shoot-first consequences; the tranquil havens making the danger more exciting; the no-regular-haven-violations rule - adventurers lose their basic motivations without any expectation of peace), Consistency (the fantastic location built on an underlying idea of why it is there and how it functions; the familiarity-over-realism doctrine with the dragon example - unreal, yet familiar by extrapolation to its world; the source consistency without slavish re-creation - the augmenting pieces used, the inconsistent ignored; the medieval-Europe familiarity of the castle and the blacksmith/serf/ merchant roles; the world founded on rules all creatures and civilizations live and die by, the established principles stable absent very strong reason; the simple nature laws - seasons, snowy mountaintops, regular tides - fixed for the campaign's duration; the growing exploration familiarity; the social-interaction familiarity with the caught treasury thief paying the stiff lawful penalty, laws extending into fantasy, the thief's role very dull without them), the Intelligent Races questionnaire (the foresight demand - quickly designed races blowing up in the DM's face, the original race extensive, the known-race branch a base to expand upon; the appearance central with the game statistics, creatures looking the way they do for a reason, the related-race framework, the challenge/terrify/befriend role fit; the livelihood - food and its source, the anti-devouring defenses, the specialized combat tactics, the neighbor problem, the infighting; the civilization extent - literacy, metalworking and building, beyond-borders knowledge - and its consequences for conflicts and documented vs oral history; the settlement scale with the manufactured/ natural dwelling split and the technology level; the customs - the forgotten ritual reasons, the societal-preservation roots, the empty-palm/ handshake show-no-weapon example, the outsider puzzlement, the develop-a-few-per-race advice; the limitations - weaknesses, leader skill, weapons, combat morale, immunities and invulnerabilities; the preferences - the glock-devouring dislike, the isolation-vs-trade split, the resemblance-driven first impressions), and Uniqueness (every DM's own style making each campaign unique to an extent; the within-world creative additions - unusual names, new architecture and plant life, original city- problem handling, unusual superstitions; the faithful-recreation exception - the fantasy-book DM as true to the source's spirit as possible).",
      "provenance" = "djvu lines 13013-13326 with the Capture-layer pdf 102-104 cross-read (the pure-python extractor of the R550 note, parser page = printed page). The two reads agree across the round. The one settled garble: the Capture layer reads 'determinatibn' - settled as determination by the djvu read. The glocks passage reads identically in both machine reads (the invented neighboring race). The two-column Capture pages interleave in extraction, but every load-bearing claim was matched sentence-for-sentence against the djvu. A CLEAN-READ ROUND, no OCR-failure cells. A ZERO-FLIP ROUND: the pp. 99-113 Campaign Considerations child stays open (plotted pp. 100-113 still in flight).",
      "sentinel" = "The campaign chapter: R550 the opener, R551 the worlds of adventure tail, next the plot and counterplot pp. 103-106.",
    },
  "consts" = {},
  "bools" = { {
      "comment" = "the world must have different types of locations; underworld settings lack the surface's climate criterion and still require variety",
      "name" = "dcdLocationTypes",
      "value" = true,
    }, {
      "comment" = "natural and artificial settings provide a source of variety; each area's sizes, shapes and physical features should have at least one or two unique characteristics",
      "name" = "dcdNaturalArtificial",
      "value" = true,
    }, {
      "comment" = "the inhabitants provide another variety source - an expedition meeting nothing but orcs and ogres becomes boring very quickly without tactical ingenuity and variety",
      "name" = "dcdInhabitantVariety",
      "value" = true,
    }, {
      "comment" = "add a few individualistic monsters - the orc chieftain fancying himself a skilled judge of fashion outfitting his troops garishly, the chieftain starved for outside news letting captives live while they entertain him with stories",
      "name" = "dcdIndividualistic",
      "value" = true,
    }, {
      "comment" = "a predictable campaign long unsuprising is the ideal time to spring an unusual setting or encounter - a sudden surprise makes up for a few weeks of stale adventuring",
      "name" = "dcdStaleSurprise",
      "value" = true,
    }, {
      "comment" = "provide a variety of dangerous and safe places, and encounters with creatures of good and evil",
      "name" = "dcdEncounterMix",
      "value" = true,
    }, {
      "comment" = "the kill-or-be-killed game soon loses its lustre for even the most bloodthirsty players - drop in a friendly or helpful NPC encounter now and then",
      "name" = "dcdFriendlyEncounters",
      "value" = true,
    }, {
      "comment" = "include realistic consequences should the PCs decide to shoot first and ask questions later",
      "name" = "dcdShootFirstConsequences",
      "value" = true,
    }, {
      "comment" = "some places should be tranquil havens for rest and recovery - the rest periods make the danger and adventure seem that much more exciting",
      "name" = "dcdTranquilHavens",
      "value" = true,
    }, {
      "comment" = "an occasional dangerous encounter in a haven is fine but not a regular practice - without any expected peace, adventurers lose basic motivations",
      "name" = "dcdHavenRespect",
      "value" = true,
    }, {
      "comment" = "any fantastic setting should be created with an underlying idea of why it is there and how it functions, the reasons often based in the real world",
      "name" = "dcdUnderlyingIdea",
      "value" = true,
    }, {
      "comment" = "a feeling of familiarity about an area is more important than realism to the success of the campaign",
      "name" = "dcdFamiliarityOverRealism",
      "value" = true,
    }, {
      "comment" = "the dragon example - not and never real, yet the familiar huge fire-breathing reptile gives players familiarity with the creature and by extrapolation with its world",
      "name" = "dcdDragonFamiliarity",
      "value" = true,
    }, {
      "comment" = "be consistent with the world's source to the extent it fits your plans - use the pieces that augment the game, ignore the pieces inconsistent with your goals, never slavish re-creation at gaming's expense",
      "name" = "dcdSourceConsistency",
      "value" = true,
    }, {
      "comment" = "with medieval Europe as the basis (as it is for the game itself), the familiar aspects - the castle's well-known characteristics, the blacksmith/serf/merchant NPC roles",
      "name" = "dcdHistoricalFamiliarity",
      "value" = true,
    }, {
      "comment" = "the world must be founded on a set of rules that all creatures and civilizations live and die by; established principles remain consistent unless there is a very strong reason for change",
      "name" = "dcdWorldRulesStable",
      "value" = true,
    }, {
      "comment" = "simple laws of nature - the changing seasons, the snow-and-ice-capped mountaintops, the regular tides - once determined remain in effect for the campaign's duration",
      "name" = "dcdNatureLaws",
      "value" = true,
    }, {
      "comment" = "as PCs explore a new world it grows increasingly familiar and they feel more at home - not omniscience, a natural growth contributing to enjoyment",
      "name" = "dcdFamiliarityGrows",
      "value" = true,
    }, {
      "comment" = "social interactions base on real-world analogies - the consequences of the PCs' actions fit society's interpretation of those actions",
      "name" = "dcdSocialFamiliarity",
      "value" = true,
    }, {
      "comment" = "the caught treasury thief pays a stiff penalty consistent with the laws of the land; civilizations develop laws to control members, extended logically into fantasy - without laws and consequences the thief's role is very dull",
      "name" = "dcdLawConsequences",
      "value" = true,
    }, {
      "comment" = "intelligent-race creation requires great DM attention and foresight - quickly designed races often blow up in the DM's face, unlike casually generated monster bands",
      "name" = "dcdRacesNeedForesight",
      "value" = true,
    }, {
      "comment" = "a completely original and unique race makes the task extensive; a branch or variation of a known race, including humans, provides a base of information to expand upon",
      "name" = "dcdOriginalRaceExtensive",
      "value" = true,
    }, {
      "comment" = "appearance is central - the game statistics for all applicable areas included; creatures generally look the way they do for a reason; related races give the initial framework; the stats fit the planned role: challenge, terrify, or befriend the PCs",
      "name" = "dcdRaceAppearance",
      "value" = true,
    }, {
      "comment" = "how the race lives - what members eat and where the food comes from, how they avoid being devoured, the specialized combat tactics planned out now, the nature of any neighbor problem, whether they fight among themselves",
      "name" = "dcdRaceLivelihood",
      "value" = true,
    }, {
      "comment" = "intelligence is not civilization - the hallmarks: literacy, the ability to work metals and build things, knowledge of the world beyond the race's borders",
      "name" = "dcdCivilizationHallmarks",
      "value" = true,
    }, {
      "comment" = "the civilization level often determines how the race fares in neighbor conflicts, and how much of its history is known - documented or passed along by word of mouth",
      "name" = "dcdCivilizationConsequences",
      "value" = true,
    }, {
      "comment" = "civilization determines the settlement - generally the more advanced the civilization the larger the settlement; not all civilized members live in cities; manufactured dwellings or natural shelters, with the technology level required",
      "name" = "dcdSettlementScale",
      "value" = true,
    }, {
      "comment" = "any intelligent race develops customs - often with reasons no longer apparent, attaining ritual status for time-honored but forgotten purposes; others rooted in the preservation of the society and its members",
      "name" = "dcdRaceCustoms",
      "value" = true,
    }, {
      "comment" = "the empty palm or the handshake could well be outgrowths of the ancient custom of showing another that you raise no weapon against him; customs can be complicated and puzzling to outsiders",
      "name" = "dcdHandshakeCustom",
      "value" = true,
    }, {
      "comment" = "all customs need not be determined before introduction - new ones can develop the story or explain creature actions; it is wise to develop a few per race for detail at first encounter",
      "name" = "dcdCustomsIncremental",
      "value" = true,
    }, {
      "comment" = "the race's limitations - significant weaknesses PCs can exploit, leader skill, weapon types, combat morale, specific immunities or invulnerabilities",
      "name" = "dcdRaceLimitations",
      "value" = true,
    }, {
      "comment" = "the likes and dislikes as natural outgrowths - the race surviving by slaughtering and devouring the neighboring glocks fairly dislikes them; isolation means disliking strangers; trade usually welcomes newcomers",
      "name" = "dcdRacePreferences",
      "value" = true,
    }, {
      "comment" = "appearance and first impressions matter - creatures naturally feel friendlier toward those that resemble them, and may be completely horrified at very different-looking creatures",
      "name" = "dcdFirstImpressions",
      "value" = true,
    }, {
      "comment" = "every DM has his own style of play, making each campaign unique to a certain extent - also strive for uniqueness within the world",
      "name" = "dcdUniquenessStyle",
      "value" = true,
    }, {
      "comment" = "add your own creative elements even on a real-life source - unusual names for places, people, or even objects give the campaign a distinctive touch",
      "name" = "dcdUnusualNames",
      "value" = true,
    }, {
      "comment" = "create unusual or new forms of architecture and plant life; devise original ways of handling the typical problems of city and village life; unusual superstitions and practices differentiate the world",
      "name" = "dcdNewForms",
      "value" = true,
    }, {
      "comment" = "when re-creating a world someone else designed, strive to be as true to the original as possible - the DM basing his world on a fantasy book faithful to the spirit of the source",
      "name" = "dcdFaithfulRecreation",
      "value" = true,
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dcdLocationTypes']() != 1 or m['dcdNaturalArtificial']() != 1",
      "note" = "the location frame: the types required, the natural/artificial source.",
    }, {
      "expr" = "m['dcdIndividualistic']() != 1 or m['dcdStaleSurprise']() != 1",
      "note" = "the variety craft: the individualistic monsters, the stale-campaign surprise.",
    }, {
      "expr" = "m['dcdFriendlyEncounters']() != 1 or m['dcdTranquilHavens']() != 1 or m['dcdHavenRespect']() != 1",
      "note" = "the mix: friendly encounters, the havens, the no-regular-violations rule.",
    }, {
      "expr" = "m['dcdFamiliarityOverRealism']() != 1 or m['dcdDragonFamiliarity']() != 1",
      "note" = "the consistency doctrine: familiarity over realism, the dragon example.",
    }, {
      "expr" = "m['dcdWorldRulesStable']() != 1 or m['dcdNatureLaws']() != 1 or m['dcdLawConsequences']() != 1",
      "note" = "the stable world: the founded rules, the nature laws, the law consequences.",
    }, {
      "expr" = "m['dcdRaceAppearance']() != 1 or m['dcdRaceLivelihood']() != 1 or m['dcdRaceLimitations']() != 1 or m['dcdRacePreferences']() != 1",
      "note" = "the race questionnaire: appearance, livelihood, limitations, preferences.",
    }, {
      "expr" = "m['dcdHandshakeCustom']() != 1 or m['dcdCivilizationHallmarks']() != 1",
      "note" = "the race culture: the handshake custom, the civilization hallmarks.",
    }, {
      "expr" = "m['dcdUniquenessStyle']() != 1 or m['dcdFaithfulRecreation']() != 1",
      "note" = "the uniqueness split: the DM's own style against the faithful-recreation exception.",
    } },
  "audit" = {
      "label" = "R551 DSG worlds of adventure audit",
      "comment" = "The rest of Worlds of Adventure pins printed pp. 101-103: the location-type variety (the missing climate criterion, the natural/artificial settings, the unique area characteristics, the inhabitant variety with the individualistic monsters), the dangerous/safe mix (the friendly encounters, the shoot-first consequences, the tranquil havens), Consistency (the familiarity-over-realism doctrine with the dragon example, the source and historical familiarity, the stable world rules, the social laws and consequences), the Intelligent Races design questionnaire (appearance, livelihood, civilization, settlements, customs, limitations, preferences, first impressions), and Uniqueness (the DM's style, the creative additions, the faithful-recreation exception).",
    },
}
