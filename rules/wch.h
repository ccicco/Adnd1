// =========================================================================================
// Adnd1 - rules/wch.h
// The Dragon issue-5 opener - the Witchcraft Supplement (folios 4-9), the
// Anhkheg lore pin (folios 12, 28) and the Wizard Research Rules (folios
// 24-26, 28)
// census 824 -> 825.
//
// Pinned from The Dragon Vol. 1 No. 5 (March 1977), the archive.org scan. The
// Witchcraft Supplement - the anonymous ms. the editor could not attribute,
// received over fifteen months prior: the witch encounter doctrine (rolls 5
// or 7 on the wilderness chart, the 35/65 Lawful/Chaotic split), the 12-sided
// Order ladder (Low 1-8, High 9-11, Secret 12, one Secret means all Secret),
// the spell quotas (good 7, Priestess 10 plus one weekly, Low 4 Minor, High 4
// Minor and 2 Major, Secret 6 Group A and 3 Group B), the spell matrix ranges
// and durations, the covens' trade economy (the willingness die, the Table A
// and B price bands, the 10 gp instructress) and the lair treasure caches by
// lair type. The Anhkheg - the Featured Creature at folios 12 and 28, its
// first magazine appearance, pinned lore-against-def: the merged MM1 ankheg
// def exists, so the print rides the bulette/Remorhaz precedent with its
// divergences (lair 25 vs 15, enzyme 1-10 vs 1-4, treasure B2 vs C) noted,
// never silent. The Wizard Research Rules by Charles Preston Goforth, Jr. -
// the spell research ladder (20 percent at every level, the investment
// doubling per level), the +1 and serious enchanting costs, the duplication,
// the ringmaking ladders up to the True Ring, the Wizard Blade with its d8
// property roll over the 11-property list, and the Memorial Enchanting In
// Distress. The voice rides extract/dragon/005/ (all 32 issue pages, the
// chat-side DjVu OCR transcript); the issue-5 gap report ships pre-flip. The
// editor's standing caution rides: none of this is official.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Witchcraft Supplement and the Wizard Research Rules pin as variant layers
// with provenance; the Anhkheg rides the lore-against-def precedent against
// the merged MM1 def - the print divergences (the 25 vs 15 lair percent, the
// 1-10 vs 1-4 enzyme, the B2 vs C treasure, the 1-6-dice acid squirt vs the
// def 8-32) noted in the audit, never silent, and no new registry def is
// created. The witchcraft wilderness encounter table is scoped out on OCR
// garble per the standing caution - the clean scalars pin, the garbled grid
// does not; the lair treasure table pins the printed cache bands with the
// Secret lair unprinted jewelry line as the 0 sentinel and its ring and
// Secret-item extras in the audit note; the spell matrix pins R and D as
// printed with 0 the no-printed-duration sentinel; the research ladder pins
// the doubling investments exactly as printed at all ten levels.
//
namespace rules {

// ---- the Anhkheg lore pin (folios 12, 28) ----

// the Anhkheg number appearing, minimum - 1 (folio 12)
inline int wchAnhkhegNaMin()
    { return 1; }

// the Anhkheg number appearing, maximum - 6 (folio 12)
inline int wchAnhkhegNaMax()
    { return 6; }

// the Anhkheg length, minimum - 10 feet (folio 12)
inline int wchAnhkhegLengthMin()
    { return 10; }

// the Anhkheg length, maximum - 20 feet (folio 12)
inline int wchAnhkhegLengthMax()
    { return 20; }

// the Anhkheg armor class, the brown chitin overall - 2 (folio 12)
inline int wchAnhkhegAcOverall()
    { return 2; }

// the Anhkheg armor class, the pink underside - 4 (folio 12)
inline int wchAnhkhegAcUnder()
    { return 4; }

// the Anhkheg movement - 12 inches on the surface (folio 12)
inline int wchAnhkhegMoveSurface()
    { return 12; }

// the Anhkheg movement - 6 through the ground (folio 12)
inline int wchAnhkhegMoveBurrow()
    { return 6; }

// the Anhkheg hit dice, minimum - 3 (folio 12)
inline int wchAnhkhegHdMin()
    { return 3; }

// the Anhkheg hit dice, maximum - 8 (folio 12)
inline int wchAnhkhegHdMax()
    { return 8; }

// the Anhkheg hit-die type - 8 sided (folio 12)
inline int wchAnhkhegHdDieSides()
    { return 8; }

// the Anhkheg percent in lair - 25 (folio 12); the merged MM1 def carries 15
// - the print divergence noted, never silent
inline int wchAnhkhegLairPct()
    { return 25; }

// the Anhkheg bite damage, minimum - 3 points (folio 12)
inline int wchAnhkhegBiteMin()
    { return 3; }

// the Anhkheg bite damage, maximum - 18 points (folio 12)
inline int wchAnhkhegBiteMax()
    { return 18; }

// the Anhkheg acid squirt - up to 1-6 dice of damage according to size (folio
// 12); the merged MM1 def carries the 8-32 squirt - the divergence noted
inline int wchAnhkhegAcidDiceMax()
    { return 6; }

// the Anhkheg acid squirt range - 30 feet (folio 28)
inline int wchAnhkhegAcidRangeFeet()
    { return 30; }

// the Anhkheg acid squirt rate - once per six hours, with digestion suspended
// the same length (folio 28)
inline int wchAnhkhegAcidRechargeHours()
    { return 6; }

// the Anhkheg digestive enzyme, minimum - 1 point per turn until the prey
// dissolves (folio 28)
inline int wchAnhkhegEnzymeMin()
    { return 1; }

// the Anhkheg digestive enzyme, maximum - 10 points per turn (folio 28); the
// merged MM1 def carries 1-4 - the divergence noted
inline int wchAnhkhegEnzymeMax()
    { return 10; }

// the Anhkheg ambush depth, minimum - 5 feet under the ground (folio 28)
inline int wchAnhkhegAmbushMin()
    { return 5; }

// the Anhkheg ambush depth, maximum - 10 feet under the ground (folio 28)
inline int wchAnhkhegAmbushMax()
    { return 10; }

// the Dragon-print Anhkheg rides the lore-against-def precedent (the
// bulette/Remorhaz line) - the merged MM1 ankheg def exists at
// monsters/monsters/a/ankheg.lua, so this is a provenance pin, never a
// competing registry def (folios 12, 28)
inline bool wchAnhkhegLoreAgainstDef()
    { return true; }

// the Dragon print diverges from the merged MM1 def - lair 25 vs 15 percent,
// enzyme 1-10 vs 1-4, treasure B2 vs C - the divergences noted in the audit,
// never silent (folios 12, 28)
inline bool wchAnhkhegPrintDivergent()
    { return true; }

// the Anhkheg treasure - B2 at folio 12, pinned as scanned against the merged
// MM1 def's C (the divergence noted)
inline bool wchAnhkhegTreasureB2()
    { return true; }

// the Anhkheg alignment - neutral (folio 12)
inline bool wchAnhkhegNeutral()
    { return true; }

// the Anhkheg magic resistance - none (folio 12)
inline bool wchAnhkhegNoMagicResistance()
    { return true; }

// the Anhkheg favorite attack - lying 5-10 feet under the ground until its
// antenna detect prey overhead, then burrowing out directly underneath (folio
// 28)
inline bool wchAnhkhegBurrowHunter()
    { return true; }

// ---- the Witchcraft Supplement (folios 4-9) ----

// the wilderness witch encounter roll, first - 5 on the die means witches
// present 50 percent of the time (folio 4)
inline int wchWitchWildRollA()
    { return 5; }

// the wilderness witch encounter roll, second - 7 (folio 4)
inline int wchWitchWildRollB()
    { return 7; }

// the witch alignment split - Lawful 35 percent of the time (folio 4)
inline int wchWitchLawfulPct()
    { return 35; }

// the witch alignment split - Chaotic 65 percent (folio 4)
inline int wchWitchChaoticPct()
    { return 65; }

// the chaotic witch Order check - a 12-sided die, checked per witch (folio 4)
inline int wchWitchOrderDieSides()
    { return 12; }

// the Low Order band, minimum - 1 on the 12-sided die (folio 4)
inline int wchWitchOrderLowMin()
    { return 1; }

// the Low Order band, maximum - 8 (folio 4)
inline int wchWitchOrderLowMax()
    { return 8; }

// the High Order band, minimum - 9 (folio 4)
inline int wchWitchOrderHighMin()
    { return 9; }

// the High Order band, maximum - 11 (folio 4)
inline int wchWitchOrderHighMax()
    { return 11; }

// the forbidden Secret Order - a roll of 12; one Secret witch present means
// all present are (folio 4)
inline int wchWitchOrderSecretRoll()
    { return 12; }

// the Secret Order witch in lair - 75 percent of the time, in any terrain
// (folio 4)
inline int wchSecretWitchLairPct()
    { return 75; }

// a good (Lawful) witch performs 7 spells per day (folio 4)
inline int wchGoodWitchSpellsDaily()
    { return 7; }

// the chance a Lawful witch encountered is ancient - 4 percent, qualifying
// her as a Priestess (folio 4)
inline int wchPriestessAncientPct()
    { return 4; }

// a Priestess performs any ten ordinary spells daily (folio 4)
inline int wchPriestessSpellsDaily()
    { return 10; }

// a Priestess may employ one of her own more powerful spells each week (folio
// 4)
inline int wchPriestessWeeklySpells()
    { return 1; }

// a Priestess has saving throws equal to an eleventh level wizard (folio 4)
inline int wchPriestessSaveLevel()
    { return 11; }

// a Low Order witch performs four Minor spells daily (folio 4)
inline int wchLowWitchMinorDaily()
    { return 4; }

// a High Order witch performs four Minor spells daily (folio 4)
inline int wchHighWitchMinorDaily()
    { return 4; }

// a High Order witch performs two Major spells daily (folio 4)
inline int wchHighWitchMajorDaily()
    { return 2; }

// a Secret Order witch performs 6 Group A spells daily (folio 7)
inline int wchSecretGroupADaily()
    { return 6; }

// a Secret Order witch performs 3 Group B spells daily (folio 7)
inline int wchSecretGroupBDaily()
    { return 3; }

// the Secret witch near her lair - impossible to surprise, a 50 percent
// chance of sneaking up (folio 7)
inline int wchSecretWitchSneakPct()
    { return 50; }

// the Secret witch items - usable only by a Priestess, a High Order evil
// witch, or a wizard above the 13th level (folio 7)
inline int wchSecretItemMinLevel()
    { return 13; }

// the Priestess super-Locate performance price - a magic item or 10,000 gold
// pieces, whichever seems more valuable (folio 4)
inline int wchPriestessLocatePriceGp()
    { return 10000; }

// a witch instructress earns 10 gold pieces per student per object (folio 8)
inline int wchWitchTrainFeeGp()
    { return 10; }

// the willingness die - 1-3 on a six-sided die, she sells at the indicated
// price (folio 9)
inline int wchSellDieWillingMax()
    { return 3; }

// the willingness die - 4, she asks double the usual price (folio 9)
inline int wchSellDieDoubleRoll()
    { return 4; }

// the willingness die - 5-6, she refuses to part with the item (folio 9)
inline int wchSellDieRefuseMin()
    { return 5; }

// the willingness die refuse band, maximum - 6 (folio 9)
inline int wchSellDieRefuseMax()
    { return 6; }

// a Table A witch item costs 6-15 thousand gold pieces or equivalent (folio
// 9)
inline int wchTableACostMin()
    { return 6000; }

// the Table A cost band, maximum - 15 thousand (folio 9)
inline int wchTableACostMax()
    { return 15000; }

// a Table B witch item - magic items plus 10-50,000 gold pieces, by hard
// bargaining (folio 9)
inline int wchTableBCostMin()
    { return 10000; }

// the Table B gold band, maximum - 50,000 (folio 9)
inline int wchTableBCostMax()
    { return 50000; }

// a witch commonly asks 20 percent of the haul for a treasure map (folio 9)
inline int wchTreasureMapCutPct()
    { return 20; }

// the treasure-map alliance die - 1-4 on a six-sided die and the witch joins
// the expedition as an ally (folio 9)
inline int wchMapAllianceRollMax()
    { return 4; }

// the Skull of Death - the wearer regenerates 5 points per turn, even if
// killed unless beheaded (folio 7)
inline int wchSkullRegenPerTurn()
    { return 5; }

// the Skull of Death - mental command of undead up to three dice at any range
// (folio 7)
inline int wchSkullUndeadDiceMax()
    { return 3; }

// the Luck Charm strength check - a 20-sided die roll per category (folios 9,
// 28)
inline int wchLuckCharmDieSides()
    { return 20; }

// the Guardian Egg brass orb weighs as much as 250 gold pieces (folio 9)
inline int wchGuardianEggWeightGp()
    { return 250; }

// the Guardian Egg servant - employable once every 48 hours, until the next
// sunrise (folio 9)
inline int wchGuardianEggReuseHours()
    { return 48; }

// the Guardian Egg metal servants - armor class 2 by their metal bodies
// (folio 9)
inline int wchGuardianEggServantAc()
    { return 2; }

// the Guardian Egg on the ground - a metal Hill Giant of 8 dice (folio 9)
inline int wchGuardianEggGiantDice()
    { return 8; }

// the Guardian Egg thrown in the air - a metal Roc of 8 dice (folio 9)
inline int wchGuardianEggRocDice()
    { return 8; }

// the Guardian Egg in a pool - a 7 foot Dragon Turtle of 10 dice (folio 9)
inline int wchGuardianEggTurtleDice()
    { return 10; }

// the Hornet Cape flight - 36 inches per turn indefinitely (folio 8)
inline int wchHornetCapeSpeed()
    { return 36; }

// the Hornet Cape commands flying creatures within 50 inches, lost on
// touchdown (folio 8)
inline int wchHornetCapeCommandRange()
    { return 50; }

// the Hornet Cape - as many as three stings per turn (folio 8)
inline int wchHornetCapeStingsPerTurn()
    { return 3; }

// the Hornet Cape sting - a 7 inch range (folio 8)
inline int wchHornetCapeStingRange()
    { return 7; }

// the Hornet Cape sting - 3 dice of damage (folio 8)
inline int wchHornetCapeStingDice()
    { return 3; }

// the Seed Satchel - a package of 7-12 magic seeds (folio 8)
inline int wchSeedSatchelMin()
    { return 7; }

// the Seed Satchel count, maximum - 12 seeds (folio 8)
inline int wchSeedSatchelMax()
    { return 12; }

// a seed feature disappears in one hour, the seed usable once (folio 8)
inline int wchSeedFeatureHours()
    { return 1; }

// the Witch Wand performs 7 spells each day, for years before the power wanes
// (folio 7)
inline int wchWandSpellsDaily()
    { return 7; }

// the Serpent Belt can stretch to 10 feet (folio 8)
inline int wchSerpentBeltStretchFeet()
    { return 10; }

// the Serpent Belt - 2 dice of damage to targets (folio 8)
inline int wchSerpentBeltDamageDice()
    { return 2; }

// a lair with three or more witches holds a Potion Cauldron (folio 8)
inline int wchPotionCauldronLairMin()
    { return 3; }

// witch potions cost between 500 gold pieces (folio 8)
inline int wchPotionPriceMin()
    { return 500; }

// and 3000 gold pieces, by a die roll (folio 8)
inline int wchPotionPriceMax()
    { return 3000; }

// a witch out of the lair is flying her broom 35 percent of the time, at 4 to
// 40 feet (folio 8)
inline int wchBroomFlyingPct()
    { return 35; }

// the Love Locket - a good witch accepts no more than 20 percent of the
// victim's wealth (folio 9)
inline int wchLoveLocketCutPct()
    { return 20; }

// the Love Locket - no more than 2 magic items kept (folio 9)
inline int wchLoveLocketItemMax()
    { return 2; }

// the Dart Ring fires twice per turn up to 30 feet, inexhaustible and never
// missing (folio 9)
inline int wchDartRingShotsPerTurn()
    { return 2; }

// the Dart Ring range - 30 feet (folio 9)
inline int wchDartRingRangeFeet()
    { return 30; }

// the Thorn Twine - a 40 foot thorn vine flexible as rope (folio 9)
inline int wchThornTwineLengthFeet()
    { return 40; }

// the Thorn Twine - 4 dice of damage each turn the victim stays ensnared
// (folio 9)
inline int wchThornTwineDicePerTurn()
    { return 4; }

// the Table B Hill Seeds come 1-3 in number (folio 9)
inline int wchHillSeedNumberMin()
    { return 1; }

// the Hill Seeds count, maximum - 3 (folio 9)
inline int wchHillSeedNumberMax()
    { return 3; }

// witchcraft - including the Clerical- and wizard-resembling spells - will
// not affect Djinn, Efreet, or Clerics of any alignment: the three immune
// types (folio 4)
inline bool wchWitchImmunities()
    { return true; }

// all witches except a Priestess have saving throws equal to warlocks (folio
// 4)
inline bool wchWitchSavesAsWarlock()
    { return true; }

// saving throws against witch magic treat it as a spell on the Saving Throw
// Matrix (folio 4)
inline bool wchWitchMagicTreatedAsSpell()
    { return true; }

// a Secret witch is a loner - never encountered in a group of mutually
// protective members (folios 4, 7)
inline bool wchSecretWitchLoner()
    { return true; }

// the Secret witches may be found in ANY terrain, including water, with only
// one regardless of location (folio 4)
inline bool wchSecretWitchAnyTerrain()
    { return true; }

// Secret Order witches have no brooms, no crystal balls and no familiar
// (folio 7)
inline bool wchSecretWitchNoGear()
    { return true; }

// any Cleric touching a Secret witch item meets with instant death - the
// Secret witches recognize no power but their own (folio 7)
inline bool wchSecretItemClericDeath()
    { return true; }

// the Secret Group B spells are not vulnerable to Dispell Magic (folio 7)
inline bool wchSecretItemsGroupBNoDispel()
    { return true; }

// never find a lair with only High Order witches - the Curtainwall note
// (folio 8)
inline bool wchLairNoHighOnly()
    { return true; }

// Lawful witch lairs are not curse-guarded; good witch lairs carry ordinary
// manual traps (folio 8)
inline bool wchLawfulLairNoCurseGuard()
    { return true; }

// good witches keep only small birds or fur animals, polymorphed into a
// dragon bodyguard in an emergency (folio 8)
inline bool wchGoodWitchPolymorphFamiliar()
    { return true; }

// a witch in her circle of concentration is immune to Charm/Hold person,
// Sleep, feeblemind and control items (folio 8)
inline bool wchConcentrationImmune()
    { return true; }

// clerics are immune to the witch's paralyzing-poison contamination, but
// cannot detect it (folio 5)
inline bool wchClericPoisonTouchImmune()
    { return true; }

// ---- the spell matrix (folios 4-7) ----

// the wchSpellMatrix row count - 21 rows as scanned
inline int wchSpellMatrixCount()
    { return 21; }

// the spell range in inches - R as printed (folios 4-7)
inline int wchSpellRange(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 10;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 10;
        case 6:
            return 2;
        case 7:
            return 7;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 15;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 50;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 8;
        case 17:
            return 7;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 2;
        default:
            return 0;
        }
    }

// the spell duration in turns - D as printed, 0 the sentinel for no printed
// duration (folios 4-7)
inline int wchSpellDuration(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return 2;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 36;
        default:
            return 0;
        }
    }

// ---- the lair treasure (folio 8) ----

// the wchLairTreasure row count - 4 rows as scanned
inline int wchLairTreasureCount()
    { return 4; }

// the gold-piece cache minimum, in thousands - as printed (folio 8)
inline int wchLairGpMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 11;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the gold-piece cache maximum, in thousands (folio 8)
inline int wchLairGpMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 20;
        case 3:
            return 4;
        default:
            return 0;
        }
    }

// the gem cache minimum (folio 8)
inline int wchLairGemMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the gem cache maximum (folio 8)
inline int wchLairGemMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 11;
        case 3:
            return 3;
        default:
            return 0;
        }
    }

// the jewelry cache minimum - 0 the sentinel for no printed jewelry line
// (folio 8)
inline int wchLairJewMin(int b)
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
        default:
            return 0;
        }
    }

// the jewelry cache maximum (folio 8)
inline int wchLairJewMax(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 10;
        case 2:
            return 8;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// the witch item cache minimum (folio 8)
inline int wchLairWiMin(int b)
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
        default:
            return 0;
        }
    }

// the witch item cache maximum (folio 8)
inline int wchLairWiMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 6;
        default:
            return 0;
        }
    }

// ---- the Wizard Research Rules (folios 24-26, 28) ----

// the spell research chance of success - 20 percent at every level, the
// certain line doubling the investment (folio 24)
inline int wchResearchSuccessPct()
    { return 20; }

// anything enchanted to +1 - 2 months (folio 24)
inline int wchEnchantPlusOneMonths()
    { return 2; }

// the +1 enchantment investment - 2,000 gold pieces (folio 24)
inline int wchEnchantPlusOneGp()
    { return 2000; }

// serious enchanting above +1 - 10 months (folio 24)
inline int wchSeriousEnchantMonths()
    { return 10; }

// the serious enchantment investment - 10,000 gold pieces (folio 24)
inline int wchSeriousEnchantGp()
    { return 10000; }

// enchanting a duplicate - 10,000 gold pieces (folio 26)
inline int wchDuplicateGp()
    { return 10000; }

// the duplication time - 10 months times the Miscellaneous Magic Table number
// (folio 26)
inline int wchDuplicateMonths()
    { return 10; }

// serious ringmaking - 10,000 gold pieces (folio 26)
inline int wchRingMakeGp()
    { return 10000; }

// the serious ringmaking time - 10 months (folio 26)
inline int wchRingMakeMonths()
    { return 10; }

// the True Ring - 10,000 gold pieces (folio 26)
inline int wchTrueRingGp()
    { return 10000; }

// the True Ring time - 10 months (folio 26)
inline int wchTrueRingMonths()
    { return 10; }

// the True Ring experience point cost - 300,000, drained and permanently lost
// (folio 26)
inline int wchTrueRingXp()
    { return 300000; }

// the Wizard Blade - 10,000 gold pieces (folio 26)
inline int wchWizardBladeGp()
    { return 10000; }

// the Wizard Blade time - 10 months (folio 26)
inline int wchWizardBladeMonths()
    { return 10; }

// the Wizard Blade experience point cost - 200,000, drained and permanently
// lost (folio 26)
inline int wchWizardBladeXp()
    { return 200000; }

// the Wizard Blade - roll one 8-sided die and choose that many properties
// (folio 26)
inline int wchWizardBladeDieSides()
    { return 8; }

// the Wizard Blade property list - 11: flaming, a purpose, another purpose,
// vorpal blade, a curse, another curse, life draining, sharpness, holy,
// dancing, disruption (folio 26)
inline int wchWizardBladePropertyCount()
    { return 11; }

// the Wizard Blade named level, maximum - +6 (folio 26)
inline int wchWizardBladeLevelMax()
    { return 6; }

// the Wizard Blade named level, minimum - -6 (folio 26)
inline int wchWizardBladeLevelMin()
    { return -6; }

// embedded rings carry unlimited charges; wands and staffs 100 charges of the
// new spell (folio 26)
inline int wchWandStaffCharges()
    { return 100; }

// the Sorcerer's Memorial Enchanting In Distress - roll one 8-sided die for
// hits, the magical distress hits uncured by time or healing (folios 26, 28)
inline int wchMemorialEnchantDie()
    { return 8; }

// the larger Wizard Blade rolls - 300,000 experience points buys the 12-sided
// die (folio 26)
inline int wchBladeLargerDie300k()
    { return 12; }

// 400,000 experience points buys the 16-sided die (folio 26)
inline int wchBladeLargerDie400k()
    { return 16; }

// 500,000 experience points buys the 20-sided die (folio 26)
inline int wchBladeLargerDie500k()
    { return 20; }

// the permanent stat-increase spell - usable once per stat per character,
// including all clones, never stacked (folio 24)
inline bool wchStatSpellOncePerStat()
    { return true; }

// spells embedded in rings carry unlimited charges (folio 26)
inline bool wchEmbeddedRingsUnlimited()
    { return true; }

// already enchanted objects may not be re-enchanted, though new spells may be
// embedded (folio 26)
inline bool wchNoReenchant()
    { return true; }

// only wizards, patriarchs, witches and matriarchs may create or change magic
// items through research, in a magic furnace fed with gold (folio 24)
inline bool wchOnlyEnchantersCreate()
    { return true; }

// ---- the spell research cost (folio 24) ----

// the wchResearchCost row count - 10 rows as scanned
inline int wchResearchCostCount()
    { return 10; }

// the research time in weeks - the spell level (folio 24)
inline int wchResearchWeeks(int b)
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
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return 0;
        }
    }

// the gold investment at the 20 percent chance - doubling per level from
// 2,000 (folio 24)
inline int wchResearchGold(int b)
    {
        switch (b) {
        case 0:
            return 2000;
        case 1:
            return 4000;
        case 2:
            return 8000;
        case 3:
            return 16000;
        case 4:
            return 32000;
        case 5:
            return 64000;
        case 6:
            return 128000;
        case 7:
            return 256000;
        case 8:
            return 512000;
        case 9:
            return 1024000;
        default:
            return 0;
        }
    }

// the gold investment at the 100 percent certain line - doubling per level
// from 10,000 (folio 24)
inline int wchResearchGoldCertain(int b)
    {
        switch (b) {
        case 0:
            return 10000;
        case 1:
            return 20000;
        case 2:
            return 40000;
        case 3:
            return 80000;
        case 4:
            return 160000;
        case 5:
            return 320000;
        case 6:
            return 640000;
        case 7:
            return 1280000;
        case 8:
            return 2560000;
        case 9:
            return 5120000;
        default:
            return 0;
        }
    }

}   // namespace rules
