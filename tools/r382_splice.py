
# R382: the UA misc magic prose
# part 2 pin round (the D-E
# stretch): EIGHT items pin -
# ONE fully clean (the dust of
# tracelessness) plus SEVEN
# mechanics-clean with flagged
# holes (the deck of illusions'
# card list, the dicerion's
# description seam, the dust of
# dryness' elemental-save cell,
# the dust of illusion's intro,
# the egg of desire's int seam,
# the egg of reason's 18+
# increment cell, the egg of
# shattering's attack seam);
# NOTHING in D-E fully garbles
# - the gap item AMENDED with
# the part-2 note, stays OPEN
# for F-Z, PDF-gated; the R381
# seam the part-1 ledger, the
# R375 seam the misc band; the
# census 308 -> 309.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)



# ---- (a) the seed: the R381 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R381 landed 2026-10-12: commit',
    '  1ae8f21, census 308, the UA',
    '  misc magic prose part 1 pin',
    '  round (rules/uamiscprose1.h):',
    '  thirteen A-C items pin -',
    '  eight fully clean (beads of',
    '  force, boots of the north,',
    '  boots winged, bracers of',
    '  archery, bracers of',
    '  brachiation, cloak of',
    '  arachnidia, cloak of the',
    '  bat, cyclocone) plus five',
    '  mechanics-clean with flagged',
    '  holes (the amulet versus',
    '  undead, the anything item,',
    '  the boccob book, the boots',
    '  of varied tracks, the chime',
    '  of interruption); nothing',
    '  in A-C fully garbles - the',
    '  item AMENDED, stays OPEN',
    '  for D-Z, PDF-gated; the',
    '  R380 seam the wands ledger,',
    '  the R375 seam the misc',
    '  band; GREEN on the first',
    '  run.'
])
s = rd(SD)
if 'R381 landed 2026-10-12' in s:
    already.append('seed: the R381 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R381 record')
s = rd(SD)
assert s.count(
    'R381 landed 2026-10-12'
) == 1, 'a entry'
assert s.count(
    'R380 landed 2026-10-12'
) == 1, 'a entry'
assert s.count(
    'R379 landed 2026-10-12'
) == 1, 'a R379 kept'
assert s.count(
    'R378 landed 2026-10-12'
) == 1, 'a R378 kept'
assert s.count(
    'R377 landed 2026-10-12'
) == 1, 'a R377 kept'
assert s.count(
    'R376 landed 2026-10-12'
) == 1, 'a R376 kept'
assert s.count(
    'R375 landed 2026-10-12'
) == 1, 'a R375 kept'
assert s.count(
    'R374 landed 2026-10-12'
) == 1, 'a R374 kept'
assert s.count(
    'R373 landed 2026-10-12'
) == 1, 'a R373 kept'
assert s.count(
    'R372 landed 2026-10-12'
) == 1, 'a R372 kept'
assert s.count(
    'R371 landed 2026-10-12'
) == 1, 'a R371 kept'
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a R370 kept'
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a R369 kept'
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a R368 kept'
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a R367 kept'
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a R364 kept'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'



# ---- (b) NEW rules/uamiscprose2.h ----
P = 'rules/uamiscprose2.h'
if os.path.exists(P) and 'R382' in rd(P):
    already.append('uamiscprose2.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamiscprose2.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 2, R382: the
// D-E stretch - eight pins,
// one fully clean (the dust
// of tracelessness) plus
// seven mechanics-clean with
// flagged holes (the deck of
// illusions' card list, the
// dicerion's description
// seam, the dust of dryness'
// elemental-save cell, the
// dust of illusion's intro,
// the egg of desire's int
// seam, the egg of reason's
// 18+ increment cell, the
// egg of shattering's attack
// seam). Nothing in D-E
// fully garbles; F-Z rides
// the later parts. The
// part-1 and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the deck of illusions
// ----
// A set of parchment cards in
// an ivory, leather, or wood
// box; a full deck holds 34
// plaques. A drawn card cast
// out forms an illusion with
// audial and visual
// components that lasts until
// it is dispelled.
inline int uamm2DekCardCount()
    { return 34; }

inline bool uamm2DekAudialVisual()
    { return true; }

inline bool uamm2DekLastsUntilDispelled()
    { return true; }

// The illusory creature will
// not go more than 30 feet
// from where the card lands.
inline int uamm2DekLeashFt()
    { return 30; }

// When the illusion is
// dispelled, the card blanks
// and cannot be used again;
// picking the card up
// dispels the illusion
// instantly.
inline bool uamm2DekCardBlanksAfterUse()
    { return true; }

inline bool uamm2DekPickupDispelsInstantly()
    { return true; }

// Two jokers, showing the
// deck's owner. The card
// list OCR-garbles (stray
// rows, "bgoblin", "rc");
// the deck mechanics read;
// flagged.
inline int uamm2DekJokers()
    { return 2; }

inline bool uamm2DekCardListGarbles()
    { return true; }

// ---- the dicerion of light
// and darkness ----
// A clerical candlestick with
// two branches - silver and
// mithral bright, iron and
// adamantite dark; the
// branch-band description
// OCR-scrambles, the
// mechanics read; flagged.
inline bool uamm2DicTwoBranches()
    { return true; }

// About 1 foot tall, a
// weight of 30-40 gold
// pieces.
inline int uamm2DicHeightIn()
    { return 1; }

inline int uamm2DicWeightGpLo()
    { return 30; }

inline int uamm2DicWeightGpHi()
    { return 40; }

// Must have specially
// manufactured candles -
// purest wax with powdered
// obsidian and crystal,
// blessed and consecrated
// (the ceremony spell).
inline bool uamm2DicNeedsSpecialCandles()
    { return true; }

inline bool uamm2DicCandlesBlessedConsecrated()
    { return true; }

// Both candles alight: the
// cleric sees into any
// darkness or the brightest
// light as if it were normal
// daylight.
inline bool uamm2DicBothAlightSeeAll()
    { return true; }

// On command the candles emit
// a metallic illumination
// that dispels natural
// shadows (not the undead
// creature) within a
// 30-foot radius; while so
// employed the dark/light
// vision boon ends.
inline int uamm2DicShadowDispelRadiusFt()
    { return 30; }

inline bool uamm2DicDispelNaturalShadowsOnly()
    { return true; }

inline bool uamm2DicDispelEndsVisionBoon()
    { return true; }

// A candle burns 5-8 turns
// in a gentle draft; a
// strong draft cuts 1-2
// turns; still air lasts
// 9-16 turns.
inline int uamm2DicBurnGentleLo()
    { return 5; }

inline int uamm2DicBurnGentleHi()
    { return 8; }

inline int uamm2DicBurnStrongCutLo()
    { return 1; }

inline int uamm2DicBurnStrongCutHi()
    { return 2; }

inline int uamm2DicBurnStillLo()
    { return 9; }

inline int uamm2DicBurnStillHi()
    { return 16; }

// Only the black-arm candle
// alight: a 15-foot darkness
// sphere englobes the cleric
// without hampering him or
// her; a bright light
// striking the eyes then
// blinds 1-4 rounds.
inline int uamm2DicDarkSphereFt()
    { return 15; }

inline bool uamm2DicDarkSphereWearerFree()
    { return true; }

inline int uamm2DicBrightLightBlindLo()
    { return 1; }

inline int uamm2DicBrightLightBlindHi()
    { return 4; }

// Only the bright-branch
// candle alight: a brilliant
// sphere surrounds the
// cleric, whose vision stays
// unimpaired while the
// dicerion is touched or
// held; darkness (evil)
// creatures blind 2-8
// rounds, light (good)
// creatures blind 1-4
// rounds on looking.
inline bool uamm2DicLightSphereWearerOk()
    { return true; }

inline int uamm2DicEvilBlindLo()
    { return 2; }

inline int uamm2DicEvilBlindHi()
    { return 8; }

inline int uamm2DicGoodBlindLo()
    { return 1; }

inline int uamm2DicGoodBlindHi()
    { return 4; }

// Magical darkness while the
// bright power works blinds
// the cleric 1-4 rounds;
// even with one candle
// burning, both branches
// must hold tapers.
inline int uamm2DicMagDarkBlindLo()
    { return 1; }

inline int uamm2DicMagDarkBlindHi()
    { return 4; }

inline bool uamm2DicBothBranchesNeedTapers()
    { return true; }

inline bool uamm2DicDescSeamGarbles()
    { return true; }

// ---- the dust of dryness
// ----
// A pinch cast into water
// negates 1 cubic yard of
// liquid and becomes a
// marble-sized pellet;
// hurled down, the pellet
// breaks and releases the
// same volume of water.
inline int uamm2DdrCuYardsPerPinch()
    { return 1; }

inline bool uamm2DdrPelletReleasesSame()
    { return true; }

// Sprinkled over an area it
// negates a precipitation or
// cloudburst spell, or dries
// up 1 cubic rod of water.
inline bool uamm2DdrSprinkleNegatesPrecip()
    { return true; }

inline int uamm2DdrSprinkleCuRods()
    { return 1; }

// It affects only water
// forms (fresh, salt,
// brackish, alkaline).
inline bool uamm2DdrWaterFormsOnly()
    { return true; }

// Against a water elemental
// or similar creature the
// creature must save versus
// spell - that sentence
// OCR-scrambles ("save spell
// or b"), the rest reads; a
// save still inflicts 6-30
// points of damage; flagged.
inline bool uamm2DdrElementalSaveVsSpell()
    { return true; }

inline int uamm2DdrElementalDmgLo()
    { return 6; }

inline int uamm2DdrElementalDmgHi()
    { return 30; }

inline bool uamm2DdrElementalSeamGarbles()
    { return true; }

// A pouch holds 11-20
// pinches and works while at
// least half the original
// amount remains.
inline int uamm2DdrPouchLo()
    { return 11; }

inline int uamm2DdrPouchHi()
    { return 20; }

inline bool uamm2DdrWorksWhileHalfRemains()
    { return true; }

// ---- the dust of illusion
// ----
// The intro sentences
// OCR-scramble; the
// mechanics read. A pinch
// lets the dusted creature
// appear as any
// similar-shape creature
// with a size variance of
// plus or minus 50%;
// flagged.
inline bool uamm2DilSimilarShapeOnly()
    { return true; }

inline int uamm2DilSizeVariancePct()
    { return 50; }

inline bool uamm2DilIntroGarbles()
    { return true; }

// An unwilling recipient is
// allowed a saving throw to
// escape the effect; the
// sprinkler must envision
// the illusion as the powder
// is shaken.
inline bool uamm2DilUnwillingSaveEscapes()
    { return true; }

inline bool uamm2DilSprinklerEnvisions()
    { return true; }

// The illusionary power
// lasts 7-12 hours unless
// dispelled; a pouch holds
// 11-20 pinches.
inline int uamm2DilDurationLo()
    { return 7; }

inline int uamm2DilDurationHi()
    { return 12; }

inline int uamm2DilPouchLo()
    { return 11; }

inline int uamm2DilPouchHi()
    { return 20; }

// ---- the dust of
// tracelessness ----
// A pinch tossed into the
// air makes a chamber of up
// to 1,000 square feet look
// dustily abandoned for a
// decade; along a trail it
// obliterates the passage of
// as many as a dozen men and
// horses for a mile back.
inline int uamm2DtrChamberSqFt()
    { return 1000; }

inline bool uamm2DtrDecadeLook()
    { return true; }

inline int uamm2DtrTrailMenHorses()
    { return 12; }

inline int uamm2DtrTrailMiles()
    { return 1; }

// No magical radiation
// occurs; a finely sewn
// pouch holds 13-24 pinches.
// Fully clean in the
// extract.
inline bool uamm2DtrNoRadiation()
    { return true; }

inline int uamm2DtrPouchLo()
    { return 13; }

inline int uamm2DtrPouchHi()
    { return 24; }

// ---- the egg of desire
// ----
// At least five sorts of
// small ovoid; placed on its
// large end and touched
// right it rocks and chimes;
// viewers within 20 feet
// save versus spell.
inline int uamm2EgdSortCount()
    { return 5; }

inline bool uamm2EgdRocksAndChimes()
    { return true; }

inline bool uamm2EgdViewerSaveVsSpell()
    { return true; }

inline int uamm2EgdViewingRangeFt()
    { return 20; }

// Black holds permanently;
// Bone takes the most prized
// magic item; Crystal all
// gems; Golden all precious
// metals - each then leave
// and forget; Scarlet holds
// one minute, then rage at
// the first living thing
// seen.
inline bool uamm2EgdBlackHoldsPermanent()
    { return true; }

inline bool uamm2EgdBonePrizedMagicItem()
    { return true; }

inline bool uamm2EgdCrystalAllGems()
    { return true; }

inline bool uamm2EgdGoldenAllMetals()
    { return true; }

inline int uamm2EgdScarletHoldMinutes()
    { return 1; }

inline bool uamm2EgdScarletRageAttacksFirst()
    { return true; }

// Removal only by a magic
// (the seam prints "a magic
// or remove curse spell")
// remove curse; the
// low-intelligence seam
// OCR-scrambles ("y an
// egg"), the table reads;
// flagged.
inline bool uamm2EgdRemovalRemoveCurse()
    { return true; }

inline bool uamm2EgdLowIntGrabsDropped()
    { return true; }

inline bool uamm2EgdIntSeamGarbles()
    { return true; }

// XP and gp sale values by
// sort: Black 500 and 5,000,
// Bone 900 and 10,000,
// Crystal 800 and 9,000,
// Golden 600 and 4,000,
// Scarlet 700 and 3,500.
inline int uamm2EgdXpForSort(int i) {
    static const int k[5] = {
        500, 900, 800, 600, 700};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uamm2EgdGpForSort(int i) {
    static const int k[5] = {
        5000, 10000, 9000, 4000,
        3500};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// ---- the egg of reason
// ----
// Always coated with oil of
// timelessness; the eater
// first saves versus poison
// with no bonuses or dies,
// and the poison cannot be
// neutralized.
inline bool uamm2EgrCoatedOilTimelessness()
    { return true; }

inline bool uamm2EgrSaveVsPoisonNoBonus()
    { return true; }

inline bool uamm2EgrPoisonNotNeutralizable()
    { return true; }

// If it does not slay: one
// point of intelligence (60%)
// or wisdom (40%); the
// success chance is 100 minus
// twice the current score.
inline int uamm2EgrIntChancePct()
    { return 60; }

inline int uamm2EgrWisChancePct()
    { return 40; }

inline int uamm2EgrGainPoints()
    { return 1; }

inline int uamm2EgrSuccessChanceForScore(
        int sc) {
    if (sc < 3) sc = 3;
    if (sc > 18) sc = 18;
    return 100 - 2 * sc;
}

// The 18-or-higher increment
// cell OCR-garbles (""so
// point at a time ... 10
// eggs") - flagged; racial
// limitations apply.
inline bool uamm2EgrHighScoreCellGarbles()
    { return true; }

inline bool uamm2EgrRacialLimitsApply()
    { return true; }

// If the oil is removed, the
// egg still may poison but
// has lost the
// ability-enhancing
// property.
inline bool uamm2EgrOilRemovedStillPoison()
    { return true; }

inline bool uamm2EgrOilRemovedNoEnhance()
    { return true; }

// ---- the egg of shattering
// ----
// Shatters with a loud noise
// when handled normally or
// touched by a detection
// spell, sending fragments
// within a 1-inch radius (as
// printed); the attack
// sentence OCR-scrambles but
// reconstructs; flagged.
inline bool uamm2EgsShattersOnHandleOrDetect()
    { return true; }

inline int uamm2EgsFragRadiusIn()
    { return 1; }

inline bool uamm2EgsAttackSeamGarbles()
    { return true; }

// Creatures in the area are
// attacked using actual armor
// class only, no dexterity
// bonuses; each hit by 1-4
// fragments takes 2-7 points
// per fragment.
inline bool uamm2EgsActualAcOnly()
    { return true; }

inline bool uamm2EgsNoDexBonus()
    { return true; }

inline int uamm2EgsFragHitsLo()
    { return 1; }

inline int uamm2EgsFragHitsHi()
    { return 4; }

inline int uamm2EgsFragDmgLo()
    { return 2; }

inline int uamm2EgsFragDmgHi()
    { return 7; }

// Fragile objects within 1
// foot break automatically;
// within 2 feet they save
// versus crushing blow.
inline int uamm2EgsFragileAutoFt()
    { return 1; }

inline int uamm2EgsFragileSaveFt()
    { return 2; }

inline bool uamm2EgsSaveVsCrushingBlow()
    { return true; }

// ---- the part ledger ----
// Eight D-E items: one fully
// clean, seven flagged, none
// fully garbled.
inline int uamm2PartItemTotal()
    { return 8; }

inline int uamm2PartCleanCount()
    { return 1; }

inline int uamm2PartFlaggedCount()
    { return 7; }

inline int uamm2PartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose2.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 107, 'b inline count'
assert s.count('R382') == 1, 'b round tag'
assert s.count(
    'uamm2DekCardCount'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uaarm' not in s, 'b no uaarm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'uatd' not in s, 'b no uatd ref'
assert 'uads' not in s, 'b no uads ref'
assert 'uapp' not in s, 'b no uapp ref'
assert 'uaps' not in s, 'b no uaps ref'
assert 'uarp' not in s, 'b no uarp ref'
assert 'uaro' not in s, 'b no uaro ref'
assert 'uawd' not in s, 'b no uawd ref'
assert 'uam2' not in s, 'b no uam2 ref'
assert s.count('uamm') == s.count(
    'uamm2'), 'b no R381 uamm ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R382' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new miscellaneous magic',
        '      items** (pp. 97-104) - the named',
        '      additions: the Egg of Reason, the',
        '      Girdle of Many Pouches, the',
        '      Gloves of Missile Snaring, the',
        '      Hat of Difference, the Heward',
        '      haversack, the Horn of Fog, the',
        '      Prison of Zagyg, the Quiver of',
        '      Ehlonna, the Robe of Stars, the',
        '      Scarab versus Golems, the Shadow',
        '      Lanthorn, the Sheet of Smallness.',
        '      - AMENDED R381: the misc magic',
        '        prose part 1 pin round',
        '        (rules/uamiscprose1.h) - the',
        '        A-C stretch, THIRTEEN items',
        '        pin: EIGHT fully clean (the',
        '        beads of force, the boots of',
        '        the north, the boots winged,',
        '        the bracers of archery, the',
        '        bracers of brachiation, the',
        '        cloak of arachnidia, the',
        '        cloak of the bat, the',
        '        cyclocone) plus FIVE',
        '        mechanics-clean with flagged',
        '        holes (the amulet versus',
        "        undead's 9th-level cell, the",
        "        anything item's tail, the",
        "        boccob book's save cell and",
        '        scribing tail, the boots of',
        "        varied tracks' row-one",
        '        print, the chime of',
        "        interruption's opening);",
        '        NOTHING in A-C fully garbles',
        '        - the item stays OPEN for',
        '        D-Z and the PDF.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = NL.join([
        '- [ ] **The new miscellaneous magic',
        '      items** (pp. 97-104) - the named',
        '      additions: the Egg of Reason, the',
        '      Girdle of Many Pouches, the',
        '      Gloves of Missile Snaring, the',
        '      Hat of Difference, the Heward',
        '      haversack, the Horn of Fog, the',
        '      Prison of Zagyg, the Quiver of',
        '      Ehlonna, the Robe of Stars, the',
        '      Scarab versus Golems, the Shadow',
        '      Lanthorn, the Sheet of Smallness.',
        '      - AMENDED R381: the misc magic',
        '        prose part 1 pin round',
        '        (rules/uamiscprose1.h) - the',
        '        A-C stretch, THIRTEEN items',
        '        pin: EIGHT fully clean (the',
        '        beads of force, the boots of',
        '        the north, the boots winged,',
        '        the bracers of archery, the',
        '        bracers of brachiation, the',
        '        cloak of arachnidia, the',
        '        cloak of the bat, the',
        '        cyclocone) plus FIVE',
        '        mechanics-clean with flagged',
        '        holes (the amulet versus',
        "        undead's 9th-level cell, the",
        "        anything item's tail, the",
        "        boccob book's save cell and",
        '        scribing tail, the boots of',
        "        varied tracks' row-one",
        '        print, the chime of',
        "        interruption's opening);",
        '        NOTHING in A-C fully garbles',
        '        - the item stays OPEN for',
        '        D-Z and the PDF.',
        '      - AMENDED R382: the misc magic',
        '        prose part 2 pin round',
        '        (rules/uamiscprose2.h) - the',
        '        D-E stretch, EIGHT items pin:',
        '        ONE fully clean (the dust of',
        '        tracelessness) plus SEVEN',
        '        mechanics-clean with flagged',
        "        holes (the deck of illusions'",
        "        card list, the dicerion's",
        '        description seam, the dust of',
        "        dryness' elemental-save cell,",
        "        the dust of illusion's intro,",
        "        the egg of desire's int seam,",
        "        the egg of reason's 18+ cell,",
        "        the egg of shattering's attack",
        '        seam); NOTHING in D-E fully',
        '        garbles - the item stays OPEN',
        '        for F-Z and the PDF.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)

# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R382'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R381'
) == 1, 'c r381 amendment kept'
assert s.count(
    'AMENDED R380'
) == 1, 'c r380 amendment kept'
assert s.count(
    'AMENDED R379'
) == 1, 'c r379 amendment kept'
assert s.count(
    'AMENDED R378'
) == 1, 'c r378 amendment kept'
assert s.count(
    'AMENDED R377'
) == 1, 'c r377 amendment kept'
assert s.count(
    'AMENDED R376'
) == 1, 'c r376 amendment kept'
assert s.count(
    'AMENDED R375'
) == 1, 'c r375 amendment kept'
assert s.count(
    '(rules/uamiscprose2.h)'
) == 1, 'c misc2 note'
assert s.count(
    '(rules/uamiscprose1.h)'
) == 1, 'c misc note kept'
assert s.count(
    '(rules/uawandprose.h)'
) == 1, 'c wands note kept'
assert s.count(
    '(rules/uarodstave.h)'
) == 1, 'c rods note kept'
assert s.count(
    '(rules/uaringprose.h)'
) == 1, 'c rings note kept'
assert s.count(
    '(rules/uaprotscr.h)'
) == 1, 'c scrolls note kept'
assert s.count(
    '(rules/uapotprose.h)'
) == 1, 'c potions note kept'
assert s.count(
    '(rules/uadetskel.h)'
) == 1, 'c skeleton note kept'
assert s.count(
    'DECIDED R374'
) == 1, 'c r374 decision kept'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c det tables kept open'
assert s.count(
    '- [ ] **The new potions**'
) == 1, 'c potions kept open'
assert s.count(
    '- [ ] **The new scrolls**'
) == 1, 'c scrolls kept open'
assert s.count(
    '- [ ] **The new rings**'
) == 1, 'c rings kept open'
assert s.count(
    '- [ ] **The new rods and staves**'
) == 1, 'c rods staves kept open'
assert s.count(
    '- [ ] **The new wands**'
) == 1, 'c wands kept open'
assert s.count(
    '- [ ] **The new armor and shields and'
) == 1, 'c armor shields kept open'
assert s.count(
    '- [ ] **The new miscellaneous weapons**'
) == 1, 'c misc weapons kept open'
assert s.count(
    '- [x] **The comeliness creation note**'
) == 1, 'c r373 note kept closed'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c r372 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert len(applied) + len(already) == 3, 'c count'



# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R382 UA misc magic prose part 2 pin audit' in s:
    already.append('regtest.cpp: the R382 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose1.h"  // '
        'R381: the UA misc magic prose 1')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose2.h"  // R382: the UA misc magic prose 2'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R382: the UA misc magic
    // prose part 2 pin audit ----
    // The D-E stretch: eight pins -
    // one fully clean (the dust of
    // tracelessness) plus seven
    // mechanics-clean with flagged
    // holes (the deck of illusions'
    // card list, the dicerion's
    // description seam, the dust of
    // dryness' elemental-save cell,
    // the dust of illusion's intro,
    // the egg of desire's int seam,
    // the egg of reason's 18+ cell,
    // the egg of shattering's attack
    // seam); the R381 seam the
    // part-1 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the deck of illusions ----
            if (uamm2DekCardCount() != 34) ++bad;
            if (!uamm2DekAudialVisual()) ++bad;
            if (!uamm2DekLastsUntilDispelled())
                ++bad;
            if (uamm2DekLeashFt() != 30) ++bad;
            if (!uamm2DekCardBlanksAfterUse())
                ++bad;
            if (!uamm2DekPickupDispelsInstantly())
                ++bad;
            if (uamm2DekJokers() != 2) ++bad;
            if (!uamm2DekCardListGarbles())
                ++bad;
        // ---- the dicerion ----
            if (!uamm2DicTwoBranches()) ++bad;
            if (uamm2DicHeightIn() != 1) ++bad;
            if (uamm2DicWeightGpLo() != 30
                    || uamm2DicWeightGpHi()
                    != 40) ++bad;
            if (!uamm2DicNeedsSpecialCandles())
                ++bad;
            if (!uamm2DicCandlesBlessedConsecrated())
                ++bad;
            if (!uamm2DicBothAlightSeeAll())
                ++bad;
            if (uamm2DicShadowDispelRadiusFt()
                    != 30) ++bad;
            if (!uamm2DicDispelNaturalShadowsOnly())
                ++bad;
            if (!uamm2DicDispelEndsVisionBoon())
                ++bad;
            if (uamm2DicBurnGentleLo() != 5
                    || uamm2DicBurnGentleHi()
                    != 8) ++bad;
            if (uamm2DicBurnStrongCutLo() != 1
                    || uamm2DicBurnStrongCutHi()
                    != 2) ++bad;
            if (uamm2DicBurnStillLo() != 9
                    || uamm2DicBurnStillHi()
                    != 16) ++bad;
            if (uamm2DicDarkSphereFt() != 15)
                ++bad;
            if (!uamm2DicDarkSphereWearerFree())
                ++bad;
            if (uamm2DicBrightLightBlindLo() != 1
                    || uamm2DicBrightLightBlindHi()
                    != 4) ++bad;
            if (!uamm2DicLightSphereWearerOk())
                ++bad;
            if (uamm2DicEvilBlindLo() != 2
                    || uamm2DicEvilBlindHi()
                    != 8) ++bad;
            if (uamm2DicGoodBlindLo() != 1
                    || uamm2DicGoodBlindHi()
                    != 4) ++bad;
            if (uamm2DicMagDarkBlindLo() != 1
                    || uamm2DicMagDarkBlindHi()
                    != 4) ++bad;
            if (!uamm2DicBothBranchesNeedTapers())
                ++bad;
            if (!uamm2DicDescSeamGarbles())
                ++bad;
            // the still-air burn is
            // twice the gentle-draft
            // burn; the dark sphere
            // halves the shadow
            // dispel radius
            if (2 * uamm2DicBurnGentleHi()
                    != uamm2DicBurnStillHi()) ++bad;
            if (uamm2DicDarkSphereFt() * 2
                    != uamm2DicShadowDispelRadiusFt())
                ++bad;
        // ---- the dust of dryness ----
            if (uamm2DdrCuYardsPerPinch() != 1)
                ++bad;
            if (!uamm2DdrPelletReleasesSame())
                ++bad;
            if (!uamm2DdrSprinkleNegatesPrecip())
                ++bad;
            if (uamm2DdrSprinkleCuRods() != 1)
                ++bad;
            if (!uamm2DdrWaterFormsOnly()) ++bad;
            if (!uamm2DdrElementalSaveVsSpell())
                ++bad;
            if (uamm2DdrElementalDmgLo() != 6
                    || uamm2DdrElementalDmgHi()
                    != 30) ++bad;
            if (!uamm2DdrElementalSeamGarbles())
                ++bad;
            if (uamm2DdrPouchLo() != 11
                    || uamm2DdrPouchHi() != 20)
                ++bad;
            if (!uamm2DdrWorksWhileHalfRemains())
                ++bad;
            // the elemental damage
            // ceiling is five times
            // its floor
            if (5 * uamm2DdrElementalDmgLo()
                    != uamm2DdrElementalDmgHi())
                ++bad;
        // ---- the dust of illusion ----
            if (!uamm2DilSimilarShapeOnly())
                ++bad;
            if (uamm2DilSizeVariancePct() != 50)
                ++bad;
            if (!uamm2DilUnwillingSaveEscapes())
                ++bad;
            if (!uamm2DilSprinklerEnvisions())
                ++bad;
            if (uamm2DilDurationLo() != 7
                    || uamm2DilDurationHi() != 12)
                ++bad;
            if (uamm2DilPouchLo() != 11
                    || uamm2DilPouchHi() != 20)
                ++bad;
            if (!uamm2DilIntroGarbles()) ++bad;
        // ---- the dust of
        // tracelessness ----
            if (uamm2DtrChamberSqFt() != 1000)
                ++bad;
            if (!uamm2DtrDecadeLook()) ++bad;
            if (uamm2DtrTrailMenHorses() != 12)
                ++bad;
            if (uamm2DtrTrailMiles() != 1) ++bad;
            if (!uamm2DtrNoRadiation()) ++bad;
            if (uamm2DtrPouchLo() != 13
                    || uamm2DtrPouchHi() != 24)
                ++bad;
        // ---- the egg of desire ----
            if (uamm2EgdSortCount() != 5) ++bad;
            if (!uamm2EgdRocksAndChimes()) ++bad;
            if (!uamm2EgdViewerSaveVsSpell())
                ++bad;
            if (uamm2EgdViewingRangeFt() != 20)
                ++bad;
            if (!uamm2EgdBlackHoldsPermanent())
                ++bad;
            if (!uamm2EgdBonePrizedMagicItem())
                ++bad;
            if (!uamm2EgdCrystalAllGems()) ++bad;
            if (!uamm2EgdGoldenAllMetals()) ++bad;
            if (uamm2EgdScarletHoldMinutes()
                    != 1) ++bad;
            if (!uamm2EgdScarletRageAttacksFirst())
                ++bad;
            if (!uamm2EgdRemovalRemoveCurse()) ++bad;
            if (!uamm2EgdLowIntGrabsDropped())
                ++bad;
            if (uamm2EgdXpForSort(0) != 500
                    || uamm2EgdXpForSort(1) != 900
                    || uamm2EgdXpForSort(2) != 800
                    || uamm2EgdXpForSort(3) != 600
                    || uamm2EgdXpForSort(4) != 700)
                ++bad;
            if (uamm2EgdGpForSort(0) != 5000
                    || uamm2EgdGpForSort(1) != 10000
                    || uamm2EgdGpForSort(2) != 9000
                    || uamm2EgdGpForSort(3) != 4000
                    || uamm2EgdGpForSort(4) != 3500)
                ++bad;
            if (!uamm2EgdIntSeamGarbles()) ++bad;
            // the bounds clamp holds;
            // the five XP values sum
            // to 3500
            if (uamm2EgdXpForSort(-3)
                    != uamm2EgdXpForSort(0)
                    || uamm2EgdGpForSort(9)
                    != uamm2EgdGpForSort(4)) ++bad;
            if (uamm2EgdXpForSort(0)
                    + uamm2EgdXpForSort(1)
                    + uamm2EgdXpForSort(2)
                    + uamm2EgdXpForSort(3)
                    + uamm2EgdXpForSort(4)
                    != 3500) ++bad;
        // ---- the egg of reason ----
            if (!uamm2EgrCoatedOilTimelessness())
                ++bad;
            if (!uamm2EgrSaveVsPoisonNoBonus())
                ++bad;
            if (!uamm2EgrPoisonNotNeutralizable())
                ++bad;
            if (uamm2EgrIntChancePct() != 60
                    || uamm2EgrWisChancePct()
                    != 40) ++bad;
            if (uamm2EgrGainPoints() != 1) ++bad;
            if (uamm2EgrSuccessChanceForScore(17)
                    != 66) ++bad;
            if (uamm2EgrSuccessChanceForScore(15)
                    != 70) ++bad;
            if (!uamm2EgrHighScoreCellGarbles())
                ++bad;
            if (!uamm2EgrRacialLimitsApply())
                ++bad;
            if (!uamm2EgrOilRemovedStillPoison())
                ++bad;
            if (!uamm2EgrOilRemovedNoEnhance())
                ++bad;
            // the bounds clamp holds;
            // the printed example
            // reads 68%, a book
            // arithmetic slip - the
            // formula gives 100 -
            // (17 x 2) = 66;
            // the chances partition
            // 100
            if (uamm2EgrSuccessChanceForScore(0)
                    != uamm2EgrSuccessChanceForScore(
                        3)
                    || uamm2EgrSuccessChanceForScore(
                        25)
                    != uamm2EgrSuccessChanceForScore(
                        18)) ++bad;
            if (uamm2EgrIntChancePct()
                    + uamm2EgrWisChancePct()
                    != 100) ++bad;
        // ---- the egg of shattering ----
            if (!uamm2EgsShattersOnHandleOrDetect())
                ++bad;
            if (uamm2EgsFragRadiusIn() != 1) ++bad;
            if (!uamm2EgsActualAcOnly()) ++bad;
            if (!uamm2EgsNoDexBonus()) ++bad;
            if (uamm2EgsFragHitsLo() != 1
                    || uamm2EgsFragHitsHi() != 4)
                ++bad;
            if (uamm2EgsFragDmgLo() != 2
                    || uamm2EgsFragDmgHi() != 7)
                ++bad;
            if (uamm2EgsFragileAutoFt() != 1
                    || uamm2EgsFragileSaveFt()
                    != 2) ++bad;
            if (!uamm2EgsSaveVsCrushingBlow())
                ++bad;
            if (!uamm2EgsAttackSeamGarbles())
                ++bad;
            // the save radius is
            // twice the automatic
            // radius
            if (2 * uamm2EgsFragileAutoFt()
                    != uamm2EgsFragileSaveFt())
                ++bad;
        // ---- the part ledger ----
            if (uamm2PartItemTotal() != 8) ++bad;
            if (uamm2PartCleanCount() != 1) ++bad;
            if (uamm2PartFlaggedCount() != 7)
                ++bad;
            if (uamm2PartGarbledCount() != 0)
                ++bad;
            if (uamm2PartCleanCount()
                    + uamm2PartFlaggedCount()
                    + uamm2PartGarbledCount()
                    != uamm2PartItemTotal()) ++bad;
        // ---- the R381 part-1 seam ----
            if (uammPartItemTotal() != 13) ++bad;
            if (uammPartCleanCount() != 8) ++bad;
            if (uammPartFlaggedCount() != 5)
                ++bad;
            if (uammPartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R382 UA misc magic prose part 2 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R382 audit')
s = rd(RT)
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R380 UA new wands prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R379 UA new rods staves prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R378 UA new rings prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R377 UA new scrolls protection pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R376 UA new potions prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R375 UA determination skeleton pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R374 UA treasure dial pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R373 UA comeliness note pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R372 UA cavalier followers pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 309, 'd census 309'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose2.h"'
) == 1, 'd new include'
for h in (
        'rules/cavalier.h',
        'rules/classtables.h',
        'rules/uabirth.h',
        'rules/uasocialclass.h',
        'rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h',
        'rules/uacavtable.h',
        'rules/uacantacq.h',
        'rules/uasmalls1.h',
        'rules/uailacquisition.h',
        'rules/thiefarmor.h',
        'rules/armorratings.h',
        'rules/comeliness.h',
        'rules/uaweapontable.h',
        'rules/uamissile.h',
        'rules/uanewweapons.h',
        'rules/uafollowers.h',
        'rules/uacomnote.h',
        'rules/uatreasuredial.h',
        'rules/uadetskel.h',
        'rules/uapotprose.h',
        'rules/uaprotscr.h',
        'rules/uaringprose.h',
        'rules/uarodstave.h',
        'rules/uawandprose.h',
        'rules/uamiscprose1.h',
        'rules/treasdet.h',
        'rules/hoard.h'):
    assert s.count(
        '#include "' + h + '"'
        ) == 1, 'd kept include'
for i in range(1, 8):
    assert s.count(
        '#include "rules/uailspells%d.h"'
        % i) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print(
    'R382 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R382 note: the misc magic',
    'prose part 2 round - the',
    'D-E stretch, eight items',
    'pin: one fully clean (the',
    'dust of tracelessness)',
    'plus seven mechanics-clean',
    'with flagged holes (the',
    'deck of illusions, the',
    'dicerion, the dust of',
    'dryness, the dust of',
    'illusion, the egg of',
    'desire, the egg of reason,',
    'the egg of shattering);',
    'nothing in D-E fully',
    'garbles - the item AMENDED,',
    'stays OPEN for F-Z,',
    'PDF-gated; the R381 seam',
    'the part-1 ledger, the',
    'R375 seam the misc band;',
    'the census 308 -> 309'
])
print(NOTE)
print('commit: R382: the UA misc')
print('magic prose part 2 pin round')
print('(census 309)')

