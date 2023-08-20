-- NameDisplayer.lua

local EntityBehaviour = require("EntityBehaviour")  -- This assumes you have an EntityBehaviour module

-- We'll create a local NameDisplayer table for encapsulation
local NameDisplayer = {}
NameDisplayer.lastPrintTime = 0.0
NameDisplayer.printInterval = 2.0  -- interval to print name (in seconds)

-- If necessary, we can inherit from EntityBehaviour as before
setmetatable(NameDisplayer, { __index = EntityBehaviour })
local superclass = EntityBehaviour

-- Now, the Update function. It's kept local but will be exposed via the returned table
local function Update()
    local timeSince = NameDisplayer:GetElapsedTime() - NameDisplayer.lastPrintTime
    if timeSince >= NameDisplayer.printInterval then
        local entityName = Crimson.GetName()
        print(entityName)
        NameDisplayer.lastPrintTime = NameDisplayer:GetElapsedTime()
    end
end

return {
    Update = Update,
}