#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include "Window.h"

namespace dorframe{

  class SDLWindow : public Window{

  public:
    SDLWindow(Vector2ui size, std::string title);
    virtual ~SDLWindow();

    void onUpdate() override;

    inline unsigned int getWidth() const override {return m_Dimensions.x;}
    inline unsigned int getHeight() const override {return m_Dimensions.y;}

  private:
    //window item
    virtual void Init(Vector2ui size, std::string title);
    virtual void Shutdown();
  };

}

#endif
