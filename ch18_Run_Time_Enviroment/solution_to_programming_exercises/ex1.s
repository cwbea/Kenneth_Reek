    .globl sum_three
    .text

sum_three:
    addq    %rdi, %rsi
    addq    %rdx, %rsi
    movq    %rsi, %rax
    ret

