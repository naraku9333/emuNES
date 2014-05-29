#ifndef SV_NES_CPU
#define SV_NES_CPU
#include <cstdint>
#include <map>
#include <functional>

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
            static std::map<std::uint8_t, std::function<void()>> op_funcs;

            public:

            Processor() = default;
            ~Processor() = default;

            void execute(std::uint8_t opcode)
            {
                op_funcs.at(opcode)();
            }
		};
	}
}
#endif
