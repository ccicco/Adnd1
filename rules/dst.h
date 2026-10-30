// =========================================================================================
// Adnd1 - rules/dst.h
// The Dragon issue-20 opener part two - the 600-death campaign census and the
// demonic possession doctrine
// census 863 -> 864.
//
// The part-two round of the issue-20 three-round shape - the remaining two of
// the five Curtiss-called chains pinned, after the R940 Polynesian pantheon,
// witch ladder and demonology grids. All pinned from The Dragon Vol. III No.
// 6 (November 1978), the Curtiss-provided Dm20.pdf scan voice, print folio
// the PDF page minus two.
//
// The part-two print catches pinned as scanned: the death-census percentage
// column sums to 100.1 percent not 100 (pinned in tenths, 1001, the
// conversion noted), the possession victim-freed line prints 55 percent with
// a dangling dash and a singular point of damage, and the 1-10 freed band
// prints 1 - 10 spaced. Both inherited watches - the Sullin levels 7-9 and
// the brawling sequel - print nowhere in TD20 and ride to TD 21.
//
namespace rules {

// ---- the death statistics census (print 26) ----

// the death-cause row count - thirty-one printed causes from the goblin races
// through the miscellaneous band the death statistics census (print 26, PDF
// 28)
inline int dstDeathRows()
    { return 31; }

// the compiled death census - 600 deaths of playing characters and their
// advanceable hirelings the death statistics census (print 26, PDF 28)
inline int dstDeathTotal()
    { return 600; }

// the percentage column sums to 1001 tenths - 100.1 percent, a print catch
// pinned as scanned the death statistics census (print 26, PDF 28)
inline int dstDeathPctSumTenths()
    { return 1001; }

// the Saskatoon campaign has run 4 years the death statistics census (print
// 26, PDF 28)
inline int dstDeathCampaignYears()
    { return 4; }

// the statistics compile window - 2 to 3 years, the floor the death
// statistics census (print 26, PDF 28)
inline int dstDeathCompileMinYears()
    { return 2; }

// the statistics compile window - 2 to 3 years, the ceiling the death
// statistics census (print 26, PDF 28)
inline int dstDeathCompileMaxYears()
    { return 3; }

// the all-time death estimate - about a thousand player and hireling deaths
// in the 4 years the death statistics census (print 26, PDF 28)
inline int dstDeathEstimate()
    { return 1000; }

// the men-types band floor - assassination, pirates, spells, war and the
// rest, 20 to 25 percent of all deaths the death statistics census (print 26,
// PDF 28)
inline int dstMenTypesMinPct()
    { return 20; }

// the men-types band ceiling - 25 percent, the biggest killers as a class the
// death statistics census (print 26, PDF 28)
inline int dstMenTypesMaxPct()
    { return 25; }

// the goblin-types encounter band floor - up to 300 or 400 orcs or goblins
// the death statistics census (print 26, PDF 28)
inline int dstGoblinBandMin()
    { return 300; }

// the goblin-types encounter band ceiling - 400 of the 300-400 band the death
// statistics census (print 26, PDF 28)
inline int dstGoblinBandMax()
    { return 400; }

// the five-death misc causes - liches, suicides and drowning the death
// statistics census (print 26, PDF 28)
inline int dstDeathFiveCauses()
    { return 3; }

// the four-death misc causes - minotaurs, ochre-jelly blobs and stakes in
// hearts the death statistics census (print 26, PDF 28)
inline int dstDeathFourCauses()
    { return 3; }

// the three-death misc causes - invisible stalkers, sea monsters, lizard men,
// harpies, tigers, rockslides, starvation and freezing the death statistics
// census (print 26, PDF 28)
inline int dstDeathThreeCauses()
    { return 8; }

// the four deadly encounter factors - the creature power, the number likely
// encountered, the willingness to attack and the meeting frequency the death
// statistics census (print 26, PDF 28)
inline int dstDeathFactors()
    { return 4; }

// the campaign is primarily a wilderness one, as the statistics reflect,
// though huge dungeons exist the death statistics census (print 26, PDF 28)
inline bool dstWildernessCampaign()
    { return true; }

// the 600 deaths are playing characters and their advanceable hirelings, not
// mercenaries or other non-playing characters the death statistics census
// (print 26, PDF 28)
inline bool dstPlayersAndHirelingsOnly()
    { return true; }

// patriarchs caused no deaths - you meet them as often as evil high priests
// but they will not attack, the willingness factor the death statistics
// census (print 26, PDF 28)
inline bool dstPatriarchsNoDeaths()
    { return true; }

// the worst thing is to be surprised, even by a minor creature - even badly
// outgunned you can usually escape with enough warning the death statistics
// census (print 26, PDF 28)
inline bool dstSurpriseWorstHazard()
    { return true; }

// the death count column - the goblin races 61 and the misc band 85 around a
// 600-death total the death statistics census (print 26, PDF 28)
inline int dstDeathCount(int b)
    {
        switch (b) {
        case 0:
            return 61;
        case 1:
            return 45;
        case 2:
            return 34;
        case 3:
            return 26;
        case 4:
            return 24;
        case 5:
            return 23;
        case 6:
            return 21;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 17;
        case 12:
            return 16;
        case 13:
            return 14;
        case 14:
            return 13;
        case 15:
            return 13;
        case 16:
            return 13;
        case 17:
            return 13;
        case 18:
            return 12;
        case 19:
            return 12;
        case 20:
            return 12;
        case 21:
            return 11;
        case 22:
            return 9;
        case 23:
            return 8;
        case 24:
            return 8;
        case 25:
            return 8;
        case 26:
            return 8;
        case 27:
            return 6;
        case 28:
            return 6;
        case 29:
            return 6;
        case 30:
            return 85;
        default:
            return -99;
        }
    }

// the percentage column - printed to one decimal, pinned in tenths: 10.1 as
// 101 through 14.6 as 146 the death statistics census (print 26, PDF 28)
inline int dstDeathPct(int b)
    {
        switch (b) {
        case 0:
            return 101;
        case 1:
            return 75;
        case 2:
            return 57;
        case 3:
            return 43;
        case 4:
            return 40;
        case 5:
            return 38;
        case 6:
            return 35;
        case 7:
            return 33;
        case 8:
            return 33;
        case 9:
            return 30;
        case 10:
            return 30;
        case 11:
            return 28;
        case 12:
            return 27;
        case 13:
            return 23;
        case 14:
            return 22;
        case 15:
            return 22;
        case 16:
            return 22;
        case 17:
            return 22;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 20;
        case 21:
            return 18;
        case 22:
            return 14;
        case 23:
            return 13;
        case 24:
            return 13;
        case 25:
            return 13;
        case 26:
            return 13;
        case 27:
            return 10;
        case 28:
            return 10;
        case 29:
            return 10;
        case 30:
            return 146;
        default:
            return -99;
        }
    }

// ---- the demonic possession doctrine (print 32) ----

// only demons of type IV or greater and the princes are capable of possessing
// bodies of adventurers the demonic possession doctrine (print 32, PDF 34)
inline int dstPossessMinType()
    { return 4; }

// the amulet of the demon must remain on the same plane and world, within one
// mile of the place of possession the demonic possession doctrine (print 32,
// PDF 34)
inline int dstAmuletMileRange()
    { return 1; }

// paladins and clerics get a plus one on the possession saving throw the
// demonic possession doctrine (print 32, PDF 34)
inline int dstPossessPaladinBonus()
    { return 1; }

// princes cause a minus two on the possession saving throw the demonic
// possession doctrine (print 32, PDF 34)
inline int dstPossessPrincePenalty()
    { return 2; }

// at the death of the host body the demon has a 20 percent chance to possess
// the killer, unless a lawful cleric or paladin the demonic possession
// doctrine (print 32, PDF 34)
inline int dstHostDeathRepossessPct()
    { return 20; }

// the post-death stay-as-spirit outcome - 35 percent, not attacking the
// demonic possession doctrine (print 32, PDF 34)
inline int dstPostDeathStaySpiritPct()
    { return 35; }

// the post-death transport-to-body-plane outcome - 35 percent, staying there
// the demonic possession doctrine (print 32, PDF 34)
inline int dstPostDeathBodyPlanePct()
    { return 35; }

// the post-death body-to-the-room outcome - 30 percent, continuing the fight
// in earnest the demonic possession doctrine (print 32, PDF 34)
inline int dstPostDeathBodyFightPct()
    { return 30; }

// if the victim is raised after the death there is a 10 percent chance of the
// demon repossessing the body after the save versus death ray the demonic
// possession doctrine (print 32, PDF 34)
inline int dstRaisedRepossessPct()
    { return 10; }

// the exorcism needs two rounds of preparation with no fighting before the
// first attempt the demonic possession doctrine (print 32, PDF 34)
inline int dstExorcismPrepRounds()
    { return 2; }

// the cleric may attempt an exorcism every five rounds after the preparation
// the demonic possession doctrine (print 32, PDF 34)
inline int dstExorcismEveryRounds()
    { return 5; }

// each exorcism attempt costs the cleric 1-6 hit points - the floor the
// demonic possession doctrine (print 32, PDF 34)
inline int dstExorcismClericHpMin()
    { return 1; }

// each exorcism attempt costs the cleric 1-6 hit points - the ceiling the
// demonic possession doctrine (print 32, PDF 34)
inline int dstExorcismClericHpMax()
    { return 6; }

// the exorcised victim is freed 55 percent of the time - the dangling-dash
// print catch rides this line the demonic possession doctrine (print 32, PDF
// 34)
inline int dstVictimFreedPct()
    { return 55; }

// the freed victim takes 1-10 points of damage - the floor the demonic
// possession doctrine (print 32, PDF 34)
inline int dstVictimFreedDmgMin()
    { return 1; }

// the freed victim takes 1-10 points of damage - the ceiling the demonic
// possession doctrine (print 32, PDF 34)
inline int dstVictimFreedDmgMax()
    { return 10; }

// the exorcised victim goes insane 25 percent of the time, treated in the
// usual ways the demonic possession doctrine (print 32, PDF 34)
inline int dstVictimInsanePct()
    { return 25; }

// the exorcised victim drops dead 20 percent of the time, revival may be
// attempted the demonic possession doctrine (print 32, PDF 34)
inline int dstVictimDeadPct()
    { return 20; }

// against remove curse or limited wish the demon saves as a thirteenth level
// cleric versus death ray the demonic possession doctrine (print 32, PDF 34)
inline int dstRemoveCurseDemonLevel()
    { return 13; }

// against a full wish the demon saves as a ninth level cleric versus dragon
// breath the demonic possession doctrine (print 32, PDF 34)
inline int dstFullWishDemonLevel()
    { return 9; }

// princes get a plus two on the remove curse, limited wish and full wish
// saves the demonic possession doctrine (print 32, PDF 34)
inline int dstPrinceSaveBonus()
    { return 2; }

// the possessed may be subdued only by two or more fighters of strength at
// least 18(01) - the strength floor the demonic possession doctrine (print
// 32, PDF 34)
inline int dstSubdueStrFloor()
    { return 18; }

// the subdual strength roll floor - 18(01), the exceptional-strength 01 the
// demonic possession doctrine (print 32, PDF 34)
inline int dstSubdueStrRoll()
    { return 1; }

// the subdual needs two or more qualifying fighters the demonic possession
// doctrine (print 32, PDF 34)
inline int dstSubdueFighterCount()
    { return 2; }

// the rule of the thumb - only demons immune to all but magical weapons exist
// upon two planes at once and may possess, the body sent to another plane
// while the spiritual essence remains the demonic possession doctrine (print
// 32, PDF 34)
inline bool dstTwoPlaneRuleOfThumb()
    { return true; }

// the demon should be placed by the DM but the victim must be at random -
// first in, last in, fourth or whatever - to preserve fair play the demonic
// possession doctrine (print 32, PDF 34)
inline bool dstRandomVictim()
    { return true; }

// only one demon will inhabit a body at one time and only one member will be
// possessed in one party at one time the demonic possession doctrine (print
// 32, PDF 34)
inline bool dstOnePerBody()
    { return true; }

// the possessed member has the same armor class as the victim before
// possession the demonic possession doctrine (print 32, PDF 34)
inline bool dstKeepsVictimAc()
    { return true; }

// the possessed may use any weapon except those aligned Lawful, regardless of
// previous character class the demonic possession doctrine (print 32, PDF 34)
inline bool dstAnyWeaponExceptLawful()
    { return true; }

// the possessed attack with those weapons as whatever level demon they are,
// not the level of the victim the demonic possession doctrine (print 32, PDF
// 34)
inline bool dstAttacksAsDemonLevel()
    { return true; }

// the demon retains all powers while possessing except the ability to gate
// the demonic possession doctrine (print 32, PDF 34)
inline bool dstKeepsPowersExceptGate()
    { return true; }

// nothing precluded by the new shape - no physical flight without wings, no
// Balrog immolation the demonic possession doctrine (print 32, PDF 34)
inline bool dstNoFlightWithoutWings()
    { return true; }

// all hits and damage are taken by the infested body rather than the demon
// itself the demonic possession doctrine (print 32, PDF 34)
inline bool dstHostTakesDamage()
    { return true; }

// the possessed registers on Detect Evil or reacts violently to Holy Water,
// paladins with their power to detect recognize possession immediately the
// demonic possession doctrine (print 32, PDF 34)
inline bool dstDetectEvilRegisters()
    { return true; }

// one of the first give-away actions is divesting all aligned weapons or
// equipment the demonic possession doctrine (print 32, PDF 34)
inline bool dstDropsAlignedGear()
    { return true; }

// the victims lose no points to alignment shock but feel intense pain in the
// presence of aligned weapons the demonic possession doctrine (print 32, PDF
// 34)
inline bool dstNoAlignmentShock()
    { return true; }

// restraint is almost impossible - the possessed break all rope and leather
// restraints and all but the strongest chains the demonic possession doctrine
// (print 32, PDF 34)
inline bool dstBreaksRopesLeather()
    { return true; }

// demon princes may not be subdued the demonic possession doctrine (print 32,
// PDF 34)
inline bool dstPrincesNotSubdued()
    { return true; }

// the actions of a person while possessed are controlled by the demon so no
// chaotic action will be held against them the demonic possession doctrine
// (print 32, PDF 34)
inline bool dstNoChaosBlame()
    { return true; }

// the exorcism ability is in direct proportion to turning undead - regular
// demons are rolled for as wraiths the demonic possession doctrine (print 32,
// PDF 34)
inline bool dstDemonsTurnAsWraiths()
    { return true; }

// demon princes are rolled for as a spectre on the turning tables the demonic
// possession doctrine (print 32, PDF 34)
inline bool dstPrincesTurnAsSpectres()
    { return true; }

// if the demon is driven from the body by exorcism there can be no
// repossession the demonic possession doctrine (print 32, PDF 34)
inline bool dstExorcisedNoRepossession()
    { return true; }

// demons cannot possess a person who is in control of his amulet the demonic
// possession doctrine (print 32, PDF 34)
inline bool dstAmuletHolderImmune()
    { return true; }

// if a once-possessed person comes in contact with the possessing demon
// amulet it causes instant death the demonic possession doctrine (print 32,
// PDF 34)
inline bool dstAmuletContactInstantDeath()
    { return true; }

// an exorcism by the found amulet, correctly phrased, orders the demon back
// to its body with no damage to the victim the demonic possession doctrine
// (print 32, PDF 34)
inline bool dstAmuletCommandNoDamage()
    { return true; }

// there is no treasure in the room in which the possession takes place - the
// wealth is deposited upon the plane with the corporeal body the demonic
// possession doctrine (print 32, PDF 34)
inline bool dstNoTreasureInRoom()
    { return true; }

// the victim-freed line prints 55 percent with a dangling dash and a singular
// point of damage - pinned as scanned, the conversion noted the demonic
// possession doctrine (print 32, PDF 34)
inline bool dstDanglingDashPrintCatch()
    { return true; }

}   // namespace rules
