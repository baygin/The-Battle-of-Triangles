#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SDL2/SDL.h>
#include <list>
#include <algorithm>

namespace Game
{
    class State
    {
    protected:
        std::list<SDL_Window *> _SDL_Window;
        std::list<SDL_Renderer *> _SDL_Renderer;
        std::list<SDL_Texture *> _SDL_Texture;
        std::list<SDL_Surface *> _SDL_Surface;

    public:
        ~State()
        {
            /**
             * @brief Destroy window list if exists
             */
            std::list<SDL_Window *>::iterator WindowIterator = this->_SDL_Window.begin();

            for (; WindowIterator != this->_SDL_Window.end(); ++WindowIterator)
            {
                SDL_DestroyWindow((*WindowIterator));
            }

            /**
             * @brief Destroy renderer list if exists
             */

            std::list<SDL_Renderer *>::iterator RendererIterator = this->_SDL_Renderer.begin();

            for (; RendererIterator != this->_SDL_Renderer.end(); ++RendererIterator)
            {
                SDL_DestroyRenderer((*RendererIterator));
            }

            /**
             * @brief Destroy texture list if exists
             */

            std::list<SDL_Texture *>::iterator TextureIterator = this->_SDL_Texture.begin();

            for (; TextureIterator != this->_SDL_Texture.end(); ++TextureIterator)
            {
                SDL_DestroyTexture((*TextureIterator));
            }

            /**
             * @brief Destroy surface list if exists
             */

            std::list<SDL_Surface *>::iterator SurfaceIterator = this->_SDL_Surface.begin();

            for (; SurfaceIterator != this->_SDL_Surface.end(); ++SurfaceIterator)
            {
                SDL_FreeSurface((*SurfaceIterator));
            }
        }

        void SetSDLWindow(SDL_Window *Window)
        {
            std::list<SDL_Window *>::iterator Iterator = this->_SDL_Window.begin();
            this->_SDL_Window.insert(Iterator, Window);
        }

        void FreeSDLWindow(SDL_Window *Window)
        {
            bool Exists = (std::find(this->_SDL_Window.begin(), this->_SDL_Window.end(), Window) != this->_SDL_Window.end());

            if (Exists)
            {
                this->_SDL_Window.remove(Window);
                SDL_DestroyWindow(Window);
                Window = NULL;
            }
        }

        void SetSDLRenderer(SDL_Renderer *Renderer)
        {
            std::list<SDL_Renderer *>::iterator Iterator = this->_SDL_Renderer.begin();
            this->_SDL_Renderer.insert(Iterator, Renderer);
        }

        void FreeSDLRenderer(SDL_Renderer *Renderer)
        {
            bool Exists = (std::find(this->_SDL_Renderer.begin(), this->_SDL_Renderer.end(), Renderer) != this->_SDL_Renderer.end());

            if (Exists)
            {
                this->_SDL_Renderer.remove(Renderer);
                SDL_DestroyRenderer(Renderer);
                Renderer = NULL;
            }
        }

        void SetSDLTexture(SDL_Texture *Texture)
        {
            std::list<SDL_Texture *>::iterator Iterator = this->_SDL_Texture.begin();
            this->_SDL_Texture.insert(Iterator, Texture);
        }

        void FreeSDLTexture(SDL_Texture *Texture)
        {
            bool Exists = (std::find(this->_SDL_Texture.begin(), this->_SDL_Texture.end(), Texture) != this->_SDL_Texture.end());

            if (Exists)
            {
                this->_SDL_Texture.remove(Texture);
                SDL_DestroyTexture(Texture);
                Texture = NULL;
            }
        }

        void SetSDLSurface(SDL_Surface *Surface)
        {
            std::list<SDL_Surface *>::iterator Iterator = this->_SDL_Surface.begin();
            this->_SDL_Surface.insert(Iterator, Surface);
        }

        void FreeSDLSurface(SDL_Surface *Surface)
        {
            bool Exists = (std::find(this->_SDL_Surface.begin(), this->_SDL_Surface.end(), Surface) != this->_SDL_Surface.end());

            if (Exists)
            {
                this->_SDL_Surface.remove(Surface);
                SDL_FreeSurface(Surface);
                Surface = NULL;
            }
        }
    };
}

#endif // !GAME_STATE_H