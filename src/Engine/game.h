#ifndef _LIVE_GAME_H_
#define _LIVE_GAME_H_

#include <memory>

namespace Live
{
	class Options;

	class Game
	{
	public:
		static Game* getInstance();

	public:
		bool init(std::unique_ptr<Options> options);
		void run();

	protected:
		bool _initialized = false;
		std::unique_ptr<Options> _options;

	private:
		Game();
		~Game();
		Game(Game const&) = delete;
		void operator=(Game const&) = delete;
	};
}

#endif