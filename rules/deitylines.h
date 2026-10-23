// =========================================================================================
// Adnd1 - rules/deitylines.h
// THE DEITY STAT LINES - the R406 messy reads pin: the class/level lines, the
// MOVE rates, the seven ability lines, the damage bonuses
// census 705 -> 706.
//
// R406 pinned the scan-clean stat-line numerics and left the messy reads
// open: the six class/level lines, the MOVE values, the S/I/W/D/C/CH/CM stat
// lines, the prose. R783 pins everything but the prose. The 23 blocks ride
// the 1eonline.info compilation (the repo-trusted source), row-verified
// against the R406 pins - armor class, hit points, magic resistance, attack
// halves, damage spans all cross-match, and where the compilation fills a
// hole the print pins stand. The grid is 23 x 12 plus 23 x 13: the
// class/level lines pin verbatim (every Nil reads zero; the halfling titles
// read as levels - Patriarch C8, Ranger Lord R12, Master Thief T10, Master of
// Dragons M8; the "in each" fills both columns; all five orc FIGHTER lines
// read as monsters; Dumathoin's "12 level thief" typo rides the pin, not the
// fix). The MOVE rates pin base plus parenthetical second (Aerdrie prints the
// flight-only phrase with no number). The ability lines pin signed (Yurtrus
// -4/-25), the slash strengths split to a pct column (18/00, 18/01), and the
// CH/Com parentheticals pin with Hanali's special sentinel. The DAMAGE/ATTACK
// bonuses pin with the see-below sentinel (Labelas, Yurtrus), and the
// cross-column check rides: the bonus equals the S parenthetical damage bonus
// on all 15 rows that print both, with the three refusing prints pinned as
// they stand (Arvoreen, Bahgtru, Solonor). Honest boundaries: the
// parenthetical reads, the special/see-text levels, the
// destructive-spells-only qualifier, and the by-weapon-type damage ride
// contract-side; the prose alone stays open
//
// Zero new book pages: the stat lines ride the Appendix S pp. 110-120 blocks
// the R405/R406 pins already seat, and the compilation source rides the R189
// speed-verify duty already trusted
//
namespace rules {

// ---- the deity stat lines (the R783 wiring) ----

// The stat-line grid row census: 23 rows in the R405/R406 registry order
// (dwarves, elves, halflings, gnomes, orcs)
inline int dvpDeityRowCount()
    { return 23; }

// The stat-line round: the R406 messy reads pin at last
inline int dvpStatLineRound()
    { return 783; }

// The feeder round: the R406 stat-block numerics this grid extends row for
// row
inline int dvpStatBlockFeederRound()
    { return 406; }

// The seam round: the R405 layer contract the R782 bridge closed
inline int dvpDeitySeamFeederRound()
    { return 405; }

// The five class/level lines per block (cleric/druid, fighter,
// magic-user/illusionist, thief/assassin, monk/bard)
inline int dvpClassLineCount()
    { return 5; }

// The seven ability lines per block (S/I/W/D/C/CH/Com)
inline int dvpAbilityLineCount()
    { return 7; }

// The FIGHTER-line kind code for the as-N-HD monster reads (all five orc
// blocks carry it)
inline int dvpMonsterFighterKind()
    { return 13; }

// The special/see-text sentinel on the class level columns (Dumathoin,
// Aerdrie, Yurtrus magic-user reads)
inline int dvpSeeTextLevel()
    { return -1; }

// The five class/level lines pin verbatim: every Nil reads zero, every
// printed level pins, and the print's own typo (Dumathoin's "12 level thief")
// rides the pin, not the fix
inline bool dvpClassLinesPinVerbatim()
    { return true; }

// The halfling pantheon prints titles, and the titles read as levels:
// Patriarch C8, Ranger Lord R12, Master Thief T10, Master of Dragons M8,
// Initiate of the 4th Circle D6, Pathfinder R7, Magician MU6, Visionist I6,
// Master Thief T19, Master M6
inline bool dvpHalflingTitlesReadAsLevels()
    { return true; }

// The "in each" convention fills both columns of its line at the one level
// (Flandal cleric/druid 8, Cyrrollalee and Segojan magic-user/illusionist,
// Luthic both lines)
inline bool dvpInEachFillsBoth()
    { return true; }

// All five orc FIGHTER lines read as N-HD monsters (16+, 10, 15, 13, 12) -
// the kind code 13 row census
inline bool dvpOrcFighterLinesReadAsMonsters()
    { return true; }

// The percentile strengths pin the slash verbatim: Sheela and Baervan print
// 18/00, Segojan prints 18/01 (the pct column; -1 = no slash printed)
inline bool dvpStrPctCellsPinTheSlash()
    { return true; }

// Three prints refuse the bonus-equals-S-damage pattern and pin as they
// stand: Arvoreen damages +8 with no S parenthetical, Bahgtru +15 against the
// S +14, Solonor prints the S +9 with no damage bonus at all
inline bool dvpDamageBonusQuirksArePrint()
    { return true; }

// The parenthetical numbers pin as data; what they MEAN (the CH/Com reads
// toward worshippers, the special CH) rides contract-side - the print is the
// print
inline bool dvpParenReadsRideContractSide()
    { return true; }

// R786: the dwarven paragraphs pin
// (rules/uadeityprose1.h); the other
// pantheons' prose stays open - the lines
// pin, the paragraphs do not (yet)
inline bool dvpProseStaysOpen()
    { return true; }

// ---- the class-line grid (the R783 wiring) ----

// The MOVE base rate in inches (the printed line)
inline int dvpMoveBase(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 48;
        case 6:
            return 18;
        case 7:
            return 15;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 15;
        case 15:
            return 12;
        case 16:
            return 9;
        case 17:
            return 6;
        case 18:
            return 9;
        case 19:
            return 18;
        case 20:
            return 12;
        case 21:
            return 6;
        case 22:
            return 15;
        default:
            return -1;
        }
    }

// The MOVE parenthetical second rate (0 = none printed; Aerdrie's
// parenthetical prints the flight-only phrase, no number)
inline int dvpMoveSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 48;
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
            return 24;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 36;
        case 16:
            return 36;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 12;
        default:
            return -1;
        }
    }

// The CLERIC/DRUID line: the cleric level (0 = none/Nil)
inline int dvpClericLvl(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 14;
        case 9:
            return 14;
        case 10:
            return 0;
        case 11:
            return 8;
        case 12:
            return 10;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 8;
        case 16:
            return 0;
        case 17:
            return 8;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 8;
        case 21:
            return 15;
        case 22:
            return 15;
        default:
            return -1;
        }
    }

// The CLERIC/DRUID line: the druid level (0 = none; "in each" fills both; the
// druidess reads as druid)
inline int dvpDruidLvl(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 12;
        case 5:
            return 14;
        case 6:
            return 8;
        case 7:
            return 12;
        case 8:
            return 10;
        case 9:
            return 12;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 12;
        case 15:
            return 0;
        case 16:
            return 14;
        case 17:
            return 8;
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
        default:
            return -1;
        }
    }

// The FIGHTER line: the level (0 = none/Nil)
inline int dvpFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 12;
        case 2:
            return 16;
        case 3:
            return 14;
        case 4:
            return 14;
        case 5:
            return 10;
        case 6:
            return 7;
        case 7:
            return 17;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 7;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 7;
        case 14:
            return 8;
        case 15:
            return 10;
        case 16:
            return 6;
        case 17:
            return 10;
        case 18:
            return 16;
        case 19:
            return 10;
        case 20:
            return 15;
        case 21:
            return 13;
        case 22:
            return 12;
        default:
            return -1;
        }
    }

// The FIGHTER line kind: 3 fighter, 4 ranger, 5 paladin, 13 the as-N-HD
// monster read (0 = nil)
inline int dvpFightKind(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 13;
        case 19:
            return 13;
        case 20:
            return 13;
        case 21:
            return 13;
        case 22:
            return 13;
        default:
            return -1;
        }
    }

// The MAGIC-USER/ILLUSIONIST line: the magic-user level (0 = Nil, -1 = the
// special/see-text sentinel)
inline int dvpMuLvl(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return 0;
        case 4:
            return 16;
        case 5:
            return -1;
        case 6:
            return 0;
        case 7:
            return 10;
        case 8:
            return 16;
        case 9:
            return 18;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 8;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 16;
        case 17:
            return 15;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return -1;
        case 22:
            return 12;
        default:
            return -1;
        }
    }

// The MAGIC-USER/ILLUSIONIST line: the illusionist level (0 = Nil; "in each"
// fills both)
inline int dvpIllusLvl(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 14;
        case 3:
            return 11;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 18;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 8;
        case 13:
            return 6;
        case 14:
            return 13;
        case 15:
            return 13;
        case 16:
            return 16;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 7;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 12;
        default:
            return -1;
        }
    }

// The THIEF/ASSASSIN line: the thief level (0 = none/Nil)
inline int dvpThiefLvl(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 18;
        case 2:
            return 12;
        case 3:
            return 20;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 12;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 10;
        case 12:
            return 0;
        case 13:
            return 19;
        case 14:
            return 20;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 16;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 6;
        default:
            return -1;
        }
    }

// The THIEF/ASSASSIN line: the assassin level (0 = none; "in each" fills
// both)
inline int dvpAssassinLvl(int b)
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
            return 0;
        case 15:
            return 12;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 15;
        case 20:
            return 14;
        case 21:
            return 15;
        case 22:
            return 6;
        default:
            return -1;
        }
    }

// The MONK/BARD line: the monk level (0 = none; Master of Dragons M8 and
// Master M6 read as monk titles)
inline int dvpMonkLvl(int b)
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
            return 8;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 10;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        default:
            return -1;
        }
    }

// The MONK/BARD line: the bard level (0 = none/Nil)
inline int dvpBardLvl(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 8;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 10;
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
            return 4;
        case 17:
            return 0;
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
        default:
            return -1;
        }
    }

// ---- the ability-line grid (the R783 wiring) ----

// The S base (the plain number; the 18/00 and 18/01 prints split to the pct
// column)
inline int dvpStrBase(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 22;
        case 2:
            return 25;
        case 3:
            return 24;
        case 4:
            return 21;
        case 5:
            return 8;
        case 6:
            return 19;
        case 7:
            return 21;
        case 8:
            return 15;
        case 9:
            return 12;
        case 10:
            return 18;
        case 11:
            return 20;
        case 12:
            return 17;
        case 13:
            return 19;
        case 14:
            return 18;
        case 15:
            return 19;
        case 16:
            return 18;
        case 17:
            return 22;
        case 18:
            return 25;
        case 19:
            return 20;
        case 20:
            return 23;
        case 21:
            return 18;
        case 22:
            return 19;
        default:
            return -1;
        }
    }

// The S percentile after the slash (-1 = no percentile printed; 0 = 18/00, 1
// = 18/01)
inline int dvpStrPct(int b)
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
            return 0;
        case 11:
            return -1;
        case 12:
            return -1;
        case 13:
            return -1;
        case 14:
            return 0;
        case 15:
            return -1;
        case 16:
            return 1;
        case 17:
            return -1;
        case 18:
            return -1;
        case 19:
            return -1;
        case 20:
            return -1;
        case 21:
            return -1;
        case 22:
            return -1;
        default:
            return -1;
        }
    }

// The S parenthetical to-hit bonus (0 = no parenthetical printed)
inline int dvpStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 7;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 3;
        default:
            return -1;
        }
    }

// The S parenthetical damage bonus (0 = no parenthetical printed)
inline int dvpStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 10;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 9;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 9;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 7;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 3;
        case 17:
            return 10;
        case 18:
            return 14;
        case 19:
            return 8;
        case 20:
            return 11;
        case 21:
            return 2;
        case 22:
            return 7;
        default:
            return -1;
        }
    }

// The I base
inline int dvpIntBase(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 23;
        case 2:
            return 23;
        case 3:
            return 22;
        case 4:
            return 25;
        case 5:
            return 24;
        case 6:
            return 23;
        case 7:
            return 22;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return 22;
        case 11:
            return 21;
        case 12:
            return 23;
        case 13:
            return 24;
        case 14:
            return 21;
        case 15:
            return 20;
        case 16:
            return 22;
        case 17:
            return 18;
        case 18:
            return 6;
        case 19:
            return 19;
        case 20:
            return 17;
        case 21:
            return 18;
        case 22:
            return 18;
        default:
            return -1;
        }
    }

// The W base
inline int dvpWisBase(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 16;
        case 4:
            return 25;
        case 5:
            return 22;
        case 6:
            return 16;
        case 7:
            return 21;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 17;
        case 14:
            return 19;
        case 15:
            return 14;
        case 16:
            return 23;
        case 17:
            return 20;
        case 18:
            return 6;
        case 19:
            return 15;
        case 20:
            return 14;
        case 21:
            return 11;
        case 22:
            return 19;
        default:
            return -1;
        }
    }

// The D base
inline int dvpDexBase(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 23;
        case 2:
            return 20;
        case 3:
            return 24;
        case 4:
            return 20;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 25;
        case 9:
            return 19;
        case 10:
            return 22;
        case 11:
            return 24;
        case 12:
            return 24;
        case 13:
            return 25;
        case 14:
            return 25;
        case 15:
            return 20;
        case 16:
            return 18;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 24;
        case 20:
            return 20;
        case 21:
            return 10;
        case 22:
            return 14;
        default:
            return -1;
        }
    }

// The C base
inline int dvpConBase(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 24;
        case 4:
            return 25;
        case 5:
            return 19;
        case 6:
            return 20;
        case 7:
            return 21;
        case 8:
            return 20;
        case 9:
            return 18;
        case 10:
            return 24;
        case 11:
            return 23;
        case 12:
            return 23;
        case 13:
            return 23;
        case 14:
            return 22;
        case 15:
            return 24;
        case 16:
            return 24;
        case 17:
            return 23;
        case 18:
            return 25;
        case 19:
            return 19;
        case 20:
            return 23;
        case 21:
            return 17;
        case 22:
            return 20;
        default:
            return -1;
        }
    }

// The CH base (signed; Yurtrus prints -4)
inline int dvpChaBase(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 8;
        case 4:
            return 19;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 23;
        case 8:
            return 25;
        case 9:
            return 24;
        case 10:
            return 22;
        case 11:
            return 21;
        case 12:
            return 22;
        case 13:
            return 20;
        case 14:
            return 22;
        case 15:
            return 3;
        case 16:
            return 20;
        case 17:
            return 18;
        case 18:
            return 5;
        case 19:
            return 7;
        case 20:
            return 8;
        case 21:
            return -4;
        case 22:
            return 12;
        default:
            return -1;
        }
    }

// The CH parenthetical (-1 = the special read, Hanali; 0 = none printed)
inline int dvpChaParen(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 14;
        case 4:
            return 25;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return -1;
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
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 22;
        case 19:
            return 24;
        case 20:
            return 25;
        case 21:
            return 0;
        case 22:
            return 25;
        default:
            return -1;
        }
    }

// The Com base (signed; Yurtrus prints -25, Urdlen -14)
inline int dvpComBase(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 18;
        case 2:
            return 13;
        case 3:
            return 7;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 25;
        case 7:
            return 22;
        case 8:
            return 30;
        case 9:
            return 25;
        case 10:
            return 24;
        case 11:
            return 21;
        case 12:
            return 21;
        case 13:
            return 19;
        case 14:
            return 16;
        case 15:
            return -14;
        case 16:
            return 15;
        case 17:
            return 16;
        case 18:
            return -2;
        case 19:
            return 8;
        case 20:
            return 5;
        case 21:
            return -25;
        case 22:
            return 3;
        default:
            return -1;
        }
    }

// The Com parenthetical (0 = none printed)
inline int dvpComParen(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 24;
        case 2:
            return 16;
        case 3:
            return 13;
        case 4:
            return 25;
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
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 20;
        case 20:
            return 24;
        case 21:
            return 0;
        case 22:
            return 24;
        default:
            return -1;
        }
    }

// The DAMAGE/ATTACK parenthetical bonus (0 = no number printed,
// Nil/by-weapon/plain; -1 = the see-below sentinel)
inline int dvpDmgBonus(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 10;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 9;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return -1;
        case 10:
            return 6;
        case 11:
            return 8;
        case 12:
            return 0;
        case 13:
            return 7;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 3;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 8;
        case 20:
            return 11;
        case 21:
            return -1;
        case 22:
            return 7;
        default:
            return -1;
        }
    }

}   // namespace rules
