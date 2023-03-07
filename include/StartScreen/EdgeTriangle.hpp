#ifndef START_SCREEN_EDGE_TRIANGLE_H
#define START_SCREEN_EDGE_TRIANGLE_H

#include "../Abstract/SDL_Image.hpp"
#include "../Abstract/SDL_Rotatable.hpp"

namespace StartScreen
{
    class EdgeTriangle : public Abstract::SDL_Image,
                         public Abstract::SDL_Rotatable
    {
    public:
        ~EdgeTriangle();
        void Render();
    };
}

#endif // !START_SCREEN_EDGE_TRIANGLE_H