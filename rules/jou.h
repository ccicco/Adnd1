// =========================================================================================
// Adnd1 - rules/jou.h
// The Dragon issue-17 opener part one - the jousting matrix, the vampire
// doctrine, the dressing tables, the joke monsters, the tesseract, the
// adamanite price grid and the angels: the seven-chain round
// census 853 -> 854.
//
// Pinned from The Dragon Vol. III No. 3 (August 1978), the Curtiss-provided
// scan voice (single-voice: the issue-17 source is the uploaded Dm17.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 17). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the
// page feet (folios 3, 5, 10, 15, 16, 17, 20, 31, 32 and 33 print at the PDF
// pages 5, 7, 12, 17, 18, 19, 22, 33, 34 and 35) plus the TOC alignments
// (Jousting at print 4 = PDF 6, A Wizard With A Difference at print 10 = PDF
// 12, the Tesseracts at print 20 = PDF 22 continued at print 22 = PDF 24, the
// Angels at print 32 = PDF 34). The transcripts ride extract/dragon/017/p001
// through p040, landed this round; the article CHAIN is the ink unit, not the
// folio. The Ward wizard chain (print 10-13) rides the part-two round - the
// issue-10, issue-12 and issue-13 split pattern.
//
// Print quirks pinned AS SCANNED, noted never silent: no full-res visual
// check exists for this issue (the scan is a text-side transcript, no page
// renders), so garbled cells pin the sentinel, never guessed - the vampire
// minimum-strength cell prints 8:69 (the OD&D 18/69 percentile form misread,
// single voice) and pins the sentinel with the prose riding the transcript;
// the Healing angel secondary move prints the garbled 15/24 quarter and pins
// the sentinel; only the Angel of Wrath prints its hit-dice sides
// (eight-sided) - the other three types print bare dice counts and ride the
// sentinel; the adamanite arrow-points weight prints nil and pins the
// sentinel, the price printing 400@ per arrow; the sounds table prints
// TWENTY-ONE rows as scanned - the die-roll column runs 1 through 21, row 21
// the joke row (the dungeon master screams of anguish), pinned as scanned
// with the count const, never corrected to 20; the joust matrix prints 0* at
// HELM versus Steady Seat - pinned 0 with the flag; the Crs'tchen prints AC
// 12 and HD 1/2 in the EPT convention - the pin IS the conversion, noted; the
// sounds and sights rows themselves ride the transcript, the pinning carrying
// the counts, the chance and the interval.
//
namespace rules {

// ---- the jousting matrix, results and injuries (folio 4) ----

// the joust matrix base numbers add to a twenty-sided die roll (folio 4, PDF
// 6)
inline int jouMatrixDieSides()
    { return 20; }

// the six-step ride resolution - both select secretly, A resolves versus B
// defense, magical adjustments, level comparison, the roll, the reverse pass
// (folio 4)
inline int jouResolutionSteps()
    { return 6; }

// an unhorsed knight takes a 10 percent chance of injury (folio 4)
inline int jouUnhorsedInjuryPercent()
    { return 10; }

// a HELM hit that unhorses adds 20 to the injury percentile roll; a
// helmetless knight takes maximum lance damage (folio 4)
inline int jouHelmKnockoffInjuryBonusPercent()
    { return 20; }

// the joust matrix - eight aiming points: HELM, DC dexter calf, CP center
// plate, SC sinister calf, DF dexter forearm, FP front plate, SF sinister
// forearm, BASE (folio 4)
inline int jouMatrixRows()
    { return 8; }

// the joust results - four result rows: U unhorsed, U/B unhorsed with broken
// lance, B broken lance, G glancing blow (folio 4)
inline int jouResultsRows()
    { return 4; }

// the injury table - six percentile bands from 01-60 to the 00 kill (folio 4)
inline int jouInjuryRows()
    { return 6; }

// the joust system grants no bonuses for exceptional strength or dexterity
// (folio 4)
inline bool jouNoStrengthDexBonuses()
    { return true; }

// the defender receives the shield bonus against a HELM aim only when he
// played position 5, Shield High (folio 4)
inline bool jouShieldBonusHelmOnlyShieldHigh()
    { return true; }

// the matrix prints 0* at HELM versus Steady Seat - the glancing blow G on
// the helm knocks it off, shattering if non-protective (folio 4)
inline bool jouHelmSteadySeatZeroSpecial()
    { return true; }

// a G glancing blow is effectively a miss unless scored on the HELM (folio 4)
inline bool jouGlancingBlowMissExceptHelm()
    { return true; }

// a magical lance breaks only if the defender shield is rated higher than the
// lance; a non-magical lance breaks on U/B and B (folio 4)
inline bool jouMagicalLanceBreaksIfShieldHigher()
    { return true; }

// an injured knight must pass a constitution check versus resurrection or be
// rendered temporarily unconscious (folio 4)
inline bool jouInjuryConCheckVsResurrection()
    { return true; }

// rides continue until one knight is unhorsed (folio 4)
inline bool jouContinueRidesUntilUnhorsed()
    { return true; }

// the knight level comparison band - A level minus B level: minus 12 or more
// lands band 0, minus 11 to minus 8 band 1, minus 7 to minus 4 band 2, minus
// 3 to 3 band 3, 4-7 band 4, 8-11 band 5, 12-up band 6 (folio 4, PDF 6)
inline int jouLevelBand(int x)
    {
        if (x <= -12) return 0;
        if (x <= -8) return 1;
        if (x <= -4) return 2;
        if (x <= 3) return 3;
        if (x <= 7) return 4;
        if (x <= 11) return 5;
        return 6;
    }

// versus Lower Helm - the aiming point 1 column (folio 4)
inline int jouLowerHelm(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 9;
        case 6:
            return 2;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// versus Lean Right - the position 2 column (folio 4)
inline int jouLeanRight(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 9;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 2;
        default:
            return -1;
        }
    }

// versus Lean Left - the position 3 column (folio 4)
inline int jouLeanLeft(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 0;
        case 5:
            return 4;
        case 6:
            return 9;
        case 7:
            return 12;
        default:
            return -1;
        }
    }

// versus Steady Seat - the position 4 column, the HELM 0* cell (folio 4)
inline int jouSteadySeat(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 9;
        case 6:
            return 2;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// versus Shield High - the position 5 column (folio 4)
inline int jouShieldHigh(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 4;
        case 2:
            return 9;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 9;
        case 6:
            return 2;
        case 7:
            return 9;
        default:
            return -1;
        }
    }

// versus Shield Low - the position 6 column (folio 4)
inline int jouShieldLow(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// may take Lower Helm - position 1 allowed: only BASE among the aiming points
// (folio 4)
inline int jouAttLowerHelm(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        default:
            return -1;
        }
    }

// may take Lean Right - position 2 allowed: SC among them (folio 4)
inline int jouAttLeanRight(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -1;
        }
    }

// may take Lean Left - position 3 allowed: DC and SC (folio 4)
inline int jouAttLeanLeft(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -1;
        }
    }

// may take Steady Seat - position 4 allowed (folio 4)
inline int jouAttSteadySeat(int b)
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
        default:
            return -1;
        }
    }

// may take Shield High - position 5 allowed (folio 4)
inline int jouAttShieldHigh(int b)
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
        default:
            return -1;
        }
    }

// may take Shield Low - position 6 allowed (folio 4)
inline int jouAttShieldLow(int b)
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
        default:
            return -1;
        }
    }

// the -12 or more band column (folio 4)
inline int jouResMinus12(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 21;
        case 3:
            return 17;
        default:
            return -1;
        }
    }

// the -11 to -8 band column (folio 4)
inline int jouResMinus8(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 21;
        case 2:
            return 19;
        case 3:
            return 15;
        default:
            return -1;
        }
    }

// the -7 to -4 band column (folio 4)
inline int jouResMinus4(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 19;
        case 2:
            return 17;
        case 3:
            return 13;
        default:
            return -1;
        }
    }

// the -3 to 3 band column (folio 4)
inline int jouResMinus3to3(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 18;
        case 2:
            return 16;
        case 3:
            return 12;
        default:
            return -1;
        }
    }

// the 4-7 band column (folio 4)
inline int jouResPlus4(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 17;
        case 2:
            return 15;
        case 3:
            return 11;
        default:
            return -1;
        }
    }

// the 8-11 band column (folio 4)
inline int jouResPlus8(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 15;
        case 2:
            return 13;
        case 3:
            return 9;
        default:
            return -1;
        }
    }

// the 12-up band column (folio 4)
inline int jouResPlus12(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 13;
        case 2:
            return 11;
        case 3:
            return 7;
        default:
            return -1;
        }
    }

// the percentile band upper bound - 60, 75, 85, 95, 99 and the 00 roll pinned
// as 100 (folio 4)
inline int jouInjuryUpper(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 75;
        case 2:
            return 85;
        case 3:
            return 95;
        case 4:
            return 99;
        case 5:
            return 100;
        default:
            return -1;
        }
    }

// the hit points lost - 10, 25, 33, 50 and 80 percent; the 00 row 0 is the
// kill marker (folio 4)
inline int jouInjuryHpPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 25;
        case 2:
            return 33;
        case 3:
            return 50;
        case 4:
            return 80;
        case 5:
            return 0;
        default:
            return -1;
        }
    }

// ---- the vampire doctrine (folio 3) ----

// the gaseous form rushes the party at up to 50 mph, buffeting as a high wind
// - the print cites some sources (folio 3, PDF 5)
inline int jouVmpGaseousSpeedMph()
    { return 50; }

// the stake must impale the heart in one stroke or in a number not to exceed
// four - the final determination is the judge call (folio 3)
inline int jouVmpStakeStrokesMax()
    { return 4; }

// a vampire over one hundred years old crumbles to dust - both the dust and
// the coffin must then be burned (folio 3)
inline int jouVmpCrumbleDustAgeYears()
    { return 100; }

// the printed minimum-strength cell garbles as 8:69 in the single voice - the
// OD&D 18/69 percentile form misread; pinned sentinel, never guessed, the
// prose rides the transcript (folio 3)
inline int jouVmpMinStrength()
    { return -1; }

// the intelligent vampire charms as many as possible, tells them to wait, and
// retrieves the rest of the party (folio 3)
inline bool jouVmpCharmManyThenBanquet()
    { return true; }

// the thinking vampire whips rats, mice and charmed creatures into a spy
// network across the dungeon (folio 3)
inline bool jouVmpRatSpyNetwork()
    { return true; }

// the gaseous form is offensive as well as defensive - rushing past at speed,
// retracing its path, wearing the party down (folio 3)
inline bool jouVmpGaseousOffensiveAssault()
    { return true; }

// garlic is an inexpensive protection, at the cost of friends (folio 3)
inline bool jouVmpGarlicProtection()
    { return true; }

// a properly made circle in the ground with host fragments may prevent a
// charmed victim from leaving (folio 3)
inline bool jouVmpHostCircleProtection()
    { return true; }

// the mirror doctrine prints two views - the vampire runs from it, or the
// secondary more realistic view, stays at bay waiting (folio 3)
inline bool jouVmpMirrorTwoViews()
    { return true; }

// the stake works only of hawthorn or blackthorn and only when correctly
// installed (folio 3)
inline bool jouVmpStakeHawthornBlackthorn()
    { return true; }

// stakes are a temporary measure - they rot, burn away, are pulled out or
// jarred loose (folio 3)
inline bool jouVmpStakeTemporaryMeasure()
    { return true; }

// holy water poured into the coffin makes it a booby trap (folio 3)
inline bool jouVmpCoffinHolyWaterBoobyTrap()
    { return true; }

// a broken host or crucifix left in the coffin denies the vampire rest until
// kobolds fetch a dirt-filled replacement (folio 3)
inline bool jouVmpCoffinHostDenial()
    { return true; }

// stealing the coffin dirt is a trick worthy of the most lawful cleric (folio
// 3)
inline bool jouVmpDirtStealing()
    { return true; }

// a victim develops vampire characteristics only near death or when forced to
// drink the vampire blood (folio 3)
inline bool jouVmpVictimInfectsNearDeathOrBlood()
    { return true; }

// a sated vampire found in his coffin is lethargic and easier to handle
// (folio 3)
inline bool jouVmpSatedVampireLethargic()
    { return true; }

// ---- the sights and sounds doctrine (folio 15) ----

// every 30 minutes there is a 25 percent chance of hearing a random noise
// (folio 15, PDF 17)
inline int jouSsgSoundChancePercent()
    { return 25; }

// the noise check interval - every 30 minutes (folio 15)
inline int jouSsgSoundIntervalMinutes()
    { return 30; }

// the sounds table prints TWENTY-ONE rows as scanned - the die-roll column
// runs 1 through 21, row 21 the joke row (dungeon master screams of anguish);
// pinned as scanned, never corrected to 20, the rows ride the transcript
// (folio 15)
inline int jouSsgSoundRows()
    { return 21; }

// the sights table prints twenty rows, from blasted stone to corpses shackled
// to the wall; the rows ride the transcript (folio 15)
inline int jouSsgSightRows()
    { return 20; }

// the noises either cease if investigated or lead investigators away,
// possibly to a trap (folio 15)
inline bool jouSsgSoundsCeaseOrLeadAway()
    { return true; }

// the noises seldom lead into a position where their cause could be seen
// (folio 15)
inline bool jouSsgSoundsSeldomRevealCause()
    { return true; }

// the sounds are also good for noise rooms (folio 15)
inline bool jouSsgNoiseRoomsDoctrine()
    { return true; }

// the noises may be distorted or sound more distant due to the acoustical
// qualities of dungeons (folio 15)
inline bool jouSsgAcousticsDistort()
    { return true; }

// the apparitions are real to all senses, including touch (folio 15)
inline bool jouSsgSightsRealToAllSenses()
    { return true; }

// the apparitions vanish immediately after the party has left (folio 15)
inline bool jouSsgSightsVanishAfterLeaving()
    { return true; }

// the apparitions are great for misleading players who use them as landmarks
// (folio 15)
inline bool jouSsgSightsMisleadLandmarks()
    { return true; }

// the rusted useless armor or weapons flake away to piles of rust if picked
// up or touched (folio 15)
inline bool jouSsgRustFlakesCrumbleOnTouch()
    { return true; }

// the slime sight prints NOT Green Slime - the distinction noted (folio 15)
inline bool jouSsgSlimeNotGreenSlime()
    { return true; }

// ---- the magic munchkin (folio 16) ----

// the munchkin clans range from 3 to 12 (folio 16, PDF 18)
inline int jouMjkClanMin()
    { return 3; }

// the clan maximum, 12 (folio 16)
inline int jouMjkClanMax()
    { return 12; }

// the Munchkin Mother stands about four feet - 48 inches (folio 16)
inline int jouMjkMotherHeightInches()
    { return 48; }

// the offspring range from three to four feet - 36 inches at the low end
// (folio 16)
inline int jouMjkOffspringMinInches()
    { return 36; }

// the offspring upper bound, four feet - 48 inches (folio 16)
inline int jouMjkOffspringMaxInches()
    { return 48; }

// there is rarely a male parent to be found - a 5 percent chance, the male
// leaving soon after mating (folio 16)
inline int jouMjkMaleParentPercent()
    { return 5; }

// the offspring are predominately male - a 75 percent chance each (folio 16)
inline int jouMjkOffspringMalePercent()
    { return 75; }

// the Magic Munchkin - a 10 percent chance of one per 25 (folio 16)
inline int jouMjkMagicChancePercent()
    { return 10; }

// the magic variety frequency denominator - one per 25 (folio 16)
inline int jouMjkMagicPerGroup()
    { return 25; }

// a Magic Munchkin can use one magic spell per day (folio 16)
inline int jouMjkMagicSpellsPerDay()
    { return 1; }

// the munchkin spell use runs up to and including 9th level (folio 16)
inline int jouMjkMagicSpellLevelMax()
    { return 9; }

// the munchkin casts as an eighteenth level Wizard (folio 16)
inline int jouMjkMagicCasterLevel()
    { return 18; }

// the Munchkin Mother can do three spells per day (folio 16)
inline int jouMjkMotherSpellsPerDay()
    { return 3; }

// a 5 percent chance per week, cumulative, that ignored munchkins leave out
// of boredom (folio 16)
inline int jouMjkLeaveChancePercent()
    { return 5; }

// the munchkins live in a matriarchal society, one Munchkin Mother per clan
// (folio 16)
inline bool jouMjkMatriarchalClans()
    { return true; }

// munchkins are immune to most magic (folio 16)
inline bool jouMjkImmuneMostMagic()
    { return true; }

// munchkins are regenerative (folio 16)
inline bool jouMjkRegenerative()
    { return true; }

// munchkins are permanent pests - the one thing you can count on is that they
// stay and bring more (folio 16)
inline bool jouMjkPermanentPests()
    { return true; }

// bored munchkins can be quite troublesome - they have set fire to thieves
// and banged on fighters helms (folio 16)
inline bool jouMjkBoredTroublesome()
    { return true; }

// the leave chance is cumulative per week (folio 16)
inline bool jouMjkLeaveChanceCumulative()
    { return true; }

// normal munchkins can be escaped by flying or teleporting (folio 16)
inline bool jouMjkEscapeFlyingTeleport()
    { return true; }

// the escape does not work against the magic variety (folio 16)
inline bool jouMjkMagicEscapePrevented()
    { return true; }

// the only way to kill a munchkin is a special weapon such as a Sword of
// Munchkin Slaying - it kills automatically upon scoring a hit (folio 16)
inline bool jouMjkSlayingWeaponAutoKill()
    { return true; }

// some magic items can detect approaching munchkins - even the most ancient
// sometimes can (folio 16)
inline bool jouMjkAncientItemsDetect()
    { return true; }

// the munchkins should not be employed in normal dungeon expeditions -
// high-level bored parties and hot-shots only (folio 16)
inline bool jouMjkNotForNormalExpeditions()
    { return true; }

// ---- the scholar (folios 16-17) ----

// the Scholar number appearing, 1-4; in the special case of a symposium,
// 10-20 (folios 16-17, PDF 18-19)
inline int jouSchNumberMin()
    { return 1; }

// the number appearing upper bound, 4 (folio 16)
inline int jouSchNumberMax()
    { return 4; }

// the symposium special case, 10 at the low end (folio 16)
inline int jouSchSymposiumMin()
    { return 10; }

// the symposium upper bound, 20 (folio 16)
inline int jouSchSymposiumMax()
    { return 20; }

// the Scholar armor class, 9 (folio 16)
inline int jouSchArmorClass()
    { return 9; }

// the Scholar hit dice, 1-3 on six-sided dice (folio 16)
inline int jouSchHdMin()
    { return 1; }

// the hit dice upper bound, 3 (folio 16)
inline int jouSchHdMax()
    { return 3; }

// the hit dice sides, six-sided (folio 16)
inline int jouSchHdSides()
    { return 6; }

// the Scholar lair chance, 30 percent (folio 16)
inline int jouSchLairPercent()
    { return 30; }

// the Scholar treasure, 5 copper pieces - scholars are notoriously poor
// (folio 16)
inline int jouSchTreasureCopper()
    { return 5; }

// the Instructor spells - Confusion and Read Obscure Languages (folio 16)
inline int jouSchInstructorSpells()
    { return 2; }

// the Associate Professor spells - Fear, Time Stop and Book Missiles (folio
// 17)
inline int jouSchAssociateSpells()
    { return 3; }

// the Fool Professor spells - Power Word Stun, Academic Dust and Cause
// Boredom (folio 17)
inline int jouSchFoolSpells()
    { return 3; }

// the Book Missiles inflict 1-8 points of damage (folio 17)
inline int jouSchBookMissileMin()
    { return 1; }

// the Book Missiles upper bound, 8 (folio 17)
inline int jouSchBookMissileMax()
    { return 8; }

// the Academic Dust does 3-18 points of damage (folio 17)
inline int jouSchDustMin()
    { return 3; }

// the Academic Dust upper bound, 18 (folio 17)
inline int jouSchDustMax()
    { return 18; }

// the Academic Dust paralyzes the mind for 2-4 turns (folio 17)
inline int jouSchParalyzeMinTurns()
    { return 2; }

// the paralysis upper bound, 4 turns (folio 17)
inline int jouSchParalyzeMaxTurns()
    { return 4; }

// the foul pipe smoke can be generated in sufficient volume to produce
// Invisibility (folio 16)
inline bool jouSchPipeSmokeInvisibility()
    { return true; }

// the one powerful spell that seizes Scholars with immediate cardiac arrest,
// no saving throw - the incantation is Tenure denied (folio 17)
inline bool jouSchTenureDeniedNoSave()
    { return true; }

// Cause Boredom speedily induces gentle and peaceful sleep and the clock
// finally begins to move (folio 17)
inline bool jouSchCauseBoredomSleep()
    { return true; }

// three levels of Scholars exist - Instructors, Associate Professors and Fool
// Professors (folio 16)
inline bool jouSchThreeRanks()
    { return true; }

// ---- the crs'tchen (folio 17) ----

// the Crs'tchen number appearing, 1-12 (folio 17, PDF 19)
inline int jouCrsNumberMin()
    { return 1; }

// the number appearing upper bound, 12 (folio 17)
inline int jouCrsNumberMax()
    { return 12; }

// the Crs'tchen armor class, 12 - the EPT-style descending print, the pin IS
// the conversion, noted (folio 17)
inline int jouCrsArmorClass()
    { return 12; }

// the Crs'tchen move, 15 (folio 17)
inline int jouCrsMoveFeet()
    { return 15; }

// the lair line prints 80/1-100 - the lair percent 80, the 1-100 range riding
// the transcript (folio 17)
inline int jouCrsLairPercent()
    { return 80; }

// the treasure-in-lair line prints G:30 - gold at 30 percent (folio 17)
inline int jouCrsLairGoldPercent()
    { return 30; }

// a 33 percent chance the victim alignment is changed without his knowledge
// when the Crs'tchen speaks (folio 17)
inline int jouCrsAlignmentChangePercent()
    { return 33; }

// the transfix table - 30 percent for 3 turns (folio 17)
inline int jouCrsTransfix3Percent()
    { return 30; }

// the transfix table - 30 percent for 4 turns (folio 17)
inline int jouCrsTransfix4Percent()
    { return 30; }

// the transfix table - 30 percent for 5 turns (folio 17)
inline int jouCrsTransfix5Percent()
    { return 30; }

// the transfix table - 5 percent for a half day (folio 17)
inline int jouCrsTransfixHalfDayPercent()
    { return 5; }

// the transfix table - 5 percent for a full day (folio 17)
inline int jouCrsTransfixFullDayPercent()
    { return 5; }

// the begging - a 20 percent chance the Crs'tchen has taken 100-600 K (folio
// 17)
inline int jouCrsBegMoneyPercent()
    { return 20; }

// the taken money low bound, 100 K (folio 17)
inline int jouCrsBegMoneyMinK()
    { return 100; }

// the taken money upper bound, 600 K (folio 17)
inline int jouCrsBegMoneyMaxK()
    { return 600; }

// a 10 percent chance the Crs'tchen has your services for 1-12 days (folio
// 17)
inline int jouCrsBegServicePercent()
    { return 10; }

// the conscripted service low bound, 1 day (folio 17)
inline int jouCrsBegServiceMinDays()
    { return 1; }

// the conscripted service upper bound, 12 days (folio 17)
inline int jouCrsBegServiceMaxDays()
    { return 12; }

// the dead body must be burned within three turns or it regenerates and seeks
// out the player ceaselessly (folio 17)
inline int jouCrsBurnWithinTurns()
    { return 3; }

// the Eyes that save a caught victim - Eye No. 1 (folio 17)
inline int jouCrsEyeOne()
    { return 1; }

// Eye No. 16 (folio 17)
inline int jouCrsEyeSixteen()
    { return 16; }

// Eye No. 19 (folio 17)
inline int jouCrsEyeNineteen()
    { return 19; }

// the hit dice print 1/2 - half a hit die, pinned as the half marker (folio
// 17)
inline bool jouCrsHdHalf()
    { return true; }

// the Crs'tchen are never seen without their assumed human form, always
// smiling and well-dressed (folio 17)
inline bool jouCrsAlwaysSmilingWellDressed()
    { return true; }

// the Book of Eternal Existence - never without it, may attempt to read from
// it as an offensive action (folio 17)
inline bool jouCrsBookOfEternalExistence()
    { return true; }

// the Book senses whatever language the character knows and becomes
// translated to that language (folio 17)
inline bool jouCrsBookSelfTranslating()
    { return true; }

// the Book is usually covered in leather and its armour class is higher than
// that of its owner (folio 17)
inline bool jouCrsBookAcHigherThanOwner()
    { return true; }

// levels III and higher are permitted a saving throw against the discourse
// (folio 17)
inline bool jouCrsSaveLevelThreePlus()
    { return true; }

// Magic Users are allowed to use control of self (folio 17)
inline bool jouCrsMagicUserControlOfSelf()
    { return true; }

// the relentless attack - it never rests and hounds the victim until killed
// or lost (folio 17)
inline bool jouCrsRegeneratesUnlessBurned()
    { return true; }

// the Crs'tchen attacks relentlessly and from so many angles (folio 17)
inline bool jouCrsRelentless()
    { return true; }

// taken to one of their lairs, the forces there are too powerful - you are
// lost (folio 17)
inline bool jouCrsLairCaptureLost()
    { return true; }

// a victim once caught may be saved by Divine Intervention or Eyes No. 1, 16
// and 19 (folio 17)
inline bool jouCrsDivineInterventionSaves()
    { return true; }

// ---- the tesseract variant (folios 20+22) ----

// the tesseract dungeon holds eight cubical rooms - the central C, the E S W
// N ring, the frame F, the upper U and lower L (folios 20+22, PDF 22+24)
inline int jouTsvRooms()
    { return 8; }

// the central room C has four doors - the tesseract is not activated so long
// as any door remains open (folio 20)
inline int jouTsvCentralDoors()
    { return 4; }

// each cube of a tesseract shares one common side with each cube adjacent to
// it (folio 20)
inline int jouTsvCommonSides()
    { return 1; }

// each cube shares four common edges with each cube adjacent to it and with
// each cube immediately adjacent to the adjacent cube (folio 20)
inline int jouTsvCommonEdges()
    { return 4; }

// so long as any door remains open, the tesseract is not activated - the
// party passes through room C as though the others did not exist (folio 20)
inline bool jouTsvAnyDoorOpenNotActivated()
    { return true; }

// if all four doors are closed at the same time, no matter how briefly,
// thereafter all doors lead to the next room of the tesseract (folio 20)
inline bool jouTsvAllClosedActivates()
    { return true; }

// some escape method should be provided - a magical item such as a ring or
// bracelet, usable only in this tesseract (folio 20)
inline bool jouTsvEscapeItemDoctrine()
    { return true; }

// a dispell magic spell would cause every room except C to instantly
// disappear, along with anyone in them (folio 20)
inline bool jouTsvDispelVanishesAllButCentral()
    { return true; }

// entering F by climbing through the ceiling of U, one finds oneself climbing
// through the ceiling of F upside down - the corollary holds for L (folios
// 20+22)
inline bool jouTsvUpDownUpsideDownAnomaly()
    { return true; }

// unless the DM delights in people falling on their heads, no access between
// L or U and F should be designed in (folio 22 cont.)
inline bool jouTsvNoUpDownAccessRecommended()
    { return true; }

// some access should be planned for the U and L rooms directly above and
// below the central room (folio 20)
inline bool jouTsvUpperLowerAccessPlanned()
    { return true; }

// ---- the adamanite lore and price grid (folios 31-32) ----

// the adamanite base price grid - ten equipment rows, plate armor through
// arrow points (folios 31-32, PDF 33-34)
inline int jouAdmRows()
    { return 10; }

// charming adamanite beyond the original +2 costs about 8000 GP per level for
// full plate armor (folio 32)
inline int jouAdmCharmCostPlatePerLevel()
    { return 8000; }

// the charm cost is about 4000 GP per level for a sword or shield (folio 32)
inline int jouAdmCharmCostSwordShieldPerLevel()
    { return 4000; }

// the handcrafted uncharmed equipment carries an original +2 (folio 32)
inline int jouAdmCharmBasePlus()
    { return 2; }

// any charm after the initial plus two lasts at maximum one year and usually
// less (folio 31)
inline int jouAdmCharmMaxYears()
    { return 1; }

// hardened plate adamanite sells for 20-40 times its weight in gold (folio
// 32)
inline int jouAdmHardenedPriceMin()
    { return 20; }

// the hardened plate multiplier upper bound, 40 (folio 32)
inline int jouAdmHardenedPriceMax()
    { return 40; }

// temperable adamanite capable of holding an edge sells for 25-60 times its
// weight in gold (folio 32)
inline int jouAdmTemperablePriceMin()
    { return 25; }

// the temperable multiplier upper bound, 60 (folio 32)
inline int jouAdmTemperablePriceMax()
    { return 60; }

// the imitation alloys range from no effect to reduced effectiveness - a
// minus 1 to Hit Prob. or AC (folio 32)
inline int jouAdmImitationHitProbPenalty()
    { return 1; }

// the best unstable imitation - a plus 2 the first melee round (folio 32)
inline int jouAdmImitationPlusFirst()
    { return 2; }

// the unstable imitation decays to a plus 1 the second melee round (folio 32)
inline int jouAdmImitationPlusSecond()
    { return 1; }

// the charmer MU makes at least 100 percent profit - the cost to the MU
// approximately half the listed price (folio 32)
inline int jouAdmMuProfitPercent()
    { return 100; }

// about fourteen months after the accidental discovery, the goblin trouble
// struck the Valley of the Iron Pits (folio 32)
inline int jouAdmDiscoveryToInvasionMonths()
    { return 14; }

// after about five years of research Aolor realized he could not perfect the
// alloy alone (folio 32)
inline int jouAdmResearchYears()
    { return 5; }

// two years after the bargain with Dealanan the Mixer, the perfected formula
// arrived (folio 32)
inline int jouAdmFormulaReturnYears()
    { return 2; }

// Snog of the Scarred Jaw, the goblin leader - an 8th level fighter (folio
// 32)
inline int jouAdmSnogFighterLevel()
    { return 8; }

// the Snog bodyguards are 2nd level fighters (folio 32)
inline int jouAdmSnogGuardsLevel()
    { return 2; }

// the forfeited goblin money - one half to the king (folio 32)
inline int jouAdmTributeKingPercent()
    { return 50; }

// one quarter to the church that claimed the Blue Saint (folio 32)
inline int jouAdmTributeChurchPercent()
    { return 25; }

// one quarter to the soldiers who took part in the clean up (folio 32)
inline int jouAdmTributeSoldiersPercent()
    { return 25; }

// the best way to test for true adamanite is with a diamond - it scratches
// all imitations but not the real thing (folio 32)
inline bool jouAdmDiamondScratchesImitations()
    { return true; }

// adamanite costs twice as much and twice as long as iron to charm for the
// first three levels (folio 31)
inline bool jouAdmCharmTwiceCostTwiceTime()
    { return true; }

// after the first three levels both price and time zoom way out of proportion
// (folio 31)
inline bool jouAdmCharmZoomAfterThree()
    { return true; }

// the imitation leaning heavily on mithril can increase HP and AC but is
// unstable (folio 32)
inline bool jouAdmUnstableImitations()
    { return true; }

// the MU cost is approximately half the listed price - purchase direct from a
// MU assumed (folio 32)
inline bool jouAdmMuCostHalfListed()
    { return true; }

// because of the MU reluctance, a person with +5 armor or shield can just
// about name his price (folio 32)
inline bool jouAdmReluctantMuMarket()
    { return true; }

// the arrow points price prints 400@ - per arrow at 400 GP, the at-sign
// riding the transcript (folio 32)
inline bool jouAdmArrowPointsPerArrowAt()
    { return true; }

// the equipment price in GP - plate 20000, chain 14000, helm 4000, shield
// 4000, broad sword 4000, two-handed sword 5000, battle-axe 3000, mace and
// flail 2000, dagger 1500, arrow points 400 at (folios 31-32)
inline int jouAdmPriceGold(int b)
    {
        switch (b) {
        case 0:
            return 20000;
        case 1:
            return 14000;
        case 2:
            return 4000;
        case 3:
            return 4000;
        case 4:
            return 4000;
        case 5:
            return 5000;
        case 6:
            return 3000;
        case 7:
            return 2000;
        case 8:
            return 1500;
        case 9:
            return 400;
        default:
            return -1;
        }
    }

// the equipment weight in GP - the arrow points weight prints nil and pins
// the sentinel (folios 31-32)
inline int jouAdmWeightGold(int b)
    {
        switch (b) {
        case 0:
            return 600;
        case 1:
            return 400;
        case 2:
            return 40;
        case 3:
            return 120;
        case 4:
            return 40;
        case 5:
            return 120;
        case 6:
            return 80;
        case 7:
            return 80;
        case 8:
            return 16;
        case 9:
            return -1;
        default:
            return -1;
        }
    }

// ---- the angels (folios 32-33) ----

// the angel stat grid - the four types recorded by the Chronicle of Bishop
// Matthews in Rudigore (folios 32-33, PDF 34-35)
inline int jouAngRows()
    { return 4; }

// the prayer response base - a 1 percent chance per cleric level (folio 33)
inline int jouAngResponseBasePercent()
    { return 1; }

// the classical celestial hierarchy has nine members (folio 33)
inline int jouAngHierarchyTypes()
    { return 9; }

// only four types of angels are recorded as appearing on Earth (folio 33)
inline int jouAngRecordedTypes()
    { return 4; }

// the Angel of Wrath wields a +5 Holy Sword - it vanishes with the golden
// armor and shield if the angel is vanquished (folio 33)
inline int jouAngWrathSwordPlus()
    { return 5; }

// the Angel of Wrath creates a double-strength Wall of Fire three times per
// day (folio 33)
inline int jouAngWrathWallPerDay()
    { return 3; }

// the Wrath wall of fire is double strength (folio 33)
inline int jouAngWrathWallMultiplier()
    { return 2; }

// the Angel of Wrath pronounces a Holy Word once per day (folio 33)
inline int jouAngWrathHolyWordPerDay()
    { return 1; }

// the Seraphim generates a triple-strength Wall of Fire (folio 33)
inline int jouAngSeraphWallMultiplier()
    { return 3; }

// the Seraphim uses a Holy Word once per day (folio 33)
inline int jouAngSeraphHolyWordPerDay()
    { return 1; }

// the Seraphim uses any Symbol once per day (folio 33)
inline int jouAngSeraphSymbolPerDay()
    { return 1; }

// once a day the Seraphim calls down the Wrath of God - a double-strength
// Meteor Swarm (folio 33)
inline int jouAngSeraphWrathOfGodMultiplier()
    { return 2; }

// the Seraphim can call to its aid 2-16 Type I angels (folio 33)
inline int jouAngSummonOneMin()
    { return 2; }

// the Type I summon upper bound, 16 (folio 33)
inline int jouAngSummonOneMax()
    { return 16; }

// the Seraphim summons 1-4 Type II angels (folio 33)
inline int jouAngSummonTwoMin()
    { return 1; }

// the Type II summon upper bound, 4 (folio 33)
inline int jouAngSummonTwoMax()
    { return 4; }

// the Seraphim summons 1-6 Type III angels (folio 33)
inline int jouAngSummonThreeMin()
    { return 1; }

// the Type III summon upper bound, 6 (folio 33)
inline int jouAngSummonThreeMax()
    { return 6; }

// all angels teleport with no chance of error (folio 33)
inline bool jouAngTeleportNoError()
    { return true; }

// the Continual Light of varying degree is common to all angels (folio 33)
inline bool jouAngContinualLightCommon()
    { return true; }

// the Bless is common to all angels (folio 33)
inline bool jouAngBlessCommon()
    { return true; }

// the Fear is common to all angels (folio 33)
inline bool jouAngFearCommon()
    { return true; }

// the Detect Evil is common to all angels (folio 33)
inline bool jouAngDetectEvilCommon()
    { return true; }

// all angels can speak any human tongue (folio 33)
inline bool jouAngSpeakHumanTongues()
    { return true; }

// all angels can Speak With Dead (folio 33)
inline bool jouAngSpeakWithDead()
    { return true; }

// the very presence of an angel turns undead as a Patriarch (folio 33)
inline bool jouAngTurnUndeadAsPatriarch()
    { return true; }

// angels are immune to psionic attack (folio 33)
inline bool jouAngImmunePsionic()
    { return true; }

// angels are immune to the Finger of Death (folio 33)
inline bool jouAngImmuneFingerOfDeath()
    { return true; }

// the Wrath golden armor, shield and sword disappear if the angel is
// vanquished (folio 33)
inline bool jouAngWrathArmorVanishes()
    { return true; }

// the Angel of Healing touch has the ability of Regeneration (folio 33)
inline bool jouAngHealingRegenerationTouch()
    { return true; }

// if necessary the Angel of Healing fights with a Flaming Sword (folio 33)
inline bool jouAngHealingFlamingSword()
    { return true; }

// the Archangel of Mercy fights with a Sword of Sharpness (folio 33)
inline bool jouAngMercySwordOfSharpness()
    { return true; }

// the Archangel of Mercy is not affected by a Time Stop (folio 33)
inline bool jouAngMercyNoTimeStop()
    { return true; }

// the Seraphim fights with a Vorpal Blade (folio 33)
inline bool jouAngSeraphVorpalBlade()
    { return true; }

// a Seraphim cannot be Time Stopped, Charmed, Held, or rendered stunned or
// unconscious by any means (folio 33)
inline bool jouAngSeraphUnstunnable()
    { return true; }

// angels have no earthly lair or treasure unless guarding some Holy Relic
// (folio 33)
inline bool jouAngNoLairUnlessRelic()
    { return true; }

// there should be no random encounters with angels (folio 33)
inline bool jouAngNoRandomEncounters()
    { return true; }

// angels should only appear on Earth with a particular mission, a
// manifestation of a god will (folio 33)
inline bool jouAngMissionManifestationOnly()
    { return true; }

// the armor class - 0, 9, minus 1 and minus 3 (folios 32-33)
inline int jouAngAc(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 9;
        case 2:
            return -1;
        case 3:
            return -3;
        default:
            return -1;
        }
    }

// the hit dice - 10, 6, 12 and 16 (folios 32-33)
inline int jouAngHitDice(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 6;
        case 2:
            return 12;
        case 3:
            return 16;
        default:
            return -1;
        }
    }

// the hit-dice sides - only the Wrath prints eight-sided; the three
// unspecified prints ride the sentinel (folios 32-33)
inline int jouAngDiceSides(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        default:
            return -1;
        }
    }

// the magic resistance - 65 without the Holy Sword, 75, 85 without the sword,
// 95 base (folios 32-33)
inline int jouAngMagicResist(int b)
    {
        switch (b) {
        case 0:
            return 65;
        case 1:
            return 75;
        case 2:
            return 85;
        case 3:
            return 95;
        default:
            return -1;
        }
    }

// the primary move in feet - 12, 15, 15 and 24 (folios 32-33)
inline int jouAngMovePrimary(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 24;
        default:
            return -1;
        }
    }

// the secondary move in feet - the Healing 15/24 quarter-garble rides the
// sentinel, never guessed; 24, 30 and 48 pin clean (folios 32-33)
inline int jouAngMoveSecondary(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return -1;
        case 2:
            return 30;
        case 3:
            return 48;
        default:
            return -1;
        }
    }

// the weapon floor - any magic weapon for the Wrath, none printed for the
// Healing at 0, plus 2 or better for the Mercy, plus 3 for the Seraphim
// (folios 32-33)
inline int jouAngWeaponFloor(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return -1;
        }
    }

}   // namespace rules
