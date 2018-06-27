#include <memory>

#include "game.h"
#include "options.h"

using namespace Live;

int main()
{
	auto game = Game::getInstance();
	if (game->init(std::unique_ptr<Options>(new Options())))
	{
		//game->setState();
		game->run();

		return 0;
	}

	return -1;
}