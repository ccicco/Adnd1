// =========================================================================================
// Adnd1 - rules/oa79buso.h
// OA MONSTERS - THE BUSO, printed capture pp. 256-257 - the two-type ghoul
// round
// census 630 -> 631.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 161 closed, 74 open - the Buso box flips
// (census 630 -> 631); NEXT - R709: the Carp, Giant (capture p. 257), prefix
// djw (verify free at the landing), audit "R709 OA monsters Giant Carp
// audit", include after rules/oa79buso.h
//
namespace rules {

// ---- the stat block ----

// the Buso type count - the tigbanua and the tagamaling of the two-column
// stat block (print capture p. 256)
inline int djvBusoTypesCount()
    { return 2; }

// the Buso appearance minimum - the 1 of the 1-6 of the stat block (print
// capture p. 256)
inline int djvBusoNoAppearingMin()
    { return 1; }

// the Buso appearance maximum - the 6 of the 1-6 of the stat block (print
// capture p. 256)
inline int djvBusoNoAppearingMax()
    { return 6; }

// the tigbanua armor class - the AC 4 of the stat block (print capture p.
// 256)
inline int djvBusoTigbanuaAC()
    { return 4; }

// the Buso movement rate - the move 12 of both columns (print capture p. 256)
inline int djvBusoMove()
    { return 12; }

// the tigbanua hit dice - the 8 of the 8 + 2 of the stat block (print capture
// p. 256)
inline int djvBusoTigbanuaHDNum()
    { return 8; }

// the tigbanua hit-dice modifier - the + 2 of the 8 + 2 (print capture p.
// 256)
inline int djvBusoTigbanuaHDMod()
    { return 2; }

// the Buso attacks per round - the 3 of both columns (print capture p. 256)
inline int djvBusoAttacks()
    { return 3; }

// the tigbanua damage minimum - the 1 of the 1-6/1-6/1-10 (print capture p.
// 256)
inline int djvBusoTigbanuaDmgMin()
    { return 1; }

// the tigbanua mid damage - the first 6 of the 1-6/1-6/1-10 (print capture p.
// 256)
inline int djvBusoTigbanuaDmgMid()
    { return 6; }

// the tigbanua damage maximum - the 10 of the 1-6/1-6/1-10 (print capture p.
// 256)
inline int djvBusoTigbanuaDmgMax()
    { return 10; }

// the tigbanua base experience - the 1,400 of the VII/1,400 (print capture p.
// 256)
inline int djvBusoTigbanuaXPBase()
    { return 1400; }

// the tigbanua experience per hit point - the 12/hp of the stat block (print
// capture p. 256)
inline int djvBusoTigbanuaXPPerHP()
    { return 12; }

// the tagamaling armor class - the AC 5 of the stat block (print capture p.
// 256)
inline int djvBusoTagamalingAC()
    { return 5; }

// the tagamaling damage minimum - the 1 of the 1-4/1-4/1-8 (print capture p.
// 256)
inline int djvBusoTagamalingDmgMin()
    { return 1; }

// the tagamaling mid damage - the first 4 of the 1-4/1-4/1-8 (print capture
// p. 256)
inline int djvBusoTagamalingDmgMid()
    { return 4; }

// the tagamaling damage maximum - the 8 of the 1-4/1-4/1-8 (print capture p.
// 256)
inline int djvBusoTagamalingDmgMax()
    { return 8; }

// the Buso frequency - the uncommon of both columns of the stat block (print
// capture p. 256)
inline int djvBusoUncommon()
    { return 1; }

// the Buso in-lair percentage - the Nil of both columns (print capture p.
// 256)
inline int djvBusoLairNil()
    { return 1; }

// the Buso treasure - the Nil of both columns (print capture p. 256)
inline int djvBusoTreasureNil()
    { return 1; }

// the Buso magic resistance - the standard of both columns (print capture p.
// 256)
inline int djvBusoMRStandard()
    { return 1; }

// the Buso intelligence - the animal of both columns (print capture p. 256)
inline int djvBusoIntAnimal()
    { return 1; }

// the Buso alignment - the chaotic evil of both columns (print capture p.
// 256)
inline int djvBusoChaoticEvil()
    { return 1; }

// the Buso size - the M of both columns (print capture p. 256)
inline int djvBusoSizeM()
    { return 1; }

// the Buso psionics - the Nil ability and the Nil attack/defense modes of
// both columns (print capture p. 256)
inline int djvBusoPsionicNil()
    { return 1; }

// ---- the nature ----

// the Buso nature - fearsome ghoul-like creatures (print capture p. 257)
inline int djvBusoGhoulLike()
    { return 1; }

// the Buso habitat - normally found near cemeteries or in forests or rocky
// mountains (print capture p. 257)
inline int djvBusoCemeteryHabitat()
    { return 1; }

// the Buso history - once friendly and helpful to men, now one of mankind
// deadly enemies (print capture p. 257)
inline int djvBusoOnceFriendlyNowEnemies()
    { return 1; }

// the Buso predation - under the cloak of night they prey on lone travelers
// and helpless villages (print capture p. 257)
inline int djvBusoNightPredators()
    { return 1; }

// the Buso build - exceptionally tall and lean, long bodies and necks, bony
// oversized feet, curly dirty hair, flat noses (print capture p. 257)
inline int djvBusoTallLean()
    { return 1; }

// the Buso eye - a single eye in the head, either red or yellow (print
// capture p. 257)
inline int djvBusoSingleEye()
    { return 1; }

// ---- the tigbanua ----

// the tigbanua fear aura - the 10-foot radius (print capture p. 257)
inline int djvTigbanuaFearRadiusFt()
    { return 10; }

// the tigbanua temperament - extremely ferocious, attacks whenever it has the
// opportunity (print capture p. 257)
inline int djvTigbanuaFerocious()
    { return 1; }

// the tigbanua aura - radiates a fear aura out to the 10-foot radius (print
// capture p. 257)
inline int djvTigbanuaFearAura()
    { return 1; }

// the tigbanua aura rule - creatures with less than 1 HD are automatically
// paralyzed (print capture p. 257)
inline int djvTigbanuaLessThanOneHDAutoParalyzed()
    { return 1; }

// the tigbanua aura rule - creatures with 1 HD or more receive a saving throw
// vs. paralyzation to avoid the effect (print capture p. 257)
inline int djvTigbanuaSaveVsParalyzation()
    { return 1; }

// the tigbanua aura rule - creatures remain paralyzed until they are no
// longer in the radius (print capture p. 257)
inline int djvTigbanuaParalyzedUntilOutOfRadius()
    { return 1; }

// the tigbanua aura rule - a successful save grants immunity to the fear aura
// for the remainder of the encounter (print capture p. 257)
inline int djvTigbanuaSaveGrantsEncounterImmunity()
    { return 1; }

// the tigbanua attack form - the sharp claws and fangs (print capture p. 257)
inline int djvTigbanuaClawsAndFangs()
    { return 1; }

// the tigbanua claw - transmits a horrible disease (print capture p. 257)
inline int djvTigbanuaClawDisease()
    { return 1; }

// the tigbanua disease rule - all wounded by the creature must make a
// successful saving throw vs. death or become infected (print capture p. 257)
inline int djvTigbanuaSaveVsDeathOrInfected()
    { return 1; }

// the tigbanua disease outcome - those infected eventually become tagamaling
// (print capture p. 257)
inline int djvTigbanuaInfectedBecomeTagamaling()
    { return 1; }

// the tigbanua mind - not noted for its intelligence (print capture p. 257)
inline int djvTigbanuaLowIntelligence()
    { return 1; }

// ---- the tagamaling ----

// the tagamaling transformation - the 1% cumulative nightly chance that the
// diseased person transforms (print capture p. 257)
inline int djvTagamalingTransformChancePct()
    { return 1; }

// the tagamaling disease limit - once the disease reaches 100% the victim can
// no longer be cured (print capture p. 257)
inline int djvTagamalingIncurablePct()
    { return 100; }

// the tagamaling origin - a person infected by a tigbanua (print capture p.
// 257)
inline int djvTagamalingInfectedPerson()
    { return 1; }

// the tagamaling change - the disease periodically transforms the person, the
// body changing into that of a buso (print capture p. 257)
inline int djvTagamalingNightlyTransformation()
    { return 1; }

// the tagamaling temperament - savage and mindless, attacking and devouring
// any and all (print capture p. 257)
inline int djvTagamalingSavageMindless()
    { return 1; }

// the tagamaling vitality - the same hit dice and hit points as the person
// possesses in normal life (print capture p. 257)
inline int djvTagamalingSameHDHPAsPerson()
    { return 1; }

// the tagamaling hit dice - the special entry of the stat block, variable
// with the host (print capture p. 256)
inline int djvTagamalingHDVariable()
    { return 1; }

// the tagamaling limitation - characters with special abilities cannot use
// their powers while transformed (print capture p. 257)
inline int djvTagamalingPowersUnusable()
    { return 1; }

// the tagamaling amnesia - the diseased person has no memory of any actions
// done as a tagamaling (print capture p. 257)
inline int djvTagamalingNoMemory()
    { return 1; }

// the tagamaling end state - at 100% the victim changes into a tagamaling
// every night (print capture p. 257)
inline int djvTagamalingNightlyAtLimit()
    { return 1; }

}   // namespace rules
