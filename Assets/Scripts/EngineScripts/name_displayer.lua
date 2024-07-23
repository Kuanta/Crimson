-- NameDisplayer.lua

local EntityBehaviour = require("EntityBehaviour")  -- This assumes you have an EntityBehaviour module

-- We'll create a local NameDisplayer table for encapsulation
local NameDisplayer = {}
NameDisplayer.lastPrintTime = 0.0
NameDisplayer.printInterval = 5.0  -- interval to print name (in seconds)

-- If necessary, we can inherit from EntityBehaviour as before
setmetatable(NameDisplayer, { __index = EntityBehaviour })
local superclass = EntityBehaviour

-- Now, the Update function. It's kept local but will be exposed via the returned table
local function Update()
    local timeSince = NameDisplayer:GetElapsedTime() - NameDisplayer.lastPrintTime
    EntityBehaviour.SetPosition(0, math.rad(timeSince) * 10,0);
    if timeSince >= NameDisplayer.printInterval then
        --local entityName = Crimson.GetName()
        NameDisplayer.lastPrintTime = NameDisplayer:GetElapsedTime()
    end
end

return {
    Update = Update,
}