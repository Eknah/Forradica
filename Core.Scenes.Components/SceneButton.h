#pragma once

#include <string>
#include "Convenience.Math/FAutoRectangle.h"
#include "Convenience.Math/FRectangle.h"
#include <functional>

namespace Forradica
{

        class SceneButton
        {
        public:
                SceneButton(std::string _label, float _x, float _y, float _width, std::function<void()> _action) : label(_label), geometry({_x, _y, _width}), action(_action) {}
                FRectangle GetFBounds();

                std::string label;
                FAutoRectangle geometry;
                std::function<void()> action;

        };


}
