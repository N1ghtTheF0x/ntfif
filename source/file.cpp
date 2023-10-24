#include <N1ghtTheF0x/ImageFormat/File.hpp>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        File::File(std::fstream *stream,std::streampos offset): _stream(stream)
        {
            _offset = offset;
            _header.read(_stream);
            _created = false;
        }
        File::File(const char* path)
        {
            _offset = 0;
            _stream = new std::fstream(path,std::ios::binary);
            _created = true;
        }
        File::~File()
        {
            if(_created)
                delete _stream;
        }
        void File::read(std::ifstream *stream,std::streampos offset)
        {

        }
        void File::read(std::fstream *stream,std::streampos offset)
        {
            _stream = stream;
            _offset = offset;
            _header.read(_stream);
            if(_created)
                delete _stream;
            _created = false;
        }
        const Header &File::header() const
        {
            return _header;
        }
        Pixels File::pixels() const
        {
            Pixels pixels;

            for(uint64_t y = 0;y < _header.height();y++)
                for(uint64_t x = 0;x < _header.width();x++)
                {
                    Pixel pixel;
                    pixel.read(_header.componentType(),_stream);
                    pixels.push_back(std::move(pixel));
                }

            return std::move(pixels);
        }
        Pixel File::pixelAt(Width x,Height y) const
        {
            Size index = ((_header.height() * y) + x) * N1GHTTHEF0X_IMAGEFORMAT_PIXEL_SIZE;
            std::streampos old_pos = _stream->tellg();
            _stream->seekg(_offset + (std::streampos)(N1GHTTHEF0X_IMAGEFORMAT_HEADER_DATA_OFFSET + index),std::ios::beg);
            Pixel pixel;
            pixel.read(_header.componentType(),_stream);
            _stream->seekg(old_pos);
            return std::move(pixel);
        }
        void File::setPixel(Width x,Height y,Pixel pixel)
        {
            Size index = ((_header.height() * y) + x) * N1GHTTHEF0X_IMAGEFORMAT_PIXEL_SIZE;
            std::streampos old_pos = _stream->tellp();
            _stream->seekp(_offset + (std::streampos)(N1GHTTHEF0X_IMAGEFORMAT_HEADER_DATA_OFFSET + index),std::ios::beg);

            size_t depth = getComponentTypeSize(_header.componentType());

            Component red = pixel.red();
            Component green = pixel.green();
            Component blue = pixel.blue();
            Component alpha = pixel.alpha();

            _stream->write((const char*)&red,depth);
            _stream->write((const char*)&green,depth);
            _stream->write((const char*)&blue,depth);
            _stream->write((const char*)&alpha,depth);

            _stream->seekp(old_pos);
        }
        void File::setPixel(Width x,Height y,Component red,Component green,Component blue,Component alpha)
        {
            setPixel(x,y,Pixel(red,green,blue,alpha));
        }
    }
}