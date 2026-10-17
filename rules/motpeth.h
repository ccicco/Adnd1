// =========================================================================================
// Adnd1 - rules/motpeth.h
// THE MotP ETHEREAL CHAPTER - printed pp. 11-21 in one round: the Border and
// Deep Ethereal, survival, encounters, combat, magic, the player characters
// and the demi-planes - with the amended manifest (90 boxes) landing in the
// same commit and the 2-20 doctrine closing with the chapter.
// census 489 -> 490.
//
// the full-book table scan found 30 named tables, charts and frequencies the
// TOC-level boxes subsumed; the amendment enumerates every one as its own
// line item - the census grows 60 to 90, nothing auto-closes. The chapter
// pins verified against printed pp. 11-21 of the uploaded motp.pdf OCR.
//
// the gap census after this round: 18 closed, 72 open - the Deep check and
// the sample charts close on the chapter's own pins, the first of the
// enumerated items to fall.
//
namespace rules {

// ---- the Ethereal chapter pins ----

// the book-wide custom encounter chart doctrine (p. 7): the d8+d12 roll
// generates the 2-20 die range - the low end.
inline int dcuCustomChartLow()
    { return 2; }

// the 2-20 range high end: a 2 or a 20 is the unique-powers slot on every
// custom chart in the book.
inline int dcuCustomChartHigh()
    { return 20; }

// the Ethereal subjective-time factor: for every 10 turns that pass, the
// effects are as if a single turn passed - aging at the subjective rate (a
// ghost ages 1d4 years, not 10-40; a potion of longevity restores 10%).
inline int dcuEtherealTimeFactor()
    { return 10; }

// clear vision extends about 100 yards in the thick soup of the plane;
// encounter distances run 80-120 yards; infravision fails (same temperature
// as the surroundings), ultravision works normally.
inline int dcuEtherealVisionYards()
    { return 100; }

// becoming ethereal takes a round to fade away; leaving rematerializes in one
// round; the phase spider pattern - reappear and bite in one round, the next
// round to return to the ethereal state.
inline int dcuFadeRounds()
    { return 1; }

// Deep Ethereal encounters: a 1-in-10 chance every four hours, or whenever
// someone steps through a curtain; the Border Ethereal follows the bordering
// plane's matrices.
inline int dcuDeepEncounterChance()
    { return 10; }

// magical weapons are reduced by one plus (a long sword +2, +3 vs reptiles
// becomes +1, +2 vs reptiles); armor and protection devices likewise lose one
// plus - except weapons keyed to ethereal or ethereal-affecting creatures,
// which remain unimpaired.
inline int dcuMagicPlusReduction()
    { return 1; }

// the Ethereal works very well for the thief: add +20% to hide in shadows and
// move silently; climb sheer surfaces has little effect.
inline int dcuThiefShadowBonus()
    { return 20; }

// the four named demi-planes: Shadow (the silver curtain), Time (translucent,
// the 1d10-years-younger risk), Electro-Magnetism (the copper curtain, dying
// into Lightning), and Imprisonment (the legend, curtain color unrecorded).
inline int dcuDemiPlaneNamedCount()
    { return 4; }

// the Ethereal has an up and a down, but falling is impossible: the traveler
// and the medium are the same substance and it supports all objects.
inline bool dcuNoFallingEth()
    { return true; }

// normal weapons inflict 0 base damage on ethereal targets - Strength,
// Dexterity and specialization bonuses still apply; magical weapons
// (retaining at least +1) inflict full damage; normal armor is ignored (AC
// 10) with Dexterity still applying.
inline bool dcuNormalWeaponsZeroBase()
    { return true; }

// the Border Ethereal traveler is invisible to the bordering plane (revealed
// as a smoky shade by detect etherealness or detect invisible), cannot attack
// across the border nor be attacked across it - phase door and dispel magic
// can pull beings out.
inline bool dcuBorderCrossingBlind()
    { return true; }

// natural healing occurs at the subjective rate - 10 times slower than on the
// Prime; a raised character rests 10 days for every day dead; golem and clone
// times run in subjective time.
inline bool dcuHealingSubjectiveSlow()
    { return true; }

}   // namespace rules
