-- File: monsters/monsters/
-- File: monsters/monsters/lizard_man.lua
-- R44: monster roster expansion. Monster Manual values (the
-- bestiary carries the same verification debt as the R16 set:
-- the printed MM wins on any disagreement). Field schema per
-- monsters/MonsterRegistry.h: hd/hpBonus roll hit points
-- (d8 per die + bonus), ac/attacks/damageCount/damageSides
-- drive combat, morale is on the dm:: base scale, levelTag
-- gates appearance depth (keysForLevel: tag <= depth + 1).
return {
    name = "Lizard Man",
    hd = 2,
    hpBonus = 2,
    ac = 5,
    attacks = 2,
    damageCount = 1,
    damageSides = 4,
    morale = 10,
    magicResist = 0,
    undead = false,
    requiredPlus = 0,
    levelTag = 2,
    xpValue = 30,
}
