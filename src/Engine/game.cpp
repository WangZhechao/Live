#include "game.h"
#include "options.h"

namespace Live
{
	Game::Game()
	{

	}

	Game::~Game()
	{

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


		return true;
	}


	void Game::run()
	{

	}
}