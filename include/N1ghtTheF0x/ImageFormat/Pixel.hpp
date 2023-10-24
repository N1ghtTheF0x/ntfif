#ifndef __N1GHTTHEF0X_IMAGEFORMAT_PIXEL_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_PIXEL_HPP

#include <fstream>
#include <vector>

#include "Utils.hpp"

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        #define N1GHTTHEF0X_IMAGEFORMAT_PIXEL_SIZE sizeof(Component) * 4
        /**
         * @brief Represents a pixel in a Image
         * 
         */
        class Pixel
        {
        private:
            Component _red;
            Component _green;
            Component _blue;
            Component _alpha;
        public:
            /**
             * @brief Construct a new Pixel object from `red`, `green`, `blue` and `alpha`. Keep in mind that they have to be `uint64_t`!
             */
            Pixel(Component red,Component green,Component blue,Component alpha = UINT64_MAX);
            /**
             * @brief Construct a new Pixel object that is opaque black (#000000FF)
             * 
             */
            Pixel();
            void read(ComponentType cType,std::ifstream *stream);
            void read(ComponentType cType,std::fstream *stream);
            void write(ComponentType cType,std::ofstream *stream);
            void write(ComponentType cType,std::fstream *stream);
            Component red() const;
            Component green() const;
            Component blue() const;
            Component alpha() const;
            void setRed(Component value);
            void setGreen(Component value);
            void setBlue(Component value);
            void setAlpha(Component value);
        };
        /**
         * @brief Contains all the pixels in a Image
         * 
         */
        typedef std::vector<Pixel> Pixels;
    }
}

#endif