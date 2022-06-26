#include "ImageResources.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <filesystem>
#include "Core/SDL.h"
#include "Convenience/SDLDeleter.h"
#include "Convenience/GetHash.h"
#include "Convenience/Tools.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{
        void ImageResources::LoadImages(std::string imageResourcesPath, std::string imageNameExtension)
        {
                DevOut("Creating image resources loading path");
                auto filePath = std::string().append(SDL_GetBasePath()).append(imageResourcesPath);
                std::filesystem::recursive_directory_iterator entries = decltype(entries) {filePath.c_str()};

                DevOut("Iterating through all images in path");
                for (auto& file : entries)
                {
                        DevOut("Creating full image file name");
                        auto fullName = file.path().filename().string();

                        DevOut("Creating image file name without extension");
                        auto name = fullName.substr(0, fullName.find("."));

                        DevOut("Check if file is directory or has incorrect file extension, then go to next image");
                        if (file.is_directory() || imageNameExtension != Tools::Right(fullName, imageNameExtension.length())) continue;

                        DevOut("Creating image surface");
                        std::unique_ptr<SDL_Surface, SDLDeleter> surface = {IMG_Load(file.path().string().c_str()), SDLDeleter()};

                        DevOut("Creating image texture");
                        std::unique_ptr<SDL_Texture, SDLDeleter> texture = {SDL_CreateTextureFromSurface(SDL::renderer.get(), surface.get()), SDLDeleter()};

                        DevOut("Get image name hash");
                        int hash = GetHash(name);

                        DevOut("Store image texture in images-field");
                        images[hash] = std::move(texture);
                }

        }

        Size ImageResources::GetImageSize(int imageNameHash)
        {
                Size result;
                SDL_QueryTexture(images.at(imageNameHash).get(), nullptr, nullptr, &result.width, &result.height);
                return result;
        }
}
