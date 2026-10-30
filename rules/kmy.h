// =========================================================================================
// Adnd1 - rules/kmy.h
// The Dragon issue-13 opener part two - The Japanese Mythos by Jerome
// Arkenberg (folios 11-15): the direct sibling of the R920 Persian Mythos
// chain, GD&H-compatible
// census 845 -> 846.
//
// Pinned from The Dragon Vol. II No. 7 (April 1978), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 13;
// the source lives in the archive.org item accessory-dragon-magazine-012,
// file Accessory - Dragon Magazine #013_djvu.xml). PRINT FOLIO = PDF PAGE,
// verified at the TOC alignments (the Japanese Mythos at 11, the silly songs
// at 16-17). The transcripts ride extract/dragon/013/p011 through p015,
// landed at R922; the article CHAIN is the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: the sixteen see-below
// magic cells of the Shinto and Luck gods and the Yuki-Onna ride the -1
// sentinel with the census; the Aizen-Myoo and Light-of-Fire and
// Shade-of-Fire armor-class cells print bar garbles and ride the sentinel,
// and the Ryujin armor class minus 1 pins as the kmyRyujinAc const with the
// grid cell riding the sentinel, the genuine clean value colliding with the
// sentinel mark; the hero strength cells print fraction garbles - Kintaro
// 1899 (18/99), Raiko 1850 (18/50), Tawara Toda 1865 (18/65), Benkei 1860
// (18/60), Yoshitsune 1875 (18/75), Yoshi-Iye 1880 (18/80), Tametomo 1845
// (18/45) - all riding the sentinel with the census, the clean stats pinning
// clean; the Shaka-Nyorai and Kobo Daishi fighter cells print the Sth garble
// (the 5 of 5th lost to the print), pinned 5 noted as scanned; the Nil magic
// and psionic cells pin zero; the Kannon-Bosatsu move prints 14 without the
// inch mark, noted as scanned; the Wizard-versus-Patriarch magic split rides
// the column comments; the eleven prose-only Other Shinto Gods ride the
// transcript. The one-visual-check precedent of R919 (the full-res scan plus
// the djvu word geometry) stands for any future cell dispute.
//
namespace rules {

// ---- the gods and goddesses (folios 11-12) ----

// the Japanese Mythos god grid - twenty-seven rows: the nine Shinto gods, the
// Seven Gods of Luck and the eleven Buddhist deities (folios 11-12)
inline int kmyGodRows()
    { return 27; }

// the nine Shinto gods with stat blocks - Amaterasu, Tsukiyomi, Susano,
// Izanagi and Izanami, Ryujin, Hachiman, Inari, Kwannon and Suka-Na-Biko or
// Momotaro (folios 11)
inline int kmyShintoGods()
    { return 9; }

// the Seven Gods of Luck - Hotei, Jurojin, Fukurokujo, Bishamon, Daikoku,
// Ebisu and Benten, six of them on the common 7th-level block with Bishamon
// the Lord 10th exception (folios 11-12)
inline int kmySevenGodsOfLuck()
    { return 7; }

// the eleven Buddhist deities - Shaka-Nyorai, Yakushi-Nyorai, Amida-Nyorai,
// Dainichi-Nyorai, Miroku-Bosatsu, Kannon-Bosatsu, Monju-Bosatsu,
// Fugen-Bosatsu, Jizo-Bosatsu, Fudo-Myoo and Aizen-Myoo (folio 12)
inline int kmyBuddhistGods()
    { return 11; }

// the eleven prose-only Other Shinto Gods - Fujin, Kosensei, Oh-Kuni-Nushi,
// Raiden, Shi-Tenno, Shoki, Tenjin, Uke-Mochi, Umi-Bozo, Uzume and Yama-Uba,
// riding the transcript, never stat blocks (folios 12-13)
inline int kmyOtherShintoGods()
    { return 11; }

// the Ryujin armor class minus 1 pins as a const with the grid cell riding
// the sentinel, the genuine clean value colliding with the -1 sentinel mark,
// the Yig-split precedent of R920 (folio 11)
inline int kmyRyujinAc()
    { return -1; }

// Susano the Storm God carries two jewels, one producing hail and the other
// lightning (folio 11)
inline int kmySusanoJewels()
    { return 2; }

// Hachiman's sword is +3 to hit (folio 11)
inline int kmyHachimanSwordPlus()
    { return 3; }

// the Hachiman sword does 24-48 points of damage, the floor (folio 11)
inline int kmyHachimanSwordDamageMin()
    { return 24; }

// the Hachiman sword damage ceiling, 24-48 (folio 11)
inline int kmyHachimanSwordDamageMax()
    { return 48; }

// the Hachiman magical arrows do 7-12 points of damage, the floor (folio 11)
inline int kmyHachimanArrowDamageMin()
    { return 7; }

// the Hachiman arrow damage ceiling, 7-12 (folio 11)
inline int kmyHachimanArrowDamageMax()
    { return 12; }

// Japanese mythology is a mixture of Buddhism and Shinto, the pantheons
// partly integrated since the late 6th Century (folio 11)
inline bool kmyShintoBuddhistMixture()
    { return true; }

// Shinto holds that everything mineral, animal and vegetable has its own kami
// or spirit (folio 11)
inline bool kmyKamiInAllThings()
    { return true; }

// the two Susano jewels produce hail and lightning (folio 11)
inline bool kmySusanoJewelsOfHailAndLightning()
    { return true; }

// Hachiman's magical arrows never miss (folio 11)
inline bool kmyHachimanArrowsNeverMiss()
    { return true; }

// the fox is the messenger of Inari, who appears as a woman and a fox as well
// as a bearded man (folio 11)
inline bool kmyInariFoxMessenger()
    { return true; }

// the armor class - Amaterasu, Tsukiyomi and Susano minus 2, Ryujin minus 1,
// Izanagi and Izanami, Hachiman and the Luck gods 2, Kwannon 0, Suka-Na-Biko
// 3, the Buddhist deities 0 through 4; the Aizen-Myoo cell prints the bar
// garble and rides the sentinel, and the Ryujin cell rides the sentinel with
// the genuine minus 1 pinning as the kmyRyujinAc const, the collision noted
// (folios 11-12)
inline int kmyGodAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return 2;
        case 4:
            return -1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 2;
        case 26:
            return -1;
        default:
            return -1;
        }
    }

// the move in inches - the Shinto trio 18, Izanagi and Izanami, Hachiman,
// Monju, Fugen and Jizo 12, Ryujin, Inari and the Luck gods 15, Kwannon 16,
// Suka-Na-Biko 10, the Buddhist deities 14 except Monju, Fugen and Jizo 12;
// the Kannon-Bosatsu cell prints 14 without the inch mark, noted as scanned
// (folios 11-12)
inline int kmyGodMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 10;
        case 9:
            return 15;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 15;
        case 16:
            return 14;
        case 17:
            return 14;
        case 18:
            return 14;
        case 19:
            return 14;
        case 20:
            return 14;
        case 21:
            return 14;
        case 22:
            return 12;
        case 23:
            return 12;
        case 24:
            return 12;
        case 25:
            return 14;
        case 26:
            return 14;
        default:
            return -1;
        }
    }

// the hit points - Amaterasu 300, Tsukiyomi 275, Susano 290, Izanagi and
// Izanami 200, Ryujin 250, Hachiman 200, Inari and Kwannon 175, Suka-Na-Biko
// 175, the Luck gods 150, the Buddhist deities 275 through 200 with Dainichi
// 300 (folios 11-12)
inline int kmyGodHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 275;
        case 2:
            return 290;
        case 3:
            return 200;
        case 4:
            return 250;
        case 5:
            return 200;
        case 6:
            return 175;
        case 7:
            return 175;
        case 8:
            return 175;
        case 9:
            return 150;
        case 10:
            return 150;
        case 11:
            return 150;
        case 12:
            return 150;
        case 13:
            return 150;
        case 14:
            return 150;
        case 15:
            return 150;
        case 16:
            return 275;
        case 17:
            return 275;
        case 18:
            return 275;
        case 19:
            return 300;
        case 20:
            return 275;
        case 21:
            return 225;
        case 22:
            return 225;
        case 23:
            return 225;
        case 24:
            return 225;
        case 25:
            return 225;
        case 26:
            return 200;
        default:
            return -1;
        }
    }

// the magic level - the sixteen Shinto and Luck god cells print See Below and
// ride the sentinel; the Buddhist deities print Patriarch levels pinning
// clean - Shaka 20th, Yakushi 15th, Amida 17th, Dainichi 23rd, Miroku and
// Kannon 10th, Monju, Fugen and Jizo 9th, Fudo 13th, Aizen-Myoo 14th (folios
// 11-12)
inline int kmyGodMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return -1;
        case 11:
            return -1;
        case 12:
            return -1;
        case 13:
            return -1;
        case 14:
            return -1;
        case 15:
            return -1;
        case 16:
            return 20;
        case 17:
            return 15;
        case 18:
            return 17;
        case 19:
            return 23;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 9;
        case 23:
            return 9;
        case 24:
            return 9;
        case 25:
            return 13;
        case 26:
            return 14;
        default:
            return -1;
        }
    }

// the fighter level - the Shinto trio Lord 15th, Izanagi and Izanami, Inari
// and Bishamon Lord 10th, Hachiman Lord 15th, Kwannon and the Luck gods 7th
// except Bishamon, Suka-Na-Biko Lord 12th, the Buddhist deities 4th through
// 12th; the Shaka-Nyorai cell prints the Sth garble (the 5 of 5th lost to the
// print) and pins 5 noted as scanned (folios 11-12)
inline int kmyGodFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 15;
        case 6:
            return 10;
        case 7:
            return 7;
        case 8:
            return 12;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 6;
        case 20:
            return 5;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 12;
        case 26:
            return 7;
        default:
            return -1;
        }
    }

// the psionic class - the Shinto and Luck gods Class 6, Shaka and Amida Class
// 1, Yakushi Class 2, Dainichi Class 6, Miroku, Kannon, Monju, Fugen and Jizo
// Class 4, Fudo Class 5, Aizen-Myoo Class 2 (folios 11-12)
inline int kmyGodPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 6;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 5;
        case 26:
            return 2;
        default:
            return -1;
        }
    }

// ---- the creatures (folio 13) ----

// the creature grid - four rows: the Kappa, the Tengu, the Oni and Yuki-Onna
// (folio 13)
inline int kmyCreatureRows()
    { return 4; }

// the Oni have three eyes, three toes and three fingers (folio 13)
inline int kmyOniEyes()
    { return 3; }

// the Kappa lose all their powers if the water in the head indentation is
// spilled (folio 13)
inline bool kmyKappaPowersNeedHeadWater()
    { return true; }

// the Kappa always keep a promise and are extremely polite, often bowing and
// thereby spilling the head water (folio 13)
inline bool kmyKappaAlwaysKeepsPromise()
    { return true; }

// a human challenged to single combat with a Kappa must accept (folio 13)
inline bool kmyKappaChallengeMustBeAccepted()
    { return true; }

// the Oni can fly but seldom do (folio 13)
inline bool kmyOniFlyButSeldomDo()
    { return true; }

// the Tengu live in colonies with a King Tengu and a messenger Tengu, good
// swordsmen and mischievous (folio 13)
inline bool kmyTenguColonyWithKing()
    { return true; }

// the Yuki-Onna appears in snowstorms to lull men to sleep and thus death
// (folio 13)
inline bool kmyYukiOnnaLullsToSleepDeath()
    { return true; }

// the armor class - the Kappa, Tengu and Oni 3, the Yuki-Onna 2 (folio 13)
inline int kmyCreatureAc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        default:
            return -1;
        }
    }

// the move in inches - the Kappa 10, the Tengu 14, the Oni 10, the Yuki-Onna
// 15 (folio 13)
inline int kmyCreatureMove(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 14;
        case 2:
            return 10;
        case 3:
            return 15;
        default:
            return -1;
        }
    }

// the hit points - the Kappa, Tengu and Oni 100, the Yuki-Onna 175 (folio 13)
inline int kmyCreatureHp(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        case 2:
            return 100;
        case 3:
            return 175;
        default:
            return -1;
        }
    }

// the magic level - the Kappa Wizard 14th, the Tengu and Oni Wizard 16th; the
// Yuki-Onna cell prints See Below and rides the sentinel (folio 13)
inline int kmyCreatureMagicLvl(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 16;
        case 2:
            return 16;
        case 3:
            return -1;
        default:
            return -1;
        }
    }

// the fighter level - the Kappa, Tengu and Oni Lord 10th, the Yuki-Onna 7th
// (folio 13)
inline int kmyCreatureFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 7;
        default:
            return -1;
        }
    }

// the psionic class - all four creatures Class 6 (folio 13)
inline int kmyCreaturePsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        default:
            return -1;
        }
    }

// ---- the heroes (folios 13-15) ----

// the hero grid - fourteen rows: Issun Boshi, Kintaro, Raiko, Tawara Toda,
// Benkei, Yoshitsune, Light-of-Fire and Shade-of-Fire, Yoshi-Iye, Kiyomori,
// Tametomo, Shotoku Daishi, En No Shokaku, Kobo Daishi and Nichiren (folios
// 13-15)
inline int kmyHeroRows()
    { return 14; }

// Benkei is 10 feet tall (folio 14)
inline int kmyBenkeiHeightFeet()
    { return 10; }

// Benkei has the strength of a hundred men (folio 14)
inline int kmyBenkeiStrengthOfMen()
    { return 100; }

// the Yoshi-Iye arrows are +2 to hit (folio 15)
inline int kmyYoshiiyeArrowPlus()
    { return 2; }

// the Tametomo arrows are +4 to hit (folio 15)
inline int kmyTametomoArrowPlus()
    { return 4; }

// Benkei has the strength of a hundred men and runs as fast as the wind
// (folio 14)
inline bool kmyBenkeiStrengthOfHundredMen()
    { return true; }

// Yoshitsune was the only swordsman to defeat Benkei (folio 14)
inline bool kmyYoshitsuneOnlyToDefeatBenkei()
    { return true; }

// Kiyomori was the head of the Taira clan, the arch-rivals of the Minamoto
// Clan (folio 15)
inline bool kmyKiyomoriTairaRivalOfMinamoto()
    { return true; }

// the armor class - Issun Boshi minus 2, the warrior heroes 2, the four holy
// men 9; the Light-of-Fire and Shade-of-Fire cell prints the bar garble and
// rides the sentinel (folios 13-15)
inline int kmyHeroAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return -1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 9;
        case 11:
            return 9;
        case 12:
            return 9;
        case 13:
            return 9;
        default:
            return -1;
        }
    }

// the move in inches - Issun Boshi 5, Benkei 14, the rest 12 (folios 13-15)
inline int kmyHeroMove(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 12;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 14;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        default:
            return -1;
        }
    }

// the hit points - Issun Boshi 50, Kintaro through Tametomo 80 except Benkei
// 100 and Yoshitsune 90, Shotoku Daishi 50, En No Shokaku 60, Kobo Daishi and
// Nichiren 70 (folios 13-15)
inline int kmyHeroHp(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 80;
        case 2:
            return 80;
        case 3:
            return 80;
        case 4:
            return 100;
        case 5:
            return 90;
        case 6:
            return 80;
        case 7:
            return 80;
        case 8:
            return 80;
        case 9:
            return 80;
        case 10:
            return 50;
        case 11:
            return 60;
        case 12:
            return 70;
        case 13:
            return 70;
        default:
            return -1;
        }
    }

// the magic level - the warrior heroes Nil as zero; Shotoku Daishi Patriarch
// 10th, En No Shokaku Wizard 12th, Kobo Daishi and Nichiren Patriarch 14th,
// the Wizard-versus-Patriarch split riding this comment (folios 14-15)
inline int kmyHeroMagicLvl(int b)
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
            return 10;
        case 11:
            return 12;
        case 12:
            return 14;
        case 13:
            return 14;
        default:
            return -1;
        }
    }

// the fighter level - Issun Boshi 7th, the warrior heroes 10th except Benkei
// 12th, Yoshitsune 11th and Yamamoto Date 11th, the holy men 4th except Kobo
// Daishi and Nichiren 5th; the Kobo Daishi cell prints the Sth garble (the 5
// of 5th lost to the print) and pins 5 noted as scanned (folios 13-15)
inline int kmyHeroFightLvl(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 12;
        case 5:
            return 11;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 5;
        default:
            return -1;
        }
    }

// the psionic class - every hero Nil as zero (folios 13-15)
inline int kmyHeroPsiClass(int b)
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
        default:
            return -1;
        }
    }

// the strength - Issun Boshi 12, Light-of-Fire and Shade-of-Fire 17, Kiyomori
// 18, Shotoku Daishi 8, En No Shokaku 7, Kobo Daishi 10, Nichiren 7; Kintaro
// prints 1899 (18/99), Raiko 1850 (18/50), Tawara Toda 1865 (18/65), Benkei
// 1860 (18/60), Yoshitsune 1875 (18/75), Yoshi-Iye 1880 (18/80) and Tametomo
// 1845 (18/45), all fraction garbles riding the sentinel as-scanned (folios
// 13-15)
inline int kmyHeroStr(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return 17;
        case 7:
            return -1;
        case 8:
            return 18;
        case 9:
            return -1;
        case 10:
            return 8;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 7;
        default:
            return -1;
        }
    }

// the intelligence - Issun Boshi 14, Kintaro 12, Raiko 17, Tawara Toda 14,
// Benkei 13, Yoshitsune 15, Light-of-Fire and Shade-of-Fire 14, Yoshi-Iye 12,
// Kiyomori 14, Tametomo 15, Shotoku Daishi 18, En No Shokaku 18, Kobo Daishi
// 17, Nichiren 15 (folios 13-15)
inline int kmyHeroInt(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 12;
        case 2:
            return 17;
        case 3:
            return 14;
        case 4:
            return 13;
        case 5:
            return 15;
        case 6:
            return 14;
        case 7:
            return 12;
        case 8:
            return 14;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 18;
        case 12:
            return 17;
        case 13:
            return 15;
        default:
            return -1;
        }
    }

// the wisdom - Issun Boshi 13, Kintaro 17, Raiko 13, Tawara Toda 12, Benkei
// 10, Yoshitsune 12, Light-of-Fire and Shade-of-Fire 14, Yoshi-Iye 12,
// Kiyomori 10, Tametomo 15, Shotoku Daishi 18, En No Shokaku 12, Kobo Daishi
// 18, Nichiren 18 (folios 13-15)
inline int kmyHeroWis(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 17;
        case 2:
            return 13;
        case 3:
            return 12;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 14;
        case 7:
            return 12;
        case 8:
            return 10;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 12;
        case 12:
            return 18;
        case 13:
            return 18;
        default:
            return -1;
        }
    }

// the constitution - Issun Boshi 18, Kintaro 15, Raiko 16, Tawara Toda 15,
// Benkei 17, Yoshitsune 17, Light-of-Fire and Shade-of-Fire 15, Yoshi-Iye 16,
// Kiyomori 15, Tametomo 16, Shotoku Daishi 14, En No Shokaku 14, Kobo Daishi
// 15, Nichiren 15 (folios 13-15)
inline int kmyHeroCon(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 15;
        case 2:
            return 16;
        case 3:
            return 15;
        case 4:
            return 17;
        case 5:
            return 17;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 14;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 15;
        default:
            return -1;
        }
    }

// the dexterity - Issun Boshi 18, Kintaro 16, Raiko 17, Tawara Toda 17,
// Benkei 17, Yoshitsune 18, Light-of-Fire and Shade-of-Fire 17, Yoshi-Iye 17,
// Kiyomori 17, Tametomo 18, Shotoku Daishi 10, En No Shokaku 17, Kobo Daishi
// 16, Nichiren 16 (folios 13-15)
inline int kmyHeroDex(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 16;
        case 2:
            return 17;
        case 3:
            return 17;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 17;
        case 8:
            return 17;
        case 9:
            return 18;
        case 10:
            return 10;
        case 11:
            return 17;
        case 12:
            return 16;
        case 13:
            return 16;
        default:
            return -1;
        }
    }

// the charisma - Issun Boshi 14, Kintaro 17, Raiko 15, Tawara Toda 15, Benkei
// 16, Yoshitsune 16, Light-of-Fire and Shade-of-Fire 17, Yoshi-Iye 15,
// Kiyomori 17, Tametomo 15, Shotoku Daishi 13, En No Shokaku 12, Kobo Daishi
// 16, Nichiren 12 (folios 13-15)
inline int kmyHeroCha(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 17;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 15;
        case 8:
            return 17;
        case 9:
            return 15;
        case 10:
            return 13;
        case 11:
            return 12;
        case 12:
            return 16;
        case 13:
            return 12;
        default:
            return -1;
        }
    }

// ---- the treasures (folio 15) ----

// the six treasures - the Tide Flowing and Tide Ebbing Jewels, the Jewels of
// Hail and Lightning, the Imperial Jewels, the Imperial Mirror, the Imperial
// Sword and the Sakaki tree (folio 15)
inline int kmyTreasures()
    { return 6; }

// the Tide Flowing and Tide Ebbing Jewels, both priceless, control the ebbing
// and flowing of the tide (folio 15)
inline bool kmyTideJewelsPriceless()
    { return true; }

// the Imperial Sword found in the tail of a Dragon by Susano is a Dancing
// Sword (folio 15)
inline bool kmyImperialSwordIsDancing()
    { return true; }

// the Imperial Sword fell into the Sea during the Battle of Dannoura and has
// never been found (folio 15)
inline bool kmyImperialSwordLostAtDannoura()
    { return true; }

// the Sakaki tree is sacred to Shinto, its branches required when calling
// upon the heroes of Japan (folio 15)
inline bool kmySakakiBranchesRequired()
    { return true; }

}   // namespace rules
