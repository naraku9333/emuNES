#ifndef SV_NES_ROM
#define SV_NES_ROM
#include <string>
#include <array>
#include <utility>
#include <cstdint>
#include <type_traits>
#include <fstream>

namespace sv
{
	namespace emuNES
	{
		class Rom
		{
            //struct Header
            //{
            //    std::uint32_t format;//NES 4E 45 53 1A
            //    std::uint8_t rom_banks;
            //    std::uint8_t vrom_banks;
            //    std::uint8_t flags_6;
            //    std::uint8_t flags_7;
            //    std::uint8_t prg_rom;
            //    std::uint8_t flags_9;
            //    std::uint8_t flags_10;
            //    std::uint8_t unused[5];
            //} header;

            
            Rom() = default;
            ~Rom() = default;

            /**
            *
            *
            */
            template<typename Cont>
            static void load(const std::string& file, Cont& c)
            {
                std::ifstream ifs(file, std::ios::binary);

                //ifs.read(reinterpret_cast<char*>(&header), sizeof(header));

                std::copy(
                    std::istreambuf_iterator<char>(ifs.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    c.begin()
                    );

                //check file header
                if (std::string(c.begin(), c.begin() + 3) != "NES")
                    throw std::runtime_error("Invalid ROM file");
            }

            public:
           
            /**
            * 
            *
            */			
            static std::array<std::uint8_t, 0x8000> get(const std::string& file)
            {
                static std::string loaded_rom;
                static std::array<std::uint8_t, 0x8000> data;//32K

                if (loaded_rom != file)
                {
                    load(file, data);
                    loaded_rom = file;
                }
                return data;
            }
		};
	}
}
#endif
