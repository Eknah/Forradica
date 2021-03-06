#include "Tools.h"
#include "Core/SDL.h"
#include "Convenience/Cast.h"
#include "Configuration/Configuration.h"

namespace Forradica
{
        Size Tools::GetCanvasSize()
        {
                Size result;
                SDL_GetWindowSize(SDL::window.get(), &result.width, &result.height);

                return result;
        }

        float Tools::GetAspectRatio()
        {
                auto canvasSize = GetCanvasSize();

                return Cast::ToFloat(canvasSize.width)/canvasSize.height;
        }

        std::string Tools::Right(std::string text, int length)
        {
                return text.substr(text.length() - length, length);
        }

        FPoint Tools::GetMousePosition()
        {
                auto canvasSize = GetCanvasSize();
                int x;
                int y;
                SDL_GetMouseState(&x, &y);

                FPoint result = {Cast::ToFloat(x)/canvasSize.width, Cast::ToFloat(y)/canvasSize.height};

                return result;
        }

        FSize Tools::GetTileSize()
        {
                auto aspectRatio = GetAspectRatio();
                auto columnsCount = Configuration::columnsCount;

                float tileFWidth = 1.0f/columnsCount;
                float tileFHeight = tileFWidth*aspectRatio;

                return {tileFWidth, tileFHeight};
        }

}
