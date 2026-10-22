// =========================================================================================
// Adnd1 - rules/oa129magitemsprose.h
// OA TREASURE - THE ORIENTAL MAGICAL ITEMS PROSE, printed capture pp. 296-301
// - the item descriptions round
// census 680 -> 681.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 211 closed, 24 open - the magical items
// prose box flips (census 680 -> 681); NEXT - R759: Table 86: Oriental
// Magical Items (capture p. 296, the grid running onto p. 297), prefix dlu
// (verify free at the landing), audit "R759 OA Table 86 items audit", include
// after rules/oa129magitemsprose.h
//
namespace rules {

// ---- the banner and the bells ----

// the banner spell block - the field blocking spells of 5th level or greater
// (print capture p. 297)
inline int dltBannerSpellBlockLevel()
    { return 5; }

// the banner radius - the area of effect never greater than a 100-yard radius
// (print capture p. 297)
inline int dltBannerRadiusYd()
    { return 100; }

// the banner of protection - the health, prosperity, and fame characters, the
// named compound protected, only while flying in plain view (print capture p.
// 297)
inline int dltBannerOfProtection()
    { return 1; }

// the bell of protection radius - the maximum 50-yard radius (print capture
// p. 297)
inline int dltBellProtRadiusYd()
    { return 50; }

// the bell of protection greater save - the -4 on the greater spirit save
// versus death to cross (print capture p. 297)
inline int dltBellProtGreaterSavePenalty()
    { return 4; }

// the bell of protection cross damage - the 4d10 of the painful effort of the
// greater spirit crossing (print capture p. 297)
inline int dltBellProtCrossDamageDice()
    { return 4; }

// the bell of protection within damage - the 3d10 of the spirit creatures
// within when struck (print capture p. 297)
inline int dltBellProtWithinDamageDice()
    { return 3; }

// the bell of protection - the temple bell barrier for one turn, the lesser
// spirits unable to cross, no effect on the spirit folk (print capture p.
// 297)
inline int dltBellOfProtection()
    { return 1; }

// the bell of warning radius - the 30 feet of the detected creatures (print
// capture p. 297)
inline int dltBellWarnRadiusFt()
    { return 30; }

// the bell of warning hours die - the 3d6 hours of each activation (print
// capture p. 298)
inline int dltBellWarnHoursDie()
    { return 6; }

// the bell of warning charges die - the 3d10 charges when found (print
// capture p. 298)
inline int dltBellWarnChargesDie()
    { return 10; }

// the bell of warning - the 6-inch bell pealing for the invisible, ethereal,
// astral, and the silently moving (print capture p. 297)
inline int dltBellOfWarning()
    { return 1; }

// ---- the biwa ----

// the biwa of calm - the pacify effect while played, the proficiency roll
// each round, the roll of 1 breaking the calm (print capture p. 298)
inline int dltBiwaOfCalm()
    { return 1; }

// the biwa of charm - the suggestion on the successful proficiency roll, the
// roll of 1 acting as the biwa of discord (print capture p. 298)
inline int dltBiwaOfCharm()
    { return 1; }

// the biwa of discord radius - the 3 feet of the rage (print capture p. 298)
inline int dltBiwaDiscordRadiusFt()
    { return 3; }

// the biwa of discord frenzy minimum - the 2 of the 2-5 rounds (print capture
// p. 298)
inline int dltBiwaDiscordFrenzyMin()
    { return 2; }

// the biwa of discord frenzy maximum - the 5 of the 2-5 rounds (print capture
// p. 298)
inline int dltBiwaDiscordFrenzyMax()
    { return 5; }

// the biwa of discord - the 50% musician target split, the player immune, the
// concealment until played in earnest (print capture p. 298)
inline int dltBiwaOfDiscord()
    { return 1; }

// ---- the charms ----

// the charm of protection from disease - the yellow or red paper, the
// occupants immune, the plague turned away (print capture p. 298)
inline int dltCharmOfProtectionFromDisease()
    { return 1; }

// the charm of protection from fire catch percent - the 50% chance of
// catching fire, half the burn damage (print capture p. 298)
inline int dltCharmFireCatchPct()
    { return 50; }

// the charm of protection from fire - the threats against the fire deities,
// the lintel paste, the charm itself immune (print capture p. 298)
inline int dltCharmOfProtectionFromFire()
    { return 1; }

// the charm of protection from spirits - the save versus death to enter, the
// spells and missiles still allowed, the charm untouchable by spirits (print
// capture p. 298)
inline int dltCharmOfProtectionFromSpirits()
    { return 1; }

// the charm of protection from theft penalty - the 20% reduction of the
// silent move, hide, and locks (print capture p. 298)
inline int dltCharmTheftSkillPenaltyPct()
    { return 20; }

// the charm of protection from theft remove damage - the 2d10 of the
// non-owner remover (print capture p. 298)
inline int dltCharmTheftRemoveDamageDie()
    { return 10; }

// the charm of protection from theft - the lintel paste, the house protected
// (print capture p. 298)
inline int dltCharmOfProtectionFromTheft()
    { return 1; }

// ---- the mace, drums, coins, mortar, gem, gong ----

// the diamond mace bolt - the 12-dice lightning bolt from the gem (print
// capture p. 298)
inline int dltDiamondMaceBoltDice()
    { return 12; }

// the diamond mace charges die - the 3d10 charges (print capture p. 298)
inline int dltDiamondMaceChargesDie()
    { return 10; }

// the diamond mace value - the 1000 ch'ien of the spent diamond (print
// capture p. 298)
inline int dltDiamondMaceValueChien()
    { return 1000; }

// the diamond mace - the iron rod and the diamond, one charge each use (print
// capture p. 298)
inline int dltDiamondMace()
    { return 1; }

// the drums of thunder fly charges - the one charge of the one-turn fly
// (print capture p. 299)
inline int dltDrumsFlyCharges()
    { return 1; }

// the drums of thunder trapeze charges - the three of the cloud trapeze
// (print capture p. 299)
inline int dltDrumsTrapezeCharges()
    { return 3; }

// the drums of thunder panic charges - the two of the drums of panic per the
// DMG (print capture p. 299)
inline int dltDrumsPanicCharges()
    { return 2; }

// the drums of thunder weather charges - the one of the control weather
// (print capture p. 299)
inline int dltDrumsWeatherCharges()
    { return 1; }

// the drums of thunder bolt dice - the 20-dice lightning bolt (print capture
// p. 299)
inline int dltDrumsBoltDice()
    { return 20; }

// the drums of thunder bolt charges - the five of the lightning bolt (print
// capture p. 299)
inline int dltDrumsBoltCharges()
    { return 5; }

// the drums of thunder charges die - the 2d10 when found (print capture p.
// 299)
inline int dltDrumsChargesDie()
    { return 10; }

// the drums of thunder - the waist harness pair, one use per round (print
// capture p. 299)
inline int dltDrumsOfThunder()
    { return 1; }

// the eight diagram coins count - the eight of the set (print capture p. 299)
inline int dltEightCoinsCount()
    { return 8; }

// the eight diagram coins - the copper discs, the fate spell on the toss and
// the command word (print capture p. 299)
inline int dltEightDiagramCoins()
    { return 1; }

// the rice mortar common percent - the 80% common against the 20%
// extraordinary (print capture p. 299)
inline int dltMortarCommonPct()
    { return 80; }

// the rice mortar food die - the 1d100 people fed by the common mortar (print
// capture p. 299)
inline int dltMortarFoodPeopleDie()
    { return 100; }

// the rice mortar wishes die - the 1d4 wishes of the extraordinary mortar
// (print capture p. 299)
inline int dltMortarWishesDie()
    { return 4; }

// the everproducing rice mortar - the mallet turn activating and
// deactivating, the hot and fresh food (print capture p. 299)
inline int dltEverproducingRiceMortar()
    { return 1; }

// the gem of wishes minimum - the 1 of the 1-4 wishes (print capture p. 299)
inline int dltGemWishesMin()
    { return 1; }

// the gem of wishes maximum - the 4 of the 1-4 wishes (print capture p. 299)
inline int dltGemWishesMax()
    { return 4; }

// the gem of wishes value minimum - the 100 ch'ien of the 100-1000 (print
// capture p. 299)
inline int dltGemValueMinChien()
    { return 100; }

// the gem of wishes value maximum - the 1000 ch'ien of the 100-1000 (print
// capture p. 299)
inline int dltGemValueMaxChien()
    { return 1000; }

// the gem of wishes - the detect magic reveal, the magic lost once the wishes
// granted (print capture p. 299)
inline int dltGemOfWishes()
    { return 1; }

// the gong of dispelling caster level - the 15th-level potency of the dispels
// (print capture p. 299)
inline int dltGongCasterLevel()
    { return 15; }

// the gong of dispelling charges die - the 1d100 initial charges (print
// capture p. 299)
inline int dltGongChargesDie()
    { return 100; }

// the gong of dispelling - the three-foot gong, the dispel evil and magic
// within the 3 feet, one charge each sounding (print capture p. 299)
inline int dltGongOfDispelling()
    { return 1; }

// ---- the mallet and the minyan ----

// the mallet of luck bonus - the +2 to hit and saving throws (print capture
// p. 299)
inline int dltMalletLuckBonus()
    { return 2; }

// the mallet of luck duration - the six turns of the bonus (print capture p.
// 299)
inline int dltMalletLuckTurns()
    { return 6; }

// the mallet of luck damage - the 2d6 of the bestowing blow, no cumulative
// effect (print capture p. 299)
inline int dltMalletLuckDamageDie()
    { return 6; }

// the mallet of luck - the warped imagination, the combat use giving the
// opponent the bonus (print capture p. 299)
inline int dltMalletOfLuck()
    { return 1; }

// the minyan bearers - the 20 men to move the shrine (print capture p. 299)
inline int dltMinyanBearers()
    { return 20; }

// the minyan cause fear radius - the 3 feet constantly in effect (print
// capture p. 299)
inline int dltMinyanFearRadiusFt()
    { return 3; }

// the minyan remove curse uses - the three per day as if a 20th-level caster
// (print capture p. 299)
inline int dltMinyanRemoveCursesPerDay()
    { return 3; }

// the minyan caster level - the 20th-level of the remove curse (print capture
// p. 299)
inline int dltMinyanCasterLevel()
    { return 20; }

// the minyan presence morale - the 10% improvement of the friendly sohei
// (print capture p. 299)
inline int dltMinyanSoheiMoralePct()
    { return 10; }

// the minyan powers - the cause fear, the remove curse, the presence, the
// ancient curse once per month, the heal once per week (print capture p. 299)
inline int dltMinyanPowers()
    { return 1; }

// the minyan care - the daily offerings and incense, the services, the ethos,
// the holy day parade, the neglected duty losing the power permanently (print
// capture p. 299)
inline int dltMinyanCare()
    { return 1; }

// ---- the mirrors, net, chasers, and paper ----

// the mirror of curing charges die - the 2d4 charges, the shatter when spent
// (print capture p. 300)
inline int dltMirrorCuringChargesDie()
    { return 4; }

// the mirror of curing - the heal spell on the viewer, one charge each (print
// capture p. 300)
inline int dltMirrorOfCuring()
    { return 1; }

// the mirror of enlightenment - the colored aura of the detect evil/good,
// detect motivation, and know alignment, one person per round (print capture
// p. 300)
inline int dltMirrorOfEnlightenment()
    { return 1; }

// the mirror of fear flee die - the 1d6 rounds of the panic, the quivering
// heap when unable to flee (print capture p. 300)
inline int dltMirrorFearFleeDie()
    { return 6; }

// the mirror of fear - the hideous distorted reflection, the save versus
// spell or flee (print capture p. 300)
inline int dltMirrorOfFear()
    { return 1; }

// the mirror of spirit seeing - the constant power, the invisibility,
// disguise, illusion, polymorph, and shapechange penetrated, the prudent
// homeowner placement (print capture p. 300)
inline int dltMirrorOfSpiritSeeing()
    { return 1; }

// the net of spirit snaring - the frozen spirit, the attacks and spell-like
// abilities prevented, the bargain allowed (print capture p. 300)
inline int dltNetOfSpiritSnaring()
    { return 1; }

// the noisome spirit chasers count - the strings of 100 firecrackers (print
// capture p. 300)
inline int dltNoisomeStringCount()
    { return 100; }

// the noisome spirit chasers flee minimum - the 2 of the 2-5 rounds of the
// lesser spirits (print capture p. 300)
inline int dltNoisomeFleeMin()
    { return 2; }

// the noisome spirit chasers flee maximum - the 5 of the 2-5 rounds (print
// capture p. 300)
inline int dltNoisomeFleeMax()
    { return 5; }

// the noisome spirit chasers - the greater spirit save versus spell, no
// damage to any creature (print capture p. 300)
inline int dltNoisomeSpiritChasers()
    { return 1; }

// the paper of forms ignite percent - the 80% of the normal fires, the
// magical fires certain (print capture p. 300)
inline int dltPaperFormsIgnitePct()
    { return 80; }

// the paper of forms sheets die - the 1d4 sheets when found (print capture p.
// 300)
inline int dltPaperFormsSheetsDie()
    { return 4; }

// the paper of forms - the origami proficiency, the animal intelligence and
// non-magical objects, the second command word reverting, the shape fixed
// thereafter, the unfold ruining (print capture p. 300)
inline int dltPaperOfForms()
    { return 1; }

// ---- the pearls, scroll, seals, and tail ----

// the pearl of protection from fire - the ring of fire resistance per the DMG
// when carried (print capture p. 300)
inline int dltPearlOfProtectionFromFire()
    { return 1; }

// the pearl of tide radius - the 60 feet of the affected waters (print
// capture p. 300)
inline int dltPearlTideRadiusFt()
    { return 60; }

// the pearl of tide rate - the five feet per round of the recede or rise, the
// instant return on the ended concentration (print capture p. 300)
inline int dltPearlTideRateFt()
    { return 5; }

// the pearl of the ebbing tide - the command word and the concentration
// (print capture p. 300)
inline int dltPearlOfEbbingTide()
    { return 1; }

// the pearl of the rising tide - the identical twin with the rise (print
// capture p. 300)
inline int dltPearlOfRisingTide()
    { return 1; }

// the scroll of protection from spirits caster level - the 12th-level
// shukenja (print capture p. 300)
inline int dltScrollSpiritsCasterLevel()
    { return 12; }

// the scroll of protection from spirits - the protection scroll usable by any
// character (print capture p. 300)
inline int dltScrollOfProtectionFromSpirits()
    { return 1; }

// the seal of deception stamp error - the 5% with the stamp at hand (print
// capture p. 301)
inline int dltSealDeceptionStampErrorPct()
    { return 5; }

// the seal of deception memory error - the 30% from the memory, the forgery
// revealed under the careful checking (print capture p. 301)
inline int dltSealDeceptionMemoryErrorPct()
    { return 30; }

// the seal of deception - the name seal culture, the reshaping stamp, the
// command word and the concentration (print capture p. 301)
inline int dltSealOfDeception()
    { return 1; }

// the seal of vigor - the inscribed name activating, the double healing and
// the maximum cures while carried, the damage link of the stolen seal (print
// capture p. 301)
inline int dltSealOfVigor()
    { return 1; }

// the tablet of spirit summoning spell level - the 9th-level wu jen summon
// spirit (print capture p. 301)
inline int dltTabletSpellLevel()
    { return 9; }

// the tablet of spirit summoning characters die - the 2d6 inscribed
// characters fading one per use (print capture p. 301)
inline int dltTabletCharsDie()
    { return 6; }

// the tablet of spirit summoning value - the 10 ch'ien of the smooth jade
// when spent (print capture p. 301)
inline int dltTabletValueChien()
    { return 10; }

// the tablet of spirit summoning - the jade tablet, once per week (print
// capture p. 301)
inline int dltTabletOfSpiritSummoning()
    { return 1; }

// the wheels of fire radius - the 30 feet of the intense heat (print capture
// p. 301)
inline int dltWheelsFireRadiusFt()
    { return 30; }

// the wheels of fire damage - the 2d6 of the creatures within, the
// fire-immune spared (print capture p. 301)
inline int dltWheelsFireDamageDie()
    { return 6; }

// the wheels of fire - the chariot pairs, the flame not hindering the
// chariot, the flaming tracks, the second command word ending (print capture
// p. 301)
inline int dltWheelsOfFire()
    { return 1; }

// the wondrous writing set calligraphy bonus - the +2 proficiency (print
// capture p. 301)
inline int dltWritingSetCalligraphyBonus()
    { return 2; }

// the wondrous writing set pages minimum - the 2 of the 2-5 pages (print
// capture p. 301)
inline int dltWritingSetPagesMin()
    { return 2; }

// the wondrous writing set pages maximum - the 5 of the 2-5 pages (print
// capture p. 301)
inline int dltWritingSetPagesMax()
    { return 5; }

// the wondrous writing set - the lacquered box, the perfect forgery on the
// calligraphy roll (print capture p. 301)
inline int dltWondrousWritingSet()
    { return 1; }

}   // namespace rules
