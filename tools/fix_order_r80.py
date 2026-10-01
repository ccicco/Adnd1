#!/usr/bin/env python3
"""fix_order_r80.py -- move the R80 AmmoBundle block in game/party.h
from EOF (after Character/Party) to BEFORE struct Character, which
uses it (std::vector<AmmoBundle> quiver). Content-anchored, idempotent.
Run from repo root: python3 tools/fix_order_r80.py"""
import sys

p = 'game/party.h'
src = open(p, encoding='utf-8').read()

# ASCII-safe anchors (em dashes kept out of the literals)
BANNER_KEY = '// R80: quiver bundles'
BANNER = src[src.find(BANNER_KEY) - 81:src.find(BANNER_KEY)]  # the ---- rule above
END_KEY = '// R79: the logistics helpers'
DEST_KEY = '// R24: Character'
DEST_RULE = '// ----------------------------------------------------------------------------\n'

if src.find(BANNER_KEY) < src.find('struct Character {'):
    print('already fixed - R80 block precedes Character')
    sys.exit(0)

start = src.find(BANNER_KEY)
end = src.find(END_KEY)
assert start != -1 and end != -1 and start < end, 'anchors missing'

# the block begins at the ---- rule line just above the banner key
rule_at = src.rfind(DEST_RULE, 0, start)
assert rule_at != -1 and start - rule_at < 100, 'banner rule not found'
block = src[rule_at:end].rstrip('\n') + '\n\n'

# remove from the old location
src = src[:rule_at] + src[end:]

# insert before the ---- rule that precedes the R24 Character banner
di = src.find(DEST_KEY)
assert di != -1, 'destination key missing'
insert_at = src.rfind(DEST_RULE, 0, di)
assert insert_at != -1 and di - insert_at < 100, 'destination rule not found'
src = src[:insert_at] + block + src[insert_at:]

open(p, 'w', encoding='utf-8').write(src)
print('R80 block moved above Character')
