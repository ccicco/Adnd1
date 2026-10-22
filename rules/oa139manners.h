// =========================================================================================
// Adnd1 - rules/oa139manners.h
// OA DAILY LIFE - MANNERS, printed capture p. 312 - the politeness, the bow,
// and the insult
// census 690 -> 691.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 221 closed, 14 open - the Manners box
// flips (census 690 -> 691); NEXT - R769: Names (capture pp. 312-313), prefix
// dme (verify free at the landing), audit "R769 OA Daily Life Names audit",
// include after rules/oa139manners.h
//
namespace rules {

// ---- the politeness doctrine ----

// the extraordinarily polite - the people of Kara-Tur, as noticed by the
// gajin, extraordinarily polite as a rule, going to meticulous pains to
// behave in the correct manner (print capture p. 312)
inline int dmdExtraordinarilyPolite()
    { return 1; }

// the manners as crime - among the higher classes incorrect or poor manners
// virtually as great a crime as murder, severe punishments for those who
// knowingly or unknowingly commit a social faux pas (print capture p. 312)
inline int dmdMannersAsCrime()
    { return 1; }

// the class markers and ridicule - correct manners mark the differences
// between social classes and help prevent embarrassing oneself in public,
// there being no greater sin than to be laughed at by others (print capture
// p. 312)
inline int dmdClassMarkersAndRidicule()
    { return 1; }

// the honor ridicule mechanic - the concern over insults to honor and the
// risk of public ridicule prompts the politeness; the DM may cause player
// characters to lose honor when they would bring themselves ridicule,
// characters cannot be cavalier in their attitude (print capture p. 312)
inline int dmdHonorRidiculeMechanic()
    { return 1; }

// ---- the bow ----

// the bow measures respect - the bow the most obvious expression of manners,
// not just a way of saying Hello, it measures the respect one has for the
// person bowed to (print capture p. 312)
inline int dmdBowMeasuresRespect()
    { return 1; }

// the lower bows deeper - those of lower status bow lower to their superiors
// than their superiors do to them, a high ranking official perhaps barely
// nodding to those under him (print capture p. 312)
inline int dmdLowerBowsDeeper()
    { return 1; }

// the kowtow deference - the greatest deference is the kowtow, kneeling and
// touching the head to the floor, normally done only in the presence of
// emperors and extremely powerful lords, sometimes necessary when apologizing
// or begging forgiveness (print capture p. 312)
inline int dmdKowtowDeference()
    { return 1; }

// the kowtow extreme act - except in the presence of a powerful lord,
// kowtowing is an extreme act, representing the debasement and surrender of
// the person to another (print capture p. 312)
inline int dmdKowtowExtremeAct()
    { return 1; }

// ---- the insult ----

// the insult subjects count - comments about a person honor, courage,
// dislikes, fears, family, dress, behavior, friends, and even possessions can
// be cause for insult, nine subjects (print capture p. 312)
inline int dmdInsultSubjectsCount()
    { return 9; }

// the ignorable jest insults - truly generous people might ignore one or two
// insults spoken in jest, but no more (print capture p. 312)
inline int dmdIgnorableJestInsults()
    { return 2; }

// the words can insult - manners extend to what one says; statements, even
// spoken in jest, can be insulting and offensive (print capture p. 312)
inline int dmdWordsCanInsult()
    { return 1; }

// the insults seldom light - insults are seldom taken lightly, even the
// generous unable to abide more than a jest or two (print capture p. 312)
inline int dmdInsultsSeldomLight()
    { return 1; }

// the polite conversation - to prevent insults, conversations are often
// stilted or phrased in extremely polite terms to avoid offence (print
// capture p. 312)
inline int dmdPoliteConversation()
    { return 1; }

}   // namespace rules
