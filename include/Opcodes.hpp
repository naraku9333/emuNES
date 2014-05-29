#ifndef SV_NES_OP
#define SV_NES_OP

#include <cstdint>

namespace sv
{
    namespace emuNES
    {
        namespace opcode
        {
            enum class mode
            {
                none,
                immediate,
                zeropage,
                zeropage_x,
                zeropage_y,                
                absolute,
                absolute_x,
                absolute_y,
                indirect,
                indirect_x,
                indirect_y
            };

            // all funcs will take a mode
            // this will hopefully reduce the number of seperate functions
            // I have to write for the opcodes
            // this depends greatly on the difference in operations
            // and may be changed later.
            void brk(const mode);
            void ora(const mode);
            void asl(const mode);
            void php(const mode);
            void bpl(const mode);
            void clc(const mode);
            void blp(const mode);
            void jsr(const mode);
            void bit(const mode);
            void and(const mode);
            void rol(const mode);
            void plp(const mode);
            void bmi(const mode);
            void sec(const mode);
            void rti(const mode);
            void eor(const mode);
            void lsr(const mode);
            void jmp(const mode);
            void bvc(const mode);
            void pha(const mode);
            void zero_page_x(const mode);
            //many more to come
        }
    }
}
#endif
