#pragma once

#include "Scene.h"

namespace Forradica
{

        class StartUpScene : public Scene
        {
        public:
                void UpdateDerived() override;
                void RenderDerived() override;
                void DoKeyDownDerived(SDL_Keycode key) override;
                void DoKeyUpDerived(SDL_Keycode key) override;
                void DoMouseDownDerived(Uint8 button) override;
                void DoMouseUpDerived(Uint8 button) override;

        private:
                void SwitchToMainMenuScene();
        };

}
