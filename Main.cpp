#include "Core/Game.h"
#include "Configuration/Configuration.h"
#include "Convenience.Development/Development.h"

int wmain()
{
        Forradica::DevOut("Setting default configuration values");
        Forradica::Configuration::UseDefaultConfigurationValues();

        Forradica::DevOut("Start new game instance");
        Forradica::Game::Start();

        return 0;
}
