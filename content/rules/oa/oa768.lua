-- oa768: promoted from rules/oa/oa139manners.h (the OA DAILY LIFE - MANNERS, printed capture p. 312 - the politeness, the bow,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 768,
  "prefix" = "oa768",
  "banner" = {
      "title" = "OA DAILY LIFE - MANNERS, printed capture p. 312 - the politeness, the bow,",
      "provenance" = "and the insult census 690 -> 691.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 221 closed, 14 open - the Manners box flips (census 690 -> 691); NEXT - R769: Names (capture pp. 312-313), prefix dme (verify free at the landing), audit \"R769 OA Daily Life Names audit\", include after rules/oa/oa139manners.h",
    },
  "consts" = { {
      "name" = "dmdExtraordinarilyPolite",
      "value" = 1,
      "comment" = "the extraordinarily polite - the people of Kara-Tur, as noticed by the gajin, extraordinarily polite as a rule, going to meticulous pains to behave in the correct manner (print capture p. 312)",
    }, {
      "name" = "dmdMannersAsCrime",
      "value" = 1,
      "comment" = "the manners as crime - among the higher classes incorrect or poor manners virtually as great a crime as murder, severe punishments for those who knowingly or unknowingly commit a social faux pas (print capture p. 312)",
    }, {
      "name" = "dmdClassMarkersAndRidicule",
      "value" = 1,
      "comment" = "the class markers and ridicule - correct manners mark the differences between social classes and help prevent embarrassing oneself in public, there being no greater sin than to be laughed at by others (print capture p. 312)",
    }, {
      "name" = "dmdHonorRidiculeMechanic",
      "value" = 1,
      "comment" = "the honor ridicule mechanic - the concern over insults to honor and the risk of public ridicule prompts the politeness; the DM may cause player characters to lose honor when they would bring themselves ridicule, characters cannot be cavalier in their attitude (print capture p. 312)",
    }, {
      "name" = "dmdBowMeasuresRespect",
      "value" = 1,
      "comment" = "the bow measures respect - the bow the most obvious expression of manners, not just a way of saying Hello, it measures the respect one has for the person bowed to (print capture p. 312)",
    }, {
      "name" = "dmdLowerBowsDeeper",
      "value" = 1,
      "comment" = "the lower bows deeper - those of lower status bow lower to their superiors than their superiors do to them, a high ranking official perhaps barely nodding to those under him (print capture p. 312)",
    }, {
      "name" = "dmdKowtowDeference",
      "value" = 1,
      "comment" = "the kowtow deference - the greatest deference is the kowtow, kneeling and touching the head to the floor, normally done only in the presence of emperors and extremely powerful lords, sometimes necessary when apologizing or begging forgiveness (print capture p. 312)",
    }, {
      "name" = "dmdKowtowExtremeAct",
      "value" = 1,
      "comment" = "the kowtow extreme act - except in the presence of a powerful lord, kowtowing is an extreme act, representing the debasement and surrender of the person to another (print capture p. 312)",
    }, {
      "name" = "dmdInsultSubjectsCount",
      "value" = 9,
      "comment" = "the insult subjects count - comments about a person honor, courage, dislikes, fears, family, dress, behavior, friends, and even possessions can be cause for insult, nine subjects (print capture p. 312)",
    }, {
      "name" = "dmdIgnorableJestInsults",
      "value" = 2,
      "comment" = "the ignorable jest insults - truly generous people might ignore one or two insults spoken in jest, but no more (print capture p. 312)",
    }, {
      "name" = "dmdWordsCanInsult",
      "value" = 1,
      "comment" = "the words can insult - manners extend to what one says; statements, even spoken in jest, can be insulting and offensive (print capture p. 312)",
    }, {
      "name" = "dmdInsultsSeldomLight",
      "value" = 1,
      "comment" = "the insults seldom light - insults are seldom taken lightly, even the generous unable to abide more than a jest or two (print capture p. 312)",
    }, {
      "name" = "dmdPoliteConversation",
      "value" = 1,
      "comment" = "the polite conversation - to prevent insults, conversations are often stilted or phrased in extremely polite terms to avoid offence (print capture p. 312)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmdInsultSubjectsCount']() != 9  or m['dmdIgnorableJestInsults']() != 2  or  m['dmdExtraordinarilyPolite']() != 1  or  m['dmdMannersAsCrime']() != 1  or  m['dmdClassMarkersAndRidicule']() != 1  or  m['dmdHonorRidiculeMechanic']() != 1  or  m['dmdBowMeasuresRespect']() != 1  or  m['dmdLowerBowsDeeper']() != 1  or  m['dmdKowtowDeference']() != 1  or  m['dmdKowtowExtremeAct']() != 1  or  m['dmdWordsCanInsult']() != 1  or  m['dmdInsultsSeldomLight']() != 1  or  m['dmdPoliteConversation']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmdExtraordinarilyPolite']() != 1  or m['dmdMannersAsCrime']() != 1",
      "note" = "the politeness example",
    }, {
      "expr" = "m['dmdClassMarkersAndRidicule']() != 1  or m['dmdHonorRidiculeMechanic']() != 1",
      "note" = "the ridicule example",
    }, {
      "expr" = "m['dmdBowMeasuresRespect']() != 1  or m['dmdLowerBowsDeeper']() != 1",
      "note" = "the bow example",
    }, {
      "expr" = "m['dmdKowtowDeference']() != 1  or m['dmdKowtowExtremeAct']() != 1",
      "note" = "the kowtow example",
    }, {
      "expr" = "m['dmdInsultSubjectsCount']() != 9  or m['dmdWordsCanInsult']() != 1",
      "note" = "the words example",
    }, {
      "expr" = "m['dmdIgnorableJestInsults']() != 2  or m['dmdInsultsSeldomLight']() != 1  or m['dmdPoliteConversation']() != 1",
      "note" = "the jest example",
    } },
  "audit" = {
      "label" = "R768 OA Daily Life Manners audit",
      "comment" = "OA round one hundred fifty-five (capture p. 312): the Chapter 15 Manners - the extraordinary politeness, the manners-as-crime doctrine, the bow and the kowtow, the insult and the polite conversation, single-pass pins per the R679 provenance shift",
    },
}
