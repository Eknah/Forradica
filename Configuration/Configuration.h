#pragma once

#include <string>

namespace Forradica
{

        class Configuration
        {
        public:
                void UseDefaultConfigurationValues();

                std::string imageResourcesPath;
                std::string imageNameExtension;
                std::string defaultFontResourcePath;
                float textScaling;
                float cursorSize;
                int mapSize;
                int columnsCount;
        };

}
