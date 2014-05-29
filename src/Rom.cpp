#include <fstream>
#include <algorithm>
#include <iterator>
#include <Rom.hpp>
#include <iostream>

void sv::emuNES::Rom::load(const std::string& file)
{
    std::ifstream ifs(file, std::ios::binary);

    ifs.read(reinterpret_cast<char*>(&header), sizeof(header));

    std::copy(
        std::istreambuf_iterator<char>(ifs.rdbuf()), 
        std::istreambuf_iterator<char>(), 
        data.begin()
        );    

    //check file header
    if (header.format != 0x1A53454E)
        throw std::runtime_error("Invalid ROM file");
}
