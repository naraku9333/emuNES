#ifndef SV_NES_CPU
#define SV_NES_CPU
#include <cstdint>
namespace sv
{
	namespace emuNES
	{
		enum class flags
		{
			N = 0X80, 
			V = 0X40, 
			D = 0X08, 
			I = 0X04, 
			Z = 0X02, 
			C = 0X01
		};

		class Processor
		{
			
		};
	}
}
#endif
