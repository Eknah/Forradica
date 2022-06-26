#include "Cast.h"

namespace Forradica
{

        int Cast::ToInt(float value)
        {
                return static_cast<int>(value);
        }


        float Cast::ToFloat(int value)
        {
                return static_cast<float>(value);
        }

}
