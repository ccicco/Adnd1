// =========================================================================================
// Adnd1 - rules/lancespeed.h
// THE LANCE SPEED FACTORS - the three lances ride the R158 ladder
// census 702 -> 703.
//
// R779 left the lance speed contract-side (the R158 ladder names no lance);
// R780 pins the three printed cells. The PHB p.38 WEAPON TYPES speed column,
// read from the 1eonline.info compilation (the repo-trusted source): light
// horse 7, medium horse 6, heavy horse 8. The medium-horse 6 outrunning the
// light-horse 7 is no OCR slip - both compilation pages print it
// cell-for-cell, and the engine follows the print exactly as it followed the
// spear 6-8 spread. The rows land in rules/weaponspeed.h - the R158
// name-keyed ladder, still pure data: the DMG p.66 three caller-detected
// cases (tie order, the extra-attack windows, the weapon-vs-spell segment)
// gained no engine caller here; the R158 audit itself gains the three checks
// against the R780 header pins, so a mutant in either the ladder row or the
// pin dies at the preflight. Honest boundaries: the printed lengths and
// space-required cells ride no engine concept, and the standing pragma once
// in weaponspeed.h stays untouched - the R778 guard rule governs new guards
// only
//
// Zero new book pages: the three speed cells ride the 1eonline.info
// compilation the R189 speed-verify duty already trusts
//
namespace rules {

// ---- the lance speed (the R780 wiring) ----

// The feeder seam this round extends: the R158 name-keyed weapon speed ladder
// (DMG p.66, the PHB p.38 factor column).
inline int lspSpeedFeederRound()
    { return 158; }

// The lance speed round: the three lances join the ladder, the cells pin.
inline int lspLanceSpeedRound()
    { return 780; }

// The three ladder rows this round adds: light, medium, heavy horse.
inline int lspLanceSpeedRowCount()
    { return 3; }

// The light horse lance speed factor (the PHB p.38 speed column, the
// 1eonline.info compilation).
inline int lspLightLanceSpeedFactor()
    { return 7; }

// The medium horse lance speed factor: the print's quirk - a 12-foot shaft
// faster than the light horse's 10-foot one. The print is the print.
inline int lspMediumLanceSpeedFactor()
    { return 6; }

// The heavy horse lance speed factor (the PHB p.38 speed column).
inline int lspHeavyLanceSpeedFactor()
    { return 8; }

// The three rows land in rules/weaponspeed.h weaponSpeedFactor: lance, light
// horse 7; lance, medium horse 6; lance, heavy horse 8.
inline bool lspLancesRideTheR158Ladder()
    { return true; }

// The medium horse cell 6 beats the light horse 7 - both compilation pages
// print it, the engine follows the print (no length-based second-guess).
inline bool lspMediumOutrunsTheLight()
    { return true; }

// No engine caller exists: the DMG p.66 caller-detected cases (tie order,
// extra-attack windows, the vs-spell segment) stay contract-side; the R158
// audit checks the cells.
inline bool lspLadderStaysPureData()
    { return true; }

// The printed lengths and space-required cells (10/12/14 feet, 1 foot) ride
// no engine concept - recorded here, pinned nowhere else.
inline bool lspLanceLengthsStayContractSide()
    { return true; }

}   // namespace rules
