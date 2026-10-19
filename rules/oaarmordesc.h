// =========================================================================================
// Adnd1 - rules/oaarmordesc.h
// ARMOR PROSE AND DESCRIPTIONS, printed capture pp. 93-97 - the OA armor
// descriptions round
// census 571 -> 572.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the section -
// the armor prose and the description entries cross-checked
// paragraph-by-paragraph between the two passes (the intro on capture p. 93,
// the suits-and-pieces doctrine and the corselet example on p. 94, the
// averaging and piece-combination rules on p. 95, the nineteen description
// entries on pp. 96-97 of the print pass); every printed number agrees - zero
// contested cells. The doctrine pins as consts and bools: all armor falls
// into two groups, suits and pieces, with the common suit list (padded,
// leather, studded leather, leather scale, chain mail, brigandine), the rare
// list (metal scale, splint, banded, laced) and the virtually-unknown list
// (plate, field plate, full plate) as counts with the names riding the
// comments; a suit's type sets the armor class via the Table 52 grid pinned
// in R643; the corselet example pins AC 7 equal to studded leather and the
// printed piece examples pin kote-only AC 9 and kote-do-maru-haidate AC 6,
// cross-checking the Table 53 steps pinned in R644; the averaging doctrine,
// the no-general-protection rule for the specialized small pieces, the
// o-yoroi-below-the-pieces-combined rule, the one-piece-per-area rule and the
// no-pieces-with-suits rule pin as bools. The description entries pin their
// printed numbers as consts - the horo back-missile bonus of 1, the kabuto
// head armor class 3, the sode one foot square, the o-yoroi six included
// pieces and five smaller pieces - and their categorical rules as bools: the
// buckler same-hand rule, the chain-under-clothing detection rule, the
// do-maru lamellar rule, the kote under-robes rule, the hara-ate-gawa leather
// rule, the hara-ate rear-attacks-AC-10 rule (the prose mirror of the R644
// star pair), the haramaki and haramaki-do concealability split, the
// hide-better-than-leather rule, the horo riding-only and no-other-use rules,
// the sode-needs-a-corselet rule, the o-yoroi matched-set rule, the scale
// commoner split, the shields-lighter rule, the sune-ate crippling-blow rule,
// and the movement drop with the o-yoroi floor. The hanburi, haidate, kabuto
// and jingasa flavor text rides the banner and comments. The shared OCR slips
// settle per the R643 branded-mail pattern - a read contradicting its own
// page does not stand: the print Hare-ate and here-ate reads are slips
// against the print pass's own Table 53 (hara-ate, corroborated by the
// compressed pass), the compressed Hanburt is a slip against the print
// Hanburi, and the print suns-ate, sods, Bode and Kate reads are slips
// corroborated by the compressed pass (sune-ate, sode, kote). The Table 52,
// 53, 54 and 55 grids stay with their rounds - R643 through R646. This is the
// last Chapter 5 box
//
// the gap census after this round: 100 closed, 135 open - the armor prose and
// armor descriptions box flips (census 571 -> 572); NEXT - R650: the Chapter
// 6 Proficiencies arc begins - the weapon proficiencies and weapon
// specialization prose (capture pp. 100-101), prefix dhk (verify free), audit
// "R650 OA proficiencies audit", include after rules/oaarmordesc.h - the
// Chapter 6 boxes at HEAD name the exact labels
//
namespace rules {

// ---- the suits-and-pieces doctrine pins ----

// all armor falls into one of two general groups - suits and pieces (capture
// p. 94 of the print pass; compressed p. 49)
inline int dhjArmorGroupCount()
    { return 2; }

// the most common suits of armor - padded, leather, studded leather, leather
// scale, chain mail and brigandine, the names riding this comment (capture p.
// 94 of the print pass; compressed p. 49)
inline int dhjCommonSuitCount()
    { return 6; }

// rare suits - metal scale mail, splint mail, banded mail and laced armor,
// the names riding this comment (capture p. 94 of the print pass; compressed
// p. 49)
inline int dhjRareSuitCount()
    { return 4; }

// virtually unknown suits - plate mail, field plate and full plate armor, the
// names riding this comment (capture p. 94 of the print pass; compressed p.
// 49)
inline int dhjUnknownSuitCount()
    { return 3; }

// the most common types of armor in Kara-Tur are of cloth and leather - the
// foot soldier's quilted cotton or padded leathers, the higher ranks'
// hardened leather scales or brigandine (capture p. 94 of the print pass;
// compressed p. 49)
inline bool dhjClothLeatherCommon()
    { return true; }

// thick metal armor such as field plate is seldom seen in Kara-Tur - the
// armorers make great use of leather, brigandine, mail and lamellar
// constructions (capture p. 93 of the print pass; compressed p. 49)
inline bool dhjFieldPlateSeldom()
    { return true; }

// pieces of armor are made of laced armor and come in a variety of shapes and
// colors, each piece providing some amount of protection to the wearer
// (capture p. 94 of the print pass; compressed p. 49)
inline bool dhjPiecesAreLaced()
    { return true; }

// when a character is wearing a suit of armor, the type of armor determines
// the armor class - the Table 52 grid pinned in R643 (capture p. 94 of the
// print pass; compressed p. 49)
inline bool dhjSuitSetsAc()
    { return true; }

// ---- the piece-combination pins ----

// a corselet of laced armor, covering the chest, back and shoulders, is armor
// class 7 - equal to studded leather armor, the prose cross-check of the R643
// T52 row (capture p. 94 of the print pass; compressed p. 49)
inline int dhjCorseletAc()
    { return 7; }

// a character wearing only kote has armor class 9 - the printed piece
// example, 10 minus the kote step of the R644 T53 grid (capture p. 95 of the
// print pass; compressed pp. 49-50)
inline int dhjKoteOnlyAc()
    { return 9; }

// a character wearing kote, do-maru and haidate has armor class 6 - the
// second printed piece example, 10 minus the 1, 2 and 1 steps of the R644 T53
// grid (capture p. 95 of the print pass; compressed p. 50)
inline int dhjKoteDomaruHaidateAc()
    { return 6; }

// the armor class rating averages the exposed and unexposed areas and the
// referee uses the averaged values - the specific armor worn on an area
// counts only in rare cases: striking from behind, stepping on a caltrop,
// striking at the only exposed part (capture pp. 94-95 of the print pass;
// compressed p. 49)
inline bool dhjAveragedAc()
    { return true; }

// a full suit of laced armor includes a number of smaller pieces whose uses
// are so specialized they afford no general protection when worn alone
// (capture p. 95 of the print pass; compressed p. 50)
inline bool dhjSpecialNoGeneral()
    { return true; }

// a full suit of laced armor - the o-yoroi - has a lower armor class than the
// individual pieces combined (capture p. 95 of the print pass; compressed p.
// 50)
inline bool dhjOyoroiBelowPieces()
    { return true; }

// each piece of armor covers a particular area and only one piece can be worn
// on any area - kote, haidate, haramaki-do and sode can be worn together, but
// not a do-maru and a haramaki-do, since each covers the same area (capture
// p. 95 of the print pass; compressed p. 50)
inline bool dhjOnePiecePerArea()
    { return true; }

// armor pieces, since they are carefully fitted and fastened, cannot be worn
// with suits of armor (capture p. 95 of the print pass; compressed p. 50)
inline bool dhjPiecesNotWithSuits()
    { return true; }

// ---- the armor description entry pins ----

// the buckler is a small shield strapped to the arm close to the fist, worn
// while still using a weapon in the same hand, and counts as a small shield
// for armor purposes - commonly used by the horse nomads of Kara-Tur (capture
// p. 96 of the print pass; compressed p. 50)
inline bool dhjBucklerSameHand()
    { return true; }

// chain mail worn under clothing is difficult to detect - it is used to make
// kote and its suits are worn by ninja and nobles both (capture p. 96 of the
// print pass; compressed p. 50)
inline bool dhjChainConcealable()
    { return true; }

// the do-maru is a corselet covering the stomach, chest, shoulders and back,
// normally made of lamellar - laced - armor, its small tassels overlapping
// the haidate (capture p. 96 of the print pass; compressed p. 50)
inline bool dhjDomaruLamellar()
    { return true; }

// the kote - armored sleeves from the shoulders to the backs of the hands -
// can be worn inconspicuously under robes and in combinations with other
// pieces of armor (capture p. 97 of the print pass; compressed p. 50)
inline bool dhjKoteUnderRobes()
    { return true; }

// the hara-ate-gawa is a simple leather corselet for the stomach, chest and
// back, cheap to make and normally worn by common foot soldiers (capture p.
// 96 of the print pass; compressed p. 50)
inline bool dhjHaraateGawaLeather()
    { return true; }

// the hara-ate protects the front of the body - it is open in the back and
// attacks from the rear are treated as armor class 10, the prose mirror of
// the R644 T53 star pair (capture p. 96 of the print pass; compressed p. 50)
inline bool dhjHaraateRearAc10()
    { return true; }

// the haramaki - the belly protector of silk and chain mail or small metal
// plates - is not bulky and can be easily worn under clothing (capture p. 96
// of the print pass; compressed p. 50)
inline bool dhjHaramakiConcealable()
    { return true; }

// the haramaki-do is similar in construction and design to the haramaki, but
// it cannot be concealed under clothing (capture p. 96 of the print pass;
// compressed p. 50)
inline bool dhjHaramakidoExposed()
    { return true; }

// hide armor is made of the hide of particularly thick-skinned creatures -
// elephant and rhinoceros hide the most common - giving better protection
// than normal leather (capture p. 96 of the print pass; compressed p. 50)
inline bool dhjHideBetterThanLeather()
    { return true; }

// the horo improves the wearer's armor class by 1 against missile weapons
// shot at the back of the character only (capture pp. 96-97 of the print
// pass; compressed p. 50)
inline int dhjHoroMissileAc()
    { return 1; }

// the cloth horo is effective only when the wearer is riding - the wind
// balloons it out behind the rider - unless a wicker skeleton is worn
// underneath, allowing it to work at all times (capture p. 96 of the print
// pass; compressed p. 50)
inline bool dhjHoroRidingOnly()
    { return true; }

// the horo has no other protective use beyond the back-missile bonus -
// usually brightly colored and decorated with the crest of the owner (capture
// p. 97 of the print pass; compressed p. 50)
inline bool dhjHoroNoOtherUse()
    { return true; }

// the kabuto gives armor class 3 to the head of the wearer (capture p. 97 of
// the print pass; compressed p. 50)
inline int dhjKabutoHeadAc()
    { return 3; }

// the sode is normally about one foot square, square or rectangular in shape
// (capture p. 97 of the print pass; compressed p. 50)
inline int dhjSodeSideFeet()
    { return 1; }

// the sode is fastened by cords to the other pieces of armor, particularly
// the corselet - it can never be worn without the do-maru, hara-ate, haramaki
// or haramaki-do (capture p. 97 of the print pass; compressed p. 50)
inline bool dhjSodeNeedsCorselet()
    { return true; }

// the o-yoroi is a complete suit of laced armor including kote, do-maru,
// sode, haidate, kabuto and sune-ate - six pieces, the names riding this
// comment (capture p. 97 of the print pass; compressed p. 50; the print sods
// and suns-ate reads are OCR slips)
inline int dhjOyoroiPieceCount()
    { return 6; }

// the o-yoroi also includes the smaller specialized pieces - the mempo face
// mask, nodawa neck guard, wakibiki armpit guards, and the sendan-no-ita and
// hato-wo-no-ita front-of-armpit guards - five pieces, the names riding this
// comment (capture p. 97 of the print pass; compressed p. 50)
inline int dhjOyoroiSmallCount()
    { return 5; }

// the o-yoroi is made as a matched set, the colors and patterns complimenting
// each other - the improved fit gives a better armor class than a collection
// of unmatched pieces; expensive and highly decorative, it is worn for
// ceremonial occasions or major battles, seldom in everyday situations
// (capture p. 97 of the print pass; compressed p. 50)
inline bool dhjOyoroiMatchedBetter()
    { return true; }

// two types of scale armor are in common use - leather scale and metal scale,
// the names riding this comment (capture p. 97 of the print pass; compressed
// p. 50)
inline int dhjScaleTypeCount()
    { return 2; }

// leather scale is worn by common soldiers and horsemen; metal scale is made
// the same way but is far less common, most often worn by wealthier or more
// important warriors (capture p. 97 of the print pass; compressed p. 50)
inline bool dhjScaleLeatherCommoner()
    { return true; }

// shields vary by land - in some lands never used at all - and nearly all are
// of lighter construction than those of other AD&D game lands; the materials
// - woven bamboo and wicker, stretched and hardened leather, coconut fiber or
// hemp - ride the banner, and metal-edged wooden shields are extremely rare
// (capture p. 97 of the print pass; compressed pp. 50-51)
inline bool dhjShieldsLighter()
    { return true; }

// the sune-ate is a shin guard from the top of the ankle to the bottom of the
// knee, normally splints of metal on leather padding, protecting against
// crippling blows to the lower leg (capture p. 97 of the print pass;
// compressed p. 51)
inline bool dhjSuneateCrippling()
    { return true; }

// when several pieces of armor are worn, the movement rate drops to the next
// lower category (capture p. 97 of the print pass; compressed p. 51)
inline bool dhjPieceMovementDrop()
    { return true; }

// the movement rate of several worn pieces never falls below that of the
// o-yoroi - the floor rule (capture p. 97 of the print pass; compressed p.
// 51)
inline bool dhjMovementFloorOyoroi()
    { return true; }

}   // namespace rules
