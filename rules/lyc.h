// =========================================================================================
// Adnd1 - rules/lyc.h
// The Dragon issue-14 opener - the Name That Monster Contest #1 winners
// (folio 3) and the Gregory Rihn lycanthropy variant (folios 29-32): the
// two-chain issue-11 walk pattern
// census 847 -> 848.
//
// Pinned from The Dragon Vol. II No. 8 (May 1978), the archive.org scan voice
// (single-voice: no chat-side upload cross-check exists for issue 14; the
// source lives in the archive.org item accessory-dragon-magazine-012, file
// Accessory - Dragon Magazine #014_djvu.xml). PRINT FOLIO = PDF PAGE MINUS
// TWO in this issue, verified at the TOC alignments (the Rust Monster
// interview at print 14 = PDF 16, the Monty Haul piece at print 21 = PDF 23,
// the Total Person charts at print 24 = PDF 26, Wormy at print 26 = PDF 28,
// Finieous Fingers at print 27 = PDF 29). The transcripts ride
// extract/dragon/014/p001 through p036, landed this round; the article CHAIN
// is the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: the Jarnkung hit-dice
// cell prints the =) bar garble in the djvu OCR and resolves at the full-res
// scan to 5 per the R919 one-visual-check precedent; the Crawler hit-dice
// line prints the prose "3 eight sided + 1 four sided = 3 1/2", the fraction
// garbled to 3 percent in the OCR and resolved at the full-res scan, pinned
// as the 3-and-1 dice with the 7-halves total, the scaled-int conversion
// noted; the experience-grid row-4 cell prints 1000 where the article own
// worked example gives 10,000 for the werebear of the fourth - pinned
// as-scanned, the dropped zero noted; the grid change-time pins in halves (6
// rds = 12, 1/2 rd = 1) and the predominance ladder pins its printed leading
// zeros as 10 through 01; the Crawler move pins in feet-per-turn as printed,
// the unit noted. The one-visual-check precedent of R919 (the full-res scan
// plus the djvu word geometry) stands for any future cell dispute.
//
namespace rules {

// ---- the Name That Monster Contest #1 winners (folio 3) ----

// the Jarnkung armor class 3 (folio 3)
inline int lycJarnkungAc()
    { return 3; }

// the Jarnkung move 9 inches (folio 3)
inline int lycJarnkungMoveInches()
    { return 9; }

// the Jarnkung hit dice 5 - the cell prints the =) bar garble in the djvu OCR
// and resolves at the full-res scan to 5, the R919 one-visual-check
// precedent, noted never silent (folio 3)
inline int lycJarnkungHitDice()
    { return 5; }

// the Jarnkung 15 percent in lair (folio 3)
inline int lycJarnkungLairPercent()
    { return 15; }

// the Jarnkung magic resistance 20 percent (folio 3)
inline int lycJarnkungMagicResistance()
    { return 20; }

// the Jarnkung number appearing 1-6, the floor (folio 3)
inline int lycJarnkungAppearingMin()
    { return 1; }

// the appearance ceiling, 1-6, or 2-12 in lair (folio 3)
inline int lycJarnkungAppearingMax()
    { return 6; }

// the in-lair number appearing 2-12, the floor (folio 3)
inline int lycJarnkungLairAppearingMin()
    { return 2; }

// the in-lair ceiling, 2-12 (folio 3)
inline int lycJarnkungLairAppearingMax()
    { return 12; }

// the Jarnkung tail does 2-12 points, the floor (folio 3)
inline int lycJarnkungTailDamageMin()
    { return 2; }

// the tail ceiling, 2-12, or two weapons by weapon type (folio 3)
inline int lycJarnkungTailDamageMax()
    { return 12; }

// the Jarnkung origin - a lonely wizard created them about 250 years ago to
// watch his keep (folio 3)
inline int lycJarnkungWizardYearsAgo()
    { return 250; }

// the Cursed Crimson Crawler move 60 feet per turn, the unit as printed,
// noted (folio 3)
inline int lycCrawlerMoveFeetPerTurn()
    { return 60; }

// the Crawler hit dice print the prose "3 eight sided + 1 four sided = 3 1/2"
// - three d8, the fraction garbled to 3% in the djvu OCR and resolved at the
// full-res scan (folio 3)
inline int lycCrawlerHdEights()
    { return 3; }

// the Crawler hit dice - one d4 (folio 3)
inline int lycCrawlerHdFours()
    { return 1; }

// the Crawler hit-dice total 3 1/2 pinned in halves as 7, the conversion
// noted (folio 3)
inline int lycCrawlerHdHalves()
    { return 7; }

// the Cursed Crimson Crawler armor class 7 (folio 3)
inline int lycCrawlerAc()
    { return 7; }

// the Crawler makes 2 attacks (folio 3)
inline int lycCrawlerAttacks()
    { return 2; }

// the Crawler close combat does 1-6 points per attack, the floor (folio 3)
inline int lycCrawlerDamageMin()
    { return 1; }

// the Crawler damage ceiling, 1-6 (folio 3)
inline int lycCrawlerDamageMax()
    { return 6; }

// the Crawler throws heavy rocks doing 1-12 points, the floor (folio 3)
inline int lycCrawlerRockDamageMin()
    { return 1; }

// the rock ceiling, 1-12 (folio 3)
inline int lycCrawlerRockDamageMax()
    { return 12; }

// the rock range is 10 feet per hit point of the Crawler (folio 3)
inline int lycCrawlerRockRangeFeetPerHp()
    { return 10; }

// the Crawler death-burst - all within 30 feet become enraged at each other
// (folio 3)
inline int lycCrawlerRageRadiusFeet()
    { return 30; }

// the rage lasts 1-4 melee rounds, the floor (folio 3)
inline int lycCrawlerRageMinRounds()
    { return 1; }

// the rage ceiling, 1-4 melee rounds (folio 3)
inline int lycCrawlerRageMaxRounds()
    { return 4; }

// the Ulik armor class 4 (folio 3)
inline int lycUlikAc()
    { return 4; }

// the Ulik movement 14 (folio 3)
inline int lycUlikMoveInches()
    { return 14; }

// the Ulik hit dice 4 plus 2 (folio 3)
inline int lycUlikHitDice()
    { return 4; }

// the Ulik hit-dice plus, 4+2 (folio 3)
inline int lycUlikHitDicePlus()
    { return 2; }

// the Ulik 20 percent in lair, treasure type I (folio 3)
inline int lycUlikLairPercent()
    { return 20; }

// the Ulik number appearing 1-6, the floor (folio 3)
inline int lycUlikAppearingMin()
    { return 1; }

// the appearance ceiling, 1-6 (folio 3)
inline int lycUlikAppearingMax()
    { return 6; }

// the Ulik pupiless white eyes hypnotize a surprised victim on 90 percent
// (folio 3)
inline int lycUlikHypnotizeSurprisedPercent()
    { return 90; }

// the hypnotize chance against a non-surprised victim, 50 percent (folio 3)
inline int lycUlikHypnotizeAwarePercent()
    { return 50; }

// the tender tail growth serves as a mace for 10-40 blows before falling off,
// the floor (folio 3)
inline int lycUlikTailBlowMin()
    { return 10; }

// the tail-mace ceiling, 10-40 blows (folio 3)
inline int lycUlikTailBlowMax()
    { return 40; }

// the fallen growth regenerates after 6-8 months, the floor (folio 3)
inline int lycUlikTailRegrowMinMonths()
    { return 6; }

// the regeneration ceiling, 6-8 months (folio 3)
inline int lycUlikTailRegrowMaxMonths()
    { return 8; }

// the Jarnkung are only affected by magic weapons, highly intelligent (folio
// 3)
inline bool lycJarnkungMagicWeaponsOnly()
    { return true; }

// the Jarnkung have ESP, the older ones rumored to use psionic powers (folio
// 3)
inline bool lycJarnkungEspRumoredPsionics()
    { return true; }

// the Crawler spiked tail knob bursts its pent-up hatred if the monster is
// killed, saving throws as against poison, those saved still attackable by
// the cursed (folio 3)
inline bool lycCrawlerHatredBurstOnDeath()
    { return true; }

// the Ulik rear up from hiding, the hypnotic eyes working on the surprised
// (folio 3)
inline bool lycUlikHypnoticEyes()
    { return true; }

// the Ulik tail growth is very tender and after 10-40 blows falls off,
// regenerating after 6-8 months (folio 3)
inline bool lycUlikTailGrowthFallsOff()
    { return true; }

// the Name That Monster Contest #1 winners printing in full - the Jarnkung
// the winner, the Cursed Crimson Crawler the first runner-up, the Ulik the
// second runner-up, the stats deferred from the issue-13 names-only list
// (folio 3)
inline bool lycContestWinnersThree()
    { return true; }

// ---- the onset of the condition (folios 29-30) ----

// characters bitten by lycanthropes have a 50 percent chance of catching the
// condition (folio 29)
inline int lycBiteCatchPercent()
    { return 50; }

// the first shape-change occurs in 30-60 days, the floor (folio 29)
inline int lycOnsetMinDays()
    { return 30; }

// the onset ceiling, 30-60 days (folio 29)
inline int lycOnsetMaxDays()
    { return 60; }

// at the first transformation the animal nature predominates on a 95 percent
// chance, resulting in blind panic (folio 29)
inline int lycFirstChangePanicPercent()
    { return 95; }

// a 10 percent chance the shock causes insane subjugation of the human
// persona to the animal nature, persisting until cured as an insanity (folio
// 29)
inline int lycSubjugationPercent()
    { return 10; }

// an exhausted lycanthrope sleeping has about a 5 percent chance of reverting
// to human form, undependable, higher under extreme exhaustion or severe
// wounds (folio 30)
inline int lycSleepRevertPercent()
    { return 5; }

// a new lycanthrope cannot revert to human form at will until 2500 experience
// points gained beyond the pre-infection total, the grid level-2 figure
// (folio 30)
inline int lycRevertWillXp()
    { return 2500; }

// a lycanthrope may transform only once per day on his own (folio 30)
inline int lycVoluntaryChangesPerDay()
    { return 1; }

// a more experienced lycanthrope may induce a second shapechange in another,
// requiring a full day of rest and no more than once per day (folio 30)
inline int lycInducedChangeRestDays()
    { return 1; }

// over the incubation the victim suffers a proportional loss of all magical,
// clerical or psychic ability, complete at the first transformation (folio
// 29)
inline bool lycAbilityLossProgressive()
    { return true; }

// children of uncured lycanthropes inherit the condition, transmitted only
// via the bloodstream and not via intercourse (folio 30)
inline bool lycChildrenInheritCondition()
    { return true; }

// hereditary werebears not raised among their own kind have their first
// transformation at the onset of puberty (folio 30)
inline bool lycFirstTransformationAtPuberty()
    { return true; }

// lycanthropes in animal shape are sterile as regards normal animals of the
// same type (folio 30)
inline bool lycAnimalShapeSterile()
    { return true; }

// a clerical cure disease or a healing cure lycanthropy cast upon the subject
// in animal form results in permanent loss of the disease and reversion to
// human form (folio 30)
inline bool lycCureDiseaseOrCureLycanthropyPermanent()
    { return true; }

// ---- the lycanthrope experience grid (folio 32) ----

// the lycanthrope experience grid - ten levels (folio 32, PDF 34)
inline int lycProgressRows()
    { return 10; }

// the experience ladder - 0, 2500, 5000, the row-4 cell printing 1000 (the
// article own worked example: 10,000 for the werebear of the fourth, the
// dropped zero noted as-scanned), 20000, 35000, 50000, 100000, 150000, 200000
// (folio 32)
inline int lycExperience(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2500;
        case 2:
            return 5000;
        case 3:
            return 1000;
        case 4:
            return 20000;
        case 5:
            return 35000;
        case 6:
            return 50000;
        case 7:
            return 100000;
        case 8:
            return 150000;
        case 9:
            return 200000;
        default:
            return -1;
        }
    }

// the changes per day - one at levels 1-2, two at 3-4, three at 5-6, four at
// 7-8, five at 9-10 (folio 32)
inline int lycChangesPerDay(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
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
        default:
            return -1;
        }
    }

// the chance of involuntary changes in combat - 50 at levels 1-2, 25 at 3-4,
// 10 at 5, 5 at 6-7, 0 from level 8 (folio 32)
inline int lycInvoluntaryCombPercent(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 25;
        case 3:
            return 25;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -1;
        }
    }

// the chance of involuntary changes in sleep - the levels 1-3 cells print the
// single combat-or-sleep value pinned to both columns, noted; 50 at 1-2, 25
// at 3, 10 at 4, 5 at 5-8, 2 at 9, 1 at 10 (folio 32)
inline int lycInvoluntarySleepPercent(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 50;
        case 2:
            return 25;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 1;
        default:
            return -1;
        }
    }

// the chance of changing back voluntarily - 0 at level 1 rising through 50,
// 60, 75, 80, 85, 90, 95 to 99 at levels 9-10 (folio 32)
inline int lycChangeBackPercent(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 50;
        case 2:
            return 60;
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
            return 99;
        case 9:
            return 99;
        default:
            return -1;
        }
    }

// the chance of beast-nature predominance DECREASING with control, printed
// with leading zeros - 10, 09, 08, 07, 06, 05, 04, 03, 02, 01 percent (folio
// 32)
inline int lycBeastPredominancePercent(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 8;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 1;
        default:
            return -1;
        }
    }

// the speak-language-of-species comprehension - 0 at level 1 rising 10, 20,
// 30, 50, 75, 90, 95, 99 to 100 percent at level 10 (folio 32)
inline int lycSpeakLanguagePercent(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 50;
        case 5:
            return 75;
        case 6:
            return 90;
        case 7:
            return 95;
        case 8:
            return 99;
        case 9:
            return 100;
        default:
            return -1;
        }
    }

// the time required for change pinned in HALVES - 6 melee rounds at levels
// 1-2 (12 halves), 4 rounds at 3-4 (8), 2 rounds at 5-6 (4), 1 round at 7-8
// (2), the half-round at 9-10 (1), the scaled-int conversion noted (folio 32)
inline int lycChangeTimeHalves(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        default:
            return -1;
        }
    }

// ---- the wereshape and the class rulings (folios 30-32) ----

// the article worked example - a fourth-level fighter contracting lycanthropy
// (folio 30)
inline int lycFighterExampleLevel()
    { return 4; }

// the worked-example lycanthrope initially fights as a monster of four hit
// dice in wereshape, unless the Blackmoor modifications are in effect (folio
// 30)
inline int lycFighterExampleHitDice()
    { return 4; }

// the worked example - a low-level werebear taking six rounds to change fully
// (folio 32)
inline int lycExampleChangeRounds()
    { return 6; }

// the worked example combat ladder - round two at level minus two (folio 32)
inline int lycRoundTwoPenalty()
    { return 2; }

// the ladder - rounds three and four at minus four (man and bear
// respectively), recovering to minus two at round five and full bear at round
// six, half damage from normal weapons at the halfway point (folio 32)
inline int lycRoundThreePenalty()
    { return 4; }

// magic-users, clergy or psychics cured after some time as a lycanthrope
// apply only 50 percent of the experience earned during that period (folio
// 32)
inline int lycCuredXpPercent()
    { return 50; }

// the further option - new characters a 1-5 percent chance of beginning as a
// hereditary lycanthrope, humans only, the floor (folio 32)
inline int lycHereditaryChanceMin()
    { return 1; }

// the hereditary-chance ceiling, 1-5 percent (folio 32)
inline int lycHereditaryChanceMax()
    { return 5; }

// lycanthropes may not speak human languages in animal shape, though they
// understand those they know (folio 30)
inline bool lycNoHumanSpeechInAnimalShape()
    { return true; }

// the wereshape cannot use standard weapons or human equipment including
// rods; passive magic items work if retained, most potions fail, poison works
// (folio 30)
inline bool lycNoHumanWeaponsInAnimalShape()
    { return true; }

// rats lack a vomit reflex, so the wereshaped wererat saving throw against
// ingested poisons should be reduced (folio 30)
inline bool lycWereratPoisonSaveReduced()
    { return true; }

// cured magic-users, clergy or psychics need the same amount of time to
// recover lost abilities as the disease took to lose them (folio 32)
inline bool lycCuredRecoveryTimeEqualsLossTime()
    { return true; }

// werebears are the most usable type for player characters, the others less
// able to control their beastly natures (folio 30)
inline bool lycWerebearMostUsableForPCs()
    { return true; }

// non-player werebears are usually lawful and extremely reluctant to
// contribute to the spread of the disease (folio 30)
inline bool lycNpcWerebearsUsuallyLawful()
    { return true; }

// clothing and armor do not disappear and reappear at a shapechange - it must
// be shed, loose fabrics advised over metal (folio 30)
inline bool lycArmorDoesNotVanish()
    { return true; }

// the change from man to beast is not instantaneous, the time reducing with
// experience (folio 32)
inline bool lycTransformationNotInstantaneous()
    { return true; }

// thieves function as fighters in this regard and are the only other class
// where lycanthropy may prove a positive asset (folio 32)
inline bool lycThievesMayBenefit()
    { return true; }

// rangers function as fighters but cannot gain any holy or magic powers while
// the disease persists (folio 32)
inline bool lycRangersFunctionAsFighters()
    { return true; }

// bards suffer a loss of charisma over the long haul - hairiness, pointed
// teeth, animal odor, raw meat, the shape changes - the charm chances
// somewhat reduced (folio 32)
inline bool lycBardsLoseCharisma()
    { return true; }

// the cleric's ability to turn undead may at the DM option be reduced by
// half, as with psionics, or retained fully (folio 32)
inline bool lycClericTurnUndeadMayHalve()
    { return true; }

}   // namespace rules
