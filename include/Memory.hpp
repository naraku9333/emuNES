#ifndef SV_NES_MEM
#define SV_NES_MEM
#include <array>
#include <cstdint>
namespace sv
{
	namespace emuNES
	{
		class Memory
		{
			std::array<uint8_t, 0x10000> data;//64K
		public:
			Memory();

			template<typename T>
			T read(uint8_t)
			{

			}

			template<typename T>
			void write(uint8_t, T)
			{

			}
		};
	}
}
#endif
