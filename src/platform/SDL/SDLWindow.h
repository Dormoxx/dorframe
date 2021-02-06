#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_

#include "Window.h"

namespace dorframe{

  class SDLWindow : public Window{

  public:
    SDLWindow(const WindowProps& props);
    virtual ~SDLWindow();

    void onUpdate() override;

    inline unsigned int getWidth() const override {return m_Data.Width;}
    inline unsigned int getHeight() const override {return m_Data.Height;}

  private:
    //window item
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

    struct WindowData{
      std::string Title;
      unsigned int Width, Height;
      bool VSync;
    }
    WindowData m_Data;
  };

}

#endif
