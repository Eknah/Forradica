#include "MapGeneration.h"
#include "Convenience/GetHash.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{

        void MapGeneration::GenerateMap(std::unique_ptr<MapArea>& mapArea)
        {
                DevOut("Clear map with grass");
                ClearMapWithGrass(mapArea);

                DevOut("Generate water");
                GenerateWater(mapArea);

                DevOut("Generate trees");
                GenerateTrees(mapArea);
        }

        void MapGeneration::ClearMapWithGrass(std::unique_ptr<MapArea>& mapArea)
        {
                for (auto y = 0; y < mapArea->GetSize(); y++)
                {
                        for (auto x = 0; x < mapArea->GetSize(); x++)
                        {
                                DevOut("Altering tile with coord: " + std::to_string(x) + ", " + std::to_string(y));

                                DevOut("Set ground type to grass");
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

                                        DevOut("Altering tile with coord: " + std::to_string(x) + ", " + std::to_string(y));

                                        auto dx = x - xCenter;
                                        auto dy = y - yCenter;

                                        if (dx*dx + dy*dy < r*r)
                                        {
                                                DevOut("Set ground type to water");
                                                mapArea->tiles[x][y].groundType = GetHash("GroundTypeWater");
                                        }
                                }
                        }
                }

        }

        void MapGeneration::GenerateTrees(std::unique_ptr<MapArea>& mapArea)
        {
                DevOut("Generating objects of type ObjectTree1");
                for (auto i = 0; i < 140; i++)
                {
                        auto x = rand() % mapArea->GetSize();
                        auto y = rand() % mapArea->GetSize();

                        for (auto j = 0; j < 20; j++)
                        {

                                if (mapArea->OutsideMap(x, y))
                                {
                                        DevOut("Coord outside map: " + std::to_string(x) + ", " + std::to_string(y));
                                        continue;
                                }

                                DevOut("Altering tile with coord: " + std::to_string(x) + ", " + std::to_string(y));

                                if (mapArea->tiles[x][y].groundType != GetHash("GroundTypeWater")
                                                && mapArea->tiles[x][y].objects.size() == 0)
                                {
                                        DevOut("Add ObjectTree1-object to tile");
                                        mapArea->tiles[x][y].objects.push_back(Object(GetHash("ObjectTree1")));
                                }



                                DevOut("Generating new coord");
                                x += rand() % 4 - rand() % 4;
                                y += rand() % 4 - rand() % 4;
                        }
                }

                DevOut("Generating objects of type ObjectTree2");
                for (auto i = 0; i < 140; i++)
                {
                        auto x = rand() % mapArea->GetSize();
                        auto y = rand() % mapArea->GetSize();

                        for (auto j = 0; j < 20; j++)
                        {

                                if (mapArea->OutsideMap(x, y))
                                {
                                        DevOut("Coord outside map: " + std::to_string(x) + ", " + std::to_string(y));
                                        continue;
                                }

                                DevOut("Altering tile with coord: " + std::to_string(x) + ", " + std::to_string(y));

                                if (mapArea->tiles[x][y].groundType != GetHash("GroundTypeWater")
                                                && mapArea->tiles[x][y].objects.size() == 0)
                                {
                                        DevOut("Add ObjectTree1-object to tile");
                                        mapArea->tiles[x][y].objects.push_back(Object(GetHash("ObjectTree2")));
                                }



                                DevOut("Generating new coord");
                                x += rand() % 4 - rand() % 4;
                                y += rand() % 4 - rand() % 4;
                        }
                }
        }

}
