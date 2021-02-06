#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
//#include <gl/glu.h>

#include <stdio.h>
#include <string>

#include "Log.h"

const int screenW = 640;
const int screenH = 480;
bool isRunning = false;

SDL_Event e;
SDL_Window* window = 0;
SDL_GLContext glContext = 0;

bool initialize(){
  if(SDL_Init(SDL_INIT_VIDEO) != 0){
      DORFRAME_LOG_TRACE("SDL Init video failed");
      return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  DORFRAME_LOG_TRACE("gl attributes");

  window = SDL_CreateWindow("SDL Context", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_OPENGL);
  if(window == NULL){
    DORFRAME_LOG_TRACE("Failed Window Creation");
    return false;
  }

  glContext = SDL_GL_CreateContext(window);
  if(glContext == NULL){
      DORFRAME_LOG_ERROR("Failed Context Creation");
      return false;
  }
  else{
    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if(glewError != GLEW_OK){
      DORFRAME_LOG_ERROR("Glew init error %s\n", glewError);
      return false;
    }
  }
  isRunning = true;
  DORFRAME_LOG_TRACE("Initialzed Window");
  return isRunning;
}

int main(){
  dorframe::Log::Init();
  if(initialize()){
    while(isRunning){
      while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT)
          isRunning = false;
      }
      SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(glContext);
    SDL_Quit();
  }
  return 0;
}
