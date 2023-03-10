#include "../../include/Game/Main.hpp"

Game::Main::Main()
{
    this->Settings = new Game::State::Settings();
}

Game::Main::~Main()
{
    SDL_DestroyWindow(this->Window);
    SDL_DestroyRenderer(this->Renderer);

    delete this->StartScreen;
    delete this->Settings;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

void Game::Main::Delay()
{
    this->FrameTime = SDL_GetTicks() - this->FrameStart;

    if (this->FrameDelay > this->FrameTime)
    {
        SDL_Delay(this->FrameDelay - this->FrameTime);
    }
}

void *Game::Main::GetCurrentScreen()
{
    return this->CurrentScreen;
}

void Game::Main::SetCurrentScreen(void *CurrentScreen)
{
    this->CurrentScreen = CurrentScreen;
}

void Game::Main::ShowStartScreen()
{
    this->SetCurrentScreen(this->StartScreen);
}

void testp()
{
    printf("down\n");
}

void Game::Main::Init()
{
    this->Window = SDL_CreateWindow("The Battle of Triangles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->Width, this->Height, 0);
    this->Renderer = SDL_CreateRenderer(this->Window, -1, 0);

    this->StartScreen = new StartScreen::Screen();
    this->StartScreen->SetRenderer(this->Renderer);
    this->StartScreen->SetHeight(this->Height);
    this->StartScreen->SetWidth(this->Width);
    this->StartScreen->SetSettings(this->Settings);
    this->StartScreen->Init();

    this->CurrentScreen = this->StartScreen;
}

void Game::Main::RenderCurrentScreen()
{
    if (this->CurrentScreen == this->StartScreen)
    {
        this->StartScreen->Render();
    }
}

void Game::Main::Render()
{
    while (this->Settings->GetRunning())
    {
        this->HandleKeyboardEvent();
        SDL_RenderClear(this->Renderer);
        this->RenderCurrentScreen();
        SDL_RenderPresent(this->Renderer);
        this->Delay();
    }
}

void Game::Main::HandleKeyboardEvent()
{
    SDL_PollEvent(&this->SDLEvent);

    if (!this->SDLEvent.key.keysym.scancode)
    {
        return;
    }

    if (this->SDLEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
    {
        this->Settings->SetRunning(false);
        return;
    }

    if (this->SDLEvent.type == SDL_KEYDOWN)
    {
        if (this->CurrentScreen == this->StartScreen)
        {
            this->StartScreen->HandleKeydownEvent(this->SDLEvent.key.keysym.scancode);
        }
    }
}
