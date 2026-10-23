// =========================================================================================
// Adnd1 - rules/uadeityprose5.h
// THE ORCISH DEITY PROSE - part 5, the finale of the Appendix S paragraph
// close: the shaman tale plus Bahgtru, Shargaas, Ilneval, Yurtrus, and Luthic
// pin from the clean archive.org OCR read
// census 712 -> 713.
//
// Part 5 of 5 (R786 the dwarves, R787 the elves, R788 the halflings, R789 the
// gnomes). The shaman-tale intro and the five orcish blocks (pp. 118-121)
// read scan-clean in the archive.org full-text OCR: every pin below is the
// printed text. The stat-block numerics stay R406/R783; the paragraph-level
// facts pin here - the lot-drawing creation tale and the Gruumsh iron spear,
// the Bahgtru crush and the blunt bounce, the Shargaas new-moon ambush creed,
// the Ilneval captain politics and the death-sword, the Yurtrus three-band
// gas and the wish-only recovery, and the Luthic fertility dirt and the
// name-abuse curse. This round FLIPS dvpProseStaysOpen to false: every
// Appendix S description paragraph now pins, and the R783 audit assertion
// rides with it.
//
namespace rules {

// ---- the prose consts (the R790 wiring) ----

// The prose round: part 5, the orcish paragraphs - the close finale
inline int udp5ProseRound()
    { return 790; }

// The feeder round: the R406 stat blocks these paragraphs hang under
inline int udp5StatblockFeederRound()
    { return 406; }

// The orcish census: five blocks described (Bahgtru, Shargaas, Ilneval,
// Yurtrus, Luthic)
inline int udp5OrcishDeityCount()
    { return 5; }

// The five-part close is complete: dwarves, elves, halflings, gnomes, orcs
inline int udp5ProsePartsTotal()
    { return 5; }

// The close opened at R786 (the dwarven prose)
inline int udp5ProsePartRoundMin()
    { return 786; }

// and closes at R790 (the orcish prose)
inline int udp5ProsePartRoundMax()
    { return 790; }

// If he rolls 4 or more over what he needs to hit with both hands, he has
// grappled his opponent
inline int udp5BahGrappleMargin()
    { return 4; }

// A grappled victim is crushed for 10-120 points per round without rolling
// again to hit: the minimum 10
inline int udp5BahCrushDamageMin()
    { return 10; }

// and the maximum 120
inline int udp5BahCrushDamageMax()
    { return 120; }

// His skin is so thick that blunt weapons do only one point of damage before
// they bounce off
inline int udp5BahBluntWeaponDamage()
    { return 1; }

// Clerics of Bahgtru must have a minimum strength of 16 and keep physically
// fit
inline int udp5BahClericStrengthMin()
    { return 16; }

// Though blinded by sunlight, he sees perfectly in darkness out to a range of
// a mile or more
inline int udp5ShaDarkSightMiles()
    { return 1; }

// Rumored shaman/witch-doctor thieving skill of 5-30 percent success: the
// minimum 5
inline int udp5ShaShadowSkillMin()
    { return 5; }

// and the maximum 30
inline int udp5ShaShadowSkillMax()
    { return 30; }

// His sword slays all non-orcs it strikes (save versus death at -6)
inline int udp5IlnSwordSaveMod()
    { return -6; }

// He is surrounded by stinking gases out to 120 feet
inline int udp5YurGasRadiusFeet()
    { return 120; }

// Beings up to and including 4 hit dice/levels are affected as by dust of
// sneezing and choking
inline int udp5YurGasLowBandHd()
    { return 4; }

// Those up to 8 hit dice/levels as if struck by a symbol of pain
inline int udp5YurGasMidBandHd()
    { return 8; }

// Those of higher level suffer -2 to hit with no saving throw
inline int udp5YurGasHighHitMod()
    { return -2; }

// He uses all death-magic spells of 18th-level magic-users
inline int udp5YurDeathMagicLevel()
    { return 18; }

// A being he strikes loses 3-12 hit points: the minimum 3
inline int udp5YurTouchDamageMin()
    { return 3; }

// and the maximum 12
inline int udp5YurTouchDamageMax()
    { return 12; }

// and catches 1-4 random diseases: the minimum 1
inline int udp5YurTouchDiseasesMin()
    { return 1; }

// and the maximum 4
inline int udp5YurTouchDiseasesMax()
    { return 4; }

// Her unbreakable black claws are four feet long
inline int udp5LutClawLengthFeet()
    { return 4; }

// In contact with the ground she regenerates 3 hit points per round
inline int udp5LutRegenPerRound()
    { return 3; }

// A 10 percent chance that abuse of her name renders the abuser susceptible
// to any disease
inline int udp5LutCurseChancePct()
    { return 10; }

// The next ailment proves fatal within 2-7 days: the minimum 2
inline int udp5LutCurseFatalDaysMin()
    { return 2; }

// and the maximum 7
inline int udp5LutCurseFatalDaysMax()
    { return 7; }

// Only the power of three wish spells applied while the victim still lives
// can undo the curse
inline int udp5LutCurseUndoWishes()
    { return 3; }

// Orcs guarding her clerics gain a +2 to-hit bonus from their ferocity and
// madness
inline int udp5LutGuardHitBonus()
    { return 2; }

// but this also causes a -2 penalty to their armor classes
inline int udp5LutGuardAcPenalty()
    { return -2; }

// ---- the prose bools (the R790 wiring) ----

// The shamans tell how the gods drew lots for the parts of the world: humans
// where they pleased, elves the green forests, dwarves the high mountains,
// gnomes the rocky sunlit hills, halflings the fields and meadows
inline bool udp5TaleOfTheLots()
    { return true; }

// The assembled gods turned to the orcish gods and laughed: all the lots are
// taken, there is no place left
inline bool udp5TaleMockedOrcs()
    { return true; }

// Gruumsh One-Eye lifted his great iron spear over the world - piercing the
// mountains, splitting the hills, gouging the meadows - and claimed those
// places for the orcs
inline bool udp5TaleIronSpear()
    { return true; }

// He-Who-Watches roared that orcs will cover the world, slay all the
// collected peoples, and inherit it
inline bool udp5TaleOrcsInherit()
    { return true; }

// This is why orcs make war, ceaseless and endless: war for the wrath of
// Gruumsh
inline bool udp5TaleWarForWrath()
    { return true; }

// Corellon Larethian tried to shoot out Gruumsh eye and failed; because of
// that battle orcs of all sects hate elves more than all other non-orc races
inline bool udp5TaleCorellonBattle()
    { return true; }

// The shamans tales of the battle between the dwarven and orcish gods for
// ownership of the mountains would weary the most ardent listener
inline bool udp5TaleDwarfMountainWars()
    { return true; }

// The eternal battles on the plains of the Nine Hells between the goblins and
// orcs, each side led by their respective gods
inline bool udp5TaleGoblinBattles()
    { return true; }

// The division of orcs into separate tribes (Evil Eye, Death Moon, Broken
// Bone, etc.) is usually made along cult lines - the tribal symbol is the
// holy symbol of the patron god
inline bool udp5TaleTribesAlongCults()
    { return true; }

// There are a large number of orcish gods in a rigid chain of command with
// Gruumsh at the top; the relative positions vary with the shaman doing the
// telling
inline bool udp5TaleHierarchyUnderGruumsh()
    { return true; }

// Warfare between tribes is encouraged to some extent - eliminating the unfit
// and weak, promoting the survival and growth of the strong
inline bool udp5TaleTribalWarfareEncouraged()
    { return true; }

// He is the son of Gruumsh and Luthic the Cave Mother
inline bool udp5BahSonOfGruumshAndLuthic()
    { return true; }

// Scorned and derided for his stupidity and lack of self-will, yet no one
// says ill of his awesome might
inline bool udp5BahScornedButMighty()
    { return true; }

// Gods call upon him for assistance; he is obedient, though his strength
// always exceeds expectations and may harm commanders who fail to give him
// respect
inline bool udp5BahStrengthExceeds()
    { return true; }

// He once slew a tremendous reptilian monster from another world barehanded
// by breaking all of its legs - his symbol derives from that battle
inline bool udp5BahSlewReptileBarehanded()
    { return true; }

// Since then he has never used weapons or armor of any usual kind, only great
// studded cesti to beat his victims flat
inline bool udp5BahFightsWithCesti()
    { return true; }

// He is a huge, incredibly muscular orc with dirty tan skin, dull green eyes,
// and glistening-white tusks from gnawing on bones
inline bool udp5BahTanSkinGreenEyes()
    { return true; }

// His clerics cannot wear armor, but may use weapons as they choose
inline bool udp5BahClericsNoArmor()
    { return true; }

// Clerics who lose their required strength lose their other powers, and have
// their spirits crushed in Bahgtru fists in the afterlife
inline bool udp5BahClericsLosePowers()
    { return true; }

// Stronger clerics may help weaker clerics along to the next plane, usually
// without the latter permission
inline bool udp5BahStrongHelpWeakOnward()
    { return true; }

// The Night Lord lives in a tremendous cavern system below the fiery plain of
// one of the levels of Gehenna - caves said to extend infinitely, darker than
// the blackest night
inline bool udp5ShaCavesBelowGehenna()
    { return true; }

// There no creature has sight but Shargaas himself and his orcish spirit
// servants
inline bool udp5ShaOnlySeerInCaves()
    { return true; }

// He can climb any surface, even perfectly smooth ones, without slipping
inline bool udp5ShaClimbsAnySurface()
    { return true; }

// In the days he walked the earth he hid himself and his followers so well
// that no mortal could detect his ambushes or lairs
inline bool udp5ShaPerfectAmbusher()
    { return true; }

// Orcish bandits and half-orc thieves hold him as their patron, as do other
// regular orc tribes
inline bool udp5ShaBanditPatron()
    { return true; }

// Half-orc clerics are multi-classed cleric/thieves or cleric/assassins;
// shamans and witch doctors may carry a small thieving or assassination skill
inline bool udp5ShaMultiClassedClerics()
    { return true; }

// The major religious holidays are the times of the new moon, when the sky is
// dark and cloudy
inline bool udp5ShaNewMoonHolidays()
    { return true; }

// When Gruumsh lacks time to command his armies he turns the job over to his
// chief lieutenant, the master of command and strategy
inline bool udp5IlnChiefLieutenant()
    { return true; }

// It is hinted Ilneval covets Gruumsh position as chief god; he has deposed
// one or two other orcish gods in his climb to power
inline bool udp5IlnCovetsGruumsh()
    { return true; }

// He is more a captain god than a god of the common soldier - Gruumsh is
// preferred by chieftains and kings, Bahgtru by common warriors
inline bool udp5IlnCaptainsGod()
    { return true; }

// He wears a suit of red iron chainmail
inline bool udp5IlnRedIronChainmail()
    { return true; }

// His armor makes him untouchable by missile weapons, and he is immune to
// non-magical weapons as well
inline bool udp5IlnImmuneToMissiles()
    { return true; }

// His heavily scarred face and arms only increase his appeal to his orcish
// followers
inline bool udp5IlnScarredAppeal()
    { return true; }

// His clerics wear red metallic armor and are expected to be good military
// leaders as well as good clerics
inline bool udp5IlnClericsRedArmor()
    { return true; }

// Half-orc clerics of Ilneval use broadswords and are multi-classed
// cleric/fighters
inline bool udp5IlnHalfOrcBroadswords()
    { return true; }

// The White Handed god of death and disease has no mouth and does not
// communicate - orcs say when White-Hands speaks to mean never
inline bool udp5YurNoMouthNeverSpeaks()
    { return true; }

// He appears as a huge, vaguely orcish giant covered with peeling, rotting
// green flesh; only his hands seem normal, chalk-white in color
inline bool udp5YurRottingFlesh()
    { return true; }

// All the gas effects last while anyone stays within the cloud
inline bool udp5YurGasLastsInRange()
    { return true; }

// The touched hit-point loss is permanent unless recovered by a wish spell on
// a one-point-per-wish basis
inline bool udp5YurWishRecoveryOnly()
    { return true; }

// His clerics wear pale white gloves made from the skins of non-orcish
// humanoids during ceremonies, and thin cloth-equivalent armor woven of the
// same materials
inline bool udp5YurClericWhiteGloves()
    { return true; }

// In combat they use maces with the weapon head made in the shape of a white
// fist
inline bool udp5YurMaceWhiteFist()
    { return true; }

// When plague strikes, his clerics appeal to him for an end to the illness
// with great sacrifices of prisoners and slaves
inline bool udp5YurPlagueAppeals()
    { return true; }

// She governs female orcs, fertility (Gruumsh holds the male side), caves and
// caverns she digs herself, servitude, primitive medicine, and the
// restoration of orcish morale
inline bool udp5LutCaveMotherSpheres()
    { return true; }

// She is the deity closest to her son Bahgtru, and he follows her commands
// over all others, even Gruumsh
inline bool udp5LutClosestToBahgtru()
    { return true; }

// The other gods fear her great claws, so strong they can tunnel through
// solid rock
inline bool udp5LutClawsTunnelRock()
    { return true; }

// Orcish clerics call her the Cave Mother and conduct her services
// underground
inline bool udp5LutServicesUnderground()
    { return true; }

// Though she represents female orcs, she is worshiped by males as well for
// her ferocity and her healing powers
inline bool udp5LutWorshipedByMales()
    { return true; }

// She wears no armor; her hair and eyes are dull black and her skin dark
// brown, lighter on the nose and ears
inline bool udp5LutUnarmoredBlackClaws()
    { return true; }

// Her followers rub dirt on themselves to ensure many children, and her
// clerics use earth in casting curative spells as a purely symbolic gesture
inline bool udp5LutDirtRituals()
    { return true; }

// Her worship is one of the few that allows both male and female orcs to
// become clerics; nearly all other deities permit male clerics only
inline bool udp5LutBothSexesClerics()
    { return true; }

// Her Vile Rune tribe generally dwells underground, commits fewer raids, but
// is especially fierce if the lair is threatened
inline bool udp5LutVileRuneTribe()
    { return true; }

}   // namespace rules
