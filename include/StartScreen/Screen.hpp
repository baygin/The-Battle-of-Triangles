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
        std::list<StartScreen::EdgeTriangle> EdgeTriangles;

    public:
        ~Screen();
        
        void SetRenderer(SDL_Renderer *Renderer);
        SDL_Renderer *GetRenderer();

        void InitEdgeTriangles();
        void Render();
    };
}

#endif // !START_SCREEN_H