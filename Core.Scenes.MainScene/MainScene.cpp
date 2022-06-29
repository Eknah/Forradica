#include "MainScene.h"
#include "Core/SDL.h"
#include "Core/SceneManager.h"
#include "Core.Logic/PlayerKeyboardMovement.h"
#include "Core.Scenes.MainScene.Input/KeyboardInput.h"
#include "Core.Scenes.MainScene.Input/MouseInput.h"
#include "Core.Scenes.MainScene.Render/WorldRendering.h"
#include "FPSCounter.h"

namespace Forradica
{

        void MainScene::UpdateDerived()
        {
                PlayerKeyboardMovement::Update();
                FPSCounter::Update();
        }

        void MainScene::RenderDerived()
        {
                SDL_SetRenderDrawColor(SDL::renderer.get(), 0, 150, 255, 255);
                SDL_RenderClear(SDL::renderer.get());

                WorldRendering::RenderGround();
                WorldRendering::RenderObjects();
                FPSCounter::Render();
        }

        void MainScene::DoKeyDownDerived(SDL_Keycode key)
        {
                KeyboardInput::DoKeyDown(key);
        }

        void MainScene::DoKeyUpDerived(SDL_Keycode key)
        {
                KeyboardInput::DoKeyUp(key);
        }

        void MainScene::DoMouseDownDerived(Uint8 button)
        {
                MouseInput::DoMouseDown(button);
        }

        void MainScene::DoMouseUpDerived(Uint8 button)
        {
                MouseInput::DoMouseDown(button);

        }

}
