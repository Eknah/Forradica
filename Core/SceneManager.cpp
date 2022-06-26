#include "SceneManager.h"
#include "Convenience/GetHash.h"
#include "Core.Scenes/StartUpScene.h"
#include "Core.Scenes/MainMenuScene.h"
#include "Core.Scenes.MainScene/MainScene.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{
        void SceneManager::Initialize()
        {
                DevOut("Adding StartUpScene");
                scenes.insert({GetHash("StartUpScene"), std::make_unique<StartUpScene>()});

                DevOut("Adding MainMenuScene");
                scenes.insert({GetHash("MainMenuScene"), std::make_unique<MainMenuScene>()});

                DevOut("Adding MainScene");
                scenes.insert({GetHash("MainScene"), std::make_unique<MainScene>()});

                DevOut("Setting currentScene to StartUpScene");
                currentScene = GetHash("StartUpScene");
        }

        void SceneManager::UpdateCurrentScene()
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->Update();
        }

        void SceneManager::RenderCurrentScene()
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->Render();
        }

        void SceneManager::DoKeyDownCurrentScene(SDL_Keycode key)
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->DoKeyDown(key);
        }

        void SceneManager::DoKeyUpCurrentScene(SDL_Keycode key)
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->DoKeyUp(key);
        }

        void SceneManager::DoMouseDownCurrentScene(Uint8 button)
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->DoMouseDown(button);
        }

        void SceneManager::DoMouseUpCurrentScene(Uint8 button)
        {
                if (currentScene != 0)
                        scenes.at(currentScene)->DoMouseUp(button);
        }


}
