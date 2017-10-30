//AtTools.h
#ifndef NEO_TOOLBOX_H
#define NEO_TOOLBOX_H

#include <Lua/lua.hpp>
#include <string>
#include <vector>
#include <sstream>

namespace AtTools {
    namespace Files {
        std::vector<std::string> GetDirectoryList(std::string Path, std::string FileType = "");
    }

    namespace Lua {
        int ExecuteScript(lua_State *Lua, std::string Script);
        int ExecuteFile(lua_State *Lua, std::string Location);
    }

    namespace Strings {
        int FindNthOf(int &Occurence, char Character, const std::string &String);
        int FindTotalOf(char Character, const std::string &String);
        std::string Seperate(const std::string &String, char Seperator ='\0', int SubstringNumber = 0);

        template <class Type>
        Type StringTo(const std::string &String, char Seperator = '\0', int SubstringNumber = 0) {
            Type Return;
            std::string Substring;

            Substring = Seperate(String, Seperator, SubstringNumber);

            std::istringstream Stream(Substring);
            Stream >> Return;

            return Return;
        }
    }

    namespace Vectors {
        template <class Type>
        int FindMaximum(std::vector<Type> Vector) {
            unsigned int Size = Vector.size();

            if (Size > 0) {
                int Maximum = 0;
                for (unsigned int i =0; i<Size; i++) {
                    if (Vector[i] > Vector[Maximum]) {
                        Maximum = i;
                    }
                }
                return Maximum;
            } else return 0;
        }

        template <class Type>
        int FindMinimum(std::vector<Type> Vector) {
            unsigned int Size = Vector.size();

            if (Size > 0) {
                int Minimum = 0;
                for (unsigned int i =0; i<Size; i++) {
                    if (Vector[i] < Vector[Minimum]) {
                        Minimum = i;
                    }
                }
                return Minimum;
            } else return 0;
        }
    }
}

#endif
