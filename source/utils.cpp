#include <N1ghtTheF0x/ImageFormat/Utils.hpp>

namespace N1ghtTheF0x
{
    namespace ImageFormat
    {
        size_t getComponentTypeSize(ComponentType type)
        {
            switch (type)
            {
            case ComponentType::INT8:
                return sizeof(int8_t);
            case ComponentType::UINT8:
                return sizeof(uint8_t);
            case ComponentType::INT16:
                return sizeof(int16_t);
            case ComponentType::UINT16:
                return sizeof(uint16_t);
            case ComponentType::INT32:
                return sizeof(int32_t);
            case ComponentType::UINT32:
                return sizeof(uint32_t);
            case ComponentType::INT64:
                return sizeof(int64_t);
            case ComponentType::UINT64:
                return sizeof(uint64_t);
            case ComponentType::FLOAT:
                return sizeof(float);
            case ComponentType::DOUBLE:
                return sizeof(double);
            default:
                return sizeof(Component);
            }
        }
    }
}