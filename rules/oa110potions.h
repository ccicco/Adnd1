// =========================================================================================
// Adnd1 - rules/oa110potions.h
// OA TREASURE - POTIONS, printed capture pp. 287-288 - the control brews
// round
// census 661 -> 662.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 192 closed, 43 open - the potions box
// flips (census 661 -> 662); NEXT - R740: Scrolls (capture p. 288), prefix
// dlb (verify free at the landing), audit "R740 OA scrolls audit", include
// after rules/oa110potions.h
//
namespace rules {

// ---- the dragon control ----

// the dragon control row count - the twelve d20 bands of the potion table
// (print capture p. 287)
inline int dlaDragonRowCount()
    { return 12; }

// the existence - the potions of dragon control do exist (print capture p.
// 287)
inline int dlaDragonControlExists()
    { return 1; }

// the difference - they do not affect the same types of dragons as those
// listed in the DMG (print capture p. 287)
inline int dlaNotSameDragonsAsDMG()
    { return 1; }

// the instruction - use the table given below (print capture p. 287)
inline int dlaUseTableBelow()
    { return 1; }

// the d20 band minimum - the low roll of the row (print capture p. 287)
inline int dlaDragonRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 15;
        case 8:
            return 16;
        case 9:
            return 17;
        case 10:
            return 18;
        case 11:
            return 20;
        default:
            return 0;
        }
    }

// the d20 band maximum - the high roll of the row (print capture p. 287)
inline int dlaDragonRollMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 16;
        case 9:
            return 17;
        case 10:
            return 19;
        case 11:
            return 20;
        default:
            return 0;
        }
    }

// the dragon code - 1 the chiang lung; 2 the pan lung; 3 the yu lung; 4 the
// shen lung; 5 the li lung; 6 the mist dragon; 7 the cloud dragon; 8 the lung
// wang; 9 the t'ien lung; 10 the gold dragon; 11 the evil dragon; 12 the good
// dragon (print capture p. 287)
inline int dlaDragonCode(int b)
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
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        default:
            return 0;
        }
    }

// ---- the band walk ----

// the 1-2 band - the chiang lung control (print capture p. 287)
inline int dlaChiangLung()
    { return 1; }

// the 3-4 band - the pan lung control (print capture p. 287)
inline int dlaPanLung()
    { return 1; }

// the 5-7 band - the yu lung control (print capture p. 287)
inline int dlaYuLung()
    { return 1; }

// the 8-9 band - the shen lung control (print capture p. 287)
inline int dlaShenLung()
    { return 1; }

// the 10 band - the li lung control (print capture p. 287)
inline int dlaLiLung()
    { return 1; }

// the 11-12 band - the mist dragon control (print capture p. 287)
inline int dlaMistDragon()
    { return 1; }

// the 13-14 band - the cloud dragon control (print capture p. 287)
inline int dlaCloudDragon()
    { return 1; }

// the 15 band - the lung wang control (print capture p. 287)
inline int dlaLungWang()
    { return 1; }

// the 16 band - the t'ien lung control (print capture p. 287)
inline int dlaTienLung()
    { return 1; }

// ---- the giant, human, and undead ----

// the giant control - the only type commonly found is the hill giant control
// (print capture p. 287)
inline int dlaGiantControlHillGiant()
    { return 1; }

// the human control row count - the seven d20 bands of the potion controls
// table (print capture p. 288)
inline int dlaHumanRowCount()
    { return 7; }

// the human control intro - when determining the type of creature that can be
// controlled, use the following table (print capture p. 287)
inline int dlaHumanControlIntro()
    { return 1; }

// the d20 band minimum - the low roll of the row (print capture p. 288)
inline int dlaHumanRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// the d20 band maximum - the high roll of the row (print capture p. 288)
inline int dlaHumanRollMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 19;
        case 6:
            return 20;
        default:
            return 0;
        }
    }

// the controls code - 1 the korobokuru; 2 the hengeyokai; 3 the spirit folk;
// 4 the human; 5 the tengu; 6 the korobokuru, hengeyokai, and humans; 7 the
// gajin of the DMG table (print capture p. 288)
inline int dlaHumanCode(int b)
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
            return 0;
        }
    }

// the 20 band - the gajin, rolled on the DMG table (print capture p. 288)
inline int dlaGajinRollOnDMG()
    { return 1; }

// the undead control - not normally available in Oriental lands, the result
// rerolled (print capture p. 288)
inline int dlaUndeadControlRerolled()
    { return 1; }

}   // namespace rules
