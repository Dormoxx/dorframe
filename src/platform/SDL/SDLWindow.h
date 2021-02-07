#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include "../../Window.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace dorframe{

  class SDLWindow : public Window{

  public:
    SDLWindow(Vector2ui size, std::string title);
    virtual ~SDLWindow();

    void clear();
    void onUpdate() override;

    inline unsigned int getWidth() const override {return m_Dimensions.x;}
    inline unsigned int getHeight() const override {return m_Dimensions.y;}
    virtual void Shutdown();
  private:
    //window item
    virtual void Init(Vector2ui size, std::string title);


    SDL_Event m_Event;
    SDL_Window* m_Window = 0;
    SDL_GLContext m_GLContext = 0;
    std::string m_Title;
  };

}

#endif
