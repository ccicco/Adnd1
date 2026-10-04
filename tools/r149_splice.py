#!/usr/bin/env python3
# tools/r149_splice.py - R149, REPORT-ONLY: the book-verify
# pass. Seven patches to tools/dmg_gap_report.md, no code and
# no battery change (AUDIT CENSUS stays 67).
#
# The fresh DMG/PHB uploads (2026-10-04) were diffed end to
# end against the repo, paying the standing verification
# debt named by the R148 book-verify box:
#
# (a) HEADER NOTE: the R149 round note joins the log.
# (b) R144 BOX: the p.71 Example of Melee is fully readable
#     in the fresh DMG upload - every pinned number prints.
#     CORRECTION: the example axe is a HAND axe, and its
#     +1 vs. no armor is the p.38 hand axe row AC 10 cell -
#     NOT an editorial error (the battle-axe claim was a
#     misreading of the example weapon). Bonus: the example
#     dwarf, CON 16, saves at +4 - exactly the R147 formula.
# (c) R145 BOX: the printed p.38 charts verify eight of the
#     fifteen rows cell for cell (dagger, club, morning
#     star, long sword, short sword, short bow, long bow,
#     sling bullet); the bow-row quirk is the premium print
#     itself, so that worry is PAID. Four rows print
#     locally-clean disagreements and the rest are
#     OCR-fused beyond reading - the same chart carries
#     gross fusion artifacts in a dozen adjacent rows, so
#     the upload cannot arbitrate them; those cells stay
#     compilation-pinned, the debt narrowed and named. The
#     compilation site itself has gone dark.
# (d) R146 BOX: both city flavor tables print exactly as
#     pinned, haughty confirmed. CORRECTION: noble gender
#     is nobleman-with-retainers 75% / noblewoman 25% (the
#     70/25/no-last-5 reading was wrong).
# (e) R146-FICTION OPEN BOX: the noble gender hole is
#     CLOSED (a coin now, not a table); the ruffian note
#     and the sedan-chair detail remain.
# (f) THE BOOK-VERIFY BOX ITSELF flips closed with the
#     full pass detail.
# (g) APPENDIX I OPEN BOX: dungeon dressing (pp.219-221)
#     is unpinned - named from the fresh read (the repo
#     pins Appendix A dressing only, R124).
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file contains
# ZERO backslash characters, and no content string embeds a
# literal apostrophe (the R133b + R147 chunk-delivery
# lessons - the few the anchors need are built with AP).
# Commit: "R149: book-verify pass paid - trap list,
# wilderness, city flavor, p.71 verified (report-only)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
AP = chr(39)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# ---- (1) the header round note ----
old_head = NL.join([
    'rewired to the exact tables - the',
    'verification debt paid. Census 42.',
    '',
    'Categories:',
])
new_head = NL.join([
    'rewired to the exact tables - the',
    'verification debt paid. Census 42.',
    'R149 CLOSED the book-verify pass (the standing',
    'debt): the fresh DMG/PHB uploads diffed end to',
    'end - the Appendix G trap list, the Appendix H',
    'attribute fragments, the Faerie / Pleistocene /',
    'Age of Dinosaurs wilderness tables, the printing',
    'variants, the city flavor cells and the p.71',
    'example all verify; the p.38 rows eight of',
    'fifteen, the rest unarbitratable against the',
    'upload OCR; the noble gender split corrected to',
    '75/25; the axe in the p.71 example is a hand',
    'axe, its +1 no error at all. Appendix I dressing',
    'named unpinned (a new open box). The compilation',
    'site has gone dark - the fresh uploads are the',
    'last standing source. Census 67.',
    '',
    'Categories:',
])

# ---- (2) the R144 box tail ----
old_144 = NL.join([
    '      see the R147 boxes). Pinned by the',
    '      R144 golden melee audit; census 62.',
])
new_144 = NL.join([
    '      see the R147 boxes). R149 BOOK-VERIFIED',
    '      against the fresh DMG upload (the p.71',
    '      example is fully readable there): every',
    '      pinned number prints as pinned - the seven',
    '      matrix cells, the STR +1/+1, the F6 spell',
    '      save of 14, the mace +1 (17 - 1 = 16), the',
    '      sling bullet +3 vs. no armor, the hammer',
    '      +1 vs. scale, and both acknowledged errors',
    '      print as called (the staff -7 mislabeled a',
    '      sword, and 18 - 7 is not 20; the magic',
    '      missile 4-10). AXE CORRECTION: the example',
    '      weapon is a HAND axe, and its +1 vs. no',
    '      armor is the p.38 hand axe row AC 10 cell -',
    '      NOT an editorial error (the battle-axe',
    '      reading was never in play; the R145 box is',
    '      corrected with it). BONUS CONFIRMATION: the',
    '      example dwarf, constitution 16, saves at',
    '      +4 - exactly the R147 formula (16 x 2 / 7',
    '      = 4) - and needs 10 instead of 14, the same',
    '      F6 spell save cell the engine pins. Pinned',
    '      by the',
    '      R144 golden melee audit; census 62.',
])

# ---- (3) the R145 box tail ----
old_145 = NL.join([
    '      example' + AP + 's axe ' + AP + '+1 vs. no armor' + AP + ' remains one of its',
    '      acknowledged editorial errors (the p.38 battle axe row',
    '      reads +2, and the engine follows p.38); the example' + AP + 's',
    '      hammer has no engine weapon (the 15-weapon registry',
    '      carries no war hammer - the R144 pin stands). Pinned by',
    '      the R145',
    '      weapon table audit; census 63.',
])
new_145 = NL.join([
    '      example' + AP + 's axe is a HAND axe, and its +1 vs. no armor',
    '      is the p.38 hand axe row AC 10 cell - NOT an editorial',
    '      error (the R149 fresh-print correction: the battle-axe',
    '      claim was a misreading of the example weapon; the R144',
    '      box is corrected with it); the example' + AP + 's',
    '      hammer has no engine weapon (the 15-weapon registry',
    '      carries no war hammer - the R144 pin stands). R149',
    '      BOOK-VERIFIED against the fresh PHB upload, the',
    '      printed p.38 charts: eight of the fifteen rows verify',
    '      cell for cell - dagger, club, morning star, long',
    '      sword and short sword from the melee chart, short',
    '      bow, long bow and sling bullet from the missile',
    '      chart - and the bow-row worry is PAID: the premium',
    '      print itself shows the short bow -4 to -1 gap and',
    '      the long bow single -1, exactly as pinned (the',
    '      composite bows print the same shape). The sling',
    '      bullet AC 10 cell of +3 is independently confirmed',
    '      by the p.71 example (R144). The premium melee',
    '      chart prints only AC 2-10 - the AC 0/1 columns',
    '      stay compilation-sourced. The other seven rows',
    '      cannot be arbitrated against this upload: four',
    '      print locally-clean disagreements (hand axe,',
    '      flail, quarterstaff, light crossbow) and the rest',
    '      are OCR cell-fused beyond reading (mace, battle',
    '      axe, spear) - the same chart carries gross fusion',
    '      artifacts in a dozen adjacent rows, so the',
    '      disagreements are more plausibly OCR folds than',
    '      print variants; those cells stay',
    '      compilation-pinned, the debt narrowed and named.',
    '      The compilation site itself has gone dark - the',
    '      fresh uploads are now the last standing source,',
    '      and a cleaner scan is the future winner. Pinned by',
    '      the R145',
    '      weapon table audit; census 63.',
])

# ---- (4) the R146 box tail ----
old_146 = NL.join([
    '      unmodeled fiction, named: noble gender (the book',
    '      prints nobleman-with-retainers 70% / noblewoman 25%',
    '      and no last 5%) and the ruffian 1-in-4',
    '      half-orc/humanoid note. Pinned by the R146 city',
    '      flavor audit; census 64.',
])
new_146 = NL.join([
    '      unmodeled fiction, named: noble gender and',
    '      the ruffian note - R149 BOOK-VERIFIED against',
    '      the fresh DMG upload and CORRECTED: the print',
    '      reads nobleman-with-retainers 75% / noblewoman',
    '      25% (the 70/25/no-last-5 reading was wrong; a',
    '      clean coin, not a five-way hole), the',
    '      noblewoman 75% sedan-chair detail prints with',
    '      it, and the ruffian 1-in-4 half-orc/humanoid',
    '      note is the printed matrix footnote, confirmed.',
    '      Pinned by the R146 city',
    '      flavor audit; census 64.',
])

# ---- (5) the R146-fiction open box ----
old_fic = NL.join([
    '- [ ] **R146 fiction (the named omissions)** - noble',
    '      gender (the book prints nobleman 70% / noblewoman',
    '      25% and no last 5%) and the ruffian 1-in-4',
    '      half-orc/humanoid note - city flavor follow-ups.',
])
new_fic = NL.join([
    '- [ ] **R146 fiction (the named omissions)** - the',
    '      noble gender hole is CLOSED R149: the split is',
    '      a clean nobleman 75% / noblewoman 25% - a coin',
    '      now, not a table (see the R146 box). The',
    '      ruffian 1-in-4 half-orc/humanoid note and the',
    '      noblewoman 75% sedan-chair detail remain - city',
    '      flavor follow-ups.',
])

# ---- (6) the book-verify box flips closed ----
old_bv = NL.join([
    '- [ ] **The book-verify pass (the standing debt)** - the',
    '      fresh DMG/PHB uploads (2026-10-04) make the whole',
    '      verification debt payable. The riders name their',
    '      winners: Appendix G/H spellings (R125), the Faerie',
    '      / Pleistocene / Age of Dinosaurs wilderness tables',
    '      and printing-variant readings (R126), the p.38',
    '      weapon rows (R145), the city flavor cells (R146),',
    '      and the p.71 example numbers (R144).',
])
new_bv = NL.join([
    '- [x] **The book-verify pass (the standing debt)** -',
    '      CLOSED R149: the fresh DMG/PHB uploads',
    '      (2026-10-04) diffed end to end against the repo.',
    '      PAID IN FULL: the Appendix G trap list (R125 -',
    '      all 46 kinds, bands and spellings, byte for',
    '      byte, and double-confirmed against a clean book',
    '      read); the Appendix H attribute fragments (65',
    '      attributes, no contradiction - the 37-feature',
    '      list did not survive the upload OCR and stays',
    '      compilation-pinned, named, though the printed',
    '      example NAMES all corroborate the pinned',
    '      feature and attribute spellings); the Faerie,',
    '      Pleistocene and Age of Dinosaurs wilderness',
    '      tables (R126 - 39 + 23 rows exact, plus all',
    '      readable Dinosaur Age cells; the Pleistocene',
    '      camel reading is an OCR column shift, resolved',
    '      by band continuity); the printing variants',
    '      (R126 - scrub Humanoid 26-32 and the tropical',
    '      mountains dervish 29-30 both print as the repo',
    '      resolved them, and the marsh Men defects are',
    '      the premium print itself, pinned as',
    '      print-defect corrections); the city flavor',
    '      cells (R146 - both tables exact, haughty',
    '      confirmed, noble gender corrected to 75/25);',
    '      and the p.71 example (R144 - every pinned',
    '      number prints; the axe is a hand axe, claim',
    '      corrected; the dwarf CON 16 save at +4',
    '      independently confirms the R147 formula).',
    '      PARTIALLY PAID, named: the p.38 weapon rows',
    '      (R145 - eight of fifteen verify exact, the',
    '      rest unarbitratable against the upload OCR;',
    '      the box carries the detail). The compilation',
    '      site has gone dark - the fresh uploads are',
    '      the last standing source, and a cleaner scan',
    '      wins any future cell.',
])

# ---- (7) the Appendix I open box ----
old_ai = NL.join([
    '      the last standing source, and a cleaner scan',
    '      wins any future cell.',
    '- [ ] **PC races layer (PHB pp.15-18, Race Tables I-III)**',
])
new_ai = NL.join([
    '      the last standing source, and a cleaner scan',
    '      wins any future cell.',
    '- [ ] **Appendix I, dungeon dressing (pp.219-221)** -',
    '      named R149 from the fresh read (a book-verify',
    '      pass bycatch, missed by the R148 sweep): the',
    '      printed lists are unpinned - air currents (16',
    '      bands, breeze, slight 01-05 through wind,',
    '      strong, moaning 96-00), odors (14, acrid 01-03',
    '      through urine 96-00), air (6, clear 01-70',
    '      through misted 99-00), general items (100,',
    '      arrow, broken 01 through wood pieces, rotting',
    '      98-00) and unexplained sounds (68, bang, slam',
    '      01-05 through whistling 99-00). The fresh',
    '      upload and a clean book read agree cell for',
    '      cell - the data is ready; the repo pins',
    '      Appendix A dressing only (R124, the',
    '      random-dungeon appendix).',
    '- [ ] **PC races layer (PHB pp.15-18, Race Tables I-III)**',
])

# ---- run ----
patch("tools/dmg_gap_report.md", old_head, new_head,
      "gap report: R149 header note",
      marker="R149 CLOSED the book-verify pass")
assert len(applied) + len(already) == 1

patch("tools/dmg_gap_report.md", old_144, new_144,
      "gap report: R144 box book-verified",
      marker="AXE CORRECTION: the example")
assert len(applied) + len(already) == 2

patch("tools/dmg_gap_report.md", old_145, new_145,
      "gap report: R145 box book-verified",
      marker="eight of the fifteen rows verify")
assert len(applied) + len(already) == 3

patch("tools/dmg_gap_report.md", old_146, new_146,
      "gap report: R146 box corrected",
      marker="nobleman-with-retainers 75%")
assert len(applied) + len(already) == 4

patch("tools/dmg_gap_report.md", old_fic, new_fic,
      "gap report: R146-fiction box amended",
      marker="a coin")
assert len(applied) + len(already) == 5

patch("tools/dmg_gap_report.md", old_bv, new_bv,
      "gap report: book-verify box closed",
      marker="CLOSED R149: the fresh DMG/PHB uploads")
assert len(applied) + len(already) == 6

patch("tools/dmg_gap_report.md", old_ai, new_ai,
      "gap report: Appendix I open box",
      marker="named R149 from the fresh read")
assert len(applied) + len(already) == 7

# ---- R149 fails/tail ----
if fails:
    print("R149 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print("R149 splice: FAIL - expected 7 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R149 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R149 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R149 note: REPORT-ONLY - no code or battery change;")
print("AUDIT CENSUS stays 67; commit: R149: book-verify pass")
print("paid - trap list, wilderness, city flavor, p.71")
print("verified (report-only)")
