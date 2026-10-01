#!/usr/bin/env python3
"""fix_caps_r80.py -- move the R79 cap constants (CARRIED_CAP,
QUIVER_CAP) above the R80 quiver helpers in game/party.h; quiverAdd's
default argument references QUIVER_CAP before the old EOF position.
Content-anchored, idempotent. Run from repo root."""
import sys
p = 'game/party.h'
src = open(p, encoding='utf-8').read()

BLOCK = '''// R79: carried-stack ceilings. Potions/scrolls pool per party; the
// quiver is per member. Caps keep decades of delve counters inside
// sane ranges (nothing can run away toward int overflow).
static const int CARRIED_CAP = 9999;   // party potions/scrolls
static const int QUIVER_CAP  = 999;    // per-member missileAmmo
'''
RULE = '// ----------------------------------------------------------------------------\n'
KEY80 = '// R80: quiver bundles'

if src.count(BLOCK) != 1:
    print('caps block not found verbatim - aborting (already moved?)')
    sys.exit(0)

caps_i = src.find(BLOCK)
r80_i = src.find(KEY80)
if caps_i != -1 and caps_i < r80_i:
    print('already fixed - caps precede the R80 block')
    sys.exit(0)

# remove the block (plus the blank line that follows it)
after = src[caps_i + len(BLOCK):]
if after.startswith('\n'):
    after = after[1:]
src = src[:caps_i] + after

# insert above the ---- rule that precedes the R80 banner
r80_i = src.find(KEY80)
assert r80_i != -1, 'R80 banner missing'
rule_i = src.rfind(RULE, 0, r80_i)
assert rule_i != -1 and r80_i - rule_i < 100, 'R80 rule not found'
src = src[:rule_i] + BLOCK + '\n' + src[rule_i:]
open(p, 'w', encoding='utf-8').write(src)
print('cap constants moved above the R80 block')
