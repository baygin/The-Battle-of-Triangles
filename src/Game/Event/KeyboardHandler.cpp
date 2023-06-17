#include "../../../include/Game/Event/KeyboardHandler.hpp"

Game::Event::KeyboardHandler::KeyboardHandler()
{
}

void Game::Event::KeyboardHandler::Handle(Game::Event::Keys Key)
{
    std::list<Event::Keyboard *>::iterator Iterator = this->Events.begin();

    for (; Iterator != this->Events.end(); ++Iterator)
    {
        if((*Iterator)->GetKey() == Key) {
            (*Iterator)->Handle();
        }
    }
}

void Game::Event::KeyboardHandler::AddEvent(Game::Event::Keyboard *Event)
{
    std::list<Event::Keyboard *>::iterator Iterator = this->Events.begin();
    this->Events.insert(Iterator, Event);
}