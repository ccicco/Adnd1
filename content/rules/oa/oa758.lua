-- oa758: promoted from rules/oa/oa129magitemsprose.h (the OA TREASURE - THE ORIENTAL MAGICAL ITEMS PROSE, printed capture pp. 296-301);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 758,
  "prefix" = "oa758",
  "banner" = {
      "title" = "OA TREASURE - THE ORIENTAL MAGICAL ITEMS PROSE, printed capture pp. 296-301",
      "provenance" = "- the item descriptions round census 680 -> 681.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 211 closed, 24 open - the magical items prose box flips (census 680 -> 681); NEXT - R759: Table 86: Oriental Magical Items (capture p. 296, the grid running onto p. 297), prefix dlu (verify free at the landing), audit \"R759 OA Table 86 items audit\", include after rules/oa/oa129magitemsprose.h",
    },
  "consts" = { {
      "name" = "dltBannerSpellBlockLevel",
      "value" = 5,
      "comment" = "the banner spell block - the field blocking spells of 5th level or greater (print capture p. 297)",
    }, {
      "name" = "dltBannerRadiusYd",
      "value" = 100,
      "comment" = "the banner radius - the area of effect never greater than a 100-yard radius (print capture p. 297)",
    }, {
      "name" = "dltBannerOfProtection",
      "value" = 1,
      "comment" = "the banner of protection - the health, prosperity, and fame characters, the named compound protected, only while flying in plain view (print capture p. 297)",
    }, {
      "name" = "dltBellProtRadiusYd",
      "value" = 50,
      "comment" = "the bell of protection radius - the maximum 50-yard radius (print capture p. 297)",
    }, {
      "name" = "dltBellProtGreaterSavePenalty",
      "value" = 4,
      "comment" = "the bell of protection greater save - the -4 on the greater spirit save versus death to cross (print capture p. 297)",
    }, {
      "name" = "dltBellProtCrossDamageDice",
      "value" = 4,
      "comment" = "the bell of protection cross damage - the 4d10 of the painful effort of the greater spirit crossing (print capture p. 297)",
    }, {
      "name" = "dltBellProtWithinDamageDice",
      "value" = 3,
      "comment" = "the bell of protection within damage - the 3d10 of the spirit creatures within when struck (print capture p. 297)",
    }, {
      "name" = "dltBellOfProtection",
      "value" = 1,
      "comment" = "the bell of protection - the temple bell barrier for one turn, the lesser spirits unable to cross, no effect on the spirit folk (print capture p. 297)",
    }, {
      "name" = "dltBellWarnRadiusFt",
      "value" = 30,
      "comment" = "the bell of warning radius - the 30 feet of the detected creatures (print capture p. 297)",
    }, {
      "name" = "dltBellWarnHoursDie",
      "value" = 6,
      "comment" = "the bell of warning hours die - the 3d6 hours of each activation (print capture p. 298)",
    }, {
      "name" = "dltBellWarnChargesDie",
      "value" = 10,
      "comment" = "the bell of warning charges die - the 3d10 charges when found (print capture p. 298)",
    }, {
      "name" = "dltBellOfWarning",
      "value" = 1,
      "comment" = "the bell of warning - the 6-inch bell pealing for the invisible, ethereal, astral, and the silently moving (print capture p. 297)",
    }, {
      "name" = "dltBiwaOfCalm",
      "value" = 1,
      "comment" = "the biwa of calm - the pacify effect while played, the proficiency roll each round, the roll of 1 breaking the calm (print capture p. 298)",
    }, {
      "name" = "dltBiwaOfCharm",
      "value" = 1,
      "comment" = "the biwa of charm - the suggestion on the successful proficiency roll, the roll of 1 acting as the biwa of discord (print capture p. 298)",
    }, {
      "name" = "dltBiwaDiscordRadiusFt",
      "value" = 3,
      "comment" = "the biwa of discord radius - the 3 feet of the rage (print capture p. 298)",
    }, {
      "name" = "dltBiwaDiscordFrenzyMin",
      "value" = 2,
      "comment" = "the biwa of discord frenzy minimum - the 2 of the 2-5 rounds (print capture p. 298)",
    }, {
      "name" = "dltBiwaDiscordFrenzyMax",
      "value" = 5,
      "comment" = "the biwa of discord frenzy maximum - the 5 of the 2-5 rounds (print capture p. 298)",
    }, {
      "name" = "dltBiwaOfDiscord",
      "value" = 1,
      "comment" = "the biwa of discord - the 50% musician target split, the player immune, the concealment until played in earnest (print capture p. 298)",
    }, {
      "name" = "dltCharmOfProtectionFromDisease",
      "value" = 1,
      "comment" = "the charm of protection from disease - the yellow or red paper, the occupants immune, the plague turned away (print capture p. 298)",
    }, {
      "name" = "dltCharmFireCatchPct",
      "value" = 50,
      "comment" = "the charm of protection from fire catch percent - the 50% chance of catching fire, half the burn damage (print capture p. 298)",
    }, {
      "name" = "dltCharmOfProtectionFromFire",
      "value" = 1,
      "comment" = "the charm of protection from fire - the threats against the fire deities, the lintel paste, the charm itself immune (print capture p. 298)",
    }, {
      "name" = "dltCharmOfProtectionFromSpirits",
      "value" = 1,
      "comment" = "the charm of protection from spirits - the save versus death to enter, the spells and missiles still allowed, the charm untouchable by spirits (print capture p. 298)",
    }, {
      "name" = "dltCharmTheftSkillPenaltyPct",
      "value" = 20,
      "comment" = "the charm of protection from theft penalty - the 20% reduction of the silent move, hide, and locks (print capture p. 298)",
    }, {
      "name" = "dltCharmTheftRemoveDamageDie",
      "value" = 10,
      "comment" = "the charm of protection from theft remove damage - the 2d10 of the non-owner remover (print capture p. 298)",
    }, {
      "name" = "dltCharmOfProtectionFromTheft",
      "value" = 1,
      "comment" = "the charm of protection from theft - the lintel paste, the house protected (print capture p. 298)",
    }, {
      "name" = "dltDiamondMaceBoltDice",
      "value" = 12,
      "comment" = "the diamond mace bolt - the 12-dice lightning bolt from the gem (print capture p. 298)",
    }, {
      "name" = "dltDiamondMaceChargesDie",
      "value" = 10,
      "comment" = "the diamond mace charges die - the 3d10 charges (print capture p. 298)",
    }, {
      "name" = "dltDiamondMaceValueChien",
      "value" = 1000,
      "comment" = "the diamond mace value - the 1000 ch'ien of the spent diamond (print capture p. 298)",
    }, {
      "name" = "dltDiamondMace",
      "value" = 1,
      "comment" = "the diamond mace - the iron rod and the diamond, one charge each use (print capture p. 298)",
    }, {
      "name" = "dltDrumsFlyCharges",
      "value" = 1,
      "comment" = "the drums of thunder fly charges - the one charge of the one-turn fly (print capture p. 299)",
    }, {
      "name" = "dltDrumsTrapezeCharges",
      "value" = 3,
      "comment" = "the drums of thunder trapeze charges - the three of the cloud trapeze (print capture p. 299)",
    }, {
      "name" = "dltDrumsPanicCharges",
      "value" = 2,
      "comment" = "the drums of thunder panic charges - the two of the drums of panic per the DMG (print capture p. 299)",
    }, {
      "name" = "dltDrumsWeatherCharges",
      "value" = 1,
      "comment" = "the drums of thunder weather charges - the one of the control weather (print capture p. 299)",
    }, {
      "name" = "dltDrumsBoltDice",
      "value" = 20,
      "comment" = "the drums of thunder bolt dice - the 20-dice lightning bolt (print capture p. 299)",
    }, {
      "name" = "dltDrumsBoltCharges",
      "value" = 5,
      "comment" = "the drums of thunder bolt charges - the five of the lightning bolt (print capture p. 299)",
    }, {
      "name" = "dltDrumsChargesDie",
      "value" = 10,
      "comment" = "the drums of thunder charges die - the 2d10 when found (print capture p. 299)",
    }, {
      "name" = "dltDrumsOfThunder",
      "value" = 1,
      "comment" = "the drums of thunder - the waist harness pair, one use per round (print capture p. 299)",
    }, {
      "name" = "dltEightCoinsCount",
      "value" = 8,
      "comment" = "the eight diagram coins count - the eight of the set (print capture p. 299)",
    }, {
      "name" = "dltEightDiagramCoins",
      "value" = 1,
      "comment" = "the eight diagram coins - the copper discs, the fate spell on the toss and the command word (print capture p. 299)",
    }, {
      "name" = "dltMortarCommonPct",
      "value" = 80,
      "comment" = "the rice mortar common percent - the 80% common against the 20% extraordinary (print capture p. 299)",
    }, {
      "name" = "dltMortarFoodPeopleDie",
      "value" = 100,
      "comment" = "the rice mortar food die - the 1d100 people fed by the common mortar (print capture p. 299)",
    }, {
      "name" = "dltMortarWishesDie",
      "value" = 4,
      "comment" = "the rice mortar wishes die - the 1d4 wishes of the extraordinary mortar (print capture p. 299)",
    }, {
      "name" = "dltEverproducingRiceMortar",
      "value" = 1,
      "comment" = "the everproducing rice mortar - the mallet turn activating and deactivating, the hot and fresh food (print capture p. 299)",
    }, {
      "name" = "dltGemWishesMin",
      "value" = 1,
      "comment" = "the gem of wishes minimum - the 1 of the 1-4 wishes (print capture p. 299)",
    }, {
      "name" = "dltGemWishesMax",
      "value" = 4,
      "comment" = "the gem of wishes maximum - the 4 of the 1-4 wishes (print capture p. 299)",
    }, {
      "name" = "dltGemValueMinChien",
      "value" = 100,
      "comment" = "the gem of wishes value minimum - the 100 ch'ien of the 100-1000 (print capture p. 299)",
    }, {
      "name" = "dltGemValueMaxChien",
      "value" = 1000,
      "comment" = "the gem of wishes value maximum - the 1000 ch'ien of the 100-1000 (print capture p. 299)",
    }, {
      "name" = "dltGemOfWishes",
      "value" = 1,
      "comment" = "the gem of wishes - the detect magic reveal, the magic lost once the wishes granted (print capture p. 299)",
    }, {
      "name" = "dltGongCasterLevel",
      "value" = 15,
      "comment" = "the gong of dispelling caster level - the 15th-level potency of the dispels (print capture p. 299)",
    }, {
      "name" = "dltGongChargesDie",
      "value" = 100,
      "comment" = "the gong of dispelling charges die - the 1d100 initial charges (print capture p. 299)",
    }, {
      "name" = "dltGongOfDispelling",
      "value" = 1,
      "comment" = "the gong of dispelling - the three-foot gong, the dispel evil and magic within the 3 feet, one charge each sounding (print capture p. 299)",
    }, {
      "name" = "dltMalletLuckBonus",
      "value" = 2,
      "comment" = "the mallet of luck bonus - the +2 to hit and saving throws (print capture p. 299)",
    }, {
      "name" = "dltMalletLuckTurns",
      "value" = 6,
      "comment" = "the mallet of luck duration - the six turns of the bonus (print capture p. 299)",
    }, {
      "name" = "dltMalletLuckDamageDie",
      "value" = 6,
      "comment" = "the mallet of luck damage - the 2d6 of the bestowing blow, no cumulative effect (print capture p. 299)",
    }, {
      "name" = "dltMalletOfLuck",
      "value" = 1,
      "comment" = "the mallet of luck - the warped imagination, the combat use giving the opponent the bonus (print capture p. 299)",
    }, {
      "name" = "dltMinyanBearers",
      "value" = 20,
      "comment" = "the minyan bearers - the 20 men to move the shrine (print capture p. 299)",
    }, {
      "name" = "dltMinyanFearRadiusFt",
      "value" = 3,
      "comment" = "the minyan cause fear radius - the 3 feet constantly in effect (print capture p. 299)",
    }, {
      "name" = "dltMinyanRemoveCursesPerDay",
      "value" = 3,
      "comment" = "the minyan remove curse uses - the three per day as if a 20th-level caster (print capture p. 299)",
    }, {
      "name" = "dltMinyanCasterLevel",
      "value" = 20,
      "comment" = "the minyan caster level - the 20th-level of the remove curse (print capture p. 299)",
    }, {
      "name" = "dltMinyanSoheiMoralePct",
      "value" = 10,
      "comment" = "the minyan presence morale - the 10% improvement of the friendly sohei (print capture p. 299)",
    }, {
      "name" = "dltMinyanPowers",
      "value" = 1,
      "comment" = "the minyan powers - the cause fear, the remove curse, the presence, the ancient curse once per month, the heal once per week (print capture p. 299)",
    }, {
      "name" = "dltMinyanCare",
      "value" = 1,
      "comment" = "the minyan care - the daily offerings and incense, the services, the ethos, the holy day parade, the neglected duty losing the power permanently (print capture p. 299)",
    }, {
      "name" = "dltMirrorCuringChargesDie",
      "value" = 4,
      "comment" = "the mirror of curing charges die - the 2d4 charges, the shatter when spent (print capture p. 300)",
    }, {
      "name" = "dltMirrorOfCuring",
      "value" = 1,
      "comment" = "the mirror of curing - the heal spell on the viewer, one charge each (print capture p. 300)",
    }, {
      "name" = "dltMirrorOfEnlightenment",
      "value" = 1,
      "comment" = "the mirror of enlightenment - the colored aura of the detect evil/good, detect motivation, and know alignment, one person per round (print capture p. 300)",
    }, {
      "name" = "dltMirrorFearFleeDie",
      "value" = 6,
      "comment" = "the mirror of fear flee die - the 1d6 rounds of the panic, the quivering heap when unable to flee (print capture p. 300)",
    }, {
      "name" = "dltMirrorOfFear",
      "value" = 1,
      "comment" = "the mirror of fear - the hideous distorted reflection, the save versus spell or flee (print capture p. 300)",
    }, {
      "name" = "dltMirrorOfSpiritSeeing",
      "value" = 1,
      "comment" = "the mirror of spirit seeing - the constant power, the invisibility, disguise, illusion, polymorph, and shapechange penetrated, the prudent homeowner placement (print capture p. 300)",
    }, {
      "name" = "dltNetOfSpiritSnaring",
      "value" = 1,
      "comment" = "the net of spirit snaring - the frozen spirit, the attacks and spell-like abilities prevented, the bargain allowed (print capture p. 300)",
    }, {
      "name" = "dltNoisomeStringCount",
      "value" = 100,
      "comment" = "the noisome spirit chasers count - the strings of 100 firecrackers (print capture p. 300)",
    }, {
      "name" = "dltNoisomeFleeMin",
      "value" = 2,
      "comment" = "the noisome spirit chasers flee minimum - the 2 of the 2-5 rounds of the lesser spirits (print capture p. 300)",
    }, {
      "name" = "dltNoisomeFleeMax",
      "value" = 5,
      "comment" = "the noisome spirit chasers flee maximum - the 5 of the 2-5 rounds (print capture p. 300)",
    }, {
      "name" = "dltNoisomeSpiritChasers",
      "value" = 1,
      "comment" = "the noisome spirit chasers - the greater spirit save versus spell, no damage to any creature (print capture p. 300)",
    }, {
      "name" = "dltPaperFormsIgnitePct",
      "value" = 80,
      "comment" = "the paper of forms ignite percent - the 80% of the normal fires, the magical fires certain (print capture p. 300)",
    }, {
      "name" = "dltPaperFormsSheetsDie",
      "value" = 4,
      "comment" = "the paper of forms sheets die - the 1d4 sheets when found (print capture p. 300)",
    }, {
      "name" = "dltPaperOfForms",
      "value" = 1,
      "comment" = "the paper of forms - the origami proficiency, the animal intelligence and non-magical objects, the second command word reverting, the shape fixed thereafter, the unfold ruining (print capture p. 300)",
    }, {
      "name" = "dltPearlOfProtectionFromFire",
      "value" = 1,
      "comment" = "the pearl of protection from fire - the ring of fire resistance per the DMG when carried (print capture p. 300)",
    }, {
      "name" = "dltPearlTideRadiusFt",
      "value" = 60,
      "comment" = "the pearl of tide radius - the 60 feet of the affected waters (print capture p. 300)",
    }, {
      "name" = "dltPearlTideRateFt",
      "value" = 5,
      "comment" = "the pearl of tide rate - the five feet per round of the recede or rise, the instant return on the ended concentration (print capture p. 300)",
    }, {
      "name" = "dltPearlOfEbbingTide",
      "value" = 1,
      "comment" = "the pearl of the ebbing tide - the command word and the concentration (print capture p. 300)",
    }, {
      "name" = "dltPearlOfRisingTide",
      "value" = 1,
      "comment" = "the pearl of the rising tide - the identical twin with the rise (print capture p. 300)",
    }, {
      "name" = "dltScrollSpiritsCasterLevel",
      "value" = 12,
      "comment" = "the scroll of protection from spirits caster level - the 12th-level shukenja (print capture p. 300)",
    }, {
      "name" = "dltScrollOfProtectionFromSpirits",
      "value" = 1,
      "comment" = "the scroll of protection from spirits - the protection scroll usable by any character (print capture p. 300)",
    }, {
      "name" = "dltSealDeceptionStampErrorPct",
      "value" = 5,
      "comment" = "the seal of deception stamp error - the 5% with the stamp at hand (print capture p. 301)",
    }, {
      "name" = "dltSealDeceptionMemoryErrorPct",
      "value" = 30,
      "comment" = "the seal of deception memory error - the 30% from the memory, the forgery revealed under the careful checking (print capture p. 301)",
    }, {
      "name" = "dltSealOfDeception",
      "value" = 1,
      "comment" = "the seal of deception - the name seal culture, the reshaping stamp, the command word and the concentration (print capture p. 301)",
    }, {
      "name" = "dltSealOfVigor",
      "value" = 1,
      "comment" = "the seal of vigor - the inscribed name activating, the double healing and the maximum cures while carried, the damage link of the stolen seal (print capture p. 301)",
    }, {
      "name" = "dltTabletSpellLevel",
      "value" = 9,
      "comment" = "the tablet of spirit summoning spell level - the 9th-level wu jen summon spirit (print capture p. 301)",
    }, {
      "name" = "dltTabletCharsDie",
      "value" = 6,
      "comment" = "the tablet of spirit summoning characters die - the 2d6 inscribed characters fading one per use (print capture p. 301)",
    }, {
      "name" = "dltTabletValueChien",
      "value" = 10,
      "comment" = "the tablet of spirit summoning value - the 10 ch'ien of the smooth jade when spent (print capture p. 301)",
    }, {
      "name" = "dltTabletOfSpiritSummoning",
      "value" = 1,
      "comment" = "the tablet of spirit summoning - the jade tablet, once per week (print capture p. 301)",
    }, {
      "name" = "dltWheelsFireRadiusFt",
      "value" = 30,
      "comment" = "the wheels of fire radius - the 30 feet of the intense heat (print capture p. 301)",
    }, {
      "name" = "dltWheelsFireDamageDie",
      "value" = 6,
      "comment" = "the wheels of fire damage - the 2d6 of the creatures within, the fire-immune spared (print capture p. 301)",
    }, {
      "name" = "dltWheelsOfFire",
      "value" = 1,
      "comment" = "the wheels of fire - the chariot pairs, the flame not hindering the chariot, the flaming tracks, the second command word ending (print capture p. 301)",
    }, {
      "name" = "dltWritingSetCalligraphyBonus",
      "value" = 2,
      "comment" = "the wondrous writing set calligraphy bonus - the +2 proficiency (print capture p. 301)",
    }, {
      "name" = "dltWritingSetPagesMin",
      "value" = 2,
      "comment" = "the wondrous writing set pages minimum - the 2 of the 2-5 pages (print capture p. 301)",
    }, {
      "name" = "dltWritingSetPagesMax",
      "value" = 5,
      "comment" = "the wondrous writing set pages maximum - the 5 of the 2-5 pages (print capture p. 301)",
    }, {
      "name" = "dltWondrousWritingSet",
      "value" = 1,
      "comment" = "the wondrous writing set - the lacquered box, the perfect forgery on the calligraphy roll (print capture p. 301)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dltBannerSpellBlockLevel']() != 5  or m['dltBannerRadiusYd']() != 100  or m['dltBellProtRadiusYd']() != 50  or m['dltBellProtGreaterSavePenalty']() != 4  or m['dltBellProtCrossDamageDice']() != 4  or m['dltBellProtWithinDamageDice']() != 3  or m['dltBellWarnRadiusFt']() != 30  or m['dltBellWarnHoursDie']() != 6  or m['dltBellWarnChargesDie']() != 10  or m['dltBiwaDiscordRadiusFt']() != 3  or m['dltBiwaDiscordFrenzyMin']() != 2  or m['dltBiwaDiscordFrenzyMax']() != 5  or m['dltCharmFireCatchPct']() != 50  or m['dltCharmTheftSkillPenaltyPct']() != 20  or m['dltCharmTheftRemoveDamageDie']() != 10  or m['dltDiamondMaceBoltDice']() != 12  or m['dltDiamondMaceChargesDie']() != 10  or m['dltDiamondMaceValueChien']() != 1000  or m['dltDrumsFlyCharges']() != 1  or m['dltDrumsTrapezeCharges']() != 3  or m['dltDrumsPanicCharges']() != 2  or m['dltDrumsWeatherCharges']() != 1  or m['dltDrumsBoltDice']() != 20  or m['dltDrumsBoltCharges']() != 5  or m['dltDrumsChargesDie']() != 10  or m['dltEightCoinsCount']() != 8  or m['dltMortarCommonPct']() != 80  or m['dltMortarFoodPeopleDie']() != 100  or m['dltMortarWishesDie']() != 4  or m['dltGemWishesMin']() != 1  or m['dltGemWishesMax']() != 4  or m['dltGemValueMinChien']() != 100  or m['dltGemValueMaxChien']() != 1000  or m['dltGongCasterLevel']() != 15  or m['dltGongChargesDie']() != 100  or m['dltMalletLuckBonus']() != 2  or m['dltMalletLuckTurns']() != 6  or m['dltMalletLuckDamageDie']() != 6  or m['dltMinyanBearers']() != 20  or m['dltMinyanFearRadiusFt']() != 3  or m['dltMinyanRemoveCursesPerDay']() != 3  or m['dltMinyanCasterLevel']() != 20  or m['dltMinyanSoheiMoralePct']() != 10  or m['dltMirrorCuringChargesDie']() != 4  or m['dltMirrorFearFleeDie']() != 6  or m['dltNoisomeStringCount']() != 100  or m['dltNoisomeFleeMin']() != 2  or m['dltNoisomeFleeMax']() != 5  or m['dltPaperFormsIgnitePct']() != 80  or m['dltPaperFormsSheetsDie']() != 4  or m['dltPearlTideRadiusFt']() != 60  or m['dltPearlTideRateFt']() != 5  or m['dltScrollSpiritsCasterLevel']() != 12  or m['dltSealDeceptionStampErrorPct']() != 5  or m['dltSealDeceptionMemoryErrorPct']() != 30  or m['dltTabletSpellLevel']() != 9  or m['dltTabletCharsDie']() != 6  or m['dltTabletValueChien']() != 10  or m['dltWheelsFireRadiusFt']() != 30  or m['dltWheelsFireDamageDie']() != 6  or m['dltWritingSetCalligraphyBonus']() != 2  or m['dltWritingSetPagesMin']() != 2  or m['dltWritingSetPagesMax']() != 5  or  m['dltBannerOfProtection']() != 1  or  m['dltBellOfProtection']() != 1  or  m['dltBellOfWarning']() != 1  or  m['dltBiwaOfCalm']() != 1  or  m['dltBiwaOfCharm']() != 1  or  m['dltBiwaOfDiscord']() != 1  or  m['dltCharmOfProtectionFromDisease']() != 1  or  m['dltCharmOfProtectionFromFire']() != 1  or  m['dltCharmOfProtectionFromSpirits']() != 1  or  m['dltCharmOfProtectionFromTheft']() != 1  or  m['dltDiamondMace']() != 1  or  m['dltDrumsOfThunder']() != 1  or  m['dltEightDiagramCoins']() != 1  or  m['dltEverproducingRiceMortar']() != 1  or  m['dltGemOfWishes']() != 1  or  m['dltGongOfDispelling']() != 1  or  m['dltMalletOfLuck']() != 1  or  m['dltMinyanPowers']() != 1  or  m['dltMinyanCare']() != 1  or  m['dltMirrorOfCuring']() != 1  or  m['dltMirrorOfEnlightenment']() != 1  or  m['dltMirrorOfFear']() != 1  or  m['dltMirrorOfSpiritSeeing']() != 1  or  m['dltNetOfSpiritSnaring']() != 1  or  m['dltNoisomeSpiritChasers']() != 1  or  m['dltPaperOfForms']() != 1  or  m['dltPearlOfProtectionFromFire']() != 1  or  m['dltPearlOfEbbingTide']() != 1  or  m['dltPearlOfRisingTide']() != 1  or  m['dltScrollOfProtectionFromSpirits']() != 1  or  m['dltSealOfDeception']() != 1  or  m['dltSealOfVigor']() != 1  or  m['dltTabletOfSpiritSummoning']() != 1  or  m['dltWheelsOfFire']() != 1  or  m['dltWondrousWritingSet']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dltBannerSpellBlockLevel']() != 5  or m['dltBannerRadiusYd']() != 100  or m['dltBellProtRadiusYd']() != 50  or m['dltBellProtGreaterSavePenalty']() != 4  or m['dltBellProtCrossDamageDice']() != 4  or m['dltBellWarnRadiusFt']() != 30  or m['dltBiwaDiscordFrenzyMin']() != 2  or m['dltBiwaDiscordFrenzyMax']() != 5  or m['dltBannerOfProtection']() != 1  or m['dltBellOfProtection']() != 1  or m['dltBiwaOfCalm']() != 1",
      "note" = "the banner, bells, and biwa, healthy values, each condition false",
    }, {
      "expr" = "m['dltCharmFireCatchPct']() != 50  or m['dltCharmTheftSkillPenaltyPct']() != 20  or m['dltCharmTheftRemoveDamageDie']() != 10  or m['dltDiamondMaceBoltDice']() != 12  or m['dltDiamondMaceValueChien']() != 1000  or m['dltDrumsBoltDice']() != 20  or m['dltDrumsBoltCharges']() != 5  or m['dltEightCoinsCount']() != 8  or m['dltMortarCommonPct']() != 80  or m['dltMortarWishesDie']() != 4",
      "note" = "the charms, mace, drums, and mortar, healthy values, each condition false",
    }, {
      "expr" = "m['dltGemWishesMin']() != 1  or m['dltGemWishesMax']() != 4  or m['dltGemValueMaxChien']() != 1000  or m['dltGongCasterLevel']() != 15  or m['dltGongChargesDie']() != 100  or m['dltMalletLuckBonus']() != 2  or m['dltMalletLuckTurns']() != 6  or m['dltMalletLuckDamageDie']() != 6  or m['dltMinyanBearers']() != 20  or m['dltMinyanSoheiMoralePct']() != 10",
      "note" = "the gem, gong, mallet, and minyan, healthy values, each condition false",
    }, {
      "expr" = "m['dltMirrorCuringChargesDie']() != 4  or m['dltMirrorFearFleeDie']() != 6  or m['dltNoisomeStringCount']() != 100  or m['dltNoisomeFleeMax']() != 5  or m['dltPaperFormsIgnitePct']() != 80  or m['dltPaperFormsSheetsDie']() != 4  or m['dltPearlTideRadiusFt']() != 60  or m['dltPearlTideRateFt']() != 5  or m['dltScrollSpiritsCasterLevel']() != 12",
      "note" = "the mirrors, chasers, paper, and pearls, healthy values, each condition false",
    }, {
      "expr" = "m['dltSealDeceptionStampErrorPct']() != 5  or m['dltSealDeceptionMemoryErrorPct']() != 30  or m['dltTabletSpellLevel']() != 9  or m['dltTabletCharsDie']() != 6  or m['dltTabletValueChien']() != 10  or m['dltWheelsFireRadiusFt']() != 30  or m['dltWheelsFireDamageDie']() != 6  or m['dltWritingSetCalligraphyBonus']() != 2  or m['dltWritingSetPagesMin']() != 2  or m['dltWritingSetPagesMax']() != 5  or m['dltWondrousWritingSet']() != 1",
      "note" = "the seals, tablet, wheels, and writing set, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R758 OA magical items prose audit",
      "comment" = "OA round one hundred forty-five (capture pp. 296-301): the Oriental Magical Items prose - the thirty-four item descriptions, the banner and bells through the wondrous writing set, the minyan powers and care, single-pass pins per the Chapter 9 provenance shift",
    },
}
