// =========================================================================================
// Adnd1 - rules/oaabilities.h
// THE ABILITY TABLES, printed capture pp. 7-13 - the OA Chapter 1 ability
// tables round
// census 537 -> 538.
//
// verified against capture pp. 7-13 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). OCR normalizations: the
// Table 4 "+" and percent spacing read clean as numbers; the Table 5
// korobokuru maximum splits from its Intelligence 15 row in the capture and
// merges back per book-internal settling; Table 2 Strength 3 weight allowance
// prints 0 - pinned as printed, flagged for the physical copy. The open-doors
// parentheticals pin as their own column (the engine strOpenDoors precedent);
// the Str 19 row prints 7-in-8 and pins as the face 7. The Table 4 footnote
// prints the warrior bonus (+3 at Con 17, +4 at 18) for samurai, bushi,
// kensai and sohei with the barbarian also entitled - all pinned as printed.
//
// the gap census after this round: 12 closed, 223 open - the eight ability
// tables flip (census 537 -> 538); NEXT - R616: the six ability prose
// sub-items (the Dexterity, Constitution, Intelligence, Wisdom, Charisma and
// Comeliness prose - the column explanations, the smitten doctrine, the
// Comeliness reaction bands and the racial adjustments), prefix dgc (verify
// free), audit "R616 OA ability prose audit", include after
// rules/oaabilities.h
//
namespace rules {

// ---- the OA ability table doctrine pins ----

// Table 2 explanation (capture p. 8): a stuck door can be retried until it
// opens, each attempt noisy and slow
inline bool dgbT2OpenDoorsRetry()
    { return true; }

// Table 2 explanation (capture p. 8): a locked, barred or magically held door
// allows one attempt ever - a failure is permanent for that character
inline bool dgbT2LockedOneAttempt()
    { return true; }

// Table 2 explanation (capture p. 8): a failed bend-bars or lift-gate attempt
// can never succeed at that task; the other task at the same gate stays open
inline bool dgbT2BendBarsOneAttempt()
    { return true; }

// Table 2 explanation (capture p. 8): a successful hit never causes less than
// 1 point of damage
inline bool dgbT2DmgFloorOne()
    { return true; }

// Table 2 explanation (capture p. 8): each additional 350 coins (35 lbs.) of
// weight slows the character by 25 percent
inline bool dgbT2WeightSlowdown()
    { return true; }

// Table 4 explanation (capture p. 10): no hit die ever yields fewer than 1
// hit point, whatever the adjustment
inline bool dgbT4HitDieFloorOne()
    { return true; }

// Table 4 footnote (capture p. 10): the +3 at Constitution 17 and +4 at 18
// apply only to samurai, bushi, kensai and sohei
inline bool dgbT4WarriorFullCon()
    { return true; }

// Table 4 footnote (capture p. 10): the barbarian also receives the full
// hit-point bonus for Constitution
inline bool dgbT4BarbarianFullCon()
    { return true; }

// Table 4 footnote (capture p. 10): wu jen, shukenja, ninja and yakuza
// receive at most +2 per hit die at Constitution 18
inline bool dgbT4OthersCapTwo()
    { return true; }

// Table 6 explanation (capture p. 11): the magical attack adjustment applies
// automatically against mind attacks - beguiling, charm, fear, hypnosis,
// illusion, possession, suggestion
inline bool dgbT6MindAuto()
    { return true; }

// ---- the Table 1 Strength annotation pins and the Table 2 grid ----

// Table 1 (capture p. 7): minimum Strength for wu jen
inline int dgbMinStrWuJen()
    { return 3; }

// Table 1 (capture p. 7): minimum Strength for spirit folk
inline int dgbMinStrSpiritFolk()
    { return 6; }

// Table 1 (capture p. 7): minimum Strength for korobokuru
inline int dgbMinStrKorobokuru()
    { return 8; }

// Table 1 (capture p. 7): minimum Strength for shukenja
inline int dgbMinStrShukenja()
    { return 9; }

// Table 1 (capture p. 7): minimum Strength for bushi
inline int dgbMinStrBushi()
    { return 9; }

// Table 1 (capture p. 7): minimum Strength for hengeyokai
inline int dgbMinStrHengeyokai()
    { return 12; }

// Table 1 (capture p. 7): minimum Strength for kensai
inline int dgbMinStrKensai()
    { return 12; }

// Table 1 (capture p. 7): minimum Strength for samurai
inline int dgbMinStrSamurai()
    { return 13; }

// Table 1 (capture p. 7): minimum Strength for sohei
inline int dgbMinStrSohei()
    { return 13; }

// Table 1 (capture p. 7): minimum Strength for barbarian
inline int dgbMinStrBarbarian()
    { return 15; }

// Table 1 (capture p. 7): minimum Strength for monk
inline int dgbMinStrMonk()
    { return 15; }

// Table 1 (capture p. 7): maximum Strength for shukenja
inline int dgbMaxStrShukenja()
    { return 18; }

// Table 1 (capture p. 7): maximum Strength for monk
inline int dgbMaxStrMonk()
    { return 18; }

// Table 1 (capture p. 7): maximum Strength for wu jen
inline int dgbMaxStrWuJen()
    { return 18; }

// Table 1 (capture p. 7): maximum Strength for yakuza
inline int dgbMaxStrYakuza()
    { return 18; }

// Table 1 (capture p. 7): maximum Strength for human - the 18/00 row (capture
// p. 7)
inline int dgbMaxStrHuman()
    { return 18; }

// Table 1 (capture p. 7): maximum Strength for korobokuru
inline int dgbMaxStrKorobokuru()
    { return 19; }

// Table 2 (capture p. 8): sixteen rows - Strength 3, 4-5, 6-7, 8-9, 10-11,
// 12-13, 14-15, 16, 17, 18, 18/01-50, 18/51-75, 18/76-90, 18/91-99, 18/00, 19
inline int dgbT2RowCount()
    { return 16; }

// the hit probability column: -3 at Strength 3 to +3 at 18/00 and 19 (capture
// p. 8).
inline int dgbT2HitProb(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -2;
        case 2:
            return -1;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 3;
        default:
            return -99;
        }
    }

// the damage adjustment column: -1 at Strength 3 to +7 at 19 (capture p. 8).
inline int dgbT2DmgAdj(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 7;
        default:
            return -99;
        }
    }

// the weight allowance column in coins: 0 at Strength 3 (the printed zero,
// pinned as printed) to 4,850 at 19 (capture p. 8).
inline int dgbT2Weight(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 100;
        case 2:
            return 200;
        case 3:
            return 350;
        case 4:
            return 350;
        case 5:
            return 450;
        case 6:
            return 550;
        case 7:
            return 700;
        case 8:
            return 850;
        case 9:
            return 1100;
        case 10:
            return 1350;
        case 11:
            return 1600;
        case 12:
            return 1850;
        case 13:
            return 2350;
        case 14:
            return 3350;
        case 15:
            return 4850;
        default:
            return -99;
        }
    }

// the open-doors max column: the highest d6 face that forces a stuck door;
// the Str 19 row prints 7-in-8, pinned as the face 7 (capture p. 8).
inline int dgbT2OpenMax(int b)
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
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 7;
        default:
            return -99;
        }
    }

// the open-doors locked column: the parenthetical chance on a locked, barred
// or held door - 0 except 1 at 18/91-99, 2 at 18/00, 3 at 19 (capture p. 8).
inline int dgbT2OpenLocked(int b)
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        default:
            return -99;
        }
    }

// the bend-bars percent column: 0 at Strength 3 to 50 at 19 (capture p. 8).
inline int dgbT2BendPct(int b)
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
            return 2;
        case 5:
            return 4;
        case 6:
            return 7;
        case 7:
            return 10;
        case 8:
            return 13;
        case 9:
            return 16;
        case 10:
            return 20;
        case 11:
            return 25;
        case 12:
            return 30;
        case 13:
            return 35;
        case 14:
            return 40;
        case 15:
            return 50;
        default:
            return -99;
        }
    }

// ---- the Table 3 Dexterity annotation pins and grid ----

// Table 3 (capture p. 9): minimum Dexterity for korobokuru
inline int dgbMinDexKorobokuru()
    { return 6; }

// Table 3 (capture p. 9): minimum Dexterity for bushi
inline int dgbMinDexBushi()
    { return 8; }

// Table 3 (capture p. 9): minimum Dexterity for hengeyokai
inline int dgbMinDexHengeyokai()
    { return 9; }

// Table 3 (capture p. 9): minimum Dexterity for spirit folk
inline int dgbMinDexSpiritFolk()
    { return 12; }

// Table 3 (capture p. 9): minimum Dexterity for kensai
inline int dgbMinDexKensai()
    { return 14; }

// Table 3 (capture p. 9): minimum Dexterity for barbarian
inline int dgbMinDexBarbarian()
    { return 14; }

// Table 3 (capture p. 9): minimum Dexterity for ninja
inline int dgbMinDexNinja()
    { return 14; }

// Table 3 (capture p. 9): minimum Dexterity for monk
inline int dgbMinDexMonk()
    { return 15; }

// Table 3 (capture p. 9): seventeen rows, Dexterity 3 through 19
inline int dgbT3RowCount()
    { return 17; }

// the reaction/attacking adjustment column: -3 at Dexterity 3 to +3 at 19
// (capture p. 9).
inline int dgbT3Reaction(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -2;
        case 2:
            return -1;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 3;
        default:
            return -99;
        }
    }

// the defensive adjustment column: +4 at Dexterity 3 to -4 at 19 (capture p.
// 9).
inline int dgbT3Defensive(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return -1;
        case 14:
            return -2;
        case 15:
            return -3;
        case 16:
            return -4;
        default:
            return -99;
        }
    }

// ---- the Table 4 Constitution annotation pins and grid ----

// Table 4 (capture p. 10): minimum Constitution for spirit folk
inline int dgbMinConSpiritFolk()
    { return 6; }

// Table 4 (capture p. 10): minimum Constitution for bushi
inline int dgbMinConBushi()
    { return 8; }

// Table 4 (capture p. 10): minimum Constitution for shukenja
inline int dgbMinConShukenja()
    { return 9; }

// Table 4 (capture p. 10): minimum Constitution for sohei
inline int dgbMinConSohei()
    { return 10; }

// Table 4 (capture p. 10): minimum Constitution for monk
inline int dgbMinConMonk()
    { return 11; }

// Table 4 (capture p. 10): minimum Constitution for korobokuru
inline int dgbMinConKorobokuru()
    { return 12; }

// Table 4 (capture p. 10): minimum Constitution for hengeyokai
inline int dgbMinConHengeyokai()
    { return 12; }

// Table 4 (capture p. 10): minimum Constitution for samurai
inline int dgbMinConSamurai()
    { return 13; }

// Table 4 (capture p. 10): maximum Constitution for spirit folk
inline int dgbMaxConSpiritFolk()
    { return 14; }

// Table 4 (capture p. 10): minimum Constitution for barbarian
inline int dgbMinConBarbarian()
    { return 15; }

// Table 4 (capture p. 10): sixteen rows, Constitution 3 through 18
inline int dgbT4RowCount()
    { return 16; }

// the hit-point adjustment column: -2 at Constitution 3 to +2 at 18 (capture
// p. 10).
inline int dgbT4HpAdj(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
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
            return 0;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        default:
            return -99;
        }
    }

// the warrior hit-point column: the full bonus ladder - the +3 at
// Constitution 17 and +4 at 18 of the printed footnote (capture p. 10).
inline int dgbT4WarriorHpAdj(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
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
            return 0;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 4;
        default:
            return -99;
        }
    }

// the system shock survival percent column: 35 at Constitution 3 to 99 at 18
// (capture p. 10).
inline int dgbT4ShockPct(int b)
    {
        switch (b) {
        case 0:
            return 35;
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
            return 88;
        case 12:
            return 91;
        case 13:
            return 95;
        case 14:
            return 97;
        case 15:
            return 99;
        default:
            return -99;
        }
    }

// the resurrection survival percent column: 40 at Constitution 3 to 100 at 18
// (capture p. 10).
inline int dgbT4ResPct(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 45;
        case 2:
            return 50;
        case 3:
            return 55;
        case 4:
            return 60;
        case 5:
            return 65;
        case 6:
            return 70;
        case 7:
            return 75;
        case 8:
            return 80;
        case 9:
            return 85;
        case 10:
            return 90;
        case 11:
            return 92;
        case 12:
            return 94;
        case 13:
            return 96;
        case 14:
            return 98;
        case 15:
            return 100;
        default:
            return -99;
        }
    }

// ---- the Table 5 Intelligence annotation pins and grid ----

// Table 5 (capture p. 11): minimum Intelligence for korobokuru
inline int dgbMinIntKorobokuru()
    { return 3; }

// Table 5 (capture p. 11): minimum Intelligence for hengeyokai
inline int dgbMinIntHengeyokai()
    { return 12; }

// Table 5 (capture p. 11): minimum Intelligence for spirit folk
inline int dgbMinIntSpiritFolk()
    { return 12; }

// Table 5 (capture p. 11): minimum Intelligence for wu jen
inline int dgbMinIntWuJen()
    { return 13; }

// Table 5 (capture p. 11): minimum Intelligence for samurai
inline int dgbMinIntSamurai()
    { return 14; }

// Table 5 (capture p. 11): minimum Intelligence for ninja
inline int dgbMinIntNinja()
    { return 15; }

// Table 5 (capture p. 11): maximum Intelligence for korobokuru - the capture
// splits the row; the annotation belongs to the Intelligence 15 row
inline int dgbMaxIntKorobokuru()
    { return 15; }

// Table 5 (capture p. 11): sixteen rows, Intelligence 3 through 18
inline int dgbT5RowCount()
    { return 16; }

// the additional languages column: 0 at Intelligence 3-7, 1 at 8-9, rising to
// 7 at 18 (capture p. 11).
inline int dgbT5Languages(int b)
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
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 7;
        default:
            return -99;
        }
    }

// the maximum wu jen spell level column: 4 at Intelligence 3-9, 5 at 10-11, 6
// at 12-14, 7 at 15, 8 at 16-17, 9 at 18 (capture p. 11).
inline int dgbT5MaxSpellLevel(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
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
            return 8;
        case 14:
            return 8;
        case 15:
            return 9;
        default:
            return -99;
        }
    }

// ---- the Table 6 Wisdom annotation pins and grid ----

// Table 6 (capture pp. 11-12): minimum Wisdom for spirit folk
inline int dgbMinWisSpiritFolk()
    { return 9; }

// Table 6 (capture p. 12): minimum Wisdom for sohei
inline int dgbMinWisSohei()
    { return 10; }

// Table 6 (capture p. 12): minimum Wisdom for kensai
inline int dgbMinWisKensai()
    { return 12; }

// Table 6 (capture p. 12): minimum Wisdom for shukenja
inline int dgbMinWisShukenja()
    { return 12; }

// Table 6 (capture p. 12): minimum Wisdom for hengeyokai
inline int dgbMinWisHengeyokai()
    { return 12; }

// Table 6 (capture p. 12): minimum Wisdom for samurai
inline int dgbMinWisSamurai()
    { return 13; }

// Table 6 (capture p. 12): minimum Wisdom for monk
inline int dgbMinWisMonk()
    { return 15; }

// Table 6 (capture p. 12): maximum Wisdom for barbarian
inline int dgbMaxWisBarbarian()
    { return 16; }

// Table 6 (capture p. 12): maximum Wisdom for korobokuru
inline int dgbMaxWisKorobokuru()
    { return 17; }

// Table 6 (capture pp. 11-12): sixteen rows, Wisdom 3 through 18
inline int dgbT6RowCount()
    { return 16; }

// the magical attack adjustment column: -3 at Wisdom 3 to +4 at 18 (capture
// pp. 11-12).
inline int dgbT6MagicAttack(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
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
            return 0;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 4;
        default:
            return -99;
        }
    }

// ---- the Table 7 Charisma annotation pins and grid ----

// Table 7 (capture p. 12): minimum Charisma for hengeyokai
inline int dgbMinChaHengeyokai()
    { return 12; }

// Table 7 (capture p. 12): minimum Charisma for spirit folk
inline int dgbMinChaSpiritFolk()
    { return 14; }

// Table 7 (capture p. 12): minimum Charisma for ninja
inline int dgbMinChaNinja()
    { return 14; }

// Table 7 (capture p. 12): maximum Charisma for korobokuru
inline int dgbMaxChaKorobokuru()
    { return 16; }

// Table 7 (capture p. 12): maximum Charisma for hengeyokai
inline int dgbMaxChaHengeyokai()
    { return 17; }

// Table 7 (capture p. 12): sixteen rows, Charisma 3 through 18
inline int dgbT7RowCount()
    { return 16; }

// the maximum henchmen column: 1 at Charisma 3-4 rising to 15 at 18 (capture
// p. 12).
inline int dgbT7Henchmen(int b)
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
            return 4;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        case 12:
            return 7;
        case 13:
            return 8;
        case 14:
            return 10;
        case 15:
            return 15;
        default:
            return -99;
        }
    }

// the loyalty base percent column: -30 at Charisma 3 to +40 at 18 (capture p.
// 12).
inline int dgbT7Loyalty(int b)
    {
        switch (b) {
        case 0:
            return -30;
        case 1:
            return -25;
        case 2:
            return -20;
        case 3:
            return -15;
        case 4:
            return -10;
        case 5:
            return -5;
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
            return 5;
        case 12:
            return 15;
        case 13:
            return 20;
        case 14:
            return 30;
        case 15:
            return 40;
        default:
            return -99;
        }
    }

// the reaction adjustment percent column: -25 at Charisma 3 to +35 at 18
// (capture p. 12).
inline int dgbT7Reaction(int b)
    {
        switch (b) {
        case 0:
            return -25;
        case 1:
            return -20;
        case 2:
            return -15;
        case 3:
            return -10;
        case 4:
            return -5;
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
            return 5;
        case 11:
            return 10;
        case 12:
            return 15;
        case 13:
            return 25;
        case 14:
            return 30;
        case 15:
            return 35;
        default:
            return -99;
        }
    }

// ---- the Table 8 Comeliness band pins and grid ----

// Table 8 (capture p. 13): nine Charisma bands - 2 or less, 3, 4-5, 6-8,
// 9-12, 13-15, 16-17, 18, 19 or more
inline int dgbT8RowCount()
    { return 9; }

// the Table 8 band chain (capture p. 13): a Charisma score maps to its band -
// 2 or less band 0, 3 band 1, 4-5 band 2, 6-8 band 3, 9-12 band 4, 13-15 band
// 5, 16-17 band 6, 18 band 7, 19 or more band 8
inline int dgbT8Band(int cha)
    {
        if (cha <= 2) return 0;
        if (cha <= 3) return 1;
        if (cha <= 5) return 2;
        if (cha <= 8) return 3;
        if (cha <= 12) return 4;
        if (cha <= 15) return 5;
        if (cha <= 17) return 6;
        if (cha <= 18) return 7;
        return 8;
    }

// the band-max column: the highest Charisma score of each band - 2, 3, 5, 8,
// 12, 15, 17, 18, and the 19-plus tail (capture p. 13).
inline int dgbT8ChaMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 8;
        case 4:
            return 12;
        case 5:
            return 15;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 19;
        default:
            return -99;
        }
    }

// the Comeliness adjustment column: -8 at Charisma 2 or less, -5 at 3, -3 at
// 4-5, -1 at 6-8, 0 at 9-12, +1 at 13-15, +2 at 16-17, +3 at 18, +5 at 19 or
// more (capture p. 13).
inline int dgbT8Adj(int b)
    {
        switch (b) {
        case 0:
            return -8;
        case 1:
            return -5;
        case 2:
            return -3;
        case 3:
            return -1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 5;
        default:
            return -99;
        }
    }

}   // namespace rules
