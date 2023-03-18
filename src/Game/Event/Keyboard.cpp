#include "../../../include/Game/Event/Keyboard.hpp"

void Game::Event::Keyboard::SetCode(SDL_Scancode Code)
{
    this->Code = Code;
}

SDL_Scancode Game::Event::Keyboard::GetCode()
{
    return this->Code;
}

void Game::Event::Keyboard::SetFunction(void (*Function)())
{
    this->Function = Function;
};

void Game::Event::Keyboard::Handle(void *Game)
{
    if (this->Function)
    {
        this->Function();
    }
}