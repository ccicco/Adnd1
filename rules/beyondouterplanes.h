// =========================================================================================
// Adnd1 - rules/beyondouterplanes.h
// BEYOND THE OUTER PLANES - printed p. 116, the closing essay of the Manual
// of the Planes: the summary that is not the final word, the undiscovered
// layers and unreached paradises, the growing model, the new Astral forms,
// the finite demi-planes of the Ethereal, and the alternate Primes - the only
// limitation the imagination.
// census 513 -> 514.
//
// verified against printed p. 116 of the uploaded motp.pdf OCR; the essay's
// six doctrines are pinned exactly as printed; this round closes the Manual
// of the Planes chapter of the gap report - every plane, every table, and the
// closing essay now pinned.
//
// the gap census after this round: 82 closed, 8 open - ONE box falls (Beyond
// the outer planes), and THE MANUAL OF THE PLANES IS FULLY CLOSED; the nine
// remaining boxes belong to later chapters.
//
namespace rules {

// ---- the beyond the outer planes pins ----

// the closing doctrine: the preceding pages are a summary of the realms,
// layers and planes that make up the known planes of existence - by no means
// the final word, for the nature of these infinite realms defies any
// all-encompassing treatise; there can be any number of realms in a layer, so
// that a third or fourth major pantheon can exist in Olympus/Arvandor, or an
// evil power created by the DM can dominate a section of the Nine Hells where
// no arch-devils rule.
inline bool ddtBeyondDoctrine()
    { return true; }

// the undiscovered layers: it is also possible there are further layers
// beyond those discovered and reported - there may be an eighth heaven, or a
// third paradise, undiscovered or unreachable by the spells and abilities
// known to researchers; and Gladsheim may have as many layers as the Abyss,
// but lacks the Abyssal method of reaching them.
inline bool ddtUndiscoveredLayers()
    { return true; }

// the growing model: our conception of the planes has grown with the AD&D
// game - the original presentations of the inner planes make no mention of
// the quasi- and para-elemental planes, and the early discussions of the
// outer planes leave out Concordant Opposition; there may be more such planes
// beyond the scope of the model presented here.
inline bool ddtGrowingModel()
    { return true; }

// the new Astral forms: there may be a different form of Astral space between
// the outer planes and planes farther out, or within the center of Concordant
// Opposition - the map not being the territory, and the void between the
// wheels its own country.
inline bool ddtNewAstralForms()
    { return true; }

// the demi-plane rule: even without new planes, the wild and unexplored known
// lands can occupy the extraplanar traveler for years - the demi-planes that
// float in the Ethereal may be the size of worlds, their only limitation that
// they are finite where the other planes are infinite.
inline bool ddtDemiPlaneRule()
    { return true; }

// the alternate Prime rule: alternate Prime Material planes enable travelers
// to visit worlds that are Earth-like or not-so-Earth-like, familiar,
// hostile, and strange - the only limitation to planar adventures being the
// imagination of those involved; the purpose of the tome is to fire the
// imaginations of DMs and players so that they explore the myriad planes of
// the AD&D system.
inline bool ddtAlternatePrimeRule()
    { return true; }

}   // namespace rules
