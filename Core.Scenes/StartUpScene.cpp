#include "StartUpScene.h"
#include <SDL2/SDL.h>
#include "Core/SDL.h"
#include "Core.Drawing/Draw.h"
#include "Convenience/GetHash.h"
#include "Core/SceneManager.h"

namespace Forradica
{

        void StartUpScene::UpdateDerived()
        {

        }

        void StartUpScene::RenderDerived()
        {
                SDL_SetRenderDrawColor(SDL::renderer.get(), 0, 150, 255, 255);
                SDL_RenderClear(SDL::renderer.get());

                Draw::Image(GetHash("ForradicaLogo"), 0.5f, 0.15f, 0.5f);
                Draw::StringCenter("Press to start", 0.5f, 0.5f, 0, 0, 0);

        }

        void StartUpScene::DoKeyDownDerived(SDL_Keycode key)
        {
                SwitchToMainMenuScene();
        }

        void StartUpScene::DoKeyUpDerived(SDL_Keycode key)
        {

        }

        void StartUpScene::DoMouseDownDerived(Uint8 button)
        {
                SwitchToMainMenuScene();
        }

        void StartUpScene::DoMouseUpDerived(Uint8 button)
        {

        }

        void StartUpScene::SwitchToMainMenuScene()
        {
                SceneManager::currentScene = GetHash("MainMenuScene");
        }

}
