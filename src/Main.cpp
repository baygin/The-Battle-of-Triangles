#include "../include/Main.hpp"
#include <unistd.h>
#include <algorithm>
#include <list>

int main()
{
    int Width = 800;
    int Height = 600;

    SDL_Window *Window = SDL_CreateWindow("The Battle of Triangles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, 0);
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, 0);

    StartScreen::Screen *Screen = new StartScreen::Screen();
    Screen->SetRenderer(Renderer);
    Screen->SetHeight(Height);
    Screen->SetWidth(Width);

    Screen->Init();

    StartScreen::Menu *Menu = Screen->GetMenu();

    SDL_Event Event;
    int Loop = 1;

    while (Loop)
    {
        const int FPS = 60;
        const int FrameDelay = 1000 / FPS;

        Uint32 FrameStart;
        int FrameTime;

        SDL_PollEvent(&Event);

        if (Event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            Loop = 0;
        }

        if (Event.type == SDL_KEYDOWN && Event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
            std::list<StartScreen::MenuItem *> Items = Menu->GetItems();
            StartScreen::MenuItem *SelectedItem = Menu->GetSelectedMenu();

            std::list<StartScreen::MenuItem *>::iterator Iterator = std::find(Items.begin(), Items.end(), SelectedItem);

            std::list<StartScreen::MenuItem *>::iterator Prev = std::prev(Iterator, 1);

            if (Prev != Items.end())
            {
                Menu->SetSelectedMenu(*Prev);
            }
        }
        else if (Event.type == SDL_KEYDOWN && Event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
            std::list<StartScreen::MenuItem *> Items = Menu->GetItems();
            StartScreen::MenuItem *SelectedItem = Menu->GetSelectedMenu();

            std::list<StartScreen::MenuItem *>::iterator Iterator = std::find(Items.begin(), Items.end(), SelectedItem);

            std::list<StartScreen::MenuItem *>::iterator Prev = std::next(Iterator, 1);

            if (Prev != Items.end())
            {
                Menu->SetSelectedMenu(*Prev);
            }
        }

        SDL_RenderClear(Renderer);
        Screen->Render();
        SDL_RenderPresent(Renderer);

        FrameTime = SDL_GetTicks() - FrameStart;

        if (FrameDelay > FrameTime)
        {
            SDL_Delay(FrameDelay - FrameTime);
        }
    }

    delete Screen;

    SDL_Quit();
    IMG_Quit();

    return EXIT_SUCCESS;
}