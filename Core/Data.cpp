#include "Data.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{
        void Data::LoadData(int _columnsCount, int _mapSize)
        {
                DevOut("Setting columns count");
                columnsCount = _columnsCount;

                DevOut("Creating MapArea-object with specified map size and stor in currentMapArea");
                currentMapArea = std::make_unique<MapArea>(_mapSize);

                DevOut("Creating Player-object with starting position of map area center");
                player = std::make_unique<Actor>(_mapSize/2, _mapSize/2);
        }
}
