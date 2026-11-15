#!/usr/bin/env python3
# r1057_splice.py - the R1057 splice
# tool: the UA spells-family
# de-wire of 18 rules/ua headers
# (68 retiring arrays, 7 kept
# struct seams).
#
# WHAT IT DOES (run from the repo
# root, idempotent):
#   - parses the 68 retiring static
#     arrays across the 13 headers
#     (band ladders, dex/feet bands,
#     [5][3]/[5][4]/[17][17] grids,
#     the [17][3] search grid, 1-D
#     clamped flats, the ragged
#     switch string lists, the 20
#     string name arrays) plus every
#     kept zero-arg scalar and logic
#     fn (a semantic MODEL, the probe
#     source)
#   - writes content/tables/
#     ua_classes/ as 25 defs, 33
#     tables, every def's rows =
#     its parsed name list (or
#     COMPUTED band/level names);
#     item_offset/roster_offset are
#     COMPUTED prefix-sum tables
#   - rewrites every retiring
#     accessor onto the namespace
#     seam uaReg()/uaRows(key)/
#     uaTable(key,tag); every
#     signature, clamp, guard and
#     branch stays; matrix reads
#     flatten; the fallback is the
#     PARSED guard value per fn
#   - writes rules/audits/
#     r1056_uaclasses_registry.h
#     (SEVEN printf sections, SIX
#     guards, census 1096 -> 1103)
#     and seats its include at
#     regtest.cpp:1305
#
# HARD LESSONS APPLIED (the
# R1049-R1055 ledgers): every want
# computes from the SAME parse that
# writes the lua; probe polarities
# derive from the parsed models;
# NEGATIVE cells end to end; every
# per-def emitted loop is scoped to
# its own def block (the R1054
# class-13 kill); the reader in-range
# probes are arg-aware (R1053 class
# 7); adjacent C string literals
# JOIN (the headers carry "..."
# "..." concatenations); the enum-
# typed returns cast explicitly so
# the fragment compiles at the
# Termux preflight.

import os
import re
import sys

ROOT = os.getcwd()
REGTEST = "regtest.cpp"
LUA_DIR = "content/tables/ua_spells"
FRAG = ("rules/audits/"
        "r1057_uaspells_registry.h")
APPLIED_MARK = "// R1057 applied"
CENSUS_BEFORE = 1103
CENSUS_AFTER = 1111
INC_ANCHOR = ('    #include "rules/audits/'
              'r1056_uaclasses_registry.h"'
              '  // R1056')
ROUND = 1057

FILES = [
    "rules/ua/uaspellcomment.h",
    "rules/ua/uaspelltables.h",
    "rules/ua/uaspelltables2.h",
    "rules/ua/uascharts.h",
    "rules/ua/uacantrips1.h",
    "rules/ua/uacantrips2.h",
    "rules/ua/uacantrips3.h",
    "rules/ua/uacantrips4.h",
    "rules/ua/uacantrips5.h",
    "rules/ua/uacantrips6.h",
    "rules/ua/uailcantrips.h",
    "rules/ua/uaclericspells1.h",
    "rules/ua/uaclericspells5.h",
    "rules/ua/uaclericspells7.h",
    "rules/ua/uadruidspells1.h",
    "rules/ua/uadruidspells2.h",
    "rules/ua/uailspells1.h",
    "rules/ua/uasmalls1.h",
]

# the def rows: (def key, rows
# source) - "reader:<fn>" = the
# parsed name array of that reader
# fn; "computed:<prefix>:<lo>:<n>"
# = computed names;
# "structnames:<fn>" = the parsed
# first-string field of the KEPT
# struct seam fn; "cstrs:<fn,fn,..>"
# = the parsed zero-arg string
# fns' literal returns
DEF_ROWS = [
    ("ua_pc_serten", "reader:uapcSertenName"),
    ("ua_ast_cleric", "reader:uastClericName"),
    ("ua_ast_frag", "reader:uastClericFragName"),
    ("ua_ast_druid1", "reader:uastDruid1stName"),
    ("ua_ast_druid4", "reader:uastDruid4thName"),
    ("ua_ast_druid5", "reader:uastDruid5thName"),
    ("ua_ast_druid6", "reader:uastDruid6thName"),
    ("ua_ast_cantrip_cat",
     "reader:uastCantripCategoryName"),
    ("ua_ast_cantrip_names",
     "reader:uastCantripName"),
    ("ua_s2_mu1", "reader:uas2Mu1stName"),
    ("ua_s2_mu2", "reader:uas2Mu2ndName"),
    ("ua_s2_mu3", "reader:uas2Mu3rdName"),
    ("ua_s2_mu4", "reader:uas2Mu4thName"),
    ("ua_s2_mu5", "reader:uas2Mu5thName"),
    ("ua_s2_mu6", "reader:uas2Mu6thName"),
    ("ua_s2_mu7", "reader:uas2Mu7thName"),
    ("ua_s2_mu8", "reader:uas2Mu8thName"),
    ("ua_s2_mu9", "reader:uas2Mu9thName"),
    ("ua_s2_il1", "reader:uas2Il1stName"),
    ("ua_s2_il2", "reader:uas2Il2ndName"),
    ("ua_s2_il7", "reader:uas2Il7thName"),
    ("ua_s2_ilcantrip", "reader:uas2IlCantripName"),
    ("ua_usc_animal", "reader:uscSacredAnimal"),
    ("ua_usc_site", "reader:uscWorshipSite"),
    ("ua_ucn", "structnames:ucnUseful"),
    ("ua_ucr", "structnames:ucrReversed"),
    ("ua_ucl", "structnames:uclLegerdemain"),
    ("ua_ucp", "structnames:ucpPersonAffecting"),
    ("ua_uco", "structnames:ucoPersonal"),
    ("ua_uch", "structnames:uchHauntingSound"),
    ("ua_uailc",
     "cstrs:uailcLightsName,uailcDimName,"
     "uailcHazeName,uailcMaskName,"
     "uailcMirageName,uailcNoiseName,"
     "uailcRainbowName,uailcTwodName"),
    ("ua_uac1",
     "reader:uac1CeremonyVarietyName"),
    ("ua_uac5_animate",
     "reader:uac5AnimateExampleTypeName"),
    ("ua_uac5_golem",
     "reader:uac5GolemMaterialName"),
    ("ua_uac5_golem_damage",
     "reader:uac5GolemDamage"),
    ("ua_uac5_golem_sd",
     "reader:uac5GolemSD"),
    ("ua_uac5_golem_spells",
     "reader:uac5GolemMindlessSpellName"),
    ("ua_uac5_rainbow",
     "reader:uac5RainbowApplicationName"),
    ("ua_uac5_rainbow_bow",
     "reader:uac5RainbowBowColorName"),
    ("ua_uac5_rainbow_bow_targets",
     "reader:uac5RainbowBowColorTarget"),
    ("ua_uac5_rainbow_flagon",
     "reader:uac5RainbowFlagonDraughtColor"),
    ("ua_uac5_rainbow_flagon_effects",
     "reader:uac5RainbowFlagonDraughtEffect"),
    ("ua_uac7",
     "reader:uac7SuccorObjectExampleName"),
    ("ua_uad1",
     "reader:uad1CeremonyVarietyName"),
    ("ua_uad1_poison",
     "reader:uad1DetectPoisonTypeName"),
    ("ua_uad2",
     "reader:uad2ReflectingPoolCastThroughName"),
    ("ua_uail1_orb",
     "reader:uail1OrbRowName"),
    ("ua_uasm1", "computed:slot_:0:12"),
    ("ua_uasm1_dice", "computed:class_:0:12"),
]

DEFS = [d for d, _ in DEF_ROWS]

# the retiring int accessors:
# (fn, file stem, def, tag, array
# name in the body, kind, params)
# kinds:
#  band (lo, hi): guards return
#    lo-val / top-cell; read
#    [arg - lo]
#  flat: clamped [i]; fallback
#    cell(0,0)
#  grid2 (w, aoff, boff, amin,
#    amax, bmin, bmax): read
#    [(a-aoff)*w + (b-boff)]
INT_FNS = [
    ("uastClericReadableCount",
     "uaspelltables", "ua_ast_cleric",
     "readable_count", "k", "band", (1, 3)),
    ("uastClericFragCount",
     "uaspelltables", "ua_ast_cleric",
     "frag_count", "k", "band", (4, 7)),
    ("uastCantripCount",
     "uaspelltables", "ua_ast_cantrip_cat",
     "cantrip_count", "k", "band", (0, 5)),
    ("ucnCastTimeDen", "uacantrips1",
     "ua_ucn", "cast_den", "D", "flat", ()),
    ("ucrCastTimeDen", "uacantrips2",
     "ua_ucr", "cast_den", "D", "flat", ()),
    ("uclCastTimeDen", "uacantrips3",
     "ua_ucl", "cast_den", "D", "flat", ()),
    ("ucpCastTimeDen", "uacantrips4",
     "ua_ucp", "cast_den", "D", "flat", ()),
    ("ucoCastTimeDen", "uacantrips5",
     "ua_uco", "cast_den", "D", "flat", ()),
    ("uchCastTimeDen", "uacantrips6",
     "ua_uch", "cast_den", "D", "flat", ()),
    ("uailcCastTimeDen", "uailcantrips",
     "ua_uailc", "cast_den", "D", "flat", ()),
    ("uac1CeremonyVarietyLevel",
     "uaclericspells1", "ua_uac1",
     "variety_level", "k", "flat", ()),
    ("uac1PortentEffectModifier",
     "uaclericspells1", "ua_uac1",
     "portent_mod", "k", "band", (1, 6)),
    ("uac5GolemMinLevel",
     "uaclericspells5", "ua_uac5_golem",
     "min_level", "k", "flat", ()),
    ("uac5GolemBuildHours",
     "uaclericspells5", "ua_uac5_golem",
     "build_hours", "k", "flat", ()),
    ("uac5GolemDurationHoursPerLevel",
     "uaclericspells5", "ua_uac5_golem",
     "dur_hours", "k", "flat", ()),
    ("uac5GolemAC",
     "uaclericspells5", "ua_uac5_golem",
     "ac", "k", "flat", ()),
    ("uac5GolemMV",
     "uaclericspells5", "ua_uac5_golem",
     "mv", "k", "flat", ()),
    ("uac5GolemHDBase",
     "uaclericspells5", "ua_uac5_golem",
     "hd_base", "k", "flat", ()),
    ("uac5GolemHDBonus",
     "uaclericspells5", "ua_uac5_golem",
     "hd_bonus", "k", "flat", ()),
    ("uac5GolemHP",
     "uaclericspells5", "ua_uac5_golem",
     "hp", "k", "flat", ()),
    ("uac5GolemAT",
     "uaclericspells5", "ua_uac5_golem",
     "at", "k", "flat", ()),
    ("uac5GolemCarryPounds",
     "uaclericspells5", "ua_uac5_golem",
     "carry_pounds", "k", "flat", ()),
    ("uad1CeremonyVarietyCasterLevel",
     "uadruidspells1", "ua_uad1",
     "variety_level", "k", "flat", ()),
    ("uail1OrbRowLevel",
     "uailspells1", "ua_uail1_orb",
     "orb_level", "k", "flat", ()),
    ("uail1OrbRowDamageMin",
     "uailspells1", "ua_uail1_orb",
     "orb_damage_min", "k", "flat", ()),
    ("uail1OrbRowDamageMax",
     "uailspells1", "ua_uail1_orb",
     "orb_damage_max", "k", "flat", ()),
    ("uasm1StartHpMin",
     "uasmalls1", "ua_uasm1",
     "start_hp_min", "k", "flat", ()),
    ("uasm1MethodVDice",
     "uasmalls1", "ua_uasm1_dice",
     "methodv_dice", "k", "grid2",
     (7, 0, 0, 0, 11, 0, 6)),
]

# the retiring string readers:
# (fn, file stem, def, array name,
# kind, params)
# kinds: reader (1-arg clamp lo..hi),
#  reader_null (same, but the
#  initializer has 0 cells -> ""),
#  reader_tern (the guard rides a
#  return ternary),
#  gridstr (a0..a1 x b0..b1 padded
#  string grid, flattened row-major,
#  "" cells legal)
READERS = [
    ("uapcSertenName", "uaspellcomment",
     "ua_pc_serten", "n", "reader_tern",
     ("i", 0, 23)),
    ("uastClericName", "uaspelltables",
     "ua_ast_cleric", "k", "gridstr",
     ("lvl", 1, 3, "row", 0, 19)),
    ("uastClericFragName", "uaspelltables",
     "ua_ast_frag", "k", "gridstr",
     ("lvl", 4, 7, "i", 0, 7)),
    ("uastDruid1stName", "uaspelltables",
     "ua_ast_druid1", "k", "reader",
     ("i", 0, 3)),
    ("uastDruid4thName", "uaspelltables",
     "ua_ast_druid4", "k", "reader",
     ("i", 0, 5)),
    ("uastDruid5thName", "uaspelltables",
     "ua_ast_druid5", "k", "reader",
     ("i", 0, 5)),
    ("uastDruid6thName", "uaspelltables",
     "ua_ast_druid6", "k", "reader",
     ("i", 0, 4)),
    ("uastCantripCategoryName",
     "uaspelltables", "ua_ast_cantrip_cat",
     "k", "reader", ("cat", 0, 5)),
    ("uastCantripName", "uaspelltables",
     "ua_ast_cantrip_names", "k", "gridstr",
     ("cat", 0, 5, "i", 0, 19)),
    ("uas2Mu1stName", "uaspelltables2",
     "ua_s2_mu1", "k", "reader", ("i", 0, 34)),
    ("uas2Mu2ndName", "uaspelltables2",
     "ua_s2_mu2", "k", "reader", ("i", 0, 29)),
    ("uas2Mu3rdName", "uaspelltables2",
     "ua_s2_mu3", "k", "reader", ("i", 0, 27)),
    ("uas2Mu4thName", "uaspelltables2",
     "ua_s2_mu4", "k", "reader", ("i", 0, 27)),
    ("uas2Mu5thName", "uaspelltables2",
     "ua_s2_mu5", "k", "reader", ("i", 0, 27)),
    ("uas2Mu6thName", "uaspelltables2",
     "ua_s2_mu6", "k", "reader", ("i", 0, 16)),
    ("uas2Mu7thName", "uaspelltables2",
     "ua_s2_mu7", "k", "reader", ("i", 0, 15)),
    ("uas2Mu8thName", "uaspelltables2",
     "ua_s2_mu8", "k", "reader", ("i", 0, 9)),
    ("uas2Mu9thName", "uaspelltables2",
     "ua_s2_mu9", "k", "reader", ("i", 0, 7)),
    ("uas2Il1stName", "uaspelltables2",
     "ua_s2_il1", "k", "reader", ("i", 0, 4)),
    ("uas2Il2ndName", "uaspelltables2",
     "ua_s2_il2", "k", "reader", ("i", 0, 3)),
    ("uas2Il7thName", "uaspelltables2",
     "ua_s2_il7", "k", "reader", ("i", 0, 0)),
    ("uas2IlCantripName", "uaspelltables2",
     "ua_s2_ilcantrip", "k", "reader",
     ("i", 0, 7)),
    ("uscSacredAnimal", "uascharts",
     "ua_usc_animal", "A", "reader_null",
     ("i", 0, 22)),
    ("uscWorshipSite", "uascharts",
     "ua_usc_site", "W", "reader",
     ("i", 0, 22)),
    ("uac1CeremonyVarietyName",
     "uaclericspells1", "ua_uac1", "k",
     "reader", ("i", 0, 9)),
    ("uac5AnimateExampleTypeName",
     "uaclericspells5", "ua_uac5_animate",
     "k", "reader", ("i", 0, 5)),
    ("uac5GolemMaterialName",
     "uaclericspells5", "ua_uac5_golem",
     "k", "reader", ("i", 0, 3)),
    ("uac5GolemDamage",
     "uaclericspells5",
     "ua_uac5_golem_damage", "k",
     "reader", ("i", 0, 3)),
    ("uac5GolemSD",
     "uaclericspells5",
     "ua_uac5_golem_sd", "k",
     "reader", ("i", 0, 3)),
    ("uac5GolemMindlessSpellName",
     "uaclericspells5",
     "ua_uac5_golem_spells", "k",
     "reader", ("i", 0, 3)),
    ("uac5RainbowApplicationName",
     "uaclericspells5", "ua_uac5_rainbow",
     "k", "reader", ("i", 0, 3)),
    ("uac5RainbowBowColorName",
     "uaclericspells5",
     "ua_uac5_rainbow_bow", "k",
     "reader", ("i", 0, 6)),
    ("uac5RainbowBowColorTarget",
     "uaclericspells5",
     "ua_uac5_rainbow_bow_targets", "k",
     "reader", ("i", 0, 6)),
    ("uac5RainbowFlagonDraughtColor",
     "uaclericspells5",
     "ua_uac5_rainbow_flagon", "k",
     "reader", ("i", 0, 6)),
    ("uac5RainbowFlagonDraughtEffect",
     "uaclericspells5",
     "ua_uac5_rainbow_flagon_effects", "k",
     "reader", ("i", 0, 6)),
    ("uac7SuccorObjectExampleName",
     "uaclericspells7", "ua_uac7", "k",
     "reader", ("i", 0, 2)),
    ("uad1CeremonyVarietyName",
     "uadruidspells1", "ua_uad1", "k",
     "reader", ("i", 0, 8)),
    ("uad1DetectPoisonTypeName",
     "uadruidspells1", "ua_uad1_poison",
     "k", "reader", ("i", 0, 2)),
    ("uad2ReflectingPoolCastThroughName",
     "uadruidspells2", "ua_uad2", "k",
     "reader", ("i", 0, 2)),
    ("uail1OrbRowName", "uailspells1",
     "ua_uail1_orb", "k", "reader",
     ("i", 0, 8)),
]

# no pointer-out list fns retire
# this round (the subraces idiom
# has no spells-family member)
LIST_FNS = []

# the KEPT struct seams:
# (file stem, accessor fn, struct
# name, row count, [field names])
KEEP_STRUCTS = [
    ("uascharts", "uscChartRow",
     "UscChartRow", 23,
     ["name", "sphere", "head",
      "body", "color", "days",
      "freq", "form"]),
    ("uacantrips1", "ucnUseful",
     "UcnCantrip", 20,
     ["name", "school", "areaKind",
      "areaVal"]),
    ("uacantrips2", "ucrReversed",
     "UcrCantrip", 12,
     ["name", "school", "areaKind",
      "areaVal"]),
    ("uacantrips3", "uclLegerdemain",
     "UclCantrip", 6,
     ["name", "school", "areaKind",
      "areaVal"]),
    ("uacantrips4", "ucpPersonAffecting",
     "UcpCantrip", 10,
     ["name", "school", "areaKind",
      "areaVal"]),
    ("uacantrips5", "ucoPersonal",
     "UcoCantrip", 10,
     ["name", "school", "areaKind",
      "areaVal"]),
    ("uacantrips6", "uchHauntingSound",
     "UchCantrip", 8,
     ["name", "school", "areaKind",
      "areaVal"]),
]

# the KEPT count fns the generic
# model cannot evaluate (loop
# bodies): (fn, kind, data)
#  ("structfield", fn, struct
#   accessor, field name, count)
#  -> counts of each distinct
#     int field value
#  ("reader", fn, retiring reader,
#   count) -> counts of each
#     distinct reader value
#  ("nonnull", fn, retiring
#   reader, count) -> non-empty
#     names
#  ("freq", fn, struct accessor)
#   -> string-arg counts of the
#     freq column
KEPT_COUNTS = [
    ("structfield", "ucnSchoolCount",
     "ucnUseful", "school", 20),
    ("structfield", "ucnAreaKindCount",
     "ucnUseful", "areaKind", 20),
    ("structfield", "ucrSchoolCount",
     "ucrReversed", "school", 12),
    ("structfield", "ucrAreaKindCount",
     "ucrReversed", "areaKind", 12),
    ("structfield", "uclSchoolCount",
     "uclLegerdemain", "school", 6),
    ("structfield", "uclAreaKindCount",
     "uclLegerdemain", "areaKind", 6),
    ("structfield", "ucpSchoolCount",
     "ucpPersonAffecting", "school", 10),
    ("structfield", "ucpAreaKindCount",
     "ucpPersonAffecting", "areaKind", 10),
    ("structfield", "ucoSchoolCount",
     "ucoPersonal", "school", 10),
    ("structfield", "ucoAreaKindCount",
     "ucoPersonal", "areaKind", 10),
    ("structfield", "uchSchoolCount",
     "uchHauntingSound", "school", 8),
    ("structfield", "uchAreaKindCount",
     "uchHauntingSound", "areaKind", 8),
    ("reader", "ucnCastTimeDenCount",
     "ucnCastTimeDen", 20),
    ("reader", "ucrCastTimeDenCount",
     "ucrCastTimeDen", 12),
    ("reader", "uclCastTimeDenCount",
     "uclCastTimeDen", 6),
    ("reader", "ucpCastTimeDenCount",
     "ucpCastTimeDen", 10),
    ("reader", "ucoCastTimeDenCount",
     "ucoCastTimeDen", 10),
    ("reader", "uchCastTimeDenCount",
     "uchCastTimeDen", 8),
    ("reader", "uailcCastTimeDenCount",
     "uailcCastTimeDen", 8),
    ("nonnull", "uscNamedSacredAnimalCount",
     "uscSacredAnimal", 23),
    ("freq", "uscFrequencyCount",
     "uscChartRow"),
]

# the kept-fn fixups applied to
# the rewritten headers (each
# idempotent: skipped when the
# old text is gone)
KEPT_FIXUPS = [
    ("rules/ua/uascharts.h",
     "if (uscSacredAnimal(i) != 0)",
     "if (uscSacredAnimal(i)[0]"
     " != '\\0')"),
    ("rules/ua/uascharts.h",
     "// deity index; null = none.",
     "// deity index; the R1057"
     " de-wire retires the null"
     " cells to empty names."),
    ("rules/ua/uascharts.h",
     "// non-null cells): 13.",
     "// non-empty cells): 13."),
    # r407 fragment pins the pre-de-wire
    # nullptr semantics at three sites;
    # after the retirement the null cells
    # read "" (non-null), so the pointer
    # compares would count bad.  Pin the
    # empty-string semantics instead.
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "if (uscSacredAnimal(0) != 0",
     "if (uscSacredAnimal(0)[0]"
     " != '\\0'"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "|| uscSacredAnimal(1) != 0",
     "|| uscSacredAnimal(1)[0]"
     " != '\\0'"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "|| uscSacredAnimal(2) != 0",
     "|| uscSacredAnimal(2)[0]"
     " != '\\0'"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "|| uscSacredAnimal(3) != 0",
     "|| uscSacredAnimal(3)[0]"
     " != '\\0'"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "|| uscSacredAnimal(4) != 0)",
     "|| uscSacredAnimal(4)[0]"
     " != '\\0')"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "if (uscSacredAnimal(17) != 0)"
     " ++bad;",
     "if (uscSacredAnimal(17)[0]"
     " != '\\0') ++bad;"),
    ("rules/audits/"
     "r407_ua_appendix_s_clerical_c.h",
     "if (uscSacredAnimal(20) != 0)"
     " ++bad;",
     "if (uscSacredAnimal(20)[0]"
     " != '\\0') ++bad;"),
]

LUA_TITLE = {
    "ua_pc_serten":
        "UA Serten's taught-spell roster",
    "ua_ast_cleric":
        "UA cleric appendix S 1st-3rd"
        " spell-name columns",
    "ua_ast_frag":
        "UA cleric appendix S 4th-7th"
        " fragment spell names",
    "ua_ast_druid1":
        "UA druid 1st-level spell names",
    "ua_ast_druid4":
        "UA druid 4th-level spell names",
    "ua_ast_druid5":
        "UA druid 5th-level spell names",
    "ua_ast_druid6":
        "UA druid 6th-level spell names",
    "ua_ast_cantrip_cat":
        "UA magic-user cantrip"
        " categories",
    "ua_ast_cantrip_names":
        "UA magic-user cantrip"
        " names by category",
    "ua_s2_mu1":
        "UA magic-user 1st-level"
        " spell names",
    "ua_s2_mu2":
        "UA magic-user 2nd-level"
        " spell names",
    "ua_s2_mu3":
        "UA magic-user 3rd-level"
        " spell names",
    "ua_s2_mu4":
        "UA magic-user 4th-level"
        " spell names",
    "ua_s2_mu5":
        "UA magic-user 5th-level"
        " spell names",
    "ua_s2_mu6":
        "UA magic-user 6th-level"
        " spell names",
    "ua_s2_mu7":
        "UA magic-user 7th-level"
        " spell names",
    "ua_s2_mu8":
        "UA magic-user 8th-level"
        " spell names",
    "ua_s2_mu9":
        "UA magic-user 9th-level"
        " spell names",
    "ua_s2_il1":
        "UA illusionist 1st-level"
        " spell names",
    "ua_s2_il2":
        "UA illusionist 2nd-level"
        " spell names",
    "ua_s2_il7":
        "UA illusionist 7th-level"
        " spell names",
    "ua_s2_ilcantrip":
        "UA illusionist cantrip names",
    "ua_usc_animal":
        "UA deity sacred animals",
    "ua_usc_site":
        "UA deity worship sites",
    "ua_ucn":
        "UA useful cantrips",
    "ua_ucr":
        "UA reversed cantrips",
    "ua_ucl":
        "UA legerdemain cantrips",
    "ua_ucp":
        "UA person-affecting"
        " cantrips",
    "ua_uco":
        "UA personal cantrips",
    "ua_uch":
        "UA haunting-sound cantrips",
    "ua_uailc":
        "UA illusionist cantrips",
    "ua_uac1":
        "UA cleric ceremony"
        " varieties",
    "ua_uac5_animate":
        "UA animate dead example"
        " types",
    "ua_uac5_golem":
        "UA lesser golem materials"
        " and combat cells",
    "ua_uac5_golem_damage":
        "UA lesser golem damage"
        " strings",
    "ua_uac5_golem_sd":
        "UA lesser golem special"
        " defense strings",
    "ua_uac5_golem_spells":
        "UA lesser golem mindless"
        " spell examples",
    "ua_uac5_rainbow":
        "UA rainbow applications",
    "ua_uac5_rainbow_bow":
        "UA rainbow bow colors",
    "ua_uac5_rainbow_bow_targets":
        "UA rainbow bow color"
        " targets",
    "ua_uac5_rainbow_flagon":
        "UA rainbow flagon"
        " draught colors",
    "ua_uac5_rainbow_flagon_effects":
        "UA rainbow flagon"
        " draught effects",
    "ua_uac7":
        "UA succor object examples",
    "ua_uad1":
        "UA druid ceremony varieties",
    "ua_uad1_poison":
        "UA detect poison types",
    "ua_uad2":
        "UA reflecting pool"
        " cast-through spells",
    "ua_uail1_orb":
        "UA orb of color ladder",
    "ua_uasm1":
        "UA method V start-HP"
        " minimums",
    "ua_uasm1_dice":
        "UA method V dice-count"
        " grid",
}

GROUPS = {
    "A": ["ua_pc_serten", "ua_ast_cleric",
          "ua_ast_frag", "ua_ast_druid1",
          "ua_ast_druid4", "ua_ast_druid5",
          "ua_ast_druid6",
          "ua_ast_cantrip_cat",
          "ua_ast_cantrip_names",
          "ua_s2_mu1", "ua_s2_mu2",
          "ua_s2_mu3", "ua_s2_mu4",
          "ua_s2_mu5", "ua_s2_mu6",
          "ua_s2_mu7", "ua_s2_mu8",
          "ua_s2_mu9", "ua_s2_il1",
          "ua_s2_il2", "ua_s2_il7",
          "ua_s2_ilcantrip"],
    "B": ["ua_usc_animal", "ua_usc_site",
          "ua_ucn", "ua_ucr", "ua_ucl",
          "ua_ucp", "ua_uco", "ua_uch",
          "ua_uailc"],
    "C": ["ua_uac1", "ua_uac5_animate",
          "ua_uac5_golem",
          "ua_uac5_golem_damage",
          "ua_uac5_golem_sd",
          "ua_uac5_golem_spells",
          "ua_uac5_rainbow",
          "ua_uac5_rainbow_bow",
          "ua_uac5_rainbow_bow_targets",
          "ua_uac5_rainbow_flagon",
          "ua_uac5_rainbow_flagon_effects",
          "ua_uac7"],
    "D": ["ua_uad1", "ua_uad1_poison",
          "ua_uad2", "ua_uail1_orb",
          "ua_uasm1", "ua_uasm1_dice"],
}

LABELS = [
    "load", "counts", "defs-A",
    "defs-B", "defs-C", "defs-D",
    "seam", "edges",
]


def die(msg):
    print("SPLICE FAIL: " + msg)
    sys.exit(1)


# ---- the parse -----------------------

def _strip(s):
    return re.sub(r"//[^\n]*", "", s)


def _fn_args(src, fn):
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn
        + r"\(([\s\S]*?)\)", src)
    if not m:
        die(fn + " args missing")
    return m.group(1)


def fn_body(src, fn):
    # a brace-counting extractor:
    # single-line bodies ({ ... })
    # and multi-line bodies both
    # parse; the body is the
    # content between the fn's
    # opening brace and its match
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn + r"\(", src)
    if not m:
        die(fn + " body missing")
    i = src.index("{", m.end())
    depth = 1
    j = i + 1
    while j < len(src) and depth:
        if src[j] == "{":
            depth += 1
        elif src[j] == "}":
            depth -= 1
        j += 1
    if depth:
        die(fn + " braces unbalanced")
    return src[i + 1:j - 1]


def _fn_args(src, fn):
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn
        + r"\(([\s\S]*?)\)", src)
    if not m:
        die(fn + " args missing")
    return m.group(1)


def _int_vals(body, name, dims):
    pat = (r"static const "
           r"(?:int|uint8_t) " + name
           + r"\[[^\]]*\]" * len(dims)
           + r"\s*=\s*\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("array " + name
            + " missing")
    vals = [int(v) for v in
            re.findall(r"-?\d+",
                       _strip(m.group(1)))]
    want = 1
    for d in dims:
        want *= d
    if len(vals) != want:
        die("array " + name + " cells "
            + str(len(vals))
            + " != " + str(want))
    return vals


def _str_vals(body, name, n):
    pat = (r"static const char\*"
           r"(?: const)? " + name
           + r"\[(?:\d+)\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string array " + name
            + " missing")
    seg = _strip(m.group(1))
    out = []
    cur = None
    for mm in re.finditer(
            r'"((?:[^"\\]|\\.)*)"',
            seg):
        if cur is not None \
                and seg[cur[1]:mm.start()
                        ].strip():
            out.append(cur[0])
            cur = None
        if cur is None:
            cur = [mm.group(1),
                   mm.end()]
        else:
            cur[0] += mm.group(1)
            cur[1] = mm.end()
    if cur is not None:
        out.append(cur[0])
    if len(out) != n:
        die("string array " + name
            + " names "
            + str(len(out))
            + " != " + str(n))
    return out


def _ragged_vals(body, prefix,
                 counts):
    out = []
    for i, c in enumerate(counts):
        out += _str_vals(
            body, prefix + str(i), c)
    return out


def parse_pristine():
    srcs = {}
    for f in FILES:
        srcs[f] = _strip(
            open(os.path.join(
                ROOT, f)).read())
    p = {"srcs": srcs,
         "ints": {}, "strs": {},
         "grids": {}, "scalars": {},
         "clamps": {}, "args": {}}
    for f in FILES:
        s = srcs[f]
        stem = f.split("/")[-1][:-2]
        # the zero-arg scalars
        for m in re.finditer(
                r"inline (int|bool)"
                r" (\w+)\(\)\s*\{\s*"
                r"return (-?\d+|true"
                r"|false);",
                s):
            v = m.group(3)
            val = (v == "true"
                   if v in ("true",
                            "false")
                   else int(v))
            p["scalars"][
                m.group(2)] = val
    # the int fns
    for (fn, stem, dkey, tag,
         arr, kind, pp) in INT_FNS:
        s = srcs[
            "rules/ua/" + stem
            + ".h"]
        b = fn_body(s, fn)
        p["args"][fn] = _fn_args(s, fn)
        if kind == "search":
            vals = _int_vals(
                b, arr, (17, 3))
        elif kind == "pref":
            vals = _int_vals(
                b, arr, (17, 17))
        else:
            dims = _arr_dims(s, b,
                             arr)
            vals = _int_vals(
                b, arr, dims)
        p["ints"][(dkey, tag)] = vals
        p["clamps"][fn] = \
            _clamp_lines(b, kind, pp)
    # the readers
    for (fn, stem, dkey, arr,
         kind, pp) in READERS:
        s = srcs[
            "rules/ua/" + stem
            + ".h"]
        b = fn_body(s, fn)
        p["args"][fn] = _fn_args(s, fn)
        if kind == "gridstr":
            dims = (pp[2] - pp[1] + 1,
                    pp[5] - pp[4] + 1)
            p["strs"][fn] = \
                _str_grid(
                    b, arr, dims)
        elif kind == "reader_null":
            n = pp[2] - pp[1] + 1
            p["strs"][fn] = \
                _str_vals_null(
                    b, arr, n)
        else:
            n = pp[2] - pp[1] + 1
            p["strs"][fn] = \
                _str_vals(
                    b, arr, n)
        p["clamps"][fn] = \
            _clamp_lines(
                b, kind, pp)
    # the pointer-out lists
    p["lists"] = {}
    for (fn, stem, arr,
         n) in LIST_FNS:
        s = srcs[
            "rules/ua/" + stem
            + ".h"]
        b = fn_body(s, fn)
        p["lists"][fn] = \
            _str_vals(b, arr, n)
    # the KEPT struct seams:
    # each T initializer parsed
    # into per-record (strings,
    # ints) field tuples
    p["structs"] = {}
    for (stem, afn, sname,
         cnt, fields) in KEEP_STRUCTS:
        s = srcs[
            "rules/ua/" + stem + ".h"]
        p["structs"][afn] = \
            _parse_struct_records(
                s, sname, cnt)
    # the zero-arg const char*
    # fns with literal returns
    p["cstrs"] = {}
    strpat = re.compile(
        r"inline const char\* "
        r"(\w+)\(\)\s*\{\s*"
        r"return\s+((?:\"(?:[^\"\\]"
        r"|\\.)*\"\s*)+);")
    for f in FILES:
        s = srcs[f]
        for m in strpat.finditer(s):
            lit = "".join(
                re.findall(
                    r"\"((?:[^\"\\]"
                    r"|\\.)*)\"",
                    m.group(2)))
            p["cstrs"][
                m.group(1)] = lit
    return p



def _arr_dims(src, body, name):
    m = re.search(
        r"static const "
        r"(?:int|uint8_t) " + name
        + r"((?:\[[^\]]*\])+)"
        r"\s*=", body)
    if not m:
        die("dims of " + name)
    dims = []
    for d in re.findall(
            r"\[([^\]]*)\]", m.group(1)):
        if d.isdigit():
            dims.append(int(d))
        else:
            dm = re.search(
                r"enum \w+ : int "
                r"\{([\s\S]*?)\}",
                src)
            val = None
            for en in re.finditer(
                    r"enum (\w+) : int"
                    r"\{([\s\S]*?)\}",
                    src):
                v = 0
                for part in \
                        en.group(2
                                 ).split(","):
                    part = part.strip()
                    if part.startswith(
                            d + " ") \
                            or part == d \
                            or part.startswith(
                            d + "="):
                        val = v
                    if "=" in part:
                        v = int(part.split(
                            "=")[1])
                    v += 1
            if val is None:
                val = 18  # SUBRACE_COUNT
            dims.append(val)
    return dims


def _str_grid(body, name, dims):
    pat = (r"static const char\*"
           r" const " + name
           + r"\[" + str(dims[0])
           + r"\]\[" + str(dims[1])
           + r"\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string grid " + name)
    seg = _strip(m.group(1))
    out = []
    cur = None
    for mm in re.finditer(
            r'"((?:[^"\\]|\\.)*)"',
            seg):
        if cur is not None \
                and seg[cur[1]:mm.start()
                        ].strip():
            out.append(cur[0])
            cur = None
        if cur is None:
            cur = [mm.group(1),
                   mm.end()]
        else:
            cur[0] += mm.group(1)
            cur[1] = mm.end()
    if cur is not None:
        out.append(cur[0])
    if len(out) != dims[0] * dims[1]:
        die("string grid " + name
            + " names")
    return out


def _str_vals_null(body, name, n):
    # a string array whose
    # initializer may hold
    # bare 0 cells (the
    # sacred-animal nullptr
    # seams): each 0 cell
    # retires as ""
    pat = (r"static const char\*"
           r"(?: const)? " + name
           + r"\[(?:\d+)\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string array " + name
            + " missing")
    seg = _strip(m.group(1))
    # split top-level commas
    cells = []
    depth = 0
    cur = ""
    inq = False
    esc = False
    for c in seg:
        if inq:
            cur += c
            if esc:
                esc = False
            elif c == "\\":
                esc = True
            elif c == '"':
                inq = False
            continue
        if c == '"':
            inq = True
            cur += c
            continue
        if c in "{[(":
            depth += 1
        elif c in "}])":
            depth -= 1
        if c == "," and depth == 0:
            cells.append(cur)
            cur = ""
            continue
        cur += c
    if cur.strip():
        cells.append(cur)
    out = []
    for cell in cells:
        cell = cell.strip()
        if not cell or re.match(
                r"^(0|NULL|"
                r"nullptr)$", cell):
            out.append("")
            continue
        lits = re.findall(
            r'"((?:[^"\\]|\\.)*)"',
            cell)
        if not lits:
            die("null cell parse: "
                + cell[:40])
        out.append("".join(lits))
    if len(out) != n:
        die("string array " + name
            + " cells "
            + str(len(out))
            + " != " + str(n))
    return out


def _parse_struct_records(src, sname,
                          cnt):
    # parse a KEPT struct
    # array's initializer
    # into per-record
    # (strings, ints) tuples
    m = re.search(
        r"static const " + sname
        + r"\s+T\[(?:\d+)\]"
        r"\s*=\s*\{",
        src)
    if not m:
        die("struct array " + sname)
    seg = src[m.end():]
    recs = []
    depth = 0
    rec = None
    for c in seg:
        if c == "{":
            depth += 1
            if depth == 1:
                rec = ""
                continue
        elif c == "}":
            depth -= 1
            if depth == 0 and rec \
                    is not None:
                recs.append(rec)
                rec = None
                continue
            if depth < 0:
                break
        elif rec is not None:
            rec += c
    if len(recs) != cnt:
        die("struct records "
            + sname + ": "
            + str(len(recs)))
    out = []
    for r in recs:
        strs = re.findall(
            r'"((?:[^"\\]|\\.)*)"',
            r)
        ints = [int(v) for v in
                re.findall(
                    r"-?\d+",
                    _strip(r))]
        out.append((strs, ints))
    return out


def _parse_struct_records(src, sname,
                          cnt):
    # parse a KEPT struct
    # array's initializer
    # into per-record
    # (strings, ints) tuples
    # (adjacent string
    # literals join; ints
    # come only from the
    # non-string spans)
    m = re.search(
        r"static const " + sname
        + r"\s+T\[(?:\d+)\]"
        r"\s*=\s*\{",
        src)
    if not m:
        die("struct array " + sname)
    seg = src[m.end():]
    recs = []
    depth = 0
    rec = None
    for c in seg:
        if c == "{":
            depth += 1
            if depth == 1:
                rec = ""
                continue
        elif c == "}":
            depth -= 1
            if depth == 0 and rec \
                    is not None:
                recs.append(rec)
                rec = None
                continue
            if depth < 0:
                break
        elif rec is not None:
            rec += c
    if len(recs) != cnt:
        die("struct records "
            + sname + ": "
            + str(len(recs)))
    # the named area-kind
    # constants (UCO_AREA_SPHERE
    # etc.) resolve to ints
    cmap = {
        m.group(1): int(m.group(2))
        for m in re.finditer(
            r"const int (\w+) ="
            r" (-?\d+);", src)}
    recs = [
        re.sub(
            r"\b(" + "|".join(
                sorted(cmap)) + r")\b",
            lambda mm: str(
                cmap[mm.group(1)]),
            r)
        for r in recs
    ] if cmap else recs
    out = []
    for r in recs:
        strs = []
        ints = []
        last = None
        for mm in re.finditer(
                r'"((?:[^"\\]'
                r'|\\.)*)"',
                r):
            gap = (r[last:mm.start()]
                   if last is not None
                   else r[:mm.start()])
            if strs and gap.strip() \
                    == "" and last \
                    is not None:
                strs[-1] += mm.group(1)
            else:
                if last is not None:
                    ints += [
                        int(v)
                        for v in
                        re.findall(
                            r"-?\d+",
                            gap)]
                else:
                    ints += [
                        int(v)
                        for v in
                        re.findall(
                            r"-?\d+",
                            gap)]
                strs.append(
                    mm.group(1))
            last = mm.end()
        tail = (r[last:]
                if last is not None
                else r)
        ints += [int(v) for v in
                 re.findall(
                     r"-?\d+",
                     _strip(tail))]
        out.append((strs, ints))
    return out


def _clamp_lines(body, kind, pp):
    # the EXACT original
    # clamp/guard statements,
    # comments stripped - the
    # new body reuses them
    # verbatim (R1053 class 5)
    lines = []
    for m in re.finditer(
            r"(?:^|(?<=;))[ \t]*"
            r"(if \([^;]*?\)"
            r"[^;]*?;|return [^;]*?;)",
            _strip(body),
            re.M):
        t = m.group(1).strip()
        if "static const" in t:
            continue
        # an if that INDEXES
        # an array is in-loop
        # logic (the search
        # kind's match if),
        # not a clamp: a real
        # clamp compares
        # scalars only
        if t.startswith("if ") \
                and "[" in t:
            continue
        lines.append(t)
    return lines


def census_count():
    n = open(os.path.join(
        ROOT, REGTEST)).read().count(
        "audit: bad %d")
    for d, _, fs in os.walk(
            os.path.join(
                ROOT, "rules/audits")):
        for f in fs:
            if f.endswith(".h"):
                n += open(os.path.join(
                    d, f)).read().count(
                    "audit: bad %d")
    return n


# ---- the enums + the kept-fn
# model (probe wants) --------

def parse_enums(srcs):
    out = {}
    for f, src in srcs.items():
        for m in re.finditer(
                r"enum (\w+) : int"
                r"[^\{]*\{([\s\S]*?)\}",
                src):
            name, body = m.group(1), m.group(2)
            if name in out:
                continue
            vals = {}
            v = 0
            for part in body.split(","):
                part = re.sub(
                    r"//[^\n]*", "",
                    part).strip()
                mm = re.match(
                    r"(\w+)\s*(?:=\s*"
                    r"(-?\d+))?", part)
                if not mm:
                    continue
                if mm.group(2) is not None:
                    v = int(mm.group(2))
                vals[mm.group(1)] = v
                v += 1
            out[name] = vals
    # the core enums the ua
    # headers lean on (Ability
    # rides engine/character.h)
    core = {}
    for cf in ("rules/engine/"
               "character.h",
               "rules/engine/"
               "races.h"):
        p = os.path.join(ROOT, cf)
        if os.path.exists(p):
            core = _strip(open(p).read())
            for m in re.finditer(
                    r"enum (\w+) : int"
                    r"[^\{]*\{([\s\S]*?)\}",
                    core):
                name = m.group(1)
                if name in out:
                    continue
                vals = {}
                v = 0
                for part in m.group(2).split(","):
                    part = re.sub(
                        r"//[^\n]*", "",
                        part).strip()
                    mm = re.match(
                        r"(\w+)\s*(?:=\s*"
                        r"(-?\d+))?", part)
                    if not mm:
                        continue
                    if mm.group(2) is not None:
                        v = int(mm.group(2))
                    vals[mm.group(1)] = v
                    v += 1
                out[name] = vals
    return out


# every inline fn in the 13
# headers: name -> (file stem,
# return type, args string)
def parse_fns(srcs):
    fns = {}
    for f, src in srcs.items():
        stem = f.split("/")[-1][:-2]
        for m in re.finditer(
                r"inline ((?:[\w:\*&]+"
                r"(?:\s+|\s*\*\s*)"
                r")+?)\b(\w+)\("
                r"([\s\S]*?)\)\s*\{",
                src):
            ret, name, args = m.groups()
            if name in ("uaReg", "uaRows",
                        "uaTable"):
                continue
            fns[name] = (stem, ret.strip(),
                         " ".join(args.split()))
    return fns


RETIRED = set()
for _t in INT_FNS:
    RETIRED.add(_t[0])
for _t in READERS:
    RETIRED.add(_t[0])


class Model:
    # the generic C-subset
    # evaluator over the KEPT
    # fns. DIE on anything it
    # cannot model (fail loud).
    def __init__(self, p, enums, fns):
        self.p = p
        self.enums = enums
        self.fns = fns
        self.cache = {}

    def enumval(self, tok):
        for _, vals in self.enums.items():
            if tok in vals:
                return vals[tok]
        return None

    def ret_of(self, fn):
        return self.fns[fn][1]

    def args_of(self, fn):
        a = self.fns[fn][2]
        return [x.strip() for x in
                a.split(",") if x.strip()]

    def call(self, fn, args):
        key = (fn, tuple(args))
        if key in self.cache:
            return self.cache[key]
        stem = self.fns[fn][0]
        src = self.p["srcs"][
            "rules/ua/" + stem + ".h"]
        body = fn_body(src, fn)
        body = _strip(body)
        names = [x.split()[-1].strip("&")
                 .strip("[]") for x in
                 self.args_of(fn)]
        env = dict(zip(names, args))
        val = self.eval_body(
            body, env)
        self.cache[key] = val
        return val

    def eval_body(self, body, env):
        # local decls ASSIGN into
        # the env (a formula's
        # named temporaries)
        while True:
            dm = re.search(
                r"\b(?:int|bool)\s+"
                r"(\w+)\s*=\s*"
                r"([^;]+);", body)
            if not dm:
                break
            env[dm.group(1)] = \
                self.eval_expr(
                    dm.group(2), env)
            body = body[:dm.start()] \
                + body[dm.end():]
        # a lone return expression
        m = re.match(
            r"^\s*(?:return\s+"
            r"([\s\S]*?);)\s*$",
            body.strip())
        if m:
            return self.eval_expr(
                m.group(1), env)
        # guard chain: a run of
        # if (...) ...; return ...;
        lines = body.strip()
        # switch statement?
        sm = re.match(
            r"^switch \((\w+)\)"
            r"\s*\{([\s\S]*)\}$",
            lines)
        if sm:
            return self.eval_switch(
                sm.group(1),
                sm.group(2), env)
        # if-chain
        if lines.startswith("if ("):
            return self.eval_ifchain(
                lines, env)
        raise ValueError(
            "unmodelable body: "
            + lines[:60])

    def eval_switch(self, var, body,
                    env):
        val = env[var]
        # split into labeled
        # arms; a DEFAULT arm
        # may hold an if-chain
        # (cavalierTitleKnown's
        # OCR-hole guard) -
        # evaluate it as a
        # body, not a lone
        # return expr
        labs = list(re.finditer(
                r"case ([\w]+):"
                r"|default:", body))
        arms = []
        for i, m in \
                enumerate(labs):
            if m.group(0) \
                    == "default:":
                lab = "DEFAULT"
            else:
                lab = \
                    m.group(1)
                lv = self.enumval(
                    lab)
                if lv is None:
                    lv = int(lab)
                lab = lv
            end = (labs[i + 1]
                   .start()
                   if i + 1
                   < len(labs)
                   else len(body))
            arms.append((lab,
                         body[
                          m.end():
                          end]))
        dflt = None
        for lab, text in arms:
            if lab == "DEFAULT":
                dflt = text
                continue
            if lab == val:
                return self.\
                    eval_arm(text,
                             env)
        if dflt is not None:
            return self.eval_arm(
                dflt, env)
        raise ValueError(
            "switch fallthrough")

    def eval_arm(self, text, env):
        # an arm is a lone
        # return (possibly
        # line-wrapped) or a
        # small if-chain body
        t = text.strip()
        m = re.match(
            r"return\s+"
            r"([\s\S]*?);\s*$",
            t)
        if m:
            return self.eval_expr(
                m.group(1), env)
        if t.startswith("if (") \
                or t.startswith(
                    "if("):
            return self.\
                eval_ifchain(t,
                             env)
        return self.eval_body(
            t, env)

    def eval_ifchain(self, text, env):
        # split into (cond, expr)
        # pairs + final return
        rest = text
        pairs = []
        while True:
            m = re.match(
                r"if \(([\s\S]*?)\)"
                r"\s*(\{[^\}]*\}"
                r"|return\s+[\s\S]*?;)"
                r"\s*",
                rest, re.S)
            if not m:
                break
            cond = m.group(1)
            act = m.group(2)
            if act.startswith("{"):
                act = act.strip("{}"
                                ).strip()
            expr = re.match(
                r"return\s+([\s\S]*?);",
                act)
            if not expr:
                # a block: handle a
                # single nested return
                # after a nested if
                raise ValueError(
                    "unmodelable if "
                    + act[:40])
            pairs.append((cond,
                          expr.group(1)))
            rest = rest[m.end():]
        tail = re.match(
            r"return\s+([\s\S]*?);"
            r"\s*$", rest.strip())
        if not tail:
            raise ValueError(
                "if-chain tail "
                + rest[:40])
        pairs.append(("1", tail.group(1)))
        for cond, expr in pairs:
            if self.eval_cond(cond,
                              env):
                return self.eval_expr(
                    expr, env)
        raise ValueError("no branch")

    def eval_cond(self, cond, env):
        return self.eval_expr(
            cond, env) != 0

    def eval_expr(self, expr, env):
        e = re.sub(r"\s+", " ",
                   expr).strip()
        # casts out
        e = re.sub(
            r"\((?:unsigned |long |"
            r"int|bool|char|size_t|"
            r"RacePref|CharSubRace|"
            r"CharRace|Ability|"
            r"HierophantConjure|"
            r"HierophantPlane|"
            r"CavalierTrack|"
            r"CavalierWeaponOfChoice|"
            r"UaAlignReq|UaClass|"
            r"HalfElfAncestry|"
            r"GenMethod|XPPct)\)",
            "", e)
        # true/false
        e = re.sub(r"\btrue\b", "1",
                   e)
        e = re.sub(r"\bfalse\b", "0",
                   e)
        # nested calls first
        # (innermost parens)
        while True:
            cm = re.search(
                r"\b(\w+)\("
                r"([^()]*?)\)", e)
            if not cm:
                break
            fn = cm.group(1)
            if fn in self.fns \
                    and fn not in \
                    RETIRED:
                raw = cm.group(2)
                argv = []
                for part in raw.split(","):
                    part = part.strip()
                    if not part:
                        continue
                    argv.append(
                        self.eval_expr(
                            part, env))
                # enum-typed args:
                # ints are fine
                v = self.call(fn, argv)
                e = e[:cm.start()] \
                    + repr(v) + e[cm.end():]
            else:
                # min/max idioms
                break
        # enum tokens
        def sub_tok(mm):
            v = self.enumval(mm.group(0))
            if v is None:
                raise ValueError(
                    "token " + mm.group(0))
            return str(v)
        e = re.sub(r"\b[A-Z][A-Z_0-9]{2,}\b",
                   sub_tok, e)
        # C ops
        e = e.replace("&&", " and ")
        e = e.replace("||", " or ")
        e = re.sub(r"!(?!=)", " not ", e)
        # ternaries: innermost
        while "?" in e:
            tm = re.search(
                r"\(([^()?]+)\)"
                r"\s*\?\s*([^()?:]*)"
                r"\s*:\s*([^()?:]*)",
                e)
            if tm:
                c = self.eval_expr(
                    tm.group(1), {})
                pick = tm.group(2) \
                    if self.eval_expr(
                        c, {}) \
                    else tm.group(3)
                e = e[:tm.start()] \
                    + "(" + pick + ")" \
                    + e[tm.end():]
                continue
            tm = re.search(
                r"([^()?]+)\s*\?\s*"
                r"([^()?:]*)\s*:\s*"
                r"([^()?:]*)", e)
            if not tm:
                raise ValueError(
                    "ternary " + e[:40])
            c = self.eval_expr(
                tm.group(1), env)
            pick = tm.group(2) \
                if c else tm.group(3)
            e = e[:tm.start()] \
                + "(" + pick + ")" \
                + e[tm.end():]
        # python-safe eval
        e = re.sub(r"\sint\b", "", e)
        try:
            return eval(
                e, {"__builtins__": {}},
                dict(env))
        except Exception as ex:
            raise ValueError(
                "expr " + expr[:50]
                + " -> " + str(ex))


def build_defs(p):
    rows = {}
    for dkey, src in DEF_ROWS:
        if src.startswith("reader:"):
            rows[dkey] = p["strs"][
                src[7:]]
        elif src.startswith("computed:"):
            _, prefix, lo, n = \
                src.split(":")
            rows[dkey] = [
                prefix + str(i)
                for i in range(
                    int(lo),
                    int(lo) + int(n))]
        elif src.startswith(
                "structnames:"):
            fn = src[12:]
            rows[dkey] = [
                rec[0][0]
                for rec in
                p["structs"][fn]]
        elif src.startswith("cstrs:"):
            fns = src[6:].split(",")
            rows[dkey] = [
                p["cstrs"][fn]
                for fn in fns]
        else:
            die("rows source " + src)
    return rows


def prefix_sums(counts):
    out = []
    acc = 0
    for c in counts:
        out.append(acc)
        acc += c
    return out


def build_tables(p):
    # (def, tag) -> values;
    # grid2 flatten, all
    # derived from the parse
    # (no computed offsets
    # this round)
    t = {}
    for (fn, stem, dkey, tag,
         arr, kind, pp) in INT_FNS:
        vals = p["ints"][(dkey, tag)]
        t[(dkey, tag)] = vals
    return t


# ---- the lua emit ----------------------------

def _q(t):
    return t.replace("\\", "\\\\").replace(
        "\"", "\\\"")


def def_tables(dkey, tables):
    out = []
    for (d, tag), vals in tables.items():
        if d == dkey:
            out.append((tag, vals))
    out.sort(key=lambda x: x[0])
    return out


def table_comment(fn, stem, dkey,
                  tag, arr, kind, pp):
    n = "the " \
        + LUA_TITLE.get(
            dkey, dkey) \
        + " " + tag + " column"
    if kind == "band":
        n += ("; banded reads "
              "index arg - "
              + str(pp[0]))
    elif kind == "grid2":
        n += ("; [a][b] FLATTENED "
              "a-major, width "
              + str(pp[0]))
    elif kind == "search":
        n += ("; the [17][3] "
              "search triples "
              "flat")
    elif kind == "pref":
        n += ("; the [17][17] "
              "matrix FLATTENED "
              "viewer-major")
    elif kind == "dex":
        n += ("; dex band "
              "16-19 reads "
              "arg - 16")
    if tag.endswith("_offset"):
        n += ("; COMPUTED "
              "prefix sums")
    return n


def lua_def(dkey, rows, tables,
            intmeta):
    out = []
    w = out.append
    tabs = def_tables(dkey, tables)
    n = len(rows[dkey])
    w("-- " + dkey)
    w("-- The R1057 UA spells-family "
      "de-wire (rules/ua).")
    w("-- " + LUA_TITLE[dkey] + ".")
    w("-- rows[]: the def's row names -"
      " the R1042 equipment rows idiom"
      " (computed names where the print"
      " has no name list).")
    w("-- tables[]: the printed columns;"
      " the accessors live in rules/ua"
      " and keep their clamps.")
    w("-- DO NOT hand-edit: "
      "tools/r1057_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % dkey)
    w("  name = \"%s\"," % LUA_TITLE[dkey])
    w("  sources = {")
    w("    { part = 0, round = 1057 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % dkey)
    w("      value = %d," % n)
    w("      comment = \"the table "
      "rows\" },")
    w("  },")
    w("  rows = {")
    for i, nm in enumerate(rows[dkey]):
        w("    { name = \"%s\"," % _q(nm))
        w("      set = \"%s\"," % dkey)
        w("      band = { %d, %d },"
          % (i, i))
        w("      xp = 0, xp_hi = 0, "
          "gp = 0, gp_hi = 0,")
        w("      qty = { 0, 0 } },")
    w("  },")
    w("  tables = {")
    for tag, vals in tabs:
        w("    { name = \"%s\"," % tag)
        w("      values = {")
        for r in range(0, len(vals), 10):
            w("        "
              + ", ".join(str(v)
                         for v in
                         vals[r:r + 10])
              + ", ")
        w("      },")
        meta = intmeta.get(
            (dkey, tag))
        if meta:
            cmt = table_comment(
                *meta)
        else:
            cmt = ("the computed "
                   "prefix-sum "
                   "offsets")
        w("      comment = \"%s\" },"
          % _q(cmt))
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(rows, tables,
              intmeta):
    os.makedirs(
        os.path.join(ROOT, LUA_DIR),
        exist_ok=True)
    wrote = []
    for dkey in DEFS:
        txt = lua_def(dkey, rows,
                      tables, intmeta)
        path = os.path.join(
            ROOT, LUA_DIR,
            dkey + ".lua")
        open(path, "w").write(txt)
        wrote.append(dkey)
    return wrote


# ---- the seam header --------------------------

SEAM_HDR = """\
// ===========================================================================
// Adnd1 - rules/ua/uaregistry.h
// The R1056+R1057 rules/ua registry seam.
//
// content/tables/ua_classes/ (R1056) and
// content/tables/ua_spells/ (R1057) via
// items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom) and the rows
// readers (the R1051 dzRows idiom). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in the rules/ua
// family headers keeps its signature,
// clamp and branch; only the array read
// moves behind the registry.
// DO NOT hand-edit: tools/r1057_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the rules/ua registry seam ----------

inline items::MiscItemRegistry&
uaReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "ua_classes");
        reg.loadDirectory(
            "content/tables/"
            "ua_spells");
    }
    return reg;
}

// the name rows of one def
inline const std::vector<
    items::MiscItemRow>& uaRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = uaReg().find(key);
        it = cache.emplace(
            key, d ? d->rows
                   : std::vector<
                        items::
                        MiscItemRow>()
                   ).first;
    }
    return it->second;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* uaTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = uaReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

}  // namespace rules
"""


def write_seam_header():
    path = os.path.join(
        ROOT, "rules/ua/",
        "uaregistry.h")
    open(path, "w").write(SEAM_HDR)


# ---- the header rewrite -----------------------

# the emitted body of one
# retiring fn (clamps and
# guards verbatim from the
# parse; the read on the
# seam)
def _guard_ret(clamps):
    # the first guard that
    # RETURNS a value (the
    # parsed fallback), or
    # None
    for c in clamps:
        m = re.match(
            r"if \([^)]*\)"
            r"[\s\S]*?"
            r"return (-?\d+);", c)
        if m:
            return int(m.group(1))
    return None


def _idx_expr(clamps):
    # the index expression of
    # the final `return k[...];`
    m = re.search(
        r"return \w+\[([^\]]*)\]"
        r"\s*;", clamps[-1])
    if m:
        return m.group(1).strip()
    return None


def new_body_int(fn, dkey, tag,
                 kind, pp, clamps,
                 vals):
    guards = clamps[:-1]
    idx = _idx_expr(clamps)
    gret = _guard_ret(clamps)
    out = []
    a = out.append
    a("    const auto* g = uaTable(")
    a("        \"%s\", \"%s\");"
      % (dkey, tag))
    for g in guards:
        a("    " + g)
    if kind in ("band", "range0",
                "dex"):
        fb = gret if gret \
            is not None else 0
        a("    if (!g) return %d;" % fb)
    elif kind == "search":
        a("    if (!g) return -1;")
    elif kind == "pref":
        a("    if (!g) return PREF_N;")
    else:
        a("    if (!g) return %d;"
          % vals[0])
    if kind == "search":
        a("    for (int i = 0; i < 17;"
          " ++i)")
        a("        if ((*g)[i * 3] =="
          " level")
        a("            && (*g)[i * 3"
          " + 1] == feet)")
        a("            return (*g)"
          "[i * 3 + 2];")
        a("    return -1;")
    elif kind == "pref":
        a("    return (RacePref)"
          "(*g)[(viewer - 1) * 17")
        a("        + (viewed - 1)];")
    elif kind == "grid2":
        wd = pp[0]
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        a("    return (int)(*g)"
          "[(%s) * %d" % (ia, wd))
        a("        + (%s)];" % ib)
    else:
        a("    return (int)(*g)"
          "[%s];" % idx)
    return "\n".join(out)


def new_body_reader(fn, dkey,
                    kind, pp, clamps):
    out = []
    a = out.append
    if kind == "reader_tern":
        # the guard rides the
        # return ternary
        # (uapcSertenName): keep
        # it verbatim with the
        # array read swapped
        a("    const auto& rows = "
          "uaRows(\"%s\");" % dkey)
        a("    if (rows.empty())")
        a("        return \"\";")
        t = clamps[-1]
        arg = pp[0]
        t = re.sub(
            r"\b\w+\[" + arg + r"\]",
            "rows[" + arg
            + "].name.c_str()", t)
        a("    " + t)
        return "\n".join(out)
    if kind == "gridstr":
        # the padded string grid:
        # both clamps verbatim,
        # the read flattened
        # row-major
        (an, alo, ahi, bn,
         blo, bhi) = pp
        a("    const auto& rows = "
          "uaRows(\"%s\");" % dkey)
        a("    if (rows.empty())")
        a("        return \"\";")
        for g in clamps[:-1]:
            if not g.startswith("if "):
                continue
            a("    " + g)
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        wdt = bhi - blo + 1
        a("    if ((int)rows.size()"
          " <= (%s) * %d"
          % (ia, wdt))
        a("        + (%s))" % ib)
        a("        return \"\";")
        a("    return rows[(%s) * %d"
          % (ia, wdt))
        a("        + (%s)].name"
          ".c_str();" % ib)
        return "\n".join(out)
    a("    const auto& rows = "
      "uaRows(\"%s\");" % dkey)
    a("    if (rows.empty())")
    a("        return \"\";")
    for g in clamps[:-1]:
        # only if-statements
        # re-emit (a bare
        # return mid-body is
        # not a clamp)
        if not g.startswith("if "):
            continue
        a("    " + g)
    if kind == "reader2":
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        wdt = pp[5] - pp[4] + 1
        a("    if ((int)rows.size()"
          " <= (%s) * %d" % (ia, wdt))
        a("        + (%s))" % ib)
        a("        return \"\";")
        a("    return rows[(%s) * %d"
          % (ia, wdt))
        a("        + (%s)].name"
          ".c_str();" % ib)
        return "\n".join(out)
    idx = _idx_expr(clamps)
    a("    if ((int)rows.size()"
      " <= (%s))" % idx)
    a("        return \"\";")
    a("    return rows[%s].name"
      ".c_str();" % idx)
    return "\n".join(out)


def rewrite_file(path, fns_in_file,
                 p, tables):
    raw = open(path).read()
    src = _strip(raw)
    changed = False
    for spec in fns_in_file:
        fn = spec[0]
        m = re.search(
            r"^[ \t]*inline [\w\s:\*&]+?"
            r"\b" + fn + r"\(",
            raw, re.M)
        if not m:
            die(fn + " decl missing in "
                + path)
        # the exact signature span
        # in the RAW text: find the
        # opening brace, then the
        # matching close
        i = raw.index("{", m.start())
        depth = 1
        j = i + 1
        while j < len(raw) and depth:
            if raw[j] == "{":
                depth += 1
            elif raw[j] == "}":
                depth -= 1
            j += 1
        if depth:
            die(fn + " braces")
        sig = raw[m.start():i + 1]
        if spec[1] == "int":
            (fn2, stem, dkey, tag,
             arr, kind, pp) = spec[2]
            vals = tables[(dkey, tag)]
            body = new_body_int(
                fn, dkey, tag, kind, pp,
                p["clamps"][fn], vals)
        else:
            (fn2, stem, dkey, arr,
             kind, pp) = spec[2]
            body = new_body_reader(
                fn, dkey, kind, pp,
                p["clamps"][fn])
        newtxt = sig + "\n" + body \
            + "\n}"
        raw = (raw[:m.start()]
               + newtxt
               + raw[j:])
        src = _strip(raw)
        changed = True
    # the seam include + mark
    if APPLIED_MARK not in raw:
        insert = (APPLIED_MARK
                  + "\n#include \"rules/ua/"
                  "uaregistry.h\"\n")
        if "#pragma once\n" in raw:
            raw = raw.replace(
                "#pragma once\n",
                "#pragma once\n\n"
                + insert, 1)
        else:
            # a header with no
            # pragma (uafollowers.h):
            # seat the mark after
            # the leading banner
            m2 = re.match(
                r"(//[^\n]*\n)+", raw)
            at = m2.end() if m2 \
                else 0
            raw = (raw[:at]
                   + "\n" + insert
                   + raw[at:])
        changed = True
    if changed:
        open(path, "w").write(raw)
    return changed


def rewrite_headers(p, tables):
    by_file = {}
    for spec in INT_FNS:
        by_file.setdefault(
            "rules/ua/" + spec[1]
            + ".h",
            []).append(("int", spec))
    for spec in READERS:
        by_file.setdefault(
            "rules/ua/" + spec[1]
            + ".h",
            []).append(("reader",
                        spec))
    applied = 0
    for path, specs in by_file.items():
        full = os.path.join(
            ROOT, path)
        raw = open(full).read()
        if APPLIED_MARK in raw:
            continue
        specs = [x[1] if x[0]
                 == "int" else x[1]
                 for x in specs]
        # tag each with its class
        wrapped = []
        for x in specs:
            cls = "int" \
                if x in INT_FNS \
                else "reader"
            wrapped.append((x[0],
                            cls, x))
        if rewrite_file(full,
                        wrapped, p,
                        tables):
            applied += 1
    return applied


# ---- the seam model (the ------
# edges wants of the REWRITTEN
# accessors; the clamps run
# generically off the parse) ---

def run_clamps(clamps, env, model):
    # returns ("ret", v) on a
    # returning guard, else None
    for c in clamps[:-1]:
        m = re.match(
            r"if \(([\s\S]*?)\)\s*"
            r"return ([\s\S]*?);", c)
        if m:
            if model.eval_expr(
                    m.group(1),
                    dict(env)):
                return ("ret",
                        model.eval_expr(
                            m.group(2),
                            dict(env)))
            continue
        m = re.match(
            r"if \(([\s\S]*?)\)\s*"
            r"(\w+) = ([\s\S]*?);", c)
        if m:
            if model.eval_expr(
                    m.group(1),
                    dict(env)):
                env[m.group(2)] = \
                    model.eval_expr(
                        m.group(3),
                        dict(env))
            continue
        m = re.match(
            r"(\w+) = ([\s\S]*?);", c)
        if m:
            env[m.group(1)] = \
                model.eval_expr(
                    m.group(2),
                    dict(env))
    return None


def seam_eval_int(fn, args, p,
                  tables, model):
    spec = None
    for t in INT_FNS:
        if t[0] == fn:
            spec = t
            break
    (fn2, stem, dkey, tag, arr,
     kind, pp) = spec
    vals = tables[(dkey, tag)]
    names = [x.split()[-1]
             .strip("&").strip("[]")
             for x in
             model.args_of(fn)]
    env = dict(zip(names, args))
    clamps = p["clamps"][fn]
    r = run_clamps(clamps, env,
                   model)
    if r:
        return r[1]
    if kind == "search":
        for i in range(17):
            if (vals[i * 3]
                    == args[0]
                    and vals[i * 3 + 1]
                    == args[1]):
                return vals[
                    i * 3 + 2]
        return -1
    if kind == "pref":
        if (args[0] < 1
                or args[0] > 17
                or args[1] < 1
                or args[1] > 17):
            return 3  # PREF_N
        return vals[(args[0] - 1)
                    * 17
                    + (args[1] - 1)]
    if kind == "grid2":
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]",
            clamps[-1])
        ia = model.eval_expr(
            m.group(1), dict(env))
        ib = model.eval_expr(
            m.group(2), dict(env))
        w = pp[0]
        return vals[ia * w + ib]
    idx = _idx_expr(clamps)
    i = model.eval_expr(
        idx, dict(env))
    if i < 0 or i >= len(vals):
        die("seam_eval_int "
            + fn
            + " out of range: "
            + str(i))
    return vals[i]


def seam_eval_reader(fn, args, p,
                     rows, model):
    spec = None
    for t in READERS:
        if t[0] == fn:
            spec = t
            break
    (fn2, stem, dkey, arr, kind,
     pp) = spec
    names = [x.split()[-1]
             .strip("&").strip("[]")
             for x in
             model.args_of(fn)]
    env = dict(zip(names, args))
    clamps = p["clamps"][fn]
    if kind == "reader_tern":
        lo, hi = pp[1], pp[2]
        a = args[0]
        if a < lo or a > hi:
            return ""
        return rows[dkey][a]
    if kind == "gridstr":
        (an, alo, ahi, bn,
         blo, bhi) = pp
        r = run_clamps(clamps, env,
                       model)
        if r is not None:
            die("gridstr guard "
                + fn)
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia = model.eval_expr(
            m.group(1), dict(env))
        ib = model.eval_expr(
            m.group(2), dict(env))
        wdt = bhi - blo + 1
        i = ia * wdt + ib
        if i < 0 \
                or i >= len(rows[dkey]):
            die("gridstr index "
                + fn + ": "
                + str(i))
        return rows[dkey][i]
    r = run_clamps(clamps, env,
                   model)
    if r is not None:
        die("reader with a "
            "returning guard: "
            + fn)
    if kind == "reader2":
        wdt = pp[5] - pp[4] + 1
        t = max(pp[1],
                min(pp[2],
                    args[0]))
        row = max(pp[4],
                  min(pp[5],
                      args[1]))
        return rows[dkey][
            t * wdt + row]
    idx = _idx_expr(clamps)
    i = model.eval_expr(
        idx, dict(env))
    if i < 0 or i >= len(rows[dkey]):
        return ""
    return rows[dkey][i]


def tables_get(p, key):
    # the parse-level table
    # (used by seam_eval_reader
    # before build_tables)
    if key == ("ua_cavmoney",
               "item_offset"):
        c = p["ints"][
            ("ua_cavmoney",
             "item_count")]
        return prefix_sums(c)
    if key == ("ua_socialclass",
               "roster_offset"):
        c = p["ints"][
            ("ua_socialclass",
             "roster_count")]
        return prefix_sums(c)
    return p["ints"][key]


# ---- the fragment emit ------------------------

F_INC = ('    #include "rules/'
         'audits/'
         'r1057_uaspells_registry.h"'
         '  // R1057')


class FE:
    # the fragment emitter
    def __init__(self, p, enums,
                 fns, rows, tables):
        self.p = p
        self.enums = enums
        self.fns = fns
        self.rows = rows
        self.tables = tables
        self.model = Model(
            p, enums, fns)
        self.out = []
        self.seam_accessors = \
            {}

    def w(self, line=""):
        self.out.append(line)

    def head(self):
        self.w("    // ==== R1057: "
               "uaspells registry "
               "==========")
        self.w("    // The R1057 "
               "de-wire: the 68 "
               "retiring static")
        self.w("    // arrays of the "
               "eighteen rules/ua "
               "SPELLS-family")
        self.w("    // headers ride "
               "items::MiscItemRegistry "
               "from")
        self.w("    // content/tables/"
               "ua_spells/ - %d defs,"
               % len(DEFS)
               + " %d tables, %d"
               % (len(INT_FNS),
                  len(READERS))
               + " rows readers;")
        self.w("    // the seven KEPT "
               "struct seams and the"
               " count fns stay"
               " C++,")
        self.w("    // probed here. "
               "Eight sections:"
               " load, counts,")
        self.w("    // defs-A/B/C/D, "
               "seam, edges. Census "
               "%d -> %d."
               % (CENSUS_BEFORE,
                  CENSUS_AFTER)
               + " DO NOT hand-edit:")
        self.w("    // tools/"
               "r1057_splice.py is "
               "the only writer.")
        self.w("    {")
        self.w("        int bad = 0;")

    def guard(self, idx):
        self.w('        printf('
               '"R1057 uaspells '
               'registry %s audit: '
               'bad %%d\\n", bad);'
               % LABELS[idx])
        if idx < len(LABELS) - 1:
            self.w(
                "        if (bad)"
                " return 1;")
            self.w("        bad = 0;")

    # 1. load
    def sec_load(self):
        self.w("        // -- 1. "
               "load -------------"
               "-----------------")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            int n = "
               "reg.loadDirectory(")
        self.w('                "'
               'content/tables/'
               'ua_spells");')
        self.w("            if (n != "
               "%d) ++bad;" % len(DEFS))
        self.w("            if (!reg."
               "errors().empty()) "
               "++bad;")
        self.w("            for (const "
               "auto& kv : reg.all())")
        self.w("                if ((int)"
               "kv.second.sources."
               "size() != 1")
        self.w("                    || "
               "kv.second.sources[0]"
               ".second != %d)"
               % ROUND)
        self.w("                    "
               "++bad;")
        for d in DEFS:
            self.w('            if (!reg'
                   '.find("%s")) ++bad;'
                   % d)
        self.w("        }")
        self.guard(0)

    # 2. counts
    def sec_counts(self):
        self.w("        // -- 2. "
               "counts -------------"
               "-------------")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'ua_spells");')
        for d in DEFS:
            tabs = def_tables(
                d, self.tables)
            self.def_block(d, tabs)
        self.w("        }")
        self.guard(1)

    def def_block(self, d, tabs):
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        self.w("                    if "
               "((int)d->rows.size() "
               "!= %d"
               % len(self.rows[d]))
        self.w("                        || "
               "(int)d->pins.size() "
               "!= 1")
        self.w('                        || '
               'd->pins[0].name')
        self.w('                            != '
               '"%sRowCount"' % d)
        self.w("                        || "
               "d->pins[0].value "
               "!= %d)"
               % len(self.rows[d]))
        self.w("                        "
               "++bad;")
        self.w("                    if "
               "((int)d->tables.size() "
               "!= %d) ++bad;"
               % len(tabs))
        for ti, (tag,
                 vals) in enumerate(tabs):
            self.w("                    if "
                   "(d->tables[%d].name"
                   % ti)
            self.w('                        != '
                   '"%s"' % tag)
            self.w("                        || "
                   "(int)d->tables[%d]"
                   % ti)
            self.w("                            "
                   ".values.size() != "
                   "%d)" % len(vals))
            self.w("                        "
                   "++bad;")
        self.w("                }")
        self.w("            }")

    # 3-6. defs groups
    def sec_defs(self, gi, gname):
        self.w("        // -- %d. %s --"
               % (gi + 3, gname)
               + "-" * max(1,
                           28 - len(
                               gname)))
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'ua_spells");')
        for d in GROUPS[gname]:
            self.def_checks(d)
        self.w("        }")
        self.guard(gi + 2)

    def def_checks(self, d):
        tabs = def_tables(
            d, self.tables)
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        for ti, (tag,
                 vals) in enumerate(tabs):
            for i, v in enumerate(vals):
                self.w("                    "
                       "if (d->tables[%d]"
                       % ti)
                self.w("                        "
                       ".values[%d] != "
                       "%d) ++bad;"
                       % (i, v))
        for spec in READERS:
            if spec[2] != d:
                continue
            self.reader_probes(
                spec)
        for spec in INT_FNS:
            if spec[2] != d:
                continue
            self.int_probes(spec)
        self.w("                }")
        self.w("            }")

    def reader_probes(self, spec):
        (fn, stem, dkey, arr,
         kind, pp) = spec
        if kind == "gridstr":
            (an, alo, ahi, bn,
             blo, bhi) = pp
            for a in range(alo,
                           ahi + 1):
                for b in range(
                        blo,
                        bhi + 1):
                    want = \
                        seam_eval_reader(
                            fn, [a, b],
                            self.p,
                            self.rows,
                            self.model)
                    self.w(
                        "                    "
                        "if (std::string("
                        "rules::%s(%d, %d))"
                        % (fn, a, b))
                    self.w(
                        '                        '
                        '!= '
                        '"%s") ++bad;'
                        % _q(want))
            return
        # reader / reader_null /
        # reader_tern: the full
        # in-range walk
        lo, hi = pp[1], pp[2]
        for a in range(lo,
                       hi + 1):
            want = \
                seam_eval_reader(
                    fn, [a],
                    self.p,
                    self.rows,
                    self.model)
            self.w("                    "
                   "if (std::string("
                   "rules::%s(%d))"
                   % (fn, a))
            self.w('                        '
                   '!= '
                   '"%s") ++bad;'
                   % _q(want))

    def int_probes(self, spec):
        (fn, stem, dkey, tag,
         arr, kind, pp) = spec
        if kind == "band":
            lo, hi = pp
            for a in range(lo,
                           hi + 1):
                want = \
                    seam_eval_int(
                        fn, [a],
                        self.p,
                        self.tables,
                        self.model)
                self.w("                    "
                       "if (rules::%s(%d)"
                       " != %d) ++bad;"
                       % (fn, a,
                          want))
            return
        if kind == "grid2":
            (w, aoff, boff, amin,
             amax, bmin, bmax) = pp
            for a in (amin, amax):
                for b in (bmin,
                          bmax):
                    want = \
                        seam_eval_int(
                            fn, [a, b],
                            self.p,
                            self.tables,
                            self.model)
                    self.w("                    "
                           "if (rules::%s("
                           "%d, %d) != %d)"
                           % (fn, a, b,
                              want))
                    self.w("                        "
                           "++bad;")
            return
        # flat
        vals = self.tables[
            (dkey, tag)]
        n = len(vals)
        for a in range(0, n):
            want = \
                seam_eval_int(
                    fn, [a],
                    self.p,
                    self.tables,
                    self.model)
            self.w("                    "
                   "if (rules::%s(%d)"
                   " != %d) ++bad;"
                   % (fn, a,
                      want))

    # 7. seam: per-def block,
    # each accessor cross-read
    # EXACTLY once, its OWN
    # def block only (the R1054
    # class-13 discipline)
    def sec_seam(self):
        self.w("        // -- 7. seam --"
               "---------------------"
               "-----")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'ua_spells");')
        for d in DEFS:
            self.seam_block(d)
        self.w("        }")
        self.guard(len(LABELS) - 2)

    def seam_block(self, d):
        tabs = def_tables(
            d, self.tables)
        tabidx = {tag: i
                  for i, (tag, _)
                  in enumerate(tabs)}
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        emitted = []
        for spec in INT_FNS:
            if spec[2] != d:
                continue
            (fn, stem, dkey, tag,
             arr, kind, pp) = spec
            vals = self.tables[
                (dkey, tag)]
            ti = tabidx[tag]
            n = len(vals)
            if kind == "band":
                lo = pp[0]
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w("                        "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, lo))
                self.w("                            "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w("                            "
                       "++bad;")
            elif kind == "grid2":
                (wd, aoff, boff, amin,
                 amax, bmin, bmax) = pp
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % (amax - amin + 1))
                self.w("                        "
                       "for (int j = 0; "
                       "j < %d; ++j)"
                       % (bmax - bmin + 1))
                self.w("                            "
                       "if (rules::%s("
                       "%d + i, %d + j)"
                       % (fn, amin, bmin))
                self.w("                                "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[(i + %d) * %d "
                       "+ (j + %d)])"
                       % (ti,
                          amin - aoff,
                          wd,
                          bmin - boff))
                self.w("                                "
                       "++bad;")
            else:
                idx = _idx_expr(
                    self.p["clamps"]
                    [fn])
                off = 0
                m = re.match(
                    r"(\w+) - (\d+)",
                    idx)
                if m:
                    off = int(
                        m.group(2))
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w("                        "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, off))
                self.w("                            "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w("                            "
                       "++bad;")
            emitted.append(fn)
        for spec in READERS:
            if spec[2] != d:
                continue
            (fn, stem, dkey, arr,
             kind, pp) = spec
            if kind == "gridstr":
                (an, alo, ahi, bn,
                 blo, bhi) = pp
                wdt = bhi - blo + 1
                self.w("                    "
                       "for (int a = 0; "
                       "a < %d; ++a)"
                       % (ahi - alo + 1))
                self.w("                        "
                       "for (int b = 0; "
                       "b < %d; ++b)"
                       % wdt)
                self.w("                            "
                       "if (std::string("
                       "rules::%s("
                       "%d + a, %d + b))"
                       % (fn, alo, blo))
                self.w("                                "
                       "!= d->"
                       "rows[a * %d + b]"
                       ".name)"
                       % wdt)
                self.w("                                "
                       "++bad;")
            else:
                lo = pp[1]
                self.w("                    "
                       "for (int i = 0; "
                       "i < (int)d->"
                       "rows.size(); "
                       "++i)")
                self.w("                        "
                       "if (std::string("
                       "rules::%s(%d + "
                       "i))" % (fn, lo))
                self.w("                            "
                       "!= d->"
                       "rows[i].name)")
                self.w("                            "
                       "++bad;")
            emitted.append(fn)
        for fn in emitted:
            self.seam_accessors[
                fn] = \
                self.seam_accessors.get(
                    fn, 0) + 1
        self.w("                }")
        self.w("            }")

    # 8. edges
    def sec_edges(self):
        self.w("        // -- 8. "
               "edges -------------"
               "-----------------")
        self.w("        {")
        self.edge_ints()
        self.edge_readers()
        self.edge_scalars()
        self.edge_cstrs()
        self.edge_logic()
        self.edge_kept_counts()
        self.edge_structs()
        self.w("        }")
        self.guard(len(LABELS) - 1)

    def edge_ints(self):
        for spec in INT_FNS:
            (fn, stem, dkey, tag,
             arr, kind, pp) = spec
            if kind == "band":
                lo, hi = pp
                probes = [lo - 1, lo,
                          hi, hi + 1]
            elif kind == "grid2":
                (w, aoff, boff, amin,
                 amax, bmin,
                 bmax) = pp
                probes = [(amin - 1,
                           bmin),
                          (amax + 1,
                           bmax)]
            else:
                vals = self.tables[
                    (dkey, tag)]
                hi = len(vals) - 1
                probes = [-1, 0,
                          hi + 1]
            for a in probes:
                args = a \
                    if isinstance(
                        a, tuple) \
                    else (a,)
                want = \
                    seam_eval_int(
                        fn, list(args),
                        self.p,
                        self.tables,
                        self.model)
                argtxt = ", ".join(
                    str(x) for x
                    in args)
                self.w("            "
                       "if (rules::%s("
                       "%s) != %d)"
                       % (fn, argtxt,
                          want))
                self.w("                "
                       "++bad;")

    def edge_readers(self):
        for spec in READERS:
            (fn, stem, dkey, arr,
             kind, pp) = spec
            if kind == "gridstr":
                (an, alo, ahi, bn,
                 blo, bhi) = pp
                probes = [(alo - 1,
                           blo),
                          (ahi + 1,
                           bhi + 1)]
            else:
                lo, hi = pp[1], pp[2]
                probes = [(lo - 1,),
                          (hi + 1,)]
            for a in probes:
                want = \
                    seam_eval_reader(
                        fn, list(a),
                        self.p,
                        self.rows,
                        self.model)
                argtxt = ", ".join(
                    str(x) for x
                    in a)
                self.w("            "
                       "if (std::string("
                       "rules::%s(%s))"
                       % (fn, argtxt))
                self.w('                '
                       '!= '
                       '"%s") '
                       '++bad;'
                       % _q(want))

    def edge_scalars(self):
        # every zero-arg scalar
        # in the 18 headers,
        # wants from the parse
        for fn in sorted(
                self.p["scalars"]):
            v = self.p["scalars"][fn]
            if isinstance(v, bool):
                self.w("            "
                       "if (rules::"
                       "%s() != %s)"
                       % (fn,
                          "true"
                          if v
                          else
                          "false"))
                self.w("                "
                       "++bad;")
            else:
                self.w("            "
                       "if (rules::"
                       "%s() != %d)"
                       % (fn, v))
                self.w("                "
                       "++bad;")

    def edge_cstrs(self):
        # the zero-arg const
        # char* fns with
        # literal returns
        for fn in sorted(
                self.p["cstrs"]):
            v = self.p["cstrs"][fn]
            self.w("            "
                   "if (std::string("
                   "rules::%s())"
                   % fn)
            self.w('                '
                   '!= '
                   '"%s") '
                   '++bad;'
                   % _q(v))

    def edge_logic(self):
        # the kept 1-arg logic
        # fns the generic model
        # can evaluate; probe
        # args derived from each
        # body; the loop-body
        # count fns and the
        # string-arg fns raise
        # in the model and are
        # covered by
        # edge_kept_counts
        # instead
        for fn in sorted(
                self.fns):
            if fn in RETIRED:
                continue
            stem, ret, args = \
                self.fns[fn]
            if args == "":
                continue
            if "," in args:
                continue
            if "const char*" in args:
                continue
            if "&" in ret:
                continue
            src = self.p["srcs"][
                "rules/ua/" + stem
                + ".h"]
            body = _strip(
                fn_body(src, fn))
            probes = set()
            for m in re.findall(
                    r"case (\w+):",
                    body):
                v = \
                    self.model.\
                    enumval(m)
                probes.add(
                    int(v) if v
                    is not None
                    else int(m))
            for m in re.findall(
                    r"(\w+) ([<>=!]+) "
                    r"(-?\d+)", body):
                lit = int(m[2])
                probes.update(
                    {lit - 1, lit,
                     lit + 1})
            probes.update(
                {0, 1})
            for a in sorted(
                    probes):
                try:
                    want = \
                        self.model.\
                        call(fn, [a])
                except (ValueError,
                        KeyError):
                    continue
                if isinstance(
                        want, str):
                    self.w("            "
                           "if (std::"
                           "string("
                           "rules::%s("
                           "%d))"
                           % (fn, a))
                    self.w('                '
                           '!= '
                           '"%s") '
                           '++bad;'
                           % _q(want))
                else:
                    if isinstance(
                            want,
                            bool):
                        wtxt = \
                            "true" \
                            if want \
                            else \
                            "false"
                    else:
                        wtxt = \
                            str(want)
                    self.w("            "
                           "if (rules::"
                           "%s(%d) != "
                           "%s)"
                           % (fn, a,
                              wtxt))
                    self.w("                "
                           "++bad;")

    def _struct_of(self, afn):
        for (stem, fn, sname,
             cnt, fields) \
                in KEEP_STRUCTS:
            if fn == afn:
                return (stem, sname,
                        cnt, fields)
        die("struct of " + afn)

    def edge_kept_counts(self):
        # the count fns the
        # model cannot evaluate
        for ent in KEPT_COUNTS:
            kind = ent[0]
            fn = ent[1]
            if kind == "structfield":
                (_, _2, afn,
                 field, cnt) = ent
                (stem, sname, n,
                 fields) = \
                    self._struct_of(
                        afn)
                fi = fields.index(
                    field)
                col = []
                for strs, ints in \
                        self.p[
                            "structs"][
                            afn]:
                    col.append(
                        ints[fi - 1]
                        if fi > 0
                        else None)
                counts = {}
                for v in col:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           "%d) != %d)"
                           % (fn, v,
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       "if (rules::%s("
                       "999) != 0)"
                       % fn)
                self.w("                "
                       "++bad;")
            elif kind == "reader":
                (_, _2, rfn,
                 cnt) = ent
                vals = None
                for spec in READERS:
                    if spec[0] == rfn:
                        vals = \
                            self.p[
                                "strs"][
                                rfn]
                        break
                if vals is None:
                    for spec in \
                            INT_FNS:
                        if spec[0] \
                                == rfn:
                            vals = \
                                self.\
                                tables[
                                    (spec[
                                         2],
                                     spec[
                                         3])]
                            break
                counts = {}
                for v in vals:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           "%d) != %d)"
                           % (fn, v,
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       "if (rules::%s("
                       "999) != 0)"
                       % fn)
                self.w("                "
                       "++bad;")
            elif kind == "nonnull":
                (_, _2, rfn,
                 cnt) = ent
                names = self.p[
                    "strs"][rfn]
                nn = sum(
                    1 for x in names
                    if x != "")
                self.w("            "
                       "if (rules::%s() "
                       "!= %d) ++bad;"
                       % (fn, nn))
            elif kind == "freq":
                (_, _2, afn) = ent
                (stem, sname, n,
                 fields) = \
                    self._struct_of(
                        afn)
                fi = fields.index(
                    "freq")
                col = []
                for strs, ints in \
                        self.p[
                            "structs"][
                            afn]:
                    col.append(
                        strs[fi])
                counts = {}
                for v in col:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           '"%s") != %d)'
                           % (fn,
                              _q(v),
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       'if (rules::%s('
                       '"never") != 0)'
                       % fn)
                self.w("                "
                       "++bad;")

    def edge_structs(self):
        # the seven KEPT struct
        # seams: every field of
        # every row probed
        # against the parse
        for (stem, afn, sname,
             cnt, fields) \
                in KEEP_STRUCTS:
            recs = self.p[
                "structs"][afn]
            nstr = sum(
                1 for f in fields
                if not f.endswith(
                    "Count")
                and f in (
                    "name", "sphere",
                    "head", "body",
                    "color", "days",
                    "freq", "form"))
            for i, rec in \
                    enumerate(recs):
                strs, ints = rec
                si = 0
                ii = 0
                for f in fields:
                    if f in (
                            "name",
                            "sphere",
                            "head",
                            "body",
                            "color",
                            "days",
                            "freq",
                            "form"):
                        self.w(
                            "            "
                            "if (std::"
                            "string("
                            "rules::%s("
                            "%d).%s)"
                            % (afn, i,
                               f))
                        self.w(
                            '                '
                            '!= '
                            '"%s") '
                            '++bad;'
                            % _q(
                                strs[
                                    si]))
                        si += 1
                    else:
                        self.w(
                            "            "
                            "if (rules::"
                            "%s(%d).%s "
                            "!= %d)"
                            % (afn, i,
                               f,
                               ints[
                                   ii]))
                        self.w(
                            "                "
                            "++bad;")
                        ii += 1

    def build(self):
        self.head()
        self.sec_load()
        self.sec_counts()
        self.sec_defs(0, "A")
        self.sec_defs(1, "B")
        self.sec_defs(2, "C")
        self.sec_defs(3, "D")
        self.sec_seam()
        self.sec_edges()
        self.w("    }")
        return "\n".join(
            self.out) + "\n"


# ---- the self-scan ----------------------------

def self_scan(p, tables, rows,
              frag):
    bad = []
    for d in DEFS:
        path = os.path.join(
            ROOT, LUA_DIR,
            d + ".lua")
        if not os.path.exists(
                path):
            bad.append("lua "
                       + d
                       + " missing")
            continue
        t = open(path).read()
        if ('key = "%s"'
                % d) not in t:
            bad.append("lua key "
                       + d)
        if ("value = %d,"
                % len(rows[d])) \
                not in t:
            bad.append("lua rows "
                       + d)
        for tag, vals in \
                def_tables(d,
                           tables):
            if ('name = "%s"'
                    % tag) not in t:
                bad.append("lua table "
                           + d
                           + "/" + tag)
    # the headers: zero
    # static const except the
    # seven KEPT struct seams
    kept_static = {
        "uascharts.h": 1,
        "uacantrips1.h": 1,
        "uacantrips2.h": 1,
        "uacantrips3.h": 1,
        "uacantrips4.h": 1,
        "uacantrips5.h": 1,
        "uacantrips6.h": 1,
    }
    for f in FILES:
        stem = f.split("/")[-1]
        src = _strip(open(os.path.join(
            ROOT, f)).read())
        found = len(re.findall(
            r"static const ", src))
        want = kept_static.get(
            stem, 0)
        if found != want:
            bad.append(
                "statics in "
                + stem + ": "
                + str(found)
                + " != "
                + str(want))
    # the seam header loads
    # BOTH family dirs
    sh = open(os.path.join(
        ROOT, "rules/ua/",
        "uaregistry.h")).read()
    for tok in ("uaReg()",
                "uaRows(",
                "uaTable(",
                "ua_classes",
                "ua_spells"):
        if tok not in sh:
            bad.append("seam "
                       + tok)
    # the fragment
    for lab in LABELS:
        if ("R1057 uaspells "
            "registry %s audit: "
            "bad %%d\\n" % lab) \
                not in frag:
            bad.append("frag "
                       + lab)
    for d in DEFS:
        if ('reg.find('
                '"%s")' % d) \
                not in frag:
            bad.append("frag find "
                       + d)
    for spec in INT_FNS:
        fn = spec[0]
        n = seam_accessors_all.get(
            fn, 0)
        if n != 1:
            bad.append("seam "
                       + fn
                       + " read "
                       + str(n)
                       + "x")
    for spec in READERS:
        fn = spec[0]
        n = seam_accessors_all.get(
            fn, 0)
        if n != 1:
            bad.append("seam "
                       + fn
                       + " read "
                       + str(n)
                       + "x")
    # census
    c = census_count()
    if c != CENSUS_AFTER:
        bad.append("census %d"
                   % c)
    return bad


seam_accessors_all = {}


# ---- main -------------------------------------

def main():
    if not os.path.isfile(
            os.path.join(
                ROOT, REGTEST)):
        die("run me from the "
            "repo root")
    h0 = open(os.path.join(
        ROOT, FILES[0])).read()
    if APPLIED_MARK in h0:
        # the R1057 cascade lesson: an
        # already-spliced tree still
        # needs the KEPT fixups (a v1-
        # spliced tree lacks fragment
        # fixups added in a later tool
        # revision) - the early return
        # must not skip them.
        apply_kept_fixups()
        print("applied 0, "
              "already 18")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    p = parse_pristine()
    enums = parse_enums(
        p["srcs"])
    fns = parse_fns(p["srcs"])
    rows = build_defs(p)
    tables = build_tables(p)
    intmeta = {(s[2], s[3]): s
               for s in INT_FNS}
    # the regtest seat
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1056 include "
            "anchor not found")
    lines = rt.splitlines()
    at = lines.index(
        [l for l in lines
         if INC_ANCHOR in l][0])
    if at != 1304:
        die("R1056 include at "
            "line %d, want 1305"
            % (at + 1))
    rt = rt.replace(
        INC_ANCHOR + "\n",
        INC_ANCHOR + "\n"
        + F_INC + "\n", 1)
    # build
    fe = FE(p, enums, fns,
            rows, tables)
    frag = fe.build()
    global seam_accessors_all
    seam_accessors_all = \
        fe.seam_accessors
    # write
    build_lua(rows, tables,
              intmeta)
    write_seam_header()
    applied = rewrite_headers(
        p, tables)
    apply_kept_fixups()
    open(os.path.join(
        ROOT, FRAG),
        "w").write(frag)
    open(os.path.join(
        ROOT, REGTEST),
        "w").write(rt)
    # self-scan
    bad = self_scan(p, tables,
                    rows, frag)
    if bad:
        for b in bad:
            print("SELF-SCAN "
                  "FAIL: " + b)
        die("self-scan")
    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("post census %d, "
            "want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d "
          "audit printf "
          "patterns" % (c0, c1))
    print("applied %d headers, "
          "%d lua defs, seam "
          "header, fragment"
          % (applied, len(DEFS)))
    print("SPLICE OK")


def apply_kept_fixups():
    for (path, old, new) \
            in KEPT_FIXUPS:
        full = os.path.join(
            ROOT, path)
        raw = open(full).read()
        if old in raw:
            raw = raw.replace(
                old, new, 1)
            open(full,
                 "w").write(raw)


if __name__ == "__main__":
    main()
