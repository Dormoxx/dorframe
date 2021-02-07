#include "SDLWindow.h"
#include "../../Log.h"

namespace dorframe{

  SDLWindow::SDLWindow(Vector2ui size, std::string title){
    Init(size, title);
  }
  SDLWindow::~SDLWindow(){

  }

  void SDLWindow::Init(Vector2ui size, std::string t){
    m_Dimensions.x = size.x;
    m_Dimensions.y = size.y;
    m_Title = t;

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        DORFRAME_LOG_TRACE("SDL Init video failed");
        m_isRunning = false;
        return;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    DORFRAME_LOG_TRACE("gl attributes");

    m_Window = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Dimensions.x, m_Dimensions.y, SDL_WINDOW_OPENGL);
    if(m_Window == NULL){
      DORFRAME_LOG_TRACE("Failed Window Creation");
      m_isRunning = false;
      return;
    }
    m_GLContext = SDL_GL_CreateContext(m_Window);
    if(m_GLContext == NULL){
        DORFRAME_LOG_ERROR("Failed Context Creation");
        m_isRunning = false;
        return;
    }
    else{
      glewExperimental = GL_TRUE;
      GLenum glewError = glewInit();
      if(glewError != GLEW_OK){
        DORFRAME_LOG_ERROR("Glew init error %s\n", glewError);
        m_isRunning = false;
        return;
      }
    }
    DORFRAME_LOG_TRACE("Initialzed Window");
    m_isRunning = true;
  }

  void SDLWindow::Shutdown(){
    SDL_GL_DeleteContext(m_GLContext);
    SDL_Quit();
  }

  void SDLWindow::onUpdate(){
    while(m_isRunning){
      while(SDL_PollEvent(&m_Event) != 0){
        if(m_Event.type == SDL_QUIT)
          m_isRunning = false;
      }
      SDL_GL_SwapWindow(m_Window);
    }
  }



}
