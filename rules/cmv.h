// =========================================================================================
// Adnd1 - rules/cmv.h
// The comedy and small-variants round - Davidson's Idiot (folio 28), Carner,
// Cannon and Simon's Jester (folios 28-29) and Cline's dexterity combat mods
// (folio 30)
// census 821 -> 822.
//
// Pinned from The Dragon Vol. 1 No. 3 (October 1976): folio 28, Gordon
// Davidson's Two Penultimate Sub-Classes, the Idiot - the 160-gold hireling
// bought to confuse the enemy into running away, attacking walls, committing
// Hari Kari or eating its treasure, with the midget add-on, the confusion
// grids, the Exceptionally BAD Abilities chart, the twelve-level ladder from
// Dummy to Idiot, and the constitution prime requisite; folios 28-29, the new
// category Jesters by Charles Carner, William Cannon and Pete Simon - the
// 15/15/6 requisites, the racial caps with the Dwarves' infinite jestership,
// the joke weapons from the smelly sock to the dirty underwear, the two
// intelligence-based saving-throw tables, the fourteen-row experience grid,
// and the eight levels of jokes from Giggle Spell through Voice Projector;
// folio 30, Steve Cline's Combat Modifications for Dexterity - the
// twelve-band hand-held/missile/damage/defense grid. The editor's standing
// caution rides: none of this is official.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// printed 'N' entries in Cline's grid CONVERT to 0, the '05%' to 5 and the
// '00' convention to 100, the half-percent wound penalty pins as five tenths
// and the half-damage spells as 50 percent with the quarter-turn damage as 25
// percent, every conversion noted, never silent; the Armor Class -4 of Body
// Contortion II pins as 4 with the sign in the comment; the Idiot confusion
// grid's odd monster rows, its truncated 12th column, the Jester experience
// grid's unlabeled column semantics and Cline's four percent-band rows ride
// AS SCANNED, garbles and all, no figure pixels to check; the comedy round
// rides the variant layer against the engine's canon class frame, never a
// rewrite.
//
namespace rules {

// ---- the Idiot (folio 28) ----

// an Idiot is obtained by paying 160 gold pieces at the beginning of the game
// or at a city, if one is present (folio 28)
inline int cmvIdiotCostGold()
    { return 160; }

// the 50 percent chance a city has an Idiot for hire (folio 28)
inline int cmvIdiotCityFindPct()
    { return 50; }

// the player also has the opportunity to buy a midget for 200 gold pieces
// (folio 28)
inline int cmvMidgetCostGold()
    { return 200; }

// the midget adds 5 percent to all base chances (folio 28)
inline int cmvMidgetBonusPct()
    { return 5; }

// the confusion lasts 3 melee turns (folio 28)
inline int cmvIdiotConfuseTurns()
    { return 3; }

// there is a 15 percent chance that the confused monster will attack anyhow
// (folio 28)
inline int cmvIdiotAttackAnyhowPct()
    { return 15; }

// the constitution threshold for the confusion bonus - 12 (folio 28)
inline int cmvIdiotConThreshold()
    { return 12; }

// for each constitution point above 12 add 1 point on chances to confuse
// (folio 28)
inline int cmvIdiotConBonusPerPoint()
    { return 1; }

// an Idiot can take his Wisdom and Intelligence down to 6 (folio 28)
inline int cmvIdiotWisIntFloor()
    { return 6; }

// the Idiot trades 3 Wisdom for 1 Constitution (folio 28)
inline int cmvIdiotTradeWisRatio()
    { return 3; }

// the Idiot trades 4 Intelligence for 1 Constitution (folio 28)
inline int cmvIdiotTradeIntRatio()
    { return 4; }

// the armor-effectiveness threshold level - above 9 (folio 28)
inline int cmvIdiotLevelThreshold()
    { return 9; }

// for each level above 9 the Idiot loses 5 percent effectiveness in armor
// (folio 28)
inline int cmvIdiotArmorLosePctPerLevel()
    { return 5; }

// after each confusion attempt - a Tantrum - the Idiot must rest 2 days
// (folio 28)
inline int cmvIdiotRestDays()
    { return 2; }

// the Idiot must be paid 10 gold pieces on the spot to play, otherwise he
// will hold his breath until he turns blue and won't play (folio 28)
inline int cmvIdiotPayGold()
    { return 10; }

// a wounded Idiot confuses at a half percent - pinned as five tenths of a
// percent, the conversion noted (folio 28)
inline int cmvIdiotWoundedTenthPct()
    { return 5; }

// a wounded Idiot must wait a week before trying again (folio 28)
inline int cmvIdiotWoundedWaitWeeks()
    { return 1; }

// the Idiot melees as a man -2 - pinned as 2, the sign carried in the comment
// (folio 28)
inline int cmvIdiotMeleeAsManMod()
    { return 2; }

// the Idiot delivers at best 1 point of damage (folio 28)
inline int cmvIdiotMaxDamage()
    { return 1; }

// the cmvIdiotFirstLevel table runs 7 rows (folio 28)
inline int cmvIdiotFirstLevelCount()
    { return 7; }

// the cmvIdiotConfuseGrid table runs 3 rows (folio 28)
inline int cmvIdiotConfuseGridCount()
    { return 3; }

// the cmvIdiotBadDex table runs 4 rows (folio 28)
inline int cmvIdiotBadDexCount()
    { return 4; }

// every 100 feet the Idiot will trip and fall, dropping everything he is
// carrying (folio 28)
inline int cmvIdiotFallDistanceFeet()
    { return 100; }

// dropped items break on a 1 out of 6 (folio 28)
inline int cmvIdiotBreakDie()
    { return 6; }

// the 1-in-6 chance the dropped articles break (folio 28)
inline int cmvIdiotBreakChance()
    { return 1; }

// the bloody-nose roll is 2 out of 6 per fall (folio 28)
inline int cmvIdiotNoseDie()
    { return 6; }

// the 2-out-of-6 chance of a bloody nose (folio 28)
inline int cmvIdiotNoseChance()
    { return 2; }

// the 1-in-10 chance per fall that the Idiot breaks an arm - pinned as 10
// percent, the conversion noted (folio 28)
inline int cmvIdiotArmPct()
    { return 10; }

// normal falling chance at average dexterity - 1 out of 10 (folio 28)
inline int cmvIdiotAvgFallOutOf10()
    { return 1; }

// normal falling chance at below-average dexterity - 2 out of 10 (folio 28)
inline int cmvIdiotBelowFallOutOf10()
    { return 2; }

// the cmvIdiotLadder table runs 12 rows (folio 28)
inline int cmvIdiotLadderCount()
    { return 12; }

// 200,001 additional points for each level above Idiot (folio 28)
inline int cmvIdiotAboveStepXp()
    { return 200001; }

// the Idiot's purpose is to confuse the enemy so that it will run away,
// attack a wall, commit Hari Kari, eat all its treasure or some related act,
// just so it will not attack the troop (folio 28)
inline bool cmvIdiotConfusePurpose()
    { return true; }

// the Idiot's prime requisite is constitution - so he can stay goofy (folio
// 28)
inline bool cmvIdiotConIsPrime()
    { return true; }

// there is only one Idiot per expedition (folio 28)
inline bool cmvIdiotOnePerExpedition()
    { return true; }

// the Idiot can wear full armor (folio 28)
inline bool cmvIdiotFullArmor()
    { return true; }

// the opposite occurs with cursed armor - the effectiveness penalty flips to
// a bonus (folio 28)
inline bool cmvIdiotCursedArmorOpposite()
    { return true; }

// the Idiot may not employ any weapons, though he may carry any articles and
// play with fire (folio 28)
inline bool cmvIdiotNoWeapons()
    { return true; }

// the Idiot's dexterity rolls SHIFT a band - an above-average dice score
// gives average dexterity, an average score below average, and a
// below-average score a roll on the Exceptionally BAD Abilities chart (folio
// 28)
inline bool cmvIdiotDexShifting()
    { return true; }

// the monster's level - 1 through 7 (folio 28)
inline int cmvIdFirstMonLevel(int b)
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
        default:
            return 9;
        }
    }

// the chance of confusing at the Idiot's first level - 65 down to 5 percent
// (folio 28)
inline int cmvIdFirstPct(int b)
    {
        switch (b) {
        case 0:
            return 65;
        case 1:
            return 55;
        case 2:
            return 45;
        case 3:
            return 35;
        case 4:
            return 20;
        case 5:
            return 10;
        case 6:
            return 5;
        default:
            return 9;
        }
    }

// the monster level - the even rows 2, 4 and 6 pin as scanned; the odd rows
// garble in the OCR's interleaved label column and ride unpinned, noted
// (folio 28)
inline int cmvIdGridMonLevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        default:
            return 9;
        }
    }

// the chance of confusing at Idiot level 1, by percent (folio 28)
inline int cmvIdGridIgL1(int b)
    {
        switch (b) {
        case 0:
            return 55;
        case 1:
            return 35;
        case 2:
            return 10;
        default:
            return 9;
        }
    }

// the chance at Idiot level 2 (folio 28)
inline int cmvIdGridIgL2(int b)
    {
        switch (b) {
        case 0:
            return 57;
        case 1:
            return 37;
        case 2:
            return 12;
        default:
            return 9;
        }
    }

// the chance at Idiot level 3 (folio 28)
inline int cmvIdGridIgL3(int b)
    {
        switch (b) {
        case 0:
            return 53;
        case 1:
            return 39;
        case 2:
            return 14;
        default:
            return 9;
        }
    }

// the chance at Idiot level 4 (folio 28)
inline int cmvIdGridIgL4(int b)
    {
        switch (b) {
        case 0:
            return 51;
        case 1:
            return 41;
        case 2:
            return 16;
        default:
            return 9;
        }
    }

// the chance at Idiot level 5 (folio 28)
inline int cmvIdGridIgL5(int b)
    {
        switch (b) {
        case 0:
            return 49;
        case 1:
            return 43;
        case 2:
            return 18;
        default:
            return 9;
        }
    }

// the chance at Idiot level 6 (folio 28)
inline int cmvIdGridIgL6(int b)
    {
        switch (b) {
        case 0:
            return 47;
        case 1:
            return 45;
        case 2:
            return 20;
        default:
            return 9;
        }
    }

// the chance at Idiot level 7 (folio 28)
inline int cmvIdGridIgL7(int b)
    {
        switch (b) {
        case 0:
            return 45;
        case 1:
            return 47;
        case 2:
            return 22;
        default:
            return 9;
        }
    }

// the chance at Idiot level 8 (folio 28)
inline int cmvIdGridIgL8(int b)
    {
        switch (b) {
        case 0:
            return 43;
        case 1:
            return 45;
        case 2:
            return 24;
        default:
            return 9;
        }
    }

// the chance at Idiot level 9 (folio 28)
inline int cmvIdGridIgL9(int b)
    {
        switch (b) {
        case 0:
            return 41;
        case 1:
            return 43;
        case 2:
            return 26;
        default:
            return 9;
        }
    }

// the chance at Idiot level 10 (folio 28)
inline int cmvIdGridIgL10(int b)
    {
        switch (b) {
        case 0:
            return 39;
        case 1:
            return 41;
        case 2:
            return 28;
        default:
            return 9;
        }
    }

// the chance at Idiot level 11 - the printed 12th column truncates in the OCR
// and rides unpinned, noted (folio 28)
inline int cmvIdGridIgL11(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 40;
        case 2:
            return 30;
        default:
            return 9;
        }
    }

// the percentile band's low roll (folio 28)
inline int cmvIdBadLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 76;
        case 3:
            return 91;
        default:
            return 9;
        }
    }

// the percentile band's high roll, the 00 convention pinned as 100 (folio 28)
inline int cmvIdBadHi(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 75;
        case 2:
            return 90;
        case 3:
            return 100;
        default:
            return 9;
        }
    }

// the chance of falling out of 10 (folio 28)
inline int cmvIdBadOutOf10(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 10;
        default:
            return 9;
        }
    }

// the level index - 1 through 12 (folio 28)
inline int cmvIdLvlIndex(int b)
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
        case 10:
            return 11;
        case 11:
            return 12;
        default:
            return 9;
        }
    }

// the experience points - Dummy at 0 through Idiot at 200,101 (folio 28)
inline int cmvIdLvlXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1001;
        case 2:
            return 2623;
        case 3:
            return 6157;
        case 4:
            return 9738;
        case 5:
            return 11432;
        case 6:
            return 19832;
        case 7:
            return 30876;
        case 8:
            return 61423;
        case 9:
            return 88749;
        case 10:
            return 120456;
        case 11:
            return 200101;
        default:
            return 9;
        }
    }

// ---- the Jester (folios 28-29) ----

// the Jester's Intelligence prime requisite - 15 or better (folios 28-29)
inline int cmvJesterIntMin()
    { return 15; }

// the Jester's Dexterity prime requisite - 15 or better (folios 28-29)
inline int cmvJesterDexMin()
    { return 15; }

// the Jester's Charisma prime requisite - 6 or less, pinned as 6 maximum, the
// conversion noted (folios 28-29)
inline int cmvJesterChaMax()
    { return 6; }

// Hobbits are limited to 10th level advancement (folios 28-29)
inline int cmvJesterHobbitMax()
    { return 10; }

// Elves can go only to 6th level - the Village Idiot (folios 28-29)
inline int cmvJesterElfMax()
    { return 6; }

// Men can reach only 5th level - the Fool (folios 28-29)
inline int cmvJesterMenMax()
    { return 5; }

// Other types can reach but 4th level - the Comic (folios 28-29)
inline int cmvJesterOtherMax()
    { return 4; }

// Jesters use a 4-sided hit die (folios 28-29)
inline int cmvJesterHitDieSides()
    { return 4; }

// a maximum of 10 dice (folios 28-29)
inline int cmvJesterHitDiceMax()
    { return 10; }

// after 10 dice add +1 per level (folios 28-29)
inline int cmvJesterHitDieAfterBonus()
    { return 1; }

// nine joke weapons - the smelly sock, dagger, acid-squirting flower, pillow,
// jester stick, laughing gas balls, pies, dirty underwear, and tomatoes or
// rotten fruit, the list carried in the audit comment (folios 28-29)
inline int cmvJesterWeaponCount()
    { return 9; }

// the smelly sock stuns 1-4 turns, save versus poison - the minimum (folios
// 28-29)
inline int cmvJesSockStunMin()
    { return 1; }

// the smelly sock stuns 1-4 turns - the maximum (folios 28-29)
inline int cmvJesSockStunMax()
    { return 4; }

// the dagger does 1-6 points - the maximum (folios 28-29)
inline int cmvJesDaggerMaxDamage()
    { return 6; }

// the dagger's range - 3 feet (folios 28-29)
inline int cmvJesDaggerRangeFeet()
    { return 3; }

// the pillow bursts on 1-2 of a six-sided die (folio 29)
inline int cmvJesPillowBurstDie()
    { return 6; }

// the pillow's burst roll - 1-2 (folio 29)
inline int cmvJesPillowBurstMax()
    { return 2; }

// the burst pillow blinds a 1-inch diameter for 3 turns (folio 29)
inline int cmvJesPillowBlindDiameter()
    { return 1; }

// the pillow burst blinds for 3 turns; if no burst, stuns 1 turn as a
// Morningstar (folio 29)
inline int cmvJesPillowBlindTurns()
    { return 3; }

// the non-bursting pillow stuns 1 turn as a Morningstar, the jester stick
// likewise (folio 29)
inline int cmvJesPillowStunTurns()
    { return 1; }

// the laughing gas balls' range - 30 feet (folio 29)
inline int cmvJesGasRangeFeet()
    { return 30; }

// the laughing gas causes uncontrollable laughter for 3 turns, save versus
// gas (folio 29)
inline int cmvJesGasLaughterTurns()
    { return 3; }

// the pies' range - 20 feet (folio 29)
inline int cmvJesPiesRangeFeet()
    { return 20; }

// the pies blind 1-4 turns - the minimum (folio 29)
inline int cmvJesPiesBlindMin()
    { return 1; }

// the pies blind 1-4 turns - the maximum (folio 29)
inline int cmvJesPiesBlindMax()
    { return 4; }

// the dirty underwear's range - 10 feet (folio 29)
inline int cmvJesUnderwearRangeFeet()
    { return 10; }

// the dirty underwear stuns 1-6 turns, save versus poison - the minimum
// (folio 29)
inline int cmvJesUnderwearStunMin()
    { return 1; }

// the dirty underwear stuns 1-6 turns - the maximum (folio 29)
inline int cmvJesUnderwearStunMax()
    { return 6; }

// the tomatoes or rotten fruit's range - 30 feet (folio 29)
inline int cmvJesTomatoRangeFeet()
    { return 30; }

// the tomatoes blind 1 turn (folio 29)
inline int cmvJesTomatoBlindTurns()
    { return 1; }

// the cmvJesterSavesHigh table runs 7 rows (folio 29)
inline int cmvJesterSavesHighCount()
    { return 7; }

// the cmvJesterSavesLow table runs 7 rows (folio 29)
inline int cmvJesterSavesLowCount()
    { return 7; }

// the cmvJesterXpGrid table runs 14 rows (folio 29)
inline int cmvJesterXpGridCount()
    { return 14; }

// Giggle Spell affects thinking creatures of less than 3 hit dice (folio 29)
inline int cmvJesGiggleHdMax()
    { return 3; }

// Giggle Spell causes laughter for 1 turn (folio 29)
inline int cmvJesGiggleTurns()
    { return 1; }

// victims are -4 to hit others while laughing - pinned as 4, the sign carried
// in the comment (folios 29-30)
inline int cmvJesLaughHitMod()
    { return 4; }

// Giggle Spell's range - 2 inches (folio 29)
inline int cmvJesGiggleRangeInches()
    { return 2; }

// the Pun causes the attacker to pause and say Wha-a - lasts 1 turn, no
// attack possible that turn (folio 29)
inline int cmvJesPunTurns()
    { return 1; }

// the Pun's range - 2 inches (folio 29)
inline int cmvJesPunRangeInches()
    { return 2; }

// Funny Face I affects 10 1st level types, 5 2nd, or 1 3rd - the 1st-level
// count (folio 29)
inline int cmvJesFF1First()
    { return 10; }

// Funny Face I affects 5 2nd level types - the 2nd-level count (folio 29)
inline int cmvJesFF1Second()
    { return 5; }

// Funny Face I affects 1 3rd level type - the 3rd-level count (folio 29)
inline int cmvJesFF1Third()
    { return 1; }

// Funny Face I causes laughter for 1 turn, no victim attack possible that
// turn (folio 29)
inline int cmvJesFF1Turns()
    { return 1; }

// Funny Face I's range - 2 inches (folio 29)
inline int cmvJesFF1RangeInches()
    { return 2; }

// Body Contortion I - the tumbling jester becomes Armor Class 0 for 1 turn
// (folio 29)
inline int cmvJesBC1Ac()
    { return 0; }

// Body Contortion I's duration - 1 turn (folio 29)
inline int cmvJesBC1Turns()
    { return 1; }

// Pause stops victims for 2 melee turns (folio 29)
inline int cmvJesPauseTurns()
    { return 2; }

// Pause's range - 2 inches (folio 29)
inline int cmvJesPauseRangeInches()
    { return 2; }

// Joke causes laughter for 2 turns (folio 29)
inline int cmvJesJokeTurns()
    { return 2; }

// Joke affects creatures of 6 hit dice or less (folio 29)
inline int cmvJesJokeHdMax()
    { return 6; }

// Joke's range - 2 inches (folio 29)
inline int cmvJesJokeRangeInches()
    { return 2; }

// Funny Face II affects 3 3rds, 2 4ths, 1 5th level type - the 3rd-level
// count (folio 29)
inline int cmvJesFF2Third()
    { return 3; }

// Funny Face II's 4th-level count (folio 29)
inline int cmvJesFF2Fourth()
    { return 2; }

// Funny Face II's 5th-level count (folio 29)
inline int cmvJesFF2Fifth()
    { return 1; }

// Body Contortion II makes the user Armor Class -4 - pinned as 4, the sign
// carried in the comment (folio 29)
inline int cmvJesBC2Ac()
    { return 4; }

// Wonder pauses victims for 4 turns if followed by an extended joke, else
// same as Pause (folio 29)
inline int cmvJesWonderTurns()
    { return 4; }

// Wonder's range - 2 inches (folio 29)
inline int cmvJesWonderRangeInches()
    { return 2; }

// Ventriloquism - same as Magic User but range 3 inches (folio 29)
inline int cmvJesVentriloquismRangeInches()
    { return 3; }

// Thighslapper takes 2 turns to utter (folio 29)
inline int cmvJesThighTurnsToUtter()
    { return 2; }

// Thighslapper causes laughter for 8 turns, affecting 10 1st, 9 2nd, 8 3rd
// level types and so on (folio 29)
inline int cmvJesThighLaughterTurns()
    { return 8; }

// Thighslapper's 1st-level count - 10 (folio 29)
inline int cmvJesThighFirst()
    { return 10; }

// Thighslapper's 2nd-level count - 9 (folio 29)
inline int cmvJesThighSecond()
    { return 9; }

// Thighslapper's 3rd-level count - 8 (folio 29)
inline int cmvJesThighThird()
    { return 8; }

// Thighslapper's range - 3 inches (folio 29)
inline int cmvJesThighRangeInches()
    { return 3; }

// Funny Face III affects 1 18th level type, 2 7th level types, etc. for 1
// turn (folio 29)
inline int cmvJesFF3Level()
    { return 18; }

// Funny Face III's 7th-level count - 2 (folio 29)
inline int cmvJesFF3Seventh()
    { return 2; }

// Funny Face III's range - 2 inches (folio 29)
inline int cmvJesFF3RangeInches()
    { return 2; }

// Obscenity renders lawful and neutral Clerics ineffective for 3 turns due to
// embarrassment, affecting other types as the Joke spell (folio 29)
inline int cmvJesObscenityTurns()
    { return 3; }

// Boring Joke takes 4 turns to utter (folio 29)
inline int cmvJesBoringTurnsToUtter()
    { return 4; }

// Boring Joke acts as Sleep - puts a 10th level type to sleep for 2 turns
// (folio 29)
inline int cmvJesBoringTenthTurns()
    { return 2; }

// Boring Joke's 9th level sleep - 4 turns, and so on down (folio 29)
inline int cmvJesBoringNinthTurns()
    { return 4; }

// Boring Joke's range - 2 inches (folio 29)
inline int cmvJesBoringRangeInches()
    { return 2; }

// Decrepitating - a 7th level jester incapacitates his target for 2 turns
// (folio 29)
inline int cmvJesDecrepSeventhTurns()
    { return 2; }

// Decrepitating - an 8th level jester incapacitates for 4 turns, and so on up
// (folio 29)
inline int cmvJesDecrepEighthTurns()
    { return 4; }

// a maximum of 3 Decrepitatings per game hour by any one jester (folio 29)
inline int cmvJesDecrepPerHourMax()
    { return 3; }

// Decrepitating's range - 3 inches (folio 29)
inline int cmvJesDecrepRangeInches()
    { return 3; }

// Bellyacher takes 2 turns to utter (folio 29)
inline int cmvJesBellyTurnsToUtter()
    { return 2; }

// Bellyacher causes the victim to laugh 8 turns plus the level of the jester
// (folio 29)
inline int cmvJesBellyLaughterTurns()
    { return 8; }

// Extension I, done while the subject is already laughing, lowers the
// victim's resistance by 1 on the next saving throw (folio 29)
inline int cmvJesExt1Resistance()
    { return 1; }

// Extension II lowers the resistance by 2 (folio 29)
inline int cmvJesExt2Resistance()
    { return 2; }

// Gutbuster is the same as Bellyacher but also does 1-4 points while the
// victim is laughing - the minimum (folio 29)
inline int cmvJesGutbusterMinDamage()
    { return 1; }

// Gutbuster's damage maximum - 4 (folio 29)
inline int cmvJesGutbusterMaxDamage()
    { return 4; }

// Insult - a 50 percent chance the target flees, crushed with embarrassment
// (folio 29)
inline int cmvJesInsultFleePct()
    { return 50; }

// Insult's flee chance reads 1-3 on a six-sided die (folio 29)
inline int cmvJesInsultFleeDie()
    { return 6; }

// Insult's flee roll - 1-3 of the d6 (folio 29)
inline int cmvJesInsultFleeDieMax()
    { return 3; }

// Insult - a 50 percent chance the victim becomes enraged and immediately
// attacks (folio 29)
inline int cmvJesInsultEnragePct()
    { return 50; }

// Insult affects any character for 1-20 turns on a 20-sided die (folio 29)
inline int cmvJesInsultDieSides()
    { return 20; }

// Insult's duration minimum - 1 turn (folio 29)
inline int cmvJesInsultTurnsMin()
    { return 1; }

// Insult's duration maximum - 20 turns (folio 29)
inline int cmvJesInsultTurnsMax()
    { return 20; }

// Quick Puns - one additional pun per level of the jester above 8th, no
// saving throw (folio 29)
inline int cmvJesQuickPunsLevelBase()
    { return 8; }

// Quick Puns' range - 3 inches (folio 29)
inline int cmvJesQuickPunsRangeInches()
    { return 3; }

// Extension III lowers the resistance by 3 (folio 30)
inline int cmvJesExt3Resistance()
    { return 3; }

// Die Laughing takes 3 turns to tell (folio 30)
inline int cmvJesDieLaughTurnsToTell()
    { return 3; }

// Die Laughing kills all under 8 hit dice; others take half damage of total
// hit points (folio 30)
inline int cmvJesDieLaughHdMax()
    { return 8; }

// Die Laughing's survivors take half of total hit points - pinned as 50
// percent, the conversion noted (folio 30)
inline int cmvJesDieLaughSavePctMaxHp()
    { return 50; }

// Die Laughing takes the victim 2 turns to die (folio 30)
inline int cmvJesDieLaughDieTurns()
    { return 2; }

// Die Laughing - 2 turns of a quarter damage per turn if the saving throw is
// made, the quarter pinned as 25 percent (folio 30)
inline int cmvJesDieLaughPerTurnPct()
    { return 25; }

// Die Laughing's range - 2 inches (folio 30)
inline int cmvJesDieLaughRangeInches()
    { return 2; }

// Uncontrollable Laughter causes incapacitation for 10 turns, no saving throw
// (folio 30)
inline int cmvJesUnctrlTurns()
    { return 10; }

// Uncontrollable Laughter affects 1 10th level type (folio 30)
inline int cmvJesUnctrlTenth()
    { return 1; }

// Uncontrollable Laughter affects 2 9th level types, etc. (folio 30)
inline int cmvJesUnctrlNinth()
    { return 2; }

// Uncontrollable Laughter's range - 2 inches (folio 30)
inline int cmvJesUnctrlRangeInches()
    { return 2; }

// Killer kills all under 12 hit dice (folio 30)
inline int cmvJesKillerHdMax()
    { return 12; }

// Killer takes 3 turns to utter (folio 30)
inline int cmvJesKillerTurnsToUtter()
    { return 3; }

// Killer - those who make their saving throws take half damage, pinned as 50
// percent (folio 30)
inline int cmvJesKillerSavePctMaxHp()
    { return 50; }

// Killer's victim takes 2 turns to die, or a quarter damage per turn if the
// save is made (folio 30)
inline int cmvJesKillerDieTurns()
    { return 2; }

// Killer's quarter-damage-per-turn on a made save, pinned as 25 percent
// (folio 30)
inline int cmvJesKillerPerTurnPct()
    { return 25; }

// Killer's range - 3 inches (folio 30)
inline int cmvJesKillerRangeInches()
    { return 3; }

// Ballbuster takes 3 turns to utter (folio 30)
inline int cmvJesBallbustTurnsToUtter()
    { return 3; }

// Ballbuster renders the victim incapacitated for 1-10 turns - the minimum
// (folio 30)
inline int cmvJesBallbustMinTurns()
    { return 1; }

// Ballbuster's incapacitation maximum - 10 turns, affecting any thinking
// creature no matter the level, no saving throw (folio 30)
inline int cmvJesBallbustMaxTurns()
    { return 10; }

// Ballbuster's range - 3 inches (folio 30)
inline int cmvJesBallbustRangeInches()
    { return 3; }

// Voice Projector doubles the range of any joke uttered (folio 30)
inline int cmvJesVoiceRangeMult()
    { return 2; }

// Voice Projector's duration - 4 turns (folio 30)
inline int cmvJesVoiceTurns()
    { return 4; }

// Jesters are always neutral or chaotic (folios 28-29)
inline bool cmvJesterNeutralOrChaotic()
    { return true; }

// Dwarves, because of their stunted height, make the best Jesters - they can
// progress infinitely in the category (folios 28-29)
inline bool cmvJesterDwarfInfinite()
    { return true; }

// Jesters are not allowed to wear any armor (folios 28-29)
inline bool cmvJesterNoArmor()
    { return true; }

// Jesters can be thieves as well as funnymen (folios 28-29)
inline bool cmvJesterThiefAlso()
    { return true; }

// limited to the joke weapons - all weapons with an asterisk are magical, and
// all weapons except the dagger can only be used by a Jester (folios 28-29)
inline bool cmvJesterWeaponExclusive()
    { return true; }

// the level of the man battling the Jester is inconsequential when rolling
// saving throws - intelligence is the only factor (folio 29)
inline bool cmvJesterIntOnlySaves()
    { return true; }

// failure to make the saving throw total or above indicates the attack having
// full effect (folio 29)
inline bool cmvJesSaveTotalOrAbove()
    { return true; }

// Jesters have the same chance as a Magic User to get a spell, except their
// wisdom score is the base instead of their intelligence (folio 30)
inline bool cmvJesSpellsByWisdom()
    { return true; }

// Strange Actions combines the Joke and Body Contortion I (folio 29)
inline bool cmvJesStrangeActions()
    { return true; }

// Pity acts as Charm Person, with limitations up to befriending the jester at
// the referee's discretion (folio 29)
inline bool cmvJesPityBefriending()
    { return true; }

// the Intelligence band's low score (folio 29)
inline int cmvJs1Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 10;
        case 4:
            return 13;
        case 5:
            return 16;
        case 6:
            return 18;
        default:
            return 9;
        }
    }

// the Intelligence band's high score (folio 29)
inline int cmvJs1Hi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 17;
        case 6:
            return 18;
        default:
            return 9;
        }
    }

// the saving throw for jokes aimed at high intellects (folio 29)
inline int cmvJs1Save(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 14;
        case 5:
            return 16;
        case 6:
            return 18;
        default:
            return 9;
        }
    }

// the Intelligence band's low score (folio 29)
inline int cmvJs2Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 10;
        case 4:
            return 13;
        case 5:
            return 16;
        case 6:
            return 18;
        default:
            return 9;
        }
    }

// the Intelligence band's high score (folio 29)
inline int cmvJs2Hi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 17;
        case 6:
            return 18;
        default:
            return 9;
        }
    }

// the saving throw for jokes aimed at those with low intelligence (folio 29)
inline int cmvJs2Save(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 16;
        case 2:
            return 14;
        case 3:
            return 11;
        case 4:
            return 9;
        case 5:
            return 7;
        case 6:
            return 5;
        default:
            return 9;
        }
    }

// the experience points, 2,000 through 828,000 (folio 29)
inline int cmvJxXp(int b)
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
            return 228000;
        case 8:
            return 328000;
        case 9:
            return 428000;
        case 10:
            return 528000;
        case 11:
            return 628000;
        case 12:
            return 728000;
        case 13:
            return 828000;
        default:
            return 9;
        }
    }

// the first progression column - the staircase cells ride AS SCANNED with the
// column semantics garbling in the OCR, capping at 15 - the Dwarf infinite
// track (folio 29)
inline int cmvJxC1(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        default:
            return 9;
        }
    }

// the second progression column, capping at 7 (folio 29)
inline int cmvJxC2(int b)
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
            return 4;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 7;
        case 13:
            return 7;
        default:
            return 9;
        }
    }

// the third progression column, capping at 6 (folio 29)
inline int cmvJxC3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        default:
            return 9;
        }
    }

// the fourth progression column, capping at 6 (folio 29)
inline int cmvJxC4(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 6;
        case 13:
            return 6;
        default:
            return 9;
        }
    }

// the fifth progression column, capping at 6 (folio 29)
inline int cmvJxC5(int b)
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
            return 1;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 6;
        default:
            return 9;
        }
    }

// the sixth progression column, capping at 5 - the Men/Fool track (folio 29)
inline int cmvJxC6(int b)
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
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        default:
            return 9;
        }
    }

// the seventh progression column, capping at 4 - the Comic track (folio 29)
inline int cmvJxC7(int b)
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
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 4;
        default:
            return 9;
        }
    }

// the eighth progression column, capping at 2 (folio 29)
inline int cmvJxC8(int b)
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
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        default:
            return 9;
        }
    }

// ---- the Cline dexterity mods (folio 30) ----

// the cmvClineDex table runs 12 rows (folio 30)
inline int cmvClineDexCount()
    { return 12; }

// the Hit column means to hit with a hand-held weapon (folio 30)
inline bool cmvClineHitHandHeld()
    { return true; }

// the band's low score - the dex 3-18 rows and the OCR's four percent-band
// rows ride together AS SCANNED, the 51-00 rows noted (folio 30)
inline int cmvClDexLo(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 9;
        case 3:
            return 13;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 51;
        case 9:
            return 76;
        case 10:
            return 91;
        case 11:
            return 100;
        default:
            return 9;
        }
    }

// the band's high score, the printed 'N' pinned as 0 where it appears, the 00
// convention pinned as 100 (folio 30)
inline int cmvClDexHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 8;
        case 2:
            return 12;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 75;
        case 9:
            return 90;
        case 10:
            return 99;
        case 11:
            return 100;
        default:
            return 9;
        }
    }

// the hand-held weapon hit modifier, sign carried in this comment (folio 30)
inline int cmvClHit(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        default:
            return 9;
        }
    }

// the missile modifier (folio 30)
inline int cmvClMissile(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 5;
        default:
            return 9;
        }
    }

// the damage modifier (folio 30)
inline int cmvClDamage(int b)
    {
        switch (b) {
        case 0:
            return -1;
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
            return -1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        default:
            return 9;
        }
    }

// the defense modifier (folio 30)
inline int cmvClDefense(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 6;
        default:
            return 9;
        }
    }

}   // namespace rules
