#pragma once

#include <string>

namespace Forradica
{

        inline int GetHash(std::string text) { return std::hash<std::string>{}(text); }

}
