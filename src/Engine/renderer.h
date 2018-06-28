#ifndef _ALIVE_RENDERER_H_
#define _ALIVE_RENDERER_H_

#include "SDL2/SDL.h"
#include "size.h"

namespace Alive
{
	namespace Engine
	{
		class Renderer
		{
		public:
			Renderer(unsigned int width, unsigned int height);
			~Renderer();


		public:
			int init();
			void uninit();


		protected:
			Base::Size _size;
			SDL_Window* _sdlWindow;
			SDL_Renderer* _sdlRenderer;
		};
	}
}

#endif