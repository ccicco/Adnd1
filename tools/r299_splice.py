#!/usr/bin/env python3
# tools/r299_splice.py - R299: the party kit
# weapon recordings wired (the R297 future
# round) and the third scope pass riding.
#
# The R297 simplification note said the party
# roster carries no recordings yet - this is
# that future round. The Character gains
# profWeaponIds; the class kit grant at
# creation is the initial proficiency choice
# set (the engine has no choice UI; the
# added-slot choices stay a future round).
# This round wires it:
#
#   (a) rules/weaponprof.h - the R299 seam:
#       wpfKitRecordsMelee (every kit carries
#       a melee arm), wpfKitRecordsRanged (the
#       thief-base kits carry the sling - the
#       R28 pin; a subclass kit rides its base
#       kit) and wpfKitGrantCount (the count
#       the engine grant must agree with).
#       The stale roster note amended.
#   (b) game/party.h - the Character field,
#       the grantKitProficiencies method (the
#       canon kit ids; the list CLEARS first -
#       a profession change re-grants the new
#       kit), the toActor copy, the
#       switchProfession and beginBardStudies
#       re-grants.
#   (c) game/appstate.h - makeMember grants at
#       creation; makeSubclassMember re-grants
#       after the monk staff overlay.
#   (d) game/state_core.cpp - the save load
#       rebuild (the R33 v1 convention: the
#       recordings are not saved; a loaded
#       member re-reads the class kit grant).
#   (e) ai/actor.h - the stale roster comment
#       amended (the list is now live data).
#   (f) regtest.cpp - the R299 audit pair (the
#       battery census 215 -> 217): the seam
#       audit (evaluable - verified by
#       audit_eval) and the engine audit (the
#       R233a/R233 precedent - the factories,
#       the switches, the toActor copy, the
#       live proficiency gate; the C++ battery
#       is the gate).
#   (g) tools/phb_gap_report.md - the R297
#       simplification note amended, the R299
#       wiring entry, the third scope pass
#       recorded (ONE new open item - the
#       equipment cost columns, the R300
#       candidate) and the Appendix IV planes
#       deferral (the Manual of the Planes
#       decision) noted at the R296 list.
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS), and no CONTENT string embeds
# an apostrophe, non-ASCII or (for the gap
# report) a line past 57 columns.
# Commit: "R299: the party kit weapon
# recordings wired and the third scope pass
# (census 217)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/weaponprof.h: the seam + the note amend ----
WPF_NOTE_OLD = NL.join([
    '//   - the slot COUNTS are data (the engine',
    '//     records no weapon choices yet beyond the',
    '//     kitNpc grant; the party roster carries',
    '//     none - a future round); the PENALTY is',
])
WPF_NOTE_NEW = NL.join([
    '//   - the slot COUNTS are data (the engine',
    '//     records no choices beyond the kit grants;',
    '//     the party roster records its class kit at',
    '//     creation - R299); the PENALTY is',
])
WPF_SEAM = NL.join([
    '',
    'inline int wpfKitRecordsMelee() {',
    '    // R299: every class kit carries a melee arm',
    '    // - the kit grant records it as an initial',
    '    // proficiency choice (the engine has no',
    '    // choice UI; the added slots stay a future',
    '    // choice round)',
    '    return 1;',
    '}',
    '',
    'inline int wpfKitRecordsRanged(int classIndex,',
    '                               int subclass) {',
    '    // R299: the kit missile slot - the thief-base',
    '    // kits carry the sling (the R28 creation pin)',
    '    // and record it; a subclass kit rides its',
    '    // base-class kit (the makeSubclassMember',
    '    // convention; the monk staff is a melee arm).',
    '    // The subclass mapping mirrors',
    '    // subclassRuntimeBase (the agreement is',
    '    // pinned by the R299 battery audit).',
    '    int base = classIndex;',
    '    if (subclass == 2) base = 2;   // druid',
    '    if (subclass == 3) base = 1;   // illusionist',
    '    if (subclass == 4) base = 3;   // assassin',
    '    if (base == 3) return 1;   // the thief sling',
    '    return 0;',
    '}',
    '',
    'inline int wpfKitGrantCount(int classIndex,',
    '                            int subclass) {',
    '    // R299: the kit-grant recording count - the',
    '    // melee slot plus the ranged slot when the',
    '    // kit carries one (the Character grant,',
    '    // game/party.h; the engine kit ids are',
    '    // game-layer data, the COUNTS are the seam)',
    '    return wpfKitRecordsMelee() +',
    '           wpfKitRecordsRanged(classIndex, subclass);',
    '}',
])
clean(WPF_NOTE_OLD, 100)
clean(WPF_NOTE_NEW, 100)
clean(WPF_SEAM, 100)

p = 'rules/weaponprof.h'
s = rd(p)
if 'wpfKitGrantCount' in s:
    already.append('weaponprof.h: the R299 seam')
else:
    assert s.count(WPF_NOTE_OLD) == 1, 'wpf note anchor not unique'
    assert s.count('}  // namespace rules') == 1, 'wpf close not unique'
    s = s.replace(WPF_NOTE_OLD, WPF_NOTE_NEW)
    s = s.replace('}  // namespace rules',
                  WPF_SEAM + NL + '}  // namespace rules')
    wr(p, s)
    applied.append('weaponprof.h: the R299 seam')
s = rd(p)
assert 'wpfKitGrantCount' in s, 'patch a failed'
assert s.count('inline int wpfKit') == 3, 'patch a accessor count'
assert 'the party roster carries' not in s, 'patch a stale note'
assert 'wpfNonProfHitAdj' in s, 'patch a ate the R297 seam'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/party.h: the field, the method, the copies ----
P_FIELD_OLD = NL.join([
    '    // R81: Ring of Protection AC bonus (0 = none worn)',
    '    int ringPlus = 0;',
])
P_FIELD_NEW = NL.join([
    '    // R81: Ring of Protection AC bonus (0 = none worn)',
    '    int ringPlus = 0;',
    '',
    '    // R299: the recorded weapon proficiency slots',
    '    // (the PHB Weapon Proficiency Table). The kit',
    '    // grant at creation is the initial choice set;',
    '    // the added slots stay a future choice round.',
    '    // EMPTY = the pre-R297 convention (never pays).',
    '    // Holds items::WeaponId values.',
    '    std::vector<int> profWeaponIds;',
])
P_KNOW_OLD = NL.join([
    '    bool knowsSpell(int id) const {',
    '        for (int s : knownSpells)',
    '            if (s == id) return true;',
    '        return false;',
    '    }',
])
P_METHOD_NEW = NL.join([
    '    bool knowsSpell(int id) const {',
    '        for (int s : knownSpells)',
    '            if (s == id) return true;',
    '        return false;',
    '    }',
    '',
    '    // R299: record the class kit as the initial',
    '    // weapon proficiency choices (the engine has',
    '    // no choice UI - the kit grant IS the initial',
    '    // slots; the counts stay data at the future',
    '    // choice round). The list CLEARS first: a',
    '    // profession change or subclass overlay',
    '    // re-grants the new kit (the old choices do',
    '    // not persist - recorded simplification).',
    '    // Called at creation (makeMember), the',
    '    // subclass overlay (makeSubclassMember), the',
    '    // profession switch, the bard studies and',
    '    // the save load rebuild (state_core.cpp).',
    '    void grantKitProficiencies() {',
    '        profWeaponIds.clear();',
    '        if (bard) {',
    '            // the bard career kit (Appendix II): the',
    '            // long sword, a permitted Table III arm',
    '            profWeaponIds.push_back(',
    '                (int)items::WPN_LONG_SWORD);',
    '            return;',
    '        }',
    '        if (subclass == rules::SUB_MONK) {',
    '            // the monk kit override (R230): the staff',
    '            profWeaponIds.push_back(',
    '                (int)items::WPN_QUARTERSTAFF);',
    '            return;',
    '        }',
    '        switch (classIndex) {',
    '            case rules::CLASS_MAGIC_USER:',
    '                profWeaponIds.push_back(',
    '                    (int)items::WPN_DAGGER);',
    '                break;',
    '            case rules::CLASS_CLERIC:',
    '                profWeaponIds.push_back(',
    '                    (int)items::WPN_MACE);',
    '                break;',
    '            case rules::CLASS_THIEF:',
    '                // the thief kit carries the missile',
    '                // slot (the R28 sling pin)',
    '                profWeaponIds.push_back(',
    '                    (int)items::WPN_SHORT_SWORD);',
    '                profWeaponIds.push_back(',
    '                    (int)items::WPN_SLING);',
    '                break;',
    '            default:',
    '                // the fighter groups and the class',
    '                // default (the attackNumber convention)',
    '                profWeaponIds.push_back(',
    '                    (int)items::WPN_LONG_SWORD);',
    '                break;',
    '        }',
    '    }',
])
P_TOACTOR_OLD = NL.join([
    '        // R33: the spellbook travels with the actor',
    '        a.knownSpells = knownSpells;',
])
P_TOACTOR_NEW = NL.join([
    '        // R33: the spellbook travels with the actor',
    '        a.knownSpells = knownSpells;',
    '        // R299: the recorded proficiency slots travel',
    '        // with the actor (the hitAdjustment gate)',
    '        a.profWeaponIds = profWeaponIds;',
])
P_SWITCH_OLD = NL.join([
    '                rangedWeapon.id = items::WPN_SLING;',
    '                break;',
    '        }',
    '        return true;',
])
P_SWITCH_NEW = NL.join([
    '                rangedWeapon.id = items::WPN_SLING;',
    '                break;',
    '        }',
    '        // R299: the new kit is the new recording',
    '        // (the old choices do not persist)',
    '        grantKitProficiencies();',
    '        return true;',
])
P_BARD_OLD = NL.join([
    '        weapon.id = items::WPN_LONG_SWORD;',
    '        armor.id  = items::ARMOR_LEATHER;',
    '        shield    = false;',
    '    }',
])
P_BARD_NEW = NL.join([
    '        weapon.id = items::WPN_LONG_SWORD;',
    '        armor.id  = items::ARMOR_LEATHER;',
    '        shield    = false;',
    '        // R299: the bard career kit records',
    '        grantKitProficiencies();',
    '    }',
])
for x in (P_FIELD_NEW, P_METHOD_NEW, P_TOACTOR_NEW,
          P_SWITCH_NEW, P_BARD_NEW):
    clean(x, 78)
clean(P_FIELD_OLD, 78)
clean(P_KNOW_OLD, 78)
clean(P_TOACTOR_OLD, 78)
clean(P_SWITCH_OLD, 78)
clean(P_BARD_OLD, 78)

p = 'game/party.h'
s = rd(p)
if 'grantKitProficiencies' in s:
    already.append('party.h: the grant and the copies')
else:
    assert s.count(P_FIELD_OLD) == 1, 'party field anchor not unique'
    assert s.count(P_KNOW_OLD) == 1, 'party knows anchor not unique'
    assert s.count(P_TOACTOR_OLD) == 1, 'party toActor anchor not unique'
    assert s.count(P_SWITCH_OLD) == 1, 'party switch anchor not unique'
    assert s.count(P_BARD_OLD) == 1, 'party bard anchor not unique'
    s = s.replace(P_FIELD_OLD, P_FIELD_NEW)
    s = s.replace(P_KNOW_OLD, P_METHOD_NEW)
    s = s.replace(P_TOACTOR_OLD, P_TOACTOR_NEW)
    s = s.replace(P_SWITCH_OLD, P_SWITCH_NEW)
    s = s.replace(P_BARD_OLD, P_BARD_NEW)
    wr(p, s)
    applied.append('party.h: the grant and the copies')
s = rd(p)
assert s.count('grantKitProficiencies') == 3, 'patch b call count wrong'
assert s.count('std::vector<int> profWeaponIds;') == 1, 'patch b field'
assert s.count('a.profWeaponIds = profWeaponIds;') == 1, 'patch b copy'
assert 'canSwitchProfession' in s, 'patch b ate the switch gates'
assert 'beginBardStudies' in s, 'patch b ate the bard gates'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/appstate.h: the factory grants ----
A_MAKE_OLD = NL.join([
    '        // R35: everyone starts with a full quiver (20 missiles)',
    '        c.missileAmmo = 20;',
    '        return c;',
])
A_MAKE_NEW = NL.join([
    '        // R35: everyone starts with a full quiver (20 missiles)',
    '        c.missileAmmo = 20;',
    '        // R299: the kit grant records the initial',
    '        // proficiency choices',
    '        c.grantKitProficiencies();',
    '        return c;',
])
A_MONK_OLD = NL.join([
    '        if (sub == rules::SUB_MONK) {',
    '            c.weapon.id = items::WPN_QUARTERSTAFF;',
    '            c.armor.id = items::ARMOR_NONE_EQUIPPED;',
    '            c.shield = false;',
    '        }',
    '        return c;',
])
A_MONK_NEW = NL.join([
    '        if (sub == rules::SUB_MONK) {',
    '            c.weapon.id = items::WPN_QUARTERSTAFF;',
    '            c.armor.id = items::ARMOR_NONE_EQUIPPED;',
    '            c.shield = false;',
    '        }',
    '        // R299: the subclass overlay re-records (the',
    '        // monk staff; the others re-read the base kit)',
    '        c.grantKitProficiencies();',
    '        return c;',
])
for x in (A_MAKE_NEW, A_MONK_NEW):
    clean(x, 78)
clean(A_MAKE_OLD, 78)
clean(A_MONK_OLD, 78)

p = 'game/appstate.h'
s = rd(p)
if s.count('grantKitProficiencies') == 2:
    already.append('appstate.h: the factory grants')
else:
    assert s.count(A_MAKE_OLD) == 1, 'makeMember anchor not unique'
    assert s.count(A_MONK_OLD) == 1, 'monk overlay anchor not unique'
    s = s.replace(A_MAKE_OLD, A_MAKE_NEW)
    s = s.replace(A_MONK_OLD, A_MONK_NEW)
    wr(p, s)
    applied.append('appstate.h: the factory grants')
s = rd(p)
assert s.count('grantKitProficiencies') == 2, 'patch c call count wrong'
assert 'makeMultiMember' in s, 'patch c ate the multi factory'
assert 'makeSubclassMember' in s, 'patch c ate the subclass factory'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_core.cpp: the load rebuild ----
S_LOAD_OLD = NL.join([
    '        // commit: career restored, fresh dungeon at saved depth',
    '        p.formed = true;',
])
S_LOAD_NEW = NL.join([
    '        // R299: the kit-proficiency rebuild (the R33',
    '        // v1 convention) - the recordings are not',
    '        // saved; a loaded member re-reads the class',
    '        // kit grant',
    '        for (auto& c : p.members)',
    '            if (c.profWeaponIds.empty())',
    '                c.grantKitProficiencies();',
    '',
    '        // commit: career restored, fresh dungeon at saved depth',
    '        p.formed = true;',
])
clean(S_LOAD_OLD, 78)
clean(S_LOAD_NEW, 78)

p = 'game/state_core.cpp'
s = rd(p)
if 'the kit-proficiency rebuild' in s:
    already.append('state_core.cpp: the load rebuild')
else:
    assert s.count(S_LOAD_OLD) == 1, 'load commit anchor not unique'
    wr(p, s.replace(S_LOAD_OLD, S_LOAD_NEW))
    applied.append('state_core.cpp: the load rebuild')
s = rd(p)
assert s.count('grantKitProficiencies') == 1, 'patch d call count wrong'
assert 'adnd1.sav is corrupt (member).' in s, 'patch d ate the load gate'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) ai/actor.h: the stale comment amend ----
H_NOTE_OLD = NL.join([
    '    // as proficient; no penalty paid) - the party',
    '    // roster carries no recordings yet. The kitNpc',
    '    // NPCs record their kit weapons. A held weapon',
])
H_NOTE_NEW = NL.join([
    '    // as proficient; no penalty paid). The roster',
    '    // records the class kit grant at creation',
    '    // (R299: game/party.h); a loaded save rebuilds',
    '    // it (game/state_core.cpp); the kitNpc NPCs',
    '    // record their kit weapons. A held weapon',
])
clean(H_NOTE_OLD, 78)
clean(H_NOTE_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'a loaded save rebuilds' in s:
    already.append('actor.h: the comment amend')
else:
    assert s.count(H_NOTE_OLD) == 1, 'actor note anchor not unique'
    wr(p, s.replace(H_NOTE_OLD, H_NOTE_NEW))
    applied.append('actor.h: the comment amend')
s = rd(p)
assert 'roster carries no recordings yet' not in s, 'patch e stale note'
assert 'proficientWithWeapon' in s, 'patch e ate the gate method'
assert 'R28: missile weapon slot' in s, 'patch e ate the R28 note'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) regtest.cpp: the R299 audit pair ----
SEAM_AUDIT = NL.join([
    '    // ---- R299a: the party kit recordings seam audit ----',
    '    // The kit-grant recording convention (the R299',
    '    // rules/weaponprof.h seam): the melee slot',
    '    // records with every class kit, the ranged slot',
    '    // where the kit carries a missile (the thief',
    '    // rows - the R28 sling pin), the grant count',
    '    // per class pair, the subclass kits ride their',
    '    // base rows, the unknown-subclass fallback',
    '    // reads the base kit, and the identities (the',
    '    // count is melee plus ranged; the missile kits',
    '    // are exactly the printed thief rows). The',
    '    // ENGINE side (the Character grant, the',
    '    // toActor copy, the load rebuild) is the',
    '    // engine audit below.',
    '    {',
    '        int bad = 0;',
    '        // the melee slot: every class kit records',
    '        if (rules::wpfKitRecordsMelee() != 1) ++bad;',
    '        // the ranged slot: the thief-base kits',
    '        // carry the sling; the other base kits',
    '        // record melee only',
    '        if (rules::wpfKitRecordsRanged(0, -1) != 0 ||',
    '            rules::wpfKitRecordsRanged(1, -1) != 0 ||',
    '            rules::wpfKitRecordsRanged(2, -1) != 0 ||',
    '            rules::wpfKitRecordsRanged(3, -1) != 1) ++bad;',
    '        // the subclass kits ride the base kit: the',
    '        // paladin, ranger and monk record the melee',
    '        // arm only; the druid and illusionist ride',
    '        // their bases; the assassin carries the',
    '        // thief sling',
    '        if (rules::wpfKitRecordsRanged(0, 0) != 0 ||',
    '            rules::wpfKitRecordsRanged(0, 1) != 0 ||',
    '            rules::wpfKitRecordsRanged(0, 5) != 0 ||',
    '            rules::wpfKitRecordsRanged(2, 2) != 0 ||',
    '            rules::wpfKitRecordsRanged(1, 3) != 0 ||',
    '            rules::wpfKitRecordsRanged(3, 4) != 1) ++bad;',
    '        // the unknown subclass reads the base kit',
    '        // (the wpfRowFor fallback convention)',
    '        if (rules::wpfKitRecordsRanged(3, 99) != 1 ||',
    '            rules::wpfKitRecordsRanged(3, -5) != 1 ||',
    '            rules::wpfKitRecordsRanged(0, 99) != 0 ||',
    '            rules::wpfKitRecordsRanged(0, -5) != 0) ++bad;',
    '        // the grant count: the four base pairs',
    '        if (rules::wpfKitGrantCount(0, -1) != 1 ||',
    '            rules::wpfKitGrantCount(1, -1) != 1 ||',
    '            rules::wpfKitGrantCount(2, -1) != 1 ||',
    '            rules::wpfKitGrantCount(3, -1) != 2) ++bad;',
    '        // the grant count identity: melee plus',
    '        // ranged, every subclass pair',
    '        for (int s = 0; s < 6; ++s)',
    '            if (rules::wpfKitGrantCount(',
    '                    rules::subclassRuntimeBase(s), s) !=',
    '                rules::wpfKitRecordsMelee() +',
    '                rules::wpfKitRecordsRanged(',
    '                    rules::subclassRuntimeBase(s), -1))',
    '                ++bad;',
    '        // the base agreement: the seam mapping',
    '        // reads the subclassRuntimeBase pin',
    '        for (int s = 0; s < 6; ++s)',
    '            if (rules::wpfKitRecordsRanged(0, s) !=',
    '                rules::wpfKitRecordsRanged(',
    '                    rules::subclassRuntimeBase(s), -1))',
    '                ++bad;',
    '        // the row identity: the kits that carry',
    '        // the missile are exactly the printed',
    '        // thief rows (THIEF 7 and ASSASSIN 8)',
    '        for (int c = 0; c < 4; ++c)',
    '            if (rules::wpfKitRecordsRanged(c, -1) !=',
    '                ((rules::wpfRowFor(c, -1) == 7 ||',
    '                  rules::wpfRowFor(c, -1) == 8)',
    '                     ? 1 : 0)) ++bad;',
    '        printf("R299a party kit recordings seam audit: bad %d'
    + BS + 'n", bad);',
    '    }',
])
ENGINE_AUDIT = NL.join([
    '    // ---- R299: the party kit recordings engine audit ----',
    '    // The Character kit grant (the makeMember,',
    '    // makeSubclassMember, switchProfession and bard',
    '    // factories), the grant-seam count agreement,',
    '    // the toActor copy and the live proficiency',
    '    // gate (an engine audit - the C++ battery is',
    '    // the gate; the save load rebuild calls the',
    '    // same method - recorded).',
    '    {',
    '        int bad = 0;',
    '        // the base kits: the grant records the kit',
    '        // arm and the count agrees with the seam',
    '        {',
    '            CreationState cr;',
    '            cr.racePick = 0;   // human',
    '            cr.rolled.str = 12; cr.rolled.int_ = 12;',
    '            cr.rolled.wis = 12; cr.rolled.dex = 12;',
    '            cr.rolled.con = 12; cr.rolled.cha = 12;',
    '            Character f = cr.makeMember(0);',
    '            if (f.profWeaponIds.size() != 1) ++bad;',
    '            if (f.profWeaponIds[0] !=',
    '                (int)items::WPN_LONG_SWORD) ++bad;',
    '            if ((int)f.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(0, -1)) ++bad;',
    '            Character m = cr.makeMember(1);',
    '            if (m.profWeaponIds.size() != 1 ||',
    '                m.profWeaponIds[0] !=',
    '                (int)items::WPN_DAGGER) ++bad;',
    '            if ((int)m.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(1, -1)) ++bad;',
    '            Character cl = cr.makeMember(2);',
    '            if (cl.profWeaponIds.size() != 1 ||',
    '                cl.profWeaponIds[0] !=',
    '                (int)items::WPN_MACE) ++bad;',
    '            if ((int)cl.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(2, -1)) ++bad;',
    '            Character t = cr.makeMember(3);',
    '            if (t.profWeaponIds.size() != 2) ++bad;',
    '            if (t.profWeaponIds[0] !=',
    '                (int)items::WPN_SHORT_SWORD ||',
    '                t.profWeaponIds[1] !=',
    '                (int)items::WPN_SLING) ++bad;',
    '            if ((int)t.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(3, -1)) ++bad;',
    '        }',
    '        // the subclass overlays: the monk staff,',
    '        // the assassin thief kit (the sling rides)',
    '        {',
    '            CreationState cr;',
    '            cr.racePick = 0;',
    '            cr.rolled.str = 12; cr.rolled.int_ = 12;',
    '            cr.rolled.wis = 12; cr.rolled.dex = 12;',
    '            cr.rolled.con = 12; cr.rolled.cha = 12;',
    '            Character mo =',
    '                cr.makeSubclassMember(rules::SUB_MONK);',
    '            if (mo.subclass != rules::SUB_MONK) ++bad;',
    '            if (mo.profWeaponIds.size() != 1 ||',
    '                mo.profWeaponIds[0] !=',
    '                (int)items::WPN_QUARTERSTAFF) ++bad;',
    '            if ((int)mo.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(0,',
    '                                       rules::SUB_MONK)) ++bad;',
    '            Character as =',
    '                cr.makeSubclassMember(rules::SUB_ASSASSIN);',
    '            if (as.classIndex != 3) ++bad;',
    '            if (as.profWeaponIds.size() != 2 ||',
    '                as.profWeaponIds[1] !=',
    '                (int)items::WPN_SLING) ++bad;',
    '            if ((int)as.profWeaponIds.size() !=',
    '                rules::wpfKitGrantCount(3,',
    '                                       rules::SUB_ASSASSIN)) ++bad;',
    '        }',
    '        // the profession switch: the new kit is',
    '        // the new recording (the old choices do',
    '        // not persist) - the printed fighter to',
    '        // magic-user example',
    '        {',
    '            Character sw;',
    '            sw.race = 0;',
    '            sw.abilities.str = 15;',
    '            sw.abilities.int_ = 17;',
    '            sw.classIndex = 0;',
    '            sw.level = 6;',
    '            sw.hp = sw.maxHp = 40;',
    '            rules::Rng r{1};',
    '            rules::Dice d(r);',
    '            if (!sw.switchProfession(1, d)) ++bad;',
    '            if (sw.profWeaponIds.size() != 1 ||',
    '                sw.profWeaponIds[0] !=',
    '                (int)items::WPN_DAGGER) ++bad;',
    '        }',
    '        // the thief switch: the sling records with',
    '        // the thief kit',
    '        {',
    '            Character sw;',
    '            sw.race = 0;',
    '            sw.abilities.str = 15;',
    '            sw.abilities.dex = 17;',
    '            sw.classIndex = 0;',
    '            sw.level = 6;',
    '            sw.hp = sw.maxHp = 40;',
    '            rules::Rng r{2};',
    '            rules::Dice d(r);',
    '            if (!sw.switchProfession(3, d)) ++bad;',
    '            if (sw.profWeaponIds.size() != 2) ++bad;',
    '            if (sw.profWeaponIds[0] !=',
    '                (int)items::WPN_SHORT_SWORD ||',
    '                sw.profWeaponIds[1] !=',
    '                (int)items::WPN_SLING) ++bad;',
    '        }',
    '        // the bard studies: the long sword kit',
    '        {',
    '            Character bd;',
    '            bd.race = 0;',
    '            bd.classIndex = 3;',
    '            bd.level = 6;',
    '            bd.dualOldClass = 0;',
    '            bd.dualOldLevel = 6;',
    '            bd.abilities.str = 15;',
    '            bd.abilities.wis = 15;',
    '            bd.abilities.dex = 15;',
    '            bd.abilities.cha = 15;',
    '            bd.abilities.int_ = 12;',
    '            bd.abilities.con = 10;',
    '            if (!bd.canBeginBardStudies()) ++bad;',
    '            bd.beginBardStudies();',
    '            if (bd.bard != true) ++bad;',
    '            if (bd.profWeaponIds.size() != 1 ||',
    '                bd.profWeaponIds[0] !=',
    '                (int)items::WPN_LONG_SWORD) ++bad;',
    '        }',
    '        // the load rebuild method: a bare member',
    '        // re-reads the class kit (state_core.cpp',
    '        // calls this on load - the R33 convention)',
    '        {',
    '            Character rb;',
    '            rb.classIndex = 3;',
    '            rb.grantKitProficiencies();',
    '            if (rb.profWeaponIds.size() != 2 ||',
    '                rb.profWeaponIds[0] !=',
    '                (int)items::WPN_SHORT_SWORD) ++bad;',
    '            rb.subclass = rules::SUB_MONK;',
    '            rb.grantKitProficiencies();',
    '            if (rb.profWeaponIds.size() != 1 ||',
    '                rb.profWeaponIds[0] !=',
    '                (int)items::WPN_QUARTERSTAFF) ++bad;',
    '            rb.bard = true;',
    '            rb.grantKitProficiencies();',
    '            if (rb.profWeaponIds.size() != 1 ||',
    '                rb.profWeaponIds[0] !=',
    '                (int)items::WPN_LONG_SWORD) ++bad;',
    '        }',
    '        // the toActor copy: the list travels and',
    '        // the proficiency gate reads it live',
    '        {',
    '            Character e;',
    '            ai::Actor ae = e.toActor();',
    '            if (!ae.profWeaponIds.empty()) ++bad;',
    '            // the empty list: the pre-R297',
    '            // convention (no penalty paid)',
    '            if (!ae.proficientWithWeapon(',
    '                    (int)items::WPN_MACE)) ++bad;',
    '            Character t2;',
    '            t2.classIndex = 3;',
    '            t2.grantKitProficiencies();',
    '            ai::Actor at = t2.toActor();',
    '            if (at.profWeaponIds.size() != 2) ++bad;',
    '            if (!at.proficientWithWeapon(',
    '                    (int)items::WPN_SHORT_SWORD) ||',
    '                !at.proficientWithWeapon(',
    '                    (int)items::WPN_SLING)) ++bad;',
    '            if (at.proficientWithWeapon(',
    '                    (int)items::WPN_MACE)) ++bad;',
    '        }',
    '        printf("R299 party kit recordings engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
for ln in (SEAM_AUDIT + NL + ENGINE_AUDIT).split(NL):
    assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
    assert len(ln) <= 76, 'audit line too long: ' + ln
    assert chr(39) not in ln, 'apostrophe in audit'
    if 'printf' in ln:
        assert ln.count(BS) == 1, 'printf BS count wrong'
    else:
        assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R299a party kit recordings seam audit' in s:
    already.append('regtest.cpp: the R299 audit pair')
else:
    assert s.count('audit: bad') == 215, 'census is not 215'
    r298_tail = ('        printf("R298 thief function take table pins'
                 ' audit: bad %d' + BS
                 + 'n", bad);')
    r227_head = '    // ---- R227: the wis mental save wiring audit ----'
    anchor = r298_tail + NL + '    }' + NL + r227_head
    assert s.count(anchor) == 1, 'regtest block anchor not unique'
    new_region = (r298_tail + NL + '    }' + NL +
                  SEAM_AUDIT + NL + ENGINE_AUDIT + NL + r227_head)
    s = s.replace(anchor, new_region)
    wr(p, s)
    applied.append('regtest.cpp: the R299 audit pair')
s = rd(p)
assert s.count('R299a party kit recordings seam audit') == 1, 'patch f seam'
assert s.count('R299 party kit recordings engine audit') == 1, 'patch f engine'
assert s.count('audit: bad') == 217, 'census is not 217'
assert 'R298 thief function take table pins audit' in s, 'patch f ate R298'
assert '// ---- R227: the wis mental save wiring audit ----' in s, 'patch f ate R227'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) tools/phb_gap_report.md: the flip and the pass ----
G_SIMPL_OLD = NL.join([
    '      recorded: the party roster carries no',
    '      recordings yet (a future round), the',
    '      slot COUNTS stay data (the engine sizes',
    '      no lists beyond the kit grant) and the',
    '      ranged-weapon slot is not yet recorded',
    '      (the missile path shares the same',
    '      hitAdjustment seam). The R297 battery',
])
G_SIMPL_NEW = NL.join([
    '      recorded: the party roster recordings are',
    '      the R299 kit grant (the R299 section',
    '      below), the slot COUNTS stay data (the',
    '      engine sizes no lists beyond the kit',
    '      grant) and the ranged slot records with',
    '      the thief kit (R299). The R297 battery',
])
G_TAIL_OLD = NL.join([
    '      example. Census 215.',
    '',
    '## Out of engine scope (the R296 additions)',
])
G_SECTION = NL.join([
    '      example. Census 215.',
    '',
    '## R299 the party recordings round (the third',
    'scope pass rides)',
    '',
    'R299 WIRED the party roster into the R297',
    'penalty seam - the R297 simplification note',
    'above is amended (the future round landed).',
    'The kit grant at creation is the initial',
    'proficiency choice set:',
    '',
    '- [x] **The party kit weapon recordings -',
    '      WIRED R299:** the Character gains',
    '      profWeaponIds (game/party.h); the grant',
    '      method grantKitProficiencies records',
    '      the class kit - the melee arm every',
    '      kit carries, plus the ranged slot',
    '      where the kit carries a missile (the',
    '      thief rows: the short sword and the R28',
    '      sling; the monk records the R230 staff;',
    '      the bard the Appendix II long sword).',
    '      The grant lands at creation',
    '      (makeMember), the subclass overlay',
    '      (makeSubclassMember - the monk staff),',
    '      the profession switch (the old choices',
    '      do not persist), the bard studies and',
    '      the save load rebuild (the R33 v1',
    '      convention - the recordings are not',
    '      saved; a loaded member re-reads the',
    '      kit). toActor copies the list to the',
    '      combat Actor - a held weapon outside a',
    '      NON-EMPTY list now pays the class',
    '      penalty LIVE (a fighter with a claimed',
    '      battle axe pays -2; a magic-user with',
    '      a staff pays -5). Simplifications',
    '      recorded: the added-slot choices stay a',
    '      future choice round (the counts are',
    '      data), the grant ids are the engine',
    '      canon kits (the kit switches and the',
    '      grant agree - pinned by the engine',
    '      audit) and the henchman keeps the',
    '      empty-list convention. The rules seam',
    '      (wpfKitRecordsMelee,',
    '      wpfKitRecordsRanged, wpfKitGrantCount -',
    '      rules/weaponprof.h) pins the slot-count',
    '      convention; the R299 battery audit pair',
    '      walks the seam (evaluable) and the',
    '      engine wiring (the R233a/R233',
    '      precedent). Census 217.',
    '',
    'R299 SCOPE PASS (the third pass, riding this',
    'round): the upload sections diffed against',
    'this ledger again. Recorded: the HENCHMEN',
    'prose (the about-50% henchman award note)',
    'matches the R45 engine convention (cited',
    'DMG p.86; the PHB section carries no table',
    'to pin); the SILENT MOVEMENT prose reads the',
    'R298 move silently column (the surprise link',
    'rides the future thief roll round); the',
    'weather tables live inside the control',
    'weather spell prose (the registry is the',
    'engine spell layer). ONE new open item',
    'found and opened below.',
    '',
    '## Open items (the R299 addition)',
    '',
    '- [ ] **The equipment cost columns (the BASIC',
    '      EQUIPMENT AND SUPPLIES COSTS tables,',
    '      upload line 2113; the reference-sheet',
    '      repeats at upload line 13432)** - the',
    '      arms and armor list prices the engine',
    '      carries as items costGp (dead data: no',
    '      shop charges them - the town stores',
    '      price canonically; verified repo-wide)',
    '      were never battery-pinned. A DATA-ONLY',
    '      pin candidate (the R190 precedent): a',
    '      rules header walking the printed arms',
    '      and armor cost columns cell by cell.',
    '      The R300 candidate. The general',
    '      equipment rows (clothing, herbs,',
    '      livestock, provisions, religious items,',
    '      tack, transport) carry no engine layer',
    '      - out of engine scope.',
    '',
    '## Out of engine scope (the R296 additions)',
])
G_PLANES_OLD = NL.join([
    '- Appendix IV (the known planes of',
    '  existence) - the engine has no planar',
    '  layer; the planar references that matter',
    '  (the artifact prose) are DMG-side and',
    '  pinned there.',
])
G_PLANES_NEW = NL.join([
    '- Appendix IV (the known planes of',
    '  existence) - the engine has no planar',
    '  layer; the planar references that matter',
    '  (the artifact prose) are DMG-side and',
    '  pinned there. R299: the full planar',
    '  material arrives with the Manual of the',
    '  Planes (the user decision); the pin',
    '  round waits for that source.',
])
for x in (G_SIMPL_NEW, G_SECTION, G_PLANES_NEW):
    clean(x, 57)
clean(G_SIMPL_OLD, 57)
clean(G_TAIL_OLD, 57)
clean(G_PLANES_OLD, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'WIRED R299' in s:
    already.append('phb_gap_report.md: the flip and the pass')
else:
    assert s.count(G_SIMPL_OLD) == 1, 'gap simpl anchor not unique'
    assert s.count(G_TAIL_OLD) == 1, 'gap tail anchor not unique'
    assert s.count(G_PLANES_OLD) == 1, 'gap planes anchor not unique'
    assert s.count('- [ ]') == 0, 'the ledger is not closed'
    s = s.replace(G_SIMPL_OLD, G_SIMPL_NEW)
    s = s.replace(G_TAIL_OLD, G_SECTION)
    s = s.replace(G_PLANES_OLD, G_PLANES_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the flip and the pass')
s = rd(p)
assert s.count('WIRED R299') == 1, 'patch g failed'
assert s.count('- [ ]') == 1, 'patch g open item count wrong'
assert 'The R300 candidate.' in s, 'patch g candidate note'
assert 'Planes (the user decision)' in s, 'patch g planes note'
assert 'Census 215.' in s, 'patch g ate the R298 census note'
assert 'Census 217.' in s, 'patch g census note missing'
assert s.count('Census 214.') == 1, 'patch g ate the R297 census note'
assert 'R296 SCOPE PASS' in s, 'patch g ate the R296 section'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- R299 fails/tail ----
if fails:
    print('R299 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print('R299 splice: FAIL - expected 7 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R299 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R299 note: 7 patches; the battery census 215 -> 217;')
print('the phb ledger holds ONE open item (the R300 candidate)')
print('real gate: md5sum rules/weaponprof.h')
print('commit: R299: the party kit weapon recordings wired and the third scope pass (census 217)')

