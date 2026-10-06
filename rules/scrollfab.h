// ====================================================================
// Adnd1 - rules/scrollfab.h
// R217: the scroll manufacture and
// fabrication pins (DMG pp.118-121) -
// the scroll inscription rules and
// failure chance, and the fabrication
// of other magic items.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the ink recipes and the actual
// scribing; the gates and the numeric
// conventions read here).
//
// Conventions and judgments, named in
// place:
//   - Inscribers: clerics, druids,
//     magic-users and illusionists of 7th
//     or higher level may inscribe
//     scrolls; the spell must be one the
//     inscriber is able to employ. The
//     write spell enables reference works
//     only - not scroll inscription.
//   - Protection scroll split: clerical
//     protection scrolls cover devils,
//     possession and undead; magic-user
//     protection scrolls cover demons,
//     elementals, lycanthropes, magic and
//     petrification. Curse scrolls can
//     be made by any spell user.
//   - Materials: papyrus 2 gp and up per
//     sheet with +5 percent failure;
//     parchment 4 gp and up at +/-0;
//     vellum 8 gp and up at -5 percent -
//     the most desirable. A fresh, virgin
//     quill must be used for each spell
//     transcribed, from a creature of
//     strange or magical nature (the six
//     named: griffon, harpy, hippogriff,
//     pegasus, roc, sphinx; demons,
//     devils, lammasu and similar at DM
//     election). Ink is compounded only
//     by the inscriber from giant squid
//     sepia or giant octopus ink as the
//     base medium; each different spell
//     requires a different ink.
//   - Preparation: one full day per level
//     of the spell being scribed,
//     continuous - rest, food and sleep
//     only. Leaving the scroll breaks the
//     magic and the effort is for naught.
//   - Failure chance: 20 percent base +
//     1 percent per spell level - the
//     character level + the material
//     modifier. The print example: a 14th
//     level cleric scribing a 7th level
//     spell on parchment fails at 13
//     percent. A percentile roll greater
//     than the chance equals success; the
//     print sets no floor.
//   - Multiple spells: a failure of one
//     spell means no further spells may
//     be placed on the scroll; a maximum
//     of 7 spells per scroll.
//   - Transcribing an unknown spell from
//     a scroll to books: read magic, then
//     a period equal to scribing the
//     spell onto a scroll; the spell then
//     disappears from the scroll. The
//     scriber never needs read magic for
//     his or her own scroll spells;
//     clerics and druids never need it.
//   - Fabrication of other magic items:
//     all require enchant an item (save
//     clerical items). A permanent dweomer
//     requires a permanency spell;
//     chargeable items do not. After
//     manufacture the maker must rest one
//     day per 100 gp of the item XP value
//     (2000 xp = 20 days) in relative
//     isolation - no adventuring or spell
//     use.
//   - Cleric/druid fabrication: a fortnight
//     in retreat meditating in complete
//     isolation, then a sennight fasting,
//     then a day of prayer and
//     purification; then a cumulative 1
//     percent per day chance the deity
//     empowers the item. A charged item
//     must receive its spells within 24
//     hours of the favor; other items
//     need only sanctification.
//   - Illusionist fabrication: scrolls at
//     7th level; one-shot and charged
//     items (no permanent dweomer) at
//     11th - major creation prepares the
//     item, then a 16-hour uninterrupted
//     instilling window; permanent dweomers
//     at 14th - major creation plus alter
//     reality, with an unflawed gem worth
//     not less than 10000 gp.
//   - Charmed, magically persuaded or
//     enslaved magic-users are totally
//     unable to fabricate any magic item;
//     their attempts are fruitless.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The scroll inscription gates.
// -----------------------------------------------------------------------
inline int scrollMinInscribeLevel() {
    // clerics, druids, magic-users and
    // illusionists of 7th or higher level
    return 7;
}

inline int inscriberClassCount() {
    // cleric, druid, magic-user, illusionist
    return 4;
}

inline int spellMustBeEmployable() {
    // the spell must be of a level the
    // inscriber is able to employ
    return 1;
}

enum ProtectionScrollKind {
    PS_DEVILS = 0,
    PS_POSSESSION,
    PS_UNDEAD,
    PS_DEMONS,
    PS_ELEMENTALS,
    PS_LYCANTHROPES,
    PS_MAGIC,
    PS_PETRIFICATION,
    PS_COUNT
};

inline int protectionClericalCount() {
    // devils, possession, undead
    return 3;
}

inline int protectionMuCount() {
    // demons, elementals, lycanthropes,
    // magic, petrification
    return 5;
}

inline int curseScrollsAnySpellUser() {
    // curse scrolls can be made by any
    // sort of spell user
    return 1;
}

inline int protectionScrollIsClerical(int kind) {
    // 1 when the kind belongs on a clerical
    // protection scroll, 0 when magic-user
    if (kind < 0) kind = 0;
    if (kind > 7) kind = 7;
    return (kind <= 2) ? 1 : 0;
}

// -----------------------------------------------------------------------
// The scroll materials.
// -----------------------------------------------------------------------
enum ScrollMaterial {
    SCM_PAPYRUS = 0,
    SCM_PARCHMENT,
    SCM_VELLUM,
    SCM_COUNT
};

inline int scrollSheetCostMin(int material) {
    // papyrus 2 gp and up, parchment 4 gp
    // and up, vellum 8 gp and up
    if (material < 0) material = 0;
    if (material > 2) material = 2;
    static const int t[3] = {
        2, 4, 8,
    };
    return t[material];
}

inline int scrollMaterialFailMod(int material) {
    // papyrus +5, parchment +/-0, vellum -5
    if (material < 0) material = 0;
    if (material > 2) material = 2;
    static const int t[3] = {
        5, 0, -5,
    };
    return t[material];
}

inline int quillPerSpell() {
    // a fresh, virgin quill for each spell
    return 1;
}

inline int quillNamedCreatures() {
    // griffon, harpy, hippogriff, pegasus,
    // roc, sphinx (DM additions aside)
    return 6;
}

inline int inkBaseCount() {
    // giant squid sepia, giant octopus ink
    return 2;
}

inline int inkPerSpellDistinct() {
    // each different spell requires a
    // different ink compound
    return 1;
}

// -----------------------------------------------------------------------
// The preparation and failure rules.
// -----------------------------------------------------------------------
inline int scrollPrepDays(int spellLevel) {
    // one full day per level of the spell
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

inline int prepMustBeContinuous() {
    // leaving the scroll breaks the magic
    return 1;
}

inline int scrollFailurePct(int spellLevel, int charLevel,
                            int material) {
    // 20 base + 1 per spell level - the
    // character level + the material
    // modifier. The print example: 14th
    // level cleric, 7th level spell,
    // parchment = 13 percent. The print
    // sets no floor.
    if (spellLevel < 1) spellLevel = 1;
    return 20 + spellLevel - charLevel
        + scrollMaterialFailMod(material);
}

inline int scrollSuccessRollIsGreaterThan() {
    // a percentile roll GREATER than the
    // failure chance equals success
    return 1;
}

inline int scrollMaxSpells() {
    // a maximum of seven spells per scroll
    return 7;
}

inline int oneFailureBlocksFurther() {
    // one failure means no further spells
    // may be placed on the scroll
    return 1;
}

// -----------------------------------------------------------------------
// Transcribing an unknown spell from a
// scroll.
// -----------------------------------------------------------------------
inline int transcribeNeedsReadMagic() {
    // a MU or illusionist needs read magic
    // first
    return 1;
}

inline int transcribeDays(int spellLevel) {
    // a period equal to placing the spell
    // on a scroll
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

inline int transcribeEraseFromScroll() {
    // the spell disappears from the scroll
    return 1;
}

inline int ownScrollsNeedNoReadMagic() {
    // the scriber never needs read magic for
    // his or her own scrolls; clerics and
    // druids never need it
    return 1;
}

// -----------------------------------------------------------------------
// The fabrication of other magic items.
// -----------------------------------------------------------------------
inline int fabricateNeedsEnchantAnItem() {
    // all other magic items require enchant
    // an item - save clerical items
    return 1;
}

inline int fabricateClericalUsesEnchant() {
    // the clerical exemption
    return 0;
}

inline int fabRestDays(int xpValue) {
    // one day of complete rest per 100 gp
    // of the item XP value; 2000 xp = 20
    // days. Each 100 gp or fraction thereof
    // is one day (the potion-day rounding).
    if (xpValue < 0) xpValue = 0;
    return (xpValue + 99) / 100;
}

inline int fabRestNoAdventuringOrSpells() {
    // no adventuring or spell use during the
    // rest, all in relative isolation
    return 1;
}

inline int permanentDweomerNeedsPermanency() {
    // weapons, armor, most rings and
    // miscellaneous items: permanency
    return 1;
}

inline int chargedItemsNeedPermanency() {
    // wands and other chargeable items wear
    // out instead
    return 0;
}

// -----------------------------------------------------------------------
// The cleric and druid fabrication retreat.
// -----------------------------------------------------------------------
inline int clericRetreatDays() {
    // a fortnight in complete isolation
    return 14;
}

inline int clericFastDays() {
    // a sennight fasting
    return 7;
}

inline int clericPurifyDays() {
    // prayer and purification takes a day
    return 1;
}

inline int clericEmpowerPctPerDay() {
    // a cumulative 1 percent per day chance
    // the deity empowers the item
    return 1;
}

inline int clericChargedSpellWindowHours() {
    // the requisite spells must be cast
    // within 24 hours of the favor
    return 24;
}

// -----------------------------------------------------------------------
// The illusionist fabrication gates.
// -----------------------------------------------------------------------
inline int illusionistScrollLevel() {
    // scrolls at 7th level and up
    return 7;
}

inline int illusionistOneShotChargedLevel() {
    // one-shot and charged items at 11th
    return 11;
}

inline int illusionistPermanentDweomerLevel() {
    // items with a truly permanent dweomer
    // at 14th
    return 14;
}

inline int illusionistMajorCreationInstillHours() {
    // the uninterrupted instilling window
    // after major creation
    return 16;
}

inline int illusionistPermanentGemCost() {
    // an unflawed gem worth not less than
    // 10000 gp
    return 10000;
}

// -----------------------------------------------------------------------
// The charmed or enslaved magic-user rule.
// -----------------------------------------------------------------------
inline int enslavedMakerCanFabricate() {
    // totally unable to fabricate any sort
    // of magic item - scroll, potion or
    // otherwise; the attempts are fruitless
    return 0;
}

}  // namespace rules
