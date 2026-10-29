// =========================================================================================
// Adnd1 - rules/wmn.h
// The issue-3 opener - Lakofka's Notes on Women & Magic: Bringing the Distaff
// Gamer into D&D (folios 7-10)
// census 817 -> 818.
//
// Pinned from The Dragon Vol. 1 No. 3 (October 1976): folios 7-10, Len
// Lakofka's Notes on Women & Magic - the Beauty attribute on two 1-10
// twenty-siders, the four female class ladders to War Lady, Matriarch, Sibyl
// and Witch 22nd, the Seduction and Charm Men and Charm Humanoid Monster
// spell family with the beauty matrix and the save ladders, the Horrid Beauty
// tiers, Poison, Magic Mount, Mind Meld, Spirit and the chaotic cleric
// Worship. The opener round also seats the issue voice: all 32 folio pages
// committed as the transcript, and the issue-3 gap report ships pre-flip. The
// folio-3 War of the Empires wargame history and all fiction and ads are
// scoped out per the R895 adjudication.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// printed hit-dice forms X+Y are CONVERTED to base-plus-bonus columns, the
// conversion noted; the 1.8x maximum load pins as 18 tenths; the folio-7
// strength line garbles in OCR as '18 sided die' and pins as 1d8+1d6 per the
// folio-8 range 2-14, never silent. The beauty matrix, the Witch-grid odd
// hit-dice cells (10+4, 11+7) and the ugly-tier flee sign ride AS SCANNED -
// no figure pixels ride the OCR artifact to verify against - the honest
// boundary pinned beside each. OD&D-era ink converted per the walk doctrine:
// the pin IS the conversion, noted, never silent.
//
namespace rules {

// ---- the woman's frame (folios 7-8) ----

// BEAUTY replaces Charisma for women, rated on TWO twenty-sided dice (folio
// 7)
inline int wmnBeautyDiceCount()
    { return 2; }

// each beauty die is numbered one to ten, so the beauty range is 2-20, not
// 2-40 (folio 7)
inline int wmnBeautyDieMax()
    { return 10; }

// the woman's strength rolls one 8-sided die plus one 6-sided die - the
// folio-7 line garbles in OCR as "18 sided die", pinned as 1d8 per the
// folio-8 strength range 2-14, the conversion noted, never silent (folio 7)
inline int wmnStrengthDieEight()
    { return 8; }

// the second strength die is the 6-sider (folio 7)
inline int wmnStrengthDieSix()
    { return 6; }

// women's strength scores range from 2 (folio 8)
inline int wmnStrengthMin()
    { return 2; }

// to 14 at the top (folio 8)
inline int wmnStrengthMax()
    { return 14; }

// any woman scoring 13 (folio 7)
inline int wmnStrConBonusMin()
    { return 13; }

// or 14 in strength (folio 7)
inline int wmnStrConBonusMax()
    { return 14; }

// may add 1 to her constitution score (folio 7)
inline int wmnStrConBonus()
    { return 1; }

// to cast spells a female thief needs intelligence 12 or higher (folio 8)
inline int wmnThiefSpellIntMin()
    { return 12; }

// except Seduction, Charm Men and Charm Humanoid Monster, where intelligence
// 9 suffices (folio 8)
inline int wmnThiefCharmIntMin()
    { return 9; }

// the thief casting those three spells must also carry a beauty score of 13
// or better (folio 8)
inline int wmnThiefCharmBeautyMin()
    { return 13; }

// women are allowed 1000 points of encumbrance (folio 8)
inline int wmnEncumbranceBase()
    { return 1000; }

// plus fifty times the strength rating, at no movement loss (folio 8)
inline int wmnEncumbrancePerStr()
    { return 50; }

// maximum load is 1.8 times the encumbrance score - pinned as 18 tenths, the
// decimal-to-integer conversion noted (folio 8)
inline int wmnMaxLoadTenths()
    { return 18; }

// women of strength 10 or lower wield flail, battle axes and morning stars at
// -1 (folio 8)
inline int wmnGroupOnePenalty()
    { return 1; }

// and at strength 10 or lower the pole arms, halberd, pike and two-handed
// sword go at -2 (folio 8)
inline int wmnGroupTwoPenaltyTen()
    { return 2; }

// women of strength 12 or lower wield only that latter group at -1 (folio 8)
inline int wmnGroupTwoPenaltyTwelve()
    { return 1; }

// ALL WOMEN wield a dagger at an additional +1 (folio 8)
inline int wmnDaggerBonus()
    { return 1; }

// plate armor carries a 20 percent greater fatigue rating in women of
// strength 10 or lower (folio 8)
inline int wmnPlateFatigueTen()
    { return 20; }

// and 10 percent at strength 11 or 12 (folio 8)
inline int wmnPlateFatigueTwelve()
    { return 10; }

// chainmail has a 10 percent greater fatigue factor in women of strength 11
// or lower (folio 8)
inline int wmnChainFatigueEleven()
    { return 10; }

// female magic users go without limit; from Witch level 13 they equal Wizard
// level 13 (folio 8)
inline int wmnWitchEqualLevel()
    { return 13; }

// women may progress to the level of men in magic and, in some ways, surpass
// men as thieves (folio 7)
inline bool wmnWomenSurpassMenThieves()
    { return true; }

// if the Alternate Combat System is used instead of Chainmail, subtract one
// level from all levels over one - else women fight as well as men for far
// fewer experience points (folio 7)
inline bool wmnAlternateSystemLevelCut()
    { return true; }

// clerics may not use beauty if they are lawful or neutral; chaotic clerics
// may use their beauty score (folio 7)
inline bool wmnChaoticClericsUseBeauty()
    { return true; }

// Seduction may be used on living humanoid unharmed males only (folio 8)
inline bool wmnSeductionMalesOnly()
    { return true; }

// the Tarot reading may be asked simple yes/no questions only, relating to
// the immediate future of one day at most (folio 8)
inline bool wmnTarotYesNoOnly()
    { return true; }

// the Sibyl at level 9 and beyond can tell something from the three cards
// used; Sibyl level 8 and below cannot (folio 8)
inline bool wmnTarotSibylReads()
    { return true; }

// ---- the four ladders (folios 7-8) ----

// the Fighting Woman ladder runs ten levels, Fighting Woman to War Lady
// (folio 7)
inline int wmnFtrLevels()
    { return 10; }

// the Fighting Woman experience ladder - Fighting Woman 0 through War Lady
// 10th at 300000 (folio 7)
inline int wmnFtrXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1600;
        case 2:
            return 3200;
        case 3:
            return 6400;
        case 4:
            return 12800;
        case 5:
            return 25000;
        case 6:
            return 50000;
        case 7:
            return 100000;
        case 8:
            return 200000;
        case 9:
            return 300000;
        default:
            return 9;
        }
    }

// the hit-dice base split from the printed "X+Y" form - the conversion noted,
// never silent (folio 7)
inline int wmnFtrHitBase(int b)
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
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        default:
            return 9;
        }
    }

// the hit-dice bonus - 1+1 at first level, +2 from Myrmidon on (folio 7)
inline int wmnFtrHitBonus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        default:
            return 9;
        }
    }

// the female Cleric ladder runs twelve levels, Novice to Matriarch 12th
// (folios 7-8)
inline int wmnClrLevels()
    { return 12; }

// the female Cleric experience ladder - Novice 0 through Matriarch 12th at
// 400000 (folios 7-8)
inline int wmnClrXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1200;
        case 2:
            return 2400;
        case 3:
            return 4800;
        case 4:
            return 9600;
        case 5:
            return 20000;
        case 6:
            return 40000;
        case 7:
            return 80000;
        case 8:
            return 160000;
        case 9:
            return 240000;
        case 10:
            return 320000;
        case 11:
            return 400000;
        default:
            return 9;
        }
    }

// the hit-dice base split from the printed "X+Y" form - the conversion noted
// (folio 8)
inline int wmnClrHitBase(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 9;
        default:
            return 9;
        }
    }

// the hit-dice bonus - Apostolate 3+1, Deaconess 4+1, +2 from Superioress on
// (folio 8)
inline int wmnClrHitBonus(int b)
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
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        default:
            return 9;
        }
    }

// the female Thief ladder runs eight levels, Wench to Sibyl (folios 7-8)
inline int wmnThfLevels()
    { return 8; }

// the female Thief experience ladder - Wench 0 through Sibyl at 70000 (folios
// 7-8)
inline int wmnThfXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1000;
        case 2:
            return 2000;
        case 3:
            return 4000;
        case 4:
            return 8000;
        case 5:
            return 16000;
        case 6:
            return 35000;
        case 7:
            return 70000;
        default:
            return 9;
        }
    }

// the hit-dice base split from the printed "X+Y" form - the conversion noted
// (folio 8)
inline int wmnThfHitBase(int b)
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
        default:
            return 9;
        }
    }

// the hit-dice bonus - Adventuress 4+1, Soothsayer 4+2, Sibyl 5+2 (folio 8)
inline int wmnThfHitBonus(int b)
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
            return 0;
        case 7:
            return 2;
        default:
            return 9;
        }
    }

// the female Magic-User ladder runs twenty-two levels, Medium to Witch 22nd
// (folios 7-8)
inline int wmnMageLevels()
    { return 22; }

// the female Magic-User ladder - Medium 0 through Witch 22nd at 2400000,
// without limit above 13th (folios 7-8)
inline int wmnMageXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2400;
        case 2:
            return 4800;
        case 3:
            return 9600;
        case 4:
            return 20000;
        case 5:
            return 40000;
        case 6:
            return 65000;
        case 7:
            return 90000;
        case 8:
            return 180000;
        case 9:
            return 270000;
        case 10:
            return 360000;
        case 11:
            return 450000;
        case 12:
            return 600000;
        case 13:
            return 700000;
        case 14:
            return 800000;
        case 15:
            return 900000;
        case 16:
            return 1000000;
        case 17:
            return 1200000;
        case 18:
            return 1400000;
        case 19:
            return 1600000;
        case 20:
            return 2000000;
        case 21:
            return 2400000;
        default:
            return 9;
        }
    }

// the hit-dice base split from the printed "X+Y" form (folio 8)
inline int wmnMageHitBase(int b)
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
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 10;
        case 16:
            return 10;
        case 17:
            return 10;
        case 18:
            return 11;
        case 19:
            return 11;
        case 20:
            return 11;
        case 21:
            return 11;
        default:
            return 9;
        }
    }

// the hit-dice bonus AS SCANNED - the odd cells (Witch 18th 10+4, Witch 22nd
// 11+7) ride the transcript with no figure to check, the honest boundary
// noted (folio 8)
inline int wmnMageHitBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
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
        case 14:
            return 3;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 5;
        case 21:
            return 7;
        default:
            return 9;
        }
    }

// ---- the seduction family (folio 9) ----

// five charmer races in the beauty matrix - Elf, Woman, Hobbit, Orc, Dwarf
// (folio 9)
inline int wmnSeduceRaces()
    { return 5; }

// the minimum beauty to seduce a man of Men (folio 9)
inline int wmnSeduceVsMen(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 13;
        default:
            return 9;
        }
    }

// of the Elves (folio 9)
inline int wmnSeduceVsElves(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 20;
        case 4:
            return 15;
        default:
            return 9;
        }
    }

// of the Orcs (folio 9)
inline int wmnSeduceVsOrcs(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 13;
        case 3:
            return 11;
        case 4:
            return 14;
        default:
            return 9;
        }
    }

// of the Hobbits (folio 9)
inline int wmnSeduceVsHobbits(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 13;
        default:
            return 9;
        }
    }

// of the Dwarves (folio 9)
inline int wmnSeduceVsDwarves(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 17;
        case 4:
            return 11;
        default:
            return 9;
        }
    }

// for thieves add 2 to each beauty-matrix score (folio 9)
inline int wmnSeduceThiefBonus()
    { return 2; }

// for fighters add 4 to each beauty-matrix score (folio 9)
inline int wmnSeduceFighterBonus()
    { return 4; }

// the seduction spell's range is six feet, one figure at a time (folio 9)
inline int wmnSeduceRangeFeet()
    { return 6; }

// the enchanted victim is at the lowered rate for two full turns after a
// first-level seduction succeeds (folio 9)
inline int wmnSeduceEffectTurns()
    { return 2; }

// while enchanted he will attack at three levels lower (folio 9)
inline int wmnSeduceAttackPenalty()
    { return 3; }

// a fighter needs a 13 or higher on the summed roll to be saved (folio 9)
inline int wmnSeduceSaveFighter()
    { return 13; }

// a thief needs 12 or better (folio 9)
inline int wmnSeduceSaveThief()
    { return 12; }

// a paladin needs 10 or better (folio 9)
inline int wmnSeduceSavePaladin()
    { return 10; }

// a magic user needs 9 or better (folio 9)
inline int wmnSeduceSaveMage()
    { return 9; }

// a cleric needs an 8 or higher to stay celibate (folio 9)
inline int wmnSeduceSaveCleric()
    { return 8; }

// nine magic-user level bands in the seduction duration table (folio 9)
inline int wmnSeduceBands()
    { return 9; }

// the base turns a seduction lasts at this magic-user level band - flat 2 at
// levels 1-2, rising to 5 at 17-18 (folio 9)
inline int wmnSedBase(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
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
        default:
            return 9;
        }
    }

// the bonus die - 0 at the first band, 1-2 through 1-8 by band (folio 9)
inline int wmnSedDie(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 8;
        case 8:
            return 8;
        default:
            return 9;
        }
    }

// three Charm Men grades - I, II and III (folio 9)
inline int wmnCharmMenLevels()
    { return 3; }

// the hit-dice cap of the men affected - 3 or fewer for I, 4 for II, 5 for
// III (folio 9)
inline int wmnCmHdCap(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        default:
            return 9;
        }
    }

// the catatonia base turns - 3, 4, 5 by grade (folio 9)
inline int wmnCmCataBase(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        default:
            return 9;
        }
    }

// the catatonia bonus die - 1-4, 1-6, 1-8 by grade (folio 9)
inline int wmnCmCataDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 9;
        }
    }

// the base count of men affected - 4, 6, 8 by grade (folio 9)
inline int wmnCmAffBase(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 9;
        }
    }

// the affected bonus die - 1-4, 1-6, 1-8 by grade (folio 9)
inline int wmnCmAffDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 9;
        }
    }

// the Charm Men spell's range is sixteen feet (folio 9)
inline int wmnCharmRangeFeet()
    { return 16; }

// charmed hirelings may be taken over by the charmer after 2 turns of
// catatonia (folio 9)
inline int wmnCharmTakeoverTurns()
    { return 2; }

// the stronger figure attempts to prevent the charm with an 8-sided die roll
// (folio 9)
inline int wmnCharmBossDie()
    { return 8; }

// a 6 or higher dispels the charm (folio 9)
inline int wmnCharmBossDispels()
    { return 6; }

// magic users require beauty 11 to Charm Men (folio 9)
inline int wmnCharmBeautyMage()
    { return 11; }

// thieves require beauty 13 (folio 9)
inline int wmnCharmBeautyThief()
    { return 13; }

// fighters require beauty 16 (folio 9)
inline int wmnCharmBeautyFighter()
    { return 16; }

// Charm Humanoid Monster needs beauty 11 or higher for magic users (folio 9)
inline int wmnChmBeautyMage()
    { return 11; }

// and 13 or higher for thieves or fighters (folio 9)
inline int wmnChmBeautyThiefFighter()
    { return 13; }

// the charmed male monster becomes catatonic for 1-4 turns only if not
// attacked (folio 9)
inline int wmnChmCatatoniaDie()
    { return 4; }

// any attack may break the spell, 70 percent of breaking it (folio 9)
inline int wmnChmBreakPercent()
    { return 70; }

// if she tries to fight, an 8 or higher on a 20-sided die means he will try
// to kill her (folio 9)
inline int wmnChmKillRoll()
    { return 8; }

// a 9 or higher means he tries to grapple her (folio 9)
inline int wmnChmGrappleRoll()
    { return 9; }

// in the grapple he may harm her, 50 percent chance (folio 9)
inline int wmnChmHarmPercent()
    { return 50; }

// vampires, gargoyles and centaurs add 2 points to their level for
// intelligence/wisdom (folio 10)
inline int wmnChmLevelBonus()
    { return 2; }

// on the summed 20-sided roll a 12 (folio 9)
inline int wmnChmCarryRollMin()
    { return 12; }

// to 16 means he will carry her off; 17 or more is catatonia (folio 9)
inline int wmnChmCarryRollMax()
    { return 16; }

// ---- the witch additions (folios 9-10) ----

// five Horrid Beauty tiers - Grotesque, Ugly, Ordinary, Beautiful, Gorgeous
// (folio 10)
inline int wmnHbTiers()
    { return 5; }

// the beauty floor of the tier - Grotesque 2-5, Ugly 6-9, Ordinary 10-12,
// Beautiful 13-16, Gorgeous 17+ (folio 10)
inline int wmnHbBeautyMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 10;
        case 3:
            return 13;
        case 4:
            return 17;
        default:
            return 9;
        }
    }

// the hit dice scared to death - Grotesque 3 or fewer, Ugly 2 or fewer (folio
// 10)
inline int wmnHbScareHd(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 9;
        }
    }

// the no-save seduction hit-dice cap - Beautiful 4 or fewer, Gorgeous 5 or
// fewer; the figures above the cap may save (folio 10)
inline int wmnHbSeduceHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 9;
        }
    }

// the equivalent seduction spell level - Beautiful casts as 6th, Gorgeous as
// 7th (folio 10)
inline int wmnHbSeduceLevel(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 9;
        }
    }

// the morale points lowered on the flee - Grotesque 2, Ugly 1 (folio 10)
inline int wmnHbMoraleDrop(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 9;
        }
    }

// the flee-duration base turns - Grotesque 4, Ugly 2 (folio 10)
inline int wmnHbFleeBase(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 9;
        }
    }

// the flee-duration bonus die - Grotesque 1-6, Ugly 1-4, the printed sign AS
// SCANNED where ambiguous, the honest boundary noted (folio 10)
inline int wmnHbFleeDie(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 9;
        }
    }

// ordinary witches may have either Horrid Beauty effect on a 50/50 basis,
// dice cast for every figure individually (folio 10)
inline bool wmnOrdinaryEffectCoinFlip()
    { return true; }

// Horrid Beauty requires direct sight of the witch within 16 feet (folio 10)
inline int wmnHbRangeFeet()
    { return 16; }

// the Horrid Beauty duration is 6 turns, longer in the case of seduction
// spells (folio 10)
inline int wmnHbDurationTurns()
    { return 6; }

// any food or water may be poisoned from up to 18 inches away (folio 10)
inline int wmnPoisonRangeInches()
    { return 18; }

// the poison is deadly, inflicting 3 hits per turn with unconsciousness at
// once (folio 10)
inline int wmnPoisonDamagePerTurn()
    { return 3; }

// Purify Food & Water rids the affected food or water only 40 percent of the
// time (folio 10)
inline int wmnPoisonPurifyPct()
    { return 40; }

// Neutralize Poison succeeds only 60 percent of the time (folio 10)
inline int wmnPoisonNeutralizePct()
    { return 60; }

// Cure Disease succeeds only 10 percent of the time (folio 10)
inline int wmnPoisonCurePct()
    { return 10; }

// a Detect Magic spell detects the poison spell as it is being cast 30
// percent of the time (folio 10)
inline int wmnPoisonDetectPct()
    { return 30; }

// the two Mind Meld magic users must be within 6 inches of each other when
// casting (folio 10)
inline int wmnMeldCastRangeInches()
    { return 6; }

// and within 12 inches of each other at all times while the meld is in effect
// (folio 10)
inline int wmnMeldRangeInches()
    { return 12; }

// after 1 full turn the lower-ranked magic user increases by HALF the
// difference in levels (folio 10)
inline int wmnMeldLowGainDiv()
    { return 2; }

// and the stronger magic user's level goes up by 1 (folio 10)
inline int wmnMeldStrongerGain()
    { return 1; }

// if either receives damage points there is an 85 percent chance of insanity
// for the MU actually damaged (folio 10)
inline int wmnMeldInsanityDamaged()
    { return 85; }

// and 50 percent for the other (folio 10)
inline int wmnMeldInsanityOther()
    { return 50; }

// the meld stays in force for 6 turns (folio 10)
inline int wmnMeldDurationBase()
    { return 6; }

// plus 1-8 turns, then the spell must be broken (folio 10)
inline int wmnMeldDurationDie()
    { return 8; }

// to break the Mind Meld neither magic user must move or be damaged for two
// full turns (folio 10)
inline bool wmnMeldRequiresStillness()
    { return true; }

// the Magic Mount Wind Horse fights as 3 heavy horse (folio 10)
inline int wmnMountHeavyCount()
    { return 3; }

// two people may ride the horse at full speed (folio 10)
inline int wmnMountRiders()
    { return 2; }

// the Wind Horse's cloth must be placed about its neck as a bridle at once or
// the horse dispels (folio 10)
inline bool wmnMountBridleAtOnce()
    { return true; }

// the Spirit form moves laterally only at 12 inches per turn (folio 10)
inline int wmnSpiritMoveInches()
    { return 12; }

// the Spirit duration runs from 4 turns (folio 10)
inline int wmnSpiritDurationBase()
    { return 4; }

// plus 1-8 turns, with the judge warning one turn before the end (folio 10)
inline int wmnSpiritDurationDie()
    { return 8; }

// while in spirit form magic weapons do only 50 percent damage (folio 10)
inline int wmnSpiritMagicDamagePct()
    { return 50; }

// spells are only 30 percent effective (folio 10)
inline int wmnSpiritSpellPct()
    { return 30; }

// Worship is a 4th-level cleric spell used by chaotic clerics of beauty 11 or
// more (folio 10)
inline int wmnWorshipLevel()
    { return 4; }

// the chaotic cleric casting Worship needs beauty 11 or higher (folio 10)
inline int wmnWorshipBeautyMin()
    { return 11; }

// all men within 12 feet will idolize the cleric (folio 10)
inline int wmnWorshipRangeFeet()
    { return 12; }

// the trance holds for 4 turns (folio 10)
inline int wmnWorshipDurationBase()
    { return 4; }

// plus 1-8 turns (folio 10)
inline int wmnWorshipDurationDie()
    { return 8; }

// those with 4+1 hit dice (five) may have a saving throw as in a 4th-level
// seduction (folio 10)
inline int wmnWorshipSaveHd()
    { return 5; }

// for neutral and lawful clerics rate Charisma instead of beauty (folio 10)
inline bool wmnClericsRateCharisma()
    { return true; }

}   // namespace rules
