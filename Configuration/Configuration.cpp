#include "Configuration.h"

namespace Forradica
{
        void Configuration::UseDefaultConfigurationValues()
        {
                imageResourcesPath = "/Resources/Images";
                imageNameExtension = ".png";
                defaultFontResourcePath ="/Resources/Fonts/PixeloidSans.ttf";
                textScaling = 2.0f;
                cursorSize = 0.02f;
                mapSize = 100;
                columnsCount = 21;
        }
}
