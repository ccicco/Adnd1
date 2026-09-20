// ============================================================================
// Adnd1 — rules/character.cpp
// PHB p.9-13 ability tables as constexpr arrays.
// 2012 Premium reprint transcription; cross-checked vs 1979 scan.
// ============================================================================

#include "character.h"

namespace rules {

// ----------------------------------------------------------------------------
// Ability plumbing
// ----------------------------------------------------------------------------

static const char* const kAbilityNames[ABILITY_COUNT] = {
    "STR", "INT", "WIS", "DEX", "CON", "CHA"
};

const char* abilityName(Ability a) {
    return kAbilityNames[(int)a];
}

uint8_t AbilityScores::get(Ability a) const {
    switch (a) {
        case ABILITY_STR: return str;
        case ABILITY_INT: return int_;
        case ABILITY_WIS: return wis;
        case ABILITY_DEX: return dex;
        case ABILITY_CON: return con;
        case ABILITY_CHA: return cha;
        default:          return 10;
    }
}

void AbilityScores::set(Ability a, uint8_t v) {
    switch (a) {
        case ABILITY_STR: str  = v; break;
        case ABILITY_INT: int_ = v; break;
        case ABILITY_WIS: wis  = v; break;
        case ABILITY_DEX: dex  = v; break;
        case ABILITY_CON: con  = v; break;
        case ABILITY_CHA: cha  = v; break;
    }
}

// ----------------------------------------------------------------------------
// Exceptional strength (PHB p.9)
//   Band          Hit adj  Dmg adj  Weight allow  Max press
//   18/01-50      +1       +3       35            90
//   18/51-75      +2       +4       45            130
//   18/76-90      +2       +5       55            160
//   18/91-99      +3       +6       70            200
//   18/00         +3       +6       80            240
// ----------------------------------------------------------------------------

static int exBand(const ExceptionalStrength& ex) {
    if (!ex.has) return -1;
    if (ex.pct <= 50)  return 0;
    if (ex.pct <= 75)  return 1;
    if (ex.pct <= 90)  return 2;
    if (ex.pct <= 99)  return 3;
    return 4;   // 100 = "00"
}

int ExceptionalStrength::hitAdj() const {
    static constexpr int adj[5]  = { 1, 2, 2, 3, 3 };
    int b = exBand(*this);
    return b < 0 ? 0 : adj[b];
}

int ExceptionalStrength::dmgAdj() const {
    static constexpr int adj[5]  = { 3, 4, 5, 6, 6 };
    int b = exBand(*this);
    return b < 0 ? 0 : adj[b];
}

int ExceptionalStrength::weightAllow() const {
    static constexpr int allow[5] = { 35, 45, 55, 70, 80 };
    int b = exBand(*this);
    return b < 0 ? 0 : allow[b];
}

int ExceptionalStrength::press() const {
    static constexpr int press[5] = { 90, 130, 160, 200, 240 };
    int b = exBand(*this);
    return b < 0 ? 0 : press[b];
}

// ----------------------------------------------------------------------------
// STR to-hit / damage (PHB p.9)
//   Score  Hit adj  Dmg adj
//   3       -3       -1
//   4-5     -2       -1
//   6-7     -1       0
//   8-9     0        0
//   10-11   0        0
//   12-13   0        0
//   14-15   0        0
//   16      0        +1
//   17      +1       +1
//   18      +1       +2   (plus exceptional if applicable)
// ----------------------------------------------------------------------------

int strHitAdj(uint8_t str, const ExceptionalStrength& ex) {
    if (str < 3)  return -3;
    if (str <= 5) return -2;
    if (str <= 7) return -1;
    if (str <= 15) return 0;
    if (str == 16) return 0;
    if (str == 17) return 1;
    // 18: +1, +2 from exceptional replaces it (PHB p.9: exceptional
    // bands are absolute, not additive)
    if (str == 18) return ex.has ? ex.hitAdj() : 1;
    if (str == 19) return 1;    // gauntlets/giant str beyond table: 19+ = +1/+3, 20+ = +2/+4 ... (informational)
    if (str == 20) return 2;
    if (str <= 22) return 2;
    if (str <= 24) return 3;
    return 4;   // 25 (storm giant tier)
}

int strDmgAdj(uint8_t str, const ExceptionalStrength& ex) {
    if (str < 3)  return -1;
    if (str <= 5) return -1;
    if (str <= 15) return 0;
    if (str == 16) return 1;
    if (str == 17) return 1;
    if (str == 18) return ex.has ? ex.dmgAdj() : 2;
    if (str == 19) return 3;
    if (str == 20) return 4;
    if (str <= 22) return 5;
    if (str <= 24) return 6;
    return 7;   // 25
}

// ----------------------------------------------------------------------------
// DEX (PHB p.11-12)
//   Score  Reaction adj  Defensive adj
//   3      -2           +4   (worse AC number)
//   4      -1           +3
//   5      -1           +2
//   6      0            +1
//   7      0            0
//   8-14   0            0
//   15     0            -1
//   16     +1           -2
//   17     +2           -3
//   18     +2           -4
// ----------------------------------------------------------------------------

int dexReactionAdj(uint8_t dex) {
    if (dex <= 3)  return -2;
    if (dex <= 5)  return -1;
    if (dex <= 14) return 0;
    if (dex == 15) return 0;
    if (dex == 16) return 1;
    if (dex == 17) return 2;
    return 2;   // 18
}

int dexDefensiveAdj(uint8_t dex) {
    if (dex <= 3)  return 4;    // adds to AC number
    if (dex == 4)  return 3;
    if (dex == 5)  return 2;
    if (dex == 6)  return 1;
    if (dex <= 14) return 0;
    if (dex == 15) return -1;
    if (dex == 16) return -2;
    if (dex == 17) return -3;
    return -4;   // 18
}

// ----------------------------------------------------------------------------
// CON (PHB p.12)
//   Score  HP adj  System shock  Res survival  Poison save adj
//   3      -2      25%           30%           -2
//   4      -1      30%           35%           -1
//   5      -1      35%           40%           -1
//   6-8    0       45-55%        45-55%        0
//   9-12   0       60-75%        60-75%        0
//   13-14  0       80-85%        80-85%        0
//   15     +1      88%           90%           0
//   16     +2      90%           93%           0
//   17     +2      94%           96%           +1
//   18     +2      96%           98%           +2
//   (19+ rows exist for non-player characters; included for monsters)
// ----------------------------------------------------------------------------

static int conIndex(uint8_t con) {
    // maps score to table row: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18
    if (con < 3)  return 0;
    if (con > 18) con = 18;
    return con - 3;
}

int conHPAdj(uint8_t con) {
    static constexpr int adj[16] = {
        -2, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 1,  2,  2,  2
    };
    return adj[conIndex(con)];
}

int conSystemShock(uint8_t con) {
    static constexpr int v[16] = {
        25, 30, 35, 45, 50, 55, 60, 65, 70, 75, 80, 85, 88, 90, 94, 96
    };
    return v[conIndex(con)];
}

int conResSurvival(uint8_t con) {
    static constexpr int v[16] = {
        30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 93, 96, 98
    };
    return v[conIndex(con)];
}

int conPoisonSaveAdj(uint8_t con) {
    static constexpr int v[16] = {
        -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2
    };
    return v[conIndex(con)];
}

// ----------------------------------------------------------------------------
// INT (PHB p.10): number of additional languages beyond native tongue
//   3: none; 4-5: +1; 6-8: +2; 9-12: +3 (bonus language allowed);
//   13-15: +4; 16-17: +5; 18: +6 (literacy per INT table is a display
//   concern, not encoded here)
// ----------------------------------------------------------------------------

int intExtraLanguages(uint8_t int_) {
    if (int_ <= 3)   return 0;
    if (int_ <= 5)   return 1;
    if (int_ <= 8)   return 2;
    if (int_ <= 12)  return 3;
    if (int_ <= 15)  return 4;
    if (int_ <= 17)  return 5;
    return 6;   // 18
}

// ----------------------------------------------------------------------------
// WIS (PHB p.11): magical defense adjustment
//   3: -2; 4-5: -1; 6-8: -1; 9-12: 0; 13-14: 0; 15: +1; 16-17: +2; 18: +2
//   (PHB prints 4-5 and 6-8 both -1)
// ----------------------------------------------------------------------------

int wisMagDefAdj(uint8_t wis) {
    if (wis <= 3)   return -2;
    if (wis <= 8)   return -1;
    if (wis <= 14)  return 0;
    if (wis == 15)  return 1;
    return 2;   // 16-18
}

// ----------------------------------------------------------------------------
// CHA (PHB p.11): reaction adjustment, henchmen count, loyalty base
//   Score  Reaction adj  Max henchmen  Loyalty base
//   3      -4            1             1
//   4      -3            2             2
//   5      -2            2             3
//   6      -1            2             4
//   7      -1            3             4
//   8      -1            3             5
//   9-11   0             4             6
//   12     0             4             7
//   13     +1            5             8
//   14     +1            6             9
//   15     +2            7             10
//   16     +2            8             11
//   17     +3            10            12
//   18     +4            15            15
// ----------------------------------------------------------------------------

int chaReactionAdj(uint8_t cha) {
    if (cha <= 3)   return -4;
    if (cha == 4)   return -3;
    if (cha == 5)   return -2;
    if (cha <= 8)   return -1;
    if (cha <= 12)  return 0;
    if (cha <= 14)  return 1;
    if (cha <= 16)  return 2;
    if (cha == 17)  return 3;
    return 4;   // 18
}

int chaHenchmenMax(uint8_t cha) {
    if (cha <= 3)   return 1;
    if (cha <= 5)   return 2;
    if (cha <= 8)   return 3;
    if (cha <= 12)  return 4;
    if (cha == 13)  return 5;
    if (cha == 14)  return 6;
    if (cha == 15)  return 7;
    if (cha == 16)  return 8;
    if (cha == 17)  return 10;
    return 15;  // 18
}

int chaLoyaltyBase(uint8_t cha) {
    if (cha <= 3)  return 1;
    if (cha == 4)  return 2;
    if (cha == 5)  return 3;
    if (cha <= 7)  return 4;
    if (cha == 8)  return 5;
    if (cha <= 11) return 6;
    if (cha == 12) return 7;
    if (cha == 13) return 8;
    if (cha == 14) return 9;
    if (cha == 15) return 10;
    if (cha == 16) return 11;
    if (cha == 17) return 12;
    return 15;  // 18
}

// ----------------------------------------------------------------------------
// Prime requisite XP adjustment (PHB p.12-13)
// ----------------------------------------------------------------------------

XPPct primeRequisitePct(uint8_t score) {
    if (score >= 16) return XP_PLUS10;
    if (score >= 13) return XP_PLUS5;
    if (score >= 9)  return XP_NONE;
    if (score >= 6)  return XP_MINUS10;
    return XP_MINUS20;
}

// ----------------------------------------------------------------------------
// Generation
// ----------------------------------------------------------------------------

AbilityScores rollAbilities(Dice& dice, GenMethod method) {
    AbilityScores s;
    uint8_t* vals[ABILITY_COUNT] = {
        &s.str, &s.int_, &s.wis, &s.dex, &s.con, &s.cha
    };
    for (int a = 0; a < ABILITY_COUNT; ++a) {
        if (method == GEN_3D6) {
            *vals[a] = (uint8_t)dice.roll(3, 6, 0);
        } else {
            *vals[a] = (uint8_t)dice.bestOf(4, 6, 3);   // 4d6 drop lowest
        }
    }
    return s;
}

} // namespace rules