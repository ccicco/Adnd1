// =========================================================================================
// Adnd1 - rules/dso.h
// The Dragon issue-6 opener - the Sea Trade system (folio 6), the psionic
// determination option (folio 25), the morale system (folios 26-27) and the
// Death Angel (folio 29): four adjudicated engine-relevant chains in one
// round
// census 828 -> 829.
//
// Pinned from The Dragon Vol. 1 No. 6 (April 1977), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 6).
// The folios: 6, the Sea Trade in D&D Campaigns by Ronald C. Spencer, Jr. -
// the Bardukian coastal trade, the cargo capacities and pilot fees, the 5
// percent import tax and the sixteen-band profit/loss grid with the ship-lost
// X sentinel; 25, the D&D Option: Determination of Psionic Abilities by David
// W. Miller - the human 91 and half-human 95 percentile gates, the
// thirty-seven abilities and the three learning ladders against the Eldritch
// Wizardry base; 26-27, the Morale in D&D system by Jim Hayes and Bill
// Gilbert - the 3d6 bravery/charisma/loyalty modifier ladder, the level and
// loss adjustments and the eleven-chart by ten-die outcome grid; 29, the
// Featured Creature: Death Angel by John Sullivan - the oracle of death on a
// single-victim mission. The transcripts ride extract/dragon/006/ (all 32
// issue pages); the issue-6 gap report ships pre-flip. PRINT FOLIO = PDF
// PAGE, verified at the printed 6, 26 and 29 footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// sea trade, psionic and morale systems pin as variant layers with
// provenance; the Death Angel, with no 1e def existing, pins as a NEW
// registry monster with the R900 Creature Features precedent and carries the
// dragon_print xp source in its lua. The XP conversion rides the DMG p.85
// additive formula - 225 base + 2 x 175 specials + 275 exceptional at the 6+1
// to 7 dice category, plus 8 per hit point at the floored 31 average - noted,
// never silent. The profit/loss grid's garbled 10 cell rides AS SCANNED, and
// the folio-25 '1%' weeks per level reads as 1 1/2, pinned as 15 tenths -
// both garbles noted, never silent. The editor's standing caution rides: none
// of this is official.
//
namespace rules {

// ---- the Sea Trade system (folio 6) ----

// the small merchant cargo capacity in gold - 10,000 G.P. (folio 6)
inline int dsoSeaCargoSmallGp()
    { return 10000; }

// the large merchant cargo capacity in gold - 50,000 G.P. (folio 6)
inline int dsoSeaCargoLargeGp()
    { return 50000; }

// the pilot fee at every port but the home port, the small merchant - 500
// G.P. (folio 6)
inline int dsoSeaPilotFeeSmall()
    { return 500; }

// the pilot fee at every port but the home port, the large merchant - 2,500
// G.P. (folio 6)
inline int dsoSeaPilotFeeLarge()
    { return 2500; }

// the import tax every country levies on the sale value in the receiving port
// - 5 percent (folio 6)
inline int dsoSeaImportTaxPct()
    { return 5; }

// the ports along the Bardukian coast - nine (folio 6)
inline int dsoSeaPortsOnCoast()
    { return 9; }

// the distance between the northernmost and southernmost port - about 2,500
// miles (folio 6)
inline int dsoSeaRouteMiles()
    { return 2500; }

// the coastal-trade limit - ships rarely venture more than fifty miles from
// land (folio 6)
inline int dsoSeaCoastalMilesMax()
    { return 50; }

// the delay at each port other than home - 1-4 weeks, the minimum (folio 6)
inline int dsoSeaDelayWeeksMin()
    { return 1; }

// the delay at each port other than home - 1-4 weeks, the maximum (folio 6)
inline int dsoSeaDelayWeeksMax()
    { return 4; }

// the owner learns of a lost ship 3-8 weeks later - the minimum (folio 6)
inline int dsoSeaLossNoticeWeeksMin()
    { return 3; }

// the owner learns of a lost ship 3-8 weeks later - the maximum (folio 6)
inline int dsoSeaLossNoticeWeeksMax()
    { return 8; }

// the dsoSeaProfitLoss table runs 16 rows - the percentile bands of the
// profit/loss table (folio 6)
inline int dsoSeaProfitLossCount()
    { return 16; }

// all trading and sailing is coastal in nature (folio 6)
inline bool dsoSeaCoastalTradeOnly()
    { return true; }

// the player/merchant is not required to sell a cargo at a loss - a loss port
// can be departed (folio 6)
inline bool dsoSeaNoForcedLossSale()
    { return true; }

// a port departed without sale counts as a port bypassed (folio 6)
inline bool dsoSeaDepartedPortCountsBypassed()
    { return true; }

// when the merchant accompanies the vessel the Wilderness Adventure rules
// govern - this layer covers the absent owner (folio 6)
inline bool dsoSeaWildernessRulesWhenAboard()
    { return true; }

// the sale percentage of cargo value at 0 port bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol0(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 90;
        case 2:
            return 95;
        case 3:
            return 100;
        case 4:
            return 105;
        case 5:
            return 105;
        case 6:
            return 110;
        case 7:
            return 110;
        case 8:
            return 110;
        case 9:
            return 115;
        case 10:
            return 120;
        case 11:
            return 125;
        case 12:
            return 130;
        case 13:
            return 140;
        case 14:
            return 150;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// the sale percentage of cargo value at 1 ports bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol1(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 85;
        case 2:
            return 90;
        case 3:
            return 95;
        case 4:
            return 100;
        case 5:
            return 105;
        case 6:
            return 110;
        case 7:
            return 115;
        case 8:
            return 120;
        case 9:
            return 125;
        case 10:
            return 130;
        case 11:
            return 135;
        case 12:
            return 140;
        case 13:
            return 150;
        case 14:
            return 200;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// the sale percentage of cargo value at 2 ports bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol2(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 80;
        case 2:
            return 85;
        case 3:
            return 90;
        case 4:
            return 95;
        case 5:
            return 110;
        case 6:
            return 115;
        case 7:
            return 120;
        case 8:
            return 130;
        case 9:
            return 150;
        case 10:
            return 160;
        case 11:
            return 180;
        case 12:
            return 200;
        case 13:
            return 250;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// the sale percentage of cargo value at 3 ports bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol3(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 70;
        case 2:
            return 80;
        case 3:
            return 85;
        case 4:
            return 90;
        case 5:
            return 115;
        case 6:
            return 120;
        case 7:
            return 130;
        case 8:
            return 140;
        case 9:
            return 160;
        case 10:
            return 180;
        case 11:
            return 200;
        case 12:
            return 300;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// the sale percentage of cargo value at 4 ports bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol4(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 70;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 115;
        case 6:
            return 125;
        case 7:
            return 135;
        case 8:
            return 150;
        case 9:
            return 200;
        case 10:
            return 250;
        case 11:
            return 350;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// the sale percentage at 5 ports bypassed - the folio's 16-20 row prints 10
// in this column where the arithmetic of its neighbours reads about 70; the
// cell rides AS SCANNED, the garble noted (folio 6)
inline int dsoSeaSaleCol5(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 10;
        case 4:
            return 85;
        case 5:
            return 120;
        case 6:
            return 140;
        case 7:
            return 160;
        case 8:
            return 200;
        case 9:
            return 300;
        case 10:
            return 400;
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
        default:
            return 0;
        }
    }

// the sale percentage of cargo value at 6 ports bypassed - the profit/loss
// table rows run the percentile bands 01-05 through 91-00 (folio 6)
inline int dsoSeaSaleCol6(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 60;
        case 4:
            return 80;
        case 5:
            return 120;
        case 6:
            return 150;
        case 7:
            return 200;
        case 8:
            return 300;
        case 9:
            return 500;
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
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// ---- the psionic determination option (folio 25) ----

// humans require a percentile roll of 91 or better for psionic potential
// (folio 25)
inline int dsoPsiHumanRollMin()
    { return 91; }

// half-humans require a percentile roll of 95 or better for psionic potential
// (folio 25)
inline int dsoPsiHalfHumanRollMin()
    { return 95; }

// any character can have any of the thirty-seven known psionic abilities
// (folio 25)
inline int dsoPsiAbilitiesCount()
    { return 37; }

// learning a new basic ability takes one week per level of difficulty (folio
// 25)
inline int dsoPsiBasicWeeksPerLevel()
    { return 1; }

// the superior abilities take the print's garbled '1%' weeks per level - read
// as 1 1/2, pinned as 15 tenths, the garble noted (folio 25)
inline int dsoPsiSuperiorWeeksTenths()
    { return 15; }

// the attack and defense modes take nine weeks each to learn (folio 25)
inline int dsoPsiAttackDefenseWeeks()
    { return 9; }

// it does not matter what class the character may choose - humanity is the
// basis of psionic potential (folio 25)
inline bool dsoPsiAnyClass()
    { return true; }

// the character does not incur a penalty for acquiring additional abilities
// (folio 25)
inline bool dsoPsiNoAcquisitionPenalty()
    { return true; }

// learning from a teacher requires the learner to have ESP (or an ESP
// Medallion) and the teacher Telepathic Projection (or a Helm of Telepathy)
// (folio 25)
inline bool dsoPsiLearnByEspAndProjection()
    { return true; }

// spontaneous development as stated in Eldritch Wizardry - the percentile
// roll is made as the next level is attained (folio 25)
inline bool dsoPsiSpontaneousAtNextLevel()
    { return true; }

// any character can acquire a psionic ability magically, but without becoming
// psionic except through magic (folio 25)
inline bool dsoPsiMagicalAcquisition()
    { return true; }

// a low intelligence limits the number of abilities learnable and extends the
// learning time (folio 25)
inline bool dsoPsiLowIntelligenceLimits()
    { return true; }

// ---- the morale system (folios 26-27) ----

// the personal bravery modifier at a 3 on 3d6 (folio 27)
inline int dsoMorBrave3()
    { return -4; }

// the personal bravery modifier at a 4 on 3d6 (folio 27)
inline int dsoMorBrave4()
    { return -3; }

// the personal bravery modifier at a 5 or 6 on 3d6 (folio 27)
inline int dsoMorBrave56()
    { return -2; }

// the personal bravery modifier at a 7 or 8 on 3d6 (folio 27)
inline int dsoMorBrave78()
    { return -1; }

// the personal bravery modifier at a 9-12 on 3d6 (folio 27)
inline int dsoMorBrave912()
    { return 0; }

// the personal bravery modifier at a 13 or 14 on 3d6 (folio 27)
inline int dsoMorBrave1314()
    { return 1; }

// the personal bravery modifier at a 15 or 16 on 3d6 (folio 27)
inline int dsoMorBrave1516()
    { return 2; }

// the personal bravery modifier at a 17 on 3d6 (folio 27)
inline int dsoMorBrave17()
    { return 3; }

// the personal bravery modifier at an 18 on 3d6 (folio 27)
inline int dsoMorBrave18()
    { return 4; }

// the bravery-table modifier at a 19 or more - the print's exceptional tail
// (folio 27)
inline int dsoMorBrave19()
    { return 5; }

// each fighter, MU or cleric of level 3-4 adds +1 to the chart number (folio
// 27)
inline int dsoMorLvl34()
    { return 1; }

// each fighter, MU or cleric of level 5-6 adds +2 to the chart number (folio
// 27)
inline int dsoMorLvl56()
    { return 2; }

// each fighter, MU or cleric of level 7-8 adds +3 to the chart number (folio
// 27)
inline int dsoMorLvl78()
    { return 3; }

// each comrade that breaks, is disabled or killed adjusts the recheck by -1
// (folio 27)
inline int dsoMorAdjComradeBreaks()
    { return -1; }

// each MU or cleric that breaks, is disabled or killed adjusts the recheck by
// -2 (folio 27)
inline int dsoMorAdjMuClericBreaks()
    { return -2; }

// if the leader breaks, is disabled or killed the recheck adjusts by -4
// (folio 27)
inline int dsoMorAdjLeaderBreaks()
    { return -4; }

// if an enemy leader breaks, is disabled or killed the recheck adjusts by +4
// (folio 27)
inline int dsoMorAdjEnemyLeader()
    { return 4; }

// each enemy MU or cleric that breaks, is disabled or killed adjusts the
// recheck by +2 (folio 27)
inline int dsoMorAdjEnemyMuCleric()
    { return 2; }

// every enemy fighter that breaks, is disabled or killed adjusts the recheck
// by +1 (folio 27)
inline int dsoMorAdjEnemyFighter()
    { return 1; }

// each side surprised takes -1 to morale (folio 27)
inline int dsoMorSurpriseMod()
    { return -1; }

// F - fights! No further morale check; 10 percent per round will berserk
// (folio 27)
inline int dsoMorBerserkPctPerRound()
    { return 10; }

// the dsoMorOutcome table runs 11 rows - the chart numbers -5 or less through
// +5 or more (folios 26-27)
inline int dsoMorOutcomeCount()
    { return 11; }

// the leader's charisma uses the same 3d6 modifier table as personal bravery
// (folio 27)
inline bool dsoMorCharismaSameTable()
    { return true; }

// loyalty as rolled and adjusted for charisma and other incentives uses the
// same modifier table (folio 27)
inline bool dsoMorLoyaltySameTable()
    { return true; }

// B - break and run: roll Dexterity to see if the runner takes one round of
// damage (folio 27)
inline bool dsoMorBreakDexDamageRoll()
    { return true; }

// H - hesitates: does not fight, check again next melee round (folio 27)
inline bool dsoMorHesitateRecheckNextRound()
    { return true; }

// S - stands and fights: check again if the morale chart number changes
// (folio 27)
inline bool dsoMorRecheckOnChartChange()
    { return true; }

// the morale outcome on the d10 roll of 1 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol1(int b)
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
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 2 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol2(int b)
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
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 3 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol3(int b)
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
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 4 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol4(int b)
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
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 5 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol5(int b)
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
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 6 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol6(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 7 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol7(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 8 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol8(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
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
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 9 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol9(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// the morale outcome on the d10 roll of 10 (0 reads as 10) across the chart
// numbers -5 or less through +5 or more: B = 0 break and run, H = 1
// hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)
inline int dsoMorCol10(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        default:
            return 0;
        }
    }

// ---- the Death Angel (folio 29) ----

// the Death Angel hit dice - 7 (folio 29)
inline int dsoDaHd()
    { return 7; }

// the Death Angel hit-die sides - eight-sided (folio 29)
inline int dsoDaHdSides()
    { return 8; }

// the Death Angel armor class - 4 (folio 29)
inline int dsoDaAc()
    { return 4; }

// the Death Angel movement - 12 (folio 29)
inline int dsoDaMove()
    { return 12; }

// the Death Angel flying movement - 20, the golden wings (folio 29)
inline int dsoDaMoveFly()
    { return 20; }

// the Death Angel number appearing - 1 (folio 29)
inline int dsoDaNumAppearing()
    { return 1; }

// the Death Scythe damage minimum - 1 (folio 29)
inline int dsoDaScytheMin()
    { return 1; }

// the Death Scythe damage maximum - 12 (folio 29)
inline int dsoDaScytheMax()
    { return 12; }

// every scythe hit forces a save vs. Death at -3 (folio 29)
inline int dsoDaSavePenalty()
    { return 3; }

// a successful save still costs one point of constitution, restored only by
// clerical Restoration or a Healer Energy spell (folio 29)
inline int dsoDaConLostPerSave()
    { return 1; }

// those killed by a Death Angel rise as Death Angels after three days unless
// raised (folio 29)
inline int dsoDaRiseDays()
    { return 3; }

// the Death Angel resistance to all magic including clerical - 95 percent
// (folio 29)
inline int dsoDaMagicResistPct()
    { return 95; }

// the percent chance for raising rolls as if the victim's constitution were 3
// (folio 29)
inline int dsoDaRaiseConAsIf()
    { return 3; }

// a being killed three times by a Death Angel is gone - not even a Wish
// brings it back (folio 29)
inline int dsoDaKillsIrreversible()
    { return 3; }

// the Death Angel's very few evil priest masters are of 20th level or higher
// (folio 29)
inline int dsoDaMasterPriestLevelMin()
    { return 20; }

// the average hit points - 7 eight-sided dice at 4.5 per die, floored (folio
// 29)
inline int dsoDaAvgHp()
    { return 31; }

// the base XP - the DMG p.85 formula at 7 dice: 225 base + 2 specials x 175 +
// 1 exceptional x 275; the conversion noted (folio 29)
inline int dsoDaXp()
    { return 850; }

// the XP per hit point - the DMG p.85 per-hit-die value at the 6+1 to 7 dice
// category (folio 29)
inline int dsoDaXpPerHp()
    { return 8; }

// the XP value - 850 + 8 x 31, the DMG p.85 additive formula (folio 29)
inline int dsoDaXpValue()
    { return 1098; }

// the Death Angel alignment - Neutral (folio 29)
inline bool dsoDaNeutral()
    { return true; }

// when killed the Death Angel vanishes entirely, leaving no remains (folio
// 29)
inline bool dsoDaVanishesWhenSlain()
    { return true; }

// the Death Angel teleport has no chance of failure (folio 29)
inline bool dsoDaTeleportNoFail()
    { return true; }

// the Death Angel cannot teleport out of melee (folio 29)
inline bool dsoDaNoTeleportFromMelee()
    { return true; }

// the Death Angel can be turned like a Vampire by a Cleric (folio 29)
inline bool dsoDaTurnedLikeVampire()
    { return true; }

// a turned Death Angel returns the next day (or night) - the mission of death
// must be fulfilled (folio 29)
inline bool dsoDaReturnsNextDay()
    { return true; }

// those successfully killed by a Death Angel become Death Angels after three
// days unless raised (folio 29)
inline bool dsoDaVictimsRiseAsAngels()
    { return true; }

// a normal Raise Dead will not work on a Death Angel victim - only Raise Dead
// Fully, and even then it raises like a regular Raise Dead (folio 29)
inline bool dsoDaRaiseDeadFullyOnly()
    { return true; }

// a Wish works automatically to raise a Death Angel victim (folio 29)
inline bool dsoDaWishRaisesAutomatically()
    { return true; }

// the Death Angel only attacks its intended victim, ignoring all others, and
// leaves after the kill (folio 29)
inline bool dsoDaOnlyAttacksVictim()
    { return true; }

// a remove curse thrown upon a slain Death Angel grants it eternal peace -
// the only permanent dispelling (folio 29)
inline bool dsoDaRemoveCurseGrantsPeace()
    { return true; }

// there can be no more than one Death Angel serving any one master (folio 29)
inline bool dsoDaOnePerMaster()
    { return true; }

// the Death Angel is highly intelligent and speaks all languages
// telepathically (folio 29)
inline bool dsoDaTelepathicAllLanguages()
    { return true; }

}   // namespace rules
