#include "../../../include/Game/Event/Handler.hpp"

Game::Event::Handler::Handler()
{
}

void Game::Event::Handler::Handle(void *Game)
{
    SDL_PollEvent(&this->SDLEvent);

    if (this->SDLEvent.key.keysym.scancode)
    {
        std::list<Event::Keyboard *>::iterator Iterator = this->KeyboardEvents.begin();

        for (; Iterator != this->KeyboardEvents.end(); ++Iterator)
        {
            if (this->SDLEvent.key.keysym.scancode == (*Iterator)->GetCode())
            {
                (*Iterator)->Handle(Game);
            }
        }
    }
}

void Game::Event::Handler::AddKeyboardEvent(Event::Keyboard *KeyboardEvent)
{
    std::list<Event::Keyboard *>::iterator Iterator = this->KeyboardEvents.begin();
    this->KeyboardEvents.insert(Iterator, KeyboardEvent);
}