//Vectors.h
#ifndef NEO_TOOLBOX_VECTORS_H
#define NEO_TOOLBOX_VECTORS_H

#include <vector>

namespace sdlUtility {
    /// Functions used to operate on std::vector structures.
    namespace Vectors {
        /// Finds the maximum value within the specified vector and returns its index.
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

        /// Finds the minimum value within the specified vector and returns its index.
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
