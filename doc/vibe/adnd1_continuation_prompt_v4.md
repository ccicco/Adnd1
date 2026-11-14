# Adnd1 splice work - the v4 continuation prompt (R1043 fresh start, 2026-11-14)

You are resuming Curtiss Cicco's Adnd1 repo pin-round workflow in a
fresh chat. Paste this prompt at the start of the new chat.

---

I'm continuing the Adnd1 pin-round work (the v4 era, fresh start at
R1043). Read your Knowledge topic "adnd1-splice-work" first - it is
the authority for everything below. Do not load it wholesale beyond
the entrypoint; its pointers say what to read on demand.

Current state you must assume (verify against the repo before
scoping any round):

- Repo: github.com:ccicco/Adnd1.git, Termux, NO compiler available
  to me, NO package installs. bash tools/preflight.sh (NEVER sh)
  is the only compile+run gate.
- HEAD at the fresh start: 8972cdba, "R1043: weapon chart tables
  de-wire (census 1022)". Census = count of "audit: bad %d" printf
  patterns in rules/audits/*.h + regtest.cpp; verify the live
  number with the preflight battery.
- The live round shape is the registry de-wire: content/tables/*
  .lua defs on items::MiscItemRegistry, header-only seams, a
  fragment audit with pins COMPUTED from the parsed source (never
  hand-transcribed), census-driven regtest.
- Standing: WAIT FOR GO - never prepare a round without my call.
  No DMG or PHB engine rounds (the engine C++ stays; the lua
  registry is data-at-load only). Heredoc-regex gotcha, delivery
  via chunkcheck canvas (GATE lines, not whole-file md5), three
  chunkcheck drills before delivery, pre-delivery emulation,
  preflight as its own command line, commit block excludes the
  canvas scratch files.

On-demand references (repo, doc/vibe/):

- adnd1_knowledge_backup_v4.md - the full pre-restart v3 topic
  (R600-R1043): every round record R849-R1026, the reorg and
  miscmagic arcs, R1027-R1033. Read sections, never wholesale.
- adnd1_knowledge_seed_v4.md - the v4 entrypoint as landed (a
  byte-copy of the live Knowledge topic at the fresh start).
- Older: adnd1_knowledge_backup_v3.md, adnd1_seed_backup_v3.md,
  adnd1_knowledge_backup_v2.md (per the topic header).

The G1 module arc is PAUSED; its full doctrine and data record
lives in the Knowledge topic (g1-arc.md) - read it in sections
only if I reopen that arc.

The queue at the fresh start: the phb ladders (subclasses/bard
xp-title pairs), dm/appendixi.h dressing tables (needs a new
band-text registry), or a fresh survey of remaining hard-coded
tables outside the encounter region. The round number continues
from R1043; the next round is R1044 unless I say otherwise.
