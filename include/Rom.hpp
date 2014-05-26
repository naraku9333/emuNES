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
			std::array<uint8_t, 0x8000> data;//32K
		public:
			Rom();

			void load(std::string);

			template<typename T>
			T read(uint8_t)
			{

			}
		};
	}
}
#endif
