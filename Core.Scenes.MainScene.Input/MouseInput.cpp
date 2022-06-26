#include "MouseInput.h"

namespace Forradica
{

        void MouseInput::Reset()
        {
                firedButtons.clear();
        }

        void MouseInput::DoMouseDown(Uint8 button)
        {
                pressedButtons.insert(button);
                firedButtons.insert(button);
        }

        void MouseInput::DoMouseUp(Uint8 button)
        {
                pressedButtons.erase(button);
        }

}
