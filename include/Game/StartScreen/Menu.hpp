#ifndef START_SCREEN_MENU_H
#define START_SCREEN_MENU_H

#include "MenuItem.hpp"
#include "../../Abstract/Visibility.hpp"

#include <list>

namespace Game
{
    namespace StartScreen
    {
        class Menu : public Abstract::Visibility
        {
        private:
            std::list<Game::StartScreen::MenuItem *> Items;
            MenuItem *SelectedMenu;
            MenuItem *CursorIn;

        public:
            void SetItem(MenuItem *Item)
            {
                std::list<StartScreen::MenuItem *>::iterator Iterator = this->Items.begin();
                this->Items.insert(Iterator, Item);
            }

            std::list<StartScreen::MenuItem *> GetItems()
            {
                return this->Items;
            }

            void SetSelectedMenu(MenuItem *SelectedMenu)
            {
                std::list<StartScreen::MenuItem *>::iterator Iterator = this->Items.begin();

                for (; Iterator != this->Items.end(); ++Iterator)
                {
                    (*Iterator)->SetColorGreen(255);
                }

                SelectedMenu->SetColorGreen(200);

                this->SelectedMenu = SelectedMenu;
            }

            MenuItem *GetSelectedMenu()
            {
                return this->SelectedMenu;
            }

            void SetCursorIn(MenuItem *Item)
            {
                this->CursorIn = Item;
            }

            MenuItem *GetCursorIn()
            {
                return this->CursorIn;
            }
        };
    }
}

#endif // !START_SCREEN_MENU_H