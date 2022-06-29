#include "Data.h"
#include "Convenience.Development/Development.h"
#include "Configuration/Configuration.h"

namespace Forradica
{
        void Data::LoadData()
        {
                auto mapSize = Configuration::mapSize;

                DevOut("Creating MapArea-object with specified map size and stor in currentMapArea");
                currentMapArea = std::make_unique<MapArea>(mapSize);

                DevOut("Creating Player-object with starting position of map area center");
                player = std::make_unique<Actor>(mapSize/2, mapSize/2);
        }
}
