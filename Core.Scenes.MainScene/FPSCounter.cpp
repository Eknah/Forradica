#include "FPSCounter.h"
#include <SDL2/SDL.h>
#include "Core.Drawing/Draw.h"
#include "Convenience/Tools.h"
#include <string>

namespace Forradica
{

        void FPSCounter::Update()
        {
                if (SDL_GetTicks() > tickLastUpdate + 1000)
                {
                        fps = framesCount;
                        framesCount = 0;
                        tickLastUpdate = SDL_GetTicks();
                }
                framesCount++;
        }

        void FPSCounter::Render()
        {
                auto w = 0.07f;
                auto h = 0.05f;
                auto x = 1.0f - w;
                auto y = 0.0f;
                Draw::FilledRectangle(x, y, w, h, 0, 150, 255, 200);
                Draw::StringCenter("FPS: " + std::to_string(fps), x + w/2, y + h/2, 255, 255, 255);
        }

}
