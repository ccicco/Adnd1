// =========================================================================================
// Adnd1 - rules/oa142celestial.h
// OA OPEN BOXES SWEEP - THE CELESTIAL EMPEROR AND THE CELESTIAL BUREAUCRACY,
// printed capture p. 253 - the spirit-world framing doctrine
// census 693 -> 694.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift (the p. 253 text re-captured at p. 117 of the compressed-3
// re-upload)
//
// the gap census after this round: 234 closed, 1 open - the Celestial Emperor
// box and the eight missed parents of Chapters 2, 3, 8, 9, 10, 11, 12, 13
// flip (census 693 -> 694); NEXT - R772: the Weapons prose arc (capture pp.
// 84-93, the weapon descriptions, re-captured at pp. 42-51 of the
// compressed-3 re-upload) - the last open box, split into per-weapon rounds;
// prefix dnj (verify free at the landing), audit "R772 OA Weapons prose
// audit", include after rules/oa142celestial.h
//
namespace rules {

// ---- the unified whole ----

// the unified whole doctrine - unlike the west viewing non-human creatures as
// a loose collection with no unity, the Oriental mind has organized the world
// into a unified whole (print capture p. 253)
inline int dnhUnifiedWholeDoctrine()
    { return 1; }

// the bureaucracy duties count - the spirit officials receive and carry out
// orders, punish the wicked, and file reports of their activities, three
// duties (print capture p. 253)
inline int dnhBureaucracyDutiesCount()
    { return 3; }

// the emperor heads bureaucracy - the Celestial Emperor, a powerful being,
// heads the Celestial Bureaucracy, a type of government of the spirits (print
// capture p. 253)
inline int dnhEmperorHeadsBureaucracy()
    { return 1; }

// the spirits hold offices - many spirit creatures come under his command and
// hold offices or positions within the Celestial Bureaucracy (print capture
// p. 253)
inline int dnhSpiritsHoldOffices()
    { return 1; }

// ---- the ministry chain ----

// the chasing lung rain duty - the chasing lung (river dragons) given the
// duty of making rain (print capture p. 253)
inline int dnhChasingLungRainDuty()
    { return 1; }

// the ministry of thunder chain - the chasing lung report to the Ministry of
// Thunder, who in turn reports to the Celestial Emperor (print capture p.
// 253)
inline int dnhMinistryOfThunderChain()
    { return 1; }

// ---- the official character ----

// the spirit official character count - like the bureaucrats of the real
// world the spirit officials can be corrupt, disobedient, just, or
// incompetent, four characters (print capture p. 253)
inline int dnhSpiritOfficialCharacterCount()
    { return 4; }

// the officials like real bureaucrats - the spirit officials can be corrupt,
// disobedient, just, or incompetent, like the bureaucrats of the real world
// (print capture p. 253)
inline int dnhOfficialsLikeRealBureaucrats()
    { return 1; }

// the annual examination - the spirit officials can be replaced, each year
// their activities and behavior examined by their superiors (print capture p.
// 253)
inline int dnhAnnualExamination()
    { return 1; }

}   // namespace rules
