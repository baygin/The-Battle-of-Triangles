#ifndef GAME_EVENT_HANDLER_H
#define GAME_EVENT_HANDLER_H

#include "Keyboard.hpp"

#include <SDL2/SDL.h>
#include <list>

namespace Game
{
    namespace Event
    {
        class Handler
        {
        private:
            SDL_Event SDLEvent;
            std::list<Game::Event::Keyboard *> KeyboardEvents;

        public:
            Handler();
            void Handle(void *Game);
            void AddKeyboardEvent(Event::Keyboard *KeyboardEvent);
        };
    }
}

#endif // !GAME_EVENT_HANDLER_H