#include <N1ghtTheF0x/ImageFormat/Pixel.hpp>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        Pixel::Pixel(Component red,Component green,Component blue,Component alpha)
        {
            _red = red;
            _green = green;
            _blue = blue;
            _alpha = alpha;
        }
        Pixel::Pixel()
        {
            _red = 0;
            _green = 0;
            _blue = 0;
            _alpha = UINT64_MAX;
        }
        void Pixel::read(ComponentType cType,std::ifstream *stream)
        {
            size_t depth = getComponentTypeSize(cType);
            stream->read((char*)&_red,depth);
            stream->read((char*)&_green,depth);
            stream->read((char*)&_blue,depth);
            stream->read((char*)&_alpha,depth);
        }
        void Pixel::write(ComponentType cType,std::ofstream *stream)
        {
            size_t depth = getComponentTypeSize(cType);
            stream->write((char*)&_red,depth);
            stream->write((char*)&_green,depth);
            stream->write((char*)&_blue,depth);
            stream->write((char*)&_alpha,depth);
        }
        void Pixel::read(ComponentType cType,std::fstream *stream)
        {
            size_t depth = getComponentTypeSize(cType);
            stream->read((char*)&_red,depth);
            stream->read((char*)&_green,depth);
            stream->read((char*)&_blue,depth);
            stream->read((char*)&_alpha,depth);
        }
        void Pixel::write(ComponentType cType,std::fstream *stream)
        {
            size_t depth = getComponentTypeSize(cType);
            stream->write((char*)&_red,depth);
            stream->write((char*)&_green,depth);
            stream->write((char*)&_blue,depth);
            stream->write((char*)&_alpha,depth);
        }
        Component Pixel::red() const
        {
            return _red;
        }
        Component Pixel::green() const
        {
            return _green;
        }
        Component Pixel::blue() const
        {
            return _blue;
        }
        Component Pixel::alpha() const
        {
            return _alpha;
        }
        void Pixel::setRed(Component value)
        {
            _red = value;
        }
        void Pixel::setGreen(Component value)
        {
            _green = value;
        }
        void Pixel::setBlue(Component value)
        {
            _blue = value;
        }
        void Pixel::setAlpha(Component value)
        {
            _alpha = value;
        }
    }
}