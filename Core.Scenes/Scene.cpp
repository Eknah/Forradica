#include "Scene.h"
#include "Core.Drawing/Draw.h"
#include "Convenience/GetHash.h"
#include "Convenience/Tools.h"
#include "Core/CustomCursor.h"
#include <SDL2/SDL.h>

namespace Forradica
{

        void Scene::Update()
        {
                hoveredSceneButton = GetHoveredButtonIndex();

                if (hoveredSceneButton != undefinedIndex)
                {
                        CustomCursor::currentCursorType = CursorTypes::Hand;
                }

                UpdateDerived();
        }

        void Scene::Render()
        {
                RenderDerived();

                DrawSceneButtons();
        }

        void Scene::DoKeyDown(SDL_Keycode key)
        {
                DoKeyDownDerived(key);
        }

        void Scene::DoKeyUp(SDL_Keycode key)
        {
                DoKeyUpDerived(key);
        }

        void Scene::DoMouseDown(Uint8 button)
        {
                if (button == SDL_BUTTON_LEFT)
                {
                        auto hoveredButtonIndex = GetHoveredButtonIndex();

                        if (hoveredButtonIndex != undefinedIndex)
                        {
                                sceneButtons.at(hoveredButtonIndex).action();
                        }
                }

                DoMouseDownDerived(button);
        }

        void Scene::DoMouseUp(Uint8 button)
        {
                DoMouseUpDerived(button);
        }

        void Scene::DrawSceneButtons()
        {
                if (!sceneButtonsVisible) return;

                int i = 0;

                for (auto button : sceneButtons)
                {
                        std::string buttonImageName;

                        if (i == hoveredSceneButton)
                        {
                                buttonImageName = "SceneButtonHovered";
                        }
                        else
                        {
                                buttonImageName = "SceneButton";
                        }

                        Draw::Image(GetHash(buttonImageName), button.geometry.x, button.geometry.y, button.geometry.width);
                        Draw::StringCenter(button.label, button.geometry.x, button.geometry.y, 0, 0, 0);

                        i++;
                }
        }

        int Scene::GetHoveredButtonIndex()
        {
                int i = 0;

                for (auto button : sceneButtons)
                {
                        auto bounds = button.GetFBounds();
                        auto mousePosition = Tools::GetMousePosition();

                        if (bounds.Contains(mousePosition))
                        {
                                return i;
                        }

                        i++;
                }

                return undefinedIndex;
        }

}
