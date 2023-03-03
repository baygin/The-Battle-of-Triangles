#ifndef ABSTRACT_SDL_IMAGE_H
#define ABSTRACT_SDL_IMAGE_H

#include "SDL_Renderable.hpp"
#include "SDL2/SDL_ttf.h"

namespace Abstract
{
    class SDL_Image : public SDL_Renderable
    {
    protected:
        char *ImagePath;

    public:
        void SetImagePath(const char *ImagePath)
        {
            this->ImagePath = (char *)ImagePath;
        }

        char *GetImagePath()
        {
            return this->ImagePath;
        }

        void CreateTextureFromImagePath()
        {
            this->SetSurface(IMG_Load(this->ImagePath));
            this->SetTexture(SDL_CreateTextureFromSurface(this->Renderer, this->GetSurface()));
        }
    };
}

#endif // !ABSTRACT_SDL_IMAGE_H