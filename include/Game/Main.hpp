#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include "./StartScreen/Screen.hpp"
#include "../Abstract/Scale.hpp"

namespace Game
{
    class Main : public Abstract::Scale
    {
        int FPS = 60;
        int FrameDelay = 1000 / 60;
        int FrameTime;
        Uint32 FrameStart;
        bool Running = true;
        SDL_Window *Window;
        SDL_Renderer *Renderer;
        SDL_Event SDLEvent;

        /**
         * @brief Screens
         *
         */
        void *CurrentScreen;
        StartScreen::Screen *StartScreen;

    private:
        void Delay();
        void RenderCurrentScreen();

    public:
        Main();
        ~Main();
        void *GetCurrentScreen();
        void SetCurrentScreen(void *CurrentScreen);
        void ShowStartScreen();
        void Init();
        void Render();
        void HandleKeyboardEvent();
    };
} // namespace Main

#endif // !GAME_MAIN_H