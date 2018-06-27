#ifndef _LIVE_OPTIONS_H_
#define _LIVE_OPTIONS_H_

namespace Live
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

#endif