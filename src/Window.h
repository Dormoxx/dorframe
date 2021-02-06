#ifndef WINDOW_H_
#define WINDOW_H_



namespace dorframe{
  struct WindowProps{

    std::string Title;
    unsigned int Width;
    unsigned int Height;

    WindowProps(const std::string& title = "dorframe application", unsigned int w = 640, unsigned int h = 480)
                : Title(title), Width(w), Height(h){}
  };

  class Window{

  public:
    virtual ~Window(){}

    virtual void onUpdate()                 = 0;

    virtual unsigned int getWidth()   const = 0;
    virtual unsigned int getHeight()  const = 0;

    static Window* Create(const WindowProps& props = WindowProps());
  };

}


#endif
