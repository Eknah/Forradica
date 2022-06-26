#pragma once

#include <string>
#include "Convenience.Math/Size.h"
#include "Convenience.Math/FPoint.h"

namespace Forradica
{

        namespace Tools
        {
                Size GetCanvasSize();
                float GetAspectRatio();
                std::string Right(std::string text, int length);
                FPoint GetMousePosition();
                FPoint GetMousePosition();

        }

}
