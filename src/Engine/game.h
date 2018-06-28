#ifndef _ALIVE_GAME_H_
#define _ALIVE_GAME_H_

#include <memory>

namespace Alive
{
	namespace Engine
	{
		class Options;
		class Renderer;

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
			std::unique_ptr<Renderer> _renderer;

		private:
			Game();
			~Game();
			Game(Game const&) = delete;
			void operator=(Game const&) = delete;
		};
	}
}

#endif