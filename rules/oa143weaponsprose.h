// =========================================================================================
// Adnd1 - rules/oa143weaponsprose.h
// OA WEAPONS PROSE - THE FORTY-SEVEN WEAPON DESCRIPTIONS, printed capture pp.
// 84-93 - the last open box closes
// census 694 -> 695.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift (the descriptions re-captured at pp. 42-51 of the
// compressed-3 re-upload)
//
// the gap census after this round: 235 closed, 0 open - THE OA BOOK CLOSES
// (the Weapons prose box flips; census 694 -> 695); NEXT - R773: the
// oa_gap_report.md is empty - the post-OA maintenance audit, the next target
// awaits Curtiss's call
//
namespace rules {

// ---- the arrows, bows, and crossbows ----

// the five arrow types - the wedge head, the narrow spike-head armor piercer,
// the v frog crotch cutting standards and cords, the whistling humming bulb
// signal arrow doubling as the 1-3 damage fire arrow, and the broad leaf head
// with its carved artistic designs (print capture pp. 84-93)
inline int dnjArrowsDoctrine()
    { return 1; }

// the daikyu - the largest bow, seven feet and bent at the ends, the
// off-center grip allowing fire from horseback and kneeling (print capture
// pp. 84-93)
inline int dnjDaikyuDoctrine()
    { return 1; }

// the pellet bow - the bow with the small sling in the bowstring holding a
// stone or clay or lead pellet, fired with more force than a sling (print
// capture pp. 84-93)
inline int dnjPelletBowDoctrine()
    { return 1; }

// the chu-ko-nu - the repeating light crossbow with its 10-quarrel magazine
// worked by a single lever, faster fire but heavier and poorer range, and no
// firing and reloading in the same round (print capture pp. 84-93)
inline int dnjChuKoNuDoctrine()
    { return 1; }

// the chu-ko-nu magazine capacity - up to 10 quarrels held in the top
// magazine (print capture pp. 84-93)
inline int dnjChuKoNuMagazineQuarrels()
    { return 10; }

// the chu-ko-nu reload rate - up to two quarrels reloaded into the magazine
// per round (print capture pp. 84-93)
inline int dnjChuKoNuReloadPerRound()
    { return 2; }

// the chu-ko-nu full reload - five rounds required to completely reload the
// magazine (print capture pp. 84-93)
inline int dnjChuKoNuFullReloadRounds()
    { return 5; }

// ---- the swords ----

// the boku-toh - the wooden katana copy for practice, still able to injure
// from the force of the blow (print capture pp. 84-93)
inline int dnjBokuTohDoctrine()
    { return 1; }

// the katana - the single-edged slightly curved chisel-point sword of
// superior construction, the weapon-smith's rare art, light and
// well-balanced, razor-sharp, often decorated and often carrying individual
// names of glory (print capture pp. 84-93)
inline int dnjKatanaDoctrine()
    { return 1; }

// the katana honor doctrine - the sword as the samurai's personal weapon and
// family honor, the touch of the scabbard and the unpermitted draw as
// insults, the generational heirloom, the loss a disgrace swept clean only by
// recovery and punishment, and the price varying with workmanship and history
// (print capture pp. 84-93)
inline int dnjKatanaHonorDoctrine()
    { return 1; }

// the ninja-to - the ninja's straight lower-quality short sword with the
// multi-use scabbard, the secret compartments, the open-ended blowpipe or
// breathing tube, the climbing silk cord, and the DM-allowed hidden devices
// (print capture pp. 84-93)
inline int dnjNinjaToDoctrine()
    { return 1; }

// the wakizashi - the short sword matching the katana in design and naming,
// the daisho long-and-short pair worn only by samurai under penalty of arrest
// or execution, with the katana rules applying to the matched set (print
// capture pp. 84-93)
inline int dnjWakizashiDoctrine()
    { return 1; }

// ---- the chains and ropes ----

// the chain - the manriki-gusari or rante, a weighted length of chain for
// whirling blows, entangling, or bola-like throwing, worn as a belt or under
// a sash and favored by ninjas (print capture pp. 84-93)
inline int dnjChainDoctrine()
    { return 1; }

// the kau sin ke - the whipping chain of four to six short iron bars joined
// by chain links, the agricultural-flail origin, the bars wrapping around
// shields to land crushing blows (print capture pp. 84-93)
inline int dnjKauSinKeDoctrine()
    { return 1; }

// the kawanaga - the rope with the grappling hook at one end and the weight
// at the other, a climbing tool doubling as a swinging or entangling weapon
// popular with ninjas (print capture pp. 84-93)
inline int dnjKawanagaDoctrine()
    { return 1; }

// the kyoketsuogi - the rope with the sharp hooked blade at one end and the
// heavy iron ring at the other, swung, snapped to entangle, thrown like a
// bola, or held while striking with the knife, nearly silent and easily
// concealed (print capture pp. 84-93)
inline int dnjKyoketsuogiDoctrine()
    { return 1; }

// the kusari-gama - the sickle developed for fighting with the weighted chain
// on the handle butt, attacking with the kama, clubbing and entangling with
// the chain, or whirling the kama at the chain's end, easy to make and
// favored by peasants and ninjas (print capture pp. 84-93)
inline int dnjKusariGamaDoctrine()
    { return 1; }

// the lasso - the no-damage entangling weapon, the saving throw versus poison
// to cut free, the automatic dismount without horsemanship, the pull-off-feet
// chance for lighter bipedal creatures, the combined pullers, and the bend
// bars attempt against the line (print capture pp. 84-93)
inline int dnjLassoDoctrine()
    { return 1; }

// the lasso line durability - the line can take 2 points of cutting damage
// (print capture pp. 84-93)
inline int dnjLassoLineCuttingDamage()
    { return 2; }

// the lasso pull chance - the bipedal creature on foot and no more than half
// the wielder's weight pulled off its feet 25 percent of the time (print
// capture pp. 84-93)
inline int dnjLassoBipedalPullPercent()
    { return 25; }

// the lasso extra-puller bonus - roughly 20 percent per additional creature
// pulling on the rope (print capture pp. 84-93)
inline int dnjLassoExtraPullerBonusPercent()
    { return 20; }

// ---- the flails and the farmers' tools ----

// the kama - the straight-bladed farmer's sickle carried without suspicion
// and used to great effect by ninjas (print capture pp. 84-93)
inline int dnjKamaDoctrine()
    { return 1; }

// the nunchaku - the two-handed martial-arts flail of two lengths joined by
// chain or cord, parrying, clubbing, and catching weapons, easily concealed
// (print capture pp. 84-93)
inline int dnjNunchakuDoctrine()
    { return 1; }

// the three-piece rod - the martial-arts flail of three two-to-three-foot
// pieces of hard wood joined by short chains, striking, blocking, and
// catching or breaking weapons in trained hands and useless otherwise (print
// capture pp. 84-93)
inline int dnjThreePieceRodDoctrine()
    { return 1; }

// the parang - the tribesman's heavy-bladed machete of chopping force, a tool
// and weapon in one (print capture pp. 84-93)
inline int dnjParangDoctrine()
    { return 1; }

// the kumade - the rake-headed climbing pole doubling as a weapon, a common
// ninja item for its innocent uses (print capture pp. 84-93)
inline int dnjKumadeDoctrine()
    { return 1; }

// the kiseru - the metal tobacco pipe whose innocent look hides its clubbing
// use, cheap and popular with peasants and monks (print capture pp. 84-93)
inline int dnjKiseruDoctrine()
    { return 1; }

// the tui-fa or tonfa - the hardwood rod with the off-center millstone-handle
// grip, blocking, catching, breaking, and attacking in trained hands, used
// where normal weapons are barred (print capture pp. 84-93)
inline int dnjTuiFaDoctrine()
    { return 1; }

// ---- the spears and polearms ----

// the chijiriki - the spear with a weighted chain on the butt end, used as a
// spear or swung to entangle (print capture pp. 84-93)
inline int dnjChijirikiDoctrine()
    { return 1; }

// the lajatang - the rare three-to-five-foot shaft with a crescent blade at
// each end, some with downward barbs, wielded two-handed like a staff by the
// skilled martial artist (print capture pp. 84-93)
inline int dnjLajatangDoctrine()
    { return 1; }

// the nagimaki - the shortened naginata used by horsemen (print capture pp.
// 84-93)
inline int dnjNagimakiDoctrine()
    { return 1; }

// the naginata - the lightweight but strong six-to-eight-foot glaive ending
// in the curved sword-like blade, the standard polearm often preferred by
// women (print capture pp. 84-93)
inline int dnjNaginataDoctrine()
    { return 1; }

// the sang kauw - the double-headed spear with the loop handle and its dagger
// or crescent projection, one-hand parry and attack, the second buckler form
// counting as a small shield, and the great training required (print capture
// pp. 84-93)
inline int dnjSangKauwDoctrine()
    { return 1; }

// the shakujo yari - the spear sheathed to look like a staff, used as a bo
// stick when sheathed and carried to look defenseless (print capture pp.
// 84-93)
inline int dnjShakujoYariDoctrine()
    { return 1; }

// the shikomi-zue - the staff concealing the spring spear head, doing bo
// stick or spear damage, and hiding other weapons inside (print capture pp.
// 84-93)
inline int dnjShikomiZueDoctrine()
    { return 1; }

// the tetsubo - the iron-shod rod, the polearm mace of the long wooden rod
// wielded with two hands, doubling as a traveler's walking stick (print
// capture pp. 84-93)
inline int dnjTetsuboDoctrine()
    { return 1; }

// the fang - the heavy iron elephant-goad weapon of short-sword length, the
// sharp point with the heavy hooked point below (print capture pp. 84-93)
inline int dnjFangDoctrine()
    { return 1; }

// the man catcher - the two-pronged pole arm encircling man-sized creatures,
// the size limits, the spikes and sharpened edges, the lost shield and
// dexterity bonuses, the push and pull damage, the bend bars escape, and the
// rescue by chopping the haft (print capture pp. 84-93)
inline int dnjManCatcherDoctrine()
    { return 1; }

// the man catcher pull chance - the 25 percent chance the caught victim is
// pulled off his feet to a kneeling or prone position (print capture pp.
// 84-93)
inline int dnjManCatcherOffFeetPercent()
    { return 25; }

// the man catcher haft durability - 6 points of cutting damage required to
// chop through the haft for a rescue (print capture pp. 84-93)
inline int dnjManCatcherHaftCuttingDamage()
    { return 6; }

// the sode garami - the sleeve entangler, the pole and crossbar of spikes and
// hooks catching clothing without harm, the saving throw versus paralyzation
// to escape, and the constables' and palace guards' carry (print capture pp.
// 84-93)
inline int dnjSodeGaramiDoctrine()
    { return 1; }

// ---- the knives and throwing weapons ----

// the shaken - the shuriken-like throwing weapon used in the same way (print
// capture pp. 84-93)
inline int dnjShakenDoctrine()
    { return 1; }

// the shuriken - the small throwing weapon of stars with three or more
// razor-edged points in large and small sizes and the tapering spike pins,
// easily concealed in clothing, sashes, or hair (print capture pp. 84-93)
inline int dnjShurikenDoctrine()
    { return 1; }

// the shuriken star point minimum - the stars have three or more razor-edged
// points so at least one strikes (print capture pp. 84-93)
inline int dnjShurikenStarPointMinimum()
    { return 3; }

// the needle - the mouth-carried needles fired by spitting or blowing, singly
// or in bursts, of poor range and almost never effective against armor, a
// dishonorable weapon of surprise and distraction (print capture pp. 84-93)
inline int dnjNeedleDoctrine()
    { return 1; }

// the needle mouth-carry maximum - up to 20 needles carried in the mouth
// (print capture pp. 84-93)
inline int dnjNeedleMouthCarryMax()
    { return 20; }

// the needle all-fired die - when all 20 are fired at once, 1d20 rolled for
// the damage (print capture pp. 84-93)
inline int dnjNeedleAllFiredDieSides()
    { return 20; }

// the siangkam - the metal-shafted arrow with the wooden handle, used in
// pairs to jab, thrust, slash, and parry, and never thrown effectively,
// needing the trained martial-arts style (print capture pp. 84-93)
inline int dnjSiangkamDoctrine()
    { return 1; }

// the uchi-ne - the short heavy javelin looking like a miniature arrow,
// thrown short distances or used for thrusting, often carried by traveling
// nobles (print capture pp. 84-93)
inline int dnjUchiNeDoctrine()
    { return 1; }

// ---- the ninja tools ----

// the metsubishi - the wooden powder blower with its mouthpiece, chamber, and
// tube, doing no damage but incapacitating on a failed save, used by ninjas
// and city constables (print capture pp. 84-93)
inline int dnjMetsubishiDoctrine()
    { return 1; }

// the metsubishi incapacitation - the failed save incapacitating for 1-6
// rounds, the maximum six (print capture pp. 84-93)
inline int dnjMetsubishiIncapacitationMaxRounds()
    { return 6; }

// the nekode - the climbing spikes worn on straps or gloves, also clawing an
// opponent for small damage while leaving the hands free (print capture pp.
// 84-93)
inline int dnjNekodeDoctrine()
    { return 1; }

// the nekode climb bonus - the climbing chance increased by 5 percent when
// the spikes are jammed into cracks (print capture pp. 84-93)
inline int dnjNekodeClimbBonusPercent()
    { return 5; }

// the tetsu-bishi - the caltrops of the four-sided spiked diamond cast on the
// ground to stop pursuit, the area rules with the base count and the saving
// throw versus paralyzation, the halved-count and per-five penalties, the
// fast-movement and cautious-move rules, and the lamed-aftermath watch (print
// capture pp. 84-93)
inline int dnjTetsubishiDoctrine()
    { return 1; }

// the tetsu-bishi base count - the base amount of 10 cast down in the area
// (print capture pp. 84-93)
inline int dnjTetsubishiBaseCount()
    { return 10; }

// the tetsu-bishi base area - the 5 by 5 foot area, 25 square feet covered by
// the base count (print capture pp. 84-93)
inline int dnjTetsubishiBaseAreaSquareFeet()
    { return 25; }

// the tetsu-bishi halved-count penalty - the victim gains a -4 on the saving
// throw when half the base amount is used (print capture pp. 84-93)
inline int dnjTetsubishiHalfCountSavePenalty()
    { return 4; }

// the tetsu-bishi per-five penalty - for every 5 above the base count the
// saving throw is reduced by 2 (print capture pp. 84-93)
inline int dnjTetsubishiPerFiveExtraSavePenalty()
    { return 2; }

// the tetsu-bishi step damage - the stepped-on victim suffering 1-4 points of
// damage, the maximum four (print capture pp. 84-93)
inline int dnjTetsubishiStepDamageMax()
    { return 4; }

// the tetsu-bishi lame watch - the failed second save leaving the victim at
// one-third movement for 24 hours or until healed (print capture pp. 84-93)
inline int dnjTetsubishiLameDurationHours()
    { return 24; }

// ---- the sticks, the emergency, and the odd ----

// the bo stick - the 6 to 7 foot hard-wood staff, difficult to cut or break
// (print capture pp. 84-93)
inline int dnjBoStickDoctrine()
    { return 1; }

// the chopsticks - an emergency weapon, not very effective but better than
// nothing (print capture pp. 84-93)
inline int dnjChopsticksDoctrine()
    { return 1; }

// the gunsen - the iron war fan, defensive as a small shield and normally a
// weapon of emergency (print capture pp. 84-93)
inline int dnjGunsenDoctrine()
    { return 1; }

// the jitte - the defensive tapered iron bar with the short hook near the
// handle, blocking attacks and catching weapons (print capture pp. 84-93)
inline int dnjJitteDoctrine()
    { return 1; }

// the sai or tjabang - the martial-arts jitte almost identical in use, the
// two projecting prongs instead of one (print capture pp. 84-93)
inline int dnjSaiDoctrine()
    { return 1; }

// the jo stick - the one-hand smaller bo stick of the same wood, often used
// in pairs (print capture pp. 84-93)
inline int dnjJoStickDoctrine()
    { return 1; }

// the whip - the weapon needing exposed or lightly covered flesh, the heavy
// clothing and thick hide protections, and the entangle use often more
// effective than the damage (print capture pp. 84-93)
inline int dnjWhipDoctrine()
    { return 1; }

}   // namespace rules
