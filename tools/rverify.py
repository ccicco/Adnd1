#!/usr/bin/env python3
# rverify: the ONE-COMMAND harness (the R428 tooling
# decision). Restores the pristine tree from GitHub raw
# at a given sha, runs the engine twice (the double-run),
# then derives the mutant battery FROM THE SPEC (every
# table cell, every const, every bool, every chain
# boundary) and proves each one trips the audit mirror.
# Mutants are applied to the MODEL (a wrong header); the
# spec stays healthy - that is the real semantics of a
# mis-pin.
# Usage: python3 rverify.py <spec.json> <base-sha>
import copy
import json
import os
import subprocess
import sys
import urllib.request

sys.path.insert(0, os.path.dirname(
    os.path.abspath(__file__)))
from speclib import build_model, audit_bad

SPEC_PATH = sys.argv[1]
SHA = sys.argv[2] if len(sys.argv) > 2 else None
S = json.load(open(SPEC_PATH))
HERE = os.path.dirname(os.path.abspath(__file__))


def fetch(path, sha):
    url = ('https://raw.githubusercontent.com/'
           'ccicco/Adnd1/%s/%s' % (sha, path))
    try:
        with urllib.request.urlopen(url) as r:
            return r.read()
    except urllib.error.HTTPError as e:
        if e.code == 404:
            return b'404: Not Found'
        raise


fails = []

# ---------- 1. restore the pristine tree ----------

if SHA:
    files = [S['regtest'], S['gap_report'],
             S['seed_file'], S['header_file']] \
        + S.get('caller_files', [])
    for p in sorted(set(files)):
        os.makedirs(os.path.dirname(p) or '.',
                     exist_ok=True)
        data = fetch(p, SHA)
        # a 404 raw response is '404: Not Found'
        if data.startswith(b'404'):
            print('RESTORE: %s absent at %s '
                  '(new file - ok)' % (p, SHA[:7]))
            if os.path.exists(p):
                os.remove(p)
        else:
            open(p, 'wb').write(data)
            print('RESTORE: %s <- %s'
                  % (p, SHA[:7]))

# ---------- 2. the double-run ----------

r1 = subprocess.run(
    [sys.executable,
     os.path.join(HERE, 'splice_engine.py'),
     SPEC_PATH], capture_output=True, text=True)
r2 = subprocess.run(
    [sys.executable,
     os.path.join(HERE, 'splice_engine.py'),
     SPEC_PATH], capture_output=True, text=True)
n_patches = len(S['gap_flips']) + 4
ok1 = ('applied %d, already 0' % n_patches) in r1.stdout
ok2 = ('applied 0, already %d' % n_patches) in r2.stdout
print('DOUBLE-RUN: first %s, second %s'
      % ('GREEN' if ok1 else r1.stdout.strip()[-60:],
         'GREEN' if ok2 else r2.stdout.strip()[-60:]))
if not (ok1 and ok2):
    fails.append('the double-run')
    if r1.returncode or r2.returncode:
        print(r1.stdout, r1.stderr,
              r2.stdout, r2.stderr)

# ---------- 3. the mutant battery ----------

M = build_model(S)
base = audit_bad(M, S)
print('BATTERY: healthy base bad = %d'
      % base)
if base != 0:
    fails.append('the healthy base')


def perturb(name, fn):
    m2 = dict(M)
    m2[name] = fn
    return m2


mutants = []

# table cells: one band wrong per column
for t in S.get('tables', []):
    for c, col in enumerate(t['cols']):
        for r in range(len(t['data'])):
            mutants.append((
                '%s[%d][%d]' % (t['name'], r, c), col,
                r, t['data'][r][c]))

# consts and bools
for c in S.get('consts', []):
    mutants.append(('const %s' % c['name'],
                    c['name'], None, c['value']))
for b in S.get('bools', []):
    mutants.append(('bool %s' % b['name'],
                    b['name'], None, b['value']))

# chain limits
for ch in S.get('chains', []):
    for i, lim in enumerate(ch['limits']):
        mutants.append(('chain %s limit %d'
                        % (ch['name'], lim),
                        ch['name'], 'limit', lim))

missed = 0
total = 0
for label, name, r, want in mutants:
    total += 1
    orig = M[name]
    if r == 'limit':
        def mk(i, lim):
            def f(x, _o=orig, _i=i, _l=lim):
                # shift this one limit by +1
                base_v = _o(x)
                return base_v
            return f
        # a limit shift needs the chain rebuilt; emulate:
        # value just at the limit must land one band high
        def f(x, _lim=lim, _o=orig, _n=name):
            if x == _lim:
                return _o(x) + 1
            return _o(x)
        m2 = perturb(name, f)
    elif r is None and isinstance(want, bool):
        m2 = perturb(
            name, (lambda w: lambda *a: not w)(want))
    elif r is None:
        m2 = perturb(
            name, (lambda w: lambda *a: w + 1)(want))
    else:
        def f(x, _r=r, _w=want, _o=orig):
            if x == _r:
                return _w + 1
            return _o(x)
        m2 = perturb(name, f)
    bad = audit_bad(m2, S)
    if bad == 0:
        missed += 1
        print('  MISSED: %s' % label)
print('BATTERY: %d mutants, %d missed'
      % (total, missed))
if missed:
    fails.append('the battery (%d missed)' % missed)

# ---------- the verdict ----------

if fails:
    print('RVERIFY: RED - %s' % '; '.join(fails))
    sys.exit(1)
print('RVERIFY: GREEN - restore, double-run, '
      'battery all clean')

