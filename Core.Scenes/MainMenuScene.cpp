#include "MainMenuScene.h"
#include <SDL2/SDL.h>
#include "Core/SDL.h"
#include "Core.Drawing/Draw.h"
#include "Convenience/GetHash.h"
#include "Core/GameLoop.h"
#include "Core/SceneManager.h"

namespace Forradica
{
        MainMenuScene::MainMenuScene()
        {
                SceneButton startNewGameButton("Start New Game", 0.5f, 0.3f, 0.2f, []() {SceneManager::currentScene = GetHash("MainScene");});
                SceneButton continueGameButton("Continue Game", 0.5f, 0.45f, 0.2f, []() {});
                SceneButton exitButton("Exit", 0.5f, 0.6f, 0.2f, []() {GameLoop::gameRunning = false;});

                sceneButtons.push_back(startNewGameButton);
                sceneButtons.push_back(continueGameButton);
                sceneButtons.push_back(exitButton);
        }

        void MainMenuScene::UpdateDerived()
        {

        }

        void MainMenuScene::RenderDerived()
        {
                SDL_SetRenderDrawColor(SDL::renderer.get(), 0, 200, 255, 255);
                SDL_RenderClear(SDL::renderer.get());

                Draw::Image(GetHash("ForradicaLogo"), 0.5f, 0.10f, 0.3f);

        }

        void MainMenuScene::DoKeyDownDerived(SDL_Keycode key)
        {

        }

        void MainMenuScene::DoKeyUpDerived(SDL_Keycode key)
        {

        }

        void MainMenuScene::DoMouseDownDerived(Uint8 button)
        {

        }

        void MainMenuScene::DoMouseUpDerived(Uint8 button)
        {

        }
}
