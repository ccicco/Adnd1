-- wrm: promoted from tools/spec_r905.json (the The witch remainders and the Friedman elf sub-race table - the might-be-usable micro-round: the familiars, the unpinned witch items, the Group B effect details and the editorially endorsed elf d20 table (Dragon #5));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 905,
  "prefix" = "wrm",
  "banner" = {
      "title" = "The witch remainders and the Friedman elf sub-race table - the might-be-usable micro-round: the familiars, the unpinned witch items, the Group B effect details and the editorially endorsed elf d20 table (Dragon #5)",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 5 (March 1977), the archive.org scan voice (the upload cross-check reached page 5 only; pages 6-32 remain single-voice, and this round's ink sits at folios 4-9, 28 - all single-voice pages; the R902 provenance stands). The witch remainders, adjudicated might-be-usable at the 2026-10-29 issue-5 ledger review: the witch familiar die (1,2 basilisk; 3 wyvern; 4 warlock with ring and wand; 5,6 one undead, no vampires, the familiars cooperating over the whole circle, the good witch exempt); the unpinned items - the Assassin's Eyes at 12 inches per turn invisible and immaterial with the one-turn kill window and the Charm or Death Ray, the Leech Dust ladder (weak at two turns, paralyzed at three, dead at four, plate armor buying two, holy water the only cure), the Mountain Seeds' castle swell, the Witch Wand's 30-foot ESP and lycanthrope/undead/elemental shield, the three-wand canon, the Ivy Bracelet, the Locket of Satan at 7 inches over 3 chaotic creatures with the two-turn 15-percent corruption, the Snake Belt at 3 feet, 6 per turn, 1 die, the Skull of Death's repeatable Finger of Death and Animate Dead, the Luck Charm remainder (the 70-percent wish, the two limited weekly, the 10-percent lair bonus, the 20/50 per-category enhancement at 75 percent), the Potion Cauldron's one-duplicate-per-hour and the Treasure-Finding blood-pledge doctrine; the spell effect details - the 12-hit-dice delayed elemental, the 50-foot Wither, the Weight spell's 1-10 targets at triple or one-third, the Volcanic Circle at 4 feet per turn behind a 10-foot line for 10 dice, the two-turn Reflections with its Banish/Disintegrate exceptions, the Solidify true-matter doctrine, the Undead Control over 1-6 with the crystal-ball range, the Curse's 75-percent silver enclosure and no-immediate-death law, the Poison Touch's 3 objects and two-turn contact death, the Curtain Wall's 10-by-20 room behind the two-control-agent bar, the Fire Box's 10-foot cube, the Diminish halving ladder, and the 25-foot Circle of Blindness. The Friedman elf sub-race table, adjudicated might-be-usable at the same review: the Out On A Limb letter proposing a 20-sided die for elf sub-races - 1-16 Silvan, 17-19 Sindar, 20 Noldor - editorially endorsed in print.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and this round is pure remainder bookkeeping over the already-adjudicated R902 chains - no new registry defs, no transcripts, no gap flips, the report 005 state verified untouched at 1 closed / 0 open. The Friedman table carries its honest boundary as a pinned bool: Silvan, Sindar and Noldor are Tolkien's names, echoed in D&D's Wood, Grey and High elf convention - the pin rides the variant layer with provenance, never a core rewrite, and the editorial endorsement is pinned as the provenance fact it is. No duplicate ink: every const here was unpinned at R902/R904 (the spell matrix carried the R/D cells only; the quotas, the lair lines and the wilderness table were pinned there and are not repeated).",
    },
  "consts" = { {
      "name" = "wrmFamiliarBasiliskMin",
      "value" = 1,
      "comment" = "the witch familiar die, the basilisk band minimum - 1 on a six-sided die (folio 8)",
    }, {
      "name" = "wrmFamiliarBasiliskMax",
      "value" = 2,
      "comment" = "the basilisk band maximum - 2 (folio 8)",
    }, {
      "name" = "wrmFamiliarWyvernRoll",
      "value" = 3,
      "comment" = "the wyvern familiar - 3 (folio 8)",
    }, {
      "name" = "wrmFamiliarWarlockRoll",
      "value" = 4,
      "comment" = "the warlock familiar with one ring and one wand - 4 (folio 8)",
    }, {
      "name" = "wrmFamiliarUndeadMin",
      "value" = 5,
      "comment" = "the undead familiar band minimum - 5 (folio 8)",
    }, {
      "name" = "wrmFamiliarUndeadMax",
      "value" = 6,
      "comment" = "the undead familiar band maximum - 6 (folio 8)",
    }, {
      "name" = "wrmAssassinEyesSpeed",
      "value" = 12,
      "comment" = "the Assassin's Eyes flight - 12 inches per turn (folio 7)",
    }, {
      "name" = "wrmAssassinEyesVictimTurns",
      "value" = 1,
      "comment" = "the Assassin's Eyes - the failed-spell victim has one turn to kill them before they turn immaterial and return (folio 7)",
    }, {
      "name" = "wrmLeechDustRange",
      "value" = 2,
      "comment" = "the Leech Dust throw - up to 2 inches, forming a cloud the dimensions of Cloudkill (folio 7)",
    }, {
      "name" = "wrmLeechDustUnableTurns",
      "value" = 2,
      "comment" = "the Leech Dust - in two turns the victim is unable to fight or use spells (folio 7)",
    }, {
      "name" = "wrmLeechDustParalyzeTurns",
      "value" = 3,
      "comment" = "the Leech Dust - paralyzed at three turns (folio 7)",
    }, {
      "name" = "wrmLeechDustDeathTurns",
      "value" = 4,
      "comment" = "the Leech Dust - dead at four turns (folio 7)",
    }, {
      "name" = "wrmLeechDustPlateBonusTurns",
      "value" = 2,
      "comment" = "wearing plate armor in the dust cloud prolongs death two turns (folio 7)",
    }, {
      "name" = "wrmWandEspRange",
      "value" = 30,
      "comment" = "the Witch Wand also acts as a 30-foot ESP medallion (folio 8)",
    }, {
      "name" = "wrmLocketSatanRange",
      "value" = 7,
      "comment" = "the Locket of Satan - commands any 3 chaotic creatures within the 7-inch range, no saving throws (folio 9)",
    }, {
      "name" = "wrmLocketSatanCommandMax",
      "value" = 3,
      "comment" = "the Locket of Satan commands up to 3 chaotic creatures regardless of intervening substances (folio 9)",
    }, {
      "name" = "wrmLocketSatanCorruptTurns",
      "value" = 2,
      "comment" = "the Locket of Satan - two turns of concentrated power against a lawful character (folio 9)",
    }, {
      "name" = "wrmLocketSatanCorruptPct",
      "value" = 15,
      "comment" = "the Locket of Satan - a 15 percent chance the lawful victim turns permanently evil and corrupted (folio 9)",
    }, {
      "name" = "wrmSnakeBeltLengthFeet",
      "value" = 3,
      "comment" = "the Snake Belt - the snake staff in 3-foot belt form, usable by everyone (folio 9)",
    }, {
      "name" = "wrmSnakeBeltSpeed",
      "value" = 6,
      "comment" = "the Snake Belt crawls anywhere its owner mentally directs, at speeds up to 6 feet per turn (folio 9)",
    }, {
      "name" = "wrmSnakeBeltDamageDice",
      "value" = 1,
      "comment" = "the Snake Belt does 1 die of damage to any creature it strikes (folio 9)",
    }, {
      "name" = "wrmLuckCharmWishPct",
      "value" = 70,
      "comment" = "the Luck Charm category d - grants 1 wish (70 percent chance) or 2 wishes of limited power per week (folio 28)",
    }, {
      "name" = "wrmLuckCharmLimitedWishes",
      "value" = 2,
      "comment" = "the Luck Charm - 2 wishes of limited power per week when not the single wish (folio 28)",
    }, {
      "name" = "wrmLuckCharmLairBonusPct",
      "value" = 10,
      "comment" = "the Luck Charm category e - increases the chance of finding an opponent's lair by 10 percent (folio 28)",
    }, {
      "name" = "wrmLuckCharmTreasure20Pct",
      "value" = 75,
      "comment" = "the Luck Charm - if the lair is found, each treasure category's presence chance enhances by 20 percent (75 percent chance of this) (folio 28)",
    }, {
      "name" = "wrmLuckCharmTreasureBonus20",
      "value" = 20,
      "comment" = "the Luck Charm - the 20-percent per-category enhancement (folio 28)",
    }, {
      "name" = "wrmLuckCharmTreasureBonus50",
      "value" = 50,
      "comment" = "the Luck Charm - the alternative 50-percent per-category enhancement (folio 28)",
    }, {
      "name" = "wrmPotionDupPerHour",
      "value" = 1,
      "comment" = "the Potion Cauldron duplicates an available potion at the rate of one duplicate per hour (folio 8)",
    }, {
      "name" = "wrmWitchElementalHd",
      "value" = 12,
      "comment" = "the witch's Summon Elemental - the elemental has 12 hit dice (folio 4)",
    }, {
      "name" = "wrmWitchElementalDelayTurns",
      "value" = 1,
      "comment" = "the elemental appears the turn after it has been summoned (folio 4)",
    }, {
      "name" = "wrmWitherCircleFeet",
      "value" = 50,
      "comment" = "the Wither - all living plants and creatures within a 50-foot diameter circle rapidly age and die (folio 7)",
    }, {
      "name" = "wrmWeightAffectedMin",
      "value" = 1,
      "comment" = "the Weight Concentration/Dilution - from 1 (folio 7)",
    }, {
      "name" = "wrmWeightAffectedMax",
      "value" = 10,
      "comment" = "the Weight Concentration/Dilution - up to 10 creatures or objects affected (folio 7)",
    }, {
      "name" = "wrmWeightFactor",
      "value" = 3,
      "comment" = "the witch may triple a target's weight or cut it to one-third, chosen per target (folio 7)",
    }, {
      "name" = "wrmVolcanicFlowFeet",
      "value" = 4,
      "comment" = "the Volcanic Circle - the lava flows outward from the witch at 4 feet per turn, the radius growing 4 feet per turn (folio 7)",
    }, {
      "name" = "wrmVolcanicLineFeet",
      "value" = 10,
      "comment" = "the Volcanic Circle - the line remains 10 feet thick as it expands, never thinning (folio 7)",
    }, {
      "name" = "wrmVolcanicDamageDice",
      "value" = 10,
      "comment" = "a ground creature caught and passed under by the molten rock takes 10 dice of damage unless immune to ordinary fire (folio 7)",
    }, {
      "name" = "wrmReflectionsTurns",
      "value" = 2,
      "comment" = "the Reflections - for two turns no magic can harm the witch, and any spell, potion or magic device used against her returns to the attacker regardless of range (folio 7)",
    }, {
      "name" = "wrmUndeadControlMin",
      "value" = 1,
      "comment" = "the Undead Control - from 1 undead character of any type (folio 5)",
    }, {
      "name" = "wrmUndeadControlMax",
      "value" = 6,
      "comment" = "the Undead Control - up to 6 undead characters of any type within the 10-inch radius (folio 5)",
    }, {
      "name" = "wrmCurseSilverPct",
      "value" = 75,
      "comment" = "the Curse - anything more than 75 percent enclosed by silver is safe; a silver helmet, shield and plate would protect, a single silver piece would not (folio 5)",
    }, {
      "name" = "wrmPoisonTouchObjects",
      "value" = 3,
      "comment" = "the Poison Touch - the first 3 objects handled by the witch are permanently contaminated, or a 4-by-4-foot flat surface (folio 5)",
    }, {
      "name" = "wrmPoisonTouchDeathAfterTurns",
      "value" = 2,
      "comment" = "the Poison Touch contamination - after two turns of contact the victim dies; gloves protect (folio 5)",
    }, {
      "name" = "wrmCurtainWidthFeet",
      "value" = 10,
      "comment" = "the Curtain Wall - a curtain 10 feet wide floats vertically just off the ground (folio 5)",
    }, {
      "name" = "wrmCurtainRoomDepthFeet",
      "value" = 20,
      "comment" = "the Curtain Wall room - 10 feet high and wide, 20 feet from back wall to front curtain (folio 5)",
    }, {
      "name" = "wrmFireBoxCubeFeet",
      "value" = 10,
      "comment" = "the Fire Box - a hollow 10-foot cube of fire forms about the target and remains six turns (folio 5)",
    }, {
      "name" = "wrmBlindnessRadiusFeet",
      "value" = 25,
      "comment" = "the Circle of Blindness - all creatures within 25 feet of the impact point are affected, a 50-foot circle (folio 5)",
    }, {
      "name" = "wrmElfSubraceCount",
      "value" = 3,
      "comment" = "the Friedman elf sub-race table row count - 3 rows: the Silvan, the Sindar and the Noldor (folio 14)",
    }, {
      "name" = "wrmElfTableDieSides",
      "value" = 20,
      "comment" = "the elf sub-race check - a 20-sided die, per the Friedman letter to Out On A Limb (folio 14)",
    } },
  "bools" = { {
      "name" = "wrmFamiliarNoVampires",
      "value" = true,
      "comment" = "the undead familiar is one undead character - no vampires (folio 8)",
    }, {
      "name" = "wrmFamiliarsCooperate",
      "value" = true,
      "comment" = "the individual familiars cooperate to protect the entire circle of witches, not just their own owner (folio 8)",
    }, {
      "name" = "wrmGoodWitchNoGuardFamiliar",
      "value" = true,
      "comment" = "good witches lack the posted-familiar guard defense - only the evil witches roll the familiar die (folio 8)",
    }, {
      "name" = "wrmAssassinEyesImmaterial",
      "value" = true,
      "comment" = "the Assassin's Eyes are normally invisible and immaterial, passing any solid barrier - visible only to attack, and vulnerable only then (folio 7)",
    }, {
      "name" = "wrmAssassinEyesCharmOrDeath",
      "value" = true,
      "comment" = "the Assassin's Eyes attack - a Charm Person spell or Death Ray, the victim allowed saving throws (folio 7)",
    }, {
      "name" = "wrmLeechDustHolyWaterOnly",
      "value" = true,
      "comment" = "the Leech Dust is removed only by a sprinkling of holy water; a victim freed before death needs a full week of rest (folio 7)",
    }, {
      "name" = "wrmMountainSeedCastleSize",
      "value" = true,
      "comment" = "the Mountain Seeds - like the Hill Seeds but much deadlier: swelling to the size of a castle almost immediately, crushing armies or destroying a town (folio 7)",
    }, {
      "name" = "wrmWandLycanthropeShield",
      "value" = true,
      "comment" = "the Witch Wand gives protection from normal missiles and shields the holder from lycanthropes, undead and elementals like scrolls (folio 8)",
    }, {
      "name" = "wrmWitchThreeWands",
      "value" = true,
      "comment" = "the only three wands a witch ever uses - the Illusion Wand, the Polymorph Wand and the Witch Wand (folio 9)",
    }, {
      "name" = "wrmIllusionWandRestricted",
      "value" = true,
      "comment" = "the Illusion Wand is usable only by witches and magic-users (folio 9)",
    }, {
      "name" = "wrmIvyBraceletPlantControl",
      "value" = true,
      "comment" = "the Ivy Bracelet - Plant Control as the potion until removed, and Speak with Plants as a Patriarch (folio 9)",
    }, {
      "name" = "wrmIvyBraceletFragile",
      "value" = true,
      "comment" = "the Ivy Bracelet - a fragile band of enchanted forest ivy, found only in forest coven hoards, destroyed by a firm wind or vigorous combat (folio 9)",
    }, {
      "name" = "wrmLocketSatanClericImmune",
      "value" = true,
      "comment" = "the Locket of Satan has no effect upon clerics, lawful or otherwise; found only with evil witches, usable by neutral and chaotic man-types (folio 9)",
    }, {
      "name" = "wrmSnakeBeltFireLightningOnly",
      "value" = true,
      "comment" = "the Snake Belt is killed only by fire and lightning; strong enough to strangle a wyvern (folio 9)",
    }, {
      "name" = "wrmSkullPowersRepeatable",
      "value" = true,
      "comment" = "the Skull of Death - the wearer also gains The Finger of Death and Animate Dead, both usable repeatedly (folio 7)",
    }, {
      "name" = "wrmPotionCauldronWitchesOnly",
      "value" = true,
      "comment" = "the Potion Cauldron is usable only by witches, producing any potion from the book-2 potion list in one game-day (folio 8)",
    }, {
      "name" = "wrmTreasureFindingDoctrine",
      "value" = true,
      "comment" = "the Treasure-Finding potion doctrine - witches sell it only if forced or offered half the treasure, against a blood pledge, a broken word bringing prompt cursing (folio 8)",
    }, {
      "name" = "wrmWitchElementalConcentration",
      "value" = true,
      "comment" = "the elemental vanishes if the witch loses her concentration (folio 4)",
    }, {
      "name" = "wrmReflectionsExceptions",
      "value" = true,
      "comment" = "the Reflections reflect everything except Banish, Disintegrate and the sense magics such as ESP, Detect Evil and Clairaudience (folio 7)",
    }, {
      "name" = "wrmSolidifyTrueMatter",
      "value" = true,
      "comment" = "the Solidify - the atmosphere coagulates into rock in one-half turn; true matter unaffected by Dispell Magic or Dissipation, but slightly porous so the trapped may still breathe (folio 7)",
    }, {
      "name" = "wrmUndeadControlCrystalBall",
      "value" = true,
      "comment" = "the Undead Control may be maintained at any range if the witch has a crystal ball with her, though the spell must be established within 10 inches (folio 5)",
    }, {
      "name" = "wrmCurseNoImmediateDeath",
      "value" = true,
      "comment" = "the Curse - it is not possible to curse a creature with immediate death; holy items, enchanted items and the witchcraft-immune are also safe (folio 5)",
    }, {
      "name" = "wrmPoisonTouchNeutralizable",
      "value" = true,
      "comment" = "a poisoned item identified and treated with a Neutralize Poison spell becomes harmless again; holy items, silver and magic objects may not be poisoned (folio 5)",
    }, {
      "name" = "wrmCurtainTwoAgents",
      "value" = true,
      "comment" = "the Curtain Wall - the witch's will is great and two control agents are required simultaneously to force her to summon her lair (folio 5)",
    }, {
      "name" = "wrmFireBoxElements",
      "value" = true,
      "comment" = "the Fire Box - destroyed by cold, rain or magic; it moves with the object it surrounds and does not suffocate or harm what is trapped inside (folio 5)",
    }, {
      "name" = "wrmDiminishHalving",
      "value" = true,
      "comment" = "the Diminish - successive uses reduce a target to 1/2, then 1/4, 1/8 and so on of its original size (folio 5)",
    }, {
      "name" = "wrmBlindnessExceptions",
      "value" = true,
      "comment" = "the Circle of Blindness exempts Djinn, Efreet, Clerics and witches; it counteracts vision, hearing, ESP, detection magic and devices alike (folio 5)",
    }, {
      "name" = "wrmElfTableEditorEndorsed",
      "value" = true,
      "comment" = "the elf sub-race table carries the editorial endorsement in print - \"Sounds good to me - any objections out there? Ed.\" (folio 14)",
    }, {
      "name" = "wrmElfTableTolkienNames",
      "value" = true,
      "comment" = "the honest boundary - Silvan, Sindar and Noldor are Tolkien's sub-race names, echoed in D&D's Wood, Grey and High elf convention; the variant layer carries the provenance, never core canon (folio 14)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wrmElfSubrace",
      "tag" = "ElfS",
      "count" = "wrmElfSubraceCount",
      "sentinel" = 0,
      "cols" = { "wrmElfSubraceMin", "wrmElfSubraceMax" },
      "col_comments" = { "the die band minimum by sub-race - Silvan from 1, Sindar from 17, Noldor at 20 (folio 14)", "the die band maximum by sub-race - Silvan to 16, Sindar to 19, Noldor at 20 (folio 14)" },
      "data" = { { 1, 16 }, { 17, 19 }, { 20, 20 } },
      "audit_comment" = "the Friedman elf sub-race table on the 20-sided die - 1-16 Silvan (Wood), 17-19 Sindar (Grey), 20 Noldor (High), editorially endorsed in print (folio 14)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wrmFamiliarBasiliskMin']() != 1 or m['wrmFamiliarBasiliskMax']() != 2 or m['wrmFamiliarWyvernRoll']() != 3 or m['wrmFamiliarWarlockRoll']() != 4 or m['wrmFamiliarUndeadMin']() != 5 or m['wrmFamiliarUndeadMax']() != 6",
      "note" = "the witch familiar die - 1,2 basilisk; 3 wyvern; 4 warlock with ring and wand; 5,6 one undead (folio 8)",
    }, {
      "expr" = "m['wrmFamiliarNoVampires']() != 1 or m['wrmFamiliarsCooperate']() != 1 or m['wrmGoodWitchNoGuardFamiliar']() != 1",
      "note" = "the familiar doctrines - no vampires, the cooperating guard, the good witch exemption (folio 8)",
    }, {
      "expr" = "m['wrmAssassinEyesSpeed']() != 12 or m['wrmAssassinEyesVictimTurns']() != 1 or m['wrmAssassinEyesImmaterial']() != 1 or m['wrmAssassinEyesCharmOrDeath']() != 1",
      "note" = "the Assassin's Eyes - 12 inches per turn, invisible and immaterial, the one-turn window, the Charm or Death Ray attack (folio 7)",
    }, {
      "expr" = "m['wrmLeechDustRange']() != 2 or m['wrmLeechDustUnableTurns']() != 2 or m['wrmLeechDustParalyzeTurns']() != 3 or m['wrmLeechDustDeathTurns']() != 4 or m['wrmLeechDustPlateBonusTurns']() != 2 or m['wrmLeechDustHolyWaterOnly']() != 1 or m['wrmMountainSeedCastleSize']() != 1",
      "note" = "the Leech Dust ladder - weak at two, paralyzed at three, dead at four, the plate-armor two-turn reprieve, holy water only; the Mountain Seeds castle-size swell (folio 7)",
    }, {
      "expr" = "m['wrmWandEspRange']() != 30 or m['wrmWandLycanthropeShield']() != 1 or m['wrmWitchThreeWands']() != 1 or m['wrmIllusionWandRestricted']() != 1",
      "note" = "the Witch Wand extras - the 30-foot ESP medallion, the lycanthrope/undead/elemental shield, the three-wand canon, the Illusion Wand restriction (folios 8, 9)",
    }, {
      "expr" = "m['wrmIvyBraceletPlantControl']() != 1 or m['wrmIvyBraceletFragile']() != 1 or m['wrmLocketSatanRange']() != 7 or m['wrmLocketSatanCommandMax']() != 3 or m['wrmLocketSatanCorruptTurns']() != 2 or m['wrmLocketSatanCorruptPct']() != 15 or m['wrmLocketSatanClericImmune']() != 1",
      "note" = "the Ivy Bracelet and the Locket of Satan - the plant control and fragility, the 7-inch 3-creature command, the two-turn 15-percent corruption, the cleric immunity (folio 9)",
    }, {
      "expr" = "m['wrmSnakeBeltLengthFeet']() != 3 or m['wrmSnakeBeltSpeed']() != 6 or m['wrmSnakeBeltDamageDice']() != 1 or m['wrmSnakeBeltFireLightningOnly']() != 1 or m['wrmSkullPowersRepeatable']() != 1",
      "note" = "the Snake Belt - 3 feet, 6 feet per turn, 1 die, fire and lightning only; the Skull of Death's repeatable Finger of Death and Animate Dead (folios 7, 9)",
    }, {
      "expr" = "m['wrmLuckCharmWishPct']() != 70 or m['wrmLuckCharmLimitedWishes']() != 2 or m['wrmLuckCharmLairBonusPct']() != 10 or m['wrmLuckCharmTreasure20Pct']() != 75 or m['wrmLuckCharmTreasureBonus20']() != 20 or m['wrmLuckCharmTreasureBonus50']() != 50",
      "note" = "the Luck Charm remainder - the 70-percent wish, the two limited wishes weekly, the 10-percent lair bonus, the 20/50 per-category treasure enhancement at 75 percent (folio 28)",
    }, {
      "expr" = "m['wrmPotionDupPerHour']() != 1 or m['wrmPotionCauldronWitchesOnly']() != 1 or m['wrmTreasureFindingDoctrine']() != 1",
      "note" = "the Potion Cauldron - one duplicate per hour, witches only, the Treasure-Finding blood-pledge doctrine (folio 8)",
    }, {
      "expr" = "m['wrmWitchElementalHd']() != 12 or m['wrmWitchElementalDelayTurns']() != 1 or m['wrmWitchElementalConcentration']() != 1",
      "note" = "the witch's Summon Elemental - 12 hit dice, one turn late, gone if the concentration breaks (folio 4)",
    }, {
      "expr" = "m['wrmWitherCircleFeet']() != 50 or m['wrmWeightAffectedMin']() != 1 or m['wrmWeightAffectedMax']() != 10 or m['wrmWeightFactor']() != 3",
      "note" = "the Group B effects - the 50-foot Wither circle, the Weight spell over 1-10 targets at triple or one-third (folio 7)",
    }, {
      "expr" = "m['wrmVolcanicFlowFeet']() != 4 or m['wrmVolcanicLineFeet']() != 10 or m['wrmVolcanicDamageDice']() != 10 or m['wrmReflectionsTurns']() != 2 or m['wrmReflectionsExceptions']() != 1 or m['wrmSolidifyTrueMatter']() != 1",
      "note" = "the Volcanic Circle - 4 feet per turn, 10-foot line, 10 dice under the flow; the two-turn Reflections with its Banish/Disintegrate exceptions; the Solidify true-matter doctrine (folio 7)",
    }, {
      "expr" = "m['wrmUndeadControlMin']() != 1 or m['wrmUndeadControlMax']() != 6 or m['wrmUndeadControlCrystalBall']() != 1 or m['wrmCurseSilverPct']() != 75 or m['wrmCurseNoImmediateDeath']() != 1",
      "note" = "the Undead Control over 1-6 undead with the crystal-ball range doctrine; the Curse - no immediate death, the 75-percent silver enclosure (folio 5)",
    }, {
      "expr" = "m['wrmPoisonTouchObjects']() != 3 or m['wrmPoisonTouchDeathAfterTurns']() != 2 or m['wrmPoisonTouchNeutralizable']() != 1 or m['wrmCurtainWidthFeet']() != 10 or m['wrmCurtainRoomDepthFeet']() != 20 or m['wrmCurtainTwoAgents']() != 1",
      "note" = "the Poison Touch - 3 objects or a 4-by-4 surface, dead at two turns of contact, Neutralize Poison the cure; the Curtain Wall - 10 feet wide, 20 feet deep, two control agents (folio 5)",
    }, {
      "expr" = "m['wrmFireBoxCubeFeet']() != 10 or m['wrmFireBoxElements']() != 1 or m['wrmDiminishHalving']() != 1 or m['wrmBlindnessRadiusFeet']() != 25 or m['wrmBlindnessExceptions']() != 1",
      "note" = "the Fire Box 10-foot cube with its element weaknesses, the Diminish halving ladder, the 25-foot Circle of Blindness with its exceptions (folio 5)",
    }, {
      "expr" = "m['wrmElfSubraceMin'](0) != 1 or m['wrmElfSubraceMax'](0) != 16 or m['wrmElfSubraceCount']() != 3 or m['wrmElfTableDieSides']() != 20",
      "note" = "the elf sub-race band, row 0 of 3 - the Silvan 1-16, the Sindar 17-19, the Noldor 20 on the d20 (folio 14)",
    }, {
      "expr" = "m['wrmElfSubraceMin'](1) != 17 or m['wrmElfSubraceMax'](1) != 19",
      "note" = "the elf sub-race band, row 1 of 3 - the Silvan 1-16, the Sindar 17-19, the Noldor 20 on the d20 (folio 14)",
    }, {
      "expr" = "m['wrmElfSubraceMin'](2) != 20 or m['wrmElfSubraceMax'](2) != 20",
      "note" = "the elf sub-race band, row 2 of 3 - the Silvan 1-16, the Sindar 17-19, the Noldor 20 on the d20 (folio 14)",
    }, {
      "expr" = "m['wrmElfTableEditorEndorsed']() != 1 or m['wrmElfTableTolkienNames']() != 1",
      "note" = "the elf table doctrines - the editorial endorsement in print, the Tolkien-names boundary noted (folio 14)",
    } },
  "audit" = {
      "label" = "R905 witch remainders audit",
      "comment" = "THE WITCH REMAINDERS AND THE FRIEDMAN ELF TABLE - the might-be-usable micro-round from the 2026-10-29 issue-5 ledger review. The familiars (folio 8): the six-sided die - 1,2 basilisk, 3 wyvern, 4 warlock with one ring and one wand, 5,6 one undead character with no vampires, the familiars cooperating over the entire circle, the good witches exempt from the guard. The items (folios 7-9): the Assassin's Eyes at 12 inches per turn, invisible and immaterial, the one-turn kill window, the Charm Person or Death Ray with saving throws; the Leech Dust - the 2-inch Cloudkill-dimension cloud, weak at two turns, paralyzed at three, dead at four, plate armor prolonging death two, holy water the only removal and a week of rest after; the Mountain Seeds swelling to a castle; the Witch Wand's 30-foot ESP medallion and the lycanthrope, undead and elemental shield like scrolls; the three-wand canon with the Illusion Wand restricted to witches and magic-users; the Ivy Bracelet's plant control and fragility; the Locket of Satan - 7 inches, 3 chaotic creatures, no saving throws, the two-turn 15-percent lawful corruption, no effect on clerics; the Snake Belt - 3 feet, 6 feet per turn, 1 die, killed only by fire and lightning; the Skull of Death's repeatable Finger of Death and Animate Dead; the Luck Charm remainder - the 70-percent single wish or two limited weekly, the 10-percent lair-finding bonus, the per-category treasure enhancement of 20 percent (at 75 percent chance) or 50 percent; the Potion Cauldron - witches only, one duplicate per hour, the Treasure-Finding blood pledge with prompt cursing on a broken word. The spell effect details (folios 4-7): the 12-hit-dice elemental one turn late and gone with the concentration; the 50-foot Wither; the Weight spell over 1-10 targets at triple or one-third; the Volcanic Circle flowing 4 feet per turn behind a 10-foot line for 10 dice to ground creatures; the two-turn Reflections returning everything but Banish, Disintegrate and the sense magics; the Solidify's true-matter rock, porous for breathing, beyond Dispel and Dissipation; the Undead Control over 1-6 undead with the crystal-ball maintenance; the Curse - no immediate death, the 75-percent silver enclosure; the Poison Touch - 3 objects or the 4-by-4 surface, death at two turns of contact, Neutralize Poison the cure; the Curtain Wall - the 10-foot curtain before the 10-by-20 room, two control agents required simultaneously; the Fire Box's 10-foot cube destroyed by cold, rain or magic; the Diminish halving ladder; the 25-foot Circle of Blindness with the Djinn, Efreet, Cleric and witch exceptions. The Friedman elf sub-race table (folio 14): the d20 - 1-16 Silvan, 17-19 Sindar, 20 Noldor, editorially endorsed in print, the Tolkien-names boundary pinned as the honest provenance. The R904 record seats in the seed via prev_record.",
    },
}
