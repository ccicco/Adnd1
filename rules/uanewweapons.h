// ===========================================================================
// Adnd1 - rules/uanewweapons.h
// The UA DESCRIPTIONS OF NEW WEAPON TYPES (pp. 26-28) pins (R340).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R337 data rows (rules/uaweapontable.h) and the R338 missile rows
// (rules/uamissile.h) are the data seam; this header pins the PROSE.
//
// JUDGMENTs:
//   - the roster: 16 prose entries in the printed order. The gap item
//     names 14 types; the section also describes the hand-held
//     crossbow and the falchion - both pinned (the item-list flag
//     uanwInGapItemList marks the 14 the item names).
//   - the khopesh "1'/z feet" reads as 1 1/2 feet (the slash-loss
//     fraction, the same artifact as the R339 "112 levels" cadence);
//     pinned as 15 tenths of a foot.
//   - the whip's "3d6e minus 2" reads as 3d6 minus 2 - the accent is
//     an OCR artifact on the plain 3d6 roll (the printed "dexterity or
//     less" pins the roll's meaning).
//   - the caltrop "hits on two" fragment: the subject cell is
//     OCR-garbled but the "virtually no movement for eight days" is
//     readable - the eight days pin, the trigger reads as hits on two
//     feet (noted pending the PDF).
//   - the khopesh trailing leverage sentence ("disallow (80%) ...
//     leverage ... (10%)") is scrambled beyond decode - a hole; the
//     readable 10% tear chance pins.
//
// OCR holes (the item stays open - the DM pp. 77-79 half of the
// item is DMG material absent from the UA extract, and these cells
// await the PDF read): the harpoon failure damage (prints
// "point damage" - the die lost), the hand-crossbow poison sentence
// (the "isons and sleep-inducing" scramble), the lasso severing
// mechanics paragraph (the bending-bars chance and the 2 cutting
// points print scrambled), the caltrop "hits on two" trigger, and
// the khopesh leverage sentence.
// ===========================================================================

#pragma once

namespace rules {

// The prose entry count (16 printed entries; the 10 PHB-style
// descriptions plus the hand-held crossbow and falchion prose).
inline int uanwCount()
    { return 16; }

// The entry name (printed).
inline const char* uanwName(int i) {
    static const char* const k[16] = {
        "Aklys", "Atlatl", "Blowgun", "Caltrop",
        "Crossbow, Hand-held", "Garrot", "Harpoon",
        "Hook Fauchard", "Lasso", "Man Catcher", "Sap",
        "Spiked Buckler", "Staff Sling", "Sword, Falchion",
        "Sword, Khopesh", "Whip",
    };
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    return k[i];
}

// True when the entry is among the 14 types the gap item names
// (the hand-held crossbow and the falchion are extra prose).
inline bool uanwInGapItemList(int i) {
    static const bool k[16] = {
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1
    };
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    return k[i];
}

// ---- the aklys ----
// 5% of the hits entangle; a subsequent roll of 20 on a hit
// indicates the entanglement; the thong runs about 10 feet;
// severing the thong takes 2 cutting points; a round spent
// disentangling frees the wielder.
inline int uanwAklysEntangleHitPct()
    { return 5; }

inline bool uanwAklysEntangleRollOf20()
    { return true; }

inline int uanwAklysThongFeet()
    { return 10; }

inline int uanwAklysThongSeverCuttingDmg()
    { return 2; }

inline int uanwAklysDisentangleRounds()
    { return 1; }

// ---- the atlatl ----
// The shorter, lighter javelins inflict the same damage
// because of their velocity.
inline bool uanwAtlatlJavelinDamageSame()
    { return true; }

// ---- the blowgun ----
// Fragile and long - impossible on the normal battlefield;
// the needles carry an insinuative poison.
inline bool uanwBlowgunBattlefieldImpossible()
    { return true; }

inline bool uanwBlowgunPoisonNeedles()
    { return true; }

// ---- the caltrop ----
// Four or six prongs; about one-half foot across; three-inch
// points at 70 or 90 degrees; aware movement slows by one-half
// for a round; each square yard crossed checks as a 1+1 HD
// monster attacking foot armor; a hit has a 25% chance to slow
// movement 25% for four days; hits on two (feet - the garbled
// trigger) mean virtually no movement for eight days; prongs
// under two inches are ignored; no proficiency needed.
inline int uanwCaltropProngCountLow()
    { return 4; }

inline int uanwCaltropProngCountHigh()
    { return 6; }

inline int uanwCaltropDiameterInches()
    { return 6; }

inline int uanwCaltropPointInches()
    { return 3; }

inline int uanwCaltropPointAngleLow()
    { return 70; }

inline int uanwCaltropPointAngleHigh()
    { return 90; }

inline int uanwCaltropAwareMoveFactorPct()
    { return 50; }

inline int uanwCaltropCheckHdDice()
    { return 1; }

inline int uanwCaltropCheckHdPlus()
    { return 1; }

inline int uanwCaltropHitSlowPct()
    { return 25; }

inline int uanwCaltropHitSlowMovePct()
    { return 25; }

inline int uanwCaltropHitSlowDays()
    { return 4; }

inline int uanwCaltropTwoHitNoMoveDays()
    { return 8; }

inline int uanwCaltropMinProngInches()
    { return 2; }

inline bool uanwCaltropNoProficiencyNeeded()
    { return true; }

// ---- the hand-held crossbow ----
// One hand to fire, two to load; a dart tipped with the
// substance forces a save versus poison at -4 or fall
// unconscious; 300 gp on the surface, 30 gp from the dark
// elves, their quarrels about a factor of 10 down - 10 gp.
inline bool uanwHandXbowOneHandFire()
    { return true; }

inline int uanwHandXbowPoisonSaveMod()
    { return -4; }

inline int uanwHandXbowSurfaceCostGp()
    { return 300; }

inline int uanwHandXbowDrowCostGp()
    { return 30; }

inline int uanwHandXbowDrowQuarrelGp()
    { return 10; }

// ---- the garrot ----
// Strike from behind; the victim's neck no more than 1 foot
// above the wielder's shoulder height; a raised limb foils
// encirclement - damage reduces to 1 point; a successful hit
// slays at the end of the next round; the victim attacks at
// -2; a successful bend bars roll spoils the attack.
inline bool uanwGarrotStrikeFromBehind()
    { return true; }

inline int uanwGarrotNeckMaxFeetAboveShoulder()
    { return 1; }

inline int uanwGarrotDeflectDmg()
    { return 1; }

inline int uanwGarrotVictimAttackMod()
    { return -2; }

inline int uanwGarrotSlayAtEndOfRounds()
    { return 1; }

inline bool uanwGarrotBendBarsBreaks()
    { return true; }

// ---- the harpoon ----
// A target of intelligence 2+ with means of dislodgement
// saves versus poison to free itself; failure drags the
// victim 1 inch closer if the harpooner desires (the failure
// damage prints "point damage" - the die lost, a hole).
inline int uanwHarpoonSaveMinInt()
    { return 2; }

inline bool uanwHarpoonSaveVsPoison()
    { return true; }

inline int uanwHarpoonDragInches()
    { return 1; }

// ---- the hook fauchard ----
// A hit has a 20% probability of dismounting or toppling
// the target - the wielder larger, or over 50% of the
// target's height and weight.
inline int uanwHookFauchardDismountPct()
    { return 20; }

inline int uanwHookFauchardSizeReqPct()
    { return 50; }

// ---- the lasso ----
// No damage in game terms; the hit mirrors the harpoon's;
// 75% dismount, 25% pulled off its feet if bipedal and no
// more than +50% of the wielder's height and mass (the
// severing mechanics print scrambled - a hole).
inline bool uanwLassoDamageless()
    { return true; }

inline int uanwLassoDismountPct()
    { return 75; }

inline int uanwLassoPullOffFeetPct()
    { return 25; }

inline int uanwLassoTargetMaxPct()
    { return 50; }

// ---- the man catcher ----
// Creatures larger or smaller than human size by 50% or more
// are unaffected; the caught loses all shield and dexterity
// bonuses; pushing and pulling inflicts 1-2 per round; 25%
// pulled off its feet; breakout by bend bars, each attempt
// 1-4 damage unless gloved; hacking the pole takes 6 cutting
// points.
inline int uanwManCatcherSizeBandPct()
    { return 50; }

inline bool uanwManCatcherLosesShieldAndDex()
    { return true; }

inline int uanwManCatcherPushPullDmgMin()
    { return 1; }

inline int uanwManCatcherPushPullDmgMax()
    { return 2; }

inline int uanwManCatcherPullOffFeetPct()
    { return 25; }

inline bool uanwManCatcherBreakoutBendBars()
    { return true; }

inline int uanwManCatcherAttemptDmgMin()
    { return 1; }

inline int uanwManCatcherAttemptDmgMax()
    { return 4; }

inline int uanwManCatcherPoleCuttingDmg()
    { return 6; }

// ---- the sap ----
// Unconsciousness only if the head is uncovered (light cloth
// counts); 5% per point of strength - 18/01 strength suffices;
// a non-head hit inflicts half damage only.
inline bool uanwSapHeadUncoveredRequired()
    { return true; }

inline int uanwSapUnconsciousPctPerStr()
    { return 5; }

inline int uanwSapNonHeadDamageFactorPct()
    { return 50; }

// ---- the spiked buckler ----
// The only effective armed shield; one extra attack per
// round, always after the initial weapon attack; as a
// second attack mode it strikes at -2.
inline int uanwSpikedBucklerExtraAttacksPerRound()
    { return 1; }

inline int uanwSpikedBucklerSecondModeMod()
    { return -2; }

// ---- the staff sling ----
// A pole of four or more feet; slower and less accurate than
// a sling, high trajectory - it always operates at medium or
// long range only; combustibles use the grenade-like missile
// table.
inline int uanwStaffSlingPoleMinFeet()
    { return 4; }

inline bool uanwStaffSlingMediumOrLongOnly()
    { return true; }

inline bool uanwStaffSlingUsesGrenadeTable()
    { return true; }

// ---- the falchion ----
// The Dungeon Master should assume 25% of magic broadswords
// are falchions.
inline int uanwFalchionMagicBroadswordPct()
    { return 25; }

// ---- the khopesh ----
// About 6 inches of handle and quillons, then about 2 feet
// straight, then about 2 feet sickle-shaped - extending the
// overall length by only 1 1/2 feet (the "1'/z" print). A
// snagged opponent not 50% smaller and lighter gets no
// effective attack for 10 segments; if smaller and lighter:
// pulled to the ground 25%, impeded 75%. Any hit 5% chance to
// snag the opponent; any miss 5% to snag the weapon; a
// snagged weapon is torn from grasp 10%. 10% of magical
// scimitars are khopeshes - a druidical instrument.
inline int uanwKhopeshHandleInches()
    { return 6; }

inline int uanwKhopeshStraightBladeFeet()
    { return 2; }

inline int uanwKhopeshSickleBladeFeet()
    { return 2; }

// The 1 1/2 feet effective extension (15 tenths).
inline int uanwKhopeshEffectiveExtendsTenthsFeet()
    { return 15; }

inline int uanwKhopeshSnagNoAttackSegments()
    { return 10; }

inline int uanwKhopeshSnagSizePct()
    { return 50; }

inline int uanwKhopeshSnaggedGroundPct()
    { return 25; }

inline int uanwKhopeshSnaggedImpededPct()
    { return 75; }

inline int uanwKhopeshOpponentSnagOnHitPct()
    { return 5; }

inline int uanwKhopeshWeaponSnagOnMissPct()
    { return 5; }

inline int uanwKhopeshWeaponTornPct()
    { return 10; }

inline int uanwKhopeshMagicScimitarPct()
    { return 10; }

inline bool uanwKhopeshDruidicalIdeal()
    { return true; }

// ---- the whip ----
// Any hit entangles at the wielder's option: 5% in
// non-proficient hands, 5% per level when proficient. The
// entanglement: one limb 50%, two limbs 10%, weapon arm and
// weapon 20%, the head 20% (40% against an opponent not using
// a weapon). One limb: no effective attack 10 segments; two
// limbs: the same, 25% kneeling or prone; weapon arm: no
// attack 10 segments, 10% weapon lost (an edged weapon severs
// the whip 50% instead); the neck: garrot-type damage without
// throat protection. A proficient wielder disentangles on
// dexterity or less on 3d6 minus 2; the victim pulls it loose
// at 5% plus 1% per point of its strength.
inline int uanwWhipEntangleNonProfPct()
    { return 5; }

inline int uanwWhipEntangleProfPctPerLevel()
    { return 5; }

inline int uanwWhipEntangleOneLimbPct()
    { return 50; }

inline int uanwWhipEntangleTwoLimbsPct()
    { return 10; }

inline int uanwWhipEntangleWeaponArmPct()
    { return 20; }

inline int uanwWhipEntangleHeadPct()
    { return 20; }

inline int uanwWhipEntangleHeadNoWeaponPct()
    { return 40; }

inline int uanwWhipNoAttackSegments()
    { return 10; }

inline int uanwWhipTwoLimbPronePct()
    { return 25; }

inline int uanwWhipWeaponLostPct()
    { return 10; }

inline int uanwWhipEdgedSeveredPct()
    { return 50; }

inline int uanwWhipDisentangle3d6Minus()
    { return 2; }

inline int uanwWhipVictimPullPct()
    { return 5; }

inline int uanwWhipVictimPullPctPerStr()
    { return 1; }

}   // namespace rules