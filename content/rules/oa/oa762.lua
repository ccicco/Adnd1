-- oa762: promoted from rules/oa/oa133tulung.h (the OA SETTING - THE TU LUNG EMPIRE, printed capture pp. 303-304 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 762,
  "prefix" = "oa762",
  "banner" = {
      "title" = "OA SETTING - THE TU LUNG EMPIRE, printed capture pp. 303-304 - the",
      "provenance" = "breakaway state of the Earth Dragon census 684 -> 685.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 215 closed, 20 open - the Tu Lung box flips (census 684 -> 685); NEXT - R763: Wa (capture p. 304), prefix dly (verify free at the landing), audit \"R763 OA Wa audit\", include after rules/oa/oa133tulung.h",
    },
  "consts" = { {
      "name" = "dlxEarthDragon",
      "value" = 1,
      "comment" = "the earth dragon - the empire name Tu Lung meaning Earth Dragon (print capture p. 303)",
    }, {
      "name" = "dlxPartOfShouLung",
      "value" = 1,
      "comment" = "the part of Shou Lung - Tu Lung was part of Shou Lung until the succession dispute (print capture p. 303)",
    }, {
      "name" = "dlxYearsSinceSplit",
      "value" = 300,
      "comment" = "the years since the split - Tu Lung part of Shou Lung until a dispute over imperial succession 300 years ago (print capture p. 303)",
    }, {
      "name" = "dlxOwnEmperorSeparateCourt",
      "value" = 1,
      "comment" = "the own emperor separate court - claiming its own emperor, Tu Lung set up a separate imperial court (print capture p. 303)",
    }, {
      "name" = "dlxWarsStabilized",
      "value" = 1,
      "comment" = "the wars stabilized - after many wars between the two states, the situation has stabilized (print capture p. 303)",
    }, {
      "name" = "dlxNoLoveLost",
      "value" = 1,
      "comment" = "the no love lost - no love is lost between the two empires (print capture p. 303)",
    }, {
      "name" = "dlxRebelNoblesGreatPower",
      "value" = 1,
      "comment" = "the rebel nobles great power - the Emperor of Tu Lung was supported by the powerful officials and nobles of the rebelling provinces, leading to their acquiring great power and strength (print capture p. 303)",
    }, {
      "name" = "dlxModeledAfterShouLung",
      "value" = 1,
      "comment" = "the modeled after Shou Lung - although the government is modeled after that of Shou Lung (print capture p. 303)",
    }, {
      "name" = "dlxLuiDynasty",
      "value" = 1,
      "comment" = "the Lui dynasty - the Emperor of Tu Lung of the Lui Dynasty (print capture p. 303)",
    }, {
      "name" = "dlxEmperorCannotBreakNobles",
      "value" = 1,
      "comment" = "the emperor cannot break the nobles - the Emperor has never been able to break the power of his nobles (print capture p. 303)",
    }, {
      "name" = "dlxNoblesControlExaminations",
      "value" = 1,
      "comment" = "the nobles control the examinations - the nobles control the examination system (print capture p. 303)",
    }, {
      "name" = "dlxOfficesHereditary",
      "value" = 1,
      "comment" = "the offices hereditary - the nobles arranged for various offices to become hereditary (print capture p. 303)",
    }, {
      "name" = "dlxEstatesExemptEdicts",
      "value" = 1,
      "comment" = "the estates exempt from edicts - the noble power allowed them to exempt their estates from most imperial edicts, including taxation (print capture p. 303)",
    }, {
      "name" = "dlxMajorityConsent",
      "value" = 1,
      "comment" = "the majority consent - the Emperor can only enforce his edicts with the consent of the majority of the nobles (print capture p. 303)",
    }, {
      "name" = "dlxCommonersLittleChance",
      "value" = 1,
      "comment" = "the commoners little chance - commoners have little chance to rise in the government (print capture p. 303)",
    }, {
      "name" = "dlxPostCorruption",
      "value" = 1,
      "comment" = "the post corruption - corruption of official posts is common (print capture p. 303)",
    }, {
      "name" = "dlxProvinceCount",
      "value" = 6,
      "comment" = "the province count - Tu Lung divided into six provinces (print capture p. 303)",
    }, {
      "name" = "dlxHereditaryGovernors",
      "value" = 1,
      "comment" = "the hereditary governors - each of the six provinces administered by a hereditary governor (print capture p. 303)",
    }, {
      "name" = "dlxDistrictsFamilyGraft",
      "value" = 1,
      "comment" = "the districts family and graft - the provinces divided into districts, official positions assigned on the basis of family and graft (print capture p. 303)",
    }, {
      "name" = "dlxInheritedPublicWorks",
      "value" = 1,
      "comment" = "the inherited public works - although Tu Lung inherited the public works of Shou Lung (print capture p. 303)",
    }, {
      "name" = "dlxWorksPoorlyMaintained",
      "value" = 1,
      "comment" = "the works poorly maintained - the public works poorly maintained and new projects seldom undertaken (print capture p. 303)",
    }, {
      "name" = "dlxPeopleEasilyOppressed",
      "value" = 1,
      "comment" = "the people easily oppressed - the people easily oppressed, having no recourse to the law (print capture p. 303)",
    }, {
      "name" = "dlxCapitalPlotting",
      "value" = 1,
      "comment" = "the capital plotting - the prime activity in the capital Chia Wan Chuan is political plotting (print capture p. 303 and p. 304)",
    }, {
      "name" = "dlxSecretSocieties",
      "value" = 1,
      "comment" = "the secret societies - many of the nobles of Tu Lung are leaders of secret societies pledged to overthrow the Emperor (print capture p. 304)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlxYearsSinceSplit']() != 300  or m['dlxProvinceCount']() != 6  or  m['dlxEarthDragon']() != 1  or  m['dlxPartOfShouLung']() != 1  or  m['dlxOwnEmperorSeparateCourt']() != 1  or  m['dlxWarsStabilized']() != 1  or  m['dlxNoLoveLost']() != 1  or  m['dlxRebelNoblesGreatPower']() != 1  or  m['dlxModeledAfterShouLung']() != 1  or  m['dlxLuiDynasty']() != 1  or  m['dlxEmperorCannotBreakNobles']() != 1  or  m['dlxNoblesControlExaminations']() != 1  or  m['dlxOfficesHereditary']() != 1  or  m['dlxEstatesExemptEdicts']() != 1  or  m['dlxMajorityConsent']() != 1  or  m['dlxCommonersLittleChance']() != 1  or  m['dlxPostCorruption']() != 1  or  m['dlxHereditaryGovernors']() != 1  or  m['dlxDistrictsFamilyGraft']() != 1  or  m['dlxInheritedPublicWorks']() != 1  or  m['dlxWorksPoorlyMaintained']() != 1  or  m['dlxPeopleEasilyOppressed']() != 1  or  m['dlxCapitalPlotting']() != 1  or  m['dlxSecretSocieties']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlxEarthDragon']() != 1  or m['dlxPartOfShouLung']() != 1  or m['dlxYearsSinceSplit']() != 300  or m['dlxOwnEmperorSeparateCourt']() != 1",
      "note" = "the founding example",
    }, {
      "expr" = "m['dlxWarsStabilized']() != 1  or m['dlxNoLoveLost']() != 1  or m['dlxRebelNoblesGreatPower']() != 1",
      "note" = "the wars example",
    }, {
      "expr" = "m['dlxModeledAfterShouLung']() != 1  or m['dlxLuiDynasty']() != 1  or m['dlxEmperorCannotBreakNobles']() != 1",
      "note" = "the government example",
    }, {
      "expr" = "m['dlxNoblesControlExaminations']() != 1  or m['dlxOfficesHereditary']() != 1  or m['dlxEstatesExemptEdicts']() != 1  or m['dlxMajorityConsent']() != 1",
      "note" = "the noble power example",
    }, {
      "expr" = "m['dlxCommonersLittleChance']() != 1  or m['dlxPostCorruption']() != 1",
      "note" = "the commoner example",
    }, {
      "expr" = "m['dlxProvinceCount']() != 6  or m['dlxHereditaryGovernors']() != 1  or m['dlxDistrictsFamilyGraft']() != 1",
      "note" = "the administration example",
    }, {
      "expr" = "m['dlxInheritedPublicWorks']() != 1  or m['dlxWorksPoorlyMaintained']() != 1  or m['dlxPeopleEasilyOppressed']() != 1",
      "note" = "the works example",
    }, {
      "expr" = "m['dlxCapitalPlotting']() != 1  or m['dlxSecretSocieties']() != 1",
      "note" = "the capital example",
    } },
  "audit" = {
      "label" = "R762 OA Tu Lung audit",
      "comment" = "OA round one hundred forty-nine (capture pp. 303-304): the Tu Lung empire - the Earth Dragon, the succession break of 300 years ago, the Lui Dynasty, the noble control of the examinations, the six provinces, the capital Chia Wan Chuan, single-pass pins per the R679 provenance shift",
    },
}
