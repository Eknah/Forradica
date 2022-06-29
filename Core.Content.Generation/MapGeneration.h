#pragma once

#include <memory>
#include "Core.WorldStructure/MapArea.h"

namespace Forradica
{

        namespace MapGeneration
        {
                void GenerateMap(std::unique_ptr<MapArea>& mapArea);
                void ClearMapWithGrass(std::unique_ptr<MapArea>& mapArea);
                void GenerateWater(std::unique_ptr<MapArea>& mapArea);
                void GenerateTrees(std::unique_ptr<MapArea>& mapArea);
        };

}
