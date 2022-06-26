#pragma once

#include "FPoint.h"

namespace Forradica
{

        class FRectangle
        {
        public:
                float x = 0;
                float y = 0;
                float width = 0;
                float height = 0;

                FRectangle() = default;
                FRectangle(float _x, float _y, float _width, float _height) : x(_x), y(_y), width(_width), height(_height) {}

                bool Contains(FPoint point);
        };

}
