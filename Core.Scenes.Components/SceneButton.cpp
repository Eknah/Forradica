#include "SceneButton.h"
#include "Resources/ImageResources.h"
#include "Convenience/GetHash.h";
#include "Convenience/Cast.h";
#include "Convenience/Tools.h";

namespace Forradica
{

        FRectangle SceneButton::GetFBounds()
        {
                auto canvasSize = Tools::GetCanvasSize();
                auto imageSize = ImageResources::GetImageSize(GetHash("SceneButton"));
                auto ratio = Cast::ToFloat(imageSize.height)/imageSize.width*Tools::GetAspectRatio();

                FRectangle bounds;
                bounds.width = geometry.width;
                bounds.height = bounds.width*ratio;
                bounds.x = geometry.x - bounds.width/2;
                bounds.y = geometry.y - bounds.height/2;

                return bounds;
        }

}
