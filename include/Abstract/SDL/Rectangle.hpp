#ifndef ABSTRACT_SDL_RECTANGLE_H
#define ABSTRACT_SDL_RECTANGLE_H

#include "SDL2/SDL_rect.h"

namespace Abstract
{
    namespace SDL
    {
        class Rectangle
        {
        protected:
            SDL_Rect Rect;

        public:
            int GetX()
            {
                return this->Rect.x;
            }

            void SetX(int X)
            {
                this->Rect.x = X;
            }

            int GetY()
            {
                return this->Rect.y;
            }

            void SetY(int Y)
            {
                this->Rect.y = Y;
            }

            void SetRect(SDL_Rect Rect)
            {
                this->Rect = Rect;
            }
            
            SDL_Rect GetRect()
            {
                return this->Rect;
            }

            int GetHeight()
            {
                return this->Rect.h;
            }

            void SetHeight(int Height)
            {
                this->Rect.h = Height;
            }

            int GetWidth()
            {
                return this->Rect.w;
            }

            void SetWidth(int Width)
            {
                this->Rect.w = Width;
            }
        };
    }
}

#endif // !ABSTRACT_SDL_RECTANGLE_H