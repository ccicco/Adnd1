# The Dragon Magazine walk - the standing context note

This file is the persistent context for the Dragon Magazine arc: what
the walk is, what works, and what does not. It is written for the
assistant in future chats. The authoritative process record stays in
the Personal Knowledge topic adnd1-splice-work (the seed and its
increments); this file rides the repo so the context is fetchable
raw, per round, from anywhere.

## What the walk is

A print-order issue walk of Dragon Magazine (The Dragon from Vol. 1
No. 1, June 1976), whole-issue, NOT monster-privileged: each issue is
read in full, the engine-relevant chains are adjudicated one by one
with Curtiss, and the rest is scoped out explicitly. The arc opened
at R887 (commit 2229eba, census 810).

Standing doctrines (user-set, 2026-10-29):

- THE ARTICLE CHAIN IS THE INK UNIT, not the folio. Articles split
  across pages (issue #1: BotFA 6->13, Magic and Science 8->10,
  Languages 9->10, MMM 23->25, reviews 26->27->30, fiction
  28->29->30); several chains converge on shared pages (10, 25, 30).
  A round captures whole chains; gap-report boxes key per round.
- THE PIN IS THE CONVERSION. The ink is OD&D-era; it is adjudicated
  to 1e terms (1e attack matrices, 1e spell format, 1e ability
  tables) and the CONVERTED value pins, with the conversion noted as
  an honest boundary, never silent. (DMO rank-field / MOP App II
  transform precedent.)
- VARIANT LAYER SEATING. Dragon ink is never core 1e canon: pins
  ride a variant layer with provenance (banner, sentinel, audit
  comment, gap report), distinct audit vocabulary, no silent core
  rewrites. Issue #1's Ives tables are the template (rules/ivs.h).
- WAIT FOR GO before preparing any round. The mining adjudication
  happens per chain, in discussion, one by one - never a bulk take.

## What works (verified)

- INK INTAKE: Curtiss uploads the issue PDF chat-side; the chat-side
  OCR read produces a per-page transcript. The transcript pages are
  committed to the repo as extract/dragon/NNN/pNNN_full.txt via the
  spec data_files mechanism - the repo IS the voice persistence
  (the DDG doctrine). Page 1 markers and chat-side figure pointers
  are stripped; the ink text rides verbatim, trailing folio and all.
- FOLIO VERIFICATION PER ISSUE: issue #1 has print folio = PDF page
  (verified both ends: folios 3, 4, 6, 14, 19, 30). Do NOT assume:
  DDG carried a -1 offset. Verify at each issue intake.
- THE OPENER SHAPE (R887): a new arc's first round ships the whole-
  issue voice pages PLUS the pre-flip gap report as data files. The
  engine cannot flip a report its own round creates, so the round's
  gap_report field points at the PRIOR arc's report (the ddg 24/0
  no-op) and the report's boxes flip at the NEXT round. The gap
  report ships PRE-FLIP - the R796 lesson binds authored gap
  reports; the engine's flip is the closing mechanism.
- THE SEED LEDGER: prev_record seats into doc/vibe/
  adnd1_knowledge_seed_v2.md per the standing convention (the v2
  file is the engine's living seat ledger; the v3 seed grows by
  append). prev_seed_key = the record's first line, absent at base.
- MINING ADJUDICATION METHOD: read every chain in full before
  triage (headings lie - issue #1's "spells" pages 14-17 turned out
  to be a Chainmail-scale wargame system); check 1e core coverage
  (does the rule exist at core? the engine's enumerated pins -
  systemShock, resurrectionSurvival, the conduct tables - are the
  canon layer); check engine coverage with a code search before
  claiming a gap (attributeCheck: zero hits = a real variant fill;
  bulette.lua exists = a provenance pin, never a competing def);
  then present per-chain verdicts and let Curtiss decide, one by
  one, in discussion - not popup questions.
- DELIVERY: the raw JSON canvas body is the standing channel
  (canvas copy + the authored-plus-newline md5 gate). BASE64 IS NOT
  A GOTO OPTION (user-set 2026-10-29): it was needed once, other
  solutions have since avoided it, and it is a last resort only if
  everything else fails.
- VERIFICATION: engine double-run, rverify against the pristine
  base sha (restore + double-run + mutants; the extract pages are
  404-at-base new files, handled), the md5 gates on the delivered
  body. The Termux ./rn preflight stays the only C++ compile gate -
  no compiler is assumed on the assistant side.

## What does not work (the cautions)

- OCR TABLE GARBLES: dense grids (issue #1's quicksand and spell
  tables) garble in OCR; the figure pixels ride the OCR artifact as
  extracted images and need vision adjudication at pin time. Never
  pin a garbled cell without checking the image.
- SERIALIZED FICTION AND WARGAME CONTENT: fiction chains (the
  Gnome Cache 28->30) continue into later issues - a box can stay
  open across issues; wargame/boardgame chains (Lakofka's Chainmail
  rules, BotFA, Hyborean, Dungeon!) are out of engine scope on the
  same grounds Curtiss scoped BotFA out - do not re-litigate them
  per issue unless he opens the question.
- ENVIRONMENT RESETS: a built spec can be invalidated by a chat-side
  environment reset; rebuild from source and RE-RUN EVERY GATE. A
  rebuild may differ byte-wise from a pre-reset build (R887:
  cf58bc... became a0224f8... at the same byte count) - always quote
  the md5 of the VERIFIED artifact, never an earlier print.
- CHAT-PASTE OF SPECS: never deliver a spec body through chat
  markup; the renderer eats `](` in expr strings (the R608 lesson).
  Canvas copy only.

## Issue #1 state (as of R887, commit 2229eba)

- R887 LANDED: the Ives attribute tables (rules/ivs.h, census 810).
- Round B (awaiting go): Gold languages (9-10) + Smith Eldar (30) +
  the Bulette lore pin vs monsters/monsters/b/bulette.lua; the Ives
  gap box flips here (the dragon report's first flip round).
- Round C (awaiting go): the Aronson illusionist deltas (23-25),
  deltas only - most of his list later canonized into the 1e PHB
  illusionist (r183/r229 layers); pin the divergences.
- Parked: Ward's Artificer devices (8-10), an items-sweep candidate.
- Dropped: Lakofka (14-17), Mapping the Dungeons (20-21), BotFA
  (6, 13), the Lankhmar houri piece (4-5), Hyborean (24-25),
  Dungeon! (25), fiction, reviews, ads.
- Gap report: tools/dragon_gap_report.md (3 boxes, 0 closed at
  authoring; the Ives box closes at the next Dragon round).

## The one-line continuity

If a fresh chat reads only this: fetch the knowledge topic first
(doc/vibe/adnd1_knowledge_seed_v3.md IS its entrypoint; rebuild the
adnd1-splice-work topic from it), trust the repo HEAD over any
recorded state, and WAIT FOR GO - the arc's next round is named by
Curtiss, never assumed.
