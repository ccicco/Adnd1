#!/usr/bin/env python3
# r597_cleanup.py -- the R597 tool round: the UA logging
# reclassification. NOT a splice and NOT a content round: it
# patches tools/ua_gap_report.md in place, idempotently
# (run twice -> applied 1, already 1, exactly like the
# splice engine's idempotency gate). The patch site must
# match EXACTLY ONCE or the run aborts with no writes.
#
# The one fix:
#   tools/ua_gap_report.md -- the two open logging boxes
#   (the code-level logging layer, the game-level logging
#   layer) are reclassified from open `[ ]` items to a
#   single DEFERRED line. Ruling 2026-10-17 (post-R596
#   maintenance round): the logging layers are NOT tied
#   to any book -- they belong to the debugging phases
#   only. They never closed a UA page, so they do not
#   belong among the book's open boxes. DEFERRED is the
#   report's own category for wants gated on an engine
#   layer not yet built, and the report prose already
#   names the game-level layer as the closure-criterion
#   instrument, so the reference stays coherent. After
#   this round the UA report sits at 102 closed / 0
#   open and every gap report in the repo is at 0 open
#   (MotP 90/0, DMG 81/0, PHB 49/0, DSG 155/0, WSG
#   186/0).
#
# The ritual is untouched: no regtest.cpp, no seed, no
# headers, no census change (census stays 520).
#
# Usage:  python3 tools/r597_cleanup.py

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def die(msg):
    print('CLEANUP ABORT: %s' % msg)
    sys.exit(1)

OLD = """- [ ] The code-level logging layer -
      bug and missing-functionality
      discovery at the code level.
- [ ] The game-level logging layer -
      playtest evidence; the closure
      criterion instrument."""

NEW = """- DEFERRED: the two logging layers (a
      debugging-phase engine layer, not
      UA book material - ruling
      2026-10-17, R597; the code-level
      layer for bug and missing-
      functionality discovery, the
      game-level layer as the playtest
      evidence and the closure-criterion
      instrument)."""

rel = 'tools/ua_gap_report.md'
p = os.path.join(ROOT, rel)
try:
    with open(p) as fh:
        t = fh.read()
except OSError as e:
    die('cannot read %s: %s' % (rel, e))

n_old = t.count(OLD)
n_new = t.count(NEW)
if n_old == 1 and n_new == 0:
    applied, already = 1, 0
elif n_old == 0 and n_new == 1:
    applied, already = 0, 1
else:
    die('the patch site does not resolve exactly once '
        '(found old %d, new %d) - restore the tree and '
        're-run' % (n_old, n_new))

if applied:
    t = t.replace(OLD, NEW, 1)
    with open(p, 'w') as fh:
        fh.write(t)

# ---------- verification (both runs) ----------

# exact open-box check (the legend line says '- [ ] = open')
nopen = len([l for l in t.split('\n')
             if l.lstrip().startswith('- [ ] ')
             and 'open item' not in l])
nclosed = t.count('- [x]')
if applied:
    if nopen != 0:
        die('the UA open count is %d, want 0' % nopen)
    if nclosed != 102:
        die('the UA closed count is %d, want 102 '
            '(untouched)' % nclosed)
else:
    if nopen != 0 or nclosed != 102:
        die('the already-run verification drifted '
            '(open %d, closed %d)' % (nopen, nclosed))

print('R597 cleanup: ALL OK (applied %d, already %d)'
      % (applied, already))
print('UA gap report: %d closed / %d open - every gap '
      'report in the repo now sits at 0 open'
      % (nclosed, nopen))
print('commit: R597: the UA logging reclassification '
      '(a tool round; census 520)')
