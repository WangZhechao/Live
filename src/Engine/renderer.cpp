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
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				uninit();
				return -1;
			}

			
			uint32_t flags = static_cast<uint32_t>(SDL_WINDOW_SHOWN);
			_sdlWindow = SDL_CreateWindow("alive", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, _size.width(), _size.height(), flags);
			if (!_sdlWindow) {
				uninit();
				return -2;
			}


			_sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, 0);
			if (!_sdlRenderer) {
				uninit();
				return -3;
			}


			SDL_RenderPresent(_sdlRenderer);

			return 0;
		}
	}
}