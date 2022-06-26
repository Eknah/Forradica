#include "Game.h"
#include "SDL.h"
#include "GameLoop.h"
#include "SceneManager.h"
#include "Resources/ImageResources.h"
#include "Resources/FontResources.h"
#include "Core.Drawing/Draw.h"
#include "CustomCursor.h"
#include "Data.h"
#include "Convenience.Development/Development.h"
#include "Core.Content.Generation/MapGeneration.h"
#include <ctime>

namespace Forradica
{

        void Game::Start(Configuration configuration)
        {
                DevOut("Seeding RNG with srand");
                srand(time(nullptr));

                DevOut("Setting up SDL");
                SDL::Setup();

                DevOut("Initializing SceneManager");
                SceneManager::Initialize();

                DevOut("Loading images");
                ImageResources::LoadImages(configuration.imageResourcesPath, configuration.imageNameExtension);

                DevOut("Initializing TTF");
                FontResources::InitializeTTF();

                DevOut("Loading fonts");
                FontResources::LoadFonts(configuration.defaultFontResourcePath);

                DevOut("Initializing drawing operations");
                Draw::Initialize(configuration.textScaling);

                DevOut("Initializing custom cursor");
                CustomCursor::Initialize(configuration.cursorSize);

                DevOut("Loading gameplay data");
                Data::LoadData(configuration.columnsCount, configuration.mapSize);

                DevOut("Generating map for currentMapArea");
                MapGeneration::GenerateMap(Data::currentMapArea);

                DevOut("Running game loop");
                GameLoop::Run();

                DevOut("Game has ended");
        }


}
