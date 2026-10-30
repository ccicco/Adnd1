// =========================================================================================
// Adnd1 - rules/t20.h
// The Dragon issue-20 opener part one - the Polynesian pantheon, the witch
// class ladder and the demonology grids
// census 862 -> 863.
//
// The opener of the issue-20 three-round shape - three of the five
// Curtiss-called chains pinned, the death stats and the demonic possession
// riding the part-two round. All pinned from The Dragon Vol. III No. 6
// (November 1978), the Curtiss-provided Dm20.pdf scan voice, print folio the
// PDF page minus two.
//
// The issue-20 print catches pinned as scanned: the contents page prints Vol.
// III No. 5 for issue 20, the Kampua-a move line prints 150 markless, the
// Demonette ladder cell runs 3 1 together, the love potion wear-off prints
// 155 chance per day, the demonology header prints B and D Variant, the
// achieved type I row double-assigns the 85, the type V row flanks both bands
// with type VI, and the Domonic Possession and Admodeus spellings ride the
// ink. Both inherited watches - the Sullin levels 7-9 and the brawling sequel
// - print nowhere in TD20 and ride to TD 21.
//
namespace rules {

// ---- the Polynesian pantheon (print 8-9 + 27) ----

// the mythos statline count - seventeen gods and goddesses, ten heroes and
// the two statted monsters, the Tuna and the Vahine-Hae the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythosStatlines()
    { return 29; }

// the god and goddess count - Tangaroa through Papa the mythos of Polynesia
// (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythosGods()
    { return 17; }

// the hero count - Kaulu through Rata the mythos of Polynesia (print 8-9 +
// 27, PDF 10-11 + 29)
inline int t20MythosHeroes()
    { return 10; }

// the statted monster count - the Tuna-of-the-Eternal-Waters and the
// Vahine-Hae; the Amakua, goblins, wood-sprites, ogres and nymphs print
// prose-only or as Monster Manual cross-references the mythos of Polynesia
// (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythosMonsters()
    { return 2; }

// the hero six-stat count - ten heroes, the six stats pinned with the
// exceptional-strength roll the mythos of Polynesia (print 8-9 + 27, PDF
// 10-11 + 29)
inline int t20HeroCount()
    { return 10; }

// the artifact count - the Great Helve of Hibiscus Wood and the Stick of
// Makalei the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythosArtifacts()
    { return 2; }

// the Great Helve of Hibiscus Wood is a plus 5 axe the mythos of Polynesia
// (print 8-9 + 27, PDF 10-11 + 29)
inline int t20GreatHelvePlus()
    { return 5; }

// the Great Helve damage floor - 10 of the 10-40 band the mythos of Polynesia
// (print 8-9 + 27, PDF 10-11 + 29)
inline int t20GreatHelveMin()
    { return 10; }

// the Great Helve damage ceiling - 40 of the 10-40 band the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20GreatHelveMax()
    { return 40; }

// the Stick of Makalei power count - attract fish, polymorph, control
// weather, animate objects, charm plants and part water the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MakaleiPowers()
    { return 6; }

// the hero armor class conversion - the printed Normal Man line adjudicated
// to the 1e unarmored 10, the conversion noted the mythos of Polynesia (print
// 8-9 + 27, PDF 10-11 + 29)
inline int t20MythosNormalManAc()
    { return 10; }

// the pantheon rides the Gods Semi-Gods and Heroes Supplement IV format, the
// system designed compatible with it the mythos of Polynesia (print 8-9 + 27,
// PDF 10-11 + 29)
inline bool t20MythosGdhFormat()
    { return true; }

// the heroes were born in non-human form and raised by their maternal
// grandparents, from whom they derived their magic the mythos of Polynesia
// (print 8-9 + 27, PDF 10-11 + 29)
inline bool t20HeroesRaisedByGrandparents()
    { return true; }

// Maui is very ugly and buffoonish and had eight heads the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline bool t20MauiEightHeads()
    { return true; }

// the Kampua-a move line prints 150 with no foot or inch mark - pinned as
// scanned, the lone markless move the mythos of Polynesia (print 8-9 + 27,
// PDF 10-11 + 29)
inline bool t20KampuaMovePrintCatch()
    { return true; }

// the armor class column - Tangaroa -3 through the Rongo 1 positive print
// catch and the Vahine-Hae 4, the heroes converted from the Normal Man line
// the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythAc(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return 0;
        case 2:
            return -2;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -2;
        case 6:
            return 1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return 0;
        case 10:
            return -4;
        case 11:
            return -1;
        case 12:
            return 0;
        case 13:
            return -2;
        case 14:
            return -2;
        case 15:
            return -4;
        case 16:
            return -3;
        case 17:
            return 10;
        case 18:
            return 10;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 10;
        case 25:
            return 10;
        case 26:
            return 10;
        case 27:
            return -1;
        case 28:
            return 4;
        default:
            return -99;
        }
    }

// the move column - the printed number with the mark dropped, the dual-move
// Makemake and Tinirau pinned at ground value, the Kampua-a 150 markless
// print catch the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythMove(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 30;
        case 11:
            return 20;
        case 12:
            return 20;
        case 13:
            return 150;
        case 14:
            return 20;
        case 15:
            return 30;
        case 16:
            return 25;
        case 17:
            return 12;
        case 18:
            return 12;
        case 19:
            return 12;
        case 20:
            return 12;
        case 21:
            return 12;
        case 22:
            return 12;
        case 23:
            return 12;
        case 24:
            return 12;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 22;
        case 28:
            return 15;
        default:
            return -99;
        }
    }

// the hit point column - the Vahine-Hae 40 floor through the Tangaroa 300
// ceiling, the Kariki 56 print catch the mythos of Polynesia (print 8-9 + 27,
// PDF 10-11 + 29)
inline int t20MythHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 250;
        case 2:
            return 250;
        case 3:
            return 250;
        case 4:
            return 250;
        case 5:
            return 240;
        case 6:
            return 225;
        case 7:
            return 220;
        case 8:
            return 220;
        case 9:
            return 200;
        case 10:
            return 200;
        case 11:
            return 200;
        case 12:
            return 170;
        case 13:
            return 150;
        case 14:
            return 140;
        case 15:
            return 100;
        case 16:
            return 100;
        case 17:
            return 90;
        case 18:
            return 80;
        case 19:
            return 90;
        case 20:
            return 60;
        case 21:
            return 80;
        case 22:
            return 90;
        case 23:
            return 140;
        case 24:
            return 110;
        case 25:
            return 56;
        case 26:
            return 110;
        case 27:
            return 220;
        case 28:
            return 40;
        default:
            return -99;
        }
    }

// the magic level column - the Wizard and Druid Nth level pinned as N, the
// See Below gods and See Above heroes as the -99 sentinel, the Nil lines
// pinned 0 the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythMagicLevel(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return -99;
        case 2:
            return -99;
        case 3:
            return 25;
        case 4:
            return -99;
        case 5:
            return -99;
        case 6:
            return 12;
        case 7:
            return 30;
        case 8:
            return 30;
        case 9:
            return 11;
        case 10:
            return -99;
        case 11:
            return -99;
        case 12:
            return -99;
        case 13:
            return -99;
        case 14:
            return 20;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return -99;
        case 21:
            return 22;
        case 22:
            return -99;
        case 23:
            return 18;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return -99;
        case 28:
            return -99;
        default:
            return -99;
        }
    }

// the magic class column - 0 Nil, 1 Wizard, 2 Druid, 3 the See Below and See
// Above sentinel class the mythos of Polynesia (print 8-9 + 27, PDF 10-11 +
// 29)
inline int t20MythMagicClass(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 3;
        default:
            return -99;
        }
    }

// the fighter level column - Lord Nth pinned as N, the Hina Myrmidon 6, the
// Haumea Swashbuckler 5, the Atea Superhero 8, the Papa Iwa and Kariki
// Champion 7 and the Vahine-Hae Veteran 1 rank names noted the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythFighterLevel(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 12;
        case 2:
            return 20;
        case 3:
            return 18;
        case 4:
            return 20;
        case 5:
            return 19;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 15;
        case 9:
            return 13;
        case 10:
            return 25;
        case 11:
            return 6;
        case 12:
            return 14;
        case 13:
            return 10;
        case 14:
            return 5;
        case 15:
            return 8;
        case 16:
            return 7;
        case 17:
            return 12;
        case 18:
            return 10;
        case 19:
            return 11;
        case 20:
            return 7;
        case 21:
            return 10;
        case 22:
            return 11;
        case 23:
            return 15;
        case 24:
            return 12;
        case 25:
            return 7;
        case 26:
            return 12;
        case 27:
            return 17;
        case 28:
            return 1;
        default:
            return -99;
        }
    }

// the psionic class column - every entity prints Nil, pinned 0 the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20MythPsionicClass(int b)
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
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return -99;
        }
    }

// the strength column - every hero 18 except the Kariki 15 the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroStr(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 15;
        case 9:
            return 18;
        default:
            return -99;
        }
    }

// the exceptional-strength roll column - 76, 01, 60, 20, 25, 30, the Maui 00
// pinned 0, the Tawhaki 05 and the Rata 55, the Kariki -99 sentinel the
// mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroStrRoll(int b)
    {
        switch (b) {
        case 0:
            return 76;
        case 1:
            return 1;
        case 2:
            return 60;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return -99;
        case 9:
            return 55;
        default:
            return -99;
        }
    }

// the intelligence column - the Ono Maui and Tawhaki 18 through the Kariki 5
// the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroInt(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 12;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 18;
        case 5:
            return 11;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 5;
        case 9:
            return 9;
        default:
            return -99;
        }
    }

// the wisdom column - the Maui 18 through the Kariki 3 the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroWis(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 9;
        case 5:
            return 10;
        case 6:
            return 18;
        case 7:
            return 14;
        case 8:
            return 3;
        case 9:
            return 5;
        default:
            return -99;
        }
    }

// the constitution column - the 18 band through the Tawhaki 15 the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroCon(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 17;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 15;
        case 8:
            return 15;
        case 9:
            return 12;
        default:
            return -99;
        }
    }

// the dexterity column - the 18 band through the Kariki 3 the mythos of
// Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroDex(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 3;
        case 9:
            return 14;
        default:
            return -99;
        }
    }

// the charisma column - the Tawhaki 18 through the Maui 3 print catch the
// mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
inline int t20HeroCha(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 13;
        case 2:
            return 14;
        case 3:
            return 11;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 3;
        case 7:
            return 18;
        case 8:
            return 6;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// ---- the witch class ladder (print 11-12 + 19) ----

// the witch level count - Medium 0 experience through the Demonette
// 1,500,000, the eighteen-title ladder the witch class (print 11-12 + 19, PDF
// 13-14 + 21)
inline int t20WitchTitles()
    { return 18; }

// the witch spell-level count - the eight spell lists the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSpellLevels()
    { return 8; }

// the witch intelligence requirement - at least 13 the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchIntMin()
    { return 13; }

// the witch wisdom requirement - at least 13 the witch class (print 11-12 +
// 19, PDF 13-14 + 21)
inline int t20WitchWisMin()
    { return 13; }

// the witch charisma requirement - at least 9 the witch class (print 11-12 +
// 19, PDF 13-14 + 21)
inline int t20WitchChaMin()
    { return 9; }

// the witch spell census - 10 first, 9 second, 8 third, 11 fourth, 10 fifth,
// 9 sixth, 10 seventh and 9 eighth level spells, 76 across the eight lists
// the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSpellTotalAll()
    { return 76; }

// the starred-spell census - the spells not hitherto known or treated
// differently: 6, 3, 7, 6, 5, 3, 6 and 8 across the eight lists, 44 of the 76
// the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSpellNewAll()
    { return 44; }

// the candle magic color count - red, blue, yellow, purple, gold and black
// the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20CandleColors()
    { return 6; }

// a witch may manufacture one candle per month the witch class (print 11-12 +
// 19, PDF 13-14 + 21)
inline int t20CandlesPerMonth()
    { return 1; }

// the candle burning rate - 3 days per turn of burning duration the witch
// class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20CandleDaysPerTurn()
    { return 3; }

// the candle burn ceiling - up to 10 turns, the magic taking effect when
// snuffed or burnt up the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20CandleBurnTurns()
    { return 10; }

// the black candle curse count - weakness, insanity, clumsiness, poverty,
// loneliness and exhaustion the witch class (print 11-12 + 19, PDF 13-14 +
// 21)
inline int t20CandleBlackCurses()
    { return 6; }

// the Voice command length - no longer than 7 words the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline int t20VoiceMaxWords()
    { return 7; }

// the Voice reuse limit - not more often than once in 3 turns on the same
// listeners the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20VoiceReuseTurns()
    { return 3; }

// the curse-lift price - the permanent transfer of 5 hit points with no rise
// in the hit points of the one saved the witch class (print 11-12 + 19, PDF
// 13-14 + 21)
inline int t20TransferCurseHp()
    { return 5; }

// the prime attribute ladder - 5 hit points up to 12 the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo12()
    { return 5; }

// the prime attribute ladder - 7 hit points from 12 to 13 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo13()
    { return 7; }

// the prime attribute ladder - 8 hit points from 13 to 14 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo14()
    { return 8; }

// the prime attribute ladder - 10 hit points from 14 to 15 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo15()
    { return 10; }

// the prime attribute ladder - 10 hit points from 15 to 16 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo16()
    { return 10; }

// the prime attribute ladder - 20 hit points from 16 to 17 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo17()
    { return 20; }

// the prime attribute ladder - 25 hit points from 17 to 18 the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20TransferTo18()
    { return 25; }

// the enchant item price - 1 hit point permanently transferred per 1000 gold
// pieces of item value the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20EnchantHpPer1000Gp()
    { return 1; }

// the familiar ceiling - any animal of less than 1 hit die, such as a cat or
// bat the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20FamiliarMaxHd()
    { return 1; }

// the familiar death band floor - the witch takes 3-24 points of damage if it
// is killed the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20FamiliarDeathMin()
    { return 3; }

// the familiar death band ceiling - 24 of the 3-24 band the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20FamiliarDeathMax()
    { return 24; }

// witches are neutral, dedicated neither to good nor evil, though an
// individual witch may be good or evil the witch class (print 11-12 + 19, PDF
// 13-14 + 21)
inline bool t20WitchNeutral()
    { return true; }

// the class is limited to women to balance the fighter-type professions, a
// matter of discretion for each DM the witch class (print 11-12 + 19, PDF
// 13-14 + 21)
inline bool t20WitchFemaleDefault()
    { return true; }

// witches receive hit dice and level as magic-users, the same restrictions on
// weaponry and armour the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline bool t20WitchMuHitDice()
    { return true; }

// witches obtain the benefits and disadvantages of magic-users, the saving
// throws and the reading of certain tomes, unless otherwise stated the witch
// class (print 11-12 + 19, PDF 13-14 + 21)
inline bool t20WitchMuSaves()
    { return true; }

// the witch bears the same relationship to the druid as a magic-user toward a
// cleric of his own alignment, the forces of nature worshipped by druids the
// witch class (print 11-12 + 19, PDF 13-14 + 21)
inline bool t20WitchNatureKinToDruids()
    { return true; }

// druid scrolls may be read with no chance of failure the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline bool t20DruidScrollsNoFail()
    { return true; }

// magic or illusion scrolls have a 10 percent chance of backfire, clerical
// scrolls cannot be utilized though the witch can read them the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline bool t20MagicScrollBackfire()
    { return true; }

// there may be only one bag of holding per witch in existence at any one
// time, used by no other person, a month to replace the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline bool t20BagOfHoldingUnique()
    { return true; }

// the hit-point transfer is the only way witches can manufacture magic items
// other than potions before the 17th level the witch class (print 11-12 + 19,
// PDF 13-14 + 21)
inline bool t20EnchantOnlyItemRoute()
    { return true; }

// the Demonette row print catch - the seventh and eighth level spell counts
// run together as 3 1 in one cell, pinned as scanned the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline bool t20DemonetteCellPrintCatch()
    { return true; }

// the love potion print catch - the cumulative wear-off chance prints 155
// chance per day, read 15 percent, pinned as scanned the witch class (print
// 11-12 + 19, PDF 13-14 + 21)
inline bool t20LovePotionPrintCatch()
    { return true; }

// the experience column - 0 through 1,500,000, the blank spell cells of the
// printed grid pinned 0 the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3000;
        case 2:
            return 6000;
        case 3:
            return 12000;
        case 4:
            return 25000;
        case 5:
            return 55000;
        case 6:
            return 80000;
        case 7:
            return 120000;
        case 8:
            return 200000;
        case 9:
            return 300000;
        case 10:
            return 400000;
        case 11:
            return 525000;
        case 12:
            return 650000;
        case 13:
            return 800000;
        case 14:
            return 900000;
        case 15:
            return 1000000;
        case 16:
            return 1250000;
        case 17:
            return 1500000;
        default:
            return -99;
        }
    }

// the first level spell column - 1 at Medium through 6 at Demonette the witch
// class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return -99;
        }
    }

// the second level spell column - blank through Soothsayer 2, 6 at Demonette
// the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return -99;
        }
    }

// the third level spell column - blank through Sibyl 1, 6 at Demonette the
// witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp3(int b)
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
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return -99;
        }
    }

// the fourth level spell column - blank through Witch 1, 6 at Demonette the
// witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp4(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 6;
        default:
            return -99;
        }
    }

// the fifth level spell column - blank through Sapphire 1, 6 at Demonette the
// witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp5(int b)
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
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 6;
        default:
            return -99;
        }
    }

// the sixth level spell column - blank through Emerald 1, 5 at Demonette the
// witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp6(int b)
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
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 5;
        default:
            return -99;
        }
    }

// the seventh level spell column - blank through Crystal 2, 3 at Demonette
// the witch class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp7(int b)
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
            return 3;
        default:
            return -99;
        }
    }

// the eighth level spell column - the Demonette 1 alone the witch class
// (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchSp8(int b)
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
            return 1;
        default:
            return -99;
        }
    }

// the list total column - the ten-spell first and seventh, the eleven-spell
// fourth, the nine-spell second sixth and eighth the witch class (print 11-12
// + 19, PDF 13-14 + 21)
inline int t20WitchListTotal(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 8;
        case 3:
            return 11;
        case 4:
            return 10;
        case 5:
            return 9;
        case 6:
            return 10;
        case 7:
            return 9;
        default:
            return -99;
        }
    }

// the starred new-spell column - the eight starred of nine at eighth level,
// the seven of eight at third, the lone unstarred Reincarnation the witch
// class (print 11-12 + 19, PDF 13-14 + 21)
inline int t20WitchListNew(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 6;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// ---- the demonology grids (print 13-15) ----

// the name research count - the nine name-of rows from the demon prince ninth
// level equivalent through the type I third the demonology grids (print
// 13-15, PDF 15-17)
inline int t20DemonNameRows()
    { return 9; }

// the level-achieved grid count - the seven rows from type I through Prince
// the demonology grids (print 13-15, PDF 15-17)
inline int t20DemonAchievedRows()
    { return 7; }

// the failure table count - the six failure bands from the 01-35 total fizzle
// through the 96-00 two-higher demon the demonology grids (print 13-15, PDF
// 15-17)
inline int t20DemonFailureRows()
    { return 6; }

// the true names change each seventy years, whereupon new names must be
// researched and all pacts renewed the demonology grids (print 13-15, PDF
// 15-17)
inline int t20DemonNameCycleYears()
    { return 70; }

// a name spoken aloud without the ritual bonds the speaker - a 50 percent or
// better chance the demon appears and snatches him back to its own plane the
// demonology grids (print 13-15, PDF 15-17)
inline int t20UnprotectedSnatchPct()
    { return 50; }

// the ritual expense floor - from 1 gold piece per spell level of the ritual
// the demonology grids (print 13-15, PDF 15-17)
inline int t20DemonCostMin()
    { return 1; }

// the ritual expense ceiling - up to 4000 gold pieces per spell level of the
// ritual the demonology grids (print 13-15, PDF 15-17)
inline int t20DemonCostMax()
    { return 4000; }

// the fifth level conjuration requires one assistant the demonology grids
// (print 13-15, PDF 15-17)
inline int t20AssistFifth()
    { return 1; }

// the sixth level conjuration requires two assistants the demonology grids
// (print 13-15, PDF 15-17)
inline int t20AssistSixth()
    { return 2; }

// the seventh level conjuration requires three assistants the demonology
// grids (print 13-15, PDF 15-17)
inline int t20AssistSeventh()
    { return 3; }

// the eighth level conjuration requires four assistants the demonology grids
// (print 13-15, PDF 15-17)
inline int t20AssistEighth()
    { return 4; }

// the ninth level conjuration requires four assistants the demonology grids
// (print 13-15, PDF 15-17)
inline int t20AssistNinth()
    { return 4; }

// the failure ladder basis - the per-level penalty counts the levels the
// operator is below 20th the demonology grids (print 13-15, PDF 15-17)
inline int t20OperatorLevelBasis()
    { return 20; }

// a basic 5 percent chance of failure for each level the operator is below
// 20th the demonology grids (print 13-15, PDF 15-17)
inline int t20FailPerLevelBelow()
    { return 5; }

// an additional 5 percent chance of failure for each assistant required,
// regardless of level the demonology grids (print 13-15, PDF 15-17)
inline int t20FailPerAssistant()
    { return 5; }

// the exorcism chance against type III and below - 50 percent the demonology
// grids (print 13-15, PDF 15-17)
inline int t20ExorcismLowPct()
    { return 50; }

// the exorcism chance on types up to and including VI - 25 percent the
// demonology grids (print 13-15, PDF 15-17)
inline int t20ExorcismMidPct()
    { return 25; }

// the exorcism chance versus princes - 10 percent the demonology grids (print
// 13-15, PDF 15-17)
inline int t20ExorcismPrincePct()
    { return 10; }

// knowing the name of the being increases the exorcism chance by 40 percent
// the demonology grids (print 13-15, PDF 15-17)
inline int t20ExorcismNameBonus()
    { return 40; }

// the pit fiend compromise - a soul indentured for 100000 years of service,
// the princes never settling for less than the soul forever the demonology
// grids (print 13-15, PDF 15-17)
inline int t20PitFiendServiceYears()
    { return 100000; }

// the assistants may be hirelings or followers of any level but all must be
// either magic-users or clerics the demonology grids (print 13-15, PDF 15-17)
inline bool t20AssistCasterOnly()
    { return true; }

// a sacrifice is absolutely necessary to make a pact - a living creature, the
// low types satisfied with a mouse or rat the demonology grids (print 13-15,
// PDF 15-17)
inline bool t20SacrificeRequiredForPact()
    { return true; }

// princes and archdevils will accept nothing less than human sacrifices the
// demonology grids (print 13-15, PDF 15-17)
inline bool t20PrincesHumanSacrificeOnly()
    { return true; }

// demons do not know devils names and vice versa, and princes and archfiends
// will not tell another of their own rank the demonology grids (print 13-15,
// PDF 15-17)
inline bool t20DemonDevilNameSplit()
    { return true; }

// an operator may sell his soul for eternity only once, though he may bind
// himself to as many years of service as he cares to the demonology grids
// (print 13-15, PDF 15-17)
inline bool t20SoulSoldOnce()
    { return true; }

// a low level devil will not knowingly act contrary to the wishes of a higher
// level devil - demons will do whatever they can get away with the demonology
// grids (print 13-15, PDF 15-17)
inline bool t20DevilsObeyHierarchy()
    { return true; }

// the exorcism is a generalized ritual in which the name of the being need
// not be known, there generally not being time to research it the demonology
// grids (print 13-15, PDF 15-17)
inline bool t20ExorcismNeedsNoName()
    { return true; }

// if a summoned demon is not controlled it will attempt to seize the prime
// operator and gate him back to its own plane, and slay any assistants
// present the demonology grids (print 13-15, PDF 15-17)
inline bool t20FailureSnatchesOperator()
    { return true; }

// the type I achieved row print catch - the exact band prints 16-85 and the
// higher band 85-00, the 85 double-assigned, pinned as scanned the demonology
// grids (print 13-15, PDF 15-17)
inline bool t20TypeIOverlapPrintCatch()
    { return true; }

// the type V achieved row print catch - both flanking bands print type VI,
// the 01-30 lower and the 91-00 higher, no type IV band, pinned as scanned
// the demonology grids (print 13-15, PDF 15-17)
inline bool t20TypeVBothNeighborsPrintCatch()
    { return true; }

// upon making a pact a demon teaches the operator spells it knows that the
// operator can use except the wish and gate, tells the names of beings of its
// own level or lower, and reveals the nearest hidden treasure the demonology
// grids (print 13-15, PDF 15-17)
inline bool t20PactThreeGrants()
    { return true; }

// the equivalent spell level column - the ninth level prince research through
// the third level type I, the TD 5 spell research rules cross-referenced the
// demonology grids (print 13-15, PDF 15-17)
inline int t20DemonNameLevel(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 8;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 3;
        default:
            return -99;
        }
    }

// the first band floor column - every row opens at 01 the demonology grids
// (print 13-15, PDF 15-17)
inline int t20DemonBand1Min(int b)
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
        default:
            return -99;
        }
    }

// the first band ceiling column - 15 through 50 the demonology grids (print
// 13-15, PDF 15-17)
inline int t20DemonBand1Max(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 50;
        default:
            return -99;
        }
    }

// the second band floor column - 16 through 51 the demonology grids (print
// 13-15, PDF 15-17)
inline int t20DemonBand2Min(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 21;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 31;
        case 5:
            return 41;
        case 6:
            return 51;
        default:
            return -99;
        }
    }

// the second band ceiling column - the 85 overlap print catch at type I, 80,
// 85, 90, 95 and 75 the demonology grids (print 13-15, PDF 15-17)
inline int t20DemonBand2Max(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 80;
        case 2:
            return 80;
        case 3:
            return 85;
        case 4:
            return 90;
        case 5:
            return 95;
        case 6:
            return 75;
        default:
            return -99;
        }
    }

// the third band floor column - the 85 overlap at type I, 81 through 96 the
// demonology grids (print 13-15, PDF 15-17)
inline int t20DemonBand3Min(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 81;
        case 2:
            return 81;
        case 3:
            return 86;
        case 4:
            return 91;
        case 5:
            return 96;
        case 6:
            return 76;
        default:
            return -99;
        }
    }

// the third band ceiling column - every band closes at 00 adjudicated to 100
// the demonology grids (print 13-15, PDF 15-17)
inline int t20DemonBand3Max(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        case 2:
            return 100;
        case 3:
            return 100;
        case 4:
            return 100;
        case 5:
            return 100;
        case 6:
            return 100;
        default:
            return -99;
        }
    }

// the band floor column - 01, 36, 46, 56, 86 and 96 the demonology grids
// (print 13-15, PDF 15-17)
inline int t20FailBandMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 46;
        case 3:
            return 56;
        case 4:
            return 86;
        case 5:
            return 96;
        default:
            return -99;
        }
    }

// the band ceiling column - 35, 45, 55, 85, 95 and 00 adjudicated to 100 the
// demonology grids (print 13-15, PDF 15-17)
inline int t20FailBandMax(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 45;
        case 2:
            return 55;
        case 3:
            return 85;
        case 4:
            return 95;
        case 5:
            return 100;
        default:
            return -99;
        }
    }

// the outcome code column - 1 fizzle, 2 lower uncontrolled, 3 lower
// controlled, 4 exact uncontrolled, 5 one higher uncontrolled, 6 two higher
// uncontrolled the demonology grids (print 13-15, PDF 15-17)
inline int t20FailOutcome(int b)
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
        default:
            return -99;
        }
    }

}   // namespace rules
