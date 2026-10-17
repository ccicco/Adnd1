#!/usr/bin/env python3
# r515_cleanup.py -- the R515 tool round: the warning-clean build,
# the quiet battery display and the warning gate. NOT a splice:
# it patches tracked source/tool files in place, idempotently
# (run twice -> applied N, already N, exactly like the splice
# engine's idempotency gate). Every patch site must match
# EXACTLY ONCE or the run aborts with no writes (all-or-nothing,
# per file: patches are gathered first, applied only if every
# site resolves).
#
# The three fixes:
#   1. rules/character.cpp -- AbilityScores::set() gains a
#      `default: break;` so the -Wswitch warning on
#      ABILITY_COUNT dies (the getter already had its default).
#   2. regtest.cpp -- the R320 statusName comparison becomes a
#      std::strcmp, so the -Wstring-compare warning dies AND
#      the latent pointer-compare bug with it: `!= "Breathing"`
#      compared a const char* against a string literal, which
#      checks IDENTITY, not content. <cstring> is already
#      included (line 318).
#   3. tools/preflight.sh -- step 2 grows the R515 quiet battery
#      display (green `audit: bad 0` lines are filtered from the
#      TERMINAL VIEW only; tee still writes the complete output
#      to $batfile so the R112c census gate is byte-identical)
#      and the warning gate: the build's stderr is captured and
#      ANY warning ends RED (the build is warning-clean now, so
#      a warning can never again ride unseen next to known
#      ones).
#
# The splice ritual is untouched: the census grep pattern
# ('audit: bad %d' printfs), the R227 anchor and the audit
# block ordering are all preserved verbatim.
#
# Usage:  python3 tools/r515_cleanup.py     (then preflight)

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def die(msg):
    print('CLEANUP ABORT: %s' % msg)
    sys.exit(1)

def patch_file(relpath, patches):
    """patches: list of (old, new, label). All-or-nothing per file."""
    p = os.path.join(ROOT, relpath)
    try:
        with open(p) as fh:
            t = fh.read()
    except OSError as e:
        die('cannot read %s: %s' % (relpath, e))
    applied = 0
    already = 0
    work = t
    for old, new, label in patches:
        n = work.count(old)
        if n != 1:
            # already applied?
            if work.count(new) == 1 and n == 0:
                already += 1
                continue
            die('%s: the %s patch site matches %d times (want 1) - no writes'
                % (relpath, label, n))
        if t.count(old) != 1:
            die('%s: the %s patch site drifted mid-run - no writes'
                % (relpath, label))
        work = work.replace(old, new, 1)
        applied += 1
    if applied or already:
        with open(p, 'w') as fh:
            fh.write(work)
    print('%s: applied %d, already %d' % (relpath, applied, already))
    return applied, already

total_applied = 0
total_already = 0

# ---- 1. rules/character.cpp: the -Wswitch fix -------------------------
res = patch_file('rules/character.cpp', [(
    '        case ABILITY_CHA: cha  = v; break;\n    }\n',
    '        case ABILITY_CHA: cha  = v; break;\n'
    '        default: break;  // R515: ABILITY_COUNT is never set (the getter has its default)\n'
    '    }\n',
    'the -Wswitch default')])
total_applied += res[0]; total_already += res[1]

# ---- 2. regtest.cpp: the -Wstring-compare / pointer-compare fix -------
res = patch_file('regtest.cpp', [(
    '            if (spelleffects::statusName(\n'
    '                    spelleffects::STATUS_WATERBREATHING)\n'
    '                != "Breathing") ++bad;\n',
    '            // R515: a strcmp, not a pointer compare against the literal\n'
    '            // (the old != "Breathing" checked identity, not content).\n'
    '            if (std::strcmp(spelleffects::statusName(\n'
    '                    spelleffects::STATUS_WATERBREATHING),\n'
    '                    "Breathing") != 0) ++bad;\n',
    'the statusName strcmp')])
total_applied += res[0]; total_already += res[1]

# ---- 3. tools/preflight.sh: the quiet display + the warning gate ------
res = patch_file('tools/preflight.sh', [(
    'batfile=$(mktemp)\n'
    'if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \\\n',
    '# R515: the quiet battery display - green audit lines are\n'
    '# filtered from the TERMINAL VIEW ONLY; tee still writes the\n'
    '# complete output to $batfile, so the census gate below sees\n'
    '# every audit line exactly as before. A nonzero bad count does\n'
    '# not match the filter and stays visible. The build\'s stderr is\n'
    '# captured for the warning gate: the build is warning-clean as\n'
    '# of R515 (the character.cpp -Wswitch and regtest.cpp\n'
    '# -Wstring-compare fixes), so ANY warning now ends RED.\n'
    'batfile=$(mktemp)\n'
    'warnfile=$(mktemp)\n'
    'if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \\\n',
    'the quiet-display header'),
    (
    '  -o regtest -L"$PREFIX/lib" -llua5.4 && ./regtest | tee "$batfile"; then\n'
    '  [ "${PIPESTATUS[0]}" = 0 ] || fail=1\n'
    'else\n'
    '  fail=1\n'
    'fi\n',
    '  -o regtest -L"$PREFIX/lib" -llua5.4 2>"$warnfile" \\\n'
    '  && ./regtest | tee "$batfile" | grep -v \'audit: bad 0$\'; then\n'
    '  [ "${PIPESTATUS[0]}" = 0 ] || fail=1\n'
    'else\n'
    '  fail=1\n'
    'fi\n'
    'if [ -s "$warnfile" ]; then\n'
    '  echo "WARN FAIL: the battery build emitted warnings (the R515 warning-clean rule):"\n'
    '  cat "$warnfile"\n'
    '  fail=1\n'
    'else\n'
    '  echo "BUILD: 0 warnings (the R515 warning gate)"\n'
    'fi\n'
    'rm -f "$warnfile"\n',
    'the warning gate')])
total_applied += res[0]; total_already += res[1]

# ---- post-verification -------------------------------------------------
if total_applied == 0 and total_already == 0:
    die('no patch sites resolved - nothing to do, nothing written')

p = os.path.join(ROOT, 'regtest.cpp')
with open(p) as fh:
    rt = fh.read()
n_audit = rt.count('audit: bad')
if ') != "Breathing") ++bad;' in rt:
    die('the pointer compare still lives in regtest.cpp')
p = os.path.join(ROOT, 'tools/preflight.sh')
with open(p) as fh:
    pf = fh.read()
for marker in ('warnfile=$(mktemp)', 'grep -v \'audit: bad 0$\'',
               'WARN FAIL', '2>"$warnfile"'):
    if marker not in pf:
        die('the preflight patch is incomplete: missing %r' % marker)

print('R515 cleanup: ALL OK (applied %d, already %d); '
      'the census printf shape is untouched (%d audit: bad sites)'
      % (total_applied, total_already, n_audit))
