#include "MapArea.h"

namespace Forradica
{

        MapArea::MapArea(int size)
        {
                for (auto x = 0; x < size; x++)
                {
                        tiles.push_back(std::vector<Tile>());

                        for (auto y = 0; y < size; y++)
                        {
                                tiles[x].push_back(Tile());
                        }
                }
        }

        int MapArea::GetSize()
        {
                return tiles.size();
        }

        bool MapArea::OutsideMap(int x, int y)
        {
                if (x < 0 || y < 0 || x >= GetSize() || y >= GetSize()) return true;

                return false;
        }

}
