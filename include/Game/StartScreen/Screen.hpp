#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "../../Abstract/Scale.hpp"
#include "EdgeTriangle.hpp"
#include "Menu.hpp"
#include "MenuCursor.hpp"
#include "../State.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <iostream>

namespace Game
{
    namespace StartScreen
    {
        class Screen : public Abstract::Scale
        {
        private:
            SDL_Renderer *Renderer;
            std::list<StartScreen::EdgeTriangle> EdgeTriangles;
            StartScreen::Menu *Menu;
            StartScreen::MenuCursor MenuCursor;
            Game::State State;

        public:
            ~Screen();

            void SetRenderer(SDL_Renderer *Renderer);
            SDL_Renderer *GetRenderer();

            void Init();
            void InitEdgeTriangles();
            void InitMenu();
            void InitMenuCursor();
            void Render();
            StartScreen::Menu *GetMenu();
        };
    }
}

#endif // !START_SCREEN_H