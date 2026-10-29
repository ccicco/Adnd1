    // ---- R897 fighting sub-classes audit ----
    // THE FIGHTING SUB-CLASSES ROUND - round C of the issue-3 walk.
    // Childers/Kay's Samurai: the dexterity-above-15 gate pinned as 16, any
    // alignment tending neutral, the daisho and yumi preference, the
    // vendetta-or-seppeku on katana loss, the special-but-non-magical
    // Japanese blades with 9+ identification and 13+ exact reading, the
    // katana and wakizashi critical-hit tables (the 'above to hit' numbers 8+
    // to 5+, the automatic critical bands pinned as their low rolls,
    // encumbrances and values), the one-step loss in non-Samurai or
    // single-handed hands with the zero floor, the two-weapon permission, the
    // three-band critical blow table (25 percent or 6 with the 1-4 limb roll,
    // 50 percent or 12, the decapitation), the five-point dexterity ladder at
    // 8,000 through 616,000, the five-grade Japanese armor run E through A at
    // 45 pounds maximum with the shield seldom, the judo rules (empty hands
    // only, the 1-2 turn recovery, 1-4 damage on 19-20 at +5 percent per 4
    // levels, the subdue on 20 at +5 percent per 6 levels), and the yumi
    // costs. Pickens' Berserker: the highly experimental human NEUTRAL,
    // Strength and Constitution above 9 pinned as 10, Intelligence below 9
    // pinned as 8, armor class no better than 6 at first level, no magical
    // armor or shields, double kill points until the wereshape, never
    // psionic, the five clans with their advance-as codes, wereshape levels,
    // follower levels, maximum dice and Clanmaster levels, +1 armor class per
    // two levels, the level abilities (surprise at 4th, detection and the
    // 4th-level Companion at 6th, hiring at 10th at -2 loyalty capped 15),
    // the 2-12 Followers at 16-plus loyalty with the Bard of level 3-6 never
    // replaced, the three percentile follower rolls, the berserking chance
    // (10 base, +20 shield bite, +10 per round cumulative, +10 per witnessed
    // death, the Companion's death automatic), the berserk edges (+2 attacks,
    // +6 with a magic sword, psionic immunity) and locks (no withdrawal), the
    // fit's end (10 percent turn-on less 1 percent per level to a 1 percent
    // minimum, 0 for a Clanmaster, the full turn of rest), never causing
    // lycanthropy, and the footnote adjustments by clan. HONEST BOUNDARIES:
    // the OCR's duplicate Magic-User follower row pins as scanned; the yumi
    // armor-class modifier grid garbles beyond numeric pinning - the OCR
    // stacked two modifier rows into single tokens, no figure pixels to check
    // - and pins nothing, the yumi costs and encumbrances pinned instead;
    // both sub-classes ride the variant layer, the Berserker experimental per
    // its author's caution.
    {
        using namespace rules;
        int bad = 0;
    if (fscSamDexMin() != 16
            || fscSamIdBladeIntMin() != 9
            || fscSamIdExactIntMin() != 13
            || fscSamBladeGrades() != 4
            || fscSamKatanaBladeInches() != 30
            || fscSamKatanaWeightLb() != 3
            || fscSamWakizashiBladeInches() != 24
            || fscSamWakizashiWeightQuarterLb() != 7
            || fscSamNonSamuraiStepLoss() != 1
            || fscSamModFloor() != 0
            || fscSamSingleHandedStepLoss() != 1
            || fscSamCritBands() != 3
            || fscSamDexBonusLevels() != 5
            || fscSamDexXp1() != 8000
            || fscSamDexXp2() != 64000
            || fscSamDexXp3() != 184000
            || fscSamDexXp4() != 368000
            || fscSamDexXp5() != 616000
            || fscSamArmorMaxWeightLb() != 45
            || fscSamArmorGradeCount() != 5
            || fscSamJudoRecoverMinTurns() != 1
            || fscSamJudoRecoverMaxTurns() != 2
            || fscSamJudoDamageMin() != 1
            || fscSamJudoDamageMax() != 4
            || fscSamJudoDamageRollMin() != 19
            || fscSamJudoDamageLevelsPerStep() != 4
            || fscSamJudoDamagePctPerStep() != 5
            || fscSamJudoSubdueRollMin() != 20
            || fscSamJudoSubdueLevelsPerStep() != 6
            || fscSamJudoSubduePctPerStep() != 5
            || fscYumiCostGold() != 75
            || fscYumiEncumbranceGold() != 50
            || fscYumiArrowsPerBundle() != 20
            || fscYumiArrowBundleCostGold() != 5
            || fscYumiQuiverCostGold() != 5
            || fscYumiQuiverEncumbranceGold() != 75
            || fscBerserkerStrMin() != 10
            || fscBerserkerConMin() != 10
            || fscBerserkerIntMax() != 8
            || fscBerserkerMaxAcLevelOne() != 6
            || fscBerserkerClanCount() != 5
            || fscBerserkerHorseReactionMod() != 2
            || fscBerserkerAcPerTwoLevels() != 1
            || fscBerserkerSurpriseLevel() != 4
            || fscBerserkerSurpriseStep() != 1
            || fscBerserkerDetectLevel() != 6
            || fscBerserkerCompanionLevel() != 4
            || fscBerserkerHireLevel() != 10
            || fscBerserkerHireLoyaltyPenalty() != 2
            || fscBerserkerHireLoyaltyMax() != 15
            || fscBerserkerFollowerMin() != 2
            || fscBerserkerFollowerMax() != 12
            || fscBerserkerFollowerLoyaltyMin() != 16
            || fscBerserkerBardFollowerMinLevel() != 3
            || fscBerserkerBardFollowerMaxLevel() != 6
            || fscBerserkerFollowerTypeBands() != 6
            || fscBerserkerFollowerLevelBands() != 6
            || fscBerserkerExtraordinaryBands() != 8
            || fscBerserkBasePct() != 10
            || fscBerserkShieldBitePct() != 20
            || fscBerserkRoundPct() != 10
            || fscBerserkWitnessDeathPct() != 10
            || fscBerserkAttackBonus() != 2
            || fscBerserkMagicSwordCheckBonus() != 6
            || fscBerserkTurnOnFriendsPct() != 10
            || fscBerserkTurnOnPerLevelPct() != 1
            || fscBerserkTurnOnMinPct() != 1
            || fscBerserkClanmasterTurnOnPct() != 0
            || fscBerserkerRestTurns() != 1
            || fscBerserkerFootnoteWereratPct() != 5
            || fscBerserkerFootnoteWerewolfPct() != 0
            || fscBerserkerFootnoteWereboarPct() != 0
            || fscBerserkerFootnoteWeretigerPct() != 5
            || fscBerserkerFootnoteWerebearPct() != 10
            || !fscSamAnyAlignment()
            || !fscSamPrefersDaisho()
            || !fscSamKatanaLossVendetta()
            || !fscSamBladesNonMagical()
            || !fscSamTwoWeaponsAtOnce()
            || !fscSamSeldomShield()
            || !fscSamJudoUnarmedOnly()
            || !fscSamJudoVsUnarmedPreferred()
            || !fscSamYumiAnyPosture()
            || !fscBerserkerExperimental()
            || !fscBerserkerHumanOnly()
            || !fscBerserkerNeutralOnly()
            || !fscBerserkerNoMagicArmorShield()
            || !fscBerserkerDoubleKillPoints()
            || !fscBerserkerNeverPsionic()
            || !fscBerserkerWereshapeBonuses()
            || !fscBerserkerNoLycanthropePowers()
            || !fscBerserkerWereshapeMeleeMagicOnly()
            || !fscBerserkerInsanityIsWereshape()
            || !fscBerserkerSpeaksLycanthropic()
            || !fscBerserkerShieldbrothersFriendly()
            || !fscBerserkerFollowersNeverReplaced()
            || !fscBerserkCompanionDeathAuto()
            || !fscBerserkerCannotWithdrawBerserk()
            || !fscBerserkerNeverCauseLycanthropy()
        )
            ++bad;
        // the katana grades - the chance of critical hit table for the
        // Japanese long sword, blades approximately 30 inches and 3 pounds
        // (folio 25)
        int CFscKat[4][5] = {
            {0,8,20,50,18},
            {1,7,19,45,240},
            {2,6,19,40,480},
            {3,5,18,40,960},
            };
        for (int b = 0;
             b < fscSamBladeGrades();
             ++b) {
            int vals[5];
            vals[0] = fscKatHitMod(b);
            vals[1] = fscKatToHitAbove(b);
            vals[2] = fscKatCritMinRoll(b);
            vals[3] = fscKatEncumbrance(b);
            vals[4] = fscKatValueGold(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CFscKat[b][c])
                    ++bad;
            }
        }
        // the wakizashi grades - the chance of critical hit table for the
        // Japanese short sword, blades approximately 24 inches and 1 and 3/4
        // pounds (folio 25)
        int CFscWak[4][5] = {
            {0,8,20,28,16},
            {1,8,20,25,200},
            {2,7,19,23,400},
            {3,7,19,23,800},
            };
        for (int b = 0;
             b < fscSamBladeGrades();
             ++b) {
            int vals[5];
            vals[0] = fscWakHitMod(b);
            vals[1] = fscWakToHitAbove(b);
            vals[2] = fscWakCritMinRoll(b);
            vals[3] = fscWakEncumbrance(b);
            vals[4] = fscWakValueGold(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CFscWak[b][c])
                    ++bad;
            }
        }
        // the critical blow table on the percentage dice - 01-80 a quarter of
        // maximum hit points or 6 with a 1-4 limb roll, 81-95 half or 12 with
        // a major body hit, 96-00 decapitation or other instant kill (folio
        // 25)
        int CFscCri[3][5] = {
            {1,80,25,6,1},
            {81,95,50,12,0},
            {96,100,100,0,0},
            };
        for (int b = 0;
             b < fscSamCritBands();
             ++b) {
            int vals[5];
            vals[0] = fscCritLoPct(b);
            vals[1] = fscCritHiPct(b);
            vals[2] = fscCritPctMaxHp(b);
            vals[3] = fscCritMinHp(b);
            vals[4] = fscCritLimbRoll(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CFscCri[b][c])
                    ++bad;
            }
        }
        // the Japanese armor grades E, D, C, B, A - European plate's
        // protection at 45 pounds maximum, protection sacrificed for speed
        // where necessary; B is heavier than A at 675 against 625 (folio 25)
        int CFscArm[5][4] = {
            {1,6,400,40},
            {2,5,400,75},
            {3,4,575,150},
            {4,3,675,300},
            {5,3,625,600},
            };
        for (int b = 0;
             b < fscSamArmorGradeCount();
             ++b) {
            int vals[4];
            vals[0] = fscArmorGradeRank(b);
            vals[1] = fscArmorAc(b);
            vals[2] = fscArmorEncumbranceGold(b);
            vals[3] = fscArmorValueGold(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CFscArm[b][c])
                    ++bad;
            }
        }
        // the five clans - Wererat advances as Cleric, Werewolf and Wereboar
        // as Druid, Weretiger and Werebear as Fighter; each has one
        // Clanmaster, combat for the top spot being detailed under Monks and
        // Druids in the supplements (folio 27)
        int CFscClan[5][6] = {
            {1,1,6,8,9,11},
            {2,2,7,9,10,12},
            {3,2,8,10,10,13},
            {4,3,9,11,11,14},
            {5,3,10,12,12,15},
            };
        for (int b = 0;
             b < fscBerserkerClanCount();
             ++b) {
            int vals[6];
            vals[0] = fscClanIndex(b);
            vals[1] = fscClanAdvanceCode(b);
            vals[2] = fscClanWereshapeLevel(b);
            vals[3] = fscClanFollowerLevel(b);
            vals[4] = fscClanMaxDice(b);
            vals[5] = fscClanmasterLevel(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CFscClan[b][c])
                    ++bad;
            }
        }
        // the Follower type roll - 01-60 Fighter, 61-70 Magic User, 71-80
        // Elf, 81-90 Dwarf, 91-00 Extraordinary; the OCR's duplicate
        // Magic-User row pins AS SCANNED with both rows at 61-70 (folio 27)
        int CFscFty[6][3] = {
            {1,60,1},
            {61,70,2},
            {61,70,2},
            {71,80,3},
            {81,90,4},
            {91,100,5},
            };
        for (int b = 0;
             b < fscBerserkerFollowerTypeBands();
             ++b) {
            int vals[3];
            vals[0] = fscFtyLo(b);
            vals[1] = fscFtyHi(b);
            vals[2] = fscFtyCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFscFty[b][c])
                    ++bad;
            }
        }
        // the Follower level roll - 01-50 2nd, 51-65 3rd, 66-80 4th, 81-90
        // 5th, 91-99 6th, 00 7th pinned as 100 (folio 27)
        int CFscFle[6][3] = {
            {1,50,2},
            {51,65,3},
            {66,80,4},
            {81,90,5},
            {91,99,6},
            {100,100,7},
            };
        for (int b = 0;
             b < fscBerserkerFollowerLevelBands();
             ++b) {
            int vals[3];
            vals[0] = fscFleLo(b);
            vals[1] = fscFleHi(b);
            vals[2] = fscFleLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFscFle[b][c])
                    ++bad;
            }
        }
        // the Extraordinary Follower roll - 01-40 Berserker shieldbrother,
        // 41-65 Lycanthrope weretype, 66-75 Druid level 3-7, 76-85 Bard,
        // 86-90 Ranger, 91-95 Hill Giant, 96-99 Stone Giant, 00 two rolls
        // ignoring 00 pinned as 100 (folio 27)
        int CFscExt[8][3] = {
            {1,40,1},
            {41,65,2},
            {66,75,3},
            {76,85,4},
            {86,90,5},
            {91,95,6},
            {96,99,7},
            {100,100,8},
            };
        for (int b = 0;
             b < fscBerserkerExtraordinaryBands();
             ++b) {
            int vals[3];
            vals[0] = fscExtLo(b);
            vals[1] = fscExtHi(b);
            vals[2] = fscExtCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFscExt[b][c])
                    ++bad;
            }
        }
        // the Samurai frame - any alignment tending neutral, the daisho and
        // yumi preference, dexterity above 15 pinned as 16, the vendetta or
        // seppeku on katana loss (folio 25)
    if (fscSamAnyAlignment() != 1
            || fscSamPrefersDaisho() != 1
            || fscSamDexMin() != 16
            || fscSamKatanaLossVendetta() != 1
        )
            ++bad;
        // the blade lore - special though non-magical, 9+ identifies Japanese
        // manufacture, 13+ tells the exact type, four grades (folio 25)
    if (fscSamBladesNonMagical() != 1
            || fscSamIdBladeIntMin() != 9
            || fscSamIdExactIntMin() != 13
            || fscSamBladeGrades() != 4
        )
            ++bad;
        // the blade physicals - the 30-inch 3-pound katana, the 24-inch 1 and
        // 3/4-pound wakizashi pinned as seven quarter-pounds (folio 25)
    if (fscSamKatanaBladeInches() != 30
            || fscSamKatanaWeightLb() != 3
            || fscSamWakizashiBladeInches() != 24
            || fscSamWakizashiWeightQuarterLb() != 7
        )
            ++bad;
        // the step-loss rules - one step down in non-Samurai hands or
        // single-handed, never below zero, both swords at once permitted
        // (folio 25)
    if (fscSamNonSamuraiStepLoss() != 1
            || fscSamModFloor() != 0
            || fscSamSingleHandedStepLoss() != 1
            || fscSamTwoWeaponsAtOnce() != 1
        )
            ++bad;
        // the dexterity ladder - one point each at 8,000, 64,000, 184,000,
        // 368,000 and 616,000 (folio 25)
    if (fscSamDexXp1() != 8000
            || fscSamDexXp2() != 64000
            || fscSamDexXp3() != 184000
            || fscSamDexXp4() != 368000
            || fscSamDexXp5() != 616000
            || fscSamDexBonusLevels() != 5
        )
            ++bad;
        // the Japanese armor - plate's protection at 45 pounds maximum, five
        // cost-related grades, the shield very seldom (folio 25)
    if (fscSamArmorMaxWeightLb() != 45
            || fscSamArmorGradeCount() != 5
            || fscSamSeldomShield() != 1
        )
            ++bad;
        // the judo frame - only with empty hands, generally versus the
        // unarmed, a throw costing 1 or 2 melee turns to recover (folio 25)
    if (fscSamJudoUnarmedOnly() != 1
            || fscSamJudoVsUnarmedPreferred() != 1
            || fscSamJudoRecoverMinTurns() != 1
            || fscSamJudoRecoverMaxTurns() != 2
        )
            ++bad;
        // the judo damage - 1-4 on a 19 or 20, +5 percent per 4 levels, the
        // 4th-level 18-20 and 8th-level 17-20 example (folio 25)
    if (fscSamJudoDamageMin() != 1
            || fscSamJudoDamageMax() != 4
            || fscSamJudoDamageRollMin() != 19
            || fscSamJudoDamageLevelsPerStep() != 4
            || fscSamJudoDamagePctPerStep() != 5
        )
            ++bad;
        // the judo subdue - on a 20 the Samurai may elect to subdue, +5
        // percent per 6 levels (folio 25)
    if (fscSamJudoSubdueRollMin() != 20
            || fscSamJudoSubdueLevelsPerStep() != 6
            || fscSamJudoSubduePctPerStep() != 5
        )
            ++bad;
        // the yumi - fired standing, kneeling or on horseback, 75 gp at 50
        // encumbrance, 20 arrows for 5 gp, the 5 gp quiver at 75 encumbrance
        // (folio 25)
    if (fscSamYumiAnyPosture() != 1
            || fscYumiCostGold() != 75
            || fscYumiEncumbranceGold() != 50
            || fscYumiArrowsPerBundle() != 20
            || fscYumiArrowBundleCostGold() != 5
            || fscYumiQuiverCostGold() != 5
            || fscYumiQuiverEncumbranceGold() != 75
        )
            ++bad;
        // the Berserker prerequisites - highly experimental, human and
        // NEUTRAL, Strength and Constitution exceeding 9 pinned as 10,
        // Intelligence below 9 pinned as 8, armor class no better than 6 at
        // level 1 (folio 27)
    if (fscBerserkerExperimental() != 1
            || fscBerserkerHumanOnly() != 1
            || fscBerserkerNeutralOnly() != 1
            || fscBerserkerStrMin() != 10
            || fscBerserkerConMin() != 10
            || fscBerserkerIntMax() != 8
            || fscBerserkerMaxAcLevelOne() != 6
        )
            ++bad;
        // the Berserker frame - no magical armor or shields, double kill
        // points until the wereshape, never psionic, +1 armor class per two
        // levels (folio 27)
    if (fscBerserkerNoMagicArmorShield() != 1
            || fscBerserkerDoubleKillPoints() != 1
            || fscBerserkerNeverPsionic() != 1
            || fscBerserkerAcPerTwoLevels() != 1
        )
            ++bad;
        // the wereshape - five clans, all hit and damage bonuses in
        // wereshape, none of the lycanthrope characteristics, melee against
        // magic-only creatures, insanity always a reversion (folio 27)
    if (fscBerserkerClanCount() != 5
            || fscBerserkerWereshapeBonuses() != 1
            || fscBerserkerNoLycanthropePowers() != 1
            || fscBerserkerWereshapeMeleeMagicOnly() != 1
            || fscBerserkerInsanityIsWereshape() != 1
        )
            ++bad;
        // the clan ties - the lycanthropic tongue and empathic command in
        // human form, horses at -2, shieldbrothers always friendly under pain
        // of outlawry (folio 27)
    if (fscBerserkerSpeaksLycanthropic() != 1
            || fscBerserkerHorseReactionMod() != 2
            || fscBerserkerShieldbrothersFriendly() != 1
        )
            ++bad;
        // the level abilities - surprise reduced by 1 at 4th, hidden and
        // invisible enemies detected and the 4th level Companion at 6th
        // (folio 27)
    if (fscBerserkerSurpriseLevel() != 4
            || fscBerserkerSurpriseStep() != 1
            || fscBerserkerDetectLevel() != 6
            || fscBerserkerCompanionLevel() != 4
        )
            ++bad;
        // the level-10 hiring - hirelings at -2 loyalty, never above 15
        // (folio 27)
    if (fscBerserkerHireLevel() != 10
            || fscBerserkerHireLoyaltyPenalty() != 2
            || fscBerserkerHireLoyaltyMax() != 15
        )
            ++bad;
        // the Followers - 2-12 at loyalty 16-plus, one Bard of level 3-6,
        // never replaced; the three percentile rolls in six, six and eight
        // rows (folio 27)
    if (fscBerserkerFollowerMin() != 2
            || fscBerserkerFollowerMax() != 12
            || fscBerserkerFollowerLoyaltyMin() != 16
            || fscBerserkerBardFollowerMinLevel() != 3
            || fscBerserkerBardFollowerMaxLevel() != 6
            || fscBerserkerFollowersNeverReplaced() != 1
            || fscBerserkerFollowerTypeBands() != 6
            || fscBerserkerFollowerLevelBands() != 6
            || fscBerserkerExtraordinaryBands() != 8
        )
            ++bad;
        // the berserking chance - a 10 percent base once per melee, +20 for
        // the bitten shield, +10 per round cumulative, +10 per witnessed
        // death, the Companion's death automatic (folio 27)
    if (fscBerserkBasePct() != 10
            || fscBerserkShieldBitePct() != 20
            || fscBerserkRoundPct() != 10
            || fscBerserkWitnessDeathPct() != 10
            || fscBerserkCompanionDeathAuto() != 1
        )
            ++bad;
        // the berserk edges and the lock - attacks at +2 over strength
        // bonuses, +6 to level or key check with a magic sword, no withdrawal
        // from melee (folio 27)
    if (fscBerserkAttackBonus() != 2
            || fscBerserkMagicSwordCheckBonus() != 6
            || fscBerserkerCannotWithdrawBerserk() != 1
        )
            ++bad;
        // the fit's end - 10 percent chance of turning on friends less 1
        // percent per level to a 1 percent minimum, 0 for a Clanmaster, a
        // full turn of rest after, and never causing lycanthropy (folio 27)
    if (fscBerserkTurnOnFriendsPct() != 10
            || fscBerserkTurnOnPerLevelPct() != 1
            || fscBerserkTurnOnMinPct() != 1
            || fscBerserkClanmasterTurnOnPct() != 0
            || fscBerserkerRestTurns() != 1
            || fscBerserkerNeverCauseLycanthropy() != 1
        )
            ++bad;
        // the footnote adjustments by clan - Wererat 5, Werewolf and Wereboar
        // 0, Weretiger +5, Werebear +10 percent (folio 27)
    if (fscBerserkerFootnoteWereratPct() != 5
            || fscBerserkerFootnoteWerewolfPct() != 0
            || fscBerserkerFootnoteWereboarPct() != 0
            || fscBerserkerFootnoteWeretigerPct() != 5
            || fscBerserkerFootnoteWerebearPct() != 10
        )
            ++bad;
        // the plain katana - 8+, automatic on 20, encumbrance 50, 18 gp
        // (folio 25)
    if (fscKatHitMod(0) != 0
            || fscKatToHitAbove(0) != 8
            || fscKatCritMinRoll(0) != 20
            || fscKatEncumbrance(0) != 50
            || fscKatValueGold(0) != 18
        )
            ++bad;
        // the +1 katana - 7+, automatic on 19-20, encumbrance 45, 240 gp
        // (folio 25)
    if (fscKatHitMod(1) != 1
            || fscKatToHitAbove(1) != 7
            || fscKatCritMinRoll(1) != 19
            || fscKatEncumbrance(1) != 45
            || fscKatValueGold(1) != 240
        )
            ++bad;
        // the +2 katana - 6+, automatic on 19-20, encumbrance 40, 480 gp
        // (folio 25)
    if (fscKatHitMod(2) != 2
            || fscKatToHitAbove(2) != 6
            || fscKatCritMinRoll(2) != 19
            || fscKatEncumbrance(2) != 40
            || fscKatValueGold(2) != 480
        )
            ++bad;
        // the +3 katana - 5+, automatic on 18-20, encumbrance 40, 960 gp
        // (folio 25)
    if (fscKatHitMod(3) != 3
            || fscKatToHitAbove(3) != 5
            || fscKatCritMinRoll(3) != 18
            || fscKatEncumbrance(3) != 40
            || fscKatValueGold(3) != 960
        )
            ++bad;
        // the plain wakizashi - 8+, automatic on 20, encumbrance 28, 16 gp
        // (folio 25)
    if (fscWakHitMod(0) != 0
            || fscWakToHitAbove(0) != 8
            || fscWakCritMinRoll(0) != 20
            || fscWakEncumbrance(0) != 28
            || fscWakValueGold(0) != 16
        )
            ++bad;
        // the +1 wakizashi - 8+, automatic on 20, encumbrance 25, 200 gp
        // (folio 25)
    if (fscWakHitMod(1) != 1
            || fscWakToHitAbove(1) != 8
            || fscWakCritMinRoll(1) != 20
            || fscWakEncumbrance(1) != 25
            || fscWakValueGold(1) != 200
        )
            ++bad;
        // the +2 wakizashi - 7+, automatic on 19-20, encumbrance 23, 400 gp
        // (folio 25)
    if (fscWakHitMod(2) != 2
            || fscWakToHitAbove(2) != 7
            || fscWakCritMinRoll(2) != 19
            || fscWakEncumbrance(2) != 23
            || fscWakValueGold(2) != 400
        )
            ++bad;
        // the +3 wakizashi - 7+, automatic on 19-20, encumbrance 23, 800 gp
        // (folio 25)
    if (fscWakHitMod(3) != 3
            || fscWakToHitAbove(3) != 7
            || fscWakCritMinRoll(3) != 19
            || fscWakEncumbrance(3) != 23
            || fscWakValueGold(3) != 800
        )
            ++bad;
        // the 01-80 critical band - 25 percent of maximum hit points or 6,
        // whichever greater, plus the 1-4 limb roll (folio 25); the three
        // percentile bands (folio 25)
    if (fscCritLoPct(0) != 1
            || fscCritHiPct(0) != 80
            || fscCritPctMaxHp(0) != 25
            || fscCritMinHp(0) != 6
            || fscCritLimbRoll(0) != 1
            || fscSamCritBands() != 3
        )
            ++bad;
        // the 81-95 critical band - 50 percent of maximum hit points or 12,
        // whichever greater, a major body hit (folio 25)
    if (fscCritLoPct(1) != 81
            || fscCritHiPct(1) != 95
            || fscCritPctMaxHp(1) != 50
            || fscCritMinHp(1) != 12
            || fscCritLimbRoll(1) != 0
        )
            ++bad;
        // the 96-00 critical band - 100 percent of maximum hit points,
        // decapitation or other instant kill (folio 25)
    if (fscCritLoPct(2) != 96
            || fscCritHiPct(2) != 100
            || fscCritPctMaxHp(2) != 100
            || fscCritMinHp(2) != 0
            || fscCritLimbRoll(2) != 0
        )
            ++bad;
        // the E grade armor - armor class 6, encumbrance 400, 40 gp (folio
        // 25)
    if (fscArmorGradeRank(0) != 1
            || fscArmorAc(0) != 6
            || fscArmorEncumbranceGold(0) != 400
            || fscArmorValueGold(0) != 40
        )
            ++bad;
        // the D grade armor - armor class 5, encumbrance 400, 75 gp (folio
        // 25)
    if (fscArmorGradeRank(1) != 2
            || fscArmorAc(1) != 5
            || fscArmorEncumbranceGold(1) != 400
            || fscArmorValueGold(1) != 75
        )
            ++bad;
        // the C grade armor - armor class 4, encumbrance 575, 150 gp (folio
        // 25)
    if (fscArmorGradeRank(2) != 3
            || fscArmorAc(2) != 4
            || fscArmorEncumbranceGold(2) != 575
            || fscArmorValueGold(2) != 150
        )
            ++bad;
        // the B grade armor - armor class 3, encumbrance 675, 300 gp (folio
        // 25)
    if (fscArmorGradeRank(3) != 4
            || fscArmorAc(3) != 3
            || fscArmorEncumbranceGold(3) != 675
            || fscArmorValueGold(3) != 300
        )
            ++bad;
        // the A grade armor - armor class 3, encumbrance 625, 600 gp (folio
        // 25)
    if (fscArmorGradeRank(4) != 5
            || fscArmorAc(4) != 3
            || fscArmorEncumbranceGold(4) != 625
            || fscArmorValueGold(4) != 600
        )
            ++bad;
        // the Wererat clan - advances as Cleric, wereshape at 6th, Followers
        // at 8th, 9 hit dice max, Clanmaster 11th (folio 27)
    if (fscClanIndex(0) != 1
            || fscClanAdvanceCode(0) != 1
            || fscClanWereshapeLevel(0) != 6
            || fscClanFollowerLevel(0) != 8
            || fscClanMaxDice(0) != 9
            || fscClanmasterLevel(0) != 11
        )
            ++bad;
        // the Werewolf clan - advances as Druid, wereshape at 7th, Followers
        // at 9th, 10 hit dice max, Clanmaster 12th (folio 27)
    if (fscClanIndex(1) != 2
            || fscClanAdvanceCode(1) != 2
            || fscClanWereshapeLevel(1) != 7
            || fscClanFollowerLevel(1) != 9
            || fscClanMaxDice(1) != 10
            || fscClanmasterLevel(1) != 12
        )
            ++bad;
        // the Wereboar clan - advances as Druid, wereshape at 8th, Followers
        // at 10th, 10 hit dice max, Clanmaster 13th (folio 27)
    if (fscClanIndex(2) != 3
            || fscClanAdvanceCode(2) != 2
            || fscClanWereshapeLevel(2) != 8
            || fscClanFollowerLevel(2) != 10
            || fscClanMaxDice(2) != 10
            || fscClanmasterLevel(2) != 13
        )
            ++bad;
        // the Weretiger clan - advances as Fighter, wereshape at 9th,
        // Followers at 11th, 11 hit dice max, Clanmaster 14th (folio 27)
    if (fscClanIndex(3) != 4
            || fscClanAdvanceCode(3) != 3
            || fscClanWereshapeLevel(3) != 9
            || fscClanFollowerLevel(3) != 11
            || fscClanMaxDice(3) != 11
            || fscClanmasterLevel(3) != 14
        )
            ++bad;
        // the Werebear clan - advances as Fighter, wereshape at 10th,
        // Followers at 12th, 12 hit dice max, Clanmaster 15th (folio 27)
    if (fscClanIndex(4) != 5
            || fscClanAdvanceCode(4) != 3
            || fscClanWereshapeLevel(4) != 10
            || fscClanFollowerLevel(4) != 12
            || fscClanMaxDice(4) != 12
            || fscClanmasterLevel(4) != 15
        )
            ++bad;
        // the 01-60 Fighter row (folio 27)
    if (fscFtyLo(0) != 1
            || fscFtyHi(0) != 60
            || fscFtyCode(0) != 1
        )
            ++bad;
        // the 61-70 Magic User row (folio 27)
    if (fscFtyLo(1) != 61
            || fscFtyHi(1) != 70
            || fscFtyCode(1) != 2
        )
            ++bad;
        // the OCR duplicate 61-70 Magic User row - pinned as scanned (folio
        // 27)
    if (fscFtyLo(2) != 61
            || fscFtyHi(2) != 70
            || fscFtyCode(2) != 2
        )
            ++bad;
        // the 71-80 Elf row (folio 27)
    if (fscFtyLo(3) != 71
            || fscFtyHi(3) != 80
            || fscFtyCode(3) != 3
        )
            ++bad;
        // the 81-90 Dwarf row (folio 27)
    if (fscFtyLo(4) != 81
            || fscFtyHi(4) != 90
            || fscFtyCode(4) != 4
        )
            ++bad;
        // the 91-00 Extraordinary row, the '00' pinned as 100 (folio 27)
    if (fscFtyLo(5) != 91
            || fscFtyHi(5) != 100
            || fscFtyCode(5) != 5
        )
            ++bad;
        // the 01-50 band - a 2nd level Follower (folio 27)
    if (fscFleLo(0) != 1
            || fscFleHi(0) != 50
            || fscFleLevel(0) != 2
        )
            ++bad;
        // the 51-65 band - a 3rd level Follower (folio 27)
    if (fscFleLo(1) != 51
            || fscFleHi(1) != 65
            || fscFleLevel(1) != 3
        )
            ++bad;
        // the 66-80 band - a 4th level Follower (folio 27)
    if (fscFleLo(2) != 66
            || fscFleHi(2) != 80
            || fscFleLevel(2) != 4
        )
            ++bad;
        // the 81-90 band - a 5th level Follower (folio 27)
    if (fscFleLo(3) != 81
            || fscFleHi(3) != 90
            || fscFleLevel(3) != 5
        )
            ++bad;
        // the 91-99 band - a 6th level Follower (folio 27)
    if (fscFleLo(4) != 91
            || fscFleHi(4) != 99
            || fscFleLevel(4) != 6
        )
            ++bad;
        // the 00 band pinned as 100 - a 7th level Follower (folio 27)
    if (fscFleLo(5) != 100
            || fscFleHi(5) != 100
            || fscFleLevel(5) != 7
        )
            ++bad;
        // the 01-40 Berserker shieldbrother row (folio 27)
    if (fscExtLo(0) != 1
            || fscExtHi(0) != 40
            || fscExtCode(0) != 1
        )
            ++bad;
        // the 41-65 Lycanthrope weretype row (folio 27)
    if (fscExtLo(1) != 41
            || fscExtHi(1) != 65
            || fscExtCode(1) != 2
        )
            ++bad;
        // the 66-75 Druid level 3-7 row (folio 27)
    if (fscExtLo(2) != 66
            || fscExtHi(2) != 75
            || fscExtCode(2) != 3
        )
            ++bad;
        // the 76-85 Bard row (folio 27)
    if (fscExtLo(3) != 76
            || fscExtHi(3) != 85
            || fscExtCode(3) != 4
        )
            ++bad;
        // the 86-90 Ranger row (folio 27)
    if (fscExtLo(4) != 86
            || fscExtHi(4) != 90
            || fscExtCode(4) != 5
        )
            ++bad;
        // the 91-95 Hill Giant row (folio 27)
    if (fscExtLo(5) != 91
            || fscExtHi(5) != 95
            || fscExtCode(5) != 6
        )
            ++bad;
        // the 96-99 Stone Giant row (folio 27)
    if (fscExtLo(6) != 96
            || fscExtHi(6) != 99
            || fscExtCode(6) != 7
        )
            ++bad;
        // the 00 row pinned as 100 - two rolls, ignoring 00 (folio 27)
    if (fscExtLo(7) != 100
            || fscExtHi(7) != 100
            || fscExtCode(7) != 8
        )
            ++bad;
        printf("R897 fighting sub-classes audit: bad %d\n", bad);
        if (bad) return 1;
    }
