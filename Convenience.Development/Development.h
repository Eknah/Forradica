#pragma once

#include <string>

namespace Forradica
{
        namespace Development
        {
                inline bool developmentMode = true;
        }

        void DevOut(std::string text);
}
