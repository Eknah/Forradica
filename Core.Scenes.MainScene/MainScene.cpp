#include "MainScene.h"
#include <SDL2/SDL.h>
#include "Core/SDL.h"
#include "Core.Drawing/Draw.h"
#include "Convenience/GetHash.h"
#include "Core/SceneManager.h"
#include "Convenience/Tools.h"
#include "Convenience/Cast.h"
#include "Core/Data.h"

namespace Forradica
{

        void MainScene::UpdateDerived()
        {

        }

        void MainScene::RenderDerived()
        {
                SDL_SetRenderDrawColor(SDL::renderer.get(), 0, 150, 255, 255);
                SDL_RenderClear(SDL::renderer.get());

                auto aspectRatio = Tools::GetAspectRatio();

                float tileFWidth = 1.0f/11;
                float tileFHeight = tileFWidth*aspectRatio;

                for (auto y = 0; y < 11; y++)
                {
                        for (auto x = 0; x < 11; x++)
                        {
                                auto mapx = Data::player->x - 5 + x;
                                auto mapy = Data::player->y - 2 + y;

                                auto xF = x*tileFWidth;
                                auto yF = y*tileFHeight;
                                auto widthF = tileFWidth + 0.001;
                                auto heightF = tileFHeight + 0.001;

                                auto groundType = Data::currentMapArea->tiles[mapx][mapy].groundType;

                                Draw::Image(groundType, xF, yF, widthF, heightF, false);

                                if (mapx == Data::player->x && mapy == Data::player->y)
                                {
                                        Draw::Image(GetHash("Player"), xF, yF, widthF, heightF, false);
                                }
                        }
                }
        }

        void MainScene::DoKeyDownDerived(SDL_Keycode key)
        {
        }

        void MainScene::DoKeyUpDerived(SDL_Keycode key)
        {

        }

        void MainScene::DoMouseDownDerived(Uint8 button)
        {
        }

        void MainScene::DoMouseUpDerived(Uint8 button)
        {

        }

}
