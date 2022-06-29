#pragma once

#include <vector>
#include "Object.h"

namespace Forradica
{

        class Tile
        {
        public:
                int groundType = 0;
                std::vector<Object> objects;
        };


}

