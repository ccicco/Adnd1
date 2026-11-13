-- misc magic item def: instrument_of_the_bards
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part14.h (R270)
--   boneyard/dmg/miscmagic_prose_part15.h (R271)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "instrument_of_the_bards",
  name = "Instrument of the Bards",
  rows = {
    { name = "Instrument of the Bards",
      set = "kMisc3", band = { 73, 78 }, xp = 1000, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 14, round = 270 },
    { part = 15, round = 271 },
  },
  pins = {
    { name = "bardInstrumentCount", value = 7,
      comment = "there are 7 magical instruments" },
    { name = "instrumentAbilityCount", value = 4,
      comment = "four abilities: protection from evil, invisibility, "
      .. "levitate, fly" },
    { name = "instrumentAbilityRadiusFeet", value = 10,
      comment = "the protection from evil in a 10 feet radius" },
    { name = "instrumentAbilityPerDay", value = 1,
      comment = "each ability once per day" },
    { name = "instrumentActivateSegments", value = 5,
      comment = "each ability takes 5 segments to activate" },
    { name = "instrumentCompleteRounds", value = 1,
      comment = "and not less than 1 full round to complete" },
    { name = "instrumentCollegeTurnsMin", value = 1,
      comment = "the abilities last as many turns as the college "
      .. "order, the low edge of 1-7" },
    { name = "instrumentCollegeTurnsMax", value = 7,
      comment = "the high edge of the college order turns" },
    { name = "instrumentMagnusTurns", value = 8,
      comment = "a magnus alumni sings for 8 turns with any of the 7" },
    { name = "instrumentCharmExcessThresholdPct", value = 100,
      comment = "when the charming ability exceeds 100 percent with "
      .. "the instrument bonus" },
    { name = "instrumentCharmExcessStepPct", value = 5,
      comment = "the saving throw penalty per every 5 percent above, "
      .. "3-4 rounding to the next 5" },
    { name = "instrumentCharmExcessPenaltyPerStep", value = 1,
      comment = "the creature saves at -1 for every step above 100 "
      .. "percent" },
    { name = "instrumentKindRowCount", value = 7,
      comment = "the type table has 7 rows" },
  },
  tables = {
    { name = "instrumentDieLo",
      comment = "the type die band lower edges; i clamps",
      clamp_hi = 6,
      values = {
        1, 6, 10, 13, 16, 18, 20,
      } },
    { name = "instrumentDieHi",
      comment = "the type die band upper edges; i clamps",
      clamp_hi = 6,
      values = {
        5, 9, 12, 15, 17, 19, 20,
      } },
  },
  subs = {
    {
      key = "anstruth_harp",
      name = "Anstruth Harp",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "anstruthMisusePct", value = 90,
          comment = "90 percent likely, any non-bard or bard of less "
          .. "than 17th level" },
        { name = "anstruthDamageMin", value = 8,
          comment = "the misuse causes 8-32 hit points" },
        { name = "anstruthDamageMax", value = 32,
          comment = "the upper edge of the 8-32 damage" },
        { name = "anstruthLevelGate", value = 17,
          comment = "a 17th or higher level bard strums it" },
        { name = "anstruthCharmBonusPct", value = 35,
          comment = "adds 35 percent to charming abilities" },
        { name = "anstruthSongCount", value = 3,
          comment = "three spells, one each per day" },
      },
      tables = {
      },
    },
    {
      key = "canaith_mandolin",
      name = "Canaith Mandolin",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "canaithMisusePct", value = 70,
          comment = "70 percent likely, any non-bard or bard under the "
          .. "11th level" },
        { name = "canaithDamageMin", value = 5,
          comment = "the misuse causes 5-20 hit points" },
        { name = "canaithDamageMax", value = 20,
          comment = "the upper edge of the 5-20 damage" },
        { name = "canaithLevelGate", value = 11,
          comment = "an 11th or higher level bard employs it" },
        { name = "canaithCharmBonusPct", value = 25,
          comment = "adds 25 percent to the charming ability" },
        { name = "canaithSongCount", value = 3,
          comment = "three spells once per day" },
        { name = "canaithProtLightningRadiusFeet", value = 10,
          comment = "the protection from lightning song in a 10 feet "
          .. "radius" },
      },
      tables = {
      },
    },
    {
      key = "cli_lyre",
      name = "Cli Lyre",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "cliMisusePct", value = 80,
          comment = "80 percent likely, any non-bard or bard of less "
          .. "than the 14th level" },
        { name = "cliDamageMin", value = 6,
          comment = "the misuse causes 6-24 hit points" },
        { name = "cliDamageMax", value = 24,
          comment = "the upper edge of the 6-24 damage" },
        { name = "cliLevelGate", value = 14,
          comment = "a 14th or higher level bard plays the lyre" },
        { name = "cliCharmBonusPct", value = 30,
          comment = "adds 30 percent to charming ability" },
        { name = "cliSongCount", value = 3,
          comment = "three songs once each per day" },
      },
      tables = {
      },
    },
    {
      key = "doss_lute",
      name = "Doss Lute",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "dossMisusePct", value = 60,
          comment = "60 percent likely, any non-bard or bard under 8th "
          .. "level" },
        { name = "dossDamageMin", value = 4,
          comment = "the misuse delivers 4-16 hit points" },
        { name = "dossDamageMax", value = 16,
          comment = "the upper edge of the 4-16 damage" },
        { name = "dossLevelGate", value = 8,
          comment = "an 8th or higher level bard plays the lute" },
        { name = "dossCharmBonusPct", value = 20,
          comment = "a 20 percent better chance of charming" },
        { name = "dossSongCount", value = 3,
          comment = "three magical songs once per day" },
        { name = "dossProtFireRadiusFeet", value = 10,
          comment = "the protection from fire song in a 10 feet radius" },
      },
      tables = {
      },
    },
    {
      key = "fochlucan_bandore",
      name = "Fochlucan Bandore",
      sources = {
        { part = 14, round = 270 },
      },
      pins = {
        { name = "fochlucanStringCount", value = 3,
          comment = "the small, 3-stringed bandore" },
        { name = "fochlucanLowestFaeriePct", value = 50,
          comment = "a 1st level bard or a non-bard: a 50 percent "
          .. "chance per round of playing to cast a faerie fire "
          .. "spell" },
        { name = "fochlucanLowestReversePct", value = 10,
          comment = "a 10 percent chance the musician is limned by the "
          .. "glow instead" },
        { name = "fochlucanFaerieBasePct", value = 50,
          comment = "a bard of Fochlucan or higher college casts the "
          .. "faerie fire at base 50 percent" },
        { name = "fochlucanReverseReductionPerLevelPct", value = 1,
          comment = "the reverse effect reduced by 1 percent per level "
          .. "above 1st" },
        { name = "fochlucanSongCount", value = 4,
          comment = "the bandore has 4 song properties when properly "
          .. "played" },
        { name = "fochlucanCharmBonusPct", value = 10,
          comment = "adds 10 percent to the bard charm percentage" },
        { name = "fochlucanEntanglePerDay", value = 1,
          comment = "casts an entangle spell once per day" },
        { name = "fochlucanShillelaghPerDay", value = 1,
          comment = "casts a shillelagh spell once per day" },
        { name = "fochlucanSpeakAnimalsPerDay", value = 1,
          comment = "enables the bard to speak with animals once per "
          .. "day" },
        { name = "fochlucanLowestSongWorkPct", value = 30,
          comment = "a 1st level bard attempts the powers: a 30 "
          .. "percent chance they work" },
        { name = "fochlucanLowestSongFailPct", value = 70,
          comment = "a 70 percent chance of the mishap" },
        { name = "fochlucanLowestFailDamageMin", value = 2,
          comment = "the mishap deals 2-8 hit points of damage" },
        { name = "fochlucanLowestFailDamageMax", value = 8,
          comment = "the upper edge of the 2-8 damage" },
      },
      tables = {
      },
    },
    {
      key = "mac_fuirmidh_cittern",
      name = "Mac-Fuirmidh Cittern",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "citternMisusePct", value = 50,
          comment = "50 percent likely to deliver the damage to any "
          .. "non-bard or bard under 5th level" },
        { name = "citternDamageMin", value = 3,
          comment = "the misuse delivers 3-12 hit points" },
        { name = "citternDamageMax", value = 12,
          comment = "the upper edge of the 3-12 damage" },
        { name = "citternLevelGate", value = 5,
          comment = "a bard of 5th or higher level uses it safely" },
        { name = "citternCharmBonusPct", value = 15,
          comment = "a 15 percent better chance of charming" },
        { name = "citternSongCount", value = 3,
          comment = "three songs once per day" },
      },
      tables = {
      },
    },
    {
      key = "ollamh_harp",
      name = "Ollamh Harp",
      sources = {
        { part = 15, round = 271 },
      },
      pins = {
        { name = "ollamhDamageMin", value = 10,
          comment = "a non-bard or bard under 20th level: it WILL "
          .. "inflict 10-40 hit points (no percent printed, the "
          .. "harm is certain)" },
        { name = "ollamhDamageMax", value = 40,
          comment = "the upper edge of the certain 10-40 damage" },
        { name = "ollamhLevelGate", value = 20,
          comment = "a bard of 20th or higher level plays it" },
        { name = "ollamhCharmBonusPct", value = 40,
          comment = "adds 40 percent to the charming abilities" },
        { name = "ollamhSongCount", value = 3,
          comment = "three spells, one each daily" },
      },
      tables = {
      },
    },
  },
}
