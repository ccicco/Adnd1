// =========================================================================================
// Adnd1 - rules/oa133tulung.h
// OA SETTING - THE TU LUNG EMPIRE, printed capture pp. 303-304 - the
// breakaway state of the Earth Dragon
// census 684 -> 685.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 215 closed, 20 open - the Tu Lung box
// flips (census 684 -> 685); NEXT - R763: Wa (capture p. 304), prefix dly
// (verify free at the landing), audit "R763 OA Wa audit", include after
// rules/oa133tulung.h
//
namespace rules {

// ---- the founding schism ----

// the earth dragon - the empire name Tu Lung meaning Earth Dragon (print
// capture p. 303)
inline int dlxEarthDragon()
    { return 1; }

// the part of Shou Lung - Tu Lung was part of Shou Lung until the succession
// dispute (print capture p. 303)
inline int dlxPartOfShouLung()
    { return 1; }

// the years since the split - Tu Lung part of Shou Lung until a dispute over
// imperial succession 300 years ago (print capture p. 303)
inline int dlxYearsSinceSplit()
    { return 300; }

// the own emperor separate court - claiming its own emperor, Tu Lung set up a
// separate imperial court (print capture p. 303)
inline int dlxOwnEmperorSeparateCourt()
    { return 1; }

// the wars stabilized - after many wars between the two states, the situation
// has stabilized (print capture p. 303)
inline int dlxWarsStabilized()
    { return 1; }

// the no love lost - no love is lost between the two empires (print capture
// p. 303)
inline int dlxNoLoveLost()
    { return 1; }

// ---- the rise of the nobles ----

// the rebel nobles great power - the Emperor of Tu Lung was supported by the
// powerful officials and nobles of the rebelling provinces, leading to their
// acquiring great power and strength (print capture p. 303)
inline int dlxRebelNoblesGreatPower()
    { return 1; }

// ---- the imperial government ----

// the modeled after Shou Lung - although the government is modeled after that
// of Shou Lung (print capture p. 303)
inline int dlxModeledAfterShouLung()
    { return 1; }

// the Lui dynasty - the Emperor of Tu Lung of the Lui Dynasty (print capture
// p. 303)
inline int dlxLuiDynasty()
    { return 1; }

// the emperor cannot break the nobles - the Emperor has never been able to
// break the power of his nobles (print capture p. 303)
inline int dlxEmperorCannotBreakNobles()
    { return 1; }

// the nobles control the examinations - the nobles control the examination
// system (print capture p. 303)
inline int dlxNoblesControlExaminations()
    { return 1; }

// the offices hereditary - the nobles arranged for various offices to become
// hereditary (print capture p. 303)
inline int dlxOfficesHereditary()
    { return 1; }

// the estates exempt from edicts - the noble power allowed them to exempt
// their estates from most imperial edicts, including taxation (print capture
// p. 303)
inline int dlxEstatesExemptEdicts()
    { return 1; }

// the majority consent - the Emperor can only enforce his edicts with the
// consent of the majority of the nobles (print capture p. 303)
inline int dlxMajorityConsent()
    { return 1; }

// the commoners little chance - commoners have little chance to rise in the
// government (print capture p. 303)
inline int dlxCommonersLittleChance()
    { return 1; }

// the post corruption - corruption of official posts is common (print capture
// p. 303)
inline int dlxPostCorruption()
    { return 1; }

// ---- the provinces ----

// the province count - Tu Lung divided into six provinces (print capture p.
// 303)
inline int dlxProvinceCount()
    { return 6; }

// the hereditary governors - each of the six provinces administered by a
// hereditary governor (print capture p. 303)
inline int dlxHereditaryGovernors()
    { return 1; }

// the districts family and graft - the provinces divided into districts,
// official positions assigned on the basis of family and graft (print capture
// p. 303)
inline int dlxDistrictsFamilyGraft()
    { return 1; }

// ---- the public works and the people ----

// the inherited public works - although Tu Lung inherited the public works of
// Shou Lung (print capture p. 303)
inline int dlxInheritedPublicWorks()
    { return 1; }

// the works poorly maintained - the public works poorly maintained and new
// projects seldom undertaken (print capture p. 303)
inline int dlxWorksPoorlyMaintained()
    { return 1; }

// the people easily oppressed - the people easily oppressed, having no
// recourse to the law (print capture p. 303)
inline int dlxPeopleEasilyOppressed()
    { return 1; }

// ---- the capital and the conspiracy ----

// the capital plotting - the prime activity in the capital Chia Wan Chuan is
// political plotting (print capture p. 303 and p. 304)
inline int dlxCapitalPlotting()
    { return 1; }

// the secret societies - many of the nobles of Tu Lung are leaders of secret
// societies pledged to overthrow the Emperor (print capture p. 304)
inline int dlxSecretSocieties()
    { return 1; }

}   // namespace rules
