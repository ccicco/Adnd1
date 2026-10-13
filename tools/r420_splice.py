#!/usr/bin/env python3
# r420_splice: the UA gap report
# hygiene sweep. A report-only
# round: sixteen boxes whose
# closure evidence (AMENDED
# R392-R399, R401, R419) landed in
# earlier rounds were never
# flipped in the same commit -
# against the report own
# convention. This splice flips
# them and appends six AMENDED
# R420 strata citing the
# superseding reads. Four boxes
# stay OPEN on real PDF-gated
# holes (the IL cantrip
# cast-times, Appendix R,
# Appendix S pantheon prose,
# Appendix T) and the two
# logging layers stay open by
# the user decision. Census
# STAYS 346: no regtest, no
# seed record, no header touch.
import sys

PATH = 'tools/ua_gap_report.md'

FLIPS = [
    ('weight and damage p. 26',
     '- [ ] **Weapons, Weight and Damage by'),
    ('hand-held p. 27',
     '- [ ] **Weapons, hand-held, general'),
    ('hurled and missile p. 28',
     '- [ ] **Weapons, hurled and missile,'),
    ('the new weapons',
     '- [ ] **The new weapons** (pp. 26-28'),
    ('the MU cantrips',
     '- [ ] **The magic-user cantrips** (pp.'),
    ('the cantrip acquisition rules',
     '- [ ] **The cantrip acquisition rules**'),
    ('the random determination tables',
     '- [ ] **The random determination'),
    ('the new potions',
     '- [ ] **The new potions** (p. 90).'),
    ('the new scrolls',
     '- [ ] **The new scrolls** (pp. 91-93).'),
    ('the new rings',
     '- [ ] **The new rings** (pp. 92-94).'),
    ('the new rods and staves',
     '- [ ] **The new rods and staves** (pp.'),
    ('the new wands',
     '- [ ] **The new wands** (pp. 96-97).'),
    ('the new miscellaneous magic',
     '- [ ] **The new miscellaneous magic'),
    ('the new armor and shields and swords',
     '- [ ] **The new armor and shields and'),
    ('the new miscellaneous weapons',
     '- [ ] **The new miscellaneous weapons**'),
    ('Appendix Q',
     '- [ ] **Appendix Q: weaponless combat**'),
]

STRATA = [
    ('weight and damage stratum',
     '      - R337: the fragment-verified',
     """
      - AMENDED R420: flipped - the
        R392 clean read (the manifest
        item above) fills every hole
        (the atlatl 30, the harpoon
        50-60, the falchion 60-80, the
        lasso dash, the garrot 1-6
        misdecode reconciled); the R337
        'stays open' tail is the
        superseded stratum.
"""),

    ('hand-held stratum',
     '      size-class damage, the strength\n'
     '      adjustment rows.\n',
     """
      - AMENDED R420: flipped - the
        clean p. 27 print pinned
        (rules/uahandheld.h, the R392
        manifest item above) - 60
        rows, the footnotes and the
        general note, no holes; the
        box flips with the hygiene
        sweep.
"""),

    ('hurled and missile stratum',
     '      - R338: the fragment-verified',
     """
      - AMENDED R420: flipped - the
        R392 clean read (the manifest
        item above) fills every hole
        (the rate column, the S/M/L
        ranges, the lost AC cells, the
        AC 7-10 columns, the aklys
        10-foot footnote); the R338
        'stays open' tail is the
        superseded stratum.
"""),

    ('the new weapons stratum',
     '      - R340: the fragment-verified',
     """
      - AMENDED R420: flipped - rides
        the DM-section closure (CLOSED
        R373, the same R340 pins, the
        manifest item); the residual
        harpoon failure die, the
        hand-crossbow poison sentence,
        the lasso severing mechanics and
        the DM pp. 77-79 half stay
        flagged pending the PDF/DMG
        read, as recorded there.
"""),

    ('the MU cantrips stratum',
     '      - AMENDED R401: the tier seam',
     """
      - AMENDED R420: flipped - the
        R419 stratum resolves the last
        recorded holes (the two areas,
        the range units, the slow-poison
        defer, the creak reads) and the
        hole flags come off: the MU
        cantrip descriptions stand
        hole-free; the R401/R417 'stays
        open' tails are the superseded
        strata.
"""),

    ('the cantrip acquisition stratum',
     '      may develop at most 3 new\n'
     '      cantrips.\n',
     """
      - AMENDED R420: flipped - the
        cross-referenced DM-section
        item stands CLOSED R369 (rules/
        uacantacq.h, the five random
        bands and the 3-developed cap);
        the players box rides it.
"""),
]

OPEN_EXPECTED = [
    '- [ ] **The illusionist cantrips** (pp.',
    '- [ ] **Appendix R: non-lethal combat**',
    '- [ ] **Appendix S: non-human deities**',
    '- [ ] **Appendix T: pole-arm',
    '- [ ] The code-level logging layer -',
    '- [ ] The game-level logging layer -',
    '- [ ] = open item (worth having; a round',
]

X_EXPECTED = 98          # 82 + 16 flips
STRATA_EXPECTED = 6       # AMENDED R420 count


def build_patches():
    """(label, old, new) - old occurs once pre-patch;
    new contains old; new-in-text means already applied."""
    patches = []
    for label, old in FLIPS:
        patches.append(('flip: ' + label, old,
                        old.replace('- [ ]', '- [x]', 1)))
    for label, anchor, body in STRATA:
        patches.append(('stratum: ' + label, anchor,
                        anchor + body))
    return patches


def verify(text):
    """the mirrored audit semantics - fail on any
    wrong count; returns the bad list."""
    bad = []
    for label, old, new in build_patches():
        if text.count(new) != 1:
            bad.append('patch text: ' + label)
    opens = [l for l in text.split('\n')
             if l.startswith('- [ ]')]
    if sorted(opens) != sorted(OPEN_EXPECTED):
        bad.append('open boxes: %d lines' % len(opens))
    n_x = sum(1 for l in text.split('\n')
              if l.startswith('- [x]'))
    if n_x != X_EXPECTED:
        bad.append('closed boxes: %d' % n_x)
    n_s = text.count('AMENDED R420')
    if n_s != STRATA_EXPECTED:
        bad.append('strata: %d' % n_s)
    for probe in (
            'casting-time fraction holes',
            'pantheon prose ALONE stays',
            'stays open only on the',
            '[x] = verified against the book text'):
        if text.count(probe) < 1:
            bad.append('probe gone: ' + probe)
    for l in text.split('\n'):
        if 'R420' in l and len(l) > 78:
            bad.append('col guard: %d' % len(l))
    return bad


def main():
    with open(PATH) as f:
        text = f.read()

    applied = 0
    already = 0
    for label, old, new in build_patches():
        if text.count(new) == 1 and new != old:
            already += 1
            continue
        n = text.count(old)
        if n != 1:
            sys.stdout.write(
                'R420 splice ABORT: %s: '
                'old text count %d\n'
                % (label, n))
            sys.exit(1)
        text = text.replace(old, new, 1)
        applied += 1

    if applied and already:
        sys.stdout.write(
            'R420 splice ABORT: the mixed '
            'state (applied %d, already %d) '
            '- restore the report and '
            're-run\n' % (applied, already))
        sys.exit(1)

    bad = verify(text)
    if bad:
        sys.stdout.write(
            'R420 splice ABORT: the '
            'verification fails: %s\n'
            % '; '.join(bad))
        sys.exit(1)

    if applied:
        with open(PATH, 'w') as f:
            f.write(text)

    sys.stdout.write(
        'R420 splice: ALL OK (applied %d, '
        'already %d)\n' % (applied, already))
    sys.stdout.write(
        """NOTE: the UA gap report
  hygiene sweep - the 16
  stale boxes flip: their
  closure evidence (AMENDED
  R392-R399, R401, R418,
  R419) had landed in
  earlier rounds but the
  boxes were never flipped
  in the same commit;
  six AMENDED R420 strata
  cite the superseding
  reads; four boxes stay
  open on real PDF-gated
  holes (the IL cantrip
  cast-times, Appendix R,
  Appendix S pantheon
  prose, Appendix T) and
  the two logging layers
  stay open by the user
  decision; census STAYS
  346 (a report-only round
  - no regtest, no seed)
commit: R420: the UA gap report hygiene sweep (census 346)
""")
    sys.exit(0)


if __name__ == '__main__':
    main()

