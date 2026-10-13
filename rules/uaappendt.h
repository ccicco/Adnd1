// ==========================================================================
// Adnd1 - rules/uaappendt.h
// The UA APPENDIX T: POLE-ARM
// NOMENCLATURE pins, R391: the
// pp. 123-129 stretch - seven
// items, two fully clean (the
// spear family, the axe family)
// plus five mechanics-clean with
// flagged holes (the
// classification system
// paragraph, the fauchard
// description, the Lucern/bec
// comparison tail, the
// combination intro and features
// list, the confusion sentence)
// - RESOLVED (R424): the clean
// pp. 123-128 read resolves all
// five; the seven items stand
// fully clean. The taxonomy
// pairs with the R340 new
// weapons roster (the hook
// fauchard seam). Pin-era
// pattern (R322).
namespace rules {

// The definition: a pole arm
// is a weapon on the end of a
// stick.
inline bool uapaDefWeaponOnStick()
    { return true; }
// Pole arms are infantry
// weapons.
inline bool uapaInfantryWeapons()
    { return true; }
// The reach lets the wielder
// strike first or hold the
// enemy at a distance.
inline bool uapaReachAdvantage()
    { return true; }
// The ultimate pole arm: the
// 18-21 foot pike.
inline int uapaUltimatePikeMinFt()
    { return 18; }
// The pike upper bound.
inline int uapaUltimatePikeMaxFt()
    { return 21; }
// An axe blade on a 5-foot
// haft is just as much a pole
// arm.
inline bool uapaAxeOnFiveFtHaftStillPoleArm()
    { return true; }
// The classification
// presupposes a haft or shaft
// of not less than 5 feet.
inline int uapaMinHaftLengthFt()
    { return 5; }
// The illustrations: about
// 1/20 of actual size.
inline int uapaScaleDrawingDivisor()
    { return 20; }
// The scale lance: 15 feet
// long in scale.
inline int uapaScaleLanceFeet()
    { return 15; }
// The scale applies to shaft
// lengths and general blade
// size, not thickness or
// complex blade detail.
inline bool uapaShaftThicknessNotScale()
    { return true; }
// Authors brand one weapon
// under a mistaken
// classification, confusing
// the reader.
inline bool uapaNamingConfusionCommon()
    { return true; }
// The print example: Saxtorph
// identifies an obvious
// morning star as a mace.
inline bool uapaSaxtorphMorningStarMisnamed()
    { return true; }
// A mace: short-shafted,
// flanged head, cast in one
// piece.
inline bool uapaMaceShortShaftedFlanged()
    { return true; }
// A morning star: longer,
// infantry, wooden shaft and
// head with radiating spikes.
inline bool uapaMorningStarLongerSpiked()
    { return true; }
// A system of classification
// and nomenclature is presented
// here that seems both
// reasonable and easy to use -
// RESOLVED (R424): the clean
// p. 123 read gives the whole
// sentence, the "reasonable"
// line included; the print
// never garbles.
inline bool uapaSystemParagraphReadsClean()
    { return true; }
// Most medieval weapons:
// hunting weapons or
// agricultural implements
// adapted.
inline bool uapaHuntingOrAgriculturalOrigin()
    { return true; }
// Late-period weapons: more
// specialized than their
// models, or combinations
// trying to merge strengths.
inline bool uapaSpecializedOrCombination()
    { return true; }
// The spear is a dagger set
// atop a pole.
inline bool uapaSpearDaggerAtopPole()
    { return true; }
// Principally a thrusting
// weapon.
inline bool uapaSpearThrustingPrimary()
    { return true; }
// A broad blade (the ox
// tongue) gives a secondary
// cutting function when
// lengthened.
inline bool uapaOxTongueSecondaryCutting()
    { return true; }
// Spears of about 12 feet:
// the ash spears of English
// writings.
inline int uapaAshSpearTwelveFt()
    { return 12; }
// At such length often
// confused with pikes.
inline bool uapaSpearConfusedWithPikes()
    { return true; }
// A lance is a long spear
// carried by a mounted man.
inline bool uapaLanceMountedSpear()
    { return true; }
// Norman lances: about 12
// feet, some less.
inline int uapaNormanLanceFt()
    { return 12; }
// Later Middle Ages: an
// average of about 14 feet.
inline int uapaLaterLanceFt()
    { return 14; }
// Gives the horseman about 10
// feet of reach beyond the
// horse's head when charging.
inline int uapaLanceReachBeyondHorseHeadFt()
    { return 10; }
// The lance is a horseman
// weapon, not a true
// footman's pole arm.
inline bool uapaLanceNotFootmansWeapon()
    { return true; }
// Any spear with a shaft of
// 15 feet or longer is
// considered a pike.
inline int uapaPikeShaftMinFt()
    { return 15; }
// The pike delivers a
// thrusting attack at long
// range, keeping the opponent
// there.
inline bool uapaPikeThrustingLongRange()
    { return true; }
// Always used in mass.
inline bool uapaPikeUsedInMass()
    { return true; }
// The awl pike: the most
// common form, strictly
// piercing.
inline bool uapaAwlPikePiercingOnly()
    { return true; }
// Swiss and German pikes:
// metal protects the shaft
// up to 2 feet from the
// head.
inline int uapaPikeShaftGuardFt()
    { return 2; }
// The spetum: a sharp,
// tapering point plus two
// blades pointing forward.
inline bool uapaSpetumTwoForwardBlades()
    { return true; }
// The side blades point
// forward at about 45
// degrees.
inline int uapaSpetumBladeAngleDeg()
    { return 45; }
// Same class: the corseques
// or korsekes.
inline bool uapaSpetumClassCorseque()
    { return true; }
// The ranseur: backward-
// hooking projections set
// well below the large
// central blade.
inline bool uapaRanseurBackwardHooks()
    { return true; }
// A twist of the shaft
// breaks a caught weapon or
// disarms its wielder.
inline bool uapaRanseurTrapAndDisarm()
    { return true; }
// The projections hold an
// opponent at range or pull
// mounted opponents off the
// horse.
inline bool uapaRanseurPullsRidersDown()
    { return true; }
// Synonyms: chauve souris,
// ransom, rhonca, roncie,
// runka - five.
inline int uapaRanseurSynonymCount()
    { return 5; }
// The partisan: a spear,
// often with an ox tongue
// blade, plus a pair of small
// axe heads below the dagger
// blade.
inline bool uapaPartisanSpearWithAxeHeads()
    { return true; }
// The Bohemian earspoon: the
// axes become piercing spikes
// against plate, with a
// ranseur-like function.
inline bool uapaBohemianEarspoonSpikes()
    { return true; }
// The family: the spear
// proper, the pike, the
// spetum, the ranseur, the
// partisan - five.
inline int uapaSpearFamilyCount()
    { return 5; }
// All are daggers atop a
// sturdy pole with trimmings
// for efficiency.
inline bool uapaSpearFamilyDaggersTrimmed()
    { return true; }
// Two basic head forms:
// broad and narrow.
inline int uapaAxeHeadFormCount()
    { return 2; }
// The narrow form is thicker,
// for the necessary weight.
inline bool uapaNarrowHeadThicker()
    { return true; }
// The cleaver: a butchering
// tool adapted for military
// use.
inline bool uapaCleaverButcheringAdapted()
    { return true; }
// The axe and cleaver
// families chop at the
// opponent rather than
// thrust.
inline bool uapaAxePrimaryChopping()
    { return true; }
// A pole axe: an axe head on
// a long haft for an
// earlier, more forceful
// blow.
inline bool uapaPoleAxeAxeHeadLongHaft()
    { return true; }
// Can be double-bitted,
// spike-backed and/or
// dagger-topped - still
// recognizable as an axe.
inline bool uapaPoleAxeVariants()
    { return true; }
// The halberd: a convex-
// headed broad axe, the head
// set at a convenient angle.
inline bool uapaHalberdConvexBroadAxe()
    { return true; }
// The whole weapon often
// reached 8 feet.
inline int uapaHalberdTotalFt()
    { return 8; }
// Always topped with a fairly
// long spear point.
inline bool uapaHalberdSpearPointTop()
    { return true; }
// Backed by a spike, often
// angled or hooked slightly
// downward.
inline bool uapaHalberdBackSpikeAngled()
    { return true; }
// The opposing spike
// penetrates heavy plate
// armor.
inline bool uapaHalberdSpikePenetratesPlate()
    { return true; }
// The spike doubles as a hook
// for dismounting opponents.
inline bool uapaHalberdHookDismounts()
    { return true; }
// Useless vs. mounted lances:
// the Battle of Arbedo,
// 1422.
inline int uapaHalberdArbedoYear()
    { return 1422; }
// Some heads made smaller (
// the piercing axe) to
// penetrate armor better.
inline bool uapaHalberdPiercingAxeSmaller()
    { return true; }
// Many weapons pictured in
// texts are fanciful parade
// arms, not battle arms.
inline bool uapaParadeArmsExist()
    { return true; }
// The bardiche: a broad,
// heavy axe linking pole axes
// to pole cleavers.
inline bool uapaBardicheTransitionalForm()
    { return true; }
// The bardiche head: from
// about 2 feet in length.
inline int uapaBardicheHeadMinFt()
    { return 2; }
// To over 3 feet.
inline int uapaBardicheHeadMaxFt()
    { return 3; }
// Attached with two rings,
// or one when the shorter
// blade is backed with a
// hammer head or spike.
inline bool uapaBardicheRingsOrHammerBack()
    { return true; }
// Very heavy and cumbersome
// - more so by far than a
// halberd.
inline bool uapaBardicheHeavierThanHalberd()
    { return true; }
// Used principally in
// Eastern Europe.
inline bool uapaBardicheEasternEurope()
    { return true; }
// The true members: the pole
// axe, the halberd (possibly
// the brown bill), the
// bardiche - three.
inline int uapaAxeFamilyTrueMemberCount()
    { return 3; }
// Per Oman: the English brown
// bill was a halberd in all
// respects save the back
// spike.
inline bool uapaBrownBillHalberdSansSpike()
    { return true; }
// The pole cleaver: an
// outraged peasant fastened
// his meat cleaver to a
// stave.
inline bool uapaPeasantCleaverOrigin()
    { return true; }
// The fauchard: a development
// of the scythe or sickle -
// a cutting blade set upon a
// pole.
inline bool uapaFauchardSickleDevelopment()
    { return true; }
// For cutting, catching and
// holding, parrying and
// dismounting.
inline bool uapaFauchardDismountFunction()
    { return true; }
// The fauchard description
// prints whole - RESOLVED
// (R424): the clean p. 126
// read gives the scythe/sickle
// development, the cut-and-
// thrust that did neither too
// well, the little parrying,
// the no-dismount early form
// and the later back hook.
inline bool uapaFauchardDescriptionReadsClean()
    { return true; }
// The fauchard passed out
// rather quickly.
inline bool uapaFauchardPassedOutEarly()
    { return true; }
// Its combination form, the
// fauchard-fork, remained.
inline bool uapaFauchardForkRemained()
    { return true; }
// The glaive: a knife-bladed
// spear.
inline bool uapaGlaiveKnifeBladedSpear()
    { return true; }
// The thrust of the spear
// plus the secondary cutting
// of the convex knife blade.
inline bool uapaGlaiveThrustPlusCutting()
    { return true; }
// The blade rapidly enlarged
// to give a cleaving
// function.
inline bool uapaGlaiveEnlargedForCleaving()
    { return true; }
// The modifications produced
// the glaive-guisarme (the
// combination arms section).
inline bool uapaGlaiveGuisarmeModification()
    { return true; }
// As with the fauchard, not
// overly effective at
// holding opponents, and no
// piercing back.
inline bool uapaGlaiveWeakAtHolding()
    { return true; }
// The guisarme: pruning hooks
// made reasonably effective
// pole arms.
inline bool uapaGuisarmePruningHookOrigin()
    { return true; }
// A sharp cutting edge along
// the convex side, from
// reverse spike to hook.
inline bool uapaGuisarmeSharpConvexEdge()
    { return true; }
// The curved hook pulls
// horsemen to the ground.
inline bool uapaGuisarmeHookPullsHorsemen()
    { return true; }
// Deficiencies: no spear
// point for thrusting, one
// projection for
// penetrating.
inline bool uapaGuisarmeNoSpearPoint()
    { return true; }
// Soon combined into a
// second generation of
// all-purpose pole arms.
inline bool uapaGuisarmeSecondGeneration()
    { return true; }
// The voulge: a hefty cleaver
// on a long, stout shaft.
inline bool uapaVoulgeHeftyCleaverShaft()
    { return true; }
// The leverage lets the
// wielder cleave through
// armor.
inline bool uapaVoulgeCleavesArmor()
    { return true; }
// A ground-down front or back
// edge gives a dagger-like
// tip - the more complete
// form.
inline bool uapaVoulgeGroundTipDagger()
    { return true; }
// Sometimes backed with a
// spike or hooked spike -
// the crude guisarme-
// voulge.
inline bool uapaVoulgeBackedSpikeCrude()
    { return true; }
// The Lochaber axe in early,
// crude forms: the same as a
// voulge.
inline bool uapaLochaberEarlyFormVoulge()
    { return true; }
// Development added a hook,
// as a tip or blade backing.
inline bool uapaLochaberHookAdded()
    { return true; }
// In that form nearly
// identical to the guisarme-
// voulge - no real
// differentiation.
inline bool uapaLochaberEqualsGuisarmeVoulge()
    { return true; }
// The Scots developed the
// Lochaber axe; the Continent
// the voulge - the same
// thing.
inline bool uapaLochaberScotsVoulgeContinental()
    { return true; }
// The English bill hook:
// almost exactly the French
// guisarme.
inline bool uapaBillHookEnglishGuisarme()
    { return true; }
// Its concave (hook) edge is
// the sharp one.
inline bool uapaBillConcaveEdgeSharp()
    { return true; }
// An L-shaped tine projects
// forward instead of a
// straight back spike.
inline bool uapaBillLTineForward()
    { return true; }
// Slightly more effective
// than the European
// guisarme.
inline bool uapaBillSlightlyMoreEffective()
    { return true; }
// The military fork: the
// lowly hay fork,
// straightened and
// strengthened.
inline bool uapaMilitaryForkHayForkOrigin()
    { return true; }
// Two efficient piercing
// points for holding off an
// enemy.
inline int uapaMilitaryForkTwoPoints()
    { return 2; }
// Sometimes a shorter third
// tine in the crotch -
// opponents are channeled
// into a third attack.
inline bool uapaMilitaryForkThirdTine()
    { return true; }
// The major drawback: lack
// of penetrating power vs.
// heavily armored targets.
inline bool uapaMilitaryForkWeakVsArmor()
    { return true; }
// The threshing flail: a
// wooden handle plus billet
// joined by a swivel or
// chain links.
inline bool uapaFlailSwivelOrChain()
    { return true; }
// Horsemen used a short-
// hafted flail with chains
// ending in smooth or
// spiked iron balls.
inline bool uapaHorsemanFlailIronBalls()
    { return true; }
// The peasant flail: a heavy
// shaft of about 3 feet.
inline int uapaPeasantFlailShaftMinFt()
    { return 3; }
// To 4 feet in length.
inline int uapaPeasantFlailShaftMaxFt()
    { return 4; }
// Hung with one or two
// metal-shod, spiked rods of
// wood or iron.
inline bool uapaPeasantFlailOneOrTwoRods()
    { return true; }
// The whole weapon over 5
// feet, with tremendous
// penetration and crushing
// power.
inline bool uapaPeasantFlailOverFiveFt()
    { return true; }
// The morning star: a heavy
// wooden haft from 3 feet or
// more in length.
inline bool uapaMorningStarHaftThreeFt()
    { return true; }
// A cylinder, barrel or
// truncated cone, metal-
// bound and set with vicious
// metal spikes.
inline bool uapaMorningStarSpikedHead()
    { return true; }
// Also called the holy water
// sprinkler.
inline bool uapaMorningStarHolyWaterSprinkler()
    { return true; }
// Or the godentag in the Low
// Countries.
inline bool uapaMorningStarGodentag()
    { return true; }
// Used extensively by the
// Swiss until the halberd
// replaced it.
inline bool uapaMorningStarSwissThenHalberd()
    { return true; }
// Often spear-tipped in
// longer form - some models
// long enough to be pole
// arms.
inline bool uapaMorningStarSometimesPoleArm()
    { return true; }
// Some military picks
// pole-mounted, shafts of 5
// feet or greater.
inline bool uapaMilitaryPicksPoleMounted()
    { return true; }
// Two pole arms developed
// purely as weapons -
// similar but separate and
// distinct.
inline bool uapaTwoPureWeaponForms()
    { return true; }
// The Lucern hammer: very
// similar to the halberd.
inline bool uapaLucernLikeHalberd()
    { return true; }
// Its end spike generally
// longer than a halberd.
inline bool uapaLucernLongerSpike()
    { return true; }
// A smaller, hammer-like
// head with three prongs
// instead of an axe head.
inline bool uapaLucernThreeProngHead()
    { return true; }
// Less efficient vs. armor -
// replaced by the halberd
// amongst the Swiss.
inline bool uapaLucernReplacedByHalberd()
    { return true; }
// Replaced after the 14th
// century.
inline int uapaLucernAfterCentury()
    { return 14; }
// The bec de corbin: used
// late by knights and nobles,
// not commoners.
inline bool uapaBecDeCorbinKnightsWeapon()
    { return true; }
// The heavy crow's-beak
// blade punctures the heavy
// plate of upper-class
// warriors.
inline bool uapaBecDeCorbinBeakPunctures()
    { return true; }
// In this weapon the beak is
// the major feature.
inline bool uapaBecDeCorbinBeakMajor()
    { return true; }
// The bec de corbin more
// specialized than the Lucern
// hammer.
inline bool uapaBecMoreSpecializedThanLucern()
    { return true; }
// "For the latter weapon was
// not so specialized" -
// RESOLVED (R424): the clean
// p. 127 read prints the
// Lucern/bec comparison tail
// whole; the print never
// garbles.
inline bool uapaLucernBecComparisonReadsClean()
    { return true; }
// Technically, all pole arms
// with a secondary spear tip
// are combination weapons.
inline bool uapaSecondarySpearTipCombination()
    { return true; }
// The partisan stays in the
// spear family - primarily a
// thrusting weapon.
inline bool uapaPartisanNotCombination()
    { return true; }
// It is necessary to ignore
// secondary spear tips when
// classifying pole arms -
// RESOLVED (R424): the clean
// p. 127 read prints the
// combination intro whole,
// the "to ignore" line
// included.
inline bool uapaCombinationIntroReadsClean()
    { return true; }
// The fauchard-fork: two
// general forms.
inline int uapaFauchardForkFormCount()
    { return 2; }
// The first follows the
// typical fauchard form with
// a single spike projecting
// from the back.
inline bool uapaFauchardForkFormOneBackSpike()
    { return true; }
// The second reverses the
// scythe blade - concave edge
// toward the opponent, more
// curved and sicklelike, a
// spike tipping the pole end.
inline bool uapaFauchardForkFormTwoReversed()
    { return true; }
// The fauchard-guisarme: a
// scythe blade backed by a
// heavy hook for dismounting.
inline bool uapaFauchardGuisarmeScytheHook()
    { return true; }
// The glaive-guisarme: a
// heavier, longer glaive head
// plus a guisarme hook to
// jerk horsemen from their
// seats.
inline bool uapaGlaiveGuisarmeHookJerks()
    { return true; }
// The guisarme-voulge: like
// the Lochaber axe, but the
// hook is formed from the
// voulge blade itself.
inline bool uapaGuisarmeVoulgeHookFromBlade()
    { return true; }
// Featured the pointed tip or
// spike so as to be as
// all-purpose as possible.
inline bool uapaGuisarmeVoulgeAllPurpose()
    { return true; }
// The bill-guisarme features:
// a sharp spear or awl point,
// a large hook from the body,
// a back spike for armor
// penetration, and several
// cutting edges - four.
inline int uapaBillGuisarmeFeatureCount()
    { return 4; }
// "A back spike for armor
// penetration" - RESOLVED
// (R424): the clean p. 128
// read prints the bill-
// guisarme features list
// whole; no "armor ion" split
// exists in the print.
inline bool uapaBillGuisarmeFeaturesReadsClean()
    { return true; }
// Some bill-guisarmes have
// sufficiently heavy blades
// and cutting edges to be
// voulge-like.
inline bool uapaBillGuisarmeVoulgeLike()
    { return true; }
// Persisted the longest of
// all save the pike and the
// halberd - efficient in all
// functions.
inline bool uapaBillGuisarmePersistedLongest()
    { return true; }
// The scorpion: one typical
// form of the bill-guisarme.
inline bool uapaScorpionBillGuisarmeForm()
    { return true; }
// A weapon with an added
// feature is identified by the
// major weapon, not the
// added part.
inline bool uapaIdentifyByMajorWeapon()
    { return true; }
// An axe head on what is
// basically a spear (the
// partisan) is not a pole
// axe - a thrusting weapon
// with secondary functions.
inline bool uapaPartisanWithAxeNotPoleAxe()
    { return true; }
// The glaring example: Stone
// identifies a halberd with a
// fork tip as a military
// fork.
inline bool uapaStoneForkMisidentified()
    { return true; }
// A halberd-sized pole: simply
// a halberd with an
// incidental fork atop it.
inline bool uapaHalberdWithIncidentalFork()
    { return true; }
// Confusion regarding the
// combination weapons "is
// certainly understandable,
// and care must be taken in
// identifying such weapons" -
// RESOLVED (R424): the clean
// p. 128 read prints the
// confusion sentence whole,
// tail included.
inline bool uapaConfusionSentenceReadsClean()
    { return true; }
// Careful examination of the
// shaft length and head shape
// gives the identity clues.
inline bool uapaCareShaftLengthHeadShape()
    { return true; }
// The pole arm put infantry on
// even terms with cavalry.
inline bool uapaInfantryVsCavalryPurpose()
    { return true; }
// The Swiss mixed pike,
// halberd/Lucern hammer and
// morning star - 40 pike as
// an average.
inline int uapaSwissPikePct()
    { return 40; }
// 40 halberd/Lucern hammer.
inline int uapaSwissHalberdPct()
    { return 40; }
// 20 morning star - 40-40-20
// as an average.
inline int uapaSwissMorningStarPct()
    { return 20; }
// The pike proliferated: most
// useful for keeping horsemen
// at a distance.
inline bool uapaPikeKeepsHorsemenDistant()
    { return true; }
// Swiss pikemen held the rear
// of the shaft higher, forcing
// glancing points downward -
// not grounding the butt.
inline bool uapaPikemenRearHigher()
    { return true; }
// Massive-headed pole arms
// were inefficient when
// lengthened past a limit -
// too cumbersome to wield.
inline bool uapaMassiveHeadsTooCumbersome()
    { return true; }
// Spear-type pole arms
// lengthened to pikes were
// then called just that.
inline bool uapaSpearTypesLengthenedToPikes()
    { return true; }
// The pike shaft is too long
// for useful ranseur or
// partisan heads.
inline bool uapaPikeShaftTooLongForHeads()
    { return true; }
// Shortened cleaving weapons:
// less efficient than the
// halberd, or changed to
// become almost
// indistinguishable from it.
inline bool uapaShortenedCleaversToHalberd()
    { return true; }
// The typically indistin-
// guishable forms: the
// guisarme-voulge.
inline bool uapaGuisarmeVoulgeTypically()
    { return true; }
// The pole arm evolution
// reflects the trends in
// armor and tactics in
// medieval warfare.
inline bool uapaEvolutionReflectsArmor()
    { return true; }
// The system derived from
// early reading of the
// Encyclopedia Britannica and
// ffoulkes's book.
inline bool uapaSystemDerivedBritannica()
    { return true; }
// The bibliography: Ashdown,
// ffoulkes, Oman, Saxtorph,
// the Britannica - five.
inline int uapaBibliographySourceCount()
    { return 5; }
// The item ledger: seven
// items.
inline int uapaPartItemTotal()
    { return 7; }
// All seven items fully clean -
// RESOLVED (R424): the clean
// pp. 123-128 read resolves the
// five flagged holes (the
// original two fully clean:
// the spear family, the axe
// family).
inline int uapaPartCleanCount()
    { return 7; }
// Zero flagged holes remain -
// RESOLVED (R424): the clean
// pp. 123-128 read resolves the
// classification system
// paragraph, the fauchard
// description, the Lucern/bec
// comparison tail, the
// combination intro and
// features list, and the
// confusion sentence.
inline int uapaPartFlaggedCount()
    { return 0; }
// Nothing fully garbles -
// every classification
// survives its scrambled
// prose.
inline int uapaPartGarbledCount()
    { return 0; }
}   // namespace rules

