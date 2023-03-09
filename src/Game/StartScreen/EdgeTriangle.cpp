#include "../../../include/Game/StartScreen/EdgeTriangle.hpp"

Game::StartScreen::EdgeTriangle::~EdgeTriangle()
{
}

void Game::StartScreen::EdgeTriangle::Render()
{
    SDL_RenderCopyEx(this->Renderer, this->Texture, NULL, &this->Rect, this->Angle, 0, SDL_FLIP_NONE);
}