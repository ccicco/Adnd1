This is a continuation prompt for the Adnd1 project - paste this
message at the start of a fresh chat after the knowledge and
chats have been cleared. The v2 setup files live in the repo
under doc/vibe/ (adnd1_knowledge_seed_v2.md,
adnd1_knowledge_backup_v2.md, adnd1_continuation_prompt_v2.md) -
this canvas body is the same prompt, kept as the durable copy.

---

I am continuing the Adnd1 project. Context you need:

Adnd1 is a first-edition AD&D engine in C++ (repo github.com/
ccicco/Adnd1, branch main, owner ccicco). Development lands in
numbered rounds (R313 is next): I run the repo on Termux; each
round is a Python "splice" script you deliver as a code canvas,
which patches the repo; I paste it into nano, run a fixed ritual
(md5 gates, py_compile, run twice for idempotence,
./tools/preflight.sh with its battery census, then git commit
straight to main and push). The full protocol, the acid-test
checklist, and every hard-won lesson are in my Personal Knowledge
topic "adnd1-delivery" - rebuild it first:

STEP 1 (rebuild the knowledge): the seed file is in the repo at
doc/vibe/adnd1_knowledge_seed_v2.md. It is public - fetch it via
the raw URL (raw.githubusercontent.com/ccicco/Adnd1/main/doc/
vibe/adnd1_knowledge_seed_v2.md) or the GitHub connector, and
create the Personal Knowledge topic "adnd1-delivery": the seed
file IS the KNOWLEDGE.md, keep its own frontmatter exactly. The
full pre-restart history (rounds R172-R312, verbose) is at
doc/vibe/adnd1_knowledge_backup_v2.md - reference it only when a
round needs old detail; never load it wholesale.

STEP 2 (state check): the repo should be at commit 8661437
("R312: the flooded crossing wired (census 237)") or the
doc/vibe setup commit just after it; the battery census is 237
audit lines. A round starts from the fresh tarball of the landed
HEAD (codeload). If the repo has moved further, trust the repo
and my next message.

STEP 3 (how rounds go): read the adnd1-delivery KNOWLEDGE.md and
follow it exactly - it carries the delivery format, the ritual,
the acid-test checklist (including the audit_eval RNNNa gate,
the replica-walk discipline, the include-chain rule, and the
canvas-delivery mechanics), the current seam-era state, and the
open threads. Do not re-derive the protocol; the knowledge is
authoritative for process.

That is all the setup. I will say what the next round is.
