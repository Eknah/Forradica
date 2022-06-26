#pragma once

#include "Core.Enums/CursorTypes.h"

namespace Forradica
{


        namespace CustomCursor
        {
                void Initialize(float _cursorSize);
                void Reset();
                void Render();

                inline float cursorSize = 0.0f;
                inline CursorTypes currentCursorType = CursorTypes::Default;
        };

}
