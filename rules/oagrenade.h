// =========================================================================================
// Adnd1 - rules/oagrenade.h
// MISCELLANEOUS EQUIPMENT DESCRIPTIONS (THE GRENADES PROSE), printed capture
// p. 98 - the OA misc equipment round
// census 569 -> 570.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the page - the
// grenades prose cross-checked paragraph-by-paragraph between the two passes;
// every printed number agrees - zero contested cells. The lone glyph artifact
// is the em-dash class (the print hyphen against the compressed em-dash in
// the not-modern-sense clause - not a pin, noted). The grenades are blown-out
// eggshells (nutshells and paper packets also used) filled with powders -
// four kinds pin: pepper-filled (single target, save versus poison or
// incapacitated 1-6 rounds by choking and sneezing), dust-filled (the same
// save, blinded 1-6 rounds), flash powder (thrown onto a fire source, all
// looking automatically blinded 1-3 rounds, the may-or-may-not-looking
// allowed a save versus petrification) and poison smoke (cast onto a fire
// source, fills five feet by five feet per round, save versus poison or
// blinded and incapacitated, 1-2 hit points per round within, enough powder
// for a 10-foot by 10-foot area, remains one turn or until the wind). The
// to-hit doctrine pins as a bool pair: no armor modifiers (the contents burst
// in a small cloud on impact) and the eggshell fragility (a fall of 10 feet
// or more with damage forces a save versus crushing blow per grenade
// carried). The barding prose box and the armor descriptions box stay open
//
// the gap census after this round: 98 closed, 137 open - the Miscellaneous
// Equipment Descriptions box flips (census 569 -> 570); NEXT - R648: the
// Barding prose box (capture p. 98), the barding AC-factor and weight
// paragraph, prefix dhi (verify free), audit "R648 OA barding prose audit",
// include after rules/oagrenade.h - the armor descriptions box stays open
// beside it
//
namespace rules {

// ---- the grenades prose pins ----

// the four grenade kinds - pepper-filled, dust-filled, flash powder and
// poison smoke (capture p. 98)
inline int dhhGrenadeKindCount()
    { return 4; }

// the pepper grenade incapacitation lower bound, in rounds - save versus
// poison or incapacitated by choking and sneezing (capture p. 98)
inline int dhhPepperIncapLo()
    { return 1; }

// the pepper grenade incapacitation upper bound, in rounds (capture p. 98)
inline int dhhPepperIncapHi()
    { return 6; }

// the dust grenade blinding lower bound, in rounds - the same
// save-versus-poison way as pepper (capture p. 98)
inline int dhhDustBlindLo()
    { return 1; }

// the dust grenade blinding upper bound, in rounds (capture p. 98)
inline int dhhDustBlindHi()
    { return 6; }

// the flash powder blinding lower bound, in rounds - all looking at the flare
// are blinded automatically (capture p. 98)
inline int dhhFlashBlindLo()
    { return 1; }

// the flash powder blinding upper bound, in rounds (capture p. 98)
inline int dhhFlashBlindHi()
    { return 3; }

// the poison smoke per-round fill - a five foot by five foot area each round
// (capture p. 98)
inline int dhhSmokeFillFeet()
    { return 5; }

// the poison smoke damage lower bound, hit points per round to all within the
// smoke (capture p. 98)
inline int dhhSmokeDmgLo()
    { return 1; }

// the poison smoke damage upper bound, hit points per round (capture p. 98)
inline int dhhSmokeDmgHi()
    { return 2; }

// the poison smoke total fill - each grenade holds enough powder for a 10
// foot by 10 foot area (capture p. 98)
inline int dhhSmokeAreaFeet()
    { return 10; }

// the poison smoke duration, in turns - remains one turn or until the wind
// blows it away (capture p. 98)
inline int dhhSmokeTurns()
    { return 1; }

// the eggshell grenade fragility threshold - a fall of 10 feet or more that
// suffers damage forces the save (capture p. 98)
inline int dhhEggshellFallFeet()
    { return 10; }

// the to-hit doctrine: no armor modifiers - the contents burst in a small
// cloud on impact (capture p. 98)
inline bool dhhGrenadeNoAcMod()
    { return true; }

// pepper-filled grenades only affect a single target (capture p. 98)
inline bool dhhPepperSingleTarget()
    { return true; }

// flash powder grenades must be thrown onto a fire source, exploding in a
// brilliant flare of light (capture p. 98)
inline bool dhhFlashNeedsFire()
    { return true; }

// the flash powder save - characters who may or may not be looking are
// allowed a save versus petrification; a success means unaffected (capture p.
// 98)
inline bool dhhFlashPetrifySave()
    { return true; }

// poison smoke grenades must also be cast onto a fire source to work (capture
// p. 98)
inline bool dhhSmokeNeedsFire()
    { return true; }

// the poison smoke save - all within the area must save versus poison or be
// blinded and incapacitated by the foul, acidic stench (capture p. 98)
inline bool dhhSmokePoisonSave()
    { return true; }

// the eggshell fragility save - a saving throw versus crushing blow must be
// made for each grenade carried after the threshold fall (capture p. 98)
inline bool dhhEggshellCrushSave()
    { return true; }

}   // namespace rules
