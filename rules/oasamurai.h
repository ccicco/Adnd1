// =========================================================================================
// Adnd1 - rules/oasamurai.h
// THE SAMURAI, printed capture pp. 39-42 - the OA samurai round
// census 545 -> 546.
//
// verified against capture pp. 39-42 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). The Table 25 hit-points
// header is settled against the 2018 print (10-sided dice for accum. hit
// points) - the dice column pins as accumulated d10 with the printed 9-plus-N
// cells. The Table 25 grid itself sits as an extracted image in the first
// capture; the cells pin from the page-40 continuation with the 2018 print
// confirming every cell. OCR normalization: 2d level reads as 2nd level; a
// fitting homes reads as a fitting home; Stunned character cannot reads as
// the stunned cannot (prose only)
//
// the gap census after this round: 45 closed, 190 open - the samurai boxes
// with Table 25 flip (census 545 -> 546); NEXT - R624: the Shukenja, capture
// pp. 42-45, Tables 26, 27 and 28, prefix dgk (verify free), audit "R624 OA
// shukenja audit", include after rules/oasamurai.h
//
namespace rules {

// ---- the samurai doctrine pins ----

// Samurai prose (capture p. 40): the Strength minimum
inline int dgjSamuraiMinStr()
    { return 13; }

// Samurai prose (capture p. 40): the Wisdom minimum
inline int dgjSamuraiMinWis()
    { return 13; }

// Samurai prose (capture p. 40): the Constitution minimum
inline int dgjSamuraiMinCon()
    { return 13; }

// Samurai prose (capture p. 40): the Intelligence minimum
inline int dgjSamuraiMinInt()
    { return 14; }

// Samurai prose (capture p. 40): must be of lawful alignment - good, evil or
// neutral
inline bool dgjSamuraiLawfulOnly()
    { return true; }

// Samurai prose (capture p. 40): fights and makes saving throws as a fighter
inline bool dgjSamuraiFighterTables()
    { return true; }

// Samurai prose (capture p. 40): no prime requisite - no experience point
// bonuses for high scores
inline bool dgjSamuraiNoPrimeBonus()
    { return true; }

// Samurai prose (capture p. 40): the 10-sided hit die, one per level
inline int dgjSamuraiHitDie()
    { return 10; }

// Samurai prose (capture p. 40): five proficiency slots at 1st level
inline int dgjSamuraiSlots()
    { return 5; }

// Samurai prose (capture p. 40): every samurai must specialize with the
// katana
inline bool dgjSamuraiKatanaRequired()
    { return true; }

// Samurai prose (capture p. 40): only samurai may specialize in two weapons
// at once - katana and daikyu
inline bool dgjSamuraiTwoWeaponOnly()
    { return true; }

// Samurai prose (capture p. 40): any armor but never a shield
inline bool dgjSamuraiAnyArmorNoShield()
    { return true; }

// Samurai prose (capture p. 40): gaining proficiency with and using
// ninja-favored weapons costs honor
inline bool dgjSamuraiNinjaWeaponsHonorLoss()
    { return true; }

// Samurai prose (capture p. 40): human or spirit folk samurai belong to the
// highest caste, commonly of noble birth
inline bool dgjSamuraiHighestCaste()
    { return true; }

// Samurai prose (capture p. 40): the +10 bonus on the Table 38 Character
// Birth roll for the highest caste
inline int dgjSamuraiBirthBonus()
    { return 10; }

// Samurai prose (capture p. 40): korobokuru need a daimyo sponsor and skip
// Table 38, automatically beginning at Upper Class
inline bool dgjSamuraiKorobokuruSponsor()
    { return true; }

// Samurai prose (capture p. 40): until the sponsor is found the korobokuru
// samurai is treated as a bushi, unable to advance beyond 1st level
inline bool dgjSamuraiKorobokuruBushi()
    { return true; }

// Samurai prose (capture p. 40): horsemanship proficiency required at 2nd
// level
inline int dgjSamuraiHorseLevel()
    { return 2; }

// Samurai prose (capture p. 40): bow proficiency required by 3rd level
inline int dgjSamuraiBowLevel()
    { return 3; }

// Samurai prose (capture p. 40): calligraphy, painting and poetry
// proficiencies required by 6th level
inline int dgjSamuraiArtsLevel()
    { return 6; }

// Samurai prose (capture p. 40): the three arts proficiencies
inline int dgjSamuraiArtsCount()
    { return 3; }

// ---- the samurai power pins ----

// Samurai prose (capture p. 41): the ki focus at 1st level
inline int dgjSamuraiKiLevel()
    { return 1; }

// Samurai prose (capture p. 41): the ki effect lasts one round
inline int dgjSamuraiKiRounds()
    { return 1; }

// Samurai prose (capture p. 41): the ki usable a number of times per day
// equal to level - the printed 7th-level example
inline int dgjSamuraiKiPerDayMult()
    { return 1; }

// Samurai prose (capture p. 41): the ki focus with the kiai shout raises
// Strength to 18/00
inline bool dgjSamuraiKiStrength1800()
    { return true; }

// Samurai prose (capture p. 41): the +1 damage bonus starting at 2nd level
inline int dgjSamuraiDmgBaseLevel()
    { return 2; }

// Samurai prose (capture p. 41): the base damage bonus
inline int dgjSamuraiDmgBase()
    { return 1; }

// Samurai prose (capture p. 41): the bonus increases one point per three
// levels beyond 2nd - +2 at 5th, +3 at 8th
inline int dgjSamuraiDmgStepLevels()
    { return 3; }

// Samurai prose (capture p. 41): surprised only on a 1 on 1d6 from 3rd level
inline int dgjSamuraiSurpriseLevel()
    { return 3; }

// Samurai prose (capture p. 41): the surprise roll value
inline int dgjSamuraiSurpriseRoll()
    { return 1; }

// Samurai prose (capture p. 41): immune to all types of fear from 5th level
inline int dgjSamuraiFearImmuneLevel()
    { return 5; }

// Samurai prose (capture p. 41): the appearance fear at 6th level
inline int dgjSamuraiAppFearLevel()
    { return 6; }

// Samurai prose (capture p. 41): the appearance fear affects creatures of 1
// Hit Die or less
inline int dgjSamuraiAppFearHdMax()
    { return 1; }

// Samurai prose (capture p. 41): the appearance fear is turned on and off at
// will; a passed save means immunity for the encounter
inline bool dgjSamuraiAppFearControllable()
    { return true; }

// Samurai prose (capture p. 41): the appearance fear allows a saving throw vs
// breath weapon
inline bool dgjSamuraiAppFearSaveAllowed()
    { return true; }

// ---- the samurai stewardship pins ----

// Samurai prose (capture p. 41): the jito stewardship offer at 7th level
inline int dgjSamuraiJitoLevel()
    { return 7; }

// Samurai prose (capture p. 41): the jito receives one-quarter of the taxes
// he collects
inline int dgjSamuraiJitoTaxShareDiv()
    { return 4; }

// Samurai prose (capture p. 41): the daimyo provides the new jito with 10
// bushi
inline int dgjSamuraiJitoBushi()
    { return 10; }

// Samurai prose (capture p. 41): one to four samurai provided with the jito
// grant
inline int dgjSamuraiJitoSamuraiMin()
    { return 1; }

// Samurai prose (capture p. 41): the samurai upper bound of the jito grant
inline int dgjSamuraiJitoSamuraiMax()
    { return 4; }

// Samurai prose (capture p. 41): the jito followers are all of 1st to 3rd
// level
inline int dgjSamuraiJitoFollowerLevelMin()
    { return 1; }

// Samurai prose (capture p. 41): the follower level upper bound
inline int dgjSamuraiJitoFollowerLevelMax()
    { return 3; }

// Samurai prose (capture p. 41): the jito stewardship is not required -
// refusal earns a fitting home in the city or bakufu
inline bool dgjSamuraiJitoOptional()
    { return true; }

// Samurai prose (capture p. 41): the jito followers are ultimately loyal to
// the daimyo but faithfully serve the character unless the daimyo intervenes
inline bool dgjSamuraiJitoDaimyoLoyal()
    { return true; }

// Samurai prose (capture p. 41): the jito position is retained from that
// point on, even after establishing his own family
inline bool dgjSamuraiJitoRetained()
    { return true; }

// Samurai prose (capture p. 41): the property remains the daimyo - only he
// may dispose of it; a jito usurpation is not unknown
inline bool dgjSamuraiJitoDaimyoProperty()
    { return true; }

// Samurai prose (capture p. 41): the shugo position offered at 8th level
inline int dgjSamuraiShugoLevel()
    { return 8; }

// Samurai prose (capture p. 41): the shugo attracts 10d10 bushi followers
inline int dgjSamuraiShugoBushiDice()
    { return 10; }

// Samurai prose (capture p. 41): the 20 percent chance that one of the bushi
// is an infiltrator ninja
inline int dgjSamuraiShugoNinjaPct()
    { return 20; }

// Samurai prose (capture p. 41): no more than one ninja will ever operate in
// any household
inline bool dgjSamuraiOneNinjaPerHousehold()
    { return true; }

// Samurai prose (capture p. 41): the shugo bushi stay loyal while adequately
// paid, housed, fed and the master does not look too bleak
inline bool dgjSamuraiShugoLoyalWhilePaid()
    { return true; }

// Samurai prose (capture p. 41): the 2d10 samurai attracted at 9th level
inline int dgjSamuraiSamuraiLevel()
    { return 9; }

// Samurai prose (capture p. 41): the 2d10 samurai follower die
inline int dgjSamuraiSamuraiDice()
    { return 10; }

// Samurai prose (capture p. 41): the 9th-level samurai followers are
// absolutely loyal, as befits his station
inline bool dgjSamuraiFollowersAbsoluteLoyal()
    { return true; }

// Samurai prose (capture p. 41): 2-7 specialists request service at 9th level
inline int dgjSamuraiSpecialistMin()
    { return 2; }

// Samurai prose (capture p. 41): the specialist upper bound
inline int dgjSamuraiSpecialistMax()
    { return 7; }

// Samurai prose (capture p. 41): the 10 percent chance one specialist is a
// ninja spy
inline int dgjSamuraiSpecialistNinjaPct()
    { return 10; }

// Samurai prose (capture p. 41): the great kiai at 9th level
inline int dgjSamuraiGreatKiaiLevel()
    { return 9; }

// Samurai prose (capture p. 41): the great kiai raises Strength to 18/00 for
// two rounds
inline int dgjSamuraiGreatKiaiRounds()
    { return 2; }

// Samurai prose (capture p. 41): all enemies within 10 feet must save vs
// paralyzation
inline int dgjSamuraiGreatKiaiRadius()
    { return 10; }

// Samurai prose (capture p. 41): the failed save means stunned for one round
inline int dgjSamuraiGreatKiaiStunRounds()
    { return 1; }

// Samurai prose (capture p. 41): the great kiai only once per day
inline bool dgjSamuraiGreatKiaiOnceDaily()
    { return true; }

// Samurai prose (capture p. 41): the normal ki power and the great kiai
// cannot be used on the same day
inline bool dgjSamuraiGreatKiaiExcludesKi()
    { return true; }

// Samurai prose (capture p. 41): the stunned gain no Armor Class bonuses for
// Dexterity or shields and cannot move or attack
inline bool dgjSamuraiGreatKiaiStunEffects()
    { return true; }

// ---- the samurai bushido and Table 25 pins ----

// Samurai prose (capture p. 42): the bushido precepts - obedience, the death
// protest, no failure, the greatest service, vengeance, the shared dishonor,
// no mercy, the repaid debts, the cowardice
inline bool dgjSamuraiBushidoPrecepts()
    { return true; }

// Samurai prose (capture p. 42): honor below the set values loses the samurai
// status - the ronin is a samurai without a master
inline bool dgjSamuraiRoninDemotion()
    { return true; }

// Samurai prose (capture p. 42): the ronin retains the samurai abilities
// except property and attracting fighting men
inline bool dgjSamuraiRoninRetainsAbilities()
    { return true; }

// Samurai prose (capture p. 42): the ronin advances at double the normal
// experience point cost
inline int dgjSamuraiRoninXpMult()
    { return 2; }

// Samurai prose (capture p. 42): a ronin returns to full status provided his
// honor is above the required level and the daimyo accepts him
inline bool dgjSamuraiRoninReturnable()
    { return true; }

// Table 25 (capture pp. 39-40): twelve rows, levels 1-12
inline int dgjT25RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 2,500 at 1st to
// 1,300,000 at 12th (capture pp. 39-40).
inline int dgjT25XpMax(int b)
    {
        switch (b) {
        case 0:
            return 2500;
        case 1:
            return 5000;
        case 2:
            return 10000;
        case 3:
            return 18000;
        case 4:
            return 36500;
        case 5:
            return 75000;
        case 6:
            return 135000;
        case 7:
            return 235000;
        case 8:
            return 400000;
        case 9:
            return 650000;
        case 10:
            return 1000000;
        case 11:
            return 1300000;
        default:
            return -99;
        }
    }

// the accumulated d10 dice column: one per level through 9th, then held at 9
// (capture pp. 39-40).
inline int dgjT25Dice(int b)
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

// the hit-point bonus column: the printed 9-plus-N cells - 2 hp per level
// beyond 10th: 0 through 9th, then 2, 4, 6 (capture pp. 39-40).
inline int dgjT25HpBonus(int b)
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
            return 2;
        case 10:
            return 4;
        case 11:
            return 6;
        default:
            return -99;
        }
    }

// the damage bonus column: 0 at 1st, +1 from 2nd, +2 from 5th, +3 from 8th,
// +4 from 11th (capture pp. 39-40).
inline int dgjT25Dmg(int b)
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
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        default:
            return -99;
        }
    }

// Table 25 note (capture p. 40): 300,000 experience points are required for
// each level beyond 12th
inline int dgjT25XpBeyond()
    { return 300000; }

// Table 25 note (capture p. 40): samurai gain 2 hp per level beyond 10th
inline int dgjT25HpBeyond()
    { return 2; }

}   // namespace rules
