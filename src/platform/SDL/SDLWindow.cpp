#include "platform/SDL/SDLWindow.h"

namespace dorframe{

  Window* Window::Create(const WindowProps& props){
    return new SDLWindow(props);
  }
  SDLWindow::SDL_Window(const WindowProps& props){
    Init(props);
  }
  SDLWindow::~SDLWindow(){

  }

  void SDLWindow::Init(const WindowProps& props){
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    DORFRAME_LOG_INFO("Creating window {0} ({1}, {2})". props.Title, props.Width, props.Height);

    //sdl/ogl init stuff here

  }

  void SDLWindow::Shutdown(){
    //cleanup
  }

  void SDLWindow::onUpdate(){

  }



}
