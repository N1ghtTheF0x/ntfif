#include <iostream>
#include <fstream>
#include <N1ghtTheF0x/ImageFormat.hpp>

int readFile(const char* path)
{
    std::fstream stream(path,std::ios::binary);
    if(!stream.good())
    {
        std::cerr << "Couldn't read " << path << std::endl;
        return EXIT_FAILURE;
    }
    N1ghtTheF0x::ImageFormat::File file(&stream);
    auto header = file.header();
    if(!header.valid())
    {
        std::cerr << "Header not valid!" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Version: " << header.version() << std::endl;
    std::cout << "Size: " << header.width() << "x" << header.height() << std::endl;
    std::cout << "Depth: " << header.depth() << std::endl;
    std::cout << "ComponentType: " << (uint8_t)header.componentType() << std::endl;
    for(N1ghtTheF0x::ImageFormat::Height y = 0;y < header.height();y++)
        for(N1ghtTheF0x::ImageFormat::Width x = 0;x < header.width();x++)
        {
            auto pixel = file.pixelAt(x,y);
            std::cout << "(" << pixel.red() << ", " << pixel.green() << ", " << pixel.blue() << ")" << std::endl;
        }
    return EXIT_SUCCESS;
}

int main(int argc,char** argv)
{
    if(argc > 1)
    {
        char* path = argv[1];
        return readFile(path);
    }
    std::cout << "No path provided!" << std::endl << "Usage: ntfif_example.exe <path-to-image>" << std::endl;
    return EXIT_FAILURE;
}