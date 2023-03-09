#ifndef GAME_H
#define GAME_H

#include "./StartScreen/Screen.hpp"

namespace Game
{
    class Game
    {
        void *CurrentScreen;
        StartScreen::Screen *StartScreen;

    public:
        Game();

        void *GetCurrentScreen()
        {
            return this->CurrentScreen;
        }

        void SetCurrentScreen(void *CurrentScreen)
        {
            this->CurrentScreen = CurrentScreen;
        }

        void ShowStartScreen()
        {
            this->SetCurrentScreen(this->StartScreen);
        }

        void Render()
        {
            this->CurrentScreen->Render();
        }
    };
} // namespace GAME

#endif // !GAME_H