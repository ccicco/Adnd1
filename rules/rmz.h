// =========================================================================================
// Adnd1 - rules/rmz.h
// The Remorhaz lore pin - the issue-2 opener (folio 21): the original 1976
// Creature Features appearance, pinned as lore against the existing MM1 def
// census 812 -> 813.
//
// Pinned from The Dragon Vol. 1 No. 2 (August 1976): folio 21, Creature
// Features - the Remorhaz, the original appearance ahead of the MM1 def. The
// voice rides extract/dragon/002/ (all 32 issue pages) plus the pre-flip
// tools/dragon_gap_report_002.md (4 boxes, 0 closed), both shipped as spec
// data files. OD&D-era ink converted per the walk doctrine: the pin IS the
// conversion, noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Remorhaz pins are lore/provenance only - the MM1 def
// monsters/monsters/r/remorhaz.lua is untouched and holds the stem, no
// competing def ever. The divergences ride noted, never silent: his bite 3-36
// vs the def's 6-36, his 6/10/14 hit-dice bands on d8 vs the def's 7-14, his
// fire-breathing wings (3/5/7 dice) where the MM1 polar worm beats its wings
// but breathes no fire, his low intelligence vs the def's animal, and his
// 30-foot length vs the def's 21-42.
//
namespace rules {

// ---- the three sizes (folio 21) ----

// the small size - 6 hit dice at 01-40 percent, d8 (folio 21); the def's
// ladder starts at 7 - the divergence noted
inline int rmzHdSmall()
    { return 6; }

// the middle size - 10 hit dice at 41-75 percent (folio 21)
inline int rmzHdMid()
    { return 10; }

// the large size - 14 hit dice at 76-00 percent, d8 (folio 21); the def tops
// at 14 too
inline int rmzHdLarge()
    { return 14; }

// all sizes roll 8-sided hit dice (folio 21)
inline int rmzHdDie()
    { return 8; }

// 01-40 percent - the 6-die encounter chance (folio 21)
inline int rmzSmallPct()
    { return 40; }

// 41-75 percent - the 10-die encounter chance (folio 21)
inline int rmzMidPct()
    { return 35; }

// 76-00 percent - the 14-die encounter chance (folio 21)
inline int rmzLargePct()
    { return 25; }

// ---- the frame (folio 21) ----

// 30 feet long - blue hued underneath, wings and head backed with red (folio
// 21); the def reads 21-42 - the divergence noted
inline int rmzLenFeet()
    { return 30; }

// movement 12 inches (folio 21) - the def agrees
inline int rmzMoveInches()
    { return 12; }

// 20 percent in lair, treasure type F (folio 21) - the def agrees
inline int rmzPctInLair()
    { return 20; }

// 75 percent magic resistance, low intelligence, neutral, 1 appearing (folio
// 21)
inline int rmzMagResPct()
    { return 75; }

// armor class: underside 4 (folio 21) - the def agrees
inline int rmzAcUnderside()
    { return 4; }

// armor class: back 0 plus special - the heated protrusions (folio 21)
inline int rmzAcBack()
    { return 0; }

// armor class: head 2 (folio 21) - the def agrees on all three
inline int rmzAcHead()
    { return 2; }

// the bite, 3-36 points (folio 21) - the def reads 6-36, the divergence
// noted, never silent
inline int rmzBiteMin()
    { return 3; }

// the bite's top end, 36 points (folio 21)
inline int rmzBiteMax()
    { return 36; }

// the fire breath - 3, 5, or 7 dice of fire damage (folio 21); the MM1 polar
// worm breathes no fire
inline int rmzBreathMinDice()
    { return 3; }

// the fire breath's top end - 7 dice (folio 21)
inline int rmzBreathMaxDice()
    { return 7; }

// ---- the lore doctrines (folio 21) ----

// wings and head backed with red, breathing fire - the Dragon doctrine where
// the MM1 polar worm beats small wings but breathes none (folio 21)
inline bool rmzWingsAndBreath()
    { return true; }

// the reddish rock-like back protrusions are heated to enormous temperatures,
// melting any non-magical weapon striking the back (folio 21) - the def
// agrees in its own words
inline bool rmzBackMeltsWeapons()
    { return true; }

// the only fire-using creature that prefers the coldness of mountain areas
// and frozen wastes, stalkable alongside the Silver Dragon on the Eldritch
// Wizardry matrix (folio 21)
inline bool rmzColdDwelling()
    { return true; }

}   // namespace rules
