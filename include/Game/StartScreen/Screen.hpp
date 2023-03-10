#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "../../Abstract/Scale.hpp"
#include "../../Abstract/State/Settings.hpp"
#include "../State/Settings.hpp"
#include "EdgeTriangle.hpp"
#include "Menu.hpp"
#include "MenuCursor.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <algorithm>
#include <iostream>

namespace Game
{
    namespace StartScreen
    {
        class Screen : public Abstract::Scale,
                       public Abstract::State::Settings

        {
        private:
            SDL_Renderer *Renderer;
            std::list<StartScreen::EdgeTriangle> EdgeTriangles;
            StartScreen::Menu *Menu;
            StartScreen::MenuCursor MenuCursor;

            void HandleKeydownUp();
            void HandleKeydownDown();
            void HandleKeydownEnter();
            void HandleKeydownBackspace();

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

            void HandleKeydownEvent(SDL_Scancode Code);
        };
    }
}

#endif // !START_SCREEN_H