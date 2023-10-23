#ifndef __N1GHTTHEF0X_IMAGEFORMAT_HEADER_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_HEADER_HPP

#include "Utils.hpp"

#include <stdint.h>
#include <fstream>
#include <cstring>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        #define N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE "NTFIF"
        #define N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH strlen(N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE)
        #define N1GHTTHEF0X_IMAGEFORMAT_HEADER_VERSION 1
        #define N1GHTTHEF0X_IMAGEFORMAT_HEADER_DATA_OFFSET N1GHTTHEF0X_IMAGEFORMAT_HEADER_SIGNATURE_LENGTH + sizeof(Version) + sizeof(Width) + sizeof(Height) + sizeof(Depth)
        /**
         * @brief The `Header` class contains information about the size of the image and its depth
         * 
         */
        class Header
        {
        private:
            Width _width;
            Height _height;
            Depth _depth;
            Version _version;
        public:
            /**
             * @brief Construct a new Header object using a predefined `width`, `height` and `depth`
             * 
             * @param width The width of the Image
             * @param height The height of the Image
             * @param depth The depth of the Image (Size of the components)
             */
            Header(Width width,Height height,Depth depth);
            Header();
            
            void read(std::ifstream *stream);
            void read(std::fstream *stream);

            Width width() const;
            Height height() const;
            Depth depth() const;
            Version version() const;
            bool valid() const;
        };
    }
}

#endif