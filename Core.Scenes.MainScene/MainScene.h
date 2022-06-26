#pragma once

#include "Core.Scenes/Scene.h"
#include "Core.WorldStructure/MapArea.h"

namespace Forradica
{

        class MainScene : public Scene
        {
        public:
                void UpdateDerived() override;
                void RenderDerived() override;
                void DoKeyDownDerived(SDL_Keycode key) override;
                void DoKeyUpDerived(SDL_Keycode key) override;
                void DoMouseDownDerived(Uint8 button) override;
                void DoMouseUpDerived(Uint8 button) override;


        };

}
