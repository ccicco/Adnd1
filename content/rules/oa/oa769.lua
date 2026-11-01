-- oa769: promoted from rules/oa140names.h (the OA DAILY LIFE - NAMES, printed capture pp. 312-313 - the thirteen name);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 769,
  "prefix" = "oa769",
  "banner" = {
      "title" = "OA DAILY LIFE - NAMES, printed capture pp. 312-313 - the thirteen name",
      "provenance" = "types of the Oriental world census 691 -> 692.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 222 closed, 13 open - the Names box flips (census 691 -> 692); NEXT - R770: Back matter (capture pp. 313-314, the bibliography and the closing page), prefix dmf (verify free at the landing), audit \"R770 OA Back matter audit\", include after rules/oa140names.h",
    },
  "consts" = { {
      "name" = "dmeMinimumLifelongNames",
      "value" = 2,
      "comment" = "the minimum lifelong names - throughout the life of an Oriental character he can expect to use at least two different names, quite often more (print capture pp. 312-313)",
    }, {
      "name" = "dmeNameTypesCount",
      "value" = 13,
      "comment" = "the name types count - the listed types: the secret name, the childhood name, the adult name, the hereditary family name, the clan or tribe name, the place name, the nickname, the undesired-activity substitute name, the artist substitute name, the school or master substitute name, the religious name, the event names, and the posthumous name, thirteen types (print capture pp. 312-313)",
    }, {
      "name" = "dmeWesternSingleName",
      "value" = 1,
      "comment" = "the western single name - in the west a given name stays for life with nicknames and aliases aside, changing a name a complicated legal matter implying a change of family and identity (print capture pp. 312-313)",
    }, {
      "name" = "dmeOrientalMultipleNames",
      "value" = 1,
      "comment" = "the Oriental multiple names - in the Oriental world the situation much different, each name valid for the person depending on his age and situation, aliases also used to keep the identity secret (print capture pp. 312-313)",
    }, {
      "name" = "dmeNamesDroppedWithNew",
      "value" = 1,
      "comment" = "the names dropped with new - players need not have names for all these instances and many names are dropped (such as a childhood name) when a new name is given (print capture pp. 312-313)",
    }, {
      "name" = "dmeSecretName",
      "value" = 1,
      "comment" = "the secret name - given at birth, never revealed, supposedly known only to the gods; superstition holds that learning the secret name of a person gives magical power over that person (print capture pp. 312-313)",
    }, {
      "name" = "dmeChildhoodName",
      "value" = 1,
      "comment" = "the childhood name - given at birth, used in daily life, distinctly different from adult names, making it easy to tell if a person has come of age (print capture pp. 312-313)",
    }, {
      "name" = "dmeAdultName",
      "value" = 1,
      "comment" = "the adult name - given at coming of age, showing the person a full adult with the inherent rights and responsibilities; once given, the childhood name seldom if ever used (print capture pp. 312-313)",
    }, {
      "name" = "dmeHereditaryFamilyName",
      "value" = 1,
      "comment" = "the hereditary family name - used in conjunction with the personal name, by no means universal, generally reserved for the upper classes and nobles; for the lower classes to attach a family name is insulting and above their station (print capture pp. 312-313)",
    }, {
      "name" = "dmeClanTribeName",
      "value" = 1,
      "comment" = "the clan tribe name - identifying the person by the group he belongs to, used by barbarian groups where tribal affiliation is extremely important (print capture pp. 312-313)",
    }, {
      "name" = "dmePlaceName",
      "value" = 1,
      "comment" = "the place name - acting in many ways like a hereditary family name, common among the common people, identifying the village, district, or province the person is from (print capture pp. 312-313)",
    }, {
      "name" = "dmeNickname",
      "value" = 1,
      "comment" = "the nickname - used much as in the west, to tell two people with the same name apart, as an honor, or to ridicule them (print capture pp. 312-313)",
    }, {
      "name" = "dmeSubstituteUndesiredName",
      "value" = 1,
      "comment" = "the substitute undesired name - for people of quality, craftsmen, or those working at unseemly or improper occupations; the closest name to an alias, yet it does not disguise the identity, it only protects the true name from connection with the undesired activity (print capture pp. 312-313)",
    }, {
      "name" = "dmeArtistPenName",
      "value" = 1,
      "comment" = "the artist pen name - a substitute name chosen by an artist because using the real name would be improper (associations with some powerful person or family) or to create a poetic allusion, a poet choosing a name derived from a great poet of the past (print capture pp. 312-313)",
    }, {
      "name" = "dmeSchoolMasterName",
      "value" = 1,
      "comment" = "the school master name - a substitute name chosen by an artist, craftsman, or warrior that shows his connection to some school or master (print capture pp. 312-313)",
    }, {
      "name" = "dmeReligiousName",
      "value" = 1,
      "comment" = "the religious name - taken upon entering the ranks of the priesthood, showing the person has severed his ties with his past life and become a new person, normally with special significance in the religion (print capture pp. 312-313)",
    }, {
      "name" = "dmeEventNames",
      "value" = 1,
      "comment" = "the event names - chosen by the person or given by another to tell of the deeds and exploits, coming and going depending on the whims and deeds of the person (print capture pp. 312-313)",
    }, {
      "name" = "dmePosthumousName",
      "value" = 1,
      "comment" = "the posthumous name - given shortly after burial, to protect and assist the departed person from evil influences (print capture pp. 312-313)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmeMinimumLifelongNames']() != 2  or m['dmeNameTypesCount']() != 13  or  m['dmeWesternSingleName']() != 1  or  m['dmeOrientalMultipleNames']() != 1  or  m['dmeNamesDroppedWithNew']() != 1  or  m['dmeSecretName']() != 1  or  m['dmeChildhoodName']() != 1  or  m['dmeAdultName']() != 1  or  m['dmeHereditaryFamilyName']() != 1  or  m['dmeClanTribeName']() != 1  or  m['dmePlaceName']() != 1  or  m['dmeNickname']() != 1  or  m['dmeSubstituteUndesiredName']() != 1  or  m['dmeArtistPenName']() != 1  or  m['dmeSchoolMasterName']() != 1  or  m['dmeReligiousName']() != 1  or  m['dmeEventNames']() != 1  or  m['dmePosthumousName']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmeMinimumLifelongNames']() != 2  or m['dmeWesternSingleName']() != 1  or m['dmeOrientalMultipleNames']() != 1",
      "note" = "the doctrine example",
    }, {
      "expr" = "m['dmeNameTypesCount']() != 13  or m['dmeNamesDroppedWithNew']() != 1",
      "note" = "the types example",
    }, {
      "expr" = "m['dmeSecretName']() != 1  or m['dmeChildhoodName']() != 1  or m['dmeAdultName']() != 1",
      "note" = "the life names example",
    }, {
      "expr" = "m['dmeHereditaryFamilyName']() != 1  or m['dmeClanTribeName']() != 1",
      "note" = "the family example",
    }, {
      "expr" = "m['dmePlaceName']() != 1  or m['dmeNickname']() != 1",
      "note" = "the place example",
    }, {
      "expr" = "m['dmeSubstituteUndesiredName']() != 1  or m['dmeArtistPenName']() != 1  or m['dmeSchoolMasterName']() != 1",
      "note" = "the substitute example",
    }, {
      "expr" = "m['dmeReligiousName']() != 1  or m['dmeEventNames']() != 1  or m['dmePosthumousName']() != 1",
      "note" = "the sacred example",
    } },
  "audit" = {
      "label" = "R769 OA Daily Life Names audit",
      "comment" = "OA round one hundred fifty-six (capture pp. 312-313): the Chapter 15 closer, Names - the western single name against the Oriental multiple names, the secret, childhood, adult, family, clan, place, nickname, substitute, religious, event, and posthumous names, single-pass pins per the R679 provenance shift",
    },
}
