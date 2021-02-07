#ifndef WINDOW_H_
#define WINDOW_H_

#include "helper/Vector2.h"

namespace dorframe{
  class Window{
  public:
    virtual ~Window(){}

    virtual void onUpdate()                 = 0;

    virtual unsigned int getWidth()   const = 0;
    virtual unsigned int getHeight()  const = 0;

    //static Window* Create(const WindowProps& props = WindowProps());
  protected:
    std::string m_Title = 0;
    Vector2ui m_Dimensions = 0;
  };
}
#endif
