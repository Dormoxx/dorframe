#ifndef PLATFORM_H_
#define PLATFORM_H_

  #define PLATFORM_DC

    #ifdef PLATFORM_SDL
      #include "platform/SDL/SDLWindow.h"
    #endif

    #ifdef PLATFORM_DC
      #include "platform/KOS/KOSWindow.h"
    #endif

#endif
