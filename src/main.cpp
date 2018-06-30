#include <memory>

#include "game.h"
#include "options.h"

using namespace Alive;

int main(int argc, char* argv[])
{
	auto game = Engine::Game::getInstance();
	if (game->init(std::unique_ptr<Engine::Options>(new Engine::Options())))
	{
		//game->setState();
		game->run();

		return 0;
	}

	return -1;
}