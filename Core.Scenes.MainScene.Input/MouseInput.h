#pragma once

#include <SDL2/SDL.h>
#include <set>

namespace Forradica
{

        namespace MouseInput
        {

                void Reset();
                void DoMouseDown(Uint8 button);
                void DoMouseUp(Uint8 button);

                inline std::set<SDL_Keycode> firedButtons;
                inline std::set<SDL_Keycode> pressedButtons;
        }

}
