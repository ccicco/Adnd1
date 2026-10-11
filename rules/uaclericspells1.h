// ===========================================================================
// Adnd1 - rules/uaclericspells1.h
// The UA NEW CLERIC SPELLS (pp. 32-35) pins, R343: the 1st-level
// spell descriptions - ceremony, combine, endure cold/heat, penetrate
// disguise, invisibility to undead, portent, magic stone,
// precipitation.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 cleric table pin (rules/uaspelltables.h) is the name seam.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family: four "Level: 7" cells print where the
//     level is position-certain 1 (the section header and the R341
//     table both read 1st level; ceremony, combine and magic stone
//     print clean "Level: 1" cells). The same 7 prints in the
//     casting-time and duration cells - the family decodes 7 as 1:
//     ceremony casting time 1 hour, magic stone casting time 1 round,
//     penetrate disguise duration 1 round.
//   - "lllusion/Phantasm" = Illusion/Phantasm (the leading I lost).
//   - the component cells "V, S" print as "V, §" (endure) and
//     "V, $" (penetrate) - the same S-garble family; decoded.
//   - the ceremony variety list prints "Sth-level" twice: the first
//     (ordination, special vows, consecrate ground) is 5th by list
//     position (1st, 3rd, then this cell), the second (anathematize)
//     is 7th - the list order 1/3/5/7 position-forces both. The
//     cells print head-lost: "rdination" = ordination,
//     "onsecrate ground" = consecrate ground.
//   - the burial sentence scrambles two columns: "magically
//     protects a corpse, and is best[?] shielded for one the week
//     blessing asif by of a" + "from evil spell" decodes as: the
//     corpse is magically protected for one week as if by a
//     protection from evil spell.
//   - the consecrate-ground evil-cleric fragment: "an[?] ... cleric,
//     any undead occupying the area are treated as if they were
//     being protected and controlled by an evil cleric of 3rd
//     level" - attributed to consecrate ground (the only
//     ground-consecration passage).
//   - combine's interleaved fragments: "The central functions as if
//     of higher cleric each gain encircling cleric. one level for"
//     = the central cleric functions as if of higher level for each
//     encircling cleric, gaining one level; "The maximum ...
//     level, is four" = the maximum gain is four levels
//     (corroborated: the circle runs three to five clerics, so at
//     most four encircle the central cleric); "and the maximum
//     duration is 3 turns" prints clean.
//   - combine's region-attributed sentences: "They gain no armor
//     class from shield or dexterity, and their attackers gain a
//     +4 bonus on all 'to hit' rolls" (the encircling clerics,
//     vulnerable while joined) and "The central cleric gains no
//     additional spells, but may cast any spell(s), often with
//     bonus effects" - both print inside the combine interleave;
//     the investiture and ordination sentences interleaved there
//     are attributed back to ceremony (their subject matter).
//   - the magic stone damage cell reads "the stone will do 1 point
//     of damage" - pinned verbatim with doubt (possible numeral
//     loss, pending the PDF). The range cell prints empty with an
//     orphan "2" fragment on the next line - pinned verbatim with
//     doubt (the PHB reads touch).
//   - the R341 table hole at row 13 (between Penetrate Disguise and
//     Precipitation) decodes as Portent - the alphabetical
//     position is forced and this round's descriptions confirm
//     portent as a 1st-level UA cleric spell. Noted here, not
//     re-pinned in R341's header.
//   - the ceremony costs: the clean pairs pin (coming of age 5-15
//     sp; special vows 1-100 gp or sometimes free; consecrate
//     ground 100-600 gp; anathematize no charge); the interleaved
//     fragments (5-50 gp, 1-100 gp, 1-20, 1-10, 200 gp) read as
//     the remaining cost cells scrambled - noted, not pinned.
//   - endure cold/heat prints "Duration: 9 turns/level" - pinned
//     verbatim with doubt (the digit-garble family suggests 1;
//     the 9 is not position-forced, pending the PDF).
//   - penetrate disguise prints "Range: 712°" - unresolvable
//     (the 7 decodes as 1 by the family; the tail reads as lost
//     cells) - a hole.
//
// OCR holes (the item stays open - the 2nd-7th levels pin in later
// rounds; these stay pending the PDF): the penetrate disguise
// range cell; the portent material component (the fragments
// "The leaves. it a wheel ... y item" scramble); the precipitation
// components, casting time and range (only the level fragment
// "vel", the duration and the area fragments survive); the combine
// components (the cell truncates at "V,"); the ceremony cost cells
// beyond the four clean pairs; the magic stone lost sentence ("A
// hit from the stone ... if the victim fails ... a saving throw
// ... fect") and the truncated "it turns back it" tail; the
// semi-porous surface scramble beyond the 2-segment and 5-segment
// fragments; the anathematize "(e." fragment.
// ===========================================================================

#pragma once

namespace rules {

// ---- ceremony (Invocation), p. 32-33 ----
inline const char* uac1CeremonyName()
    { return "Ceremony (Invocation)"; }

inline const char* uac1CeremonyComponents()
    { return "V, S, M"; }

// The casting time prints "7 hour" - the digit-garble family decodes
// 1 hour.
inline int uac1CeremonyCastingTimeHours()
    { return 1; }

// The ten ceremony varieties, by the cleric level that can cast
// them (the Sth cells decode by list position).
inline int uac1CeremonyVarietyCount()
    { return 10; }

inline const char* uac1CeremonyVarietyName(int i) {
    static const char* const k[10] = {
        "Coming of Age", "Burial", "Marriage",
        "Dedication", "Investiture", "Consecrate Item",
        "Ordination", "Special Vows", "Consecrate Ground",
        "Anathematize",
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

inline int uac1CeremonyVarietyLevel(int i) {
    // 1st: the first three; 3rd: the next three; 5th: the next
    // three; 7th: anathematize.
    static const int k[10] = {
        1, 1, 1, 3, 3, 3, 5, 5, 5, 7,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

// No saving throw for any ceremony except anathematize (it simply
// fails on an unwilling recipient).
inline bool uac1CeremonyNoSaveExceptAnathematize()
    { return true; }

// Coming of age: a limited bless; the +1 bonus applies to any
// single saving throw, taken at any time after the ceremony.
inline int uac1ComingOfAgeSaveBonus()
    { return 1; }

inline int uac1ComingOfAgeUsualAge()
    { return 12; }

// Burial: the corpse is shielded for one week as if by a
// protection from evil spell; a disinterer within that time must
// save versus spell or stop and flee in fear for one turn.
inline int uac1BurialProtectionWeeks()
    { return 1; }

inline int uac1BurialDisintererFleeTurns()
    { return 1; }

// An edifice on unconsecrated ground has a 1% chance per year,
// cumulative, of collapsing.
inline int uac1UnconsecratedCollapsePctPerYear()
    { return 1; }

// Consecrated (unholy) ground held by an evil cleric: the undead
// occupying it are treated as if protected and controlled by an
// evil cleric of 3rd level.
inline int uac1ConsecrateGroundEvilClericLevel()
    { return 3; }

// Special vows (cavalier or paladin): immunity to bestow curse
// spells (not cursed items) while in effect; and -4 on saving
// throws against a quest spell cast by a cleric of the vows
// caster's alignment.
inline bool uac1SpecialVowsBestowCurseImmunity()
    { return true; }

inline int uac1SpecialVowsQuestSaveMod()
    { return -4; }

// The clean cost pairs (the interleaved cells are holes).
inline int uac1CostComingOfAgeMinSp()
    { return 5; }

inline int uac1CostComingOfAgeMaxSp()
    { return 15; }

inline int uac1CostSpecialVowsMinGp()
    { return 1; }

inline int uac1CostSpecialVowsMaxGp()
    { return 100; }

inline bool uac1CostSpecialVowsSometimesFree()
    { return true; }

inline int uac1CostConsecrateGroundMinGp()
    { return 100; }

inline int uac1CostConsecrateGroundMaxGp()
    { return 600; }

inline bool uac1CostAnathematizeNoCharge()
    { return true; }

// ---- combine (Evocation), p. 33-34 ----
inline const char* uac1CombineName()
    { return "Combine (Evocation)"; }

// Three to five clerics join hands in a circle; all cast the
// spell together; the highest-level other cleric stands central.
inline int uac1CombineClericsMin()
    { return 3; }

inline int uac1CombineClericsMax()
    { return 5; }

// The central cleric functions as if of higher level, gaining one
// level per encircling cleric, to a maximum of four levels.
inline int uac1CombineLevelGainPerEncircling()
    { return 1; }

inline int uac1CombineMaxGainLevels()
    { return 4; }

inline int uac1CombineMaxDurationTurns()
    { return 3; }

// The encircling clerics gain no armor class from shield or
// dexterity, and attackers gain +4 on "to hit" rolls against them.
inline bool uac1CombineEncirclingNoShieldOrDexAc()
    { return true; }

inline int uac1CombineAttackerToHitBonus()
    { return 4; }

// The central cleric gains no additional spells but may cast any
// spell(s), often with bonus effects.
inline bool uac1CentralClericNoExtraSpells()
    { return true; }

// The combine components cell truncates at "V," - a hole.
inline bool uac1CombineComponentsLost()
    { return true; }

// ---- endure cold / endure heat (Alteration), reversible, p. 34 ----
inline const char* uac1EndureName()
    { return "Endure Cold / Endure Heat"; }

inline bool uac1EndureReversible()
    { return true; }

inline int uac1EndureColdLowFLimit()
    { return -30; }

inline int uac1EndureHeatHighFLimit()
    { return 130; }

// Beyond the limits: 1 hit point of exposure damage per hour per
// degree; unprotected exposure runs 1 hit point per turn per
// degree.
inline int uac1EndureExposureDamagePerHourPerDegree()
    { return 1; }

inline int uac1UnprotectedExposureDamagePerTurnPerDegree()
    { return 1; }

// The duration prints "9 turns/level" - verbatim with doubt (the
// digit-garble family suggests 1).
inline int uac1EndureDurationTurnsPerLevel()
    { return 9; }

// The spell breaks on any magical cold (including white dragon
// breath) or magical heat (including magical fire); no damage in
// the breaking round; resist fire or resist cold cancels it
// instantly.
inline bool uac1EndureCancelledByMagicalColdOrHeat()
    { return true; }

inline bool uac1EndureNoDamageInBreakingRound()
    { return true; }

inline bool uac1EndureResistFireOrColdCancels()
    { return true; }

// ---- penetrate disguise (Divination), p. 34 ----
inline const char* uac1PenetrateName()
    { return "Penetrate Disguise (Divination)"; }

inline int uac1PenetrateCastingTimeRounds()
    { return 2; }

// The duration prints "7 round" - the digit-garble family decodes
// 1 round.
inline int uac1PenetrateDurationRounds()
    { return 1; }

inline bool uac1PenetrateSeesNonMagicalDisguise()
    { return true; }

// The spell cannot identify the figure's class or profession, nor
// detect actual rank or status; it cannot reveal an illusion; it
// can detect whether a figure is the object of a friends spell;
// it cannot detect deception involving alignment.
inline bool uac1PenetrateCannotIdClassOrStatus()
    { return true; }

inline bool uac1PenetrateCannotRevealIllusion()
    { return true; }

inline bool uac1PenetrateDetectsFriendsSpellObject()
    { return true; }

inline bool uac1PenetrateCannotDetectAlignmentDeception()
    { return true; }

// On a successful target save the disguise is enhanced: the caster
// becomes convinced the target is what he claims to be. Bless,
// magic armor or a magic item of protection grants the target a
// saving throw bonus.
inline bool uac1PenetrateTargetSaveEnhancesDisguise()
    { return true; }

inline bool uac1PenetrateProtectionGrantsSaveBonus()
    { return true; }

// The range cell prints "712" - a hole.
inline bool uac1PenetrateRangeLost()
    { return true; }

// ---- invisibility to undead (Illusion/Phantasm), p. 34-35 ----
inline const char* uac1ItuName()
    { return "Invisibility to Undead"; }

inline int uac1ItuMaxHitDice()
    { return 4; }

inline int uac1ItuRadiusFeet()
    { return 30; }

inline int uac1ItuDurationRounds()
    { return 6; }

inline int uac1ItuCastingTimeSegments()
    { return 4; }

// A save is made per undead type within 30 feet: on a failure all
// undead of that type ignore the caster for the duration (this
// negates the caster's subsequent turning attempts); on a success
// they attack the caster in preference to other targets. The
// spell ends if the caster attacks or casts any other spell.
inline bool uac1ItuSavePerType()
    { return true; }

inline bool uac1ItuNegatesOwnTurning()
    { return true; }

inline bool uac1ItuEndsIfCasterActs()
    { return true; }

// A neutral caster (re good/evil) gives the undead -2 on the save.
inline int uac1ItuNeutralCasterSaveMod()
    { return -2; }

inline bool uac1ItuMaterialHolySymbol()
    { return true; }

// ---- portent (Divination), p. 35 ----
inline const char* uac1PortentName()
    { return "Portent (Divination)"; }

// The DM rolls 1d12 in secret for which future roll is affected,
// then 1d6 for the effect.
inline int uac1PortentTimingDieSides()
    { return 12; }

inline int uac1PortentEffectDieSides()
    { return 6; }

inline int uac1PortentEffectModifier(int roll) {
    // 1 = -3; 2 = -2; 3 = -1; 4 = +1; 5 = +2; 6 = +3.
    static const int k[6] = { -3, -2, -1, 1, 2, 3 };
    if (roll < 1) roll = 1;
    if (roll > 6) roll = 6;
    return k[roll - 1];
}

// Only life-or-death rolls (combat or peril) count toward the
// timing; contrived saving throws against non-harmful effects
// suspend the count.
inline bool uac1PortentOnlyLifeOrDeathRolls()
    { return true; }

inline bool uac1PortentContrivedRollsSuspended()
    { return true; }

inline int uac1PortentCastingTimeTurns()
    { return 1; }

// The R341 table's hole at row 13 decodes as this spell (see the
// JUDGMENTs).
inline bool uac1PortentTableHoleDecoded()
    { return true; }

// The material component fragments scramble - a hole.
inline bool uac1PortentMaterialLost()
    { return true; }

// ---- magic stone (Alteration), p. 35 ----
inline const char* uac1MagicStoneName()
    { return "Magic Stone (Alteration)"; }

inline int uac1MagicStoneToHitBonus()
    { return 1; }

// The damage cell reads "1 point of damage" - verbatim with doubt.
inline int uac1MagicStoneDamagePoints()
    { return 1; }

// The stone can be thrown at a target up to 4" distant; beyond
// that, or on a miss, it loses its dweomer and falls harmlessly.
inline int uac1MagicStoneThrowRangeInches()
    { return 4; }

// The range cell prints empty with an orphan "2" fragment -
// verbatim with doubt (the PHB reads touch).
inline int uac1MagicStoneRangeInches()
    { return 2; }

// The stone must be thrown within 6 rounds of casting or it
// turns back [to a normal pebble - the tail truncates].
inline int uac1MagicStoneDweomerWindowRounds()
    { return 6; }

// Stones per caster level: 1 through 5th level one stone; 6th
// through 10th two; 11th through 15th three; then one more per
// five levels beyond 11th (4 at 16th, 5 at 21st).
inline int uac1MagicStoneStonesForLevel(int level) {
    if (level < 1) level = 1;
    if (level <= 5) return 1;
    if (level <= 10) return 2;
    return 3 + (level - 11) / 5;
}

// Any target with innate magic resistance cannot be affected; a
// shield spell, a brooch of shielding, protection from normal
// missiles, a minor globe of invulnerability or similar stronger
// magic protects the target.
inline bool uac1MagicStoneInnateResistImmune()
    { return true; }

inline bool uac1MagicStoneShieldBlocks()
    { return true; }

inline int uac1MagicStoneDurationRounds()
    { return 6; }

// The enchanted stone(s) can be given to another character to
// throw; some religions forbid the spell (a missile weapon of
// sorts).
inline bool uac1MagicStoneGiveToAnother()
    { return true; }

inline bool uac1MagicStoneSomeReligionsForbid()
    { return true; }

// The components cell truncates at "V," - a hole.
inline bool uac1MagicStoneComponentsLost()
    { return true; }

// ---- precipitation (Alteration), p. 35 ----
inline const char* uac1PrecipName()
    { return "Precipitation (Alteration)"; }

// The stat block scrambles; the readable fragments: duration
// 1 segment/level; area of effect a 3" diameter cylinder up to
// 12" high; saving throw none. The components, casting time and
// range are holes.
inline int uac1PrecipDurationSegmentsPerLevel()
    { return 1; }

inline int uac1PrecipCylinderDiameterInches()
    { return 3; }

inline int uac1PrecipCylinderHeightInches()
    { return 12; }

inline bool uac1PrecipComponentsLost()
    { return true; }

// Thin light material damp in 1 segment, thoroughly wet
// thereafter; twigs and heavy material (canvas) damp in 2
// segments, wet thereafter; flat relatively non-porous surfaces
// (stone floors, rock, painted wood) damp in 1 segment, filmed
// with water thereafter.
inline int uac1PrecipThinMaterialDampSegments()
    { return 1; }

inline int uac1PrecipHeavyMaterialDampSegments()
    { return 2; }

inline int uac1PrecipFlatSurfaceDampSegments()
    { return 1; }

// Semi-porous surfaces progress in 2 segments and are thoroughly
// wet after 5 (the interleaved tail).
inline int uac1PrecipSemiPorousWetAfterSegments()
    { return 5; }

// Porous surfaces absorb up to their capacity - likely beyond the
// spell's duration.
inline bool uac1PrecipPorousAbsorbs()
    { return true; }

// Small flames (candles) are extinguished by 1 segment; small
// fires slow and become smoky for 1 round after the rain ceases;
// large fires are not materially affected.
inline int uac1PrecipCandleOutSegments()
    { return 1; }

inline int uac1PrecipSmallFireSmokyRounds()
    { return 1; }

inline bool uac1PrecipLargeFiresUnaffected()
    { return true; }

// Above 90 F the duration doubles (except in arid regions);
// between 33 and 31 F the rain falls as sleet; at 30 F and below
// it falls as thick snow and the dampness/wetness effects are
// negated or postponed until the snow melts.
inline int uac1PrecipHotTempDoublesAboveF()
    { return 90; }

inline int uac1PrecipSleetHighF()
    { return 33; }

inline int uac1PrecipSleetLowF()
    { return 31; }

inline int uac1PrecipSnowAtOrBelowF()
    { return 30; }

// Magical heat of large area (fire, fireball, flame strike)
// applied to the rain forms a cloud of warm fog of double the
// area; magical cold applied forms normal ice.
inline int uac1PrecipMagicalHeatFogAreaMultiplier()
    { return 2; }

inline bool uac1PrecipMagicalColdFormsIce()
    { return true; }

inline bool uac1PrecipMaterialSilverDust()
    { return true; }

}   // namespace rules
