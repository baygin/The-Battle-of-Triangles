#include "../../../include/Game/Event/Keyboard.hpp"

Game::Event::Keyboard::Keyboard(Game::Event::Keys Key)
{
    this->Key = Key;
}

Game::Event::Keys Game::Event::Keyboard::GetKey()
{
    return this->Key;
}

void Game::Event::Keyboard::Handle()
{
    if (this->Function == NULL)
    {
        return;
    }

    this->Function();
}

void Game::Event::Keyboard::SetFunction(void (*Function)())
{
    this->Function = Function;
}