#ifndef GAME_EVENT_KEYBOARD_H
#define GAME_EVENT_KEYBOARD_H

#include <SDL2/SDL.h>
#include "Keys.hpp"

namespace Game
{
    namespace Event
    {
        class Keyboard
        {
        private:
            Game::Event::Keys Key;
            void (*Function)();

        public:
            Keyboard(Game::Event::Keys Key);
            Game::Event::Keys GetKey();
            void SetFunction(void(*Function)());
            void Handle();
        };
    }
}

#endif // !GAME_EVENT_KEYBOARD_H