// =========================================================================================
// Adnd1 - rules/dsglode.h
// The DSG LODESTONE AND NPC REACTIONS, R514: the printed pp. 42-43 (pdf
// 43-44) - the magnetic effects of lodestone (the iron-armor and iron-weapon
// effects, the innocuous iron-ore form that cannot impede movement or combat,
// the deep concentrated ores forming powerful magnetic rock, the Wisdom Check
// detection at 120 feet with the slight tug, the obvious-within-90-feet stage
// with the noticeable-but-not-pulling force, the threatened-within-30-feet
// stage with the strap-snapping pull on hanging iron, the Strength Checks for
// hand-held iron and iron armor with the 10-foot pull on a failed armor
// check, the no-repeat hold on a success, the checks repeated each 10 feet of
// approach, the -2 Strength at 20 feet and -4 at 10 feet, the -6 removal
// check with the forever-stuck failure, and the loss of all powers off-site)
// and the NPC reactions to long underground adventures (the special
// incentives, the Loyalty Check on being informed per DMG pages 36-37, the
// week-or-more trigger with the dwarf/gnome/drow exemption, the -5% per
// planned week, the -10% deception modifier, the -20%-month desert example,
// the separate roll per NPC, the avoidance short of risking life on a
// failure, the compelled NPC becoming unsteady, the slipping mind with the
// first-week ill effects, the 10% morale penalty and the nervous jumpiness,
// the weekly rechecks, the irrational break rolling d100 on Table 20, the
// four-band reactions grid, the effect lasting until slain or surfaced, and
// the 1d6 above-ground weeks with the recovery Wisdom Check and the permanent
// affliction on a failure)
// census 438 -> 439.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read (idx 58-60 = the lodestone pages,
// idx 61-62 = the NPC pages) - every numeric cell dual-confirmed: the
// 120/90/30/10/10 distance ladder, the -2/-4/-6 penalties, the -5%/-10%/-20%
// Loyalty modifiers (the djvu garble -209/ settled by the Capture -20% read
// of the desert example) and the Table 20 bands confirmed by chapter djvu +
// the compiled-tables appendix reprint + Capture idx 62; the djvu garble ih
// place = in place settled by the appendix reprint. The Structural Decay
// section starts the NEXT round per the content-density rule.
//
// Table 20 pins as a 4x3 grid: the row key plus the lo and hi ends of each
// d100 band, with 00 read as 100 (the 86-00 band pins as 86-100). The percent
// and point penalties pin as positive magnitudes with the minus carried in
// the name and comment. The recovery period pins as dice + sides consts (1d6
// weeks) per the R508 convention. The DMG pages 36-37 Loyalty seam and the
// Table 20 irrationality are noted; nothing auto-credits.
//
namespace rules {

// ---- the lodestone opener ----

// magnetism affects characters cloaked in iron armor, and can impede combat
// when iron weapons are used.
inline bool dnzMagnetismAffectsIronArmor()
    { return true; }

// lodestone in its more innocuous form is encountered frequently in areas
// containing iron ore.
inline bool dnzInnocuousFormInIronOre()
    { return true; }

// in the common form the magnetic pull is barely strong enough to be noticed,
// and certainly cannot impede a character's movement or combat.
inline bool dnzInnocuousCannotImpede()
    { return true; }

// deep beneath the earth, concentrated ores of iron and other minerals have
// formed regions of massively powerful magnetic rock.
inline bool dnzDeepOresPowerful()
    { return true; }

// ---- the lodestone detection stages ----

// the magnetic attraction of such rock can be detected by a character who
// passes a Wisdom Check when still 120 feet distant from the lodestone.
inline int dnzWisCheckDetectionFt()
    { return 120; }

// the initial detection is manifested by nothing more than a slight tug on
// all iron possessions.
inline bool dnzWisCheckSlightTug()
    { return true; }

// the lodestone's effects become obvious to any characters moving within 90
// feet.
inline int dnzObviousWithinFt()
    { return 90; }

// within 90 feet the force upon metal objects is definitely noticeable, but
// still not capable of pulling a character against his will.
inline bool dnzObviousNotPullingWill()
    { return true; }

// a character who comes within 30 feet of such a powerful lodestone becomes
// threatened.
inline int dnzThreatenedWithinFt()
    { return 30; }

// when threatened, iron objects hanging on the character are pulled toward
// the lodestone with a force that can snap a thin leather strap.
inline bool dnzHangingIronSnapsStraps()
    { return true; }

// ---- the lodestone Strength Checks ----

// the threatened character must make a Strength Check for all hand-held
// objects containing iron.
inline bool dnzStrCheckHandheldIron()
    { return true; }

// if the character is wearing iron armor, he must make an additional Strength
// Check.
inline bool dnzIronArmorExtraStrCheck()
    { return true; }

// a failed iron-armor Strength Check pulls the character 10 feet closer to
// the lodestone.
inline int dnzArmorPullFt()
    { return 10; }

// if the Strength Check is successful, the character retains hold of the item
// or holds his ground, and no further checks are required as long as he does
// not move closer to the stone.
inline bool dnzSuccessHoldsNoRepeat()
    { return true; }

// when the stone is approached, whether voluntarily or not, the Strength
// Checks must be repeated each 10 feet.
inline int dnzRepeatEveryFt()
    { return 10; }

// a character suffers a -2 penalty to his Strength when 20 feet away (the
// magnitude of the penalty).
inline int dnzStrPenalty20Ft()
    { return 2; }

// a -4 penalty to Strength when only 10 feet away (the magnitude of the
// penalty).
inline int dnzStrPenalty10Ft()
    { return 4; }

// ---- the lodestone removal ----

// removing any iron object stuck to the lodestone requires a Strength Check
// with a -6 modifier (the magnitude of the penalty).
inline int dnzRemovalStrPenalty()
    { return 6; }

// if the removal check fails, the character is forever unable to remove the
// object.
inline bool dnzRemovalFailForever()
    { return true; }

// these lodestones lose all their powers if removed from their natural
// settings.
inline bool dnzLosePowersOffSite()
    { return true; }

// ---- the expedition Loyalty Checks ----

// henchmen and hirelings lack the motivation of player characters for a
// prolonged underground expedition, and special incentives may be necessary
// to persuade the NPCs to remain underground.
inline bool dnzNpcsNeedSpecialIncentives()
    { return true; }

// henchman and hireling loyalty should be checked as soon as they are
// informed of the nature of the expedition, with a normal Loyalty Check as
// explained on DMG pages 36 and 37.
inline bool dnzLoyaltyCheckOnInformed()
    { return true; }

// the Loyalty Check is required whenever a party plans to spend a week or
// more underground.
inline bool dnzCheckWeekOrMore()
    { return true; }

// the Loyalty Check is not necessary for dwarf, gnome, or drow NPCs.
inline bool dnzNoCheckDwarfGnomeDrow()
    { return true; }

// a -5% modifier applies to the d100 Loyalty roll for every week that the
// party plans to spend underground (the magnitude of the penalty).
inline int dnzWeeklyLoyaltyPenaltyPct()
    { return 5; }

// an additional -10% modifier applies if the NPCs learn they have been
// deceived about the duration or destination of the expedition, or are told
// when it is too late for them to avoid it (the magnitude of the penalty).
inline int dnzDeceptionPenaltyPct()
    { return 10; }

// the worked example: PCs leading henchmen across a blazing desert, then
// announcing a month underground, take a -20% Loyalty modifier for the month
// plus the -10% deception modifier (the djvu garble -209/, settled by the
// Capture -20% read; the magnitude of the penalty).
inline int dnzExampleMonthPenaltyPct()
    { return 20; }

// each NPC, whether henchman or hireling, must be checked with a separate
// roll, and the DM should note all of the NPCs who fail the check.
inline bool dnzSeparateRollPerNpc()
    { return true; }

// a failure on the Loyalty Check means the NPC does everything possible,
// short of risking his life, to avoid going on the mission.
inline bool dnzFailureAvoidsMission()
    { return true; }

// an NPC compelled to accompany the party by circumstances or the PCs is
// considered to be unsteady.
inline bool dnzCompelledBecomesUnsteady()
    { return true; }

// ---- the unsteady descent ----

// an unsteady character becomes unsettled by long periods underground, away
// from sunlight and fresh air; his mind begins to slip, slowly at first, and
// finally in a fashion that can prove disastrous for himself and his
// companions.
inline bool dnzUnsteadyMindSlips()
    { return true; }

// the unsteady character begins to suffer ill effects following the first
// week underground.
inline bool dnzIllEffectsAfterFirstWeek()
    { return true; }

// the unsteady character's morale is lowered by 10% for all Morale and
// Loyalty Checks (the magnitude of the penalty).
inline int dnzMoralePenaltyPct()
    { return 10; }

// the unsteady character acts nervous and jumpy.
inline bool dnzNervousAndJumpy()
    { return true; }

// following each additional week of underground exposure, another Loyalty
// Check is rolled for the character.
inline bool dnzLoyaltyCheckEachAddedWeek()
    { return true; }

// as soon as one of the weekly Loyalty Checks fails, the character becomes
// completely irrational, and the DM rolls 1d100 against Table 20: Unsteady
// NPC Reactions.
inline bool dnzIrrationalOnFail()
    { return true; }

// ---- the unsteady reactions and recovery ----

// effects determined on Table 20 last until the character is slain, or
// returned to the surface.
inline bool dnzEffectUntilSlainOrSurface()
    { return true; }

// a character returned to the surface must spend 1d6 weeks above ground
// before a Wisdom Check is rolled for him - the dice count.
inline int dnzRecoveryWeeksDice()
    { return 1; }

// the above-ground recovery period die: d6.
inline int dnzRecoveryWeeksSides()
    { return 6; }

// if the recovery Wisdom Check succeeds, the character has recovered.
inline bool dnzRecoveryWisCheck()
    { return true; }

// if the recovery Wisdom Check fails, the character is permanently afflicted
// with the appropriate irrational behavior.
inline bool dnzPermanentOnFail()
    { return true; }

// ---- the Table 20 reactions grid ----

// the Table 20 carries four reaction bands: running screaming to the surface,
// attacking a nearby PC, sneaking away quietly, and freezing in place.
inline int dnzT20RowCount()
    { return 4; }

// the row key: 0 runs screaming toward the surface to the limits of his
// Endurance, 1 attacks a nearby PC, 2 attempts to sneak away quietly as soon
// as possible, 3 freezes in place, not reacting or moving.
inline int dnzT20Key(int b)
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
        default:
            return -99;
        }
    }

// the low end of the d100 roll band.
inline int dnzT20Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 56;
        case 3:
            return 86;
        default:
            return -99;
        }
    }

// the high end of the d100 roll band; a rolled 00 reads as 100, so the last
// band pins as 86-100.
inline int dnzT20Hi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 55;
        case 2:
            return 85;
        case 3:
            return 100;
        default:
            return -99;
        }
    }

}   // namespace rules
