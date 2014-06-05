#ifndef SV_NES_CPU
#define SV_NES_CPU
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <Rom.hpp>
#include <Memory.hpp>

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
            bool running = true;
            static std::unordered_map<std::uint8_t, std::function<void()>> op_funcs;
            std::uint16_t PC,//program counter
                A,//accumulator
                SP;//stack pointer
            Memory mem;

            public:
            /*REMOVE*/Memory& get_mem(){ return mem; }//for testing only!!!

            template<typename T, std::uint16_t N>
            void  load_cart(std::array<T, N> cart)
            {
                mem.write(cart, 0x8000);
            }

            Processor() = default;
            ~Processor() = default;

            void run()
            {
                while (running)
                {
                    std::uint8_t op = mem.read<std::uint8_t>(PC);
                    ++PC;
                    execute(op);
                }
            }

            void execute(std::uint8_t opcode)
            {
                op_funcs.at(opcode)();
            }
		};
	}
}
#endif
