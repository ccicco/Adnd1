// =========================================================================================
// Adnd1 - rules/oa118armorexpl.h
// OA TREASURE - THE EXPLANATION OF ARMOR PROPERTIES, printed capture pp.
// 290-291 - the big prose round
// census 669 -> 670.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 200 closed, 35 open - the explanation box
// flips (census 669 -> 670); NEXT - R748: Weapons prose (capture pp.
// 291-294), prefix dlj (verify free at the landing), audit "R748 OA weapons
// prose audit", include after rules/oa118armorexpl.h
//
namespace rules {

// ---- the armor of quality ----

// the quality non-magic - the armor not magical in any way (print capture p.
// 290)
inline int dliQualityNotMagical()
    { return 1; }

// the quality construction - the exceptionally fine construction giving the
// special properties (print capture p. 290)
inline int dliQualityFineConstruction()
    { return 1; }

// the quality armor class - no bonus to the Armor Class (print capture p.
// 290)
inline int dliQualityNoACBonus()
    { return 1; }

// the quality feel - light and highly flexible (print capture p. 290)
inline int dliQualityLightFlexible()
    { return 1; }

// the quality value die - the 2d4 times more valuable than normal, the 4 the
// die of the 2d4 (print capture p. 290)
inline int dliQualityValueDie()
    { return 4; }

// the quality encumbrance - treated as one encumbrance class less than normal
// (print capture p. 290)
inline int dliQualityOneEncumbranceLess()
    { return 1; }

// the quality decoration - decorated with fine artistic taste and quality
// (print capture p. 290)
inline int dliQualityDecorated()
    { return 1; }

// ---- the etherealness, vulnerability, and missile attraction ----

// the etherealness - the wearer made ethereal as per the armor of
// etherealness in the DMG (print capture p. 290)
inline int dliEtherealPerDMG()
    { return 1; }

// the vulnerability - the armor functioning as the armor of vulnerability as
// per the DMG (print capture p. 290)
inline int dliVulnerabilityPerDMG()
    { return 1; }

// the vulnerability pluses - the +1, +2, +3, etc. of the armor actually a
// penalty to the wearer Armor Class (print capture p. 290)
inline int dliVulnerabilityPlusesPenalty()
    { return 1; }

// the missile attraction curse - the armor or shield cursed, functioning
// identically to the missile attractor shield of the DMG (print capture p.
// 290)
inline int dliMissileAttractionCursed()
    { return 1; }

// the missile attraction modifier - the pluses actually a negative modifier
// to the Armor Class (print capture p. 290)
inline int dliMissileAttractionNegative()
    { return 1; }

// ---- the presence and blending ----

// the presence charisma - the 18 Charisma treated for all encounter reactions
// (print capture p. 290)
inline int dliPresenceCharisma()
    { return 18; }

// the presence morale percent - the morale raise of the friendly troops
// (print capture p. 290)
inline int dliPresenceMoralePct()
    { return 10; }

// the presence radius - the 12 feet within which the friendly troops gain the
// morale raise (print capture p. 290)
inline int dliPresenceRadiusFt()
    { return 12; }

// the presence aura - the dignified and commanding aura bestowed on the
// wearer (print capture p. 290)
inline int dliPresenceCommandingAura()
    { return 1; }

// the presence visibility - quite distinctive, only effective when visible,
// no hiding unnoticed in a crowd (print capture p. 290)
inline int dliPresenceOnlyWhenVisible()
    { return 1; }

// the blending concealment - the detect magic not revealing the special
// property (print capture p. 290)
inline int dliBlendingDetectNotReveal()
    { return 1; }

// the blending command word - the armor changing shape and form, appearing as
// normal clothing (print capture p. 290)
inline int dliBlendingCommandWordClothing()
    { return 1; }

// the blending retention - all properties retained and functioning even when
// disguised (print capture p. 290)
inline int dliBlendingRetainsProperties()
    { return 1; }

// the blending reveal - the true nature seen only by a true seeing spell
// (print capture p. 290)
inline int dliBlendingTrueSeeingOnly()
    { return 1; }

// ---- the fear ----

// the fear radius - the 30-foot radius of the fear aura (print capture p.
// 290)
inline int dliFearRadiusFt()
    { return 30; }

// the fear charges die of the p. 290 print - the 2d4 fear charges when found
// (print capture p. 290)
inline int dliFearChargesDieFirst()
    { return 4; }

// the fear charges die of the p. 291 continuation - the 2d10 charges when
// found, the capture discrepancy pinned as printed (print capture p. 291)
inline int dliFearChargesDieSecond()
    { return 10; }

// the fear concealment - the detect magic revealing only that it is magical
// (print capture p. 290)
inline int dliFearDetectOnlyMagical()
    { return 1; }

// the fear command word - upon uttering it the wearer radiates the fear aura
// (print capture p. 290)
inline int dliFearCommandWordAura()
    { return 1; }

// the fear save - all creatures within the radius saving versus spell or
// fleeing in panic for one turn (print capture p. 291)
inline int dliFearSaveOrFleeOneTurn()
    { return 1; }

// the fear immunity - the wearer immune to the effect (print capture p. 291)
inline int dliFearWearerImmune()
    { return 1; }

// the fear cost - each use expending one charge (print capture p. 291)
inline int dliFearOneChargePerUse()
    { return 1; }

// the fear charges discrepancy - the p. 290 printing the 2d4 fear charges
// when found and the p. 291 continuation printing the 2d10 charges when
// found, pinned as printed both pages (print capture p. 291)
inline int dliFearChargesDiscrepancy()
    { return 1; }

// the fear exhaustion - all charges spent, the armor functioning as normal +1
// armor, not rechargeable (print capture p. 291)
inline int dliFearSpentBecomesPlusOne()
    { return 1; }

// ---- the possession ----

// the possession days die - the 3d4 days of the gradual insinuation (print
// capture p. 291)
inline int dliPossessionDaysDie()
    { return 4; }

// the possession appearance - a normal suit of magical armor with the Table
// 76 plus (print capture p. 291)
inline int dliPossessionAppearsNormal()
    { return 1; }

// the possession origin - the craftsman investing more than the normal
// effort, the armor absorbing or stealing the personality and lifeforce of
// its maker (print capture p. 291)
inline int dliPossessionStolenLifeforce()
    { return 1; }

// the possession save - the first time donned and once per day thereafter the
// DM secretly rolling a save versus spell for the wearer (print capture p.
// 291)
inline int dliPossessionFirstDonnedDailySave()
    { return 1; }

// the possession save success - nothing happens (print capture p. 291)
inline int dliPossessionSaveSuccessNothing()
    { return 1; }

// the possession save failure - the lifeforce successfully possessing the
// character (print capture p. 291)
inline int dliPossessionSaveFailPossesses()
    { return 1; }

// the possession pace - not sudden, a gradual insinuation of the new
// personality into the psyche, the odd quirks and the possessiveness growing
// into the full takeover (print capture p. 291)
inline int dliPossessionGradualInsinuation()
    { return 1; }

// the possession symptom - the character refusing to abandon or remove the
// armor (print capture p. 291)
inline int dliPossessionRefusesRemoval()
    { return 1; }

// the possession end - the character entirely possessed, becoming an NPC
// under the control of the DM (print capture p. 291)
inline int dliPossessionBecomesNPC()
    { return 1; }

// the possession cure - an exorcism spell breaking it, destroying the
// personality of the armor (print capture p. 291)
inline int dliPossessionExorcismBreaks()
    { return 1; }

// the possession dispel - a dispel magic releasing the character long enough
// to remove the armor, not canceling the absorbed traits (print capture p.
// 291)
inline int dliPossessionDispelTemporary()
    { return 1; }

// the possession aftermath - the destroyed influence leaving the armor
// without all its magical properties (print capture p. 291)
inline int dliPossessionDestroyedLosesMagic()
    { return 1; }

// ---- the healing ----

// the healing points die - the 2d6 points of damage healed per day (print
// capture p. 291)
inline int dliHealingPointsDie()
    { return 6; }

// the healing charges die - the 3d10 charges when found (print capture p.
// 291)
inline int dliHealingChargesDie()
    { return 10; }

// the healing appearance - the armor appearing to be normal magical armor
// (print capture p. 291)
inline int dliHealingAppearsNormal()
    { return 1; }

// the healing trigger - once per day, automatically, whether desired or not,
// without warning or set time (print capture p. 291)
inline int dliHealingOncePerDayAutomatic()
    { return 1; }

// the healing cost - each healing taking one charge (print capture p. 291)
inline int dliHealingOneChargeEach()
    { return 1; }

// the healing exhaustion - all charges spent, the armor becoming +1 magical
// armor (print capture p. 291)
inline int dliHealingSpentBecomesPlusOne()
    { return 1; }

}   // namespace rules
