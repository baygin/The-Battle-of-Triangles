#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "../Abstract/Scale.hpp"
#include "EdgeTriangle.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>

namespace StartScreen
{
    class Screen : public Abstract::Scale
    {
    private:
        SDL_Renderer *Renderer;

    public:
        std::list<StartScreen::EdgeTriangle> EdgeTriangles;
        ~Screen();
        void SetRenderer(SDL_Renderer *Renderer)
        {
            this->Renderer = Renderer;
        }

        SDL_Renderer *GetRenderer()
        {
            return this->Renderer;
        }

        void InitEdgeTriangles();
        void Render();
    };
}

#endif // !START_SCREEN_H