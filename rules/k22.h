// =========================================================================================
// Adnd1 - rules/k22.h
// The Dragon issue-22 opener part three - the commentary set
// census 870 -> 871.
//
// The part-three round of the issue-22 four-round shape - five chains of the
// Curtiss TD-22 call pinned as the commentary set: the Gygax
// design-philosophy essay What It Is and Where It Is Going (print 29-30), the
// Gygax pole arms taxonomy (print 50-54), the Berg rebuttal SPI on AD and D
// (print 44), the Gosling battle report Stalemate at Kassala (print 45-47)
// and the Mapping the Dungeons games catalog riding the International DM
// Search roster (print 18-28). Pinned from The Dragon Vol. III No. 8
// (February 1979) print 18-30 and 44-54 at extract/dragon/022, PRINT FOLIO =
// PDF PAGE this issue, the transcript of the Curtiss-provided scan. The
// interleaved ads ride the standing drop list; the flip to close all three
// report-022 boxes follows at R949.
//
namespace rules {

// ---- the design philosophy essay (print 29-30) ----

// the player base estimate - perhaps one hundred fifty thousand persons now
// play the game the design philosophy essay (print 29-30)
inline int k22PlayersNow()
    { return 150000; }

// the first thousand hand-assembled boxed sets sold over eleven months the
// design philosophy essay (print 29-30)
inline int k22FirstThousandMonths()
    { return 11; }

// the second thousand sold in five months of the vague five-or-six print the
// design philosophy essay (print 29-30)
inline int k22SecondThousandLowMonths()
    { return 5; }

// the six-month ceiling of the same vague five-or-six months the design
// philosophy essay (print 29-30)
inline int k22SecondThousandHighMonths()
    { return 6; }

// the third printing - two thousand sets the design philosophy essay (print
// 29-30)
inline int k22ThirdPrintingSets()
    { return 2000; }

// the third printing sold out in five months the design philosophy essay
// (print 29-30)
inline int k22ThirdPrintingMonths()
    { return 5; }

// only four thousand original sets in circulation from the seventy-four start
// through December seventy-five the design philosophy essay (print 29-30)
inline int k22OriginalSetsByEnd()
    { return 4000; }

// the low piracy estimate - about twenty percent of total sales the design
// philosophy essay (print 29-30)
inline int k22PiracyLowPct()
    { return 20; }

// the high piracy estimate - some place it as high as fifty percent the
// design philosophy essay (print 29-30)
inline int k22PiracyHighPct()
    { return 50; }

// the Basic Set today sells four thousand copies per month the design
// philosophy essay (print 29-30)
inline int k22BasicMonthlyCopies()
    { return 4000; }

// the game born January seventy-four the design philosophy essay (print
// 29-30)
inline int k22GameBornYear()
    { return 1974; }

// the colorfully boxed Basic Set published in seventy-seven the design
// philosophy essay (print 29-30)
inline int k22BasicSetYear()
    { return 1977; }

// the whole likened to the Poetics of Aristotle the design philosophy essay
// (print 29-30)
inline bool k22AristotleAnalogy()
    { return true; }

// each Dungeon Master a playwright scripting plot outlines and the players
// the Thespians the design philosophy essay (print 29-30)
inline bool k22DmPlaywrightThespians()
    { return true; }

// the game is cooperative - players must interact successfully amongst
// themselves first the design philosophy essay (print 29-30)
inline bool k22CooperativeGame()
    { return true; }

// the answer to who wins is everybody, providing the game is well run the
// design philosophy essay (print 29-30)
inline bool k22EverybodyWins()
    { return true; }

// the referee must be disinterested in general, incidentally against the
// players when running the hostile parts the design philosophy essay (print
// 29-30)
inline bool k22DmDisinterestedReferee()
    { return true; }

// the seventy-seven Basic Set contained geomorphs plus monster and treasure
// selections and dice the design philosophy essay (print 29-30)
inline bool k22BasicSetHadGeomorphs()
    { return true; }

// the newest edition does away with the geomorphs and lists in favor of a
// complete basic module the design philosophy essay (print 29-30)
inline bool k22NewestBasicModule()
    { return true; }

// the game moves in two directions - the Original system and the new Advanced
// system the design philosophy essay (print 29-30)
inline bool k22TwoDirections()
    { return true; }

// no continual barrage of new rules - when you have a fine product let well
// enough alone the design philosophy essay (print 29-30)
inline bool k22NoPerpetualRevision()
    { return true; }

// the personal opinion that the game form is a classic of the same stamp as
// chess and the property-trading board game the design philosophy essay
// (print 29-30)
inline bool k22ChessMonopolyStamp()
    { return true; }

// the hoped direction - program cassettes on a home computer doing the record
// work, supplementing not destroying the human campaign the design philosophy
// essay (print 29-30)
inline bool k22HomeComputerDirection()
    { return true; }

// the column is a forum - DMs and players invited to submit high-calibre
// material the design philosophy essay (print 29-30)
inline bool k22ColumnIsForum()
    { return true; }

// the confession that the game was written for a small audience of devoted
// miniatures players the design philosophy essay (print 29-30)
inline bool k22WroteForMiniaturists()
    { return true; }

// ---- the pole arms taxonomy (print 50-54) ----

// the taxonomy floor - a pole arm presupposes a haft or shaft of not less
// than five feet the pole arms taxonomy (print 50-54)
inline int k22HaftMinFeet()
    { return 5; }

// the ultimate pole arm - the eighteen-foot low end of the
// eighteen-to-twenty-one-foot pike the pole arms taxonomy (print 50-54)
inline int k22UltimatePikeLowFeet()
    { return 18; }

// the twenty-one-foot high end of the same ultimate pike the pole arms
// taxonomy (print 50-54)
inline int k22UltimatePikeHighFeet()
    { return 21; }

// the wide breadth of the genre - an axe blade on a five-foot haft is just as
// much a pole arm the pole arms taxonomy (print 50-54)
inline int k22AxeHaftFeet()
    { return 5; }

// any spear with a shaft of fifteen feet or longer is considered a pike the
// pole arms taxonomy (print 50-54)
inline int k22PikeMinFeet()
    { return 15; }

// spears of twelve feet or so are often referred to as ash spears in English
// writings the pole arms taxonomy (print 50-54)
inline int k22AshSpearFeet()
    { return 12; }

// Norman lances about twelve feet in length, some less the pole arms taxonomy
// (print 50-54)
inline int k22NormanLanceFeet()
    { return 12; }

// the later Middle Ages lance grew to an average of about fourteen feet the
// pole arms taxonomy (print 50-54)
inline int k22LanceAvgFeet()
    { return 14; }

// the horseman thereby gains about ten feet of reach beyond the head of the
// horse the pole arms taxonomy (print 50-54)
inline int k22LanceReachFeet()
    { return 10; }

// Swiss and German pikes had metal protecting the shaft up to two feet from
// the head the pole arms taxonomy (print 50-54)
inline int k22PikeShaftGuardFeet()
    { return 2; }

// the spetum - two blades pointing forwards at about forty-five degrees added
// to the tapering point the pole arms taxonomy (print 50-54)
inline int k22SpetumBladeDegrees()
    { return 45; }

// the dismounted Austrian lances against the Swiss - the Sempach reference
// the pole arms taxonomy (print 50-54)
inline int k22SempachYear()
    { return 1386; }

// the halberd as a whole weapon often reached eight feet in length the pole
// arms taxonomy (print 50-54)
inline int k22HalberdFeet()
    { return 8; }

// the halberd spear point useless against mounted knights with lances - the
// Arbedo reference the pole arms taxonomy (print 50-54)
inline int k22ArbedoYear()
    { return 1422; }

// the bardiche head ranged from about two feet the pole arms taxonomy (print
// 50-54)
inline int k22BardicheHeadLowFeet()
    { return 2; }

// through over three feet in length, the bardiche head high end the pole arms
// taxonomy (print 50-54)
inline int k22BardicheHeadHighFeet()
    { return 3; }

// the peasant flail - a heavy shaft of about three the pole arms taxonomy
// (print 50-54)
inline int k22FlailShaftLowFeet()
    { return 3; }

// to four feet in length, the flail shaft high end the pole arms taxonomy
// (print 50-54)
inline int k22FlailShaftHighFeet()
    { return 4; }

// the whole flail being over five feet long with tremendous penetration and
// crushing power the pole arms taxonomy (print 50-54)
inline int k22FlailTotalFeet()
    { return 5; }

// the morning star - a heavy wooden haft from three feet the pole arms
// taxonomy (print 50-54)
inline int k22MorningStarLowFeet()
    { return 3; }

// to five feet or more in length, the morning star high end the pole arms
// taxonomy (print 50-54)
inline int k22MorningStarHighFeet()
    { return 5; }

// the Lucern hammer - a smaller hammer-like head with three prongs and a
// longer spike than the halberd the pole arms taxonomy (print 50-54)
inline int k22LucernHammerProngs()
    { return 3; }

// each bill-guisarme has four features - the sharp point, the large hook, the
// back spike and the sharpened edges the pole arms taxonomy (print 50-54)
inline int k22BillGuisarmeFeatures()
    { return 4; }

// some military picks were also pole mounted, having shafts of five feet or
// greater the pole arms taxonomy (print 50-54)
inline int k22PickShaftMinFeet()
    { return 5; }

// the fauchard-fork combination weapon had two general forms the pole arms
// taxonomy (print 50-54)
inline int k22FauchardForkForms()
    { return 2; }

// the Swiss mix - forty percent pike as an average the pole arms taxonomy
// (print 50-54)
inline int k22SwissPikePct()
    { return 40; }

// forty percent halberd, Lucern hammer and morning star in the same Swiss mix
// the pole arms taxonomy (print 50-54)
inline int k22SwissHalberdPct()
    { return 40; }

// twenty percent crossbow and arquebus completing the Swiss mix the pole arms
// taxonomy (print 50-54)
inline int k22SwissShotPct()
    { return 20; }

// the seven basic families of the medieval pole arm taxonomy the pole arms
// taxonomy (print 50-54)
inline int k22PoleArmFamCount()
    { return 7; }

// the family code by print order - one the dagger family, two the axe, three
// the cleaver, four the scythe, five the heavy knife, six the pruning hook,
// seven the hay fork
inline int k22PoleArmFamCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return -99;
        }
    }

// the member count of each family - the dagger six, the axe three, the
// cleaver two, the scythe one, the heavy knife one, the pruning hook two, the
// hay fork one
inline int k22PoleArmFamMembers(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        default:
            return -99;
        }
    }

// the Saxtorph book identifies an obvious morning star as a mace - the
// misnaming example that opens the taxonomy the pole arms taxonomy (print
// 50-54)
inline bool k22SaxtorphMaceError()
    { return true; }

// the mace is usually short-hafted with a flanged head, the whole cast in one
// piece the pole arms taxonomy (print 50-54)
inline bool k22MaceCastOnePiece()
    { return true; }

// the morning star is longer, an infantry weapon with a wooden shaft and head
// set with radiating spikes the pole arms taxonomy (print 50-54)
inline bool k22MorningStarRadiatingSpikes()
    { return true; }

// the ranseur has backward-hooking projections set well below the large
// central blade the pole arms taxonomy (print 50-54)
inline bool k22RanseurBackwardHooks()
    { return true; }

// the Bohemian ear spoon is a form of partisan with piercing spikes against
// plate armor the pole arms taxonomy (print 50-54)
inline bool k22EarSpoonPartisan()
    { return true; }

// the halberd is topped with a fairly long spear point and backed by an
// angled or hooked-down spike the pole arms taxonomy (print 50-54)
inline bool k22HalberdSpikeHook()
    { return true; }

// the bardiche links the pole axes to the pole cleavers as a transitional
// step the pole arms taxonomy (print 50-54)
inline bool k22BardicheTransitional()
    { return true; }

// the bardiche in all its forms was very heavy and used principally in
// Eastern Europe the pole arms taxonomy (print 50-54)
inline bool k22BardicheEasternEurope()
    { return true; }

// the earlier-article confession - the author once mistakenly recommended
// treating the lochaber axe as a halberd the pole arms taxonomy (print 50-54)
inline bool k22LochaberRecanted()
    { return true; }

// the fauchard cut and thrust - it is strongly suspected it did neither too
// well the pole arms taxonomy (print 50-54)
inline bool k22FauchardInefficient()
    { return true; }

// the guisarme sharp cutting edge runs its convex side, probably from reverse
// spike to hook the pole arms taxonomy (print 50-54)
inline bool k22GuisarmeReverseSpike()
    { return true; }

// the English bill hook - same as the French guisarme but the concave hook
// edge is sharp with an L-shaped forward tine the pole arms taxonomy (print
// 50-54)
inline bool k22BillHookLTine()
    { return true; }

// the military fork sometimes had a shorter third tine in the crotch to
// channel opponents the pole arms taxonomy (print 50-54)
inline bool k22MilitaryForkThirdTine()
    { return true; }

// the morning star also called the holy water sprinkler or the godentag in
// the Low Countries the pole arms taxonomy (print 50-54)
inline bool k22MorningStarSprinkler()
    { return true; }

// the Lucern hammer was replaced by the halberd amongst the ranks of the
// Swiss after the fourteenth century the pole arms taxonomy (print 50-54)
inline bool k22LucernHammerReplaced()
    { return true; }

// the bec de corbin was used late in the Middle Ages and into the Renaissance
// by knights and nobles, not commoners the pole arms taxonomy (print 50-54)
inline bool k22BecDeCorbinKnightly()
    { return true; }

// the Stone glossary shows a halberd with a fork tip and misidentifies it as
// a military fork the pole arms taxonomy (print 50-54)
inline bool k22StoneForkError()
    { return true; }

// the classification ignores secondary spear tips when classifying pole arms
// the pole arms taxonomy (print 50-54)
inline bool k22SecondaryTipsIgnored()
    { return true; }

// the partisan is primarily a thrusting weapon and belongs in the spear
// family the pole arms taxonomy (print 50-54)
inline bool k22PartisanSpearFamily()
    { return true; }

// per Oman the English brown bill was a halberd in all respects save the back
// spike the pole arms taxonomy (print 50-54)
inline bool k22BrownBillHalberd()
    { return true; }

// the bill-guisarme persisted the longest of all pole arms save the pike and
// the halberd the pole arms taxonomy (print 50-54)
inline bool k22BillGuisarmeLongest()
    { return true; }

// the scorpion is a typical form of bill-guisarme the pole arms taxonomy
// (print 50-54)
inline bool k22ScorpionBillGuisarme()
    { return true; }

// Swiss pikemen did not ground the pike butt to accept a cavalry charge - the
// rear of the shaft was held higher the pole arms taxonomy (print 50-54)
inline bool k22SwissPikeNotGrounded()
    { return true; }

// ---- the Berg rebuttal (print 44) ----

// the S and T reviewer demonstrated that he does not play the game he
// reviewed the Berg rebuttal (print 44)
inline bool k22BergDoesNotPlay()
    { return true; }

// the review asserted the Players Handbook was not a game design but a simple
// rewriting of the original game the Berg rebuttal (print 44)
inline bool k22PhMereRewrite()
    { return true; }

// the reviewer claimed the majority of the work was pigs lips or some such
// the Berg rebuttal (print 44)
inline bool k22PigsLipsQuote()
    { return true; }

// the reaction from players has been uniformly favorable the Berg rebuttal
// (print 44)
inline bool k22UniformlyFavorable()
    { return true; }

// the rebuttal analogy - an antique set of ivory chessmen is appreciated only
// by the chess aficionado the Berg rebuttal (print 44)
inline bool k22IvoryChessmenAnalogy()
    { return true; }

// the countercharge - the reviewer comes from the past masters of the rehash,
// artisans of the warmed-over war game the Berg rebuttal (print 44)
inline bool k22SpiRehashMasters()
    { return true; }

// not the pot calling the kettle black but the pot complaining its besooted
// vision imagines tarnish on the silver salver above it the Berg rebuttal
// (print 44)
inline bool k22PotSalverImage()
    { return true; }

// the rival fantasy game despite extensive advertising and riding the Tolkien
// coattails comes nowhere near the Players Handbook sales record the Berg
// rebuttal (print 44)
inline bool k22TolkienCoattails()
    { return true; }

// the closing line - the ball is back in your court, Richard the Berg
// rebuttal (print 44)
inline bool k22BallBackInCourt()
    { return true; }

// ---- the Kassala battle report (print 45-47) ----

// the historical occurrence - Portugal aids the Ethiopian emperor Claudius
// against the Turkish emirate of Egypt the Kassala battle report (print
// 45-47)
inline int k22KassalaYear()
    { return 1541; }

// Portugal sent four hundred infantry the Kassala battle report (print 45-47)
inline int k22PortugalInfantry()
    { return 400; }

// with one thousand stand of firearms and some cannon the Kassala battle
// report (print 45-47)
inline int k22FirearmsStand()
    { return 1000; }

// the Galla warriors - four hundred interned in Kassala plus two more cohorts
// the Kassala battle report (print 45-47)
inline int k22GallaCohorts()
    { return 2; }

// each defending cohort of sword, spear or bowmen numbered four hundred the
// Kassala battle report (print 45-47)
inline int k22CohortStrength()
    { return 400; }

// the recessed line left only one hundred sixty light cavalry as the
// Ethiopian reserve the Kassala battle report (print 45-47)
inline int k22EthiopianCavReserve()
    { return 160; }

// twenty-six hundred enemies to the front of the Europeans at Udaka the
// Kassala battle report (print 45-47)
inline int k22EnemiesToFront()
    { return 2600; }

// the infantry stood three thousand miles from their homeland the Kassala
// battle report (print 45-47)
inline int k22HomelandMiles()
    { return 3000; }

// the one thousand Nubian footmen marching barefoot over the sun-blasted
// rocks the Kassala battle report (print 45-47)
inline int k22NubianFoot()
    { return 1000; }

// six hundred brightly clad Mamalukes - white slaves raised from childhood to
// be warriors the Kassala battle report (print 45-47)
inline int k22MamalukeCount()
    { return 600; }

// two hundred Turkish heavy cavalry of the bodyguard in black iron chainmail
// with the silver moon and star the Kassala battle report (print 45-47)
inline int k22TurkishHeavyCount()
    { return 200; }

// four hundred tattoo-faced Arab mercenaries of the desert with cane spears
// and round shields the Kassala battle report (print 45-47)
inline int k22ArabMercCount()
    { return 400; }

// the Egyptian and Turkish infantry in the center, each unit two hundred
// strong the Kassala battle report (print 45-47)
inline int k22CenterUnitStrength()
    { return 200; }

// Don Iago left a hundred Portuguese in Udaka the Kassala battle report
// (print 45-47)
inline int k22UdakaGarrison()
    { return 100; }

// plus his one hundred twenty armed black slaves to hold the trenches the
// Kassala battle report (print 45-47)
inline int k22ArmedSlaves()
    { return 120; }

// the rest of his command, three hundred strong, about-faced against the
// flank attack the Kassala battle report (print 45-47)
inline int k22IagoWing()
    { return 300; }

// one hundred musketeers beat the Nubians to the rim of the wadi and fired
// one volley before the charge struck home the Kassala battle report (print
// 45-47)
inline int k22RimMusketeers()
    { return 100; }

// the local superiority of infantry numbers - fourteen hundred attackers the
// Kassala battle report (print 45-47)
inline int k22FlankAttackers()
    { return 1400; }

// against five hundred twenty defenders of the Portuguese wing the Kassala
// battle report (print 45-47)
inline int k22FlankDefenders()
    { return 520; }

// two hundred musket balls shrieked into the packed Moslem ranks the Kassala
// battle report (print 45-47)
inline int k22MusketBallsVolley()
    { return 200; }

// each ball one and a half ounces - twelve eighths of an ounce the Kassala
// battle report (print 45-47)
inline int k22MusketBallEighths()
    { return 12; }

// the print calls the volley fifteen pounds of red-hot lead - the arithmetic
// of two hundred one-and-a-half-ounce balls gives eighteen and three-quarters
// pounds, both pinned the Kassala battle report (print 45-47)
inline int k22PrintLeadPounds()
    { return 15; }

// twenty miles downstream from Kassala the river Ghash dies in the marshes
// and sands the Kassala battle report (print 45-47)
inline int k22GhashMilesToDeath()
    { return 20; }

// the Nubians were stunned by a third volley that piled corpses two deep on
// the dried grass the Kassala battle report (print 45-47)
inline int k22VolleysFired()
    { return 3; }

// the enemy stood thirty percent stronger in numbers against the Ethiopian
// left flank in the air the Kassala battle report (print 45-47)
inline int k22EnemyStrengthPctPlus()
    { return 30; }

// the game used borrowed figures from the Crusades, the Zulu War, the
// Renaissance and the ancient Egyptian eras the Kassala battle report (print
// 45-47)
inline bool k22BorrowedFigures()
    { return true; }

// the game had four participants - three players and one umpire the Kassala
// battle report (print 45-47)
inline bool k22ThreePlayersOneUmpire()
    { return true; }

// there was no strategic game as a prelude and the terrain is for the most
// part fictional the Kassala battle report (print 45-47)
inline bool k22NoStrategicPrelude()
    { return true; }

// both sides lit no fires in the night before the battle the Kassala battle
// report (print 45-47)
inline bool k22NoFiresLit()
    { return true; }

// all Ethiopian units were ordered to hold their ground in a passive defense
// the Kassala battle report (print 45-47)
inline bool k22PassiveDefense()
    { return true; }

// with a ruthless enemy and the river at their backs there was no need to
// worry about a route of retreat the Kassala battle report (print 45-47)
inline bool k22NoRetreatWorry()
    { return true; }

// the lines of abatis would break up the lightning cavalry charge like
// primitive barbed wire the Kassala battle report (print 45-47)
inline bool k22AbatisBarbWire()
    { return true; }

// the hetman Beshrabi broke through with a handful of men and stormed the
// Portuguese gun nearest the river the Kassala battle report (print 45-47)
inline bool k22BeshrabiGunRaid()
    { return true; }

// the Arab light cavalry attempted unsuccessfully to take the other cannon
// the Kassala battle report (print 45-47)
inline bool k22ArabCannonFail()
    { return true; }

// the Ethiopian light cavalry came screeching down, hurled javelins at the
// gallop and butchered every Arab that had crossed the Kassala battle report
// (print 45-47)
inline bool k22ArabBreakthroughSnuffed()
    { return true; }

// the Turkish Janissaries fought to the central flagpole with swords,
// gunbutts and hand-grenades, then withdrew in good order the Kassala battle
// report (print 45-47)
inline bool k22JanissaryWithdraw()
    { return true; }

// the entire Nubian force turned and fled after the third volley the Kassala
// battle report (print 45-47)
inline bool k22NubianRout()
    { return true; }

// the basic fact illustrated - different troop composition compels battle on
// different terms and the result is usually a stalemate the Kassala battle
// report (print 45-47)
inline bool k22StalemateLesson()
    { return true; }

// the baffled Emir withdrew down the Atbara river to the Nile and spent the
// rainy season in Khartoum the Kassala battle report (print 45-47)
inline bool k22SuliemanKhartoum()
    { return true; }

// the editor holds the weak point in the Christian lines was the walled town
// of Kassala the Kassala battle report (print 45-47)
inline bool k22EditorTownTarget()
    { return true; }

// the Muezzins sent up their wailing cry as the sun cleared the horizon at
// dawn in Ethiopia the Kassala battle report (print 45-47)
inline bool k22MuezzinDawn()
    { return true; }

// ---- the games catalog roster (print 18-28) ----

// the list of some five hundred plus names of referees represents a small
// fraction of the whole the games catalog roster (print 18-28)
inline int k22DmSearchClaimedNames()
    { return 500; }

// the cut-off date for the list was the eighteenth the games catalog roster
// (print 18-28)
inline int k22DmSearchCutOffDay()
    { return 18; }

// of December seventy-eight the games catalog roster (print 18-28)
inline int k22DmSearchCutOffYear()
    { return 1978; }

// corrections print in the update list in about three the games catalog
// roster (print 18-28)
inline int k22DmSearchUpdateLowMonths()
    { return 3; }

// to four months the games catalog roster (print 18-28)
inline int k22DmSearchUpdateHighMonths()
    { return 4; }

// back issue price two dollars and ten cents, postage and handling included
// the games catalog roster (print 18-28)
inline int k22BackIssuePriceCents()
    { return 210; }

// seven Volume Two back issues in stock the games catalog roster (print
// 18-28)
inline int k22BackIssueVolTwoCount()
    { return 7; }

// five Volume Three back issues in stock the games catalog roster (print
// 18-28)
inline int k22BackIssueVolThreeCount()
    { return 5; }

// twenty-one games appear in the list that follows the roster the games
// catalog roster (print 18-28)
inline int k22GamesCatalogCount()
    { return 21; }

// the Hobbitronics association is composed of nine people across eight states
// and the APO the games catalog roster (print 18-28)
inline int k22HobbitronicsMembers()
    { return 9; }

// five named dungeons printed as sounding interesting - from Unicorn Mountain
// through the Polish Dungeon the games catalog roster (print 18-28)
inline int k22NamedDungeonCount()
    { return 5; }

// if no game is listed assume the person at least referees the one and only
// original game the games catalog roster (print 18-28)
inline bool k22AssumeDndIfSilent()
    { return true; }

// where two addresses are given the italic one is the school-year address,
// generally September to May the games catalog roster (print 18-28)
inline bool k22SchoolYearItalics()
    { return true; }

// no other correspondence may be included with your name for the list - lost
// in the shuffle names got left off the games catalog roster (print 18-28)
inline bool k22NoOtherCorrespondence()
    { return true; }

// to be taken off a company mailing list contact your postmaster for the
// proper procedure the games catalog roster (print 18-28)
inline bool k22PostmasterRemoval()
    { return true; }

// club addresses were included whenever possible, but associations were not
// the games catalog roster (print 18-28)
inline bool k22ClubsWherePossible()
    { return true; }

// as a general rule specific board games were not listed - beyond the
// intended scope the games catalog roster (print 18-28)
inline bool k22NoBoardGames()
    { return true; }

// the Space Quest publisher is unknown - the offer to print the name if he
// identifies himself the games catalog roster (print 18-28)
inline bool k22SpaceQuestUnknown()
    { return true; }

// most listed referees play only once a week at most - their time is very
// valuable the games catalog roster (print 18-28)
inline bool k22OnceAWeekAtMost()
    { return true; }

// the blanket apology to those whose names or addresses were misspelled -
// roster spellings ride unpinned the games catalog roster (print 18-28)
inline bool k22RosterMisspellApology()
    { return true; }

// the Listerine Brothers of Texas - millions killed upon contact the games
// catalog roster (print 18-28)
inline bool k22ListerineMillions()
    { return true; }

// the epithet Arrh the Insane - Shane Sadler of Florida the games catalog
// roster (print 18-28)
inline bool k22ArrhInsane()
    { return true; }

}   // namespace rules
