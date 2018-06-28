#ifndef _ALIVE_OPTIONS_H_
#define _ALIVE_OPTIONS_H_

namespace Alive
{
	namespace Engine
	{
		class Options
		{
		public:
			Options();
			~Options();

		public:
			unsigned int screenWidth() const;
			unsigned int screenHeight() const;

		private:
			unsigned int _screenWidth = 960;
			unsigned int _screenHeight = 544;
		};
	}
}

#endif