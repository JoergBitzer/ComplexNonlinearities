#ifndef SATURATORS_H_INCLUDED
#define SATURATORS_H_INCLUDED

#include"JuceHeader.h"

enum SatType
{
    none,
    hard,
    soft,
    hyptan
};

using SatFunc = std::function<float (float)>;

class Saturators
{
public:
    static SatFunc getSaturator (SatType type)
    {
        if (type == SatType::hard)
            return [] (float x) { return hardClip (x); };

        if (type == SatType::soft)
            return [] (float x) { return softClip (x); };

        if (type == SatType::hyptan)
            return [] (float x) { return tanhClip (x); };

        // None
        return [] (float x) { return x; };
    }

    static inline float hardClip (float x)
    {
        if (x > 1.0f)
            return 1.0f;

        if (x < -1.0f)
            return -1.0f;

        return x;
    }

    static inline float softClip (float x)
    {
        if (x > 1.0f)
            return 1.0f;

        if (x < -1.0f)
            return -1.0f;

        return x - x*x*x/3.0f;
    }

    static inline float tanhClip (float x)
    {
        return tanhf (x);
    }
};

#endif //SATURATORS_H_INCLUDED
