// ===========================================================================
// Adnd1 - rules/uamuspells9.h
// The UA NEW MAGIC-USER SPELLS (pp. 74-77) pins, R362: the
// 9th-level spell descriptions - crystalbrittle, succor,
// energy drain and the Mordenkainen disjunction.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the crystalbrittle casting head loses the Casting
//     word (a bare Time: 9 segments) - pinned as printed;
//     the components cell garbles the sign (V, S) - the
//     M pins from the stat pattern, flagged pending the
//     PDF.
//   - the succor stat head prints only the Duration and
//     Area cells; the Components, Casting Time and
//     Saving Throw cells print in an interleaved tail
//     after the prose - the casting garbles (a 17-to-4
//     print; the leading fragment reads as 1, flagged
//     pending the PDF). The level cell is lost - the
//     level pins from the section heading. The spell is
//     reversible.
//   - the energy drain stat block scrambles - the 3
//     segments displace above the Casting Time line, and
//     the duration and save cells never print - holes
//     pending the PDF; the material sentence scrambles
//     the spectre word (an essence-of fragment) and the
//     three-segments phrase - flagged pending the PDF.
//   - the Mordenkainen disjunction name header garbles
//     to a bare possessive-fragment; the name pins from
//     the gap item list and the prose. The school is
//     lost pending the PDF; the components cell prints
//     bare - a hole pending the PDF.
//   - the R342 MU table seam prints only two 9th-level
//     names (Prismatic Sphere, Shape Change) - none of
//     the new names seam-checks, asserted in the audit.
// ===========================================================================

namespace rules {

// ---- crystalbrittle (Alteration) ----
inline const char* uam9CrystalName()
    { return "Crystalbrittle (Alteration)"; }

// The components cell garbles the sign for the M - pinned
// as V, S, M, flagged pending the PDF.
inline bool uam9CrystalComponentsVSM()
    { return true; }

inline bool uam9CrystalComponentsCellGarbled()
    { return true; }

inline int uam9CrystalLevel()
    { return 9; }

// The casting head loses the Casting word - a bare Time:
// 9 segments; pinned as printed.
inline int uam9CrystalCastingTimeSegments()
    { return 9; }

inline bool uam9CrystalCastingHeadLost()
    { return true; }

inline bool uam9CrystalRangeTouch()
    { return true; }

inline bool uam9CrystalDurationPermanent()
    { return true; }

inline bool uam9CrystalSaveSpecial()
    { return true; }

inline int uam9CrystalAoeCuFtPerLevel()
    { return 2; }

// The dweomer turns metal - as soft as gold or as hard as
// adamantite - into a crystalline substance as brittle and
// fragile as crystal.
inline bool uam9CrystalTurnsMetalToCrystal()
    { return true; }

// A sword, metal shield, metal armor, or even an iron
// golem becomes delicate, glass-like material easily
// shattered by any forceful blow.
inline bool uam9CrystalShattersByBlow()
    { return true; }

// The change is unalterable short of a wish - dispel
// magic will not reverse it.
inline bool uam9CrystalReversibleOnlyByWish()
    { return true; }

// The caster must physically touch the target - equal to
// a hit in combat if worn, wielded, or a monster.
inline bool uam9CrystalTouchRequiresHit()
    { return true; }

// A single metal item is affected per casting - a worn
// suit of armor changes but the shield does not, or vice
// versa.
inline bool uam9CrystalSingleItemPerCasting()
    { return true; }

// Items save by their magical bonus value or protection:
// a +1/+3 sword gets a 10% chance (the average of the two
// plusses).
inline int uam9CrystalSwordSavePct()
    { return 10; }

// +5 magic armor gets a 25% chance to be unaffected.
inline int uam9CrystalArmorSavePct()
    { return 25; }

// An iron golem gets a 15% chance (hit only by +3 or
// better weapons).
inline int uam9CrystalGolemSavePct()
    { return 15; }

// Artifacts and relics of metal have a 95% chance to be
// unaffected.
inline int uam9CrystalArtifactSavePct()
    { return 95; }

// Unprotected items are shattered and permanently
// destroyed if struck by a normal blow from a metal tool
// or any weighty weapon, including a staff.
inline bool uam9CrystalDestroyedByWeightyBlow()
    { return true; }

// ---- succor (Alteration - Enchantment), reversible ----
inline const char* uam9SuccorName()
    { return "Succor (Alteration - Enchantment)"; }

inline bool uam9SuccorReversible()
    { return true; }

// The level cell is lost - the level pins from the
// section heading.
inline bool uam9SuccorLevelCellLost()
    { return true; }

inline int uam9SuccorLevel()
    { return 9; }

// The stat head prints only the Duration and Area cells;
// the Components, Casting Time and Save print in an
// interleaved tail after the prose.
inline bool uam9SuccorStatTailInterleaved()
    { return true; }

inline bool uam9SuccorComponentsVSM()
    { return true; }

// The casting garbles - a 17-to-4 days print; the leading
// fragment reads as 1, flagged pending the PDF.
inline int uam9SuccorCastingTimeDaysMin()
    { return 1; }

inline int uam9SuccorCastingTimeDaysMax()
    { return 4; }

inline bool uam9SuccorCastingPrintGarbled()
    { return true; }

inline bool uam9SuccorDurationSpecial()
    { return true; }

inline bool uam9SuccorSaveNone()
    { return true; }

inline bool uam9SuccorAoeOneIndividual()
    { return true; }

// The spell is the same as the 7th-level cleric spell of
// the same name.
inline bool uam9SuccorSameAsClericSeventh()
    { return true; }

// The magic-user version teleports without error the
// individual who breaks the object and speaks the command
// word - the R361 teleport exception.
inline bool uam9SuccorTeleportsWithoutError()
    { return true; }

// The reverse likewise brings the archmage to the presence
// of the individual.
inline bool uam9SuccorReverseBringsArchmage()
    { return true; }

// Unlike the cleric spell, the summoned archmage has no
// choice but to answer - making this version rare indeed.
inline bool uam9SuccorArchmageHasNoChoice()
    { return true; }

// Interference causes irrevocable loss of the individual
// or spell caster involved in the succor - the sentence
// scrambles, flagged pending the PDF.
inline bool uam9SuccorInterferenceIrrevocableLoss()
    { return true; }

inline bool uam9SuccorInterferenceSentenceScrambled()
    { return true; }

// The material component is gem material of not less than
// 5,000 gp value; faceted or not is immaterial.
inline int uam9SuccorGemGpMin()
    { return 5000; }

// The components can only be enchanted once per month -
// usually on the night of a clear, full moon - set then
// for the type of succor and its final destination.
inline bool uam9SuccorEnchantedOncePerMonth()
    { return true; }

inline bool uam9SuccorSetOnFullMoonNight()
    { return true; }

inline bool uam9SuccorSetForTypeAndDestination()
    { return true; }

// ---- energy drain (Evocation) ----
inline const char* uam9EnergyName()
    { return "Energy Drain (Evocation)"; }

inline bool uam9EnergyComponentsVSM()
    { return true; }

inline int uam9EnergyLevel()
    { return 9; }

// The stat block scrambles - the 3 segments displace above
// the Casting Time line; pinned as printed.
inline int uam9EnergyCastingTimeSegments()
    { return 3; }

inline bool uam9EnergyCastingCellDisplaced()
    { return true; }

inline bool uam9EnergyRangeTouch()
    { return true; }

// The duration and save cells never print - holes pending
// the PDF, not pinned as data.
inline bool uam9EnergyDurationCellLost()
    { return true; }

inline bool uam9EnergySaveCellLost()
    { return true; }

inline bool uam9EnergyAoeOneCreature()
    { return true; }

// The spell opens a channel between the caster's plane and
// the Negative Material Plane, the caster becoming the
// conductor between the two.
inline bool uam9EnergyNegativePlaneChannel()
    { return true; }

inline bool uam9EnergyCasterIsConductor()
    { return true; }

// A touch (equal to a hit in melee) drains two energy
// levels from any living creature, as if struck by a
// spectre.
inline int uam9EnergyLevelsDrained()
    { return 2; }

inline bool uam9EnergyAsSpectre()
    { return true; }

// A monster loses two hit dice permanently - hit points
// and attack ability both.
inline int uam9EnergyHitDiceDrained()
    { return 2; }

// A character loses levels, hit dice, hit points and
// abilities permanently - until regained through
// adventuring, if applicable.
inline bool uam9EnergyCharacterLossPermanent()
    { return true; }

// The material: essence of spectre or vampire dust - the
// print loses the spectre word, flagged pending the PDF.
inline bool uam9EnergyMaterialSpectreOrVampireDust()
    { return true; }

inline bool uam9EnergyMaterialWordLost()
    { return true; }

// The three-segments phrase scrambles into the material
// sentence - flagged pending the PDF.
inline bool uam9EnergyMaterialSentenceScrambled()
    { return true; }

// The component is cast forth; upon touching the victim
// the caster speaks the triggering word, and the dweomer
// takes effect instantly.
inline bool uam9EnergyTriggeringWord()
    { return true; }

// A 5% chance (1 in 20) that the caster is also drained of
// one energy level as the victim loses two.
inline int uam9EnergyCasterRiskPct()
    { return 5; }

inline int uam9EnergyCasterRiskLevels()
    { return 1; }

// Humans or humanoids brought to zero energy level become
// juju zombies.
inline bool uam9EnergyZeroLevelJujuZombies()
    { return true; }

// ---- the Mordenkainen disjunction ----
// The name header garbles to a bare possessive fragment;
// the name pins from the gap item list and the prose. The
// school is lost pending the PDF.
inline const char* uam9DisjunctionName()
    { return "Mordenkainen's Disjunction"; }

inline bool uam9DisjunctionNameHeaderGarbled()
    { return true; }

inline bool uam9DisjunctionSchoolLost()
    { return true; }

// The components cell prints bare - a hole pending the
// PDF, not pinned as data.
inline bool uam9DisjunctionComponentsCellLost()
    { return true; }

inline int uam9DisjunctionLevel()
    { return 9; }

inline int uam9DisjunctionRangeZero()
    { return 0; }

inline int uam9DisjunctionCastingTimeSegments()
    { return 9; }

inline bool uam9DisjunctionDurationPermanent()
    { return true; }

inline bool uam9DisjunctionSaveSpecial()
    { return true; }

inline int uam9DisjunctionAoeRadiusInches()
    { return 3; }

// All magic and magic items within the radius are
// disjoined, except those on the person of or being
// touched by the spell caster.
inline bool uam9DisjunctionDisjoinsAllMagic()
    { return true; }

inline bool uam9DisjunctionCasterPersonExempt()
    { return true; }

// Spells being cast are separated into their individual
// components and the effect spoiled, as does a dispel
// magic.
inline bool uam9DisjunctionSpoilsSpellsBeingCast()
    { return true; }

// Items must save - versus spell if actually cast upon a
// creature, versus dispel magic otherwise - or be turned
// into normal items.
inline bool uam9DisjunctionItemsSaveOrBecomeNormal()
    { return true; }

inline bool uam9DisjunctionItemSaveVsSpellIfCreature()
    { return true; }

// Even artifacts and relics are subject to the disjunction
// - a 1% chance per caster level of actually affecting
// such powerful items.
inline int uam9DisjunctionArtifactPctPerLevel()
    { return 1; }

// Thus all potions, scrolls, rings, rods et al,
// miscellaneous magic items, artifacts and relics, arms
// and armor, swords and miscellaneous weapons within 3
// inches of the caster can possibly lose all their
// magical properties.
inline bool uam9DisjunctionAffectsAllItemClasses()
    { return true; }

// Destroying artifacts is dangerous business - 95% likely
// to attract the attention of some powerful being with an
// interest or connection with the device.
inline int uam9DisjunctionArtifactAttentionPct()
    { return 95; }

// If an artifact is destroyed, the casting magic-user must
// save versus spell at -4 or permanently lose all spell
// casting abilities.
inline int uam9DisjunctionArtifactDestroySaveAdj()
    { return -4; }

inline bool uam9DisjunctionCasterMayLoseCasting()
    { return true; }

}   // namespace rules

