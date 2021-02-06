#include "Application.h"

namespace dorframe{

  Application::Application(){
    m_Window = Window::Create();
  }

  Application::~Application(){
    
  }

  void Application::Run(){
    while(m_isRunning){
      m_Window->onUpdate();
    }
  }

}
