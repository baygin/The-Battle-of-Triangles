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
        std::list<MenuItem> *Items;
        std::list<MenuItem>::iterator *ItemsIterator;

    public:
        SetItem(MenuItem *Item)
        {
            this->Items->insert(this->ItemsIterator, Item);
        }

        RemoveItemByText(char *Text)
        {
            auto it std::find_if(this->Items.begin(), this->Items.end(), [&](const MenuItem Item)
                                 { return Item->GetText() == Text; });
        }
    };
}

#endif // !START_SCREEN_MENU_H