#ifndef GAME_START_SCREEN_MENU_H
#define GAME_START_SCREEN_MENU_H

#include "MenuItem.hpp"
#include "../../Abstract/Visibility.hpp"
#include "../../Abstract/State/Settings.hpp"

#include <list>
#include <algorithm>

namespace Game
{
    namespace StartScreen
    {
        class Menu : public Abstract::Visibility,
                     public Abstract::State::Settings
        {
        private:
            std::list<Game::StartScreen::MenuItem *> Items;
            MenuItem *SelectedMenu;

        public:
            void SetItem(MenuItem *Item);
            std::list<StartScreen::MenuItem *> GetItems();
            void SetSelectedMenu(MenuItem *SelectedMenu);
            MenuItem *GetSelectedMenu();
            void HandleKeydownEvent(SDL_Scancode Code);
            void HandleKeydownUp();
            void HandleKeydownDown();
            void HandleKeydownEnter();
            void HandleKeydownBackspace();
        };
    }
}

#endif // !GAME_START_SCREEN_MENU_H