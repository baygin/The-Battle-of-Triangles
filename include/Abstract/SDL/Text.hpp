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
                if (this->Surface)
                {
                    SDL_FreeSurface(this->Surface);
                }

                if (this->Texture)
                {
                    SDL_DestroyTexture(this->Texture);
                }

                this->Surface = TTF_RenderText_Solid(this->Font, this->Text, this->Color);
                this->Texture = SDL_CreateTextureFromSurface(this->Renderer, this->Surface);
            }

            void SetColorRed(Uint8 Color)
            {
                if (this->Color.r != Color)
                {
                    this->Color.r = Color;
                    this->CreateTextureFromText();
                }
            }

            Uint8 GetColorRed()
            {
                return this->Color.r;
            }

            void SetColorBlue(Uint8 Color)
            {
                if (this->Color.b != Color)
                {
                    this->Color.b = Color;
                    this->CreateTextureFromText();
                }
            }

            Uint8 GetColorBlue()
            {
                return this->Color.b;
            }

            void SetColorGreen(Uint8 Color)
            {
                if (this->Color.g != Color)
                {
                    this->Color.g = Color;
                    this->CreateTextureFromText();
                }
            }

            Uint8 GetColorGreen()
            {
                return this->Color.g;
            }
        };
    }
}

#endif // !ABSTRACT_SDL_TEXT_H