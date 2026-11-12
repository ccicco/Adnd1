// R-refactor: split from scroll_manufacture.h - definitions
#include "rules/dmg/scroll_manufacture.h"

int Scroll_manufacture::scrollMinInscribeLevel() {
    // clerics, druids, magic-users and
    // illusionists of 7th or higher level
    return 7;
}

int Scroll_manufacture::inscriberClassCount() {
    // cleric, druid, magic-user, illusionist
    return 4;
}

int Scroll_manufacture::spellMustBeEmployable() {
    // the spell must be of a level the
    // inscriber is able to employ
    return 1;
}

int Scroll_manufacture::protectionClericalCount() {
    // devils, possession, undead
    return 3;
}

int Scroll_manufacture::protectionMuCount() {
    // demons, elementals, lycanthropes,
    // magic, petrification
    return 5;
}

int Scroll_manufacture::curseScrollsAnySpellUser() {
    // curse scrolls can be made by any
    // sort of spell user
    return 1;
}

int Scroll_manufacture::protectionScrollIsClerical(int kind) {
    // 1 when the kind belongs on a clerical
    // protection scroll, 0 when magic-user
    if (kind < 0) kind = 0;
    if (kind > 7) kind = 7;
    return (kind <= 2) ? 1 : 0;
}

int Scroll_manufacture::scrollSheetCostMin(int material) {
    // papyrus 2 gp and up, parchment 4 gp
    // and up, vellum 8 gp and up
    if (material < 0) material = 0;
    if (material > 2) material = 2;
    static const int t[3] = {
        2, 4, 8,
    };
    return t[material];
}

int Scroll_manufacture::scrollMaterialFailMod(int material) {
    // papyrus +5, parchment +/-0, vellum -5
    if (material < 0) material = 0;
    if (material > 2) material = 2;
    static const int t[3] = {
        5, 0, -5,
    };
    return t[material];
}

int Scroll_manufacture::quillPerSpell() {
    // a fresh, virgin quill for each spell
    return 1;
}

int Scroll_manufacture::quillNamedCreatures() {
    // griffon, harpy, hippogriff, pegasus,
    // roc, sphinx (DM additions aside)
    return 6;
}

int Scroll_manufacture::inkBaseCount() {
    // giant squid sepia, giant octopus ink
    return 2;
}

int Scroll_manufacture::inkPerSpellDistinct() {
    // each different spell requires a
    // different ink compound
    return 1;
}

int Scroll_manufacture::scrollPrepDays(int spellLevel) {
    // one full day per level of the spell
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

int Scroll_manufacture::prepMustBeContinuous() {
    // leaving the scroll breaks the magic
    return 1;
}

int Scroll_manufacture::scrollFailurePct(int spellLevel, int charLevel, int material) {
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

int Scroll_manufacture::scrollSuccessRollIsGreaterThan() {
    // a percentile roll GREATER than the
    // failure chance equals success
    return 1;
}

int Scroll_manufacture::scrollMaxSpells() {
    // a maximum of seven spells per scroll
    return 7;
}

int Scroll_manufacture::oneFailureBlocksFurther() {
    // one failure means no further spells
    // may be placed on the scroll
    return 1;
}

int Scroll_manufacture::transcribeNeedsReadMagic() {
    // a MU or illusionist needs read magic
    // first
    return 1;
}

int Scroll_manufacture::transcribeDays(int spellLevel) {
    // a period equal to placing the spell
    // on a scroll
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

int Scroll_manufacture::transcribeEraseFromScroll() {
    // the spell disappears from the scroll
    return 1;
}

int Scroll_manufacture::ownScrollsNeedNoReadMagic() {
    // the scriber never needs read magic for
    // his or her own scrolls; clerics and
    // druids never need it
    return 1;
}

int Scroll_manufacture::fabricateNeedsEnchantAnItem() {
    // all other magic items require enchant
    // an item - save clerical items
    return 1;
}

int Scroll_manufacture::fabricateClericalUsesEnchant() {
    // the clerical exemption
    return 0;
}

int Scroll_manufacture::fabRestDays(int xpValue) {
    // one day of complete rest per 100 gp
    // of the item XP value; 2000 xp = 20
    // days. Each 100 gp or fraction thereof
    // is one day (the potion-day rounding).
    if (xpValue < 0) xpValue = 0;
    return (xpValue + 99) / 100;
}

int Scroll_manufacture::fabRestNoAdventuringOrSpells() {
    // no adventuring or spell use during the
    // rest, all in relative isolation
    return 1;
}

int Scroll_manufacture::permanentDweomerNeedsPermanency() {
    // weapons, armor, most rings and
    // miscellaneous items: permanency
    return 1;
}

int Scroll_manufacture::chargedItemsNeedPermanency() {
    // wands and other chargeable items wear
    // out instead
    return 0;
}

int Scroll_manufacture::clericRetreatDays() {
    // a fortnight in complete isolation
    return 14;
}

int Scroll_manufacture::clericFastDays() {
    // a sennight fasting
    return 7;
}

int Scroll_manufacture::clericPurifyDays() {
    // prayer and purification takes a day
    return 1;
}

int Scroll_manufacture::clericEmpowerPctPerDay() {
    // a cumulative 1 percent per day chance
    // the deity empowers the item
    return 1;
}

int Scroll_manufacture::clericChargedSpellWindowHours() {
    // the requisite spells must be cast
    // within 24 hours of the favor
    return 24;
}

int Scroll_manufacture::illusionistScrollLevel() {
    // scrolls at 7th level and up
    return 7;
}

int Scroll_manufacture::illusionistOneShotChargedLevel() {
    // one-shot and charged items at 11th
    return 11;
}

int Scroll_manufacture::illusionistPermanentDweomerLevel() {
    // items with a truly permanent dweomer
    // at 14th
    return 14;
}

int Scroll_manufacture::illusionistMajorCreationInstillHours() {
    // the uninterrupted instilling window
    // after major creation
    return 16;
}

int Scroll_manufacture::illusionistPermanentGemCost() {
    // an unflawed gem worth not less than
    // 10000 gp
    return 10000;
}

int Scroll_manufacture::enslavedMakerCanFabricate() {
    // totally unable to fabricate any sort
    // of magic item - scroll, potion or
    // otherwise; the attempts are fruitless
    return 0;
}
