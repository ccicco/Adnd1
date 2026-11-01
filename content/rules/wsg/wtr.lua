-- wtr: promoted from tools/spec_r480.json (the R480: the WSG INJURIES AND TREATMENT slice, printed p. 70 - the tenth camping-arc round, a pure prose round with NO table: the five specific injuries and their treatments - broken bone, minor burn, major burn, major wound and minor wound - with the general first-aid frame (the skills are common knowledge, useful only when the DM rules with proper reason that a specific injury was suffered).);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 480,
  "prefix" = "wtr",
  "banner" = {
      "title" = "R480: the WSG INJURIES AND TREATMENT slice, printed p. 70 - the tenth camping-arc round, a pure prose round with NO table: the five specific injuries and their treatments - broken bone, minor burn, major burn, major wound and minor wound - with the general first-aid frame (the skills are common knowledge, useful only when the DM rules with proper reason that a specific injury was suffered).",
      "provenance" = "The settle: the injuries section lives on the same printed p. 70 already settled for R479 - the tesseract full-text read and the pdfy layout read agree on every number of the section (the tesseract tsv even confirms the dice formulas and ranges cell by cell), so no contested cells and no vision reads were needed. The dice formulas are pinned as dice-plus-modifier consts with the printed ranges as cross-checks: 2-4 as 1d3+1, 2-7 as 1d6+1, the immediate 1d6 and the 1d4 per round.",
      "sentinel" = "Bounds held: the major burn pain penalty is exactly three times the minor one; both the bleeding and the pressure ranges match their dice-plus-modifier formulas; the artery trigger sits at an unmodified damage roll of 6 or higher with a 25% chance.",
    },
  "consts" = { {
      "name" = "wtrInjuryTypeCount",
      "value" = 5,
      "comment" = "five specific injuries: broken bone, minor burn, major burn, major wound, minor wound",
    }, {
      "name" = "wtrBurnImmerseMinTurns",
      "value" = 2,
      "comment" = "immerse the burned area in water for at least two turns",
    }, {
      "name" = "wtrHealPerDay",
      "value" = 1,
      "comment" = "a protected burn heals at the normal rate of 1 hit point per day",
    }, {
      "name" = "wtrMinorPainPenalty",
      "value" = 1,
      "comment" = "an unprotected minor burn: a -1 penalty on all attack rolls and saving throws",
    }, {
      "name" = "wtrMajorPainPenalty",
      "value" = 3,
      "comment" = "a major burn: the pain penalty is -3 instead of -1 on all attack rolls and saving throws",
    }, {
      "name" = "wtrHalfNum",
      "value" = 1,
      "comment" = "the half fraction: one-half of the body, of the lost points",
    }, {
      "name" = "wtrHalfDen",
      "value" = 2,
      "comment" = "both the major-burn body bar and the rest bar use one-half",
    }, {
      "name" = "wtrMajorActivityDice",
      "value" = 1,
      "comment" = "a major burn victim active before recovery takes 1d4 per round",
    }, {
      "name" = "wtrMajorActivitySides",
      "value" = 4,
      "comment" = "the additional damage per round of voluntary activity is 1d4",
    }, {
      "name" = "wtrSplintUseDice",
      "value" = 1,
      "comment" = "using the splinted injured extremity costs an immediate 1d6",
    }, {
      "name" = "wtrSplintUseSides",
      "value" = 6,
      "comment" = "the immediate extra damage for using the injured extremity",
    }, {
      "name" = "wtrArteryMinDamage",
      "value" = 6,
      "comment" = "the major wound trigger: an unmodified damage roll of 6 or higher from an edged melee weapon",
    }, {
      "name" = "wtrArteryChance",
      "value" = 25,
      "comment" = "the DM may rule the artery strike on a 25% chance",
    }, {
      "name" = "wtrBleedMin",
      "value" = 2,
      "comment" = "the severe bleeding loses an additional 2-4 hit points per round",
    }, {
      "name" = "wtrBleedMax",
      "value" = 4,
      "comment" = "the top of the severe bleeding range",
    }, {
      "name" = "wtrBleedDice",
      "value" = 1,
      "comment" = "the severe bleeding is 1d3 + 1 hit points per round",
    }, {
      "name" = "wtrBleedSides",
      "value" = 3,
      "comment" = "the die of the severe bleeding formula",
    }, {
      "name" = "wtrBleedPlus",
      "value" = 1,
      "comment" = "the modifier of the severe bleeding formula",
    }, {
      "name" = "wtrPressureMin",
      "value" = 2,
      "comment" = "direct pressure must be applied for 2-7 consecutive rounds",
    }, {
      "name" = "wtrPressureMax",
      "value" = 7,
      "comment" = "the top of the pressure duration range",
    }, {
      "name" = "wtrPressureDice",
      "value" = 1,
      "comment" = "the pressure duration is 1d6 + 1 rounds",
    }, {
      "name" = "wtrPressureSides",
      "value" = 6,
      "comment" = "the die of the pressure duration formula",
    }, {
      "name" = "wtrPressurePlus",
      "value" = 1,
      "comment" = "the modifier of the pressure duration formula",
    }, {
      "name" = "wtrPressureHpLoss",
      "value" = 1,
      "comment" = "while the pressure is applied the victim loses 1 hit point per round until the time has passed",
    } },
  "bools" = { {
      "name" = "wtrFirstAidCommonKnowledge",
      "value" = true,
      "comment" = "the general first-aid skills are common knowledge among most adventurers, usable by anyone with the time and materials",
    }, {
      "name" = "wtrDmRulesSpecificInjury",
      "value" = true,
      "comment" = "the skills are only useful if the DM rules with proper reason that a specific injury was suffered",
    }, {
      "name" = "wtrSplintAlignsBone",
      "value" = true,
      "comment" = "putting a splint on the injury keeps the ends of the broken bone properly aligned and makes healing possible",
    }, {
      "name" = "wtrSplintRequiredToHeal",
      "value" = true,
      "comment" = "no hit points lost to a broken bone in an extremity are regained until the character is fitted with a splint",
    }, {
      "name" = "wtrSplintUseExtraDamage",
      "value" = true,
      "comment" = "attempting to use the injured extremity even while splinted immediately costs the extra damage",
    }, {
      "name" = "wtrSplintUseNeutralizesHealing",
      "value" = true,
      "comment" = "the use also neutralizes any healing of the bone up to that time",
    }, {
      "name" = "wtrBrokenBoneHealsLast",
      "value" = true,
      "comment" = "for a character with several injuries the broken bone is the last injury for which hit points are regained",
    }, {
      "name" = "wtrBurnAirDeprivedHeals",
      "value" = true,
      "comment" = "depriving the burned area of air - immersion in water or a tight clean-cloth wrapping - lets the burn heal at the normal rate",
    }, {
      "name" = "wtrMinorBurnHalfHealUnprotected",
      "value" = true,
      "comment" = "an unprotected minor burn heals only half as fast as normal",
    }, {
      "name" = "wtrMajorBurnRestRequired",
      "value" = true,
      "comment" = "a major burn victim must rest until he has regained at least half of the hit points lost due to the burn",
    }, {
      "name" = "wtrMajorBurnForfeitRegained",
      "value" = true,
      "comment" = "voluntary activity before recovery forfeits every hit point regained up to that point",
    }, {
      "name" = "wtrMajorBurnCanBeCarried",
      "value" = true,
      "comment" = "a major burn victim can usually still ride a mount or be carried by a comrade or on a stretcher",
    }, {
      "name" = "wtrMajorWoundEdgedOnly",
      "value" = true,
      "comment" = "the major wound comes only from an edged melee weapon",
    }, {
      "name" = "wtrMajorWoundDmDiscretion",
      "value" = true,
      "comment" = "the artery strike is ruled at the DM discretion or on the 25% chance",
    }, {
      "name" = "wtrBleedingStemmedByPressure",
      "value" = true,
      "comment" = "a comrade or the victim himself - if the wound is in an accessible place - stems the bleeding by applying pressure directly to the wound",
    }, {
      "name" = "wtrWrappingHaltsButNeedsHealer",
      "value" = true,
      "comment" = "wrapping the wound tightly halts the bleeding, but recovering the lost hit points needs the pressure procedure performed by a character with proficiency in healing",
    }, {
      "name" = "wtrPressureReleaseNegates",
      "value" = true,
      "comment" = "releasing the pressure before the required time negates the first aid and the bleeding begins again",
    }, {
      "name" = "wtrDmMayRerollPressure",
      "value" = true,
      "comment" = "for the renewed pressure the DM can use the original result or roll again for added randomness",
    }, {
      "name" = "wtrMinorWoundBandageAssumed",
      "value" = true,
      "comment" = "any wound that breaks the skin is assumed bandaged at the first available opportunity",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the five injuries, and the major burn bar: more than half the body, rest until half the points",
      "expr" = "m['wtrInjuryTypeCount']() != 5 or m['wtrHalfDen']() != 2 * m['wtrHalfNum']()",
    }, {
      "note" = "the severe bleeding: 2-4 hit points per round as 1d3 + 1",
      "expr" = "m['wtrBleedDice']() + m['wtrBleedPlus']() != m['wtrBleedMin']() or m['wtrBleedSides']() + m['wtrBleedPlus']() != m['wtrBleedMax']()",
    }, {
      "note" = "the pressure duration: 2-7 consecutive rounds as 1d6 + 1",
      "expr" = "m['wtrPressureDice']() + m['wtrPressurePlus']() != m['wtrPressureMin']() or m['wtrPressureSides']() + m['wtrPressurePlus']() != m['wtrPressureMax']()",
    }, {
      "note" = "the pain penalties: the major burn is -3, exactly three times the minor -1",
      "expr" = "m['wtrMajorPainPenalty']() != 3 * m['wtrMinorPainPenalty']() or m['wtrMinorPainPenalty']() != 1",
    }, {
      "note" = "the artery trigger: an unmodified damage roll of 6 or higher, on a 25% chance",
      "expr" = "m['wtrArteryMinDamage']() != 6 or m['wtrArteryChance']() != 25",
    }, {
      "note" = "the treatment clocks: two turns of immersion, 1 point per day of healing, 1 point lost per round of applied pressure, the 1d6 and the 1d4",
      "expr" = "m['wtrBurnImmerseMinTurns']() != 2 or m['wtrHealPerDay']() != 1 or m['wtrPressureHpLoss']() != 1 or m['wtrSplintUseDice']() != 1 or m['wtrSplintUseSides']() != 6 or m['wtrMajorActivityDice']() != 1 or m['wtrMajorActivitySides']() != 4",
    } },
  "audit" = {
      "label" = "R480 WSG injuries treatment pin audit",
      "comment" = "The injuries and treatment rules: the broken bone (the splint aligns the ends and makes healing possible, no hit points regained until splinted, using the injured extremity even while splinted costs an immediate 1d6 and neutralizes all healing to that time, the broken bone heals last, most other injuries heal before it is mended), the minor burn (deprive the area of air by immersing in water for at least two turns or wrapping tightly with a clean cloth for normal 1-per-day healing, otherwise a -1 pain penalty on attacks and saves and healing at half speed), the major burn (more than half the body burned, treated as above plus rest until at least half the lost hit points are regained, voluntary activity forfeits all regained points and costs 1d4 per round, the pain penalty is -3 instead of -1, the victim can still ride or be carried), the major wound (an edged melee weapon with an unmodified damage roll of 6 or higher, at the DM discretion or on a 25% chance an artery struck, 2-4 as 1d3+1 hit points per round of severe bleeding until tended, pressure applied directly for 2-7 consecutive rounds as 1d6+1 at 1 hit point lost per round meanwhile, wrapping halts the bleeding but recovery needs a healer with the healing proficiency, releasing the pressure early negates the first aid and the bleeding begins again for another 2-7 rounds with the DM free to use the original result or roll again), and the minor wound (any skin-breaking wound is assumed bandaged at the first available opportunity).",
    },
}
