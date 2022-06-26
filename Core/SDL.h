#pragma once

#include <SDL2/SDL.h>
#include "Convenience/SDLDeleter.h"
#include <memory>
#include "Convenience.Math/Size.h"

namespace Forradica
{
        namespace SDL
        {
                void Setup();

                inline std::unique_ptr<SDL_Window, SDLDeleter> window = nullptr;
                inline std::unique_ptr<SDL_Renderer, SDLDeleter> renderer = nullptr;

                bool fullscreen = false;
                const Size defaultWindowSize = {660, 660};
        }
}
