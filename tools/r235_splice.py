#!/usr/bin/env python3
# R235 splice: the bard engine.
#
# The Appendix II career goes live: a fighter-turned-
# thief (the R234 dual-class machinery) inside both
# printed windows - fighter 5th-7th, then thief 5th-
# 9th - with the Appendix II ability minimums (STR
# WIS DEX CHA 15+, INT 12, CON 10; human or half-elf)
# begins the druidical studies at the town guild
# (the [A] key). The hit dice and hit points are
# retained; all functions restart at 1st level; the
# kit rides Table III (leather, no shield, a bard
# weapon); the druid slots fill from Table I; the
# member levels on the Table I XP ladder (the bard
# XP only convention) and rolls the Table I d6
# column per level with the druidical con
# adjustment. The roster prints the B line; the
# combat castable list reads the druid roster.
#
# commit: R235: the bard engine - the Appendix II career playable, the Table I ladder and dice, the druid slots (census 154)

import sys

BRD  = 'rules/bard.h'
PAR  = 'game/party.h'
ACT  = 'ai/actor.h'
APP  = 'game/appstate.h'
TOWN = 'game/state_town.cpp'
AD   = 'adnd1.cpp'
CORE = 'game/state_core.cpp'
REG  = 'regtest.cpp'
GAP  = 'tools/phb_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson)
g = open(GAP).read()
if g.count('Census 152.') != 1 and g.count('Census 154.') != 1:
    print('R235 FAIL: gap report census line missing')
    sys.exit(1)
t = open(REG).read()
if t.count('audit: bad ') != 152 and t.count('audit: bad ') != 154:
    print('R235 FAIL: regtest census is neither 152 nor 154')
    sys.exit(1)

# ---- 0: the BARD_* constants become a named enum
# (the R233 McBits convention - audit_eval reads enum
# constants, not static const ints) ----
pins_old = [
    'static const int BARD_LEVEL_COUNT = 23;',
    'static const int BARD_PRIME_MIN = 15;   // STR WIS DEX CHA',
    'static const int BARD_INT_MIN = 12;',
    'static const int BARD_CON_MIN = 10;',
]
pins_new = [
    '// R235: named enum constants (was static const',
    '// ints) so the audit_eval seam reads the same',
    '// values (the R233 McBits convention).',
    'enum BardPins {',
    '    BARD_LEVEL_COUNT = 23,',
    '    BARD_PRIME_MIN = 15,   // STR WIS DEX CHA',
    '    BARD_INT_MIN = 12,',
    '    BARD_CON_MIN = 10,',
    '};',
]

# ---- 1: the rules/bard.h career seam ----
seam_old = [
    '// The wiring: combat at the fighter level',
]
seam_new = [
    '// ---- the R235 career seam (pure expressions -',
    '// the evaluable-subset convention) ----',
    '',
    '// The career gate: the druid studies open to a',
    '// fighter-turned-thief inside BOTH printed',
    '// windows (fighter 5th-7th, then thief 5th-9th).',
    'inline bool bardCareerGate(int fighterLevel,',
    '                            int thiefLevel) {',
    '    return bardFighterWindow(fighterLevel)',
    '           && bardThiefWindow(thiefLevel);',
    '}',
    '',
    '// The wiring: combat at the fighter level',
]

# ---- 2: the party.h include ----
inc_old = [
    '#include "../rules/multiclass.h"  // R233: the multi-class engine',
]
inc_new = [
    '#include "../rules/multiclass.h"  // R233: the multi-class engine',
    '#include "../rules/bard.h"  // R235: the bard engine',
]

# ---- 3: the Character bard field ----
fld_old = [
    '    bool oldClassUse = false;',
]
fld_new = [
    '    bool oldClassUse = false;',
    '    // R235: the bard career (true once the',
    '    // druidical studies begin - the Appendix II',
    '    // fighter/thief/bard path)',
    '    bool bard = false;',
]

# ---- 4: the toActor bard carry ----
toa_old = [
    '        a.subclass    = subclass;   // R232: the specials hooks',
]
toa_new = [
    '        a.subclass    = subclass;   // R232: the specials hooks',
    '        a.bard        = bard;   // R235: the druid studies',
]

# ---- 5: the member methods (canBeginBardStudies /
# beginBardStudies), after switchProfession ----
meth_old = [
    '            case rules::CLASS_THIEF:',
    '                weapon.id = items::WPN_SHORT_SWORD;',
    '                armor.id  = items::ARMOR_LEATHER;',
    '                shield    = false;',
    '                rangedWeapon.id = items::WPN_SLING;',
    '                break;',
    '        }',
    '        return true;',
    '    }',
    '};',
]
meth_new = [
    '            case rules::CLASS_THIEF:',
    '                weapon.id = items::WPN_SHORT_SWORD;',
    '                armor.id  = items::ARMOR_LEATHER;',
    '                shield    = false;',
    '                rangedWeapon.id = items::WPN_SLING;',
    '                break;',
    '        }',
    '        return true;',
    '    }',
    '',
    '    // R235: can this member begin the bardic',
    '    // studies? The print (Appendix II): the career',
    '    // runs fighter (to 5th-7th) then thief (to',
    '    // 5th-9th) - the member is a fighter-turned-',
    '    // thief (the R234 dual-class career) inside',
    '    // both windows, human or half-elf, with the',
    '    // ability minimums (STR WIS DEX CHA 15+,',
    '    // INT 12, CON 10).',
    '    bool canBeginBardStudies() const {',
    '        if (bard) return false;',
    '        if (!rules::bardRaceAllowed(race)) return false;',
    '        if (classIndex != 3) return false;',
    '        if (dualOldClass != 0) return false;',
    '        if (!rules::bardCareerGate(dualOldLevel, level))',
    '            return false;',
    '        return rules::bardAbilityGate(',
    '            abilities.str, abilities.wis,',
    '            abilities.dex, abilities.cha,',
    '            abilities.int_, abilities.con);',
    '    }',
    '',
    '    // R235: begin the studies - the bard career.',
    '    // The hit dice and hit points are RETAINED',
    '    // (the class d6s ride the Table I column from',
    '    // level 2); all functions restart at 1st',
    '    // level; the kit rides Table III (leather, no',
    '    // shield, a bard weapon - the long sword, a',
    '    // permitted Table III arm; the engine has no',
    '    // scimitar); the druid slots fill from Table',
    '    // I level 1.',
    '    void beginBardStudies() {',
    '        bard = true;',
    '        dualOldClass = -1;',
    '        dualOldLevel = 0;',
    '        oldClassUse = false;',
    '        classIndex = 2;   // the druidical caster base',
    '        subclass = -1;',
    '        level = 1;',
    '        xp = 0;',
    '        knownSpells.clear();',
    '        for (int lv = 0; lv < 9; ++lv)',
    '            slotsByLevel[lv] = 0;',
    '        for (int lv = 1; lv <= 5; ++lv)',
    '            slotsByLevel[lv - 1] =',
    '                rules::bardDruidSlots(1, lv);',
    '        weapon.id = items::WPN_LONG_SWORD;',
    '        armor.id  = items::ARMOR_LEATHER;',
    '        shield    = false;',
    '    }',
    '};',
]

# ---- 6: the gainXp bard queue ----
gx_old = [
    '                log.add(nbuf);',
    '                continue;',
    '            }',
    '            // R30: prime-requisite % (PHB p.20 class notes) -',
]
gx_new = [
    '                log.add(nbuf);',
    '                continue;',
    '            }',
    '            // R235: the bard levels on the Table I XP',
    '            // ladder (bard XP only - the R186 pin);',
    '            // the queue and message mirror the class',
    '            // ladder below, then the bard owns the',
    '            // member',
    '            if (c.bard) {',
    '                int bcap = 23;',
    '                int bneed = rules::bardXpForLevel(',
    '                    c.level + 1);',
    '                if (c.level < bcap && c.xp >= bneed &&',
    '                    !isQueuedForTraining(',
    '                        (int)(&c - members.data()))) {',
    '                    pendingTraining.push_back(',
    '                        (int)(&c - members.data()));',
    '                    char bbuf[96];',
    '                    snprintf(bbuf, sizeof bbuf,',
    '                             "%s is due a level - training "',
    '                             "costs %d gp in town.",',
    '                             c.name.c_str(),',
    '                             1500 * (c.level + 1));',
    '                    log.add(bbuf);',
    '                }',
    '                continue;',
    '            }',
    '            // R30: prime-requisite % (PHB p.20 class notes) -',
]

# ---- 7: the trainNext cap/need bard branch ----
cap_old = [
    '            // R233: a multi-class member promotes on the',
    '            // primary class ladder (the first set bit)',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            if (c.multiMask != 0) {',
]
cap_new = [
    '            // R233: a multi-class member promotes on the',
    '            // primary class ladder (the first set bit)',
    '            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];',
    '            int need = rules::xpForLevel(c.classIndex,',
    '                                        c.level + 1);',
    '            // R235: a bard promotes on the Table I XP',
    '            // ladder, capped at the 23rd (M. Bard)',
    '            if (c.bard) {',
    '                cap = 23;',
    '                need = rules::bardXpForLevel(c.level + 1);',
    '            } else if (c.multiMask != 0) {',
]

# ---- 8: the trainNext die bard branch ----
die_old = [
    '            if (c.dualOldClass >= 0) {',
    '                // R234: the dual-class promotion die -',
]
die_new = [
    '            if (c.bard) {',
    '                // R235: the bard promotion die - the',
    '                // Table I d6 count gained this level',
    '                // (level 1 gains none - the fighter and',
    '                // thief dice are the retained base),',
    '                // each with the druidical con',
    '                // adjustment (the druid rides the',
    '                // cleric con class - the R230',
    '                // convention), the per-die floor 1',
    '                int nd = rules::bardHitDice(c.level)',
    '                        - rules::bardHitDice(c.level - 1);',
    '                conAdj = rules::conHPAdjustment(',
    '                    rules::subclassConClass(2),',
    '                    c.abilities.con);',
    '                die = 0;',
    '                for (int i = 0; i < nd; ++i) {',
    '                    int d = (int)dice.roll(1, 6, 0)',
    '                            + conAdj;',
    '                    if (d < 1) d = 1;',
    '                    die += d;',
    '                }',
    '            } else if (c.dualOldClass >= 0) {',
    '                // R234: the dual-class promotion die -',
]

# ---- 9: the Actor bard field ----
act_old = [
    '    int  subclass = -1;',
    '    int  level      = 1;',
]
act_new = [
    '    int  subclass = -1;',
    '    // R235: the bard career (the druidical studies)',
    '    bool bard = false;',
    '    int  level      = 1;',
]

# ---- 10: the castableSpells bard branch ----
cast_old = [
    '        bool mu = (a.classIndex == 1);',
]
cast_new = [
    '        // R235: a bard casts the druid roster from',
    '        // the Table I slot columns (levels 1-5; the',
    '        // MU book gate does not apply - the',
    '        // druidical studies are not a book)',
    '        if (a.bard) {',
    '            for (int id = 0; id < spells::SPELL_COUNT;',
    '                 ++id) {',
    '                const spells::SpellDef& s =',
    '                    spells::spell((spells::SpellId)id);',
    '                if (s.sclass != spells::SPELL_DRUID)',
    '                    continue;',
    '                if (s.level < 1 || s.level > 5) continue;',
    '                if (a.slotsByLevel[s.level - 1] <= 0)',
    '                    continue;',
    '                out.push_back((spells::SpellId)id);',
    '            }',
    '            return out;',
    '        }',
    '        bool mu = (a.classIndex == 1);',
]

# ---- 11: the restoreSlots bard branch ----
res_old = [
    '            if (c.classIndex != 1 && c.classIndex != 2) continue;',
]
res_new = [
    '            // R235: a bard reads the Table I druid',
    '            // slot columns (levels 1-5; 6-9 empty)',
    '            if (c.bard) {',
    '                for (int lv = 1; lv <= 9; ++lv)',
    '                    c.slotsByLevel[lv - 1] =',
    '                        lv <= 5',
    '                            ? rules::bardDruidSlots(',
    '                                  c.level, lv)',
    '                            : 0;',
    '                continue;',
    '            }',
    '            if (c.classIndex != 1 && c.classIndex != 2) continue;',
]

# ---- 12: the appstate.h declaration ----
decl_old = [
    '    void townChangeClass();',
    '    void townOldClassResort();',
]
decl_new = [
    '    void townChangeClass();',
    '    void townOldClassResort();',
    '',
    '    // R235: the bardic studies - the Appendix II career',
    '    void townBeginBardStudies();',
]

# ---- 13: the town guild command ----
town_old = [
    '        log.add("No member has two classes.");',
    '}',
    '',
    '// ---- townBuyChain ----',
]
town_new = [
    '        log.add("No member has two classes.");',
    '}',
    '',
    '// ---- townBeginBardStudies ----',
    '// R235: the druidical studies - a fighter-turned-',
    '// thief inside both printed windows (fighter 5th-',
    '// 7th, then thief 5th-9th) with the Appendix II',
    '// ability minimums begins the bard career. The',
    '// hit dice are retained; all functions restart at',
    '// 1st level (the R234 class-change convention).',
    'void AppState::townBeginBardStudies(){',
    '        if (mode != MODE_TOWN) return;',
    '        for (auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            if (c.bard) continue;',
    '            if (!c.canBeginBardStudies()) continue;',
    '            c.beginBardStudies();',
    '            char buf[128];',
    '            snprintf(buf, sizeof buf,',
    '                     "%s begins the druidical studies - "',
    '                     "a bard at 1st level (hit dice kept).",',
    '                     c.name.c_str());',
    '            log.add(buf);',
    '            return;',
    '        }',
    '        log.add("No one can begin the bardic studies "',
    '                "(fighter 5th-7th, then thief 5th-9th, "',
    '                "the Appendix II minimums).");',
    '}',
    '',
    '// ---- townBuyChain ----',
]

# ---- 14: the town keydown case ----
key_old = [
    '                    case ' + Q + 'U' + Q + ':',
    '                    case ' + Q + 'u' + Q + ':',
    '                        g_app.townOldClassResort();',
    '                        break;',
]
key_new = [
    '                    case ' + Q + 'U' + Q + ':',
    '                    case ' + Q + 'u' + Q + ':',
    '                        g_app.townOldClassResort();',
    '                        break;',
    '',
    '                    // R235: the bardic studies',
    '                    case ' + Q + 'A' + Q + ':',
    '                    case ' + Q + 'a' + Q + ':',
    '                        g_app.townBeginBardStudies();',
    '                        break;',
]

# ---- 15: the guild help line ----
help_old = [
    '    snprintf(line, sizeof line,',
    '             "GUILD: [K] change class  [U] resort stance");',
]
help_new = [
    '    snprintf(line, sizeof line,',
    '             "GUILD: [K] class change  [U] resort  "',
    '             "[A] bardic studies");',
]

# ---- 16: the roster bard line ----
ros_old = [
    '        } else if (c.dualOldClass >= 0) {',
]
ros_new = [
    '        } else if (c.bard) {',
    '            // R235: the bard roster line',
    '            snprintf(line, sizeof line,',
    '                     "%s  B%d  %d/%d",',
    '                     nm, c.level, c.hp, c.maxHp);',
    '        } else if (c.dualOldClass >= 0) {',
]

# ---- 17: the save line ----
save_old = [
    '                fprintf(f, "olduse %d' + BS + 'n",',
    '                        c.oldClassUse ? 1 : 0);',
    '            }',
]
save_new = [
    '                fprintf(f, "olduse %d' + BS + 'n",',
    '                        c.oldClassUse ? 1 : 0);',
    '            }',
    '            // R235: the bard career (only when begun -',
    '            // v1 saves carry no line and load as',
    '            // single-classed)',
    '            if (c.bard)',
    '                fprintf(f, "bard %d' + BS + 'n", 1);',
]

# ---- 18: the load branch ----
load_old = [
    '                    c.oldClassUse = ou != 0;',
    '                } else if (strcmp(tag, "age") == 0) {',
]
load_new = [
    '                    c.oldClassUse = ou != 0;',
    '                } else if (strcmp(tag, "bard") == 0) {',
    '                    int bd = 0;',
    '                    if (fscanf(f, "%d", &bd) != 1 ||',
    '                        bd < 0 || bd > 1) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (bard).");',
    '                        return false;',
    '                    }',
    '                    c.bard = bd != 0;',
    '                } else if (strcmp(tag, "age") == 0) {',
]

# ---- 19: the regtest audits ----
audit_old = [
    '        printf("R234 dual-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
audit_new = [
    '        printf("R234 dual-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R235a: the bard career seam audit ----',
    '    // The career windows, the Table I ladders and',
    '    // the gates (an evaluable block - verified by',
    '    // audit_eval).',
    '    {',
    '        int bad = 0;',
    '        // the career gate: fighter 5th-7th, then',
    '        // thief 5th-9th',
    '        if (!rules::bardCareerGate(5, 5)) ++bad;',
    '        if (!rules::bardCareerGate(7, 9)) ++bad;',
    '        if (rules::bardCareerGate(4, 5)) ++bad;',
    '        if (rules::bardCareerGate(8, 5)) ++bad;',
    '        if (rules::bardCareerGate(5, 4)) ++bad;',
    '        if (rules::bardCareerGate(5, 10)) ++bad;',
    '        // the Table I d6 column: 0 at 1st, 1-10 at',
    '        // 2nd-11th, then 10+1 through 10+12',
    '        if (rules::bardHitDice(1) != 0) ++bad;',
    '        if (rules::bardHitDice(2) != 1) ++bad;',
    '        if (rules::bardHitDice(11) != 10) ++bad;',
    '        if (rules::bardHitDice(12) != 11) ++bad;',
    '        if (rules::bardHitDice(23) != 22) ++bad;',
    '        if (rules::bardHitDice(0) != 0) ++bad;',
    '        if (rules::bardHitDice(24) != 22) ++bad;',
    '        // the Table I XP ladder (bard XP only)',
    '        if (rules::bardXpForLevel(1) != 0) ++bad;',
    '        if (rules::bardXpForLevel(2) != 2001) ++bad;',
    '        if (rules::bardXpForLevel(11) != 150001) ++bad;',
    '        if (rules::bardXpForLevel(12) != 200001) ++bad;',
    '        if (rules::bardXpForLevel(13) != 400001) ++bad;',
    '        if (rules::bardXpForLevel(20) != 1800001) ++bad;',
    '        if (rules::bardXpForLevel(23) != 3000001) ++bad;',
    '        // the Table I druid slots',
    '        if (rules::bardDruidSlots(1, 1) != 1) ++bad;',
    '        if (rules::bardDruidSlots(1, 2) != 0) ++bad;',
    '        if (rules::bardDruidSlots(4, 2) != 1) ++bad;',
    '        if (rules::bardDruidSlots(14, 5) != 2) ++bad;',
    '        if (rules::bardDruidSlots(15, 1) != 3) ++bad;',
    '        if (rules::bardDruidSlots(16, 1) != 4) ++bad;',
    '        if (rules::bardDruidSlots(19, 1) != 5) ++bad;',
    '        if (rules::bardDruidSlots(23, 5) != 5) ++bad;',
    '        // the druid ability cap: 12th until the 23rd',
    '        if (rules::bardDruidCastLevel(1) != 1) ++bad;',
    '        if (rules::bardDruidCastLevel(12) != 12) ++bad;',
    '        if (rules::bardDruidCastLevel(13) != 12) ++bad;',
    '        if (rules::bardDruidCastLevel(22) != 12) ++bad;',
    '        if (rules::bardDruidCastLevel(23) != 13) ++bad;',
    '        // the henchmen ladder',
    '        if (rules::bardHenchmen(4) != 0) ++bad;',
    '        if (rules::bardHenchmen(5) != 1) ++bad;',
    '        if (rules::bardHenchmen(8) != 2) ++bad;',
    '        if (rules::bardHenchmen(23) != 999) ++bad;',
    '        // the ability and race gates, Table III',
    '        if (!rules::bardAbilityGate(15, 15, 15, 15,',
    '                                12, 10)) ++bad;',
    '        if (rules::bardAbilityGate(14, 15, 15, 15,',
    '                                12, 10)) ++bad;',
    '        if (rules::bardAbilityGate(15, 15, 15, 15,',
    '                                11, 10)) ++bad;',
    '        if (!rules::bardRaceAllowed(0)) ++bad;',
    '        if (!rules::bardRaceAllowed(4)) ++bad;',
    '        if (rules::bardRaceAllowed(1)) ++bad;',
    '        if (rules::bardShieldAllowed()) ++bad;',
    '        if (!rules::bardOilAllowed()) ++bad;',
    '        printf("R235a bard career seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R235: the bard engine audit ----',
    '    // The career gates, the retained hit dice,',
    '    // the 1st-level restart, the Table I queue and',
    '    // the promotion die (an engine audit - the C++',
    '    // battery is the gate).',
    '    {',
    '        int bad = 0;',
    '        {',
    '            Character c;',
    '            c.race = 0;   // human',
    '            c.abilities.str = 15;',
    '            c.abilities.wis = 15;',
    '            c.abilities.dex = 15;',
    '            c.abilities.cha = 15;',
    '            c.abilities.int_ = 12;',
    '            c.abilities.con = 10;',
    '            c.classIndex = 3;   // the thief leg',
    '            c.level = 6;',
    '            c.dualOldClass = 0;   // the fighter leg',
    '            c.dualOldLevel = 6;',
    '            c.hp = c.maxHp = 30;',
    '            if (!c.canBeginBardStudies()) ++bad;',
    '            // the refusals: wrong race, fighter',
    '            // window, thief window, low CHA, a',
    '            // plain class, already a bard',
    '            c.race = 1;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '            c.race = 0;',
    '            c.dualOldLevel = 4;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '            c.dualOldLevel = 6;',
    '            c.level = 10;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '            c.level = 6;',
    '            c.abilities.cha = 14;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '            c.abilities.cha = 15;',
    '            c.classIndex = 0;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '            c.classIndex = 3;',
    '            // the studies: hit dice kept, 1st-level',
    '            // restart, the Table III kit, the',
    '            // Table I level-1 slots',
    '            c.beginBardStudies();',
    '            if (!c.bard) ++bad;',
    '            if (c.classIndex != 2) ++bad;',
    '            if (c.subclass != -1) ++bad;',
    '            if (c.level != 1) ++bad;',
    '            if (c.xp != 0) ++bad;',
    '            if (c.hp != 30 || c.maxHp != 30) ++bad;',
    '            if (c.dualOldClass != -1) ++bad;',
    '            if (c.armor.id != items::ARMOR_LEATHER) ++bad;',
    '            if (c.shield) ++bad;',
    '            if (c.slotsByLevel[0] != 1) ++bad;',
    '            if (c.slotsByLevel[1] != 0) ++bad;',
    '            if (c.slotsByLevel[5] != 0) ++bad;',
    '            if (c.canBeginBardStudies()) ++bad;',
    '        }',
    '        // the Table I queue and the promotion die,',
    '        // on a live party train loop',
    '        {',
    '            Party p;',
    '            Character c;',
    '            c.name = "Rhymer";',
    '            c.bard = true;',
    '            c.classIndex = 2;',
    '            c.level = 1;',
    '            c.hp = c.maxHp = 30;',
    '            p.members.push_back(c);',
    '            rules::Rng r{7};',
    '            rules::Dice d(r);',
    '            MessageLog log;',
    '            p.gainXp(2500, d, log);',
    '            if (p.members[0].xp != 2500) ++bad;',
    '            if (p.trainNext(d, log) < 0) ++bad;',
    '            if (p.members[0].level != 2) ++bad;',
    '            if (p.members[0].maxHp <= 30) ++bad;',
    '        }',
    '        printf("R235 bard engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

# ---- 20: the gap-report box ----
gap_old = [
    '      prints the F6>M1 line. Census 152.',
]
gap_new = [
    '      prints the F6>M1 line. Census 152.',
    '- [x] R235 the bard engine - WIRED: the',
    '      Appendix II career is playable - the guild',
    '      studies (the [A] town key; the first member',
    '      who meets the gates begins), the gates (a',
    '      fighter-turned-thief inside BOTH printed',
    '      windows - fighter 5th-7th, then thief 5th-9th',
    '      - human or half-elf, the ability minimums',
    '      STR WIS DEX CHA 15+, INT 12, CON 10), the',
    '      studies (the hit dice and hit points',
    '      RETAINED, all functions at 1st level, the',
    '      Table III kit - leather, no shield, a bard',
    '      weapon - and the Table I level-1 druid',
    '      slots), the leveling (the Table I XP ladder,',
    '      bard XP only, capped at the 23rd; the Table',
    '      I d6 promotion column with the druidical con',
    '      adjustment), the combat castable list (the',
    '      druid roster from the Table I slot columns,',
    '      levels 1-5), the B roster line and the',
    '      v1-compatible bard save line. Simplifications',
    '      recorded: the alignment pin (always neutral)',
    '      stays data-only (no alignment concept yet),',
    '      the poetics layers, the colleges, the',
    '      henchmen ladder and the musical item bonuses',
    '      stay data-only (the R186 pins), the engine',
    '      has no scimitar (the kit rides the long',
    '      sword - a permitted Table III arm), the',
    '      druid spell EFFECTS resolve on the generic',
    '      combat layer. Census 154.',
]

PATCHES = [
    (BRD,  'enum BardPins', pins_old, pins_new),
    (BRD,  'bardCareerGate', seam_old, seam_new),
    (PAR,  'rules/bard.h', inc_old, inc_new),
    (PAR,  'bool bard = false;', fld_old, fld_new),
    (PAR,  'a.bard        = bard;', toa_old, toa_new),
    (PAR,  'bool canBeginBardStudies() const', meth_old, meth_new),
    (PAR,  'the bard levels on the Table I XP', gx_old, gx_new),
    (PAR,  'a bard promotes on the Table I XP', cap_old, cap_new),
    (PAR,  'the bard promotion die', die_old, die_new),
    (ACT,  'bool bard = false;', act_old, act_new),
    (APP,  'a bard casts the druid roster', cast_old, cast_new),
    (APP,  'void townBeginBardStudies();', decl_old, decl_new),
    (CORE, 'a bard reads the Table I druid', res_old, res_new),
    (TOWN, 'void AppState::townBeginBardStudies()', town_old, town_new),
    (AD,   'g_app.townBeginBardStudies();', key_old, key_new),
    (AD,   'bardic studies', help_old, help_new),
    (AD,   'the bard roster line', ros_old, ros_new),
    (CORE, 'bard %d', save_old, save_new),
    (CORE, 'strcmp(tag, "bard") == 0', load_old, load_new),
    (REG,  'R235a bard career seam audit', audit_old, audit_new),
    (GAP,  'R235 the bard engine - WIRED', gap_old, gap_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    count_new = text.count(new_s)
    count_old = text.count(old_s)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if count_new >= 1:
        already += 1
        continue
    if count_old == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count_old == 0:
        print('R235 FAIL: marker missing post-patch: ' + marker)
        sys.exit(1)
    else:
        print('R235 FAIL: marker appears ' + str(count_old) +
              ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied == len(PATCHES):
    t = open(REG).read()
    if t.count('audit: bad ') != 154:
        print('R235 FAIL: census is not 154')
        sys.exit(1)
    if t.count('R235a bard career seam audit') != 1:
        print('R235 FAIL: the R235a audit line must appear once')
        sys.exit(1)
    if t.count('R235 bard engine audit') != 1:
        print('R235 FAIL: the R235 audit line must appear once')
        sys.exit(1)
    t = open(GAP).read()
    if t.count('Census 154.') != 1:
        print('R235 FAIL: gap census line missing')
        sys.exit(1)
    if 'R235 the bard engine - WIRED' not in t:
        print('R235 FAIL: the bard box is not flipped')
        sys.exit(1)

print('R235 splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R235 note: 21 patches - the Appendix II career playable; the')
print('fighter-turned-thief begins the druidical studies; the hit')
print('dice are kept, all functions restart at 1st level.')
print('commit: R235: the bard engine - the Appendix II career playable, the Table I ladder and dice, the druid slots (census 154)')

