#include "SDL.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{

        void SDL::Setup()
        {

                DevOut("Creating SDL window");
                window = {SDL_CreateWindow("Forradia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, defaultWindowSize.width, defaultWindowSize.height, (fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0) | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED), SDLDeleter()};

                DevOut("Creating SDL renderer");
                renderer = {SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED), SDLDeleter()};

                DevOut("Turning on alpha blending for renderer");
                SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_BLEND);

        }

}
