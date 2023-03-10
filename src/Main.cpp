#include "../include/Main.hpp"

int main()
{
    int Width = 800;
    int Height = 600;
    
    Game::Main *tBoT = new Game::Main();
    tBoT->SetHeight(Height);
    tBoT->SetWidth(Width);
    tBoT->Init();
    tBoT->Render();

    return EXIT_SUCCESS;
}