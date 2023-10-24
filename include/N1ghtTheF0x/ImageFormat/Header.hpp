#ifndef __N1GHTTHEF0X_IMAGEFORMAT_HEADER_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_HEADER_HPP

#include <fstream>
#include <cstring>

#include "Utils.hpp"

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
            ComponentType _component_type;
        public:
            /**
             * @brief Construct a new Header object using a predefined `width`, `height` and `depth`
             * 
             * @param width The width of the Image
             * @param height The height of the Image
             * @param depth Color depth of the Image
             * @param componentType The size of each color value in a pixel
             */
            Header(Width width,Height height,Depth depth,ComponentType componentType = ComponentType::UINT64);
            /**
             * @brief Construct a new Header object that is invalid. Useful for reading the Header from a file
             * 
             */
            Header();
            /**
             * @brief Read from `stream` into this Header object
             * 
             * @param stream A pointer to a `std::ifstream`
             */
            void read(std::ifstream *stream);
            /**
             * @brief Read from `stream` into this Header object
             * 
             * @param stream A pointer to a `std::fstream`
             */
            void read(std::fstream *stream);
            void write(std::ofstream *stream);
            void write(std::fstream *stream);
            /**
             * @brief Get the width of the Image
             */
            Width width() const;
            /**
             * @brief Get the height of the Image
             */
            Height height() const;
            /**
             * @brief Get the depth of the Image
             */
            Depth depth() const;
            /**
             * @brief Get the version of this Header object
             */
            Version version() const;
            /**
             * @brief Get the type of the component of the pixels
             */
            ComponentType componentType() const;
            /**
             * @brief Check if this Header object is valid.
             */
            bool valid() const;
        };
    }
}

#endif