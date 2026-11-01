-- oa764: promoted from rules/oa135kozakura.h (the OA SETTING - THE ISLAND OF KOZAKURA, printed capture p. 304 - the turbulent);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 764,
  "prefix" = "oa764",
  "banner" = {
      "title" = "OA SETTING - THE ISLAND OF KOZAKURA, printed capture p. 304 - the turbulent",
      "provenance" = "land of the daimyo wars census 686 -> 687.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 217 closed, 18 open - the Kozakura box flips (census 686 -> 687); NEXT - R765: Gajin (capture p. 304), prefix dma (verify free at the landing), audit \"R765 OA Gajin audit\", include after rules/oa135kozakura.h",
    },
  "consts" = { {
      "name" = "dlzLittleCherryBlossomName",
      "value" = 1,
      "comment" = "the Little Cherry Blossom name - Kozakura, meaning Little Cherry Blossom (print capture p. 304)",
    }, {
      "name" = "dlzSameRaceAsWa",
      "value" = 1,
      "comment" = "the same race as Wa - inhabited by the same race of people as found on Wa (print capture p. 304)",
    }, {
      "name" = "dlzSharedCustomsTraditions",
      "value" = 1,
      "comment" = "the shared customs and traditions - Kozakura shares virtually the same customs and traditions as Wa (print capture p. 304)",
    }, {
      "name" = "dlzFarFromUnifiedState",
      "value" = 1,
      "comment" = "the far from unified state - Kozakura is far from a unified state (print capture p. 304)",
    }, {
      "name" = "dlzIncessantDaimyoWarfare",
      "value" = 1,
      "comment" = "the incessant daimyo warfare - for several centuries the scene of incessant warfare between powerful daimyos (print capture p. 304)",
    }, {
      "name" = "dlzShogunTitleStruggle",
      "value" = 1,
      "comment" = "the shogun title struggle - all the daimyos struggling to gain the title of shogun (print capture p. 304)",
    }, {
      "name" = "dlzFiefsAndEstatesRule",
      "value" = 1,
      "comment" = "the fiefs and estates rule - the island divided into fiefs and estates, ruled by the daimyos (print capture p. 304)",
    }, {
      "name" = "dlzTurbulentFortunes",
      "value" = 1,
      "comment" = "the turbulent fortunes - a very turbulent place where fortunes and might can be achieved by those of even the most common upbringing (print capture p. 304)",
    }, {
      "name" = "dlzAdventurerHaven",
      "value" = 1,
      "comment" = "the adventurer haven - the perfect place for the adventurer seeking fame and fortune (print capture p. 304)",
    }, {
      "name" = "dlzStruggleSides",
      "value" = 2,
      "comment" = "the struggle sides - the raging struggle has two sides, the daimyos who support the emperor and the remains of the bakufu (print capture p. 304)",
    }, {
      "name" = "dlzEmperorRegainsPower",
      "value" = 1,
      "comment" = "the emperor regains power - the daimyos who support the emperor in his bid to regain his long-lost political power (print capture p. 304)",
    }, {
      "name" = "dlzBakufuRemainsOppose",
      "value" = 1,
      "comment" = "the bakufu remains oppose - the remains of the bakufu, the shogunal government, on the other side of the struggle (print capture p. 304)",
    }, {
      "name" = "dlzFamiliesAlliedEachSide",
      "value" = 1,
      "comment" = "the families allied to each side - each side attempting to ally the remaining families on the island (print capture p. 304)",
    }, {
      "name" = "dlzLoyaltyOrPowerMotive",
      "value" = 1,
      "comment" = "the loyalty or power motive - some families joining out of loyalty, others seeing the chance to amass more power themselves (print capture p. 304)",
    }, {
      "name" = "dlzAlliedToBothSides",
      "value" = 1,
      "comment" = "the allied to both sides - some families arranging to be allied to both sides so they cannot lose (print capture p. 304)",
    }, {
      "name" = "dlzWarriorMostRespected",
      "value" = 1,
      "comment" = "the warrior most respected - the warrior the most respected and powerful class (print capture p. 304)",
    }, {
      "name" = "dlzLacksRigidLaws",
      "value" = 1,
      "comment" = "the lacks rigid laws - Kozakura lacks the rigid laws of Wa (print capture p. 304)",
    }, {
      "name" = "dlzPeasantRisenToLord",
      "value" = 1,
      "comment" = "the peasant risen to lord - more than once a humble peasant risen to powerful lord through his military skill (print capture p. 304)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlzStruggleSides']() != 2  or  m['dlzLittleCherryBlossomName']() != 1  or  m['dlzSameRaceAsWa']() != 1  or  m['dlzSharedCustomsTraditions']() != 1  or  m['dlzFarFromUnifiedState']() != 1  or  m['dlzIncessantDaimyoWarfare']() != 1  or  m['dlzShogunTitleStruggle']() != 1  or  m['dlzFiefsAndEstatesRule']() != 1  or  m['dlzTurbulentFortunes']() != 1  or  m['dlzAdventurerHaven']() != 1  or  m['dlzEmperorRegainsPower']() != 1  or  m['dlzBakufuRemainsOppose']() != 1  or  m['dlzFamiliesAlliedEachSide']() != 1  or  m['dlzLoyaltyOrPowerMotive']() != 1  or  m['dlzAlliedToBothSides']() != 1  or  m['dlzWarriorMostRespected']() != 1  or  m['dlzLacksRigidLaws']() != 1  or  m['dlzPeasantRisenToLord']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlzLittleCherryBlossomName']() != 1  or m['dlzSameRaceAsWa']() != 1  or m['dlzSharedCustomsTraditions']() != 1",
      "note" = "the island example",
    }, {
      "expr" = "m['dlzFarFromUnifiedState']() != 1  or m['dlzIncessantDaimyoWarfare']() != 1  or m['dlzShogunTitleStruggle']() != 1",
      "note" = "the wars example",
    }, {
      "expr" = "m['dlzFiefsAndEstatesRule']() != 1  or m['dlzTurbulentFortunes']() != 1  or m['dlzAdventurerHaven']() != 1",
      "note" = "the fief example",
    }, {
      "expr" = "m['dlzStruggleSides']() != 2  or m['dlzEmperorRegainsPower']() != 1  or m['dlzBakufuRemainsOppose']() != 1",
      "note" = "the struggle example",
    }, {
      "expr" = "m['dlzFamiliesAlliedEachSide']() != 1  or m['dlzLoyaltyOrPowerMotive']() != 1  or m['dlzAlliedToBothSides']() != 1",
      "note" = "the families example",
    }, {
      "expr" = "m['dlzWarriorMostRespected']() != 1  or m['dlzLacksRigidLaws']() != 1  or m['dlzPeasantRisenToLord']() != 1",
      "note" = "the warrior example",
    } },
  "audit" = {
      "label" = "R764 OA Kozakura audit",
      "comment" = "OA round one hundred fifty-one (capture p. 304): the island of Kozakura - the Little Cherry Blossom, the same race and customs as Wa, the incessant daimyo warfare for the shogun title, the adventurer haven, the emperor against the bakufu, the families allied to both sides, the peasant risen to lord, single-pass pins per the R679 provenance shift",
    },
}
