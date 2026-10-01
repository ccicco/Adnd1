#!/usr/bin/env python3
# R86-CHUNK-1-START
# R86 "THE MULE + THE CURSE AUDIT" splice.
# Content-anchored, idempotent. Patch groups (6 files):
#   game/party.h        - Party::henchmanPack (the hire's pack)
#   game/state_dungeon.cpp - overflow gear the members cannot
#                         carry is shouldered by the henchman
#   game/state_town.cpp - [P] peddles the hire's pack too
#   game/state_core.cpp - save/load "hpack N" + "pk ..." lines
#                         (v1-save compatible)
#   adnd1.cpp           - HUD roster token gains " pN" for
#                         pack carriers (dungeon/at-a-glance)
#   regtest.cpp         - "R86 cursed/hire audit: bad 0"
#   tools/playverify_r77_r83.md - the R85 pack walkthrough
# All anchors and inserted text are ASCII-only (protocol rule).

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)

def patch(fname, old, new, tag, count=1):
    s = rd(fname)
    if new in s:
        REPORT.append("%s: already patched" % tag)
        return True
    n = s.count(old)
    if n != count:
        REPORT.append("%s: FAIL (anchor x%d, want %d)" % (tag, n, count))
        return False
    wr(fname, s.replace(old, new, count))
    REPORT.append("%s: patched" % tag)
    return True

OK = True

# ---------------------------------------------------------------------------
# 1) party.h - the hire's pack field
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    // R80: the hire's magic kit - a won sword's enchant and a won
    // magic shield's plus (armor stays the R46 plate ladder)
    int  henchmanWeaponPlus = 0;
    int  henchmanShieldPlus = 0;""",
"""    // R80: the hire's magic kit - a won sword's enchant and a won
    // magic shield's plus (armor stays the R46 plate ladder)
    int  henchmanWeaponPlus = 0;
    int  henchmanShieldPlus = 0;

    // R86: the hire's pack - the mule slot. Gear the members
    // cannot carry (full packs) is shouldered by the henchman
    // and peddled in town with the rest ([P]). His kit stays
    // fixed (R80) - the pack is cargo, never equipped.
    std::vector<PackItem> henchmanPack;""",
'party.h henchmanPack')

# ---------------------------------------------------------------------------
# 2) state_dungeon.cpp - the mule slot (after the member pack loop)
# ---------------------------------------------------------------------------
OK &= patch('game/state_dungeon.cpp',
"""                                     (int)c.pack.size(),
                                     PACK_CAP);
                            log.add(buf);
                            take = true;
                            break;
                        }
                    }
                }
""",
"""                                     (int)c.pack.size(),
                                     PACK_CAP);
                            log.add(buf);
                            take = true;
                            break;
                        }
                    }
                    // R86: the mule slot - the hire shoulders
                    // what the members could not (same cap; his
                    // pack is cargo only, the kit stays R80)
                    if (!take && party.henchmanPresent &&
                        party.henchmanHp > 0 &&
                        (int)party.henchmanPack.size() < PACK_CAP) {
                        party.henchmanPack.push_back(cand);
                        snprintf(buf, sizeof buf,
                                 "%s shoulders the %s "
                                 "(hire's pack %d/%d).",
                                 party.henchmanName.c_str(),
                                 mi.name.c_str(),
                                 (int)party.henchmanPack.size(),
                                 PACK_CAP);
                        log.add(buf);
                        take = true;
                    }
                }
""",
'state_dungeon.cpp mule slot')
# R86-CHUNK-1-END
# R86-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) state_town.cpp - [P] sells the hire's pack too
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""            c.pack = keep;
        }
        if (sold == 0 && kept == 0) {""",
"""            c.pack = keep;
        }
        // R86: the hire's pack goes under the same hammer - he
        // carried it for the company, the gold is company gold
        if (!party.henchmanPack.empty()) {
            std::vector<PackItem> keep;
            for (const auto& p : party.henchmanPack) {
                if (p.gp > 0) {
                    party.gold += p.gp;
                    total += p.gp;
                    ++sold;
                    snprintf(buf, sizeof buf,
                             "%s sells the %s for %d gp.",
                             party.henchmanName.c_str(),
                             packItemName(p).c_str(), p.gp);
                    log.add(buf);
                } else {
                    keep.push_back(p);
                    ++kept;
                }
            }
            party.henchmanPack = keep;
        }
        if (sold == 0 && kept == 0) {""",
'state_town.cpp hire sale')

# ---------------------------------------------------------------------------
# 4) state_core.cpp - save + load the hire's pack
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        else
            fprintf(f, "henchman 0\\n");""",
"""        else
            fprintf(f, "henchman 0\\n");
        // R86: the hire's pack (nonempty only - v1 saves load
        // with an empty mule slot)
        if (!party.henchmanPack.empty()) {
            fprintf(f, "hpack %d\\n",
                    (int)party.henchmanPack.size());
            for (const auto& pi : party.henchmanPack)
                fprintf(f, "pk %d %d %d %d\\n",
                        pi.kind, pi.id, pi.plus, pi.gp);
        }""",
'state_core.cpp save hpack')

OK &= patch('game/state_core.cpp',
"""                    if (got >= 4) p.henchmanWeaponPlus = wpl;
                    if (got >= 5) p.henchmanShieldPlus = spl;
                }
            } else if (strcmp(tag, "idscrolls") == 0) {""",
"""                    if (got >= 4) p.henchmanWeaponPlus = wpl;
                    if (got >= 5) p.henchmanShieldPlus = spl;
                }
            } else if (strcmp(tag, "hpack") == 0) {
                int nhp = 0;
                if (fscanf(f, "%d", &nhp) != 1 ||
                    nhp < 0 || nhp > PACK_CAP) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (hpack).");
                    return false;
                }
                for (int k = 0; k < nhp; ++k) {
                    char t2[16];
                    int kd = 0, idd = 0, pl = 0, gpv = 0;
                    if (fscanf(f, "%15s %d %d %d %d",
                               t2, &kd, &idd, &pl, &gpv) != 5 ||
                        strcmp(t2, "pk") != 0 ||
                        kd < 0 || kd > 2 ||
                        pl < 0 || pl > 5 ||
                        gpv < 0 || gpv > 100000) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpk).");
                        return false;
                    }
                    if (kd == 0 &&
                        (idd < 0 ||
                         idd >= (int)items::WPN_COUNT)) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpkw).");
                        return false;
                    }
                    if (kd == 1 &&
                        (idd < 0 ||
                         idd >= (int)items::ARMOR_COUNT)) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hpka).");
                        return false;
                    }
                    PackItem pi;
                    pi.kind = kd; pi.id = idd;
                    pi.plus = pl; pi.gp = gpv;
                    p.henchmanPack.push_back(pi);
                }
            } else if (strcmp(tag, "idscrolls") == 0) {""",
'state_core.cpp load hpack')
# R86-CHUNK-2-END
# R86-CHUNK-3-START

# ---------------------------------------------------------------------------
# 5) adnd1.cpp - HUD roster token gains the pack count
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""        char tok[40];
        char nm[9];
        strncpy(nm, c.name.c_str(), 8);""",
"""        char tok[40];
        char nm[9];
        char pk[8] = "";
        strncpy(nm, c.name.c_str(), 8);""",
'adnd1.cpp roster pk buf')

OK &= patch('adnd1.cpp',
"""        snprintf(tok, sizeof tok, "%s%s %c%d %d/%d   ",
                 c.hp > 0 ? "" : "*",
                 nm, CLASS_INITIALS[c.classIndex],
                 c.level, c.hp, c.maxHp);""",
"""        // R86: carriers show " pN" after their hp (the pack
        // at a glance, dungeon HUD; empty packs stay quiet)
        if (!c.pack.empty())
            snprintf(pk, sizeof pk, " p%d",
                     (int)c.pack.size());
        snprintf(tok, sizeof tok, "%s%s %c%d %d/%d%s   ",
                 c.hp > 0 ? "" : "*",
                 nm, CLASS_INITIALS[c.classIndex],
                 c.level, c.hp, c.maxHp, pk);""",
'adnd1.cpp roster token')

# ---------------------------------------------------------------------------
# 6) regtest.cpp - the R86 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R85 pack audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R85 pack audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R86: cursed/hire audit ----
    {
        int bad = 0;
        // the cursed-name routing the claim guard depends on:
        // cursed items never reach the gear cases, so they can
        // never become pack cargo (the carry invariant)
        {
            dm::treasure::MagicItem mi;
            mi.name = "Sword +1, Cursed";
            if (!mi.cursed()) ++bad;
            mi.name = "Shield -1, Vulnerability";
            if (!mi.cursed()) ++bad;
            mi.name = "Hematite attractor of Armor";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword -2, Backbiter";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword +2, Frost Brand";
            if (mi.cursed()) ++bad;
            mi.name = "Chain Mail +2";
            if (mi.cursed()) ++bad;
        }
        // defense in depth: a negative-plus item never improves
        // a kit even if some future path offered it as cargo
        {
            Character c;
            c.hp = 10;
            c.weapon.id = items::WPN_LONG_SWORD;
            c.weapon.plus = 0;
            PackItem cw{};
            cw.kind = 0;
            cw.id = (int)items::WPN_LONG_SWORD;
            cw.plus = -1;
            cw.gp = 300;
            if (packImproves(c, cw)) ++bad;
            // any shield beats none (even a cursed one would),
            // so wear a mundane shield first: -1 must lose
            c.shield = true;
            c.shieldPlus = 0;
            PackItem cs{};
            cs.kind = 2;
            cs.plus = -1;
            cs.gp = 50;
            if (packImproves(c, cs)) ++bad;
        }
        printf("R86 cursed/hire audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp audit')

# ---------------------------------------------------------------------------
# 7) playverify checklist - the R85 pack walkthrough
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R85: the pack (+ R86 hire's pack)
- [ ] Win magic gear nobody equips (hoard rolls a weapon no
      member improves with): the log shows
      "Rolf carries the Long Sword +2 (pack 1/6)." - first
      living member with a free slot, 6 slots each.
- [ ] With every member's pack full, the next unclaimed gear
      goes to the henchman instead:
      "Grimnir shoulders the Chain Mail (hire's pack 1/6)."
      (R86; no henchman = appraised as before.)
- [ ] In town press [D] (dump kit): each carrier prints
      "  Rolf's pack (1/6): Long Sword +2".
- [ ] Press [E] (equip best): a member with a mundane sword and
      a +2 in the pack shows "Rolf equips the Long Sword +2."
      and the old kit returns as a keepsake (pack count stays;
      the keepsake never sells).
- [ ] Press [P] (peddle): sale-value items sell, ending with
      "The pack sale nets N gp."; the henchman's cargo sells
      too ("Grimnir sells the Chain Mail for 300 gp.");
      keepsakes stay ("Keepsakes (swapped-out kit) stay
      unsold.").
- [ ] Dungeon HUD roster line: carriers show " pN" after hp
      (R86, at-a-glance pack count).
- [ ] Save ([K]) and load ([L]): packs (member and hire)
      survive the round trip; a pre-R85 save loads clean with
      empty packs.
- [ ] Town screen right column: "PACK: [E] equip best  [P]
      peddle  [D] dump kit" above the quiver list (the quiver
      moved right - it used to collide with the [L]/[R] lines).

## Sign-off""",
'playverify R85 section')

# ---------------------------------------------------------------------------
print("\\n".join(REPORT))
print("R86 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R86-CHUNK-3-END
