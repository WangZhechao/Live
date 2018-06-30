#ifndef _ALIVE_CROSSPLATFORM_H_
#define _ALIVE_CROSSPLATFORM_H_

#include "SDL2/SDL.h"

namespace Alive
{
	namespace CrossPlatform
	{
		bool isQuitShortcut(const SDL_Event& ev);
	}
}

#endif