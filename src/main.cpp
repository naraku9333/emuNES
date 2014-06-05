#include <iostream>
#include <string>
#include <Processor.hpp>
#include <Rom.hpp>

int main()
{
    using namespace sv::emuNES;

    Processor cpu;
    cpu.load_cart(Rom::get("data/nestest.nes"));

    auto m = cpu.get_mem();
    auto i = m.read<std::uint32_t>(0x81F0);
    std::cout << std::hex << i << std::endl;
}
