#ifndef ABSTRACT_SDL_TEXT_H
#define ABSTRACT_SDL_TEXT_H

#include "Renderable.hpp"

#include "SDL2/SDL_ttf.h"

namespace Abstract
{
    namespace SDL
    {
        class Text : public Renderable
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

            void SetColorRed(Uint8 Color)
            {
                this->Color.r = Color;
            }

            Uint8 GetColorRed()
            {
                return this->Color.r;
            }

            void SetColorBlue(Uint8 Color)
            {
                this->Color.b = Color;
            }

            Uint8 GetColorBlue()
            {
                return this->Color.b;
            }

            void SetColorGreen(Uint8 Color)
            {
                this->Color.g = Color;
            }

            Uint8 GetColorGreen()
            {
                return this->Color.g;
            }
        };
    }
}

#endif // !ABSTRACT_SDL_TEXT_H