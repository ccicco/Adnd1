// =========================================================================================
// Adnd1 - rules/oa144dailylife.h
// OA DAILY-LIFE MISSES - DRESS, RELIGION, AND LAW AND JUSTICE, printed
// capture pp. 306-312 - the audit-found gaps close
// census 695 -> 696.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift (the text re-captured at pp. 139-142 of the compressed-3
// re-upload and pp. 305-312 of the original-scan OCR)
//
// the gap census after this round: 238 closed, 0 open - the three audit-found
// boxes seat closed (census 695 -> 696); NEXT - R774: the next target awaits
// Curtiss's call
//
namespace rules {

// ---- the dress materials and colors ----

// the clothing status doctrine - clothing as practicality plus the
// identification of rank, the decoration quality and materials indicating the
// wearer's status (print capture pp. 306-312)
inline int dmkClothingStatusDoctrine()
    { return 1; }

// the common clothing materials - cotton and silk the most common (print
// capture pp. 306-312)
inline int dmkCommonMaterials()
    { return 1; }

// the regional lower-class materials - pounded tree bark, flax, wool, woven
// horse-hair, furs, paper, and hemp, confined to specific regions and the
// lower classes (print capture pp. 306-312)
inline int dmkRegionalMaterials()
    { return 1; }

// the regional material count - seven lower-class materials: pounded tree
// bark, flax, wool, woven horse-hair, furs, paper, and hemp (print capture p.
// 306)
inline int dmkRegionalMaterialCount()
    { return 7; }

// the leather doctrine - heavy leathers for durability, soft deerskin for
// flexibility or lavish decoration (print capture pp. 306-312)
inline int dmkLeatherDoctrine()
    { return 1; }

// the white mourning rule - white the color of mourning, so nearly all cloth
// is dyed, the dyes from flowers, nuts, barks, woods, and minerals (print
// capture pp. 306-312)
inline int dmkWhiteMourning()
    { return 1; }

// the common colors - browns, ochres, yellows, grays, and blues common, the
// brighter greens, pinks, and reds rarer and worn by the higher station
// (print capture pp. 306-312)
inline int dmkCommonColors()
    { return 1; }

// the common color count - five common dye colors: browns, ochres, yellows,
// grays, and blues (print capture p. 306)
inline int dmkCommonColorCount()
    { return 5; }

// ---- the clothing and the footwear ----

// the trouser doctrine - the short wrap-around cotton trousers tied with
// strings, loose for wading the paddies, striped or patterned, the peasant
// wear of both sexes (print capture pp. 306-312)
inline int dmkTrouserDoctrine()
    { return 1; }

// the robe doctrine - the commoners' short belted robe; the wealthier
// omitting trousers for long robes; the nobility's layered robes of different
// colors peeking at sleeves and collar, an art of the ladies' court; the wide
// open sleeves as cold-weather muffs since gloves are not worn and as pockets
// for handkerchief and cash (print capture pp. 306-312)
inline int dmkRobeDoctrine()
    { return 1; }

// the mino raincloak - the peasants' rain cloak of layered straw (print
// capture pp. 306-312)
inline int dmkMinoRaincloak()
    { return 1; }

// the footwear doctrine - the woven straw sandal simplest and most common;
// the straw or wooden-block sandals of Kozakura; the soft-leather or cloth
// slippers of the refined and the soldiers' short boots of Shou Lung and T'u
// Lung; the fur-wrapped leather boots of the cold north (print capture pp.
// 306-312)
inline int dmkFootwearDoctrine()
    { return 1; }

// the hat doctrine - hats a clear sign of status; the peasants' round
// broad-rimmed straw or bamboo hats doubling as baskets; the shukenja and
// monks' basket hats; the nobles' small styled hats; the gentlemen's
// huge-rimmed horsehair hats; the scarf or cloth for rain (print capture pp.
// 306-312)
inline int dmkHatDoctrine()
    { return 1; }

// ---- the beauty and the hair ----

// the male beauty doctrine - grace and beauty the pride of men of rank, the
// pale complexion best, the plucked eyebrows, the perfume-mixing skill, most
// falling short of the ideal (print capture pp. 306-312)
inline int dmkMaleBeauty()
    { return 1; }

// the female beauty doctrine - the blackened teeth as standard with the
// pearly white smile an unfortunate flaw of the west, the plucked and
// repainted thin-line eyebrows, the powdered palest faces (print capture pp.
// 306-312)
inline int dmkFemaleBeauty()
    { return 1; }

// the hair doctrine - the topknot of rank held with carved pins, the Kozakura
// topknot-cutting punishment for minor offenses shaming the man before his
// lord; the children's single lock, crown for boys and ear for girls; the
// samurai's coming-of-age forehead shave; the peasants' queue; the women's
// long flowing hair as beauty and station, cut short in mourning or upon the
// nun's veil; the priests' shaven heads (print capture pp. 306-312)
inline int dmkHairDoctrine()
    { return 1; }

// ---- the religions ----

// the no-church concept - the average man not attending, the church as a
// separate entity strange to him, religion organized on such a scale
// nonexistent, yet piety and respect intact (print capture pp. 306-312)
inline int dmkNoChurchConcept()
    { return 1; }

// the named religion count - five named: The Way, The Path of Enlightenment,
// The Eight Million Gods, ancestor worship, and the cult of the state (print
// capture p. 310)
inline int dmkNamedReligionCount()
    { return 5; }

// the many-religions practice - few commoners follow strictly one religion,
// taking no chances, making offerings, hearing sermons, celebrating holy
// days, and praying at the temples of many different religions without it
// being unusual (print capture pp. 306-312)
inline int dmkManyReligionsPractice()
    { return 1; }

// the tolerance doctrine - the religions extremely tolerant of one another,
// temples side by side, sects adopting other practices and re-explaining
// them, minor gods adopted as forms of deities already worshiped, the clergy
// alone faithful to one (print capture pp. 306-312)
inline int dmkReligiousTolerance()
    { return 1; }

// the sect doctrine - the sects sharing goals but disputing methods, the
// chanting phrases, the different phrase, the breathing and physical
// exercises, the fierce rivalries, feuds, and violent clashes, sects of the
// same religion often more hostile to each other than to entirely different
// religions (print capture pp. 306-312)
inline int dmkSectDoctrine()
    { return 1; }

// ---- the court ----

// the court structure - the law court of every province and major city headed
// by the magistrate with broad powers, the scholar by examinations, the noble
// appointee, the daimyo, the sage, or the village headman, with bailiff,
// constables, outcast assistants, and secretaries (print capture pp. 306-312)
inline int dmkCourtStructure()
    { return 1; }

// the evidence gathering - the bailiff and constables gathering evidence and
// holding it, arresting or ordering witnesses, no protection from arrest save
// the displeasure of the magistrate, and the trial date set with little delay
// (print capture pp. 306-312)
inline int dmkEvidenceGathering()
    { return 1; }

// the no-lawyers trial - the accused and accuser stating their cases, the
// magistrate asking all questions, the ordered beatings and torture to aid
// memory and for the out-of-order, the witnesses questioned with force to
// extract testimony, the bailiff keeping order and administering the beatings
// (print capture pp. 306-312)
inline int dmkNoLawyers()
    { return 1; }

// the speak-with-dead testimony - the murder-case spellcaster summoned, the
// dead's testimony accepted as fact, spells determining the truth of
// statements, the secretaries stating the laws and previous cases (print
// capture pp. 306-312)
inline int dmkSpeakWithDeadTestimony()
    { return 1; }

// the class double standard - the higher rank receiving special
// considerations, the commoner's crimes not crimes for the warrior class, the
// Kozakuran samurai's right to cut down an insulting or truculent commoner
// without a murder charge, the vendetta with approvals, yet gambling and
// drunkenness more severe for the samurai who has broken his trust (print
// capture pp. 306-312)
inline int dmkClassDoubleStandard()
    { return 1; }

// ---- the punishments and the settlements ----

// the punishment doctrine - punishments fixed by law with the magistrate's
// power to alter severity, the commoner punishments of execution, branding,
// loss of the hands, fines, imprisonment, banishment, slavery, the heavy
// yoke, and the public announcements, the higher classes' house arrest,
// banishment, loss of position, and honorable death, the treasonous samurai
// forced to public humiliation in execution (print capture pp. 306-312)
inline int dmkPunishmentDoctrine()
    { return 1; }

// the commoner punishment count - nine: execution, branding, loss of the
// hands, fines, imprisonment, banishment, slavery, the heavy yoke, and public
// announcements (print capture p. 311)
inline int dmkCommonerPunishmentCount()
    { return 9; }

// the higher-class punishment count - four: house arrest, banishment, loss of
// position, and honorable death (print capture p. 311)
inline int dmkHigherClassPunishmentCount()
    { return 4; }

// the civil mediation - the magistrate hearing civil and criminal cases, the
// harsh court treatment driving settlements through the priest or
// village-headman mediator, binding only if both parties agree, else the
// court (print capture pp. 306-312)
inline int dmkCivilMediation()
    { return 1; }

// the collective responsibility - the entire family, village, or group
// punished for the criminal's actions, the banished samurai's family banished
// with him, the murderer's village punished, the commoners loathe to aid
// criminals, the policy effective (print capture pp. 306-312)
inline int dmkCollectiveResponsibility()
    { return 1; }

// ---- the vendetta ----

// the vendetta doctrine - the vendetta officially sanctioned in some lands
// such as Kozakura, a required part of the samurai's honor to avenge the
// murdered or slain relation (print capture pp. 306-312)
inline int dmkVendettaDoctrine()
    { return 1; }

// the vendetta rank rule - the avenger cannot be of higher rank than the
// person slain, the eldest son unable to avenge a younger brother, the direct
// retainer unable to avenge a lesser retainer (print capture pp. 306-312)
inline int dmkVendettaRankRule()
    { return 1; }

// the vendetta approvals - release from the lord's service by application,
// granted if the cause is just and the services not required, the reentry
// with no penalties and perhaps renown, the local government's approval
// normally given with little question but deniable if the hunted is valuable
// or a friend, the unapproved avenger arrested for murder (print capture pp.
// 306-312)
inline int dmkVendettaApproval()
    { return 1; }

// the vendetta duel - with all approvals the challenge to a duel to the death
// at any time, everything legally done so the winner is not charged with
// murder, and any number of seconds assisting so it need not be one-on-one
// (print capture pp. 306-312)
inline int dmkVendettaDuel()
    { return 1; }

}   // namespace rules
