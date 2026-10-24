// =========================================================================================
// Adnd1 - rules/mm2hi.h
// THE MM2 LETTERS HI WALK - THE HANGMAN TREE, HAUNT, HOLLYPHANT, HORDLING AND
// HYBSIL TURNS (the hangman tree, the haunt pp. 74-75, the hollyphant, the
// hordling pp. 75-76 and the hybsil pp. 76-77), promoted to the live
// registry; the Letter I box closes on the already-pinned ildriss (no new
// letter-I defs ride the walk)
// census 728 -> 729.
//
// Round eleven of the MM2 arc, the SECOND TWO-LETTER pass (the user Go call
// on the landed FG walk: the multiple letters standing call - the hangman
// tree opens p. 74 and the hybsil tail closes p. 77, the letter-I span holds
// only the ildriss already promoted by the R805 FG walk - the HI-FLIP round,
// both the Letter H and the Letter I gap boxes flip to closed). The capture
// is the Curtiss PDF upload cross-checked against the archive.org djvu OCR,
// the contested cells settled book-internal first: the hangman tree "61
// hp/year" cell pins capture verbatim with the flat printed 61 hp read (the
// 1eonline 6-plus-1-per-year typo note the cross-check voice); the haunt
// "1/1, as 5 HD monster" loads the max 5; the hordling or-form cells read
// their best variant; the hybsil xp level reads II over the OCR "ll"/"11"
// misreads
//
// LOADER SEMANTICS (the R805 grim lesson): the composite numAttacks strings
// load as their max (the "as 5 HD monster" read 5) and the textless cells
// floor at 1; the flat-hp monsters carry hitDiceNum 0; every Nil lair reads 0
// and every Standard magic resistance reads 0; the walk demands the loaded
// def equal the pin - walk patches may only touch real MonsterDef fields
//
namespace rules {

// ---- the MM2 letters HI walk round pins (the R806 census) ----

// The MM2 letters HI walk round: the hangman tree, haunt, hollyphant,
// hordling and hybsil turns, the second TWO-LETTER pass (the user Go call on
// the landed FG walk)
inline int mm2hiRound()
    { return 806; }

// The registry census before the R806 promotion (the landed R805 count)
inline int mm2hiRegistryBefore()
    { return 650; }

// The registry census after the R806 promotion (5 defs)
inline int mm2hiRegistryAfter()
    { return 655; }

// The .lua defs riding the R806 walk (the hangman tree, the haunt, the
// hollyphant, the hordling and the hybsil)
inline int mm2hiDefCount()
    { return 5; }

// The pin-time walk entry census (5 entries, all with stat blocks)
inline int mm2hiEntryCount()
    { return 5; }

// The stat-block headings walked at pin time from the print pp. 74-77
inline int mm2hiStatBlockHeadings()
    { return 5; }

// The doctrine-only family heads riding the letter-H walk (none - the five
// letter-H entries each carry their own stat block)
inline int mm2hiDoctrineHeads()
    { return 0; }

// The letter-H headings (the hangman tree, the haunt, the hollyphant, the
// hordling and the hybsil)
inline int mm2hiLetterHHeadings()
    { return 5; }

// The letter-I headings walked by R806 (zero new entries - the letter-I span
// holds only the ildriss)
inline int mm2hiLetterIHeadings()
    { return 0; }

// The row count of the hangman-tree-to-hybsil stat grid
inline int mm2hiHhStatRows()
    { return 5; }

// The MM2 gap report closed-box count after the HI-FLIP (the letter H and
// letter I boxes flip to closed)
inline int mm2hiGapClosed()
    { return 14; }

// The MM2 gap report open-box count after the HI-FLIP
inline int mm2hiGapOpen()
    { return 23; }

// The prior-owned letter-H-and-I entries (the ildriss, promoted by the R805
// FG walk - the letter-I box closes on it)
inline int mm2hiPriorOwnedEntries()
    { return 1; }

// The owning round of the only letter-I entry (the ildriss rode the R805
// letters FG walk under the GRUE family head)
inline int mm2hiIldrissOwningRound()
    { return 805; }

// Haunts may not be turned because they are linked to the site of their
// deaths
inline bool mm2hiHauntCannotBeTurned()
    { return true; }

// In natural form the haunt can be struck only by silver and magical weapons
// and by fire
inline bool mm2hiHauntStruckOnlyBySilverMagicOrFire()
    { return true; }

// Exorcism will destroy a haunt forever (the reform-in-1-week cycle
// otherwise)
inline bool mm2hiHauntExorcismDestroysForever()
    { return true; }

// The haunt stat block prints no size or magic resistance line (the size
// reads empty and the magic resistance reads Nil 0)
inline bool mm2hiHauntBlockPrintsNoSizeOrMrLine()
    { return true; }

// Live hollyphants are always protected by a globe of invulnerability
// radiated by their fur
inline bool mm2hiHollyphantGlobeOfInvulnerability()
    { return true; }

// The hollyphant tusks give immunity to all diseases and poisons (the tusks
// do not function thus for others)
inline bool mm2hiHollyphantTusksImmunity()
    { return true; }

// Lightning or electricity will cause double damage to the hangman tree
inline bool mm2hiHangmanTreeLightningDoubleDamage()
    { return true; }

// The hangman tree hallucinatory perfume makes victims believe it to be an
// ordinary quickwood or treant
inline bool mm2hiHangmanTreeHallucinatoryPerfume()
    { return true; }

// Treat hordlings as minor demons with respect to clerical turning and like
// effects
inline bool mm2hiHordlingTurnedAsMinorDemons()
    { return true; }

// All hordlings have ultravisual capabilities
inline bool mm2hiHordlingUltravisual()
    { return true; }

// The bringer of doom is the only known method of drawing more than 1
// hordling to the Prime Material Plane
inline bool mm2hiHordlingBringerOfDoomSummoning()
    { return true; }

// Hybsils add +4 to all their saving throws because of their hearty
// constitutions
inline bool mm2hiHybsilPlusFourSaves()
    { return true; }

// The hybsil tribal leader will be a witch doctor (druid 60% or magic-user
// 40% spells)
inline bool mm2hiHybsilWitchDoctorLeadership()
    { return true; }

// The Letter I gap box closes on the already-pinned ildriss (no new letter-I
// defs ride the R806 walk)
inline bool mm2hiLetterIBoxClosesOnIldriss()
    { return true; }

// ---- the hangman tree pins (the R806 MM2 letters HI walk) ----

// The hangman tree full kill xp (1600 + 8/hp x 61 avg; level VII)
inline int mm2hiHangmanTreeXpValue()
    { return 2088; }

// The hangman tree printed xp level (VII)
inline int mm2hiHangmanTreeXpLevel()
    { return 7; }

// The hangman tree appendage count low end (6-9)
inline int mm2hiHangmanTreeAppendagesMin()
    { return 6; }

// The hangman tree appendage count high end (6-9)
inline int mm2hiHangmanTreeAppendagesMax()
    { return 9; }

// The hangman tree appendages controllable at one time
inline int mm2hiHangmanTreeControlledAppendages()
    { return 3; }

// The hangman tree vine sever damage low end (13-20 points)
inline int mm2hiHangmanTreeVineSeverMin()
    { return 13; }

// The hangman tree vine sever damage high end (13-20 points)
inline int mm2hiHangmanTreeVineSeverMax()
    { return 20; }

// The hangman tree vine tightening damage high end (1-3 per round)
inline int mm2hiHangmanTreeVineDamageMax()
    { return 3; }

// The hangman tree vine lift capacity (pounds)
inline int mm2hiHangmanTreeLiftPounds()
    { return 1000; }

// The hangman tree rounds to lift prey to the trunk opening
inline int mm2hiHangmanTreeLiftRounds()
    { return 4; }

// The hangman tree round the victim is dropped into the acid (the round after
// the lift)
inline int mm2hiHangmanTreeDropRound()
    { return 5; }

// The hangman tree acid damage high end (3-12 per round)
inline int mm2hiHangmanTreeAcidDamageMax()
    { return 12; }

// The man-sized victims fitting the hangman tree digestive cavity
inline int mm2hiHangmanTreeDigestVictims()
    { return 3; }

// The hangman tree hallucinatory perfume release range low end (30-80 feet
// distant)
inline int mm2hiHangmanTreePerfumeRangeMinFeet()
    { return 30; }

// The hangman tree hallucinatory perfume release range high end
inline int mm2hiHangmanTreePerfumeRangeMaxFeet()
    { return 80; }

// The hangman tree magic resistance (1% per year of age)
inline int mm2hiHangmanTreeMrPerYear()
    { return 1; }

// The hangman tree sprout age band high end (1-10 years)
inline int mm2hiHangmanTreeSproutAgeMax()
    { return 10; }

// The hangman tree sapling age band low end (11-25 years)
inline int mm2hiHangmanTreeSaplingAgeMin()
    { return 11; }

// The hangman tree sapling age band high end
inline int mm2hiHangmanTreeSaplingAgeMax()
    { return 25; }

// The hangman tree sapling movement (feet per hour)
inline int mm2hiHangmanTreeSaplingMoveFeetPerHour()
    { return 6; }

// The hangman tree mature age band low end (26-75 years)
inline int mm2hiHangmanTreeMatureAgeMin()
    { return 26; }

// The hangman tree mature age band high end
inline int mm2hiHangmanTreeMatureAgeMax()
    { return 75; }

// The hangman tree old age band low end (76-150 years)
inline int mm2hiHangmanTreeOldAgeMin()
    { return 76; }

// The hangman tree old age band high end
inline int mm2hiHangmanTreeOldAgeMax()
    { return 150; }

// The hangman tree ancient age band low end (151+ years)
inline int mm2hiHangmanTreeAncientAgeMin()
    { return 151; }

// The hangman tree efficiency under darkness (half efficiency)
inline int mm2hiHangmanTreeDarknessEfficiencyPct()
    { return 50; }

// ---- the haunt pins (the R806 MM2 letters HI walk) ----

// The haunt full kill xp (165 + 5/hp x 17 avg; level IV)
inline int mm2hiHauntXpValue()
    { return 250; }

// The haunt printed xp level (IV)
inline int mm2hiHauntXpLevel()
    { return 4; }

// The haunt habitation radius around the death site (inches)
inline int mm2hiHauntAreaRadiusInches()
    { return 6; }

// The haunt dexterity drain per hit
inline int mm2hiHauntDexDrain()
    { return 2; }

// The dexterity score at which the haunt steps into the body
inline int mm2hiHauntPossessDexFloor()
    { return 0; }

// The victim dexterity after the haunt leaves the body
inline int mm2hiHauntReleaseVictimDex()
    { return 3; }

// The lost dexterity regain rate (1 point per turn of complete rest)
inline int mm2hiHauntDexRegainPerTurn()
    { return 1; }

// The haunt strangling damage the first round
inline int mm2hiHauntStrangleStart()
    { return 1; }

// The haunt strangling damage the second round
inline int mm2hiHauntStrangleSecond()
    { return 2; }

// The haunt strangling damage the third round (doubling each round)
inline int mm2hiHauntStrangleThird()
    { return 4; }

// The haunt damage per weapon attack (plus any magical bonuses)
inline int mm2hiHauntWeaponDamage()
    { return 1; }

// The haunt damage per round from fire
inline int mm2hiHauntFireDamagePerRound()
    { return 1; }

// The haunt reform time after being reduced to zero hit points (weeks)
inline int mm2hiHauntReformWeeks()
    { return 1; }

// The haunt attack capability in its natural state (the "1/1, as 5 HD
// monster" cell reads the 5)
inline int mm2hiHauntAttackAsHd()
    { return 5; }

// The haunt assumed forms (the luminescent ball of light and the translucent
// body image)
inline int mm2hiHauntFormCount()
    { return 2; }

// ---- the hollyphant pins (the R806 MM2 letters HI walk) ----

// The hollyphant full kill xp (3750 + 14/hp x 36 avg; level VIII)
inline int mm2hiHollyphantXpValue()
    { return 4254; }

// The hollyphant printed xp level (VIII)
inline int mm2hiHollyphantXpLevel()
    { return 8; }

// The hollyphant trumpet blasts per day
inline int mm2hiHollyphantTrumpsPerDay()
    { return 3; }

// The hollyphant deafening cone dimensions (1 x 3 x 7 inches)
inline int mm2hiHollyphantDeafenConeLengthInches()
    { return 7; }

// The hollyphant sun-sparkles damage dice (8d6)
inline int mm2hiHollyphantSunSparkleDamageDice()
    { return 8; }

// The hollyphant sun-sparkles damage bonus (+8)
inline int mm2hiHollyphantSunSparkleBonus()
    { return 8; }

// The hollyphant spell-like ability level (16th)
inline int mm2hiHollyphantSpellLevel()
    { return 16; }

// The hollyphant banishment range (inches)
inline int mm2hiHollyphantBanishRangeInches()
    { return 2; }

// The hollyphant banishment total hit dice cap
inline int mm2hiHollyphantBanishHdCap()
    { return 32; }

// The hollyphant banishment backlash damage low end (2-12)
inline int mm2hiHollyphantBacklashDamageMin()
    { return 2; }

// The hollyphant banishment backlash damage high end (2-12)
inline int mm2hiHollyphantBacklashDamageMax()
    { return 12; }

// The hollyphant banishment backlash stun (2-12 segments)
inline int mm2hiHollyphantBacklashStunSegmentsMax()
    { return 12; }

// The hollyphant cure serious wounds uses per day
inline int mm2hiHollyphantCureSeriousWoundsPerDay()
    { return 2; }

// The hollyphant protection from evil uses per day
inline int mm2hiHollyphantProtectionFromEvilPerDay()
    { return 2; }

// The hollyphant protection from evil radius (feet)
inline int mm2hiHollyphantProtectionRadiusFeet()
    { return 10; }

// The hollyphant gate success percent
inline int mm2hiHollyphantGatePct()
    { return 50; }

// The gated hollyphant arrival percent
inline int mm2hiHollyphantGateHollyphantPct()
    { return 70; }

// The gated deva arrival percent
inline int mm2hiHollyphantGateDevaPct()
    { return 30; }

// The hollyphant automatic detect evil radius (inches)
inline int mm2hiHollyphantDetectEvilRadiusInches()
    { return 2; }

// The hollyphant usual minor psionic disciplines
inline int mm2hiHollyphantPsionicMinor()
    { return 4; }

// The hollyphant usual major psionic disciplines
inline int mm2hiHollyphantPsionicMajor()
    { return 2; }

// The hollyphant probability of going by foot (percent)
inline int mm2hiHollyphantFootTravelPct()
    { return 5; }

// The weapon enchantment floor to harm a hollyphant
inline int mm2hiHollyphantWeaponPlusMin()
    { return 1; }

// The hollyphant flight rate (42 inches; the ground move reads 9)
inline int mm2hiHollyphantFlyRate()
    { return 42; }

// The hollyphant psionic ability score low end (201-300)
inline int mm2hiHollyphantPsionicMin()
    { return 201; }

// The hollyphant psionic ability score high end (201-300)
inline int mm2hiHollyphantPsionicMax()
    { return 300; }

// ---- the hordling pins (the R806 MM2 letters HI walk) ----

// The hordling full kill xp of the top variant (1400 + 12/hp x 31 avg; level
// VII - the or-form best read)
inline int mm2hiHordlingXpValue()
    { return 1772; }

// The hordling top-variant printed xp level (VII)
inline int mm2hiHordlingXpLevelTop()
    { return 7; }

// The hordling armor class tier 1 (the "3,2,1, OR 0" ladder)
inline int mm2hiHordlingAcTier1()
    { return 3; }

// The hordling armor class tier 2
inline int mm2hiHordlingAcTier2()
    { return 2; }

// The hordling armor class tier 3
inline int mm2hiHordlingAcTier3()
    { return 1; }

// The hordling armor class tier 4
inline int mm2hiHordlingAcTier4()
    { return 0; }

// The hordling ground move tier 1 (the "6, 9, 12, or 15" ladder)
inline int mm2hiHordlingMoveTier1()
    { return 6; }

// The hordling ground move tier 4
inline int mm2hiHordlingMoveTier4()
    { return 15; }

// The hordling hit dice tier 1 (the 6+3, 7+2, 8+1, or 9 ladder)
inline int mm2hiHordlingHdTier1()
    { return 6; }

// The hordling hit dice bonus tier 1 (6+3)
inline int mm2hiHordlingHdBonusTier1()
    { return 3; }

// The hordling hit dice tier 4 (the or-form best read)
inline int mm2hiHordlingHdTier4()
    { return 9; }

// The hordling hit dice bonus tier 4 (the bare 9)
inline int mm2hiHordlingHdBonusTier4()
    { return 0; }

// The hordling magic resistance tier 1 (the 0%, 5%, 15%, 30% ladder)
inline int mm2hiHordlingMrTier1()
    { return 0; }

// The hordling magic resistance tier 4
inline int mm2hiHordlingMrTier4()
    { return 30; }

// The hordling base xp tier 1 (525 + 8/hp; level VI)
inline int mm2hiHordlingXpTier1()
    { return 525; }

// The hordling xp per hit point tier 1
inline int mm2hiHordlingXpHpTier1()
    { return 8; }

// The hordling base xp tier 4 (1400 + 12/hp; level VII)
inline int mm2hiHordlingXpTier4()
    { return 1400; }

// The hordling xp per hit point tier 4
inline int mm2hiHordlingXpHpTier4()
    { return 12; }

// The hordling tier roll (1d4 for armor class, move, hit dice, magic
// resistance, intelligence and size)
inline int mm2hiHordlingTierDie()
    { return 4; }

// The hordling 1d6 physical-characteristic tables (the head through the
// color)
inline int mm2hiHordlingTraitTableCount()
    { return 18; }

// The hordling physical-characteristic roll (1d6 per characteristic)
inline int mm2hiHordlingTraitDie()
    { return 6; }

// The hordling attack table letter entries (a through o)
inline int mm2hiHordlingAttackTableEntries()
    { return 15; }

// The hordling special attacks table entries
inline int mm2hiHordlingSpecialAttackCount()
    { return 6; }

// The hordling special defenses table entries
inline int mm2hiHordlingSpecialDefenseCount()
    { return 6; }

// The hordling chance of 2 special attacks or defenses (percent)
inline int mm2hiHordlingDoubleSpecialPct()
    { return 10; }

// The hordling near-invisibility effectiveness (percent)
inline int mm2hiHordlingNearInvisiblePct()
    { return 75; }

// The hordling near-invisibility duration (up to 1 full turn once per day)
inline int mm2hiHordlingNearInvisibleTurns()
    { return 1; }

// The hordling in-lair percent on the Planes of Hades
inline int mm2hiHordlingLairPctHades()
    { return 15; }

// The hordling strength ladder to-hit bonus low end (the 17 through 18/99
// ladder)
inline int mm2hiHordlingStrengthToHitMin()
    { return 1; }

// The hordling strength ladder to-hit bonus high end
inline int mm2hiHordlingStrengthToHitMax()
    { return 2; }

// The hordling strength ladder damage bonus low end
inline int mm2hiHordlingStrengthDamageMin()
    { return 1; }

// The hordling strength ladder damage bonus high end (the 18/99 +2/+5 rung)
inline int mm2hiHordlingStrengthDamageMax()
    { return 5; }

// The hordling acidic spittle missile range (feet)
inline int mm2hiHordlingAcidSpittleRangeFeet()
    { return 10; }

// The hordling acidic spittle damage high end (2-8)
inline int mm2hiHordlingAcidSpittleDamageMax()
    { return 8; }

// The hordling regeneration rate low end (2-5 hp per turn)
inline int mm2hiHordlingRegenerateMin()
    { return 2; }

// The hordling regeneration rate high end
inline int mm2hiHordlingRegenerateMax()
    { return 5; }

// ---- the hybsil pins (the R806 MM2 letters HI walk) ----

// The hybsil full kill xp (22 + 1/hp x 2 avg; level II)
inline int mm2hiHybsilXpValue()
    { return 24; }

// The hybsil printed xp level (II - the capture "ll" and the djvu "11" both
// the OCR misreads)
inline int mm2hiHybsilXpLevel()
    { return 2; }

// The hybsil number appearing roll (1d6)
inline int mm2hiHybsilNoAppearingDie()
    { return 6; }

// The hybsil number appearing multiplier (x 10)
inline int mm2hiHybsilNoAppearingMult()
    { return 10; }

// The hybsil arrow damage high end (1-4)
inline int mm2hiHybsilArrowDamageMax()
    { return 4; }

// The hybsil arrow sleep duration low end (1-4 hours)
inline int mm2hiHybsilSleepHoursMin()
    { return 1; }

// The hybsil arrow sleep duration high end
inline int mm2hiHybsilSleepHoursMax()
    { return 4; }

// The hybsil arrow sleep save penalty (save vs. poison at -4)
inline int mm2hiHybsilSleepSavePenalty()
    { return 4; }

// The hybsil bonus to all saving throws (+4)
inline int mm2hiHybsilSaveBonus()
    { return 4; }

// The hybsil witch doctor druid-spell probability (percent)
inline int mm2hiHybsilWitchDoctorDruidPct()
    { return 60; }

// The hybsil witch doctor magic-user-spell probability (percent)
inline int mm2hiHybsilWitchDoctorMuPct()
    { return 40; }

// The hybsil witch doctor casting ability cap (7th level)
inline int mm2hiHybsilWitchDoctorLevelMax()
    { return 7; }

// ---- the MM2 letters HI walk stat grid (the R806 wiring) ----

// The armor class cells (the hangman tree "3/5 (appendages)" composite reads
// the trunk 3; the haunt "0/victim's AC" reads 0; the hordling "3,2,1, OR 0"
// reads the first 3; the hollyphant -4)
inline int mm2hiHhStatAC(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return -4;
        case 3:
            return 3;
        case 4:
            return 7;
        default:
            return 0;
        }
    }

// The hit dice num cells (the hangman tree flat-hp "61 hp/year" cell reads 0
// dice - the demilich precedent; the hordling or-form reads the best 9
inline int mm2hiHhStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 1;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the hybsil "1-1" carries the minus 1 - the
// buckawn precedent; the hollyphant 8+8)
inline int mm2hiHhStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 8;
        case 3:
            return 0;
        case 4:
            return -1;
        default:
            return 0;
        }
    }

// The book-average hit points (the floor(num x 3.5) + bonus formula; the
// hangman tree reads the flat printed 61 hp - the demilich "50 hp and
// special" precedent, the 1eonline 6 + 1-per-year typo note the cross-check
// voice)
inline int mm2hiHhStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 61;
        case 1:
            return 17;
        case 2:
            return 36;
        case 3:
            return 31;
        case 4:
            return 2;
        default:
            return 0;
        }
    }

// The attack cells (the composite prints read their loaded value, the R798
// duergar max-read convention: the haunt "1/1, as 5 HD monster" loads the max
// 5; the hordling "By type of hordling" reads the 1 loader floor; the hybsil
// "1 weapon" reads 1)
inline int mm2hiHhStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        default:
            return 0;
        }
    }

// The base xp cells (every letter-H print carries the xp level prefix; the
// hordling reads the top VII/1400 + 12/hp variant)
inline int mm2hiHhStatXp(int b)
    {
        switch (b) {
        case 0:
            return 1600;
        case 1:
            return 165;
        case 2:
            return 3750;
        case 3:
            return 1400;
        case 4:
            return 22;
        default:
            return 0;
        }
    }

// The xp per hit point cells
inline int mm2hiHhStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 5;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 1;
        default:
            return 0;
        }
    }

// The lair percentage cells (Nil reads 0; the hordling "0% (15% in Hades)"
// reads 0)
inline int mm2hiHhStatLairPct(int b)
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
            return 30;
        default:
            return 0;
        }
    }

// The ground move-rate cells (the hangman tree "0'' (effectively)" reads 0;
// the haunt "6''/as possessed victim" reads 6; the hordling tier list reads
// the first 6; the hollyphant "9''/42''" reads the ground 9)
inline int mm2hiHhStatMove(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 6;
        case 4:
            return 15;
        default:
            return 0;
        }
    }

// The magic resistance cells (the hangman tree "1% per year of age" reads 1;
// the hollyphant 60%; Standard reads 0; the haunt block prints no magic
// resistance line and reads Nil 0)
inline int mm2hiHhStatMr(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 60;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
