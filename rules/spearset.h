// =========================================================================================
// Adnd1 - rules/spearset.h
// THE SET SPEAR AND THE SPEED SEAM - the receive answers the charge, the DMG
// p.66 cases go live
// census 703 -> 704.
//
// R779 left the spear set-to-receive contract-side (no monster charge
// concept) and R780 left the DMG p.66 speed cases caller-less (the ladder
// pure data); R781 closes both seams and strikes the R779 zero-row JUDGMENT
// besides. The set spear rides the R189 chart double asterisk: the S command
// plants the stance (round one + a spear, the round consumed), and a closing
// monster blow that round answers to the counterstrike FIRST - the receive
// multiplier doubles that one blow, then the stance is done (the JUDGMENT:
// the monster's round-one melee reads as the charge, the R232 pattern again).
// The DMG p.66 three cases gain their engine callers in the round scheduler,
// reading each side's front melee actor through the R158 name-keyed ladder
// (the footman mace/flail JUDGMENT; the lances and the spear now on the
// ladder): the tie shifts the slower side +1, the extra-attack window opens
// after round one (the before-count minus one on the +5 spacing - the
// JUDGMENT; the charge round exempts it per speedFactorApplies), and the
// weapon-vs-spell segment is the factor minus the losing die (clamped 1..10).
// And the lance vs-AC cells: the 1eonline.info compilation (the repo-trusted
// source) carries the full rows - light -3..0, medium -1..+1, heavy +4..0 -
// so items.cpp and the R145 audit pin them cell for cell and the R779
// no-adjustment JUDGMENT is STRUCK. Honest boundaries: no reach layer exists
// (the front actor reads as the side), the printed lengths and space-required
// cells ride no engine concept, and the spear keeps its R158 default 7 on
// this seam
//
// Zero new book pages: the set-spear asterisk rides the R189 chart already
// pinned, the speed cases ride DMG p.66 already honored in
// rules/weaponspeed.h, and the lance vs-AC rows ride the 1eonline.info
// compilation the R189 speed-verify duty already trusts
//
namespace rules {

// ---- the set spear (the R781 wiring) ----

// The feeder seam: the R189 chart's set-spear double asterisk (the receive
// vs. the charging rider).
inline int spsSetFeederRound()
    { return 189; }

// The set spear round: the stance goes live, the receive doubles its one
// blow.
inline int spsSpearSetRound()
    { return 781; }

// The set spear's receive multiplier: double damage on the one counterstrike
// blow.
inline int spsSetDamageMultiplier()
    { return 2; }

// The stance answers a closing monster blow with a FIRST counterstrike
// (ai/actor.cpp, the resolution-loop fold).
inline bool spsSpearSetReceivesTheClosingFoe()
    { return true; }

// The planted spear submits no attack that round - one defensive posture (the
// submitTeam stance branch).
inline bool spsTheStanceConsumesTheRound()
    { return true; }

// ---- the speed seam and the vs-AC rows (the R781 wiring) ----

// The vs-AC feeder seam: the R145 per-weapon adjustment audit the three
// compilation lance rows now pin.
inline int spsAcFeederRound()
    { return 145; }

// DMG p.66 - the speed factor cases page the R158 helpers already honor.
inline int spsSpeedPage()
    { return 66; }

// The three compilation vs-AC rows: light, medium, heavy horse.
inline int spsLanceAcRowCount()
    { return 3; }

// The three 1eonline.info vs-AC rows (light -3..0, medium -1..+1, heavy
// +4..0) replace the struck R779 zero rows.
inline bool spsLanceAcCellsRideTheCompilation()
    { return true; }

// DMG p.66 case 1 live: a tie orders the blows by the lower factor (a +1
// shift on the slower side's base).
inline bool spsTieReadsTheSpeedLadder()
    { return true; }

// DMG p.66 case 3 live: the weapon strikes at the factor minus the losing die
// (clamped 1..10) against the caster.
inline bool spsWeaponVsSpellReadsTheSegment()
    { return true; }

// DMG p.66 case 2 live: after round one the faster front gains the
// before-count minus one (the +5 spacing JUDGMENT).
inline bool spsExtraAttacksOpenAfterRoundOne()
    { return true; }

// The R158 print: missile weapons carry no factor - the fold reads 0 as
// unknown and skips.
inline bool spsMissileWeaponsCarryNoFactor()
    { return true; }

}   // namespace rules
