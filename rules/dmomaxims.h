// =========================================================================================
// Adnd1 - rules/dmomaxims.h
// THE SEVEN MAXIMS - the DMO arc opener: the front matter and the campaign
// doctrine of printed pp. 1-23 - the seven-principle roster, the high-level
// definitions (level 10 or more, the 30th-level cap, the level-20 retirement
// frame), the flat-XP breakdown, the Table 1 demographics ladder, and the
// foreword previews of the true dweomers and the auto-fail rule.
// census 521 -> 522.
//
// verified against printed pp. 1-22 of the uploaded dmo.pdf OCR (part 1 of
// the session capture); the maxim roster from p. 6, the tension doctrine from
// pp. 7-10, the demographics from p. 22; THIS ROUND LANDS A NEW GAP REPORT
// tools/dmo_gap_report.md (96 boxes at opener, all 52 numbered tables
// enumerated per the R566 amended-manifest lesson applied at opener) in the
// same commit as the spec.
//
// the gap census after this round: 6 closed, 90 open - the DMO arc begins
// (R566 -> R596 closed MotP at 91/0; the high-level arc opens here).
//
namespace rules {

// ---- the DMO opener pins ----

// the maxim roster count: seven basic principles for running a high-level
// campaign - don't depend on the dice, use adversaries intelligently and
// inventively, control magic, be aware of demographics, think on an epic
// scale, plan ahead, share responsibility with the players.
inline int degMaximCount()
    { return 7; }

// the high-level definition: for this book's purposes, any character of level
// 10 or more is high-level (printed p. 6).
inline int degHighLevelFloor()
    { return 10; }

// the book's scope: rules and campaign suggestions for characters of up to
// 30th level (printed p. 6) - the ceiling the Chapter 7 ascension doctrine
// later caps.
inline int degBookLevelCap()
    { return 30; }

// the retirement frame: per the DMG Chapter Three, retirement is inevitable
// once characters exceed level 20 - the doctrine this book argues against
// (printed p. 6).
inline int degRetirementLevel()
    { return 20; }

// the beyond-9th-level breakdown: the experience required to gain the next
// level no longer increases geometrically once the PCs reach 9th level - a
// flat increase from level to level instead (printed p. 8, Figure 3).
inline int degFlatXpFrom()
    { return 9; }

// the demographic ladder, Table 1: there is only one 10th-level character in
// a general population of 5,000 (printed p. 22).
inline int degDemographicTenth()
    { return 5000; }

// the demographic ladder's top: an 18th-level character of any class is truly
// a one-in-a-million individual (printed p. 22).
inline int degDemographicEighteenth()
    { return 1000000; }

// the subclass rarity: only .2% of the population (1 in 500) qualifies to be
// a paladin; other subclasses with strict ability requirements (bards,
// rangers, druids) are equally rare (printed p. 22).
inline int degPaladinRate()
    { return 500; }

// the seven named maxims, in book order: don't depend on the dice; use
// adversaries intelligently and inventively; control magic; be aware of
// demographics; think on an epic scale; plan ahead; share responsibility with
// your players - following them does not guarantee a great game, but all
// successful high-level campaigns use them to one degree or another.
inline bool degMaximRoster()
    { return true; }

// the foreword preview, Chapter 6: true dweomers are essentially 10th-level
// spells - world-shaking magic for high-level spellcasters, included to allow
// the casting of a single true dweomer to keep a group of PCs busy for a long
// time.
inline bool degForewordDweomerThesis()
    { return true; }

// the foreword preview, Chapter 7: the revised rule for automatic failure of
// saving throws - something that places a little fear back into high-level
// characters' lives.
inline bool degForewordAutoFail()
    { return true; }

// the first maxim's core: maintain tension without inflating the level of
// power - create situations where the players rely on their own memories and
// reasoning skills; not every encounter has to be a fight; do not allow the
// PCs to become so dominant that every situation descends into a die-rolling
// extravaganza.
inline bool degTensionDoctrine()
    { return true; }

// the fifth maxim's core: heroes are not anonymous, heroes deserve heroic
// tasks, and the impact of high-level deeds reaches far - the campaign
// doctrine of printed pp. 22-23.
inline bool degEpicScaleDoctrine()
    { return true; }

}   // namespace rules
