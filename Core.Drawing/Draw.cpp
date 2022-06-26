#include "Draw.h"
#include "Convenience/Tools.h"
#include "Core/SDL.h"
#include "Resources/ImageResources.h"
#include "Resources/FontResources.h"
#include "Convenience/Cast.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{
        void Draw::Initialize(float _textScaling)
        {
                DevOut("Setting textScaling value from configuration");
                textScaling = _textScaling;
        }

        void Draw::Image(int imageNameHash, float x, float y, float width, float height, bool centerAlign)
        {
                if (ImageResources::images.count(imageNameHash) == 0)
                {
                        printf("Error: Image could not be found.\n");
                        return;
                }

                auto canvasSize = Tools::GetCanvasSize();
                auto imageSize = ImageResources::GetImageSize(imageNameHash);

                int xI = Cast::ToInt(x*canvasSize.width);
                int yI = Cast::ToInt(y*canvasSize.height);
                int widthI = Cast::ToInt(width*canvasSize.width);
                int heightI;

                if (height == 0)
                {
                        float ratio = Cast::ToFloat(imageSize.height)/imageSize.width;
                        heightI = Cast::ToInt(widthI*ratio);
                }
                else
                {
                        heightI = Cast::ToInt(height*canvasSize.height);
                }

                if (centerAlign)
                {
                        xI -= widthI/2;
                        yI -= heightI/2;
                }

                SDL_Rect rectangle = {xI, yI, widthI, heightI};

                SDL_RenderCopy(SDL::renderer.get(), ImageResources::images.at(imageNameHash).get(), nullptr, &rectangle);
        }

        void Draw::StringCenter(std::string text, float x, float y, Uint8 red, Uint8 green, Uint8 blue)
        {
                auto canvasSize = Tools::GetCanvasSize();

                int xI = Cast::ToInt(x*canvasSize.width);
                int yI = Cast::ToInt(y*canvasSize.height);

                int width;
                int height;

                TTF_SizeText(FontResources::defaultFont.get(), text.c_str(), &width, &height);

                SDL_Color color = {red, green, blue, uint8Max};

                auto surface = std::unique_ptr<SDL_Surface, SDLDeleter>((TTF_RenderText_Blended(FontResources::defaultFont.get(), text.c_str(), color)), SDLDeleter());
                auto image = std::unique_ptr<SDL_Texture, SDLDeleter>((SDL_CreateTextureFromSurface(SDL::renderer.get(), surface.get())), SDLDeleter());

                SDL_Rect rectangle;

                rectangle.x = xI;
                rectangle.y = yI;
                rectangle.w = Cast::ToInt(width*textScaling);
                rectangle.h = Cast::ToInt(height*textScaling);

                rectangle.x -= rectangle.w/2;
                rectangle.y -= rectangle.h/2;

                SDL_RenderCopy(SDL::renderer.get(), image.get(), nullptr, &rectangle);
        }

        void Draw::Rectangle(float x, float y, float width, float height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
        {
                auto canvasSize = Tools::GetCanvasSize();
                int xI = Cast::ToInt(x*canvasSize.width);
                int yI = Cast::ToInt(y*canvasSize.height);
                int widthI = Cast::ToInt(width*canvasSize.width);
                int heightI = Cast::ToInt(height*canvasSize.height);
                SDL_Rect rectangle = {xI, yI, widthI, heightI};
                SDL_SetRenderDrawColor(SDL::renderer.get(), red, green, blue, alpha);
                SDL_RenderDrawRect(SDL::renderer.get(), &rectangle);
        }
}
