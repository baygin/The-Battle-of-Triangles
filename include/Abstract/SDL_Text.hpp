#ifndef ABSTRACT_SDL_TEXT_H
#define ABSTRACT_SDL_TEXT_H

#include "SDL_Renderable.hpp"

#include "SDL2/SDL_ttf.h"

namespace Abstract
{
    class SDL_Text : public SDL_Renderable
    {
    protected:
        char *Text;
        TTF_Font *Font;
        SDL_Color Color = {255, 255, 255};

    public:
        void SetFont(TTF_Font *Font)
        {
            this->Font = Font;
        }

        TTF_Font *GetFont()
        {
            return this->Font;
        }

        void SetColor(SDL_Color Color)
        {
            this->Color = Color;
        }

        SDL_Color GetColor()
        {
            return this->Color;
        }

        void SetText(char *Text)
        {
            this->Text = Text;
        }

        char *GetText()
        {
            return this->Text;
        }

        void CreateTextureFromText()
        {
            this->SetSurface(TTF_RenderText_Solid(this->Font, this->Text, this->Color));
            this->SetTexture(SDL_CreateTextureFromSurface(this->Renderer, this->Surface));
        }
    };
}

#endif // !ABSTRACT_SDL_TEXT_H