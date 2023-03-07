#include "../../include/StartScreen/EdgeTriangle.hpp"

StartScreen::EdgeTriangle::~EdgeTriangle()
{
    if (this->Texture)
    {
        SDL_DestroyTexture(this->Texture);
    }

    if (this->Surface)
    {
        SDL_FreeSurface(this->Surface);
    }
}

void StartScreen::EdgeTriangle::Render()
{
    SDL_RenderCopyEx(this->Renderer, this->Texture, NULL, &this->Rect, this->Angle, 0, SDL_FLIP_NONE);
}