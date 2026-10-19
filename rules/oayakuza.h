// =========================================================================================
// Adnd1 - rules/oayakuza.h
// THE YAKUZA, printed capture pp. 51-54 - the OA yakuza round
// census 549 -> 550.
//
// verified against capture pp. 51-54 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). No contested cells this
// round - both captures agree on every pinned value. The T35 area column pins
// as the 1-9 code: 1, 2 and 3 blocks; 1 ward 4; 2 wards 5; 1 district 6; 2
// districts 7; 3 districts 8; province 9. The T34 9-plus-N cells pin as dice
// 9 with the 1-per-level bonus 1, 2, 3. OCR normalization: Zing reads Zingi;
// 2d level reads 2nd level; hide-out and hideout both printed
//
// the gap census after this round: 59 closed, 176 open - the yakuza boxes
// with Tables 34 and 35 flip (census 549 -> 550); NEXT - R628: the Character
// Abilities chapter opener, capture pp. 55-59, Tables 36 (Multiple Attacks),
// prefix dgo (verify free), audit "R628 OA character abilities audit",
// include after rules/oayakuza.h
//
namespace rules {

// ---- the yakuza doctrine pins ----

// Yakuza prose (capture p. 52): the Strength minimum
inline int dgnYakuzaMinStr()
    { return 11; }

// Yakuza prose (capture p. 52): the Intelligence minimum
inline int dgnYakuzaMinInt()
    { return 15; }

// Yakuza prose (capture p. 52): the Dexterity minimum
inline int dgnYakuzaMinDex()
    { return 15; }

// Yakuza prose (capture p. 52): the Charisma minimum
inline int dgnYakuzaMinCha()
    { return 16; }

// Yakuza prose (capture p. 52): the 6-sided hit die, one per level
inline int dgnYakuzaHitDie()
    { return 6; }

// Yakuza prose (capture p. 52): three weapon proficiency slots
inline int dgnYakuzaSlots()
    { return 3; }

// Yakuza prose (capture p. 52): the yakuza is always lawful, rarely lawful
// good
inline bool dgnYakuzaAlwaysLawful()
    { return true; }

// Yakuza prose (capture p. 52): no prime requisite
inline bool dgnYakuzaNoPrimeReq()
    { return true; }

// Yakuza prose (capture p. 52): the thief combat and saving throw tables
inline bool dgnYakuzaThiefTables()
    { return true; }

// Yakuza prose (capture p. 52): any weapon may be used
inline bool dgnYakuzaAnyWeapon()
    { return true; }

// Yakuza prose (capture p. 52): the armor choices from Table 13
inline bool dgnYakuzaArmorFromTable13()
    { return true; }

// Yakuza prose (capture p. 52): no shield may be used
inline bool dgnYakuzaNoShields()
    { return true; }

// ---- the yakuza family and ki pins ----

// Yakuza prose (capture p. 52): the yakuza must belong to a family or clan
inline bool dgnYakuzaFamilyClanRequired()
    { return true; }

// Yakuza prose (capture p. 52): the -5 birth-rank modifier on the family-clan
// roll
inline int dgnYakuzaFamilyBirthMod()
    { return -5; }

// Yakuza prose (capture p. 52): the free gaming proficiency
inline bool dgnYakuzaFreeGamingProf()
    { return true; }

// Yakuza prose (capture p. 52): the thief abilities at the ninja chances
inline bool dgnYakuzaThiefSkillsAtNinja()
    { return true; }

// Yakuza prose (capture p. 52): hear noise at the monk chances
inline bool dgnYakuzaHearNoiseAsMonk()
    { return true; }

// Yakuza prose (capture p. 53): the ki power halves the damage, rounding up
inline int dgnYakuzaKiDamageDiv()
    { return 2; }

// Yakuza prose (capture p. 53): the halved damage rounds up
inline bool dgnYakuzaKiHalvesRoundUp()
    { return true; }

// Yakuza prose (capture p. 53): the ki power usable once per round
inline int dgnYakuzaKiPerRound()
    { return 1; }

// Yakuza prose (capture p. 53): the ki power usable once per level per day
inline int dgnYakuzaKiPerDayPerLevel()
    { return 1; }

// Yakuza prose (capture p. 53): the +10 percent encounter reaction bonus
inline int dgnYakuzaReactionBonusPct()
    { return 10; }

// Yakuza prose (capture p. 53): the +10 reaction bonus never applies to
// social-status rolls
inline bool dgnYakuzaReactionExcludesStatus()
    { return true; }

// ---- the yakuza investigate pins ----

// Yakuza prose (capture p. 53): common information takes one day
inline int dgnYakuzaInfoCommonDays()
    { return 1; }

// Yakuza prose (capture p. 53): common information costs 2d6 fen
inline int dgnYakuzaInfoCommonCostCount()
    { return 2; }

// Yakuza prose (capture p. 53): the 2d6-fen common cost dice
inline int dgnYakuzaInfoCommonCostDice()
    { return 6; }

// Yakuza prose (capture p. 53): common information is always accurate
inline bool dgnYakuzaInfoCommonAlwaysAccurate()
    { return true; }

// Yakuza prose (capture p. 53): uncommon information takes 1-3 days
inline int dgnYakuzaInfoUncommonDaysMin()
    { return 1; }

// Yakuza prose (capture p. 53): the 1-3 day uncommon upper bound
inline int dgnYakuzaInfoUncommonDaysMax()
    { return 3; }

// Yakuza prose (capture p. 53): uncommon information costs 2d4 yuan
inline int dgnYakuzaInfoUncommonCostDice()
    { return 4; }

// Yakuza prose (capture p. 53): the 10 percent inaccurate chance, uncommon
inline int dgnYakuzaInfoUncommonInacc()
    { return 10; }

// Yakuza prose (capture p. 53): confidential information takes 2d6 days
inline int dgnYakuzaInfoConfDaysMin()
    { return 2; }

// Yakuza prose (capture p. 53): the 2d6-day confidential upper bound
inline int dgnYakuzaInfoConfDaysMax()
    { return 12; }

// Yakuza prose (capture p. 53): confidential information costs 2d10 tael
inline int dgnYakuzaInfoConfCostDice()
    { return 10; }

// Yakuza prose (capture p. 53): the 25 percent inaccurate chance,
// confidential
inline int dgnYakuzaInfoConfInacc()
    { return 25; }

// Yakuza prose (capture p. 53): secret information takes 3d6 days
inline int dgnYakuzaInfoSecretDaysMin()
    { return 3; }

// Yakuza prose (capture p. 53): the 3d6-day secret upper bound
inline int dgnYakuzaInfoSecretDaysMax()
    { return 18; }

// Yakuza prose (capture p. 53): secret information costs 2d10 ch'ien
inline int dgnYakuzaInfoSecretCostDice()
    { return 10; }

// Yakuza prose (capture p. 53): the 40 percent inaccurate chance, secret
inline int dgnYakuzaInfoSecretInacc()
    { return 40; }

// Yakuza prose (capture p. 53): the investigate ability never reveals magical
// items
inline bool dgnYakuzaInfoNeverMagical()
    { return true; }

// Yakuza prose (capture p. 53): the investigate ability never reveals
// legendary lore
inline bool dgnYakuzaInfoNeverLegendary()
    { return true; }

// ---- the yakuza brethren and honor pins ----

// Yakuza prose (capture p. 54): the kyodai-bun brethren gained from 2nd level
inline int dgnYakuzaBrethrenMinLevel()
    { return 2; }

// Yakuza prose (capture p. 54): one brother gained once per level of
// experience
inline int dgnYakuzaBrethrenPerLevel()
    { return 1; }

// Yakuza prose (capture p. 54): no brother ever above 8th level
inline int dgnYakuzaBrethrenMaxLevel()
    { return 8; }

// Yakuza prose (capture p. 54): major enterprises need the oyabun approval
inline bool dgnYakuzaEnterpriseNeedsOyabun()
    { return true; }

// Yakuza prose (capture p. 54): adoption into the kumi without the Table 39
// or 40 rolls
inline bool dgnYakuzaAdoptedNoRolls()
    { return true; }

// Yakuza prose (capture p. 53): the monthly stipend, 2 ch'ien per level
inline int dgnYakuzaStipendPerLevel()
    { return 2; }

// Yakuza prose (capture p. 53): one contact per two levels of experience
inline int dgnYakuzaContactLevelDiv()
    { return 2; }

// Yakuza prose (capture p. 53): no contact more than four levels above the
// yakuza
inline int dgnYakuzaContactMaxAbove()
    { return 4; }

// Yakuza prose (capture p. 54): tattoos per level, never on the face, hands
// or feet
inline bool dgnYakuzaTattoosNeverFaceHandsFeet()
    { return true; }

// Yakuza prose (capture p. 54): cast out below the family honor, a non-person
// whose death is not avenged
inline bool dgnYakuzaCastOutNonPerson()
    { return true; }

// Yakuza prose (capture p. 54): cast-out membership can be regained
inline bool dgnYakuzaMembershipRegainable()
    { return true; }

// Yakuza prose (capture p. 54): always criminals, wary of the law
inline bool dgnYakuzaWaryOfLaw()
    { return true; }

// ---- the Table 34 and Table 35 grids ----

// Table 34 (capture p. 51): twelve advancement rows
inline int dgnT34RowCount()
    { return 12; }

// Table 34 note (capture p. 51): 300,000 xp per level beyond 12th
inline int dgnYakuzaXpBeyond12th()
    { return 300000; }

// Table 34 note (capture p. 51): 1 hit point per level beyond 9th
inline int dgnYakuzaHpPerLevelBeyond9()
    { return 1; }

// Table 35 (capture p. 53): twenty-one capability rows
inline int dgnT35RowCount()
    { return 21; }

// the experience column: the upper xp bound of each level, 2,000 at 1st to
// 1,400,000 at 12th (capture p. 51).
inline int dgnT34XpMax(int b)
    {
        switch (b) {
        case 0:
            return 2000;
        case 1:
            return 4000;
        case 2:
            return 8000;
        case 3:
            return 16000;
        case 4:
            return 30000;
        case 5:
            return 60000;
        case 6:
            return 130000;
        case 7:
            return 260000;
        case 8:
            return 520000;
        case 9:
            return 800000;
        case 10:
            return 1100000;
        case 11:
            return 1400000;
        default:
            return -99;
        }
    }

// the accumulated d6 dice column: one per level through 9th, then held at 9
// (capture p. 51).
inline int dgnT34Dice(int b)
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
        case 11:
            return 9;
        default:
            return -99;
        }
    }

// the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level
// beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 51).
inline int dgnT34HpBonus(int b)
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
        case 11:
            return 3;
        default:
            return -99;
        }
    }

// the investigate column: the whole-percent ladder, 20 at 1st rising by 4 to
// 92 at 19th, then 95 at 20th and 21st (capture p. 53).
inline int dgnT35InvestigatePct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 24;
        case 2:
            return 28;
        case 3:
            return 32;
        case 4:
            return 36;
        case 5:
            return 40;
        case 6:
            return 44;
        case 7:
            return 48;
        case 8:
            return 52;
        case 9:
            return 56;
        case 10:
            return 60;
        case 11:
            return 64;
        case 12:
            return 68;
        case 13:
            return 72;
        case 14:
            return 76;
        case 15:
            return 80;
        case 16:
            return 84;
        case 17:
            return 88;
        case 18:
            return 92;
        case 19:
            return 95;
        case 20:
            return 95;
        default:
            return -99;
        }
    }

// the area covered column, pinned as the 1-9 code: 1, 2 and 3 blocks as 1, 2,
// 3; 1 ward 4; 2 wards 5; 1 district 6; 2 districts 7; 3 districts 8;
// province 9 (capture p. 53).
inline int dgnT35AreaCode(int b)
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
            return 5;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 9;
        default:
            return -99;
        }
    }

}   // namespace rules
