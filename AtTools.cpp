//AtTools.cpp
#include "AtTools.h"
#include <iostream>
#include <dirent.h>

namespace AtTools {
    namespace Files {
        std::vector<std::string> GetDirectoryList(std::string Path, std::string FileType) {
            std::vector<std::string> DirectoryList;

            DIR *Directory = opendir(Path.c_str());
            if (Directory) {
                dirent *Entry = readdir(Directory);
                while (Entry) {
                    std::string Name = Entry->d_name;
                    int Length = Entry->d_namlen;

                    if (Name != "." and Name != "..") {
                        if (FileType != "") {
                            int TypeLength = FileType.size();
                            if (Length > TypeLength) {
                                if (Name.substr(Length-TypeLength, TypeLength) == FileType) {
                                    DirectoryList.push_back(Name);
                                }
                            }
                        } else {
                            DirectoryList.push_back(Name);
                        }
                    }

                    Entry = readdir(Directory);
                }
                closedir(Directory);
            } else std::cerr << "(Physics/Functions.cpp) GetDirectoryList(): Directory '" << Path << "' could not be initialized correctly." << std::endl;

            return DirectoryList;
        }
    }

    namespace Lua {
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

    namespace Strings {
        int FindNthOf(int &Occurence, char Character, const std::string &String) {
            int TargetPosition = -1;

            if (FindTotalOf(Character, String) >= Occurence) {
                int LastOccurence = -1;
                int Counter = 0;

                bool More = true;
                while (More) {
                    int Position = String.find(Character, LastOccurence+1);
                    if (Position >= 0) {
                        LastOccurence = Position;
                        Counter++;
                        if (Counter-1 == Occurence) {
                            Occurence = Position;
                            More = false;
                        }
                    } else More = false;

                    if (Counter == Occurence) {
                        if (Position < 0) Occurence = -1; else TargetPosition = Position;
                    }
                }
            }

            return TargetPosition;
        }

        int FindTotalOf(char Character, const std::string &String) {
            int Counter = 0;
            int LastOccurence = -1;

            bool More = true;
            while (More) {
                int Position = String.find(Character, LastOccurence+1);
                if (Position >= 0) {
                    LastOccurence = Position;
                    Counter++;
                } else More = false;
            }

            return Counter;
        }

        std::string Seperate(const std::string &String, char Seperator, int SubstringNumber) {
            std::string Substring = "";
            if (Seperator) {
                int InitialPosition = 0;
                int FinalPosition = 0;
                if (SubstringNumber) {
                    InitialPosition = FindNthOf(SubstringNumber, Seperator, String)+1;
                    if (InitialPosition != 0) FinalPosition = SubstringNumber;
                } else {
                    InitialPosition = 0;
                    FinalPosition = String.find_first_of(Seperator);
                }
                //std::cout <<  "(" << InitialPosition << ", " << FinalPosition << ")" << std::endl;
                Substring = String.substr(InitialPosition, FinalPosition-InitialPosition);
            } else Substring = String;
            //std::cout << Substring << std::endl;
            return Substring;
        }
    }
}
