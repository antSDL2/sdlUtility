//Lua.cpp
#include "Lua.h"
#include <iostream>

namespace AtUtility {
    namespace Lua {
        /// Used to execute a Lua script.
        /** @param Lua The Lua context.
            @param Script The Lua script as a string. */
        int ExecuteScript(lua_State *Lua, std::string Script) {
            int ExecuteScript = 0;

            if (Lua) {
                ExecuteScript = luaL_dostring(Lua, Script.c_str());

                if (ExecuteScript) {
                    std::cerr << lua_tostring(Lua, -1) << std::endl;
                    lua_pop(Lua, 1);
                }
            }

            /*
            std::cout << "Script {" << std::endl;
            std::cout << Script << std::endl;
            std::cout << "}" << std::endl;
            */

            return ExecuteScript;
        }

        /// Used to execute a Lua script from the specified file.
        /** @param Lua The Lua context.
            @param Location The location of the Lua script to be executed. */
        int ExecuteFile(lua_State *Lua, std::string Location) {
            int ExecuteFile = 0;

            if (Lua) {
                ExecuteFile = luaL_dofile(Lua, Location.c_str());

                if (ExecuteFile) {
                    std::cerr << lua_tostring(Lua, -1) << std::endl;
                    lua_pop(Lua, 1);
                }
            }

            return ExecuteFile;
        }
    }
}
