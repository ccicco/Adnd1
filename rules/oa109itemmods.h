// =========================================================================================
// Adnd1 - rules/oa109itemmods.h
// OA TREASURE - THE MODIFICATIONS TO STANDARD MAGICAL ITEMS, printed capture
// p. 286 - the occidental items round
// census 660 -> 661.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 191 closed, 44 open - the item mods box
// flips (census 660 -> 661); NEXT - R739: Potions (capture p. 287), prefix
// dla (verify free at the landing), audit "R739 OA potions audit", include
// after rules/oa109itemmods.h
//
namespace rules {

// ---- the occidental items rule ----

// the majority - most of the DMG magical items available throughout the world
// of the Orient (print capture p. 286)
inline int dkzMajorityAvailable()
    { return 1; }

// the exceptions - some items particularly occidental (print capture p. 286)
inline int dkzSomeParticularlyOccidental()
    { return 1; }

// the appearance rule - the occidental items do not appear normally in the
// Oriental world (print capture p. 286)
inline int dkzDoNotAppearNormally()
    { return 1; }

// the difference rule - if they do appear, they are somewhat different from
// those listed in the DMG (print capture p. 286)
inline int dkzOrSomewhatDifferent()
    { return 1; }

// the use clause - there may be little or no use for the items in the
// Oriental setting (print capture p. 286)
inline int dkzLittleOrNoUse()
    { return 1; }

// the culture clause - they may not be items found within the culture (print
// capture p. 286)
inline int dkzNotWithinCulture()
    { return 1; }

// the allowance - this is not to say they cannot appear (print capture p.
// 286)
inline int dkzNotToSayCannotAppear()
    { return 1; }

// the commonness - only that their construction and use is far from common
// (print capture p. 286)
inline int dkzConstructionFarFromCommon()
    { return 1; }

// ---- the three sources ----

// the general rule - if any of the items below appear as presented in the DMG
// in an Oriental setting (print capture p. 286)
inline int dkzGeneralRuleIfAsPresented()
    { return 1; }

// the gajin count - the three sources of an item appearing as printed in the
// DMG in an Oriental setting: the gajin bringing it in, the import as a
// curiosity, the inspired or deranged spell caster assembling it (print
// capture p. 286)
inline int dkzGajinThreshold()
    { return 3; }

// the gajin source - brought in by gajin, the capture misreading the gaijin
// (print capture p. 286)
inline int dkzBroughtInByGajin()
    { return 1; }

// the import source - imported as curiosities (print capture p. 286)
inline int dkzImportedAsCuriosities()
    { return 1; }

// the caster source - assembled by some inspired or deranged spell caster
// (print capture p. 286)
inline int dkzAssembledByInspiredCaster()
    { return 1; }

// ---- the form changes ----

// the form - the DMG items generally, although not always, occidental in form
// and function (print capture p. 286)
inline int dkzGenerallyOccidentalForm()
    { return 1; }

// the form change count - the four examples of the occidental form taking an
// Oriental shape: the lyre, cloak, boots, and bags (print capture p. 286)
inline int dkzFormChangeCount()
    { return 4; }

// the lyre example - a known instrument in occidental lands taking the form
// of a samisen or flute in the Orient (print capture p. 286)
inline int dkzLyreSamisenOrFlute()
    { return 1; }

// the cloak example - a cloak becoming a robe or jacket (print capture p.
// 286)
inline int dkzCloakRobeOrJacket()
    { return 1; }

// the boots example - boots becoming sandals (print capture p. 286)
inline int dkzBootsSandals()
    { return 1; }

// the bags example - bags becoming boxes (print capture p. 286)
inline int dkzBagsBoxes()
    { return 1; }

// the decision - it is the DM's decision to alter the form of any item, the
// capture misreading after for the alter (print capture p. 286)
inline int dkzDMDecidesForm()
    { return 1; }

// the function clause - this does not affect the function of the item in any
// way (print capture p. 286)
inline int dkzFunctionUnaffected()
    { return 1; }

}   // namespace rules
