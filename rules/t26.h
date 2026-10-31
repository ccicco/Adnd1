// =========================================================================================
// Adnd1 - rules/t26.h
// The Dragon issue-26 opener part one - the opener set
// census 884 -> 885.
//
// The opener of the issue-26 four-round shape - five of the thirteen
// Curtiss-called chains pinned as the opener set, the four-chain table round
// and the four-chain commentary set riding parts two and three with the flip
// to follow. All pinned from The Dragon Vol. III No. 12 (June 1979) print
// 13-14 + 26-30 + 39 at extract/dragon/026, PRINT FOLIO = PDF PAGE - 2 this
// issue, the single-voice transcript of the Curtiss-provided scan - the issue
// runs 52 pages, the cover printing the issue tag 36 and the PDF-3 mail-label
// notice printing the TD 26 last-issue note, both pinned as scanned, and no
// letters page this issue. The System 7 Napoleonics block, the Solo Berserker
// 1066 design, Boot Hill, the EPT birth tables, the Skinnies Starship
// Troopers variant and Lords and Wizards sit on the drop list per the Curtiss
// 2026-10-31 non-D&D calls, the Mugger! humor variant and the Dragon Augury
// reviews per the same-day calls, and the two watches - the Sullin levels 7-9
// and the brawling sequel - ride to TD 27 absent a fifth issue.
//
namespace rules {

// ---- the Giants in the Earth heroes roster (print 13-14) ----

// the three heroes of the column debut - Cugel, Kane and Tros the Giants in
// the Earth heroes roster (print 13-14)
inline int t26GiantsHeroes()
    { return 3; }

// the Cugel the Clever thief level the Giants in the Earth heroes roster
// (print 13-14)
inline int t26CugelLevel()
    { return 14; }

// the bizarre coincidence luck chance Cugel capitalizes upon the Giants in
// the Earth heroes roster (print 13-14)
inline int t26CugelLuckPct()
    { return 85; }

// the two-turn group discord chance the natural troublemaker brings the
// Giants in the Earth heroes roster (print 13-14)
inline int t26CugelDiscordPct()
    { return 70; }

// the three lucounu notebook spells - the hypnotic, the mantle of stealth and
// the laganetic transfer, the name pinned as scanned the Giants in the Earth
// heroes roster (print 13-14)
inline int t26CugelSpells()
    { return 3; }

// the Kane fighter level the Giants in the Earth heroes roster (print 13-14)
inline int t26KaneFighterLevel()
    { return 30; }

// the Kane magic user level the Giants in the Earth heroes roster (print
// 13-14)
inline int t26KaneMagicUserLevel()
    { return 20; }

// the Kane assassin level the Giants in the Earth heroes roster (print 13-14)
inline int t26KaneAssassinLevel()
    { return 14; }

// the Kane hit points the Giants in the Earth heroes roster (print 13-14)
inline int t26KaneHitPoints()
    { return 165; }

// the assassination chance when Kane meets a party, the an 05 percent print
// pinned as scanned the Giants in the Earth heroes roster (print 13-14)
inline int t26KaneAssassinatePct()
    { return 5; }

// the Cugel spell backfire - half his castings causing the opposite of the
// intended effect, the failed transfer carrying him away instead the Giants
// in the Earth heroes roster (print 13-14)
inline bool t26CugelSpellBackfire()
    { return true; }

// the Cugel verdict - completely untrustworthy, attempting the whole hoard
// once the guardians are dispatched the Giants in the Earth heroes roster
// (print 13-14)
inline bool t26CugelUntrustworthy()
    { return true; }

// the Kane gaze - characters of fifth level or below saving versus fear, the
// mad blue eyes the mark the Giants in the Earth heroes roster (print 13-14)
inline bool t26KaneFearGaze()
    { return true; }

// the Kane inconstancy - a ten percent chance of acting out of character, the
// remaining alignments numbered for the roll the Giants in the Earth heroes
// roster (print 13-14)
inline bool t26KaneEternalRebel()
    { return true; }

// the Kane escape - teleporting to safety whenever a battle looks mortal the
// Giants in the Earth heroes roster (print 13-14)
inline bool t26KaneTeleportEscape()
    { return true; }

// the Tros missions - Athene sending the paladin through other spaces and
// times, the mission his to determine on arrival the Giants in the Earth
// heroes roster (print 13-14)
inline bool t26TrosAtheneMissions()
    { return true; }

// the column debut - the new monthly entry co-authored by Lawrence Schick per
// the Rumbles, fighters leading off and magic users later in the summer the
// Giants in the Earth heroes roster (print 13-14)
inline bool t26GiantsMonthlyDebut()
    { return true; }

// ---- the Hirelings Have Feelings Too doctrine (print 26-27) ----

// the hireling advance - at least two years normal salary up front the
// Hirelings Have Feelings Too doctrine (print 26-27)
inline int t26HirelingAdvanceYears()
    { return 2; }

// the human heavy foot advance price the Hirelings Have Feelings Too doctrine
// (print 26-27)
inline int t26HirelingAdvanceGp()
    { return 72; }

// the base share the principals pass to their NPC employees, up to ten
// percent the Hirelings Have Feelings Too doctrine (print 26-27)
inline int t26HirelingBaseSharePct()
    { return 5; }

// the orphaned hireling share - the straight percentage example when no
// principal takes them on the Hirelings Have Feelings Too doctrine (print
// 26-27)
inline int t26MercenarySharePct()
    { return 25; }

// the elf price - at least a fifteen percent share of gems, jewelry and magic
// the Hirelings Have Feelings Too doctrine (print 26-27)
inline int t26ElfSharePct()
    { return 15; }

// the dwarf heavy infantry four-year demand the Hirelings Have Feelings Too
// doctrine (print 26-27)
inline int t26DwarfAdvanceGp()
    { return 192; }

// the dwarf crossbowman four-year demand the Hirelings Have Feelings Too
// doctrine (print 26-27)
inline int t26DwarfCrossbowGp()
    { return 240; }

// the legendary returning hammer grab chance - the relic of the forefathers,
// any given dwarf trying stealth or force the Hirelings Have Feelings Too
// doctrine (print 26-27)
inline int t26DwarfHammerGrabPct()
    { return 65; }

// the orc set salary - the heavy foot rate for five years regular work, never
// trusted the Hirelings Have Feelings Too doctrine (print 26-27)
inline int t26OrcSetSalaryGp()
    { return 90; }

// the hireling first principle - a free man who made the choice, never a
// slave the Hirelings Have Feelings Too doctrine (print 26-27)
inline bool t26HirelingFreeMan()
    { return true; }

// the strict-salary hirelings - untrustworthy, demanding five years in
// advance and running when the dragon or the Balor steps in the Hirelings
// Have Feelings Too doctrine (print 26-27)
inline bool t26MercenaryFleeRule()
    { return true; }

// the level ladder - each NPC level doubling the salary demanded of the level
// below the Hirelings Have Feelings Too doctrine (print 26-27)
inline bool t26HirelingLevelDoubling()
    { return true; }

// the magic user and cleric deals - rarely mercenary, no dungeon service
// below a full share of all treasure found the Hirelings Have Feelings Too
// doctrine (print 26-27)
inline bool t26ClericFullShare()
    { return true; }

// the elf price - a fine gem or magic item on top of the share, coins carried
// for the employer but rarely kept the Hirelings Have Feelings Too doctrine
// (print 26-27)
inline bool t26ElfGemPrice()
    { return true; }

// the orc gate - working only for chaotic employers, prone to running with
// the treasure and killing the employer in his sleep the Hirelings Have
// Feelings Too doctrine (print 26-27)
inline bool t26OrcChaoticOnly()
    { return true; }

// the fair-pay dividend - the well-paid, uncheated hireling taking a plus one
// on the next loyalty rating the Hirelings Have Feelings Too doctrine (print
// 26-27)
inline bool t26LoyaltyPlusOne()
    { return true; }

// ---- the D&D Meets the Electronic Age commentary (print 26) ----

// the microcomputer memory - four K the D&D Meets the Electronic Age
// commentary (print 26)
inline int t26SageMemoryK()
    { return 4; }

// the random hit roll - one to twenty the D&D Meets the Electronic Age
// commentary (print 26)
inline int t26SageHitRoll()
    { return 20; }

// the example monster hit dice the D&D Meets the Electronic Age commentary
// (print 26)
inline int t26SageExampleHitDice()
    { return 1; }

// the example foe armor class the D&D Meets the Electronic Age commentary
// (print 26)
inline int t26SageExampleArmorClass()
    { return 9; }

// the example to-hit number - ten or better scores the hit the D&D Meets the
// Electronic Age commentary (print 26)
inline int t26SageExampleHitNumber()
    { return 10; }

// the example damage die - type six, one die, doubled on the twenty the D&D
// Meets the Electronic Age commentary (print 26)
inline int t26SageExampleDamageDie()
    { return 6; }

// the natural twenty - the double damage roll the D&D Meets the Electronic
// Age commentary (print 26)
inline int t26SageDoubleDamageRoll()
    { return 20; }

// the five SAGE duties - the hit charts with damage allocation, the name
// generation, the NPC requisites and levels, the player bookkeeping and the
// self-running dungeon the D&D Meets the Electronic Age commentary (print 26)
inline int t26SageDuties()
    { return 5; }

// the machine verdict - the mechanics handled better at no expense to
// creativity the D&D Meets the Electronic Age commentary (print 26)
inline bool t26SageNoCreativityLoss()
    { return true; }

// the name generation - letter values and predetermined patterns, the Barker
// Strategic Review article the reference the D&D Meets the Electronic Age
// commentary (print 26)
inline bool t26SageNamePatterns()
    { return true; }

// the labyrinth trick - recurring rooms and passages worded to be
// undetectable, the misdirection the threat the D&D Meets the Electronic Age
// commentary (print 26)
inline bool t26SageRepeatingRooms()
    { return true; }

// the timer loop - the damage held on screen before it vanishes back to
// battle the D&D Meets the Electronic Age commentary (print 26)
inline bool t26SageTimerLoop()
    { return true; }

// the cross-game use - the campaign mechanics carried to Boot Hill too, the
// Gamma World program unfinished the D&D Meets the Electronic Age commentary
// (print 26)
inline bool t26SageBootHillToo()
    { return true; }

// the closing split - the computer the skeleton of gaming, the DM the flesh
// of the campaign the D&D Meets the Electronic Age commentary (print 26)
inline bool t26SageSkeletonFlesh()
    { return true; }

// the verdict on fear - the worry that the machine destroys creativity
// groundless the D&D Meets the Electronic Age commentary (print 26)
inline bool t26SageFearGroundless()
    { return true; }

// ---- the Notes from a Very Successful D&D Moderator essay (print 27) ----

// the pit countermove - the one-ton weight dropping to carry the roped party
// down the Notes from a Very Successful D&D Moderator essay (print 27)
inline int t26PitCounterweightTons()
    { return 1; }

// the ten large jello cubes guarding the treasure room the Notes from a Very
// Successful D&D Moderator essay (print 27)
inline int t26JelloDecoys()
    { return 10; }

// the reward method ceiling - the seldom-reached fifteen characters the Notes
// from a Very Successful D&D Moderator essay (print 27)
inline int t26PlayerCharacterCeiling()
    { return 15; }

// the reward method grant - one additional character per level survived the
// Notes from a Very Successful D&D Moderator essay (print 27)
inline int t26RewardPerLevel()
    { return 1; }

// the poison countermeasures - the self-nick chance and the tolerance build
// the Notes from a Very Successful D&D Moderator essay (print 27)
inline int t26PoisonCountermeasures()
    { return 2; }

// the shared dark secrets - the pit, the deceiving appearance, the reward
// method and the poison counters the Notes from a Very Successful D&D
// Moderator essay (print 27)
inline int t26ModeratorDevices()
    { return 4; }

// the closing wish - the players eight on their next saving throw, the
// missing dash pinned as scanned the Notes from a Very Successful D&D
// Moderator essay (print 27)
inline int t26SavingThrowWish()
    { return 8; }

// the player brainstorms - the mountain climber safety line and the
// lead-loaded cart the Notes from a Very Successful D&D Moderator essay
// (print 27)
inline int t26PitPlayerSolutions()
    { return 2; }

// the moderator countermoves - the counterweight and the linked trap paths
// the Notes from a Very Successful D&D Moderator essay (print 27)
inline int t26PitModeratorCounters()
    { return 2; }

// the final pit counter - a sprung trap activating the previously unactivated
// traps along the approach paths the Notes from a Very Successful D&D
// Moderator essay (print 27)
inline bool t26PitLinkedTraps()
    { return true; }

// the appearance doctrine - things that are not what they seem, the
// Gelatinous Cube fear turned to jello molds and the unsackable room the
// Notes from a Very Successful D&D Moderator essay (print 27)
inline bool t26CubeDecoyDoctrine()
    { return true; }

// the reward method - one additional character per adventure survived and
// level gained, the careful player spared the bottom restart the Notes from a
// Very Successful D&D Moderator essay (print 27)
inline bool t26RewardMethod()
    { return true; }

// the nick rule - each poison use risking a self-wound, the more effective
// poison the worse the effect the Notes from a Very Successful D&D Moderator
// essay (print 27)
inline bool t26PoisonNickRule()
    { return true; }

// the tolerance rule - lightly wounded monsters building up immunity while
// the players keep stabbing the Notes from a Very Successful D&D Moderator
// essay (print 27)
inline bool t26PoisonTolerance()
    { return true; }

// the column purpose - the moderators sharing their dark secrets back after
// the player trick columns the Notes from a Very Successful D&D Moderator
// essay (print 27)
inline bool t26ModeratorSharing()
    { return true; }

// the poison freaks - the players with a liberal supply always on hand, the
// named target of both counters the Notes from a Very Successful D&D
// Moderator essay (print 27)
inline bool t26PoisonFreaks()
    { return true; }

// ---- the Gygax D&D AD&D gaming essay (print 28-30 + 39) ----

// the LGTSA one-to-one gaming year - about 1970 the Gygax D&D AD&D gaming
// essay (print 28-30 + 39)
inline int t26SandTableYear()
    { return 1970; }

// the Blackmoor progression - the hero gaining the ability of five rather
// than but four men the Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline int t26HeroAbilityGain()
    { return 5; }

// the fantasy section playtest year - late 1972, superheroes and wizards on
// the sand table the Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline int t26FantasyPlaytestYear()
    { return 1972; }

// the Original manuscript completed in the spring the Gygax D&D AD&D gaming
// essay (print 28-30 + 39)
inline int t26ManuscriptYear()
    { return 1973; }

// the D&D publication - January 1974 the Gygax D&D AD&D gaming essay (print
// 28-30 + 39)
inline int t26PublicationYear()
    { return 1974; }

// the 1974 sales - slightly more than a thousand copies, far more sold each
// month today the Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline int t26FirstYearSales()
    { return 1000; }

// the quarter million player estimate, called conservative the Gygax D&D AD&D
// gaming essay (print 28-30 + 39)
inline int t26PlayerEstimate()
    { return 250000; }

// the Blume Invitational - this writer placing a rather abysmal tenth the
// Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline int t26InvitationalPlace()
    { return 10; }

// the Blume Invitational field - eighteen entries the Gygax D&D AD&D gaming
// essay (print 28-30 + 39)
inline int t26InvitationalEntries()
    { return 18; }

// the Tony Bath priority - the Hyborean Age tabletop battles years before the
// CHAINMAIL Fantasy Supplement the Gygax D&D AD&D gaming essay (print 28-30 +
// 39)
inline bool t26BathPreChainmail()
    { return true; }

// the Blackmoor innovations - individual roles, expertise progression and the
// dungeon focus, the Ameson spelling pinned as scanned the Gygax D&D AD&D
// gaming essay (print 28-30 + 39)
inline bool t26ArnesonInnovations()
    { return true; }

// the AD&D doctrine - neither an expansion nor a revision but a new game, the
// Mansfield SIGNAL caution quoted the Gygax D&D AD&D gaming essay (print
// 28-30 + 39)
inline bool t26AdndNewGame()
    { return true; }

// the D&D verdict - so much regional variation it has turned into a non-game
// the Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline bool t26DdNonGameVerdict()
    { return true; }

// the AD&D counter - the tighter, structured system with no grey areas, the
// campaign mandate unchanging even under future change the Gygax D&D AD&D
// gaming essay (print 28-30 + 39)
inline bool t26AdndTightStructure()
    { return true; }

// the creed - it simulates absolutely nothing and pretends no realism, only a
// game the Gygax D&D AD&D gaming essay (print 28-30 + 39)
inline bool t26AdndOnlyAGame()
    { return true; }

// the swipe and the nod - the amateur publishing efforts taken to task,
// DUNGEONEER credited for the honest quality approach the Gygax D&D AD&D
// gaming essay (print 28-30 + 39)
inline bool t26AmateurPressSwipe()
    { return true; }

}   // namespace rules
