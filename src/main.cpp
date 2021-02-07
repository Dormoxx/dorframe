
#include "Log.h"
#include "platform.h"

using namespace dorframe;

int main(int argc, char **argv){
  //Log::Init();
  //SDLWindow wind({640, 480}, "test");

  KOSWindow *wind = new KOSWindow;
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
  wind->clear();
  wind->onUpdate();
  wind->Shutdown();
  return 0;
}
