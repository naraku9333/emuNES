#include <Opcodes.hpp>
#include <iostream>
namespace sv
{
    namespace emuNES
    {
        namespace opcode
        {
            void brk(const mode m)
            {
                std::cout << "in brk, mode = " << int(m) << std::endl;
            }

            void ora(const mode m)
            {
                std::cout << "in ora, mode = " << int(m) << std::endl;
            }

            void asl(const mode m)
            {

            }

            void php(const mode m)
            {

            }

            void bpl(const mode m)
            {

            }

            void clc(const mode m)
            {

            }

            void blp(const mode m)
            {

            }

            void jsr(const mode m)
            {

            }

            void bit(const mode m)
            {

            }

            void and(const mode m)
            {

            }

            void rol(const mode m)
            {

            }

            void plp(const mode m)
            {

            }

            void bmi(const mode m)
            {

            }

            void sec(const mode m)
            {

            }

            void rti(const mode m)
            {

            }

            void eor(const mode m)
            {

            }

            void lsr(const mode m)
            {

            }

            void jmp(const mode m)
            {

            }

            void bvc(const mode m)
            {

            }

            void pha(const mode m)
            {

            }

            void zero_page_x(const mode m)
            {

            }
        }
    }
}
