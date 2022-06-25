//Files.h
#ifndef NEO_TOOLBOX_FILES_H
#define NEO_TOOLBOX_FILES_H

#include <vector>
#include <string>

namespace sdlUtility {
    /// Functions used to browse directories/files.
    namespace Files {
        std::vector<std::string> GetDirectoryList(std::string Path, std::string FileType = "");
    }
}

#endif
