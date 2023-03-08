#include "../../include/StartScreen/EdgeTriangle.hpp"

StartScreen::EdgeTriangle::~EdgeTriangle()
{
}

void StartScreen::EdgeTriangle::Render()
{
    SDL_RenderCopyEx(this->Renderer, this->Texture, NULL, &this->Rect, this->Angle, 0, SDL_FLIP_NONE);
}