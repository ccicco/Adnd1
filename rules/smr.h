// =========================================================================================
// Adnd1 - rules/smr.h
// the Sumerian mythos - the D&DG walk round eighteen, print pp. 125-127:
// seven stat-block rows - the five greater gods (Enlil, Enki, Inanna, Ki,
// Utu) and the two lesser (Nanna-Sin, Nin-hursag) - plus the city-temple
// doctrine of the intro (the patron deity, the priest-king, the punishment
// ladder, the holy days) and the pantheon-wide cloud chariots doctrine of
// print p. 127. Every one of the seven beings prints armor class -2, the only
// uniform-AC pantheon of the walk.
// census 788 -> 789.
//
// primary ink: the extract/ddg tesseract pass (pNNN_full.txt + pNNN_tsv.tsv,
// print = pdf - 1, pages 126-128; the second printing) with the tsv x-y
// geometry as the fold-swap, dropped-glyph and not-printed-cell arbiter - the
// psm-4 fold interleaved the Inanna and Ki blocks of print p. 126 across the
// two columns and the geometry sorted them; the collation voice: the 1eonline
// L&L transcription (the per-being pages, the R853 parity voice). The
// adjudications: the Enlil 127/36" move garble adjudicated 12 by the L&L
// voice, the Enlil (64") size = the 6 1/2 foot 78 fraction cell (the L&L
// voice reads 6.5, the R859 fraction fingerprint), the (&) and (6) size
// garbles read 72 and 60 through the L&L voice, the Utu 32 attacks garble
// adjudicated 3/2, the Ki 15/36//36 triple slash pinned as printed in both
// voices (the R861 convention), the Inanna single-pipe psionic I (the L&L
// voice reads II) and the Inanna warriors-and-lovers worshipper line pinned
// by the print, the Enki 10th-level bard (the L&L voice reads 13th in each),
// the Utu 15th in-each magic-user pair (the L&L voice reads 15th illusionist
// alone) and the Enlil D:23 CH:24 cells (the L&L voice normalizes to the 25s)
// pinned by the print.
//
namespace rules {

// ---- the Sumerian doctrine ----

// the Sumerian mythos round: the D&DG walk round eighteen
inline int smrRound()
    { return 866; }

// the section opens on print p. 125 (Enlil)
inline int smrPrintStart()
    { return 125; }

// the section closes on print p. 127 (Utu, the cloud chariots)
inline int smrPrintEnd()
    { return 127; }

// the seventh day of the month is a holy day
inline int smrHolyDaySeventh()
    { return 7; }

// the fifteenth day of the month is a holy day
inline int smrHolyDayFifteenth()
    { return 15; }

// the twenty-fifth day of the month is a holy day
inline int smrHolyDayTwentyFifth()
    { return 25; }

// the second-transgression punishment: fifteen troubles, each worse than the
// last, none automatically fatal
inline int smrTroubleLadderCount()
    { return 15; }

// the cloud chariot movement rate in inches
inline int smrCloudChariotMove()
    { return 24; }

// every city has its patron deity and all the people belong to that temple
// and none other
inline bool smrCityPatronDeity()
    { return true; }

// all officials of the city are clerics of the temple and the high priest is
// always the king or queen of the city-state
inline bool smrKingHighPriest()
    { return true; }

// the temples have a stepped pyramid shape in the manner of the Aztec temples
inline bool smrSteppedPyramidTemples()
    { return true; }

// the more important temples are raised up on artificial hills (ziggurats) of
// red brick
inline bool smrZigguratRedBrick()
    { return true; }

// sacrifices and gifts are all made as items that dress up altars and temple
// surroundings
inline bool smrSacrificeItemsAltars()
    { return true; }

// the clerics themselves make items to be directly sacrificed to the gods by
// burning
inline bool smrClericItemBurning()
    { return true; }

// human lives are sacrificed to the gods
inline bool smrHumanSacrifice()
    { return true; }

// the human sacrifices are primarily condemned criminals
inline bool smrCondemnedCriminals()
    { return true; }

// each temple has an image of its god on a raised platform in an inner shrine
// closed off to the public
inline bool smrInnerShrineImage()
    { return true; }

// before the image is a table used as an altar with all the gifts of the year
// upon it
inline bool smrAltarTableGifts()
    { return true; }

// a central courtyard beyond the main entrance serves public worship
inline bool smrCentralCourtyard()
    { return true; }

// the building has side chapels and storerooms of several types
inline bool smrSideChapels()
    { return true; }

// the main entrance is set at right angles to the inner temple
inline bool smrRightAngleEntrance()
    { return true; }

// clerics serve the best meat and drink to the gods on special tables beside
// altars, and the food is burnt every night for the gods use
inline bool smrFoodBurntNightly()
    { return true; }

// a sacrifice is always held on the night of the new moon
inline bool smrNewMoonSacrifice()
    { return true; }

// the first major transgression results in an acute severe gastro-intestinal
// disease (as per DMG) for the offending cleric
inline bool smrPunishmentGastro()
    { return true; }

// the second transgression results in a punishment of fifteen troubles, each
// worse than the last
inline bool smrPunishmentTroubles()
    { return true; }

// the third transgression results in the death of the offending one
inline bool smrPunishmentDeath()
    { return true; }

// any transgression can be erased in the sight of the deity by a sacrifice
// sufficient and important-or-expensive in proportion to the offense
inline bool smrSacrificeErases()
    { return true; }

// clerics of this pantheon must shave all hair from their bodies
inline bool smrShavenClerics()
    { return true; }

// the clerics wear kilts and robes of white with colorful borders
inline bool smrWhiteKiltRobes()
    { return true; }

// the shape and color of the border indicates the cleric patron deity
inline bool smrBorderIndicatesPatron()
    { return true; }

// female clerics wear rounded conical hats to cover their baldness
inline bool smrConicalHats()
    { return true; }

// the gods are unusually close to their worshipers and every worshiper is a
// servant of his or her god, a willingness to help soon lost to all other
// mythoi
inline bool smrGodsCloseToWorshipers()
    { return true; }

// the geographical area of the Sumerian mythos is almost exactly the
// Babylonian; the two were kept separate for diversity, deliberately
// increased in some cases to prevent overlap (the Greek-Roman manner)
inline bool smrBabylonianOverlap()
    { return true; }

// all of the gods and goddesses have cloud chariots at their personal command
inline bool smrCloudChariotsAll()
    { return true; }

// the chariots appear to be clouds that give off a dazzling radiance and
// become platforms of transportation when a god steps on them
inline bool smrCloudChariotRadiance()
    { return true; }

// the chariots are also a means to impress worshipers and non-believers alike
inline bool smrCloudChariotImpress()
    { return true; }

// a cloud chariot can teleport itself to any place where there are clouds in
// the sky
inline bool smrCloudChariotTeleport()
    { return true; }

// a cloud chariot is unaffected by any material force and is never destroyed
inline bool smrCloudChariotIndestructible()
    { return true; }

// the devices are capable of carrying anything the controlling deity wishes
inline bool smrCloudChariotCarry()
    { return true; }

// the gods will always appear to their clerics on such devices to prove that
// they are gods
inline bool smrGodsAppearOnChariots()
    { return true; }

// ---- Enlil ----

// the lightning bolt damage per strike (save vs. spells for half)
inline int smrEnlilBoltDmg()
    { return 40; }

// Enlil raises electrical storms and directs lightning bolts at targets up to
// a mile distant
inline int smrEnlilBoltRangeMiles()
    { return 1; }

// the stone axe damage per strike
inline int smrEnlilAxeDmg()
    { return 50; }

// Enlil's percentage chance of NOT hitting metal is equal to the base armor
// class of the metallically-armored opponent times ten
inline int smrEnlilAxePctTimes()
    { return 10; }

// the worked example: a 30 percent chance of striking an unarmored portion of
// a person in plate mail
inline int smrEnlilAxePlatePct()
    { return 30; }

// the axe teleports to the god's hand if taken more than 100 feet from his
// body
inline int smrEnlilTeleportFeet()
    { return 100; }

// the axe has a 25 percent chance of negating any spell tossed at the god
// before the spell reaches him
inline int smrEnlilSpellNegatePct()
    { return 25; }

// at will the god can shape change
inline bool smrEnlilShapeChange()
    { return true; }

// Enlil can ESP at any distance
inline bool smrEnlilEspAnyDistance()
    { return true; }

// unlike the other deities of this pantheon, Enlil has the power to raise the
// dead
inline bool smrEnlilRaiseDead()
    { return true; }

// Enlil takes no damage from lightning or electrical attacks
inline bool smrEnlilLightningImmune()
    { return true; }

// in battle the god wears a war helm that is not affected by anything
inline bool smrEnlilWarHelmUnaffected()
    { return true; }

// when attacked by only one weapon in a given melee, that weapon is forced to
// hit the helm (no saving throw)
inline bool smrEnlilHelmForcedHit()
    { return true; }

// if attacked by two or more weapons, Enlil chooses which shall strike his
// helm
inline bool smrEnlilHelmChooseTwo()
    { return true; }

// when wearing the helm Enlil feels no shock or harm from objects hitting it
inline bool smrEnlilHelmNoShock()
    { return true; }

// the stone axe does no damage if it hits metal
inline bool smrEnlilAxeNoMetalDmg()
    { return true; }

// Enlil's axe disenchant any magic item it comes in contact with (no save)
inline bool smrEnlilAxeDisenchant()
    { return true; }

// the axe cannot be broken
inline bool smrEnlilAxeUnbreakable()
    { return true; }

// ---- Enki ----

// the jade green mace damage on a successful hit
inline int smrEnkiMaceDmg()
    { return 35; }

// the mace negates any spell below the 6th level cast at the god
inline int smrEnkiNegateSpellBelow()
    { return 6; }

// Enki can only teleport to areas with water in quantities of more than 50
// gallons
inline int smrEnkiWaterGallons()
    { return 50; }

// one being of any species that has died in the water can be summoned per day
inline int smrEnkiSummonPerDay()
    { return 1; }

// this god is always green in color in any of his human manifestations
inline bool smrEnkiAlwaysGreen()
    { return true; }

// at will he shape changes
inline bool smrEnkiShapeChange()
    { return true; }

// Enki is aware of and can summon any being that has died in the water to do
// his bidding
inline bool smrEnkiWaterDeadSummon()
    { return true; }

// a particular summoned being cannot be summoned ever again
inline bool smrEnkiSummonOnceEver()
    { return true; }

// Enki moves like a blink dog
inline bool smrEnkiBlinkDogMove()
    { return true; }

// Enki is immune to all forms of heat
inline bool smrEnkiHeatImmune()
    { return true; }

// he can only teleport to areas where there is water
inline bool smrEnkiTeleportWaterOnly()
    { return true; }

// the god is known for his great hatred of demons and will slay any person in
// his presence that has ever dealt with these monsters in a friendly manner
inline bool smrEnkiDemonHater()
    { return true; }

// in battle he fights the strongest enemy facing his group first
inline bool smrEnkiStrongestFirst()
    { return true; }

// the mace is ethereal when not held by the god
inline bool smrEnkiMaceEthereal()
    { return true; }

// the mace will never cause harm to a lawful neutral being it strikes
inline bool smrEnkiMaceNeverHarmLN()
    { return true; }

// Enki's armor, helm and shield are made out of water and automatically
// absorb the first two hits made against him in any given melee round
inline bool smrEnkiWaterArmorAbsorb()
    { return true; }

// Enki is the patron of jewelers, goldsmiths and stonecutters; only the
// finest jewels, gold items and carvings can be given to his temples in
// homage
inline bool smrEnkiPatronJewelers()
    { return true; }

// ---- Inanna ----

// the double bladed brass axe damage per hit
inline int smrInannaAxeDmg()
    { return 25; }

// the chariot is pulled by seven lions
inline int smrInannaLionsCount()
    { return 7; }

// the flying lions movement rate in inches
inline int smrInannaLionMv()
    { return 30; }

// this goddess usually appears in the form of a beautiful woman
inline bool smrInannaBeautifulWoman()
    { return true; }

// on rare occasions she picks exceptionally brave warriors in battle and aids
// them
inline bool smrInannaAidBraveWarriors()
    { return true; }

// the aid takes the form of that warrior never being hit
inline bool smrInannaAidNeverHit()
    { return true; }

// the aided warrior always makes his or her saving throw
inline bool smrInannaAidAlwaysSave()
    { return true; }

// the aided warrior never misses an attempted hit
inline bool smrInannaAidNeverMiss()
    { return true; }

// the aid lasts for the duration of the melee
inline bool smrInannaAidMeleeDuration()
    { return true; }

// at will the goddess can shape change
inline bool smrInannaShapeChange()
    { return true; }

// at will she can animate statues of herself in her temples
inline bool smrInannaAnimateStatues()
    { return true; }

// she can summon from the dead any being she has killed in a past battle to
// aid any given side (only on a one time basis per being)
inline bool smrInannaSummonDeadKilled()
    { return true; }

// the axe causes any armor it strikes to turn to dust (no saving throw)
inline bool smrInannaAxeArmorDust()
    { return true; }

// the axe user is never surprised
inline bool smrInannaAxeNeverSurprised()
    { return true; }

// her breast plates negate any damage caused by heat, cold, fang, or claw to
// her body
inline bool smrInannaBreastPlates()
    { return true; }

// the goddess is a fickle being and requires the sacrificing of the best in
// magical or high quality weapons on her altars
inline bool smrInannaFickleWeapons()
    { return true; }

// in battle she drives a chariot pulled by seven lions
inline bool smrInannaLionChariot()
    { return true; }

// the chariot lions have been given the gift of flight and are otherwise
// normal beasts under her complete control
inline bool smrInannaLionFlight()
    { return true; }

// ---- Ki ----

// any non-monster animal of any species is hers to summon instantly, in any
// number up to 100
inline int smrKiAnimalCount()
    { return 100; }

// the luck of the gods lasts for a 24 hour period
inline int smrKiLuckHours()
    { return 24; }

// Ki appears as an elfin woman of great beauty
inline bool smrKiElfinWoman()
    { return true; }

// the goddess cannot be touched by anything material cast through the air at
// her
inline bool smrKiUntouchedByThrown()
    { return true; }

// at will she can shape change (into non-monster forms only)
inline bool smrKiShapeChangeNonMonster()
    { return true; }

// she can give the luck of the gods to those she favors: the recipient always
// makes his or her saving throw
inline bool smrKiLuckOfGods()
    { return true; }

// the luck of the gods recipient only suffers half damage from any attack
inline bool smrKiLuckHalfDamage()
    { return true; }

// any non-monster animal of any species is hers to summon instantly
inline bool smrKiAnimalSummon()
    { return true; }

// no species can be summoned more than once per week
inline bool smrKiSpeciesOncePerWeek()
    { return true; }

// she can only summon one type of creature at a time
inline bool smrKiOneTypeAtATime()
    { return true; }

// she has the power to instantly know where any given thing is on the surface
// of the earth
inline bool smrKiLocateAnything()
    { return true; }

// when forced to do combat she will take only half damage from any attack
inline bool smrKiHalfDamageAlways()
    { return true; }

// she will always make her saving throw on all things
inline bool smrKiAlwaysSaves()
    { return true; }

// Ki's clerics are druids
inline bool smrKiClericsDruids()
    { return true; }

// her Great Druid may receive communications directly from the goddess
inline bool smrKiGreatDruidComms()
    { return true; }

// ---- Nanna-Sin ----

// the blue glow acts as a rod of beguiling to all who come within 10 feet of
// it
inline int smrNannaSinGlowFeet()
    { return 10; }

// the jet black axe bonus
inline int smrNannaSinAxePlus()
    { return 3; }

// the axe damage per hit
inline int smrNannaSinAxeDmg()
    { return 30; }

// this human-appearing god is always bathed in a blue glow that acts as a rod
// of beguiling
inline bool smrNannaSinBlueGlow()
    { return true; }

// at will Nanna-Sin can negate heat
inline bool smrNannaSinNegateHeat()
    { return true; }

// at will Nanna-Sin can negate cold
inline bool smrNannaSinNegateCold()
    { return true; }

// at will Nanna-Sin can negate electricity
inline bool smrNannaSinNegateElectricity()
    { return true; }

// at will Nanna-Sin can negate light
inline bool smrNannaSinNegateLight()
    { return true; }

// at will Nanna-Sin can negate darkness
inline bool smrNannaSinNegateDarkness()
    { return true; }

// the axe also acts as a sword of sharpness
inline bool smrNannaSinSwordOfSharpness()
    { return true; }

// ---- Nin-hursag ----

// the withering takes the form of a special 9th level spell
inline int smrNinhursagWitherSpellLevel()
    { return 9; }

// the withering works like three charges from a staff of withering
inline int smrNinhursagWitherCharges()
    { return 3; }

// this deity always appears as a dark-skinned female
inline bool smrNinhursagDarkSkinnedFemale()
    { return true; }

// she is mistress of gravity and magnetism and has complete control over
// these forces
inline bool smrNinhursagGravityControl()
    { return true; }

// she can give the gift of flight to those she especially favors
inline bool smrNinhursagGiftOfFlight()
    { return true; }

// she has the power to wither those she hates
inline bool smrNinhursagWitherHated()
    { return true; }

// the withering requires the same components as a wish spell
inline bool smrNinhursagWitherWishComponents()
    { return true; }

// ---- Utu ----

// the deity is constantly bathed in a dazzling 10 radius yellow glow
inline int smrUtuGlowRadiusFeet()
    { return 10; }

// the glow causes all enemies to suffer a -2 on all strikes at the god
inline int smrUtuGlowStrikeMod()
    { return 2; }

// he can cast two light rays per round at anything in sight
inline int smrUtuRayCount()
    { return 2; }

// each light ray damage (save vs. spells for half damage)
inline int smrUtuRayDmg()
    { return 20; }

// he regenerates all lost hit points when touched by heat of any degree above
// 100 degrees F
inline int smrUtuHeatThreshold()
    { return 100; }

// he polymorphs living matter into dirt with a -3 on the being saving throw
inline int smrUtuPolymorphSaveMod()
    { return 3; }

// the sun-bits can be thrown up to 2 miles away from the god
inline int smrUtuSunbitsRangeMiles()
    { return 2; }

// the sun-bits strike for 50 points of heat damage when they hit
inline int smrUtuSunbitsDmg()
    { return 50; }

// this deity is always in human form
inline bool smrUtuHumanForm()
    { return true; }

// all undead wither to dust at a touch of his glow
inline bool smrUtuUndeadWither()
    { return true; }

// he regenerates all lost hit points when touched by heat
inline bool smrUtuRegenerateHeat()
    { return true; }

// he is able to polymorph living matter into dirt
inline bool smrUtuPolymorphDirt()
    { return true; }

// his aura causes anything striking his body to melt unless the thing is
// indestructible
inline bool smrUtuAuraMelt()
    { return true; }

// ---- the combat grid ----

// The armor class cells (ALL SEVEN BEINGS PRINT MINUS 2 - the only uniform-AC
// pantheon of the walk; Inanna the bare-dash-minus _2 print, the w32 dash
// glyph matching the minus 2 tokens elsewhere)
inline int smrCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -2;
        case 6:
            return -2;
        default:
            return 0;
        }
    }

// The alternative armor class cells (none printed - all 0)
inline int smrCbtACAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Enlil 400 the high, Nanna-Sin 339 the low)
inline int smrCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 388;
        case 2:
            return 391;
        case 3:
            return 380;
        case 4:
            return 339;
        case 5:
            return 355;
        case 6:
            return 377;
        default:
            return 0;
        }
    }

// The move cells (Enlil the 127/36" print garble adjudicated 12 by the L&L
// voice; Utu the Infinite print minus 1 sentinel - the R863 Death and R861
// Amaterasu precedent)
inline int smrCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 9;
        case 6:
            return -1;
        default:
            return 0;
        }
    }

// The alternative move cells (Ki prints the triple slash 15/36//36 - both
// voices carry the duplicated third 36, pinned as printed the R861 Susanowo
// convention with the duplicate in this comment; six dual moves, Utu the lone
// 0)
inline int smrCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 36;
        case 4:
            return 24;
        case 5:
            return 12;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The attacks-per-round numerators (Inanna 2; Ki the printed 0 attacks; Enki,
// Nin-hursag and Utu the 3 of three-halves - Utu the 32 tesseract garble
// adjudicated 3/2 by the L&L voice)
inline int smrCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// The attacks-per-round denominators (Enki, Nin-hursag and Utu the 2 of
// three-halves; 0 = a bare number print)
inline int smrCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 2;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The magic resistance cells (Ki and Utu 90 the highs, Inanna 66, Nanna-Sin
// 75, Enlil, Enki and Nin-hursag 50)
inline int smrCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 66;
        case 3:
            return 90;
        case 4:
            return 75;
        case 5:
            return 50;
        case 6:
            return 90;
        default:
            return 0;
        }
    }

// The size cells in inches (Enlil the 6 1/2 foot 78 - the (64") tesseract
// garble, the L&L voice reading 6.5, the R859 fraction fingerprint; Enki,
// Inanna, Nanna-Sin, Nin-hursag and Utu the 6 foot 72, Inanna and Utu the (&)
// tesseract garble with the L&L voice reading 6; Ki the 5 foot 60 - the (5)
// print garble)
inline int smrCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 78;
        case 1:
            return 72;
        case 2:
            return 72;
        case 3:
            return 60;
        case 4:
            return 72;
        case 5:
            return 72;
        case 6:
            return 72;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric levels (Ki the 30th level high; Enlil and Enki 20; Inanna and
// Nanna-Sin the in-each 10 and 13 pairs; Utu 15)
inline int smrClsClr(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 10;
        case 3:
            return 30;
        case 4:
            return 13;
        case 5:
            return 0;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// The druid levels (Ki the 30th-cleric/14th-druid print; Inanna and Nanna-Sin
// the in-each pairs; Utu 14; Nin-hursag the 13th level druid)
inline int smrClsDrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 14;
        case 4:
            return 13;
        case 5:
            return 13;
        case 6:
            return 14;
        default:
            return 0;
        }
    }

// The fighter levels (Nanna-Sin 16, Nin-hursag 11)
inline int smrClsFtr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 16;
        case 5:
            return 11;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The ranger levels (Enlil 19, Inanna 20, Utu 13)
inline int smrClsRng(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 13;
        default:
            return 0;
        }
    }

// The paladin levels (Enki 13, Ki 10)
inline int smrClsPal(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 13;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user levels (Nin-hursag the 30th level high; Enki, Inanna, Ki,
// Nanna-Sin and Utu the in-each pairs; Enlil 15)
inline int smrClsMU(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 20;
        case 4:
            return 15;
        case 5:
            return 30;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// The illusionist levels (the in-each rows Enki 13, Inanna 12, Ki 20,
// Nanna-Sin 15, Utu 15; Utu the L&L voice reads 15th illusionist alone, the
// print pins the in-each pair)
inline int smrClsIll(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 20;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// The thief levels (Inanna the 15th level thief)
inline int smrClsThf(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The assassin levels (none printed - all 0)
inline int smrClsAss(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The monk levels (none printed - all 0)
inline int smrClsMnk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The bard levels (Ki 20 the high, Enlil 12, Nanna-Sin 15, Inanna 10, Utu 5;
// ENKI PRINTS THE 10TH LEVEL BARD - the L&L voice reads 13th in each, pinned
// by the print with the divergence noted; Nin-hursag the Nil print)
inline int smrClsBrd(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 5;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (Enlil and Nanna-Sin 25; Ki the bare 25 with no bonus
// pair; Utu 24)
inline int smrAbiS(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 25;
        case 5:
            return 23;
        case 6:
            return 24;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (Ki the bare-25 print 0; the Enlil (47,4+14)
// tesseract garble adjudicated (+7,+14) by the L&L voice and the bracket
// arithmetic)
inline int smrAbiHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 0;
        case 4:
            return 7;
        case 5:
            return 5;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The strength damage bonuses (every god bonus pair matches the strength
// bracket; Utu the (+6, +12) printed-space cell)
inline int smrAbiDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 11;
        case 2:
            return 8;
        case 3:
            return 0;
        case 4:
            return 14;
        case 5:
            return 11;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// The intelligence cells (Enki 25 the high, Enlil 25, Inanna 21, Nanna-Sin
// 24, Nin-hursag 23, Utu 20; Ki 23)
inline int smrAbiI(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 21;
        case 3:
            return 23;
        case 4:
            return 24;
        case 5:
            return 23;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// The wisdom cells (Enlil 25, Nanna-Sin 25, Ki 25; Inanna 19 the low)
inline int smrAbiW(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 24;
        case 2:
            return 19;
        case 3:
            return 25;
        case 4:
            return 25;
        case 5:
            return 23;
        case 6:
            return 22;
        default:
            return 0;
        }
    }

// The dexterity cells (Inanna 25 the high; ENLIL PRINTS D:23 - the L&L voice
// normalizes to 25, pinned by the print with the divergence noted)
inline int smrAbiD(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 23;
        case 4:
            return 19;
        case 5:
            return 23;
        case 6:
            return 22;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s: Enlil, Enki, Inanna, Ki; Utu 24; Nanna-Sin
// 23)
inline int smrAbiC(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 24;
        case 3:
            return 25;
        case 4:
            return 23;
        case 5:
            return 23;
        case 6:
            return 24;
        default:
            return 0;
        }
    }

// The charisma cells (Inanna 25, Nanna-Sin 25, Utu 25; ENLIL PRINTS CH:24 -
// the L&L voice normalizes to 25, pinned by the print; Nin-hursag the all-23
// row)
inline int smrAbiCH(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 25;
        case 4:
            return 25;
        case 5:
            return 23;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The print page cells (125 through 127, the Sumerian box of the gap report)
inline int smrRosPage(int b)
    {
        switch (b) {
        case 0:
            return 125;
        case 1:
            return 126;
        case 2:
            return 126;
        case 3:
            return 126;
        case 4:
            return 127;
        case 5:
            return 127;
        case 6:
            return 127;
        default:
            return 0;
        }
    }

// The plane cells (1 Elysium, 2 Nirvana, 3 Nine Hells, 4 Prime Material
// Plane)
inline int smrRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The alternative plane cells (none printed - all 0; the L&L Phlegethos and
// Eronia glosses are transcriber D64 additions)
inline int smrRosPlaneAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG 1 LN 2 CG 3 CN 4 N 5 NG 6 LE 7 NE 8 CE)
inline int smrRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The rank cells (1 greater, 0 lesser)
inline int smrRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The psionic class cells (I: Inanna and Ki; VI: Utu; 0 = Nil. INANNA PRINTS
// THE SINGLE PIPE - the w15 one-pipe signature, the L&L voice reads II,
// pinned by the print with the divergence noted)
inline int smrRosPsi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The printed-damage flags (Enlil, Enki, Inanna, Nanna-Sin and Utu the
// fixed-points rows; Ki the Nil and Nin-hursag the 2-20 dice print carry 0)
inline int smrRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the five rows printing an Nth-level-in-each pair: Enki,
// Inanna, Ki, Nanna-Sin, Utu)
inline int smrRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The odd worshipper-alignment prints (Inanna the warriors-and-lovers line -
// the L&L voice reads Lawful evil, pinned by the print)
inline int smrRosWorshipOdd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// ---- the R866 census ----

// the Sumerian mythos beings
inline int smrBeingCount()
    { return 7; }

// the greater gods and goddesses (Enlil, Enki, Inanna, Ki, Utu)
inline int smrGreaterCount()
    { return 5; }

// the lesser gods and goddesses (Nanna-Sin, Nin-hursag)
inline int smrLesserCount()
    { return 2; }

// the four grids
inline int smrTableCount()
    { return 4; }

// no chains this round
inline int smrChainCount()
    { return 0; }

// the combat grid rows
inline int smrCbtRows()
    { return 7; }

// the class grid rows
inline int smrClsRows()
    { return 7; }

// the ability grid rows
inline int smrAbiRows()
    { return 7; }

// the roster grid rows
inline int smrRosRows()
    { return 7; }

// the Elysium plane rows (Enlil, Nanna-Sin, Nin-hursag)
inline int smrElysiumCount()
    { return 3; }

// the Nirvana plane rows (Enki, Utu)
inline int smrNirvanaCount()
    { return 2; }

// the Nine Hells plane row (Inanna)
inline int smrNineHellsCount()
    { return 1; }

// the Prime Material Plane row (Ki)
inline int smrPrimeCount()
    { return 1; }

// the Nil psionic rows (Enlil, Enki, Nanna-Sin, Nin-hursag)
inline int smrPsiNilCount()
    { return 4; }

// the class-I psionic rows (Inanna, Ki)
inline int smrPsiICount()
    { return 2; }

// the class-VI psionic row (Utu)
inline int smrPsiVicount()
    { return 1; }

// every one of the seven beings prints armor class -2, the only such pantheon
// of the walk
inline int smrUniformAcCount()
    { return 7; }

// the in-each rows (Enki, Inanna, Ki, Nanna-Sin, Utu)
inline int smrInEachCount()
    { return 5; }

// the dual-move rows (all but Utu the Infinite)
inline int smrDualMoveCount()
    { return 6; }

// the printed fixed-damage rows (Enlil 50, Enki 35, Inanna 25, Nanna-Sin 30,
// Utu 50)
inline int smrDmgFixedCount()
    { return 5; }

// the odd worshipper-alignment print (Inanna the warriors-and-lovers line)
inline int smrWorshipOddCount()
    { return 1; }

}   // namespace rules
