#pragma once

#include "Core.WorldStructure/MapArea.h"
#include "Core.WorldStructure/Actor.h"
#include <memory>

namespace Forradica
{
        namespace Data
        {
                void LoadData(int _columnsCount, int _mapSize);

                inline int columnsCount = 0;
                inline std::unique_ptr<MapArea> currentMapArea = nullptr;
                inline std::unique_ptr<Actor> player = nullptr;
        };

}

