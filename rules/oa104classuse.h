// =========================================================================================
// Adnd1 - rules/oa104classuse.h
// OA TREASURE - THE MAGICAL ITEMS USABLE BY CLASS, printed capture p. 285 -
// the Chapter 13 opener round
// census 655 -> 656.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 186 closed, 49 open - the class usage box
// flips (census 655 -> 656); NEXT - R734: the Random Treasure Determination
// prose (capture pp. 285-286), prefix dkv (verify free at the landing), audit
// "R734 OA random treasure prose audit", include after rules/oa104classuse.h
//
namespace rules {

// ---- the chapter 13 opener ----

// the chapter opener - the treasure and magical items chapter of the goal of
// accumulating treasure (print capture p. 285)
inline int dkuChapterOpener()
    { return 1; }

// the power line - money and magic is power (print capture p. 285)
inline int dkuMoneyMagicPower()
    { return 1; }

// the power to influence destiny - the first half of the power line (print
// capture p. 285)
inline int dkuPowerToInfluenceDestiny()
    { return 1; }

// the power to influence others - the second half of the power line (print
// capture p. 285)
inline int dkuPowerToInfluenceOthers()
    { return 1; }

// the access - the treasure found gives access to the power, the use being
// another matter (print capture p. 285)
inline int dkuTreasureGivesAccess()
    { return 1; }

// the DMG relation - the information supplements the Dungeon Masters Guide
// (print capture p. 285)
inline int dkuSupplementsDMG()
    { return 1; }

// the overlap - most DMG magic items can be found in the world of the Orient
// (print capture p. 285)
inline int dkuMostDMGItemsFound()
    { return 1; }

// the peculiar items - the magical items peculiar to the Oriental world given
// here (print capture p. 285)
inline int dkuPeculiarItemsGiven()
    { return 1; }

// the integration - the necessary tables and information to integrate them
// into a campaign (print capture p. 285)
inline int dkuIntegrationTables()
    { return 1; }

// ---- the restrictions and the codes ----

// the restrictions clause - the DMG item restrictions by class applied for
// Oriental characters as follows (print capture p. 285)
inline int dkuDMGRestrictionsApply()
    { return 1; }

// the fighter code - the samurai, bushi, and kensai mapping, and the sohei
// half (print capture p. 285)
inline int dkuCodeFighter()
    { return 1; }

// the cleric code - the shukenja mapping, and the sohei half except staves
// (print capture p. 285)
inline int dkuCodeCleric()
    { return 2; }

// the magic-user code - the wu jen mapping (print capture p. 285)
inline int dkuCodeMagicUser()
    { return 3; }

// the thief code - the ninja and yakuza mappings (print capture p. 285)
inline int dkuCodeThief()
    { return 4; }

// the sohei split code - the fighter and cleric-except-staves of the sohei
// row (print capture p. 285)
inline int dkuCodeSoheiSplit()
    { return 5; }

// ---- the class table ----

// the class table row count - the eight Oriental classes of the mapping table
// (print capture p. 285)
inline int dkuClassCount()
    { return 8; }

// the usable-by code - the fighter 1 of the samurai, bushi, and kensai; the
// sohei split 5; the cleric 2 of the shukenja; the magic-user 3 of the wu
// jen; the thief 4 of the ninja and yakuza (print capture p. 285)
inline int dkuUsableCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        default:
            return 0;
        }
    }

// ---- the per-class mappings ----

// the samurai mapping - the fighter items (print capture p. 285)
inline int dkuSamuraiFighter()
    { return 1; }

// the sohei mapping - the fighter and cleric items except for staves (print
// capture p. 285)
inline int dkuSoheiFighterClericExceptStaves()
    { return 1; }

// the shukenja mapping - the cleric items (print capture p. 285)
inline int dkuShukenjaCleric()
    { return 1; }

// the bushi mapping - the fighter items (print capture p. 285)
inline int dkuBushiFighter()
    { return 1; }

// the kensai mapping - the fighter items (print capture p. 285)
inline int dkuKensaiFighter()
    { return 1; }

// the wu jen mapping - the magic-user items (print capture p. 285)
inline int dkuWuJenMagicUser()
    { return 1; }

// the ninja mapping - the thief items (print capture p. 285)
inline int dkuNinjaThief()
    { return 1; }

// the yakuza mapping - the thief items (print capture p. 285)
inline int dkuYakuzaThief()
    { return 1; }

}   // namespace rules
