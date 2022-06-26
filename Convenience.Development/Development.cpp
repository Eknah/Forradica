#include "Development.h"
#include <iostream>

namespace Forradica
{
        void DevOut(std::string text)
        {
                if (Development::developmentMode)
                {
                        std::cout << text << std::endl;
                }
        }

}
