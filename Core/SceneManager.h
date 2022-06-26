#pragma once

#include <map>
#include <memory>
#include "Core.Scenes/Scene.h"

namespace Forradica
{
        namespace SceneManager
        {
                inline std::map<int, std::unique_ptr<Scene>> scenes;
                inline int currentScene = 0;

                void Initialize();
                void UpdateCurrentScene();
                void RenderCurrentScene();
                void DoKeyDownCurrentScene(SDL_Keycode key);
                void DoKeyUpCurrentScene(SDL_Keycode key);
                void DoMouseDownCurrentScene(Uint8 button);
                void DoMouseUpCurrentScene(Uint8 button);
        }

}
