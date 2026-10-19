// =========================================================================================
// Adnd1 - rules/oawujen.h
// THE WU JEN, printed capture pp. 47-51 - the OA wu jen round
// census 548 -> 549.
//
// verified against capture pp. 47-51 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). Three cells settled against
// the 2018 print BEFORE pinning, per the settling doctrine: the T31 row-2
// bound (the capture lost the comma - 4,000); the T33 row-5 first-spell cell
// (the capture prints 4, the 2018 prints 3, the ladder-consistent reading
// stands); the T33 row-22 ninth-spell cell (the capture prints 2, the 2018
// prints 1, the ladder-consistent reading stands). The T32 All maximum pins
// as the -1 code; the T33 dashes pin as zeros. OCR normalization: konobokuru
// reads as korobokuru; in hit, spell book reads as in his spell book;
// cloud/adder reads as cloud ladder (prose only)
//
// the gap census after this round: 56 closed, 179 open - the wu jen boxes
// with Tables 31, 32 and 33 flip (census 548 -> 549); NEXT - R627: the
// Yakuza, capture pp. 51-54, Tables 34 and 35, prefix dgn (verify free),
// audit "R627 OA yakuza audit", include after rules/oawujen.h
//
namespace rules {

// ---- the wu jen doctrine pins ----

// Wu jen prose (capture p. 48): the Intelligence minimum
inline int dgmWuJenMinInt()
    { return 13; }

// Wu jen prose (capture p. 48): Intelligence 15 or greater earns the 10
// percent experience bonus
inline int dgmWuJenBonusInt()
    { return 15; }

// Wu jen prose (capture p. 48): the bonus value
inline int dgmWuJenBonusPct()
    { return 10; }

// Wu jen prose (capture p. 48): wu jen cannot be lawful
inline bool dgmWuJenNeverLawful()
    { return true; }

// Wu jen prose (capture p. 48): human, korobokuru and hengeyokai can be wu
// jen
inline bool dgmWuJenRaces()
    { return true; }

// Wu jen prose (capture p. 48): the 4-sided hit die, one per level
inline int dgmWuJenHitDie()
    { return 4; }

// Wu jen prose (capture p. 48): the automatic +1 hit point bonus per die, 2-5
// per level
inline int dgmWuJenHpBonusPerDie()
    { return 1; }

// Wu jen prose (capture p. 48): the 2-5 hit points per level lower bound
inline int dgmWuJenHpPerLevelMin()
    { return 2; }

// Wu jen prose (capture p. 48): the 2-5 upper bound
inline int dgmWuJenHpPerLevelMax()
    { return 5; }

// Wu jen prose (capture p. 48): the magic-user combat and saving throw tables
inline bool dgmWuJenMagicUserTables()
    { return true; }

// Wu jen prose (capture p. 48): cannot wear armor or use shields, limited to
// the Table 13 weapons
inline bool dgmWuJenNoArmor()
    { return true; }

// Wu jen prose (capture p. 48): the favored weapon earns +1 to hit
inline int dgmWuJenFavoredBonus()
    { return 1; }

// Wu jen prose (capture p. 48): six proficiency slots at the beginning
inline int dgmWuJenSlots()
    { return 6; }

// ---- the wu jen spell and ki pins ----

// Wu jen prose (capture p. 50): understanding, knowing and remembering are
// three different things - only study of the spell book lets him cast from
// memory
inline bool dgmWuJenUnderstandKnowMemorize()
    { return true; }

// Wu jen prose (capture p. 50): a lasting Intelligence loss forces a recheck
// of every understood spell against the new maximum; a gain allows new
// learning
inline bool dgmWuJenIntLossRecheck()
    { return true; }

// Wu jen prose (capture p. 50): new spells come from a teacher, another wu
// jen book or a scroll - the scroll is destroyed in learning
inline bool dgmWuJenScrollDestroyed()
    { return true; }

// Wu jen prose (capture p. 50): learns to meditate like a shukenja as part of
// the mental regimen
inline bool dgmWuJenMeditates()
    { return true; }

// Wu jen prose (capture p. 50): the ki burst gives +3 on the initiative roll
inline int dgmWuJenKiInitBonus()
    { return 3; }

// Wu jen prose (capture p. 50): the ki burst lasts one round
inline int dgmWuJenKiInitRounds()
    { return 1; }

// Wu jen prose (capture p. 50): the ki burst once per day
inline int dgmWuJenKiInitPerDay()
    { return 1; }

// Wu jen prose (capture p. 50): the second ki power at 4th level - maximum
// effect
inline int dgmWuJenKiMaxEffectLevel()
    { return 4; }

// Wu jen prose (capture p. 50): any one spell three or more levels lower than
// the wu jen level, at maximum effect
inline int dgmWuJenKiMaxEffectGap()
    { return 3; }

// Wu jen prose (capture p. 50): five elemental groups - earth/metal, water,
// fire, wind and wood/nature
inline int dgmWuJenElementCount()
    { return 5; }

// Wu jen prose (capture p. 50): the element master casts with a -1 saving
// throw modifier against the enemies
inline int dgmWuJenMasterEnemySaveMod()
    { return -1; }

// Wu jen prose (capture p. 50): the element master gains +1 to all damage of
// that element
inline int dgmWuJenMasterDamageBonus()
    { return 1; }

// Wu jen prose (capture p. 50): the element master gains +1 on saves versus
// spells of that element
inline int dgmWuJenMasterSaveBonus()
    { return 1; }

// Wu jen prose (capture p. 50): the element mastery is lost when a higher
// spell level becomes castable until all its spells are learned
inline bool dgmWuJenMasterLostOnNewLevel()
    { return true; }

// ---- the wu jen pupil and taboo pins ----

// Wu jen prose (capture p. 50): the 1d4 pupils attracted at 10th level
inline int dgmWuJenPupilLevel()
    { return 10; }

// Wu jen prose (capture p. 50): the pupil die
inline int dgmWuJenPupilDice()
    { return 4; }

// Wu jen prose (capture p. 50): the pupils leave at a level equal to one-half
// their master level, each replaced by a new 1st-level seeker
inline int dgmWuJenPupilLeaveDiv()
    { return 2; }

// Wu jen prose (capture p. 50): no fighting men attracted - he hires them and
// must employ a lieutenant to command them
inline bool dgmWuJenStrongholdWithLieutenant()
    { return true; }

// Wu jen prose (capture p. 51): wu jen speak the language of tengu and oni
inline bool dgmWuJenTenguOniLanguage()
    { return true; }

// Wu jen prose (capture p. 51): the +20 percent reaction modifier with tengu
// and oni
inline int dgmWuJenTenguOniReaction()
    { return 20; }

// Wu jen prose (capture p. 51): no Table 38 roll, no family bonuses or
// penalties
inline bool dgmWuJenNoFamily()
    { return true; }

// Wu jen prose (capture p. 51): integrity without the honor codes - bonuses
// and penalties of honor are much smaller
inline bool dgmWuJenLightHonor()
    { return true; }

// Wu jen prose (capture p. 51): one taboo at 1st level
inline int dgmWuJenTabooFirstLevel()
    { return 1; }

// Wu jen prose (capture p. 51): an additional taboo upon gaining every five
// levels
inline int dgmWuJenTabooStepLevels()
    { return 5; }

// Wu jen prose (capture p. 51): violating a taboo brings loss of spells,
// illness or other evil events; the DM may add similar taboos
inline bool dgmWuJenTabooConsequences()
    { return true; }

// ---- the Table 31, Table 32 and Table 33 grids ----

// Table 31 (capture pp. 47-48): eleven rows, levels 1-11
inline int dgmT31RowCount()
    { return 11; }

// the experience column: the upper xp bound of each level, 2,000 at 1st to
// 800,000 at 11th - the row-2 bound OCR-mangled in the capture (4000 without
// the comma) and settled against the 2018 print (capture pp. 47-48).
inline int dgmT31XpMax(int b)
    {
        switch (b) {
        case 0:
            return 2000;
        case 1:
            return 4000;
        case 2:
            return 8000;
        case 3:
            return 18000;
        case 4:
            return 36000;
        case 5:
            return 65000;
        case 6:
            return 100000;
        case 7:
            return 140000;
        case 8:
            return 280000;
        case 9:
            return 600000;
        case 10:
            return 800000;
        default:
            return -99;
        }
    }

// the accumulated d4 dice column: one per level through 9th, then held at 9
// (capture pp. 47-48).
inline int dgmT31Dice(int b)
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
            return 9;
        case 10:
            return 9;
        default:
            return -99;
        }
    }

// the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level
// beyond 9th: 0 through 9th, then 1, 2 (capture pp. 47-48).
inline int dgmT31HpBonus(int b)
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
            return 2;
        default:
            return -99;
        }
    }

// Table 31 note (capture p. 48): 300,000 experience points are required for
// each level beyond 11th
inline int dgmT31XpBeyond()
    { return 300000; }

// Table 31 note (capture p. 48): wu jen gain 1 hp per level beyond 9th
inline int dgmT31HpBeyond()
    { return 1; }

// Table 32 (capture p. 48): seven tier rows, Intelligence 9 through 19 or
// more
inline int dgmT32RowCount()
    { return 7; }

// Table 32 (capture p. 48): the 19-or-more maximum reads All - pinned as the
// -1 code
inline int dgmT32MaxAll()
    { return -1; }

// the chance to know each listed spell column: 35 percent at Int 9 climbing
// 10 per tier to 95 at 19 or more (capture p. 48).
inline int dgmT32KnowPct(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 45;
        case 2:
            return 55;
        case 3:
            return 65;
        case 4:
            return 75;
        case 5:
            return 85;
        case 6:
            return 95;
        default:
            return -99;
        }
    }

// the minimum number of spells per level column: 4 at Int 9 to 10 at 19 or
// more (capture p. 48).
inline int dgmT32MinSpells(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 9;
        case 6:
            return 10;
        default:
            return -99;
        }
    }

// the maximum number of spells per level column: 6 at Int 9 to 18 at Int 18,
// then the printed All at 19 or more pinned as the -1 code (capture p. 48).
inline int dgmT32MaxSpells(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 14;
        case 5:
            return 18;
        case 6:
            return -1;
        default:
            return -99;
        }
    }

// Table 33 (capture p. 49): twenty-nine rows, levels 1-29
inline int dgmT33RowCount()
    { return 29; }

// Table 33 (capture p. 49): nine spell-level columns, 1st through 9th
inline int dgmT33SpellLevels()
    { return 9; }

// the 1st-level spells column: 1 at 1st to 9 at 28th - the row-5 cell (level
// 5) is contested, the capture prints 4 and the 2018 print 3; the 2018
// ladder-consistent reading stands (capture p. 49).
inline int dgmT33S1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
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
            return 5;
        case 12:
            return 5;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 8;
        case 25:
            return 8;
        case 26:
            return 8;
        case 27:
            return 9;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 2nd-level spells column: none until 3rd, then 1 to 9 at 29th (capture
// p. 49).
inline int dgmT33S2(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 8;
        case 26:
            return 8;
        case 27:
            return 8;
        case 28:
            return 9;
        default:
            return -99;
        }
    }

// the 3rd-level spells column: none until 5th, then 1 to 8 at 29th (capture
// p. 49).
inline int dgmT33S3(int b)
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
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 7;
        case 26:
            return 8;
        case 27:
            return 8;
        case 28:
            return 8;
        default:
            return -99;
        }
    }

// the 4th-level spells column: none until 7th, then 1 to 8 at 29th (capture
// p. 49).
inline int dgmT33S4(int b)
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
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 6;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 8;
        default:
            return -99;
        }
    }

// the 5th-level spells column: none until 9th, then 1 to 7 at 29th (capture
// p. 49).
inline int dgmT33S5(int b)
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
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 6;
        case 25:
            return 6;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 7;
        default:
            return -99;
        }
    }

// the 6th-level spells column: none until 11th, then 1 to 7 at 29th (capture
// p. 49).
inline int dgmT33S6(int b)
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
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 6;
        case 25:
            return 6;
        case 26:
            return 6;
        case 27:
            return 7;
        case 28:
            return 7;
        default:
            return -99;
        }
    }

// the 7th-level spells column: none until 13th, then 1 to 6 at 29th (capture
// p. 49).
inline int dgmT33S7(int b)
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
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 5;
        case 28:
            return 6;
        default:
            return -99;
        }
    }

// the 8th-level spells column: none until 17th, then 1 to 5 at 29th (capture
// p. 49).
inline int dgmT33S8(int b)
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
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 5;
        case 28:
            return 5;
        default:
            return -99;
        }
    }

// the 9th-level spells column: none until 21st, then 1 to 4 at 29th - the
// row-22 cell (level 22) is contested, the capture prints 2 and the 2018
// print 1; the 2018 ladder-consistent reading stands (capture p. 49).
inline int dgmT33S9(int b)
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
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 3;
        case 26:
            return 3;
        case 27:
            return 3;
        case 28:
            return 4;
        default:
            return -99;
        }
    }

}   // namespace rules
