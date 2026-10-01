#!/usr/bin/env python3
# R85 fix-up - items/items.h was never self-contained: it uses
# rules::ArmorWeight and rules::ExceptionalStrength but included
# only combat.h (which pulls in neither classes.h nor character.h).
# items.cpp got away with it by including character.h AFTER items.h
# - but any TU that includes items.h first (the new regtest build)
# fails. The rules:: qualifiers were right; the includes were not.
import sys, os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()
def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)
OK = True
s = rd('items/items.h')
NEW = ('#include "../rules/classes.h"   // ArmorWeight, ARMOR_NONE/'
       'LEATHER/CHAIN/PLATE\n'
       '#include "../rules/character.h" // ExceptionalStrength\n'
       '#include <cstdint>\n')
if NEW in s:
    print('items.h includes: already patched')
elif s.count('#include <cstdint>\n') != 1:
    print('items.h includes: FAIL (anchor x%d, want 1)'
          % s.count('#include <cstdint>\n'))
    OK = False
else:
    wr('items/items.h', s.replace('#include <cstdint>\n', NEW, 1))
    print('items.h includes: patched')
print('R85 fixup:', 'ALL OK' if OK else 'FAILURES PRESENT')
sys.exit(0 if OK else 1)
