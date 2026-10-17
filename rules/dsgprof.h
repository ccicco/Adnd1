// =========================================================================================
// Adnd1 - rules/dsgprof.h
// The DSG NONWEAPON PROFICIENCIES, R506: the printed pp. 23-29 (pdf 24-30) -
// the Proficiency Check system (the Ability Check frame with the listed
// die-roll modifiers, the improving +2 per additional slot, the quality
// ladder from success to the natural-20 flawless creation and the 110-200
// percent pricing), the slot economy (the weapon-slot-buys-nonweapon one-way
// trade, the filled-slot immutability, the Secondary Skills conversion), the
// artisan ladder for NPCs, the optional DM bonuses, the fourteen craftsman
// descriptions, the fifteen adventuring descriptions and the
// XP-for-proficiencies option, with Table 10 (the 14 class rows), Table 11
// (the 14 craftsman rows), Table 12 (the 11 weapon-making rows) and Table 13
// (the 15 adventuring rows).
// census 430 -> 431.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the grids read from the IA djvu OCR at 300dpi coordinates
// with the pdf Acrobat-Capture layer as the second read; the Weaver and
// Weaponsmith cells and the trainer/armorer slot cells carry the grids-file
// image cautions and are pinned as printed (the R501 precedent); the
// cross-book seam verified const-for-const against rules/wsgprof.h (R425) and
// rules/wsgprofd.h (R498) - NOTHING auto-credited; Table 10 agrees
// cell-for-cell with the WSG Table 1 pins, the shared Table 13 rows are
// SUBSTANTIALLY rebalanced (10 of 11 diverge), the shared description numbers
// agree whole.
//
// The DSG Table 10/11/13 sign convention is the die-roll convention (negative
// easier), matching the WSG tables; the p. 23 prose example (+3 makes 12
// equal 15) is the ability-score framing of the same modifiers. NA cells:
// ability 0, modifier 99, the bard as-other-classes row -1, the arrowhead
// per-day row -1.
//
namespace rules {

// ---- the check system and the slot economy ----

// the Proficiency Check is made exactly like an Ability Check.
inline bool dnpCheckLikeAbilityCheck()
    { return true; }

// the player rolls 1d20 and compares the result to the ability score.
inline int dnpCheckDieSides()
    { return 20; }

// a die-roll modifier example: a +3 modifier.
inline int dnpCheckModifierExampleMod()
    { return 3; }

// a d20 roll of 12 with the +3 modifier.
inline int dnpCheckModifierExampleRoll()
    { return 12; }

// the 12 roll with +3 is equal to a 15 for success.
inline int dnpCheckModifierExampleEq()
    { return 15; }

// improving a proficiency with an additional slot increases its modifier by
// 2.
inline int dnpImprovedStepPlus()
    { return 2; }

// the improving example: a miner proficiency modifier of -1.
inline int dnpImprovedExampleFrom()
    { return -1; }

// one additional slot raises the -1 miner modifier to +1.
inline int dnpImprovedExampleTo()
    { return 1; }

// the exact amount of success determines the degree of workmanship.
inline bool dnpSuccessDegreeQuality()
    { return true; }

// a 20 equals a nearly flawless creation.
inline bool dnpNatural20Flawless()
    { return true; }

// quality products sell from 110 percent of the normal price.
inline int dnpProductPriceLoPct()
    { return 110; }

// quality products sell up to 200 percent of the normal price.
inline int dnpProductPriceHiPct()
    { return 200; }

// under normal conditions there is no chance of failure for most proficiency
// uses.
inline bool dnpMostUsesNoFailure()
    { return true; }

// characters are not required to fill all of their proficiency slots.
inline bool dnpSlotsNeedNotBeFilled()
    { return true; }

// unfilled slots are saved and can be used at a later time.
inline bool dnpUnfilledSlotSaved()
    { return true; }

// once a slot is filled it cannot be changed for any reason.
inline bool dnpFilledSlotCannotChange()
    { return true; }

// a weapon slot can be used for a nonweapon proficiency instead.
inline bool dnpWeaponSlotHoldsNonweapon()
    { return true; }

// the reverse is not allowed: a nonweapon slot cannot buy a weapon
// proficiency.
inline bool dnpNonweaponSlotHoldsWeapon()
    { return false; }

// converting Secondary Skills takes one slot per one or two skills (low).
inline int dnpSecondarySkillsPerSlotLo()
    { return 1; }

// converting Secondary Skills takes one slot per one or two skills (high).
inline int dnpSecondarySkillsPerSlotHi()
    { return 2; }

// the listed proficiency time assumes the character devotes his entire
// working day.
inline bool dnpTimeAssumesFullDay()
    { return true; }

// time out to hunt, fight or yield to distractions increases the required
// time.
inline bool dnpDistractionIncreasesTime()
    { return true; }

// ---- artisans craftsmen and other NPCs ----

// an NPC who claims no weapon proficiency gets two nonweapon slots after
// apprenticeship training.
inline int dnpNpcNoWeaponYieldsNonweapon()
    { return 2; }

// after one year of journeyman practice (low).
inline int dnpJourneymanYearsLo()
    { return 1; }

// after up to four years of journeyman practice the character advances to
// master.
inline int dnpJourneymanYearsHi()
    { return 4; }

// the new master is granted one additional proficiency slot.
inline int dnpMasterArrivalSlot()
    { return 1; }

// every four years of work thereafter gains one additional slot.
inline int dnpMasterYearsPerSlot()
    { return 4; }

// the DM may modify and expand the nonweapon proficiency rules.
inline bool dnpOptionalBonusesAllowed()
    { return true; }

// improved nonmagical armor from strong metal: +1 (low).
inline int dnpOptionalArmorPlusLo()
    { return 1; }

// improved nonmagical armor from strong metal: +2 (high).
inline int dnpOptionalArmorPlusHi()
    { return 2; }

// the DM can rule a youth apprenticeship grants automatic proficiency in the
// skill.
inline bool dnpBackgroundAutoProficiency()
    { return true; }

// ---- the Table 10 class grid ----

// The Table 10 census: 14 class rows.
inline int dnpT10RowCount()
    { return 14; }

// 0th-level horsemen and lancers have one nonweapon proficiency.
inline bool dnpHorsemanHasOneNonweapon()
    { return true; }

// the bard Table 10 row reads as other classes (the -1 sentinel).
inline bool dnpBardAsOtherClasses()
    { return true; }

// The initial weapon proficiencies by class row: cavalier 3, paladin 3,
// cleric 2, druid 2, fighter 4, barbarian 6, ranger 3, magic-user 1,
// illusionist 1, thief 2, acrobat 2, assassin 3, monk 1, bard
// as-other-classes (-1).
inline int dnpT10InitialWeapon(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return -1;
        default:
            return -1;
        }
    }

// The initial nonweapon proficiencies: cavalier 2, paladin 2, cleric 3, druid
// 3, fighter 2, barbarian 3, ranger 2, magic-user 3, illusionist 3, thief 3,
// acrobat 3, assassin 2, monk 1, bard -1.
inline int dnpT10InitialNonweapon(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return -1;
        default:
            return -1;
        }
    }

// The weapon proficiency slots added per interval: 1 for every class.
inline int dnpT10AddWeapon(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return -1;
        }
    }

// The nonweapon slots added per interval: 1 for every class except magic-user
// and illusionist at 2.
inline int dnpT10AddNonweapon(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return -1;
        }
    }

// The levels per added proficiency: cavalier 2, paladin 2, cleric 4, druid 5,
// fighter 3, barbarian 2, ranger 3, magic-user 6, illusionist 6, thief 4,
// acrobat 4, assassin 4, monk 2, bard 4.
inline int dnpT10EveryLevels(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 4;
        default:
            return -1;
        }
    }

// ---- the craftsman proficiencies ----

// The Table 11 census: 14 craftsman rows.
inline int dnpT11RowCount()
    { return 14; }

// The Table 12 census: 11 weapon rows.
inline int dnpT12RowCount()
    { return 11; }

// The Table 13 census: 15 adventuring rows.
inline int dnpT13RowCount()
    { return 15; }

// The slots required: trainer 1, armorer 1, blacksmith 1, boatwright 1,
// bowyer/fletcher 1, carpenter 1, gem cutter 2, leatherworker 1, miner 2,
// potter 1, smelter 1, stonemason 1, weaponsmith 3, weaver 4 (the weaver and
// weaponsmith cells carry the grids-file image cautions).
inline int dnpT11Slots(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 4;
        default:
            return 0;
        }
    }

// The appropriate ability codes: 1 Wisdom, 2 Intelligence, 3 Dexterity, 4
// Strength.
inline int dnpT11Ability(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 2;
        default:
            return 0;
        }
    }

// The die-roll modifier: armorer +2, blacksmith 0, boatwright -2,
// bowyer/fletcher -1, carpenter 0, gem cutter +2, leatherworker 0, miner -3,
// potter -2, smelter -2, stonemason -2, trainer 0, weaponsmith +3, weaver +4
// (caution class as the slots column).
inline int dnpT11Modifier(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return -2;
        case 4:
            return -1;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return -3;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return -2;
        case 12:
            return 3;
        case 13:
            return 4;
        default:
            return 0;
        }
    }

// The asterisk flag: rows requiring a d20 roll for success each time used:
// animal trainer, bowyer/fletcher, miner, weaponsmith.
inline int dnpT11EveryUse(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// training an animal for a typical role requires three months.
inline int dnpTrainerRoleMonths()
    { return 3; }

// an animal trainer can have up to six animals in training at a given time.
inline int dnpTrainerMaxAnimals()
    { return 6; }

// typical training grants a +10 modifier to the trainer check at the end of
// the period.
inline int dnpTrainerEndMod()
    { return 10; }

// additional training to add functions requires another three months.
inline int dnpTrainerAdvancedMonths()
    { return 3; }

// no more than three animals during additional training.
inline int dnpTrainerAdvancedMax()
    { return 3; }

// the trainer must declare the creature type when the proficiency is first
// gained.
inline bool dnpTrainerDeclaresSpecies()
    { return true; }

// armor takes two weeks of work per level of AC below 10.
inline int dnpArmorWeeksPerACPoint()
    { return 2; }

// a shield (one AC point below 10) requires two weeks.
inline int dnpArmorShieldWeeks()
    { return 2; }

// a suit of full plate (nine AC points below 10) requires 18 weeks.
inline int dnpArmorFullPlateWeeks()
    { return 18; }

// a failed check within four of the needed amount creates usable but flawed
// armor.
inline int dnpArmorFlawedWithin()
    { return 4; }

// flawed armor functions as one Armor Class worse than usual.
inline int dnpArmorFlawedACWorse()
    { return 1; }

// flawed armor struck in melee breaks on a natural 19.
inline int dnpArmorBreaksOnLo()
    { return 19; }

// flawed armor struck in melee breaks on a natural 20.
inline int dnpArmorBreaksOnHi()
    { return 20; }

// broken armor drops the AC immediately by four classes.
inline int dnpArmorBreakACDrop()
    { return 4; }

// the broken-armor AC drop never takes the AC above 10.
inline int dnpArmorBreakACCap()
    { return 10; }

// removing broken armor requires 1d4 rounds.
inline int dnpArmorRemoveRoundsDie()
    { return 4; }

// in broken armor the character moves at 1/2 rate (numerator).
inline int dnpArmorBrokenMoveNum()
    { return 1; }

// in broken armor the character moves at 1/2 rate (denominator).
inline int dnpArmorBrokenMoveDen()
    { return 2; }

// in broken armor the character suffers -4 on all attack rolls.
inline int dnpArmorBrokenAttackMod()
    { return -4; }

// only a character with armorer proficiency can detect the flaws, on careful
// inspection.
inline bool dnpArmorFlawsArmorerDetects()
    { return true; }

// field or full plate requires the wearer present at least once a week for
// exact fittings.
inline bool dnpArmorPlateFittingsWeekly()
    { return true; }

// blacksmithing requires a forge with a coal-fed fire and bellows, a hammer
// and an anvil.
inline bool dnpBlacksmithNeedsForge()
    { return true; }

// a blacksmith cannot make armor or sharp weapons, only hammers, maces and
// iron objects.
inline bool dnpBlacksmithNoSharpWeapons()
    { return true; }

// the boatwright can build watercraft up to 60 feet long.
inline int dnpBoatMaxLenFt()
    { return 60; }

// a boat requires one week of construction time per foot of length.
inline int dnpBoatWeeksPerFoot()
    { return 1; }

// a maximum of one boatwright per five-foot length can work simultaneously.
inline int dnpBoatCrewPerFtDen()
    { return 5; }

// a cabin or sealed hold adds about a week apiece.
inline int dnpBoatFeatureWeeks()
    { return 1; }

// two unskilled helpers equal the time savings of one additional skilled
// boatwright.
inline int dnpBoatUnskilledPerSkilled()
    { return 2; }

// vessels larger than 60 feet require shipbuilding, outside underground
// exploration.
inline bool dnpBoatLargerNeedsShipwright()
    { return true; }

// a long or short bow takes one week of construction.
inline int dnpBowWeeks()
    { return 1; }

// a composite bow takes two weeks.
inline int dnpCompositeBowWeeks()
    { return 2; }

// 1d6 arrows can be made in one day.
inline int dnpArrowsPerDayDie()
    { return 6; }

// a natural 20 on the bow check increases the range by +2 inches for all
// range classes.
inline int dnpFineBowRangeBonusIn()
    { return 2; }

// a failed bow breaks when the character using it rolls an unmodified 1 on a
// d20 attack.
inline int dnpBowBreaksOnAttack()
    { return 1; }

// a failed arrow breaks on the first shot.
inline bool dnpBowFailArrowFirstShot()
    { return true; }

// a failed bow has a limited lifespan and breaks on the unmodified 1.
inline bool dnpBowFailBowBreaks()
    { return true; }

// the fine-quality option: any failure means the weapon is worthless.
inline bool dnpBowFineFailWorthless()
    { return true; }

// the fine-quality bow inflicts +1 damage on all successful attacks.
inline int dnpBowFineDamageBonus()
    { return 1; }

// a natural 20 on the fine-quality check adds +1 to all attack rolls.
inline int dnpBowFineNat20AttackBonus()
    { return 1; }

// a weaponsmith is required to fashion arrowheads; the bowyer does the rest.
inline bool dnpBowyerNeedsWeaponsmithHeads()
    { return true; }

// a single carpenter builds a wooden object the size of a 10-foot cube.
inline int dnpCarpenterCubeFt()
    { return 10; }

// the 10-foot cube takes one week.
inline int dnpCarpenterWeeksPerCube()
    { return 1; }

// seven characters (only one a carpenter) build the 10-foot cube in a day.
inline int dnpCarpenterCrewForDaily()
    { return 7; }

// one carpenter is needed for every nine non-carpenter workers.
inline int dnpCarpenterPerWorkers()
    { return 9; }

// a gem cutter finishes rough gems at 1d10 stones per day.
inline int dnpGemStonesPerDayDie()
    { return 10; }

// a gem cutter derives no benefit from nonproficient assistance.
inline bool dnpGemCutterNoAssist()
    { return true; }

// the gem cutter needs a good light source, chisels, small hammers and
// hardened blades.
inline bool dnpGemCutterNeedsLightTools()
    { return true; }

// the leatherworker makes leather armor, clothing, backpacks, saddlebags,
// saddles and harnesses.
inline bool dnpLeatherMakesArmor()
    { return true; }

// the miner proficiency is needed to find a mine site and supervise its
// operations.
inline bool dnpMinerFindsAndSupervises()
    { return true; }

// a potter creates two small or medium items per day.
inline int dnpPotterSmallMedPerDay()
    { return 2; }

// or one large item per day.
inline int dnpPotterLargePerDay()
    { return 1; }

// the pottery must then fire in the kiln an additional day.
inline int dnpPotterKilnDays()
    { return 1; }

// raw materials cost 3 cp for a small item.
inline int dnpPotterSmallCostCp()
    { return 3; }

// raw materials cost 5 cp for a medium item.
inline int dnpPotterMediumCostCp()
    { return 5; }

// raw materials cost 1 sp (10 cp) for a large item.
inline int dnpPotterLargeCostCp()
    { return 10; }

// a small smelter processes ore as fast as four miners produce it.
inline int dnpSmeltSmallMiners()
    { return 4; }

// a medium smelter processes the ore of up to 20 miners.
inline int dnpSmeltMediumMiners()
    { return 20; }

// a large smelter processes the ore of up to 100 miners.
inline int dnpSmeltLargeMiners()
    { return 100; }

// a small smelting operation costs 5 gp per day to run.
inline int dnpSmeltSmallGpPerDay()
    { return 5; }

// a medium smelting operation costs 12 gp per day.
inline int dnpSmeltMediumGpPerDay()
    { return 12; }

// a large smelting operation costs 25 gp a day.
inline int dnpSmeltLargeGpPerDay()
    { return 25; }

// the smelter only costs money when operating.
inline bool dnpSmeltCostsOnlyOperating()
    { return true; }

// ore is stockpiled and then smelted at maximum efficiency.
inline bool dnpSmeltStockpilePractice()
    { return true; }

// a stonemason builds a wall section one foot thick.
inline int dnpMasonWallThickFt()
    { return 1; }

// the wall section is 10 feet long.
inline int dnpMasonWallLongFt()
    { return 10; }

// the wall section is five feet high, in a day.
inline int dnpMasonWallHighFt()
    { return 5; }

// the stones are often but not always mortared together.
inline bool dnpMasonOftenMortared()
    { return true; }

// a weaver creates two square yards of material per day.
inline int dnpWeaveSqYardsPerDay()
    { return 2; }

// the weaver requires a spinning apparatus and a loom, working wool or
// cotton.
inline bool dnpWeaverNeedsLoom()
    { return true; }

// the weaponsmith fine-quality option: any failure means the weapon is
// worthless.
inline bool dnpWeaponsmithFineFailWorthless()
    { return true; }

// the fine-quality weapon inflicts +1 damage on all successful attacks.
inline int dnpWeaponsmithFineDamageBonus()
    { return 1; }

// a natural 20 on the fine-quality check adds +1 to all attack rolls.
inline int dnpWeaponsmithNat20AttackBonus()
    { return 1; }

// unlisted weapons are estimated by comparison to the listed ones.
inline bool dnpWeaponsmithEstimateByComparison()
    { return true; }

// ---- the Table 12 weapon making ----

// the arrowhead rate: 1-2 arrowheads per day (low).
inline int dnpArrowheadsPerDayLo()
    { return 1; }

// the arrowhead rate: 1-2 arrowheads per day (high).
inline int dnpArrowheadsPerDayHi()
    { return 2; }

// The construction time in days: arrowhead is the -1 sentinel (1-2 per day,
// see the consts), battle axe 10, hand axe 5, dagger 5, heavy crossbow 20,
// light crossbow 15, fork/trident 20, spear/lance 4, shortsword 20, longsword
// 30, two-handed sword 45.
inline int dnpT12Days(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 20;
        case 5:
            return 15;
        case 6:
            return 20;
        case 7:
            return 4;
        case 8:
            return 20;
        case 9:
            return 30;
        case 10:
            return 45;
        default:
            return -1;
        }
    }

// The material cost in copper pieces (the printed 10 sp = 100 cp, 2 gp = 200
// cp): arrowhead 1, battle axe 100, hand axe 50, dagger 20, heavy crossbow
// 100, light crossbow 50, fork/trident 100, spear/lance 40, shortsword 50,
// longsword 100, two-handed sword 200.
inline int dnpT12CostCp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 100;
        case 2:
            return 50;
        case 3:
            return 20;
        case 4:
            return 100;
        case 5:
            return 50;
        case 6:
            return 100;
        case 7:
            return 40;
        case 8:
            return 50;
        case 9:
            return 100;
        case 10:
            return 200;
        default:
            return -1;
        }
    }

// ---- the adventuring proficiencies ----

// The slots required: animal noise 1, blind-fighting 1, boating 1, direction
// sense 1, endurance 2, fire-building 1, fishing 1, fungus identification 1,
// healing 2, mountaineering 1, riding 1, rope use 1, slow respiration 1,
// sound analysis 1, swimming 1.
inline int dnpT13Slots(int b)
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
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 99;
        }
    }

// The appropriate ability codes: 1 Wisdom, 2 Intelligence, 3 Dexterity, 5
// Strength, 0 NA - blind-fighting, endurance, mountaineering and slow
// respiration are NA.
inline int dnpT13Ability(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 5;
        default:
            return 99;
        }
    }

// The die-roll modifier, 99 = NA: animal noise -1, blind-fighting NA, boating
// +1, direction sense +1, endurance NA, fire-building -1, fishing -1, fungus
// identification +6, healing +2, mountaineering NA, riding +3, rope use 0,
// slow respiration NA, sound analysis -1, swimming 0.
inline int dnpT13Modifier(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 99;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 99;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 99;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 99;
        case 13:
            return -1;
        case 14:
            return 0;
        default:
            return 99;
        }
    }

// The asterisk flag: direction sense, fishing and healing require a d20 roll
// each time used.
inline int dnpT13EveryUse(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 99;
        }
    }

// a successful check: only magical means distinguish the noise from the real
// animal.
inline bool dnpAnimalNoiseMagicOnly()
    { return true; }

// creatures very familiar with the real noise know a failed imitation
// automatically.
inline bool dnpAnimalNoiseFamiliarAuto()
    { return true; }

// other listeners get Wisdom Checks to detect the failed fake.
inline bool dnpAnimalNoiseOthersWisdomCheck()
    { return true; }

// blind-fighting suffers only -2 on attack and damage rolls and saving
// throws.
inline int dnpBlindAttackMod()
    { return -2; }

// the standard darkness penalty blind-fighting replaces is -4.
inline int dnpBlindStandardMod()
    { return -4; }

// blind-fighting characters suffer no penalties to Armor Class from darkness.
inline bool dnpBlindNoACPenalty()
    { return true; }

// special abilities are retained: a thief can backstab and a ranger keeps
// giant-class damage in the dark.
inline bool dnpBlindRetainsSpecials()
    { return true; }

// the chance of stumbling over a drop-off or falling from a sheer surface is
// halved.
inline bool dnpBlindStumbleHalved()
    { return true; }

// the Dexterity reduction for a blind-fighting character is only 1.
inline int dnpBlindDexReductionOnly()
    { return 1; }

// the Climbing Rating penalty for a blind-fighting character is only -5
// percent.
inline int dnpBlindClimbPenaltyOnly()
    { return -5; }

// a boating-proficient character insures the boat is propelled at maximum
// speed.
inline bool dnpBoatingMaxSpeed()
    { return true; }

// boating proficiency reduces the dangers of capsizing a canoe or kayak.
inline bool dnpBoatingReducesCapsize()
    { return true; }

// direction sense requires concentrating 1d6 rounds before the determination.
inline int dnpDirConcentrateRoundsDie()
    { return 6; }

// a failed-but-greater-than-1 roll is off by up to 90 degrees left or right.
inline int dnpDirErrorDeg()
    { return 90; }

// a Proficiency Check of 1 determines a direction exactly opposite the true
// one.
inline int dnpDirOppositeRoll()
    { return 1; }

// the DM always makes the Proficiency Check for direction sense.
inline bool dnpDirSecretDMRoll()
    { return true; }

// endurance doubles the time a character can exert himself before fatigue and
// exhaustion.
inline int dnpEnduranceTimeMult()
    { return 2; }

// endurance does not extend the time unaffected by lack of food or water.
inline bool dnpEnduranceNoFoodWaterExtension()
    { return true; }

// fire-building starts a fire in 2d20 minutes with dry wood and tinder.
inline int dnpFireDryMinutesDice()
    { return 2; }

// wet wood or high winds increase the time to 3d20 minutes.
inline int dnpFireAdverseMinutesDice()
    { return 3; }

// the fire-builder does not normally need a tinderbox; flint and steel not
// required.
inline bool dnpFireNoTinderbox()
    { return true; }

// adverse conditions also require a successful Proficiency Check.
inline bool dnpFireAdverseNeedsCheck()
    { return true; }

// fishing allows one Proficiency Check per hour spent fishing.
inline int dnpFishChecksPerHour()
    { return 1; }

// the number of fish caught is the Wisdom score minus the d20 roll.
inline bool dnpFishCountWisdomMinusRoll()
    { return true; }

// one fish provides 1/2 the daily rations for one character (numerator).
inline int dnpFishRationNum()
    { return 1; }

// one fish provides 1/2 the daily rations for one character (denominator).
inline int dnpFishRationDen()
    { return 2; }

// approximately 50 percent of all fungi discovered underground are deadly
// poisonous.
inline int dnpFungusDeadlyPct()
    { return 50; }

// no check is needed with plentiful light and one turn of study.
inline bool dnpFungusStudyNoCheck()
    { return true; }

// the no-check study period is one turn.
inline int dnpFungusStudyTurns()
    { return 1; }

// emergency healing must occur within one round of the wound being inflicted.
inline int dnpHealEmergencyRounds()
    { return 1; }

// successful emergency healing recovers 1d3 hit points.
inline int dnpHealEmergencyDie()
    { return 3; }

// regular healing attention recovers 1 hit point per day without complete
// rest.
inline int dnpHealTravelHpPerDay()
    { return 1; }

// under a healer a character at complete rest recovers 2 hit points per day.
inline int dnpHealRestHpPerDay()
    { return 2; }

// immediate healing aid gives +2 to the saving throw vs. injected poison.
inline int dnpHealPoisonSaveMod()
    { return 2; }

// the aided character must remain at complete rest one turn.
inline int dnpHealPoisonRestTurns()
    { return 1; }

// the healer is completely occupied ministering for five melee rounds.
inline int dnpHealPoisonAidRounds()
    { return 5; }

// if the patient is moved or the aid interfered with, an unmodified re-save
// vs. poison is required.
inline bool dnpHealInterruptResaves()
    { return true; }

// mountaineering grants +10 percent to the Climbing Rating per slot spent.
inline int dnpMountClimbBonusPctPerSlot()
    { return 10; }

// mountaineering allows climbing with the aid of spikes driven into rock.
inline bool dnpMountUsesSpikes()
    { return true; }

// no jump check is needed for obstacles three feet tall or less.
inline int dnpRideJumpFreeObstacleFt()
    { return 3; }

// no jump check is needed for gaps less than 12 feet wide.
inline int dnpRideJumpFreeGapFt()
    { return 12; }

// a successful check urges the mount to leap obstacles up to seven feet high.
inline int dnpRideJumpMaxObstacleFt()
    { return 7; }

// a successful check urges the mount across gaps up to thirty feet.
inline int dnpRideJumpMaxGapFt()
    { return 30; }

// spurring adds six feet per round to the mount movement rate.
inline int dnpRideSpurFtPerRound()
    { return 6; }

// spurring lasts up to four turns.
inline int dnpRideSpurMaxTurns()
    { return 4; }

// after racing the steed must be walked by its dismounted rider for a turn.
inline int dnpRideSpurLeadTurns()
    { return 1; }

// hanging alongside the steed as a shield grants +6 to Armor Class.
inline int dnpRideShieldACBonus()
    { return 6; }

// the mounted leap allows a melee attack on any creature within 10 feet.
inline int dnpRideDropMeleeFt()
    { return 10; }

// the mounted leap requires a Proficiency Check with a -4 modifier.
inline int dnpRideDropMod()
    { return -4; }

// a failed mounted leap falls clumsily and suffers 1d3 points damage.
inline int dnpRideDropFailDie()
    { return 3; }

// failing the knees-guidance check after damage means falling: an additional
// 1d6 damage.
inline int dnpRideKneesFailDie()
    { return 6; }

// vaulting into the saddle of a standing mount needs no check, even in armor.
inline bool dnpRideVaultStillFree()
    { return true; }

// vaulting a moving mount, or moving in the same segment, requires a check.
inline bool dnpRideVaultMovingCheck()
    { return true; }

// guiding with the knees needs a check only if the character takes damage
// while riding.
inline bool dnpRideKneesCheckOnlyWhenDamaged()
    { return true; }

// a failed jump check means the mount balks and another check retains the
// seat or falls.
inline bool dnpRideJumpBalkOnFail()
    { return true; }

// spurring requires a Proficiency Check each turn.
inline bool dnpRideSpurCheckEachTurn()
    { return true; }

// the steed-shield feat allows no attack and no armor; missed attacks strike
// the mount instead.
inline bool dnpRideShieldNoArmorNoAttack()
    { return true; }

// rope use grants +2 on all attacks made with a lasso.
inline int dnpRopeLassoMod()
    { return 2; }

// rope use grants +10 percent on all Climbing Checks made while using a rope.
inline int dnpRopeClimbBonusPct()
    { return 10; }

// escaping bound hands takes a Proficiency Check with a -6 penalty.
inline int dnpRopeEscapeMod()
    { return -6; }

// the +10 percent includes attempts to belay companions.
inline bool dnpRopeClimbBonusIncludesBelay()
    { return true; }

// slow respiration drops air use to 10 percent of the resting rate.
inline int dnpSlowAirPct()
    { return 10; }

// the trance requires one turn of concentration in a restful position.
inline int dnpSlowConcentrateTurns()
    { return 1; }

// the trance character is fully aware of anything nearby and emerges at will.
inline bool dnpSlowFullyAware()
    { return true; }

// sound analysis calculates distances of up to one mile.
inline int dnpSoundMaxMiles()
    { return 1; }

// the successful-analysis margin of error for length: + or -30 percent.
inline int dnpSoundLenPct()
    { return 30; }

// the margin of error for width: + or -25 percent.
inline int dnpSoundWidthPct()
    { return 25; }

// the margin of error for height: + or -25 percent.
inline int dnpSoundHeightPct()
    { return 25; }

// a check of 5 or less also reveals additional details of the area.
inline int dnpSoundDetailRoll()
    { return 5; }

// sound analysis requires conditions of absolute silence.
inline bool dnpSoundSilenceRequired()
    { return true; }

// the sound must have a sharp staccato quality: a howl is ineffective, a
// click or loud hey works.
inline bool dnpSoundStaccatoRequired()
    { return true; }

// a failed check means no further attempts by that character on the same
// area.
inline bool dnpSoundFailLocksArea()
    { return true; }

// using sound analysis announces the presence of the party to listeners.
inline bool dnpSoundAnnouncesParty()
    { return true; }

// sound analysis can be used in conjunction with the animal noise
// proficiency.
inline bool dnpSoundCombinesAnimalNoise()
    { return true; }

// the swimming proficiency is fully detailed under the swimming rules on page
// 12 (the R504 pins).
inline bool dnpSwimRulesOnPageTwelve()
    { return true; }

// ---- the XP option ----

// player characters never earn experience points from proficiency use.
inline bool dnpXpPcNeverEarns()
    { return true; }

// a business NPC gains 1 experience point (numerator).
inline int dnpXpPerGpNum()
    { return 1; }

// per 2 gp of income netted by his business (denominator).
inline int dnpXpPerGpDen()
    { return 2; }

// NPCs advanced this way use the level-advancement table for fighters.
inline bool dnpXpUseFighterTable()
    { return true; }

// such characters gain 1d4 hit points per level.
inline int dnpXpNpcHpDie()
    { return 4; }

// the DM may simply assign these characters additional levels without
// recording income.
inline bool dnpXpDMMayAssignLevels()
    { return true; }

}   // namespace rules
