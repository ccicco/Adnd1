// =========================================================================================
// Adnd1 - rules/oaabilityprose.h
// THE ABILITY PROSE, printed capture pp. 8-15 - the OA Chapter 1 prose round
// census 538 -> 539.
//
// verified against capture pp. 8-15 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). ADJUDICATIONS: the capture
// prints the Comeliness bands with two holes - no 26-27 band exists between
// the stunning +25 top and the unearthly +28 floor, and the bands print
// contiguous otherwise; both pinned as printed, flagged for the physical
// copy. The smitten doctrine prints the fascinate equation with the +t
// contrary-interest modifier read as the plus-one-class hazard ladder (up to
// +6 or more at the extreme) - pinned as the printed ladder. The
// reaction-band reaction-adds (score, 150 percent, twice) pin as the printed
// multipliers.
//
// the gap census after this round: 18 closed, 217 open - the six ability
// prose boxes flip and Chapter 1 closes COMPLETE (the parent closed at R614;
// every child now closed) - the first full OA chapter in the arc (census 538
// -> 539); NEXT - R617: Chapter 2 opens - the Class and Race Combinations
// prose, Tables 9, 10, 12 and 13 (the limits and the armor/weapons grids),
// prefix dgd (verify free), audit "R617 OA class combos audit", include after
// rules/oaabilityprose.h
//
namespace rules {

// ---- the Dexterity and Constitution prose pins ----

// Dexterity prose (capture pp. 8-9): the ninja prime requisite - Dex 16 or
// higher earns the 10 percent experience bonus
inline bool dgcDexPrime()
    { return true; }

// Dexterity prose (capture p. 9): the reaction/attacking adjustment applies
// to missile-fire to-hit rolls and to both sides of a surprise situation
// (capturing and being captured)
inline bool dgcDexMissileAndSurprise()
    { return true; }

// Dexterity prose (capture p. 9): the defensive adjustment applies to
// dodgable saving throws (fireballs, lightning bolts, boulders) and modifies
// Armor Class - the Ieyasu haramaki-do example: AC 6 modified to 4 at Dex 16,
// to 8 at Dex 5
inline bool dgcDexDefensiveDodge()
    { return true; }

// Constitution prose (capture p. 9): the initial Constitution score is the
// absolute limit on revivals - each raise or resurrection reduces
// Constitution by one (the printed Ieyasu example: Con 12 allows 12 revivals)
inline bool dgcConRevivalLimit()
    { return true; }

// Constitution prose (capture p. 9): magic can restore a reduced Constitution
// score but has no effect on the revival count - the original score binds;
// only a wish revives past the limit
inline bool dgcConRestoreNoRefund()
    { return true; }

// Constitution prose (capture p. 10): the system shock roll repeats on the
// return polymorph - surviving the change does not survive the change back
inline bool dgcConShockSecondRoll()
    { return true; }

// Constitution prose (capture p. 10): a failed resurrection survival roll is
// final - the character is irrevocably dead regardless of prior revivals
inline bool dgcConResurrectionFail()
    { return true; }

// ---- the Intelligence Wisdom and Charisma prose pins ----

// Intelligence prose (capture p. 11): the wu jen prime requisite - Int 16 or
// higher earns the 10 percent experience bonus
inline bool dgcIntPrime()
    { return true; }

// Intelligence prose (capture p. 11): the wu jen Intelligence gates which
// spells he can learn and how many he can remember; only the highest
// Intelligence comprehends 9th-level spells
inline bool dgcIntSpellGate()
    { return true; }

// Wisdom prose (capture p. 11): the shukenja prime requisite - Wis 16 or
// higher earns the 10 percent experience bonus
inline bool dgcWisPrime()
    { return true; }

// Wisdom prose (capture p. 11): shukenja and sohei with Wisdom 13 or higher
// gain bonus spells over their normal allowance
inline bool dgcWisBonusSpells()
    { return true; }

// Charisma prose (capture p. 12): the maximum henchmen is an absolute limit
// on permanent unpaid companions; killed or mistreated henchmen cannot be
// replaced; paid servitors are unaffected
inline bool dgcChaHenchmenPaid()
    { return true; }

// ---- the Comeliness base and racial pins ----

// Comeliness prose (capture p. 13): the base roll is 3d6 - a raw 3 to 18
// range before the Charisma adjustment
inline int dgcComBaseDie()
    { return 3; }

// Comeliness prose (capture p. 13): the human Comeliness floor - the -2 after
// the Charisma ladder
inline int dgcComHumanMin()
    { return -2; }

// Comeliness prose (capture p. 13): the human Comeliness ceiling after the
// Charisma ladder
inline int dgcComHumanMax()
    { return 23; }

// Comeliness prose (capture p. 13): Comeliness tracks Charisma
// point-for-point through disease, disfigurement, aging and magic
inline bool dgcComCharismaTracks()
    { return true; }

// Comeliness prose (capture p. 13): the racial Comeliness adjustments apply
// only when interacting with characters of other races
inline bool dgcComRacialOtherRaceOnly()
    { return true; }

// Comeliness prose (capture p. 13): the korobokuru racial Comeliness
// adjustment
inline int dgcComRacialKorobokuru()
    { return -2; }

// Comeliness prose (capture p. 13): the hengeyokai racial Comeliness
// adjustment
inline int dgcComRacialHengeyokai()
    { return -1; }

// Comeliness prose (capture p. 13): the spirit folk racial Comeliness
// adjustment
inline int dgcComRacialSpiritFolk()
    { return 1; }

// ---- the Comeliness reaction band pins ----

// Comeliness bands (capture p. 13): the -16-or-lower horror band - repulsion,
// destruction or escape; evil viewers of an evil creature read the negative
// total as positive
inline int dgcBandHorrorMax()
    { return -16; }

// Comeliness bands (capture p. 13): the -15-to--9 disgust band - revilement
// and hostility, no acceptance unless all are evil
inline int dgcBandDisgustMax()
    { return -9; }

// Comeliness bands (capture p. 14): the -8-to-0 aversion band - rejection,
// hostility if provoked
inline int dgcBandAversionMax()
    { return 0; }

// Comeliness bands (capture p. 14): the +1-to-+6 ugly band - unease; high
// Charisma can offset through conversation
inline int dgcBandUglyMax()
    { return 6; }

// Comeliness bands (capture p. 14): the +7-to-+9 homely band - a bad first
// impression, quickly overcome by high Charisma
inline int dgcBandHomelyMax()
    { return 9; }

// Comeliness bands (capture p. 14): the +10-to-+13 plain band - no effect on
// others
inline int dgcBandPlainMax()
    { return 13; }

// Comeliness bands (capture p. 14): the +14-to-+17 good-looking band - watch
// and stare; add the Comeliness score to the reaction roll; the opposite sex
// smitten at Wisdom 50 percent or less of the Comeliness score
inline int dgcBandGoodlookingMin()
    { return 14; }

// Comeliness bands (capture p. 14): the top of the good-looking band
inline int dgcBandGoodlookingMax()
    { return 17; }

// Comeliness bands (capture p. 14): the good-looking band adds the Comeliness
// score itself to the percentile reaction roll
inline bool dgcBandGoodlookingReactionAdd()
    { return true; }

// Comeliness bands (capture p. 14): the +18-to-+21 beautiful band - heads
// turn and hearts race
inline int dgcBandBeautifulMin()
    { return 18; }

// Comeliness bands (capture p. 14): the top of the beautiful band
inline int dgcBandBeautifulMax()
    { return 21; }

// Comeliness bands (capture p. 14): the beautiful band adds 150 percent of
// the Comeliness score to the initial reaction roll
inline int dgcBandBeautifulPct()
    { return 150; }

// Comeliness bands (capture p. 14): in the beautiful band the opposite sex is
// smitten unless Wisdom exceeds two-thirds of the Comeliness score; the same
// sex unless Wisdom is at least 50 percent
inline bool dgcBandBeautifulSmitten()
    { return true; }

// Comeliness bands (capture p. 14): a harsh rejection in the beautiful band
// makes the rejected react as if the Comeliness were a negative score of half
// the actual positive total
inline bool dgcBandRejectionHalfNegative()
    { return true; }

// Comeliness bands (capture p. 14): the +22-to-+25 stunning band - people
// flock and behave outrageously to attract attention
inline int dgcBandStunningMin()
    { return 22; }

// Comeliness bands (capture p. 14): the top of the stunning band
inline int dgcBandStunningMax()
    { return 25; }

// Comeliness bands (capture p. 14): the stunning band reaction adjustment is
// twice the Comeliness score - the printed Comeliness 22 equals +44 example
inline bool dgcBandStunningReactionTwice()
    { return true; }

// Comeliness bands (capture p. 14): in the stunning band anyone whose Wisdom
// is less than two-thirds of the Comeliness score is smitten; a purposefully
// sought opposite-sex target is smitten unless Wisdom is 18 or more
inline bool dgcBandStunningSmitten()
    { return true; }

// Comeliness bands (capture p. 14): the +28-to-+30 unearthly band - only
// creatures from other planes: demi-gods and unusual deities
inline int dgcBandUnearthlyMin()
    { return 28; }

// Comeliness bands (capture p. 14): the top of the unearthly band
inline int dgcBandUnearthlyMax()
    { return 30; }

// Comeliness bands (capture p. 14): in the unearthly band the looks affect
// everyone except viewers with Wisdom at least 75 percent of the Comeliness
// score; Wisdom 19 or more earns a saving throw; a sought opposite-sex target
// escapes only at Wisdom 20 or more
inline bool dgcBandUnearthlySave()
    { return true; }

// ---- the smitten doctrine and the magic-cap pins ----

// the smitten doctrine (capture p. 14): a smitten creature acts as if under
// the 2nd-level illusionist spell fascinate (Unearthed Arcana) - trusted
// friend and companion; a successful saving throw vs. spell negates
inline bool dgcSmittenFascinate()
    { return true; }

// the smitten doctrine (capture p. 14): if the Comeliness is not magical,
// dispel magic and anti-magic spells do not affect the fascination
inline bool dgcSmittenNonmagical()
    { return true; }

// the smitten doctrine (capture p. 14): a smitten creature follows orders if
// 3d6 does not exceed the Comeliness score; contrary-to-interest orders gain
// a modifier; hazardous orders up to +6 or more; a higher roll breaks the
// effect
inline bool dgcSmittenOrderRoll()
    { return true; }

// the smitten doctrine (capture p. 15): being smitten does not affect
// fighting or spellcasting ability, nor reduce the target to a zombie or a
// puppet - alignment still guides; contrary instructions allow a +3 or +4
// modifier to break the effect
inline bool dgcSmittenNotPuppet()
    { return true; }

// the smitten doctrine (capture p. 14): a badly treated creature that breaks
// free reacts as if the Comeliness were negative; a well-treated one may stay
// friendly after the effect fades
inline bool dgcSmittenBadTreatmentNegative()
    { return true; }

// Comeliness prose (capture p. 14): the high-Comeliness effect is temporary -
// once known, Comeliness is negated and Charisma determines reactions and
// followers (beauty is only skin deep)
inline bool dgcComTemporary()
    { return true; }

// Comeliness prose (capture p. 15): illusion spells raise or lower Comeliness
// by at most one point; illusions of high-Comeliness figures last a single
// round - the high Comeliness focuses attention and weakens the illusion
inline bool dgcComIllusionCapOne()
    { return true; }

// Comeliness prose (capture p. 15): polymorph spells adjust the subject
// Comeliness by only two points - the subtle non-visual social clues
inline int dgcComPolymorphCap()
    { return 2; }

// Comeliness prose (capture p. 15): shapechange confers the full Comeliness
// effects of the final form
inline bool dgcComShapechangeFull()
    { return true; }

}   // namespace rules
