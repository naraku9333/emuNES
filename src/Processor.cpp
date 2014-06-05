#include <Processor.hpp>
#include <Opcodes.hpp>
#include <initializer_list>
#include <vector>
namespace sv
{
    namespace emuNES
    {
        
        /*template<opcode::mode m>
        void op_func(opcode op)
        {
            
        }*/
        

        std::unordered_map<std::uint8_t, std::function<void()>> Processor::op_funcs
        {
            { 0X00, std::bind(opcode::brk, opcode::mode::none) }, { 0x01, std::bind(opcode::ora, opcode::mode::none) }, { 0x05, std::bind(opcode::ora, opcode::mode::zeropage) },
            { 0x06, std::bind(opcode::asl, opcode::mode::zeropage) }, { 0x08, std::bind(opcode::php, opcode::mode::none) }, { 0x09, std::bind(opcode::ora, opcode::mode::immediate) },
            { 0x0A, std::bind(opcode::asl, opcode::mode::none) }, { 0x0D, std::bind(opcode::ora, opcode::mode::absolute) }, { 0x10, std::bind(opcode::bpl, opcode::mode::none) },
            { 0x11, std::bind(opcode::ora, opcode::mode::indirect_y) }, { 0x15, std::bind(opcode::ora, opcode::mode::zeropage) }, { 0x16, std::bind(opcode::asl, opcode::mode::zeropage_x) },
            { 0x18, std::bind(opcode::clc, opcode::mode::none) }, { 0x19, std::bind(opcode::ora, opcode::mode::absolute_y) }, { 0x1D, std::bind(opcode::ora, opcode::mode::absolute_x) },
            { 0x20, std::bind(opcode::jsr, opcode::mode::none) }, { 0x21, std::bind(opcode::and, opcode::mode::indirect_x) }, { 0x24, std::bind(opcode::bit, opcode::mode::zeropage) },
            { 0x25, std::bind(opcode::and, opcode::mode::zeropage) }, { 0x26, std::bind(opcode::rol, opcode::mode::zeropage) }, { 0x28, std::bind(opcode::plp, opcode::mode::none) },
            { 0x29, std::bind(opcode::and, opcode::mode::immediate) }, { 0x2A, std::bind(opcode::rol, opcode::mode::none) }, { 0x2C, std::bind(opcode::bit, opcode::mode::absolute) },
            { 0x2D, std::bind(opcode::and, opcode::mode::absolute) }, { 0x2E, std::bind(opcode::rol, opcode::mode::absolute) }, { 0x30, std::bind(opcode::bmi, opcode::mode::none) },
            { 0x31, std::bind(opcode::and, opcode::mode::indirect_x) }, { 0x35, std::bind(opcode::and, opcode::mode::zeropage_x) }, { 0x36, std::bind(opcode::rol, opcode::mode::zeropage_x) },
            { 0x38, std::bind(opcode::sec, opcode::mode::none) }, { 0x39, std::bind(opcode::and, opcode::mode::absolute_y) }, { 0x3D, std::bind(opcode::and, opcode::mode::absolute_x) },
            { 0x40, std::bind(opcode::rti, opcode::mode::none) }, { 0x41, std::bind(opcode::eor, opcode::mode::indirect_x) }, { 0x45, std::bind(opcode::eor, opcode::mode::zeropage) },
            { 0x46, std::bind(opcode::lsr, opcode::mode::zeropage) }, { 0x48, std::bind(opcode::pha, opcode::mode::none) }, { 0x49, std::bind(opcode::eor, opcode::mode::immediate) },
            { 0x4A, std::bind(opcode::lsr, opcode::mode::none) }, { 0x4C, std::bind(opcode::jmp, opcode::mode::absolute) }, { 0x4D, std::bind(opcode::eor, opcode::mode::absolute) },
            { 0x4E, std::bind(opcode::lsr, opcode::mode::absolute) }, { 0x50, std::bind(opcode::bvc, opcode::mode::none) }, { 0x51, std::bind(opcode::eor, opcode::mode::indirect_y) },
            { 0x55, std::bind(opcode::eor, opcode::mode::zeropage_x) }, { 0x56, std::bind(opcode::zero_page_x, opcode::mode::none) }
        };        
    }
}
