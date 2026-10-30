// =========================================================================================
// Adnd1 - rules/mkn.h
// The Dragon issue-18 opener part two - the Sullin new spells, the monkish
// weapons and kedo combat, and the effective use of poison: the three-chain
// round
// census 857 -> 858.
//
// Pinned from The Dragon Vol. III No. 4 (September 1978), the
// Curtiss-provided scan voice (single voice: the issue-18 source is the
// uploaded Dm18.pdf with its mistral-ocr transcript; no archive.org djvu
// cross-check exists for issue 18). PRINT FOLIO = PDF PAGE MINUS TWO,
// verified at the page feet in the R934 intake (folios 3, 9, 13, 14, 19, 21,
// 24 and 31 print at the PDF pages 5, 11, 15, 16, 21, 23, 26 and 33); this
// round pins print 13 (PDF 15), print 23-24 (PDF 25-26) and print 24 (PDF
// 26).
//
// Print quirks pinned AS SCANNED, noted never silent: the kedo attack list
// prints 2-8 while claiming eight attacks - attack 1 never prints, and the
// migi-do row appears only in the matrix (presumably the missing attack 1);
// the kedo notes key prints dla, dra, ara, ala, x and the dash but the matrix
// carries one dar - a transposition of dra at the migi-men vs hidari-men
// crossing, pinned as printed; the migi-men, migi-do, gyaku-do, kote,
// hidari-kote and tsuki diagonal cells print as cuts (six diagonal breaks,
// pinned as printed) and the migi-do and gyaku-do blocked cells print crossed
// against each other; the G.M./North Wind rank prints the doubled word
// bowbow; the poison units print as scanned - the A and B death in turns, the
// C death in days, the A stricken week pinned as 7 days and the C one-hour
// delay pinned as 60 minutes; the Sullin spell list ends level 6 with cont pg
// 21 but the levels 7-9 NEVER printed in TD18 - the watch rides to TD 19; no
// numeric cell garbles beyond that, so the only sentinel cells are the three
// never-printed poison A unconscious entries.
//
namespace rules {

// ---- the Sullin new spells, levels 1-6 (print 13) ----

// the total Sullin new-spell count - nineteen spells across levels one to six
// (print 13, PDF 15)
inline int mknSullinSpells()
    { return 19; }

// the level-one spell count - Nature Call alone (print 13, PDF 15)
inline int mknSpellsLvl1()
    { return 1; }

// the level-two spell count - Magic Missile II and Moon Runes (print 13, PDF
// 15)
inline int mknSpellsLvl2()
    { return 2; }

// the level-three spell count - Flamebolt, Mystic Rope, Pit of Flame, Word of
// Warding (print 13, PDF 15)
inline int mknSpellsLvl3()
    { return 4; }

// the level-four spell count - Force Field, Extend I, Shatterray, Wall of
// Water (print 13, PDF 15)
inline int mknSpellsLvl4()
    { return 4; }

// the level-five spell count - Extend II and Beam of Blasting (print 13, PDF
// 15)
inline int mknSpellsLvl5()
    { return 2; }

// the level-six spell count - Conjure Djinn/Efreet, Density Control, Extend
// III, Combine I, Call Spirit, Rust Monster Touch (print 13, PDF 15)
inline int mknSpellsLvl6()
    { return 6; }

// Nature Call summons small mammals and birds - the minimum of the 1-10
// (print 13, PDF 15)
inline int mknNcrSummonMin()
    { return 1; }

// Nature Call summon maximum - 1-10 small mammals and/or birds up to
// squirrels or small hawks (print 13, PDF 15)
inline int mknNcrSummonMax()
    { return 10; }

// Nature Call subtracts two from the hit die of more intelligent creatures
// (print 13, PDF 15)
inline int mknNcrHitDiePenalty()
    { return 2; }

// Nature Call messenger - one eagle-sized creature carries to any point
// within three days travel (print 13, PDF 15)
inline int mknNcrMessengerDays()
    { return 3; }

// Nature Call arrival - the summoned creatures take 1-4 melee turns to
// arrive, the minimum (print 13, PDF 15)
inline int mknNcrArrivalTurnsMin()
    { return 1; }

// Nature Call arrival maximum - 1-4 melee turns (print 13, PDF 15)
inline int mknNcrArrivalTurnsMax()
    { return 4; }

// Magic Missile II fires one +2 arrow (print 13, PDF 15)
inline int mknMmiPlusTwoArrows()
    { return 1; }

// Magic Missile II fires two +1 arrows (print 13, PDF 15)
inline int mknMmiPlusOneArrows()
    { return 2; }

// Magic Missile II adds a like amount for every fifth level advanced beyond
// third (print 13, PDF 15)
inline int mknMmiBonusEveryLevels()
    { return 5; }

// Magic Missile II progression base - the beyond-third level (print 13, PDF
// 15)
inline int mknMmiBeyondLevel()
    { return 3; }

// Moon Runes duration - one year maximum (print 13, PDF 15)
inline int mknMreMaxDurationYears()
    { return 1; }

// Flamebolt damage to living beings - 3-24 points, the dice count (print 13,
// PDF 15)
inline int mknFlbLivingDice()
    { return 3; }

// Flamebolt living damage - 3-24, the d8 sides (print 13, PDF 15)
inline int mknFlbLivingDieSides()
    { return 8; }

// Flamebolt damage to undead - 3-30 points, the dice count (print 13, PDF 15)
inline int mknFlbUndeadDice()
    { return 3; }

// Flamebolt undead damage - 3-30, the d10 sides (print 13, PDF 15)
inline int mknFlbUndeadDieSides()
    { return 10; }

// Flamebolt ignites flammables within five feet of the impact point (print
// 13, PDF 15)
inline int mknFlbIgniteRadiusFeet()
    { return 5; }

// Flamebolt range - 240 feet (print 13, PDF 15)
inline int mknFlbRangeFeet()
    { return 240; }

// Flamebolt fires the level of the caster plus 1-3 times - the bonus minimum
// (print 13, PDF 15)
inline int mknFlbFiresBonusMin()
    { return 1; }

// Flamebolt fires the level plus 1-3 times - the bonus maximum (print 13, PDF
// 15)
inline int mknFlbFiresBonusMax()
    { return 3; }

// Mystic Rope - a magical rope up to 100 feet long (print 13, PDF 15)
inline int mknMroLengthFeet()
    { return 100; }

// Mystic Rope takes one point per four feet of length (print 13, PDF 15)
inline int mknMroHpPerFeet()
    { return 4; }

// Mystic Rope regenerates one foot per melee turn (print 13, PDF 15)
inline int mknMroRegenFeetPerTurn()
    { return 1; }

// Pit of Flame - the conjured pit is 20 x 20 x 5 feet, the width (print 13,
// PDF 15)
inline int mknPofWidthFeet()
    { return 20; }

// Pit of Flame - the pit length, 20 feet (print 13, PDF 15)
inline int mknPofLengthFeet()
    { return 20; }

// Pit of Flame - the pit depth, five feet (print 13, PDF 15)
inline int mknPofDepthFeet()
    { return 5; }

// Pit of Flame duration - three turns (print 13, PDF 15)
inline int mknPofDurationTurns()
    { return 3; }

// Pit of Flame - a fifth level pit does 3 dice per melee turn, the half-level
// rounded up example (print 13, PDF 15)
inline int mknPofFifthLevelDice()
    { return 3; }

// Word of Warding duration - one melee turn (print 13, PDF 15)
inline int mknWowDurationMeleeTurns()
    { return 1; }

// Word of Warding used off-initiative - the speaker may use no spells higher
// than third level when his initiative comes again (print 13, PDF 15)
inline int mknWowImmediateMaxSpellLevel()
    { return 3; }

// Force Field - a spherical field ten feet across (print 13, PDF 15)
inline int mknFfdDiameterFeet()
    { return 10; }

// Force Field range - 60 feet (print 13, PDF 15)
inline int mknFfdRangeFeet()
    { return 60; }

// Extend I extends the range of 1st-3rd level spells by 50 percent (print 13,
// PDF 15)
inline int mknExtOneMaxSpellLevel()
    { return 3; }

// Extend I range extension - 50 percent (print 13, PDF 15)
inline int mknExtOneRangePct()
    { return 50; }

// Shatterray damage - 5-30 points of impact, the dice count (print 13, PDF
// 15)
inline int mknShdDamageDice()
    { return 5; }

// Shatterray damage - 5-30, the d6 sides (print 13, PDF 15)
inline int mknShdDamageDieSides()
    { return 6; }

// Shatterray - structures such as walls and buildings suffer 20 structure
// points as per Chainmail (print 13, PDF 15)
inline int mknShdStructurePoints()
    { return 20; }

// Shatterray adds one damage die for every level the caster progresses beyond
// seventh (print 13, PDF 15)
inline int mknShdBonusBeyondLevel()
    { return 7; }

// Shatterray damage caps at a maximum of 12 dice (print 13, PDF 15)
inline int mknShdMaxDamageDice()
    { return 12; }

// Shatterray adds five structural damage points per level beyond seventh
// (print 13, PDF 15)
inline int mknShdStructBonusPerLevel()
    { return 5; }

// Shatterray structural damage caps at 60 points (print 13, PDF 15)
inline int mknShdMaxStructPoints()
    { return 60; }

// Shatterray range - 120 feet (print 13, PDF 15)
inline int mknShdRangeFeet()
    { return 120; }

// Wall of Water - a wall up to 50 x 20 feet, the length (print 13, PDF 15)
inline int mknWwdLengthFeet()
    { return 50; }

// Wall of Water - the wall height, 20 feet (print 13, PDF 15)
inline int mknWwdHeightFeet()
    { return 20; }

// Wall of Water - flaming creatures take 5-30 points when breaking through,
// the dice count (print 13, PDF 15)
inline int mknWwdBreakDice()
    { return 5; }

// Wall of Water break-through damage - 5-30, the d6 sides (print 13, PDF 15)
inline int mknWwdBreakDieSides()
    { return 6; }

// Wall of Water prevents creatures with fewer than five hit dice from passing
// through (print 13, PDF 15)
inline int mknWwdBlocksBelowHd()
    { return 5; }

// Wall of Water range - 30 feet (print 13, PDF 15)
inline int mknWwdRangeFeet()
    { return 30; }

// Wall of Water duration - one hour (print 13, PDF 15)
inline int mknWwdDurationHours()
    { return 1; }

// Extend II - as Extend I but applies to fourth level spells as well (print
// 13, PDF 15)
inline int mknExtTwoMaxSpellLevel()
    { return 4; }

// Beam of Blasting - the blast area is 30 feet across (print 13, PDF 15)
inline int mknBbbBlastDiameterFeet()
    { return 30; }

// Beam of Blasting does one point of damage per Gold Piece weight of matter
// transmuted (print 13, PDF 15)
inline int mknBbbDmgPerGp()
    { return 1; }

// Beam of Blasting damage caps at 50 points maximum (print 13, PDF 15)
inline int mknBbbMaxDamage()
    { return 50; }

// Beam of Blasting adds a like amount for every three levels the magic-user
// progresses beyond ninth (print 13, PDF 15)
inline int mknBbbBonusEveryLevels()
    { return 3; }

// Beam of Blasting progression base - the beyond-ninth level (print 13, PDF
// 15)
inline int mknBbbBeyondLevel()
    { return 9; }

// Beam of Blasting - a twelfth level caster does 2 points per Gold Piece
// (print 13, PDF 15)
inline int mknBbbTwelfthDmgPerGp()
    { return 2; }

// Beam of Blasting range - 200 feet (print 13, PDF 15)
inline int mknBbbRangeFeet()
    { return 200; }

// Conjure Djinn/Efreet - the conjured djinn or efreet serves for 24 hours
// (print 13, PDF 15)
inline int mknCdeServiceHours()
    { return 24; }

// Density Control duration - three turns (print 13, PDF 15)
inline int mknDcoDurationTurns()
    { return 3; }

// Density Control - at maximum density the caster is armor class one and his
// hands strike as swords (print 13, PDF 15)
inline int mknDcoMaxDensityAc()
    { return 1; }

// Extend III - as Extend II but applies to fifth level spells (print 13, PDF
// 15)
inline int mknExtThreeMaxSpellLevel()
    { return 5; }

// Combine I - spells combine in any combination not exceeding seven spell
// levels (print 13, PDF 15)
inline int mknCmbMaxSpellLevels()
    { return 7; }

// Combine I - three spells maximum (print 13, PDF 15)
inline int mknCmbMaxSpells()
    { return 3; }

// Call Spirit - the shade of a deceased person may be asked two questions
// (print 13, PDF 15)
inline int mknCspQuestions()
    { return 2; }

// Call Spirit - the chance of the ghost knowing an answer should never be
// less than 25 percent (print 13, PDF 15)
inline int mknCspMinChancePct()
    { return 25; }

// Call Spirit - the body, bones or other remains must be within 20 feet
// (print 13, PDF 15)
inline int mknCspRemainsWithinFeet()
    { return 20; }

// Nature Call - the feinting rushes confuse stupid monsters (print 13, PDF
// 15)
inline bool mknNcrConfusesStupidMonsters()
    { return true; }

// Nature Call - the creatures may not be forced into attacks on monsters they
// would normally flee, the undead, demons and the like (print 13, PDF 15)
inline bool mknNcrRefusesFearedFoes()
    { return true; }

// Nature Call - one creature as large as an eagle may carry an object or
// message (print 13, PDF 15)
inline bool mknNcrEagleMessenger()
    { return true; }

// Nature Call - the spell may not be used underground (print 13, PDF 15)
inline bool mknNcrNoUnderground()
    { return true; }

// Moon Runes - the letters may be set to shine or fade under certain
// conditions or after a preset time (print 13, PDF 15)
inline bool mknMreSetToShineOrFade()
    { return true; }

// Mystic Rope - immune to all non-magical forces (print 13, PDF 15)
inline bool mknMroImmuneNonMagical()
    { return true; }

// Mystic Rope - the independent movement makes untying impossible for anyone
// but the conjurer (print 13, PDF 15)
inline bool mknMroUntyingOnlyByConjurer()
    { return true; }

// Pit of Flame - the interrogation use floats the person just above the
// surface until he tells an untruth (print 13, PDF 15)
inline bool mknPofInterrogationFloats()
    { return true; }

// Pit of Flame - the damage is half the caster level rounded up (print 13,
// PDF 15)
inline bool mknPofDamageHalfLevelRoundedUp()
    { return true; }

// Word of Warding - one of the only spells usable while the speaker is meled
// (print 13, PDF 15)
inline bool mknWowUsableWhileMeled()
    { return true; }

// Word of Warding - deflects any one weapon from its intended course toward
// the speaker (print 13, PDF 15)
inline bool mknWowDeflectsOneWeapon()
    { return true; }

// Force Field - similar to a cube of force EXCEPT that it will not block
// magic, the pin IS the conversion noted never silent (print 13, PDF 15)
inline bool mknFfdBlocksMagic()
    { return false; }

// Force Field - cast around any object but it will not move unless the caster
// is inside it (print 13, PDF 15)
inline bool mknFfdMovesOnlyWithCasterInside()
    { return true; }

// Force Field - duration is the level of the caster in turns (print 13, PDF
// 15)
inline bool mknFfdDurationPerLevelTurns()
    { return true; }

// Wall of Water - normal fire cannot pass through the wall (print 13, PDF 15)
inline bool mknWwdBlocksNormalFire()
    { return true; }

// Wall of Water - the swirling currents block missile fire (print 13, PDF 15)
inline bool mknWwdBlocksMissileFire()
    { return true; }

// Beam of Blasting - will not transmute living matter (print 13, PDF 15)
inline bool mknBbbNoLivingMatter()
    { return true; }

// Beam of Blasting - if the object transmuted is held or worn there is no
// save for the holder, otherwise the save halves the damage (print 13, PDF
// 15)
inline bool mknBbbHeldOrWornNoSave()
    { return true; }

// Conjure Djinn/Efreet - at the end of the 24 hours the djinn vanish (print
// 13, PDF 15)
inline bool mknCdeDjinnVanishAtEnd()
    { return true; }

// Conjure Djinn/Efreet - efreets must be forcibly banished by the reversal of
// the spell or attack the summoner (print 13, PDF 15)
inline bool mknCdeEfreetBanishOrAttack()
    { return true; }

// Density Control - the body density alters within a range extending from gas
// to steel (print 13, PDF 15)
inline bool mknDcoGasToSteel()
    { return true; }

// Density Control - at maximum density the hands strike as swords (print 13,
// PDF 15)
inline bool mknDcoHandsStrikeAsSwords()
    { return true; }

// Density Control - any items in contact with the body change also (print 13,
// PDF 15)
inline bool mknDcoItemsInContactChange()
    { return true; }

// Density Control - at minimum density no solid weapon can affect him (print
// 13, PDF 15)
inline bool mknDcoNoSolidWeaponAtMinDensity()
    { return true; }

// Extend III - as Extend II but doubles the range (print 13, PDF 15)
inline bool mknExtThreeDoublesRange()
    { return true; }

// Combine I - duration is that of the shortest spell combined (print 13, PDF
// 15)
inline bool mknCmbDurationAsShortest()
    { return true; }

// Call Spirit - may only be performed at night, the spirits dispelled by
// sunlight (print 13, PDF 15)
inline bool mknCspNightOnly()
    { return true; }

// Call Spirit - the name of the deceased must be known (print 13, PDF 15)
inline bool mknCspNameMustBeKnown()
    { return true; }

// Rust Monster Touch - affects all ferrous metal touched by the caster as if
// touched by a rust monster (print 13, PDF 15)
inline bool mknRmtAsRustMonster()
    { return true; }

// the editor note - a DM must carefully consider each new spell before
// approval, they are NOT recommended for general absorption willy-nilly
// (print 13, PDF 15)
inline bool mknSullinEditorApprovalRequired()
    { return true; }

// the editor note - every spell should have a loophole, some other spell or
// power that will negate it (print 13, PDF 15)
inline bool mknSullinEverySpellNeedsLoophole()
    { return true; }

// the author introduction - any level may research, even a low-level type
// (print 13, PDF 15)
inline bool mknSullinResearchAnyLevel()
    { return true; }

// ---- the monkish weapons and the kedo combat matrix (print 23-24) ----

// the monk rank progression count - Novice, Initiate, Disciple, Immaculate,
// Master, Grand Master, G.M./North Wind (print 23-24, PDF 25-26)
inline int mknMonkRanks()
    { return 7; }

// the distinct monkish weapons described - the live blade, shimia, bokutois,
// the kyudo bow, naginata, yari, rokushakubo, kama, ton-fa/tui-fa, nunchaku,
// sai (print 23, PDF 25)
inline int mknMonkWeapons()
    { return 11; }

// the kedo combat matrix rows - nine attacker moves from shomen to the front
// block (print 24, PDF 26)
inline int mknKedoMoves()
    { return 9; }

// the kedo matrix columns - the nine defender moves sh, h.m., m.m., m.d.,
// g.d., k, h.k., t, b (print 24, PDF 26)
inline int mknKedoDefenses()
    { return 9; }

// the article claims eight different attacks are used in kedo (print 23, PDF
// 25)
inline int mknKedoAttacksClaimed()
    { return 8; }

// the numbered attack list prints 2-8 - seven entries, attack 1 never prints,
// pinned as scanned (print 23, PDF 25)
inline int mknKedoAttacksPrinted()
    { return 7; }

// the kedo matrix code 0 - the cut is blocked, printed as a dash (print 24,
// PDF 26)
inline int mknKedoCodeBlocked()
    { return 0; }

// the kedo matrix code 1 - x, the cut is made (print 24, PDF 26)
inline int mknKedoCodeCut()
    { return 1; }

// the kedo matrix code 2 - dla, the defender left arm is cut (print 24, PDF
// 26)
inline int mknKedoCodeDla()
    { return 2; }

// the kedo matrix code 3 - dra, the defender right arm is cut (print 24, PDF
// 26)
inline int mknKedoCodeDra()
    { return 3; }

// the kedo matrix code 4 - ara, the attacker right arm is cut (print 24, PDF
// 26)
inline int mknKedoCodeAra()
    { return 4; }

// the kedo matrix code 5 - ala, the attacker left arm is cut (print 24, PDF
// 26)
inline int mknKedoCodeAla()
    { return 5; }

// the kedo matrix code 6 - the odd dar at the migi-men vs hidari-men
// crossing, a print transposition of dra, pinned as printed and noted never
// silent; dar appears in the grid but NOT in the printed notes key (print 24,
// PDF 26)
inline int mknKedoCodeDar()
    { return 6; }

// the Japanese bow was about seven feet long, the art known as Kyudo (print
// 23, PDF 25)
inline int mknKyudoBowFeet()
    { return 7; }

// the kyudo bow is between one and two inches thick, the minimum (print 23,
// PDF 25)
inline int mknKyudoThickMinInches()
    { return 1; }

// the kyudo bow thickness maximum, two inches (print 23, PDF 25)
inline int mknKyudoThickMaxInches()
    { return 2; }

// the kyudo draw was a 40 to 50-pound pull, the minimum (print 23, PDF 25)
inline int mknKyudoDrawLbMin()
    { return 40; }

// the kyudo draw maximum, the 50-pound pull (print 23, PDF 25)
inline int mknKyudoDrawLbMax()
    { return 50; }

// an expert can draw up to a 90-pound pull - the G.M./North Wind bow (print
// 23, PDF 25)
inline int mknKyudoExpertDrawLb()
    { return 90; }

// the kyudo arrows are 39 inches in length (print 23, PDF 25)
inline int mknKyudoArrowInches()
    { return 39; }

// the naginata curved-bladed spear - the three basic cuts, waterwheel,
// windmill and butterfly (print 23, PDF 25)
inline int mknNaginataBasicCuts()
    { return 3; }

// the yari straight-bladed spear is between seven and nine feet, the minimum
// (print 23, PDF 25)
inline int mknYariMinFeet()
    { return 7; }

// the yari length maximum, nine feet (print 23, PDF 25)
inline int mknYariMaxFeet()
    { return 9; }

// the rokushakubo - the six-foot staff (print 23, PDF 25)
inline int mknRokFeet()
    { return 6; }

// the rokushakubo diameter is one to two inches, the minimum (print 23, PDF
// 25)
inline int mknRokDiameterMinInches()
    { return 1; }

// the rokushakubo diameter maximum, two inches (print 23, PDF 25)
inline int mknRokDiameterMaxInches()
    { return 2; }

// the ton-fa or tui-fa is a tapered hardwood billet between 15 and 20 inches,
// the minimum (print 23, PDF 25)
inline int mknTonfaMinInches()
    { return 15; }

// the ton-fa length maximum, 20 inches (print 23, PDF 25)
inline int mknTonfaMaxInches()
    { return 20; }

// the ton-fa side-handle is set at a right angle about six inches down from
// the thicker end (print 23, PDF 25)
inline int mknTonfaHandleInches()
    { return 6; }

// the sai short sword is about 15 to 20 inches in length, the minimum (print
// 23, PDF 25)
inline int mknSaiMinInches()
    { return 15; }

// the sai length maximum, 20 inches (print 23, PDF 25)
inline int mknSaiMaxInches()
    { return 20; }

// the Novice can use the naginata, yari, kama and the sai - four weapons
// (print 23-24, PDF 25-26)
inline int mknRankNoviceWeapons()
    { return 4; }

// the Initiate can use the shimia and the bokutois - two weapons (print
// 23-24, PDF 25-26)
inline int mknRankInitiateWeapons()
    { return 2; }

// the Disciple can use the live blade - one weapon (print 24, PDF 26)
inline int mknRankDiscipleWeapons()
    { return 1; }

// the Immaculate can use the rokushakubo and the ton-fa or tui-fa - two
// weapons (print 24, PDF 26)
inline int mknRankImmaculateWeapons()
    { return 2; }

// the Master can use the nunchaku - one weapon (print 24, PDF 26)
inline int mknRankMasterWeapons()
    { return 1; }

// the Grand Master can use the 7-foot bow with the 40-50 lb pull - one weapon
// (print 24, PDF 26)
inline int mknRankGrandMasterWeapons()
    { return 1; }

// the G.M./North Wind can use the 90 lb pull bow - one weapon, printed as the
// doubled bowbow, pinned as scanned (print 24, PDF 26)
inline int mknRankNorthWindWeapons()
    { return 1; }

// the attack list prints 2-8 while claiming eight attacks - attack 1 never
// prints, the gap flagged as scanned (print 23, PDF 25)
inline bool mknKedoAttackOneMissing()
    { return true; }

// the migi-do row appears in the kedo matrix but never in the numbered attack
// list - presumably the missing attack 1, noted never silent (print 23-24,
// PDF 25-26)
inline bool mknKedoMigiDoMatrixOnly()
    { return true; }

// the gyaku-do is the downwards cut at the left side of the breast plate,
// rarely used (print 23, PDF 25)
inline bool mknKedoGyakuDoRarelyUsed()
    { return true; }

// the hidari-kote is valid only if the arm is raised to shoulder height or
// higher (print 23, PDF 25)
inline bool mknKedoHidariKoteShoulderHeight()
    { return true; }

// the tsuki is a thrust at the throat to strike the beard of the man (print
// 23, PDF 25)
inline bool mknKedoTsukiThroat()
    { return true; }

// the Japanese bow can be fired while standing, crouching, or on horseback
// (print 23, PDF 25)
inline bool mknKyudoFiredHorseback()
    { return true; }

// the naginata is used to maim the enemy horse before dealing with the fallen
// rider (print 23, PDF 25)
inline bool mknNaginataMaimsHorseFirst()
    { return true; }

// the yari primary use is for tsuki thrusting or use from horseback, the
// targets the groin/stomach and chest/throat regions (print 23, PDF 25)
inline bool mknYariHorsebackUse()
    { return true; }

// the metal swords are called live blade (print 23, PDF 25)
inline bool mknLiveBladeMetal()
    { return true; }

// the bamboo swords are called shimia (print 23, PDF 25)
inline bool mknShimiaBamboo()
    { return true; }

// the wooden swords are called bokutois (print 23, PDF 25)
inline bool mknBokutoisWooden()
    { return true; }

// the ton-fa or tui-fa can be used in pairs (print 23, PDF 25)
inline bool mknTonfaUsedInPairs()
    { return true; }

// some of these weapons need special skills to use them, i.e. the nunchaku
// (print 23, PDF 25)
inline bool mknNunchakuSpecialSkill()
    { return true; }

// the nunchaku is two equal lengths of hardwood hinged by a short piece of
// silk or chain, used for blocks, smashing blows, and thrusts into vulnerable
// areas (print 23, PDF 25)
inline bool mknNunchakuSilkOrChain()
    { return true; }

// the kama is a rice-harvesting hand sickle - slash, rake, hook, chip,
// deflect or block (print 23, PDF 25)
inline bool mknKamaRiceSickle()
    { return true; }

// the defender shomen column - blocked 0, dla 2, dra 3, cut 1, cut 1, dra 3,
// cut 1, cut 1, blocked 0 down the nine attacker moves (print 24, PDF 26)
inline int mknKedoVsShomen(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the defender hidari-men column - the attacker left arm 5, blocked 0, the
// odd dar 6, dra 3, cut 1, dra 3, cut 1, cut 1, cut 1 (print 24, PDF 26)
inline int mknKedoVsHidariMen(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the defender migi-men column - ara 4, ara 4, cut 1, ara 4, dra 3, cut 1,
// cut 1, cut 1, cut 1 - the migi-men row crossing is a cut, one of the six
// diagonal breaks pinned as printed (print 24, PDF 26)
inline int mknKedoVsMigiMen(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the defender migi-do column - cut 1, dra 3, dra 3, cut 1, blocked 0, dra 3,
// dra 3, cut 1, cut 1 - the migi-do row crossing is a cut, one of the six
// diagonal breaks, and its blocked cell prints crossed into the gyaku-do
// column (print 24, PDF 26)
inline int mknKedoVsMigiDo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the defender gyaku-do column - cut 1, cut 1, ara 4, blocked 0, cut 1, dra
// 3, dra 3, cut 1, cut 1 - the gyaku-do row crossing is a cut, one of the six
// diagonal breaks pinned as printed (print 24, PDF 26)
inline int mknKedoVsGyakuDo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the defender kote column - ara 4, ara 4, cut 1, ara 4, ara 4, cut 1, cut 1,
// cut 1, blocked 0 - the kote row crossing is a cut, one of the six diagonal
// breaks pinned as printed (print 24, PDF 26)
inline int mknKedoVsKote(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the defender hidari-kote column - cut 1, cut 1, cut 1, ara 4, ara 4, cut 1,
// cut 1, blocked 0, blocked 0 (print 24, PDF 26)
inline int mknKedoVsHidariKote(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the defender tsuki column - cut 1, cut 1, cut 1, cut 1, cut 1, cut 1,
// blocked 0, blocked 0, blocked 0 (print 24, PDF 26)
inline int mknKedoVsTsuki(int b)
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
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the defender front-block column - blocked 0, cut 1, cut 1, cut 1, cut 1,
// cut 1, blocked 0, blocked 0, blocked 0 (print 24, PDF 26)
inline int mknKedoVsBlock(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// ---- the effective use of poison (print 24) ----

// the poison code count - A, B and C (print 24, PDF 26)
inline int mknPoisCodes()
    { return 3; }

// the stricken stat count - Strength, Dexterity, Constitution and Movement
// (print 24, PDF 26)
inline int mknStrickenStats()
    { return 4; }

// a stricken player has Strength, Dexterity, Constitution and Movement at one
// half (print 24, PDF 26)
inline int mknStrickenDivisor()
    { return 2; }

// the armor saving-throw adjustment - plate plus 2 (print 24, PDF 26)
inline int mknArmorPlate()
    { return 2; }

// the armor saving-throw adjustment - chainmail plus 1 (print 24, PDF 26)
inline int mknArmorChain()
    { return 1; }

// the armor saving-throw adjustment - leather 0 (print 24, PDF 26)
inline int mknArmorLeather()
    { return 0; }

// the armor saving-throw adjustment - no armor minus 2 (print 24, PDF 26)
inline int mknArmorNone()
    { return -2; }

// poison A is found as a potion (print 24, PDF 26)
inline bool mknPoisAFoundPotion()
    { return true; }

// poison A description - arsenic, hemlock, etc. (print 24, PDF 26)
inline bool mknPoisAArsenicEtc()
    { return true; }

// poison B is found as gas, darts, cobras, needles (print 24, PDF 26)
inline bool mknPoisBFoundGasDarts()
    { return true; }

// poison B description - neurotoxic (print 24, PDF 26)
inline bool mknPoisBNeurotoxic()
    { return true; }

// poison C is found with spiders, scorpions, P. worms, other snakes, wyverns,
// etc. (print 24, PDF 26)
inline bool mknPoisCFoundCreatures()
    { return true; }

// poison C description - hemotoxic (print 24, PDF 26)
inline bool mknPoisCHemotoxic()
    { return true; }

// if a player does not make the saving throw it shall be considered poisoned
// (print 24, PDF 26)
inline bool mknPoisSaveFailIsPoisoned()
    { return true; }

// if that player does not die it is considered stricken (print 24, PDF 26)
inline bool mknPoisSurvivorStricken()
    { return true; }

// in the case of unconsciousness the stricken state takes effect upon
// regaining consciousness (print 24, PDF 26)
inline bool mknPoisStrickenOnConsciousness()
    { return true; }

// Neutralize Poison, if successful, will cancel all deleterious
// manifestations (print 24, PDF 26)
inline bool mknPoisNeutralizeCancelsAll()
    { return true; }

// armor has no effect on the poisons that have been taken internally (print
// 24, PDF 26)
inline bool mknPoisArmorNoEffectInternal()
    { return true; }

// if a portion of a potion is drunk, each individual portion has its own
// saving throw (print 24, PDF 26)
inline bool mknPoisEachPortionOwnSave()
    { return true; }

// the death percentage - 80, 50 and 10 down the A, B, C rows (print 24, PDF
// 26)
inline int mknPoisDeathPct(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 50;
        case 2:
            return 10;
        default:
            return -99;
        }
    }

// the death timing minimum - A and B in turns (2 and 4), C in days (1), the
// units pinned as printed (print 24, PDF 26)
inline int mknPoisDeathMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the death timing maximum - A and B in turns (8 and 16), C in days (4)
// (print 24, PDF 26)
inline int mknPoisDeathMax(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 16;
        case 2:
            return 4;
        default:
            return -99;
        }
    }

// the stricken minimum - A one week pinned as 7 days noted never silent, B
// and C one day (print 24, PDF 26)
inline int mknPoisStrickenMin(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the stricken maximum - A 7 days, B 3 days, C 10 days (print 24, PDF 26)
inline int mknPoisStrickenMax(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 3;
        case 2:
            return 10;
        default:
            return -99;
        }
    }

// the unconscious delay in minutes - A never prints an unconscious time and
// rides the sentinel, B 30 minutes, C one hour pinned as 60 minutes (print
// 24, PDF 26)
inline int mknPoisUnconcDelay(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 30;
        case 2:
            return 60;
        default:
            return -99;
        }
    }

// the unconscious duration minimum in days - A rides the sentinel, B 1, C 2
// (print 24, PDF 26)
inline int mknPoisUnconcDurMin(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the unconscious duration maximum in days - A rides the sentinel, B 4, C 8
// (print 24, PDF 26)
inline int mknPoisUnconcDurMax(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 4;
        case 2:
            return 8;
        default:
            return -99;
        }
    }

}   // namespace rules
