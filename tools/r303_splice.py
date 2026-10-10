#!/usr/bin/env python3
# tools/r303_splice.py - R303: the thief
# pockets wired (the R301/R302 standing
# successor - the pick pockets column
# rolls at the city street site).
#
# The R298 pick pockets column stayed
# data (no engine site rolled it). This
# round wires the PHB print (the Notes
# Regarding Thief Functions): one
# percentile at or below the chance CUT
# 5 percent per victim level above the
# 3rd; a fail 21 percent or more above
# the chance reads noticed (the printed
# worked example: 120 cut to 75 by a 12th
# level victim, noticed from 96).
#
#   (a) rules/thieffunc.h - the
#       street-site seams:
#       thfPocketsChanceTenths (the
#       victim cut fold; the cut may
#       cross zero) and
#       thfPocketsVictimNotices (the
#       printed 21 percent notice band);
#       the R301/R302 comment heads
#       amend.
#   (b) game/appstate.h - the
#       cityPickPockets declaration.
#   (c) game/state_sea.cpp - the roll:
#       the first living thief draws the
#       passerby trade (d4) and level
#       (d6), then one printed
#       percentile; success lifts the
#       R190 purse of the trade (the
#       startmoney pin gains its first
#       engine caller), a noticed fail
#       draws the watch fine (a tenth of
#       the purse, the R133 convention);
#       enterCity keys [P].
#   (d) adnd1.cpp - the [P] city key
#       (the switch, the comment, the
#       screen). The case labels carry
#       the one apostrophe family of the
#       content (built via chr(39), the
#       R301 allow_apos precedent).
#   (e) regtest.cpp - the R303 audit
#       pair (the battery census 223 ->
#       225): the R303a seam audit walks
#       the cut fold and the notice band
#       (evaluable - verified by
#       audit_eval; the printed worked
#       example walks live) and the R303
#       engine audit pins every scenario
#       on seeded sequences (the replica
#       walked the draws first - no
#       compiler in the splice sandbox).
#   (f) tools/phb_gap_report.md - the
#       wiring-arc box (the R298 box head
#       amended; the ledger holds ZERO
#       open items).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS) and no CONTENT string embeds
# an apostrophe outside the adnd1.cpp case
# labels, non-ASCII or (for the gap report) a
# line past 57 columns.
# Commit: "R303: the thief pockets wired
# (census 225)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
Q = chr(39)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, allow_apos=False):
    if not allow_apos:
        assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/thieffunc.h: the street-site seams ----
TF_HEAD_OLD = NL.join([
    '// R302: the move silently roll now runs at',
    '// the surprise site; the other functions',
    '// wait for engine sites that do not exist',
    '// yet.',
])
TF_HEAD_NEW = NL.join([
    '// R302: the move silently roll now runs at',
    '// the surprise site; R303: the pick',
    '// pockets roll now runs at the city',
    '// street site; the others wait for engine',
    '// sites that do not exist yet.',
])
TF_SEAM_OLD = NL.join([
    '    // draws); R302: the surprise site rolls',
    '    // the move silently draw (one per',
    '    // encounter); the rest stay data',
])
TF_SEAM_NEW = NL.join([
    '    // draws); R302: the surprise site rolls',
    '    // the move silently draw (one per',
    '    // encounter); R303: the street site',
    '    // rolls the pick pockets draw (through',
    '    // the victim-cut seam); the rest stay',
    '    // data',
])
TF_TAIL_OLD = NL.join([
    '// R302: the printed note - moving silently',
    '// can be attempted each time the thief',
    '// moves. The encounter site rolls it once',
    '// per encounter (the movement granularity',
    '// simplification, recorded in the phb gap',
    '// report).',
    'inline int thfNoteSilenceEachMove() {',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
TF_TAIL_NEW = NL.join([
    '// R302: the printed note - moving silently',
    '// can be attempted each time the thief',
    '// moves. The encounter site rolls it once',
    '// per encounter (the movement granularity',
    '// simplification, recorded in the phb gap',
    '// report).',
    'inline int thfNoteSilenceEachMove() {',
    '    return 1;',
    '}',
    '',
    '// R303: the pick pockets adjusted chance',
    '// seam - the printed base folded with the',
    '// printed victim cut: the potential victim',
    '// reduces the chance 5 percent per level',
    '// above the 3rd. The cut may drive the',
    '// chance below zero (every draw then',
    '// fails and the notice band reads off the',
    '// negative chance).',
    'inline int thfPocketsChanceTenths(int level, int race,',
    '                                   int dex,',
    '                                   int victimLevel) {',
    '    int cut = victimLevel > 3',
    '        ? (victimLevel - 3) * thfNotePocketsVictimCut()',
    '        : 0;',
    '    return thfChanceTenths(THF_PICK_POCKETS, level,',
    '                           race, dex) - 10 * cut;',
    '}',
    '',
    '// R303: the printed notice band - a failed',
    '// score 21 percent or more above the',
    '// chance means the victim notices the',
    '// attempt (the worked example: the 75',
    '// chance reads noticed from 96).',
    'inline bool thfPocketsVictimNotices(int rollTenths,',
    '                                    int chanceTenths) {',
    '    return rollTenths >= chanceTenths +',
    '        10 * thfNotePocketsNoticeBand();',
    '}',
    '',
    '}  // namespace rules',
])
for t in (TF_HEAD_OLD, TF_HEAD_NEW, TF_SEAM_OLD, TF_SEAM_NEW,
          TF_TAIL_OLD, TF_TAIL_NEW):
    clean(t, 78)

p = 'rules/thieffunc.h'
s = rd(p)
if 'thfPocketsChanceTenths' in s:
    already.append('thieffunc.h: the street-site seams')
else:
    assert s.count(TF_HEAD_OLD) == 1, 'tf head anchor not unique'
    assert s.count(TF_SEAM_OLD) == 1, 'tf seam anchor not unique'
    assert s.count(TF_TAIL_OLD) == 1, 'tf tail anchor not unique'
    assert 'thfPocketsVictimNotices' not in s, 'tf marker collision'
    s = s.replace(TF_HEAD_OLD, TF_HEAD_NEW)
    s = s.replace(TF_SEAM_OLD, TF_SEAM_NEW)
    s = s.replace(TF_TAIL_OLD, TF_TAIL_NEW)
    wr(p, s)
    applied.append('thieffunc.h: the street-site seams')
s = rd(p)
assert s.count('inline int thfPocketsChanceTenths') == 1, 'patch a chance seam'
assert s.count('inline bool thfPocketsVictimNotices') == 1, 'patch a notice seam'
assert 'the other functions stay data' not in s, 'patch a stale seam note'
assert 'wait for engine' in s, 'patch a ate the head note'
assert s.count('}  // namespace rules') == 1, 'patch a namespace close'
assert s.count('inline int thfNoteSilenceEachMove') == 1, 'patch a ate the note'
assert s.count('inline bool thf') == 3, 'patch a percentile family'
assert s.count('inline bool thfAttemptSucceeds') == 1, 'patch a ate the attempt'
assert 'thfTakeTenths' in s and 'thfNoteLocksOneTry' in s, 'patch a ate a pin'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/appstate.h: the declaration ----
AH_OLD = NL.join([
    '    void cityExcursion(dm::CityTime t);',
    '};',
])
AH_NEW = NL.join([
    '    void cityExcursion(dm::CityTime t);',
    '',
    '    // R303: [P] - the thief street lift (the',
    '    // PHB pick pockets print: one percentile',
    '    // against the chance cut 5 percent per',
    '    // victim level above the 3rd; a fail 21',
    '    // percent or more above reads noticed;',
    '    // success lifts the purse). The mode and',
    '    // alive gates ride (the cityExcursion',
    '    // convention).',
    '    void cityPickPockets();',
    '};',
])
for t in (AH_OLD, AH_NEW):
    clean(t, 78)

p = 'game/appstate.h'
s = rd(p)
if 'cityPickPockets' in s:
    already.append('appstate.h: the declaration')
else:
    assert s.count(AH_OLD) == 1, 'ah anchor not unique'
    assert 'cityPickPockets' not in s, 'ah marker collision'
    s = s.replace(AH_OLD, AH_NEW)
    wr(p, s)
    applied.append('appstate.h: the declaration')
s = rd(p)
assert s.count('void cityPickPockets();') == 1, 'patch b declaration'
assert s.count('void cityExcursion(dm::CityTime t);') == 1, 'patch b excursion'
assert s.count('};') >= 1, 'patch b class close'
assert 'void enterCity();' in s, 'patch b ate enterCity'
assert 'void leaveCity();' in s, 'patch b ate leaveCity'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/state_sea.cpp: the roll + the key line ----
SS_INC_OLD = NL.join([
    '#include "appstate.h"',
])
SS_INC_NEW = NL.join([
    '#include "appstate.h"',
    '#include "rules/startmoney.h"   // R303: the passerby purse',
    '#include "rules/thieffunc.h"    // R303: the pockets roll',
])
SS_CITY_OLD = NL.join([
    '        log.add("[1] by day  [2] by night  [B] back to town.");',
])
SS_CITY_NEW = NL.join([
    '        log.add("[1] by day  [2] by night  [P] pick "',
    '                "pockets  [B] back to town.");',
])
SS_TAIL_OLD = NL.join([
    '        log.add(line);',
    '    }',
])
SS_TAIL_NEW = NL.join([
    '        log.add(line);',
    '    }',
    '',
    '// ---- cityPickPockets ----',
    '// R303: the printed pick pockets roll (the',
    '// PHB Notes Regarding Thief Functions): one',
    '// percentile at or below the chance CUT 5',
    '// percent per victim level above the 3rd; a',
    '// fail 21 percent or more above the chance',
    '// means the passerby notices. JUDGMENTS (the',
    '// print leaves them open): the passerby',
    '// reads a d4 trade and a d6 level; the',
    '// purse reads the R190 starting money dice',
    '// of that trade (the engine only prints',
    '// money by class - the printed random item',
    '// has no stranger inventory); a noticed',
    '// attempt draws the watch - a fine of a',
    '// tenth of the company purse (the R133',
    '// greed convention).',
    'void AppState::cityPickPockets(){',
    '        if (mode != MODE_CITY) return;',
    '        if (!party.alive()) return;',
    '        const Character* thief = nullptr;',
    '        for (const auto& c : party.members)',
    '            if (c.hp > 0 && c.classIndex == 3) {',
    '                thief = &c;',
    '                break;',
    '            }',
    '        if (!thief) {',
    '            log.add("No thief walks the streets "',
    '                    "with you.");',
    '            return;',
    '        }',
    '        // the passerby: trade and level',
    '        int vcls = (int)dice.roll(1, 4, 0) - 1;',
    '        int vlevel = (int)dice.roll(1, 6, 0);',
    '        // the printed percentile draw (tenths)',
    '        int roll = (int)rng.below(1000);',
    '        int chance = rules::thfPocketsChanceTenths(',
    '            thief->level, thief->race,',
    '            (int)thief->abilities.dex, vlevel);',
    '        if (rules::thfPercentileSucceeds(roll, chance)) {',
    '            // success: the purse lift (the R190',
    '            // starting money roll of the trade)',
    '            int purse = (int)dice.roll(',
    '                rules::startingMoneyDiceCount(vcls),',
    '                rules::startingMoneyDieFaces(vcls), 0)',
    '                * rules::startingMoneyMultiplier(vcls);',
    '            party.gold += purse;',
    '            char buf[96];',
    '            snprintf(buf, sizeof buf,',
    '                     "%s lifts %d gp from a passerby.",',
    '                     thief->name.c_str(), purse);',
    '            log.add(buf);',
    '            return;',
    '        }',
    '        if (rules::thfPocketsVictimNotices(roll, chance)) {',
    '            // noticed: the watch fine (a tenth)',
    '            int fine = party.gold / 10;',
    '            party.gold -= fine;',
    '            char buf[96];',
    '            snprintf(buf, sizeof buf,',
    '                     "A passerby notices the attempt - "',
    '                     "the watch takes %d gp.", fine);',
    '            log.add(buf);',
    '            return;',
    '        }',
    '        log.add("The lift fails, but nobody notices.");',
    '    }',
])
for t in (SS_INC_OLD, SS_INC_NEW, SS_CITY_OLD, SS_CITY_NEW,
          SS_TAIL_OLD, SS_TAIL_NEW):
    clean(t, 78)

p = 'game/state_sea.cpp'
s = rd(p)
if 'AppState::cityPickPockets' in s:
    already.append('state_sea.cpp: the roll + the key line')
else:
    assert s.count(SS_INC_OLD) == 1, 'ss include anchor not unique'
    assert s.count(SS_CITY_OLD) == 1, 'ss city anchor not unique'
    assert s.count(SS_TAIL_OLD) == 1, 'ss tail anchor not unique'
    assert 'thfPocketsChanceTenths' not in s, 'ss marker collision'
    s = s.replace(SS_INC_OLD, SS_INC_NEW)
    s = s.replace(SS_CITY_OLD, SS_CITY_NEW)
    s = s.replace(SS_TAIL_OLD, SS_TAIL_NEW)
    wr(p, s)
    applied.append('state_sea.cpp: the roll + the key line')
s = rd(p)
assert s.count('void AppState::cityPickPockets(){') == 1, 'patch c method'
assert 'rules::thfPocketsChanceTenths(' in s, 'patch c chance seam'
assert 'rules::thfPocketsVictimNotices(roll, chance)' in s, 'patch c notice seam'
assert s.count('rules/startmoney.h') == 1, 'patch c startmoney include'
assert s.count('rules/thieffunc.h') == 1, 'patch c thieffunc include'
assert '[P] pick ' in s, 'patch c key line'
assert s.count('log.add(line);') == 1, 'patch c ate the flavor tail'
assert 'rollCityEncounter' in s, 'patch c ate the excursion'
assert 'cityNobleKind' in s, 'patch c ate the noble'
assert 'You walk the streets of the city.' in s, 'patch c ate enterCity'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) adnd1.cpp: the [P] city key ----
AD_CMT_OLD = NL.join([
    '                // R70: city street keys - [1] day excursion,',
    '                // [2] night excursion, [B]/Esc back to town',
])
AD_CMT_NEW = NL.join([
    '                // R70: city street keys - [1] day excursion,',
    '                // [2] night excursion, [P] pick pockets,',
    '                // [B]/Esc back to town',
])
AD_KEY_OLD = NL.join([
    '                        g_app.cityExcursion(dm::CITY_NIGHT);',
    '                        break;',
])
AD_KEY_NEW = NL.join([
    '                        g_app.cityExcursion(dm::CITY_NIGHT);',
    '                        break;',
    '',
    '                    // R303: the thief street lift',
    '                    case ' + Q + 'P' + Q + ':',
    '                    case ' + Q + 'p' + Q + ':',
    '                        g_app.cityPickPockets();',
    '                        break;',
])
AD_PAINT_OLD = NL.join([
    '    snprintf(line, sizeof line, "[2] An excursion by night");',
    '    TextOutA(dc, 20, 120, line, (int)strlen(line));',
])
AD_PAINT_NEW = NL.join([
    '    snprintf(line, sizeof line, "[2] An excursion by night");',
    '    TextOutA(dc, 20, 120, line, (int)strlen(line));',
    '    snprintf(line, sizeof line, "[P] Pick pockets");',
    '    TextOutA(dc, 20, 144, line, (int)strlen(line));',
])
for t in (AD_CMT_OLD, AD_CMT_NEW, AD_KEY_OLD, AD_PAINT_OLD,
          AD_PAINT_NEW):
    clean(t, 78)
clean(AD_KEY_NEW, 78, allow_apos=True)

p = 'adnd1.cpp'
s = rd(p)
if 'g_app.cityPickPockets();' in s:
    already.append('adnd1.cpp: the [P] city key')
else:
    assert s.count(AD_CMT_OLD) == 1, 'ad comment anchor not unique'
    assert s.count(AD_KEY_OLD) == 1, 'ad key anchor not unique'
    assert s.count(AD_PAINT_OLD) == 1, 'ad paint anchor not unique'
    assert 'cityPickPockets' not in s, 'ad marker collision'
    s = s.replace(AD_CMT_OLD, AD_CMT_NEW)
    s = s.replace(AD_KEY_OLD, AD_KEY_NEW)
    s = s.replace(AD_PAINT_OLD, AD_PAINT_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the [P] city key')
s = rd(p)
assert s.count('g_app.cityPickPockets();') == 1, 'patch d the call'
assert (NL.join(['                    case ' + Q + 'P' + Q + ':',
                 '                    case ' + Q + 'p' + Q + ':',
                 '                        g_app.cityPickPockets();'])
        in s), 'patch d the case pair'
assert s.count('g_app.cityExcursion(dm::CITY_NIGHT);') == 1, 'patch d excursion'
assert s.count('g_app.leaveCity();') == 1, 'patch d leaveCity'
assert s.count('"[P] Pick pockets"') == 1, 'patch d the screen line'
assert s.count('R70: city street keys') == 1, 'patch d the comment'
assert '"[B]/[Esc] back to town"' in s, 'patch d ate the paint tail'
assert 'drawCity' in s, 'patch d ate the painter'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) regtest.cpp: the R303 audit pair ----
RT_OLD = NL.join([
    '        printf("R302 thief silence engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_R303A = NL.join([
    '    // ---- R303: the thief pockets seam audit ----',
    '    // The street-site seams: the victim cut',
    '    // fold (the potential victim reduces the',
    '    // chance 5 percent per level above the',
    '    // 3rd - the cut may drive the chance below',
    '    // zero) and the printed notice band (a',
    '    // failed score 21 percent or more above',
    '    // the chance means the victim notices).',
    '    // The printed worked example walks live: the',
    '    // 12th level half-elf (race 4) with 18',
    '    // dexterity reads the printed 120 percent,',
    '    // cut to 75 by a 12th level victim, and',
    '    // reads noticed from 96.',
    '    {',
    '        int bad = 0;',
    '        // the printed worked example: the 1200',
    '        // tenths chance cut to 750',
    '        if (rules::thfPocketsChanceTenths(12, 4, 18, 12)',
    '            != 750) ++bad;',
    '        // no cut at the 3rd, the printed -5 at',
    '        // the 4th',
    '        if (rules::thfPocketsChanceTenths(12, 4, 18, 3)',
    '            != 1200) ++bad;',
    '        if (rules::thfPocketsChanceTenths(12, 4, 18, 4)',
    '            != 1150) ++bad;',
    '        // the cut may cross zero: the level 1',
    '        // human dex 9 base 150 reads -200',
    '        // against a 10th level victim',
    '        if (rules::thfPocketsChanceTenths(1, 0, 9, 10)',
    '            != -200) ++bad;',
    '        // the notice band: the printed 75 chance',
    '        // reads noticed from 96 (95 does not)',
    '        if (rules::thfPocketsVictimNotices(959, 750) ||',
    '            !rules::thfPocketsVictimNotices(960, 750)',
    '            ) ++bad;',
    '        // a plain fail inside the band stays',
    '        // quiet; the negative chance reads',
    '        // noticed from 10 (9 does not)',
    '        if (rules::thfPocketsVictimNotices(755, 750) ||',
    '            !rules::thfPocketsVictimNotices(10, -200) ||',
    '            rules::thfPocketsVictimNotices(9, -200)',
    '            ) ++bad;',
    '        printf("R303a thief pockets seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_R303 = NL.join([
    '    // ---- R303: the thief pockets engine audit ----',
    '    // The wired street roll on pinned seeds (the',
    '    // R301/R302 replica convention - the splice',
    '    // sandbox compiles nothing; the replica walked',
    '    // every draw first): the first living thief',
    '    // draws the passerby trade and level, one',
    '    // printed percentile, and the branch lands -',
    '    // the R190 purse lift on success (the trade',
    '    // dice), the quiet fail, the watch fine on a',
    '    // noticed fail (the seed 127 passerby reads',
    '    // 6th level: the cut fires - without it the',
    '    // seed reads the quiet band). The gates ride',
    '    // too: no living thief, the mode gate, the',
    '    // dead-thief skip.',
    '    {',
    '        int bad = 0;',
    '        // no living thief - the fallen Rook draws',
    '        // nothing; the gate line reads',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_CITY;',
    '            Character f;',
    '            f.name = "Fighter";',
    '            f.classIndex = 0; f.level = 1;',
    '            f.hp = 30; f.maxHp = 30;',
    '            st.party.members.push_back(f);',
    '            Character d;',
    '            d.name = "Rook";',
    '            d.classIndex = 3; d.level = 7;',
    '            d.hp = 0; d.maxHp = 30;',
    '            st.party.members.push_back(d);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.cityPickPockets();',
    '            if (st.log.get(0).find("No thief walks")',
    '                == std::string::npos) ++bad;',
    '            if (st.party.gold != 0) ++bad;',
    '        }',
    '        // the mode gate - MODE_TOWN reads nothing',
    '        // (the same seed would lift 140 with the',
    '        // gate broken)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_TOWN;',
    '            Character t;',
    '            t.name = "Sly";',
    '            t.classIndex = 3; t.level = 17;',
    '            t.race = 0;',
    '            t.abilities.dex = 18;',
    '            t.hp = 30; t.maxHp = 30;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.rng.seed(21);',
    '            st.cityPickPockets();',
    '            if (st.log.get(0).find("lifts")',
    '                != std::string::npos) ++bad;',
    '            if (st.party.gold != 0) ++bad;',
    '        }',
    '        // seed 21: success - the passerby reads a',
    '        // fighter trade (the 5d4 x 10 purse), the',
    '        // percentile 955 lands under the 1350',
    '        // tenths chance (level 17 human 18 dex)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_CITY;',
    '            Character t;',
    '            t.name = "Sly";',
    '            t.classIndex = 3; t.level = 17;',
    '            t.race = 0;',
    '            t.abilities.dex = 18;',
    '            t.hp = 30; t.maxHp = 30;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.rng.seed(21);',
    '            st.cityPickPockets();',
    '            if (st.party.gold != 140) ++bad;',
    '            if (st.log.get(0).find("lifts 140 gp")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("watch")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // seed 19: the quiet fail at the boundary -',
    '        // the percentile 150 reads exactly the',
    '        // 150 tenths chance (level 1 human dex 9,',
    '        // the passerby 1st): a fail, under the',
    '        // notice band',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_CITY;',
    '            Character t;',
    '            t.name = "Sly";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.race = 0;',
    '            t.abilities.dex = 9;',
    '            t.hp = 30; t.maxHp = 30;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.party.gold = 777;',
    '            st.rng.seed(19);',
    '            st.cityPickPockets();',
    '            if (st.party.gold != 777) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "fails, but nobody notices")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // seed 127: the noticed fail with the cut',
    '        // firing - the passerby reads 6th level,',
    '        // the cut drives the 150 base to 0 and',
    '        // the percentile 256 reads noticed; the',
    '        // watch fine takes a tenth of 5000',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_CITY;',
    '            Character t;',
    '            t.name = "Sly";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.race = 0;',
    '            t.abilities.dex = 9;',
    '            t.hp = 30; t.maxHp = 30;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.party.gold = 5000;',
    '            st.rng.seed(127);',
    '            st.cityPickPockets();',
    '            if (st.party.gold != 4500) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "the watch takes 500 gp")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("lifts")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // seed 11: the fallen Rook skips, Sly rolls',
    '        // - the passerby reads a magic-user trade',
    '        // (the 2d4 x 10 purse) and the percentile',
    '        // 21 lands under the cut chance 1200 (the',
    '        // 6th level passerby cuts the 1350)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_CITY;',
    '            Character d;',
    '            d.name = "Rook";',
    '            d.classIndex = 3; d.level = 7;',
    '            d.hp = 0; d.maxHp = 30;',
    '            st.party.members.push_back(d);',
    '            Character t;',
    '            t.name = "Sly";',
    '            t.classIndex = 3; t.level = 17;',
    '            t.race = 0;',
    '            t.abilities.dex = 18;',
    '            t.hp = 30; t.maxHp = 30;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.rng.seed(11);',
    '            st.cityPickPockets();',
    '            if (st.party.gold != 60) ++bad;',
    '            if (st.log.get(0).find("Sly lifts 60 gp")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("Rook")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        printf("R303 thief pockets engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEW = NL.join([
    '        printf("R302 thief silence engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    RT_R303A,
    RT_R303,
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_OLD, RT_R303A, RT_R303):
    for ln in t.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
        assert len(ln) <= 76, 'audit line too long: ' + ln
        assert chr(39) not in ln, 'apostrophe in audit'
        if 'printf("' in ln:
            assert ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R303 thief pockets engine audit' in s:
    already.append('regtest.cpp: the R303 audit pair')
else:
    assert s.count('audit: bad') == 223, 'rt census not 223'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'R303a thief pockets seam audit' not in s, 'rt marker collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the R303 audit pair')
s = rd(p)
assert s.count('audit: bad') == 225, 'patch e census wrong'
assert s.count('R303a thief pockets seam audit') == 1, 'patch e R303a marker'
assert s.count('R303 thief pockets engine audit') == 1, 'patch e R303 marker'
assert s.count('R303: the thief pockets seam audit') == 1, 'patch e R303a head'
assert s.count('R303: the thief pockets engine audit') == 1, 'patch e R303 head'
assert s.count('R227: the wis mental save wiring audit') == 1, 'patch e ate R227'
assert s.count('R302 thief silence engine audit') == 1, 'patch e ate R302'
assert 'R301 thief trap rolls engine audit' in s, 'patch e ate R301'
assert s.count('st.cityPickPockets();') == 6, 'patch e call count'
assert s.count('thfPocketsChanceTenths(12, 4, 18, 12)') == 1, 'patch e example'
assert s.count('rules/thieffunc.h') >= 1, 'patch e the include'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) tools/phb_gap_report.md: the wiring-arc box ----
GR_HEAD_OLD = NL.join([
    '      R302: the surprise site rolls the',
    '      move silently draw; the rest stay',
    '      data) -',
])
GR_HEAD_NEW = NL.join([
    '      R302: the surprise site rolls the',
    '      move silently draw; R303: the street',
    '      site rolls the pick pockets draw;',
    '      the rest stay data) -',
])
GR_INS_OLD = NL.join([
    '      convention). Census 223. The ledger',
    '      holds ZERO open items.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The thief pockets wired - WIRED',
    '      R303:** the pick pockets column gains',
    '      its first engine site - the city',
    '      streets command ([P], the R70 shell).',
    '      rules/thieffunc.h gains',
    '      thfPocketsChanceTenths (the printed',
    '      base folded with the printed victim',
    '      cut - the potential victim reduces',
    '      the chance 5 percent per level above',
    '      the 3rd; the cut may cross zero) and',
    '      thfPocketsVictimNotices (the printed',
    '      notice band - a fail 21 percent or',
    '      more above the chance means the',
    '      victim notices; the worked example',
    '      walks live: 120 cut to 75, noticed',
    '      from 96). game/state_sea.cpp gains',
    '      cityPickPockets: the FIRST living',
    '      thief draws the passerby trade (d4,',
    '      the four engine classes) and level',
    '      (d6), then one printed percentile;',
    '      success lifts the purse, a noticed',
    '      fail draws the watch, a plain fail',
    '      reads quiet. JUDGMENTS (the print',
    '      leaves them open): the passerby',
    '      purse reads the R190 starting money',
    '      dice of the trade (the engine only',
    '      prints money by class; the printed',
    '      random item has no stranger',
    '      inventory to draw from), and a',
    '      noticed attempt costs a watch fine',
    '      of a tenth of the company purse (the',
    '      R133 greed convention). adnd1.cpp',
    '      keys [P] (the city switch and the',
    '      screen). The remaining functions',
    '      stay data (open locks - the dungeon',
    '      doors carry no lock data; hide in',
    '      shadows, hear noise, climb walls',
    '      and read languages - no engine',
    '      site; hear noise keeps the R120',
    '      portal listen convention, not the',
    '      R298 percentile). The R303a battery',
    '      audit walks the cut fold and the',
    '      notice band (evaluable - verified',
    '      by audit_eval); the R303 engine',
    '      audit pins every scenario on seeded',
    '      sequences (the R301 replica',
    '      convention). Census 225. The ledger',
    '      holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      convention). Census 223. The ledger',
    '      holds ZERO open items.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR_HEAD_OLD, GR_HEAD_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The thief pockets wired' in s:
    already.append('phb_gap_report.md: the wiring-arc box')
else:
    assert s.count(GR_HEAD_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    assert 'Census 225.' not in s, 'gr marker collision'
    s = s.replace(GR_HEAD_OLD, GR_HEAD_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the wiring-arc box')
s = rd(p)
assert s.count('The thief pockets wired') == 1, 'patch f box'
assert s.count('R303: the street') == 1, 'patch f head amend'
assert s.count('holds ZERO open items') == 3, 'patch f zero-item notes'
assert s.count('Census 225.') == 1, 'patch f census note'
assert s.count('Census 223.') == 1, 'patch f R302 census'
assert 'Census 221.' in s, 'patch f ate the R301 census'
assert 'Census 215.' in s, 'patch f ate the R298 census'
assert 'Census 217.' in s, 'patch f ate the R299 census'
assert 'Census 219.' in s, 'patch f ate the R300 census'
assert s.count('PINNED R298') == 1, 'patch f ate the R298 box head'
assert 'The thief silence wired' in s, 'patch f ate the R302 box'
assert 'WIRED R299' in s, 'patch f ate the R299 entry'
assert 'R299 SCOPE PASS' in s, 'patch f ate the R299 pass'
assert '## Out of engine scope' in s, 'patch f ate the scope head'
assert '## R299 the party recordings round' in s, 'patch f ate the R299 head'
assert s.count('- [ ]') == 0, 'patch f opened an item'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- R303 fails/tail ----
if fails:
    print('R303 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 6:
    print('R303 splice: FAIL - expected 6 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R303 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R303 note: 6 patches; the battery census 223 -> 225;')
print('the phb ledger holds ZERO open items')
print('commit: R303: the thief pockets wired (census 225)')

