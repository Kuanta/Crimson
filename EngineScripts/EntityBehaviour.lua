local EntityBehaviour = {}

function EntityBehaviour:Update()
    -- Default implementation (can be overridden by specific scripts)
end

function EntityBehaviour:SetPosition(x, y, z)
    -- Here, you'd typically change the position of the entity.
end

-- This can be called by user scripts to get the global delta time
function EntityBehaviour:GetDeltaTime()
    return Crimson.GetDeltaTime()
end

function EntityBehaviour:GetElapsedTime()
    return Crimson.GetElapsedTime()
end

function EntityBehaviour:GetName()
    return Crimson.GetName()
end

return EntityBehaviour
