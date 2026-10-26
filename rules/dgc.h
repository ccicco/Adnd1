// =========================================================================================
// Adnd1 - rules/dgc.h
// the Arthurian mythos - the D&DG walk round three, print pp. 17-21: the
// knights of the Round Table - the chivalry doctrine, the two knight
// templates, the two printed rosters, and thirteen named beings from King
// Arthur to Sir Tristram.
// census 773 -> 774.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 018-022; the second printing); the
// collation voice: the archive.org 1st-print derivative (djvu.txt + djvu.xml
// word geometry). The adjudications: Garlon hit points 80 and one attack (the
// IA xml words, clean, against the Termux fold), the Arthur 14th level
// paladin fighter line (the IA voice; the Termux extract dropped the line),
// the Gawaine Neutral alignment (the 107px geometry match), the Morgan 5 feet
// 4 inches and Palomides 5 and a half feet sizes (both voices), the Merlin
// psionic 300 point score with the B C E over All modes (both voices), and
// the evil-roster Damas and King Mark entries (the IA voice; the Termux
// two-column interleave dropped them). The Gawaine hit points pin the
// second-print extract 112 against the 1st-print 172 - flagged for the
// physical-copy eyeball.
//
// the 0 sentinels: ACAlt 0 = a single printed armor class (the two templates
// read the printed 3 to -2 range); MoveAlt 0 = a single printed move; AtD 0 =
// a single printed attacks figure; the magic resistance 0 = the printed
// Standard (all fifteen); the size 0 = the unresolved or ranged cell (the
// renown template 5-foot-4-to-6 range, the Garlon garble); the class-grid 0 =
// Nil or none printed; the ability-grid template rows are all 0 (the printed
// Specials ride the consts); the psi 0 = Nil (Merlin carries the printed
// 300); the roster flags 0 = the doctrine does not apply; the LawfulPct 0 = a
// fixed alignment.
//
namespace rules {

// ---- the R851 census ----

// the Arthurian mythos round: the D&DG walk round three, print pp. 17-21
inline int dgcRound()
    { return 851; }

// the walk opens at print p. 17 (the chivalry doctrine and the knight
// templates)
inline int dgcPrintStart()
    { return 17; }

// the walk closes at print p. 21 (the Sir Tristram block)
inline int dgcPrintEnd()
    { return 21; }

// the fifteen beings of the Arthurian mythos: the two knight templates and
// thirteen named beings
inline int dgcBeingCount()
    { return 15; }

// the four grids: combat, class, ability, roster
inline int dgcTableCount()
    { return 4; }

// no chains this round - the grids and the prose pins carry the walk
inline int dgcChainCount()
    { return 0; }

// zero registry defs touched - the MM1 live registry floor holds at 995
inline int dgcRegistryFloor()
    { return 995; }

// the combat grid row count (one row per being)
inline int dgcCbtRows()
    { return 15; }

// the class grid row count
inline int dgcClsRows()
    { return 15; }

// the ability grid row count
inline int dgcAbiRows()
    { return 15; }

// the roster grid row count
inline int dgcRosRows()
    { return 15; }

// the named knights of the two printed rosters: 90 good or neutral + 13 evil
inline int dgcKnightCount()
    { return 103; }

// the good or neutral roster (print pp. 17-18)
inline int dgcGoodKnightCount()
    { return 90; }

// the evil roster (print p. 18)
inline int dgcEvilKnightCount()
    { return 13; }

// the asterisked knights of quality across both rosters
inline int dgcQualityKnightCount()
    { return 29; }

// the knights of quality in the good or neutral roster
inline int dgcGoodQualityCount()
    { return 26; }

// the knights of quality in the evil roster: Edward the Knight Perilous,
// Mordred, Turquine
inline int dgcEvilQualityCount()
    { return 3; }

// ---- the chivalry doctrine ----

// Sir Thomas Malory's Le Morte D'Arthur collected the legends of Arthur and
// his Knights of the Round Table
inline bool dgcMaloryCollected()
    { return true; }

// Arthur's knights represent the concept of chivalry to modern readers more
// than any other group
inline bool dgcKnightsRepresentChivalry()
    { return true; }

// chivalrous conduct basically means playing fair
inline bool dgcChivalryIsFairPlay()
    { return true; }

// taking advantage of an opponent's misfortune is dishonorable
inline bool dgcMisfortuneDishonorable()
    { return true; }

// fighting at better-than-even odds is dishonorable
inline bool dgcBetterOddsDishonorable()
    { return true; }

// a chivalrous knight shows respect to ladies and good clerics
inline bool dgcRespectsLadiesAndClerics()
    { return true; }

// a chivalrous knight is suspicious of sorcery and will avoid it if possible
inline bool dgcSuspiciousOfSorcery()
    { return true; }

// knights undertake quests to win fame and prove virtue, swearing oaths of
// unceasing effort
inline bool dgcQuestsWithOaths()
    { return true; }

// the knights of the Round Table may not fit into some AD&D worlds - the trip
// to Arthur's Britain is a DM spice option
inline bool dgcRoundTableOptional()
    { return true; }

// more useful information can be found in TSR's KNIGHTS OF CAMELOT Fantasy
// Boardgame
inline bool dgcCamelotBoardgameReference()
    { return true; }

// knights always have a high quality heavy war-horse
inline bool dgcKnightsHaveWarhorse()
    { return true; }

// knights use a lance, a bastard sword, a two-handed sword, or a morningstar
// in battle
inline bool dgcKnightWeaponList()
    { return true; }

// knights always have a lesser beast to ride when not fighting
inline bool dgcKnightsHaveLesserBeast()
    { return true; }

// knights always have a squire of some type to aid them with their equipment
inline bool dgcKnightsHaveSquire()
    { return true; }

// squires cannot use swords in battle nor fight from horseback until they
// have been made knights
inline bool dgcSquiresRestrained()
    { return true; }

// average knights will most often kill their defeated opponents, rather than
// grant mercy
inline bool dgcAverageKnightsKill()
    { return true; }

// the 5 percent chance that a squire is better at fighting than the knight he
// serves
inline int dgcSquireBetterPct()
    { return 5; }

// ---- the knight templates ----

// the average knight of renown: hit points variable with level but never less
// than 60
inline int dgcRenownHPFloor()
    { return 60; }

// the average knight of renown: 8th through 10th level fighter
inline int dgcRenownFighterLo()
    { return 8; }

// the fighter level ceiling
inline int dgcRenownFighterHi()
    { return 10; }

// the renown specials: variable numbers never below 10
inline int dgcRenownSpecialFloor()
    { return 10; }

// the renown specials most often average 15
inline int dgcRenownSpecialAvg()
    { return 15; }

// the average knight of renown: variable alignment but 80 percent lawful
inline int dgcRenownLawfulPct()
    { return 80; }

// the knight of quality: hit points variable with level but never less than
// 70
inline int dgcQualityHPFloor()
    { return 70; }

// the knight of quality: 10th through 13th level fighter
inline int dgcQualityFighterLo()
    { return 10; }

// the fighter level ceiling
inline int dgcQualityFighterHi()
    { return 13; }

// the quality specials: variable numbers never below 13
inline int dgcQualitySpecialFloor()
    { return 13; }

// the quality specials most often average 16
inline int dgcQualitySpecialAvg()
    { return 16; }

// the knight of quality: variable alignment but 85 percent lawful
inline int dgcQualityLawfulPct()
    { return 85; }

// the knight of quality often (60 percent) travels with squires and
// men-at-arms
inline int dgcQualitySquirePct()
    { return 60; }

// the quality knight squires: 1-4
inline int dgcQualitySquireLo()
    { return 1; }

// the squire count ceiling
inline int dgcQualitySquireHi()
    { return 4; }

// the quality knight men-at-arms: 1-10
inline int dgcQualityMenAtArmsLo()
    { return 1; }

// the men-at-arms count ceiling
inline int dgcQualityMenAtArmsHi()
    { return 10; }

// the knight of quality usually (75 percent of the time) grants mercy to all
// who ask during battle
inline int dgcQualityMercyPct()
    { return 75; }

// the knights of quality usually grant mercy (the 75 percent doctrine rides
// the consts)
inline bool dgcQualityKnightsMerciful()
    { return true; }

// ---- the Arthur walk ----

// Excalibur: a +5 lawful good sword of sharpness
inline int dgcExcaliburPlus()
    { return 5; }

// the printed FIGHTER line: 14th level paladin (the IA voice; the Termux
// extract dropped the line)
inline bool dgcArthurPaladin()
    { return true; }

// Arthur pulled the sword from the stone and identified himself as rightful
// king of all England
inline bool dgcArthurSwordFromStone()
    { return true; }

// Uther Pendragon died in Arthur's boyhood; Merlin hid the babe with Sir
// Ector, trained in war by Ector and in kingliness by Merlin
inline bool dgcArthurUtherMerlinEctor()
    { return true; }

// Arthur married his lady Gwynevere and organized the Knights of the Round
// Table to fight for all that is right and proper
inline bool dgcArthurRoundTable()
    { return true; }

// Arthur upholds the idea of lawful righteousness and fair play
inline bool dgcArthurLawfulRighteousness()
    { return true; }

// he wields the sword Excalibur, a lawful good sword of sharpness
inline bool dgcExcaliburSharpness()
    { return true; }

// the scabbard prevents him from being cut by any attack
inline bool dgcScabbardPreventsCutting()
    { return true; }

// thrusting and slashing attacks against Arthur do half damage (from the
// force of the blow); bludgeoning attacks do full damage
inline bool dgcArthurHalfDamageDoctrine()
    { return true; }

// his shield device is a gold dragon
inline bool dgcArthurGoldDragonShield()
    { return true; }

// ---- the Bernlad walk ----

// Bernlad wields a +3 axe
inline int dgcBernladAxePlus()
    { return 3; }

// as long as he wears his bright green armor, Bernlad cannot be hurt by
// physical weapons
inline bool dgcBernladGreenArmor()
    { return true; }

// the armor is enchanted for Bernlad only, and is normal plate mail for
// anyone else
inline bool dgcBernladArmorPersonal()
    { return true; }

// one of the few powerful good knights that would not side with Arthur -
// though he also would not side with Arthur's enemies
inline bool dgcBernladNeutralStance()
    { return true; }

// he was fond of baiting knights of the Round Table to test their courage
inline bool dgcBernladBaitsKnights()
    { return true; }

// ---- the Galahad walk ----

// dressed in white armor
inline bool dgcGalahadWhiteArmor()
    { return true; }

// the bastard son of Sir Launcelot and Princess Elaine
inline bool dgcGalahadParentage()
    { return true; }

// the perfect representation of knighthood - a paragon of purity and
// invincibility
inline bool dgcGalahadParagon()
    { return true; }

// it was he who successfully completed the quest for the Holy Grail
inline bool dgcGalahadHolyGrail()
    { return true; }

// ---- the Gareth walk ----

// the young son of King Lot, Gareth served in the kitchens of King Arthur
inline bool dgcGarethSonOfLot()
    { return true; }

// he became the enemy of Sir Kay, who called him Beaumains
inline bool dgcGarethEnemyOfKay()
    { return true; }

// he was the most modest of all the knights
inline bool dgcGarethModest()
    { return true; }

// he used his great fighting skills to help many a lady in distress,
// especially one Lady Lyoness
inline bool dgcGarethHelpsLadies()
    { return true; }

// noted for the many colors he used on his armor and shield
inline bool dgcGarethManyColors()
    { return true; }

// ---- the Garlon walk ----

// the invisible knight: armor class 1, effectively -3 due to invisibility
inline int dgcGarlonEffectiveAC()
    { return -3; }

// this knight would always fight invisibly
inline bool dgcGarlonFightsInvisibly()
    { return true; }

// only defeated by the combined might of several knights of quality acting in
// concert
inline bool dgcGarlonDefeatedByConcert()
    { return true; }

// given the power of invisibility by a witch of the fens
inline bool dgcGarlonWitchOfTheFens()
    { return true; }

// he promised the witch to only use the power for evil
inline bool dgcGarlonPowerForEvil()
    { return true; }

// ---- the Gawaine walk ----

// from 9 to 10 in the morning he has a 19 strength
inline int dgcGawaineStrEarly()
    { return 19; }

// from 10 to 11 he has a 20 strength
inline int dgcGawaineStrMid()
    { return 20; }

// from 11 to 12 his strength is 21
inline int dgcGawaineStrLate()
    { return 21; }

// the sun-strength window opens at 9 in the morning
inline int dgcGawaineSunStart()
    { return 9; }

// after 12 noon his strength returns to normal
inline int dgcGawaineSunEnd()
    { return 12; }

// his sword, Galatine, is a +2 weapon
inline int dgcGalatinePlus()
    { return 2; }

// Gawaine has been given a magical gift of an unusual nature: from 9 in the
// morning till 12 noon he gains in strength
inline bool dgcGawaineMagicalGift()
    { return true; }

// after 12 his strength returns to normal (the armor move of 6 is at normal
// strength)
inline bool dgcGawaineStrengthReturns()
    { return true; }

// the favorite cousin of King Arthur
inline bool dgcGawaineFavoriteCousin()
    { return true; }

// a revengeful knight who would travel to the ends of the earth to right some
// supposed wrong done to him or his family
inline bool dgcGawaineRevengeful()
    { return true; }

// ---- the Lamorak walk ----

// the son of King Pellinore
inline bool dgcLamorakSonOfPellinore()
    { return true; }

// a constant champion at many tournaments held by Queen Margawse, Lamorak's
// lover
inline bool dgcLamorakTournamentChampion()
    { return true; }

// this knight was the death of several members of the Round Table
inline bool dgcLamorakKilledTable()
    { return true; }

// his greatest enemy was Sir Gawaine and his brothers
inline bool dgcLamorakEnemyOfGawaine()
    { return true; }

// noted for a battle in which he killed 12 renegade knights of Morgan le Fay
inline bool dgcLamorakKilledTwelve()
    { return true; }

// ---- the Launcelot walk ----

// the best of the best in the circle of the Round Table
inline bool dgcLauncelotBestOfBest()
    { return true; }

// able to use all the powers of a Paladin, until he fell from grace by being
// tricked into loving King Pelles' daughter, the lovely Elaine
inline bool dgcLauncelotFellFromGrace()
    { return true; }

// Elaine bore him a son, the knight Sir Galahad
inline bool dgcLauncelotGalahadSon()
    { return true; }

// forced to leave the side of King Arthur, who had treated Launcelot as the
// king's champion
inline bool dgcLauncelotLeftTheKing()
    { return true; }

// he would never fail to aid the king in time of need
inline bool dgcLauncelotNeverFails()
    { return true; }

// he went on all of the most important quests for the king and his weapons
// skills defended the King's side in major battles
inline bool dgcLauncelotQuests()
    { return true; }

// ---- the Merlin walk ----

// Merlin's damage/attack: 1-10
inline int dgcMerlinDmgLo()
    { return 1; }

// the damage/attack ceiling
inline int dgcMerlinDmgHi()
    { return 10; }

// the printed PSIONIC ABILITY: 300 - the point score, not a roman-numeral
// class (both voices)
inline int dgcMerlinPsi()
    { return 300; }

// his demonic heritage allows him to regenerate 1 hit point per melee round
inline int dgcMerlinRegen()
    { return 1; }

// the son of a sorceress and an incubus (a succubus shape-changed into male
// form)
inline bool dgcMerlinParentage()
    { return true; }

// Merlin has a combination of powers and abilities far beyond those of
// mortals
inline bool dgcMerlinPowersBeyondMortals()
    { return true; }

// a great deal of evidence supports the concept that Merlin is a being as
// powerful as the Great Druid with magical powers thrown in
inline bool dgcMerlinGreatDruid()
    { return true; }

// he never uses armor or normal physical weapons
inline bool dgcMerlinNoArmorOrWeapons()
    { return true; }

// his staff is as a staff of many spell storings and acts as a staff of
// striking
inline bool dgcMerlinStaffSpellStorings()
    { return true; }

// with this device Merlin can absorb spells thrown at him and turn the power
// into spells of his own needs (like a staff of the magi)
inline bool dgcMerlinAbsorbsSpells()
    { return true; }

// Merlin can foresee the future in a random manner; his inability to see just
// ahead causes him great problems
inline bool dgcMerlinForeseesRandomly()
    { return true; }

// he always teleports away from danger that could cause him a quick death
inline bool dgcMerlinTeleportsFromDanger()
    { return true; }

// on several occasions he was attacked and suffered damage that would kill a
// mortal man
inline bool dgcMerlinSurvivedMortalDamage()
    { return true; }

// his magical skills allow him to heal the remainder (beyond the
// regeneration)
inline bool dgcMerlinHealsMagically()
    { return true; }

// a very earthy being - a pretty face may cause him to act rather boyish in
// order to impress a lady
inline bool dgcMerlinEarthy()
    { return true; }

// the printed attack/defense modes: attack B, C, E
inline bool dgcMerlinAttackModesBCE()
    { return true; }

// the printed defense modes: All
inline bool dgcMerlinAllDefenses()
    { return true; }

// ---- the Morgan walk ----

// Morgan's damage/attack: 1-4
inline int dgcMorganDmgLo()
    { return 1; }

// the damage/attack ceiling
inline int dgcMorganDmgHi()
    { return 4; }

// she wears a +3 ring of protection
inline int dgcMorganRingPlus()
    { return 3; }

// the half sister to King Arthur
inline bool dgcMorganHalfSister()
    { return true; }

// this sorceress constantly uses the powers of illusion to attempt to become
// queen of the British Isles
inline bool dgcMorganIllusionQueen()
    { return true; }

// Arthur was aware of her evil but never acted openly against her because of
// their blood tie
inline bool dgcMorganBloodTie()
    { return true; }

// as her name indicates (Fay = Faerie), Morgan is at least partially nonhuman
inline bool dgcMorganPartiallyNonhuman()
    { return true; }

// sometimes able to trick knights of the Round Table into her castle
inline bool dgcMorganTricksKnights()
    { return true; }

// she will either seduce them to evil ways or imprison them for a time
inline bool dgcMorganSeduceOrImprison()
    { return true; }

// her special attack: poisoned dagger
inline bool dgcMorganPoisonedDagger()
    { return true; }

// ---- the Palomides walk ----

// a bitter rival of Sir Tristram
inline bool dgcPalomidesRivalOfTristram()
    { return true; }

// noted for the quickness of his scimitar and his courage in battle
inline bool dgcPalomidesScimitar()
    { return true; }

// noted for his use of the composite bow - a weapon not usually used by
// knights of any order
inline bool dgcPalomidesCompositeBow()
    { return true; }

// ---- the Pellinore walk ----

// this knight fought with King Arthur and almost defeated him
inline bool dgcPellinoreFoughtArthur()
    { return true; }

// he later joined the Round Table and became one of the Queen's Guards
inline bool dgcPellinoreRoundTable()
    { return true; }

// Pellinore hunts a strange unique creature, the Questing Beast
inline bool dgcPellinoreQuestingBeast()
    { return true; }

// his family is fated to pursue it, though neither they nor anybody else will
// ever catch it
inline bool dgcPellinoreFatedPursuit()
    { return true; }

// at the time of Arthur's court, Pellinore is just past middle age, though
// still a stout fighter
inline bool dgcPellinorePastMiddleAge()
    { return true; }

// ---- the Tristram walk ----

// known for his skill of arms and savagery in battle, considered by many
// second only to Launcelot in battle skills
inline bool dgcTristramSecondBest()
    { return true; }

// well-known for his ill-fated romance with the beautiful Lady Isolde, who is
// married to the evil and cowardly King Mark
inline bool dgcTristramIsolde()
    { return true; }

// the insanely jealous King searches constantly for ways to discredit or
// destroy the noble Tristram
inline bool dgcTristramMarkJealous()
    { return true; }

// ---- the combat grid ----

// The armor class cells (99 = the printed See below: Bernlad's green armor;
// the templates read the printed range 3 to -2)
inline int dgcCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 99;
        case 4:
            return -4;
        case 5:
            return -2;
        case 6:
            return 1;
        case 7:
            return -2;
        case 8:
            return -2;
        case 9:
            return -3;
        case 10:
            return 2;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return -2;
        case 14:
            return -3;
        default:
            return 0;
        }
    }

// The range ceiling cells for the two template rows (0 = a single printed
// armor class)
inline int dgcCbtACAlt(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
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
        default:
            return 0;
        }
    }

// The hit point cells (the templates carry their floors: never less than 60
// and 70)
inline int dgcCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 70;
        case 2:
            return 123;
        case 3:
            return 99;
        case 4:
            return 120;
        case 5:
            return 105;
        case 6:
            return 80;
        case 7:
            return 112;
        case 8:
            return 99;
        case 9:
            return 141;
        case 10:
            return 175;
        case 11:
            return 39;
        case 12:
            return 93;
        case 13:
            return 65;
        case 14:
            return 120;
        default:
            return 0;
        }
    }

// The primary move cells (inches; Bernlad rides his special armor without the
// note)
inline int dgcCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 15;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 12;
        default:
            return 0;
        }
    }

// The alternate move cells (0 = a single printed move; Palomides reads 12
// over 9 in chain armor; Gawaine's 6 applies at normal strength)
inline int dgcCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 6;
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
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 9;
        case 13:
            return 6;
        case 14:
            return 6;
        default:
            return 0;
        }
    }

// The attacks-per-round numerator cells
inline int dgcCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 2;
        default:
            return 0;
        }
    }

// The attacks-per-round denominator cells (0 = a single printed figure; the
// two templates read the printed 3/2)
inline int dgcCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard - all fifteen read
// Standard)
inline int dgcCbtMR(int b)
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
        default:
            return 0;
        }
    }

// The size-in-inches cells (0 = the unresolved or ranged cell: the renown
// template prints the 5'4"-6' range, Garlon's height garbles in both voices;
// the half-foot cells read 78 for the 6-and-a-half-foot rows and 66 for
// Palomides 5 and a half feet)
inline int dgcCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 78;
        case 2:
            return 72;
        case 3:
            return 84;
        case 4:
            return 84;
        case 5:
            return 72;
        case 6:
            return 0;
        case 7:
            return 72;
        case 8:
            return 78;
        case 9:
            return 78;
        case 10:
            return 72;
        case 11:
            return 64;
        case 12:
            return 66;
        case 13:
            return 76;
        case 14:
            return 72;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil)
inline int dgcClsCleric(int b)
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
        default:
            return 0;
        }
    }

// The druid level cells (Merlin 14th level druid)
inline int dgcClsDruid(int b)
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
            return 14;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level floor cells (the templates carry their printed ranges)
inline int dgcClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 10;
        case 2:
            return 14;
        case 3:
            return 14;
        case 4:
            return 20;
        case 5:
            return 17;
        case 6:
            return 13;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 16;
        case 13:
            return 12;
        case 14:
            return 17;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (the named knights carry lo = hi)
inline int dgcClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 13;
        case 2:
            return 14;
        case 3:
            return 14;
        case 4:
            return 20;
        case 5:
            return 17;
        case 6:
            return 13;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 16;
        case 13:
            return 12;
        case 14:
            return 17;
        default:
            return 0;
        }
    }

// The ranger level cells (0 = Nil - no printed ranger this round)
inline int dgcClsRanger(int b)
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
        default:
            return 0;
        }
    }

// The magic-user level cells (Merlin 15th, Morgan 12th)
inline int dgcClsMagUser(int b)
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
        default:
            return 0;
        }
    }

// The illusionist level cells (Merlin 10th, Morgan 12th in each)
inline int dgcClsIllus(int b)
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
            return 10;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (Garlon 3rd level thief)
inline int dgcClsThief(int b)
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (0 = Nil)
inline int dgcClsAssassin(int b)
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
        default:
            return 0;
        }
    }

// The monk level cells (Palomides 3rd level in each)
inline int dgcClsMonk(int b)
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
            return 3;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The bard level cells (Arthur 5th level bard, Palomides 3rd level in each)
inline int dgcClsBard(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 5;
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
            return 3;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (0 = the printed Special of the two templates - the
// floors and averages ride the consts)
inline int dgcAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 15;
        case 7:
            return 18;
        case 8:
            return 18;
        case 9:
            return 19;
        case 10:
            return 15;
        case 11:
            return 10;
        case 12:
            return 17;
        case 13:
            return 18;
        case 14:
            return 18;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = none printed)
inline int dgcAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells
inline int dgcAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 5;
        default:
            return 0;
        }
    }

// The intelligence cells
inline int dgcAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 17;
        case 4:
            return 15;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 13;
        case 9:
            return 14;
        case 10:
            return 19;
        case 11:
            return 18;
        case 12:
            return 18;
        case 13:
            return 15;
        case 14:
            return 16;
        default:
            return 0;
        }
    }

// The wisdom cells
inline int dgcAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 19;
        case 3:
            return 14;
        case 4:
            return 18;
        case 5:
            return 11;
        case 6:
            return 9;
        case 7:
            return 13;
        case 8:
            return 8;
        case 9:
            return 13;
        case 10:
            return 19;
        case 11:
            return 7;
        case 12:
            return 11;
        case 13:
            return 10;
        case 14:
            return 13;
        default:
            return 0;
        }
    }

// The dexterity cells
inline int dgcAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 16;
        case 3:
            return 13;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 15;
        case 7:
            return 18;
        case 8:
            return 18;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 17;
        case 12:
            return 18;
        case 13:
            return 18;
        case 14:
            return 19;
        default:
            return 0;
        }
    }

// The constitution cells (the printed C: column)
inline int dgcAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 18;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 18;
        case 12:
            return 17;
        case 13:
            return 18;
        case 14:
            return 18;
        default:
            return 0;
        }
    }

// The charisma cells
inline int dgcAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 12;
        case 4:
            return 18;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 17;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 18;
        case 12:
            return 18;
        case 13:
            return 15;
        case 14:
            return 17;
        default:
            return 0;
        }
    }

// The psionic cells (0 = Nil; Merlin reads the printed 300 point score - a
// score, not a roman-numeral class)
inline int dgcAbiPsi(int b)
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
            return 300;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, the two templates through
// Tristram)
inline int dgcRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (17-21, the folio offset PRINT = PDF - 1)
inline int dgcRosPage(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 17;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 19;
        case 5:
            return 19;
        case 6:
            return 19;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 21;
        case 13:
            return 21;
        case 14:
            return 21;
        default:
            return 0;
        }
    }

// The alignment cells (0 lawful good, 1 neutral good, 2 chaotic good, 3
// neutral, 7 chaotic evil, 8 lawful neutral, and the two variable-template
// codes: 7? no - the variable codes are 4 = the renown variable-but-80-lawful
// and 5 = the quality variable-but-85-lawful; see the builder note)
inline int dgcRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 3;
        case 13:
            return 8;
        case 14:
            return 3;
        default:
            return 0;
        }
    }

// The paladin flag cells (1 = the printed paladin class: Arthur, Galahad,
// Launcelot)
inline int dgcRosPaladin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
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
        default:
            return 0;
        }
    }

// The attack/defense modes cells (1 = modes printed: Merlin B, C, E over All)
inline int dgcRosPsiModes(int b)
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
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The hit-point-floor cells (1 = the printed variable-with-level floor: the
// two templates)
inline int dgcRosHPFloor(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
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
        default:
            return 0;
        }
    }

// The strength-varies cells (1 = Gawaine, the sun-strength doctrine)
inline int dgcRosStrVaries(int b)
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
            return 1;
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
        default:
            return 0;
        }
    }

// The fixed-damage cells (1 = a printed damage/attack figure instead of by
// weapon type: Merlin 1-10, Morgan 1-4)
inline int dgcRosDmgFixed(int b)
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
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The lawful percent cells (the templates: 80 and 85; 0 = a fixed alignment)
inline int dgcRosLawfulPct(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 85;
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
        default:
            return 0;
        }
    }

}   // namespace rules
