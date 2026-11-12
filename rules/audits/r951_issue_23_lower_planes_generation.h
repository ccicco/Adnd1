    // ---- R951 issue-23 Lower Planes generation audit ----
    // THE SORCEROR SCROLL LOWER-PLANES GENERATOR AUDIT - the issue-23
    // part-two table round, the Random Generation of Creatures from the Lower
    // Planes system headed into the forth coming DUNGEON MASTERS GUIDE. The
    // base stat block, the twenty-three appearance and generation grids, the
    // strength-to-hit-damage bands, the attack forms, the special attacks and
    // defenses and the optional-poison footnote all ride this single chain,
    // print 15 through 18.
    {
        using namespace rules;
        int bad = 0;
    if (s23LowerPlanes() != 5
            || s23RihnIssue() != 20
            || s23PickensIssue() != 13
            || s23FreqBands() != 3
            || s23AppearMin() != 1
            || s23AppearMax() != 8
            || s23AcDice() != 4
            || s23AcWorst() != 0
            || s23AcBest() != -3
            || s23MoveDie() != 8
            || s23MoveRerollFrom() != 6
            || s23MoveRerollDie() != 4
            || s23MoveIncrement() != 3
            || s23MoveBonusMax() != 4
            || s23SwimLo() != 1
            || s23SwimHi() != 2
            || s23FlyLo() != 3
            || s23FlyHi() != 6
            || s23HdBase() != 6
            || s23HdDice() != 4
            || s23HdMin() != 7
            || s23HdMax() != 10
            || s23HdBonusOn() != 4
            || s23HdBonusMin() != 1
            || s23HdBonusMax() != 4
            || s23MrPerDie() != 5
            || s23IntBands() != 4
            || s23SizeDice() != 8
            || s23SizeSmallHi() != 1
            || s23SizeMedHi() != 4
            || s23PsiNil() != 90
            || s23PsiBase() != 95
            || s23PsiDie() != 20
            || s23PsiMin() != 96
            || s23PsiMax() != 115
            || s23AtkModeCount() != 4
            || s23AtkModeDie() != 4
            || s23DefModeCount() != 3
            || s23DefModeDie() != 6
            || s23DefBandWidth() != 2
            || s23HornsMax() != 4
            || s23EyesMid() != 2
            || s23EyesHighMin() != 3
            || s23EyesHighMax() != 4
            || s23MouthAvgLo() != 2
            || s23MouthAvgHi() != 3
            || s23MouthHugeLo() != 5
            || s23MouthHugeHi() != 6
            || s23BipedLo() != 1
            || s23BipedHi() != 4
            || s23QuadLo() != 5
            || s23QuadHi() != 6
            || s23ArmsMin() != 2
            || s23BipedArmsMax() != 4
            || s23OtherArmsMax() != 6
            || s23HandsAlikeHi() != 3
            || s23HandsDiffLo() != 4
            || s23TailLo() != 1
            || s23TailHi() != 4
            || s23AntlerDiceMin() != 1
            || s23AntlerSidesMin() != 2
            || s23AntlerDiceMax() != 2
            || s23AntlerSidesMax() != 8
            || s23MouthDmgMin() != 1
            || s23MouthDmgMaxDice() != 3
            || s23MouthDmgMaxSides() != 12
            || s23TailDmgMin() != 1
            || s23TailDmgMax() != 6
            || s23HandDiceMin() != 1
            || s23HandSidesMin() != 2
            || s23HandDiceMax() != 2
            || s23HandSidesMax() != 12
            || s23FootDiceMin() != 1
            || s23FootSidesMin() != 2
            || s23FootDiceMax() != 3
            || s23FootSidesMax() != 12
            || s23HugeClawDice() != 2
            || s23HugeClawSides() != 8
            || s23SpineDmgMin() != 1
            || s23SpineDmgMax() != 6
            || s23StrSubFifty() != 50
            || s23StrSubSeventyFive() != 75
            || s23StrSubNinety() != 90
            || s23StrSubNinetyNine() != 99
            || s23SpecAtkMin() != 1
            || s23SpecAtkMax() != 3
            || s23SpecAtkOptions() != 8
            || s23LesserSpellMin() != 1
            || s23LesserSpellMax() != 2
            || s23PowerSpellMin() != 2
            || s23PowerSpellMax() != 5
            || s23SpecDefMin() != 1
            || s23SpecDefMax() != 4
            || s23SpecDefOptions() != 10
            || s23RegenBase() != 1
            || s23SpellImmuMin() != 1
            || s23SpellImmuMax() != 4
            || s23MetalKinds() != 3
            || s23WeaponImmuMinPlus() != 1
            || s23PoisonChance() != 4
            || s23InsanityRoundsMax() != 4
            || s23WeaknessPoints() != 1
            || s23OtherAbilities() != 3
            || s23HeadCount() != 8
            || s23AdornCount() != 8
            || s23VisageCount() != 6
            || s23EarsCount() != 6
            || s23EyeFormCount() != 6
            || s23NoseCount() != 6
            || s23MouthCount() != 6
            || s23BipedCount() != 6
            || s23QuadCount() != 7
            || s23CharCount() != 8
            || s23BackCount() != 4
            || s23SkinCount() != 10
            || s23WingsCount() != 4
            || s23ColorCount() != 10
            || s23TailTypeCount() != 8
            || s23OdorCount() != 8
            || s23HandTypeCount() != 6
            || s23FeetCount() != 8
            || s23BirdFootCount() != 6
            || s23MoveCount() != 5
            || s23MrVarCount() != 6
            || s23PoisonCount() != 6
            || s23StrCount() != 9
            || !s23OfficialApproach()
            || !s23DmgPreview()
            || !s23RihnPickensThanks()
            || !s23FormatMonsterManual()
            || !s23CircumstancesDictate()
            || !s23EyesPlusCatch()
            || !s23MouthFourCatch()
            || !s23SpecialEffectsMinimum()
            || !s23StrOverlapCatch()
            || !s23ImmunityOverFourConditional()
            || !s23MetalExcludesMagic()
            || !s23WeaponImmunityMagicalOnly()
            || !s23SpellImmunityPredetermined()
            || !s23AudialNegatesSurprise()
            || !s23VisualInfravisual()
            || !s23ExxeduunusseSignoff()
            || !s23ForthComingCatch()
            || !s23QuadrapedalEtalCatch()
            || !s23DfForCfCatch()
            || !s23PredominateCatch()
            || !s23BirdAsteriskCatch()
            || !s23DefEtcCatch()
            || s23TarterusCanon()
        )
            ++bad;
        // the head table - bat-like, bird-like, crocodilian, horse-like,
        // human-like, monkey-like, snake-like, weasel-like the Sorceror
        // Scroll lower-planes generator (print 15-18)
        int CHd[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23HeadCount();
             ++b) {
            int vals[1];
            vals[0] = s23HeadOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CHd[b][c])
                    ++bad;
            }
        }
        // the head adornment table - antlers, crest or peak, horns, knobs,
        // ridges, ruff, spines, none the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CHa[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23AdornCount();
             ++b) {
            int vals[1];
            vals[0] = s23AdornOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CHa[b][c])
                    ++bad;
            }
        }
        // the overall visage table - gibbering-drooling, glaring-menacing,
        // rotting, skeletal, twitching-moving, wrinkled-seamed the Sorceror
        // Scroll lower-planes generator (print 15-18)
        int CVi[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23VisageCount();
             ++b) {
            int vals[1];
            vals[0] = s23VisageOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CVi[b][c])
                    ++bad;
            }
        }
        // the ears table - dog-like, elephant-like, human tiny, human huge,
        // trumpet-like, none the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int CEa[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23EarsCount();
             ++b) {
            int vals[1];
            vals[0] = s23EarsOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CEa[b][c])
                    ++bad;
            }
        }
        // the eye form and color grid - small multi-faceted amber through
        // huge protruding orange-red the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CEf[6][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,4},
            {5,5},
            {6,6},
            };
        for (int b = 0;
             b < s23EyeFormCount();
             ++b) {
            int vals[2];
            vals[0] = s23EyeFormOpt(b);
            vals[1] = s23EyeColorOpt(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CEf[b][c])
                    ++bad;
            }
        }
        // the nose table - flat misshapen, huge bulbous, slits only, snouted,
        // tiny, trunk-like, if necessary the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CNo[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23NoseCount();
             ++b) {
            int vals[1];
            vals[0] = s23NoseOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CNo[b][c])
                    ++bad;
            }
        }
        // the mouth table - fanged, mandibled, sucker-like, toothed small or
        // ridged, toothed large, tusked the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CMo[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23MouthCount();
             ++b) {
            int vals[1];
            vals[0] = s23MouthOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CMo[b][c])
                    ++bad;
            }
        }
        // the bipedal torso table - ape-like, bear-like, bird-like,
        // human-like, pig-like, rat-like the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CBt[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23BipedCount();
             ++b) {
            int vals[1];
            vals[0] = s23BipedOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CBt[b][c])
                    ++bad;
            }
        }
        // the quadrapedal or other torso table - amoeba-like, bison-like,
        // crab-like, horse-like, insect-like, serpent-like or reptilian,
        // spider-like the Sorceror Scroll lower-planes generator (print
        // 15-18)
        int CQt[7][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            };
        for (int b = 0;
             b < s23QuadCount();
             ++b) {
            int vals[1];
            vals[0] = s23QuadOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CQt[b][c])
                    ++bad;
            }
        }
        // the general characteristics table - fat, long, short, thin, broad,
        // muscled, narrow, rubbery the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int CGc[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23CharCount();
             ++b) {
            int vals[1];
            vals[0] = s23CharOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CGc[b][c])
                    ++bad;
            }
        }
        // the back table - humped-hunched, maned, normal,
        // spiked-spined-ridged the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int CBk[4][1] = {
            {1},
            {2},
            {3},
            {4},
            };
        for (int b = 0;
             b < s23BackCount();
             ++b) {
            int vals[1];
            vals[0] = s23BackOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CBk[b][c])
                    ++bad;
            }
        }
        // the skin table - bald-smooth, furred, hairy-bristled,
        // leathery-leprous, scaled, slimed, warted-bumpy, wrinkled-folded,
        // feathered, translucent the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int CSk[10][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            {9},
            {10},
            };
        for (int b = 0;
             b < s23SkinCount();
             ++b) {
            int vals[1];
            vals[0] = s23SkinOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CSk[b][c])
                    ++bad;
            }
        }
        // the wings-if-any table - bat-like, bird-like, insect-like,
        // membranous or fan-like the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int CWg[4][1] = {
            {1},
            {2},
            {3},
            {4},
            };
        for (int b = 0;
             b < s23WingsCount();
             ++b) {
            int vals[1];
            vals[0] = s23WingOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CWg[b][c])
                    ++bad;
            }
        }
        // the predominate color table - blackish, bluish, brownish,
        // grayish-whitish, greenish, orangy, pinkish, purplish, reddish,
        // yellowish-tannish the Sorceror Scroll lower-planes generator (print
        // 15-18)
        int CCl[10][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            {9},
            {10},
            };
        for (int b = 0;
             b < s23ColorCount();
             ++b) {
            int vals[1];
            vals[0] = s23ColorOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CCl[b][c])
                    ++bad;
            }
        }
        // the tail type table - barbed, dog-like, goat-like, horse-like,
        // lion-like, pig-like, prehensile, stingered the Sorceror Scroll
        // lower-planes generator (print 15-18)
        int CTl[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23TailTypeCount();
             ++b) {
            int vals[1];
            vals[0] = s23TailTypeOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CTl[b][c])
                    ++bad;
            }
        }
        // the body odor table - bloody, fishy, fecal, gangrenous, moldy,
        // sweaty, urine, vomit the Sorceror Scroll lower-planes generator
        // (print 15-18)
        int COd[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23OdorCount();
             ++b) {
            int vals[1];
            vals[0] = s23OdorOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != COd[b][c])
                    ++bad;
            }
        }
        // the hands table - clawed, human nailed, pincered, taloned, tentacle
        // fingered, withered and boney the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CHn[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23HandTypeCount();
             ++b) {
            int vals[1];
            vals[0] = s23HandTypeOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CHn[b][c])
                    ++bad;
            }
        }
        // the legs and feet table - clawed, hooved, human-like, insect-like,
        // snake-like, suctioned, taloned, webbed the Sorceror Scroll
        // lower-planes generator (print 15-18)
        int CFt[8][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            };
        for (int b = 0;
             b < s23FeetCount();
             ++b) {
            int vals[1];
            vals[0] = s23FeetOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CFt[b][c])
                    ++bad;
            }
        }
        // the bird-like feet table - duck-like, hawk-like, owl-like,
        // pelican-like, stork-like, turkey-like the Sorceror Scroll
        // lower-planes generator (print 15-18)
        int CBf[6][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            };
        for (int b = 0;
             b < s23BirdFootCount();
             ++b) {
            int vals[1];
            vals[0] = s23BirdFootOpt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CBf[b][c])
                    ++bad;
            }
        }
        // the base move table - six, nine, twelve, fifteen or eighteen inches
        // the Sorceror Scroll lower-planes generator (print 15-18)
        int CMv[5][1] = {
            {6},
            {9},
            {12},
            {15},
            {18},
            };
        for (int b = 0;
             b < s23MoveCount();
             ++b) {
            int vals[1];
            vals[0] = s23MoveInch(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CMv[b][c])
                    ++bad;
            }
        }
        // the magic resistance variance table - minus five, minus ten, plus
        // five, plus ten, plus fifteen, standard the Sorceror Scroll
        // lower-planes generator (print 15-18)
        int CMr[6][1] = {
            {-5},
            {-10},
            {5},
            {10},
            {15},
            {0},
            };
        for (int b = 0;
             b < s23MrVarCount();
             ++b) {
            int vals[1];
            vals[0] = s23MrMod(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CMr[b][c])
                    ++bad;
            }
        }
        // the optional-poison save table - plus one, normal, minus one, minus
        // two, insanity for one to four rounds, weakness one point per hit
        // permanently lost the Sorceror Scroll lower-planes generator (print
        // 15-18)
        int CPs[6][2] = {
            {1,1},
            {2,0},
            {3,-1},
            {4,-2},
            {5,-99},
            {6,-99},
            };
        for (int b = 0;
             b < s23PoisonCount();
             ++b) {
            int vals[2];
            vals[0] = s23PoisonOpt(b);
            vals[1] = s23PoisonMod(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPs[b][c])
                    ++bad;
            }
        }
        // the strength-to-hit-damage table - the nine percentile bands from
        // one through twenty-five to ninety-nine and double zero, the overlap
        // at forty-five printed as scanned the Sorceror Scroll lower-planes
        // generator (print 15-18)
        int CSt[9][5] = {
            {1,25,17,1,1},
            {26,45,18,1,2},
            {45,60,18,1,3},
            {61,70,18,2,3},
            {71,80,18,2,4},
            {81,90,18,2,5},
            {91,95,18,3,6},
            {96,98,19,3,7},
            {99,100,20,3,8},
            };
        for (int b = 0;
             b < s23StrCount();
             ++b) {
            int vals[5];
            vals[0] = s23StrLo(b);
            vals[1] = s23StrHi(b);
            vals[2] = s23StrVal(b);
            vals[3] = s23StrHit(b);
            vals[4] = s23StrDmg(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CSt[b][c])
                    ++bad;
            }
        }
        // the frame - the five lower planes, the Rihn and Pickens
        // antecedents, the official approach riding into the forth coming DMG
        // the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23LowerPlanes() != 5
            || s23RihnIssue() != 20
            || s23PickensIssue() != 13
            || s23OfficialApproach() != 1
            || s23DmgPreview() != 1
        )
            ++bad;
        // the base block - the frequency bands, the number appearing ceiling,
        // the armor class d4 from zero to minus three the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23FreqBands() != 3
            || s23AppearMax() != 8
            || s23AcDice() != 4
            || s23AcBest() != -3
            || s23AcWorst() != 0
        )
            ++bad;
        // the hit dice and magic resistance - d4 plus six for seven to ten
        // dice, the four-face bonus hit points, five percent per die the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23HdBase() != 6
            || s23HdMax() != 10
            || s23HdBonusOn() != 4
            || s23HdBonusMax() != 4
            || s23MrPerDie() != 5
        )
            ++bad;
        // the psionic block - ninety percent nil, else d20 plus ninety-five
        // for ninety-six to one hundred fifteen the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23PsiNil() != 90
            || s23PsiBase() != 95
            || s23PsiDie() != 20
            || s23PsiMin() != 96
            || s23PsiMax() != 115
        )
            ++bad;
        // the psionic modes - A through D on the d4, F through H on the d6 in
        // two-face bands ending at the bare etc. the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23AtkModeCount() != 4
            || s23DefModeCount() != 3
            || s23DefModeDie() != 6
            || s23DefBandWidth() != 2
            || s23DefEtcCatch() != 1
        )
            ++bad;
        // the eyes - the two-to-four and five-to-six bands, the one-plus-one
        // formula catch, the six-row form and color grid the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23EyesMid() != 2
            || s23EyesHighMin() != 3
            || s23EyesHighMax() != 4
            || s23EyesPlusCatch() != 1
            || s23EyeFormCount() != 6
        )
            ++bad;
        // the mouth - the average and huge bands with the skipped four, the
        // six mouth types the Sorceror Scroll lower-planes generator (print
        // 15-18)
    if (s23MouthAvgHi() != 3
            || s23MouthHugeLo() != 5
            || s23MouthFourCatch() != 1
            || s23MouthCount() != 6
        )
            ++bad;
        // the body attributes - the bipedal and quadrapedal etal bands, the
        // seven quadrapedal torso options the Sorceror Scroll lower-planes
        // generator (print 15-18)
    if (s23BipedHi() != 4
            || s23QuadLo() != 5
            || s23QuadCount() != 7
            || s23QuadrapedalEtalCatch() != 1
        )
            ++bad;
        // the coverings - the ten skin options, the ten predominate colors,
        // the eight general characteristics the Sorceror Scroll lower-planes
        // generator (print 15-18)
    if (s23SkinCount() != 10
            || s23ColorCount() != 10
            || s23PredominateCatch() != 1
            || s23CharCount() != 8
        )
            ++bad;
        // the tail and poison - the one-to-four tail band, the four-in-six
        // optional poison, the insanity and weakness rows the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23TailHi() != 4
            || s23PoisonChance() != 4
            || s23InsanityRoundsMax() != 4
            || s23WeaknessPoints() != 1
            || s23TailTypeCount() != 8
        )
            ++bad;
        // the exceptional strength subrolls - the fifty, seventy-five, ninety
        // and ninety-nine ceilings, the forty-five overlap the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23StrSubFifty() != 50
            || s23StrSubNinety() != 90
            || s23StrSubNinetyNine() != 99
            || s23StrOverlapCatch() != 1
        )
            ++bad;
        // the attack forms - antlers to two-eight, mouth to three-twelve,
        // hands to two-twelve, feet to three-twelve, the huge claw floor the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23AntlerSidesMax() != 8
            || s23MouthDmgMaxSides() != 12
            || s23HandSidesMax() != 12
            || s23FootSidesMax() != 12
            || s23HugeClawDice() != 2
        )
            ++bad;
        // the special attacks and defenses - one to three of eight attacks,
        // one to four of ten defenses, the two-to-five spell ceiling the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23SpecAtkMax() != 3
            || s23SpecAtkOptions() != 8
            || s23PowerSpellMax() != 5
            || s23SpecDefMax() != 4
            || s23SpecDefOptions() != 10
        )
            ++bad;
        // the defense limits - the regeneration base, the one-to-four
        // pre-determined spells, the three metals, the plus-one weapon floor
        // the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23RegenBase() != 1
            || s23SpellImmuMax() != 4
            || s23MetalKinds() != 3
            || s23WeaponImmuMinPlus() != 1
            || s23ImmunityOverFourConditional() != 1
        )
            ++bad;
        // the print-catch roll - the two-word forth coming, the Df. citation,
        // the bird asterisk, the EXXEDUUNUSSE vacation sign-off the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23ForthComingCatch() != 1
            || s23DfForCfCatch() != 1
            || s23BirdAsteriskCatch() != 1
            || s23ExxeduunusseSignoff() != 1
        )
            ++bad;
        // the closing notes - the three optional abilities, the Tarterus
        // canon pin, the thrice circumstances-must-dictate the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23OtherAbilities() != 3
            || s23TarterusCanon() != 0
            || s23CircumstancesDictate() != 1
        )
            ++bad;
        // the head spot check - bat-like one, weasel-like eight the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23HeadOpt(0) != 1
            || s23HeadOpt(7) != 8
        )
            ++bad;
        // the adornment spot check - antlers one, none eight the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23AdornOpt(0) != 1
            || s23AdornOpt(7) != 8
        )
            ++bad;
        // the visage spot check - gibbering-drooling one, wrinkled-seamed six
        // the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23VisageOpt(0) != 1
            || s23VisageOpt(5) != 6
        )
            ++bad;
        // the ears spot check - dog-like one, none six the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23EarsOpt(0) != 1
            || s23EarsOpt(5) != 6
        )
            ++bad;
        // the eye grid spot check - small multi-faceted amber, huge
        // protruding orange-red the Sorceror Scroll lower-planes generator
        // (print 15-18)
    if (s23EyeFormOpt(0) != 1
            || s23EyeColorOpt(0) != 1
            || s23EyeFormOpt(5) != 6
            || s23EyeColorOpt(5) != 6
        )
            ++bad;
        // the nose spot check - flat misshapen one, trunk-like six the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23NoseOpt(0) != 1
            || s23NoseOpt(5) != 6
        )
            ++bad;
        // the mouth type spot check - fanged one, tusked six the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23MouthOpt(0) != 1
            || s23MouthOpt(5) != 6
        )
            ++bad;
        // the bipedal torso spot check - ape-like one, rat-like six the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23BipedOpt(0) != 1
            || s23BipedOpt(5) != 6
        )
            ++bad;
        // the quadrapedal torso spot check - amoeba-like one, spider-like
        // seven the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23QuadOpt(0) != 1
            || s23QuadOpt(6) != 7
        )
            ++bad;
        // the characteristics spot check - fat one, rubbery eight the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23CharOpt(0) != 1
            || s23CharOpt(7) != 8
        )
            ++bad;
        // the back spot check - humped-hunched one, spiked-spined-ridged four
        // the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23BackOpt(0) != 1
            || s23BackOpt(3) != 4
        )
            ++bad;
        // the skin spot check - bald-smooth one, translucent ten the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23SkinOpt(0) != 1
            || s23SkinOpt(9) != 10
        )
            ++bad;
        // the wings spot check - bat-like one, membranous or fan-like four
        // the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23WingOpt(0) != 1
            || s23WingOpt(3) != 4
        )
            ++bad;
        // the color spot check - blackish one, yellowish-tannish ten the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23ColorOpt(0) != 1
            || s23ColorOpt(9) != 10
        )
            ++bad;
        // the tail type spot check - barbed one, stingered eight the Sorceror
        // Scroll lower-planes generator (print 15-18)
    if (s23TailTypeOpt(0) != 1
            || s23TailTypeOpt(7) != 8
        )
            ++bad;
        // the odor spot check - bloody one, vomit eight the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23OdorOpt(0) != 1
            || s23OdorOpt(7) != 8
        )
            ++bad;
        // the hands spot check - clawed one, withered and boney six the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23HandTypeOpt(0) != 1
            || s23HandTypeOpt(5) != 6
        )
            ++bad;
        // the feet spot check - clawed one, webbed eight the Sorceror Scroll
        // lower-planes generator (print 15-18)
    if (s23FeetOpt(0) != 1
            || s23FeetOpt(7) != 8
        )
            ++bad;
        // the bird feet spot check - duck-like one, turkey-like six the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23BirdFootOpt(0) != 1
            || s23BirdFootOpt(5) != 6
        )
            ++bad;
        // the move spot check - six inches one, eighteen inches five the
        // Sorceror Scroll lower-planes generator (print 15-18)
    if (s23MoveInch(0) != 6
            || s23MoveInch(4) != 18
        )
            ++bad;
        // the magic resistance variance spot check - minus five, minus ten,
        // the standard zero on six the Sorceror Scroll lower-planes generator
        // (print 15-18)
    if (s23MrMod(0) != -5
            || s23MrMod(1) != -10
            || s23MrMod(5) != 0
        )
            ++bad;
        // the poison save spot check - plus one, minus two, the insanity
        // sentinel the Sorceror Scroll lower-planes generator (print 15-18)
    if (s23PoisonOpt(0) != 1
            || s23PoisonMod(0) != 1
            || s23PoisonMod(3) != -2
            || s23PoisonMod(4) != -99
        )
            ++bad;
        // the strength spot check - the one-to-twenty-five seventeen, the
        // ninety-nine-and-double-zero twenty with plus eight damage, the
        // forty-five overlap band the Sorceror Scroll lower-planes generator
        // (print 15-18)
    if (s23StrLo(0) != 1
            || s23StrHi(0) != 25
            || s23StrVal(0) != 17
            || s23StrDmg(8) != 8
            || s23StrVal(8) != 20
            || s23StrLo(2) != 45
            || s23StrHi(2) != 60
        )
            ++bad;
        printf("R951 issue-23 Lower Planes generation audit: bad %d\n", bad);
        if (bad) return 1;
    }
