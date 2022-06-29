#include "FontResources.h"
#include "Convenience.Development/Development.h"
#include "Configuration/Configuration.h"

namespace Forradica
{
        void FontResources::InitializeTTF()
        {
                DevOut("Executing TTF_Init()");
                TTF_Init();
        }

        void FontResources::LoadFonts()
        {
                DevOut("Creating font resources path");
                char str[200];
                strcpy_s(str, SDL_GetBasePath());
                strcat_s(str, Configuration::defaultFontResourcePath.c_str());

                DevOut("Load and store default font");
                defaultFont = std::unique_ptr<TTF_Font, SDLDeleter>(TTF_OpenFont(str, 9), SDLDeleter());

                if (!defaultFont)
                    printf("TTF_OpenFont: %s\n", TTF_GetError());
        }

}
