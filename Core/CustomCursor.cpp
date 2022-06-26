#include "CustomCursor.h"
#include "Convenience/GetHash.h"
#include "Core.Drawing/Draw.h"
#include "Convenience/Tools.h"
#include "Convenience.Development/Development.h"

namespace Forradica
{

        void CustomCursor::Initialize(float _cursorSize)
        {
                DevOut("Setting cursor size from configuration");
                cursorSize = _cursorSize;

                DevOut("Hiding default Windows-cursor");
                SDL_ShowCursor(0);
        }

        void CustomCursor::Reset()
        {
                currentCursorType = CursorTypes::Default;
        }

        void CustomCursor::Render()
        {
                auto mousePosition = Tools::GetMousePosition();

                std::string imageName;

                switch (currentCursorType)
                {
                case CursorTypes::Default:
                        imageName = "CursorDefault";
                        break;
                case CursorTypes::Hand:
                        imageName = "CursorHand";
                        break;
                }

                Draw::Image(GetHash(imageName), mousePosition.x, mousePosition.y, cursorSize, 0, false);
        }

}
