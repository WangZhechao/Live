#include "renderer.h"

namespace Alive
{
	namespace Engine
	{
		Renderer::Renderer(unsigned int width, unsigned int height)
			: _sdlWindow(nullptr)
		{
			_size.setWidth(width);
			_size.setHeight(height);
		}


		Renderer::~Renderer()
		{

		}

		void Renderer::uninit()
		{
			if (_sdlRenderer) {
				SDL_DestroyRenderer(_sdlRenderer);
			}

			if (_sdlWindow) {
				SDL_DestroyWindow(_sdlWindow);
			}

			SDL_Quit();
		}
	
		int Renderer::init()
		{
			int ret = 0;

			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				ret = -1;
				goto err;
			}

			
			uint32_t flags = SDL_WINDOW_SHOWN;
			_sdlWindow = SDL_CreateWindow("alive", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, _size.width(), _size.height(), flags);
			if (!_sdlWindow) {
				ret = -2;
				goto err;
			}


			_sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, 0);
			if (!_sdlRenderer) {
				ret = -3;
				goto err;
			}


			SDL_RenderPresent(_sdlRenderer);

			return 0;

		err:
			uninit();

			return ret;
		}
	}
}