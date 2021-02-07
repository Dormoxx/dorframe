#include "platform/SDL/SDLWindow.h"

namespace dorframe{

  SDLWindow::SDL_Window(Vector2ui size, std::string title){
    Init(Vector2ui size, std::string title);
  }
  SDLWindow::~SDLWindow(){

  }

  void SDLWindow::Init(Vector2ui size, std::string title){
    m_Dimensions.x = size.x;
    m_Dimensions.y = size.y;
    m_Title = title;

    DORFRAME_LOG_INFO("Creating window {0} ({1}, {2})". title, size.x, size.y);

    //sdl/ogl init stuff here

  }

  void SDLWindow::Shutdown(){
    //cleanup
  }

  void SDLWindow::onUpdate(){

  }



}
