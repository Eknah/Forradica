#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "Convenience/Constants.h"

namespace Forradica
{

        namespace Draw
        {
                void Initialize(float _textScaling);
                void Image(int imageNameHash, float x, float y, float width, float height = 0, bool centerAlign = true);
                SDL_Rect GetRenderBounds(int imageNameHash, float x, float y, float width);
                void StringCenter(std::string text, float x, float y, Uint8 red, Uint8 green, Uint8 blue);
                void Rectangle(float x, float y, float width, float height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = uint8Max);

                float textScaling = 1.0f;
        }
}
