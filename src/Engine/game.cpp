#include "game.h"
#include "options.h"
#include "renderer.h"

namespace Alive
{
	namespace Engine
	{
		Game::Game()
		{

		}

		Game::~Game()
		{
			if (_renderer) {
				_renderer->uninit();
			}
		}

		Game* Game::getInstance()
		{
			static Game instance;
			return &instance;
		}


		bool Game::init(std::unique_ptr<Options> options)
		{
			if (_initialized) {
				return true;
			}
			_initialized = true;


			_options = std::move(options);

			_renderer = std::make_unique<Renderer>(
				_options->screenWidth(), _options->screenHeight());
			if (_renderer->init() < 0) {
				return false;
			}

			return true;
		}


		void Game::run()
		{
			SDL_Delay(4000);
		}
	}
}