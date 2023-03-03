#ifndef ABSTRACT_SDL_RENDERABLE_H
#define ABSTRACT_SDL_RENDERABLE_H

#include "SDL_Rectangle.hpp"

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

namespace Abstract
{
    class SDL_Renderable : public SDL_Rectangle
    {
    protected:
        SDL_Renderer *Renderer;
        SDL_Texture *Texture;
        SDL_Surface *Surface;

    public:
        ~SDL_Renderable()
        {
            SDL_FreeSurface(this->Surface);
            SDL_DestroyTexture(this->Texture);
            SDL_DestroyRenderer(this->Renderer);
        }

        void SetRenderer(SDL_Renderer *Renderer)
        {
            this->Renderer = Renderer;
        }

        SDL_Renderer *GetRenderer()
        {
            return this->Renderer;
        }

        SDL_Texture *GetTexture()
        {
            return this->Texture;
        }

        void SetTexture(SDL_Texture *Texture)
        {
            this->Texture = Texture;
        }

        SDL_Surface *GetSurface()
        {
            return this->Surface;
        }

        void SetSurface(SDL_Surface *Surface)
        {
            this->Surface = Surface;
        }

        virtual void Render()
        {
            SDL_RenderCopy(this->Renderer, this->Texture, NULL, &this->Rect);
        }
    };
}

#endif // !ABSTRACT_SDL_RENDERABLE_H