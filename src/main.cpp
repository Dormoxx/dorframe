
//#include <gl/glu.h>

#include <stdio.h>
#include <string>
#include "Log.h"
#include "platform/SDL/SDLWindow.h"

using namespace dorframe;

int main(){
  Log::Init();
  SDLWindow wind({640, 480}, "test");
  wind.onUpdate();
  wind.Shutdown();
  return 0;
}
