#include "Core/Game.h"
#include "Configuration/Configuration.h"
#include "Convenience.Development/Development.h"

int wmain()
{
        Forradica::DevOut("Creating configuration object");
        Forradica::Configuration configuration;

        Forradica::DevOut("Setting default configuration values");
        configuration.UseDefaultConfigurationValues();

        Forradica::DevOut("Start new game instance");
        Forradica::Game::Start(configuration);

        return 0;
}
