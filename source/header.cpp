#include <N1ghtTheF0x/ImageFormat/Header.hpp>

#include <iostream>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        Header::Header(Width width,Height height,Depth depth,ComponentType componentType)
        {
            _width = width;
            _height = height;
            _depth = depth;
            _component_type = componentType;
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
            stream->read((char*)&_component_type,sizeof(_component_type));
            delete signature;
        }
        void Header::write(std::ofstream *stream)
        {
            stream->write(N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE,N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH);
            stream->write((char*)&_version,sizeof(_version));
            stream->write((char*)&_width,sizeof(_width));
            stream->write((char*)&_height,sizeof(_height));
            stream->write((char*)&_depth,sizeof(_depth));
            stream->write((char*)&_component_type,sizeof(_component_type));
        }
        void Header::read(std::fstream *stream)
        {
            char* signature = new char[N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH];
            stream->read(signature,N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH);

            stream->read((char*)&_version,sizeof(_version));
            stream->read((char*)&_width,sizeof(_width));
            stream->read((char*)&_height,sizeof(_height));
            stream->read((char*)&_depth,sizeof(_depth));
            stream->read((char*)&_component_type,sizeof(_component_type));
            delete signature;
        }
        void Header::write(std::fstream *stream)
        {
            stream->write(N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE,N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH);
            stream->write((char*)&_version,sizeof(_version));
            stream->write((char*)&_width,sizeof(_width));
            stream->write((char*)&_height,sizeof(_height));
            stream->write((char*)&_depth,sizeof(_depth));
            stream->write((char*)&_component_type,sizeof(_component_type));
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
        ComponentType Header::componentType() const
        {
            return _component_type;
        }
        bool Header::valid() const
        {
            return _width > 0 && _height > 0 && _depth > 0;
        }
    }
}