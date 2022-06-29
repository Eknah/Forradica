#include "WorldRendering.h"
#include "Configuration/Configuration.h"
#include "Convenience/Tools.h"
#include "Convenience/Cast.h"
#include <SDL2/SDL.h>
#include "Core/Data.h"
#include "Convenience/GetHash.h"
#include "Resources/ImageResources.h"
#include "Core.Drawing/Draw.h"

namespace Forradica
{

        void WorldRendering::RenderGround()
        {
                auto columnsCount = Configuration::columnsCount;
                auto tileFSize = Tools::GetTileSize();
                auto rowsCount = Cast::ToInt(1.0/tileFSize.height);

                for (auto y = 0; y < rowsCount; y++)
                {
                        for (auto x = 0; x < columnsCount; x++)
                        {
                                auto mapx = Cast::ToInt(Data::player->x - (columnsCount - 1)/2 + x);
                                auto mapy = Cast::ToInt(Data::player->y - (rowsCount - 1)/2 + y);

                                auto xF = x*tileFSize.width;
                                auto yF = y*tileFSize.height;
                                auto widthF = tileFSize.width + 0.001f;
                                auto heightF = tileFSize.height + 0.001f;

                                auto groundType = Data::currentMapArea->tiles[mapx][mapy].groundType;

                                if (groundType == GetHash("GroundTypeWater"))
                                {
                                        auto waterAnimIndex = ((SDL_GetTicks() + mapx*mapy) % 1500) / 500;

                                        if (waterAnimIndex > 0)
                                        {
                                                groundType = GetHash("GroundTypeWater" + std::to_string(waterAnimIndex));
                                        }
                                }

                                Draw::Image(groundType, xF, yF, widthF, heightF, false);
                        }
                }
        }

        void WorldRendering::RenderObjects()
        {
                auto columnsCount = Configuration::columnsCount;
                auto tileFSize = Tools::GetTileSize();
                auto rowsCount = Cast::ToInt(1.0/tileFSize.height);

                for (auto y = 0; y < rowsCount; y++)
                {
                        for (auto x = 0; x < columnsCount; x++)
                        {
                                auto mapx = Cast::ToInt(Data::player->x - (columnsCount - 1)/2 + x);
                                auto mapy = Cast::ToInt(Data::player->y - (rowsCount - 1)/2 + y);

                                auto xF = x*tileFSize.width;
                                auto yF = y*tileFSize.height;
                                auto widthF = tileFSize.width + 0.001f;
                                auto heightF = tileFSize.height + 0.001f;

                                for (auto object : Data::currentMapArea->tiles[mapx][mapy].objects)
                                {
                                        auto objectType = object.objectType;

                                        auto origImageSize = ImageResources::GetImageSize(objectType);
                                        auto canvasSize = Tools::GetCanvasSize();
                                        auto scaleFactor = Cast::ToFloat(canvasSize.width)/Configuration::columnsCount/60.0f;
                                        auto imageFWidth = Cast::ToFloat(origImageSize.width)/canvasSize.width*scaleFactor;
                                        auto imageFHeight = Cast::ToFloat(origImageSize.height)/canvasSize.height*scaleFactor;

                                        Draw::Image(objectType, xF + tileFSize.width/2 - imageFWidth/2, yF + tileFSize.height - imageFHeight, imageFWidth, imageFHeight, false);
                                }

                                if (mapx == Data::player->x && mapy == Data::player->y)
                                {
                                        Draw::Image(GetHash("Player"), xF, yF, widthF, heightF, false);
                                }
                        }
                }
        }

}
