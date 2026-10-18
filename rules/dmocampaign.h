// =========================================================================================
// Adnd1 - rules/dmocampaign.h
// THE REMAINING MAXIMS - DMO Chapter 1 closed: the intelligent-adversary
// doctrines (act as smart as the intelligence says, shield the weaknesses,
// maximize the strengths, handle defeat by motivation), the villain
// self-preservation rules (never be there; bad guys don't fight fair), the
// control-magic doctrines (the AC -4 floor, the 18-hour study vs 37-minute
// cast, no magic shops), the plan-ahead doctrines (villains who learn,
// consequences, fame), and the share-responsibility doctrines (the players as
// the cadre, the goals, the profile).
// census 522 -> 523.
//
// verified against printed pp. 10-29 of the uploaded DMO session capture
// (part 1, printed page N at OCR page N+1); the defeat ladder from p. 13, the
// troll and vampire audits from pp. 12-13, the memorization economics from p.
// 21, the item rate from p. 28; the maxim roster from p. 6 (R599) rides the
// chapter parent.
//
// the gap census after this round: 11 closed, 85 open - EVERY maxim box of
// Chapter 1 is closed; the DMO arc continues with Chapter 2 (Adventures).
//
namespace rules {

// ---- the DMO maxim-doctrine pins ----

// the handling-defeat ladder: four options open to an opponent staring defeat
// in the face - surrender, flee, reversal, or fight (printed p. 13).
inline int dejDefeatOptionCount()
    { return 4; }

// the leaving-the-field doctrine: a successful flee must accomplish three
// things - outrun the PCs, foil their ranged attacks, and elude long-term
// pursuit (printed p. 14).
inline int dejEscapeGoalCount()
    { return 3; }

// the troll regeneration delay: the creature regains no hit points until
// three rounds after it suffers its first wound (printed p. 12).
inline int dejTrollRegenDelayRounds()
    { return 3; }

// the troll strength read: the damage bonus when a troll employs a weapon
// such as a two-handed sword is +8 (printed p. 13).
inline int dejTrollWeaponDamageBonus()
    { return 8; }

// the armor-class tension floor: once characters get below an Armor Class of
// -4 a great deal of the tension dissipates - the heroes are virtually immune
// to most physical attacks (printed p. 19).
inline int dejTensionAcFloor()
    { return -4; }

// the bracers of defense AC 2 grant an effective Armor Class bonus of +8 and
// should be rarer than even magical plate (printed p. 19).
inline int dejBracersAc2Bonus()
    { return 8; }

// the memorization economics: a 20th-level wizard requires 18 hours of study
// time to memorize a full complement of spells (printed p. 21).
inline int dejWizardStudyHours()
    { return 18; }

// the memorization economics, the other half: it takes the same 20th-level
// wizard only 37 minutes to cast every spell in memory (printed p. 21).
inline int dejWizardCastMinutes()
    { return 37; }

// the teleport impracticality: the 5th-level teleport spell requires 50
// minutes of memorization time, making it impractical for any trip that can
// be made in less than an hour by other means (printed p. 21).
inline int dejTeleportMemorizeMinutes()
    { return 50; }

// the teleport risk, the minor accident: even when very familiar with the
// destination there is a 2 percent chance per use of arriving too high
// (printed p. 21).
inline int dejTeleportMinorPct()
    { return 2; }

// the teleport risk, the fatal accident: a 1 percent chance per use of
// teleporting low, potentially fatal (printed p. 21).
inline int dejTeleportFatalPct()
    { return 1; }

// the balancing-act item rate: following the DMG suggestion of three to six
// adventures between levels, a party of six characters should find only about
// one magical item every adventure (printed p. 28).
inline int dejPartyItemPerAdventure()
    { return 1; }

// maxim two, the intelligence review: an opponent has to avoid obvious
// mistakes, not be brilliant - even low-intelligence foes learn from
// experience (the man-eating tiger at Int 2-4), and average-intelligence
// kobolds and goblins are as smart as a typical human (printed pp. 10-11).
inline bool dejIntelligenceDoctrine()
    { return true; }

// the weakness audit: against high-level PCs few allies are expendable, and
// discernible weaknesses (the rakshasa blessed bolt, troll fire and acid,
// vampire sunlight and turning, the giant slug Armor Class) must be shielded
// before the fight - with the prepared advantage explained to the PCs
// (printed pp. 11-12).
inline bool dejWeaknessShielding()
    { return true; }

// the strength audit: maximize the strong points - trolls in waves with fresh
// troops while the hurt regenerate, vampires fighting one-on-one using
// gaseous form and prepared pinholes, giant slugs with stoneskin and hidden
// approaches (printed pp. 12-14).
inline bool dejStrengthMaximization()
    { return true; }

// the handling-defeat doctrine: important NPCs never check morale, only
// rank-and-file troops; the four options ride the motivation - coerced foes
// fight on, magically compelled foes cannot flee, home-front defenders fall
// back to attack again, looters flee at the first difficulty, proud foes
// attempt the dramatic reversal; the surrendering foe keeps a bargaining chip
// (printed pp. 12-17).
inline bool dejHandlingDefeat()
    { return true; }

// the leaving-the-field doctrine: run somewhere the PCs cannot follow, divert
// with illusions or reinforcements, slow pursuit with caltrops and webs; foil
// ranged attacks with cover, broken bows and antimagic shell; foil tracking
// with faint trails, river crossings and changed forms; cover a withdrawal
// with wall spells and rear guards; hit-and-run attackers strike from
// concealment at the spellcasters and the mounted (printed pp. 14-17).
inline bool dejLeavingFieldDoctrine()
    { return true; }

// the reversal doctrine: exploit the opportunity unique to the situation (the
// bridge supports, the flammables, the avalanche), spare the treasure the
// opponent wants intact, hold the potent one-use weapons in reserve, and use
// knowledge of the PCs as a weapon (printed p. 17).
inline bool dejReversalDoctrine()
    { return true; }

// the minimizing-personal-risks doctrine: the safest villain never goes
// anywhere dangerous - henchmen do the dirty work; be somewhere else (project
// image, the magic jar in a servant's hands, posing as a bystander or
// prisoner), or strike where the PCs are vulnerable but absent (their castle,
// their friends, their business associates) (printed pp. 16-18).
inline bool dejVillainSelfPreservation()
    { return true; }

// the bad-guys-don't-fight-fair doctrine: no trick is too low - innocents
// block the area effects, diversions force the PCs to abandon the fight,
// sentimental targets goad emotional decisions, and the villain never meets
// the heroes without an escape route and a hidden advantage (printed p. 18).
inline bool dejBadGuysDontFightFair()
    { return true; }

// maxim three, the control-magic core: too much magic ruins play - the PCs
// become exterminators and the mechanics break down; too little disheartens
// the players; rarity keeps the wonder (a potion momentous, a holy sword no
// big deal when everyone owns two); protective stacking via barter and
// loaning must be watched (printed pp. 17-19).
inline bool dejControlMagicDoctrine()
    { return true; }

// the item-economy doctrine: intelligent opponents use their items against
// the PCs and expend charged items freely when faced with defeat; captured
// items should be nearly drained; item saves are rolled per item when a PC
// fails a save (protections do not extend to equipment); villains demand
// items for ransom; leprechauns, storms at sea and annoyed deities remove
// excess magic (printed pp. 19-20).
inline bool dejMagicItemUseDoctrine()
    { return true; }

// the no-magic-shops doctrine: magic is never a commodity - supplies come
// from specialty shops by barter and haggling with only a reputation as
// guarantee; purchases are pig-in-a-poke adventures (the fake or damaged cube
// of force, the rival's favor-laden loan, the dragon learning of the search);
// the Encyclopedia Magica values set relative worth only (printed pp. 20-21).
inline bool dejMagicShopsDoctrine()
    { return true; }

// the magic-is-unlike-technology doctrine: most spells do one thing and one
// thing only (magic missile harms nothing inanimate, knock opens no
// portcullis); players with modern minds must not be allowed to treat spells
// as adaptable tools (printed p. 21).
inline bool dejMagicLimitationDoctrine()
    { return true; }

// maxim six, the plan-ahead doctrine: prepare the campaign for high-level
// play during low-level play, neither too late nor too soon; create villains
// who learn - the growing villain with ambitions achieved over play, built on
// the six background pillars: source of power, objectives, motives,
// personality, history, allies (printed pp. 24-25).
inline bool dejPlanAheadDoctrine()
    { return true; }

// the consequences doctrine: every adventure has aftereffects - someone is
// left behind to pick up the hoard, word spreads by boasting or witnesses,
// and someone always cares (helped or hurt); the charmed servant of the slain
// dragon is the worked example; simple incidents can hide layer upon layer
// (printed pp. 25-27).
inline bool dejConsequencesDoctrine()
    { return true; }

// the fame-and-infamy ledger: track the PCs' reputation - exaggerated
// accounts of early exploits, blowhards who did know them way back when;
// broken word blocks later land grants and knighthoods (printed p. 27).
inline bool dejFameInfamyDoctrine()
    { return true; }

// the balancing-act doctrine: build the balanced campaign, do not fix a
// runaway one - set the XP rate per DMG Chapter Eight, place the magic in
// advance behind appropriate risks (never the holy avenger for one orc), and
// take the excess out of circulation; the fair rate: one permanent or
// rechargeable item per two or three levels plus one or two consumables per
// two levels (printed p. 28).
inline bool dejBalancingActDoctrine()
    { return true; }

// maxim seven, the share-responsibility doctrine: the players are the cadre
// of helpers - they detail unexplored areas, histories and NPC actions; the
// DM garners their interests and weaves several threads at once (the artifact
// example); long-term character goals beyond wealth and XP; the
// allies-and-enemies ledger with its favors; and the personality profile
// beyond the record sheet (occupation, appearance, quirks, tastes, residence,
// history, friends, enemies, goals) (printed pp. 27-29).
inline bool dejShareResponsibilityDoctrine()
    { return true; }

}   // namespace rules
