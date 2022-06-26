#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Core.Scenes.Components/SceneButton.h"
#include "Convenience/Constants.h"

namespace Forradica
{

        class Scene
        {
        public:
                void Update();
                void Render();
                void DoKeyDown(SDL_Keycode key);
                void DoKeyUp(SDL_Keycode key);
                void DoMouseDown(Uint8 button);
                void DoMouseUp(Uint8 button);

                virtual void UpdateDerived() = 0;
                virtual void RenderDerived() = 0;
                virtual void DoKeyDownDerived(SDL_Keycode key) = 0;
                virtual void DoKeyUpDerived(SDL_Keycode key) = 0;
                virtual void DoMouseDownDerived(Uint8 button) = 0;
                virtual void DoMouseUpDerived(Uint8 button) = 0;


        protected:
                std::vector<SceneButton> sceneButtons;

        private:
                void DrawSceneButtons();
                int GetHoveredButtonIndex();

                bool sceneButtonsVisible = true;
                int hoveredSceneButton = undefinedIndex;

        };

}
