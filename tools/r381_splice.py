# R381: the UA misc magic prose
# part 1 pin round (pp. 97-100,
# the A-C items): THIRTEEN items
# pin - EIGHT fully clean (the
# beads of force, the boots of
# the north, the boots winged,
# the bracers of archery, the
# bracers of brachiation, the
# cloak of arachnidia, the
# cloak of the bat, the
# cyclocone) plus FIVE
# mechanics-clean with flagged
# holes (the amulet versus
# undead's 9th-level cell, the
# anything item's tail, the
# boccob book's save cell and
# scribing tail, the boots of
# varied tracks' row-one print,
# the chime of interruption's
# opening); NOTHING in A-C fully
# garbles - the gap item
# AMENDED with the part-1 note,
# stays OPEN for D-Z, PDF-gated;
# the R380 seam the wands
# ledger, the R375 seam the misc
# band; the census 307 -> 308.
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



# ---- (a) the seed: the R380 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R380 landed 2026-10-12: commit',
    '  867e10a, census 307, the UA',
    '  new wands prose pin round',
    '  (rules/uawandprose.h): seven',
    '  of the twelve wand types pin',
    '  - five fully clean',
    '  (anything, fireballs, flame',
    '  extinguishing, ice storms,',
    '  lightning bolts) plus two',
    '  mechanics-clean with flagged',
    '  holes (defoliation, metal',
    '  command); five types',
    '  OCR-scramble (buckler, earth',
    '  and stone, force, size',
    '  alteration, steam and vapor)',
    '  - the item AMENDED, stays',
    '  OPEN, PDF-gated; the R379',
    '  seam the rods ledger, the',
    '  R375 seam the wand band;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R380 landed 2026-10-12' in s:
    already.append('seed: the R380 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R380 record')
s = rd(SD)
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



# ---- (b) NEW rules/uamiscprose1.h ----
P = 'rules/uamiscprose1.h'
if os.path.exists(P) and 'R381' in rd(P):
    already.append('uamiscprose1.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamiscprose1.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 1, R381: the
// A-C items (pp. 97-100) -
// thirteen pins, eight fully
// clean (beads of force,
// boots of the north, boots
// winged, bracers of archery,
// bracers of brachiation,
// cloak of arachnidia, cloak
// of the bat, cyclocone) and
// five mechanics-clean with
// flagged holes (the amulet
// versus undead's 9th-level
// cell, the anything item's
// tail, the boccob book's
// save cell and scribing
// tail, the boots of varied
// tracks' row-one print, the
// chime of interruption's
// opening). Nothing in A-C
// fully garbles; D-Z rides
// the later parts. The wands
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the amulet versus
// undead ----
// A specially blessed symbol
// that turns undead as a
// cleric of its effective
// level; glows when
// presented strongly in the
// presence of undead.
inline bool uammAmuTurnsAsCleric()
    { return true; }

inline bool uammAmuGlowsWhenPresented()
    { return true; }

// The five strength bands:
// 01-30 5th, 31-55 6th,
// 56-75 7th, 76-90 8th,
// 91-00 9th - the 9th cell
// OCR-garbles ("Sth"), the
// sequence pins it; flagged.
inline int uammAmuBandCount()
    { return 5; }

inline int uammAmuLevelForBand(int i) {
    static const int k[5] = {
        5, 6, 7, 8, 9};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uammAmuBandLo(int i) {
    static const int k[5] = {
        1, 31, 56, 76, 91};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uammAmuBandHi(int i) {
    static const int k[5] = {
        30, 55, 75, 90, 100};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline bool uammAmuNinthCellGarbles()
    { return true; }

// Must be worn at all times;
// inert when not worn, and
// inert for the first seven
// days after it is put on.
inline bool uammAmuMustBeWorn()
    { return true; }

inline bool uammAmuInertWhenNotWorn()
    { return true; }

inline int uammAmuInertDaysOnDonning()
    { return 7; }

// The value rides the
// effective level: 200 x.p.,
// 1,000 gp sale, per level.
inline int uammAmuXpPerLevel()
    { return 200; }

inline int uammAmuGpPerLevel()
    { return 1000; }

// ---- the anything item ----
// Appears as one of the small,
// weak, frequently-found
// misc items; on command
// becomes any other misc
// magic item except an
// artifact or relic.
inline bool uammAnyBecomesAnyMiscItem()
    { return true; }

inline bool uammAnyExcludesArtifactsRelics()
    { return true; }

inline bool uammAnyNoFormRepeated()
    { return true; }

// If the commanded form is
// normally destroyed in
// usage, the anything item
// is destroyed likewise.
inline bool uammAnyDiesWithDestructiveForms()
    { return true; }

// Short-term single-usage
// forms (a horn, drums)
// return it to original after
// one use; long-term forms
// see it disappear after
// three uses - the tail
// sentence OCR-scrambles, the
// mechanics read; flagged.
inline bool uammAnyShortTermReturnsOnce()
    { return true; }

inline bool uammAnyLongTermDisappears()
    { return true; }

inline int uammAnyLongTermUseLimit()
    { return 3; }

inline bool uammAnyTailGarbles()
    { return true; }

// ---- the beads of force ----
// A small black sphere,
// three-quarters of an inch
// across, nearly an ounce;
// hurled up to 3".
inline int uammBeaDiamEighthIn()
    { return 6; }

inline int uammBeaWeightOunces()
    { return 1; }

inline int uammBeaHurlRangeIn()
    { return 3; }

// On impact: 5-20 (5d4) to
// all within a 10-foot radius,
// save versus spell - savers
// thrown clear, failers
// encapsulated after taking
// the damage.
inline int uammBeaDmgDice()
    { return 5; }

inline int uammBeaDmgLo()
    { return 5; }

inline int uammBeaDmgHi()
    { return 20; }

inline int uammBeaBlastRadiusFt()
    { return 10; }

inline bool uammBeaSaveIsVsSpell()
    { return true; }

inline bool uammBeaSaversThrownClear()
    { return true; }

inline bool uammBeaFailersEncapsulated()
    { return true; }

// The sphere of force holds
// 3-12 rounds, even around
// large creatures; escape
// only as from a wall of
// force.
inline int uammBeaSphereLoRounds()
    { return 3; }

inline int uammBeaSphereHiRounds()
    { return 12; }

inline bool uammBeaEscapeOnlyAsWallOfForce()
    { return true; }

// Five to eight beads are
// usually found together.
inline int uammBeaFoundLo()
    { return 5; }

inline int uammBeaFoundHi()
    { return 8; }

// ---- boccob's blessed book
// ----
// A small durable tome: no
// more than 12 inches tall,
// 6 wide, 1 thick; some a
// mere 6 inches in height.
inline int uammBocMaxHeightIn()
    { return 12; }

inline int uammBocWidthIn()
    { return 6; }

inline int uammBocThickIn()
    { return 1; }

inline int uammBocSomeMereHeightIn()
    { return 6; }

inline bool uammBocWaterproofBoundLocked()
    { return true; }

// +3 on saving throws - the
// save-category cell ("leather
// or ...") OCR-truncates,
// flagged.
inline int uammBocSaveBonus()
    { return 3; }

inline bool uammBocSaveCellGarbles()
    { return true; }

// The pages accept scribed
// spells; a book holds up to
// 45 levels - prized as a
// travelling spell book; the
// enscribing tail garbles,
// flagged.
inline int uammBocMaxSpellLevels()
    { return 45; }

inline bool uammBocPrizedAsTravellingBook()
    { return true; }

inline bool uammBocScribingTailGarbles()
    { return true; }

// ---- the boots of the north
// ----
// Snow travel at normal rate
// leaving no tracks; half
// normal rate on the most
// slippery ice, horizontal
// surfaces only.
inline bool uammBnSnowNormalNoTracks()
    { return true; }

inline bool uammBnIceHalfRateHorizontal()
    { return true; }

// Warmth: -50 F in scant
// clothing; -100 F fully
// dressed in cold-weather
// gear.
inline int uammBnScantClothingMinF()
    { return -50; }

inline int uammBnFullDressMinF()
    { return -100; }

// ---- the boots of varied
// tracks ----
// On command the wearer's
// tracks alter: as small as a
// halfling's, as large as an
// ogre's, bare or shod.
inline bool uammBvtCommandAltersTracks()
    { return true; }

inline bool uammBvtSmallAsHalfling()
    { return true; }

inline bool uammBvtLargeAsOgre()
    { return true; }

inline bool uammBvtBareOrShod()
    { return true; }

// Each pair carries four
// capabilities from the
// 16-entry track table; the
// table's row-one print
// OCR-garbles, the other
// fifteen read; flagged.
inline int uammBvtCapabilitiesPerPair()
    { return 4; }

inline int uammBvtTrackTableCount()
    { return 16; }

inline bool uammBvtRowOnePrintGarbles()
    { return true; }

// ---- the boots, winged ----
// Up to two hours of flight
// per day, at once or split;
// past the limit the power
// fades slowly, a gentle
// descent.
inline int uammBwMaxHoursPerDay()
    { return 2; }

inline bool uammBwFadeSlowlyPastLimit()
    { return true; }

// Twelve hours of non-use
// regain one flying hour;
// never above the two-hour
// maximum.
inline int uammBwRestHoursPerChargeHour()
    { return 12; }

inline bool uammBwNeverAboveMax()
    { return true; }

// The four types by die roll:
// 1: 15" MC A, 2: 18" B,
// 3: 21" C, 4: 24" D - the
// die column carries minor
// OCR, the mapping pins;
// flagged.
inline int uammBwTypeCount()
    { return 4; }

inline int uammBwSpeedForRoll(int r) {
    static const int k[4] = {
        15, 18, 21, 24};
    if (r < 1) return 0;
    if (r > 4) return 0;
    return k[r - 1];
}

inline char uammBwMcForRoll(int r) {
    static const char k[4] = {
        'A', 'B', 'C', 'D'};
    if (r < 1) return ' ';
    if (r > 4) return ' ';
    return k[r - 1];
}

inline bool uammBwDieCellsMinorOcr()
    { return true; }

// ---- the bracers of
// archery ----
// For bow-able wearers
// (crossbows excluded):
// grants proficiency if
// lacking; with proficiency
// in the bow type used:
// +2 to hit, +1 to damage.
inline bool uammBaWorksForBowUsers()
    { return true; }

inline bool uammBaExcludesCrossbows()
    { return true; }

inline bool uammBaGrantsProficiencyIfLacking()
    { return true; }

inline int uammBaProficientHitBonus()
    { return 2; }

inline int uammBaProficientDmgBonus()
    { return 1; }

// The bonuses are cumulative
// with all others except
// weapon specialization.
inline bool uammBaCumulativeExceptSpecialization()
    { return true; }

// ---- the bracers of
// brachiation ----
// Movement by brachiation
// where hand-holds exist:
// 3", 6", or 9" by how
// jungle-like the locale.
inline bool uammBbNeedsHandholds()
    { return true; }

inline int uammBbMoveRatesCount()
    { return 3; }

inline int uammBbMoveLoIn()
    { return 3; }

inline int uammBbMoveHiIn()
    { return 9; }

// Climbs trees, vines, poles,
// ropes at 6"; swings as a
// simian; leaps and jumps as
// boots of striding and
// springing, but the jump
// must culminate in a
// brachiation-related
// activity.
inline int uammBbClimbRateIn()
    { return 6; }

inline bool uammBbSwingsAsSimian()
    { return true; }

inline bool uammBbJumpsAsStridingSpringing()
    { return true; }

inline bool uammBbJumpMustCulminate()
    { return true; }

// ---- the chime of
// interruption ----
// The opening sentence
// OCR-scrambles - the item
// name garbles into the
// mechanics; flagged. Struck
// only once per turn; the
// resonant tone lasts three
// full rounds.
inline bool uammChiOpeningGarbles()
    { return true; }

inline int uammChiStrikesPerTurn()
    { return 1; }

inline int uammChiToneRounds()
    { return 3; }

// While resonating: no
// verbal-component spell
// within a 30-foot radius
// unless the caster saves
// versus breath weapon.
inline int uammChiVerbalBlockRadiusFt()
    { return 30; }

inline bool uammChiBlockSaveIsVsBreath()
    { return true; }

// After the tone fades the
// chime rests at least 7
// rounds; an early strike
// sounds nothing and waits
// a full turn from that
// point.
inline int uammChiRestRounds()
    { return 7; }

inline bool uammChiEarlyStrikeSilent()
    { return true; }

inline int uammChiEarlyStrikeWaitTurns()
    { return 1; }

// ---- the cloak of
// arachnidia ----
// A strong alteration aura;
// the wearer climbs as
// spider climb, immune to
// web entrapment, moving in
// webs at the creator
// spider's rate or base 6".
inline bool uammCaStrongAlterationAura()
    { return true; }

inline bool uammCaGrantsSpiderClimb()
    { return true; }

inline bool uammCaImmuneToWebs()
    { return true; }

inline int uammCaWebMoveBaseIn()
    { return 6; }

// Once per day a
// double-sized web, as the
// 2nd-level magic-user
// spell; +2 on saves versus
// arachnid poison.
inline int uammCaDoubleWebPerDay()
    { return 1; }

inline int uammCaDoubleWebSpellLevel()
    { return 2; }

inline int uammCaSaveVsArachnidPoison()
    { return 2; }

// ---- the cloak of the bat
// ----
// 90% invisible when
// stationary in shadow or
// darkness; the wearer may
// hang upside down keeping
// the chance.
inline int uammCbInvisibilityPct()
    { return 90; }

inline bool uammCbStationaryInShadowOrDark()
    { return true; }

inline bool uammCbHangsUpsideDown()
    { return true; }

// Holding the edges: fly at
// 15" (MC B); or transform
// into an ordinary bat, all
// possessions riding along.
inline int uammCbFlySpeedIn()
    { return 15; }

inline char uammCbFlyMcClass()
    { return 'B'; }

inline bool uammCbBatTransformation()
    { return true; }

// Flying, either way, only in
// darkness; up to one hour
// at a time, then no flight
// for a like period.
inline bool uammCbFlightDarknessOnly()
    { return true; }

inline int uammCbFlightMaxHours()
    { return 1; }

inline bool uammCbRestEqualsFlight()
    { return true; }

// Protection as a robe of
// protection at +2, holding
// even in bat form.
inline int uammCbProtectionBonus()
    { return 2; }

inline bool uammCbProtectionHoldsInBatForm()
    { return true; }

// ---- the cyclocone ----
// An ordinary pointed hat
// radiating dim evocation;
// magic-user only, tossed
// with a spinning motion.
inline bool uammCyDimEvocationAura()
    { return true; }

inline bool uammCyMuOnly()
    { return true; }

// The whirlwind: 5 feet wide
// at the base, 15 at the
// top, up to 45 high; forms
// within 1-4 segments.
inline int uammCyBaseWidthFt()
    { return 5; }

inline int uammCyTopWidthFt()
    { return 15; }

inline int uammCyMaxHeightFt()
    { return 45; }

inline int uammCyFormSegsLo()
    { return 1; }

inline int uammCyFormSegsHi()
    { return 4; }

// It sweeps straight at 18"
// for one full round, until
// a solid sturdy object
// breaks it up - a living
// breaker takes the damage.
inline int uammCyMoveRateIn()
    { return 18; }

inline int uammCyDurationRounds()
    { return 1; }

inline bool uammCySturdyObjectBreaksIt()
    { return true; }

inline bool uammCyBreakerTakesDamage()
    { return true; }

// Creatures under 2+1 hit
// dice caught or touched:
// instantly killed and
// carried along; others take
// 4-16; within 5 feet of the
// outer edge at formation:
// 2-8.
inline bool uammCyInstantKillBelowTwoPlusOne()
    { return true; }

inline int uammCyCaughtDmgLo()
    { return 4; }

inline int uammCyCaughtDmgHi()
    { return 16; }

inline int uammCyEdgeRangeFt()
    { return 5; }

inline int uammCyEdgeDmgLo()
    { return 2; }

inline int uammCyEdgeDmgHi()
    { return 8; }

// Not reusable - destroyed
// when the whirlwind
// dissipates.
inline bool uammCyNotReusable()
    { return true; }

// ---- the part ledger ----
// Thirteen A-C items: eight
// fully clean, five
// mechanics-clean with
// flagged holes, none fully
// garbled.
inline int uammPartItemTotal()
    { return 13; }

inline int uammPartCleanCount()
    { return 8; }

inline int uammPartFlaggedCount()
    { return 5; }

inline int uammPartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose1.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 126, 'b inline count'
assert s.count('R381') == 1, 'b round tag'
assert s.count(
    'uammAmuTurnsAsCleric'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'



# ---- (c) the gap report: the amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R381' in s:
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
        '      Lanthorn, the Sheet of Smallness.'
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
        '        undead\'s 9th-level cell, the',
        '        anything item\'s tail, the',
        '        boccob book\'s save cell and',
        '        scribing tail, the boots of',
        '        varied tracks\' row-one',
        '        print, the chime of',
        '        interruption\'s opening);',
        '        NOTHING in A-C fully garbles',
        '        - the item stays OPEN for',
        '        D-Z and the PDF.'
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
    'AMENDED R381'
) == 1, 'c amendment'
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
    '(rules/uamiscprose1.h)'
) == 1, 'c misc note'
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
if 'R381 UA misc magic prose part 1 pin audit' in s:
    already.append('regtest.cpp: the R381 audit')
else:
    INC_ANCH = ('#include "rules/uawandprose.h"  // '
        'R380: the UA new wands prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose1.h"  // R381: the UA misc magic prose 1'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R381: the UA misc magic
    // prose part 1 pin audit ----
    // The A-C items (pp. 97-100),
    // thirteen pins: eight fully
    // clean (beads of force,
    // boots of the north, boots
    // winged, bracers of archery,
    // bracers of brachiation,
    // cloak of arachnidia, cloak
    // of the bat, cyclocone)
    // plus five mechanics-clean
    // with flagged holes (the
    // amulet, the anything item,
    // the boccob book, the boots
    // of varied tracks, the
    // chime). D-Z rides the
    // later parts. The R380 seam
    // cross-checks the wands
    // ledger, the R375 seam the
    // misc band; the census
    // 307 -> 308.
    {
        using namespace rules;
        int bad = 0;
        // ---- the amulet versus undead ----
            if (!uammAmuTurnsAsCleric()) ++bad;
            if (!uammAmuGlowsWhenPresented()) ++bad;
            static const int kAmuL[5] = {
                5, 6, 7, 8, 9};
            static const int kAmuLo[5] = {
                1, 31, 56, 76, 91};
            static const int kAmuHi[5] = {
                30, 55, 75, 90, 100};
            if (uammAmuBandCount() != 5) ++bad;
            for (int i = 0; i < 5; ++i) {
                if (uammAmuLevelForBand(i)
                        != kAmuL[i]) ++bad;
                if (uammAmuBandLo(i) != kAmuLo[i])
                    ++bad;
                if (uammAmuBandHi(i) != kAmuHi[i])
                    ++bad;
                if (i < 4 && kAmuHi[i] + 1
                        != kAmuLo[i + 1]) ++bad;
            }
            if (uammAmuLevelForBand(4) != 9)
                ++bad;
            if (!uammAmuNinthCellGarbles()) ++bad;
            if (!uammAmuMustBeWorn()) ++bad;
            if (!uammAmuInertWhenNotWorn()) ++bad;
            if (uammAmuInertDaysOnDonning() != 7)
                ++bad;
            if (uammAmuXpPerLevel() != 200) ++bad;
            if (uammAmuGpPerLevel() != 1000) ++bad;
            // the gp value rides at
            // five times the xp value
            if (uammAmuGpPerLevel()
                    != 5 * uammAmuXpPerLevel())
                ++bad;
        // ---- the anything item ----
            if (!uammAnyBecomesAnyMiscItem())
                ++bad;
            if (!uammAnyExcludesArtifactsRelics())
                ++bad;
            if (!uammAnyNoFormRepeated()) ++bad;
            if (!uammAnyDiesWithDestructiveForms())
                ++bad;
            if (!uammAnyShortTermReturnsOnce())
                ++bad;
            if (!uammAnyLongTermDisappears())
                ++bad;
            if (uammAnyLongTermUseLimit() != 3)
                ++bad;
            if (!uammAnyTailGarbles()) ++bad;
        // ---- the beads of force ----
            if (uammBeaDiamEighthIn() != 6) ++bad;
            if (uammBeaWeightOunces() != 1) ++bad;
            if (uammBeaHurlRangeIn() != 3) ++bad;
            if (uammBeaDmgDice() != 5) ++bad;
            if (uammBeaDmgLo() != 5) ++bad;
            if (uammBeaDmgHi() != 20) ++bad;
            if (uammBeaBlastRadiusFt() != 10) ++bad;
            if (!uammBeaSaveIsVsSpell()) ++bad;
            if (!uammBeaSaversThrownClear()) ++bad;
            if (!uammBeaFailersEncapsulated())
                ++bad;
            if (uammBeaSphereLoRounds() != 3) ++bad;
            if (uammBeaSphereHiRounds() != 12)
                ++bad;
            if (!uammBeaEscapeOnlyAsWallOfForce())
                ++bad;
            if (uammBeaFoundLo() != 5) ++bad;
            if (uammBeaFoundHi() != 8) ++bad;
        // ---- boccob's blessed book ----
            if (uammBocMaxHeightIn() != 12) ++bad;
            if (uammBocWidthIn() != 6) ++bad;
            if (uammBocThickIn() != 1) ++bad;
            if (uammBocSomeMereHeightIn() != 6)
                ++bad;
            if (!uammBocWaterproofBoundLocked())
                ++bad;
            if (uammBocSaveBonus() != 3) ++bad;
            if (!uammBocSaveCellGarbles()) ++bad;
            if (uammBocMaxSpellLevels() != 45)
                ++bad;
            if (!uammBocPrizedAsTravellingBook())
                ++bad;
            if (!uammBocScribingTailGarbles())
                ++bad;
        // ---- the boots of the north ----
            if (!uammBnSnowNormalNoTracks()) ++bad;
            if (!uammBnIceHalfRateHorizontal())
                ++bad;
            if (uammBnScantClothingMinF() != -50)
                ++bad;
            if (uammBnFullDressMinF() != -100)
                ++bad;
            // full dress doubles the
            // scant-clothing floor
            if (2 * uammBnScantClothingMinF()
                    != uammBnFullDressMinF()) ++bad;
        // ---- the boots of varied tracks ----
            if (!uammBvtCommandAltersTracks())
                ++bad;
            if (!uammBvtSmallAsHalfling()) ++bad;
            if (!uammBvtLargeAsOgre()) ++bad;
            if (!uammBvtBareOrShod()) ++bad;
            if (uammBvtCapabilitiesPerPair() != 4)
                ++bad;
            if (uammBvtTrackTableCount() != 16)
                ++bad;
            if (!uammBvtRowOnePrintGarbles()) ++bad;
            // the four capabilities
            // ride the 16-entry table
            if (4 * uammBvtCapabilitiesPerPair()
                    != uammBvtTrackTableCount())
                ++bad;
        // ---- the boots, winged ----
            if (uammBwMaxHoursPerDay() != 2) ++bad;
            if (!uammBwFadeSlowlyPastLimit())
                ++bad;
            if (uammBwRestHoursPerChargeHour()
                    != 12) ++bad;
            if (!uammBwNeverAboveMax()) ++bad;
            static const int kBw[4] = {
                15, 18, 21, 24};
            if (uammBwTypeCount() != 4) ++bad;
            for (int i = 0; i < 4; ++i) {
                if (uammBwSpeedForRoll(i + 1)
                        != kBw[i]) ++bad;
                // the speeds climb by 3
                if (uammBwSpeedForRoll(i + 1)
                        != 15 + 3 * i) ++bad;
            }
            if (uammBwSpeedForRoll(0) != 0) ++bad;
            if (uammBwSpeedForRoll(5) != 0) ++bad;
            if (uammBwMcForRoll(1) != 'A') ++bad;
            if (uammBwMcForRoll(4) != 'D') ++bad;
            if (!uammBwDieCellsMinorOcr()) ++bad;
        // ---- the bracers of archery ----
            if (!uammBaWorksForBowUsers()) ++bad;
            if (!uammBaExcludesCrossbows()) ++bad;
            if (!uammBaGrantsProficiencyIfLacking())
                ++bad;
            if (uammBaProficientHitBonus() != 2)
                ++bad;
            if (uammBaProficientDmgBonus() != 1)
                ++bad;
            if (!uammBaCumulativeExceptSpecialization())
                ++bad;
        // ---- the bracers of brachiation ----
            if (!uammBbNeedsHandholds()) ++bad;
            if (uammBbMoveRatesCount() != 3) ++bad;
            if (uammBbMoveLoIn() != 3) ++bad;
            if (uammBbMoveHiIn() != 9) ++bad;
            if (uammBbClimbRateIn() != 6) ++bad;
            if (!uammBbSwingsAsSimian()) ++bad;
            if (!uammBbJumpsAsStridingSpringing())
                ++bad;
            if (!uammBbJumpMustCulminate()) ++bad;
            // the three movement rates
            // climb by 3
            if (uammBbMoveLoIn() != 3
                    || uammBbMoveHiIn()
                    != 3 * uammBbMoveRatesCount())
                ++bad;
        // ---- the chime of interruption ----
            if (!uammChiOpeningGarbles()) ++bad;
            if (uammChiStrikesPerTurn() != 1) ++bad;
            if (uammChiToneRounds() != 3) ++bad;
            if (uammChiVerbalBlockRadiusFt() != 30)
                ++bad;
            if (!uammChiBlockSaveIsVsBreath()) ++bad;
            if (uammChiRestRounds() != 7) ++bad;
            if (!uammChiEarlyStrikeSilent()) ++bad;
            if (uammChiEarlyStrikeWaitTurns() != 1)
                ++bad;
        // ---- the cloak of arachnidia ----
            if (!uammCaStrongAlterationAura())
                ++bad;
            if (!uammCaGrantsSpiderClimb()) ++bad;
            if (!uammCaImmuneToWebs()) ++bad;
            if (uammCaWebMoveBaseIn() != 6) ++bad;
            if (uammCaDoubleWebPerDay() != 1) ++bad;
            if (uammCaDoubleWebSpellLevel() != 2)
                ++bad;
            if (uammCaSaveVsArachnidPoison() != 2)
                ++bad;
        // ---- the cloak of the bat ----
            if (uammCbInvisibilityPct() != 90)
                ++bad;
            if (!uammCbStationaryInShadowOrDark())
                ++bad;
            if (!uammCbHangsUpsideDown()) ++bad;
            if (uammCbFlySpeedIn() != 15) ++bad;
            if (uammCbFlyMcClass() != 'B') ++bad;
            if (!uammCbBatTransformation()) ++bad;
            if (!uammCbFlightDarknessOnly()) ++bad;
            if (uammCbFlightMaxHours() != 1) ++bad;
            if (!uammCbRestEqualsFlight()) ++bad;
            if (uammCbProtectionBonus() != 2) ++bad;
            if (!uammCbProtectionHoldsInBatForm())
                ++bad;
        // ---- the cyclocone ----
            if (!uammCyDimEvocationAura()) ++bad;
            if (!uammCyMuOnly()) ++bad;
            if (uammCyBaseWidthFt() != 5) ++bad;
            if (uammCyTopWidthFt() != 15) ++bad;
            if (uammCyMaxHeightFt() != 45) ++bad;
            if (uammCyFormSegsLo() != 1) ++bad;
            if (uammCyFormSegsHi() != 4) ++bad;
            if (uammCyMoveRateIn() != 18) ++bad;
            if (uammCyDurationRounds() != 1) ++bad;
            if (!uammCySturdyObjectBreaksIt())
                ++bad;
            if (!uammCyBreakerTakesDamage()) ++bad;
            if (!uammCyInstantKillBelowTwoPlusOne())
                ++bad;
            if (uammCyCaughtDmgLo() != 4) ++bad;
            if (uammCyCaughtDmgHi() != 16) ++bad;
            if (uammCyEdgeRangeFt() != 5) ++bad;
            if (uammCyEdgeDmgLo() != 2) ++bad;
            if (uammCyEdgeDmgHi() != 8) ++bad;
            if (!uammCyNotReusable()) ++bad;
            // the top width is the
            // base tripled; the height
            // is the top tripled
            if (3 * uammCyBaseWidthFt()
                    != uammCyTopWidthFt()) ++bad;
            if (3 * uammCyTopWidthFt()
                    != uammCyMaxHeightFt()) ++bad;
            // the edge damage is the
            // caught damage halved
            if (2 * uammCyEdgeDmgLo()
                    != uammCyCaughtDmgLo()
                    || 2 * uammCyEdgeDmgHi()
                    != uammCyCaughtDmgHi()) ++bad;
        // ---- the part ledger ----
            if (uammPartItemTotal() != 13) ++bad;
            if (uammPartCleanCount() != 8) ++bad;
            if (uammPartFlaggedCount() != 5) ++bad;
            if (uammPartGarbledCount() != 0) ++bad;
            if (uammPartCleanCount()
                    + uammPartFlaggedCount()
                    + uammPartGarbledCount()
                    != uammPartItemTotal()) ++bad;
        // ---- the R380 wands seam ----
            if (uawdCleanCount() != 5) ++bad;
            if (uawdFlaggedCount() != 2) ++bad;
            if (uawdGarbledCount() != 5) ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R381 UA misc magic prose part 1 pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R381 audit')
s = rd(RT)
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 308, 'd census 308'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose1.h"'
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
    'R381 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R381 note: the misc magic',
    'prose part 1 round - the',
    'A-C stretch, thirteen',
    'items pin: eight fully',
    'clean (beads of force,',
    'boots of the north, boots',
    'winged, bracers of',
    'archery, bracers of',
    'brachiation, cloak of',
    'arachnidia, cloak of the',
    'bat, cyclocone) plus',
    'five mechanics-clean with',
    'flagged holes (the',
    'amulet, the anything item,',
    'the boccob book, the',
    'boots of varied tracks,',
    'the chime); nothing in',
    'A-C fully garbles - the',
    'item AMENDED, stays OPEN',
    'for D-Z, PDF-gated; the',
    'R380 seam the wands',
    'ledger, the R375 seam the',
    'misc band; the census',
    '307 -> 308'
])
print(NOTE)
print('commit: R381: the UA misc')
print('magic prose part 1 pin round')
print('(census 308)',)

