#include <stdint.h>

typedef union {
    unsigned short addr;  // Access to all 16 bits

    // Misc format: full 16-bit opcode
    struct {
        unsigned short opcode : 16;
    } misc;

    // Branch format
    struct {
        unsigned short offset : 8;
        unsigned short opcode : 8;
    } branch;

    // Single operand format
    struct {
        unsigned short dst_reg  : 3;  // bits 0-2
        unsigned short dst_mode : 3;  // bits 3-5
        unsigned short opcode   : 10; // bits 6-15
    } sgl_op;

    // Register source format
    struct {
        unsigned short dst_reg  : 3;  // bits 0-2
        unsigned short dst_mode : 3;  // bits 3-5
        unsigned short src_reg  : 3;  // bits 6-8
        unsigned short opcode   : 7;  // bits 9-15
    } reg_src;

    // Double operand format
    struct {
        unsigned short dst_reg  : 3;  // bits 0-2
        unsigned short dst_mode : 3;  // bits 3-5
        unsigned short src_reg  : 3;  // bits 6-8
        unsigned short src_mode : 3;  // bits 9-11
        unsigned short opcode   : 4;  // bits 12-15
    } dbl_op;

} machine_inst;

