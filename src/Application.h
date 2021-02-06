#ifndef APPLICATION_H_
#define APPLICATION_H_

namespace dorframe{

  class Application{
  public:
    Application();
    virtual ~Application();

    void Run();

  private:
    Window* m_Window;
    bool m_isRunning;
  };

}

#endif
