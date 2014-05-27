#include <fstream>
#include <algorithm>
#include <iterator>
#include <Rom.hpp>

void sv::emuNES::Rom::load(const std::string& file)
{
    std::ifstream ifs(file, std::ios::binary);
    std::copy(
        std::istreambuf_iterator<char>(ifs), 
        std::istreambuf_iterator<char>(), 
        data.begin()
        );    

    //check file header
    if (std::string(data.begin(), data.begin() + 3) != "NES")
        throw std::runtime_error("Invalid ROM file");
}
