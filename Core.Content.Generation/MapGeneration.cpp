#include "MapGeneration.h"
#include "Convenience/GetHash.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{

        void MapGeneration::GenerateMap(std::unique_ptr<MapArea>& mapArea)
        {
                DevOut("Clear map with grass");
                ClearMapWithGrass(mapArea);
                GenerateWater(mapArea);
        }

        void MapGeneration::ClearMapWithGrass(std::unique_ptr<MapArea>& mapArea)
        {
                for (auto y = 0; y < mapArea->GetSize(); y++)
                {
                        for (auto x = 0; x < mapArea->GetSize(); x++)
                        {
                                mapArea->tiles[x][y].groundType = GetHash("GroundTypeGrass");
                        }
                }
        }

        void MapGeneration::GenerateWater(std::unique_ptr<MapArea>& mapArea)
        {
                for (auto i = 0; i < 40; i++)
                {
                        auto xCenter = rand() % mapArea->GetSize();
                        auto yCenter = rand() % mapArea->GetSize();
                        auto r = 2 + rand() % 9;

                        for (auto y = yCenter - r; y <= yCenter + r; y++)
                        {
                                for (auto x = xCenter - r; x <= xCenter + r; x++)
                                {
                                        if (mapArea->OutsideMap(x,y)) continue;

                                        auto dx = x - xCenter;
                                        auto dy = y - yCenter;

                                        if (dx*dx + dy*dy < r*r)
                                        {
                                                mapArea->tiles[x][y].groundType = GetHash("GroundTypeWater");
                                        }
                                }
                        }
                }
        }

}
