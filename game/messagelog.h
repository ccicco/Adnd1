// ============================================================================
// Adnd1 — game/messagelog.h
// The scrolling message log (moved verbatim from adnd1.cpp, R31).
// ============================================================================

#pragma once

#include <string>

// ----------------------------------------------------------------------------
// Message log
// ----------------------------------------------------------------------------

struct MessageLog {
    static const int MAX_LINES = 4;
    std::string lines[MAX_LINES];
    int head = 0;

    void add(const std::string& s) {
        lines[head] = s;
        head = (head + 1) % MAX_LINES;
    }
    const std::string& get(int i) const {
        int idx = head - 1 - i;
        while (idx < 0) idx += MAX_LINES;
        return lines[idx];
    }
};
