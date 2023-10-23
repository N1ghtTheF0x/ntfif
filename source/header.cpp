#include <N1ghtTheF0x/ImageFormat/Header.hpp>

#include <iostream>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        Header::Header(Width width,Height height,Depth depth)
        {
            _width = width;
            _height = height;
            _depth = depth;
            _version = N1GHTTHEF0X_IMAGEFORMAT_HEADER_VERSION;
        }
        Header::Header()
        {
            _width = 0;
            _height = 0;
            _depth = 0;
            _version = N1GHTTHEF0X_IMAGEFORMAT_HEADER_VERSION;
        }
        void Header::read(std::ifstream *stream)
        {
            char* signature = new char[N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH];
            stream->read(signature,N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH);

            stream->read((char*)&_version,sizeof(_version));
            stream->read((char*)&_width,sizeof(_width));
            stream->read((char*)&_height,sizeof(_height));
            stream->read((char*)&_depth,sizeof(_depth));
        }
        void Header::read(std::fstream *stream)
        {
            char* signature = new char[N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH];
            stream->read(signature,N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH);

            stream->read((char*)&_version,sizeof(_version));
            stream->read((char*)&_width,sizeof(_width));
            stream->read((char*)&_height,sizeof(_height));
            stream->read((char*)&_depth,sizeof(_depth));
        }
        Width Header::width() const
        {
            return _width;
        }
        Height Header::height() const
        {
            return _height;
        }
        Depth Header::depth() const
        {
            return _depth;
        }
        Version Header::version() const
        {
            return _version;
        }
        bool Header::valid() const
        {
            return _width > 0 && _height > 0 && _depth > 0;
        }
    }
}