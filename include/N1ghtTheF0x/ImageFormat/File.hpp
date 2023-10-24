#ifndef __N1GHTTHEF0X_IMAGEFORMAT_FILE_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_FILE_HPP

#include "Header.hpp"
#include "Pixel.hpp"

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        /**
         * @brief Represents a `.ntfif` file
         * 
         */
        class File
        {
        private:
            Header _header;
            std::fstream *_stream;
            bool _created = false;
            std::streampos _offset;
        public:
            /**
             * @brief Construct a new `.ntfif` File object from `stream`
             * 
             * @param stream The pointer to a `std::fstream`
             * @param offset The offset for reading
             */
            File(std::fstream *stream,std::streampos offset = 0);
            /**
             * @brief Construct a new `.ntfif` File object from a filepath
             * 
             * @param path The path to a `.ntfif` file
             */
            File(const char* path);
            ~File();
            void read(std::ifstream *stream,std::streampos offset = 0);
            void read(std::fstream *stream,std::streampos offset = 0);
            void write(std::ofstream *stream);
            void write(std::fstream *stream);
            /**
             * @brief Get Header data of this `.ntfif` file
             */
            const Header &header() const;
            /**
             * @brief Read all the pixels from this file
             */
            Pixels pixels() const;
            /**
             * @brief Get a pixel from `x` and `y`. The top-left pixel is `(0,0)`
             * 
             * @param x The position along the width
             * @param y The position along the height
             */
            Pixel pixelAt(Width x,Height y) const;
            /**
             * @brief Overwrite the pixel at `x` and `y` to `pixel`
             * 
             * @param x The position along the width
             * @param y The position along the height
             * @param pixel The new pixel data
             */
            void setPixel(Width x,Height y,Pixel pixel);
            /**
             * @brief Overwrite the pixel at `x` and `y` to `red`, `green`, `blue` and `alpha`
             * 
             * @param x The position along the width
             * @param y The position along the height
             */
            void setPixel(Width x,Height y,Component red,Component green,Component blue,Component alpha = UINT64_MAX);
        };
    }
}

#endif