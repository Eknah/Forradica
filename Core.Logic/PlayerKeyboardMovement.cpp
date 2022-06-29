#include "PlayerKeyboardMovement.h"
#include "Core/Data.h"
#include <SDL2/SDL.h>
#include "Core.Scenes.MainScene.Input/KeyboardInput.h"

namespace Forradica
{

        void PlayerKeyboardMovement::Update()
        {
                auto pressedKeys = KeyboardInput::pressedKeys;

                if (SDL_GetTicks() > Data::player->tickLastMove + Data::player->moveSpeed
                                && (pressedKeys.count(SDLK_UP) || pressedKeys.count(SDLK_RIGHT) || pressedKeys.count(SDLK_DOWN) || pressedKeys.count(SDLK_LEFT)))
                {
                        auto newX = Data::player->x;
                        auto newY = Data::player->y;

                        if (pressedKeys.count(SDLK_UP))
                        {
                                newY--;
                        }

                        if (pressedKeys.count(SDLK_RIGHT))
                        {
                                newX++;
                        }

                        if (pressedKeys.count(SDLK_DOWN))
                        {
                                newY++;
                        }

                        if (pressedKeys.count(SDLK_LEFT))
                        {
                                newX--;
                        }

                        Data::player->x = newX;
                        Data::player->y = newY;
                        Data::player->tickLastMove = SDL_GetTicks();
                }
        }

}
