#ifndef GAME_EVENT_KEYS_H
#define GAME_EVENT_KEYS_H

#include <SDL2/SDL.h>

namespace Game
{
    namespace Event
    {
        enum class Keys
        {
            W = SDL_SCANCODE_W,
            S = SDL_SCANCODE_S,
            D = SDL_SCANCODE_D,
            A = SDL_SCANCODE_A,
            Enter = SDL_SCANCODE_RETURN,
            Escape = SDL_SCANCODE_ESCAPE,
            Space = SDL_SCANCODE_SPACE,
            Up = SDL_SCANCODE_UP,
            Down = SDL_SCANCODE_DOWN,
            Right = SDL_SCANCODE_RIGHT,
            Left = SDL_SCANCODE_LEFT,
        };
    }
}

#endif // !GAME_EVENT_KEYS_H