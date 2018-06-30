#include "game.h"
#include "options.h"
#include "renderer.h"
#include "crossplatform.h"

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
			while (!_quit)
			{
				processInput();
				update();
				render();

				SDL_Delay(1);
			}
		}


		void Game::processInput()
		{
			while (SDL_PollEvent(&_event))
			{
				if (CrossPlatform::isQuitShortcut(_event))
					_event.type = SDL_QUIT;

				switch (_event.type)
				{
				case SDL_QUIT:
					quit();
					break;

				default:
					break;
				}
			}
		}


		void Game::update()
		{

		}


		void Game::render()
		{

		}


		void Game::quit()
		{
			_quit = true;
		}
	}
}