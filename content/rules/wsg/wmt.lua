-- wmt: promoted from tools/spec_r446.json (the The WSG THE MOUNTAINEERING PROFICIENCY, R446: the mountaineer prose (no table this round) - a proficient character is only slightly more accomplished than any other non-thief on most non-horizontal surfaces where his special equipment offers no advantage, but when a difficult surface must be ascended or descended his presence can mean the difference between life and death. The essential tools and skills: PITONS, specially crafted metal spikes pounded into small cracks and fissures in a rock face to provide an anchor for a line - they are NOT used as handholds or footholds (uncomfortable at best, dangerous at worst, the surface area of a secured piton is not very large); a SPECIAL HAMMER to pound them in (a weapon hammer is the wrong material and too unwieldy to swing perched on a cliff); and the KNOWLEDGE of where to place them so they hold and give the greatest support - anyone can drive a piton into a crack, but only a mountaineer can tell which cracks will not widen or crumble. One mountaineer enables everyone else in the group to ascend or descend a surface they could not climb without him, as long as all the characters are roped together and the mountaineer is in the lead. Pitons also serve as a backup for a belayer, an anchor for someone rappelling, and a place to tie a rope before crossing a chasm. No matter the use or the strain, a piton has only a 10% chance of coming loose, checked the FIRST time it supports 100 pounds or more (simply pulling the rope does not count); a piton that passes stays lodged until a mountaineer dislodges it with his hammer - and there is a 10% chance any secured piton cannot be dislodged and must be left behind. Census 370 -> 371.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 446,
  "prefix" = "wmt",
  "banner" = {
      "title" = "The WSG THE MOUNTAINEERING PROFICIENCY, R446: the mountaineer prose (no table this round) - a proficient character is only slightly more accomplished than any other non-thief on most non-horizontal surfaces where his special equipment offers no advantage, but when a difficult surface must be ascended or descended his presence can mean the difference between life and death. The essential tools and skills: PITONS, specially crafted metal spikes pounded into small cracks and fissures in a rock face to provide an anchor for a line - they are NOT used as handholds or footholds (uncomfortable at best, dangerous at worst, the surface area of a secured piton is not very large); a SPECIAL HAMMER to pound them in (a weapon hammer is the wrong material and too unwieldy to swing perched on a cliff); and the KNOWLEDGE of where to place them so they hold and give the greatest support - anyone can drive a piton into a crack, but only a mountaineer can tell which cracks will not widen or crumble. One mountaineer enables everyone else in the group to ascend or descend a surface they could not climb without him, as long as all the characters are roped together and the mountaineer is in the lead. Pitons also serve as a backup for a belayer, an anchor for someone rappelling, and a place to tie a rope before crossing a chasm. No matter the use or the strain, a piton has only a 10% chance of coming loose, checked the FIRST time it supports 100 pounds or more (simply pulling the rope does not count); a piton that passes stays lodged until a mountaineer dislodges it with his hammer - and there is a 10% chance any secured piton cannot be dislodged and must be left behind. Census 370 -> 371.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 39; the user own copy OCR cross-checked against the archive djvu word layer (Guide_0039.djvu) - the section reads CLEAN, every number (the two 10 percent chances and the 100-pound first-check threshold) matched exactly; no eye-reads were needed.",
      "sentinel" = "A piton has a 10% chance of coming loose, checked the first time it supports 100 pounds or more; a passed check stays lodged until a mountaineer dislodges it - and a secured piton has a 10% chance of refusing to come out at all and being left behind.",
    },
  "consts" = { {
      "name" = "wmtLoosenPct",
      "value" = 10,
      "comment" = "No matter what a piton is used for or how much strain is put on it, there is only a 10% chance that it will come loose.",
    }, {
      "name" = "wmtFirstCheckLbs",
      "value" = 100,
      "comment" = "The loosen chance is checked the first time the piton is called upon to support a weight of 100 pounds or more; simply pulling on the rope will not dislodge a piton or indicate whether it has a chance of coming loose.",
    }, {
      "name" = "wmtStuckPct",
      "value" = 10,
      "comment" = "There is a 10% chance that any secured piton will not be able to be dislodged and must be left behind.",
    } },
  "bools" = { {
      "name" = "wmtSlightlyBetterWithoutGear",
      "value" = true,
      "comment" = "A character with proficiency in mountaineering is only slightly more accomplished than any other non-thief at climbing or traversing most non-horizontal surfaces where his special equipment is not needed or offers no advantage.",
    }, {
      "name" = "wmtLifeAndDeathOnDifficult",
      "value" = true,
      "comment" = "When a difficult surface must be ascended or descended by members of an adventuring party, the presence of a mountaineer can mean the difference between life and death.",
    }, {
      "name" = "wmtPitonsAreAnchorsNotHolds",
      "value" = true,
      "comment" = "Pitons are specially crafted metal spikes pounded into small cracks and fissures in a rock face to provide an anchor for a line - contrary to popular conception, they are NOT used as handholds or footholds: uncomfortable at best, dangerous at worst, since the surface area of a secured piton is not very large.",
    }, {
      "name" = "wmtSpecialHammerRequired",
      "value" = true,
      "comment" = "A special hammer is used to pound the pitons into the rock face; a hammer that serves as a weapon will not do - wrong material, and far too unwieldy to swing while perched on the side of a cliff.",
    }, {
      "name" = "wmtPlacementKnowledge",
      "value" = true,
      "comment" = "The third essential skill is the knowledge of where to place the pitons so they hold and give the greatest support - anyone, conceivably, can drive a piton into a crack, but only a mountaineer can tell which cracks will not widen or crumble so the piton has only a small chance of coming loose.",
    }, {
      "name" = "wmtLeadsRopedGroup",
      "value" = true,
      "comment" = "One mountaineer in a group can enable everyone else to ascend or descend a surface they could not climb without him, as long as all the characters are roped together and the mountaineer is in the lead.",
    }, {
      "name" = "wmtPitonBackupForBelayer",
      "value" = true,
      "comment" = "A piton will serve as a backup for a belayer, provide an anchor for someone rappelling, or serve as a place to tie a rope before crossing a chasm.",
    }, {
      "name" = "wmtPassedCheckStaysLodged",
      "value" = true,
      "comment" = "If the piton passes the first loosen check, it will remain lodged until a mountaineer dislodges it with his hammer.",
    }, {
      "name" = "wmtStuckMustBeLeftBehind",
      "value" = true,
      "comment" = "There is a 10% chance that any secured piton will not be able to be dislodged and must be left behind.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wmtLoosenPct']() != 10 or m['wmtStuckPct']() != 10",
      "note" = "the two piton chances: a 10% come-loose chance on the first load, and a 10% cannot-be-dislodged chance on removal",
    }, {
      "expr" = "m['wmtFirstCheckLbs']() != 100",
      "note" = "the first-check threshold: the loosen chance is checked the first time the piton supports 100 pounds or more",
    }, {
      "expr" = "m['wmtLoosenPct']() != m['wmtStuckPct']() or m['wmtFirstCheckLbs']() != 10 * m['wmtLoosenPct']()",
      "note" = "the piton arithmetic anchor: the two chances are equal at 10, and the 100-pound threshold is ten times the loosen percentage",
    } },
  "audit" = {
      "label" = "R446 WSG mountaineering pin audit",
      "comment" = "The mountaineering slice pins the essential tools and skills (pitons - metal spikes pounded into cracks for a line anchor, never handholds or footholds; the special hammer, a weapon hammer will not do; the placement knowledge only a mountaineer has), the mountaineer-led roped ascent (one mountaineer enables the whole group on a surface they could not climb, if all are roped together and he leads), the piton-as-anchor uses (a belayer backup, a rappel anchor, a chasm-crossing tie point), and the piton loosen rules (a 10% come-loose chance, checked the first time it supports 100 pounds or more; a passed check stays lodged until a mountaineer dislodges it; a 10% chance a secured piton cannot be dislodged and must be left behind) (rules/wsgmntnr.h, prefix wmt); census 370 -> 371.",
    },
}
