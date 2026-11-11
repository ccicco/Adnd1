-- oa668: promoted from rules/oa/oat65fate.h (the TABLE 65 FATE, printed capture p. 135 - the OA fate round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 668,
  "prefix" = "oa668",
  "banner" = {
      "title" = "TABLE 65 FATE, printed capture p. 135 - the OA fate round",
      "provenance" = "census 590 -> 591.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print p. 135; compressed p. 66); the twelve band rows cross-checked line by line between the passes, zero contested reads - the outcome prose agrees verbatim. The table answers the fourth level fate spell, rolled when the DM knows of no particular event that will occur to the character. The outcomes are DM-adventure seeds - general statements whose value is narrative, so the cells pin the band STRUCTURE, not the prose: the bands pin as a chain (the 1d20 roll mapped to its band: rolls 1, 2, 3 the single-face bands, 4-5, 6-7, 8-9 and 16-17 the two-face pairs, 10-12 and 13-15 the three-face widest bands at the ladder middle, 18, 19 and 20 the single-face tail) and a one-column grid of the band face widths - six single-face, four two-face and two three-face bands summing to the twenty faces of the die. The one-fate-at-a-time rule pins as the didT65FateLimit const. The outcome names ride the column comment, the fate prose closes in its own round. The table tag T65Data identifier-safe per the R639 lesson  the gap census after this round: 121 closed, 114 open - the Table 65 Fate box flips (census 590 -> 591); the shukenja chapter boxes are ALL CLOSED - NEXT - R669: the wu jen spell chapter opens, Table 66 Wu Jen Spells (capture p. 153, the full spell list by level), prefix did (verified free - dic is NOT free: the dice() helpers), audit \"R669 OA wu jen spell list audit\"",
    },
  "consts" = { {
      "name" = "didT65BandCount",
      "value" = 12,
      "comment" = "the twelve fate bands (print p. 135; compressed p. 66)",
    }, {
      "name" = "didT65DieFaces",
      "value" = 20,
      "comment" = "the fate roll is 1d20, the table consulted when the DM knows of no particular event that will occur to the character (print p. 135; compressed p. 66)",
    }, {
      "name" = "didT65SingleFaceBands",
      "value" = 6,
      "comment" = "the six single-face bands - rolls 1, 2, 3, 18, 19 and 20 (print p. 135; compressed p. 66)",
    }, {
      "name" = "didT65TwoFaceBands",
      "value" = 4,
      "comment" = "the four two-face bands - rolls 4-5, 6-7, 8-9 and 16-17 (print p. 135; compressed p. 66)",
    }, {
      "name" = "didT65WidestBands",
      "value" = 3,
      "comment" = "the face width of the two widest bands - rolls 10-12 and 13-15, three faces each (print p. 135; compressed p. 66)",
    }, {
      "name" = "didT65FateLimit",
      "value" = 1,
      "comment" = "a character can only have one fate at a time - once determined, the nature of the event cannot be changed (print p. 135; compressed p. 66)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "didT65Faces",
      "values" = { 1, 1, 1, 2, 2, 2, 3, 3, 2, 1, 1, 1 },
      "default" = 0,
      "comment" = "the fate band face widths by ordinal (print p. 135; compressed p. 66). The band list rides this comment: 0 roll 1, 1 roll 2, 2 roll 3, 3 rolls 4-5, 4 rolls 6-7, 5 rolls 8-9, 6 rolls 10-12, 7 rolls 13-15, 8 rolls 16-17, 9 roll 18, 10 roll 19, 11 roll 20 - the widths sum to the twenty faces of the die: six single-face bands at the ladder ends (rolls 1, 2, 3, 18, 19, 20), four two-face bands (rolls 4-5, 6-7, 8-9, 16-17) and the two three-face widest bands at the ladder middle (rolls 10-12 and 13-15). The outcomes themselves are prose - the DM-adventure seeds riding the printed table, not pinned cells",
    } },
  "tables" = { {
      "name" = "didT65Grid",
      "tag" = "T65Data",
      "count" = "didT65BandCount",
      "col_default" = 0,
      "cols" = { "didT65Faces" },
      "col_comments" = { "the fate band face widths by ordinal (print p. 135; compressed p. 66). The band list rides this comment: 0 roll 1, 1 roll 2, 2 roll 3, 3 rolls 4-5, 4 rolls 6-7, 5 rolls 8-9, 6 rolls 10-12, 7 rolls 13-15, 8 rolls 16-17, 9 roll 18, 10 roll 19, 11 roll 20 - the widths sum to the twenty faces of the die: six single-face bands at the ladder ends (rolls 1, 2, 3, 18, 19, 20), four two-face bands (rolls 4-5, 6-7, 8-9, 16-17) and the two three-face widest bands at the ladder middle (rolls 10-12 and 13-15). The outcomes themselves are prose - the DM-adventure seeds riding the printed table, not pinned cells" },
      "data" = { { 1 }, { 1 }, { 1 }, { 2 }, { 2 }, { 2 }, { 3 }, { 3 }, { 2 }, { 1 }, { 1 }, { 1 } },
      "comment" = "the Table 65 fate band grid (print p. 135; compressed p. 66)",
      "audit_comment" = "the fate grid: the band face widths by ordinal - the outcome prose is narrative, not pinned cells",
    } },
  "chains" = { {
      "name" = "didT65FateBand",
      "arg" = "d",
      "limits" = { 1, 2, 3, 5, 7, 9, 12, 15, 17, 18, 19 },
      "tail" = 11,
      "comment" = "the 1d20 fate roll mapped to its band (print p. 135; compressed p. 66): 1 band 0, 2 band 1, 3 band 2, 4-5 band 3, 6-7 band 4, 8-9 band 5, 10-12 band 6, 13-15 band 7, 16-17 band 8, 18 band 9, 19 band 10, 20 band 11",
    } },
  "examples" = { {
      "expr" = "m['didT65BandCount']() != 12  or m['didT65DieFaces']() != 20  or m['didT65SingleFaceBands']() != 6  or m['didT65TwoFaceBands']() != 4  or m['didT65WidestBands']() != 3  or m['didT65FateLimit']() != 1",
      "note" = "",
    }, {
      "expr" = "m['didT65FateBand'](0) != 0  or m['didT65FateBand'](1) != 0  or m['didT65FateBand'](2) != 1  or m['didT65FateBand'](2) != 1  or m['didT65FateBand'](3) != 2  or m['didT65FateBand'](3) != 2  or m['didT65FateBand'](5) != 3  or m['didT65FateBand'](4) != 3  or m['didT65FateBand'](7) != 4  or m['didT65FateBand'](6) != 4  or m['didT65FateBand'](9) != 5  or m['didT65FateBand'](8) != 5  or m['didT65FateBand'](12) != 6  or m['didT65FateBand'](10) != 6  or m['didT65FateBand'](15) != 7  or m['didT65FateBand'](13) != 7  or m['didT65FateBand'](17) != 8  or m['didT65FateBand'](16) != 8  or m['didT65FateBand'](18) != 9  or m['didT65FateBand'](18) != 9  or m['didT65FateBand'](19) != 10  or m['didT65FateBand'](19) != 10  or m['didT65FateBand'](20) != 11",
      "note" = "the didT65FateBand band-for boundaries",
    }, {
      "expr" = "m['didT65BandCount']() != 12  or m['didT65DieFaces']() != 20  or m['didT65SingleFaceBands']() != 6  or m['didT65TwoFaceBands']() != 4  or m['didT65WidestBands']() != 3  or m['didT65FateLimit']() != 1",
      "note" = "the count pins - twelve bands, the 1d20 faces, the six single-face and four two-face bands, the three-face widest bands, the one-fate limit",
    }, {
      "expr" = "m['didT65FateBand'](1) != 0  or m['didT65FateBand'](2) != 1  or m['didT65FateBand'](3) != 2  or m['didT65FateBand'](4) != 3  or m['didT65FateBand'](5) != 3  or m['didT65FateBand'](7) != 4  or m['didT65FateBand'](9) != 5  or m['didT65FateBand'](12) != 6  or m['didT65FateBand'](15) != 7  or m['didT65FateBand'](17) != 8  or m['didT65FateBand'](18) != 9  or m['didT65FateBand'](19) != 10  or m['didT65FateBand'](20) != 11",
      "note" = "the chain pins - the 1d20 roll mapped to its band: rolls 1, 2 and 3 the bands 0-2, the paired bands through 17, the single-face tail bands 18, 19 and 20",
    }, {
      "expr" = "m['didT65Faces'](0) != 1  or m['didT65Faces'](2) != 1  or m['didT65Faces'](9) != 1  or m['didT65Faces'](11) != 1  or m['didT65Faces'](3) != 2  or m['didT65Faces'](5) != 2  or m['didT65Faces'](8) != 2  or m['didT65Faces'](6) != 3  or m['didT65Faces'](7) != 3",
      "note" = "the width grid pins - the six single-face ladder ends, the four two-face pairs, the two three-face widest bands",
    }, {
      "expr" = "m['didT65Faces'](0) +m['didT65Faces'](1) +m['didT65Faces'](2) != 3  or m['didT65Faces'](3) +m['didT65Faces'](4) +m['didT65Faces'](5) != 6  or m['didT65Faces'](6) +m['didT65Faces'](7) != 6  or m['didT65Faces'](8) != 2  or m['didT65Faces'](9) +m['didT65Faces'](10) +m['didT65Faces'](11) != 3  or m['didT65DieFaces']() != 20",
      "note" = "the width sum pins - the widths sum to the twenty faces of the die, checked as the ladder-end, pair and widest subtotals",
    }, {
      "expr" = "m['didT65SingleFaceBands']() != 6  or m['didT65TwoFaceBands']() != 4  or m['didT65WidestBands']() != 3",
      "note" = "the band census pins - the count of one-face and two-face bands matches the consts, checked band by band",
    } },
  "audit" = {
      "label" = "R668 OA fate audit",
      "comment" = "OA round fifty-five (capture p. 135): Table 65 - the fate table of the fourth level fate spell, the twelve 1d20 bands with their face widths, cross-checked between the passes",
    },
}
