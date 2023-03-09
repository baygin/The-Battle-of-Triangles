#include "../../../include/Game/StartScreen/Screen.hpp"

Game::StartScreen::Screen::~Screen()
{
}

void Game::StartScreen::Screen::Init()
{
    this->InitEdgeTriangles();
    this->InitMenu();
    this->InitMenuCursor();
}

void Game::StartScreen::Screen::InitEdgeTriangles()
{
    // We will use again
    SDL_Rect Rect = {0, 0, 100, 100};

    EdgeTriangle *TopLeft = new EdgeTriangle();
    TopLeft->SetRenderer(this->Renderer);
    TopLeft->SetRect(Rect);
    TopLeft->SetX(-20);
    TopLeft->SetY(-20);
    TopLeft->SetAngle(0);
    TopLeft->SetImagePath("assets/images/start-screen/edge.png");
    TopLeft->CreateTextureFromImagePath();

    // We will use again
    SDL_Texture *Texture = TopLeft->GetTexture();
    SDL_Surface *Surface = TopLeft->GetSurface();

    EdgeTriangle *TopRight = new EdgeTriangle();
    TopRight->SetRenderer(this->Renderer);
    TopRight->SetRect(Rect);
    TopRight->SetX(this->Width - 80);
    TopRight->SetY(-20);
    TopRight->SetAngle(90);
    TopRight->SetTexture(Texture);
    TopRight->SetSurface(Surface);

    EdgeTriangle *BottomLeft = new EdgeTriangle();
    BottomLeft->SetRenderer(this->Renderer);
    BottomLeft->SetRect(Rect);
    BottomLeft->SetX(-20);
    BottomLeft->SetY(this->Height - 80);
    BottomLeft->SetAngle(270);
    BottomLeft->SetTexture(Texture);
    BottomLeft->SetSurface(Surface);

    EdgeTriangle *BottomRight = new EdgeTriangle();
    BottomRight->SetRenderer(this->Renderer);
    BottomRight->SetRect(Rect);
    BottomRight->SetX(this->Width - 80);
    BottomRight->SetY(this->Height - 80);
    BottomRight->SetAngle(180);
    BottomRight->SetTexture(Texture);
    BottomRight->SetSurface(Surface);

    std::list<EdgeTriangle>::iterator Iterator = this->EdgeTriangles.begin();

    this->EdgeTriangles.insert(Iterator, *TopLeft);
    this->EdgeTriangles.insert(Iterator, *TopRight);
    this->EdgeTriangles.insert(Iterator, *BottomLeft);
    this->EdgeTriangles.insert(Iterator, *BottomRight);
}

void Game::StartScreen::Screen::InitMenu()
{
    TTF_Init();
    TTF_Font *Neucha = TTF_OpenFont("assets/fonts/Neucha-Regular.ttf", 24);
    StartScreen::Menu *Menu = new StartScreen::Menu();

    const int FirstItemY = (this->Height / 2) - 100;
    const int X = (this->Height / 2) - 100;

    std::list<const char *> MenuList = {"Try tBot", "Choose Room", "Settings", "Quit"};
    std::list<const char *>::iterator MenuListIterator = MenuList.begin();

    for (int i = 0; MenuListIterator != MenuList.end(); ++MenuListIterator, i++)
    {
        MenuItem *Item = new MenuItem();
        Item->SetRect((SDL_Rect){(this->Height / 2) - 50, FirstItemY + (i * 100), 300, 70});
        Item->SetRenderer(this->Renderer);
        Item->SetText((char *)*MenuListIterator);
        Item->SetFont(Neucha);
        Item->CreateTextureFromText();
        Menu->SetItem(Item);

        if (i == 0)
        {
            Menu->SetSelectedMenu(Item);
        }
    }

    this->Menu = Menu;
}

void Game::StartScreen::Screen::InitMenuCursor()
{
    StartScreen::MenuCursor *Cursor = new StartScreen::MenuCursor();
    Cursor->SetRenderer(this->Renderer);
    Cursor->SetRect((SDL_Rect){-100, -100, 50, 50});
    Cursor->SetImagePath("assets/images/start-screen/cursor.png");
    Cursor->CreateTextureFromImagePath();

    this->MenuCursor = *Cursor;
}

void Game::StartScreen::Screen::Render()
{
    // Edge triangles
    std::list<EdgeTriangle>::iterator EdgeTrianglesIterator = this->EdgeTriangles.begin();

    for (; EdgeTrianglesIterator != EdgeTriangles.end(); ++EdgeTrianglesIterator)
    {
        EdgeTrianglesIterator->Render();
    }

    // Menu
    std::list<MenuItem *> MainMenuItems = this->Menu->GetItems();
    std::list<MenuItem *>::iterator MenuItemIterator = MainMenuItems.begin();

    for (; MenuItemIterator != MainMenuItems.end(); ++MenuItemIterator)
    {
        (*MenuItemIterator)->Render();
    }

    // Menu cursor
    MenuItem *SelectedItem = this->Menu->GetSelectedMenu();

    this->MenuCursor.SetX(SelectedItem->GetX() - 75);
    this->MenuCursor.SetY(SelectedItem->GetY() + 12);
    this->MenuCursor.Render();
}

void Game::StartScreen::Screen::SetRenderer(SDL_Renderer *Renderer)
{
    this->Renderer = Renderer;
}

SDL_Renderer *Game::StartScreen::Screen::GetRenderer()
{
    return this->Renderer;
}

Game::StartScreen::Menu *Game::StartScreen::Screen::GetMenu()
{
    return this->Menu;
}
