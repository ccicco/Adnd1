-- ua: promoted from rules/ua/uadeityprose5.h (the THE ORCISH DEITY PROSE - part 5, the finale of the Appendix S paragraph);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 790,
  "prefix" = "ua",
  "banner" = {
      "title" = "THE ORCISH DEITY PROSE - part 5, the finale of the Appendix S paragraph",
      "provenance" = "close: the shaman tale plus Bahgtru, Shargaas, Ilneval, Yurtrus, and Luthic pin from the clean archive.org OCR read census 712 -> 713.  Part 5 of 5 (R786 the dwarves, R787 the elves, R788 the halflings, R789 the gnomes). The shaman-tale intro and the five orcish blocks (pp. 118-121) read scan-clean in the archive.org full-text OCR: every pin below is the printed text. The stat-block numerics stay R406/R783; the paragraph-level facts pin here - the lot-drawing creation tale and the Gruumsh iron spear, the Bahgtru crush and the blunt bounce, the Shargaas new-moon ambush creed, the Ilneval captain politics and the death-sword, the Yurtrus three-band gas and the wish-only recovery, and the Luthic fertility dirt and the name-abuse curse. This round FLIPS dvpProseStaysOpen to false: every Appendix S description paragraph now pins, and the R783 audit assertion rides with it.",
    },
  "consts" = { {
      "name" = "udp5ProseRound",
      "value" = 790,
      "comment" = "---- the prose consts (the R790 wiring) ---- The prose round: part 5, the orcish paragraphs - the close finale",
    }, {
      "name" = "udp5StatblockFeederRound",
      "value" = 406,
      "comment" = "The feeder round: the R406 stat blocks these paragraphs hang under",
    }, {
      "name" = "udp5OrcishDeityCount",
      "value" = 5,
      "comment" = "The orcish census: five blocks described (Bahgtru, Shargaas, Ilneval, Yurtrus, Luthic)",
    }, {
      "name" = "udp5ProsePartsTotal",
      "value" = 5,
      "comment" = "The five-part close is complete: dwarves, elves, halflings, gnomes, orcs",
    }, {
      "name" = "udp5ProsePartRoundMin",
      "value" = 786,
      "comment" = "The close opened at R786 (the dwarven prose)",
    }, {
      "name" = "udp5ProsePartRoundMax",
      "value" = 790,
      "comment" = "and closes at R790 (the orcish prose)",
    }, {
      "name" = "udp5BahGrappleMargin",
      "value" = 4,
      "comment" = "If he rolls 4 or more over what he needs to hit with both hands, he has grappled his opponent",
    }, {
      "name" = "udp5BahCrushDamageMin",
      "value" = 10,
      "comment" = "A grappled victim is crushed for 10-120 points per round without rolling again to hit: the minimum 10",
    }, {
      "name" = "udp5BahCrushDamageMax",
      "value" = 120,
      "comment" = "and the maximum 120",
    }, {
      "name" = "udp5BahBluntWeaponDamage",
      "value" = 1,
      "comment" = "His skin is so thick that blunt weapons do only one point of damage before they bounce off",
    }, {
      "name" = "udp5BahClericStrengthMin",
      "value" = 16,
      "comment" = "Clerics of Bahgtru must have a minimum strength of 16 and keep physically fit",
    }, {
      "name" = "udp5ShaDarkSightMiles",
      "value" = 1,
      "comment" = "Though blinded by sunlight, he sees perfectly in darkness out to a range of a mile or more",
    }, {
      "name" = "udp5ShaShadowSkillMin",
      "value" = 5,
      "comment" = "Rumored shaman/witch-doctor thieving skill of 5-30 percent success: the minimum 5",
    }, {
      "name" = "udp5ShaShadowSkillMax",
      "value" = 30,
      "comment" = "and the maximum 30",
    }, {
      "name" = "udp5IlnSwordSaveMod",
      "value" = -6,
      "comment" = "His sword slays all non-orcs it strikes (save versus death at -6)",
    }, {
      "name" = "udp5YurGasRadiusFeet",
      "value" = 120,
      "comment" = "He is surrounded by stinking gases out to 120 feet",
    }, {
      "name" = "udp5YurGasLowBandHd",
      "value" = 4,
      "comment" = "Beings up to and including 4 hit dice/levels are affected as by dust of sneezing and choking",
    }, {
      "name" = "udp5YurGasMidBandHd",
      "value" = 8,
      "comment" = "Those up to 8 hit dice/levels as if struck by a symbol of pain",
    }, {
      "name" = "udp5YurGasHighHitMod",
      "value" = -2,
      "comment" = "Those of higher level suffer -2 to hit with no saving throw",
    }, {
      "name" = "udp5YurDeathMagicLevel",
      "value" = 18,
      "comment" = "He uses all death-magic spells of 18th-level magic-users",
    }, {
      "name" = "udp5YurTouchDamageMin",
      "value" = 3,
      "comment" = "A being he strikes loses 3-12 hit points: the minimum 3",
    }, {
      "name" = "udp5YurTouchDamageMax",
      "value" = 12,
      "comment" = "and the maximum 12",
    }, {
      "name" = "udp5YurTouchDiseasesMin",
      "value" = 1,
      "comment" = "and catches 1-4 random diseases: the minimum 1",
    }, {
      "name" = "udp5YurTouchDiseasesMax",
      "value" = 4,
      "comment" = "and the maximum 4",
    }, {
      "name" = "udp5LutClawLengthFeet",
      "value" = 4,
      "comment" = "Her unbreakable black claws are four feet long",
    }, {
      "name" = "udp5LutRegenPerRound",
      "value" = 3,
      "comment" = "In contact with the ground she regenerates 3 hit points per round",
    }, {
      "name" = "udp5LutCurseChancePct",
      "value" = 10,
      "comment" = "A 10 percent chance that abuse of her name renders the abuser susceptible to any disease",
    }, {
      "name" = "udp5LutCurseFatalDaysMin",
      "value" = 2,
      "comment" = "The next ailment proves fatal within 2-7 days: the minimum 2",
    }, {
      "name" = "udp5LutCurseFatalDaysMax",
      "value" = 7,
      "comment" = "and the maximum 7",
    }, {
      "name" = "udp5LutCurseUndoWishes",
      "value" = 3,
      "comment" = "Only the power of three wish spells applied while the victim still lives can undo the curse",
    }, {
      "name" = "udp5LutGuardHitBonus",
      "value" = 2,
      "comment" = "Orcs guarding her clerics gain a +2 to-hit bonus from their ferocity and madness",
    }, {
      "name" = "udp5LutGuardAcPenalty",
      "value" = -2,
      "comment" = "but this also causes a -2 penalty to their armor classes",
    } },
  "bools" = { {
      "name" = "udp5TaleOfTheLots",
      "value" = true,
      "comment" = "---- the prose bools (the R790 wiring) ---- The shamans tell how the gods drew lots for the parts of the world: humans where they pleased, elves the green forests, dwarves the high mountains, gnomes the rocky sunlit hills, halflings the fields and meadows",
    }, {
      "name" = "udp5TaleMockedOrcs",
      "value" = true,
      "comment" = "The assembled gods turned to the orcish gods and laughed: all the lots are taken, there is no place left",
    }, {
      "name" = "udp5TaleIronSpear",
      "value" = true,
      "comment" = "Gruumsh One-Eye lifted his great iron spear over the world - piercing the mountains, splitting the hills, gouging the meadows - and claimed those places for the orcs",
    }, {
      "name" = "udp5TaleOrcsInherit",
      "value" = true,
      "comment" = "He-Who-Watches roared that orcs will cover the world, slay all the collected peoples, and inherit it",
    }, {
      "name" = "udp5TaleWarForWrath",
      "value" = true,
      "comment" = "This is why orcs make war, ceaseless and endless: war for the wrath of Gruumsh",
    }, {
      "name" = "udp5TaleCorellonBattle",
      "value" = true,
      "comment" = "Corellon Larethian tried to shoot out Gruumsh eye and failed; because of that battle orcs of all sects hate elves more than all other non-orc races",
    }, {
      "name" = "udp5TaleDwarfMountainWars",
      "value" = true,
      "comment" = "The shamans tales of the battle between the dwarven and orcish gods for ownership of the mountains would weary the most ardent listener",
    }, {
      "name" = "udp5TaleGoblinBattles",
      "value" = true,
      "comment" = "The eternal battles on the plains of the Nine Hells between the goblins and orcs, each side led by their respective gods",
    }, {
      "name" = "udp5TaleTribesAlongCults",
      "value" = true,
      "comment" = "The division of orcs into separate tribes (Evil Eye, Death Moon, Broken Bone, etc.) is usually made along cult lines - the tribal symbol is the holy symbol of the patron god",
    }, {
      "name" = "udp5TaleHierarchyUnderGruumsh",
      "value" = true,
      "comment" = "There are a large number of orcish gods in a rigid chain of command with Gruumsh at the top; the relative positions vary with the shaman doing the telling",
    }, {
      "name" = "udp5TaleTribalWarfareEncouraged",
      "value" = true,
      "comment" = "Warfare between tribes is encouraged to some extent - eliminating the unfit and weak, promoting the survival and growth of the strong",
    }, {
      "name" = "udp5BahSonOfGruumshAndLuthic",
      "value" = true,
      "comment" = "He is the son of Gruumsh and Luthic the Cave Mother",
    }, {
      "name" = "udp5BahScornedButMighty",
      "value" = true,
      "comment" = "Scorned and derided for his stupidity and lack of self-will, yet no one says ill of his awesome might",
    }, {
      "name" = "udp5BahStrengthExceeds",
      "value" = true,
      "comment" = "Gods call upon him for assistance; he is obedient, though his strength always exceeds expectations and may harm commanders who fail to give him respect",
    }, {
      "name" = "udp5BahSlewReptileBarehanded",
      "value" = true,
      "comment" = "He once slew a tremendous reptilian monster from another world barehanded by breaking all of its legs - his symbol derives from that battle",
    }, {
      "name" = "udp5BahFightsWithCesti",
      "value" = true,
      "comment" = "Since then he has never used weapons or armor of any usual kind, only great studded cesti to beat his victims flat",
    }, {
      "name" = "udp5BahTanSkinGreenEyes",
      "value" = true,
      "comment" = "He is a huge, incredibly muscular orc with dirty tan skin, dull green eyes, and glistening-white tusks from gnawing on bones",
    }, {
      "name" = "udp5BahClericsNoArmor",
      "value" = true,
      "comment" = "His clerics cannot wear armor, but may use weapons as they choose",
    }, {
      "name" = "udp5BahClericsLosePowers",
      "value" = true,
      "comment" = "Clerics who lose their required strength lose their other powers, and have their spirits crushed in Bahgtru fists in the afterlife",
    }, {
      "name" = "udp5BahStrongHelpWeakOnward",
      "value" = true,
      "comment" = "Stronger clerics may help weaker clerics along to the next plane, usually without the latter permission",
    }, {
      "name" = "udp5ShaCavesBelowGehenna",
      "value" = true,
      "comment" = "The Night Lord lives in a tremendous cavern system below the fiery plain of one of the levels of Gehenna - caves said to extend infinitely, darker than the blackest night",
    }, {
      "name" = "udp5ShaOnlySeerInCaves",
      "value" = true,
      "comment" = "There no creature has sight but Shargaas himself and his orcish spirit servants",
    }, {
      "name" = "udp5ShaClimbsAnySurface",
      "value" = true,
      "comment" = "He can climb any surface, even perfectly smooth ones, without slipping",
    }, {
      "name" = "udp5ShaPerfectAmbusher",
      "value" = true,
      "comment" = "In the days he walked the earth he hid himself and his followers so well that no mortal could detect his ambushes or lairs",
    }, {
      "name" = "udp5ShaBanditPatron",
      "value" = true,
      "comment" = "Orcish bandits and half-orc thieves hold him as their patron, as do other regular orc tribes",
    }, {
      "name" = "udp5ShaMultiClassedClerics",
      "value" = true,
      "comment" = "Half-orc clerics are multi-classed cleric/thieves or cleric/assassins; shamans and witch doctors may carry a small thieving or assassination skill",
    }, {
      "name" = "udp5ShaNewMoonHolidays",
      "value" = true,
      "comment" = "The major religious holidays are the times of the new moon, when the sky is dark and cloudy",
    }, {
      "name" = "udp5IlnChiefLieutenant",
      "value" = true,
      "comment" = "When Gruumsh lacks time to command his armies he turns the job over to his chief lieutenant, the master of command and strategy",
    }, {
      "name" = "udp5IlnCovetsGruumsh",
      "value" = true,
      "comment" = "It is hinted Ilneval covets Gruumsh position as chief god; he has deposed one or two other orcish gods in his climb to power",
    }, {
      "name" = "udp5IlnCaptainsGod",
      "value" = true,
      "comment" = "He is more a captain god than a god of the common soldier - Gruumsh is preferred by chieftains and kings, Bahgtru by common warriors",
    }, {
      "name" = "udp5IlnRedIronChainmail",
      "value" = true,
      "comment" = "He wears a suit of red iron chainmail",
    }, {
      "name" = "udp5IlnImmuneToMissiles",
      "value" = true,
      "comment" = "His armor makes him untouchable by missile weapons, and he is immune to non-magical weapons as well",
    }, {
      "name" = "udp5IlnScarredAppeal",
      "value" = true,
      "comment" = "His heavily scarred face and arms only increase his appeal to his orcish followers",
    }, {
      "name" = "udp5IlnClericsRedArmor",
      "value" = true,
      "comment" = "His clerics wear red metallic armor and are expected to be good military leaders as well as good clerics",
    }, {
      "name" = "udp5IlnHalfOrcBroadswords",
      "value" = true,
      "comment" = "Half-orc clerics of Ilneval use broadswords and are multi-classed cleric/fighters",
    }, {
      "name" = "udp5YurNoMouthNeverSpeaks",
      "value" = true,
      "comment" = "The White Handed god of death and disease has no mouth and does not communicate - orcs say when White-Hands speaks to mean never",
    }, {
      "name" = "udp5YurRottingFlesh",
      "value" = true,
      "comment" = "He appears as a huge, vaguely orcish giant covered with peeling, rotting green flesh; only his hands seem normal, chalk-white in color",
    }, {
      "name" = "udp5YurGasLastsInRange",
      "value" = true,
      "comment" = "All the gas effects last while anyone stays within the cloud",
    }, {
      "name" = "udp5YurWishRecoveryOnly",
      "value" = true,
      "comment" = "The touched hit-point loss is permanent unless recovered by a wish spell on a one-point-per-wish basis",
    }, {
      "name" = "udp5YurClericWhiteGloves",
      "value" = true,
      "comment" = "His clerics wear pale white gloves made from the skins of non-orcish humanoids during ceremonies, and thin cloth-equivalent armor woven of the same materials",
    }, {
      "name" = "udp5YurMaceWhiteFist",
      "value" = true,
      "comment" = "In combat they use maces with the weapon head made in the shape of a white fist",
    }, {
      "name" = "udp5YurPlagueAppeals",
      "value" = true,
      "comment" = "When plague strikes, his clerics appeal to him for an end to the illness with great sacrifices of prisoners and slaves",
    }, {
      "name" = "udp5LutCaveMotherSpheres",
      "value" = true,
      "comment" = "She governs female orcs, fertility (Gruumsh holds the male side), caves and caverns she digs herself, servitude, primitive medicine, and the restoration of orcish morale",
    }, {
      "name" = "udp5LutClosestToBahgtru",
      "value" = true,
      "comment" = "She is the deity closest to her son Bahgtru, and he follows her commands over all others, even Gruumsh",
    }, {
      "name" = "udp5LutClawsTunnelRock",
      "value" = true,
      "comment" = "The other gods fear her great claws, so strong they can tunnel through solid rock",
    }, {
      "name" = "udp5LutServicesUnderground",
      "value" = true,
      "comment" = "Orcish clerics call her the Cave Mother and conduct her services underground",
    }, {
      "name" = "udp5LutWorshipedByMales",
      "value" = true,
      "comment" = "Though she represents female orcs, she is worshiped by males as well for her ferocity and her healing powers",
    }, {
      "name" = "udp5LutUnarmoredBlackClaws",
      "value" = true,
      "comment" = "She wears no armor; her hair and eyes are dull black and her skin dark brown, lighter on the nose and ears",
    }, {
      "name" = "udp5LutDirtRituals",
      "value" = true,
      "comment" = "Her followers rub dirt on themselves to ensure many children, and her clerics use earth in casting curative spells as a purely symbolic gesture",
    }, {
      "name" = "udp5LutBothSexesClerics",
      "value" = true,
      "comment" = "Her worship is one of the few that allows both male and female orcs to become clerics; nearly all other deities permit male clerics only",
    }, {
      "name" = "udp5LutVileRuneTribe",
      "value" = true,
      "comment" = "Her Vile Rune tribe generally dwells underground, commits fewer raids, but is especially fierce if the lair is threatened",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['udp5ProseRound']() != 790  or m['udp5StatblockFeederRound']() != 406  or m['udp5OrcishDeityCount']() != 5  or m['udp5ProsePartsTotal']() != 5  or m['udp5ProsePartRoundMin']() != 786  or m['udp5ProsePartRoundMax']() != 790  or m['udp5BahGrappleMargin']() != 4  or m['udp5BahCrushDamageMin']() != 10  or m['udp5BahCrushDamageMax']() != 120  or m['udp5BahBluntWeaponDamage']() != 1  or m['udp5BahClericStrengthMin']() != 16  or m['udp5ShaDarkSightMiles']() != 1  or m['udp5ShaShadowSkillMin']() != 5  or m['udp5ShaShadowSkillMax']() != 30  or m['udp5IlnSwordSaveMod']() != -6  or m['udp5YurGasRadiusFeet']() != 120  or m['udp5YurGasLowBandHd']() != 4  or m['udp5YurGasMidBandHd']() != 8  or m['udp5YurGasHighHitMod']() != -2  or m['udp5YurDeathMagicLevel']() != 18  or m['udp5YurTouchDamageMin']() != 3  or m['udp5YurTouchDamageMax']() != 12  or m['udp5YurTouchDiseasesMin']() != 1  or m['udp5YurTouchDiseasesMax']() != 4  or m['udp5LutClawLengthFeet']() != 4  or m['udp5LutRegenPerRound']() != 3  or m['udp5LutCurseChancePct']() != 10  or m['udp5LutCurseFatalDaysMin']() != 2  or m['udp5LutCurseFatalDaysMax']() != 7  or m['udp5LutCurseUndoWishes']() != 3  or m['udp5LutGuardHitBonus']() != 2  or m['udp5LutGuardAcPenalty']() != -2  or  m['udp5TaleOfTheLots']() != 1  or  m['udp5TaleMockedOrcs']() != 1  or  m['udp5TaleIronSpear']() != 1  or  m['udp5TaleOrcsInherit']() != 1  or  m['udp5TaleWarForWrath']() != 1  or  m['udp5TaleCorellonBattle']() != 1  or  m['udp5TaleDwarfMountainWars']() != 1  or  m['udp5TaleGoblinBattles']() != 1  or  m['udp5TaleTribesAlongCults']() != 1  or  m['udp5TaleHierarchyUnderGruumsh']() != 1  or  m['udp5TaleTribalWarfareEncouraged']() != 1  or  m['udp5BahSonOfGruumshAndLuthic']() != 1  or  m['udp5BahScornedButMighty']() != 1  or  m['udp5BahStrengthExceeds']() != 1  or  m['udp5BahSlewReptileBarehanded']() != 1  or  m['udp5BahFightsWithCesti']() != 1  or  m['udp5BahTanSkinGreenEyes']() != 1  or  m['udp5BahClericsNoArmor']() != 1  or  m['udp5BahClericsLosePowers']() != 1  or  m['udp5BahStrongHelpWeakOnward']() != 1  or  m['udp5ShaCavesBelowGehenna']() != 1  or  m['udp5ShaOnlySeerInCaves']() != 1  or  m['udp5ShaClimbsAnySurface']() != 1  or  m['udp5ShaPerfectAmbusher']() != 1  or  m['udp5ShaBanditPatron']() != 1  or  m['udp5ShaMultiClassedClerics']() != 1  or  m['udp5ShaNewMoonHolidays']() != 1  or  m['udp5IlnChiefLieutenant']() != 1  or  m['udp5IlnCovetsGruumsh']() != 1  or  m['udp5IlnCaptainsGod']() != 1  or  m['udp5IlnRedIronChainmail']() != 1  or  m['udp5IlnImmuneToMissiles']() != 1  or  m['udp5IlnScarredAppeal']() != 1  or  m['udp5IlnClericsRedArmor']() != 1  or  m['udp5IlnHalfOrcBroadswords']() != 1  or  m['udp5YurNoMouthNeverSpeaks']() != 1  or  m['udp5YurRottingFlesh']() != 1  or  m['udp5YurGasLastsInRange']() != 1  or  m['udp5YurWishRecoveryOnly']() != 1  or  m['udp5YurClericWhiteGloves']() != 1  or  m['udp5YurMaceWhiteFist']() != 1  or  m['udp5YurPlagueAppeals']() != 1  or  m['udp5LutCaveMotherSpheres']() != 1  or  m['udp5LutClosestToBahgtru']() != 1  or  m['udp5LutClawsTunnelRock']() != 1  or  m['udp5LutServicesUnderground']() != 1  or  m['udp5LutWorshipedByMales']() != 1  or  m['udp5LutUnarmoredBlackClaws']() != 1  or  m['udp5LutDirtRituals']() != 1  or  m['udp5LutBothSexesClerics']() != 1  or  m['udp5LutVileRuneTribe']() != 1",
      "note" = "",
    }, {
      "expr" = "m['udp5ProseRound']() != 790  or m['udp5StatblockFeederRound']() != 406  or m['udp5OrcishDeityCount']() != 5  or m['udp5ProsePartsTotal']() != 5  or m['udp5ProsePartRoundMin']() != 786  or m['udp5ProsePartRoundMax']() != 790",
      "note" = "the round consts (the prose round, the feeder round, the census, the close complete)",
    }, {
      "expr" = "m['udp5TaleOfTheLots']() != 1  or m['udp5TaleMockedOrcs']() != 1  or m['udp5TaleIronSpear']() != 1  or m['udp5TaleOrcsInherit']() != 1  or m['udp5TaleWarForWrath']() != 1  or m['udp5TaleCorellonBattle']() != 1  or m['udp5TaleDwarfMountainWars']() != 1  or m['udp5TaleGoblinBattles']() != 1  or m['udp5TaleTribesAlongCults']() != 1  or m['udp5TaleHierarchyUnderGruumsh']() != 1  or m['udp5TaleTribalWarfareEncouraged']() != 1",
      "note" = "the shaman-tale prose walk",
    }, {
      "expr" = "m['udp5BahGrappleMargin']() != 4  or m['udp5BahCrushDamageMin']() != 10  or m['udp5BahCrushDamageMax']() != 120  or m['udp5BahBluntWeaponDamage']() != 1  or m['udp5BahClericStrengthMin']() != 16  or m['udp5BahSonOfGruumshAndLuthic']() != 1  or m['udp5BahScornedButMighty']() != 1  or m['udp5BahStrengthExceeds']() != 1  or m['udp5BahSlewReptileBarehanded']() != 1  or m['udp5BahFightsWithCesti']() != 1  or m['udp5BahTanSkinGreenEyes']() != 1  or m['udp5BahClericsNoArmor']() != 1  or m['udp5BahClericsLosePowers']() != 1  or m['udp5BahStrongHelpWeakOnward']() != 1",
      "note" = "the Bahgtru prose walk",
    }, {
      "expr" = "m['udp5ShaDarkSightMiles']() != 1  or m['udp5ShaShadowSkillMin']() != 5  or m['udp5ShaShadowSkillMax']() != 30  or m['udp5ShaCavesBelowGehenna']() != 1  or m['udp5ShaOnlySeerInCaves']() != 1  or m['udp5ShaClimbsAnySurface']() != 1  or m['udp5ShaPerfectAmbusher']() != 1  or m['udp5ShaBanditPatron']() != 1  or m['udp5ShaMultiClassedClerics']() != 1  or m['udp5ShaNewMoonHolidays']() != 1",
      "note" = "the Shargaas prose walk",
    }, {
      "expr" = "m['udp5IlnSwordSaveMod']() != -6  or m['udp5IlnChiefLieutenant']() != 1  or m['udp5IlnCovetsGruumsh']() != 1  or m['udp5IlnCaptainsGod']() != 1  or m['udp5IlnRedIronChainmail']() != 1  or m['udp5IlnImmuneToMissiles']() != 1  or m['udp5IlnScarredAppeal']() != 1  or m['udp5IlnClericsRedArmor']() != 1  or m['udp5IlnHalfOrcBroadswords']() != 1",
      "note" = "the Ilneval prose walk",
    }, {
      "expr" = "m['udp5YurGasRadiusFeet']() != 120  or m['udp5YurGasLowBandHd']() != 4  or m['udp5YurGasMidBandHd']() != 8  or m['udp5YurGasHighHitMod']() != -2  or m['udp5YurDeathMagicLevel']() != 18  or m['udp5YurTouchDamageMin']() != 3  or m['udp5YurTouchDamageMax']() != 12  or m['udp5YurTouchDiseasesMin']() != 1  or m['udp5YurTouchDiseasesMax']() != 4  or m['udp5YurNoMouthNeverSpeaks']() != 1  or m['udp5YurRottingFlesh']() != 1  or m['udp5YurGasLastsInRange']() != 1  or m['udp5YurWishRecoveryOnly']() != 1  or m['udp5YurClericWhiteGloves']() != 1  or m['udp5YurMaceWhiteFist']() != 1  or m['udp5YurPlagueAppeals']() != 1",
      "note" = "the Yurtrus prose walk",
    }, {
      "expr" = "m['udp5LutClawLengthFeet']() != 4  or m['udp5LutRegenPerRound']() != 3  or m['udp5LutCurseChancePct']() != 10  or m['udp5LutCurseFatalDaysMin']() != 2  or m['udp5LutCurseFatalDaysMax']() != 7  or m['udp5LutCurseUndoWishes']() != 3  or m['udp5LutGuardHitBonus']() != 2  or m['udp5LutGuardAcPenalty']() != -2  or m['udp5LutCaveMotherSpheres']() != 1  or m['udp5LutClosestToBahgtru']() != 1  or m['udp5LutClawsTunnelRock']() != 1  or m['udp5LutServicesUnderground']() != 1  or m['udp5LutWorshipedByMales']() != 1  or m['udp5LutUnarmoredBlackClaws']() != 1  or m['udp5LutDirtRituals']() != 1  or m['udp5LutBothSexesClerics']() != 1  or m['udp5LutVileRuneTribe']() != 1",
      "note" = "the Luthic prose walk",
    } },
  "audit" = {
      "label" = "R790 orcish deity prose audit",
      "comment" = "THE ORCISH DEITY PROSE - part 5, the finale of the Appendix S description-paragraph close. The archive.org full-text OCR of pp. 118-121 reads the shaman tale and the five orcish blocks scan-clean: the Bahgtru grapple and cesti might, the Shargaas night caves below Gehenna, the Ilneval slaying sword and red chainmail, the Yurtrus gas envelope and death magic, and the Luthic cave-mother curse and claws. The stat-block numerics stay R406/R783; the paragraph facts ride rules/ua/uadeityprose5.h. THE FLIP: dvpProseStaysOpen returns false at last - the close is complete, and the R783 audit assertion rides with it.",
    },
}
