#ifndef __N1GHTTHEF0X_IMAGEFORMAT_FILE_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_FILE_HPP

#include "Header.hpp"
#include "Pixel.hpp"

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        class File
        {
        private:
            Header _header;
            std::fstream *_stream;
            bool _stream_ref = false;
        public:
            File(std::fstream *stream);
            File(const char* path);
            ~File();
            ReadonlyPixels pixels() const;
            ReadonlyPixel pixelAt(Width x,Height y) const;
        };
    }
}

#endif