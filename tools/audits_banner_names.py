#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/audits_banner_names.py
# The rules/audits/ naming pass: all 202 rNNN_batch.h headers
# rename to their own banner names (the descriptive title sits in
# each file's first banner line - R900 Dragon Creature Features,
# R848 FF magic item tables, etc), mechanically slugged:
# rNNN_batch.h -> rNNN_<banner-slug>.h, same directory. regtest.cpp
# include lines and tools/spec_r*.json audit_file/anchor refs
# rewrite with them. The doc/vibe seed and backup records are
# ARCHIVE - history prose, never rewritten. Nothing deleted, no
# content changes, no commit.
import os, re, subprocess, sys

TOOL = "tools/audits_banner_names.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v2.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- audits renames: the 202 batch headers take their own
# banner names (rNNN_batch.h -> rNNN_<banner-slug>.h)
MOVES = {
    "rules/audits/r1000_batch.h": "rules/audits/r1000_ua_promotion_batch_two.h",
    "rules/audits/r1001_batch.h": "rules/audits/r1001_ua_promotion_batch_three.h",
    "rules/audits/r1002_batch.h": "rules/audits/r1002_ua_promotion_batch_four.h",
    "rules/audits/r1003_batch.h": "rules/audits/r1003_ua_promotion_batch_five.h",
    "rules/audits/r1004_batch.h": "rules/audits/r1004_ua_promotion_batch_six.h",
    "rules/audits/r1005_batch.h": "rules/audits/r1005_ua_promotion_batch_seven.h",
    "rules/audits/r1006_batch.h": "rules/audits/r1006_promotions_mop_round_one.h",
    "rules/audits/r1007_batch.h": "rules/audits/r1007_promotions_mop_round_two.h",
    "rules/audits/r1008_batch.h": "rules/audits/r1008_promotions_mop_round_three.h",
    "rules/audits/r1009_batch.h": "rules/audits/r1009_mm1_normalization_batch_one.h",
    "rules/audits/r1010_batch.h": "rules/audits/r1010_mm1_normalization_batch_two.h",
    "rules/audits/r1011_batch.h": "rules/audits/r1011_mm1_normalization_batch_three.h",
    "rules/audits/r1012_batch.h": "rules/audits/r1012_mm1_normalization_batch_four.h",
    "rules/audits/r1013_batch.h": "rules/audits/r1013_mm1_normalization_batch_five.h",
    "rules/audits/r1014_batch.h": "rules/audits/r1014_mm1_normalization_batch_six.h",
    "rules/audits/r1015_batch.h": "rules/audits/r1015_oa_table_promotion_batch_nine.h",
    "rules/audits/r1016_batch.h": "rules/audits/r1016_oa_normalization.h",
    "rules/audits/r1017_batch.h": "rules/audits/r1017_mm2_normalization.h",
    "rules/audits/r1018_batch.h": "rules/audits/r1018_mm2_normalization.h",
    "rules/audits/r1019_batch.h": "rules/audits/r1019_mm2_normalization.h",
    "rules/audits/r1020_batch.h": "rules/audits/r1020_mm2_normalization.h",
    "rules/audits/r1021_batch.h": "rules/audits/r1021_ff_normalization.h",
    "rules/audits/r1022_batch.h": "rules/audits/r1022_ff_normalization.h",
    "rules/audits/r1023_batch.h": "rules/audits/r1023_ff_normalization.h",
    "rules/audits/r1024_batch.h": "rules/audits/r1024_wsg_mop_normalization.h",
    "rules/audits/r1025_batch.h": "rules/audits/r1025_drg_normalization.h",
    "rules/audits/r1026_batch.h": "rules/audits/r1026_deity_seam_close.h",
    "rules/audits/r826_batch.h": "rules/audits/r826_dmg_tables_batch.h",
    "rules/audits/r827_batch.h": "rules/audits/r827_subclass_batch.h",
    "rules/audits/r828_batch.h": "rules/audits/r828_hundred_block_batch.h",
    "rules/audits/r829_batch.h": "rules/audits/r829_ua_wsg_batch.h",
    "rules/audits/r830_batch.h": "rules/audits/r830_wsg_dsg_batch.h",
    "rules/audits/r831_batch.h": "rules/audits/r831_planes_oa_batch.h",
    "rules/audits/r832_batch.h": "rules/audits/r832_oa_tail_batch.h",
    "rules/audits/r833_batch.h": "rules/audits/r833_final_digest_batch.h",
    "rules/audits/r834_batch.h": "rules/audits/r834_holdback_tooling_patch.h",
    "rules/audits/r835_batch.h": "rules/audits/r835_final_holdback_batch.h",
    "rules/audits/r836_batch.h": "rules/audits/r836_first_ff_promotion.h",
    "rules/audits/r837_batch.h": "rules/audits/r837_second_ff_promotion.h",
    "rules/audits/r838_batch.h": "rules/audits/r838_third_ff_promotion.h",
    "rules/audits/r839_batch.h": "rules/audits/r839_fourth_ff_promotion.h",
    "rules/audits/r840_batch.h": "rules/audits/r840_hornet_promotion.h",
    "rules/audits/r841_batch.h": "rules/audits/r841_ff_index_line_walk.h",
    "rules/audits/r842_batch.h": "rules/audits/r842_fifth_ff_promotion.h",
    "rules/audits/r843_batch.h": "rules/audits/r843_sixth_ff_promotion.h",
    "rules/audits/r844_batch.h": "rules/audits/r844_seventh_ff_promotion.h",
    "rules/audits/r845_batch.h": "rules/audits/r845_eighth_ff_promotion.h",
    "rules/audits/r846_batch.h": "rules/audits/r846_ff_monster_level_tables.h",
    "rules/audits/r847_batch.h": "rules/audits/r847_ff_encounter_listings.h",
    "rules/audits/r848_batch.h": "rules/audits/r848_ff_magic_item_tables.h",
    "rules/audits/r849_batch.h": "rules/audits/r849_ddg_front_matter.h",
    "rules/audits/r850_batch.h": "rules/audits/r850_american_indian_mythos.h",
    "rules/audits/r851_batch.h": "rules/audits/r851_arthurian_mythos.h",
    "rules/audits/r852_batch.h": "rules/audits/r852_babylonian_mythos.h",
    "rules/audits/r853_batch.h": "rules/audits/r853_celtic_mythos.h",
    "rules/audits/r854_batch.h": "rules/audits/r854_central_american_mythos.h",
    "rules/audits/r855_batch.h": "rules/audits/r855_chinese_mythos.h",
    "rules/audits/r856_batch.h": "rules/audits/r856_cthulhu_mythos.h",
    "rules/audits/r857_batch.h": "rules/audits/r857_egyptian_mythos.h",
    "rules/audits/r858_batch.h": "rules/audits/r858_finnish_mythos.h",
    "rules/audits/r859_batch.h": "rules/audits/r859_greek_mythos.h",
    "rules/audits/r860_batch.h": "rules/audits/r860_indian_mythos.h",
    "rules/audits/r861_batch.h": "rules/audits/r861_japanese_mythos.h",
    "rules/audits/r862_batch.h": "rules/audits/r862_melnibonean_mythos.h",
    "rules/audits/r863_batch.h": "rules/audits/r863_nehwon_mythos.h",
    "rules/audits/r864_batch.h": "rules/audits/r864_nonhumans_deities.h",
    "rules/audits/r865_batch.h": "rules/audits/r865_norse_mythos.h",
    "rules/audits/r866_batch.h": "rules/audits/r866_sumerian_mythos.h",
    "rules/audits/r867_batch.h": "rules/audits/r867_known_planes.h",
    "rules/audits/r868_batch.h": "rules/audits/r868_temple_trappings.h",
    "rules/audits/r869_batch.h": "rules/audits/r869_clerical_chart_batch_one.h",
    "rules/audits/r870_batch.h": "rules/audits/r870_clerical_chart_batch_two.h",
    "rules/audits/r871_batch.h": "rules/audits/r871_clerical_chart_batch_three.h",
    "rules/audits/r872_batch.h": "rules/audits/r872_clerical_chart_batch_four.h",
    "rules/audits/r873_batch.h": "rules/audits/r873_clerical_chart_batch_five.h",
    "rules/audits/r874_batch.h": "rules/audits/r874_clerical_chart_batch_six.h",
    "rules/audits/r875_batch.h": "rules/audits/r875_clerical_chart_batch_seven.h",
    "rules/audits/r876_batch.h": "rules/audits/r876_clerical_chart_batch_eight.h",
    "rules/audits/r877_batch.h": "rules/audits/r877_appendix_4_and_index.h",
    "rules/audits/r878_batch.h": "rules/audits/r878_alignment_figures.h",
    "rules/audits/r879_batch.h": "rules/audits/r879_registry_schema.h",
    "rules/audits/r880_batch.h": "rules/audits/r880_ddg_promotion.h",
    "rules/audits/r881_batch.h": "rules/audits/r881_ddg_promotion.h",
    "rules/audits/r882_batch.h": "rules/audits/r882_ddg_promotion.h",
    "rules/audits/r883_batch.h": "rules/audits/r883_ddg_promotion.h",
    "rules/audits/r884_batch.h": "rules/audits/r884_ddg_promotion.h",
    "rules/audits/r885_batch.h": "rules/audits/r885_ddg_promotion.h",
    "rules/audits/r886_batch.h": "rules/audits/r886_ddg_promotion.h",
    "rules/audits/r887_batch.h": "rules/audits/r887_ives_attribute.h",
    "rules/audits/r888_batch.h": "rules/audits/r888_dragon_small_variants.h",
    "rules/audits/r889_batch.h": "rules/audits/r889_aronson_deltas.h",
    "rules/audits/r890_batch.h": "rules/audits/r890_remorhaz_lore.h",
    "rules/audits/r891_batch.h": "rules/audits/r891_alchemist_class.h",
    "rules/audits/r892_batch.h": "rules/audits/r892_fischer_items.h",
    "rules/audits/r893_batch.h": "rules/audits/r893_systems.h",
    "rules/audits/r894_batch.h": "rules/audits/r894_artificer.h",
    "rules/audits/r895_batch.h": "rules/audits/r895_women_magic.h",
    "rules/audits/r896_batch.h": "rules/audits/r896_specialists.h",
    "rules/audits/r897_batch.h": "rules/audits/r897_fighting_sub_classes.h",
    "rules/audits/r898_batch.h": "rules/audits/r898_character_round.h",
    "rules/audits/r899_batch.h": "rules/audits/r899_comedy_and_small_variants.h",
    "rules/audits/r900_batch.h": "rules/audits/r900_dragon_creature_features.h",
    "rules/audits/r901_batch.h": "rules/audits/r901_creature_features_closure.h",
    "rules/audits/r902_batch.h": "rules/audits/r902_dragon_issue_5.h",
    "rules/audits/r903_batch.h": "rules/audits/r903_dragon_issue_5_closure.h",
    "rules/audits/r904_batch.h": "rules/audits/r904_wilderness_encounter_table.h",
    "rules/audits/r905_batch.h": "rules/audits/r905_witch_remainders.h",
    "rules/audits/r906_batch.h": "rules/audits/r906_issue_6_opener.h",
    "rules/audits/r907_batch.h": "rules/audits/r907_dragon_issue_6_closure.h",
    "rules/audits/r908_batch.h": "rules/audits/r908_prowler_opener.h",
    "rules/audits/r909_batch.h": "rules/audits/r909_dragon_issue_7_closure.h",
    "rules/audits/r910_batch.h": "rules/audits/r910_issue_8_opener.h",
    "rules/audits/r911_batch.h": "rules/audits/r911_dragon_issue_8_closure.h",
    "rules/audits/r912_batch.h": "rules/audits/r912_issue_9_opener.h",
    "rules/audits/r913_batch.h": "rules/audits/r913_dragon_issue_9_closure.h",
    "rules/audits/r914_batch.h": "rules/audits/r914_issue_10_opener.h",
    "rules/audits/r915_batch.h": "rules/audits/r915_issue_10_opener.h",
    "rules/audits/r916_batch.h": "rules/audits/r916_dragon_issue_10_closure.h",
    "rules/audits/r917_batch.h": "rules/audits/r917_issue_11_opener.h",
    "rules/audits/r918_batch.h": "rules/audits/r918_dragon_issue_11_closure.h",
    "rules/audits/r919_batch.h": "rules/audits/r919_issue_12_opener.h",
    "rules/audits/r920_batch.h": "rules/audits/r920_issue_12_opener_part_two.h",
    "rules/audits/r921_batch.h": "rules/audits/r921_dragon_issue_12_closure.h",
    "rules/audits/r922_batch.h": "rules/audits/r922_issue_13_opener.h",
    "rules/audits/r923_batch.h": "rules/audits/r923_issue_13_opener_part_two.h",
    "rules/audits/r924_batch.h": "rules/audits/r924_dragon_issue_13_closure.h",
    "rules/audits/r925_batch.h": "rules/audits/r925_issue_14_opener.h",
    "rules/audits/r926_batch.h": "rules/audits/r926_dragon_issue_14_closure.h",
    "rules/audits/r927_batch.h": "rules/audits/r927_issue_15_opener.h",
    "rules/audits/r928_batch.h": "rules/audits/r928_dragon_issue_15_closure.h",
    "rules/audits/r929_batch.h": "rules/audits/r929_issue_16_opener.h",
    "rules/audits/r930_batch.h": "rules/audits/r930_dragon_issue_16_closure.h",
    "rules/audits/r931_batch.h": "rules/audits/r931_issue_17_opener_part_one.h",
    "rules/audits/r932_batch.h": "rules/audits/r932_issue_17_wizard_article_part_two.h",
    "rules/audits/r933_batch.h": "rules/audits/r933_dragon_issue_17_closure.h",
    "rules/audits/r934_batch.h": "rules/audits/r934_issue_18_opener_part_one.h",
    "rules/audits/r935_batch.h": "rules/audits/r935_issue_18_opener_part_two.h",
    "rules/audits/r936_batch.h": "rules/audits/r936_dragon_issue_18_closure.h",
    "rules/audits/r937_batch.h": "rules/audits/r937_issue_19_opener_part_one.h",
    "rules/audits/r938_batch.h": "rules/audits/r938_issue_19_opener_part_two.h",
    "rules/audits/r939_batch.h": "rules/audits/r939_dragon_issue_19_closure.h",
    "rules/audits/r940_batch.h": "rules/audits/r940_issue_20_opener_part_one.h",
    "rules/audits/r941_batch.h": "rules/audits/r941_issue_20_opener_part_two.h",
    "rules/audits/r942_batch.h": "rules/audits/r942_dragon_issue_20_closure.h",
    "rules/audits/r943_batch.h": "rules/audits/r943_issue_21_opener_part_one.h",
    "rules/audits/r944_batch.h": "rules/audits/r944_issue_21_opener_part_two.h",
    "rules/audits/r945_batch.h": "rules/audits/r945_dragon_issue_21_closure.h",
    "rules/audits/r946_batch.h": "rules/audits/r946_issue_22_opener_part_one.h",
    "rules/audits/r947_batch.h": "rules/audits/r947_issue_22_sneak_preview.h",
    "rules/audits/r948_batch.h": "rules/audits/r948_issue_22_commentary_set.h",
    "rules/audits/r949_batch.h": "rules/audits/r949_dragon_issue_22_closure.h",
    "rules/audits/r950_batch.h": "rules/audits/r950_issue_23_variant_triptych.h",
    "rules/audits/r951_batch.h": "rules/audits/r951_issue_23_lower_planes_generation.h",
    "rules/audits/r952_batch.h": "rules/audits/r952_issue_23_commentary_set.h",
    "rules/audits/r953_batch.h": "rules/audits/r953_dragon_issue_23_closure.h",
    "rules/audits/r954_batch.h": "rules/audits/r954_issue_24_variant_triptych.h",
    "rules/audits/r955_batch.h": "rules/audits/r955_issue_24_alignment_pantheon.h",
    "rules/audits/r956_batch.h": "rules/audits/r956_issue_24_commentary_set.h",
    "rules/audits/r957_batch.h": "rules/audits/r957_dragon_issue_24_closure.h",
    "rules/audits/r958_batch.h": "rules/audits/r958_issue_25_opener_set.h",
    "rules/audits/r959_batch.h": "rules/audits/r959_issue_25_table_round.h",
    "rules/audits/r960_batch.h": "rules/audits/r960_issue_25_commentary_set.h",
    "rules/audits/r961_batch.h": "rules/audits/r961_dragon_issue_25_closure.h",
    "rules/audits/r962_batch.h": "rules/audits/r962_issue_26_opener_set.h",
    "rules/audits/r963_batch.h": "rules/audits/r963_issue_26_table_round.h",
    "rules/audits/r964_batch.h": "rules/audits/r964_issue_26_commentary_set.h",
    "rules/audits/r965_batch.h": "rules/audits/r965_dragon_issue_26_closure.h",
    "rules/audits/r966_batch.h": "rules/audits/r966_content_structure_charter.h",
    "rules/audits/r967_batch.h": "rules/audits/r967_content_tree_creation.h",
    "rules/audits/r968_batch.h": "rules/audits/r968_rules_record_format.h",
    "rules/audits/r969_batch.h": "rules/audits/r969_dragon_promotion_batch_one.h",
    "rules/audits/r970_batch.h": "rules/audits/r970_dragon_promotion_batch_two.h",
    "rules/audits/r971_batch.h": "rules/audits/r971_dragon_promotion_batch_three.h",
    "rules/audits/r972_batch.h": "rules/audits/r972_dragon_promotion_batch_four.h",
    "rules/audits/r973_batch.h": "rules/audits/r973_dragon_promotion_batch_five.h",
    "rules/audits/r974_batch.h": "rules/audits/r974_dragon_promotion_batch_six.h",
    "rules/audits/r975_batch.h": "rules/audits/r975_dragon_promotion_batch_seven.h",
    "rules/audits/r976_batch.h": "rules/audits/r976_dragon_promotion_batch_eight.h",
    "rules/audits/r977_batch.h": "rules/audits/r977_dragon_promotion_batch_nine.h",
    "rules/audits/r978_batch.h": "rules/audits/r978_dragon_promotion_batch_ten.h",
    "rules/audits/r979_batch.h": "rules/audits/r979_dragon_promotion_batch_eleven.h",
    "rules/audits/r980_batch.h": "rules/audits/r980_dragon_promotion_batch_twelve.h",
    "rules/audits/r981_batch.h": "rules/audits/r981_oa_promotion_batch_one.h",
    "rules/audits/r982_batch.h": "rules/audits/r982_oa_promotion_batch_two.h",
    "rules/audits/r983_batch.h": "rules/audits/r983_oa_promotion_batch_three.h",
    "rules/audits/r984_batch.h": "rules/audits/r984_oa_promotion_batch_four.h",
    "rules/audits/r985_batch.h": "rules/audits/r985_oa_promotion_batch_five.h",
    "rules/audits/r986_batch.h": "rules/audits/r986_oa_promotion_batch_six.h",
    "rules/audits/r987_batch.h": "rules/audits/r987_oa_promotion_batch_seven.h",
    "rules/audits/r988_batch.h": "rules/audits/r988_oa_promotion_batch_eight.h",
    "rules/audits/r989_batch.h": "rules/audits/r989_wsg_promotion_batch_one.h",
    "rules/audits/r990_batch.h": "rules/audits/r990_wsg_promotion_batch_two.h",
    "rules/audits/r991_batch.h": "rules/audits/r991_wsg_promotion_batch_three.h",
    "rules/audits/r992_batch.h": "rules/audits/r992_wsg_promotion_batch_four.h",
    "rules/audits/r993_batch.h": "rules/audits/r993_wsg_promotion_batch_five.h",
    "rules/audits/r994_batch.h": "rules/audits/r994_dsg_promotion_batch_one.h",
    "rules/audits/r995_batch.h": "rules/audits/r995_dsg_promotion_batch_two.h",
    "rules/audits/r996_batch.h": "rules/audits/r996_dsg_promotion_batch_three.h",
    "rules/audits/r997_batch.h": "rules/audits/r997_dsg_promotion_batch_four.h",
    "rules/audits/r998_batch.h": "rules/audits/r998_dsg_promotion_batch_five.h",
    "rules/audits/r999_batch.h": "rules/audits/r999_ua_promotion_batch_one.h",
}

# --- nothing deleted this round
DELETES = ()



def die(msg):
    sys.stderr.write("REORG RED: " + msg + "\n")
    sys.exit(1)


def git(*args):
    r = subprocess.run(["git"] + list(args), capture_output=True,
                      text=True)
    if r.returncode != 0:
        die("git " + " ".join(args) + " -> " + r.stderr.strip())
    return r.stdout


def build_plan():
    return [(o, n, False) for o, n in sorted(MOVES.items())]


def main():
    if not os.path.isfile("regtest.cpp"):
        die("run from the repo root (regtest.cpp not found)")
    moves = build_plan()
    applied, already = 0, 0
    for old, new, _rn in moves:
        o_exists = os.path.isfile(old)
        n_exists = os.path.isfile(new)
        if o_exists and n_exists:
            die("both exist: " + old + " and " + new)
        if not o_exists and n_exists:
            already += 1
            continue
        if not o_exists and not n_exists:
            die("missing: " + old)
        os.makedirs(os.path.dirname(new), exist_ok=True)
        git("mv", old, new)
        applied += 1
        print("moved " + old + " -> " + new)

    # deletions -----------------------------------------------------------
    deleted = 0
    for d in DELETES:
        if os.path.isfile(d) or os.path.islink(d):
            git("rm", "-q", "--", d)
            deleted += 1
            print("deleted " + d)
    print("deletes applied " + str(deleted) + " of "
          + str(len(DELETES)))

    # reference rewrite -----------------------------------------------------
    tracked = [f for f in git("ls-files").split()
               if f != TOOL and f not in ARCHIVE
               and not f.endswith(BIN_EXT)]
    # longest-first so dp10.h is safe from dp1.h
    path_rules = [(o, n) for o, n, _rn in moves]
    path_rules.sort(key=lambda t: -len(t[0]))
    bare_rules = [(os.path.basename(o), n) for o, n, rn in moves
                  if rn]
    bare_rules.sort(key=lambda t: -len(t[0]))
    touched = 0
    for f in tracked:
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        orig = body
        for o, n in path_rules:
            if o in body:
                sent = "\x00KEEP\x00"
                body = body.replace(n, sent)
                body = body.replace(o, n)
                body = body.replace(sent, n)
        for ob, n in bare_rules:
            pat = re.compile(r"(?<![A-Za-z0-9_/])" + re.escape(ob)
                             + r"(?![A-Za-z0-9_])")
            body = pat.sub(n, body)
        if body != orig:
            with open(f, "w", encoding="utf-8") as fh:
                fh.write(body)
            touched += 1
            print("rewrote " + f)

    # include repair (v2): normalize every quoted include to its
    # file-relative target (true quoted-include semantics - the
    # R400 lesson: a moved classes.h breaks bare includes that
    # only worked at the old location). Idempotent.
    by_base = {}
    for f in tracked:
        by_base.setdefault(os.path.basename(f), []).append(f)
    inc_pat = re.compile(r'(#include\s+")([^"]+)(")')
    fixed_inc, unresolved = 0, []

    def resolve_incl(f, m):
        nonlocal fixed_inc
        d = os.path.dirname(f) or "."
        target = os.path.normpath(os.path.join(d, m.group(2)))
        if os.path.isfile(target):
            return m.group(0)              # already correct
        cands = by_base.get(os.path.basename(m.group(2)), [])
        if len(cands) == 1:
            rel = os.path.relpath(cands[0], d).replace(os.sep, "/")
            fixed_inc += 1
            return m.group(1) + rel + m.group(3)
        if not cands:
            return m.group(0)
        unresolved.append(f + ': "' + m.group(2) + '"')
        return m.group(0)

    for f in tracked:
        if not f.endswith((".h", ".cpp", ".c")):
            continue
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        new = inc_pat.sub(lambda m: resolve_incl(f, m), body)
        if new != body:
            with open(f, "w", encoding="utf-8") as fh:
                fh.write(new)
            print("fixed includes in " + f)
    if unresolved:
        for u in sorted(set(unresolved))[:40]:
            sys.stderr.write("ambiguous include " + u + "\n")
        die("ambiguous includes (" + str(len(unresolved)) + ")")

    # verify: no stale references ------------------------------------------
    stale = []
    for f in tracked:
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        for o, n, rn in moves:
            # n contains o (root sweep pairs), so blank out the new
            # path before looking for a stale old one
            if o in body.replace(n, "\x00"):
                stale.append(f + ": " + o)
    if stale:
        for s in sorted(set(stale))[:40]:
            sys.stderr.write("stale ref " + s + "\n")
        die("stale references remain (" + str(len(stale)) + ")")
    print("REORG GREEN: applied " + str(applied) + ", already "
          + str(already) + ", moved " + str(len(moves))
          + ", rewrote " + str(touched) + " files, include_fix "
          + str(fixed_inc) + ", deletes " + str(deleted))


main()
