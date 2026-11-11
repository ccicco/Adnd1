-- oa616: promoted from rules/oa/oaabilityprose.h (the THE ABILITY PROSE, printed capture pp. 8-15 - the OA Chapter 1 prose round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 616,
  "prefix" = "oa616",
  "banner" = {
      "title" = "THE ABILITY PROSE, printed capture pp. 8-15 - the OA Chapter 1 prose round",
      "provenance" = "census 538 -> 539.  verified against capture pp. 8-15 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). ADJUDICATIONS: the capture prints the Comeliness bands with two holes - no 26-27 band exists between the stunning +25 top and the unearthly +28 floor, and the bands print contiguous otherwise; both pinned as printed, flagged for the physical copy. The smitten doctrine prints the fascinate equation with the +t contrary-interest modifier read as the plus-one-class hazard ladder (up to +6 or more at the extreme) - pinned as the printed ladder. The reaction-band reaction-adds (score, 150 percent, twice) pin as the printed multipliers.  the gap census after this round: 18 closed, 217 open - the six ability prose boxes flip and Chapter 1 closes COMPLETE (the parent closed at R614; every child now closed) - the first full OA chapter in the arc (census 538 -> 539); NEXT - R617: Chapter 2 opens - the Class and Race Combinations prose, Tables 9, 10, 12 and 13 (the limits and the armor/weapons grids), prefix dgd (verify free), audit \"R617 OA class combos audit\", include after rules/oa/oaabilityprose.h",
    },
  "consts" = { {
      "name" = "dgcComBaseDie",
      "value" = 3,
      "comment" = "Comeliness prose (capture p. 13): the base roll is 3d6 - a raw 3 to 18 range before the Charisma adjustment",
    }, {
      "name" = "dgcComHumanMin",
      "value" = -2,
      "comment" = "Comeliness prose (capture p. 13): the human Comeliness floor - the -2 after the Charisma ladder",
    }, {
      "name" = "dgcComHumanMax",
      "value" = 23,
      "comment" = "Comeliness prose (capture p. 13): the human Comeliness ceiling after the Charisma ladder",
    }, {
      "name" = "dgcComRacialKorobokuru",
      "value" = -2,
      "comment" = "Comeliness prose (capture p. 13): the korobokuru racial Comeliness adjustment",
    }, {
      "name" = "dgcComRacialHengeyokai",
      "value" = -1,
      "comment" = "Comeliness prose (capture p. 13): the hengeyokai racial Comeliness adjustment",
    }, {
      "name" = "dgcComRacialSpiritFolk",
      "value" = 1,
      "comment" = "Comeliness prose (capture p. 13): the spirit folk racial Comeliness adjustment",
    }, {
      "name" = "dgcBandHorrorMax",
      "value" = -16,
      "comment" = "Comeliness bands (capture p. 13): the -16-or-lower horror band - repulsion, destruction or escape; evil viewers of an evil creature read the negative total as positive",
    }, {
      "name" = "dgcBandDisgustMax",
      "value" = -9,
      "comment" = "Comeliness bands (capture p. 13): the -15-to--9 disgust band - revilement and hostility, no acceptance unless all are evil",
    }, {
      "name" = "dgcBandAversionMax",
      "value" = 0,
      "comment" = "Comeliness bands (capture p. 14): the -8-to-0 aversion band - rejection, hostility if provoked",
    }, {
      "name" = "dgcBandUglyMax",
      "value" = 6,
      "comment" = "Comeliness bands (capture p. 14): the +1-to-+6 ugly band - unease; high Charisma can offset through conversation",
    }, {
      "name" = "dgcBandHomelyMax",
      "value" = 9,
      "comment" = "Comeliness bands (capture p. 14): the +7-to-+9 homely band - a bad first impression, quickly overcome by high Charisma",
    }, {
      "name" = "dgcBandPlainMax",
      "value" = 13,
      "comment" = "Comeliness bands (capture p. 14): the +10-to-+13 plain band - no effect on others",
    }, {
      "name" = "dgcBandGoodlookingMin",
      "value" = 14,
      "comment" = "Comeliness bands (capture p. 14): the +14-to-+17 good-looking band - watch and stare; add the Comeliness score to the reaction roll; the opposite sex smitten at Wisdom 50 percent or less of the Comeliness score",
    }, {
      "name" = "dgcBandGoodlookingMax",
      "value" = 17,
      "comment" = "Comeliness bands (capture p. 14): the top of the good-looking band",
    }, {
      "name" = "dgcBandBeautifulMin",
      "value" = 18,
      "comment" = "Comeliness bands (capture p. 14): the +18-to-+21 beautiful band - heads turn and hearts race",
    }, {
      "name" = "dgcBandBeautifulMax",
      "value" = 21,
      "comment" = "Comeliness bands (capture p. 14): the top of the beautiful band",
    }, {
      "name" = "dgcBandBeautifulPct",
      "value" = 150,
      "comment" = "Comeliness bands (capture p. 14): the beautiful band adds 150 percent of the Comeliness score to the initial reaction roll",
    }, {
      "name" = "dgcBandStunningMin",
      "value" = 22,
      "comment" = "Comeliness bands (capture p. 14): the +22-to-+25 stunning band - people flock and behave outrageously to attract attention",
    }, {
      "name" = "dgcBandStunningMax",
      "value" = 25,
      "comment" = "Comeliness bands (capture p. 14): the top of the stunning band",
    }, {
      "name" = "dgcBandUnearthlyMin",
      "value" = 28,
      "comment" = "Comeliness bands (capture p. 14): the +28-to-+30 unearthly band - only creatures from other planes: demi-gods and unusual deities",
    }, {
      "name" = "dgcBandUnearthlyMax",
      "value" = 30,
      "comment" = "Comeliness bands (capture p. 14): the top of the unearthly band",
    }, {
      "name" = "dgcComPolymorphCap",
      "value" = 2,
      "comment" = "Comeliness prose (capture p. 15): polymorph spells adjust the subject Comeliness by only two points - the subtle non-visual social clues",
    } },
  "bools" = { {
      "name" = "dgcDexPrime",
      "value" = true,
      "comment" = "Dexterity prose (capture pp. 8-9): the ninja prime requisite - Dex 16 or higher earns the 10 percent experience bonus",
    }, {
      "name" = "dgcDexMissileAndSurprise",
      "value" = true,
      "comment" = "Dexterity prose (capture p. 9): the reaction/attacking adjustment applies to missile-fire to-hit rolls and to both sides of a surprise situation (capturing and being captured)",
    }, {
      "name" = "dgcDexDefensiveDodge",
      "value" = true,
      "comment" = "Dexterity prose (capture p. 9): the defensive adjustment applies to dodgable saving throws (fireballs, lightning bolts, boulders) and modifies Armor Class - the Ieyasu haramaki-do example: AC 6 modified to 4 at Dex 16, to 8 at Dex 5",
    }, {
      "name" = "dgcConRevivalLimit",
      "value" = true,
      "comment" = "Constitution prose (capture p. 9): the initial Constitution score is the absolute limit on revivals - each raise or resurrection reduces Constitution by one (the printed Ieyasu example: Con 12 allows 12 revivals)",
    }, {
      "name" = "dgcConRestoreNoRefund",
      "value" = true,
      "comment" = "Constitution prose (capture p. 9): magic can restore a reduced Constitution score but has no effect on the revival count - the original score binds; only a wish revives past the limit",
    }, {
      "name" = "dgcConShockSecondRoll",
      "value" = true,
      "comment" = "Constitution prose (capture p. 10): the system shock roll repeats on the return polymorph - surviving the change does not survive the change back",
    }, {
      "name" = "dgcConResurrectionFail",
      "value" = true,
      "comment" = "Constitution prose (capture p. 10): a failed resurrection survival roll is final - the character is irrevocably dead regardless of prior revivals",
    }, {
      "name" = "dgcIntPrime",
      "value" = true,
      "comment" = "Intelligence prose (capture p. 11): the wu jen prime requisite - Int 16 or higher earns the 10 percent experience bonus",
    }, {
      "name" = "dgcIntSpellGate",
      "value" = true,
      "comment" = "Intelligence prose (capture p. 11): the wu jen Intelligence gates which spells he can learn and how many he can remember; only the highest Intelligence comprehends 9th-level spells",
    }, {
      "name" = "dgcWisPrime",
      "value" = true,
      "comment" = "Wisdom prose (capture p. 11): the shukenja prime requisite - Wis 16 or higher earns the 10 percent experience bonus",
    }, {
      "name" = "dgcWisBonusSpells",
      "value" = true,
      "comment" = "Wisdom prose (capture p. 11): shukenja and sohei with Wisdom 13 or higher gain bonus spells over their normal allowance",
    }, {
      "name" = "dgcChaHenchmenPaid",
      "value" = true,
      "comment" = "Charisma prose (capture p. 12): the maximum henchmen is an absolute limit on permanent unpaid companions; killed or mistreated henchmen cannot be replaced; paid servitors are unaffected",
    }, {
      "name" = "dgcComCharismaTracks",
      "value" = true,
      "comment" = "Comeliness prose (capture p. 13): Comeliness tracks Charisma point-for-point through disease, disfigurement, aging and magic",
    }, {
      "name" = "dgcComRacialOtherRaceOnly",
      "value" = true,
      "comment" = "Comeliness prose (capture p. 13): the racial Comeliness adjustments apply only when interacting with characters of other races",
    }, {
      "name" = "dgcBandGoodlookingReactionAdd",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): the good-looking band adds the Comeliness score itself to the percentile reaction roll",
    }, {
      "name" = "dgcBandBeautifulSmitten",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): in the beautiful band the opposite sex is smitten unless Wisdom exceeds two-thirds of the Comeliness score; the same sex unless Wisdom is at least 50 percent",
    }, {
      "name" = "dgcBandRejectionHalfNegative",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): a harsh rejection in the beautiful band makes the rejected react as if the Comeliness were a negative score of half the actual positive total",
    }, {
      "name" = "dgcBandStunningReactionTwice",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): the stunning band reaction adjustment is twice the Comeliness score - the printed Comeliness 22 equals +44 example",
    }, {
      "name" = "dgcBandStunningSmitten",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): in the stunning band anyone whose Wisdom is less than two-thirds of the Comeliness score is smitten; a purposefully sought opposite-sex target is smitten unless Wisdom is 18 or more",
    }, {
      "name" = "dgcBandUnearthlySave",
      "value" = true,
      "comment" = "Comeliness bands (capture p. 14): in the unearthly band the looks affect everyone except viewers with Wisdom at least 75 percent of the Comeliness score; Wisdom 19 or more earns a saving throw; a sought opposite-sex target escapes only at Wisdom 20 or more",
    }, {
      "name" = "dgcSmittenFascinate",
      "value" = true,
      "comment" = "the smitten doctrine (capture p. 14): a smitten creature acts as if under the 2nd-level illusionist spell fascinate (Unearthed Arcana) - trusted friend and companion; a successful saving throw vs. spell negates",
    }, {
      "name" = "dgcSmittenNonmagical",
      "value" = true,
      "comment" = "the smitten doctrine (capture p. 14): if the Comeliness is not magical, dispel magic and anti-magic spells do not affect the fascination",
    }, {
      "name" = "dgcSmittenOrderRoll",
      "value" = true,
      "comment" = "the smitten doctrine (capture p. 14): a smitten creature follows orders if 3d6 does not exceed the Comeliness score; contrary-to-interest orders gain a modifier; hazardous orders up to +6 or more; a higher roll breaks the effect",
    }, {
      "name" = "dgcSmittenNotPuppet",
      "value" = true,
      "comment" = "the smitten doctrine (capture p. 15): being smitten does not affect fighting or spellcasting ability, nor reduce the target to a zombie or a puppet - alignment still guides; contrary instructions allow a +3 or +4 modifier to break the effect",
    }, {
      "name" = "dgcSmittenBadTreatmentNegative",
      "value" = true,
      "comment" = "the smitten doctrine (capture p. 14): a badly treated creature that breaks free reacts as if the Comeliness were negative; a well-treated one may stay friendly after the effect fades",
    }, {
      "name" = "dgcComTemporary",
      "value" = true,
      "comment" = "Comeliness prose (capture p. 14): the high-Comeliness effect is temporary - once known, Comeliness is negated and Charisma determines reactions and followers (beauty is only skin deep)",
    }, {
      "name" = "dgcComIllusionCapOne",
      "value" = true,
      "comment" = "Comeliness prose (capture p. 15): illusion spells raise or lower Comeliness by at most one point; illusions of high-Comeliness figures last a single round - the high Comeliness focuses attention and weakens the illusion",
    }, {
      "name" = "dgcComShapechangeFull",
      "value" = true,
      "comment" = "Comeliness prose (capture p. 15): shapechange confers the full Comeliness effects of the final form",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgcComBaseDie']() != 3  or m['dgcComHumanMin']() != -2  or m['dgcComHumanMax']() != 23  or m['dgcComRacialKorobokuru']() != -2  or m['dgcComRacialHengeyokai']() != -1  or m['dgcComRacialSpiritFolk']() != 1  or m['dgcBandHorrorMax']() != -16  or m['dgcBandDisgustMax']() != -9  or m['dgcBandAversionMax']() != 0  or m['dgcBandUglyMax']() != 6  or m['dgcBandHomelyMax']() != 9  or m['dgcBandPlainMax']() != 13  or m['dgcBandGoodlookingMin']() != 14  or m['dgcBandGoodlookingMax']() != 17  or m['dgcBandBeautifulMin']() != 18  or m['dgcBandBeautifulMax']() != 21  or m['dgcBandBeautifulPct']() != 150  or m['dgcBandStunningMin']() != 22  or m['dgcBandStunningMax']() != 25  or m['dgcBandUnearthlyMin']() != 28  or m['dgcBandUnearthlyMax']() != 30  or m['dgcComPolymorphCap']() != 2  or  m['dgcDexPrime']() != 1  or  m['dgcDexMissileAndSurprise']() != 1  or  m['dgcDexDefensiveDodge']() != 1  or  m['dgcConRevivalLimit']() != 1  or  m['dgcConRestoreNoRefund']() != 1  or  m['dgcConShockSecondRoll']() != 1  or  m['dgcConResurrectionFail']() != 1  or  m['dgcIntPrime']() != 1  or  m['dgcIntSpellGate']() != 1  or  m['dgcWisPrime']() != 1  or  m['dgcWisBonusSpells']() != 1  or  m['dgcChaHenchmenPaid']() != 1  or  m['dgcComCharismaTracks']() != 1  or  m['dgcComRacialOtherRaceOnly']() != 1  or  m['dgcBandGoodlookingReactionAdd']() != 1  or  m['dgcBandBeautifulSmitten']() != 1  or  m['dgcBandRejectionHalfNegative']() != 1  or  m['dgcBandStunningReactionTwice']() != 1  or  m['dgcBandStunningSmitten']() != 1  or  m['dgcBandUnearthlySave']() != 1  or  m['dgcSmittenFascinate']() != 1  or  m['dgcSmittenNonmagical']() != 1  or  m['dgcSmittenOrderRoll']() != 1  or  m['dgcSmittenNotPuppet']() != 1  or  m['dgcSmittenBadTreatmentNegative']() != 1  or  m['dgcComTemporary']() != 1  or  m['dgcComIllusionCapOne']() != 1  or  m['dgcComShapechangeFull']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgcDexPrime']() != 1",
      "note" = "the dgcDexPrime pin",
    }, {
      "expr" = "m['dgcDexMissileAndSurprise']() != 1",
      "note" = "the dgcDexMissileAndSurprise pin",
    }, {
      "expr" = "m['dgcDexDefensiveDodge']() != 1",
      "note" = "the dgcDexDefensiveDodge pin",
    }, {
      "expr" = "m['dgcConRevivalLimit']() != 1",
      "note" = "the dgcConRevivalLimit pin",
    }, {
      "expr" = "m['dgcConRestoreNoRefund']() != 1",
      "note" = "the dgcConRestoreNoRefund pin",
    }, {
      "expr" = "m['dgcConShockSecondRoll']() != 1",
      "note" = "the dgcConShockSecondRoll pin",
    }, {
      "expr" = "m['dgcConResurrectionFail']() != 1",
      "note" = "the dgcConResurrectionFail pin",
    }, {
      "expr" = "m['dgcIntPrime']() != 1",
      "note" = "the dgcIntPrime pin",
    }, {
      "expr" = "m['dgcIntSpellGate']() != 1",
      "note" = "the dgcIntSpellGate pin",
    }, {
      "expr" = "m['dgcWisPrime']() != 1",
      "note" = "the dgcWisPrime pin",
    }, {
      "expr" = "m['dgcWisBonusSpells']() != 1",
      "note" = "the dgcWisBonusSpells pin",
    }, {
      "expr" = "m['dgcChaHenchmenPaid']() != 1",
      "note" = "the dgcChaHenchmenPaid pin",
    }, {
      "expr" = "m['dgcComBaseDie']() != 3",
      "note" = "the dgcComBaseDie pin",
    }, {
      "expr" = "m['dgcComHumanMin']() != -2",
      "note" = "the dgcComHumanMin pin",
    }, {
      "expr" = "m['dgcComHumanMax']() != 23",
      "note" = "the dgcComHumanMax pin",
    }, {
      "expr" = "m['dgcComCharismaTracks']() != 1",
      "note" = "the dgcComCharismaTracks pin",
    }, {
      "expr" = "m['dgcComRacialOtherRaceOnly']() != 1",
      "note" = "the dgcComRacialOtherRaceOnly pin",
    }, {
      "expr" = "m['dgcComRacialKorobokuru']() != -2",
      "note" = "the dgcComRacialKorobokuru pin",
    }, {
      "expr" = "m['dgcComRacialHengeyokai']() != -1",
      "note" = "the dgcComRacialHengeyokai pin",
    }, {
      "expr" = "m['dgcComRacialSpiritFolk']() != 1",
      "note" = "the dgcComRacialSpiritFolk pin",
    }, {
      "expr" = "m['dgcBandHorrorMax']() != -16",
      "note" = "the dgcBandHorrorMax pin",
    }, {
      "expr" = "m['dgcBandDisgustMax']() != -9",
      "note" = "the dgcBandDisgustMax pin",
    }, {
      "expr" = "m['dgcBandAversionMax']() != 0",
      "note" = "the dgcBandAversionMax pin",
    }, {
      "expr" = "m['dgcBandUglyMax']() != 6",
      "note" = "the dgcBandUglyMax pin",
    }, {
      "expr" = "m['dgcBandHomelyMax']() != 9",
      "note" = "the dgcBandHomelyMax pin",
    }, {
      "expr" = "m['dgcBandPlainMax']() != 13",
      "note" = "the dgcBandPlainMax pin",
    }, {
      "expr" = "m['dgcBandGoodlookingMin']() != 14",
      "note" = "the dgcBandGoodlookingMin pin",
    }, {
      "expr" = "m['dgcBandGoodlookingMax']() != 17",
      "note" = "the dgcBandGoodlookingMax pin",
    }, {
      "expr" = "m['dgcBandGoodlookingReactionAdd']() != 1",
      "note" = "the dgcBandGoodlookingReactionAdd pin",
    }, {
      "expr" = "m['dgcBandBeautifulMin']() != 18",
      "note" = "the dgcBandBeautifulMin pin",
    }, {
      "expr" = "m['dgcBandBeautifulMax']() != 21",
      "note" = "the dgcBandBeautifulMax pin",
    }, {
      "expr" = "m['dgcBandBeautifulPct']() != 150",
      "note" = "the dgcBandBeautifulPct pin",
    }, {
      "expr" = "m['dgcBandBeautifulSmitten']() != 1",
      "note" = "the dgcBandBeautifulSmitten pin",
    }, {
      "expr" = "m['dgcBandRejectionHalfNegative']() != 1",
      "note" = "the dgcBandRejectionHalfNegative pin",
    }, {
      "expr" = "m['dgcBandStunningMin']() != 22",
      "note" = "the dgcBandStunningMin pin",
    }, {
      "expr" = "m['dgcBandStunningMax']() != 25",
      "note" = "the dgcBandStunningMax pin",
    }, {
      "expr" = "m['dgcBandStunningReactionTwice']() != 1",
      "note" = "the dgcBandStunningReactionTwice pin",
    }, {
      "expr" = "m['dgcBandStunningSmitten']() != 1",
      "note" = "the dgcBandStunningSmitten pin",
    }, {
      "expr" = "m['dgcBandUnearthlyMin']() != 28",
      "note" = "the dgcBandUnearthlyMin pin",
    }, {
      "expr" = "m['dgcBandUnearthlyMax']() != 30",
      "note" = "the dgcBandUnearthlyMax pin",
    }, {
      "expr" = "m['dgcBandUnearthlySave']() != 1",
      "note" = "the dgcBandUnearthlySave pin",
    }, {
      "expr" = "m['dgcSmittenFascinate']() != 1",
      "note" = "the dgcSmittenFascinate pin",
    }, {
      "expr" = "m['dgcSmittenNonmagical']() != 1",
      "note" = "the dgcSmittenNonmagical pin",
    }, {
      "expr" = "m['dgcSmittenOrderRoll']() != 1",
      "note" = "the dgcSmittenOrderRoll pin",
    }, {
      "expr" = "m['dgcSmittenNotPuppet']() != 1",
      "note" = "the dgcSmittenNotPuppet pin",
    }, {
      "expr" = "m['dgcSmittenBadTreatmentNegative']() != 1",
      "note" = "the dgcSmittenBadTreatmentNegative pin",
    }, {
      "expr" = "m['dgcComTemporary']() != 1",
      "note" = "the dgcComTemporary pin",
    }, {
      "expr" = "m['dgcComIllusionCapOne']() != 1",
      "note" = "the dgcComIllusionCapOne pin",
    }, {
      "expr" = "m['dgcComPolymorphCap']() != 2",
      "note" = "the dgcComPolymorphCap pin",
    }, {
      "expr" = "m['dgcComShapechangeFull']() != 1",
      "note" = "the dgcComShapechangeFull pin",
    }, {
      "expr" = "m['dgcBandDisgustMax']() -m['dgcBandHorrorMax']() != 7",
      "note" = "the disgust band spans its seven scores above the horror floor (capture pp. 13-14)",
    }, {
      "expr" = "m['dgcBandBeautifulPct']() != 150",
      "note" = "the printed 150 percent beautiful-band reaction (capture p. 14)",
    }, {
      "expr" = "m['dgcBandStunningMin']() * 2 != 44",
      "note" = "the stunning band doubles the score - the printed 22-to-44 example (capture p. 14)",
    }, {
      "expr" = "m['dgcComHumanMax']() -m['dgcComHumanMin']() != 25",
      "note" = "the human Comeliness range spans the ladder (capture p. 13)",
    }, {
      "expr" = "m['dgcComPolymorphCap']() !=m['dgcComIllusionCapOne']() * 2",
      "note" = "the polymorph cap doubles the illusion cap (capture p. 15)",
    }, {
      "expr" = "m['dgcBandUnearthlyMin']() -m['dgcBandStunningMax']() != 3",
      "note" = "the unearthly band sits above the stunning band with the printed 26-27 hole (capture p. 14)",
    } },
  "audit" = {
      "label" = "R616 OA ability prose audit",
      "comment" = "OA round three (capture pp. 8-15): the six ability prose sub-items - the prime requisites and column explanations, the Constitution revival ledger, the Comeliness reaction bands with the smitten doctrine and the magic caps.",
    },
}
