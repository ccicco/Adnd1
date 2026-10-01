#!/usr/bin/env python3
# R84-CHUNK-1-START
# R84 "POLISH + ASCII + PLAY-VERIFY" splice - idempotent.
# Three parts:
#   1) tools/preflight.sh - __pycache__ auto-clean (was a FAIL
#      that taxed every round since R80; bytecode is always
#      regenerable, so the gate now removes it silently)
#   2) ASCII normalization of ALL .cpp/.h - the MSVC-readiness
#      audit found ~60 game-facing strings with mojibake that
#      would render as garbage through TextOutA on Windows:
#      double-encoded em-dashes/dagger/arrows (UTF-8 -> latin-1
#      -> UTF-8 artifacts) plus real U+2014 em-dashes. The
#      whole codebase becomes pure ASCII (bulletproof for any
#      compiler / code page, no /utf-8 flag needed).
#   3) tools/playverify_r77_r83.md - the keyboard checklist that
#      clears the play-verify backlog item once a PC build runs.
# Idempotent: each part skips if its result is already present.

import sys, os, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = []

# ---------------------------------------------------------------------------
# 1) preflight.sh auto-clean
# ---------------------------------------------------------------------------
def patch_preflight():
    p = os.path.join(ROOT, 'tools/preflight.sh')
    s = open(p, encoding='utf-8').read()
    old = """if [ -d tools/__pycache__ ]; then
  echo "FAIL: tools/__pycache__ present (would ride into the commit)"
  fail=1
else
  echo "OK: no __pycache__"
fi"""
    new = """# R84: auto-clean - bytecode is always regenerable, so the gate
# removes it instead of failing (it rode into a commit once, R80;
# the FAIL taxed every splice round since)
if [ -d tools/__pycache__ ]; then
  rm -rf tools/__pycache__
  echo "NOTE: removed tools/__pycache__ (auto-clean)"
else
  echo "OK: no __pycache__"
fi"""
    if new in s:
        REPORT.append('preflight auto-clean: already patched')
        return True
    if old not in s:
        REPORT.append('preflight auto-clean: FAIL (anchor missing)')
        return False
    open(p, 'w', encoding='utf-8').write(s.replace(old, new))
    REPORT.append('preflight auto-clean: patched')
    return True

OK = patch_preflight()
# R84-CHUNK-1-END
# R84-CHUNK-2-START

# ---------------------------------------------------------------------------
# 2) ASCII normalization (all .cpp/.h)
# ---------------------------------------------------------------------------
DAGGER = '\u00c3\u00a2\u00c2\u0080\u00c2\u00a0'   # double-encoded U+2020 (dead marker)
DEM    = '\u00e2\u0080\u0094'                     # double-encoded U+2014
EM     = '\u2014'                                 # real em-dash
ARR    = '\u00e2\u0086\u0092'                     # double-encoded U+2192

def ascii_pass():
    files = sorted(glob.glob(os.path.join(ROOT, '**/*.cpp'),
                            recursive=True) +
                   glob.glob(os.path.join(ROOT, '**/*.h'),
                            recursive=True))
    files = [f for f in files if '/tools/' not in f.replace('\\', '/')]
    touched, residual = 0, []
    for f in files:
        s = open(f, encoding='utf-8').read()
        if all(ord(c) < 128 for c in s):
            continue   # already pure ASCII (idempotent skip)
        n0 = sum(1 for c in s if ord(c) > 127)
        s = (s.replace(DAGGER, '*')
              .replace(DEM, '-')
              .replace(EM, '-')
              .replace(ARR, '->'))
        open(f, 'w', encoding='utf-8').write(s)
        touched += 1
        REPORT.append('ascii: %s (%d non-ASCII chars normalized)'
                      % (os.path.relpath(f, ROOT), n0))
        if any(ord(c) > 127 for c in s):
            residual.append(os.path.relpath(f, ROOT))
    if touched == 0:
        REPORT.append('ascii pass: all files already pure ASCII')
    if residual:
        REPORT.append('ascii pass: FAIL - residual non-ASCII in '
                      + ', '.join(residual))
        return False
    return True

OK &= ascii_pass()
# R84-CHUNK-2-END
# R84-CHUNK-3-START

# ---------------------------------------------------------------------------
# 3) the play-verify checklist (tools/playverify_r77_r83.md)
# ---------------------------------------------------------------------------
CHECKLIST = """# Play-Verify Checklist: R77-R83 features (run on a PC build)
# Build first (MSVC or mingw): adnd1.exe. Then walk these in order.
# Every line has the keys to press and the exact text to look for.

## Setup
- [ ] New party ([N] at the title). Note one member's name.
- [ ] Delve ([B] leaves town when you want; return with stairs).

## R77-R78: gear and quiver basics
- [ ] Buy arrows at the fletcher ([2], 30 gp). Enter a fight,
      fire missiles ([X]). Arrows deplete; dry quiver falls back
      to melee.
- [ ] Rest at the inn ([3], 10 gp). Slots and quiver return.

## R79: per-member gear caps
- [ ] Smith ([5]): buy a +1 sword; a second sword for the same
      slot is refused (cap). Temple identify ([9]) shows it.

## R80: quiver bundles (the big visible one)
- [ ] Peddler ([M], 500 gp) until you get magic arrows, or win
      them from a lair. dumpEquipment (see R79 key) prints a
      band line like: "  Rolf's quiver: 8 mundane +2 x12".
- [ ] In a fight, fire missiles ([X]): magic shots land before
      mundane ones (front-first FIFO) and the +N applies to-hit
      and damage vs foes needing a plus.

## R81: ring + scroll study
- [ ] Peddler until a Ring of Protection; claim it from the
      treasure screen - the member's AC improves (dumpEquipment
      shows ", ring +1"). A second ring for the same member is
      refused.
- [ ] Buy a spell scroll ([8], 200 gp), return to town, press
      [L] (study desk, new R83 key). Expect one line per scroll:
      "... masters <Spell> from a scroll!" or "... fails to
      master ... the scroll crumbles." Summary: "Studied N
      scroll(s); M spell(s) learned."

## R82: raise dead
- [ ] Let a member die (or load a save with a casualty). With a
      living 7th+ cleric and 1000+ gp in town, press [R].
      Expect the survival line: "... returns to life at
      <cleric>'s word!" (or "... spirit cannot return; the
      offering is spent."). Raised member at 1 hp.

## R83: teleport escape (the finale)
- [ ] MU with INT 15+, level 9+, Teleport known (study scrolls
      or scribe stock), at least one L5 slot. Enter a fight,
      press [C] for the spell menu. NOTE: menu keys are now
      [1-9] then [A-G]; [Esc] closes (C is a cast key now!).
- [ ] Cast Teleport, then [space] to resolve. Expect:
      "The air folds around the company!" then
      "The company teleports away!" - and the company lands in
      TOWN (no spoils, town billing runs: rents/upkeep lines if
      applicable).

## Town screen (R83 layout fix)
- [ ] On the town screen, confirm the overland line is VISIBLE:
      "[O] overland  [V] sea  [W] city - set out" (it was
      overdrawn and invisible since R68), plus the new
      "[L] Study the carried scrolls" and
      "[R] Raise a fallen member - 1,000 gp" lines.

## Sign-off
- [ ] No mojibake anywhere on screen (every string is pure ASCII
      since R84 - report ANY stray glyph, it is a bug).
"""

def write_checklist():
    p = os.path.join(ROOT, 'tools/playverify_r77_r83.md')
    if os.path.exists(p):
        REPORT.append('play-verify checklist: already present')
        return True
    open(p, 'w', encoding='utf-8').write(CHECKLIST)
    REPORT.append('play-verify checklist: written')
    return True

OK &= write_checklist()

print("\n".join(REPORT))
print("R84 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R84-CHUNK-3-END
