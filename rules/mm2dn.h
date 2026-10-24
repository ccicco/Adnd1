// =========================================================================================
// Adnd1 - rules/mm2dn.h
// THE MM2 LETTER D PART 4 - THE DIAKK AND DINOSAUR WALK (the diakk and the
// DINOSAUR family pp. 49-55: the 19 dinosaur form stat blocks under the
// doctrine-only family head), promoted to the live registry
// census 724 -> 725.
//
// Round six of the MM2 arc, the fourth PART-LETTER walk (the user Go call on
// the landed devil section: the letter D continues with the diakk and the
// dinosaur walk pp. 49-55; the dracolisk, dragon, dragonnel, drelb, drider,
// duergar and dustdigger turns and the rest of D await the user call). The
// capture is the Curtiss PDF upload cross-checked against the independent
// transcription and the archive.org djvu OCR, the contested cells settled:
// the nothosaurus 18 xp/hp over the transcription 12; the struthiomimus 2-8
// tail over the transcription 1-8; the Nighthags word over the capture
// Nightbags; the podokesaurus prose prints under the struthiomimus block (the
// print quirk, the empty text pinned); the ranged hit-dice cells read the low
// end (the kuei precedent); the diakk or-forms read the broad max. Census 724
// -> 725, registry 583 -> 603, 20 defs, no gap flips.
//
namespace rules {

// ---- the MM2 letter D part 4 round pins (the R802 census) ----

// The MM2 letter D part 4 round: the diakk and dinosaur walk (the user Go
// call on the landed devil section)
inline int mm2dnRound()
    { return 802; }

// The registry census before the R802 promotion (the landed R801 count)
inline int mm2dnRegistryBefore()
    { return 583; }

// The registry census after the R802 promotion (583 + the 20 promoted defs)
inline int mm2dnRegistryAfter()
    { return 603; }

// The R802 def count: the diakk and the 19 dinosaur forms ride the R791
// data_files extension
inline int mm2dnDefCount()
    { return 20; }

// The R802 pin-time entry count: the diakk entry plus the 19 dinosaur form
// stat blocks (the DINOSAUR family head on p. 50 carries doctrine only, no
// stat block)
inline int mm2dnEntryCount()
    { return 20; }

// The dinosaur family form count: the 19 dinosaur form stat blocks walk the
// family head pp. 50-55
inline int mm2dnDinosaurFormCount()
    { return 19; }

// The DinoStats grid row count (the diakk row plus the 19 dinosaur form rows,
// in print order)
inline int mm2dnDinoStatRows()
    { return 20; }

// ---- the diakk and dinosaur doctrine pins (the R802 letter D part 4) ----

// The tall diakk hit dice: 6 (+6) - the print tall/broad or-form reads its
// max for the def (the broad 8+8 rides the grid)
inline int mm2dnDiakkTallHitDiceNum()
    { return 6; }

// The tall diakk hit dice bonus (HD 6+6)
inline int mm2dnDiakkTallHitDiceBonus()
    { return 6; }

// The broad diakk hit dice: 8 (+8)
inline int mm2dnDiakkBroadHitDiceNum()
    { return 8; }

// The broad diakk hit dice bonus (HD 8+8)
inline int mm2dnDiakkBroadHitDiceBonus()
    { return 8; }

// The diakk circling dance needs 4 consecutive rounds of hooting calls and
// croaks
inline int mm2dnDiakkCirclingDanceRounds()
    { return 4; }

// At least 4 diakka must succeed in circling the opponents to evoke the dance
inline int mm2dnDiakkCirclingDanceMinimum()
    { return 4; }

// The hypnotic enfeeblement acts as if by a 13th level magic-user
inline int mm2dnDiakkEnfeeblementCasterLevel()
    { return 13; }

// The enfeebled subject suffers 40% strength loss
inline int mm2dnDiakkEnfeeblementStrengthLossPct()
    { return 40; }

// The enfeeblement lasts 13 rounds
inline int mm2dnDiakkEnfeeblementDurationRounds()
    { return 13; }

// In their lair there will always be at least 13 diakka
inline int mm2dnDiakkLairBandMin()
    { return 13; }

// In their lair there will be at most 16 diakka
inline int mm2dnDiakkLairBandMax()
    { return 16; }

// The diakk weakness by touch in attack: 1 per day
inline int mm2dnDiakkWeaknessPerDay()
    { return 1; }

// The diakk jump: 2 per day
inline int mm2dnDiakkJumpPerDay()
    { return 2; }

// The diakk audible glamor: 1 per day
inline int mm2dnDiakkAudibleGlamorPerDay()
    { return 1; }

// Each subject of the circling-dance enfeeblement must save vs. spell
// regardless of magic resistance
inline bool mm2dnDiakkEnfeeblementIgnoresMagicResistance()
    { return true; }

// The circling-dance enfeeblement has an area effect identical to the ray of
// enfeeblement spell
inline bool mm2dnDiakkDanceIsAreaRayOfEnfeeblement()
    { return true; }

// A diakk on the Prime Material Plane always appears due to summoning
inline bool mm2dnDiakkPrimeMaterialBySummoningOnly()
    { return true; }

// Night hags frequently use diakka as guards (the capture Nightbags is the
// OCR misread; the transcription and the djvu agree on Nighthags)
inline bool mm2dnDiakkNightHagGuards()
    { return true; }

// Diakka speak the hateful tongue common to Hades and their own language
inline bool mm2dnDiakkSpeaksHadesTongueAndOwn()
    { return true; }

// All of these reptiles are extremely stupid
inline bool mm2dnDinosaursExtremelyStupid()
    { return true; }

// The dinosaur motivation is primarily hunger
inline bool mm2dnDinosaurMotivationPrimarilyHunger()
    { return true; }

// The predatory types are both ferocious and voracious
inline bool mm2dnPredatoryDinosaursFerociousVoracious()
    { return true; }

// The herbivorous dinosaurs are likewise insatiable eaters
inline bool mm2dnHerbivorousDinosaursInsatiable()
    { return true; }

// The herbivores tend to ignore all noneatable things which do not threaten
// them or flee in panic from anything dangerous
inline bool mm2dnHerbivoresIgnoreOrFlee()
    { return true; }

// Certain plant eaters are aggressive in their defense, and these sorts are
// dangerous
inline bool mm2dnSomePlantEatersAggressiveInDefense()
    { return true; }

// Marine dinosaurs might overturn vessels to get at the food aboard or snatch
// creatures from the decks of passing ships
inline bool mm2dnMarineDinosaursOverturnVessels()
    { return true; }

// Land carnivores pursue anything edible, ceasing only when the prey has
// moved out of their grasp
inline bool mm2dnLandCarnivoresPursueUntilOutOfGrasp()
    { return true; }

// A creature in the path of a herbivore stampede is carried along or killed
// if smaller, slower, and weaker
inline bool mm2dnStampedeCarriesSmallerSlowerWeaker()
    { return true; }

// Several of the creatures listed are not true dinosaurs but fit the lost
// world surroundings (see MONSTER MANUAL I, Dinosaur)
inline bool mm2dnSeveralNotTrueDinosaurs()
    { return true; }

// ---- the MM2 letter D part 4 stat grid (the R802 wiring) ----

// The diakk and dinosaur form armor class cells (the or-form and slash-form
// cells read their best value)
inline int mm2dnDinoStatAC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 2;
        case 10:
            return 7;
        case 11:
            return 5;
        case 12:
            return 6;
        case 13:
            return 4;
        case 14:
            return 6;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 6;
        case 18:
            return 5;
        case 19:
            return 4;
        default:
            return 0;
        }
    }

// The hit dice num cells (the ranged cells read the low end - the kuei
// precedent; the diakk or-form reads the broad max)
inline int mm2dnDinoStatHd(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 10;
        case 5:
            return 4;
        case 6:
            return 8;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 11;
        case 10:
            return 18;
        case 11:
            return 7;
        case 12:
            return 14;
        case 13:
            return 2;
        case 14:
            return 7;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 10;
        default:
            return 0;
        }
    }

// The hit dice bonus points (the compsognathus minus-1 rides here)
inline int mm2dnDinoStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
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
            return 7;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 6;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The book-average hit points (the floor(num x 3.5) + bonus formula)
inline int mm2dnDinoStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 7;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 35;
        case 5:
            return 15;
        case 6:
            return 30;
        case 7:
            return 10;
        case 8:
            return 4;
        case 9:
            return 38;
        case 10:
            return 63;
        case 11:
            return 24;
        case 12:
            return 49;
        case 13:
            return 7;
        case 14:
            return 31;
        case 15:
            return 9;
        case 16:
            return 27;
        case 17:
            return 24;
        case 18:
            return 27;
        case 19:
            return 35;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the camptosaurus printed 0 clamps
// to 1, the nothosaurus 1-and-2 sums to 3, the tennodontosaurus 1-and-1 sums
// to 2, the diakk 1-or-2 reads the max 2)
inline int mm2dnDinoStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 2;
        default:
            return 0;
        }
    }

// The base xp cells (the printed xp before the per-hit-point add)
inline int mm2dnDinoStatXp(int b)
    {
        switch (b) {
        case 0:
            return 1300;
        case 1:
            return 20;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 900;
        case 5:
            return 130;
        case 6:
            return 600;
        case 7:
            return 65;
        case 8:
            return 20;
        case 9:
            return 2000;
        case 10:
            return 3000;
        case 11:
            return 225;
        case 12:
            return 1800;
        case 13:
            return 20;
        case 14:
            return 600;
        case 15:
            return 35;
        case 16:
            return 350;
        case 17:
            return 225;
        case 18:
            return 375;
        case 19:
            return 1500;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the nothosaurus 18 settled read)
inline int mm2dnDinoStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 14;
        case 5:
            return 5;
        case 6:
            return 12;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 16;
        case 10:
            return 25;
        case 11:
            return 8;
        case 12:
            return 18;
        case 13:
            return 2;
        case 14:
            return 10;
        case 15:
            return 3;
        case 16:
            return 8;
        case 17:
            return 8;
        case 18:
            return 10;
        case 19:
            return 14;
        default:
            return 0;
        }
    }

// The percent in lair cells (the diakk 25, every dinosaur Nil reads 0)
inline int mm2dnDinoStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 25;
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
        default:
            return 0;
        }
    }

// The primary move cells in print inches (the first number of the print move
// line, the parseIntRange floor)
inline int mm2dnDinoStatMove(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 9;
        case 5:
            return 21;
        case 6:
            return 18;
        case 7:
            return 12;
        case 8:
            return 15;
        case 9:
            return 9;
        case 10:
            return 6;
        case 11:
            return 15;
        case 12:
            return 3;
        case 13:
            return 24;
        case 14:
            return 15;
        case 15:
            return 21;
        case 16:
            return 3;
        case 17:
            return 18;
        case 18:
            return 6;
        case 19:
            return 24;
        default:
            return 0;
        }
    }

// The magic resistance cells (the diakk 30; every dinosaur Standard reads 0)
inline int mm2dnDinoStatMr(int b)
    {
        switch (b) {
        case 0:
            return 30;
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
        default:
            return 0;
        }
    }

// ---- the diakk pins (the R802 MM2 letter D part 4) ----

// The Diakk full kill xp value (the xpValue formula: 1300 + 12 x 36)
inline int mm2dnDiakkXpValue()
    { return 1732; }

// The Diakk printed LEVEL cell reads VII (1300 + 12/hp)
inline int mm2dnDiakkXpLevel()
    { return 7; }

// ---- the ankisaurus pins (the R802 MM2 letter D part 4) ----

// The Ankisaurus full kill xp value (the xpValue formula: 20 + 2 x 7)
inline int mm2dnAnkisaurusXpValue()
    { return 34; }

// The Ankisaurus printed LEVEL cell reads I (20 + 2/hp)
inline int mm2dnAnkisaurusXpLevel()
    { return 1; }

// The ankisaurus climbs nearby vegetation to escape small predators
inline bool mm2dnAnkisaurusClimbsToEscape()
    { return true; }

// ---- the camptosaurus pins (the R802 MM2 letter D part 4) ----

// The Camptosaurus full kill xp value (the xpValue formula: 5 + 1 x 3)
inline int mm2dnCamptosaurusXpValue()
    { return 8; }

// The Camptosaurus printed LEVEL cell reads II (5 + 1/hp)
inline int mm2dnCamptosaurusXpLevel()
    { return 2; }

// The camptosaurus herd stampedes at the 18 inch rate
inline int mm2dnCamptosaurusStampedeRate()
    { return 18; }

// The camptosaurus hit dice range reads 1-3; the def carries the low end (the
// kuei precedent, the R802 settled read)
inline int mm2dnCamptosaurusHitDiceRangeLow()
    { return 1; }

// The camptosaurus hit dice range high end (1-3)
inline int mm2dnCamptosaurusHitDiceRangeHigh()
    { return 3; }

// Anyone caught in a camptosaurus stampede must save vs. death ray or be
// crushed to death
inline bool mm2dnCamptosaurusStampedeSaveVsDeathRay()
    { return true; }

// ---- the compsognathus pins (the R802 MM2 letter D part 4) ----

// The Compsognathus full kill xp value (the xpValue formula: 5 + 1 x 2)
inline int mm2dnCompsognathusXpValue()
    { return 7; }

// The Compsognathus printed LEVEL cell reads I (5 + 1/hp)
inline int mm2dnCompsognathusXpLevel()
    { return 1; }

// The compsognathus surprise roll minimum: 1 to 3 on 1d6
inline int mm2dnCompsognathusSurpriseMin()
    { return 1; }

// The compsognathus surprise roll maximum: 1 to 3 on 1d6
inline int mm2dnCompsognathusSurpriseMax()
    { return 3; }

// The compsognathus tends to be nocturnal; attacks at night might occur on
// sleeping prey
inline bool mm2dnCompsognathusNocturnal()
    { return true; }

// ---- the dacentrurus pins (the R802 MM2 letter D part 4) ----

// The Dacentrurus full kill xp value (the xpValue formula: 900 + 14 x 35)
inline int mm2dnDacentrurusXpValue()
    { return 1390; }

// The Dacentrurus printed LEVEL cell reads VI (900 + 14/hp)
inline int mm2dnDacentrurusXpLevel()
    { return 6; }

// The dacentrurus active defense gives it a 75% probability of armor class 3
inline int mm2dnDacentrurusAcThreePct()
    { return 75; }

// Attackers striking the neck, back, or tail are 25% likely to stand a
// counterattack
inline int mm2dnDacentrurusNeckCounterPct()
    { return 25; }

// The dacentrurus counterattack damage: 1-8 points
inline int mm2dnDacentrurusNeckDamageMax()
    { return 8; }

// ---- the deinonychus pins (the R802 MM2 letter D part 4) ----

// The Deinonychus full kill xp value (the xpValue formula: 130 + 5 x 15)
inline int mm2dnDeinonychusXpValue()
    { return 205; }

// The Deinonychus printed LEVEL cell reads III (130 + 5/hp)
inline int mm2dnDeinonychusXpLevel()
    { return 3; }

// The deinonychus jumping rear talon attack is at +2 to hit
inline int mm2dnDeinonychusTalonToHitBonus()
    { return 2; }

// The gutting talon damage low end (2-12)
inline int mm2dnDeinonychusTalonDamageMin()
    { return 2; }

// The gutting talon damage high end (2-12)
inline int mm2dnDeinonychusTalonDamageMax()
    { return 12; }

// ---- the dilophosaurus pins (the R802 MM2 letter D part 4) ----

// The Dilophosaurus full kill xp value (the xpValue formula: 600 + 12 x 30)
inline int mm2dnDilophosaurusXpValue()
    { return 960; }

// The Dilophosaurus printed LEVEL cell reads VI (600 + 12/hp)
inline int mm2dnDilophosaurusXpLevel()
    { return 6; }

// The dilophosaurus prefers open areas to jungle and seldom ventures into
// thick trees
inline bool mm2dnDilophosaurusPrefersOpenAreas()
    { return true; }

// ---- the dimetrodon pins (the R802 MM2 letter D part 4) ----

// The Dimetrodon full kill xp value (the xpValue formula: 65 + 4 x 10)
inline int mm2dnDimetrodonXpValue()
    { return 105; }

// The Dimetrodon printed LEVEL cell reads III (65 + 4/hp)
inline int mm2dnDimetrodonXpLevel()
    { return 3; }

// The dimetrodon hit dice range reads 3 to 5; the def carries the low end
// (the kuei precedent, the R802 settled read)
inline int mm2dnDimetrodonHitDiceRangeLow()
    { return 3; }

// The dimetrodon hit dice range high end (3 to 5)
inline int mm2dnDimetrodonHitDiceRangeHigh()
    { return 5; }

// The dimetrodon ability to swim is questionable but likely
inline bool mm2dnDimetrodonSwimQuestionable()
    { return true; }

// ---- the euparkeria pins (the R802 MM2 letter D part 4) ----

// The Euparkeria full kill xp value (the xpValue formula: 20 + 2 x 4)
inline int mm2dnEuparkeriaXpValue()
    { return 28; }

// The Euparkeria printed LEVEL cell reads I (20 + 2/hp)
inline int mm2dnEuparkeriaXpLevel()
    { return 1; }

// A euparkeria pack attacks a single man-sized figure only if 3 or more are
// present
inline int mm2dnEuparkeriaManSizePackMinimum()
    { return 3; }

// ---- the kentrosaurus pins (the R802 MM2 letter D part 4) ----

// The Kentrosaurus full kill xp value (the xpValue formula: 2000 + 16 x 38)
inline int mm2dnKentrosaurusXpValue()
    { return 2608; }

// The Kentrosaurus printed LEVEL cell reads VII (2000 + 16/hp)
inline int mm2dnKentrosaurusXpLevel()
    { return 7; }

// The kentrosaurus is 80% likely to defend at armor class 2
inline int mm2dnKentrosaurusAcTwoPct()
    { return 80; }

// Creatures attacking the kentrosaurus rear third have a 25% chance of
// suffering an attack
inline int mm2dnKentrosaurusRearAttackPct()
    { return 25; }

// The kentrosaurus rear attack damage: 1-8 points
inline int mm2dnKentrosaurusRearDamageMax()
    { return 8; }

// ---- the mamenchisaurus pins (the R802 MM2 letter D part 4) ----

// The Mamenchisaurus full kill xp value (the xpValue formula: 3000 + 25 x 63)
inline int mm2dnMamenchisaurusXpValue()
    { return 4575; }

// The Mamenchisaurus printed LEVEL cell reads VII (3000 + 25/hp)
inline int mm2dnMamenchisaurusXpLevel()
    { return 7; }

// The mamenchisaurus neck is 35 feet long
inline int mm2dnMamenchisaurusNeckFeet()
    { return 35; }

// The mamenchisaurus trample damage low end (3-24)
inline int mm2dnMamenchisaurusTrampleDamageMin()
    { return 3; }

// The mamenchisaurus trample damage high end (3-24)
inline int mm2dnMamenchisaurusTrampleDamageMax()
    { return 24; }

// ---- the massopondylus pins (the R802 MM2 letter D part 4) ----

// The Massopondylus full kill xp value (the xpValue formula: 225 + 8 x 24)
inline int mm2dnMassopondylusXpValue()
    { return 417; }

// The Massopondylus printed LEVEL cell reads IV (225 + 8/hp)
inline int mm2dnMassopondylusXpLevel()
    { return 4; }

// The massopondylus delivers swift bites and then runs away
inline bool mm2dnMassopondylusBitesThenRunsAway()
    { return true; }

// ---- the nothosaurus pins (the R802 MM2 letter D part 4) ----

// The Nothosaurus full kill xp value (the xpValue formula: 1800 + 18 x 49)
inline int mm2dnNothosaurusXpValue()
    { return 2682; }

// The Nothosaurus printed LEVEL cell reads VII (1800 + 18/hp)
inline int mm2dnNothosaurusXpLevel()
    { return 7; }

// The nothosaurus xp per hit point reads 18 (the transcription 12 is its own
// annotation error; the capture and the djvu agree on 18, consistent with the
// xp ladder)
inline int mm2dnNothosaurusXpPerHp()
    { return 18; }

// The nothosaurus frenzy foreflipper lash causes damage only to soft-skinned
// or small creatures
inline bool mm2dnNothosaurusFrenzyFlippersSoft()
    { return true; }

// ---- the ornitholestes pins (the R802 MM2 letter D part 4) ----

// The Ornitholestes full kill xp value (the xpValue formula: 20 + 2 x 7)
inline int mm2dnOrnitholestesXpValue()
    { return 34; }

// The Ornitholestes printed LEVEL cell reads I (20 + 2/hp)
inline int mm2dnOrnitholestesXpLevel()
    { return 1; }

// The ornitholestes attacks larger creatures only if it significantly
// outnumbers the victims and is sufficiently hungry
inline bool mm2dnOrnitholestesOutnumberToAttack()
    { return true; }

// ---- the phororhacos pins (the R802 MM2 letter D part 4) ----

// The Phororhacos full kill xp value (the xpValue formula: 600 + 10 x 31)
inline int mm2dnPhororhacosXpValue()
    { return 910; }

// The Phororhacos printed LEVEL cell reads VI (600 + 10/hp)
inline int mm2dnPhororhacosXpLevel()
    { return 6; }

// The phororhacos jumping claw damage low end (2-8/2-8 double)
inline int mm2dnPhororhacosJumpClawDamageMin()
    { return 2; }

// The phororhacos jumping claw damage high end (2-8/2-8 double)
inline int mm2dnPhororhacosJumpClawDamageMax()
    { return 8; }

// The phororhacos will always jump to attack initially
inline bool mm2dnPhororhacosAlwaysJumpsInitially()
    { return true; }

// ---- the podokesaurus pins (the R802 MM2 letter D part 4) ----

// The Podokesaurus full kill xp value (the xpValue formula: 35 + 3 x 9)
inline int mm2dnPodokesaurusXpValue()
    { return 62; }

// The Podokesaurus printed LEVEL cell reads III (35 + 3/hp)
inline int mm2dnPodokesaurusXpLevel()
    { return 3; }

// The print gives the podokesaurus no descriptive prose: its paragraph prints
// under the struthiomimus block (the print quirk, pinned verbatim; the
// capture, the djvu and the transcription all agree)
inline bool mm2dnPodokesaurusPrintsNoProse()
    { return true; }

// ---- the giant pterosaur pins (the R802 MM2 letter D part 4) ----

// The Pterosaur, Giant full kill xp value (the xpValue formula: 350 + 8 x 27)
inline int mm2dnGiantPterosaurXpValue()
    { return 566; }

// The Pterosaur, Giant printed LEVEL cell reads V (350 + 8/hp)
inline int mm2dnGiantPterosaurXpLevel()
    { return 5; }

// The giant pterosaur diving attack surprises 3 in 6
inline int mm2dnPterosaurDiveSurpriseOnD6()
    { return 3; }

// The print reads: its chance to hit is 4 (the print wording, pinned
// verbatim)
inline int mm2dnPterosaurSwoopChanceToHit()
    { return 4; }

// The pterosaur can carry prey of 3 times its weight (low end)
inline int mm2dnPterosaurCarryMultipleMin()
    { return 3; }

// The pterosaur can carry prey of 4 times its weight (high end)
inline int mm2dnPterosaurCarryMultipleMax()
    { return 4; }

// The pterosaur weighs only about 75 pounds
inline int mm2dnPterosaurWeightPounds()
    { return 75; }

// The surprised pterosaur has swooped at double speed and inflicts double
// damage
inline bool mm2dnPterosaurSwoopDoubleDamage()
    { return true; }

// ---- the struthiomimus pins (the R802 MM2 letter D part 4) ----

// The Struthiomimus full kill xp value (the xpValue formula: 225 + 8 x 24)
inline int mm2dnStruthiomimusXpValue()
    { return 417; }

// The Struthiomimus printed LEVEL cell reads IV (225 + 8/hp)
inline int mm2dnStruthiomimusXpLevel()
    { return 4; }

// The struthiomimus tail damage low end (2-8; the transcription 1-8 is its
// own error - the capture and the djvu print 2-8)
inline int mm2dnStruthiomimusTailDamageMin()
    { return 2; }

// The struthiomimus tail damage high end (2-8, the settled read)
inline int mm2dnStruthiomimusTailDamageMax()
    { return 8; }

// ---- the tanystropheus pins (the R802 MM2 letter D part 4) ----

// The Tanystropheus full kill xp value (the xpValue formula: 375 + 10 x 27)
inline int mm2dnTanystropheusXpValue()
    { return 645; }

// The Tanystropheus printed LEVEL cell reads V (375 + 10/hp)
inline int mm2dnTanystropheusXpLevel()
    { return 5; }

// The tanystropheus surprises 5 in 6
inline int mm2dnTanystropheusSurpriseOnD6()
    { return 5; }

// The tanystropheus surprise strike is at +2 to hit
inline int mm2dnTanystropheusSurpriseToHitBonus()
    { return 2; }

// The tanystropheus drags victims under 500 pounds into the water
inline int mm2dnTanystropheusDragUnderPounds()
    { return 500; }

// ---- the tennodontosaurus pins (the R802 MM2 letter D part 4) ----

// The Tennodontosaurus full kill xp value (the xpValue formula: 1500 + 14 x
// 35)
inline int mm2dnTennodontosaurusXpValue()
    { return 1990; }

// The Tennodontosaurus printed LEVEL cell reads VII (1500 + 14/hp)
inline int mm2dnTennodontosaurusXpLevel()
    { return 7; }

// A second tennodontosaurus appears 10% of the time (1 with 10% for 2)
inline int mm2dnTennodontosaurusSecondChancePct()
    { return 10; }

// The tennodontosaurus frenzy tail damage low end (2-12)
inline int mm2dnTennodontosaurusTailDamageMin()
    { return 2; }

// The tennodontosaurus frenzy tail damage high end (2-12)
inline int mm2dnTennodontosaurusTailDamageMax()
    { return 12; }

}   // namespace rules
