#ifndef WINDOW_H_
#define WINDOW_H_

#include "helper/Vector2.h"
#include <string>

namespace dorframe{
  class Window{
  public:
    virtual ~Window(){}

    virtual void onUpdate()                 = 0;

    virtual unsigned int getWidth()   const = 0;
    virtual unsigned int getHeight()  const = 0;

    //static Window* Create(const WindowProps& props = WindowProps());
  protected:
    Vector2ui m_Dimensions = {0, 0};
    bool m_isRunning = 0;
  };
}
#endif
