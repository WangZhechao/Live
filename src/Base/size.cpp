#include "size.h"

namespace Alive
{
	namespace Base
	{
		Size::Size() : _width(0), _height(0)
		{

		}

		Size::Size(int w, int h)
		{
			setWidth(w);
			setHeight(h);
		}


		bool Size::operator ==(const Size& rhs) const
		{
			return _width == rhs._width && _height == rhs._height;
		}

		bool Size::operator !=(const Size& rhs) const
		{
			return !(*this == rhs);
		}


		int Size::width() const
		{
			return _width;
		}

		int Size::height() const
		{
			return _height;
		}


		int Size::setWidth(int w)
		{
			if (w < 0)
				_width = 0;
			else
				_width = w;

			return _width;
		}


		int Size::setHeight(int h)
		{
			if (h < 0)
				_height = 0;
			else
				_height = h;

			return _height;
		}
	}
}