#ifndef SV_NES_MEM
#define SV_NES_MEM
#include <array>
#include <cstdint>
#include <utility>

namespace sv
{
	namespace emuNES
	{
		class Memory
		{
			std::array<uint8_t, 0x10000> data;//64K
		public:
			Memory() = default;

			/*template<typename T>
			T read(uint16_t pos)
			{
                std::size_t bytes = sizeof(T);
                T val= 0;
                for (int i = 0; i < bytes; ++i)
                {
                    val |= data[pos + i];
                    val <<= 8;
                }
                return std::move(val);
			}*/

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

			template<
                typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type
            >
			void write(uint16_t pos, T val)
			{
                std::size_t bytes = sizeof(val);
                for (int i = 0; i < bytes; ++i)
                {
                    data[pos + i] = val & 0xFF;
                    val >>= 8;
                }
			}

            template<typename T, std::uint16_t N>
            void write(std::array<T, N> rom, std::uint16_t pos)
            {
                std::copy(rom.begin(), rom.end(), &data[pos]);
            }
		};
	}
}
#endif
