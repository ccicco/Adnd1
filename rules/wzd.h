// =========================================================================================
// Adnd1 - rules/wzd.h
// The Dragon issue-17 opener part two - A Wizard With A Difference: the eight
// Ward area-wizard variants, the chance-of-making grid, the spell-list roster
// and the explanation doctrines
// census 854 -> 855.
//
// Pinned from The Dragon Vol. III No. 3 (August 1978), the Curtiss-provided
// scan voice (single voice: the issue-17 source is the uploaded Dm17.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 17). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet. The
// article prints at folios 10-13 (PDF 12-15), its list pages broken by the
// Strategists Club ballot at folio 12 and its Movement explanations riding
// folio 15 (PDF 17) alongside the R931-pinned Sights and Sounds; the cont.
// overleaf footer at folio 13 closes there. The pin IS the conversion:
// OD&D-era ink adjudicated to 1e terms, the conversion noted, never silent;
// Dragon pins ride a VARIANT layer with provenance, never core canon.
//
// Print quirks pinned AS SCANNED, noted never silent: the single-voice
// transcript garbles ride the data file and the comments, never silently
// normalized - Dispel! Magic (the Defense third-level row), Pall-wall (the
// Movement fourth-level Pass-wall), Extention, Telekenisis, Ventriliquism,
// Animate Deat, the Defense-list Etherfulness against the explanation-head
// Etherialness, the Movement explanation-head Etheriainess, Replusion Field,
// Hold Staffs in the list against Hold Staff in the explanation, the
// lowercase Fire immunity, the Movement list skipping its Fifth Level row and
// printing no ordinal for it, the Control overflow row printing without its
// level label, and the End All Barriers explanation printing twice with two
// different texts - both pinned, the dupe noted as scanned. No printed grid
// in this article carries a garbled numeric cell: the chance grid and the
// roster counts pin clean, so no table cell rides a sentinel this round.
//
namespace rules {

// ---- the chance-of-making doctrine (print 10) ----

// the chance-of-making table runs First through Eighth Level (print 10, PDF
// 12)
inline int wzdChanceLevels()
    { return 8; }

// the chance table row count, one row per spell level band (print 10)
inline int wzdChanceRows()
    { return 8; }

// the normal D&D magic user carries nine spell levels - the Ward prose frame
// (print 10)
inline int wzdNormalSpellLevels()
    { return 9; }

// the eight area wizard types: Aggression, Defense, All Things Rustic,
// Control, Tenaciousness, Detection, Fire, Movement (print 10)
inline int wzdWizardTypes()
    { return 8; }

// the area wizard picks two spells per experience level from any spell level
// on his list (print 10)
inline int wzdSpellsPerLevel()
    { return 2; }

// the working chance increases by 5 percent for every level over the first
// (print 10)
inline int wzdChanceBonusPerLevel()
    { return 5; }

// the printed legend: one star marks a spell changed to fit the area (print
// 10)
inline int wzdChangedSpellMarkStars()
    { return 1; }

// the printed legend: two stars mark a new spell (print 10)
inline int wzdNewSpellMarkStars()
    { return 2; }

// the Ward worked example: a fifth-level wizard of fire (print 10)
inline int wzdExampleWizardLevel()
    { return 5; }

// the example casts a sixth-level spell, heat ray (print 10)
inline int wzdExampleSpellLevel()
    { return 6; }

// the fifth level over the first gives a +20 percent chance in the example -
// four bands at 5 percent (print 10)
inline int wzdExampleBonusPercent()
    { return 20; }

// the sixth-level spell carries a 30 percent base chance in the example
// (print 10)
inline int wzdExampleBasePercent()
    { return 30; }

// the example roll needs 1-50 percent for the spell to work (print 10)
inline int wzdExampleRollMax()
    { return 50; }

// the example fail floor - a 51 roll and the spell does not work (print 10)
inline int wzdExampleFailMin()
    { return 51; }

// the area wizards raise levels of experience in the same manner as the D&D
// wizard (print 10)
inline bool wzdSameLevelProgression()
    { return true; }

// an area wizard studies nothing but his area and is faster in spell use than
// the normal magic user (print 10)
inline bool wzdFasterSpellUse()
    { return true; }

// the better the spell, the less chance a first-level area magic user has of
// performing it (print 10)
inline bool wzdBetterSpellLowerChance()
    { return true; }

// a failed chance roll costs the memorized spell unless more than one was
// taken (print 10)
inline bool wzdExampleSpellLostOnFail()
    { return true; }

// the ED note recommends the variants as a source of NPC bedevilment (print
// 10)
inline bool wzdEdNoteNpcBedevilment()
    { return true; }

// the spell level ordinal, 1-8 (print 10)
inline int wzdChanceLevel(int b)
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
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -1;
        }
    }

// the working percent at first caster level - the better the spell the less
// the chance (print 10)
inline int wzdChancePercent(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 85;
        case 2:
            return 75;
        case 3:
            return 50;
        case 4:
            return 40;
        case 5:
            return 30;
        case 6:
            return 20;
        case 7:
            return 10;
        default:
            return -1;
        }
    }

// ---- the roster grid and mark census (print 10-15) ----

// the spell-offer count grid rows - one per wizard type in article order:
// Aggression, Defense, Tenaciousness, Detection, Fire, Movement, All Things
// Rustic, Control (print 10-15)
inline int wzdOfferRows()
    { return 8; }

// the total spells offered across the eight lists, every level row counted
// (print 10-15)
inline int wzdTotalSpellsOffered()
    { return 206; }

// the Control list prints an unlabeled overflow row after the Eighth Level -
// Gate, Monster Summoning VI, Astral Spell, Charm Golems - three spells, the
// level ordinal never printing (print 12, PDF 14)
inline int wzdCtlOverflowCount()
    { return 3; }

// the total changed spells carrying the single star (print 10-15)
inline int wzdMarkedChanged()
    { return 22; }

// the total new spells carrying the double star (print 10-15)
inline int wzdMarkedNew()
    { return 54; }

// the Control overflow row prints without its level label - the ninth-row
// ordinal never prints, noted as scanned (print 12)
inline bool wzdCtlOverflowRowUnlabeled()
    { return true; }

// the Movement list prints no Fifth Level row - the grid cell pins 0, the row
// itself never printing (print 10, PDF 12)
inline bool wzdMovFifthLevelRowAbsent()
    { return true; }

// the spells offered at First Level (print 10-12)
inline int wzdOfferL1(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the spells offered at Second Level (print 10-12)
inline int wzdOfferL2(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the spells offered at Third Level (print 10-12)
inline int wzdOfferL3(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 7;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 8;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the spells offered at Fourth Level (print 10-12)
inline int wzdOfferL4(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 2;
        default:
            return -1;
        }
    }

// the spells offered at Fifth Level - the Movement row pins 0, no row prints
// (print 10-12)
inline int wzdOfferL5(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 8;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the spells offered at Sixth Level (print 10-12)
inline int wzdOfferL6(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// the spells offered at Seventh Level (print 10-12)
inline int wzdOfferL7(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 5;
        default:
            return -1;
        }
    }

// the spells offered at Eighth Level (print 10-12)
inline int wzdOfferL8(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 5;
        default:
            return -1;
        }
    }

// ---- the wizard of aggression (print 10-12) ----

// the changed Magic Missile: one more arrow per level of the magic user than
// the old spell (print 12, PDF 14)
inline int wzdAggMagicMissileArrowsPerLevel()
    { return 1; }

// the changed Hold Person: affects 1-6 persons instead of 1-4 (print 12)
inline int wzdAggHoldPersonMax()
    { return 6; }

// the old Hold Person ceiling, 1-4 (print 12)
inline int wzdAggHoldPersonOldMax()
    { return 4; }

// the new Magic Spear: three spears base (print 12)
inline int wzdAggMagicSpearBase()
    { return 3; }

// the Magic Spear adds one spear per four-level band (print 12)
inline int wzdAggMagicSpearPerBand()
    { return 1; }

// the Magic Spear band width: per every four levels of the caster (print 12)
inline int wzdAggMagicSpearLevelsPerBand()
    { return 4; }

// the new Dancing Magic Sword: a plus 1 sword (print 12)
inline int wzdAggDancingSwordPlus()
    { return 1; }

// the Dancing Magic Sword fights as a hero for four melee turns at the caster
// command (print 12)
inline int wzdAggDancingSwordTurns()
    { return 4; }

// the new Melt: the metal turns red hot in one melee turn (print 12)
inline int wzdAggMeltHotTurn()
    { return 1; }

// the Melt melts the metal on the next melee turn - the second turn from
// casting (print 12)
inline int wzdAggMeltMeltTurn()
    { return 2; }

// the Melt allows the magic saving throw (print 12)
inline bool wzdAggMeltMagicSaveApplicable()
    { return true; }

// the Melt affects masses of metal no greater than a set of plate mail (print
// 12)
inline bool wzdAggMeltPlateMailMassLimit()
    { return true; }

// ---- the wizard of defense (print 10-13) ----

// the changed Shield: armor class 2 for the caster (print 12, PDF 14)
inline int wzdDefShieldArmorClass()
    { return 2; }

// the changed Shield lasts five melee turns plus the level of the magic user
// (print 12)
inline int wzdDefShieldTurns()
    { return 5; }

// the changed Protection from Evil: any chaotic being takes minus one on all
// attempts to hit the caster (print 12)
inline int wzdDefProtEvilToHitPenalty()
    { return 1; }

// the changed Protection from Evil lasts six melee turns (print 12)
inline int wzdDefProtEvilTurns()
    { return 6; }

// the new Protection from Swords lasts four melee turns plus the caster level
// (print 12)
inline int wzdDefProtSwordsTurns()
    { return 4; }

// the new Repulsion Field lasts two melee turns plus the caster level (print
// 12)
inline int wzdDefRepulsionTurns()
    { return 2; }

// the new Etherialness works as the potion for three melee turns plus the
// caster level (print 12)
inline int wzdDefEtherialnessTurns()
    { return 3; }

// the new No Punctures lasts three melee turns (print 12)
inline int wzdDefNoPuncturesTurns()
    { return 3; }

// the Shield duration adds the caster level (print 12)
inline bool wzdDefShieldPlusLevel()
    { return true; }

// the Protection from Evil penalty binds chaotic beings only (print 12)
inline bool wzdDefProtEvilChaoticOnly()
    { return true; }

// the Protection from Evil 10 foot Radius does the same as the base spell,
// affecting the circle area around the caster (print 12)
inline bool wzdDefProtEvilRadiusSameAsBase()
    { return true; }

// the Protection from Swords forces the attacker to make the magic saving
// throw to hit with a sword (print 12)
inline bool wzdDefProtSwordsSaveToHit()
    { return true; }

// the Protection from Swords duration adds the caster level (print 12)
inline bool wzdDefProtSwordsPlusLevel()
    { return true; }

// the new Protection from Edged Weapons matches the sword spell for all edged
// weapons, same duration (print 12)
inline bool wzdDefProtEdgedAsSwordSpell()
    { return true; }

// the Repulsion Field duration adds the caster level (print 12)
inline bool wzdDefRepulsionPlusLevel()
    { return true; }

// the Repulsion Field stops anything of physical matter from touching the
// caster (print 12)
inline bool wzdDefRepulsionStopsPhysical()
    { return true; }

// the Etherialness duration adds the caster level (print 12)
inline bool wzdDefEtherialnessPlusLevel()
    { return true; }

// the Etherialness works as the potion of the same name (print 12)
inline bool wzdDefEtherialnessAsPotion()
    { return true; }

// the No Punctures stops any skin-breaking attack - all such wounds heal
// instantly and are not felt (print 12)
inline bool wzdDefNoPuncturesHealsInstantly()
    { return true; }

// the new Protection from All Weapons matches the sword spell, applying to
// all weapons (print 12)
inline bool wzdDefProtAllWeaponsAsSwordSpell()
    { return true; }

// ---- the wizard of all things rustic (print 10-13) ----

// the new Communicate spells - Mammals, Plants, Reptiles, Insects, Avians,
// Monsters - each allow speech for ten melee turns (print 12-13)
inline int wzdRusCommuneTurns()
    { return 10; }

// the changed Conjure Earth Elemental summons a 20 die elemental in the first
// melee turn (print 13)
inline int wzdRusEarthElementalDice()
    { return 20; }

// the new Summon Felines, Canines, Avians: the summoned animals vanish after
// one full turn or death (print 13)
inline int wzdRusSummonVanishTurns()
    { return 1; }

// the new Command as the Staff: the caster commands like a staff of
// commanding once (print 13)
inline int wzdRusCommandStaffUses()
    { return 1; }

// the changed Light gives the light of full day (print 12)
inline bool wzdRusLightFullDay()
    { return true; }

// the Reptiles, Insects, Avians and Monsters Communicate spells match the
// Mammal spell (print 13)
inline bool wzdRusCommuneReptilesAsMammals()
    { return true; }

// the conjured earth elemental thinks for itself and will not attack the
// caster on lost concentration - it simply vanishes (print 13)
inline bool wzdRusConjureElementalThinks()
    { return true; }

// the Summon Felines conjures any type of cat the caster has seen, doing
// whatever the caster dictates (print 13)
inline bool wzdRusSummonSeenTypesOnly()
    { return true; }

// the Summon Canines matches the feline spell for any type of dog (print 13)
inline bool wzdRusSummonCaninesAsFelines()
    { return true; }

// the Summon Avians matches the feline spell for any type of bird except the
// magical Roc (print 13)
inline bool wzdRusSummonAviansRocExcluded()
    { return true; }

// the new Charm Insect works on any type or size of insect (print 13)
inline bool wzdRusCharmInsectAnyTypeSize()
    { return true; }

// the Charm Snake and Charm Mammal match the charm insect spell for snakes
// and mammals (print 13)
inline bool wzdRusCharmSnakeMammalAsInsect()
    { return true; }

// the Insect Plague in the list works as the cleric spell (print 13)
inline bool wzdRusInsectPlagueAsCleric()
    { return true; }

// ---- the wizard of control (print 10-12) ----

// the changed Sleep affects two beings with five dice (print 12, PDF 14)
inline int wzdCtlSleepTwoBeings()
    { return 2; }

// the five-dice Sleep share for two beings (print 12)
inline int wzdCtlSleepFiveDice()
    { return 5; }

// the changed Sleep affects one being with six dice (print 12)
inline int wzdCtlSleepOneBeing()
    { return 1; }

// the six-dice Sleep draw for one being (print 12)
inline int wzdCtlSleepSixDice()
    { return 6; }

// the new Charm Golems gives any golem the saving throw of a 14th level
// wizard (print 12)
inline int wzdCtlGolemSaveLevel()
    { return 14; }

// the new Control as the Staff: the caster commands like a staff of
// commanding once (print 12)
inline int wzdCtlStaffUses()
    { return 1; }

// the Charm Golems cuts through the magic protection of any given golem and
// allows a control attempt (print 12)
inline bool wzdCtlGolemCutsProtection()
    { return true; }

// the changed Sleep is the normal spell otherwise, adding only the
// two-beings-five-dice and one-being-six-dice draws (print 12)
inline bool wzdCtlSleepNormalOtherwise()
    { return true; }

// ---- the wizard of tenaciousness (print 10-13) ----

// the changed Wizard Lock: only 2 dispel magics break its power (print 13,
// PDF 15)
inline int wzdTenWizardLockDispels()
    { return 2; }

// the Hold Swords and Hold Crossbows radius: 60 yards around the caster
// (print 13)
inline int wzdTenHoldRadiusYards()
    { return 60; }

// the Hold Swords duration floor, 2-20 melee turns (print 13)
inline int wzdTenHoldSwordsTurnsMin()
    { return 2; }

// the Hold Swords duration ceiling, 2-20 melee turns (print 13)
inline int wzdTenHoldSwordsTurnsMax()
    { return 20; }

// the Hold Staff duration floor, 3-30 melee turns (print 13)
inline int wzdTenHoldStaffTurnsMin()
    { return 3; }

// the Hold Staff duration ceiling, 3-30 melee turns (print 13)
inline int wzdTenHoldStaffTurnsMax()
    { return 30; }

// the Hold Monster duration floor, 1-10 melee turns (print 13)
inline int wzdTenHoldMonsterTurnsMin()
    { return 1; }

// the Hold Monster duration ceiling, 1-10 melee turns (print 13)
inline int wzdTenHoldMonsterTurnsMax()
    { return 10; }

// the Stop Magic radius: 30 yards around the caster (print 13)
inline int wzdTenStopMagicRadiusYards()
    { return 30; }

// the Stop Magic lasts 6 melee turns (print 13)
inline int wzdTenStopMagicTurns()
    { return 6; }

// the Hold Groups holds any enemy group of less than 12 beings (print 13)
inline int wzdTenHoldGroupsMaxBeings()
    { return 12; }

// the Hold Openings area: less than 40 feet tall (print 13)
inline int wzdTenOpeningsHeightFeet()
    { return 40; }

// the Hold Openings area: 30 feet wide (print 13)
inline int wzdTenOpeningsWidthFeet()
    { return 30; }

// the Hold Openings force field lasts 24 hours (print 13)
inline int wzdTenOpeningsHours()
    { return 24; }

// the Wizard Lock Openings covers the same area but lasts only one hour
// (print 13)
inline int wzdTenLockOpeningsHours()
    { return 1; }

// the changed Hold Portal works like a wizard lock for this wizard (print 13)
inline bool wzdTenHoldPortalAsWizardLock()
    { return true; }

// the changed Wizard Lock falls to the normal knock spell but needs both
// dispel magics (print 13)
inline bool wzdTenWizardLockKnockWorks()
    { return true; }

// the changed Knock opens any locked, fastened or blocked thing - a passage
// filled with rubble and the like (print 13)
inline bool wzdTenKnockOpensBlocked()
    { return true; }

// the Hold Swords holds any sword in its scabbard that has not been drawn at
// the casting (print 13)
inline bool wzdTenHoldSwordsUndrawnOnly()
    { return true; }

// the Hold Crossbows blocks the shaft only as long as the caster concentrates
// (print 13)
inline bool wzdTenHoldCrossbowsWhileConcentrating()
    { return true; }

// the Hold Monster works unless the monster makes its magic saving throw - it
// stops special powers like troll regeneration and dragon breath (print 13)
inline bool wzdTenHoldMonsterSaveStops()
    { return true; }

// the Stop Magic binds only enemies failing the magic saving throw (print 13)
inline bool wzdTenStopMagicSaveStops()
    { return true; }

// the Hold Groups holds even when creatures and humans are intermixed, each
// being saving individually (print 13)
inline bool wzdTenHoldGroupsMixed()
    { return true; }

// the Hold Openings needs no concentration once up - the caster may leave the
// area (print 13)
inline bool wzdTenOpeningsCasterMayLeave()
    { return true; }

// the Hold Openings field takes damage like a human with the caster hit point
// count (print 13)
inline bool wzdTenOpeningsTakesDamage()
    { return true; }

// the Wizard Lock Openings falls only to a dispel magic - nothing else gets
// through it or hurts it (print 13)
inline bool wzdTenLockOpeningsDispelOnly()
    { return true; }

// the End Arcane Walls dissolves all magically created walls - stone, fire,
// ice and the like (print 13)
inline bool wzdTenEndArcaneAllMagicalWalls()
    { return true; }

// the Hold a Cube of Force and Hold Wands run 2-20 melee turns, the Hold
// Rings 3-30 - the two duration families of the list (print 13)
inline bool wzdTenHoldCubeRingsWandsDurations()
    { return true; }

// ---- the wizard of detection (print 10-13) ----

// the changed Find Traps lasts 1-4 melee turns plus the caster level, as the
// wand of the same name (print 13, PDF 15)
inline int wzdDetFindTrapsTurnsMin()
    { return 1; }

// the Find Traps duration ceiling, 1-4 melee turns (print 13)
inline int wzdDetFindTrapsTurnsMax()
    { return 4; }

// the new End Surprise warns for 1-6 melee turns plus the caster level (print
// 13)
inline int wzdDetEndSurpriseTurnsMin()
    { return 1; }

// the End Surprise duration ceiling, 1-6 melee turns (print 13)
inline int wzdDetEndSurpriseTurnsMax()
    { return 6; }

// the new Reveal the Way lasts 24 hours (print 13)
inline int wzdDetRevealHours()
    { return 24; }

// the new Divine Any Object lasts 24 hours with no range limitation (print
// 13)
inline int wzdDetDivineHours()
    { return 24; }

// the new Transport to the Spot carries the caster and 1-6 other beings
// (print 13)
inline int wzdDetTransportBeingsMin()
    { return 1; }

// the Transport to the Spot beings ceiling, 1-6 (print 13)
inline int wzdDetTransportBeingsMax()
    { return 6; }

// the transported beings must be within 20 feet of the caster (print 13)
inline int wzdDetTransportRangeFeet()
    { return 20; }

// the caster must have studied the target thing for over 6 hours (print 13)
inline int wzdDetStudyHours()
    { return 6; }

// the Find Traps duration adds the caster level (print 13)
inline bool wzdDetFindTrapsPlusLevel()
    { return true; }

// the changed Find Secret Doors matches the trap spell for secret doors
// (print 13)
inline bool wzdDetFindSecretDoorsAsTraps()
    { return true; }

// the End Surprise duration adds the caster level (print 13)
inline bool wzdDetEndSurprisePlusLevel()
    { return true; }

// the changed Find the Path works as the cleric spell (print 13)
inline bool wzdDetFindPathAsCleric()
    { return true; }

// the Reveal the Way makes the actual footsteps or claw steps of the fleeing
// being glow before the caster (print 13)
inline bool wzdDetRevealFootstepsGlow()
    { return true; }

// the Reveal the Way glows the flight path when the quarry flew away (print
// 13)
inline bool wzdDetRevealFlightPathGlow()
    { return true; }

// the Divine Any Object uses a willow wand to feel the way to the known
// object or being (print 13)
inline bool wzdDetDivineWillowWand()
    { return true; }

// the Transport to the Spot needs the caster to know exactly what is
// transported near - studied, mentally projected, transported safely (print
// 13)
inline bool wzdDetTransportMustStudy()
    { return true; }

// ---- the wizard of fire (print 10-13) ----

// the changed Fire Ball adds plus 1 point to every die (print 13, PDF 15)
inline int wzdFireBallBonusPerDie()
    { return 1; }

// the changed Wall of Fire is a 10 die wall (print 13)
inline int wzdFireWallDice()
    { return 10; }

// the Wall of Fire stays 1-4 melee turns after the caster stops thinking
// (print 13)
inline int wzdFireWallTurnsMin()
    { return 1; }

// the Wall of Fire persistence ceiling, 1-4 melee turns (print 13)
inline int wzdFireWallTurnsMax()
    { return 4; }

// the changed Conjure Fire Elemental summons a 20 die elemental in the first
// melee turn (print 13)
inline int wzdFireElementalDice()
    { return 20; }

// the changed Fire Resistance grants immunity to all fire damage for 1-10
// melee turns (print 13)
inline int wzdFireResistTurnsMin()
    { return 1; }

// the Fire Resistance duration ceiling, 1-10 melee turns (print 13)
inline int wzdFireResistTurnsMax()
    { return 10; }

// the new Heat Ray causes 10 dice of heat damage (print 13)
inline int wzdFireHeatRayDice()
    { return 10; }

// the Heat Ray delivers its damage in 1 melee turn (print 13)
inline int wzdFireHeatRayTurns()
    { return 1; }

// the new Fire Immunity covers all beings in a 10 yard radius about the
// caster (print 13)
inline int wzdFireImmunityRadiusYards()
    { return 10; }

// the Fire Immunity lasts 1-10 melee turns (print 13)
inline int wzdFireImmunityTurnsMin()
    { return 1; }

// the Fire Immunity duration ceiling, 1-10 melee turns (print 13)
inline int wzdFireImmunityTurnsMax()
    { return 10; }

// the new Combustion of All Things burns for 1-6 melee turns (print 13)
inline int wzdFireCombustTurnsMin()
    { return 1; }

// the Combustion duration ceiling, 1-6 melee turns (print 13)
inline int wzdFireCombustTurnsMax()
    { return 6; }

// the Combustion does 5 dice of damage every turn (print 13)
inline int wzdFireCombustDicePerTurn()
    { return 5; }

// the new Fire Vision lasts 5-50 melee turns (print 13)
inline int wzdFireVisionTurnsMin()
    { return 5; }

// the Fire Vision duration ceiling, 5-50 melee turns (print 13)
inline int wzdFireVisionTurnsMax()
    { return 50; }

// the fire wizard is never affected by his own fire ball (print 13)
inline bool wzdFireBallNeverAffectsCaster()
    { return true; }

// the fire wizard equipment is however affected by his own fire ball (print
// 13)
inline bool wzdFireBallEquipmentNotProtected()
    { return true; }

// the changed Phantasmal Force Fire Illusions makes only illusions dealing
// with fire (print 13)
inline bool wzdFireIllusionsFireOnly()
    { return true; }

// the new Fire Negation destroys any fire the caster comes in contact with,
// lasting 2-20 melee turns (print 13)
inline bool wzdFireNegationDestroysContactedFire()
    { return true; }

// the new Control of Fire throws directed fire spells back at the thrower
// when the caster makes the magic saving throw, lasting 2-20 melee turns
// (print 13)
inline bool wzdFireControlRedirectOnSave()
    { return true; }

// the conjured fire elemental thinks for itself and vanishes on lost
// concentration rather than attacking the caster (print 13)
inline bool wzdFireConjureElementalThinks()
    { return true; }

// the new Body of Fire turns the caster into an inferno for the number of
// dice or hit points he has, lasting 2-20 melee turns (print 13)
inline bool wzdFireBodyInfernoCasterDice()
    { return true; }

// the Heat Ray damages any creature, even a fire type creature (print 13)
inline bool wzdFireHeatRayHitsFireTypes()
    { return true; }

// the Fire Immunity covers all beings in the radius, not the caster alone
// (print 13)
inline bool wzdFireImmunityAllBeingsInRadius()
    { return true; }

// the Fire Vision sees into any area with a lit fire (print 13)
inline bool wzdFireVisionNeedsLitFire()
    { return true; }

// ---- the wizard of movement (print 10-15) ----

// the new Water Travel: walk on water for up to 5 full turns (print 15, PDF
// 17)
inline int wzdMovWaterTravelTurns()
    { return 5; }

// the new Negate the Ability to Fly: the fly muscles paralyzed 1-5 melee
// turns (print 15)
inline int wzdMovNegateFlyTurnsMin()
    { return 1; }

// the Negate Fly ceiling, 1-5 melee turns (print 15)
inline int wzdMovNegateFlyTurnsMax()
    { return 5; }

// the new Negate the Ability to Move on or in the Water lasts 1-6 melee turns
// (print 15)
inline int wzdMovNegateWaterTurnsMin()
    { return 1; }

// the Negate Water ceiling, 1-6 melee turns (print 15)
inline int wzdMovNegateWaterTurnsMax()
    { return 6; }

// the new Mass Teleport transports a maximum of 20 beings plus the caster
// (print 15)
inline int wzdMovMassTeleportBeings()
    { return 20; }

// the changed Etherialness works as the potion for three melee turns plus the
// caster level (print 15)
inline int wzdMovEtherialnessTurns()
    { return 3; }

// the new End All Barriers makes a single barrier vanish for 1-10 melee turns
// (print 15)
inline int wzdMovEndBarrierTurnsMin()
    { return 1; }

// the End All Barriers ceiling, 1-10 melee turns (print 15)
inline int wzdMovEndBarrierTurnsMax()
    { return 10; }

// the new Negate the Ability to Run from a Fight forces the fleeing being, on
// a failed magic save, to run toward the very creature it sought to flee
// (print 15)
inline bool wzdMovNegateRunTowardFled()
    { return true; }

// the Mass Teleport acts in all other respects as the teleport spell, to the
// area the caster mentally envisions (print 15)
inline bool wzdMovMassTeleportAsTeleport()
    { return true; }

// the Movement Etherialness duration adds the caster level (print 15)
inline bool wzdMovEtherialnessPlusLevel()
    { return true; }

// the End All Barriers explanation prints TWICE with two different texts -
// the vanish-for-1-10 reading and the giant-disintegrate reading, both
// pinned, the dupe noted as scanned (print 15)
inline bool wzdMovEndBarrierPrintedTwice()
    { return true; }

// the second End All Barriers text reads as a giant disintegrate that
// unblocks anything stopping the wizard of movement (print 15)
inline bool wzdMovEndBarrierGiantDisintegrate()
    { return true; }

// the changed Safe Teleport matches the normal teleport except the caster
// never comes high or low on the target (print 15)
inline bool wzdMovSafeTeleportNoHighLow()
    { return true; }

// the Water Travel allows the user or the being the caster casts it on to
// walk on water (print 15)
inline bool wzdMovWaterTravelCastOnOthers()
    { return true; }

}   // namespace rules
