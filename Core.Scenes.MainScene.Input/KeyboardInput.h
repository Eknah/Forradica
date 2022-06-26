#pragma once

#include <SDL2/SDL.h>
#include <set>

namespace Forradica
{

        namespace KeyboardInput
        {
                void DoKeyDown(SDL_Keycode key);
                void DoKeyUp(SDL_Keycode key);

                inline std::set<SDL_Keycode> pressedKeys;
        }

}
