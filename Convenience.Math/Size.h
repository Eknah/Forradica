#pragma once

namespace Forradica
{

        class Size
        {
        public:
                Size() = default;
                Size(int _width, int _height) : width(_width), height(_height) {}

                int width = 0;
                int height = 0;
        };

}
