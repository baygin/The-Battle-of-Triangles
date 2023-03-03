#include "../include/Main.hpp"
#include <unistd.h>

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

   Screen->InitEdgeTriangles();

   SDL_Event Event;
   int Loop = 1;

   while (Loop)
   {
      SDL_PollEvent(&Event);

      if (Event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
      {
         Loop = 0;
      }

      SDL_RenderClear(Renderer);
      Screen->Render();
      SDL_RenderPresent(Renderer);
   }

   delete Screen;

   SDL_Quit();
   IMG_Quit();

   return EXIT_SUCCESS;
}