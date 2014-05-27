#ifndef SV_NES_ROM
#define SV_NES_ROM
#include <string>
#include <array>
#include <cstdint>
namespace sv
{
	namespace emuNES
	{
		class Rom
		{
			std::array<std::uint8_t, 0x8000> data;//32K
		public:
            Rom() = default;
            ~Rom() = default;

			void load(const std::string&);

            /**
            * read N bytes from rom starting at pos (index)
            * template params N is number of bytes (must be <= 8
            * T is integral data type to return
            */
			template<
                std::uint8_t N = std::enable_if<(N <= 8), bool>,
                typename T = std::enable_if<std::is_integral<T>::value, bool>
            >
			T read(std::uint16_t pos)
			{
                static_assert(sizeof(T) <= N, "data type not large enough");

                T temp = 0;

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
                return a;
            }
		};
	}
}
#endif
