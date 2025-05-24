    .section .rodata
fmt:
    .string "Values: %d, %d, %d\n"

    .text
    .globl print_three
print_three:
    # Prologue (optional here, no stack frame needed)
    
    # Load address of format string into rdi (1st argument)
    lea fmt(%rip), %rdi
    
    # Load integer values into rsi, rdx, rcx (2nd, 3rd, 4th arguments)
    mov $10, %esi
    mov $20, %edx
    mov $30, %ecx
    
    # Clear rax before calling variadic function per AMD64 ABI
    xor %eax, %eax
    
    # Call printf
    call printf
    
    # Return
    ret

