// =========================================================================================
// Adnd1 - rules/oa125table83.h
// OA TREASURE - TABLE 83, MISSILE CLASS, printed capture p. 293 - the missile
// type grid round
// census 676 -> 677.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 207 closed, 28 open - the Table 83 box
// flips (census 676 -> 677); NEXT - R755: Table 84: Martial Arts Class
// (capture p. 293), prefix dlq (verify free at the landing), audit "R755 OA
// Table 84 martial arts audit", include after rules/oa125table83.h
//
namespace rules {

// ---- the Table 83 grid ----

// the missile row count - the twelve d100 bands of the Table 83 missile type
// grid (print capture p. 293)
inline int dlpMissileRowCount()
    { return 12; }

// the d100 band minimum - the low roll of the row (print capture p. 293)
inline int dlpMissileRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 21;
        case 3:
            return 26;
        case 4:
            return 41;
        case 5:
            return 61;
        case 6:
            return 71;
        case 7:
            return 72;
        case 8:
            return 73;
        case 9:
            return 78;
        case 10:
            return 91;
        case 11:
            return 99;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 293)
inline int dlpMissileRollMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 40;
        case 4:
            return 60;
        case 5:
            return 70;
        case 6:
            return 71;
        case 7:
            return 72;
        case 8:
            return 77;
        case 9:
            return 90;
        case 10:
            return 98;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// the missile type code - 1 the armor piercer arrow, 2-12 damage; 2 the frog
// crotch arrow, 2-8 damage; 3 the humming bulb arrow, 2-5 damage; 4 the leaf
// head arrow, 2-12 damage; 5 the normal arrow, 3-24 damage; 6 the throwing
// axe; 7 the blowpipe dart, 2-8 damage; 8 the thrown dart, 3-12 damage; 9 the
// javelin; 10 the quarrel, 2-24 damage; 11 the sling and pellet bow bullets,
// 2-20 damage; 12 the uchi-ne (print capture p. 293)
inline int dlpMissileCode(int b)
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

// ---- the quirks ----

// the arrow bands - the five arrow types of the 01-60 stretch, the armor
// piercer through the normal (print capture p. 293)
inline int dlpArrowBands()
    { return 1; }

// the single-roll bands - the 71 blowpipe dart and the 72 thrown dart, the
// one-number bands of the grid (print capture p. 293)
inline int dlpSingleRollBands()
    { return 1; }

// the uchi-ne tail - the 99-100 closing band, the short Japanese throwing
// dart (print capture p. 293)
inline int dlpUchiNeTail()
    { return 1; }

}   // namespace rules
