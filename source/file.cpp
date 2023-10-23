#include <N1ghtTheF0x/ImageFormat/File.hpp>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        File::File(std::fstream *stream): _stream(stream)
        {
            _header.read(stream);
            _stream_ref = false;
        }
        File::File(const char* path)
        {
            _stream = new std::fstream(path,std::ios::binary);
            _stream_ref = true;
        }
        File::~File()
        {
            if(_stream_ref)
                delete _stream;
        }
        ReadonlyPixels File::pixels() const
        {
            ReadonlyPixels pixels;

            for(uint64_t y = 0;y < _header.height();y++)
                for(uint64_t x = 0;x < _header.width();x++)
                {
                    Pixel pixel;
                    pixel.read(_header.depth(),_stream);
                    pixels.push_back(std::move(pixel));
                }

            return pixels;
        }
        ReadonlyPixel File::pixelAt(Width x,Height y) const
        {
            Size index = ((_header.height() * y) + x) * N1GHTTHEF0X_IMAGEFORMAT_PIXEL_SIZE;
            _stream->seekg(N1GHTTHEF0X_IMAGEFORMAT_HEADER_DATA_OFFSET + index,std::ios::beg);
            Pixel pixel;
            pixel.read(_header.depth(),_stream);
            return pixel;
        }
    }
}