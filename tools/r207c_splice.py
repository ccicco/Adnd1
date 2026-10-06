#!/usr/bin/env python3
# R207c gate splice: teach the preflight hygiene
# gate the tool-only round shape.
#
# The R207c round ships tools/audit_eval.py - a
# standalone tool, no splice, no other change.
# The R112c hygiene gate (born of the 7a86ee7
# lesson) FAILs that shape as a never-ran
# splice, RED on a clean delivery. The gate
# now distinguishes the shapes: untracked
# files that are all plain tools/*.py (never
# a *splice*.py) with no tracked modification
# are a tool round - a NOTE, not a failure.
# Anything else keeps the old FAIL.
# Patches: 1 (tools/preflight.sh).

NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: tools/preflight.sh - the tool-only
# round shape is a NOTE, not the 7a86ee7 FAIL
# ---------------------------------------------------------------------------

old1 = (
    '  if git diff --quiet && git diff --cached --quiet; then' + NL +
    '    echo "HYGIENE FAIL: untracked file(s) present but NO tracked file modified"' + NL +
    '    echo "  - did the splice run? (the 7a86ee7 lesson)"' + NL +
    '    fail=1' + NL +
    '  fi' + NL +
    'fi')

new1 = (
    '  if git diff --quiet && git diff --cached --quiet; then' + NL +
    '    # R207c: the tool-only round shape - every untracked' + NL +
    '    # file a plain tools/*.py, never a splice script, with' + NL +
    '    # no tracked modification - is a tool delivery, not' + NL +
    '    # the 7a86ee7 never-ran-splice shape' + NL +
    '    tools_only=1' + NL +
    '    for f in $(git status --porcelain | grep ' + chr(39) + '^??' + chr(39) + ' | cut -c4-); do' + NL +
    '      case "$f" in' + NL +
    '        tools/*.py)' + NL +
    '          case "$f" in *splice*) tools_only=0 ;; esac' + NL +
    '          ;;' + NL +
    '        *) tools_only=0 ;;' + NL +
    '      esac' + NL +
    '    done' + NL +
    '    if [ "$tools_only" = 1 ]; then' + NL +
    '      echo "NOTE: tool-only round (R207c) - no splice expected, new tool(s) belong in this commit"' + NL +
    '    else' + NL +
    '      echo "HYGIENE FAIL: untracked file(s) present but NO tracked file modified"' + NL +
    '      echo "  - did the splice run? (the 7a86ee7 lesson)"' + NL +
    '      fail=1' + NL +
    '    fi' + NL +
    '  fi' + NL +
    'fi')

patch('tools/preflight.sh',
      'R207c: the tool-only round shape',
      old1,
      new1)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 1, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R207c gate splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R207c gate note: 1 patch; the hygiene gate now knows the')
print('tool-only round shape - untracked plain tools/*.py with no')
print('splice is a NOTE, not the 7a86ee7 FAIL; census stays 123.')
print('commit: rides the R207c commit - R207c: the literal audit')
print('evaluator - tools/audit_eval.py, the sim-from-intent fix')

