//Strings.cpp
#include "Strings.h"

namespace sdlUtility {
    namespace Strings {
        /// Returns the position of the nth occurrence of a character within the specified string.
        /** @param Occurrence Parameter to specify which occurrence to find.
            @param Character The character to find.
            @param String The specified string. */
        int FindNthOf(int &Occurrence, char Character, const std::string &String) {
            int TargetPosition = -1;

            if (FindTotalOf(Character, String) >= Occurrence) {
                int LastOccurence = -1;
                int Counter = 0;

                bool More = true;
                while (More) {
                    int Position = String.find(Character, LastOccurence+1);
                    if (Position >= 0) {
                        LastOccurence = Position;
                        Counter++;
                        if (Counter-1 == Occurrence) {
                            Occurrence = Position;
                            More = false;
                        }
                    } else More = false;

                    if (Counter == Occurrence) {
                        if (Position < 0) Occurrence = -1; else TargetPosition = Position;
                    }
                }
            }

            return TargetPosition;
        }

        /// Returns the total occurrences of a character within the specified string.
        /** @param Character The character to find.
            @param String The specified string. */
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

        /// Returns a substring from a character-delimited string, as specified by the parameters.
        /** @param String The character-delimited string.
            @param Separator Optional delimiter character.
            @param SubstringNumber Optional index of the requested substring within the character-delimited string. */
        std::string Separate(const std::string &String, char Separator, int SubstringNumber) {
            std::string Substring = "";
            if (Separator) {
                int InitialPosition = 0;
                int FinalPosition = 0;
                if (SubstringNumber) {
                    InitialPosition = FindNthOf(SubstringNumber, Separator, String)+1;
                    if (InitialPosition != 0) FinalPosition = SubstringNumber;
                } else {
                    InitialPosition = 0;
                    FinalPosition = String.find_first_of(Separator);
                }
                //std::cout <<  "(" << InitialPosition << ", " << FinalPosition << ")" << std::endl;
                Substring = String.substr(InitialPosition, FinalPosition-InitialPosition);
            } else Substring = String;
            //std::cout << Substring << std::endl;
            return Substring;
        }
    }
}
