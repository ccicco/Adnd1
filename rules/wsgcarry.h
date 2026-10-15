// =========================================================================================
// Adnd1 - rules/wsgcarry.h
// R466: the WSG CONSUMING AND CARRYING FOOD slice - the ration ladder (one
// fish half a ration, one size S animal a full ration, one size M animal
// feeding three characters for a day, one size L animal six rations, at least
// twenty rations for a full day of expert butchering), the druid disapproval
// of intentional overkill with the feed-three excuse, carrying the excess
// subject only to encumbrance and spoilage, and Table 33: the food spoilage
// grid by effective temperature with the taint and spoil mechanics, printed
// p. 58.
// census 390 -> 391.
//
// Ground truth two-way: the pdfy embedded OCR text layer of the printed p. 58
// content stream (the FlateDecode stream of pageobj 549, decompressed and
// position-read) vs the djvu word layer (Guide_0058), with the arithmetic
// ladders as the tiebreaker. Both layers agree on every Table 33 value cell
// except the green-plants 31-50 cell, where the pdfy reads 6/20 against a
// djvu garble; 6/20 fits the clean days ladder (6, 4, 2, 1) and the pct
// ladder (20, 30, 40, 50). The below-30 column is a dash in every row (both
// layers garble the dash glyph); the book explanation sentence - spoilage
// will not occur as long as the effective temperature remains within this
// range - confirms the dash, and continually frozen food keeps indefinitely
// no matter how long it is carried. The printed p. 58 image shows scanner
// double-imaging (a ghost copy about 12 pixels below the true print) which
// defeated the pixel and vision reads; the text layers carry the table. The
// mechanics: the effective temperature is the warmest category applying at
// least one hour that day, a category once used ratchets to the same or
// warmer for all later checks, thawed food is subject to spoilage from the
// thaw day (counted as day 1) even if promptly re-frozen; one failed check
// taints (a secret Wisdom Check to notice, eatable anyway, a CON check at +4
// to avoid nausea and cramps within 1d10+10 minutes, a -1 penalty on attacks
// and dodging or maneuvering saves for 12 hours, then an unmodified CON check
// per hour to recover, tainted food still a full ration); a second failed
// check obviously spoils (CON check at +10, penalties at least 24 hours if
// stricken, else a 50% chance the food still provides the full or half ration
// value, otherwise no nourishment at all). The onset window is 11-20 minutes
// (1d10+10). The gluttony and indigestion note: the rules do not account for
// them.
//
// All 40 Table 33 cells pinned (the max days and the spoilage pct per food
// type per temperature band); the ration ladder and the taint and spoil
// mechanics are audit examples, including the dash column and the frozen and
// thaw rules.
//
namespace rules {

// ---- The ration ladder ----

// one fish provides half of a character minimum daily ration: the numerator
inline int wccFishRationNum()
    { return 1; }

// the fish half-ration denominator
inline int wccFishRationDen()
    { return 2; }

// one size S animal is one full ration
inline int wccSizeSRations()
    { return 1; }

// one size M animal is enough to feed three characters for one day
inline int wccSizeMFeedCount()
    { return 3; }

// one size L animal is six rations worth of food
inline int wccSizeLRations()
    { return 6; }

// at least twenty full rations from a size L carcass with expert butchering
inline int wccButcherRations()
    { return 20; }

// the expert butchering takes one full day of butchering, slicing and
// packaging
inline int wccButcherDays()
    { return 1; }

// these rules do not account for gluttony or indigestion - that is left to
// the Dungeon Master
inline bool wccGluttonyNotModeled()
    { return true; }

// a druid in the party strongly disapproves if hunters or fishermen
// intentionally kill more than they can conceivably eat in one sitting
inline bool wccDruidDisapprovesOverkill()
    { return true; }

// an overkill cannot always be helped: the hunter feeding three is not held
// responsible for the leftovers
inline bool wccOverkillExcusable()
    { return true; }

// killing one size L animal to feed himself and two others is an excusable
// overkill
inline int wccOverkillFeedCount()
    { return 3; }

// ---- Carrying the excess ----

// excess food need not be left behind when the party breaks camp - it can be
// carried along
inline bool wccExcessCarryAllowed()
    { return true; }

// encumbrance, the first of the two carrying factors, is a Dungeon Master
// ruling
inline bool wccEncumbranceDMCall()
    { return true; }

// ---- Table 33: the food spoilage grid ----

// the Table 33 row count: green plants, fruits or vegetables, cooked meat,
// raw meat
inline int wccRowCount()
    { return 4; }

// the Table 33 below-30 max days (the dash)
inline int wccBelowDays(int b)
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
        default:
            return 0;
        }
    }

// the Table 33 below-30 spoilage pct (the dash)
inline int wccBelowPct(int b)
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
        default:
            return 0;
        }
    }

// the Table 33 31-50 max days
inline int wcc31Days(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// the Table 33 31-50 spoilage pct
inline int wcc31Pct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 20;
        case 3:
            return 50;
        default:
            return 0;
        }
    }

// the Table 33 51-70 max days
inline int wcc51Days(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the Table 33 51-70 spoilage pct
inline int wcc51Pct(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 70;
        default:
            return 0;
        }
    }

// the Table 33 71-90 max days
inline int wcc71Days(int b)
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
        default:
            return 0;
        }
    }

// the Table 33 71-90 spoilage pct
inline int wcc71Pct(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 80;
        default:
            return 0;
        }
    }

// the Table 33 above-90 max days
inline int wccAboveDays(int b)
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
        default:
            return 0;
        }
    }

// the Table 33 above-90 spoilage pct
inline int wccAbovePct(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 80;
        case 3:
            return 90;
        default:
            return 0;
        }
    }

// ---- The spoilage mechanics ----

// the Table 33 dash: spoilage will not occur as long as the effective
// temperature remains within the below-30 range
inline bool wccDashNoSpoilage()
    { return true; }

// food kept continually frozen will be good to eat no matter how long it is
// carried or stored
inline bool wccFrozenKeepsIndefinitely()
    { return true; }

// thawed food is subject to spoilage from the thaw day even if promptly
// re-frozen after the exposure
inline bool wccThawSpoilsEvenIfRefrozen()
    { return true; }

// thawed food is subject to spoilage beginning on the thaw day, counting that
// day as day 1
inline int wccThawStartDay()
    { return 1; }

// the effective temperature is the warmest category that applied on the given
// day, gated by the one-hour rule
inline bool wccWarmestCategoryApplies()
    { return true; }

// a temperature category applies as the effective temperature only if it held
// for at least one hour on that day
inline int wccTempHourGate()
    { return 1; }

// once a temperature category is used for one spoilage check, the same or a
// warmer one is used for all subsequent checks
inline bool wccCategoryRatchet()
    { return true; }

// food that fails one spoilage check is tainted - not as good as fresh, but
// not obviously spoiled
inline bool wccOneFailTainted()
    { return true; }

// a character intending to eat tainted food gets a secret Wisdom Check to
// notice the spoilage first
inline bool wccTaintSecretWisdomCheck()
    { return true; }

// a character who notices the taint may choose to eat the food anyway
inline bool wccMayEatAnyway()
    { return true; }

// food that fails a second spoilage check is obviously spoiled and perceived
// as such by anyone intending to eat it
inline bool wccTwoFailsSpoiled()
    { return true; }

// eating tainted food demands a Constitution check with a +4 modifier to
// avoid suffering
inline int wccTaintConMod()
    { return 4; }

// the tainted-food onset die: 1d10
inline int wccTaintOnsetDie()
    { return 10; }

// the tainted-food onset base: nausea and cramps within 1d10+10, the 11-20
// minute window
inline int wccTaintOnsetBase()
    { return 10; }

// the tainted-food penalty: -1 on all attack rolls and on dodging or
// maneuvering saves
inline int wccTaintAtkPenalty()
    { return 1; }

// the tainted-food penalty lasts for 12 hours
inline int wccTaintPenaltyHours()
    { return 12; }

// after the 12 hours, recovery checks come at one per hour until one succeeds
inline int wccTaintRecheckMins()
    { return 60; }

// tainted food still provides a normal amount of food value: a full ration
// still counts as a full ration
inline bool wccTaintFullRationValue()
    { return true; }

// eating spoiled food demands a Constitution check with a +10 modifier to
// avoid the illness
inline int wccSpoilConMod()
    { return 10; }

// if stricken by spoiled food, the penalties last at least 24 hours instead
// of 12
inline int wccSpoilPenaltyHours()
    { return 24; }

// if spoiled food causes no illness, a 50% chance it still provides the full
// ration value (or half, if only that much was eaten)
inline int wccSpoilRationPct()
    { return 50; }

// if only half of the no-illness spoiled food was eaten, it counts as a
// half-ration
inline bool wccSpoiledHalfRationIfHalfEaten()
    { return true; }

// otherwise the spoiled food is so spoiled it does not serve as nourishment -
// as if not eaten at all
inline bool wccSpoiledNoNourishment()
    { return true; }

}   // namespace rules
