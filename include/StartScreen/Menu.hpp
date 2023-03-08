#ifndef START_SCREEN_MENU_H
#define START_SCREEN_MENU_H

#include "MenuItem.hpp"
#include "../Abstract/Visibility.hpp"

#include <list>

namespace StartScreen
{
    class Menu : public Abstract::Visibility
    {
    private:
        std::list<StartScreen::MenuItem*> Items;
        MenuItem *SelectedMenu;
        MenuItem *CursorIn;

    public:
        void SetItem(MenuItem *Item)
        {
            std::list<StartScreen::MenuItem*>::iterator Iterator = this->Items.begin();
            this->Items.insert(Iterator, Item);
        }

        std::list<StartScreen::MenuItem*> GetItems()
        {
            return this->Items;
        }

        void SetSelectedMenu(MenuItem *SelectedMenu)
        {
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

#endif // !START_SCREEN_MENU_H