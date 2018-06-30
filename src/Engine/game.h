#ifndef _ALIVE_GAME_H_
#define _ALIVE_GAME_H_

#include <memory>
#include "SDL2/SDL.h"

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
			void quit();

			void processInput();
			void update();
			void render();

		protected:
			bool _quit = false;
			bool _initialized = false;

			SDL_Event _event;
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