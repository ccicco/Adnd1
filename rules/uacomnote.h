// ===========================================================================
// Adnd1 - rules/uacomnote.h
// The UA COMELINESS CREATION NOTE
// (p. 74) pins, R373: the DM
// pointer in the DM section's
// CHARACTER ABILITIES - the
// attribute fully described on
// pages 6 and 7 of this volume,
// while it might more properly be
// called a characteristic, it
// does have effects (in game
// terms) upon those viewing or
// reacting to the character. The
// creation ride: the R322 pins
// carry the roll and the
// adjustments - checked in the
// regtest audit, not here. The
// trailing sentence of the
// printed note garbles in the
// extract - flagged.
namespace rules {

// The pointer pages of this
// volume.
inline int uacmPointerFirstPage()
    { return 6; }

inline int uacmPointerSecondPage()
    { return 7; }

// The attribute is fully
// described on the pointer
// pages.
inline bool uacmFullyDescribedOnPointerPages()
    { return true; }

// While it might more properly
// be called a characteristic.
inline bool uacmMoreProperlyCharacteristic()
    { return true; }

// It does have effects in game
// terms upon those viewing the
// character.
inline bool uacmAffectsViewers()
    { return true; }

// ... upon those reacting to the
// character.
inline bool uacmAffectsReactors()
    { return true; }

// "As shown above, human player"
// - the human example opens
// before the extract garbles.
inline bool uacmShownAboveForHumans()
    { return true; }

// The trailing sentence garbles
// beyond decode - a hole
// awaiting the PDF.
inline bool uacmTrailingSentenceGarbles()
    { return true; }

}   // namespace rules

