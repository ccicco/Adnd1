local failures = 0
local checked = 0
local seen_names = {}

local function fail(path, message)
    io.stderr:write(path .. ": " .. message .. "\n")
    failures = failures + 1
end

local function is_finite_number(value)
    return type(value) == "number"
        and value == value
        and value ~= math.huge
        and value ~= -math.huge
end

local function normalize_name(name)
    return name:lower():gsub("%s+", " "):gsub("^%s+", ""):gsub("%s+$", "")
end

local function check_string_value(path, field, value, required)
    if value == nil then
        if required then
            fail(path, ("field '%s' is required"):format(field))
        end
        return nil
    end
    if type(value) ~= "string" then
        fail(path, ("field '%s' must be a string"):format(field))
        return nil
    end
    if value:match("^%s*$") then
        fail(path, ("field '%s' must not be empty"):format(field))
    end
    return value
end

local function check_string(path, record, key, required)
    return check_string_value(path, key, record[key], required)
end

local function check_table(path, record, key, required)
    local value = record[key]
    if value == nil then
        if required then
            fail(path, ("field '%s' is required"):format(key))
        end
        return nil
    end
    if type(value) ~= "table" then
        fail(path, ("field '%s' must be a table"):format(key))
        return nil
    end
    return value
end

local function check_number_value(path, field, value, opts)
    if value == nil then
        if opts.required then
            fail(path, ("field '%s' is required"):format(field))
        end
        return nil
    end
    if not is_finite_number(value) then
        fail(path, ("field '%s' must be a finite number"):format(field))
        return nil
    end

    if opts.integer and value % 1 ~= 0 then
        fail(path, ("field '%s' must be an integer"):format(field))
    end
    if opts.min ~= nil and value < opts.min then
        fail(path, ("field '%s' must be >= %s"):format(field, opts.min))
    end
    if opts.max ~= nil and value > opts.max then
        fail(path, ("field '%s' must be <= %s"):format(field, opts.max))
    end

    return value
end

local function check_number(path, record, key, opts)
    return check_number_value(path, key, record[key], opts)
end

local function check_number_in_table(path, parent, parent_key, key, opts)
    if type(parent) ~= "table" then
        return nil
    end
    return check_number_value(path, parent_key .. "." .. key, parent[key], opts)
end

local function validate_damage(path, damage)
    for i, attack in ipairs(damage) do
        if type(attack) ~= "table" then
            fail(path, ("damage[%d] must be a table"):format(i))
        elseif attack.raw ~= nil then
            if type(attack.raw) ~= "string" or attack.raw:match("^%s*$") then
                fail(path, ("damage[%d].raw must be a non-empty string"):format(i))
            end
        else
            local minimum = check_number_in_table(path, attack, ("damage[%d]"):format(i), "min", {
                required = true,
                min = 0,
                max = 100000,
            })
            local maximum = check_number_in_table(path, attack, ("damage[%d]"):format(i), "max", {
                required = true,
                min = 0,
                max = 100000,
            })
            if minimum ~= nil and maximum ~= nil and maximum < minimum then
                fail(path, ("damage[%d].max must be >= damage[%d].min"):format(i, i))
            end
        end
    end
end

local function validate_imported_schema(path, record)
    -- Broad sanity bounds only (not a full AD&D rules audit):
    -- page 1..5000, hit dice values up to 100, AC -30..30, attack count 1..20,
    -- XP fields up to 1e9, movement rates up to 10000, and appearance counts up to 1e6.
    check_number(path, record, "page", { required = true, integer = true, min = 1, max = 5000 })
    check_string(path, record, "hitDice", true)
    check_number(path, record, "hitDiceNum", { required = true, min = 0, max = 100 })
    check_number(path, record, "hitDiceBonus", { required = true, integer = true, min = -1000, max = 1000 })
    check_number(path, record, "avgHp", { required = true, min = 0, max = 100000 })
    check_number(path, record, "armorClass", { required = true, integer = true, min = -30, max = 30 })
    check_number(path, record, "numAttacks", { required = true, integer = true, min = 1, max = 20 })
    check_table(path, record, "damage", true)
    check_number(path, record, "xp", { required = true, integer = true, min = 0, max = 1000000000 })
    check_number(path, record, "xpPerHp", { required = true, integer = true, min = 0, max = 1000000000 })
    check_number(path, record, "xpValue", { required = true, integer = true, min = 0, max = 1000000000 })
    check_string(path, record, "frequency", true)
    check_table(path, record, "noAppearing", true)
    check_table(path, record, "treasure", true)
    check_table(path, record, "move", true)
    check_string(path, record, "size", false)
    check_string(path, record, "alignment", true)
    check_string(path, record, "text", true)

    local no_appearing = record.noAppearing
    if type(no_appearing) == "table" then
        local minimum = check_number_in_table(path, no_appearing, "noAppearing", "min", {
            required = true,
            integer = true,
            min = 0,
            max = 1000000,
        })
        local maximum = check_number_in_table(path, no_appearing, "noAppearing", "max", {
            required = true,
            integer = true,
            min = 0,
            max = 1000000,
        })
        if minimum ~= nil and maximum ~= nil and maximum < minimum then
            fail(path, "noAppearing.max must be >= noAppearing.min")
        end
    end

    local damage = record.damage
    if type(damage) == "table" then
        validate_damage(path, damage)
    end

    check_number(path, record, "lairPct", { required = false, integer = true, min = 0, max = 100 })

    local move = record.move
    if type(move) == "table" then
        check_number_in_table(path, move, "move", "rate", {
            required = false,
            min = 0,
            max = 10000,
        })

        local modes = move.modes
        if modes ~= nil then
            if type(modes) ~= "table" then
                fail(path, "move.modes must be a table when present")
            else
                for i, mode in ipairs(modes) do
                    if type(mode) ~= "table" then
                        fail(path, ("move.modes[%d] must be a table"):format(i))
                    else
                        check_string_value(path, ("move.modes[%d].mode"):format(i), mode.mode, true)
                        check_number_in_table(path, mode, ("move.modes[%d]"):format(i), "rate", {
                            required = true,
                            min = 0,
                            max = 10000,
                        })
                    end
                end
            end
        end
    end
end

local function validate_legacy_schema(path, record)
    check_number(path, record, "hd", { required = true, min = 0, max = 100 })
    check_number(path, record, "ac", { required = true, integer = true, min = -30, max = 30 })
    check_number(path, record, "attacks", { required = true, integer = true, min = 1, max = 20 })

    if record.xp == nil and record.xpValue == nil then
        fail(path, "field 'xp' or 'xpValue' is required")
    end
    check_number(path, record, "xp", { required = false, integer = true, min = 0, max = 1000000000 })
    check_number(path, record, "xpValue", { required = false, integer = true, min = 0, max = 1000000000 })

    check_number(path, record, "hpBonus", { required = false, integer = true, min = -10000, max = 10000 })
    check_number(path, record, "damageCount", { required = false, integer = true, min = 0, max = 1000 })
    check_number(path, record, "damageSides", { required = false, integer = true, min = 1, max = 1000 })
    check_number(path, record, "morale", { required = false, min = 0, max = 20 })
    check_number(path, record, "magicResist", { required = false, min = 0, max = 100 })
    check_number(path, record, "requiredPlus", { required = false, integer = true, min = 0, max = 10 })
    check_number(path, record, "levelTag", { required = false, integer = true, min = 1, max = 100 })
end

local function validate_file(path)
    checked = checked + 1

    local env = {}
    local chunk, load_error = loadfile(path, "t", env)
    if not chunk then
        fail(path, "Lua syntax/load error: " .. tostring(load_error))
        return
    end

    local ok, record = pcall(chunk)
    if not ok then
        fail(path, "error while evaluating file: " .. tostring(record))
        return
    end

    if type(record) ~= "table" then
        fail(path, "file must return a table")
        return
    end

    local name = check_string(path, record, "name", true)
    if name ~= nil and not name:match("^%s*$") then
        local normalized = normalize_name(name)
        local previous = seen_names[normalized]
        if previous then
            fail(path, ("duplicate monster name '%s' (also in %s)"):format(name, previous))
        else
            seen_names[normalized] = path
        end
    end

    if record.hitDiceNum ~= nil or record.hitDice ~= nil then
        validate_imported_schema(path, record)
    else
        validate_legacy_schema(path, record)
    end
end

if #arg == 0 then
    io.stderr:write("Usage: lua5.4 scripts/validate_monsters.lua <monster.lua> [more files]\n")
    os.exit(2)
end

for _, path in ipairs(arg) do
    validate_file(path)
end

if failures > 0 then
    io.stderr:write(("%d error(s) in %d monster file(s)\n"):format(failures, checked))
    os.exit(1)
end

print(("Validated %d monster files"):format(checked))
