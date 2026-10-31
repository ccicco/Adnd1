    // ---- R955 issue-24 alignment pantheon audit ----
    // the alignment pantheon audit - the eighteen prime alignments, the
    // twenty-one prime deities, the four elemental lords, the five sons of
    // Thakta Tylden and the Headsman of Marly
    {
        using namespace rules;
        int bad = 0;
    if (s24PrimeAlignments() != 18
            || s24LawSlots() != 6
            || s24NeutralSlots() != 6
            || s24ChaosSlots() != 6
            || s24PrimeDeities() != 21
            || s24ElementalLords() != 4
            || s24SonsOfThakta() != 5
            || s24StandardSpellList() != 14
            || s24GodHitMissRoll() != 1
            || s24PantheonCount() != 21
            || s24SonsCount() != 5
            || s24AlignsCount() != 18
            || s24GodBaseHp() != 300
            || s24ElementalHp() != 200
            || s24MoriliromTurnRange() != 200
            || s24WhickerwindHp() != 40
            || s24WhickerwindMove() != 56
            || s24CyrulliaUnicorns() != 6
            || s24CyrulliaMiraclePct() != 5
            || s24CyrulliaMiracleLevel() != 7
            || s24MarlyTalismanPct() != 10
            || s24MarlyAidPct() != 5
            || s24MarlyNonLawfulAidPct() != 1
            || s24HeadsmanHp() != 150
            || s24HeadsmanAc() != -2
            || s24HeadsmanMr() != 100
            || s24HeadsmanAxeBonus() != 5
            || s24HeadsmanHeight() != 8
            || s24SedjimaAuguryHalfPct() != 3
            || s24SedjimaContactPct() != 2
            || s24SlarskenHits() != 4
            || s24SlarskenDamageAdd() != 10
            || s24TholtanoomaLawfulAdd() != 4
            || s24TholtanoomaChaoticSub() != 4
            || s24BodyguardAc() != -2
            || s24BodyguardLevel() != 10
            || s24TholtanoomaRewardPct() != 5
            || s24TholtanoomaCouragePct() != 5
            || s24ManturinLightningDice() != 15
            || s24ManturinStarPoints() != 8
            || s24ManturinFireballDice() != 10
            || s24ManturinJavelinPoints() != 20
            || s24ManturinStarGrant() != 15
            || s24RilliflohamHeight() != 40
            || s24RilliflohamSummonLo() != 3
            || s24RilliflohamSummonHi() != 18
            || s24RilliflohamRewardPct() != 10
            || s24RasanFireballDice() != 10
            || s24RasanFavorPct() != 5
            || s24DemyuritasTeleportLo() != 1
            || s24DemyuritasTeleportHi() != 20
            || s24ElementalSummonLo() != 1
            || s24ElementalSummonHi() != 12
            || s24HaraHits() != 6
            || s24ZkraclFireballDice() != 20
            || s24BleskutaServantsLo() != 1
            || s24BleskutaServantsHi() != 6
            || s24BleskutaServantsPct() != 3
            || s24TemanamatHealingPct() != 10
            || s24GolodClaws() != 4
            || s24GolodUndeadPct() != 5
            || s24GolodRewardPct() != 5
            || s24SogDiameter() != 40
            || s24SogFearRadius() != 100
            || s24SogAidPct() != 5
            || s24SogAidLo() != 1
            || s24SogAidHi() != 10
            || s24KarnawennTentaclePct() != 10
            || s24ThaktaWhipTargets() != 3
            || s24ThaktaWeaponPct() != 10
            || s24HiskAttentionPct() != 5
            || s24RakunthHitAdd() != 6
            || s24RakunthDmgAdd() != 8
            || !s24LawEquatedGood()
            || !s24PerpendicularAxes()
            || !s24RulesLawFavoritism()
            || !s24NineFail()
            || !s24NiceNasty()
            || !s24GodsWorshipMade()
            || !s24WorshipContest()
            || !s24MoralityFlexible()
            || !s24SplinterAlignments()
            || !s24NoAlignmentTongues()
            || !s24StandardSpellsAtWill()
            || !s24GodsAutoHit()
            || !s24GodsBanished()
            || !s24PronounNote()
            || !s24GenConChallenge()
            || !s24MoriliroomTwice()
            || !s24FeetMoveDrift()
            || !s24WhickerwindPrint()
            || !s24RichlyApparelated()
            || !s24WerebbarTwice()
            || !s24Psuedopods()
            || !s24CivilizationTopping()
            || !s24TholtanoomaHeader()
            || !s24MoriliromPhysicalProof()
            || !s24MoriliromBeyondFlattery()
            || !s24CyrulliaStaffDuality()
            || !s24CyrulliaOnceCall()
            || !s24MarlySpies()
            || !s24SedjimaPassive()
            || !s24SlarskenMatriarch()
            || !s24SlarskenCovets()
            || !s24TholtanoomaBodyguard()
            || !s24ManturinAidEnemies()
            || !s24ManturinNeutralPaladins()
            || !s24RilliflohamFireNormal()
            || !s24RilliflohamWildConspire()
            || !s24RasanUsurper()
            || !s24RasanWeaklings()
            || !s24DemyuritasBards()
            || !s24GunggerCrossesWater()
            || !s24HaraProjectileProof()
            || !s24ZkraclSpiesFires()
            || !s24ZkraclWaterProof()
            || !s24ShaliroiHeatProof()
            || !s24HiskWeaponsAppear()
            || !s24HiskGallarna()
            || !s24KarnawennMadness()
            || !s24KarnawennOneTentacle()
            || !s24BleskutaGuises()
            || !s24TemanamatSatyrs()
            || !s24GolodYellowSign()
            || !s24GolodSacrifice()
            || !s24GolodUndeadService()
            || !s24SogBestialServants()
            || !s24ThaktaArmageddon()
            || !s24ThaktaCowardKobolds()
            || !s24HeadsmanAlways()
            || !s24AmbitionTwice()
            || !s24WarTwice()
        )
            ++bad;
        // the pantheon grid - the twenty-one prime deities in roster order,
        // six Law, five Neutrality singles plus the four elemental lords, six
        // Chaos, with the printed armor class, hit points, move, second move
        // and damage pair
        int CPa[21][6] = {
            {-99,300,-99,-99,-99,-99},
            {-4,300,18,-99,-99,-99},
            {-4,300,24,-99,4,40},
            {0,300,12,-99,-99,-99},
            {-5,300,36,-99,-99,-99},
            {-6,300,24,-99,10,100},
            {-5,300,24,-99,-99,-99},
            {-3,300,12,-99,5,50},
            {-4,300,12,-99,8,80},
            {-2,300,24,-99,-99,-99},
            {-4,200,12,-99,10,100},
            {-2,200,72,-99,3,30},
            {-2,200,36,-99,5,50},
            {-2,200,12,36,3,30},
            {-5,300,21,-99,-99,-99},
            {-6,300,-99,-99,-99,-99},
            {-5,300,18,-99,6,60},
            {-1,300,12,-99,-99,-99},
            {-4,300,24,-99,3,30},
            {-2,300,18,-99,-99,-99},
            {-6,300,24,-99,4,40},
            };
        int nPa[6] = {0,0,0,0,0,0};
        int ePa[6] = {1,0,2,20,10,10};
        for (int b = 0;
             b < s24PantheonCount();
             ++b) {
            int vals[6];
            vals[0] = s24GodAc(b);
            vals[1] = s24GodHp(b);
            vals[2] = s24GodMove(b);
            vals[3] = s24GodMove2(b);
            vals[4] = s24GodDmgLo(b);
            vals[5] = s24GodDmgHi(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CPa[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nPa[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nPa[c] != ePa[c])
                ++bad;
        // the sons grid - the five Thakta Tylden sons, the Lakunth Weretiger,
        // the Pakunth Stone Giant, the Rakunth Orcish demi-god, the Quakunth
        // winged Troll and the Dakunth Type VI Demon printing on page 39
        int CSn[5][5] = {
            {-1,75,-99,15,-99},
            {4,45,50,-99,-99},
            {-2,60,-99,-99,3},
            {2,45,-99,10,-99},
            {2,90,85,20,-99},
            };
        int nSn[5] = {0,0,0,0,0};
        int eSn[5] = {0,0,3,2,4};
        for (int b = 0;
             b < s24SonsCount();
             ++b) {
            int vals[5];
            vals[0] = s24SonAc(b);
            vals[1] = s24SonHp(b);
            vals[2] = s24SonMr(b);
            vals[3] = s24SonLevel(b);
            vals[4] = s24SonAttacks(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CSn[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nSn[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nSn[c] != eSn[c])
                ++bad;
        // the alignment roster - the eighteen prime alignments in print order
        // with the axis, the slot letter and the prime deity index into the
        // pantheon grid, the Four Elements pointing at Gungger, the first of
        // the four lords
        int CAl[18][3] = {
            {0,0,0},
            {0,1,1},
            {0,2,2},
            {0,3,3},
            {0,4,4},
            {0,5,5},
            {1,0,6},
            {1,1,7},
            {1,2,8},
            {1,3,9},
            {1,4,10},
            {1,5,14},
            {2,0,15},
            {2,1,16},
            {2,2,17},
            {2,3,18},
            {2,4,19},
            {2,5,20},
            };
        for (int b = 0;
             b < s24AlignsCount();
             ++b) {
            int vals[3];
            vals[0] = s24AlignAxis(b);
            vals[1] = s24AlignSlot(b);
            vals[2] = s24AlignDeity(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CAl[b][c])
                    ++bad;
            }
        }
        // the frame - eighteen alignments at six per axis, twenty-one prime
        // deities, four elemental lords, five sons, the fourteen-spell
        // standard list the alignment pantheon variant (print 34+36-39)
    if (s24PrimeAlignments() != 18
            || s24LawSlots() != 6
            || s24NeutralSlots() != 6
            || s24ChaosSlots() != 6
            || s24PrimeDeities() != 21
            || s24ElementalLords() != 4
            || s24SonsOfThakta() != 5
            || s24StandardSpellList() != 14
        )
            ++bad;
        // the deity frame - the three-hundred prime and two-hundred elemental
        // hit points, the one-in-twenty miss the alignment pantheon variant
        // (print 34+36-39)
    if (s24GodBaseHp() != 300
            || s24ElementalHp() != 200
            || s24GodHitMissRoll() != 1
        )
            ++bad;
        // the Headsman of Marly - armor class minus two, one hundred fifty
        // hit points, total magic resistance and the plus-five two-handed
        // vorpal axe the alignment pantheon variant (print 34+36-39)
    if (s24HeadsmanHp() != 150
            || s24HeadsmanAc() != -2
            || s24HeadsmanMr() != 100
            || s24HeadsmanAxeBonus() != 5
            || s24HeadsmanHeight() != 8
        )
            ++bad;
        // the High Law and Harmony pins - the two-hundred-foot Chaotic turn
        // range, the Whickerwind pegasus, the six unicorns, the five-percent
        // seventh-level miracle the alignment pantheon variant (print
        // 34+36-39)
    if (s24MoriliromTurnRange() != 200
            || s24WhickerwindHp() != 40
            || s24WhickerwindMove() != 56
            || s24CyrulliaUnicorns() != 6
            || s24CyrulliaMiraclePct() != 5
            || s24CyrulliaMiracleLevel() != 7
        )
            ++bad;
        // the Inquisitor percentages - the ten-percent talisman, the
        // five-percent material aid, the one percent for the non-Lawful the
        // alignment pantheon variant (print 34+36-39)
    if (s24MarlyTalismanPct() != 10
            || s24MarlyAidPct() != 5
            || s24MarlyNonLawfulAidPct() != 1
        )
            ++bad;
        // the Knowledge god - the one-and-a-half-percent Augury bonus pinned
        // as three half-percent units, the two-percent Contact Other Plane
        // bonus the alignment pantheon variant (print 34+36-39)
    if (s24SedjimaAuguryHalfPct() != 3
            || s24SedjimaContactPct() != 2
        )
            ++bad;
        // the Evolution god - four strikes per round for plus ten damage with
        // any weapon the alignment pantheon variant (print 34+36-39)
    if (s24SlarskenHits() != 4
            || s24SlarskenDamageAdd() != 10
        )
            ++bad;
        // the War god of Law - the plus-four and minus-four presence, the
        // tenth-level Paladin Bodyguard at minus two, the two five-percent
        // rewards the alignment pantheon variant (print 34+36-39)
    if (s24TholtanoomaLawfulAdd() != 4
            || s24TholtanoomaChaoticSub() != 4
            || s24BodyguardAc() != -2
            || s24BodyguardLevel() != 10
            || s24TholtanoomaRewardPct() != 5
            || s24TholtanoomaCouragePct() != 5
        )
            ++bad;
        // the Balance titan - the right-pan fifteen-dice lightning, the
        // left-pan eight-pointed stars into ten-dice fireballs, the
        // twenty-point javelins and fifteen-point stars the alignment
        // pantheon variant (print 34+36-39)
    if (s24ManturinLightningDice() != 15
            || s24ManturinStarPoints() != 8
            || s24ManturinFireballDice() != 10
            || s24ManturinJavelinPoints() != 20
            || s24ManturinStarGrant() != 15
        )
            ++bad;
        // the Nature, Ambition and Esthetics pins - the forty-foot treant
        // with his three-to-eighteen summons and ten-percent reward, the
        // ten-dice fireballs and five-percent favor, the one-to-twenty-hex
        // teleport the alignment pantheon variant (print 34+36-39)
    if (s24RilliflohamHeight() != 40
            || s24RilliflohamSummonLo() != 3
            || s24RilliflohamSummonHi() != 18
            || s24RilliflohamRewardPct() != 10
            || s24RasanFireballDice() != 10
            || s24RasanFavorPct() != 5
            || s24DemyuritasTeleportLo() != 1
            || s24DemyuritasTeleportHi() != 20
        )
            ++bad;
        // the elemental lords - the one-to-twelve summons, the six Hara hits,
        // the twenty-dice Zkracl fireball at save for half the alignment
        // pantheon variant (print 34+36-39)
    if (s24ElementalSummonLo() != 1
            || s24ElementalSummonHi() != 12
            || s24HaraHits() != 6
            || s24ZkraclFireballDice() != 20
        )
            ++bad;
        // the Chaos middle - the Bleskuta one-to-six servants at three
        // percent, the Temanamat ten-percent-per-level healing, the four
        // Golod claws with the two five-percent rolls the alignment pantheon
        // variant (print 34+36-39)
    if (s24BleskutaServantsLo() != 1
            || s24BleskutaServantsHi() != 6
            || s24BleskutaServantsPct() != 3
            || s24TemanamatHealingPct() != 10
            || s24GolodClaws() != 4
            || s24GolodUndeadPct() != 5
            || s24GolodRewardPct() != 5
        )
            ++bad;
        // the Devolution and High Chaos pins - the forty-foot body, the
        // one-hundred-foot permanent Fear, the five-percent one-to-ten-round
        // doubling, the ten-percent tentacle the alignment pantheon variant
        // (print 34+36-39)
    if (s24SogDiameter() != 40
            || s24SogFearRadius() != 100
            || s24SogAidPct() != 5
            || s24SogAidLo() != 1
            || s24SogAidHi() != 10
            || s24KarnawennTentaclePct() != 10
        )
            ++bad;
        // the Chaos War and Battle Glory pins - the three-target whip, the
        // ten-percent weapon reward, the Rakunth plus six and plus eight, the
        // five-percent Hisk attention the alignment pantheon variant (print
        // 34+36-39)
    if (s24ThaktaWhipTargets() != 3
            || s24ThaktaWeaponPct() != 10
            || s24RakunthHitAdd() != 6
            || s24RakunthDmgAdd() != 8
            || s24HiskAttentionPct() != 5
        )
            ++bad;
        // the Cyrullia row - armor class minus four, three hundred hit
        // points, move eighteen - and the Morilirom irrelevant armor class
        // with the two instantaneous-move sentinels of Morilirom and
        // Karnawenn the alignment pantheon variant (print 34+36-39)
    if (s24GodAc(1) != -4
            || s24GodHp(1) != 300
            || s24GodMove(1) != 18
            || s24GodAc(0) != -99
            || s24GodMove(0) != -99
            || s24GodMove(15) != -99
        )
            ++bad;
        // the elemental and damage spot checks - the Hara seventy-two move,
        // the Shaliroi thirty-six water move, the Rillifloham eight-to-eighty
        // fists, the Sog-Morthoth damage sentinel and the Thakta Tylden whip
        // four to forty the alignment pantheon variant (print 34+36-39)
    if (s24GodAc(11) != -2
            || s24GodMove(11) != 72
            || s24GodMove2(13) != 36
            || s24GodMove2(0) != -99
            || s24GodDmgLo(8) != 8
            || s24GodDmgHi(8) != 80
            || s24GodDmgLo(19) != -99
            || s24GodDmgHi(20) != 40
        )
            ++bad;
        // the Lakunth row - the fifteenth-level Weretiger at minus one and
        // seventy-five - and the Pakunth Stone Giant at four and forty-five
        // the alignment pantheon variant (print 34+36-39)
    if (s24SonAc(0) != -1
            || s24SonHp(0) != 75
            || s24SonLevel(0) != 15
            || s24SonAc(1) != 4
            || s24SonHp(1) != 45
        )
            ++bad;
        // the Dakunth row - the twentieth-level Type VI Demon at ninety hit
        // points and eighty-five percent resistance - with the Rakunth three
        // attacks and the Pakunth fifty the alignment pantheon variant (print
        // 34+36-39)
    if (s24SonAc(4) != 2
            || s24SonHp(4) != 90
            || s24SonMr(4) != 85
            || s24SonLevel(4) != 20
            || s24SonAttacks(2) != 3
            || s24SonMr(1) != 50
        )
            ++bad;
        // the roster axes in order with the High Neutrality Manturin, the
        // Battle Glory Hisk and the High Chaos Karnawenn indexes the
        // alignment pantheon variant (print 34+36-39)
    if (s24AlignAxis(0) != 0
            || s24AlignAxis(6) != 1
            || s24AlignAxis(12) != 2
            || s24AlignDeity(6) != 6
            || s24AlignDeity(11) != 14
            || s24AlignDeity(12) != 15
        )
            ++bad;
        // the two War slots closing Law and Chaos at the Tholtanooma and
        // Thakta Tylden rows, the Four Elements pointing at Gungger the
        // alignment pantheon variant (print 34+36-39)
    if (s24AlignSlot(5) != 5
            || s24AlignSlot(17) != 5
            || s24AlignDeity(10) != 10
            || s24AlignDeity(17) != 20
            || s24AlignSlot(2) != 2
        )
            ++bad;
        printf("R955 issue-24 alignment pantheon audit: bad %d\n", bad);
        if (bad) return 1;
    }
