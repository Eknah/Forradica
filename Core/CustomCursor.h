#pragma once

#include "Core.Enums/CursorTypes.h"

namespace Forradica
{


        namespace CustomCursor
        {
                void Initialize();
                void Reset();
                void Render();

                inline CursorTypes currentCursorType = CursorTypes::Default;
        };

}
