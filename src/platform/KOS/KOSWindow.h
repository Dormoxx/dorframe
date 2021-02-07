#ifndef KOSWINDOW_H_
#define KOSWINDOW_H_

#include "../../Window.h"
#include <kos.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

namespace dorframe{
  class KOSWindow : public Window{
  public:
    KOSWindow();
    virtual ~KOSWindow();

    void clear();
    void onUpdate() override;

    inline unsigned int getWidth() const override {return m_Dimensions.x;}
    inline unsigned int getHeight() const override {return m_Dimensions.y;}

    virtual void Shutdown();

  private:
    void Init();
    void render();
    maple_device_t *controller;
    cont_state_t *state;

  };
}


#endif
