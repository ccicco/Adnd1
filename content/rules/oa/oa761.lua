-- oa761: promoted from rules/oa/oa132shoulung.h (the OA SETTING - THE SHOU LUNG EMPIRE, printed capture p. 303 - the largest and);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 761,
  "prefix" = "oa761",
  "banner" = {
      "title" = "OA SETTING - THE SHOU LUNG EMPIRE, printed capture p. 303 - the largest and",
      "provenance" = "most powerful empire of Kara-Tur census 683 -> 684.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 214 closed, 21 open - the Shou Lung box flips (census 683 -> 684); NEXT - R762: Tu Lung (capture p. 303), prefix dlx (verify free at the landing), audit \"R762 OA Tu Lung audit\", include after rules/oa/oa132shoulung.h",
    },
  "consts" = { {
      "name" = "dlwReceiverOfTheDragon",
      "value" = 1,
      "comment" = "the receiver of the dragon - the empire name Shou Lung meaning Receiver of the Dragon (print capture p. 303)",
    }, {
      "name" = "dlwLargestMostPowerful",
      "value" = 1,
      "comment" = "the largest and most powerful empire of Kara-Tur (print capture p. 303)",
    }, {
      "name" = "dlwOldestState",
      "value" = 1,
      "comment" = "the oldest state of Kara-Tur (print capture p. 303)",
    }, {
      "name" = "dlwYearsOfState",
      "value" = 1200,
      "comment" = "the years of the state - Shou Lung in existence over 1,200 years in one form or another, the oldest state of Kara-Tur (print capture p. 303)",
    }, {
      "name" = "dlwEmperorAllHistory",
      "value" = 1,
      "comment" = "the emperor all history - ruled by an emperor for all of its history (print capture p. 303)",
    }, {
      "name" = "dlwTurmoilPeriods",
      "value" = 1,
      "comment" = "the turmoil periods - the few periods of turmoil the exception to the imperial rule (print capture p. 303)",
    }, {
      "name" = "dlwKuoDynastyChin",
      "value" = 1,
      "comment" = "the Kuo dynasty Chin - the head and center of the state the current emperor Chin of the Kuo Dynasty (print capture p. 303)",
    }, {
      "name" = "dlwDynastyCount",
      "value" = 8,
      "comment" = "the dynasty count - the Kuo Dynasty of emperor Chin the eighth dynasty to rule the land (print capture p. 303)",
    }, {
      "name" = "dlwExaminedBureaucracy",
      "value" = 1,
      "comment" = "the examined bureaucracy - manned by thousands of officials major and minor chosen by a system of examinations given throughout the land (print capture p. 303)",
    }, {
      "name" = "dlwCommonerRise",
      "value" = 1,
      "comment" = "the commoner rise - even the poorest commoner can rise to an influential position provided he is talented enough and studies hard (print capture p. 303)",
    }, {
      "name" = "dlwProvinceCount",
      "value" = 14,
      "comment" = "the province count - Shou Lung divided into 14 provinces, each headed by a governor (print capture p. 303)",
    }, {
      "name" = "dlwGovernorPerProvince",
      "value" = 1,
      "comment" = "the governor per province - each of the 14 provinces headed by a governor (print capture p. 303)",
    }, {
      "name" = "dlwDistrictOwnOfficial",
      "value" = 1,
      "comment" = "the district own official - the provinces divided into districts each with its own official (print capture p. 303)",
    }, {
      "name" = "dlwOfficialDuties",
      "value" = 1,
      "comment" = "the official duties - at each level the officials responsible for the management of those beneath them, the hearing of court cases, keeping the peace, the collection of taxes, and the construction of public works (print capture p. 303)",
    }, {
      "name" = "dlwRoadsAndBridges",
      "value" = 1,
      "comment" = "the roads and bridges - the well-maintained network connecting the provinces, creating a regular flow of trade between them (print capture p. 303)",
    }, {
      "name" = "dlwImperialMessengers",
      "value" = 1,
      "comment" = "the imperial messengers - the extensive network stationed at depots throughout the land to carry news to and from the capital city Tien Shih (print capture p. 303)",
    }, {
      "name" = "dlwDikesAndDams",
      "value" = 1,
      "comment" = "the dikes and dams - extensive areas built along the major rivers to reduce the risk of flooding (print capture p. 303)",
    }, {
      "name" = "dlwCoinageAndPaper",
      "value" = 1,
      "comment" = "the coinage and paper - regular coinage and paper money minted and honored throughout the land (print capture p. 303)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlwYearsOfState']() != 1200  or m['dlwDynastyCount']() != 8  or m['dlwProvinceCount']() != 14  or  m['dlwReceiverOfTheDragon']() != 1  or  m['dlwLargestMostPowerful']() != 1  or  m['dlwOldestState']() != 1  or  m['dlwEmperorAllHistory']() != 1  or  m['dlwTurmoilPeriods']() != 1  or  m['dlwKuoDynastyChin']() != 1  or  m['dlwExaminedBureaucracy']() != 1  or  m['dlwCommonerRise']() != 1  or  m['dlwGovernorPerProvince']() != 1  or  m['dlwDistrictOwnOfficial']() != 1  or  m['dlwOfficialDuties']() != 1  or  m['dlwRoadsAndBridges']() != 1  or  m['dlwImperialMessengers']() != 1  or  m['dlwDikesAndDams']() != 1  or  m['dlwCoinageAndPaper']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlwReceiverOfTheDragon']() != 1  or m['dlwLargestMostPowerful']() != 1  or m['dlwOldestState']() != 1  or m['dlwYearsOfState']() != 1200",
      "note" = "the standing example",
    }, {
      "expr" = "m['dlwEmperorAllHistory']() != 1  or m['dlwTurmoilPeriods']() != 1  or m['dlwKuoDynastyChin']() != 1  or m['dlwDynastyCount']() != 8",
      "note" = "the throne example",
    }, {
      "expr" = "m['dlwExaminedBureaucracy']() != 1  or m['dlwCommonerRise']() != 1",
      "note" = "the bureaucracy example",
    }, {
      "expr" = "m['dlwProvinceCount']() != 14  or m['dlwGovernorPerProvince']() != 1  or m['dlwDistrictOwnOfficial']() != 1  or m['dlwOfficialDuties']() != 1",
      "note" = "the administration example",
    }, {
      "expr" = "m['dlwRoadsAndBridges']() != 1  or m['dlwImperialMessengers']() != 1  or m['dlwDikesAndDams']() != 1  or m['dlwCoinageAndPaper']() != 1",
      "note" = "the infrastructure example",
    } },
  "audit" = {
      "label" = "R761 OA Shou Lung audit",
      "comment" = "OA round one hundred forty-eight (capture p. 303): the Shou Lung empire - the Receiver of the Dragon, the oldest state of over 1,200 years, the Chin emperor of the Kuo Dynasty the eighth, the examination bureaucracy with the commoner rise, the fourteen provinces and the districts, the roads and bridges, the Imperial Messengers of Tien Shih, the dikes and dams, the coinage and paper money, single-pass pins per the Chapter 9 provenance shift",
    },
}
