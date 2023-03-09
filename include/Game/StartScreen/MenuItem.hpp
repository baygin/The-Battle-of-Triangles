#ifndef START_SCREEN_MENU_ITEM_H
#define START_SCREEN_MENU_ITEM_H

#include "../../Abstract/SDL/Text.hpp"
#include "../../Abstract/Selectable.hpp"

#include <list>

namespace Game
{
    namespace StartScreen
    {
        class MenuItem : public Abstract::SDL::Text,
                         public Abstract::Selectable
        {
        private:
            std::list<StartScreen::MenuItem> SubItems;

        public:
            void AddSubItem(MenuItem *Item)
            {
                std::list<StartScreen::MenuItem>::iterator Iterator = this->SubItems.begin();
                this->SubItems.insert(Iterator, *Item);
            }

            std::list<StartScreen::MenuItem> GetSubItems()
            {
                return this->SubItems;
            }
        };
    }
}

#endif // !START_SCREEN_MENU_ITEM_H