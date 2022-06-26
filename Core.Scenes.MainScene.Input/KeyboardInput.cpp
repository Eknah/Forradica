#include "KeyboardInput.h"

namespace Forradica
{

        void KeyboardInput::DoKeyDown(SDL_Keycode key)
        {
                pressedKeys.insert(key);
        }
        void KeyboardInput::DoKeyUp(SDL_Keycode key)
        {
                pressedKeys.erase(key);
        }

}
