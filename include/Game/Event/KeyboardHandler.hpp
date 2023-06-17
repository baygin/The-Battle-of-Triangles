#ifndef GAME_EVENT_KEYBOARD_HANDLER_H
#define GAME_EVENT_KEYBOARD_HANDLER_H

#include "Keyboard.hpp"
#include "Keys.hpp"

#include <SDL2/SDL.h>
#include <list>

namespace Game
{
    namespace Event
    {
        class KeyboardHandler
        {
        private:
            std::list<Game::Event::Keyboard *> Events;

        public:
            KeyboardHandler();
            void Handle(Game::Event::Keys Key);
            void AddEvent(Game::Event::Keyboard *Event);
        };
    }
}

#endif // !GAME_EVENT_KEYBOARD_HANDLER_H