#include <iostream>
#include "SDLOpenGL.h"
#include <ngl/NGLInit.h>

void initializeGL();
void renderGL();


int main(int argc, char *argv[])
{
  SDLOpenGL window("test",0,0,1024,720);  //Call the constructor of the window
  window.makeCurrent(); //Make the window current so everything will do will be done on the window
  initializeGL();
  while(true)
  {
    renderGL();
    window.swapWindow();
    SDL_Delay(10);
  }



  std::cout<<"working\n";
}

void initializeGL()
{
  ngl::NGLInit::instance();
  glClearColor(0.8,0.8,0.8,1.0);
}

void renderGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
