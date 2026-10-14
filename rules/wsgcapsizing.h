// =========================================================================================
// Adnd1 - rules/wsgcapsizing.h
// The WSG CAPSIZING AND DAMAGE TO CRAFT, R456: waterborne vehicles and their
// passengers are to some degree at the mercy of the elements - most vessels
// have a chance of capsizing (turning over, and perhaps sinking) if the wind
// is strong or the water is rough, and violent weather can damage masts and
// sails on a rigged vessel. Table 26, the CHANCE OF CAPSIZING: kayak
// 25/40/60/80, small canoe 20/35/50/75, small rowboat 5/15/30/50, coracle
// 10/20/30/50, large canoe 10/20/30/40, large rowboat 0/10/25/40, small barge
// 0/5/10/20, and large barge 0/0/5/10, across the four wind/water conditions
// - MILD, MODERATE, DANGEROUS and SEVERE. The check is made whenever a
// character enters or leaves a boat, when someone moves abruptly from one
// spot to another in or on the craft, and at any other time the Dungeon
// Master deems appropriate. The table rates are for vessels with no sails, or
// with the sails furled (rolled up and tied to the mast); under sail the
// chance of capsizing is 20% greater in all cases where the base chance is
// greater than 0%. The condition bands: MILD - wind light at 15 miles per
// hour or less and the water calm or moving only slightly (current of 3
// inches or less); MODERATE - wind 16 to 30 miles per hour, or the water
// running fairly fast (current faster than 3 inches, up to 6); DANGEROUS -
// wind 31 to 50 miles per hour, or the water running very fast (current
// faster than 6 inches, up to 9); SEVERE - wind more than 50 miles per hour,
// or a current of 9 inches or greater. As with the movement figures, all of
// these assume at least one character aboard with proficiency in
// boating/sailing. The mast damage rules: strong winds can damage sails,
// rigging or the mast (assuming the mast is raised) whenever the wind
// velocity is 40 miles per hour or greater, on a percentage chance equal to
// the velocity of the wind, modified downward by 30% if the mast is raised
// but the sail is furled - and upward if the mast is not securely rigged or
// is made of weak material, at the Dungeon Master discretion. The check is
// made once per hour or as often as the DM deems appropriate, conceivably
// more frequently for a poorly rigged or substandard mast. Census 380 -> 381.
// census 380 -> 381.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 45; the
// user own copy OCR (page 46) cross-checked against the archive djvu word
// layer (Guide_0045) - the prose reads clean two-way, but the djvu TRUNCATES
// the Table 26 large barge row (the severe cell cut off at the page break),
// so the grid was settled by TWO independent IIIF eye-reads of leaf $45,
// which agree with the OCR exactly on all eight rows and all four columns,
// the large barge severe cell reading 10%.
//
// Watch the weather or swim: the kayak flips one time in four in mild water
// and four times in five in a gale, the barges barely at all. Step in, step
// out, or lurch across the deck and roll. Under sail add twenty, if there was
// anything to add. Mild is a lazy breeze under fifteen and a drift under
// four; moderate to thirty and six; dangerous to fifty and nine; severe
// beyond both. And from forty miles per hour the wind itself snaps the mast
// on a roll of the velocity - thirty less if the sail is furled, once an
// hour, more if the rigging is bad.
//
namespace rules {

// ---- the capsize grid ----

// Table 26 lists the same eight vessels as Table 25: kayak, small canoe,
// small rowboat, coracle, large canoe, large rowboat, small barge and large
// barge.
inline int wcpVesselCount()
    { return 8; }

// The four wind/water conditions: mild, moderate, dangerous and severe.
inline int wcpConditionCount()
    { return 4; }

// Capsizing is turning over, and perhaps sinking.
inline bool wcpCapsizeMeansTurnOver()
    { return true; }

// The chance of capsizing in MILD conditions (wind 15 mph or less, current 3
// inches or less): 25, 20, 5, 10, 10, 0, 0, 0.
inline int wcpMildPct(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return 0;
        }
    }

// The chance of capsizing in MODERATE conditions (wind 16-30 mph, current 3
// to 6 inches): 40, 35, 15, 20, 20, 10, 5, 0.
inline int wcpModeratePct(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 35;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 10;
        case 6:
            return 5;
        case 7:
            return 0;
        default:
            return 0;
        }
    }

// The chance of capsizing in DANGEROUS conditions (wind 31-50 mph, current 6
// to 9 inches): 60, 50, 30, 30, 30, 25, 10, 5.
inline int wcpDangerPct(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 25;
        case 6:
            return 10;
        case 7:
            return 5;
        default:
            return 0;
        }
    }

// The chance of capsizing in SEVERE conditions (wind over 50 mph, current 9
// inches or more): 80, 75, 50, 50, 40, 40, 20, 10.
inline int wcpSeverePct(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 75;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 40;
        case 5:
            return 40;
        case 6:
            return 20;
        case 7:
            return 10;
        default:
            return 0;
        }
    }

// ---- the check triggers ----

// The chance of capsizing is checked whenever a character enters or leaves a
// boat.
inline bool wcpCheckOnEnterLeave()
    { return true; }

// The chance of capsizing is checked when someone moves abruptly from one
// spot to another in or on the craft.
inline bool wcpCheckOnAbruptMove()
    { return true; }

// The check is also made at any other time the Dungeon Master deems
// appropriate.
inline bool wcpCheckOnDmCall()
    { return true; }

// The table rates are for vessels with no sails, or those on which the sails
// are furled (rolled up and tied to the mast).
inline bool wcpTableAssumesNoSail()
    { return true; }

// If the vessel is being operated under sail, the chance of capsizing is 20%
// greater in all cases where the base chance is greater than 0%.
inline bool wcpUnderSailIncreased()
    { return true; }

// If the vessel is being operated under sail, the chance of capsizing is 20%
// greater in all cases where the base chance is greater than 0%.
inline int wcpSailModifier()
    { return 20; }

// As with the movement figures, all of these figures assume the presence on
// board of at least one character with proficiency in boating/sailing.
inline bool wcpProficiencyAssumed()
    { return true; }

// ---- the condition bands ----

// Mild conditions prevail when the wind velocity is light - 15 miles per hour
// or less.
inline int wcpMildWindMax()
    { return 15; }

// Mild: the surface of the water is calm or moving only slightly - a current
// of 3 inches or less.
inline int wcpMildCurrentMax()
    { return 3; }

// Moderate conditions exist when the wind is blowing at 16 to 30 miles per
// hour.
inline int wcpModWindMin()
    { return 16; }

// The top of the moderate wind band: 16 to 30 miles per hour.
inline int wcpModWindMax()
    { return 30; }

// Moderate: the water is running fairly fast - a current faster than 3
// inches, up to 6.
inline int wcpModCurrentMax()
    { return 6; }

// Dangerous conditions occur when the wind is blowing at 31 to 50 miles per
// hour.
inline int wcpDangerWindMin()
    { return 31; }

// The top of the dangerous wind band: 31 to 50 miles per hour.
inline int wcpDangerWindMax()
    { return 50; }

// Dangerous: the water is running very fast - a current faster than 6 inches,
// up to 9.
inline int wcpDangerCurrentMax()
    { return 9; }

// Severe conditions exist when the wind is blowing at more than 50 miles per
// hour.
inline int wcpSevereWindMin()
    { return 50; }

// Severe: a current of 9 inches or greater.
inline int wcpSevereCurrentMin()
    { return 9; }

// ---- the mast damage rules ----

// Strong winds can damage sails, rigging or the mast on a vessel so equipped,
// assuming the mast is raised and has not been taken down.
inline bool wcpMastDamageByWind()
    { return true; }

// Strong winds can damage sails, rigging or the mast whenever the wind
// velocity is 40 miles per hour or greater.
inline int wcpMastDamageWindMin()
    { return 40; }

// The mast damage occurs on a percentage chance equal to the velocity of the
// wind.
inline bool wcpDamageChanceEqualsVelocity()
    { return true; }

// The mast damage chance is modified downward by 30% if the mast is raised
// but the sail is furled.
inline bool wcpFurledSailReduced()
    { return true; }

// The mast damage chance is modified downward by 30% if the mast is raised
// but the sail is furled (not in use).
inline int wcpFurledReduction()
    { return 30; }

// If the mast is not securely rigged, or is made of relatively weak material,
// the Dungeon Master adjusts the chance of damage upward.
inline bool wcpPoorRiggingIncreased()
    { return true; }

// The mast damage check is made once per hour or as often as the DM deems
// appropriate - more frequently for a poorly rigged or substandard mast.
inline bool wcpMastCheckHourly()
    { return true; }

// The mast damage check is made once per hour, or as often as the Dungeon
// Master deems appropriate.
inline int wcpMastCheckPeriodHours()
    { return 1; }

}   // namespace rules
