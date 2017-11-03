//Strings.cpp
#include "Strings.h"

namespace AtUtility {
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
