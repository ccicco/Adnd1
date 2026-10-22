// =========================================================================================
// Adnd1 - rules/oa132shoulung.h
// OA SETTING - THE SHOU LUNG EMPIRE, printed capture p. 303 - the largest and
// most powerful empire of Kara-Tur
// census 683 -> 684.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 214 closed, 21 open - the Shou Lung box
// flips (census 683 -> 684); NEXT - R762: Tu Lung (capture p. 303), prefix
// dlx (verify free at the landing), audit "R762 OA Tu Lung audit", include
// after rules/oa132shoulung.h
//
namespace rules {

// ---- the empire standing ----

// the receiver of the dragon - the empire name Shou Lung meaning Receiver of
// the Dragon (print capture p. 303)
inline int dlwReceiverOfTheDragon()
    { return 1; }

// the largest and most powerful empire of Kara-Tur (print capture p. 303)
inline int dlwLargestMostPowerful()
    { return 1; }

// the oldest state of Kara-Tur (print capture p. 303)
inline int dlwOldestState()
    { return 1; }

// the years of the state - Shou Lung in existence over 1,200 years in one
// form or another, the oldest state of Kara-Tur (print capture p. 303)
inline int dlwYearsOfState()
    { return 1200; }

// ---- the throne and the dynasty ----

// the emperor all history - ruled by an emperor for all of its history (print
// capture p. 303)
inline int dlwEmperorAllHistory()
    { return 1; }

// the turmoil periods - the few periods of turmoil the exception to the
// imperial rule (print capture p. 303)
inline int dlwTurmoilPeriods()
    { return 1; }

// the Kuo dynasty Chin - the head and center of the state the current emperor
// Chin of the Kuo Dynasty (print capture p. 303)
inline int dlwKuoDynastyChin()
    { return 1; }

// the dynasty count - the Kuo Dynasty of emperor Chin the eighth dynasty to
// rule the land (print capture p. 303)
inline int dlwDynastyCount()
    { return 8; }

// ---- the bureaucracy ----

// the examined bureaucracy - manned by thousands of officials major and minor
// chosen by a system of examinations given throughout the land (print capture
// p. 303)
inline int dlwExaminedBureaucracy()
    { return 1; }

// the commoner rise - even the poorest commoner can rise to an influential
// position provided he is talented enough and studies hard (print capture p.
// 303)
inline int dlwCommonerRise()
    { return 1; }

// ---- the provincial administration ----

// the province count - Shou Lung divided into 14 provinces, each headed by a
// governor (print capture p. 303)
inline int dlwProvinceCount()
    { return 14; }

// the governor per province - each of the 14 provinces headed by a governor
// (print capture p. 303)
inline int dlwGovernorPerProvince()
    { return 1; }

// the district own official - the provinces divided into districts each with
// its own official (print capture p. 303)
inline int dlwDistrictOwnOfficial()
    { return 1; }

// the official duties - at each level the officials responsible for the
// management of those beneath them, the hearing of court cases, keeping the
// peace, the collection of taxes, and the construction of public works (print
// capture p. 303)
inline int dlwOfficialDuties()
    { return 1; }

// ---- the infrastructure ----

// the roads and bridges - the well-maintained network connecting the
// provinces, creating a regular flow of trade between them (print capture p.
// 303)
inline int dlwRoadsAndBridges()
    { return 1; }

// the imperial messengers - the extensive network stationed at depots
// throughout the land to carry news to and from the capital city Tien Shih
// (print capture p. 303)
inline int dlwImperialMessengers()
    { return 1; }

// the dikes and dams - extensive areas built along the major rivers to reduce
// the risk of flooding (print capture p. 303)
inline int dlwDikesAndDams()
    { return 1; }

// the coinage and paper - regular coinage and paper money minted and honored
// throughout the land (print capture p. 303)
inline int dlwCoinageAndPaper()
    { return 1; }

}   // namespace rules
