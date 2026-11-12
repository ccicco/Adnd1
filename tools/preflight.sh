#!/data/data/com.termux/files/usr/bin/bash
# preflight.sh -- the gate that must pass before any git add/commit/push.
# Runs the full regtest battery on a FRESH binary (chained &&, so a
# failed build can never run a stale regtest) plus hygiene checks.
# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
# R107 (the lean gate): the gate now compiles only the
# TUs the battery build does NOT - every TU compiles
# exactly once per preflight (the old gate doubled the
# build's own files; the -Wswitch warning printed twice).
# It also gained monsters/MonsterXp.cpp, which no compile
# path had ever touched.
# Usage:  ./tools/preflight.sh && git add -A && git commit -m "..." && git push
# Exit 0 only when every check is green.
# R112c: two new checks born of the R112 mishap - (a) the
# battery census: every audit printf in regtest.cpp must
# appear EXACTLY ONCE in the battery output as "bad 0" (a
# double-inserted audit block or a missing audit both end
# RED); (b) hygiene FAILS when untracked file(s) exist but
# no tracked file is modified - the shape of a splice that
# never ran (the 7a86ee7 lesson). Steps renumbered to 5.

set -u
cd "$(dirname "$0")/.."
fail=0

echo "== [1/5] syntax gate: the build's complement (R99/R107) =="
# R107 (the lean gate): the battery build below compiles
# rules/, dm/, abilities/ (R118 - it was compiled by
# nothing before), items/, spells/, monsters/
# MonsterRegistry.cpp and regtest.cpp - a syntax pass
# over the same files
# was pure redundancy. This gate now covers ONLY the
# complement, so every Termux-visible TU compiles exactly
# once per preflight. Same R99 discipline: one file at a
# time so a failure names its file, NOT "|| break" - the
# loop remembers failures and the gate ends RED. A build
# failure in the build's own files still names its file in
# step 2 and ends RED there - attribution is kept.
# NEW COVERAGE: monsters/MonsterXp.cpp was compiled by NO
# path (the old loop never listed monsters/; the build
# links only MonsterRegistry.cpp) while its xpForKill/
# xpForNpc are called from game/state_dungeon.cpp - it
# joins the gate here.
# adnd1.cpp stays skipped: the Win32/GDI shell needs
# windows.h (MSVC verify pending, backlog).
# R301: the engine audit drives live AppState
# methods, so the battery build below now compiles
# every game/*.cpp state TU and links
# monsters/MonsterXp.cpp (xpForKill feeds
# state_dungeon.cpp). The complement gate drops
# game/*.cpp and MonsterXp.cpp from its loop (the
# R107 NEW COVERAGE note above is the pre-R301
# history); every TU still compiles exactly once.
checked=0
for f in ai/*.cpp spelleffects/*.cpp \
         treasuresim.cpp; do
  if [ ! -f "$f" ]; then continue; fi
  checked=$((checked + 1))
  if ! clang++ -fsyntax-only -std=c++17 -I. "$f"; then
    echo "SYNTAX FAIL: $f"
    fail=1
  fi
done
if [ "$fail" = 0 ]; then
  echo "SYNTAX-OK: $checked complement TUs clean (the battery build covers the rest)"
fi

echo "== [2/5] regtest build + battery (fresh binary) =="
# R112c: tee keeps stdout byte-identical while the census gate
# below reads the copy; PIPESTATUS keeps regtest's own exit
# code authoritative (a failed battery still ends RED).
# R515: the quiet battery display - green audit lines are
# filtered from the TERMINAL VIEW ONLY; tee still writes the
# complete output to $batfile, so the census gate below sees
# every audit line exactly as before. A nonzero bad count does
# not match the filter and stays visible. The build's stderr is
# captured for the warning gate: the build is warning-clean as
# of R515 (the character.cpp -Wswitch and regtest.cpp
# -Wstring-compare fixes), so ANY warning now ends RED.
batfile=$(mktemp)
warnfile=$(mktemp)
if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \
  rules/engine/dice.cpp rules/engine/character.cpp rules/engine/classes.cpp rules/engine/combat.cpp \
  rules/engine/saves.cpp rules/engine/turn.cpp rules/engine/races.cpp \
  dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \
  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \
  abilities/abilities.cpp items/items.cpp ai/actor.cpp \
  game/state_core.cpp game/state_dungeon.cpp \
  game/state_combat.cpp game/state_town.cpp \
  game/state_overland.cpp game/state_sea.cpp \
  monsters/MonsterXp.cpp \
  spelleffects/spelleffects.cpp \
    rules/dmg/armorshield.cpp rules/dmg/assassinate.cpp rules/dmg/conduct.cpp rules/dmg/construct.cpp rules/dmg/disease.cpp \
    rules/dmg/dmg_appendices_klm.cpp rules/dmg/doorforce.cpp rules/dmg/energydrain.cpp rules/dmg/followers.cpp rules/dmg/grenade.cpp \
    rules/dmg/herbs.cpp rules/dmg/hirecost.cpp rules/dmg/hirelings.cpp rules/dmg/hoard.cpp rules/dmg/humanoid_preferences.cpp \
    rules/dmg/insanity.cpp rules/dmg/itemsavethrow.cpp rules/dmg/locktime.cpp rules/dmg/magic_research.cpp rules/dmg/miscibility.cpp \
    rules/dmg/misc_magic/miscmagic_alchemy_jug_to_bag_of_devouring.cpp rules/dmg/misc_magic/miscmagic_bag_of_holding_to_book_of_exalted_deeds.cpp rules/dmg/misc_magic/miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.cpp rules/dmg/misc_magic/miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.cpp rules/dmg/misc_magic/miscmagic_candle_of_invocation_to_cloak_of_protection.cpp \
    rules/dmg/misc_magic/miscmagic_crystal_balls.cpp rules/dmg/misc_magic/miscmagic_cube_of_force_to_decanter_of_endless_water.cpp rules/dmg/misc_magic/miscmagic_deck_of_many_things.cpp rules/dmg/misc_magic/miscmagic_drums_of_deafening_to_eyes_of_petrification.cpp rules/dmg/misc_magic/miscmagic_figurines_of_wondrous_power.cpp \
    rules/dmg/misc_magic/miscmagic_flask_of_curses_to_girdle_of_giant_strength.cpp rules/dmg/misc_magic/miscmagic_helm_of_brilliance_to_horn_of_bubbles.cpp rules/dmg/misc_magic/miscmagic_horn_of_collapsing_to_incense_of_meditation.cpp rules/dmg/misc_magic/miscmagic_incense_of_obsession_to_fochlucan_bandore.cpp rules/dmg/misc_magic/miscmagic_iron_flask_to_keoghtoms_ointment.cpp \
    rules/dmg/misc_magic/miscmagic_librams_lyre_and_manuals.cpp rules/dmg/misc_magic/miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.cpp rules/dmg/misc_magic/miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.cpp rules/dmg/misc_magic/miscmagic_necklace_of_prayer_beads_to_periapts.cpp rules/dmg/misc_magic/miscmagic_phylactery_of_faithfulness_to_feather_token.cpp \
    rules/dmg/misc_magic/miscmagic_robes.cpp rules/dmg/misc_magic/miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.cpp rules/dmg/misc_magic/miscmagic_sphere_of_annihilation_to_wings_of_flying.cpp rules/dmg/misc_magic/miscmagic_table1_footnotes.cpp rules/dmg/misc_magic/miscmagic_table2_footnotes.cpp \
    rules/dmg/misc_magic/miscmagic_table3_footnotes.cpp rules/dmg/misc_magic/miscmagic_table4_footnotes.cpp rules/dmg/misc_magic/miscmagic_table5_footnotes.cpp rules/dmg/mweapons.cpp rules/dmg/npcbody.cpp \
    rules/dmg/npcpersonae.cpp rules/dmg/npctraits.cpp rules/dmg/poison.cpp rules/dmg/potions.cpp rules/dmg/potions_conventions_animal_control_to_extra_healing.cpp \
    rules/dmg/potions_fire_resistance_to_invisibility.cpp rules/dmg/potions_invulnerability_to_water_breathing.cpp rules/dmg/pursuit.cpp rules/dmg/rings.cpp rules/dmg/rings_feather_falling_to_shooting_stars.cpp \
    rules/dmg/rings_mechanics_contrariness_to_elemental_command.cpp rules/dmg/rings_spell_storing_to_x_ray_vision.cpp rules/dmg/rods_absorption_to_smiting.cpp rules/dmg/rodswands.cpp rules/dmg/sage.cpp \
    rules/dmg/scroll_manufacture.cpp rules/dmg/scrollpins.cpp rules/dmg/scrolls_mechanics_protection_demons_to_undead.cpp rules/dmg/secondary.cpp rules/dmg/set_spear.cpp \
    rules/dmg/siegefire.cpp rules/dmg/socialrank.cpp rules/dmg/specart.cpp rules/dmg/specart_axe_of_the_dwarvish_lords_to_codex.cpp rules/dmg/specart_notes_on_artifacts_and_relics.cpp \
    rules/dmg/spying.cpp rules/dmg/staves_command_to_withering.cpp rules/dmg/subdue.cpp rules/dmg/swimcross.cpp rules/dmg/swords.cpp \
    rules/dmg/taxation.cpp rules/dmg/treasure_determination.cpp rules/dmg/twoweapon.cpp rules/dmg/uwfight.cpp rules/dmg/uwspells.cpp \
    rules/dmg/wands_conventions_conjuration_to_fear.cpp rules/dmg/wands_illumination_to_secret_door_and_trap_location.cpp rules/dmg/weaponless.cpp rules/dmg/weaponspeed.cpp rules/dmg/wonder.cpp \
  regtest.cpp \
  -o regtest -L"$PREFIX/lib" -llua5.4 2>"$warnfile" \
  && ./regtest | tee "$batfile" | grep -v 'audit: bad 0$'; then
  [ "${PIPESTATUS[0]}" = 0 ] || fail=1
else
  fail=1
fi
if [ -s "$warnfile" ]; then
  echo "WARN FAIL: the battery build emitted warnings (the R515 warning-clean rule):"
  cat "$warnfile"
  fail=1
else
  echo "BUILD: 0 warnings (the R515 warning gate)"
fi
rm -f "$warnfile"

echo "== [3/5] battery audit census (R112c) =="
# Every audit printf pattern is read FROM regtest.cpp itself,
# so the gate is self-maintaining: a round's new audit is
# covered the moment its printf lands in regtest.cpp. The
# pattern is the printf text up to (not including) the %d,
# so it prefixes the printed line whatever the count is.
# Each pattern must appear EXACTLY ONCE in the battery output
# (a double-inserted audit block ends RED here - the R112b
# lesson) and no audit may report a nonzero bad count.
# R822: the patterns are read from regtest.cpp PLUS
# the audit fragments (rules/audits/*.h) - a block
# that rides a fragment still prints its label, and
# the census covers it exactly as before.
census_fail=0
if [ ! -f "$batfile" ]; then
  echo "CENSUS FAIL: no battery output (build failed?)"
  census_fail=1
fi
while IFS= read -r pat; do
  [ -n "$pat" ] || continue
  n=$(grep -cF "$pat" "$batfile")
  [ -n "$n" ] || n=0
  if [ "$n" -ne 1 ]; then
    echo "CENSUS FAIL: '$pat' appears $n times (expected exactly once)"
    census_fail=1
  fi
done <<R112C_PATS
$( (grep 'printf("' regtest.cpp; grep -h 'printf("' rules/audits/*.h 2>/dev/null) | grep -oE '[^"]*audit: bad %d' | sed 's/%d$//' | sort -u)
R112C_PATS
if grep -qE 'audit: bad [1-9]' "$batfile" 2>/dev/null; then
  echo "CENSUS FAIL: an audit reported a nonzero bad count:"
  grep -E 'audit: bad [1-9]' "$batfile"
  census_fail=1
fi
naudits=$(grep -cE 'audit: bad ' "$batfile" 2>/dev/null)
[ -n "$naudits" ] || naudits=0
if [ "$census_fail" = 0 ]; then
  echo "AUDIT CENSUS: $naudits audit lines, each exactly once, all bad 0"
else
  fail=1
fi
rm -f "$batfile"

echo "== [4/5] working tree hygiene =="
# R84: auto-clean - bytecode is always regenerable, so the gate
# removes it instead of failing (it rode into a commit once, R80;
# the FAIL taxed every splice round since)
if [ -d tools/__pycache__ ]; then
  rm -rf tools/__pycache__
  echo "NOTE: removed tools/__pycache__ (auto-clean)"
else
  echo "OK: no __pycache__"
fi
if git status --porcelain | grep -q '^??'; then
  echo "NOTE: untracked files exist:"; git status --porcelain | grep '^??'
  echo "     (not a failure - confirm they belong in this commit)"
  # R112c: untracked file(s) plus NO tracked modification is the
  # shape of a splice that never ran (commit 7a86ee7 pushed a
  # truncated splice with nothing else). Run the splice twice,
  # or delete the script if abandoning the round.
  if git diff --quiet && git diff --cached --quiet; then
    # R207c: the tool-only round shape - every untracked
    # file a plain tools/*.py, never a splice script, with
    # no tracked modification - is a tool delivery, not
    # the 7a86ee7 never-ran-splice shape
    tools_only=1
    for f in $(git status --porcelain | grep '^??' | cut -c4-); do
      case "$f" in
        tools/*.py)
          case "$f" in *splice*) tools_only=0 ;; esac
          ;;
        *) tools_only=0 ;;
      esac
    done
    if [ "$tools_only" = 1 ]; then
      echo "NOTE: tool-only round (R207c) - no splice expected, new tool(s) belong in this commit"
    else
      echo "HYGIENE FAIL: untracked file(s) present but NO tracked file modified"
      echo "  - did the splice run? (the 7a86ee7 lesson)"
      fail=1
    fi
  fi
fi

echo "== [5/5] branch check =="
branch=$(git rev-parse --abbrev-ref HEAD)
echo "on branch: $branch"
if [ "$branch" = "main" ]; then
  echo "NOTE: committing straight to main (Termux-gated convention)"
fi

if [ "$fail" = 0 ]; then
  echo "PREFLIGHT: GREEN - safe to commit and push"
else
  echo "PREFLIGHT: RED - fix the failures above before any git add/commit/push"
fi
exit $fail
