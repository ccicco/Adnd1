-- oa771: promoted from rules/oa/oa142celestial.h (the OA OPEN BOXES SWEEP - THE CELESTIAL EMPEROR AND THE CELESTIAL BUREAUCRACY,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 771,
  "prefix" = "oa771",
  "banner" = {
      "title" = "OA OPEN BOXES SWEEP - THE CELESTIAL EMPEROR AND THE CELESTIAL BUREAUCRACY,",
      "provenance" = "printed capture p. 253 - the spirit-world framing doctrine census 693 -> 694.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift (the p. 253 text re-captured at p. 117 of the compressed-3 re-upload)  the gap census after this round: 234 closed, 1 open - the Celestial Emperor box and the eight missed parents of Chapters 2, 3, 8, 9, 10, 11, 12, 13 flip (census 693 -> 694); NEXT - R772: the Weapons prose arc (capture pp. 84-93, the weapon descriptions, re-captured at pp. 42-51 of the compressed-3 re-upload) - the last open box, split into per-weapon rounds; prefix dnj (verify free at the landing), audit \"R772 OA Weapons prose audit\", include after rules/oa/oa142celestial.h",
    },
  "consts" = { {
      "name" = "dnhUnifiedWholeDoctrine",
      "value" = 1,
      "comment" = "the unified whole doctrine - unlike the west viewing non-human creatures as a loose collection with no unity, the Oriental mind has organized the world into a unified whole (print capture p. 253)",
    }, {
      "name" = "dnhBureaucracyDutiesCount",
      "value" = 3,
      "comment" = "the bureaucracy duties count - the spirit officials receive and carry out orders, punish the wicked, and file reports of their activities, three duties (print capture p. 253)",
    }, {
      "name" = "dnhEmperorHeadsBureaucracy",
      "value" = 1,
      "comment" = "the emperor heads bureaucracy - the Celestial Emperor, a powerful being, heads the Celestial Bureaucracy, a type of government of the spirits (print capture p. 253)",
    }, {
      "name" = "dnhSpiritsHoldOffices",
      "value" = 1,
      "comment" = "the spirits hold offices - many spirit creatures come under his command and hold offices or positions within the Celestial Bureaucracy (print capture p. 253)",
    }, {
      "name" = "dnhChasingLungRainDuty",
      "value" = 1,
      "comment" = "the chasing lung rain duty - the chasing lung (river dragons) given the duty of making rain (print capture p. 253)",
    }, {
      "name" = "dnhMinistryOfThunderChain",
      "value" = 1,
      "comment" = "the ministry of thunder chain - the chasing lung report to the Ministry of Thunder, who in turn reports to the Celestial Emperor (print capture p. 253)",
    }, {
      "name" = "dnhSpiritOfficialCharacterCount",
      "value" = 4,
      "comment" = "the spirit official character count - like the bureaucrats of the real world the spirit officials can be corrupt, disobedient, just, or incompetent, four characters (print capture p. 253)",
    }, {
      "name" = "dnhOfficialsLikeRealBureaucrats",
      "value" = 1,
      "comment" = "the officials like real bureaucrats - the spirit officials can be corrupt, disobedient, just, or incompetent, like the bureaucrats of the real world (print capture p. 253)",
    }, {
      "name" = "dnhAnnualExamination",
      "value" = 1,
      "comment" = "the annual examination - the spirit officials can be replaced, each year their activities and behavior examined by their superiors (print capture p. 253)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnhBureaucracyDutiesCount']() != 3  or m['dnhSpiritOfficialCharacterCount']() != 4  or  m['dnhUnifiedWholeDoctrine']() != 1  or  m['dnhEmperorHeadsBureaucracy']() != 1  or  m['dnhSpiritsHoldOffices']() != 1  or  m['dnhChasingLungRainDuty']() != 1  or  m['dnhMinistryOfThunderChain']() != 1  or  m['dnhOfficialsLikeRealBureaucrats']() != 1  or  m['dnhAnnualExamination']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dnhUnifiedWholeDoctrine']() != 1  or m['dnhEmperorHeadsBureaucracy']() != 1",
      "note" = "the unified whole example",
    }, {
      "expr" = "m['dnhBureaucracyDutiesCount']() != 3  or m['dnhSpiritsHoldOffices']() != 1",
      "note" = "the offices example",
    }, {
      "expr" = "m['dnhChasingLungRainDuty']() != 1  or m['dnhMinistryOfThunderChain']() != 1",
      "note" = "the chain example",
    }, {
      "expr" = "m['dnhSpiritOfficialCharacterCount']() != 4  or m['dnhOfficialsLikeRealBureaucrats']() != 1",
      "note" = "the character example",
    }, {
      "expr" = "m['dnhAnnualExamination']() != 1",
      "note" = "the examination example",
    } },
  "audit" = {
      "label" = "R771 OA open boxes audit",
      "comment" = "OA round one hundred fifty-eight (capture p. 253): the open-boxes sweep - the Celestial Emperor and the Celestial Bureaucracy spirit-world framing doctrine, with the eight missed chapter parents of Chapters 2, 3, 8, 9, 10, 11, 12, and 13 closed; the Weapons prose box stays open for its own arc, single-pass pins per the R679 provenance shift",
    },
}
