#include <iostream>
#include <string>
#include <Processor.hpp>
#include <Rom.hpp>

int main()
{
    using namespace sv::emuNES;

    Rom rom;
    rom.load("data/nestest.nes");
    auto x = rom.read<8, std::uint64_t>(62);
    std::cout << "x=" << std::hex << x << std::endl;

    auto y = rom.read<10>(16);
    for (auto i : y)
        std::cout << std::hex << int(i) << ' ';
    std::cout << std::endl;
}
