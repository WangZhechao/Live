#include "options.h"

namespace Live
{
	Options::Options()
	{

	}


	Options::~Options()
	{

	}


	unsigned int Options::screenWidth() const
	{
		return _screenWidth;
	}

	unsigned int Options::screenHeight() const
	{
		return _screenHeight;
	}
}