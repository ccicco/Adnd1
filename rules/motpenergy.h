// =========================================================================================
// Adnd1 - rules/motpenergy.h
// THE MotP ENERGY PLANES - printed p. 54, Positive and Negative in one round:
// the gain-and-explode rule, the drain rule, the protection paradox, the
// weakened Border Ethereal, and the features (the xeg-ya and xeg-yi, the
// trilloch, the undead link).
// census 496 -> 497.
//
// verified against printed p. 54 of the uploaded motp.pdf OCR; the energy
// planes pin their own text exclusively - the R567 inner-planes doctrine
// frame supplies the general rules, this round the particulars.
//
// the gap census after this round: 36 closed, 54 open - two boxes fall (the
// energy planes, the encounter frequency); the positive quasi-planes are
// next.
//
namespace rules {

// ---- the energy planes pins ----

// the Positive Material plane, the Plane of Life: every round an unprotected
// character gains 2d6 hit points - at greater than twice his original total
// he EXPLODES; escape first and the extra points fade in 1d20 true turns
// (damage taken from them first).
inline int ddbPositiveGainDieSides()
    { return 6; }

// the Negative Material plane, the Plane of Death: the unprotected traveler
// loses 2d6 hit points AND one level or hit die per round; at zero hit points
// or levels he shrivels and dies.
inline int ddbNegativeDrainDieSides()
    { return 6; }

// vision and detection are limited to 10 yards - the light of the Positive
// and the darkness of the Negative are each too intense to see farther.
inline int ddbEnergyVisionYards()
    { return 10; }

// the Border Ethereal is WEAKENED by the energy planes: each turn spent in it
// carries a 10% chance the Border pulls back and strands the traveler in the
// adjoining energy plane.
inline int ddbBorderCollapsePct()
    { return 10; }

// the xeg-ya and xeg-yi, the two known inhabitants: mindless but possibly
// persuadable as guides, on a roll of 8 or better on 2d6 - and no inducement
// changes the creature's mind if the roll fails.
inline int ddbXegGuideRoll()
    { return 8; }

// the energy planes are thoroughly hostile to outside life, worse than the
// four majors put together - no Greater, Lesser or Demi-Powers inhabit them.
inline bool ddbEnergyHostile()
    { return true; }

// the only protections are negative/positive plane protection - but they
// CANNOT be cast in the energy planes (they draw on the opposite plane);
// elemental protections cannot be modified to cover energy effects.
inline bool ddbProtectionParadox()
    { return true; }

// you cannot breathe energy, nor transform it into a breathable mixture (airy
// element fails): only breath-negating devices (an ibo stone) or spells
// permit more than breath-holding time.
inline bool ddbNoBreathingEnergy()
    { return true; }

// there are NO random encounters in the energy planes: the destructive nature
// of the plane quickly destroys elemental pockets, and the native creature
// types remain undetermined.
inline bool ddbNoRandomEncounters()
    { return true; }

// the magic rule: created matter is destroyed one round after creation
// (exploding in harmless motes in the Positive, collapsing to dust in the
// Negative); variable spells deal MAXIMUM damage in the Positive, MINIMUM in
// the Negative; multi-round damage spells last one round; summoned creatures
// of average-plus intelligence may simply decline to appear.
inline bool ddbMagicMaxMinRule()
    { return true; }

// many undead draw their animating force from the Negative Material - the
// source of their level and ability drains - yet no undead are recorded IN
// either energy plane, only in the quasi-planes; the trilloch, the energy
// vulture, thrives in the Negative after its demi-plane was consumed.
inline bool ddbUndeadNegativeLink()
    { return true; }

}   // namespace rules
