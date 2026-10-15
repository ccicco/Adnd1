// =========================================================================================
// Adnd1 - rules/wsgfae.h
// R481: the WSG FIRST AID EQUIPMENT slice, printed p. 71 - the eleventh
// camping-arc round and the LAST of the medicine chapter, a pure prose round
// with NO table: the four essentials - bandages, splints, stretcher and
// litter - with the party gear-advice frame (nobody goes through an adventure
// unscathed, so pack the materials for administering aid to the injured).
// census 405 -> 406.
//
// The settle: two-way clean on the first pass - the tesseract full-text read
// and the pdfy layout read agree on every number of the section (the 2-3 foot
// splint length, the two-pole stretcher, the half-weight carry bars), and the
// tsv confirms the geometry cell by cell; no contested cells, no vision reads
// needed. The skin ailments and other-injuries prose at the top of the page
// belongs to the injuries chapter landed at R480 and stays out of scope here.
//
// Bounds held: the splint length runs 2-3 feet; both carry bars use one-half
// of the victim weight - two carriers on a stretcher, one on a litter.
//
namespace rules {

// ---- The gear-advice frame ----

// it is a good idea for the party gear to include the materials for
// administering aid to the injured in the line of duty
inline bool wfePartyPacksAidMaterials()
    { return true; }

// four essentials: bandages, splints, stretcher, litter
inline int wfeEquipmentKindCount()
    { return 4; }

// ---- Bandages ----

// at least one backpack should contain several swatches of clean fabric for
// covering and binding wounds and burns
inline bool wfeBandagesCleanFabric()
    { return true; }

// in a pinch an article of clothing torn into strips can be used for bandages
inline bool wfeClothingStripsInPinch()
    { return true; }

// an adventurer clothing is usually not clean, so infection remains possible
// even when the wound is bandaged
inline bool wfeClothingCarriesInfection()
    { return true; }

// ---- Splints ----

// splints may be unnecessary when the journey passes through a wooded area
inline bool wfeSplintsUnneededInWood()
    { return true; }

// for a mountain climb or a desert crossing it is wise to pack a couple of
// straight, short rigid pieces bound along the sides of a broken limb to keep
// the bones properly aligned
inline bool wfeSplintsPackedForMountainDesert()
    { return true; }

// the packed splint pieces are 2-3 feet long
inline int wfeSplintMinFeet()
    { return 2; }

// the top of the splint length range
inline int wfeSplintMaxFeet()
    { return 3; }

// a large piece of thick leather or untanned hide works as a splint if large
// and rigid enough to immobilize the limb and the joints on both sides, like
// a plaster cast
inline bool wfeLeatherHideAsSplint()
    { return true; }

// ---- The stretcher ----

// most groups carry the stretcher parts separately and assemble the stretcher
// if and when it is needed
inline bool wfeStretcherPartsCarriedSeparately()
    { return true; }

// the stretcher needs a pair of poles
inline int wfeStretcherPoleCount()
    { return 2; }

// the poles must be at least as long as the injured character height
inline bool wfeStretcherPolesAsTallAsVictim()
    { return true; }

// sturdy cloth or leather large enough to recline on, plus rope or cord of
// sufficient length to bind the poles to the edges
inline bool wfeStretcherNeedsSurfaceAndBinding()
    { return true; }

// two comrades carry a stretcher-borne victim
inline int wfeStretcherCarriers()
    { return 2; }

// each carrier supports half of the victim weight
inline int wfeHalfNum()
    { return 1; }

// the half-weight fraction on both stretcher and litter
inline int wfeHalfDen()
    { return 2; }

// two comrades can carry the victim as long as each supports half the weight
// without being too encumbered to move
inline bool wfeStretcherTwoCarryHalfEach()
    { return true; }

// ---- The litter ----

// the litter is essentially the same as a stretcher, except extra rope or
// cord binds the victim to the frame
inline bool wfeLitterSameAsStretcher()
    { return true; }

// one carrier suffices for a bound litter victim
inline int wfeLitterCarriers()
    { return 1; }

// one character, mount or beast of burden can transport the bound victim
// while supporting half the weight
inline bool wfeLitterOneCarrierOrBeast()
    { return true; }

// it is usually not wise to transport a litter over rugged or very rugged
// terrain
inline bool wfeLitterUnwiseOnRugged()
    { return true; }

// one end of the litter is always on the ground and the victim is jostled as
// it skids and bumps along
inline bool wfeLitterDragsAndJostles()
    { return true; }

// if the victim must be kept motionless, the DM may rule that a rugged trip
// causes further damage from the rough handling
inline bool wfeDmMayRuleRoughHandlingDamage()
    { return true; }

}   // namespace rules
