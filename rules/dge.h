// =========================================================================================
// Adnd1 - rules/dge.h
// the Celtic mythos - the D&DG walk round five, print pp. 26-31: sixteen
// beings from Dagda the dozen king to the Pack of the Wild Hunt - the druid
// doctrine of the feast-day sacrifices, the torc and the cauldron, seven
// greater gods, and the Wild Hunt itself.
// census 775 -> 776.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 027-032; the second printing); the
// collation voices: the archive.org 1st-print derivative (djvu.txt + djvu.xml
// word geometry) and the 1eonline.info transcription (the Lugh S:23 and
// Morrigan charisma tie-breaks). The adjudications: the Dagda psionic class
// II (the 29px two-glyph IA word against the Termux I-slash), the Dagda
// magic-user/illusionist 15th in each and 20th bard (the IA recovery of the
// Termux fold), the Silvanus AC -4 and the 18 over 48 through-forests move
// (the IA recovery of fold-garbled lines), the Cu Chulainn 6-foot-4 and Math
// 5-foot-4 sizes (the foot-mark-as-1 decode of the printed 614 and 514
// cells), the Cu Chulainn intelligence 17 (the Termux against the IA 1:97
// misread), the Lugh strength 23 plus 5 plus 11 (the Termux and the
// transcription against the IA S:20 misread), the Lugh fighter slot kept as
// the printed 19th level ranger (both print voices; the transcription
// normalizes to fighter), the Nuada and Oghma 6-foot sizes (the IA clean read
// against the Termux ampersand garbles), the Goibhnie psionic VI (the 51px
// V-slash word), and the Morrigan charisma line 21 or -1 (the print
// variable-charisma cell, the transcription corroborating). Flagged for the
// physical-copy eyeball: the Manannan trident one-fourth drain and the
// tathlum damage fraction (both garbled in both voices).
//
namespace rules {

// ---- the R853 census ----

// the Celtic mythos round: the D&DG walk round five, print pp. 26-31
inline int dgeRound()
    { return 853; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int dgePrintStart()
    { return 26; }

// the last print page
inline int dgePrintEnd()
    { return 31; }

// the sixteen beings of the mythos (Dagda through the Pack of the Wild Hunt)
inline int dgeBeingCount()
    { return 16; }

// the four grids (combat, class, ability, roster)
inline int dgeTableCount()
    { return 4; }

// no chains this round
inline int dgeChainCount()
    { return 0; }

// zero registry defs touched - the floor holds at 995
inline int dgeRegistryFloor()
    { return 995; }

// the combat grid rows
inline int dgeCbtRows()
    { return 16; }

// the class grid rows
inline int dgeClsRows()
    { return 16; }

// the ability grid rows
inline int dgeAbiRows()
    { return 16; }

// the roster grid rows
inline int dgeRosRows()
    { return 16; }

// the two printed planes: Concordant Opposition and the Prime Material Plane
// (Arawn)
inline int dgePlaneCount()
    { return 2; }

// the printed psionic class VI (ten of the sixteen read VI this round)
inline int dgePsiClassVI()
    { return 6; }

// Dagda reads the printed class II (the 29px two-glyph IA word against the
// Termux I-slash garble)
inline int dgePsiClassII()
    { return 2; }

// Oghma reads the printed class IV (the 57px three-glyph word)
inline int dgePsiClassIV()
    { return 4; }

// the Samain sacrifice, November 1, celebrating winter start
inline int dgeSamainMonth()
    { return 11; }

// the Samain day
inline int dgeSamainDay()
    { return 1; }

// the Imbalc sacrifice, February 1, celebrating winter leavetaking
inline int dgeImbalcMonth()
    { return 2; }

// the Imbalc day
inline int dgeImbalcDay()
    { return 1; }

// the Beltane sacrifice, May 1, celebrating spring planting
inline int dgeBeltaneMonth()
    { return 5; }

// the Beltane day
inline int dgeBeltaneDay()
    { return 1; }

// the Lugnasad sacrifice, August 1, celebrating the time of harvest
inline int dgeLugnasadMonth()
    { return 8; }

// the Lugnasad day
inline int dgeLugnasadDay()
    { return 1; }

// the four human sacrifices a year (condemned criminals the typical
// sacrifice)
inline int dgeSacrificesPerYear()
    { return 4; }

// druids of the sixth level or less wear light blue robes; higher levels
// always white
inline int dgeDruidBlueLevelMax()
    { return 6; }

// the cauldrons of tenth level or higher druids act as crystal balls when
// filled with human blood
inline int dgeCauldronCrystalLevel()
    { return 10; }

// druids of the eleventh through fourteenth levels carry the wheel with a
// crossed spiral on all their tools
inline int dgeWheelSymbolLoLevel()
    { return 11; }

// the wheel-symbol ceiling
inline int dgeWheelSymbolHiLevel()
    { return 14; }

// the hounds do 2-8
inline int dgeHoundDmgLo()
    { return 2; }

// the hound damage ceiling
inline int dgeHoundDmgHi()
    { return 8; }

// the hounds attack as 8 hit dice monsters
inline int dgeHoundAttackHD()
    { return 8; }

// the pack xp line: VI/950 per hound
inline int dgeHoundXpValue()
    { return 950; }

// ---- the mythos intro ----

// the Celtic mythology is by no means confined to the British Isles
inline bool dgeNotConfinedToBritishIsles()
    { return true; }

// the listed beings are all in human form, unlike some of the other pantheons
inline bool dgeAllHumanForm()
    { return true; }

// the gods all have spheres of influence - areas of control; major
// manipulations make the god take an interest in force
inline bool dgeSpheresOfInfluence()
    { return true; }

// the clerics of most of these deities are druids, fully detailed in Players
// Handbook
inline bool dgeClericsAreDruids()
    { return true; }

// all religious services are performed by druids in wooded areas made holy by
// the planting of mistletoe and holly
inline bool dgeServicesInWoodedAreas()
    { return true; }

// in these areas are deep natural wells or dug pits where sacrifices are
// thrown
inline bool dgeWellsAndPits()
    { return true; }

// human sacrifices are made four times a year on the four feast days
inline bool dgeHumanSacrifices()
    { return true; }

// condemned criminals are the typical sacrifices
inline bool dgeCondemnedCriminals()
    { return true; }

// druid groves are the only places druids can cast commune with nature; they
// are guarded by packs of wild boars under complete control, the pack growing
// with the grove
inline bool dgeGrovesGuardedByBoars()
    { return true; }

// sixth level or less druids wear light blue robes, higher levels always
// white
inline bool dgeDruidRobes()
    { return true; }

// every druid wears a torc, an ornamental neck ring representing the favored
// god - the more powerful the druid, the better the torc
inline bool dgeTheTorc()
    { return true; }

// the best torcs are encrusted with gems and imparted with magic along the
// lines of a +1 or +2 protection ring or talisman
inline bool dgeTorcMagic()
    { return true; }

// every druid makes a cauldron as a first level druid, used to catch the
// blood or sap of sacrifices
inline bool dgeDruidCauldron()
    { return true; }

// druids of the eleventh through fourteenth levels mark all their tools with
// the wheel with a crossed spiral
inline bool dgeWheelSymbol()
    { return true; }

// the Celtic gods are very tolerant of their priests actions as long as they
// further the sect
inline bool dgeTolerantOfPriests()
    { return true; }

// regard for nature is the prime concern; trifling with nature harmfully is
// reason for punishment
inline bool dgeNaturePrimeConcern()
    { return true; }

// druids consider themselves an elite group, separate from all other humans,
// mating only within the sect
inline bool dgeEliteSeparateGroup()
    { return true; }

// ---- the Dagda walk ----

// Dagda separates himself into 12 distinct and powerful entities
inline int dgeDagdaEntityCount()
    { return 12; }

// eleven of the twelve are ethereal and roam the earth with unlimited range
inline int dgeDagdaEtherealCount()
    { return 11; }

// Dagda: the club does 5-50 when striking
inline int dgeDagdaClubDmgLo()
    { return 5; }

// Dagda: the club damage ceiling
inline int dgeDagdaClubDmgHi()
    { return 50; }

// Dagda: the strength bonus of 14 points on the club
inline int dgeDagdaStrBonus()
    { return 14; }

// Dagda, the dozen king, a greater god and ruler of a very loose pantheon
inline bool dgeDagdaDozenKing()
    { return true; }

// his primary attribute is separating himself into 12 distinct powerful
// entities
inline bool dgeDagdaSeparatesSelf()
    { return true; }

// eleven of the twelve are ethereal, fully aware and mobile, roaming with
// unlimited range and supplying information to Dagda
inline bool dgeDagdaEtherealServants()
    { return true; }

// unlimited use of shape change, telepathy and legend lore
inline bool dgeDagdaShapeChange()
    { return true; }

// he is fond of walking the earth as a shabbily dressed man with a large club
inline bool dgeDagdaShabbyMan()
    { return true; }

// Dagda has the strength to break anything in his two hands
inline bool dgeDagdaBreaksAnything()
    { return true; }

// the club large end acts as a death spell when it touches a being
inline bool dgeDagdaClubDeathEnd()
    { return true; }

// the small end raises the dead no matter how long dead - only a portion of
// the body is needed
inline bool dgeDagdaClubRaiseEnd()
    { return true; }

// he can summon a cauldron that brews any non-magical liquid or food
inline bool dgeDagdaCauldron()
    { return true; }

// he sings with a sentient harp that talks in the common tongue and can
// control weather
inline bool dgeDagdaSentientHarp()
    { return true; }

// ---- the Arawn walk ----

// Arawn flashes 2 death spells from his eyes at any time, striking
// independent targets
inline int dgeArawnDeathSpells()
    { return 2; }

// Arawn uses any spell of up to the third level
inline int dgeArawnSpellLevelMax()
    { return 3; }

// Arawn casts those spells as a 20th level magic-user
inline int dgeArawnSpellAsLevel()
    { return 20; }

// Arawn appears on a 2 percent chance per level of a restored dead Celtic
// worshiper
inline int dgeArawnRestoreChancePerLevel()
    { return 2; }

// Arawn offers a substitute from the ranks of the dead 25 percent of the time
inline int dgeArawnSubstitutePct()
    { return 25; }

// Arawn fights with a +3 club
inline int dgeArawnClubPlus()
    { return 3; }

// Arawn: the club strikes for 2-20
inline int dgeArawnClubDmgLo()
    { return 2; }

// Arawn: the club damage ceiling
inline int dgeArawnClubDmgHi()
    { return 20; }

// Arawn: the strength bonus of 11 points
inline int dgeArawnStrBonus()
    { return 11; }

// Arawn, god of the dead, The Dark One, a greater god
inline bool dgeArawnGodOfDead()
    { return true; }

// Arawn appears as a normal man and lives on an island only the dead can find
inline bool dgeArawnIslandOfDead()
    { return true; }

// he flashes 2 death spells from his eyes at any time, striking independent
// targets
inline bool dgeArawnEyeDeathSpells()
    { return true; }

// he uses any spell of up to the third level as a 20th level magic-user (the
// See below cell)
inline bool dgeArawnThirdLevelSpells()
    { return true; }

// the god appears if someone restores to life a person he wants kept in his
// domain
inline bool dgeArawnAppearsOnRestore()
    { return true; }

// he fights for the dead person or offers a substitute from the vast ranks of
// the dead
inline bool dgeArawnFightsOrSubstitutes()
    { return true; }

// Arawn is immune to any magical or clerical spell causing direct damage to
// the body
inline bool dgeArawnImmuneToDirectDamage()
    { return true; }

// any being touching him with a magical weapon dies, saving throw applicable
inline bool dgeArawnWeaponTouchDeath()
    { return true; }

// ---- the Brigit walk ----

// Brigit uses any fire spell as a 35th level spell-caster (the See below
// cell)
inline int dgeBrigitFireSpellLevel()
    { return 35; }

// Brigit has +5 armor in the form of tongues of flame
inline int dgeBrigitArmorPlus()
    { return 5; }

// Brigit favors a singer of an original composition 5 percent of the time
inline int dgeBrigitSongPct()
    { return 5; }

// the favored singer is raised 1 level for the length of the battle
inline int dgeBrigitSongBoost()
    { return 1; }

// Brigit: the flame aura does 30 points of damage
inline int dgeBrigitAuraDamage()
    { return 30; }

// Brigit: the aura reaches all within 30 feet
inline int dgeBrigitAuraFeet()
    { return 30; }

// Brigit: weapons less than +3 melt when touching her
inline int dgeBrigitMeltPlus()
    { return 3; }

// Brigit: the flame staff does 2-20 when striking
inline int dgeBrigitStaffDmgLo()
    { return 2; }

// Brigit: the staff damage ceiling
inline int dgeBrigitStaffDmgHi()
    { return 20; }

// Brigit, goddess of fire and poetry, a lesser goddess
inline bool dgeBrigitFireAndPoetry()
    { return true; }

// Brigit appears as a tall woman with flame-colored hair
inline bool dgeBrigitFlameHair()
    { return true; }

// she loves poetry sung on the battlefield and may raise a singer of an
// original composition 1 level
inline bool dgeBrigitSongFavor()
    { return true; }

// the printed note: a player wishing to worship Brigit must make up an
// original battle-song on the spot and sing it
inline bool dgeBrigitBattleSongDoctrine()
    { return true; }

// Brigit is immune to fire, cold, petrification and dragon breath attacks
inline bool dgeBrigitFireImmunities()
    { return true; }

// in battle she is surrounded with flame doing 30 points to all within 30
// feet
inline bool dgeBrigitFlameAura()
    { return true; }

// weapons less than +3 melt when touching her
inline bool dgeBrigitMeltsWeapons()
    { return true; }

// her staff turns into a tongue of flame at her command, doing 2-20
inline bool dgeBrigitFlameStaff()
    { return true; }

// ---- the Cu Chulainn walk ----

// Cu Chulainn: Gae Bolg, the +4 spear of sea-dragon bones
inline int dgeCuSpearPlus()
    { return 4; }

// Gae Bolg does 4-40 points of damage
inline int dgeCuSpearDmgLo()
    { return 4; }

// Gae Bolg: the damage ceiling
inline int dgeCuSpearDmgHi()
    { return 40; }

// Cu Chulainn: his mortal enemies take -4 on their chances to hit (the
// brilliance)
inline int dgeCuGlarePenalty()
    { return 4; }

// Cu Chulainn: the strength bonus of 8 points
inline int dgeCuStrBonus()
    { return 8; }

// Cu Chulainn, the hero
inline bool dgeCuHero()
    { return true; }

// he always uses the spear Gae Bolg, made from the bones of a sea dragon - a
// +4 weapon doing 4-40
inline bool dgeCuGaeBolg()
    { return true; }

// when holding Gae Bolg he cannot be surprised; none but Cu Chulainn can
// wield it
inline bool dgeCuNeverSurprised()
    { return true; }

// in battle he shines so his mortal enemies cannot look directly at him, -4
// to hit
inline bool dgeCuBattleBrilliance()
    { return true; }

// the hero exists to fight giants and right wrongs; he often appears when all
// hope is lost
inline bool dgeCuFightsGiants()
    { return true; }

// the printed special defenses line: See below (the brilliance doctrine rides
// the consts; the R851 Merlin cannot-be-charmed parallel does not apply here)
inline bool dgeCuCannotBeCharmed()
    { return false; }

// ---- the Diancecht walk ----

// Diancecht: 12th level or above clerics have a 10 percent chance of
// summoning him
inline int dgeDiancechtSummonPct()
    { return 10; }

// Diancecht: the summoner level floor (with the year-long pilgrimage oath)
inline int dgeDiancechtSummonerLevel()
    { return 12; }

// Diancecht is immune to anything doing less than one-fourth of his hit
// points in one strike
inline int dgeDiancechtImmuneDiv()
    { return 4; }

// Diancecht fights with a +3 spear
inline int dgeDiancechtSpearPlus()
    { return 3; }

// Diancecht: the spear does 3-30 when it hits
inline int dgeDiancechtSpearDmgLo()
    { return 3; }

// Diancecht: the spear damage ceiling
inline int dgeDiancechtSpearDmgHi()
    { return 30; }

// Diancecht: the strength bonus of 10 points
inline int dgeDiancechtStrBonus()
    { return 10; }

// Diancecht, physician of the gods, a lesser god
inline bool dgeDiancechtPhysician()
    { return true; }

// Diancecht appears as a young man
inline bool dgeDiancechtAppearsYoung()
    { return true; }

// he can heal any wound or restore any dead being, no matter how long dead
inline bool dgeDiancechtHealsAnything()
    { return true; }

// the god appears whenever any Celtic deity summons him to help
inline bool dgeDiancechtSummonedByDeities()
    { return true; }

// 12th level or above clerics may summon him swearing a year-long pilgrimage
// to heal all things knowing hurt, including opposite alignments; failure
// brings his revenge
inline bool dgeDiancechtPilgrimage()
    { return true; }

// his power will not work on beings who have had their head taken away
inline bool dgeDiancechtHeadlessLimit()
    { return true; }

// he never fights in large battles but has fought Arawn over some of his
// dead, always winning
inline bool dgeDiancechtWonVsArawn()
    { return true; }

// he is hardly ever attacked because he heals friends and enemies alike
// during a battle
inline bool dgeDiancechtHealsAllSides()
    { return true; }

// ---- the Dunatis walk ----

// Dunatis enters battle using +4 armor and shield
inline int dgeDunatisArmorPlus()
    { return 4; }

// Dunatis: the boulders do 8-80 points of damage
inline int dgeDunatisBoulderDmgLo()
    { return 8; }

// Dunatis: the boulder damage ceiling
inline int dgeDunatisBoulderDmgHi()
    { return 80; }

// Dunatis throws the boulders up to 1,000 yards with great accuracy
inline int dgeDunatisBoulderRangeYards()
    { return 1000; }

// Dunatis: the strength bonus of 14 points
inline int dgeDunatisStrBonus()
    { return 14; }

// Dunatis, god of the mountains and peaks, a lesser god
inline bool dgeDunatisMountainGod()
    { return true; }

// this god always appears as a normal man
inline bool dgeDunatisAppearsNormal()
    { return true; }

// he can raise a mountain peak from a flat plain, or flatten a giant mountain
// into a prairie, instantaneously
inline bool dgeDunatisRaisesPeaks()
    { return true; }

// the power was often done to destroy forts and the like
inline bool dgeDunatisDestroysForts()
    { return true; }

// his weapons are boulders formed instantly from thin air
inline bool dgeDunatisAirBoulders()
    { return true; }

// he is immune to paralysis, petrification, and charming attacks
inline bool dgeDunatisImmunities()
    { return true; }

// ---- the Goibhnie walk ----

// Goibhnie: the impossible-hit thunderbolt does 50 points, no saving throw
inline int dgeGoibhnieThunderboltDamage()
    { return 50; }

// Goibhnie: an amulet can protect up to 500 persons with hands linked in
// series
inline int dgeGoibhnieAmuletProtectCount()
    { return 500; }

// Goibhnie: the +4 spear
inline int dgeGoibhnieSpearPlus()
    { return 4; }

// Goibhnie: the spear does 3-30 plus strength
inline int dgeGoibhnieSpearDmgLo()
    { return 3; }

// Goibhnie: the spear damage ceiling
inline int dgeGoibhnieSpearDmgHi()
    { return 30; }

// Goibhnie: the strength bonus of 14 points
inline int dgeGoibhnieStrBonus()
    { return 14; }

// Goibhnie, blacksmith of the gods, a lesser god
inline bool dgeGoibhnieBlacksmith()
    { return true; }

// this god appears as a hugely proportioned man
inline bool dgeGoibhnieHugeMan()
    { return true; }

// the weapons he makes never miss their target
inline bool dgeGoibhnieWeaponsNeverMiss()
    { return true; }

// his amulets nullify any one specific spell; effects of the protected spell
// never appear, or solids turn to dust
inline bool dgeGoibhnieAmulets()
    { return true; }

// an impossible hit with his weapon lands, then the weapon shatters and the
// thunderbolt comes
inline bool dgeGoibhnieImpossibleHit()
    { return true; }

// it is impossible to wear more than one of the amulets at a time - they
// shatter
inline bool dgeGoibhnieOneAmulet()
    { return true; }

// the god has made himself immune to any damage done by physical weaponry of
// any type
inline bool dgeGoibhniePhysicalImmune()
    { return true; }

// ---- the Lugh walk ----

// Lugh casts druidical spells at the 30th level of magic use, unlimited (the
// Nil/see below cell)
inline int dgeLughDruidSpellLevel()
    { return 30; }

// Lugh: the strength bonus of 11 points
inline int dgeLughStrBonus()
    { return 11; }

// Lugh long handed, god of generalities, a greater god
inline bool dgeLughGeneralities()
    { return true; }

// he is unique: he can use any one attribute of any being he has ever met
inline bool dgeLughBorrowedAttribute()
    { return true; }

// he appears as a tall man with very large hands
inline bool dgeLughLargeHands()
    { return true; }

// he never uses armor and depends on his one power to defeat his foe
inline bool dgeLughNoArmor()
    { return true; }

// he is a druidical ideal, casting druidical spells at the 30th level,
// unlimited
inline bool dgeLughDruidicalIdeal()
    { return true; }

// he is immune to control, petrification, or paralyzation
inline bool dgeLughImmunities()
    { return true; }

// ---- the Manannan walk ----

// Manannan wears +5 armor of sea shells
inline int dgeManannanArmorPlus()
    { return 5; }

// Manannan: the trident drains one-fourth of the victim original hit points
// (the fraction garbles in both voices - flagged)
inline int dgeManannanTridentDrainDiv()
    { return 4; }

// Manannan: Retaliator does 3-30 plus strength even when the save is made
inline int dgeManannanRetaliatorDmgLo()
    { return 3; }

// Manannan: the Retaliator damage ceiling
inline int dgeManannanRetaliatorDmgHi()
    { return 30; }

// Manannan calls any non-godlike sea creature in numbers up to 50
inline int dgeManannanSummonCount()
    { return 50; }

// Manannan: the strength bonus of 12 points
inline int dgeManannanStrBonus()
    { return 12; }

// Manannan Mac Lir, god of the sea, a greater god
inline bool dgeManannanSeaGod()
    { return true; }

// this god appears as a large red-bearded man
inline bool dgeManannanRedBeard()
    { return true; }

// his trident absorbs moisture from bodies it hits, draining one-fourth of
// the victim original hit points
inline bool dgeManannanTridentDrains()
    { return true; }

// against the fire giants he uses the sword Retaliator, which kills every
// time it hits, magic save applicable, and does 3-30 plus strength even on a
// save
inline bool dgeManannanRetaliator()
    { return true; }

// he calls on any non-godlike sea creature in numbers up to 50, arriving
// under their own power
inline bool dgeManannanSeaSummon()
    { return true; }

// he is immune to any magical device attack while in salt water
inline bool dgeManannanSaltWaterImmune()
    { return true; }

// ---- the Math walk ----

// Math: the printed 200 point psionic score (like Merlin 300 - a score, not a
// class)
inline int dgeMathPsiScore()
    { return 200; }

// Math: 30th level magic-user
inline int dgeMathMuLevel()
    { return 30; }

// Math: 10th level illusionist
inline int dgeMathIllusLevel()
    { return 10; }

// Math, the magic-user, greatest of all the legendary wizards in Celtic myth
inline bool dgeMathMagicUser()
    { return true; }

// he has given himself the power to hear anything said in a breeze anywhere
// in the world
inline bool dgeMathHearsBreezes()
    { return true; }

// he has been given a Torc of the Gods for what he has done for the gods
inline bool dgeMathTorcBearer()
    { return true; }

// when forced to fight he uses a rod that turns any being touched into a pool
// of water, permanently, magic save applicable
inline bool dgeMathWaterRod()
    { return true; }

// he enjoys using polymorph others to turn opponents into animals
inline bool dgeMathPolymorphOthers()
    { return true; }

// ---- the Morrigan walk ----

// Morrigan: the printed charisma line reads 21 or -1 (the hideous-face
// doctrine)
inline int dgeMorriganChaAlt()
    { return -1; }

// Morrigan sees clearly over 15 miles
inline int dgeMorriganSightMiles()
    { return 15; }

// Morrigan strikes dead a fleeing worshiper 5 percent of the time
inline int dgeMorriganFleeStrikePct()
    { return 5; }

// the chance she is watching any given battle
inline int dgeMorriganWatchingPct()
    { return 10; }

// Morrigan: the two spears strike for 3-36 each and never miss
inline int dgeMorriganSpearDmgLo()
    { return 3; }

// Morrigan: the spear damage ceiling
inline int dgeMorriganSpearDmgHi()
    { return 36; }

// Morrigan: the four demi-goddesses of war, Fen, Neman, Badb and Macha
inline int dgeMorriganServantCount()
    { return 4; }

// Morrigan: each demi-goddess has 200 hit points
inline int dgeMorriganServantHP()
    { return 200; }

// Morrigan: the strength bonus of 14 points
inline int dgeMorriganStrBonus()
    { return 14; }

// Morrigan, goddess of war, a lesser goddess
inline bool dgeMorriganWarGoddess()
    { return true; }

// she appears as a well-proportioned woman with a hideous face - the printed
// charisma line reads 21 or -1
inline bool dgeMorriganHideousFace()
    { return true; }

// she deprives all who face her of their courage, as the fear spell
inline bool dgeMorriganFear()
    { return true; }

// she can fight invisibly
inline bool dgeMorriganInvisibleFight()
    { return true; }

// she travels on land at any speed she wishes when chasing a foe (the
// Variable move)
inline bool dgeMorriganChaseSpeed()
    { return true; }

// she strikes dead a fleeing worshiper 5 percent of the time when watching,
// 10 percent per battle
inline bool dgeMorriganStrikesFleeing()
    { return true; }

// her two spears, red-headed and yellow-headed, strike for 3-36 each and
// never miss
inline bool dgeMorriganTwoSpears()
    { return true; }

// she is immune to attacks by magic-using beings not of godlike power while
// in battle
inline bool dgeMorriganMagicImmune()
    { return true; }

// her servants include four demi-goddesses of war, Fen, Neman, Badb and
// Macha, identical in all regards save 200 hit points each
inline bool dgeMorriganDemiGoddesses()
    { return true; }

// ---- the Nuada walk ----

// Nuada gives any weapon he holds a +3 bonus to hit
inline int dgeNuadaHitPlus()
    { return 3; }

// Nuada doubles the weapon normal damaging power
inline int dgeNuadaDoubleDamage()
    { return 2; }

// Nuada: the silver hand enters battle as a dancing sword hitting for 6-36
inline int dgeNuadaHandDmgLo()
    { return 6; }

// Nuada: the silver-hand damage ceiling
inline int dgeNuadaHandDmgHi()
    { return 36; }

// Nuada: the +4 suit of studded leather armor
inline int dgeNuadaArmorPlus()
    { return 4; }

// Nuada: the +5 sword
inline int dgeNuadaSwordPlus()
    { return 5; }

// Nuada: the sword fends off any 3 weapons used against its master
inline int dgeNuadaFendCount()
    { return 3; }

// Nuada: the strength bonus of 14 points
inline int dgeNuadaStrBonus()
    { return 14; }

// Nuada, god of war, god of the Silver Hand, a greater god
inline bool dgeNuadaSilverHand()
    { return true; }

// he appears as a man with an artificial silver hand
inline bool dgeNuadaArtificialHand()
    { return true; }

// he gives any weapon he holds a +3 bonus to hit and double its damaging
// power
inline bool dgeNuadaWeaponBonus()
    { return true; }

// in battle he detaches the silver hand, which enters battle as a dancing
// sword hitting for 6-36
inline bool dgeNuadaDancingHand()
    { return true; }

// the +5 sword fends off any 3 weapons against its master, however powerful,
// and still attacks
inline bool dgeNuadaFendingSword()
    { return true; }

// he demands his enemies wrestle him; the winner stays, the loser leaves the
// battle
inline bool dgeNuadaWrestles()
    { return true; }

// his strength is such that facing any being he has strength equal to that
// being plus his own
inline bool dgeNuadaEqualStrength()
    { return true; }

// the god is immune to any type of magical control spell
inline bool dgeNuadaControlImmune()
    { return true; }

// ---- the Oghma walk ----

// Oghma: a 1 percent chance he is listening to an original composition when
// sung
inline int dgeOghmaListenPct()
    { return 1; }

// Oghma: a 5 percent chance he rewards a spread song or tale with great
// wealth
inline int dgeOghmaRewardPct()
    { return 5; }

// Oghma wears +4 chainmail and demands wrestling
inline int dgeOghmaChainmailPlus()
    { return 4; }

// Oghma: the asterisked strength bonus of 14 points (the See below doctrine)
inline int dgeOghmaStrBonus()
    { return 14; }

// Oghma, god of knowledge, The Binder, Patron of all Bards, a greater god
inline bool dgeOghmaBinder()
    { return true; }

// Oghma looks like an aged, white-haired man
inline bool dgeOghmaAgedMan()
    { return true; }

// he is the best wrestler of all the gods, their champion against giants
inline bool dgeOghmaBestWrestler()
    { return true; }

// he is patron of things creative and beautiful in man and woman alike
inline bool dgeOghmaCreativePatron()
    { return true; }

// his love of song, story and poetry brings him to earth seeking especially
// gifted people from hold to hold
inline bool dgeOghmaSeeksGifted()
    { return true; }

// he can answer any question after a short period of study - the more
// difficult, the longer it takes
inline bool dgeOghmaAnswerMachine()
    { return true; }

// he knows the secret name of any non-godlike creature; knowing it lets one
// control the being or make it die, save vs death applicable
inline bool dgeOghmaSecretNames()
    { return true; }

// the asterisked strength: facing any being he has strength equal to that
// being plus his own (the printed See below)
inline bool dgeOghmaVariableStrength()
    { return true; }

// Oghma is known as The Binder for forcing demons and devils into his special
// prison until he wishes them out
inline bool dgeOghmaImprisonsDemons()
    { return true; }

// ---- the Silvanus walk ----

// Silvanus: the leaf armor acts like +5 plate mail
inline int dgeSilvanusArmorPlus()
    { return 5; }

// Silvanus: the +5 wooden mallet
inline int dgeSilvanusMalletPlus()
    { return 5; }

// Silvanus: the mallet strikes for 5-50 in his hands
inline int dgeSilvanusMalletDmgLo()
    { return 5; }

// Silvanus: the mallet damage ceiling
inline int dgeSilvanusMalletDmgHi()
    { return 50; }

// Silvanus: the giant wolfhound, armor class 3
inline int dgeSilvanusHoundAC()
    { return 3; }

// Silvanus: the wolfhound hit dice
inline int dgeSilvanusHoundHD()
    { return 10; }

// Silvanus: the wolfhound hit points
inline int dgeSilvanusHoundHP()
    { return 100; }

// Silvanus: the wolfhound attacks once
inline int dgeSilvanusHoundAtN()
    { return 1; }

// Silvanus: the wolfhound does 2-20
inline int dgeSilvanusHoundDmgLo()
    { return 2; }

// Silvanus: the wolfhound damage ceiling
inline int dgeSilvanusHoundDmgHi()
    { return 20; }

// Silvanus: the wolfhound regenerates 5 hit points per melee round
inline int dgeSilvanusHoundRegen()
    { return 5; }

// Silvanus: a 1 percent chance he appears when harm is done to a high level
// druid or grove
inline int dgeSilvanusGroveAppearPct()
    { return 1; }

// Silvanus: the strength bonus of 14 points
inline int dgeSilvanusStrBonus()
    { return 14; }

// Silvanus, god of the forests and nature, a greater god
inline bool dgeSilvanusForestGod()
    { return true; }

// Silvanus looks like a man with very long legs
inline bool dgeSilvanusLongLegs()
    { return true; }

// he can control any number of animals and creatures of the forest with the
// sound of his voice
inline bool dgeSilvanusVoiceControl()
    { return true; }

// he makes plants grow and/or shrink at any rate he wills
inline bool dgeSilvanusPlants()
    { return true; }

// he wears armor made of leaves that act like +5 plate mail; the +5 wooden
// mallet strikes for 5-50
inline bool dgeSilvanusLeafArmor()
    { return true; }

// a giant wolfhound fights at his side, so fast it takes all the damage meant
// for its master, but cannot block spells
inline bool dgeSilvanusWolfhound()
    { return true; }

// he is a protector of the druid places: groves, villages, colleges and
// woodland paths
inline bool dgeSilvanusGroveProtector()
    { return true; }

// ---- the Master walk ----

// the Master uses a +3 spear in battle
inline int dgeMasterSpearPlus()
    { return 3; }

// the Master sounds his horn at every 1 mile increment of the chase
inline int dgeMasterHornMiles()
    { return 1; }

// the Master of the Hunt, the huge black-skinned man with antlers
inline bool dgeMasterOfTheHunt()
    { return true; }

// the Master has jet black skin and glowing green eyes
inline bool dgeMasterGreenEyes()
    { return true; }

// his head is crowned by stag antlers and he wears a suit of black leather
inline bool dgeMasterBlackLeather()
    { return true; }

// the Master never speaks
inline bool dgeMasterNeverSpeaks()
    { return true; }

// he runs a few feet behind his pack and sounds his horn every 1 mile
// increment
inline bool dgeMasterRunsBehind()
    { return true; }

// ---- the Pack walk ----

// the hounds have licks of green fire for tongues and green fire for eyes,
// casting the eerie glow but doing no damage
inline bool dgePackGreenFire()
    { return true; }

// the beasts never attack the hunted until all the beings drawn into the Hunt
// have had their chance to kill
inline bool dgePackWaitsForHunters()
    { return true; }

// if the pack is killed the Master battles the being
inline bool dgePackTakesOverIfKilled()
    { return true; }

// the death of any member goes unnoticed by the rest and disappears after the
// battle
inline bool dgePackDeathsUnnoticed()
    { return true; }

// ---- the Wild Hunt doctrine ----

// the Wild Hunt always begins ten miles from the source of evil
inline int dgeHuntStartMiles()
    { return 10; }

// each mile nearer the source, a 10 percent chance the observer becomes the
// object of the Hunt
inline int dgeHuntSpotPctPerMile()
    { return 10; }

// beings passed by the Hunt look at the pack on a 25 percent chance
inline int dgeHuntLookPct()
    { return 25; }

// beings that see it and fail the save have a 90 percent chance of becoming
// the hunted
inline int dgeHuntHuntedPct()
    { return 90; }

// all who have been in the Hunt have a 50 percent chance of being ensnared
// again at every sighting
inline int dgeHuntResnarePct()
    { return 50; }

// the pack appears in numbers of 20 hounds
inline int dgeHuntPackCount()
    { return 20; }

// each hound has 30 hit points (the printed hit dice/points line)
inline int dgeHuntHoundHP()
    { return 30; }

// the Wild Hunt exists in all lands where druids and their deities dwell - a
// physical manifestation of life force
inline bool dgeHuntManifestation()
    { return true; }

// it always takes on the same form: one huge black-skinned antlered man and
// his pack of hounds
inline bool dgeHuntOneForm()
    { return true; }

// the Hunt appears whenever there is evil in the land - an evil temple, a
// 12th level evil priest, or a grossly evil act
inline bool dgeHuntSummonedByEvil()
    { return true; }

// the noise of the howling dogs or the Master horn can be heard for miles in
// the night
inline bool dgeHuntPursuitNoise()
    { return true; }

// any being actively pursuing the noise becomes part of the Hunt when they
// sight the pack and its master
inline bool dgeHuntPursuersJoin()
    { return true; }

// beings taken into the Hunt become the hunters or the hunted
inline bool dgeHuntTwoRoles()
    { return true; }

// the Hunt passes close by the source of evil but never enters a building,
// passing within inches
inline bool dgeHuntNeverEntersBuildings()
    { return true; }

// there is only one Hunt on the Prime Material Plane on any given night,
// drawn to the greatest evil in the Celtic area
inline bool dgeHuntOnePerNight()
    { return true; }

// if the Hunt finds a being to hunt, it attacks to kill and disappears at its
// summoning source
inline bool dgeHuntKillsOrDisappears()
    { return true; }

// if no one becomes the hunted after ten miles, the pack turns on the nearest
// big game creature
inline bool dgeHuntBigGameFallback()
    { return true; }

// hunters must attack the quarry even against their alignment - paladins
// might have to attack helpless women
inline bool dgeHuntCompelledAlignment()
    { return true; }

// the Master and pack can be slain, only to reappear the next night - the
// force creating the Hunt is eternal
inline bool dgeHuntEternal()
    { return true; }

// the magic of the Hunt sweeps along its members, mounted or on foot, to keep
// the hound pace
inline bool dgeHuntKeepsPace()
    { return true; }

// the Hunt pursues on the ground but can run right into the air over
// obstacles or difficult terrain
inline bool dgeHuntFlies()
    { return true; }

// when the hunted is run down there is an instant melee to the death; all
// fight to the death, no holding back
inline bool dgeHuntDeathMelee()
    { return true; }

// the only escapes: run out of the 10 mile radius, elude the pack until
// morning, or slay the Master and his pack
inline bool dgeHuntEscape()
    { return true; }

// any being that has been part of the Hunt has a 50% chance of becoming
// ensnared again with every sighting of the Master and his pack
inline bool dgeHuntSightingResnare()
    { return true; }

// ---- the tathlum and the torc ----

// the tathlum: one day per lime coat
inline int dgeTathlumCoatDays()
    { return 1; }

// the tathlum: each coat takes one week to dry
inline int dgeTathlumCoatWeeks()
    { return 1; }

// the tathlum: one-half the hit points are taken from a relative of the head
inline int dgeTathlumRelativeDiv()
    { return 2; }

// the tathlum: a weapon of war anyone of the Celtic religions can make - an
// enemy head coated with lime into a rock hard ball
inline bool dgeTathlumWeapon()
    { return true; }

// thrown at friends of the former head owner under bright sunshine, it
// damages up to a fraction of the original hit points (the fraction garbles
// in both voices - flagged)
inline bool dgeTathlumSunshine()
    { return true; }

// the tathlum is usable only once
inline bool dgeTathlumOnceOnly()
    { return true; }

// the Torc of the Gods, made by Goibhnie: the holder can shape change or
// polymorph others
inline bool dgeTorcOfTheGods()
    { return true; }

// the Torc is like the other druidical torcs but made of rare metals with a
// large gem of random type set into the front
inline bool dgeTorcRareMetals()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Dunatis the printed -10; Silvanus -4 - the IA
// recovery of the Termux fold-garbled line)
inline int dgeCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -4;
        case 2:
            return -4;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -10;
        case 6:
            return -4;
        case 7:
            return 0;
        case 8:
            return -2;
        case 9:
            return 6;
        case 10:
            return -4;
        case 11:
            return -4;
        case 12:
            return -6;
        case 13:
            return -4;
        case 14:
            return 0;
        case 15:
            return 5;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all sixteen read
// single this round)
inline int dgeCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (400 for Dagda down to 30 per hound)
inline int dgeCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 325;
        case 2:
            return 325;
        case 3:
            return 150;
        case 4:
            return 300;
        case 5:
            return 350;
        case 6:
            return 329;
        case 7:
            return 375;
        case 8:
            return 389;
        case 9:
            return 100;
        case 10:
            return 388;
        case 11:
            return 390;
        case 12:
            return 310;
        case 13:
            return 333;
        case 14:
            return 100;
        case 15:
            return 30;
        default:
            return 0;
        }
    }

// The primary move cells (0 = the printed Variable: Morrigan the any-speed
// chase doctrine; Silvanus reads 18 over 48 through forests - the IA recovery
// of the Termux fold)
inline int dgeCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 24;
        case 6:
            return 9;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 0;
        case 11:
            return 15;
        case 12:
            return 12;
        case 13:
            return 18;
        case 14:
            return 18;
        case 15:
            return 18;
        default:
            return 0;
        }
    }

// The alternate move cells (0 = a single printed move)
inline int dgeCbtMoveAlt(int b)
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
            return 48;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 48;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The attacks-per-round numerator cells (Brigit and Silvanus read the printed
// 3/2)
inline int dgeCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 1;
        default:
            return 0;
        }
    }

// The attacks-per-round denominator cells (0 = a single printed figure)
inline int dgeCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
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
            return 2;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (Diancecht the printed 100 percent; the Pack 15
// percent)
inline int dgeCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 75;
        case 2:
            return 50;
        case 3:
            return 20;
        case 4:
            return 100;
        case 5:
            return 10;
        case 6:
            return 75;
        case 7:
            return 90;
        case 8:
            return 75;
        case 9:
            return 35;
        case 10:
            return 50;
        case 11:
            return 10;
        case 12:
            return 85;
        case 13:
            return 30;
        case 14:
            return 25;
        case 15:
            return 15;
        default:
            return 0;
        }
    }

// The size-in-inches cells (the foot-mark-as-1 decode: Cu Chulainn 6 feet 4
// inches - 76, Math 5 feet 4 inches - 64; the Master and Silvanus 7 feet; the
// Pack L, 4 feet at the shoulder - 48)
inline int dgeCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 84;
        case 2:
            return 72;
        case 3:
            return 76;
        case 4:
            return 72;
        case 5:
            return 72;
        case 6:
            return 72;
        case 7:
            return 84;
        case 8:
            return 72;
        case 9:
            return 64;
        case 10:
            return 72;
        case 11:
            return 72;
        case 12:
            return 72;
        case 13:
            return 84;
        case 14:
            return 84;
        case 15:
            return 48;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil; Diancecht the 25th level cleric)
inline int dgeClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 25;
        case 5:
            return 15;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 14;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (99 = the printed See below: Lugh the 30th level
// druidical-spell doctrine)
inline int dgeClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 14;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 99;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 15;
        case 13:
            return 14;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level floor cells
inline int dgeClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 14;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 0;
        case 8:
            return 16;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 13;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells
inline int dgeClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 14;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 0;
        case 8:
            return 16;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 13;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells (the Celtic fighter-slot rangers: Arawn 17, Cu
// Chulainn 18, Lugh 19, Morrigan 20, Nuada 20, the Master 15)
inline int dgeClsRanger(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 17;
        case 2:
            return 0;
        case 3:
            return 18;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 19;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 15;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the printed See below: Arawn the
// third-level-spells doctrine, Brigit the 35th level fire spells, Manannan;
// Math the printed 30)
inline int dgeClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 99;
        case 2:
            return 99;
        case 3:
            return 0;
        case 4:
            return 12;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 99;
        case 9:
            return 30;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist level cells (Dagda 15th in each, Oghma 18th in each,
// Silvanus the 19th level illusionist, Cu Chulainn 12, Math 10)
inline int dgeClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 12;
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
            return 10;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 19;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (0 = Nil - none printed this round)
inline int dgeClsThief(int b)
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
        default:
            return 0;
        }
    }

// The assassin level cells (Morrigan the 15th, Nuada the 12th)
inline int dgeClsAssassin(int b)
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
            return 15;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (0 = Nil - none printed this round)
inline int dgeClsMonk(int b)
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
        default:
            return 0;
        }
    }

// The bard level cells (Dagda 20, Brigit 18, Dunatis 20, Lugh 19, Oghma 20,
// the Morrigan/Nuada 10, Diancecht 10, Goibhnie 15, Silvanus 15, Cu Chulainn
// 8)
inline int dgeClsBard(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 18;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 15;
        case 7:
            return 19;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 20;
        case 13:
            return 15;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the Master reads the printed S:18(00)(+3, +6); the Pack
// monster row reads the all-sentinel line)
inline int dgeAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 20;
        case 4:
            return 22;
        case 5:
            return 25;
        case 6:
            return 25;
        case 7:
            return 23;
        case 8:
            return 24;
        case 9:
            return 18;
        case 10:
            return 25;
        case 11:
            return 25;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 18;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (Math the printed +1)
inline int dgeAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 1;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 3;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (Math the printed +2; Oghma
// the asterisked 14 - the See below equal-plus-own doctrine)
inline int dgeAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 11;
        case 2:
            return 14;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 2;
        case 10:
            return 14;
        case 11:
            return 14;
        case 12:
            return 14;
        case 13:
            return 14;
        case 14:
            return 6;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The intelligence cells (Cu Chulainn 17: the Termux 1117 against the IA 1:97
// misread)
inline int dgeAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 24;
        case 2:
            return 22;
        case 3:
            return 17;
        case 4:
            return 25;
        case 5:
            return 20;
        case 6:
            return 24;
        case 7:
            return 25;
        case 8:
            return 24;
        case 9:
            return 18;
        case 10:
            return 22;
        case 11:
            return 22;
        case 12:
            return 25;
        case 13:
            return 24;
        case 14:
            return 18;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The wisdom cells
inline int dgeAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 22;
        case 3:
            return 16;
        case 4:
            return 25;
        case 5:
            return 22;
        case 6:
            return 23;
        case 7:
            return 24;
        case 8:
            return 23;
        case 9:
            return 18;
        case 10:
            return 19;
        case 11:
            return 19;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 18;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The dexterity cells
inline int dgeAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 25;
        case 8:
            return 21;
        case 9:
            return 18;
        case 10:
            return 25;
        case 11:
            return 25;
        case 12:
            return 22;
        case 13:
            return 24;
        case 14:
            return 18;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The constitution cells (the printed C: column)
inline int dgeAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 18;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 24;
        case 8:
            return 24;
        case 9:
            return 18;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 20;
        case 13:
            return 25;
        case 14:
            return 18;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The charisma cells (Morrigan reads the printed 21 or -1 - the alt value
// rides the consts; the hideous-face doctrine)
inline int dgeAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 17;
        case 4:
            return 24;
        case 5:
            return 23;
        case 6:
            return 19;
        case 7:
            return 24;
        case 8:
            return 22;
        case 9:
            return 18;
        case 10:
            return 21;
        case 11:
            return 24;
        case 12:
            return 23;
        case 13:
            return 23;
        case 14:
            return 15;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The psionic cells (Math reads the printed 200 point score like the R851
// Merlin 300 - a score, not a roman-numeral class; the classes ride the
// roster grid)
inline int dgeAbiPsi(int b)
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
            return 200;
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Dagda through the Pack)
inline int dgeRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (26-31, the folio offset PRINT = PDF - 1)
inline int dgeRosPage(int b)
    {
        switch (b) {
        case 0:
            return 26;
        case 1:
            return 26;
        case 2:
            return 27;
        case 3:
            return 27;
        case 4:
            return 27;
        case 5:
            return 27;
        case 6:
            return 28;
        case 7:
            return 28;
        case 8:
            return 28;
        case 9:
            return 28;
        case 10:
            return 29;
        case 11:
            return 29;
        case 12:
            return 29;
        case 13:
            return 30;
        case 14:
            return 31;
        case 15:
            return 31;
        default:
            return 0;
        }
    }

// The alignment cells (0 lawful good, 1 neutral good, 4 neutral, 5 chaotic
// neutral, 6 lawful evil - the R852 code scheme)
inline int dgeRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 hero or no-rank-line, 3 monster
// format: the seven greater gods, the five lesser, Cu Chulainn/Math/the
// Master, the Pack)
inline int dgeRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        default:
            return 0;
        }
    }

// The psionic class cells (6 = VI, 2 = Dagda II, 4 = Oghma IV, 0 = Nil or a
// printed score - the Math 200 rides the ability grid)
inline int dgeRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 4;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The plane cells (1 Concordant Opposition, 2 the Prime Material Plane -
// Arawn, 0 none printed: Cu Chulainn, Math, the Master, the Pack)
inline int dgeRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The fixed-damage cells (1 = a printed damage figure: the eleven printed
// rows; 0 = by weapon type or See below: Lugh, Manannan, Math, Nuada, Oghma,
// the Master)
inline int dgeRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
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
        default:
            return 0;
        }
    }

// The in-each cells (1 = a printed Nth level in each class line: Dagda
// magic-user/illusionist 15, Oghma both slots, Silvanus cleric/druid 14)
inline int dgeRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return 0;
        }
    }

// The Wild Hunt cells (1 = a member of the Hunt roster: the Master and the
// Pack; the fourteen mythos beings read 0)
inline int dgeRosWildHunt(int b)
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
            return 1;
        case 15:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
