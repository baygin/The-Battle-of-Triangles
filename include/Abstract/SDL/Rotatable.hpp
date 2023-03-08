#ifndef ABSTRACT_SDL_ROTATABLE_H
#define ABSTRACT_SDL_ROTATABLE_H

#include "SDL2/SDL_rect.h"

namespace Abstract
{
    namespace SDL
    {
        class Rotatable
        {
        protected:
            float Angle;

        public:
            float GetAngle()
            {
                return this->Angle;
            }

            void SetAngle(float Angle)
            {
                this->Angle = Angle;
            }
        };
    }
}

#endif // !ABSTRACT_SDL_ROTATABLE_H