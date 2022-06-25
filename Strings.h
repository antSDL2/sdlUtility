//Strings.h
#ifndef NEO_TOOLBOX_STRINGS_H
#define NEO_TOOLBOX_STRINGS_H

#include <string>
#include <sstream>

namespace sdlUtility {
    /// Functions used to manipulate strings.
    namespace Strings {
        int FindNthOf(int &Occurrence, char Character, const std::string &String);
        int FindTotalOf(char Character, const std::string &String);
        std::string Separate(const std::string &String, char Separator ='\0', int SubstringNumber = 0);

        /// Converts a string to the specified type.
        /** @param String The string to be converted.
            @param Separator Optional delimiter character.
            @param SubstringNumber Optional index of the requested value within a character-delimited string. */
        template <class Type>
        Type StringTo(const std::string &String, char Separator = '\0', int SubstringNumber = 0) {
            Type Return;
            std::string Substring;

            Substring = Separate(String, Separator, SubstringNumber);

            std::istringstream Stream(Substring);
            Stream >> Return;

            return Return;
        }
    }
}

#endif
