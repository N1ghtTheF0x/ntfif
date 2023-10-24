# N1ghtTheF0x Image Format
A custom Image format I made :D

## Structure
There are various verions of Image Format
### Version 1
almost like a bitmap image
```c
struct HeaderVersion1
{
    char signature[5]; // Always "NTFIF"
    uint8_t version; // Version of Image Format
    uint64_t width; // Width of Image
    uint64_t height; // Height of Image
    uint64_t depth; // Color depth of Image
    uint64_t componentSize; // The size of the components Red, Green, Blue, Alpha
}

struct Pixel
{
    uint64_t red;
    uint64_t green;
    uint64_t blue;
    uint64_t alpha;
}
```

The order goes like this:

- Header
- Pixel Data