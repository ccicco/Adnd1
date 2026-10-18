// =========================================================================================
// Adnd1 - rules/dmoitems.h
// CREATING MAGICAL ITEMS - DMO Chapter 4 closes: the holy water ceremony (the
// five-spell chain with the two reversed unholy forms, the eight-hour
// meditations, the chant turn, the -4 combat window, the one-font-one-week
// rule, the nine-row cost ladder with the Delsenora recycle read at 30
// percent of 21,000 gp), the requirements doctrine (the wizard 9-and-11 and
// priest 7-9-11 thresholds, the specialist +5, the 5,000-gp laboratory with
// its 500-a-month upkeep, the 2,000-gp altar with its one-week vigil), the
// Table 23 grid (28 item rows of material, process, footnote, cost and time
// codes), the per-type success formulas (the 70/80/60 bases, the 1d3+1-week
// potion research at 100 gp a week, the 1d6+1-week ring research at 200 gp a
// week, the ink ladder, the scroll and ring reads, the drained-item death
// rule), the 24-hour recharge window with the -1 save-or-dust preparation
// risk, the 96-00 automatic failure with the cursed and creator curses, the
// Table 24 XP grid with its per-plus and special forms, and the Rozmare
// worked examples (the potion of speed at 94 percent, the long sword +1 +3
// vs. regenerating creatures at 65 percent with its eight-week preparation).
// census 527 -> 528.
//
// verified against printed pp. 86-95 of the uploaded DMO session capture
// (part 1 holds printed 1-90, printed page N at OCR page N+1; part 2 holds
// printed 91-192, the 86-90 overlap resolved to the part 1 text); the holy
// water ceremony from pp. 86-87, the font cost ladder from p. 87, the level
// thresholds and working space from pp. 87-88, Table 23 from p. 89, the item
// details from pp. 90-92, the recharge and failure doctrine from pp. 92-93,
// Table 24 and the cursed values from pp. 93-94, the Rozmare examples from
// pp. 94-95. The potion success rule prints +1 percent for every two levels
// while the book's own Rozmare example works her 13th level at +26 percent,
// two percent a level; the printed rule and the worked read are both pinned
// with the divergence noted.
//
// the gap census after this round: 52 closed, 44 open - Chapter 4 is DONE in
// one round, ten boxes flip (nine children and the parent); the DMO arc
// continues with Chapter 5 (Magical Duels, pp. 96-117).
//
namespace rules {

// ---- the DMO holy-water ceremony pins ----

// the holy-water ceremony chain length: five spells, create water, purify
// food and drink, bless, chant and prayer, cast in the listed order (printed
// p. 86).
inline int derHolySpellCount()
    { return 5; }

// the unholy-water reversal count: two of the five spells, purify food and
// drink and bless, are cast in reversed form (printed p. 86).
inline int derHolyUnholySpellCount()
    { return 2; }

// the pre-casting meditation: at least eight hours of praying and meditating
// before casting the chain (printed p. 86).
inline int derHolyMeditateHours()
    { return 8; }

// the chant maintenance: the chant spell is maintained for one full turn
// after the chain (printed p. 86).
inline int derHolyChantTurns()
    { return 1; }

// the post-ceremony rest: at least eight hours of rest before casting any
// spells (printed p. 86).
inline int derHolyRestHours()
    { return 8; }

// the combat-window penalty: forced combat during the rest costs -4 on all
// attack rolls, saving throws and ability checks (printed p. 86).
inline int derHolyCombatPenalty()
    { return -4; }

// the one-font-one-week rule: a particular font can be used only once a week
// (printed p. 86).
inline int derFontUsePerWeek()
    { return 1; }

// the temple font limit: a religious building contains only one font, one per
// wing or floor at the DM option (printed p. 86).
inline int derFontsPerBuilding()
    { return 1; }

// the reversed-spell rule: the spells marked with an asterisk are used in
// reversed form to create unholy water (printed p. 86).
inline bool derUnholyReversedSpells()
    { return true; }

// the no-delay rule: any delay between finishing one spell and starting the
// next ruins the ceremony (printed p. 86).
inline bool derCeremonyRuinOnDelay()
    { return true; }

// the overflow rule: the create water spell produces more water than the
// basin holds and the extra is channeled away or magically dissipated
// (printed p. 86).
inline bool derCreateWaterOverflowDissipated()
    { return true; }

// the font-cost ladder length: nine capacity rows, six vials through fifty
// (printed p. 87).
inline int derFontRowCount()
    { return 9; }

// the font construction dice count: 2d4+2 weeks to design and fashion the
// basin and pedestal (printed p. 87).
inline int derFontBuildWeeksDieCount()
    { return 2; }

// the font construction die size: 2d4+2 weeks (printed p. 87).
inline int derFontBuildWeeksDieSize()
    { return 4; }

// the font construction bonus weeks: 2d4+2 (printed p. 87).
inline int derFontBuildWeeksBonus()
    { return 2; }

// the blessed vial cost: five gp for a crystal or leaded-glass vial holding a
// quarter pint (printed p. 87).
inline int derVialCostGp()
    { return 5; }

// the potency window: holy water loses potency if removed from the font for
// more than one turn unless in a blessed vial (printed p. 87).
inline int derVialPotencyTurns()
    { return 1; }

// the empty-vial resale dice count: 1d4+1 gp each on the open market (printed
// p. 87).
inline int derEmptyVialSellDieCount()
    { return 1; }

// the empty-vial resale die size: 1d4+1 gp (printed p. 87).
inline int derEmptyVialSellDieSize()
    { return 4; }

// the empty-vial resale bonus: 1d4+1 gp (printed p. 87).
inline int derEmptyVialSellBonus()
    { return 1; }

// the magical defilement: touching the font and casting a curse spell defiles
// it for holy water and magic font spells (printed p. 87).
inline bool derFontDefileByCurse()
    { return true; }

// the mundane defilement: placing anything repugnant to the deity within the
// font defiles it nonmagically (printed p. 87).
inline bool derFontDefileNonmagical()
    { return true; }

// the remade-font rule: a defiled font must be entirely remade; it cannot be
// cleansed or restored except by a wish (printed p. 87).
inline bool derDefiledFontRemade()
    { return true; }

// the basin-recycle dice count: the defiled basin materials recycle at
// (1d4+1) x 10 percent of the original cost (printed p. 87).
inline int derRecyclePctDieCount()
    { return 1; }

// the basin-recycle die size: (1d4+1) x 10 percent (printed p. 87).
inline int derRecyclePctDieSize()
    { return 4; }

// the basin-recycle bonus: (1d4+1) x 10 percent (printed p. 87).
inline int derRecyclePctBonus()
    { return 1; }

// the basin-recycle multiplier: (1d4+1) x 10 percent (printed p. 87).
inline int derRecyclePctMult()
    { return 10; }

// the Delsenora read: her temple font holds 32 vials, the seventh ladder row
// (printed p. 87).
inline int derDelsenoraFontVials()
    { return 32; }

// the Delsenora read: the initial basin cost was 21,000 gp (printed p. 87).
inline int derDelsenoraBasinCost()
    { return 21000; }

// the Delsenora read: the pedestal cost was 1,500 gp and is repaid on a
// remake (printed p. 87).
inline int derDelsenoraPedestalCost()
    { return 1500; }

// the Delsenora read: she rolls a 2 on the recycle die (printed p. 87).
inline int derDelsenoraRecycleRoll()
    { return 2; }

// the Delsenora read: the roll works out to 30 percent of the original basin
// cost (printed p. 87).
inline int derDelsenoraRecyclePct()
    { return 30; }

// the Delsenora read: 30 percent of 21,000 gp is 6,300 gp (printed p. 87).
inline int derDelsenoraRecycleCost()
    { return 6300; }

// the capacity in vials: 6, 8, 10, 14, 18, 24, 32, 40, 50 (printed p. 87).
inline int derFontCapVials(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 14;
        case 4:
            return 18;
        case 5:
            return 24;
        case 6:
            return 32;
        case 7:
            return 40;
        case 8:
            return 50;
        default:
            return -99;
        }
    }

// the basin cost dice count: one die on every row (printed p. 87).
inline int derFontBasinDieCount(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the basin cost die size: d6, d6, d6, d4, d4, d4, d4, d6, d10 (printed p.
// 87).
inline int derFontBasinDieSize(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 10;
        default:
            return -99;
        }
    }

// the basin cost die multiplier: 10, 50, 100, 500, 1,000, 1,000, 1,000,
// 10,000, 10,000 (printed p. 87).
inline int derFontBasinDieMult(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 500;
        case 4:
            return 1000;
        case 5:
            return 1000;
        case 6:
            return 1000;
        case 7:
            return 10000;
        case 8:
            return 10000;
        default:
            return -99;
        }
    }

// the basin cost bonus in gp: 120, 1,000, 1,800, 5,200, 8,000, 15,000,
// 18,000, 50,000, 100,000 (printed p. 87).
inline int derFontBasinBonusGp(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 1000;
        case 2:
            return 1800;
        case 3:
            return 5200;
        case 4:
            return 8000;
        case 5:
            return 15000;
        case 6:
            return 18000;
        case 7:
            return 50000;
        case 8:
            return 100000;
        default:
            return -99;
        }
    }

// the pedestal cost in gp: 200 through 2,000, a flat fee (printed p. 87).
inline int derFontPedestalGp(int b)
    {
        switch (b) {
        case 0:
            return 200;
        case 1:
            return 350;
        case 2:
            return 500;
        case 3:
            return 750;
        case 4:
            return 1000;
        case 5:
            return 1250;
        case 6:
            return 1500;
        case 7:
            return 1750;
        case 8:
            return 2000;
        default:
            return -99;
        }
    }

// ---- the DMO item-creation requirement pins ----

// the wizard threshold: potions and scrolls at 9th level, given the spells
// (printed p. 87).
inline int derWizPotionScrollLevel()
    { return 9; }

// the wizard threshold: all other items at 11th level (printed p. 87).
inline int derWizOtherItemLevel()
    { return 11; }

// the priest thresholds: scrolls at 7th level (printed p. 87).
inline int derPriestScrollLevel()
    { return 7; }

// the priest thresholds: potions at 9th level (printed p. 87).
inline int derPriestPotionLevel()
    { return 9; }

// the priest thresholds: all other items at 11th level (printed p. 87).
inline int derPriestOtherLevel()
    { return 11; }

// the class bar: warriors and rogues cannot create magical items even with
// spellcasting ability (printed p. 87).
inline bool derWarriorsRoguesCannot()
    { return true; }

// the writings bar: no character can make a magical book, libram, manual,
// tome or artifact (printed p. 87).
inline bool derNoMagicalBooks()
    { return true; }

// the writings bar: magical writings that increase levels and ability scores
// are likewise unbalancing (printed p. 87).
inline bool derNoAbilityWritings()
    { return true; }

// the racial rule: racial items such as boots of elvenkind only by priests of
// the indicated race (printed p. 87).
inline bool derRacialItemsRacePriestOnly()
    { return true; }

// the spell-source rule: priests and wizards can use spells on scrolls,
// stored in items or cast by other characters (printed p. 87).
inline bool derPriestsCastStoredSpellsOk()
    { return true; }

// the usability bar: priests and specialist wizards can make only items they
// can use - no cleric long swords, no transmuter wands of fire (printed p.
// 88).
inline bool derOnlyUsableItems()
    { return true; }

// the specialist bonus: +5 percent to success when the item holds abilities
// from the school of specialization (printed p. 88).
inline int derSpecialistSchoolBonusPct()
    { return 5; }

// the wizard laboratory floor: at least 500 square feet, 20 x 25 feet, more
// preferable (printed p. 88).
inline int derLabMinSqFt()
    { return 500; }

// the laboratory setup cost: 5,000 gp for basic furnishings and supplies
// (printed p. 88).
inline int derLabSetupCostGp()
    { return 5000; }

// the laboratory upkeep: 500 gp a month to stay properly equipped (printed p.
// 88).
inline int derLabMonthlyGp()
    { return 500; }

// the priest altar minimum: 2,000 gp to build and properly consecrate
// (printed p. 88).
inline int derAltarMinCostGp()
    { return 2000; }

// the consecration vigil: one week of prayer and meditation occupying all
// waking hours (printed p. 88).
inline int derAltarVigilWeeks()
    { return 1; }

// the vigil restart: if interrupted, the vigil must be started over again
// (printed p. 88).
inline bool derVigilRestartOnInterrupt()
    { return true; }

// the altar monopoly: only the priest who performed the consecration can use
// it, no other creature while the priest lives (printed p. 88).
inline bool derOnlyConsecratorUsesAltar()
    { return true; }

// the defiled altar: if defiled, the priest must consecrate it again (printed
// p. 88).
inline bool derDefiledAltarReconsecrated()
    { return true; }

// the approval gate: the DM must approve any new magical item entering the
// campaign (printed p. 89).
inline bool derDmApprovalRequired()
    { return true; }

// the quality rule: every item must be of the finest quality, specifically
// created to hold enchantment - no smithy sword becomes a frost brand
// (printed p. 90).
inline bool derItemFinestQuality()
    { return true; }

// the hidden-requirements rule: the character does not automatically know
// what materials and processes are necessary (printed p. 90).
inline bool derRequirementsNotAutoKnown()
    { return true; }

// the wizard chain: enchant an item to focus the energy, the
// power-duplicating spells, and most items also require permanency (printed
// p. 90).
inline bool derEnchantAndPermanencyRequired()
    { return true; }

// the priest path: priests lack enchant an item and must petition their
// deities, the DMG Chapter 10 procedure (printed p. 90).
inline bool derPriestsPetitionDeities()
    { return true; }

// the permanency price: wizards lose one point of Constitution casting the
// permanency most items require (printed p. 90).
inline int derPermanencyConLoss()
    { return 1; }

// the priest read: priests do not normally suffer the loss, though the DM can
// rule the taxing process drains a point on permanency-class items (printed
// p. 90).
inline bool derPriestNoConLossDefault()
    { return true; }

// the material rarity code: common - plentiful, steel, oak staves, copper,
// wool (printed pp. 90-91).
inline int derMatCommon()
    { return 1; }

// the material rarity code: rare - expensive and difficult, silk, diamonds,
// roc feathers, ebony (printed pp. 90-91).
inline int derMatRare()
    { return 2; }

// the material rarity code: exotic - unique, unpurchasable, adventure-borne,
// moon tears and goddess hair (printed pp. 90-91).
inline int derMatExotic()
    { return 3; }

// the material code: one rare and one common, the scroll-spell read (printed
// p. 89).
inline int derMatRareAndCommon()
    { return 4; }

// the material code: one exotic per function, the multiple-function read
// (printed p. 89).
inline int derMatExoticPerFunction()
    { return 5; }

// the material code: one exotic per use, the limited-use read (printed p.
// 89).
inline int derMatExoticPerUse()
    { return 6; }

// the process code: common - simple and straightforward, spring-storm snow
// and lava tempering (printed pp. 91 and 91).
inline int derProcCommon()
    { return 1; }

// the process code: rare - extra effort or extraordinary expense (printed p.
// 91).
inline int derProcRare()
    { return 2; }

// the process code: exotic - unique, adventure-only, a lover's sigh and
// burning ice (printed p. 91).
inline int derProcExotic()
    { return 3; }

// the process code: one rare and one common, the armor and weapon
// single-function read (printed p. 89).
inline int derProcRareAndCommon()
    { return 4; }

// the process code: one exotic per function (printed p. 89).
inline int derProcExoticPerFunction()
    { return 5; }

// the process code: one exotic per use (printed p. 89).
inline int derProcExoticPerUse()
    { return 6; }

// the process code: one rare per function, the miscellaneous-multiple read
// (printed p. 89).
inline int derProcRarePerFunction()
    { return 7; }

// the process code zero: variable, the scroll-spell read (printed p. 89).
inline int derProcVariable()
    { return 0; }

// the footnote-process code: no extra process required (printed p. 89).
inline int derExtraNone()
    { return 0; }

// the footnote one: one common process also is required (printed p. 89).
inline int derExtraCommon()
    { return 1; }

// the footnote two: one exotic process also is required (printed p. 89).
inline int derExtraExotic()
    { return 3; }

// the footnote three: one rare and one common process also are required
// (printed p. 89).
inline int derExtraRareCommon()
    { return 4; }

// the cost code: half the XP value in gp (printed p. 89).
inline int derCostHalfXp()
    { return 1; }

// the cost code: the XP value in gp (printed p. 89).
inline int derCostXp()
    { return 2; }

// the cost code: double the XP value in gp (printed p. 89).
inline int derCostDoubleXp()
    { return 4; }

// the cost code: triple the XP value in gp (printed p. 89).
inline int derCostTripleXp()
    { return 6; }

// the cost code: quadruple the XP value in gp (printed p. 89).
inline int derCostQuadXp()
    { return 8; }

// the time code: one day per 100 gp (printed p. 89).
inline int derTimeDayPerHundredGp()
    { return 1; }

// the time code: one day per spell level (printed p. 89).
inline int derTimeDayPerSpellLevel()
    { return 2; }

// the time code: a fixed number of days (printed p. 89).
inline int derTimeFixedDays()
    { return 3; }

// the time code: one week per 100 gp (printed p. 89).
inline int derTimeWeekPerHundredGp()
    { return 4; }

// the time code: one week per 1,000 gp (printed p. 89).
inline int derTimeWeekPerThousandGp()
    { return 5; }

// the Table 23 grid length: 28 item rows, potion single-use through weapon
// limited-use (printed p. 89).
inline int derT23RowCount()
    { return 28; }

// the material code: 1 common, 2 rare, 3 exotic, 4 rare-and-common, 5
// exotic-per-function, 6 exotic-per-use (printed p. 89).
inline int derT23MatCode(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 5;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 5;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 5;
        case 20:
            return 6;
        case 21:
            return 3;
        case 22:
            return 5;
        case 23:
            return 6;
        case 24:
            return 2;
        case 25:
            return 3;
        case 26:
            return 5;
        case 27:
            return 6;
        default:
            return -99;
        }
    }

// the process code: 0 variable, 1 common, 2 rare, 3 exotic, 4
// rare-and-common, 5 exotic-per-function, 6 exotic-per-use, 7
// rare-per-function (printed p. 89).
inline int derT23ProcCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 5;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 2;
        case 12:
            return 5;
        case 13:
            return 6;
        case 14:
            return 2;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 7;
        case 20:
            return 6;
        case 21:
            return 4;
        case 22:
            return 5;
        case 23:
            return 6;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 5;
        case 27:
            return 6;
        default:
            return -99;
        }
    }

// the footnote process: 0 none, 1 the footnote-one common, 3 the footnote-two
// exotic, 4 the footnote-three rare-and-common (printed p. 89).
inline int derT23ProcExtraCode(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 0;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 4;
        case 27:
            return 4;
        default:
            return -99;
        }
    }

// the cost in half-XP units: 1 half value, 2 the value, 4 double, 6 triple, 8
// quadruple (printed p. 89).
inline int derT23CostHalfXp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 6;
        case 19:
            return 8;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 2;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        default:
            return -99;
        }
    }

// the time kind: 1 day per 100 gp, 2 day per spell level, 3 fixed days, 4
// week per 100 gp, 5 week per 1,000 gp (printed p. 89).
inline int derT23TimeKind(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 4;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 5;
        default:
            return -99;
        }
    }

// the time rate: the days or weeks of the time kind, or the fixed day count
// (printed p. 89).
inline int derT23TimeRate(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 2;
        case 24:
            return 1;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 2;
        default:
            return -99;
        }
    }

// ---- the DMO item-details pins ----

// the potion brew base: 70 percent (printed p. 91).
inline int derPotionBasePct()
    { return 70; }

// the potion level bonus: +1 percent for every two levels of the creator
// (printed p. 91) - the book's own Rozmare example works her 13th level at
// +26, two percent a level, the divergence noted in the banner.
inline int derPotionLevelPctStep()
    { return 1; }

// the potion cost penalty: -1 percent for each 100 gp the potion costs
// (printed p. 91).
inline int derPotionCostStepGp()
    { return 100; }

// the potion-formula research dice: 1d3+1 weeks from scratch (printed p. 91).
inline int derPotionResearchDieCount()
    { return 1; }

// the potion-formula research die size: 1d3+1 weeks (printed p. 91).
inline int derPotionResearchDieSize()
    { return 3; }

// the potion-formula research bonus: 1d3+1 weeks (printed p. 91).
inline int derPotionResearchBonus()
    { return 1; }

// the potion-formula research cost: 100 gp a week (printed p. 91).
inline int derPotionResearchWeeklyGp()
    { return 100; }

// the potion analysis: with a dose or another caster's formula the research
// is free and takes one week (printed p. 91).
inline int derPotionAnalyzeWeeks()
    { return 1; }

// the analysis dose: a full dose is needed but not consumed in the research
// (printed p. 91).
inline bool derPotionDoseNotConsumed()
    { return true; }

// the recorded formula: once personally researched and recorded, no
// re-research unless the record is lost (printed p. 91).
inline bool derPotionFormulaReusable()
    { return true; }

// the scroll-writing base: 80 percent (printed p. 91).
inline int derScrollBasePct()
    { return 80; }

// the scroll level bonus: +1 percent for every level of the creator (printed
// p. 91).
inline int derScrollLevelPctPerLevel()
    { return 1; }

// the scroll spell penalty: -1 percent for each level of the written spell
// (printed p. 91).
inline int derScrollSpellPctPerSpellLevel()
    { return 1; }

// the ink blending: one day to blend, the ink must be used within two weeks
// (printed p. 91).
inline int derScrollInkBlendDays()
    { return 1; }

// the ink window: two weeks from blending to use (printed p. 91).
inline int derScrollInkUseWeeks()
    { return 2; }

// the ink ladder: spells of levels 1-3 require a rare ingredient (printed p.
// 91).
inline int derScrollLowInkLevelMax()
    { return 3; }

// the ink ladder: spells of levels 4-6 require an exotic ingredient (printed
// p. 91).
inline int derScrollHighInkLevelMin()
    { return 4; }

// the ink ladder: spells of levels 7 and up require one rare and one exotic
// ingredient (printed p. 91).
inline int derScrollTopInkLevelMin()
    { return 7; }

// the scroll capacity: 1d6 spells per scroll, secretly rolled, the character
// knows when it is full (printed p. 91).
inline int derScrollSpellsDieSize()
    { return 6; }

// the scroll doctrine: no spells are actually cast in writing, but the writer
// must know the spell and hold the components (printed p. 91).
inline bool derScrollNoSpellsCast()
    { return true; }

// the scroll components: if normally consumed in casting, they are consumed
// in writing (printed p. 91).
inline bool derScrollComponentsConsumed()
    { return true; }

// the scroll penalty carry: a casting penalty such as magical aging carries
// into the scroll writing (printed p. 91).
inline bool derScrollPenaltyCarried()
    { return true; }

// the scroll failure: a failed spell fills the remaining space with an ink
// blob, leaving written spells intact (printed p. 91).
inline bool derScrollFailurePreservesSpells()
    { return true; }

// the scroll quill: a new quill must be used for each spell written (printed
// p. 91).
inline bool derScrollNewQuillPerSpell()
    { return true; }

// the ring creation base: 60 percent (printed p. 91).
inline int derRingBasePct()
    { return 60; }

// the ring level bonus: +1 percent for every level of the creator (printed p.
// 91).
inline int derRingLevelPctPerLevel()
    { return 1; }

// the ring penalty: -1 percent for each spell and special process required,
// except enchant an item (printed p. 91).
inline int derRingSpellPctPerSpell()
    { return 1; }

// the ring research dice: 1d6+1 weeks (printed p. 91).
inline int derRingResearchDieCount()
    { return 1; }

// the ring research die size: 1d6+1 weeks (printed p. 91).
inline int derRingResearchDieSize()
    { return 6; }

// the ring research bonus: 1d6+1 weeks (printed p. 91).
inline int derRingResearchBonus()
    { return 1; }

// the ring research cost: 200 gp a week (printed p. 91).
inline int derRingResearchWeeklyGp()
    { return 200; }

// the aided ring research: contact other plane or commune reduces the time to
// two weeks (printed p. 91).
inline int derRingResearchAidedWeeks()
    { return 2; }

// the ring read: any ring requires one common process beyond its Table 23
// needs (printed p. 91).
inline bool derRingCommonProcessExtra()
    { return true; }

// the ring read: priests still suffer the spell penalty though they cast
// nothing - the complex enchantment is harder to petition (printed p. 91).
inline bool derRingPriestsSufferPenalty()
    { return true; }

// the rods-staves-wands chain: enchant an item, the power spells, and a
// permanency spell is required (printed p. 92).
inline bool derRodStaffWandPermanency()
    { return true; }

// the drained-item death: losing all charges kills the magic forever, even a
// rechargeable item can never be enchanted again (printed p. 92).
inline bool derDrainedItemDeadForever()
    { return true; }

// the plus rule: each plus for a weapon or protective device requires a
// separate spell (printed p. 92).
inline bool derEachPlusSeparateSpell()
    { return true; }

// the permanency exemption: single-use and limited-use items do not require
// permanency (printed p. 92).
inline bool derSingleUseNoPermanency()
    { return true; }

// the misc-armor-weapon base: the chance to create one of these is the same
// as for a ring (printed p. 92).
inline bool derMiscSameAsRing()
    { return true; }

// the time doctrine: manufacturing time cannot be reduced by extra workers,
// help or money (printed p. 91).
inline bool derTimeNotReducible()
    { return true; }

// the rods-staves-wands base: the same chance as a ring, 60 percent (printed
// p. 92).
inline int derRodStaffWandBasePct()
    { return 60; }

// the rechargeable birth: created with one charge, the rest added by
// recharging (printed p. 92).
inline int derInitialCharges()
    { return 1; }

// ---- the DMO recharge and failure pins ----

// the recharge window: 24 hours to create charges once the preparatory spell
// or ceremony is complete (printed p. 93).
inline int derRechargeWindowHours()
    { return 24; }

// the preparation risk: each preparation forces a save vs. spell at the
// caster's level with a -1 penalty; failure is dust (printed p. 93).
inline int derRechargeSavePenalty()
    { return -1; }

// the recharge permission: mages can also recharge items usable only by
// fighters or rogues (printed p. 93).
inline bool derMagesRechargeNoncasterItems()
    { return true; }

// the recharge doctrine: the spell must duplicate the item's power - the most
// powerful function for multi-function items, a cone of cold for a wand of
// frost (printed p. 93).
inline bool derRechargeSpellDuplicatesPower()
    { return true; }

// the recharge timing: each spell takes its normal casting time, not the
// enchant an item delay (printed p. 93).
inline bool derRechargeNormalCastingTime()
    { return true; }

// the automatic failure floor: any roll of 96-00 fails automatically (printed
// p. 93).
inline int derAutoFailRollMin()
    { return 96; }

// the automatic failure ceiling: rolls 96 through 100 (printed p. 93).
inline int derAutoFailRollMax()
    { return 100; }

// the secret roll: the DM secretly rolls the dice for each creation attempt
// (printed p. 93).
inline bool derDmRollsSecretly()
    { return true; }

// the mastery limit: no matter how many times a character has created an
// item, the chances stay the same (printed p. 93).
inline bool derSuccessNeverImproves()
    { return true; }

// the ordinary failure: most failed attempts ruin the item into useless slag
// (printed p. 93).
inline bool derFailureUsuallyRuins()
    { return true; }

// the 96-00 twist: the item appears normal but carries a cursed or reversed
// effect, DM's choice (printed pp. 93-94).
inline bool derAutoFailMakesCurse()
    { return true; }

// the cursed-item doctrine: judge cost and difficulty against useful items of
// similar power - a sword -2 is as hard as a sword +2 (printed p. 94).
inline bool derCursedCompareToSimilar()
    { return true; }

// the cursed failure: a failed cursed-item attempt is destroyed (printed p.
// 94).
inline bool derCursedFailureDestroys()
    { return true; }

// the creator curse: a cursed-item attempt failing on 96-00 puts the curse on
// the creator, never a useful item (printed p. 94).
inline bool derCreatorCursedOnAutoFail()
    { return true; }

// the nonstandard doctrine: assign an XP value by comparison to similar
// existing items; err high (printed p. 94).
inline bool derNonstandardCompareToSimilar()
    { return true; }

// ---- the DMO Table 24 XP grid ----

// the Table 24 code: a flat min-max range (printed p. 93).
inline int derXpFlat()
    { return 0; }

// the Table 24 code: the range is per plus, the armor and weapon reads
// (printed p. 93).
inline int derXpPerPlus()
    { return 1; }

// the Table 24 code: the multiple-function value is the lower value plus the
// higher value, the armor read (printed p. 93).
inline int derXpSumOfValues()
    { return 2; }

// the Table 24 code: the lower value plus 20-40 percent of the higher value,
// the weapon read (printed p. 93).
inline int derXpLowerPlusShare()
    { return 3; }

// the Table 24 code: 100 XP per spell level, the scroll-spell read (printed
// p. 93).
inline int derXpPerSpellLevel()
    { return 4; }

// the Table 24 grid length: 27 item rows, potion single-use through weapon
// limited-use (printed p. 93).
inline int derT24RowCount()
    { return 27; }

// the XP minimum: the low end of the range, or the per-plus and
// per-spell-level base (printed p. 93).
inline int derT24XpMin(int b)
    {
        switch (b) {
        case 0:
            return 200;
        case 1:
            return 250;
        case 2:
            return 100;
        case 3:
            return 1000;
        case 4:
            return 1000;
        case 5:
            return 3000;
        case 6:
            return 1000;
        case 7:
            return 4000;
        case 8:
            return 5000;
        case 9:
            return 6000;
        case 10:
            return 4000;
        case 11:
            return 5000;
        case 12:
            return 7000;
        case 13:
            return 2500;
        case 14:
            return 2000;
        case 15:
            return 4000;
        case 16:
            return 4000;
        case 17:
            return 200;
        case 18:
            return 2000;
        case 19:
            return 2500;
        case 20:
            return 500;
        case 21:
            return 250;
        case 22:
            return 0;
        case 23:
            return 3000;
        case 24:
            return 20;
        case 25:
            return 400;
        case 26:
            return 0;
        case 27:
            return 1000;
        default:
            return -99;
        }
    }

// the XP maximum: the high end of the range, zero where a special form
// applies (printed p. 93).
inline int derT24XpMax(int b)
    {
        switch (b) {
        case 0:
            return 1000;
        case 1:
            return 1000;
        case 2:
            return 0;
        case 3:
            return 2500;
        case 4:
            return 4000;
        case 5:
            return 5000;
        case 6:
            return 5000;
        case 7:
            return 10000;
        case 8:
            return 10000;
        case 9:
            return 10000;
        case 10:
            return 10000;
        case 11:
            return 8000;
        case 12:
            return 15000;
        case 13:
            return 5000;
        case 14:
            return 4000;
        case 15:
            return 7000;
        case 16:
            return 6000;
        case 17:
            return 2000;
        case 18:
            return 10000;
        case 19:
            return 10000;
        case 20:
            return 2500;
        case 21:
            return 800;
        case 22:
            return 0;
        case 23:
            return 5000;
        case 24:
            return 50;
        case 25:
            return 600;
        case 26:
            return 0;
        case 27:
            return 5000;
        default:
            return -99;
        }
    }

// the special-form code: 0 flat, 1 per plus, 2 lower value plus higher value,
// 3 lower value plus 20-40 percent of the higher, 4 per spell level (printed
// p. 93).
inline int derT24PerPlus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 3;
        case 27:
            return 0;
        default:
            return -99;
        }
    }

// ---- the DMO Rozmare worked-example pins ----

// the Rozmare level: 13th in both worked examples (printed pp. 94-95).
inline int derRozmareLevel()
    { return 13; }

// the potion-of-speed read: its XP value is 200 gp, also the
// additional-materials cost (printed p. 95).
inline int derPotionSpeedXpValue()
    { return 200; }

// the potion-of-speed read: brewing takes two weeks (printed p. 95).
inline int derPotionSpeedBrewWeeks()
    { return 2; }

// the potion-of-speed read: the DM rolls 71 against her 94 percent (printed
// p. 95).
inline int derPotionSpeedSuccessPct()
    { return 94; }

// the Rozmare sword: an 800 XP value, the long sword +1 +3 vs. regenerating
// creatures (printed p. 95).
inline int derRozmareSwordXpValue()
    { return 800; }

// the Rozmare sword: additional materials cost double the XP value, 1,600 gp
// (printed p. 95).
inline int derRozmareSwordMaterialGp()
    { return 1600; }

// the Rozmare sword: three weeks of research without magical aid (printed p.
// 95).
inline int derSwordResearchWeeks()
    { return 3; }

// the Rozmare sword: 600 gp spent on the research (printed p. 95).
inline int derSwordResearchGp()
    { return 600; }

// the preparation doctrine: four weeks per 1,000 gp of cost, rounded up to
// the nearest 1,000 (printed p. 95).
inline int derPrepWeeksPerThousandGp()
    { return 4; }

// the Rozmare sword: 1,600 gp rounds to 2,000, four weeks a thousand - eight
// weeks (printed p. 95).
inline int derRozmareSwordPrepWeeks()
    { return 8; }

// the Rozmare sword: base 60 + 13 for level - 8 for processes and spells, 65
// percent; the DM rolls 54 (printed p. 95).
inline int derRozmareSwordSuccessPct()
    { return 65; }

// the Rozmare sword: two exotic materials, fallen-star metal and
// vampire-coffin nails (printed p. 95).
inline int derRozmareSwordExoticMaterials()
    { return 2; }

}   // namespace rules
