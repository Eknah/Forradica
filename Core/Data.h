#pragma once

#include "Core.WorldStructure/MapArea.h"
#include "Core.WorldStructure/Actor.h"
#include <memory>

namespace Forradica
{
        namespace Data
        {
                void LoadData();

                inline std::unique_ptr<MapArea> currentMapArea = nullptr;
                inline std::unique_ptr<Actor> player = nullptr;
        };

}

