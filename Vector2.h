//Vector2.h
#ifndef NEO_TOOLBOX_VECTOR2_H
#define NEO_TOOLBOX_VECTOR2_H

namespace sdlUtility {
	/// Used to describe a 2D vector as a set of (x, y) components.
    class Vector2 {
        //Members
        protected:
            float x;                                    //!< X component of the vector.
            float y;                                    //!< Y component of the vector.
        //Access Methods
        public:
            Vector2(float X = 0, float Y = 0);
            ~Vector2();
            void operator=(Vector2 Vector);
            void operator+=(Vector2 Vector);
            void operator-=(Vector2 Vector);
            bool operator==(Vector2 Vector);
            bool operator!();
            bool operator!=(Vector2 Vector);
            float Angle();
            float Length();
            float Length2();
            float X();
            float Y();
    };
}

#endif
