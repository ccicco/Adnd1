// =========================================================================================
// Adnd1 - rules/uadeityprose4.h
// THE GNOMISH DEITY PROSE - part 4 of the Appendix S paragraph close:
// Baervan, Urdlen, Segojan, and Flandal pin from the clean archive.org OCR
// read
// census 711 -> 712.
//
// Part 4 of the five-part close (R786 the dwarves, R787 the elves, R788 the
// halflings). The four gnomish blocks (pp. 116-118) read scan-clean in the
// archive.org full-text OCR: every pin below is the printed text. The
// stat-block numerics stay R406/R783; the paragraph-level facts pin here -
// the Whisperleaf spear craft and the Chiktikka partnership, the Urdlen soul
// debt and the blood appeasement, the Segojan golem rod and the glowing gem
// symbols, and the Rhondang fireballs and the fire elemental retinue. Part 5
// remains: the orcs.
//
namespace rules {

// ---- the prose consts (the R789 wiring) ----

// The prose round: part 4, the gnomish paragraphs
inline int udp4ProseRound()
    { return 789; }

// The feeder round: the R406 stat blocks these paragraphs hang under
inline int udp4StatblockFeederRound()
    { return 406; }

// The gnomish census: four blocks described (Baervan, Urdlen, Segojan,
// Flandal)
inline int udp4GnomishDeityCount()
    { return 4; }

// By most counts there are only six or seven gnomish deities: the minimum six
inline int udp4PantheonCountMin()
    { return 6; }

// and the maximum seven, though there may be more in other universes
inline int udp4PantheonCountMax()
    { return 7; }

// He carries a spear +3 made from the ancient oak Whisperleaf
inline int udp4BaeSpearBonus()
    { return 3; }

// If the spear is destroyed he may make another from Whisperleaf wood in a
// single day
inline int udp4BaeSpearRemakeDays()
    { return 1; }

// Whisperleaf regenerates all wood loss within an hour
inline int udp4BaeWhisperleafRegenHours()
    { return 1; }

// His spear animates an ordinary tree for 5-20 turns: the minimum 5
inline int udp4BaeTreeAnimTurnsMin()
    { return 5; }

// and the maximum 20
inline int udp4BaeTreeAnimTurnsMax()
    { return 20; }

// The animated tree is a treant of 12 hit dice
inline int udp4BaeTreeTreantHitDice()
    { return 12; }

// He may animate one tree per round, as often as he likes
inline int udp4BaeTreesPerRound()
    { return 1; }

// His raccoon partner Chiktikka Fastpaws is AC 3
inline int udp4BaeChikAc()
    { return 3; }

// Chiktikka moves at 15 inches
inline int udp4BaeChikMoveInches()
    { return 15; }

// and has 70 hit points
inline int udp4BaeChikHp()
    { return 70; }

// Chiktikka has all the powers of a 12th-level thief
inline int udp4BaeChikThiefLevel()
    { return 12; }

// with an 18 dexterity
inline int udp4BaeChikDex()
    { return 18; }

// Chiktikka does 2-8 points of claw damage: the minimum 2
inline int udp4BaeChikClawDamageMin()
    { return 2; }

// and the maximum 8
inline int udp4BaeChikClawDamageMax()
    { return 8; }

// Chiktikka bites for 2-12 points of damage: the minimum 2
inline int udp4BaeChikBiteDamageMin()
    { return 2; }

// and the maximum 12
inline int udp4BaeChikBiteDamageMax()
    { return 12; }

// About a 1 percent chance that a worshiper who performed a great deed meets
// him and receives a minor magical item
inline int udp4BaeGiftMeetChancePct()
    { return 1; }

// His clerics have a 5 percent chance of calling upon Urdlen in danger for
// his protective blur
inline int udp4UrdBlurClericChancePct()
    { return 5; }

// His grass-and-roots armor acts as +4 leather
inline int udp4SegArmorBonus()
    { return 4; }

// His crystalline quartz rod is +4 to hit
inline int udp4SegRodBonus()
    { return 4; }

// The rod does 3-30 points of damage per hit: the minimum 3
inline int udp4SegRodDamageMin()
    { return 3; }

// and the maximum 30
inline int udp4SegRodDamageMax()
    { return 30; }

// The rod creates a stone golem once a day
inline int udp4SegGolemPerDay()
    { return 1; }

// Segojan may call up earth elementals once a day
inline int udp4SegElementalsPerDay()
    { return 1; }

// The summons brings 2-8 earth elementals: the minimum 2
inline int udp4SegElementalsMin()
    { return 2; }

// and the maximum 8
inline int udp4SegElementalsMax()
    { return 8; }

// each with 16 hit dice
inline int udp4SegElementalHitDice()
    { return 16; }

// His axe-backed hammer Rhondang is +5 to hit
inline int udp4FlaHammerBonus()
    { return 5; }

// Rhondang shoots a six-dice fireball
inline int udp4FlaFireballDice()
    { return 6; }

// as frequently as once per round
inline int udp4FlaFireballPerRound()
    { return 1; }

// up to a total of ten times per day
inline int udp4FlaFireballPerDay()
    { return 10; }

// A 65 percent chance he has fire elementals with him when encountered
inline int udp4FlaElementalChancePct()
    { return 65; }

// He is likely to have 1-4 fire elementals: the minimum 1
inline int udp4FlaElementalsMin()
    { return 1; }

// and the maximum 4
inline int udp4FlaElementalsMax()
    { return 4; }

// each with 16 hit dice
inline int udp4FlaElementalHitDice()
    { return 16; }

// ---- the prose bools (the R789 wiring) ----

// The gnomish pantheon is the demi-human pantheon with the fewest members
inline bool udp4PanFewestMembers()
    { return true; }

// All gnomish gods except Urdlen the Crawler are ruled by Garl Glittergold
inline bool udp4PanGarlRulesAll()
    { return true; }

// All but Urdlen live on the Twin Paradises in the Golden Hills, where the
// souls of faithful gnomes go at death
inline bool udp4PanGoldenHills()
    { return true; }

// Urdlen lives in the Abyss
inline bool udp4PanUrdlenInAbyss()
    { return true; }

// All the known gnomish deities are masculine, worshiped by male and female
// gnomes with equal reverence
inline bool udp4PanAllMasculine()
    { return true; }

// They lack the he-man image and are clever, sensible, and helpful
inline bool udp4PanCleverSensible()
    { return true; }

// Urdlen is sexless though still referred to as a he, and shares none of
// these good qualities
inline bool udp4PanUrdlenSexless()
    { return true; }

// Gnomish gods nearly always have at least one companion - a weapon, animal,
// or other deity
inline bool udp4PanCompanionsCommon()
    { return true; }

// Garl has Arumdina, his intelligent battle axe
inline bool udp4PanGarlHasArumdina()
    { return true; }

// Segojan is sometimes accompanied by an intelligent stone golem
inline bool udp4PanSegojanGolemFriend()
    { return true; }

// Urdlen, an exception again, has no friends
inline bool udp4PanUrdlenFriendless()
    { return true; }

// Pranks and practical jokes are a major response of gnomish gods to their
// enemies
inline bool udp4PanPranksAgainstEnemies()
    { return true; }

// They usually only associate with other gnomish deities, though they keep
// loose contact with a few dwarven gods
inline bool udp4PanLooseDwarvenContact()
    { return true; }

// The gnomish pantheon is one of the most active and most involved with its
// worshipers
inline bool udp4PanMostActive()
    { return true; }

// He is Garl Glittergold closest rival in the field of good-natured mischief,
// slightly better at thieving practice
inline bool udp4BaeRivalOfGarl()
    { return true; }

// He dresses in clothes of wood-brown hues
inline bool udp4BaeWoodBrownClothes()
    { return true; }

// Only Baervan may safely approach Whisperleaf; the tree attacks all others
// as a treant of maximum size and hit points
inline bool udp4BaeOnlyHeApproachesTree()
    { return true; }

// The animated tree/treant obeys all of Baervan orders and no one elses
inline bool udp4BaeTreeObeysOnlyHim()
    { return true; }

// Chiktikka is highly intelligent but prone to act before he thinks
inline bool udp4BaeChikHasty()
    { return true; }

// Many stories are told of the trouble Chiktikka starts by borrowing
// something valuable
inline bool udp4BaeChikBorrower()
    { return true; }

// Baervan is distinguished by his nut-brown skin and pale gray hair
inline bool udp4BaeNutBrownSkin()
    { return true; }

// He tends to keep to himself except for Chiktikka company, and sometimes
// roams the forests of the Prime Material Plane
inline bool udp4BaeKeepsToHimself()
    { return true; }

// Such a worshiper will meet Baervan only once in his or her lifetime
inline bool udp4BaeGiftOncePerLifetime()
    { return true; }

// Though he sometimes plays jokes on other creatures, it is hard not to like
// him
inline bool udp4BaeHardToDislike()
    { return true; }

// Gnomish fighters, fighter/thieves, and thieves of a non-evil nature follow
// him, preferring the outdoors to a city
inline bool udp4BaeFollowersOutdoorsmen()
    { return true; }

// Urdlen is the epitome of the evil impulse that rules some gnomes and is
// feared by the rest
inline bool udp4UrdEvilImpulse()
    { return true; }

// He appears as a huge, dead-white, furless mole with claws of steel
inline bool udp4UrdFurlessWhiteMole()
    { return true; }

// He lusts for precious metals, jewels, and the blood of any human, humanoid,
// or demi-human
inline bool udp4UrdLustsForMetals()
    { return true; }

// No one can predict where he will strike next, or what his plans are to
// further evil among gnomekind
inline bool udp4UrdUnpredictable()
    { return true; }

// His form is distorted by a permanent blur spell which cannot be dispelled
// while he lives
inline bool udp4UrdPermanentBlur()
    { return true; }

// If a protected cleric is slain anyway while the blur is in effect, Urdlen
// will eat the gnome soul when it reaches the Abyss
inline bool udp4UrdEatsSlainClericSoul()
    { return true; }

// His clerics appease him by pouring the blood of a creature they have killed
// into the ground and burying it
inline bool udp4UrdAppeasedByBlood()
    { return true; }

// Jewels and valuable metal goods are sacrificed by ruining them - breaking,
// tarnishing, melting - and then burying them
inline bool udp4UrdSacrificeByRuining()
    { return true; }

// Clerics of this deity are continually at war with the rest of the gnomish
// deities and their clerics and followers
inline bool udp4UrdAtWarWithPantheon()
    { return true; }

// Gnomish assassins and evil thieves and fighters worship him, often living
// underground after the manner of his chaotic tunnel home
inline bool udp4UrdFollowersUnderground()
    { return true; }

// He is a friend to all living animals above and below the earth, and one who
// speaks to the very rock itself
inline bool udp4SegSpeaksToRock()
    { return true; }

// He is known to his worshipers as a gray-skinned gnome
inline bool udp4SegGraySkinned()
    { return true; }

// The rod-created stone golem is of average intelligence and obeys Segojan
// commands alone
inline bool udp4SegGolemAverageIntelligence()
    { return true; }

// The rod must be pressed against a mass of rock of sufficient size to form
// the golem
inline bool udp4SegGolemNeedsRockMass()
    { return true; }

// He is also seen in a lesser way as the gnomish god of magic
inline bool udp4SegLesserGodOfMagic()
    { return true; }

// Many of his followers are illusionists who strive to improve their art for
// the betterment of gnomekind
inline bool udp4SegIllusionistFollowers()
    { return true; }

// Gnomish miners and jewelers also revere this deity
inline bool udp4SegMinersAndJewelers()
    { return true; }

// His clerics frequently cast light or continual light on large well-cut gems
// for use as holy symbols, causing them to glow from within
inline bool udp4SegGlowingGemSymbols()
    { return true; }

// He wears only a leather apron for armor, enchanted to reduce by half all
// damage from heat and fire
inline bool udp4FlaApronOnlyArmor()
    { return true; }

// His skin is the color of mithril steel, his eyes flaming coals, and his
// hair and beard a brilliant blue-silver
inline bool udp4FlaMithrilSkin()
    { return true; }

// He is one of the strongest of gnomish deities, perhaps the most so
inline bool udp4FlaStrongestGnomishGod()
    { return true; }

// It was Flandal who helped forge and enchant Arumdina, Garl Glittergold
// battle axe
inline bool udp4FlaForgedArumdina()
    { return true; }

// He is often found traveling with one or two other gnomish deities in search
// of new ores and veins of metal
inline bool udp4FlaTravelsSeekingOres()
    { return true; }

// Rhondang converses naturally with all beings who use fire or dwell in fiery
// locations - red dragons, chimerae, fire elementals
inline bool udp4FlaRhondangSpeaksFire()
    { return true; }

// This does not make him friendly toward those beings, though he will be
// prone to talk first before attacking
inline bool udp4FlaTalksBeforeAttacking()
    { return true; }

// Rhondang does double damage to cold-using or cold-dwelling creatures
inline bool udp4FlaRhondangDoubleVsCold()
    { return true; }

// His fire elementals are quite friendly toward him and obey him in all
// respects, because he needs their services to help forge items
inline bool udp4FlaElementalsObedient()
    { return true; }

// When not traveling he is found in his workshop on the Twin Paradises,
// planning or making a new magical weapon
inline bool udp4FlaWorkshopOnTwinParadises()
    { return true; }

// He is a popular god among the gnomish smiths; a large number of
// fighter/clerics follow his worship in some areas
inline bool udp4FlaSmithsFollowHim()
    { return true; }

// Some of his clerics have developed or been granted a new spell that makes
// their war hammers burst into flame like a flame tongue long sword
inline bool udp4FlaFlamingHammerSpell()
    { return true; }

}   // namespace rules
