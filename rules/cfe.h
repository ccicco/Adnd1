// =========================================================================================
// Adnd1 - rules/cfe.h
// The Dragon issue-4 opener - the Creature Features chain: the Mihalli
// (folios 18-19), the Vriyagga (folios 19, 21) and the Qu'uni (folio 21),
// pinned as new variant-layer registry monsters
// census 822 -> 823.
//
// Pinned from The Dragon Vol. 1 No. 4 (December 1976), the archive.org scan:
// folios 18-19, the Mihalli - the humanoid hermaphroditic shape-changers with
// the 20 percent red-eye reveal, the two-to-three-plus bonus spells, the 40
// percent Eyes/amulets/scrolls lair chance and the four-step Ball of
// Immediate Eventuation colour ladder reserved to the fourteenth level and
// up; folios 19 and 21, the Vriyagga - the tentacled city creature with the
// 12/10/8 move, the 10/15/25 hit-dice ladder, the four-plus armor-class-2
// tentacles and the 2/4/6 dice per turn; folio 21, the Qu'uni sidebar - the
// pallid semi-transparent shrimp-like water-grotto swarm. The voice rides
// extract/dragon/004/ (all 36 issue pages, the chat-side DjVu OCR transcript
// cross-checked against the archive.org PDF text layer); the issue-4 gap
// report ships pre-flip. The editor's standing caution rides: none of this is
// official.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// with no 1e defs existing the Creature Features chain pins as NEW registry
// monsters - the Remorhaz lore-against-def precedent does not apply. The XP
// conversions ride the DMG p.85 additive formula (the Mihalli 115 base + 3
// per hp at 13 average, the Vriyagga 5250 + 20 per hp at 67, the Qu'uni 20 +
// 2 per hp at 9), the averages at the 4.5-per-die d8 convention floored,
// every conversion noted, never silent; the print's 'l-20' glyph pins as 1,
// the garbled F: 50 and I: 50 stat lines ride AS SCANNED with the semantics
// unpinned, the tentacle damage dice assume d6 noted, and the Vriyagga XP
// pins the 15-dice middle size with the full size ladder in the pin header;
// the three lua defs carry the new dragon_print xp source, whitelisted at the
// R73 audit.
//
namespace rules {

// ---- the Mihalli (folios 18-19) ----

// the number appearing minimum - NA 1-20 (folio 18); the print's 'l-20' glyph
// pins as 1, the OCR-of-font artifact noted
inline int cfeMihalliNaMin()
    { return 1; }

// the number appearing maximum - NA 1-20 (folio 18)
inline int cfeMihalliNaMax()
    { return 20; }

// the armor class - AC 1 (folio 18)
inline int cfeMihalliAc()
    { return 1; }

// the movement rate - M 15 inches per turn (folio 18)
inline int cfeMihalliMove()
    { return 15; }

// the hit dice - HD 3 (folio 18)
inline int cfeMihalliHd()
    { return 3; }

// the chance of treasure in lair - L 40 percent (folio 18)
inline int cfeMihalliLairPct()
    { return 40; }

// the lair gold minimum - 80-800 only near own territory (folio 18)
inline int cfeMihalliLairMin()
    { return 80; }

// the lair gold maximum - 80-800 only near own territory (folio 18)
inline int cfeMihalliLairMax()
    { return 800; }

// the print stat line F: 50 - the glyph garbles in both the PDF layer and the
// OCR (folio 18); pinned AS SCANNED, semantics unpinned
inline int cfeMihalliF()
    { return 50; }

// the print stat line I: 50 - the glyph garbles in both the PDF layer and the
// OCR (folio 18); pinned AS SCANNED, semantics unpinned
inline int cfeMihalliI()
    { return 50; }

// the glowing red eyes reveal the Mihalli 20 percent of the turns they are
// looked at (folio 18)
inline int cfeMihalliRedEyesPct()
    { return 20; }

// the minimum two bonus spells of the higher Mihalli (folios 18-19)
inline int cfeMihalliBonusSpellsMin()
    { return 2; }

// the three-plus bonus spells at levels IV and up (folios 18-19)
inline int cfeMihalliBonusSpellsHigh()
    { return 3; }

// the 40 percent chance of Eyes, amulets or scrolls (folios 18-19)
inline int cfeMihalliEyeChancePct()
    { return 40; }

// the Ball of Immediate Eventuation climbs a four-step colour ladder (folio
// 19)
inline int cfeMihalliBallLadderCount()
    { return 4; }

// the ball ladder step 1 - light purple (folio 19)
inline int cfeMihalliBallPurple()
    { return 1; }

// the ball ladder step 2 - bright silver (folio 19)
inline int cfeMihalliBallSilver()
    { return 2; }

// the ball ladder step 3 - bright gold (folio 19)
inline int cfeMihalliBallGold()
    { return 3; }

// the ball ladder step 4 - lambent translucent blue (folio 19)
inline int cfeMihalliBallBlue()
    { return 4; }

// the ball is usable only by magic users and priests of the fourteenth level
// and up - below that it scrambles brains (folio 19)
inline int cfeMihalliUseLevelMin()
    { return 14; }

// the 5 percent chance a Mihalli is friendly - rolled each turn (folio 19)
inline int cfeMihalliFriendlyPct()
    { return 5; }

// the 1 percent chance a friendly Mihalli offers a magical item (folio 19)
inline int cfeMihalliOfferItemPct()
    { return 1; }

// the average hit points - 3 dice at the 4.5-per-die d8 convention, floored;
// the conversion noted, never silent
inline int cfeMihalliAvgHp()
    { return 13; }

// the base XP - DMG p.85 formula: 35 base + 25 one special + 55 one
// exceptional (folios 18-19); the conversion noted
inline int cfeMihalliXp()
    { return 115; }

// the XP per hit point - the DMG p.85 per-hit-die value at 3 dice (folios
// 18-19)
inline int cfeMihalliXpPerHp()
    { return 3; }

// the XP value - 115 + 3 x 13, the DMG p.85 additive formula (folios 18-19)
inline int cfeMihalliXpValue()
    { return 154; }

// the Mihalli are shape-changers (folio 19)
inline bool cfeMihalliShapeChanger()
    { return true; }

// the Mihalli are humanoid (folio 19)
inline bool cfeMihalliHumanoid()
    { return true; }

// the Mihalli are hermaphroditic (folio 19)
inline bool cfeMihalliHermaphroditic()
    { return true; }

// the Mihalli see in the dark (folio 19)
inline bool cfeMihalliSeeDark()
    { return true; }

// the Mihalli gas spares the Shen and the Ssu (folio 19)
inline bool cfeMihalliGasSparingShenSsu()
    { return true; }

// the Ball of Immediate Eventuation is usable only by magic users and priests
// XIV-up (folio 19)
inline bool cfeMihalliBallXivUpOnly()
    { return true; }

// below the fourteenth level the ball scrambles brains (folio 19)
inline bool cfeMihalliScrambleBelowXiv()
    { return true; }

// the Mihalli defends itself if attacked (folio 19)
inline bool cfeMihalliDefendsIfAttacked()
    { return true; }

// the reaction is rolled at random each turn (folio 19)
inline bool cfeMihalliRandomRollEachTurn()
    { return true; }

// ---- the Vriyagga (folios 19, 21) ----

// the number appearing minimum - NA 1-10 (folio 19)
inline int cfeVriyaggaNaMin()
    { return 1; }

// the number appearing maximum - NA 1-10 (folio 19)
inline int cfeVriyaggaNaMax()
    { return 10; }

// the armor class - AC 1 (folio 19)
inline int cfeVriyaggaAc()
    { return 1; }

// the L 40 percent stat line (folio 19) - the treasure itself is nil, the
// nil-in-lair bool carries the print
inline int cfeVriyaggaLairPct()
    { return 40; }

// the in-own-city number minimum - 20-200 (folio 19)
inline int cfeVriyaggaCityMin()
    { return 20; }

// the in-own-city number maximum - 20-200 (folio 19)
inline int cfeVriyaggaCityMax()
    { return 200; }

// the minimum four tentacles, more in the larger forms (folio 21)
inline int cfeVriyaggaTentaclesMin()
    { return 4; }

// it takes armor class 2 to sever a tentacle (folio 21)
inline int cfeVriyaggaTentacleAc()
    { return 2; }

// the average hit points - the 15-dice middle size at the 4.5-per-die d8
// convention, floored; the conversion noted, never silent
inline int cfeVriyaggaAvgHp()
    { return 67; }

// the base XP - the DMG p.85 formula at the 15-dice middle size: 2400 + 1250
// + 1600 (folio 19); the conversion noted
inline int cfeVriyaggaXp()
    { return 5250; }

// the XP per hit point - the DMG p.85 per-hit-die value at 15 dice (folio 19)
inline int cfeVriyaggaXpPerHp()
    { return 20; }

// the XP value - 5250 + 20 x 67, the DMG p.85 additive formula (folio 19)
inline int cfeVriyaggaXpValue()
    { return 6590; }

// the cfeVriyaggaSizes table runs 3 rows (folios 19, 21)
inline int cfeVriyaggaSizesCount()
    { return 3; }

// the movement rate by size - 12, 10 and 8 inches per turn (folios 19, 21)
inline int cfeVriSizeMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 8;
        default:
            return 30;
        }
    }

// the hit dice by size - 10, 15 and 25 (folios 19, 21)
inline int cfeVriSizeHd(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 25;
        default:
            return 30;
        }
    }

// the tentacle damage dice per turn by size - 2, 4 and 6, assumed d6 (folios
// 19, 21)
inline int cfeVriSizeDice(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        default:
            return 30;
        }
    }

// the treasure is nil (folio 19)
inline bool cfeVriyaggaNilTreasure()
    { return true; }

// the treasure is nil in lair too - T in L nil (folio 19)
inline bool cfeVriyaggaNilTreasureInLair()
    { return true; }

// the Vriyagga senses heat (folio 21)
inline bool cfeVriyaggaSensesHeat()
    { return true; }

// the Vriyagga cannot speak (folio 21)
inline bool cfeVriyaggaCannotSpeak()
    { return true; }

// the Vriyagga thinks, organizes and lays ambushes (folio 21)
inline bool cfeVriyaggaAmbushThinker()
    { return true; }

// the Vriyagga cannot climb stairs (folio 21)
inline bool cfeVriyaggaNoStairs()
    { return true; }

// the black-opal eyes see in the dark (folio 21)
inline bool cfeVriyaggaSeeDark()
    { return true; }

// ---- the Qu'uni (folio 21) ----

// the hit dice - 2 (folio 21 sidebar)
inline int cfeQuuniHd()
    { return 2; }

// the movement rate - 10 inches per turn (folio 21 sidebar)
inline int cfeQuuniMove()
    { return 10; }

// the number appearing minimum - 50-100 (folio 21 sidebar)
inline int cfeQuuniNaMin()
    { return 50; }

// the number appearing maximum - 50-100 (folio 21 sidebar)
inline int cfeQuuniNaMax()
    { return 100; }

// the armor class - AC 3 (folio 21 sidebar)
inline int cfeQuuniAc()
    { return 3; }

// the average hit points - 2 dice at the 4.5-per-die d8 convention, floored;
// the conversion noted, never silent
inline int cfeQuuniAvgHp()
    { return 9; }

// the base XP - the DMG p.85 formula at 2 dice, no specials (folio 21
// sidebar); the conversion noted
inline int cfeQuuniXp()
    { return 20; }

// the XP per hit point - the DMG p.85 per-hit-die value at 2 dice (folio 21
// sidebar)
inline int cfeQuuniXpPerHp()
    { return 2; }

// the XP value - 20 + 2 x 9, the DMG p.85 additive formula (folio 21 sidebar)
inline int cfeQuuniXpValue()
    { return 38; }

// the Qu'uni automatically attack human parties seeking water (folio 21
// sidebar)
inline bool cfeQuuniAttacksWaterSeekers()
    { return true; }

// no treasure except under the water in its sea-grotto home (folio 21
// sidebar)
inline bool cfeQuuniSeaGrottoTreasure()
    { return true; }

// the Qu'uni carry no treasure (folio 21 sidebar)
inline bool cfeQuuniNoTreasure()
    { return true; }

// the Qu'uni are pallid, semi-transparent, shrimp-like creatures (folio 21
// sidebar)
inline bool cfeQuuniShrimpLike()
    { return true; }

// ---- the registry walk ----

// the live lua def census after the three promotions - the 1308 loaded base
// defs plus the Mihalli, the Vriyagga and the Qu'uni; the 1333 base lua files
// include 25 long-standing load-error defs (broken text lines) that never
// enter the registry, a pre-R900 print-fidelity state this round does not
// touch (the Termux battery line 'loaded 1311, errors 25' is the ground
// truth)
inline int cfeRegistryAfter()
    { return 1311; }

}   // namespace rules
