#include "../../include/StartScreen/Screen.hpp"

StartScreen::Screen::~Screen()
{
}

void StartScreen::Screen::InitEdgeTriangles()
{
    // We will use again
    SDL_Rect Rect = {0, 0, 100, 100};

    StartScreen::EdgeTriangle *TopLeft = new StartScreen::EdgeTriangle();
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

    StartScreen::EdgeTriangle *TopRight = new StartScreen::EdgeTriangle();
    TopRight->SetRenderer(this->Renderer);
    TopRight->SetRect(Rect);
    TopRight->SetX(this->Width - 80);
    TopRight->SetY(-20);
    TopRight->SetAngle(90);
    TopRight->SetTexture(Texture);
    TopRight->SetSurface(Surface);

    StartScreen::EdgeTriangle *BottomLeft = new StartScreen::EdgeTriangle();
    BottomLeft->SetRenderer(this->Renderer);
    BottomLeft->SetRect(Rect);
    BottomLeft->SetX(-20);
    BottomLeft->SetY(this->Height - 80);
    BottomLeft->SetAngle(270);
    BottomLeft->SetTexture(Texture);
    BottomLeft->SetSurface(Surface);

    StartScreen::EdgeTriangle *BottomRight = new StartScreen::EdgeTriangle();
    BottomRight->SetRenderer(this->Renderer);
    BottomRight->SetRect(Rect);
    BottomRight->SetX(this->Width - 80);
    BottomRight->SetY(this->Height - 80);
    BottomRight->SetAngle(180);
    BottomRight->SetTexture(Texture);
    BottomRight->SetSurface(Surface);

    std::list<StartScreen::EdgeTriangle>::iterator Iterator = this->EdgeTriangles.begin();

    this->EdgeTriangles.insert(Iterator, *TopLeft);
    this->EdgeTriangles.insert(Iterator, *TopRight);
    this->EdgeTriangles.insert(Iterator, *BottomLeft);
    this->EdgeTriangles.insert(Iterator, *BottomRight);
}

void StartScreen::Screen::Render()
{
    std::list<StartScreen::EdgeTriangle>::iterator Iterator = this->EdgeTriangles.begin();

    for (; Iterator != EdgeTriangles.end(); ++Iterator)
    {
        Iterator->Render();
    }
}

void StartScreen::Screen::SetRenderer(SDL_Renderer *Renderer)
{
    this->Renderer = Renderer;
}

SDL_Renderer *StartScreen::Screen::GetRenderer()
{
    return this->Renderer;
}
