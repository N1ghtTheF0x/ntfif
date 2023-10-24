#ifndef __N1GHTTHEF0X_IMAGEFORMAT_UTILS_HPP
#define __N1GHTTHEF0X_IMAGEFORMAT_UTILS_HPP

#include <stdint.h>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        /**
         * @brief The type of `width` and `height` in `Header`
         * 
         */
        typedef uint64_t Size;
        /**
         * @brief The type of `depth` in `Header`
         * 
         */
        typedef uint64_t Depth;
        /**
         * @brief The type of `componentType` in `Pixel`
         * 
         */
        enum struct ComponentType : uint8_t
        {
            INT8,
            UINT8,
            INT16,
            UINT16,
            INT32,
            UINT32,
            INT64,
            UINT64,
            FLOAT,
            DOUBLE
        };
        /**
         * @brief The type of `version` in `Header`
         * 
         */
        typedef uint8_t Version;
        /**
         * @brief The type of `red`, `green`, `blue` and `alpha` in `Pixel`
         * 
         */
        typedef uint64_t Component;
        // DO NOT MODIFY BELOW HERE
        /**
         * @brief The type of `width` in `Header`
         * 
         */
        typedef Size Width;
        /**
         * @brief The type of `height` in `Header`
         * 
         */
        typedef Size Height;
        /**
         * @brief Get the byte size of `type`
         * 
         * @param type The type of Component
         */
        size_t getComponentTypeSize(ComponentType type);
    }
}

#endif