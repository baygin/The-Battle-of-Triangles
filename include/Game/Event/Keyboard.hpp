#ifndef GAME_EVENT_KEYBOARD_H
#define GAME_EVENT_KEYBOARD_H

#include <SDL2/SDL.h>

namespace Game
{
    namespace Event
    {
        class Keyboard
        {
        private:
            SDL_Scancode Code;
            void (*Function)();

        public:
            void SetCode(SDL_Scancode Code);
            SDL_Scancode GetCode();
            void SetFunction(void (*Function)());
            void Handle(void * Game);
        };
    }
}

#endif // !GAME_EVENT_KEYBOARD_H