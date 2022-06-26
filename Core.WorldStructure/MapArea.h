#pragma once

#include <vector>
#include "Tile.h"

namespace Forradica
{

        class MapArea
        {
        public:
                MapArea(int size);
                int GetSize();
                bool OutsideMap(int x, int y);

                std::vector<std::vector<Tile>> tiles;
        };


}

