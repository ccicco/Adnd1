This is a continuation prompt for the Adnd1 project - paste this
message at the start of a fresh chat after the knowledge and
chats have been cleared. The v3 setup files live in the repo
under doc/vibe/ (adnd1_knowledge_seed_v3.md,
adnd1_knowledge_backup_v3.md, adnd1_seed_backup_v3.md,
adnd1_continuation_prompt_v3.md) - this canvas body is the same
prompt, kept as the durable copy.

---

I am continuing the Adnd1 project. Context you need:

Adnd1 is a first-edition AD&D engine in C++ (repo github.com/
ccicco/Adnd1, branch main, owner ccicco). Development lands in
numbered splice rounds (R849 is next): I run the repo on Termux;
each round is a JSON spec you deliver as a code canvas, which
the splice engine patches into the repo; I save it, run a fixed
ritual (md5 gate, the double engine run, ./tools/preflight.sh
with its battery census, then git commit straight to main and
push). The full protocol, the ritual rules, the verification
lessons, and the standing decisions are in my Personal Knowledge
topic "adnd1-splice-work" - rebuild it first:

STEP 1 (rebuild the knowledge): the seed file is in the repo at
doc/vibe/adnd1_knowledge_seed_v3.md. It is public - fetch it via
the raw URL (raw.githubusercontent.com/ccicco/Adnd1/main/doc/
vibe/adnd1_knowledge_seed_v3.md) or the GitHub connector, and
create the Personal Knowledge topic "adnd1-splice-work": the seed
file IS the KNOWLEDGE.md, keep its own frontmatter exactly. Then
seat the R848 landed record at the top of its Round state
section: the record rides near the top of PART 1 (the records
block) of doc/vibe/adnd1_knowledge_backup_v3.md - the repo seed
deliberately omits it (the R849 splice seats it into the seed;
the topic copy carries it for continuity). The backups:
adnd1_knowledge_backup_v3.md (the full pre-restart knowledge
topic - records R600-R848, the R389-R599 archive, the R504-R510
extraction grids) and adnd1_seed_backup_v3.md (the accumulated
v2 seed - records R313-R847) - reference them only when a round
needs old detail; never load them wholesale.

STEP 2 (state check): the repo should be at commit 96831bb
("R848: the FF magic item tables (census 771)") or the doc/vibe
v3 setup commit just after it; the battery census is 771 audit
lines. A round starts from the landed HEAD (restore via the
rverify GitHub-raw fetch at the base sha). If the repo has moved
further, trust the repo and my next message.

STEP 3 (how rounds go): read the adnd1-splice-work
KNOWLEDGE.md and follow it exactly - it carries the ritual
rules (the one-line ./rn handoff, WAIT FOR GO, the prose-codifies
doctrine), the verification lessons (the engine gates, the
repair classes, the prefix-freedom and header-availability
checks), the standing seams (the deity layer, the
creature-registry promotion seam, the parked logging layers),
and the current state. Do not re-derive the protocol; the
knowledge is authoritative for process.

That is all the setup. I will say what the next round is.
## Amendment (appended 2026-10-27, R848 -> R886)

State at R886: the repo should be at commit
69d4b93 ("R886: The DDG lua promotion, batch
seven (census 809)") or the doc/vibe v3 append
commit just after it; the battery census is 809
audit lines, the registry floor 1333. R887 is
the next round. The DDG lua promotion is
COMPLETE (338 defs, batches one to seven); the
next queue item is the per-book normalization
rounds (MM1 408, MM2 332, FF 185, OA 47,
WSG+MOP 23) - NOT authorized until I say go.
The seed and the backup now carry the R849-R886
increment appended after their R848 content -
STEP 1's "seat the R848 record" is history:
the records through R886 ride in the appended
increment, and the seed's own Round state plus
the increment covers the rebuild.
