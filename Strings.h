//Strings.h
#ifndef NEO_TOOLBOX_STRINGS_H
#define NEO_TOOLBOX_STRINGS_H

#include <string>
#include <sstream>

namespace AtUtility {
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
}

#endif
