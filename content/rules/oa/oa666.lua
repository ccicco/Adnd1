-- oa666: promoted from rules/oat63divination.h (the TABLE 63 DIVINATION RESULTS, printed capture p. 117 - the OA divination);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 666,
  "prefix" = "oa666",
  "banner" = {
      "title" = "TABLE 63 DIVINATION RESULTS, printed capture p. 117 - the OA divination",
      "provenance" = "results round census 588 -> 589.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print p. 117; compressed pp. 59-60); the five band rows cross-checked line by line between the passes, zero contested reads - the only OCR variance is typographic (the compressed dropping a period on the neutral row and a stray quote mark on the favorable to hit line). The table answers the omen spell: a 1d10 rolled when the DM has no information on which to base his judgment. The bands pin as a chain (the die roll mapped to its band: 1-2 ill omen, 3-4 great danger, 5-7 neutral, 8-9 favorable, 10 auspicious - the neutral band the widest at three faces) and a six-column grid: the party to hit and save modifiers, the foe to hit modifier, the encounter chance multiplier, the reaction modifier and the travel boost. The ill omen band is conditional: the -1 party penalties apply only if the characters ignore the advice (the diaIllOmenIgnorePenalty pin), while the doubled encounters and the -10% reaction apply outright - great danger shares the doubled encounters and the reaction penalty and adds the adversaries to hit at +1. The favorable band travels at half again the normal rate (pinned +50 percent) with opponents to hit at -1; the auspicious band stacks all the favorable effects plus the +1 on all saving throws that day. The band names ride the column comments, the omen prose closes in its own round. The table tag T63Data identifier-safe per the R639 lesson  the gap census after this round: 119 closed, 116 open - the Table 63 Divination Results box flips (census 588 -> 589); NEXT - R667: the Table 64 Speak with Dead (capture p. 132), prefix dib (verify free), audit \"R667 OA speak with dead audit\"",
    },
  "consts" = { {
      "name" = "diaBandCount",
      "value" = 5,
      "comment" = "the five divination result bands (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaDieFaces",
      "value" = 10,
      "comment" = "the omen roll is 1d10, the table consulted when the DM has no information (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaNeutralFaces",
      "value" = 3,
      "comment" = "the neutral band is the widest at three faces (die 5-7); the other bands one or two (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaIllOmenBand",
      "value" = 0,
      "comment" = "the ill omen band - die 1-2: the characters should not undertake the task this day (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaGreatDangerBand",
      "value" = 1,
      "comment" = "the great danger band - die 3-4: doubled encounters, the -10% reaction and the adversaries to hit at +1 (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaNeutralBand",
      "value" = 2,
      "comment" = "the neutral omen band - die 5-7: no special modifiers apply (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaFavorableBand",
      "value" = 3,
      "comment" = "the favorable omen band - die 8-9: travel at half again the normal rate and opponents to hit at -1 (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaAuspiciousBand",
      "value" = 4,
      "comment" = "the auspicious omen band - die 10: all the favorable omen effects plus a +1 on all saving throws that day (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaDoubledEncounterBands",
      "value" = 2,
      "comment" = "the two bands doubling the chance for encounters - ill omen and great danger (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaReactionPenaltyPct",
      "value" = 10,
      "comment" = "the -10% reaction modifier applied to all encounters in the ill omen and great danger bands (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaFavorableSaveBonus",
      "value" = 1,
      "comment" = "the auspicious band alone grants the +1 on all saving throws made that day (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaTravelBoostPct",
      "value" = 50,
      "comment" = "the favorable and auspicious bands travel at half again the normal rate - pinned as +50 percent (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaIllOmenIgnorePenalty",
      "value" = 1,
      "comment" = "the ill omen penalty - if the advice is ignored, all characters suffer a -1 on to hit and saving throw rolls for the rest of the day (print p. 117; compressed pp. 59-60)",
    }, {
      "name" = "diaOmenWeeklyLimit",
      "value" = 1,
      "comment" = "the omen spell can only be used once per week - the strain of the casting (print p. 117; compressed pp. 59-60)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "diaPartyHit",
      "values" = { -1, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the party to hit modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -1 applies only in the ill omen band, and there only if the advice is ignored (the diaIllOmenIgnorePenalty pin); the other bands carry no party to hit modifier",
    }, {
      "name" = "diaPartySave",
      "values" = { -1, 0, 0, 0, 1 },
      "default" = 0,
      "comment" = "the party saving throw modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -1 in the ill omen band (again only if the advice is ignored) and the +1 in the auspicious band; great danger, neutral and favorable carry none",
    }, {
      "name" = "diaFoeHit",
      "values" = { 0, 1, 0, -1, -1 },
      "default" = 0,
      "comment" = "the foe to hit modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the adversaries gain +1 in the great danger band and suffer -1 against the characters in the favorable and auspicious bands; the ill omen and neutral bands carry none",
    }, {
      "name" = "diaEncMult",
      "values" = { 2, 2, 1, 1, 1 },
      "default" = 0,
      "comment" = "the encounter chance multiplier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the chance for encounters is doubled in the ill omen and great danger bands (pinned 2), the other three bands the normal 1",
    }, {
      "name" = "diaReaction",
      "values" = { -10, -10, 0, 0, 0 },
      "default" = 0,
      "comment" = "the reaction modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -10 reaction modifier (pinned as a percentage, the diaReactionPenaltyPct const) applies to all encounters in the ill omen and great danger bands; the other bands carry none",
    }, {
      "name" = "diaTravel",
      "values" = { 0, 0, 0, 1, 1 },
      "default" = 0,
      "comment" = "the travel rate boost by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the favorable and auspicious bands travel at half again their normal traveling rate that day (pinned 1, the +50 percent riding the diaTravelBoostPct const); the other bands carry none",
    } },
  "tables" = { {
      "name" = "diaT63Grid",
      "tag" = "T63Data",
      "count" = "diaBandCount",
      "col_default" = 0,
      "cols" = { "diaPartyHit", "diaPartySave", "diaFoeHit", "diaEncMult", "diaReaction", "diaTravel" },
      "col_comments" = { "the party to hit modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -1 applies only in the ill omen band, and there only if the advice is ignored (the diaIllOmenIgnorePenalty pin); the other bands carry no party to hit modifier", "the party saving throw modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -1 in the ill omen band (again only if the advice is ignored) and the +1 in the auspicious band; great danger, neutral and favorable carry none", "the foe to hit modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the adversaries gain +1 in the great danger band and suffer -1 against the characters in the favorable and auspicious bands; the ill omen and neutral bands carry none", "the encounter chance multiplier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the chance for encounters is doubled in the ill omen and great danger bands (pinned 2), the other three bands the normal 1", "the reaction modifier by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the -10 reaction modifier (pinned as a percentage, the diaReactionPenaltyPct const) applies to all encounters in the ill omen and great danger bands; the other bands carry none", "the travel rate boost by band (print p. 117; compressed pp. 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3 favorable, 4 auspicious - the favorable and auspicious bands travel at half again their normal traveling rate that day (pinned 1, the +50 percent riding the diaTravelBoostPct const); the other bands carry none" },
      "data" = { { -1, -1, 0, 2, -10, 0 }, { 0, 0, 1, 2, -10, 0 }, { 0, 0, 0, 1, 0, 0 }, { 0, 0, -1, 1, 0, 1 }, { 0, 1, -1, 1, 0, 1 } },
      "comment" = "the Table 63 divination results band grid (print p. 117; compressed pp. 59-60)",
      "audit_comment" = "the divination results grid: the party, foe, encounter, reaction, save and travel modifiers by omen band",
    } },
  "chains" = { {
      "name" = "diaOmenBand",
      "arg" = "d",
      "limits" = { 2, 4, 7, 9 },
      "tail" = 4,
      "comment" = "the 1d10 roll mapped to its band (print p. 117; compressed pp. 59-60): 1-2 the ill omen band 0, 3-4 the great danger band 1, 5-7 the neutral band 2, 8-9 the favorable band 3, 10 the auspicious band 4",
    } },
  "examples" = { {
      "expr" = "m['diaBandCount']() != 5  or m['diaDieFaces']() != 10  or m['diaNeutralFaces']() != 3  or m['diaIllOmenBand']() != 0  or m['diaGreatDangerBand']() != 1  or m['diaNeutralBand']() != 2  or m['diaFavorableBand']() != 3  or m['diaAuspiciousBand']() != 4  or m['diaDoubledEncounterBands']() != 2  or m['diaReactionPenaltyPct']() != 10  or m['diaFavorableSaveBonus']() != 1  or m['diaTravelBoostPct']() != 50  or m['diaIllOmenIgnorePenalty']() != 1  or m['diaOmenWeeklyLimit']() != 1",
      "note" = "",
    }, {
      "expr" = "m['diaOmenBand'](1) != 0  or m['diaOmenBand'](2) != 0  or m['diaOmenBand'](4) != 1  or m['diaOmenBand'](3) != 1  or m['diaOmenBand'](7) != 2  or m['diaOmenBand'](5) != 2  or m['diaOmenBand'](9) != 3  or m['diaOmenBand'](8) != 3  or m['diaOmenBand'](10) != 4",
      "note" = "the diaOmenBand band-for boundaries",
    }, {
      "expr" = "m['diaBandCount']() != 5  or m['diaDieFaces']() != 10  or m['diaNeutralFaces']() != 3  or m['diaDoubledEncounterBands']() != 2",
      "note" = "the count pins - five bands, the 1d10 faces, the neutral band the widest at three faces, the two doubled encounter bands",
    }, {
      "expr" = "m['diaIllOmenBand']() != 0  or m['diaGreatDangerBand']() != 1  or m['diaNeutralBand']() != 2  or m['diaFavorableBand']() != 3  or m['diaAuspiciousBand']() != 4",
      "note" = "the band ordinal pins - ill omen 0, great danger 1, neutral 2, favorable 3, auspicious 4",
    }, {
      "expr" = "m['diaOmenBand'](1) != 0  or m['diaOmenBand'](2) != 0  or m['diaOmenBand'](3) != 1  or m['diaOmenBand'](4) != 1  or m['diaOmenBand'](5) != 2  or m['diaOmenBand'](7) != 2  or m['diaOmenBand'](8) != 3  or m['diaOmenBand'](9) != 3  or m['diaOmenBand'](10) != 4",
      "note" = "the chain pins - the die roll mapped to its band: 1 and 2 the ill omen band 0, 3 and 4 the great danger band 1, 5 through 7 the neutral band 2, 8 and 9 the favorable band 3, 10 the auspicious band 4",
    }, {
      "expr" = "m['diaPartyHit'](0) != -1  or m['diaPartySave'](0) != -1  or m['diaPartySave'](4) != 1  or m['diaPartyHit'](1) != 0  or m['diaPartySave'](1) != 0  or m['diaPartyHit'](2) != 0  or m['diaPartySave'](3) != 0",
      "note" = "the party modifier pins - the ill omen to hit and save penalties (the ignored advice); the auspicious save bonus; great danger, neutral and favorable carry none",
    }, {
      "expr" = "m['diaFoeHit'](1) != 1  or m['diaFoeHit'](3) != -1  or m['diaFoeHit'](4) != -1  or m['diaFoeHit'](0) != 0  or m['diaFoeHit'](2) != 0",
      "note" = "the foe to hit pins - the adversaries +1 in the great danger band, -1 against the characters in the favorable and auspicious bands, none in the ill omen and neutral bands",
    }, {
      "expr" = "m['diaEncMult'](0) != 2  or m['diaEncMult'](1) != 2  or m['diaEncMult'](2) != 1  or m['diaEncMult'](3) != 1  or m['diaEncMult'](4) != 1  or m['diaReaction'](0) != -10  or m['diaReaction'](1) != -10  or m['diaReaction'](2) != 0  or m['diaReaction'](4) != 0",
      "note" = "the encounter and reaction pins - the chance doubled and the -10 reaction modifier in the ill omen and great danger bands, normal in the other three",
    }, {
      "expr" = "m['diaTravel'](3) != 1  or m['diaTravel'](4) != 1  or m['diaTravel'](0) != 0  or m['diaTravel'](2) != 0  or m['diaTravelBoostPct']() != 50  or m['diaReactionPenaltyPct']() != 10  or m['diaFavorableSaveBonus']() != 1  or m['diaIllOmenIgnorePenalty']() != 1",
      "note" = "the travel pins - the boost in the favorable and auspicious bands, none in the other three; the modifier consts - the +50 percent travel boost, the -10 reaction percentage, the auspicious save bonus and the ill omen ignored penalty",
    }, {
      "expr" = "m['diaOmenWeeklyLimit']() != 1",
      "note" = "the weekly limit pin - the omen spell usable once per week",
    } },
  "audit" = {
      "label" = "R666 OA divination results audit",
      "comment" = "OA round fifty-three (capture p. 117): Table 63 - the divination results of the omen spell, the five 1d10 bands with their mechanical modifiers, cross-checked between the passes",
    },
}
