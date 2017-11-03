//Files.h
#ifndef NEO_TOOLBOX_FILES_H
#define NEO_TOOLBOX_FILES_H

#include <vector>
#include <string>

namespace AtUtility {
    namespace Files {
        std::vector<std::string> GetDirectoryList(std::string Path, std::string FileType = "");
    }
}

#endif
