-- ua: promoted from rules/uamoves.h (the The UA APPENDIX S MOVE values);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 411,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA APPENDIX S MOVE values",
      "provenance" = "(pp. 110-120), R411: the 23 deity block movement rates - the last numeric remainder in Appendix S (the pantheon prose alone stays open). The clean djvu scan carries all 23 lines; the systematic OCR reads resolve: the label colon dot (\"MOVE;\" reads \"MOVE:\"), the quote forms rendering as apostrophes, back-ticks and dashes (MOVE: 12', 18', 12- all read the printed inch mark; the parentheticals 48/24/36/36/12 are all multiples of 12.  The hole: the Shargaas line garbles (\"MOVE: 78-\") with no independent confirmation - the value records as the hole sentinel, never a guess.  The sanity ladders: every clean base is a multiple of 3; every printed alternate is a multiple of 12.",
    },
  "consts" = { {
      "name" = "umvMoveCount",
      "value" = 23,
      "comment" = "",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "umvMove",
      "comment" = "The 23 MOVE lines, in the R406 roster order.",
      "kind" = "header pin",
      "body" = "static const UmvMove T[23] = { { 12, 0, false }, { 18, 0, false }, { 9, 48, false }, { 12, 0, false }, { 12, 0, false }, { 48, 0, true }, { 18, 0, false }, { 15, 0, false }, { 12, 0, false }, { 12, 0, false }, { 9, 24, false }, { 12, 0, false }, { 12, 0, false }, { 12, 0, false }, { 15, 0, false }, { 12, 36, false }, { 9, 36, false }, { 6, 0, false }, { 9, 0, false }, { -1, 0, false }, { 12, 0, false }, { 6, 0, false }, { 15, 12, false }, }; if (i < 0) i = 0; if (i > 22) i = 22; return T[i];",
    }, {
      "name" = "umvAltCount",
      "comment" = "The alternate census (the lines printing a parenthetical): 5 - Dumathoin 48, Sheela 24, Urdlen 36, Segojan 36, Luthic 12.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (umvMove(i).alt > 0) ++n; return n;",
    }, {
      "name" = "umvBaseSum",
      "comment" = "The base sum over the clean rows (the hole excluded): a drift in ANY clean base cell moves it.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) { const UmvMove& m = umvMove(i); if (m.base != UMV_MOVE_HOLE) n += m.base; } return n;",
    }, {
      "name" = "umvBasesAreMultiplesOf3",
      "comment" = "True when every clean base is a multiple of 3 (the sanity ladder; the hole excluded).",
      "kind" = "header pin",
      "body" = "for (int i = 0; i < 23; ++i) { const UmvMove& m = umvMove(i); if (m.base == UMV_MOVE_HOLE) continue; if (m.base <= 0 || m.base % 3) return false; } return true;",
    }, {
      "name" = "umvAltsAreMultiplesOf12",
      "comment" = "True when every printed alternate is a multiple of 12 (the sanity ladder).",
      "kind" = "header pin",
      "body" = "for (int i = 0; i < 23; ++i) { const UmvMove& m = umvMove(i); if (m.alt > 0 && m.alt % 12) return false; } return true;",
    }, {
      "name" = "umvAerdrieFlightOnly",
      "comment" = "The flight-only flag: the Aerdrie 48 reads flight only.",
      "kind" = "header pin",
      "body" = "return umvMove(5).flightOnly;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['umvMoveCount']() != 23  or m['umvAltCount']() != 5  or m['umvBaseSum']() != 297  or  m['umvBasesAreMultiplesOf3']() != 1  or  m['umvAltsAreMultiplesOf12']() != 1  or  m['umvAerdrieFlightOnly']() != 1",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['umvMove'](0).flightOnly  or m['umvMove'](2).flightOnly  or m['umvMove'](14).flightOnly  or m['umvMove'](19).flightOnly  or m['umvMove'](22).flightOnly  or m['umvMove'](19).base != UMV_MOVE_HOLE  or m['umvMove'](0).base != 12  or m['umvMove'](0).alt != 0  or m['umvMove'](1).base != 18  or m['umvMove'](1).alt != 0  or m['umvMove'](2).base != 9  or m['umvMove'](2).alt != 48  or m['umvMove'](3).base != 12  or m['umvMove'](3).alt != 0  or m['umvMove'](4).base != 12  or m['umvMove'](4).alt != 0  or m['umvMove'](5).base != 48  or m['umvMove'](5).alt != 0  or m['umvMove'](6).base != 18  or m['umvMove'](6).alt != 0  or m['umvMove'](7).base != 15  or m['umvMove'](7).alt != 0  or m['umvMove'](8).base != 12  or m['umvMove'](8).alt != 0  or m['umvMove'](9).base != 12  or m['umvMove'](9).alt != 0  or m['umvMove'](10).base != 9  or m['umvMove'](10).alt != 24  or m['umvMove'](11).base != 12  or m['umvMove'](11).alt != 0  or m['umvMove'](12).base != 12  or m['umvMove'](12).alt != 0  or m['umvMove'](13).base != 12  or m['umvMove'](13).alt != 0  or m['umvMove'](14).base != 15  or m['umvMove'](14).alt != 0  or m['umvMove'](15).base != 12  or m['umvMove'](15).alt != 36  or m['umvMove'](16).base != 9  or m['umvMove'](16).alt != 36  or m['umvMove'](17).base != 6  or m['umvMove'](17).alt != 0  or m['umvMove'](18).base != 9  or m['umvMove'](18).alt != 0  or m['umvMove'](20).base != 12  or m['umvMove'](20).alt != 0  or m['umvMove'](21).base != 6  or m['umvMove'](21).alt != 0  or m['umvMove'](22).base != 15  or m['umvMove'](22).alt != 12",
      "note" = "the flight flag rides the Aerdrie row ALONE",
    } },
  "audit" = {
      "label" = "R411: the UA Appendix S MOVE values pin audit",
      "comment" = "The 23 movement rates pin; the five parenthetical alternates pin (Dumathoin 48, Sheela 24, Urdlen 36, Segojan 36, Luthic 12); the Aerdrie flight-only flag pins; the Shargaas garble records as the hole sentinel (\"MOVE: 78-\", no independent confirmation); the sanity ladders run live (every clean base a multiple of 3, every alternate a multiple of 12); the base sum catches a drift in ANY clean cell; census 337 -> 338.",
    },
}
