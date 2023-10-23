#ifndef __N1GHTTHEF0X_IMAGEFORMAT_PIXEL_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_PIXEL_HPP

#include <stdint.h>
#include <fstream>
#include <vector>

#include "Utils.hpp"

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        #define N1GHTTHEF0X_IMAGEFORMAT_PIXEL_SIZE sizeof(Component) * 4
        class Pixel
        {
        private:
            Component _red;
            Component _green;
            Component _blue;
            Component _alpha;
        public:
            Pixel(Component red,Component green,Component blue,Component alpha = UINT64_MAX);
            Pixel();
            void read(Depth depth,std::ifstream *stream);
            void read(Depth depth,std::fstream *stream);
            Component red() const;
            Component green() const;
            Component blue() const;
            Component alpha() const;
            void setRed(Component value);
            void setGreen(Component value);
            void setBlue(Component value);
            void setAlpha(Component value);
        };
        typedef const Pixel ReadonlyPixel;
        typedef std::vector<Pixel> Pixels;
        typedef std::vector<ReadonlyPixel> ReadonlyPixels;
    }
}

#endif