// =========================================================================================
// Adnd1 - rules/klv.h
// the Finnish mythos - the D&DG walk round ten, print pp. 57-62: twenty
// beings from Vainamoinen the greatest hero and minstrel of the Kalevala to
// the Air Maiden of Ukko, the six heroes (Vainamoinen, Ilmarinen,
// Lemminkainen, Kullervo, Tiera, the Son of Pohjola), the two servants (the
// Water Dwarf of Ahto, the Air Maiden of Ukko), the three magic items of the
// mythos intro (the Great Tree, the Magic Wool, the Rake of Iron), and the
// Kalevala doctrine, across seven planes.
// census 780 -> 781.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 058-063; the second printing); the
// collation voice: the archive.org 1st-print derivative
// (deities-demigods-1st-print, djvu.xml word geometry at 600dpi, segs 57-62).
// The adjudications: the KULLERVO TIERA FOLD SWAP (the Termux full-text
// interleave gave Kullervo the lawful good ranger block and Tiera the chaotic
// neutral block; the djvu column geometry, the tsv clean columns and the
// prose settled Kullervo as the chaotic neutral S:19(+3,+7) I:15 W:6 D:18
// C:19 CH:14 fighter-thief-bard and Tiera as the lawful good S:17(+1,+1)
// ranger shield man of Lemminkainen), the Lemminkainen MOVE 12 (the djvu and
// the tsv word against the Termux full-text 15), the Louhi HP 110 (the tsv
// against the djvu 1170 garble; the 81px token too narrow for four glyphs),
// the Kiputytto attack 1 (the 11px single glyph against the djvu 17), the
// psionic pipe of Mielikki (the 8px single stroke read as class I), the
// negative charisma of Tuonetar (both voices print the minus six), the Hiisi
// W:10 and the Kullervo W:6 (both voices agree on the odd prints), the
// foot-mark size decodes (Lemminkainen 6 foot 2, Kullervo 6 foot 1, Tiera 5
// foot 4, Mielikki 5 foot 1), the triple-slash moves of Ahto 18/24/24 and
// Tuoni 18/18/48, the Tuonetar fear radius 30 feet (the djvu feet against the
// tsv inches), and the Surka armor class minus two (the 64px dash-two token
// against the bare 2 garble).
//
namespace rules {

// ---- the R858 census ----

// the Finnish mythos round: the D&DG walk round ten, print pp. 57-62
inline int klvRound()
    { return 858; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int klvPrintStart()
    { return 57; }

// the last print page of the mythos
inline int klvPrintEnd()
    { return 62; }

// the twenty beings of the mythos (Vainamoinen through the Air Maiden: six
// heroes, five greater gods, four lesser gods, three demigods, two servants)
inline int klvBeingCount()
    { return 20; }

// the four grids (combat, class, ability, roster)
inline int klvTableCount()
    { return 4; }

// no chains this round: no banded thresholds printed in the mythos
inline int klvChainCount()
    { return 0; }

// the registry floor holds: zero registry defs touched this round
inline int klvRegistryFloor()
    { return 995; }

// the combat grid rows (one per being)
inline int klvCbtRows()
    { return 20; }

// the class grid rows
inline int klvClsRows()
    { return 20; }

// the ability grid rows
inline int klvAbiRows()
    { return 20; }

// the roster grid rows
inline int klvRosRows()
    { return 20; }

// the seven printed planes: Prime Material, Elemental Water, Tarterus,
// Gehenna, Pandemonium, the Twin Paradises, Concordant Opposition
inline int klvPlaneCount()
    { return 7; }

// the six heroes (Vainamoinen, Ilmarinen, Lemminkainen, Kullervo, Tiera, the
// Son of Pohjola)
inline int klvHeroCount()
    { return 6; }

// the two servant beings (the Water Dwarf of Ahto, the Air Maiden of Ukko)
inline int klvServantCount()
    { return 2; }

// the five greater powers (Ahto, Hiisi, Tuonetar, Tuoni, Ukko)
inline int klvGreaterCount()
    { return 5; }

// the four lesser powers (Ilmatar, Louhi, Mielikki, Untamo)
inline int klvLesserCount()
    { return 4; }

// the three demigods (Kiputytto, Loviatar, Surma)
inline int klvDemigodCount()
    { return 3; }

// the three magic items of the mythos intro (the Great Tree, the Magic Wool,
// the Rake of Iron)
inline int klvArtifactCount()
    { return 3; }

// the four psionic classes printed this round (I, II, IV, VI)
inline int klvPsiClassKinds()
    { return 4; }

// the thirteen printed bard levels across the roster (the
// all-heroes-are-bards doctrine of the Kalevala)
inline int klvBardCount()
    { return 13; }

// ---- the Kalevala intro ----

// the stories magnificently told in The Kalevala, the Finnish national epic
inline bool klvKalevalaTheEpic()
    { return true; }

// the tales focus on the exploits of the heroes rather than the gods
inline bool klvTalesFocusOnHeroes()
    { return true; }

// the heroes of The Kalevala are very powerful, with abilities beyond those
// of mortal men
inline bool klvHeroesBeyondMortal()
    { return true; }

// most of the heroes have divine ancestors
inline bool klvMostHaveDivineAncestors()
    { return true; }

// only Vainamoinen is powerful and skillful enough to successfully meddle
// with the gods
inline bool klvOnlyVainamoinenMeddles()
    { return true; }

// the core of the epic: the continuing conflict between Kalevala the land of
// good heroes and Pohjola the land of evil and wizardry
inline bool klvKalevalaVersusPohjola()
    { return true; }

// all of the heroes are great bards and make mighty magics with their songs
inline bool klvAllHeroesGreatBards()
    { return true; }

// the clerics of the gods consider themselves above normal men, generally
// well respected and or feared
inline bool klvClericsAboveNormalMen()
    { return true; }

// the clerics have no qualms about using spells to chastise those who offend
// them or threaten their power
inline bool klvClericsChastiseWithSpells()
    { return true; }

// ---- the Great Tree walk ----

// each branch can be made into 1-10 magic arrows: the floor
inline int klvTreeArrowsLo()
    { return 1; }

// the 1-10 magic arrow ceiling per branch
inline int klvTreeArrowsHi()
    { return 10; }

// each branch can be made into a +1 magical spear
inline int klvTreeSpearPlus()
    { return 1; }

// the fragments of the Great Tree can be used to make various magic items
inline bool klvTreeFragmentsMakeItems()
    { return true; }

// the wood merely supplies the raw materials: it cannot just be cut into the
// shape of magic weapons
inline bool klvTreeRawMaterialsOnly()
    { return true; }

// the wood still must be enchanted properly
inline bool klvTreeMustBeEnchanted()
    { return true; }

// ---- the Magic Wool walk ----

// the wool rubbed against the flesh produces a flock of 30 sheep
inline int klvWoolSheepCount()
    { return 30; }

// the flock comes once a month
inline int klvWoolPerMonth()
    { return 1; }

// certain mighty persons of Pohjola have some of this material
inline bool klvWoolOfPohjola()
    { return true; }

// the rubbing against the flesh produces the flock
inline bool klvWoolRubbedOnFlesh()
    { return true; }

// ---- the Rake of Iron walk ----

// the rake appears 3 feet in length: 36 inches
inline int klvRakeRestLengthInches()
    { return 36; }

// the rake can elongate as far as the user wishes, up to 200 yards
inline int klvRakeElongateYards()
    { return 200; }

// the 10 percent chance per stroke of raking out a specific item from under
// the water
inline int klvRakeStrokePct()
    { return 10; }

// the approximate location of the item must be known
inline bool klvRakeNeedsApproxLocation()
    { return true; }

// the rake was used by Lemminkainen mother in recovering his body, which was
// deep under water
inline bool klvRakeOfLemminkainensMother()
    { return true; }

// ---- the Vainamoinen walk ----

// the +5 battle axe wielded alternately with the sword
inline int klvVainaAxePlus()
    { return 5; }

// the intelligent +3 sword of sharpness
inline int klvVainaSwordPlus()
    { return 3; }

// the sword casts a fear spell once per day
inline int klvVainaSwordFearPerDay()
    { return 1; }

// the girdle of cloud giant strength gives him a strength of 23
inline int klvVainaGirdleStr()
    { return 23; }

// he appears as an elderly fighter wearing +5 leather armor
inline int klvVainaArmorPlus()
    { return 5; }

// the monster summoning I-IV at will: the floor
inline int klvVainaSummoningLo()
    { return 1; }

// the monster summoning I-IV at will: the ceiling
inline int klvVainaSummoningHi()
    { return 4; }

// his special horse: armor class 3
inline int klvVainaHorseAC()
    { return 3; }

// the horse move of 24 inches
inline int klvVainaHorseMV()
    { return 24; }

// the horse hit dice
inline int klvVainaHorseHD()
    { return 10; }

// the horse hit points
inline int klvVainaHorseHp()
    { return 59; }

// the horse attacks per round
inline int klvVainaHorseAt()
    { return 3; }

// the horse damage of 1-10/1-10/1-6: the 1-10 ceiling (twice printed)
inline int klvVainaHorseDmgHi()
    { return 10; }

// the third horse damage ceiling of 1-6
inline int klvVainaHorseDmgThirdHi()
    { return 6; }

// the horse pulls sledges drawing up to 300,000 gp with no appreciable loss
// of speed
inline int klvVainaHorseGpLimit()
    { return 300000; }

// the canoe-sized boat holds up to 60,000 gp of weight, much as a bag of
// holding
inline int klvVainaBoatGpLimit()
    { return 60000; }

// the boat volume of 1,000 cubic feet
inline int klvVainaBoatCubicFeet()
    { return 1000; }

// Vainamoinen is the Kalevala greatest hero and minstrel
inline bool klvVainaGreatestHero()
    { return true; }

// he is called the Son of the Wind by friends and enemies alike
inline bool klvVainaSonOfTheWind()
    { return true; }

// the sword of sharpness talks
inline bool klvVainaSwordTalks()
    { return true; }

// his first crossbow combines the abilities of crossbows of accuracy,
// distance and speed
inline bool klvVainaCrossbowCombo()
    { return true; }

// the other crossbow, once started, loads and fires itself at his enemies
// until stopped, much like a dancing sword
inline bool klvVainaCrossbowSelfFiring()
    { return true; }

// he can shape change at will
inline bool klvVainaShapeChange()
    { return true; }

// he can dispel magic at will
inline bool klvVainaDispelMagic()
    { return true; }

// he is immune to the effects of charm-type spells
inline bool klvVainaCharmImmune()
    { return true; }

// he is immune to disease
inline bool klvVainaDiseaseImmune()
    { return true; }

// the special horse is immune to magical attacks
inline bool klvVainaHorseMagicalImmune()
    { return true; }

// the horse pulls his sledges across land or water
inline bool klvVainaHorseLandOrWater()
    { return true; }

// ---- the Ahto walk ----

// the +4 sickle that strikes for 2-20 points of damage
inline int klvAhtoSicklePlus()
    { return 4; }

// the sickle damage floor
inline int klvAhtoSickleDmgLo()
    { return 2; }

// the sickle damage ceiling
inline int klvAhtoSickleDmgHi()
    { return 20; }

// he can use any spell involving wind or water as a 40th level spell caster
inline int klvAhtoSpellLevel()
    { return 40; }

// the magic resistance of 100 percent in water
inline int klvAhtoMRWater()
    { return 100; }

// the magic resistance of 50 percent otherwise
inline int klvAhtoMROtherwise()
    { return 50; }

// the middle 24 of the triple-slash 18/24/24 move print (both alts read 24 -
// flagged)
inline int klvAhtoMoveMid()
    { return 24; }

// Ahto is the god of the seas and waters, a greater god
inline bool klvAhtoGodOfSeas()
    { return true; }

// he appears to the world as a green-bearded man
inline bool klvAhtoGreenBearded()
    { return true; }

// he rarely reveals himself to mortals
inline bool klvAhtoRarelyReveals()
    { return true; }

// when called on to aid mortals he sends the Water Dwarf
inline bool klvAhtoSendsTheWaterDwarf()
    { return true; }

// sacrifices are made to Ahto by placing the objects into deep water and
// calling on him
inline bool klvAhtoSacrificesDeepWater()
    { return true; }

// ---- the Water Dwarf walk ----

// the 25 percent chance that Ahto will aid the dwarf in any difficulty
inline int klvDwarfAidPct()
    { return 25; }

// the 100 percent chance that the god will appear if the dwarf is slain
inline int klvDwarfAppearPct()
    { return 100; }

// the +3 mace for hand-to-hand combat
inline int klvDwarfMacePlus()
    { return 3; }

// the regeneration of 5 points per melee round
inline int klvDwarfRegen()
    { return 5; }

// the regeneration works when within 50 feet of a body of water
inline int klvDwarfRegenRangeFeet()
    { return 50; }

// the Water Dwarf is the shield man of Ahto
inline bool klvDwarfAhtosShieldMan()
    { return true; }

// he uses a crossbow of accuracy at twice the usual rate of fire
inline bool klvDwarfCrossbowTwiceRate()
    { return true; }

// the dwarf is often sent on missions for Ahto, carefully observed by the god
inline bool klvDwarfSentOnMissions()
    { return true; }

// ---- the Ilmarinen walk ----

// the +4 hammer that strikes for 1-10 points of damage
inline int klvIlmaHammerPlus()
    { return 4; }

// the hammer damage floor
inline int klvIlmaHammerDmgLo()
    { return 1; }

// the hammer damage ceiling
inline int klvIlmaHammerDmgHi()
    { return 10; }

// the +4 leather armor
inline int klvIlmaArmorPlus()
    { return 4; }

// the magical sledge pulls itself at a rate of 21 and travels over land or
// water
inline int klvIlmaSledgeRate()
    { return 21; }

// Ilmarinen is a blacksmith of great magical power, with the ability to
// create mighty magic items of many sorts
inline bool klvIlmaBlacksmith()
    { return true; }

// he is a massively built man
inline bool klvIlmaMassivelyBuilt()
    { return true; }

// when traveling incognito or among enemies he will yoke deer to the front of
// the sledge to conceal its magical nature
inline bool klvIlmaYokesDeer()
    { return true; }

// ---- the Hiisi walk ----

// the giant club does 4-40 points per strike: the floor
inline int klvHiisiClubDmgLo()
    { return 4; }

// the club damage ceiling
inline int klvHiisiClubDmgHi()
    { return 40; }

// he sends in a group of 1-10 evil heroes: the floor
inline int klvHiisiEvilHeroesLo()
    { return 1; }

// the evil hero group ceiling
inline int klvHiisiEvilHeroesHi()
    { return 10; }

// each evil hero wears armor class 2
inline int klvHiisiEvilHeroAC()
    { return 2; }

// each evil hero is 4th level, armed with swords
inline int klvHiisiEvilHeroLevel()
    { return 4; }

// Hiisi is the god of evil, a greater god
inline bool klvHiisiGodOfEvil()
    { return true; }

// he always appears as a huge, richly robed man with coarse features
inline bool klvHiisiHugeRobedMan()
    { return true; }

// he constantly aids evil creatures
inline bool klvHiisiAidsEvilCreatures()
    { return true; }

// he does not like to directly enter battle, preferring to sit on the
// sidelines while sending in the evil heroes
inline bool klvHiisiAvoidsDirectBattle()
    { return true; }

// evil beings are unable to do any damage to him either directly or
// indirectly
inline bool klvHiisiEvilCannotHurtHim()
    { return true; }

// Hiisi prints single class lines (15th level cleric and 15th level
// illusionist over a Nil magic-user), not the in-each pair
inline bool klvHiisiInEachCleric()
    { return false; }

// ---- the Ilmatar walk ----

// her sledge moves by itself on the land, air and water at a rate of 24
inline int klvIlmatarSledgeRate()
    { return 24; }

// Ilmatar is the goddess of mothers, a lesser goddess
inline bool klvIlmatarGoddessOfMothers()
    { return true; }

// she is described as the Daughter of the Air
inline bool klvIlmatarDaughterOfTheAir()
    { return true; }

// she is the mother of Vainamoinen
inline bool klvIlmatarMotherOfVainamoinen()
    { return true; }

// she can instantly gate in any Finnish god or goddess, and they will help
// her or her son as they all owe her favors
inline bool klvIlmatarGatesAnyFinnishGod()
    { return true; }

// her hand-sized ball, carried in a copper box, has written upon it all the
// legends of creation and the spells used in that formation
inline bool klvIlmatarBallOfCreation()
    { return true; }

// she is able to use the ball to know all the powers and abilities of any
// being that ever existed
inline bool klvIlmatarKnowsAllBeings()
    { return true; }

// ---- the Kiputytto walk ----

// the sickness takes away 5 hit points from its victim per turn until dead or
// cured (saving throw applicable)
inline int klvKipuSicknessHpPerTurn()
    { return 5; }

// her symbol is a battered metal bowl over a flame (the 0 rides the prose
// pin; the symbol cells need no number this round)
inline int klvKipuSymbolBowl()
    { return 0; }

// Kiputytto is the goddess of sickness, the Mother of the Plague, a
// demigoddess
inline bool klvKipuGoddessOfSickness()
    { return true; }

// anything that touches her will rot away, including swords, armor, claw or
// fang
inline bool klvKipuTouchRots()
    { return true; }

// she is very fond of floating above a battle invisibly and affecting those
// that have minor wounds and are forced to retreat
inline bool klvKipuFloatsInvisible()
    { return true; }

// she appears most often as a black skinned, twisted old crone with a scarred
// face
inline bool klvKipuTwistedCrone()
    { return true; }

// the members of her cult seem to have all suffered from some wasting disease
// and bear the marks on their faces
inline bool klvKipuCultWastedDisease()
    { return true; }

// her 14th level cleric/druid and 15th level magic-user/illusionist spells
// are harming spells only
inline bool klvKipuHarmingSpellsOnly()
    { return true; }

// ---- the Lemminkainen walk ----

// the +3 javelin of distance
inline int klvLemmJavelinPlus()
    { return 3; }

// the javelin range of 36 inches
inline int klvLemmJavelinRangeInches()
    { return 36; }

// the +3 bow
inline int klvLemmBowPlus()
    { return 3; }

// the +5 sword
inline int klvLemmSwordPlus()
    { return 5; }

// the +3 dagger
inline int klvLemmDaggerPlus()
    { return 3; }

// the +4 chainmail
inline int klvLemmChainmailPlus()
    { return 4; }

// the snowshoes of speed and traveling enable him to proceed at a rate of 24
// on snow-covered ground
inline int klvLemmSnowshoeRate()
    { return 24; }

// Lemminkainen is jovial and reckless, constantly getting himself into
// serious scrapes
inline bool klvLemmJovialReckless()
    { return true; }

// he has mastered the art of shape changing
inline bool klvLemmShapeChangeMaster()
    { return true; }

// bears and wolves will not attack him
inline bool klvLemmBeastsWillNotAttack()
    { return true; }

// he is immune to poisons of all types
inline bool klvLemmPoisonImmune()
    { return true; }

// the bow comes with a quiver of animal slaying arrows
inline bool klvLemmBowAnimalSlaying()
    { return true; }

// the +5 sword is both a sword of sharpness and a flaming sword
inline bool klvLemmSwordSharpnessFlaming()
    { return true; }

// he uses a girdle of frost giant strength
inline bool klvLemmFrostGirdle()
    { return true; }

// his magical brush, left at home on adventures, sheds blood when
// Lemminkainen is in trouble
inline bool klvLemmBrushShedsBlood()
    { return true; }

// by that token his mother, a mighty magic-user in her own right, knows that
// she should send aid
inline bool klvLemmMotherSendsAid()
    { return true; }

// ---- the Kullervo walk ----

// the +2 axe of sharpness (as the sword of the same name)
inline int klvKullAxePlus()
    { return 2; }

// the axe strikes for 1-10: the floor
inline int klvKullAxeDmgLo()
    { return 1; }

// the axe damage ceiling
inline int klvKullAxeDmgHi()
    { return 10; }

// Kullervo is the foil of the good heroes of Kalevala, doomed to eventually
// betray Kalevala and become evil, and acts as if he knows it
inline bool klvKullervoTheFoil()
    { return true; }

// Kullervo can shape change
inline bool klvKullervoShapeChange()
    { return true; }

// Kullervo is immune to fire-based attacks
inline bool klvKullervoFireImmune()
    { return true; }

// ---- the Tiera walk ----

// the +3 spear that glows when a lie is told in its presence
inline int klvTieraSpearPlus()
    { return 3; }

// the spear does 1-10 points of damage: the floor
inline int klvTieraSpearDmgLo()
    { return 1; }

// the spear damage ceiling
inline int klvTieraSpearDmgHi()
    { return 10; }

// Tiera is the shield man of Lemminkainen
inline bool klvTieraTheShieldMan()
    { return true; }

// this fighter will always aid his master to the best of his ability
inline bool klvTieraAidsHisMaster()
    { return true; }

// ---- the Louhi walk ----

// she can summon four invisible fighters at will to defend her
inline int klvLouhiFighterCount()
    { return 4; }

// each fighter wears armor class 7
inline int klvLouhiFighterAC()
    { return 7; }

// the fighters are effectively armor class 3 because invisible
inline int klvLouhiFighterEffAC()
    { return 3; }

// each fighter is level 6
inline int klvLouhiFighterLevel()
    { return 6; }

// each fighter has 27 hit points, armed with spears
inline int klvLouhiFighterHp()
    { return 27; }

// Louhi is the old crone of Pohjola, a lesser goddess
inline bool klvLouhiOldCroneOfPohjola()
    { return true; }

// she rules the evil land of Pohjola with an iron hand
inline bool klvLouhiIronHand()
    { return true; }

// she opposes all of the good heroes of Kalevala and works continuously for
// their downfall
inline bool klvLouhiOpposesTheHeroes()
    { return true; }

// of the four fighters two will guard her while two attack the enemy
inline bool klvLouhiTwoGuardTwoAttack()
    { return true; }

// she is very adept at the creation of poison and sleep potions, which she
// uses on guests she wants to eliminate
inline bool klvLouhiPoisonAndSleepPotions()
    { return true; }

// ---- the Loviatar walk ----

// the printed example: the worst pain re-experienced, as 49 hit points of
// damage from a fireball
inline int klvLoviPainExampleHp()
    { return 49; }

// Loviatar is the goddess of hurt, the Maiden of Pain, a demigoddess
inline bool klvLoviatarMaidenOfPain()
    { return true; }

// she is described as a beautiful cold maiden, usually dressed in white silks
inline bool klvLoviatarColdMaiden()
    { return true; }

// when she speaks a cold wind blows
inline bool klvLoviatarColdWindSpeaks()
    { return true; }

// her main concern is the inflicting of pain
inline bool klvLoviatarInflictsPain()
    { return true; }

// she owns a dagger of ice that makes her immune to all magical spells
inline bool klvLoviatarDaggerOfIce()
    { return true; }

// when attacked or when magic is used against her, the attacker will once
// again re-experience the worst pain he or she has ever suffered (no saving
// throw)
inline bool klvLoviatarPainReflection()
    { return true; }

// a second attack on the part of that character would result in the second
// most painful thing hurting him, and so on
inline bool klvLoviatarSecondWorstPain()
    { return true; }

// ---- the Mielikki walk ----

// the 1 percent chance that she will aid her dryads when they are in extreme
// danger within the bounds of the forest
inline int klvMielDryadAidPct()
    { return 1; }

// the 5 percent chance that she will attack those that try to destroy her
// domain, for whatever reason
inline int klvMielAttackPct()
    { return 5; }

// men like woodcutters must plant two trees for every one that they cut down,
// or eventually face her wrath
inline int klvMielTreeRatio()
    { return 2; }

// she automatically negates all charm-type spells within a 30 yard radius of
// her body
inline int klvMielCharmNegateYards()
    { return 30; }

// Mielikki is the goddess of nature, the Mistress of the Forest, a lesser
// goddess
inline bool klvMielikkiMistressOfTheForest()
    { return true; }

// the goddess is always dressed in a green gossamer gown, even in the coldest
// of winters, and is always surrounded with summer songbirds
inline bool klvMielikkiGreenGossamer()
    { return true; }

// she watches over rangers and all creatures of the forest, especially dryads
inline bool klvMielikkiWatchesRangers()
    { return true; }

// no creature that lives in the wilds is able to hurt her, even if controlled
inline bool klvMielikkiWildsCannotHurtHer()
    { return true; }

// she is not affected by clerical spells of any type
inline bool klvMielikkiClericalImmune()
    { return true; }

// when magic has failed to hurt her enemies, she has been known to summon
// huge packs of wolves and flights of hawks to attack despoilers of the
// forest
inline bool klvMielikkiSummonsWolvesAndHawks()
    { return true; }

// ---- the Son of Pohjola walk ----

// his sword does 2-20 points of damage per strike and is a +3 weapon
inline int klvSonSwordPlus()
    { return 3; }

// the sword damage floor
inline int klvSonSwordDmgLo()
    { return 2; }

// the sword damage ceiling
inline int klvSonSwordDmgHi()
    { return 20; }

// the giant wolf from his mother: armor class 5
inline int klvSonWolfAC()
    { return 5; }

// the wolf move of 18 inches
inline int klvSonWolfMV()
    { return 18; }

// the wolf hit dice
inline int klvSonWolfHD()
    { return 6; }

// the wolf hit points
inline int klvSonWolfHp()
    { return 40; }

// the wolf attacks per round
inline int klvSonWolfAt()
    { return 1; }

// the wolf damage of 1-10: the floor
inline int klvSonWolfDmgLo()
    { return 1; }

// the wolf damage ceiling
inline int klvSonWolfDmgHi()
    { return 10; }

// the Son of Pohjola is an evil hero
inline bool klvSonEvilHero()
    { return true; }

// this son of Louhi was a leader of the people of Pohjola
inline bool klvSonLeaderOfPohjola()
    { return true; }

// he is a savage enemy to Lemminkainen and the other good heroes of Kalevala
inline bool klvSonEnemyOfLemminkainen()
    { return true; }

// the giant wolf obeys his every command
inline bool klvSonWolfObeysEveryCommand()
    { return true; }

// the giant wolf is immune to cold attacks
inline bool klvSonWolfColdImmune()
    { return true; }

// his mother has given him the giant wolf
inline bool klvSonWolfFromLouhi()
    { return true; }

// ---- the Surma walk ----

// his club strikes for 3-30 points of damage: the floor
inline int klvSurmaClubDmgLo()
    { return 3; }

// the club damage ceiling
inline int klvSurmaClubDmgHi()
    { return 30; }

// Surma is the demigod of death
inline bool klvSurmaDemigodOfDeath()
    { return true; }

// only Surma can wield this weapon
inline bool klvSurmaClubOnlyHeCanWield()
    { return true; }

// he occasionally travels about the country challenging all he meets to
// combat
inline bool klvSurmaChallengesAll()
    { return true; }

// if they refuse, he lets them go only to follow them and kill them in their
// sleep
inline bool klvSurmaKillsRefusersInSleep()
    { return true; }

// he often appears as a slightly aging warrior in leather buckskins and red
// boots
inline bool klvSurmaAgingWarrior()
    { return true; }

// ---- the Tuonetar walk ----

// her merest touch inflicts 4-40 points of damage: the floor
inline int klvTuonetaTouchDmgLo()
    { return 4; }

// the touch damage ceiling
inline int klvTuonetaTouchDmgHi()
    { return 40; }

// any creature that comes within 30 feet of her must save vs. spells or be
// affected by her fear aura (the djvu feet word against the tsv inches -
// flagged)
inline int klvTuonetaFearRadiusFeet()
    { return 30; }

// Tuonetar is the goddess of the underworld, a greater goddess, the wife of
// Tuoni
inline bool klvTuonetarGoddessOfTheUnderworld()
    { return true; }

// she appears to the world as an incredibly ugly old crone
inline bool klvTuonetarUglyCrone()
    { return true; }

// those affected by the fear aura flee until exhaustion sets in
inline bool klvTuonetarFleeUntilExhaustion()
    { return true; }

// she is an implacable enemy of Vainamoinen
inline bool klvTuonetarEnemyOfVainamoinen()
    { return true; }

// ---- the Tuoni walk ----

// his club does 3-30 points of damage: the floor
inline int klvTuoniClubDmgLo()
    { return 3; }

// the club damage ceiling
inline int klvTuoniClubDmgHi()
    { return 30; }

// the middle 18 of the triple-slash 18/18/48 move print (the land and water
// alts read the same - flagged)
inline int klvTuoniMoveMid()
    { return 18; }

// the 1 percent chance that he will actually come in person to reclaim the
// raised person soul
inline int klvTuoniReclaimPct()
    { return 1; }

// Tuoni is the god of the underworld, a greater god
inline bool klvTuoniGodOfTheUnderworld()
    { return true; }

// this god is usually dressed in dark furs
inline bool klvTuoniDarkFurs()
    { return true; }

// at will he can constantly shape change and cast death and prismatic wall
// spells
inline bool klvTuoniDeathAndPrismaticWall()
    { return true; }

// he is immune to all death and charm-type spells
inline bool klvTuoniDeathCharmImmune()
    { return true; }

// the god will always appear as if in a vision when a being who worships the
// Finnish pantheon is raised from the dead
inline bool klvTuoniVisionOnRaise()
    { return true; }

// his club, which only he can lift, always disenchants one randomly
// determined magic item on the being hit (no saving throw)
inline bool klvTuoniClubOnlyHeCanLift()
    { return true; }

// his clerics go about the battlefield and aid those near death to reach the
// land of the dead, sending the near dead off a bit too soon, and take the
// dead person valuables as recompense
inline bool klvTuoniClericsTakeValuables()
    { return true; }

// ---- the Ukko walk ----

// the flaming sword does 3-30 points of damage: the floor
inline int klvUkkoSwordDmgLo()
    { return 3; }

// the sword damage ceiling
inline int klvUkkoSwordDmgHi()
    { return 30; }

// the sword has the power to slay anything it hits as a death spell; saving
// throw at -6 applicable
inline int klvUkkoDeathSaveMod()
    { return -6; }

// when a devout follower calls his name he is likely (30 percent) to send a
// warrior maiden
inline int klvUkkoMaidenPct()
    { return 30; }

// Ukko is the supreme god of the Kalevala, a greater god
inline bool klvUkkoSupremeGod()
    { return true; }

// Ukko is represented as an old man
inline bool klvUkkoTheOldMan()
    { return true; }

// he is very supportive of all the good heroes in the mythos
inline bool klvUkkoSupportsGoodHeroes()
    { return true; }

// while he usually uses a magic attack, when hard pressed in battle he uses
// the flaming sword
inline bool klvUkkoMagicAttackFirst()
    { return true; }

// this god is master of the sky and air, and supports the world: he is
// responsible for all weather and protects all avian life
inline bool klvUkkoSkyMaster()
    { return true; }

// because he is the supreme god he will never directly intervene in worldly
// affairs unless there is a strong possibility of the world being destroyed
// by evil, especially chaotics
inline bool klvUkkoNonintervention()
    { return true; }

// the warrior maiden is sent first to advise, then to rescue the imperiled
// believer
inline bool klvUkkoMaidenAdviseThenRescue()
    { return true; }

// these powerful warriors will be sent only when his worshipers face certain
// death at the hands of demons, devils or very powerful evil characters
inline bool klvUkkoMaidensOnlyCertainDeath()
    { return true; }

// ---- the Untamo walk ----

// he cannot be hurt by any being that has not recently slept for 13 hours or
// more
inline int klvUntaSleepHours()
    { return 13; }

// those that summon him must agree to serve his needs for one year to receive
// his help in any matter
inline int klvUntaServiceYears()
    { return 1; }

// his club strikes for 3-30 points of damage: the floor
inline int klvUntaClubDmgLo()
    { return 3; }

// the club damage ceiling
inline int klvUntaClubDmgHi()
    { return 30; }

// Untamo is the god of sleep and dreams, a lesser god
inline bool klvUntamoGodOfSleep()
    { return true; }

// this god is very mild in all of his actions and dislikes being summoned for
// any reason
inline bool klvUntamoVeryMild()
    { return true; }

// those who have not slept will go to sleep instantly in his presence
inline bool klvUntamoSleepAuraOnContact()
    { return true; }

// those that do not make their saving throw vs. spells will fall instantly
// asleep
inline bool klvUntamoClubSleep()
    { return true; }

// ---- the Air Maiden walk ----

// each maiden is armed with a +3 frost brand sword
inline int klvMaidenSwordPlus()
    { return 3; }

// each maiden may fly at up to 48 without tiring
inline int klvMaidenFlyRate()
    { return 48; }

// the Air Maiden is the warrior of Ukko
inline bool klvMaidenUkkosWarrior()
    { return true; }

// an air maiden appears as a winged human with a sword, garbed in flowing
// robes, and glowing with a brilliant light
inline bool klvMaidenWingedLight()
    { return true; }

// only one air maiden will appear at a time
inline bool klvMaidenOneAtATime()
    { return true; }

// when sent by Ukko, a maiden will first advise the worshiper as to the best
// course of action, using telepathy
inline bool klvMaidenTelepathy()
    { return true; }

// if a maiden is slain, she and all her possessions including the sword will
// vanish
inline bool klvMaidenVanishesOnDeath()
    { return true; }

// should an air maiden be slain before her mission is completed, another will
// immediately appear
inline bool klvMaidenReplacedOnDeath()
    { return true; }

// ---- the strength bracket walk ----

// the Water Dwarf S:18(37) bracket print (both voices read 37 - flagged)
inline int klvDwarfStrPct()
    { return 37; }

// the Lemminkainen S:18(09) bracket print (both voices read 09 - flagged)
inline int klvLemmStrPct()
    { return 9; }

// the Son of Pohjola S:18(00) bracket print: the double zero of exceptional
// strength
inline int klvSonStrPct()
    { return 0; }

// the 18(00) strength of the Son of Pohjola is the maximum percentile print
inline bool klvSonStrDoubleZero()
    { return true; }

// Loviatar prints the odd S:16(0, +1) bracket: a zero to hit bonus over a +1
// damage bonus
inline bool klvLoviStrZeroBracket()
    { return true; }

// ---- the ranger and paladin walk ----

// Vainamoinen prints a 20th level paladin on the fighter line (the R857
// convention: paladins ride the fighter cols)
inline bool klvVainaPaladin()
    { return true; }

// Ilmatar prints a 10th level paladin on the fighter line
inline bool klvIlmaPaladin()
    { return true; }

// Ukko prints a 20th level paladin on the fighter line
inline bool klvUkkoPaladin()
    { return true; }

// Tiera prints a 9th level ranger on the fighter line (rides the fighter
// cols, the bool carries the ranger word)
inline bool klvTieraRanger()
    { return true; }

// Mielikki prints a 10th level ranger on the fighter line
inline bool klvMielRanger()
    { return true; }

// Surma prints a 15th level ranger on the fighter line
inline bool klvSurmaRanger()
    { return true; }

// ---- the in-each walk ----

// Ahto prints the 15th level in each magic-user/illusionist pair
inline bool klvAhtoInEachMagUser()
    { return true; }

// Ilmatar prints the 13th level in each cleric/druid pair
inline bool klvIlmatarInEachCleric()
    { return true; }

// Kiputytto prints the in-each pair twice: 14th cleric/druid and 15th
// magic-user/illusionist
inline bool klvKiputyttoInEachBoth()
    { return true; }

// Louhi prints the 10th level in each cleric/druid pair
inline bool klvLouhiInEachCleric()
    { return true; }

// Loviatar prints the 12th level in each cleric/druid pair
inline bool klvLoviatarInEachCleric()
    { return true; }

// Mielikki prints the in-each pair twice: 14th cleric/druid and 12th
// magic-user/illusionist
inline bool klvMielikkiInEachBoth()
    { return true; }

// Surma prints the in-each pair twice: 14th cleric/druid and 12th
// magic-user/illusionist, both harming spells only
inline bool klvSurmaInEachBoth()
    { return true; }

// Tuonetar prints the 20th level in each magic-user/illusionist pair
inline bool klvTuonetarInEachMagUser()
    { return true; }

// Tuoni prints the 15th level in each magic-user/illusionist pair
inline bool klvTuoniInEachMagUser()
    { return true; }

// Ilmarinen prints the 9th level in each magic-user/illusionist pair
inline bool klvIlmarinenInEachMagUser()
    { return true; }

// Kullervo prints the 8th level in each magic-user/illusionist pair
inline bool klvKullervoInEachMagUser()
    { return true; }

// Tiera prints the 8th level in each magic-user/illusionist pair
inline bool klvTieraInEachMagUser()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Vainamoinen -4, Kullervo 1, Louhi 8 the worst, the
// Air Maiden 5)
inline int klvCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return -2;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 8;
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return -2;
        case 15:
            return 6;
        case 16:
            return -2;
        case 17:
            return -2;
        case 18:
            return 0;
        case 19:
            return 5;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all twenty read
// single this round)
inline int klvCbtACAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Ukko 400 the supreme, down to 66 per Tiera; Louhi the
// 110 decode against the djvu 1170 garble)
inline int klvCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 250;
        case 1:
            return 324;
        case 2:
            return 99;
        case 3:
            return 167;
        case 4:
            return 333;
        case 5:
            return 200;
        case 6:
            return 189;
        case 7:
            return 149;
        case 8:
            return 119;
        case 9:
            return 66;
        case 10:
            return 110;
        case 11:
            return 227;
        case 12:
            return 322;
        case 13:
            return 119;
        case 14:
            return 224;
        case 15:
            return 340;
        case 16:
            return 389;
        case 17:
            return 400;
        case 18:
            return 319;
        case 19:
            return 85;
        default:
            return 0;
        }
    }

// The primary move cells (-1 = the printed Infinite of Mielikki and Ukko, the
// R854 convention; Lemminkainen the 12 catch)
inline int klvCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 18;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 18;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 15;
        case 9:
            return 12;
        case 10:
            return 9;
        case 11:
            return 24;
        case 12:
            return -1;
        case 13:
            return 15;
        case 14:
            return 18;
        case 15:
            return 9;
        case 16:
            return 18;
        case 17:
            return -1;
        case 18:
            return 18;
        case 19:
            return 48;
        default:
            return 0;
        }
    }

// The secondary move cells (the printed slash ceilings; Ahto the 18/24/24 and
// Tuoni the 18/18/48 triple prints)
inline int klvCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 24;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 48;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 48;
        case 17:
            return 0;
        case 18:
            return 36;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (the 1s of Ilmatar, Kiputytto, Louhi, Loviatar and
// Tuonetar; Vainamoinen through Ukko the 2s)
inline int klvCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 2;
        default:
            return 0;
        }
    }

// The attack alternative cells (the 3/2 slashes of Ahto, Tiera, Mielikki, the
// Son of Pohjola and Untamo)
inline int klvCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 2;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard of the seven hero and
// servant rows; Ahto the 50 otherwise)
inline int klvCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 50;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 45;
        case 5:
            return 50;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 25;
        case 12:
            return 50;
        case 13:
            return 0;
        case 14:
            return 40;
        case 15:
            return 70;
        case 16:
            return 64;
        case 17:
            return 85;
        case 18:
            return 25;
        case 19:
            return 50;
        default:
            return 0;
        }
    }

// The size cells in inches (the foot-mark decodes: Lemminkainen 6 foot 2,
// Kullervo 6 foot 1, Tiera 5 foot 4, Mielikki 5 foot 1; Tuoni the L 10 foot)
inline int klvCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 84;
        case 1:
            return 84;
        case 2:
            return 48;
        case 3:
            return 72;
        case 4:
            return 84;
        case 5:
            return 60;
        case 6:
            return 60;
        case 7:
            return 74;
        case 8:
            return 73;
        case 9:
            return 64;
        case 10:
            return 60;
        case 11:
            return 60;
        case 12:
            return 61;
        case 13:
            return 84;
        case 14:
            return 72;
        case 15:
            return 60;
        case 16:
            return 120;
        case 17:
            return 84;
        case 18:
            return 84;
        case 19:
            return 72;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Tuoni 20th, Ukko 20th, Hiisi 15th; the in-each
// pairs of Ilmatar, Kiputytto, Louhi, Loviatar, Mielikki and Surma)
inline int klvClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 12;
        case 12:
            return 14;
        case 13:
            return 0;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 20;
        case 17:
            return 20;
        case 18:
            return 15;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// The druid level cells (the in-each pairs; Ilmarinen, Lemminkainen and the
// Son of Pohjola the single druid prints)
inline int klvClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 0;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 8;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 12;
        case 12:
            return 14;
        case 13:
            return 5;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level floor cells (the paladins Vainamoinen, Ilmatar and Ukko
// ride the fighter cols; Kullervo 19th, Lemminkainen 18th)
inline int klvClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 12;
        case 2:
            return 16;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 4;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 9;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 10;
        case 13:
            return 12;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 15;
        case 17:
            return 20;
        case 18:
            return 10;
        case 19:
            return 16;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (single printed levels read floor =
// ceiling)
inline int klvClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 12;
        case 2:
            return 16;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 4;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 9;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 10;
        case 13:
            return 12;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 15;
        case 17:
            return 20;
        case 18:
            return 10;
        case 19:
            return 16;
        default:
            return 0;
        }
    }

// The ranger level cells (0 = no separate ranger line this round; Tiera,
// Mielikki and Surma print the ranger on the fighter line and ride the bools)
inline int klvClsRanger(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (Ukko 25th, Ilmatar 20th, Tuonetar 20th in each;
// Hiisi, the Son of Pohjola and Untamo print Nil magic-users)
inline int klvClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 9;
        case 4:
            return 0;
        case 5:
            return 20;
        case 6:
            return 15;
        case 7:
            return 10;
        case 8:
            return 8;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 10;
        case 12:
            return 12;
        case 13:
            return 0;
        case 14:
            return 12;
        case 15:
            return 20;
        case 16:
            return 15;
        case 17:
            return 25;
        case 18:
            return 0;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// The illusionist level cells (Untamo 25th, Set-style Nil MU pairs; the
// in-each pairs of Ahto, Ilmarinen, Kiputytto, Kullervo, Mielikki, Surma,
// Tuonetar and Tuoni)
inline int klvClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 9;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 8;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 15;
        case 12:
            return 12;
        case 13:
            return 10;
        case 14:
            return 12;
        case 15:
            return 20;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 25;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (Kullervo the 10th level thief, Tiera-style zero
// elsewhere)
inline int klvClsThief(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 10;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (Hiisi 15th, Loviatar 10th, Surma 15th, the Son of
// Pohjola 8th)
inline int klvClsAssassin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 10;
        case 12:
            return 0;
        case 13:
            return 8;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (all Nil this round)
inline int klvClsMonk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The bard level cells (the all-heroes-are-bards doctrine: Vainamoinen 23rd,
// thirteen printed bard levels total)
inline int klvClsBard(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 9;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 10;
        case 12:
            return 12;
        case 13:
            return 5;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 10;
        case 17:
            return 15;
        case 18:
            return 10;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the FOLD SWAP catch: Kullervo the S:19(+3,+7) line the
// Termux full text gave to Tiera; Tiera the S:17(+1,+1))
inline int klvAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 24;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 24;
        case 5:
            return 14;
        case 6:
            return 19;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 17;
        case 10:
            return 8;
        case 11:
            return 16;
        case 12:
            return 15;
        case 13:
            return 18;
        case 14:
            return 25;
        case 15:
            return 15;
        case 16:
            return 25;
        case 17:
            return 25;
        case 18:
            return 19;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = no printed bracket;
// Loviatar the printed zero over the +1 damage)
inline int klvAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 7;
        case 15:
            return 0;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 3;
        case 19:
            return 3;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (the +14s of Surma, Tuoni and
// Ukko; the +12s of Ahto and Hiisi)
inline int klvAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 12;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 12;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 14;
        case 17:
            return 14;
        case 18:
            return 7;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// The intelligence cells (Untamo 25th-season I:25, Ukko I:24, the Air Maiden
// and Kiputytto the 19s)
inline int klvAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 22;
        case 2:
            return 16;
        case 3:
            return 18;
        case 4:
            return 22;
        case 5:
            return 19;
        case 6:
            return 19;
        case 7:
            return 18;
        case 8:
            return 15;
        case 9:
            return 17;
        case 10:
            return 19;
        case 11:
            return 20;
        case 12:
            return 22;
        case 13:
            return 15;
        case 14:
            return 19;
        case 15:
            return 18;
        case 16:
            return 20;
        case 17:
            return 24;
        case 18:
            return 25;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The wisdom cells (Hiisi the W:10 and Kullervo the W:6 - both voices agree
// on the odd prints; Mielikki W:25)
inline int klvAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 24;
        case 2:
            return 15;
        case 3:
            return 17;
        case 4:
            return 10;
        case 5:
            return 22;
        case 6:
            return 19;
        case 7:
            return 18;
        case 8:
            return 6;
        case 9:
            return 17;
        case 10:
            return 14;
        case 11:
            return 20;
        case 12:
            return 25;
        case 13:
            return 15;
        case 14:
            return 19;
        case 15:
            return 21;
        case 16:
            return 19;
        case 17:
            return 25;
        case 18:
            return 23;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The dexterity cells (Vainamoinen D:24, Ahto D:22; Loviatar D:16 the lowest)
inline int klvAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 22;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 21;
        case 5:
            return 20;
        case 6:
            return 19;
        case 7:
            return 18;
        case 8:
            return 18;
        case 9:
            return 17;
        case 10:
            return 18;
        case 11:
            return 16;
        case 12:
            return 19;
        case 13:
            return 19;
        case 14:
            return 23;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 23;
        case 18:
            return 24;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The constitution cells (Tuonetar C:25, Ukko C:25; Louhi C:19 over the S:8)
inline int klvAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 23;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 22;
        case 5:
            return 22;
        case 6:
            return 19;
        case 7:
            return 20;
        case 8:
            return 19;
        case 9:
            return 18;
        case 10:
            return 19;
        case 11:
            return 22;
        case 12:
            return 23;
        case 13:
            return 19;
        case 14:
            return 22;
        case 15:
            return 25;
        case 16:
            return 24;
        case 17:
            return 25;
        case 18:
            return 24;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The charisma cells (Tuonetar the negative six print; Kiputytto CH:6, Louhi
// CH:7, the Water Dwarf CH:7)
inline int klvAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 23;
        case 2:
            return 7;
        case 3:
            return 17;
        case 4:
            return 23;
        case 5:
            return 19;
        case 6:
            return 6;
        case 7:
            return 18;
        case 8:
            return 14;
        case 9:
            return 17;
        case 10:
            return 7;
        case 11:
            return 20;
        case 12:
            return 23;
        case 13:
            return 17;
        case 14:
            return 18;
        case 15:
            return -6;
        case 16:
            return 14;
        case 17:
            return 23;
        case 18:
            return 20;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = every being reads the R849 class table this
// round; no point scores printed)
inline int klvAbiPsi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Vainamoinen through the Air
// Maiden)
inline int klvRosOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The print page cells (57-62, the folio offset PRINT = PDF - 1)
inline int klvRosPage(int b)
    {
        switch (b) {
        case 0:
            return 57;
        case 1:
            return 57;
        case 2:
            return 58;
        case 3:
            return 58;
        case 4:
            return 58;
        case 5:
            return 58;
        case 6:
            return 59;
        case 7:
            return 59;
        case 8:
            return 59;
        case 9:
            return 59;
        case 10:
            return 60;
        case 11:
            return 60;
        case 12:
            return 60;
        case 13:
            return 61;
        case 14:
            return 61;
        case 15:
            return 61;
        case 16:
            return 61;
        case 17:
            return 62;
        case 18:
            return 62;
        case 19:
            return 62;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 4 N, 5 CN the Kullervo and Tuoni
// evil-tendency prints, 6 LE, 7 NE, 8 CE - the R852 code scheme)
inline int klvRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 8;
        case 5:
            return 0;
        case 6:
            return 8;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 8;
        case 16:
            return 5;
        case 17:
            return 0;
        case 18:
            return 4;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod, 3 servant - the Water Dwarf
// and the Air Maiden, 4 hero - the six Kalevala heroes)
inline int klvRosRank(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 4;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 3;
        default:
            return 0;
        }
    }

// The psionic class cells (Ahto IV, Tuonetar II, Mielikki the 8px pipe read
// as class I, Hiisi, Loviatar, Surma and Ukko VI)
inline int klvRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 2;
        case 16:
            return 0;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The plane cells (0 = none printed for the heroes and servants; 1 Prime
// Material, 2 Elemental Water, 3 Tarterus, 4 Gehenna, 5 Pandemonium, 6 Twin
// Paradises, 7 Concordant Opposition)
inline int klvRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 3;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 6;
        case 18:
            return 7;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed DAMAGE/ATTACK cell is numeric
// damage; 0 = the by-weapon rows)
inline int klvRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells, both the
// cleric/druid and magic-user/illusionist pairs)
inline int klvRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The Pohjola-enmity flags (the printed enemy lines: Kullervo the doomed
// foil, Louhi, the Son of Pohjola, Tuonetar the implacable enemy of
// Vainamoinen)
inline int klvRosEnmity(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
