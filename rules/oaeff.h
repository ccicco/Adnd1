// =========================================================================================
// Adnd1 - rules/oaeff.h
// ALTERING FAMILY HONOR, THE EFFECTS OF HONOR AND TABLE 42, printed capture
// pp. 70-72 - the OA effects of honor round
// census 557 -> 558.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T42 grid pins as 68 rows x 2 columns
// across the ten printed sections (all characters, shukenja, hengeyokai,
// kensai, ninja, samurai, sohei, spirit folk, wu jen, yakuza); the points
// column carries every printed award and the mark column codes the printed
// footnotes (0 unmarked, 1 the samurai-doubled star, 2 the single-creature
// double star). The two rate rows pin as per-unit consts - the monsters row
// -1 per 2000 experience points for a single creature, the yakuza
// stolen-goods row +1 per 100 ch'ien - with the base points in the grid. OCR
// normalization: the double-star footnote reads "defeating a single-creature"
// with a printed em dash (pins as single-creature); the awards use the
// printed x.p. abbreviation. The Chapter 5 Money and Equipment prose (capture
// pp. 73+) is deliberately left for the next rounds
//
// the gap census after this round: 80 closed, 155 open - the Altering Family
// Honor, Effects of Honor prose, Table 42 and the Chapter 4 parent boxes flip
// (census 557 -> 558); NEXT - R636: the Chapter 5 Money and Equipment opener,
// the Currency prose with Table 43 (Currency Values) and Table 44 (Barter
// Units), capture pp. 73-75, prefix dgw (verify free), audit "R636 OA money
// audit", include after rules/oaeff.h
//
namespace rules {

// ---- the altering family honor pins ----

// Altering family honor prose (capture p. 70): the character 10 points above
// the family honor raises the family base
inline int dgvFamilyRaiseStep()
    { return 10; }

// Altering family honor prose (capture p. 70): the family base honor raise
// per step, also at 20, 30, 40 and so on
inline int dgvFamilyRaiseAmount()
    { return 1; }

// Altering family honor prose (capture p. 70): the single-action loss that
// blots the family - five or more points
inline int dgvFamilyLossThreshold()
    { return 5; }

// Altering family honor prose (capture p. 70): the family base honor loss for
// the blot
inline int dgvFamilyLossAmount()
    { return 1; }

// Altering family honor prose (capture p. 70): noble, heroic and successful
// characters elevate the family name while craven, lying and treacherous
// characters drag it down
inline bool dgvClanFortunesFollow()
    { return true; }

// Altering family honor prose (capture p. 70): the family raise is earned
// only once for each group of 10 points
inline bool dgvRaiseOncePerGroup()
    { return true; }

// Altering family honor prose (capture p. 70): the bonus can be earned even
// at the honor maximum - the character has reached his pinnacle but his deeds
// still reflect well upon the clan
inline bool dgvRaiseAtMaxHonor()
    { return true; }

// Altering family honor prose (capture p. 70): losing five or more points for
// a single action is a lasting blot on the family name
inline bool dgvLossBlotsFamily()
    { return true; }

// Altering family honor prose (capture p. 70): when a character changes the
// family honor, all other family members change by the same amount - family
// members affect each other
inline bool dgvFamilyShareChange()
    { return true; }

// ---- the effects of honor pins ----

// Effects of honor prose (capture pp. 71-72): the reaction modifier below the
// family or class base, -20 percent with the family members
inline int dgvBelowBaseModPct()
    { return -20; }

// Effects of honor prose (capture pp. 71-72): the reaction bonus per 10
// points above the base, +5 percent
inline int dgvAboveBaseBonusPct()
    { return 5; }

// Effects of honor prose (capture pp. 71-72): the gift from a powerful lord
// at 75 honor points
inline int dgvGiftHonorPoints()
    { return 75; }

// Effects of honor prose (capture pp. 71-72): the songs and stories at 80
// honor points
inline int dgvSongsHonorPoints()
    { return 80; }

// Effects of honor prose (capture pp. 71-72): the invitation to serve a great
// lord at 90 honor points
inline int dgvServeHonorPoints()
    { return 90; }

// Effects of honor prose (capture pp. 71-72): the great hero at 95 honor
// points
inline int dgvGreatHeroHonorPoints()
    { return 95; }

// Effects of honor prose (capture pp. 71-72): the 10 percent weekly chance of
// the notorious foe boasting
inline int dgvFoeBoastPct()
    { return 10; }

// Effects of honor prose (capture pp. 71-72): the honor loss for refusing to
// seek out the boasting foe
inline int dgvFoeRefuseHonorLoss()
    { return 10; }

// Effects of honor prose (capture pp. 71-72): the refusal penalty with the
// lord and his followers, -10 percent
inline int dgvServeRefusePct()
    { return -10; }

// Effects of honor prose (capture pp. 71-72): the +10 percent bonus with
// lesser rank, the -10 percent penalty with the opposite alignment
inline int dgvGreatHeroBonusPct()
    { return 10; }

// The final benefit prose (capture p. 72): the death-honor remainder divided
// by 10, fractions rounded down
inline int dgvSuccessorDivisor()
    { return 10; }

// The final benefit prose (capture p. 72): no more than three points on any
// single roll
inline int dgvSuccessorMaxPerRoll()
    { return 3; }

// Effects of honor prose (capture pp. 71-72): the advantages and
// disadvantages automatically come into play as honor is gained and lost
inline bool dgvEffectsAutomatic()
    { return true; }

// Effects of honor prose (capture pp. 71-72): honor below zero means the
// character is out of the game - the record sheet is crumpled up and tossed
// away
inline bool dgvBelowZeroOut()
    { return true; }

// Effects of honor prose (capture pp. 71-72): a samurai or kensai whose honor
// falls below the family base loses his status - the samurai becomes a ronin
// and the kensai is treated as a bushi
inline bool dgvSamuraiKensaiStatus()
    { return true; }

// Effects of honor prose (capture pp. 71-72): any class below the family
// honor or the class base takes the -20 percent family modifier until the
// honor again equals or exceeds the base
inline bool dgvBelowBaseFamilyMod()
    { return true; }

// Effects of honor prose (capture pp. 71-72): every 10 points above the base
// gives the +5 percent bonus, but the family or group honor also rises - it
// becomes harder and harder to impress them
inline bool dgvHarderToImpress()
    { return true; }

// Effects of honor prose (capture pp. 71-72): the 75-point gift is
// appropriate to the level and class, never a threat to the lord, and the
// player character is expected to return the compliment
inline bool dgvGiftFromLord()
    { return true; }

// Effects of honor prose (capture pp. 71-72): at 80 points the name appears
// in songs and stories; the notorious foe boasts reach the character's ears
// automatically
inline bool dgvSongsAndBoasts()
    { return true; }

// Effects of honor prose (capture pp. 71-72): at 90 points the character is
// invited to serve one of the most powerful lords - under no obligation, but
// refusal angers the lord
inline bool dgvLordInvitation()
    { return true; }

// Effects of honor prose (capture pp. 71-72): at 95 points the great hero
// gains the +10 percent bonus with lesser rank and the -10 percent penalty
// with opposite alignment or belief - friends treat him with respect, enemies
// hate him more
inline bool dgvGreatHeroRead()
    { return true; }

// The final benefit prose (capture p. 72): a character who dies and is not
// returned to play grants the next character bonus points - the death honor
// above the base, divided by 10 rounded down, added to ability or hit point
// dice rolls
inline bool dgvSuccessorBonus()
    { return true; }

// The final benefit prose (capture p. 72): the bonus cannot raise a roll
// above the racial or class maximum and cannot be saved for later in the
// career
inline bool dgvSuccessorLimits()
    { return true; }

// The final benefit prose (capture p. 72): the created character can be of
// any race, class or family, meeting the ability requirements normally
inline bool dgvSuccessorFreedom()
    { return true; }

// ---- the Table 42 grid ----

// Table 42 (capture p. 72): sixty-eight honor-award rows
inline int dgvT42RowCount()
    { return 68; }

// T42 monsters row (capture p. 72): the honor loss per 2000 experience
// points, single creatures only
inline int dgvMonsterXpPerPoint()
    { return 2000; }

// T42 yakuza row (capture p. 72): the honor gain per 100 ch'ien of stolen
// goods
inline int dgvStolenChienPerPoint()
    { return 100; }

// the honor points column, by deed row - the sections run 0-29 all
// characters, 30-32 shukenja, 33-34 hengeyokai, 35-41 kensai, 42-45 ninja,
// 46-58 samurai, 59-61 sohei, 62 spirit folk, 63 wu jen, 64-67 yakuza
// (capture p. 72).
inline int dgvT42Points(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return -5;
        case 4:
            return -10;
        case 5:
            return -4;
        case 6:
            return 5;
        case 7:
            return -10;
        case 8:
            return 2;
        case 9:
            return -1;
        case 10:
            return -1;
        case 11:
            return -2;
        case 12:
            return 7;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return -10;
        case 16:
            return -5;
        case 17:
            return -1;
        case 18:
            return -2;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return -3;
        case 22:
            return -2;
        case 23:
            return -2;
        case 24:
            return -2;
        case 25:
            return -2;
        case 26:
            return 5;
        case 27:
            return -2;
        case 28:
            return -30;
        case 29:
            return -1;
        case 30:
            return -1;
        case 31:
            return -1;
        case 32:
            return -3;
        case 33:
            return -1;
        case 34:
            return 1;
        case 35:
            return -3;
        case 36:
            return -2;
        case 37:
            return -5;
        case 38:
            return -5;
        case 39:
            return -1;
        case 40:
            return 3;
        case 41:
            return 1;
        case 42:
            return 3;
        case 43:
            return -10;
        case 44:
            return -30;
        case 45:
            return -5;
        case 46:
            return -3;
        case 47:
            return -10;
        case 48:
            return 1;
        case 49:
            return -1;
        case 50:
            return -4;
        case 51:
            return 3;
        case 52:
            return -5;
        case 53:
            return -10;
        case 54:
            return -10;
        case 55:
            return -3;
        case 56:
            return -1;
        case 57:
            return 1;
        case 58:
            return -3;
        case 59:
            return -1;
        case 60:
            return -1;
        case 61:
            return -10;
        case 62:
            return -5;
        case 63:
            return 2;
        case 64:
            return -2;
        case 65:
            return 5;
        case 66:
            return -3;
        case 67:
            return 1;
        default:
            return -99;
        }
    }

// the mark column: 0 unmarked, 1 the samurai-doubled star, 2 the
// single-creature double star (capture p. 72).
inline int dgvT42Mark(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 2;
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
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        default:
            return -99;
        }
    }

// T42 kensai prose (capture p. 72): duel awards are given only for fighting a
// particular NPC once per level - a second duel has no effect until the
// character advances
inline bool dgvKensaiDuelOncePerLevel()
    { return true; }

// T42 footnote (capture p. 72): the starred awards are doubled for samurai
// characters
inline bool dgvSamuraiDoubleAwards()
    { return true; }

// T42 footnote (capture p. 72): the monsters award applies only to points
// earned for defeating a single creature
inline bool dgvSingleCreatureRead()
    { return true; }

}   // namespace rules
