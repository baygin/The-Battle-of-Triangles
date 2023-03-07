#ifndef START_SCREEN_MENU_ITEM_H
#define START_SCREEN_MENU_ITEM_H

#include "../Abstract/SDL/Text.hpp"
#include "../Abstract/Selectable.hpp"

namespace StartScreen
{
    class MenuItem : public Abstract::SDL::Text,
                     public Abstract::Selectable
    {
    };
}

#endif // !START_SCREEN_MENU_ITEM_H