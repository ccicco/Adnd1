// =========================================================================================
// Adnd1 - rules/pwl.h
// The Dragon issue-7 opener - the Prowler (folio 24): the single
// engine-relevant chain in a thin harvest issue, pinned as a new
// variant-layer registry monster
// census 830 -> 831.
//
// Pinned from The Dragon Vol. I No. 7 (June 1977), the archive.org scan voice
// (single-voice: no chat-side upload cross-check exists for issue 7; the
// issue-7 source lives in the archive.org item accessory-dragon-magazine-012,
// which holds issues 7-14). The folio: 24, the Prowler - 14 hit dice, armor
// class 1, move 12, number appearing 1, Evil and highly intelligent, 50
// percent magic resistant, the constriction at 4-48 hit points per turn and
// the bite at 1-8, the mind-blank gaze with its save vs. magic and zombei
// control, the tentacle egg-injection at 1-8 damage with the 2-8 day hatch
// and the hatched brood's first meal, the exceptional hatcheries in abandoned
// caves or underground, and the three Patriarchs' simultaneous dispel evil
// restoration. The transcripts ride extract/dragon/007/ (all 32 issue pages);
// the issue-7 gap report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at
// the printed 12, 16 and 28 footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// with no 1e def existing the Prowler pins as a NEW registry monster - the
// R900 Creature Features precedent, the Remorhaz lore-against-def shape not
// applying - carrying the dragon_print xp source in its lua. The XP
// conversion rides the DMG p.85 additive formula - 1800 base + 3 specials x
// 950 + 1 exceptional x 1200 at the 13 to 14+ dice category, plus 18 per hit
// point at the 63 average - the special/exceptional count a noted judgment
// (the gaze, the constriction, the magic resistance special; the hatchery
// lifecycle exceptional), never silent. The print's zombei spelling rides AS
// SCANNED; the statblock prints no treasure or size line and those ride 'not
// printed' in the lua, never invented. The Fineous Fingers comic sharing
// folio 24 drops as comic ink per the standing precedent. The editor's
// standing caution rides: none of this is official.
//
namespace rules {

// ---- the Prowler (folio 24) ----

// the Prowler hit dice - 14 (folio 24)
inline int pwlHd()
    { return 14; }

// the Prowler movement - 12 (folio 24)
inline int pwlMove()
    { return 12; }

// the Prowler armor class - 1 (folio 24)
inline int pwlAc()
    { return 1; }

// the Prowler number appearing - 1 (folio 24)
inline int pwlNumAppearing()
    { return 1; }

// the constriction attack damage minimum - 4 hit points per turn (folio 24)
inline int pwlConstrictMin()
    { return 4; }

// the constriction attack damage maximum - 48 hit points per turn (folio 24)
inline int pwlConstrictMax()
    { return 48; }

// the bite damage minimum - 1 (folio 24)
inline int pwlBiteMin()
    { return 1; }

// the bite damage maximum - 8 (folio 24)
inline int pwlBiteMax()
    { return 8; }

// the Prowler magic resistance - 50 percent (folio 24)
inline int pwlMagicResistPct()
    { return 50; }

// the egg-injection damage under the skin minimum - 1, however tenderly done
// (folio 24)
inline int pwlEggDamageMin()
    { return 1; }

// the egg-injection damage under the skin maximum - 8, however tenderly done
// (folio 24)
inline int pwlEggDamageMax()
    { return 8; }

// the zombei wanders aimlessly 2-8 days until the eggs hatch - the minimum
// (folio 24)
inline int pwlHatchDaysMin()
    { return 2; }

// the zombei wanders aimlessly 2-8 days until the eggs hatch - the maximum
// (folio 24)
inline int pwlHatchDaysMax()
    { return 8; }

// three Patriarchs must simultaneously cast dispel evil upon the zombei to
// restore his mind (folio 24)
inline int pwlRestorePatriarchs()
    { return 3; }

// the average hit points - 14 dice at 4.5 per die (folio 24)
inline int pwlAvgHp()
    { return 63; }

// the base XP - the DMG p.85 formula at 14 dice: 1800 base + 3 specials x 950
// + 1 exceptional x 1200; the conversion noted (folio 24)
inline int pwlXp()
    { return 5850; }

// the XP per hit point - the DMG p.85 per-hit-die value at the 13 to 14+
// category (folio 24)
inline int pwlXpPerHp()
    { return 18; }

// the XP value - 5850 + 18 x 63, the DMG p.85 additive formula (folio 24)
inline int pwlXpValue()
    { return 6984; }

// the Prowler alignment - Evil, highly intelligent (folio 24)
inline bool pwlEvil()
    { return true; }

// looking into the Prowler's eyes forces a save vs. magic or the victim is
// irrevocably mind blanked (folio 24)
inline bool pwlGazeSaveVsMagic()
    { return true; }

// the mind-blanked victim becomes a zombei under the control of the Prowler
// (folio 24)
inline bool pwlZombeiUnderControl()
    { return true; }

// those who save against the gaze the Prowler attempts to crush within its
// powerful coils (folio 24)
inline bool pwlConstrictOnSave()
    { return true; }

// the zombeis become the recipient of the monster's eggs, injected under the
// skin with the brown tentacles that line her mouth (folio 24)
inline bool pwlEggsViaTentacles()
    { return true; }

// when the eggs hatch the baby prowlers make the zombei their first meal - he
// lays down calmly as they pick his bones clean (folio 24)
inline bool pwlHatchedFirstMeal()
    { return true; }

// some exceptionally intelligent prowlers form hatcheries - charming large
// numbers as guards and egg hosts in abandoned caves or underground (folio
// 24)
inline bool pwlExceptionalFormHatcheries()
    { return true; }

}   // namespace rules
