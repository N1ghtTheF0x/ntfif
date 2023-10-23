#include <iostream>
#include <fstream>
#include <N1ghtTheF0x/ImageFormat.hpp>

int readFile(const char* path)
{
    std::ifstream file(path,std::ios::binary);
    N1ghtTheF0x::ImageFormat::Header header(file);
    if(header.hasError())
    {
        std::cerr << "There was a parse Error!" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Version: " << header.version() << std::endl;
    std::cout << "Size: " << header.width() << "x" << header.height() << std::endl;
    std::cout << "Depth: " << header.depth() << std::endl;
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