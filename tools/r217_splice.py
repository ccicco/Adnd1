#!/usr/bin/env python3
# R217 splice: the scroll manufacture and
# fabrication pins - DMG pp.118-121, the
# MANUFACTURE OF SCROLLS and FABRICATION
# seams: who may inscribe (clerics,
# druids, magic-users, illusionists of
# 7th or higher level, spells the
# inscriber can employ), the protection
# scroll split (clerical devils/
# possession/undead, magic-user demons/
# elementals/lycanthropes/magic/
# petrification; curse scrolls by any
# spell user), the materials (papyrus 2
# gp and up +5 percent failure, parchment
# 4 gp and up +/-0, vellum 8 gp and up -5
# percent; a fresh virgin quill per spell
# from a strange or magical creature -
# the 6 named: griffon, harpy, hippogriff,
# pegasus, roc, sphinx; ink compounded by
# the inscriber from giant squid sepia or
# giant octopus ink, a different ink per
# spell), preparation (one full day per
# spell level, continuous - leaving breaks
# the magic), the failure chance (20
# percent base + 1 percent per spell level
# - the character level + the material
# modifier; the print example: a 14th
# level cleric, 7th level spell on
# parchment = 13 percent), multiple spells
# (a failure blocks further spells, a
# maximum of 7 spells per scroll),
# transcribing an unknown spell off a
# scroll (read magic + the same time as
# scribing; the spell then disappears),
# the fabrication of other magic items
# (enchant an item - save clerical items;
# rest one day per 100 gp of the item XP
# value - 2000 xp = 20 days, no
# adventuring or spell use; permanency
# for permanent dweomers but not
# chargeable items), the cleric/druid
# retreat (a fortnight in retreat, a
# sennight fasting, a day of purification,
# a cumulative 1 percent per day
# empowerment chance, 24 hours to cast the
# requisite spells into a charged item),
# the illusionist gates (scrolls 7th,
# one-shot and charged items 11th - major
# creation with a 16-hour uninterrupted
# instilling window, permanent dweomers
# 14th with alter reality and an
# unflawed gem worth not less than 10000
# gp), and the charmed or enslaved
# magic-user rule (totally unable to
# fabricate any magic item). Patches: 4
# (new rules/scrollfab.h, regtest include,
# audit block, gap-report log entry).
# Census 132 -> 133.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique;
    # old = None means the new-file form
    global applied, already
    try:
        t = rd(path)
    except IOError:
        # the file does not exist: create it
        assert old is None, 'anchor patch on absent file: ' + marker
        assert marker in new, 'marker missing in new file: ' + marker
        wr(path, new)
        applied += 1
        return
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/scrollfab.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
'// ====================================================================',
'// Adnd1 - rules/scrollfab.h',
'// R217: the scroll manufacture and',
'// fabrication pins (DMG pp.118-121) -',
'// the scroll inscription rules and',
'// failure chance, and the fabrication',
'// of other magic items.',
'//',
'// Pure data + helpers, header-only (the',
'// grenade.h pattern: the caller owns the',
'// dice, the ink recipes and the actual',
'// scribing; the gates and the numeric',
'// conventions read here).',
'//',
'// Conventions and judgments, named in',
'// place:',
'//   - Inscribers: clerics, druids,',
'//     magic-users and illusionists of 7th',
'//     or higher level may inscribe',
'//     scrolls; the spell must be one the',
'//     inscriber is able to employ. The',
'//     write spell enables reference works',
'//     only - not scroll inscription.',
'//   - Protection scroll split: clerical',
'//     protection scrolls cover devils,',
'//     possession and undead; magic-user',
'//     protection scrolls cover demons,',
'//     elementals, lycanthropes, magic and',
'//     petrification. Curse scrolls can',
'//     be made by any spell user.',
'//   - Materials: papyrus 2 gp and up per',
'//     sheet with +5 percent failure;',
'//     parchment 4 gp and up at +/-0;',
'//     vellum 8 gp and up at -5 percent -',
'//     the most desirable. A fresh, virgin',
'//     quill must be used for each spell',
'//     transcribed, from a creature of',
'//     strange or magical nature (the six',
'//     named: griffon, harpy, hippogriff,',
'//     pegasus, roc, sphinx; demons,',
'//     devils, lammasu and similar at DM',
'//     election). Ink is compounded only',
'//     by the inscriber from giant squid',
'//     sepia or giant octopus ink as the',
'//     base medium; each different spell',
'//     requires a different ink.',
'//   - Preparation: one full day per level',
'//     of the spell being scribed,',
'//     continuous - rest, food and sleep',
'//     only. Leaving the scroll breaks the',
'//     magic and the effort is for naught.',
'//   - Failure chance: 20 percent base +',
'//     1 percent per spell level - the',
'//     character level + the material',
'//     modifier. The print example: a 14th',
'//     level cleric scribing a 7th level',
'//     spell on parchment fails at 13',
'//     percent. A percentile roll greater',
'//     than the chance equals success; the',
'//     print sets no floor.',
'//   - Multiple spells: a failure of one',
'//     spell means no further spells may',
'//     be placed on the scroll; a maximum',
'//     of 7 spells per scroll.',
'//   - Transcribing an unknown spell from',
'//     a scroll to books: read magic, then',
'//     a period equal to scribing the',
'//     spell onto a scroll; the spell then',
'//     disappears from the scroll. The',
'//     scriber never needs read magic for',
'//     his or her own scroll spells;',
'//     clerics and druids never need it.',
'//   - Fabrication of other magic items:',
'//     all require enchant an item (save',
'//     clerical items). A permanent dweomer',
'//     requires a permanency spell;',
'//     chargeable items do not. After',
'//     manufacture the maker must rest one',
'//     day per 100 gp of the item XP value',
'//     (2000 xp = 20 days) in relative',
'//     isolation - no adventuring or spell',
'//     use.',
'//   - Cleric/druid fabrication: a fortnight',
'//     in retreat meditating in complete',
'//     isolation, then a sennight fasting,',
'//     then a day of prayer and',
'//     purification; then a cumulative 1',
'//     percent per day chance the deity',
'//     empowers the item. A charged item',
'//     must receive its spells within 24',
'//     hours of the favor; other items',
'//     need only sanctification.',
'//   - Illusionist fabrication: scrolls at',
'//     7th level; one-shot and charged',
'//     items (no permanent dweomer) at',
'//     11th - major creation prepares the',
'//     item, then a 16-hour uninterrupted',
'//     instilling window; permanent dweomers',
'//     at 14th - major creation plus alter',
'//     reality, with an unflawed gem worth',
'//     not less than 10000 gp.',
'//   - Charmed, magically persuaded or',
'//     enslaved magic-users are totally',
'//     unable to fabricate any magic item;',
'//     their attempts are fruitless.',
'// ====================================================================',
'',
'#pragma once',
'',
'namespace rules {',
'',
'// -----------------------------------------------------------------------',
'// The scroll inscription gates.',
'// -----------------------------------------------------------------------',
'inline int scrollMinInscribeLevel() {',
'    // clerics, druids, magic-users and',
'    // illusionists of 7th or higher level',
'    return 7;',
'}',
'',
'inline int inscriberClassCount() {',
'    // cleric, druid, magic-user, illusionist',
'    return 4;',
'}',
'',
'inline int spellMustBeEmployable() {',
'    // the spell must be of a level the',
'    // inscriber is able to employ',
'    return 1;',
'}',
'',
'enum ProtectionScrollKind {',
'    PS_DEVILS = 0,',
'    PS_POSSESSION,',
'    PS_UNDEAD,',
'    PS_DEMONS,',
'    PS_ELEMENTALS,',
'    PS_LYCANTHROPES,',
'    PS_MAGIC,',
'    PS_PETRIFICATION,',
'    PS_COUNT',
'};',
'',
'inline int protectionClericalCount() {',
'    // devils, possession, undead',
'    return 3;',
'}',
'',
'inline int protectionMuCount() {',
'    // demons, elementals, lycanthropes,',
'    // magic, petrification',
'    return 5;',
'}',
'',
'inline int curseScrollsAnySpellUser() {',
'    // curse scrolls can be made by any',
'    // sort of spell user',
'    return 1;',
'}',
'',
'inline int protectionScrollIsClerical(int kind) {',
'    // 1 when the kind belongs on a clerical',
'    // protection scroll, 0 when magic-user',
'    if (kind < 0) kind = 0;',
'    if (kind > 7) kind = 7;',
'    return (kind <= 2) ? 1 : 0;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The scroll materials.',
'// -----------------------------------------------------------------------',
'enum ScrollMaterial {',
'    SCM_PAPYRUS = 0,',
'    SCM_PARCHMENT,',
'    SCM_VELLUM,',
'    SCM_COUNT',
'};',
'',
'inline int scrollSheetCostMin(int material) {',
'    // papyrus 2 gp and up, parchment 4 gp',
'    // and up, vellum 8 gp and up',
'    if (material < 0) material = 0;',
'    if (material > 2) material = 2;',
'    static const int t[3] = {',
'        2, 4, 8,',
'    };',
'    return t[material];',
'}',
'',
'inline int scrollMaterialFailMod(int material) {',
'    // papyrus +5, parchment +/-0, vellum -5',
'    if (material < 0) material = 0;',
'    if (material > 2) material = 2;',
'    static const int t[3] = {',
'        5, 0, -5,',
'    };',
'    return t[material];',
'}',
'',
'inline int quillPerSpell() {',
'    // a fresh, virgin quill for each spell',
'    return 1;',
'}',
'',
'inline int quillNamedCreatures() {',
'    // griffon, harpy, hippogriff, pegasus,',
'    // roc, sphinx (DM additions aside)',
'    return 6;',
'}',
'',
'inline int inkBaseCount() {',
'    // giant squid sepia, giant octopus ink',
'    return 2;',
'}',
'',
'inline int inkPerSpellDistinct() {',
'    // each different spell requires a',
'    // different ink compound',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The preparation and failure rules.',
'// -----------------------------------------------------------------------',
'inline int scrollPrepDays(int spellLevel) {',
'    // one full day per level of the spell',
'    if (spellLevel < 1) spellLevel = 1;',
'    return spellLevel;',
'}',
'',
'inline int prepMustBeContinuous() {',
'    // leaving the scroll breaks the magic',
'    return 1;',
'}',
'',
'inline int scrollFailurePct(int spellLevel, int charLevel,',
'                            int material) {',
'    // 20 base + 1 per spell level - the',
'    // character level + the material',
'    // modifier. The print example: 14th',
'    // level cleric, 7th level spell,',
'    // parchment = 13 percent. The print',
'    // sets no floor.',
'    if (spellLevel < 1) spellLevel = 1;',
'    return 20 + spellLevel - charLevel',
'        + scrollMaterialFailMod(material);',
'}',
'',
'inline int scrollSuccessRollIsGreaterThan() {',
'    // a percentile roll GREATER than the',
'    // failure chance equals success',
'    return 1;',
'}',
'',
'inline int scrollMaxSpells() {',
'    // a maximum of seven spells per scroll',
'    return 7;',
'}',
'',
'inline int oneFailureBlocksFurther() {',
'    // one failure means no further spells',
'    // may be placed on the scroll',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// Transcribing an unknown spell from a',
'// scroll.',
'// -----------------------------------------------------------------------',
'inline int transcribeNeedsReadMagic() {',
'    // a MU or illusionist needs read magic',
'    // first',
'    return 1;',
'}',
'',
'inline int transcribeDays(int spellLevel) {',
'    // a period equal to placing the spell',
'    // on a scroll',
'    if (spellLevel < 1) spellLevel = 1;',
'    return spellLevel;',
'}',
'',
'inline int transcribeEraseFromScroll() {',
'    // the spell disappears from the scroll',
'    return 1;',
'}',
'',
'inline int ownScrollsNeedNoReadMagic() {',
'    // the scriber never needs read magic for',
'    // his or her own scrolls; clerics and',
'    // druids never need it',
'    return 1;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The fabrication of other magic items.',
'// -----------------------------------------------------------------------',
'inline int fabricateNeedsEnchantAnItem() {',
'    // all other magic items require enchant',
'    // an item - save clerical items',
'    return 1;',
'}',
'',
'inline int fabricateClericalUsesEnchant() {',
'    // the clerical exemption',
'    return 0;',
'}',
'',
'inline int fabRestDays(int xpValue) {',
'    // one day of complete rest per 100 gp',
'    // of the item XP value; 2000 xp = 20',
'    // days. Each 100 gp or fraction thereof',
'    // is one day (the potion-day rounding).',
'    if (xpValue < 0) xpValue = 0;',
'    return (xpValue + 99) / 100;',
'}',
'',
'inline int fabRestNoAdventuringOrSpells() {',
'    // no adventuring or spell use during the',
'    // rest, all in relative isolation',
'    return 1;',
'}',
'',
'inline int permanentDweomerNeedsPermanency() {',
'    // weapons, armor, most rings and',
'    // miscellaneous items: permanency',
'    return 1;',
'}',
'',
'inline int chargedItemsNeedPermanency() {',
'    // wands and other chargeable items wear',
'    // out instead',
'    return 0;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The cleric and druid fabrication retreat.',
'// -----------------------------------------------------------------------',
'inline int clericRetreatDays() {',
'    // a fortnight in complete isolation',
'    return 14;',
'}',
'',
'inline int clericFastDays() {',
'    // a sennight fasting',
'    return 7;',
'}',
'',
'inline int clericPurifyDays() {',
'    // prayer and purification takes a day',
'    return 1;',
'}',
'',
'inline int clericEmpowerPctPerDay() {',
'    // a cumulative 1 percent per day chance',
'    // the deity empowers the item',
'    return 1;',
'}',
'',
'inline int clericChargedSpellWindowHours() {',
'    // the requisite spells must be cast',
'    // within 24 hours of the favor',
'    return 24;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The illusionist fabrication gates.',
'// -----------------------------------------------------------------------',
'inline int illusionistScrollLevel() {',
'    // scrolls at 7th level and up',
'    return 7;',
'}',
'',
'inline int illusionistOneShotChargedLevel() {',
'    // one-shot and charged items at 11th',
'    return 11;',
'}',
'',
'inline int illusionistPermanentDweomerLevel() {',
'    // items with a truly permanent dweomer',
'    // at 14th',
'    return 14;',
'}',
'',
'inline int illusionistMajorCreationInstillHours() {',
'    // the uninterrupted instilling window',
'    // after major creation',
'    return 16;',
'}',
'',
'inline int illusionistPermanentGemCost() {',
'    // an unflawed gem worth not less than',
'    // 10000 gp',
'    return 10000;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The charmed or enslaved magic-user rule.',
'// -----------------------------------------------------------------------',
'inline int enslavedMakerCanFabricate() {',
'    // totally unable to fabricate any sort',
'    // of magic item - scroll, potion or',
'    // otherwise; the attempts are fruitless',
'    return 0;',
'}',
'',
'}  // namespace rules',
]
hdr = NL.join(hdr_lines) + NL

patch('rules/scrollfab.h',
      'R217: the scroll manufacture and',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/magres.h"  // R216: pp.114-119 magical research pins'

new2 = ('#include "rules/magres.h"  // R216: pp.114-119 magical research pins'
        + NL + '#include "rules/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins')

patch('regtest.cpp',
      'R217: pp.118-121 scroll manufacture and fabrication pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R217 audit block
# ---------------------------------------------------------------------------

audit_lines = [
'    // ---- R217: the scroll manufacture and fabrication pins audit ----',
'    // DMG pp.118-121: the scroll inscription',
'    // rules and failure chance, and the',
'    // fabrication of other magic items.',
'    {',
'        int bad = 0;',
'        // the inscription gates',
'        if (rules::scrollMinInscribeLevel() != 7 ||',
'            rules::inscriberClassCount() != 4 ||',
'            rules::spellMustBeEmployable() != 1) ++bad;',
'        // the protection scroll split',
'        if (rules::PS_COUNT != 8 ||',
'            rules::PS_UNDEAD != 2 ||',
'            rules::PS_DEMONS != 3 ||',
'            rules::PS_PETRIFICATION != 7) ++bad;',
'        if (rules::protectionClericalCount() != 3 ||',
'            rules::protectionMuCount() != 5 ||',
'            rules::curseScrollsAnySpellUser() != 1) ++bad;',
'        for (int k = -1; k < 9; ++k)',
'            if (rules::protectionScrollIsClerical(k)',
'                    != ((k > 2) ? 0 : 1)) ++bad;',
'        // the materials',
'        if (rules::SCM_COUNT != 3) ++bad;',
'        static const int kMatCost[3] = { 2, 4, 8 };',
'        static const int kMatMod[3] = { 5, 0, -5 };',
'        for (int m = 0; m < 3; ++m)',
'            if (rules::scrollSheetCostMin(m) != kMatCost[m] ||',
'                rules::scrollMaterialFailMod(m) != kMatMod[m]) ++bad;',
'        if (rules::scrollSheetCostMin(-2) != 2 ||',
'            rules::scrollSheetCostMin(9) != 8) ++bad;',
'        if (rules::quillPerSpell() != 1 ||',
'            rules::quillNamedCreatures() != 6 ||',
'            rules::inkBaseCount() != 2 ||',
'            rules::inkPerSpellDistinct() != 1) ++bad;',
'        // the preparation and failure rules',
'        if (rules::scrollPrepDays(1) != 1 ||',
'            rules::scrollPrepDays(2) != 2 ||',
'            rules::scrollPrepDays(7) != 7 ||',
'            rules::prepMustBeContinuous() != 1) ++bad;',
'        if (rules::scrollFailurePct(7, 14, 1) != 13 ||',
'            rules::scrollFailurePct(1, 1, 1) != 20 ||',
'            rules::scrollFailurePct(1, 7, 1) != 14 ||',
'            rules::scrollFailurePct(9, 7, 1) != 22 ||',
'            rules::scrollFailurePct(1, 7, 0) != 19 ||',
'            rules::scrollFailurePct(1, 7, 2) != 9) ++bad;',
'        if (rules::scrollSuccessRollIsGreaterThan() != 1 ||',
'            rules::scrollMaxSpells() != 7 ||',
'            rules::oneFailureBlocksFurther() != 1) ++bad;',
'        // transcribing an unknown spell',
'        if (rules::transcribeNeedsReadMagic() != 1 ||',
'            rules::transcribeDays(4) != 4 ||',
'            rules::transcribeEraseFromScroll() != 1 ||',
'            rules::ownScrollsNeedNoReadMagic() != 1) ++bad;',
'        // the fabrication of other magic items',
'        if (rules::fabricateNeedsEnchantAnItem() != 1 ||',
'            rules::fabricateClericalUsesEnchant() != 0) ++bad;',
'        if (rules::fabRestDays(2000) != 20 ||',
'            rules::fabRestDays(100) != 1 ||',
'            rules::fabRestDays(101) != 2 ||',
'            rules::fabRestDays(250) != 3 ||',
'            rules::fabRestDays(-5) != 0 ||',
'            rules::fabRestNoAdventuringOrSpells() != 1) ++bad;',
'        if (rules::permanentDweomerNeedsPermanency() != 1 ||',
'            rules::chargedItemsNeedPermanency() != 0) ++bad;',
'        // the cleric and druid retreat',
'        if (rules::clericRetreatDays() != 14 ||',
'            rules::clericFastDays() != 7 ||',
'            rules::clericPurifyDays() != 1 ||',
'            rules::clericEmpowerPctPerDay() != 1 ||',
'            rules::clericChargedSpellWindowHours() != 24) ++bad;',
'        // the illusionist gates',
'        if (rules::illusionistScrollLevel() != 7 ||',
'            rules::illusionistOneShotChargedLevel() != 11 ||',
'            rules::illusionistPermanentDweomerLevel() != 14 ||',
'            rules::illusionistMajorCreationInstillHours() != 16 ||',
'            rules::illusionistPermanentGemCost() != 10000) ++bad;',
'        // the charmed or enslaved maker rule',
'        if (rules::enslavedMakerCanFabricate() != 0) ++bad;',
'        printf("R217 scroll manufacture and fabrication pins audit: bad %d' + BS + 'n", bad);',
'        if (bad) return 1;',
'    }',
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R217: the scroll manufacture and fabrication pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
'R217 landed the scroll manufacture and',
'fabrication pins (DMG pp.118-121) - the',
'MANUFACTURE OF SCROLLS seam and the',
'FABRICATION material that follows it.',
'rules/scrollfab.h (the grenade.h pattern):',
'the inscription gates (cleric, druid,',
'magic-user, illusionist at 7th or higher,',
'the spell one the inscriber can employ;',
'the protection scroll split - clerical',
'devils/possession/undead vs magic-user',
'demons/elementals/lycanthropes/magic/',
'petrification, curse scrolls by any spell',
'user), the materials (papyrus 2 gp and up',
'+5 percent, parchment 4 gp and up +/-0,',
'vellum 8 gp and up -5 percent, a fresh',
'virgin quill per spell from a strange or',
'magical creature - the 6 named quill',
'beasts, ink from giant squid sepia or',
'giant octopus ink with a different ink',
'per spell), the preparation (one full day',
'per spell level, continuous - leaving',
'breaks the magic), the failure chance (20',
'percent + 1 per spell level - the',
'character level + the material modifier;',
'the print example: 14th level cleric, 7th',
'level spell, parchment = 13 percent; a',
'percentile roll over the chance is a',
'success, the print sets no floor),',
'multiple spells (a failure blocks further',
'spells, 7 spells maximum per scroll),',
'transcription off a scroll (read magic',
'plus the same time as scribing, the spell',
'then disappears), the fabrication of',
'other items (enchant an item - save',
'clerical items; rest one day per 100 gp',
'of XP value - 2000 xp = 20 days, no',
'adventuring or spell use; permanency for',
'permanent dweomers but not chargeable',
'items), the cleric and druid retreat (a',
'fortnight in retreat, a sennight fasting,',
'a day of purification, a cumulative 1',
'percent per day empowerment, 24 hours to',
'charge), the illusionist gates (scrolls',
'7th, one-shot and charged items 11th with',
'major creation and the 16-hour instilling',
'window, permanent dweomers 14th with',
'alter reality and the unflawed 10000 gp',
'gem), and the charmed or enslaved',
'magic-user rule (totally unable to',
'fabricate any magic item, the attempts',
'fruitless). The non-standard items and',
'command words seams remain; the upload is',
'the sole source at this seam. New R217',
'battery audit; census 133. Next: the USE',
'OF MAGIC ITEMS seam - command words,',
'crystal balls and scrying, drinking',
'potions and applying oils, and the potion',
'miscibility tables (upload lines ~9320+,',
'pp.121+).',
]
log_entry = NL.join(log_lines)

old4 = ('lines ~9100+, pp.119+).' + NL + NL + 'Categories:')

new4 = ('lines ~9100+, pp.119+).' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R217 landed the scroll manufacture',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R217 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R217 note: 4 patches; the scroll manufacture and fabrication pins')
print('landed - the inscription gates, the failure chance, the retreat')
print('and illusionist gates; census 133.')
print('commit: R217: the scroll manufacture and fabrication pins pinned - DMG')
print('pp.118-121, scroll inscription, failure chance, magic item fabrication (census 133)')

