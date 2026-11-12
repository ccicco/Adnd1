// ====================================================================
// Adnd1 - rules/dmg/scroll_manufacture.h
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



// -----------------------------------------------------------------------
// The scroll materials.
// -----------------------------------------------------------------------
enum ScrollMaterial {
    SCM_PAPYRUS = 0,
    SCM_PARCHMENT,
    SCM_VELLUM,
    SCM_COUNT
};

// R-refactor: namespace rules -> class Scroll_manufacture (instance methods)
class Scroll_manufacture {
public:


// -----------------------------------------------------------------------
// The scroll inscription gates.
// -----------------------------------------------------------------------
    int scrollMinInscribeLevel();
    int inscriberClassCount();
    int spellMustBeEmployable();
    int protectionClericalCount();
    int protectionMuCount();
    int curseScrollsAnySpellUser();
    int protectionScrollIsClerical(int kind);
    int scrollSheetCostMin(int material);
    int scrollMaterialFailMod(int material);
    int quillPerSpell();
    int quillNamedCreatures();
    int inkBaseCount();
    int inkPerSpellDistinct();


// -----------------------------------------------------------------------
// The preparation and failure rules.
// -----------------------------------------------------------------------
    int scrollPrepDays(int spellLevel);
    int prepMustBeContinuous();
    int scrollFailurePct(int spellLevel, int charLevel, int material);
    int scrollSuccessRollIsGreaterThan();
    int scrollMaxSpells();
    int oneFailureBlocksFurther();


// -----------------------------------------------------------------------
// Transcribing an unknown spell from a
// scroll.
// -----------------------------------------------------------------------
    int transcribeNeedsReadMagic();
    int transcribeDays(int spellLevel);
    int transcribeEraseFromScroll();
    int ownScrollsNeedNoReadMagic();


// -----------------------------------------------------------------------
// The fabrication of other magic items.
// -----------------------------------------------------------------------
    int fabricateNeedsEnchantAnItem();
    int fabricateClericalUsesEnchant();
    int fabRestDays(int xpValue);
    int fabRestNoAdventuringOrSpells();
    int permanentDweomerNeedsPermanency();
    int chargedItemsNeedPermanency();


// -----------------------------------------------------------------------
// The cleric and druid fabrication retreat.
// -----------------------------------------------------------------------
    int clericRetreatDays();
    int clericFastDays();
    int clericPurifyDays();
    int clericEmpowerPctPerDay();
    int clericChargedSpellWindowHours();


// -----------------------------------------------------------------------
// The illusionist fabrication gates.
// -----------------------------------------------------------------------
    int illusionistScrollLevel();
    int illusionistOneShotChargedLevel();
    int illusionistPermanentDweomerLevel();
    int illusionistMajorCreationInstillHours();
    int illusionistPermanentGemCost();


// -----------------------------------------------------------------------
// The charmed or enslaved magic-user rule.
// -----------------------------------------------------------------------
    int enslavedMakerCanFabricate();
};
