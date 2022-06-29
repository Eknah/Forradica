#pragma once

#include <string>
#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include "Convenience/SDLDeleter.h"
#include "Convenience.Math/Size.h"

namespace Forradica
{
        namespace ImageResources
        {
                void LoadImages();
                Size GetImageSize(int imageNameHash);

                inline std::map<int, std::unique_ptr<SDL_Texture, SDLDeleter>> images;
        }

}
