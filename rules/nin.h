// =========================================================================================
// Adnd1 - rules/nin.h
// The Dragon issue-16 opener - the Near Eastern Mythos (print 4-6) and the
// Ninja, the ultimate NPC (print 7-10): the two-chain round
// census 851 -> 852.
//
// Pinned from The Dragon Vol. III No. 2 (July 1978), the Curtiss-provided
// scan voice (single-voice: the issue-16 source is the uploaded Dm16.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 16). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the
// page feet (folios 4, 7, 10, 16, 18, 22 and 36 print at the PDF pages 6, 9,
// 12, 18, 20, 24 and 38) plus the TOC alignments (the Ninja at print 7 = PDF
// 9, the Green Magician part two at print 25 = PDF 27, Game Balance at print
// 36 = PDF 38). The transcripts ride extract/dragon/016/p001 through p040,
// landed this round; the article CHAIN is the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: no full-res visual
// check exists for this issue (the scan is a text-side transcript, no page
// renders), so garbled cells pin sentinel, never guessed - the Enkidu
// strength prints 1895 and the Aqht strength 1875, the 18-slash-percentile
// garble class, both pin sentinel; the as-a-normal-man armor classes (Enkidu,
// King Krt, King Dn-il, Aqht, the Maiden) pin sentinel; the see-below deity
// magic cells pin sentinel with the spell lists riding the transcript; the
// assassination hiring column prints 1006, 1518 and 2012 K at levels 14-16
// against the 1, 2, 4 ... 512 doubling pattern, pinned as scanned, never
// corrected to the doubling; the assassination grid header prints eleven
// victim bands but each row prints ten percent values, the columns pin in
// PRINTED ORDER with the band alignment riding the transcript, the bullet
// cells pin sentinel; the thieving hide-in-shadows column prints 70 at level
// 4 and 60 at level 5 against the +5 drift, as scanned; the row-12
// sixth-column 99, the row-13 sixth-column 110 and the row-15 eighth-column
// 99 prints pin as scanned; the hit-dice column (1D4 through 8D12+2D4), the
// disguise-class weapon rosters and the weapons-effects damage grid ride the
// transcript, the table pinning the uniform columns.
//
namespace rules {

// ---- the near eastern mythos, the gods (folio 4-5) ----

// the sixteen full stat-block deities of the pantheon (folio 4-5, PDF 6-7)
inline int ninGodRows()
    { return 16; }

// the Enlil-Marduk-Baal chariot horses move 36 feet (folio 4, PDF 6)
inline int ninEnlilChariotHorsesMoveFeet()
    { return 36; }

// Enlil carries 30 arrows of slaying plus the magic bow (folio 4, PDF 6)
inline int ninEnlilArrowsOfSlaying()
    { return 30; }

// the Enlil dagger +3, effective vs chaotic creatures only (folio 4, PDF 6)
inline int ninEnlilDaggerPlus()
    { return 3; }

// the Enlil dagger bonus applies only against chaotic creatures (folio 4, PDF
// 6)
inline bool ninEnlilDaggerVsChaoticOnly()
    { return true; }

// the deity armor classes - the four genuine minus-one prints (Enki-Ea,
// Ninhursag-Asherah, Ereshkigal-Mot, Nergal-Mekal) count in the sentinel
// census as the minus-one class (folios 4-5, PDF 6-7)
inline int ninGodAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return 0;
        case 4:
            return -1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return 2;
        case 11:
            return -3;
        case 12:
            return -3;
        case 13:
            return -2;
        case 14:
            return 2;
        case 15:
            return 2;
        default:
            return -1;
        }
    }

// the deity move in feet - the dual entries pin the first figure, the second
// rides the transcript (folios 4-5)
inline int ninGodMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 20;
        case 4:
            return 18;
        case 5:
            return 20;
        case 6:
            return 18;
        case 7:
            return 15;
        case 8:
            return 18;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 20;
        case 12:
            return 20;
        case 13:
            return 18;
        case 14:
            return 15;
        case 15:
            return 15;
        default:
            return -1;
        }
    }

// the deity hit points (folios 4-5)
inline int ninGodHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 290;
        case 2:
            return 250;
        case 3:
            return 200;
        case 4:
            return 275;
        case 5:
            return 200;
        case 6:
            return 200;
        case 7:
            return 150;
        case 8:
            return 200;
        case 9:
            return 175;
        case 10:
            return 150;
        case 11:
            return 300;
        case 12:
            return 300;
        case 13:
            return 200;
        case 14:
            return 150;
        case 15:
            return 150;
        default:
            return -1;
        }
    }

// the wizard level - sentinel for the see-below spell lists, never guessed
// (folios 4-5)
inline int ninGodMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 35;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return -1;
        case 11:
            return 20;
        case 12:
            return 18;
        case 13:
            return -1;
        case 14:
            return -1;
        case 15:
            return 14;
        default:
            return -1;
        }
    }

// the fighter ability, the Lord level (folios 4-5)
inline int ninGodFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 18;
        case 2:
            return 15;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 15;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 16;
        case 10:
            return 12;
        case 11:
            return 16;
        case 12:
            return 15;
        case 13:
            return 14;
        case 14:
            return 10;
        case 15:
            return 11;
        default:
            return -1;
        }
    }

// the psionic ability class (folios 4-5)
inline int ninGodPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 6;
        default:
            return -1;
        }
    }

// ---- the near eastern mythos, heroes, monsters, artifacts (folios 5-6) ----

// the eight heroes and kings with full stat blocks (folio 5, PDF 7)
inline int ninHeroRows()
    { return 8; }

// the two full stat-block monsters, Humbaba and the scorpion men (folios 5-6,
// PDF 7-8)
inline int ninCreatureRows()
    { return 2; }

// the twenty one-line other deities listed at folio 6 (PDF 8)
inline int ninOtherDeities()
    { return 20; }

// the hero armor classes - the as-a-normal-man prints pin sentinel, never
// guessed (folio 5, PDF 7)
inline int ninHeroAc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        default:
            return -1;
        }
    }

// the hero move in feet (folio 5)
inline int ninHeroMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 13;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        default:
            return -1;
        }
    }

// the hero hit points (folio 5)
inline int ninHeroHp(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 100;
        case 2:
            return 140;
        case 3:
            return 140;
        case 4:
            return 80;
        case 5:
            return 88;
        case 6:
            return 100;
        case 7:
            return 70;
        default:
            return -1;
        }
    }

// the magic level - nil pins sentinel (folio 5)
inline int ninHeroMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 11;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        default:
            return -1;
        }
    }

// the fighter ability, the Lord level (folio 5)
inline int ninHeroFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 13;
        case 2:
            return 15;
        case 3:
            return 11;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 9;
        default:
            return -1;
        }
    }

// the psionic ability class - nil pins sentinel (folio 5)
inline int ninHeroPsiClass(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        default:
            return -1;
        }
    }

// the monster armor classes (folios 5-6, PDF 7-8)
inline int ninCreatureAc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        default:
            return -1;
        }
    }

// the monster move in feet (folios 5-6)
inline int ninCreatureMove(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        default:
            return -1;
        }
    }

// the monster hit points (folios 5-6)
inline int ninCreatureHp(int b)
    {
        switch (b) {
        case 0:
            return 230;
        case 1:
            return 240;
        default:
            return -1;
        }
    }

// the magic level - nil pins sentinel (folios 5-6)
inline int ninCreatureMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 15;
        default:
            return -1;
        }
    }

// the fighter ability, the Lord level (folios 5-6)
inline int ninCreatureFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 15;
        default:
            return -1;
        }
    }

// the psionic ability class - nil pins sentinel (folios 5-6)
inline int ninCreaturePsiClass(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 1;
        default:
            return -1;
        }
    }

// the hero strength - the garbled 1895 (Enkidu) and 1875 (Aqht) prints pin
// sentinel, the 18-slash-percentile reading rides the transcript (folio 5,
// PDF 7)
inline int ninHeroStr(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return -1;
        case 2:
            return 20;
        case 3:
            return 16;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return -1;
        case 7:
            return 14;
        default:
            return -1;
        }
    }

// the hero intelligence (folio 5)
inline int ninHeroInt(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 12;
        case 2:
            return 20;
        case 3:
            return 19;
        case 4:
            return 17;
        case 5:
            return 13;
        case 6:
            return 16;
        case 7:
            return 14;
        default:
            return -1;
        }
    }

// the hero wisdom (folio 5)
inline int ninHeroWis(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 12;
        case 5:
            return 18;
        case 6:
            return 10;
        case 7:
            return 13;
        default:
            return -1;
        }
    }

// the hero constitution (folio 5)
inline int ninHeroCon(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 17;
        case 2:
            return 20;
        case 3:
            return 18;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 13;
        case 7:
            return 15;
        default:
            return -1;
        }
    }

// the hero dexterity (folio 5)
inline int ninHeroDex(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 20;
        case 3:
            return 17;
        case 4:
            return 16;
        case 5:
            return 14;
        case 6:
            return 17;
        case 7:
            return 17;
        default:
            return -1;
        }
    }

// the hero charisma (folio 5)
inline int ninHeroCha(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 15;
        case 6:
            return 17;
        case 7:
            return 18;
        default:
            return -1;
        }
    }

// the Axe Might of Heroes: +3 hit probability (folio 6, PDF 8)
inline int ninAxeMightPlus()
    { return 3; }

// the Axe Might of Heroes does 2-16 damage (folio 6, PDF 8)
inline int ninAxeMightDamageMin()
    { return 2; }

// the Axe Might of Heroes damage upper bound (folio 6, PDF 8)
inline int ninAxeMightDamageMax()
    { return 16; }

// the Bow of Anshan: all arrows +3 to hit (folio 6, PDF 8)
inline int ninBowOfAnshanPlus()
    { return 3; }

// the Breastplate Voice of Heroes acts as armor +5 (folio 6, PDF 8)
inline int ninBreastplateArmorBonus()
    { return 5; }

// the Breastplate Voice of Heroes weighs 30 shekels (folio 6, PDF 8)
inline int ninBreastplateShekels()
    { return 30; }

// the Mace Driver: +3 hit vs Lotan only (folio 6, PDF 8)
inline int ninMaceDriverPlus()
    { return 3; }

// the Mace Driver does 3-18 damage (folio 6, PDF 8)
inline int ninMaceDriverDamageMin()
    { return 3; }

// the Mace Driver damage upper bound (folio 6, PDF 8)
inline int ninMaceDriverDamageMax()
    { return 18; }

// the Mace Expeller: +3 hit vs Yamm only (folio 6, PDF 8)
inline int ninMaceExpellerPlus()
    { return 3; }

// the Mace Expeller does 3-18 damage (folio 6, PDF 8)
inline int ninMaceExpellerDamageMin()
    { return 3; }

// the Mace Expeller damage upper bound (folio 6, PDF 8)
inline int ninMaceExpellerDamageMax()
    { return 18; }

// the Mace Driver is only effective against Lotan (folio 6, PDF 8)
inline bool ninMaceDriverLotanOnly()
    { return true; }

// the Mace Expeller is only effective against Yamm (folio 6, PDF 8)
inline bool ninMaceExpellerYammOnly()
    { return true; }

// ---- the ninja identity, senses and movement (folio 7) ----

// no ninja may be higher than 16th level, any ninja may advance to that level
// (folio 7, PDF 9)
inline int ninLevelCap()
    { return 16; }

// the automatic 20 percent chance the encountered being considers the ninja
// of its own alignment (folio 7, PDF 9)
inline int ninSameAlignmentPercent()
    { return 20; }

// languages known equal to intelligence minus six (folio 7, PDF 9)
inline int ninLanguageBase()
    { return 6; }

// night vision: see clearly to 30 feet at first level (folio 7, PDF 9)
inline int ninNightVisionFeetLevel1()
    { return 30; }

// night vision: see clearly to 60 feet at sixth level (folio 7, PDF 9)
inline int ninNightVisionFeetLevel6()
    { return 60; }

// a ninja tracks as a ranger with a 20 percent penalty (folio 7, PDF 9)
inline int ninTrackingPenaltyPercent()
    { return 20; }

// simulated death lasts (1-6) x level + 1 turns (folio 7, PDF 9)
inline int ninSimulateDeathDiceSides()
    { return 6; }

// the simulated-death turn bonus (folio 7, PDF 9)
inline int ninSimulateDeathTurnsBonus()
    { return 1; }

// a ninja above second level travels up to 50 miles a day (folio 7, PDF 9)
inline int ninTravelMilesLevel2()
    { return 50; }

// a ninja above sixth level travels up to 75 miles a day (folio 7, PDF 9)
inline int ninTravelMilesLevel6()
    { return 75; }

// a ninja above tenth level travels up to 100 miles a day (folio 7, PDF 9)
inline int ninTravelMilesLevel10()
    { return 100; }

// the alignment of a ninja is strict neutrality (folio 7, PDF 9)
inline bool ninStrictNeutrality()
    { return true; }

// a ninja is incorruptible in matters of alignment, virtually impossible to
// change (folio 7, PDF 9)
inline bool ninAlignmentIncorruptible()
    { return true; }

// the same-alignment probability is generated only once per encounter,
// permanent, never re-rolled (folio 7, PDF 9)
inline bool ninSameAlignmentRolledOnce()
    { return true; }

// a ninja is surprised as are monks (folio 7, PDF 9)
inline bool ninSurprisedAsMonk()
    { return true; }

// ninja are nonpsychic (folio 7, PDF 9)
inline bool ninNonpsychic()
    { return true; }

// ninja are conditioned to die before revealing secrets, even when charmed
// (folio 9, PDF 11)
inline bool ninDieBeforeRevealingSecrets()
    { return true; }

// ninja do not talk in their sleep (folio 9, PDF 11)
inline bool ninDoNotTalkInSleep()
    { return true; }

// a ninja falls from walls as a monk, climbing the sheerest walls with his
// tools (folio 9, PDF 11)
inline bool ninFallsAsMonk()
    { return true; }

// ---- the ninja poisons (folio 8) ----

// the six ninja poison types (folio 8, PDF 10)
inline int ninPoisonTypes()
    { return 6; }

// kill poisons do 0-5 damage per level of strength (folio 8, PDF 10)
inline int ninKillPoisonDamageMax()
    { return 5; }

// instant poison takes effect in 1-2 melee rounds (folio 8, PDF 10)
inline int ninInstantPoisonMaxRounds()
    { return 2; }

// slow poison takes effect in 10-60 melee rounds (folio 8, PDF 10)
inline int ninSlowPoisonMinRounds()
    { return 10; }

// slow poison upper bound (folio 8, PDF 10)
inline int ninSlowPoisonMaxRounds()
    { return 60; }

// delayed poison takes effect in 90-140 melee rounds (folio 8, PDF 10)
inline int ninDelayedPoisonMinRounds()
    { return 90; }

// delayed poison upper bound (folio 8, PDF 10)
inline int ninDelayedPoisonMaxRounds()
    { return 140; }

// at level six the ninja must make three different poison types (folio 8, PDF
// 10)
inline int ninLevel6PoisonTypes()
    { return 3; }

// the three level-six poison types must be at least strength two (folio 8,
// PDF 10)
inline int ninLevel6PoisonStrengthMin()
    { return 2; }

// at level 12 the ninja must make all six types of at least strength one
// (folio 8, PDF 10)
inline int ninLevel12PoisonStrengthMin()
    { return 1; }

// viscous poison evaporates in about 12 hours after application (folio 8, PDF
// 10)
inline int ninViscousLifeHours()
    { return 12; }

// a 20 percent chance the poison use is noticed (folio 8, PDF 10)
inline int ninPoisonNoticedPercent()
    { return 20; }

// a ninja brews poisons and broths as an alchemist three levels lower (folio
// 7, PDF 9)
inline int ninAlchemistLevelsBelow()
    { return 3; }

// the poison strength made may not be larger than the number of levels
// selected for that poison (folio 8, PDF 10)
inline bool ninPoisonStrengthCappedByLevels()
    { return true; }

// a kill poison produces only half damage if the saving throw is made (folio
// 8, PDF 10)
inline bool ninKillPoisonHalfDamageOnSave()
    { return true; }

// a character hit by an accumulation of double his level in paralyze poisons
// dies through suffocation (folio 8, PDF 10)
inline bool ninParalyzeDoubleLevelSuffocation()
    { return true; }

// ninja poison may be made either fluid or viscous at the ninja discretion
// (folio 8, PDF 10)
inline bool ninPoisonFluidOrViscous()
    { return true; }

// viscous poison is used on weapons as per blade venom for coverage (folio 8,
// PDF 10)
inline bool ninViscousAsBladeVenom()
    { return true; }

// no saving throw is needed against neutralization brews (folio 8, PDF 10)
inline bool ninNeutralizeNoSavingThrow()
    { return true; }

// a cure brew is of half effect against the other two rates of onset poisons
// and alchemist poisons (folio 8, PDF 10)
inline bool ninCureHalfEffectOffDesign()
    { return true; }

// paralization and kill cures do not affect each other (folio 8, PDF 10)
inline bool ninParalyzeKillCuresDoNotCross()
    { return true; }

// ---- the ninja combat and disguise (folio 8) ----

// the -3 attack penalty with unmastered weapons, removed per weapon by
// mastery or disguise class (folio 8, PDF 10)
inline int ninUnmasteredAttackPenalty()
    { return 3; }

// a 4 percent advantage over an assassin in disguise recognition (folio 8,
// PDF 10)
inline int ninDisguiseAdvantagePercent()
    { return 4; }

// non-ninja using ninja gear: -3 on attack rolls (folio 9, PDF 11)
inline int ninNonNinjaAttackPenalty()
    { return 3; }

// non-ninja using ninja gear: -2 on damage rolls (folio 9, PDF 11)
inline int ninNonNinjaDamagePenalty()
    { return 2; }

// the ten-entry disguise list (folio 8, PDF 10)
inline int ninDisguiseClasses()
    { return 10; }

// the special disguise needs at least three choices from 1-8 (folio 8, PDF
// 10)
inline int ninSpecialDisguiseRequires()
    { return 3; }

// the nobility disguise needs at least five choices from 1-9 (folio 8, PDF
// 10)
inline int ninNobilityDisguiseRequires()
    { return 5; }

// teaching any ninja skill takes at least one month per item (folio 8, PDF
// 10)
inline int ninTeachMonthsMin()
    { return 1; }

// ninja will refuse to wear plate armor; chain or leather only in
// emergencies, chain disliked as noisy (folio 8, PDF 10)
inline bool ninRefusesPlate()
    { return true; }

// a ninja advances in combat steps as a fighter and has the combat adds of a
// fighter (folio 8, PDF 10)
inline bool ninAdvancesInCombatAsFighter()
    { return true; }

// a ninja may attack open-handed as a monk (folio 8, PDF 10)
inline bool ninOpenHandedAsMonk()
    { return true; }

// a ninja may use judo as a samurai (folio 8, PDF 10)
inline bool ninJudoAsSamurai()
    { return true; }

// a ninja gets a saving throw against all missile, melee and directed spell
// damage (folio 8, PDF 10)
inline bool ninSpecialSaveVsDamage()
    { return true; }

// the ninja saves as a magician of one level higher versus spells (folio 8,
// PDF 10)
inline bool ninSavesAsMagicianOneHigherVsSpells()
    { return true; }

// hobbits and dwarves do not add four levels for the ninja spell saves (folio
// 8, PDF 10)
inline bool ninHobbitsDwarvesNoFourLevelsVsSpells()
    { return true; }

// a ninja saves as a fighter (folio 8, PDF 10)
inline bool ninSavesAsFighter()
    { return true; }

// the unmastered-weapon penalty is removed only once per weapon even if used
// by several groups (folio 8, PDF 10)
inline bool ninPenaltyRemovedOncePerWeapon()
    { return true; }

// the non-ninja gear penalty applies no matter how much time is spent
// attempting mastery (folio 9, PDF 11)
inline bool ninNonNinjaMasteryNeverRemovesPenalty()
    { return true; }

// ---- the ninja progression and kit (folios 8-9) ----

// the seventeen progression rows, chigo through 16th level (folio 8, PDF 10)
inline int ninProgressionRows()
    { return 17; }

// the save vs damage by level - 15 through level 4, 12 through 9, 8 through
// 14, 3 at 15-16 (folio 8, PDF 10)
inline int ninSaveVsDamage(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 8;
        case 15:
            return 3;
        case 16:
            return 3;
        default:
            return -1;
        }
    }

// the weapons draws gained on reaching the level - the blank chigo and bushi
// cells pin sentinel (folio 8)
inline int ninDrawWeapons(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
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
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        default:
            return -1;
        }
    }

// the disguises draws gained on reaching the level - blanks pin sentinel
// (folio 8)
inline int ninDrawDisguises(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
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
        case 15:
            return 1;
        case 16:
            return 1;
        default:
            return -1;
        }
    }

// the ninja tools draws gained on reaching the level - blanks pin sentinel
// (folio 8)
inline int ninDrawTools(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        default:
            return -1;
        }
    }

// the equipment draws gained on reaching the level - blanks pin sentinel
// (folio 8)
inline int ninDrawEquipment(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        default:
            return -1;
        }
    }

// the basic kit: ninja-to, sageo, saya, tetsu-bishi, osaku - plus one
// disguise and one equipment choice (folio 9, PDF 11)
inline int ninBasicKitItems()
    { return 5; }

// the W D T E draws are gained immediately upon advancing a level (folio 8,
// PDF 10)
inline bool ninSkillsGainedImmediatelyOnLevel()
    { return true; }

// ---- the ninja thieving (folio 9) ----

// a ninja acts as a thief three levels below him (folio 9, PDF 11)
inline int ninThieveryLevelsBelow()
    { return 3; }

// a ninja scores the multiple damage of a thief one level higher (folio 9,
// PDF 11)
inline int ninMultipleDamageLevelsAbove()
    { return 1; }

// the five race and sex rows of the thieving bonus table (folio 9, PDF 11)
inline int ninRaceRows()
    { return 5; }

// the seventeen rows of the ninja thieving table, levels 0-16 (folio 9, PDF
// 11)
inline int ninThievingRows()
    { return 17; }

// the racial pick lock bonus (folio 9, PDF 11)
inline int ninRacePickLock(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the racial remove trap bonus (folio 9)
inline int ninRaceRemoveTrap(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 5;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the racial pick pocket bonus (folio 9)
inline int ninRacePickPocket(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the racial move silent bonus (folio 9)
inline int ninRaceMoveSilent(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the racial hide in shadows bonus (folio 9)
inline int ninRaceHideShadows(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the racial hear noise bonus (folio 9)
inline int ninRaceHearNoise(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 5;
        default:
            return -999;
        }
    }

// the pick lock percentages, -5 at chigo to 105 at 16th (folio 9, PDF 11)
inline int ninPickLock(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 20;
        case 6:
            return 25;
        case 7:
            return 35;
        case 8:
            return 40;
        case 9:
            return 45;
        case 10:
            return 55;
        case 11:
            return 65;
        case 12:
            return 75;
        case 13:
            return 85;
        case 14:
            return 95;
        case 15:
            return 100;
        case 16:
            return 105;
        default:
            return -999;
        }
    }

// the remove trap percentages, -10 at chigo to 100 at 16th (folio 9)
inline int ninRemoveTrap(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -5;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 20;
        case 7:
            return 30;
        case 8:
            return 35;
        case 9:
            return 40;
        case 10:
            return 50;
        case 11:
            return 60;
        case 12:
            return 70;
        case 13:
            return 80;
        case 14:
            return 90;
        case 15:
            return 95;
        case 16:
            return 100;
        default:
            return -999;
        }
    }

// the pick pocket percentages (folio 9)
inline int ninPickPocket(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 30;
        case 7:
            return 35;
        case 8:
            return 45;
        case 9:
            return 55;
        case 10:
            return 60;
        case 11:
            return 65;
        case 12:
            return 75;
        case 13:
            return 85;
        case 14:
            return 95;
        case 15:
            return 100;
        case 16:
            return 105;
        default:
            return -999;
        }
    }

// the move silent percentages (folio 9)
inline int ninMoveSilent(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 40;
        case 2:
            return 45;
        case 3:
            return 50;
        case 4:
            return 55;
        case 5:
            return 60;
        case 6:
            return 65;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 80;
        case 10:
            return 90;
        case 11:
            return 95;
        case 12:
            return 100;
        case 13:
            return 105;
        case 14:
            return 110;
        case 15:
            return 115;
        case 16:
            return 120;
        default:
            return -999;
        }
    }

// the hide in shadows percentages - the 70 and 60 prints at levels 4 and 5
// pin as scanned (folio 9)
inline int ninHideShadows(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 45;
        case 3:
            return 50;
        case 4:
            return 70;
        case 5:
            return 60;
        case 6:
            return 65;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 80;
        case 10:
            return 90;
        case 11:
            return 95;
        case 12:
            return 100;
        case 13:
            return 105;
        case 14:
            return 110;
        case 15:
            return 115;
        case 16:
            return 120;
        default:
            return -999;
        }
    }

// the hear noise percentages (folio 9)
inline int ninHearNoise(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 50;
        case 2:
            return 58;
        case 3:
            return 67;
        case 4:
            return 70;
        case 5:
            return 73;
        case 6:
            return 77;
        case 7:
            return 80;
        case 8:
            return 83;
        case 9:
            return 88;
        case 10:
            return 94;
        case 11:
            return 100;
        case 12:
            return 104;
        case 13:
            return 108;
        case 14:
            return 112;
        case 15:
            return 117;
        case 16:
            return 121;
        default:
            return -999;
        }
    }

// the fall off walls percentages, 15 at chigo down to -1 at 16th, the genuine
// -1 print (folio 9)
inline int ninFallOffWalls(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 14;
        case 2:
            return 13;
        case 3:
            return 12;
        case 4:
            return 11;
        case 5:
            return 10;
        case 6:
            return 9;
        case 7:
            return 8;
        case 8:
            return 7;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 4;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return -1;
        default:
            return -999;
        }
    }

// ---- the ninja assassination and gear (folios 9-10) ----

// a ninja operates as an assassin two levels higher (folio 9, PDF 11)
inline int ninAssassinationLevelsAbove()
    { return 2; }

// a ninja pays 15 percent of his fee to the jonin of his family, a chigo pays
// nothing (folio 9, PDF 11)
inline int ninFeeJoninPercent()
    { return 15; }

// the seventeen rows of the assassination probability and hire table (folio
// 9, PDF 11)
inline int ninAssassinationRows()
    { return 17; }

// the K price unit equals 1000 gold pieces (folio 9, PDF 11)
inline int ninAssassinationKGold()
    { return 1000; }

// the hiring cost in half-K units, 1 K at chigo doubling to 512 K at 13th,
// then the as-scanned 1006, 1518 and 2012 K prints at 14th-16th (folio 9, PDF
// 11)
inline int ninAssassCostHalfK(int b)
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
            return 16;
        case 8:
            return 32;
        case 9:
            return 64;
        case 10:
            return 128;
        case 11:
            return 256;
        case 12:
            return 512;
        case 13:
            return 1024;
        case 14:
            return 2012;
        case 15:
            return 3036;
        case 16:
            return 4024;
        default:
            return -1;
        }
    }

// the first printed percent column, in printed order - the header prints
// eleven victim bands, the rows ten values, the alignment riding the
// transcript (folio 9)
inline int ninAssassBand1(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 85;
        case 2:
            return 90;
        case 3:
            return 95;
        case 4:
            return 100;
        case 5:
            return 100;
        case 6:
            return 105;
        case 7:
            return 105;
        case 8:
            return 105;
        case 9:
            return 110;
        case 10:
            return 110;
        case 11:
            return 110;
        case 12:
            return 115;
        case 13:
            return 115;
        case 14:
            return 115;
        case 15:
            return 120;
        case 16:
            return 120;
        default:
            return -1;
        }
    }

// the second printed percent column (folio 9)
inline int ninAssassBand2(int b)
    {
        switch (b) {
        case 0:
            return 45;
        case 1:
            return 80;
        case 2:
            return 85;
        case 3:
            return 90;
        case 4:
            return 95;
        case 5:
            return 100;
        case 6:
            return 100;
        case 7:
            return 105;
        case 8:
            return 105;
        case 9:
            return 105;
        case 10:
            return 110;
        case 11:
            return 110;
        case 12:
            return 110;
        case 13:
            return 115;
        case 14:
            return 115;
        case 15:
            return 115;
        case 16:
            return 120;
        default:
            return -1;
        }
    }

// the third printed percent column (folio 9)
inline int ninAssassBand3(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 75;
        case 2:
            return 80;
        case 3:
            return 85;
        case 4:
            return 90;
        case 5:
            return 95;
        case 6:
            return 100;
        case 7:
            return 100;
        case 8:
            return 105;
        case 9:
            return 105;
        case 10:
            return 105;
        case 11:
            return 110;
        case 12:
            return 110;
        case 13:
            return 110;
        case 14:
            return 115;
        case 15:
            return 115;
        case 16:
            return 115;
        default:
            return -1;
        }
    }

// the fourth printed percent column (folio 9)
inline int ninAssassBand4(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 65;
        case 2:
            return 70;
        case 3:
            return 75;
        case 4:
            return 80;
        case 5:
            return 85;
        case 6:
            return 90;
        case 7:
            return 95;
        case 8:
            return 100;
        case 9:
            return 100;
        case 10:
            return 105;
        case 11:
            return 105;
        case 12:
            return 105;
        case 13:
            return 110;
        case 14:
            return 110;
        case 15:
            return 110;
        case 16:
            return 115;
        default:
            return -1;
        }
    }

// the fifth printed percent column (folio 9)
inline int ninAssassBand5(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 55;
        case 2:
            return 60;
        case 3:
            return 65;
        case 4:
            return 70;
        case 5:
            return 75;
        case 6:
            return 80;
        case 7:
            return 85;
        case 8:
            return 90;
        case 9:
            return 95;
        case 10:
            return 100;
        case 11:
            return 100;
        case 12:
            return 105;
        case 13:
            return 105;
        case 14:
            return 105;
        case 15:
            return 110;
        case 16:
            return 110;
        default:
            return -1;
        }
    }

// the sixth printed percent column - the 99 print at level 12 pins as scanned
// (folio 9)
inline int ninAssassBand6(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 40;
        case 2:
            return 45;
        case 3:
            return 50;
        case 4:
            return 55;
        case 5:
            return 60;
        case 6:
            return 65;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 80;
        case 10:
            return 85;
        case 11:
            return 90;
        case 12:
            return 99;
        case 13:
            return 110;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 105;
        default:
            return -1;
        }
    }

// the seventh printed percent column - the chigo bullet pins sentinel (folio
// 9)
inline int ninAssassBand7(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 55;
        case 8:
            return 60;
        case 9:
            return 65;
        case 10:
            return 70;
        case 11:
            return 75;
        case 12:
            return 95;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 105;
        default:
            return -1;
        }
    }

// the eighth printed percent column - the 99 print at level 15 pins as
// scanned (folio 9)
inline int ninAssassBand8(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 45;
        case 8:
            return 45;
        case 9:
            return 50;
        case 10:
            return 55;
        case 11:
            return 60;
        case 12:
            return 80;
        case 13:
            return 90;
        case 14:
            return 95;
        case 15:
            return 99;
        case 16:
            return 100;
        default:
            return -1;
        }
    }

// the ninth printed percent column (folio 9)
inline int ninAssassBand9(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 20;
        case 7:
            return 25;
        case 8:
            return 30;
        case 9:
            return 35;
        case 10:
            return 40;
        case 11:
            return 45;
        case 12:
            return 65;
        case 13:
            return 75;
        case 14:
            return 85;
        case 15:
            return 95;
        case 16:
            return 100;
        default:
            return -1;
        }
    }

// the tenth printed percent column - the four bullets pin sentinel (folio 9)
inline int ninAssassBand10(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 5;
        case 7:
            return 10;
        case 8:
            return 15;
        case 9:
            return 20;
        case 10:
            return 25;
        case 11:
            return 30;
        case 12:
            return 50;
        case 13:
            return 60;
        case 14:
            return 80;
        case 15:
            return 85;
        case 16:
            return 90;
        default:
            return -1;
        }
    }

// nine shuriken normally carried, nine the lucky number (folio 10, PDF 12)
inline int ninShurikenCarried()
    { return 9; }

// one shuriken costs 3 gold (folio 10, PDF 12)
inline int ninShurikenCostGold()
    { return 3; }

// one shuriken takes 3 days to make (folio 10, PDF 12)
inline int ninShurikenDays()
    { return 3; }

// the three kinds: dart, star and whistler, each a separate weapon choice
// (folio 10, PDF 12)
inline int ninShurikenKinds()
    { return 3; }

// one shuriken thrown per melee round for every two levels (folio 10, PDF 12)
inline int ninShurikenPerLevels()
    { return 2; }

// shuriken take an extra -1 on attack vs shields (folio 10, PDF 12)
inline int ninShurikenShieldPenalty()
    { return 1; }

// shuriken maximum range 30 feet (folio 10, PDF 12)
inline int ninShurikenRangeFeet()
    { return 30; }

// dart shuriken attack as a +2 dagger (folio 10, PDF 12)
inline int ninDartShurikenPlus()
    { return 2; }

// dart shuriken do a basic 1-6 vs a man-sized target (folio 10, PDF 12)
inline int ninDartShurikenDamageMax()
    { return 6; }

// two fukumi-bari needles spat per melee round (folio 10, PDF 12)
inline int ninFukumiNeedlesPerRound()
    { return 2; }

// at most five needles held in the mouth (folio 10, PDF 12)
inline int ninFukumiMouthMax()
    { return 5; }

// fukumi-bari spit up to 15 feet (folio 10, PDF 12)
inline int ninFukumiRangeFeet()
    { return 15; }

// a hit has a 50 percent chance the needle poisoned the target (folio 10, PDF
// 12)
inline int ninFukumiPoisonPercent()
    { return 50; }

// fukumi-bari cost 1 silver, no time (folio 10, PDF 12)
inline int ninFukumiCostSilver()
    { return 1; }

// the bo staff, the basic quarterstaff, costs nothing (folio 10, PDF 12)
inline int ninBoStaffCostGold()
    { return 0; }

// the ninja-to costs 10 gold, the price of a basic short sword (folio 10, PDF
// 12)
inline int ninNinjaToCostGold()
    { return 10; }

// the sageo cord costs 1 gold (folio 10, PDF 12)
inline int ninSageoCostGold()
    { return 1; }

// nage teppo eggshell grenades: 20 gold, one week (folio 10, PDF 11 tail)
inline int ninNageTeppoCostGold()
    { return 20; }

// the nage teppo make 2-8, treated as alchemist flash pellets (folio 11, PDF
// 12 tail)
inline int ninNageTeppoDamageMin()
    { return 2; }

// the nage teppo damage upper bound (folio 11)
inline int ninNageTeppoDamageMax()
    { return 8; }

// the sode tsutsu one-shot shotgun: 50 gold, one week (folio 11, PDF 12 tail)
inline int ninSodeTsutsuCostGold()
    { return 50; }

// the sode tsutsu fires its cone up to 30 feet away (folio 11)
inline int ninSodeTsutsuRangeFeet()
    { return 30; }

// the sode tsutsu cone is 10 feet across at the base (folio 11)
inline int ninSodeTsutsuConeFeet()
    { return 10; }

// the sode tsutsu does 3-24, save vs death for half (folio 11)
inline int ninSodeTsutsuDamageMax()
    { return 24; }

// the kakae ozutsu one-shot mortar: 50 gold, one week (folio 11)
inline int ninKakaeOzutsuCostGold()
    { return 50; }

// the kakae ozutsu minimum range 30 feet (folio 11)
inline int ninKakaeMinRangeFeet()
    { return 30; }

// the kakae ozutsu maximum range 90 feet (folio 11)
inline int ninKakaeMaxRangeFeet()
    { return 90; }

// the kakae ozutsu projectile bursts in a 10-foot blast radius (folio 11)
inline int ninKakaeBlastRadiusFeet()
    { return 10; }

// the kakae ozutsu does 1-20 within the blast, save vs death for half (folio
// 11)
inline int ninKakaeDamageMax()
    { return 20; }

// the uzume-bi: 20 gold and 3 days to make one (folio 11-12)
inline int ninUzumeBiCostGold()
    { return 20; }

// the uzume-bi manufacture time in days (folio 11-12)
inline int ninUzumeBiDays()
    { return 3; }

// the uzume-bi does 1-10, save vs damage (folio 12, PDF 12 tail)
inline int ninUzumeBiDamageMax()
    { return 10; }

// the kyoketsu shoge: 4 gold, one week (folio 10, PDF 12)
inline int ninKyoketsuShogeCostGold()
    { return 4; }

// the kyoketsu shoge manufacture time (folio 10)
inline int ninKyoketsuShogeDays()
    { return 7; }

// the shinobi zue staff: 6 gold and 4 days (folio 10, PDF 12)
inline int ninShinobiZueCostGold()
    { return 6; }

// the shinobi zue manufacture time (folio 10)
inline int ninShinobiZueDays()
    { return 4; }

// metsubushi do 1-2 plus poison (folio 12, PDF 12 tail)
inline int ninMetsubushiDamageMax()
    { return 2; }

// tetsu-bishi do 1-4 vs man-sized (folio 12)
inline int ninTetsuBishiDamageMaxMan()
    { return 4; }

// tetsu-bishi do 1-6 vs larger than man-sized (folio 12)
inline int ninTetsuBishiDamageMaxLarger()
    { return 6; }

// the hankyu bow does 1-6 (folio 12)
inline int ninHankyuDamageMax()
    { return 6; }

}   // namespace rules
