-- oa635: promoted from rules/oaeff.h (the ALTERING FAMILY HONOR, THE EFFECTS OF HONOR AND TABLE 42, printed capture);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 635,
  "prefix" = "oa635",
  "banner" = {
      "title" = "ALTERING FAMILY HONOR, THE EFFECTS OF HONOR AND TABLE 42, printed capture",
      "provenance" = "pp. 70-72 - the OA effects of honor round census 557 -> 558.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T42 grid pins as 68 rows x 2 columns across the ten printed sections (all characters, shukenja, hengeyokai, kensai, ninja, samurai, sohei, spirit folk, wu jen, yakuza); the points column carries every printed award and the mark column codes the printed footnotes (0 unmarked, 1 the samurai-doubled star, 2 the single-creature double star). The two rate rows pin as per-unit consts - the monsters row -1 per 2000 experience points for a single creature, the yakuza stolen-goods row +1 per 100 ch'ien - with the base points in the grid. OCR normalization: the double-star footnote reads \"defeating a single-creature\" with a printed em dash (pins as single-creature); the awards use the printed x.p. abbreviation. The Chapter 5 Money and Equipment prose (capture pp. 73+) is deliberately left for the next rounds  the gap census after this round: 80 closed, 155 open - the Altering Family Honor, Effects of Honor prose, Table 42 and the Chapter 4 parent boxes flip (census 557 -> 558); NEXT - R636: the Chapter 5 Money and Equipment opener, the Currency prose with Table 43 (Currency Values) and Table 44 (Barter Units), capture pp. 73-75, prefix dgw (verify free), audit \"R636 OA money audit\", include after rules/oaeff.h",
    },
  "consts" = { {
      "name" = "dgvFamilyRaiseStep",
      "value" = 10,
      "comment" = "Altering family honor prose (capture p. 70): the character 10 points above the family honor raises the family base",
    }, {
      "name" = "dgvFamilyRaiseAmount",
      "value" = 1,
      "comment" = "Altering family honor prose (capture p. 70): the family base honor raise per step, also at 20, 30, 40 and so on",
    }, {
      "name" = "dgvFamilyLossThreshold",
      "value" = 5,
      "comment" = "Altering family honor prose (capture p. 70): the single-action loss that blots the family - five or more points",
    }, {
      "name" = "dgvFamilyLossAmount",
      "value" = 1,
      "comment" = "Altering family honor prose (capture p. 70): the family base honor loss for the blot",
    }, {
      "name" = "dgvBelowBaseModPct",
      "value" = -20,
      "comment" = "Effects of honor prose (capture pp. 71-72): the reaction modifier below the family or class base, -20 percent with the family members",
    }, {
      "name" = "dgvAboveBaseBonusPct",
      "value" = 5,
      "comment" = "Effects of honor prose (capture pp. 71-72): the reaction bonus per 10 points above the base, +5 percent",
    }, {
      "name" = "dgvGiftHonorPoints",
      "value" = 75,
      "comment" = "Effects of honor prose (capture pp. 71-72): the gift from a powerful lord at 75 honor points",
    }, {
      "name" = "dgvSongsHonorPoints",
      "value" = 80,
      "comment" = "Effects of honor prose (capture pp. 71-72): the songs and stories at 80 honor points",
    }, {
      "name" = "dgvServeHonorPoints",
      "value" = 90,
      "comment" = "Effects of honor prose (capture pp. 71-72): the invitation to serve a great lord at 90 honor points",
    }, {
      "name" = "dgvGreatHeroHonorPoints",
      "value" = 95,
      "comment" = "Effects of honor prose (capture pp. 71-72): the great hero at 95 honor points",
    }, {
      "name" = "dgvFoeBoastPct",
      "value" = 10,
      "comment" = "Effects of honor prose (capture pp. 71-72): the 10 percent weekly chance of the notorious foe boasting",
    }, {
      "name" = "dgvFoeRefuseHonorLoss",
      "value" = 10,
      "comment" = "Effects of honor prose (capture pp. 71-72): the honor loss for refusing to seek out the boasting foe",
    }, {
      "name" = "dgvServeRefusePct",
      "value" = -10,
      "comment" = "Effects of honor prose (capture pp. 71-72): the refusal penalty with the lord and his followers, -10 percent",
    }, {
      "name" = "dgvGreatHeroBonusPct",
      "value" = 10,
      "comment" = "Effects of honor prose (capture pp. 71-72): the +10 percent bonus with lesser rank, the -10 percent penalty with the opposite alignment",
    }, {
      "name" = "dgvSuccessorDivisor",
      "value" = 10,
      "comment" = "The final benefit prose (capture p. 72): the death-honor remainder divided by 10, fractions rounded down",
    }, {
      "name" = "dgvSuccessorMaxPerRoll",
      "value" = 3,
      "comment" = "The final benefit prose (capture p. 72): no more than three points on any single roll",
    }, {
      "name" = "dgvT42RowCount",
      "value" = 68,
      "comment" = "Table 42 (capture p. 72): sixty-eight honor-award rows",
    }, {
      "name" = "dgvMonsterXpPerPoint",
      "value" = 2000,
      "comment" = "T42 monsters row (capture p. 72): the honor loss per 2000 experience points, single creatures only",
    }, {
      "name" = "dgvStolenChienPerPoint",
      "value" = 100,
      "comment" = "T42 yakuza row (capture p. 72): the honor gain per 100 ch'ien of stolen goods",
    } },
  "bools" = { {
      "name" = "dgvClanFortunesFollow",
      "value" = true,
      "comment" = "Altering family honor prose (capture p. 70): noble, heroic and successful characters elevate the family name while craven, lying and treacherous characters drag it down",
    }, {
      "name" = "dgvRaiseOncePerGroup",
      "value" = true,
      "comment" = "Altering family honor prose (capture p. 70): the family raise is earned only once for each group of 10 points",
    }, {
      "name" = "dgvRaiseAtMaxHonor",
      "value" = true,
      "comment" = "Altering family honor prose (capture p. 70): the bonus can be earned even at the honor maximum - the character has reached his pinnacle but his deeds still reflect well upon the clan",
    }, {
      "name" = "dgvLossBlotsFamily",
      "value" = true,
      "comment" = "Altering family honor prose (capture p. 70): losing five or more points for a single action is a lasting blot on the family name",
    }, {
      "name" = "dgvFamilyShareChange",
      "value" = true,
      "comment" = "Altering family honor prose (capture p. 70): when a character changes the family honor, all other family members change by the same amount - family members affect each other",
    }, {
      "name" = "dgvEffectsAutomatic",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): the advantages and disadvantages automatically come into play as honor is gained and lost",
    }, {
      "name" = "dgvBelowZeroOut",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): honor below zero means the character is out of the game - the record sheet is crumpled up and tossed away",
    }, {
      "name" = "dgvSamuraiKensaiStatus",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): a samurai or kensai whose honor falls below the family base loses his status - the samurai becomes a ronin and the kensai is treated as a bushi",
    }, {
      "name" = "dgvBelowBaseFamilyMod",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): any class below the family honor or the class base takes the -20 percent family modifier until the honor again equals or exceeds the base",
    }, {
      "name" = "dgvHarderToImpress",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): every 10 points above the base gives the +5 percent bonus, but the family or group honor also rises - it becomes harder and harder to impress them",
    }, {
      "name" = "dgvGiftFromLord",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): the 75-point gift is appropriate to the level and class, never a threat to the lord, and the player character is expected to return the compliment",
    }, {
      "name" = "dgvSongsAndBoasts",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): at 80 points the name appears in songs and stories; the notorious foe boasts reach the character's ears automatically",
    }, {
      "name" = "dgvLordInvitation",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): at 90 points the character is invited to serve one of the most powerful lords - under no obligation, but refusal angers the lord",
    }, {
      "name" = "dgvGreatHeroRead",
      "value" = true,
      "comment" = "Effects of honor prose (capture pp. 71-72): at 95 points the great hero gains the +10 percent bonus with lesser rank and the -10 percent penalty with opposite alignment or belief - friends treat him with respect, enemies hate him more",
    }, {
      "name" = "dgvSuccessorBonus",
      "value" = true,
      "comment" = "The final benefit prose (capture p. 72): a character who dies and is not returned to play grants the next character bonus points - the death honor above the base, divided by 10 rounded down, added to ability or hit point dice rolls",
    }, {
      "name" = "dgvSuccessorLimits",
      "value" = true,
      "comment" = "The final benefit prose (capture p. 72): the bonus cannot raise a roll above the racial or class maximum and cannot be saved for later in the career",
    }, {
      "name" = "dgvSuccessorFreedom",
      "value" = true,
      "comment" = "The final benefit prose (capture p. 72): the created character can be of any race, class or family, meeting the ability requirements normally",
    }, {
      "name" = "dgvKensaiDuelOncePerLevel",
      "value" = true,
      "comment" = "T42 kensai prose (capture p. 72): duel awards are given only for fighting a particular NPC once per level - a second duel has no effect until the character advances",
    }, {
      "name" = "dgvSamuraiDoubleAwards",
      "value" = true,
      "comment" = "T42 footnote (capture p. 72): the starred awards are doubled for samurai characters",
    }, {
      "name" = "dgvSingleCreatureRead",
      "value" = true,
      "comment" = "T42 footnote (capture p. 72): the monsters award applies only to points earned for defeating a single creature",
    } },
  "switches" = { {
      "name" = "dgvT42Points",
      "values" = { -4, 1, 5, -5, -10, -4, 5, -10, 2, -1, -1, -2, 7, 1, 1, -10, -5, -1, -2, 1, 1, -3, -2, -2, -2, -2, 5, -2, -30, -1, -1, -1, -3, -1, 1, -3, -2, -5, -5, -1, 3, 1, 3, -10, -30, -5, -3, -10, 1, -1, -4, 3, -5, -10, -10, -3, -1, 1, -3, -1, -1, -10, -5, 2, -2, 5, -3, 1 },
      "default" = -99,
      "comment" = "the honor points column, by deed row - the sections run 0-29 all characters, 30-32 shukenja, 33-34 hengeyokai, 35-41 kensai, 42-45 ninja, 46-58 samurai, 59-61 sohei, 62 spirit folk, 63 wu jen, 64-67 yakuza (capture p. 72).",
    }, {
      "name" = "dgvT42Mark",
      "values" = { 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the mark column: 0 unmarked, 1 the samurai-doubled star, 2 the single-creature double star (capture p. 72).",
    } },
  "tables" = { {
      "name" = "dgvT42Grid",
      "tag" = "T42",
      "count" = "dgvT42RowCount",
      "sentinel" = -99,
      "cols" = { "dgvT42Points", "dgvT42Mark" },
      "data" = { { -4, 0 }, { 1, 0 }, { 5, 0 }, { -5, 0 }, { -10, 1 }, { -4, 1 }, { 5, 0 }, { -10, 0 }, { 2, 1 }, { -1, 0 }, { -1, 2 }, { -2, 0 }, { 7, 0 }, { 1, 0 }, { 1, 0 }, { -10, 0 }, { -5, 1 }, { -1, 0 }, { -2, 0 }, { 1, 0 }, { 1, 0 }, { -3, 0 }, { -2, 0 }, { -2, 0 }, { -2, 0 }, { -2, 0 }, { 5, 0 }, { -2, 1 }, { -30, 0 }, { -1, 0 }, { -1, 0 }, { -1, 0 }, { -3, 0 }, { -1, 0 }, { 1, 0 }, { -3, 0 }, { -2, 0 }, { -5, 0 }, { -5, 0 }, { -1, 0 }, { 3, 0 }, { 1, 0 }, { 3, 0 }, { -10, 0 }, { -30, 0 }, { -5, 0 }, { -3, 0 }, { -10, 0 }, { 1, 0 }, { -1, 0 }, { -4, 0 }, { 3, 0 }, { -5, 0 }, { -10, 0 }, { -10, 0 }, { -3, 0 }, { -1, 0 }, { 1, 0 }, { -3, 0 }, { -1, 0 }, { -1, 0 }, { -10, 0 }, { -5, 0 }, { 2, 0 }, { -2, 0 }, { 5, 0 }, { -3, 0 }, { 1, 0 } },
      "comment" = "the Table 42 honor awards grid (capture p. 72)",
      "col_comments" = { "the honor points column, by deed row - the sections run 0-29 all characters, 30-32 shukenja, 33-34 hengeyokai, 35-41 kensai, 42-45 ninja, 46-58 samurai, 59-61 sohei, 62 spirit folk, 63 wu jen, 64-67 yakuza (capture p. 72).", "the mark column: 0 unmarked, 1 the samurai-doubled star, 2 the single-creature double star (capture p. 72)." },
      "audit_comment" = "the Table 42 grid: the deed awards and the footnote marks (capture p. 72)",
      "sentinel_census" = { 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgvT42RowCount']() != 68  or m['dgvFamilyRaiseStep']() != 10  or m['dgvFamilyRaiseAmount']() != 1  or m['dgvFamilyLossThreshold']() != 5  or m['dgvFamilyLossAmount']() != 1  or m['dgvBelowBaseModPct']() != -20  or m['dgvAboveBaseBonusPct']() != 5  or m['dgvGiftHonorPoints']() != 75  or m['dgvSongsHonorPoints']() != 80  or m['dgvServeHonorPoints']() != 90  or m['dgvGreatHeroHonorPoints']() != 95  or m['dgvFoeBoastPct']() != 10  or m['dgvFoeRefuseHonorLoss']() != 10  or m['dgvServeRefusePct']() != -10  or m['dgvGreatHeroBonusPct']() != 10  or m['dgvSuccessorDivisor']() != 10  or m['dgvSuccessorMaxPerRoll']() != 3  or m['dgvMonsterXpPerPoint']() != 2000  or m['dgvStolenChienPerPoint']() != 100  or  m['dgvClanFortunesFollow']() != 1  or  m['dgvRaiseOncePerGroup']() != 1  or  m['dgvRaiseAtMaxHonor']() != 1  or  m['dgvLossBlotsFamily']() != 1  or  m['dgvFamilyShareChange']() != 1  or  m['dgvEffectsAutomatic']() != 1  or  m['dgvBelowZeroOut']() != 1  or  m['dgvSamuraiKensaiStatus']() != 1  or  m['dgvBelowBaseFamilyMod']() != 1  or  m['dgvHarderToImpress']() != 1  or  m['dgvGiftFromLord']() != 1  or  m['dgvSongsAndBoasts']() != 1  or  m['dgvLordInvitation']() != 1  or  m['dgvGreatHeroRead']() != 1  or  m['dgvSuccessorBonus']() != 1  or  m['dgvSuccessorLimits']() != 1  or  m['dgvSuccessorFreedom']() != 1  or  m['dgvKensaiDuelOncePerLevel']() != 1  or  m['dgvSamuraiDoubleAwards']() != 1  or  m['dgvSingleCreatureRead']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgvT42RowCount']() != 68",
      "note" = "the dgvT42RowCount pin",
    }, {
      "expr" = "m['dgvFamilyRaiseStep']() != 10",
      "note" = "the dgvFamilyRaiseStep pin",
    }, {
      "expr" = "m['dgvFamilyRaiseAmount']() != 1",
      "note" = "the dgvFamilyRaiseAmount pin",
    }, {
      "expr" = "m['dgvFamilyLossThreshold']() != 5",
      "note" = "the dgvFamilyLossThreshold pin",
    }, {
      "expr" = "m['dgvFamilyLossAmount']() != 1",
      "note" = "the dgvFamilyLossAmount pin",
    }, {
      "expr" = "m['dgvBelowBaseModPct']() != -20",
      "note" = "the dgvBelowBaseModPct pin",
    }, {
      "expr" = "m['dgvAboveBaseBonusPct']() != 5",
      "note" = "the dgvAboveBaseBonusPct pin",
    }, {
      "expr" = "m['dgvGiftHonorPoints']() != 75",
      "note" = "the dgvGiftHonorPoints pin",
    }, {
      "expr" = "m['dgvSongsHonorPoints']() != 80",
      "note" = "the dgvSongsHonorPoints pin",
    }, {
      "expr" = "m['dgvServeHonorPoints']() != 90",
      "note" = "the dgvServeHonorPoints pin",
    }, {
      "expr" = "m['dgvGreatHeroHonorPoints']() != 95",
      "note" = "the dgvGreatHeroHonorPoints pin",
    }, {
      "expr" = "m['dgvFoeBoastPct']() != 10",
      "note" = "the dgvFoeBoastPct pin",
    }, {
      "expr" = "m['dgvFoeRefuseHonorLoss']() != 10",
      "note" = "the dgvFoeRefuseHonorLoss pin",
    }, {
      "expr" = "m['dgvServeRefusePct']() != -10",
      "note" = "the dgvServeRefusePct pin",
    }, {
      "expr" = "m['dgvGreatHeroBonusPct']() != 10",
      "note" = "the dgvGreatHeroBonusPct pin",
    }, {
      "expr" = "m['dgvSuccessorDivisor']() != 10",
      "note" = "the dgvSuccessorDivisor pin",
    }, {
      "expr" = "m['dgvSuccessorMaxPerRoll']() != 3",
      "note" = "the dgvSuccessorMaxPerRoll pin",
    }, {
      "expr" = "m['dgvMonsterXpPerPoint']() != 2000",
      "note" = "the dgvMonsterXpPerPoint pin",
    }, {
      "expr" = "m['dgvStolenChienPerPoint']() != 100",
      "note" = "the dgvStolenChienPerPoint pin",
    }, {
      "expr" = "m['dgvClanFortunesFollow']() != 1",
      "note" = "the dgvClanFortunesFollow pin",
    }, {
      "expr" = "m['dgvRaiseOncePerGroup']() != 1",
      "note" = "the dgvRaiseOncePerGroup pin",
    }, {
      "expr" = "m['dgvRaiseAtMaxHonor']() != 1",
      "note" = "the dgvRaiseAtMaxHonor pin",
    }, {
      "expr" = "m['dgvLossBlotsFamily']() != 1",
      "note" = "the dgvLossBlotsFamily pin",
    }, {
      "expr" = "m['dgvFamilyShareChange']() != 1",
      "note" = "the dgvFamilyShareChange pin",
    }, {
      "expr" = "m['dgvEffectsAutomatic']() != 1",
      "note" = "the dgvEffectsAutomatic pin",
    }, {
      "expr" = "m['dgvBelowZeroOut']() != 1",
      "note" = "the dgvBelowZeroOut pin",
    }, {
      "expr" = "m['dgvSamuraiKensaiStatus']() != 1",
      "note" = "the dgvSamuraiKensaiStatus pin",
    }, {
      "expr" = "m['dgvBelowBaseFamilyMod']() != 1",
      "note" = "the dgvBelowBaseFamilyMod pin",
    }, {
      "expr" = "m['dgvHarderToImpress']() != 1",
      "note" = "the dgvHarderToImpress pin",
    }, {
      "expr" = "m['dgvGiftFromLord']() != 1",
      "note" = "the dgvGiftFromLord pin",
    }, {
      "expr" = "m['dgvSongsAndBoasts']() != 1",
      "note" = "the dgvSongsAndBoasts pin",
    }, {
      "expr" = "m['dgvLordInvitation']() != 1",
      "note" = "the dgvLordInvitation pin",
    }, {
      "expr" = "m['dgvGreatHeroRead']() != 1",
      "note" = "the dgvGreatHeroRead pin",
    }, {
      "expr" = "m['dgvSuccessorBonus']() != 1",
      "note" = "the dgvSuccessorBonus pin",
    }, {
      "expr" = "m['dgvSuccessorLimits']() != 1",
      "note" = "the dgvSuccessorLimits pin",
    }, {
      "expr" = "m['dgvSuccessorFreedom']() != 1",
      "note" = "the dgvSuccessorFreedom pin",
    }, {
      "expr" = "m['dgvKensaiDuelOncePerLevel']() != 1",
      "note" = "the dgvKensaiDuelOncePerLevel pin",
    }, {
      "expr" = "m['dgvSamuraiDoubleAwards']() != 1",
      "note" = "the dgvSamuraiDoubleAwards pin",
    }, {
      "expr" = "m['dgvSingleCreatureRead']() != 1",
      "note" = "the dgvSingleCreatureRead pin",
    }, {
      "expr" = "m['dgvT42Points'](28) != -30  or m['dgvT42Points'](44) != -30",
      "note" = "the T42 treason and identity rows - the two -30 awards (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](12) != 7",
      "note" = "the T42 family debt row - the +7 best all-character award (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](2) != 5  or m['dgvT42Points'](6) != 5  or m['dgvT42Points'](26) != 5",
      "note" = "the T42 +5 trio - avenging murder, the great deed, the life saved at great risk (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Mark'](4) != 1  or m['dgvT42Mark'](5) != 1  or m['dgvT42Mark'](8) != 1  or m['dgvT42Mark'](16) != 1  or m['dgvT42Mark'](27) != 1",
      "note" = "the T42 starred rows - the samurai-doubled marks at prisoner, broken oath, ancestral enemy, lost birthright, served lord (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](10) != -1  or m['dgvT42Mark'](10) != 2  or m['dgvMonsterXpPerPoint']() != 2000",
      "note" = "the T42 monsters row - the -1 per 2000 experience points, single creatures only (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](67) != 1  or m['dgvStolenChienPerPoint']() != 100",
      "note" = "the T42 yakuza rate row - the +1 per 100 ch'ien stolen-goods read (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](41) != 1  or m['dgvT42Points'](35) != -3  or m['dgvT42Points'](38) != -5",
      "note" = "the T42 kensai duel trio - the +1 win, the -3 loss, the -5 refusal (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](47) != -10  or m['dgvT42Points'](53) != -10  or m['dgvT42Points'](54) != -10  or m['dgvT42Points'](43) != -10  or m['dgvT42Points'](61) != -10",
      "note" = "the T42 -10 gravest rows - fleeing a fight, the lost magical item, the ninja-weapon proficiency, the failing mission, the lost minyan (capture p. 72)",
    }, {
      "expr" = "m['dgvT42Points'](0) != -4  or m['dgvT42Points'](67) != 1  or m['dgvT42RowCount']() != 68",
      "note" = "the T42 bounds - the -4 accused first row, the +1 stolen-goods last row, sixty-eight rows only (capture p. 72)",
    }, {
      "expr" = "m['dgvFamilyRaiseStep']() != 10  or m['dgvFamilyRaiseAmount']() != 1  or m['dgvRaiseOncePerGroup']() != 1  or m['dgvFamilyLossThreshold']() != 5  or m['dgvFamilyLossAmount']() != 1",
      "note" = "the family ledger doctrine - the 10-point raise step with the +1 raise and the once-per-group read, the 5-point blot with the -1 loss (capture p. 70)",
    }, {
      "expr" = "m['dgvGiftHonorPoints']() != 75  or m['dgvSongsHonorPoints']() != 80  or m['dgvServeHonorPoints']() != 90  or m['dgvGreatHeroHonorPoints']() != 95",
      "note" = "the effects thresholds - the 75 gift, the 80 songs, the 90 invitation, the 95 great hero (capture pp. 71-72)",
    }, {
      "expr" = "m['dgvSuccessorDivisor']() != 10  or m['dgvSuccessorMaxPerRoll']() != 3  or m['dgvSuccessorBonus']() != 1  or m['dgvSuccessorFreedom']() != 1",
      "note" = "the successor doctrine - the remainder divided by 10, the 3-point cap, the freedom of race, class and family (capture p. 72)",
    } },
  "audit" = {
      "label" = "R635 OA effects of honor audit",
      "comment" = "OA round twenty-two (capture pp. 70-72): the altering family honor prose, the effects of honor doctrines and the Table 42 grid",
    },
}
