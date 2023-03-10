#include "../../../include/Game/State/Settings.hpp"

void Game::State::Settings::SetRunning(bool Running)
{
    this->Running = Running;
}

bool Game::State::Settings::GetRunning()
{
    return this->Running;
}