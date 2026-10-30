// =========================================================================================
// Adnd1 - rules/t22.h
// The Dragon issue-22 opener part one - the assassin order history, the Swiss
// military doctrine and the Renaissance armies overview
// census 868 -> 869.
//
// The opener of the issue-22 four-round shape - three of the nine
// Curtiss-called chains pinned as the military-history triptych, the DMG
// sneak preview riding its own part-two round, the commentary set at part
// three and the flip to follow. All pinned from The Dragon Vol. III No. 8
// (February 1979), the combined TD22-plus-LW13 experiment issue, the
// Curtiss-provided Dm22.pdf scan voice, print folio the PDF page this issue.
//
// The issue-22 part-one print catches pinned as scanned: the contents prints
// Brunner where the byline prints Bruner, the Assassins article prints
// titantic, seige and the duplicated acknowledge-the-Sultan phrase, the Swiss
// piece prints Vol. with a double period, foreward twice, Giarnico in the
// table against Giornico in the text, Courtai against Courtrai and Perrer for
// the Chainmail co-author, the St. Jacob table prints 30,000 where the text
// prints 15,000, and the Armies piece prints Ziska for Zizka and stardio for
// the stradiot - all pinned as scanned, the conversion noted
//
namespace rules {

// ---- the assassin order history (print 5-7) ----

// the Alamut rock height - six hundred feet above the plain, well named the
// Eagles Guidance the assassin order history (print 5-7)
inline int t22AssassRockFeet()
    { return 600; }

// the rock width floor - thirty feet at the narrowest the assassin order
// history (print 5-7)
inline int t22AssassRockWidthMin()
    { return 30; }

// the rock width ceiling - one hundred twenty-five feet the assassin order
// history (print 5-7)
inline int t22AssassRockWidthMax()
    { return 125; }

// the rock length - four hundred fifty feet along the top the assassin order
// history (print 5-7)
inline int t22AssassRockLengthFeet()
    { return 450; }

// the garrison commandant note - three thousand golden dinars handed over,
// the takeover bloodless the assassin order history (print 5-7)
inline int t22AssassDinarRansom()
    { return 3000; }

// the Hasan Sabbah birth - ca. 1050 in Ray, five miles north of Teheran in
// the Elburz shadow the assassin order history (print 5-7)
inline int t22AssassHasanBirth()
    { return 1050; }

// the House of Wisdom arrival - 1078 A.D., the Cairo school founded
// seventy-four years earlier the assassin order history (print 5-7)
inline int t22AssassHasanCairoYear()
    { return 1078; }

// the Alamut takeover - September 1090, the Ismaili garrison smuggled the
// Master inside the assassin order history (print 5-7)
inline int t22AssassAlamutTaken()
    { return 1090; }

// the siege-camp raid - the fall of 1092, the sheer cliffs descended at night
// the assassin order history (print 5-7)
inline int t22AssassCampRaidYear()
    { return 1092; }

// the raid party - seventy hand-picked men plying their daggers with speed
// and silence the assassin order history (print 5-7)
inline int t22AssassRaiders()
    { return 70; }

// the first major political assassination - the Grand Visir Nizam al-Mulk
// stabbed by a fildai disguised as an ancient holy man the assassin order
// history (print 5-7)
inline int t22AssassNizamAlMulkYear()
    { return 1092; }

// the Malik Shah poisoning - November of the same year, the old debt settled
// the assassin order history (print 5-7)
inline int t22AssassMalikShahYear()
    { return 1092; }

// the no-women decree - wife and daughter banished from Alamut, never seen
// again the assassin order history (print 5-7)
inline int t22AssassWomenBanished()
    { return 1108; }

// the Hattin turn - the Assassins riding WITH Saladin against the Templars
// and Hospitallers the assassin order history (print 5-7)
inline int t22AssassHattinYear()
    { return 1187; }

// the Master death - May 1124, Umid named successor the assassin order
// history (print 5-7)
inline int t22AssassHasanDeath()
    { return 1124; }

// the fildais recruit ceiling - the ideal recruit no older than twelve years
// the assassin order history (print 5-7)
inline int t22AssassRecruitAge()
    { return 12; }

// the seven levels of achievement, each with its secret rites and oaths the
// assassin order history (print 5-7)
inline int t22AssassLevels()
    { return 7; }

// the Marco Polo passage - he passed by Alamut in 1273, the garden tale
// circulating since the eleventh century the assassin order history (print
// 5-7)
inline int t22AssassMarcoPoloYear()
    { return 1273; }

// the Guide to Famous Assassinations first entry - the Visir Kashi slain by
// his own two grooms the assassin order history (print 5-7)
inline int t22AssassGuideFirst()
    { return 1127; }

// the Guide last entry - Conrad Lord of Tyre slain by two monks, one under
// torture implicating Richard Lion-Heart the assassin order history (print
// 5-7)
inline int t22AssassGuideLast()
    { return 1192; }

// the Guide census - eight entries, 1127 through 1192 the assassin order
// history (print 5-7)
inline int t22AssassGuideCount()
    { return 8; }

// the Hasan boast - sixty thousand more followers not unlike the two that had
// just died the assassin order history (print 5-7)
inline int t22AssassSixtyThousandFollowers()
    { return 60000; }

// the modern tail - three million religious followers of the Aga Khan today
// the assassin order history (print 5-7)
inline int t22AssassAgaKhanMillions()
    { return 3; }

// the demonstration - the youth cutting his own throat and the wall man
// leaping before the ambassadors, the pillow dagger commanding Negotiate the
// assassin order history (print 5-7)
inline bool t22AssassDaggerDemo()
    { return true; }

// the etymology debate - users of hashish against followers of Hasan, no
// irrefutable argument either way the assassin order history (print 5-7)
inline bool t22AssassHashishDebate()
    { return true; }

// the paradise garden tale - the hashish garden of the travellers judged
// unlikely at the harsh Alamut climate and unnecessary given the fanatic
// devotion the assassin order history (print 5-7)
inline bool t22AssassGardenUnlikely()
    { return true; }

// the fildais curriculum - the dagger, the art of disguise, languages and
// court etiquette the assassin order history (print 5-7)
inline bool t22AssassDisguiseTraining()
    { return true; }

// the Crusader dealings - the Old Man of the Mountain title, the Kahf and
// Masyaf strongholds, Apamea delivered to Tancred the assassin order history
// (print 5-7)
inline bool t22AssassCrusaderDealing()
    { return true; }

// the succession solution - the eldest implicated on slight evidence, the
// youngest executed for the wine store stumble the assassin order history
// (print 5-7)
inline bool t22AssassSonsExecuted()
    { return true; }

// the Sanjar campaign - the dagger in the pillow aborts the 1118-1124
// campaign and buys the truce the assassin order history (print 5-7)
inline bool t22AssassSanjarTruce()
    { return true; }

// the print catch - the contents prints Brunner where the byline prints
// Bruner, and the article prints titantic, seige and the duplicated
// acknowledge-the-Sultan phrase, all pinned as scanned the assassin order
// history (print 5-7)
inline bool t22AssassBrunnerPrintCatch()
    { return true; }

// ---- the Swiss military doctrine (print 8-11) ----

// the Morgarten year - boulders and logs on the icy road, the Hapsburg column
// slaughtered the Swiss military doctrine (print 8-11)
inline int t22SwissMorgartenYear()
    { return 1315; }

// the Morgarten Austrian numbers - Duke Leopold purportedly fifteen thousand
// the Swiss military doctrine (print 8-11)
inline int t22SwissMorgartenAustrians()
    { return 15000; }

// the Morgarten Swiss numbers - said to be only fifteen hundred mountaineers
// the Swiss military doctrine (print 8-11)
inline int t22SwissMorgartenSwiss()
    { return 1500; }

// the Laupen year - the Bernese pike turns the tide, the echelon born the
// Swiss military doctrine (print 8-11)
inline int t22SwissLaupenYear()
    { return 1339; }

// the Laupen Burgundian numbers - Count Gerard of Vallangin and his feudal
// array the Swiss military doctrine (print 8-11)
inline int t22SwissLaupenBurgundians()
    { return 15000; }

// the echelon - Vorhut, Gewaltshaufen and Nachhut in echelon, the deployment
// that became the rule after 1339 the Swiss military doctrine (print 8-11)
inline int t22SwissPhalanxes()
    { return 3; }

// the Sempach year - Leopold III killed, the Kiel wedge breaks the Austrian
// battles the Swiss military doctrine (print 8-11)
inline int t22SwissSempachYear()
    { return 1386; }

// the Arbedo year - the lesson that ordered the pike increase the Swiss
// military doctrine (print 8-11)
inline int t22SwissArbedoYear()
    { return 1422; }

// the Arbedo Milanese numbers - Carmagnola with six thousand gendarmes the
// Swiss military doctrine (print 8-11)
inline int t22SwissArbedoGendarmes()
    { return 6000; }

// the Arbedo Swiss numbers - four thousand drawn up in a single block the
// Swiss military doctrine (print 8-11)
inline int t22SwissArbedoSwiss()
    { return 4000; }

// the Arbedo rescue - the foragers cresting the rise at the crucial moment,
// the timely appearance the Swiss military doctrine (print 8-11)
inline int t22SwissArbedoForagers()
    { return 600; }

// the St Jacob year - the Dauphine turned back to France the Swiss military
// doctrine (print 8-11)
inline int t22SwissStJacobYear()
    { return 1444; }

// the St Jacob dead - six hundred pikemen die to a man rather than surrender
// the Swiss military doctrine (print 8-11)
inline int t22SwissStJacobSwiss()
    { return 600; }

// the St Jacob print catch - the battles table prints thirty thousand French
// where the text prints fifteen thousand, pinned as scanned both the Swiss
// military doctrine (print 8-11)
inline int t22SwissStJacobFrenchTable()
    { return 30000; }

// the St Jacob French strength as the text prints it the Swiss military
// doctrine (print 8-11)
inline int t22SwissStJacobFrenchText()
    { return 15000; }

// the St Jacob French loss - two thousand men in the fight the Swiss military
// doctrine (print 8-11)
inline int t22SwissStJacobFrenchLoss()
    { return 2000; }

// the Grandson year - beaten without a real fight at Mount Aubert the Swiss
// military doctrine (print 8-11)
inline int t22SwissGrandsonYear()
    { return 1476; }

// the Morat year - no scouts, defeat in detail, the slaughter the Swiss
// military doctrine (print 8-11)
inline int t22SwissMoratYear()
    { return 1476; }

// the Nancy year - the Burgundian end, Burgundy absorbed by the French the
// Swiss military doctrine (print 8-11)
inline int t22SwissNancyYear()
    { return 1477; }

// the dozen battles listing - the major battles for national sovereignty
// after Laupen the Swiss military doctrine (print 8-11)
inline int t22SwissDozenBattles()
    { return 12; }

// the battles span opens - Sempach 1386 the Swiss military doctrine (print
// 8-11)
inline int t22SwissBattlesFirst()
    { return 1386; }

// the battles span closes - Dornach 1499, the last invasion until the
// Napoleonic era the Swiss military doctrine (print 8-11)
inline int t22SwissBattlesLast()
    { return 1499; }

// the Swabian war hedgehog - six hundred pikemen repelling the horse with
// laughing and jesting, outnumbered near two to one the Swiss military
// doctrine (print 8-11)
inline int t22SwissHedgehogPikemen()
    { return 600; }

// the Swiss cavalry ceiling - a few score at most, an upper limit of one to
// two hundred men the Swiss military doctrine (print 8-11)
inline int t22SwissCavalryMax()
    { return 200; }

// the pike decree - at least half the force pike-armed after Arbedo the Swiss
// military doctrine (print 8-11)
inline int t22SwissPikeAfterArbedo()
    { return 50; }

// the halberd relegation floor - c. 1450 the halberdiers form the pike-square
// center at twenty to thirty percent the Swiss military doctrine (print 8-11)
inline int t22SwissHalberdCenterMin()
    { return 20; }

// the halberd relegation ceiling of the same passage the Swiss military
// doctrine (print 8-11)
inline int t22SwissHalberdCenterMax()
    { return 30; }

// the missile switch - crossbows give way to arquebuses c. 1450 the Swiss
// military doctrine (print 8-11)
inline int t22SwissCrossbowToArquebus()
    { return 1450; }

// the crossbow persistence - some carried on until 1500 the Swiss military
// doctrine (print 8-11)
inline int t22SwissArquebusPersist()
    { return 1500; }

// the La Bicocca year - the charge on the entrenched landsknechte the Swiss
// military doctrine (print 8-11)
inline int t22SwissLaBicoccaYear()
    { return 1522; }

// the La Bicocca cost - three thousand men lost and the retirement the Swiss
// military doctrine (print 8-11)
inline int t22SwissLaBicoccaLoss()
    { return 3000; }

// the mercenary battles - Barletta, Novara, Marignano, La Bicocca and Pavia
// the Swiss military doctrine (print 8-11)
inline int t22SwissMercBattles()
    { return 5; }

// the army composition table - six troop types, the halberd through the
// cavalry lance the Swiss military doctrine (print 8-11)
inline int t22SwissCompCount()
    { return 6; }

// the echelon doctrine - three phalanxes with multiple impact, flank
// protection and reserve rolled into one the Swiss military doctrine (print
// 8-11)
inline bool t22SwissEchelonDoctrine()
    { return true; }

// the Kiel - the Sempach wedge of extra depth formed to break an
// exceptionally strong line the Swiss military doctrine (print 8-11)
inline bool t22SwissKielWedge()
    { return true; }

// the dismounted lance - Sempach and Arbedo, cavalry lances used as pikes,
// the hobilars lesson the Swiss military doctrine (print 8-11)
inline bool t22SwissLancesAsPikes()
    { return true; }

// the Grandson ploy - Charles the Rash thought another Cannae, the Mount
// Aubert arrival broke his army without a real fight the Swiss military
// doctrine (print 8-11)
inline bool t22SwissGrandsonCannae()
    { return true; }

// the Rash end - Charles the Rash rather than the Bold, cut down by the
// halberd blow at Nancy while rallying his troops the Swiss military doctrine
// (print 8-11)
inline bool t22SwissCharlesHalberdDeath()
    { return true; }

// the national levy - each man knew his neighbor in formation and often
// elected the leaders the Swiss military doctrine (print 8-11)
inline bool t22SwissElectedLeaders()
    { return true; }

// the mobility doctrine - light armor by determination rather than poverty,
// only the front ranks in metal the Swiss military doctrine (print 8-11)
inline bool t22SwissLightArmorDoctrine()
    { return true; }

// the two-to-four-day levy - each man carrying his own food, in the field
// faster than any invader could hope to counter the Swiss military doctrine
// (print 8-11)
inline bool t22SwissLogistics()
    { return true; }

// the artillery verdict - artillery the greatest foe of the mass formation,
// the Swiss refused to change, the era closed at Marignano the Swiss military
// doctrine (print 8-11)
inline bool t22SwissArtilleryFoe()
    { return true; }

// the landsknecht record - never bested on a fair field, slaughtered at La
// Bicocca, never dominant again after Pavia the Swiss military doctrine
// (print 8-11)
inline bool t22SwissNeverBestedLandsknecht()
    { return true; }

// the tabletop recommendation - Chainmail, carefully researched for close
// simulation of the Swiss battles the Swiss military doctrine (print 8-11)
inline bool t22SwissChainmailRec()
    { return true; }

// the print catch - Vol. with a double period at print 10, foreward twice,
// Giarnico in the table against Giornico in the text, Courtai against
// Courtrai, and Perrer for the Chainmail co-author, pinned as scanned the
// Swiss military doctrine (print 8-11)
inline bool t22SwissPrintCatch()
    { return true; }

// the composition floor - halberd 20 to 60, lucern hammer morningstar
// two-handed sword 10 to 20, pike 10 to 65, crossbow 5 to 30, arquebus 5 to
// 25, cavalry lance 0 to 5
inline int t22SwissCompMin(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 0;
        default:
            return -99;
        }
    }

// the composition ceiling of the same six troop types, the table as printed
inline int t22SwissCompMax(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 20;
        case 2:
            return 65;
        case 3:
            return 30;
        case 4:
            return 25;
        case 5:
            return 5;
        default:
            return -99;
        }
    }

// ---- the Renaissance armies overview (print 12) ----

// the Renaissance span opens - the end of the Hundred Years War the
// Renaissance armies overview (print 12)
inline int t22ArmiesHundredYearsEnd()
    { return 1453; }

// the span closes - Queen Anne of England and the final ban on pikes the
// Renaissance armies overview (print 12)
inline int t22ArmiesPikeBan()
    { return 1703; }

// the pike length floor - twelve feet the Renaissance armies overview (print
// 12)
inline int t22ArmiesPikeMinFeet()
    { return 12; }

// the pike length ceiling - twenty-one feet the Renaissance armies overview
// (print 12)
inline int t22ArmiesPikeMaxFeet()
    { return 21; }

// the longbow rate of fire - more than three times the crossbow the
// Renaissance armies overview (print 12)
inline int t22ArmiesLongbowRate()
    { return 3; }

// the three developments sounding the feudal death knell - the longbow, the
// pike and the Hussite wagon laager the Renaissance armies overview (print
// 12)
inline int t22ArmiesThreeWeapons()
    { return 3; }

// the great captains - de Cordoba, Gaston of Foix, Maurice of Nassau and
// Gustavus Adolphus the Renaissance armies overview (print 12)
inline int t22ArmiesGreatCaptains()
    { return 4; }

// the bibliography census - Machiavelli twice, Oman twice, Mattingly, Dupuy
// and Dupuy, Wise, and Monluc the Renaissance armies overview (print 12)
inline int t22ArmiesBibliography()
    { return 8; }

// the Franklin note - Benjamin Franklin urged the longbow as the standard arm
// of the American forces in the revolution the Renaissance armies overview
// (print 12)
inline bool t22ArmiesFranklinLongbow()
    { return true; }

// the Venetian stardio - the dragoon forerunners, armed with spear bow or
// crossbow, equally adept mounted or afoot the Renaissance armies overview
// (print 12)
inline bool t22ArmiesStardioDragoon()
    { return true; }

// the Hungarian hussars - the national fighting force of levies raised on
// short notice, bow and curved saber the Renaissance armies overview (print
// 12)
inline bool t22ArmiesHussarLevy()
    { return true; }

// the Hussite laager - Jan Ziska of Bohemia turning the wagon laager from
// refuge into a remarkable offensive tool the Renaissance armies overview
// (print 12)
inline bool t22ArmiesZiskaLaager()
    { return true; }

// the mercenary age - Swiss, Flemings, Landsknecht and English longbowmen in
// Italian service, Genoese crossbowmen backing French knights the Renaissance
// armies overview (print 12)
inline bool t22ArmiesMercenaryAge()
    { return true; }

// the print catch - the piece prints Ziska for the usual Zizka and stardio
// for the stradiot, pinned as scanned the Renaissance armies overview (print
// 12)
inline bool t22ArmiesZiskaSpellingPrintCatch()
    { return true; }

// the series preview - the next installment opens with the Swiss Pikeman the
// Renaissance armies overview (print 12)
inline bool t22ArmiesSwissNextTime()
    { return true; }

}   // namespace rules
