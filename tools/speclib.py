#!/usr/bin/env python3
# speclib: the shared spec model + audit mirror used by
# splice_engine.py (emit + verify) and rverify.py (the
# one-command harness). Single source of truth: a check
# exists ONCE here, fail-on-wrong, and both the emitted
# C++ audit and the Python battery derive from the spec.
def build_model(spec):
    m = {}
    for c in spec.get('consts', []):
        m[c['name']] = (lambda v: (lambda *a: v))(c['value'])
    for b in spec.get('bools', []):
        m[b['name']] = (lambda v: (lambda *a: v))(b['value'])
    for sw in spec.get('switches', []):
        vals = list(sw['values'])
        dflt = sw.get('default', vals[-1] if vals else None)
        m[sw['name']] = (lambda vs, d:
                         (lambda b:
                          vs[b] if 0 <= b < len(vs) else d))(vals, dflt)
    for t in spec.get('tables', []):
        sent = t.get('sentinel')
        for c, col in enumerate(t['cols']):
            colvals = [row[c] for row in t['data']]
            dflt = t.get('col_default', sent)
            m[col] = (lambda vs, d:
                      (lambda b:
                       vs[b] if 0 <= b < len(vs) else d))(colvals, dflt)
    for ch in spec.get('chains', []):
        lims = list(zip(ch['limits'],
                        range(len(ch['limits']))))
        tail = ch['tail']
        m[ch['name']] = (lambda ls, t:
                         (lambda x:
                          next((r for lim, r in ls
                              if x <= lim),
                              t)))(lims, tail)
    return m


def audit_bad(m, spec):
    bad = 0
    for c in spec.get('consts', []):
        if m[c['name']]() != c['value']:
            bad += 1
    for b in spec.get('bools', []):
        if m[b['name']]() != (True if b['value'] else False):
            bad += 1
    for t in spec.get('tables', []):
        cols = t['cols']
        data = t['data']
        for r, row in enumerate(data):
            for c, col in enumerate(cols):
                if m[col](r) != row[c]:
                    bad += 1
        if t.get('sentinel_census'):
            sent = t.get('sentinel')
            for c, col in enumerate(cols):
                want = t['sentinel_census'][c]
                got = sum(1 for r in range(len(data))
                          if m[col](r) == sent)
                if got != want:
                    bad += 1
        pr = t.get('pair')
        if pr:
            for r in range(len(data)):
                nu = m[pr['num']](r)
                de = m[pr['den']](r)
                sent = t.get('sentinel')
                if ((nu == sent)
                        != (de == sent)):
                    bad += 1
                elif nu != sent and de != nu + 1:
                    bad += 1
    for ch in spec.get('chains', []):
        f = m[ch['name']]
        lims = ch['limits']
        # the bands are contiguous and 0-based: each limit
        # sits at its own band index, the value just above
        # the previous limit sits at this band, the value
        # below the first limit stays in band 0, and the
        # value above the last limit is the tail
        if f(lims[0] - 1) != 0:
            bad += 1
        for i, lim in enumerate(lims):
            if f(lim) != i:
                bad += 1
            if i > 0 and f(lims[i - 1] + 1) != i:
                bad += 1
        if f(lims[-1] + 1) != ch['tail']:
            bad += 1
    for ex in spec.get('examples', []):
        if eval(ex['expr'], {}, {'m': m}):
            bad += 1
    for ex in spec.get('table_checks', []):
        if eval(ex['expr'], {}, {'m': m}):
            bad += 1
    return bad

