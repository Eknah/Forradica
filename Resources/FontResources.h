#pragma once

#include <memory>
#include <SDL2/SDL_ttf.h>
#include "Convenience/SDLDeleter.h"
#include <string>

namespace Forradica
{

        namespace FontResources
        {
                void InitializeTTF();
                void LoadFonts();

                inline std::unique_ptr<TTF_Font, SDLDeleter> defaultFont = nullptr;
        };



}

