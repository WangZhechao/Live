#ifndef _ALIVE_SIZE_H_
#define _ALIVE_SIZE_H_

namespace Alive
{
	namespace Base
	{
		class Size
		{
		public:
			Size();
			Size(int width, int height);

			bool operator ==(const Size& rhs) const;
			bool operator !=(const Size& rhs) const;


		public:
			int width() const;
			int height() const;
			int setWidth(int w);
			int setHeight(int h);


		protected:
			int _width;
			int _height;
		};
	}
}

#endif