//Files.cpp
#include "Files.h"
#include <iostream>
#include <dirent.h>

namespace AtUtility {
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
}
