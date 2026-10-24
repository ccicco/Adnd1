// =========================================================================================
// Adnd1 - rules/mm2s.h
// THE MM2 LETTER S WALK - THE SANDLING TO TAER TURNS (pp. 106-117: the
// sandling p. 106, the scorpion variant table p. 107, the scum creeper and
// the selkie p. 107, the shade p. 108, the greater shedu head p. 109
// (prior-owned), the sirine and the skeleton (animal) p. 109, the skunk, the
// slime creature and the olive slime p. 110, the snake variant table p. 111,
// the solar pp. 111-112, the solifugid variant table p. 112, the spectator
// pp. 112-113, the spider (giant marine), the spriggan and the squealer pp.
// 113-114, the squirrel variant table p. 114, the squirrel (carnivorous
// flying) p. 114, the stegocentipede pp. 114-115, the stench kow, the stone
// guardian and the storoper pp. 115-116, the sundew (giant), the swan and the
// swanmay pp. 116-117, the swordfish and the taer p. 117), promoted to the
// live registry; the S-FLIP round, the Letter S gap box flips to closed
// census 735 -> 736.
//
// Round eighteen of the MM2 arc, the SEVENTH single-letter pass (Curtiss Go
// call on the landed letter R walk; the letter S pin-time walk found
// TWENTY-NINE entry heads carrying THIRTY-FOUR stat blocks - one prior-owned
// head (the greater shedu, the MM1 s/shedu.lua print owns it, head pins only,
// no def), no doctrine-only heads)
//
// The pin headers stay the print-fidelity record; the thirty-three .lua defs
// ride the R791 data_files extension in the MM1 registry schema (the
// defensive coercers load the verbatim print cells, the SStats grid carries
// the loader values)
//
namespace rules {

// ---- the MM2 letter S walk round pins (the R813 census) ----

// The MM2 letter S walk round: the sandling to taer turns, the SEVENTH
// single-letter pass (Curtiss Go call on the landed letter R walk)
inline int mm2sRound()
    { return 813; }

// The registry census before the R813 promotion (the landed R812 count)
inline int mm2sRegistryBefore()
    { return 733; }

// The registry census after the R813 promotion (33 defs riding the R791
// data_files extension)
inline int mm2sRegistryAfter()
    { return 766; }

// The 33 letter S defs promoted this round
inline int mm2sDefCount()
    { return 33; }

// The 29 letter S entry heads (the shedu greater head is prior-owned, no def
// of its own)
inline int mm2sEntryCount()
    { return 29; }

// The 34 letter S stat blocks (33 promoted defs plus the prior-owned greater
// shedu head block)
inline int mm2sStatBlockHeadings()
    { return 34; }

// No doctrine-only family heads in the letter S walk
inline int mm2sDoctrineHeads()
    { return 0; }

// The 29 letter S index entries
inline int mm2sLetterSHeadings()
    { return 29; }

// The 33-row SStats stat grid
inline int mm2sSStatRows()
    { return 33; }

// The gap census after the S-FLIP: 24 boxes closed
inline int mm2sGapClosed()
    { return 24; }

// The gap census after the S-FLIP: 13 boxes open
inline int mm2sGapOpen()
    { return 13; }

// The one prior-owned letter S head: the greater shedu - the MM1 s/shedu.lua
// print owns it, head pins only, no def
inline int mm2sPriorOwnedEntries()
    { return 1; }

// ---- the sandling pins (the R813 MM2 letter S walk) ----

// The Sandling xpValue (the print 4 base 85 + 4/hp x avgHp 14)
inline int mm2sSandlingXpValue()
    { return 141; }

// The Sandling xp level
inline int mm2sSandlingXpLevel()
    { return 3; }

// 10 gallons or more of water cast upon a sandling acts as a slow spell and
// halves its damage
inline int mm2sSandlingWaterGallons()
    { return 10; }

// The water-slowed sandling strikes for only one-half damage (1-8)
inline int mm2sSandlingWaterDamageMax()
    { return 8; }

// A sandling grows until it reaches full size (10 feet in diameter)
inline int mm2sSandlingFullSizeFeet()
    { return 10; }

// Tiny sandlings grow to about 2 inches in diameter before they split from
// the parent
inline int mm2sSandlingInfantSplitInches()
    { return 2; }

// Reports of huge sandlings 3 times as large as normal adults
// (unsubstantiated)
inline int mm2sSandlingHugeReportsMultiplier()
    { return 3; }

// Sandlings are savagely territorial and attack trespassers
inline bool mm2sSandlingTerritorial()
    { return true; }

// ---- the scorpion pins (the R813 MM2 letter S walk) ----

// The Scorpion, Large xpValue (the print 2+2 base 90 + 3/hp x avgHp 9)
inline int mm2sScorpionLargeXpValue()
    { return 117; }

// The Scorpion, Large xp level
inline int mm2sScorpionLargeXpLevel()
    { return 3; }

// The Scorpion, Huge xpValue (the print 4+4 base 165 + 5/hp x avgHp 18)
inline int mm2sScorpionHugeXpValue()
    { return 255; }

// The Scorpion, Huge xp level
inline int mm2sScorpionHugeXpLevel()
    { return 4; }

// The poison of the large scorpion is weaker than normal (+2 on saving throw)
inline int mm2sScorpionLargeSaveBonus()
    { return 2; }

// If struck by the stinger the victim must save vs. poison or be instantly
// killed
inline bool mm2sScorpionStingerLethal()
    { return true; }

// ---- the scum creeper pins (the R813 MM2 letter S walk) ----

// The Scum Creeper xpValue (the print 1 (2-8 hp) base 14 + 1/hp x avgHp 5)
inline int mm2sScumCreeperXpValue()
    { return 19; }

// The Scum Creeper xp level
inline int mm2sScumCreeperXpLevel()
    { return 1; }

// 1 in 20 scum creeper hits fasten the monster onto the face, blinding the
// victim
inline int mm2sScumFaceAttachChanceIn20()
    { return 20; }

// Each round thereafter the attached scum creeper inflicts 1 point of damage
// automatically
inline int mm2sScumAttachDamagePerRound()
    { return 1; }

// Rock salt causes 2 points of damage per round for 1-4 rounds
inline int mm2sScumSaltDamagePerRound()
    { return 2; }

// The saline effect lasts at least 1 round
inline int mm2sScumSaltRoundsMin()
    { return 1; }

// The saline effect lasts at most 4 rounds
inline int mm2sScumSaltRoundsMax()
    { return 4; }

// A scum creeper can move freely upon walls or ceilings
inline bool mm2sScumWallClimber()
    { return true; }

// ---- the selkie pins (the R813 MM2 letter S walk) ----

// The Selkie xpValue (the print 3+3 base 75 + 4/hp x avgHp 13)
inline int mm2sSelkieXpValue()
    { return 127; }

// The Selkie xp level
inline int mm2sSelkieXpLevel()
    { return 3; }

// Selkies encountered underwater are 90% likely to be unarmed
inline int mm2sSelkieUnarmedUnderwaterPct()
    { return 90; }

// Weather spells require 1 week of rest between castings
inline int mm2sSelkieWeatherRestWeeks()
    { return 1; }

// The old selkie leader can perform augury, cure light wounds, cure disease,
// weather summoning and control weather
inline bool mm2sSelkieLeaderSpellPowers()
    { return true; }

// ---- the shade pins (the R813 MM2 letter S walk) ----

// The Shade xpValue (the print As original class and level base 0 + 0/hp x
// avgHp 0)
inline int mm2sShadeXpValue()
    { return 0; }

// The Shade xp level
inline int mm2sShadeXpLevel()
    { return 0; }

// Shades regain hit points at 1 hit point per turn
inline int mm2sShadeRegenPerTurn()
    { return 1; }

// Shades regrow body parts lost in combat (save the head) in 1-4 weeks
inline int mm2sShadeRegrowLimbsWeeksMin()
    { return 1; }

// Shades regrow body parts lost in combat (save the head) in 1-4 weeks
inline int mm2sShadeRegrowLimbsWeeksMax()
    { return 4; }

// A shade can create 2-5 shadow images
inline int mm2sShadeImagesMin()
    { return 2; }

// A shade can create 2-5 shadow images
inline int mm2sShadeImagesMax()
    { return 5; }

// Shadow images act only within 30 feet of their creator
inline int mm2sShadeImageRangeFeet()
    { return 30; }

// Magic resistance for a shade will never exceed 60%
inline int mm2sShadeMrCapPct()
    { return 60; }

// Shades with thieving ability gain 2% per level in shadowy conditions
inline int mm2sShadeHideBonusShadowyPct()
    { return 2; }

// Shades with thieving ability gain 5% per level in night/dark conditions
inline int mm2sShadeHideBonusNightPct()
    { return 5; }

// A shade in bright light makes all saves at -4 on the die
inline int mm2sShadeBrightSavePenalty()
    { return 4; }

// Unless they meet with an accident or are killed, shades are undying
inline bool mm2sShadeUndying()
    { return true; }

// All shades have the shadow-walk ability (the transport requires 1 full
// round)
inline bool mm2sShadeShadowWalk()
    { return true; }

// ---- the sirine pins (the R813 MM2 letter S walk) ----

// The Sirine xpValue (the print 4-7 base 350 + 10/hp x avgHp 14)
inline int mm2sSirineXpValue()
    { return 490; }

// The Sirine xp level
inline int mm2sSirineXpLevel()
    { return 5; }

// The sirine song charms person at 3" range
inline int mm2sSirineSongRangeInches()
    { return 3; }

// A creature touched in melee by a sirine must save vs. poison or become an
// idiot (intelligence=2)
inline int mm2sSirineTouchIdiotInt()
    { return 2; }

// All sirine saving throws are made as 11th-level magic-users
inline int mm2sSirineSaveAsLevel()
    { return 11; }

// Sirines save vs. poison with a +2 bonus
inline int mm2sSirinePoisonSaveBonus()
    { return 2; }

// Sirines are immune to all forms of gas
inline bool mm2sSirineGasImmune()
    { return true; }

// The sirine song will charm person all hostile creatures within hearing
inline bool mm2sSirineSongCharm()
    { return true; }

// ---- the skeleton (animal) pins (the R813 MM2 letter S walk) ----

// The Skeleton, Animal xpValue (the print 1-1 base 10 + 1/hp x avgHp 2)
inline int mm2sSkeletonAnimalXpValue()
    { return 12; }

// The Skeleton, Animal xp level
inline int mm2sSkeletonAnimalXpLevel()
    { return 1; }

// Animal skeletons are produced at the rate of 1-1/2 (3 halves) per
// experience level of the caster
inline int mm2sSkeletonAnimalAnimateNum()
    { return 3; }

// Animal skeletons are produced at the rate of 1-1/2 per 2 experience levels
// of the caster
inline int mm2sSkeletonAnimalAnimateDen()
    { return 2; }

// Animal skeletons are turned at +1 in the cleric's favor, and 1d8+6 will be
// turned or destroyed
inline int mm2sSkeletonAnimalTurnDieSides()
    { return 8; }

// Animal skeletons are turned at +1 in the cleric's favor, and 1d8+6 will be
// turned or destroyed
inline int mm2sSkeletonAnimalTurnDieBonus()
    { return 6; }

// Animal skeletons are turned as normal skeletons but at +1 in the cleric's
// favor
inline int mm2sSkeletonAnimalTurnPlus()
    { return 1; }

// Edged weapons inflict only one-half normal damage on animal skeletons
inline bool mm2sSkeletonAnimalEdgedHalf()
    { return true; }

// Animal skeletons are immune to charm, cold, death magic, hold, and sleep
inline bool mm2sSkeletonAnimalImmuneToMindSpells()
    { return true; }

// ---- the skunk pins (the R813 MM2 letter S walk) ----

// The Skunk xpValue (the print 1/4 base 4 + 1/hp x avgHp 2)
inline int mm2sSkunkXpValue()
    { return 6; }

// The Skunk xp level
inline int mm2sSkunkXpLevel()
    { return 1; }

// Those failing the musk save are nauseated for 1-4 rounds
inline int mm2sSkunkMuskNauseaRoundsMin()
    { return 1; }

// Those failing the musk save are nauseated for 1-4 rounds
inline int mm2sSkunkMuskNauseaRoundsMax()
    { return 4; }

// Each must save again vs. poison or be blinded for 1-4 rounds
inline int mm2sSkunkBlindRoundsMin()
    { return 1; }

// Each must save again vs. poison or be blinded for 1-4 rounds
inline int mm2sSkunkBlindRoundsMax()
    { return 4; }

// The skunk releases a 1"x1"x1" cloud of stinking musk
inline bool mm2sSkunkMuskCloud()
    { return true; }

// ---- the slime pins (the R813 MM2 letter S walk) ----

// The Slime Creature xpValue (the print 3+2, 5+2, or 8+2 base 110 + 4/hp x
// avgHp 12)
inline int mm2sSlimeCreatureXpValue()
    { return 158; }

// The Slime Creature xp level
inline int mm2sSlimeCreatureXpLevel()
    { return 3; }

// The Slime, Olive xpValue (the print 2+2 base 330 + 3/hp x avgHp 9)
inline int mm2sSlimeOliveXpValue()
    { return 357; }

// The Slime, Olive xp level
inline int mm2sSlimeOliveXpLevel()
    { return 5; }

// Slime creatures have a 10% chance of infecting their opponent with olive
// slime when a hit is scored
inline int mm2sSlimeCreatureInfectPct()
    { return 10; }

// Slime creatures have telepathic communication with their own kind in a
// radius of up to 20"
inline int mm2sSlimeCreatureTelepathyInches()
    { return 20; }

// The attachment might (50%) be noticed by others in the vicinity
inline int mm2sOliveSlimeNoticePct()
    { return 50; }

// After 7-12 days the host begins a metamorphosis into vegetable creature
inline int mm2sOliveSlimeMetamorphDaysMin()
    { return 7; }

// After 7-12 days the host begins a metamorphosis into vegetable creature
inline int mm2sOliveSlimeMetamorphDaysMax()
    { return 12; }

// Intake of food must be doubled or the host body wastes away (10% of hit
// points per day)
inline int mm2sOliveSlimeWasteHpPctPerDay()
    { return 10; }

// Slime creatures are harmed by acid, freezing cold, fire and magic missile
// spells
inline bool mm2sSlimeCreatureHarmedByAcid()
    { return true; }

// Slime creatures can use their cunning to lay traps
inline bool mm2sSlimeCreatureTrapLayer()
    { return true; }

// Olive slime can be harmed only by acid, freezing cold, fire, or by a cure
// disease spell
inline bool mm2sOliveSlimeCureDiseaseKills()
    { return true; }

// Green slime and olive slime will attack and neutralize each other
inline bool mm2sOliveSlimeNeutralizesGreenSlime()
    { return true; }

// ---- the snake pins (the R813 MM2 letter S walk) ----

// The Snake, Constrictor xpValue (the print 3+2 base 85 + 4/hp x avgHp 12)
inline int mm2sSnakeConstrictorXpValue()
    { return 133; }

// The Snake, Constrictor xp level
inline int mm2sSnakeConstrictorXpLevel()
    { return 3; }

// The Snake, Poisonous xpValue (the print 2+1 base 255 + 3/hp x avgHp 8)
inline int mm2sSnakePoisonousXpValue()
    { return 279; }

// The Snake, Poisonous xp level
inline int mm2sSnakePoisonousXpLevel()
    { return 5; }

// A humanoid can escape coiling attack by a roll to open doors, penalized by
// +1 to the roll
inline int mm2sSnakeConstrictorEscapePenalty()
    { return 1; }

// The 7-row poisonous snake save-modifier table
inline int mm2sSnakePoisonRows()
    { return 7; }

// Die roll 1-4: +3 modifier, sickness + incapacitation 2-8 days
inline int mm2sSnakePoisonSaveMod1()
    { return 3; }

// Die roll 5-8: +2 modifier, death
inline int mm2sSnakePoisonSaveMod2()
    { return 2; }

// Die roll 9-11: +1 modifier, 2-8 points of damage
inline int mm2sSnakePoisonSaveMod3()
    { return 1; }

// Die roll 12-14: +/-0 modifier, 3-12 points of damage
inline int mm2sSnakePoisonSaveMod4()
    { return 0; }

// Die roll 15-17: -1 modifier, sickness + incapacitation 1-4 days
inline int mm2sSnakePoisonSaveMod5()
    { return -1; }

// Die roll 18-19: -2 modifier, sickness + incapacitation 2-12 days
inline int mm2sSnakePoisonSaveMod6()
    { return -2; }

// Die roll 20: -3 modifier, death
inline int mm2sSnakePoisonSaveMod7()
    { return -3; }

// ---- the solar pins (the R813 MM2 letter S walk) ----

// The Solar xpValue (the print 177 hp base 95000 + 35/hp x avgHp 177)
inline int mm2sSolarXpValue()
    { return 101195; }

// The Solar xp level
inline int mm2sSolarXpLevel()
    { return 10; }

// Solars regenerate at a rate of 7 hit points per round
inline int mm2sSolarRegenPerRound()
    { return 7; }

// Consider each solar a 17th+ level as a fighter
inline int mm2sSolarFighterLevel()
    { return 17; }

// Consider each solar to have a dexterity of 24
inline int mm2sSolarDexterity()
    { return 24; }

// Solars have spell-like abilities equal to a 12th level cleric, druid,
// magic-user and illusionist
inline int mm2sSolarSpellClassLevel()
    { return 12; }

// Each solar has a huge composite bow (36" range)
inline int mm2sSolarBowRangeInches()
    { return 36; }

// The solar sword is equal to +5 with qualities of dancing and sharpness
inline int mm2sSolarSwordPlus()
    { return 5; }

// Only +5 or better weapons affect solars
inline int mm2sSolarWeaponPlusMinimum()
    { return 5; }

// A solar can summon 1-2 ki-rin, phoenix or greater titans
inline int mm2sSolarSummonMin()
    { return 1; }

// A solar can summon 1-2 ki-rin, phoenix or greater titans
inline int mm2sSolarSummonMax()
    { return 2; }

// A destroyed solar's spirit re-forms a corporeal body in a full 7 decades
inline int mm2sSolarReformDecades()
    { return 7; }

// Acid does not harm solars
inline bool mm2sSolarAcidImmune()
    { return true; }

// Solars are never surprised and always strike first against opponents with
// less than 22 dexterity
inline bool mm2sSolarNeverSurprised()
    { return true; }

// Solars are immune to death spells, death magic and life level loss
inline bool mm2sSolarDeathMagicImmune()
    { return true; }

// ---- the solifugid pins (the R813 MM2 letter S walk) ----

// The Solifugid, Large xpValue (the print 3+3 base 85 + 4/hp x avgHp 13)
inline int mm2sSolifugidLargeXpValue()
    { return 137; }

// The Solifugid, Large xp level
inline int mm2sSolifugidLargeXpLevel()
    { return 3; }

// The Solifugid, Huge xpValue (the print 5+5 base 225 + 6/hp x avgHp 22)
inline int mm2sSolifugidHugeXpValue()
    { return 357; }

// The Solifugid, Huge xp level
inline int mm2sSolifugidHugeXpLevel()
    { return 4; }

// The Solifugid, Giant xpValue (the print 6+6 base 350 + 8/hp x avgHp 27)
inline int mm2sSolifugidGiantXpValue()
    { return 566; }

// The Solifugid, Giant xp level
inline int mm2sSolifugidGiantXpLevel()
    { return 5; }

// Solifugids have 10 legs, the first pair ending in sucker-like clamps
inline int mm2sSolifugidLegs()
    { return 10; }

// The beak attack gains +3 on its to-hit roll against a held character
inline int mm2sSolifugidBeakBonus()
    { return 3; }

// Outdoors there is a 60% chance solifugids are of the nocturnal variety
inline int mm2sSolifugidNocturnalPct()
    { return 60; }

// Nocturnal solifugids attack at -2 when in daylight
inline int mm2sSolifugidDaylightPenalty()
    { return 2; }

// The only way to break the grip is to sever a limb by rolling 3 or more
// above the number needed to hit
inline int mm2sSolifugidSeverMargin()
    { return 3; }

// Nocturnal solifugids flee from lights brighter than a torch or lantern
inline bool mm2sSolifugidFleeBrightLight()
    { return true; }

// ---- the spectator pins (the R813 MM2 letter S walk) ----

// The Spectator xpValue (the print 4+4 base 350 + 9/hp x avgHp 18)
inline int mm2sSpectatorXpValue()
    { return 512; }

// The Spectator xp level
inline int mm2sSpectatorXpLevel()
    { return 5; }

// Once given a task the spectator will guard for up to 101 years
inline int mm2sSpectatorGuardYears()
    { return 101; }

// The guarded treasure is 90% likely to be a magic item or worth at least
// 15,000 gp
inline int mm2sSpectatorGuardMagicItemPct()
    { return 90; }

// The guarded treasure is 90% likely to be a magic item or worth at least
// 15,000 gp
inline int mm2sSpectatorTreasureValueGp()
    { return 15000; }

// Any general blow is 70% likely to hit the body
inline int mm2sSpectatorBodyHitPct()
    { return 70; }

// Hits on the eye stalks or central eye occur 30% of the time (20% stalks,
// 10% central)
inline int mm2sSpectatorEyeHitPct()
    { return 30; }

// The central eye can reflect 1 spell per round back to the caster
inline int mm2sSpectatorCentralReflectPerRound()
    { return 1; }

// Spectator initiative is made rolling a 1d8 instead of a 1d6 in all cases
inline int mm2sSpectatorInitiativeDie()
    { return 8; }

// The spectator senses psionic disciplines, powers and spell-like effects at
// 240 feet
inline int mm2sSpectatorSenseRangeFeet()
    { return 240; }

// The spectator's destroyed eyes regenerate in 1 day
inline int mm2sSpectatorEyeRegenDays()
    { return 1; }

// When the central eye is undamaged it can reflect a fired spell (only within
// a 60 degree arc)
inline bool mm2sSpectatorCentralEyeReflect()
    { return true; }

// Spectators are summoned from Nirvana by monster summoning V and the
// sacrifice of 3 small beholder eyes
inline bool mm2sSpectatorSummons()
    { return true; }

// ---- the giant marine spider pins (the R813 MM2 letter S walk) ----

// The Spider, Giant Marine xpValue (the print 7+7 base 650 + 12/hp x avgHp
// 31)
inline int mm2sSpiderGiantMarineXpValue()
    { return 1022; }

// The Spider, Giant Marine xp level
inline int mm2sSpiderGiantMarineXpLevel()
    { return 6; }

// The giant marine spider paralyzes its prey by poisonous bite and carries it
// back to the nest lair
inline bool mm2sSpiderMarineParalyticBite()
    { return true; }

// ---- the spriggan pins (the R813 MM2 letter S walk) ----

// The Spriggan xpValue (the print 4 (8+4) base 1000 + 10/hp x avgHp 14)
inline int mm2sSprigganXpValue()
    { return 1140; }

// The Spriggan xp level
inline int mm2sSprigganXpLevel()
    { return 6; }

// All spriggans in small form have the abilities of an 8th-level gnome thief
// of 18 dexterity
inline int mm2sSprigganThiefLevel()
    { return 8; }

// All spriggans in small form have the abilities of an 8th-level gnome thief
// of 18 dexterity
inline int mm2sSprigganDexterity()
    { return 18; }

// The spriggan thief percentages: pick pockets 75
inline int mm2sSprigganPickPocketsPct()
    { return 75; }

// The spriggan thief percentages: open locks 78
inline int mm2sSprigganOpenLocksPct()
    { return 78; }

// The spriggan thief percentages: find/remove traps 70
inline int mm2sSprigganFindTrapsPct()
    { return 70; }

// The spriggan thief percentages: move silently 77
inline int mm2sSprigganMoveSilentlyPct()
    { return 77; }

// The spriggan thief percentages: hide in shadows 64
inline int mm2sSprigganHideShadowsPct()
    { return 64; }

// The spriggan thief percentages: hear noise 35
inline int mm2sSprigganHearNoisePct()
    { return 35; }

// The spriggan thief percentages: climb walls 81
inline int mm2sSprigganClimbWallsPct()
    { return 81; }

// The spriggan thief percentages: read languages 40
inline int mm2sSprigganReadLanguagesPct()
    { return 40; }

// Back stabbing is for triple dagger damage and can only be performed in
// small form
inline int mm2sSprigganBackstabMultiplier()
    { return 3; }

// The spriggan scare is at -2 on saving throws due to ugliness
inline int mm2sSprigganScareSavePenalty()
    { return 2; }

// ---- the squealer pins (the R813 MM2 letter S walk) ----

// The Squealer xpValue (the print 12 base 3000 + 16/hp x avgHp 42)
inline int mm2sSquealerXpValue()
    { return 3672; }

// The Squealer xp level
inline int mm2sSquealerXpLevel()
    { return 5; }

// When amidst foliage the squealer's bulk is 75% invisible
inline int mm2sSquealerCamouflagePct()
    { return 75; }

// The squealer is 50% likely to surprise a victim
inline int mm2sSquealerSurprisePct()
    { return 50; }

// Attacking by surprise the squealer adds +2 to each attack both to hit and
// to damage
inline int mm2sSquealerSurpriseBonus()
    { return 2; }

// A held victim takes 5-8 points of crushing damage the next round
inline int mm2sSquealerCrushDamageMin()
    { return 5; }

// A held victim takes 5-8 points of crushing damage the next round
inline int mm2sSquealerCrushDamageMax()
    { return 8; }

// The squealer has 18/00 strength and weighs 400 or more pounds
inline int mm2sSquealerWeightLb()
    { return 400; }

// Young squealers have 1-2 hit points per die and can bite only, doing 1-4
// points of damage
inline int mm2sSquealerYoungHpPerDie()
    { return 2; }

// A squealer can imitate many sounds perfectly to attract prey
inline bool mm2sSquealerSoundImitation()
    { return true; }

// ---- the squirrel pins (the R813 MM2 letter S walk) ----

// The Squirrel, Giant Black xpValue (the print 1+1 base 20 + 2/hp x avgHp 4)
inline int mm2sSquirrelGiantBlackXpValue()
    { return 28; }

// The Squirrel, Giant Black xp level
inline int mm2sSquirrelGiantBlackXpLevel()
    { return 1; }

// The Squirrel, Ordinary xpValue (the print 1 hp base 0 + 0/hp x avgHp 1)
inline int mm2sSquirrelOrdinaryXpValue()
    { return 0; }

// The Squirrel, Ordinary xp level
inline int mm2sSquirrelOrdinaryXpLevel()
    { return 1; }

// The Squirrel, Carnivorous Flying xpValue (the print 1-7 hp base 10 + 1/hp x
// avgHp 4)
inline int mm2sSquirrelCarnivorousFlyingXpValue()
    { return 14; }

// The Squirrel, Carnivorous Flying xp level
inline int mm2sSquirrelCarnivorousFlyingXpLevel()
    { return 1; }

// Giant black squirrel lairs are always in hollows of trees 20 feet or more
// above the ground
inline int mm2sSquirrelGiantLairHeightFeet()
    { return 20; }

// The flying squirrel range is 5 feet for every foot of altitude from which
// it jumps
inline int mm2sSquirrelFlyingGlideRatio()
    { return 5; }

// The carnivorous flying squirrel surprises on 4 in 6 during a flying attack
inline int mm2sSquirrelFlyingSurpriseChanceIn6()
    { return 4; }

// If surprise is achieved during a flying attack they make their initial
// attack as 2 hit dice monsters
inline int mm2sSquirrelFlyingSurpriseHd()
    { return 2; }

// Carnivorous flying squirrels attack only when they have 2 to 1 odds or
// better
inline int mm2sSquirrelFlyingOddsMin()
    { return 2; }

// Giant black squirrels steal small, shiny objects to secrete in their nests
inline bool mm2sSquirrelGiantStealsShiny()
    { return true; }

// ---- the stegocentipede pins (the R813 MM2 letter S walk) ----

// The Stegocentipede xpValue (the print 9 base 1700 + 12/hp x avgHp 31)
inline int mm2sStegocentipedeXpValue()
    { return 2072; }

// The Stegocentipede xp level
inline int mm2sStegocentipedeXpLevel()
    { return 7; }

// The chitinous plates give armor class 3 in most (75%) combat situations
inline int mm2sStegoPlateAcPct()
    { return 75; }

// Victims not slain by the tail take 3-12 points of damage
inline int mm2sStegoTailDamageMin()
    { return 3; }

// Victims not slain by the tail take 3-12 points of damage
inline int mm2sStegoTailDamageMax()
    { return 12; }

// The spiked front plates inflict 1-6 hit points damage on attackers of the
// head
inline int mm2sStegoSpikeDamageMin()
    { return 1; }

// The spiked front plates inflict 1-6 hit points damage on attackers of the
// head
inline int mm2sStegoSpikeDamageMax()
    { return 6; }

// Up to 3 attackers can be subject to the defense attack
inline int mm2sStegoSpikeAttackersMax()
    { return 3; }

// The tail club can lash 6 feet in any direction to strike opponents
inline int mm2sStegoTailReachFeet()
    { return 6; }

// Victims struck by the tail must save vs. poison or be slain
inline bool mm2sStegoTailPoison()
    { return true; }

// ---- the stench kow pins (the R813 MM2 letter S walk) ----

// The Stench Kow xpValue (the print 3+3 base 150 + 4/hp x avgHp 13)
inline int mm2sStenchKowXpValue()
    { return 202; }

// The Stench Kow xp level
inline int mm2sStenchKowXpLevel()
    { return 3; }

// For every 5 beasts encountered, 1 will be a bull
inline int mm2sStenchKowBullsPer()
    { return 5; }

// Bulls have at least 6 points per hit die
inline int mm2sStenchKowBullHpPerDie()
    { return 6; }

// Bulls never do less than 5 points of damage
inline int mm2sStenchKowBullMinDamage()
    { return 5; }

// Bulls are treated as monsters of 6 hit dice
inline int mm2sStenchKowBullHd()
    { return 6; }

// The trampling to-hit causes 2-12 points of damage if successful
inline int mm2sStenchKowTrampleDamageMin()
    { return 2; }

// The trampling to-hit causes 2-12 points of damage if successful
inline int mm2sStenchKowTrampleDamageMax()
    { return 12; }

// A charging stench kow that hits does double damage (at least 10 points for
// a bull)
inline int mm2sStenchKowChargeDamageMultiplier()
    { return 2; }

// The stinking cloud check must be made every 3 rounds of close-quarters
// exposure
inline int mm2sStenchKowStenchCheckRounds()
    { return 3; }

// Charging requires at least a 1" move
inline int mm2sStenchKowChargeMoveInches()
    { return 1; }

// A herd will contain 5-30 young, which have no attack form
inline int mm2sStenchKowHerdYoungMin()
    { return 5; }

// A herd will contain 5-30 young, which have no attack form
inline int mm2sStenchKowHerdYoungMax()
    { return 30; }

// Stench kine are immune to all forms (including magical) of cold
inline bool mm2sStenchKowColdImmune()
    { return true; }

// Stench kine are immune to all forms (including magical) of fire
inline bool mm2sStenchKowFireImmune()
    { return true; }

// Stench kine are immune to all forms (including magical) of poison and
// poison gas
inline bool mm2sStenchKowPoisonGasImmune()
    { return true; }

// ---- the stone guardian pins (the R813 MM2 letter S walk) ----

// The Stone Guardian xpValue (the print 4+4 base 550 + 8/hp x avgHp 18)
inline int mm2sStoneGuardianXpValue()
    { return 694; }

// The Stone Guardian xp level
inline int mm2sStoneGuardianXpLevel()
    { return 6; }

// There is a 20% chance per activation that the precise instructions will be
// disregarded
inline int mm2sStoneGuardianDisregardPct()
    { return 20; }

// The special ring keeps all within a 10-foot radius immune to its guardian's
// attack
inline int mm2sStoneGuardianRingRadiusFeet()
    { return 10; }

// The stone guardian takes only one-quarter damage from edged weapons
inline int mm2sStoneGuardianEdgedDamageDivisor()
    { return 4; }

// The stone guardian takes half-damage from cold, fire and electrical-based
// spells
inline int mm2sStoneGuardianElementDamageDivisor()
    { return 2; }

// Normal missiles cannot harm the stone guardian at all
inline bool mm2sStoneGuardianMissileImmune()
    { return true; }

// The stone guardian cannot be poisoned, held, charmed, paralyzed or affected
// by fear - no mind, no living body
inline bool mm2sStoneGuardianMindless()
    { return true; }

// Stone to flesh, transmute rock to mud, stone shape or dig spells kill it
// instantly with no saving throw
inline bool mm2sStoneGuardianTransmuteKills()
    { return true; }

// ---- the storoper pins (the R813 MM2 letter S walk) ----

// The Storoper xpValue (the print 6 base 500 + 6/hp x avgHp 21)
inline int mm2sStoroperXpValue()
    { return 626; }

// The Storoper xp level
inline int mm2sStoroperXpLevel()
    { return 6; }

// The storoper is a cigar-shaped creature with 6 tentacles and a gaping maw
inline int mm2sStoroperTentacles()
    { return 6; }

// The storoper can inject victims only twice per day
inline int mm2sStoroperVenomUsesPerDay()
    { return 2; }

// The drugged defenders wander aimlessly until the venom wears off - 10 turns
inline int mm2sStoroperVenomDurationTurns()
    { return 10; }

// Each tentacle hit causes weakness (50% loss of strength in 1-3 rounds)
inline int mm2sStoroperStrengthLossPct()
    { return 50; }

// During each round the victim is dragged 10 feet closer to its maw
inline int mm2sStoroperDragFeetPerRound()
    { return 10; }

// The storoper can sense movement up to 200 feet away
inline int mm2sStoroperSenseRangeFeet()
    { return 200; }

// If anything approaches within 50 feet the storoper shoots out its tentacles
inline int mm2sStoroperAttackRangeFeet()
    { return 50; }

// The first 2 victims successfully attacked are injected with venom through
// the tentacles - no saving throw
inline bool mm2sStoroperVenomNoSave()
    { return true; }

// Normal missile fire will not injure storopers, but magic missiles and
// hand-held weapons will
inline bool mm2sStoroperMissileImmune()
    { return true; }

// ---- the giant sundew pins (the R813 MM2 letter S walk) ----

// The Sundew, Giant xpValue (the print 8 base 1075 + 10/hp x avgHp 28)
inline int mm2sSundewGiantXpValue()
    { return 1355; }

// The Sundew, Giant xp level
inline int mm2sSundewGiantXpLevel()
    { return 7; }

// Up to 6 tendrils may attack each creature in range each round
inline int mm2sSundewTendrilsPerVictim()
    { return 6; }

// For every 3 tendrils that strike, the victim suffers -1 on its subsequent
// to-hit rolls
inline int mm2sSundewToHitPenaltyPerTendrils()
    { return 3; }

// The cumulative to-hit penalty per 3 tendrils struck
inline int mm2sSundewToHitPenalty()
    { return 1; }

// A mouth-and-nose-clogged character suffocates in 2-4 rounds unless the sap
// is removed
inline int mm2sSundewSuffocateRoundsMin()
    { return 2; }

// A mouth-and-nose-clogged character suffocates in 2-4 rounds unless the sap
// is removed
inline int mm2sSundewSuffocateRoundsMax()
    { return 4; }

// The sap enzyme acid causes 1 point of damage per tendril each round until
// the tendril is broken
inline int mm2sSundewEnzymeDamage()
    { return 1; }

// Due to the sticky exterior, missile and fire-based attacks only do
// half-damage
inline bool mm2sSundewHalfDamageFromMissiles()
    { return true; }

// The sap dissolves and becomes harmless if soaked with vinegar or alcohol
inline bool mm2sSundewVinegarNeutralizes()
    { return true; }

// ---- the swan and swanmay pins (the R813 MM2 letter S walk) ----

// The Swan xpValue (the print 1+2 base 0 + 0/hp x avgHp 5)
inline int mm2sSwanXpValue()
    { return 0; }

// The Swan xp level
inline int mm2sSwanXpLevel()
    { return 1; }

// The Swanmay xpValue (the print 2 or more base 0 + 0/hp x avgHp 7)
inline int mm2sSwanmayXpValue()
    { return 0; }

// The Swanmay xp level
inline int mm2sSwanmayXpLevel()
    { return 0; }

// The swan attack mode is 50% likely to blind and disorient an opponent
inline int mm2sSwanBlindPct()
    { return 50; }

// The approach of any danger will be noted 90% of the time
inline int mm2sSwanDangerSensePct()
    { return 90; }

// Swans are surprised only 1 in 10
inline int mm2sSwanSurpriseChanceIn10()
    { return 10; }

// If there are eggs, the nest will contain 1-3
inline int mm2sSwanEggsMin()
    { return 1; }

// If there are eggs, the nest will contain 1-3
inline int mm2sSwanEggsMax()
    { return 3; }

// Immature cygnets number 1-2 per mated pair
inline int mm2sSwanCygnetsMin()
    { return 1; }

// Immature cygnets number 1-2 per mated pair
inline int mm2sSwanCygnetsMax()
    { return 2; }

// To find the level of a swanmay, 2d6 are rolled
inline int mm2sSwanmayLevelDice()
    { return 2; }

// The swanmay level runs between 1st (2) and 11th (12)
inline int mm2sSwanmayLevelMin()
    { return 1; }

// The swanmay level runs between 1st (2) and 11th (12)
inline int mm2sSwanmayLevelMax()
    { return 11; }

// A swanmay can be harmed only by +1 or better magic weapons when in swan
// form
inline int mm2sSwanmayWeaponPlusMin()
    { return 1; }

// In swan form she has a magic resistance of 2% per hit die
inline int mm2sSwanmayMrPerHitDie()
    { return 2; }

// Both cob and pen will aggressively threaten or attack when the territory is
// invaded
inline bool mm2sSwanTerritorial()
    { return true; }

// In human form, all swanmays are rangers
inline bool mm2sSwanmayRanger()
    { return true; }

// Swanmays attract no followers
inline bool mm2sSwanmayNoFollowers()
    { return true; }

// ---- the swordfish pins (the R813 MM2 letter S walk) ----

// The Swordfish xpValue (the print 1+1, 2+2, or 3+3 base 35 + 3/hp x avgHp 4)
inline int mm2sSwordfishXpValue()
    { return 47; }

// The Swordfish xp level
inline int mm2sSwordfishXpLevel()
    { return 2; }

// Smaller swordfish are kept as pets and used as guards by aquatic elves and
// dolphin communities
inline bool mm2sSwordfishTrainedGuards()
    { return true; }

// ---- the taer pins (the R813 MM2 letter S walk) ----

// The Taer xpValue (the print 3+6 base 150 + 4/hp x avgHp 16)
inline int mm2sTaerXpValue()
    { return 214; }

// The Taer xp level
inline int mm2sTaerXpLevel()
    { return 3; }

// Any creature within 10 feet of a taer must save vs. breath weapon
inline int mm2sTaerStenchRadiusFeet()
    { return 10; }

// The disorientation and nausea lasts 2-5 hours
inline int mm2sTaerStenchHoursMin()
    { return 2; }

// The disorientation and nausea lasts 2-5 hours
inline int mm2sTaerStenchHoursMax()
    { return 5; }

// Attacks against a taer are penalized by -2 to hit probability
inline int mm2sTaerToHitPenalty()
    { return 2; }

// Attacks against a taer are penalized by -1 damage
inline int mm2sTaerDamagePenalty()
    { return 1; }

// There is a 15% chance for real treasure captured from some human victims
inline int mm2sTaerTreasurePct()
    { return 15; }

// If such treasure exists, there is a 10% chance for 1 magic item to be
// included, especially a weapon
inline int mm2sTaerMagicItemPct()
    { return 10; }

// 50% of taers have crude spears which they hurl prior to closing for melee
inline int mm2sTaerSpearPct()
    { return 50; }

// Spear hurling is at +1 to hit
inline int mm2sTaerSpearToHitBonus()
    { return 1; }

// Spear hurling is at +3 to damage
inline int mm2sTaerSpearDamageBonus()
    { return 3; }

// The fatty excretion aids taers to withstand cold, even of the magical sort
inline bool mm2sTaerColdImmune()
    { return true; }

// ---- the shedu (greater) head pins (the R813 MM2 letter S walk) ----

// The greater shedu prior-owned head: hit dice 14+14 (the MM1 s/shedu.lua
// print owns the def)
inline int mm2sSheduGreaterHdNum()
    { return 14; }

// The greater shedu prior-owned head: hit dice 14+14 (the MM1 s/shedu.lua
// print owns the def)
inline int mm2sSheduGreaterHdBonus()
    { return 14; }

// The greater shedu prior-owned head: armor class 2
inline int mm2sSheduGreaterAc()
    { return 2; }

// The greater shedu prior-owned head: magic resistance 50%
inline int mm2sSheduGreaterMrPct()
    { return 50; }

// The greater shedu has 7 minor and 4 major psionic disciplines
inline int mm2sSheduGreaterMinorDisciplines()
    { return 7; }

// The greater shedu has 7 minor and 4 major psionic disciplines
inline int mm2sSheduGreaterMajorDisciplines()
    { return 4; }

// The greater shedu performs its disciplines at 14th level of mastery
inline int mm2sSheduGreaterMasteryLevel()
    { return 14; }

// The greater shedu prior-owned head: psionic ability 120-150
inline int mm2sSheduGreaterPsionicMin()
    { return 120; }

// The greater shedu prior-owned head: psionic ability 120-150
inline int mm2sSheduGreaterPsionicMax()
    { return 150; }

// The greater shedu prior-owned head: IX/5250 + 20/hp x avgHp 63 (the floor
// formula)
inline int mm2sSheduGreaterXpValue()
    { return 6510; }

// The greater shedu prior-owned head: IX/5250 + 20/hp
inline int mm2sSheduGreaterXpLevel()
    { return 9; }

// ---- the SStats grid pins (the R813 MM2 letter S walk) ----

// The armor class cells (the sirine 3 or less reads 3, the spectator Body 4,
// eyes 7 reads 4, the spriggan 3 (5) and the stegocentipede 3/6 read the
// first int, the shade As original creature the 9 default, the solar 9 kept
// per print-wins against the transcription -9)
inline int mm2sSStatAc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 5;
        case 5:
            return 9;
        case 6:
            return 3;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 9;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 8;
        case 23:
            return 7;
        case 24:
            return 3;
        case 25:
            return 2;
        case 26:
            return 2;
        case 27:
            return 0;
        case 28:
            return 7;
        case 29:
            return 7;
        case 30:
            return 7;
        case 31:
            return 6;
        case 32:
            return 4;
        default:
            return 0;
        }
    }

// The hit dice num cells (the scum creeper, skunk, ordinary squirrel,
// carnivorous flying squirrel and solar ride the flat-hp path - hdNum 0,
// avgHp the print hp; the skeleton animal 1-1 reads 1 die; the sirine 4-7,
// the spriggan 4 (8+4), the slime creature 3+2-of-3+2-5+2-or-8+2 and the
// swordfish 1+1-of-1+1-2+2-or-3+3 read the first number)
inline int mm2sSStatHd(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 3;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 4;
        case 18:
            return 7;
        case 19:
            return 4;
        case 20:
            return 12;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 9;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 6;
        case 28:
            return 8;
        case 29:
            return 1;
        case 30:
            return 2;
        case 31:
            return 1;
        case 32:
            return 3;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the skeleton animal 1-1 reads -1 - the buckawn
// precedent; the taer 3+6 reads +6)
inline int mm2sSStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return -1;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 3;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 4;
        case 18:
            return 7;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 2;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 6;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula; the flat-hp reads
// carry the print hp: the scum creeper 5, the skunk 2, the ordinary squirrel
// 1, the carnivorous flying squirrel 4, the solar 177; the shade the nil
// block 0)
inline int mm2sSStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 9;
        case 2:
            return 18;
        case 3:
            return 5;
        case 4:
            return 13;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 12;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 8;
        case 13:
            return 177;
        case 14:
            return 13;
        case 15:
            return 22;
        case 16:
            return 27;
        case 17:
            return 18;
        case 18:
            return 31;
        case 19:
            return 14;
        case 20:
            return 42;
        case 21:
            return 4;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 31;
        case 25:
            return 13;
        case 26:
            return 18;
        case 27:
            return 21;
        case 28:
            return 28;
        case 29:
            return 5;
        case 30:
            return 7;
        case 31:
            return 4;
        case 32:
            return 16;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the olive slime 0 clamps to 1, the
// sundew Special and the swanmay As swan or human floor at 1, the solifugid 2
// or 1 and the taer 3 or 1 read the max, the stegocentipede 1 and 1 sums 2)
inline int mm2sSStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 3;
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
            return 2;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 2;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 3;
        default:
            return 0;
        }
    }

// The xp base cells (the shade, ordinary squirrel, swan and swanmay read 0 -
// the phantom precedent)
inline int mm2sSStatXp(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 90;
        case 2:
            return 165;
        case 3:
            return 14;
        case 4:
            return 75;
        case 5:
            return 0;
        case 6:
            return 350;
        case 7:
            return 10;
        case 8:
            return 4;
        case 9:
            return 110;
        case 10:
            return 330;
        case 11:
            return 85;
        case 12:
            return 255;
        case 13:
            return 95000;
        case 14:
            return 85;
        case 15:
            return 225;
        case 16:
            return 350;
        case 17:
            return 350;
        case 18:
            return 650;
        case 19:
            return 1000;
        case 20:
            return 3000;
        case 21:
            return 20;
        case 22:
            return 0;
        case 23:
            return 10;
        case 24:
            return 1700;
        case 25:
            return 150;
        case 26:
            return 550;
        case 27:
            return 500;
        case 28:
            return 1075;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 35;
        case 32:
            return 150;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the solar 35 the highest per-hp rate in the
// registry)
inline int mm2sSStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 3;
        case 13:
            return 35;
        case 14:
            return 4;
        case 15:
            return 6;
        case 16:
            return 8;
        case 17:
            return 9;
        case 18:
            return 12;
        case 19:
            return 10;
        case 20:
            return 16;
        case 21:
            return 2;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 12;
        case 25:
            return 4;
        case 26:
            return 8;
        case 27:
            return 6;
        case 28:
            return 10;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 3;
        case 32:
            return 4;
        default:
            return 0;
        }
    }

// The in-lair percentage cells (the loader luaGetInt accepts only
// lua_isnumber strings, so the print percent cells ride as the bare-numeral
// read - the R812 repair lesson; the selkie 0 or 90% and the shade Variable
// read 0)
inline int mm2sSStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 65;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 30;
        case 7:
            return 85;
        case 8:
            return 0;
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
            return 10;
        case 15:
            return 20;
        case 16:
            return 25;
        case 17:
            return 100;
        case 18:
            return 70;
        case 19:
            return 30;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 40;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 100;
        case 27:
            return 90;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 40;
        default:
            return 0;
        }
    }

// The move cells (the parseIntRange first-read: the sirine 12"//24" and the
// selkie 12"//36" read 12, the swan 3"/18" 3, the swordfish //24" 24, the
// squealer 12" @ 9" 12, the olive slime 0" 0)
inline int mm2sSStatMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 3;
        case 4:
            return 12;
        case 5:
            return 0;
        case 6:
            return 12;
        case 7:
            return 6;
        case 8:
            return 12;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 15;
        case 13:
            return 18;
        case 14:
            return 9;
        case 15:
            return 9;
        case 16:
            return 12;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 9;
        case 20:
            return 12;
        case 21:
            return 12;
        case 22:
            return 9;
        case 23:
            return 9;
        case 24:
            return 15;
        case 25:
            return 15;
        case 26:
            return 10;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 24;
        case 32:
            return 18;
        default:
            return 0;
        }
    }

// The magic resistance cells (the sirine 20% or more reads 20, the spectator
// 5% and the solar 85% their percents, the swanmay 2% per hit die 2, every
// Standard/See below/Variable cell 0)
inline int mm2sSStatMr(int b)
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
            return 20;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 85;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 5;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 2;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
