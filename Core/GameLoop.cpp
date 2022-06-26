#include "GameLoop.h"
#include <SDL2/SDL.h>
#include "SDL.h"
#include "SceneManager.h"
#include "CustomCursor.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{

        void GameLoop::Run()
        {

                DevOut("Entering game loop");
                while (gameRunning)
                {
                        CustomCursor::Reset();

                        SDL_Event event;

                        while (SDL_PollEvent(&event))
                        {
                                switch (event.type)
                                {
                                case SDL_KEYDOWN:
                                        DevOut("Fired SDL_KEYDOWN event");
                                        SceneManager::DoKeyDownCurrentScene(event.key.keysym.sym);
                                        break;
                                case SDL_KEYUP:
                                        DevOut("Fired SDL_KEYUP event");
                                        SceneManager::DoKeyUpCurrentScene(event.key.keysym.sym);
                                        break;
                                case SDL_MOUSEBUTTONDOWN:
                                        DevOut("Fired SDL_MOUSEBUTTONDOWN event");
                                        SceneManager::DoMouseDownCurrentScene(event.button.button);
                                        break;
                                case SDL_MOUSEBUTTONUP:
                                        DevOut("Fired SDL_MOUSEBUTTONUP event");
                                        SceneManager::DoMouseUpCurrentScene(event.button.button);
                                        break;
                                case SDL_QUIT:
                                        DevOut("Fired SDL_QUIT event");
                                        gameRunning = false;
                                        break;
                                }
                        }
                        SceneManager::UpdateCurrentScene();
                        SDL_RenderClear(SDL::renderer.get());
                        SceneManager::RenderCurrentScene();
                        CustomCursor::Render();
                        SDL_RenderPresent(SDL::renderer.get());
                }
                DevOut("Exiting game loop");

                DevOut("Executing SDL_Quit");
                SDL_Quit();
        }

}
