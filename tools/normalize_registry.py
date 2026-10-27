#!/usr/bin/env python3
"""normalize_registry.py - the R879 maintenance-arc normalizer.

One idempotent pass over every .lua def in monsters/monsters:
each def is rewritten in the FINAL post-DDG schema (the 57-key
mm2lua FIELD_ORDER) with FULL-FIELD emission - every key
present, sentinels where the book prints nothing ("n/a" for
strings, -1 for ints; both distinct from every real print
value, the printed "Nil" included).

Byte-stable: a second run over a normalized file changes
nothing (the canonical key order, the verbatim raw values and
the interior provenance comments are preserved). DO NOT
hand-edit the defs; re-run the normalizer instead.

Usage:
  python3 tools/normalize_registry.py            # rewrite
  python3 tools/normalize_registry.py --census  # count only
"""
import glob
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from mm2lua import FIELD_ORDER, INT_KEYS, STRING_SENTINEL, \
    INT_SENTINEL

REG = os.path.normpath(
    os.path.join(HERE, os.pardir, 'monsters', 'monsters'))

PAT = re.compile(r'^  (\w+) = (.*)$')


def parse(path):
    """Return (header_lines, fields, comments).

    fields maps key -> verbatim raw value text; comments maps
    key -> the interior provenance comment lines that preceded
    it (they ride along when the keys reorder). A value ends at
    the next field-start line or the closing brace, quote
    parity gating (multi-line strings are real).
    """
    lines = [l.rstrip('\n')
             for l in open(path, encoding='utf-8')]
    i = 0
    hdr = []
    while i < len(lines) and not lines[i].startswith('return {'):
        hdr.append(lines[i])
        i += 1
    i += 1
    fields, cmts, pend = {}, {}, []
    while i < len(lines):
        ln = lines[i]
        if ln == '}' or ln == '':
            i += 1
            continue
        if ln.lstrip().startswith('--'):
            pend.append(ln)
            i += 1
            continue
        m = PAT.match(ln)
        if not m:
            raise ValueError('%s: %r' % (path, ln))
        key, buf = m.group(1), [m.group(2)]
        if pend:
            cmts[key] = pend
            pend = []
        i += 1
        while i < len(lines):
            nxt = lines[i]
            joined = '\n'.join(buf)
            nq = re.sub(r'\\.', '', joined).count('"')
            ended = (nq % 2 == 0
                     and (nxt == '}'
                          or PAT.match(nxt) is not None))
            if ended:
                break
            buf.append(nxt)
            i += 1
        val = '\n'.join(buf)
        if val.rstrip().endswith(','):
            val = val.rstrip()[:-1].rstrip()
        fields[key] = val
    return hdr, fields, cmts


def render(hdr, fields, cmts):
    out = list(hdr) + ['return {']
    for k in FIELD_ORDER:
        if k in cmts:
            out.extend(cmts[k])
        if k in fields:
            out.append('  %s = %s,' % (k, fields[k]))
        elif k in INT_KEYS:
            out.append('  %s = %d,' % (k, INT_SENTINEL))
        else:
            out.append('  %s = "%s",' % (k, STRING_SENTINEL))
    out.append('}')
    return '\n'.join(out) + '\n'


def book_of(fields):
    m = re.fullmatch(
        r'"(MM1|MM2|FF|OA|WSG|MOP|DDG)"',
        fields.get('source', ''))
    if not m:
        raise ValueError('unknown source: %r'
                         % fields.get('source'))
    return m.group(1)


def main():
    census_only = '--census' in sys.argv[1:]
    order = set(FIELD_ORDER)
    census = {k: {} for k in FIELD_ORDER}
    books = {}
    paths = sorted(glob.glob(
        os.path.join(REG, '*', '*.lua')))
    for p in paths:
        hdr, f, cmts = parse(p)
        for k in f:
            if k not in order:
                raise ValueError('%s: unknown key %s'
                                 % (p, k))
        b = book_of(f)
        books[b] = books.get(b, 0) + 1
        for k in f:
            census[k][b] = census[k].get(b, 0) + 1
        if census_only:
            continue
        new = render(hdr, f, cmts)
        old = open(p, encoding='utf-8').read()
        if new != old:
            with open(p, 'w', encoding='utf-8') as fh:
                fh.write(new)
            print('rewrote %s' % p)
    total = sum(books.values())
    print('defs: %d  %s' % (total, ' '.join(
        '%s=%d' % kv for kv in sorted(books.items()))))
    if census_only:
        for k in FIELD_ORDER:
            print('%-20s %5d'
                  % (k, sum(census[k].values())))


if __name__ == '__main__':
    main()
