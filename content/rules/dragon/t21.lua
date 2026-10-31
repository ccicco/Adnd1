-- t21: promoted from tools/spec_r943.json (the The Dragon issue-21 opener part one - the twenty-NPC personality grid, the spell-research doctrine and the foretelling-spell counters);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 943,
  "prefix" = "t21",
  "banner" = {
      "title" = "The Dragon issue-21 opener part one - the twenty-NPC personality grid, the spell-research doctrine and the foretelling-spell counters",
      "provenance" = "The opener of the issue-21 three-round shape - three of the seven Curtiss-called chains pinned, the economics, monster blues, Hall of Mystery and title kit riding the part-two round. All pinned from The Dragon Vol. III No. 6 (December 1978), the Curtiss-provided Dm21.pdf scan voice, print folio the PDF page minus two.",
      "sentinel" = "The issue-21 print catches pinned as scanned: the contents masthead prints Vol. 111 No. 6 for Vol. III and November 1978 for December, the cover also prints No. 6, the Suliin article prints Paul Suliin and Ventriliquism, the Rollo prose statline prints seven stat numbers, and the Medivar spelling rides the Prophet Proofing deterrents. Both inherited watches - the Sullin levels 7-9 and the brawling sequel - print nowhere in TD21 and ride to TD 22.",
    },
  "consts" = { {
      "name" = "t21NpcCount",
      "value" = 20,
      "comment" = "the NPC statline count - Blarg through Dassol, twenty personality encounters across three print pages the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcFirstPage",
      "value" = 9,
      "comment" = "the first-print-page count - nine NPCs on print 11, ten on print 23, the last two on print 27 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcMidPage",
      "value" = 10,
      "comment" = "the mid-print-page count - the ten NPCs Grunt through Pontance on print 23, sharing the page with the Judges Guild ad the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcLevelSeventeen",
      "value" = 17,
      "comment" = "the Gantol dual-class level - the 17th-level magic user turned first-level fighter, the highest level in the kit the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcRolloLevel",
      "value" = 9,
      "comment" = "the Rollo the Rotund level - the 9th-level magic user owner of Zilch, his statline printed in the prose the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcRolloHp",
      "value" = 24,
      "comment" = "the Rollo hit points - 24, printed in the prose as 24Htk the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcRolloAc",
      "value" = 9,
      "comment" = "the Rollo armor class - 9, printed in the prose the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcClarHeight",
      "value" = 12,
      "comment" = "the Clar werebear height - 12 feet tall in bear form, the claws 1-3 and bite 2-8 with the 2-16 hug on an 18 or better the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcRolloStatlineSeven",
      "value" = 7,
      "comment" = "the Rollo print catch - his prose statline prints SEVEN stat numbers 9 17 1 1 10 7 17, one more than the six-stat grid the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21ResearchRules",
      "value" = 3,
      "comment" = "the Rules of Research count - Rule One no outdoing existing spells, Rule Two no cross-profession spells, Rule Three no spell of an unlearnable level the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21MoonRunesLevel",
      "value" = 2,
      "comment" = "the Moon Runes adjudication - too cheap at first level and not worth having at third with Explosive Rune there, so second level is the fit the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21MagicMissileTwoLevel",
      "value" = 2,
      "comment" = "the Magic Missile II level - the obvious second-level equivalent, researched elsewhere as Magic Javelin the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21WallWaterBlockHd",
      "value" = 5,
      "comment" = "the Wall of Water block ceiling - blocks creatures under 5 hit dice the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21WallWaterFireDice",
      "value" = 6,
      "comment" = "the Wall of Water fiery damage - 6 dice against fiery creatures the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21WallFireBlockHd",
      "value" = 4,
      "comment" = "the Wall of Fire block ceiling - the existing fourth-level wall blocks creatures under 4 hit dice the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21WallIceFireDice",
      "value" = 1,
      "comment" = "the Wall of Ice fiery damage - only 1 die against fiery creatures the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21ShatterrayMin",
      "value" = 5,
      "comment" = "the Shatterray damage floor - 5 of the 5-30 band, on top of the aiming and level-scaling extras the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21ShatterrayMax",
      "value" = 30,
      "comment" = "the Shatterray damage ceiling - 30 of the 5-30 band the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21IceStormMin",
      "value" = 3,
      "comment" = "the Ice Storm damage floor - the Greyhawk fourth-level benchmark at 3-30 the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21IceStormMax",
      "value" = 30,
      "comment" = "the Ice Storm damage ceiling - 30 of the 3-30 band, with none of the Shatterray advantages the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21FireMageBoltsLevel",
      "value" = 2,
      "comment" = "the specialist exception - a Fire-Mage may get Firebolts or Firebeams doing equivalent to Fireballs at second level the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21ForetellingSpells",
      "value" = 5,
      "comment" = "the foretelling spell count - Clairvoyance, Clairaudience, Wizard Eye, ESP and X-ray vision, the five DM-patience testers the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21InsanityContagionMin",
      "value" = 2,
      "comment" = "the insanity contagion floor - a sane person reading a madman becomes insane in the same manner for 2-7 turns the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21InsanityContagionMax",
      "value" = 7,
      "comment" = "the insanity contagion ceiling - 7 of the 2-7 turn band the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21NonDirectionalFeet",
      "value" = 60,
      "comment" = "the non-directional option - Clairvoyance, Clairaudience and ESP declared to return the sights, sounds or thoughts of all beings within 60 feet the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21LeadInches",
      "value" = 3,
      "comment" = "the lead-wall doctrine - three inches of lead sandwiched in the lower-level walls, ceilings and floors the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21VoyeurPct",
      "value" = 33,
      "comment" = "the voyeur Wizard Eye flaw - 33 percent of the time it ignores its owner and hunts mating monsters or pornographic wall paintings the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21WizardEyeUsesPerDay",
      "value" = 3,
      "comment" = "the Wizard Eye medallion - projects the spell three times per day the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21HelmFireballDice",
      "value" = 15,
      "comment" = "the Helm of Telepathy trick - the KOBOLD-thinking MU behind the door charged with a fifteen hit-die fireball the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21InsanityArticleIssue",
      "value" = 18,
      "comment" = "the insanity cross-reference - Kevin Thompson fine article in TD 18 provides the ESP-counter key the foretelling-spell counters (print 9, PDF 11)",
    } },
  "bools" = { {
      "name" = "t21NpcDassolConfederates",
      "value" = true,
      "comment" = "the Dassol buffoon magnet - 3-18 person crowds while his two 8th-level elf thief confederates pick pockets at 70 percent, with the pyrotechnics smokescreen escape the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcGleenSocks",
      "value" = true,
      "comment" = "the Gleen pick-everyone doctrine - he picks every pocket in a crowd so succeeds only 5 percent, but climbs at 0 percent fall, moves silently at 80 and hides at 85 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcGruntArmsBan",
      "value" = true,
      "comment" = "the Grunt doctrine - no one will sell him weapons, sellers face 4-40 months hard labor or a 100-1000 gold fine or both the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcZilchRollo",
      "value" = true,
      "comment" = "the Zilch-Rollo doctrine - the zombie runs embarrassing errands for the 9th-level joker MU and runs away if seriously threatened the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcPontanceDisguise",
      "value" = true,
      "comment" = "the Pontance phantasmal-forces cloak - she appears an old woman, the saving throw versus magic at minus 4, her true charisma 14 disguised as 9 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21NpcKlundRoar",
      "value" = true,
      "comment" = "the Klund roar - clears the street 60 feet in all directions, the giant club swung as a flail to subdue, losers tossed onto roofs for 2-8 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "name" = "t21RuleOne",
      "value" = true,
      "comment" = "Rule One of Research - no researched spell may cause more damage, gain more information, summon more powerful beings, or give more control than an existing spell of the same or lower level the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21RuleTwo",
      "value" = true,
      "comment" = "Rule Two of Research - a character cannot learn a spell that is the province of another profession, the dividing line between magic-user and cleric the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21RuleThree",
      "value" = true,
      "comment" = "Rule Three of Research - a character cannot research a spell of a level he cannot yet learn the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21SpecialistException",
      "value" = true,
      "comment" = "the Rule One exception - a researcher of a more suited profession may exceed, the Fire-Mage precedent the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21VendingMachineWarning",
      "value" = true,
      "comment" = "the vending-machine warning - gold in and anything out is the too-common shape, the research neither fixes the level, the fit, nor the capability the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21ClericNoAttackMagic",
      "value" = true,
      "comment" = "the cleric line - clerics do not manipulate natural or supernatural forces to attack: Web, Magic Missile, Fireball the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21MuNoDivineAid",
      "value" = true,
      "comment" = "the magic-user line - no divine guidance or intervention: Detect Traps, Speak With Dead, Resurrection the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21WallWaterNoConcentration",
      "value" = true,
      "comment" = "the Wall of Water print critique - it demands no concentration while the existing walls do, part of the too-much case the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21SuliinSpellingPrintCatch",
      "value" = true,
      "comment" = "the Suliin spelling print catch - the article prints Paul Suliin and Suliin throughout for the Suliin article it critiques, and Ventriliquism for Ventriloquism, pinned as scanned the spell-research doctrine (print 10, PDF 12)",
    }, {
      "name" = "t21MedivarDeterrent",
      "value" = true,
      "comment" = "the Medivar deterrent - a few strategically placed ones discourage Clairvoyance, Wizard Eyes and X-ray vision; the print catch rides the Medivar spelling, pinned as scanned the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21HarpyDeterrent",
      "value" = true,
      "comment" = "the harpy deterrent - just as effective against Clairaudience the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21SanityContagionDoctrine",
      "value" = true,
      "comment" = "the sanity contagion - reading a madman mind or scrying him madly makes the reader insane in the same manner, applied to ESP, Clairvoyance and Clairaudience users the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21WizardEyeNoLiquidsSolids",
      "value" = true,
      "comment" = "the Wizard Eye restriction option - unable to penetrate liquids and solids, fine for corners and useless for closed rooms the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21XrayLeadBuiltIn",
      "value" = true,
      "comment" = "the X-ray built-in limitation - it cannot penetrate lead the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21ParanoidNpcProtection",
      "value" = true,
      "comment" = "the paranoid NPC doctrine - high-level non-players possess Amulets versus ESP and other foretelling protection the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21HelmKoboldTrick",
      "value" = true,
      "comment" = "the Helm of Telepathy dirty trick - the MU thinks KOBOLD into the Helm so the charging party eats the fifteen-die fireball the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "name" = "t21MedallionBlueMovies",
      "value" = true,
      "comment" = "the medallion economy - the magic-user rented the voyeur Eye to wealthy townsmen who loved its blue movies, and made a mint the foretelling-spell counters (print 9, PDF 11)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "t21Npcs",
      "tag" = "Np",
      "count" = "t21NpcCount",
      "sentinel" = -99,
      "audit_comment" = "the personality statline grid - twenty NPCs down, the eleven columns across: level, hit points, armor class, the six stats, the to-hit and to-damage bonuses; the printed Ave. bonus lines pinned 0, the conversion noted, and the Clar werebear armor class 2 pinned with the apparent-9 footnote, the Pontance disguise charisma 14 pinned with the asterisk footnote the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
      "cols" = { "t21NpcLevel", "t21NpcHp", "t21NpcAc", "t21NpcStr", "t21NpcInt", "t21NpcWis", "t21NpcCon", "t21NpcDex", "t21NpcCha", "t21NpcToHit", "t21NpcToDmg" },
      "col_comments" = { "the level column - the Blarg 3rd through the Gantol 17th, the zombie and mummy NPCs pinned at their monster-equivalent fighter levels as printed the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the hit point column - the Grunt 2 print catch floor through the Tarky 69 ceiling the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the armor class column - the Gantol -2 through the multiple 9s, the Clar 2 with the apparent-9 when-human footnote the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the strength column - the Grunt 4 floor through the 18 band the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the intelligence column - the Lontipol 6 floor through the Gantol 17 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the wisdom column - the Lontipol 19 peak with the Str 8 floor the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the constitution column - the Gleen 7 floor through the Klund 18 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the dexterity column - the Snir 4 floor through the Iradain 19 archer peak the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the charisma column - the Snir 4 floor through the Gleen 18, the Pontance 14 with the disguise-9 footnote the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the to-hit column - the Grunt -2 through the Clar and Klund +4, the printed Ave. pinned 0 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)", "the to-damage column - the Grunt -1 through the Clar and Klund +6, the printed Ave. pinned 0 the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)" },
      "data" = { { 3, 20, 5, 16, 7, 7, 6, 8, 6, 1, 1 }, { 4, 23, 6, 15, 9, 7, 12, 9, 4, 0, 0 }, { 17, 64, -2, 8, 17, 9, 11, 13, 11, 0, 0 }, { 6, 36, 7, 17, 12, 10, 13, 19, 16, 2, 2 }, { 7, 45, 2, 18, 16, 14, 18, 9, 11, 4, 6 }, { 11, 69, 7, 18, 10, 8, 16, 11, 14, 3, 4 }, { 13, 51, 9, 8, 6, 19, 7, 7, 7, 0, 0 }, { 1, 9, 7, 17, 9, 10, 9, 7, 8, 2, 2 }, { 1, 9, 9, 18, 12, 8, 16, 4, 5, 3, 3 }, { 1, 2, 2, 4, 9, 11, 3, 6, 15, -2, -1 }, { 1, 8, 8, 16, 8, 4, 14, 10, 10, 1, 1 }, { 2, 4, 7, 5, 10, 14, 7, 16, 18, -1, 0 }, { 2, 20, 8, 10, 10, 8, 10, 10, 7, 0, 0 }, { 3, 9, 9, 14, 7, 8, 10, 8, 4, 1, 0 }, { 5, 27, 3, 13, 9, 4, 10, 10, 6, 0, 0 }, { 5, 28, 4, 17, 11, 10, 14, 9, 9, 2, 2 }, { 6, 51, 7, 18, 7, 6, 18, 10, 6, 4, 6 }, { 7, 11, 9, 8, 15, 16, 6, 13, 14, 1, 0 }, { 8, 33, 6, 15, 9, 7, 13, 10, 12, 1, 0 }, { 9, 30, 9, 8, 10, 14, 8, 14, 6, 0, 0 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['t21NpcCount']() != 20 or m['t21NpcFirstPage']() != 9 or m['t21NpcMidPage']() != 10 or m['t21NpcLevelSeventeen']() != 17 or m['t21NpcRolloLevel']() != 9 or m['t21NpcRolloHp']() != 24 or m['t21NpcRolloAc']() != 9",
      "note" = "the personality census - twenty NPCs across three print pages, the Gantol 17th dual and the Rollo 9/24/9 inline statline the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "expr" = "m['t21NpcLevel'](0) != 3 or m['t21NpcHp'](0) != 20 or m['t21NpcAc'](0) != 5 or m['t21NpcLevel'](2) != 17 or m['t21NpcAc'](2) != -2 or m['t21NpcToHit'](2) != 0 or m['t21NpcCha'](5) != 14 or m['t21NpcDex'](3) != 19 or m['t21NpcHp'](9) != 2 or m['t21NpcToHit'](9) != -2",
      "note" = "the grid corners - the Blarg opener, the Gantol -2 dual, the Tarky charisma 14, the Iradain dexterity 19, the Grunt 2-hit-point minus-2 floor the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "expr" = "m['t21NpcLevel'](19) != 9 or m['t21NpcHp'](19) != 30 or m['t21NpcAc'](19) != 9 or m['t21NpcCha'](11) != 18 or m['t21NpcHp'](16) != 51 or m['t21NpcToHit'](16) != 4 or m['t21NpcToDmg'](16) != 6 or m['t21NpcCha'](17) != 14 or m['t21NpcRolloStatlineSeven']() != 7",
      "note" = "the grid tail - the Dassol closer, the Gleen charisma 18, the Klund 51 with the plus-4 plus-6 club, the Pontance 14 disguise charisma and the Rollo seven-stat print catch the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "expr" = "m['t21NpcClarHeight']() != 12 or m['t21NpcDassolConfederates']() != 1 or m['t21NpcGleenSocks']() != 1 or m['t21NpcGruntArmsBan']() != 1 or m['t21NpcZilchRollo']() != 1 or m['t21NpcPontanceDisguise']() != 1 or m['t21NpcKlundRoar']() != 1",
      "note" = "the personality doctrine - the twelve-foot Clar, the Dassol confederates, the Gleen five-percent pick-everyone, the Grunt arms ban, the Zilch-Rollo gags, the Pontance cloak and the Klund roar the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)",
    }, {
      "expr" = "m['t21ResearchRules']() != 3 or m['t21MoonRunesLevel']() != 2 or m['t21MagicMissileTwoLevel']() != 2 or m['t21FireMageBoltsLevel']() != 2 or m['t21WallWaterBlockHd']() != 5 or m['t21WallWaterFireDice']() != 6 or m['t21WallFireBlockHd']() != 4 or m['t21WallIceFireDice']() != 1",
      "note" = "the research census - three rules, the Moon Runes, Magic Missile II and Fire-Mage bolts all at second level, the Wall of Water 5-hit-dice 6-dice case against the existing wall benchmarks the spell-research doctrine (print 10, PDF 12)",
    }, {
      "expr" = "m['t21ShatterrayMin']() != 5 or m['t21ShatterrayMax']() != 30 or m['t21IceStormMin']() != 3 or m['t21IceStormMax']() != 30 or m['t21RuleOne']() != 1 or m['t21RuleTwo']() != 1 or m['t21RuleThree']() != 1 or m['t21SpecialistException']() != 1",
      "note" = "the Shatterray 5-30 against the Ice Storm 3-30 with none of the extras, the three Rules of Research and the specialist exception the spell-research doctrine (print 10, PDF 12)",
    }, {
      "expr" = "m['t21VendingMachineWarning']() != 1 or m['t21ClericNoAttackMagic']() != 1 or m['t21MuNoDivineAid']() != 1 or m['t21WallWaterNoConcentration']() != 1 or m['t21SuliinSpellingPrintCatch']() != 1",
      "note" = "the research doctrine - the vending machine, the cleric and magic-user dividing lines, the no-concentration critique and the Suliin spelling print catch the spell-research doctrine (print 10, PDF 12)",
    }, {
      "expr" = "m['t21ForetellingSpells']() != 5 or m['t21InsanityContagionMin']() != 2 or m['t21InsanityContagionMax']() != 7 or m['t21NonDirectionalFeet']() != 60 or m['t21LeadInches']() != 3 or m['t21InsanityArticleIssue']() != 18",
      "note" = "the foretelling census - five spells, the 2-7 turn insanity contagion, the 60-foot non-directional option, the three-inch lead and the TD-18 cross-reference the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "expr" = "m['t21VoyeurPct']() != 33 or m['t21WizardEyeUsesPerDay']() != 3 or m['t21HelmFireballDice']() != 15 or m['t21MedivarDeterrent']() != 1 or m['t21HarpyDeterrent']() != 1 or m['t21SanityContagionDoctrine']() != 1",
      "note" = "the counter census - the 33-percent voyeur, the 3-per-day medallion, the fifteen-die Kobold fireball, the Medivar and harpy deterrents and the contagion doctrine the foretelling-spell counters (print 9, PDF 11)",
    }, {
      "expr" = "m['t21WizardEyeNoLiquidsSolids']() != 1 or m['t21XrayLeadBuiltIn']() != 1 or m['t21ParanoidNpcProtection']() != 1 or m['t21HelmKoboldTrick']() != 1 or m['t21MedallionBlueMovies']() != 1",
      "note" = "the counter doctrine - the liquids-and-solids restriction, the built-in lead limit, the paranoid NPC amulets, the Helm trick and the blue-movie medallion economy the foretelling-spell counters (print 9, PDF 11)",
    } },
  "audit" = {
      "label" = "R943 issue-21 opener part one audit",
      "comment" = "THE DRAGON ISSUE-21 OPENER PART ONE - the three-chain round of the issue-21 three-round shape. Three chains pinned from the Curtiss-provided Dm21.pdf scan: the Stevens Encounters with Personality - the twenty-NPC statline kit across three print pages; the Pehr Sensible Sorcery - the three Rules of Research, the Suliin spell-level critiques and the specialist exception; the Schroeder Prophet Proofing - the five foretelling spells and their counters, from the Medivar deterrents to the fifteen-die Kobold fireball. Part two (the inflation economics, the monster blues, the Hall of Mystery, the title kit) rides R944, the closing flip R945.",
    },
}
