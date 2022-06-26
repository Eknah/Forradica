#include "FRectangle.h"

namespace Forradica
{

        bool FRectangle::Contains(FPoint point)
        {
                if (point.x < x) return false;
                if (point.y < y) return false;
                if (point.x >= x + width) return false;
                if (point.y >= y + height) return false;

                return true;
        }

}
