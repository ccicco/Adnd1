// ============================================================================
// Adnd1 — game/henchman_save.h
// Henchman save-line helpers shared by AppState save/load and tests.
// ============================================================================

#pragma once

#include "messagelog.h"
#include "party.h"

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

enum { HENCHMAN_SAVE_INT_MAX_CHARS = 11 };
enum {
    HENCHMAN_SAVE_LINE_CHARS =
        (8 * HENCHMAN_SAVE_INT_MAX_CHARS) + NAME_MAX_CHARS + 10
};

inline bool parseSaveIntToken(const std::string& s, int& out) {
    if (s.empty()) return false;
    char* end = nullptr;
    long v = std::strtol(s.c_str(), &end, 10);
    if (!end || *end != '\0' || v < INT_MIN || v > INT_MAX)
        return false;
    out = (int)v;
    return true;
}

inline bool loadHenchmanRecord(Party& p, int hp, int mx, int lv,
                               int loy, int hxp, int hpu, int dgv,
                               const std::string& name) {
    if (hp < 1 || mx < 1 || lv < 1 || loy < 0 || loy > 125 ||
        hxp < 0 || hpu < 0 || dgv < 0 ||
        name.empty() || name.size() > NAME_MAX_CHARS)
        return false;
    p.henchmanPresent = true;
    p.henchmanName = name;
    p.henchmanHp = hp;
    p.henchmanMaxHp = mx;
    p.henchmanLevel = lv;
    p.henchmanLoyalty = loy;
    p.henchmanXp = hxp;
    p.henchmanPurse = hpu;
    p.delveGold = dgv;
    return true;
}

inline void writeHenchmanSaveRecord(FILE* f, const Party& party) {
    if (party.henchmanPresent)
        fprintf(f, "henchman %d %d %d %d %d %d %d %s\n",
                party.henchmanHp, party.henchmanMaxHp,
                party.henchmanLevel, party.henchmanLoyalty,
                party.henchmanXp, party.henchmanPurse,
                party.delveGold, party.henchmanName.c_str());
    else
        fprintf(f, "henchman 0\n");
}

inline bool parseHenchmanSaveRecord(const char* line, Party& p) {
    std::istringstream iss(line);
    std::vector<std::string> tok;
    for (std::string s; iss >> s; ) {
        if (tok.size() >= 9) return false;
        tok.push_back(s);
    }
    if (tok.empty()) return false;
    if (tok.size() == 1 && tok[0] == "0") return true;

    int hp = 0, mx = 0, lv = 0, loy = 0;
    int hxp = 0, hpu = 0, dgv = 0;

    // Canonical v1 record written by saveGame():
    //   henchman <hp> <maxHp> <level> <loyalty> <xp> <purse>
    //            <delveGold> <name>
    if (tok.size() == 8 &&
        parseSaveIntToken(tok[0], hp) &&
        parseSaveIntToken(tok[1], mx) &&
        parseSaveIntToken(tok[2], lv) &&
        parseSaveIntToken(tok[3], loy) &&
        parseSaveIntToken(tok[4], hxp) &&
        parseSaveIntToken(tok[5], hpu) &&
        parseSaveIntToken(tok[6], dgv))
        return loadHenchmanRecord(p, hp, mx, lv, loy, hxp, hpu,
                                  dgv, tok[7]);

    // Legacy flagged forms accepted by earlier loaders:
    //   henchman 1 <hp> <maxHp> <level> <loyalty> <name>
    //   henchman 1 <hp> <maxHp> <level> <loyalty> <name>
    //              <xp> <purse> <delveGold>
    if ((tok.size() == 6 || tok.size() == 9) && tok[0] == "1" &&
        parseSaveIntToken(tok[1], hp) &&
        parseSaveIntToken(tok[2], mx) &&
        parseSaveIntToken(tok[3], lv) &&
        parseSaveIntToken(tok[4], loy)) {
        if (tok.size() == 9) {
            int ambiguous = 0;
            if (parseSaveIntToken(tok[5], ambiguous) ||
                !parseSaveIntToken(tok[6], hxp) ||
                !parseSaveIntToken(tok[7], hpu) ||
                !parseSaveIntToken(tok[8], dgv))
                return false;
        }
        return loadHenchmanRecord(
            p, hp, mx, lv, loy, hxp, hpu, dgv,
            tok[5]);
    }
    return false;
}

inline bool readHenchmanSaveRecord(FILE* f, Party& p) {
    char line[HENCHMAN_SAVE_LINE_CHARS];
    if (!fgets(line, sizeof line, f)) return false;
    size_t len = strlen(line);
    if (len == 0 || line[len - 1] != '\n')
        return false;
    return parseHenchmanSaveRecord(line, p);
}
