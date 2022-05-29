//Lua.h
#ifndef NEO_TOOLBOX_LUA_H
#define NEO_TOOLBOX_LUA_H

#include <string>
#include <Lua/lua.hpp>

namespace AtUtility {
    /// Functions used to execute Lua scripts.
    namespace Lua {
        int ExecuteScript(lua_State *Lua, std::string Script);
        int ExecuteFile(lua_State *Lua, std::string Location);
    }
}

#endif
