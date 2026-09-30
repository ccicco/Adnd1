// ============================================================================
// Adnd1 — dm/treasure.h
// R71: Monster Manual Treasure Types (Premium reprint p.105, verified
// cell-by-cell against the printed page) + DMG Random Treasure
// Determination (pp.25-27, 120-125; Curtiss-verified OCR corrections
// applied: Clairaudience, Cloak-of (not Clock), Petrification, Daern's,
// Bucknard's, Robe/Rope split in III.E.5 incl. Rope of Constriction,
// Tuerny, Jacinth, Heward's, twin Hammer +2 rows printed as-is).
//
// Scope: rollTreasureType(letter) reproduces a monster's hoard per the
// MM table — coins (chance-gated ranges), gems and jewelry (DMG base
// value + variation rolls), and the maps-or-magic column (DMG tables
// III / III.A-H, percentile into sub-tables exactly as printed).
//
// Coinage: 1 pp = 10 gp, 1 ep = 1/2 gp, 1 sp = 1/10 gp, 1 cp = 1/100 gp
// (1e PHB exchange table; ep = 50 cp = 5 sp = 1/2 gp confirmed).
//
// Determinism: all randomness flows through the passed rules::Dice.
// ============================================================================

#pragma once

#include "../rules/dice.h"

#include <string>
#include <vector>

namespace dm {
namespace treasure {

// ----------------------------------------------------------------------------
// One rolled magic item (DMG III.A-H rows). xp = the printed experience
// point value (0 = none printed); gp = printed gold piece sale value;
// qty > 1 for bundled finds (arrows, bolts); note carries footnotes,
// scroll contents, or curse flavor.
// ----------------------------------------------------------------------------
struct MagicItem {
    std::string name;
    int  xp  = 0;
    int  gp  = 0;
    int  qty = 1;
    std::string note;

    // R76: which DMG table III category the item rolled from
    // (the roller knows; the app consumes). -1 = unset/legacy.
    int  category = -1;

    // true for the healing draughts (DMG III.A rows 24-26 & 42-47);
    // the party already carries potions as a counted stack
    bool isHealingPotion() const;
    // "+N" out of the printed name (0 = no plus in the name);
    // meaningful for categories 10 (swords) and 11 (weapons)
    int  weaponPlus() const;
};

// R76: magic item categories (DMG table III dispatch order)
enum MagicItemCategory {
    MIC_POTION     = 0,   // III.A potions
    MIC_SCROLL     = 1,   // III.B scrolls
    MIC_RING       = 2,   // III.C rings
    MIC_ROD_STAFF  = 3,   // III.D rods/staves/wands
    MIC_MISC1      = 4,   // III.E.1
    MIC_MISC2      = 5,   // III.E.2
    MIC_MISC3      = 6,   // III.E.3
    MIC_MISC4      = 7,   // III.E.4
    MIC_MISC5      = 8,   // III.E.5
    MIC_ARMOR      = 9,   // III.F armor & shields
    MIC_SWORD      = 10,  // III.G swords
    MIC_WEAPON     = 11,  // III.H misc weapons
    MIC_UNSET      = -1
};

// ----------------------------------------------------------------------------
// A rolled hoard: raw coin denominations, gems and jewelry carried as
// count + appraised value (values rolled per DMG pp.25-27), magic items
// by name, and flavor notes (maps, curses).
// ----------------------------------------------------------------------------
struct Hoard {
    long long cp = 0, sp = 0, ep = 0, gp = 0, pp = 0;
    int  gemCount = 0;
    long long gemValue = 0;
    int  jewelryCount = 0;
    long long jewelryValue = 0;
    std::vector<MagicItem> magic;
    std::vector<std::string> notes;

    bool empty() const {
        return cp == 0 && sp == 0 && ep == 0 && gp == 0 && pp == 0 &&
               gemCount == 0 && jewelryCount == 0 && magic.empty() &&
               notes.empty();
    }

    // Total value in gold pieces at the 1e exchange rates, including
    // gem/jewelry appraisals and magic items at their printed sale
    // value (the engine carries no item inventory; the take is
    // appraised and carried — simplification recorded in R71 notes).
    long long goldValue() const {
        long long v = cp / 100 + sp / 10 + ep * 5 / 10 + gp + pp * 10;
        v += gemValue + jewelryValue;
        for (const auto& m : magic) v += (long long)m.gp * m.qty;
        return v;
    }

    void absorb(const Hoard& o) {
        cp += o.cp; sp += o.sp; ep += o.ep; gp += o.gp; pp += o.pp;
        gemCount += o.gemCount;     gemValue += o.gemValue;
        jewelryCount += o.jewelryCount; jewelryValue += o.jewelryValue;
        magic.insert(magic.end(), o.magic.begin(), o.magic.end());
        notes.insert(notes.end(), o.notes.begin(), o.notes.end());
    }
};

// ----------------------------------------------------------------------------
// Roll one MM Treasure Type letter (A-Z) once, per the verified p.105
// table. magicOnly selects only the maps-or-magic column — the MM's
// "G (magic)" / "C (magic only)" annotations (e.g. lizard man entries).
//
// For J-N (the "pieces per individual" rows), nCreatures multiplies the
// per-creature coin roll: rollTreasureType(dice, 'M', 10) = the gold
// carried by 10 ogres (2-8 gp each). For all other letters nCreatures
// is ignored.
// ----------------------------------------------------------------------------
Hoard rollTreasureType(rules::Dice& dice, char letter,
                       int nCreatures = 1, bool magicOnly = false);

// ----------------------------------------------------------------------------
// Gem and jewelry appraisals (DMG pp.25-27) — exposed for tests.
// Each gem: percentile base value, then the printed d10 variation roll
// (rerolling 1/0 per the book's rules, bounded by the +/- step caps).
// Each piece of jewelry: percentile class + uniform value in class,
// d10 workmanship (each 1 promotes), then the gem-setting d8/d6 chain
// for gem-set pieces (+5,000 gp doubling to the 640,000 gp maximum).
// ----------------------------------------------------------------------------
long long rollGemValue(rules::Dice& dice);
long long rollJewelryValue(rules::Dice& dice);

// One item from the DMG Magic Items table (III) — percentile through
// the sub-tables; potion/scroll/ring/rod/misc/armor/sword/weapon rows
// resolved to name, xp, and gp sale value.
MagicItem rollMagicItem(rules::Dice& dice);

} // namespace treasure
} // namespace dm
