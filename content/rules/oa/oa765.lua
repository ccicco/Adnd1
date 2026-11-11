-- oa765: promoted from rules/oa/oa136gajin.h (the OA SETTING - THE GAJIN DOCTRINE, printed capture p. 304 - the insular lands);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 765,
  "prefix" = "oa765",
  "banner" = {
      "title" = "OA SETTING - THE GAJIN DOCTRINE, printed capture p. 304 - the insular lands",
      "provenance" = "and the outside barbarians census 687 -> 688.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 218 closed, 17 open - the Gajin box flips (census 687 -> 688); NEXT - R766: Food (capture p. 307, the Chapter 15 daily-life opener), prefix dmb (verify free at the landing), audit \"R766 OA Daily Life Food audit\", include after rules/oa/oa136gajin.h",
    },
  "consts" = { {
      "name" = "dmaOutsideClassesIntroduced",
      "value" = 1,
      "comment" = "the outside classes introduced - players who already have the AD&D game rules may want to introduce character classes from these worlds into the lands of Oriental Adventures (print capture p. 304)",
    }, {
      "name" = "dmaLandsVeryDifferent",
      "value" = 1,
      "comment" = "the lands very different - these lands are very different from those of the standard classes (print capture p. 304)",
    }, {
      "name" = "dmaInsularClosedLands",
      "value" = 1,
      "comment" = "the insular closed lands - the lands described in this book are insular and closed, avoiding contact with the outside world when possible (print capture p. 304)",
    }, {
      "name" = "dmaTradeInfrequentControlled",
      "value" = 1,
      "comment" = "the trade infrequent and controlled - trade exists with the outside world but is infrequent and carefully controlled (print capture p. 304)",
    }, {
      "name" = "dmaRoutesVanishDanger",
      "value" = 1,
      "comment" = "the routes vanish danger - many ply the sea lanes and caravan routes with gold and treasures only to disappear at the hands of bandits or other, more cruel, dangers (print capture p. 304)",
    }, {
      "name" = "dmaStandardClassCount",
      "value" = 4,
      "comment" = "the standard class count - the standard classes of fighter, magic user, cleric, and thief, four classes (print capture p. 304)",
    }, {
      "name" = "dmaPeculiarTraitsCount",
      "value" = 2,
      "comment" = "the peculiar traits count - the result of the separation has left the inhabitants with two peculiar traits (print capture p. 304)",
    }, {
      "name" = "dmaSeparationTraitsResult",
      "value" = 1,
      "comment" = "the separation traits result - the result of this separation has left the inhabitants with peculiar traits (print capture p. 304)",
    }, {
      "name" = "dmaLackOfCuriosity",
      "value" = 1,
      "comment" = "the lack of curiosity - the first trait is a lack of curiosity about the rest of the world (print capture p. 304)",
    }, {
      "name" = "dmaHostileBarbariansView",
      "value" = 1,
      "comment" = "the hostile barbarians view - to most people of the Oriental lands the outside world is filled with rude and hostile barbarians (print capture p. 304)",
    }, {
      "name" = "dmaGajinName",
      "value" = 1,
      "comment" = "the gajin name - the rude and hostile barbarians of the outside world are known as gajin (print capture p. 304)",
    }, {
      "name" = "dmaGajinNotDealtWith",
      "value" = 1,
      "comment" = "the gajin not dealt with - as such they are not dealt with (print capture p. 304)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmaStandardClassCount']() != 4  or m['dmaPeculiarTraitsCount']() != 2  or  m['dmaOutsideClassesIntroduced']() != 1  or  m['dmaLandsVeryDifferent']() != 1  or  m['dmaInsularClosedLands']() != 1  or  m['dmaTradeInfrequentControlled']() != 1  or  m['dmaRoutesVanishDanger']() != 1  or  m['dmaSeparationTraitsResult']() != 1  or  m['dmaLackOfCuriosity']() != 1  or  m['dmaHostileBarbariansView']() != 1  or  m['dmaGajinName']() != 1  or  m['dmaGajinNotDealtWith']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmaOutsideClassesIntroduced']() != 1  or m['dmaLandsVeryDifferent']() != 1",
      "note" = "the classes example",
    }, {
      "expr" = "m['dmaInsularClosedLands']() != 1  or m['dmaTradeInfrequentControlled']() != 1",
      "note" = "the insular example",
    }, {
      "expr" = "m['dmaRoutesVanishDanger']() != 1",
      "note" = "the routes example",
    }, {
      "expr" = "m['dmaStandardClassCount']() != 4  or m['dmaPeculiarTraitsCount']() != 2  or m['dmaSeparationTraitsResult']() != 1",
      "note" = "the separation example",
    }, {
      "expr" = "m['dmaLackOfCuriosity']() != 1",
      "note" = "the curiosity example",
    }, {
      "expr" = "m['dmaHostileBarbariansView']() != 1  or m['dmaGajinName']() != 1  or m['dmaGajinNotDealtWith']() != 1",
      "note" = "the gajin example",
    } },
  "audit" = {
      "label" = "R765 OA Gajin audit",
      "comment" = "OA round one hundred fifty-two (capture p. 304): the gajin doctrine - the outside classes into the insular lands, the carefully controlled trade, the two peculiar traits of the separation, the rude and hostile barbarians known as gajin and not dealt with, single-pass pins per the R679 provenance shift",
    },
}
