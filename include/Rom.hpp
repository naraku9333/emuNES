#ifndef SV_NES_ROM
#define SV_NES_ROM
#include <string>
#include <array>
#include <utility>
#include <cstdint>
#include <type_traits>

namespace sv
{
	namespace emuNES
	{
		class Rom
		{
            struct Header
            {
                std::uint32_t format;//NES 4E 45 53 1A
                std::uint8_t rom_banks;
                std::uint8_t vrom_banks;
                std::uint8_t flags_6;
                std::uint8_t flags_7;
                std::uint8_t prg_rom;
                std::uint8_t flags_9;
                std::uint8_t flags_10;
                std::uint8_t unused[5];
            } header;

			std::array<std::uint8_t, 0x8000> data;//32K
		public:
            Rom() = default;
            ~Rom() = default;

			void load(const std::string&);

            /**
            * template param T is integral data type to return
            * number of bytes return depend on type passed
            * uint8_t will return 1 byte
            * ...
            * uint64_t will return 8 bytes
            *
            * bytes returned start at pos
            */
			template<
                typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type
            >
			T read(std::uint16_t pos)
			{
                T temp = 0;
                int N = sizeof(T);
                for (int i = 0; i < N; ++i)
                {
                    temp <<= 8;
                    temp += data[pos + i];
                }
                return temp;
			}

            /**
            * read any number of bytes from ROM
            * starting at pos
            * returns std::array of bytes
            */
            template <std::uint8_t N>
            std::array<std::uint8_t, N> read(std::uint8_t pos)
            {
                std::array<std::uint8_t, N> a;
                std::copy(&data[pos], &data[pos + N], a.begin());
                return std::move(a);
            }
		};
	}
}
#endif
