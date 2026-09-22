-- File: monsters/monsters/mind_flayer.lua
-- R46: the psionic hook's flagship monster. Monster Manual
-- values (verification debt as with the R16/R44 sets: the
-- printed MM wins on any disagreement). The mind flayer's
-- PSIONICS are not a Lua field — the app flags psionic
-- monsters by key in beginCombat (the R37 monsterRanged
-- pattern; the registry schema has no psionics field).
return {
    name = "Mind Flayer",
    hd = 8,
    hpBonus = 4,
    ac = 5,
    attacks = 4,
    damageCount = 1,
    damageSides = 4,
    morale = 12,
    magicResist = 0,
    undead = false,
    requiredPlus = 0,
    levelTag = 4,
    xpValue = 250,
}
