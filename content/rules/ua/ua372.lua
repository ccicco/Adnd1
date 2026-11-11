-- ua372: promoted from rules/ua/uafollowers.h (the The UA CAVALIER FOLLOWERS AND);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 372,
  "prefix" = "ua372",
  "banner" = {
      "title" = "The UA CAVALIER FOLLOWERS AND",
      "provenance" = "HENCHMEN (pp. 74-75) pins, R372: the cavalier follower tables and the henchman rules. The men-at-arms dice ladder (all d4, non-cumulative, no gain if the roll is not higher than the current count); the four equipment percentile rows (both outfits each, the medium warhorses at 91-00); the leader rules (a 5th-level fighter per 20 troops, a 6th per 60 with a 3rd-level lieutenant, no replacement if slain); the neutral-cause and evil-bandit reads with the 1 and 5 percent per level monster chances; the +3/+1 henchman bonus and the alignment type table; the retainer ladder - the Armiger / Scutifer start at 4th (Knight Errant), the Esquire at 6th (the prose's \"Knight (6th level)\" conflicts with the Cavaliers Table I grid's Knight at 5th - flagged), the Horseman herald and Lancer guard at 7th, the extra mounted man-at-arms at 8th, the Chevalier travel freedom at 9th; the paladin retainers. The seams ride the R368 title cells and the R371 armor costs (checked in the regtest audit, not here).",
    },
  "consts" = { {
      "name" = "uafolFollowersStartLevel",
      "value" = 4,
      "comment" = "---- the men-at-arms dice ---- The ladder starts at 4th (Knight Errant) and tops at 10th.",
    }, {
      "name" = "uafolFollowersTopLevel",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uafolEquipRowCount",
      "value" = 4,
      "comment" = "---- the equipment rows ---- Four percentile rows, each with two outfits; the 91-00 cavalry rides medium warhorses.",
    }, {
      "name" = "uafolRowOneJavelinCount",
      "value" = 3,
      "comment" = "01-50: light cavalry in ring mail and shield, 3 javelins, long sword and hand axe; or heavy infantry in scale mail, pole arm of choice and club.",
    }, {
      "name" = "uafolLeaderFighterLevel",
      "value" = 5,
      "comment" = "---- the leaders ---- For every 20 troops a 5th-level fighter follower/leader; for every 60 a 6th-level fighter leader plus a 3rd-level fighter lieutenant. Leaders slain are not replaced.",
    }, {
      "name" = "uafolLeaderTroopDenominator",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uafolSeniorLeaderLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uafolSeniorLeaderTroops",
      "value" = 60,
      "comment" = "",
    }, {
      "name" = "uafolLieutenantLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uafolEvilMonsterFollowerPctPerLevel",
      "value" = 1,
      "comment" = "The 1% per level chance an encountered intelligent monster of fewer hit dice and similar alignment becomes a follower; the 5% per level chance of cooperation.",
    }, {
      "name" = "uafolEvilMonsterCooperatePctPerLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uafolHenchmanBonusGood",
      "value" = 3,
      "comment" = "---- the henchmen ---- The Charisma Table count with a +3 bonus for good cavaliers, +1 for neutral or evil.",
    }, {
      "name" = "uafolHenchmanBonusOther",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uafolRetainerStartLevel",
      "value" = 4,
      "comment" = "---- the retainers ---- At 4th (Knight Errant) the good cavalier must acquire at least one retainer - Armigers (level 1) or Scutifers (level 2) or both.",
    }, {
      "name" = "uafolRetainerArmigerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uafolRetainerScutiferLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uafolEsquireLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uafolHeraldGuardLevel",
      "value" = 7,
      "comment" = "At 7th a Horseman herald and a Lancer guard are added; at 8th (Banneret) an extra mounted man-at-arms; at 9th (Chevalier) the cavalier may travel with or without retainers.",
    }, {
      "name" = "uafolExtraManAtArmsLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uafolChevalierTravelFreedomLevel",
      "value" = 9,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uafolDiceCumulative",
      "value" = false,
      "comment" = "The ranges are gained on a per-level basis - not cumulative.",
    }, {
      "name" = "uafolNoGainIfRollNotHigher",
      "value" = true,
      "comment" = "If the new roll is equal to or lower than the current number, no new followers are gained.",
    }, {
      "name" = "uafolRowOneLightCavRingMailShield",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolRowOneHeavyInfScalePoleArmClub",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolRowTwoSplintMorningStarHandAxe",
      "value" = true,
      "comment" = "51-75: heavy infantry in splint mail with morning star and hand axe; or heavy infantry in leather armor with pike and short sword.",
    }, {
      "name" = "uafolRowTwoLeatherPikeShortSword",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolRowThreeHeavyCrossbowShortSword",
      "value" = true,
      "comment" = "76-90: crossbowmen in chain mail with heavy crossbow and short sword; or crossbowmen in chain mail with light crossbow and military fork.",
    }, {
      "name" = "uafolRowThreeLightCrossbowMilitaryFork",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolRowFourBandedShieldLanceMace",
      "value" = true,
      "comment" = "91-00: cavalry in banded mail and shield with lance and horseman's mace; or cavalry in studded leather with long sword and horseman's flail.",
    }, {
      "name" = "uafolRowFourStuddedLeatherLongSwordFlail",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolLeadersNotReplacedIfSlain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolNeutralSpecificCause",
      "value" = true,
      "comment" = "---- the neutral and evil reads ---- Neutral cavaliers attract followers only for a specific, neutral cause; the followers leave if the cavalier goes elsewhere.",
    }, {
      "name" = "uafolNeutralLeaveIfElsewhere",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolEvilBanditsBrigands",
      "value" = true,
      "comment" = "Evil cavaliers attract only bandits and brigands (orcs or hobgoblins in the right area).",
    }, {
      "name" = "uafolHenchmanGoodPaladins",
      "value" = true,
      "comment" = "The alignment type table cells that differ from the plain lists: good accepts paladins, neutral accepts thieves, evil swaps in assassins.",
    }, {
      "name" = "uafolHenchmanNeutralThieves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolHenchmanEvilAssassins",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uafolRetainerKnightProseConflict",
      "value" = true,
      "comment" = "The prose: \"Upon becoming a Knight (6th level), an Esquire (level 3) must be added\" - but the Cavaliers Table I grid prints Knight at 5th, not 6th; the conflict is flagged here.",
    }, {
      "name" = "uafolRetainersServeForCareAndUpkeep",
      "value" = true,
      "comment" = "Retainers serve for care, upkeep and training; gifts always accepted.",
    }, {
      "name" = "uafolPaladinNoFollowers",
      "value" = true,
      "comment" = "---- the paladin retainers ----",
    }, {
      "name" = "uafolPaladinRetainersMustBeCavaliers",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uafolDiceCount",
      "comment" = "The dice counts: 1d4 at 4th, 2d4 at 5th, 3d4 at 6th, 6d4 at 7th, 12d4 at 8th, 24d4 at 9th and 48d4 at 10th. All sides are 4.",
      "kind" = "header pin",
      "body" = "if (level < 4) return 0; if (level > 10) return 0; static const int k[7] = { 1, 2, 3, 6, 12, 24, 48 }; return k[level - 4];",
    }, {
      "name" = "uafolDiceSides",
      "comment" = "",
      "kind" = "header pin",
      "body" = "if (level < 4 || level > 10) return 0; return 4;",
    }, {
      "name" = "uafolFollowersMin",
      "comment" = "The min is the count; the max is the count times four (the d4 invariant).",
      "kind" = "header pin",
      "body" = "return uafolDiceCount(level);",
    }, {
      "name" = "uafolFollowersMax",
      "comment" = "",
      "kind" = "header pin",
      "body" = "return 4 * uafolDiceCount(level);",
    }, {
      "name" = "uafolEquipRowLo",
      "comment" = "",
      "kind" = "header pin",
      "body" = "if (row < 0 || row > 3) return 0; static const int k[4] = { 1, 51, 76, 91 }; return k[row];",
    }, {
      "name" = "uafolEquipRowHi",
      "comment" = "",
      "kind" = "header pin",
      "body" = "if (row < 0 || row > 3) return 0; static const int k[4] = { 50, 75, 90, 100 }; return k[row];",
    }, {
      "name" = "uafolEquipRowIsCavalry",
      "comment" = "Rows 01-50 and 91-00 are cavalry; rows 51-75 and 76-90 are foot.",
      "kind" = "header pin",
      "body" = "return row == 0 || row == 3;",
    }, {
      "name" = "uafolEquipRowMediumWarhorse",
      "comment" = "Only the 91-00 cavalry rides medium warhorses.",
      "kind" = "header pin",
      "body" = "return row == 3;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uafolFollowersStartLevel']() != 4  or m['uafolFollowersTopLevel']() != 10  or m['uafolDiceSides'](4) != 4  or m['uafolDiceSides'](10) != 4  or m['uafolDiceSides'](3) != 0  or m['uafolDiceSides'](11) != 0  or m['uafolDiceCumulative']()  or  m['uafolNoGainIfRollNotHigher']() != 1  or m['uafolRowOneJavelinCount']() != 3  or  m['uafolRowOneLightCavRingMailShield']() != 1  or  m['uafolRowOneHeavyInfScalePoleArmClub']() != 1  or  m['uafolRowTwoSplintMorningStarHandAxe']() != 1  or  m['uafolRowTwoLeatherPikeShortSword']() != 1  or  m['uafolRowThreeHeavyCrossbowShortSword']() != 1  or  m['uafolRowThreeLightCrossbowMilitaryFork']() != 1  or  m['uafolRowFourBandedShieldLanceMace']() != 1  or  m['uafolRowFourStuddedLeatherLongSwordFlail']() != 1  or m['uafolLeaderFighterLevel']() != 5  or m['uafolLeaderTroopDenominator']() != 20  or m['uafolSeniorLeaderLevel']() != 6  or m['uafolSeniorLeaderTroops']() != 60  or m['uafolLieutenantLevel']() != 3  or  m['uafolLeadersNotReplacedIfSlain']() != 1  or  m['uafolNeutralSpecificCause']() != 1  or  m['uafolNeutralLeaveIfElsewhere']() != 1  or  m['uafolEvilBanditsBrigands']() != 1  or m['uafolEvilMonsterFollowerPctPerLevel']() != 1  or m['uafolEvilMonsterCooperatePctPerLevel']() != 5  or m['uafolHenchmanBonusGood']() != 3  or m['uafolHenchmanBonusOther']() != 1  or  m['uafolHenchmanGoodPaladins']() != 1  or  m['uafolHenchmanNeutralThieves']() != 1  or  m['uafolHenchmanEvilAssassins']() != 1  or m['uafolRetainerStartLevel']() != 4  or m['uafolRetainerArmigerLevel']() != 1  or m['uafolRetainerScutiferLevel']() != 2  or m['uafolEsquireLevel']() != 3  or  m['uafolRetainerKnightProseConflict']() != 1  or m['uafolHeraldGuardLevel']() != 7  or m['uafolExtraManAtArmsLevel']() != 8  or m['uafolChevalierTravelFreedomLevel']() != 9  or  m['uafolRetainersServeForCareAndUpkeep']() != 1  or  m['uafolPaladinNoFollowers']() != 1  or  m['uafolPaladinRetainersMustBeCavaliers']() != 1",
      "note" = "---- the pinned cells ----",
    }, {
      "expr" = "m['uafolDiceCount'](l) != kCnt[l]  or m['uafolFollowersMin'](l) != kCnt[l]  or m['uafolFollowersMax'](l) != 4 * kCnt[l]  or m['uafolDiceCount'](3) != 0  or m['uafolDiceCount'](11) != 0",
      "note" = "---- the dice ladder loops ----",
    }, {
      "expr" = "m['uafolEquipRowCount']() != 4  or m['uafolEquipRowLo'](r) != kLo[r]  or m['uafolEquipRowHi'](r) != kHi[r]  or r < 3 && kHi[r] + 1 != kLo[r + 1]  or m['uafolEquipRowIsCavalry'](r) != (r == 0  or r == 3)  or m['uafolEquipRowMediumWarhorse'](r) != (r == 3)  or m['uafolEquipRowLo'](0) != 1  or m['uafolEquipRowHi'](3) != 100",
      "note" = "---- the equipment rows ----",
    }, {
      "expr" = "m['uafolRetainerStartLevel']() >=m['uafolHeraldGuardLevel']()  or m['uafolHeraldGuardLevel']() >=m['uafolExtraManAtArmsLevel']()  or m['uafolExtraManAtArmsLevel']() >=m['uafolChevalierTravelFreedomLevel']()",
      "note" = "---- the retainer ladder order ----",
    }, {
      "expr" = "strcmp(m['uacavtTitle'](m['uafolRetainerStartLevel']()), \"Knight Errant\") != 0  or strcmp(m['uacavtTitle'](m['uafolHeraldGuardLevel']()), \"Grand Knight\") != 0  or strcmp(m['uacavtTitle'](m['uafolExtraManAtArmsLevel']()), \"Banneret\") != 0  or strcmp(m['uacavtTitle'](m['uafolChevalierTravelFreedomLevel']()), \"Chevalier\") != 0  or strcmp(m['uacavtTitle'](m['uafolRetainerArmigerLevel']()), \"Armiger\") != 0  or strcmp(m['uacavtTitle'](m['uafolRetainerScutiferLevel']()), \"Scutifer\") != 0  or strcmp(m['uacavtTitle'](m['uafolEsquireLevel']()), \"Esquire\") != 0  or strcmp(m['uacavtTitle'](0), \"Horseman\") != 0  or strcmp(m['uacavtTitle'](-1), \"Lancer\") != 0",
      "note" = "---- the R368 seam ----",
    }, {
      "expr" = "m['uaarmRingMailCost']() != 30  or m['uaarmScaleMailCost']() != 45  or m['uaarmSplintMailCost']() != 80  or m['uaarmBandedCost']() != 90  or m['uaarmStuddedLeatherCost']() != 15",
      "note" = "---- the R371 seam ----",
    } },
  "audit" = {
      "label" = "R372: the UA cavalier followers pin audit",
      "comment" = "The UA CAVALIER FOLLOWERS AND HENCHMEN (pp. 74-75): the men-at-arms dice ladder (all d4, 1d4 at 4th through 48d4 at 10th, non-cumulative, no gain if the roll is not higher than the current count), the four equipment percentile rows (the two outfits each, the medium warhorses at 91-00), the leader rules (the 5th-level fighter per 20 troops, the 6th per 60 with the 3rd-level lieutenant, no replacement if slain), the neutral-cause and evil-bandit reads with the 1 and 5 percent per level monster chances, the +3/+1 henchman bonus and the alignment type table, the retainer ladder (the prose Knight at 6th flagged against the R368 grid's Knight at 5th), the paladin rules; the R368 seam cross-checks the title and rank cells, the R371 seam the armor costs; two items flip CLOSED; the census 298 -> 299.",
    },
}
