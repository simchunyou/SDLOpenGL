#include "SDLOpenGL.h"
#include <iostream>

SDLOpenGL::SDLOpenGL(const std::string &_name, int _x, int _y, int _width, int _height)
{
  m_name = _name;
  m_x= _x;
  m_y = _y;
  m_width=_width;
  m_height=_height;
  init();
}

void SDLOpenGL::init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) <0)
  {
    errorExit("Error calling int");
  }

  m_window=SDL_CreateWindow(m_name.c_str(),m_x,m_y,m_width,m_height,SDL_WINDOW_OPENGL);

  if(!m_window)
  {
    errorExit("Could not Open Window");
  }

  createGLContext();  //Can't create openGL context if we havent created a window
}

void SDLOpenGL::createGLContext()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

  m_glContext=SDL_GL_CreateContext(m_window);
}

void SDLOpenGL::errorExit(const std::string &_msg) const
{
  std::cerr<<_msg<<std::endl;
  std::cerr<<SDL_GetError()<<std::endl;
  SDL_Quit();
  exit(EXIT_FAILURE);
}
