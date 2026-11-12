    // ---- R943 issue-21 opener part one audit ----
    // THE DRAGON ISSUE-21 OPENER PART ONE - the three-chain round of the
    // issue-21 three-round shape. Three chains pinned from the
    // Curtiss-provided Dm21.pdf scan: the Stevens Encounters with Personality
    // - the twenty-NPC statline kit across three print pages; the Pehr
    // Sensible Sorcery - the three Rules of Research, the Suliin spell-level
    // critiques and the specialist exception; the Schroeder Prophet Proofing
    // - the five foretelling spells and their counters, from the Medivar
    // deterrents to the fifteen-die Kobold fireball. Part two (the inflation
    // economics, the monster blues, the Hall of Mystery, the title kit) rides
    // R944, the closing flip R945.
    {
        using namespace rules;
        int bad = 0;
    if (t21NpcCount() != 20
            || t21NpcFirstPage() != 9
            || t21NpcMidPage() != 10
            || t21NpcLevelSeventeen() != 17
            || t21NpcRolloLevel() != 9
            || t21NpcRolloHp() != 24
            || t21NpcRolloAc() != 9
            || t21NpcClarHeight() != 12
            || t21NpcRolloStatlineSeven() != 7
            || t21ResearchRules() != 3
            || t21MoonRunesLevel() != 2
            || t21MagicMissileTwoLevel() != 2
            || t21WallWaterBlockHd() != 5
            || t21WallWaterFireDice() != 6
            || t21WallFireBlockHd() != 4
            || t21WallIceFireDice() != 1
            || t21ShatterrayMin() != 5
            || t21ShatterrayMax() != 30
            || t21IceStormMin() != 3
            || t21IceStormMax() != 30
            || t21FireMageBoltsLevel() != 2
            || t21ForetellingSpells() != 5
            || t21InsanityContagionMin() != 2
            || t21InsanityContagionMax() != 7
            || t21NonDirectionalFeet() != 60
            || t21LeadInches() != 3
            || t21VoyeurPct() != 33
            || t21WizardEyeUsesPerDay() != 3
            || t21HelmFireballDice() != 15
            || t21InsanityArticleIssue() != 18
            || !t21NpcDassolConfederates()
            || !t21NpcGleenSocks()
            || !t21NpcGruntArmsBan()
            || !t21NpcZilchRollo()
            || !t21NpcPontanceDisguise()
            || !t21NpcKlundRoar()
            || !t21RuleOne()
            || !t21RuleTwo()
            || !t21RuleThree()
            || !t21SpecialistException()
            || !t21VendingMachineWarning()
            || !t21ClericNoAttackMagic()
            || !t21MuNoDivineAid()
            || !t21WallWaterNoConcentration()
            || !t21SuliinSpellingPrintCatch()
            || !t21MedivarDeterrent()
            || !t21HarpyDeterrent()
            || !t21SanityContagionDoctrine()
            || !t21WizardEyeNoLiquidsSolids()
            || !t21XrayLeadBuiltIn()
            || !t21ParanoidNpcProtection()
            || !t21HelmKoboldTrick()
            || !t21MedallionBlueMovies()
        )
            ++bad;
        // the personality statline grid - twenty NPCs down, the eleven
        // columns across: level, hit points, armor class, the six stats, the
        // to-hit and to-damage bonuses; the printed Ave. bonus lines pinned
        // 0, the conversion noted, and the Clar werebear armor class 2 pinned
        // with the apparent-9 footnote, the Pontance disguise charisma 14
        // pinned with the asterisk footnote the twenty-NPC personality grid
        // (print 11 + 23 + 27, PDF 13 + 25 + 29)
        int CNp[20][11] = {
            {3,20,5,16,7,7,6,8,6,1,1},
            {4,23,6,15,9,7,12,9,4,0,0},
            {17,64,-2,8,17,9,11,13,11,0,0},
            {6,36,7,17,12,10,13,19,16,2,2},
            {7,45,2,18,16,14,18,9,11,4,6},
            {11,69,7,18,10,8,16,11,14,3,4},
            {13,51,9,8,6,19,7,7,7,0,0},
            {1,9,7,17,9,10,9,7,8,2,2},
            {1,9,9,18,12,8,16,4,5,3,3},
            {1,2,2,4,9,11,3,6,15,-2,-1},
            {1,8,8,16,8,4,14,10,10,1,1},
            {2,4,7,5,10,14,7,16,18,-1,0},
            {2,20,8,10,10,8,10,10,7,0,0},
            {3,9,9,14,7,8,10,8,4,1,0},
            {5,27,3,13,9,4,10,10,6,0,0},
            {5,28,4,17,11,10,14,9,9,2,2},
            {6,51,7,18,7,6,18,10,6,4,6},
            {7,11,9,8,15,16,6,13,14,1,0},
            {8,33,6,15,9,7,13,10,12,1,0},
            {9,30,9,8,10,14,8,14,6,0,0},
            };
        for (int b = 0;
             b < t21NpcCount();
             ++b) {
            int vals[11];
            vals[0] = t21NpcLevel(b);
            vals[1] = t21NpcHp(b);
            vals[2] = t21NpcAc(b);
            vals[3] = t21NpcStr(b);
            vals[4] = t21NpcInt(b);
            vals[5] = t21NpcWis(b);
            vals[6] = t21NpcCon(b);
            vals[7] = t21NpcDex(b);
            vals[8] = t21NpcCha(b);
            vals[9] = t21NpcToHit(b);
            vals[10] = t21NpcToDmg(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CNp[b][c])
                    ++bad;
            }
        }
        // the personality census - twenty NPCs across three print pages, the
        // Gantol 17th dual and the Rollo 9/24/9 inline statline the
        // twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
    if (t21NpcCount() != 20
            || t21NpcFirstPage() != 9
            || t21NpcMidPage() != 10
            || t21NpcLevelSeventeen() != 17
            || t21NpcRolloLevel() != 9
            || t21NpcRolloHp() != 24
            || t21NpcRolloAc() != 9
        )
            ++bad;
        // the grid corners - the Blarg opener, the Gantol -2 dual, the Tarky
        // charisma 14, the Iradain dexterity 19, the Grunt 2-hit-point
        // minus-2 floor the twenty-NPC personality grid (print 11 + 23 + 27,
        // PDF 13 + 25 + 29)
    if (t21NpcLevel(0) != 3
            || t21NpcHp(0) != 20
            || t21NpcAc(0) != 5
            || t21NpcLevel(2) != 17
            || t21NpcAc(2) != -2
            || t21NpcToHit(2) != 0
            || t21NpcCha(5) != 14
            || t21NpcDex(3) != 19
            || t21NpcHp(9) != 2
            || t21NpcToHit(9) != -2
        )
            ++bad;
        // the grid tail - the Dassol closer, the Gleen charisma 18, the Klund
        // 51 with the plus-4 plus-6 club, the Pontance 14 disguise charisma
        // and the Rollo seven-stat print catch the twenty-NPC personality
        // grid (print 11 + 23 + 27, PDF 13 + 25 + 29)
    if (t21NpcLevel(19) != 9
            || t21NpcHp(19) != 30
            || t21NpcAc(19) != 9
            || t21NpcCha(11) != 18
            || t21NpcHp(16) != 51
            || t21NpcToHit(16) != 4
            || t21NpcToDmg(16) != 6
            || t21NpcCha(17) != 14
            || t21NpcRolloStatlineSeven() != 7
        )
            ++bad;
        // the personality doctrine - the twelve-foot Clar, the Dassol
        // confederates, the Gleen five-percent pick-everyone, the Grunt arms
        // ban, the Zilch-Rollo gags, the Pontance cloak and the Klund roar
        // the twenty-NPC personality grid (print 11 + 23 + 27, PDF 13 + 25 +
        // 29)
    if (t21NpcClarHeight() != 12
            || t21NpcDassolConfederates() != 1
            || t21NpcGleenSocks() != 1
            || t21NpcGruntArmsBan() != 1
            || t21NpcZilchRollo() != 1
            || t21NpcPontanceDisguise() != 1
            || t21NpcKlundRoar() != 1
        )
            ++bad;
        // the research census - three rules, the Moon Runes, Magic Missile II
        // and Fire-Mage bolts all at second level, the Wall of Water
        // 5-hit-dice 6-dice case against the existing wall benchmarks the
        // spell-research doctrine (print 10, PDF 12)
    if (t21ResearchRules() != 3
            || t21MoonRunesLevel() != 2
            || t21MagicMissileTwoLevel() != 2
            || t21FireMageBoltsLevel() != 2
            || t21WallWaterBlockHd() != 5
            || t21WallWaterFireDice() != 6
            || t21WallFireBlockHd() != 4
            || t21WallIceFireDice() != 1
        )
            ++bad;
        // the Shatterray 5-30 against the Ice Storm 3-30 with none of the
        // extras, the three Rules of Research and the specialist exception
        // the spell-research doctrine (print 10, PDF 12)
    if (t21ShatterrayMin() != 5
            || t21ShatterrayMax() != 30
            || t21IceStormMin() != 3
            || t21IceStormMax() != 30
            || t21RuleOne() != 1
            || t21RuleTwo() != 1
            || t21RuleThree() != 1
            || t21SpecialistException() != 1
        )
            ++bad;
        // the research doctrine - the vending machine, the cleric and
        // magic-user dividing lines, the no-concentration critique and the
        // Suliin spelling print catch the spell-research doctrine (print 10,
        // PDF 12)
    if (t21VendingMachineWarning() != 1
            || t21ClericNoAttackMagic() != 1
            || t21MuNoDivineAid() != 1
            || t21WallWaterNoConcentration() != 1
            || t21SuliinSpellingPrintCatch() != 1
        )
            ++bad;
        // the foretelling census - five spells, the 2-7 turn insanity
        // contagion, the 60-foot non-directional option, the three-inch lead
        // and the TD-18 cross-reference the foretelling-spell counters (print
        // 9, PDF 11)
    if (t21ForetellingSpells() != 5
            || t21InsanityContagionMin() != 2
            || t21InsanityContagionMax() != 7
            || t21NonDirectionalFeet() != 60
            || t21LeadInches() != 3
            || t21InsanityArticleIssue() != 18
        )
            ++bad;
        // the counter census - the 33-percent voyeur, the 3-per-day
        // medallion, the fifteen-die Kobold fireball, the Medivar and harpy
        // deterrents and the contagion doctrine the foretelling-spell
        // counters (print 9, PDF 11)
    if (t21VoyeurPct() != 33
            || t21WizardEyeUsesPerDay() != 3
            || t21HelmFireballDice() != 15
            || t21MedivarDeterrent() != 1
            || t21HarpyDeterrent() != 1
            || t21SanityContagionDoctrine() != 1
        )
            ++bad;
        // the counter doctrine - the liquids-and-solids restriction, the
        // built-in lead limit, the paranoid NPC amulets, the Helm trick and
        // the blue-movie medallion economy the foretelling-spell counters
        // (print 9, PDF 11)
    if (t21WizardEyeNoLiquidsSolids() != 1
            || t21XrayLeadBuiltIn() != 1
            || t21ParanoidNpcProtection() != 1
            || t21HelmKoboldTrick() != 1
            || t21MedallionBlueMovies() != 1
        )
            ++bad;
        // the mid-grid catches - the Clar werebear 7th with armor class 2 and
        // plus-6 damage, the Volitia 3rd and the Bundline mummy 5th with
        // armor class 3 the twenty-NPC personality grid (print 11 + 23 + 27,
        // PDF 13 + 25 + 29)
    if (t21NpcLevel(4) != 7
            || t21NpcAc(4) != 2
            || t21NpcStr(4) != 18
            || t21NpcToDmg(4) != 6
            || t21NpcLevel(13) != 3
            || t21NpcAc(14) != 3
            || t21NpcLevel(14) != 5
            || t21NpcHp(14) != 27
        )
            ++bad;
        printf("R943 issue-21 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
