#!/usr/bin/env python3
# build_spec_general: the GENERAL spec builder (the R428
# tooling follow-up, 2026-10-14). A round is now a small
# DATA MODULE: the verified ground truth + the round
# labels + the gap-report flip texts. Everything else -
# the census, the inline count, the sentinel censuses,
# the gap closed/open counts, the include anchor, the
# seed key, the anchors - is DERIVED from the repo at
# the base sha. The per-round build script shrinks to a
# data table; the general part lives in the repo.
#
# Usage (per round, on the Vibe side):
#     import build_spec_general as G
#     G.build(SPEC_PATH, BASE_SHA, ROUND)
# where ROUND is the dict below with only these keys
# REQUIRED: round, title, prefix, header_file,
# audit_label, include_comment, banner,
# header_sections, gap_flips, prev_record - plus the
# content pools (consts/bools/chains/switches/tables/
# examples). Everything else auto-fills.
import json
import os
import sys
import urllib.request

REPO = 'ccicco/Adnd1'
WIDTH = 78

# the fixed anchors (stable across the WSG arc)
AUDIT_ANCHOR = ('    // ---- R227: the wis mental '
                'save wiring audit ----')
SEED_ANCHOR = '## Knowledge maintenance'
SEED_FILE = ('doc/vibe/'
             'adnd1_knowledge_seed_v2.md')
REGTEST = 'regtest.cpp'
GAP_REPORT = 'tools/wsg_gap_report.md'
CALLER_FILES = ['dm/treasure.cpp',
                'game/state_combat.cpp']


def raw(path, sha):
    url = ('https://raw.githubusercontent.com/'
           '%s/%s/%s' % (REPO, sha, path))
    try:
        with urllib.request.urlopen(url) as r:
            return r.read().decode('utf-8')
    except urllib.error.HTTPError as e:
        if e.code == 404:
            return None
        raise


def die(msg):
    print('build_spec ABORT: ' + msg)
    sys.exit(1)


def wrap78(text, indent='  '):
    # the seed-record wrap: greedy, whole words
    words = text.split(' ')
    out = []
    cur = indent
    for w in words:
        cand = (cur + ' ' + w
                if cur != indent else cur + w)
        if len(cand) > WIDTH and cur != indent:
            out.append(cur.rstrip())
            cur = indent + w
        else:
            cur = cand
    out.append(cur.rstrip())
    return out


def build(spec_path, base_sha, R):
    # ---------- the required keys ----------
    for k in ('round', 'title', 'prefix',
              'header_file', 'audit_label',
              'include_comment', 'banner',
              'header_sections', 'gap_flips',
              'prev_record'):
        if k not in R:
            die('the round data is missing '
                'the key %r' % k)
    for k in ('title', 'provenance'):
        if k not in R['banner']:
            die('the banner is missing %r' % k)

    # ---------- the seed record ----------
    rec = R['prev_record']
    if isinstance(rec, str):
        rec = wrap78(rec)
    rec = [l.rstrip() for l in rec]
    if max(len(l) for l in rec) > WIDTH:
        die('a seed record line is over '
            '%d cols' % WIDTH)
    prev_key = rec[0]
    if not prev_key.startswith('- R'):
        die('the seed record must start '
            'with the round headline')

    # ---------- the census at the base sha ----------
    rt = raw(REGTEST, base_sha)
    if rt is None:
        die('regtest.cpp is absent at %s'
            % base_sha[:7])
    census_before = rt.count('audit: bad')

    # ---------- the include anchor: the include of
    # the PREVIOUS round (the highest R-number in the
    # include comments - the WSG/UA convention) ----------
    import re as _re
    best, best_n = None, -1
    for l in rt.split('\n'):
        if not l.startswith('#include "rules/'):
            continue
        m = _re.search(r'// R(\d+):', l)
        if m and int(m.group(1)) > best_n:
            best, best_n = l, int(m.group(1))
    if best is None:
        die('no round-numbered rules/ include '
            'found at the base sha')
    include_after = best

    # ---------- the gap counts at the base sha
    # plus the round's box flips ----------
    gr = raw(GAP_REPORT, base_sha)
    if gr is None:
        die('the gap report is absent at '
            'the base sha')
    closed0 = gr.count('- [x]')
    open0 = len([l for l in gr.split('\n')
                 if l.lstrip()
                 .startswith('- [ ]')])
    box_flips = [f for f in R['gap_flips']
                 if f['from'].lstrip()
                 .startswith('- [ ]')]
    gap_census = {'closed': closed0 + len(box_flips),
                  'open': open0 - len(box_flips)}

    # ---------- the sentinel censuses and the
    # inline count: COMPUTED, never asserted ----------
    inline = 0
    for t in R.get('tables', []):
        sent = t.get('sentinel')
        ncol = len(t['cols'])
        if len(t['data'][0]) != ncol:
            die('the %s row width is %d, '
                'the cols say %d'
                % (t.get('name'),
                   len(t['data'][0]), ncol))
        if any(len(r) != ncol
               for r in t['data']):
            die('the %s grid is ragged'
                % t.get('name'))
        if sent is not None:
            t['sentinel_census'] = [
                sum(1 for row in t['data']
                    if row[c] == sent)
                for c in range(ncol)]
        ss = t.get('sentinel_sum')
        if ss and t.get('sentinel_census'):
            total = sum(t['sentinel_census'][c]
                        for c in ss['cols'])
            want = next(
                c['value']
                for c in R.get('consts', [])
                if c['name'] == ss['const'])
            if total != want:
                die('the %s sentinel sum is '
                    '%d but %s is %d'
                    % (t.get('name'), total,
                       ss['const'], want))
        inline += ncol
    inline += len(R.get('consts', []))
    inline += len(R.get('bools', []))
    inline += len(R.get('chains', []))
    inline += len(R.get('switches', []))

    # ---------- the audit-label bound (R389) ----------
    lbl = R['audit_label']
    if len('        printf("%s: bad '
           '%%d\\n", bad);' % lbl) > WIDTH:
        die('the audit label is too long '
            'for one line: %r' % lbl)

    # ---------- assemble ----------
    S = {
        'round': R['round'],
        'title': R['title'],
        'prefix': R['prefix'],
        'header_file': R['header_file'],
        'regtest': REGTEST,
        'gap_report': GAP_REPORT,
        'seed_file': SEED_FILE,
        'caller_files': R.get('caller_files',
                              CALLER_FILES),
        'census_before': census_before,
        'inline_count': inline,
        'audit_label': lbl,
        'audit_comment': R['audit_comment'],
        'banner': R['banner'],
        'consts': R.get('consts', []),
        'bools': R.get('bools', []),
        'chains': R.get('chains', []),
        'switches': R.get('switches', []),
        'tables': R.get('tables', []),
        'examples': R.get('examples', []),
        'table_checks': R.get('table_checks', []),
        'header_sections': R['header_sections'],
        'gap_flips': R['gap_flips'],
        'gap_census': gap_census,
        'include_comment':
            R['include_comment'],
        'include_after': include_after,
        'audit_anchor': R.get('audit_anchor',
                              AUDIT_ANCHOR),
        'seed_anchor': R.get('seed_anchor',
                             SEED_ANCHOR),
        'prev_seed_key': prev_key,
        'prev_record': rec,
    }
    json.dump(S, open(spec_path, 'w'), indent=1)
    print('spec written: %s' % spec_path)
    print('  round R%d, census %d -> %d, '
          '%d inlines, gap %d closed / '
          '%d open'
          % (R['round'], census_before,
             census_before + 1, inline,
             gap_census['closed'],
             gap_census['open']))
    return S

