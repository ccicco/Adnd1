# Adnd1 rules record format

The Lua record shape for content/rules/, adjudicated with
Curtiss 2026-10-31 and pinned R968. This document defines
what a rules record is, where it lives, and how it is
verified.

## The record

One Lua record per pin round - the mechanical translation
of the round's spec JSON (the model section). The spec
stays the adjudicated record; the Lua record is promoted
from it, never hand-edited.

```lua
-- {prefix}: promoted from tools/spec_r{NNN}.json (the
-- round title); DO NOT hand-edit; the spec JSON stays the
-- adjudicated record.
return {
  round = NNN,
  prefix = "...",
  banner = { title = "...", provenance = "..." },
  consts = { { name = "...", value = 14,
               comment = "..." }, ... },
  bools = { { name = "...", value = true,
              comment = "..." }, ... },
  switches = { { name = "...", values = { ... },
                 default = -1 }, ... },
  tables = { { name = "...", sentinel = -1,
               cols = { ... }, data = { ... },
               col_comments = { ... } }, ... },
  chains = { { name = "...", limits = { ... },
              tail = 6 }, ... },
  examples = { { expr = "...", note = "..." }, ... },
  audit = { label = "...", comment = "..." },
}
```

The sections: round, prefix, banner, consts, bools,
switches, tables, chains, examples, audit - ten fields,
five model pools (consts, bools, switches, tables,
chains). Optional pools are absent when the source spec
declares none.

## The buckets

content/rules/{phb,dmg,ddg,mm,mm2,ff,ua,oa,ds,wsg,mop,
dragon,...}/{prefix}.lua - bucketed by source book, one
file per round. A bucket holds many records: the bucket is
the printed taxonomy, the file is the adjudication.

## The promotion doctrine

Records are generated from the spec JSONs by the batch
builder; the translation back is the proof - a record must
rebuild its spec's model byte-identically. DO NOT
hand-edit a record; fix the spec and re-promote.

## The testing move

The battery derives from records: build the model
(speclib semantics), run the examples, mutate every
const, bool, cell and band - rverify's semantics pointed
at records instead of specs. The pin headers stay until
the battery is GREEN record-side; regtest then shrinks to
engine plus smoke test.

## The first batch

The Dragon set (issues 2-26, 25 issues, 128 round specs)
promotes first - recent specs, easy verify - landing in
batches under content/rules/dragon/.
