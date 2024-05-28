#include "ibeel.hpp"
#include <vector>
#include <fstream>
#include <cassert>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

std::vector<char> read_binary_file(const std::string& filename)
{
    ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        printf("Failed to open file: %s\n", filename.c_str());
        return vector<char>();
    }
    const streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    if (file.read(buffer.data(), size)) return buffer;
    assert(false);
    return vector<char>();
}

void load_environment(const std::string& filename)
{
    int width;
    int height;
    int channels;
    auto data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
}
