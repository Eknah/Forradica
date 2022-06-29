#pragma once

#include <string>

namespace Forradica
{

        namespace Configuration
        {
                void UseDefaultConfigurationValues();

                inline std::string imageResourcesPath;
                inline std::string imageNameExtension;
                inline std::string defaultFontResourcePath;
                inline float textScaling;
                inline float cursorSize;
                inline int mapSize;
                inline int columnsCount;
        };

}
