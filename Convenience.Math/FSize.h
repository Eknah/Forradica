#pragma once

namespace Forradica
{

        class FSize
        {
        public:
                FSize() = default;
                FSize(float _width, float _height) : width(_width), height(_height) {}

                float width = 0.0f;
                float height = 0.0f;
        };

}
