#include "crossplatform.h"
#include "config.h"

namespace Alive
{
	namespace CrossPlatform
	{
		bool isQuitShortcut(const SDL_Event& ev)
		{
#ifdef RUN_WIN32_PLATFORM
			//if (ev.type == SDL_QUIT)
			//	return true;

			return (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_F4 && ev.key.keysym.mod & KMOD_ALT);
#else
			return false;
#endif
		}
	}
}