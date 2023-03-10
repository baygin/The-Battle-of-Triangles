#include "../../../include/Game/StartScreen/Menu.hpp"

void Game::StartScreen::Menu::SetItem(MenuItem *Item)
{
    std::list<StartScreen::MenuItem *>::iterator Iterator = this->Items.begin();
    this->Items.insert(Iterator, Item);
}

std::list<Game::StartScreen::MenuItem *> Game::StartScreen::Menu::GetItems()
{
    return this->Items;
}

void Game::StartScreen::Menu::SetSelectedMenu(MenuItem *SelectedMenu)
{
    std::list<Game::StartScreen::MenuItem *>::iterator Iterator = this->Items.begin();

    for (; Iterator != this->Items.end(); ++Iterator)
    {
        (*Iterator)->SetColorGreen(255);
    }

    SelectedMenu->SetColorGreen(200);

    this->SelectedMenu = SelectedMenu;
}

Game::StartScreen::MenuItem *Game::StartScreen::Menu::GetSelectedMenu()
{
    return this->SelectedMenu;
}

void Game::StartScreen::Menu::HandleKeydownEvent(SDL_Scancode Code)
{
    switch (Code)
    {
    case SDL_SCANCODE_UP:
        this->HandleKeydownUp();
        break;
    case SDL_SCANCODE_DOWN:
        this->HandleKeydownDown();
        break;
    case SDL_SCANCODE_KP_ENTER:
    case SDL_SCANCODE_RETURN:
        this->HandleKeydownEnter();
        break;
    case SDL_SCANCODE_BACKSPACE:
        this->HandleKeydownBackspace();
        break;
    default:
        break;
    }
}

void Game::StartScreen::Menu::HandleKeydownUp()
{
    std::list<Game::StartScreen::MenuItem *>::iterator Iterator = std::find(this->Items.begin(), this->Items.end(), this->SelectedMenu);
    std::list<Game::StartScreen::MenuItem *>::iterator Next = std::next(Iterator, 1);

    if (Next != this->Items.end())
    {
        this->SetSelectedMenu(*Next);
    }
}

void Game::StartScreen::Menu::HandleKeydownDown()
{
    std::list<Game::StartScreen::MenuItem *>::iterator Iterator = std::find(this->Items.begin(), this->Items.end(), this->SelectedMenu);
    std::list<Game::StartScreen::MenuItem *>::iterator Prev = std::prev(Iterator, 1);

    if (Prev != this->Items.end())
    {
        this->SetSelectedMenu(*Prev);
    }
}

void Game::StartScreen::Menu::HandleKeydownEnter()
{
    if (strcmp(this->SelectedMenu->GetText(), "Quit") == 0)
    {
        this->GetSettings()->SetRunning(false);
    }
}

void Game::StartScreen::Menu::HandleKeydownBackspace()
{
    printf("Backspace\n");
}