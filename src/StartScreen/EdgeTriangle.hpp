#include "../../include/StartScreen/EdgeTriangle.hpp"

StartScreen::EdgeTriangle::~EdgeTriangle()
{
    SDL_DestroyTexture(this->Texture);
    SDL_FreeSurface(this->Surface);
}

void StartScreen::EdgeTriangle::Render()
{
    SDL_RenderCopyEx(this->Renderer, this->Texture, NULL, &this->Rect, this->Angle, 0, SDL_FLIP_NONE);
}