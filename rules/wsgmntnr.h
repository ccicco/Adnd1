// =========================================================================================
// Adnd1 - rules/wsgmntnr.h
// The WSG THE MOUNTAINEERING PROFICIENCY, R446: the mountaineer prose (no
// table this round) - a proficient character is only slightly more
// accomplished than any other non-thief on most non-horizontal surfaces where
// his special equipment offers no advantage, but when a difficult surface
// must be ascended or descended his presence can mean the difference between
// life and death. The essential tools and skills: PITONS, specially crafted
// metal spikes pounded into small cracks and fissures in a rock face to
// provide an anchor for a line - they are NOT used as handholds or footholds
// (uncomfortable at best, dangerous at worst, the surface area of a secured
// piton is not very large); a SPECIAL HAMMER to pound them in (a weapon
// hammer is the wrong material and too unwieldy to swing perched on a cliff);
// and the KNOWLEDGE of where to place them so they hold and give the greatest
// support - anyone can drive a piton into a crack, but only a mountaineer can
// tell which cracks will not widen or crumble. One mountaineer enables
// everyone else in the group to ascend or descend a surface they could not
// climb without him, as long as all the characters are roped together and the
// mountaineer is in the lead. Pitons also serve as a backup for a belayer, an
// anchor for someone rappelling, and a place to tie a rope before crossing a
// chasm. No matter the use or the strain, a piton has only a 10% chance of
// coming loose, checked the FIRST time it supports 100 pounds or more (simply
// pulling the rope does not count); a piton that passes stays lodged until a
// mountaineer dislodges it with his hammer - and there is a 10% chance any
// secured piton cannot be dislodged and must be left behind. Census 370 ->
// 371.
// census 370 -> 371.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 39; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0039.djvu) - the section reads CLEAN, every number (the two 10
// percent chances and the 100-pound first-check threshold) matched exactly;
// no eye-reads were needed.
//
// A piton has a 10% chance of coming loose, checked the first time it
// supports 100 pounds or more; a passed check stays lodged until a
// mountaineer dislodges it - and a secured piton has a 10% chance of refusing
// to come out at all and being left behind.
//
namespace rules {

// ---- the mountaineering rules ----

// A character with proficiency in mountaineering is only slightly more
// accomplished than any other non-thief at climbing or traversing most
// non-horizontal surfaces where his special equipment is not needed or offers
// no advantage.
inline bool wmtSlightlyBetterWithoutGear()
    { return true; }

// When a difficult surface must be ascended or descended by members of an
// adventuring party, the presence of a mountaineer can mean the difference
// between life and death.
inline bool wmtLifeAndDeathOnDifficult()
    { return true; }

// Pitons are specially crafted metal spikes pounded into small cracks and
// fissures in a rock face to provide an anchor for a line - contrary to
// popular conception, they are NOT used as handholds or footholds:
// uncomfortable at best, dangerous at worst, since the surface area of a
// secured piton is not very large.
inline bool wmtPitonsAreAnchorsNotHolds()
    { return true; }

// A special hammer is used to pound the pitons into the rock face; a hammer
// that serves as a weapon will not do - wrong material, and far too unwieldy
// to swing while perched on the side of a cliff.
inline bool wmtSpecialHammerRequired()
    { return true; }

// The third essential skill is the knowledge of where to place the pitons so
// they hold and give the greatest support - anyone, conceivably, can drive a
// piton into a crack, but only a mountaineer can tell which cracks will not
// widen or crumble so the piton has only a small chance of coming loose.
inline bool wmtPlacementKnowledge()
    { return true; }

// One mountaineer in a group can enable everyone else to ascend or descend a
// surface they could not climb without him, as long as all the characters are
// roped together and the mountaineer is in the lead.
inline bool wmtLeadsRopedGroup()
    { return true; }

// A piton will serve as a backup for a belayer, provide an anchor for someone
// rappelling, or serve as a place to tie a rope before crossing a chasm.
inline bool wmtPitonBackupForBelayer()
    { return true; }

// No matter what a piton is used for or how much strain is put on it, there
// is only a 10% chance that it will come loose.
inline int wmtLoosenPct()
    { return 10; }

// The loosen chance is checked the first time the piton is called upon to
// support a weight of 100 pounds or more; simply pulling on the rope will not
// dislodge a piton or indicate whether it has a chance of coming loose.
inline int wmtFirstCheckLbs()
    { return 100; }

// If the piton passes the first loosen check, it will remain lodged until a
// mountaineer dislodges it with his hammer.
inline bool wmtPassedCheckStaysLodged()
    { return true; }

// There is a 10% chance that any secured piton will not be able to be
// dislodged and must be left behind.
inline int wmtStuckPct()
    { return 10; }

// There is a 10% chance that any secured piton will not be able to be
// dislodged and must be left behind.
inline bool wmtStuckMustBeLeftBehind()
    { return true; }

}   // namespace rules
