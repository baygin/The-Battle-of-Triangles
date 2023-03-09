#ifndef START_SCREEN_EDGE_TRIANGLE_H
#define START_SCREEN_EDGE_TRIANGLE_H

#include "../../Abstract/SDL/Image.hpp"
#include "../../Abstract/SDL/Rotatable.hpp"

namespace Game
{
    namespace StartScreen
    {
        class EdgeTriangle : public Abstract::SDL::Image,
                             public Abstract::SDL::Rotatable
        {
        public:
            ~EdgeTriangle();
            void Render();
        };
    }
}

#endif // !START_SCREEN_EDGE_TRIANGLE_H