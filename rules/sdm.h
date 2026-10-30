// =========================================================================================
// Adnd1 - rules/sdm.h
// The Dragon issue-19 opener part two - the Origins 78 tourney and
// victory-point scoring, the creative treasures and location charts, and the
// hostile magic-user spell determination: the three-chain round
// census 860 -> 861.
//
// Pinned from The Dragon Vol. III No. 5 (October 1978), the Curtiss-provided
// scan voice (single voice: the issue-19 source is the uploaded Dm19.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 19). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet in
// the R937 intake (folios 12, 18, 21, 24, 26 and 31 print at the PDF pages
// 14, 20, 23, 26, 28 and 33); this round pins print 3-4 + 6 (PDF 5-6 + 8),
// print 13 + 25 (PDF 15 + 27) and print 24-25 (PDF 26-27).
//
// Print quirks pinned AS SCANNED, noted never silent: the scoring formula
// prints (G=R=C) x S = VP - the pluses for the sum pinned in the audit
// comment, the formula kept as printed; the Snurre Hall continuation rides
// the tail of the Ettins article stamped Smurre with an S; the shrine prints
// Kuo-Tao while the fight paragraph prints Kuo-Toa; the location chart prints
// 13-13 for the pot then jumps to 16-17 loose, the d20 bands 14-15 never
// assigned; the assassin kit dagger prints a plus +2 dagger, the doubled
// plus; the enchanter spell list trails into a printed ellipsis after the 4
// first level and 3 second level counts; the second-level table prints -01-05
// for Levitate, the leading dash; Hold Portal and Time Stop carry the
// asterisk that means dungeons only, reroll for wilderness encounters.
//
namespace rules {

// ---- the Origins 78 tourney and scoring (print 3-4 + 6, PDF 5-6 + 8) ----

// the Origins 78 scale - over 275 players and judges over two days the
// Origins 78 tourney (print 3, PDF 5)
inline int sdmOriginsPlayers()
    { return 275; }

// the tournament team size - teams of nine each the Origins 78 tourney (print
// 3, PDF 5)
inline int sdmTeamSize()
    { return 9; }

// the tournament depth - up to three rounds the Origins 78 tourney (print 3,
// PDF 5)
inline int sdmTourneyRounds()
    { return 3; }

// the GenCon X DM count - fifteen needed the Blake tournament scoring (print
// 6, PDF 8)
inline int sdmDmCountGenconX()
    { return 15; }

// the Origins 78 DM count - sixteen needed (print 6, PDF 8)
inline int sdmDmCountOrigins78()
    { return 16; }

// the GenCon XI DM count - twenty needed (print 6, PDF 8)
inline int sdmDmCountGenconXI()
    { return 20; }

// the briefing session length - four hour plus meetings the Blake tournament
// scoring (print 6, PDF 8)
inline int sdmBriefingHours()
    { return 4; }

// the first-portion length floor - two hours, pinned 120 minutes the Origins
// 78 tourney (print 3, PDF 5)
inline int sdmRoundOneMinutesFloor()
    { return 120; }

// the first-portion length ceiling - two and a half hours, pinned 150 minutes
// (print 4, PDF 6)
inline int sdmRoundOneMinutesCeil()
    { return 150; }

// the corridor-block marks - the blade barrier and wall of fire centered 20
// feet down the west hall (print 4, PDF 6)
inline int sdmWallFeet()
    { return 20; }

// the hallway width - 30 feet, the party on the invisible dusted rope (print
// 4, PDF 6)
inline int sdmHallWidthFeet()
    { return 30; }

// the module price - G1 Steading of the Hill Giant Chief at 449 cents (print
// 4, PDF 6)
inline int sdmG1PriceCents()
    { return 449; }

// the module price - G2 Glacial Rift of the Frost Giant Jarl at 449 cents
// (print 4, PDF 6)
inline int sdmG2PriceCents()
    { return 449; }

// the module price - G3 Hall of the Fire Giant King at 498 cents (print 4,
// PDF 6)
inline int sdmG3PriceCents()
    { return 498; }

// the victory-point terms - G giant kills, R rooms, C clues, the survivor S
// multiplier (print 6, PDF 8)
inline int sdmFormulaTerms()
    { return 3; }

// the GenCon X first round - two teams competing in the town adventure for
// the magical key (print 6, PDF 8)
inline int sdmGenconXRoundTeams()
    { return 2; }

// the scoring formula - the printed (G=R=C) x S = VP, the terms summed then
// multiplied by the survivors, pinned as scanned the Blake tournament scoring
// (print 6, PDF 8)
inline bool sdmSurvivorMultiplied()
    { return true; }

// the point weighting - the total room value plus the total clue value equals
// the total giant value available in the module (print 6, PDF 8)
inline bool sdmRoomClueEqualGiant()
    { return true; }

// the do-or-dont situation - one of the easiest and most desirable scoring
// means the Blake tournament scoring (print 6, PDF 8)
inline bool sdmDoOrDieDesirable()
    { return true; }

// the subjective DM-vote assessment is the least desirable means the Blake
// tournament scoring (print 6, PDF 8)
inline bool sdmSubjectivityLeastDesirable()
    { return true; }

// strict point objectivity is better but still inadequate alone - it may warp
// the design intent the Blake tournament scoring (print 6, PDF 8)
inline bool sdmObjectivityBetterAloneInadequate()
    { return true; }

// the best approach is the combination of subjectivity and objectivity the
// Blake tournament scoring (print 6, PDF 8)
inline bool sdmCombinationBest()
    { return true; }

// a super clever team may find a far superior method and deserve a greater
// reward the Blake tournament scoring (print 6, PDF 8)
inline bool sdmSuperiorMethodGreaterReward()
    { return true; }

// GenCon X ran the do-or-dont - the tower skull, the wilderness trap, one
// team close to defusing it (print 6, PDF 8)
inline bool sdmGenconXDoOrDie()
    { return true; }

// the GenCon X skull - pieces to be assembled, few teams got them all, some
// fudging done (print 6, PDF 8)
inline bool sdmSkullPiecesFudged()
    { return true; }

// the GenCon XI survivor multiplier - casualties counted as slain or captured
// for sacrifice (print 6, PDF 8)
inline bool sdmGenconXISurvivorMultiplier()
    { return true; }

// the GenCon XI round two - every team but one died to the demon encounter,
// one casualty survived (print 6, PDF 8)
inline bool sdmGenconXIDemonWipe()
    { return true; }

// the GenCon XI winners took a bye in the third round, second and third slots
// left to fill (print 6, PDF 8)
inline bool sdmGenconXIBye()
    { return true; }

// the post-GenCon XI vow - never use the subjective DM-meeting approach again
// if at all possible (print 6, PDF 8)
inline bool sdmSubjectiveNeverAgain()
    { return true; }

// DM briefing sessions are a must - the designer intent must be clear to all
// the Blake tournament scoring (print 6, PDF 8)
inline bool sdmBriefingSessionsMust()
    { return true; }

// a short standard-rules compilation for every DM - movement, turn order,
// scenario modifications the Blake tournament scoring (print 6, PDF 8)
inline bool sdmStandardRulesSheet()
    { return true; }

// the Battle of the Triangular - the two fire giant guards at the T
// intersection, the alarm, the chimera (print 4, PDF 6)
inline bool sdmBattleOfTriangular()
    { return true; }

// Obmi the rescued dwarf - the ballista and the water and flour traced back
// to him, never trusted (print 4, PDF 6)
inline bool sdmObmiBetrayal()
    { return true; }

// the DM verdict - the haste spell the real turning point of the battle, all
// ten on their feet (print 4, PDF 6)
inline bool sdmHasteTurningPoint()
    { return true; }

// King Snurre was not really dead, only pretending - the severed head
// confirmed the apparent death (print 4, PDF 6)
inline bool sdmKingOnlyPretending()
    { return true; }

// the thief cut the head off and placed it in his bag of holding - a regular
// part of any coup they staged (print 4, PDF 6)
inline bool sdmHeadInBagHolding()
    { return true; }

// the print catch - the Snurre Hall continuation rides the tail of the Ettins
// article stamped Smurre with an S, pinned as scanned (print 6, PDF 8)
inline bool sdmSmurreContTypo()
    { return true; }

// the GenCon XI Shrine of the Kuo-Tao - one way through unscathed worth
// considerable points, fights otherwise (print 6, PDF 8)
inline bool sdmGenconXIShrinePassage()
    { return true; }

// the print catch - the shrine prints Kuo-Tao while the fight paragraph
// prints Kuo-Toa, pinned as scanned (print 6, PDF 8)
inline bool sdmKuoSpellingCrossed()
    { return true; }

// ---- the treasure chains (print 13 + 25, PDF 15 + 27) ----

// the trap chance - one in four treasures carries a trap the Guritzky
// treasure charts (print 25, PDF 27)
inline int sdmTrapChanceDenominator()
    { return 4; }

// the dagger trap floor - 1-8 daggers, 1 in 6 poisoned the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmDaggerCountMin()
    { return 1; }

// the dagger trap ceiling - 8 daggers the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmDaggerCountMax()
    { return 8; }

// the trap poison chance - 1 in 6 on daggers and spears the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmTrapPoisonDenominator()
    { return 6; }

// the arrow trap ceiling - 1-6 arrows the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmArrowCountMax()
    { return 6; }

// the spear trap ceiling - 1-3 spears, 1 in 6 poisoned the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmSpearCountMax()
    { return 3; }

// the exploding chest floor - 2-7 dice of damage the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmExplodingDiceMin()
    { return 2; }

// the exploding chest ceiling - 7 dice the Guritzky treasure charts (print
// 25, PDF 27)
inline int sdmExplodingDiceMax()
    { return 7; }

// the gas roll - two dice, the 6-sided first digit and 4-sided second the
// Guritzky treasure charts (print 25, PDF 27)
inline int sdmGasDieCount()
    { return 2; }

// the blinding gas - 01-100 hours of blindness the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmGasBlindHoursMax()
    { return 100; }

// the fear gas floor - fear during the next 2-9 fights the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmGasFearFightsMin()
    { return 2; }

// the fear gas ceiling - 9 fights the Guritzky treasure charts (print 25, PDF
// 27)
inline int sdmGasFearFightsMax()
    { return 9; }

// the sleep gas floor - 6-36 rounds the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmGasSleepMin()
    { return 6; }

// the sleep gas ceiling - 36 rounds the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmGasSleepMax()
    { return 36; }

// the ability-drain gas floor - 1-4 points to a random ability the Guritzky
// treasure charts (print 25, PDF 27)
inline int sdmGasAbilityMin()
    { return 1; }

// the ability-drain gas ceiling - 4 points the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmGasAbilityMax()
    { return 4; }

// the ability-drain gas duration - 8 hours the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmGasAbilityHours()
    { return 8; }

// the ability-drain permanence - 1 in 10 permanent the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmGasAbilityPermanentDenominator()
    { return 10; }

// the sick gas - return to the surface, 1 in 6 in coma the Guritzky treasure
// charts (print 25, PDF 27)
inline int sdmSickComaDenominator()
    { return 6; }

// the amnesia gas floor - 1-20 days the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmGasAmnesiaMinDays()
    { return 1; }

// the amnesia gas ceiling - 20 days the Guritzky treasure charts (print 25,
// PDF 27)
inline int sdmGasAmnesiaMaxDays()
    { return 20; }

// the amnesia permanence - 1 in 6 permanent the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmGasAmnesiaPermanentDenominator()
    { return 6; }

// the intelligent chest floor - a 2nd-7th level magic user the Guritzky
// treasure charts (print 25, PDF 27)
inline int sdmIntelligentChestMinLevel()
    { return 2; }

// the intelligent chest ceiling - 7th level the Guritzky treasure charts
// (print 25, PDF 27)
inline int sdmIntelligentChestMaxLevel()
    { return 7; }

// the alchemist bar bouncers - 12 feet tall in their hobnail boots the
// Schroeder creative treasures (print 13, PDF 15)
inline int sdmBouncerFeet()
    { return 12; }

// the location-chart kinds - chest, urn, bag, pot, loose, carried, hidden and
// the referee choice (print 25, PDF 27)
inline int sdmLocKinds()
    { return 8; }

// the trap-chart kinds - thirteen from the dagger trap to the roll-twice
// (print 25, PDF 27)
inline int sdmTrapKinds()
    { return 13; }

// the gas-chart kinds - sixteen outcomes from obscured vision to the berserk
// attack (print 25, PDF 27)
inline int sdmGasKinds()
    { return 16; }

// the creative-treasure doctrine - first of all choose a theme the Schroeder
// creative treasures (print 13, PDF 15)
inline bool sdmChooseThemeFirst()
    { return true; }

// the item-connection doctrine - a connection between the treasure contents
// and their guardian the Schroeder creative treasures (print 13, PDF 15)
inline bool sdmItemConnections()
    { return true; }

// the first aid kit - healing potion, smelling salts, the poison bottle, the
// oil of slipperiness, the scrolls the Schroeder creative treasures (print
// 13, PDF 15)
inline bool sdmFirstAidKitDoctrine()
    { return true; }

// the thief toolkit - plus 1 dagger, trap-glowing gem, gauntlets, skeleton
// key, waldos, periscope, bag of holding the Schroeder creative treasures
// (print 13, PDF 15)
inline bool sdmThiefToolkitDoctrine()
    { return true; }

// the assassin disguise kit - polymorph potions, the plus +2 dagger, poisons,
// wigs, the girdle, the scareb the Schroeder creative treasures (print 13,
// PDF 15)
inline bool sdmDisguiseKitDoctrine()
    { return true; }

// the print catch - the assassin kit dagger prints a plus +2 dagger, the
// doubled plus pinned as scanned the Schroeder creative treasures (print 13,
// PDF 15)
inline bool sdmAssassinDaggerPlusTwo()
    { return true; }

// the paranoid high-level example - the bishop with dozens of bottles of
// youth potion the Schroeder creative treasures (print 13, PDF 15)
inline bool sdmYouthPotionBishop()
    { return true; }

// the paranoid magic-user - the necklace of detection gems, detect magic,
// evil, good, weres, gold, doors, invisible the Schroeder creative treasures
// (print 13, PDF 15)
inline bool sdmDetectionGemNecklace()
    { return true; }

// the monster-in-chest trap - pay attention to the monster size the Guritzky
// treasure charts (print 25, PDF 27)
inline bool sdmMonsterSizeAttention()
    { return true; }

// the trap chart 00 - roll twice the Guritzky treasure charts (print 25, PDF
// 27)
inline bool sdmTrapRollTwice()
    { return true; }

// the print catch - the location chart prints 13-13 for the pot then 16-17
// loose, the bands 14-15 never assigned, pinned as scanned the Guritzky
// treasure charts (print 25, PDF 27)
inline bool sdmLocBandsGap()
    { return true; }

// the gas-roll method - the 6-sided die for the first digit and the 4-sided
// for the second the Guritzky treasure charts (print 25, PDF 27)
inline bool sdmGasD64Method()
    { return true; }

// the location band lows - 1, 7, 10, 13, 16, 18, 19 and 20, the pot a lone 13
// with the 14-15 gap (print 25, PDF 27)
inline int sdmLocLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 10;
        case 3:
            return 13;
        case 4:
            return 16;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 20;
        default:
            return 0;
        }
    }

// the location band highs - 6, 9, 12, 13, 17, 18, 19 and 20 (print 25, PDF
// 27)
inline int sdmLocHigh(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 13;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 20;
        default:
            return 0;
        }
    }

// the trap band lows - 01 through 96 with the singleton traps at 96, 97, 98,
// 99 and 100 (print 25, PDF 27)
inline int sdmTrapLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 37;
        case 3:
            return 47;
        case 4:
            return 63;
        case 5:
            return 79;
        case 6:
            return 89;
        case 7:
            return 93;
        case 8:
            return 96;
        case 9:
            return 97;
        case 10:
            return 98;
        case 11:
            return 99;
        case 12:
            return 100;
        default:
            return 0;
        }
    }

// the trap band highs - the dagger 20 through the roll-twice 100, the
// contiguous run (print 25, PDF 27)
inline int sdmTrapHigh(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 36;
        case 2:
            return 46;
        case 3:
            return 62;
        case 4:
            return 78;
        case 5:
            return 88;
        case 6:
            return 92;
        case 7:
            return 95;
        case 8:
            return 96;
        case 9:
            return 97;
        case 10:
            return 98;
        case 11:
            return 99;
        case 12:
            return 100;
        default:
            return 0;
        }
    }

// the gas band lows - 11, 13, 21, 23, 31, 32, 34, 41, 42, 43, 44, 51, 53, 61,
// 63, 64 (print 25, PDF 27)
inline int sdmGasLow(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 13;
        case 2:
            return 21;
        case 3:
            return 23;
        case 4:
            return 31;
        case 5:
            return 32;
        case 6:
            return 34;
        case 7:
            return 41;
        case 8:
            return 42;
        case 9:
            return 43;
        case 10:
            return 44;
        case 11:
            return 51;
        case 12:
            return 53;
        case 13:
            return 61;
        case 14:
            return 63;
        case 15:
            return 64;
        default:
            return 0;
        }
    }

// the gas band highs - 12, 14, 22, 24, 31, 33, 34, 41, 42, 43, 44, 52, 54,
// 62, 63, 64 (print 25, PDF 27)
inline int sdmGasHigh(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 14;
        case 2:
            return 22;
        case 3:
            return 24;
        case 4:
            return 31;
        case 5:
            return 33;
        case 6:
            return 34;
        case 7:
            return 41;
        case 8:
            return 42;
        case 9:
            return 43;
        case 10:
            return 44;
        case 11:
            return 52;
        case 12:
            return 54;
        case 13:
            return 62;
        case 14:
            return 63;
        case 15:
            return 64;
        default:
            return 0;
        }
    }

// ---- the hostile MU spell determination (print 24-25, PDF 26-27) ----

// the determination depth - nine percentile tables, first through ninth level
// the Miller spell determination (print 24, PDF 26)
inline int sdmSpellLevels()
    { return 9; }

// the total pinned spell rows - 75 across the nine tables (print 24-25, PDF
// 26-27)
inline int sdmDetSpellsTotal()
    { return 75; }

// the first-level table count - 7 spells, Hold Portal through Ventriloquism
// (print 24, PDF 26)
inline int sdmL1Spells()
    { return 7; }

// the second-level table count - 9 spells, Levitate through Mirror Image
// (print 24, PDF 26)
inline int sdmL2Spells()
    { return 9; }

// the third-level table count - 11 spells, Fly through Suggestion (print 24,
// PDF 26)
inline int sdmL3Spells()
    { return 11; }

// the fourth-level table count - 8 spells, Polymorph Self through Fear (print
// 24, PDF 26)
inline int sdmL4Spells()
    { return 8; }

// the fifth-level table count - 9 spells, Teleport through Growth of Animals
// (print 24, PDF 26)
inline int sdmL5Spells()
    { return 9; }

// the sixth-level table count - 11 spells, Stone to Flesh through Monster
// Summoning IV (print 25, PDF 27)
inline int sdmL6Spells()
    { return 11; }

// the seventh-level table count - 7 spells, Delayed Blast Fire Ball through
// Monster Summoning V (print 25, PDF 27)
inline int sdmL7Spells()
    { return 7; }

// the eighth-level table count - 5 spells, Mass Charm through Monster
// Summoning VI (print 25, PDF 27)
inline int sdmL8Spells()
    { return 5; }

// the ninth-level table count - 8 spells, Meteor Swarm through Monster
// Summoning VII (print 25, PDF 27)
inline int sdmL9Spells()
    { return 8; }

// the worked example - the enchanter with 10 spells to choose from the Miller
// spell determination (print 24, PDF 26)
inline int sdmEnchanterSpells()
    { return 10; }

// the worked example - 4 first-level spells the Miller spell determination
// (print 24, PDF 26)
inline int sdmEnchanterL1()
    { return 4; }

// the worked example - 3 second-level spells, the remaining levels cut off by
// the printed ellipsis (print 24, PDF 26)
inline int sdmEnchanterL2()
    { return 3; }

// the level die in the worked example - the 20-sided roll for the spell level
// the Miller spell determination (print 24, PDF 26)
inline int sdmMethodDieSides()
    { return 20; }

// the conjurer level die - four-sided the Miller spell determination (print
// 24, PDF 26)
inline int sdmConjurerDieSides()
    { return 4; }

// the magician level die - eight-sided the Miller spell determination (print
// 24, PDF 26)
inline int sdmMagicianDieSides()
    { return 8; }

// the reroll rule - insufficient range, a dungeon spell in a wilderness
// encounter or the obviously inappropriate allows a reroll the Miller spell
// determination (print 24, PDF 26)
inline bool sdmRerollAllowed()
    { return true; }

// the footnote pair - the range reroll note and the asterisk dungeons-only
// reroll for wilderness, Hold Portal and Time Stop carrying the asterisk
// (print 24-25, PDF 26-27)
inline bool sdmAsteriskDungeonRerull()
    { return true; }

// the obviously inappropriate example - throwing feeblemind on a fighter the
// Miller spell determination (print 24, PDF 26)
inline bool sdmInappropriateReroll()
    { return true; }

// the charts can be modified to suit individual campaigns the Miller spell
// determination (print 24, PDF 26)
inline bool sdmChartsModifiable()
    { return true; }

// the doctrine example - one wizard hasted himself and his henchmen,
// invisible, levitated, then opened up (print 24, PDF 26)
inline bool sdmHasteInvisLevitateOpening()
    { return true; }

// the bowman response - protection from normal missiles on himself, sleep on
// the archers (print 24, PDF 26)
inline bool sdmProtectionThenSleep()
    { return true; }

// the doctrine - hostile MUs spend plentiful lower-level spells instead of
// blowing groups away with the big three immediately (print 24, PDF 26)
inline bool sdmLowerLevelPreferred()
    { return true; }

// the print catch - the second-level table prints -01-05 for Levitate, the
// leading dash pinned as scanned (print 24, PDF 26)
inline bool sdmL2LeadingDash()
    { return true; }

// the print catch - the enchanter spell list prints 4 first level and 3
// second level then trails into a printed ellipsis, pinned as scanned (print
// 24, PDF 26)
inline bool sdmEnchanterEllipsis()
    { return true; }

// the re-done encounter - the enchanter opens with a lightning bolt and
// disposes of one of the magic users (print 24, PDF 26)
inline bool sdmLightningBoltOpening()
    { return true; }

// the re-done encounter - a magic missile stabs out and scratches one cleric
// (print 24, PDF 26)
inline bool sdmMagicMissileCleric()
    { return true; }

// the level-1 band lows - row one opens at 01 (print 24, PDF 26)
inline int sdmL1Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 31;
        case 4:
            return 56;
        case 5:
            return 76;
        case 6:
            return 96;
        default:
            return 0;
        }
    }

// the level-1 band highs - the last row closes at 100 (print 24, PDF 26)
inline int sdmL1High(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 30;
        case 3:
            return 55;
        case 4:
            return 75;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// the level-2 band lows - row one opens at 01 (print 24, PDF 26)
inline int sdmL2Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 31;
        case 4:
            return 41;
        case 5:
            return 51;
        case 6:
            return 66;
        case 7:
            return 71;
        case 8:
            return 91;
        default:
            return 0;
        }
    }

// the level-2 band highs - the last row closes at 100 (print 24, PDF 26)
inline int sdmL2High(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 50;
        case 5:
            return 65;
        case 6:
            return 70;
        case 7:
            return 90;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// the level-3 band lows - row one opens at 01 (print 24, PDF 26)
inline int sdmL3Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 16;
        case 3:
            return 21;
        case 4:
            return 41;
        case 5:
            return 51;
        case 6:
            return 56;
        case 7:
            return 61;
        case 8:
            return 76;
        case 9:
            return 81;
        case 10:
            return 91;
        default:
            return 0;
        }
    }

// the level-3 band highs - the last row closes at 100 (print 24, PDF 26)
inline int sdmL3High(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 40;
        case 4:
            return 50;
        case 5:
            return 55;
        case 6:
            return 60;
        case 7:
            return 75;
        case 8:
            return 80;
        case 9:
            return 90;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// the level-4 band lows - row one opens at 01 (print 24, PDF 26)
inline int sdmL4Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 21;
        case 3:
            return 26;
        case 4:
            return 31;
        case 5:
            return 41;
        case 6:
            return 51;
        case 7:
            return 71;
        default:
            return 0;
        }
    }

// the level-4 band highs - the last row closes at 100 (print 24, PDF 26)
inline int sdmL4High(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 40;
        case 5:
            return 50;
        case 6:
            return 70;
        case 7:
            return 100;
        default:
            return 0;
        }
    }

// the level-5 band lows - row one opens at 01 (print 24, PDF 26)
inline int sdmL5Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 26;
        case 3:
            return 36;
        case 4:
            return 46;
        case 5:
            return 56;
        case 6:
            return 61;
        case 7:
            return 86;
        case 8:
            return 96;
        default:
            return 0;
        }
    }

// the level-5 band highs - the last row closes at 100 (print 24, PDF 26)
inline int sdmL5High(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 25;
        case 2:
            return 35;
        case 3:
            return 45;
        case 4:
            return 55;
        case 5:
            return 60;
        case 6:
            return 85;
        case 7:
            return 95;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// the level-6 band lows - row one opens at 01 (print 25, PDF 27)
inline int sdmL6Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 26;
        case 3:
            return 36;
        case 4:
            return 41;
        case 5:
            return 61;
        case 6:
            return 66;
        case 7:
            return 76;
        case 8:
            return 81;
        case 9:
            return 86;
        case 10:
            return 96;
        default:
            return 0;
        }
    }

// the level-6 band highs - the last row closes at 100 (print 25, PDF 27)
inline int sdmL6High(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 25;
        case 2:
            return 35;
        case 3:
            return 40;
        case 4:
            return 60;
        case 5:
            return 65;
        case 6:
            return 75;
        case 7:
            return 80;
        case 8:
            return 85;
        case 9:
            return 95;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// the level-7 band lows - row one opens at 01 (print 25, PDF 27)
inline int sdmL7Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 31;
        case 3:
            return 56;
        case 4:
            return 76;
        case 5:
            return 81;
        case 6:
            return 91;
        default:
            return 0;
        }
    }

// the level-7 band highs - the last row closes at 100 (print 25, PDF 27)
inline int sdmL7High(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 55;
        case 3:
            return 75;
        case 4:
            return 80;
        case 5:
            return 90;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// the level-8 band lows - row one opens at 01 (print 25, PDF 27)
inline int sdmL8Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 56;
        case 3:
            return 61;
        case 4:
            return 91;
        default:
            return 0;
        }
    }

// the level-8 band highs - the last row closes at 100 (print 25, PDF 27)
inline int sdmL8High(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 55;
        case 2:
            return 60;
        case 3:
            return 90;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// the level-9 band lows - row one opens at 01 (print 25, PDF 27)
inline int sdmL9Low(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 46;
        case 3:
            return 51;
        case 4:
            return 71;
        case 5:
            return 76;
        case 6:
            return 86;
        case 7:
            return 96;
        default:
            return 0;
        }
    }

// the level-9 band highs - the last row closes at 100 (print 25, PDF 27)
inline int sdmL9High(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 45;
        case 2:
            return 50;
        case 3:
            return 70;
        case 4:
            return 75;
        case 5:
            return 85;
        case 6:
            return 95;
        case 7:
            return 100;
        default:
            return 0;
        }
    }

}   // namespace rules
