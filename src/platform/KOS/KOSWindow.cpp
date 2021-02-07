#include "KOSWindow.h"

namespace dorframe{

  KOSWindow::KOSWindow(){
    Init();
  }
  KOSWindow::~KOSWindow(){

  }
  void KOSWindow::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
  void KOSWindow::render(){
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    glTranslatef(3.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
  }
  void KOSWindow::onUpdate(){
    while(m_isRunning){
      controller = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
      state = (cont_state_t*)maple_dev_status(controller);
      if(!state) {
          printf("Error reading controller\n");
          break;
      }
      if(state->buttons & CONT_START){
        m_isRunning = false;
      }
      render();
      glutSwapBuffers();
    }
  }
  void KOSWindow::Shutdown(){

  }
  void KOSWindow::Init(){
    glKosInit();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_isRunning = true;
  }

}
